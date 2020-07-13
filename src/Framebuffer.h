//
// Created by William Daughtridge on 7/12/20.
//

#ifndef RENDERER_FRAMEBUFFER_H
#define RENDERER_FRAMEBUFFER_H

#include "Includes.h"
#include "Swapchain.h"
#include "GraphicsPipeline.h"
#include "LogicalDevice.h"

namespace RVK {

class Framebuffer {
private:
    std::vector<VkFramebuffer> m_swapchainFramebuffers;

    LogicalDevice* m_pLogicalDevice;

    Swapchain* m_pSwapchain;

    GraphicsPipeline* m_pGraphicsPipeline;

public:
    Framebuffer(LogicalDevice* pLogicalDevice, Swapchain* pSwapchain, GraphicsPipeline* pGraphicsPipeline) :
        m_pLogicalDevice(pLogicalDevice),
        m_pSwapchain(pSwapchain),
        m_pGraphicsPipeline(pGraphicsPipeline)
    {
        if (CreateFramebuffer() != VK_SUCCESS)
            std::cout << "ERROR: FRAMEBUFFER NOT CREATED!\n";
    }

    ~Framebuffer()
    {
        for (const auto& fb : m_swapchainFramebuffers)
            vkDestroyFramebuffer(m_pLogicalDevice->GetDevice(), fb, nullptr);
    }

    std::vector<VkFramebuffer>* GetFramebuffersPointer() { return &m_swapchainFramebuffers; }

private:
    int CreateFramebuffer();
};

}

#endif //RENDERER_FRAMEBUFFER_H
