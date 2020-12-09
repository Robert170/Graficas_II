/**
 * @class CModel
 *
 * @brief class for the model
 *
 * This class is the  for model of Directx and opengl
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
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
    // model data 
    std::vector<Texture> m_Texturesloaded;	
    std::vector<CMesh>  m_vMeshes;
    std::string m_Directory;
    bool gammaCorrection;

    CModel();
    ~CModel();


    void Init(std::string const& path,
              CGraphiAPI* API,
              bool gamma = false);

    // draws the model, and thus all its meshes
    void Draw(CShaderProgram& shader, CGraphiAPI* API);

private:

    void LoadModel(std::string const& path, CGraphiAPI* API);

    void ProcessNode(aiNode* node, const aiScene* scene, CGraphiAPI* API);

    CMesh ProcessMesh(aiMesh* mesh, const aiScene* scene, CGraphiAPI* API);

    // checks all material textures of a given type and loads the textures if they're not loaded yet.
    // the required info is returned as a Texture struct.
    /*std::vector<Texture> loadMaterialTextures(aiMaterial* mat, 
                                              aiTextureType type, 
                                              std::string typeName);*/

    /*unsigned int TextureFromFile(const char* path,
                                 const std::string& directory,
                                 bool gamma = false);*/
};

