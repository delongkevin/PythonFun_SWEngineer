//--------------------------------------------------------------------------
/// @file ME_Window_LINUX.c
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

#include "bsp/graphics/Window.h"

#ifdef ME_PLATFORM_LINUX

namespace bsp
{

Window::Window()
  : window_t()
  , deviceContext_t()
  , context_t()
  , numOfBuffer_u8(2U)
  , xPos_u32(0U)
  , yPos_u32(0U)
  , width_u32(640U)
  , height_u32(480U)
{
  renderBuffers_apv[0] = NULL;
  renderBuffers_apv[1] = NULL;
}

Window::~Window()
{
}

bool_t Window::create_b(ScreenContext_t i_ScreenContext_t,
                        WindowUsage_e i_Usage_e,
                        uint32_t i_Width_u32, uint32_t i_Height_u32,
                        uint32_t i_Xpos_u32, uint32_t i_Ypos_u32,
                        uint8_t i_NumOfBuffer_u8)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t Window::destroy_b() const
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t Window::post_b() const
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t Window::fill_b()
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t Window::fill_b(const uint8_t* i_RgbBuff_pu8, uint32_t i_Width_u32, uint32_t i_Height_u32)
{
  bool_t v_Result_b = true;
  static_cast<void>(i_RgbBuff_pu8);
  static_cast<void>(i_Width_u32);
  static_cast<void>(i_Height_u32);

  return v_Result_b;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX
