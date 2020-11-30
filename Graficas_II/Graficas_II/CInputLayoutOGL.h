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
#include <map>
class CInputLayoutOGL : public CInputLayout
{
protected:
	/// Default Constructor
	CInputLayoutOGL();

	/// Destructor
	~CInputLayoutOGL() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_IPLA, unsigned int for the input layout
	*/
	unsigned int m_IPLA = 0;

	/**
	  * @Variable m_Size, size, depent of the format
	*/
	unsigned int m_Size = 0;

	/**
	  * @Variable m_Offset, offset for each element 
	*/
	unsigned int m_Offset = 0;

	/**
	  * @Variable m_mFormatSize, map whit the size of formats
	*/
	std::map<unsigned int, unsigned int> m_mFormatSize;

	unsigned int GetSize(unsigned int Format);

	friend class COGLGraphiAPI;
};

