//--------------------------------------------------------------------------
/// @file JobDLD.cpp
/// @brief Contains the job definition for the DLD Job
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------

#include "JobDLD.h"
#include "osal/system/Clock.h"
#include "algo/common/DLDDef.h"
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_DLD     (1u)
#endif
#if PROFILE_DLD
#include "osal/system/Clock.h"
static uint32_t v_AvgDLDRuntime_u32 = 0;
static uint32_t v_DLDRunCntr_u32 = 0;
static uint32_t v_AvgDLDPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_DLDRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsEnable_dp;
#endif

namespace dld
{

JobDLD::JobDLD(container::JobDesc_s& b_JobDesc_rs, IDataProviderDLD& b_DataProvider_ro)
    : JobBase(b_JobDesc_rs, b_DataProvider_ro)
#if ENABLE_DLD_THREAD
    ,m_DLDThread_o("DLDThread")
    ,m_DLDThreadRunnable_o(b_DataProvider_ro)
#endif
{
#if ENABLE_DLD_THREAD
  m_DLDThread_o.setPriority_v(e_PriorityLow);
#endif
}

JobDLD::~JobDLD() {
}

  /*
	*	Name: onInit_b
	*	Remarks: DD-ID: {625B9961-F4A0-4cdc-BE4F-A8AFDC185127}
	*	Remarks: DD-ID: {B44CB008-05A9-490c-B6A9-198819D5690B}
	*	Remarks: DD-ID: {163A415D-65F5-4b88-8C38-0710C7E2C103}
  */
bool_t JobDLD::onInit_b() {
  DLD_DEBUG_PRINT(DLD_TRACE_HIGH, "[DLD] JobDLD onInit_b()\n");
#if ENABLE_DLD_THREAD
  m_DLDThread_o.start_v(&m_DLDThreadRunnable_o);
#endif
  return true;
}

  /*
	*	Name: onRun_b
	*	Remarks: DD-ID: {330D8B95-30A2-4fc7-82C2-5F5F4549EFA7}
	*	Remarks: DD-ID: {88A817B1-147A-4da7-B67E-21D1FC423CD0}
	*	Remarks: DD-ID: {C03F4D5A-1CF0-44ee-A708-D6C7B01FBA54}
  */
bool_t JobDLD::onRun_b() {
  //DLD_DEBUG_PRINT("[DLD] JobDLD onRun_b()\n");
	//ME_Thread_Sleep_t(5);
#if PROFILE_DLD
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

#if PROFILE_DLD
    if (TRUE ==  PerformanceStatsEnable_dp.RunTimeStatsEnable)
    {
      v_End_t = __get_time_usec();
      //ME_Debugger_F_Printf_v("DLD: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
      v_DLDRunCntr_u32++; //Increment the run counter for averaging purpose
      v_AvgDLDPeriodicity_u32 = ((v_AvgDLDPeriodicity_u32 * (v_DLDRunCntr_u32 -1)) + currPeriodicity)/v_DLDRunCntr_u32; //Average Periodicity
      v_AvgDLDRuntime_u32 = ((v_AvgDLDRuntime_u32 * (v_DLDRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_DLDRunCntr_u32; //New Average  
      v_DLDRuntimeData = (((v_AvgDLDRuntime_u32/1000U)<<16U) | ((v_AvgDLDPeriodicity_u32/1000U) & 0xFFFF));
      dataProvider_ro.setDLDRuntime(v_DLDRuntimeData);
      //ME_Debugger_F_Printf_v("DLD: E: %lld P: %lld \n", v_AvgDLDRuntime_u32, v_AvgDLDPeriodicity_u32);
      v_PreviousTime_u32 = v_Start_t;
    }
#endif
    return true;
  }

  /*
	*	Name: onCleanup_v
	*	Remarks: DD-ID: {AF730E9E-9FC1-41e0-9E83-E11D86589B2F}
	*	Remarks: DD-ID: {F7D85249-FA9F-4153-9DCE-58E1EEC91271}
	*	Remarks: DD-ID: {67EA492F-0293-4ae7-94D8-2E975105611A}
  */
void JobDLD::onCleanup_v() {
#if ENABLE_DLD_THREAD
  m_DLDThreadRunnable_o.stop_v();
  m_DLDThread_o.terminate_v();
  m_DLDThread_o.join_v();
#endif
}


  /*
	*	Name: onVariantChanged_v
	*	Remarks: DD-ID: {CFC19C67-9F88-46f9-99BE-FB5D6715B8D6}
	*	Remarks: DD-ID: {338862E6-DE83-49b8-8BE8-5AAC9EBD9978}
	*	Remarks: DD-ID: {F3110FC8-1511-454b-928B-690F7A66630A}
  */
void JobDLD::onVariantChanged_v(bool_t i_FirstTime_b) {

}

} // namespace dld
