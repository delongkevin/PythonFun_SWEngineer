#include <ti/board/src/flash/nand/qspi/nand_qspi_utils.h>
#include <ti/drv/spi/test/src/SPI_log.h>
#include <ti/drv/spi/src/SPI_osal.h>

static uint8_t gBadBlockList[NAND_NUM_BLOCKS] = {0};

NAND_Info Nand_qspiInfo =
{
    0,                          /* hwHandle */
    0,                          /* manufacturerId */
    0,                          /* deviceId */
    0,                          /* busWidth */
    NAND_NUM_BLOCKS,            /* blockCnt */
    NAND_NUM_PAGES_PER_BLOCK,   /* pageCnt */
    NAND_PAGE_SIZE,             /* pageSize */
    NAND_SPARE_AREA_SIZE,       /* spareSize */
    NAND_SPARE_AREA_BB_OFFSET,  /* bbOffset */
    gBadBlockList,             /* *bbList */
    NAND_ECC_ALGO_SUPPORTED,    /* eccAlgo */
    NAND_ECC_OFFSET_VALUE,      /* eccOffset */
    NAND_ECC_BYTE_COUNT,        /* eccByteCount */
};

bool gBufferReadModeEnabled = FALSE;

bool IsOspiConfigValid(OSPI_v0_HwAttrs* const ospiCfg)
{
    bool valid = true;

    if (!ospiCfg)
    {
        valid = false;
    }
    else
    {
        if (ospiCfg->xipEnable)
        {
            SPI_log("\nQSPI NAND Flash Driver doesn't support xipEnable\n");
            valid = false;
        }
        if (ospiCfg->xferLines != OSPI_XFER_LINES_QUAD)
        {
            SPI_log("\nQSPI NAND Flash Driver only supports xferLines=OSPI_XFER_LINES_QUAD\n");
            valid = false;
        }
        if (!ospiCfg->dacEnable)
        {
            SPI_log("\nQSPI NAND Flash Driver only supports dacEnable=1\n");
            valid = false;
        }
        if (ospiCfg->phyEnable && !ospiCfg->dtrEnable)
        {
            SPI_log("\nQSPI NAND Flash Driver only supports dtrEnable=1 when phyEnable=1\n");
            valid = false;
        }
        if (!ospiCfg->phyEnable && ospiCfg->dtrEnable)
        {
            SPI_log("\nQSPI NAND Flash Driver only supports dtrEnable=0 when phyEnable=0\n");
            valid = false;
        }
    }

    return valid;
}

static inline void DqsInputEnable(OSPI_Handle handle, bool enable)
{
    OSPI_v0_HwAttrs* hwAttrs = (OSPI_v0_HwAttrs *)handle->hwAttrs;
    const CSL_ospi_flash_cfgRegs* pRegs = (const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr);

    CSL_REG32_FINS(&pRegs->RD_DATA_CAPTURE_REG,
            OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_DQS_ENABLE_FLD,
            enable?1:0);
}

/* Optimized version of the Nand_qspiSetOpcode function specifically to configure
   the OSPI controller for DTR QSPI DAC reads
   */
