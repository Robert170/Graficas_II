#pragma once
#include "CSamplerState.h"
#include <d3d11.h>
#include <d3dcompiler.h>
class CSamplerStateDX : public CSamplerState
{
	CSamplerStateDX() = default;
	~CSamplerStateDX() = default;

	ID3D11SamplerState* m_pSamplerLinear = nullptr;

	friend class CDXGraphiAPI;
    
};

