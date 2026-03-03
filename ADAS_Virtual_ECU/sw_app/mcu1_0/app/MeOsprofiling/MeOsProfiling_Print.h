/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @addtogroup     MeOsProfiling
 *  @file           MeOsProfiling_Print.h
 *  @brief          Target dependant OS Profiling printing
 *
 * Target dependent printing configuration.
 * Requeued interfaces and defines:
 *    Enable printing:
 *      MEOSPROF_PRINTF
 *    printf like function to print from from OS scheduler:
 *      MeOsProf_os_printf()
 *    printf like function to print from from Task:
 *      MeOsProf_printf()
 *
 * OS profiling UART print for LIDAR.
 *
 *  @author         Bernard Bosnjak
 *
 * ========================================================================= */

#ifndef MEOSPROFILING_PRINT_H
#define MEOSPROFILING_PRINT_H

#if HAVE_PDEBUG
#include "pdebug.h"

#define MEOSPROF_PRINTF STD_ON

#if (STD_ON == MEOSPROF_PRINT_FROM_OS)
#include "posprint.h"
/**
 * @brief MeOsProf_os_printf() shall be capable to print from OS scheduler,
 * It is running in priviledged mode, and interrupts are most likely disabled (depends on OS implementation).
 *
 */
#define MeOsProf_os_printf(...)   os_print(__VA_ARGS__)
#endif
/**
 * @brief MeOsProf_printf() is running from Task.
 *
 */
#define MeOsProf_printf(...)      dprintf(__VA_ARGS__)

#else
#define MEOSPROF_PRINTF STD_OFF
#endif

#endif /* MEOSPROFILING_PRINT_H */
