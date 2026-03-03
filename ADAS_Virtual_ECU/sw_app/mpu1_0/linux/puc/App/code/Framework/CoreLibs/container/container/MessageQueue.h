//--------------------------------------------------------------------------
/// @file MessageQueue.h
/// @brief
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

#ifndef CONTAINER_MESSAGE_QUEUE_H
#define CONTAINER_MESSAGE_QUEUE_H

// PRQA S 1020 7 // we want macros here
#define MAKE_ALIGNMENT_SIZE(size)  ((( (size) + (sizeof(sint32_t) - 1) ) \
                                   / sizeof(sint32_t))*sizeof(sint32_t))

#define HEADER_SIZE  (MAKE_ALIGNMENT_SIZE((sizeof(osal::SoftwareInterrupt))))

#define QUEUE_SIZE(numOfMsg)   (MAKE_ALIGNMENT_SIZE((sizeof(MessageQueue)\
  + sizeof(Message)*((numOfMsg) - 1))))

#include "Message.h"
#include <osal/threading/BinarySemaphore.h>
#include <osal/sync/SoftwareInterrupt.h>

namespace container
{

class MessageQueue
{
public:
  MessageQueue(sint32_t i_QueueSize_s32, osal::SoftwareInterrupt& b_SignalSem_ro);
  ~MessageQueue();

  // --------------------------------------------------------------------------
  /// @brief add a message into the queue
  /// @param[in] i_Message_ro  reference to a message
  /// @param[in] i_WaitForEver_b true (=blocking) when the sender can wait
  ///            (normally only admin's watchdog is allowed to send non-blocking messages to signal a no answering component)
  /// @return true if the event is delivered
  // --------------------------------------------------------------------------
  bool_t add_b(const Message& i_Message_ro, bool_t i_WaitForEver_b = true);

  // --------------------------------------------------------------------------
  /// @brief get the number of messages in the queue
  /// @return the number of messages
  // --------------------------------------------------------------------------
  sint32_t getNumMessages_s32(void);

  // --------------------------------------------------------------------------
  /// @brief get a message from the queue. The caller cannot be blocked
  /// @param[in] b_Message_ro  object at front of the queue
  /// @return true if a message exists, false otherwise
  // --------------------------------------------------------------------------
  bool_t getMessage_b(Message& b_Message_ro);

  // --------------------------------------------------------------------------
  /// @brief get the number of bytes occupied the queue
  /// @return memory size occupied by the object
  // --------------------------------------------------------------------------
  sint32_t getNumBytesNeeded_s32(void) const ;

  // --------------------------------------------------------------------------
  /// @brief get the size of a queue with given message
  /// @param[in] i_NumMessages_s32  Number of messages to calculate the size for
  /// @return true if a message exists, false otherwise
  // --------------------------------------------------------------------------
  static sint32_t getNumBytesNeeded_s32(sint32_t i_NumMessages_s32);

  // --------------------------------------------------------------------------
  /// @brief reset the queue
  /// @param[in] nothing
  /// @return nothing
  // --------------------------------------------------------------------------
  void reset_v();


  // disallow copy
private:
  MessageQueue (const MessageQueue& i_Rhs_ro);
  const MessageQueue& operator=(const MessageQueue& i_Rhs_ro);

private:

  Mutex_s mutex_s;

  // waiting task gets a wake up signal.
  osal::SoftwareInterrupt& signal_ro;

  // Queue Size
  sint32_t size_s32;

  // Current Queue Size
  sint32_t currentSize_s32;

  // first possible element for reading
  sint32_t headIndex_s32;

  // position to insert
  sint32_t tailIndex_s32;

  // dirty trick to force the subsequent memory
  // belong to the queue. This technique is needed for placing the queue into a shared memory
  Message queue_ao[1];
};

} // namespace container

#endif
