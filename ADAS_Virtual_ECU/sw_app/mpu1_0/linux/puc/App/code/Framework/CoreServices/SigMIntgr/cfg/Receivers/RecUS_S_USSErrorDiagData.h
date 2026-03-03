/**
 * -------------------------------------------------------------------------
 *  @file ***.cpp/***.h
 *  @brief Contains
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
 *  @author sagar.saste@magna.com
 *  --------------------------------------------------------------------------*/
#ifndef US_S_USSERRORDIAGDATA_H_
#define US_S_USSERRORDIAGDATA_H_
#include "BaseReceiver.h"

namespace sigm
{
class US_S_USSErrorDiagData : public BaseReceiver
{
public:
   US_S_USSErrorDiagData();
   virtual ~US_S_USSErrorDiagData();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_US_S_USSErrorDiagDataReceiver_b();
};
} // namespace sigm
#endif // US_S_USSERRORDIAGDATA_H_
