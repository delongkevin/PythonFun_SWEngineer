// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for windows only
#ifdef ME_PLATFORM_WIN

// stdlib header include
#include "platform/stdlib/ME_Time.h"
#include "platform/stdlib/ME_Assert.h"

#include "platform/win/WinInclude.h"

PlatformError_t getPerformanceCounter_t(uint64_t* i_Time_pu64)
{
  LARGE_INTEGER v_TimeLongLong_t;
  PlatformError_t v_Error_t = e_PeOk;

  if ( (NULL != i_Time_pu64) && (QueryPerformanceCounter(&v_TimeLongLong_t)) )
  {
    *i_Time_pu64 = (uint64_t)v_TimeLongLong_t.QuadPart;
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t getPerformanceFrequency_t(uint64_t* i_Frequency_pu64)
{
  LARGE_INTEGER v_FrequencyLongLong_t;
  PlatformError_t v_Error_t = e_PeOk;

  if ( (NULL != i_Frequency_pu64) && (QueryPerformanceFrequency(&v_FrequencyLongLong_t)) )
  {
    *i_Frequency_pu64 = (uint64_t)v_FrequencyLongLong_t.QuadPart;
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Time_GetTimeNsec_t(uint64_t* i_TimeInNsec_pu64)
{
  PlatformError_t v_Error_t = e_PeOk;
  uint64_t v_Frequency_u64;
  uint64_t v_Timer_u64;

  v_Error_t = getPerformanceFrequency_t(&v_Frequency_u64);
  Assert(e_PeOk == v_Error_t);

  v_Error_t = getPerformanceCounter_t(&v_Timer_u64);
  Assert(e_PeOk == v_Error_t);

  if ( (e_PeOk == v_Error_t) && (NULL != i_TimeInNsec_pu64) )
  {
    *i_TimeInNsec_pu64 = (uint64_t)( (v_Timer_u64 / v_Frequency_u64) * 1000000000);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Time_GetTimeUsec_t(uint64_t* i_TimeInUsec_pu64)
{
  PlatformError_t v_Error_t = e_PeOk;
  uint64_t v_Frequency_f64;
  uint64_t v_Timer_u64;

  v_Error_t = getPerformanceFrequency_t(&v_Frequency_f64);
  Assert(e_PeOk == v_Error_t);

  v_Error_t = getPerformanceCounter_t(&v_Timer_u64);
  Assert(e_PeOk == v_Error_t);


  if ( (e_PeOk == v_Error_t) && (NULL != i_TimeInUsec_pu64) )
  {                                                               
    *i_TimeInUsec_pu64 = (uint64_t)( (v_Timer_u64 / v_Frequency_f64) * 1000000);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Time_GetTimeMsec_t(uint64_t* o_TimeInMsec_pu64)
{
  PlatformError_t v_Error_t = e_PeOk;
  uint64_t v_Frequency_u64;
  uint64_t v_Timer_u64;

  v_Error_t = getPerformanceFrequency_t(&v_Frequency_u64);
  Assert(e_PeOk == v_Error_t);

  v_Error_t = getPerformanceCounter_t(&v_Timer_u64);
  Assert(e_PeOk == v_Error_t);


  if ( (e_PeOk == v_Error_t) && (NULL != o_TimeInMsec_pu64) )
  {
    *o_TimeInMsec_pu64 = (uint64_t)( (v_Timer_u64 / v_Frequency_u64) * 1000);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Time_GetTimeMsecf64_t(float64_t* o_TimeInMsec_pf64)
{
  PlatformError_t v_Error_t = e_PeOk;
  uint64_t v_Frequency_u64;
  uint64_t v_Timer_u64;

  v_Error_t = getPerformanceFrequency_t(&v_Frequency_u64);
  Assert(e_PeOk == v_Error_t);

  v_Error_t = getPerformanceCounter_t(&v_Timer_u64);
  Assert(e_PeOk == v_Error_t);


  if ( (e_PeOk == v_Error_t) && (NULL != o_TimeInMsec_pf64) )
  {
    *o_TimeInMsec_pf64 = (v_Timer_u64 / (float64_t)v_Frequency_u64);
    *o_TimeInMsec_pf64 *= 1000.0;
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}


#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
