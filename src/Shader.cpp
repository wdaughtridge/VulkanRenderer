//
// Created by William Daughtridge on 7/11/20.
//

#include "Shader.h"

std::vector<char> RVK::Shader::ReadShader(const std::string &path) const
{
    std::ifstream file(path, std::ios::ate | std::ios::binary);

    if (!file.is_open())
        std::cout << "ERROR: FILE DID NOT OPEN\n";

    size_t fileSize = (size_t) file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;
}

int RVK::Shader::CreateShaderModule(const std::vector<char> &src)
{
    VkShaderModuleCreateInfo shaderModuleCreateInfo;
    shaderModuleCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    shaderModuleCreateInfo.pCode = reinterpret_cast<const uint32_t*>(src.data());
    shaderModuleCreateInfo.codeSize = src.size();
    shaderModuleCreateInfo.pNext = VK_NULL_HANDLE;
    shaderModuleCreateInfo.flags = 0;

    return vkCreateShaderModule(m_pLogicalDevice->GetDevice(), &shaderModuleCreateInfo, nullptr, &m_module);
}

VkPipelineShaderStageCreateInfo RVK::Shader::CreateShaderStageInfo()
{
    VkPipelineShaderStageCreateInfo shaderStageCreateInfo;
    shaderStageCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    shaderStageCreateInfo.module = m_module;
    shaderStageCreateInfo.pSpecializationInfo = VK_NULL_HANDLE;

    if (m_shaderType == Vertex)
        shaderStageCreateInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
    else if (m_shaderType == Fragment)
        shaderStageCreateInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
    else
        std::cout << "ERROR: UNKNOWN SHADER TYPE USED!";

    shaderStageCreateInfo.pName = "main";
    shaderStageCreateInfo.flags = 0;
    shaderStageCreateInfo.pNext = VK_NULL_HANDLE;

    return shaderStageCreateInfo;
}