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
	  * @bug		No know Bugs
	  * @return     Returns a pointer of CBuffer
	*/
	CVertexBuffer* CreateVertexBuffer(std::vector <SimpleVertex> Ver,
		                              unsigned int BufferSize,
		                              unsigned int NumBuffer) override;

	/**
	  * @brief      CreateIndexBuffer function, to create index buffer
	  * @param      bindFlags parameter one, bind Flags for the desc of index buffer
	  * @param      Ind parameter two, a vector unsigned ints of indices
	  * @param      ID parameter three, id for the index buffer
	  * @bug		No know Bugs
	  * @return     Returns a pointer of CBuffer
	*/
	CIndexBuffer* CreateIndexBuffer(const std::vector<unsigned int>& Ind,
		                            unsigned int BufferSize,
		                            unsigned int NumBuffer) override; //Numberos de index buffer, deberia estar en la clase buffer

/**
  * @brief      CreateConstantBuffer function, to create constant buffer
  *             Never Change
  * @param      bindFlags parameter one, bind Flags for the desc of constant buffer
  * @bug		No know Bugs
  * @return     Returns a pointer of CBuffer
*/
	CConstantBuffer* CreateConstantBuffer(unsigned int BufferSize,
		                                  unsigned int NumBuffer) override;


	/**
	  * @brief      CreateTexture1D function, to create a texture
	  * @bug		No know Bugs
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
	  * @bug		No know Bugs
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
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void CreateTexture3D() override;

	/**
	  * @brief      CreatePixelShaders function, to create pixel shader
	  * @param      FileName parameter one, name of the file of the pixel shader
	  * @param      Entry parameter two, point of entry in the file
	  * @param      ShaderModel parameter three, shader model of pixel shader
	  * @param      NumPixelShader parameter fourth, number of the pixel shader
	  * @bug		No know Bugs
	  * @return     Returns a pointer of CPixelShader
	*/
	CPixelShader* CreatePixelShaders(std::string FileName,
		                             std::string Entry,
		                             std::string ShaderModel,
		                             int NumPixelShader) override;

	/**
	  * @brief      CreateVertexShaders function, to create vertex shader
	  * @param      FileName parameter one, name of the file of the vertex shader
	  * @param      Entry parameter two, point of entry in the file
	  * @param      ShaderModel parameter three, shader model of vertex shader
	  * @param      NumVertexShader parameter fourth, number of the vertex shader
	  * @bug		No know Bugs
	  * @return     Returns a pointer of CVertexShader
	*/
	CVertexShader* CreateVertexShaders(std::string FileName,
		                               std::string Entry,
		                               std::string ShaderModel,
		                               int NumVertexShader) override;

	/**
	  * @brief      CreateInputLayout function, to create the input layaout
	  * @param      Vertex parameter one, a pointer of vertex shader for use his blop
	  * @param      SemanticName parameter two, a vector of strign with semanticname
	  * @param      NumInputLayout parameter three, number of input layout
	  * @bug		No know Bugs
	  * @return     Returns a pointer of CInputLayout
	*/
	CInputLayout* CreateInputLayout(CVertexShader* Vertex,
		                            std::vector<std::string> SemanticName,
		                            unsigned int NumInputLayout) override;

	/**
	 * @brief      CreateSamplerState function, to create the sampler state
	 * @param      NumSamplerState parameter two, number of sampler state
	 * @bug		   No know Bugs
	 * @return     Returns a pointer of CSamplerState
	*/
	CSamplerState* CreateSamplerState(unsigned int NumSamplerState) override;

	/**
	  * @brief      CreateRasterizerState function, to create the sampler state
	  * @bug		No know Bugs
	  * @return     Returns a pointer of CRasterizerState
	*/
	CRasterizerState* CreateRasterizerState() override;


	//set

	/**
	  * @brief      SetVertexBuffer function, to set vertex buffer
	  * @param      VerBuff parameter one, a pointer of CVertexBuffer
	  * @param      StartSlot parameter two, start slot for set vertex buffer
	  * @param      NumBuffer parameter three, number of buffer
	  * @param      stride parameter fourth, stride for set vertex buffer
	  * @param      offset parameter five, offset for set vertex buffer
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetVertexBuffer(CVertexBuffer* VerBuff,
		                 unsigned int StartSlot,
		                 unsigned int NumBuffer,
		                 unsigned int stride,
		                 unsigned int offset) override;


	/**
	  * @brief      SetIndexBuffer function, to set index buffer
	  * @param      IndBuff parameter one, a pointer of CIndexBuffer
	  * @param      offset parameter two, offset for set index buffer
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetIndexBuffer(CIndexBuffer* IndBuff,
		                unsigned int offset)override;


	/**
	  * @brief      SetConstantBuffer function, to set constant buffer Never changes
	  * @param      ConstBuff parameter one, a pointer of CConstantBuffer
	  * @param      StartSlot parameter two, start slot for set constant buffer
	  * @param      NumBuffer parameter three, number of buffer
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetConstantBuffer(CConstantBuffer* ConstBuff,
		                   unsigned int StartSlot,
		                   unsigned int NumBuffer) override;

	/**
	  * @brief      SetPixelShaders function, to set pixel shader
	  * @param      Pixel parameter one, a pointer of CPixelShader
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetPixelShaders(CPixelShader* Pixel) override;

	/**
	  * @brief      SetVertexShaders function, to set vertex shader
	  * @param      Pixel parameter one, a pointer of CVertexShader
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetVertexShaders(CVertexShader* Vertex)override;

	/**
	  * @brief      SetInputLayout function, to set input layout
	  * @param      Inp parameter one, a pointer of CInputLayout
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetInputLayout(CInputLayout* Inp) override;

	/**
	  * @brief      SetSamplerState function, to set sampler state
	  * @param      Sam parameter one, a pointer of CSamplerState
	  * @param      StartSlot parameter two, start slot for set sampler state
	  * @param      NumSamplers parameter three, number of sampler
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetSamplerState(const std::vector<CSamplerState*>& Sam,
		                 unsigned int StartSlot) override;

	/**
	  * @brief      SetDepthStencil function, to set depth stencil
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetDepthStencil() override;

	/**
	  * @brief      SetRasterizerState function, to set rasteraizer state
	  * @param      RasState parameter one, a pointer of CRasterizerState
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetRasterizerState(CRasterizerState* RasState) override;

	/**
	  * @brief      SetRenderTarget function, to set render target
	  * @param      pRTTex parameter one, a pointer of CTexture
	  * @param      pDSTex parameter two, a pointer of CTexture
	  * @param      NumView parameter three, number of render target view
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetRenderTarget(const std::vector<CTexture*>& pRTTex,
		                 CTexture* pDSTex) override;

	/**
	  * @brief      SetShaderResouerce function, to set shader resource
	  * @param      pRTTex parameter one, a pointer of CTexture
	  * @param      pDSTex parameter two, a pointer of CTexture
	  * @param      NumView parameter three, number of render target view
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetShaderResource(const std::vector<CTexture*>& pRTTex,
		                   unsigned int StartSlot) override;

	/**
	  * @brief      SetViewport function, to set viewport
	  * @param      NumViewport parameter one, number of viewport
	  * @param      Width parameter two, width for the desc of viewport
	  * @param      Height parameter three, height for the desc of viewport
	  * @param      TopLeftX parameter fourth, TopLeftX for the desc of viewport
	  * @param      TopLeftY parameter five, TopLeftY for the desc of viewport
	  * @bug		No know Bugs
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
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void ClearRenderTarget(CTexture* RT,
		                   ColorStruct Color) override;

	/**
	  * @brief      ClearDepthStenView function, to clear the depth stencil view
	  * @param      RT parameter one, a pointer of CTexture
	  * @param      ClerFlag parameter two, a flag for clear the depth stencil view
	  * @param      Depth parameter three, a depth for clear the depth stencil view
	  * @param      Stencil parameter fourt, a stencil for clear the depth stencil view
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void ClearDepthStencil(CTexture* RT,
		                   CLEAR_FLAG ClerFlag,
		                   float Depth,
		                   unsigned int Stencil) override;

	//draw

	/**
	  * @brief      DrawIndexed function, to draw
	  * @param      SizeIndex parameter one, num of index
	  * @param      StartindexLocation parameter two, start index location
	  * @param      BaseVertexLocation parameter two, base vertex location
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void DrawIndexed(unsigned int NumIndex,
		             unsigned int StartindexLocation,
		             unsigned int BaseVertexLocation) override;

	/**
	  * @brief      DrawInstanced function, to draw
	  * @param      VertexCountPerInstance parameter one, Number of vertices to draw
	  * @param      InstanceCount parameter two, Number of instances to draw
	  * @param      StartVertexLocation parameter two, Index of the first vertex.
	  * @param      StartInstanceLocation parameter one, A value added to each index before
	  *             reading per-instance data from a vertex buffer
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void DrawInstanced(unsigned int VertexCountPerInstance,
		               unsigned int InstanceCount,
		               unsigned int StartVertexLocation,
		               unsigned int StartInstanceLocation) override;

	/**
	  * @brief      Draw function, to draw
	  * @param      VertexCount parameter one, Number of vertices to draw
	  * @param      StartVertexLocation parameter two, Index of the first vertex, which is
					usually an offset in a vertex buffer
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void Draw(unsigned int VertexCount,
		      unsigned int StartVertexLocation) override;

	//swap

	/**
	 * @brief      Present function, to do swap with swapchain
	 * @bug		   No know Bugs
	 * @return     Returns nothing
	*/
	void Present() override;
};

