/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------

/// @file ME_Interrupt.h
/// @brief Handle system interrupts
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ME_INTERRUPT_H_
#define ME_INTERRUPT_H_

#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif

PlatformError_t ME_Interrupt_Attach_t(InterruptHandle_t* i_InterruptHandle_pt, uint32_t i_InterruptId_u32);

PlatformError_t ME_Interrupt_Mask_t(const InterruptHandle_t* i_InterruptHandle_pt);

PlatformError_t ME_Interrupt_Unmask_t(const InterruptHandle_t* i_InterruptHandle_pt);

PlatformError_t ME_Interrupt_Wait_t(const InterruptHandle_t* i_InterruptHandle_pt);

#if defined(__cplusplus)
}; // extern C
#endif

#endif /* ME_INTERRUPT_H_ */
