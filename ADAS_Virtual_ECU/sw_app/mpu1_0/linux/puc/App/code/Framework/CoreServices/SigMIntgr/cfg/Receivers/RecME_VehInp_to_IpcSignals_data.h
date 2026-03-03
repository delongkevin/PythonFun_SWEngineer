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
#ifndef ME_VEHINP_TO_IPCSIGNALS_DATA_H_
#define ME_VEHINP_TO_IPCSIGNALS_DATA_H_
#include "BaseReceiver.h"

namespace sigm
{
class ME_VehInp_to_IpcSignals_data : public BaseReceiver
{
public:
   ME_VehInp_to_IpcSignals_data();
   virtual ~ME_VehInp_to_IpcSignals_data();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_ME_VehInp_to_IpcSignals_dataReceiver_b();
};
} // namespace sigm
#endif // ME_VEHINP_TO_IPCSIGNALS_DATA_H_
