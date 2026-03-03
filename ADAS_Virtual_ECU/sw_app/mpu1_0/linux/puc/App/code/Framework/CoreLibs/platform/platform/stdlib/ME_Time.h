/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------

/// @file ME_Time.h
/// @brief Gets System Time
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ME_TIME_QNX_H_
#define ME_TIME_QNX_H_

#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif

PlatformError_t ME_Time_GetTimeNsec_t(uint64_t* o_TimeInMsec_pu64);
PlatformError_t ME_Time_GetTimeUsec_t(uint64_t* o_TimeInUsec_pu64);
PlatformError_t ME_Time_GetTimeMsec_t(uint64_t* o_TimeInMsec_pu64);
PlatformError_t ME_Time_GetTimeMsecf64_t(float64_t* o_TimeInMsec_pf64);

#if defined(__cplusplus)
}; // extern C
#endif

#endif /* QNX_H_ */