static inline void Nand_qspiSetOpcodeQuadReadDtrOptimized(OSPI_Handle handle)
{
    OSPI_v0_HwAttrs const *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    OSPI_v0_Object* object = (OSPI_v0_Object *)handle->object;

    object->rdDummyClks = gBufferReadModeEnabled ? NAND_QUAD_DTR_FAST_READ_DUMMY_CYCLE_BUFFER_MODE : NAND_QUAD_DTR_FAST_READ_DUMMY_CYCLE_CONTINUOUS_MODE;
    object->xferLines = OSPI_XFER_LINES_QUAD;
    object->transferCmd =  NAND_CMD_QUAD_FAST_READ_DTR;


    CSL_ospiConfigRead((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
            NAND_CMD_QUAD_FAST_READ_DTR,
            OSPI_XFER_LINES_QUAD,
            gBufferReadModeEnabled ? NAND_QUAD_DTR_FAST_READ_DUMMY_CYCLE_BUFFER_MODE : NAND_QUAD_DTR_FAST_READ_DUMMY_CYCLE_CONTINUOUS_MODE);
    CSL_ospiWriteSetup((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
            NAND_CMD_EXT_QUAD_FAST_PROG,
            OSPI_XFER_LINES_QUAD);

    object->rdStatusCmd = NAND_CMD_RDSR;
    object->rdStatusAddr = NAND_SR3_ADDR;
    object->extRdDummyClks = NAND_QUAD_DTR_CMD_READ_DUMMY_CYCLE;
}

/* Optimized version of the Nand_qspiSetOpcode function specifically to configure
   the OSPI controller for PHY STR SPI DAC reads
   */
static inline void Nand_qspiSetOpcodeSpiPhyOptimized(OSPI_Handle handle)
{
    OSPI_v0_HwAttrs const *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    OSPI_v0_Object* object = (OSPI_v0_Object *)handle->object;

    object->rdDummyClks = gBufferReadModeEnabled ? NAND_OCTAL_READ_DUMMY_CYCLE_BUFFER_MODE : NAND_OCTAL_READ_DUMMY_CYCLE_CONTINUOUS_MODE;
    object->xferLines = OSPI_XFER_LINES_SINGLE;
    object->transferCmd =  NAND_CMD_QUAD_IO_FAST_RD;


    CSL_ospiConfigRead((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
            NAND_CMD_QUAD_IO_FAST_RD,
            OSPI_XFER_LINES_QUAD,
            gBufferReadModeEnabled ? NAND_OCTAL_READ_DUMMY_CYCLE_BUFFER_MODE : NAND_OCTAL_READ_DUMMY_CYCLE_CONTINUOUS_MODE);
    CSL_ospiWriteSetup((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
            NAND_CMD_EXT_QUAD_FAST_PROG,
            OSPI_XFER_LINES_QUAD);

    object->rdStatusCmd = NAND_CMD_RDSR;
    object->rdStatusAddr = NAND_SR3_ADDR;
    object->extRdDummyClks = NAND_OCTAL_SDR_CMD_READ_DUMMY_CYCLE;
}



/* Configure the OSPI peripheral for Quad SPI */
void Nand_enterQspiMode(OSPI_Handle handle, bool dacEnable, bool phyEnable, bool dtrEnable)
{
    //SPI_log("\nEntering QSPI mode. dacEnable: %d,  phyEnable: %d,  dtrEnable: %d\n", dacEnable, phyEnable, dtrEnable);
    OSPI_v0_HwAttrs *hwAttrs= (OSPI_v0_HwAttrs*)handle->hwAttrs;

    hwAttrs->xferLines = OSPI_XFER_LINES_QUAD;
    hwAttrs->dacEnable = dacEnable;
    hwAttrs->phyEnable = phyEnable;
    hwAttrs->dtrEnable = dtrEnable;

    while (!CSL_ospiIsIdle((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr)));

    /* For phyEnable, dtrEnable, and dacEnable, there's an optimized setOpcode function to speed up
       overall read speed.
       */
    if (phyEnable && dtrEnable && dacEnable)
    {
        Nand_qspiSetOpcodeQuadReadDtrOptimized(handle);
    }
    else
    {
        /* Set read/write opcode and read dummy cycles */
        Nand_qspiSetOpcode(handle);
    }

    if (phyEnable)
    {
        /* The PHY should already be tuned. But the DQS input bit may not be set which is needed
           for QSPI PHY operations
           */
        DqsInputEnable(handle, dtrEnable);
    }
    else
    {
        DqsInputEnable(handle, false);

        CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);
        /* Re-set Baud Rate divisor, which may have been
           changed if we were in QSPI mode with PHY enabled */
        CSL_ospiSetPreScaler((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                CSL_OSPI_BAUD_RATE_DIVISOR(hwAttrs->baudRateDiv));
    }

    CSL_ospiPhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), phyEnable);
    /* DTR can only be used with PHY enabled */
    CSL_ospiDtrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), dtrEnable && phyEnable);
}

/* Configure the OSPI peripheral for Single-line SPI */
void Nand_enterSpiMode(OSPI_Handle handle, bool dacEnable, bool phyEnable)
{
    OSPI_v0_HwAttrs *hwAttrs= (OSPI_v0_HwAttrs*)handle->hwAttrs;

    /* The DAC, PHY, and DTR settings are used by Nand_qspiSetOpcode to configure the
       OSPI registers controlling opcodes, dummy cycles, etc */
    hwAttrs->xferLines = OSPI_XFER_LINES_SINGLE;
    hwAttrs->dacEnable = dacEnable;
    hwAttrs->phyEnable = phyEnable;
    /* This flash device doesn't have any DTR single-spi commands. */
    hwAttrs->dtrEnable = false;

    while (!CSL_ospiIsIdle((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr)));

    /* Use the optimized version of the setOpcode function when appropriate to increase
       read speed.
       */
    if (dacEnable && phyEnable)
    {
        Nand_qspiSetOpcodeSpiPhyOptimized(handle);
    }
    else
    {
        /* Set read/write opcode and read dummy cycles */
        Nand_qspiSetOpcode(handle);
    }

    /* Configure DTR settings */
    CSL_ospiDtrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);
    /* Always disable DQS input bit for SPI */
    DqsInputEnable(handle, false);

    if (phyEnable)
    {
        // Placeholder -- do nothing right now
    }
    else
    {
        /* Re-set Baud Rate divisor, which may have been
           changed if we were in QSPI mode with PHY enabled */
        CSL_ospiSetPreScaler((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                CSL_OSPI_BAUD_RATE_DIVISOR(hwAttrs->baudRateDiv));
        CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);
    }

    CSL_ospiPhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), phyEnable);
}

NAND_STATUS NAND_qspiCmdRead(OSPI_Handle handle, uint8_t *cmdBuf,
        uint32_t cmdLen, uint8_t *rxBuf, uint32_t rxLen)
{
    OSPI_Transaction transaction;
    uint32_t         transferType = SPI_TRANSACTION_TYPE_READ;
    bool             ret;

    /* Update the mode and transfer type with the required values */
    OSPI_control(handle, OSPI_V0_CMD_SET_CFG_MODE, NULL);
    OSPI_control(handle, OSPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);
    OSPI_control(handle, OSPI_V0_CMD_EXT_RD_CMD_LEN, (void *)&cmdLen);

    transaction.txBuf = (void *)cmdBuf;
    transaction.rxBuf = (void *)rxBuf;
    transaction.count = cmdLen + rxLen;

    ret = OSPI_transfer(handle, &transaction);
    if (ret == true)
    {
        return NAND_PASS;
    }
    else
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }
}

NAND_STATUS Nand_qspiReadId(OSPI_Handle handle)
{
    NAND_STATUS     retVal;
    uint8_t         idCode[NAND_RDID_NUM_BYTES];
    uint8_t         cmd = NAND_CMD_RDID;
    uint32_t        manfID, devID;
    uint32_t        cmdDummyCycles;

    cmdDummyCycles = 8; // NOTE (amendola) may need changing!!!
    OSPI_control(handle, OSPI_V0_CMD_EXT_RD_DUMMY_CLKS, (void *)&cmdDummyCycles);

    retVal = NAND_qspiCmdRead(handle, &cmd, 1, idCode, NAND_RDID_NUM_BYTES);

    if (retVal == NAND_PASS)
    {
        manfID = (uint32_t)idCode[0];
        devID = ((uint32_t)idCode[1] << 8) | ((uint32_t)idCode[2]);
        if ((manfID == NAND_MANF_ID) && (devID == NAND_DEVICE_ID))
        {
            Nand_qspiInfo.manufacturerId = manfID;
            Nand_qspiInfo.deviceId = devID;
        }
        else
        {
            SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
            retVal = NAND_FAIL;
        }
    }

    return (retVal);
}

NAND_STATUS Nand_qspiResetMemory(OSPI_Handle handle)
{
    NAND_STATUS     retVal = NAND_PASS;
    uint8_t         cmd;

    /* Send Reset Enable command */
    cmd = NAND_CMD_RSTEN;
    retVal = Nand_qspiCmdWrite(handle, &cmd, 1, 0);

    if (retVal == NAND_PASS)
    {
        /* Send Reset Device Memory command */
        cmd = NAND_CMD_RST_MEM;
        retVal = Nand_qspiCmdWrite(handle, &cmd, 1, 0);
    }

    return (retVal);
}

NAND_STATUS Nand_qspiDisableWriteProtection(OSPI_Handle handle)
{
    NAND_STATUS     retVal = NAND_PASS;
    uint32_t        data[3];
    uint32_t        retry = 10;
    volatile uint32_t delay = 1000;
    uint32_t        idleFlag = FALSE;
    OSPI_v0_HwAttrs const *hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    const CSL_ospi_flash_cfgRegs *pRegs = (const CSL_ospi_flash_cfgRegs *)hwAttrs->baseAddr;

    data[0] = (NAND_CMD_WRITE_STATUS << 24)   | /* write volatile config reg cmd */
        (0 << 23)                         | /* read data disable */
        (0 << 20)                         | /* read 0 data bytes */
        (1 << 19)                         | /* enable cmd adddr */
        (0 << 16)                         | /* 1 address bytes */
        (1 << 15)                         | /* write data enable */
        (0 << 12);                          /* write 1 data bytes */
    data[1] = 0x000000A0;                       /* status register 1 address */
    data[2] = 0x00000000;                       /* Value to disable all protection */

    CSL_ospiFlashStig((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), data[0], data[1], data[2]);

    while (idleFlag == FALSE)
    {
        idleFlag = CSL_ospiIsIdle(pRegs);
    }

    /* Start to execute flash read/write command */
    CSL_ospiFlashExecCmd(pRegs);

    while (1)
    {
        /* Check the command execution status */
        if (CSL_ospiFlashExecCmdComplete(pRegs) == TRUE)
        {
            break;
        }
        while(delay--);
        delay = 1000;
        retry--;
    }

    if (retry == 0U)
    {
        retVal = (int32_t)(-1);
    }

    idleFlag = FALSE;
    while (idleFlag == FALSE)
    {
        idleFlag = CSL_ospiIsIdle(pRegs);
    }

    return retVal;
}


NAND_STATUS Nand_qspiSetBufferReadMode(OSPI_Handle handle, bool enable_buffer_mode)
{
    NAND_STATUS     retVal = NAND_PASS;
    uint32_t        data[3] = {0};
    uint32_t        retry = 10;
    volatile uint32_t delay = 1000;
    uint32_t        idleFlag = FALSE;
    OSPI_v0_HwAttrs const *hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    const CSL_ospi_flash_cfgRegs *pRegs = (const CSL_ospi_flash_cfgRegs *)hwAttrs->baseAddr;
    uint8_t         status;

    {
        uint8_t         cmd[3];
        uint32_t        cmdDummyCycles = 0;
        cmd[0] = NAND_CMD_RDSR;
        cmd[1] = NAND_SR2_ADDR;  /* Address Bytes */

        cmdDummyCycles = 0;
        OSPI_control(handle, OSPI_V0_CMD_EXT_RD_DUMMY_CLKS, (void *)&cmdDummyCycles);

        if (NAND_qspiCmdRead(handle, cmd, 2, &status, 1))
        {
            SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
            return NAND_FAIL;
        }
    }

    if (enable_buffer_mode)
    {
        status |= (1U << 3);
    }
    else
    {
        status &= ~(1U << 3);
    }

    data[0] = (NAND_CMD_WRITE_STATUS << 24)   | /* write volatile config reg cmd */
        (0 << 23)                         | /* read data disable */
        (0 << 20)                         | /* read 0 data bytes */
        (1 << 19)                         | /* enable cmd adddr */
        (0 << 16)                         | /* 1 address bytes */
        (1 << 15)                         | /* write data enable */
        (0 << 12);                          /* write 1 data bytes */
    data[1] = 0x000000B0;                       /* status register 1 address */
    data[2] = status;                       /* Value to disable all protection */


    CSL_ospiFlashStig((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), data[0], data[1], data[2]);

    while (idleFlag == FALSE)
    {
        idleFlag = CSL_ospiIsIdle(pRegs);
    }

    /* Start to execute flash read/write command */
    CSL_ospiFlashExecCmd(pRegs);

    while (1)
    {
        /* Check the command execution status */
        if (CSL_ospiFlashExecCmdComplete(pRegs) == TRUE)
        {
            break;
        }
        while(delay--);
        delay = 1000;
        retry--;
    }

    if (retry == 0U)
    {
        retVal = (int32_t)(-1);
    }

    idleFlag = FALSE;
    while (idleFlag == FALSE)
    {
        idleFlag = CSL_ospiIsIdle(pRegs);
    }

    if (retVal == 0U)
    {
        if (Nand_qspiWaitReady(handle, NAND_WRR_WRITE_TIMEOUT, NULL))
        {
            SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
            retVal = -1;
        }
        else
        {
            gBufferReadModeEnabled = enable_buffer_mode;
        }
    }

    idleFlag = FALSE;
    while (idleFlag == FALSE)
    {
        idleFlag = CSL_ospiIsIdle(pRegs);
    }

    return retVal;
}

void Nand_qspiSetOpcode(OSPI_Handle handle)
{
    uint32_t               data[6];
    uint32_t               rdDummyCycles = 0;
    uint32_t               cmdDummyCycles = 0;
    uint32_t               readCmd;
    uint32_t               progCmd;
    uint32_t               rx_lines;
    OSPI_v0_HwAttrs const *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;

    /* Wait for OSPI peripheral to be idle before messing with any settings. Without this,
       sometimes some bad things happen. For example, without this wait, sometimes the
       OSPI peripheral ueses only 1 SPI line for writes instead of 4 even though the
       DEV_INSTR_WR_CONFIG_REG.DATA_XFER_TYPE_EXT_MODE_FLD is configured for 4. */
    while (!CSL_ospiIsIdle((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr)));

    rx_lines = hwAttrs->xferLines;
    if (rx_lines == OSPI_XFER_LINES_QUAD)
    {
        /* Dummy cycles used in the regular Read command ("readCmd") */
        if (hwAttrs->dacEnable)
        {
            if (hwAttrs->phyEnable)
            {
                if (hwAttrs->dtrEnable)
                {
                    if (gBufferReadModeEnabled)
                    {
                        rdDummyCycles = NAND_QUAD_DTR_FAST_READ_DUMMY_CYCLE_BUFFER_MODE;
                    }
                    else
                    {
                        rdDummyCycles = NAND_QUAD_DTR_FAST_READ_DUMMY_CYCLE_CONTINUOUS_MODE;
                    }
                }
                else
                {
                    if (gBufferReadModeEnabled)
                    {
                        rdDummyCycles = NAND_OCTAL_READ_DUMMY_CYCLE_BUFFER_MODE;
                    }
                    else
                    {
                        rdDummyCycles = NAND_OCTAL_READ_DUMMY_CYCLE_CONTINUOUS_MODE;
                    }
                }
            }
            else
            {
                if (gBufferReadModeEnabled)
                {
                    rdDummyCycles = NAND_OCTAL_READ_DUMMY_CYCLE_BUFFER_MODE;
                }
                else
                {
                    rdDummyCycles = NAND_OCTAL_READ_DUMMY_CYCLE_CONTINUOUS_MODE;
                }
            }
        }
        else
        {
            rdDummyCycles = NAND_OCTAL_READ_DUMMY_CYCLE_INDAC;
        }
        // Double Transfer Rate, Quad SPI
        if (hwAttrs->dtrEnable == true)
        {
            /* cmdDummyCycles corresponds to  */
            cmdDummyCycles  = NAND_QUAD_DTR_CMD_READ_DUMMY_CYCLE;
            readCmd         = NAND_CMD_QUAD_FAST_READ_DTR; // NAND_CMD_FAST_READ_DDR
            progCmd         = NAND_CMD_PAGE_PROG;
        }
        else  // Single Transfer rate, Quad SPI
        {
            cmdDummyCycles  = NAND_OCTAL_SDR_CMD_READ_DUMMY_CYCLE;
            readCmd         = NAND_CMD_QUAD_IO_FAST_RD;  // NAND_CMD_OCTAL_IO_FAST_RD
            progCmd         = NAND_CMD_EXT_QUAD_FAST_PROG;
        }
    }
    else
    {
        /* Set to legacy SPI mode 1-1-1 if not Octal mode */
        rdDummyCycles   = NAND_SINGLE_READ_DUMMY_CYCLE;
        cmdDummyCycles  = NAND_SINGLE_CMD_READ_DUMMY_CYCLE; // ??
        readCmd         = NAND_CMD_READ;
        progCmd         = NAND_CMD_PAGE_PROG;
    }

    data[0] = readCmd;
    data[1] = progCmd;
    data[2] = NAND_CMD_RDSR;
    data[3] = NAND_SR3_ADDR;

    /* Update the read opCode, rx lines and read dummy cycles */
    OSPI_control(handle, OSPI_V0_CMD_RD_DUMMY_CLKS, (void *)&rdDummyCycles);
    OSPI_control(handle, OSPI_V0_CMD_SET_XFER_LINES, (void *)&rx_lines);

    /* Sets the read opcode, write opcode, read dummy cycles (rdDummyCycles), readStatus opcode, and readStatus register */
    OSPI_control(handle, OSPI_V0_CMD_XFER_OPCODE, (void *)data);
    // Doesn't seem like the QSPI NAND has extended opcodes
    OSPI_control(handle, OSPI_V0_CMD_EXT_RD_DUMMY_CLKS, (void *)&cmdDummyCycles);
}

