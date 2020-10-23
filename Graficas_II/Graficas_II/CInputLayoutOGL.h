#pragma once
#include "CInputLayout.h"
class CInputLayoutOGL : public CInputLayout
{
protected:

	CInputLayoutOGL() = default;
	~CInputLayoutOGL() = default;

	unsigned int m_IPLA;

	friend class COGLGraphiAPI;
};

