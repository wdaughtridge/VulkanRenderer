//
// Created by William Daughtridge on 7/12/20.
//

#include "IndexBuffer.h"

int RVK::IndexBuffer::CreateIndexBuffer()
{
    VkBufferCreateInfo bufferCreateInfo;
    bufferCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferCreateInfo.flags = 0;
    bufferCreateInfo.pNext = VK_NULL_HANDLE;
    bufferCreateInfo.size = sizeof(uint16_t) * m_indices.size();
    bufferCreateInfo.usage = VK_BUFFER_USAGE_INDEX_BUFFER_BIT;
    bufferCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    return vkCreateBuffer(m_pLogicalDevice->GetDevice(), &bufferCreateInfo, nullptr, &m_ebo);
}

int RVK::IndexBuffer::AllocateBufferMemory()
{
    VkMemoryRequirements memRequirements;
    vkGetBufferMemoryRequirements(m_pLogicalDevice->GetDevice(), m_ebo, &memRequirements);

    VkMemoryAllocateInfo allocateInfo;
    allocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocateInfo.pNext = VK_NULL_HANDLE;
    allocateInfo.allocationSize = memRequirements.size;
    allocateInfo.memoryTypeIndex = GetMemoryType(memRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, m_pPhysicalDevice);

    return vkAllocateMemory(m_pLogicalDevice->GetDevice(), &allocateInfo, nullptr, &m_eboMemory);
}

uint32_t RVK::IndexBuffer::GetMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags memoryPropertyFlags, PhysicalDevice* pPhysicalDevice)
{
    VkPhysicalDeviceMemoryProperties memoryProperties;
    vkGetPhysicalDeviceMemoryProperties(pPhysicalDevice->GetVkPhysicalDevice(), &memoryProperties);

    for (uint32_t i = 0; i < memoryProperties.memoryTypeCount; i++) {
        if ((static_cast<uint32_t>(typeFilter) & (static_cast<uint32_t>(1) << i)) && (memoryProperties.memoryTypes[i].propertyFlags & memoryPropertyFlags) == memoryPropertyFlags) {
            return i;
        }
    }

    return 0;
}

int RVK::IndexBuffer::MapIndexBufferMemory()
{
    void* data;

    vkMapMemory(m_pLogicalDevice->GetDevice(), m_eboMemory, 0, sizeof(uint16_t) * m_indices.size(), 0, &data);
    memcpy(data, m_indices.data(), (size_t)(sizeof(uint16_t) * m_indices.size()));
    vkUnmapMemory(m_pLogicalDevice->GetDevice(), m_eboMemory);

    return 0;
}