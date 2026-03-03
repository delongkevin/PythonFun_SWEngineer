//--------------------------------------------------------------------------
/// @file RuntimeStatsThread.cpp
/// @brief Contains the Software watchdog runnable implementation
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Shreyas P (shreyas.pophli@magna.com)
///
//  --------------------------------------------------------------------------

#include "RuntimeStatsThread.h"

#include <cfg/Context.h>
#include <container/JobContext.h>

#include <variants/Assets.h>

#include <osal/system/Time.h>

#include <logging/Logger.h>

#define RUNTIME_STATS_IDLE_THREAD_SLEEP  1000U
#define RUNTIME_STATS_RUN_THREAD_SLEEP  250U

namespace sysmon
{

RuntimeStatsRunnable::RuntimeStatsRunnable(IDataProviderSysMon &i_DataProviderSysMon_po)
  : osal::IRunnable()
  , isRunning_b(true)
  , m_dataProvider_ro(i_DataProviderSysMon_po)
  , m_RunTimeStats_MPU1_0{0}
{
  
}

RuntimeStatsRunnable::~RuntimeStatsRunnable()
{
  // Nothing to do yet!
}

void RuntimeStatsRunnable::init_v()
{
  // Nothing to do yet!
}

bool_t RuntimeStatsRunnable::run_b()
{
  PerformanceStatsEnable_t v_PerformanceStatsEnable = {};
  v_PerformanceStatsEnable = m_dataProvider_ro.getPerformanceStatsEnable_t();

  if(TRUE == v_PerformanceStatsEnable.RunTimeStatsEnable)
  {
    //Get the application runtime data
    m_RunTimeStats_MPU1_0.CALSM_Runtime = m_dataProvider_ro.getCALSMRuntime();
    m_RunTimeStats_MPU1_0.CALSMThread_Runtime = m_dataProvider_ro.getCALSMThreadRuntime();
    m_RunTimeStats_MPU1_0.DLDThread_Runtime = m_dataProvider_ro.getDLDThreadRuntime();
    m_RunTimeStats_MPU1_0.DLD_Runtime = m_dataProvider_ro.getDLDRuntime();
    m_RunTimeStats_MPU1_0.EOL_Runtime = m_dataProvider_ro.getEOLRuntime();
    m_RunTimeStats_MPU1_0.EOLThread_Runtime = m_dataProvider_ro.getEOLThreadRuntime();
    m_RunTimeStats_MPU1_0.OC_Runtime = m_dataProvider_ro.getOCRuntime();
    m_RunTimeStats_MPU1_0.OCThread_Runtime = m_dataProvider_ro.getOCThreadRuntime();
    m_RunTimeStats_MPU1_0.OVL3D_Runtime = m_dataProvider_ro.getOVL3DRuntime();
    m_RunTimeStats_MPU1_0.RenderThread_Runtime = m_dataProvider_ro.getRenderThreadRuntime();
    m_RunTimeStats_MPU1_0.TAD_Runtime = m_dataProvider_ro.getTAD2Runtime();
    m_RunTimeStats_MPU1_0.TADThread_Runtime = m_dataProvider_ro.getTAD2ThreadRuntime();
    m_RunTimeStats_MPU1_0.THA_Runtime = m_dataProvider_ro.getTHARuntime();
    m_RunTimeStats_MPU1_0.THAThread_Runtime = m_dataProvider_ro.getTHAThreadRuntime();
    m_RunTimeStats_MPU1_0.TIOVXThread_Runtime = m_dataProvider_ro.getTIOVXThreadRuntime();
    m_RunTimeStats_MPU1_0.TIOVX_Runtime = m_dataProvider_ro.getTIOVXRuntime();
    m_RunTimeStats_MPU1_0.CameraCalib_Runtime = m_dataProvider_ro.getCamCalibRuntime();
    m_RunTimeStats_MPU1_0.AppM_Runtime = m_dataProvider_ro.getAppMRuntime();
    m_RunTimeStats_MPU1_0.LogM_Runtime = m_dataProvider_ro.getLogMRuntime();
    m_RunTimeStats_MPU1_0.KeepAlive_Runtime = m_dataProvider_ro.getKeepAliveRuntime();
    m_RunTimeStats_MPU1_0.ThreadMsgSndr_Runtime = m_dataProvider_ro.getMsgSndrRuntime();
    m_RunTimeStats_MPU1_0.SigM_Runtime = m_dataProvider_ro.getSigMRuntime();
    m_RunTimeStats_MPU1_0.ThreadSigM_Runtime = m_dataProvider_ro.getThSigMRuntime();
    m_RunTimeStats_MPU1_0.SysMon_Runtime = m_dataProvider_ro.getSysMonRuntime();
    m_RunTimeStats_MPU1_0.VarM_Runtime = m_dataProvider_ro.getVarMRuntime();
    m_RunTimeStats_MPU1_0.AlgoViewThread_Runtime = m_dataProvider_ro.getAlgoViewRuntime();
    //TBD: VideoInput and Sys Runtime

    //Send combined runtime data over IPC
    m_dataProvider_ro.setRunTimeStats_MPU1_0_v(m_RunTimeStats_MPU1_0);
    ME_Thread_Sleep_t(static_cast<uint32_t>(RUNTIME_STATS_RUN_THREAD_SLEEP)); // sleep 250ms
  }
  else
  {
    memset(&m_RunTimeStats_MPU1_0,0x00u,sizeof(m_RunTimeStats_MPU1_0));
    m_dataProvider_ro.setRunTimeStats_MPU1_0_v(m_RunTimeStats_MPU1_0);
    ME_Thread_Sleep_t(static_cast<uint32_t>(RUNTIME_STATS_IDLE_THREAD_SLEEP)); // sleep 1sec
  }

  return isRunning_b;
}

void RuntimeStatsRunnable::cleanup_v()
{
  // Nothing to do yet!
}


} // namespace sysmon
