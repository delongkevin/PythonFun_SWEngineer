/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file          EepIo.h
 *  \brief         EEPROM Driver wrapper functions I2C EEPROM driver
 *                 for ST, Atmel and Microchip compatible I2C drivers.
 *
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
 *  01.00.00   2014-07-01  AWh     -                Creation
 *  01.01.00   2016-06-07  CEl     ESCAN00090362    Correct version numbers
 *  01.02.00   2016-11-30  DlM     ESCAN00093080    No changes
 *  01.03.00   2018-10-17  Rie     ESCAN00101020    No changes
 *                                 ESCAN00101049    No changes
 **********************************************************************************************************************/

#ifndef EEPSTM24_IO_H
#define EEPSTM24_IO_H

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblWrapperEeprom_Stm24xHis CQComponent : Implementation */
#define FBLWRAPPEREEPROM_STM24XHIS_VERSION            0x0103U
#define FBLWRAPPEREEPROM_STM24XHIS_RELEASE_VERSION    0x00U

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
#ifndef IO_DRIVERMODUS
# define IO_DRIVERMODUS  SYNCRON
#endif
#ifndef IO_DEVICETYPE
# define IO_DEVICETYPE   RANDOM
#endif

#define EepromDriver_GetVersionOfDriver()  ((vuint32)(EEPROM_DRIVER_VERSION_MAJOR << 16U)|\
                                           (vuint32)(EEPROM_DRIVER_VERSION_MINOR << 8U)|\
                                           EEPROM_DRIVER_VERSION_PATCH)

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define I2C_CHIP_SELECT_MASK     ((vuint8)((((vuint8)0x01U << I2C_CHIP_SELECT_BITS) - (vuint8)0x01U) << 1U))
#define I2C_BLOCK_SELECT_MASK    ((vuint8)((((vuint8)0x01U << I2C_BLOCK_SELECT_BITS) - (vuint8)0x01U) << (I2C_CHIP_SELECT_BITS + 1U)))
#define I2C_ADDRESS_MASK         ((vuint8)(((vuint8)0x01U << (I2C_ADDRESS_BITS - ((I2C_ADDRESS_BYTES - 1U) << 3U))) - (vuint8)0x01U))

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/

IO_ErrorType V_API_NEAR EepromDriver_InitSync( void * address );
IO_ErrorType V_API_NEAR EepromDriver_DeinitSync( void * address );
IO_ErrorType V_API_NEAR EepromDriver_RReadSync( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress );
IO_ErrorType V_API_NEAR EepromDriver_RWriteSync( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress );
IO_ErrorType V_API_NEAR EepromDriver_REraseSync( IO_SizeType eraseLength, IO_PositionType eraseAddress );
IO_ErrorType V_API_NEAR EepromDriver_VerifySync( void * address );
#endif   /* EEPSTM24_IO_H */

/***********************************************************************************************************************
 *  END OF FILE: EEPIO.H
 **********************************************************************************************************************/
