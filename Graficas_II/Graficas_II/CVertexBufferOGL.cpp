#include "CVertexBufferOGL.h"

CVertexBufferOGL::~CVertexBufferOGL()
{
	//delete vertex buffer
	glDeleteBuffers(m_NumberOfBuffers,
			        &m_VBO);
	
}
