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
 *  \file        Os_Hal_Core.c
 *  \brief       Core related primitives which don't have to be inlined.
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */


#define OS_HAL_CORE_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Derivative.h"
#include "Os_Hal_Core.h"
#include "Os_Hal_Interrupt.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Os.h"
#include "Os_Hal_Cfg.h"

/***********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/

/* Check the version of OS header file */
#if (  (OS_HAL_SW_MAJOR_VERSION != (2u)) \
    || (OS_HAL_SW_MINOR_VERSION != (89u)) \
    || (OS_HAL_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of Os_Hal_Core.c and Os_Hal_Os.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (OS_CFG_HAL_MAJOR_VERSION != (2u)) \
    || (OS_CFG_HAL_MINOR_VERSION != (70u)) )
# error "Version numbers of Os_Hal_Core.c and Os_Hal_Cfg.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

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

/***********************************************************************************************************************
 *  Os_Hal_CoreInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_Hal_CoreInit
(
  P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Config
)
{
  /* #10 Setup processor mode. */
  Os_Hal_ChangeToSystemMode();

  /* #20 Write the address of the variable ExcEntryRegSaveVarRef to {SP_abt, SP_und, SP_fiq, SP_svc} registers. */
  Os_Hal_SetAbortModeStackPointer((uint32)Config->ExcEntryRegSaveVarRef);                                               /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  Os_Hal_SetUndModeStackPointer((uint32)Config->ExcEntryRegSaveVarRef);                                                 /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  Os_Hal_SetFiqModeStackPointer((uint32)Config->ExcEntryRegSaveVarRef);                                                 /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  
  /* #30 Initialize exception handling. */
  Os_Hal_Core_InitExceptions(Config);                                                                                   /* SBSW_OS_HAL_FC_CALLER */
  
  /* #40 Initialize interrupt handling. */
  Os_Hal_INTC_InitIntVectors(Config);                                                                                   /* SBSW_OS_HAL_FC_CALLER */

  /* #50 Initialize stack protection MPU regions. */
  Os_Hal_Core_InitStackProtectionRegions(Config);                                                                       /* SBSW_OS_HAL_FC_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_CoreInitHardware()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_Hal_CoreInitHardware(P2CONST(Os_Hal_SystemConfigType, AUTOMATIC, OS_CONST) Config)
{
  /* #10 Nop. */
  OS_IGNORE_UNREF_PARAM(Config);                                                                                        /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
}


/***********************************************************************************************************************
 *  Os_Hal_CoreFreeze()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN, Os_Hal_CoreFreeze,                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  void
))                                                                                                                      /* COV_OS_HALCOREFREEZE */
{
  /* #10 Loop forever. */
  while( (1 == 1) )                                                                                                     /* COV_OS_HALCOREFREEZE */ /* FETA_OS_HAL_ARM_COREFREEZE */
  {
    Os_Hal_Nop();
  }
}


/***********************************************************************************************************************
 *  Os_Hal_CoreExceptionGetInterruptLockLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Os_Hal_IntLevelType, OS_CODE) Os_Hal_CoreExceptionGetInterruptLockLevel(void)                                      /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  /* #10 Get the current interrupt lock level. */
  return Os_Hal_IntGetLevelException();
}


