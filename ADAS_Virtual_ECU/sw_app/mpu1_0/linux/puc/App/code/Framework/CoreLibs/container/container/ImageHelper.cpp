//--------------------------------------------------------------------------
/// @file Image.cpp
/// @brief This is the short description of the template module
///
/// Here may follow a longer description for the template module with examples.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------
/// \addtogroup container
/// @{
/// \addtogroup imagehelper
/// @{
/// @brief Magna Electronics Image Library

#include "ImageHelper.h"
#include <osal/system/Time.h>
#include <logging/Logger.h>

namespace container
{
namespace imagehelper
{


// ------------------------------------------------------------------------------
// Yuv422ToGrey8_t
// Converts a YUV422 with UV interleaved image into greyscale 8-bit image
// ------------------------------------------------------------------------------
PlatformError_t Yuv422ToGrey8_t(const uint8_t* i_Yuv422_pu8, uint8_t* o_Grey8_pu8, uint32_t i_Width_u32, uint32_t i_Height_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  osal::Time v_Time_o;
  if((i_Yuv422_pu8 != NULL) && (o_Grey8_pu8 != NULL)
      && (i_Width_u32 != 0) && (i_Height_u32 != 0))
  {
    uint64_t v_T1_u64 = v_Time_o.getTimeUsec_u64();
    memcpy(o_Grey8_pu8, i_Yuv422_pu8, sizeof(uint8_t) * i_Width_u32 * i_Height_u32);
    uint64_t v_T2_u64 = v_Time_o.getTimeUsec_u64();

    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "Yuv422ToGrey8_t() - memcpy time: [%lld]", v_T2_u64 - v_T1_u64);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

// ------------------------------------------------------------------------------
// Yuv422ToRgba8888_t
// Converts a YUV422 with UV interleaved image into RGB image with alpha channel
// ------------------------------------------------------------------------------
PlatformError_t Yuv422ToRgba8888_t(const uint8_t* i_Yuv422_pu8, uint8_t* o_Rgba8888_pu8, uint32_t i_Width_u32, uint32_t i_Height_u32)
{
  PlatformError_t v_Error_t = e_PeOk;

  if((i_Yuv422_pu8 != NULL) && (o_Rgba8888_pu8 != NULL)
      && (i_Width_u32 != 0) && (i_Height_u32 != 0))
  {
    const uint32_t c_NumOfChannelRgba8888_u32 = 4;
    uint32_t v_OffsetChroma_u32 = i_Width_u32 * i_Height_u32;
    uint32_t v_StrideRgbx_u32   = c_NumOfChannelRgba8888_u32 * i_Width_u32;
    uint32_t v_StrideYuv_u32    = i_Width_u32;

    for(uint32_t v_Y_u32 = 0; v_Y_u32 < i_Height_u32; v_Y_u32++)
    {
      uint32_t _py1 = (v_Y_u32 * v_StrideRgbx_u32);
      uint32_t _py2 = (v_Y_u32 * v_StrideYuv_u32);

      for(uint32_t v_X_u32 = 0; v_X_u32 < i_Width_u32; v_X_u32++)
      {
        uint32_t _p1 = _py1 + (v_X_u32 * c_NumOfChannelRgba8888_u32);
        uint32_t _p2 = _py2 + (v_X_u32);

        float32_t Y = static_cast<float32_t>(i_Yuv422_pu8[_p2]);
        float32_t V = static_cast<float32_t>(i_Yuv422_pu8[_p2 + v_OffsetChroma_u32 - (_p2 % 2)]);
        float32_t U = static_cast<float32_t>(i_Yuv422_pu8[_p2 + v_OffsetChroma_u32 - !(_p2 % 2)]);

        // B
        float32_t B = (Y - 16.0F)                         + ( 2.018F * (V - 128.0F) );
        // G
        float32_t G = (Y - 16.0F) - ( 0.813F * (U - 128.0F) )  - ( 0.391F * (V - 128.0F) );
        // R
        float32_t R = (Y - 16.0F) + ( 1.596F * (U - 128.0F));

        o_Rgba8888_pu8[_p1]     = static_cast<uint8_t>(B); 
        o_Rgba8888_pu8[_p1 + 1] = static_cast<uint8_t>(G); 
        o_Rgba8888_pu8[_p1 + 2] = static_cast<uint8_t>(R); 
        o_Rgba8888_pu8[_p1 + 3] = 255U;
      }
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

} // namespace imagehelper
} // namespace container
