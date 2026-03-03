/*
 * ME_SharedMemory_WIN.c
 *
 *  Creation Date: 21.11.2017
 *         Author: Martin Rachor
 *        Company: Magna Electronics
 */

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for WIN only
#ifdef ME_PLATFORM_WIN

#include "platform/stdlib/ME_Assert.h"
#include "platform/stdlib/ME_Semaphore.h"
#include "platform/stdlib/ME_SharedMemory.h"


static const void *   C_ME_MAP_FAILED_pv   = (void*)-1; // PRQA S 306 // Cast between a pointer to object and an integral type
static const sint32_t C_ME_MAP_FAILED_si32 = (sint32_t)-1;

// Initialize the shared memory
PlatformError_t ME_SharedMemory_Init_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_v)
{
  PlatformError_t v_Error_t = e_PeUnmapped;

  if((NULL != b_ShMem_po) && (NULL != b_SharedMemoryData_v))
  {
    b_ShMem_po->shmFileHandle_t = CreateFileMapping(
                                                    INVALID_HANDLE_VALUE,    // use paging file
                                                    NULL,                    // default security
                                                    PAGE_READWRITE,          // read/write access
                                                    0,                       // maximum object size (high-order DWORD)
                                                    i_Size_u32,              // maximum object size (low-order DWORD)
                                                    i_Name_pc);              // name of mapping object
  
    if(ME_INVALID_FILE_HANDLE != b_ShMem_po->shmFileHandle_t)
    {
      v_Error_t = ME_SharedMemory_Map_t(b_ShMem_po, i_Name_pc, i_Size_u32, b_SharedMemoryData_v);
    }
    else
    {
      v_Error_t = e_PeFault;
    }
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Create or access to the shared mem
PlatformError_t ME_SharedMemory_Map_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_v)
{
  sint32_t        v_Result_s32      = 0;
  PlatformError_t v_Error_t         = e_PeOk;

  if(NULL != b_ShMem_po)
  {

    b_ShMem_po->shmFileHandle_t = OpenFileMapping(FILE_MAP_ALL_ACCESS, false, i_Name_pc);

    if(ME_INVALID_FILE_HANDLE != b_ShMem_po->shmFileHandle_t)
    {
      *b_SharedMemoryData_v = (LPTSTR) MapViewOfFile(
                                                    b_ShMem_po->shmFileHandle_t, // handle to map object
                                                    FILE_MAP_ALL_ACCESS,  // read/write permission
                                                    0,
                                                    0,
                                                    i_Size_u32);
    }

    if(NULL == b_SharedMemoryData_v)
    {
      v_Error_t = e_PeFault;
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Remove access to the shared mem
PlatformError_t ME_SharedMemory_UnMap_t(SharedMemory_s* b_ShMem_po, uint32_t i_Size_u32, void* b_SharedMemoryData_v)
{
  PlatformError_t v_Error_t         = e_PeOk;

  if(false == UnmapViewOfFile(b_SharedMemoryData_v))
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Free the shared memory
PlatformError_t ME_SharedMemory_UnLink_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc)
{
  PlatformError_t v_Error_t = e_PeOk;

  if((NULL != b_ShMem_po) && (ME_INVALID_FILE_HANDLE != b_ShMem_po->shmFileHandle_t))
  {
    CloseHandle(b_ShMem_po->shmFileHandle_t);
  }

  return v_Error_t;
}


// Lock the mapping of the shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_LockPhysical_t(const void* b_PhysicalMemoryData_pv, uint32_t i_Size_u32)
{
  return e_PeOk;
}

// Lock the mapping of all shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_LockAllPhysical_t(void)
{
  return e_PeOk;
}

// Initialize (create) the shared memory and return its physical address also
PlatformError_t ME_SharedMemory_InitPhysical_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv, void** b_PhysicalMemoryData_ppv)
{
  PlatformError_t v_Error_t = ME_SharedMemory_Init_t(b_ShMem_po, i_Name_pc, i_Size_u32, b_SharedMemoryData_ppv);

  // Windows does not grant access to the physical memory. We are faking that by returning the virtual memory instead.
  *b_PhysicalMemoryData_ppv = *b_SharedMemoryData_ppv;

  return v_Error_t;
}

// Access the shared mem and return its physical address also
PlatformError_t ME_SharedMemory_MapPhysical_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv, void** b_PhysicalMemoryData_ppv)
{
  PlatformError_t v_Error_t = ME_SharedMemory_Map_t(b_ShMem_po, i_Name_pc, i_Size_u32, b_SharedMemoryData_ppv);

  // Windows does not grant access to the physical memory. We are faking that by returning the virtual memory instead.
  *b_PhysicalMemoryData_ppv = *b_SharedMemoryData_ppv;

  return v_Error_t;
}

// Access the shared mem by its physical address
PlatformError_t ME_SharedMemory_MapPhysicalByAddress_t(size_t i_PhysicalMemoryAddr_u64, size_t i_Size_t, void** o_VirtualMemoryAddr_ppv)
{
  // Windows does not grant access to the physical memory. We are faking that by returning the virtual memory instead.
  *o_VirtualMemoryAddr_ppv = (void*)(i_PhysicalMemoryAddr_u64);

  return e_PeOk;
}

// Unlock the mapping of the shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_UnlockPhysical_t(void* b_PhysicalMemoryData_pv, size_t i_Size_t)
{
  return e_PeOk;
}

// Unlock the mapping of all shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_UnlockAllPhysical_t(void)
{
  return e_PeOk;
}

#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
