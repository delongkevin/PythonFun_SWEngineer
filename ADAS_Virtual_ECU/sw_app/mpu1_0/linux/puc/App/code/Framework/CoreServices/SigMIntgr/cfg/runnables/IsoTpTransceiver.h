//--------------------------------------------------------------------------
/// @file IsoTpTransceiver.h
/// @brief Contains the definition for the ISO TP transceiver component.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ISO_TP_TRANSCEIVER_H
#define ISO_TP_TRANSCEIVER_H

#include <osal/threading/Mutex.h>
#include <osal/threading/IRunnable.h>
#include <osal/networking/INetwork.h>
#include <osal/networking/INetworkMsgHandler.h>

#include <logging/Logger.h>

#include <cfg/shmdata/SigM_Messages.h>

namespace sigm
{

namespace
{
  static const uint8_t c_CanMsgIdShiftLen_u8        = 0x08U;
  static const uint8_t c_CanMsgIdMsbIdx_u8          = 0x00U;
  static const uint8_t c_CanMsgIdLsbIdx_u8          = 0x01U;
  static const uint8_t c_CanDataIndex_u8            = 0x02U;

  static const uint8_t c_MaxIsoTpFrameDataLen_u8    = 0x08U;

  static const uint8_t c_IsoTpFrameTypeMask_u8      = 0x30U;

  static const uint8_t c_MinIsoTpFramePayLoadLen_u8 = 0x01U;
  static const uint8_t c_MaxIsoTpFramePayLoadLen_u8 = 0x07U;

  static const uint8_t c_IsoTpSingleFramePayloadDataLenMask_u8   = 0x07U;
  static const uint8_t c_IsoTpFirstFramePayloadDataLenHiMask_u8  = 0x0FU;
  static const uint8_t c_IsoTpFirstFramePayloadDataLenLoMask_u16  = 0x0FFU;

  static const uint16_t c_IsoTpMaxFfPayLoadLen_u16 = 0x0FFFU;
  static const uint16_t c_IsoTpMaxPayLoadLen_u16   = 0x1001U; /* 0xFFF -> PayLoad + 0x02U -> MsgId */

  static const uint64_t c_IsoTpWaitFcTimeOut_u64   = 1000UL; /* Timeout for FC-frame max. 1 sec. */
}

typedef struct {
  uint16_t msgId_u16;
  uint8_t frmData_pu8[c_MaxIsoTpFrameDataLen_u8];
} RawIsoTpFrame_t;

typedef enum
{
  e_IsoTpRxState_Idle = 0,    /**< Idle state */
  e_IsoTpRxState_Receiving    /**< Receiving data */
} IsoTpRxChannelState_t;

typedef enum
{
  e_IsoTpFlowCtrl_ClearToSend = 0,
  e_IsoTpFlowCtrl_Wait,
  e_IsoTpFlowCtrl_Overflow
} IsoTpFlowControlStatus_t;

typedef enum
{
  e_IsoTpTxState_Idle = 0,        /**< Idle state */
  e_IsoTpTxState_StartSending,   /**< Start sending data */
  e_IsoTpTxState_WaitFc,          /**< Waiting for flow control frame */
  e_IsoTpTxState_WaitMinSt,       /**< Waiting for min. separation time */
  e_IsoTpTxState_ContinueSending  /**< Continue sending data */
} IsoTpTxChannelState_t;

typedef struct {
  uint16_t respMsgId_u16;
  IsoTpRxChannelState_t channelRxState_t;
  uint8_t rxFrmCnt_u8;
  uint16_t rxPayLoadLen_u16;
  uint16_t rxIndex_u16;
  uint8_t rxDataBuf_pu8[c_IsoTpMaxPayLoadLen_u16];
  IsoTpTxChannelState_t channelTxState_t;
  uint8_t txDataBuf_pu8[c_IsoTpMaxPayLoadLen_u16];
  uint16_t txPayLoadLen_u16;
  uint16_t txIndex_u16;
  uint8_t txFrmCnt_u8;
  uint8_t txBlockStartFrmCnt_u8;
  uint64_t txTimerStart_u64;
  uint8_t txFlowStatus_u8;
  uint8_t txBlockSize_u8;
  uint8_t txMinSepTime_u8;
  bool_t   txFcFrameReceived_b;
} IsoTpChannelCtrl_t;

typedef mepl::queue<RawIsoTpFrame_t> RawIsoTpFrameFifo_t;
typedef std::pair<const uint16_t, sigm::IsoTpChannelCtrl_t> IsoTpChannelAssoc_t;
typedef mepl::map<uint16_t, IsoTpChannelCtrl_t> IsoTpChannelAssocs_t;

typedef enum {
  e_SingleFrame      = 0x00,
  e_FirstFrame       = 0x10,
  e_ContinuousFrame  = 0x20,
  e_FlowControlFrame = 0x30
} IsoTpFrameType_t;

class IsoTpTransceiver : public osal::IRunnable, public osal::INetworkMsgHandler
{
public:
  explicit IsoTpTransceiver();
  virtual ~IsoTpTransceiver();

