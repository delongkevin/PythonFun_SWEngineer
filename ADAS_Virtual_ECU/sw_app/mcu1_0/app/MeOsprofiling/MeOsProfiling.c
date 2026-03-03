/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/*@addtogroup     MeOsProfiling
 *  @file           MeOsProfiling.c
 *  @brief          OS Profiling
 *
 *  @author         Bernard Bosnjak
 *
 * ========================================================================= */

#include "MeOsProfiling.h"

#ifdef MEOSPROFILING_ASR_H

#include <string.h>
#include "MeOsProfiling_Tick.h"
#include "MeOsProfiling_Print.h"

/* --- Private Type definitions, Enumerations, Defines -------------------- */

#ifndef UNUSED
#define UNUSED(x) (void)(x)
#endif

/* --- Private Variables, Constants --------------------------------------- */

#define MEOSPROF_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#include "MeOsProfiling_MemMap.h" /* PRQA S 5087 */

#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
static uint8 MeOsProf_StatSlot;
static MeOsProf_StatisticType MeOsProf_Statistic[MEOSPROFILING_DATA_SLOTS][OS_TRACE_THREADID_COUNT];
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
static MeOsProf_StatisticType MeOsProf_StatisticIntLock[MEOSPROFILING_DATA_SLOTS][MEOS_TRACE_INTLOCK_COUNT];
#endif
#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
static MeOsProf_StatisticType MeOsProf_StatisticResLock[MEOSPROFILING_DATA_SLOTS][OS_RESOURCEID_COUNT];
#endif
#endif

#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
static uint8 MeOsSlack_StatSlot;
static MeOsSlack_StatisticType MeOsSlack_Statistic[MEOSPROFILING_DATA_SLOTS][OS_TRACE_THREADID_COUNT];
#endif

/* +++ Public Variables, Constants ++++++++++++++++++++++++++++++++++++++++ */

#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT) || (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
MeOsProf_TickType MeOsProf_MeasStartTime;
#endif

#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
MeOsProf_WorkType MeOsProf_Work[OS_TRACE_THREADID_COUNT];
MeOsProf_TickType MeOsProf_LastProfTick;
MeOsProf_StatisticType *MeOsProf_StatPtr;
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
MeOsProf_WorkType MeOsProf_WorkIntLock[MEOS_TRACE_INTLOCK_COUNT];
MeOsProf_StatisticType *MeOsProf_StatPtrIntLock;
#endif
#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
MeOsProf_WorkType MeOsProf_WorkResLock[OS_RESOURCEID_COUNT];
MeOsProf_StatisticType *MeOsProf_StatPtrResLock;
#endif
#endif

#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
MeOsSlack_WorkType MeOsSlack_Work[OS_TRACE_THREADID_COUNT];
MeOsSlack_StatisticType *MeOsSlack_StatPtr;
#endif

#define MEOSPROF_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#include "MeOsProfiling_MemMap.h" /* PRQA S 5087 */

/* --- Private Macros ----------------------------------------------------- */

/* --- Private Function Prototypes ---------------------------------------- */

#define MEOSPROF_START_SEC_CODE
#include "MeOsProfiling_MemMap.h" /* PRQA S 5087 */

#if (STD_ON == MEOSPROF_PRINTF) && (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
#if (STD_ON == MEOSPROF_PRINT_FROM_OS)

/**********************************************************************************************************************
 * Traceability to SDD: DD-ID: {ACD5CE0D-8174-4566-9DE7-4F25538DB508}
 *********************************************************************************************************************/

LOCAL_INLINE void MeOsProf_LogThreadSys(const MeOsProf_StatisticType *ptr, MeOsProf_TickType MeasTimeDiv1000, sint32 i)
{
  uint32 rate = ptr->ticks / MeasTimeDiv1000;
  MeOsProf_os_printf("  %2d | %4ld | %8ld | %8ld | %11ld\n", i, rate, MEOSPROF_TICK_2_US(ptr->max),
           ptr->activations, MEOSPROF_TICK_2_US(ptr->ticks));
}
#else
/**********************************************************************************************************************
 * Traceability to SDD: DD-ID: {249BF6B1-C127-4b0c-9DC1-2C35066B67FC}
 *********************************************************************************************************************/

LOCAL_INLINE void MeOsProf_LogThread(const MeOsProf_StatisticType *ptr, MeOsProf_TickType MeasTimeDiv1000, sint32 i)
{
  uint32 rate = ptr->ticks / MeasTimeDiv1000;
  MeOsProf_printf("CPULOAD  %2d | %4ld | %8ld | %8ld | %11ld\n", i, rate, MEOSPROF_TICK_2_US(ptr->max),
          ptr->activations, MEOSPROF_TICK_2_US(ptr->ticks));
}
#endif
#endif

