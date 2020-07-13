//
// Created by William Daughtridge on 7/12/20.
//

#ifndef RENDERER_RENDERER_H
#define RENDERER_RENDERER_H

#include "Includes.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Window.h"
#include "Instance.h"
#include "PhysicalDevice.h"
#include "LogicalDevice.h"
#include "Swapchain.h"
#include "GraphicsPipeline.h"
#include "Shader.h"
#include "Framebuffer.h"
#include "CommandBuffer.h"
#include "Semaphore.h"
#include "UniformBuffer.h"

namespace RVK {

class Renderer {
private:
    Window m_window;

    Instance m_instance;

    PhysicalDevice m_physicalDevice;

    LogicalDevice m_logicalDevice;

    Swapchain m_swapchain;

    GraphicsPipeline m_pipeline;

    Framebuffer m_framebuffer;

    CommandBuffer m_commandBuffer;

    Semaphore m_imageAvailableSemaphore;

    Semaphore m_renderFinishedSemaphore;

    double m_timePerFrame;

public:
    Renderer() :
        m_instance(&m_window),
        m_physicalDevice(&m_instance),
        m_logicalDevice(&m_physicalDevice, &m_instance),
        m_swapchain(&m_instance, &m_logicalDevice, &m_physicalDevice),
        m_pipeline(&m_physicalDevice, &m_logicalDevice, &m_swapchain),
        m_framebuffer(&m_logicalDevice, &m_swapchain, &m_pipeline),
        m_commandBuffer(&m_logicalDevice, &m_physicalDevice, &m_swapchain, &m_pipeline, &m_framebuffer),
        m_imageAvailableSemaphore(&m_logicalDevice),
        m_renderFinishedSemaphore(&m_logicalDevice),
        m_timePerFrame(0)
    {}

    ~Renderer() {}

    int Draw();

    int Start();

    int UpdateUniformBuffer(uint32_t index);
};

}

#endif //RENDERER_RENDERER_H
