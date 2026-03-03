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
 *  @author (Author sagar.saste@magna.com)
 *  --------------------------------------------------------------------------*/
#ifndef CANDEBUGRIDSTATUS_H_
#define CANDEBUGRIDSTATUS_H_
#include "BaseReceiver.h"

namespace sigm
{
class CanDebugRIDStatus : public BaseReceiver
{
public:
   CanDebugRIDStatus();
   virtual ~CanDebugRIDStatus();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_CanDebugRIDStatusReceiver_b();
};
} // namespace sigm
#endif //CANDEBUGRIDSTATUS_H_