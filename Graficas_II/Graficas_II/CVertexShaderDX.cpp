#include "CVertexShaderDX.h"

CVertexShaderDX::~CVertexShaderDX()
{
    if (m_VertexShader)
    {
        m_VertexShader->Release();
    }
    if (m_pVSBlob)
    {
        m_pVSBlob->Release();
    }
}

bool CVertexShaderDX::CompileVertexShaderFromFile(const std::wstring& FileName,
                                                  const std::string& EntryPoint,
                                                  const std::string& ShaderModel,
                                                  ID3DBlob** ppBlobOut)
{
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;


    ID3DBlob* pErrorBlob;
    hr = D3DCompileFromFile(FileName.c_str(), 
                            nullptr, 
                            nullptr, 
                            EntryPoint.c_str(), 
                            ShaderModel.c_str(),
                            dwShaderFlags, 
                            0, 
                            ppBlobOut, 
                            &pErrorBlob);

    if (FAILED(hr))
    {
        if (pErrorBlob != nullptr)
        {
            std::cout << "Error al compilar el vertex shader" << std::endl;
           // OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
        }
           
        if (pErrorBlob)
        {
            pErrorBlob->Release();
            return false;
        }
    }

    if (pErrorBlob)
    {
        pErrorBlob->Release();
    }

    return true;
    
}
