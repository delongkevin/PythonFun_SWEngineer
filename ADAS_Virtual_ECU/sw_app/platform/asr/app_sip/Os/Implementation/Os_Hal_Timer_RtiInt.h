/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup  Os_Hal_Timer
 *  \{
 *
 *  \file    Os_Hal_Timer_RtiInt.h
 *  \brief   Data types and interfaces to work with the Real Time interrupt counter (RTI).
 *  \details RTI module features:
 *              - Two counters.
 *              - Can be used only as a PIT.
 *              - Four independent 32-bit compare register, with autoreload functionality.
 *              - Four interrupts, one for each compare event.
 *              - Increment counting.
 *
 *  Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_TIMER_TTCINT_H
# define OS_HAL_TIMER_TTCINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_TimerInt.h"

/* Os kernel module dependencies */
# include "Os_Common.h"

/* Os HAL dependencies */
# include "Os_Hal_Compiler.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! Number of counters in timer module. */
# define OS_HAL_TIMER_RTI_COUNTER_COUNT                    (2uL)

/*! Counter Id value used for PIT. */
# define OS_HAL_TIMER_PIT_RTI_COUNTER_ID                   (0uL)
/*! Counter Id value used for FRT. */
# define OS_HAL_TIMER_FRT_RTI_COUNTER_ID                   (1uL)

/*! Global Control register, CNT0EN field. */
# define OS_HAL_TIMER_RTI_ENABLE_BIT                       (1uL)
/*! Compare Up counter register, CPUCx fields. */
# define OS_HAL_TIMER_RTI_PRESCALER_RTICLK_DIV_2           (1uL)
/*! Set interrupt control register, SETINTx fields. */
# define OS_HAL_TIMER_RTI_INTERRUPT_ENABLE_BIT             (1uL)
/*! Interrupt flags register, INTx fields. */
# define OS_HAL_TIMER_RTI_INTERRUPT_CLEAR_BIT              (1uL)


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! RTI Compare Unit types. */
typedef enum
{
  OS_HAL_RTI_COMPARE_UNIT_0 = 0u,      /*! RTI compare unit 0. */
  OS_HAL_RTI_COMPARE_UNIT_1 = 1u,      /*! RTI compare unit 1. */
  OS_HAL_RTI_COMPARE_UNIT_2 = 2u,      /*! RTI compare unit 2. */
  OS_HAL_RTI_COMPARE_UNIT_3 = 3u,      /*! RTI compare unit 3. */
  OS_HAL_RTI_COMPARE_UNIT_COUNT = 4u   /*! RTI compare units number. */
}Os_Hal_RtiCompareUnitType;


/*! RTI counter module Layout. */
typedef struct
{
  uint32 FreeRunningCounterValue;     /*!< Free running counter value register. */
  uint32 UpCounterValue;              /*!< Up counter value register. */
  uint32 UpCounterCompare;            /*!< Up counter compare register. */
  uint32 Reserved0;                   /*!< Reserved bits. */
  uint32 FreeRunningCapture;          /*!< Free running counter capture register. */
  uint32 UpCapture;                   /*!< Up counter capture register. */
  uint32 Reserved1;                   /*!< Reserved bits. */
  uint32 Reserved2;                   /*!< Reserved bits. */
} Os_Hal_RtiCounterModuleType;

/*! RTI compare module Layout. */
typedef struct
{
  uint32 CompareValue;                     /*!< Compare value register. */
  uint32 UpdateCompareValue;               /*!< Update compare value register. */
} Os_Hal_RtiCompareModuleType;

/*! RTI module Layout. */
typedef struct
{
  uint32 GlobalControl;                                                           /*!< Offset: 0x00 Global control register. */
  uint32 TimebaseControl;                                                         /*!< Offset: 0x04 Timebase control register. */
  uint32 CaptureControl;                                                          /*!< Offset: 0x08 Capture control register. */
  uint32 CompareControl;                                                          /*!< Offset: 0x0C Compare control register. */
  Os_Hal_RtiCounterModuleType Counter[OS_HAL_TIMER_RTI_COUNTER_COUNT];            /*!< Offset: 0x10 Counter specific registers. */                                                   /*!< Reserved bits. */
  Os_Hal_RtiCompareModuleType Compare[OS_HAL_RTI_COMPARE_UNIT_COUNT];             /*!< Offset: 0x50 Compare specific registers. */
  uint32 TimebaseLowCompare;                                                      /*!< Offset: 0x70 Timebase low compare register. */
  uint32 TimebaseHighCompare;                                                     /*!< Offset: 0x74 Timebase high compare register. */
  uint32 Reserved3;                                                               /*!< Offset: 0x78 Reserved bits. */
  uint32 Reserved4;                                                               /*!< Offset: 0x7C Reserved bits. */
  uint32 SetInterruptEnable;                                                      /*!< Offset: 0x80 Set Interrupt enable register. */
  uint32 ClearInterruptEnable;                                                    /*!< Offset: 0x84 Clear Interrupt enable register. */
  uint32 InterruptFlag;                                                           /*!< Offset: 0x88 Interrupt flag register. */
} Os_Hal_RtiModuleType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


#endif /* OS_HAL_TIMER_TTCINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_TtcInt.h
 **********************************************************************************************************************/
