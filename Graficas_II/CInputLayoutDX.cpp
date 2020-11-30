#include "CInputLayoutDX.h"

CInputLayoutDX::~CInputLayoutDX()
{
	if (m_pInputLayout)
	{
		m_pInputLayout->Release();
	}
}