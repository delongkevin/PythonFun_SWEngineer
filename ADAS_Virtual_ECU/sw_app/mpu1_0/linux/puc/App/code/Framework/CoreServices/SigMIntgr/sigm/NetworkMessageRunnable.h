#ifndef NETWORK_MESSAGE_RUNNABLE_H_
#define NETWORK_MESSAGE_RUNNABLE_H_

#include <platform/PlatformAPI.h>

#include <osal/networking/INetwork.h>
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_ThreadSigM   (1u)
#endif
#if PROFILE_ThreadSigM
#include "osal/system/Time.h"
static uint32_t v_AvgThSigMRuntime_u32 = 0;
static uint32_t v_ThSigMRunCntr_u32 = 0;
static uint32_t v_AvgThSigMPeriodicity_u32 = 0;
static uint32_t v_ThSigMPreviousTime_u32 = 0;
static uint32_t v_ThSigMRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsNMEnable_dp;
#endif


class NetworkMessageRunnable : public osal::IRunnable
{
public:
  explicit NetworkMessageRunnable(sigm::IDataProviderSigM& b_DataProvider_ro)
    : osal::IRunnable()
    , dataProvider_ro(b_DataProvider_ro)
    , network_po(NULL)
    , isRunning_b(true)
  { }

  virtual ~NetworkMessageRunnable() { }

  virtual void init_v()  { }

  bool_t registerNetwork_b(osal::INetwork* b_Network_po)
  {
    bool_t v_Result_b = true;

    Assert(NULL == network_po);
    Assert(NULL != b_Network_po);
    network_po = b_Network_po;

    return v_Result_b;
  }

  virtual bool_t run_b()
  {
  
  #if PROFILE_ThreadSigM
  PerformanceStatsNMEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  volatile uint32_t currPeriodicity = 0;
  if (TRUE ==  PerformanceStatsNMEnable_dp.RunTimeStatsEnable)
  {
    v_Start_t = __get_time_usec();
    currPeriodicity = v_Start_t - v_ThSigMPreviousTime_u32;
  }
  #endif

    if (NULL != network_po)
    {
      network_po->process_b();
    }

  #if PROFILE_ThreadSigM
  if (TRUE ==  PerformanceStatsNMEnable_dp.RunTimeStatsEnable)
  {
    v_End_t = __get_time_usec();
    // ME_Debugger_F_Printf_v("ThreadSigM: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
    v_ThSigMRunCntr_u32++; //Increment the run counter for averaging purpose
    v_AvgThSigMPeriodicity_u32 = ((v_AvgThSigMPeriodicity_u32 * (v_ThSigMRunCntr_u32 -1)) + currPeriodicity)/v_ThSigMRunCntr_u32; //Average Periodicity
    v_AvgThSigMRuntime_u32 = ((v_AvgThSigMRuntime_u32 * (v_ThSigMRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_ThSigMRunCntr_u32; //New Average  
    v_ThSigMRuntimeData = (((v_AvgThSigMRuntime_u32/1000U)<<16U) | ((v_AvgThSigMPeriodicity_u32/1000U) & 0xFFFF));
    dataProvider_ro.setThSigMRuntime(v_ThSigMRuntimeData);
    //ME_Debugger_F_Printf_v("ThSigM: E: %lld P: %lld \n", v_AvgThSigMRuntime_u32, v_AvgThSigMPeriodicity_u32);
    v_ThSigMPreviousTime_u32 = v_Start_t;
  }
  #endif

    return isRunning_b;
  }

  virtual void cleanup_v() { }

  void terminate_v()
  {
    isRunning_b = false;
  }

private:
  osal::INetwork* network_po;
  bool_t          isRunning_b;
  sigm::IDataProviderSigM& dataProvider_ro;
};

#endif // NETWORK_MESSAGE_RUNNABLE_H_
