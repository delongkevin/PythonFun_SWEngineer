//--------------------------------------------------------------------------
/// @file CamBase.h
/// @brief Defines a general interface implementation for cameras
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

// PRQA S 3054 EOF // bool_t ensures correctness
// PRQA S 3709 EOF // &= makes code more readable.
// PRQA S 3003 EOF // &= makes code more readable.

#include "CameraBase.h"

namespace sensor
{


  /// CamBase

  CameraBase::CameraBase()
      : SensorBase()
      , mutex_o()
      , cameraID_t(variants::e_CameraInvalid)
      , cameraErrorData_t()
      , cameraPowerMode_t(variants::e_CameraPowerModeOff)
      , cameraTestPattern_t(variants::e_CamTestPatternNone)
      , cameraState_e(e_CameraStateNotInitialized)
      , cameraParams_o()
      , isp_po(NULL)
  {
    for(uint32_t v_I_u32 = 0; v_I_u32 < variants::e_CameraDeviceCount; v_I_u32++)
    {
      deviceList_ao[v_I_u32] = NULL;
    }
  }

  CameraBase::~CameraBase()
  {

  }

  IspBase* CameraBase::getIsp_po()const
  {
    Assert(isp_po != NULL);
    return isp_po;
  }

  IDevice<uint32_t>* CameraBase::getDevice_po(variants::CameraDevice_t i_Device_e)
  {
    IDevice<uint32_t>* v_Result_po = NULL;

    mutex_o.take_b();

    if(i_Device_e < variants::e_CameraDeviceCount)
    {
      v_Result_po = deviceList_ao[i_Device_e];
    }

    mutex_o.give_v();

    return v_Result_po;
  }

  bool_t CameraBase::setDevice_b(variants::CameraDevice_t i_Device_t, IDevice<uint32_t>& i_Device_ro)
  {
    bool_t v_Result_b = false;

    mutex_o.take_b();

    if(i_Device_t < variants::e_CameraDeviceCount)
    {
      deviceList_ao[i_Device_t] = &i_Device_ro;
      v_Result_b = true;
    }

    mutex_o.give_v();

    return v_Result_b;
  }

  variants::Camera_t CameraBase::getCameraId_t() const
  {
    return cameraID_t;
  }

  variants::CameraPowerMode_t CameraBase::getCameraPowerMode_t() const
  {
    return cameraPowerMode_t;
  }

  variants::CamTestPattern_t CameraBase::getCameraTestPatternMode_t() const
  {
    return cameraTestPattern_t;
  }

  const CameraErrorData_t& CameraBase::getCameraErrorData_rt() const
  {
    return cameraErrorData_t;
  }

  CameraState_e CameraBase::getCameraState_e() const
  {
    return cameraState_e;
  }

  CameraParams& CameraBase::getCameraParams_ro()
  {
    return cameraParams_o;
  }

} // namespace sensor
