//
// Created by William Daughtridge on 7/12/20.
//

#include "Framebuffer.h"

int RVK::Framebuffer::CreateFramebuffer()
{
    auto imageViews = m_pSwapchain->GetImageViewsPointer();
    m_swapchainFramebuffers.resize(imageViews->size());

    for (uint32_t i = 0; i < m_swapchainFramebuffers.size(); i++) {
        VkImageView attachments[] = { imageViews->at(i), m_pSwapchain->GetDepthImageView() };

        VkFramebufferCreateInfo framebufferCreateInfo;
        framebufferCreateInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebufferCreateInfo.renderPass = m_pGraphicsPipeline->GetRenderPass();
        framebufferCreateInfo.attachmentCount = 2;
        framebufferCreateInfo.pAttachments = attachments;
        framebufferCreateInfo.width = m_pSwapchain->GetExtent().width;
        framebufferCreateInfo.height = m_pSwapchain->GetExtent().height;
        framebufferCreateInfo.layers = 1;
        framebufferCreateInfo.pNext = VK_NULL_HANDLE;
        framebufferCreateInfo.flags = 0;

        VkResult createRes = vkCreateFramebuffer(m_pLogicalDevice->GetDevice(), &framebufferCreateInfo, nullptr, &m_swapchainFramebuffers[i]);

        if (createRes != VK_SUCCESS)
            return createRes;
    }

    return VK_SUCCESS;
}