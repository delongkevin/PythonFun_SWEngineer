/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_Mutex.h
/// @brief Interface to abstract standard-library Mutex
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ME_MUTEX_H
#define ME_MUTEX_H


#include "platform/PlatformSpecs.h"

#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif

// --------------------------------------------------------------------------
/// Initialize a mutex based on the underlying platform.
///
/// If the shared flag is set to \c true any thread that has access to the memory
/// where the mutex is allocated can operate on it, even if the mutex is allocated
/// in memory that's shared by multiple processes.
/// Otherwise, the mutex can be accessed only by threads created within the same process
/// as the thread that initialized the mutex. if threads from other processes try to access
/// the private mutex, the behavior is undefined.

/// @param[in,out] b_Mutex_po Pointer to the mutex to be initialized
/// @param[in]     i_Shared_b \c true, if the mutex is to be shared, \c false otherwise
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Mutex_Init_t(Mutex_s* b_Mutex_po, bool_t i_Shared_b);

// --------------------------------------------------------------------------
/// Lock a mutex.
///
/// @param[in,out] b_Mutex_po Pointer to the mutex to be locked
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Mutex_Lock_t(Mutex_s* i_Mutex_po);

// --------------------------------------------------------------------------
/// Unblocking try to lock a mutex.
///
/// @param[in,out] b_Mutex_po Pointer to the mutex to be locked
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Mutex_TryLock_t(Mutex_s* i_Mutex_po);

// --------------------------------------------------------------------------
/// Unlock a mutex.
///
/// @param[in,out] b_Mutex_po Pointer to the mutex to be unlocked
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Mutex_UnLock_t(Mutex_s* i_Mutex_po);

// --------------------------------------------------------------------------
/// Destroy a (locked, unlocked) mutex.
///
/// Only the owner of a mutex can destroy that mutex.
///
/// @param[in,out] b_Mutex_po Pointer to the mutex to be destroyed
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Mutex_Destroy_t(Mutex_s* b_Mutex_po);

#if defined(__cplusplus)
}; // extern C
#endif

#endif // ME_MUTEX_H
