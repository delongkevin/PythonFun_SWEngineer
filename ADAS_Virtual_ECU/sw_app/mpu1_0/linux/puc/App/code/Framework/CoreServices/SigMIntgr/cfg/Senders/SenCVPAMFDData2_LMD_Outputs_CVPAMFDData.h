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
#ifndef CVPAMFDDATA2_LMD_OUTPUTS_CVPAMFDDATA_H_
#define CVPAMFDDATA2_LMD_OUTPUTS_CVPAMFDDATA_H_
#include "BaseSender.h"
namespace sigm
{
class CVPAMFDData2_LMD_Outputs_CVPAMFDData : public BaseSender
{
public:
   CVPAMFDData2_LMD_Outputs_CVPAMFDData();
   virtual ~CVPAMFDData2_LMD_Outputs_CVPAMFDData();
   virtual bool_t handleSpecificSender_b();
private:
   bool_t handle_LMD_Outputs_CVPAMFDData2_b();
};
} // namespace sigm
#endif //CVPAMFDDATA2_LMD_OUTPUTS_CVPAMFDDATA_H_