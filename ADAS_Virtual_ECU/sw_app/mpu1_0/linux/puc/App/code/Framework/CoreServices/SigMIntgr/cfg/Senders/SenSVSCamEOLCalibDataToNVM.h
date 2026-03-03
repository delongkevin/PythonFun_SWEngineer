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
#ifndef SVSCAMEOLCALIBDATATONVM_H_
#define SVSCAMEOLCALIBDATATONVM_H_
#include "BaseSender.h"
namespace sigm
{
class SVSCamEOLCalibDataToNVM : public BaseSender
{
public:
   SVSCamEOLCalibDataToNVM();
   virtual ~SVSCamEOLCalibDataToNVM();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_TbSVS_S_SVSCamEOLCalibDataToNVM_b();
};
} // namespace sigm
#endif //SVSCAMEOLCALIBDATATONVM_H_
