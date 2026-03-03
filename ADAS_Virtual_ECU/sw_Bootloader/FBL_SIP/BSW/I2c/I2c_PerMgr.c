/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*        \file   I2c_PerMgr.c
 *        \brief  I2c peripheral manager for Jacinto7
 *
 *      \details  This sub-module controls the specific I2c peripherals of the Jacinto7 platform. It takes requests for
 *                simple data transfers from the higher layers and executes them on the specific hardware. The result of
 *                a data transfer which depends on successful transmission or a detected error event is reported back to
 *                the layers above. In addition, the module offers mechanisms for the handling of error states to the
 *                layers above.
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#define I2C_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "I2c_PerMgr.h"
#include "I2c_TransProc.h"
#include "I2c_PerMgr_RegAccess_Int.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of the configuration header file */
#if (  (I2C_CFG_COMP_MAJOR_VERSION != (2u)) \
    || (I2C_CFG_COMP_MINOR_VERSION != (1u)) )
# error "Version numbers of I2c.c and I2c_Cfg.h are inconsistent!"
#endif

/* Check the version of I2c_PerMgr header file */
#if (  (I2C_SW_MAJOR_VERSION != (2u)) \
    || (I2C_SW_MINOR_VERSION != (1u)) \
    || (I2C_SW_PATCH_VERSION != (1u)) )
# error "Vendor specific version numbers of I2c_PerMgr.c and I2c_PerMgr.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define I2C_FREEBUS_CLK_EDGES        (18u)  /*!< No. of clock edges to generate 9 clock pulses to free the bus. */
#define I2C_MAX7BIT_ADDR           (0x7Fu)  /*!< Maximum address which can be addressed with 7bit addressing. */
#define I2C_FIFO_SIZE                (32u)  /*!< I2c Peripherals built-in fifo size. */
#define I2C_6BIT_MASK              (0x3Fu)  /*!< Bit mask for 6-bit buffer length. */
#define I2C_BYTES_PER_FIFO_DEPTH   (0x08u)  /*!< Bytes per fifo depth unit. */
#define I2C_1BIT_MASK              (0x01u)  /*!< 1 lsb bit mask. */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (I2C_LOCAL) /* COV_I2C_COMPATIBILITY */
# define I2C_LOCAL static
#endif

#if !defined (I2C_LOCAL_INLINE) /* COV_I2C_COMPATIBILITY */
# define I2C_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef uint32 I2c_PerMgr_HwLoopMaxType;
I2C_LOCAL I2c_PerMgr_HwLoopMaxType I2c_PerMgr_HwLoopMax = I2C_HW_LOOP_MAX;

#define I2C_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  I2c_PerMgr_GetTotalDataLength()
 *********************************************************************************************************************/
/*! \brief      Get total data length.
 *  \details    Depending on the configuration of the currently executed transfer, this function gets a total number
 *  of bytes to be transfered of all chained channels.
 *  \param[in]  hwUnitId           Index of hardware unit.
 *  \return     Total number of bytes to be transfered.
 *  \context    ISR
 *  \pre        -
 *  \reentrant  TRUE
 *********************************************************************************************************************/
I2C_LOCAL_INLINE FUNC(uint16, I2C_CODE) I2c_PerMgr_GetTotalDataLength(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 *  I2c_PerMgr_StopTrans()
 *********************************************************************************************************************/
/*! \brief      Stop a transmission.
 *  \details    Depending on the configuration of the currently executed transfer, this function generates a STOP
 *              condition on the bus, or prepares for RESTART condition (e.g. if another channel follows in a sequence).
 *  \param[in]  hwUnitId           Index of hardware unit.
 *  \context    ISR
 *  \pre        -
 *  \reentrant  TRUE
 *********************************************************************************************************************/
I2C_LOCAL_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_StopTrans(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 *  I2c_PerMgr_TxData()
 *********************************************************************************************************************/
/*! \brief      Transmits data to slave.
 *  \details    This function handles the transmission of data from a buffer to a slave device.
 *  \param[in]  hwUnitId           Index of hardware unit.
 *  \context    ISR
 *  \pre        -
 *  \reentrant  TRUE
 *********************************************************************************************************************/
I2C_LOCAL_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_TxData(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 *  I2c_PerMgr_RxData()
 *********************************************************************************************************************/
/*! \brief      Receives data from slave.
 *  \details    This function handles the reception of data from a slave device to a buffer.
 *  \param[in]  hwUnitId           Index of hardware unit.
 *  \context    ISR
 *  \pre        -
 *  \reentrant  FALSE
 *********************************************************************************************************************/
I2C_LOCAL_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_RxData(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
 *  I2c_PerMgr_DataProc()
 *********************************************************************************************************************/
/*! \brief      Decides based on the rawIrqStatus which transmission function to call.
 *  \details    Based on the rawIrqStatus calls one of the following functions: 
 *              I2c_PerMgr_ReadTrans(), I2c_PerMgr_WriteTrans(), I2c_PerMgr_StopTrans().
 *  \param[in]  hwUnitId           Id of hardware unit.
 *  \param[in]  rawIrqStatus       raw interrupt status register value.
 *  \context    ISR
 *  \pre        -
 *  \reentrant  FALSE
 *********************************************************************************************************************/
I2C_LOCAL_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_DataProc(I2c_HwUnitType hwUnitId, I2c_PerMgr_RegWidthType rawIrqStatus);

/**********************************************************************************************************************
   I2c_PerMgr_IsBusReady()
 **********************************************************************************************************************/
/*! \brief      Check if the bus status is either free or in "master busy" mode.
 *  \details    In case of a repeated start the bus status must be "master busy".
 *  \param[in]  hwUnitId           Id of the hardware unit.
 *  \return     TRUE               The bus is ready.
 *  \return     FALSE              The bus is not ready.
 *  \context    TASK
 *  \pre        -
 *  \reentrant  FALSE
 *********************************************************************************************************************/
I2C_LOCAL_INLINE FUNC(boolean, I2C_CODE) I2c_PerMgr_IsBusReady(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
   I2c_PerMgr_ResetI2cPeripheral()
 **********************************************************************************************************************/
/*! \brief      Reset I2c peripheral.
 *  \details    Tries to perform reset and returns TRUE if reset was a success.
 *  \param[in]  hwUnitId           Id of the hardware unit.
 *  \return     TRUE               Reset success.
 *  \return     FALSE              Reset fail.
 *  \context    TASK
 *  \pre        -
 *  \reentrant  FALSE
 *********************************************************************************************************************/
I2C_LOCAL FUNC(boolean, I2C_CODE) I2c_PerMgr_ResetI2cPeripheral(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
   I2c_PerMgr_CheckForReportResult()
 **********************************************************************************************************************/
/*! \brief      Check if reportResult is set and report it.
 *  \details    In case of reportResult set, change state to IDLE and report result.
 *  \param[in]  hwUnitId           Id of the hardware unit.
 *  \context    TASK | ISR
 *  \pre        -
 *  \reentrant  FALSE
 *********************************************************************************************************************/
I2C_LOCAL FUNC(void, I2C_CODE) I2c_PerMgr_CheckForReportResult(I2c_HwUnitType hwUnitId);

/**********************************************************************************************************************
   I2c_PerMgr_HandleIrqErrorCaseOrBusFreeEvent()
 **********************************************************************************************************************/
/*! \brief      Handle IRQ error case or bus free event.
 *  \details    Handle the case of NACK, Arbitration-Loss or bus free event.
 *  \param[in]  hwUnitId           Id of the hardware unit.
 *  \param[in]  rawIrqStatus       raw interrupt status register value.
 *  \context    TASK | ISR
 *  \pre        -
 *  \reentrant  FALSE
 *********************************************************************************************************************/
I2C_LOCAL_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_HandleIrqErrorCaseOrBusFreeEvent(I2c_HwUnitType hwUnitId, I2c_PerMgr_RegWidthType rawIrqStatus);



/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  I2c_PerMgr_GetTotalDataLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
I2C_LOCAL_INLINE FUNC(uint16, I2C_CODE) I2c_PerMgr_GetTotalDataLength(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_ConstPerMgrPtrType hwRuntimeDataPtr = &I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData;
  I2c_ConstTransDataPtrType transDataPtr = &I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->TransData;
  I2c_ChannelIndexType channelIndex;
  uint16 totalDataLength = 0;

  /* ----- Implementation ----------------------------------------------- */
  /* - #10 Cycle trough chained channels and accumulate channel data lengths. */
  for(channelIndex = 0u; channelIndex < transDataPtr->NumOfChannels; channelIndex++)
  {
     totalDataLength += (transDataPtr->TransBufferDesc[(hwRuntimeDataPtr->BufDescrIdx + channelIndex)].DataLength); /* SBSW_I2C_PERMGR_VALID_HWUNITID */
  }

  /* - #20 Return total accumulated data length. */
  return totalDataLength;
} /* I2c_PerMgr_GetTotalDataLength() */

/**********************************************************************************************************************
 *  I2c_PerMgr_StopTrans()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
I2C_LOCAL_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_StopTrans(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_VarHwUnitDescPtrType hwUnitDescPtr = I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr;
  I2c_TransDataPtrType transDataPtr = &hwUnitDescPtr->TransData;
  I2c_VarPerMgrPtrType hwRuntimeDataPtr = &hwUnitDescPtr->PerData;

  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQENABLE_CLR,
      (REG_MASK_IRQ_XRDY | REG_MASK_IRQ_XDR | REG_MASK_IRQ_RDR | REG_MASK_IRQ_RRDY | REG_MASK_IRQ_ARDY));

  /* ----- Implementation ----------------------------------------------- */

  /* - #10 If bus should be hold
   *         Prepare a report for channel OK. */
  transDataPtr->RepeatedStart = transDataPtr->HoldBus; /* SBSW_I2C_PERMGR_VALID_HWUNITID */

  if (transDataPtr->HoldBus == TRUE)
  {
    hwRuntimeDataPtr->Result = I2C_CH_RESULT_OK; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
    hwRuntimeDataPtr->ReportResult = TRUE; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
  }
  else
  /* - #20 Otherwise
   *         If bus is busy generate stop condition.
   */
  {
     I2c_PerMgr_Reg_SetBitMask(hwUnitId, REG_OFFSET_CON, REG_MASK_CON_STP);
  }
} /* I2c_PerMgr_StopTrans() */

/**********************************************************************************************************************
 *  I2c_PerMgr_TxData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
I2C_LOCAL_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_TxData(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_VarHwUnitDescPtrType hwUnitDescPtr = I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr;
  I2c_VarPerMgrPtrType hwRuntimeDataPtr = &hwUnitDescPtr->PerData;
  I2c_ConstTransDataPtrType transDataPtr = &hwUnitDescPtr->TransData;
  I2c_ConstTransBufferDescPtrType curTransBufferDesc = &transDataPtr->TransBufferDesc[hwRuntimeDataPtr->BufDescrIdx];
  I2c_PerMgr_RegWidthType freeFifoSpaceBytes =  /* Current available space in tx fifo (in bytes) calculated: */
    /* Fifo depth in bytes */
    ((I2c_PerMgr_RegWidthType)I2C_BYTES_PER_FIFO_DEPTH << (I2c_PerMgr_Reg_Read(hwUnitId, REG_OFFSET_BUFSTAT) >> (I2c_PerMgr_RegWidthType)REG_SHIFT_BUFSTAT_FIFODEPTH)) 
    /* minus filled bytes of tx Fifo. */
   - ((I2c_PerMgr_Reg_Read(hwUnitId, REG_OFFSET_CNT) - I2c_PerMgr_Reg_Read(hwUnitId, REG_OFFSET_BUFSTAT)) & I2C_6BIT_MASK); 

  uint32 currBufIdxMaxForThisCycle; /* Maximal allowed value of hwRuntimeDataPtr->CurBufIdx for this while loop cycle. */
  
  /* ----- Implementation ----------------------------------------------- */
  
  /* - #10 Loop until tx Fifo is filled or all channels are sent. */
  while((freeFifoSpaceBytes > 0u) && 
    (hwRuntimeDataPtr->BufDescrIdx < transDataPtr->NumOfChannels))
  {
    /* - #20 Calculate how much bytes should be sent until end of the channel or end of the free Fifo space. */
    currBufIdxMaxForThisCycle = hwRuntimeDataPtr->CurBufIdx + freeFifoSpaceBytes;
    if(currBufIdxMaxForThisCycle > curTransBufferDesc->DataLength)
    {
      currBufIdxMaxForThisCycle = curTransBufferDesc->DataLength;
    }
    freeFifoSpaceBytes -= (currBufIdxMaxForThisCycle - hwRuntimeDataPtr->CurBufIdx);
    
    /* - #30 Cyclic filling the data register. */
    while(hwRuntimeDataPtr->CurBufIdx < currBufIdxMaxForThisCycle)
    {
      I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_DATA, (uint32) curTransBufferDesc->BufPtr[hwRuntimeDataPtr->CurBufIdx]);
      hwRuntimeDataPtr->CurBufIdx++; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
    }
    
    /* - #40 Switch to the next channel if needed. */
    if(hwRuntimeDataPtr->CurBufIdx >= curTransBufferDesc->DataLength)
    {
       hwRuntimeDataPtr->CurBufIdx = 0; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
       hwRuntimeDataPtr->BufDescrIdx++; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
       curTransBufferDesc = &transDataPtr->TransBufferDesc[hwRuntimeDataPtr->BufDescrIdx];
    }
  }
} /* I2c_PerMgr_TxData() */

/**********************************************************************************************************************
 *  I2c_PerMgr_RxData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
I2C_LOCAL_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_RxData(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ----------------------------------------------------------------------------------------- */
  I2c_VarPerMgrPtrType hwRuntimeDataPtr = &I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData;
  I2c_ConstTransDataPtrType transDataPtr = &I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->TransData;
  I2c_ConstTransBufferDescPtrType curTransBufferDesc = &transDataPtr->TransBufferDesc[hwRuntimeDataPtr->BufDescrIdx];
  uint32 currBufIdxMaxForThisCycle; /* Maximal allowed value of hwRuntimeDataPtr->CurBufIdx for this while loop cycle. */
  uint32 bytesInFifo = I2C_FIFO_SIZE;

  /* ------ Implementation ----------------------------------------------------------------------------------------- */
  /* - #10 Loop until all bytes of rx Fifo are read or all channels are read. */
  while((bytesInFifo > 0u) && (hwRuntimeDataPtr->BufDescrIdx < transDataPtr->NumOfChannels))
  {
    /* - #20 Calculate how much bytes should be read until end of the bytesInFifo or end of the channel. */
    currBufIdxMaxForThisCycle = hwRuntimeDataPtr->CurBufIdx + bytesInFifo;
    if(currBufIdxMaxForThisCycle > curTransBufferDesc->DataLength)
    {
      currBufIdxMaxForThisCycle = curTransBufferDesc->DataLength;
    }
    
    bytesInFifo -= (currBufIdxMaxForThisCycle - hwRuntimeDataPtr->CurBufIdx);
    
    /* - #30 Cyclic reading the data register. */
    while(hwRuntimeDataPtr->CurBufIdx < currBufIdxMaxForThisCycle)
    {
      curTransBufferDesc->BufPtr[hwRuntimeDataPtr->CurBufIdx] = (uint8)I2c_PerMgr_Reg_Read(hwUnitId, REG_OFFSET_DATA); /* SBSW_I2C_PERMGR_VALID_HWUNITID */
      hwRuntimeDataPtr->CurBufIdx++; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
    }

    /* - #40 Switch to the next channel if needed. */
    if(hwRuntimeDataPtr->CurBufIdx >= curTransBufferDesc->DataLength)
    {
       hwRuntimeDataPtr->CurBufIdx = 0; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
       hwRuntimeDataPtr->BufDescrIdx++; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
       curTransBufferDesc = &transDataPtr->TransBufferDesc[hwRuntimeDataPtr->BufDescrIdx];
    }
  }
} /* I2c_PerMgr_RxData() */


/**********************************************************************************************************************
 *  I2c_PerMgr_DataProc()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
I2C_LOCAL_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_DataProc(I2c_HwUnitType hwUnitId, I2c_PerMgr_RegWidthType rawIrqStatus)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_ConstPerMgrPtrType hwRuntimeDataPtr = &I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData;
  I2c_ConstTransDataPtrType transDataPtr = &I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->TransData;

  /* ----- Implementation ----------------------------------------------- */
  /* - #10 If data is received
   *         Process received data. */
  if((rawIrqStatus & (REG_MASK_IRQ_RRDY | REG_MASK_IRQ_RDR)) != 0u)
  {
    I2c_PerMgr_RxData(hwUnitId);
  }
  /* - #20 If data needs to be sent
   *         Process sending data.
   */
  if((rawIrqStatus & (REG_MASK_IRQ_XRDY | REG_MASK_IRQ_XDR)) != 0u)
  {
    I2c_PerMgr_TxData(hwUnitId);

    if(hwRuntimeDataPtr->BufDescrIdx >= transDataPtr->NumOfChannels)
    {
      I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQENABLE_SET, REG_MASK_IRQ_ARDY);
      I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQENABLE_CLR, REG_MASK_IRQ_XDR | REG_MASK_IRQ_XRDY);
    }
  }
  /* - #30 Otherwise
   *         If access ready flag is detected
   *           Stop Transmission.
   */
  else if((rawIrqStatus & REG_MASK_IRQ_ARDY) != 0u)
  {
    I2c_PerMgr_StopTrans(hwUnitId);
  }
  else
  {
    /* Nothing to do. */
    /* Left empty intentionally. */
  }
} /* I2c_PerMgr_DataProc() */

