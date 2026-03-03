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
#ifndef THARELATED_SCREENREQ_H_
#define THARELATED_SCREENREQ_H_
#include "BaseReceiver.h"

namespace sigm
{
class THARelated_ScreenReq : public BaseReceiver
{
public:
   THARelated_ScreenReq();
   virtual ~THARelated_ScreenReq();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_THARelated_ScreenReqReceiver_b();
};
} // namespace sigm
#endif // THARELATED_SCREENREQ_H_
