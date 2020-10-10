#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class CTexture;
class CBuffer;
class CPixelShader;
class CVertexShader;
class CSamplerState;
class CPixelShader;
class CVertexShader;
class CInputLayout;

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


class CGraphiAPI
{
protected:
	virtual void InitWindow(unsigned int width, unsigned int height) = 0;

	virtual void CreateDeviceandSwap() = 0;
	virtual void CreateDeferredContext() = 0;
public:
	CGraphiAPI() = default;
	virtual ~CGraphiAPI() = default;
	

	virtual void Init(unsigned int width, unsigned int height) = 0;

	//create
	
	virtual CBuffer* CreateVertexBuffer(SimpleVertex Ver[],
		                                unsigned int bindFlags) = 0;
	virtual CBuffer* CreateIndexBuffer(unsigned int Ind[],
		                               unsigned int bindFlags) = 0;
	virtual CBuffer* CreateConstantBufferNC(CBNeverChanges CBNC,
		                                    unsigned int bindFlags) = 0;
	virtual CBuffer* CreateConstantBufferCOR(CBChangeOnResize CBCR,
		                                     unsigned int bindFlags) = 0;
	virtual CBuffer* CreateConstantBufferCEF(CBChangesEveryFrame CBCEF,
		                                     unsigned int bindFlags) = 0;
	virtual void CreateTexture1D() = 0;
	virtual CTexture* CreateTexture2D(unsigned int width,
		                              unsigned int height,
		                              TEXTURE_FORMAT format = TF_R8G8B8A8_UNORM,
		                              unsigned int bindFlags = TEXTURE_BIND_SHADER_RESOURCE,
		                              TYPE_USAGE Usage = TYPE_USAGE_DEFAULT,
		                              unsigned int numberTexture = 1) = 0;
	virtual void CreateTexture3D() = 0;
	virtual CPixelShader* CreatePixelShaders(std::string FileName,
		                                    std::string Entry = "",
		                                    std::string ShaderModel = "",
		                                    int ID = 1) = 0;
	virtual	CVertexShader* CreateVertexShaders(std::string FileName,
		                             std::string Entry = "",
		                             std::string ShaderModel = "",
		                             int ID = 1) = 0;
	virtual CInputLayout* CreateInputLayout() = 0;
	virtual CSamplerState* CreateSamplerState() = 0;
	virtual void CreateRasterizerState() = 0;
	

	//set
	virtual void SetVertexBuffer(CBuffer* VerBuff,
		                         unsigned int StartSlot,
		                         unsigned int NumBuffer,
		                         unsigned int stride,
		                         unsigned int offset) = 0;
	virtual void SetIndexBuffer(CBuffer* IndBuff, 
		                        unsigned int offset) = 0;
	virtual void SetConstantBufferNC(CBuffer* ConstBuff,
		                             unsigned int StartSlot,
		                             unsigned int NumBuffer) = 0;
	virtual void SetConstantBufferCOR(CBuffer* ConstBuff,
		                              unsigned int StartSlot,
		                              unsigned int NumBuffer) = 0;
	virtual void SetConstantBufferCEF(CBuffer* ConstBuff,
		                              unsigned int StartSlot,
		                              unsigned int NumBuffer) = 0;
	virtual void SetPixelShaders(CPixelShader * Pixel) = 0;
	virtual void SetVertexShaders(CVertexShader* Vertex) = 0;
	virtual void SetInputLayout(CInputLayout* Inp) = 0;
	virtual void SetSamplerState(CSamplerState* Sam,
		                         unsigned int StartSlot,
		                         unsigned int NumSamplers) = 0;
	virtual void SetDepthStencil() = 0;
	virtual void SetRasterizerState() = 0;
	virtual void SetRenderTarget(CTexture* pRTTex, 
		                         CTexture* pDSTex = nullptr) = 0;
	virtual void SetDepthStencil() = 0;
	virtual void SetShaderResouerce(CTexture* pRTTex) = 0;

	//clear

	//draw
	virtual void Drawindex(int SizeIndex, int StartindexLocation) = 0;

	//swap
	virtual void Present() = 0;

protected:
	unsigned int m_Width = 800;
	unsigned int m_Height = 600;
};

