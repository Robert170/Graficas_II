/**
 * @class CPixelShader
 *
 * @brief class base for pixell shader
 *
 * This class is the base for pixel shader of Directx and opengl
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include <iostream>
class CPixelShader
{
public:
	/// Default Constructor
	CPixelShader() = default;

	/// Destructor
	virtual ~CPixelShader() = default;
};

