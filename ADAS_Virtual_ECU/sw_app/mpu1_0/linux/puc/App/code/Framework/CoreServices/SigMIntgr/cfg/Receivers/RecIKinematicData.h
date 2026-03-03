//--------------------------------------------------------------------------
/// @file RecIKinematicData.h
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

#ifndef SIGM_RECEIVERS_REC_IKINEMATIC_DATA_H_
#define SIGM_RECEIVERS_REC_IKINEMATIC_DATA_H_

#include "BaseReceiver.h"

namespace sigm
{

class RecIKinematicData : public BaseReceiver
{
public:
  RecIKinematicData();
  virtual ~RecIKinematicData();

  virtual bool_t handleSpecificReceiver_b();


private:
  bool_t handleIKinematicDataReceiver_b();
};

} // namespace sigm
#endif // SIGM_RECEIVERS_REC_IKINEMATIC_DATA_H_
