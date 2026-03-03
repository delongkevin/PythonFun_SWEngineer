//--------------------------------------------------------------------------
/// @file SoftwareWatchdogRunnable.cpp
/// @brief Contains the Software watchdog runnable implementation
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#include "SoftwareWatchdogRunnable.h"

#include <cfg/Context.h>
#include <container/JobContext.h>

#include <variants/Assets.h>

#include <osal/system/Time.h>

#include <logging/Logger.h>

namespace sysmon
{

SoftwareWatchdogRunnable::SoftwareWatchdogRunnable()
  : osal::IRunnable()
  , isRunning_b(true)
{
}

SoftwareWatchdogRunnable::~SoftwareWatchdogRunnable()
{
  // Nothing to do yet!
}

void SoftwareWatchdogRunnable::init_v()
{
  // Nothing to do yet!
}

bool_t SoftwareWatchdogRunnable::run_b()
{
  variants::ErrorManagerConfig* v_ErrMConfig_po = variants::ErrorManagerConfig::get_po(variants::c_ErrorManagerConfig_u32);
  const variants::ErrorManagerConfigComponent* v_ErrMConfigComponent_po = v_ErrMConfig_po->getErrorManagerConfigComponent_po();

  ME_Thread_Sleep_t(static_cast<uint32_t>(v_ErrMConfigComponent_po->getCheckAliveTimePeriod_u64())); // sleep 1 frames

  checkAliveState_v();

  return isRunning_b;
}

void SoftwareWatchdogRunnable::cleanup_v()
{
  // Nothing to do yet!
}

void SoftwareWatchdogRunnable::checkAliveState_v()
{
  osal::Time v_Time_o;
  variants::ErrorManagerConfig* v_ErrMConfig_po = variants::ErrorManagerConfig::get_po(variants::c_ErrorManagerConfig_u32);
  const variants::ErrorManagerConfigComponent* v_ErrMConfigComponent_po = v_ErrMConfig_po->getErrorManagerConfigComponent_po();
  const variants::ErrorManagerConfigComponent::Jobs_s* jobs_ps = v_ErrMConfigComponent_po->getJobs_ps();

  if(jobs_ps != NULL)
  {
    for(uint32_t v_I_u32 = 0; v_I_u32 < variants::e_JobCount; v_I_u32++)
    {
      container::JobContext& v_JobContext_ro = container::Context::getContext_ro(static_cast<variants::Job_e>(v_I_u32));

      uint64_t v_JobActiveTime_u64 = v_JobContext_ro.getDataContainer_ro().getActiveTime_u64();
      uint64_t v_CurrentTime_u64 = v_Time_o.getTimeMsec_u64();

      // PRQA S 3706 3 // it's know as an array, subscript operator necessary here to adress all jobs
      if((jobs_ps[v_I_u32].aliveTime_u64 > 0) && (v_JobActiveTime_u64 > 0))
      {
        if((v_CurrentTime_u64 - v_JobActiveTime_u64) > jobs_ps[v_I_u32].aliveTime_u64)
        {
          logging::Logger::log_b(logging::e_LogLvlError, logging::e_LogModeMaskPrintf, "SoftwareWatchdog: Job [%d] - Given AliveTime [%dms] - Actual AliveTime [%dms]\n", v_I_u32, jobs_ps[v_I_u32].aliveTime_u64, (v_CurrentTime_u64 - v_JobActiveTime_u64));
        }
      }
    }
  }
}


} // namespace sysmon
