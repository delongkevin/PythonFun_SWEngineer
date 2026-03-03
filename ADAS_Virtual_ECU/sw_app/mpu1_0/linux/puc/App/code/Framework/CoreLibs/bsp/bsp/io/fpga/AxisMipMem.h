//--------------------------------------------------------------------------
/// @file AxisMipMem.cpp
/// @brief Implementation of QNX Axis Mip Mem interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef AXIS_MIP_MEM_H_
#define AXIS_MIP_MEM_H_

#include <platform/PlatformAPI.h>

#include <variants/Enums.h>

#include "bsp/io/fpga/FpgaHelper.h"

namespace bsp
{

enum CaptureMode_e
{
  e_CaptureModeSnapshot,
  e_CaptureModeContinous,
  e_CaptureModeCound,
  e_CaptureModeInvalid
};

typedef enum Port_e
{
  e_PortCameraFront      = 0,
  e_PortCameraLeft       = 1,
  e_PortCameraRear       = 2,
  e_PortCameraRight      = 3,
  e_PortCameraChmsl      = 4,
  e_PortCameraUnused     = 5,
  e_PortCameraUnderfloor = 6,
  e_PortCameraCount      = 7,
  e_PortCameraInvalid    = 8
} Port_t;

class AxisMipMem
{
public:

  static uint32_t getCameraId_u32(variants::Camera_t i_CameraId_t);

public:

  AxisMipMem();

  ~AxisMipMem();

public:

  bool_t                  initAxisMipMap_b();

  bool_t                  snapshot_b(Port_e i_Port_e, uint8_t i_BufferIdx_u8) const;

  bool_t                  continous_b(Port_e i_Port_e, uint8_t i_BufferIdx_u8) const;

  bool_t                  enablePort_b(Port_e i_Port_e);

  bool_t                  disablePort_b(Port_e i_Port_e);

public:

  bool_t                  setCameraSelect_b(variants::Camera_t i_CameraID_t) const;

  bool_t                  getFrameError_b(variants::Camera_t i_CameraID_t);

private:

  bool_t                  setPortControl_b(Port_e i_Port_e, bool_t i_Enable_b, CaptureMode_e i_CaptureMode_e, uint8_t i_BufferIdx_u8) const;

private:

  void*                   axisMipMemBase_pv;

  uint8_t                 portsCount_u32;

  uint8_t                 snapshotBuffersCount_u32;

  uint32_t                frameErrorReg_u32;

};


} // namespace bsp

#endif // AXIS_MIP_MEM_H_
