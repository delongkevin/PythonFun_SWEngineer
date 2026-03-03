//--------------------------------------------------------------------------
/// @file SocketClient.h
/// @brief Acts as a socket client
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OSAL_SOCKET_CLIENT_H
#define OSAL_SOCKET_CLIENT_H

#include "INetwork.h"

#include <platform/PlatformAPI.h>

namespace osal
{

class SocketClient : public INetwork
{
public:
  SocketClient();
  virtual ~SocketClient();

  // configure socket server
  bool_t init_b(SocketHandle_t i_SocketHandle_t);
  bool_t init_b(SocketProtocolType_t i_Type_e, const char_t* i_Address_pc, sint32_t i_Port_s32);

  // returns the socket handle
  SocketHandle_t getSocketHandle_t() const;

  // --- INetwork function overrides ---
  virtual bool_t   registerHandler_b(INetworkMsgHandler* b_Handler_po) ME_OVERRIDE;

  virtual bool_t process_b() ME_OVERRIDE;

  virtual void   shutdown_v() ME_OVERRIDE;

  virtual bool_t send_b(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t) ME_OVERRIDE;

private:
  INetworkMsgHandler* msgHandler_po;
  SocketHandle_t      socketHandle_t;
  size_t              numBytesReceived_t;
  char_t              receiveBuffer_ac[MAX_SOCKET_SIZE]; // PRQA S 1021 // MAX_SOCKET_SIZE to be used from C and CPP
};

} // namespace osal

#endif // OSAL_SOCKET_CLIENT_H
