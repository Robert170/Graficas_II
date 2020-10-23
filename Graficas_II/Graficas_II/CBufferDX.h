/**
 * @class CBufferDX
 *
 * @brief class for all buffers of directx
 *
 * This class is to use all pointers of buffer that directx needs
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */

#pragma once
#include "CBuffer.h"
#include <d3d11.h>
#include <d3dcompiler.h>
class CBufferDX : public CBuffer
{
protected:
    /// Default Constructor
    CBufferDX() = default;

    /// Destructor
	~CBufferDX() = default;


    /**
      * @brief protected variables member
    */

    /**
      * @Variable m_pVertexBuffer, is for a vertex buffer
    */
    ID3D11Buffer* m_pVertexBuffer = nullptr;


    /**
      * @Variable m_pIndexBuffer, is for an index buffer
    */
    ID3D11Buffer* m_pIndexBuffer = nullptr;


    /**
      * @Variable m_pCBNeverChanges, is for a constant buffer never change
    */
    ID3D11Buffer* m_pCBNeverChanges = nullptr;


    /**
      * @Variable m_pCBChangeOnResize, is for a constant buffer change on resize
    */
    ID3D11Buffer* m_pCBChangeOnResize = nullptr;


    /**
      * @Variable m_pCBChangesEveryFrame, is for a constant buffer change every frame
    */
    ID3D11Buffer* m_pCBChangesEveryFrame = nullptr;

	friend class CDXGraphiAPI;
};

