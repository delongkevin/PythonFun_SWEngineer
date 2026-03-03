#include "Common/Textures/TextureInfo.h"

#include <mecl/math/Math.h>


// PRQA S 1021 EOF // by design

namespace me3d
{
  TextureInfo::TextureInfo()
  {

  }

  TextureInfo::~TextureInfo()
  {

  }

  void TextureInfo::computeMipMapLevelCount_v(uint32_t& o_LevelCount_u32, uint32_t i_MinMipMapSize_u32, uint32_t i_Width_u32, uint32_t i_Height_u32)
  {
    if (i_MinMipMapSize_u32 == ONE_MIPMAP_LEVEL)
    {
      o_LevelCount_u32 = 1U;
    }
    else
    {
      sint32_t v_TmpMipMapSize_s32 = ((i_MinMipMapSize_u32 == ALL_MIPMAP_LEVEL) ||
                                      (i_MinMipMapSize_u32 == USE_MIPMAP_COUNT)) ? 1 : static_cast<sint32_t>(i_MinMipMapSize_u32);

      v_TmpMipMapSize_s32 = mecl::math::max_x(v_TmpMipMapSize_s32, 1);

      // compute level count, which results from the min mip map size
      uint32_t v_TexSize_u32 = mecl::math::min_x(i_Width_u32, i_Height_u32);
      
      sint32_t v_TexLevel_s32 = static_cast<sint32_t>(logf(static_cast<float32_t>(v_TexSize_u32))        / logf(2.0f));
      sint32_t v_MipLevel_s32 = static_cast<sint32_t>(logf(static_cast<float32_t>(v_TmpMipMapSize_s32))  / logf(2.0f));


      // if the mip size is greater than texture size -> only one level will be created

      uint32_t v_NumLevels_u32 = static_cast<uint32_t>(mecl::math::max_x(v_TexLevel_s32 - v_MipLevel_s32 + 1, 1));


      if ((i_MinMipMapSize_u32 == USE_MIPMAP_COUNT) && (o_LevelCount_u32 != 0U))
      {
        o_LevelCount_u32 = mecl::math::min_x(v_NumLevels_u32, o_LevelCount_u32);
      }
      else
      {
        // use the computed level count
        o_LevelCount_u32 = v_NumLevels_u32;
      }

    }


  }
} // namespace me3d