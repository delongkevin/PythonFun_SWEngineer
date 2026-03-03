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
#ifndef SVSCAMOCCALIBDATATONVM_H_
#define SVSCAMOCCALIBDATATONVM_H_
#include "BaseSender.h"
namespace sigm
{
class SVSCamOCCalibDataToNVM : public BaseSender
{
public:
   SVSCamOCCalibDataToNVM();
   virtual ~SVSCamOCCalibDataToNVM();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_TbSVS_S_SVSCamOCCalibDataToNVM_b();
};
} // namespace sigm
#endif //SVSCAMOCCALIBDATATONVM_H_
