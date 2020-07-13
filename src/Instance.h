//
// Created by William Daughtridge on 7/10/20.
//

#ifndef RENDERER_INSTANCE_H
#define RENDERER_INSTANCE_H

#define ENABLE_VALIDATION_LAYER 1

#include "Includes.h"
#include "Window.h"

namespace RVK
{

class Instance
{
private:
    VkInstance m_instance;

    Window* m_pWindow;

    VkSurfaceKHR m_surface;

#if ENABLE_VALIDATION_LAYER == 1
    std::vector<const char*> m_layerNames { "VK_LAYER_KHRONOS_validation" };
    VkDebugUtilsMessengerEXT m_debugMessenger;
#endif

public:
    Instance(Window* pWindow) : m_pWindow(pWindow)
    {
        if (CreateInstance() != VK_SUCCESS)
            std::cout << "ERROR: VK INSTANCE NOT CREATED!\n";

        if (SetupDebugMessenger() != VK_SUCCESS)
            std::cout << "ERROR: VALIDATION LAYER NOT SET UP!\n";

        if (CreateSurface() != VK_SUCCESS)
            std::cout << "ERROR: WINDOW SURFACE NOT CREATED!\n";
    }

    ~Instance()
    {
        auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(m_instance, "vkDestroyDebugUtilsMessengerEXT");
        if (func)
            func(m_instance, m_debugMessenger, nullptr);

        vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        vkDestroyInstance(m_instance, nullptr);
    }

    VkInstance GetVkInstance() const { return m_instance; }

    VkSurfaceKHR GetSurface() const { return m_surface; }

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback (
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData);
private:
    int CreateInstance();
    int CheckValidationLayerSupport();
    int SetupDebugMessenger();

    int CreateSurface()
    {
        return glfwCreateWindowSurface(m_instance, m_pWindow->GetGLFWWindow(), nullptr, &m_surface);
    }
};

}

#endif //RENDERER_INSTANCE_H