/**********************************************************************************************************************
 *  I2c_PerMgr_IsBusReady()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

I2C_LOCAL_INLINE FUNC(boolean, I2C_CODE) I2c_PerMgr_IsBusReady(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------------------------------------------------- */
  I2c_ConstTransDataPtrType transDataPtr = &I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->TransData;
  I2c_PerMgr_RegWidthType statRegister = I2c_PerMgr_Reg_Read(hwUnitId, REG_OFFSET_IRQSTATUS_RAW);
  I2c_PerMgr_RegWidthType sysTest;
  boolean retVal = FALSE;

  /* ------ Implementation ----------------------------------------------------------------------------------------- */
  /* - #10 If Repeated start is set and the bus status is in "master busy" mode return TRUE. */
  if((transDataPtr->RepeatedStart == TRUE) && ((statRegister & REG_MASK_IRQ_BB) == REG_MASK_IRQ_BB))
  {
    retVal = TRUE;
  }

  /* - #20 Or both SCL and SDA lines are high return TRUE. */
  else {
    sysTest = I2c_PerMgr_Reg_Read(hwUnitId, REG_OFFSET_SYSTEST);
    if((sysTest & (REG_MASK_SYSTEST_SCL_I_FUNC | REG_MASK_SYSTEST_SDA_I_FUNC)) == (REG_MASK_SYSTEST_SCL_I_FUNC | REG_MASK_SYSTEST_SDA_I_FUNC))
    {
      retVal = TRUE;
    }
  }

  return retVal;
} /* I2c_PerMgr_IsBusReady */

