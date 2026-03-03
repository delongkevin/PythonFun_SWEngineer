//--------------------------------------------------------------------------
/// @file JobSysMon.h
/// @brief Contains the System Monitor job definition
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOBSYSMON_H_
#define JOBSYSMON_H_

#include "IDataProviderSysMon.h"

#include "cfg/SoftwareWatchdogRunnable.h"
#include "cfg/SoCTempMonRunnable.h"
#include "cfg/RuntimeStatsThread.h"

#include <container/JobBase.h>

#include <osal/threading/Thread.h>

namespace sysmon
{

class JobSysMon : public container::JobBase<IDataProviderSysMon>
{
public:

  JobSysMon(container::JobDesc_s& i_JobDesc_rs, IDataProviderSysMon& i_DataProviderSysMon_ro);
  virtual ~JobSysMon();

  virtual bool_t onInit_b()                               ME_OVERRIDE;
  virtual void   onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;
  virtual bool_t onRun_b()                                ME_OVERRIDE;
  virtual void   onCleanup_v()                            ME_OVERRIDE;

private:

//  osal::Thread        socTempMonitorThread_o;
//  SoCTempMonRunnable  socTempMonitorRunnable_o;

//  osal::Thread              softwareWatchdogThread_o;
//  SoftwareWatchdogRunnable  softwareWatchdogRunnable_o;

 osal::Thread              m_runtimeStatsThread_o;
 RuntimeStatsRunnable      m_runtimeStatsRunnable_o;
};

} // namespace sysmon

#endif // JOBSYSMON_H_
