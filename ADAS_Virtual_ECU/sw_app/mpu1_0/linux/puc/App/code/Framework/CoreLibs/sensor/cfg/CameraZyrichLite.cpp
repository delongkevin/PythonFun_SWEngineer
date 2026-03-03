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
/// @author Gangadhar Reddy Yadiki (GangadharReddy.Yadiki@Magna.com)
//  --------------------------------------------------------------------------

#include "CameraZyrichLite.h"

#include "CamTypes.h"

#ifdef ME_PLATFORM_QNX

#include <logging/Logger.h>

#include <osal/system/Time.h>

#include <bsp/io/fpga/FpgaParameters.h>
#include <bsp/io/fpga/FpgaHelper.h>

#include <platform/stdlib/utils/crc/src/crc.h>

namespace sensor
{

const uint32_t c_FlashIntrinsicAddress_u32  =    0x00050000U;
const uint32_t v_FlashProductionAddress_u32 =    0x00060000U;


CameraZyrichLite::CameraZyrichLite()
  : CameraBase()
  , initialized_b(false)
  , cameraEepromData_t()
  , fpgaCameraId_u32(0U)
  , plBaseAddress_pv(NULL)
{
}

CameraZyrichLite::~CameraZyrichLite()
{
}

// configure
bool_t CameraZyrichLite::init_b(variants::Camera_t i_CameraId_t)
{
  bool_t v_Result_b = true;
  ME_IO_MapDeviceAdress_b(bsp::c_AxiLiteBase_u32, bsp::c_AxiLiteSize_u32, &plBaseAddress_pv);

  cameraID_t = i_CameraId_t;
  fpgaCameraId_u32 = bsp::mapCameraId_u32(i_CameraId_t);

  setPowerMode_b(variants::e_CameraPowerModeOn);

  initialized_b = v_Result_b;

  return v_Result_b;
}


// open for usage
bool_t CameraZyrichLite::open_b()
{
  bool_t v_Result_b = false;
  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf,
                         "CameraZyrichLite::open_b() - Camera [%d]",
                         cameraID_t);

  if(initialized_b == true)
  {
    v_Result_b = cameraParams_o.init_b(cameraID_t);
  }

  return v_Result_b;
}


bool_t CameraZyrichLite::close_b()
{
  bool_t v_Result_b = false;

  return v_Result_b;
}

bool_t CameraZyrichLite::run_b()
{
  return true;
}

bool_t CameraZyrichLite::stop_b()
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

variants::CameraPowerMode_t CameraZyrichLite::readCameraPowerMode_t()
{
  variants::CameraPowerMode_t v_CameraPowerMode_t;

  uint32_t v_CamMask_u32 = 0x7U << (3U * fpgaCameraId_u32);
  uint32_t v_VideoInGPIO1Reg_u32 = 0x00000000U;

  ME_IO_In32_b(plBaseAddress_pv, bsp::c_VideoInGPIO1Offset_u32, &v_VideoInGPIO1Reg_u32);

  if((v_VideoInGPIO1Reg_u32 & v_CamMask_u32) == v_CamMask_u32)
  {
    v_CameraPowerMode_t = variants::e_CameraPowerModeOn;
  }
  else
  {
    v_CameraPowerMode_t = variants::e_CameraPowerModeOff;
  }

  return v_CameraPowerMode_t;
}

bool_t CameraZyrichLite::setPowerMode_b(variants::CameraPowerMode_t i_CameraPowerMode_e)
{
  bool_t v_Result_b = false;

  if(plBaseAddress_pv != NULL)
  {
    uint32_t v_CamMask_u32 = 0x7U << (3U * fpgaCameraId_u32);
    uint32_t v_VideoInGPIO1Reg_u32 = 0x00000000U;

    ME_IO_In32_b(plBaseAddress_pv, bsp::c_VideoInGPIO1Offset_u32, &v_VideoInGPIO1Reg_u32);

    if(i_CameraPowerMode_e != cameraPowerMode_t)
    {
      cameraPowerMode_t = i_CameraPowerMode_e;

      switch(cameraPowerMode_t)
      {
      case variants::e_CameraPowerModeOn:
      {
        v_VideoInGPIO1Reg_u32 |= v_CamMask_u32;
        ME_IO_Out32_b(plBaseAddress_pv, bsp::c_VideoInGPIO1Offset_u32, v_VideoInGPIO1Reg_u32);

        break;
      }
      case variants::e_CameraPowerModeOff:
      {
        v_VideoInGPIO1Reg_u32 &= ~(v_CamMask_u32);
        ME_IO_Out32_b(plBaseAddress_pv, bsp::c_VideoInGPIO1Offset_u32, v_VideoInGPIO1Reg_u32);
        break;
      }
      case variants::e_CameraPowerModeSleep:
      {
        break;
      }
      default:
      {
        break;
      }
      }

      v_Result_b = true;

      ME_Debugger_F_Printf_v("SetPowerMode: Addr 0x%x, powermode %d\n", plBaseAddress_pv, cameraPowerMode_t);
    }
    else
    {
      v_Result_b = true;
    }
  }

  return v_Result_b;
}


