//--------------------------------------------------------------------------
/// @file CameraStellanis
/// @brief Implementation of QNX camera interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
///
//  --------------------------------------------------------------------------

#include "CameraStellantis.h"

#include "CamTypes.h"

#ifdef ME_PLATFORM_QNX

#include <logging/Logger.h>

#include <osal/system/Time.h>


namespace sensor
{


CameraStellanis::CameraStellanis()
  : CameraBase()
  , initialized_b(false)
  , cameraEepromData_t()
{
}

CameraStellanis::~CameraStellanis()
{
}

// configure
bool_t CameraStellanis::init_b(variants::Camera_t i_CameraId_t)
{
  bool_t v_Result_b = true;

  cameraID_t = i_CameraId_t;

  initialized_b = v_Result_b;

  return v_Result_b;
}


// open for usage
bool_t CameraStellanis::open_b()
{
  bool_t v_Result_b = false;
  logging::Logger::log_b(logging::e_LogLvlDebug, logging::e_LogModeMaskPrintf,
                         "CameraStellanis::open_b() - Camera [%d]",
                         cameraID_t);

  if(initialized_b == true)
  {
    v_Result_b = cameraParams_o.init_b(cameraID_t);
  }

  return v_Result_b;
}


bool_t CameraStellanis::close_b()
{
  bool_t v_Result_b = false;

  return v_Result_b;
}

bool_t CameraStellanis::run_b()
{
  return true;
}

bool_t CameraStellanis::stop_b()
{
  bool_t v_Result_b = true;

  return v_Result_b;
}

variants::CameraPowerMode_t CameraStellanis::readCameraPowerMode_t()
{
  variants::CameraPowerMode_t v_CameraPowerMode_t;

  return v_CameraPowerMode_t;
}

bool_t CameraStellanis::setPowerMode_b(variants::CameraPowerMode_t i_CameraPowerMode_e)
{
  bool_t v_Result_b = true;

  return v_Result_b;
}


bool_t CameraStellanis::setVideoMode_b(VideoMode_e i_VideoMode_e)
{
  bool_t v_Result_b = true;


  return v_Result_b;
}

bool_t CameraStellanis::setTestPatternMode_b(variants::CamTestPattern_t i_TestPatternMode_e)
{
  bool_t v_Result_b = true;


  return v_Result_b;
}


void CameraStellanis::setCameraState_v(CameraState_e i_CameraState_e)
{
 
}

bool_t CameraStellanis::getEepromData_b(CameraEepromData_t& o_EepromData_rt)
{
  bool_t v_Result_b = false;

  mutex_o.take_b();


 v_Result_b = getCameraParams_ro().createRealCamera_b() && v_Result_b;


  mutex_o.give_v();

  return v_Result_b;
}


} // namespace sensor

#endif // ME_PLATFORM_QNX
