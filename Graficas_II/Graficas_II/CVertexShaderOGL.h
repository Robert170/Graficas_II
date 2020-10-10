#pragma once
#include "CVertexShader.h"
#include <fstream>
#include <sstream>
class CVertexShaderOGL : public CVertexShader
{
protected:
	CVertexShaderOGL() = default;
	~CVertexShaderOGL() = default;

	std::string ReadFile(std::string FileName);

	std::string m_VertexCode;
	std::ifstream m_VertexShaderFile;
	std::stringstream m_VertexShaderStream;
	unsigned int m_VertexShader;



	friend class COGLGraphiAPI;
};

