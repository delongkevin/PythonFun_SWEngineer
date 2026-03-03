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
 *                                               Added/adapted MemMap sections
 **********************************************************************************************************************/

#define FBL_I2C_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_i2c.h"
#include "fbl_i2c_cfg.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLDRVI2C_TEXASINSTRUMENTS_I2C_VERSION != 0x0100u ) || \
    ( FBLDRVI2C_TEXASINSTRUMENTS_I2C_RELEASE_VERSION != 0x00u )
# error "Error in fbl_i2c.c: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES: Registers and flags
 **********************************************************************************************************************/

#if !defined( FBL_I2C_IOS )
# define FBL_I2C_IOS(type, base, offset) (*((volatile type *)((base) + (offset))))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

/* I2C registers */
#define FBL_I2C_IRQSTATUS_RAW      FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0x24u)  /**< I2C Bus Status Register RAW (IRQSTATUS_RAW) */
#define FBL_I2C_IRQSTATUS          FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0x28u)  /**< I2C Bus Status Register (IRQSTATUS) */
#define FBL_I2C_IE                 FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0x84u)  /**< I2C Bus Interrupt Config Register (IE) */
#define FBL_I2C_BUF                FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0x94u)  /**< I2C Bus Buffer Register (BUF) */
#define FBL_I2C_CNT                FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0x98u)  /**< I2C Bus Data Count Register (CNT) */
#define FBL_I2C_DATA               FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0x9Cu)  /**< I2C Bus Data I/O Register (DATA) */
#define FBL_I2C_CON                FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0xA4u)  /**< I2C Bus Control Register (CON) */
#define FBL_I2C_OA                 FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0xA8u)  /**< I2C Bus Own Address Register (OA) */
#define FBL_I2C_SA                 FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0xACu)  /**< I2C Bus Slave Address Register (SA) */
#define FBL_I2C_PSC                FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0xB0u)  /**< I2C Bus Frequency Divider Register (PSC) */
#define FBL_I2C_SCLL               FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0xB4u)  /**< I2C Bus Bitrate Register (SCLL) */
#define FBL_I2C_SCLH               FBL_I2C_IOS(vuint32, FBL_I2C_BASE, 0xB8u)  /**< I2C Bus Bitrate Register (SCLH) */

/* I2C_CON flags */
#define FBL_I2C_CON_STT            0x00000001uL    /**< Start condition */
#define FBL_I2C_CON_STP            0x00000002uL    /**< Stop condition */
#define FBL_I2C_CON_TRX            0x00000200uL    /**< Transmit/Receive mode select bit (Transmit=1, Receive=0) */
#define FBL_I2C_CON_MST            0x00000400uL    /**< Master/Slave mode select bit (Master=1, Slave=0) */
#define FBL_I2C_CON_I2C_EN         0x00008000uL    /**< Module enable bit */
#define FBL_I2C_CON_IDIS           0x00009000uL    /**< Interrupt disable mask */

/* I2C_IRQSTATUS flags */
#define FBL_I2C_IRQSTATUS_AL       0x00000001uL    /**< Arbitration bit */
#define FBL_I2C_IRQSTATUS_NACK     0x00000002uL    /**< No acknowledgement bit */
#define FBL_I2C_IRQSTATUS_ARDY     0x00000004uL    /**< I-Bus RegisterReadReady flag bit */
#define FBL_I2C_IRQSTATUS_RRDY     0x00000008uL    /**< I-Bus DataReceiveReady flag bit */
#define FBL_I2C_IRQSTATUS_XRDY     0x00000010uL    /**< I-Bus DataTransferReady flag bit */
#define FBL_I2C_IRQSTATUS_BB       0x00001000uL    /**< Bus busy bit */

/* Default settings */
#define FBL_I2C_DEFAULT_THRESHOLD  0x00000000uL    /**< Default threshold */

/***********************************************************************************************************************
 *  DEFINES: Function like macros
 **********************************************************************************************************************/

