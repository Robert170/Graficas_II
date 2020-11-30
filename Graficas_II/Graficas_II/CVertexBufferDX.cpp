#include "CVertexBufferDX.h"


CVertexBufferDX::~CVertexBufferDX()
{
	if (m_pVertexBuffer)
	{
		m_pVertexBuffer->Release();
	}
}
