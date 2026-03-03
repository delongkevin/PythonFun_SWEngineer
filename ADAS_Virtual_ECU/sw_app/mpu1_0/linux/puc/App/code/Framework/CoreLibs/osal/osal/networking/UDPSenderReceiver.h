//--------------------------------------------------------------------------
/// @file UDPSenderReceiver.h
/// @brief Acts as a socket server
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Marcel Engelhardt (Marcel.Engelhardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OSAL_UDPSENDERRECEIVER_H
#define OSAL_UDPSENDERRECEIVER_H

#include "INetwork.h"

#include <platform/PlatformAPI.h>

namespace osal
{

class UDPSenderReceiver : public INetwork
{
public:
  UDPSenderReceiver(const char_t* i_Address_pc, sint32_t i_ListenPort_s32, const char_t* i_DestinationAddress_pc, sint32_t i_DestinationPort_s32);
  virtual ~UDPSenderReceiver();

  // configure socket server
  void init_v(const char_t* i_Address_pc, sint32_t i_ListenPort_s32, const char_t* i_DestinationAddress_pc, sint32_t i_DestinationPort_s32);

  // --- INetwork function overrides ---
  virtual bool_t registerHandler_b(INetworkMsgHandler* b_Handler_po) ME_OVERRIDE;

  virtual bool_t process_b() ME_OVERRIDE;

  virtual void shutdown_v() ME_OVERRIDE;

  virtual bool_t send_b(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t) ME_OVERRIDE;

private:
  INetworkMsgHandler* msgHandler_po;
  SocketHandle_t ListenSocket_t;
  SocketHandle_t SendSocket_t;  // only 1 client for now
  char_t receiveBuffer_ac[MAX_SOCKET_SIZE]; // PRQA S 1021 // MAX_SOCKET_SIZE to be used from C and CPP

  sint32_t ListenPort_s32; // Port on which to listen
  sint32_t DestinationPort_s32; // Port towards to send

  const char_t* c_DestinationAddress_pc;
};

} // namespace osal

#endif // OSAL_UDPSENDERRECEIVER_H
