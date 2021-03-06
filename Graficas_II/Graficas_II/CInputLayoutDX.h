/**
 * @class CInputLayoutDX
 *
 * @brief class for the input layout of directx
 *
 * This class is to use the pointers of input layout that directx needs
 *
 * @author Roberto Ram�rez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 10/6/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once
#include "CInputLayout.h"
#include <d3d11.h>
#include <d3dcompiler.h>
class CInputLayoutDX : public CInputLayout
{
public:
	/// Destructor
	~CInputLayoutDX();
protected:

	/// Default Constructor
	CInputLayoutDX() = default;

	

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_pInputLayout, pointer for the input layout
	*/
	ID3D11InputLayout* m_pInputLayout = nullptr;//

	friend class CDXGraphiAPI;
};

