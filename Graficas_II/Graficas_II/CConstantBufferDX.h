/**
 * @class CConstantBufferDX
 *
 * @brief class for all constant buffers of directx
 *
 * This class is to use all pointers of constant buffer that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */

#pragma once
#include "CConstantBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>
class CConstantBufferDX : public CConstantBuffer
{
protected:
    /// Default Constructor
    CConstantBufferDX() = default;

    /// Destructor
    ~CConstantBufferDX() = default;

    //Separar los buffer en diferentes clases

    /**
      * @brief protected variables member
    */

    /**
      * @Variable m_pConstantBuffer, is for a constant buffer
    */
    ID3D11Buffer* m_pConstantBuffer = nullptr;

    friend class CDXGraphiAPI;
};

