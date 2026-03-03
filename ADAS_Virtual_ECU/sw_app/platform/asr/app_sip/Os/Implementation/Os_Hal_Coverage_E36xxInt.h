
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

#ifndef  OS_HAL_COVERAGE_E36XXINT_H
# define OS_HAL_COVERAGE_E36XXINT_H
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

\ID COV_OS_HALPLATFORMNOCENTRALECXEPTIONHANDLER
  \ACCEPT XX
  \REASON This path is never covered. It has no functionality for E36xx and is never used.

\ID COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY
  \ACCEPT XX
  \ACCEPT XF
  \REASON This derivative does not meet the hardware requirements to support interrupt mapping.
          Functionality has been tested on another derivative.

\ID COV_OS_HALPLATFORMISRPOSTACTIONAVAILABILITY
  \ACCEPT XX
  \ACCEPT XF
  \REASON This derivative does not meet the hardware requirements to support interrupt post action handling.
          Functionality has been tested on another derivative.

\ID COV_OS_HALPLATFORMLEVELSUPPORT
  \ACCEPT TX
  \REASON This derivative does support interrupt level switching.

\ID COV_OS_HALPLATFORMTPUNSUPPORTED_XF
  \ACCEPT XF
  \REASON Timing protection not supported yet for this platform.

\ID COV_OS_HALPLATFORMGETEXCEPTIONCONTEXTAVAILABILITY
   \ACCEPT XF
   \REASON The feature "read exception context" is available on this platform.

\ID COV_OS_HALPLATFORMTPUNSUPPORTED_XX
  \ACCEPT XX
  \REASON Timing protection not supported yet for this platform.

\ID COV_OS_HALPLATFORMCONTEXT
  \ACCEPT XF
  \REASON This state is never true, since it is a do-while-zero construct.

\ID COV_OS_HALPLATFORMCLEARPENDINGAVAILABILITY
   \ACCEPT TX
   \REASON The condition is hardware dependent always true. The unnecessary code parts should be
           removed by compiler optimization. No risk as the remaining code shall be optimized
           away.

\ID COV_OS_HALPLATFORMTPUNSUPPORTED_TX
  \ACCEPT TX
  \REASON Timing protection not supported yet for this platform.

\ID COV_OS_HALPLATFORMPERIPHERALINTTRIGGERSUPPORTED
  \ACCEPT TX
  \ACCEPT XX
  \REASON This platform always support peripheral interrupt software trigger.

\ID COV_OS_HALPLATFORMFRTUNSUPPORTED_XX
  \ACCEPT XX
  \REASON Timer type FRT is not being tested for SC1 on this derivative. 
          Functionality has been tested on another derivative.

\ID COV_OS_HALPLATFORMFRT64BITAVAILABILITY
   \ACCEPT XF
   \ACCEPT XX
   \REASON The feature "64-bit FRT timer" is not available on this platform.

\ID COV_OS_HALPLATFORMMULTICOREORTPUNSUPPORTED
  \ACCEPT XX
  \ACCEPT TX
  \ACCEPT XF
  \REASON Timing protection not supported yet for this platform.

\ID COV_OS_HALPLATFORMISRNESTINGSUPPORT_TX
  \ACCEPT TX
  \REASON This derivative does not meet the hardware requirements to support interrupt nesting. Nesting is realized by 
          using software simulated level register. Functionality has been tested on another derivative.

\ID COV_OS_HALPLATFORMTHREADPOINTERUSERREADABILITY_TX_XF
  \ACCEPT TX
  \REASON The condition is hardware dependent always true. The unnecessary code parts should be
          removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
          always just test the code for the respective platform. No risk as the remaining code shall be optimized
          away.

\ID COV_OS_HALPLATFORMSETEXCEPTIONCONTEXTAVAILABILITY
   \ACCEPT XF
   \REASON The feature "modify exception context" is available on this platform.

\ID COV_OS_HALPLATFORMCOREINTERRUPTSUNSUPPORTED
  \ACCEPT XF
  \REASON The loop invariant is never true, because on this platform all interrupts are system wide. They are initialized
          in Os_SystemInterruptHandlingInit.

\ID COV_OS_HALARMCROSSCOREUNSUPPORTED
  \ACCEPT XX
  \REASON The function is not needed for E3. Triggering X-signal interrupts is done using software interrupt trigger
          (See Os_Hal_XSigTrigger function in Os_Hal_XSignals_E3x.h).

END_COVERAGE_JUSTIFICATION */

#endif /* OS_HAL_COVERAGE_E36XXINT_H */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Coverage_E36xxInt.h
 **********************************************************************************************************************/
