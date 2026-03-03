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
 *  \addtogroup Os_Hal_CoreStart_G9x.h
 *  \trace      
 *  \{
 *
 *  \file       Os_Hal_CoreStart_G9x.h
 *  \brief      provides implementation of core start with G9x
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_CORESTART_G9X_H
# define OS_HAL_CORESTART_G9X_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! Base address of the core reset module. */
# define OS_HAL_CORE_RST_BASE_ADDRESS              (0xF8400000uL)

/*! RSTGEN Core Reset Enable Register */
# define OS_HAL_CORE_RST_EN(Core)   *(volatile uint32*)(OS_HAL_CORE_RST_BASE_ADDRESS + ((0x4uL + (Core * 0x8uL))<<10))
/*! RSTGEN Core Reset Register */
# define OS_HAL_CORE_SW_RST(Core)   *(volatile uint32*)(OS_HAL_CORE_RST_BASE_ADDRESS + ((0x8uL + (Core * 0x8uL))<<10))

/*! Core software reset enable bit */
# define OS_HAL_CORE_SW_RST_EN           (0x1uL << 0u)
/*! Core reset lock bit */
# define OS_HAL_CORE_SW_RST_LOCK         (0x1uL << 31u)
/*! Core software reset enable status bit */
# define OS_HAL_CORE_SW_RST_EN_STA       (0x1uL << 30u)
/*! Core reset status bit */
# define OS_HAL_CORE_RST_STA             (0x1uL << 30u)
/*! Core software static reset status bit, polling this bit to check whether the register program is done */
# define OS_HAL_CORE_STATIC_RST_B_STA    (0x1uL << 29u)
/*! Core software auto clear reset bit.
 *  Write one to trigger reset, and it can be auto cleared, core will re-start automatically. */
# define OS_HAL_CORE_AUTO_CLR_RST        (0x1uL << 1u)
/*! Core software static reset bit */
# define OS_HAL_CORE_STATIC_RST_B        (0x1uL << 0u)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Hal_CoreStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_CoreStart,
(
  P2CONST(Os_Hal_CoreConfigType, AUTOMATIC, OS_CONST) Core
))                                                                                                                      /* COV_OS_HALPLATFORMNONAUTOSTARTCORE */
{
  /* #10 Check if core reset is locked */
  if((OS_HAL_CORE_RST_EN(Core->CoreId) & OS_HAL_CORE_SW_RST_LOCK) == 0u)
  {
    /* #20 Release reset before enable */
    OS_HAL_CORE_SW_RST(Core->CoreId) |= OS_HAL_CORE_STATIC_RST_B;
    while (!(OS_HAL_CORE_SW_RST(Core->CoreId) & OS_HAL_CORE_STATIC_RST_B_STA));

    /* #30 Enable core software reset */
    OS_HAL_CORE_RST_EN(Core->CoreId) |= OS_HAL_CORE_SW_RST_EN;
    while (!(OS_HAL_CORE_RST_EN(Core->CoreId) & OS_HAL_CORE_SW_RST_EN_STA));

    /* #40 Trigger core software: auto clear reset */
    OS_HAL_CORE_SW_RST(Core->CoreId) |= OS_HAL_CORE_AUTO_CLR_RST;
    while (!(OS_HAL_CORE_SW_RST(Core->CoreId) & OS_HAL_CORE_RST_STA));
  }
}

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

#endif /* OS_HAL_CORESTART_G9X_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_CoreStart_G9X.h
 **********************************************************************************************************************/
