/**
 * @class CRasterizerStateDX
 *
 * @brief class for the rasterizer state of directx
 *
 * This class is to use the pointers of rasterizer state that directx needs
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
#include <d3d11.h>
#include <d3dcompiler.h>
class CRasterizerStateDX : public CRasterizerState
{
protected:

	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CRasterizerStateDX() = default;

	/// Destructor
	~CRasterizerStateDX() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_pRasterizerState, pointer for the rasterizer state
	*/
	ID3D11RasterizerState* m_pRasterizerState = nullptr;


	friend class CDXGraphiAPI;
};

