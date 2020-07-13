//
// Created by William Daughtridge on 7/11/20.
//

#include "Swapchain.h"

int RVK::Swapchain::CreateSwapchain()
{
    VkSwapchainCreateInfoKHR swapchainCreateInfo;
    swapchainCreateInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;

    uint32_t imageCount = m_pPhysicalDevice->m_swapchainProperties.capabilities.minImageCount + 1;
    if (m_pPhysicalDevice->m_swapchainProperties.capabilities.maxImageCount > 0 && imageCount > m_pPhysicalDevice->m_swapchainProperties.capabilities.maxImageCount) {
        imageCount = m_pPhysicalDevice->m_swapchainProperties.capabilities.maxImageCount;
    }

    for (const auto& format : m_pPhysicalDevice->m_swapchainProperties.formats) {
        if (format.format == VK_FORMAT_B8G8R8A8_SRGB && format.colorSpace == VK_COLORSPACE_SRGB_NONLINEAR_KHR) {
            swapchainCreateInfo.imageFormat = format.format;
            m_format = format.format;
            swapchainCreateInfo.imageColorSpace = format.colorSpace;
        }
    }

    PhysicalDevice::SwapchainProperties props = m_pPhysicalDevice->m_swapchainProperties;

    for (const auto& mode : m_pPhysicalDevice->m_swapchainProperties.presentModes) {
        if (mode == VK_PRESENT_MODE_IMMEDIATE_KHR)
            swapchainCreateInfo.presentMode = mode;
    }

    // TODO: FIX
    swapchainCreateInfo.imageExtent = m_pPhysicalDevice->m_swapchainProperties.capabilities.currentExtent;
    m_extent = swapchainCreateInfo.imageExtent;

    PhysicalDevice::QueueFamilyIndices indices = m_pPhysicalDevice->FindQueueFamilies(m_pPhysicalDevice->GetVkPhysicalDevice());
    uint32_t queueFamilyIndices[] = { indices.graphicsFamily.value(), indices.presentFamily.value() };

    if (indices.graphicsFamily.value() != indices.presentFamily.value()) {
        swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
        swapchainCreateInfo.queueFamilyIndexCount = 2;
        swapchainCreateInfo.pQueueFamilyIndices = queueFamilyIndices;
    }
    else {
        swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        swapchainCreateInfo.pQueueFamilyIndices = VK_NULL_HANDLE;
        swapchainCreateInfo.queueFamilyIndexCount = 0;
    }

    VkSurfaceKHR surface = m_pInstance->GetSurface();
    swapchainCreateInfo.surface = surface;
    swapchainCreateInfo.flags = 0;
    swapchainCreateInfo.pNext = VK_NULL_HANDLE;
    swapchainCreateInfo.minImageCount = imageCount;
    swapchainCreateInfo.imageArrayLayers = 1;
    swapchainCreateInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    VkSurfaceTransformFlagBitsKHR transform = m_pPhysicalDevice->m_swapchainProperties.capabilities.currentTransform;
    swapchainCreateInfo.preTransform = transform;
    swapchainCreateInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    swapchainCreateInfo.clipped = VK_TRUE;
    swapchainCreateInfo.oldSwapchain = VK_NULL_HANDLE;

    VkResult res = vkCreateSwapchainKHR(m_pLogicalDevice->GetDevice(), &swapchainCreateInfo, nullptr, &m_swapchain);

    vkGetSwapchainImagesKHR(m_pLogicalDevice->GetDevice(), m_swapchain, &imageCount, nullptr);
    m_swapchainImages.resize(imageCount);
    vkGetSwapchainImagesKHR(m_pLogicalDevice->GetDevice(), m_swapchain, &imageCount, m_swapchainImages.data());

    return res;
}

int RVK::Swapchain::CreateImageViews()
{
    m_swapchainImageViews.resize(m_swapchainImages.size());

    VkResult res = VK_SUCCESS;

    for (uint32_t i = 0; i < m_swapchainImageViews.size(); i++) {
        VkImageViewCreateInfo viewCreateInfo;
        viewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        viewCreateInfo.flags = 0;
        viewCreateInfo.image = m_swapchainImages[i];
        viewCreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        viewCreateInfo.format = m_format;
        viewCreateInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        viewCreateInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        viewCreateInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        viewCreateInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        viewCreateInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        viewCreateInfo.subresourceRange.baseMipLevel = 0;
        viewCreateInfo.subresourceRange.levelCount = 1;
        viewCreateInfo.subresourceRange.baseArrayLayer = 0;
        viewCreateInfo.subresourceRange.layerCount = 1;
        viewCreateInfo.pNext = VK_NULL_HANDLE;

        VkResult subRes = vkCreateImageView(m_pLogicalDevice->GetDevice(), &viewCreateInfo, nullptr, &(m_swapchainImageViews[i]));
        if (subRes != VK_SUCCESS)
            res = subRes;
    }

    return res;
}