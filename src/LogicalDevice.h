//
// Created by William Daughtridge on 7/10/20.
//

#ifndef RENDERER_LOGICALDEVICE_H
#define RENDERER_LOGICALDEVICE_H

#include "Includes.h"
#include "PhysicalDevice.h"

namespace RVK {

class LogicalDevice {
private:
    PhysicalDevice* m_pPhysicalDevice;

    Instance* m_pInstance;

    VkDevice m_logicalDevice = VK_NULL_HANDLE;

    VkQueue m_graphicsQueue = VK_NULL_HANDLE;

    VkQueue m_presentQueue = VK_NULL_HANDLE;

public:
    LogicalDevice(PhysicalDevice* pDevice, Instance* pInstance) :
        m_pPhysicalDevice(pDevice),
        m_pInstance(pInstance)
    {
        if (CreateLogicalDevice() != VK_SUCCESS)
            std::cout << "ERROR: LOGICAL DEVICE NOT CREATED SUCCESSFULLY!\n";
    }

    ~LogicalDevice()
    {
        vkDestroyDevice(m_logicalDevice, nullptr);
    }

    VkDevice GetDevice() const { return m_logicalDevice; }

    VkQueue GetGraphicsQueue() const { return m_graphicsQueue; }

    VkQueue GetPresentQueue() const { return m_presentQueue; }

private:
    int CreateLogicalDevice();
};

}

#endif //RENDERER_LOGICALDEVICE_H
