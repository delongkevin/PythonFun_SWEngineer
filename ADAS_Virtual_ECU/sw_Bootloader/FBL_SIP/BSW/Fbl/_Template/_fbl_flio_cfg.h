/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Flash Driver wrapper functions using an Autosar FLS driver
 *
 *  \note         Please note, that this file contains an implementation/configuration example for the SPI driver.
 *                This code may influence the behavior of the SPI driver in principle. Therefore, great care must be
 *                taken to verify the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. implementation proposals.
 *                With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                admissible by law or statute.
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
 *  01.01.00   2020-08-12  visrie  FBL-1953         Add support for downloadable driver
 *  01.02.00   2022-01-21  visjdn  FBL-4535         Support secondary/tertiary use-case
 **********************************************************************************************************************/

#ifndef FBLWRAPPERFLASH_ASRFLSHIS_CFG_H
#define FBLWRAPPERFLASH_ASRFLSHIS_CFG_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Fls.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/** Specifies how often the watchdog is polled, set to 2^x (smaller value means WD is polled more often) */
#define FBL_FLASHFLS_WD_POLLING_INTERVAL        1u

/* FLS interface */
#define FBL_FLASHFLS_INITMEMORY()               /* No InitMemory available */
#define FBL_FLASHFLS_INIT()                     Fls_Init(NULL_PTR)
#define FBL_FLASHFLS_ERASE(addr, len)           Fls_Erase((addr), (len))
#define FBL_FLASHFLS_WRITE(addr, buf, len)      Fls_Write((addr), (buf), (len))
#define FBL_FLASHFLS_READ(addr, buf, len)       Fls_Read((addr), (buf), (len))
#define FBL_FLASHFLS_GETSTATUS()                Fls_GetStatus()
#define FBL_FLASHFLS_MAINFUNCTION()             Fls_MainFunction()
#define FBL_FLASHFLS_GETJOBRESULT()             Fls_GetJobResult()

#endif /* FBLWRAPPERFLASH_ASRFLSHIS_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_FLIO_CFG.H
 **********************************************************************************************************************/
