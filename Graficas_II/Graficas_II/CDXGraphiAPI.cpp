#include "CDXGraphiAPI.h"
//#include "CTextureDX.h"
#include "CInputLayoutDX.h"
#include "CIndexBufferDX.h"
#include "CVertexBufferDX.h"
#include "CConstantBufferDX.h"
#include "CVertexShaderDX.h"
#include "CPixelShaderDX.h"
#include "CSamplerStateDX.h"
#include "CRasterizerStateDX.h"
#include <vector>
#include "resource.h"


using std::vector;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

CDXGraphiAPI::CDXGraphiAPI()
{
    m_pd3dDevice = nullptr;
    m_pImmediateContext = nullptr;
    m_pSwapChain = nullptr;
    m_hWnd = nullptr;
}

CDXGraphiAPI::~CDXGraphiAPI()
{
}

//fuction to create a window
void CDXGraphiAPI::InitWindow(unsigned int width, 
                              unsigned int height,
                              HINSTANCE hInstance,
                              int nCmdShow)
{
    
}

//fuction to create device and swap chain
void CDXGraphiAPI::CreateDeviceandSwap()
{
    RECT rc;
    GetClientRect(m_hWnd, &rc);
    m_Width = rc.right - rc.left;
    m_Height = rc.bottom - rc.top;

    D3D_DRIVER_TYPE driverType = D3D_DRIVER_TYPE_NULL;
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

    UINT createDeviceFlags = 0;
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    vector<D3D_DRIVER_TYPE> driverTypes =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };

    vector<D3D_FEATURE_LEVEL> featureLevels =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };

    DXGI_SWAP_CHAIN_DESC sd;
    memset(&sd, 0, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = m_Width;
    sd.BufferDesc.Height = m_Height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = m_hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;

    HRESULT hr = S_OK;
    
    for (auto& dType : driverTypes)
    {
        hr = D3D11CreateDeviceAndSwapChain(nullptr,
                                           dType,
                                           nullptr,
                                           createDeviceFlags,
                                           featureLevels.data(),
                                           featureLevels.size(),
                                           D3D11_SDK_VERSION,
                                           &sd,
                                           &m_pSwapChain,
                                           &m_pd3dDevice,
                                           &featureLevel,
                                           &m_pImmediateContext);
        if (SUCCEEDED(hr))
        {
            break;
        }
    }
    if (FAILED(hr))
    {
        std::cout << "//error fallo la creacion del device y swapchain" << std::endl;
    }
}

void CDXGraphiAPI::CreateDeferredContext()
{
    m_pd3dDevice->CreateDeferredContext(0, &m_pImmediateContext);
}


//fuction to create a vertex buffer 
CVertexBuffer* CDXGraphiAPI::CreateVertexBuffer(vector <SimpleVertex> Ver,
                                                unsigned int BufferSize,
                                                unsigned int NumBuffer)
{
    auto VertexBuffer = new CVertexBufferDX();
    CD3D11_BUFFER_DESC BufferDesc(sizeof(SimpleVertex)* BufferSize,
                                  D3D11_BIND_VERTEX_BUFFER);

    D3D11_SUBRESOURCE_DATA InitData;
    ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = Ver.data();

    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc, 
                                            &InitData, 
                                            &VertexBuffer->m_pVertexBuffer);
    if (FAILED(hr))
    {
        std::cout << "//error fallo la creacion del vertex buffer" << std::endl;
        return nullptr;
    }
    return VertexBuffer;
        
}

//fuction to create an index buffer 
CIndexBuffer* CDXGraphiAPI::CreateIndexBuffer(const std::vector<unsigned int>& Ind,
                                              unsigned int BufferSize,
                                              unsigned int NumBuffer)
{
    auto IndexBuffer = new CIndexBufferDX();
    CD3D11_BUFFER_DESC BufferDesc(sizeof(unsigned int)* BufferSize,
                                  D3D11_BIND_VERTEX_BUFFER);

    D3D11_SUBRESOURCE_DATA InitData;
    ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = Ind.data();

    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                            &InitData,
                                            &IndexBuffer->m_pIndexBuffer);
    if (FAILED(hr))
    {
        std::cout << "//error fallo la creacion del Index buffer" << std::endl;
        return nullptr;
    }
    return IndexBuffer;
}

