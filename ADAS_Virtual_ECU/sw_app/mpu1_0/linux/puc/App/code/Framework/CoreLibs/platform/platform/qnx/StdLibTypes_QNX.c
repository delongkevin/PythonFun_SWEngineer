//--------------------------------------------------------------------------
/// @file StdLibTypes_QNX.h
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

// compile this file for QNX only
#ifdef ME_PLATFORM_QNX

#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Assert.h"

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
    case EOK:             { v_State_e = e_PeOk;                 } break;
    case EPERM:           { v_State_e = e_PeNoPermission;       } break;
    case ENOENT:          { v_State_e = e_PeNoEntry;            } break;
    case ESRCH:           { v_State_e = e_PeNoSuchProcess;      } break;
    case ENXIO:           { v_State_e = e_PeNoSuchDevice;       } break;
    case EBADF:           { v_State_e = e_PeBadFileDescriptor;  } break;
    case EAGAIN:          { v_State_e = e_PeAgain;              } break;
    case EBUSY:           { v_State_e = e_PeBusy;               } break;
    case EINVAL:          { v_State_e = e_PeInvalid;            } break;
    case EDEADLK:         { v_State_e = e_PeDeadLock;           } break;
    case EFAULT:          { v_State_e = e_PeFault;              } break;
    case ETIMEDOUT:       { v_State_e = e_PeTimedOut;           } break;
    case ENOMEM:          { v_State_e = e_PeNoMemory;           } break;
    case ENOTSUP:         { v_State_e = e_PeNotSupported;       } break;
    case ERANGE:          { v_State_e = e_PeResultTooLarge;     } break;
    case EADDRNOTAVAIL:   { v_State_e = e_PeAddrNotAvailable;   } break;
    default:              { v_State_e = e_PeUnmapped;           } break;
  }

  if(v_State_e != e_PeOk)
  {
    ME_Debugger_F_Printf_v("ME_GetPlatformError_t() - Error [%d]\n", i_ErrorState_s32);
  }

  AssertMsg(v_State_e != e_PeUnmapped, "error = %d\n", errno);

  return v_State_e;
}

#endif // ME_PLATFORM_QNX
