//
// Created by William Daughtridge on 7/10/20.
//

#ifndef RENDERER_WINDOW_H
#define RENDERER_WINDOW_H

#include "Includes.h"
#include "Camera.h"

namespace RVK
{

class Window
{
private:
    GLFWwindow* m_window;

    const uint32_t WIDTH = 1024;

    const uint32_t HEIGHT = 768;

public:
    Window()
    {
        if (InitWindow())
            std::cout << "ERROR: WINDOW NOT CREATED SUCCESSFULLY.";
    }

    ~Window()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    GLFWwindow* GetGLFWWindow() { return m_window; }

    bool WindowShouldClose();

private:
    int InitWindow();
};

}

#endif //RENDERER_WINDOW_H
