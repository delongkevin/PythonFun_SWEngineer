//--------------------------------------------------------------------------
/// @file JobScheduler.h
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

#ifndef APP_SCHEDULER_H
#define APP_SCHEDULER_H

#include <platform/PlatformAPI.h>
#include <cfg/ContextTypes.h>
#include <osal/system/Time.h>

// PRQA S 2100 EOF // public members in a struct used by design

#include <variants/Enums.h>

namespace appm
{

// contains useful information for each job
struct JobInfo_s
{
  bool executed_b;
  bool executing_b;
  variants::Job_e job_e;
  uint64_t executionTime_u64;
  uint64_t executionStart_u64;
  uint64_t executionEnd_u64;

  explicit JobInfo_s(variants::Job_e i_Job_e)
    : executed_b(false)
    , executing_b(false)
    , job_e(i_Job_e)
    , executionTime_u64(0UL)
    , executionStart_u64(0UL)
    , executionEnd_u64(0UL)
  {
  }
};


typedef mepl::vector<JobInfo_s> JobList_t;
typedef mepl::vector<JobList_t> SchedulderList_t;

class JobScheduler
{
public:
  // --------------------------------------------------------------------------
  /// Constructor
  // --------------------------------------------------------------------------
  JobScheduler();

  // --------------------------------------------------------------------------
  /// Destructor
  // --------------------------------------------------------------------------
  ~JobScheduler();

  // --------------------------------------------------------------------------
  /// Sets the desired target frame rate. 
  /// @param[in] i_TargetFrameRate_u64  the desired target frame rate. specify 0 if it shall be ignored
  /// @return void
  // --------------------------------------------------------------------------
  void setTargetSchedulingRate_v(uint64_t i_TargetFrameRate_u64);

  // --------------------------------------------------------------------------
  /// setTargetFrameRate_v
  /// @param[in] i_Jobs_t The scheduler list to execute, usually contains just a list of jobs configured via Variant Management
  /// @return void
  // --------------------------------------------------------------------------
  void setSchedulerList_v(const SchedulderList_t& i_Jobs_t);

  // --------------------------------------------------------------------------
  /// Retrieves the current job from the Scheduler List and executes the configured jobs in order
  /// @param[in] i_AppState_e The scheduler will update due to the current AppState, e.g. sending Init Message or Execute Message
  /// @return void
  // --------------------------------------------------------------------------
  void update_v(variants::AppState_t i_AppState_e);

  // --------------------------------------------------------------------------
  /// jobExecuted_b
  /// @param[in] i_Job_e The job which was executed
  /// @return true if last job in the Scheduler List was executed
  // --------------------------------------------------------------------------
  bool_t jobExecuted_b(variants::Job_e i_Job_e);

private:
  size_t index_t;
  osal::Time time_o;
  uint64_t targetSchedulingRate_u64;
  SchedulderList_t jobs_t;
};

} // namespace appm

#endif // APP_SCHEDULER_H
