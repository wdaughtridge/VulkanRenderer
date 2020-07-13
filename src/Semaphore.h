//
// Created by William Daughtridge on 7/12/20.
//

#ifndef RENDERER_SEMAPHORE_H
#define RENDERER_SEMAPHORE_H

#include "Includes.h"
#include "LogicalDevice.h"

namespace RVK {

class Semaphore {
private:
    VkSemaphore m_semaphore;

    LogicalDevice* m_pLogicalDevice;

public:
    Semaphore(LogicalDevice* pLogicalDevice) :
        m_pLogicalDevice(pLogicalDevice)
    {
        if (CreateSemaphore() != VK_SUCCESS)
            std::cout << "ERROR: SEMAPHORE NOT CREATED\n";
    }

    ~Semaphore()
    {
        vkDestroySemaphore(m_pLogicalDevice->GetDevice(), m_semaphore, nullptr);
    }

    VkSemaphore GetSemaphore() const { return m_semaphore; }

private:
    int CreateSemaphore();
};

}

#endif //RENDERER_SEMAPHORE_H
