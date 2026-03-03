//--------------------------------------------------------------------------
/// @file INetwork.h
/// @brief Interface for Network connections.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OSAL_INETWORK_H
#define OSAL_INETWORK_H

#include <platform/PlatformAPI.h>

namespace osal
{

class INetworkMsgHandler;

class INetwork
{
  public:
    INetwork() { }
    virtual ~INetwork() { }

    // initialize network configuration
    virtual bool_t registerHandler_b(INetworkMsgHandler* b_Handler_po) = 0;

    // process messages return true if connection is still alive (no connection abort)
    virtual bool_t process_b() = 0;

    // shutdown connection
    virtual void shutdown_v() = 0;

    // send data
    virtual bool_t send_b(const uint8_t* b_Buffer_pu8, size_t i_BufferLength_t) = 0;
};

} // namespace osal


#endif
