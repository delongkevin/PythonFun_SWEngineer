//--------------------------------------------------------------------------                                                                                                           
/// @file Window.h                                                                         
/// @brief Windows window class
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef WINDOW_H
#define WINDOW_H

#ifdef _WINDOWS

#include <platform/PlatformAPI.h>

#include "MeclCfg.h"

namespace me3d
{

struct WindowDesc_s
{
  sint32_t posX_s32;
  sint32_t posY_s32;
  uint32_t screenWidth_u32;
  uint32_t screenHeight_u32;

  WindowDesc_s()
    : posX_s32(0)
    , posY_s32(0)
    , screenWidth_u32(800U)
    , screenHeight_u32(600U)
  {}
};

class Window
{

public:
  Window();
  ~Window();

  bool create_b(const WindowDesc_s& i_Desc_rs);
  void release_v();

  void messageLoop_v();

  void* getWindowHandle_pv() const;
  void* getDeviceHandle_pv() const;
  
  void setShutDown_v();
  bool shutDown_b() const;

  void onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);

  uint32_t getWidth_u32() const;
  uint32_t getHeight_u32() const;

private:
  bool          close_b;

  HWND				  hWnd; 
  HDC					  hDc;

  WindowDesc_s  windowDesc_s;
};

extern Window* g_Window_po;

} // namespace me3d


#endif // _WINDOWS


#endif
