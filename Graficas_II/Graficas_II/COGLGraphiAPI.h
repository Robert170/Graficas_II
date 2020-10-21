#pragma once
#include "glad.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "CGraphiAPI.h"
class COGLGraphiAPI : public CGraphiAPI
{
public:

	unsigned int m_AttachShaderID;
	GLFWwindow* m_window;

protected:
	void InitWindow(unsigned int width, 
		            unsigned int height) override;
	
	void CreateDeviceandSwap() override;

	void CreateDeferredContext() override;

public:
	COGLGraphiAPI();
	~COGLGraphiAPI();

	void Init(unsigned int width, unsigned int height) override;

	//create
	CBuffer* CreateVertexBuffer(unsigned int bindFlags,
		                        std::vector <SimpleVertex> Ver,
		                        unsigned int ID) override;

	CBuffer* CreateIndexBuffer(unsigned int bindFlags,
		                       std::vector<unsigned int> Ind,
		                       unsigned int ID) override;

	CBuffer* CreateConstantBufferNC(unsigned int bindFlags) override;

	CBuffer* CreateConstantBufferCOR(unsigned int bindFlags) override;

	CBuffer* CreateConstantBufferCEF(unsigned int bindFlags) override;

	void CreateTexture1D() override;

	CTexture* CreateTexture2D(unsigned int width,
		                      unsigned int height,
		                      unsigned int numberTexture,
		                      TEXTURE_FORMAT format,
		                      unsigned int bindFlags,
		                      TYPE_USAGE Usage) override;

	void CreateTexture3D() override;

	CPixelShader* CreatePixelShaders(std::string FileName,
		                             std::string Entry,
		                             std::string ShaderModel,
		                             int ID) override;

	CVertexShader* CreateVertexShaders(std::string FileName,
		                               std::string Entry,
		                               std::string ShaderModel,
		                               int ID) override;

	CInputLayout* CreateInputLayout() override;

	CSamplerState* CreateSamplerState() override;

	CRasterizerState* CreateRasterizerState() override;


	//set
	void SetVertexBuffer(CBuffer* VerBuff,
		                 unsigned int StartSlot,
		                 unsigned int NumBuffer,
		                 unsigned int stride,
		                 unsigned int offset) override;

	void SetIndexBuffer(CBuffer* IndBuff,
		                unsigned int offset)override;

	void SetConstantBufferNC(CBuffer* ConstBuff,
		                     unsigned int StartSlot,
		                     unsigned int NumBuffer) override;

	void SetConstantBufferCOR(CBuffer* ConstBuff,
		                      unsigned int StartSlot,
		                      unsigned int NumBuffer) override;

	void SetConstantBufferCEF(CBuffer* ConstBuff,
		                      unsigned int StartSlot,
		                      unsigned int NumBuffer) override;

	void SetPixelShaders(CPixelShader* Pixel) override;

	void SetVertexShaders(CVertexShader* Vertex)override;

	void SetInputLayout(CInputLayout* Inp) override;

	void SetSamplerState(CSamplerState* Sam,
		                 unsigned int StartSlot,
		                 unsigned int NumSamplers) override;
	void SetDepthStencil() override;

	void SetRasterizerState(CRasterizerState* RasState) override;

	void SetRenderTarget(CTexture* pRTTex,
		                 CTexture* pDSTex,
		                 unsigned int NumView) override;

	void SetDepthStencil() override;

	void SetShaderResouerce(CTexture* pRTTex,
		                    unsigned int StartSlot,
		                    unsigned int NumSamplers) override;

	void SetViewport(unsigned int NumViewport,
		             float Width,
		             float Height,
		             float TopLeftX,
		             float TopLeftY) override;

	//clear
	void ClearRendTarView(CTexture* RT,
		                  std::vector<float> ClearColor) override;

	void ClearDepthStenView(CTexture* RT,
		                    CLEAR_FLAG ClerFlag,
		                    float Depth,
		                    unsigned int Stencil) override;

	//draw
	void Drawindex(int SizeIndex, int StartindexLocation) override;

	void Present() override;
};

