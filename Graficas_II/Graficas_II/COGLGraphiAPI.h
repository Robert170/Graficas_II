#pragma once
#include "glad.h"
#include "GLFW/glfw3.h"
#include "CGraphiAPI.h"
class COGLGraphiAPI : public CGraphiAPI
{
private:

	/**
	  * @brief private variables member
	*/

	/**
	  * @Variable m_AttachShaderID
	*/
	unsigned int m_AttachShaderID;

	/**
	  * @Variable m_window, a variable for a window
	*/
	GLFWwindow* m_window;

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
	void InitWindow(unsigned int width,
		            unsigned int height,
		            HINSTANCE hInstance,
		            int nCmdShow) override;

	/**
	 * @brief      CreateDeviceandSwap function, to create device and swapchain
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void CreateDeviceandSwap() override;

	/**
	 * @brief      CreateDeferredContext function, to create Deferred Context
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void CreateDeferredContext() override;


public:
	/// Default Constructor
	COGLGraphiAPI();

	/// Destructor
	~COGLGraphiAPI();

	/**
	  * @brief public functions
	*/


	//create

	/**
	 * @brief      CreateVertexBuffer function, to create vertex buffer
	 * @param      bindFlags parameter one, bind Flags for the desc of vertex buffer
	 * @param      Ver parameter two, a vector whit positions and tex of vertices
	 * @param      ID parameter three, id for the vertex buffer
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CBuffer
	*/
	CBuffer* CreateVertexBuffer(unsigned int bindFlags,
		                        std::vector <SimpleVertex> Ver,
		                        unsigned int ID) override;

	/**
	 * @brief      CreateIndexBuffer function, to create index buffer
	 * @param      bindFlags parameter one, bind Flags for the desc of index buffer
	 * @param      Ind parameter two, a vector unsigned ints of indices
	 * @param      ID parameter three, id for the index buffer
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CBuffer
	*/
	CBuffer* CreateIndexBuffer(unsigned int bindFlags,
		                       std::vector<unsigned int> Ind,
		                       unsigned int ID) override;

	/**
	 * @brief      CreateConstantBufferNC function, to create constant buffer
	 *             Never Change
	 * @param      bindFlags parameter one, bind Flags for the desc of constant buffer
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CBuffer
	*/
	CBuffer* CreateConstantBufferNC(unsigned int bindFlags) override;

	/**
	 * @brief      CreateConstantBufferCOR function, to create constant buffer
	 *             Change on Resize
	 * @param      bindFlags parameter one, bind Flags for the desc of constant buffer
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CBuffer
	*/
	CBuffer* CreateConstantBufferCOR(unsigned int bindFlags) override;

	/**
	 * @brief      CreateConstantBufferCEF function, to create constant buffer
	 *             Change Every Frame
	 * @param      bindFlags parameter one, bind Flags for the desc of constant buffer
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CBuffer
	*/
	CBuffer* CreateConstantBufferCEF(unsigned int bindFlags) override;

	/**
	 * @brief      CreateTexture1D function, to create a texture
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void CreateTexture1D() override;

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
	CTexture* CreateTexture2D(unsigned int width,
		                      unsigned int height,
		                      unsigned int numberTexture,
		                      TEXTURE_FORMAT format,
		                      unsigned int bindFlags,
		                      TYPE_USAGE Usage) override;

	/**
	 * @brief      CreateTexture3D function, to create a texture 3D
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void CreateTexture3D() override;

	/**
	 * @brief      CreatePixelShaders function, to create pixel shader
	 * @param      FileName parameter one, name of the file of the pixel shader
	 * @param      Entry parameter two, point of entry in the file
	 * @param      ShaderModel parameter three, shader model of pixel shader
	 * @param      ID parameter fourth, id of the pixel shader
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CPixelShader
	*/
	CPixelShader* CreatePixelShaders(std::string FileName,
		                             std::string Entry,
		                             std::string ShaderModel,
		                             int ID) override;

	/**
	 * @brief      CreateVertexShaders function, to create vertex shader
	 * @param      FileName parameter one, name of the file of the vertex shader
	 * @param      Entry parameter two, point of entry in the file
	 * @param      ShaderModel parameter three, shader model of vertex shader
	 * @param      ID parameter fourth, id of the vertex shader
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CVertexShader
	*/
	CVertexShader* CreateVertexShaders(std::string FileName,
		                               std::string Entry,
		                               std::string ShaderModel,
		                               int ID) override;

	/**
	 * @brief      CreateInputLayout function, to create the input layaout
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CInputLayout
	*/
	CInputLayout* CreateInputLayout(unsigned int ID) override;

	/**
	 * @brief      CreateSamplerState function, to create the sampler state
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CSamplerState
	*/
	CSamplerState* CreateSamplerState(unsigned int ID) override;

