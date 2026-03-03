//--------------------------------------------------------------------------
/// @file MessageDispatcher.h
/// @brief Message Dispatcher (aka Postman) gets commands from the MessageQueues and delivers them to jobs
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

#ifndef CONTAINER_MESSAGE_DISPATCHER_H
#define CONTAINER_MESSAGE_DISPATCHER_H

#include "Message.h"

namespace osal
{
  class SoftwareInterrupt;
} // namespace osal

namespace container
{
  class MessageQueue;
  class IMessageHandler;
} // namespace osal

namespace container
{

class MessageDispatcher
{
public:
  // --------------------------------------------------------------------------
  /// @brief set the MEssage Handler
  /// @param[in] b_NormalQueue_ro
  /// @param[in] b_SystemQueue_ro System messages
  /// @param[in] b_InternalQueue_ro Internal messages
  // --------------------------------------------------------------------------
  MessageDispatcher(MessageQueue& b_NormalQueue_ro,
                    MessageQueue& b_SystemQueue_ro,
                    MessageQueue& b_InternalQueue_ro,
                    osal::SoftwareInterrupt& b_Sem_ro);

  ~MessageDispatcher();

  // --------------------------------------------------------------------------
  /// @brief set the MEssage Handler
  /// @param[in] b_Listener_ro object handling message received
  // --------------------------------------------------------------------------
  void setHandler_v(IMessageHandler& b_Listener_ro);

  // --------------------------------------------------------------------------
  /// @brief get a command from the queue and dispatch it
  /// @param[in] i_WaitForEver_b true means the Dispatcher will be blocked as long, as no command is avaiable
  // --------------------------------------------------------------------------
  void dispatch_v(bool i_WaitForEver_b);

  void reset_v();

private:
  // to avoid misuse
  MessageDispatcher(const MessageDispatcher& i_Rhs_ro);
  MessageDispatcher& operator=(const MessageDispatcher& i_Rhs_ro);

private:
  // Message Queues
  MessageQueue& normalQueue_ro;
  MessageQueue& systemQueue_ro;
  MessageQueue& internalQueue_ro;

  // used to unblock
  osal::SoftwareInterrupt& sem_ro;

  IMessageHandler* messageHandler_po;

  // holds the current message
  Message message_o;
};

} // namespace container

#endif
