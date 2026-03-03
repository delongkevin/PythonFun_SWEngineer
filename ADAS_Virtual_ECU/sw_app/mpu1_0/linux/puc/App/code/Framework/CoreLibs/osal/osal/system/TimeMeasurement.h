//--------------------------------------------------------------------------
/// @file TimeMeasurement.h
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

#ifndef OSAL_TIME_MEASUREMENT_H
#define OSAL_TIME_MEASUREMENT_H

#include <platform/PlatformAPI.h>

#include "Time.h"

namespace osal
{

  const uint32_t c_MaxDepth_u32 = 10U;

  class TimeMeasurement
  {
  public:

    explicit TimeMeasurement(const char_t* i_ContextString_pc);
    ~TimeMeasurement();

    void    start_v(const char_t* i_LocalContextString_pc);

    void    end_v();

  private:

    TimeMeasurement & operator=(const TimeMeasurement &i_data_rs);
    TimeMeasurement(const TimeMeasurement& i_data_rs);

  private:

    char_t contextString_ac[64];
    char_t localContextString_ac[c_MaxDepth_u32][64];

    Time          time_o;
    uint64_t      startTime_au64[c_MaxDepth_u32];
    uint64_t      endTime_au64[c_MaxDepth_u32];
    uint64_t      diffTime_au64[c_MaxDepth_u32];

    uint32_t      depth_u32;
  };

};// namespace osal

#endif // OSAL_TIME_MEASUREMENT_H
