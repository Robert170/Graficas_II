/**
 * @class CShaderProgramOGL
 *
 * @brief class base for pixel and vertex shader of opengl
 *
 * This class is for compile and set pixel and vertex shader of opengl
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
#include "CPixelShaderOGL.h"
#include "CVertexShaderOGL.h"
class CShaderProgramOGL : public CShaderProgram
{
protected:

	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CShaderProgramOGL() = default;

	/// Destructor
	~CShaderProgramOGL();

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_AttachShaderID, shader id for atyachand link shaders
    */
	int m_AttachShaderID;

	/**
	  * @Variable m_PixelShaderProgram, pointer for the pixel shader of opengl
	*/
	CPixelShaderOGL* m_PixelShaderProgram = nullptr;

	/**
	  * @Variable m_PixelShaderProgram, pointer for the pixel shader of opengl
	*/
	CVertexShaderOGL* m_VertexShaderProgram = nullptr;




	friend class COGLGraphiAPI;
};

