/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

/*
 * Debugger.h
 *
 *  Created on: 13.11.2017
 *      Author: SAI_MEnge
 */

#ifndef ME_DEBUGGER_H
#define ME_DEBUGGER_H

#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif

#ifdef ME_PLATFORM_QNX
#define USE_SLOG2_FOR_OUTPUT
#endif

// --------------------------------------------------------------------------
/// Activates system's process debugger for the calling process.
// --------------------------------------------------------------------------
void ME_Debugger_F_BreakPoint_v(void);

// --------------------------------------------------------------------------
/// A variadic function to \c printf a formatted string.
///
/// A variable length of arguments to be processed along with the format string can be provided.
///
/// @param[in] i_Format_pc The format string
// --------------------------------------------------------------------------
void ME_Debugger_F_Printf_v(const char_t* i_Format_pc, ...);

// --------------------------------------------------------------------------
/// Gets the average CPU usage as float
///
/// @param[in] b_Percentage_pf32 The average cpu usage in percent
// --------------------------------------------------------------------------
void ME_Debugger_F_GetAverageCpuUsage_v(float32_t* b_Percentage_pf32);

#ifdef ME_PLATFORM_QNX
#include <sys/syspage.h>
#include <sys/neutrino.h>
#include <inttypes.h>

static inline uint32_t __get_time_usec(void)
{
    return (uint32_t)((ClockCycles() * 1000000ULL) / SYSPAGE_ENTRY(qtime)->cycles_per_sec);
}
#endif

#if defined(__cplusplus)
}; // extern C
#endif

#endif /* ME_DEBUGGER_H */
