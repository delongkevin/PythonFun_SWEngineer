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
#ifdef ME_PLATFORM_AUTOSAR

// stdlib header include
#include "platform/stdlib/ME_Interrupt.h"

PlatformError_t ME_Interrupt_Attach_t(InterruptHandle_t* i_InterruptHandle_t, uint32_t i_InterruptId_u32)
{
  PlatformError_t v_Error_t = e_PeInvalid;
  return v_Error_t;
}

PlatformError_t ME_Interrupt_Mask_t(const InterruptHandle_t* i_InterruptHandle_pt)
{
  return e_PeOk;
}

PlatformError_t ME_Interrupt_Unmask_t(const InterruptHandle_t* i_InterruptHandle_pt)
{
  return e_PeOk;
}

PlatformError_t ME_Interrupt_Wait_t(const InterruptHandle_t* i_InterruptHandle_pt)
{
  return e_PeOk;
}

#endif // ME_PLATFORM_QNX
