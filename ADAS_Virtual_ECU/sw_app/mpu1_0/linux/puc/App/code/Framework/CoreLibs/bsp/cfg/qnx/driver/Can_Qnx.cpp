//--------------------------------------------------------------------------
/// @file Can_Qnx.cpp
/// @brief Class implementation of Can server
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
//  --------------------------------------------------------------------------

#include "bsp/driver/Can.h"
#include "osal/networking/INetworkMsgHandler.h"
#include "logging/Logger.h"

namespace bsp
{

#ifdef ME_PLATFORM_QNX

Can::Can()
  : INetwork()
  , canChannelType_e(e_CanRxChannel)
  , canChannelStatus_e(e_ChannelStatusSendFailed)
  , canHandleRx_t()
  , canHandleTx_t()
  , msgHandler_po(NULL)
{
}

Can::~Can()
{
}

void Can::init_v(const uint8_t& i_ChannelId_ru8)
{
  AssertMsg(i_ChannelId_ru8 <= e_CanChannelCnt, "Unexpected CAN channel type %d \r\n", i_ChannelId_ru8);
  canChannelType_e = static_cast<CanChannelType_t>(i_ChannelId_ru8);
}

bool_t Can::open_b()
{
  bool_t v_Result_b = false;

  switch (canChannelType_e)
  {
    case e_CanRxChannel:
    {
      v_Result_b = openRxChannel_b();
    }
    break;

    case e_CanTxChannel:
    {
      v_Result_b = openTxChannel_b();
    }
    break;

    default:
    {
       AssertMsg(true, "Unexpected CAN channel type %d \r\n", static_cast<uint32_t>(canChannelType_e));
    }
    break;
  }

  return v_Result_b;
}

bool_t Can::registerHandler_b(osal::INetworkMsgHandler* b_Handler_po)
{
  bool_t v_Result_b = true;

  Assert(NULL == msgHandler_po);
  Assert(NULL != b_Handler_po);
  msgHandler_po = b_Handler_po;

  return v_Result_b;
}

bool_t Can::process_b()
{
  bool_t v_Result_b = false;
  CAN_MSG  v_CanMsg_s;

  if (true == isOpened_b())
  {
    sint32_t v_DevCtlErr_s32 = ENODATA;
    size_t v_MsgSize_t = sizeof(CAN_MSG);
    v_DevCtlErr_s32 = devctl(static_cast<int32_t>(canHandleRx_t), CAN_DEVCTL_READ_CANMSG_EXT, &v_CanMsg_s, v_MsgSize_t, NULL);
    if (EOK == v_DevCtlErr_s32)
    {
      processFrameData_v(v_CanMsg_s);
      v_Result_b = true;
    }
    else
    {
      shutdown_v();
    }
  }
  else
  {
    tryReopen_v();
  }

  return v_Result_b;
}

void Can::processFrameData_v(const CanMessage_t& i_CanMsg_ro)
{
  if ( NULL != msgHandler_po )
  {
    memcpy(reinterpret_cast<void*>(frameDataBuf_au8), &i_CanMsg_ro.mid, sizeof(uint16_t));
    memcpy(reinterpret_cast<void*>(&(frameDataBuf_au8[c_CanDataIndex_u8])), i_CanMsg_ro.dat, i_CanMsg_ro.len);
    msgHandler_po->onReceive_v(this, frameDataBuf_au8, i_CanMsg_ro.len + c_CanDataIndex_u8);
  }
}

void Can::shutdown_v()
{
  (void)close(canHandleRx_t);
  (void)close(canHandleTx_t);

  canChannelStatus_e = e_ChannelStatusClosed;
}

void Can::tryReopen_v()
{
  ME_Thread_Sleep_t(c_ReopenSleepTime_u8);
  shutdown_v();
  (void)open_b();
}

bool_t Can::send_b(const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = false;

  if (true == isOpened_b())
  {
     CAN_MSG v_CanMsg_s;
     uint32_t v_MsgId_u32 = static_cast<uint32_t>((i_Buffer_pu8[c_CanMsgIdMsbIdx_u8] << c_CanMsgIdShiftLen_u8) + i_Buffer_pu8[c_CanMsgIdLsbIdx_u8]);
     (void)memset(&v_CanMsg_s, 0U, sizeof(CAN_MSG));
     v_CanMsg_s.mid = v_MsgId_u32;
     v_CanMsg_s.len = (static_cast<uint8_t>(i_BufferLength_t) - c_CanDataIndex_u8);
     (void)memcpy(v_CanMsg_s.dat, &i_Buffer_pu8[c_CanDataIndex_u8], v_CanMsg_s.len);

     sint32_t v_DevCtlErr_s32 = ENODATA;
     v_DevCtlErr_s32 = devctl(static_cast<int32_t>(canHandleTx_t), CAN_DEVCTL_WRITE_CANMSG_EXT, reinterpret_cast<void *>(&v_CanMsg_s), sizeof(CAN_MSG), NULL);
     if (v_DevCtlErr_s32 == EOK)
     {
       v_Result_b = true;
     }
     else
     {
       // i.e. if v_DevCtlErr_s32 == EAGAIN (11 -> Resource temporarily unavailable)
       // in most cases it means buffer overflow.
       ME_Debugger_F_Printf_v("CAN_QNX: CAN devctl error [%d]! \n", v_DevCtlErr_s32);
     }
  }

  return v_Result_b;
}

bool_t Can::openRxChannel_b()
{
  bool_t v_Result_b = false;

  canHandleRx_t = open(c_CanDevRxName_pc, O_RDWR);

  if (canHandleRx_t < 0)
  {
    canChannelStatus_e = e_ChannelStatusClosed;
  }
  else
  {
    canChannelStatus_e = e_ChannelStatusOpened;
  }

  return v_Result_b;
}

bool_t Can::openTxChannel_b()
{
  bool_t v_Result_b = false;

  canHandleTx_t = open(c_CanDevTxName_pc, O_RDWR);

  if (canHandleTx_t < 0)
  {
    canChannelStatus_e = e_ChannelStatusClosed;
  }
  else
  {
    canChannelStatus_e = e_ChannelStatusOpened;
  }

  return v_Result_b;
}

inline bool_t Can::isOpened_b() const
{
  return ( e_ChannelStatusOpened == canChannelStatus_e );
}


#endif // ME_PLATFORM_QNX

} // namespace bsp
