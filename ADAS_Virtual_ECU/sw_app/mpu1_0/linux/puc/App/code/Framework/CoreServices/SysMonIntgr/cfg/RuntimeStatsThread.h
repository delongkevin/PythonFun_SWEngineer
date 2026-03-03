//--------------------------------------------------------------------------
/// @file RuntimeStatsThread.h
/// @brief Contains the Software watchdog runnable definitions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Shreyas P (shreyas.pophli@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef RUNTIMESTATRUNNABLE_H_
#define RUNTIMESTATRUNNABLE_H_

#include <platform/PlatformAPI.h>
#include <osal/threading/IRunnable.h>
#include "sysmon/IDataProviderSysMon.h"

namespace sysmon
{
class IDataProviderSysMon;

class RuntimeStatsRunnable : public osal::IRunnable
{
public:

  explicit RuntimeStatsRunnable(IDataProviderSysMon &i_DataProviderSysMon_po);

  virtual ~RuntimeStatsRunnable();

  virtual void   init_v() ME_OVERRIDE;

  virtual bool_t run_b() ME_OVERRIDE;

  virtual void   cleanup_v() ME_OVERRIDE;

public:

  //void           checkAliveState_v();

private:

  bool_t         isRunning_b;

  IDataProviderSysMon &m_dataProvider_ro; 

  RunTimeStats_MPU1_0_t m_RunTimeStats_MPU1_0;

};

}  // namespace sysmon

#endif //RUNTIMESTATRUNNABLE_H_