/* +++ Public Function Definitions ++++++++++++++++++++++++++++++++++++++++ */

/**********************************************************************************************************************
 * Traceability to SDD: DD-ID: {A1EA9569-F5F1-4dcd-A5E3-941CAF5CCB01}
 *********************************************************************************************************************/

void MeOsProf_Init(void)
{
#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
  _Static_assert(MEOSPROF_TIME_MEAS_PERIOD < 0xFFFFFFFFu, "MEOSPROF_TIME_MEAS_PERIOD too big");

  MeOsProf_MeasStartTime = 0u;
  MeOsProf_LastProfTick = 0u;
  MeOsProf_StatSlot = 0u;
  MeOsProf_StatPtr = &MeOsProf_Statistic[0][0];
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
  MeOsProf_StatPtrIntLock = &MeOsProf_StatisticIntLock[0][0];
#endif
#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
  MeOsProf_StatPtrResLock = &MeOsProf_StatisticResLock[0][0];
#endif
#endif
#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
  MeOsSlack_StatSlot = 0;
  MeOsSlack_StatPtr = &MeOsSlack_Statistic[0][0];
  (void)memset(MeOsSlack_Statistic, 0xFF, sizeof(MeOsSlack_Statistic)); /* PRQA S 0315 */
#endif

#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT) || (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
  MeOsProf_InitTick();
#endif
}

#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
#if (STD_ON == MEOSPROF_PRINT_FROM_OS)

/**********************************************************************************************************************
 * Traceability to SDD: DD-ID: {20245D84-2254-423b-94BB-7B2B49699834}
 *********************************************************************************************************************/

void MeOsProf_PrintOsThreadStatSys(MeOsProf_TickType MeasTime)
{
#if (STD_ON == MEOSPROF_PRINTF)
  sint32 i;
  MeOsProf_TickType MeasTimeDiv1000 = MeasTime / 1000u;

  MeOsProf_StatisticType *ProfCurrent = MeOsProf_StatPtr;
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
  MeOsProf_StatisticType *IntLockProfCurrent = MeOsProf_StatPtrIntLock;
#endif
#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
  MeOsProf_StatisticType *ResLockProfCurrent = MeOsProf_StatPtrResLock;
#endif
  MeOsProf_os_printf("CPULOAD t[us]=%-15ld\n", MEOSPROF_TICK_2_US(MeasTime));
  MeOsProf_os_printf("  Id |  ppm |    max t |     act. |     total t\n");
  MeOsProf_os_printf("-----------------------------------------------\n");

  for (i = 0; i < (sint32)OS_TRACE_THREADID_COUNT; i++)
  {
    if (0u != ProfCurrent[i].ticks)
    {
      MeOsProf_LogThreadSys(&ProfCurrent[i], MeasTimeDiv1000, i);
    }
  }
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
  MeOsProf_os_printf("INT LOCK --------------------------------------\n");
  for (i = 0; i < (sint32)MEOS_TRACE_INTLOCK_COUNT; i++)
  {
    if (0u != IntLockProfCurrent[i].ticks)
    {
      MeOsProf_LogThreadSys(&IntLockProfCurrent[i], MeasTimeDiv1000, i);
    }
  }
#endif
#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
  MeOsProf_os_printf("RES LOCK --------------------------------------\n");
  for (i = 0; i < (sint32)OS_RESOURCEID_COUNT; i++)
  {
    if (0u != ResLockProfCurrent[i].ticks)
    {
      MeOsProf_LogThreadSys(&ResLockProfCurrent[i], MeasTimeDiv1000, i);
    }
  }
#endif
  (void)memset(ProfCurrent, 0, sizeof(MeOsProf_Statistic[0]));
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
  (void)memset(IntLockProfCurrent, 0, sizeof(MeOsProf_StatisticIntLock[0]));
#endif
#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
  (void)memset(ResLockProfCurrent, 0, sizeof(MeOsProf_StatisticResLock[0]));
#endif
#else
  UNUSED(MeasTime);
#endif
}
#else

/**********************************************************************************************************************
 * Traceability to SDD: DD-ID: {68E1234E-7435-4177-8937-BE0082363710}
 *********************************************************************************************************************/

