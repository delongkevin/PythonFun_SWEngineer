/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @addtogroup     MeOsProfiling
 *  @file           MeOsProfiling_ASR.h
 *  @brief          OS Profiling Vector AUTOSAR include
 *
 * This include header has to be specified in the attribute "OsTimingHooksIncludeHeader"
 * located in the "OsDebug" container in DaVinci Configurator project.
 *
 *  @author         Bernard Bosnjak
 *
 * ========================================================================= */

/* PRQA S 3453 EOF */ /* MSRD_3453 */

#ifndef MEOSPROFILING_ASR_H
#define MEOSPROFILING_ASR_H

#include "Os.h"
#include "MeOsProfiling_Cfg.h"
#include "MeOsProfiling_Tick.h"

#if (STD_ON == MEOSPROF_GLIWA_T1_INTEGRATION)
#include "T1_Microsar.h"
#endif
#if (STD_ON == MEOSPROF_METRACE_INTEGRATION)
#include "MeTrace_Vth.h"
#endif

#ifdef MEOSPROF_SLACK_REALTIME_CALLBACK
void MEOSPROF_SLACK_REALTIME_CALLBACK(int TaskId, MeOsProf_TickType SlackTimeMin);
#endif

/* +++ Public Type definitions, Enumerations, Defines ++++++++++++++++++++++ */

#define MEOSPROFILING_DATA_SLOTS  2u

#define MEOS_TRACE_CAT2INTERRUPTS 0u
#define MEOS_TRACE_ALLINTERRUPTS  1u
#define MEOS_TRACE_INTLOCK_COUNT  2u
#define MEOS_IntLockId_2_MeIntLockId(IntLockId)  ((IntLockId) - 1)

typedef struct MeOsProf_StatisticType_tag
{
  MeOsProf_TickType ticks; /* Time in nr. ticks. */
  MeOsProf_TickType max;   /* Maximum execution is time in one activation. */
  uint32 activations;      /* Nr. activations. */
} MeOsProf_StatisticType;

#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
typedef struct MeOsProf_WorkType_tag
{
  MeOsProf_TickType start;
} MeOsProf_WorkType;
#endif

typedef struct MeOsSlack_StatisticType_tag
{
  uint32 min;
} MeOsSlack_StatisticType;

#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
typedef struct MeOsSlack_WorkType_tag
{
  MeOsProf_TickType stop;
} MeOsSlack_WorkType;
#endif

/* +++ Public Variables, Constants ++++++++++++++++++++++++++++++++++++++++ */

#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT) || (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
extern MeOsProf_TickType MeOsProf_MeasStartTime;
#endif

#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
extern MeOsProf_TickType MeOsProf_LastProfTick;
extern MeOsProf_StatisticType *MeOsProf_StatPtr;
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
extern MeOsProf_StatisticType *MeOsProf_StatPtrIntLock;
#endif
#if  (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
extern MeOsProf_StatisticType *MeOsProf_StatPtrResLock;
#endif
extern MeOsProf_WorkType MeOsProf_Work[OS_TRACE_THREADID_COUNT];
#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
extern MeOsProf_WorkType MeOsProf_WorkIntLock[MEOS_TRACE_INTLOCK_COUNT];
#endif
#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
extern MeOsProf_WorkType MeOsProf_WorkResLock[OS_RESOURCEID_COUNT];
#endif
#endif

#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
extern MeOsSlack_StatisticType *MeOsSlack_StatPtr;
extern MeOsSlack_WorkType MeOsSlack_Work[OS_TRACE_THREADID_COUNT];
#endif

/* +++ Public Macros ++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* PRQA S 3614 NO_UNDEF */ /* MSRD_3614 */

/* Set MEOSPROF_ASR_USE for Task load measurement. */
#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
#define MEOSPROF_ASR_USE_SCHEDULE
#define MEOSPROF_ASR_USE_WAITEVENT_NOWAIT
#endif

