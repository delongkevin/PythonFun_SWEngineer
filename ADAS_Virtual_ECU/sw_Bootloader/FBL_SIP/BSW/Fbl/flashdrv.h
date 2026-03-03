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
 *  01.00.00   2018-08-15  vistbe                   Initial version
 *  01.01.00   2020-08-12  visrie  FBL-1953         Add support for downloadable driver
 *  01.02.00   2022-01-21  visjdn  FBL-4535         Support secondary/tertiary use-case
 **********************************************************************************************************************/

#ifndef FBLDRVFLASH_ASRFLSHIS_H
#define FBLDRVFLASH_ASRFLSHIS_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Fbl_Cfg.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* Flash driver specific version information */
#define FLASH_DRIVER_VERSION_MAJOR           (tFlashUint8)(FBLWRAPPERFLASH_ASRFLSHIS_VERSION >> 8u)
#define FLASH_DRIVER_VERSION_MINOR           (tFlashUint8)(FBLWRAPPERFLASH_ASRFLSHIS_VERSION & 0xFFu)
#define FLASH_DRIVER_VERSION_PATCH           (tFlashUint8)(FBLWRAPPERFLASH_ASRFLSHIS_RELEASE_VERSION)

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Flash Driver hardware information */
#define FLASH_DRIVER_VERSION_MCUTYPE         0x5Cu
#define FLASH_DRIVER_VERSION_MASKTYPE        0x00u
#define FLASH_DRIVER_VERSION_INTERFACE       0x00u

/* Defines to access version and type information */
#define FLASH_DRIVER_MCUTYPE(flashCode)      (*(tFlashUint8*)((flashCode) + 0x03u))
#define FLASH_DRIVER_MASKTYPE(flashCode)     (*(tFlashUint8*)((flashCode) + 0x02u))
#define FLASH_DRIVER_INTERFACE(flashCode)    (*(tFlashUint8*)((flashCode) + 0x00u))

/* Flash driver is relocatable */
#define FLASH_DRIVER_RELOCATABLE

/* Minimum number of bytes that has to be programmed at a time */
#if !defined( FLASH_SEGMENT_SIZE )
# define FLASH_SEGMENT_SIZE                  256u
#endif

/* Value of deleted flash memory, usually 0xFF */
#if !defined( FBL_FLASH_DELETED )
# define FBL_FLASH_DELETED                   0xFFu

#endif
/* Common error codes */
#define kFlashOk                             0x00u /**< Function call successful */
#define kFlashFailed                         0x01u /**< Function call failed */

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

typedef unsigned short tFlashErrorCode;
typedef unsigned char  tFlashUint8;             /**< equivalent to vuint8 */
typedef unsigned long  tFlashUint32;            /**< equivalent to vuint32 */

#endif /* FBLDRVFLASH_ASRFLSHIS_H */

/***********************************************************************************************************************
 *  END OF FILE: FLASHDRV.H
 **********************************************************************************************************************/