/**********************************************************************************************************************
 *  I2c_PerMgr_ResetI2cPeripheral()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
I2C_LOCAL FUNC(boolean, I2C_CODE) I2c_PerMgr_ResetI2cPeripheral(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 waitCycles = 0;
  boolean resetSuccess = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* - #10 Disable I2c peripheral module. */
  I2c_PerMgr_Reg_ClearBitMask(hwUnitId, REG_OFFSET_CON, REG_MASK_CON_I2C_EN);

  /* - #20 Trigger a software reset. */
  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_SYSC, REG_MASK_SYSC_SRST);

  /* - #30 Enable I2c peripheral module. */
  I2c_PerMgr_Reg_SetBitMask(hwUnitId, REG_OFFSET_CON, REG_MASK_CON_I2C_EN);

  /* - #40 Wait till the reset is done. */
  while(((waitCycles) < I2c_PerMgr_HwLoopMax) && (resetSuccess == FALSE))
  {
    resetSuccess = I2c_PerMgr_Reg_IsBitMaskSet(hwUnitId, REG_OFFSET_SYSS, REG_MASK_SYSS_RDONE);
    waitCycles++;
  }

  return resetSuccess;
}

/**********************************************************************************************************************
 *  I2c_PerMgr_CheckForReportResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
I2C_LOCAL FUNC(void, I2C_CODE) I2c_PerMgr_CheckForReportResult(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_VarPerMgrPtrType hwRuntimeDataPtr = &I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData;
  
  /* ----- Implementation ----------------------------------------------- */
  /* - #10 If reportResult is set
   *           Change state to IDLE and report result. */
  if (hwRuntimeDataPtr->ReportResult == TRUE)
  {
    /* Attention! After reporting the result to TransProc, data shared between TransProc/PerMgr must not be manipulated
     * within this transmission. Rationale: Reporting the result may prepare the shared data structures for next trans-
     * mission. */
    SchM_Enter_I2c_I2C_PERMGR_EXCLUSIVE_AREA_0();
    hwRuntimeDataPtr->State = IDLE; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
    I2c_TransProcessor_ReportResult(hwUnitId, hwRuntimeDataPtr->Result);
    SchM_Exit_I2c_I2C_PERMGR_EXCLUSIVE_AREA_0(); 
  }
} /* I2c_PerMgr_CheckForReportResult() */

