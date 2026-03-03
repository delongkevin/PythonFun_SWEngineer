//--------------------------------------------------------------------------
/// @file JobSigM.cpp
/// @brief Contains the job implementation of signal manager.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///         Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------


#include "JobSigM.h"

// Never include cfg specific headers here! (e.g. variants::e_JobSigM enum or Context:: calls
// we will not achieve a loosely coupled job system. Which makes it hard for Integration tests.
// AppM (ApplicationManager) shall be the Main Dispatcher receiver for messages.

#ifdef ENABLE_RUNTIME_STATS
//commented the below #define used for CAN communication
#define PROFILE_SigM   (1u)
#endif
#if PROFILE_SigM
#include "osal/system/Time.h"
static uint32_t v_AvgSigMRuntime_u32 = 0;
static uint32_t v_SigMRunCntr_u32 = 0;
static uint32_t v_AvgSigMPeriodicity_u32 = 0;
static uint32_t v_PreviousTime_u32 = 0;
static uint32_t v_SigMRuntimeData = 0; //Runtime Data contains Execution Time and Periodicity, 31-16: Execution Time and 15-0: Periodicity
static PerformanceStatsEnable_t PerformanceStatsSMEnable_dp;
#endif

namespace sigm
{

JobSigM::JobSigM(container::JobDesc_s& b_JobDesc_rs, IDataProviderSigM& b_DataProvider_ro, osal::INetwork* b_NetInterface_po)
  : JobBase(b_JobDesc_rs, b_DataProvider_ro)
  , INetworkMsgHandler()
  , mutex_o()
  , network_po(b_NetInterface_po)
#ifdef USE_KEEP_ALIVE
  , keepAliveRunnable_o(&b_DataProvider_ro)
  , keepAliveSenderThread_o("KeepAliveSenderThread")
#endif
#ifdef TRA_GATEWAY4
  , TRAGateway4Runnable_o(&b_DataProvider_ro)
  , TRAGateway4SenderThread_o("TRAGateway4SenderThread")
#endif
  , networkMessageRunnable_o(b_DataProvider_ro)
  , networkMessageThread_o("ThreadSigM")
  , MessageSenderRunnable_o(b_DataProvider_ro, *this)
  , messageSenderThread_o("ThreadMessageSender")
#ifdef USE_ISOTP
  , isoTpTransceiver_o()
  , isoTpTransceiverThread_o("IsoTpTransceiverThread")
#endif
{

}

JobSigM::~JobSigM()
{
}

bool_t JobSigM::onInit_b()
{
  bool_t v_Result_b = false;
#ifdef USE_REQUEST_AND_RESPONSE
  // Init non-iso-tp requests
  projectRequests_s.init_v(requestItems_t);
  for (uint32_t v_idx_u32 = 0U; v_idx_u32 < requestItems_t.size_u32(); ++v_idx_u32)
  {
    requestItems_t[v_idx_u32]->init_v(dataProvider_ro, *this);
  }
  // Init signal receivers
#else
  projectReceivers_s.init_v(receiverItems_t);
  for (uint32_t v_idx_u32 = 0U; v_idx_u32 < receiverItems_t.size_u32(); ++v_idx_u32)
  {
    receiverItems_t[v_idx_u32]->init_v(dataProvider_ro, *this);
  }
#endif
  if (NULL != network_po)
  {
    networkMessageRunnable_o.registerNetwork_b(network_po);
#ifdef USE_ISOTP
    isoTpTransceiver_o.registerNetwork_b(network_po);
    isoTpTransceiver_o.registerHandler_b(this);
    network_po->registerHandler_b(&isoTpTransceiver_o);
#else
    network_po->registerHandler_b(this);
#endif

#ifdef USE_KEEP_ALIVE
    // Register callback for keep alive handler
    keepAliveRunnable_o.registerNetwork_v(network_po);
#endif
#ifdef TRA_GATEWAY4
    // Register callback for keep TRAGateway4 handler
    TRAGateway4Runnable_o.registerNetwork_v(network_po);
#endif
    // Register callback for keep MessageSender handler
    MessageSenderRunnable_o.registerNetwork_v(network_po);

    v_Result_b = true;
  }

  startThreads_v();

  return v_Result_b;
}

void JobSigM::onVariantChanged_v(bool_t i_FirstTime_b)
{
  logger_o.log_b(logging::e_LogLvlInfo, "JobSigM::onVariantChanged_v() was triggered \n");
}

bool_t JobSigM::onRun_b()
{
  #if PROFILE_SigM
  PerformanceStatsSMEnable_dp = dataProvider_ro.get_PerformanceStatsEnable();
  static osal::Time start;
  volatile uint32_t v_Start_t = 0;
  volatile uint32_t v_End_t = 0;
  volatile uint32_t currPeriodicity = 0;
  if (TRUE ==  PerformanceStatsSMEnable_dp.RunTimeStatsEnable)
  {
    v_Start_t = __get_time_usec();
    currPeriodicity = v_Start_t - v_PreviousTime_u32;
  }
  #endif

  MEP_BEGIN("onRun", "SigM");
#ifdef USE_KEEP_ALIVE
  keepAliveSenderThread_o.resume_v();
#endif

#ifdef USE_ISOTP
  isoTpTransceiverThread_o.resume_v();
#endif
  networkMessageThread_o.resume_v();
  messageSenderThread_o.resume_v();

  MEP_END("onRun", "SigM");
//  printf("ONRUN_B- %s\n", __PRETTY_FUNCTION__);
  ME_Thread_Sleep_t(5);
  // Nothing to do more -> return FALSE.

  #if PROFILE_SigM
  if (TRUE ==  PerformanceStatsSMEnable_dp.RunTimeStatsEnable)
  {
    v_End_t = __get_time_usec();
    // ME_Debugger_F_Printf_v("SigM: S: %lld E: %lld D: %lld\n", v_Start_t, v_End_t, (v_End_t - v_Start_t));
    v_SigMRunCntr_u32++; //Increment the run counter for averaging purpose
    v_AvgSigMPeriodicity_u32 = ((v_AvgSigMPeriodicity_u32 * (v_SigMRunCntr_u32 -1)) + currPeriodicity)/v_SigMRunCntr_u32; //Average Periodicity
    v_AvgSigMRuntime_u32 = ((v_AvgSigMRuntime_u32 * (v_SigMRunCntr_u32 -1)) + (v_End_t - v_Start_t))/v_SigMRunCntr_u32; //New Average  
    v_SigMRuntimeData = (((v_AvgSigMRuntime_u32/1000U)<<16U) | ((v_AvgSigMPeriodicity_u32/1000U) & 0xFFFF));
    dataProvider_ro.setSigMRuntime(v_SigMRuntimeData);
    //ME_Debugger_F_Printf_v("SigM: E: %lld P: %lld \n", v_AvgSigMRuntime_u32, v_AvgSigMPeriodicity_u32);
    v_PreviousTime_u32 = v_Start_t;
  }
  #endif

  return true;
}

void JobSigM::onCleanup_v()
{
  terminateThreads_v();

  if(NULL != network_po)
  {
    network_po->shutdown_v();
  }
  receiverItems_t.clear_v();
  requestItems_t.clear_v();

}

// this function is called by low level ICommunication Class
void JobSigM::onReceive_v(osal::INetwork * i_NetworkInterface_po, uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
{

  bool_t v_Found_b = false;

  mecl::core::UnusedParameter(i_NetworkInterface_po);

  ME_MsgRx_s v_MsgReceived_s(b_Buffer_pu8, i_BufferLength_t);
  //minimum message length is header +one byte
  if(0x0 ==v_MsgReceived_s.id_e || 3 >= i_BufferLength_t )
  {
    //valid condition. Puc is sending  too frequent request to  Ipc_manger for data.
    //logger_o.log_b(logging::e_LogLvlDebug, "JobSigM::Invalid data receive length is : %d \t MSGId is : %d\n",i_BufferLength_t,v_MsgReceived_s.id_e );
    v_Found_b = true;
  }
  else
  {
    //  logger_o.log_b(logging::e_LogLvlDebug, "JobSigM::received msgiD %d \n",v_MsgReceived_s.id_e);
    mutex_o.take_b();
    v_Found_b = processMessage_b(v_MsgReceived_s);
   // check for direct answers
   if (false == v_Found_b)
   {
#ifdef USE_REQUEST_AND_RESPONSE
     handleErrorneousRequest(v_MsgReceived_s);
#else
     //logs
#endif
   }
   else
   {
     checkBaseRequests_v();
   }
    mutex_o.give_v();
  }
}

bool_t JobSigM::processMessage_b(const ME_MsgRx_s& i_Msg_rx) {
  bool_t v_RetVal_b = false;
#ifdef USE_REQUEST_AND_RESPONSE
  for (uint32_t v_idx_u32 = 0U; (v_idx_u32 < requestItems_t.size_u32()) && (false == v_RetVal_b); ++v_idx_u32)
  {
    BaseRequest& v_BaseRequest_ro = *(requestItems_t[v_idx_u32]);
    if(v_BaseRequest_ro.getReceiveID_t() == i_Msg_rx.id_e)
    {
      logger_o.log_b(logging::e_LogLvlDebug, "JobSigM::BaseRequest [0x%02x]\n", i_Msg_rx.id_e);

      v_BaseRequest_ro.setRequestedMsg_v(i_Msg_rx); // save currently received message to BaseRequest class
      v_BaseRequest_ro.setRequested_v(); // mark BaseRequest as requested

      v_RetVal_b = true;
    }
  }
#else  //handle received messages
  for (uint32_t v_idx_u32 = 0U; (v_idx_u32 < receiverItems_t.size_u32()) && (false == v_RetVal_b); ++v_idx_u32)
  {
    BaseReceiver& v_BaseReceiver_ro = *(receiverItems_t[v_idx_u32]);
    if(v_BaseReceiver_ro.getReceiveID_t() == i_Msg_rx.id_e)
    {
      //logger_o.log_b(logging::e_LogLvlInfo, "JobSigM::BaseReceiver Id is : %d, Index is : %d\n", i_Msg_rx.id_e, v_idx_u32);
      v_BaseReceiver_ro.setReceivedMsg_v(i_Msg_rx); // save currently received message to BaseReceiver class
      v_BaseReceiver_ro.setReceived_v(); // mark BaseReceiver as received new message
      //logger_o.log_b(logging::e_LogLvlInfo, "JobSigM::setReceived_v Id is : %d, Index is : %d\n", i_Msg_rx.id_e, v_idx_u32);
      v_RetVal_b = true;
    }
  }
#endif

  return v_RetVal_b;
}

bool_t JobSigM::send_b(const uint8_t* i_Data_pu8, uint32_t i_DataSize_u32, uint32_t i_Channel_u32)
{
  bool_t v_Result_b = false;
  mutex_o.take_b();

#ifdef USE_ISOTP
  v_Result_b = isoTpTransceiver_o.send_b(i_Data_pu8, i_DataSize_u32);
#else
  v_Result_b = network_po->send_b(i_Data_pu8, i_DataSize_u32);
#endif

  mutex_o.give_v();

  return v_Result_b;
}

void JobSigM::handleErrorneousRequest(const ME_MsgRx_s& i_Msg_rx)
{
#ifdef USE_REQUEST_AND_RESPONSE
  ErrorneousResponse_t v_Response_t;
  v_Response_t.ResponseCode_u8 = static_cast<uint8_t>(variants::e_ResponseCodeNotSupportedCANID);
  v_Response_t.ErrorMessageID_u16 = 0;

  if (i_Msg_rx.msgSize_u32 >= 2U)
  {
    // Read Id from Data Pointer
    uint32_t v_Index_u32 = 0U;
    v_Response_t.ErrorMessageID_u16 = ME_DataSerializer_Read_u16(&i_Msg_rx.data_t[0], &v_Index_u32, true);
  }
  else
  {
    // don't read anything
  }

  // write to message to respond
  ME_Msg_s v_Msg_s(NULL, 0);
  v_Msg_s.msgSize_u32 = BaseRequest::getMessageSize_u32<ErrorneousResponse_t>();
  uint32_t v_Index_u32 = addHeaderToMessage_u32(&v_Msg_s.data_t[0], e_ErrorneousResponse);

  bool_t v_WriteOk_b = writeErrorneousResponse_b(&v_Msg_s.data_t[v_Index_u32], v_Msg_s.msgSize_u32, &v_Response_t);
  if (true == v_WriteOk_b)
  {
    send_b(&v_Msg_s.data_t[0], v_Msg_s.msgSize_u32, 0U);
  }
  else
  {
    logger_o.log_b(logging::e_LogLvlInfo, "JobSigM::handleErrorneousRequest - Failed to write errorneous response \n");
  }
#else
  // error format to be updated.
  //error will be updated in the dataProvider
#endif
}

void JobSigM::checkBaseRequests_v(void)
{
  //if(true == mutex_o.take_b(false))
  {
#ifdef USE_REQUEST_AND_RESPONSE
    for (uint32_t v_idx_u32 = 0U; (v_idx_u32 < requestItems_t.size_u32()) ; ++v_idx_u32)
    {
      BaseRequest& v_BaseRequest_ro = *(requestItems_t[v_idx_u32]);

      if(v_BaseRequest_ro.isActive_b())
      {
        logger_o.log_b(logging::e_LogLvlDebug, "JobSigM::handleRequest_b %d\n", v_idx_u32);
        if (true == v_BaseRequest_ro.handleRequest_b())
        {
          v_BaseRequest_ro.sendResponse_b();
        }
        else
        {
          // request ongoing
          logger_o.log_b(logging::e_LogLvlDebug, "REQUEST ONGOING\n");
        }
      }
      else
      {
        // no request is active
      }
    }
#else
    for (uint32_t v_idx_u32 = 0U; (v_idx_u32 < receiverItems_t.size_u32()) ; ++v_idx_u32)
    {
      BaseReceiver& v_BaseReceiver_ro = *(receiverItems_t[v_idx_u32]);

     if(v_BaseReceiver_ro.isActive_b())
      {
        //logger_o.log_b(logging::e_LogLvlInfo, "JobSigM::handleReceiver_b %d\n", v_idx_u32);
        if (true == v_BaseReceiver_ro.handleReceive_b())
        {
          v_BaseReceiver_ro.setProcess_b();
        }
        else
        {
          // request ongoing
          logger_o.log_b(logging::e_LogLvlInfo, "RECEIVER ONGOING\n");
        }
      }
      else
      {

      }
    }

    //mutex_o.give_v();
#endif
  }
}

void JobSigM::startThreads_v()
{
  // start threads here
#ifdef USE_KEEP_ALIVE
  keepAliveSenderThread_o.start_v(&keepAliveRunnable_o, false);
#endif
  networkMessageThread_o.start_v(&networkMessageRunnable_o, false);
  messageSenderThread_o.start_v(&MessageSenderRunnable_o, false);

}

void JobSigM::terminateThreads_v()
{
#ifdef USE_KEEP_ALIVE
  keepAliveSenderThread_o.terminate_v();
  keepAliveSenderThread_o.join_v();
#endif

#ifdef  TRA_GATEWAY4
  TRAGateway4SenderThread_o.terminate_v();
  TRAGateway4SenderThread_o.join_v();
#endif

#ifdef USE_ISOTP
  isoTpTransceiverThread_o.terminate_v();
  isoTpTransceiverThread_o.join_v();
#endif

  networkMessageThread_o.terminate_v();
  networkMessageThread_o.join_v();

  messageSenderThread_o.terminate_v();
  messageSenderThread_o.join_v();
}

} // namespace sigm

