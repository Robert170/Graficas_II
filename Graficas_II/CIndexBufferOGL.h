/**
 * @class CIndexBufferOGL
 *
 * @brief class for index buffers of opengl
 *
 * This class is to use unsigned int of index buffer that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CIndexBuffer.h"
class CIndexBufferOGL : public CIndexBuffer
{

	/// Default Constructor
	CIndexBufferOGL() = default;

	/// Destructor
	~CIndexBufferOGL() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_IBO, is for a index buffer
	*/
	unsigned int m_IBO;

	friend class COGLGraphiAPI;
};