NAND_STATUS Nand_qspiCmdWrite(OSPI_Handle handle, uint8_t *cmdBuf,
        uint32_t cmdLen, uint32_t dataLen)
{
    OSPI_Transaction  transaction;
    uint32_t          transferType = SPI_TRANSACTION_TYPE_WRITE;
    bool              ret;

    /* Update the mode and transfer type with the required values */
    OSPI_control(handle, OSPI_V0_CMD_SET_CFG_MODE, NULL);
    OSPI_control(handle, OSPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);

    transaction.txBuf = (void *)cmdBuf; /* Buffer includes command and write data */
    transaction.count = cmdLen + dataLen;
    transaction.rxBuf = NULL;
    transaction.arg = (void *)(uintptr_t)dataLen;

    ret = OSPI_transfer(handle, &transaction);
    if (ret == true)
    {
        return NAND_PASS;
    }
    else
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }
}

NAND_STATUS Nand_qspiWaitReady(OSPI_Handle handle, uint32_t timeOut, uint8_t* sr3)
{
    uint8_t         status = 0xFF;
    uint8_t         cmd[2];
    uint32_t        cmdDummyCycles = 0;

    cmd[0] = NAND_CMD_RDSR;
    cmd[1] = NAND_SR3_ADDR;  /* Address Bytes */

    OSPI_control(handle, OSPI_V0_CMD_EXT_RD_DUMMY_CLKS, (void *)&cmdDummyCycles);

    do
    {
        if (NAND_qspiCmdRead(handle, cmd, 2, &status, 1))
        {
            SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
            return NAND_FAIL;
        }
        if ((status & NAND_SR3_BUSY) == 0)
        {
            break;
        }

        timeOut--;
        if (!timeOut)
        {
            break;
        }

    } while (1);
    cmdDummyCycles = 8;
    OSPI_control(handle, OSPI_V0_CMD_EXT_RD_DUMMY_CLKS, (void *)&cmdDummyCycles);

    if ((status & NAND_SR3_BUSY) == 0)
    {
        if (sr3)
        {
            *sr3 = status;
        }
        return NAND_PASS;
    }

    /* Timed out */
    SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
    return NAND_FAIL;
}

