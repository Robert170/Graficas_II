#include "CGraphiAPI.h"
#include "COGLGraphiAPI.h"
#include "CDXGraphiAPI.h"
#include <windows.h>

CGraphiAPI* API = new CDXGraphiAPI();
//CGraphiAPI* API = new COGLGraphiAPI();

//Textures
CTexture* g_pRenderTarget = nullptr;
CTexture* g_pDepthStencil = nullptr;
CTexture* g_pShaderResource = nullptr;

std::vector<CTexture*> g_vRenderTargets;
std::vector<CTexture*> g_vShaderResources;
std::vector<CSamplerState*> g_vSamplers;
std::vector<CConstantBuffer*> g_vConstantBuffers;
std::vector<std::string> g_vSemanticNames;

//Shader
CVertexShader* g_pVertexShader = nullptr;
CPixelShader* g_pPixelShader = nullptr;

CInputLayout* g_pInputLayout = nullptr;

//Buffers
CVertexBuffer* g_pVertexBuffer = nullptr;
CIndexBuffer* g_pIndexBuffer = nullptr;
CConstantBuffer* g_pCBNeverChanges = nullptr;

//Sampler
CSamplerState* g_pSamplerState = nullptr;

//World matrix
glm::mat4 g_World;
glm::mat4 g_View;
glm::mat4 g_Projection;

glm::vec4 g_MeshColor;

ColorStruct Color;

InputLayout_Desc g_InpLayDesc;



struct CBNeverChanges
{
	glm::mat4x4 mView;
	glm::mat4x4 mProjection;
	glm::mat4x4 mWorld;
	glm::vec4 vMeshColor;
};

CBNeverChanges g_ConstantBuffer;

std::vector<uint32_t> indices =
{
	3,1,0,
	2,1,3,

	6,4,5,
	7,4,6,

	11,9,8,
	10,9,11,

	14,12,13,
	15,12,14,

	19,17,16,
	18,17,19,

	22,20,21,
	23,20,22
};

