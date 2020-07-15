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
        double dX;
        double dY;
    };

    glm::vec3 m_cameraFront;

    glm::vec3 m_cameraPosition;

    glm::vec3 m_cameraUp;

    glm::mat4 m_proj;

    glm::mat4 m_view;

    glm::mat4 m_model;

    double m_yaw;

    double m_pitch;

private:
    static std::queue<KeyEvent> s_keyQueue;

    static MouseDelta s_mouseDelta;

    static double m_last_x;

    static double m_last_y;

public:
    Camera() :
        m_cameraFront({0.0f, 0.0f, -1.0f}),
        m_cameraPosition({0.0f, 0.0f, 0.0f}),
        m_cameraUp({0.0f, 1.0f, 0.0f}),
        m_model(glm::mat4(1.0f)),
        m_view(glm::lookAt(m_cameraPosition, m_cameraFront + m_cameraPosition, m_cameraUp)),
        m_proj(glm::perspective(glm::radians(45.0f), 1024.0f / (float) 768.0f, 0.1f, 100.0f)),
        m_yaw(0),
        m_pitch(0)
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
        MouseDelta ret = s_mouseDelta;
        s_mouseDelta = {0,0};
        return ret;
    }

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if ((key == GLFW_KEY_W || key == GLFW_KEY_A || key == GLFW_KEY_S || key == GLFW_KEY_D) && (action == GLFW_PRESS || action == GLFW_REPEAT))
            s_keyQueue.push({static_cast<int16_t>(key), static_cast<int16_t>(action)});
    }

    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
    {
        s_mouseDelta.dX += (xpos - m_last_x);
        s_mouseDelta.dY += (ypos - m_last_y);

        m_last_x = xpos;
        m_last_y = ypos;
    }
};

}

#endif //RENDERER_CAMERA_H