/* Set MEOSPROF_ASR_USE for Slack time measurement. */
#if (STD_ON == MEOSSLACK_MEASURE_BASIC_TASKS)
#define MEOSPROF_ASR_USE_ACTIVATION
#define MEOSPROF_ASR_USE_SCHEDULE
#endif
#if (STD_ON == MEOSSLACK_MEASURE_EXTENDED_TASKS)
#define MEOSPROF_ASR_USE_SETEVENT
#define MEOSPROF_ASR_USE_SCHEDULE
#define MEOSPROF_ASR_USE_WAITEVENT_NOWAIT
#endif
#if (STD_ON == MEOSSLACK_MEASURE_IRQS)
#define MEOSPROF_ASR_USE_SCHEDULE
#endif

/* Set MEOSPROF_ASR_USE for GLIWA time measurement. */
#if defined(ME__T1_ACTIVATION)
#define MEOSPROF_ASR_USE_ACTIVATION
#else
#define ME__T1_ACTIVATION(TaskId, DestCoreId, CallerCoreId)
#endif
#if defined(ME__T1_ACTIVATION_LIMIT)
#define MEOSPROF_ASR_USE_ACTIVATION_LIMIT
#else
#define ME__T1_ACTIVATION_LIMIT(TaskId, DestCoreId, CallerCoreId)
#endif
#if defined(ME__T1_SETEVENT)
#define MEOSPROF_ASR_USE_SETEVENT
#else
#define ME__T1_SETEVENT(TaskId, EventMask, StateChanged, DestCoreId, CallerCoreId)
#endif
#if defined(ME__T1_SCHEDULE)
#define MEOSPROF_ASR_USE_SCHEDULE
#else
#define ME__T1_SCHEDULE(FromThreadId, FromThreadReason, ToThreadId, ToThreadReason, CallerCoreId)
#endif
#if defined(ME__T1_WAITEVENT_NOWAIT)
#define MEOSPROF_ASR_USE_WAITEVENT_NOWAIT
#else
#define ME__T1_WAITEVENT_NOWAIT(TaskId, EventMask, DestCoreId, CallerCoreId)
#endif

/* Set MEOSPROF_ASR_USE for MeTace. */
#if defined(METRACE_VTH_ACTIVATION)
#define MEOSPROF_ASR_USE_ACTIVATION
#else
#define METRACE_VTH_ACTIVATION(TaskId, DestCoreId, CallerCoreId)
#endif
#if defined(METRACE_VTH_ACTIVATION_LIMIT)
#define MEOSPROF_ASR_USE_ACTIVATION_LIMIT
#else
#define METRACE_VTH_ACTIVATION_LIMIT(TaskId, DestCoreId, CallerCoreId)
#endif
#if defined(METRACE_VTH_SETEVENT)
#define MEOSPROF_ASR_USE_SETEVENT
#else
#define METRACE_VTH_SETEVENT(TaskId, EventMask, StateChanged, DestCoreId, CallerCoreId)
#endif
#if defined(METRACE_VTH_SCHEDULE)
#define MEOSPROF_ASR_USE_SCHEDULE
#else
#define METRACE_VTH_SCHEDULE(FromThreadId, FromThreadReason, ToThreadId, ToThreadReason, CallerCoreId)
#endif
#if defined(METRACE_VTH_WAITEVENT_NOWAIT)
#define MEOSPROF_ASR_USE_WAITEVENT_NOWAIT
#else
#define METRACE_VTH_WAITEVENT_NOWAIT(TaskId, EventMask, DestCoreId, CallerCoreId)
#endif

/* PRQA L:NO_UNDEF */

/* Define Vector timing hook macros.  */
#if defined(MEOSPROF_ASR_USE_ACTIVATION)
#define OS_VTH_ACTIVATION(TaskId, DestCoreId, CallerCoreId)  \
  {                                                          \
    ME__T1_ACTIVATION(TaskId, DestCoreId, CallerCoreId)      \
    METRACE_VTH_ACTIVATION(TaskId, DestCoreId, CallerCoreId) \
    MeOS_VTH_ACTIVATION(TaskId);                             \
  }
#endif

#if defined(MEOSPROF_ASR_USE_ACTIVATION_LIMIT)
#define OS_VTH_ACTIVATION_LIMIT(TaskId, DestCoreId, CallerCoreId)  \
  {                                                                \
    ME__T1_ACTIVATION_LIMIT(TaskId, DestCoreId, CallerCoreId)      \
    METRACE_VTH_ACTIVATION_LIMIT(TaskId, DestCoreId, CallerCoreId) \
  }
