#include "COGLGraphiAPI.h"
#include "CPixelShaderOGL.h"
#include "CVertexShaderOGL.h"
#include "CTextureOGL.h"
#include "CIndexBufferOGL.h"
#include "CVertexBufferOGL.h"
#include "CConstantBufferOGL.h"
#include "CInputLayoutOGL.h"
#include "CSamplerStateOGL.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void COGLGraphiAPI::InitWindow(unsigned int width, 
	                           unsigned int height)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(width, height, "LearnOpenGL", nullptr, nullptr);
	if (m_window == nullptr)
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


CVertexBuffer* COGLGraphiAPI::CreateVertexBuffer(const std::vector <SimpleVertex>& Ver,
	                                             unsigned int BufferSize,
	                                             unsigned int NumBuffer)
{
	auto VertexBuffer = new CVertexBufferOGL();

	glGenBuffers(NumBuffer, 
		         &VertexBuffer->m_VBO);
	glBufferData(GL_ARRAY_BUFFER, 
		         Ver.size()* BufferSize, 
		         Ver.data(), 
		         GL_STATIC_DRAW);

	return VertexBuffer;
}

CIndexBuffer* COGLGraphiAPI::CreateIndexBuffer(const std::vector<unsigned int>& Ind,
	                                           unsigned int BufferSize,
	                                           unsigned int NumBuffer)
{
	auto IndexBuffer = new CIndexBufferOGL();

	glGenBuffers(NumBuffer, 
		         &IndexBuffer->m_IBO);
	
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 
		         Ind.size()* BufferSize, 
		         Ind.data(), 
		         GL_STATIC_DRAW);

	return IndexBuffer;
}

CConstantBuffer* COGLGraphiAPI::CreateConstantBuffer(unsigned int BufferSize,
	                                                 unsigned int NumBuffer)
{
	auto ConstantBuffer = new CConstantBufferOGL();

	glGenBuffers(BufferSize,
		         &ConstantBuffer->m_CBO);
	//glBufferData(GL_UNIFORM_BUFFER, BufferSize, &shader_data, GL_DYNAMIC_DRAW);
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
	

	//Checar que interfaces se van a crear
	if (bindFlags & TEXTURE_BIND_SHADER_RESOURCE)
	{//Crear SRV
		//flata arreglar
		glTextureView(0, 0, 0, 0, 0, 0, 0, 0);
	}
	if (bindFlags & TEXTURE_BIND_DEPTH_STENCIL)
	{//Crear DSV

		glGenRenderbuffers(bindFlags,
			               &Texture->m_DSV);
		glRenderbufferStorage(GL_RENDERBUFFER, 
			                  GL_DEPTH_COMPONENT, 
			                  width,
			                  height);
	}
	if (bindFlags & TEXTURE_BIND_RENDER_TARGET)
	{//Crear RTV
		
		glGenFramebuffers(numberTexture, &Texture->m_RTV);
	}
	if (bindFlags & TEXTURE_BIND_UNORDERED_ACCESS)
	{//Crear UAV
		

	}

	glGenTextures(numberTexture, 
		          &Texture->m_Texture);

	glBindTexture(GL_TEXTURE_2D, 
		          Texture->m_Texture);

	glTexImage2D(GL_TEXTURE_2D, 
		         0, 
		         GL_RGB, 
		         width, 
		         height, 
		         0, 
		         GL_RGB, 
		         GL_UNSIGNED_BYTE, 
		         0);

	glTexParameteri(GL_TEXTURE_2D, 
		            GL_TEXTURE_MAG_FILTER, 
		            GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, 
		            GL_TEXTURE_MIN_FILTER, 
		            GL_NEAREST);

	return Texture;
}


void COGLGraphiAPI::CreateTexture3D()
{
}

