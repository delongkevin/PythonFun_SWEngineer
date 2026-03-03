/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */
/*
 * ME_SharedMemory_AUTOSAR.c
 *
 *  Creation Date: 21.11.2017
 *         Author: Marcel Engelhardt
 *        Company: Magna Electronics
 */

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

#include "platform/stdlib/StdLibTypes.h"
#include "platform/stdlib/ME_Assert.h"
#include "platform/stdlib/ME_Semaphore.h"
#include "platform/stdlib/ME_SharedMemory.h"


static const void *   C_ME_MAP_FAILED_pv   = (void*)-1; // PRQA S 306 // Cast between a pointer to object and an integral type
static const sint32_t C_ME_MAP_FAILED_si32 = (sint32_t)-1;



#define c_ShareMemoryPoolSize_u32           (20 * 1024U * 1024U)
static uint32_t s_SharedMemoryPointer_u32 = 0U;
static uint8_t s_ShareMemoryPool_au8[c_ShareMemoryPoolSize_u32];

// Initialize the shared memory
PlatformError_t ME_SharedMemory_Init_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_v)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(i_Size_u32 < c_ShareMemoryPoolSize_u32)
  {
    *b_SharedMemoryData_v = &s_ShareMemoryPool_au8[s_SharedMemoryPointer_u32];

    s_SharedMemoryPointer_u32 += i_Size_u32;

    v_Error_t = e_PeOk;
  }

  return v_Error_t;
}

// Create or access to the shared mem
PlatformError_t ME_SharedMemory_Map_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_v)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Remove access to the shared mem
PlatformError_t ME_SharedMemory_UnMap_t(SharedMemory_s* b_ShMem_po, uint32_t i_Size_u32, void* b_SharedMemoryData_v)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Free the shared memory
PlatformError_t ME_SharedMemory_UnLink_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}


// Lock the mapping of the shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_LockPhysical_t(const void* b_PhysicalMemoryData_pv, uint32_t i_Size_u32)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Lock the mapping of all shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_LockAllPhysical_t(void)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}


// Initialize (create) the shared memory and return its physical address also
PlatformError_t ME_SharedMemory_InitPhysical_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv, void** b_PhysicalMemoryData_ppv)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Access the shared mem and return its physical address also
PlatformError_t ME_SharedMemory_MapPhysical_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv, void** b_PhysicalMemoryData_ppv)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Access the shared mem by its physical address
PlatformError_t ME_SharedMemory_MapPhysicalByAddress_t(size_t i_PhysicalMemoryAddr_t, size_t i_Size_t, void** o_VirtualMemoryAddr_ppv)
{
  // implement me
  return e_PeFault;
}

// Unlock the mapping of the shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_UnlockPhysical_t(void* b_PhysicalMemoryData_pv, size_t i_Size_t)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Unlock the mapping of all shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_UnlockAllPhysical_t(void)
{
  PlatformError_t v_Error_t = e_PeOk;

  return e_PeOk;
}

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined
