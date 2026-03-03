//--------------------------------------------------------------------------
/// @file Mutex.h
/// @brief Generic Thread class implementation based on platforms stdlib
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OSAL_MUTEX_H
#define OSAL_MUTEX_H

#include "platform/PlatformAPI.h"

namespace osal
{


class Mutex
{
public:

  explicit Mutex(bool_t i_IsFree_b = true,
                 bool_t i_IsProcessShared_b = true);

  ~Mutex();


  bool_t init_b(bool_t i_IsFree_b = true,
                bool_t i_IsProcessShared_b = true);

  bool_t deInit_b();

  /// @brief Lock (decrement) the Mutex
  /// @param[in] i_WaitForEver_b if true the task will wait until the mutex is free.
  /// @return true, if the lock was successfully done.
  bool_t take_b(bool_t i_WaitForEver_b = true);

  /// @brief free the Mutex
  void give_v();

  uint8_t getLockCount_u8() { return lockCount_u8; };

private:

  // disallow copy
  Mutex(const Mutex& rhs);
  Mutex& operator=(const Mutex& rhs);

  Mutex_s    mutex_s;

  ThreadID_t ownerID_t;

  uint8_t    lockCount_u8;
};

}

#endif // OSAL_MUTEX_H
