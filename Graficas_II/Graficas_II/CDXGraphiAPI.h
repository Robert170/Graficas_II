#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>

#include "CGraphiAPI.h"
#include "CTextureDX.h"
#include "CBufferDX.h"
#include "CVertexShaderDX.h"
#include "CPixelShaderDX.h"
#include "CSamplerStateDX.h"


class CDXGraphiAPI : public CGraphiAPI
{
private:
	HWND m_hWnd = nullptr;

	ID3D11Device* m_pd3dDevice;
	ID3D11DeviceContext* m_pImmediateContext;
	IDXGISwapChain* m_pSwapChain;

	ID3D11RenderTargetView* g_pRenderTargetView;
	ID3D11Texture2D* g_pDepthStencil;
	ID3D11DepthStencilView* g_pDepthStencilView;

	ID3DBlob* m_VSBlob;
	ID3DBlob* m_PSBlob;

	CTextureDX m_BackBuffer;

protected:
	void InitWindow(unsigned int width, unsigned int height) override;
	void CreateDeviceandSwap() override;
	void CreateDeferredContext() override;
public:
	CDXGraphiAPI();
	~CDXGraphiAPI();

	void Init(unsigned int width, unsigned int height) override;

	//create
    
	
	CBuffer* CreateVertexBuffer(SimpleVertex Ver[],
		                            unsigned int bindFlags) override;
	CBuffer* CreateIndexBuffer(unsigned int Ind[],
		                           unsigned int bindFlags) override;
	CBuffer* CreateConstantBufferNC(CBNeverChanges CBNC,
		                            unsigned int bindFlags) override;
	CBuffer* CreateConstantBufferCOR(CBChangeOnResize CBCR,
		                             unsigned int bindFlags) override;
	CBuffer* CreateConstantBufferCEF(CBChangesEveryFrame CBCEF,
		                             unsigned int bindFlags) override;
    
    void CreateTexture1D() override;
    
	CTexture* CreateTexture2D(unsigned int width,
							  unsigned int height,
							  TEXTURE_FORMAT format = TF_R8G8B8A8_UNORM,
							  unsigned int bindFlags = TEXTURE_BIND_SHADER_RESOURCE) override;

    void CreateTexture3D() override;
	CPixelShader* CreatePixelShaders(std::string FileName,
		                     std::string Entry = "",
		                     std::string ShaderModel = "",
		                     int ID = 1) override;
	CVertexShader* CreateVertexShaders(std::string FileName,
		                     std::string Entry = "",
		                     std::string ShaderModel = "",
		                     int ID = 1) override;
	CInputLayout* CreateInputLayout() override;
	CSamplerState* CreateSamplerState() override;
    void CreateRasterizerState() override;
    

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
	void SetVertexShaders(CVertexShader * Vertex)override;
	void SetInputLayout(CInputLayout* Inp) override;
	void SetSamplerState(CSamplerState* Sam, 
		                 unsigned int StartSlot,
		                 unsigned int NumSamplers) override;
	void SetDepthStencil() override;
	void SetRasterizerState() override;
	void SetRenderTarget(CTexture* pRTTex, CTexture* pDSTex = nullptr) override;
	void SetDepthStencil() override;
	void SetShaderResouerce(CTexture* pRTTex) override;

	void Drawindex(int SizeIndex, int StartindexLocation) override;
	void Present() override;
};