#endif

#if defined(MEOSPROF_ASR_USE_SETEVENT)
#define OS_VTH_SETEVENT(TaskId, EventMask, StateChanged, DestCoreId, CallerCoreId)  \
  {                                                                                 \
    ME__T1_SETEVENT(TaskId, EventMask, StateChanged, DestCoreId, CallerCoreId)      \
    METRACE_VTH_SETEVENT(TaskId, EventMask, StateChanged, DestCoreId, CallerCoreId) \
    MeOS_VTH_SETEVENT(TaskId, StateChanged);                                        \
  }
#endif

#if defined(MEOSPROF_ASR_USE_SCHEDULE)
#define OS_VTH_SCHEDULE(FromThreadId, FromThreadReason, ToThreadId, ToThreadReason, CallerCoreId)  \
  {                                                                                                \
    ME__T1_SCHEDULE(FromThreadId, FromThreadReason, ToThreadId, ToThreadReason, CallerCoreId)      \
    METRACE_VTH_SCHEDULE(FromThreadId, FromThreadReason, ToThreadId, ToThreadReason, CallerCoreId) \
    MeOS_VTH_SCHEDULE(FromThreadId, FromThreadReason, ToThreadId, ToThreadReason);                 \
  }
#endif

#if defined(MEOSPROF_ASR_USE_WAITEVENT_NOWAIT)
#define OS_VTH_WAITEVENT_NOWAIT(TaskId, EventMask, DestCoreId, CallerCoreId)  \
  {                                                                           \
    ME__T1_WAITEVENT_NOWAIT(TaskId, EventMask, DestCoreId, CallerCoreId)      \
    METRACE_VTH_WAITEVENT_NOWAIT(TaskId, EventMask, DestCoreId, CallerCoreId) \
    MeOS_VTH_WAITEVENT_NOWAIT(TaskId);                                        \
  }
#endif

#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
#define OS_VTH_DISABLEDINT(IntLockId, CallerCoreId)     \
  {                                                     \
    if (OS_VTHP_CAT2INTERRUPTS == (IntLockId)) {        \
      MeOS_VTH_DISABLEDINT(MEOS_TRACE_CAT2INTERRUPTS);  \
    } else if (OS_VTHP_ALLINTERRUPTS == (IntLockId)) {  \
      MeOS_VTH_DISABLEDINT(MEOS_TRACE_ALLINTERRUPTS);   \
    } else {/* Do nothing */}                                           \
  }

#define OS_VTH_ENABLEDINT(IntLockId, CallerCoreId)      \
  {                                                     \
    if (OS_VTHP_CAT2INTERRUPTS == (IntLockId)) {        \
      MeOS_VTH_ENABLEDINT(MEOS_TRACE_CAT2INTERRUPTS);   \
    } else if (OS_VTHP_ALLINTERRUPTS == (IntLockId)) {  \
      MeOS_VTH_ENABLEDINT(MEOS_TRACE_ALLINTERRUPTS);    \
    } else {/* Do nothing */}                                           \
  }
#endif

#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
#define OS_VTH_GOT_RES(ResId, CallerCoreId) \
  {                                         \
    MeOS_VTH_GOT_RES(ResId);                \
  }

#define OS_VTH_REL_RES(ResId, CallerCoreId) \
  {                                         \
    MeOS_VTH_REL_RES(ResId);                \
  }
#endif


/* +++ Public Function Prototypes +++++++++++++++++++++++++++++++++++++++++ */

#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
#if (STD_OFF == MEOSPROF_PRINT_FROM_OS)
void MeOsProf_PrintOsThreadStatSys(MeOsProf_TickType MeasTime);
#endif

