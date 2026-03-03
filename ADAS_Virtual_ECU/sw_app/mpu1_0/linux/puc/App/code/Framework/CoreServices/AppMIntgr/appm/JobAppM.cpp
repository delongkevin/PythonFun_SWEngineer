//--------------------------------------------------------------------------
/// @file JobAppM.cpp
/// @brief Contains the job implementation of Application Manager
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#include "JobAppM.h"
#include "container/MessageQueue.h"

#include <osal/system/Time.h>

#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_AppM   (1u)
#endif
#if PROFILE_AppM
#include "osal/system/Time.h"
static uint32_t v_AvgAppMRuntime_u32 = 0;
static uint32_t v_AppMRunCntr_u32 = 0;
static uint32_t v_AvgAppMPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_AppMRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsEnable_dp;
#endif

namespace appm
{


void JobAppM::stateMachine_v()
{
  switch(appState_e)
  {
  case variants::e_AppStateInit:
  {
    // switch to normal State
    if (true == isAllAppsInitialized_b())
    {
      logger_o.log_b(logging::e_LogLvlInfo, "%s::Changing Application State from e_AppStateInit to e_AppStateNormal. ", context_ro.getContextName_pc());

      appState_e = variants::e_AppStateNormal;

      dataProvider_ro.setBootState_v(static_cast<uint8_t>(variants::e_PerfMBootStateComplete));

      scheduler_o.setSchedulerList_v(schedulingSchemes_at[appState_e]);
    }
    else
    {
      appState_e = variants::e_AppStateInit;
    }

    break;
  }
  case variants::e_AppStateNormal:
  {
    if(true == isChangeVariantConfig_b())
    {
      logger_o.log_b(logging::e_LogLvlInfo, "%s::Changing Application State from e_AppStateNormal to e_AppStateVariantSwitch. ", context_ro.getContextName_pc());

      appState_e = variants::e_AppStateVariantSwitch;

      scheduler_o.setSchedulerList_v(schedulingSchemes_at[appState_e]);
    }
    else
    {
      appState_e = variants::e_AppStateNormal;
    }

    break;
  }
  case variants::e_AppStateVariantSwitch:
  {
    // broadcast variant config changed
    for (uint32_t v_I_u32 = 0U; v_I_u32 < variants::e_JobCount; ++v_I_u32)
    {
      variants::Job_e v_ReceiverId_e = static_cast<variants::Job_e>(v_I_u32);
      container::Message v_Msg_o;
      v_Msg_o.setMessageType_v(container::e_MtFramework);
      v_Msg_o.setOpcode_v(container::e_OpFwVariantConfigChanged);
      v_Msg_o.setSenderID_v(variants::e_JobAppM);
      v_Msg_o.setReceiverID_v(v_ReceiverId_e);
      container::Context::getContext_ro(v_ReceiverId_e).getSystemQueue_ro().add_b(v_Msg_o, true);
    }

    logger_o.log_b(logging::e_LogLvlInfo, "%s::Changing Application State from e_AppStateVariantSwitch to e_AppStateNormal. ", context_ro.getContextName_pc());

    appState_e = variants::e_AppStateNormal;

    scheduler_o.setSchedulerList_v(schedulingSchemes_at[appState_e]);

    break;
  }
  default:
  {
    // invalid
  }

  }
}

JobAppM::JobAppM(container::JobContext& i_Context_ro, IDataProviderAppM& b_DataProvider_ro)
  : osal::IRunnable()
  , IMessageHandler()
  , context_ro(i_Context_ro)
  , dispatcher_o(i_Context_ro.getExternalQueue_ro(),
                 i_Context_ro.getSystemQueue_ro(),
                 i_Context_ro.getInternalQueue_ro(),
                 i_Context_ro.getTriggerSemaphore_ro())
  , dataProvider_ro(b_DataProvider_ro)
  , frameID_u32(0)
  , appState_e(variants::e_AppStateInit)
  , isRunning_b(true)
  , changeVariantConfig_b(false)
  , allAppsInitialized_b(false)
{
  // attach this job to the message handler
  dispatcher_o.setHandler_v(*this);
}

JobAppM::~JobAppM()
{
}

void JobAppM::initSchedulingSchemes_v()
{
  using namespace variants;

  JobConfig* v_Config_po = JobConfig::get_po(c_JobConfig_u32);
  if (NULL != v_Config_po)
  {
    const JobConfigComponent* v_ConfigComp_po = v_Config_po->getJobConfigComponent_po();

    if (NULL != v_ConfigComp_po)
    {
      // for each scheduling scheme (AppState)
      const JobConfigComponent::SchedulingSchemes_s* c_Schemes_ps = v_ConfigComp_po->getSchedulingSchemes_ps();
      for (uint32_t v_SchemeIdx_u32 = 0; v_SchemeIdx_u32 < e_AppStateCount; ++v_SchemeIdx_u32)
      {
        const JobConfigComponent::SchedulingSchemes_s* c_CurrScheme_ps = &c_Schemes_ps[v_SchemeIdx_u32]; // PRQA S 3706 // subscipt operator

        // special case for initialized check, leave out applications with execution order -1
        if (static_cast<AppState_t>(v_SchemeIdx_u32) == v_ConfigComp_po->getInitalizationScheme_e())
        {
          // for each Job
          for (uint32_t v_Job_u32 = 0U; v_Job_u32 < e_JobCount; ++v_Job_u32)
          {
            const JobConfigComponent::Jobs_s* v_Job_ps = & c_CurrScheme_ps->jobs_as[v_Job_u32];

            // if it's -1, don't check for initialized state in execute done
            if (v_Job_ps->executionOrder_s32 == -1)
            {
              // so set this job to already initialized
              initializedJobs_ab[v_Job_u32] = true;
            }
            else
            {
              // every other value means check initialization state
              initializedJobs_ab[v_Job_u32] = false;
            }
          } // for v_Job_u32
        } 

        // build the vectors which are the input for the JobScheduler.
        // max execution order may be the number of jobs (assuming only sequential scheduled jobs)
        schedulingSchemes_at[v_SchemeIdx_u32].clear();

        for (sint32_t v_ExecOrder_s32 = 0U; v_ExecOrder_s32 < e_JobCount; ++v_ExecOrder_s32)
        {
          // add jobs to this list if exec order matches
          JobList_t v_JobList_o;

          // for each Job
          for (uint32_t v_Job_u32 = 0U; v_Job_u32 < e_JobCount; ++v_Job_u32)
          {
            const JobConfigComponent::Jobs_s* v_Job_ps = & c_CurrScheme_ps->jobs_as[v_Job_u32];

            if (v_Job_ps->executionOrder_s32 == v_ExecOrder_s32)
            {
              v_JobList_o.push_back(JobInfo_s(static_cast<variants::Job_e>(v_Job_u32)));
            }

          } // for v_Job_u32

          if (false == v_JobList_o.empty())
          {
            schedulingSchemes_at[v_SchemeIdx_u32].push_back(v_JobList_o);
          }
        } // for v_ExecOrder_s32
      } // for v_SchemeIdx_u32
    } // if configComp
  } // if config
}

void JobAppM::init_v()
{
  logger_o.config_b(static_cast<logging::LogLevel_t>(context_ro.getMaxLogLevel_s32()),
                    context_ro.getContextName_pc(),
                    "Run",
                    (logging::e_LogModeMaskDlt));

  logger_o.log_b(logging::e_LogLvlInfo, "%s::init_v()", context_ro.getContextName_pc());

  // Initalize JobScheduler target frame rate
  variants::JobConfig* v_JobConfig_po = variants::JobConfig::get_po(variants::c_JobConfig_u32);
  const variants::JobConfigComponent* v_JobConfigComponent_po = v_JobConfig_po->getJobConfigComponent_po();
  uint64_t v_TargetSchedulingRate = v_JobConfigComponent_po->getTargetSchedulingRate_u64();
  scheduler_o.setTargetSchedulingRate_v(v_TargetSchedulingRate);

  initSchedulingSchemes_v();

  appState_e = variants::e_AppStateInit;
  frameID_u32 = 0;

  dispatcher_o.reset_v();

  scheduler_o.setSchedulerList_v(schedulingSchemes_at[appState_e]);

  dataProvider_ro.setBootState_v(static_cast<uint8_t>(variants::e_PerfMBootStateInit));

  isRunning_b = true;
}


bool_t JobAppM::run_b()
{

#if PROFILE_AppM
  PerformanceStatsEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  volatile uint32_t currPeriodicity = 0;
  if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
  {
    v_Start_t = __get_time_usec();
    currPeriodicity = v_Start_t - v_PreviousTime_u32;
  }
#endif

  container::Message v_Msg_o;
  osal::Time v_Time_o;

  // trigger execution
  scheduler_o.update_v(appState_e);

  dispatcher_o.dispatch_v(true);

  // inform Error Manager
  context_ro.getDataContainer_ro().setActivetime_v(v_Time_o.getTimeMsec_u64());

#if PROFILE_AppM
  if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
  {
    v_End_t = __get_time_usec();
    // ME_Debugger_F_Printf_v("AppM: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
    v_AppMRunCntr_u32++; //Increment the run counter for averaging purpose
    v_AvgAppMPeriodicity_u32 = ((v_AvgAppMPeriodicity_u32 * (v_AppMRunCntr_u32 -1)) + currPeriodicity)/v_AppMRunCntr_u32; //Average Periodicity
    v_AvgAppMRuntime_u32 = ((v_AvgAppMRuntime_u32 * (v_AppMRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_AppMRunCntr_u32; //New Average  
    //ME_Debugger_F_Printf_v("AppM: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
    v_AppMRuntimeData = (((v_AvgAppMRuntime_u32/1000U)<<16U) | ((v_AvgAppMPeriodicity_u32/1000U) & 0xFFFF));
    dataProvider_ro.setAppMRuntime(v_AppMRuntimeData);
    //ME_Debugger_F_Printf_v("AppM: E: %lld P: %lld \n", v_AvgAppMRuntime_u32, v_AvgAppMPeriodicity_u32);
    v_PreviousTime_u32 = v_Start_t;
  }
#endif
  // TODO: remove while loop, everything is handled in upper class (e.g. Thread)
  return true;
}

void JobAppM::cleanup_v()
{
  logger_o.log_b(logging::e_LogLvlInfo, "%s::cleanup_v()", context_ro.getContextName_pc());
  dispatcher_o.reset_v();
}

void JobAppM::handleMessage_v(const container::Message& i_Msg_ro)
{
  logger_o.log_b(logging::e_LogLvlVerbose, "%s::handleMessage_v() - Sender: %d", context_ro.getContextName_pc(), i_Msg_ro.getSenderID_s32());
  logger_o.log_b(logging::e_LogLvlVerbose, "%s::handleMessage_v() - MessageType: %d OpCode: %d", context_ro.getContextName_pc(), i_Msg_ro.getMessageType_s32(), i_Msg_ro.getOpcode_s32());

  switch(i_Msg_ro.getMessageType_s32())
  {
    case container::e_MtFramework:
    {
      handleFrameworkMessage_v(i_Msg_ro);
      break;
    }
    default:
    {
      logger_o.log_b(logging::e_LogLvlInfo, "%s::handleMessage_v() - MessageType: %d ", context_ro.getContextName_pc(), i_Msg_ro.getMessageType_s32());
      break;
    }
  }
}

void JobAppM::handleFrameworkMessage_v(const container::Message& i_Msg_ro)
{
  variants::Job_e v_Job_e = static_cast<variants::Job_e>(i_Msg_ro.getSenderID_s32());

  switch(i_Msg_ro.getOpcode_s32())
  {
    case container::e_OpFwShutdown:
    {
      logger_o.log_b(logging::e_LogLvlInfo, "%s::ExitCondition received", context_ro.getContextName_pc());
      isRunning_b = false;
      break;
    }
    case container::e_OpFwAppInitDone:
    {
      if ((v_Job_e >= 0) && (v_Job_e < variants::e_JobCount))
      {
        initializedJobs_ab[v_Job_e] = true;
        bool_t v_LastJobExecuted_b = scheduler_o.jobExecuted_b(v_Job_e);

        // check if this was the last job in the scheduler list and if so, increment the frame count
        if (true == v_LastJobExecuted_b)
        {
          stateMachine_v();
        }

        logger_o.log_b(logging::e_LogLvlInfo, "%s::AppInitDone: %d received", context_ro.getContextName_pc(), i_Msg_ro.getSenderID_s32());
      }
      else
      {
        logger_o.log_b(logging::e_LogLvlInfo, "%s::Invalid Job initialized: %d", context_ro.getContextName_pc(), i_Msg_ro.getSenderID_s32());
      }

      break;
    }
    case container::e_OpFwAppExecute:
    {
      logger_o.log_b(logging::e_LogLvlInfo, "%s::AppMExecute run msg", context_ro.getContextName_pc());
      break;
    }
    case container::e_OpFwAppExecuteDone:
    {
      logger_o.log_b(logging::e_LogLvlVerbose, "%s::AppMExecution Done for Sender: %d \n", context_ro.getContextName_pc(), i_Msg_ro.getSenderID_s32());

      // tell scheduler that we received a job execution done event
      bool_t v_LastJobExecuted_b = scheduler_o.jobExecuted_b(v_Job_e);

      // check if this was the last job in the scheduler list and if so, increment the frame count
      if (true == v_LastJobExecuted_b)
      {
        stateMachine_v();

        frameID_u32 = dataProvider_ro.getFrameID_u32(); // get frame ID
        frameID_u32++;                                  // increment
        dataProvider_ro.setFrameID_v(frameID_u32);      // write frame ID back to shared memory

        if(frameID_u32 == 3000)
        {
          MEP_SHUTDOWN();
        }

        logger_o.log_b(logging::e_LogLvlVerbose, "%s::AppMExecution Done %d --- Reached new Frame ID %d ---", context_ro.getContextName_pc(), i_Msg_ro.getSenderID_s32(), frameID_u32);
      }

      break;
    }
    default:
    {
      logger_o.log_b(logging::e_LogLvlError, "%s::OpCode: %d not supported", context_ro.getContextName_pc(), i_Msg_ro.getOpcode_s32());
      break;
    }
  }
}

bool_t JobAppM::isAllAppsInitialized_b()
{
  allAppsInitialized_b = true;

  for (sint32_t v_Job_s32 = 0; v_Job_s32 < variants::e_JobCount; ++v_Job_s32)
  {
    if (false == initializedJobs_ab[v_Job_s32])
    {
      // set to false, if one job is false
      allAppsInitialized_b = false;
    }
  }

  return allAppsInitialized_b;
}

bool_t JobAppM::isChangeVariantConfig_b()const
{
  return changeVariantConfig_b;
}

} // namespace appm

