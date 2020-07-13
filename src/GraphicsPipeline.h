//
// Created by William Daughtridge on 7/12/20.
//

#ifndef RENDERER_GRAPHICSPIPELINE_H
#define RENDERER_GRAPHICSPIPELINE_H

#include "Includes.h"
#include "PhysicalDevice.h"
#include "LogicalDevice.h"
#include "Swapchain.h"
#include "Shader.h"
#include "VertexBuffer.h"

namespace RVK {

class GraphicsPipeline {
private:
    PhysicalDevice* m_pPhysicalDevice;

    LogicalDevice* m_pLogicalDevice;

    Swapchain* m_pSwapchain;

    VkPipelineLayout m_pipelineLayout;

    VkPipeline m_graphicsPipeline;

    VkRenderPass m_renderPass;

    VkDescriptorSetLayout m_descriptorSetLayout;

public:
    GraphicsPipeline(PhysicalDevice* pPhysicalDevice, LogicalDevice* pLogicalDevice, Swapchain* pSwapchain) :
        m_pPhysicalDevice(pPhysicalDevice),
        m_pLogicalDevice(pLogicalDevice),
        m_pSwapchain(pSwapchain)
    {
        if (CreateRenderPass() != VK_SUCCESS)
            std::cout << "ERROR: RENDER PASS NOT CREATED!\n";

        if (CreateGraphicsPipeline() != VK_SUCCESS)
            std::cout << "ERROR: GRAPHICS PIPELINE NOT CREATED!\n";
    }

    ~GraphicsPipeline()
    {
        vkDestroyPipelineLayout(m_pLogicalDevice->GetDevice(), m_pipelineLayout, nullptr);
        vkDestroyDescriptorSetLayout(m_pLogicalDevice->GetDevice(), m_descriptorSetLayout, nullptr);
        vkDestroyRenderPass(m_pLogicalDevice->GetDevice(), m_renderPass, nullptr);
        vkDestroyPipeline(m_pLogicalDevice->GetDevice(), m_graphicsPipeline, nullptr);
    }

    VkRenderPass GetRenderPass() const { return m_renderPass; }

    VkPipeline GetPipeline() const { return m_graphicsPipeline; }

    VkPipelineLayout GetPipelineLayout() const { return m_pipelineLayout; }

    VkDescriptorSetLayout GetDescriptorSetLayout() const { return m_descriptorSetLayout; }

private:
    int CreateRenderPass();

    int CreateGraphicsPipeline();
};

}

#endif //RENDERER_GRAPHICSPIPELINE_H