LOCAL_INLINE void MeOsProf_WaitEventNoWait(MeOsProf_TickType currentTime, int TaskId) __attribute__((always_inline));
LOCAL_INLINE void MeOsProf_WaitEventNoWait(MeOsProf_TickType currentTime, int TaskId)
{
  MeOsProf_StatisticType *ptr = &MeOsProf_StatPtr[TaskId];
  /* Calculate running time from start. */
  MeOsProf_TickType running = MeOsProf_GetTickDiff(currentTime, MeOsProf_Work[TaskId].start);
  if (ptr->max < running)
  {
    ptr->max = running;
  }
#if (STD_ON == MEOSPROF_PRINT_FROM_OS)
  {
    MeOsProf_TickType MeasTime = MeOsProf_GetTickDiff(currentTime, MeOsProf_MeasStartTime);
    if (MeasTime >= MEOSPROF_TIME_MEAS_PERIOD)
    {
      MeOsProf_PrintOsThreadStatSys(MeasTime);
      currentTime = MeOsProf_GetTick();
      MeOsProf_MeasStartTime = currentTime;
      MeOsProf_LastProfTick = MeOsProf_MeasStartTime;
    }
  }
#endif
  ptr->activations++;
  MeOsProf_Work[TaskId].start = currentTime;
}

LOCAL_INLINE void MeOsProf_AddTicks(MeOsProf_TickType currentTime, int FromThreadId, int FromThreadReason, int ToThreadId, int ToThreadReason) __attribute__((always_inline));
LOCAL_INLINE void MeOsProf_AddTicks(MeOsProf_TickType currentTime, int FromThreadId, int FromThreadReason, int ToThreadId, int ToThreadReason)
{
  if (FromThreadId < (int)OS_TRACE_THREADID_COUNT)
  {
    MeOsProf_StatisticType *ptr = &MeOsProf_StatPtr[FromThreadId];
    /* Calculate running time. */
    MeOsProf_TickType running = MeOsProf_GetTickDiff(currentTime, MeOsProf_LastProfTick);
    ptr->ticks += running;
    if (OS_VTHP_THREAD_PREEMPT != FromThreadReason)
    {
      /* Calculate running time from start. */
      running = MeOsProf_GetTickDiff(currentTime, MeOsProf_Work[FromThreadId].start);
      if (ptr->max < running)
      {
        ptr->max = running;
      }
    }

    /* Update current value for new task. */
    MeOsProf_LastProfTick = currentTime;
  }

  if (ToThreadId < (int)OS_TRACE_THREADID_COUNT)
  {
#if (STD_ON == MEOSPROF_PRINT_FROM_OS)
    if ((OS_VTHP_TASK_ACTIVATION == ToThreadReason) ||
        (OS_VTHP_TASK_SETEVENT == ToThreadReason) ||
        (OS_VTHP_TASK_GOTSEMA == ToThreadReason))
    {
      MeOsProf_TickType MeasTime = MeOsProf_GetTickDiff(currentTime, MeOsProf_MeasStartTime);
      if (MeasTime >= MEOSPROF_TIME_MEAS_PERIOD)
      {
        MeOsProf_PrintOsThreadStatSys(MeasTime);
        currentTime = MeOsProf_GetTick();
        MeOsProf_MeasStartTime = currentTime;
        MeOsProf_LastProfTick = MeOsProf_MeasStartTime;
      }
    }
#endif

    if (OS_VTHP_THREAD_RESUME != ToThreadReason)
    {
      MeOsProf_StatisticType *ptr = &MeOsProf_StatPtr[ToThreadId];

      ptr->activations++;
      MeOsProf_Work[ToThreadId].start = currentTime;
    }
  }
}
#endif /* (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT) */

#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
LOCAL_INLINE void MeOsSlack_Start(MeOsProf_TickType currentTime, int TaskId) __attribute__((always_inline));
LOCAL_INLINE void MeOsSlack_Start(MeOsProf_TickType currentTime, int TaskId)
{
  MeOsProf_TickType StopTime = MeOsSlack_Work[TaskId].stop;
  if (0u != StopTime)
  {
    MeOsProf_TickType SlackTime = MeOsProf_GetTickDiff(currentTime, StopTime);
    MeOsSlack_StatisticType *ptr = &MeOsSlack_StatPtr[TaskId];
    if (SlackTime < ptr->min)
    {
      ptr->min = SlackTime;
#ifdef MEOSPROF_SLACK_REALTIME_CALLBACK
      MEOSPROF_SLACK_REALTIME_CALLBACK(TaskId, SlackTime);
#endif
    }
  }
}

