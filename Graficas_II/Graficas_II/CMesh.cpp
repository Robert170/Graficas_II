#include "CMesh.h"

CMesh::CMesh(std::vector<VertexTexture> Vertices,
	         std::vector<unsigned int> Indices, 
             std::vector<CTexture*> Textures,
             std::vector<CSamplerState*> Samplers,
	         CGraphiAPI* API)
{
    this->m_Vertices = Vertices;
    this->m_Indices = Indices;
    this->m_vTextures = Textures;
    this->m_vSamplers = Samplers;
    //this->textures = Textures;
    // now that we have all the required data, set the vertex buffers and its attribute pointers.
    setupMesh(API);
}

CMesh::~CMesh()
{
    
}

void CMesh::Draw(CShaderProgram& shader,
                 CGraphiAPI* API)
{
    //set shader resource
    for (int i = 0; i < m_vTextures.size(); i++)
    {
        API->SetShaderResource(m_vTextures,
                               1);
    }

    //set sampler state
    for (int i = 0; i < m_vSamplers.size(); i++)
    {
        API->SetSamplerState(m_vSamplers,
                             1);
    }

    //set vertex buffer
    API->SetVertexBuffer(m_VertexBuffer,
                           0,
                           1,
                           sizeof(VertexTexture),
                           0);

    //set index buffer
    API->SetIndexBuffer(m_IndexBuffer,
                        0);

    // draw mesh
    API->DrawIndexed(m_Indices.size(),
                     0,
                     0,
                     nullptr);
    
}

void CMesh::DeletePointers()
{
    //delete samplers
    for (int i = m_vSamplers.size() - 1; i >= 0; i--)
    {
        if (nullptr != m_vSamplers.at(i))
        {
            delete m_vSamplers.at(i);
        }
    }

    for (int i = m_vTextures.size() - 1; i >= 0; i--)
    {
        if (nullptr != m_vTextures.at(i))
        {
            delete m_vTextures.at(i);
        }
    }

    delete m_VertexBuffer;
    delete m_IndexBuffer;
}

void CMesh::setupMesh(CGraphiAPI* API)
{
    //create vertex buffer
    m_VertexBuffer = API->CreateVertexBuffer(m_Vertices,
                                             1);

    //create index buffer
    m_IndexBuffer = API->CreateIndexBuffer(m_Indices,
                                           1);
}
