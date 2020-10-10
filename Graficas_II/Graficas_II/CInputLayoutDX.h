#pragma once
#include "CInputLayout.h"
#include <d3d11.h>
#include <d3dcompiler.h>
class CInputLayoutDX : public CInputLayout
{
protected:
	CInputLayoutDX() = default;
	~CInputLayoutDX() = default;

	ID3D11InputLayout* m_pVertexLayout = nullptr;//

	friend class CDXGraphiAPI;
};