/**********************************************************************************************************************
 *  I2c_PerMgr_HandleIrqErrorCaseOrBusFreeEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
I2C_LOCAL_INLINE FUNC(void, I2C_CODE) I2c_PerMgr_HandleIrqErrorCaseOrBusFreeEvent(I2c_HwUnitType hwUnitId, I2c_PerMgr_RegWidthType rawIrqStatus)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_VarHwUnitDescPtrType hwUnitDescPtr = I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr;
  I2c_VarPerMgrPtrType hwRuntimeDataPtr = &hwUnitDescPtr->PerData;

  /* ----- Implementation ----------------------------------------------- */
  /* - #10 If NACK is detected
   *         Set result as NACK fail, clear all fifos and wait until bus free is reported.
   */
  if((rawIrqStatus & REG_MASK_IRQ_NACK) != 0u)
  {
    hwRuntimeDataPtr->Result = I2C_CH_RESULT_NACKFAIL; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
    I2c_PerMgr_Reg_WriteBits(hwUnitId, REG_OFFSET_BUF, REG_MASK_BUF_TXFIFO_CLR | REG_MASK_BUF_RXFIFO_CLR, REG_MASK_BUF_TXFIFO_CLR | REG_MASK_BUF_RXFIFO_CLR);
  }
  /* - #20 If Arbitration-Loss is detected
   *         Disable all i2c interrupts.
   *         Report Arbitration failure.
   */
  if((rawIrqStatus & REG_MASK_IRQ_AL) == REG_MASK_IRQ_AL)
  {
    I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQENABLE_CLR, REG_MASK_IRQ_ALL);
    hwRuntimeDataPtr->Result = I2C_CH_RESULT_ARBFAIL; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
  }
  /* - #30 If Bus free is detected (stop condition executed from this device)
   *         Disable all i2c interrupts and report result.
   */
  if((rawIrqStatus & REG_MASK_IRQ_BF) != 0u)
  {
    I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQENABLE_CLR, REG_MASK_IRQ_ALL);
    if(hwRuntimeDataPtr->Result != I2C_CH_RESULT_NACKFAIL)
    {
      hwRuntimeDataPtr->Result = I2C_CH_RESULT_OK; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
    }
  }

  hwRuntimeDataPtr->ReportResult = TRUE; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
} /* I2c_PerMgr_HandleIrqErrorCaseOrBusFreeEvent() */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  I2c_PerMgr_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, I2C_CODE) I2c_PerMgr_Init(I2c_HwUnitType hwUnitId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* - #10 If reset of I2c peripheral succeeds
   *         Clear and disable all I2c interrupts.
   *         Set RX and TX threshold value.
   *         Disable AUTOIDLE functionality, set IDLE state and I2c_PerMgr_HwLoopMax to I2C_HW_LOOP_MAX. */

  /* In current design there is no possibility to report errors during initialization.
   * In the case of initialization failure a bus error is reported on a call of TransData(). */

  /* Set state to uninit because it could be that it is undefined before Init. */
  (&I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData)->State = UNINIT; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
  
  if(I2c_PerMgr_ResetI2cPeripheral(hwUnitId) == TRUE)
  {
    I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQSTATUS, REG_MASK_IRQ_ALL);
    I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQENABLE_CLR, REG_MASK_IRQ_ALL);

    I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_BUF, (((I2c_PerMgr_RegWidthType)(I2C_FIFO_SIZE - 1u)) << 8u) | (I2C_FIFO_SIZE - 1u));

    I2c_PerMgr_Reg_ClearBitMask(hwUnitId, REG_OFFSET_SYSC, REG_MASK_SYSC_AUTOIDLE);
    (&I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData)->State  = IDLE; /* SBSW_I2C_PERMGR_VALID_HWUNITID */

    I2c_PerMgr_HwLoopMax = I2C_HW_LOOP_MAX;
  }
} /* I2c_PerMgr_Init() */

