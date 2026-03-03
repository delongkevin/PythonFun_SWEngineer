#include "Texture.h"

#include <string.h>

namespace me3d
{

Texture::Texture()
  : ITextureConstantData()
  , renderEngine_po(NULL)
  , desc_s()
{
}

Texture::~Texture()
{
  // PRQA S 4261 2 // This function doesn't throw exceptions
  // PRQA S 4631 1 // This function doesn't throw exceptions
  release_v();
}

bool Texture::create_b(RenderEngine* i_RenEng_po, const TextureDesc_s& i_Desc_rs, const uint8_t* i_InitialData_pu8)
{
  renderEngine_po = i_RenEng_po;
  desc_s          = i_Desc_rs;

  Assert(desc_s.type_e   != e_TtUnknown      );
  Assert(desc_s.type_e   != e_Tt2DMultisample); // not a valid type for textures, just for render targets!
  Assert(desc_s.format_e != mepl::e_RfUnknown);

  return true;
}

void Texture::release_v()
{
  desc_s.fileName_o = "";
}

me3d::TextureType_e Texture::getTextureType_e() const
{
  return desc_s.type_e;
}

me3d::TextureConstantDataType_e Texture::getDataType_e() const
{
  return e_TcdtTexture;
}

uint32_t Texture::getWidth_u32() const
{
  return desc_s.width_u32;
}

uint32_t Texture::getHeight_u32() const
{
  return desc_s.height_u32;
}

const MEString& Texture::getFilename_ro() const
{
  return desc_s.fileName_o;
}

bool Texture::hasAlpha_b() const
{
  return desc_s.format_e == mepl::e_RfR8G8B8A8;
}

const TextureDesc_s& Texture::getDesc_rs() const
{
  return desc_s;
}

uint32_t Texture::getImageSize_u32(uint32_t i_Width_u32, uint32_t i_Height_u32, uint32_t i_Depth_u32, mepl::PixelFormat_e i_Format_e)
{
  using namespace mepl;

  uint32_t v_Size_u32 = 0U;

  switch (i_Format_e)
  {
  case e_RfR8G8B8:
  case e_RfR8G8B8A8:
  case e_RfR8:
  case e_RfR16F:
    {
      uint32_t v_Channels_u32 = 1U;

      if (i_Format_e == e_RfR16F)
      {
        v_Channels_u32 = 2U;
      }
      else if (i_Format_e == e_RfR8G8B8)
      {
        v_Channels_u32 = 3U;
      }
      else if (i_Format_e == e_RfR8G8B8A8)
      {
        v_Channels_u32 = 4U;
      }
	  else
	  {
		  //Do nothing
	  }
      
      if (i_Depth_u32 > 1U)
      {
        v_Size_u32 = i_Width_u32 * i_Height_u32 * i_Depth_u32 * v_Channels_u32;
      }
      else
      {
        v_Size_u32 = i_Width_u32 * i_Height_u32 * v_Channels_u32;
      }

      break;
    }
  case e_RfEtc1:
    {
      uint32_t v_BytesPerBlock_u32 = 8U;

      if (i_Depth_u32 > 1U)
      {
        v_Size_u32 = static_cast<uint32_t>(ceilf(static_cast<float32_t>(i_Width_u32) / 4.0F) *
			ceilf(static_cast<float32_t>(i_Height_u32) / 4.0F) * ceilf(static_cast<float32_t>(i_Depth_u32) / 4.0F) * static_cast<float32_t>(v_BytesPerBlock_u32));
      }
      else
      {
        v_Size_u32 = static_cast<uint32_t>(ceilf(static_cast<float32_t>(i_Width_u32) / 4.0F) *
			ceilf(static_cast<float32_t>(i_Height_u32) / 4.0F) * static_cast<float32_t>(v_BytesPerBlock_u32));
      }

      break;
    }
  case e_RfUnknown: // fall through
  default:
	  {
		Assert(false);
		break;
	  }
    
  }

  return v_Size_u32;
}

} // namespace me3d