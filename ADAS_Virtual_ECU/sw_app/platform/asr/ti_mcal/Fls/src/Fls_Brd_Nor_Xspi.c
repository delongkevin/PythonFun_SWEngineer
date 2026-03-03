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
 *  \file     Fls_Brd_Nor_Xspi.c
 *
 *  \brief    This file contains FLS MCAL driver internal functions for Board Nor XSPI
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "stdint.h"
#include "string.h"
#include "Fls_Brd_Nor.h"
#include "Fee_Cbk.h"
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include "nor_spi_phy_tune.h"
#include "nor_spi_patterns.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static Std_ReturnType Nor_xspiCmdWrite(SPI_Handle handle, uint8 *cmdBuf,
                                uint32 cmdLen, uint32 dataLen);
static Std_ReturnType Nor_xspiCmdRead(SPI_Handle handle, uint8 *cmdBuf,
                                uint32 cmdLen, uint8 *rxBuf, uint32 rxLen);
static Std_ReturnType Nor_xspiHybridSectCfg(SPI_Handle handle, uint8 enable,
                                        uint32   cfgFlag);
static Std_ReturnType Nor_xspiReadId(SPI_Handle handle);
static Std_ReturnType Nor_xspiEnableDDR(SPI_Handle handle);
static Std_ReturnType Nor_xspiEnableSDR(SPI_Handle handle);
static Std_ReturnType Nor_xspiWaitReady(SPI_Handle handle, uint32 timeOut);
static Std_ReturnType Nor_xspiSetOpcode(SPI_Handle handle);
static Std_ReturnType Nor_xspiSetDummyCycle(SPI_Handle handle, uint32 dummyCycle);
static Std_ReturnType Fls_norRead(uint32 actualChunkSize);
static Std_ReturnType Fls_norWrite(uint32 actualChunkSize);
static Std_ReturnType Fls_norErase(uint32 actualChunkSize);
static boolean Fls_VerifyData_priv(const uint8 *expData,
                const uint8 *rxData,
                uint32 length);
static Std_ReturnType Fls_norCompare(uint32 actualChunkSize);
static Std_ReturnType Fls_norBlankCheck(uint32 actualChunkSize);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static bool gPhyEnable;
static bool gDtrEnable;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */


#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"


#if (STD_ON == FLS_DEV_ERROR_DETECT)
FLS_FUNC_TEXT_SECTION void Fls_reportDetError(uint8 apiId, uint8 errorId)
{
    (void) Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, apiId, errorId);
    return;
}
#endif  /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */

FLS_FUNC_TEXT_SECTION void Fls_reportDetRuntimeError(uint8 apiId, uint8 errorId)
{
    (void) Det_ReportRuntimeError(FLS_MODULE_ID, FLS_INSTANCE_ID, apiId, errorId);
    return;
}

