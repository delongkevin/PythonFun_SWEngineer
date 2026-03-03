/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

/*
 * ME_SharedMemory.h
 *
 *  Creation Date: 21.11.2017
 *         Author: Marcel Engelhardt
 *        Company: Magna Electronics
 */

#ifndef ME_SHAREDMEMORY_H_
#define ME_SHAREDMEMORY_H_

#include "platform/PlatformSpecs.h"

#if defined(__cplusplus)
extern "C"
{
#endif

// --------------------------------------------------------------------------
/// Creates a shared memory object.
///
/// @param[in,out] b_ShMem_po             Pointer to a #SharedMemory_s (for more details refer to OS specific versions of this function)
/// @param[in]     i_Name_pc              Name of the shared memory object to be created
/// @param[in]     i_Size_u32             Nonzero number of bytes to map into the caller's address space
/// @param[in,out] b_SharedMemoryData_ppv Double pointer to store the address of the shared memory region to be created
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_SharedMemory_Init_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv);

// --------------------------------------------------------------------------
/// Access the shared memory.
///
/// @param[in,out] b_ShMem_po             Pointer to a #SharedMemory_s (for more details refer to OS specific versions of this function)
/// @param[in]     i_Name_pc              Name of the shared memory object to be created
/// @param[in]     i_Size_u32             Nonzero number of bytes to map into the caller's address space
/// @param[in,out] b_SharedMemoryData_ppv Double pointer to store the address of the shared memory region to be created
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_SharedMemory_Map_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv);

// --------------------------------------------------------------------------
/// Remove access to the shared memory.
///
/// @param[in,out] b_ShMem_po            Pointer to a #SharedMemory_s created or opened before
/// @param[in]     i_Size_u32            Length of the mapped memory region to be unmapped
/// @param[in,out] b_SharedMemoryData_pv Starting address of the shared memory region to be unmapped
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_SharedMemory_UnMap_t(SharedMemory_s* b_ShMem_po, uint32_t i_Size_u32, void* b_SharedMemoryData_pv);

// --------------------------------------------------------------------------
/// Free the shared memory.
///
/// @param[in,out] b_ShMem_po Pointer to a #SharedMemory_s (for more details refer to OS specific versions of this function)
/// @param[in]     i_Name_pc  Name of the shared memory object to be freed
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_SharedMemory_UnLink_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc);


// --------------------------------------------------------------------------
/// Lock the mapping of the shared memory for usage of the *PhysicalMemory* functions.
///
/// @param[in,out] b_PhysicalMemoryData_pv Pointer to the physical memory region to be locked
/// @param[in]     i_Size_u32              Size of the physical memory region to be locked
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_SharedMemory_LockPhysical_t(const void* b_PhysicalMemoryData_pv, uint32_t i_Size_u32);

// --------------------------------------------------------------------------
/// Lock the mapping of all shared memory for usage of the *PhysicalMemory* functions.
///
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_SharedMemory_LockAllPhysical_t(void);

// --------------------------------------------------------------------------
/// Initialize (create) the shared memory and return its physical address also.
///
/// @param[in,out] b_ShMem_po               Pointer to a #SharedMemory_s (for more details refer to OS specific versions of this function)
/// @param[in]     i_Name_pc                i_Name_pc  Name of the shared memory object
/// @param[in]     i_Size_u32               Nonzero number of bytes to map into the caller's address space
/// @param[in,out] b_SharedMemoryData_ppv   Double pointer to store the address of the shared memory region to be created
/// @param[in,out] b_PhysicalMemoryData_ppv Double pointer to store the physical address of the shared memory region to be created
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_SharedMemory_InitPhysical_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv, void** b_PhysicalMemoryData_ppv);

// --------------------------------------------------------------------------
/// Access the shared mem and return its physical address also.
///
/// @param[in,out] b_ShMem_po               Pointer to a #SharedMemory_s (for more details refer to OS specific versions of this function)
/// @param[in]     i_Name_pc                Name of the shared memory object to be created
/// @param[in]     i_Size_u32               Nonzero number of bytes to map into the caller's address space
/// @param[in,out] b_SharedMemoryData_ppv   Double pointer to store the address of the shared memory region to be mapped
/// @param[in,out] b_PhysicalMemoryData_ppv Double pointer to store the physical address of the shared memory region to be mapped
/// @return bla
/// @return Platform error representing result of the operation
PlatformError_t ME_SharedMemory_MapPhysical_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv, void** b_PhysicalMemoryData_ppv);

// --------------------------------------------------------------------------
/// Access the shared mem by its physical address.
///
/// @param[in,out] b_ShMem_po              Pointer to a #SharedMemory_s (for more details refer to OS specific versions of this function)
/// @param[in]     i_PhysicalMemoryAddr_t Address of the physical memory region
/// @param[in]     i_Size_u32              Nonzero number of bytes to map into the caller's address space
/// @param[in,out] o_SharedMemoryData_ppv  Double pointer to store the address of the shared memory region to be mapped
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_SharedMemory_MapPhysicalByAddress_t(size_t i_PhysicalMemoryAddr_t, size_t i_Size_t, void** o_VirtualMemoryAddr_ppv);

// --------------------------------------------------------------------------
/// Unlock the mapping of the shared memory for usage of the *PhysicalMemory* functions.
///
/// @param[in,out] b_PhysicalMemoryData_pv Address of the physical memory region to be unlocked
/// @param[in]     i_Size_u32              Size of the physical memory region to be unlocked
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_SharedMemory_UnlockPhysical_t(void* b_PhysicalMemoryData_pv, size_t i_Size_t);

// --------------------------------------------------------------------------
/// Unlock the mapping of all shared memory for usage of the *PhysicalMemory* functions.
///
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_SharedMemory_UnlockAllPhysical_t(void);


#if defined(__cplusplus)
}; // extern C
#endif



#endif /* ME_SHAREDMEMORY_H_ */
