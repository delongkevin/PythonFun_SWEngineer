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
 *  @author (Author pavan.raut@magna.com)
 *  --------------------------------------------------------------------------*/
#ifndef CAM_HOTPLUG_STATUS_H_
#define CAM_HOTPLUG_STATUS_H_
#include "BaseReceiver.h"

namespace sigm
{
class CamHotplugStatus : public BaseReceiver
{
public:
   CamHotplugStatus();
   virtual ~CamHotplugStatus();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_CamHotplugStatusReceiver_b();
};
} // namespace sigm
#endif //CAM_HOTPLUG_STATUS_H_
