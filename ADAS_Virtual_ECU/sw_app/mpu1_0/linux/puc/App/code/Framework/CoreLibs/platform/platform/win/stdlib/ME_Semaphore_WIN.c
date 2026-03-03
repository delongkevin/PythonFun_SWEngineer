//--------------------------------------------------------------------------
/// @file ME_Semaphore_WIN.c
/// @brief Windows implementation for standard-library File
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

// Compile this file for windows only
#include "platform/PlatformSpecs.h"
#ifdef ME_PLATFORM_WIN

// include stdlib header
#include "platform/stdlib/ME_Semaphore.h"

PlatformError_t ME_Semaphore_Init_t(Semaphore_s* b_Semaphore_po, sint32_t i_Shared_s32, uint32_t i_Value_u32)
{
   PlatformError_t v_Error_t = e_PeOk;
 
   if (NULL == b_Semaphore_po)
   {
     v_Error_t = e_PeInvalid;
   }
   else
   {
     b_Semaphore_po->winSem_po = CreateSemaphore(NULL, i_Value_u32, 100, NULL);
     v_Error_t = ME_GetPlatformError_t(-1);
   }
 
   return v_Error_t;
}

PlatformError_t ME_Semaphore_Open_t(Semaphore_s* b_Semaphore_po, const char_t* i_Name_pc, SemaphoreOpenFlags_t i_OpenFlag_e, SemaphoreModeFlags_t i_ModeFlags_e, uint32_t i_Value_u32)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (NULL == b_Semaphore_po)
  {
    v_Error_t = e_PeInvalid;
  }
  else
  {
    b_Semaphore_po->winSem_po = CreateSemaphore(NULL, i_Value_u32, 1000, i_Name_pc);
    v_Error_t = ME_GetPlatformError_t(-1);
  }

  return v_Error_t;
}

PlatformError_t ME_Semaphore_Close_t(Semaphore_s* b_Semaphore_po)
{
  // same functionality
  return ME_Semaphore_Destroy_t(b_Semaphore_po);
}

PlatformError_t ME_Semaphore_Destroy_t(Semaphore_s* b_Semaphore_po)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (NULL == b_Semaphore_po)
  {
    v_Error_t = e_PeInvalid;
  }
  else
  {
    CloseHandle(b_Semaphore_po->winSem_po);
    v_Error_t = ME_GetPlatformError_t(-1);
  }

  return v_Error_t;
}

PlatformError_t ME_Semaphore_GetValue_t(Semaphore_s* b_Semaphore_po, sint32_t* o_value_ps32)
{
  long previous;

  switch (WaitForSingleObject(b_Semaphore_po->winSem_po, 0)) 
  {
    case WAIT_OBJECT_0:
      ReleaseSemaphore(b_Semaphore_po->winSem_po, 1, &previous);
      *o_value_ps32 = previous + 1;
      break;

    case WAIT_TIMEOUT:
      *o_value_ps32 = 0;
    break;

    default: 
      break;
  }

  return ME_GetPlatformError_t(-1);
}

PlatformError_t ME_Semaphore_Post_t(Semaphore_s* b_Semaphore_po)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (false == ReleaseSemaphore(b_Semaphore_po->winSem_po, 1, NULL))
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

PlatformError_t ME_Semaphore_TryWait_t(Semaphore_s* b_Semaphore_po)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (WaitForSingleObject(b_Semaphore_po->winSem_po, 0) == WAIT_TIMEOUT)
  {
    v_Error_t = ME_GetPlatformError_t(-1);
  }
  else
  {
    v_Error_t = e_PeOk;
  }

  return v_Error_t;
}

PlatformError_t ME_Semaphore_Unlink_t(const char_t* i_Name_pc)
{
  // no functionality in windows
  return e_PeOk;
}

PlatformError_t ME_Semaphore_Wait_t(Semaphore_s* b_Semaphore_po)
{
  WaitForSingleObject(b_Semaphore_po->winSem_po, INFINITE);

  return ME_GetPlatformError_t(-1);
}

#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
