//
// Created by William Daughtridge on 7/10/20.
//

#include "PhysicalDevice.h"

int RVK::PhysicalDevice::ChoosePhysicalDevice()
{
    uint32_t numDevices;
    vkEnumeratePhysicalDevices(m_pInstance->GetVkInstance(), &numDevices, nullptr);

    if (!numDevices)
        return -1;

    std::vector<VkPhysicalDevice> devices(numDevices);
    vkEnumeratePhysicalDevices(m_pInstance->GetVkInstance(), &numDevices, devices.data());

    for (const auto& device : devices) {
        if (EvaluatePhysicalDevice(device)) {
            m_physicalDevice = device;

            uint32_t numPresentModes;
            vkGetPhysicalDeviceSurfacePresentModesKHR(m_physicalDevice, m_pInstance->GetSurface(), &numPresentModes,nullptr);
            m_swapchainProperties.presentModes.resize(numPresentModes);
            vkGetPhysicalDeviceSurfacePresentModesKHR(m_physicalDevice, m_pInstance->GetSurface(), &numPresentModes,m_swapchainProperties.presentModes.data());

            vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_physicalDevice, m_pInstance->GetSurface(), &m_swapchainProperties.capabilities);

            uint32_t numFormats;
            vkGetPhysicalDeviceSurfaceFormatsKHR(m_physicalDevice, m_pInstance->GetSurface(), &numFormats, nullptr);
            m_swapchainProperties.formats.resize(numFormats);
            vkGetPhysicalDeviceSurfaceFormatsKHR(m_physicalDevice, m_pInstance->GetSurface(), &numFormats, m_swapchainProperties.formats.data());

            return 0;
        }
    }

    return -1;
}

int RVK::PhysicalDevice::EvaluatePhysicalDevice(const VkPhysicalDevice& device)
{
    uint32_t numProperties = 0;
    vkEnumerateDeviceExtensionProperties(device, nullptr, &numProperties, nullptr);

    std::vector<VkExtensionProperties> extensionProperties(numProperties);
    vkEnumerateDeviceExtensionProperties(device, nullptr, &numProperties, extensionProperties.data());

    bool extsAvailable = false;
    for (const auto& ext : m_deviceExtensions) {
        for (const auto& prop : extensionProperties) {
            if (!std::strcmp(ext, prop.extensionName))
                extsAvailable = true;
        }
    }

    bool swapchainSupport = false;

    if (extsAvailable) {
        VkSurfaceCapabilitiesKHR capabilities;
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, m_pInstance->GetSurface(), &capabilities);

        uint32_t numFormats;
        vkGetPhysicalDeviceSurfaceFormatsKHR(device, m_pInstance->GetSurface(), &numFormats, nullptr);

        std::vector<VkSurfaceFormatKHR> formats(numFormats);
        vkGetPhysicalDeviceSurfaceFormatsKHR(device, m_pInstance->GetSurface(), &numFormats, formats.data());

        uint32_t numPresentModes;
        vkGetPhysicalDeviceSurfacePresentModesKHR(device, m_pInstance->GetSurface(), &numPresentModes, nullptr);

        std::vector<VkPresentModeKHR> presentModes(numPresentModes);
        vkGetPhysicalDeviceSurfacePresentModesKHR(device, m_pInstance->GetSurface(), &numPresentModes, presentModes.data());

        swapchainSupport = numFormats != 0 && numPresentModes != 0;
    }

    QueueFamilyIndices indices = FindQueueFamilies(device);

    return indices.graphicsFamily.has_value() && indices.presentFamily.has_value() && extsAvailable && swapchainSupport;
}

RVK::PhysicalDevice::QueueFamilyIndices RVK::PhysicalDevice::FindQueueFamilies(const VkPhysicalDevice& device)
{
    QueueFamilyIndices indices;

    uint32_t numQueueFamilies = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &numQueueFamilies, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilyProperties(numQueueFamilies);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &numQueueFamilies, queueFamilyProperties.data());

    uint32_t i = 0;
    for (const auto& prop : queueFamilyProperties) {
        VkBool32 presentSupport = false;
        vkGetPhysicalDeviceSurfaceSupportKHR(device, i, m_pInstance->GetSurface(), &presentSupport);

        if (presentSupport)
            indices.presentFamily = i;

        if (prop.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.graphicsFamily = i;
        }

        if (indices.presentFamily.has_value() && indices.graphicsFamily.has_value())
            break;

        i++;
    }

    return indices;
}