//fuction to create a constant buffer never change
CConstantBuffer* CDXGraphiAPI::CreateConstantBuffer(unsigned int BufferSize,
                                                    unsigned int NumBuffer)
{
    auto ConsBuffer = new CConstantBufferDX();
    CD3D11_BUFFER_DESC BufferDesc(BufferSize,
                                  D3D11_BIND_CONSTANT_BUFFER);
    //never change
    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                            nullptr,
                                            &ConsBuffer->m_pConstantBuffer);
    if (FAILED(hr))
    {
        std::cout << "//error fallo la creacion del Constant buffer Never" <<std::endl;
        return nullptr;
    }
    return ConsBuffer;
}

void CDXGraphiAPI::CreateTexture1D()
{
}

//fuction to create a texture 2D
CTexture* CDXGraphiAPI::CreateTexture2D(unsigned int width,
	                                    unsigned int height,
                                        unsigned int numberTexture,
	                                    TEXTURE_FORMAT format,
	                                    unsigned int bindFlags,
                                        TYPE_USAGE Usage)
{
    auto texture = new CTextureDX();


    CD3D11_TEXTURE2D_DESC desc(static_cast<DXGI_FORMAT>(format),
                               width,
                               height,
                               1,
                               0,
                               bindFlags,
                               static_cast<D3D11_USAGE>(Usage));

    //Crear textura
    HRESULT hr = m_pd3dDevice->CreateTexture2D(&desc, nullptr, &texture->m_Texture);
    if(FAILED(hr))
    {
        std::cout << "//error fallo la creacion de la textura" << std::endl;
        return nullptr;
    }

    //Checar que interfaces se van a crear
    if(bindFlags & D3D11_BIND_SHADER_RESOURCE)
    {//Crear SRV
      CD3D11_SHADER_RESOURCE_VIEW_DESC srvDesc(D3D11_SRV_DIMENSION_TEXTURE2D);
      m_pd3dDevice->CreateShaderResourceView(texture->m_Texture,
                                             &srvDesc,
                                             &texture->m_SRV);
    }
    else if(bindFlags & D3D11_BIND_DEPTH_STENCIL)
    {//Crear DSV
        CD3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc(D3D11_DSV_DIMENSION_TEXTURE2D);
        m_pd3dDevice->CreateDepthStencilView(texture->m_Texture,
                                             &dsvDesc,
                                             &texture->m_DSV);
     
    }
    else if (bindFlags & D3D11_BIND_RENDER_TARGET)
    {//Crear RTV
        m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&m_BackBuffer.m_Texture);

        CD3D11_RENDER_TARGET_VIEW_DESC rtvDesc(D3D11_RTV_DIMENSION_TEXTURE2D);

        m_pd3dDevice->CreateRenderTargetView(m_BackBuffer.m_Texture,
                                             &rtvDesc,
                                             &texture->m_RTV);
        
    }
    else if (bindFlags & D3D11_BIND_RENDER_TARGET)
    {//Crear UAV
        CD3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc(D3D11_UAV_DIMENSION_TEXTURE2D);
        m_pd3dDevice->CreateUnorderedAccessView(texture->m_Texture,
                                                &uavDesc,
                                                &texture->m_UAV);

    }
    return texture;
    
}

void CDXGraphiAPI::CreateTexture3D()
{
} //falta

