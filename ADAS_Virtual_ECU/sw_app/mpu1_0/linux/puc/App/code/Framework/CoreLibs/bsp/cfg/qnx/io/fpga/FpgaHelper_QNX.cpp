//--------------------------------------------------------------------------
/// @file FpgaHelper_QNX.cpp
/// @brief Implementation of QNX camera interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#include <platform/PlatformAPI.h>

#include <variants/Enums.h>

#include "bsp/io/fpga/FpgaHelper.h"

#ifdef ME_PLATFORM_QNX

namespace bsp
{

  uint32_t mapCameraId_u32(variants::Camera_t i_Camera_t)
  {
    uint32_t v_ViewGenCameraId_u32 = bsp::c_InvalidViewGenCameraId_u32;

    switch(i_Camera_t)
    {
    case variants::e_CameraFront:
      {
        v_ViewGenCameraId_u32 = 0U;
        break;
      }
    case variants::e_CameraLeft:
      {
        v_ViewGenCameraId_u32 = 1U;
        break;
      }
    case variants::e_CameraRear:
      {
        v_ViewGenCameraId_u32 = 2U;
        break;
      }
    case variants::e_CameraRight:
      {
        v_ViewGenCameraId_u32 = 3U;
        break;
      }
    case variants::e_CameraChmsl:
      {
        v_ViewGenCameraId_u32 = 4U;
        break;
      }
  #if 0
    case variants::e_CameraAux:
      {
        v_ViewGenCameraId_u32 = 5U;
        break;
      }
  #endif
    default:
    {
      break;
    }
    }

    return v_ViewGenCameraId_u32;
  }

  uint32_t mapOldCameraId_u32(variants::Camera_t i_CameraId_t)
  {
    uint32_t v_ViewGenCameraId_u32 = bsp::c_InvalidViewGenCameraId_u32;

    switch(i_CameraId_t)
    {
    case variants::e_CameraFront:
      {
        v_ViewGenCameraId_u32 = 3U;
        break;
      }
    case variants::e_CameraLeft:
      {
        v_ViewGenCameraId_u32 = 1U;
        break;
      }
    case variants::e_CameraRear:
      {
        v_ViewGenCameraId_u32 = 2U;
        break;
      }
    case variants::e_CameraRight:
      {
        v_ViewGenCameraId_u32 = 0U;
        break;
      }
    case variants::e_CameraChmsl:
      {
        v_ViewGenCameraId_u32 = 4U;
        break;
      }
  #if 0
    case variants::e_CameraAux:
      {
        v_ViewGenCameraId_u32 = 5U;
        break;
      }
  #endif
    default:
    {
      break;
    }
    }

    return v_ViewGenCameraId_u32;
  }


}

#endif // ME_PLATFORM_QNX
