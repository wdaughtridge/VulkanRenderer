//
// Created by William Daughtridge on 7/12/20.
//

#include "Renderer.h"

int RVK::Renderer::Draw()
{
    uint32_t imageIndex;
    vkAcquireNextImageKHR(m_logicalDevice.GetDevice(), m_swapchain.GetSwapchain(), UINT64_MAX, m_imageAvailableSemaphore.GetSemaphore(), VK_NULL_HANDLE, &imageIndex);

    VkSubmitInfo submitInfo{};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.pNext = VK_NULL_HANDLE;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &m_commandBuffer.GetCommandBuffersPointer()->at(imageIndex);

    VkSemaphore waitSemaphores[] = { m_imageAvailableSemaphore.GetSemaphore() };
    VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = waitSemaphores;
    submitInfo.pWaitDstStageMask = waitStages;

    VkSemaphore signalSemaphores[] = { m_renderFinishedSemaphore.GetSemaphore() };
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signalSemaphores;

    VkResult res = vkQueueSubmit(m_logicalDevice.GetGraphicsQueue(), 1, &submitInfo, VK_NULL_HANDLE);
    if (res != VK_SUCCESS)
        return res;

    VkPresentInfoKHR presentInfo;
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = signalSemaphores;
    VkSwapchainKHR swapchains[] = { m_swapchain.GetSwapchain() };
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapchains;
    presentInfo.pImageIndices = &imageIndex;
    presentInfo.pResults = VK_NULL_HANDLE;
    presentInfo.pNext = VK_NULL_HANDLE;

    UpdateUniformBuffer(imageIndex);

    res = vkQueuePresentKHR(m_logicalDevice.GetPresentQueue(), &presentInfo);
    if (res != VK_SUCCESS)
        return res;

    return VK_SUCCESS;
}

int RVK::Renderer::Start()
{
    double start;
    while (!m_window.WindowShouldClose()) {
        start = glfwGetTime();
        glfwPollEvents();

        int res = Draw();
        if (res != VK_SUCCESS)
            return res;

        vkQueueWaitIdle(m_logicalDevice.GetPresentQueue());
        m_timePerFrame = glfwGetTime() - start;
        std::cout << 1/m_timePerFrame << "\n";
    }

    return VK_SUCCESS;
}

int RVK::Renderer::UpdateUniformBuffer(uint32_t index)
{
    UniformBuffer* pUbo = m_commandBuffer.GetUniformBuffersPointer()->at(index).get();
//    pUbo->m_uniforms.model = glm::rotate(pUbo->m_uniforms.model, glm::radians(45.0f) * (1.0f/255.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    pUbo->m_uniforms.model = glm::translate(pUbo->m_uniforms.model, glm::vec3(0.0f, 0.0f, 0.02f));
    return pUbo->MapUniformBufferMemory();
}