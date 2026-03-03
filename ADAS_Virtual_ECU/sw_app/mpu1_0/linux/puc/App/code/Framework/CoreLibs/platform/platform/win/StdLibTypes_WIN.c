//--------------------------------------------------------------------------
/// @file StdLibTypes_WIN.c
/// @brief Implements the getPlatformError function declared in StdLibTypes.h
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

#include "platform/PlatformDefines.h"

// Compile this file for WIN only!
#ifdef ME_PLATFORM_WIN

#include "platform/stdlib/StdLibTypes.h"
#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Assert.h"

#include <errno.h>
#include <string.h>

#define EOK 0 // TODO

// convert win state to our Platform error state. Add more error states here for QNX!
// see documentation on errno
PlatformError_t ME_GetPlatformError_t(sint32_t i_ErrorState_s32)
{
  PlatformError_t v_Error_t;

  if(-1 == i_ErrorState_s32)
  {
    i_ErrorState_s32 = errno;
    errno = EOK;
  }


  switch (i_ErrorState_s32)
  {
    case EOK:       { v_Error_t = e_PeOk;       } break;
    case ENOENT:    { v_Error_t = e_PeNoEntry;  } break;
    case EAGAIN:    { v_Error_t = e_PeAgain;    } break;
    case EBUSY:     { v_Error_t = e_PeBusy;     } break;
    case EINVAL:    { v_Error_t = e_PeInvalid;  } break;
    case EDEADLK:   { v_Error_t = e_PeDeadLock; } break;
    case EFAULT:    { v_Error_t = e_PeFault;    } break;
    case ETIMEDOUT: { v_Error_t = e_PeTimedOut; } break;
    case ENOMEM:    { v_Error_t = e_PeNoMemory; } break;
    default:        { v_Error_t = e_PeUnmapped; } break;
  }

  if (e_PeOk != v_Error_t)
  {
    char_t v_Buffer[128];
    (void)strerror_s(v_Buffer, sizeof(v_Buffer), i_ErrorState_s32);
    ME_Debugger_F_Printf_v("Error %d: %s\n", i_ErrorState_s32, v_Buffer);

    //ME_Debugger_F_Printf_v("Error %d: %s\n", i_ErrorState_s32, strerror(i_ErrorState_s32)); // depricitated
  }


  Assert(v_Error_t != e_PeUnmapped);
  return v_Error_t;
}

#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
