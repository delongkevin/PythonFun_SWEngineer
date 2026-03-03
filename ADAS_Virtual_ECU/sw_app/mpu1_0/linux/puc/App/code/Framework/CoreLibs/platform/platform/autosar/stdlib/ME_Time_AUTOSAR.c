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
#ifdef ME_PLATFORM_AUTOSARTODO

// stdlib header include
#include "platform/stdlib/ME_Time.h"

PlatformError_t ME_Time_F_GetTimeNsec_t(uint64_t* i_TimeInMsec_pu64)
{
  PlatformError_t v_Error_t;
  struct timespec clockval;
  sint32_t v_Result_s32;

  if(NULL != i_TimeInMsec_pu64)
  {
    v_Result_s32 = clock_gettime(CLOCK_REALTIME, &clockval);

    *i_TimeInMsec_pu64 = (uint64_t)clockval.tv_nsec + ((uint64_t)clockval.tv_sec *1000*1000*1000);
    v_Error_t = getPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Time_F_GetTimeUsec_t(uint64_t* i_TimeInUsec_pu64)
{
  PlatformError_t v_Error_t;
  struct timespec clockval;
  sint32_t v_Result_s32;

  if(NULL != i_TimeInUsec_pu64)
  {
    v_Result_s32 = clock_gettime(CLOCK_REALTIME, &clockval);

    *i_TimeInUsec_pu64 = ((uint64_t)clockval.tv_nsec/1000) + ((uint64_t)clockval.tv_sec *1000*1000);
    v_Error_t = getPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Time_F_GetTimeMsec_t(uint64_t* i_TimeInMsec_pu64)
{
  PlatformError_t v_Error_t;
  struct timespec clockval;
  sint32_t v_Result_s32;

  if(NULL != i_TimeInMsec_pu64)
  {
    v_Result_s32 = clock_gettime(CLOCK_REALTIME, &clockval);

    *i_TimeInMsec_pu64 = ((uint64_t)clockval.tv_nsec/1000/1000) + ((uint64_t)clockval.tv_sec *1000);
    v_Error_t = getPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Time_GetTimeMsecf64_t(float64_t* o_TimeInMsec_pf64)
{
  PlatformError_t v_Error_t;
  struct timespec v_Clockval_s;
  sint32_t v_Result_s32;

  if(NULL != o_TimeInMsec_pf64)
  {
    v_Result_s32 = clock_gettime(CLOCK_REALTIME, &v_Clockval_s);

    *o_TimeInMsec_pf64 = ((float64_t)((v_Clockval_s.tv_nsec/1000)/1000)) + ((float64_t)v_Clockval_s.tv_sec * 1000);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

#endif // ME_PLATFORM_AUTOSAR // PRQA S 862 // this define decides which platform is defined
