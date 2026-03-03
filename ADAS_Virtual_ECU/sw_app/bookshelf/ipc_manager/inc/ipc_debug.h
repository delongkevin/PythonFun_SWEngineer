/**
 * @file ipc_debug.h
 * @brief Header file for IPC debug feature
 *
 * @details This file contains API prototype for IPC debug feature
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2014.  Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status.  Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author ----  (---- @magna.com)
 */

#ifndef IPC_DEBUG_H_
#define IPC_DEBUG_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */


/* ===========================================================================
*
*   Defines
*
* ========================================================================= */

/* Debug Levels */
#define IPC_DEBUG_LEVEL_0   (0)     /* 0 -> No debug message */
#define IPC_DEBUG_LEVEL_1   (1)     /* 1 -> Critical debug messages (e.g: On error) */
#define IPC_DEBUG_LEVEL_2   (2)     /* 2 -> Major debug messages (e.g: if-else conditions) */
#define IPC_DEBUG_LEVEL_3   (3)     /* 3 -> Cosmetic debug messages (e.g: entry-exit of functions) */

/* Enable debug level */
#if defined(BUILD_MPU1_0)
#define IPC_DEBUG_LEVEL     (IPC_DEBUG_LEVEL_0)
#elif defined(BUILD_MCU2_0)
#define IPC_DEBUG_LEVEL     (IPC_DEBUG_LEVEL_0)
#else
#define IPC_DEBUG_LEVEL     (IPC_DEBUG_LEVEL_0)
#endif

#if defined(BUILD_MPU1_0)
#define DBG_MSG             printf
#else
#define DBG_MSG             appLogPrintf
#endif


#if(IPC_DEBUG_LEVEL == IPC_DEBUG_LEVEL_1)       /* 1 -> Critical debug messages (e.g: On error) */
#define   IPC_DBG_MSG_1(...)   DBG_MSG(__VA_ARGS__)
#define   IPC_DBG_MSG_2(...)
#define   IPC_DBG_MSG_3(...)
#elif(IPC_DEBUG_LEVEL == IPC_DEBUG_LEVEL_2)     /* 2 -> Major debug messages (e.g: if-else conditions) */
#define   IPC_DBG_MSG_1(...)   DBG_MSG(__VA_ARGS__)
#define   IPC_DBG_MSG_2(...)   DBG_MSG(__VA_ARGS__)
#define   IPC_DBG_MSG_3(...)
#elif(IPC_DEBUG_LEVEL == IPC_DEBUG_LEVEL_3)     /* 3 -> Cosmetic debug messages (e.g: entry-exit of functions) */
#define   IPC_DBG_MSG_1(...)   DBG_MSG(__VA_ARGS__)
#define   IPC_DBG_MSG_2(...)   DBG_MSG(__VA_ARGS__)
#define   IPC_DBG_MSG_3(...)   DBG_MSG(__VA_ARGS__)
#else                                           /* 0 -> No debug message */
#define   IPC_DBG_MSG_1(...)
#define   IPC_DBG_MSG_2(...)
#define   IPC_DBG_MSG_3(...)
#endif


/* ===========================================================================
*
*   Global data types
*
* ========================================================================= */


/* ========================================================================== */
/*                          External Dependencies                             */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


 /* === End Of Header File ================================================= */
#endif  /* #define IPC_DEBUG_H_ */
