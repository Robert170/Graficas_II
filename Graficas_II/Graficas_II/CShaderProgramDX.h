/**
 * @class CShaderProgramDX
 *
 * @brief class base for pixel and vertex shader of directx
 *
 * This class is for compile and set pixel and vertex shader of directx
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 12/2/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CShaderProgram.h"
#include "CPixelShaderDX.h"
#include "CVertexShaderDX.h"
class CShaderProgramDX : public CShaderProgram
{
public:
	/// Destructor
	~CShaderProgramDX();
protected:

	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CShaderProgramDX() = default;

	

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_PixelShaderProgram, pointer for the pixel shader of directx
	*/
	CPixelShaderDX* m_PixelShaderProgram = nullptr;

	/**
	  * @Variable m_PixelShaderProgram, pointer for the pixel shader of directx
	*/
	CVertexShaderDX* m_VertexShaderProgram = nullptr;

	


	friend class CDXGraphiAPI;
};

