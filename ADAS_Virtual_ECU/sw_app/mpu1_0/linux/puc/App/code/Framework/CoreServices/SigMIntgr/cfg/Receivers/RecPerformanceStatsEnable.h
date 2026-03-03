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
#ifndef RUN_TIME_STATS_ENABLE_H_
#define RUN_TIME_STATS_ENABLE_H_
#include "BaseReceiver.h"

namespace sigm
{
class PerformanceStatsEnable : public BaseReceiver
{
public:
   PerformanceStatsEnable();
   virtual ~PerformanceStatsEnable();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_PerformanceStatsEnableReceiver_b();
};
} // namespace sigm
#endif //RUN_TIME_STATS_ENABLE_H_
