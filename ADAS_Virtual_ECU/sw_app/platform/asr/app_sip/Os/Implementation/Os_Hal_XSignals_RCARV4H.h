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
 *  \brief      Implements X-signals for RCARV4H using the Inter-processor Communication Registers
 *  \details
 *  \{
 *
 *  \file       Os_Hal_XSignals_RCARV4H.h
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_XSIGNALS_RCARV4H_H
# define OS_HAL_XSIGNALS_RCARV4H_H
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
# include "Os_Hal_InterruptController_GICv3.h"
/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* Calculating XSignal address. We are using the connection between (sender -> receiver) 2 -> 0, 2 -> 1 and 0 -> 2.
 * Receivercore 2 Calculation: OS_HAL_MFIS_HW_BASEADDRESS + 0xB464uL - 0x2038uL * ((ReceiverCoreID & 0x2uL) >> 1uL )
 * Receivercore 1 Calculation: OS_HAL_MFIS_HW_BASEADDRESS + 0xB464uL + 0x08uL   * (ReceiverCoreID & 0x1uL)
 * Receivercore 0 Calculation: OS_HAL_MFIS_HW_BASEADDRESS + 0xB464uL
 */
#define MFISRREMBR(ReceiverCoreID)  ((OS_HAL_MFIS_HW_BASEADDRESS + 0xB464uL) - (0x2038uL * ((ReceiverCoreID & 0x2uL) >> 1uL)) + (0x08uL * (ReceiverCoreID & 0x1uL)))

/* Key value to get access to modify MFISWPCNTR.*/
#define MAGIC_CODE_VALUE  (0xACCE0000UL)
/* Write protection register. */
#define MFISWPCNTR  (*(volatile uint32*)(OS_HAL_MFIS_HW_BASEADDRESS + 0x0900uL))
/* Set first bit to 0 to enable write protection.*/
#define ENABLE_WRITE_PROTECTION  (MAGIC_CODE_VALUE + 0x00uL)
/* Set first bit to 1 to enable write protection.*/
#define DISABLE_WRITE_PROTECTION (MAGIC_CODE_VALUE + 0x01uL)

#define INTERRUPT_ENABLE (0x01uL)
#define INTERRUPT_DISABLE (0x00uL)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
 
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
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  /* #10 Enable interrupt. */
  OS_HAL_INTC_GIC_DISTRIBUTOR->Isenanbler[XSigConfig->Source/32u] = (1uL << (XSigConfig->Source%32u));                  /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CALLER */
  /* #20 Get write access via MFISWPCNTR to write to MFISRREMBR. */ 
  MFISWPCNTR = DISABLE_WRITE_PROTECTION;                                                                                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_ISRCONFIG_RCARV4H_UNLOCK */
}


/***********************************************************************************************************************
 *  Os_Hal_XSigTrigger()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_XSigTrigger,
(
  P2CONST(Os_Hal_XSigInterruptConfigType, AUTOMATIC, OS_CONST) XSigConfig
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  /* #10 Trigger cross core interrupt source. */
  (*(volatile uint32*) (MFISRREMBR(XSigConfig->CoreID))) = INTERRUPT_ENABLE;                                            /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_XSigAcknowledge()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_XSigAcknowledge,
(
  P2CONST(Os_Hal_XSigInterruptConfigType, AUTOMATIC, OS_CONST) XSigConfig
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  /* #10 Clear cross core interrupt source. */
  (*(volatile uint32*) (MFISRREMBR(Os_Hal_CoreGetId()))) = INTERRUPT_DISABLE;                                           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CALLER */

  OS_IGNORE_UNREF_PARAM(XSigConfig);                                                                                    /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h" 

#endif /* OS_HAL_XSIGNALS_RCARV4H_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_XSignals_RCARV4H.h
 **********************************************************************************************************************/

