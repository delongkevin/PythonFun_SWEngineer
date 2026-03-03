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
 *  @author (Author pavan.raut@magna.com)
 *  --------------------------------------------------------------------------*/
#ifndef LMD_CALIBRATION_DATA_H_
#define LMD_CALIBRATION_DATA_H_
#include "BaseReceiver.h"

namespace sigm
{
class LMD_Calibration_data : public BaseReceiver
{
public:
   LMD_Calibration_data();
   virtual ~LMD_Calibration_data();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_LMD_Calibration_dataReceiver_b();
};
} // namespace sigm
#endif //LMD_CALIBRATION_DATA_H_

