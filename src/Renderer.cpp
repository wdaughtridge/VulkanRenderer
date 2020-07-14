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

    UpdateUniformBuffer();

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
    }

    return VK_SUCCESS;
}

int RVK::Renderer::UpdateUniformBuffer()
{
    Camera::MouseDelta mD = Camera::GetMouseDelta();

    if (mD.dX != 0 && mD.dY != 0) {
        m_camera.m_yaw += static_cast<float>(mD.dX);
        m_camera.m_pitch -= static_cast<float>(mD.dY);

        if(m_camera.m_pitch > 89.0f)
            m_camera.m_pitch = 89.0f;
        if(m_camera.m_pitch < -89.0f)
            m_camera.m_pitch = -89.0f;

        glm::vec3 direction;
        direction.x = cos(glm::radians(m_camera.m_yaw)) * cos(glm::radians(m_camera.m_pitch));
        direction.y = sin(glm::radians(m_camera.m_pitch));
        direction.z = sin(glm::radians(m_camera.m_yaw)) * cos(glm::radians(m_camera.m_pitch));
        m_camera.m_cameraFront = glm::normalize(direction);
        for (auto & i : *m_commandBuffer.GetUniformBuffersPointer()) {
            m_camera.m_view = glm::lookAt(m_camera.m_cameraPosition, m_camera.m_cameraPosition + m_camera.m_cameraFront, m_camera.m_cameraUp);
            i.m_uniforms.view = m_camera.m_view;
            i.MapUniformBufferMemory();
        }
    }

    Camera::KeyEvent e = Camera::GetNextKeyEvent();

    if (e.key == -1) {
        for (auto & i : *m_commandBuffer.GetUniformBuffersPointer()) {
            i.m_uniforms.view = m_camera.m_view;
            i.MapUniformBufferMemory();
        }
        return VK_SUCCESS;
    }

    if (e.key == GLFW_KEY_W) {
        for (auto & i : *m_commandBuffer.GetUniformBuffersPointer()) {
            m_camera.m_cameraPosition.z += 0.5;
            m_camera.m_view = glm::lookAt(m_camera.m_cameraPosition, m_camera.m_cameraPosition + m_camera.m_cameraFront, m_camera.m_cameraUp);
            i.m_uniforms.view = m_camera.m_view;
            i.MapUniformBufferMemory();
        }
        return VK_SUCCESS;
    }
    if (e.key == GLFW_KEY_A) {
        for (auto & i : *m_commandBuffer.GetUniformBuffersPointer()) {
            m_camera.m_cameraPosition.x -= 0.5;
            m_camera.m_view = glm::lookAt(m_camera.m_cameraPosition, m_camera.m_cameraPosition + m_camera.m_cameraFront, m_camera.m_cameraUp);
            i.m_uniforms.view = m_camera.m_view;
            i.MapUniformBufferMemory();
        }
        return VK_SUCCESS;
    }
    if (e.key == GLFW_KEY_S) {
        for (auto & i : *m_commandBuffer.GetUniformBuffersPointer()) {
            m_camera.m_cameraPosition.z -= 0.5;
            m_camera.m_view = glm::lookAt(m_camera.m_cameraPosition, m_camera.m_cameraPosition + m_camera.m_cameraFront, m_camera.m_cameraUp);
            i.m_uniforms.view = m_camera.m_view;
            i.MapUniformBufferMemory();
        }
        return VK_SUCCESS;
    }
    if (e.key == GLFW_KEY_D) {
        for (auto & i : *m_commandBuffer.GetUniformBuffersPointer()) {
            m_camera.m_cameraPosition.x += 0.5;
            m_camera.m_view = glm::lookAt(m_camera.m_cameraPosition, m_camera.m_cameraPosition + m_camera.m_cameraFront, m_camera.m_cameraUp);
            i.m_uniforms.view = m_camera.m_view;
            i.MapUniformBufferMemory();
        }
        return VK_SUCCESS;
    }

    return VK_ERROR_UNKNOWN;
}