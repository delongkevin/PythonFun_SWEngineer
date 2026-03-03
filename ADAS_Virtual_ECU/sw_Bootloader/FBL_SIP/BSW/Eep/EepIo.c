/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file          EepIo.c
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
 *  01.02.00   2016-11-30  DlM     ESCAN00093080    Added channel selection for I2C
 *  01.03.00   2018-10-17  Rie     ESCAN00101020    Wrong write address send to the EEPROM
 *                                 ESCAN00101049    Minor changes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "EepInc.h"

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

#if ( FBLWRAPPEREEPROM_STM24XHIS_VERSION != 0x0103U ) || \
    ( FBLWRAPPEREEPROM_STM24XHIS_RELEASE_VERSION != 0x00U )
# error "Error in eepio.c: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
/* PRQA S 3453 TAG_FblWrapperEeprom_3453_1 */ /* MD_MSR_FctLikeMacro */
#define EEP_UNINITIALISED  0x00U
#define EEP_INITIALISED    0x01U

#define EEP_CMD_BUFFER_SIZE (2U + I2C_ADDRESS_BYTES)
#define EEP_CMD_LENGTH_READ EEP_CMD_BUFFER_SIZE
#define EEP_CMD_LENGTH_SEND EEP_CMD_BUFFER_SIZE

#define EepromGetBytesToNextPage(addr) (EEPROM_PAGE_SIZE - ((addr) & (EEPROM_PAGE_SIZE - 1U)))

#if (I2C_ADDRESS_BYTES > 1U)
/* 2 byte address */
#define EepromFillCmdBuffer(buff, addr){\
                                          (buff)[kCmdCtrlIdx] = EepromDriver_GetDeviceSelect((tEepAddr)(addr));\
                                          (buff)[kCmdAddrIdx] = (vuint8)( ((addr) & 0xFF00U) >> 8U);\
                                          (buff)[kCmdAddrIdx + 1U] = (vuint8)((addr) & 0xFFU);\
                                       }
#elif (I2C_ADDRESS_BYTES > 0U)
/* 1 byte address */
#define EepromFillCmdBuffer(buff, addr){\
                                          (buff)[kCmdCtrlIdx] = EepromDriver_GetDeviceSelect((tEepAddr)(addr));\
                                          (buff)[kCmdAddrIdx] = (vuint8)( (addr) & 0xFFU);\
                                       }
#else
#define EepromFillCmdBuffer(buff, addr){\
                                          (buff)[kCmdCtrlIdx] = EepromDriver_GetDeviceSelect((tEepAddr)(addr));\
                                       }
#endif

#if (0U == EEPROM_BASE_ADDRESS)
/* This is a optimized version of the below. This avoids also compiler warnings. */
#  define EEPROM_RANGE_CONTAINED_LEN(address, length) \
    (   ((address) < EEPROM_SIZE)  \
     && ((length) <= EEPROM_SIZE)  \
     && ((address) <= (EEPROM_SIZE - (length))))
#else
#  define EEPROM_RANGE_CONTAINED_LEN(address, length) \
    (   (((address) >= EEPROM_BASE_ADDRESS) && (((address) - EEPROM_BASE_ADDRESS) < EEPROM_SIZE))  \
     && ((length) <= EEPROM_SIZE)                                                                  \
     && (((address) - EEPROM_BASE_ADDRESS) <= (EEPROM_SIZE - (length))))
# endif
/* PRQA L:TAG_FblWrapperEeprom_3453_1 */
/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/
#if ((I2C_ADDRESS_BITS + I2C_BLOCK_SELECT_BITS) > 16U)
typedef vuint32 tEepAddr;
#else
typedef vuint16 tEepAddr;
#endif

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 eepInitialised;
V_MEMRAM0 static V_MEMRAM1 tFblI2cTransferParam V_MEMRAM2 tfParam;
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 eepCmdBuffer[EEP_CMD_BUFFER_SIZE];

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/
static vuint8 EepromDriver_GetDeviceSelect( tEepAddr address );
static IO_ErrorType EepromDriver_SendI2cData( vuint8 operation, const vuint8 * dataBuffer, IO_PositionType sendAddress, IO_SizeType sendLength );

/***********************************************************************************************************************
 *   LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  EepromDriver_GetDeviceSelect
 **********************************************************************************************************************/
