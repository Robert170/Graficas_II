/**
 * @class CSamplerStateDX
 *
 * @brief class for the sampler state of directx
 *
 * This class is to use the pointers of sampler state that directx needs
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
#include <d3d11.h>
#include <d3dcompiler.h>
class CSamplerStateDX : public CSamplerState
{
protected:
	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CSamplerStateDX() = default;

	/// Destructor
	~CSamplerStateDX();

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_pSamplerLinear, pointer for the sampler state
	*/
	ID3D11SamplerState* m_pSamplerLinear = nullptr;

	friend class CDXGraphiAPI;
    
};

