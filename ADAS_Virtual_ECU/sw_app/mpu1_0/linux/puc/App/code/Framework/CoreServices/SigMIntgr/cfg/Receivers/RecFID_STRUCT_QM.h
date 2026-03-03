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
 *  @author (Author Pavan.Raut@magna.com)
 *  --------------------------------------------------------------------------*/
#ifndef FID_STRUCT_QM_H_
#define FID_STRUCT_QM_H_
#include "BaseReceiver.h"

namespace sigm
{
class FID_STRUCT_QM_C : public BaseReceiver
{
public:
   FID_STRUCT_QM_C();
   virtual ~FID_STRUCT_QM_C();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_FID_STRUCT_QM_Receiver_b();
};
} // namespace sigm
#endif //FID_STRUCT_QM_H_