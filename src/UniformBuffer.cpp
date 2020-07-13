//
// Created by William Daughtridge on 7/12/20.
//

#include "UniformBuffer.h"

int RVK::UniformBuffer::CreateUniformBuffer()
{
    VkBufferCreateInfo bufferCreateInfo;
    bufferCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferCreateInfo.flags = 0;
    bufferCreateInfo.pNext = VK_NULL_HANDLE;
    bufferCreateInfo.size = sizeof(UBO);
    bufferCreateInfo.usage = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;
    bufferCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    return vkCreateBuffer(m_pLogicalDevice->GetDevice(), &bufferCreateInfo, nullptr, &m_ubo);
}

int RVK::UniformBuffer::AllocateBufferMemory()
{
    VkMemoryRequirements memRequirements;
    vkGetBufferMemoryRequirements(m_pLogicalDevice->GetDevice(), m_ubo, &memRequirements);

    VkMemoryAllocateInfo allocateInfo;
    allocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocateInfo.pNext = VK_NULL_HANDLE;
    allocateInfo.allocationSize = memRequirements.size;
    allocateInfo.memoryTypeIndex = GetMemoryType(memRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

    return vkAllocateMemory(m_pLogicalDevice->GetDevice(), &allocateInfo, nullptr, &m_uboMemory);
}

uint32_t RVK::UniformBuffer::GetMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags memoryPropertyFlags)
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

int RVK::UniformBuffer::MapUniformBufferMemory()
{
    void* data;

    vkMapMemory(m_pLogicalDevice->GetDevice(), m_uboMemory, 0, sizeof(UBO), 0, &data);
    memcpy(data, &m_uniforms, (size_t)(sizeof(UBO)));
    vkUnmapMemory(m_pLogicalDevice->GetDevice(), m_uboMemory);

    return 0;
}