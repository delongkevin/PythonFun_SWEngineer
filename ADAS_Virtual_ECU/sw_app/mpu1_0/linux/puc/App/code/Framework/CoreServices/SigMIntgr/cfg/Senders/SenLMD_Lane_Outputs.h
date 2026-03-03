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
#ifndef LMD_LANE_OUTPUTS_H
#define LMD_LANE_OUTPUTS_H
#include "BaseSender.h"
namespace sigm
{
class LMD_Lane_Outputs : public BaseSender
{
public:
   LMD_Lane_Outputs();
   virtual ~LMD_Lane_Outputs();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_LMD_Lane_Outputs_s_b();
};
} // namespace sigm
#endif //LMD_LANE_OUTPUTS_H
