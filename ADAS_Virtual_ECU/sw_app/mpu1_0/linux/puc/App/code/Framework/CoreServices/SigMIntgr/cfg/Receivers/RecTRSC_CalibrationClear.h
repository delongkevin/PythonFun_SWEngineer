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
#ifndef TRSC_CALIBRATION_CLEAR_H_
#define TRSC_CALIBRATION_CLEAR_H_

#include "BaseReceiver.h"

namespace sigm
{
class TRSC_CalibrationClear : public BaseReceiver
{
public:
   TRSC_CalibrationClear();
   virtual ~TRSC_CalibrationClear();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_TRSC_CalibrationClearReceiver_b();
};
} // namespace sigm

#endif //TRSC_CALIBRATION_CLEAR_H_
