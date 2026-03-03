//--------------------------------------------------------------------------
/// @file BinarySemaphore.h
/// @brief Simple wrapper for binary semaphore. A semaphore is
/// used to lock a resource. Unlike a mutex a semaphore
/// is not allowed to be taken recursively. Furthermore
/// a semaphore can be released by other thread.
/// This feature allows using semaphores for signaling
/// a thread. The receiver thread will block on some semaphore
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OSAL_BINARY_SEMAPHORE_H_
#define OSAL_BINARY_SEMAPHORE_H_

#include <platform/PlatformAPI.h>

namespace osal
{

/// Wrapper for OS specific binary semaphore (a semaphore with counter = 1) implementation.
class BinarySemaphore
{
public:
  /// @brief Create a semaphore object with count 1. The semaphore can be acquired recursively.
  /// @param[in] if this is true, the semaphore will be locked immediately after creation.
  /// @param[in] if this is true, the semaphore can be shared between multiple processes
  explicit BinarySemaphore(bool_t i_IsLocked_b = false, bool_t i_IsProcessShared_b = true);
  ~BinarySemaphore();

  /// @brief Lock (decrement) the semaphore
  /// @param[in] i_WaitForEver_b if true the function call only returns when the semaphore could be locked
  /// @return true, if the semaphore has been locked
  bool_t take_b(bool_t i_WaitForEver_b = true);

  /// @brief Unlock (increment) the semaphore
  void give_v(void);

private:
  /// unsupported: copy constructor and assignment operator
  BinarySemaphore(const BinarySemaphore& i_sem_ro);
  BinarySemaphore& operator=(const BinarySemaphore& i_sem_ro);

private:
  Condvar_s condVar_s;
  uint32_t counter_u32;
};

}

#endif /* OSAL_BINARY_SEMAPHORE_H_ */
