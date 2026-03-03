//--------------------------------------------------------------------------                                                                                                           
/// @file FontTypes.h                                                                         
/// @brief Types used by Font class
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef FONT_TYPES_H
#define FONT_TYPES_H

#include <platform/PlatformAPI.h>

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{

struct CharacterInfo_s
{
  float32_t ax_f32;	// advance x
  float32_t ay_f32;	// advance y

  float32_t bw_f32;	// bitmap width
  float32_t bh_f32;	// bitmap height

  float32_t bl_f32;	// bitmap left
  float32_t bt_f32;	// bitmap top

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

  CharacterInfo_s(float32_t i_Ax_f32, float32_t i_Ay_f32, float32_t i_Bw_f32, float32_t i_Bh_f32, 
                  float32_t i_Bl_f32, float32_t i_Bt_f32, float32_t i_Tx_f32, float32_t i_Ty_f32,
                  sint32_t i_Xoff_s32, sint32_t i_Yoff_s32, 
                  sint32_t i_BufWidth_s32, sint32_t i_Bufheight_s32,
                  uint8_t* b_Buffer_pu8)
    : ax_f32(i_Ax_f32)
    , ay_f32(i_Ay_f32)
    , bw_f32(i_Bw_f32)
    , bh_f32(i_Bh_f32)
    , bl_f32(i_Bl_f32)
    , bt_f32(i_Bt_f32)
    , tx_f32(i_Tx_f32)
    , ty_f32(i_Ty_f32)
    , xOffset_s32(i_Xoff_s32)
    , yOffset_s32(i_Yoff_s32)
    , bufferWidth_s32(i_BufWidth_s32)
    , bufferHeight_s32(i_Bufheight_s32)
    , buffer_pu8(b_Buffer_pu8)
  {
  }
};

struct FontData_s
{
  CharacterInfo_s* charInfos_ps;
  uint32_t         numCharacters_u32;
  uint32_t         width_u32;
  uint32_t         height_u32;

  FontData_s()
    : charInfos_ps(NULL)
    , numCharacters_u32(0U)
    , width_u32(0U)
    , height_u32(0U)
  {
  }
};

} // namespace me3d

#endif