	/**
	 * @brief      CreateRasterizerState function, to create the sampler state
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CRasterizerState
	*/
	CRasterizerState* CreateRasterizerState() override;


	//set

	/**
	 * @brief      SetVertexBuffer function, to set vertex buffer
	 * @param      VerBuff parameter one, a pointer of CBuffer
	 * @param      StartSlot parameter two, start slot for set vertex buffer
	 * @param      NumBuffer parameter three, number of buffer
	 * @param      stride parameter fourth, stride for set vertex buffer
	 * @param      offset parameter five, offset for set vertex buffer
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetVertexBuffer(CVertexBuffer* VerBuff,
		                 unsigned int StartSlot,
		                 unsigned int NumBuffer,
		                 unsigned int stride,
		                 unsigned int offset) override;


	/**
	 * @brief      SetIndexBuffer function, to set index buffer
	 * @param      IndBuff parameter one, a pointer of CBuffer
	 * @param      offset parameter two, offset for set index buffer
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetIndexBuffer(CIndexBuffer* IndBuff,
		                unsigned int offset)override;


	/**
	 * @brief      SetConstantBufferNC function, to set constant buffer Never changes
	 * @param      ConstBuff parameter one, a pointer of CBuffer
	 * @param      StartSlot parameter two, start slot for set constant buffer
	 * @param      NumBuffer parameter three, number of buffer
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetConstantBufferNC(CBuffer* ConstBuff,
		                     unsigned int StartSlot,
		                     unsigned int NumBuffer) override;

	/**
	 * @brief      SetPixelShaders function, to set pixel shader
	 * @param      Pixel parameter one, a pointer of CPixelShader
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetPixelShaders(CPixelShader* Pixel) override;

	/**
	 * @brief      SetVertexShaders function, to set vertex shader
	 * @param      Pixel parameter one, a pointer of CVertexShader
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetVertexShaders(CVertexShader* Vertex)override;

	/**
	 * @brief      SetInputLayout function, to set input layout
	 * @param      Inp parameter one, a pointer of CInputLayout
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetInputLayout(CInputLayout* Inp) override;

	/**
	 * @brief      SetSamplerState function, to set sampler state
	 * @param      Sam parameter one, a pointer of CSamplerState
	 * @param      StartSlot parameter two, start slot for set sampler state
	 * @param      NumSamplers parameter three, number of sampler
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetSamplerState(CSamplerState* Sam,
		                 unsigned int StartSlot,
		                 unsigned int NumSamplers) override;

	/**
	 * @brief      SetDepthStencil function, to set depth stencil
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetDepthStencil() override;

	/**
	 * @brief      SetRasterizerState function, to set rasteraizer state
	 * @param      RasState parameter one, a pointer of CRasterizerState
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetRasterizerState(CRasterizerState* RasState) override;

	/**
	 * @brief      SetRenderTarget function, to set render target
	 * @param      pRTTex parameter one, a pointer of CTexture
	 * @param      pDSTex parameter two, a pointer of CTexture
	 * @param      NumView parameter three, number of render target view
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetRenderTarget(CTexture* pRTTex,
		                 CTexture* pDSTex,
		                 unsigned int NumView) override;

	/**
	 * @brief      SetShaderResouerce function, to set shader resource
	 * @param      pRTTex parameter one, a pointer of CTexture
	 * @param      pDSTex parameter two, a pointer of CTexture
	 * @param      NumView parameter three, number of render target view
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void SetShaderResource(CTexture* pRTTex,
		                   unsigned int StartSlot,
		                   unsigned int NumSamplers) override;

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
	void SetViewport(unsigned int NumViewport,
		             float Width,
		             float Height,
		             float TopLeftX,
		             float TopLeftY) override;

	//clear

	/**
	 * @brief      ClearRendTarView function, to clear the render target view
	 * @param      RT parameter one, a pointer of CTexture
	 * @param      ClearColor parameter two, of for the color of back buffer
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void ClearRendTarView(CTexture* RT,
		                  std::vector<float> ClearColor) override;

	/**
	 * @brief      ClearDepthStenView function, to clear the depth stencil view
	 * @param      RT parameter one, a pointer of CTexture
	 * @param      ClerFlag parameter two, a flag for clear the depth stencil view
	 * @param      Depth parameter three, a depth for clear the depth stencil view
	 * @param      Stencil parameter fourt, a stencil for clear the depth stencil view
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void ClearDepthStenView(CTexture* RT,
		                    CLEAR_FLAG ClerFlag,
		                    float Depth,
		                    unsigned int Stencil) override;

	//draw

	/**
	 * @brief      Drawindex function, to draw
	 * @param      SizeIndex parameter one, size of index
	 * @param      StartindexLocation parameter two, index location
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void Drawindexed(int NumIndex,
		             int StartindexLocation) override;

	//swap

	/**
	 * @brief      Present function, to do swap with swapchain
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void Present() override;
};

