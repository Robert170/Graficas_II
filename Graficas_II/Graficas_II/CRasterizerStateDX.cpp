#include "CRasterizerStateDX.h"

CRasterizerStateDX::~CRasterizerStateDX()
{
	if (m_pRasterizerState)
	{
		m_pRasterizerState->Release();
	}
}