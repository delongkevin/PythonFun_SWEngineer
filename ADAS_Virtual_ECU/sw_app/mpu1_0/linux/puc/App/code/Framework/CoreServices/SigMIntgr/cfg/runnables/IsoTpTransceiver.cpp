//--------------------------------------------------------------------------
/// @file IsoTpTransceiver.cpp
/// @brief Contains the implementation of the ISO TP transceiver component.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#include "IsoTpTransceiver.h"

#include <mecl/core/Helpers.h>

#include <osal/system/Time.h>

namespace sigm
{

IsoTpTransceiver::IsoTpTransceiver()
 : logger_o()
 , network_po(NULL)
 , msgHandler_po(NULL)
 , rawIsoTpFrameFiFoMutex_o()
 , rawIsoTpFrameFifo_o()
 , channelAssocs_o()
 , flowControlEnabled_b(false) // The flow control mode is per default disabled
{
}

IsoTpTransceiver::~IsoTpTransceiver()
{
  disbleFlowControl_v();
}

bool_t IsoTpTransceiver::registerNetwork_b(osal::INetwork* b_Network_po)
{
  bool_t v_Result_b = true;

  Assert(NULL == network_po);
  Assert(NULL != b_Network_po);
  network_po = b_Network_po;

  return v_Result_b;
}


bool_t IsoTpTransceiver::registerHandler_b(osal::INetworkMsgHandler* b_Handler_po)
{
  bool_t v_Result_b = true;

  Assert(NULL == msgHandler_po);
  Assert(NULL != b_Handler_po);
  msgHandler_po = b_Handler_po;

  return v_Result_b;
}

void IsoTpTransceiver::init_v()
{
  // Turn OFF the flow control mode: re-enable it again, if the CuC is ready
  disbleFlowControl_v();
  // enableFlowControl_v();

  // Add ISO-TP channel associations here
/*  addChannelAssociation_v(e_ScreenRequest,             e_ScreenResponse);
  addChannelAssociation_v(e_VehicleStateRequest,       e_VehicleStateResponse);
  addChannelAssociation_v(e_TRA_Data_Request,          e_TRA_Data_Response);
  addChannelAssociation_v(e_Request_Camera_ApplyCalib, e_Response_Camera_ApplyCalib);
  addChannelAssociation_v(e_Request_EOL_Start,         e_Response_EOL_Start);
  addChannelAssociation_v(e_Request_EOL_Stop,          e_Response_EOL_Stop);
  addChannelAssociation_v(e_Request_EOL_Status,        e_Response_EOL_Status);
  addChannelAssociation_v(e_ErrorStateRequest,         e_ErrorStateResponse);
  addChannelAssociation_v(e_Request_Camera_GetEeprom,  e_Response_Camera_GetEeprom);
*/
  logger_o.config_b(logging::e_LogLvlInfo, "SIGM", "ISOT", logging::e_LogModeMaskAll);
  
  logger_o.log_b(logging::e_LogLvlInfo, "IsoTpTransceiver::init_v() - done\n");
}

void IsoTpTransceiver::addChannelAssociation_v(const IpcMsgId_t& i_RequestMsgId_rt, const IpcMsgId_t& i_ResponceMsgId_rt)
{
  IsoTpChannelCtrl_t isoTpChannelCtrl_o;
  isoTpChannelCtrl_o.respMsgId_u16 = i_ResponceMsgId_rt;

  IsoTpChannelAssoc_t v_NewChannelAssoc_o(i_RequestMsgId_rt, isoTpChannelCtrl_o);

  channelAssocs_o.insert(v_NewChannelAssoc_o);

  rxReSet_v(i_RequestMsgId_rt);
}

IsoTpChannelCtrl_t& IsoTpTransceiver::getAssotiatedChannel_ro(const uint16_t& i_CanMsgId_ru16) const
{
  const IsoTpChannelCtrl_t& c_Res_ro = channelAssocs_o.at(i_CanMsgId_ru16);
  IsoTpChannelCtrl_t& v_Res_ro = const_cast<IsoTpChannelCtrl_t&>(c_Res_ro);
  return v_Res_ro;
}

bool_t IsoTpTransceiver::run_b()
{
  const bool_t c_GotNewData_b = processReceivedData_b();
  const bool_t c_IsIdle_b = performIsoTpDataTransmisson_b();
  checkTimeOut_v();

  if ((false == c_GotNewData_b) && (true == c_IsIdle_b))
  {
    // We don't got new data and all ISO TP channels are idle -> let's sleep a while
    ME_Thread_Sleep_t(1U);
  }

  // always return TRUE, the run_b() has to be called permanently
  return true;
}

bool_t IsoTpTransceiver::processReceivedData_b()
{
  RawIsoTpFrame_t v_RawIsoTpFrame_s;

  bool_t v_GotNewData_b = getNextRawFrameData_b(v_RawIsoTpFrame_s);

  if (true == v_GotNewData_b)
  {
    switch (getFrameType_t(v_RawIsoTpFrame_s))
    {
      case e_SingleFrame:
      {
        handleSingleFrame_v(v_RawIsoTpFrame_s);
      }
      break;

      case e_FirstFrame:
      {
        handleFirstFrame_v(v_RawIsoTpFrame_s);
      }
      break;

      case e_ContinuousFrame:
      {
        handleContinuousFrame_v(v_RawIsoTpFrame_s);
      }
      break;

      case e_FlowControlFrame:
      {
        handleFlowControlFrame_v(v_RawIsoTpFrame_s);
      }
      break;

      default:
      {
        // Unexpected frame type -> ignore

        logger_o.log_b(logging::e_LogLvlError, "CAN_ISOTP: ERROR: Unexpected frame type. \n");
      }
      break;
    }
  }

  return v_GotNewData_b;
}

bool_t IsoTpTransceiver::performIsoTpDataTransmisson_b()
{
  bool_t v_IsIdle_b = true;

  IsoTpChannelAssocs_t::iterator v_ChannelAssocIterator_o;
  for (v_ChannelAssocIterator_o = channelAssocs_o.begin(); v_ChannelAssocIterator_o != channelAssocs_o.end(); ++v_ChannelAssocIterator_o)
  {
    IsoTpChannelCtrl_t& v_Channel_rt = v_ChannelAssocIterator_o->second;
    switch (v_Channel_rt.channelTxState_t)
    {
      case e_IsoTpTxState_StartSending:
      {
        handleTxStartSendingState_v(v_Channel_rt);
        v_IsIdle_b = false;
      }
      break;

      case e_IsoTpTxState_WaitFc:
      {
        handleTxWaitFcState_v(v_Channel_rt);
        v_IsIdle_b = false;
      }
      break;

      case e_IsoTpTxState_WaitMinSt:
      {
        handleTxWaitMinStState_v(v_Channel_rt);
        v_IsIdle_b = false;
      }
      break;

      case e_IsoTpTxState_ContinueSending:
      {
        handleContinueSendingState_v(v_Channel_rt);
        v_IsIdle_b = false;
      }
      break;

      default:
      {
        // Nothing to do yet.
      }
      break;
    }
  }

  return v_IsIdle_b;
}

void IsoTpTransceiver::checkTimeOut_v()
{
  IsoTpChannelAssocs_t::iterator v_ChannelAssocIterator_o;
  for (v_ChannelAssocIterator_o = channelAssocs_o.begin(); v_ChannelAssocIterator_o != channelAssocs_o.end(); ++v_ChannelAssocIterator_o)
  {
    IsoTpChannelCtrl_t& v_Channel_rt = v_ChannelAssocIterator_o->second;
    if (true == isTimerRunning_b(v_Channel_rt))
    {
      if(true == isTimerTimedOut_b(v_Channel_rt, c_IsoTpWaitFcTimeOut_u64))
      {
        if (e_IsoTpTxState_Idle != v_Channel_rt.channelTxState_t)
        {
          logger_o.log_b(logging::e_LogLvlError, "CAN_ISOTP: ERROR: Tx channel is timed out [mID: 0x%03X]! \n", v_ChannelAssocIterator_o->first);
          txReSet_v(v_Channel_rt);
        }
        if (e_IsoTpRxState_Idle != v_Channel_rt.channelRxState_t)
        {
          logger_o.log_b(logging::e_LogLvlError, "CAN_ISOTP: ERROR: Rx channel is timed out [mID: 0x%03X]! \n", v_ChannelAssocIterator_o->first);
          rxReSet_v(v_ChannelAssocIterator_o->first);
        }
        stopTimer_v(v_Channel_rt);
      }
    }
  }
}

void IsoTpTransceiver::handleTxStartSendingState_v(IsoTpChannelCtrl_t& b_Channel_rt)
{
  if (b_Channel_rt.txPayLoadLen_u16 <= 7U)
  {
    sendSingleFrameMessage_v(b_Channel_rt);
    txReSet_v(b_Channel_rt);
  }
  else
  {
    sendFirstFrameMessage_v(b_Channel_rt);
    if (true == isFlowControlEnabled_b())
    {
      // Flow control mode is enabled -> wait for FC-frame
      b_Channel_rt.channelTxState_t = e_IsoTpTxState_WaitFc;
      startTimer_v(b_Channel_rt);
    }
    else
    {
      // Flow control mode is disabled -> just send the rest of data
      b_Channel_rt.channelTxState_t = e_IsoTpTxState_ContinueSending;
    }
  }
}

void IsoTpTransceiver::handleTxWaitFcState_v(IsoTpChannelCtrl_t& b_Channel_rt)
{
  if (true == b_Channel_rt.txFcFrameReceived_b)
  {
    // FC received -> switch state.
    b_Channel_rt.channelTxState_t = e_IsoTpTxState_WaitMinSt;
    b_Channel_rt.txFcFrameReceived_b = false;
    startTimer_v(b_Channel_rt);
  }
  else
  {
    // FC is still not received -> check time out
    if (true == isTimerTimedOut_b(b_Channel_rt, c_IsoTpWaitFcTimeOut_u64))
    {
      // Timeout occured -> abort transmission
      logger_o.log_b(logging::e_LogLvlWarning, "ISOTP: ERROR: Awaiting of FlowControl frame is timed out! \n");
      txReSet_v(b_Channel_rt);
    }
  }
}

void IsoTpTransceiver::handleTxWaitMinStState_v(IsoTpChannelCtrl_t& b_Channel_rt)
{
  if (true == isTimerTimedOut_b(b_Channel_rt, b_Channel_rt.txMinSepTime_u8))
  {
    // Timeout occured -> switch state
    b_Channel_rt.channelTxState_t = e_IsoTpTxState_ContinueSending;
    stopTimer_v(b_Channel_rt);
  }
}

void IsoTpTransceiver::handleContinueSendingState_v(IsoTpChannelCtrl_t& b_Channel_rt)
{
  if (true == hasDataToSend_b(b_Channel_rt))
  {
    // Send next frame
    sendContinuousFrameMessage_v(b_Channel_rt);

    // Check block size
    if (true == isBlockSizeExhausted_b(b_Channel_rt))
    {
      // Block size exhausted -> switch state
      b_Channel_rt.channelTxState_t = e_IsoTpTxState_WaitFc;
    }
    else
    {
      // Block size is not exhausted -> wait for min. separation time!
      b_Channel_rt.channelTxState_t = e_IsoTpTxState_WaitMinSt;
    }
    startTimer_v(b_Channel_rt);
  }
  else
  {
    txReSet_v(b_Channel_rt);
  }
}

bool_t IsoTpTransceiver::isBlockSizeExhausted_b(const IsoTpChannelCtrl_t& b_Channel_rt)
{
  bool_t v_Result_b = false;

  v_Result_b = (b_Channel_rt.txFrmCnt_u8 == (b_Channel_rt.txBlockStartFrmCnt_u8 + b_Channel_rt.txBlockSize_u8));
  v_Result_b = hasDataToSend_b(b_Channel_rt) && v_Result_b;

  return v_Result_b;
}

bool_t IsoTpTransceiver::hasDataToSend_b(const IsoTpChannelCtrl_t& b_Channel_rt)
{
  return (b_Channel_rt.txIndex_u16 < b_Channel_rt.txPayLoadLen_u16);
}

void IsoTpTransceiver::sendContinuousFrameMessage_v(IsoTpChannelCtrl_t& b_Channel_rt)
{
  uint8_t cfFrameMsgBuf_pu8[10U];
  memset(cfFrameMsgBuf_pu8, 0U, sizeof(cfFrameMsgBuf_pu8));

  // inc. frame counter
  b_Channel_rt.txFrmCnt_u8++;

  // set msg id
  memcpy(&cfFrameMsgBuf_pu8[0U], &b_Channel_rt.respMsgId_u16, sizeof(uint16_t));

  // swap msg id bytes
  swapMsgIdBytes_v(cfFrameMsgBuf_pu8);

  // set CF frame type and frame counter
  cfFrameMsgBuf_pu8[c_CanDataIndex_u8] = static_cast<uint8_t>(e_ContinuousFrame | b_Channel_rt.txFrmCnt_u8);

  // calculate number of bytes to send
  uint8_t v_BytesToSend_u8 = b_Channel_rt.txPayLoadLen_u16 - b_Channel_rt.txIndex_u16;
  if (v_BytesToSend_u8 >= 7U)
  {
    v_BytesToSend_u8 = 7U;
  }

  // copy data to send
  memcpy(&cfFrameMsgBuf_pu8[3U], &(b_Channel_rt.txDataBuf_pu8[b_Channel_rt.txIndex_u16]), v_BytesToSend_u8);

  // set new tx ctrl values
  b_Channel_rt.txIndex_u16 += v_BytesToSend_u8;

  network_po->send_b(cfFrameMsgBuf_pu8, sizeof(cfFrameMsgBuf_pu8));
}

void IsoTpTransceiver::sendSingleFrameMessage_v(IsoTpChannelCtrl_t& b_Channel_rt)
{
  uint8_t sfFrameMsgBuf_pu8[10U];
  memset(sfFrameMsgBuf_pu8, 0U, sizeof(sfFrameMsgBuf_pu8));

  // set msg id
  memcpy(&sfFrameMsgBuf_pu8[0U], &b_Channel_rt.respMsgId_u16, sizeof(uint16_t));

  // swap msg id bytes
  swapMsgIdBytes_v(sfFrameMsgBuf_pu8);

  // set SF frame type and msg sise
  sfFrameMsgBuf_pu8[2U] = static_cast<uint8_t>(e_SingleFrame | static_cast<uint8_t>(b_Channel_rt.txPayLoadLen_u16 & 0x0FFU));

  // copy payload data
  memcpy(&sfFrameMsgBuf_pu8[3U], b_Channel_rt.txDataBuf_pu8, b_Channel_rt.txPayLoadLen_u16);

  network_po->send_b(sfFrameMsgBuf_pu8, 10U);
}

void IsoTpTransceiver::sendFirstFrameMessage_v(IsoTpChannelCtrl_t& b_Channel_rt)
{
  uint8_t ffFrameMsgBuf_pu8[10U];
  memset(ffFrameMsgBuf_pu8, 0U, sizeof(ffFrameMsgBuf_pu8));

  memcpy(&ffFrameMsgBuf_pu8[0U], &b_Channel_rt.respMsgId_u16, sizeof(uint16_t));

  // swap msg id bytes
  swapMsgIdBytes_v(ffFrameMsgBuf_pu8);

  // set payload length and type of frame
  uint16_t v_FrameTypeAndSize_u16 = static_cast<uint16_t>(e_FirstFrame << c_CanMsgIdShiftLen_u8);
  v_FrameTypeAndSize_u16 |= b_Channel_rt.txPayLoadLen_u16;
  memcpy(&ffFrameMsgBuf_pu8[c_CanDataIndex_u8], &v_FrameTypeAndSize_u16, sizeof(uint16_t));

  // swap bytes for the rigth order
  swapMsgIdBytes_v(&ffFrameMsgBuf_pu8[c_CanDataIndex_u8]);

  // copy payload data
  memcpy(&ffFrameMsgBuf_pu8[4U], b_Channel_rt.txDataBuf_pu8, 6U);

  // set the tx index
  b_Channel_rt.txIndex_u16 = 6U;

  // set frame counter
  b_Channel_rt.txFrmCnt_u8 = 0U;

  network_po->send_b(ffFrameMsgBuf_pu8, sizeof(ffFrameMsgBuf_pu8));
}

IsoTpFrameType_t IsoTpTransceiver::getFrameType_t(const RawIsoTpFrame_t& b_NextRawFrameData_rt)
{
  return static_cast<IsoTpFrameType_t>(b_NextRawFrameData_rt.frmData_pu8[0U] & c_IsoTpFrameTypeMask_u8);
}

void IsoTpTransceiver::handleSingleFrame_v(const RawIsoTpFrame_t& i_SingleFrameData_rt)
{
  IsoTpChannelCtrl_t v_Channel_rt = getAssotiatedChannel_ro(i_SingleFrameData_rt.msgId_u16);

  // TP must be idle for processing the SF
  if (e_IsoTpRxState_Idle == v_Channel_rt.channelRxState_t)
  {
    // get pay load data length
    uint8_t v_PayLoadDataLength_u8 = i_SingleFrameData_rt.frmData_pu8[0U] & c_IsoTpSingleFramePayloadDataLenMask_u8;

    // The payload data length must be within valid range
    if ((v_PayLoadDataLength_u8 >= c_MinIsoTpFramePayLoadLen_u8) && (v_PayLoadDataLength_u8 <= c_MaxIsoTpFramePayLoadLen_u8))
    {
      // check, if message handler is registered
      AssertMsg(NULL != msgHandler_po, "CAN_ISOTP: Message handler is not registered yet! \r\n");

      // copy recieved data
      uint8_t* v_DataBuf_pu8 = v_Channel_rt.rxDataBuf_pu8;
      memcpy(&v_DataBuf_pu8[0U], &i_SingleFrameData_rt.msgId_u16, sizeof(uint16_t));
      memcpy(&v_DataBuf_pu8[2U], &i_SingleFrameData_rt.frmData_pu8[1U], v_PayLoadDataLength_u8);

      // swap msg id bytes
      swapMsgIdBytes_v(v_DataBuf_pu8);

      // call the message handler
      msgHandler_po->onReceive_v(reinterpret_cast<osal::INetwork*>(this), v_DataBuf_pu8, v_PayLoadDataLength_u8 + sizeof(uint16_t));
      rxReSet_v(i_SingleFrameData_rt.msgId_u16);
    }
  }
  else
  {
    logger_o.log_b(logging::e_LogLvlError, "CAN_ISOTP: ERROR: Got ISO TP SF, but the channel is not idle! \n");
  }
}

void IsoTpTransceiver::handleFirstFrame_v(const RawIsoTpFrame_t& i_SingleFrameData_rt)
{
  IsoTpChannelCtrl_t& v_Channel_rt = getAssotiatedChannel_ro(i_SingleFrameData_rt.msgId_u16);

  // TP must be idle for processing the FF
  if (e_IsoTpRxState_Idle == v_Channel_rt.channelRxState_t)
  {
     // get pay load data length
     uint16_t v_PayLoadDataLength_u16 = ((i_SingleFrameData_rt.frmData_pu8[0U] & c_IsoTpFirstFramePayloadDataLenHiMask_u8) << c_CanMsgIdShiftLen_u8);
     v_PayLoadDataLength_u16 += (i_SingleFrameData_rt.frmData_pu8[1U] & c_IsoTpFirstFramePayloadDataLenLoMask_u16);

     if ((v_PayLoadDataLength_u16 >= c_MaxIsoTpFrameDataLen_u8) && (v_PayLoadDataLength_u16 <= c_IsoTpMaxFfPayLoadLen_u16))
     {
       // copy received data
       uint8_t* v_DataBuf_pu8 = v_Channel_rt.rxDataBuf_pu8;
       memcpy(&v_DataBuf_pu8[0U], &i_SingleFrameData_rt.msgId_u16, sizeof(uint16_t));
       memcpy(&v_DataBuf_pu8[2U], &i_SingleFrameData_rt.frmData_pu8[2U], 6U);

       // swap msg id bytes
       swapMsgIdBytes_v(v_DataBuf_pu8);

       //set rx variables
       v_Channel_rt.rxFrmCnt_u8 = 0x1U;
       v_Channel_rt.rxPayLoadLen_u16 = v_PayLoadDataLength_u16;
       v_Channel_rt.rxIndex_u16 = 8U;
       v_Channel_rt.channelRxState_t = e_IsoTpRxState_Receiving;

       // Start timer
       startTimer_v(v_Channel_rt);

       if (true == isFlowControlEnabled_b())
       {
         // The flow control mode is enabled -> send the flow control frame
         sendControlFrame_v(i_SingleFrameData_rt);
       }
     }
     else
     {
       logger_o.log_b(logging::e_LogLvlError, "CAN_ISOTP: ERROR: Got ISO TP FF with data len = %d, which is out of range! \n", v_PayLoadDataLength_u16);
     }
  }
  else
  {
    logger_o.log_b(logging::e_LogLvlError, "CAN_ISOTP: ERROR: Got ISO TP FF, but the channel is not idle [mId: 0x%03X]! \n", i_SingleFrameData_rt.msgId_u16);
  }
}

void IsoTpTransceiver::handleContinuousFrame_v(const RawIsoTpFrame_t& i_SingleFrameData_rt)
{
  IsoTpChannelCtrl_t& v_Channel_rt = getAssotiatedChannel_ro(i_SingleFrameData_rt.msgId_u16);

  // TP must be idle for processing the CF
  if (e_IsoTpRxState_Receiving == v_Channel_rt.channelRxState_t)
  {
    uint8_t v_FrameCounter_u8 = i_SingleFrameData_rt.frmData_pu8[0U] & 0x0F;

    // check for valid frame counter
    if (v_FrameCounter_u8 == v_Channel_rt.rxFrmCnt_u8)
    {
      // calculate number of bytes to copy
      uint8_t v_BytesToCpoy_u8 = (v_Channel_rt.rxPayLoadLen_u16 + 2U) - v_Channel_rt.rxIndex_u16;
      if (v_BytesToCpoy_u8 >= 7U)
      {
        v_BytesToCpoy_u8 = 7U;
      }

      // copy received data
      uint8_t* v_DataBuf_pu8 = &v_Channel_rt.rxDataBuf_pu8[0U];
      uint16_t v_RxIdx_u16 = v_Channel_rt.rxIndex_u16;
      memcpy(&v_DataBuf_pu8[v_RxIdx_u16], &i_SingleFrameData_rt.frmData_pu8[1U], v_BytesToCpoy_u8);
      v_Channel_rt.rxIndex_u16 += v_BytesToCpoy_u8;

      // inc. frame counter
      v_Channel_rt.rxFrmCnt_u8++;
      if (v_Channel_rt.rxFrmCnt_u8 > 0x0FU)
      {
    	  v_Channel_rt.rxFrmCnt_u8 = 0U;
      }

      // Start timer
      startTimer_v(v_Channel_rt);

      // check for end of block transfer
      if (v_Channel_rt.rxIndex_u16 >= v_Channel_rt.rxPayLoadLen_u16)
      {
    	// stop timer
    	stopTimer_v(v_Channel_rt);

    	const size_t v_BufferLength_t = v_Channel_rt.rxPayLoadLen_u16 + sizeof(uint16_t);

    	// reset rx channel data
    	rxReSet_v(i_SingleFrameData_rt.msgId_u16);

        // call the message handler
        msgHandler_po->onReceive_v(reinterpret_cast<osal::INetwork*>(this), v_DataBuf_pu8, v_BufferLength_t);
      }
    }
    else
    {
      rxReSet_v(i_SingleFrameData_rt.msgId_u16);
      // Got invalid frame counter -> abort
      logger_o.log_b(logging::e_LogLvlError, "CAN_ISOTP: ERROR: Invalid frame counter [got: %d, expected: %d, mID: 0x%03X]! \n", v_FrameCounter_u8, v_Channel_rt.rxFrmCnt_u8, i_SingleFrameData_rt.msgId_u16);
    }
  }
  else
  {
    rxReSet_v(i_SingleFrameData_rt.msgId_u16);
    // Got invalid frame type (the channel is not in receiving sate!) -> abort
    logger_o.log_b(logging::e_LogLvlError, "CAN_ISOTP: ERROR: Invalid frame type [got: CF, expected: FF, mID: 0x%03X]! \n", i_SingleFrameData_rt.msgId_u16);
  }
}

void IsoTpTransceiver::handleFlowControlFrame_v(const RawIsoTpFrame_t& i_SingleFrameData_rt)
{
  // read the flow status: 0 -> ClearToSend, 1 -> Wait, 2 -> Overflow.
  const uint8_t c_FlowStatus_u8 = (i_SingleFrameData_rt.frmData_pu8[0U] & 0x0FU);

  // read the block size.
  const uint8_t c_BlockSize_u8 = (i_SingleFrameData_rt.frmData_pu8[1U]);

  // read the min. separation time in ms.
  const uint8_t c_MinSepTime_u8 = (i_SingleFrameData_rt.frmData_pu8[2U]);

  IsoTpChannelCtrl_t& v_Channel_rt = getAssotiatedChannel_ro(i_SingleFrameData_rt.msgId_u16);

  if (e_IsoTpTxState_Idle != v_Channel_rt.channelTxState_t)
  {
    // set the flow ctrl data
    v_Channel_rt.txFlowStatus_u8 = c_FlowStatus_u8;
    v_Channel_rt.txBlockSize_u8 = c_BlockSize_u8;
    v_Channel_rt.txMinSepTime_u8 = c_MinSepTime_u8;
    v_Channel_rt.txBlockStartFrmCnt_u8 = v_Channel_rt.txFrmCnt_u8;
    v_Channel_rt.txFcFrameReceived_b = true;

    if (c_FlowStatus_u8 == e_IsoTpFlowCtrl_Overflow)
    {
       logger_o.log_b(logging::e_LogLvlError, "ISOTP: ERROR: Overflow on the receiver (CuC) side! \n");
       txReSet_v(v_Channel_rt);
    }
    else if (c_FlowStatus_u8 == e_IsoTpFlowCtrl_Wait)
    {
      logger_o.log_b(logging::e_LogLvlInfo, "ISOTP: INFO: got 'wait' from receiver (CuC) side! \n");
      v_Channel_rt.channelTxState_t = e_IsoTpTxState_WaitFc;
      v_Channel_rt.txFcFrameReceived_b = false;
      startTimer_v(v_Channel_rt);
    }
    else
    {
      // The flow control status seems to be ClearToSend -> Nothing to do yet.
    }
  }
  else
  {
    // The Tx-channel is in idle state -> ignore flow control frame
  }
}

void IsoTpTransceiver::sendControlFrame_v(const RawIsoTpFrame_t& i_SingleFrameData_rt)
{
    IsoTpChannelCtrl_t& v_Channel_rt = getAssotiatedChannel_ro(i_SingleFrameData_rt.msgId_u16);

    uint8_t fcFrameMsgBuf_pu8[5U];
    memcpy(&fcFrameMsgBuf_pu8[0U], &(v_Channel_rt.respMsgId_u16), sizeof(uint16_t));

    // swap msg id bytes
    swapMsgIdBytes_v(fcFrameMsgBuf_pu8);

    // set FC frame type and ClearToSend status
    fcFrameMsgBuf_pu8[2U] = e_FlowControlFrame;

    // set BlockSize = 0xFF (255)
    fcFrameMsgBuf_pu8[3U] = 0xFFU;

    // set min. separation time = 0
    fcFrameMsgBuf_pu8[4U] = 0x0U;

    network_po->send_b(fcFrameMsgBuf_pu8, 5U);
}

void IsoTpTransceiver::rxReSet_v(const uint16_t& i_CanMsgId_u16)
{
  IsoTpChannelCtrl_t& v_Channel_rt = getAssotiatedChannel_ro(i_CanMsgId_u16);

  v_Channel_rt.channelRxState_t = e_IsoTpRxState_Idle;
  v_Channel_rt.rxFrmCnt_u8 = 0U;
  v_Channel_rt.rxIndex_u16 = 0U;
  v_Channel_rt.rxPayLoadLen_u16 = 0U;
}

void IsoTpTransceiver::txReSet_v(IsoTpChannelCtrl_t& b_Channel_rt)
{
  b_Channel_rt.channelTxState_t = e_IsoTpTxState_Idle;
  b_Channel_rt.txIndex_u16 = 0U;
  b_Channel_rt.txFrmCnt_u8 = 0U;
  b_Channel_rt.txBlockStartFrmCnt_u8 = 0U;
  b_Channel_rt.txPayLoadLen_u16 = 0U;
  b_Channel_rt.txFcFrameReceived_b = false;
  stopTimer_v(b_Channel_rt);
}

void IsoTpTransceiver::swapMsgIdBytes_v(uint8_t* b_MsgBuf_pu8)
{
  uint8_t v_Tmp_u8 = b_MsgBuf_pu8[0U];
  b_MsgBuf_pu8[0U] = b_MsgBuf_pu8[1U];
  b_MsgBuf_pu8[1U] = v_Tmp_u8;
}

void IsoTpTransceiver::cleanup_v()
{
}

bool_t IsoTpTransceiver::send_b(const uint8_t* i_Data_pu8, const uint32_t& i_DataSize_ru32) const
{
  bool_t v_Result_b = false;

  // get response msg id
  uint16_t v_MsgId_u16 = 0U;
  v_MsgId_u16 = static_cast<uint16_t>((i_Data_pu8[c_CanMsgIdMsbIdx_u8] << c_CanMsgIdShiftLen_u8) + i_Data_pu8[c_CanMsgIdLsbIdx_u8]);

  // check if the response msg is ISO TP message
  if (true == isIsoTpRespFrame_b(v_MsgId_u16))
  {
    v_Result_b = prepareMsgDataToSend_b(i_Data_pu8, i_DataSize_ru32, v_MsgId_u16);
  }
  else
  {
    // send non-iso-tp message
    AssertMsg(network_po != NULL, "CAN_ISOTP: ERROR: The network handler is not registered yet! \n");
    v_Result_b = network_po->send_b(i_Data_pu8, i_DataSize_ru32);
  }

  return v_Result_b;
}

bool_t IsoTpTransceiver::prepareMsgDataToSend_b(const uint8_t* i_Data_pu8, const uint32_t& i_DataSize_ru32, const uint16_t& i_RespMsgId_u16) const
{
  bool_t v_Result_b = false;

  const uint16_t& c_CanMsgId_ru16 = findReqMsgId_u16(i_RespMsgId_u16);

  IsoTpChannelCtrl_t& v_Channel_rt = getAssotiatedChannel_ro(c_CanMsgId_ru16);

  if (e_IsoTpTxState_Idle == v_Channel_rt.channelTxState_t)
  {
    if (i_DataSize_ru32 <= (c_IsoTpMaxFfPayLoadLen_u16 - c_CanDataIndex_u8))
    {
      memcpy(v_Channel_rt.txDataBuf_pu8, &i_Data_pu8[c_CanDataIndex_u8], i_DataSize_ru32-c_CanDataIndex_u8);
      v_Channel_rt.txIndex_u16 = 0U;
      v_Channel_rt.txPayLoadLen_u16 = i_DataSize_ru32-c_CanDataIndex_u8;
      v_Channel_rt.channelTxState_t = e_IsoTpTxState_StartSending;
      v_Result_b = true;
    }
  }

  return v_Result_b;
}

uint16_t IsoTpTransceiver::findReqMsgId_u16(const uint16_t& i_RespMsgId_u16) const
{
  uint16_t v_Result_u16 = 0U;

  IsoTpChannelAssocs_t::const_iterator v_ChannelAssocIterator_o;
  for (v_ChannelAssocIterator_o = channelAssocs_o.begin(); v_ChannelAssocIterator_o != channelAssocs_o.end(); ++v_ChannelAssocIterator_o)
  {
    const IsoTpChannelCtrl_t& c_Channel_rt = v_ChannelAssocIterator_o->second;
    if (c_Channel_rt.respMsgId_u16 == i_RespMsgId_u16)
    {
      v_Result_u16 = static_cast<uint16_t>(v_ChannelAssocIterator_o->first);
      break;
    }
  }

  return v_Result_u16;
}

void IsoTpTransceiver::onReceive_v(osal::INetwork* i_NetworkInterface_po, uint8_t* i_Buffer_pu8, size_t i_BufferLength_t)
{
  mecl::core::UnusedParameter(i_NetworkInterface_po);

  uint16_t v_MsgId_u16 = 0U;
  memcpy(reinterpret_cast<void*>(&v_MsgId_u16), reinterpret_cast<void*>(i_Buffer_pu8), sizeof(uint16_t));

  if (true == isIsoTpReqFrame_b(v_MsgId_u16))
  {
    // check msg length
    if (i_BufferLength_t <= c_MaxIsoTpFrameDataLen_u8 + c_CanDataIndex_u8)
    {
      RawIsoTpFrame_t rawIsoTpFrame_s;
      memcpy(reinterpret_cast<void*>(&rawIsoTpFrame_s), reinterpret_cast<void*>(i_Buffer_pu8), c_MaxIsoTpFrameDataLen_u8 + c_CanDataIndex_u8);
      rawIsoTpFrameFiFoMutex_o.take_b();
      rawIsoTpFrameFifo_o.push(rawIsoTpFrame_s);
      rawIsoTpFrameFiFoMutex_o.give_v();
    }
    else
    {
      logger_o.log_b(logging::e_LogLvlError, "CAN_ISOTP: ERROR: Unexpected msg length %d for msgId = 0x%03X \n", i_BufferLength_t-c_CanDataIndex_u8, v_MsgId_u16);
    }
  }
  else
  {
    AssertMsg(NULL != msgHandler_po, "CAN_ISOTP: Message handler is not registered yet! \r\n");

    // swap msg id bytes
    swapMsgIdBytes_v(i_Buffer_pu8);

    // call onReceive_v() of SigM
    msgHandler_po->onReceive_v(i_NetworkInterface_po, i_Buffer_pu8, i_BufferLength_t);
  }
}

bool_t IsoTpTransceiver::getNextRawFrameData_b(RawIsoTpFrame_t& b_NextRawFrameData_rt)
{
  bool_t v_GotNewData_b = false;

  // check if data is available
  rawIsoTpFrameFiFoMutex_o.take_b();
  if (false == rawIsoTpFrameFifo_o.empty())
  {
    b_NextRawFrameData_rt = rawIsoTpFrameFifo_o.front();
    rawIsoTpFrameFifo_o.pop();
    v_GotNewData_b = true;
  }
  rawIsoTpFrameFiFoMutex_o.give_v();

  return v_GotNewData_b;
}

bool_t IsoTpTransceiver::isIsoTpReqFrame_b(const uint16_t& i_CanMsgId_ru16)
{
  return (0x01U == channelAssocs_o.count(i_CanMsgId_ru16));
}

bool_t IsoTpTransceiver::isIsoTpRespFrame_b(const uint16_t& i_CanMsgId_ru16) const
{
  bool v_Result_b = false;

  IsoTpChannelAssocs_t::const_iterator v_ChannelAssocIterator_o;
  for (v_ChannelAssocIterator_o = channelAssocs_o.begin(); v_ChannelAssocIterator_o != channelAssocs_o.end(); ++v_ChannelAssocIterator_o)
  {
    const IsoTpChannelCtrl_t& c_Channel_rt = v_ChannelAssocIterator_o->second;

    if (c_Channel_rt.respMsgId_u16 == i_CanMsgId_ru16)
    {
      v_Result_b = true;
      break;
    }
  }

  return v_Result_b;
}

void IsoTpTransceiver::startTimer_v(IsoTpChannelCtrl_t& b_Channel_rt)
{
  b_Channel_rt.txTimerStart_u64 = osal::Time().getTimeMsec_u64();
}

void IsoTpTransceiver::stopTimer_v(IsoTpChannelCtrl_t& b_Channel_rt)
{
  b_Channel_rt.txTimerStart_u64 = 0U;
}

bool_t IsoTpTransceiver::isTimerRunning_b(const IsoTpChannelCtrl_t& i_Channel_rt)
{
  return (i_Channel_rt.txTimerStart_u64 > 0U);
}

bool_t IsoTpTransceiver::isTimerTimedOut_b(const IsoTpChannelCtrl_t& i_Channel_rt, const uint64_t& i_TimeOutMs_u64)
{
  uint64_t v_CurrentTime_u64 = osal::Time().getTimeMsec_u64();
  uint64_t v_TimeDiff_u64 = v_CurrentTime_u64 - i_Channel_rt.txTimerStart_u64;

  return (v_TimeDiff_u64 >= i_TimeOutMs_u64);
}

void IsoTpTransceiver::enableFlowControl_v()
{
  flowControlEnabled_b = true;
}

void IsoTpTransceiver::disbleFlowControl_v()
{
  flowControlEnabled_b = false;
}

bool_t IsoTpTransceiver::isFlowControlEnabled_b()
{
  return (true == flowControlEnabled_b);
}

} // namespace sigm
