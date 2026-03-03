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
#ifndef TRSC_INPUTS_FROM_TRAILERDETECTION_H_
#define TRSC_INPUTS_FROM_TRAILERDETECTION_H_
#include "BaseSender.h"
namespace sigm
{
class TRSC_Inputs_from_TrailerDetection : public BaseSender
{
public:
   TRSC_Inputs_from_TrailerDetection();
   virtual ~TRSC_Inputs_from_TrailerDetection();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_TRSC_Inputs_from_TrailerDetection_b();
};
} // namespace sigm
#endif //TRSC_INPUTS_FROM_TRAILERDETECTION_H_