CPixelShader* COGLGraphiAPI::CreatePixelShaders(const std::string &FileName,
	                                            const std::string &Entry,
	                                            const std::string &ShaderModel,
	                                            int ID)
{
	// Pixel Shader
	auto PixelShader = new CPixelShaderOGL();
	const char* PixelCode = PixelShader->ReadFile(FileName).c_str();
	PixelShader->m_PixelShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(PixelShader->m_PixelShader, ID, &PixelCode, NULL);


	return PixelShader;

}

CVertexShader* COGLGraphiAPI::CreateVertexShaders(const std::string &FileName,
	                                              const std::string &Entry,
	                                              const std::string &ShaderModel,
	                                              int ID)
{
	// vertex Shader
	auto VertexShader = new CVertexShaderOGL();

	const char* VertexCode = VertexShader->ReadFile(FileName).c_str();

	VertexShader->m_VertexShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(VertexShader->m_VertexShader, ID, &VertexCode, NULL);

	return VertexShader;
}

CInputLayout* COGLGraphiAPI::CreateInputLayout(CVertexShader* &Vertex,
	                                           const std::vector<std::string> &SemanticName,
	                                           unsigned int NumInputLayout)
{
	auto InputLa = new CInputLayoutOGL();

	glGenVertexArrays(NumInputLayout,
		              &InputLa->m_IPLA);

	return InputLa;
}