void Init()
{



	CCameraDatas Data;
	Data.Far = 100;
	Data.Fov = 0.7f;
	Data.H = 800;
	Data.W = 600;
	Data.Near = 1.0f;

	glm::vec3 Eye = { 0.0f, 3.0f, -6.0f };
	glm::vec3 At = { 0.0f, 1.0f, 0.0f };
	glm::vec3 Up = { 0.0f, 1.0f, 0.0f };

	

	std::vector<SimpleVertex> vertices =
	{
		// positions                    // texture coords
		{glm::vec3(-1.0f, 1.0f, -1.0f),  glm::vec2(0.0f, 0.0f) },
		{glm::vec3(1.0f, 1.0f, -1.0f),   glm::vec2(1.0f, 0.0f) },
		{glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1.0f, 1.0f) },
		{glm::vec3(-1.0f, 1.0f, 1.0f),   glm::vec2(0.0f, 1.0f) },

		{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f) },
		{glm::vec3(1.0f, -1.0f, -1.0f),  glm::vec2(1.0f, 0.0f) },
		{glm::vec3(1.0f, -1.0f, 1.0f),   glm::vec2(1.0f, 1.0f) },
		{glm::vec3(-1.0f, -1.0f, 1.0f),  glm::vec2(0.0f, 1.0f) },

		{glm::vec3(-1.0f, -1.0f, 1.0f),  glm::vec2(0.0f, 0.0f) },
		{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(1.0f, 0.0f) },
		{glm::vec3(-1.0f, 1.0f, -1.0f),  glm::vec2(1.0f, 1.0f) },
		{glm::vec3(-1.0f, 1.0f, 1.0f),   glm::vec2(0.0f, 1.0f) },

		{glm::vec3(1.0f, -1.0f, 1.0f),   glm::vec2(0.0f, 0.0f) },
		{glm::vec3(1.0f, -1.0f, -1.0f),  glm::vec2(1.0f, 0.0f) },
		{glm::vec3(1.0f, 1.0f, -1.0f),   glm::vec2(1.0f, 1.0f) },
		{glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(0.0f, 1.0f) },

		{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f) },
		{glm::vec3(1.0f, -1.0f, -1.0f),  glm::vec2(1.0f, 0.0f) },
		{glm::vec3(1.0f, 1.0f, -1.0f),   glm::vec2(1.0f, 1.0f) },
		{glm::vec3(-1.0f, 1.0f, -1.0f),  glm::vec2(0.0f, 1.0f) },

		{glm::vec3(-1.0f, -1.0f, 1.0f),  glm::vec2(0.0f, 0.0f) },
		{glm::vec3(1.0f, -1.0f, 1.0f),   glm::vec2(1.0f, 0.0f) },
		{glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec2(1.0f, 1.0f) },
		{glm::vec3(-1.0f, 1.0f, 1.0f),   glm::vec2(0.0f, 1.0f) },
	};


	g_MeshColor.x = 1;
	g_MeshColor.y = 1;
	g_MeshColor.z = 1;


	API->Init(800,
		      600);

	//Create render Target
	/*g_pRenderTarget = API->CreateTexture2D(800,
		                                   600,
		                                   1,
		                                   TF_R8G8B8A8_UNORM,
		                                   TEXTURE_BIND_RENDER_TARGET);*/

	//g_vRenderTargets.push_back(g_pRenderTarget);

	//// Create the depth stencil 
	/*g_pDepthStencil = API->CreateTexture2D(800,
		                                   600,
		                                   1,
		                                   TF_D24_UNORM_S8_UINT,
		                                   TEXTURE_BIND_DEPTH_STENCIL,
		                                   TYPE_USAGE_DEFAULT);*/

	////create shader resource
	/*g_pShaderResource = API->CreateTexture2D(800,
		                                     600,
		                                     1,
		                                     TF_R8G8B8A8_UNORM,
		                                     TEXTURE_BIND_SHADER_RESOURCE);

	g_vShaderResources.push_back(g_pShaderResource);*/

	// Create the vertex shader
	g_pVertexShader = API->CreateVertexShaders("Tutorial07.fx",
			                                    "VS",
			                                    "vs_4_0",
			                                     1);

    /*g_pVertexShader = API->CreateVertexShaders("Tutorial07.fx",
			                                   "VS",
			                                   "vs_4_0", 
		                                        1);*/

	//Set semantic 
	g_InpLayDesc.Semantics.push_back("POSITION");
	g_InpLayDesc.Semantics.push_back("TEXCOORD");

	g_InpLayDesc.Formats.push_back(TF_R32G32B32_FLOAT);
	g_InpLayDesc.Formats.push_back(TF_R32G32_FLOAT);

	// Create the input layout
	g_pInputLayout = API->CreateInputLayout(*g_pVertexShader,
		                                    g_InpLayDesc,1);

	// Create the pixel shader
	g_pPixelShader = API->CreatePixelShaders("Tutorial07.fx",
		                                     "PS",
		                                     "ps_4_0",
		                                     1);
	/*g_pPixelShader = API->CreatePixelShaders("Tutorial07.fx",
		                                     "PS",
		                                     "ps_4_0", 
		                                      1);*/

	// Create vertex buffer

	g_pVertexBuffer = API->CreateVertexBuffer(vertices,
		                                      vertices.size(),1);

	// Create index buffer
	g_pIndexBuffer = API->CreateIndexBuffer(indices,
		                                    indices.size(),1);

	// Create the constant buffers

	g_pCBNeverChanges = API->CreateConstantBuffer(sizeof(CBNeverChanges),1, &g_ConstantBuffer);

	g_vConstantBuffers.push_back(g_pCBNeverChanges);

	//// Create the sample state

	//g_pSamplerState = API->CreateSamplerState();

	//g_vSamplers.push_back(g_pSamplerState);

	////Init World Matrix
	g_World = glm::mat4(1.0);

	////init view matrix
	g_View = glm::lookAtLH(Eye, 
		                   At,
		                   Up);

	

	////init projection matrix
	g_Projection = glm::perspectiveFovLH(Data.Fov,
		                                 Data.H,
		                                 Data.W,
		                                 Data.Near,
		                                 Data.Far);
	
	
}

