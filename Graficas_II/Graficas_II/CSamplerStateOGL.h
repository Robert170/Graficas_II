#pragma once
#include "CSamplerState.h"
class CSamplerStateOGL : public CSamplerState
{
protected:

	CSamplerStateOGL() = default;
	~CSamplerStateOGL() = default;

	unsigned int m_SamSt;

	friend class COGLGraphiAPI;
};

