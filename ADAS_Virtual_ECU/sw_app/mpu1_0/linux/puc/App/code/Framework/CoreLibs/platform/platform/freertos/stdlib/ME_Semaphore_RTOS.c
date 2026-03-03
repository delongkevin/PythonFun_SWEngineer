/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */
// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

// stdlib header include
#include "platform/stdlib/ME_Semaphore.h"
#include <fcntl.h>

// NOT named semaphore
// http://www.qnx.com/developers/docs/6.5.0/topic/com.qnx.doc.neutrino_lib_ref/s/sem_init.html?cp=13_4_22_31
PlatformError_t ME_Semaphore_Init_t(Semaphore_s* b_Semaphore_po, sint32_t i_Shared_s32, uint32_t i_Value_u32)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// named semaphore
// http://www.qnx.com/developers/docs/6.5.0/topic/com.qnx.doc.neutrino_lib_ref/s/sem_open.html?cp=13_4_22_32
PlatformError_t ME_Semaphore_Open_t(Semaphore_s* b_Semaphore_po, const char_t* i_Name_pc, SemaphoreOpenFlags_t i_OpenFlag_e, SemaphoreModeFlags_t i_ModeFlags_e, uint32_t i_Value_u32)
{
  // http://www.qnx.com/developers/docs/6.5.0/index.jsp?topic=%2Fcom.qnx.doc.neutrino_lib_ref%2Fs%2Fsem_open.html
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Destroy an unnamed semaphore
PlatformError_t ME_Semaphore_Destroy_t(Semaphore_s* b_Semaphore_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Get the value of a named or unnamed semaphore
PlatformError_t ME_Semaphore_GetValue_t(Semaphore_s* b_Semaphore_po, sint32_t* o_value_ps32)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Increment a named or unnamed semaphore
PlatformError_t ME_Semaphore_Post_t(Semaphore_s* b_Semaphore_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Wait on a named or unnamed semaphore, but don't block
PlatformError_t ME_Semaphore_TryWait_t(Semaphore_s* b_Semaphore_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Destroy a named semaphore
PlatformError_t ME_Semaphore_Unlink_t(const char_t* i_Name_pc)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Wait on a named or unnamed semaphore
PlatformError_t ME_Semaphore_Wait_t(Semaphore_s* b_Semaphore_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined
