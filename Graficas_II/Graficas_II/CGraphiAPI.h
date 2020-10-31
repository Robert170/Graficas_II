/**
 * @class CGraphiAPI
 *
 * @brief class base for the GraphiApi
 *
 * This class is the base for graphiapi of Directx and opengl
 *
 * @author Roberto Ramírez (idv18c.rramirez@uartesdigitales.edu.mx)
 *
 * @date 9/24/2020
 *
 *
 * @bug	No know Bugs
 */
#pragma once

#include <windows.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class CTexture;
class CIndexBuffer;
class CVertexBuffer;
class CConstantBuffer;
class CPixelShader;
class CVertexShader;
class CSamplerState;
class CPixelShader;
class CVertexShader;
class CInputLayout;
class CRasterizerState;

using TEXTURE_FORMAT = enum
{
	TF_UNKNOWN = 0,
	TF_R32G32B32A32_TYPELESS = 1,
	TF_R32G32B32A32_FLOAT = 2,
	TF_R32G32B32A32_UINT = 3,
	TF_R32G32B32A32_SINT = 4,
	TF_R32G32B32_TYPELESS = 5,
	TF_R32G32B32_FLOAT = 6,
	TF_R32G32B32_UINT = 7,
	TF_R32G32B32_SINT = 8,
	TF_R16G16B16A16_TYPELESS = 9,
	TF_R16G16B16A16_FLOAT = 10,
	TF_R16G16B16A16_UNORM = 11,
	TF_R16G16B16A16_UINT = 12,
	TF_R16G16B16A16_SNORM = 13,
	TF_R16G16B16A16_SINT = 14,
	TF_R32G32_TYPELESS = 15,
	TF_R32G32_FLOAT = 16,
	TF_R32G32_UINT = 17,
	TF_R32G32_SINT = 18,
	TF_R32G8X24_TYPELESS = 19,
	TF_D32_FLOAT_S8X24_UINT = 20,
	TF_R32_FLOAT_X8X24_TYPELESS = 21,
	TF_X32_TYPELESS_G8X24_UINT = 22,
	TF_R10G10B10A2_TYPELESS = 23,
	TF_R10G10B10A2_UNORM = 24,
	TF_R10G10B10A2_UINT = 25,
	TF_R11G11B10_FLOAT = 26,
	TF_R8G8B8A8_TYPELESS = 27,
	TF_R8G8B8A8_UNORM = 28,
	TF_R8G8B8A8_UNORM_SRGB = 29,
	TF_R8G8B8A8_UINT = 30,
	TF_R8G8B8A8_SNORM = 31,
	TF_R8G8B8A8_SINT = 32,
	TF_R16G16_TYPELESS = 33,
	TF_R16G16_FLOAT = 34,
	TF_R16G16_UNORM = 35,
	TF_R16G16_UINT = 36,
	TF_R16G16_SNORM = 37,
	TF_R16G16_SINT = 38,
	TF_R32_TYPELESS = 39,
	TF_D32_FLOAT = 40,
	TF_R32_FLOAT = 41,
	TF_R32_UINT = 42,
	TF_R32_SINT = 43,
	TF_R24G8_TYPELESS = 44,
	TF_D24_UNORM_S8_UINT = 45,
	TF_R24_UNORM_X8_TYPELESS = 46,
	TF_X24_TYPELESS_G8_UINT = 47,
	TF_R8G8_TYPELESS = 48,
	TF_R8G8_UNORM = 49,
	TF_R8G8_UINT = 50,
	TF_R8G8_SNORM = 51,
	TF_R8G8_SINT = 52,
	TF_R16_TYPELESS = 53,
	TF_R16_FLOAT = 54,
	TF_D16_UNORM = 55,
	TF_R16_UNORM = 56,
	TF_R16_UINT = 57,
	TF_R16_SNORM = 58,
	TF_R16_SINT = 59,
	TF_R8_TYPELESS = 60,
	TF_R8_UNORM = 61,
	TF_R8_UINT = 62,
	TF_R8_SNORM = 63,
	TF_R8_SINT = 64,
	TF_A8_UNORM = 65,
	TF_R1_UNORM = 66,
	TF_R9G9B9E5_SHAREDEXP = 67,
	TF_R8G8_B8G8_UNORM = 68,
	TF_G8R8_G8B8_UNORM = 69,
	TF_BC1_TYPELESS = 70,
	TF_BC1_UNORM = 71,
	TF_BC1_UNORM_SRGB = 72,
	TF_BC2_TYPELESS = 73,
	TF_BC2_UNORM = 74,
	TF_BC2_UNORM_SRGB = 75,
	TF_BC3_TYPELESS = 76,
	TF_BC3_UNORM = 77,
	TF_BC3_UNORM_SRGB = 78,
	TF_BC4_TYPELESS = 79,
	TF_BC4_UNORM = 80,
	TF_BC4_SNORM = 81,
	TF_BC5_TYPELESS = 82,
	TF_BC5_UNORM = 83,
	TF_BC5_SNORM = 84,
	TF_B5G6R5_UNORM = 85,
	TF_B5G5R5A1_UNORM = 86,
	TF_B8G8R8A8_UNORM = 87,
	TF_B8G8R8X8_UNORM = 88,
	TF_R10G10B10_XR_BIAS_A2_UNORM = 89,
	TF_B8G8R8A8_TYPELESS = 90,
	TF_B8G8R8A8_UNORM_SRGB = 91,
	TF_B8G8R8X8_TYPELESS = 92,
	TF_B8G8R8X8_UNORM_SRGB = 93,
	TF_BC6H_TYPELESS = 94,
	TF_BC6H_UF16 = 95,
	TF_BC6H_SF16 = 96,
	TF_BC7_TYPELESS = 97,
	TF_BC7_UNORM = 98,
	TF_BC7_UNORM_SRGB = 99,
	TF_AYUV = 100,
	TF_Y410 = 101,
	TF_Y416 = 102,
	TF_NV12 = 103,
	TF_P010 = 104,
	TF_P016 = 105,
	TF_420_OPAQUE = 106,
	TF_YUY2 = 107,
	TF_Y210 = 108,
	TF_Y216 = 109,
	TF_NV11 = 110,
	TF_AI44 = 111,
	TF_IA44 = 112,
	TF_P8 = 113,
	TF_A8P8 = 114,
	TF_B4G4R4A4_UNORM = 115,

	TF_P208 = 130,
	TF_V208 = 131,
	TF_V408 = 132,

	TF_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE = 189,
	TF_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE = 190,

	TF_FORCE_UINT = 0xffffffff
};

