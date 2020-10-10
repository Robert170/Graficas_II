#include "COGLGraphiAPI.h"
#include "CPixelShaderOGL.h"
#include "CVertexShaderOGL.h"


void COGLGraphiAPI::CreateInputLayout()
{
}

void COGLGraphiAPI::CreateSamplerState()
{
}

void COGLGraphiAPI::CreateRasterizerState()
{
}

void COGLGraphiAPI::SetIndexBuffer(unsigned int offset)
{
}

void COGLGraphiAPI::SetVertexBuffer(unsigned int stride,
	                                unsigned int offset)
{
}

void COGLGraphiAPI::SetConstantBuffer()
{
}

void COGLGraphiAPI::SetPixelShaders()
{
}

void COGLGraphiAPI::SetVertexShaders()
{
}



void COGLGraphiAPI::SetInputLayout()
{
}

void COGLGraphiAPI::SetSamplerState(unsigned int StartSlot,
	                                unsigned int NumSamplers)
{
}

void COGLGraphiAPI::SetDepthStencil()
{
}

void COGLGraphiAPI::SetShaderResouerce(CTexture* pRTTex)
{
}

void COGLGraphiAPI::SetRasterizerState()
{
}

void COGLGraphiAPI::SetRenderTarget(CTexture* pRTTex, CTexture* pDSTex)
{
}


void COGLGraphiAPI::Drawindex(int SizeIndex, int StartindexLocation)
{
	glDrawArrays(GL_TRIANGLES, StartindexLocation, SizeIndex);
}

void COGLGraphiAPI::Present()
{
}



void COGLGraphiAPI::InitWindow(unsigned int width, unsigned int height)
{
}

void COGLGraphiAPI::CreateDeviceandSwap()
{
}

void COGLGraphiAPI::CreateDeferredContext()
{
}

COGLGraphiAPI::COGLGraphiAPI()
{
}

COGLGraphiAPI::~COGLGraphiAPI()
{
}

void COGLGraphiAPI::Init(unsigned int width, unsigned int height)
{
	m_AttachShaderID = glCreateProgram();
}



void COGLGraphiAPI::CreateVertexBuffer(SimpleVertex Ver[],
	                                   unsigned int bindFlags)
{
}

void COGLGraphiAPI::CreateIndexBuffer(unsigned int Ind[],
	                                 unsigned int bindFlags)
{
}

void COGLGraphiAPI::CreateConstantBuffer(CBNeverChanges CBNC,
	                                     CBChangeOnResize CBCR,
	                                     CBChangesEveryFrame CBCEF,
	                                     unsigned int bindFlags)
{
}

void COGLGraphiAPI::CreateTexture1D()
{
}

CTexture* COGLGraphiAPI::CreateTexture2D(unsigned int width, 
	                                     unsigned int height, 
	                                     TEXTURE_FORMAT format, 
	                                     unsigned int bindFlags)
{
	return nullptr;
}


void COGLGraphiAPI::CreateTexture3D()
{
}

void COGLGraphiAPI::CreatePixelShaders(std::string FileName, 
	                                   std::string Entry, 
	                                   std::string ShaderModel, 
	                                   int ID)
{
	// Pixel Shader
	auto PixelShader = new CPixelShaderOGL();
	const char* PixelCode = PixelShader->ReadFile(FileName).c_str();
	PixelShader->m_PixelShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(PixelShader->m_PixelShader, ID, &PixelCode, NULL);
	glCompileShader(PixelShader->m_PixelShader);
	glAttachShader(m_AttachShaderID, PixelShader->m_PixelShader);
	
	glDeleteShader(PixelShader->m_PixelShader);

}

void COGLGraphiAPI::CreateVertexShaders(std::string FileName, 
	                                    std::string Entry, 
	                                    std::string ShaderModel, 
	                                    int ID)
{
	// vertex Shader
	auto VertexShader = new CVertexShaderOGL();
	const char* VertexCode = VertexShader->ReadFile(FileName).c_str();
	VertexShader->m_VertexShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(VertexShader->m_VertexShader, ID, &VertexCode, NULL);
	glCompileShader(VertexShader->m_VertexShader);
	glAttachShader(m_AttachShaderID, VertexShader->m_VertexShader);
	glDeleteShader(VertexShader->m_VertexShader);
}
