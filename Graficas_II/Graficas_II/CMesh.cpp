#include "CMesh.h"

CMesh::CMesh(std::vector<SimpleVertex> Vertices, 
	         std::vector<unsigned int> Indices, 
	         InputLayout_Desc InpLayDesc, 
	         CGraphiAPI* API)
{
    this->m_Vertices = Vertices;
    this->m_Indices = Indices;
    m_InpLayDesc = InpLayDesc;
    //this->textures = Textures;
    // now that we have all the required data, set the vertex buffers and its attribute pointers.
    setupMesh(API);
}

void CMesh::Draw(CShaderProgram& shader,
                 CGraphiAPI* API)
{
    API->SetVertexBuffer(m_VertexBuffer,
                           0,
                           1,
                           sizeof(SimpleVertex),
                           0);

    API->SetIndexBuffer(m_IndexBuffer,
                        0);

    // draw mesh
    API->DrawIndexed(m_Indices.size(),
                     0,
                     0,
                     nullptr);
    
}

void CMesh::setupMesh(CGraphiAPI* API)
{
    m_VertexBuffer = API->CreateVertexBuffer(m_Vertices,
                                             m_Vertices.size(),
                                             1);

    m_IndexBuffer = API->CreateIndexBuffer(m_Indices,
                                           m_Indices.size(),
                                           1);
}
