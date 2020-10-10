#pragma once
#include "CBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>
class CBufferDX : public CBuffer
{
protected:
    CBufferDX() = default;
	~CBufferDX() = default;

    ID3D11Buffer* m_pVertexBuffer = nullptr;
    ID3D11Buffer* m_pIndexBuffer = nullptr;
    ID3D11Buffer* m_pCBNeverChanges = nullptr;
    ID3D11Buffer* m_pCBChangeOnResize = nullptr;
    ID3D11Buffer* m_pCBChangesEveryFrame = nullptr;

	friend class CDXGraphiAPI;
};