void MeOsProf_PrintOsThreadStat(const MeOsProf_StatisticType *ProfCurrent,
                                const MeOsProf_StatisticType *IntLockProfCurrent,
                                const MeOsProf_StatisticType *ResLockProfCurrent,
                                MeOsProf_TickType MeasTime)
{
#if (STD_ON == MEOSPROF_PRINTF)
  if (NULL_PTR != ProfCurrent)
  {
    sint32 i;
    MeOsProf_TickType MeasTimeDiv1000 = MeasTime / 1000u;

    MeOsProf_printf("CPULOAD t[us]=%-15ld\n", MEOSPROF_TICK_2_US(MeasTime));
    MeOsProf_printf("CPULOAD  Id | pmil |    max t |     act. |     total t\n");
    MeOsProf_printf("CPULOAD ----------------------------------------------\n");

    for (i = 0; i < (sint32)OS_TRACE_THREADID_COUNT; i++)
    {
      if (0u != ProfCurrent[i].ticks)
      {
        MeOsProf_LogThread(&ProfCurrent[i], MeasTimeDiv1000, i);
      }
    }
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
    MeOsProf_printf("CPULOAD INT LOCK -------------------------------------\n");
    for (i = 0; i < (sint32)MEOS_TRACE_INTLOCK_COUNT; i++)
    {
      if (0u != IntLockProfCurrent[i].ticks)
      {
        MeOsProf_LogThread(&IntLockProfCurrent[i], MeasTimeDiv1000, i);
      }
    }
#else
  UNUSED(IntLockProfCurrent);
#endif
#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
    MeOsProf_printf("CPULOAD RES LOCK -------------------------------------\n");
    for (i = 0; i < (sint32)OS_RESOURCEID_COUNT; i++)
    {
      if (0u != ResLockProfCurrent[i].ticks)
      {
        MeOsProf_LogThread(&ResLockProfCurrent[i], MeasTimeDiv1000, i);
      }
    }
#else
  UNUSED(ResLockProfCurrent);
#endif
  }
#else
  UNUSED(ProfCurrent);
  UNUSED(IntLockProfCurrent);
  UNUSED(ResLockProfCurrent);
  UNUSED(MeasTime);
#endif
}

#endif
#endif /* MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT */

/**********************************************************************************************************************
 * Traceability to SDD: DD-ID: {148D25BC-91DE-4e6d-B949-EB5E7531A30D}
 *********************************************************************************************************************/

MeOsProf_TickType MeOsProfiling_GetStatistic(MeOsProf_StatisticType **ProfCurrent,
                                             MeOsProf_StatisticType **IntLockProfCurrent,
                                             MeOsProf_StatisticType **ResLockProfCurrent,
                                             MeOsSlack_StatisticType **SlackCurrent,
                                             boolean force)
{
  MeOsProf_TickType MeasTimeResult = 0u;

#if (STD_OFF == MEOSPROF_PRINT_FROM_OS) && ((STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT) || (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT))
  MeOsProf_TickType MeasTime;
  MeOsProf_TickType TimeNow;

  SuspendAllInterrupts();
  TimeNow = MeOsProf_GetTick();
  MeasTime = MeOsProf_GetTickDiff(TimeNow, MeOsProf_MeasStartTime);
  if ((MeasTime >= (MeOsProf_TickType)MEOSPROF_TIME_MEAS_PERIOD) || (force != (boolean)FALSE))
  {
    MeasTimeResult = MeasTime;
    MeOsProf_MeasStartTime = TimeNow;
#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
    MeOsProf_LastProfTick = TimeNow;
    *ProfCurrent = MeOsProf_StatPtr;
    MeOsProf_StatSlot = (MeOsProf_StatSlot + (uint8)1u) % (uint8)MEOSPROFILING_DATA_SLOTS;
    MeOsProf_StatPtr = &MeOsProf_Statistic[MeOsProf_StatSlot][0];
#else
    *ProfCurrent = NULL_PTR;
#endif
#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
    *SlackCurrent = MeOsSlack_StatPtr;
    MeOsSlack_StatSlot = (MeOsSlack_StatSlot + 1u) % MEOSPROFILING_DATA_SLOTS;
    MeOsSlack_StatPtr = &MeOsSlack_Statistic[MeOsSlack_StatSlot][0];
#else
    *SlackCurrent = NULL_PTR;
#endif
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
    *IntLockProfCurrent = MeOsProf_StatPtrIntLock;
    MeOsProf_StatPtrIntLock = &MeOsProf_StatisticIntLock[MeOsProf_StatSlot][0];
#else
    *IntLockProfCurrent = NULL_PTR;
#endif
#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
    *ResLockProfCurrent = MeOsProf_StatPtrResLock;
    MeOsProf_StatPtrResLock = &MeOsProf_StatisticResLock[MeOsProf_StatSlot][0];
#else
    *ResLockProfCurrent = NULL_PTR;
#endif
  }
  else
  {
	  /* Do Nothing */
  }
  ResumeAllInterrupts();
#endif

  return MeasTimeResult;
}

