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
	unsigned int m_texture;

	friend class COGLGraphiAPI;
    
};

