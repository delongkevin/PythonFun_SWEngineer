//--------------------------------------------------------------------------
/// @file MessageDispatcher.cpp
/// @brief Implementation of the generic dispatcher that dispatch messages to  the listeners of the Job
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

#include "MessageDispatcher.h"

#include <osal/threading/BinarySemaphore.h>

#include "IMessageHandler.h"
#include "MessageQueue.h"


namespace container
{

static uint8_t v_AttachID_u8 = osal::c_MAX_ATTACHMENTS_u8;

MessageDispatcher::MessageDispatcher(MessageQueue& b_NormalQueue_ro,
                                     MessageQueue& b_SystemQueue_ro,
                                     MessageQueue& b_InternalQueue_ro,
                                     osal::SoftwareInterrupt& b_Sem_ro)
  : normalQueue_ro(b_NormalQueue_ro)
  , systemQueue_ro(b_SystemQueue_ro)
  , internalQueue_ro(b_InternalQueue_ro)
  , sem_ro(b_Sem_ro)
  , messageHandler_po(NULL)
  , message_o()
{
  //v_AttachID_u8 = sem_ro.attach_u8();
}

MessageDispatcher::~MessageDispatcher()
{
  // nothing to do here for now
}

void MessageDispatcher::setHandler_v(IMessageHandler& b_Listener_ro)
{
  messageHandler_po = &b_Listener_ro; // PRQA S 2516 // This is assigning the address of an object to a pointer that may have greater lifetime. // no issue as object gets destroyed by destructor also
}

void MessageDispatcher::dispatch_v(bool i_WaitForEver_b)
{
  bool v_HasMessage_b = false;

  // as long as the dispatcher is not interrupted it will block if no message is available
  while (false == v_HasMessage_b)
  {
    // try to get an system command
    v_HasMessage_b = systemQueue_ro.getMessage_b(message_o);
    if (false == v_HasMessage_b)
    {
      v_HasMessage_b = internalQueue_ro.getMessage_b(message_o);
    }
    if (false == v_HasMessage_b)
    {
      v_HasMessage_b = normalQueue_ro.getMessage_b(message_o);
    }

    if (true == v_HasMessage_b)
    {
      // a command has been found
      messageHandler_po->handleMessage_v(message_o);
    }
    else if (true == i_WaitForEver_b)
    {
      // at this point the dispatcher must wait for a new message because queues are empty.
      // the semaphore is only free if at least one queue is not empty or if a signal is received
      // the context must call interruptDispatcher before
      //uint8_t v_AttachID_u8 = sem_ro.attach_u8();

      sem_ro.receive_v(v_AttachID_u8);

      // watchdog trigger might be located here
    }
    else
    {
      /* simply return */
      break;
    }
  }

  return;
}

void MessageDispatcher::reset_v()
{
  systemQueue_ro.reset_v();
  internalQueue_ro.reset_v();
  normalQueue_ro.reset_v();
}

} // namespace container
