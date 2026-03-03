//--------------------------------------------------------------------------
/// @file ME_Screen.h
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

#ifndef SCREEN_H
#define SCREEN_H

#include <platform/PlatformSpecs.h>

#include "cfg/BspTypes.h"


namespace bsp
{

typedef struct ScreenConfig_s
{
  uint32_t width_u32;
  uint32_t height_u32;
  uint32_t fps_u32;
  char_t*  configFile_ac[ME_MAX_PATH_LENGTH];
} ScreenConfig_t;


class Screen
{
public:

  Screen();

  ~Screen();

  // --------------------------------------------------------------------------
  /// Starts the screen service application
  ///
  /// @param[in] i_ScreenConfig_t
  /// @return bool_t
  // --------------------------------------------------------------------------
  static bool_t start_b(ScreenConfig_t i_ScreenConfig_t);

  // --------------------------------------------------------------------------
  /// Creates a screen context within the screen service application
  ///
  /// @param[in/out] b_ScreenContext_pt
  /// @return bool_t
  // --------------------------------------------------------------------------
  bool_t createContext_b();

  // --------------------------------------------------------------------------
  /// Destroys the given screen context object
  ///
  /// @param[in] i_ScreenContext_pt
  /// @return PlatformError_t
  // --------------------------------------------------------------------------
  bool_t destroyContext_b() const;


  ScreenContext_t getContext_t() const;


private:

  ScreenContext_t screenContext_t;

};

class Event
{

  Event();

  ~Event();

  // --------------------------------------------------------------------------
  /// Creates an event
  ///
  /// @param[in/out] b_ScreenEvent_pt);
  /// @return PlatformError_t
  // --------------------------------------------------------------------------
 bool_t create_b(Event_t* b_ScreenEvent_pt) const;

};

}

#endif // SCREEN_H
