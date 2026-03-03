//--------------------------------------------------------------------------
/// @file SenMOT_Output.h
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

#ifndef SIGM_SENDERS_MOT_OUTPUT_H_
#define SIGM_SENDERS_MOT_OUTPUT_H_

#include "BaseSender.h"

namespace sigm
{

class SenMOT_Output : public BaseSender
{
public:
	SenMOT_Output();
  virtual ~SenMOT_Output();

  virtual bool_t handleSpecificSender_b();


private:
  bool_t handle_MOT_OutputSender_b();
};

} // namespace sigm
#endif // SIGM_SENDERS_MOT_OUTPUT_H_
