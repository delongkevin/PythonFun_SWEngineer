//--------------------------------------------------------------------------
/// @file SocketServer.h
/// @brief Acts as a TCP socket server
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OSAL_SOCKET_SERVER_H
#define OSAL_SOCKET_SERVER_H

#include "INetwork.h"

#include <platform/PlatformAPI.h>

#include "SocketClient.h"

namespace osal
{

class SocketServer : public INetwork
{
public:
  SocketServer(SocketProtocolType_t i_Type_e, const char_t* i_Address_pc, sint32_t i_Port_s32);
  virtual ~SocketServer();

  // configure socket server
  bool_t init_b(SocketProtocolType_t i_Type_e, const char_t* i_Address_pc, sint32_t i_Port_s32);

  // --- INetwork function overrides ---
  virtual bool_t registerHandler_b(INetworkMsgHandler* b_Handler_po) ME_OVERRIDE;

  virtual bool_t process_b() ME_OVERRIDE;

  virtual void shutdown_v() ME_OVERRIDE;

  virtual bool_t send_b(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t) ME_OVERRIDE;

private:
  INetworkMsgHandler* msgHandler_po;
  SocketHandle_t serverSocket_t;
  SocketClient acceptedClient_o;      // just 1 client for now
};

} // namespace osal

#endif // OSAL_SOCKET_SERVER_H
