#include "CIndexBufferOGL.h"

CIndexBufferOGL::~CIndexBufferOGL()
{
	//delete index buffer
	glDeleteBuffers(m_NumberOfBuffers,
		            &m_IBO);
}