/***********************************************************************************************************************
 *  Os_Hal_CoreExceptionSetInterruptLockLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_Hal_CoreExceptionSetInterruptLockLevel(Os_Hal_IntLevelType LockLevel)                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMSETEXCEPTIONCONTEXTAVAILABILITY */
{
  Os_Hal_IntSetLevelException(LockLevel);
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* START_COVERAGE_JUSTIFICATION

\ID COV_OS_HALCOREFREEZE
  \ACCEPT XX
  \REASON This function is called from Os_ErrKernelPanic() right after the panic hook has returned. As the panic hook
          is the last possible exit point for the tests, Os_Hal_CoreFreeze cannot be covered in tests. Because of the
          simplicity of the code, the performed code inspection results in sufficient quality.

Justifications for core:

\ID COV_OS_HALPLATFORMCLZAVAILABILITY
  \ACCEPT TX
  \REASON The condition is hardware dependent always true. The unnecessary code parts should be
          removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
          always just test the code for the respective platform. No risk as the remaining code shall be optimized
          away. (Other platforms may set ACCEPT XF with a similar justification)

\ID COV_OS_HALPLATFORMCOREIDUSERREADABILITY_TX_XF
   \ACCEPT XF
   \REASON The condition is hardware dependent always false. The unnecessary code parts should be
           removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
           always just test the code for the respective platform. No risk as the remaining code shall be optimized
           away. (Other platforms may set ACCEPT XF with a similar justification)

\ID COV_OS_HALPLATFORMPRIVILEGEMODEUSERREADABILITY
  \ACCEPT XF
  \REASON The condition is hardware dependent always false. The unnecessary code parts should be
          removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
          always just test the code for the respective platform. No risk as the remaining code shall be optimized
          away.

\ID COV_OS_HALPRIVILEGEMODEUSERREADABILITY_XX
  \ACCEPT XX
  \REASON The function is hardware dependent never called. The unnecessary code parts should be removed by
          compiler optimization. As the tests run on each platform, the OS is to be released for, we always just
          test the code for the respective platform. No risk as the remaining code shall be optimized  away.

\ID COV_OS_HALPLATFORMBITLIBCLZ
  \ACCEPT XX
  \REASON This code is meant as library code for the software implementation of Os_Bit_CountLeadingZeros(). As this
          processor provides a hardware solution, this code is unused. However, the function is extremely simple,
          code inspected and unit tested. It is typically optimized away by the linker. Therefore, the risk of
          keeping this code is expected to be low.

\ID COV_OS_HALPLATFORMUNHANDLEDSYSCALL
  \ACCEPT XX
  \REASON This function is only reacheable on some platforms. However, unit test and code inspection have not found
          any risk in keeping this code. The function is fully tested on those platforms which have potentially
          unhandled system calls.

\ID COV_OS_HALPLATFORMUNSUPPORTED8082
  \ACCEPT XX
  \REASON Unit test and code inspection have not found any risk in keeping this code. On ARM platform this code is
          covered in any case. Exhaustive testing is planned in WORKITEM8082.

\ID COV_OS_HALPLATFORM_NEED_NO_TRAP_IOC_MULTIQUEUE
  \ACCEPT XF
  \ACCEPT XX
  \REASON This path can never be reached on this platform. As IsTrapRequired is always false for multi-queue IOCs
          and the thread pointer is readable in user mode on this platform, no trap is necessary.

\ID COV_OS_HALPLATFORMGLOBAL2LEVELSUPPORTED
   \ACCEPT XF
   \ACCEPT XX
   \REASON Global to level switch is not supported on this platform.

Justifications for Variant Coverage:

\ID COV_OS_HALARMMPUDUMMYMODULE
   \ACCEPT XF
   \REASON [COV_OS_DERIVATIVEDUMMYMODULE]

\ID COV_OS_HALARMCDKMISRA
   \ACCEPT TX
   \REASON [COV_OS_CDKMISRA]

\ID COV_OS_HALPLATFORMFRT16BITAVAILABILITY
   \ACCEPT XF
   \ACCEPT XX
   \REASON The feature "16-bit FRT timer" is not available on this platform.

\ID COV_OS_HALPLATFORMFRT16BITAVAILABILITY_TX
   \ACCEPT TX
   \REASON The feature "16-bit FRT timer" is not available on this platform.

END_COVERAGE_JUSTIFICATION */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_HAL_PWA_CALLER
 \DESCRIPTION    A write access is performed on a pointer, which is coming directly from the caller.
 \COUNTERMEASURE \N No measure is required, because the caller has to check the validity.

\ID SBSW_OS_HAL_FC_CALLER
 \DESCRIPTION    A function is called with one or more pointer parameters, which are coming directly from the caller.
 \COUNTERMEASURE \N No measure is required, because the caller has to check the validity.

\ID SBSW_OS_HAL_FC_LOCAL_VAR
 \DESCRIPTION    A function is called with one or more pointer parameters, which are pointing to local variables.
 \COUNTERMEASURE \N No measure is required, because local variables are always valid.

\ID SBSW_OS_HAL_FC_POINTER2CONST
 \DESCRIPTION    A function is called with a const pointer parameter.
 \COUNTERMEASURE \N The parameter is declared as pointer to const to prevent invalid write access.

\ID SBSW_OS_HAL_PERIPHERAL_ACCESS
 \DESCRIPTION    Write access is performed on a pointer to a peripheral register.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_BOOTROM_TRAVEO_LOCK
 \DESCRIPTION    A write access is performed on the Traveo family specific BootROM lock/unlock register
                 (OS_HAL_BOOTROM_UNLOCK, OS_HAL_BOOTROM_LOCK).
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_BOOTROM_TRAVEO_EXCEPTION
 \DESCRIPTION    A write access is performed on the Traveo family specific BootROM registers (OS_HAL_BOOTROM_UNDEFINACT,
                 OS_HAL_BOOTROM_SVCINACT, OS_HAL_BOOTROM_PABORTINACT, OS_HAL_BOOTROM_DABORTINACT)
                 to set the exception table entries.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_BOOTROM_TRAVEO_CNFG
 \DESCRIPTION    A write access is performed on the Traveo family specific BootROM configuration register.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_UNLOCK
 \DESCRIPTION    A write access is performed on the interrupt lock/unlock register (OS_HAL_INTC_TRAVEO_UNLOCK).
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_IRQVA
 \DESCRIPTION    A write access is performed on the interrupt vector address register (OS_HAL_INTC_TRAVEO_IRQVA)
                 to set the configured handler functions.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_CSR
 \DESCRIPTION    A write access is performed on the interrupt control status register (OS_HAL_INTC_TRAVEO_CSR) to enable
                 the interrupt processing.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_PRIO
 \DESCRIPTION    A write access is performed on the interrupt priority register (OS_HAL_INTC_TRAVEO_IRQPL) to set
                 the priority to a specific source or on the priority mask register (OS_HAL_INTC_TRAVEO_IRQPLM) to mask
                 interrupts in a priority level range.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_ENABLE
 \DESCRIPTION    A write access is performed on the interrupt channel enable register (OS_HAL_INTC_TRAVEO_IRQCES) to
                 enable a specific source or on the interrupt channel disable register (OS_HAL_INTC_TRAVEO_IRQCEC) to
                 disable it.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_HOLD
 \DESCRIPTION    A write access is performed on the interrupt hold status register (OS_HAL_INTC_TRAVEO_IRQHC) to signal
                 the end of interrupt.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_ISRCONFIG_TRAVEO_SFTW
 \DESCRIPTION    A write access is performed on the software interrupt set register(OS_HAL_INTC_TRAVEO_IRQS) to trigger
                 the given interrupt source or on the software interrupt reset register (OS_HAL_INTC_TRAVEO_IRQR) to
                 clear the request.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_ISRCONFIG_GIC_DISTRIBUTOR
 \DESCRIPTION    A write access is performed on the GIC Distributor registers, starting from the base address
                 (OS_HAL_INTC_GIC_DISTRIBUTOR_BASE, OS_HAL_INTC_GIC_RT_DISTRIBUTOR_BASE
                 and OS_HAL_INTC_GIC_CORE_DISTRIBUTOR_BASE) to set the required interrupt priority and the connection
                 to the CPU interface.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_ISRCONFIG_GIC_CPUIF
 \DESCRIPTION    A write access is performed on the GIC CPU interface registers, starting from the base address
                 (OS_HAL_INTC_GIC_CPUIF_BASE, OS_HAL_INTC_GIC_RT_CPUIF_BASE and OS_HAL_INTC_GIC_CORE_CPUIF_BASE) to
                 set the required settings of the GIC with respect to the connected CPU.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_FC_ISRCONFIG_GIC
 \DESCRIPTION    A function is called with one or more parameters that are automatically generated depending on the ISRs
                 configuration. Namely OsCfg_Hal_InterruptVectorTable_Core0 could contain entries of type
                 Os_Hal_IsrConfigType that are used by the ISR handler mechanism.
 \COUNTERMEASURE \S Safety manual should state that the functionality of each configured ISR has to be checked for its
                 correctness.
                 This includes the correct call of the ISR handler as well as enabling, disabling, reading the enable
                 state,reading the pending state and clearing of the pending information of the corresponding sources.
                 SMI-491

\ID SBSW_OS_HAL_FPC_ISRCONFIG_GIC
 \DESCRIPTION    A function pointer is called which has been generated depending on the ISRs configuration.
                 Namely OsCfg_Hal_InterruptVectorTable_Core0 could contain pointers to ISR CAT1 functions that are
                 directly called by the ISR handler.
 \COUNTERMEASURE \S Safety manual should state that the functionality of each configured ISR has to be checked for its
                 correctness.
                 This includes the correct call of the ISR handler as well as enabling, disabling, reading the enable
                 state, reading the pending state and clearing of the pending information of the corresponding sources.
                 SMI-491

\ID SBSW_OS_HAL_FC_MPUCONFIG
 \DESCRIPTION    A function is called with a pointer parameter.
 \COUNTERMEASURE \N No measure required, because this pointer will not be used for write operation by the callee.

\ID SBSW_OS_HAL_PWA_PITCONFIG_RELOADTIMER
 \DESCRIPTION    A write access is performed starting from the Timer Base Address, which is generated from the timer
                 configuration for TRAVEO Reaload Timer of type Os_Hal_TimerPitConfigType.
 \COUNTERMEASURE \S Safety manual should state that the generated PIT timer configuration Os_Hal_TimerPitConfigType
                 in Os_Hal_Timer_Lcfg.c has to be checked for its correctness.
                 More in details:
                 * TimerBaseAddress has to match the related hardware manual specifications.
                 * ReloadValue has to match the configuration.
                 SMI-3325

\ID SBSW_OS_HAL_PWA_FRTCONFIG_TRAVEO
 \DESCRIPTION    A write access is performed starting from CounterRegisterAddress and CompareRegisterAddress, which are
                 generated from the timer configuration for TRAVEO of type Os_Hal_TimerFrtConfigType.
 \COUNTERMEASURE \S Safety manual should state that the generated FRT configuration Os_Hal_TimerFrtConfigType in
                 Os_Hal_Timer_Lcfg.c has to be checked for its correctness.
                 More in details:
                 * _CounterRegisterAddress_ has to match the related hardware manual specifications.
                 * _CompareRegisterAddress_ and _InterruptSource_ have to match the configuration.
                 SMI-3326

\ID SBSW_OS_HAL_PWA_PITCONFIG_TTC
 \DESCRIPTION    A write access is performed starting from the Timer Base Address, which is generated from the timer
                 configuration for TTC (Triple-timer Counter) of type Os_Hal_TimerPitConfigType.
 \COUNTERMEASURE \S Safety manual should state that the generated PIT configuration of type Os_Hal_TimerPitConfigType_
                 in Os_Hal_Timer_Lcfg.c_ has to be checked for its correctness.
                 More in details:
                 * TTC configuration base address of type Os_Hal_TtcModuleType*_ has to match the hardware manual
                   specification.
                 * ReloadValue and InterruptSource have to match the configuration.
                 SMI-3330

\ID SBSW_OS_HAL_PWA_FRTCONFIG_TTC
 \DESCRIPTION    A write access is performed starting from CounterRegisterAddress and CompareRegisterAddress, which are
                 generated from the timer configuration for TTC (Triple-timer Counter) of type Os_Hal_TimerFrtConfigType.
 \COUNTERMEASURE \S Safety manual should state that the generated FRT configuration of type Os_Hal_TimerFrtConfigType_
                 in Os_Hal_Timer_Lcfg.c_ has to be checked for its correctness.
                 More in details:
                 * TTC configuration base address of type Os_Hal_TtcModuleType*_ has to match the hardware manual
                   specification.
                 * InterruptSource has to match the configuration.
                 SMI-3331

\ID SBSW_OS_HAL_INT_VECTOR_TABLE
 \DESCRIPTION    Write address is performed on a pointer to an ISR related data structure. The accessing address is
                 calculated using the core ID and the interrupt number.
 \COUNTERMEASURE \S The user of MICROSAR Safe shall verify the functionality of each configured ISR.
                 This includes the correct call of the ISR handler as well as enabling, disabling, reading the enable
                 state, reading the pending state and clearing of the pending information of the corresponding sources.
                 SMI-491

\ID SBSW_OS_HAL_CORE_RESET_REGISTER
 \DESCRIPTION    A write access is performed on the Software control register for the LPD block register
                 (OS_HAL_RST_LPD_TOP) to start an additional core.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_VIM_CHANNCTRL
 \DESCRIPTION    A write access is performed on the VIM channel control register.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_VIM_FIRQPR
 \DESCRIPTION    A write access is performed on the VIM interrupt priority register.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_VIMSSIR1
 \DESCRIPTION    A write access is performed on the VIM software interrupt request register.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_VIMINTREQ
 \DESCRIPTION    A write access is performed on the VIM interrupt request register.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_VIMCHANNELHANDLER
 \DESCRIPTION    A write access is performed on the VIM channel handler address.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_VIMREQENASET
 \DESCRIPTION    A write access is performed on the VIM channel enable set register.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_VIMREQENACLR
 \DESCRIPTION    A write access is performed on the VIM channel enable clear register.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_RTI_MODULETYPE
 \DESCRIPTION    A write access is performed on a member of the struct Os_Hal_RtiModuleType that is mapped to
                 RTI hardware registers addresses: their validity is ensured by manual test.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_RTI_COUNTER
 \DESCRIPTION    A write access is performed on the array Os_Hal_RtiCounterModuleType.
                 The indexes used is statically defined and manual test ensures that they are between
                 0 and OS_HAL_TIMER_RTI_COUNTER_COUNT - 1.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_RTI_COMPAREUNITID
 \DESCRIPTION    A write access is performed on the array Os_Hal_RtiCompareModuleType.
                 The index used can only be one of the enum values of Os_Hal_RtiCompareUnitType: their validity is
                 ensured by manual test.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

 \ID SBSW_OS_HAL_TMU_MODULETYPE
 \DESCRIPTION    A write access is performed on a member of the struct Os_Hal_TmuModuleType that is mapped to
                 TMU hardware registers addresses: their validity is ensured by manual test.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_TMU_CHANNEL
 \DESCRIPTION    A write access is performed on the array Os_Hal_TmuChannelType.
                 The index used can only be one of the enum values of Os_Hal_TmuChannelNumType: their validity
                 is ensured by manual test.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_SIINTC0
 \DESCRIPTION    A write access is performed on the SIINTC0 interrupt controller registers, starting from the base
                 address OS_HAL_INTC_SIINTC_CORE_BASE to set the required settings for CR4DL0 CPU.
                 The validity of the addresses is ensured by manual test.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_AWA_SIINTC0
 \DESCRIPTION    An array write access is performed on the SIINTC0 interrupt controller registers, mapped as arrays in
                 the struct Os_Hal_IntcSiintcType starting from the base address OS_HAL_INTC_SIINTC_CORE_BASE to
                 initialize the interrupt handling for CR4DL0 CPU.
                 The validity of the indexes and of the corresponding hardware access is ensured by manual test.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_SICOMM
 \DESCRIPTION    A write access is performed on the SICOMM interrupt controller registers, starting from the base
                 address OS_HAL_INTC_SIINTC_SICOMM_BASE to set the required settings for CR4DL0 CPU.
                 The validity of the addresses is ensured by manual test.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_SICMPT0
 \DESCRIPTION    A write access is performed on the SICMPT0 timer registers starting from the base address
                 OS_HAL_TIMER_SICMPT0_BASE to set the required settings.
                 The validity of the addresses is ensured by manual test.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_SICMPT1
 \DESCRIPTION    A write access is performed on the SICMPT1 timer registers starting from the base address
                 OS_HAL_TIMER_SICMPT1_BASE to set the required settings.
                 The validity of the addresses is ensured by manual test.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_FC_POINTER2FUCNTION
 \DESCRIPTION    The callback is used as pointer to function to call the corresponding timer function.
 \COUNTERMEASURE \T TCASE-910391 ensures that the called function access its hardware registers correctly. 

\ID SBSW_OS_HAL_PWA_ISRCONFIG_GICV3_DISTRIBUTOR
 \DESCRIPTION    A write access is performed on the GIC Distributor registers, starting from the base address
                 (OS_HAL_INTC_GIC_DISTRIBUTOR, OS_HAL_INTC_GIC_REDISTRIBUTOR) to set the required interrupt
                 priority and the connection to the CPU interface.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

 \ID SBSW_OS_HAL_CORE_RESET_REGISTER_001
 \DESCRIPTION    A write access is performed on the core reset control register(OS_HAL_CORE_RST_REG) to start
                 an additional core.
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

\ID SBSW_OS_HAL_PWA_ISRCONFIG_RCARV4H_UNLOCK
 \DESCRIPTION    A write access is performed on the interrupt lock/unlock register (MFISWPCNTR).
 \COUNTERMEASURE \T TCASE-910391 ensures that the hardware access is correct.

 SBSW_JUSTIFICATION_END */

/* FETA_JUSTIFICATION_BEGIN

\ID FETA_OS_HAL_ARM_COREFREEZE
 \DESCRIPTION    The loop is the OS core freeze loop. It is used in case of a catastrophic failure.
 \COUNTERMEASURE \N None as the loop is endless by design. The system is intended to be reset by a watchdog at this point.

\ID FETA_OS_HAL_ARM_MPU
 \DESCRIPTION    The loop iterates over all configured MPU region descriptors.
 \COUNTERMEASURE \N None as the maximum number of iterations is fixed.

\ID FETA_OS_HAL_ARM_TRAVEOBOOTROMINIT
 \DESCRIPTION    The loop waits for a HW busy bit to be reset during intialization of the exception handlers. As the OS
                 has not been started and no other component is running, the FFI with respect to timing is not violated.
 \COUNTERMEASURE \N None as freedom from interference with respect to timing is not violated since the OS has not been
                 started and no other components are running.

\ID FETA_OS_HAL_ARM_JACINTO7INTC
 \DESCRIPTION    The loop iterates over all available interrupt sources of it's own core to set the interrupt handler address.
 \COUNTERMEASURE \N None as the maximum number of iterations is fixed.

\ID FETA_OS_HAL_ARM_GICV3INIT
 \DESCRIPTION    The loop waits for the initialization of GIC registers during initialization of the interrupt controller.
                 As the OS has not been started and no other component is running, the FFI with respect to timing is not
                 violate.
 \COUNTERMEASURE \N None as freedom from interference with respect to timing is not violated since the OS has not been
                 started and no other components are running.

\ID FETA_OS_HAL_ARM_JACINTO7FRTINIT
 \DESCRIPTION    The loop waits for a HW busy bit to be reset during initialization of the timer unit. As the OS has not 
                 been started and no other component is running, the FFI with respect to timing is not violated.
 \COUNTERMEASURE \N None as freedom from interference with respect to timing is not violated since the OS has not been
                 started and no other components are running.

\ID FETA_OS_HAL_ARM_SEMIDRIVEPITINIT
 \DESCRIPTION    The loop waits until counter value is updated during initialization of the timer unit. As the OS has not
                 been started and no other component is running, the FFI with respect to timing is not violated.
 \COUNTERMEASURE \N None as freedom from interference with respect to timing is not violated since the OS has not been
                 started and no other components are running.

FETA_JUSTIFICATION_END */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core.c
 **********************************************************************************************************************/
