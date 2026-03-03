/*
*
* Copyright (c) 2020 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  \file   Fls_OSPI.c
 *
 *  \brief  OSPI  specific driver APIs implementation.
 *
 *   This file contains the driver APIs for OSPI controller.
 */


 /* ========================================================================== */
 /*                             Include Files                                  */
 /* ========================================================================== */

#include "stdint.h"
#include "Std_Types.h"
#include <ti/csl/arch/csl_arch.h>
#include "Fls_Ospi.h"
#include "Fls_Brd_Nor.h"
#include <ti/osal/osal.h>
#include <SchM_Fls.h>



/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


#define OSPI_DAC_WRITE_TIMEOUT      (500000U)
#define OSPI_CHECK_IDLE_DELAY       (10U)
#define OSPI_CALIBRATE_DELAY        (20U)
#define OSPI_XIP_SETUP_DELAY        (250U)

#define OSPI_PHY_DLL_ELEM_DELAY_PERIOD   (80U)  /* worst delay element periord in ps */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

typedef enum OSPI_intrPollMode_s
{
    SPI_OPER_MODE_POLLING,
    /**< Non interrupt based blocking mode */
    SPI_OPER_MODE_CALLBACK
    /**< Interrupt based call back mode */
} OSPI_intrPollMode;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

static Std_ReturnType    OSPI_primeTransfer(SPI_Handle handle,
                                        SPI_Transaction *transaction);
static Std_ReturnType    OSPI_waitIdle(SPI_Handle handle, uint32 timeOut);
static Std_ReturnType    OSPI_flashExecCmd(const CSL_ospi_flash_cfgRegs *pRegs);
static Std_ReturnType    OSPI_read(SPI_Handle handle, SPI_Transaction *transaction);
static Std_ReturnType    OSPI_cmdRead(const CSL_ospi_flash_cfgRegs *pRegs,
                               uint32                      cmd,
                               uint8                      *rxBuf,
                               uint32                      rxLen);
static Std_ReturnType    OSPI_cmdExtRead(const CSL_ospi_flash_cfgRegs *pRegs,
                              uint8                      *cmd,
                              uint32                      cmdLen,
                              uint8                      *rxBuf,
                              uint32                      rxLen,
                              uint32                      dummyCycles);
static Std_ReturnType    OSPI_write(SPI_Handle handle, SPI_Transaction *transaction);
static Std_ReturnType    OSPI_cmdWrite(const CSL_ospi_flash_cfgRegs *pRegs,
                                const uint8                *cmdBuf,
                                uint32                      cmdLen,
                                const uint8                *txBuf,
                                uint32                      txLen);
static Std_ReturnType    OSPI_waitReadSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                       uint32 *rdLevel);
static Std_ReturnType    OSPI_ind_xfer_mode_read(SPI_Handle handle,
                                             SPI_Transaction *transaction);
static Std_ReturnType    OSPI_waitIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs);
static Std_ReturnType    OSPI_waitWriteSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                        uint32 *sramLvl);
static Std_ReturnType    OSPI_ind_xfer_mode_write(SPI_Handle handle,
                                              SPI_Transaction *transaction);
static Std_ReturnType    OSPI_dac_xfer_mode_read(SPI_Handle handle,
                                             const SPI_Transaction *transaction);
static Std_ReturnType    OSPI_dac_xfer_mode_write(SPI_Handle handle,
                                              const SPI_Transaction *transaction);
static Std_ReturnType    OSPI_cmd_mode_write(SPI_Handle handle,
                                         const SPI_Transaction *transaction);
static Std_ReturnType    OSPI_cmd_mode_read(SPI_Handle handle,
                                        SPI_Transaction *transaction);
//static void   OSPI_configPhy(SPI_Handle handle, const void *pDelay);
static Std_ReturnType OSPI_configDdr(SPI_Handle handle, uint32 cmd, uint32 addr, uint32 data);
static boolean OSPI_waitDeviceReady(SPI_Handle handle, uint32 timeOut);


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */


#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

FLS_FUNC_TEXT_SECTION static void OSPI_delay(uint32 delay);
FLS_FUNC_TEXT_SECTION static void OSPI_delay(uint32 delay)
{
    volatile uint32 i = delay;

    while (i > 0U)
    {
        i = i - 1U;
    }
}

/*
 *  ======== OSPI_hwi ========
 *  Hwi interrupt handler to service the OSPI peripheral
 *
 *  The handler is a generic handler for a OSPI object.
 */