bool_t CameraZyrichLite::setVideoMode_b(VideoMode_e i_VideoMode_e)
{
  bool_t v_Result_b = true;

  if ( i_VideoMode_e == e_VideoModeMachineVision )
  {
  }
  else
  {
  }

  return v_Result_b;
}

bool_t CameraZyrichLite::setTestPatternMode_b(variants::CamTestPattern_t i_TestPatternMode_e)
{
  bool_t v_Result_b = false;

  if(i_TestPatternMode_e == variants::e_CamTestPatternTurnOff)
  {
    if(setPowerMode_b(variants::e_CameraPowerModeOff) == true)
    {
      cameraTestPattern_t = variants::e_CamTestPatternTurnOff;
      v_Result_b = true;
    }
  }
  else if(cameraState_e == sensor::e_CameraStateRunning)
  {
    IDevice<uint32_t>* v_Imager_po = getDevice_po(variants::e_ImagerAS0149AT);

    mutex_o.take_b();

    if(v_Imager_po->runCommand_b(i_TestPatternMode_e))
    {
      cameraTestPattern_t = i_TestPatternMode_e;
      v_Result_b = true;
    }

    mutex_o.give_v();
  }

  return v_Result_b;
}


void CameraZyrichLite::setCameraState_v(CameraState_e i_CameraState_e)
{
  cameraState_e = i_CameraState_e;

  cameraErrorData_t.PowerStatus_u8 = cameraPowerMode_t;

  switch(cameraState_e)
  {
  case e_CameraStateNotInitialized:
  {
    cameraErrorData_t.VideoLinkDetected_u8 = 0;
    cameraErrorData_t.ConfigLinkDetected_u8 = 0;
    cameraErrorData_t.RunningStatus_u8 = 0;
    break;
  }
  case e_CameraStateDisconnected:
  {
    cameraErrorData_t.VideoLinkDetected_u8 = 0;
    cameraErrorData_t.ConfigLinkDetected_u8 = 0;
    cameraErrorData_t.RunningStatus_u8 = 0;
    break;
  }
  case e_CameraStateInitialized:
  {
    cameraErrorData_t.RunningStatus_u8 = 0;
    break;
  }
  case e_CameraStateStopped:
  {
    cameraErrorData_t.RunningStatus_u8 = 0;
    break;
  }
  case e_CameraStateConnected:
  {
    cameraErrorData_t.VideoLinkDetected_u8 = 1;
    cameraErrorData_t.ConfigLinkDetected_u8 = 1;
    cameraErrorData_t.RunningStatus_u8 = 0;
    break;
  }
  case e_CameraStateRunning:
  {
    cameraErrorData_t.RunningStatus_u8 = 1;
    break;
  }
  case e_CameraStateFailure:
  {
    cameraErrorData_t.VideoLinkDetected_u8 = 0;
    cameraErrorData_t.ConfigLinkDetected_u8 = 0;
    cameraErrorData_t.RunningStatus_u8 = 0;
    break;
  }
  default:
  {
    cameraErrorData_t.VideoLinkDetected_u8 = 0;
    cameraErrorData_t.RunningStatus_u8 = 0;
    break;
  }
  }
}

bool_t CameraZyrichLite::getEepromData_b(CameraEepromData_t& o_EepromData_rt)
{
  bool_t v_Result_b = false;

  sensor::SpiFlashW25Q40& v_SpiFlashW25Q40_ro = *reinterpret_cast<sensor::SpiFlashW25Q40*>(getDevice_po(variants::e_SpiFlashW25Q40));

  memset(&cameraEepromData_t, 0xffU, sizeof(cameraEepromData_t));

  mutex_o.take_b();

  v_Result_b = v_SpiFlashW25Q40_ro.read_b(c_FlashIntrinsicAddress_u32, reinterpret_cast<uint32_t*>(&cameraEepromData_t.camCrcData_s), 132U);

  if(v_Result_b == true)
  {
    uint32_t v_CrC_u32 = crc_calculateCRC32(reinterpret_cast<uint8_t*>(&cameraEepromData_t.camIntrinsicData_s), sizeof(cameraEepromData_t.camIntrinsicData_s), CRC_INITIAL_VALUE32);

    if(v_CrC_u32 == cameraEepromData_t.camCrcData_s.crc_u32)
    {
      v_Result_b = v_SpiFlashW25Q40_ro.read_b(0x54U, reinterpret_cast<uint32_t*>(&cameraEepromData_t.camVersion_s), 16U) && v_Result_b;

      ME_Debugger_F_Printf_v("Camera [%d]: Flash read successful \n", cameraID_t);
      getCameraParams_ro().setEepromData_v(cameraEepromData_t);
      v_Result_b = getCameraParams_ro().createRealCamera_b() && v_Result_b;
    }
    else
    {
      ME_Debugger_F_Printf_v("Camera [%d]: Flash CRC incorrect\n", cameraID_t);
      v_Result_b = false;
    }
  }
  else
  {
    ME_Debugger_F_Printf_v("Camera [%d]: Flash couldn't read properly \n", cameraID_t);
  }

  mutex_o.give_v();

  return v_Result_b;
}


} // namespace sensor

#endif // ME_PLATFORM_QNX
