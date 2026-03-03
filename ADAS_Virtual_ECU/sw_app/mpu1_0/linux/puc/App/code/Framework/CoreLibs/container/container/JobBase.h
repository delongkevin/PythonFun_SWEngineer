//--------------------------------------------------------------------------
/// @file JobBase.h
/// @brief Contains the algo job definition with input and output providers.
/// This class shall be derived by all algorithms to define the main job
/// which is executed in the application and watched by the system.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_JOBBASE_H_
#define CONTAINER_JOBBASE_H_

#include <platform/PlatformAPI.h>

#include <osal/system/Time.h>
#include <osal/threading/IRunnable.h>

#include <logging/Logger.h>

#include "IMessageHandler.h"
#include "MessageDispatcher.h"
#include "MessageQueue.h"
#include "JobContext.h"

namespace container
{
// PRQA S 2100 EOF // public members in a struct used by design
// Description of Job Input
struct JobDesc_s
{
  // reference to the own job's context
  JobContext& ownContext_ro;

  // reference to dispatcher context -> All Jobs only communicate with the AppManager or with themselves(e.g. to implement a state machine).
  // Never communicate with other applications directly or include them!
  JobContext& dispatcher_ro;

  // our own Sender ID
  sint32_t senderId_s32;

  // Receiver ID is always the id of the main dispatcher.
  sint32_t appMReceiverId_s32;

  JobDesc_s(JobContext& b_Own_ro, JobContext& b_Dispatcher_ro)
  : ownContext_ro(b_Own_ro)
  , dispatcher_ro(b_Dispatcher_ro)
  , senderId_s32(b_Own_ro.getContextId_s32())
  , appMReceiverId_s32(b_Dispatcher_ro.getContextId_s32())
  {
  }

private:
  JobDesc_s();
  const JobDesc_s& operator=(const JobDesc_s& i_Rhs_rs);
};

template<typename DataProviderDataType>
class JobBase : public osal::IRunnable, public IMessageHandler
{
public:
  /// Creates the Job.
  /// @param[in] i_dataProvider_ro the adapter between algo and framework
  explicit JobBase(JobDesc_s& b_JobDesc_rs, DataProviderDataType& i_DataProvider_ro)
  : osal::IRunnable()
  , IMessageHandler()
  , jobDesc_s(b_JobDesc_rs)
  , dataProvider_ro(i_DataProvider_ro)
  , time_o()
  , dispatcher_o(jobDesc_s.ownContext_ro.getExternalQueue_ro(),
                 jobDesc_s.ownContext_ro.getSystemQueue_ro(),
                 jobDesc_s.ownContext_ro.getInternalQueue_ro(),
                 jobDesc_s.ownContext_ro.getTriggerSemaphore_ro())
  , isRunning_b(true)
  {
    // attach this job to the message handler
    dispatcher_o.setHandler_v(*this);
  }

protected:

  virtual ~JobBase()
  {
  }

  void init_v() ME_FINAL
  {
    MEP_BEGIN("init", jobDesc_s.ownContext_ro.getContextName_pc());
    logger_o.config_b(static_cast<logging::LogLevel_t>(jobDesc_s.ownContext_ro.getMaxLogLevel_s32()),
                      jobDesc_s.ownContext_ro.getContextName_pc(),
                      "Init",
                      logging::e_LogModeMaskDlt | logging::e_LogModeMaskPrintf);

    logger_o.log_b(logging::e_LogLvlInfo, "%s::init_v() with Process ID [%d]", jobDesc_s.ownContext_ro.getContextName_pc(), ME_Process_GetCurrentID_t());

    jobDesc_s.ownContext_ro.getDataContainer_ro().setActivetime_v(0);

    MEP_END("init", jobDesc_s.ownContext_ro.getContextName_pc());
  }

  virtual bool_t onInit_b() = 0;

  virtual void onVariantChanged_v(bool_t i_FirstTime_b) = 0;

  bool_t run_b() ME_FINAL
  {
    logger_o.log_b(logging::e_LogLvlDebug, "%s::run_v()", jobDesc_s.ownContext_ro.getContextName_pc());

    dispatcher_o.dispatch_v(true);

    // TODO: remove while loop, everything is handled in upper class (e.g. Thread)
    return true;
  }

  // true = wait forever argument
  virtual bool_t onRun_b() = 0;

  void cleanup_v() ME_FINAL
  {
    logger_o.log_b(logging::e_LogLvlInfo, "%s::cleanup_v()", jobDesc_s.ownContext_ro.getContextName_pc());

    onCleanup_v();

    jobDesc_s.dispatcher_ro.reset_v();

    sendFrameworkOperationMessage_v(container::e_OpFwAppCleanupDone, 0, true);
  }

  virtual void onCleanup_v() = 0;

private:

  void sendAlgoExecutedMessage_v() const
  {
    container::Message v_Msg_o;
    v_Msg_o.setMessageType_v(container::e_MtFramework);
    v_Msg_o.setOpcode_v(container::e_OpFwAppExecuteDone);
    v_Msg_o.setSenderID_v(jobDesc_s.senderId_s32);
    v_Msg_o.setReceiverID_v(jobDesc_s.appMReceiverId_s32);

    sendExternalMessage_b(v_Msg_o, true);
  }

  void sendFrameworkOperationMessage_v(sint32_t i_OpCode_s32, sint32_t i_Parameter1_s32, bool_t i_WaitForEver_b)
  {
    container::Message v_Msg_o;
    v_Msg_o.setMessageType_v(container::e_MtFramework);
    v_Msg_o.setSenderID_v(jobDesc_s.senderId_s32);
    v_Msg_o.setReceiverID_v(jobDesc_s.appMReceiverId_s32);
    v_Msg_o.setOpcode_v(i_OpCode_s32);
    v_Msg_o.setParameter1_v(i_Parameter1_s32);

    sendExternalMessage_b(v_Msg_o, i_WaitForEver_b);
  }

