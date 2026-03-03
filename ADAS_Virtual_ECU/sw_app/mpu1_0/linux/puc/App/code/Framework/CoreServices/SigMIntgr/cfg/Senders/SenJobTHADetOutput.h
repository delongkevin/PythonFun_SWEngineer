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
#ifndef JOBTHADETOUTPUT_H_
#define JOBTHADETOUTPUT_H_
#include "BaseSender.h"
namespace sigm
{
class JobTHADetOutput : public BaseSender
{
public:
   JobTHADetOutput();
   virtual ~JobTHADetOutput();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_JobTHADetOutput_b();
};
} // namespace sigm
#endif //JOBTHADETOUTPUT_H_
