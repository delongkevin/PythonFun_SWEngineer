/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file          EepCfg.h
 *  \brief         Configuration header for I2C EEPROM driver
 *                 for ST, Atmel and Microchip compatible I2C drivers.
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Andreas Wenckebach            AWh           Vector Informatik GmbH
 *  Christopher Elkins            CEl           Vector CANtech, Inc.
 *  Daniel Moessner               DlM           Vector Informatik GmbH
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2014-06-05  AWh     -                Creation (Merge from Driver A and B, abstraction of Hw layer)
 *  01.01.00   2016-06-07  CEl     ESCAN00090362    Correct version numbers
 *  01.02.00   2016-11-30  DlM     ESCAN00093080    Added channel selection for I2C
 *  01.03.00   2018-10-17  Rie     ESCAN00101020    No changes
 *                                 ESCAN00101049    No changes
 **********************************************************************************************************************/
#ifndef EEPSTM24_CFG_H
#define EEPSTM24_CFG_H

/***********************************************************************************************************************
 * START User configuration section
 **********************************************************************************************************************/

/* Supported devices:   EEPROM_DEVICE_24XX00   (not tested) */
/*                      EEPROM_DEVICE_24XX01   (not tested) */
/*                      EEPROM_DEVICE_24XX02   (not tested) */
/*                      EEPROM_DEVICE_24XX04                */
/*                      EEPROM_DEVICE_24XX08   (not tested) */
/*                      EEPROM_DEVICE_24XX16                */
/*                      EEPROM_DEVICE_24XX32                */
/*                      EEPROM_DEVICE_24XX64                */
/*                      EEPROM_DEVICE_24XX128  (not tested) */
/*                      EEPROM_DEVICE_24XX256               */
/*                      EEPROM_DEVICE_24XX512  (not tested) */
/*                      EEPROM_DEVICE_24XX1024 (not tested) */
#define EEPROM_DEVICE_24XX256

/* The functional base address of EEPROM memory **********************************************************************/
/* Must match with entry in FlashBlock[] (apfb.c)                                                                    */
#define EEPROM_BASE_ADDRESS     0x00000000UL
/*********************************************************************************************************************/

/*********************************************************************************************************************/

/* ST M24CXX device select code **************************************************************************************/
/* depends on Chip Enable Address (E2-E0 of device)                                                                  */
#define I2C_DEVICE_SELECT_CODE  0xA0U
/*********************************************************************************************************************/

/* ST M24CXX chip select code ****************************************************************************************/
/* depends on Chip Enable Address (E2-E0 of device)                                                                  */
#define I2C_CHIP_SELECT         0x00U
/*********************************************************************************************************************/

/* Enable EEPROM erase ***********************************************************************************************/
/* The EEPROM does not need a explicit erase before                                                                  */
/* writing. In case of data consistency it could be                                                                  */
/* performed (writing ERASE_VALUE) before actual writing                                                             */
/* ENABLE_EEPROM_ERASE vs. DISABLE_EEPROM_ERASE *********************************************************************/
#define ENABLE_EEPROM_ERASE
/*********************************************************************************************************************/

#if defined( ENABLE_EEPROM_ERASE )
/* The 8 Bit value which represents erased EEPROM ********************************************************************/
/* e.g. 0xFF or 0x00                                                                                                 */
# define ERASE_VALUE            0xFFU
/*********************************************************************************************************************/
#endif

/* I2C channel selection *********************************************************************************************/
#define I2C_CHANNEL             0x00U
/*********************************************************************************************************************/

/***********************************************************************************************************************
 * END User configuration section
***********************************************************************************************************************/

/* -> Configuration below is automatic configuration, that usually does not need to be adapted */
#if defined( EEPROM_DEVICE_24XX00 )
# define I2C_BLOCK_SELECT_BITS   0U
# define I2C_CHIP_SELECT_BITS    0U
# define I2C_ADDRESS_BYTES       1U
# define I2C_ADDRESS_BITS        4U

# define EEPROM_SIZE             0x10U
# define EEPROM_PAGE_SIZE        0x01U
# define EEPROM_BLOCK_SIZE       0x10U
#endif /* EEPROM_DEVICE_24XX00 */

#if defined( EEPROM_DEVICE_24XX01 )
# define I2C_BLOCK_SELECT_BITS   0U
# define I2C_CHIP_SELECT_BITS    0U
# define I2C_ADDRESS_BYTES       1U
# define I2C_ADDRESS_BITS        7U

# define EEPROM_SIZE             0x80U
# define EEPROM_PAGE_SIZE        0x08U
# define EEPROM_BLOCK_SIZE       0x80U
#endif /* EEPROM_DEVICE_24XX01 */

#if defined( EEPROM_DEVICE_24XX02 )
# define I2C_BLOCK_SELECT_BITS   0U
# define I2C_CHIP_SELECT_BITS    0U
# define I2C_ADDRESS_BYTES       1U
# define I2C_ADDRESS_BITS        8U

