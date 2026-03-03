/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Flash Driver wrapper functions using an Autosar FLS driver
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
 *  01.00.00   2018-08-15  vistbe  -                Initial version
 *  01.01.00   2020-08-12  visrie  FBL-1953         Add support for downloadable driver
 *  01.02.00   2022-01-21  visjdn  FBL-4535         Support secondary/tertiary use-case
 *                                                  Added/adapted MemMap sections
 **********************************************************************************************************************/

#ifndef FBLWRAPPERFLASH_ASRFLSHIS_H
#define FBLWRAPPERFLASH_ASRFLSHIS_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblWrapperFlash_AsrFlsHis CQComponent : Implementation */
#define FBLWRAPPERFLASH_ASRFLSHIS_VERSION            0x0102u
#define FBLWRAPPERFLASH_ASRFLSHIS_RELEASE_VERSION    0x00u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FLASH_SIZE )
#else
# define FLASH_SIZE     4u
#endif

/** Determines I/O mode of driver (blocking/non-blocking) */
#define IO_DRIVERMODUS              SYNCRON
/** Type of the memory device */
#define IO_DEVICETYPE               RANDOM

#define FlashDriver_GetVersionOfDriver()  ((IO_U32)(FLASH_DRIVER_VERSION_MAJOR << 16u) |\
                                                (IO_U32)(FLASH_DRIVER_VERSION_MINOR << 8u)  |\
                                                FLASH_DRIVER_VERSION_PATCH )

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLFLIO_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
IO_ErrorType FlashDriver_InitPowerOnSync( void );
IO_ErrorType FlashDriver_InitSync( void * address );
IO_ErrorType FlashDriver_DeinitSync( void * address );
IO_ErrorType FlashDriver_RWriteSync( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress );
IO_ErrorType FlashDriver_REraseSync( IO_SizeType eraseLength, IO_PositionType eraseAddress );
IO_ErrorType FlashDriver_RReadSync( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress );
#define FBLFLIO_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define FBLFLIO_FLASHCODE_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 flashCode[FLASH_SIZE];
#define FBLFLIO_FLASHCODE_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FBLWRAPPERFLASH_ASRFLSHIS_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_FLIO.H
 **********************************************************************************************************************/
