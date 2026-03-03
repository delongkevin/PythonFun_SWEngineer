//--------------------------------------------------------------------------
/// @file RecCalDataProvider_Def.h
/// @brief Contains
///
///
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Anand Kavrady (Ananda.Kavrady@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef SIGM_RECEIVERS_CALDATA_PROVIDER_DEF_H_
#define SIGM_RECEIVERS_CALDATA_PROVIDER_DEF_H_

#include "BaseReceiver.h"

namespace sigm
{

class RecCalDataProvider_Def : public BaseReceiver
{
public:
  RecCalDataProvider_Def();
  virtual ~RecCalDataProvider_Def();

  virtual bool_t handleSpecificReceiver_b();


private:
  osal::Mutex                        mutex_o;
  bool_t handle_RecCalDataProviderDefReceiver_b();
  sensor::CameraBase*    cameras_ao[(variants::e_CameraCount -1)];
  bool_t                 cameraInit_ab[(variants::e_CameraCount -1)];
  void updateCamera_v(const variants::Camera_t i_Camera_t, const sensor::CalibrationData_t& i_CalibrationData_rt);
};

} // namespace sigm
#endif // SIGM_RECEIVERS_CALDATA_PROVIDER_DEF_H_
