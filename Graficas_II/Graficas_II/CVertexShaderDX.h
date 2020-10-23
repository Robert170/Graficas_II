/**
 * @class CVertexShaderDX
 *
 * @brief class for the vertex shader of directx
 *
 * This class is to use the pointers of vertex shader that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */

#pragma once
#include "CVertexShader.h"
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>

class CVertexShaderDX :public CVertexShader
{
protected:

	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CVertexShaderDX() = default;

	/// Destructor
	~CVertexShaderDX() = default;


	/**
	 * @brief      CompileVertexShaderFromFile function, to compile a shader from a file
	 * @param      FileName parameter one, name of the file with the shader
	 * @param      EntryPoint parameter two, entry point of the shader
	 * @param      ShaderModel parameter three, shader model of the shader
	 * @param      ppBlobOut parameter fourth, blob
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	bool CompileVertexShaderFromFile(LPWSTR FileName,
		                             LPCSTR EntryPoint,
		                             LPCSTR ShaderModel,
		                             ID3DBlob** ppBlobOut);

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_VertexShader, pointer for the vertex shader
	*/
	ID3D11VertexShader* m_VertexShader = nullptr;


	friend class CDXGraphiAPI;
};

