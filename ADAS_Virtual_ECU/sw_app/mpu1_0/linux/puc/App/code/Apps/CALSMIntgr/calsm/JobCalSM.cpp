//--------------------------------------------------------------------------
/// @file JobCalSM.cpp
/// @brief Contains the job definition for the CALSM
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
/// @author Ananda Kavrady (ananda.kavrady@magna.com)
#include "JobCalSM.h"
#include "cfg/DataProvider/DataProviderCALSM.h"
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_CALSM     (1u)
#define PROFILE_CALSMThread     (1u)
static PerformanceStatsEnable_t PerformanceStatsEnable_dp;
static PerformanceStatsEnable_t PerformanceStatsThEnable_dp;
#endif
#if PROFILE_CALSM
#include "osal/system/Clock.h"
static uint32_t v_AvgCALSMRuntime_u32 = 0;
static uint32_t v_CALSMRunCntr_u32 = 0;
static uint32_t v_AvgCALSMPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_CALSMRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
#endif


#if PROFILE_CALSMThread
#include "osal/system/Clock.h"
static uint32_t v_AvgCALSMThreadRuntime_u32 = 0;
static uint32_t v_CALSMThreadRunCntr_u32 = 0;
static uint32_t v_AvgCALSMThreadPeriodicity_u32 = 0;
static uint32_t v_CALSMThreadPreviousTime_u32 = 0;
static uint32_t v_CALSMThreadRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity

#endif

namespace calsm
{
  #define _30_FPS_ ((uint32_t)32)

  /* *******************************************************************************
   *                              C A L S M    J O B
   ******************************************************************************* */
  JobCalSM::JobCalSM(container::JobDesc_s& b_JobDesc_rs, IDataProviderCALSM& b_DPCalSm_ro)
    : container::JobBase<IDataProviderCALSM>(b_JobDesc_rs, b_DPCalSm_ro),
    m_CALSMThread_o("CALSM_Thread"),
    m_CALSMThreadRunnable_o(b_DPCalSm_ro)
  {
    m_CALSMThread_o.setPriority_v(e_PriorityLow);
  }
  
  JobCalSM::~JobCalSM() {
  }

  bool_t JobCalSM::onInit_b() {
    /* DD-ID: {1F338A2B-FA5F-452b-B672-9126BD4467A8}*/
    m_CALSMThread_o.start_v(&m_CALSMThreadRunnable_o);
    return true;
  }

  void JobCalSM::onVariantChanged_v(bool_t i_FirstTime_b) {
    /* DD-ID: {D2A2F312-339F-4ed2-85F1-13D733D350B3}*/
  }

  bool_t JobCalSM::onRun_b() {
    /* DD-ID: {4125B342-F0ED-460b-8FA9-AAD0D5FB7DA7}*/
#if PROFILE_CALSM
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

#if PROFILE_CALSM
    if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
    {
    v_End_t = __get_time_usec();
    v_CALSMRunCntr_u32++; //Increment the run counter for averaging purpose
    v_AvgCALSMPeriodicity_u32 = ((v_AvgCALSMPeriodicity_u32 * (v_CALSMRunCntr_u32 -1)) + currPeriodicity)/v_CALSMRunCntr_u32; //Average Periodicity
		v_AvgCALSMRuntime_u32 = ((v_AvgCALSMRuntime_u32 * (v_CALSMRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_CALSMRunCntr_u32; //New Average  
    //ME_Debugger_F_Printf_v("CALSM: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
    v_CALSMRuntimeData = (((v_AvgCALSMRuntime_u32/1000U)<<16U) | ((v_AvgCALSMPeriodicity_u32/1000U) & 0xFFFF));
    dataProvider_ro.setCALSMRuntime(v_CALSMRuntimeData);
    //ME_Debugger_F_Printf_v("CALSM: E: %lld P: %lld \n", v_AvgCALSMRuntime_u32, v_AvgCALSMPeriodicity_u32);
    v_PreviousTime_u32 = v_Start_t;
    }
#endif
    return true;
  }

  void JobCalSM::onCleanup_v() {
    /* DD-ID: {3584E22A-9CDF-4b9c-923F-BC53832CA314}*/
    m_CALSMThread_o.terminate_v();
    m_CALSMThread_o.join_v();
  }

  /* *******************************************************************************
   *                   C A L S M    T H R E A D   R U N N A B L E
   ******************************************************************************* */
  CALSMThreadRunnable::CALSMThreadRunnable(IDataProviderCALSM& b_DPCalSm_ro)
  : IRunnable(),
  dataProvider_ro(b_DPCalSm_ro)
  {

  }

  CALSMThreadRunnable::~CALSMThreadRunnable() {

  }

  void CALSMThreadRunnable::init_v() {
    /* DD-ID: {80F58545-7280-43ac-915A-43EC4F5C3895}*/
    aZynqM_f_InternalInit_v();
  #if ENABLE_DEBUG    
    ME_Debugger_F_Printf_v("CALSM onInit_b() ...\n");
  #endif
  }

  bool_t CALSMThreadRunnable::run_b() {
    /* DD-ID: {331D7986-B82E-49cc-A103-288EA286AD2B}*/
  #if PROFILE_CALSMThread
    PerformanceStatsThEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
    static osal::Time start;
    volatile uint32_t v_Start_t = 0;
    volatile uint32_t v_End_t = 0;
    volatile uint32_t currPeriodicity = 0;
    if (TRUE ==  PerformanceStatsThEnable_dp.RunTimeStatsEnable)
    {
      v_Start_t = __get_time_usec();
      currPeriodicity = v_Start_t - v_CALSMThreadPreviousTime_u32;
    }
  #endif
    osal::Time v_Time_o;
    uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
    
    start_v();
    execute_v();
    end_v();

  #if PROFILE_CALSMThread
    if (TRUE ==  PerformanceStatsThEnable_dp.RunTimeStatsEnable)
    {
      v_End_t = __get_time_usec();
      // ME_Debugger_F_Printf_v("CALSM_Thread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
      v_CALSMThreadRunCntr_u32++; //Increment the run counter for averaging purpose
      v_AvgCALSMThreadPeriodicity_u32 = ((v_AvgCALSMThreadPeriodicity_u32 * (v_CALSMThreadRunCntr_u32 -1)) + currPeriodicity)/v_CALSMThreadRunCntr_u32; //Average Periodicity
      v_AvgCALSMThreadRuntime_u32 = ((v_AvgCALSMThreadRuntime_u32 * (v_CALSMThreadRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_CALSMThreadRunCntr_u32; //New Average  
      //ME_Debugger_F_Printf_v("CALSMThread: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
      v_CALSMThreadRuntimeData = (((v_AvgCALSMThreadRuntime_u32/1000U)<<16U) | ((v_AvgCALSMThreadPeriodicity_u32/1000U) & 0xFFFF));
      dataProvider_ro.setCALSMThreadRuntime(v_CALSMThreadRuntimeData);
      //ME_Debugger_F_Printf_v("CALSMThread: E: %lld P: %lld \n", v_AvgCALSMThreadRuntime_u32, v_AvgCALSMThreadPeriodicity_u32);
      v_CALSMThreadPreviousTime_u32 = v_Start_t;
    }
  #endif

    uint64_t v_EndTime_u64 = v_Time_o.getTimeMsec_u64();
    uint32_t v_TotalTime_u32 = (uint32_t)(v_EndTime_u64 - v_StartTime_u64);
    if(v_TotalTime_u32 < _30_FPS_)
    {
      uint32_t v_AdjustmentTime_u32 = (_30_FPS_ - v_TotalTime_u32); /* Total sleep and last frmae's execution will be syncronised to 30 FPS */
      ME_Thread_Sleep_t(v_AdjustmentTime_u32);
    }
  
  return true;
  
  }

  void CALSMThreadRunnable::cleanup_v() {
    /* DD-ID: {494E15D8-34D3-4b01-B339-10EA086187B5}*/
  }

  void CALSMThreadRunnable::start_v() {
    /* DD-ID: {1860C61E-7F79-4052-BD4D-CFABC1D18A38}*/
    dataProvider_ro.get_calib_nvmmgr_input();
    dataProvider_ro.get_calib_diagmgr_input();
    dataProvider_ro.get_calib_vehicle_signal_input();
    dataProvider_ro.get_calib_algo_input();
	dataProvider_ro.get_HmiScreen();
	dataProvider_ro.get_shutdown_input();
#if ENABLE_DEBUG    
    ME_Debugger_F_Printf_v("CALSM start_v() ...\n");
#endif   
    return;
  }

  void CALSMThreadRunnable::execute_v() {
    /* DD-ID: {3B3D608A-B35B-432c-8696-A53529B801AE}*/
    aZynqM_F_Task10msec_v();
#if ENABLE_DEBUG
    ME_Debugger_F_Printf_v("Calib SM triggered triggered ...\n");

    ME_Debugger_F_Printf_v("CALSM execute_v() ...\n");
#endif
    return;
  }

  void CALSMThreadRunnable::end_v() {
    /* DD-ID: {00599BAD-C629-44dc-9E5A-04A8184D56E3}*/
    dataProvider_ro.set_calib_algo_input();
    dataProvider_ro.set_DiagMgr_CalibData();
    dataProvider_ro.set_NVM_CalibData();
    dataProvider_ro.set_TscScreen();

#if ENABLE_DEBUG
    ME_Debugger_F_Printf_v("CALSM end_v() ...\n");
#endif    
    return;
  }
}