/**********************************************************************************************************************
 * Traceability to SDD: DD-ID: {EAA33A17-579B-4335-ABCA-9604059E8BE2}
 *********************************************************************************************************************/

void MeOsProfiling_DeleteProfilingData(MeOsProf_StatisticType *ProfCurrent,
                                       MeOsProf_StatisticType *IntLockProfCurrent,
                                       MeOsProf_StatisticType *ResLockProfCurrent,
                                       MeOsSlack_StatisticType *SlackCurrent)
{
#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
  (void)memset(ProfCurrent, 0, sizeof(MeOsProf_Statistic[0])); /* PRQA S 0315 */
#else
  UNUSED(ProfCurrent);
#endif
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
  (void)memset(IntLockProfCurrent, 0, sizeof(MeOsProf_StatisticIntLock[0])); /* PRQA S 0315 */
#else
  UNUSED(IntLockProfCurrent);
#endif
#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
  (void)memset(ResLockProfCurrent, 0, sizeof(MeOsProf_StatisticResLock[0])); /* PRQA S 0315 */
#else
  UNUSED(ResLockProfCurrent);
#endif
#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
  (void)memset(SlackCurrent, 0xFF, sizeof(MeOsSlack_Statistic[0])); /* PRQA S 0315 */
#else
  UNUSED(SlackCurrent);
#endif
}

#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT) && (STD_OFF == MEOSPROF_PRINT_FROM_OS)

#if (STD_ON == MEOSPROF_PRINTF)
/**********************************************************************************************************************
 * Traceability to SDD: DD-ID: {E1E19BB3-9EAB-4f47-9391-2DC636A01DD4}
 *********************************************************************************************************************/

LOCAL_INLINE void MeOsSlack_LogThread(MeOsProf_TickType SlackTicks, sint32 i, MeOsProf_TickType CycleTime_Us)
{
  if (0u == CycleTime_Us)
  {
#if 0 /* Enable to print slack time for thread without cycle time. */
    MeOsProf_printf("  %2d |  -- | %8ld\n", i, MEOSPROF_TICK_2_US(SlackTicks));
#endif
  }
  else if (MEOSPROF_TICKTYPE_MAX == SlackTicks)
  {
    MeOsProf_printf("CPUSLCK  %2d |  -- |       -- \n", i);
  }
  else
  {
    uint8_least rate = (MEOSPROF_TICK_2_US(SlackTicks) * 100u) / CycleTime_Us;
    MeOsProf_printf("CPUSLCK  %2d | %3ld | %8ld\n", i, rate, MEOSPROF_TICK_2_US(SlackTicks));
  }
}
#endif

/**********************************************************************************************************************
 * Traceability to SDD: DD-ID: {9844812C-8B23-4bed-AB93-9B2EFC95875C}
 *********************************************************************************************************************/

void MeOsSlack_PrintStatistic(const MeOsSlack_StatisticType *SlackCurrent, const MeOsProf_ThreadSlackTimeType *ThreadSlackTimesConfig)
{
#if (STD_ON == MEOSPROF_PRINTF)
  const MeOsProf_ThreadSlackTimeType *pThreadSlackTime = ThreadSlackTimesConfig;

  MeOsProf_printf("CPUSLCK SLACKTIME t[us]\n");
  MeOsProf_printf("CPUSLCK  Id |   %% |    min t\n");
  MeOsProf_printf("CPUSLCK --------------------\n");

  while (OS_TRACE_INVALID_THREAD != pThreadSlackTime->threadId)
  {
    MeOsSlack_LogThread(SlackCurrent[pThreadSlackTime->threadId].min, (sint32)pThreadSlackTime->threadId, 1000u * (MeOsProf_TickType)pThreadSlackTime->threadMs);
    pThreadSlackTime++;
  }
#else
  UNUSED(SlackCurrent);
  UNUSED(ThreadSlackTimesConfig);
#endif
}
#endif

/* --- Private Function Definitions --------------------------------------- */

#define MEOSPROF_STOP_SEC_CODE
#include "MeOsProfiling_MemMap.h" /* PRQA S 5087 */

#endif

/* === End Of Source File ================================================= */
