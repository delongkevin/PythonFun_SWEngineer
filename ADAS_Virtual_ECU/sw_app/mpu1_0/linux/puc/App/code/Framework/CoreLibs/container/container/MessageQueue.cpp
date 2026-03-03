//--------------------------------------------------------------------------
/// @file MessageQueue.cpp
/// @brief MessageQueue Implementation
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
#include "MessageQueue.h"

#include <logging/Logger.h>

#include <new> // for placement new

namespace container
{

MessageQueue::MessageQueue(sint32_t i_QueueSize_s32, osal::SoftwareInterrupt& b_Signal_ro)
  : signal_ro(b_Signal_ro)
  , size_s32(i_QueueSize_s32)
  , currentSize_s32(0)
  , headIndex_s32(0)
  , tailIndex_s32(0)
//  , accessSem_o()   // free and shared
//  , canWriteSem_o() // writing into an empty queue is ok
{
  Assert(i_QueueSize_s32 > 0);

  // init queue correctly
  sint8_t* v_Ptr_ps8 = reinterpret_cast<sint8_t*>(&queue_ao[0]);
  new (v_Ptr_ps8) Message[i_QueueSize_s32]; // PRQA S 5118 // false detection - using placement new here

  ME_Mutex_Init_t(&mutex_s, true);
}

MessageQueue::~MessageQueue()
{

}

bool_t MessageQueue::add_b(const Message& i_Message_ro, bool_t i_WaitForEver_b)
{
  bool_t v_Ret_b = false;

  if(getNumMessages_s32() >= size_s32)
  {
    signal_ro.receive_v(osal::c_MAX_ATTACHMENTS_u8);
  }

  ME_Mutex_Lock_t(&mutex_s);

  // now we have full control
  queue_ao[tailIndex_s32] = i_Message_ro;

  // decrement the tail index for next message
  --tailIndex_s32;

  // ring buffer
  if (tailIndex_s32 < 0)
  {
    tailIndex_s32 = size_s32 - 1;
  }

  // increment the size, we added a new message
  ++currentSize_s32;

  signal_ro.broadcast_v();

  ME_Mutex_UnLock_t(&mutex_s);

  v_Ret_b = true;

  // everything fine, we added to queue
  return v_Ret_b;
}

sint32_t MessageQueue::getNumMessages_s32(void)
{
  sint32_t v_Size_s32 = 0;

  ME_Mutex_Lock_t(&mutex_s);
  v_Size_s32 = currentSize_s32;
  ME_Mutex_UnLock_t(&mutex_s);

  return v_Size_s32;
}

bool_t MessageQueue::getMessage_b(Message& b_Message_ro)
{
  bool_t v_Ret_b = false;

  ME_Mutex_Lock_t(&mutex_s);

  if (0 == currentSize_s32)
  {
    v_Ret_b = false;
  }
  else
  {
    // now we have full control, copy message and decrement size and head
    b_Message_ro = queue_ao[headIndex_s32];
    --currentSize_s32;
    --headIndex_s32;

    // ring buffer
    if (headIndex_s32 < 0)
    {
      headIndex_s32 = size_s32 - 1;
    }

    signal_ro.broadcast_v();

    // do not forget the give the access right back
    v_Ret_b = true;
  }

  ME_Mutex_UnLock_t(&mutex_s);

  return v_Ret_b;
}

sint32_t MessageQueue::getNumBytesNeeded_s32(void) const
{
  return MessageQueue::getNumBytesNeeded_s32(size_s32);
}

sint32_t MessageQueue::getNumBytesNeeded_s32(sint32_t i_NumMessages_s32)
{
  return MAKE_ALIGNMENT_SIZE(sizeof(MessageQueue) +
                             sizeof(Message) * (i_NumMessages_s32 - 1) );
}

void MessageQueue::reset_v()
{
  uint32_t num = getNumMessages_s32();
  // splitted due to QAC
  while (0 != num)
  {
    Message msg;
    getMessage_b(msg); // clear the Message Queue
    num = getNumMessages_s32();
  }
}

} // namespace container
