//--------------------------------------------------------------------------
/// @file SenIParkingSlotInformation.h
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
/// @author sagar saste (sagar.saste@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef SIGM_SENDERS_IPARKING_SLOT_INFO_H_
#define SIGM_SENDERS_IPARKING_SLOT_INFO_H_

#include "BaseSender.h"

namespace sigm
{

class SenIParkingSlotInformation : public BaseSender
{
public:
	SenIParkingSlotInformation();
  virtual ~SenIParkingSlotInformation();

  virtual bool_t handleSpecificSender_b();


private:
  bool_t handle_IParkingSlotInformation_b();
};

} // namespace sigm
#endif // SIGM_SENDERS_IPARKING_SLOT_INFO_H_
