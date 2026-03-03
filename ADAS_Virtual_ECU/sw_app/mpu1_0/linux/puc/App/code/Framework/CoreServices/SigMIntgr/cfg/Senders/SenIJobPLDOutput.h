//--------------------------------------------------------------------------
/// @file SenIJobPLDOutput.h
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

#ifndef SIGM_SENDERS_IJOB_PLD_OUTPUT_H_
#define SIGM_SENDERS_IJOB_PLD_OUTPUT_H_

#include "BaseSender.h"

namespace sigm
{

class SenIJobPLDOutput : public BaseSender
{
public:
	SenIJobPLDOutput();
  virtual ~SenIJobPLDOutput();

  virtual bool_t handleSpecificSender_b();


private:
  bool_t handle_IJobPLDOutput_b();
};

} // namespace sigm
#endif // SIGM_SENDERS_IJOB_PLD_OUTPUT_H_
