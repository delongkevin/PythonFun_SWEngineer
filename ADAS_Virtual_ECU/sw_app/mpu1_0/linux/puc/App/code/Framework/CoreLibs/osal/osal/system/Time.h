/*
 * Time.h
 *
 *  Created on: 17.11.2017
 *      Author: Marcel Engelhardt
 */

#ifndef OSAL_TIME_H
#define OSAL_TIME_H

#include "platform/PlatformAPI.h"

namespace osal
{
  class Time
  {
  public:
    Time();
    ~Time();

    uint64_t getTimeNsec_u64() const;
    uint64_t getTimeUsec_u64() const;
    uint64_t getTimeMsec_u64() const;

  private:
    Time & operator=(const Time &i_data_rs);
    Time(const Time& i_data_rs);
  };

};// namespace osal

#endif // OSAL_TIME_H
