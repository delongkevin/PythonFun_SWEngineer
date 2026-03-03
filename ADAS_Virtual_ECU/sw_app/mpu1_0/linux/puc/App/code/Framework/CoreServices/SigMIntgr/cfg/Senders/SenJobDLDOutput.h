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
#ifndef JOBDLD_OUTPUT_H_
#define JOBDLD_OUTPUT_H_
#include "BaseSender.h"
namespace sigm
{
class JobDLDOutput : public BaseSender
{
public:
	JobDLDOutput();
   virtual ~JobDLDOutput();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_JobDLDOutput_b();
};
} // namespace sigm
#endif //JOBDLD_OUTPUT_H_
