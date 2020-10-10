#include "CVertexShaderDX.h"

bool CVertexShaderDX::CompileVertexShaderFromFile(LPWSTR FileName,
                                                  LPCSTR EntryPoint, 
                                                  LPCSTR ShaderModel,
                                                  ID3DBlob** ppBlobOut)
{
    HRESULT hr = S_OK;

    DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;


    ID3DBlob* pErrorBlob;
    hr = D3DCompileFromFile(FileName, NULL, NULL, EntryPoint, ShaderModel,
        dwShaderFlags, 0, ppBlobOut, &pErrorBlob);
    if (FAILED(hr))
    {
        if (pErrorBlob != NULL)
        {
            OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
        }
           
        if (pErrorBlob)
        {
            pErrorBlob->Release();
            return false;
        }
    }
    if (pErrorBlob) pErrorBlob->Release();

    return true;
    
}