void OSPI_hwi(SPI_Handle handle)
{
    uint32               intrStatus;
    OSPI_Object        *object = NULL;
    OSPI_HwAttrs         *hwAttrs = NULL;
    uint32               sramLevel = 0, rdBytes = 0, wrBytes = 0;

    /* Get the pointer to the object and hwAttrs */
    object = (OSPI_Object *)(handle->object);
    hwAttrs = (OSPI_HwAttrs *)(handle->hwAttrs);

    /* Read the interrupt status register */
    intrStatus = CSL_ospiIntrStatus(hwAttrs->baseAddr);

    if (object->readBufIdx != NULL_PTR)
    {
		/* Indirect read operation */
        if ((intrStatus & CSL_OSPI_INTR_MASK_IND_XFER) != 0U)
        {
            if(object->readCountIdx != 0U)
            {
                while ((boolean)TRUE)
                {
                    sramLevel = CSL_ospiGetSramLvl(hwAttrs->baseAddr, 1U);
                    if (sramLevel == 0U)
                    {
                        break;
                    }
                    rdBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
                    rdBytes = (rdBytes > (uint32)object->readCountIdx) ? (uint32)object->readCountIdx : rdBytes;
                    /* Read data from FIFO */
                    CSL_ospiReadFifoData(hwAttrs->dataAddr, (uint8 *)object->readBufIdx, rdBytes);

                    object->readBufIdx += rdBytes;
                    object->readCountIdx -= rdBytes;

                }

                if (((uint32)object->readCountIdx > 0U) &&
                    ((uint32)object->readCountIdx < (CSL_OSPI_SRAM_WARERMARK_RD_LVL * CSL_OSPI_FIFO_WIDTH)))
                {

                    while((boolean)TRUE)
                    {
                        sramLevel = CSL_ospiGetSramLvl(hwAttrs->baseAddr, 1U);
                        rdBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
                        if (rdBytes >= object->readCountIdx)
                        {
                            break;
                        }
                    }
                    rdBytes = object->readCountIdx;
                    CSL_ospiReadFifoData(hwAttrs->dataAddr, object->readBufIdx, rdBytes);
                    object->readBufIdx += rdBytes;
                    object->readCountIdx -= rdBytes;
                }
            }

            if((object->readCountIdx == 0U) || ((intrStatus & CSL_OSPI_INTR_MASK_IND_OP_DONE) != 0U))
            {
                /* Clear indirect read operation complete status */
                CSL_ospiClrIndReadComplete(hwAttrs->baseAddr);

                /* disable and clear the interrupts */
                CSL_ospiIntrEnable(hwAttrs->baseAddr,
                                    CSL_OSPI_INTR_MASK_ALL,
                                    FALSE);
                CSL_ospiIntrClear(hwAttrs->baseAddr,
                                  CSL_OSPI_INTR_MASK_ALL);

                object->transaction = NULL;

                if (Fls_DrvObj.length != 0U)
                {
                    processJobs(Fls_DrvObj.jobType);
                }
            }
            else
            {
                /* Clear interrupt status */
                CSL_ospiIntrClear(hwAttrs->baseAddr, intrStatus);
            }
        }
    }
    else
    {
		/* Indirect write operation */
        if ((intrStatus & CSL_OSPI_INTR_MASK_IND_XFER) != 0U)
        {
            if (object->writeCountIdx != 0U)
            {
                sramLevel = CSL_OSPI_SRAM_PARTITION_WR - \
                            CSL_ospiGetSramLvl(hwAttrs->baseAddr, 0U);

                wrBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
                wrBytes = (wrBytes > object->writeCountIdx) ? object->writeCountIdx : wrBytes;

                /* Write data to FIFO */
                CSL_ospiWriteFifoData(hwAttrs->dataAddr, object->writeBufIdx, wrBytes);

                object->writeBufIdx += wrBytes;
                object->writeCountIdx -= wrBytes;

                sramLevel = CSL_OSPI_SRAM_PARTITION_WR - \
                            CSL_ospiGetSramLvl(hwAttrs->baseAddr, 0U);

                if ((object->writeCountIdx > 0U) &&
                    (object->writeCountIdx <= (sramLevel * CSL_OSPI_FIFO_WIDTH)))
                {
                    wrBytes = object->writeCountIdx;
                    CSL_ospiWriteFifoData(hwAttrs->dataAddr, object->writeBufIdx, wrBytes);
                    object->writeBufIdx += wrBytes;
                    object->writeCountIdx -= wrBytes;
                }
            }

            if ((intrStatus & CSL_OSPI_INTR_MASK_IND_OP_DONE) != 0U)
            {
                /* Clear indirect write operation complete status */
                CSL_ospiClrIndWriteComplete(hwAttrs->baseAddr);

                /* disable and clear the interrupts */
                CSL_ospiIntrEnable(hwAttrs->baseAddr,
                                    CSL_OSPI_INTR_MASK_ALL,
                                    FALSE);
                CSL_ospiIntrClear(hwAttrs->baseAddr,
                                  CSL_OSPI_INTR_MASK_ALL);
                object->transaction = NULL;

                if (Fls_DrvObj.length != 0U)
                {
                    processJobs(Fls_DrvObj.jobType);
                }
            }
            else
            {
                /* Clear interrupt status */
                CSL_ospiIntrClear(hwAttrs->baseAddr, intrStatus);
            }
        }
    }
}

/*
 *  ======== OSPI_close ========
 */
FLS_FUNC_TEXT_SECTION void OSPI_close(SPI_Handle handle)
{
    OSPI_Object        *object = NULL;
    OSPI_HwAttrs const *hwAttrs = NULL;

    if (handle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        object = (OSPI_Object *)handle->object;
        hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;

        /* disable the interrupts */
        CSL_ospiIntrEnable(hwAttrs->baseAddr,
                        CSL_OSPI_INTR_MASK_ALL,
                        FALSE);

        /* Open flag is set FALSE */
        object->isOpen = FALSE;
    }

    return;
}

/*
 *  ======== OSPI_init ========
 */
