//
// Created by William Daughtridge on 7/12/20.
//

#include "CommandBuffer.h"

int RVK::CommandBuffer::CreateCommandPool()
{
    VkCommandPoolCreateInfo commandPoolCreateInfo{};
    commandPoolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    commandPoolCreateInfo.pNext = VK_NULL_HANDLE;
    commandPoolCreateInfo.flags = 0;
    commandPoolCreateInfo.queueFamilyIndex = m_pPhysicalDevice->FindQueueFamilies(m_pPhysicalDevice->GetVkPhysicalDevice()).graphicsFamily.value();

    return vkCreateCommandPool(m_pLogicalDevice->GetDevice(), &commandPoolCreateInfo, nullptr, &m_commandPool);
}

int RVK::CommandBuffer::CreateCommandBuffer()
{
    m_commandBuffers.resize(m_pSwapchain->GetImageViewsPointer()->size());

    VkCommandBufferAllocateInfo commandBufferAllocateInfo{};
    commandBufferAllocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    commandBufferAllocateInfo.commandPool = m_commandPool;
    commandBufferAllocateInfo.pNext = VK_NULL_HANDLE;
    commandBufferAllocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    commandBufferAllocateInfo.commandBufferCount = static_cast<uint32_t>(m_commandBuffers.size());

    return vkAllocateCommandBuffers(m_pLogicalDevice->GetDevice(), &commandBufferAllocateInfo, m_commandBuffers.data());
}

int RVK::CommandBuffer::BeginCommandBufferAndRenderPass()
{
    for (uint32_t i = 0; i < m_commandBuffers.size(); i++) {
        VkCommandBufferBeginInfo commandBufferBeginInfo{};
        commandBufferBeginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        commandBufferBeginInfo.flags = 0;
        commandBufferBeginInfo.pInheritanceInfo = VK_NULL_HANDLE;
        commandBufferBeginInfo.pNext = VK_NULL_HANDLE;

        VkResult res = vkBeginCommandBuffer(m_commandBuffers[i], &commandBufferBeginInfo);
        if (res != VK_SUCCESS)
            return res;

        VkRenderPassBeginInfo renderPassBeginInfo{};
        renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassBeginInfo.pNext = VK_NULL_HANDLE;
        renderPassBeginInfo.renderPass = m_pGraphicsPipeline->GetRenderPass();
        renderPassBeginInfo.framebuffer = m_pFramebuffer->GetFramebuffersPointer()->at(i);
        renderPassBeginInfo.renderArea.offset = {0, 0 };
        renderPassBeginInfo.renderArea.extent = m_pSwapchain->GetExtent();

        VkClearValue clearValue{0.2f, 0.2f, 0.2f, 1.0f};
        renderPassBeginInfo.clearValueCount = 1;
        renderPassBeginInfo.pClearValues = &clearValue;

        vkCmdBeginRenderPass(m_commandBuffers[i], &renderPassBeginInfo, VK_SUBPASS_CONTENTS_INLINE);
        vkCmdBindPipeline(m_commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, m_pGraphicsPipeline->GetPipeline());

        VkBuffer vertexBuffers[] = { m_model.m_vbo->GetBuffer() };
        VkDeviceSize offsets[] = {0};
        vkCmdBindVertexBuffers(m_commandBuffers[i], 0, 1, vertexBuffers, offsets);

        vkCmdBindIndexBuffer(m_commandBuffers[i], m_model.m_ebo->GetBuffer(), 0, VK_INDEX_TYPE_UINT16);

        vkCmdBindDescriptorSets(m_commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, m_pGraphicsPipeline->GetPipelineLayout(), 0, 1, &m_descriptorSets[i], 0,
                                nullptr);

        vkCmdDrawIndexed(m_commandBuffers[i], static_cast<uint32_t>(m_model.m_ebo->GetNumIndices()), 1, 0, 0, 0);
        vkCmdEndRenderPass(m_commandBuffers[i]);

        res = vkEndCommandBuffer(m_commandBuffers[i]);
        if (res != VK_SUCCESS)
            return res;
    }

    return VK_SUCCESS;
}

int RVK::CommandBuffer::CreateDescriptorPool()
{
    VkDescriptorPoolSize descriptorPoolSize{};
    descriptorPoolSize.descriptorCount = m_pSwapchain->GetImageViewsPointer()->size();
    descriptorPoolSize.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;

    VkDescriptorPoolCreateInfo descriptorPoolCreateInfo{};
    descriptorPoolCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    descriptorPoolCreateInfo.poolSizeCount = 1;
    descriptorPoolCreateInfo.pPoolSizes = &descriptorPoolSize;
    descriptorPoolCreateInfo.maxSets = m_pSwapchain->GetImageViewsPointer()->size();
    descriptorPoolCreateInfo.flags = 0;
    descriptorPoolCreateInfo.pNext = VK_NULL_HANDLE;

    return vkCreateDescriptorPool(m_pLogicalDevice->GetDevice(), &descriptorPoolCreateInfo, nullptr, &m_descriptorPool);
}

int RVK::CommandBuffer::CreateDescriptorSets()
{
    std::vector<VkDescriptorSetLayout> layouts(m_pSwapchain->GetImageViewsPointer()->size(), m_pGraphicsPipeline->GetDescriptorSetLayout());
    VkDescriptorSetAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    allocInfo.descriptorPool = m_descriptorPool;
    allocInfo.descriptorSetCount = static_cast<uint32_t>(m_pSwapchain->GetImageViewsPointer()->size());
    allocInfo.pSetLayouts = layouts.data();

    m_descriptorSets.resize(m_pSwapchain->GetImageViewsPointer()->size());
    if (vkAllocateDescriptorSets(m_pLogicalDevice->GetDevice(), &allocInfo, m_descriptorSets.data()) != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate descriptor sets!");
    }

    for (size_t i = 0; i < m_pSwapchain->GetImageViewsPointer()->size(); i++) {
        VkDescriptorBufferInfo bufferInfo{};
        bufferInfo.buffer = m_uniformBuffers.at(i)->GetBuffer();
        bufferInfo.offset = 0;
        bufferInfo.range = sizeof(UniformBuffer::UBO);

        VkWriteDescriptorSet descriptorWrite{};
        descriptorWrite.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrite.dstSet = m_descriptorSets[i];
        descriptorWrite.dstBinding = 0;
        descriptorWrite.dstArrayElement = 0;
        descriptorWrite.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorWrite.descriptorCount = 1;
        descriptorWrite.pBufferInfo = &bufferInfo;

        vkUpdateDescriptorSets(m_pLogicalDevice->GetDevice(), 1, &descriptorWrite, 0, nullptr);
    }

    return VK_SUCCESS;
}