/*! \brief       Get Part specific Device Select byte.
 *  \detail      For some parts, part of the address information for the following command needs to be added.
 *  \param[in]   address information
 *  \return      Part specific Device Select byte
 **********************************************************************************************************************/
static vuint8 EepromDriver_GetDeviceSelect( tEepAddr address )
{
   vuint8 devSel = I2C_DEVICE_SELECT_CODE | (I2C_CHIP_SELECT & I2C_CHIP_SELECT_MASK);

#if (I2C_BLOCK_SELECT_BITS == 0U) && defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)address;
#endif

#if (I2C_BLOCK_SELECT_BITS > 0U)
   /* For some parts, part of the address need to be added to device select / control byte info */
   devSel |= ((vuint8)(address >> (I2C_ADDRESS_BITS - I2C_CHIP_SELECT_BITS - 1U)) & I2C_BLOCK_SELECT_MASK);
#endif

   return devSel;
}

/***********************************************************************************************************************
 *  EepromDriver_SendI2cData
 **********************************************************************************************************************/
/*! \brief       Send data to I2c Eeprom
 *  \detail      The data sent could either be the erased value, or data to be written
 *  \param[in]   operation  CMD_SEND_CONST / CMD_SEND_BUFF
 *  \param[in]   dataBuffer data to send
 *  \param[in]   sendLength length of data to send
 *  \param[in]   sendAddress address to send data to
 *  \return      IO_E_OK / IO_E_NOT_OK
 **********************************************************************************************************************/
static IO_ErrorType EepromDriver_SendI2cData( vuint8 operation, const vuint8 * dataBuffer, IO_PositionType sendAddress, IO_SizeType sendLength )
{
   vuint8 i2cRetVal = kFblI2cOk;
   tEepAddr currAddr = (tEepAddr)(sendAddress);
   tEepAddr totalTransLenLeft = (tEepAddr)sendLength;
   vuint16 transLen;
   vuint16 bytesToNextPage;

   /* Setup non-iterated buffer elements: command buffer operation, cmdLength */
   eepCmdBuffer[kCmdOpIdx] = operation;
   tfParam.cmdLength = EEP_CMD_LENGTH_SEND;

   while ((totalTransLenLeft > 0U) && (kFblI2cOk == i2cRetVal))
   {
      bytesToNextPage = (vuint16)EepromGetBytesToNextPage(currAddr);
      transLen = (totalTransLenLeft < bytesToNextPage) ? (vuint16)totalTransLenLeft : bytesToNextPage;

      /* Setup command buffer */
      EepromFillCmdBuffer(eepCmdBuffer, currAddr);
      tfParam.cmdBuffer = eepCmdBuffer;
      /* Setup sendBuffer (receiveBuffer unused) */
      tfParam.sendBuffer = &dataBuffer[sendLength - totalTransLenLeft];
      tfParam.sendLength = transLen;

      i2cRetVal = FblI2cTransferSequenceSync(&tfParam);

      /* Prepare next loop */
      currAddr += transLen;
      totalTransLenLeft -= transLen;
   } /* while ((totalTransLenLeft > 0U) && (Return == kFblI2cOk)) */

   return (kFblI2cOk == i2cRetVal) ? IO_E_OK : IO_E_NOT_OK;
}

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  EepromDriver_InitSync
 **********************************************************************************************************************/
/*! \brief       Initialize the Eeprom algorithm
 *  \return      The return code shows the success of the initialization
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_InitSync( void * address ) /* PRQA S 3673 */ /* MD_EepIO_3673 */
{
   vuint8 i2cRetVal = kFblI2cFailed;
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)address;
#endif

   /* Init eepInitialised as uninitialised */
   eepInitialised = EEP_UNINITIALISED;

   /* Set I2C channel */
   tfParam.channel = I2C_CHANNEL;

   /* Call EepInit to set and enable I2C module */
   if (kFblI2cOk == FblI2cInit())
   {
      i2cRetVal = kFblI2cOk;
      eepInitialised = EEP_INITIALISED;
   }

   return (kFblI2cOk == i2cRetVal) ? IO_E_OK : IO_E_NOT_OK;
}

/***********************************************************************************************************************
 *  EepromDriver_DeinitSync
 **********************************************************************************************************************/
