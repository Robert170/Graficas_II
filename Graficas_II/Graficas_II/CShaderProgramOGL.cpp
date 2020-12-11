#include "CShaderProgramOGL.h"

CShaderProgramOGL::~CShaderProgramOGL()
{
	delete m_VertexShaderProgram;
	delete m_PixelShaderProgram;
}
