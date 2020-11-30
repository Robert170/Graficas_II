/**
 * @class CPixelShaderDX
 *
 * @brief class for the pixel shader of directx
 *
 * This class is to use the pointers of pixel shader that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */

#pragma once
#include "CPixelShader.h"
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
class CPixelShaderDX : public CPixelShader
{
protected:

	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CPixelShaderDX() = default;

	/// Destructor
	~CPixelShaderDX();

	/**
	 * @brief      CompilePixelShaderFromFile function, to compile a shader from a file
	 * @param      FileName parameter one, name of the file with the shader
	 * @param      EntryPoint parameter two, entry point of the shader
	 * @param      ShaderModel parameter three, shader model of the shader
	 * @param      ppBlobOut parameter fourth, blob
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	bool CompilePixelShaderFromFile(const std::wstring& FileName,
		                            const std::string& EntryPoint,
		                            const std::string& ShaderModel,
		                            ID3DBlob * *ppBlobOut);
	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_PixelShader, pointer for the pixel shader
	*/
	ID3D11PixelShader* m_PixelShader = nullptr;

	/**
	  * @Variable m_pPSBlob, pointer for the blob of pixel shader
	*/
	ID3DBlob* m_pPSBlob = nullptr;


	friend class CDXGraphiAPI;
};

