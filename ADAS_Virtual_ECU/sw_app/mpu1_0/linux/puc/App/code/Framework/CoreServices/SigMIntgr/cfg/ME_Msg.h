//--------------------------------------------------------------------------
/// @file CanMsg.h
/// @brief Contains the message structs that are used to send and receive data over the communication interface.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Michael Schulte (michael.schulte@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ME_MSG_H_
#define ME_MSG_H_

#include <cfg/shmdata/SigM_Messages.h>



// Subscript operator used here is OK
// PRQA S 3706 EOF

// public, yes this is a structure
// PRQA S 2100 EOF

namespace sigm
{

struct ME_Msg_s
{
  static const uint32_t c_MsgMaxSize_u32 = 10240U;

  ME_Msg_s(const uint8_t* b_Data_pu8, uint32_t i_DataSize_u32)
  : id_e(e_IpcMsgId_Data_FID_STRUCT_B)
  , msgSize_u32(i_DataSize_u32)
  {
    if((NULL != b_Data_pu8) && (i_DataSize_u32 >= 2))
    {
      if((i_DataSize_u32-2) <= c_MsgMaxSize_u32)
      {
        uint32_t v_IDLength_u32 = 0U;

        id_e = getMessageId_e(b_Data_pu8, &v_IDLength_u32);
        msgSize_u32 = i_DataSize_u32 - v_IDLength_u32;
        (void)memcpy(data_t, &b_Data_pu8[v_IDLength_u32], msgSize_u32);
      }
      else
      {
        id_e = e_IpcMsgId_Data_FID_STRUCT_B;
      }
    }
    else
    {
      (void)memset(data_t, 0x00, sizeof(data_t));
      msgSize_u32 = 0;
    }
  }

  IpcMsgId_t id_e; ///< Message ID
  uint32_t msgSize_u32; ///< Number of valid data bytes in message
  uint8_t data_t[c_MsgMaxSize_u32];
};

/// Message received from Communication interface.
struct ME_MsgRx_s : public ME_Msg_s
{
  ME_MsgRx_s(const uint8_t* b_Data_pu8, uint32_t i_DataSize_u32)
    : ME_Msg_s(b_Data_pu8, i_DataSize_u32)
    , stat_u32(0U)
    , consecutiveNum_u32(0U)
    , time_u64(0U)
  {
  }

  uint32_t getpayloaddata(uint8_t* b_Data_pu8, uint32_t i_MaxReturnSize_u32)
  {
    uint32_t retlen = 0;

    if ((NULL != b_Data_pu8) && (i_MaxReturnSize_u32 >= (msgSize_u32)))
    {
      (void)memcpy(&b_Data_pu8[0], &data_t[0], msgSize_u32);
      retlen = msgSize_u32;
    }
    return retlen;
  }

  uint32_t stat_u32; ///< Driver status information
  uint32_t consecutiveNum_u32;///< Consecutive number of rx message
  uint64_t time_u64;///< timestamp
};


/// Message for sending to Communication interface.
struct ME_MsgTx_s : public ME_Msg_s
{
  ME_MsgTx_s()
  : ME_Msg_s(NULL, 0)
  {
  }

  ME_MsgTx_s(const uint8_t* b_Data_pu8, uint32_t i_DataSize_u32)
  : ME_Msg_s(b_Data_pu8, i_DataSize_u32)
  {
  }

  ME_MsgTx_s& operator = (const ME_MsgRx_s& rx)
  {

    // copy data
    (void)memcpy(this->data_t, rx.data_t, rx.msgSize_u32);

    this->msgSize_u32 = rx.msgSize_u32;

    return *this;
  }

  ME_MsgTx_s& operator = (const ME_MsgTx_s& tx)
  {
    // copy ID
    this->id_e = tx.id_e;

    // copy data
    (void)memcpy(this->data_t, tx.data_t, tx.msgSize_u32);

    this->msgSize_u32 = tx.msgSize_u32;

    return *this;
  }

  bool_t setrawdata(const uint8_t* b_Data_pu8, uint32_t i_DataLength_u32)
  {
    bool_t v_Ret_b;

    if ((NULL != b_Data_pu8) && (i_DataLength_u32 <= (c_MsgMaxSize_u32)))
    {
      msgSize_u32 = i_DataLength_u32;

      (void)memcpy(&data_t[0], b_Data_pu8, msgSize_u32);
      v_Ret_b = true;
    }
    else
    {
      v_Ret_b = false;
    }
    return v_Ret_b;
  }
};

} // namespace sigm

// PRQA S 2100 --

#endif // ME_MSG_H_