/* Status-Flag handling */
#define FblI2cIsAckSet()                  ((FBL_I2C_IRQSTATUS_RAW & FBL_I2C_IRQSTATUS_NACK) == 0u)
#define FblI2cClearAck()                  FBL_I2C_IRQSTATUS |= FBL_I2C_IRQSTATUS_NACK
#define FblI2cIsArbitrationLost()         ((FBL_I2C_IRQSTATUS_RAW & FBL_I2C_IRQSTATUS_AL) == FBL_I2C_IRQSTATUS_AL)
#define FblI2cClearArbitrationLost()      FBL_I2C_IRQSTATUS |= FBL_I2C_IRQSTATUS_AL
#define FblI2cIsRegisterReadyForRead()    ((FBL_I2C_IRQSTATUS_RAW & FBL_I2C_IRQSTATUS_ARDY) == FBL_I2C_IRQSTATUS_ARDY)
#define FblI2cClearRegisterReady()        FBL_I2C_IRQSTATUS |= FBL_I2C_IRQSTATUS_ARDY
#define FblI2cIsReadyForTransfer()        ((FBL_I2C_IRQSTATUS_RAW & FBL_I2C_IRQSTATUS_XRDY) == FBL_I2C_IRQSTATUS_XRDY)
#define FblI2cClearReadyForTransfer()     FBL_I2C_IRQSTATUS |= FBL_I2C_IRQSTATUS_XRDY
#define FblI2cIsReadyForReceive()         ((FBL_I2C_IRQSTATUS_RAW & FBL_I2C_IRQSTATUS_RRDY) == FBL_I2C_IRQSTATUS_RRDY)
#define FblI2cClearReadyForReceive()      FBL_I2C_IRQSTATUS |= FBL_I2C_IRQSTATUS_RRDY
#define FblI2cIsBusIdle()                 ((FBL_I2C_IRQSTATUS_RAW & FBL_I2C_IRQSTATUS_BB) == 0u)

/* Start and Stop condition */
#define FblI2cSetStartCondition()         FBL_I2C_CON |= FBL_I2C_CON_STT
#define FblI2cSetStopCondition()          FBL_I2C_CON |= FBL_I2C_CON_STP
#define FblI2cTriggerStartCondition()     FBL_I2C_CON |= FBL_I2C_CON_MST
#define FblI2cTriggerStopCondition()      FBL_I2C_CON &= FblInvert32Bit(FBL_I2C_CON_MST)

/* Data register access and payload count */
#define FblI2cReadReceivedByte()          FBL_I2C_DATA
#define FblI2cSetSendByte(sendBuff)       FBL_I2C_DATA = (sendBuff)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define FblI2cSetCountByte(sendLength)    FBL_I2C_CNT = (sendLength) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Data transmission/reception */
#define FblI2cSetTransmitMode()           FBL_I2C_CON |= FBL_I2C_CON_TRX
#define FblI2cSetReceiveMode()            FBL_I2C_CON &= FblInvert32Bit(FBL_I2C_CON_TRX)

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define FBLDRVI2C_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static tFblResult   FblI2cInitCommunication( vuint32 cmdType, vuint32 cmdCtrl, vuint32 byteLength);
static tFblResult   FblI2cEndCommunication( void );
static tFblResult   FblI2cWaitForTransferReady( void );
static tFblResult   FblI2cWaitForReceiveReady( void );
static tFblResult   FblI2cSendByte( vuint32 byte, vuint32 cmdType );
static tFblResult   FblI2cReceive( vuint32 cmdCtrl, vuint32 receiveLength, V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3 * receiveBuffer );
static tFblResult   FblI2cSend( vuint32 cmdCtrl, vuint32 cmdType, vuint32 sendLength, const V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3 * sendBuffer );
static I2cStateType FblI2cCheckBusResult( vuint32 cmdType );

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/* PRQA S 0303 EOF */ /* MD_FblDrvI2c_0303 */

