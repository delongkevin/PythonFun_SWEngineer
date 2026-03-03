/*
 * ME_SharedMemory_QNX.c
 *
 *  Creation Date: 21.11.2017
 *         Author: Marcel Engelhardt
 *        Company: Magna Electronics
 */

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for QNX only
#ifdef ME_PLATFORM_QNX

#include "platform/stdlib/StdLibTypes.h"
#include "platform/stdlib/ME_Assert.h"
#include "platform/stdlib/ME_Semaphore.h"
#include "platform/stdlib/ME_SharedMemory.h"

#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>


static const void *   C_ME_MAP_FAILED_pv   = (void*)-1; // PRQA S 306 // Cast between a pointer to object and an integral type
static const sint32_t C_ME_MAP_FAILED_si32 = (sint32_t)-1;

// Initialize the shared memory
PlatformError_t ME_SharedMemory_Init_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeUnmapped;
  sint32_t        v_Fd_s32;

  if((NULL != b_ShMem_po) && (NULL != b_SharedMemoryData_ppv))
  {
    // unlink to be sure shared mem is gone
    if(i_Name_pc != NULL)
    {
      (void)shm_unlink(i_Name_pc); // do not care for the result
    }

    /* create the shared memory object */
    if(i_Name_pc != NULL)
    {
      v_Fd_s32 = shm_open(i_Name_pc , O_RDWR | O_CREAT | O_EXCL, 0400); // PRQA S 339 // Octal is used for mode: Read Write for Own|Group|Other = 666
    }
    else
    {
      v_Fd_s32 = shm_open(SHM_ANON , O_RDWR | O_CREAT | O_EXCL, 0400); // PRQA S 339 // Octal is used for mode: Read Write for Own|Group|Other = 666
      shm_ctl(v_Fd_s32, SHMCTL_ANON, 0, i_Size_u32);
    }

    Assert(v_Fd_s32 != -1);

    if(v_Fd_s32 != -1)
    {
      /* set the size of the shared memory object */
      v_Result_s32 = ftruncate(v_Fd_s32, (off_t)i_Size_u32);
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
      Assert(v_Error_t == e_PeOk);

      if(v_Error_t == e_PeOk)
      {
        *b_SharedMemoryData_ppv = mmap(NULL, i_Size_u32, PROT_READ | PROT_WRITE, MAP_SHARED, v_Fd_s32, 0);
        if(C_ME_MAP_FAILED_pv == *b_SharedMemoryData_ppv)
        {
          v_Error_t = ME_GetPlatformError_t(C_ME_MAP_FAILED_si32);
          Assert(C_ME_MAP_FAILED_pv != *b_SharedMemoryData_ppv);
        }
        else
        {
          b_ShMem_po->dummy = 1; // 1=init //do this to satisfy QAC, as in other implementation this b_ShMem_po pointer is needed
        }
      }

      /* don't need fd anymore, so close it */
      (void)close(v_Fd_s32);
    }
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Create or access to the shared mem
PlatformError_t ME_SharedMemory_Map_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeUnmapped;
  sint32_t        fd;

  if((NULL != b_ShMem_po) && (NULL != b_SharedMemoryData_ppv))
  {
    /* open the shared memory object */
    fd = shm_open(i_Name_pc, O_RDWR, 0666); // PRQA S 339 // Octal is used for mode: Read Write for Own|Group|Other = 666
    Assert(fd != -1);

    if(fd != -1)
    {
      /* set the size of the shared memory object */
      v_Result_s32 = ftruncate(fd, (off_t)i_Size_u32);
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
      Assert(v_Error_t == e_PeOk);

      if(v_Error_t == e_PeOk)
      {
        *b_SharedMemoryData_ppv = mmap(0, i_Size_u32, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if(C_ME_MAP_FAILED_pv == *b_SharedMemoryData_ppv)
        {
          v_Error_t = ME_GetPlatformError_t(C_ME_MAP_FAILED_si32);
          Assert(C_ME_MAP_FAILED_pv != *b_SharedMemoryData_ppv);
        }
        else
        {
          b_ShMem_po->dummy += 1; // increment as one more instance is mapped //do this to satisfy QAC, as in other implementation this b_ShMem_po pointer is needed
        }
      }

      /* don't need fd anymore, so close it */
      (void)close(fd);
    }
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Remove access to the shared mem
PlatformError_t ME_SharedMemory_UnMap_t(SharedMemory_s* b_ShMem_po, uint32_t i_Size_u32, void* b_SharedMemoryData_pv)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_ShMem_po)
  {
    v_Result_s32 = munmap(b_SharedMemoryData_pv, i_Size_u32);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);

    b_ShMem_po->dummy -= 1; // decrement as one more instance is mapped //do this to satisfy QAC, as in other implementation this b_ShMem_po pointer is needed
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Free the shared memory
PlatformError_t ME_SharedMemory_UnLink_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_ShMem_po)
  {
    v_Result_s32 = shm_unlink(i_Name_pc);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);

    if(v_Error_t == e_PeOk)
    {
      b_ShMem_po->dummy = -1; // -1=unlinked //do this to satisfy QAC, as in other implementation this b_ShMem_po pointer is needed
    }
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}


