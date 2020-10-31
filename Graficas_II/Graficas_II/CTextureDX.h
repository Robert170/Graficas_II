/**
 * @class CTextureDX
 *
 * @brief class for the texture of directx
 *
 * This class is to use the pointers of texture that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once

#include "CTexture.h"
#include <d3d11.h>
#include <d3dcompiler.h>

class CTextureDX : public CTexture
{
protected:
	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CTextureDX() = default;

	/// Destructor
	~CTextureDX() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_Texture, pointer for the texture
	*/
	ID3D11Texture2D* m_pTexture = nullptr;

	/**
	  * @Variable m_RTV, pointer for the render target view
	*/
	ID3D11RenderTargetView* m_pRTV = nullptr;

	/**
	  * @Variable m_DSV, pointer for the depth stencil view
	*/
	ID3D11DepthStencilView* m_pDSV = nullptr;

	/**
	  * @Variable m_UAV, pointer for the unordered access view
	*/
	ID3D11UnorderedAccessView* m_pUAV = nullptr;

	/**
	  * @Variable m_SRV, pointer for the shader resource view
	*/
	ID3D11ShaderResourceView* m_pSRV = nullptr;

	friend class CDXGraphiAPI;
};
