#include "platform/stdlib/StdLibTypes.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Assert.h"

#include <string.h>

// convert Qnx state to our Platform error state. Add more error states here for QNX!
// see documentation on errno: http://www.qnx.com/developers/docs/6.5.0/index.jsp?topic=%2Fcom.qnx.doc.neutrino_lib_ref%2Fe%2Ferrno.html
PlatformError_t ME_GetPlatformError_t(sint32_t i_ErrorState_s32)
{
  PlatformError_t v_State_e;

  if(-1 == i_ErrorState_s32)
  {
    i_ErrorState_s32 = errno;
    errno = 0;
  }

  switch (i_ErrorState_s32)
  {
    case EOK:       { v_State_e = e_PeOk;       } break;
    case EPERM:     { v_State_e = e_PeNoPermission;       } break;
    case ENOENT:    { v_State_e = e_PeNoEntry;  } break;
    case ESRCH:     { v_State_e = e_PeNoSuchProcess;  } break;
    case EAGAIN:    { v_State_e = e_PeAgain;    } break;
    case EBUSY:     { v_State_e = e_PeBusy;     } break;
    case EINVAL:    { v_State_e = e_PeInvalid;  } break;
    case EDEADLK:   { v_State_e = e_PeDeadLock; } break;
    case EFAULT:    { v_State_e = e_PeFault;    } break;
    case ETIMEDOUT: { v_State_e = e_PeTimedOut; } break;
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

#endif // ME_PLATFORM_LINUX // PRQA S 862 // this define decides which platform is defined
