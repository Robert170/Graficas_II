/**
 * @class CIndexBuffer
 *
 * @brief class base for constant buffer
 *
 * This class is the base for constant buffer of Directx and opengl
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
class CConstantBuffer
{
public:
    /// Default Constructor
    CConstantBuffer() = default;

    /// Destructor
    virtual ~CConstantBuffer() = default;
};

