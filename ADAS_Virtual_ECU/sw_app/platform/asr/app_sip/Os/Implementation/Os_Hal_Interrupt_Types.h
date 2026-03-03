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
 *  \addtogroup Os_Hal_Interrupt
 *  \{
 *
 *  \file  Os_Hal_Interrupt_Types.h
 *  \brief  Defines some data structures related to interrupt handling
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_INTERRUPT_TYPES_H
# define OS_HAL_INTERRUPT_TYPES_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! \brief    Data type which contains the interrupt type Ids. */
typedef enum
{
  OS_HAL_ISR_TYPE_FIQ = 0u,
  OS_HAL_ISR_TYPE_IRQ = 1u
} Os_Hal_IntIsrType;

/*! \brief    Data type which contains the interrupt trigger type Ids. */
typedef enum
{
  OS_HAL_ISR_TRIGGER_TYPE_LEVEL = 0u,
  OS_HAL_ISR_TRIGGER_TYPE_PULSE = 1u
} Os_Hal_IntIsrTriggerType;

/*! \brief    Interrupt controller type.
 *  \details  Some derivatives (like NVIDIA Xavier) use daisy chained interrupt controllers for each core.
 *            The index is used to access the related, configured one. */
typedef enum
{
  OS_HAL_ISR_INTC_ROOT = 0u,
  OS_HAL_ISR_INTC_CHAINED = 1u,
  OS_HAL_ISR_INTC_E3_SF = 0u,
  OS_HAL_ISR_INTC_E3_SP0 = 2u,
  OS_HAL_ISR_INTC_E3_SP1 = 3u,
  OS_HAL_ISR_INTC_E3_SX0 = 4u,
  OS_HAL_ISR_INTC_E3_SX1 = 5u
} Os_Hal_IntControllerType;

/*! \brief    Interrupt state.
 *  \details  The kernel uses this data type to suspend/resume interrupts, to protect OS internal critical sections.
 *            This type is typically some kind of bit mask (e.g. processor status word). */
typedef uint32 Os_Hal_IntGlobalStateType;

/*! \brief    Interrupt level.
 *  \details  The kernel uses this data type to suspend/resume category 2 ISRs up to a certain level.
 *            This data type is needed to implement interrupt resources. */
typedef uint32 Os_Hal_IntLevelType;

/*! \brief    Interrupt state (with trap information).
 *  \details  The kernel uses this data type to restore the caller's interrupt state on OS service requests.
 *            On TriCore this data type also contains a pointer to the user space CSA. */
typedef uint32 Os_Hal_IntTrapStateType;

/*! Forward declaration of Os_Hal_IntStateType */
struct Os_Hal_IntStateType_Tag;
typedef struct Os_Hal_IntStateType_Tag Os_Hal_IntStateType;


/*! \brief    Interrupt source.
 *  \details  The kernel uses this data type to disable an interrupt source.
 *            This data type is needed to implement killing of applications.
 *            It is typically an interrupt index or interrupt source address. */
typedef uint32 Os_Hal_IntSourceType;

/*! \brief    Interrupt core ID.
 *  \details  The kernel uses this data type to select the interrupt
 *            vector table related to the core that is executing. */
typedef uint32 Os_Hal_IntIsrCoreID;

/*! \brief    Interrupt sender Core ID.
 *  \details  The kernel uses this data type to signal the completion of
 *            an interrupt in a multiprocessor scenario (GIC interrupt controller).*/
typedef uint32 Os_Hal_IntIsrSenderCoreID;

/*! \brief    The information for interrupt source.
 *  \details  This type is relevant for VIM controller to have the channel mapping for each source. */
typedef uint8 VIMChannel;

/*! Forward declaration of Os_Hal_IntIsrConfigType */
struct Os_Hal_IntIsrConfigType_Tag;
typedef struct Os_Hal_IntIsrConfigType_Tag Os_Hal_IntIsrConfigType;

typedef P2FUNC(void, OS_CODE, Os_Hal_VectorTableEntryType)(void);
typedef CONSTP2CONST(Os_Hal_VectorTableEntryType, TYPEDEF, OS_CONST)  Os_Hal_VectorTableType;

/*! Forward declaration of Os_Hal_IntIsrMapConfigType */
struct Os_Hal_IntIsrMapConfigType_Tag;
typedef struct Os_Hal_IntIsrMapConfigType_Tag Os_Hal_IntIsrMapConfigType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


#endif /* OS_HAL_INTERRUPT_TYPES_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Types.h
 **********************************************************************************************************************/
