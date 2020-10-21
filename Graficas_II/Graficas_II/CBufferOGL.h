#pragma once
#include "CBuffer.h"
class CBufferOGL :public CBuffer
{
protected:

	CBufferOGL() = default;
	~CBufferOGL() = default;

	unsigned int m_VBO;

	friend class COGLGraphiAPI;
};

