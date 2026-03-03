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
#ifndef TBAP_DRIVEASSISTSTATOUT_H_
#define TBAP_DRIVEASSISTSTATOUT_H_
#include "BaseReceiver.h"

namespace sigm
{
class TbAP_DriveAssistStatOut : public BaseReceiver
{
public:
   TbAP_DriveAssistStatOut();
   virtual ~TbAP_DriveAssistStatOut();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_TbAP_DriveAssistStatOutReceiver_b();
};
} // namespace sigm
#endif //TBAP_DRIVEASSISTSTATOUT_H_
