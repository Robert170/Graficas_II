#pragma once
#include "CVertexShader.h"
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>

class CVertexShaderDX :public CVertexShader
{
protected:
	CVertexShaderDX() = default;
	~CVertexShaderDX() = default;

	bool CompileVertexShaderFromFile(LPWSTR FileName,
		                             LPCSTR EntryPoint,
		                             LPCSTR ShaderModel,
		                             ID3DBlob** ppBlobOut);

	ID3D11VertexShader* m_VertexShader;


	friend class CDXGraphiAPI;
};

