//--------------------------------------------------------------------------
/// @file LogMain.cpp
/// @brief LogMIntgr.out starting point
///
/// Creates the basic functionalities:
/// - Initializing all log modes
/// - Initializing the interface to the log user (e.g. puc_app.out)
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#include "JobLogM.h"

#include "LogM.h"

#include <cfg/LogTypes.h>
#include <cfg/LogPrintf/LogPrintf.h>
#include <cfg/LogDlt/LogDlt.h>
#include <cfg/LogDlt/DltViewerReceiver.h>


#include <cfg/Context.h>

#include <osal/networking/INetworkMsgHandler.h>
#include <osal/networking/SocketServer.h>

#include <mecl/buffer/Fifo.h>


// PRQA S 4038 EOF // uncaugth exception
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_LogM   (1u)
#endif
#if PROFILE_LogM
#include "osal/system/Time.h"
static uint32_t v_AvgLogMRuntime_u32 = 0;
static uint32_t v_LogMRunCntr_u32 = 0;
static uint32_t v_AvgLogMPeriodicity_u32 = 0;
static uint32_t v_LogMPreviousTime_u32 = 0;
static uint32_t v_LogMRuntimeData = 0;
static PerformanceStatsEnable_t PerformanceStatsEnable_dp; 
#endif

