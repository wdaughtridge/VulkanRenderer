//
// Created by William Daughtridge on 7/12/20.
//

#include "VertexBuffer.h"

int RVK::VertexBuffer::CreateVertexBuffer()
{
    VkBufferCreateInfo bufferCreateInfo;
    bufferCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferCreateInfo.flags = 0;
    bufferCreateInfo.pNext = VK_NULL_HANDLE;
    bufferCreateInfo.size = sizeof(m_vertices[0]) * m_vertices.size();
    bufferCreateInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
    bufferCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    return vkCreateBuffer(m_pLogicalDevice->GetDevice(), &bufferCreateInfo, nullptr, &m_vbo);
}

int RVK::VertexBuffer::AllocateBufferMemory()
{
    VkMemoryRequirements memRequirements;
    vkGetBufferMemoryRequirements(m_pLogicalDevice->GetDevice(), m_vbo, &memRequirements);

    VkMemoryAllocateInfo allocateInfo;
    allocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocateInfo.pNext = VK_NULL_HANDLE;
    allocateInfo.allocationSize = memRequirements.size;
    allocateInfo.memoryTypeIndex = GetMemoryType(memRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

    return vkAllocateMemory(m_pLogicalDevice->GetDevice(), &allocateInfo, nullptr, &m_vboMemory);
}

uint32_t RVK::VertexBuffer::GetMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags memoryPropertyFlags)
{
    VkPhysicalDeviceMemoryProperties memoryProperties;
    vkGetPhysicalDeviceMemoryProperties(m_pPhysicalDevice->GetVkPhysicalDevice(), &memoryProperties);

    for (uint32_t i = 0; i < memoryProperties.memoryTypeCount; i++) {
        if ((static_cast<uint32_t>(typeFilter) & (static_cast<uint32_t>(1) << i)) && (memoryProperties.memoryTypes[i].propertyFlags & memoryPropertyFlags) == memoryPropertyFlags) {
            return i;
        }
    }

    return 0;
}

int RVK::VertexBuffer::MapVertexBufferMemory()
{
    void* data;
    vkMapMemory(m_pLogicalDevice->GetDevice(), m_vboMemory, 0, sizeof(m_vertices), 0, &data);
    memcpy(data, m_vertices.data(), (size_t)(sizeof(m_vertices[0]) * m_vertices.size()));
    vkUnmapMemory(m_pLogicalDevice->GetDevice(), m_vboMemory);

    return 0;
}