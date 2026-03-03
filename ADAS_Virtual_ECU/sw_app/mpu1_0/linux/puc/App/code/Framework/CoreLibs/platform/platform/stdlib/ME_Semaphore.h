/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_Semaphore.h
/// @brief Interface to abstract standard-library Semaphore
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

#ifndef ME_SEMAPHORE_H
#define ME_SEMAPHORE_H


#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif

// --------------------------------------------------------------------------
/// Flags that affect how the function creates a new semaphore. This argument is a combination of:
typedef enum SemaphoreOpenFlags_e // PRQA S 2400 // global scope, this is a shared c and cpp header file
{
  e_SofCreate = 0,
  e_SofExcl
} SemaphoreOpenFlags_t; // PRQA S 2400 // global scope, this is a shared c and cpp header file

// --------------------------------------------------------------------------
/// \see http://www.qnx.com/developers/docs/6.5.0/index.jsp?topic=%2Fcom.qnx.doc.neutrino_lib_ref%2Fs%2Fsem_open.html
typedef enum SemaphoreModeFlags_e // PRQA S 2400 // global scope, this is a shared c and cpp header file
{
  e_SmfGroup = 0,   // S_IRWXG for group access.
  e_SmfOther,       // S_IRWXO for other's access.
  e_SmfOwn          // S_IRWXU for your own access.
} SemaphoreModeFlags_t; // PRQA S 2400 // global scope, this is a shared c and cpp header file

// --------------------------------------------------------------------------
/// Initialize an unnamed semaphore.
///
/// For more details refer to the respective OS versions of this function.
///
/// @param[in,out] b_Semaphore_po Pointer to the semaphore to be initialized
/// @param[in]     i_Shared_s32   Nonzero if you want the semaphore to be shared between processes via shared memory
/// @param[in]     i_Value_u32    The initial value of the semaphore.
///                               A positive value indicates an unlocked semaphore,
///                               and a value of 0 (zero) indicates a locked semaphore
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Semaphore_Init_t(Semaphore_s* b_Semaphore_po, sint32_t i_Shared_s32, uint32_t i_Value_u32);

// --------------------------------------------------------------------------
/// Create or access a named semaphore.
///
/// @param[in,out] b_Semaphore_po Pointer to the semaphore
/// @param[in]     i_Name_pc      Name of the semaphore to be created / accessed
/// @param[in]     i_OpenFlag_e   Semaphore's Opan flag
/// @param[in]     i_ModeFlags_e  Semaphore's mode flag
/// @param[in]     i_Value_u32    The initial value of the semaphore.
///                               A positive value indicates an unlocked semaphore,
///                               and a value of 0 (zero) indicates a locked semaphore
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Semaphore_Open_t(Semaphore_s* b_Semaphore_po, const char_t* i_Name_pc, SemaphoreOpenFlags_t i_OpenFlag_e, SemaphoreModeFlags_t i_ModeFlags_e, uint32_t i_Value_u32);

// --------------------------------------------------------------------------
// Close a named semaphore.
//
// NOT_IMPLEMENTED
// --------------------------------------------------------------------------
PlatformError_t ME_Semaphore_Close_t(Semaphore_s* b_Semaphore_po);

// --------------------------------------------------------------------------
/// Destroy an unnamed semaphore.
///
/// @pre The semaphore must have been previously initialized by #ME_Semaphore_Init_t.
///
/// @param[in,out] b_Semaphore_po Pointer to the unnamed semaphore to be destroyed
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Semaphore_Destroy_t(Semaphore_s* b_Semaphore_po);

// --------------------------------------------------------------------------
/// Get the value of a semaphore.
///
/// @param[in,out] b_Semaphore_po Pointer to the semaphore
/// @param[in,out] o_value_ps32 Pointer to the variable semaphore's current value has to be stored to
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Semaphore_GetValue_t(Semaphore_s* b_Semaphore_po, sint32_t* o_value_ps32);

// --------------------------------------------------------------------------
/// Increment the value of a semaphore.
///
/// @param[in,out] b_Semaphore_po Pointer to the semaphore whose value has to be incremented
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Semaphore_Post_t(Semaphore_s* b_Semaphore_po);

// --------------------------------------------------------------------------
/// Unblocking try to wait on a semaphore.
///
/// @param[in,out] b_Semaphore_po Pointer to the semaphore to be waited on
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Semaphore_TryWait_t(Semaphore_s* b_Semaphore_po);

// --------------------------------------------------------------------------
/// Destroy a named semaphore.
///
/// @param[in] i_Name_pc Name of the semaphore to be destroyed
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Semaphore_Unlink_t(const char_t* i_Name_pc);

// --------------------------------------------------------------------------
/// Blocking wait on a semaphore.
///
/// @param[in,out] b_Semaphore_po Pointer to the semaphore to be waited on
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Semaphore_Wait_t(Semaphore_s* b_Semaphore_po);


#if defined(__cplusplus)
}; // extern C
#endif

#endif // ME_SEMAPHORE_H
