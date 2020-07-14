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

    glfwSetKeyCallback(m_window, Camera::key_callback);
    glfwSetCursorPosCallback(m_window, Camera::cursor_position_callback);

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    return 0;
}

bool RVK::Window::WindowShouldClose()
{
    return glfwWindowShouldClose(m_window);
}