//fuction to create a pixel shader
CPixelShader* CDXGraphiAPI::CreatePixelShaders(std::string FileName,
                                               std::string Entry,
                                               std::string ShaderModel,
                                               int NumPixelShader)
{
    auto PixelShader = new CPixelShaderDX();
    LPWSTR File = new wchar_t[FileName.size()];
    if (PixelShader->CompilePixelShaderFromFile(File,
                                                Entry.c_str(),
                                                ShaderModel.c_str(),
                                                &PixelShader->m_pPSBlob));
    {
        std::cout << " //error fallo la compilacion del shader" << std::endl;
        return nullptr;
    }

    HRESULT hr = m_pd3dDevice->CreatePixelShader(PixelShader->m_pPSBlob->GetBufferPointer(),
                                                 PixelShader->m_pPSBlob->GetBufferSize(),
                                                 nullptr, 
                                                 &PixelShader->m_PixelShader);

    if (FAILED(hr))
    {
        PixelShader->m_pPSBlob->Release();
        std::cout << "//error fallo la creacion del Pixel shader" << std::endl;
        return nullptr;
    }

    return PixelShader;
}
//fuction to create a vertex shader
CVertexShader* CDXGraphiAPI::CreateVertexShaders(std::string FileName,
                                                 std::string Entry,
                                                 std::string ShaderModel,
                                                 int NumVextexShader)
{
    auto VertexShaders = new CVertexShaderDX();
    LPWSTR File = new wchar_t[FileName.size()];
    if (VertexShaders->CompileVertexShaderFromFile(File,
                                                   Entry.c_str(),
                                                   ShaderModel.c_str(), 
                                                   &VertexShaders->m_pVSBlob));
    {
        std::cout << "//error fallo la compilacion del shader" << std::endl;
    }

    HRESULT hr = m_pd3dDevice->CreateVertexShader(VertexShaders->m_pVSBlob->GetBufferPointer(),
                                                  VertexShaders->m_pVSBlob->GetBufferSize(),
                                                  nullptr, 
                                                  &VertexShaders->m_VertexShader);
    if (FAILED(hr))
    {
        VertexShaders->m_pVSBlob->Release();
        std::cout << "//error fallo la creacion del vertex shader" << std::endl;
        ///error
        return nullptr;
    }
    return VertexShaders;
}

//fuction to create an input layout,
CInputLayout* CDXGraphiAPI::CreateInputLayout(CVertexShader* Vertex,
                                              std::vector<std::string> SemanticName,
                                              unsigned int NumInputLayout)
{
    auto InputLayout = new CInputLayoutDX();
    auto VertexShaderBlob = reinterpret_cast<CVertexShaderDX*>(Vertex);
    

    vector<D3D11_INPUT_ELEMENT_DESC> layout;

    unsigned int SemanticIndexPosition = 0;
    unsigned int SemanticIndexTexcoord = 0;
    unsigned int SemanticIndexColor = 0;
    unsigned int SemanticIndexNormal = 0;
    

    for (int i = 0; i < SemanticName.size(); i++)
    {
        if ("POSITION" == SemanticName.at(i))
        {
            layout.push_back({ "POSITION", 
                               SemanticIndexPosition,
                               DXGI_FORMAT_R32G32B32_FLOAT, 
                               0, 
                               D3D11_APPEND_ALIGNED_ELEMENT, 
                               D3D11_INPUT_PER_VERTEX_DATA, 
                               0 });
            SemanticIndexPosition++;
        }
        else if ("TEXCOORD" == SemanticName.at(i))
        {
            layout.push_back({ "TEXCOORD",
                               SemanticIndexTexcoord,
                               DXGI_FORMAT_R32G32_FLOAT,
                               0,
                               D3D11_APPEND_ALIGNED_ELEMENT,
                               D3D11_INPUT_PER_VERTEX_DATA,
                               0 });
            SemanticIndexTexcoord++;
        }
        else if ("COLOR" == SemanticName.at(i))
        {
            layout.push_back({ "COLOR",
                               SemanticIndexColor,
                               DXGI_FORMAT_R32G32B32_FLOAT,
                               0,
                               D3D11_APPEND_ALIGNED_ELEMENT,
                               D3D11_INPUT_PER_VERTEX_DATA,
                               0 });
            SemanticIndexColor++;
        }
        else if ("NORMAL" == SemanticName.at(i))
        {
            layout.push_back({ "NORMAL",
                               SemanticIndexNormal,
                               DXGI_FORMAT_R32G32B32_FLOAT,
                               0,
                               D3D11_APPEND_ALIGNED_ELEMENT,
                               D3D11_INPUT_PER_VERTEX_DATA,
                               0 });
            SemanticIndexNormal++;
        }
    }
   
    HRESULT  hr = m_pd3dDevice->CreateInputLayout(layout.data(), 
                                                  layout.size(),
                                                  VertexShaderBlob->m_pVSBlob->GetBufferPointer(),
                                                  VertexShaderBlob->m_pVSBlob->GetBufferSize(),
                                                  &InputLayout->m_pInputLayout);
    VertexShaderBlob->m_pVSBlob->Release();

    if (FAILED(hr))
    {
        std::cout << "//error fallo la creacion del Input layout" << std::endl;
        return nullptr;
    }

    return InputLayout;


}

