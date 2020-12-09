#include "CGraphiAPI.h"
#include "COGLGraphiAPI.h"
#include "CDXGraphiAPI.h"
#include "CModel.h"
#include <windows.h>

CGraphiAPI* API = new CDXGraphiAPI();
//CGraphiAPI* API = new COGLGraphiAPI();

const unsigned int g_Width = 800;
const unsigned int g_Height = 600;
const unsigned int g_NumberOfPixelShader = 1;
const unsigned int g_NumberOfVertexShader = 1;
const unsigned int g_NumberOfInputLayout = 1;
const unsigned int g_NumberOfViewport = 1;
const unsigned int g_NumberOfBuffers = 1;
const unsigned int g_StartSlot = 0;
const float g_Far = 100.0f;
const float g_Near = 1.0f;
const float g_FieldOfView = 0.7f;
const float g_ColorR = 0.0f;
const float g_ColorG = 0.125f;
const float g_ColorB = 0.3f;
const float g_ColorA = 1.0f;

const glm::vec3 g_vEye = { 0.0f, 3.0f, -6.0f };
const glm::vec3 g_vAt = { 0.0f, 1.0f, 0.0f };
const glm::vec3 g_vUp = { 0.0f, 1.0f, 0.0f };

//Textures
CTexture* g_pRenderTarget = nullptr;
CTexture* g_pDepthStencil = nullptr;
CTexture* g_pShaderResource = nullptr;

std::vector<CTexture*> g_vRenderTargets;
std::vector<CTexture*> g_vShaderResources;
std::vector<CSamplerState*> g_vSamplers;
std::vector<CConstantBuffer*> g_vConstantBuffers;

//Shader
CVertexShader* g_pVertexShader = nullptr;
CPixelShader* g_pPixelShader = nullptr;
CShaderProgram* g_pShaderProgram = nullptr;
CInputLayout* g_pInputLayout = nullptr;

//Buffers
//CVertexBuffer* g_pVertexBuffer = nullptr;
//CIndexBuffer* g_pIndexBuffer = nullptr;
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
std::vector<std::string> g_vSemanticNames;
std::vector<unsigned int> g_vFormats;


CModel* g_Model;


struct CBNeverChanges
{
	glm::mat4x4 mView;
	glm::mat4x4 mProjection;
	glm::mat4x4 mWorld;
	glm::vec4 vMeshColor;
};

CBNeverChanges g_ConstantBuffer;

