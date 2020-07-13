//
// Created by William Daughtridge on 7/13/20.
//

#include "Model.h"
/*
 ----------------------------------------------------------------
 Model
 ----------------------------------------------------------------
 */

std::vector<std::future<void>> RVK::Model::s_futures;
std::mutex RVK::Model::meshLock;

/*
Processes all nodes and all meshes of nodes in model
*/
void RVK::Model::GetNode(RVK::Model* model, const aiNode *node, const aiScene *scene, ModelReturn& returnData) {
    for(int i = 0; i < node->mNumMeshes; i++)
        RVK::Model::GetMesh(model, scene->mMeshes[node->mMeshes[i]], scene, returnData);

    for(int i = 0; i < node->mNumChildren; i++)
        GetNode(model, node->mChildren[i], scene, returnData);
}

void RVK::Model::GetMesh(RVK::Model* model, const aiMesh *mesh, const aiScene *scene, ModelReturn& returnData) {
//    std::vector<VertexBuffer::Vertex> vertices;
//    std::vector<unsigned int> indices;
//    std::vector<unsigned int> texID;

    for(int i = 0; i < mesh->mNumVertices; i++) {
        VertexBuffer::Vertex vertex;
//        if (mesh->mVertices) {
            vertex.pos.x = mesh->mVertices[i].x;
            vertex.pos.y = -1.0f * mesh->mVertices[i].y;
            vertex.pos.z = mesh->mVertices[i].z;
//        }
//        else
//            vertex.pos = glm::vec3();

//        if (mesh->HasNormals()) {
//            vertex.normal.x = mesh->mNormals[i].x;
//            vertex.normal.y = mesh->mNormals[i].y;
//            vertex.normal.z = mesh->mNormals[i].z;
//        }
//        else
//            vertex.normal = glm::vec3();
//
//        if(mesh->HasTextureCoords(0)) {
//            vertex.textureCoord.x = mesh->mTextureCoords[0][i].x;
//            vertex.textureCoord.y = mesh->mTextureCoords[0][i].y;
//        }
//        else
//            vertex.textureCoord = glm::vec2(0.0f, 0.0f);
//
//        if (mesh->HasTangentsAndBitangents()) {
//            vertex.tangent.x = mesh->mTangents[i].x;
//            vertex.tangent.y = mesh->mTangents[i].y;
//            vertex.tangent.z = mesh->mTangents[i].z;
//
//            vertex.bitangent.x = mesh->mBitangents[i].x;
//            vertex.bitangent.y = mesh->mBitangents[i].y;
//            vertex.bitangent.z = mesh->mBitangents[i].z;
//        }
//        else {
//            vertex.tangent = glm::vec3();
//            vertex.bitangent = glm::vec3();
//        }

//        if (mesh->HasVertexColors(0)) {
//            vertex.color.r = mesh->mColors[i]->r;
//            vertex.color.g = mesh->mColors[i]->g;
//            vertex.color.b = mesh->mColors[i]->b;
////            vertex.color.a = mesh->mColors[i]->a;
//        }
//        else
        vertex.color = glm::vec3((rand() % 100)/100.0f,(rand() % 100)/100.0f,(rand() % 100)/100.0f);

        returnData.vertices.push_back(vertex);
    }

    uint32_t maxIndex;
    if (returnData.indices.size() != 0)
        maxIndex = *std::max_element(returnData.indices.begin(), returnData.indices.end()) + 1;
    else
        maxIndex = 0;

    std::cout << maxIndex << "\n";

    for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];

        for(unsigned int j = 0; j < face.mNumIndices; j++) {
            returnData.indices.push_back((uint32_t) face.mIndices[j] + maxIndex);
        }
    }

    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

//    RVK::Mesh newMesh = RVK::Mesh(&(model->m_data.m_textures), texID, vertices, indices);
//    model->m_data.m_meshes.push_back(newMesh);

//    RVK::Model::GetTextures(model, &(model->m_data.m_meshes.back()), material, &texID);
}

//void RVK::Model::GetTextures(RVK::Model* model, RVK::Mesh* mesh, const aiMaterial *mat, const std::vector<unsigned int>* texID) {
//    aiColor3D ambient;
//    if(AI_SUCCESS != mat->Get(AI_MATKEY_COLOR_AMBIENT, ambient))
//        std::cout << "AMBIENT color not loaded!\n";
//
//    aiColor3D diffuse;
//    if(AI_SUCCESS != mat->Get(AI_MATKEY_COLOR_DIFFUSE, diffuse))
//        std::cout << "DIFFUSE color not loaded!\n";
//
//    aiColor3D specular;
//    if(AI_SUCCESS != mat->Get(AI_MATKEY_COLOR_SPECULAR, specular))
//        std::cout << "SPECULAR color not loaded!\n";
//
//    aiColor3D emissive;
//    if(AI_SUCCESS != mat->Get(AI_MATKEY_COLOR_EMISSIVE, emissive))
//        std::cout << "EMISSIVE color not loaded!\n";
//
//    std::array<aiTextureType, 18> texTypes {
//            aiTextureType_DIFFUSE,
//            aiTextureType_SPECULAR,
//            aiTextureType_NORMALS,
//            aiTextureType_HEIGHT,
//            aiTextureType_AMBIENT,
//            aiTextureType_METALNESS,
//            aiTextureType_REFLECTION,
//            aiTextureType_AMBIENT_OCCLUSION,
//            aiTextureType_LIGHTMAP,
//            aiTextureType_BASE_COLOR,
//            aiTextureType_SHININESS,
//            aiTextureType_NONE,
//            aiTextureType_DIFFUSE_ROUGHNESS,
//            aiTextureType_DISPLACEMENT,
//            aiTextureType_EMISSION_COLOR,
//            aiTextureType_UNKNOWN,
//            aiTextureType_OPACITY,
//            aiTextureType_EMISSIVE
//    };
//
//    std::array<std::string, 18> texTypeUniforms {
//            "uDiffuse",
//            "uSpecular",
//            "uNormals",
//            "uNormal",
//            "uAmbient",
//            "uMetalness",
//            "uReflection",
//            "uOcclusion",
//            "uLightmap",
//            "uBaseColor",
//            "uShininess",
//            "uNone",
//            "uDiffuseRoughness",
//            "uDisplacement",
//            "uEmissionColor",
//            "uUnknown",
//            "uOpacity",
//            "uEmissive"
//    };
//
//    for (int h = 0; h < texTypes.size(); h++) {
//        aiString file;
//        bool loaded;
//        for(int i = 0; i < mat->GetTextureCount(texTypes[h]); i++) {
//            loaded = false;
//            mat->GetTexture(texTypes[h], i, &file);
//            std::string path = model->m_data.m_currentdir + '/' + std::string(file.C_Str());
//
//            for (int j = 0; j < model->m_data.m_textures.size(); j++) {
//                if (!strcmp(model->m_data.m_textures[j].m_filename.c_str(), path.c_str())) {
//                    loaded = true;
//                    mesh->m_texID.push_back(j);
//                }
//            }
//            if (!loaded) {
//                model->m_data.m_textures.emplace_back(GraviT::Texture(path.c_str(), texTypeUniforms[h].c_str(), &(mesh->m_vao), model->m_data.m_flipTex));
//                mesh->m_texID.push_back((unsigned int)model->m_data.m_textures.size()-1);
//            }
//        }
//    }
//}
