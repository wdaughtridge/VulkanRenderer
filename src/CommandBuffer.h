//
// Created by William Daughtridge on 7/12/20.
//

#ifndef RENDERER_COMMANDBUFFER_H
#define RENDERER_COMMANDBUFFER_H

#include "Includes.h"
#include "LogicalDevice.h"
#include "PhysicalDevice.h"
#include "Swapchain.h"
#include "GraphicsPipeline.h"
#include "Framebuffer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "UniformBuffer.h"
#include "Model.h"

namespace RVK {

class CommandBuffer {
private:
    VkCommandPool m_commandPool;

    VkDescriptorPool m_descriptorPool;

    std::vector<VkCommandBuffer> m_commandBuffers;

    std::vector<VkDescriptorSet> m_descriptorSets;

    LogicalDevice* m_pLogicalDevice;

    PhysicalDevice* m_pPhysicalDevice;

    Swapchain* m_pSwapchain;

    GraphicsPipeline* m_pGraphicsPipeline;

    Framebuffer* m_pFramebuffer;

//    VertexBuffer m_vbo;
//
//    IndexBuffer m_ebo;

    Model m_model;

    std::vector<UniformBuffer> m_uniformBuffers;

public:
    CommandBuffer(LogicalDevice* pLogicalDevice, PhysicalDevice* pPhysicalDevice, Swapchain* pSwapchain, GraphicsPipeline* pGraphicsPipeline, Framebuffer* pFramebuffer, Camera* pCamera) :
        m_pLogicalDevice(pLogicalDevice),
        m_pPhysicalDevice(pPhysicalDevice),
        m_pSwapchain(pSwapchain),
        m_pGraphicsPipeline(pGraphicsPipeline),
        m_pFramebuffer(pFramebuffer),
        m_model(m_pLogicalDevice, m_pPhysicalDevice, "/Users/wdaughtridge/GraviT/src/asset/junkshop/junkshop.obj")
//        m_vbo(m_pLogicalDevice, m_pPhysicalDevice, std::vector<VertexBuffer::Vertex>{
//            {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
//            {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
//            {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
//            {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}} }),
//        m_ebo(m_pLogicalDevice, m_pPhysicalDevice)
    {
        for (size_t i = 0; i < m_pSwapchain->GetImageViewsPointer()->size(); i++) {
            UniformBuffer buf{m_pLogicalDevice, m_pPhysicalDevice, pCamera};
            m_uniformBuffers.push_back(buf);
        }

        if (CreateCommandPool() != VK_SUCCESS)
            std::cout << "ERROR: COMMAND POOL NOT CREATED!\n";

        if (CreateCommandBuffer() != VK_SUCCESS)
            std::cout << "ERROR: COMMAND BUFFER NOT CREATED!\n";

        if (CreateDescriptorPool() != VK_SUCCESS)
            std::cout << "ERROR: DESCRIPTOR POOL NOT CREATED!\n";

        if (CreateDescriptorSets() != VK_SUCCESS)
            std::cout << "ERROR: DESCRIPTOR SET LAYOUT NOT CREATED!\n";

        if (BeginCommandBufferAndRenderPass() != VK_SUCCESS)
            std::cout << "ERROR: COMMAND BUFFER NOT STARTED!\n";
    }

    ~CommandBuffer()
    {
        vkDestroyCommandPool(m_pLogicalDevice->GetDevice(), m_commandPool, nullptr);
        vkDestroyDescriptorPool(m_pLogicalDevice->GetDevice(), m_descriptorPool, nullptr);
    }

    std::vector<VkCommandBuffer>* GetCommandBuffersPointer() { return &m_commandBuffers; }

    std::vector<UniformBuffer>* GetUniformBuffersPointer() { return &m_uniformBuffers; }

private:
    int CreateCommandPool();

    int CreateCommandBuffer();

    int BeginCommandBufferAndRenderPass();

    int CreateDescriptorPool();

    int CreateDescriptorSets();
};

}

#endif //RENDERER_COMMANDBUFFER_H
