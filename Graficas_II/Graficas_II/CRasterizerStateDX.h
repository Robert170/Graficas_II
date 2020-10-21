#pragma once
#include "CRasterizerState.h"
#include <d3d11.h>
#include <d3dcompiler.h>
class CRasterizerStateDX : public CRasterizerState
{
protected:
	CRasterizerStateDX() = default;
	~CRasterizerStateDX() = default;

	ID3D11RasterizerState* m_pRasterizerState;


	friend class CDXGraphiAPI;
};

