#include "COGLGraphiAPI.h"
#include "CPixelShaderOGL.h"
#include "CVertexShaderOGL.h"
#include "CTextureOGL.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void COGLGraphiAPI::InitWindow(unsigned int width, unsigned int height)
{
	m_window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);

}

void COGLGraphiAPI::Init(unsigned int width, unsigned int height)
{
	m_AttachShaderID = glCreateProgram();
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	InitWindow(width, height);
}



void COGLGraphiAPI::CreateRasterizerState()
{
}

void COGLGraphiAPI::SetVertexBuffer(CBuffer* VerBuff, 
	                                unsigned int StartSlot, 
	                                unsigned int NumBuffer, 
	                                unsigned int stride, 
	                                unsigned int offset)
{
}

void COGLGraphiAPI::SetIndexBuffer(CBuffer* IndBuff, unsigned int offset)
{
}

void COGLGraphiAPI::SetConstantBufferNC(CBuffer* ConstBuff, 
	                                    unsigned int StartSlot, 
	                                    unsigned int NumBuffer)
{
}

void COGLGraphiAPI::SetConstantBufferCOR(CBuffer* ConstBuff, 
	                                     unsigned int StartSlot, 
	                                     unsigned int NumBuffer)
{
}

void COGLGraphiAPI::SetConstantBufferCEF(CBuffer* ConstBuff, 
	                                     unsigned int StartSlot, 
	                                     unsigned int NumBuffer)
{
}

void COGLGraphiAPI::SetPixelShaders(CPixelShader* Pixel)
{
}

void COGLGraphiAPI::SetVertexShaders(CVertexShader* Vertex)
{
}

void COGLGraphiAPI::SetInputLayout(CInputLayout* Inp)
{
}

void COGLGraphiAPI::SetSamplerState(CSamplerState* Sam, unsigned int StartSlot, unsigned int NumSamplers)
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


CBuffer* COGLGraphiAPI::CreateVertexBuffer(SimpleVertex Ver[], 
	                                       unsigned int bindFlags)
{
	return nullptr;
}

CBuffer* COGLGraphiAPI::CreateIndexBuffer(unsigned int Ind[], 
	                                      unsigned int bindFlags)
{
	return nullptr;
}

CBuffer* COGLGraphiAPI::CreateConstantBufferNC(CBNeverChanges CBNC, 
	                                           unsigned int bindFlags)
{
	return nullptr;
}

CBuffer* COGLGraphiAPI::CreateConstantBufferCOR(CBChangeOnResize CBCR, 
	                                            unsigned int bindFlags)
{
	return nullptr;
}

CBuffer* COGLGraphiAPI::CreateConstantBufferCEF(CBChangesEveryFrame CBCEF, 
	                                            unsigned int bindFlags)
{
	return nullptr;
}

void COGLGraphiAPI::CreateTexture1D()
{
}

CTexture* COGLGraphiAPI::CreateTexture2D(unsigned int width, 
	                                     unsigned int height, 
	                                     TEXTURE_FORMAT format, 
	                                     unsigned int bindFlags, 
	                                     TYPE_USAGE Usage,
	                                     unsigned int numberTexture)
{
	auto Texture = new CTextureOGL();
	glGenTextures(numberTexture, &Texture->m_texture);
	glBindTexture(GL_TEXTURE_2D, Texture->m_texture);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return nullptr;
}


void COGLGraphiAPI::CreateTexture3D()
{
}

CPixelShader* COGLGraphiAPI::CreatePixelShaders(std::string FileName,
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

	return nullptr;

}

CVertexShader* COGLGraphiAPI::CreateVertexShaders(std::string FileName,
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

	return nullptr;
}

CInputLayout* COGLGraphiAPI::CreateInputLayout()
{
	return nullptr;
}

CSamplerState* COGLGraphiAPI::CreateSamplerState()
{
	return nullptr;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
