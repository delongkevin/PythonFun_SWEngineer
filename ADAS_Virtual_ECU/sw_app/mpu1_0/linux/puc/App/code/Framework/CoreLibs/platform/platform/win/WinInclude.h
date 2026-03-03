//--------------------------------------------------------------------------
/// @file WinInclude.h
/// 
/// Just includes the windows.h header with an appropriate _WIN32_WINNT define and removes some nasty defines
/// Define OSAL_FULL_WIN_INCLUDE before including this header for full windows.h inclusion (otherwise WIN32_LEAN_AND_MEAN is used).
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------
  
#ifndef OSAL_WIN_INCLUDE_H
#define OSAL_WIN_INCLUDE_H

// Compile this file for windows only
#ifdef ME_PLATFORM_WIN

#ifndef _WIN32_WINNT
  #define _WIN32_WINNT _WIN32_WINNT_VISTA
#endif

#ifndef OSAL_FULL_WIN_INCLUDE
  #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN        // Do not include rarely used parts of the windows header
  #endif
#endif

#ifndef NOMINMAX
  #define NOMINMAX
#endif


#include <windows.h>

// remove some nasty defines
#undef max  // windef.h
#undef min  // windef.h


#endif // ME_PLATFORM_WIN

#endif // OSAL_WIN_INCLUDE_H
