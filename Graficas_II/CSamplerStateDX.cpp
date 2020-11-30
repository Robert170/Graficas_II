#include "CSamplerStateDX.h"

CSamplerStateDX::~CSamplerStateDX()
{
	if (m_pSamplerLinear)
	{
		m_pSamplerLinear->Release();
	}
}
