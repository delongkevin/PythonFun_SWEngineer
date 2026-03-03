/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Hardware-specific module for:
 *                  NXP MPC57xx / ST SPC57x / NXP Vybrid
 *                  ST SPC58xx
 *                  Spansion Traveo
 *                  Renesas Rh850/P1x-C
 *                  Infineon TC3xx/TC4xx
 *                  Microchip SAML1x/SAMC21/SAMD21/SAME5x/SAMV70/SAMV71/SAMHAx/PIC32CM
 *                  Broadcom BCM8910x
 *                  Cypress Traveo 2
 *                  Toshiba TMPV770
 *                  ST STM32H7xx/STM32L5xx
 *                  TI TDA4/Jacinto7
 *                 Provides the CAN-Interface and timer operations
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2014-07-18  visach  -                Initial version
 *  01.01.00   2015-04-30  visach  ESCAN00082734    Synchronized file with FlexCAN3 1.09.00
 *  01.02.00   2015-06-12  visawh  ESCAN00083227    Add Spansion Traveo
 *  01.02.01   2015-09-25  visawh  ESCAN00085490    No changes
 *  01.03.00   2016-01-28  vaddod  ESCAN00085772    Added support for Renesas Rh850/P1x-C
 *                         visawh  ESCAN00086117    No changes
 *                         visach  ESCAN00086967    Result of start message content check is not returned
 *                                 ESCAN00087164    Reworked CAN memory handling
 *  01.04.00   2016-02-01  vistns  ESCAN00087576    Replacement of unlock sequence for Traveo pin configuration
 *  01.05.00   2016-03-01  visqpc  ESCAN00088688    Added support for Atmel SAMC21x
 *  01.06.00   2016-03-23  visthm  ESCAN00089063    No changes
 *                                 ESCAN00088816    Corrected parameter passing of bit timings for GM
 *  01.07.00   2016-04-15  viskjs  ESCAN00089376    No changes
 *  01.08.00   2016-04-27  visqpc  ESCAN00089758    Added support for SPC58ECx
 *  01.09.00   2016-10-26  visawh  ESCAN00090796    No changes
 *                                 ESCAN00091228    No changes
 *  01.09.01   2016-11-24  visthm  ESCAN00093004    No changes
 *  01.10.00   2016-12-30  visdkl  ESCAN00093431    No changes
 *  01.11.00   2017-10-19  visach  ESCAN00093985    Synchronize with FlexCAN implementation
 *                                 ESCAN00094027    Support Aurix+
 *                         viskjs  ESCAN00096812    Support ATSAMV70/71
 *  01.11.01   2017-11-15  visach  ESCAN00097217    No changes
 *  01.12.00   2017-12-01  visach  ESCAN00097588    Adaptions to keep evaluation of switch FBL_ENABLE_BUSTYPE_CAN
 *  01.12.01   2018-05-04  visrie  ESCAN00099314    No changes
 *  01.13.00   2018-05-02  vaddod  ESCAN00099284    Added support for BCM8910x
 *             2018-06-14  visshs  ESCAN00099682    No changes
 *                                 ESCAN00099686    No changes
 *  01.14.00   2018-07-03  visach  ESCAN00099883    Add configuration switches for message RAM parameters
 *  01.15.00   2018-08-10  vistmo  ESCAN00100358    Add Cypress Traveo 2
 *  01.15.01   2018-10-05  visach  ESCAN00100708    SWCP processing for Traveo1 fails
 *  01.15.02   2018-10-17  vistmo  ESCAN00101054    No changes
 *  01.16.00   2019-01-31  vistmo  ESCAN00101956    Add ATSAME5x support
 *                                 ESCAN00101982    Adapting to MISRA 2012
 *  01.17.00   2019-04-01  vistmo  ESCAN00102706    Add ATSAML1x support
 *                                 ESCAN00102853    Add TMPV770 support
 *  01.18.00   2019-06-25  vistmo  ESCAN00103504    Added Mcan support for ATSAMC21
 *  01.19.00   2019-08-22  vistmo  FBL-383          Added support for Tricore Green Hills compiler
 *  01.19.01   2019-10-22  vistmo  ESCAN00103561    No changes
 *  01.20.00   2019-12-13  vistmo  FBL-777          Add STM32H7xx and STM32L5xx support
 *  01.21.00   2020-04-28  vistmo  FBL-1734         No changes
 *  01.22.00   2020-05-29  vistmo  FBL-1869         Add ATSAMHAx support
 *  01.23.00   2020-08-12  visjdn  FBL-1947         Add Jacinto7/TDA4 support
 *  01.23.01   2020-09-01  visjdn  ESCAN00107257    No changes
 *  01.24.00   2020-09-01  visrcn  FBL-2511         Add SAMD21 support
 *  01.25.00   2020-11-05  vistmo  FBL-2336         No changes
 *  01.26.00   2020-11-10  visjdn  FBL-2311         No changes
 *                                 FBL-2665         No changes
 *  01.26.01   2021-03-22  visjdn  ESCAN00108454    No changes
 *  01.27.00   2021-07-22  visrie  FBL-3688         No changes
 *  01.28.00   2021-09-21  visjdn  FBL-3844         No changes
 *  01.29.00   2022-03-04  vishor  FBL-4692         No changes
 *                                 ESCAN00110852    No changes
 *                                 ESCAN00111409    No changes
 *  01.30.00   2022-05-10  vishor  FBL-4246         Add support for Tricore TC4xx
 *  01.31.00   2022-05-17  visjdn  FBL-5159         No changes
 *  01.32.00   2022-05-31  visjdn  FBL-4938         Add support of PIC32CM
 *  01.32.01   2022-08-04  visrie  ESCAN00112517    The bootloader waits infinite for the HW to be finished
 *  01.32.02   2022-08-05  visjdn  ESCAN00112523    No changes
 *  01.33.00   2022-08-09  visjdn  FBL-4709         Add support for Sitara AM62xxA
 **********************************************************************************************************************/