CSamplerState* COGLGraphiAPI::CreateSamplerState(unsigned int NumSamplerState)
{
	auto SamplerState = new CSamplerStateOGL();

	glGenSamplers(NumSamplerState, 
		          &SamplerState->m_SamSt);

	glSamplerParameteri(SamplerState->m_SamSt, 
		                GL_TEXTURE_WRAP_S, GL_REPEAT);

	glSamplerParameteri(SamplerState->m_SamSt, 
		                GL_TEXTURE_WRAP_T, GL_REPEAT);

	glSamplerParameteri(SamplerState->m_SamSt, 
		                GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glSamplerParameteri(SamplerState->m_SamSt, 
		                GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glSamplerParameterf(SamplerState->m_SamSt, 
	                	GL_TEXTURE_MAX_ANISOTROPY, 16.0f);
	return SamplerState;
}

CRasterizerState* COGLGraphiAPI::CreateRasterizerState()
{
	return nullptr;
}

void COGLGraphiAPI::SetVertexBuffer(CVertexBuffer* &VerBuff,
	                                unsigned int StartSlot,
	                                unsigned int NumBuffer,
	                                unsigned int stride,
	                                unsigned int offset)
{
	auto VertBuff = reinterpret_cast<CVertexBufferOGL*>(VerBuff);
	glBindBuffer(GL_ARRAY_BUFFER, VertBuff->m_VBO);

	
}

void COGLGraphiAPI::SetIndexBuffer(CIndexBuffer* &IndBuff,
	                               unsigned int offset)
{
	auto IndexBuff = reinterpret_cast<CIndexBufferOGL*>(IndBuff);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuff->m_IBO);
}

void COGLGraphiAPI::SetVertexShaderConstantBuffer(CConstantBuffer* &ConstBuff,
	                                              unsigned int StartSlot,
	                                              unsigned int NumBuffer)
{
}

void COGLGraphiAPI::SetPixelShaderConstantBuffer(CConstantBuffer*& ConstBuff, 
	                                             unsigned int StartSlot, 
	                                             unsigned int NumBuffer)
{
}

void COGLGraphiAPI::SetPixelShaders(CPixelShader* &Pixel)
{
	auto PixelSh = reinterpret_cast<CPixelShaderOGL*>(Pixel);
	glCompileShader(PixelSh->m_PixelShader);
	glAttachShader(m_AttachShaderID, PixelSh->m_PixelShader);

	//delete shader
	glDeleteShader(PixelSh->m_PixelShader);
}

void COGLGraphiAPI::SetVertexShaders(CVertexShader* &Vertex)
{
	auto VertexSh = reinterpret_cast<CVertexShaderOGL*>(Vertex);

	glCompileShader(VertexSh->m_VertexShader);

	glAttachShader(m_AttachShaderID, VertexSh->m_VertexShader);

	glDeleteShader(VertexSh->m_VertexShader);
}

void COGLGraphiAPI::SetInputLayout(CInputLayout* &Inp)
{
	auto InpL = reinterpret_cast<CInputLayoutOGL*>(Inp);
	glBindVertexArray(InpL->m_IPLA);
}

void COGLGraphiAPI::SetSamplerState(const std::vector<CSamplerState*>& Sam,
	                                unsigned int StartSlot)
{
	for (int i = 0; i < Sam.size(); i++)
	{
		auto SamSt = reinterpret_cast<CSamplerStateOGL*>(Sam.at(i));

		glBindSampler(StartSlot, SamSt->m_SamSt);
	}
}


void COGLGraphiAPI::SetDepthStencil(CTexture* &pDSTex)
{
	auto DepSten = reinterpret_cast<CTextureOGL*>(pDSTex);

	glBindRenderbuffer(GL_RENDERBUFFER, 
		               DepSten->m_DSV);

	glFramebufferRenderbuffer(GL_FRAMEBUFFER, 
		                      GL_DEPTH_ATTACHMENT, 
		                      GL_RENDERBUFFER, 
		                      DepSten->m_DSV);
}

void COGLGraphiAPI::SetShaderResource(const std::vector<CTexture*>& pRTTex,
	                                  unsigned int StartSlot)
{
	for (int i = 0; i < pRTTex.size(); i++)
	{
		auto SamSt = reinterpret_cast<CTextureOGL*>(pRTTex.at(i));

		//glTextureView()
	}
	
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

void COGLGraphiAPI::SetPrimitiveTopology(PRIMITIVE_TOPOLOGY Topology)
{
}

void COGLGraphiAPI::ClearRenderTarget(CTexture* &RT,
	                                 ColorStruct Color)
{
}

void COGLGraphiAPI::ClearDepthStencil(CTexture* &RT,
	                                  unsigned int ClerFlag,
	                                  float Depth, 
	                                  unsigned int Stencil)
{
}

void COGLGraphiAPI::SetRasterizerState(CRasterizerState* &RasState)
{
}

void COGLGraphiAPI::SetRenderTarget(const std::vector<CTexture*>& pRTTex,
	                                CTexture* pDSTex)
{
	for (int i = 0; i < pRTTex.size(); i++)
	{
		auto pRTDX = reinterpret_cast<CTextureOGL*>(pRTTex.at(i));

		/*ID3D11DepthStencilView* pDSV = nullptr;

		if (nullptr != pDSTex)
		{
			auto pDSDX = reinterpret_cast<CTextureOGL*>(pDSTex);
			pDSV = pDSDX->m_DSV;
		}*/

		glBindFramebuffer(GL_FRAMEBUFFER, 
			              pRTDX->m_RTV);

		glFramebufferTexture(GL_FRAMEBUFFER, 
			                 GL_COLOR_ATTACHMENT0, 
			                 pRTDX->m_Texture, 
			                 i);
	}
}

//glDrawBuffers donde usar?

void COGLGraphiAPI::DrawIndexed(unsigned int NumIndex,
	                            unsigned int StartindexLocation,
	                            unsigned int BaseVertexLocation)
{
	//glDrawElements(GL_TRIANGLES, NumIndex, GL_UNSIGNED_BYTE, GL_ELEMENT_ARRAY_BUFFER)
}
void COGLGraphiAPI::DrawInstanced(unsigned int VertexCountPerInstance, 
	                              unsigned int InstanceCount, 
	                              unsigned int StartVertexLocation, 
	                              unsigned int StartInstanceLocation)
{
}

void COGLGraphiAPI::Draw(unsigned int VertexCount, 
	                     unsigned int StartVertexLocation)
{
	glDrawArrays(GL_TRIANGLES, StartVertexLocation, VertexCount);
}

void COGLGraphiAPI::Present()
{
	glfwSwapBuffers(m_window);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
