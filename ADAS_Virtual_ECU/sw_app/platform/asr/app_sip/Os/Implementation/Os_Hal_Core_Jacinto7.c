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
 *  \addtogroup  Os_Hal_Core
 *  \{
 *
 *  \file        Os_Hal_Core_Jacinto7.c
 *  \brief       contains translation tables for the different core domains of Jacinto7
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_DerivativeInt.h"

#if defined (OS_HAL_INTC_VIM_JACINTO7)
/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define OS_HAL_JACINTO7_MAXIMUM_NUMBER_OF_R5F_CORES (8uL)

/*! IPC Generation Registers */
#define OS_HAL_JACINTO7_REG_CTRLMMR_MCU_IPC_SET0    (0x40F00100uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_MCU_IPC_SET1    (0x40F00104uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET16       (0x00100140uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET17       (0x00100144uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET18       (0x00100148uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET19       (0x0010014CuL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET28       (0x00100170uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET29       (0x00100174uL)

/*! IPC Acknowledge Registers */
#define OS_HAL_JACINTO7_REG_CTRLMMR_MCU_IPC_CLR0    (0x40F00180uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_MCU_IPC_CLR1    (0x40F00184uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR16       (0x001001C0uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR17       (0x001001C4uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR18       (0x001001C8uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR19       (0x001001CCuL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR28       (0x001001F0uL)
#define OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR29       (0x001001F4uL)

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/
/*! translation table: HW Core ID to VIM Base Address */
CONST(uint32, OS_CONST) OsJacinto7VimBase[OS_HAL_JACINTO7_MAXIMUM_NUMBER_OF_R5F_CORES];

/*! translation table: HW Core ID to VIM number of IRQs */
CONST(uint32, OS_CONST) OsJacinto7VimNbrIrq[OS_HAL_JACINTO7_MAXIMUM_NUMBER_OF_R5F_CORES];

/*! Translation table: R5F logical Core ID to IPC_SET register address */
CONST(uint32, OS_CONST) OsHalJacinto7_IPC_SET_REG[OS_HAL_JACINTO7_MAXIMUM_NUMBER_OF_R5F_CORES];

/*! Translation table: R5F logical Core ID to IPC_CLR register address */
CONST(uint32, OS_CONST) OsHalJacinto7_IPC_CLR_REG[OS_HAL_JACINTO7_MAXIMUM_NUMBER_OF_R5F_CORES];

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL CONST
 **********************************************************************************************************************/
#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! translation table: HW Core ID to VIM Base Address */
CONST(uint32, OS_CONST) OsJacinto7VimBase[OS_HAL_JACINTO7_MAXIMUM_NUMBER_OF_R5F_CORES] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_HAL_JACINTO7_MCU_INTC_VIM_BASE,  /* MCU Domain */
  OS_HAL_JACINTO7_MCU_INTC_VIM_BASE,  /* MCU Domain */
  OS_HAL_JACINTO7_MAIN_INTC_VIM_BASE, /* Main Domain */
  OS_HAL_JACINTO7_MAIN_INTC_VIM_BASE, /* Main Domain */
  OS_HAL_JACINTO7_MAIN_INTC_VIM_BASE, /* Main Domain */
  OS_HAL_JACINTO7_MAIN_INTC_VIM_BASE, /* Main Domain */
  OS_HAL_JACINTO7_MAIN_INTC_VIM_BASE, /* Main Domain */
  OS_HAL_JACINTO7_MAIN_INTC_VIM_BASE  /* Main Domain */
};

/*! translation table: HW Core ID to VIM number of IRQs */
CONST(uint32, OS_CONST) OsJacinto7VimNbrIrq[OS_HAL_JACINTO7_MAXIMUM_NUMBER_OF_R5F_CORES] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_HAL_JACINTO7_MCU_INTC_NUMBER_OF_IRQS,  /* MCU Domain */
  OS_HAL_JACINTO7_MCU_INTC_NUMBER_OF_IRQS,  /* MCU Domain */
  OS_HAL_JACINTO7_MAIN_INTC_NUMBER_OF_IRQS, /* Main Domain */
  OS_HAL_JACINTO7_MAIN_INTC_NUMBER_OF_IRQS, /* Main Domain */
  OS_HAL_JACINTO7_MAIN_INTC_NUMBER_OF_IRQS, /* Main Domain */
  OS_HAL_JACINTO7_MAIN_INTC_NUMBER_OF_IRQS, /* Main Domain */
  OS_HAL_JACINTO7_MAIN_INTC_NUMBER_OF_IRQS, /* Main Domain */
  OS_HAL_JACINTO7_MAIN_INTC_NUMBER_OF_IRQS  /* Main Domain */
};

/*! Translation table: R5F logical Core ID to IPC_SET register address */
CONST(uint32, OS_CONST) OsHalJacinto7_IPC_SET_REG[OS_HAL_JACINTO7_MAXIMUM_NUMBER_OF_R5F_CORES] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_HAL_JACINTO7_REG_CTRLMMR_MCU_IPC_SET0, /* IPC_SET Reg Address for MCU Core0 */
  OS_HAL_JACINTO7_REG_CTRLMMR_MCU_IPC_SET1, /* IPC_SET Reg Address for MCU Core1 */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET16,    /* IPC_SET Reg Address for Main Core0 (Group0 Core0) */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET17,    /* IPC_SET Reg Address for Main Core1 (Group0 Core1) */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET18,    /* IPC_SET Reg Address for Main Core2 (Group1 Core0) */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET19,    /* IPC_SET Reg Address for Main Core3 (Group1 Core1) */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET28,    /* IPC_SET Reg Address for Main Core4 (Group2 Core0) */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_SET29     /* IPC_SET Reg Address for Main Core5 (Group2 Core1) */
};


/*! Translation table: R5F logical Core ID to IPC_CLR register address */
CONST(uint32, OS_CONST) OsHalJacinto7_IPC_CLR_REG[OS_HAL_JACINTO7_MAXIMUM_NUMBER_OF_R5F_CORES] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_HAL_JACINTO7_REG_CTRLMMR_MCU_IPC_CLR0, /* IPC_CLR Reg Address for MCU Core0 */
  OS_HAL_JACINTO7_REG_CTRLMMR_MCU_IPC_CLR1, /* IPC_CLR Reg Address for MCU Core1 */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR16,    /* IPC_CLR Reg Address for Main Core0 (Group0 Core0) */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR17,    /* IPC_CLR Reg Address for Main Core1 (Group0 Core1) */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR18,    /* IPC_CLR Reg Address for Main Core2 (Group1 Core0) */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR19,    /* IPC_CLR Reg Address for Main Core3 (Group1 Core1) */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR28,    /* IPC_CLR Reg Address for Main Core4 (Group2 Core0) */
  OS_HAL_JACINTO7_REG_CTRLMMR_IPC_CLR29     /* IPC_CLR Reg Address for Main Core5 (Group2 Core1) */
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* defined (OS_HAL_INTC_VIM_JACINTO7) */
/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_Jacinto7.c
 **********************************************************************************************************************/
