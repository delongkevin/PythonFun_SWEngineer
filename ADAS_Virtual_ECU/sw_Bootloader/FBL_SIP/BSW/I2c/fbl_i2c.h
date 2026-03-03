/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Inter-Integrated Circuit Driver (Texas Instruments)
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
 *  TEMPLATE REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2015-06-12  visrie  -             Initial version
 *  01.00.01   2015-09-14  visshs  -             Minor changes
 *  01.00.02   2016-05-13  visrie  -             Minor changes
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2022-05-12  vismix  FBL-4521      Initial version
 **********************************************************************************************************************/

/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */

#ifndef FBLDRVI2C_TEXASINSTRUMENTS_I2C_H
#define FBLDRVI2C_TEXASINSTRUMENTS_I2C_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#define FBLDRVI2C_TEXASINSTRUMENTS_I2C_VERSION            0x0100u
#define FBLDRVI2C_TEXASINSTRUMENTS_I2C_RELEASE_VERSION    0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_def.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* FBL I2C driver characteristics */

#define CMD_SEND_BUFF      0u    /**< Command to send data to the device */
#define CMD_REC_BUFF       1u    /**< Command to receive data from the device */
#define CMD_SEND_CONST     2u    /**< Command to send constant data to the device */
#define CMD_LAST           CMD_SEND_CONST    /**< Always set to last defined command */

/* R/W bit information to set in control byte can be derived from command */
#define FblI2cGetRWBit(cmd)  (((cmd) & 0x01u) == 0x01u)  /* PRQA S 3453 */ /*  MD_MSR_FctLikeMacro */

/* Define command buffer offsets */
#define kCmdOpIdx          0u    /**< Offset to the operation mode in the command buffer */
#define kCmdCtrlIdx        1u    /**< Offset to the control byte (device select) in the command buffer */
#define kCmdAddrIdx        2u    /**< Offset to the read/write address in the command buffer */

/* Return codes - used for compatibility in EEPROM driver */
#define kFblI2cOk       kFblOk
#define kFblI2cFailed   kFblFailed

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/** I2c transfer parameter structure */
typedef struct
{
   /* Select different I2C modules */
   vuint8 channel;            /**< Currently not used (control byte info is part of the command) */
   vuint8 mode;               /**< Specify mode e.g. full duplex I2C (send and receive data sequentially) */

   /* Buffer and size information */
   const V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3 * cmdBuffer;   /**< Pointer to command buffer */
   vuint32 cmdLength;                                        /**< Number of bytes in command buffer */
   const V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3 * sendBuffer;  /**< Pointer to send buffer */
   vuint32 sendLength;                                       /**< Number of bytes in send buffer */
   V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3 * receiveBuffer;     /**< Pointer to receive buffer */
   vuint32 receiveLength;                                    /**< Number of bytes in receive buffer */
   vuint32 maxReceiveLength;                                 /**< (in/out) Length of output buffer */
} tFblI2cTransferParam;

/* States for Bus-transmission result */
typedef enum
{
  I2C_OK,                  /* Everything ok */
  I2C_NACK,                /* No acknowledge condition received */
  I2C_BUS_IDLE,            /* Unexpected bus transition from busy to idle */
  I2C_ARBITRATION_LOST     /* Unexpected arbitration lose */
} I2cStateType;

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

tFblResult FblI2cInit( void );
tFblResult FblI2cDeinit( void );
tFblResult FblI2cTransferSequenceSync( V_MEMRAM1 tFblI2cTransferParam V_MEMRAM2 V_MEMRAM3 * transferParam );

#endif /* FBLDRVI2C_TEXASINSTRUMENTS_I2C_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_I2C.H
 **********************************************************************************************************************/
