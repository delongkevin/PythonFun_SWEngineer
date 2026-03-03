//--------------------------------------------------------------------------
/// @file ME_Window_QNX.c
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

#ifdef ME_PLATFORM_QNX

#include <sys/mman.h>

namespace bsp
{

const uint8_t c_ZynqGpuByteStrideGranularity_u8 = 8U;
const uint8_t c_ZynqGpuHeightGranularity_u8     = 1U;

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
  renderBuffers_apv[2] = NULL;
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

  sint32_t v_Result_s32 = -1;

  if((i_Width_u32 > 0U) && (i_Height_u32 > 0U)
  && (i_Xpos_u32 >= 0U) && (i_Ypos_u32 >= 0U)
  && (i_Usage_e == e_WindowUsageOpenGles2)
  && (i_NumOfBuffer_u8 > 0))
  {
    void* v_MappedAdress_pv = NULL;

    sint32_t v_Usage_s32        = SCREEN_USAGE_OPENGL_ES2 | SCREEN_USAGE_READ | SCREEN_USAGE_WRITE | SCREEN_USAGE_DISPLAY; // PRQA S 3710 // bitwise or is necessary here, defined by QNX
    sint32_t v_Transparency_s32 = SCREEN_TRANSPARENCY_NONE;
    sint32_t v_ZOrder_s32       = 10;
    sint32_t v_Size_as32[2]     = { static_cast<sint32_t>(i_Width_u32), static_cast<sint32_t>(i_Height_u32) };   /* size of the window on screen */
    sint32_t v_Position_as32[2] = { static_cast<sint32_t>(i_Xpos_u32), static_cast<sint32_t>(i_Ypos_u32)    };                         /* position of the window on screen */
    sint32_t v_Format_s32       = SCREEN_FORMAT_RGBA8888;           /* pixel v_Format_s32 for our window and pixmap */
    sint32_t v_Interval_s32     = 0;                                /* swap interval */
    sint32_t v_NumOfBuffer_s32  = i_NumOfBuffer_u8;                 /* number of buffers (1 or 2) */


    width_u32 = i_Width_u32;
    height_u32 = i_Height_u32;


    v_Result_s32 = screen_create_window(&window_t, i_ScreenContext_t);
    if (v_Result_s32 != 0)
    {
      ME_Debugger_F_Printf_v("screen_create_window");
    }

    v_Result_s32 = screen_set_window_property_iv(window_t, SCREEN_PROPERTY_ZORDER, &v_ZOrder_s32);
    if (v_Result_s32 != 0)
    {
      ME_Debugger_F_Printf_v("screen_set_window_property_iv(SCREEN_PROPERTY_ZORDER)");
    }

    v_Result_s32 = screen_set_window_property_iv(window_t, SCREEN_PROPERTY_FORMAT, &v_Format_s32);
    if (v_Result_s32 != 0)
    {
      ME_Debugger_F_Printf_v("screen_set_window_property_iv(SCREEN_PROPERTY_FORMAT)");
    }

    v_Result_s32 = screen_set_window_property_iv(window_t, SCREEN_PROPERTY_USAGE, &v_Usage_s32);
    if (v_Result_s32 != 0)
    {
      ME_Debugger_F_Printf_v("screen_set_window_property_iv");
    }

    if ((v_Size_as32[0] > 0) && (v_Size_as32[1] > 0))
    {
      v_Result_s32 = screen_set_window_property_iv(window_t, SCREEN_PROPERTY_SIZE, &v_Size_as32[0]);
      if (v_Result_s32 != 0) {
        ME_Debugger_F_Printf_v("screen_set_window_property_iv(SCREEN_PROPERTY_SIZE)");
      }
    }
    else
    {
      v_Result_s32 = screen_get_window_property_iv(window_t, SCREEN_PROPERTY_SIZE, &v_Size_as32[0]);
      if (v_Result_s32 != 0)
      {
        ME_Debugger_F_Printf_v("screen_get_window_property_iv(SCREEN_PROPERTY_SIZE)");
      }
    }

    sint32_t v_AllocationSize_as32[2] = { -1, -1 };

    v_AllocationSize_as32[0] = v_Size_as32[0];
    sint32_t v_Stride_s32    = (v_AllocationSize_as32[0] * 4 + (c_ZynqGpuByteStrideGranularity_u8-1)) & ~(c_ZynqGpuByteStrideGranularity_u8-1);
    v_AllocationSize_as32[1] = (v_Size_as32[1] + (c_ZynqGpuHeightGranularity_u8-1)) & ~(c_ZynqGpuHeightGranularity_u8-1);

    v_Result_s32 = screen_set_window_property_iv(window_t, SCREEN_PROPERTY_SIZE, &v_AllocationSize_as32[0]); //ZYNQ
    if (v_Result_s32 != 0)
    {
      ME_Debugger_F_Printf_v("screen_set_window_property_iv(SCREEN_PROPERTY_SIZE)");
    }

    if((v_Position_as32[0] != 0) || (v_Position_as32[1] != 0))
    {
      v_Result_s32 = screen_set_window_property_iv(window_t, SCREEN_PROPERTY_POSITION, &v_Position_as32[0]);
      if (v_Result_s32 != 0) {
        ME_Debugger_F_Printf_v("screen_set_window_property_iv(SCREEN_PROPERTY_POSITION)");
      }
    }

    v_Result_s32 = screen_set_window_property_iv(window_t, SCREEN_PROPERTY_TRANSPARENCY, &v_Transparency_s32);
    if (v_Result_s32 != 0) {
      ME_Debugger_F_Printf_v("screen_set_window_property_iv(SCREEN_PROPERTY_TRANSPARENCY)");
    }

    v_Result_s32 = screen_set_window_property_iv(window_t, SCREEN_PROPERTY_SWAP_INTERVAL, &v_Interval_s32);
    if (v_Result_s32 != 0) {
      ME_Debugger_F_Printf_v("screen_set_window_property_iv(SCREEN_PROPERTY_SWAP_INTERVAL)");
    }

    // Set ID string for debugging via /dev/screen.
#if 0
    const char_t* v_IdString_pc = "gles2-vsync-maze";
    screen_set_window_property_cv(window_t, SCREEN_PROPERTY_ID_STRING, strlen(v_IdString_pc), v_IdString_pc);
#endif

    sint32_t v_BufferSize_s32 = (v_Stride_s32 * v_AllocationSize_as32[1] + __PAGESIZE - 1) & ~(__PAGESIZE - 1); // PRQA S 3003 // Calculation for buffer size was provided by QNX

    for (uint32_t v_I_u32 = 0; v_I_u32 < v_NumOfBuffer_s32; v_I_u32++)
    {
      v_Result_s32 = screen_create_buffer(&windowBuffers_at[v_I_u32]);
      if (v_Result_s32 != 0)
      {
        ME_Debugger_F_Printf_v("screen_create_buffer");
      }

      v_Result_s32 = screen_set_buffer_property_iv(windowBuffers_at[v_I_u32], SCREEN_PROPERTY_SIZE, &v_BufferSize_s32);
      if (v_Result_s32 != 0)
      {
        ME_Debugger_F_Printf_v("screen_set_buffer_property_iv(SCREEN_PROPERTY_SIZE)");
      }

      v_Result_s32 = screen_set_buffer_property_iv(windowBuffers_at[v_I_u32], SCREEN_PROPERTY_BUFFER_SIZE, &v_Size_as32[0]);
      if (v_Result_s32 != 0)
      {
        ME_Debugger_F_Printf_v("screen_set_buffer_property_iv(SCREEN_PROPERTY_BUFFER_SIZE)");
      }

      v_Result_s32 = screen_set_buffer_property_iv(windowBuffers_at[v_I_u32], SCREEN_PROPERTY_STRIDE, &v_Stride_s32);
      if (v_Result_s32 != 0)
      {
        ME_Debugger_F_Printf_v("screen_set_buffer_property_iv(SCREEN_PROPERTY_STRIDE)");
      }

      v_Result_s32 = screen_set_buffer_property_iv(windowBuffers_at[v_I_u32], SCREEN_PROPERTY_FORMAT, &v_Format_s32);
      if (v_Result_s32 != 0)
      {
        ME_Debugger_F_Printf_v("screen_set_buffer_property_iv(SCREEN_PROPERTY_FORMAT)");
      }

      v_Result_s32 = screen_set_buffer_property_pv(windowBuffers_at[v_I_u32], SCREEN_PROPERTY_POINTER, &renderBuffers_apv[v_I_u32]);
      if (v_Result_s32 != 0)
      {
        ME_Debugger_F_Printf_v("Address: 0x%p\n", v_MappedAdress_pv);
        ME_Debugger_F_Printf_v("screen_set_buffer_property_pv(SCREEN_PROPERTY_POINTER)");
      }
    }

    v_Result_s32 = screen_attach_window_buffers(window_t, v_NumOfBuffer_s32, &windowBuffers_at[0]);
    if (v_Result_s32 != 0)
    {
      ME_Debugger_F_Printf_v("screen_attach_pixmap_buffer");
    }

    v_Result_s32 = screen_flush_context(i_ScreenContext_t, SCREEN_WAIT_IDLE);
    if (v_Result_s32 != 0)
    {
      ME_Debugger_F_Printf_v("screen_flush_context");
    }
  }

  return (v_Result_s32 == 0);
}

bool_t Window::destroy_b() const
{
  /* DD-ID: {8FFAC950-21A0-4983-8CCD-125A4883C803}*/
  bool_t v_Result_b = false;

  sint32_t v_Result_s32 = screen_destroy_window(window_t);

  if(v_Result_s32 == EOK)
  {
    v_Result_b = true;
  }

  return v_Result_b;
}

bool_t Window::post_b() const
{
  /* DD-ID: {E72C7CC8-55F6-437a-9DD2-2EBEFB673554}*/
  bool_t v_Result_b = true;

  return v_Result_b;
}

bool_t Window::fill_b()
{
  /* DD-ID: {C1C4E2E4-89F0-4c94-9386-0FD18648EF79}*/
  post_b();
  return true;
}

bool_t Window::fill_b(const uint8_t* i_RgbBuff_pu8, uint32_t i_Width_u32, uint32_t i_Height_u32)
{
  /* DD-ID: {C1C4E2E4-89F0-4c94-9386-0FD18648EF79}*/
  bool_t v_Result_b = true;

  static_cast<void>(i_RgbBuff_pu8);
  static_cast<void>(i_Width_u32);
  static_cast<void>(i_Height_u32);

  return v_Result_b;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX
