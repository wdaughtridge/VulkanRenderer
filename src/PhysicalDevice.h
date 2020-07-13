//
// Created by William Daughtridge on 7/10/20.
//

#ifndef RENDERER_PHYSICALDEVICE_H
#define RENDERER_PHYSICALDEVICE_H

#include "Includes.h"
#include "Instance.h"
#include "Window.h"

namespace RVK {

class PhysicalDevice {
public:
    struct QueueFamilyIndices {
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;
    };

    const std::vector<const char*> m_deviceExtensions {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };

    struct SwapchainProperties {
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
        VkSurfaceCapabilitiesKHR capabilities;
    };

    SwapchainProperties m_swapchainProperties;

private:
    const Instance* m_pInstance;

    VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;

public:
    PhysicalDevice(const Instance* pInstance) : m_pInstance(pInstance)
    {
        if (ChoosePhysicalDevice())
            std::cout << "ERROR: PHYSICAL DEVICE NOT FOUND!\n";
    }

    VkPhysicalDevice GetVkPhysicalDevice() { return m_physicalDevice; }

    QueueFamilyIndices FindQueueFamilies(const VkPhysicalDevice& device);

private:
    int ChoosePhysicalDevice();

    int EvaluatePhysicalDevice(const VkPhysicalDevice& device);
};

}

#endif //RENDERER_PHYSICALDEVICE_H
