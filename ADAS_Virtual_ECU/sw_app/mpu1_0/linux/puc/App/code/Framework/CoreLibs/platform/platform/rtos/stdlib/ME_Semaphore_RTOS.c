/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */
// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

// stdlib header include
#include "platform/stdlib/ME_Semaphore.h"

// NOT named semaphore
PlatformError_t ME_Semaphore_Init_t(Semaphore_s* b_Semaphore_po, sint32_t i_Shared_s32, uint32_t i_Value_u32)
{
  PlatformError_t v_Error_t = e_PeOk;

  b_Semaphore_po->handle_t = xSemaphoreCreateCounting(32, i_Value_u32);

  return v_Error_t;
}

// named semaphore
PlatformError_t ME_Semaphore_Open_t(Semaphore_s* b_Semaphore_po, const char_t* i_Name_pc, SemaphoreOpenFlags_t i_OpenFlag_e, SemaphoreModeFlags_t i_ModeFlags_e, uint32_t i_Value_u32)
{
  PlatformError_t v_Error_t = e_PeOk;

  b_Semaphore_po->handle_t = xSemaphoreCreateCounting(32, i_Value_u32);

  return v_Error_t;
}

// Destroy an unnamed semaphore
PlatformError_t ME_Semaphore_Destroy_t(Semaphore_s* b_Semaphore_po)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Get the value of a named or unnamed semaphore
PlatformError_t ME_Semaphore_GetValue_t(Semaphore_s* b_Semaphore_po, sint32_t* o_value_ps32)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Increment a named or unnamed semaphore
PlatformError_t ME_Semaphore_Post_t(Semaphore_s* b_Semaphore_po)
{
  PlatformError_t v_Error_t = e_PeOk;

  if(pdPASS != xSemaphoreGive(b_Semaphore_po->handle_t))
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Wait on a named or unnamed semaphore, but don't block
PlatformError_t ME_Semaphore_TryWait_t(Semaphore_s* b_Semaphore_po)
{
  PlatformError_t v_Error_t = e_PeOk;

  if(pdPASS != xSemaphoreTake(b_Semaphore_po->handle_t, 0))
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Destroy a named semaphore
PlatformError_t ME_Semaphore_Unlink_t(const char_t* i_Name_pc)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

// Wait on a named or unnamed semaphore
PlatformError_t ME_Semaphore_Wait_t(Semaphore_s* b_Semaphore_po)
{

  PlatformError_t v_Error_t = e_PeOk;

  if(pdPASS != xSemaphoreTake(b_Semaphore_po->handle_t, portMAX_DELAY))
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined
