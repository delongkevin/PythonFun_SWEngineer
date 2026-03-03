//--------------------------------------------------------------------------
/// @file JobSys.cpp
/// @brief Contains the job implementation of the System Job Manager.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com), Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#include "JobSys.h"

#include <platform/PlatformDefines.h>

#include <container/MessageTypes.h>

#include <sigm/JobSigM.h>
#include <appm/JobAppM.h>
#include <varm/JobVarM.h>
#include <logm/JobLogM.h>
#include <oc/JobOc.h>

#include <JobOvl3D.h>
#include <tiovx/JobTIOVX.h>
#include <EOL/JobAlgoEol.h>
#include <sysmon/JobSysMon.h>
#include <calsm/JobCalSM.h>
#include <THA/JobTHA.h>
#include <TAD2/JobTAD2.h>
#include <DLD/JobDLD.h>

#include <osal/threading/Thread.h>
#include <osal/networking/SocketServer.h>
#include <osal/networking/UDPSenderReceiver.h>
//#include <bsp/driver/Can.h>

#include <bsp/driver/IpcCom.h>
#include <logging/Logger.h>

// PRQA S 1021 EOF // using ME_INVALID_PROCESS_ID
// PRQA S 4633 EOF // using static objects for container
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_Sys   (1u)
#endif
#if PROFILE_Sys
#include "osal/system/Time.h"
#endif

#if !defined(ME_PLATFORM_WIN) && !defined(ME_PLATFORM_LINUX)
#if 0
#define USE_FORK
#endif
#endif

namespace sys
{

JobSystem::JobSystem(container::JobContext& b_JobContext_ro)
 : osal::IRunnable()
 , container::IMessageHandler()
 , dataProvider_o()
 , dataProviderVarM_o(dataProvider_o)
 , dataProviderSigM_o(dataProvider_o)
 , dataProviderAppM_o(dataProvider_o)
 , dataProviderOvl3D_o(dataProvider_o)
 , dataProviderEol_o(dataProvider_o)
 , dataProviderSysMon_o(dataProvider_o)
 , dataProviderLogM_o(dataProvider_o)
 , dataProviderOC_o(dataProvider_o)
 , dataProviderTiovx_o(dataProvider_o)    
  , dataProviderCALSM_o(dataProvider_o)
 , dataProviderTHA_o(dataProvider_o)
 , dataProviderTAD2_o(dataProvider_o)
 , dataProviderDLD_o(dataProvider_o)
 , dispatcher_o(b_JobContext_ro.getExternalQueue_ro(),
                b_JobContext_ro.getSystemQueue_ro(),
                b_JobContext_ro.getInternalQueue_ro(),
                b_JobContext_ro.getTriggerSemaphore_ro())
 , FatherPID(ME_INVALID_PROCESS_ID)
 , isRunning_b(true)
{
  dispatcher_o.setHandler_v(*this);
}

JobSystem::~JobSystem()
{
}


void JobSystem::init_v()
{
  logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "ONLY JobSystem::init_v()");

  FatherPID = ME_Process_GetCurrentID_t();

  ME_Thread_SetName_t(NULL, "SYS");

  createAllJobs_v();
}

void JobSystem::createAllJobs_v()
{
  for(uint32_t v_I_u32 = 0; v_I_u32 < (static_cast<uint32_t>(variants::e_JobCount)); v_I_u32++)
  {
    processIds_at[v_I_u32] = ME_INVALID_PROCESS_ID;

    if(v_I_u32 != variants::e_JobSys)
    {
      if(0 == createJob_u32(static_cast<variants::Job_e>(v_I_u32)))
      {
        break;
      }
    }
  }
}

sint32_t JobSystem::createJob_u32(variants::Job_e i_JobId_e)
{
  sint32_t v_RetVal_s32 = -1;
  container::JobContext& v_JobContext_ro = container::Context::getContext_ro(i_JobId_e);

  osal::IRunnable* v_JobRunnable_po = NULL;

#if defined(USE_FORK)
  if ((processIds_at[i_JobId_e] = ME_Process_Fork_t()) == 0) // PRQA S 3902 // this is needed to directly assign ID
  { // PRQA S 4113 // cannot move v_JobRunnable_o into #ifdef
#endif

    switch(i_JobId_e)
    {
      case variants::e_JobAppM:
      {
        static appm::JobAppM v_Job_o(v_JobContext_ro, dataProviderAppM_o);
        v_JobRunnable_po = &v_Job_o;
        break;
      }
      case variants::e_JobSigM:
      {
        container::JobDesc_s v_DescSigM_s(v_JobContext_ro, // ContextOwn
                                          container::Context::getContext_ro(variants::e_JobAppM)); // ContextDispatcher

#if defined(ME_PLATFORM_WIN)
        static osal::SocketServer v_NetworkInterface_o(e_SptTcp, NULL, 7000);
#elif defined(ME_PLATFORM_QNX)
#if 0
        static osal::SocketServer v_NetworkInterface_o(e_SptTcp, NULL, 7000);
#else
          static bsp::IpcCom      v_NetworkInterface_o; // for QNX

          v_NetworkInterface_o.init_v(1);  //IPC Rx/Tx channel
          v_NetworkInterface_o.open_b();

#endif // switch
#else
        static osal::SocketServer v_NetworkInterface_o(e_SptTcp, NULL, 7000);
#endif // ME_PLATFORM_XXX

        static sigm::JobSigM v_Job_o(v_DescSigM_s, dataProviderSigM_o, &v_NetworkInterface_o);
        v_JobRunnable_po = &v_Job_o;
        break;
      }
      case variants::e_JobVarM:
      {
        container::JobDesc_s v_Desc_s(v_JobContext_ro,  // ContextOwn
                                      container::Context::getContext_ro(variants::e_JobAppM)); // ContextDispatcher

        static varm::JobVarM v_Job_o(v_Desc_s, dataProviderVarM_o);
        v_JobRunnable_po = &v_Job_o;
        break;
      }
      case variants::e_JobLogM:
      {
        container::JobDesc_s v_Desc_s(v_JobContext_ro,  // ContextOwn
                                      container::Context::getContext_ro(variants::e_JobAppM)); // ContextDispatcher

        static logm::JobLogM v_Job_o(v_Desc_s, dataProviderLogM_o);
        v_JobRunnable_po = &v_Job_o;
        break;
      }
      case variants::e_JobEol:
      {
        container::JobDesc_s v_Desc_s(v_JobContext_ro,  // ContextOwn
                                      container::Context::getContext_ro(variants::e_JobAppM)); // ContextDispatcher
        static eol::JobAlgoEol v_Job_o(v_Desc_s, dataProviderEol_o);
        v_JobRunnable_po = &v_Job_o;
        break;
      }
      case variants::e_JobOVL3D:
      {
        container::JobDesc_s v_Desc_s(v_JobContext_ro,  // ContextOwn
                                      container::Context::getContext_ro(variants::e_JobAppM)); // ContextDispatcher

        static ovl3d::JobOvl3D v_Job_o(v_Desc_s, dataProviderOvl3D_o);
        v_JobRunnable_po = &v_Job_o;
        break;
      }
      case variants::e_JobSysMon:
      {
        container::JobDesc_s v_Desc_s(v_JobContext_ro,  // ContextOwn
                                      container::Context::getContext_ro(variants::e_JobAppM)); // ContextDispatcher

        static sysmon::JobSysMon v_Job_o(v_Desc_s, dataProviderSysMon_o);
        v_JobRunnable_po = &v_Job_o;

        break;
      }
      case variants::e_JobTIOVX:
      {
        container::JobDesc_s v_Desc_s(v_JobContext_ro,  // ContextOwn
                                      container::Context::getContext_ro(variants::e_JobAppM)); // ContextDispatcher
        static tiovx::JobTIOVX v_Job_o(v_Desc_s, dataProviderTiovx_o);
        v_JobRunnable_po = &v_Job_o;

        break;
      }
      case variants::e_JobOC:
      {
        container::JobDesc_s v_Desc_s(v_JobContext_ro, // ContextOwn
                                      container::Context::getContext_ro(variants::e_JobAppM)); // Context Dispatcher
        static oc::JobOC v_Job_o(v_Desc_s, dataProviderOC_o);
        v_JobRunnable_po = &v_Job_o;

        break;
      }
      case variants::e_JobCalSM:
      {
        container::JobDesc_s v_Desc_s(v_JobContext_ro, // ContextOwn
                                      container::Context::getContext_ro(variants::e_JobAppM)); // Context Dispatcher
        static calsm::JobCalSM v_Job_o(v_Desc_s, dataProviderCALSM_o);
        v_JobRunnable_po = &v_Job_o;

        break;
      }
	  case variants::e_JobTHA:
      {
        container::JobDesc_s v_Desc_s(v_JobContext_ro, // ContextOwn
                                      container::Context::getContext_ro(variants::e_JobAppM)); // Context Dispatcher
        static tha::JobTHA v_Job_o(v_Desc_s, dataProviderTHA_o);
        v_JobRunnable_po = &v_Job_o;

        break;
      }
	  case variants::e_JobTAD2:
	  {
	    container::JobDesc_s v_Desc_s(v_JobContext_ro, // ContextOwn
	                                  container::Context::getContext_ro(variants::e_JobAppM)); // Context Dispatcher
	    static TAD2::JobTAD2 v_Job_o(v_Desc_s, dataProviderTAD2_o);
	    v_JobRunnable_po = &v_Job_o;
	    break;
	  }
    case variants::e_JobDLD:
	  {
	    container::JobDesc_s v_Desc_s(v_JobContext_ro, // ContextOwn
	                                  container::Context::getContext_ro(variants::e_JobAppM)); // Context Dispatcher
	    static dld::JobDLD v_Job_o(v_Desc_s, dataProviderDLD_o);
	    v_JobRunnable_po = &v_Job_o;
	    break;
	  }

      default:
      {
        logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "JobSystem::createJob_u32() - Create Job [%d] not supported", i_JobId_e);
        v_RetVal_s32 = -1;
        break;
      }
    }

    if(v_JobRunnable_po != NULL)
    {

#ifdef ME_PLATFORM_RTOS
      threadIds_at[i_JobId_e].start_v(v_JobRunnable_po);
      container::Context::setThreadConfig_v(threadIds_at[i_JobId_e], i_JobId_e); // TODO: Main Thread is named like the last created thread
#else
      container::Context::setThreadConfig_v(threadIds_at[i_JobId_e], i_JobId_e); // TODO: Main Thread is named like the last created thread
      threadIds_at[i_JobId_e].start_v(v_JobRunnable_po);
#endif
    }

#if defined(USE_FORK)
  }
  v_RetVal_s32 = processIds_at[i_JobId_e];
