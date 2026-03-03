//--------------------------------------------------------------------------
/// @file INetworkMsgHandler.h
/// @brief Interface for Network receive callback functions.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OSAL_INETWORK_MSG_HANDLER_H
#define OSAL_INETWORK_MSG_HANDLER_H

#include <osal/networking/INetwork.h>
#include <platform/PlatformAPI.h>

namespace osal
{

class INetworkMsgHandler
{
public:
  INetworkMsgHandler() { }
  virtual ~INetworkMsgHandler() { }

  virtual void onReceive_v(osal::INetwork * i_NetworkInterface_po, uint8_t* i_Buffer_pu8, size_t i_BufferLength_t) = 0;
};

} // namespace osal


#endif // OSAL_INETWORK_MSG_HANDLER_H
