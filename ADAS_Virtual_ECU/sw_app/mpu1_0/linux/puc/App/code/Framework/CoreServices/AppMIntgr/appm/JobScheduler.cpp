//--------------------------------------------------------------------------
/// @file JobScheduler.cpp
/// @brief Job Scheduler executes a scheduler list, setting the target frame 
/// rate and tracking useful information for each job
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#include "JobScheduler.h"
#include <container/Message.h>
#include <cfg/Context.h>
#include <container/MessageQueue.h>
#include <container/JobContext.h>


namespace appm
{

JobScheduler::JobScheduler()
  : index_t(0)
  , time_o()
  , targetSchedulingRate_u64(0UL)
{
}

JobScheduler::~JobScheduler()
{

}

void JobScheduler::setTargetSchedulingRate_v(uint64_t i_TargetSchedulingRate_u64)
{
  targetSchedulingRate_u64 = i_TargetSchedulingRate_u64;
}

void JobScheduler::setSchedulerList_v(const SchedulderList_t& i_Jobs_t)
{
  jobs_t = i_Jobs_t;
  index_t = 0;
}

void JobScheduler::update_v(variants::AppState_t i_AppState_e)
{
  JobList_t& current = jobs_t.at(index_t);

  for (size_t i = 0; i < current.size(); ++i)
  {
    if ((false == current[i].executing_b) && (false == current[i].executed_b))
    {
      current[i].executing_b = true;

      container::Message v_Msg_o;
      v_Msg_o.setMessageType_v(container::e_MtFramework);

      switch(i_AppState_e)
      {
      case variants::e_AppStateInit:
      {
        v_Msg_o.setOpcode_v(container::e_OpFwAppInit);
        break;
      }
      case variants::e_AppStateNormal:
      {
        v_Msg_o.setOpcode_v(container::e_OpFwAppExecute);
        break;
      }
      case variants::e_AppStateVariantSwitch:
      {
        v_Msg_o.setOpcode_v(container::e_OpFwVariantConfigChanged);
        break;
      }
      default:
      {
        v_Msg_o.setOpcode_v(container::e_OpFwInvalid);
        break;
      }
      }

      v_Msg_o.setSenderID_v(variants::e_JobAppM);
      v_Msg_o.setReceiverID_v(current[i].job_e);
#if ENABLE_DEBUG
	    ME_Debugger_F_Printf_v("set-receiver-id: job=%d, queue=%p\n", current[i].job_e, &container::Context::getContext_ro(current[i].job_e).getSystemQueue_ro());
#endif

      container::Context::getContext_ro(current[i].job_e).getSystemQueue_ro().add_b(v_Msg_o, true);

      current[i].executionTime_u64 = 0UL;
      current[i].executionStart_u64 = time_o.getTimeMsec_u64();
    }
  }
}

bool_t JobScheduler::jobExecuted_b(variants::Job_e i_Job_e)
{
  JobList_t& current = jobs_t.at(index_t);

  bool_t allSubJobsExecuted_b = true;

  for (size_t i = 0; i < current.size(); ++i)
  {
    if (current[i].job_e == i_Job_e)
    {
      current[i].executed_b = true;
      current[i].executing_b = false; // no longer executing this job

      current[i].executionEnd_u64 = time_o.getTimeMsec_u64();
	  
      current[i].executionTime_u64 = (current[i].executionEnd_u64 - current[i].executionStart_u64); 
    }

    // use this if-statement to avoid QAC warning 3003/3709/3054
    if (false == current[i].executed_b)
    {
      allSubJobsExecuted_b = false; // set to false if one job out of list is false
    }
  }

  if (true == allSubJobsExecuted_b)
  {
    ++index_t;
  }

  // executed all applications
  bool_t v_AllJobsExecuted_b = (index_t >= jobs_t.size());

  if (true == v_AllJobsExecuted_b)
  {
    // reset index, loop again
    index_t = 0;

    // calculate the execution time for each application
    uint64_t v_ExecutionTime_u64 = 0UL;

    // reset all flags
    size_t v_jobSize_t = jobs_t.size();
    for (size_t v_Job_t = 0; v_Job_t < v_jobSize_t; ++v_Job_t)
    {
      JobList_t& v_SubJobs_t = jobs_t[v_Job_t];

      // the execution time for the longest taking sub job 
      uint64_t v_MaxExecTimeSubJobs_u64 = 0UL;

      for (size_t i = 0; i < v_SubJobs_t.size(); ++i)
      {
        v_SubJobs_t[i].executed_b = false;
        v_SubJobs_t[i].executing_b = false;

        // update longest job
        if (v_SubJobs_t[i].executionTime_u64 > v_MaxExecTimeSubJobs_u64)
        {
          v_MaxExecTimeSubJobs_u64 = v_SubJobs_t[i].executionTime_u64;
        }
      }

      // add the job that tooks the longest time
      v_ExecutionTime_u64 += v_MaxExecTimeSubJobs_u64;
    }

    // only check target frame rate if its above zero and the execution time did exceed
    if ( (targetSchedulingRate_u64 > 0) && (targetSchedulingRate_u64 > v_ExecutionTime_u64) )
    {
      uint64_t v_SleepingMS_u64 = targetSchedulingRate_u64 - v_ExecutionTime_u64;
      (void)ME_Thread_Sleep_t(static_cast<uint32_t>(v_SleepingMS_u64));
    }
  }

  return v_AllJobsExecuted_b;
}

} // namespace appm
