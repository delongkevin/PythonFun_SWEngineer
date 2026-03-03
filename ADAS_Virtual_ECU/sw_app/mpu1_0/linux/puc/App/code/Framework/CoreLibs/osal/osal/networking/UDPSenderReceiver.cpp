#include "UDPSenderReceiver.h"
#include "INetworkMsgHandler.h"

// PRQA S 1021 EOF // macro literal using ME_INVALID_SOCKET and MAX_SOCKET_SIZE

namespace osal
{
  UDPSenderReceiver::UDPSenderReceiver(const char_t* i_Address_pc, sint32_t i_ListenPort_s32, const char_t* i_DestinationAddress_pc, sint32_t i_DestinationPort_s32)
    : INetwork()
    , msgHandler_po(NULL)
    , ListenPort_s32(0)
    , DestinationPort_s32(0)
    , c_DestinationAddress_pc(NULL)
  {
    receiveBuffer_ac[0] = '\0';
    init_v(i_Address_pc, i_ListenPort_s32, i_DestinationAddress_pc, i_DestinationPort_s32);
  }

  UDPSenderReceiver::~UDPSenderReceiver()
  {

  }

  void UDPSenderReceiver::init_v(const char_t* i_Address_pc, sint32_t i_ListenPort_s32, const char_t* i_DestinationAddress_pc, sint32_t i_DestinationPort_s32)
  {
    PlatformError_t v_Error_t = ME_Socket_Startup_t();
    Assert(v_Error_t == e_PeOk);

    v_Error_t = ME_Socket_Create_t(&ListenSocket_t, e_SptUdp, true);
    Assert(v_Error_t == e_PeOk);

    v_Error_t = ME_Socket_Create_t(&SendSocket_t, e_SptUdp, true);
    Assert(v_Error_t == e_PeOk);

    // we assume a valid server socket now
    Assert(ME_Socket_IsValid_b(&ListenSocket_t) == true);

    // we assume a valid client socket now
    Assert(ME_Socket_IsValid_b(&SendSocket_t) == true);

    // Bind to ip address and port
    v_Error_t = ME_Socket_Bind_t(&ListenSocket_t, i_Address_pc, i_ListenPort_s32);
    Assert(e_PeOk == v_Error_t);
    ListenPort_s32 = i_ListenPort_s32;

    v_Error_t = ME_Socket_Bind_t(&SendSocket_t, i_Address_pc, i_ListenPort_s32 + 1); // need a different port then the one we want to send to
    Assert(e_PeOk == v_Error_t);
    DestinationPort_s32 = i_DestinationPort_s32;

    c_DestinationAddress_pc = i_DestinationAddress_pc;
  }

  bool_t UDPSenderReceiver::registerHandler_b(INetworkMsgHandler* b_Handler_po)
  {
    bool_t v_Result_b = true;
    if(b_Handler_po != NULL)
    {
      msgHandler_po = b_Handler_po;
    }
    else
    {
      v_Result_b = false;
    }

    return v_Result_b;
  }

  bool_t UDPSenderReceiver::process_b()
  {
    bool_t v_ConnectionAlive_b = true;

    // if we have a valid connection accepted
    if (ME_Socket_IsValid_b(&SendSocket_t) == true)
    {
      PlatformError_t v_Error_t = e_PeOk;

      // check if we received something
      size_t v_NumBytesReceived_t = 0;

      v_Error_t = ME_Socket_Receive_t(&ListenSocket_t, &receiveBuffer_ac[0], MAX_SOCKET_SIZE, &v_NumBytesReceived_t);

      if (e_PeConnAborted == v_Error_t)
      {
        ME_Socket_Close_t(&ListenSocket_t);
        v_ConnectionAlive_b = false;
      }
      else if (v_NumBytesReceived_t > 0)
      {
        receiveBuffer_ac[v_NumBytesReceived_t] = '\0';

        // and if so, inform the message handler
        if (NULL != msgHandler_po)
        {
          msgHandler_po->onReceive_v(this, reinterpret_cast<uint8_t*>(&receiveBuffer_ac[0]), v_NumBytesReceived_t);
        }
        else
        {
          // no handler registered
        }
      }
      else
      {
        // do nothing
      }
    }
    else
    {
      // do nothing
    }

    return v_ConnectionAlive_b;
  }

  void UDPSenderReceiver::shutdown_v()
  {
    PlatformError_t v_Error_t = e_PeOk;

    // close server
    if (ME_Socket_IsValid_b(&ListenSocket_t) == true)
    {
      v_Error_t = ME_Socket_Close_t(&ListenSocket_t);
      Assert(e_PeOk == v_Error_t);
    }

    // close client
    if (ME_Socket_IsValid_b(&SendSocket_t) == true)
    {
      v_Error_t = ME_Socket_Close_t(&SendSocket_t);
      Assert(e_PeOk == v_Error_t);
    }

    // cleanup socket library
    v_Error_t = ME_Socket_Cleanup_t();
    Assert(v_Error_t == e_PeOk);
  }

  bool_t UDPSenderReceiver::send_b(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
  {
    bool_t v_Result_b = true;
    if (ME_Socket_IsValid_b(&SendSocket_t) == true)
    {
      size_t v_NumBytesSent_t = 0;
      PlatformError_t v_Error_t = ME_Socket_Send_t_ToDest_t(&SendSocket_t, reinterpret_cast<const char_t*>(b_Buffer_pu8), i_BufferLength_t, &v_NumBytesSent_t, c_DestinationAddress_pc, DestinationPort_s32);

      if((e_PeOk == v_Error_t) && (v_NumBytesSent_t == i_BufferLength_t))
      {
        v_Result_b = true;
      }
    }

    return v_Result_b;
  }

} // namespace osal
