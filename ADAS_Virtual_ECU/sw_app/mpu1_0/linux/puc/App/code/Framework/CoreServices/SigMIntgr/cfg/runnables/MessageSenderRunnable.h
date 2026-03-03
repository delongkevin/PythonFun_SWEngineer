
#ifndef MESSAGE_SENDER_RUNNABLE_H_
#define MESSAGE_SENDER_RUNNABLE_H_

#include <platform/PlatformAPI.h>
#include "cfg/ProjectSenders.h"
#include <osal/threading/Thread.h>
#include <logging/Logger.h>
#include "cfg/runnables/MessageSenderRunnable.h"
#include "sigm/IDataProviderSigM.h"
#ifdef ENABLE_RUNTIME_STATS
#define PROFILE_ThreadMessageSender   (1u)
#endif
#if PROFILE_ThreadMessageSender
#include "osal/system/Time.h"
static uint32_t v_AvgMsgSndrRuntime_u32 = 0;
static uint32_t v_MsgSndrRunCntr_u32 = 0;
static uint32_t v_AvgMsgSndrPeriodicity_u32 = 0;
static uint32_t v_MsgSndrPreviousTime_u32 = 0;
static uint32_t v_MsgSndrRuntimeData = 0; 
static PerformanceStatsEnable_t PerformanceStatsMSEnable_dp;
#endif


namespace sigm
{

namespace sigmconsts
{
const uint64_t c_MsgSenderThresholdMS_u64 = 10;
} //namespace sigmconsts


class MessageSenderRunnable : public osal::IRunnable
{
public:

  explicit MessageSenderRunnable(sigm::IDataProviderSigM& b_DataProvider_ro, JobSigM& b_JobSigM_ro)
    : osal::IRunnable()
    , logger_o()
    , dataProvider_po(&b_DataProvider_ro)
    , dataProvider_ro(b_DataProvider_ro)
    , isRunning_b(true)
    , network_po(NULL)
    , jobSigM_ro(b_JobSigM_ro)
  { }

  virtual ~MessageSenderRunnable() { }

  virtual void registerNetwork_v(osal::INetwork* i_Network_po)
  {
    network_po = i_Network_po;
  }


  virtual void init_v()
  {
    logger_o.config_b(logging::e_LogLvlInfo, "SIGM", "MSND", logging::e_LogModeMaskAll);

    projectSenders_s.init_v(senderItems_t);
    for (uint32_t v_idx_u32 = 0U; v_idx_u32 < senderItems_t.size_u32(); ++v_idx_u32)
    {
      senderItems_t[v_idx_u32]->init_v(dataProvider_ro, jobSigM_ro); //
    }

    logger_o.log_b(logging::e_LogLvlInfo, "Message send runnable::init_v() - done\n");

  }

  virtual bool_t run_b()
  {
  #if PROFILE_ThreadMessageSender
  PerformanceStatsMSEnable_dp = dataProvider_po->get_PerformanceStatsEnable();
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  volatile uint32_t currPeriodicity = 0;
  if (TRUE ==  PerformanceStatsMSEnable_dp.RunTimeStatsEnable)
  {
    v_Start_t = __get_time_usec();
    currPeriodicity = v_Start_t - v_MsgSndrPreviousTime_u32;
  }
  #endif

    if (NULL != network_po)
    {
      MessageStatus_t v_messageStatus_t;
      //handle sender messages
      for (uint32_t v_idx_u32 = 0U; (v_idx_u32 < senderItems_t.size_u32()); ++v_idx_u32)
      {
        //get the list of sender messages
        BaseSender& v_BaseSender_ro = *(senderItems_t[v_idx_u32]);

        memset(&v_messageStatus_t, 0, sizeof(v_messageStatus_t));

        v_messageStatus_t = dataProvider_po->getMessageStatus_t(v_idx_u32);

        if(true == v_messageStatus_t.sender_Status_b)
        {
          // This signal is updated and ready to send
          v_BaseSender_ro.setReceived_v();
          if (true == v_BaseSender_ro.handlSender_b())
          {
            checkBaseSenders_v();
          }
        }

      }
    }

    ME_Thread_Sleep_t(sigmconsts::c_MsgSenderThresholdMS_u64);
  #if PROFILE_ThreadMessageSender
  if (TRUE ==  PerformanceStatsMSEnable_dp.RunTimeStatsEnable)
  {
    v_End_t = __get_time_usec();
    // ME_Debugger_F_Printf_v("ThreadMsgSndr: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
    v_MsgSndrRunCntr_u32++; //Increment the run counter for averaging purpose
    v_AvgMsgSndrPeriodicity_u32 = ((v_AvgMsgSndrPeriodicity_u32 * (v_MsgSndrRunCntr_u32 -1)) + currPeriodicity)/v_MsgSndrRunCntr_u32; //Average Periodicity
    v_AvgMsgSndrRuntime_u32 = ((v_AvgMsgSndrRuntime_u32 * (v_MsgSndrRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_MsgSndrRunCntr_u32; //New Average  
    v_MsgSndrRuntimeData = (((v_AvgMsgSndrRuntime_u32/1000U)<<16U) | ((v_AvgMsgSndrPeriodicity_u32/1000U) & 0xFFFF));
    dataProvider_po->setMsgSndrRuntime(v_MsgSndrRuntimeData);
    //ME_Debugger_F_Printf_v("MsgSndr: E: %lld P: %lld \n", v_AvgMsgSndrRuntime_u32, v_AvgMsgSndrPeriodicity_u32);
    v_MsgSndrPreviousTime_u32 = v_Start_t;
  }  
  #endif

    return isRunning_b;
  }

/// Collector function to process all common requests
void   checkBaseSenders_v(void)
{
  for (uint32_t v_idx_u32 = 0U; (v_idx_u32 < senderItems_t.size_u32()) ; ++v_idx_u32)
  {
    BaseSender& v_BaseSender_ro = *(senderItems_t[v_idx_u32]);

    if(v_BaseSender_ro.isActive_b())
    {
      v_BaseSender_ro.sendResponse_b();
    }
    else
    {
      //do nothing.
    }
  }

}

virtual void cleanup_v()
{
  senderItems_t.clear_v();
}

void terminate_v()
{
  isRunning_b = false;
}

protected:
  JobSigM& jobSigM_ro;

private:

  logging::Logger           logger_o;
  IDataProviderSigM* dataProvider_po;
  sigm::IDataProviderSigM& dataProvider_ro;

  bool_t             isRunning_b;

  osal::INetwork*    network_po;

  BaseSenderList_t              senderItems_t;
  ProjectSenders_s              projectSenders_s;
};


} // namespace sigm

#endif // MESSAGE_SENDER_RUNNABLE_H_
