//
// Created by William Daughtridge on 7/12/20.
//

#ifndef RENDERER_INDEXBUFFER_H
#define RENDERER_INDEXBUFFER_H

#include "Includes.h"
#include "LogicalDevice.h"
#include "PhysicalDevice.h"

namespace RVK{

class IndexBuffer {
private:
    VkBuffer m_ebo;

    VkDeviceMemory m_eboMemory;

    LogicalDevice* m_pLogicalDevice;

    PhysicalDevice* m_pPhysicalDevice;

    std::vector<uint16_t> m_indices;

public:
    IndexBuffer(LogicalDevice* pLogicalDevice, PhysicalDevice* pPhysicalDevice, std::vector<uint16_t>& indices) :
        m_pLogicalDevice(pLogicalDevice),
        m_pPhysicalDevice(pPhysicalDevice),
//        m_indices{
//            0, 1, 2,
//            2, 3, 0,
//            4, 5, 6,
//            6, 7, 4
//            }
        m_indices(indices)
    {
        if (CreateIndexBuffer() != VK_SUCCESS)
            std::cout << "ERROR: VERTEX BUFFER NOT CREATED SUCCESSFULLY!\n";

        if (AllocateBufferMemory() != VK_SUCCESS)
            std::cout << "ERROR: VERTEX BUFFER MEMORY NOT ALLOCATED!\n";

        vkBindBufferMemory(m_pLogicalDevice->GetDevice(), m_ebo, m_eboMemory, 0);

        MapIndexBufferMemory();
    }

    ~IndexBuffer()
    {
        vkDestroyBuffer(m_pLogicalDevice->GetDevice(), m_ebo, nullptr);
        vkFreeMemory(m_pLogicalDevice->GetDevice(), m_eboMemory, nullptr);
    }

    [[nodiscard]] VkBuffer GetBuffer() const { return m_ebo; }

    size_t GetNumIndices() const { return m_indices.size(); }

private:
    int CreateIndexBuffer();

    int AllocateBufferMemory();

    int MapIndexBufferMemory();

    uint32_t GetMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags memoryPropertyFlags);
};

}

#endif //RENDERER_INDEXBUFFER_H
