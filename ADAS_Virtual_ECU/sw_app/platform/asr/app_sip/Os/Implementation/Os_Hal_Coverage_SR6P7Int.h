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

#ifndef  OS_HAL_COVERAGE_SR6P7INT_H
# define OS_HAL_COVERAGE_SR6P7INT_H
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
  \ACCEPT XF
  \REASON The condition is hardware dependent always false. The unnecessary code parts should be
          removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
          always just test the code for the respective platform. No risk as the remaining code shall be optimized
          away.

\ID COV_OS_HALPLATFORMISRMAPPINGAVAILABILITY
  \ACCEPT XX
  \ACCEPT XF
  \REASON This derivative does not meet the hardware requirements to support interrupt mapping.
          Functionality has been tested on another derivative.

\ID COV_OS_HALPLATFORMCONTEXT
  \ACCEPT XF
  \REASON This state is never can never be true, since it is a do-while-zero construct.

\ID COV_OS_HALPLATFORMNEEDMORETHAN2CORES
  \ACCEPT XX
  \ACCEPT XF
  \REASON This derivative only supports 2 cores.

\ID COV_OS_HALPLATFORMMASTERSTARTALLOWED
  \ACCEPT XF
  \REASON This code can only be reached when at least one core is configured to be allowed to start the master core.
          For SR6 all cores are auto-started and thus there is no need to configure a core to start the master core.

\ID COV_OS_HALPLATFORMNONAUTOSTARTCORE
  \ACCEPT TX
  \ACCEPT XX
  \REASON For SR6, all cores are auto-started.
          The function Os_Hal_CoreStart() is not called when all cores are auto-started cores.

\ID COV_OS_HALPLATFORMPERIPHERALINTTRIGGERSUPPORTED
  \ACCEPT TX
  \ACCEPT XX
  \REASON This platform always support peripheral interrupt software trigger.

\ID COV_OS_HALPLATFORMLEVELSUPPORT
  \ACCEPT TX
  \REASON This derivative does support interrupt level switching.

\ID COV_OS_HALPLATFORMLEVELSUPPORTEXCEPTION
  \ACCEPT XX
  \REASON The feature "modify exception context" is not available on this platform.

\ID COV_OS_HALPLATFORMCLEARPENDINGAVAILABILITY
  \ACCEPT TX
  \REASON The condition is hardware dependent always true. The unnecessary code parts should be
          removed by compiler optimization. No risk as the remaining code shall be optimized
          away.

\ID COV_OS_HALPLATFORMISRPOSTACTIONAVAILABILITY
  \ACCEPT XX
  \ACCEPT XF
  \REASON This derivative does not meet the hardware requirements to support interrupt post action handling.
          Functionality has been tested on another derivative.

\ID COV_OS_HALPLATFORMPITUNSUPPORTED_XX
  \ACCEPT XX
  \REASON Timer type PIT is not available on this derivative. Functionality has been tested on another derivative.

\ID COV_OS_HALPLATFORMSPURIOUSINTERRUPT
  \ACCEPT XF
  \REASON This code is reached only in special cases when there are no interrupt ID in the pending state, or all
          interrupt IDs in that pending state are of insufficient priority to be taken.
          Defensive programming paradigm is here used to ensure that only valid requests are going to be processed.

\ID COV_OS_HALPLATFORMGICINVSTATE
  \ACCEPT XX
  \REASON This case is never reached, since all the possible generated interrupt types are already handled.

\ID COV_OS_HALPLATFORMINVSTATE
  \ACCEPT XF
  \REASON This state is never seen as true, since the checked condition is already true before the check is reached.
          Hence, no waiting in the loop is necessary

\ID COV_OS_HALPLATFORMFRT64BITAVAILABILITY
  \ACCEPT TX
  \REASON The feature "64-bit FRT timer" is available on this platform.

\ID COV_OS_HALPLATFORMTIMERFRTCALLBACK
  \ACCEPT XX
  \REASON The functions are called as callbacks according to the timer configuration and the coverage token is
          fully reached for the corresponding generic timer type. The correctness is proved by code review
          and unit test.

\ID COV_OS_HALPLATFORMTRIGGERPERIPHERALINTERRUPT
  \ACCEPT TX
  \REASON The condition is always true, since the OS trigers internally either virtual timer interrupt or physical
          timer interrupt, which are both PPI interrupts. The function can be called generally for any interrupt
          source. The unnecessary code parts should be removed by compiler optimization. No risk as the remaining
          code shall be optimized away.

\ID COV_OS_HALPLATFORMAPPISPRIVILEGED
  \ACCEPT XX
  \REASON Due to the hardware inability to read the thread pointer in user mode when memory protection feauture
          is set, this function is never called. The unnecessary code parts should be removed by compiler
          optimization. As the tests run on each platform the OS is to be released for, we always just test
          the code for the respective platform. No risk as the remaining code shall be optimized away.

\ID COV_OS_HALPLATFORMCOREIDUSERREADABLE
  \ACCEPT XX
  \REASON Due to the hardware inability to read the thread pointer in user mode when memory protection feauture
          is set, Os_Hal_CoreIsCoreIdUserReadable function is never called. The unnecessary code parts should
          be removed by compiler optimization. As the tests run on each platform the OS is to be released for,
          we always just test the code for the respective platform. No risk as the remaining code shall be
          optimized away.

\ID COV_OS_HALPLATFORMTHREADPOINTERUSERREADABILITY_XX
  \ACCEPT XX
  \REASON See COV_OS_HALPLATFORMAPPISPRIVILEGED.

\ID COV_OS_HALPLATFORMTRAPALWAYSNEEDED
  \ACCEPT TX
  \REASON The condition is hardware dependent always true. The unnecessary code parts should be removed by
          compiler optimization. As the tests run on each platform the OS is to be released for, we always
          just test the code for the respective platform. No risk as the remaining code shall be optimized away.

\ID COV_OS_HALPLATFORMSETEXCEPTIONCONTEXTAVAILABILITY
   \ACCEPT TX
   \ACCEPT XX
   \REASON The feature "modify exception context" is not available on this platform.

\ID COV_OS_HALPLATFORMGETEXCEPTIONCONTEXTAVAILABILITY
   \ACCEPT TX
   \REASON The feature "read exception context" is not available on this platform.

\ID COV_OS_HALPLATFORMGETSPINLOCK
   \ACCEPT XF
   \REASON Though this code may be reached, it is impossible to have a reliable test with only 2 cores to cover this
           branch. Thus this is not covered on this derivative. However, the correctness can be proved by code review 
           and unit test.

END_COVERAGE_JUSTIFICATION */

#endif /* OS_HAL_COVERAGE_SR6P7INT_H */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Coverage_SR6P7Int.h
 **********************************************************************************************************************/
