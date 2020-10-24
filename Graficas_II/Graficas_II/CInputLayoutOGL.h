/**
 * @class CInputLayoutOGL
 *
 * @brief class for the input layout of opengl
 *
 * This class is to use the unsigned int of input layout that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CInputLayout.h"
class CInputLayoutOGL : public CInputLayout
{
protected:
	/// Default Constructor
	CInputLayoutOGL() = default;

	/// Destructor
	~CInputLayoutOGL() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_IPLA, unsigned int for the input layout
	*/
	unsigned int m_IPLA;

	friend class COGLGraphiAPI;
};

