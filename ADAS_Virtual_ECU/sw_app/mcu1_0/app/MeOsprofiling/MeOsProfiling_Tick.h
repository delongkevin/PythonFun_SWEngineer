/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @addtogroup     MeOsProfiling
 *  @file           MeOsProfiling_Tick.h
 *  @brief          Target dependant OS Profiling tick.
 *
 * Target dependent tick. Tick Shall be implemented as free running timer. For effective
 * implementation use tick that can be acquired as fast as possible (for example ARM Pmu counter).
 * Requeued interfaces and types:
 *    Init tick:
 *      void MeOsProf_InitTick(void)
 *    Get tick interface:
 *      MeOsProf_TickType MeOsProf_GetTick(void)
 *    Calculate difference between 2 ticks (Tick2 is always most recent then Tick1):
 *      MeOsProf_TickType MeOsProf_GetTickDiff(MeOsProf_TickType Tick2, MeOsProf_TickType Tick1)
 *    Tick type:
 *      MeOsProf_TickType
 *    Max tick value before overflow (used for slack time measurement):
 *      MEOSPROF_TICKTYPE_MAX
 *    Tick to ms/us macros:
 *      MEOSPROF_MS_2_TICK()
 *      MEOSPROF_TICK_2_MS()
 *      MEOSPROF_TICK_2_US()
 *
 * OS profiling tick implementation for LIDAR (ARM Cortex R7).
 *
 *  @author         Bernard Bosnjak
 *
 * ========================================================================= */

#ifndef MEOSPROFILING_TICK_H
#define MEOSPROFILING_TICK_H

#define MEOSPROF_USE_GLOBAL_TIMER STD_OFF

extern unsigned int __builtin_arm_mrc(unsigned int coproc,unsigned int opcode_1, unsigned int CRn, unsigned int CRm, unsigned int opcode_2);
extern void __builtin_arm_mcr(unsigned int coproc,unsigned int opcode_1, unsigned int CRn, unsigned int CRm, unsigned int opcode_2, unsigned int value);

#if STD_ON == MEOSPROF_USE_GLOBAL_TIMER
#define MEOSPROF_TICK_CLOCK_MHz 200u
#else
#define MEOSPROF_TICK_CLOCK_MHz 1000u
#endif

#define MEOSPROF_MS_2_TICK(x) ((x) * (MEOSPROF_TICK_CLOCK_MHz * 1000u))    /*As per TI r5 core for 1.0Ghz Clock frequency*/
#define MEOSPROF_TICK_2_MS(x) ((x) / (MEOSPROF_TICK_CLOCK_MHz * 1000u))
#define MEOSPROF_TICK_2_US(x) ((x) / MEOSPROF_TICK_CLOCK_MHz)


#if STD_ON == MEOSPROF_USE_GLOBAL_TIMER
/* Macros for Global Timer Offset from the Peripheral Base address (LIDAR) */
#define MEOSPROF_GLOBAL_TIMER_LOWER_COUNTER_REG    (*((volatile uint32 *)0xF0000200u))
#define MEOSPROF_GLOBAL_TIMER_UPPER_COUNTER_REG    (*((volatile uint32 *)0xF0000204u))
#define MEOSPROF_GLOBAL_TIMER_CONTROL_REG          (*((volatile uint32 *)0xF0000208u))
#define MEOSPROF_GLOBAL_TIMER_INTERRUPT_STATUS_REG (*((volatile uint32 *)0xF000020Cu))
#define MEOSPROF_GLOBAL_TIMER_COMPARE_LOWER_REG    (*((volatile uint32 *)0xF0000210u))
#define MEOSPROF_GLOBAL_TIMER_COMPARE_UPPER_REG    (*((volatile uint32 *)0xF0000214u))
#define MEOSPROF_GLOBAL_TIMER_AUTO_INCREMENT_REG   (*((volatile uint32 *)0xF0000218u))

#define MEOSPROF_GLOBAL_AUTO_INCREMENT_MODE 0x08u
#define MEOSPROF_GLOBAL_IRQ_ENABLE          0x04u
#define MEOSPROF_GLOBAL_COMPARE_ENABLE      0x02u
#define MEOSPROF_GLOBAL_TIMER_ENABLE        0x01u
#endif

/**
 * @brief Tick type (required)
 *
 */
typedef uint32 MeOsProf_TickType;
typedef sint32 MeOsProf_TickSignedType;

/**
 * @brief Max tick value before overflow (required)
 *
 */
#define MEOSPROF_TICKTYPE_MAX 0xFFFFFFFFu

/**
 * @brief Init tick (required)
 *
 */
LOCAL_INLINE void MeOsProf_InitTick(void)
{
#if STD_ON == MEOSPROF_USE_GLOBAL_TIMER
  /* Clear the global timer counter registers */
  MEOSPROF_GLOBAL_TIMER_LOWER_COUNTER_REG = 0u;
  MEOSPROF_GLOBAL_TIMER_UPPER_COUNTER_REG = 0u;
  /* Clear the global timer control register */
  MEOSPROF_GLOBAL_TIMER_CONTROL_REG = 0u;
  /* Clear the global timer interrupt status register */
  MEOSPROF_GLOBAL_TIMER_INTERRUPT_STATUS_REG = 0u;

  /* Enable global timer */
  MEOSPROF_GLOBAL_TIMER_CONTROL_REG = MEOSPROF_GLOBAL_TIMER_ENABLE;
#else
  uint32 const PMCR = __builtin_arm_mrc(15, 0, 9, 12, 0);
  __builtin_arm_mcr(15, 0, PMCR | 1u, 9, 12, 0);
  __builtin_arm_mcr(15, 0, 0x80000000u, 9, 12, 1);  /* Write to PMCNTENSET */
  __builtin_arm_mcr(15, 0, 1, 9, 14, 0);            /* Write to PMUSERENR */
#endif
}

/**
 * @brief Get tick (required)
 *
 * @return Tick.
 */
LOCAL_INLINE MeOsProf_TickType MeOsProf_GetTick(void) __attribute__((always_inline));
LOCAL_INLINE MeOsProf_TickType MeOsProf_GetTick(void)
{
  MeOsProf_TickType tick;
#if STD_ON == MEOSPROF_USE_GLOBAL_TIMER
  tick = MEOSPROF_GLOBAL_TIMER_LOWER_COUNTER_REG;
#else
  tick = __builtin_arm_mrc(15, 0, 9, 13, 0);
#endif
  return tick;
}

/**
 * @brief Calculate difference between 2 ticks (required)
 *
 * @param Tick2[in]   Recent Tick
 * @param Tick1[in]   Old Tick
 * @return Tick difference.
 */
LOCAL_INLINE MeOsProf_TickType MeOsProf_GetTickDiff(MeOsProf_TickType Tick2, MeOsProf_TickType Tick1) __attribute__((always_inline));
LOCAL_INLINE MeOsProf_TickType MeOsProf_GetTickDiff(MeOsProf_TickType Tick2, MeOsProf_TickType Tick1)
{
  MeOsProf_TickSignedType diff = (MeOsProf_TickSignedType)Tick2 - (MeOsProf_TickSignedType)Tick1;
  return (MeOsProf_TickType)diff;
}

#endif /* MEOSPROFILING_TICK_H */