# define EEPROM_SIZE             0x100U
# define EEPROM_PAGE_SIZE        0x08U
# define EEPROM_BLOCK_SIZE       0x100U
#endif /* EEPROM_DEVICE_24XX02 */

#if defined( EEPROM_DEVICE_24XX04 )
# define I2C_BLOCK_SELECT_BITS   1U
# define I2C_CHIP_SELECT_BITS    0U
# define I2C_ADDRESS_BYTES       1U
# define I2C_ADDRESS_BITS        8U

# define EEPROM_SIZE             0x200U
# define EEPROM_PAGE_SIZE        0x10U
# define EEPROM_BLOCK_SIZE       0x200U
#endif /* EEPROM_DEVICE_24XX04 */

#if defined( EEPROM_DEVICE_24XX08 )
# define I2C_BLOCK_SELECT_BITS   2U
# define I2C_CHIP_SELECT_BITS    0U
# define I2C_ADDRESS_BYTES       1U
# define I2C_ADDRESS_BITS        8U

# define EEPROM_SIZE             0x400U
# define EEPROM_PAGE_SIZE        0x10U
# define EEPROM_BLOCK_SIZE       0x400U
#endif /* EEPROM_DEVICE_24XX08 */

#if defined( EEPROM_DEVICE_24XX16 )
# define I2C_BLOCK_SELECT_BITS   3U
# define I2C_CHIP_SELECT_BITS    0U
# define I2C_ADDRESS_BYTES       1U
# define I2C_ADDRESS_BITS        8U

# define EEPROM_SIZE             0x800U
# define EEPROM_PAGE_SIZE        0x10U
# define EEPROM_BLOCK_SIZE       0x800U
#endif /* EEPROM_DEVICE_24XX16 */

#if defined( EEPROM_DEVICE_24XX32 )
# define I2C_BLOCK_SELECT_BITS   0U
# define I2C_CHIP_SELECT_BITS    3U
# define I2C_ADDRESS_BYTES       2U
# define I2C_ADDRESS_BITS        12U

# define EEPROM_SIZE             0x1000U
# define EEPROM_PAGE_SIZE        0x20U
# define EEPROM_BLOCK_SIZE       0x1000U
#endif /* EEPROM_DEVICE_24XX32 */

#if defined( EEPROM_DEVICE_24XX64 )
# define I2C_BLOCK_SELECT_BITS   0U
# define I2C_CHIP_SELECT_BITS    3U
# define I2C_ADDRESS_BYTES       2U
# define I2C_ADDRESS_BITS        13U

# define EEPROM_SIZE             0x2000U
# define EEPROM_PAGE_SIZE        0x20U
# define EEPROM_BLOCK_SIZE       0x2000U
#endif /* EEPROM_DEVICE_24XX64 */

#if defined( EEPROM_DEVICE_24XX128 )
# define I2C_BLOCK_SELECT_BITS   0U
# define I2C_CHIP_SELECT_BITS    3U
# define I2C_ADDRESS_BYTES       2U
# define I2C_ADDRESS_BITS        14U

# define EEPROM_SIZE             0x4000U
# define EEPROM_PAGE_SIZE        0x40U
# define EEPROM_BLOCK_SIZE       0x4000U
#endif /* EEPROM_DEVICE_24XX128 */

#if defined( EEPROM_DEVICE_24XX256 )
# define I2C_BLOCK_SELECT_BITS   0U
# define I2C_CHIP_SELECT_BITS    3U
# define I2C_ADDRESS_BYTES       2U
# define I2C_ADDRESS_BITS        15U

# define EEPROM_SIZE             0x8000U
# define EEPROM_PAGE_SIZE        0x40U
# define EEPROM_BLOCK_SIZE       0x8000U
#endif /* EEPROM_DEVICE_24XX256 */

#if defined( EEPROM_DEVICE_24XX512 )
# define I2C_BLOCK_SELECT_BITS   0U
# define I2C_CHIP_SELECT_BITS    3U
# define I2C_ADDRESS_BYTES       2U
# define I2C_ADDRESS_BITS        16U

# define EEPROM_SIZE             0x10000U
# define EEPROM_PAGE_SIZE        0x80U
# define EEPROM_BLOCK_SIZE       0x10000U
#endif /* EEPROM_DEVICE_24XX512 */

#if defined( EEPROM_DEVICE_24XX1024 )
# define I2C_BLOCK_SELECT_BITS   1U
# define I2C_CHIP_SELECT_BITS    2U
# define I2C_ADDRESS_BYTES       2U
# define I2C_ADDRESS_BITS        16U

# define EEPROM_SIZE             0x20000U
# define EEPROM_PAGE_SIZE        0x80U
# define EEPROM_BLOCK_SIZE       0x10000U
#endif /* EEPROM_DEVICE_24XX1024 */

#endif /* EEPSTM24_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: EEPCFG.H
 **********************************************************************************************************************/
