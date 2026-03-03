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
#ifndef THA_CALIBRATION_DATA_MPU1_0_H_
#define THA_CALIBRATION_DATA_MPU1_0_H_
#include "BaseReceiver.h"

namespace sigm
{
class THA_Calibration_data_MPU1_0 : public BaseReceiver
{
public:
   THA_Calibration_data_MPU1_0();
   virtual ~THA_Calibration_data_MPU1_0();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_THA_Calibration_data_MPU1_0Receiver_b();
};
} // namespace sigm
#endif //THA_CALIBRATION_DATA_MPU1_0_H_
