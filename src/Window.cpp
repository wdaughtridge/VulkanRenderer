//
// Created by William Daughtridge on 7/10/20.
//

#include "Window.h"

int RVK::Window::InitWindow()
{
    if (glfwInit() != GLFW_TRUE)
        return -1;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan Renderer", nullptr, nullptr);

    if (!m_window)
        return -1;

    return 0;
}

bool RVK::Window::WindowShouldClose()
{
    return glfwWindowShouldClose(m_window);
}