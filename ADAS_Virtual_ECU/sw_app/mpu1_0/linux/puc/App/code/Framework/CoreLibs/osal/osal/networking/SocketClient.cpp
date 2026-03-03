#include "SocketClient.h"
#include "INetworkMsgHandler.h"

// PRQA S 1021 EOF // macro literal using ME_INVALID_SOCKET and MAX_SOCKET_SIZE

namespace osal
{
  SocketClient::SocketClient()
    : INetwork()
    , msgHandler_po(NULL)
    , numBytesReceived_t(0)
  {
    receiveBuffer_ac[0] = '\0';

    ME_Socket_Init_v(&socketHandle_t);
  }

  SocketClient::~SocketClient()
  {

  }

  bool_t SocketClient::init_b(SocketProtocolType_t i_Type_e, const char_t* i_Address_pc, sint32_t i_Port_s32)
  {
    bool_t v_Result_b = true;
    PlatformError_t v_Error_t = ME_Socket_Startup_t();

    v_Error_t = ME_Socket_Create_t(&socketHandle_t, i_Type_e, true);

    // we assume a valid server socket now
    if(true == ME_Socket_IsValid_b(&socketHandle_t)) // PRQA S 1021 // macro literal
    {
      // Connect or bind to ip address and port
      if (e_SptTcp == i_Type_e)
      {
        v_Error_t = ME_Socket_Connect_t(&socketHandle_t, i_Address_pc, i_Port_s32);
      }
      else if (e_SptUdp == i_Type_e)
      {
        v_Error_t = ME_Socket_Bind_t(&socketHandle_t, i_Address_pc, i_Port_s32);
      }
      else
      {
        v_Result_b = false;
      }

      if (v_Error_t != e_PeOk)
      {
        ME_Socket_Close_t(&socketHandle_t);
      }
    }

    if(v_Error_t != e_PeOk)
    {
      v_Result_b = false;
    }

    return v_Result_b;
  }

  bool_t SocketClient::init_b(SocketHandle_t i_SocketHandle_t)
  {
    bool_t v_Result_b = true;

    if( (false == ME_Socket_IsValid_b(&socketHandle_t)) && // PRQA S 1021 // macro literal
        (true == ME_Socket_IsValid_b(&i_SocketHandle_t))  // PRQA S 1021 // macro literal
      )
    {
      PlatformError_t v_Error_t = ME_Socket_Startup_t();

      if(v_Error_t != e_PeOk)
      {
        v_Result_b = false;
      }
      else
      {
        socketHandle_t = i_SocketHandle_t;
      }
    }

    return v_Result_b;
  }

  SocketHandle_t SocketClient::getSocketHandle_t() const
  {
    return socketHandle_t;
  }

  bool_t SocketClient::registerHandler_b(INetworkMsgHandler* b_Handler_po)
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

  bool_t SocketClient::process_b()
  {
    // rest number of bytes received
    numBytesReceived_t = 0;

    bool_t v_ConnectionAlive_b = ME_Socket_IsValid_b(&socketHandle_t); // PRQA S 1021 // macro literal

    // if we have a valid connection accepted
    if (true == v_ConnectionAlive_b)
    {
      PlatformError_t v_Error_t = e_PeOk;
      // check if we received something
      v_Error_t = ME_Socket_Receive_t(&socketHandle_t, &receiveBuffer_ac[0], MAX_SOCKET_SIZE, &numBytesReceived_t);
      
      // check if connection was aborted 
      if (e_PeConnAborted == v_Error_t)
      {
        ME_Socket_Close_t(&socketHandle_t);
        v_ConnectionAlive_b = false;
      }
      else if (numBytesReceived_t > 0)
      {
        receiveBuffer_ac[numBytesReceived_t] = '\0';

        // and if so, inform the message handler
        if (NULL != msgHandler_po)
        {
          msgHandler_po->onReceive_v(this, reinterpret_cast<uint8_t*>(&receiveBuffer_ac[0]), numBytesReceived_t);
        }
      }
      else
      {
        // nothing received
      }
    }

    return v_ConnectionAlive_b;
  }

  void SocketClient::shutdown_v()
  {
    numBytesReceived_t = 0;

    // close client
    if (true == ME_Socket_IsValid_b(&socketHandle_t)) // PRQA S 1021 // macro literal
    {
      ME_Socket_Close_t(&socketHandle_t);
    }

    // cleanup socket library
    ME_Socket_Cleanup_t();
  }

  bool_t SocketClient::send_b(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
  {
    bool_t v_Result_b = false;
    if (true == ME_Socket_IsValid_b(&socketHandle_t)) // PRQA S 1021 // macro literal
    {
      size_t v_NumBytesSent_t = 0;
      PlatformError_t v_Error_t = ME_Socket_Send_t(&socketHandle_t, reinterpret_cast<const char_t*>(b_Buffer_pu8), i_BufferLength_t, &v_NumBytesSent_t);

      if((e_PeOk == v_Error_t) && (v_NumBytesSent_t == i_BufferLength_t))
      {
        v_Result_b = true;
      }
    }

    return v_Result_b;
  }

} // namespace osal
