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
    // mesh Data
    std::vector<SimpleVertex> m_Vertices;
    std::vector<unsigned int> m_Indices;
    //std::vector<Texture> m_Textures;


    // constructor
    CMesh(std::vector<SimpleVertex> Vertices,
          std::vector<unsigned int> indices,
          //std::vector<Texture> textures,
          CGraphiAPI* API);

    // render the mesh
    void Draw(CShaderProgram& shader, 
              CGraphiAPI* API);

private:
    // render data 

    CIndexBuffer* m_IndexBuffer;
    CVertexBuffer* m_VertexBuffer;



    // initializes all the buffer objects/arrays
    void setupMesh(CGraphiAPI* API);
};

