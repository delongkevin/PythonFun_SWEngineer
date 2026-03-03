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
#ifndef TRAILERDETECTION_OUTPUT_HMI_H_
#define TRAILERDETECTION_OUTPUT_HMI_H_
#include "BaseSender.h"
namespace sigm
{
class TrailerDetection_Output_HMI : public BaseSender
{
public:
   TrailerDetection_Output_HMI();
   virtual ~TrailerDetection_Output_HMI();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_TrailerDetection_Output_HMI_b();
};
} // namespace sigm
#endif //TRAILERDETECTION_OUTPUT_HMI_H_
