//
// Created by William Daughtridge on 7/13/20.
//

#include "Camera.h"

std::queue<RVK::Camera::KeyEvent> RVK::Camera::s_keyQueue;
RVK::Camera::MouseDelta RVK::Camera::s_mouseDelta;