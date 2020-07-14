//
// Created by William Daughtridge on 7/13/20.
//

#ifndef RENDERER_CAMERA_H
#define RENDERER_CAMERA_H

#include "Includes.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace RVK {

class Camera {
public:
    struct KeyEvent {
        int16_t key;
        int16_t action;
    };

    struct MouseDelta {
        int16_t dX;
        int16_t dY;
    };

    glm::vec3 m_cameraFront;

    glm::vec3 m_cameraPosition;

    glm::vec3 m_cameraUp;

    glm::mat4 m_proj;

    glm::mat4 m_view;

    glm::mat4 m_model;

    float m_yaw;

    float m_pitch;

private:
    static std::queue<KeyEvent> s_keyQueue;

    static MouseDelta s_mouseDelta;

public:
    Camera() :
        m_cameraFront({0.0f, 0.0f, -1.0f}),
        m_cameraPosition({0.0f, 0.0f, 0.0f}),
        m_cameraUp({0.0f, 1.0f, 0.0f}),
        m_model(glm::mat4(1.0f)),
        m_view(glm::lookAt(m_cameraPosition, m_cameraFront + m_cameraPosition, m_cameraUp)),
        m_proj(glm::perspective(glm::radians(45.0f), 1024.0f / (float) 768.0f, 0.1f, 100.0f))
    {
    }

    static Camera::KeyEvent GetNextKeyEvent()
    {
        if (s_keyQueue.empty())
            return {-1, -1};

        Camera::KeyEvent ret = s_keyQueue.front();
        s_keyQueue.pop();
        return ret;
    }

    static Camera::MouseDelta GetMouseDelta()
    {
        if (s_mouseDelta.dX == 0 && s_mouseDelta.dY == 0)
            return {0,0};

        MouseDelta ret = s_mouseDelta;
        s_mouseDelta = {0,0};
        return ret;
    }

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
            s_keyQueue.push({static_cast<int16_t>(key), static_cast<int16_t>(action)});
        }
        else if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
            s_keyQueue.push({static_cast<int16_t>(key), static_cast<int16_t>(action)});
        }
        else if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
            s_keyQueue.push({static_cast<int16_t>(key), static_cast<int16_t>(action)});
        }
        else if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
            s_keyQueue.push({static_cast<int16_t>(key), static_cast<int16_t>(action)});
        }
    }

    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    {
        double x, y;
        glfwGetCursorPos(window, &x, &y);

        s_mouseDelta.dX += x;
        s_mouseDelta.dY += y;

        glfwSetCursorPos(window, 0, 0);
    }
};

}

#endif //RENDERER_CAMERA_H
