/**
 * @class CShaderProgram
 *
 * @brief class base for pixel and vertex shader
 *
 * This class is the base compile and set pixel and vertex shader
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 12/2/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
class CShaderProgram
{
public:
    /// Default Constructor
    CShaderProgram() = default;

    /// Destructor
    virtual ~CShaderProgram() = default;
};

