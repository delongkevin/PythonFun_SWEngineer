//--------------------------------------------------------------------------
/// @file Window.h
/// @brief Interface to abstract standard-library Thread
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

#ifndef WINDOW_H
#define WINDOW_H

#include "cfg/BspTypes.h"

#include <platform/PlatformSpecs.h>

namespace bsp
{

enum WindowUsage_e
{
  e_WindowUsageNative = 0,
  e_WindowUsageOpenGles1,
  e_WindowUsageOpenGles2,
  e_WindowUsageOpenGles3,
  e_WindowUsageCount,
  e_WindowUsageInvalid
};

class Window
{

public:

  Window();

  ~Window();

  // --------------------------------------------------------------------------
  /// Creating a window with parameters:
  /// Width, height, x- and y-position
  ///
  /// @param[in] i_Context_t
  /// @param[in]     i_Width_u32
  /// @param[in]     i_Height_u32
  /// @param[in]     i_Xpos_u32
  /// @param[in]     i_Ypos_u32
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t create_b(ScreenContext_t i_ScreenContext_t,
                  WindowUsage_e i_Usage_e,
                  uint32_t i_Width_u32, uint32_t i_Height_u32,
                  uint32_t i_Xpos_u32, uint32_t i_Ypos_u32,
                  uint8_t i_NumOfBuffer_u8);

  // --------------------------------------------------------------------------
  /// Destroys the window object
  ///
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t                    destroy_b() const;

  // --------------------------------------------------------------------------
  /// Post window
  ///
  /// @return TBD
  // --------------------------------------------------------------------------
  bool_t                    post_b() const;

  bool_t                    fill_b();

  bool_t                    fill_b(const uint8_t* i_RgbBuff_pu8, uint32_t i_Width_u32, uint32_t i_Height_u32);


  ME_INLINE void            setRenderBuffer_v(void* i_Buffer0_pv, void* i_Buffer1_pv, void* i_Buffer2_pv)
  {
    renderBuffers_apv[0] = i_Buffer0_pv;
    renderBuffers_apv[1] = i_Buffer1_pv;
    renderBuffers_apv[2] = i_Buffer2_pv;
  }

  ME_INLINE Window_t        getWindowHandle_t() const { return window_t; }
  ME_INLINE DeviceContext_t getDeviceContext_t() const { return deviceContext_t; }

private:

  void*           renderBuffers_apv[3];

  Window_t        window_t;

  DeviceContext_t deviceContext_t;

  // Necessary for QNX implementation
  ScreenContext_t context_t;

  uint8_t         numOfBuffer_u8;

  uint32_t        xPos_u32;
  uint32_t        yPos_u32;

  uint32_t        width_u32;
  uint32_t        height_u32;

  Buffer_t        windowBuffers_at[3];

};


} // namespace bsp

#endif // WINDOW_H
