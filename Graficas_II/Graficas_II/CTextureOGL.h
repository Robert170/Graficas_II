/**
 * @class CTextureOGL
 *
 * @brief class for the texture of opengl
 *
 * This class is to use the unsigned int of texture that opengl needs
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
class CTextureOGL : public CTexture
{
protected:
	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CTextureOGL() = default;

	/// Destructor
	~CTextureOGL() = default;

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_texture, unsigned int for the texture
	*/
	unsigned int m_Texture = 0;

	/**
	  * @Variable m_RTV, unsigned int for the render target view
	*/
	unsigned int m_RTV = 0;

	/**
	  * @Variable m_DSV, unsigned int for the depth stencil view
	*/
	unsigned int m_DSV = 0;

	/**
	  * @Variable m_UAV, unsigned int for the unordered access view
	*/
	unsigned int m_UAV = 0;

	/**
	  * @Variable m_SRV, unsigned int for the shader resource view
	*/
	unsigned int m_SRV = 0;

	friend class COGLGraphiAPI;
    
};