void Update()
{
	//g_ConstantBuffer.mView = glm::transpose(g_View);
	g_ConstantBuffer.mView = glm::transpose(g_View);
	g_ConstantBuffer.mProjection = glm::transpose(g_Projection);
	g_ConstantBuffer.mWorld = glm::transpose(g_World);
	g_ConstantBuffer.vMeshColor = g_MeshColor;

	API->UpdateSubresource(&g_ConstantBuffer,
		                   *g_pCBNeverChanges);


}

void Render()
{

	Color.R = 0.0f;
	Color.G = 0.125f;
	Color.B = 0.3f;
	Color.A = 1.0f;


	/*API->SetRenderTarget(g_vRenderTargets,
		                 g_pDepthStencil);*/

	API->SetDefaultRenderTarget();



	// Setup the viewport
	API->SetViewport(1,
		             800,
		             600,0,0);

	//set inputlayout
	API->SetInputLayout(g_pInputLayout);

	//set vertex buffer
	API->SetVertexBuffer(g_pVertexBuffer,
		                 0,
		                 1,
		                 sizeof(SimpleVertex),
		                 0);

	//set index buffer
	API->SetIndexBuffer(g_pIndexBuffer, 
		                0);

	// Set primitive topology
	API->SetPrimitiveTopology(PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	//// Clear the render target
	/*API->ClearRenderTarget(g_pRenderTarget,
		                   Color);*/

	//// Clear the depth stencil
	/*API->ClearDepthStencil(g_pDepthStencil, CLEAR_DEPTH,1.0f,0);*/

	API->ClearDefaultRenderTargetAndDepthStencil(Color);

	

	//set vertex shader
	API->SetVertexShaders(g_pVertexShader);

	//set all vertex shader constant buffer

	API->SetVertexShaderConstantBuffer(g_pCBNeverChanges,
		                               0,
		                               1);

	

	//set pixel shader
	API->SetPixelShaders(g_pPixelShader);

	//set pixel shader constant buffer

	API->SetPixelShaderConstantBuffer(g_pCBNeverChanges,
		                              0,
		                              1);

	/*API->SetShaderResource(g_vShaderResources,
		                   0);*/

	/*API->SetSamplerState(g_vSamplers,
		                 0);*/

	API->DrawIndexed(36,
		             0,
		             0,
		             &indices);
	API->Present();
}

void Destroy()
{
	//sampler state
	for (int i = g_vSamplers.size() - 1; i >= 0; i--)
	{
		if (nullptr != g_vSamplers.at(i))
		{
			delete g_vSamplers.at(i);
		}
	}

	//ShaderResource
	for (int i = g_vShaderResources.size() - 1; i >= 0; i--)
	{
		if (nullptr != g_vShaderResources.at(i))
		{
			delete g_vShaderResources.at(i);
		}
	}

	//constant Buffers
	for (int i = g_vConstantBuffers.size() - 1; i >= 0; i--)
	{
		if (nullptr != g_vConstantBuffers.at(i))
		{
			delete g_vConstantBuffers.at(i);
		}
	}

	//vertex buffer
	delete g_pVertexBuffer;

	//index buffer
	delete g_pIndexBuffer;

	//input layout
	delete g_pInputLayout;

	//vertex shader
	delete g_pVertexShader;

	//pixel shader
	delete g_pPixelShader;

	//depthstencil
	delete g_pDepthStencil;

	//render targets
	for (int i = g_vRenderTargets.size() - 1; i >= 0; i--)
	{
		if (nullptr != g_vRenderTargets.at(i))
		{
			delete g_vRenderTargets.at(i);
		}
	}
}

int main()
{
	Init();

	// Main message loop
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//update
			Update();

			//render
			Render();
			
		}
	}

	Destroy();
	API->Destroy();

	g_vRenderTargets.clear();
	g_vShaderResources.clear();
	g_vSamplers.clear();
	g_vConstantBuffers.clear();
	g_vSemanticNames.clear();
		
	
	return 0;
}