/***********************************************************************************************************************
 *  FblI2cInitCommunication
 **********************************************************************************************************************/
/*! \brief       Initialize I2C-bus, preparation for read or write
 *  \pre         FblI2cInit() has been called
 *  \param[in]   cmdType Transfer a const value (const byte) or a data buffer
 *  \param[in]   cmdCtrl Control byte (select device)
 *  \param[in]   byteLength Amount of data bytes to be send
 *  \return      kFblOk if successful, otherwise kFblFailed
 **********************************************************************************************************************/
static tFblResult FblI2cInitCommunication( vuint32 cmdType, vuint32 cmdCtrl, vuint32 byteLength)
{
   tFblResult result;

   while (!FblI2cIsBusIdle())
   {
      (void)FBL_I2C_WATCHDOG_FCT();
   }

   /* Set slave address for external device */
   FBL_I2C_SA = cmdCtrl;
   /* Set count of bytes to be send: */
   FblI2cSetCountByte(byteLength);

   if (cmdType == CMD_REC_BUFF)
   {
      /* Set transfer mode to receiver: */
      FblI2cSetReceiveMode();
   }
   else
   {
       /* Set transfer mode to transmitter: */
      FblI2cSetTransmitMode();
   }

   /* Generate start condition - Set to master */
   FblI2cTriggerStartCondition();

   /* Set start condition: */
   FblI2cSetStartCondition();

   /* Evaluate the result */
   switch (FblI2cCheckBusResult(cmdType))
   {
      case I2C_OK:
         result = kFblOk;
         break;
      case I2C_NACK:
         FblI2cClearAck();
         result = kFblFailed;
         break;
      case I2C_BUS_IDLE:
         result = kFblFailed;
         break;
      case I2C_ARBITRATION_LOST:
         FblI2cClearArbitrationLost();
         result = kFblFailed;
         break;
      default:
         result = kFblFailed;
         break;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblI2cEndCommunication
 **********************************************************************************************************************/
/*! \brief       Generate stop condition and wait until stop is applied
 *  \pre         Data transfer done
 *  \return      kFblOk: Bus released
 **********************************************************************************************************************/
static tFblResult FblI2cEndCommunication( void )
{
   FblI2cSetStopCondition();
   FblI2cTriggerStopCondition();  /* PRQA S 0277 */ /* MD_FblDrvI2c_0277 */
   FblI2cClearAck();
   FblI2cClearArbitrationLost();
   FblI2cClearRegisterReady();
   FblI2cClearReadyForTransfer();
   FblI2cClearReadyForReceive();
   FblI2cSetReceiveMode();

   while (!FblI2cIsBusIdle())
   {
      (void)FBL_I2C_WATCHDOG_FCT();
   }

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblI2cWaitForTransferReady
 **********************************************************************************************************************/
/*! \brief       Wait for data ready to transfer then return
 *  \pre         FblI2cInit() has been called
 *  \return      kFblOk: Ready for transfer
 **********************************************************************************************************************/
static tFblResult FblI2cWaitForTransferReady( void )
{
   do
   {
      (void)FBL_I2C_WATCHDOG_FCT();
   } while (!FblI2cIsReadyForTransfer());

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblI2cWaitForReceiveReady
 **********************************************************************************************************************/
/*! \brief       Wait for data ready to receive then return
 *  \pre         FblI2cInit() has been called
 *  \return      kFblOk: Received Data ready to read
 **********************************************************************************************************************/
static tFblResult FblI2cWaitForReceiveReady( void )
{
   do
   {
      (void)FBL_I2C_WATCHDOG_FCT();
   } while (!FblI2cIsReadyForReceive());

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblI2cSendByte
 **********************************************************************************************************************/
/*! \brief       Send byte via I2C, wait for send out byte
 *  \pre         A start condition had to be triggered
 *  \param[in]   byte Byte to send
 *  \param[in]   cmdType Transfer a const value (const byte) or a data buffer
 *  \return      kFblOk if successful, otherwise kFblFailed
 **********************************************************************************************************************/
static tFblResult FblI2cSendByte( vuint32 byte, vuint32 cmdType )
{
   tFblResult result;

   /* PRQA S 2987 1 */ /* MD_FblDrvI2c_2987 */
   (void)FblI2cWaitForTransferReady();

   FblI2cSetSendByte(byte);
   FblI2cClearReadyForTransfer();

   /* Evaluate the result */
   switch (FblI2cCheckBusResult(cmdType))
   {
      case I2C_OK:
         result = kFblOk;
         break;
      case I2C_NACK:
         FblI2cClearAck();
         result = kFblFailed;
         break;
      case I2C_BUS_IDLE:
         result = kFblFailed;
         break;
      case I2C_ARBITRATION_LOST:
         FblI2cClearArbitrationLost();
         result = kFblFailed;
         break;
      default:
         result = kFblFailed;
         break;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblI2cReceive
 **********************************************************************************************************************/
/*! \brief       Receive data bytes via I2C from external device
 *  \pre         FblI2cInit() has been called
 *  \param[in]   cmdCtrl Control byte (select device)
 *  \param[in]   receiveLength Amount of space bytes in receiveBuffer
 *  \param[out]  receiveBuffer Used to store the data which has been received over I2C
 *  \return      kFblOk if successful, otherwise kFblFailed
 **********************************************************************************************************************/
static tFblResult FblI2cReceive( vuint32 cmdCtrl, vuint32 receiveLength,
   V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3 * receiveBuffer )
{
   tFblResult result;
   vuint32 index;

   /* The device address word and data word address are already acknowledged by the external I2C device.
    * The micro controller must generate another start condition now and initiates a "current address read"
    * by sending a control byte with the read/write select bit high (iCtrl|0x01u). */

   /* STOP-Condition was already send by Hardware. Now send new start condition. */
   result = FblI2cInitCommunication(CMD_REC_BUFF, cmdCtrl, receiveLength);

   if (kFblOk == result)
   {
      for (index = 0; index < receiveLength; index++)
      {
         result = FblI2cWaitForReceiveReady();
         receiveBuffer[index] = FblI2cReadReceivedByte();
         FblI2cClearReadyForReceive();
      }

      (void)FblI2cEndCommunication();
   }

   return result;
}

/***********************************************************************************************************************
 *  FblI2cSend
 **********************************************************************************************************************/
/*! \brief       Send a byte sequence to the external device via I2C
 *  \pre         FblI2cInit() has been called
 *  \param[in]   cmdCtrl Control byte (select device) to send for acknowledge polling
 *  \param[in]   cmdType Transfer a const value (const byte) or a data buffer
 *  \param[in]   sendLength Amount of data bytes in sendBuffer
 *  \param[in]   sendBuffer Contains the data which shall be transmitted over I2C
 *  \return      kFblOk if successful, otherwise kFblFailed
 **********************************************************************************************************************/
static tFblResult FblI2cSend( vuint32 cmdCtrl, vuint32 cmdType, vuint32 sendLength,
   const V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3 * sendBuffer )
{
   tFblResult result;
   vuint32 buffIdx;
   vuint32 index;

   /* Initialize variables */
   result = kFblOk;

   /* Transmit buffer */
   for (index = 0u; (result == kFblOk) && (index < sendLength); index++)
   {
      (void)FBL_I2C_WATCHDOG_FCT();
      /* Write data: buffer or always first entry */
      buffIdx = (CMD_SEND_CONST == cmdType) ? 0u : index;
      result = FblI2cSendByte(sendBuffer[buffIdx], cmdType);
   }

   /* Always send stop signal whether sending failed or not */
   (void)FblI2cEndCommunication();

   if (kFblOk == result)
   {
      /* Start Ack polling to wait for internal data processing end of device */
      do
      {
         if (kFblOk != result)
         {
            (void)FblI2cEndCommunication();
         }

         result = FblI2cInitCommunication(CMD_SEND_BUFF, cmdCtrl, 1u);
         (void)FBL_I2C_WATCHDOG_FCT();

      } while ((kFblOk != result));

      (void)FblI2cSendByte(0x0u, cmdType); /* Required to send dummy data. Otherwise random data is sent. Result is not required. */
      (void)FblI2cEndCommunication();
   }

   return result;
}

/***********************************************************************************************************************
 *  FblI2cCheckBusResult
 **********************************************************************************************************************/
/*! \brief       Check whether bus transmission is okay within a certain period of time
 *  \pre         FblI2cInit() has been called
 *  \return      I2C_OK if successful
 *               I2C_NACK if no acknowledge condition received
 *               I2C_BUS_IDLE if unexpected bus transition from busy to idle occurred
 *               I2C_ARBITRATION_LOST if unexpected arbitration lose occurred
 **********************************************************************************************************************/
static I2cStateType FblI2cCheckBusResult( vuint32 cmdType )
{
   I2cStateType result;
   vuint32 timeout;
   result = I2C_OK;
   timeout = FBL_I2C_BUS_TIMEOUT;

   while (!FblI2cIsAckSet() || (FblI2cIsBusIdle() && (cmdType == CMD_SEND_BUFF)) || FblI2cIsArbitrationLost()
         || (timeout > FBL_I2C_BUS_MIN_WAITTIME))
   {
      if((FBL_I2C_WATCHDOG_FCT() & FBL_TM_TRIGGERED) == FBL_TM_TRIGGERED)
      {
         timeout--;
         if (timeout == 0u){
            if (!FblI2cIsAckSet())
            {
               result = I2C_NACK;
            }
            if (FblI2cIsBusIdle() && (cmdType == CMD_SEND_BUFF))
            {
               result = I2C_BUS_IDLE;
            }
            if (FblI2cIsArbitrationLost())
            {
               result = I2C_ARBITRATION_LOST;
            }
            break;
         }
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblI2cInit
 **********************************************************************************************************************/
/*! \brief       Initialize I2C module
 *  \detail      Currently implemented use case is for single transfer mode/single master environment
 *  \return      kFblOk if successful, otherwise kFblFailed
 **********************************************************************************************************************/
tFblResult FblI2cInit( void )
{
   /* Setup clock frequency - Prescaler for 12 MHz */
   FBL_I2C_PSC = FBL_I2C_PSC_VALUE;

   /* Set bitrate to 400Kbps */
   FBL_I2C_SCLL = FBL_I2C_BITRATE_SCLL_VALUE;
   FBL_I2C_SCLH = FBL_I2C_BITRATE_SCLH_VALUE;

   /* Set slave (own) address for this micro */
   FBL_I2C_OA = FBL_I2C_SLAVE_OWN_VALUE;

   /* Set the TX and RX threshold */
   FBL_I2C_BUF = FBL_I2C_DEFAULT_THRESHOLD;

   /* Disable interrupts */
   FBL_I2C_IE &= FBL_I2C_CON_IDIS;  /* PRQA S 0277 */ /* MD_FblDrvI2c_0277 */

   /* Enable I2C controller - must be the last operation; register changes no more possible */
   FBL_I2C_CON |= FBL_I2C_CON_I2C_EN;

   return kFblOk;
}

/***********************************************************************************************************************
 *  I2cDeinit
 **********************************************************************************************************************/
/*! \brief       Deinitialize I2C module
 *  \return      kFblOk if successful, otherwise kFblFailed
 **********************************************************************************************************************/
tFblResult FblI2cDeinit( void )
{
   /* Disable I2C controller */
   FBL_I2C_CON &= FblInvert32Bit(FBL_I2C_CON_I2C_EN);  /* PRQA S 0277 */ /* MD_FblDrvI2c_0277 */

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblI2cTransferSequenceSync
 **********************************************************************************************************************/
/*! \brief       Initiate serial communication over I2C module
 *  \pre         FblI2cInit() has been called
 *  \param[in]   transferParam The transfer parameter structure
 *  \return      kFblOk if successful, otherwise kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDrvI2c_3673 */
tFblResult FblI2cTransferSequenceSync( V_MEMRAM1 tFblI2cTransferParam V_MEMRAM2 V_MEMRAM3 * transferParam )
{
   tFblResult result;
   vuint32 dataLength;
   vuint8 currAddrIdx;
   vuint8 currAddrIndex;

   /* Initialize variables */
   result = kFblFailed;
   dataLength = 1u;

   if (CMD_LAST >= transferParam->cmdBuffer[kCmdOpIdx])
   {
      /* Calculate new dataLength if I2C should send data to other device */
      if (CMD_SEND_BUFF == transferParam->cmdBuffer[kCmdOpIdx])
      {
         dataLength = transferParam->sendLength;
         /* If more than one adress-byte have to be sent, calculate count of adress-bytes and add it to dataLength */
         if (transferParam->cmdLength > kCmdAddrIdx)
         {
            dataLength = transferParam->sendLength + (transferParam->cmdLength - kCmdAddrIdx);
         }
      }

      /* Initialize the I2C communication with params and calculated dataLength */
      result = FblI2cInitCommunication(CMD_SEND_BUFF, transferParam->cmdBuffer[kCmdCtrlIdx], dataLength);

      if (kFblOk == result)
      {
         /* Send all adress-bytes */
         if (transferParam->cmdLength > kCmdAddrIdx)
         {
            for (currAddrIndex = 0u; (currAddrIndex < (transferParam->cmdLength - kCmdAddrIdx)) && (kFblOk == result); currAddrIndex++)
            {
               currAddrIdx = kCmdAddrIdx + currAddrIndex;
               result = FblI2cSendByte(transferParam->cmdBuffer[currAddrIdx], transferParam->cmdBuffer[kCmdOpIdx]); /* Send address byte */
            }
         }
      }

      if (kFblOk == result)
      {
         if (CMD_REC_BUFF == transferParam->cmdBuffer[kCmdOpIdx])
         {
            /* Receive something from other device to receiveBuffer */
            result = FblI2cReceive(transferParam->cmdBuffer[kCmdCtrlIdx], transferParam->receiveLength, transferParam->receiveBuffer);
         }
         else
         {
            /* Send sendBuffer to other device */
            result = FblI2cSend(transferParam->cmdBuffer[kCmdCtrlIdx], transferParam->cmdBuffer[kCmdOpIdx], transferParam->sendLength, transferParam->sendBuffer);
         }
      }
   }

   /* Make sure I2C ends communication */
   (void)FblI2cEndCommunication();

   return result;
}

#define FBLDRVI2C_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblDrvI2c_0277:
      Reason:     Usage of FblInvert.. macros implies usage of ~ operator and appropriate casts. This includes a cast from
                  negative integer to unsigned value. The integer is only an intermediate type that occurs because of integer
                  promotion while using ~ operator, though only a bit mask is operated on.
      Risk:       No risk.
      Prevention: No prevention defined.

   MD_FblDrvI2c_0303:
      Reason:     [I] Cast between a pointer to volatile object and an integral type.
      Risk:       No identifiable risk as casts are used to define SFRs here.
      Prevention: No prevention defined.

   MD_FblDrvI2c_3673:
      Reason:     The prototype is not adapted because future code additions might use the respective parameter as output.
      Risk:       The parameter value might be changed unintentionally, thus causing malfunction in the calling instance.
      Prevention: All changes to the affected code parts have to be reviewed by the module responsible.

   MD_FblDrvI2c_2987:
      Reason:     MCU-Register access.
      Risk:       No identifiable risk.
      Prevention: No prevention defined.
*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_I2C.C
 **********************************************************************************************************************/