namespace logm
{

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Global variables
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static osal::Thread s_LogModeThreads_ao[logging::e_LogModeCount];

static osal::Thread s_LogMThreads_ao[logging::e_LogModeCount];



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Function declarations
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

static uint32_t createLogMode_u32(logging::LogMode_e i_LogModeId_e)
{
#if 0 //disabling socket communication for production software
  ME_Debugger_F_Printf_v("Starting Log mode (id): %d\n", i_LogModeId_e);
  

  switch (i_LogModeId_e)
  {
    case logging::e_LogModeDlt:
    {
#ifdef ME_PLATFORM_QNX
      //static osal::SocketServer s_DltViewerSocketServer_o(e_SptTcp, "192.168.1.2", 3490);
      static osal::SocketServer s_DltViewerSocketServer_o(e_SptTcp, "192.168.2.210", 3490);
#else
      static osal::SocketServer s_DltViewerSocketServer_o(e_SptTcp, "127.0.0.1", 3490);
#endif

      static logm::DltViewerReceiver s_DltViewerReceiver_o;

      s_DltViewerSocketServer_o.registerHandler_b(&s_DltViewerReceiver_o);
      logm::LogDlt::setLogInterface_v(&s_DltViewerSocketServer_o);

      static mecl::buffer::Fifo<logging::ME_MAX_LOG_BUFFER_SIZE> s_FifoBufferDlt_o;
      static logm::LogDlt    s_LogDlt_o(s_FifoBufferDlt_o);
      static osal::SocketServer s_LogMsgHandlerDlt_o(e_SptTcp, "127.0.0.1", logging::s_LogPorts_pu32[i_LogModeId_e]);
      static logm::LogM s_LogMDlt_o(s_LogDlt_o, s_LogMsgHandlerDlt_o);

      s_LogModeThreads_ao[i_LogModeId_e].start_v(&s_LogDlt_o);
      s_LogMThreads_ao[i_LogModeId_e].start_v(&s_LogMDlt_o);
      break;
    }
    case logging::e_LogModePrintf:
    {
      static mecl::buffer::Fifo<logging::ME_MAX_LOG_BUFFER_SIZE> s_FifoBufferPrintf_o;
      static logm::LogPrintf s_LogPrintf_o(s_FifoBufferPrintf_o);
      static osal::SocketServer s_LogMsgHandlerPrintf_o(e_SptTcp, "127.0.0.1", logging::s_LogPorts_pu32[i_LogModeId_e]);
      static logm::LogM s_LogMPrintf_o(s_LogPrintf_o, s_LogMsgHandlerPrintf_o);

      s_LogModeThreads_ao[i_LogModeId_e].start_v(&s_LogPrintf_o);
      s_LogMThreads_ao[i_LogModeId_e].start_v(&s_LogMPrintf_o);
      break;
    }
    default:
    {
      break;
    }
  }
#endif
  return 0;
}

// ------------------------------------------------------------------------
static void createAllLogModes_v()
{
  for (uint32_t v_I_u32 = 1; v_I_u32 < logging::e_LogModeCount; v_I_u32++)
  {
    createLogMode_u32(static_cast<logging::LogMode_e>(v_I_u32));
  }
}

// ------------------------------------------------------------------------
/// Static functions

void JobLogM::initLogModes_v()
{

  createAllLogModes_v();

  logm::s_LogMThreads_ao[logging::e_LogModeDlt].setAffinity_v(e_CpuAny);
  logm::s_LogMThreads_ao[logging::e_LogModeDlt].setPriority_v(e_PriorityNormal);

  logm::s_LogModeThreads_ao[logging::e_LogModeDlt].setAffinity_v(e_CpuAny);
  logm::s_LogModeThreads_ao[logging::e_LogModeDlt].setPriority_v(e_PriorityNormal);


  logm::s_LogMThreads_ao[logging::e_LogModePrintf].setAffinity_v(e_CpuAny);
  logm::s_LogMThreads_ao[logging::e_LogModePrintf].setPriority_v(e_PriorityNormal);

  logm::s_LogModeThreads_ao[logging::e_LogModePrintf].setAffinity_v(e_CpuAny);
  logm::s_LogModeThreads_ao[logging::e_LogModePrintf].setPriority_v(e_PriorityNormal);

  logging::Logger::init_v(static_cast<logging::LogLevel_t>(container::Context::s_MaxLogLvlError_s32), logging::e_LogModeMaskDlt);
}

// ------------------------------------------------------------------------

JobLogM::JobLogM(container::JobDesc_s& b_JobDesc_rs, IDataProviderLogM& b_DataProviderLogM_ro)
  : JobBase(b_JobDesc_rs, b_DataProviderLogM_ro)
  ,dataProvider_ro(b_DataProviderLogM_ro)
{

}

JobLogM::~JobLogM()
{

}

bool_t JobLogM::onInit_b()
{
  return true;
}

bool_t JobLogM::onRun_b()
{
  #if PROFILE_LogM
  PerformanceStatsEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  volatile uint32_t currPeriodicity = 0;
  if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
  {
    v_Start_t = __get_time_usec();
    currPeriodicity = v_Start_t - v_LogMPreviousTime_u32;
  }
  #endif
//    printf("ONRUN_B- %s\n", __PRETTY_FUNCTION__);
	ME_Thread_Sleep_t(5);
  #if PROFILE_LogM
  if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
  {
    v_End_t = __get_time_usec();
    // ME_Debugger_F_Printf_v("LogM: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
    v_LogMRunCntr_u32++; //Increment the run counter for averaging purpose
    v_AvgLogMPeriodicity_u32 = ((v_AvgLogMPeriodicity_u32 * (v_LogMRunCntr_u32 -1)) + currPeriodicity)/v_LogMRunCntr_u32; //Average Periodicity
    v_AvgLogMRuntime_u32 = ((v_AvgLogMRuntime_u32 * (v_LogMRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_LogMRunCntr_u32; //New Average  
    v_LogMRuntimeData = (((v_AvgLogMRuntime_u32/1000U)<<16U) | ((v_AvgLogMPeriodicity_u32/1000U) & 0xFFFF));
    dataProvider_ro.setLogMRuntime(v_LogMRuntimeData);
    //ME_Debugger_F_Printf_v("LogM: E: %lld P: %lld \n", v_AvgLogMRuntime_u32, v_AvgLogMPeriodicity_u32);
    v_LogMPreviousTime_u32 = v_Start_t;
  }
  #endif
  return true;
}

void JobLogM::onCleanup_v()
{

}

void JobLogM::onVariantChanged_v(bool_t i_FirstTime_b)
{

}

} // namespace logm