  void sendInitDoneMessage(const container::JobContext& i_Dispatcher_ro, sint32_t i_ReceiverId_s32)
  {
    container::Message v_Msg_o;
    v_Msg_o.setMessageType_v(container::e_MtFramework);
    v_Msg_o.setSenderID_v(jobDesc_s.senderId_s32);
    v_Msg_o.setReceiverID_v(i_ReceiverId_s32);
    v_Msg_o.setOpcode_v(container::e_OpFwAppInitDone);
    v_Msg_o.setParameter1_v(0);

    i_Dispatcher_ro.getExternalQueue_ro().add_b(v_Msg_o, true);
  }

  bool_t sendExternalMessage_b(const container::Message& i_Message_ro, bool_t i_WaitForEver_b = true) const
  {
    return jobDesc_s.dispatcher_ro.getExternalQueue_ro().add_b(i_Message_ro, i_WaitForEver_b);
  }

  bool_t sendInternalMessage_b(const container::Message& i_Message_ro, bool_t i_WaitForEver_b = true)
  {
    return jobDesc_s.dispatcher_ro.getInternalQueue_ro().add_b(i_Message_ro, i_WaitForEver_b);
  }

  bool_t sendSystemMessage_b(const container::Message& i_Message_ro, bool_t i_WaitForEver_b = true)
  {
    return jobDesc_s.dispatcher_ro.getSystemQueue_ro().add_b(i_Message_ro, i_WaitForEver_b);
  }

private:
  virtual void handleMessage_v(const Message& i_Msg_ro) ME_OVERRIDE ME_FINAL
  {
    logger_o.log_b(logging::e_LogLvlVerbose, "%s::handleMessage_v() - Sender: %d", jobDesc_s.ownContext_ro.getContextName_pc(), i_Msg_ro.getSenderID_s32());
    logger_o.log_b(logging::e_LogLvlVerbose, "%s::handleMessage_v() - MessageType: %d OpCode: %d", jobDesc_s.ownContext_ro.getContextName_pc(), i_Msg_ro.getMessageType_s32(), i_Msg_ro.getOpcode_s32());

    switch(i_Msg_ro.getMessageType_s32())
    {
      case container::e_MtFramework:
      {
        handleFrameworkOperation_v(static_cast<OpCodeFramework_e>(i_Msg_ro.getOpcode_s32()));
        break;
      }
      default:
      {
        logger_o.log_b(logging::e_LogLvlError, "%s::handleMessage_v() - MessageType: %d OpCode: %d not supported", jobDesc_s.ownContext_ro.getContextName_pc(), i_Msg_ro.getMessageType_s32(), i_Msg_ro.getOpcode_s32());
        break;
      }
    }
  }

  void handleFrameworkOperation_v(OpCodeFramework_e i_FwOp_e)
  {
    switch(i_FwOp_e)
    {
      case container::e_OpFwShutdown:
      {
        logger_o.log_b(logging::e_LogLvlInfo, "%s::ExitCondition received", jobDesc_s.ownContext_ro.getContextName_pc());
        isRunning_b = false;
        break;
      }
      case container::e_OpFwAppInit:
      {
        logger_o.log_b(logging::e_LogLvlInfo, "%s::e_OpFwAppInit", jobDesc_s.ownContext_ro.getContextName_pc());

        // trigger this also for the first time, so everyone can configure it's Module with the current variant data
        isRunning_b = onInit_b();

        onVariantChanged_v(true);

        if(isRunning_b == true)
        {
          sendInitDoneMessage(jobDesc_s.dispatcher_ro, jobDesc_s.appMReceiverId_s32);
        }

        break;
      }
      case container::e_OpFwAppExecute:
      {
        logger_o.log_b(logging::e_LogLvlVerbose, "%s::e_OpFwAppExecute", jobDesc_s.ownContext_ro.getContextName_pc());

        jobDesc_s.ownContext_ro.getDataContainer_ro().setActivetime_v(time_o.getTimeMsec_u64());

        while(false == this->onRun_b()){}
        sendAlgoExecutedMessage_v();

        jobDesc_s.ownContext_ro.getDataContainer_ro().setActivetime_v(0);

        break;
      }
      case container::e_OpFwVariantConfigChanged:
        {
          logger_o.log_b(logging::e_LogLvlVerbose, "%s::e_OpFwVariantConfigChanged received", jobDesc_s.ownContext_ro.getContextName_pc());

          this->onVariantChanged_v(false);
          break;
        }
      default:
      {
        logger_o.log_b(logging::e_LogLvlError, "%s::Unknown", jobDesc_s.ownContext_ro.getContextName_pc());
        break;
      }
    }
  }


private:
  // disallow copy and Constructor without arguments, else our system won't work
  JobBase();
  JobBase (const JobBase& i_Rhs_ro);
  const JobBase& operator=(const JobBase& i_Rhs_ro);

private:
  // must be first due to initializer list in ctor
  JobDesc_s jobDesc_s;

protected:
  // PRQA S 2101 3 // used by deriving classes
  DataProviderDataType& dataProvider_ro;

  logging::Logger logger_o;

private:

  osal::Time time_o;

  // Massage Dispatcher which handles the messaging
  MessageDispatcher dispatcher_o;

  bool_t isRunning_b;

};

} // namespace container

#endif // CONTAINER_JOBBASE_H_
