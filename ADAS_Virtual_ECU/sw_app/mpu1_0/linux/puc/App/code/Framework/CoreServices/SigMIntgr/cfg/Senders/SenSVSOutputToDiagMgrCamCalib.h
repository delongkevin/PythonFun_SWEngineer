//--------------------------------------------------------------------------
/// @file SenSVSOutputToDiagMgrCamCalib.h
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
///  *  @author sagar.saste@magna.com
///
//  --------------------------------------------------------------------------

#ifndef SIGM_SENDERS_SVS_OUTPUT_TO_DIAG_MGR_CALIB_H_
#define SIGM_SENDERS_SVS_OUTPUT_TO_DIAG_MGR_CALIB_H_

#include "BaseSender.h"

namespace sigm
{

class SenSVSOutputToDiagMgrCamCalib : public BaseSender
{
public:
	SenSVSOutputToDiagMgrCamCalib();
  virtual ~SenSVSOutputToDiagMgrCamCalib();

  virtual bool_t handleSpecificSender_b();


private:
  bool_t handle_TbADAS_SVSOutputToDiagMgrCamCalibSender_b();
};

} // namespace sigm
#endif // SIGM_SENDERS_SVS_OUTPUT_TO_DIAG_MGR_CALIB_H_