using TEXTURE_BIND_FLAG = enum
{
	TEXTURE_BIND_SHADER_RESOURCE = 0x8L,
	TEXTURE_BIND_RENDER_TARGET = 0x20L,
	TEXTURE_BIND_DEPTH_STENCIL = 0x40L,
	TEXTURE_BIND_UNORDERED_ACCESS = 0x80L,
};

using TYPE_USAGE = enum
{
	TYPE_USAGE_DEFAULT = 0,
	TYPE_USAGE_IMMUTABLE = 1,
	TYPE_USAGE_DYNAMIC = 2,
	TYPE_USAGE_STAGING = 3
};	

using CLEAR_FLAG = enum
{
	CLEAR_DEPTH = 0x1L,
	CLEAR_STENCIL = 0x2L
};

struct SimpleVertex
{
	glm::vec3 Pos;
	glm::vec2 Tex;
};

struct CBNeverChanges
{
	glm::mat4x4 mView;
};
struct CBChangeOnResize
{
	glm::mat4x4 mProjection;
};

struct CBChangesEveryFrame
{
	glm::mat4x4 mWorld;
	glm::vec4 vMeshColor;
};

struct ColorStruct
{
	float R;
	float G;
	float B;
	float A;
};


class CGraphiAPI
{
protected:
	/**
	  * @brief protected functions
	*/


	/**
	  * @brief      InitWindow function, to create window for the api
	  * @param      width parameter one, width of the window
	  * @param      height parameter two, height of the window
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void InitWindow(unsigned int width, 
		                    unsigned int height,
		                    HINSTANCE hInstance,
		                    int nCmdShow) = 0;

	/**
	  * @brief      CreateDeviceandSwap function, to create device and swapchain
	  * @bug		   No know Bugs
	  * @return     Returns nothing
    */
	virtual void CreateDeviceandSwap() = 0;

