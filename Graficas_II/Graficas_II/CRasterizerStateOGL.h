#pragma once
#include "CRasterizerState.h"
class CRasterizerStateOGL : public CRasterizerState
{
protected:
	CRasterizerStateOGL() = default;
	~CRasterizerStateOGL() = default;



	friend class COGLGraphiAPI;
};

