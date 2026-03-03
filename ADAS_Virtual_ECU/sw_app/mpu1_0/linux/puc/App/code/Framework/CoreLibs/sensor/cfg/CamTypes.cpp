//--------------------------------------------------------------------------
/// @file CamTypes.cpp
/// @brief 
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

#include "CamTypes.h"

namespace sensor
{

uint32_t mapCameraIds_u32(variants::Camera_t i_CameraId_t)
{
  uint32_t v_CameraId_u32 = variants::e_CameraInvalid;
  switch (i_CameraId_t)
  {
  case variants::e_CameraFront    : { v_CameraId_u32 = variants::e_CameraRear;    } break;
  case variants::e_CameraLeft     : { v_CameraId_u32 = variants::e_CameraRight;   } break;
  case variants::e_CameraRear     : { v_CameraId_u32 = variants::e_CameraLeft;    } break;
  case variants::e_CameraRight    : { v_CameraId_u32 = variants::e_CameraFront;   } break;
  default:
  {
    ME_Debugger_F_Printf_v("FALSCH!!!!\n");
    break;
  }
  }

  return v_CameraId_u32;
}


} // namespace sensor
