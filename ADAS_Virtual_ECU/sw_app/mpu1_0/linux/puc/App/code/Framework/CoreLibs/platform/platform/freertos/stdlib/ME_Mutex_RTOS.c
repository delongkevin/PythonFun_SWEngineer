/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */
//--------------------------------------------------------------------------

/// @file ME_Mutex_AUTOSAR.c
/// @brief Autosar implementation for standard-library Mutex
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

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

// stdlib header include
#include "platform/stdlib/ME_Mutex.h"

PlatformError_t ME_Mutex_Init_t(Mutex_s* b_Mutex_po, bool_t i_Shared_b)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Mutex_Lock_t(Mutex_s* i_Mutex_po)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Mutex_TryLock_t(Mutex_s* i_Mutex_po)
{
  PlatformError_t v_Error_t;

  return v_Error_t;
}

PlatformError_t ME_Mutex_UnLock_t(Mutex_s* i_Mutex_po)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Mutex_Destroy_t(Mutex_s* b_Mutex_po)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined
