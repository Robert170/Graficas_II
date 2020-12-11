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
#include "glad.h"
class CVertexBufferOGL : public CVertexBuffer
{
public:
	/**
	  * @brief public functions
	*/

	/// Destructor
	~CVertexBufferOGL();

protected:

	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CVertexBufferOGL() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_VBO, is for a vertex buffer
	*/
	unsigned int m_VBO = 0;

	/**
	  * @Variable m_NumberOfBuffers, number of vertex buffer to delete
	*/
	unsigned int m_NumberOfBuffers = 0;

	friend class COGLGraphiAPI;

};

