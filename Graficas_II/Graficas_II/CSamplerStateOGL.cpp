#include "CSamplerStateOGL.h"

CSamplerStateOGL::~CSamplerStateOGL()
{
	glDeleteSamplers(m_NumberOfSampler,
		             &m_SamSt);
}
