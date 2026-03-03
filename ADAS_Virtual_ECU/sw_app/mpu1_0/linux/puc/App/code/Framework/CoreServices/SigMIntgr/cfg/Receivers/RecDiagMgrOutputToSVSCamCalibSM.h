//--------------------------------------------------------------------------
/// @file RecDiagMgrOutputToSVSCamCalibSM.h
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

#ifndef SIGM_RECEIVERS_DIAGMGR_OUTPUT_TO_SVS_CAM_CALIB_SM_H_
#define SIGM_RECEIVERS_DIAGMGR_OUTPUT_TO_SVS_CAM_CALIB_SM_H_

#include "BaseReceiver.h"

namespace sigm
{

class RecDiagMgrOutputToSVSCamCalibSM : public BaseReceiver
{
public:
  RecDiagMgrOutputToSVSCamCalibSM();
  virtual ~RecDiagMgrOutputToSVSCamCalibSM();

  virtual bool_t handleSpecificReceiver_b();


private:
  bool_t handle_DiagMgrOutputToSVSCamCalibSMReceiver_b();
};

} // namespace sigm
#endif // SIGM_RECEIVERS_DIAGMGR_OUTPUT_TO_SVS_CAM_CALIB_SM_H_
