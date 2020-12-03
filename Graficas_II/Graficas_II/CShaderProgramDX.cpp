#include "CShaderProgramDX.h"

CShaderProgramDX::~CShaderProgramDX()
{
	delete m_VertexShaderProgram;
	delete m_PixelShaderProgram;
}
