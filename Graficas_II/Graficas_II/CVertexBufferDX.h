/**
 * @class CVertexBufferDX
 *
 * @brief class for vertex buffers of directx
 *
 * This class is to use pointer of vertex buffer that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CVertexBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>

class CVertexBufferDX : public CVertexBuffer
{
protected:
    /// Default Constructor
    CVertexBufferDX() = default;

    /// Destructor
    ~CVertexBufferDX() = default;

    //Separar los buffer en diferentes clases

    /**
      * @brief protected variables member
    */

    /**
      * @Variable m_pVertexBuffer, is for a vertex buffer
    */
    ID3D11Buffer* m_pVertexBuffer = nullptr;

    friend class CDXGraphiAPI;
};