LOCAL_INLINE void MeOsSlack_Stop(MeOsProf_TickType currentTime, int TaskId) __attribute__((always_inline));
LOCAL_INLINE void MeOsSlack_Stop(MeOsProf_TickType currentTime, int TaskId)
{
  MeOsSlack_Work[TaskId].stop = currentTime | 1u;
}

LOCAL_INLINE void MeOsSlack_WaitEventNoWait(int TaskId) __attribute__((always_inline));
LOCAL_INLINE void MeOsSlack_WaitEventNoWait(int TaskId)
{
  MeOsSlack_StatisticType *ptr = &MeOsSlack_StatPtr[TaskId];
  ptr->min = 0;
#ifdef MEOSPROF_SLACK_REALTIME_CALLBACK
  MEOSPROF_SLACK_REALTIME_CALLBACK(TaskId, 0);
#endif
}
#endif

LOCAL_INLINE void MeOS_VTH_ACTIVATION(int TaskId) __attribute__((always_inline));
LOCAL_INLINE void MeOS_VTH_ACTIVATION(int TaskId)
{
#if (STD_ON == MEOSSLACK_MEASURE_BASIC_TASKS)
  const MeOsProf_TickType currentTime = MeOsProf_GetTick();
  MeOsSlack_Start(currentTime, TaskId);
#else
  (void)TaskId;
#endif
}

LOCAL_INLINE void MeOS_VTH_SETEVENT(int TaskId, unsigned int StateChanged) __attribute__((always_inline));
LOCAL_INLINE void MeOS_VTH_SETEVENT(int TaskId, unsigned int StateChanged)
{
#if (STD_ON == MEOSSLACK_MEASURE_EXTENDED_TASKS)
  if (FALSE != StateChanged)
  {
    const MeOsProf_TickType currentTime = MeOsProf_GetTick();
    MeOsSlack_Start(currentTime, TaskId);
  }
#else
  (void)TaskId;
  (void)StateChanged;
#endif
}

LOCAL_INLINE void MeOS_VTH_SCHEDULE(int FromThreadId, int FromThreadReason, int ToThreadId, int ToThreadReason) __attribute__((always_inline));
LOCAL_INLINE void MeOS_VTH_SCHEDULE(int FromThreadId, int FromThreadReason, int ToThreadId, int ToThreadReason)
{
#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT) || (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
  const MeOsProf_TickType currentTime = MeOsProf_GetTick();
#endif
#if (STD_ON == MEOSPROF_ENABLE_SLACK_TIME_MEASUREMENT)
  if (
#if (STD_ON == MEOSSLACK_MEASURE_BASIC_TASKS)
    (OS_VTHP_TASK_TERMINATION == FromThreadReason) ||
#endif
#if (STD_ON == MEOSSLACK_MEASURE_EXTENDED_TASKS)
    (OS_VTHP_TASK_WAITEVENT == FromThreadReason) ||
#endif
#if (STD_ON == MEOSSLACK_MEASURE_IRQS)
    (OS_VTHP_ISR_END == FromThreadReason)
#endif
  )
  {
    MeOsSlack_Stop(currentTime, FromThreadId);
  }
#endif
#if (STD_ON == MEOSSLACK_MEASURE_IRQS)
  if (OS_VTHP_ISR_START == ToThreadReason)
  {
    MeOsSlack_Start(currentTime, ToThreadId);
  }
#endif
#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
  MeOsProf_AddTicks(currentTime, FromThreadId, FromThreadReason, ToThreadId, ToThreadReason);
#endif
}

LOCAL_INLINE void MeOS_VTH_WAITEVENT_NOWAIT(int TaskId) __attribute__((always_inline));
LOCAL_INLINE void MeOS_VTH_WAITEVENT_NOWAIT(int TaskId)
{
#if (STD_ON == MEOSSLACK_MEASURE_EXTENDED_TASKS) || (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
  const MeOsProf_TickType currentTime = MeOsProf_GetTick();
#endif
#if (STD_ON == MEOSSLACK_MEASURE_EXTENDED_TASKS)
  MeOsSlack_WaitEventNoWait(TaskId);
#endif
#if (STD_ON == MEOSPROF_ENABLE_TASK_LOAD_MEASUREMENT)
  MeOsProf_WaitEventNoWait(currentTime, TaskId);
#endif
}