#define FBL_HW_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLDRVCAN_MPC5700MCANCRX_VERSION != 0x0133u ) || \
    ( FBLDRVCAN_MPC5700MCANCRX_RELEASE_VERSION != 0x00u )
# error "Error in fbl_hw.c: Source and header file are inconsistent!"
#endif
#if ( FBLDRVCAN_MPC5700MCANCRX_VERSION != _FBLDRVCAN_VERSION ) || \
    ( FBLDRVCAN_MPC5700MCANCRX_RELEASE_VERSION != _FBLDRVCAN_RELEASE_VERSION )
# error "Error in fbl_hw.c: Source and v_ver.h are inconsistent!"
#endif

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */



/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
#define FBLHW_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */
#define FBLHW_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
#define FBLHW_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  TIMER HANDLING FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  FblTimerInit
 **********************************************************************************************************************/
/*! \brief       Initialize system timer
 **********************************************************************************************************************/
void FblTimerInit( void )
{
   /* Fbl 1ms Base Timer */
   /* PRQA S 0303 10 */ /* MD_FBL_0303_MemoryMappedRegAccess */
   FBL_TIMER_TIOCP_CFG(0u)      |= 0x01uL; /* Execute SW reset of the module */
   while ((FBL_TIMER_TIOCP_CFG(0u) & 0x01uL) != 0x00uL) /* Check that the reset was executed */
   {
      ;
   }
   FBL_TIMER_TCLR(0u)           |= (0x01uL << FBL_TIMER_TCLR_AUTORELOAD); /* Set autoreload mode */
   FBL_TIMER_IRQSTATUS_SET(0u)  = (0x01uL << FBL_TIMER_IRQSTATUS_OVERFLOW); /* Enable overflow interrupt */
   FBL_TIMER_TCRR(0u)           = FblInvert32Bit(FBL_TIMER_RELOAD_VALUE); /* Set timer load value */
   FBL_TIMER_TLDR(0u)           = FblInvert32Bit(FBL_TIMER_RELOAD_VALUE); /* Set timer reload value */
   FBL_TIMER_TCLR(0u)           |= FBL_TIMER_TCLR_START; /* Start the timer */

   /* Free running timer */
   /* PRQA S 0303 9 */ /* MD_FBL_0303_MemoryMappedRegAccess */
   FBL_TIMER_TIOCP_CFG(1u)      |= 0x01uL; /* Execute SW reset of the module */
   while ((FBL_TIMER_TIOCP_CFG(1u) & 0x01uL) != 0x00uL) /* Check that the reset was executed */
   {
      ;
   }
   FBL_TIMER_TCLR(1u)           |= (0x01uL << FBL_TIMER_TCLR_AUTORELOAD); /* Set autoreload mode */
   FBL_TIMER_TCRR(1u)           = 0x00uL; /* Set timer load value */
   FBL_TIMER_TLDR(1u)           = 0x00uL; /* Set timer reload value */
   FBL_TIMER_TCLR(1u)           |= FBL_TIMER_TCLR_START; /* Start the timer */
}
#define FBLHW_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLHW_RAMCODE_START_SEC_CODE
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblGetTimerValue
 **********************************************************************************************************************/