	/**
	  * @brief      CreateDeferredContext function, to create Deferred Context
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void CreateDeferredContext() = 0;
public:

	/// Default Constructor
	CGraphiAPI() = default;

	/// Destructor
	virtual ~CGraphiAPI() = default;
	

	/**
	  * @brief public functions
	*/


	/**
	  * @brief      Init function, to init the api
	  * @param      width parameter one, width of the window
	  * @param      height parameter two, height of the window
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void Init(unsigned int width,
		              unsigned int height,
		              int nCmdShow,
		              HINSTANCE hInstance) 
	{
		InitWindow(width, height, hInstance, nCmdShow);
		CreateDeviceandSwap();
	}

	//create
	

	/**
	  * @brief      CreateVertexBuffer function, to create vertex buffer
	  * @param      bindFlags parameter one, bind Flags for the desc of vertex buffer
	  * @param      Ver parameter two, a vector whit positions and tex of vertices
	  * @param      ID parameter three, id for the vertex buffer
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CBuffer
	*/

	//preguntar tamaño del buffer, puntero del inicio del buffer y tamaño del buffer
	virtual CVertexBuffer* CreateVertexBuffer(std::vector <SimpleVertex> Ver, 
		                                      unsigned int BufferSize,
		                                      unsigned int NumBuffer = 0) = 0;

	/**
	  * @brief      CreateIndexBuffer function, to create index buffer
	  * @param      bindFlags parameter one, bind Flags for the desc of index buffer
	  * @param      Ind parameter two, a vector unsigned ints of indices
	  * @param      ID parameter three, id for the index buffer
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CBuffer
	*/
	virtual CIndexBuffer* CreateIndexBuffer(const std::vector<unsigned int> & Ind,
		                                    unsigned int BufferSize,
		                                    unsigned int NumBuffer = 0) = 0;

	/**
	  * @brief      CreateConstantBuffer function, to create constant buffer
	  *             Never Change
	  * @param      bindFlags parameter one, bind Flags for the desc of constant buffer
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CBuffer
	*/
	virtual CConstantBuffer* CreateConstantBuffer(unsigned int BufferSize,
		                                          unsigned int NumBuffer = 0) = 0;



	/**
	  * @brief      CreateTexture1D function, to create a texture
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void CreateTexture1D() = 0;

	/**
	  * @brief      CreateTexture2D function, to create a texture 2D
	  * @param      width parameter one, width of the texture
	  * @param      height parameter two, height of the texture
	  * @param      numberTexture parameter three, Number of the texture we are create
	  * @param      format parameter fourth, format for the desc of the txture
	  * @param      bindFlags parameter five, bind Flags for the desc of the txture
	  * @param      Usage parameter six, Usage for the desc of the txture
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CTexture
	*/
	virtual CTexture* CreateTexture2D(unsigned int width,
		                              unsigned int height,
		                              unsigned int numberTexture, //deberia estar en la clase texture
		                              TEXTURE_FORMAT format = TF_R8G8B8A8_UNORM,
		                              unsigned int bindFlags = TEXTURE_BIND_SHADER_RESOURCE,
		                              TYPE_USAGE Usage = TYPE_USAGE_DEFAULT) = 0;

