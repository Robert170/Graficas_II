#pragma once

#include "CTexture.h"
#include <d3d11.h>
#include <d3dcompiler.h>

class CTextureDX : public CTexture
{
protected:
	CTextureDX() = default;
	~CTextureDX() = default;

	ID3D11Texture2D* m_Texture = nullptr;
	ID3D11RenderTargetView* m_RTV = nullptr;
	ID3D11DepthStencilView* m_DSV = nullptr;
	ID3D11UnorderedAccessView* m_UAV = nullptr;
	ID3D11ShaderResourceView* m_SRV = nullptr;

	friend class CDXGraphiAPI;
};
