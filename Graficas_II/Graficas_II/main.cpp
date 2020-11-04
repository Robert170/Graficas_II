#include "CGraphiAPI.h"
#include "COGLGraphiAPI.h"
#include "CDXGraphiAPI.h"

CGraphiAPI* API = new CDXGraphiAPI();
//CGraphiAPI* API = new COGLGraphiAPI();

CTexture* g_pRenderTarget = nullptr;
CTexture* g_pDepthStencil = nullptr;
CTexture* g_pShaderResource = nullptr;
std::vector<CTexture*>g_vTextures;
std::vector<std::string>g_vTextures;

/// <summary>
/// //////////////////
/// </summary>
ID3D11VertexShader* g_pVertexShader = NULL;//
ID3D11PixelShader* g_pPixelShader = NULL;//
ID3D11InputLayout* g_pVertexLayout = NULL;//
ID3D11Buffer* g_pVertexBuffer = NULL;//
ID3D11Buffer* g_pIndexBuffer = NULL;//
ID3D11Buffer* g_pCBNeverChanges = NULL;//
ID3D11Buffer* g_pCBChangeOnResize = NULL;//
ID3D11Buffer* g_pCBChangesEveryFrame = NULL;//
ID3D11ShaderResourceView* g_pTextureRV = NULL;//
ID3D11SamplerState* g_pSamplerLinear = NULL;

int main()
{

	//while (true)
	//{

		API->Init(800, 
			      600);

		
		//Create render Target
		g_pRenderTarget = API->CreateTexture2D(800,
			                                   600, 
			                                   1, 
			                                   TF_R8G8B8A8_UNORM, 
			                                   TEXTURE_BIND_RENDER_TARGET);
		g_vTextures.push_back(g_pRenderTarget);
		// Create the depth stencil 
		g_pDepthStencil = API->CreateTexture2D(800,
			                                   600,
			                                   1,
			                                   TF_D24_UNORM_S8_UINT,
			                                   TEXTURE_BIND_DEPTH_STENCIL);

		API->SetRenderTarget(g_vTextures, g_pDepthStencil);

		// Setup the viewport
		API->SetViewport(1, 
			             800,
			             600);

		// Create the vertex shader
		API->CreateVertexShaders("Tutorial07.fx", "VS", "vs_4_0");
	//}
	
	return 0;
}

