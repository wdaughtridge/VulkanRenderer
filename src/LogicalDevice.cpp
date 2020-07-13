//
// Created by William Daughtridge on 7/10/20.
//

#include "LogicalDevice.h"

int RVK::LogicalDevice::CreateLogicalDevice()
{
    PhysicalDevice::QueueFamilyIndices indices = m_pPhysicalDevice->FindQueueFamilies(m_pPhysicalDevice->GetVkPhysicalDevice());
    std::vector<VkDeviceQueueCreateInfo> queueInfos;
    std::set<uint32_t> uniqueQueueFamilies { indices.graphicsFamily.value(), indices.presentFamily.value() };

    float priority = 1.0f;
    for (auto family : uniqueQueueFamilies) {
        VkDeviceQueueCreateInfo queueCreateInfo{};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = family;
        queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = &priority;
        queueInfos.push_back(queueCreateInfo);
    }

    VkPhysicalDeviceFeatures deviceFeatures{};

    VkDeviceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    createInfo.pQueueCreateInfos = queueInfos.data();
    createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueInfos.size());
    createInfo.pEnabledFeatures = &deviceFeatures;

    createInfo.enabledExtensionCount = static_cast<uint>(m_pPhysicalDevice->m_deviceExtensions.size());
    createInfo.ppEnabledExtensionNames = m_pPhysicalDevice->m_deviceExtensions.data();

    VkResult res = vkCreateDevice(m_pPhysicalDevice->GetVkPhysicalDevice(), &createInfo, nullptr, &m_logicalDevice);

    vkGetDeviceQueue(m_logicalDevice, indices.graphicsFamily.value(), 0, &m_graphicsQueue);
    vkGetDeviceQueue(m_logicalDevice, indices.presentFamily.value(), 0, &m_presentQueue);

    return res;
}