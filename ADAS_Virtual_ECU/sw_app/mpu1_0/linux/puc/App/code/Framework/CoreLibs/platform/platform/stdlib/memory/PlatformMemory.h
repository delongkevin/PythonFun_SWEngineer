//--------------------------------------------------------------------------                                                                                                           
/// @file PlatformMemory.h
/// @brief Encapsulates the Two Level Segregated Fit memory allocator and provides a default memory pool.
///
/// For further information, check out the tlsf homepage: http://www.gii.upv.es/tlsf/main/docs
/// This allocator is not thread safe, so we provide a method to register callbacks for lock / unlock.
/// These callbacks are called for all functions that manipulate the memory pool: malloc/realloc/mem align/free
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

#ifndef PLATFORM_MEMORY_H
#define PLATFORM_MEMORY_H

#include "tlsf.h"

// maximum default memory pool size 0x40000000UL = 1gb decimal.
// PRQA S 2400 // global scope, this is a header file

#if defined(__cplusplus)
extern "C" {
#endif

// Callback function typedefs for lock/unlock. we need this for thread safety support. TLSF allocator is not thread safe.
typedef void (*MeplMemoryLockCb_t)   (void); // PRQA S 2400 // global scope, this is the declaration used in c and cpp
typedef void (*MeplMemoryUnlockCb_t) (void); // PRQA S 2400 // global scope, this is the declaration used in c and cpp

// --------------------------------------------------------------------------
/// @brief Registers callbacks for lock and unlock functions
///
/// TLSF implementation is not thread safe, so we define function prototypes for lock / unlock
///
/// @param[in] i_Lock_t   Function pointer to lock function
/// @param[in] i_Unlock_t Function pointer to unlock function
// --------------------------------------------------------------------------
void lMepl_F_RegisterCallbacks_v(MeplMemoryLockCb_t i_Lock_t, MeplMemoryUnlockCb_t i_Unlock_t);

// --------------------------------------------------------------------------
/// @brief Initialize the memory pool
///
/// before including this header, define PLATFORM_MEM_POOL_SIZE to define the pool size.
/// if PALTFORM_MEM_POOL_SIZE is not defined PLATFORM_MAX_DEFAULT_MEM_POOL_SIZE (1gb) gets allocated
// --------------------------------------------------------------------------
void lMepl_F_InitMemoryPool_v(void* i_MemoryPool_pv, size_t i_Size_t);

// --------------------------------------------------------------------------
/// @brief destroy the memory pool
// --------------------------------------------------------------------------
void lMepl_F_DestroyMemoryPool_v(void);

// --------------------------------------------------------------------------
/// @brief allocate memory in O(1) time
/// if target platform is 64 bit, all allocation sizes and addresses are aligned to 8 bytes.
/// if target platform is 32 bit, all allocation sizes and addresses are aligned to 4 bytes.
///
/// @param[in] i_Size_t the size in bytes to allocate
/// @return    void pointer to allocated memory
// --------------------------------------------------------------------------
void* lMepl_F_Malloc_pv(size_t i_Size_t);

// --------------------------------------------------------------------------
/// @brief reallocate memory in O(1) time
///
/// Changes the size of the memory block pointed to by i_Memory_pv O(1).
/// Requests with NULL pointers are treated as malloc.
/// Zero-size requests are treated as lMepl_F_Free_v.
///
/// @param[in] i_Memory_pv pointer to the memory to reallocate
/// @param[in] i_Size_t the size in bytes to reallocate
/// @return    void pointer to reallocated memory
// --------------------------------------------------------------------------
void* lMepl_F_Realloc_pv(void* i_Memory_pv, size_t i_Size_t);

// --------------------------------------------------------------------------
/// @brief free memory in O(1) time. 
///
/// @param[in] i_Memory_pv pointer to the memory to reallocate. We don't attempt to free a null pointer
// --------------------------------------------------------------------------
void lMepl_F_Free_v(const void* i_Memory_pv);

// --------------------------------------------------------------------------
/// @brief allocates a block of size i_Size_t whose address is a multiple of i_Align_u3264. 
///
/// @param[in] i_Align_u3264 the alignment. must be given as a power of two.
/// @param[in] i_Size_t the size in bytes to reallocate
/// @return    void pointer pointing to the address within the block that is on the specified boundary
// --------------------------------------------------------------------------
void* lMepl_F_MemAlign_pv(size_t i_Align_u3264, size_t i_Size_t);

#if defined(__cplusplus)
};
#endif

#endif // PLATFORM_MEMORY_H


