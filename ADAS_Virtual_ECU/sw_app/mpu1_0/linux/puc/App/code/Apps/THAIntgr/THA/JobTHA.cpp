//--------------------------------------------------------------------------
/// @file JobTHA.h
/// @brief Contains the job definition for the THA Manager
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
//  --------------------------------------------------------------------------

#include "JobTHA.h"
#include "osal/system/Clock.h"
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_THA_RT   (1u)
#endif
#if PROFILE_THA_RT
#include "osal/system/Clock.h"
static uint32_t v_AvgTHARuntime_u32 = 0;
static uint32_t v_THARunCntr_u32 = 0;
static uint32_t v_AvgTHAPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_THARuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsEnable_dp;
#endif
namespace tha
{

JobTHA::JobTHA(container::JobDesc_s& b_JobDesc_rs, IDataProviderTHA& b_DataProvider_ro)
    : JobBase(b_JobDesc_rs, b_DataProvider_ro),
    THAThread_o("THAThread"),
    THAThreadRunnable_o(b_DataProvider_ro)
{
    THAThread_o.setPriority_v(e_PriorityLow);
}

JobTHA::~JobTHA()
{
}

bool_t JobTHA::onInit_b()
{
#if ENABLE_DEBUG_THA
  ME_Debugger_F_Printf_v("\n ###### JobTHA onInit_b ###### \n");
#endif
  THAThread_o.start_v(&THAThreadRunnable_o);
  return true;
}

bool_t JobTHA::onRun_b()
{
//    ME_Debugger_F_Printf_v("ONRUN_B- %s\n", __PRETTY_FUNCTION__);
#if PROFILE_THA_RT
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
	ME_Thread_Sleep_t(5);
#if PROFILE_THA_RT
        if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
        {
          v_End_t = __get_time_usec();
          //ME_Debugger_F_Printf_v("THA: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
          v_THARunCntr_u32++; //Increment the run counter for averaging purpose
          v_AvgTHAPeriodicity_u32 = ((v_AvgTHAPeriodicity_u32 * (v_THARunCntr_u32 -1)) + currPeriodicity)/v_THARunCntr_u32; //Average Periodicity
          v_AvgTHARuntime_u32 = ((v_AvgTHARuntime_u32 * (v_THARunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_THARunCntr_u32; //New Average  
          v_THARuntimeData = (((v_AvgTHARuntime_u32/1000U)<<16U) | ((v_AvgTHAPeriodicity_u32/1000U) & 0xFFFF));
          dataProvider_ro.setTHARuntime(v_THARuntimeData);
          //ME_Debugger_F_Printf_v("THA: E: %lld P: %lld \n", v_AvgTHARuntime_u32, v_AvgTHAPeriodicity_u32);
          v_PreviousTime_u32 = v_Start_t;
        }
#endif
  return true;
}

void JobTHA::onCleanup_v()
{
  THAThreadRunnable_o.stop_v();
  THAThread_o.terminate_v();
  THAThread_o.join_v();
}

void JobTHA::onVariantChanged_v(bool_t i_FirstTime_b)
{

}

} // namespace
