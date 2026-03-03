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
#ifndef MEDLD_E_RRCAMSTS_H_
#define MEDLD_E_RRCAMSTS_H_
#include "BaseSender.h"
namespace sigm
{
class MeDLD_e_RrCamSts : public BaseSender
{
public:
   MeDLD_e_RrCamSts();
   virtual ~MeDLD_e_RrCamSts();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_MeDLD_e_RrCamSts_b();
};
} // namespace sigm
#endif //MEDLD_E_RRCAMSTS_H_