/*! \brief       Returns free running timer value
 *  \pre         Timer must be initialized
 *  \return      Current timer value
 **********************************************************************************************************************/
vuint16 FblGetTimerValue(void)
{
   volatile vuint32 tempCount;

   /* Force 32 Bit access to timer value registers */
   tempCount = FBL_TIMER_TCRR(1u); /* PRQA S 0303 */ /* MD_FBL_0303_MemoryMappedRegAccess */

   return (vuint16)(tempCount & 0x0000FFFFuL);
}


#define FBLHW_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#endif /* FBL_ENABLE_BUSTYPE_CAN */

/***********************************************************************************************************************
 *  MEMORY HANDLING FUNCTIONS
 **********************************************************************************************************************/

#define MEMCPY_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# if defined( FBL_USE_OWN_MEMCPY )
/***********************************************************************************************************************
 *  FblOwnMemcpy
 **********************************************************************************************************************/
/*! \brief       Copies a given amount of bytes.
 *  \details     This function copies a given amount of bytes. The Bootloader watchdog handling is called during
 *               copying. Can be used instead of a compiler library memcpy if watchdog handling is needed.
 *  \param[out]  dest Pointer to destination
 *  \param[in]   source Pointer to source
 *  \param[in]   count Copy length in Byte
 *  \return      Pointer to destination
 **********************************************************************************************************************/
/* PRQA S 5013 1 */ /* MD_FblHwMpc57xx_5013 */
void* FblOwnMemcpy(void *dest, const void *source, unsigned int count)     /* PRQA S 5209 */ /* MD_FblHwMpc57xx_5209 */
{
   vuint8* localDest;
   const vuint8* localSource;
   vuint32 i;

   /* Initialize variables */
   localDest = (vuint8*)dest;                /* PRQA S 0316 */ /* MD_FblHwMpc57xx_0316_0326_VoidPtrToObj */
   localSource = (const vuint8*)source;      /* PRQA S 0316 */ /* MD_FblHwMpc57xx_0316_0326_VoidPtrToObj */

   for (i = 0u; i < count; i++)
   {
      if ((i & 0x3Fu) == 0u)
      {
         (void)FblLookForWatchdog();
      }
      localDest[i] = localSource[i];
   }

   return dest;
}
# endif /* FBL_USE_OWN_MEMCPY */
#define MEMCPY_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLHW_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/***********************************************************************************************************************
 *  FblReadByte
 **********************************************************************************************************************/
/*! \brief          This function can be used to read one byte from the given address.
 *  \param[in]      Read address.
 *  \return         Byte at memory location 'address'
 **********************************************************************************************************************/
vuint8 FblReadByte( tFblAddress address )
{
   return *(V_MEMROM1_FAR vuint8 V_MEMROM2_FAR V_MEMROM3 *)address; /* PRQA S 0306 */ /* MD_FblHwMpc57xx_0306 */
}