  virtual void    init_v()        ME_OVERRIDE;
  virtual bool_t  run_b()         ME_OVERRIDE;
  virtual void    cleanup_v()     ME_OVERRIDE;
  virtual bool_t  registerNetwork_b(osal::INetwork* b_Network_po);
  virtual bool_t  registerHandler_b(osal::INetworkMsgHandler* b_Handler_po);
  virtual bool_t  send_b(const uint8_t* i_Data_pu8, const uint32_t& i_DataSize_ru32) const;
  virtual void    onReceive_v(osal::INetwork * i_NetworkInterface_po, uint8_t* i_Buffer_pu8, size_t i_BufferLength_t) ME_OVERRIDE;

private:
  virtual void                 addChannelAssociation_v(const IpcMsgId_t& i_RequestMsgId_rt, const IpcMsgId_t& i_ResponceMsgId_rt);
  virtual IsoTpChannelCtrl_t&  getAssotiatedChannel_ro(const  uint16_t& i_CanMsgId_ru16) const;
  virtual bool_t               isIsoTpReqFrame_b(const uint16_t& i_CanMsgId_ru16);
  virtual bool_t               isIsoTpRespFrame_b(const uint16_t& i_CanMsgId_ru16) const;
  virtual bool_t               processReceivedData_b();
  virtual bool_t               performIsoTpDataTransmisson_b();
  virtual void                 checkTimeOut_v();
  virtual bool_t               getNextRawFrameData_b(RawIsoTpFrame_t& b_NextRawFrameData_rt);
  virtual IsoTpFrameType_t     getFrameType_t(const RawIsoTpFrame_t& b_NextRawFrameData_rt);
  virtual void                 handleSingleFrame_v(const RawIsoTpFrame_t& i_SingleFrameData_rt);
  virtual void                 handleFirstFrame_v(const RawIsoTpFrame_t& i_SingleFrameData_rt);
  virtual void                 handleContinuousFrame_v(const RawIsoTpFrame_t& i_SingleFrameData_rt);
  virtual void                 handleFlowControlFrame_v(const RawIsoTpFrame_t& i_SingleFrameData_rt);
  virtual void                 handleTxStartSendingState_v(IsoTpChannelCtrl_t& b_Channel_rt);
  virtual void                 handleTxWaitFcState_v(IsoTpChannelCtrl_t& b_Channel_rt);
  virtual void                 handleTxWaitMinStState_v(IsoTpChannelCtrl_t& b_Channel_rt);
  virtual void                 sendControlFrame_v(const RawIsoTpFrame_t& i_SingleFrameData_rt);
  virtual void                 sendSingleFrameMessage_v(IsoTpChannelCtrl_t& b_Channel_rt);
  virtual void                 sendFirstFrameMessage_v(IsoTpChannelCtrl_t& b_Channel_rt);
  virtual void                 sendContinuousFrameMessage_v(IsoTpChannelCtrl_t& b_Channel_rt);
  virtual void                 handleContinueSendingState_v(IsoTpChannelCtrl_t& b_Channel_rt);
  virtual bool_t               isBlockSizeExhausted_b(const IsoTpChannelCtrl_t& b_Channel_rt);
  virtual void                 startTimer_v(IsoTpChannelCtrl_t& b_Channel_rt);
  virtual void                 stopTimer_v(IsoTpChannelCtrl_t& b_Channel_rt);
  virtual bool_t               isTimerRunning_b(const IsoTpChannelCtrl_t& b_Channel_rt);
  virtual bool_t               isTimerTimedOut_b(const IsoTpChannelCtrl_t& b_Channel_rt, const uint64_t& i_TimeOutMs_u64);
  virtual bool_t               hasDataToSend_b(const IsoTpChannelCtrl_t& b_Channel_rt);
  virtual bool_t               prepareMsgDataToSend_b(const uint8_t* i_Data_pu8, const uint32_t& i_DataSize_ru32, const uint16_t& i_RespMsgId_u16) const;
  virtual void                 rxReSet_v(const uint16_t& i_CanMsgId_u16);
  virtual void                 txReSet_v(IsoTpChannelCtrl_t& b_Channel_rt);
  virtual void                 swapMsgIdBytes_v(uint8_t* b_MsgBuf_pu8);
  virtual uint16_t             findReqMsgId_u16(const uint16_t& i_RespMsgId_u16) const;
  virtual void                 enableFlowControl_v();
  virtual void                 disbleFlowControl_v();
  virtual bool_t               isFlowControlEnabled_b();

private:

  logging::Logger           logger_o;

  osal::INetwork*           network_po;
  osal::INetworkMsgHandler* msgHandler_po;
  osal::Mutex               rawIsoTpFrameFiFoMutex_o;
  RawIsoTpFrameFifo_t       rawIsoTpFrameFifo_o;
  IsoTpChannelAssocs_t      channelAssocs_o;

  bool_t                    flowControlEnabled_b;
};

} // namespace sigm

#endif // ISO_TP_TRANSCEIVER_H
