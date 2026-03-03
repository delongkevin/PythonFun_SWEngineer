//--------------------------------------------------------------------------
/// @file Message.cpp
/// @brief Implements the Message class
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

#include "Message.h"

namespace container
{

Message::Message()
  : message_s()
{
}

Message::~Message()
{
  // nothing to do here for now
}

void Message::setMessageType_v(sint32_t i_MessageType_s32)
{
  message_s.type_s32 = i_MessageType_s32;
}

sint32_t Message::getMessageType_s32(void) const
{
  return message_s.type_s32;
}

void Message::setSenderID_v(sint32_t i_SenderId_s32)
{
  message_s.senderId_s32 = i_SenderId_s32;
}

sint32_t Message::getSenderID_s32(void) const
{
  return message_s.senderId_s32;
}

void Message::setReceiverID_v(sint32_t i_ReceiverId_s32)
{
  message_s.receiverId_s32 = i_ReceiverId_s32;
}

sint32_t Message::getReceiverID_s32(void) const
{
  return message_s.receiverId_s32;
}

void Message::setOpcode_v(sint32_t i_OpCode_s32)
{
  message_s.opCode_s32 = i_OpCode_s32;
}

sint32_t Message::getOpcode_s32(void) const
{
  return message_s.opCode_s32;
}

void Message::setParameter1_v(sint32_t i_Parameter_s32)
{
  message_s.parameter1_s32 = i_Parameter_s32;
}

sint32_t Message::getParameter1_s32(void) const
{
  return message_s.parameter1_s32;
}

void Message::setMessageHandler_v(IMessageHandler* i_Handler_po)
{
  message_s.messageHandler_po = i_Handler_po;
}

IMessageHandler* Message::getMessageHandler_po(void) const
{
  return message_s.messageHandler_po;
}

} // namespace container
