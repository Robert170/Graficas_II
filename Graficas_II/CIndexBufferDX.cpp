#include "CIndexBufferDX.h"

CIndexBufferDX::~CIndexBufferDX()
{
	if (m_pIndexBuffer)
	{
		m_pIndexBuffer->Release();
	}
}