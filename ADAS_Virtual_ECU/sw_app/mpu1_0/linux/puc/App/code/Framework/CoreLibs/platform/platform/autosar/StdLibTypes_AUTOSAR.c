/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------

/// @file StdLibTypes_AUTOSAR.h
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

#include "platform/stdlib/StdLibTypes.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_AUTOSAR

#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Assert.h"

#include <string.h>
#include <errno.h>

#define EOK       0

// convert Qnx state to our Platform error state. Add more error states here for QNX!
// see documentation on errno: http://www.qnx.com/developers/docs/6.5.0/index.jsp?topic=%2Fcom.qnx.doc.neutrino_lib_ref%2Fe%2Ferrno.html
PlatformError_t ME_GetPlatformError_t(sint32_t i_ErrorState_s32)
{
  PlatformError_t v_State_e;

  if(-1 == i_ErrorState_s32)
  {
    i_ErrorState_s32 = errno;
    errno = EOK;
  }

  switch (i_ErrorState_s32)
  {
    case EOK:       { v_State_e = e_PeOk;       } break;
    case ERANGE:    { v_State_e = e_PeNoEntry;  } break;
    case ESIGNUM:
    case EILSEQ:
    case EINVAL:    { v_State_e = e_PeInvalid;  } break;
    case EDOM:      { v_State_e = e_PeFault;    } break;
    case ENOMEM:    { v_State_e = e_PeNoMemory; } break;
    default:        { v_State_e = e_PeUnmapped; } break;
  }

  if (e_PeOk != v_State_e)
  {
    ME_Debugger_F_Printf_v("Error %d: %s\n", i_ErrorState_s32, strerror(i_ErrorState_s32));
  }

  Assert(v_State_e != e_PeUnmapped);

  return v_State_e;
}

#endif // ME_PLATFORM_AUTOSAR // PRQA S 862 // this define decides which platform is defined
