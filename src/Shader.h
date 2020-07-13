//
// Created by William Daughtridge on 7/11/20.
//

#ifndef RENDERER_SHADER_H
#define RENDERER_SHADER_H

#include "Includes.h"
#include "LogicalDevice.h"

namespace RVK {

class Shader {
public:
    enum ShaderType { Vertex, Fragment };

private:
    VkShaderModule m_module;

    VkPipelineShaderStageCreateInfo m_createInfo;

    LogicalDevice* m_pLogicalDevice;

    ShaderType m_shaderType;

public:
    Shader(LogicalDevice* pLogicalDevice, const std::string& path, const ShaderType& type) :
        m_pLogicalDevice(pLogicalDevice),
        m_shaderType(type)
    {
        std::vector<char> src = ReadShader(path);

        if (CreateShaderModule(src) != VK_SUCCESS)
            std::cout << "ERROR: SHADER MODULE NOT CREATED";
    }

    ~Shader()
    {
        vkDestroyShaderModule(m_pLogicalDevice->GetDevice(), m_module, nullptr);
    }

    VkPipelineShaderStageCreateInfo CreateShaderStageInfo();

private:
    std::vector<char> ReadShader(const std::string& path) const;

    int CreateShaderModule(const std::vector<char>& src);
};

}

#endif //RENDERER_SHADER_H
