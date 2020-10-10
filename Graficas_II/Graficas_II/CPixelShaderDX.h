#pragma once
#include "CPixelShader.h"
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
class CPixelShaderDX : public CPixelShader
{
protected:
	CPixelShaderDX() = default;
	~CPixelShaderDX() = default;

	bool CompileVertexShaderFromFile(LPWSTR FileName,
		                             LPCSTR EntryPoint,
		                             LPCSTR ShaderModel,
		                             ID3DBlob * *ppBlobOut);

	ID3D11PixelShader* m_PixelShader;


	friend class CDXGraphiAPI;
};