#endif

  return v_RetVal_s32;
}

bool_t JobSystem::run_b()
{
  #if PROFILE_Sys
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  v_Start_t = __get_time_usec();
  #endif

  while( (ME_Process_GetCurrentID_t() == FatherPID) && (true == isRunning_b) )
  {
    dispatcher_o.dispatch_v(true);
  }

  if( ME_Process_GetCurrentID_t() == FatherPID )
  {
    shutdownAllJobs_v();

    (void)ME_Thread_Sleep_t(500);

    logging::Logger::log_b(logging::e_LogLvlInfo, logging::e_LogModeMaskPrintf, "JobSystem::Kill Processes");
    killAllJobs_v();
  }

  if(ME_Process_GetCurrentID_t() != FatherPID)
  {
    ME_Process_WaitForSigTerm_t();
  }

  #if PROFILE_Sys
  v_End_t = __get_time_usec();
  // ME_Debugger_F_Printf_v("Sys: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
  #endif

  // TODO: remove while loop, everything is handled in upper class (e.g. Thread)
  return true;
}

void JobSystem::cleanup_v()
{
  // Nothing to do yet!
}

void JobSystem::handleMessage_v(const container::Message& b_Msg_ro)
{
  if(b_Msg_ro.getMessageType_s32() == container::e_MtFramework)
  {
    if(b_Msg_ro.getOpcode_s32() == container::e_OpFwAppRestart)
    {
      restartJob_v(static_cast<variants::Job_e>(b_Msg_ro.getParameter1_s32()));
    }
  }
}

void JobSystem::shutdownAllJobs_v()
{
  for(sint32_t v_i_s32 = (static_cast<uint32_t>(variants::e_JobCount) - 2); v_i_s32 >= 0; v_i_s32--)
  {
    if(v_i_s32 != variants::e_JobSys)
    {
      shutdownJob_v(static_cast<variants::Job_e>(v_i_s32));
    }
  }
}

void JobSystem::shutdownJob_v(variants::Job_e i_JobId_e)
{
  container::Message v_Msg_o;
  v_Msg_o.setMessageType_v(container::e_MtFramework);
  v_Msg_o.setSenderID_v(variants::e_JobSys);
  v_Msg_o.setReceiverID_v(i_JobId_e);
  v_Msg_o.setOpcode_v(container::e_OpFwShutdown);
  v_Msg_o.setParameter1_v(0);

  container::Context::getContext_ro(i_JobId_e).getSystemQueue_ro().add_b(v_Msg_o, true);
}

void JobSystem::waitForAllJobs_v() const
{
    for(sint32_t v_i_s32 = (static_cast<uint32_t>(variants::e_JobCount) - 2); v_i_s32 >= 0; v_i_s32--)
    {
      waitForJob_v(static_cast<variants::Job_e>(v_i_s32));
    }
}

void JobSystem::waitForJob_v(variants::Job_e i_JobId_e) const
{
  threadIds_at[i_JobId_e].join_v();
}

void JobSystem::killAllJobs_v()
{
  for(uint32_t v_i_u32 = 0; v_i_u32 < (static_cast<uint32_t>(variants::e_JobCount)); v_i_u32++)
  {
    if(v_i_u32 != variants::e_JobSys)
    {
      killJob_v(static_cast<variants::Job_e>(v_i_u32));
    }
  }
}

void JobSystem::killJob_v(variants::Job_e i_JobId_e)
{
  threadIds_at[i_JobId_e].terminate_v();
#if defined(USE_FORK)
  PlatformError_t v_Result_t;
  v_Result_t = ME_Process_Kill_t(processIds_at[i_JobId_e]);
  Assert(v_Result_t == e_PeOk);
#endif
}

void JobSystem::restartJob_v(variants::Job_e i_JobId_e)
{
  if(i_JobId_e == variants::e_JobAppM)
  {
    shutdownAllJobs_v();
#if !defined(USE_FORK)
    waitForAllJobs_v();
#endif
    killAllJobs_v();
    container::Context::resetContexts_v();
    createAllJobs_v();
  }
  else
  {
    shutdownJob_v(i_JobId_e);
#if !defined(USE_FORK)
    waitForJob_v(i_JobId_e);
#endif
    killJob_v(i_JobId_e);
    createJob_u32(i_JobId_e);
  }
}

void JobSystem::triggerShutdown_v()
{
  isRunning_b = false;
}

} // namespace sys
