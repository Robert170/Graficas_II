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
	CRasterizerStateDX() = default;
	~CRasterizerStateDX() = default;

	ID3D11RasterizerState* m_pRasterizerState = nullptr;


	friend class CDXGraphiAPI;
};