/**********************************************************************************************************************
 *  I2c_PerMgr_DeInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

FUNC(void, I2C_CODE) I2c_PerMgr_DeInit(I2c_HwUnitType hwUnitId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* - #10 Disable i2c module. */
  I2c_PerMgr_Reg_ClearBitMask(hwUnitId, REG_OFFSET_CON, REG_MASK_CON_I2C_EN);

  /* - #20 Set state to UNINIT. */
  (&I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData)->State = UNINIT; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
} /* I2c_PerMgr_DeInit */

/**********************************************************************************************************************
 *  I2c_PerMgr_IsHwUnitIdle()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, I2C_CODE) I2c_PerMgr_IsHwUnitIdle(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_ConstPerMgrPtrType hwRuntimeDataPtr = (&I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData);
  boolean isHwUnitIdle = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* - #10 Check if the state of hardware unit is idle. */
  if (hwRuntimeDataPtr->State == IDLE)
  {
    isHwUnitIdle = TRUE;
  }

  return isHwUnitIdle;
} /* I2c_PerMgr_IsHwUnitIdle() */

/**********************************************************************************************************************
 *  I2c_PerMgr_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

FUNC(void, I2C_CODE) I2c_PerMgr_MainFunction(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------------------------------------------------- */
  I2c_VarPerMgrPtrType hwRuntimeDataPtr = &I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData;

  /* ----- Implementation ----------------------------------------------------------------------------------------- */
  /* - #10 If hardware is busy
   *         If timeout exceeded
   *               Report BUSFAIL. */
  if(hwRuntimeDataPtr->State == BUSY)
  {
    if(hwRuntimeDataPtr->Timeout.CntVal == hwRuntimeDataPtr->Timeout.LimitVal)
    {
      hwRuntimeDataPtr->Result = I2C_CH_RESULT_BUSFAIL; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
      I2c_TransProcessor_ReportResult(hwUnitId, hwRuntimeDataPtr->Result);
    }
    hwRuntimeDataPtr->Timeout.CntVal++; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
  }
} /* I2c_PerMgr_MainFunction() */

/**********************************************************************************************************************
 *  I2c_PerMgr_FreeBus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, I2C_CODE) I2c_PerMgr_FreeBus(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_PerMgr_RegWidthType sysTestSavedMode;
  uint32 ticks = 0u;
  uint8 loopCounter = 0;
  boolean sclPinSet;

  /* ----- Implementation ----------------------------------------------- */
  SchM_Enter_I2c_I2C_PERMGR_EXCLUSIVE_AREA_0();

  sysTestSavedMode = I2c_PerMgr_Reg_Read(hwUnitId, REG_OFFSET_SYSTEST);

  /* - #10 Switch to test mode and try to send 9 clock pulses to free the bus. */
  /* Switch to system test mode */
  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_SYSTEST, REG_SYSTEST_TMODE_TEST | REG_MASK_SYSTEST_ST_EN);

  /* While System test mode is sending the clock pulses with currently configured frequency
   * try to count the edges by sensing the SCL line. If the pulses are not present stop trying
   * after I2c_PerMgr_HwLoopMax loop cycles.
   */

  do
  {
    sclPinSet = I2c_PerMgr_Reg_IsBitMaskSet(hwUnitId, REG_OFFSET_SYSTEST, REG_MASK_SYSTEST_SCL_I_FUNC);
    ticks++;
    if(sclPinSet == (boolean)(loopCounter & I2C_1BIT_MASK))
    {
      loopCounter++;
    }
  }while((loopCounter < I2C_FREEBUS_CLK_EDGES) &&
      (ticks < I2c_PerMgr_HwLoopMax));

  /* - #20 Switch back to saved mode with SDA and SCL lines pulled up. */
  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_SYSTEST, sysTestSavedMode | REG_MASK_SYSTEST_SDA_O_FUNC | REG_MASK_SYSTEST_SCL_O_FUNC);

  SchM_Exit_I2c_I2C_PERMGR_EXCLUSIVE_AREA_0();

  /* - #30 Detach bus to get clean state. */
  I2c_PerMgr_DetachBus(hwUnitId);
} /* I2c_PerMgr_FreeBus() */