void Init()
{
	CCameraDatas Data;
	Data.Far = g_Far;
	Data.Fov = g_FieldOfView;
	Data.H = g_Height;
	Data.W = g_Width;
	Data.Near = g_Near;

	g_MeshColor.x = 1;
	g_MeshColor.y = 1;
	g_MeshColor.z = 1;


	API->Init(g_Width,
		      g_Height);

	//load model
	g_Model = new CModel();
	g_Model->Init("Modelo/Scene.fbx",
		           API);

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


	g_pShaderProgram = API->CreateShaderProgram("VS", 
		                                        "PS", 
		                                        "VS", 
		                                        "PS", 
		                                        "vs_4_0", 
		                                        "ps_4_0", 
		                                        g_NumberOfVertexShader,
		                                        g_NumberOfPixelShader);
	// Create the vertex shader
	/*g_pVertexShader = API->CreateVertexShaders("VS",
			                                   "VS",
			                                   "vs_4_0",
			                                    1);*/

    /*g_pVertexShader = API->CreateVertexShaders("Tutorial07.fx",
			                                   "VS",
			                                   "vs_4_0", 
		                                        1);*/


	//Set semantic 
	g_vSemanticNames.push_back("POSITION");
	g_vSemanticNames.push_back("TEXCOORD");

	//formats
	g_vFormats.push_back(TF_R32G32B32_FLOAT);
	g_vFormats.push_back(TF_R32G32_FLOAT);

	//Create input layout desc
	g_InpLayDesc = API->CreateInputLayoutDesc(g_vSemanticNames,
		                                      g_vFormats);
	// Create the input layout
	g_pInputLayout = API->CreateInputLayout(*g_pShaderProgram,
		                                    g_InpLayDesc,
		                                    g_NumberOfInputLayout);

	// Create the pixel shader
	/*g_pPixelShader = API->CreatePixelShaders("PS",
		                                     "PS",
		                                     "ps_4_0",
		                                     1);*/
	/*g_pPixelShader = API->CreatePixelShaders("Tutorial07.fx",
		                                     "PS",
		                                     "ps_4_0", 
		                                      1);*/

	// Create vertex buffer

	/*g_pVertexBuffer = API->CreateVertexBuffer(vertices,
		                                      vertices.size(),1);*/

	// Create index buffer
	/*g_pIndexBuffer = API->CreateIndexBuffer(indices,
		                                    indices.size(),
		                                    1);*/

	// Create the matrixs

	g_ConstantBuffer.mView = API->CreateMatrixView(g_vEye,
		                                           g_vAt,
		                                           g_vUp);

	g_ConstantBuffer.mProjection = API->CreateMatrixProjection(Data.Fov,
		                                                       Data.H,
		                                                       Data.W,
		                                                       Data.Near,
		                                                       Data.Far);

	g_ConstantBuffer.mWorld = API->CreateMatrixWorld();
	
	g_ConstantBuffer.vMeshColor = g_MeshColor;

	g_pCBNeverChanges = API->CreateConstantBuffer(sizeof(CBNeverChanges),
		                                          g_NumberOfBuffers,
		                                          &g_ConstantBuffer);

	g_vConstantBuffers.push_back(g_pCBNeverChanges);

	//// Create the sample state

	//g_pSamplerState = API->CreateSamplerState();

	//g_vSamplers.push_back(g_pSamplerState);

}

void Update()
{
	API->UpdateSubresource(&g_ConstantBuffer,
		                   *g_pCBNeverChanges);
}

void Render()
{

	Color.R = g_ColorR;
	Color.G = g_ColorG;
	Color.B = g_ColorB;
	Color.A = g_ColorA;

	/*API->SetRenderTarget(g_vRenderTargets,
		                 g_pDepthStencil);*/

	API->SetDefaultRenderTarget();

	// Setup the viewport
	API->SetViewport(g_NumberOfViewport,
		             g_Width,
		             g_Height);

	//set inputlayout
	API->SetInputLayout(g_pInputLayout);

	//set vertex buffer
	//API->SetVertexBuffer(g_pVertexBuffer,
	//	                 0,
	//	                 1,
	//	                 sizeof(SimpleVertex),
	//	                 0);

	////set index buffer
	//API->SetIndexBuffer(g_pIndexBuffer, 
	//	                0);

	// Set primitive topology
	API->SetPrimitiveTopology(PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	//// Clear the render target
	/*API->ClearRenderTarget(g_pRenderTarget,
		                   Color);*/

	//// Clear the depth stencil
	/*API->ClearDepthStencil(g_pDepthStencil, CLEAR_DEPTH,1.0f,0);*/

	API->ClearDefaultRenderTargetAndDepthStencil(Color);

	//shader program
	API->SetShaderProgram(g_pShaderProgram);

	//set vertex shader
	//API->SetVertexShaders(g_pVertexShader);

	//set all vertex shader constant buffer

	API->SetVertexShaderConstantBuffer(g_pCBNeverChanges,
		                               g_StartSlot,
		                               g_NumberOfBuffers);
	//set pixel shader
	//API->SetPixelShaders(g_pPixelShader);

	//set pixel shader constant buffer

	API->SetPixelShaderConstantBuffer(g_pCBNeverChanges,
		                              g_StartSlot,
		                              g_NumberOfBuffers);

	/*API->SetShaderResource(g_vShaderResources,
		                   0);*/

	/*API->SetSamplerState(g_vSamplers,
		                 0);*/
	g_Model->Draw(*g_pShaderProgram, API);
	/*API->DrawIndexed(36,
		             0,
		             0,
		             nullptr);*/
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
	//delete g_pVertexBuffer;

	//index buffer
	//delete g_pIndexBuffer;

	delete g_pShaderProgram;

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

