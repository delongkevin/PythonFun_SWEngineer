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
#ifndef MCU2_STATE_2_0_H_
#define MCU2_STATE_2_0_H_
#include "BaseReceiver.h"

namespace sigm
{
class MCU2_State_2_0 : public BaseReceiver
{
public:
   MCU2_State_2_0();
   virtual ~MCU2_State_2_0();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_MCU2_State_2_0Receiver_b();
};
} // namespace sigm
#endif // MCU2_STATE_2_0_H_
