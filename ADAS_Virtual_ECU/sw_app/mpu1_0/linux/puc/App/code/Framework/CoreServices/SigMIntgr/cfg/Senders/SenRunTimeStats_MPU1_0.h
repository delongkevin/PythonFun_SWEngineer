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
#ifndef RUN_TIME_STATS_MPU1_0_H_
#define RUN_TIME_STATS_MPU1_0_H_
#include "BaseSender.h"
namespace sigm
{
class RunTimeStats_MPU1_0 : public BaseSender
{
public:
	RunTimeStats_MPU1_0();
   virtual ~RunTimeStats_MPU1_0();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_RunTimeStats_MPU1_0_b();
};
} // namespace sigm
#endif //RUN_TIME_STATS_MPU1_0_H_
