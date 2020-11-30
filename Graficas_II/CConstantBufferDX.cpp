#include "CConstantBufferDX.h"

CConstantBufferDX::~CConstantBufferDX()
{
	if (m_pConstantBuffer)
	{
		m_pConstantBuffer->Release();
	}
}