/***********************************************************************************************************************
 *  FblReadBlock
 **********************************************************************************************************************/
/*! \brief          This function reads a given amount of bytes from an address.
 *  \param[in]      address Memory address to read out
 *  \param[out]     buffer Target buffer
 *  \param[in]      length Number of bytes to read
 *  \return         Number of actually copied bytes
 **********************************************************************************************************************/
tFblLength FblReadBlock( tFblAddress address, vuint8 *buffer, tFblLength length )
{
   (void)MEMCPY(buffer, address, length); /* PRQA S 0314, 0326 */ /* MD_FblHwMpc57xx_0314_0326_MemCpy */
   return length;
}
#define FBLHW_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES (PLATFORM SPECIFIC)
 **********************************************************************************************************************/


/* Module specific MISRA deviations:

   MD_FblHwMpc57xx_2214:
      Reason:     This is an assertion macro used only for debugging in development (FBL_ENABLE_ASSERTION). There should
                  be no need to extend the amount of statements, so the current usage is accepted.
      Risk:       Unintended debugging code behavior could result, through adding further statements,
      Prevention: A comment is in place to avoid that further statements are added to the if condition.

   MD_FblHwMpc57xx_0306:
      Reason:     Address conversion between integer values and pointers is required to allow for hardware independent
                  configuration and address range checks.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis.

   MD_FblHwMpc57xx_0883:
      Reason:     QAC does not recognize #elif statements and concludes that the header file is not protected against
                  repeated inclusion.
      Risk:       The repeated inclusion protection is missing.
      Prevention: Correctness of repeated inclusion protection has to be verified by code inspection.

   MD_FBL_0303_MemoryMappedRegAccess:
      Reason:     Addressing memory mapped registers or other hardware specific feature requires casting a pointer type to
                  an integral type. This is a usual pattern for MCAL (Micro Controller Abstraction Layer) software.
      Risk:       Unintended read or write access into memory location.
      Prevention: Code inspection focus on correct access to expected memory location.

   MD_FblHwMpc57xx_3109:
      Reason:     Multi-line macros encapsulated in curly brackets to reduce side-effects. Results in empty statement after
                  the closing bracket.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblHwMpc57xx_5013:
      Reason:     Used types should indicate size and signedness in code. Basic types are used here because called
                  memcpy function uses these types as well.
      Risk:       Types are redefined by a different compiler.
      Prevention: Correctness has to be checked during implementation/code review.

   MD_FblHwMpc57xx_0316_0326_VoidPtrToObj:
      Reason:     Some interfaces can carry void data for generalization, that need to be casted to the right type before usage.
      Risk:       A cast to the wrong object type is done.
      Prevention: The cast shall be done in according to the carried data.

   MD_FblHwMpc57xx_0314_0326_MemCpy:
      Reason:     The copy function have a void pointer as a function parameter and an integer is casted to pointer void.
      Risk:       No risk, because the underlying pointer type is known and the cast is safe.
      Prevention: No prevention necessary.

   MD_FblHwMpc57xx_0286:
      Reason:     The character set of a certain architecture assembler contains characters which are not part of the MISRA defined
                  character set for inline assembler.
      Risk:       No identifiable risk
      Prevention: No prevention defined.

   MD_FblHwMpc57xx_5209:
      Reason:     function signature has been chosen to comply with ANSI C standard library function. The function is only used by FBL modules
      Risk:       Size of the data could be misinterpreted
      Prevention: Implementation shall care of the possible change in data size for different architecture

   MD_FblHwMpc57xx_2985_2986_RedundantOp:
      Reason:     Some operations are kept into the code, even if redundant and with no effect, for better code
                  understanding and debug improvement.
      Risk:       No risk.
      Prevention: No prevention required.

   MD_FblHwMpc57xx_3673:
     Reason: No change due to compatibility of the API.
     Risk: Data could be modified without intention.
     Prevention: Code inspection.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_HW.C
 **********************************************************************************************************************/
