/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------

/// @file PlatformAPI.h
/// @brief The header file to include for external components (like OSAL)
///        For POS, define ME_POS_32 or ME_POS_64 macro including the API
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ME_PLATFORM_API_H
#define ME_PLATFORM_API_H

#include "PlatformSpecs.h"
#include "PlatformHelper.h"
#include "stdlib/memory/PlatformMemory.h"
#include "stdlib/ME_Assert.h"
#include "stdlib/ME_File.h"
#include "stdlib/ME_Debugger.h"
#include "stdlib/ME_Directory.h"
#include "stdlib/ME_Semaphore.h"
#include "stdlib/ME_Condvar.h"
#include "stdlib/ME_Mutex.h"
#include "stdlib/ME_Thread.h"
#include "stdlib/ME_Time.h"
#include "stdlib/ME_String.h"
#include "stdlib/ME_Process.h"
#include "stdlib/ME_SharedMemory.h"
#include "stdlib/ME_Socket.h"
#include "stdlib/ME_IO.h"
#include "stdlib/ME_Interrupt.h"
#include "stdlib/ME_Atomic.h"

#include "stdlib/utils/ME_Profiler.h"
#include "stdlib/utils/ME_FileSystem.h"

// include c++ specific helpers
#ifdef __cplusplus
  #include "stdlib/utils/CppHelpers.h"
  #include "stdlib/utils/CppBridge.h"
  #include "stdlib/memory/PlatformStl.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

#if defined(__cplusplus)
}; // extern C
#endif





#endif // ME_PLATFORM_API_H
