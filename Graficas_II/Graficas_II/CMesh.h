/**
 * @class CMesh
 *
 * @brief class for the Mesh of the model
 *
 * This class is the for Mesh of Directx and opengl
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 12/3/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include <glad/glad.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>
#include "CShaderProgram.h"
#include "CVertexBuffer.h"
#include "CIndexBuffer.h"
#include "CTexture.h"
#include "CSamplerState.h"
#include "CGraphiAPI.h"

struct Vertex {
    // position
    glm::vec3 Position;
    // texCoords
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
};

class CMesh
{
public:

    /**
       * @brief public functions
    */

    /**
      * @Variable m_Vertices, textures vertex
    */
    std::vector<VertexTexture> m_Vertices;

    /**
      * @Variable m_Indices, textures indices
    */
    std::vector<unsigned int> m_Indices;

    /**
      * @Variable m_vTextures, all textures
    */
    std::vector<CTexture*> m_vTextures;

    /**
      * @Variable m_vSamplers, all samplers
    */
    std::vector<CSamplerState*> m_vSamplers;


    /**
      * @brief      CMesh function, constructor whit parameters
      * @param      Vertices parameter one, textures vertex
      * @param      indices parameter two, textures indices
      * @param      Textures parameter three, all textures
      * @param      Samplers parameter four, all samplers
      * @param      API parameter five, api to have acces to diferent functions
      * @bug		No know Bugs
      * @return     Returns nothing
    */
    CMesh(std::vector<VertexTexture> Vertices,
          std::vector<unsigned int> indices,
          std::vector<CTexture*> Textures,
          std::vector<CSamplerState*> Samplers,
          CGraphiAPI* API);

    /// Destructor
    ~CMesh();

    /**
      * @brief      Draw function, to draw the load model
      * @param      shader parameter one, to use shader
      * @param      API parameter two, api to have acces to diferent functions
      * @bug		No know Bugs
      * @return     Returns nothing
    */
    void Draw(CShaderProgram& shader, 
              CGraphiAPI* API);

    /**
      * @brief      DeletePointers function, to delete pointers
      * @bug		No know Bugs
      * @return     Returns nothing
    */
    void DeletePointers();

private:
    /**
      * @brief private variables
    */

    /**
      * @Variable m_IndexBuffer, index buffer
    */
    CIndexBuffer* m_IndexBuffer;

    /**
      * @Variable m_VertexBuffer, vertex buffer
    */
    CVertexBuffer* m_VertexBuffer;


    /**
       * @brief private functions
    */

    /**
      * @brief      setupMesh function, to set mesh
      * @param      API parameter one, api to have acces to diferent functions
      * @bug		No know Bugs
      * @return     Returns nothing
    */
    void setupMesh(CGraphiAPI* API);
};

