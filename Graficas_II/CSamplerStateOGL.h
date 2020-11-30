/**
 * @class CSamplerStateOGL
 *
 * @brief class for the sampler state of opengl
 *
 * This class is to use the unsigned int of sampler state that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CSamplerState.h"
class CSamplerStateOGL : public CSamplerState
{
protected:

	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CSamplerStateOGL() = default;
	~CSamplerStateOGL() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_SamSt, unsigned int for the sampler state
	*/
	unsigned int m_SamSt;

	friend class COGLGraphiAPI;
};

