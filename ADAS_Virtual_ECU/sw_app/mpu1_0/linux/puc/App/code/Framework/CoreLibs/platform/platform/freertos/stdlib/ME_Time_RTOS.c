/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */
/*

 * ME_Time_AUTOSAR.c
 *
 *  Creation Date: 17.11.2017
 *         Author: Marcel Engelhardt
 *        Company: Magna Electronics
 */

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

// stdlib header include
#include "platform/stdlib/ME_Time.h"

PlatformError_t ME_Time_GetTimeNsec_t(uint64_t* i_TimeInMsec_pu64)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Time_GetTimeUsec_t(uint64_t* i_TimeInUsec_pu64)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Time_GetTimeMsec_t(uint64_t* i_TimeInMsec_pu64)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Time_GetTimeMsecf64_t(float64_t* o_TimeInMsec_pf64)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined
