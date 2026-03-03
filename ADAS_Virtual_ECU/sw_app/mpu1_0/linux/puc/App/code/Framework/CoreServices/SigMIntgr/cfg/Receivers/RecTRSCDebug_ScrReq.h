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
#ifndef TRSCDEBUG_SCRREQ_H_
#define TRSCDEBUG_SCRREQ_H_
#include "BaseReceiver.h"

namespace sigm
{
class TRSCDebug_ScrReq : public BaseReceiver
{
public:
   TRSCDebug_ScrReq();
   virtual ~TRSCDebug_ScrReq();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_TRSCDebug_ScrReqReceiver_b();
};
} // namespace sigm
#endif //TRSCDEBUG_SCRREQ_H_