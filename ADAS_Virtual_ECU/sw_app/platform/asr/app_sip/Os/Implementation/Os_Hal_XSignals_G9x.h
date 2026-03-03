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
 *  \ingroup    Os_Hal
 *  \defgroup   Os_Hal_XSIGNALS  HAL X-Signals mechanism
 *  \brief      Implements X-signals for G9x using the Inter-processor Communication Registers
 *  \details
 *  \{
 *
 *  \file       Os_Hal_XSignals_G9x.h
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_XSIGNALS_G9X_H
# define OS_HAL_XSIGNALS_G9X_H
                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Core_Types.h"

/* Os kernel module dependencies */
# include "Os_CommonInt.h"

/* Os Hal includes */
# include "Os_Hal_InterruptController_GIC.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! Transmitter Message Control Register in Mailbox module */
# define OS_HAL_MB_TMC0_REG             (*(volatile uint32 *)(OS_HAL_MAILBOX_BASE_ADDRESS + 0xCuL))
/*! Receive Wakeup Control Register in Mailbox module */
# define OS_HAL_MB_RWC_REG              (*(volatile uint32 *)(OS_HAL_MAILBOX_BASE_ADDRESS + 0x28uL))

/*! Wakeup Event Mask. If set to 1, wakeup event from corresponding processor is masked */
# define OS_HAL_MB_RWC_WEM              0xF800uL
/*! Wakeup Acknowledgement. Self-cleared, set this bit to clear interrupt from other processors */
# define OS_HAL_MB_RWC_WACK             0x1uL

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONST
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_Hal_XSigInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_XSigInit,
(
  P2CONST(Os_Hal_XSigInterruptConfigType, AUTOMATIC, OS_CONST) XSigConfig
))
{
  /* #10 Set mask to receive interrupt form Safety/Secrity/MP processor only. */
  OS_HAL_MB_RWC_REG = OS_HAL_MB_RWC_WEM;
  /* #20 Enable interrupt for a given interrupt source. */
  OS_HAL_INTC_GIC_DISTRIBUTOR->Icdiser[XSigConfig->Source/32u] |= (1uL << (XSigConfig->Source%32u));
}

/***********************************************************************************************************************
 *  Os_Hal_XSigTrigger()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_XSigTrigger,
(
  P2CONST(Os_Hal_XSigInterruptConfigType, AUTOMATIC, OS_CONST) XSigConfig
))                                                                                                                     
{
  /* #10 Trigger interprocessor mailbox wakeup interrupt to the destination core. */
  OS_HAL_MB_TMC0_REG |= (1uL << (XSigConfig->CoreID + 16u));
}

/***********************************************************************************************************************
 *  Os_Hal_XSigAcknowledge()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_XSigAcknowledge,
(
  P2CONST(Os_Hal_XSigInterruptConfigType, AUTOMATIC, OS_CONST) XSigConfig
))                                                                                                                     
{
  /* #10 Clear interprocessor mailbox wakeup interrupt. */
  OS_HAL_MB_RWC_REG |= OS_HAL_MB_RWC_WACK;
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_XSIGNALS_G9X_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_XSignals_G9x.h
 **********************************************************************************************************************/

