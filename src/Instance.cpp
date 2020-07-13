//
// Created by William Daughtridge on 7/10/20.
//

#include "Instance.h"

int RVK::Instance::CreateInstance()
{
    VkApplicationInfo applicationInfo{};
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pApplicationName = "Renderer";
    applicationInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    applicationInfo.pEngineName = "No Engine";
    applicationInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    applicationInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo instanceInfo;
    instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceInfo.pApplicationInfo = &applicationInfo;

    uint32_t numExtensions = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&numExtensions);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + numExtensions);

    if (ENABLE_VALIDATION_LAYER)
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

    instanceInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    instanceInfo.ppEnabledExtensionNames = extensions.data();

    VkDebugUtilsMessengerCreateInfoEXT messengerInfo{};

    if (ENABLE_VALIDATION_LAYER && !CheckValidationLayerSupport()) {
        instanceInfo.enabledLayerCount = static_cast<uint32_t>(m_layerNames.size());
        instanceInfo.ppEnabledLayerNames = m_layerNames.data();

        messengerInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
        messengerInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
        messengerInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
        messengerInfo.pfnUserCallback = debugCallback;
        instanceInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &messengerInfo;
    }
    else
        instanceInfo.enabledLayerCount = 0;

    instanceInfo.flags = 0;

    return vkCreateInstance(&instanceInfo, nullptr, &m_instance);
}

int RVK::Instance::CheckValidationLayerSupport()
{
    uint32_t numLayers;
    vkEnumerateInstanceLayerProperties(&numLayers, nullptr);

    std::vector<VkLayerProperties> layers(numLayers);
    vkEnumerateInstanceLayerProperties(&numLayers, layers.data());

    for (const auto& layer : layers) {
        if (!std::strcmp(layer.layerName, "VK_LAYER_KHRONOS_validation"))
            return 0;
    }

    return -1;
}

int RVK::Instance::SetupDebugMessenger()
{
    VkDebugUtilsMessengerCreateInfoEXT messengerInfo{};
    messengerInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    messengerInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    messengerInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
    messengerInfo.pfnUserCallback = debugCallback;

    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(m_instance, "vkCreateDebugUtilsMessengerEXT");
    if (func)
        return func(m_instance, &messengerInfo, nullptr, &m_debugMessenger);

    return VK_ERROR_EXTENSION_NOT_PRESENT;
}

VKAPI_ATTR VkBool32 VKAPI_CALL RVK::Instance::debugCallback (
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData)
{
    std::cerr << "VALIDATION LAYER: " << pCallbackData->pMessage << std::endl;

    return VK_FALSE;
}