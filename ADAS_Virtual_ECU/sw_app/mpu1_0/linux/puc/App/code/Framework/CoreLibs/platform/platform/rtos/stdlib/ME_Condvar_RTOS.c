/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */
// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

// stdlib header include
#include "platform/stdlib/ME_Condvar.h"
#include "platform/stdlib/ME_Mutex.h"


PlatformError_t ME_Condvar_Init_t(Condvar_s* b_Condvar_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  ME_Mutex_Init_t(&b_Condvar_po->MEMutex_po, true);

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

  ME_Condvar_Broadcast_t(b_Condvar_po);

  return v_Error_t;
}

// signal a broadcast to all waiting threads
PlatformError_t ME_Condvar_Broadcast_t(Condvar_s* b_Condvar_po)
{
  uint8_t v_I_u8 = 0;
  PlatformError_t v_Error_t = e_PeOk;

  ME_Mutex_Lock_t(&b_Condvar_po->MEMutex_po);
  if(b_Condvar_po->taskHandles_at[0] != NULL)
  {
    xTaskNotify(b_Condvar_po->taskHandles_at[0], 0, eNoAction);
    b_Condvar_po->taskHandles_at[0] = NULL;
  }
  ME_Mutex_UnLock_t(&b_Condvar_po->MEMutex_po);

  return v_Error_t;
}

// Wait on a Condvar
PlatformError_t ME_Condvar_Wait_t(Condvar_s* b_Condvar_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t = e_PeOk;

  ME_Mutex_Lock_t(&b_Condvar_po->MEMutex_po);
  b_Condvar_po->taskHandles_at[0] = xTaskGetCurrentTaskHandle();
  ME_Mutex_UnLock_t(&b_Condvar_po->MEMutex_po);

  xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);

  return v_Error_t;
}

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined
