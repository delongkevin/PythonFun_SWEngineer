//--------------------------------------------------------------------------
/// @file JobTAD2.cpp
/// @brief Contains the TAD job implementation. mecl.h
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
///
//  --------------------------------------------------------------------------

#include <string.h>
#include <math.h>
#include <assert.h>
#include "JobTAD2.h"

volatile extern uint32_t m_FrameNumber;

extern TAD2::RawKinematicData v_KMData;
extern TAD2::RawVehicleData v_VehData;
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_TAD   (1u)
#endif
#if PROFILE_TAD
#include "osal/system/Clock.h"
static uint32_t v_AvgTADRuntime_u32 = 0;
static uint32_t v_TADRunCntr_u32 = 0;
static uint32_t v_AvgTADPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_TADRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsEnable_dp;
#endif
namespace TAD2
{
// -------------------------------------------------------------------------
JobTAD2::JobTAD2(container::JobDesc_s& b_JobDesc_rs, IDataProviderTAD2& b_DPTAD_ro)
: container::JobBase<IDataProviderTAD2>(b_JobDesc_rs, b_DPTAD_ro)
#if ENABLE_TAD2_THREAD
  ,TAD2Thread_o("TAD2Thread"),

  TAD2ThreadRunnable_o(dataProvider_ro)
#endif

{
#if ENABLE_TAD2_THREAD
  TAD2Thread_o.setPriority_v(e_PriorityLow);
#endif
}
// -------------------------------------------------------------------------
JobTAD2::~JobTAD2()
{
}

// -------------------------------------------------------------------------
bool_t JobTAD2::onInit_b()
{
#if TAD2_DEBUG_PRINTS
    ME_Debugger_F_Printf_v("JobTAD2::onInit_b()\n");
#endif
#if ENABLE_TAD2_THREAD
    TAD2Thread_o.start_v(&TAD2ThreadRunnable_o);
#endif
    return true;
}

// -------------------------------------------------------------------------
void JobTAD2::onVariantChanged_v(bool_t i_FirstTime_b)
{
#if TAD2_DEBUG_PRINTS
    ME_Debugger_F_Printf_v("JobTAD2::onVariantChanged_v()\n");
#endif
}

// -------------------------------------------------------------------------
bool_t JobTAD2::onRun_b()
{
#if TAD2_DEBUG_PRINTS
	static int count = 0;
    ME_Debugger_F_Printf_v("JobTAD2::onRun_b() %d\n", count);
    count++;
#endif
//    printf("ONRUN_B- %s\n", __PRETTY_FUNCTION__);
#if PROFILE_TAD
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
#if PROFILE_TAD
        if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
        {
          v_End_t = __get_time_usec();
          //ME_Debugger_F_Printf_v("TAD: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
          v_TADRunCntr_u32++; //Increment the run counter for averaging purpose
          v_AvgTADPeriodicity_u32 = ((v_AvgTADPeriodicity_u32 * (v_TADRunCntr_u32 -1)) + currPeriodicity)/v_TADRunCntr_u32; //Average Periodicity
          v_AvgTADRuntime_u32 = ((v_AvgTADRuntime_u32 * (v_TADRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_TADRunCntr_u32; //New Average  
          v_TADRuntimeData = (((v_AvgTADRuntime_u32/1000U)<<16U) | ((v_AvgTADPeriodicity_u32/1000U) & 0xFFFF));
          dataProvider_ro.setTADRuntime(v_TADRuntimeData);
          //ME_Debugger_F_Printf_v("TAD: E: %lld P: %lld \n", v_AvgTADRuntime_u32, v_AvgTADPeriodicity_u32);
          v_PreviousTime_u32 = v_Start_t;
        }
#endif
  return true;
}

// -------------------------------------------------------------------------
void JobTAD2::onCleanup_v()
{
#if ENABLE_TAD2_THREAD
  TAD2ThreadRunnable_o.stop_v();
  TAD2Thread_o.terminate_v();
  TAD2Thread_o.join_v();
#endif
}

} //namespace TAD2
