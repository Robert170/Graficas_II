#include "CDXGraphiAPI.h"
#include "CTextureDX.h"
#include "CInputLayoutDX.h"
#include "CBufferDX.h"
#include <vector>


using std::vector;

CDXGraphiAPI::CDXGraphiAPI()
{
}

CDXGraphiAPI::~CDXGraphiAPI()
{
}

void CDXGraphiAPI::Init(unsigned int width, unsigned int height)
{
    InitWindow(width, height);
    CreateDeviceandSwap();
}

void CDXGraphiAPI::InitWindow(unsigned int width, unsigned int height)
{
    m_hWnd = nullptr;
}

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
        //Gritame en la cara que algo salio mal
    }
}

void CDXGraphiAPI::CreateDeferredContext()
{
}

CBuffer* CDXGraphiAPI::CreateVertexBuffer(SimpleVertex Ver[],
                                          unsigned int bindFlags)
{
    auto VertexBuffer = new CBufferDX();
    CD3D11_BUFFER_DESC BufferDesc(sizeof(SimpleVertex),
                                  bindFlags);

    D3D11_SUBRESOURCE_DATA InitData;
    ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = Ver;

    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc, 
                                            &InitData, 
                                            &VertexBuffer->m_pVertexBuffer);
    if (FAILED(hr))
    {
        //error
        return nullptr;
    }
    return VertexBuffer;
        
}

CBuffer* CDXGraphiAPI::CreateIndexBuffer(unsigned int Ind[],
                                     unsigned int bindFlags)
{
    auto IndexBuffer = new CBufferDX();
    CD3D11_BUFFER_DESC BufferDesc(sizeof(unsigned int),
                                  bindFlags);

    D3D11_SUBRESOURCE_DATA InitData;
    ZeroMemory(&InitData, sizeof(InitData));
    InitData.pSysMem = Ind;

    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                            &InitData,
                                            &IndexBuffer->m_pIndexBuffer);
    if (FAILED(hr))
    {
        //error
        return nullptr;
    }
    return IndexBuffer;
}

CBuffer* CDXGraphiAPI::CreateConstantBufferNC(CBNeverChanges CBNC, 
                                              unsigned int bindFlags)
{
    auto ConsBuffer = new CBufferDX();
    CD3D11_BUFFER_DESC BufferDesc(sizeof(CBNC),
                                  bindFlags);
    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                            nullptr,
                                            &ConsBuffer->m_pCBNeverChanges);
    if (FAILED(hr))
    {
        //error
        return nullptr;
    }
    return ConsBuffer;
}

CBuffer* CDXGraphiAPI::CreateConstantBufferCOR(CBChangeOnResize CBCR, unsigned int bindFlags)
{
    auto ConsBuffer = new CBufferDX();
    CD3D11_BUFFER_DESC BufferDesc(sizeof(CBCR),
                                  bindFlags);
    HRESULT hr  = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                             nullptr,
                                             &ConsBuffer->m_pCBChangeOnResize);
    if (FAILED(hr))
    {
        //error
        return nullptr;
    }

    return ConsBuffer;
}

CBuffer* CDXGraphiAPI::CreateConstantBufferCEF(CBChangesEveryFrame CBCEF, 
                                               unsigned int bindFlags)
{
    auto ConsBuffer = new CBufferDX();
    CD3D11_BUFFER_DESC BufferDesc(sizeof(CBCEF),
                                  bindFlags);
    //change every frame
    HRESULT hr = m_pd3dDevice->CreateBuffer(&BufferDesc,
                                            nullptr,
                                            &ConsBuffer->m_pCBChangesEveryFrame);
    if (FAILED(hr))
    {
        //error
        return nullptr;
    }

    return ConsBuffer;
}

void CDXGraphiAPI::CreateTexture1D()
{
}

