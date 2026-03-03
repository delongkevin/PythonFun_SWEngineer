//--------------------------------------------------------------------------
/// @file RecSSM_SystemState.h
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
/// *  @author sagar.saste@magna.com
///
//  --------------------------------------------------------------------------

#ifndef SIGM_RECEIVERS_SSM_SYSTEM_STATE_H_
#define SIGM_RECEIVERS_SSM_SYSTEM_STATE_H_

#include "BaseReceiver.h"

namespace sigm
{

class RecSSM_SystemState : public BaseReceiver
{
public:
  RecSSM_SystemState();
  virtual ~RecSSM_SystemState();

  virtual bool_t handleSpecificReceiver_b();


private:
  bool_t handle_RecSSM_SystemStateReceiver_b();
};

} // namespace sigm
#endif // SIGM_RECEIVERS_SSM_SYSTEM_STATE_H_
