/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_Condvar.h
/// @brief Interface to abstract standard-library conditional variable
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Marcel Engelhardt (Marcel.Engehardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ME_CONDVAR_H
#define ME_CONDVAR_H


#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif


// --------------------------------------------------------------------------
/// Initializes a unnamed condition variable.
///
/// @param[in,out] b_Condvar_po Pointer to the condition variable to be initialized
/// @return        Platform error representing the result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Condvar_Init_t(Condvar_s* b_Condvar_po);

// --------------------------------------------------------------------------
/// Destroys a unnamed condition variable.
///
/// @param[in,out] b_Condvar_po Pointer to the condition variable to be destroyed
/// @return        Platform error representing the result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Condvar_Destroy_t(Condvar_s* b_Condvar_po);

// --------------------------------------------------------------------------
/// Increments a (named / unnamed) condition variable.
///
/// @param[in,out] b_Condvar_po Pointer to the condition variable to be incremented
/// @return        Platform error representing the result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Condvar_Signal_t(Condvar_s* b_Condvar_po);

// --------------------------------------------------------------------------
/// Signals a broadcast to all threads waiting on the condition variable passed in.
///
/// @param[in,out] b_Condvar_po Pointer to the condition variable broadcast signal has to be made for
/// @return        Platform error representing the result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Condvar_Broadcast_t(Condvar_s* b_Condvar_po);

// --------------------------------------------------------------------------
/// Blocking wait on the condition variable passed in.
///
/// @param[in,out] b_Condvar_po Pointer to the condition variable to be waited on
/// @return        Platform error representing the result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Condvar_Wait_t(Condvar_s* b_Condvar_po);


#if defined(__cplusplus)
}; // extern C
#endif

#endif // ME_CONDVAR_H
