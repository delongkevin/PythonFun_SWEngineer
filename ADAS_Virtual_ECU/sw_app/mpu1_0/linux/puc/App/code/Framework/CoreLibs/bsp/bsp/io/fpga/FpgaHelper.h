//--------------------------------------------------------------------------
/// @file FpgaHelper.h
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

#ifndef FPGA_HELPER_H_
#define FPGA_HELPER_H_

#include <platform/PlatformAPI.h>

// TODO: Remove variants from CMAKE
#include <variants/Enums.h>

namespace bsp
{

  const uint32_t     c_InvalidViewGenCameraId_u32 = 0xffffffffU;
  
  uint32_t           mapCameraId_u32(variants::Camera_t i_Camera_t);
  
  uint32_t           mapOldCameraId_u32(variants::Camera_t i_CameraId_t);

} // namepsace bsp

#endif // FPGA_HELPER_H_
