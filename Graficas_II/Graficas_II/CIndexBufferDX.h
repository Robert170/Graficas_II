/**
 * @class CIndexBufferDX
 *
 * @brief class for index buffers of directx
 *
 * This class is to use pointer of index buffer that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/25/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CIndexBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>
class CIndexBufferDX : public CIndexBuffer
{
public:
    /// Destructor
    ~CIndexBufferDX();
protected:
    /// Default Constructor
    CIndexBufferDX() = default;

    //Separar los buffer en diferentes clases

    /**
      * @brief protected variables member
    */

    /**
      * @Variable m_pIndexBuffer, is for an index buffer
    */
    ID3D11Buffer* m_pIndexBuffer = nullptr;

    unsigned int m_Offset;


    friend class CDXGraphiAPI;
};

