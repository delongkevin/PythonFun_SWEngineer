
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
 * \addtogroup  Os_Hal_Derivative
 * \{
 *
 * \file
 * \brief  This file contains derivative specific coverage justifications.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef  OS_HAL_COVERAGE_JACINTO7INT_H
# define OS_HAL_COVERAGE_JACINTO7INT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

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

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/* START_COVERAGE_JUSTIFICATION

Justifications for core:

\ID COV_OS_HALPLATFORMTHREADPOINTERUSERREADABILITY_TX_XF
  \ACCEPT TX
  \REASON The condition is hardware dependent always true. The unnecessary code parts should be
          removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
          always just test the code for the respective platform. No risk as the remaining code shall be optimized
          away.

\ID COV_OS_HALPLATFORMFRT64BITAVAILABILITY
  \ACCEPT XF
  \ACCEPT XX
  \REASON The feature "64-bit FRT timer" is not available on this platform.

\ID COV_OS_HALPLATFORMCONTEXT
  \ACCEPT XF
  \REASON This state is never true, since it is a do-while-zero construct.

\ID COV_OS_HALPLATFORMPERIPHERALINTTRIGGERSUPPORTED
  \ACCEPT TX
  \ACCEPT XX
  \REASON This platform supports peripheral interrupt software trigger.

\ID COV_OS_HALPLATFORMSYSTEMINTERRUPTSUNSUPPORTED
  \ACCEPT XF
  \REASON The loop invariant is never true, because on this derivative we only have core interrupts. They are 
          initialized in Os_CoreInterruptHandlingInit.

\ID COV_OS_HALPLATFORMLEVELSUPPORT
  \ACCEPT TX
  \ACCEPT XF
  \REASON Jacinto7 supports interrupt level switching. So,
          for TX : when timning protection is configured, Os_InterruptLockOnLevelIsNeeded() returns TRUE;
          for XF : when timning protection is not configured, Os_InterruptLockOnLevelIsNeeded() 
                   returns FALSE since Cat0 interrupts are not supported.

\ID COV_OS_HALPLATFORMPITUNSUPPORTED_XX
  \ACCEPT XX
  \REASON Timer type PIT is not available on this derivative. Functionality has been tested on another derivative.

\ID COV_OS_HALPLATFORMNOCENTRALECXEPTIONHANDLER
  \ACCEPT XX
  \REASON This path is never covered. It has no functionality for Jacinto7 and is never used.

\ID COV_OS_HALPLATFORMCLEARPENDINGAVAILABILITY
  \ACCEPT TX
  \REASON The condition is hardware dependent always true. The unnecessary code parts should be
           removed by compiler optimization. No risk as the remaining code shall be optimized
           away.

\ID COV_OS_HALPLATFORMNONAUTOSTARTCORE
  \ACCEPT TX
  \ACCEPT XX
  \REASON For Jacinto7, all cores are auto-started.
          The function Os_Hal_CoreStart() is not called when all cores are auto-started cores.

\ID COV_OS_HALARMCROSSCOREUNSUPPORTED
  \ACCEPT XX
  \REASON The function is not needed for Jacinto7. Triggering X-signal interrupts is done using inter-processor 
          communication registers (See Os_Hal_XSigTrigger function in Os_Hal_XSignals_Jacinto7.h).

\ID COV_OS_HALARMWAITFORWRITE
  \ACCEPT XF
  \REASON The check is to ensure if all subsequent writes have been performed. It cannot be ensured that this path is 
          entered during a test run. The funtionality is ensured through review.

\ID COV_OS_HALPLATFORMAPPISPRIVILEGED
  \ACCEPT TF
  \REASON This justification is not relevant for this platform.

\ID COV_OS_HALPLATFORMMASTERSTARTALLOWED
  \ACCEPT XF
  \REASON This code can only be reached when at least one core is configured to be allowed to start the master core.
          For Jacinto7 all cores are auto-started and thus there is no need to configure a core to start the master core.
           
\ID COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY
  \ACCEPT XX
  \ACCEPT XF
  \REASON Jacinto7 does not support routing of CAT2 interrupts via e.g. an interrupt router.
          I.e. the feature of "mapping of user CAT2 interrupts" is not supported by Jacinto7.
          Configuring interrupts as IRQ or FIQ is not related to the "mapping of user CAT2 interrupts" feature.
          Hence, "mapping of user CAT2 interrupts" related functions/paths are not executed for this derivative. 
          There is no risk since those functions/paths are covered for other derivatives. Additionally, the unnecessary
          code parts are removed by compiler optimization.

\ID COV_OS_HALPLATFORMSETEXCEPTIONCONTEXTAVAILABILITY
   \ACCEPT XF
   \REASON The feature "modify exception context" is available on this platform.

\ID COV_OS_HALPLATFORMGETEXCEPTIONCONTEXTAVAILABILITY
   \ACCEPT XF
   \REASON The feature "read exception context" is available on this platform.

END_COVERAGE_JUSTIFICATION */

#endif /* OS_HAL_COVERAGE_JACINTO7INT_H */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Coverage_Jacinto7Int.h
 **********************************************************************************************************************/