/* TODO amendola add error handling */
NAND_STATUS NAND_SendPageReadCmd(OSPI_Handle spiHandle, uint32_t pageidx)
{
    OSPI_v0_HwAttrs const *hwAttrs= (OSPI_v0_HwAttrs const *)spiHandle->hwAttrs;

    uint32_t pageReadCmdLen = 4;
    uint8_t pageReadCmd[4];

    bool saveDacEnable = hwAttrs->dacEnable;
    bool savePhyEnable = hwAttrs->phyEnable;
    bool saveDtrEnable = hwAttrs->dtrEnable;
    int32_t saveXferLines = hwAttrs->xferLines;

    /* Enter 1s-1s-1s mode to send Page Read Data command. */
    if (hwAttrs->xferLines == OSPI_XFER_LINES_QUAD)
    {
        Nand_enterSpiMode(spiHandle, saveDacEnable, savePhyEnable);
    }

    /* Send the Page Read Data command */
    pageReadCmd[0] = NAND_CMD_PAGE_READ;
    pageReadCmd[1] = 0x00;                       /* Dummy Byte */
    pageReadCmd[2] = (pageidx >>  8) & 0xff;    /* page address 2 bytes */
    pageReadCmd[3] = (pageidx >>  0) & 0xff;
    pageReadCmdLen = 4;
    Nand_qspiCmdWrite(spiHandle, pageReadCmd, pageReadCmdLen, 0);

    /* Wait for command to finish before reverting OSPI peripheral settings. */
    if (Nand_qspiWaitReady(spiHandle, NAND_WRR_WRITE_TIMEOUT, NULL))
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    /* Revert OSPI peripheral settings to QSPI mode. */
    if (saveXferLines == OSPI_XFER_LINES_QUAD)
    {
        Nand_enterQspiMode(spiHandle, saveDacEnable, savePhyEnable, saveDtrEnable);
    }

    return NAND_PASS;
}

NAND_STATUS Nand_qspiReadStatusRegister(OSPI_Handle handle, uint8_t status_reg_addr, uint8_t* status)
{
    uint8_t         cmd[3];
    uint32_t        cmdDummyCycles = 0;

    cmd[0] = NAND_CMD_RDSR;
    cmd[1] = status_reg_addr;  /* Address Bytes */

    OSPI_control(handle, OSPI_V0_CMD_EXT_RD_DUMMY_CLKS, (void *)&cmdDummyCycles);

    NAND_STATUS ret = NAND_qspiCmdRead(handle, cmd, 2, status, 1);

    cmdDummyCycles = 8;
    OSPI_control(handle, OSPI_V0_CMD_EXT_RD_DUMMY_CLKS, (void *)&cmdDummyCycles);
    return ret;
}

