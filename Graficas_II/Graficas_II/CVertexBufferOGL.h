/**
 * @class CVertexBufferOGL
 *
 * @brief class for vertex buffers of opengl
 *
 * This class is to use unsigned int of vertex buffer that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CVertexBuffer.h"
class CVertexBufferOGL : public CVertexBuffer
{
	/// Default Constructor
	CVertexBufferOGL() = default;

	/// Destructor
	~CVertexBufferOGL() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_VBO, is for a vertex buffer
	*/
	unsigned int m_VBO;

	friend class COGLGraphiAPI;

};

