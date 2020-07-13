//
// Created by William Daughtridge on 7/13/20.
//

#ifndef RENDERER_MODEL_H
#define RENDERER_MODEL_H

#include "Includes.h"
#include "glm/glm.hpp"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "LogicalDevice.h"
#include "PhysicalDevice.h"
#include <future>

namespace RVK {

//    struct VertexData {
//        glm::vec3 position;
//        glm::vec4 color;
//        glm::vec2 textureCoord;
//        glm::vec3 normal;
//        glm::vec3 tangent;
//        glm::vec3 bitangent;
//    };

class Mesh {
private:
    std::vector<VertexBuffer::Vertex> m_vertices;

    std::vector<uint16_t> m_indices;

    unsigned int m_numIndices;

//    std::vector<GraviT::Texture>* m_textures;

    glm::mat4 m_model;
public:

//    std::vector<unsigned int> m_texID;

//    Mesh(std::vector<GraviT::Texture>* textures, const std::vector<unsigned int>& texID, const std::vector<GraviT::VertexData>& vertices, const std::vector<unsigned int>& indices) : m_textures(textures), m_texID(texID), m_numIndices((unsigned int)indices.size()), m_model(1.0f) {
//
//    }
};

class Model {
private:
    struct MeshData {
        aiMaterial* material;
        std::vector<VertexBuffer::Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<unsigned int> texID;
    };

    struct ModelReturn {
        std::vector<VertexBuffer::Vertex> vertices;
        std::vector<uint16_t> indices;
    };

    struct ModelData {
        std::vector<RVK::Mesh> m_meshes;
//        std::vector<GraviT::Texture> m_textures;
        glm::vec3 m_pos;

        std::string m_currentdir;
        const bool m_flipTex;

        ModelData(const bool flipTex) : m_flipTex(flipTex) {}
    };

    ModelData m_data;

    static std::vector<std::future<void>> s_futures;
    static std::mutex meshLock;
    static size_t m_numMeshes;

public:
    ModelReturn returnData;
    std::shared_ptr<VertexBuffer> m_vbo;
    std::shared_ptr<IndexBuffer> m_ebo;

    Model(LogicalDevice* pLogicalDevice, PhysicalDevice* pPhysicalDevice, const std::string& src, const bool flipTex = false) :
        m_data(flipTex)
    {
        Assimp::Importer imp;
        const aiScene* scene = imp.ReadFile(src, aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType | aiProcess_ImproveCacheLocality | aiProcess_OptimizeMeshes);

        m_data.m_currentdir = src.substr(0, src.find_last_of('/'));
        GetNode(this, scene->mRootNode, scene,returnData);

        m_vbo = std::make_shared<VertexBuffer>(pLogicalDevice, pPhysicalDevice, returnData.vertices);
        m_ebo = std::make_shared<IndexBuffer>(pLogicalDevice, pPhysicalDevice, returnData.indices);
    }

private:
    static void GetNode(RVK::Model* model, const aiNode *node, const aiScene *scene, ModelReturn& returnData);

    static void GetMesh(RVK::Model* model, const aiMesh *mesh, const aiScene *scene, ModelReturn& returnData);

//    static void GetTextures(RVK::Model* model, RVK::Mesh* mesh, const aiMaterial *mat, const std::vector<unsigned int>* texID);
};

}


#endif //RENDERER_MODEL_H