void SetDeviceSizeReg(OSPI_v0_HwAttrs* hwAttrs)
{
    /* Set device size register to 1Gb (defaults to 512 Mb) */
    const CSL_ospi_flash_cfgRegs* pRegs = (const CSL_ospi_flash_cfgRegs*)hwAttrs->baseAddr;

    uint32_t regVal = CSL_REG32_RD(&pRegs->DEV_SIZE_CONFIG_REG);

    /* Configure the Device Write Instruction Configuration Register */
    regVal &= ~(CSL_OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_MEM_SIZE_ON_CS0_FLD_MASK);
    regVal |= (1 << CSL_OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_MEM_SIZE_ON_CS0_FLD_SHIFT);

    CSL_REG32_WR(&pRegs->DEV_SIZE_CONFIG_REG, regVal);

    /* Set device size cofigurations:
       - Num Address bytes
       - Page Size
       - "bytes per subsector" doesn't seem to be applicable
       */
    CSL_ospiSetDevSize((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
            1,
            NAND_PAGE_SIZE,
            0x11);
}

void PrintBuffer(uint8_t* buf, uint32_t length)
{
    uint8_t* readhead = buf;
    SPI_log("\n \t: BUFPRINT: [");
    int idx;
    for(idx = 0; idx < length; idx++)
    {
        if (idx % 20 == 0)
        {
            SPI_log("\n\t\t");
        }
        SPI_log("%x ", *readhead);
        readhead++;
    }
    SPI_log("]\n");
}

/* This doesn't fetch from header due to SPI_DMA_ENABLE mess */
extern void OSPI_dmaTransfer(OSPI_Handle handle,
		             const OSPI_Transaction *transaction);

#if defined(BUILD_MCU1_0) && !defined(SBL_BUILD_EN)
extern void WaitEventOSPI();
#endif
/* This function is an optimized replacement for calling SPI_transfer to do a DMA, DAC, PHY
 * DTR read.
 */
bool Nand_qspiOptimizedQuadRead(OSPI_Handle handle, OSPI_Transaction *transaction)
{
    bool                   ret = (bool)false; /* return value */
    OSPI_v0_HwAttrs const *hwAttrs;     /* OSPI hardware attributes */
    OSPI_v0_Object        *object;      /* OSPI object */
    volatile uint8_t      *pSrc;        /* Source address */
    volatile uint8_t      *pDst;        /* Destination address */
    uint32_t               offset;      /* OSPI flash offset address */

    /* Check if anything needs to be written or read */
    if ((handle != NULL) && (transaction != NULL) && (0U != (uint32_t)transaction->count))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (OSPI_v0_Object *)handle->object;
        hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

        /* Save the pointer to the transaction */
        object->transaction = transaction;

        /* Book keeping of transmit and receive buffers. */
        object->writeBufIdx = (uint8_t *)transaction->txBuf;
        object->writeCountIdx = (uint32_t)transaction->count;
        object->readBufIdx =  (uint8_t *)transaction->rxBuf;
        object->readCountIdx = (uint32_t)transaction->count;

        SPI_osalHardwareIntrEnable((int32_t)hwAttrs->intrNum, (int32_t)hwAttrs->eventId);

        /* Clear and enable the OSPI interrupts */
        // CSL_ospiIntrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
        //                     CSL_OSPI_INTR_MASK_ALL,
        //                     FALSE);
        CSL_ospiIntrClear((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                CSL_OSPI_INTR_MASK_ALL);


        CSL_ospiIntrEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                CSL_OSPI_INTR_MASK_ALL,
                TRUE);


        /* Copy flash transaction parameters to local variables */
        offset = (uint32_t)((uintptr_t)transaction->arg); /* OSPI Flash offset address to read */
        pDst = (uint8_t *)transaction->rxBuf;
        pSrc = (uint8_t *)(hwAttrs->dataAddr + offset);

        /* Enable PHY pipeline mode for read */
        CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), TRUE);

        CacheP_Inv((void *)pSrc, transaction->count);
        CacheP_wbInv((void *)pDst, transaction->count);

        OSPI_dmaTransfer(handle, transaction);

        CSL_ospiIntrClear((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr),
                CSL_OSPI_INTR_MASK_ALL);

        CacheP_wb((void *)pDst, transaction->count);

#if defined(BUILD_MCU1_0) && !defined(SBL_BUILD_EN)
    	WaitEventOSPI();
#else
    	/* Wait to be woken back up by OSPI_dmaIsrHandler */
    	(void)SPI_osalPendLock(object->transferComplete, SemaphoreP_WAIT_FOREVER);
#endif
        ret = (transaction->status == OSPI_TRANSFER_COMPLETED);

        object->transaction = NULL;
    }
    else
    {
        ret = false;
        if (transaction != NULL)
        {
            transaction->status = OSPI_TRANSFER_CANCELED;
        }
    }

    return ret;
}
