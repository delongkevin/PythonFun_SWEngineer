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
#ifndef SVSTOTHADET_H_
#define SVSTOTHADET_H_
#include "BaseReceiver.h"

namespace sigm
{
class SvsToTHADet : public BaseReceiver
{
public:
   SvsToTHADet();
   virtual ~SvsToTHADet();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_SvsToTHADetReceiver_b();
};
} // namespace sigm
#endif // SVSTOTHADET_H_
