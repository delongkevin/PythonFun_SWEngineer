#include "SocketServer.h"
#include "INetworkMsgHandler.h"

// PRQA S 1021 EOF // macro for invalid file handle is defined in shared c and cpp file

namespace osal
{
  SocketServer::SocketServer(SocketProtocolType_t i_Type_e, const char_t* i_Address_pc, sint32_t i_Port_s32)
    : INetwork()
    , msgHandler_po(NULL)
  {
    ME_Socket_Init_v(&serverSocket_t);

    init_b(i_Type_e, i_Address_pc, i_Port_s32);
  }

  SocketServer::~SocketServer()
  {

  }

  bool_t SocketServer::init_b(SocketProtocolType_t i_Type_e, const char_t* i_Address_pc, sint32_t i_Port_s32)
  {
    bool_t v_Result_b = true;
    PlatformError_t v_Error_t = ME_Socket_Startup_t();

    if(v_Error_t == e_PeOk)
    {
      v_Error_t = ME_Socket_Create_t(&serverSocket_t, i_Type_e, true);
    }

    // we assume a valid server socket now
    if(true == ME_Socket_IsValid_b(&serverSocket_t))
    {
      // Bind to ip address and port
      v_Error_t = ME_Socket_Bind_t(&serverSocket_t, i_Address_pc, i_Port_s32);

      // now listen to incoming connections
      v_Error_t = ME_Socket_Listen_t(&serverSocket_t);
    }

    if(v_Error_t != e_PeOk)
    {
      v_Result_b = false;
    }

    return v_Result_b;
  }

  bool_t SocketServer::registerHandler_b(INetworkMsgHandler* b_Handler_po)
  {
    bool_t v_Result_b = true;
    if(NULL != b_Handler_po)
    {
      msgHandler_po = b_Handler_po;
    }
    else
    {
      v_Result_b = false;
    }

    return v_Result_b;
  }

  bool_t SocketServer::process_b()
  {
    bool_t b_Ret = true;

    // accept incoming connections. (only 1 for now)
    const SocketHandle_t& v_tmpSocketHandle_rt = acceptedClient_o.getSocketHandle_t();

    if( (true == ME_Socket_IsValid_b(&serverSocket_t)) &&
        (false == ME_Socket_IsValid_b(&v_tmpSocketHandle_rt))
      )
    {
      SocketHandle_t v_AcceptedSocket_t;
      PlatformError_t v_Error_t;

      v_Error_t = ME_Socket_Accept_t(&serverSocket_t, &v_AcceptedSocket_t);
      Assert((e_PeOk == v_Error_t) || (e_PeAgain == v_Error_t));

      if (true == ME_Socket_IsValid_b(&v_AcceptedSocket_t))
      {
        // register message handler
        acceptedClient_o.registerHandler_b(msgHandler_po);

        // and initialize the client with new socket
        acceptedClient_o.init_b(v_AcceptedSocket_t);
      }
    }

    // if we have a valid connection accepted
    if (true == ME_Socket_IsValid_b(&serverSocket_t))
    {
      bool_t v_ClientDisconnected_b = acceptedClient_o.process_b();
      b_Ret = v_ClientDisconnected_b;
    }

    // always return true for server. we are still alive if someone calls the process method.
    // for now this flag just detects disconnected clients
    return b_Ret;
  }

  void SocketServer::shutdown_v()
  {
    PlatformError_t v_Error_t = e_PeOk;
    // close server
    if (true == ME_Socket_IsValid_b(&serverSocket_t))
    {
      v_Error_t = ME_Socket_Close_t(&serverSocket_t);
      Assert(e_PeOk == v_Error_t);
    }

    acceptedClient_o.shutdown_v();

    // cleanup socket library
    v_Error_t = ME_Socket_Cleanup_t();
    Assert(v_Error_t == e_PeOk);
  }

  bool_t SocketServer::send_b(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t)
  {
    return acceptedClient_o.send_b(b_Buffer_pu8, i_BufferLength_t);
  }

} // namespace osal