//fuction to create a sampler state
CSamplerState* CDXGraphiAPI::CreateSamplerState(unsigned int NumSamplerState)
{
    auto SamplerState = new CSamplerStateDX();
    CD3D11_SAMPLER_DESC SamStDesc;

    m_pd3dDevice->CreateSamplerState(&SamStDesc,
                                     &SamplerState->m_pSamplerLinear);
   
    return SamplerState;
}

//fuction to create a rasterizer state
CRasterizerState* CDXGraphiAPI::CreateRasterizerState()
{
    auto RasState = new CRasterizerStateDX();

    CD3D11_RASTERIZER_DESC RasDesc;

    m_pd3dDevice->CreateRasterizerState(&RasDesc,
                                        &RasState->m_pRasterizerState);
    return RasState;
}

//fuction to set a constant buffer never change
void CDXGraphiAPI::SetConstantBuffer(CConstantBuffer* ConstBuff,
                                       unsigned int StartSlot, 
                                       unsigned int NumBuffer)
{
    auto Buffer = reinterpret_cast<CConstantBufferDX*>(ConstBuff);
    m_pImmediateContext->VSSetConstantBuffers(StartSlot, 
                                              NumBuffer, 
                                              &Buffer->m_pConstantBuffer);
}

//fuction to set an index buffer 
void CDXGraphiAPI::SetIndexBuffer(CIndexBuffer* IndBuff,
                                  unsigned int offset)
{
    auto IndexBuff = reinterpret_cast<CIndexBufferDX*>(IndBuff);

    m_pImmediateContext->IASetIndexBuffer(IndexBuff->m_pIndexBuffer,
                                          DXGI_FORMAT_R16_UINT, 
                                          offset);
}

//fuction to set a vertex buffer 
void CDXGraphiAPI::SetVertexBuffer(CVertexBuffer* VerBuff,
                                   unsigned int StartSlot,
                                   unsigned int NumBuffer,
                                   unsigned int stride,
                                   unsigned int offset)
{

    auto VertexBuff = reinterpret_cast<CVertexBufferDX*>(VerBuff);
    m_pImmediateContext->IASetVertexBuffers(StartSlot,
        NumBuffer,
        &VertexBuff->m_pVertexBuffer,
        &stride,
        &offset);
}

//fuction to set a pixel shader 
void CDXGraphiAPI::SetPixelShaders(CPixelShader* Pixel)
{
    auto PixelSh = reinterpret_cast<CPixelShaderDX*>(Pixel);

    m_pImmediateContext->PSSetShader(PixelSh->m_PixelShader, 
                                     nullptr, 
                                     0);
}

//fuction to set a vertex shader 
void CDXGraphiAPI::SetVertexShaders(CVertexShader* Vertex)
{
    auto VertexSh = reinterpret_cast<CVertexShaderDX*>(Vertex);
    m_pImmediateContext->VSSetShader(VertexSh->m_VertexShader,
                                     nullptr, 
                                     0);
}

//fuction to set a render target 
void CDXGraphiAPI::SetRenderTarget(const std::vector<CTexture*>& pRTTex,
                                   CTexture* pDSTex)
{
    for (int i = 0; i < pRTTex.size(); i++)
    {
        auto pRTDX = reinterpret_cast<CTextureDX*>(pRTTex.at(i));

        ID3D11DepthStencilView* pDSV = nullptr;

        if (nullptr != pDSTex)
        {
            auto pDSDX = reinterpret_cast<CTextureDX*>(pDSTex);
            pDSV = pDSDX->m_DSV;
        }

        m_pImmediateContext->OMSetRenderTargets(pRTTex.size(),
                                                &pRTDX->m_RTV,
                                                pDSV);
    }
}


