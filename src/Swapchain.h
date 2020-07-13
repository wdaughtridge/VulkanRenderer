//
// Created by William Daughtridge on 7/11/20.
//

#ifndef RENDERER_SWAPCHAIN_H
#define RENDERER_SWAPCHAIN_H

#include "Includes.h"
#include "Instance.h"
#include "LogicalDevice.h"
#include "PhysicalDevice.h"
#include "IndexBuffer.h"

namespace RVK {

class Swapchain {
private:
    Instance* m_pInstance;

    LogicalDevice* m_pLogicalDevice;

    PhysicalDevice* m_pPhysicalDevice;

    VkSwapchainKHR m_swapchain;

    VkFormat m_format;

    VkExtent2D m_extent;

    std::vector<VkImage> m_swapchainImages;

    std::vector<VkImageView> m_swapchainImageViews;

    VkImage m_depthImage;

    VkDeviceMemory m_depthMemory;

    VkImageView m_depthView;

public:
    Swapchain(Instance* pInstance, LogicalDevice* pLogicalDevice, PhysicalDevice* pPhysicalDevice) :
        m_pInstance(pInstance),
        m_pLogicalDevice(pLogicalDevice),
        m_pPhysicalDevice(pPhysicalDevice)
    {
        if (CreateSwapchain() != VK_SUCCESS)
            std::cout << "ERROR: SWAPCHAIN NOT CREATED!\n";

        if (CreateImageViews() != VK_SUCCESS)
            std::cout << "ERROR: IMAGE VIEWS NOT CREATED!\n";

        if (CreateDepthResources() != VK_SUCCESS)
            std::cout << "ERROR: DEPTH RESOURCES NOT CREATED!\n";
    }

    ~Swapchain()
    {
        for (const auto& view : m_swapchainImageViews) {
            vkDestroyImageView(m_pLogicalDevice->GetDevice(), view, nullptr);
        }

        vkDestroySwapchainKHR(m_pLogicalDevice->GetDevice(), m_swapchain, nullptr);

        vkDestroyImage(m_pLogicalDevice->GetDevice(), m_depthImage, nullptr);
        vkDestroyImageView(m_pLogicalDevice->GetDevice(), m_depthView, nullptr);
        vkFreeMemory(m_pLogicalDevice->GetDevice(), m_depthMemory, nullptr);
    }

    VkFormat GetFormat() const { return m_format; }

    VkExtent2D GetExtent() const { return m_extent; }

    VkSwapchainKHR GetSwapchain() const { return m_swapchain; }

    std::vector<VkImageView>* GetImageViewsPointer() { return &m_swapchainImageViews; }

    VkImageView GetDepthImageView() const { return m_depthView; }

private:
    int CreateSwapchain();

    int CreateImageViews();

    int CreateDepthResources();
};

}

#endif //RENDERER_SWAPCHAIN_H