/*! \brief       De-initialize the Eeprom algorithm
 *  \return      The return code shows the success of the de-initialization
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_DeinitSync( void * address ) /* PRQA S 3673 */ /* MD_EepIO_3673 */
{
   vuint8 i2cRetVal = kFblI2cFailed;
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)address;
#endif

   /* Call EepDeinit to disable I2C module */
   if (kFblI2cOk == FblI2cDeinit())
   {
      i2cRetVal = kFblI2cOk;
   }

   /* Set driver to uninitialized regardless of return code of FblI2cDeinit */
   eepInitialised = EEP_UNINITIALISED;

   return (kFblI2cOk == i2cRetVal) ? IO_E_OK : IO_E_NOT_OK;
}

/***********************************************************************************************************************
 *  EepromDriver_RWriteSync
 **********************************************************************************************************************/
/*! \brief       Program Eeprom by calling eeprom driver routine
 *  \pre         Eeprom driver has to be initialized
 *  \param[in]   writeBuffer Pointer to input data buffer.
 *  \param[in]   writeLength Data length.
 *  \param[in]   writeAddress Write target address ( in EEPROM memory ).
 *  \return      Status of Eeprom programming
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_RWriteSync( IO_MemPtrType writeBuffer, IO_SizeType writeLength, IO_PositionType writeAddress ) /* PRQA S 3673 */ /* MD_EepIO_3673 */
{
   IO_ErrorType retVal = IO_E_NOT_OK;
   IO_PositionType localWriteAddress;

           /* Check if the EEPROM was initialized */
   if (    (eepInitialised != EEP_INITIALISED)
            /* Check address range */
        || (!EEPROM_RANGE_CONTAINED_LEN(writeAddress, writeLength)) )
   {
      /* Do nothing */
   }
   else if (writeLength == 0U)
   {
     /* writeLength equal 0 is acceptable */
      retVal = IO_E_OK;
   }
   else
   {
      localWriteAddress = writeAddress;
#if (0U != EEPROM_BASE_ADDRESS)
      localWriteAddress -= EEPROM_BASE_ADDRESS;
#endif
      retVal = EepromDriver_SendI2cData(CMD_SEND_BUFF, writeBuffer, localWriteAddress, writeLength);
   }

   return retVal;
}

/***********************************************************************************************************************
 *  EepromDriver_REraseSync
 **********************************************************************************************************************/
/*! \brief       Erase Eeprom memory
 *  \pre         Eeprom driver has to be initialized
 *  \param[in]   eraseLength Length of memory to be erased. The length has to be aligned to the length
 *               of one or more flash sectors.
 *  \param[in]   eraseAddress Start address of erase area. The start address has to be the start
 *               address of a logical flash sector.
 *  \return      Status of Eeprom erase
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_REraseSync( IO_SizeType eraseLength, IO_PositionType eraseAddress )
{
   IO_ErrorType retVal = IO_E_NOT_OK;
#if defined( ENABLE_EEPROM_ERASE )
   IO_PositionType currentAddress;
   vuint8 erasedValBuffer[1U];
#endif
           /* Check if the EEPROM was initialized */
   if (    (eepInitialised != EEP_INITIALISED)
           /* Check address range */
        || (!EEPROM_RANGE_CONTAINED_LEN(eraseAddress, eraseLength)) )
   {
      /* Do nothing */
   }
   else if (eraseLength == 0U)
   {
      /* eraseLength equal 0 is acceptable */
      retVal = IO_E_OK;
   }
   else
   {
#if defined( ENABLE_EEPROM_ERASE )
      erasedValBuffer[0U] = ERASE_VALUE;
      for (currentAddress = eraseAddress; currentAddress < (IO_PositionType)(eraseAddress + eraseLength); currentAddress++)
      {
         retVal = EepromDriver_RWriteSync(erasedValBuffer, (IO_SizeType)1U, currentAddress);

         if (IO_E_OK != retVal)
         {
            break;
         }
      }
#else
      retVal = IO_E_OK;
#endif

   }

   return retVal;
}

/***********************************************************************************************************************
 *  EepromDriver_RReadSync
 **********************************************************************************************************************/
