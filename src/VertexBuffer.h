//
// Created by William Daughtridge on 7/12/20.
//

#ifndef RENDERER_VERTEXBUFFER_H
#define RENDERER_VERTEXBUFFER_H

#include "Includes.h"
#include "glm/glm.hpp"
#include "LogicalDevice.h"
#include "PhysicalDevice.h"

namespace RVK{

class VertexBuffer {
public:
    struct Vertex {
        glm::vec3 pos;
        glm::vec3 color;

        static VkVertexInputBindingDescription GetBindingDescription()
        {
            VkVertexInputBindingDescription bindingDescription;
            bindingDescription.binding = 0;
            bindingDescription.stride = sizeof(Vertex);
            bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
            return bindingDescription;
        }

        static std::array<VkVertexInputAttributeDescription, 2> GetAttributeDescriptions()
        {
            std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions{};

            attributeDescriptions[0].binding = 0;
            attributeDescriptions[0].offset = offsetof(Vertex, pos);
            attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributeDescriptions[0].location = 0;

            attributeDescriptions[1].binding = 0;
            attributeDescriptions[1].offset = offsetof(Vertex, color);
            attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributeDescriptions[1].location = 1;

            return attributeDescriptions;
        }
    };

private:
    VkBuffer m_vbo;

    VkDeviceMemory m_vboMemory;

    LogicalDevice* m_pLogicalDevice;

    PhysicalDevice* m_pPhysicalDevice;

    std::vector<Vertex> m_vertices;

public:
    VertexBuffer(LogicalDevice* pLogicalDevice, PhysicalDevice* pPhysicalDevice, const std::vector<Vertex>& vertices) :
        m_pLogicalDevice(pLogicalDevice),
        m_pPhysicalDevice(pPhysicalDevice),
//        m_vertices{
//            {{-0.5f, -0.5f, 0.0f}, {1.0f, 0.0f, 0.0f}},
//            {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}},
//            {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}},
//            {{-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}},
//            {{-0.5f, 0.5f, -1.0f}, {1.0f, 0.0f, 0.0f}},
//            {{0.5f, 0.5f, -1.0f}, {0.0f, 1.0f, 0.0f}},
//            {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}},
//            {{-0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 1.0f}}
//            }
        m_vertices(vertices)
    {
        if (CreateVertexBuffer() != VK_SUCCESS)
            std::cout << "ERROR: VERTEX BUFFER NOT CREATED SUCCESSFULLY!\n";

        if (AllocateBufferMemory() != VK_SUCCESS)
            std::cout << "ERROR: VERTEX BUFFER MEMORY NOT ALLOCATED!\n";

        vkBindBufferMemory(m_pLogicalDevice->GetDevice(), m_vbo, m_vboMemory, 0);

        MapVertexBufferMemory();
    }

    ~VertexBuffer()
    {
        vkDestroyBuffer(m_pLogicalDevice->GetDevice(), m_vbo, nullptr);
        vkFreeMemory(m_pLogicalDevice->GetDevice(), m_vboMemory, nullptr);
    }

    [[nodiscard]] VkBuffer GetBuffer() const { return m_vbo; }

private:
    int CreateVertexBuffer();

    int AllocateBufferMemory();

    int MapVertexBufferMemory();

    uint32_t GetMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags memoryPropertyFlags);
};

}

#endif //RENDERER_VERTEXBUFFER_H