CTexture* CDXGraphiAPI::CreateTexture2D(unsigned int width,
	                                    unsigned int height,
	                                    TEXTURE_FORMAT format,
	                                    unsigned int bindFlags,
                                        TYPE_USAGE Usage,
                                        unsigned int numberTexture)
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
        //Dime que no se pudo crear la textura!
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

CPixelShader* CDXGraphiAPI::CreatePixelShaders(std::string FileName,
                                      std::string Entry,
                                      std::string ShaderModel,
                                      int ID)
{
    auto PixelShader = new CPixelShaderDX();
    LPWSTR File = new wchar_t[FileName.size()];
    if (PixelShader->CompileVertexShaderFromFile(File,
                                                 Entry.c_str(),
                                                 ShaderModel.c_str(),
                                                 &m_VSBlob));
    {
        //error fallo la compilacion del shader
    }

    HRESULT hr = m_pd3dDevice->CreatePixelShader(m_VSBlob->GetBufferPointer(),
        m_VSBlob->GetBufferSize(),
        NULL, &PixelShader->m_PixelShader);
    if (FAILED(hr))
    {
        m_VSBlob->Release();
        ///error
        return nullptr;
    }

    return PixelShader;
}

CVertexShader* CDXGraphiAPI::CreateVertexShaders(std::string FileName,
                                       std::string Entry,
                                       std::string ShaderModel,
                                       int ID)
{
    auto VertexShaders = new CVertexShaderDX();
    LPWSTR File = new wchar_t[FileName.size()];
    if (VertexShaders->CompileVertexShaderFromFile(File,
                                                   Entry.c_str(),
                                                   ShaderModel.c_str(), 
                                                   &m_VSBlob));
    {
        //error fallo la compilacion del shader
    }

    HRESULT hr = m_pd3dDevice->CreateVertexShader(m_VSBlob->GetBufferPointer(), 
                                                  m_VSBlob->GetBufferSize(), 
                                                  NULL, &VertexShaders->m_VertexShader);
    if (FAILED(hr))
    {
        m_VSBlob->Release();
        ///error
        return nullptr;
    }
    return VertexShaders;
}

CInputLayout* CDXGraphiAPI::CreateInputLayout()
{
    auto InputLayout = new CInputLayoutDX();
   
   D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    HRESULT  hr = m_pd3dDevice->CreateInputLayout(layout, 
                                                  ARRAYSIZE(layout),
                                                  m_VSBlob->GetBufferPointer(),
                                                  m_VSBlob->GetBufferSize(), 
                                                  &InputLayout->m_pVertexLayout);
    m_VSBlob->Release();

    if (FAILED(hr))
    {
        return nullptr;
    }

    return InputLayout;


}

CSamplerState* CDXGraphiAPI::CreateSamplerState()
{
    auto SamplerState = new CSamplerStateDX();
    CD3D11_SAMPLER_DESC SamStDesc;

    m_pd3dDevice->CreateSamplerState(&SamStDesc,
                                     &SamplerState->m_pSamplerLinear);

    return SamplerState;
}

void CDXGraphiAPI::CreateRasterizerState()
{
}

void CDXGraphiAPI::SetConstantBufferNC(CBuffer* ConstBuff, 
                                       unsigned int StartSlot, 
                                       unsigned int NumBuffer)
{
    auto Buffer = reinterpret_cast<CBufferDX*>(ConstBuff);
    m_pImmediateContext->VSSetConstantBuffers(StartSlot, 
                                              NumBuffer, 
                                              &Buffer->m_pCBNeverChanges);
}

void CDXGraphiAPI::SetConstantBufferCOR(CBuffer* ConstBuff, 
                                        unsigned int StartSlot, 
                                        unsigned int NumBuffer)
{
    auto Buffer = reinterpret_cast<CBufferDX*>(ConstBuff);
    m_pImmediateContext->VSSetConstantBuffers(StartSlot, 
                                              NumBuffer, 
                                              &Buffer->m_pCBChangeOnResize);
}