/*! \brief       Read Eeprom memory
 *  \pre         Eeprom driver has to be initialized
 *  \param[out]  readBuffer Pointer to read target buffer. The buffer size must be at least readLength Bytes.
 *  \param[in]   readLength Size of data to be read.
 *  \param[in]   readAddress Start address of data to be read.
 *  \return      Status of Eeprom read
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_RReadSync( IO_MemPtrType readBuffer, IO_SizeType readLength, IO_PositionType readAddress )
{
   IO_ErrorType retVal = IO_E_NOT_OK;
   IO_PositionType localReadAddress;

   /* Check if the EEPROM was initialized */
   if (    (eepInitialised != EEP_INITIALISED)
         /* Check address range */
         || (!EEPROM_RANGE_CONTAINED_LEN(readAddress, readLength)) )
   {
      /* Do nothing */
   }
   else if (readLength == 0U)
   {
      /* readLength equal 0 is acceptable */
      retVal = IO_E_OK;
   }
   else
   {
      vuint8 i2cRetVal;
      /* Setup non-iterated buffer elements: command buffer operation, cmdLength */
      eepCmdBuffer[kCmdOpIdx] = CMD_REC_BUFF;
      tfParam.cmdLength = EEP_CMD_LENGTH_READ;

      localReadAddress = readAddress;
#if (0U != EEPROM_BASE_ADDRESS)
      localReadAddress -= EEPROM_BASE_ADDRESS;
#endif

      /* Setup command buffer */
      EepromFillCmdBuffer(eepCmdBuffer, localReadAddress);
      tfParam.cmdBuffer = eepCmdBuffer;
      /* Setup receiveBuffer (sendBuffer unused) */
      tfParam.receiveBuffer = readBuffer;
      tfParam.receiveLength = readLength;

      i2cRetVal = FblI2cTransferSequenceSync(&tfParam);
      retVal = (kFblI2cOk == i2cRetVal) ? IO_E_OK : IO_E_NOT_OK;
   }

   return retVal;
}

/***********************************************************************************************************************
 *  EepromDriver_VerifySync
 **********************************************************************************************************************/
/*! \brief       verify Eeprom blocks
 *  \pre         Eeprom driver has to be initialized
 *  \param[   ]  not used; conformance to HIS Interface
 *  \return      Status of Eeprom verification
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR EepromDriver_VerifySync( void * address ) /* PRQA S 3673 */ /* MD_EepIO_3673 */
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)address;
#endif
   return IO_E_OK;
}
/***************************************************************************/
/* Plausibility of configuration                                           */
/***************************************************************************/
#if (I2C_ADDRESS_BITS > (I2C_ADDRESS_BYTES << 3U))
# error "Error in EepIO.h: I2C_ADDRESS_BITS don't fit in I2C_ADDRESS_BYTES."
#endif

#if ((I2C_BLOCK_SELECT_BITS + I2C_CHIP_SELECT_BITS) > 3U)
# error "Error in EepIO.h: I2C_BLOCK_SELECT_BITS and/or I2C_CHIP_SELECT_BITS greater than 3."
#endif

#if !defined(I2C_BLOCK_SELECT_BITS)
# error "Error in EepIO.h: I2C_BLOCK_SELECT_BITS not defined."
#endif

#if !defined(I2C_CHIP_SELECT_BITS)
# error "Error in EepIO.h: I2C_CHIP_SELECT_BITS not defined."
#endif

#if !defined(I2C_ADDRESS_BYTES)
# error "Error in EepIO.h: I2C_ADDRESS_BYTES not defined."
#endif

#if !defined(I2C_ADDRESS_BITS)
# error "Error in EepIO.h: I2C_ADDRESS_BITS not defined."
#endif

#if !defined(EEPROM_SIZE)
# error "Error in EepIO.h: EEPROM_SIZE not defined."
#endif

#if !defined(EEPROM_PAGE_SIZE)
# error "Error in EepIO.h: EEPROM_PAGE_SIZE not defined."
#endif

#if !defined(EEPROM_BLOCK_SIZE)
# error "Error in EepIO.h: EEPROM_BLOCK_SIZE not defined."
#endif

/* Module specific MISRA deviations:

   MD_EepIO_3673:
      Reason:     This interface is required by the HIS flash driver standard.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

*/
/***********************************************************************************************************************
 *  END OF FILE: EEPIO.C
 **********************************************************************************************************************/
