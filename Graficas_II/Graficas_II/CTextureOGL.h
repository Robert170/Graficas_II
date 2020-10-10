#pragma once
#include "CTexture.h"
class CTextureOGL : public CTexture
{
protected:

	CTextureOGL() = default;
	~CTextureOGL() = default;

	unsigned int m_texture;

	friend class COGLGraphiAPI;
    
};