FLS_FUNC_TEXT_SECTION void OSPI_init(SPI_Handle handle)
{
    if (handle != NULL)
    {
        /* Mark the object as available */
        OSPI_Object *ospi_Obj;
        ospi_Obj = (OSPI_Object *)(handle->object);
        ospi_Obj->isOpen = FALSE;
    }
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_waitIdle(SPI_Handle handle, uint32 timeOut)
{
    OSPI_HwAttrs const *hwAttrs;      /* OSPI hardware attributes */
    uint32               retry = 0U;
    Std_ReturnType     retVal = E_NOT_OK;
    uint32               timeOutVal = timeOut;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;

    while (timeOutVal != 0U)
    {
        if (CSL_ospiIsIdle(hwAttrs->baseAddr) != 0U)
        {
            retry++;
            if (retry == 3U)
            {
                retVal = E_OK;
                break;
            }
        }
        else
        {
            retry = 0U;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        timeOutVal--;
    }

    return (retVal);
}

#if 0
/*
 *  ======== OSPI_configPhy ========
 */
FLS_FUNC_TEXT_SECTION static void OSPI_configPhy(SPI_Handle handle, const void *pDelay)
{
    OSPI_HwAttrs const   *hwAttrs = NULL;
    uint32                 numDelayElems;

    /* Get the pointer to the hwAttrs */
    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;
    numDelayElems = (1000000U / (hwAttrs->funcClk / 1000000U)) / OSPI_PHY_DLL_ELEM_DELAY_PERIOD;
    CSL_ospiConfigPhy(hwAttrs->baseAddr,
                      numDelayElems,
                      (const uint32 *)pDelay);
    OSPI_delay(OSPI_CALIBRATE_DELAY);
}
#endif

/*
 *  ======== OSPI_open ========
 */
FLS_FUNC_TEXT_SECTION SPI_Handle OSPI_open(SPI_Handle handle, const SPI_Params *params)
{
    SPI_Handle               retHandle = handle;
    OSPI_Object              *object = NULL;
    OSPI_HwAttrs const       *hwAttrs = NULL;
    sint32                    retFlag = 0;
    uint32                numAddrBytes;

    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_0();
    if (NULL == handle)
    {
        retHandle = NULL; /*if SPI handle is NULL, return NULL*/
    }
    else /*if handle != NULL*/
    {
        /* Get the pointer to the object and hwAttrs */
        object = (OSPI_Object *)handle->object;
        hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;
        if (object->isOpen == TRUE)
        {
            retHandle = NULL;
        }
        else
        {
            /* Mark the handle as being used */
            object->isOpen = TRUE;
        }
    }
    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_0();

    if (retHandle != NULL)
    {
        SPI_Params_init(&(object->ospiParams)); /*Use default SPI params*/

        /* Copy the controller mode from hardware attributes to object */
        object->ospiMode  = (uint32)hwAttrs->operMode;
        object->xferLines = (uint32)hwAttrs->xferLines;
        object->hwi       = NULL;

        /* Extract OSPI operating mode based on hwAttrs and input parameters */
#if (STD_ON == FLS_USE_INTERRUPTS)//callback interrupt mode
        object->intrPollMode = (uint32)SPI_OPER_MODE_CALLBACK;
#else
        object->intrPollMode = (uint32)SPI_OPER_MODE_POLLING;
#endif

        object->transaction = NULL;
        /* Disable DAC */
        CSL_ospiDacEnable(hwAttrs->baseAddr, FALSE);

        /* Disable DTR protocol */
        CSL_ospiDtrEnable(hwAttrs->baseAddr, FALSE);

        if (hwAttrs->xipEnable == FALSE)
        {
            /* Disable XIP */
            CSL_ospiXipEnable(hwAttrs->baseAddr, FALSE);
        }

        /* Disable OSPI controller */
        CSL_ospiEnable(hwAttrs->baseAddr, FALSE);

        /* Wait until Serial Interface and OSPI pipeline is IDLE. */
        if (OSPI_waitIdle(handle, OSPI_DAC_WRITE_TIMEOUT) != E_OK)
        {
            OSPI_close(handle);
            retHandle = NULL;
            retFlag = 1;
        }

        if(retFlag == 0)
        {
            /* Chip select setup */
            CSL_ospiSetChipSelect(hwAttrs->baseAddr,
                                  hwAttrs->chipSelect,
                                  CSL_OSPI_DECODER_SELECT4);

            /* Set clock mode */
            CSL_ospiSetClkMode(hwAttrs->baseAddr,
                               hwAttrs->frmFmt);

            /* Disable the adapted loopback clock circuit */
            CSL_ospiLoopbackClkEnable(hwAttrs->baseAddr,
                                      FALSE);

            /* Delay Setup */
            CSL_ospiSetDevDelay(hwAttrs->baseAddr,
                                hwAttrs->devDelays);

            if (hwAttrs->baudRateDiv != 0)
            {
                CSL_ospiSetPreScaler(hwAttrs->baseAddr,
                                     CSL_OSPI_BAUD_RATE_DIVISOR(hwAttrs->baudRateDiv));
            }
            else
            {
                /* Set default baud rate divider value */
                if (hwAttrs->phyEnable == TRUE)
                {
                    CSL_ospiSetPreScaler(hwAttrs->baseAddr,
                                         CSL_OSPI_BAUD_RATE_DIVISOR(2U));
                }
                else
                {
                    /* Disable high speed mode when PHY is disabled */
                    CSL_ospiSetPreScaler(hwAttrs->baseAddr,
                                         CSL_OSPI_BAUD_RATE_DIVISOR_DEFAULT);
                }
            }

            if (hwAttrs->phyEnable == TRUE)
            {
                /* Enable PHY mode */
                CSL_ospiPhyEnable(hwAttrs->baseAddr, TRUE);

            }
            else
            {
                /* Disable PHY mode */
                CSL_ospiPhyEnable(hwAttrs->baseAddr, FALSE);
            }

            /* Disable PHY pipeline mode */
            CSL_ospiPipelinePhyEnable(hwAttrs->baseAddr, FALSE);

            if (hwAttrs->dtrEnable == TRUE)
            {
                numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_4;
            }
            else
            {
                numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_3;
            }

            /* Set device size cofigurations */
            CSL_ospiSetDevSize(hwAttrs->baseAddr,
                               numAddrBytes,
                               hwAttrs->pageSize,
                               hwAttrs->blkSize);

            /* Set indirect trigger address register */
            if (hwAttrs->dacEnable == TRUE)
            {
                CSL_ospiSetIndTrigAddr(hwAttrs->baseAddr,
                                       0x4000000);
            }
            else
            {
                CSL_ospiSetIndTrigAddr(hwAttrs->baseAddr,
                                       0);
            }

            /* Disable write completion auto polling */
            CSL_ospiSetWrCompAutoPolling(hwAttrs->baseAddr,
                                         CSL_OSPI_WRITE_COMP_AUTO_POLLING_ENABLE);

            /* Set SRAM partition configuration */
            CSL_ospiSetSramPartition(hwAttrs->baseAddr,
                                     CSL_OSPI_SRAM_PARTITION_DEFAULT);

            /* disable and clear the interrupts */
            CSL_ospiIntrEnable(hwAttrs->baseAddr,
                                CSL_OSPI_INTR_MASK_ALL,
                                FALSE);
            CSL_ospiIntrClear(hwAttrs->baseAddr,
                              CSL_OSPI_INTR_MASK_ALL);

            if (hwAttrs->dacEnable == TRUE)
            {
                CSL_ospiDacEnable(hwAttrs->baseAddr, TRUE);
            }
            else
            {
                CSL_ospiDacEnable(hwAttrs->baseAddr, FALSE);
            }

            CSL_ospiSetDataReadCapDelay(hwAttrs->baseAddr,
                                        hwAttrs->rdDataCapDelay);
            CSL_ospiSetCsSotDelay(hwAttrs->baseAddr,
                                  hwAttrs->csSotDelay);
            /* Enable OSPI controller */
            CSL_ospiEnable(hwAttrs->baseAddr, TRUE);
        }
    }

    return(retHandle);
}

/*
 *  ======== OSPI_primeTransfer =======
 */
FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_primeTransfer(SPI_Handle handle,
                                     SPI_Transaction *transaction)
{
    OSPI_Object        *object = NULL;
    OSPI_HwAttrs const *hwAttrs = NULL;
    Std_ReturnType      retVal = E_OK;

    /* Get the pointer to the object and hwAttrs */
    object = (OSPI_Object *)handle->object;
    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;

    /* Disable and clear the interrupts */
    CSL_ospiIntrEnable(hwAttrs->baseAddr,
                        CSL_OSPI_INTR_MASK_ALL,
                        FALSE);
    CSL_ospiIntrClear(hwAttrs->baseAddr,
                      CSL_OSPI_INTR_MASK_ALL);

#if (STD_ON == FLS_USE_INTERRUPTS)
    CSL_ospiIntrEnable(hwAttrs->baseAddr,
                   CSL_OSPI_INTR_MASK_ALL,
                   TRUE);

#endif

    /* Identify the direction of transfer (whether read/write) */
    if((uint32)SPI_TRANSACTION_TYPE_READ == object->transactionType)
    {
        retVal = (OSPI_read(handle, transaction));
    }
    else if((uint32)SPI_TRANSACTION_TYPE_WRITE == object->transactionType)
    {
        retVal = (OSPI_write(handle, transaction));
    }
    else
    {
        transaction->status = SPI_TRANSFER_CANCELED;
		retVal = E_NOT_OK;
    }
    return(retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_waitReadSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                    uint32 *rdLevel)
{
    uint32 retry = OSPI_DAC_WRITE_TIMEOUT;
    uint32 sramLevel;
    Std_ReturnType  retVal;
    while(retry != 0U)
    {
        sramLevel = CSL_ospiGetSramLvl(pReg, 1U);
        if (sramLevel != 0U)
        {
            *rdLevel = sramLevel;
            break;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        retry--;
    }

    if (retry != 0U)
    {
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return(retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_waitIndReadComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32 retry = OSPI_DAC_WRITE_TIMEOUT;
    Std_ReturnType  retVal;

    /* Check flash indirect read controller status */
    while (retry != 0U)
    {
        if (CSL_ospiIndReadComplete(pRegs) == TRUE)
        {
            break;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        retry--;
    }
    if (retry != 0U)
    {
        /* Clear indirect completion status */
        CSL_ospiClrIndReadComplete(pRegs);
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return(retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_ind_xfer_mode_read(SPI_Handle handle,
                                          SPI_Transaction *transaction)
{
    OSPI_HwAttrs const *hwAttrs;      /* OSPI hardware attributes */
    OSPI_Object        *object;       /* OSPI object */
    uint8               *pDst;         /* Destination address */
    uint32               count;        /* transaction length */
    uint32               offset;       /* OSPI flash offset address */
    uint32               remaining;
    uint32               sramLevel = 0, rdBytes = 0;
    uint32               retFlag = 0U;
    Std_ReturnType                retVal = E_OK;

    /* Copy flash transaction parameters to local variables */
    offset = (uint32)(transaction->arg); /* NOR Flash offset address to read */
    pDst = (uint8 *)transaction->rxBuf;
    count = (uint32)transaction->count;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;
    object = (OSPI_Object *)handle->object;

    /* Disable DAC mode */
    CSL_ospiDacEnable(hwAttrs->baseAddr, FALSE);

    if (hwAttrs->phyEnable == TRUE)
    {
        /* Enable PHY pipeline mode for read */
        CSL_ospiPipelinePhyEnable(hwAttrs->baseAddr, TRUE);
    }

    /* Set read address in indirect mode */
    CSL_ospiIndSetStartAddr(hwAttrs->baseAddr,
                            offset,
                            TRUE);
    CSL_ospiIndReadExecute(hwAttrs->baseAddr, count);
    if ((uint32)SPI_OPER_MODE_POLLING == object->intrPollMode)
    {
        remaining = count;
        while(remaining > 0U)
        {
            /* Wait indirect read SRAM fifo has data */
            if (OSPI_waitReadSramLvl(hwAttrs->baseAddr,
                                     &sramLevel) != E_OK)
            {
                retFlag = 1U;
                retVal = E_NOT_OK;
                transaction->status=SPI_TRANSFER_FAILED;
                break;
            }

            rdBytes = sramLevel * CSL_OSPI_FIFO_WIDTH;
            rdBytes = (rdBytes > remaining) ? remaining : rdBytes;
            /* Read data from FIFO */
            CSL_ospiReadFifoData(hwAttrs->dataAddr, pDst, rdBytes);

            pDst += rdBytes;
            remaining -= rdBytes;

        }
        if(retFlag == 0U)
        {
            if (OSPI_waitIndReadComplete(hwAttrs->baseAddr) != E_OK)
            {
                retVal = E_NOT_OK;
                transaction->status=SPI_TRANSFER_FAILED;
            }
        }
    }
#if defined (aarch64) || ((__ARM_ARCH == 7) && (__ARM_ARCH_PROFILE == R))
    CSL_archMemoryFence();
#endif

    return (retVal);
}

static uint32 OSPI_getDeviceStatus(SPI_Handle handle);
FLS_FUNC_TEXT_SECTION static uint32 OSPI_getDeviceStatus(SPI_Handle handle)
{
    OSPI_HwAttrs const *hwAttrs; /* OSPI hardware attributes */
    OSPI_Object        *object;  /* OSPI object */
    uint8                status = 0xff;

    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;
    object = (OSPI_Object *)handle->object;

    (void)OSPI_cmdRead(hwAttrs->baseAddr,
                       object->rdStatusCmd,
                       &status,
                       1);

    return (status);
}

FLS_FUNC_TEXT_SECTION static boolean OSPI_waitDeviceReady(SPI_Handle handle, uint32 timeOut)
{
    boolean         retVal = FALSE;
    uint32      status;
    uint32     timeOutVal = timeOut;

    while (timeOutVal != 0U)
    {
        status = OSPI_getDeviceStatus(handle);
        if ((status & 1U) == 0U)
        {
            retVal = TRUE;
            break;
        }
        timeOutVal--;
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
    }

    return (retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_dac_xfer_mode_read(SPI_Handle handle,
                                          const SPI_Transaction *transaction)
{
    OSPI_HwAttrs const *hwAttrs;      /* OSPI hardware attributes */
    uint8               *pSrc;         /* Source address */
    uint8               *pDst;         /* Destination address */
    uint32               offset;       /* OSPI flash offset address */
    uint32               i;
    uint32               size;
    uint32               remainSize;

    /* Copy flash transaction parameters to local variables */
    offset = (uint32)(transaction->arg); /* OSPI Flash offset address to read */
    pDst = (uint8 *)transaction->rxBuf;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;

    /* Disable PHY pipeline mode for read since we are not using DMA*/
    CSL_ospiPipelinePhyEnable(hwAttrs->baseAddr, FALSE);

    pSrc = (uint8 *)(hwAttrs->dataAddr + offset);
    remainSize = (uint32)transaction->count & 3U;
    size = (uint32)transaction->count - remainSize;
    /* Transfer the data in 32-bit size */
    for (i = 0U; i < size; i += 4U)
    {
        CSL_REG32_WR(pDst + i, CSL_REG32_RD(pSrc + i));
#if defined (__aarch64__)
        CSL_archMemoryFence();
#endif
    }
    /* Transfer the remaining data in 8-bit size */
    for (i = 0; i < remainSize; i++)
    {
        CSL_REG8_WR(pDst + size + i, CSL_REG8_RD(pSrc + size + i));
#if defined (__aarch64__)
        CSL_archMemoryFence();
#endif
    }

    return E_OK;
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_flashExecCmd(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32 retry = OSPI_DAC_WRITE_TIMEOUT;
    Std_ReturnType  retVal = E_OK;
    uint32 idleFlag = FALSE;

    while (idleFlag == FALSE)
    {
        idleFlag = CSL_ospiIsIdle(pRegs);
    }

    /* Start to execute flash read/write command */
    CSL_ospiFlashExecCmd(pRegs);

    while (retry != 0U)
    {
        /* Check the command execution status */
        if (CSL_ospiFlashExecCmdComplete(pRegs) == TRUE)
        {
            break;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        retry--;
    }

    if (retry == 0U)
    {
        retVal = E_NOT_OK;
    }

    idleFlag = FALSE;
    while (idleFlag == FALSE)
    {
        idleFlag = CSL_ospiIsIdle(pRegs);
    }

    return (retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_cmdRead(const CSL_ospi_flash_cfgRegs *pRegs,
                            uint32                      cmd,
                            uint8                      *rxBuf,
                            uint32                      rxLen)
{
    uint32 regVal;
    uint32 rdLen;
    Std_ReturnType  retVal;
    uint8 *pBuf = rxBuf;

    (void)CSL_ospiCmdRead(pRegs, cmd, rxLen);
    retVal = OSPI_flashExecCmd(pRegs);
    if (retVal == E_OK)
    {
        regVal = CSL_REG32_RD(&pRegs->FLASH_RD_DATA_LOWER_REG);

        /* Put the read value into rxBuf */
        rdLen = (rxLen > 4U) ? 4U : rxLen;
        (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen);
        pBuf += rdLen;

        if (rxLen > 4U) {
            regVal = CSL_REG32_RD(&pRegs->FLASH_RD_DATA_UPPER_REG);
            rdLen = rxLen - rdLen;
            (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen);
        }
    }
    return (retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_cmdExtRead(const CSL_ospi_flash_cfgRegs *pRegs,
                              uint8                      *cmd,
                              uint32                      cmdLen,
                              uint8                      *rxBuf,
                              uint32                      rxLen,
                              uint32                      dummyCycles)
{
    uint32 regVal;
    uint32 rdLen;
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 *pBuf = rxBuf;

    (void)CSL_ospiCmdExtRead(pRegs, cmd, cmdLen, rxLen, dummyCycles);
    retVal = OSPI_flashExecCmd(pRegs);
    if (retVal == E_OK)
    {
        regVal = CSL_REG32_RD(&pRegs->FLASH_RD_DATA_LOWER_REG);

        /* Put the read value into rxBuf */
        rdLen = (rxLen > 4U) ? 4U : rxLen;
        (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen);
        pBuf += rdLen;

        if (rxLen > 4U) {
            regVal = CSL_REG32_RD(&pRegs->FLASH_RD_DATA_UPPER_REG);
            rdLen = rxLen - rdLen;
            (void)memcpy((void *)pBuf, (void *)(&regVal), rdLen);
        }
    }
    return (retVal);

}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_cmd_mode_read(SPI_Handle handle,
                                     SPI_Transaction *transaction)
{
    OSPI_HwAttrs const *hwAttrs;    /* OSPI hardware attributes */
    uint8               *cmd;
    OSPI_Object *object;
    Std_ReturnType retVal = E_NOT_OK;

    cmd = (uint8 *)transaction->txBuf;
    /* Get the pointer to the hwAttrs */
    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;
    object = (OSPI_Object *)handle->object;

    if(CSL_ospiGetDualByteOpcodeMode(hwAttrs->baseAddr))
    {
        retVal = OSPI_cmdExtRead(hwAttrs->baseAddr,
                                 (uint8 *)cmd,
                                 (uint32)CSL_OSPI_CMD_LEN_EXTENDED,
                                 (uint8 *)transaction->rxBuf,
                                 (uint32)transaction->count - CSL_OSPI_CMD_LEN_EXTENDED,
                                 (uint32)object->extRdDummyClks);
    }
    else
    {
        retVal = OSPI_cmdRead(hwAttrs->baseAddr,
                              (uint32)cmd[0],
                              (uint8 *)transaction->rxBuf,
                              (uint32)transaction->count - CSL_OSPI_CMD_LEN_DEFAULT);
    }

    return (retVal);
}


FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_read(SPI_Handle handle, SPI_Transaction *transaction)
{
    OSPI_Object *object;
    Std_ReturnType         retVal = E_NOT_OK;

    object = (OSPI_Object *)handle->object;

    if((uint32)OSPI_OPER_MODE_IND_XFER == object->ospiMode)
    {
        retVal = (OSPI_ind_xfer_mode_read(handle, transaction));
    }
    else if((uint32)OSPI_OPER_MODE_DAC_XFER == object->ospiMode)
    {
        retVal = (OSPI_dac_xfer_mode_read(handle, transaction));
    }
    else if((uint32)OSPI_OPER_MODE_CFG == object->ospiMode)
    {
        retVal = (OSPI_cmd_mode_read(handle, transaction));
#if (STD_ON == FLS_USE_INTERRUPTS)
        object->transaction = NULL;
#endif
    }
    else
    {
        transaction->status=SPI_TRANSFER_CANCELED;
    }

    return(retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_waitWriteSramLvl(const CSL_ospi_flash_cfgRegs *pReg,
                                     uint32 *sramLvl)
{
    uint32 retry = CSL_OSPI_REG_RETRY;
    uint32 sramLevel;
    Std_ReturnType  retVal = E_OK;

    while(retry != 0U)
    {
        sramLevel = CSL_ospiGetSramLvl(pReg, 0);
        if (sramLevel <= CSL_OSPI_SRAM_WATERMARK_WR_LVL)
        {
			*sramLvl = sramLevel;
            break;
        }
        (void)Osal_delay(CSL_OSPI_POLL_IDLE_DELAY);
        retry--;
    }

    if (retry != 0U)
    {
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return(retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_waitIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32 retry = OSPI_DAC_WRITE_TIMEOUT;
    Std_ReturnType  retVal;

    /* Check flash indirect write controller status */
    while (retry != 0U)
    {
        if (CSL_ospiIsIndWriteComplete(pRegs) == TRUE)
        {
            break;
        }
        OSPI_delay(OSPI_CHECK_IDLE_DELAY);
        retry--;
    }

    if (retry != 0U)
    {
        /* Clear indirect completion status */
        CSL_ospiClrIndWriteComplete(pRegs);
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return(retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_ind_xfer_mode_write(SPI_Handle handle,
                                           SPI_Transaction *transaction)
{
    OSPI_HwAttrs const *hwAttrs;      /* OSPI hardware attributes */
    OSPI_Object        *object;       /* OSPI object */
    uint8               *pSrc;         /* Destination address */
    uint32               count;        /* transaction length */
    uint32               offset;       /* OSPI flash offset address */
    uint32               remaining;
    uint32               sramLevel, wrBytes;
    uint32               retFlag = 0;
    Std_ReturnType       retVal = E_OK;

    /* Copy flash transaction parameters to local variables */
    offset = (uint32)(transaction->arg); /* NOR Flash offset address to write */
    pSrc = (uint8*)transaction->txBuf;
    count = (uint32)transaction->count;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;
    object = (OSPI_Object *)handle->object;

    /* Disable DAC mode */
    CSL_ospiDacEnable(hwAttrs->baseAddr, FALSE);

    /* Set write address in indirect mode */
    CSL_ospiIndSetStartAddr(hwAttrs->baseAddr,
                            offset,
                            FALSE);
    CSL_ospiIndWriteExecute(hwAttrs->baseAddr, count);

    if ((uint32)SPI_OPER_MODE_POLLING == object->intrPollMode)
    {
        /* Wait Indirect Write  SRAM fill level below the threshold */
        if (OSPI_waitWriteSramLvl(hwAttrs->baseAddr,
                                  &sramLevel) != E_OK)
        {
            retFlag = 1U;
            retVal = E_NOT_OK;
            transaction->status=SPI_TRANSFER_FAILED;
        }
        else
        {
            remaining = count;
            while(remaining > 0U)
            {
                /* Wait indirect write SRAM fifo level below watermark */
                if (OSPI_waitWriteSramLvl(hwAttrs->baseAddr,
                                          &sramLevel) != E_OK)
                {
                    retFlag = 1U;
                    retVal = E_NOT_OK;
                    break;
                }

                wrBytes = (CSL_OSPI_SRAM_PARTITION_WR - sramLevel) * CSL_OSPI_FIFO_WIDTH;
                wrBytes = (wrBytes > remaining) ? remaining : wrBytes;

                /* Write data to FIFO */
                CSL_ospiWriteFifoData(hwAttrs->dataAddr, pSrc, wrBytes);

                pSrc += wrBytes;
                remaining -= wrBytes;
            }

            if(retFlag == 0U)
            {
                if (OSPI_waitIndWriteComplete(hwAttrs->baseAddr) != E_OK)
                {
                    retFlag = 1U;
                    retVal = E_NOT_OK;
                }
            }
        }
    }

    if(retFlag == 1U)
    {
        transaction->status=SPI_TRANSFER_FAILED;
        CSL_ospiIndWriteCancel(hwAttrs->baseAddr);
    }
    return (retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_dac_xfer_mode_write(SPI_Handle handle,
                                           const SPI_Transaction *transaction)
{

    OSPI_HwAttrs const *hwAttrs;      /* OSPI hardware attributes */
    uint8               *pSrc;         /* Source address */
    uint32               offset;       /* OSPI flash offset address */
    uint32               i;
    uint8               *pDst;         /* Destination address */
    uint32               size;
    uint32               remainSize;
    Std_ReturnType       retVal = E_OK;
    uint32               wrWord;
    uint32               wrByte;

    /* Copy flash transaction parameters to local variables */
    offset = (uint32)(transaction->arg); /* OSPI Flash offset address to write */
    pSrc = (uint8 *)transaction->txBuf;

    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;

    /* Disable PHY pipeline mode */
    CSL_ospiPipelinePhyEnable(hwAttrs->baseAddr, FALSE);

    pDst = (uint8 *)(hwAttrs->dataAddr + offset);
    remainSize = (uint32)transaction->count & 3U;
    size = (uint32)transaction->count - remainSize;
    /* Transfer the data in 32-bit size */
    for (i = 0U; i < size; i += 4U)
    {
        wrWord = CSL_REG32_RD(pSrc + i);
        CSL_REG32_WR(pDst + i, wrWord);
        if (OSPI_waitDeviceReady(handle, OSPI_DAC_WRITE_TIMEOUT) == TRUE)
        {
            retVal = E_OK;
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }
    if (retVal == E_OK)
    {
        /* Transfer the remaining data in 8-bit size */
        for (i = 0; i < remainSize; i++)
        {
            wrByte = CSL_REG8_RD(pSrc + size + i);
            CSL_REG8_WR(pDst + size + i, wrByte);
            if (OSPI_waitDeviceReady(handle, OSPI_DAC_WRITE_TIMEOUT) == TRUE)
            {
                retVal = E_OK;
            }
            else
            {
                retVal = E_NOT_OK;
            }
        }
    }

    return (retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_cmdWrite(const CSL_ospi_flash_cfgRegs *pRegs,
                             const uint8                *cmdBuf,
                             uint32                      cmdLen,
                             const uint8                *txBuf,
                             uint32                      txLen)
{
    (void)CSL_ospiCmdWrite(pRegs, cmdBuf, cmdLen, txBuf, txLen);
    return (OSPI_flashExecCmd(pRegs));
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_cmd_mode_write(SPI_Handle handle,
                                      const SPI_Transaction *transaction)
{
    OSPI_HwAttrs const *hwAttrs; /* OSPI hardware attributes */
    uint8               *txBuf;
    uint32               dataLen;
    uint32               cmdLen;
    Std_ReturnType       retVal = E_OK;

    txBuf = (uint8 *)transaction->txBuf;
    dataLen = (uint32)(transaction->arg);
    cmdLen = (uint32)transaction->count - dataLen;
    /* Get the pointer to the object and hwAttrs */
    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;

    if (dataLen != 0U)
    {
        retVal = (OSPI_cmdWrite(hwAttrs->baseAddr,
                                txBuf,
                                cmdLen,
                                &txBuf[cmdLen],
                                dataLen));
    }
    else
    {
        retVal = (OSPI_cmdWrite(hwAttrs->baseAddr,
                                txBuf,
                                cmdLen,
                                NULL,
                                0));
    }
    return (retVal);
}


FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_write(SPI_Handle handle, SPI_Transaction *transaction)
{
    OSPI_Object  *object;
    Std_ReturnType retVal = E_NOT_OK;

    /* Get the pointer to the object and hwAttrs */
    object = (OSPI_Object *)handle->object;

    if((uint32)OSPI_OPER_MODE_IND_XFER == object->ospiMode)
    {
        retVal = (OSPI_ind_xfer_mode_write(handle, transaction));
    }
    else if((uint32)OSPI_OPER_MODE_DAC_XFER == object->ospiMode)
    {
        retVal = (OSPI_dac_xfer_mode_write(handle, transaction));
    }
    else if((uint32)OSPI_OPER_MODE_CFG == object->ospiMode)
    {
        retVal = (OSPI_cmd_mode_write(handle, transaction));
#if (STD_ON == FLS_USE_INTERRUPTS)
        object->transaction = NULL;
#endif
    }
    else
    {
        transaction->status=SPI_TRANSFER_CANCELED;
    }
    return (retVal);
}

/*
 *  ======== OSPI_transfer ========
 */
FLS_FUNC_TEXT_SECTION boolean OSPI_transfer(SPI_Handle handle, SPI_Transaction *transaction_xfer)
{
    boolean                ret = FALSE; /* return value */
#if (STD_ON == FLS_USE_INTERRUPTS)
    OSPI_HwAttrs        *hwAttrs;     /* OSPI hardware attributes */
#endif
    OSPI_Object        *object;      /* OSPI object */
    Std_ReturnType      xferRet;

    /* Check if anything needs to be written or read */
    if ((handle != NULL) && (transaction_xfer != NULL) && (0U != (uint32)transaction_xfer->count))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (OSPI_Object *)handle->object;
#if (STD_ON == FLS_USE_INTERRUPTS)
        hwAttrs = (OSPI_HwAttrs *)handle->hwAttrs;
#endif
        /* Check if a transfer is in progress */
        if (object->transaction != NULL)
        {
            /* Transfer is in progress */
            transaction_xfer->status = SPI_TRANSFER_CANCELED;
        }
        else
        {
            /* Save the pointer to the transaction */
            object->transaction = transaction_xfer;

            /* Book keeping of transmit and receive buffers. */
            object->writeBufIdx = (uint8 *)transaction_xfer->txBuf;
            object->writeCountIdx = (uint32)transaction_xfer->count;
            object->readBufIdx =  (uint8 *)transaction_xfer->rxBuf;
            object->readCountIdx = (uint32)transaction_xfer->count;

#if (STD_ON == FLS_USE_INTERRUPTS)
            Osal_EnableInterrupt((sint32)hwAttrs->intrNum, (sint32)hwAttrs->eventId);
#endif

            xferRet = OSPI_primeTransfer(handle, transaction_xfer);
            if (xferRet == E_OK)
            {
                /* Always return TRUE if in Asynchronous mode */
                ret = TRUE;
                transaction_xfer->status = SPI_TRANSFER_COMPLETED;
            }
            else
            {
                transaction_xfer->status=SPI_TRANSFER_FAILED;
            }

            if (object->intrPollMode == (uint32)SPI_OPER_MODE_POLLING)
            {
                object->transaction = NULL;
            }
        }
    }
    else
    {
        if (transaction_xfer != NULL)
        {
            transaction_xfer->status = SPI_TRANSFER_CANCELED;
        }
    }

    return (ret);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_configDdr(SPI_Handle handle, uint32 cmd, uint32 addr, uint32 data)
{
    OSPI_HwAttrs const *hwAttrs; /* OSPI hardware attributes */
    Std_ReturnType      retVal;

    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;
    CSL_ospiFlashStig(hwAttrs->baseAddr, cmd, addr, data);
    retVal = OSPI_flashExecCmd(hwAttrs->baseAddr);
    if (retVal == E_OK)
    {
        if (hwAttrs->dacEnable == TRUE)
        {
            CSL_ospiDacEnable(hwAttrs->baseAddr, TRUE);
        }
        else
        {
            CSL_ospiDacEnable(hwAttrs->baseAddr, FALSE);
        }

        /* Enable DTR protocol */
        if (hwAttrs->dtrEnable == TRUE)
        {
            CSL_ospiDtrEnable(hwAttrs->baseAddr, TRUE);
        }
        else
        {
            CSL_ospiDtrEnable(hwAttrs->baseAddr, FALSE);
        }
    }

    return (retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_enableXip (SPI_Handle handle, uint32 cmd, uint32 addr, uint32 data)
{

    OSPI_HwAttrs const *hwAttrs; /* OSPI hardware attributes */
    Std_ReturnType     retVal;

    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;

    /* Disable Direct Access Controller */
    CSL_ospiDacEnable(hwAttrs->baseAddr, FALSE);

    /* Configure Flash Command Control Register to issue VCR write to FLASH memory to enable/disable XIP mode */
    CSL_ospiFlashStig(hwAttrs->baseAddr, cmd, addr, data);
    retVal = OSPI_flashExecCmd(hwAttrs->baseAddr);
    if (retVal == E_OK)
    {
        OSPI_delay(OSPI_XIP_SETUP_DELAY);

        /* Clear the XIP mode bits in the Mode Bit Configuration Register. */
        CSL_ospiSetModeBits(hwAttrs->baseAddr, 0x00);

        /* Enable the local controllers XIP mode */
        CSL_ospiXipEnable(hwAttrs->baseAddr, TRUE);
    }

    /* Re-enable the Direct Access Controller */
    CSL_ospiDacEnable(hwAttrs->baseAddr, TRUE);
    return (retVal);
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType OSPI_configDummyCycle(SPI_Handle handle,
                                                    uint32 cmd, uint32 addr, uint32 data)
{
    OSPI_HwAttrs const *hwAttrs; /* OSPI hardware attributes */
    Std_ReturnType         retVal;

    hwAttrs = (OSPI_HwAttrs const *)handle->hwAttrs;
    CSL_ospiFlashStig(hwAttrs->baseAddr, cmd, addr, data);
    retVal = OSPI_flashExecCmd(hwAttrs->baseAddr);

    return (retVal);
}

/*
 *  ======== OSPI_control ========
 */
FLS_FUNC_TEXT_SECTION Std_ReturnType OSPI_control(SPI_Handle handle, uint32 cmd, const void *arg)
{
    OSPI_HwAttrs *hwAttrs; /* OSPI hardware attributes */
    OSPI_Object        *object;  /* OSPI object */
    Std_ReturnType      retVal = E_NOT_OK;
    const uint32        *ctrlData = (const uint32 *)arg;
    uint32               nvcrCmd;
    uint32               addr;
    uint32               data;
    uint32               extOpcodeLo;
    uint32               extOpcodeUp;

    if (handle != NULL)
    {
        /* Get the pointer to the object */
        object = (OSPI_Object *)handle->object;
        hwAttrs = (OSPI_HwAttrs *)handle->hwAttrs;

        switch (cmd)
        {
            case SPI_V0_CMD_XFER_OPCODE:
            {
                object->transferCmd = *ctrlData;
                ctrlData++;
                CSL_ospiConfigRead(hwAttrs->baseAddr,
                                   object->transferCmd,
                                   object->xferLines,
                                   object->rdDummyClks);
                object->transferCmd = *ctrlData;
                ctrlData++;
                CSL_ospiWriteSetup(hwAttrs->baseAddr,
                                   object->transferCmd,
                                   object->xferLines);
                object->rdStatusCmd = *ctrlData;
                retVal = E_OK;
                break;
            }

            case SPI_V0_CMD_XFER_OPCODE_EXT:
            {
                extOpcodeLo  = *ctrlData++; /* EXT_STIG_OPCODE_FLD */
                extOpcodeLo |= (*ctrlData++ << 8); /* EXT_POLL_OPCODE_FLD */
                extOpcodeLo |= (*ctrlData++ << 16); /* EXT_WRITE_OPCODE_FLD */
                extOpcodeLo |= (*ctrlData++ << 24); /* EXT_READ_OPCODE_FLD */

                extOpcodeUp  = (*ctrlData++ << 16); /* EXT_WEL_OPCODE_FLD */
                extOpcodeUp |= (*ctrlData << 24); /* WEL_OPCODE_FLD */

                CSL_ospiExtOpcodeSet(hwAttrs->baseAddr,
                             extOpcodeLo,
                             extOpcodeUp);
                CSL_ospiSetDualByteOpcodeMode(hwAttrs->baseAddr,
                                      TRUE);
                retVal = E_OK;
                break;
            }

            case SPI_V0_CMD_XFER_MODE_RW:
            {
                object->transactionType = *ctrlData;
                retVal = E_OK;
                break;
            }

            case SPI_V0_CMD_SET_CFG_MODE:
            {
                object->ospiMode = (uint32)OSPI_OPER_MODE_CFG;
                retVal = E_OK;
                break;
            }

            case SPI_V0_CMD_SET_XFER_MODE:
            {
                if (hwAttrs->dacEnable == TRUE)
                {
                    object->ospiMode = (uint32)OSPI_OPER_MODE_DAC_XFER;
                }
                else
                {
                    object->ospiMode = (uint32)OSPI_OPER_MODE_IND_XFER;
                }
                retVal = E_OK;
                break;
            }

            case SPI_V0_CMD_SET_XFER_LINES:
            {
                uint32 numAddrBytes;
                object->xferLines = *ctrlData;
                numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_3;
                if ((object->xferLines == OSPI_XFER_LINES_OCTAL) && (hwAttrs->dtrEnable))
                {
                    numAddrBytes = CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_4;
                }

                /* Set device size cofigurations */
                CSL_ospiSetDevSize(hwAttrs->baseAddr,
                                   numAddrBytes,
                                   hwAttrs->pageSize,
                                   hwAttrs->blkSize);
                retVal = E_OK;
                break;
            }

            case SPI_V0_CMD_RD_DUMMY_CLKS:
            {
                object->rdDummyClks = *ctrlData;
                retVal = E_OK;
                break;
            }

            case SPI_V0_CMD_EXT_RD_DUMMY_CLKS:
            {
                object->extRdDummyClks = *ctrlData;
                retVal = E_OK;
                break;
            }

            case SPI_V0_CMD_CFG_PHY:
            {
                uint32 phyEnable = *ctrlData++;
                if (phyEnable == TRUE)
                {
                    if (hwAttrs->phyEnable == FALSE)
                    {
                        CSL_ospiSetPreScaler(hwAttrs->baseAddr, CSL_OSPI_BAUD_RATE_DIVISOR(2U));
                        /* Enable PHY mode */
                        CSL_ospiPhyEnable(hwAttrs->baseAddr, TRUE);
                        hwAttrs->phyEnable = TRUE;
                    }
                    uint32 txDelay = *ctrlData++;
                    uint32 rxDelay = *ctrlData;
                    uint32 funcClk = hwAttrs->funcClk;
                    CSL_ospiConfigPhyDLL(hwAttrs->baseAddr,txDelay, rxDelay, funcClk);
                }
                else
                {
                    if (hwAttrs->phyEnable == TRUE)
                    {
                        /* Disable high speed mode when PHY is disabled */
                        CSL_ospiSetPreScaler(hwAttrs->baseAddr, CSL_OSPI_BAUD_RATE_DIVISOR_DEFAULT);
                        CSL_ospiPhyEnable(hwAttrs->baseAddr, FALSE);
                        hwAttrs->phyEnable = FALSE;
                    }
                }
                retVal = E_OK;
                break;
            }

            case SPI_V0_CMD_ENABLE_DDR:
            case SPI_V0_CMD_ENABLE_SDR:
            {
                nvcrCmd = *ctrlData;
                ctrlData++;
                addr   = *ctrlData;
                ctrlData++;
                data   = *ctrlData;
                retVal = OSPI_configDdr(handle, nvcrCmd, addr, data);
                break;
            }

            case SPI_V0_CMD_CFG_XIP:
            {
                if (hwAttrs->xipEnable == TRUE) {
                    nvcrCmd = *ctrlData;
                    ctrlData++;
                    addr = *ctrlData;
                    ctrlData++;
                    data = *ctrlData;
                    retVal = OSPI_enableXip(handle, nvcrCmd , addr, data);

                }
                /* Enable PHY pipeline mode for read */
                CSL_ospiPipelinePhyEnable(hwAttrs->baseAddr, TRUE);
                break;
            }

            case SPI_V0_CMD_CFG_RD_DELAY:
            {
                uint32 rdDelay = *ctrlData;
                CSL_ospiSetDataReadCapDelay(hwAttrs->baseAddr, rdDelay);
                retVal = E_OK;
                break;
            }

            case SPI_V0_CMD_CFG_DUMMY_CYCLE:
            {
                nvcrCmd = *ctrlData;
                ctrlData++;
                addr   = *ctrlData;
                ctrlData++;
                data   = *ctrlData;
                retVal = OSPI_configDummyCycle(handle, nvcrCmd, addr, data);
                break;
            }

            default:
                retVal = E_STATUS_UNDEFINED;
            break;
        }
    }
    return retVal;
}


#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
