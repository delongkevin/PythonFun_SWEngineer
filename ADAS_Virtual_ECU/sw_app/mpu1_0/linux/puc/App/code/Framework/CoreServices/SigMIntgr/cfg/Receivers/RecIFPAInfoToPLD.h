//--------------------------------------------------------------------------
/// @file RecIFPAInfoToPLD.h
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

#ifndef SIGM_IFPA_INFO_TO_PLD_H_
#define SIGM_IFPA_INFO_TO_PLD_H_

#include "BaseReceiver.h"

namespace sigm
{

class RecIFPAInfoToPLD : public BaseReceiver
{
public:
  RecIFPAInfoToPLD();
  virtual ~RecIFPAInfoToPLD();

  virtual bool_t handleSpecificReceiver_b();


private:
  bool_t handle_IFPAInfoToPLD_b();
};

} // namespace sigm
#endif // SIGM_IFPA_INFO_TO_PLD_H_
