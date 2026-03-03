//--------------------------------------------------------------------------
/// @file ME_Pixmap_AUTOSAR.c
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

#include "bsp/graphics/Pixmap.h"

#ifdef ME_PLATFORM_RTOS

namespace bsp
{


Pixmap::Pixmap()
  : pixmap_t()
{
}

Pixmap::~Pixmap()
{
}

sint32_t Pixmap::mapFormat_s32(PixelFormat_t i_Format_t)
{
  sint32_t v_RetFormat_s32 = -1;

  return v_RetFormat_s32;
}

PixelFormat_t Pixmap::mapFormat_t(sint32_t i_Format_s32)
{
  PixelFormat_t v_RetFormat_t = e_PixelFormatInvalid;

  return v_RetFormat_t;
}


bool_t Pixmap::create_b(ScreenContext_t i_ScreenContext_t,
                        uint32_t i_Width_u32, uint32_t i_Height_u32,
                        PixelFormat_t i_Format_e)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}


bool_t Pixmap::getPointer_b(uint8_t** o_Pointer_ppu8, uint32_t* o_Width_pu32, uint32_t* o_Height_pu32) const
{
  bool_t v_Result_b = true;

  return v_Result_b;
}



Buffer::Buffer()
  : buffer_t()
{
}

Buffer::~Buffer()
{
}

bool_t Buffer::release_b(const Buffer_t* i_Buffer_pt)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

} // namespace bsp

#endif // ME_PLATFORM_AUTOSAR


