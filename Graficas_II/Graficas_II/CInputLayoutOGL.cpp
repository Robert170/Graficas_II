#include "CInputLayoutOGL.h"

CInputLayoutOGL::CInputLayoutOGL()
{
	m_mFormatSize.insert(std::pair<unsigned int, unsigned int>(TF_R32G32B32A32_FLOAT, 4));
	m_mFormatSize.insert(std::pair<unsigned int, unsigned int>(TF_R32G32B32A32_UINT, 4));
	m_mFormatSize.insert(std::pair<unsigned int, unsigned int>(TF_R32G32B32_FLOAT, 3));
	m_mFormatSize.insert(std::pair<unsigned int, unsigned int>(TF_R32G32B32_UINT, 3));
	m_mFormatSize.insert(std::pair<unsigned int, unsigned int>(TF_R32G32_FLOAT, 2));
	m_mFormatSize.insert(std::pair<unsigned int, unsigned int>(TF_R32G32_UINT, 2));
	m_mFormatSize.insert(std::pair<unsigned int, unsigned int>(TF_R32_FLOAT, 1));
	m_mFormatSize.insert(std::pair<unsigned int, unsigned int>(TF_R32_UINT, 1));
}

unsigned int CInputLayoutOGL::GetSize(unsigned int Format)
{
	if (m_mFormatSize.find(Format) != m_mFormatSize.end())
	{
		return m_mFormatSize.at(Format);
	}
	else
	{
		return 0;
	}
}
