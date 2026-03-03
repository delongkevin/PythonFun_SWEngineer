//--------------------------------------------------------------------------
/// @file ME_Pixmap_QNX.c
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

#ifdef ME_PLATFORM_QNX

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

  switch(i_Format_t)
  {
  case e_RGB888:
  {
    v_RetFormat_s32 = SCREEN_FORMAT_RGB888;
    break;
  }
  case e_RGBA8888:
  {
    v_RetFormat_s32 = SCREEN_FORMAT_RGBX8888;
    break;
  }
  case e_Grey8:
  {
    v_RetFormat_s32 = SCREEN_FORMAT_BYTE;
    break;
  }
  default:
  {
    break;
  }
  }

  return v_RetFormat_s32;
}

PixelFormat_t Pixmap::mapFormat_t(sint32_t i_Format_s32)
{
  PixelFormat_t v_RetFormat_t = e_PixelFormatInvalid;

  switch(i_Format_s32)
  {
  case SCREEN_FORMAT_RGB888:
  {
    v_RetFormat_t = e_RGB888;
    break;
  }
  case SCREEN_FORMAT_RGBX8888:
  {
    v_RetFormat_t = e_RGBA8888;
    break;
  }
  case SCREEN_FORMAT_BYTE:
  {
    v_RetFormat_t = e_Grey8;
    break;
  }
  default:
  {
    break;
  }
  }

  return v_RetFormat_t;
}


bool_t Pixmap::create_b(ScreenContext_t i_ScreenContext_t,
                        uint32_t i_Width_u32, uint32_t i_Height_u32,
                        PixelFormat_t i_Format_e)
{
  bool_t v_Result_b = false;
  sint32_t v_Result_s32 = EINVAL;
  sint32_t v_Size_as32[2];
  v_Size_as32[0] = static_cast<sint32_t>(i_Width_u32);
  v_Size_as32[1] = static_cast<sint32_t>(i_Height_u32);


  if(pixmap_t != NULL)
  {
    v_Result_s32 = screen_create_pixmap(&pixmap_t, i_ScreenContext_t);
  }

  if(EOK == v_Result_s32)
  {
    sint32_t v_Format_s32 = mapFormat_s32(i_Format_e);
    v_Result_s32 = screen_set_pixmap_property_iv(pixmap_t, SCREEN_PROPERTY_FORMAT, &v_Format_s32);
  }

  if(EOK == v_Result_s32)
  {
    const sint32_t v_Usage_s32 = (SCREEN_USAGE_WRITE | SCREEN_USAGE_NATIVE); // PRQA S 3710 // QNX function needs it like that
    v_Result_s32 = screen_set_pixmap_property_iv(pixmap_t, SCREEN_PROPERTY_USAGE, &v_Usage_s32);
  }

  if(EOK == v_Result_s32)
  {
    v_Result_s32 = screen_set_pixmap_property_iv(pixmap_t, SCREEN_PROPERTY_BUFFER_SIZE, &v_Size_as32[0]);
  }

  if(EOK == v_Result_s32)
  {
    v_Result_s32 = screen_create_pixmap_buffer(pixmap_t);
  }

  if(EOK == v_Result_s32)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}


bool_t Pixmap::getPointer_b(uint8_t** o_Pointer_ppu8, uint32_t* o_Width_pu32, uint32_t* o_Height_pu32) const
{
  bool_t v_Result_b = false;
  sint32_t v_Result_s32 = EINVAL;
  screen_buffer_t v_Buffer_t = 0;

  if(pixmap_t != NULL)
  {
    // PRQA S 0310 1 // Screen API requires cast to void**
    v_Result_s32 = screen_get_pixmap_property_pv(pixmap_t, SCREEN_PROPERTY_RENDER_BUFFERS, reinterpret_cast<void**>(&v_Buffer_t));
  }

  if(EOK == v_Result_s32)
  {
    // PRQA S 0310 1 // Screen API requires cast to void**
    v_Result_s32 = screen_get_buffer_property_pv(v_Buffer_t, SCREEN_PROPERTY_POINTER, reinterpret_cast<void**>(o_Pointer_ppu8));
  }

  if((EOK == v_Result_s32))
  {
    sint32_t v_Size_as32[2] = {0, 0};
    v_Result_s32 = screen_set_pixmap_property_iv(pixmap_t, SCREEN_PROPERTY_BUFFER_SIZE, &v_Size_as32[0]);

    if(o_Width_pu32 != NULL)
    {
      *o_Width_pu32 = static_cast<uint32_t>(v_Size_as32[0]);
    }

    if(o_Height_pu32 != NULL)
    {
      *o_Height_pu32 = static_cast<uint32_t>(v_Size_as32[1]);
    }
  }

  if(EOK == v_Result_s32)
  {
    v_Result_b = true;
  }

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
  bool_t v_Result_b = false;
  sint32_t v_Result_s32 = EINVAL;

  if(i_Buffer_pt != NULL)
  {
    v_Result_s32 = screen_release_buffer(*i_Buffer_pt);
  }

  if(EOK == v_Result_s32)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX


