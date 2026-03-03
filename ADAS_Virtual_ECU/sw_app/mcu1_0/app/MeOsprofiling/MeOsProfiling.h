/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @addtogroup     MeOsProfiling
 *  @file           MeOsProfiling.h
 *  @brief          OS Profiling
 *
 * This module implements profiling of Threads (Tasks and Os ISRs) by implementing
 * MICROSAR OS Timing Hooks.
 *
 * To use OS profiling, "MeOsProfiling_ASR.h" include header has to be specified
 * in the attribute "OsTimingHooksIncludeHeader" located in the "OsDebug" container
 * in DaVinci Configurator project.
 * When "MeOsProfiling_ASR.h" is not specified, this module is inactive (translation
 * unit is empty) and does not influence execution of system in any way.
 *
 * Intended way to use MeOsProfiling is to get statistic from task:
 *    MeOsProf_TickType MeasTime;
 *    MeOsProf_StatisticType *ProfCurrent;
 *    MeOsProf_StatisticType *IntLockProfCurrent;
 *    MeOsProf_StatisticType *ResLockProfCurrent;
 *    MeOsSlack_StatisticType *SlackCurrent;
 *    MeasTime = MeOsProfiling_GetStatistic(&ProfCurrent, &IntLockProfCurrent, &ResLockProfCurrent, &SlackCurrent, FALSE);
 *    if (0u != MeasTime)
 *    {
 *      USER CODE HERE TO LOG DATA
 *      MeOsProfiling_DeleteProfilingData(ProfCurrent, IntLockProfCurrent, ResLockProfCurrent, SlackCurrent);
 *    }
 * You can use already available function to log data over UART:
 *    MeOsProf_PrintOsThreadStat(ProfCurrent, IntLockProfCurrent, ResLockProfCurrent, MeasTime);
 *    MeOsSlack_PrintStatistic(SlackCurrent, EcuMon_ThreadSlackTimesConfig);
 *
 * For debug purposes it is possible to print profile log from context switch by
 * defining MEOSPROF_PRINT_FROM_OS to STD_ON. In this case MeOsProfiling_GetStatistic() will not return data.
 *
 * Enumerator Os_TraceThreadIdType in file Os_Types_Lcfg.h defines Thread Ids.
 *
 *  @author         Bernard Bosnjak
 *
 * ========================================================================= */

/**
 * @defgroup MeI2C MeI2c
 * @brief I2C master driver.
 *
 * This module implements I2C master drivers.
 * @{
 */

#ifndef MEOSPROFILING_H
#define MEOSPROFILING_H

#include <Std_Types.h>
#include "Os_Trace.h"

/* +++ Public Type definitions, Enumerations, Defines ++++++++++++++++++++++ */

/**
 * @brief Thread cyclicly values.
 *
 */
typedef struct s_MeOsProf_ThreadCycleMonType
{
  uint8 threadMs;
  Os_TraceThreadIdType threadId;
} MeOsProf_ThreadSlackTimeType;

/* +++ Public Variables, Constants ++++++++++++++++++++++++++++++++++++++++ */

/* +++ Public Macros ++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* +++ Public Function Prototypes +++++++++++++++++++++++++++++++++++++++++ */

/**
 * @brief Initialize Os Profiling.
 *
 * Must be called before OS initialization.
 */
void MeOsProf_Init(void);

#if defined(MEOSPROFILING_ASR_H)
/**
 * @brief Get Os Profiling measurement.
 *
 * @param ProfCurrent[out]        Pointer to pointer for os profiling data for all the tasks
 * @param IntLockProfCurrent[out] Pointer to pointer for os profiling data for all the interrupts
 * @param ResLockProfCurrent[out] Pointer to pointer for os profiling data for all Resources
 * @param SlackCurrent[out]       Pointer to pointer for os slack data
 * @param force[in]               Force measurement collection (ignore MEOSPROF_TIME_MEAS_PERIOD)
 * @return Duration of measurement [in ticks], 0 if data is not ready.
 */
MeOsProf_TickType MeOsProfiling_GetStatistic(MeOsProf_StatisticType **ProfCurrent,
                                             MeOsProf_StatisticType **IntLockProfCurrent,
                                             MeOsProf_StatisticType **ResLockProfCurrent,
                                             MeOsSlack_StatisticType **SlackCurrent,
                                             boolean force);

/**
 * @brief Release os profiling data acquired with MeOsProfiling_GetStatistic()
 *
 * @param ProfCurrent[in]        Pointer to os profiling data for all the tasks
 * @param IntLockProfCurrent[in] Pointer to os profiling data for all the interrupts
 * @param ResLockProfCurrent[in] Pointer to os profiling data for all Resources
 * @param SlackCurrent[in]       Pointer to os slack data
 */
void MeOsProfiling_DeleteProfilingData(MeOsProf_StatisticType *ProfCurrent,
                                       MeOsProf_StatisticType *IntLockProfCurrent,
                                       MeOsProf_StatisticType *ResLockProfCurrent,
                                       MeOsSlack_StatisticType *SlackCurrent);
#endif

#if defined(MEOSPROFILING_ASR_H) && (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT) && (STD_OFF == MEOSPROF_PRINT_FROM_OS)
/**
 * @brief Example how to print task measurement statistic.
 *
 * @param[in] ProfCurrent         Pointer to os profiling data for all the tasks
 * @param[in] IntLockProfCurrent  Pointer to os profiling data for all the interrupts
 * @param[in] ResLockProfCurrent  Pointer to os profiling data for all Resources
 * @param[in] MeasTime            Duration of measurement
 */
void MeOsProf_PrintOsThreadStat(const MeOsProf_StatisticType *ProfCurrent,
                                const MeOsProf_StatisticType *IntLockProfCurrent,
                                const MeOsProf_StatisticType *ResLockProfCurrent,
                                MeOsProf_TickType MeasTime);
#else
#define MeOsProf_PrintOsThreadStat(ProfCurrent, IntLockProfCurrent, ResLockProfCurrent, MeasTime)
#endif

#if defined(MEOSPROFILING_ASR_H) && (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT) && (STD_OFF == MEOSPROF_PRINT_FROM_OS)
/**
 * @brief Example how to print slack time measurement statistic.
 *
 * @param[in] SlackCurrent            Pointer to slack time measurement data (see MeOsSlack_GetStatistic)
 * @param[in] ThreadSlackTimesConfig  Pointer to array of OS_TRACE_THREADID_COUNT size with thread cyclicly values in miliseconds.
 */
void MeOsSlack_PrintStatistic(const MeOsSlack_StatisticType *SlackCurrent,
                              const MeOsProf_ThreadSlackTimeType *ThreadSlackTimesConfig);
#else
#define MeOsSlack_PrintStatistic(SlackCurrent, ThreadSlackTimesConfig)
#endif

#endif /* MEOSPROFILING_H */
/**@}*/