//fuction to set a input layout 
void CDXGraphiAPI::SetInputLayout(CInputLayout* Inp)
{
    auto InpLay = reinterpret_cast<CInputLayoutDX*>(Inp);
    m_pImmediateContext->IASetInputLayout(InpLay->m_pInputLayout);
}

//fuction to set a sampler state 
void CDXGraphiAPI::SetSamplerState(const std::vector<CSamplerState*>& Sam,
                                   unsigned int StartSlot)
{
    for (int i = 0; i < Sam.size(); i++)
    {
        auto Sampler = reinterpret_cast<CSamplerStateDX*>(Sam.at(i));
        m_pImmediateContext->PSSetSamplers(StartSlot,
                                           Sam.size(),
                                           &Sampler->m_pSamplerLinear);
    }
    
}

void CDXGraphiAPI::SetDepthStencil()
{
}

//fuction to set a shader resource
void CDXGraphiAPI::SetShaderResource(const std::vector<CTexture*>& pRTTex,
                                     unsigned int StartSlot)
{
    for (int i = 0; i < pRTTex.size(); i++)
    {
        auto pRTDX = reinterpret_cast<CTextureDX*>(pRTTex.at(i));
        m_pImmediateContext->PSSetShaderResources(StartSlot,
                                                  pRTTex.size(), 
                                                  &pRTDX->m_SRV);
    }
}

//fuction to set a viewport 
void CDXGraphiAPI::SetViewport(unsigned int NumViewport,
                               float Width,
                               float Height,
                               float TopLeftX,
                               float TopLeftY)
{
    CD3D11_VIEWPORT Vp(TopLeftX,
                       TopLeftY,
                       Width,
                       Height);

    m_pImmediateContext->RSSetViewports(NumViewport, &Vp);
}

//fuction to set a rasyerizer state
void CDXGraphiAPI::SetRasterizerState(CRasterizerState * RasState)
{
    auto pRasteState = reinterpret_cast<CRasterizerStateDX*>(RasState);
    m_pImmediateContext->RSSetState(pRasteState->m_pRasterizerState);
}

//fuction to clear render target view
void CDXGraphiAPI::ClearRenderTarget(CTexture* RT,
                                     ColorStruct Color)
{
    auto pRTDX = reinterpret_cast<CTextureDX*>(RT);

    std::vector<float> ClearColor;
    ClearColor.push_back(Color.R);
    ClearColor.push_back(Color.G);
    ClearColor.push_back(Color.B);
    ClearColor.push_back(Color.A);

    m_pImmediateContext->ClearRenderTargetView(pRTDX->m_RTV, ClearColor.data());
}

//fuction to clear depth stenci view
void CDXGraphiAPI::ClearDepthStencil(CTexture* DS,
                                     CLEAR_FLAG ClerFlag, 
                                     float Depth, 
                                     unsigned int Stencil)
{
    auto pDSDX = reinterpret_cast<CTextureDX*>(DS);

     

    m_pImmediateContext->ClearDepthStencilView(pDSDX->m_DSV,
                                               static_cast<D3D11_CLEAR_FLAG>(ClerFlag),
                                               Depth,
                                               Stencil);
}

//fuction to draw
void CDXGraphiAPI::DrawIndexed(unsigned int NumIndex,
                               unsigned int StartindexLocation,
                               unsigned int BaseVertexLocation)
{
    m_pImmediateContext->DrawIndexed(NumIndex, 
                                     StartindexLocation,
                                     BaseVertexLocation);
}

void CDXGraphiAPI::DrawInstanced(unsigned int VertexCountPerInstance, 
                                 unsigned int InstanceCount, 
                                 unsigned int StartVertexLocation, 
                                 unsigned int StartInstanceLocation)
{
    m_pImmediateContext->DrawInstanced(VertexCountPerInstance,
                                       InstanceCount,
                                       StartVertexLocation,
                                       StartInstanceLocation);
}

void CDXGraphiAPI::Draw(unsigned int VertexCount, 
                        unsigned int StartVertexLocation)
{
    m_pImmediateContext->Draw(VertexCount,
                              StartVertexLocation);
}

//fuction to present the swap chain
void CDXGraphiAPI::Present()
{
    m_pSwapChain->Present(0, 0);
}