/**********************************************************************************************************************
 *  I2c_PerMgr_ConfigHwUnit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, I2C_CODE) I2c_PerMgr_ConfigHwUnit(I2c_HwUnitType hwUnitId, I2c_BaudrateType baudrate,
    I2c_TimeoutType timeout)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_VarPerMgrPtrType hwRuntimeDataPtr = (&I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData);

  /* ----- Implementation ----------------------------------------------- */
  /* - #10 Disable i2c module. */
  I2c_PerMgr_Reg_ClearBitMask(hwUnitId, REG_OFFSET_CON, REG_MASK_CON_I2C_EN);
  
  /* - #20 Set registers defining the baudrate. */
  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_PSC, baudrate.PscRegValue);
  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_SCLL, baudrate.ScllRegValue);
  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_SCLH, baudrate.SclhRegValue);

  /* - #30 Enable the I2C Master for operation. */
  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_CON, REG_MASK_CON_I2C_EN | REG_MASK_CON_MST | REG_CON_OPMODE_FS);

  /* - #40 Enable free run mode (running in background on breakpoint). */
  I2c_PerMgr_Reg_SetBitMask(hwUnitId, REG_OFFSET_SYSTEST, REG_MASK_SYSTEST_FREE);
  
  /* - #50 Store timeout value. */
  hwRuntimeDataPtr->Timeout.LimitVal = timeout; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
} /* I2c_PerMgr_ConfigHwUnit() */

/**********************************************************************************************************************
 *  I2c_PerMgr_TransData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, I2C_CODE) I2c_PerMgr_TransData(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_VarHwUnitDescPtrType hwUnitDescPtr = I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr;
  I2c_VarPerMgrPtrType hwRuntimeDataPtr = &hwUnitDescPtr->PerData;
  I2c_ConstTransDataPtrType transDataPtr = &hwUnitDescPtr->TransData;
  I2c_PerMgr_RegWidthType interruptsEnableMask;

  I2c_PerMgr_RegWidthType conReg;
  uint16 totalDataLength;

  /* ----- Implementation ----------------------------------------------- */ 
  hwRuntimeDataPtr->ReportResult = TRUE; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
  hwRuntimeDataPtr->Result = I2C_CH_RESULT_BUSFAIL; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
  
  SchM_Enter_I2c_I2C_PERMGR_EXCLUSIVE_AREA_0();
  
  /* - #10 If PerMgr is not uninitialized and bus is ready
   *         Prepare the module.
   *         Reset current buffer indexes.
   *         Disable all I2c interrupts.
   *         Configure slave address.
   *         Configure interrupts.
   *         Set registers and generate start condition.
   *         Change state to BUSY.
   */
  if(hwRuntimeDataPtr->State != UNINIT)
  {
    if(I2c_PerMgr_IsBusReady(hwUnitId) == TRUE)
    {
 
      hwRuntimeDataPtr->State = BUSY; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
      
      SchM_Exit_I2c_I2C_PERMGR_EXCLUSIVE_AREA_0();
      
      /* Prepare the module. */
      /* Reset current buffer indexes. */
      hwRuntimeDataPtr->Result = I2C_CH_RESULT_OK; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
      hwRuntimeDataPtr->ReportResult = FALSE; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
      hwRuntimeDataPtr->Timeout.CntVal = 0u; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
      hwRuntimeDataPtr->BufDescrIdx = 0; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
      hwRuntimeDataPtr->CurBufIdx = 0; /* SBSW_I2C_PERMGR_VALID_HWUNITID */

      /* Disable all I2c interrupts. */
      I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQENABLE_CLR, REG_MASK_IRQ_ALL);
      conReg = REG_MASK_CON_I2C_EN | REG_MASK_CON_MST | REG_CON_OPMODE_FS | REG_MASK_CON_STT;

      /* Configure slave address. */
      /* if the slave address is 10-bit address set extended slave address bit. */
      if (transDataPtr->SlaveAddress > I2C_MAX7BIT_ADDR)
      {
        conReg |= REG_MASK_CON_XSA;
      }
      
      /* Write slave address. */
      I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_SA, transDataPtr->SlaveAddress); /* SBSW_I2C_PERMGR_VALID_HWUNITID */

      /* Get the data lengths of all chained channels and add them up. */
      totalDataLength = I2c_PerMgr_GetTotalDataLength(hwUnitId);

      /* Write total length. */
      I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_CNT, totalDataLength);
      
      /* Configure interrupts. */
      /* Clear any pending interrupts. */
      I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQSTATUS, REG_MASK_IRQ_ALL);
      
      /* Select nack, arbitration loss and bus free interrupts. */
      interruptsEnableMask = REG_MASK_IRQ_NACK | REG_MASK_IRQ_AL | REG_MASK_IRQ_BF;
      
      if(transDataPtr->TransDir == I2C_WRITE)
      {
        /* Set direction to a transmit direction. */
        conReg |= REG_MASK_CON_TRX; 
        /* Select transmit data transfer Interrupts. */
        interruptsEnableMask |=  REG_MASK_IRQ_XRDY | REG_MASK_IRQ_XDR;
      }
      else
      {
        /* Select receive data transfer and access ready interrupts. */
        interruptsEnableMask |= REG_MASK_IRQ_RRDY | REG_MASK_IRQ_RDR | REG_MASK_IRQ_ARDY;
      }

      /* Enable selected interrupts. */
      I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQENABLE_SET, interruptsEnableMask);

      /* Set configuration register together with start condition. */
      I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_CON, conReg);
      

    }
    else
    {
      SchM_Exit_I2c_I2C_PERMGR_EXCLUSIVE_AREA_0();
    }
  }
  else
  {
    SchM_Exit_I2c_I2C_PERMGR_EXCLUSIVE_AREA_0();
  }

  /* - #20 Check for report result. */
  I2c_PerMgr_CheckForReportResult(hwUnitId);
} /* I2c_PerMgr_TransData() */

