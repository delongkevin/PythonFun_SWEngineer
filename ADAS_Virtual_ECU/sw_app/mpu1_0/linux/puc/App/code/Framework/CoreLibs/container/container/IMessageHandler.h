//--------------------------------------------------------------------------
/// @file IMessageHandler.h
/// @brief Interface for all message handler. A message handler is responsible
//         to handle the messages which were sent by the dispatcher correctly.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert(Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_I_MESSAGE_HANDLER_H
#define CONTAINER_I_MESSAGE_HANDLER_H

#include "platform/PlatformSpecs.h"

namespace container
{
class Message;
} // namespace container

namespace container
{

class IMessageHandler
{
public:
  // Empty constructor
  IMessageHandler() {}

  // Empty virtual Destructor
  virtual ~IMessageHandler() {}

  // Override this method to react on Messages.
  virtual void handleMessage_v(const Message& i_Msg_ro) = 0;
};

} // namespace container

#endif // CONTAINER_I_MESSAGE_HANDLER_H
