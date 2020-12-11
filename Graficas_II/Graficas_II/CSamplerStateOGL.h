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
#include "glad.h"
class CSamplerStateOGL : public CSamplerState
{

public:
	/**
	  * @brief public functions
	*/

	/// Destructor
	~CSamplerStateOGL();

protected:

	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CSamplerStateOGL() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_SamSt, unsigned int for the sampler state
	*/
	unsigned int m_SamSt = 0;

	/**
	  * @Variable m_SamSt, unsigned int for the sampler state
	*/
	unsigned int m_NumberOfSampler = 0;

	friend class COGLGraphiAPI;
};