	/**
	  * @brief      CreateTexture3D function, to create a texture 3D
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void CreateTexture3D() = 0;


	/**
	  * @brief      CreatePixelShaders function, to create pixel shader
	  * @param      FileName parameter one, name of the file of the pixel shader
	  * @param      Entry parameter two, point of entry in the file
	  * @param      ShaderModel parameter three, shader model of pixel shader
	  * @param      NumPixelShader parameter fourth, number of the pixel shader
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CPixelShader
	*/
	virtual CPixelShader* CreatePixelShaders(std::string FileName,
		                                    std::string Entry = "",
		                                    std::string ShaderModel = "",
		                                    int NumPixelShader = 0) = 0; //no va
	/**
	  * @brief      CreateVertexShaders function, to create vertex shader
	  * @param      FileName parameter one, name of the file of the vertex shader
	  * @param      Entry parameter two, point of entry in the file
	  * @param      ShaderModel parameter three, shader model of vertex shader
	  * @param      NumVertexShader parameter fourth, number of the vertex shader
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CVertexShader
	*/
	virtual	CVertexShader* CreateVertexShaders(std::string FileName,
		                                       std::string Entry = "",
		                                       std::string ShaderModel = "",
		                                       int NumVertexShader = 0) = 0; //no va
	/**
	  * @brief      CreateInputLayout function, to create the input layaout
	  * @param      Vertex parameter one, a pointer of vertex shader for use his blop
	  * @param      SemanticName parameter two, a vector of strign with semanticname
	  * @param      NumInputLayout parameter three, number of input layout
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CInputLayout
	*/
	virtual CInputLayout* CreateInputLayout(CVertexShader* Vertex,
		                                    std::vector<std::string> SemanticName,
		                                    unsigned int NumInputLayout = 0) = 0; //no va

	/**
	 * @brief      CreateSamplerState function, to create the sampler state
	 * @param      NumSamplerState parameter two, number of sampler state
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CSamplerState
	*/
	virtual CSamplerState* CreateSamplerState(unsigned int NumSamplerState = 0) = 0; //no va

	/**
	  * @brief      CreateRasterizerState function, to create the sampler state
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CRasterizerState
	*/
	virtual CRasterizerState* CreateRasterizerState() = 0; //falta parametros
	

	//set

