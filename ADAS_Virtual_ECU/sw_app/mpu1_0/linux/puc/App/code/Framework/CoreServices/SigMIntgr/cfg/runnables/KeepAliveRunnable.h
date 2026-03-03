
#ifndef KEEPALIVERUNNABLE_H_
#define KEEPALIVERUNNABLE_H_

#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_Keepalive   (1u)
#endif
#if PROFILE_Keepalive
#include "osal/system/Time.h"
static uint32_t v_AvgKeepAliveRuntime_u32 = 0;
static uint32_t v_KeepAliveRunCntr_u32 = 0;
static uint32_t v_AvgKeepAlivePeriodicity_u32 = 0;
static uint32_t v_KeepAlivePreviousTime_u32 = 0;
static uint32_t v_KeepAliveRuntimeData = 0;
static PerformanceStatsEnable_t PerformanceStatsKAEnable_dp; 
#endif

namespace sigm
{

namespace sigmconsts
{
  const uint64_t c_KeepAliveThresholdMS_u64 = 30U;
  const uint64_t c_KeepAliveLongSleepMS_u64 = 100000U;
} //namespace sigmconsts



class KeepAliveRunnable : public osal::IRunnable
{
public:

  explicit KeepAliveRunnable(IDataProviderSigM* i_DataProviderSigM_po)
    : osal::IRunnable()
    , dataProvider_po(i_DataProviderSigM_po)
    , isRunning_b(true)
    , network_po(NULL)
  { }

  virtual ~KeepAliveRunnable() { }

  virtual void registerNetwork_v(osal::INetwork* i_Network_po)
  {
    network_po = i_Network_po;
  }

  virtual void init_v()  {

     ME_Debugger_F_Printf_v(" keep alive monitor init() done...\n");
   }

  virtual bool_t run_b()
  {

      #if PROFILE_Keepalive
        PerformanceStatsKAEnable_dp = dataProvider_po->get_PerformanceStatsEnable();
        static osal::Time start;
        volatile uint32_t v_Start_t = 0;
        volatile uint32_t v_End_t = 0;
        volatile uint32_t currPeriodicity = 0;
        if (TRUE ==  PerformanceStatsKAEnable_dp.RunTimeStatsEnable)
        {
          v_Start_t = __get_time_usec();
          currPeriodicity = v_Start_t - v_KeepAlivePreviousTime_u32;
        }
      #endif

    if (NULL != network_po)
    {
      KeepAliveResponse_t v_Response_t;
      uint32_t v_RenderFrame_count_u32 = 0;

      static uint32_t v_count_u32 = 1;

      // according to Marcel, value should change every time keep alive is triggered, so just send frame id here.
      v_RenderFrame_count_u32 = dataProvider_po->getRenderFrameID();

      v_Response_t.FrameID_u32 = v_RenderFrame_count_u32;
      v_Response_t.ResponseCode_u8 = static_cast<uint8_t>(variants::e_ResponseCodePositive);

      ME_MsgTx_s v_KeepAliveMessage_o;
      v_KeepAliveMessage_o.msgSize_u32 = BaseReceiver::getMessageSize_u32<KeepAliveResponse_t>();
      uint32_t v_Index_u32 = addHeaderToMessage_u32(&v_KeepAliveMessage_o.data_t[0], e_IpcMsgId_PpKeepAliveResponse_KeepAliveResponse_t);
            
      memcpy(&v_KeepAliveMessage_o.data_t[v_Index_u32], &v_Response_t, sizeof(KeepAliveResponse_t));
 
      network_po->send_b(&v_KeepAliveMessage_o.data_t[0], v_KeepAliveMessage_o.msgSize_u32);

      //We will send the keep alive in every 30ms. The FrameID value is validated every 100ms in master watchdog.

      ME_Thread_Sleep_t(sigmconsts::c_KeepAliveThresholdMS_u64);
       //This test code is helpful in future to check  thread interval or timings. 
      /*
      if(v_count_u32%10 == 0)
      {
        osal::Time v_Time_o;
        uint64_t v_StartTime_u64 = v_Time_o.getTimeMsec_u64();
        ME_Debugger_F_Printf_v(" keep alive is %ld , render frame count %ld, and time %ld sent() ...\n", v_count_u32, v_RenderFrame_count_u32, v_StartTime_u64);
      }
      else if(((v_count_u32-1)%10) == 0)
      {
         osal::Time v_Time_o;
        uint64_t v_nextTime_u64 = v_Time_o.getTimeMsec_u64();
        ME_Debugger_F_Printf_v(" keep alive subsequent is  %ld, render frame count %ld, and time %ld sent() ...\n", v_count_u32, v_RenderFrame_count_u32, v_nextTime_u64);

      }
      */
      v_count_u32++;
    }
    
    else
    {
      //Safer side we are doing the thread sleep. The goal is master to take the action.
    	ME_Thread_Sleep_t(sigmconsts::c_KeepAliveLongSleepMS_u64);
    }
    
    #if PROFILE_Keepalive
        if (TRUE ==  PerformanceStatsKAEnable_dp.RunTimeStatsEnable)
        {
          v_End_t = __get_time_usec();
          // ME_Debugger_F_Printf_v("KeepAlive: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
          v_KeepAliveRunCntr_u32++; //Increment the run counter for averaging purpose
          v_AvgKeepAlivePeriodicity_u32 = ((v_AvgKeepAlivePeriodicity_u32 * (v_KeepAliveRunCntr_u32 -1)) + currPeriodicity)/v_KeepAliveRunCntr_u32; //Average Periodicity
          v_AvgKeepAliveRuntime_u32 = ((v_AvgKeepAliveRuntime_u32 * (v_KeepAliveRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_KeepAliveRunCntr_u32; //New Average  
          v_KeepAliveRuntimeData = (((v_AvgKeepAliveRuntime_u32/1000U)<<16U) | ((v_AvgKeepAlivePeriodicity_u32/1000U) & 0xFFFF));
          dataProvider_po->setKeepAliveRuntime(v_KeepAliveRuntimeData);
          //ME_Debugger_F_Printf_v("KeepAlive: E: %lld P: %lld \n", v_AvgKeepAliveRuntime_u32, v_AvgKeepAlivePeriodicity_u32);
          v_KeepAlivePreviousTime_u32 = v_Start_t;
        }
    #endif
    return true;
  }

  virtual void cleanup_v() { }

  void terminate_v()
  {
    isRunning_b = false;
  }

private:

  IDataProviderSigM* dataProvider_po;

  bool_t             isRunning_b;

  osal::INetwork*    network_po;
};

} // namespace sigm


#endif // KEEPALIVERUNNABLE_H_
