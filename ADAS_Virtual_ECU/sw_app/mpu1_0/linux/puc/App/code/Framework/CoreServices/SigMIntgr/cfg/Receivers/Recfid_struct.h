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
#ifndef FID_STRUCT_H_
#define FID_STRUCT_H_
#include "BaseReceiver.h"

namespace sigm
{
class fid_struct : public BaseReceiver
{
public:
   fid_struct();
   virtual ~fid_struct();
   virtual bool_t handleSpecificReceiver_b();
private:
   bool_t handle_fid_structReceiver_b();
};
} // namespace sigm
#endif //FID_STRUCT_H_