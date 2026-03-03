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
#ifndef ME_PROXI_MPU1_0_TO_MCU1_0_H
#define ME_PROXI_MPU1_0_TO_MCU1_0_H
#include "BaseSender.h"
namespace sigm
{
class ME_Proxi_MPU1_0_to_MCU1_0 : public BaseSender
{
public:
   ME_Proxi_MPU1_0_to_MCU1_0();
   virtual ~ME_Proxi_MPU1_0_to_MCU1_0();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_ME_Proxi_MPU1_0_to_MCU1_0_t_b();
};
} // namespace sigm
#endif //ME_PROXI_MPU1_0_TO_MCU1_0_H
