/**
 * @class CRasterizerStateOGL
 *
 * @brief class for the rasterizer state of opengl
 *
 * This class is to use the  of rasterizer state that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/20/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CRasterizerState.h"
class CRasterizerStateOGL : public CRasterizerState
{
protected:
	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CRasterizerStateOGL() = default;

	/// Destructor
	~CRasterizerStateOGL() = default;



	friend class COGLGraphiAPI;
};

