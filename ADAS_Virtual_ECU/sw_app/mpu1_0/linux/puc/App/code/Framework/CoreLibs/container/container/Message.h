//--------------------------------------------------------------------------
/// @file Message.h
/// @brief Defines the structure of Messages sent between the different Jobs
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

#ifndef CONTAINER_MESSAGE_H
#define CONTAINER_MESSAGE_H

#include <platform/PlatformSpecs.h>

#include "MessageTypes.h"

namespace container
{
class IMessageHandler;
} // namespace container

namespace container
{

// structure used for messages which are sent between the components
struct AppMessage_s
{
  // type of message
  sint32_t type_s32;

  // id of the sender job
  sint32_t senderId_s32;

  // id of the job which shall receive the message
  sint32_t receiverId_s32;

  // action that should be taken (see Event.h in cfg folder)
  sint32_t opCode_s32;

  // some parameters
  sint32_t parameter1_s32;

  // Message handler is ignored if it sents from one thread to an other.
  // While sending a message in the same thread context the sender can explicitely set the handler.
  // A correct handler for external message is found using the local registry.
  IMessageHandler* messageHandler_po;
};

// Message class
class Message
{
public:
  Message();
  ~Message();

  void setMessageType_v(sint32_t i_MessageType_s32);
  sint32_t getMessageType_s32(void) const;

  void setSenderID_v(sint32_t i_SenderId_s32);
  sint32_t getSenderID_s32(void) const;

  void setReceiverID_v(sint32_t i_ReceiverId_s32);
  sint32_t getReceiverID_s32(void) const;

  void setOpcode_v(sint32_t i_OpCode_s32);
  sint32_t getOpcode_s32(void) const;

  void setParameter1_v(sint32_t i_Parameter_s32);
  sint32_t getParameter1_s32(void) const;

  void setMessageHandler_v(IMessageHandler* i_Handler_po);
  IMessageHandler* getMessageHandler_po(void) const;

private:
  AppMessage_s message_s;
};

} // namespace container

#endif // CONTAINER_MESSAGE_H