// Lock the mapping of the shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_LockPhysical_t(const void* b_PhysicalMemoryData_pv, uint32_t i_Size_u32)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  v_Result_s32 = mlock(b_PhysicalMemoryData_pv, i_Size_u32);
  Assert(v_Result_s32 == 0);

  v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  Assert(v_Error_t == e_PeOk);

  return v_Error_t;
}

// Lock the mapping of all shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_LockAllPhysical_t(void)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  v_Result_s32 = mlockall(MCL_CURRENT | MCL_FUTURE);
  Assert(v_Result_s32 == 0);

  v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  Assert(v_Error_t == e_PeOk);

  return v_Error_t;
}


// Initialize (create) the shared memory and return its physical address also
PlatformError_t ME_SharedMemory_InitPhysical_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv, void** b_PhysicalMemoryData_ppv)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeUnmapped;
  sint32_t        fd;
  off_t           offset;

  if((NULL != b_ShMem_po) && (NULL != b_SharedMemoryData_ppv) && (NULL != b_PhysicalMemoryData_ppv))
  {
    // unlink to be sure shared mem is gone
    (void)shm_unlink(i_Name_pc); // do not care for the result

    /* create the shared memory object */
    fd = shm_open(i_Name_pc , O_RDWR | O_CREAT | O_EXCL, 0666); // PRQA S 339 // Octal is used for mode: Read Write for Own|Group|Other = 666
    Assert(fd != -1);

    if(fd != -1)
    {
      /* set the size of the shared memory object */
      v_Result_s32 = ftruncate(fd, (off_t)i_Size_u32);
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
      Assert(v_Error_t == e_PeOk);

      if(v_Error_t == e_PeOk)
      {
        *b_SharedMemoryData_ppv = mmap(0, i_Size_u32, PROT_NOCACHE | PROT_READ | PROT_WRITE, MAP_SHARED | MAP_NOINIT, fd, 0);
        if(C_ME_MAP_FAILED_pv == *b_SharedMemoryData_ppv)
        {
          v_Error_t = ME_GetPlatformError_t(C_ME_MAP_FAILED_si32);
          Assert(C_ME_MAP_FAILED_pv != *b_SharedMemoryData_ppv);

          *b_SharedMemoryData_ppv = 0;
          *b_PhysicalMemoryData_ppv = 0;
        }
        else
        {
          // Translate the virtual address into a physical address
          v_Result_s32 = mem_offset(*b_SharedMemoryData_ppv, NOFD, i_Size_u32, &offset, 0);
          v_Error_t = ME_GetPlatformError_t(v_Result_s32);
          Assert(v_Error_t == e_PeOk);

          if(v_Error_t == e_PeOk)
          {
            *b_PhysicalMemoryData_ppv = (void*)offset; // PRQA S 0306 // Cast between a pointer to object and an integral type

            b_ShMem_po->dummy = 1; // 1=init //do this to satisfy QAC, as in other implementation this b_ShMem_po pointer is needed
          }
          else
          {
            *b_SharedMemoryData_ppv = 0;
            *b_PhysicalMemoryData_ppv = 0;
          }
        }
      }

      /* don't need fd anymore, so close it */
      (void)close(fd);
    }
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Access the shared mem and return its physical address also
PlatformError_t ME_SharedMemory_MapPhysical_t(SharedMemory_s* b_ShMem_po, const char_t* i_Name_pc, uint32_t i_Size_u32, void** b_SharedMemoryData_ppv, void** b_PhysicalMemoryData_ppv)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeUnmapped;
  sint32_t        fd;
  off_t           v_Offset_t;

  if((NULL != b_ShMem_po) && (NULL != b_SharedMemoryData_ppv) && (NULL != b_PhysicalMemoryData_ppv))
  {
    /* create the shared memory object */
    fd = shm_open(i_Name_pc , O_RDWR | O_CREAT | O_EXCL, 0666); // PRQA S 339 // Octal is used for mode: Read Write for Own|Group|Other = 666
    Assert(fd != -1);

    if(fd != -1)
    {
      /* set the size of the shared memory object */
      v_Result_s32 = ftruncate(fd, (off_t)i_Size_u32);
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
      Assert(v_Error_t == e_PeOk);

      if(v_Error_t == e_PeOk)
      {
        *b_SharedMemoryData_ppv = mmap(0, i_Size_u32, PROT_NOCACHE | PROT_READ | PROT_WRITE, MAP_SHARED | MAP_NOINIT, fd, 0);
        if(C_ME_MAP_FAILED_pv == *b_SharedMemoryData_ppv)
        {
          v_Error_t = ME_GetPlatformError_t(C_ME_MAP_FAILED_si32);
          Assert(C_ME_MAP_FAILED_pv != *b_SharedMemoryData_ppv);

          *b_SharedMemoryData_ppv = 0;
          *b_PhysicalMemoryData_ppv = 0;
        }
        else
        {
          // Translate the virtual address into a physical address
          v_Result_s32 = mem_offset(*b_SharedMemoryData_ppv, NOFD, i_Size_u32, &v_Offset_t, 0);
          v_Error_t = ME_GetPlatformError_t(v_Result_s32);
          Assert(v_Error_t == e_PeOk);

          if(v_Error_t == e_PeOk)
          {
            *b_PhysicalMemoryData_ppv = (void*)v_Offset_t; // PRQA S 0306 // Cast between a pointer to object and an integral type

            b_ShMem_po->dummy = 1; // 1=init //do this to satisfy QAC, as in other implementation this b_ShMem_po pointer is needed
          }
          else
          {
            *b_SharedMemoryData_ppv = 0;
            *b_PhysicalMemoryData_ppv = 0;
          }
        }
      }

      /* don't need fd anymore, so close it */
      (void)close(fd);
    }
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Access the shared mem by its physical address
PlatformError_t ME_SharedMemory_MapPhysicalByAddress_t(size_t i_PhysicalMemoryAddr_t, size_t i_Size_t, void** o_VirtualMemoryAddr_ppv)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (NULL != o_VirtualMemoryAddr_ppv)
  {
    *o_VirtualMemoryAddr_ppv = mmap_device_memory(
      NULL,
      i_Size_t,
      PROT_READ | PROT_WRITE | PROT_NOCACHE,
      0,
      i_PhysicalMemoryAddr_t);

    if (*o_VirtualMemoryAddr_ppv == C_ME_MAP_FAILED_pv)
    {
      v_Error_t = e_PeFault;
    }
    else
    {
      v_Error_t = ME_GetPlatformError_t(errno);
    }
  }

  return v_Error_t;
}

// Unlock the mapping of the shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_UnlockPhysical_t(void* b_PhysicalMemoryData_pv, size_t i_Size_t)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  v_Result_s32 = munmap_device_memory(b_PhysicalMemoryData_pv, i_Size_t);
  Assert(v_Result_s32 == 0);

  v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  Assert(v_Error_t == e_PeOk);

  return v_Error_t;
}

// Unlock the mapping of all shared memory for usage of the *PhysicalMemory* functions
PlatformError_t ME_SharedMemory_UnlockAllPhysical_t(void)
{
  (void)munlockall();

  return e_PeOk;
}

#endif // ME_PLATFORM_QNX
