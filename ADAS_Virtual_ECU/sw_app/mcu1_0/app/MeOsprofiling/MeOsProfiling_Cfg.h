/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @addtogroup     MeOsProfiling
 *  @file           MeOsProfiling_Cfg.h
 *  @brief          OS Profiling Configuration
 *
 *  @author         Bernard Bosnjak
 *
 * ========================================================================= */

#ifndef MEOSPROFILING_CFG_H
#define MEOSPROFILING_CFG_H

/**
 * @brief Enable Task/Interrupts load measurement
 *
 */
#define MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT STD_ON

/**
 * @brief Realtime min slack time callback (ONLY FOR DEBUGGING)
 *
 * Define function to be called every time new min slack time value is measured.
 *
 */
//#define MEOSPROF_SLACK_REALTIME_CALLBACK EcuMon_SlackRealtimeCallback

/**
 * @brief Enable Interrupt lock measurement
 *
 * Can be enabled only together with MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT
 *
 */
#define MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT  (STD_OFF & MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)

/**
 * @brief Enable Resource lock measurement
 *
 * Can be enabled only together with MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT
 *
 */
#define MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT  (STD_OFF & MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)

/**
 * @brief Define if Os profile print is executed from OS.
 *
 * If enabled, NOT RECOMMENDED, Os profile print is executed from task scheduler.
 *
 */
#define MEOSPROF_PRINT_FROM_OS STD_OFF

/**
 * @brief Enable slack time measurement for Basic tasks
 *
 */
#define MEOSSLACK_MEASURE_BASIC_TASKS STD_OFF
/**
 * @brief Enable slack time measurement for Extended tasks
 *
 */
#define MEOSSLACK_MEASURE_EXTENDED_TASKS STD_OFF
/**
 * @brief Enable slack time measurement for interrupts
 *
 */
#define MEOSSLACK_MEASURE_IRQS STD_OFF

/**
 * @brief Enable Gliwa T1 integration
 *
 * As T1 and MeOsProfiling use same OS_VTH_* macros, MeOsProfiling integration will call T1 macros.
 * In "T1_Microsar.h" file rename "OS_VTH_*" macros to "ME__T1_*".
 *
 */
#define MEOSPROF_GLIWA_T1_INTEGRATION STD_OFF

/**
 * @brief Enable MeTrace integration
 *
 */
#define MEOSPROF_METRACE_INTEGRATION STD_OFF

/**
 * @brief Measurement time.
 *
 */
#define MEOSPROF_TIME_MEAS_PERIOD MEOSPROF_MS_2_TICK(500u)      /*CPU load calculates for every 0.5 sec */


/*********************************/
/* DO NOT CHANGE FOLLOWING LINES */
/*********************************/
#if (STD_ON == MEOSSLACK_MEASURE_BASIC_TASKS) || (STD_ON == MEOSSLACK_MEASURE_EXTENDED_TASKS) || (STD_ON == MEOSSLACK_MEASURE_IRQS)
#define MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT STD_ON
#else
#define MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT STD_OFF
#endif

#endif /* MEOSPROFILING_CFG_H */

/** @file
 *****************************************************************************
  @par MISRA deviations
 *****************************************************************************

  @misra MSRD_3453: MISRA C:2012 Dir-4.9; A function could probably be used instead of this function-like macro.
    - Reason:     Tick to time conversion configurations.
    - Risk:       No risk.
    - Prevention: Not needed.

 */