	/**
	  * @brief      SetVertexBuffer function, to set vertex buffer
	  * @param      VerBuff parameter one, a pointer of CVertexBuffer
	  * @param      StartSlot parameter two, start slot for set vertex buffer
	  * @param      NumBuffer parameter three, number of buffer
	  * @param      stride parameter fourth, stride for set vertex buffer
	  * @param      offset parameter five, offset for set vertex buffer
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetVertexBuffer(CVertexBuffer* VerBuff,
		                         unsigned int StartSlot,
		                         unsigned int NumBuffers,
		                         unsigned int stride, //deben estar en la clase buffer
		                         unsigned int offset) = 0; //deben estar en la clase buffer

	/**
	  * @brief      SetIndexBuffer function, to set index buffer
	  * @param      IndBuff parameter one, a pointer of CIndexBuffer
	  * @param      offset parameter two, offset for set index buffer
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetIndexBuffer(CIndexBuffer* IndBuff, 
		                        unsigned int offset) = 0; //deben estar en la clase buffer

	/**
	  * @brief      SetConstantBuffer function, to set constant buffer Never changes
	  * @param      ConstBuff parameter one, a pointer of CConstantBuffer
	  * @param      StartSlot parameter two, start slot for set constant buffer
	  * @param      NumBuffer parameter three, number of buffer
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetConstantBuffer(CConstantBuffer* ConstBuff,
		                           unsigned int StartSlot,
		                           unsigned int NumBuffers) = 0;

	


	/**
	  * @brief      SetPixelShaders function, to set pixel shader
	  * @param      Pixel parameter one, a pointer of CPixelShader
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetPixelShaders(CPixelShader * Pixel) = 0;

	/**
	  * @brief      SetVertexShaders function, to set vertex shader
	  * @param      Pixel parameter one, a pointer of CVertexShader
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetVertexShaders(CVertexShader* Vertex) = 0;

	/**
	  * @brief      SetInputLayout function, to set input layout
	  * @param      Inp parameter one, a pointer of CInputLayout
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetInputLayout(CInputLayout* Inp) = 0;

	/**
	  * @brief      SetSamplerState function, to set sampler state
	  * @param      Sam parameter one, a pointer of CSamplerState
	  * @param      StartSlot parameter two, start slot for set sampler state
	  * @param      NumSamplers parameter three, number of sampler
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetSamplerState(const std::vector<CSamplerState*>& Sam,
		                         unsigned int StartSlot) = 0; //

	/**
	  * @brief      SetDepthStencil function, to set depth stencil
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetDepthStencil(CTexture* pDSTex) = 0; ///necesita recibir una textura

	/**
	  * @brief      SetRasterizerState function, to set rasteraizer state
	  * @param      RasState parameter one, a pointer of CRasterizerState
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetRasterizerState(CRasterizerState* RasState) = 0;

	/**
	  * @brief      SetRenderTarget function, to set render target
	  * @param      pRTTex parameter one, a pointer of CTexture
	  * @param      pDSTex parameter two, a pointer of CTexture
	  * @param      NumView parameter three, number of render target view
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetRenderTarget(const std::vector<CTexture*>& pRTTex, 
		                         CTexture* pDSTex = nullptr) = 0;

	/**
	  * @brief      SetShaderResouerce function, to set shader resource
	  * @param      pRTTex parameter one, a pointer of CTexture
	  * @param      pDSTex parameter two, a pointer of CTexture
	  * @param      NumView parameter three, number of render target view
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/ 
	virtual void SetShaderResource(const std::vector<CTexture*>& pRTTex, 
		                           unsigned int StartSlot = 0) = 0;
	
	/**
	  * @brief      SetViewport function, to set viewport
	  * @param      NumViewport parameter one, number of viewport
	  * @param      Width parameter two, width for the desc of viewport
	  * @param      Height parameter three, height for the desc of viewport
	  * @param      TopLeftX parameter fourth, TopLeftX for the desc of viewport
	  * @param      TopLeftY parameter five, TopLeftY for the desc of viewport
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void SetViewport(unsigned int NumViewport,
		                     float Width,
		                     float Height,
		                     float TopLeftX = 0,
		                     float TopLeftY = 0 ) = 0; //falta checar eje z
	//clear

	/**
	  * @brief      ClearRendTarView function, to clear the render target view
	  * @param      RT parameter one, a pointer of CTexture
	  * @param      ClearColor parameter two, of for the color of back buffer
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void ClearRenderTarget(CTexture* RT,
		                           ColorStruct Color) = 0; //structura de color con 4 flotantes

	/**
	  * @brief      ClearDepthStenView function, to clear the depth stencil view
	  * @param      RT parameter one, a pointer of CTexture
	  * @param      ClerFlag parameter two, a flag for clear the depth stencil view
	  * @param      Depth parameter three, a depth for clear the depth stencil view
	  * @param      Stencil parameter fourt, a stencil for clear the depth stencil view
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void ClearDepthStencil(CTexture* RT,
		                            CLEAR_FLAG ClerFlag = CLEAR_DEPTH,
		                            float Depth = 1.0f,
		                            unsigned int Stencil = 0) = 0;
		

	//draw

	/**
	  * @brief      DrawIndexed function, to draw
	  * @param      SizeIndex parameter one, num of index
	  * @param      StartindexLocation parameter two, start index location
	  * @param      BaseVertexLocation parameter two, base vertex location
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void DrawIndexed(unsigned int NumIndex,
		                     unsigned int StartindexLocation,
		                     unsigned int BaseVertexLocation) = 0; 

	/**
	  * @brief      DrawInstanced function, to draw
	  * @param      VertexCountPerInstance parameter one, Number of vertices to draw
	  * @param      InstanceCount parameter two, Number of instances to draw
	  * @param      StartVertexLocation parameter two, Index of the first vertex.
	  * @param      StartInstanceLocation parameter one, A value added to each index before 
	  *             reading per-instance data from a vertex buffer
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void DrawInstanced(unsigned int VertexCountPerInstance,
		                       unsigned int InstanceCount,
		                       unsigned int StartVertexLocation,
		                       unsigned int StartInstanceLocation) = 0;

	/**
	  * @brief      Draw function, to draw
	  * @param      VertexCount parameter one, Number of vertices to draw
	  * @param      StartVertexLocation parameter two, Index of the first vertex, which is 
	                usually an offset in a vertex buffer
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void Draw(unsigned int VertexCount,
		              unsigned int StartVertexLocation) = 0;

	//swap

	/**
	  * @brief      Present function, to do swap with swapchain
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	virtual void Present() = 0;

protected:

	/**
	  * @brief protected variables member
	*/

	/**
	  * @Variable m_Width, width of the window
	*/
	unsigned int m_Width = 800;

	/**
	  * @Variable m_Height, height of the window
	*/
	unsigned int m_Height = 600;
};

