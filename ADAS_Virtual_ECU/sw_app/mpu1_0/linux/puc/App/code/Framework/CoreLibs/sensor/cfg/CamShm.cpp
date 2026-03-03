//--------------------------------------------------------------------------
/// @file CamShm.h
/// @brief Implementation of Shared Memory camera grabber
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

#include "CamShm.h"

namespace sensor
{

  CamShm::CamShm()
    : CameraBase()
  {

  }

  CamShm::~CamShm()
  {

  }

  // configure
  bool_t CamShm::init_b(variants::Camera_t i_CameraId_t, const char_t* i_ShmName_pc)
  {
    cameraID_t = i_CameraId_t;
    cameraParams_o.init_b(cameraID_t);
    return true;
  }

  // open for usage
  bool_t CamShm::open_b()
  {
    return true;
  }

  bool_t CamShm::close_b()
  {
    bool_t v_Result_b = true;

    return v_Result_b;
  }

  bool_t CamShm::run_b()
  {
    cameraState_e = e_CameraStateRunning;
    return true;
  }

  bool_t CamShm::stop_b()
  {
	  return true;
  }

  bool_t CamShm::setPowerMode_b(variants::CameraPowerMode_e i_CameraPowerMode_e)
  {
    return true;
  }

  bool_t CamShm::setTestPatternMode_b(variants::CamTestPattern_t i_TestPatternMode_t)
  {
    return true;
  }

  bool_t CamShm::setVideoMode_b(VideoMode_e i_VideoMode_e)
  {
    return true;
  }

  void CamShm::setCameraState_v(sensor::CameraState_e i_CameraState_e)
  {

  }

  bool_t CamShm::getEepromData_b(CameraEepromData_t& o_EepromData_rt)
  {
    return true;
  }

} // namespace sensor
