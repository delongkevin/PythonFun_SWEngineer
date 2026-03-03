//--------------------------------------------------------------------------
/// @file SenScreenResponse.h
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

#ifndef SIGM_SENDERS_SCREEN_RESPONSE_H_
#define SIGM_SENDERS_SCREEN_RESPONSE_H_

#include "BaseSender.h"

namespace sigm
{

class SenScreenResponse : public BaseSender
{
public:
	SenScreenResponse();
  virtual ~SenScreenResponse();

  virtual bool_t handleSpecificSender_b();


private:
  bool_t handle_ScreenResponseSender_b();
};

} // namespace sigm
#endif // SIGM_SENDERS_SCREEN_RESPONSE_H_
