//--------------------------------------------------------------------------
/// @file Can.h
/// @brief Class declaration of Can server
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
//  --------------------------------------------------------------------------

#ifndef CAN_H
#define CAN_H

#include "cfg/BspTypes.h"
#include <osal/networking/INetwork.h>

namespace bsp
{

namespace {
 static const char* c_CanDevRxName_pc = "/dev/can2/rx0";
 static const char* c_CanDevTxName_pc = "/dev/can2/tx4";

 static uint8_t c_ReopenSleepTime_u8  = 250U;

 static const uint32_t c_FrameDataMaxBufferSize_u32 = 512U;

 static const uint8_t c_CanMsgIdShiftLen_u8 = 8U;
 static const uint32_t c_CanMsgIdMask_u32 = 0x0FFU;

 static const uint8_t c_CanMsgIdMsbIdx_u8 = 0U;
 static const uint8_t c_CanMsgIdLsbIdx_u8 = 1U;
 static const uint8_t c_CanDataIndex_u8 = 2U;
}

typedef enum {
 e_CanRxChannel = 0U,
 e_CanTxChannel,
 e_CanChannelCnt
} CanChannelType_t;

typedef enum {
 e_ChannelStatusSendFailed =0,
 e_ChannelStatusOpened,
 e_ChannelStatusClosed
} CanChannelStatus_t;

class Can : public osal::INetwork
{

public:
  explicit Can();
  virtual ~Can();

  void                       init_v(const uint8_t& i_ChannelId_ru8);
  bool_t                     open_b();

  // INetwork interface methods
  virtual bool_t             registerHandler_b(osal::INetworkMsgHandler* b_Handler_po) ME_OVERRIDE;
  virtual bool_t             process_b() ME_OVERRIDE;
  virtual void               shutdown_v() ME_OVERRIDE;
  virtual bool_t             send_b(const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t) ME_OVERRIDE;

private:
  virtual bool_t openRxChannel_b();
  virtual bool_t openTxChannel_b();
  virtual void tryReopen_v();
  virtual void processFrameData_v(const CanMessage_t& i_CanMsg_ro);
  virtual bool_t isOpened_b() const;

private:
  CanChannelType_t          canChannelType_e;
  CanChannelStatus_t        canChannelStatus_e;
  CanHandleRx_t             canHandleRx_t;
  CanHandleTx_t             canHandleTx_t;

  osal::INetworkMsgHandler* msgHandler_po;
  uint8_t                   frameDataBuf_au8[c_FrameDataMaxBufferSize_u32];

}; // class Can

} // namespace bsp

#endif // CAN_H
