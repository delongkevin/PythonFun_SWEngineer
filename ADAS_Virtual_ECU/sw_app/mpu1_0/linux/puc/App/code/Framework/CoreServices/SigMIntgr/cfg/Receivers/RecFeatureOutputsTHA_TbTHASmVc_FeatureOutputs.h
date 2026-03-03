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
#ifndef FEATUREOUTPUTSTHA_TBTHASMVC_FEATUREOUTPUTS_H_
#define FEATUREOUTPUTSTHA_TBTHASMVC_FEATUREOUTPUTS_H_
#include "BaseReceiver.h"

namespace sigm
{
class FeatureOutputsTHA_TbTHASmVc_FeatureOutputs : public BaseReceiver
{
public:
   FeatureOutputsTHA_TbTHASmVc_FeatureOutputs();
   virtual ~FeatureOutputsTHA_TbTHASmVc_FeatureOutputs();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_FeatureOutputsTHA_TbTHASmVc_FeatureOutputsReceiver_b();
};
} // namespace sigm
#endif // FEATUREOUTPUTSTHA_TBTHASMVC_FEATUREOUTPUTS_H_
