/*
 * ME_Time_QNX.c
 *
 *  Creation Date: 17.11.2017
 *         Author: Marcel Engelhardt
 *        Company: Magna Electronics
 */

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for QNX only
#ifdef ME_PLATFORM_QNX

// stdlib header include
#include "platform/stdlib/ME_Time.h"

PlatformError_t ME_Time_GetTimeNsec_t(uint64_t* o_TimeInMsec_pu64)
{
  PlatformError_t v_Error_t;
  struct timespec v_Clockval_s;
  sint32_t v_Result_s32;

  if(NULL != o_TimeInMsec_pu64)
  {
    v_Result_s32 = clock_gettime(CLOCK_REALTIME, &v_Clockval_s);

    *o_TimeInMsec_pu64 = (uint64_t)v_Clockval_s.tv_nsec + ((uint64_t)v_Clockval_s.tv_sec *1000*1000*1000);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Time_GetTimeUsec_t(uint64_t* o_TimeInUsec_pu64)
{
  PlatformError_t v_Error_t;
  struct timespec v_Clockval_s;
  sint32_t v_Result_s32;

  if(NULL != o_TimeInUsec_pu64)
  {
    v_Result_s32 = clock_gettime(CLOCK_REALTIME, &v_Clockval_s);

    *o_TimeInUsec_pu64 = ((uint64_t)v_Clockval_s.tv_nsec/1000) + ((uint64_t)v_Clockval_s.tv_sec *1000*1000);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Time_GetTimeMsec_t(uint64_t* o_TimeInMsec_pu64)
{
  PlatformError_t v_Error_t;
  struct timespec v_Clockval_s;
  sint32_t v_Result_s32;

  if(NULL != o_TimeInMsec_pu64)
  {
    v_Result_s32 = clock_gettime(CLOCK_REALTIME, &v_Clockval_s);

    *o_TimeInMsec_pu64 = ((uint64_t)((v_Clockval_s.tv_nsec/1000)/1000)) + ((uint64_t)v_Clockval_s.tv_sec * 1000);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
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

    *o_TimeInMsec_pf64 = ((float64_t)(((float64_t)v_Clockval_s.tv_nsec/1000.0)/1000.0)) + ((float64_t)v_Clockval_s.tv_sec * 1000.0);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

#endif // ME_PLATFORM_QNX