FLS_FUNC_TEXT_SECTION void Fls_reportDetTransientFault(uint8 apiId, uint8 errorId)
{
    (void) Det_ReportTransientFault(FLS_MODULE_ID, FLS_INSTANCE_ID, apiId, errorId);
    return;
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiCmdWrite(SPI_Handle handle, uint8 *cmdBuf,
                                        uint32 cmdLen, uint32 dataLen)
{
    SPI_Transaction  transaction_local;
    uint32         transferType = (uint32) SPI_TRANSACTION_TYPE_WRITE;
    Std_ReturnType  retVal = E_NOT_OK;
    boolean             ret;

    /* Update the mode and transfer type with the required values */
    retVal = SPI_control(handle, SPI_V0_CMD_SET_CFG_MODE, NULL);
    if (retVal == E_OK)
    {
        retVal = SPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);
    }

    if (retVal == E_OK)
    {
        transaction_local.txBuf = (void *)cmdBuf;
        /* Buffer includes command and write data */
        transaction_local.count = cmdLen + dataLen;
        transaction_local.rxBuf = NULL;
        transaction_local.arg = (void *)(uint32)dataLen;

        ret = SPI_transfer(handle, &transaction_local);
        if (ret == TRUE)
        {
            retVal = E_OK;
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }
    return retVal;
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiRegRead(SPI_Handle handle,
                                  uint32   regAddr,
                                  uint8    *data)
{
    Std_ReturnType retVal =  E_OK;
    uint8    cmd[6];

    cmd[0] = NOR_CMD_RDREG;
    cmd[1] = (regAddr >> 24) & 0xFF;
    cmd[2] = (regAddr >> 16) & 0xFF;
    cmd[3] = (regAddr >> 8) & 0xFF;
    cmd[4] = (regAddr) & 0xFF;

    retVal = Nor_xspiCmdRead(handle, cmd, 5, data, 1);
    if(retVal != E_OK)
    {
        return E_NOT_OK;
    }

    return retVal;
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiRegWrite(SPI_Handle handle,
                                   uint32   regAddr,
                                   uint8    data)
{
    Std_ReturnType retVal = E_NOT_OK;
    uint8    cmd[6];

    /* Enable flash write */
    cmd[0] = NOR_CMD_WREN;
    retVal = Nor_xspiCmdWrite(handle, cmd, 1, 0);
    if(retVal == E_OK)
    {
        retVal = Nor_xspiWaitReady(handle, NOR_WRR_WRITE_TIMEOUT);
        if (retVal == E_OK)
        {
            cmd[0] = NOR_CMD_WRREG;
            cmd[1] = (regAddr >> 24) & 0xFF;
            cmd[2] = (regAddr >> 16) & 0xFF;
            cmd[3] = (regAddr >> 8) & 0xFF;
            cmd[4] = (regAddr) & 0xFF;
            cmd[5] = data;

            retVal = Nor_xspiCmdWrite(handle, cmd, 5, 1);
            if (retVal == E_OK)
            {
                retVal = Nor_xspiWaitReady(handle, NOR_WRR_WRITE_TIMEOUT);
            }
        }
    }

    return retVal;
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiHybridSectCfg(SPI_Handle handle,
                                        uint8    enable,
                                        uint32   cfgFlag)
{
    Std_ReturnType  retVal = E_OK;
    uint8     regData;

    /* Read configuration register3 */
    retVal = Nor_xspiRegRead(handle, NOR_CFG3_VREG_ADDR, &regData);
    if(retVal != E_OK)
    {
        return E_NOT_OK;
    }

    if(enable == 1)
    {
        /* Enable hybrid sector configuration */
        regData &= ~0x8;
    }
    else
    {
        /* Disable hybrid sector configuration */
        regData |= 0x8;
    }

    /* Write configuration register3 */
    retVal = Nor_xspiRegWrite(handle, NOR_CFG3_VREG_ADDR, regData);
    if(retVal != E_OK)
    {
        return E_NOT_OK;
    }

    return retVal;
}


FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiCmdRead(SPI_Handle handle, uint8 *cmdBuf,
                            uint32 cmdLen, uint8 *rxBuf, uint32 rxLen)
{
    SPI_Transaction  transaction_local;
    uint32         transferType = (uint32) SPI_TRANSACTION_TYPE_READ;
    Std_ReturnType  retVal = E_NOT_OK;
    boolean             ret;

    /* Update the mode and transfer type with the required values */
    retVal = SPI_control(handle, SPI_V0_CMD_SET_CFG_MODE, NULL);
    if (retVal == E_OK)
    {
        retVal = SPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);
    }

    if (retVal == E_OK)
    {
        transaction_local.txBuf = (void *)cmdBuf;
        transaction_local.rxBuf = (void *)rxBuf;
        transaction_local.count = cmdLen + rxLen;

        ret = SPI_transfer(handle, &transaction_local);
        if (ret == TRUE)
        {
            retVal = E_OK;
        }
        else
        {
            retVal = E_NOT_OK;
        }
    }
    return retVal;
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiReadId(SPI_Handle handle)
{
    Std_ReturnType       retVal = E_NOT_OK;
    uint8     idCode[NOR_RDID_NUM_BYTES];
    uint8     cmd[6];
    uint32    manfID, devID;
    cmd[0] = NOR_CMD_RDID;
    cmd[1] = 0;  /* Address Bytes */
    cmd[2] = 0;
    cmd[3] = 0;
    cmd[4] = 0;

    retVal = Nor_xspiCmdRead(handle, cmd, 5, idCode, NOR_RDID_NUM_BYTES);
    if (retVal == E_OK)
    {
        manfID = (uint32)idCode[0];
        devID = ((uint32)idCode[1] << 8) | ((uint32)idCode[2]);
        if ((manfID != Fls_NorOspiInfo.manufacturerId) || (devID != Fls_NorOspiInfo.deviceId))
        {
            retVal = E_NOT_OK;
        }
    }
    return (retVal);
}


FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiEnableDDR(SPI_Handle handle)
{
    Std_ReturnType       retVal = E_NOT_OK;
    uint8          cmdWren = NOR_CMD_WREN;
    uint32         data[6];

    /* Send Write Enable command */
    retVal = Nor_xspiCmdWrite(handle, &cmdWren, 1U, 0U);

    /* Enable double transfer rate mode */
    if (retVal == E_OK)
    {
        /* send write VCR command to reg addr 0x0 to set to DDR mode */
        data[0] = ((uint32)NOR_CMD_WRITE_VCR << 24U)         | /* write volatile config reg cmd */
                  ((uint32)0U << 23U)                         | /* read data disable */
                  ((uint32)7U << 20U)                         | /* read 8 data bytes */
                  ((uint32)1U << 19U)                         | /* enable cmd adddr */
                  ((uint32)2U << 16U)                         | /* 3 address bytes */
                  ((uint32)1U << 15U);                          /* write data enable */
        data[1] = 0x00800006;     /* Non-volatile config register address */
        data[2] = 0x43; /* set to Octal DDR in Nonvolatile Config Reg 0x0 */
        retVal = SPI_control(handle, SPI_V0_CMD_ENABLE_DDR, (void *)data);
    }

    return retVal;
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiEnableSDR(SPI_Handle handle)
{
    Std_ReturnType       retVal = E_NOT_OK;
    uint8          cmdWren = NOR_CMD_WREN;
    uint32         data[6];
    OSPI_HwAttrs const *hwAttrs= (OSPI_HwAttrs const *)handle->hwAttrs;
    CSL_ospi_flash_cfgRegs *regAddr; //TODO
    uint32               regVal;

    /* Send Write Enable command */
    retVal = Nor_xspiCmdWrite(handle, &cmdWren, 1U, 0U);

    /* Enable single transfer rate mode */
    if (retVal == E_OK)
    {
        /* send write VCR command to reg addr 0x0 to set to DDR mode */
        data[0] = ((uint32)NOR_CMD_WRITE_VCR << 24U)         | /* write volatile config reg cmd */
                  ((uint32)0U << 23U)                         | /* read data disable */
                  ((uint32)7U << 20U)                         | /* read 8 data bytes */
                  ((uint32)1U << 19U)                         | /* enable cmd adddr */
                  ((uint32)2U << 16U)                         | /* 3 address bytes */
                  ((uint32)1U << 15U);                          /* write data enable */
        data[1] = 0x00800006;     /* Non-volatile config register address */
        data[2] = 0x41U; /* set to Extended SPI mode in Nonvolatile Config Reg 0x0 */
        retVal = SPI_control(handle, SPI_V0_CMD_ENABLE_SDR, (void *)data);

        /* Flash device requires 4-bit access for command as well in quad mode */
        regAddr = (CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr); //TODO
        regVal = CSL_REG32_RD(&regAddr->DEV_INSTR_RD_CONFIG_REG);
        regVal |= 0x300;
        CSL_REG32_WR(&regAddr->DEV_INSTR_RD_CONFIG_REG, regVal);

    }
    return retVal;
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiWaitReady(SPI_Handle handle, uint32 timeOut)
{
    uint8         status;
    uint8         cmd[6];
    Std_ReturnType       retVal = E_OK;
    Std_ReturnType       ready = E_NOT_OK;
    uint32 timeOutVal = timeOut;

    cmd[0] = NOR_CMD_RDREG;
    cmd[1] = 0;
    cmd[2] = NOR_VREG_OFFSET;
    cmd[3] = 0;
    cmd[4] = 0;

    do
    {
        if (E_OK == Nor_xspiCmdRead(handle, cmd, 5U, &status, 1U))
        {
            if ((status & NOR_SR_WIP) == 0U)
            {
                ready = E_OK;
            }
            if (E_OK == ready)
            {
                break;
            }
            else
            {
                timeOutVal--;
                if (timeOutVal == 0U)
                {
                    retVal = E_NOT_OK;
                }
            }
        }
        else
        {
            retVal = E_NOT_OK;
        }
    } while (retVal == E_OK);

    /*Timed out*/
    if (ready == E_OK)
    {
        retVal = E_OK;
    }
    return retVal;
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiSetDummyCycle(SPI_Handle handle, uint32 dummyCycle)
{
    Std_ReturnType         retVal;
    uint8                 regData;

    /* Read configuration register2 */
    retVal = Nor_xspiRegRead(handle, NOR_CFG2_VREG_ADDR, &regData);
    if (retVal == E_OK)
    {
        /* Set the dummy cycles */
        regData = (regData & ~0xF) | dummyCycle;

        /* Write configuration register2 */
        retVal = Nor_xspiRegWrite(handle, NOR_CFG2_VREG_ADDR, regData);
    }

    return retVal;
}

FLS_FUNC_TEXT_SECTION static Std_ReturnType Nor_xspiSetOpcode(SPI_Handle handle)
{
    uint32               data[6];
    uint32               rdDummyCycles = 0;
    uint32               cmdDummyCycles = 0;
    uint32               readCmd;
    uint32               progCmd;
    uint32               latencyCode = 0;
    uint32               rx_lines;
    Std_ReturnType       retVal = E_OK;
    rx_lines = (uint32)OSPI_XFER_LINES_OCTAL;
    OSPI_HwAttrs const *hwAttrs= (OSPI_HwAttrs const *)handle->hwAttrs;

    if (hwAttrs->dacEnable == TRUE)
    {
        rdDummyCycles = NOR_OCTAL_READ_DUMMY_CYCLE;
        latencyCode   = NOR_OCTAL_READ_DUMMY_CYCLE_LC;
    }
    else
    {
        rdDummyCycles = NOR_OCTAL_READ_DUMMY_CYCLE_INDAC;
        latencyCode   = NOR_OCTAL_READ_DUMMY_CYCLE_LC_INDAC;
    }

    if (gDtrEnable == TRUE)
    {
        cmdDummyCycles = NOR_OCTAL_DDR_CMD_READ_DUMMY_CYCLE;
        readCmd = NOR_CMD_OCTAL_DDR_READ;
        if (gPhyEnable == FALSE)
        {
            rdDummyCycles += 1;
        }
    }
    else
    {
        cmdDummyCycles = NOR_OCTAL_SDR_CMD_READ_DUMMY_CYCLE;
        readCmd = NOR_CMD_OCTAL_READ;
    }

    progCmd = NOR_CMD_OCTAL_PROG;

    data[0] = readCmd;
    data[1] = progCmd;
    data[2] = NOR_CMD_RDSR;

    /* Update the read opCode, rx lines and read dummy cycles */
    if (SPI_control(handle, SPI_V0_CMD_RD_DUMMY_CLKS, (void *)&rdDummyCycles) != E_OK)
    {
        retVal = E_NOT_OK;
    }
    if (E_OK == retVal)
    {
        if (SPI_control(handle, SPI_V0_CMD_SET_XFER_LINES, (void *)&rx_lines) != E_OK)
        {
            retVal = E_NOT_OK;
        }
    }
    if (E_OK == retVal)
    {
        if (SPI_control(handle, SPI_V0_CMD_XFER_OPCODE, (void *)data) != E_OK)
        {
            retVal = E_NOT_OK;
        }
    }
    if (E_OK == retVal)
    {
        /* Set the opcodes for dual opcode mode */
        data[0] = 0;
        data[1] = 0xFA;
        data[2] = readCmd;
        data[3] = progCmd;
        data[4] = 0xF9;
        data[5] = 0x6;
        if (SPI_control(handle, SPI_V0_CMD_XFER_OPCODE_EXT, (void *)data) != E_OK)
        {
            retVal = E_NOT_OK;
        }
        if (E_OK == retVal)
        {
            if (SPI_control(handle, SPI_V0_CMD_EXT_RD_DUMMY_CLKS, (void *)&cmdDummyCycles) != E_OK)
            {
                retVal = E_NOT_OK;
            }
        }
        if (E_OK == retVal)
        {
            /* Set read dummy cycles to the flash device */
            retVal = Nor_xspiSetDummyCycle(handle, latencyCode);
        }
    }

    return retVal;
}

/*
 * Requirements : MCAL-4220
 */
FLS_FUNC_TEXT_SECTION Std_ReturnType Fls_hwUnitInit(void)
{
    Std_ReturnType retVal;
    SPI_Handle handle = NULL;

    handle = SPI_init();

    if (handle != NULL)
    {
        Fls_DrvObj.spiHandle = handle;
        retVal = Fls_norOpen();
    }
    else
    {
        retVal = E_NOT_OK; /*Handle is NULL */
    }
    return retVal;
}

FLS_FUNC_TEXT_SECTION static void ReportFlsError(Fls_JobType job)
{
    switch(job) {
        case FLS_JOB_COMPARE:
            Fls_reportDetTransientFault(FLS_SID_COMPARE, FLS_E_COMPARE_FAILED);
            break;
        case FLS_JOB_ERASE:
            Fls_reportDetTransientFault(FLS_SID_ERASE, FLS_E_ERASE_FAILED);
            break;
        case FLS_JOB_READ:
            Fls_reportDetTransientFault(FLS_SID_READ, FLS_E_READ_FAILED);
            break;
        case FLS_JOB_WRITE:
            Fls_reportDetTransientFault(FLS_SID_WRITE, FLS_E_WRITE_FAILED);
            break;
        default:
            break;
    }
	Fls_DrvObj.jobResultType = MEMIF_JOB_FAILED;
	Fls_DrvObj.status = MEMIF_IDLE;
}


/* Design :  DES_FLS_020  */
/* Requirements : MCAL-4326, MCAL-4324, MCAL-4323, MCAL-4325,
 *                MCAL-4332, MCAL-4333, MCAL-4328, MCAL-4196,
 *                MCAL-4197, MCAL-4198, MCAL-4199, MCAL-4349,
 *                MCAL-4350, MCAL-4353
 */
FLS_FUNC_TEXT_SECTION void processJobs(Fls_JobType job)
{
    uint32 chunkSize;
    Std_ReturnType retVal = E_NOT_OK;
    /*Get the MIN of two*/
    if (Fls_DrvObj.length < Fls_DrvObj.jobChunkSize)
    {
        chunkSize = Fls_DrvObj.length;
    }
    else
    {
        chunkSize = Fls_DrvObj.jobChunkSize;
    }

    SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_0();

    switch(job) {
        case FLS_JOB_COMPARE:
            retVal = Fls_norCompare(chunkSize);
            break;
        case FLS_JOB_ERASE:
            retVal = Fls_norErase(chunkSize);
            break;
        case FLS_JOB_READ:
            retVal = Fls_norRead(chunkSize);
            break;
        case FLS_JOB_WRITE:
            retVal = Fls_norWrite(chunkSize);
            break;
        case FLS_JOB_BLANKCHECK:
            retVal = Fls_norBlankCheck(chunkSize);
            break;
        default:
            retVal = E_NOT_OK;
            break;
    }

    if (retVal == E_OK)
    {
        Fls_DrvObj.ramAddr = &Fls_DrvObj.ramAddr[chunkSize];
        if (job != FLS_JOB_ERASE)
        {
            Fls_DrvObj.flashAddr += chunkSize;
            /*Erase FlashAddr updated in Fls_norErase*/
        }
        Fls_DrvObj.length -= chunkSize;
        Fls_DrvObj.transferred += chunkSize;

        if( 0U == Fls_DrvObj.length )
        {
            Fls_DrvObj.jobResultType = MEMIF_JOB_OK;
            Fls_DrvObj.status = MEMIF_IDLE;
            Fls_DrvObj.jobType = FLS_JOB_NONE;
            Fls_DrvObj.transferred = 0;
            if( Fls_DrvObj.Fls_JobEndNotification != NULL )
            {
                Fls_DrvObj.Fls_JobEndNotification();
            }
        }
    }
    else /*if retval == E_NOT_OK or E_COMPARE_MISMATCH*/
    {
        if ((E_BLANKCHECK_MISMATCH == retVal) || (E_COMPARE_MISMATCH == retVal))
        {
            Fls_DrvObj.status = MEMIF_IDLE;
            Fls_DrvObj.jobType = FLS_JOB_NONE;
            Fls_DrvObj.transferred = 0;
            if (FLS_JOB_BLANKCHECK == job)
            {
                Fls_reportDetRuntimeError(FLS_SID_BLANK_CHECK, FLS_E_VERIFY_ERASE_FAILED);
            }
            else /*if (FLS_JOB_COMPARE == job)*/
            {
                Fls_DrvObj.jobResultType = MEMIF_BLOCK_INCONSISTENT;
                Fls_reportDetRuntimeError(FLS_SID_COMPARE, FLS_E_VERIFY_WRITE_FAILED);
            }
            if( Fls_DrvObj.Fls_JobErrorNotification != NULL )
            {
                Fls_DrvObj.Fls_JobErrorNotification();
            }
        }
        else /*if retVal == E_NOT_OK*/
        {
            /*Hardware/driver internal error occured*/
            ReportFlsError(job);
            if( Fls_DrvObj.Fls_JobErrorNotification != NULL )
            {
                   Fls_DrvObj.Fls_JobErrorNotification();
            }
        }
    }

    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_0();

    return;
}

static SPI_Transaction transaction;

/* Design :  DES_FLS_021  */
/* Requirements : MCAL-4277, MCAL-4271
 */
FLS_FUNC_TEXT_SECTION static Std_ReturnType Fls_norRead(uint32 actualChunkSize)
{
    SPI_Handle handle;
    uint32 addr     = Fls_DrvObj.flashAddr;
    uint8 *buf      = Fls_DrvObj.ramAddr;
    boolean ret;
    uint32 transferType = (uint32)SPI_TRANSACTION_TYPE_READ;
    handle          = Fls_DrvObj.spiHandle;
    Std_ReturnType retVal = E_OK;

    if (handle != NULL)
    {
        OSPI_HwAttrs     *hwAttrs = (OSPI_HwAttrs *)handle->hwAttrs;

        if ((gPhyEnable == TRUE) && (hwAttrs->tuneDone == FALSE))
        {
            retVal = Nor_spiPhyTune(handle, NOR_TUNING_DATA_OFFSET);
            hwAttrs->tuneDone = TRUE;
        }

        if (E_OK == retVal)
        {
            /* Set transfer mode and read type */
            if (E_OK == SPI_control(handle, SPI_V0_CMD_SET_XFER_MODE, NULL))
            {
                if (E_OK == SPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType))
                {
                    retVal = E_OK;
                }
                else
                {
                    retVal = E_NOT_OK;
                }
            }
            else
            {
                retVal = E_NOT_OK;
            }

            if (E_OK == retVal)
            {
                transaction.arg   = (void *)(uint32)addr;
                transaction.txBuf = NULL;
                transaction.rxBuf = (void *)buf;
                transaction.count = actualChunkSize;

                ret = SPI_transfer(handle, &transaction);
                if (ret != TRUE)
                {
                    retVal = E_NOT_OK; /*HW error occured*/
                }
            }
        }
        else
        {
            retVal = E_NOT_OK; /*Nor_spiPhyTune Failed */
        }
    }
    else
    {
        retVal = E_NOT_OK; /*Handle is NULL*/
    }
    return retVal;
}

/* Design :  DES_FLS_022  */
/* Requirements : MCAL-4240, MCAL-4246
 */
FLS_FUNC_TEXT_SECTION static Std_ReturnType Fls_norWrite(uint32 actualChunkSize) //TODO
{
    SPI_Handle       handle;
    uint32 addr = Fls_DrvObj.flashAddr;
    uint32 len = actualChunkSize;
    uint8 *buf = Fls_DrvObj.ramAddr;
    boolean        ret;
    uint32         byteAddr;
    uint32         wrSize = len ;
    uint32         chunkLen;
    uint32         actual;
    uint32         transferType = (uint32)SPI_TRANSACTION_TYPE_WRITE;
    uint8          cmdWren[2];
    OSPI_HwAttrs     *hwAttrs;
    Std_ReturnType retVal = E_OK;

    handle = Fls_DrvObj.spiHandle;

    if(handle != NULL)
    {
        hwAttrs = (OSPI_HwAttrs *)handle->hwAttrs;
        cmdWren[0] = NOR_CMD_WREN;

        if (hwAttrs->dacEnable == FALSE)
        {
            /* indirect access transfer mode */
            if (hwAttrs->intrEnable == TRUE)
            {
                wrSize = Fls_NorOspiInfo.pageSize; /*for Intr mode, has to be page size of flash device.*/
            }
        }

        byteAddr = addr & (wrSize - 1U);
        for (actual = 0; actual < len; actual += chunkLen)
        {
            if (E_OK == retVal)
            {
                if (Nor_xspiCmdWrite(handle, cmdWren, 1, 0)) //TODO correct structure
                {
                    return E_NOT_OK;
                }

                if (Nor_xspiWaitReady(handle, NOR_WRR_WRITE_TIMEOUT))
                {
                    return E_NOT_OK;
                }

                /* Set the transfer mode, write op code and tx lines */
                SPI_control(handle, SPI_V0_CMD_SET_XFER_MODE, NULL);
                SPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);


                /* Send Page Program command */
                chunkLen = (((len - actual) < (wrSize - byteAddr)) ?
                            (len - actual) : (wrSize - byteAddr));

                transaction.arg   = (void *)(uint32)addr;
                transaction.txBuf = (void *)(buf + actual);
                transaction.rxBuf = NULL;
                transaction.count = chunkLen;

                ret = SPI_transfer(handle, &transaction);
                if (ret == TRUE)
                {
                    addr += chunkLen;
                    byteAddr = 0;
                    retVal = E_OK;
                }
                else
                {
                    retVal = E_NOT_OK;
                }
                /* Wait till the write operation completes */
                if (Nor_xspiWaitReady(handle, NOR_PAGE_PROG_TIMEOUT))
                {
                    return E_NOT_OK;
                }


            }
            else
            {
                retVal = E_NOT_OK;
                break; /*error occured while writing, exit loop */
            }
        }
    }
    else
    {
        retVal = E_NOT_OK; /*handle is NULL */
    }

    return retVal;
}

/* Design :  DES_FLS_023  */
/* Requirements : MCAL-4227, MCAL-4232, MCAL-4233
 */
FLS_FUNC_TEXT_SECTION static Std_ReturnType Fls_norErase(uint32 actualChunkSize)
{
    uint8           cmd[10];
    uint32          cmdLen;
    uint32          address = 0;
    uint8           cmdWren[2];
    SPI_Handle      handle;
    uint32          sector;
    uint32          page;
    uint32          leftover, sector_count, page_size, page_count;
    Std_ReturnType retVal = E_OK;
    handle = Fls_DrvObj.spiHandle;

    cmdWren[0]  = NOR_CMD_WREN;

    if (handle != NULL)
    {
        /*Calculate sector number based on flashAddr, erase one sector at a time*/

        page_size       = Fls_NorOspiInfo.pageSize;
        page_count  	= Fls_NorOspiInfo.pageCnt;
        sector_count    = Fls_NorOspiInfo.sectorCnt;

        sector          = Fls_DrvObj.flashAddr / Fls_NorOspiInfo.sectorSize;
        leftover        = Fls_DrvObj.flashAddr % Fls_NorOspiInfo.sectorSize;
        page 	        = leftover / page_size;

        if ((leftover % page_size ) || (sector > sector_count) ||
            (page > page_count) || (sector >= sector_count))
        {
            retVal = E_NOT_OK;
        }

        if (E_OK == retVal)
        {
            address   = sector * Fls_NorOspiInfo.sectorSize;
            cmd[0]  = NOR_CMD_BLOCK_ERASE;

            cmd[1] = (uint8)(address >> 24U) & 0xffU; /* 4 address bytes */
            cmd[2] = (uint8)(address >> 16U) & 0xffU;
            cmd[3] = (uint8)(address >>  8U) & 0xffU;
            cmd[4] = (uint8)(address >>  0U) & 0xffU;
            cmdLen = 5U;

            if (Nor_xspiWaitReady(handle, NOR_WRR_WRITE_TIMEOUT) == E_OK)
            {
                if (Nor_xspiCmdWrite(handle, cmdWren, 1, 0) == E_OK)
                {
                    if (Nor_xspiWaitReady(handle, NOR_WRR_WRITE_TIMEOUT) == E_OK)
                    {
                        if (Nor_xspiCmdWrite(handle, cmd, cmdLen, 0) == E_OK)
                        {
                            if (Nor_xspiWaitReady(handle, NOR_BULK_ERASE_TIMEOUT)!= E_OK)
                            {
                                retVal = E_NOT_OK;
                            }
                        }
                        else
                        {
                            retVal = E_NOT_OK;
                        }
                    }
                    else
                    {
                        retVal = E_NOT_OK;
                    }
                }
                else
                {
                    retVal = E_NOT_OK;
                }
            }
            else
            {
                retVal = E_NOT_OK;
            }

            Fls_DrvObj.flashAddr = (sector + 1U) * Fls_NorOspiInfo.sectorSize;
        }
    }
    else
    {
        retVal = E_NOT_OK;
    }

    return retVal;
}

FLS_FUNC_TEXT_SECTION static boolean Fls_VerifyData_priv(const uint8 *expData,
                const uint8 *rxData,
                uint32 length)
{
    uint32 idx = 0U;
    uint32 match = 1U;
    boolean retVal = FALSE;
    uint8 *expData_local = (uint8 *)expData;
    uint8 *rxData_local = (uint8 *)rxData;

    for(idx = 0; ((idx < length) && (match != 0U)); idx++)
    {
        if(*expData_local != *rxData_local)
        {
            match = 0U;
        }
        expData_local++;
        rxData_local++;
    }
    if(match == 1U)
    {
        retVal = TRUE;
    }
    return retVal;
}

/* Design :  DES_FLS_024  */
/* Requirements : MCAL-4291, MCAL-4286
 */
FLS_FUNC_TEXT_SECTION static Std_ReturnType Fls_norCompare(uint32 actualChunkSize)
{
    SPI_Handle handle;
    uint32 addr             = Fls_DrvObj.flashAddr;
    uint32 len              = actualChunkSize;
    uint8 *readData_buf     = NULL;
    uint8 *expData_Buf      = Fls_DrvObj.ramAddr;
    boolean  ret;
    uint32 transferType     = (uint32) SPI_TRANSACTION_TYPE_READ;
    Std_ReturnType retVal;

    handle = Fls_DrvObj.spiHandle;

    if (handle != NULL)
    {
        /* Set transfer mode and read type */
        if (E_OK == SPI_control(handle, SPI_V0_CMD_SET_XFER_MODE, NULL))
        {
            if (E_OK == SPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType))
            {
                retVal = E_OK;
            }
            else
            {
                retVal = E_NOT_OK;
            }
        }
        else
        {
            retVal = E_NOT_OK;
        }

        if(E_OK == retVal)
        {
            transaction.arg   = (void *)(uint32)addr;
            transaction.txBuf = NULL;
            transaction.rxBuf = (void *)readData_buf;
            transaction.count = len;

            ret = SPI_transfer(handle, &transaction);
            if (TRUE == ret)
            {
                if (Fls_VerifyData_priv(expData_Buf, (const uint8*)transaction.rxBuf, len) == TRUE)
                {
                    retVal = E_OK;
                }
                else
                {
                    retVal = E_COMPARE_MISMATCH;
                }
            }
            else
            {
                retVal = E_NOT_OK;
            }
        }
    }
    else
    {
        retVal = E_NOT_OK; /* Handle is NULL*/
    }
    return retVal;
};

/* Design :  DES_FLS_025  */
/* Requirements : MCAL-4306, MCAL-4305, MCAL-4310, MCAL-4311
 */
FLS_FUNC_TEXT_SECTION static Std_ReturnType Fls_norBlankCheck(uint32 actualChunkSize)
{
    SPI_Handle handle;
    uint32 addr             = Fls_DrvObj.flashAddr;
    uint32 len              = actualChunkSize;
    uint8 *readData_buf     = NULL;
    boolean  ret;
    uint32         transferType = (uint32)SPI_TRANSACTION_TYPE_READ;
    Std_ReturnType retVal;

    handle = Fls_DrvObj.spiHandle;

    if (handle != NULL)
    {
        /* Buffer containing the received data */
        uint8 expData_Buf[Fls_DrvObj.maxReadNormalMode];

        volatile uint32 idx;
        volatile uint8 *expData_ptr = expData_Buf;

        for(idx = 0; idx < len; idx++)
        {
            *expData_ptr = NOR_ERASED_DATA;
            expData_ptr++;
        }

        /* Set transfer mode and read type */
        if (E_OK == SPI_control(handle, SPI_V0_CMD_SET_XFER_MODE, NULL))
        {
            if (E_OK == SPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType))
            {
                retVal = E_OK;
            }
            else
            {
                retVal = E_NOT_OK;
            }
        }
        else
        {
            retVal = E_NOT_OK;
        }

        if(E_OK == retVal)
        {
            transaction.arg   = (void *)(uint32)addr;
            transaction.txBuf = NULL;
            transaction.rxBuf = (void *)readData_buf;
            transaction.count = len;

            ret = SPI_transfer(handle, &transaction);
            if (TRUE == ret)
            {
                if (Fls_VerifyData_priv(expData_Buf, (const uint8*)transaction.rxBuf, len) == TRUE)
                {
                    retVal = E_OK;
                }
                else
                {
                    retVal = E_BLANKCHECK_MISMATCH;
                }
            }
            else
            {
                retVal = E_NOT_OK;
            }
        }
    }
    else
    {
        retVal = E_NOT_OK; /*Handle is NULL*/
    }
    return retVal;
}

FLS_FUNC_TEXT_SECTION Std_ReturnType Fls_norOpen(void)
{
    SPI_Params      spiParams;  /* SPI params structure */
    SPI_Handle      hwHandle;  /* SPI handle */
    OSPI_HwAttrs    *hwAttrs = NULL;
    Std_ReturnType             retVal = E_OK;

    hwAttrs = (OSPI_HwAttrs *)Fls_DrvObj.spiHandle->hwAttrs;

    /*Copy the config ptr parameters and change the default settings from the Soc default ones */
    hwAttrs->dacEnable = Fls_DrvObj.dacEnable;
    hwAttrs->xipEnable = Fls_DrvObj.xipEnable;
    hwAttrs->dtrEnable = Fls_DrvObj.dtrEnable;
    hwAttrs->funcClk = Fls_DrvObj.ospiClkSpeed;
    hwAttrs->phyEnable = Fls_DrvObj.phyEnable;

    /*Save the DTR enable flag*/
    gDtrEnable = hwAttrs->dtrEnable;

    if (Fls_DrvObj.dacEnable == TRUE)
    {
        /*enable PHY for DAC mode*/
        Nor_spiPhyTuneReset(gDtrEnable);
    }
    else
    {
        hwAttrs->phyEnable = FALSE;
        /*Check to ensure that phy mode should be disabled for INDAC mode*/
    }

    gPhyEnable = hwAttrs->phyEnable;
    if (gPhyEnable == TRUE)
    {
        /*
         * phyEnable is turned on only for DAC read,
         * it turned off for open/erase/write operation
         */
        hwAttrs->phyEnable = FALSE; /*keep phyEnable off for all and only enable for reads */
        /*Set the TuneDone variable to false in open */
        hwAttrs->tuneDone = FALSE;
    }

    if(Fls_DrvObj.clkSpeed == 133333333U)
    {
        hwAttrs->devDelays[3] = OSPI_DEV_DELAY_CSDA;
    }
    else
    {
        hwAttrs->devDelays[3] = OSPI_DEV_DELAY_CSDA_3;
    }

    if(Fls_DrvObj.clkSpeed == OSPI_MODULE_CLK_200M)
    {
        hwAttrs->baudRateDiv = BOARD_XSPI_BAUDRATE_DIV_200M;
    }
    else
    {
        hwAttrs->baudRateDiv = BOARD_XSPI_BAUDRATE_DIV_133M;
    }


#if (STD_ON == FLS_USE_INTERRUPTS)
    hwAttrs->intrEnable = TRUE;
#endif

    /* Use default SPI config params if no params provided */
    SPI_Params_init(&spiParams);

    hwHandle = (SPI_Handle)SPI_open(Fls_DrvObj.spiHandle, &spiParams);

    if (hwHandle != NULL)
    {

        if (gDtrEnable == TRUE)
        {
           if (Nor_xspiEnableDDR(hwHandle) != E_OK)
           {
                retVal = E_NOT_OK;
           }
        }
        else
        {
           if (Nor_xspiEnableSDR(hwHandle) != E_OK)
           {
                retVal = E_NOT_OK;
           }
        }
        if (E_OK == retVal)
        {
            /* Set read/write opcode and read dummy cycles */
            if (Nor_xspiSetOpcode(hwHandle) == E_OK)
            {
                if (Nor_xspiReadId(hwHandle) != E_OK)
                {
                    SPI_close(hwHandle);
                    /* Requirements : MCAL-4200, MCAL-4201 */
                    Fls_reportDetTransientFault(FLS_SID_INIT, FLS_E_UNEXPECTED_FLASH_ID);
                    retVal = E_NOT_OK;
                }

                if (E_OK == retVal)
                {
                    /* Disable hybrid sector configuration */
                    retVal = Nor_xspiHybridSectCfg(hwHandle, 0U, 0U);
                }
            }
            else
            {
                SPI_close(hwHandle);
                retVal = E_NOT_OK;
            }
        }
   }
   else
   {
       retVal = E_NOT_OK;
   }
   return (retVal);
}

void Fls_NorOspiClose(void)
{
    SPI_Handle   spiHandle;
    spiHandle = Fls_DrvObj.spiHandle;
    if (spiHandle != NULL)
    {
        SPI_close(spiHandle);
    }
}


FLS_FUNC_TEXT_SECTION void Fls_copyConfig(Fls_DriverObjType *drvObj,
    const Fls_ConfigType *cfgPtr)
{
    drvObj->Fls_JobEndNotification = cfgPtr->Fls_JobEndNotification;
    drvObj->Fls_JobErrorNotification = cfgPtr->Fls_JobErrorNotification;
    drvObj->maxReadNormalMode = cfgPtr->maxReadNormalMode;
    drvObj->maxWriteNormalMode = cfgPtr->maxWriteNormalMode;
    drvObj->clkSpeed = cfgPtr->ospiClkSpeed;
    drvObj->dacEnable = cfgPtr->dacEnable;
    drvObj->xipEnable = cfgPtr->xipEnable;
    drvObj->dtrEnable = cfgPtr->dtrEnable;
    drvObj->phyEnable = cfgPtr->phyEnable;

    return;
}
/*
 * Requirements : MCAL-1392
 */
FLS_FUNC_TEXT_SECTION void Fls_resetDrvObj(Fls_DriverObjType *drvObj)
{
    drvObj->Fls_JobEndNotification = NULL;
    drvObj->Fls_JobErrorNotification = NULL;
    drvObj->maxReadNormalMode = 0U;
    drvObj->maxWriteNormalMode = 0U;
    drvObj->clkSpeed = 0U;
    drvObj->dacEnable = (uint32)NULL;
    drvObj->xipEnable = (uint32)NULL;
    drvObj->dtrEnable = (uint32)NULL;
    drvObj->phyEnable = (uint32)NULL;
    drvObj->status = MEMIF_UNINIT;
    drvObj->jobResultType = MEMIF_JOB_OK;
    drvObj->jobType = FLS_JOB_NONE;
    drvObj->flashAddr = 0U;
    drvObj->ramAddr = NULL;
    drvObj->length = 0U;
    drvObj->mode = MEMIF_MODE_SLOW;
    drvObj->jobChunkSize = 0U;
    drvObj->spiHandle = NULL;
    drvObj->transferred = 0U;

    return;
}


#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
