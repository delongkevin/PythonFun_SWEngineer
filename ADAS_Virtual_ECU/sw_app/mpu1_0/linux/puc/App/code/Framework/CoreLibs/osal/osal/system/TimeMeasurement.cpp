//--------------------------------------------------------------------------
/// @file TimeMeasurement.cpp
/// @brief Class to record and display time a given code block was processing
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#include "TimeMeasurement.h"

namespace osal
{

TimeMeasurement::TimeMeasurement(const char_t* i_ContextString_pc)
  : depth_u32(0U)
{
  ME_String_Strcpy_v(contextString_ac, i_ContextString_pc);
}

TimeMeasurement::~TimeMeasurement()
{
}

void TimeMeasurement::start_v(const char_t* i_LocalContextString_pc)
{
  startTime_au64[depth_u32] = time_o.getTimeMsec_u64();

  ME_String_Strcpy_v(localContextString_ac[depth_u32], i_LocalContextString_pc);
  depth_u32++;
}

void TimeMeasurement::end_v()
{
  depth_u32--;

  endTime_au64[depth_u32] = time_o.getTimeMsec_u64();
  diffTime_au64[depth_u32] = endTime_au64[depth_u32] - startTime_au64[depth_u32];

  ME_Debugger_F_Printf_v("%s::%s - Time needed %d\n", contextString_ac, localContextString_ac[depth_u32], diffTime_au64[depth_u32]);
}

} /* namespace osal */
