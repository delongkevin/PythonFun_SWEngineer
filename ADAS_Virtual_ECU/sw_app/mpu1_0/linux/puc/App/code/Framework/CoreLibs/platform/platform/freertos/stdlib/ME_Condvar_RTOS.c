/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */
// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

// stdlib header include
#include "platform/stdlib/ME_Condvar.h"
#include "platform/stdlib/ME_Mutex.h"

//#include <pthread.h>

PlatformError_t ME_Condvar_Init_t(Condvar_s* b_Condvar_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Destroy a Condvar
PlatformError_t ME_Condvar_Destroy_t(Condvar_s* b_Condvar_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// signal to Condvar
PlatformError_t ME_Condvar_Signal_t(Condvar_s* b_Condvar_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// signal a broadcast to all waiting threads
PlatformError_t ME_Condvar_Broadcast_t(Condvar_s* b_Condvar_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Wait on a Condvar
PlatformError_t ME_Condvar_Wait_t(Condvar_s* b_Condvar_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined
