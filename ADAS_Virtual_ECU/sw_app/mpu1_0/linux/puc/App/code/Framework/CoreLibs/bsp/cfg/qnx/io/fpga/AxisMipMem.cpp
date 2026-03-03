//--------------------------------------------------------------------------
/// @file Cam.cpp
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

#ifdef ME_PLATFORM_QNX

#include "bsp/io/fpga/AxisMipMem.h"
#include "bsp/io/fpga/FpgaParameters.h"
#include "bsp/io/fpga/FpgaHelper.h"

namespace bsp
{


AxisMipMem::AxisMipMem()
  : axisMipMemBase_pv(NULL)
  , portsCount_u32(0U)
  , snapshotBuffersCount_u32(0U)
  , frameErrorReg_u32(0x00U)
{

}

AxisMipMem::~AxisMipMem()
{

}

bool_t AxisMipMem::initAxisMipMap_b()
{
  bool_t v_Result_b = ME_IO_MapDeviceAdress_b(c_AxisMipMemBase_u32, 0x100U, &axisMipMemBase_pv);

  if((v_Result_b == true) && (axisMipMemBase_pv != NULL))
  {
    uint32_t v_ReadVal_u32 = 0x0000000U;
    ME_IO_In32_b(axisMipMemBase_pv, 0x08U, &v_ReadVal_u32);

    snapshotBuffersCount_u32 = 2U << (v_ReadVal_u32 & 0x0000000fU);
    portsCount_u32           =      ((v_ReadVal_u32 & 0x00000070U) >> 4U) + 1U;

    v_Result_b = setCameraSelect_b(variants::e_CameraFront);

    for(uint32_t v_I_u32 = 0; v_I_u32 < e_PortCameraCount; v_I_u32++)
    {
      setPortControl_b(static_cast<Port_e>(v_I_u32), true, e_CaptureModeContinous, 0U);
    }

    //Enable interrupt
    ME_IO_Out32_b(axisMipMemBase_pv, 0x14U, 0x00ffffffU);

    ME_IO_In32_b(axisMipMemBase_pv, 0x18U, &frameErrorReg_u32);
    ME_IO_Out32_b(axisMipMemBase_pv, 0x18U, frameErrorReg_u32);
  }

  return v_Result_b;
}

bool_t AxisMipMem::snapshot_b(Port_e i_Port_e, uint8_t i_BufferIdx_u8) const
{
  bool_t v_Result_b = false;

  if(i_Port_e < portsCount_u32)
  {
    v_Result_b = setPortControl_b(i_Port_e, true, e_CaptureModeSnapshot, i_BufferIdx_u8);
  }

  return v_Result_b;
}

bool_t AxisMipMem::continous_b(Port_e i_Port_e, uint8_t i_BufferIdx_u8) const
{
  bool_t v_Result_b = false;

  if(i_Port_e < portsCount_u32)
  {
    v_Result_b = setPortControl_b(i_Port_e, true, e_CaptureModeContinous, i_BufferIdx_u8);
  }

  return v_Result_b;
}

bool_t AxisMipMem::enablePort_b(Port_e i_Port_e)
{
  uint32_t v_PortControl_u32 = 0x00U;

  ME_IO_In32_b(axisMipMemBase_pv, 0x20U + (4U * i_Port_e), &v_PortControl_u32);

  v_PortControl_u32 |= 0x0001U;

  return ME_IO_Out32_b(axisMipMemBase_pv, 0x20U + (4U * i_Port_e), v_PortControl_u32);
}

bool_t AxisMipMem::disablePort_b(Port_e i_Port_e)
{
  uint32_t v_PortControl_u32 = 0x00U;

  ME_IO_In32_b(axisMipMemBase_pv, 0x20U + (4U * i_Port_e), &v_PortControl_u32);

  v_PortControl_u32 &= ~(0x0001U);

  return ME_IO_Out32_b(axisMipMemBase_pv, 0x20U + (4U * i_Port_e), v_PortControl_u32);
}

bool_t AxisMipMem::setCameraSelect_b(variants::Camera_t i_CameraID_t) const
{
  bool_t v_Result_b = false;

  if(i_CameraID_t <= variants::e_CameraCount)
  {
    uint32_t v_CameraBits_u32 = (0x00000007U & mapCameraId_u32(i_CameraID_t));

    // currently only for underfloor port
    v_Result_b = ME_IO_Out32_b(axisMipMemBase_pv, 0x10U, v_CameraBits_u32);
  }

  return v_Result_b;
}

bool_t AxisMipMem::getFrameError_b(variants::Camera_t i_CameraID_t)
{
  uint32_t v_CamMask_u32 = (0x1U << (mapCameraId_u32(i_CameraID_t) + 17U));

  ME_IO_Out32_b(axisMipMemBase_pv, 0x18U, frameErrorReg_u32);
  ME_Thread_Sleep_t(1);
  ME_IO_In32_b(axisMipMemBase_pv, 0x18U, &frameErrorReg_u32);

  //ME_Debugger_F_Printf_v("frameErrorReg_u32: 0x%x\n", frameErrorReg_u32);

  return ((frameErrorReg_u32 & v_CamMask_u32) == v_CamMask_u32);
}

bool_t AxisMipMem::setPortControl_b(Port_e i_Port_e, bool_t i_Enable_b, CaptureMode_e i_CaptureMode_e, uint8_t i_BufferIdx_u8) const
{
  bool_t v_Result_b = false;
  uint32_t v_PortControl_u32 = 0x00U;

  if(i_Port_e < portsCount_u32)
  {
    if(i_Enable_b == true)
    {
      v_PortControl_u32 |= 0x0001U;
    }

    if(i_CaptureMode_e == e_CaptureModeSnapshot)
    {
      v_PortControl_u32 |= 0x0002U;
    }

    v_PortControl_u32 |= (i_BufferIdx_u8 << 8U);
    v_PortControl_u32 |= (            5U << 4U);  // maximum MIP-level

    v_Result_b = ME_IO_Out32_b(axisMipMemBase_pv, 0x20U + (4U * i_Port_e), v_PortControl_u32);
  }

  return v_Result_b;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX

