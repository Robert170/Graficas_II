/**
 * @class CModel
 *
 * @brief class for the model
 *
 * This class is the  for model of Directx and opengl
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 12/3/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <fstream>
#include <sstream>
#include "stb_image.h"
#include "CMesh.h"
class CModel
{
public:
   

    CModel();
    ~CModel();


    void LoadModel(std::string const& path,
                   CGraphiAPI* API,
                   bool gamma = false);

    // draws the model, and thus all its meshes
    void Draw(CShaderProgram& shader, CGraphiAPI* API);

private:

    // model data 
    std::vector<CTexture*> m_Texturesloaded;
    std::vector<CSamplerState*> m_vSamplers;
    std::vector<CMesh>  m_vMeshes;
    std::string m_Directory;
    bool gammaCorrection;

    CTexture* m_Texture;
    CSamplerState* m_Sampler;


    void LoadModel_2(std::string const& path, CGraphiAPI* API);

    void ProcessNode(aiNode* node, const aiScene* scene, CGraphiAPI* API);

    CMesh ProcessMesh(aiMesh* mesh, const aiScene* scene, CGraphiAPI* API);

    // checks all material textures of a given type and loads the textures if they're not loaded yet.
    // the required info is returned as a Texture struct.
    void LoadMaterialTextures(aiMaterial* mat,
                              aiTextureType type, 
                              std::string typeName,
                              CGraphiAPI* API);

    void TextureFromFile(const char* path,
                         const std::string& directory,
                         CGraphiAPI* API,
                         bool gamma = false);
};