/**********************************************************************************************************************
 *  I2c_PerMgr_DetachBus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

FUNC(void, I2C_CODE) I2c_PerMgr_DetachBus(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_VarPerMgrPtrType hwRuntimeDataPtr = (&I2c_ConfigPtr->HwCfgPtr[hwUnitId].varHwUnitDescPtr->PerData);

  /* ----- Implementation ----------------------------------------------- */
  /* - #10 Disable I2c peripheral module and clear fifos. */
  I2c_PerMgr_Reg_ClearBitMask(hwUnitId, REG_OFFSET_CON, REG_MASK_CON_I2C_EN);
  I2c_PerMgr_Reg_WriteBits(hwUnitId, REG_OFFSET_BUF, REG_MASK_BUF_TXFIFO_CLR | REG_MASK_BUF_RXFIFO_CLR, REG_MASK_BUF_TXFIFO_CLR | REG_MASK_BUF_RXFIFO_CLR);

  /* - #20 Clear and disable all I2c interrupts. */
  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQENABLE_CLR, REG_MASK_IRQ_ALL);
  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQSTATUS, REG_MASK_IRQ_ALL);

  /* - #30 Set Idle state and enable I2c peripheral module. */
  I2c_PerMgr_Reg_SetBitMask(hwUnitId, REG_OFFSET_CON, REG_MASK_CON_I2C_EN);
  hwRuntimeDataPtr->State = IDLE; /* SBSW_I2C_PERMGR_VALID_HWUNITID */
} /* I2c_PerMgr_DetachBus() */

/**********************************************************************************************************************
 *  I2c_PerMgr_IrqHandler()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */

FUNC(void, I2C_CODE) I2c_PerMgr_IrqHandler(I2c_HwUnitType hwUnitId)
{
  /* ----- Local Variables ---------------------------------------------- */
  I2c_PerMgr_RegWidthType rawIrqStatus;

  /* ----- Implementation ----------------------------------------------- */
  rawIrqStatus = I2c_PerMgr_Reg_Read(hwUnitId, REG_OFFSET_IRQSTATUS_RAW);
  /* - #10 If there was no error flag reported
   *         Call data procedure.
   */
   
  if((rawIrqStatus & (REG_MASK_IRQ_NACK | REG_MASK_IRQ_AL | REG_MASK_IRQ_BF)) == 0u)
  {
    I2c_PerMgr_DataProc(hwUnitId, rawIrqStatus);
  }
  /* - #20 Otherwise handle error or bus free event */
  else
  {
    I2c_PerMgr_HandleIrqErrorCaseOrBusFreeEvent(hwUnitId, rawIrqStatus);
  }

  /* - #30 Clear all processed interrupts. */
  I2c_PerMgr_Reg_Write(hwUnitId, REG_OFFSET_IRQSTATUS, rawIrqStatus);
  
  /* - #40 Check for report result. */
  I2c_PerMgr_CheckForReportResult(hwUnitId);
} /* I2c_PerMgr_IrqHandler() */

#if (I2C_POLLING_MODE == STD_ON)
/**********************************************************************************************************************
 *  I2c_PerMgr_PollingModeProcessing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, I2C_CODE) I2c_PerMgr_PollingModeProcessing(I2c_HwUnitType hwUnitId)
{
  /* ----- Implementation ----------------------------------------------- */

  /* - #10 Call I2c_PerMgr_IrqHandler();  */
  I2c_PerMgr_IrqHandler(hwUnitId);
}
#endif

/* Justification for module-specific MISRA deviations:

 */

/* SBSW_JUSTIFICATION_BEGIN
\ID SBSW_I2C_PERMGR_REGACCESS
    \DESCRIPTION Access of hardware registers depending on the configuration parameter 'I2C_PROTECTED_MODE':
                  - I2C_PROTECTED_MODE == STD_OFF: Direct register access via pointer dereferencing.
                  - I2C_PROTECTED_MODE == STD_ON: Indirect register access via OS-provided APIs.
                 The access address results from a hardware-unit-specific base address and a register-specific offset.
                 The base-address is determined from generated configuration structure using parameter 'hwUnitId', whose
                 correctness is ensured by the caller.
    \COUNTERMEASURE \S Verify that generated addresses for the I2C Bus Controller match for the used derivate.
                       SMI-973114.


\ID SBSW_I2C_PERMGR_VALID_HWUNITID
    \DESCRIPTION Write access to a pointer parameter using 'hwUnitId' or 'hwUnitDescPtr'.
    \COUNTERMEASURE \N [CM_I2C_VALID_HWUNIT]

SBSW_JUSTIFICATION_END
 */

/* START_COVERAGE_JUSTIFICATION

 \ID COV_I2C_COMPATIBILITY
   \ACCEPT XF
   \REASON [COV_MSR_COMPATIBILITY]

 END_COVERAGE_JUSTIFICATION
 */

/**********************************************************************************************************************
 *  END OF FILE: I2c_PerMgr.c
 *********************************************************************************************************************/
