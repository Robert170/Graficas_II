/**
 * @class CConstantBufferOGL
 *
 * @brief class for constant buffers of opengl
 *
 * This class is to use unsigned int of constant buffer that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CConstantBuffer.h"
class CConstantBufferOGL: public CConstantBuffer
{
	/// Default Constructor
	CConstantBufferOGL() = default;

	/// Destructor
	~CConstantBufferOGL() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_CBO, is for a Constant buffer
	*/
	unsigned int m_CBO = 0;

	friend class COGLGraphiAPI;
};

