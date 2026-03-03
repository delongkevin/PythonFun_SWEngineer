/*
 * ME_Interrupt_QNX.c
 *
 *  Creation Date: 20,02,2020
 *         Author: Martin Rachor
 *        Company: Magna Electronics
 */

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for QNX only
#ifdef ME_PLATFORM_QNX

// stdlib header include
#include "platform/stdlib/ME_Interrupt.h"

#include <sys/neutrino.h>
#include <sys/procmgr.h>

PlatformError_t ME_Interrupt_Attach_t(InterruptHandle_t* i_InterruptHandle_pt, uint32_t i_IrqId_u32)
{
  PlatformError_t v_Error_t = e_PeInvalid;
  
  if(i_InterruptHandle_pt != NULL)
  {
    struct sigevent v_Event_t;
    memset(&v_Event_t, 0, sizeof(v_Event_t));
    v_Event_t.sigev_notify = SIGEV_INTR;

    ThreadCtl(_NTO_TCTL_IO, NULL);

    sint32_t v_IntID_s32 = InterruptAttachEvent(i_IrqId_u32, &v_Event_t, 0);

    if(v_IntID_s32 > 0)
    {
      i_InterruptHandle_pt->interruptId_s32 = v_IntID_s32;
      i_InterruptHandle_pt->irqId_s32 = i_IrqId_u32;
      v_Error_t = e_PeOk;
    }
  }
  
  return v_Error_t;
}

PlatformError_t ME_Interrupt_Mask_t(const InterruptHandle_t* i_InterruptHandle_pt)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(i_InterruptHandle_pt != NULL)
  {
    InterruptMask(i_InterruptHandle_pt->irqId_s32, i_InterruptHandle_pt->interruptId_s32);

    v_Error_t = e_PeOk;
  }
  
  return v_Error_t;
}

PlatformError_t ME_Interrupt_Unmask_t(const InterruptHandle_t* i_InterruptHandle_pt)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(i_InterruptHandle_pt != NULL)
  {
    InterruptUnmask(i_InterruptHandle_pt->irqId_s32, i_InterruptHandle_pt->interruptId_s32);

    v_Error_t = e_PeOk;
  }
  
  return v_Error_t;
}

PlatformError_t ME_Interrupt_Wait_t(const InterruptHandle_t* i_InterruptHandle_pt)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if(i_InterruptHandle_pt != NULL)
  {
    InterruptWait (0, NULL);

    v_Error_t = e_PeOk;
  }
  
  return v_Error_t;
}

#endif // ME_PLATFORM_QNX
