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
#ifndef SVSCAMCURRENTCALIBDATATONVM_H_
#define SVSCAMCURRENTCALIBDATATONVM_H_
#include "BaseSender.h"
namespace sigm
{
class SVSCamCurrentCalibDataToNVM : public BaseSender
{
public:
   SVSCamCurrentCalibDataToNVM();
   virtual ~SVSCamCurrentCalibDataToNVM();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_TbSVS_S_SVSCamCurrentCalibDataToNVM_b();
};
} // namespace sigm
#endif //SVSCAMCURRENTCALIBDATATONVM_H_