#if (STD_ON == MEOSPROF_ENABLE_INT_LOCK_MEASUREMENT)
LOCAL_INLINE void MeOS_VTH_DISABLEDINT(unsigned int MeIntLockId) __attribute__((always_inline));
LOCAL_INLINE void MeOS_VTH_DISABLEDINT(unsigned int MeIntLockId)
{
  const MeOsProf_TickType currentTime = MeOsProf_GetTick();
  MeOsProf_StatisticType *ptr = &MeOsProf_StatPtrIntLock[MeIntLockId];
  ptr->activations++;
  MeOsProf_WorkIntLock[MeIntLockId].start = currentTime;
}

LOCAL_INLINE void MeOS_VTH_ENABLEDINT(unsigned int MeIntLockId) __attribute__((always_inline));
LOCAL_INLINE void MeOS_VTH_ENABLEDINT(unsigned int MeIntLockId)
{
  const MeOsProf_TickType currentTime = MeOsProf_GetTick();
  MeOsProf_StatisticType *ptr = &MeOsProf_StatPtrIntLock[MeIntLockId];
  /* Calculate running time. */
  MeOsProf_TickType running = MeOsProf_GetTickDiff(currentTime, MeOsProf_WorkIntLock[MeIntLockId].start);
  ptr->ticks += running;
  if (ptr->max < running)
  {
    ptr->max = running;
  }
}
#endif

#if (STD_ON == MEOSPROF_ENABLE_RES_LOCK_MEASUREMENT)
LOCAL_INLINE void MeOS_VTH_GOT_RES(int ResId) __attribute__((always_inline));
LOCAL_INLINE void MeOS_VTH_GOT_RES(int ResId)
{
  if (ResId < (int)OS_RESOURCEID_COUNT)
  {
    const MeOsProf_TickType currentTime = MeOsProf_GetTick();
    MeOsProf_StatisticType *ptr = &MeOsProf_StatPtrResLock[ResId];
    ptr->activations++;
    MeOsProf_WorkResLock[ResId].start = currentTime;
  }
}

LOCAL_INLINE void MeOS_VTH_REL_RES(int ResId) __attribute__((always_inline));
LOCAL_INLINE void MeOS_VTH_REL_RES(int ResId)
{
  if (ResId < (int)OS_RESOURCEID_COUNT)
  {
    const MeOsProf_TickType currentTime = MeOsProf_GetTick();
    MeOsProf_StatisticType *ptr = &MeOsProf_StatPtrResLock[ResId];
    /* Calculate running time. */
    MeOsProf_TickType running = MeOsProf_GetTickDiff(currentTime, MeOsProf_WorkResLock[ResId].start);
    ptr->ticks += running;
    if (ptr->max < running)
    {
      ptr->max = running;
    }
  }
}
#endif

/* === End Of Header File ================================================= */
#endif /* MEOSPROFILING_ASR_H */

/** @file
 *****************************************************************************
  @par MISRA deviations
 *****************************************************************************

  @misra MSRD_3453: MISRA C:2012 Dir-4.9; A function could probably be used instead of this function-like macro.
    - Reason:     Macros are used as it required from Vector and GLIWA apis.
                  Macro to convert Vector IntLockId to MeIntLockId which requers to start from 0.
    - Risk:       No risk.
    - Prevention: Not needed.

  @misra MSRD_3614: Macro 'MEOSPROF_ASR_USE_*' is being defined more than once without using #undef to remove the previous definition.
    - Reason:     'MEOSPROF_ASR_USE_*' macros are used to define which hooks to Vector or GLIWA shall be defined,
                  depending on MeOsProfiling and GLIWA configurations.
    - Risk:       No risk, macros can be defined or not defined and are used only in this file.
    - Prevention: Not needed.

 */