void CDXGraphiAPI::SetConstantBufferCEF(CBuffer* ConstBuff, 
                                        unsigned int StartSlot, 
                                        unsigned int NumBuffer)
{
    auto Buffer = reinterpret_cast<CBufferDX*>(ConstBuff);
    m_pImmediateContext->VSSetConstantBuffers(StartSlot, 
                                              NumBuffer, 
                                              &Buffer->m_pCBChangesEveryFrame);

    m_pImmediateContext->PSSetConstantBuffers(StartSlot, 
                                              NumBuffer, 
                                              &Buffer->m_pCBChangesEveryFrame);
}

void CDXGraphiAPI::SetIndexBuffer(CBuffer* IndBuff,unsigned int offset)
{
    auto IndexBuff = reinterpret_cast<CBufferDX*>(IndBuff);
    m_pImmediateContext->IASetIndexBuffer(IndexBuff->m_pIndexBuffer,
                                          DXGI_FORMAT_R16_UINT, 
                                          offset);
}


void CDXGraphiAPI::SetVertexBuffer(CBuffer* VerBuff,
                                   unsigned int StartSlot,
                                   unsigned int NumBuffer,
                                   unsigned int stride,
                                   unsigned int offset)
{

    auto VertexBuff = reinterpret_cast<CBufferDX*>(VerBuff);
    m_pImmediateContext->IASetVertexBuffers(StartSlot,
        NumBuffer,
        &VertexBuff->m_pVertexBuffer,
        &stride,
        &offset);
}


void CDXGraphiAPI::SetPixelShaders(CPixelShader* Pixel)
{
    auto PixelSh = reinterpret_cast<CPixelShaderDX*>(Pixel);
    m_pImmediateContext->PSSetShader(PixelSh->m_PixelShader, 
                                     nullptr, 
                                     0);
}

void CDXGraphiAPI::SetVertexShaders(CVertexShader* Vertex)
{
    auto VertexSh = reinterpret_cast<CVertexShaderDX*>(Vertex);
    m_pImmediateContext->VSSetShader(VertexSh->m_VertexShader,
                                     nullptr, 
                                     0);
}


void CDXGraphiAPI::SetRenderTarget(CTexture* pRTTex, CTexture* pDSTex)
{
    auto pRTDX = reinterpret_cast<CTextureDX*>(pRTTex);
    ID3D11DepthStencilView* pDSV = nullptr;
    if(nullptr != pDSTex)
    {
      auto pDSDX = reinterpret_cast<CTextureDX*>(pDSTex);
      pDSV = pDSDX->m_DSV;
    }

    m_pImmediateContext->OMSetRenderTargets(1, &pRTDX->m_RTV, pDSV);
}



void CDXGraphiAPI::SetInputLayout(CInputLayout* Inp)
{
    auto InpLay = reinterpret_cast<CInputLayoutDX*>(Inp);
    m_pImmediateContext->IASetInputLayout(InpLay->m_pVertexLayout);
}

void CDXGraphiAPI::SetSamplerState(CSamplerState* Sam, 
                                   unsigned int StartSlot,
                                   unsigned int NumSamplers)
{
    auto Sampler = reinterpret_cast<CSamplerStateDX*>(Sam);
    m_pImmediateContext->PSSetSamplers(StartSlot,
                                       NumSamplers,
                                       &Sampler->m_pSamplerLinear);
}

void CDXGraphiAPI::SetDepthStencil()
{
}

void CDXGraphiAPI::SetShaderResouerce(CTexture* pRTTex)
{
    auto pRTDX = reinterpret_cast<CTextureDX*>(pRTTex);
    m_pImmediateContext->PSSetShaderResources(0, 1, &pRTDX->m_SRV);
}

void CDXGraphiAPI::SetRasterizerState()
{
}

void CDXGraphiAPI::Drawindex(int SizeIndex, int StartindexLocation)
{
    m_pImmediateContext->Draw(SizeIndex, StartindexLocation);
}

void CDXGraphiAPI::Present()
{
    //m_pSwapChain->Present()
}
