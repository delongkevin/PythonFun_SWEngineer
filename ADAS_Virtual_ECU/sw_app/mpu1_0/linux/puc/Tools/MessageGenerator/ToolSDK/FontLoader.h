#ifndef FONT_LOADER_H
#define FONT_LOADER_H

#ifdef USE_DEVIL_AND_FREETYPE

#include <string>
#include <platform/PlatformAPI.h>

#include <ft2build.h>
#include FT_FREETYPE_H

namespace tsdk
{

struct CharacterInfo_s
{
  float32_t ax_f32;	// advance.x
  float32_t ay_f32;	// advance.y

  float32_t bw_f32;	// bitmap.width;
  float32_t bh_f32;	// bitmap.height;

  float32_t bl_f32;	// bitmap_left;
  float32_t bt_f32;	// bitmap_top;

  float32_t tx_f32;	// x offset of glyph in texture coordinates
  float32_t ty_f32;	// y offset of glyph in texture coordinates

  // bitmap data
  sint32_t xOffset_s32;
  sint32_t yOffset_s32;
  sint32_t bufferWidth_s32;
  sint32_t bufferHeight_s32;
  uint8_t* buffer_pu8;

  CharacterInfo_s()
    : ax_f32(0.0F)
    , ay_f32(0.0F)
    , bw_f32(0.0F)
    , bh_f32(0.0F)
    , bl_f32(0.0F)
    , bt_f32(0.0F)
    , tx_f32(0.0F)
    , ty_f32(0.0F)
    , xOffset_s32(0)
    , yOffset_s32(0)
    , bufferWidth_s32(0)
    , bufferHeight_s32(0)
    , buffer_pu8(NULL)
  {
  }

  CharacterInfo_s(float32_t i_ax_f32, float32_t i_ay_f32, float32_t i_bw_f32, float32_t i_bh_f32, 
    float32_t i_bl_f32, float32_t i_bt_f32, float32_t i_tx_f32, float32_t i_ty_f32,
    sint32_t i_xOff_s32, sint32_t i_yOff_s32, 
    sint32_t i_BufWidth_s32, sint32_t i_Bufheight_s32,
    uint8_t* i_Buffer_pu8)
  {
    ax_f32 = i_ax_f32; ay_f32 = i_ay_f32; bw_f32 = i_bw_f32; bh_f32 = i_bh_f32;

    bl_f32 = i_bl_f32; bt_f32 = i_bt_f32; tx_f32 = i_tx_f32; ty_f32 = i_ty_f32;

    xOffset_s32 = i_xOff_s32; yOffset_s32 = i_yOff_s32; 

    bufferWidth_s32 = i_BufWidth_s32;
    bufferHeight_s32 = i_Bufheight_s32;
    buffer_pu8 = i_Buffer_pu8;
  }

};

class FontLoader
{
public:
  FontLoader();
  ~FontLoader();

  bool load_b(const std::string& i_FileName_ro);
  void export_v();

private:
  std::string fileName_o;
  uint32_t fontAtlasWidth_u32;
  uint32_t fontAtlasHeight_u32;
  static const uint32_t c_MaxCharaters_u32 = 128U;
  CharacterInfo_s charInfos_as[c_MaxCharaters_u32];
};

} // namespace tsdk

#endif

#endif
