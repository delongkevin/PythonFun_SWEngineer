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
#ifndef DETECTION_INPUTS_FROM_TRSC_H_
#define DETECTION_INPUTS_FROM_TRSC_H_
#include "BaseReceiver.h"

namespace sigm
{
class Detection_Inputs_from_TRSC : public BaseReceiver
{
public:
   Detection_Inputs_from_TRSC();
   virtual ~Detection_Inputs_from_TRSC();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_Detection_Inputs_from_TRSCReceiver_b();
};
} // namespace sigm
#endif // DETECTION_INPUTS_FROM_TRSC_H_
