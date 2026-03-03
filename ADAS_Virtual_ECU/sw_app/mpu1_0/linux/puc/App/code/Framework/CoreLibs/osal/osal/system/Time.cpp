/*
 * Time.cpp
 *
 *  Created on: 17.11.2017
 *      Author: Marcel Engelhardt
 */

#include "Time.h"

namespace osal
{

Time::Time()
{
}

Time::~Time()
{
}

uint64_t Time::getTimeNsec_u64(void) const // PRQA S 4212 // member function as wrapper for Platform call
{
  PlatformError_t v_Success_b;
  uint64_t v_TimeInNsec_u64;

  v_Success_b = ME_Time_GetTimeNsec_t(&v_TimeInNsec_u64);
  Assert(v_Success_b == e_PeOk);

  return v_TimeInNsec_u64;
}

uint64_t Time::getTimeUsec_u64(void) const // PRQA S 4212 // member function as wrapper for Platform call
{
  PlatformError_t v_Success_b;
  uint64_t v_TimeInUsec_u64;

  v_Success_b = ME_Time_GetTimeUsec_t(&v_TimeInUsec_u64);
  Assert(v_Success_b == e_PeOk);

  return v_TimeInUsec_u64;
}

uint64_t Time::getTimeMsec_u64(void) const // PRQA S 4212 // member function as wrapper for Platform call
{
  PlatformError_t v_Success_b;
  uint64_t v_TimeInMsec_u64;

  v_Success_b = ME_Time_GetTimeMsec_t(&v_TimeInMsec_u64);
  Assert(v_Success_b == e_PeOk);

  return v_TimeInMsec_u64;
}

} /* namespace osal */
