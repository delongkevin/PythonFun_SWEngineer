//--------------------------------------------------------------------------
/// @file IpcCom_Qnx.cpp
/// @brief Implementation of IpcCom
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda Kavrady (Ananda.Kavrady@Magna.com)
///
//  --------------------------------------------------------------------------

// ==========================================================================
// Includes
// ==========================================================================
#include "bsp/driver/IpcCom.h"
#include "Ipc_mgr_Qnx.h"
#include <osal/networking/INetworkMsgHandler.h>
#include <cfg/shmdata/SigM_Messages.h>

namespace bsp
{

#ifdef ME_PLATFORM_QNX
// --------------------------------------------------------------------------
// Class //END IPCOMServer()
// -------------------------------------------------------------------------

IpcCom::IpcCom()
  : INetwork()
  , ipcComHandle_t()
  , channelId_u8(0)
  , msgHandler_po(NULL)
  , status_e(e_Closed)
  , mutex_o()
{
  (void)memset(&receiveBuffer_ac[0], 0, sizeof(receiveBuffer_ac));
}//END //END IPCOMServer()

IpcCom::~IpcCom()
{
}//END //END IPCOMServer()

bool IpcCom::registerHandler_b(osal::INetworkMsgHandler* b_Handler_po)
{

  bool_t v_Result_b = true;

  Assert(NULL == msgHandler_po);
  Assert(NULL != b_Handler_po);
  msgHandler_po = b_Handler_po;

  return v_Result_b;
}//END registerHandler_b()

bool_t IpcCom::process_b()
{
  bool_t v_Result_b = true;
  sint32_t v_Error_s32 = EINVAL;

  if(isOpened_b() == true)
  {
    size_t v_NumBytesReceived_t=0;
    ResMgr_CmdArgs_t cargs_t;
    iov_t rpmsg_recv_iov[2];

    void *v_data_p = static_cast<void*>(&receiveBuffer_ac[0]);
    cargs_t.args.recv.data = NULL;

    SETIOV(&rpmsg_recv_iov[0], &cargs_t, sizeof(ResMgr_CmdArgs_t));
    SETIOV(&rpmsg_recv_iov[1], v_data_p, c_MaxBufferSize_u32);

    mutex_o.take_b();
    v_Error_s32 = devctlv(ipcComHandle_t.ipcComFd_s32, DCMD_RESMGR_MSG_RECV, 2, 2,
                           rpmsg_recv_iov, rpmsg_recv_iov, NULL);
    mutex_o.give_v();

    if (v_Error_s32 != EOK)
    {
      v_Result_b = false;
    }
    else
    {
      v_NumBytesReceived_t = static_cast<size_t>(cargs_t.args.recv.len);
    }


    if(v_NumBytesReceived_t <= 0)
    {
      shutdown_v();
      v_Result_b = false;
    }
    else
    {
      // we've successfully received a message
      // received message is non-empty
      // just drop the message if no handler is registered yet
      if( NULL != msgHandler_po )
      {
        msgHandler_po->onReceive_v(this, reinterpret_cast<uint8_t*>(&receiveBuffer_ac[0]), v_NumBytesReceived_t);
        ME_Thread_Sleep_t(1);
      }
    }
  }
  else
  {
    ME_Thread_Sleep_t(500);
    shutdown_v();
    open_b();
  }

  return v_Result_b;

}//END process_b()

void IpcCom::shutdown_v()
{
  (void)close(ipcComHandle_t.ipcComFd_s32);

  status_e = e_Closed;
}//END shutdown_v()

bool_t IpcCom::send_b(const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t)
{
  bool_t v_Result_b = isOpened_b();
  sint32_t v_Error_s32 = EINVAL;
  IpcMsgId_t id_e;
  uint32_t v_IDLength_u32 = 0U;

  id_e = getMessageId_e(i_Buffer_pu8, &v_IDLength_u32);
  /* Here e_IpcMsgId_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t has to replace enum last entry. This requires IPC to generate hence added this as a last entry*/
  if((v_Result_b == true) && ((id_e > e_IpcMsgId_data_UnknownMsg_t) && (id_e <= e_IpcMsgId_MAX_COUNT)))
  {
    uint32_t msgSize_u32;
    ResMgr_CmdArgs_t cargs_t;
    iov_t rpmsg_send_iov[2];

    msgSize_u32 = i_BufferLength_t - v_IDLength_u32;
    uint16_t v_len_u16 = static_cast<uint16_t>(msgSize_u32);
    //sending raw data and length to IPC manger.
    //message ID is sent separately  to IPC manager.
    void *v_data_p = reinterpret_cast<void *>(const_cast< uint8_t*>(&i_Buffer_pu8[v_IDLength_u32]));

    cargs_t.args.send.data = NULL;
    cargs_t.args.send.msgID = id_e;
    cargs_t.args.send.len = v_len_u16;
    SETIOV(&rpmsg_send_iov[0], &cargs_t, sizeof(ResMgr_CmdArgs_t));
    SETIOV(&rpmsg_send_iov[1], v_data_p, v_len_u16);

    mutex_o.take_b();
    v_Error_s32 = devctlv(ipcComHandle_t.ipcComFd_s32, DCMD_RESMGR_MSG_SEND, 2, 1,
                     rpmsg_send_iov, rpmsg_send_iov, NULL);
    mutex_o.give_v();

    if(v_Error_s32 != EOK)
    {
      v_Result_b = false;
    }

  }
  else{
	  if(id_e !=0){
	  printf("IPCCOM Send_b: Wrong Message id : 0x%X \t DevStatus: %d\n",id_e,v_Result_b);
	  }
  }

  return v_Result_b;
}//END send_v()

void IpcCom::init_v(uint8_t i_ChannelId_u8)
{
  channelId_u8 = i_ChannelId_u8;
}


bool_t IpcCom::open_b()
{
  bool_t v_Result_b = true;

  sint32_t v_Flags_s32 = O_RDWR; // PRQA S 3600 // QNX define

  ipcComHandle_t.ipcComFd_s32 = open("/dev/resMgr1", v_Flags_s32);

  if(ipcComHandle_t.ipcComFd_s32 < 0)  //IpcCom_SOK   (CSL_PASS)  ( (int32_t) (0))
  {
    status_e = e_Closed;

    v_Result_b = false;
  }
  else
  {
    status_e = e_Opened;
  }


  return v_Result_b;
}

// ==========================================================================
// Inlines
// ==========================================================================
inline bool_t IpcCom::isOpened_b() const
{
  return ( e_Opened == status_e );
}

inline bool_t IpcCom::isClosed_b() const
{
  return ( e_Closed == status_e );
}

inline bool_t IpcCom::isFailed_b() const
{
  return ( e_SendFailed == status_e );
}

#endif // ME_PLATFORM_QNX

} // namespace bsp


