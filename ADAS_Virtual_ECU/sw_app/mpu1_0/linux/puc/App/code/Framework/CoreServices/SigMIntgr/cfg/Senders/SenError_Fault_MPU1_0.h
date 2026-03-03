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
#ifndef ERROR_FAULT_MPU1_0_H_
#define ERROR_FAULT_MPU1_0_H_
#include "BaseSender.h"
namespace sigm
{
class Error_Fault_MPU1_0 : public BaseSender
{
public:
	Error_Fault_MPU1_0();
   virtual ~Error_Fault_MPU1_0();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_Error_Fault_MPU1_0_b();
};
} // namespace sigm
#endif //ERROR_FAULT_MPU1_0_H_
