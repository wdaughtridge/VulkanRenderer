//
// Created by William Daughtridge on 7/12/20.
//

#ifndef RENDERER_UNIFORMBUFFER_H
#define RENDERER_UNIFORMBUFFER_H

#include "Includes.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "LogicalDevice.h"
#include "PhysicalDevice.h"

namespace RVK {

class UniformBuffer {
public:
    struct UBO {
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 proj;
    };

    UBO m_uniforms;

private:
    VkBuffer m_ubo;

    VkDeviceMemory m_uboMemory;

    LogicalDevice* m_pLogicalDevice;

    PhysicalDevice* m_pPhysicalDevice;

public:
    UniformBuffer(LogicalDevice* pLogicalDevice, PhysicalDevice* pPhysicalDevice) :
            m_pLogicalDevice(pLogicalDevice),
            m_pPhysicalDevice(pPhysicalDevice),
            m_uniforms{glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)) ,
                       glm::lookAt(glm::vec3(-2.0f, -4.0f, 20.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
                       glm::perspective(glm::radians(45.0f), 1024.0f / (float) 768.0f, 0.1f, 100.0f)}
    {
        if (CreateUniformBuffer() != VK_SUCCESS)
            std::cout << "ERROR: VERTEX BUFFER NOT CREATED SUCCESSFULLY!\n";

        if (AllocateBufferMemory() != VK_SUCCESS)
            std::cout << "ERROR: VERTEX BUFFER MEMORY NOT ALLOCATED!\n";

        vkBindBufferMemory(m_pLogicalDevice->GetDevice(), m_ubo, m_uboMemory, 0);
    }

    ~UniformBuffer()
    {
        vkDestroyBuffer(m_pLogicalDevice->GetDevice(), m_ubo, nullptr);
        vkFreeMemory(m_pLogicalDevice->GetDevice(), m_uboMemory, nullptr);
    }

    [[nodiscard]] VkBuffer GetBuffer() const { return m_ubo; }

    int MapUniformBufferMemory();

private:
    int CreateUniformBuffer();

    int AllocateBufferMemory();

    uint32_t GetMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags memoryPropertyFlags);
};

}

#endif //RENDERER_UNIFORMBUFFER_H
