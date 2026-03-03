//--------------------------------------------------------------------------
/// @file ME_Screen_QNX.c
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

#include "bsp/graphics/Screen.h"
#include "platform/stdlib/ME_Assert.h"
#include "platform/stdlib/ME_Thread.h"

#ifdef ME_PLATFORM_QNX

namespace bsp
{


Screen::Screen()
  : screenContext_t()
{

}

Screen::~Screen()
{

}

bool_t Screen::start_b(ScreenConfig_t i_ScreenConfig_t)
{
  bool_t v_Result_b = false;
  ScreenContext_t v_ScreenContext_t;
  sint32_t v_Error_s32 = screen_create_context(&v_ScreenContext_t, SCREEN_BUFFER_PROVIDER_CONTEXT | SCREEN_APPLICATION_CONTEXT);

  if(v_Error_s32 != EOK)
  {
    // PRQA S 0310 1 // Casting char_t array to const char_t* should be OK
    FILE* v_ReturnVal_pt = popen(reinterpret_cast<const char_t*>(i_ScreenConfig_t.configFile_ac), "rw");

    if(NULL == v_ReturnVal_pt)
    {
      v_Error_s32 = EINVAL;
    }
    else
    {
      while(EOK != v_Error_s32)
      {
        v_Error_s32 = screen_create_context(&v_ScreenContext_t, SCREEN_APPLICATION_CONTEXT);
      }
    }
  }
  else
  {
    v_Error_s32 = screen_create_context(&v_ScreenContext_t, SCREEN_APPLICATION_CONTEXT);
  }

  if(v_Error_s32 == EOK)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}


bool_t Screen::createContext_b()
{
  bool_t v_Result_b = false;
  sint32_t v_Result_s32 = EINVAL;

  v_Result_s32 = screen_create_context(&screenContext_t, SCREEN_APPLICATION_CONTEXT | SCREEN_BUFFER_PROVIDER_CONTEXT);

  if(v_Result_s32 == EOK)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

bool_t Screen::destroyContext_b() const
{
  bool_t v_Result_b = false;
  sint32_t v_Result_s32 = EINVAL;

  v_Result_s32 = screen_destroy_context(screenContext_t);

  if(v_Result_s32 == EOK)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

ScreenContext_t Screen::getContext_t() const
{
  return screenContext_t;
}




Event::Event()
{
}

Event::~Event()
{
}


bool_t Event::create_b(Event_t* b_ScreenEvent_pt) const
{
  bool_t v_Error_b = false;

  if(EOK == screen_create_event(b_ScreenEvent_pt))
  {
    v_Error_b = true;;
  }

  return v_Error_b;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX
