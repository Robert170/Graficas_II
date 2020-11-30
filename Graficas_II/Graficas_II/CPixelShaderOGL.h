/**
 * @class CPixelShaderOGL
 *
 * @brief class for the pixel shader of opengl
 *
 * This class is to use the unsigned int of pixel shader and fuctions that opengl needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CPixelShader.h"
#include <fstream>
#include <sstream>
class CPixelShaderOGL : public CPixelShader
{
protected:
	/**
	  * @brief protected functions
	*/

	/// Default Constructor
	CPixelShaderOGL() = default;

	/// Destructor
	~CPixelShaderOGL() = default;

	/**
	 * @brief      ReadFile function, to read a file
	 * @param      FileName parameter one, name of the file with the shader
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	std::string ReadFile(std::string FileName);

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_PixelCode, string where we save te code of the pixel shade
	*/
	std::string m_PixelCode;

	/**
	  * @Variable m_PixelShaderFile, for open file, take exepcions 
	*/
	std::ifstream m_PixelShaderFile;

	/**
      * @Variable m_PixelShaderStream, this is temp for transfor in string
    */ 
	std::stringstream m_PixelShaderStream;

	/**
	  * @Variable m_PixelShader, unsigned int for the pixel shader
	*/
	unsigned int m_PixelShader;



	friend class COGLGraphiAPI;
};

