#include "COGLGraphiAPI.h"
#include "CPixelShaderOGL.h"
#include "CVertexShaderOGL.h"
#include "CTextureOGL.h"
#include "CIndexBufferOGL.h"
#include "CVertexBufferOGL.h"
#include "CConstantBufferOGL.h"
#include "CInputLayoutOGLOGL.h"
#include "CSamplerStateOGLOGL.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void COGLGraphiAPI::InitWindow(unsigned int width, 
	                           unsigned int height, 
	                           HINSTANCE hInstance,
	                           int nCmdShow)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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


void COGLGraphiAPI::CreateDeviceandSwap()
{
	glfwInit();
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


CBuffer* COGLGraphiAPI::CreateVertexBuffer(unsigned int bindFlags,
	                                       std::vector <SimpleVertex> Ver,
	                                       unsigned int ID)
{
	auto VertexBuffer = new CBufferOGL();

	glGenBuffers(ID, &VertexBuffer->m_VBO);
	glBufferData(GL_ARRAY_BUFFER, Ver.size(), Ver.data(), GL_STATIC_DRAW);

	return VertexBuffer;
}

CBuffer* COGLGraphiAPI::CreateIndexBuffer(unsigned int bindFlags,
	                                      std::vector<unsigned int> Ind,
	                                      unsigned int ID)
{
	auto IndexBuffer = new CBufferOGL();

	glGenBuffers(ID, &IndexBuffer->m_IBO);
	
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Ind.size(), Ind.data(), GL_STATIC_DRAW);

	return IndexBuffer;
}

CBuffer* COGLGraphiAPI::CreateConstantBufferNC(unsigned int bindFlags)
{
	return nullptr;
}

CBuffer* COGLGraphiAPI::CreateConstantBufferCOR(unsigned int bindFlags)
{
	return nullptr;
}

CBuffer* COGLGraphiAPI::CreateConstantBufferCEF(unsigned int bindFlags)
{
	return nullptr;
}

void COGLGraphiAPI::CreateTexture1D()
{
}

CTexture* COGLGraphiAPI::CreateTexture2D(unsigned int width,
	                                     unsigned int height,
	                                     unsigned int numberTexture,
	                                     TEXTURE_FORMAT format,
	                                     unsigned int bindFlags,
	                                     TYPE_USAGE Usage)
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
	return Texture;
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

	/*glCompileShader(PixelShader->m_PixelShader);
	glAttachShader(m_AttachShaderID, PixelShader->m_PixelShader);

	glDeleteShader(PixelShader->m_PixelShader);*/

	return PixelShader;

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

	return VertexShader;
}

CInputLayout* COGLGraphiAPI::CreateInputLayout(unsigned int ID)
{
	auto InputLa = new CInputLayoutOGL();

	glGenVertexArrays(ID, &InputLa->m_IPLA);

	return InputLa;
}

CSamplerState* COGLGraphiAPI::CreateSamplerState(unsigned int ID)
{
	auto SamplerState = new CSamplerStateOGL();

	glGenSamplers(ID, &SamplerState->m_SamSt);

	glSamplerParameteri(SamplerState->m_SamSt, 
		                GL_TEXTURE_WRAP_S, GL_REPEAT);

	glSamplerParameteri(SamplerState->m_SamSt, 
		                GL_TEXTURE_WRAP_T, GL_REPEAT);

	glSamplerParameteri(SamplerState->m_SamSt, 
		                GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glSamplerParameteri(SamplerState->m_SamSt, 
		                GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glSamplerParameterf(SamplerState->m_SamSt, 
		                GL_TEXTURE_MAX_ANISOTROPY_EXT, 16.0f);
	return SamplerState;
}

CRasterizerState* COGLGraphiAPI::CreateRasterizerState()
{
	return nullptr;
}

void COGLGraphiAPI::SetVertexBuffer(CBuffer* VerBuff, 
	                                unsigned int StartSlot, 
	                                unsigned int NumBuffer, 
	                                unsigned int stride, 
	                                unsigned int offset)
{
	auto VertBuff = reinterpret_cast<CBufferOGL*>(VerBuff);
	glBindBuffer(GL_ARRAY_BUFFER, VertBuff->m_VBO);

	
}

void COGLGraphiAPI::SetIndexBuffer(CBuffer* IndBuff, 
	                               unsigned int offset)
{
	auto IndexBuff = reinterpret_cast<CBufferOGL*>(IndBuff);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuff->m_IBO);
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
	auto PixelSh = reinterpret_cast<CPixelShaderOGL*>(Pixel);
	glCompileShader(PixelSh->m_PixelShader);
	glAttachShader(m_AttachShaderID, PixelSh->m_PixelShader);

	//delete shader
	glDeleteShader(PixelSh->m_PixelShader);
}

void COGLGraphiAPI::SetVertexShaders(CVertexShader* Vertex)
{
	auto VertexSh = reinterpret_cast<CVertexShaderOGL*>(Vertex);

	glCompileShader(VertexSh->m_VertexShader);

	glAttachShader(m_AttachShaderID, VertexSh->m_VertexShader);

	glDeleteShader(VertexSh->m_VertexShader);
}

void COGLGraphiAPI::SetInputLayout(CInputLayout* Inp)
{
	auto InpL = reinterpret_cast<CInputLayoutOGL*>(Inp);
	glBindVertexArray(InpL->m_IPLA);
}

void COGLGraphiAPI::SetSamplerState(CSamplerState* Sam, 
	                                unsigned int StartSlot, 
	                                unsigned int NumSamplers)
{
	auto SamSt = reinterpret_cast<CSamplerStateOGL*>(Sam);

	glBindSampler(StartSlot, SamSt->m_SamSt);
}


void COGLGraphiAPI::SetDepthStencil()
{
}

void COGLGraphiAPI::SetShaderResource(CTexture* pRTTex,
	                                  unsigned int StartSlot,
	                                  unsigned int NumSamplers)
{
	//glTextureView()
}

void COGLGraphiAPI::SetViewport(unsigned int NumViewport, 
	                            float Width, 
	                            float Height, 
	                            float TopLeftX, 
	                            float TopLeftY)
{
	glViewport(TopLeftX,
		       TopLeftY,
		       Width,
		       Height);
}

void COGLGraphiAPI::ClearRendTarView(CTexture* RT, 
	                                 std::vector<float> ClearColor)
{
}

void COGLGraphiAPI::ClearDepthStenView(CTexture* RT, 
	                                   CLEAR_FLAG ClerFlag, 
	                                   float Depth, 
	                                   unsigned int Stencil)
{
}

void COGLGraphiAPI::SetRasterizerState(CRasterizerState* RasState)
{
}

void COGLGraphiAPI::SetRenderTarget(CTexture* pRTTex,
	                                CTexture* pDSTex,
	                                unsigned int NumView)
{
}


void COGLGraphiAPI::Drawindexed(int NumIndex, 
	                            int StartindexLocation)
{
	glDrawArrays(GL_TRIANGLES, StartindexLocation, NumIndex);
}

void COGLGraphiAPI::Present()
{
	glfwSwapBuffers(m_window);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
