#pragma once
#include "CPixelShader.h"
#include <fstream>
#include <sstream>
class CPixelShaderOGL : public CPixelShader
{
protected:
	CPixelShaderOGL() = default;
	~CPixelShaderOGL() = default;

	std::string ReadFile(std::string FileName);

	std::string m_PixelCode;
	std::ifstream m_PixelShaderFile;
	std::stringstream m_PixelShaderStream;
	unsigned int m_PixelShader;



	friend class COGLGraphiAPI;
};

