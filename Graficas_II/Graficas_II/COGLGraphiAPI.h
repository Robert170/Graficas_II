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
	  * @Variable m_window, a variable for a window
	*/
	GLFWwindow* m_window;

	int m_AttachShaderID;

	//unsigned int m_BackBuffer;

	//unsigned int m_Depth;

protected:
	/**
	  * @brief protected functions
	*/


	/**
	  * @brief      InitWindow function, to create window for the api
	  * @param      width parameter one, width of the window
	  * @param      height parameter two, height of the window
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void InitWindow(unsigned int width,
		            unsigned int height) override; 

/**
  * @brief      CreateDeviceandSwap function, to create device and swapchain
  * @bug		No know Bugs
  * @return     Returns nothing
*/
	void CreateDeviceandSwap() override;

	/**
	  * @brief      CreateDeferredContext function, to create Deferred Context
	  * @bug		No know Bugs
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

	/**
	  * @brief      InitMatrixWorld function, to init the world matrix
	  * @param      MatrixWorld parameter one, a matrix world to modificate
	  * @return     Returns a world matrix initializaded
	*/
	glm::mat4 InitMatrixWorld(glm::mat4& MatrixWorld);

	/**
	  * @brief      InitMatrixView function, to init the view matrix
	  * @param      MatrixView parameter one, a matrix view to modificate
	  * @param      Eye parameter one, eye for the matrix
	  * @param      At parameter one, lookat for the matrix
	  * @param      Up parameter one, lookat for the matrix
	  * @return     Returns a view matrix initializaded
	*/
	glm::mat4 InitMatrixView(glm::mat4& MatrixView,
		                     glm::vec3& Eye,
		                     glm::vec3& At,
		                     glm::vec3& Up);

	/**
	  * @brief      InitMatrixProjection function, to init the view matrix
	  * @param      MatrixProjection parameter one, a matrix projection to modificate
	  * @param      Fov parameter one,feel of view for the matrix
	  * @param      Height parameter one, Height for the matrix
	  * @param      Width parameter one, Width for the matrix
	  * @param      Near parameter one, Near for the matrix
	  * @param      Far parameter one, Far for the matrix
	  * @return     Returns a view matrix initializaded
	*/
	glm::mat4 InitMatrixProjection(glm::mat4& MatrixProjection,
		                           float &Fov,
		                           float &Height,
		                           float &Width,
		                           float &Near,
		                           float &Far);

	/**
	  * @brief      LoadModel function, to load model
	  * @param      API parameter one, Api to have acces the functions
	  * @param      ID parameter two, id for the vertex buffer
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CBuffer
	*/
	 /*CModel* LoadModel(CGraphiAPI* API,
		               InputLayout_Desc InpLayDesc,
		               std::string Path) override;*/

	//create

	/**
	  * @brief      CreateVertexBuffer function, to create vertex buffer
	  * @param      bindFlags parameter one, bind Flags for the desc of vertex buffer
	  * @param      Ver parameter two, a vector whit positions and tex of vertices
	  * @param      ID parameter three, id for the vertex buffer
	  * @bug		No know Bugs
	  * @return     Returns a pointer of CBuffer
	*/
	CVertexBuffer* CreateVertexBuffer(const std::vector <SimpleVertex>& Ver,
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
	CIndexBuffer* CreateIndexBuffer(const std::vector<uint32_t>& Ind,
		                            unsigned int BufferSize,
		                            unsigned int NumBuffer) override; //Numberos de index buffer, deberia estar en la clase buffer

	/**
	  * @brief      CreateConstantBuffer function, to create constant buffer
	  *             Never Change
	  * @param      BufferSize parameter one, buffer size
	  * @param      NumBuffer parameter two, number of buffer
	  * @param      Data parameter three, void pointer for the data
	  * @bug		No know Bugs
	  * @return     Returns a pointer of CBuffer
	*/
	CConstantBuffer* CreateConstantBuffer(unsigned int BufferSize,
		                                  unsigned int NumBuffer,
		                                  const void* Data) override;


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
	  * @param      format parameter four, format for the desc of the txture
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
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	void CreateTexture3D() override;


	/**
	  * @brief      CreateShaderProgram function, to create shader program
	  * @param      FileNameVS parameter one, name of the file of the vertex shader
	  * @param      FileNamePS parameter two, name of the file of the pixel shader
	  * @param      EntryVS parameter three, point of entry in the file vertex shader
	  * @param      EntryPS parameter four, point of entry in the file pixel shader
	  * @param      ShaderModelVS parameter five, shader model vertex shader
	  * @param      ShaderModelPS parameter six, shader model pixel shader
	  * @param      NumVertexShader parameter seven, number of the vertex shader
	  * @param      NumPixelShader parameter eigth, number of the pixel shader
	  * @bug		No know Bugs
	  * @return     Returns a pointer of CPixelShader
	*/
	CShaderProgram* CreateShaderProgram(const std::string& FileNameVS,
		                                const std::string& FileNamePS,
		                                const std::string& EntryVS,
		                                const std::string& EntryPS,
		                                const std::string& ShaderModelVS,
		                                const std::string& ShaderModelPS,
		                                int NumVertexShader,
		                                int NumPixelShader);

	/**
	  * @brief      CreatePixelShaders function, to create pixel shader
	  * @param      FileName parameter one, name of the file of the pixel shader
	  * @param      Entry parameter two, point of entry in the file
	  * @param      ShaderModel parameter three, shader model of pixel shader
	  * @param      NumPixelShader parameter four, number of the pixel shader
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CPixelShader
	*/
	CPixelShader* CreatePixelShaders(const std::string& FileName,
		                             const std::string& Entry,
		                             const std::string& ShaderModel,
		                             int NumPixelShader) override;

	/**
	  * @brief      CreateVertexShaders function, to create vertex shader
	  * @param      FileName parameter one, name of the file of the vertex shader
	  * @param      Entry parameter two, point of entry in the file
	  * @param      ShaderModel parameter three, shader model of vertex shader
	  * @param      NumVertexShader parameter four, number of the vertex shader
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CVertexShader
	*/
	CVertexShader* CreateVertexShaders(const std::string& FileName,
		                               const std::string& Entry,
		                               const std::string& ShaderModel,
		                               int NumVertexShader) override;

	/**
	  * @brief      CreateInputLayout function, to create the input layaout
	  * @param      Vertex parameter one, a pointer of vertex shader for use his blop
	  * @param      SemanticName parameter two, a vector of strign with semanticname
	  * @param      NumInputLayout parameter three, number of input layout
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CInputLayout
	*/
	CInputLayout* CreateInputLayout(CShaderProgram& Vertex,
	                             	InputLayout_Desc& LayoutDesc,
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
	  * @bug		   No know Bugs
	  * @return     Returns a pointer of CRasterizerState
	*/
	CRasterizerState* CreateRasterizerState() override;


	//set

	/**
	  * @brief      SetVertexBuffer function, to set vertex buffer
	  * @param      VerBuff parameter one, a pointer of CVertexBuffer
	  * @param      StartSlot parameter two, start slot for set vertex buffer
	  * @param      NumBuffer parameter three, number of buffer
	  * @param      stride parameter four, stride for set vertex buffer
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
	  * @param      IndBuff parameter one, a pointer of CIndexBuffer
	  * @param      offset parameter two, offset for set index buffer
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	void SetIndexBuffer(CIndexBuffer* IndBuff,
		                unsigned int offset)override;


	/**
	  * @brief      SetVertexShaderConstantBuffer function, to set constant
	  *             buffer of the vertex shader
	  * @param      ConstBuff parameter one, a pointer of CConstantBuffer
	  * @param      StartSlot parameter two, start slot for set constant buffer
	  * @param      NumBuffer parameter three, number of buffer
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetVertexShaderConstantBuffer(CConstantBuffer* ConstBuff,
		                               unsigned int StartSlot,
		                               unsigned int NumBuffer) override;

	/**
	  * @brief      SetPixelShaderConstantBuffer function, to set constant
	  *             buffer of the pixel shader
	  * @param      ConstBuff parameter one, a pointer of CConstantBuffer
	  * @param      StartSlot parameter two, start slot for set constant buffer
	  * @param      NumBuffer parameter three, number of buffer
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetPixelShaderConstantBuffer(CConstantBuffer* ConstBuff,
		                              unsigned int StartSlot,
		                              unsigned int NumBuffer) override;
	
	/**
	  * @brief      SetShaderProgram function, to set pixel and vertex shader
	  * @param      Pixel parameter one, a pointer of CShaderProgram
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetShaderProgram(CShaderProgram* ShaderProgram);

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
	void SetDepthStencil(CTexture* pDSTex) override;

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
	void SetRenderTarget(const std::vector<CTexture*>& pRTTex,
		                 CTexture* pDSTex) override;

	/**
	  * @brief      SetShaderResouerce function, to set shader resource
	  * @param      pRTTex parameter one, a pointer of CTexture
	  * @param      pDSTex parameter two, a pointer of CTexture
	  * @param      NumView parameter three, number of render target view
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	void SetShaderResource(const std::vector<CTexture*>& pRTTex,
		                   unsigned int StartSlot) override;

	/**
	  * @brief      SetViewport function, to set viewport
	  * @param      NumViewport parameter one, number of viewport
	  * @param      Width parameter two, width for the desc of viewport
	  * @param      Height parameter three, height for the desc of viewport
	  * @param      TopLeftX parameter four, TopLeftX for the desc of viewport
	  * @param      TopLeftY parameter five, TopLeftY for the desc of viewport
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	void SetViewport(unsigned int NumViewport,
		             float Width,
		             float Height,
		             float TopLeftX,
		             float TopLeftY) override;

	/**
	  * @brief      SetPrimitiveTopology function, to set primitive topology
	  * @param      PRIMITIVE_TOPOLOGY parameter one, topology to set
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetPrimitiveTopology(PRIMITIVE_TOPOLOGY Topology) override;

	/**
	  * @brief      SetDefaultRenderTarget function, to set default render taret
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void SetDefaultRenderTarget() override;

	//clear

	/**
	  * @brief      ClearRendTarView function, to clear the render target view
	  * @param      RT parameter one, a pointer of CTexture
	  * @param      Color parameter two, of for the color of back buffer
	  * @bug		   No know Bugs
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
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	void ClearDepthStencil(CTexture* RT,
		                   unsigned int ClerFlag,
		                   float Depth,
		                   unsigned int Stencil) override;

	/**
	  * @brief      ClearDefaultRenderTargetAndDepthStencil function, to
	  *             clear default render target and depth stencil
	  * @param      Color parameter two, of for the color of back buffer
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	void ClearDefaultRenderTargetAndDepthStencil(ColorStruct Color) override;


	void UpdateSubresource(const void* Data,
		                   CConstantBuffer& ConstantBufffer);

	//draw

	/**
	  * @brief      DrawModel function, to draw model
	  * @param      ShaderPro parameter one, shader program for the model
	  * @bug		No know Bugs
	  * @return     Returns nothing
	*/
	//void DrawModel(CShaderProgram& ShaderPro) override;

	/**
	  * @brief      DrawIndexed function, to draw
	  * @param      SizeIndex parameter one, num of index
	  * @param      StartindexLocation parameter two, start index location
	  * @param      BaseVertexLocation parameter two, base vertex location
	  * @bug		   No know Bugs
	  * @return     Returns nothing
	*/
	void DrawIndexed(unsigned int NumIndex,
		             unsigned int StartindexLocation,
		             unsigned int BaseVertexLocation,
		             const void* Index) override;

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
	void DrawInstanced(unsigned int VertexCountPerInstance,
		               unsigned int InstanceCount,
		               unsigned int StartVertexLocation,
		               unsigned int StartInstanceLocation) override;

	/**
	  * @brief      Draw function, to draw
	  * @param      VertexCount parameter one, Number of vertices to draw
	  * @param      StartVertexLocation parameter two, Index of the first vertex, which is
					usually an offset in a vertex buffer
	  * @bug		   No know Bugs
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

	//clear
	void Destroy() override;
};

