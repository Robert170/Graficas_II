#include "COGLGraphiAPI.h"
#include "CPixelShaderOGL.h"
#include "CVertexShaderOGL.h"
#include "CTextureOGL.h"
#include "CBufferOGL.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void COGLGraphiAPI::InitWindow(unsigned int width, unsigned int height)
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

void COGLGraphiAPI::Init(unsigned int width, unsigned int height)
{
	m_AttachShaderID = glCreateProgram();
	
	glfwInit();
	
	InitWindow(width, height);
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


CBuffer* COGLGraphiAPI::CreateVertexBuffer(unsigned int bindFlags,
	                                       std::vector <SimpleVertex> Ver,
	                                       unsigned int ID)
{
	auto VertexBuffer = new CBufferOGL();

	glGenBuffers(ID, &VertexBuffer->m_VBO);

	
	glGenVertexArrays(1, &VertexBuffer->m_VAO);

	return VertexBuffer;
}

CBuffer* COGLGraphiAPI::CreateIndexBuffer(unsigned int bindFlags,
	                                      std::vector<unsigned int> Ind,
	                                      unsigned int ID)
{
	return nullptr;
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

	/*glCompileShader(VertexShader->m_VertexShader);
	glAttachShader(m_AttachShaderID, VertexShader->m_VertexShader);
	glDeleteShader(VertexShader->m_VertexShader);*/

	return VertexShader;
}

CInputLayout* COGLGraphiAPI::CreateInputLayout()
{
	return nullptr;
}

CSamplerState* COGLGraphiAPI::CreateSamplerState()
{
	return nullptr;
}

CRasterizerState* COGLGraphiAPI::CreateRasterizerState()
{
}

void COGLGraphiAPI::SetVertexBuffer(CBuffer* VerBuff, 
	                                unsigned int StartSlot, 
	                                unsigned int NumBuffer, 
	                                unsigned int stride, 
	                                unsigned int offset)
{
	auto VertBuff = reinterpret_cast<CBufferOGL*>(VerBuff);
	glBindBuffer(GL_ARRAY_BUFFER, VertBuff->m_VBO);
	glBindVertexArray(VertBuff->m_VAO);
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
}

void COGLGraphiAPI::SetSamplerState(CSamplerState* Sam, unsigned int StartSlot, unsigned int NumSamplers)
{
}


void COGLGraphiAPI::SetDepthStencil()
{
}

void COGLGraphiAPI::SetShaderResource(CTexture* pRTTex,
	                                  unsigned int StartSlot,
	                                  unsigned int NumSamplers)
{
}

void COGLGraphiAPI::SetViewport(unsigned int NumViewport, 
	                            float Width, 
	                            float Height, 
	                            float TopLeftX, 
	                            float TopLeftY)
{
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


void COGLGraphiAPI::Drawindex(int SizeIndex, int StartindexLocation)
{
	glDrawArrays(GL_TRIANGLES, StartindexLocation, SizeIndex);
}

void COGLGraphiAPI::Present()
{
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
