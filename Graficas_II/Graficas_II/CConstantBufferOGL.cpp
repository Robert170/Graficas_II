#include "CConstantBufferOGL.h"

CConstantBufferOGL::~CConstantBufferOGL()
{
	//delete constant buffer
	
	glDeleteBuffers(m_NumberOfBuffers,
			        &m_CBO);
	
}
