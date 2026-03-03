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
#ifndef TRAILERDET_OUTPUT_DID_H_
#define TRAILERDET_OUTPUT_DID_H_
#include "BaseSender.h"
namespace sigm
{
class TrailerDet_Output_DID : public BaseSender
{
public:
   TrailerDet_Output_DID();
   virtual ~TrailerDet_Output_DID();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_TrailerDetection_Output_DID_b();
};
} // namespace sigm
#endif //TRAILERDET_OUTPUT_DID_H_