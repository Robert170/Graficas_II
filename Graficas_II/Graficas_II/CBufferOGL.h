/**
 * @class CBufferOGL
 *
 * @brief class for all buffers of opengl
 *
 * This class is to use all unsigned int of buffer that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CBuffer.h"
class CBufferOGL :public CBuffer
{
protected:
	/// Default Constructor
	CBufferOGL() = default;

	/// Destructor
	~CBufferOGL() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_VBO, is for a vertex buffer
	*/
	unsigned int m_VBO;

	/**
	  * @Variable m_IBO, is for a index buffer
	*/
	unsigned int m_IBO;

	friend class COGLGraphiAPI;
};

