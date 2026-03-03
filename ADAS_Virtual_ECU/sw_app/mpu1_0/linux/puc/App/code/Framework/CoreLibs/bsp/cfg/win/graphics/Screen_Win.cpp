//--------------------------------------------------------------------------
/// @file ME_Screen_WIN.c
/// @brief Interface to abstract standard-library Screen
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

#ifdef ME_PLATFORM_WIN


namespace bsp
{


Screen::Screen()
{

}

Screen::~Screen()
{

}

bool_t Screen::start_b(ScreenConfig_t i_ScreenConfig_t)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}


bool_t Screen::createContext_b()
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t Screen::destroyContext_b() const
{
  bool_t v_Result_b = true;

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
  bool_t v_Error_b = true;

  return v_Error_b;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX
