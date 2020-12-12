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
    /**
       * @brief public functions
    */

    /// Default Constructor
    CModel();

    /// Destructor
    ~CModel();

    /**
      * @brief      LoadModel function, to init the load model
      * @param      path parameter one, path of the model
      * @param      API parameter two, api to have acces to diferent functions
      * @bug		No know Bugs
      * @return     Returns nothing
    */
    void LoadModel(std::string const& path,
                   CGraphiAPI* API,
                   bool gamma = false);

    /**
      * @brief      Draw function, to draw the load model
      * @param      shader parameter one, to use shader
      * @param      API parameter two, api to have acces to diferent functions
      * @bug		No know Bugs
      * @return     Returns nothing
    */
    void Draw(CShaderProgram& shader, 
              CGraphiAPI* API);

private:
    /**
      * @brief private variables
    */
    // model data 

    /**
      * @Variable m_Texturesloaded, is for all textures of the model
    */
    std::vector<CTexture*> m_Texturesloaded;

    /**
      * @Variable m_vSamplers, is for all samplers
    */
    std::vector<CSamplerState*> m_vSamplers;

    /**
      * @Variable m_vMeshes, is for all Meshes
    */
    std::vector<CMesh>  m_vMeshes;

    /**
      * @Variable m_Directory, directori of textures
    */
    std::string m_Directory;
    bool gammaCorrection;

    /**
      * @Variable m_Texture, texture of model
    */
    CTexture* m_Texture;

    /**
      * @Variable m_Sampler, sampler of model
    */
    CSamplerState* m_Sampler;

    /**
       * @brief private functions
    */

     /**
       * @brief      LoadModel_2 function, to load model
       * @param      path parameter one, path of the model
       * @param      API parameter two, api to have acces to diferent functions
       * @bug		 No know Bugs
       * @return     Returns nothing
     */
    void LoadModel_2(std::string const& path, 
                     CGraphiAPI* API);

    /**
       * @brief      ProcessNode function, to process node of the model
       * @param      node parameter one, node of the model
       * @param      scene parameter two, scene of the model
       * @param      API parameter three, api to have acces to diferent functions
       * @bug		 No know Bugs
       * @return     Returns nothing
     */
    void ProcessNode(aiNode* node, 
                     const aiScene* scene, 
                     CGraphiAPI* API);

    /**
       * @brief      ProcessMesh function, to process node of the mesh
       * @param      mesh parameter one, mesh of the model
       * @param      scene parameter two, scene of the model
       * @param      API parameter three, api to have acces to diferent functions
       * @bug		 No know Bugs
       * @return     Returns a mesh
     */
    CMesh ProcessMesh(aiMesh* mesh, 
                      const aiScene* scene, 
                      CGraphiAPI* API);

    /**
      * @brief      LoadMaterialTextures function, to load material of the model
      * @param      mat parameter one, material of the model
      * @param      type parameter two, type of material of the model
      * @param      typeName parameter three, name of the material
      * @param      API parameter four, api to have acces to diferent functions
      * @bug		 No know Bugs
      * @return     Returns nothing
    */
    void LoadMaterialTextures(aiMaterial* mat,
                              aiTextureType type, 
                              std::string typeName,
                              CGraphiAPI* API);

    /**
       * @brief      TextureFromFile function, to load texture from file
       * @param      path parameter one, path of the texture
       * @param      directory parameter two, directory of the texture
       * @param      API parameter three, api to have acces to diferent functions
       * @bug		 No know Bugs
       * @return     Returns nothing
     */
    void TextureFromFile(const char* path,
                         const std::string& directory,
                         CGraphiAPI* API,
                         bool gamma = false);
};

