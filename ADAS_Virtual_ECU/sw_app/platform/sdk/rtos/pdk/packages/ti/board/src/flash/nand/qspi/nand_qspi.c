/**
 * NOTE: This file did not originate at TI, and was more or less copied from TI
 * code!!! (need to check about copyright stuff)
 */

/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <ti/board/src/flash/nand/qspi/nand_qspi.h>
#include <ti/board/src/flash/nand/qspi/nand_qspi_utils.h>

/* TODO include this file when we enable speed up and enable runtime PHY tuning */ 
#include <ti/board/src/flash/nand/qspi/nand_spi_phy_tune.h>

#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/csl/soc.h>
#include <ti/drv/spi/test/src/SPI_log.h>

#include <ti/board/src/flash/include/board_flash.h>

/* Comment this out to stop checking the ECC-0 and ECC-1 bits in Nand_qspiRead(). With
    this removed, we could have corrupted reads without knowing, but it speeds up the 
    read speed by ~4%.
    If all the reads will end up being checked with a CRC during boot, then this may
    be viable.
*/
#define CHECK_ECC_ON_READS
//#define ENABLE_CONTINUOUS_READS

/* SPI entry offset is at index 0 of SPI config array */
#define SPI_CONFIG_OFFSET     (0U)

/* Max size for our DMA setup. Inner loop (icnt[0]) is 1 page */
#define MAX_DMA_XFER_SIZE  (0x4000000)

/* For unknown reasons, reads longer than this have a CS de-assertion at this length */
#define MAX_NONDMA_XFER_SIZE (0x3fc0000)

static NAND_HANDLE Nand_qspiOpen(uint32_t nandIntf, uint32_t portNum, void *params);
static void Nand_qspiClose(NAND_HANDLE handle);
static NAND_STATUS Nand_qspiRead(NAND_HANDLE handle, uint32_t addr,
                               uint32_t len, uint8_t *buf);
static NAND_STATUS Nand_qspiWrite(NAND_HANDLE handle, uint32_t addr,
                                uint32_t len, uint8_t *buf);
static NAND_STATUS Nand_qspiErase(NAND_HANDLE handle, int32_t eraseCnt);


/* NAND function table for NAND QSPI interface implementation */
const NAND_FxnTable Nand_qspiFxnTable =
{
    &Nand_qspiOpen,
    &Nand_qspiClose,
    &Nand_qspiRead,
    &Nand_qspiWrite,
    &Nand_qspiErase,
};

extern NAND_Info Nand_qspiInfo;

extern bool gBufferReadModeEnabled;

NAND_HANDLE Nand_qspiOpen(uint32_t nandIntf, uint32_t portNum, void *params)
{
    OSPI_Params     spiParams;      /* SPI params structure */
    OSPI_Handle     hwHandle;       /* SPI handle */
    NAND_HANDLE     nandHandle = 0;
    OSPI_v0_HwAttrs ospiCfg;
    bool saved_dtr_enable;
    bool saved_dac_mode;
    bool saved_phy_enable;
    OSPI_xferLines saved_xferLines;

    /* Get the OSPI SoC configurations */
    OSPI_socGetInitCfg(SPI_OSPI_DOMAIN_MCU, portNum, &ospiCfg);

    if (!IsOspiConfigValid(&ospiCfg))
    {
        SPI_log("\nError: Unsupported NAND Flash driver configuration\n");
        nandHandle = (NAND_HANDLE)NULL;
        return nandHandle;
    }

    /* Save the DTR enable flag */
    saved_dtr_enable = ospiCfg.dtrEnable;
    saved_dac_mode = ospiCfg.dacEnable;
    saved_phy_enable = ospiCfg.phyEnable;
    saved_xferLines = ospiCfg.xferLines;
 
    /* Put the OSPI controller in single-line/legacy SPI mode */
    ospiCfg.xferLines = OSPI_XFER_LINES_SINGLE;
    /* Put controller in DAC mode so flash ID can be read directly */
    ospiCfg.dacEnable = true;
    /* Disable PHY during initialization. */
    ospiCfg.phyEnable = false;
    ospiCfg.dtrEnable = false;

    OSPI_socSetInitCfg(SPI_OSPI_DOMAIN_MCU, portNum, &ospiCfg);

    /* Use default SPI config params if no params provided */
    OSPI_Params_init(&spiParams);

    hwHandle = OSPI_open(SPI_OSPI_DOMAIN_MCU, portNum + SPI_CONFIG_OFFSET, &spiParams);

    if (hwHandle)
    {
        OSPI_v0_HwAttrs *hwAttrs = (OSPI_v0_HwAttrs *)hwHandle->hwAttrs;

        SetDeviceSizeReg(hwAttrs);

        /* No dual-byte opcode mode */
        CSL_ospiSetDualByteOpcodeMode((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), FALSE);

        /* Reset device memory for all the other lines */
        Nand_qspiResetMemory(hwHandle);

        /* Device takes up to 500us to reset. During this time, new commands will be rejected.
           Wait at least this much time until issuing the next command. 
           The following busy delay results in a ~780us delay between the reset command and the
           subsequent command. */
        {
            volatile uint32_t delay = 0x18000;
            while(--delay);
        }


        /* Set read/write opcode and read dummy cycles */
        Nand_qspiSetOpcode(hwHandle);

        /* Read the flash ID to ensure correct config */
        if (Nand_qspiReadId(hwHandle) == NAND_PASS)
        {
            Nand_qspiInfo.hwHandle = (uintptr_t)hwHandle;
            nandHandle = (NAND_HANDLE)(&Nand_qspiInfo);

            /* Disable write protection */
            Nand_qspiDisableWriteProtection(hwHandle);

            /* Configure the Flash device for Buffer Read Mode (BUF=1) */
            Nand_qspiSetBufferReadMode(hwHandle, TRUE);

            /* Restore setttings */
            ospiCfg.xferLines = saved_xferLines;
            ospiCfg.dacEnable = saved_dac_mode;
            ospiCfg.phyEnable = saved_phy_enable;
            ospiCfg.dtrEnable = saved_dtr_enable;
            OSPI_socSetInitCfg(SPI_OSPI_DOMAIN_MCU, portNum, &ospiCfg);

            /* Set read/write opcode and read dummy cycles */
            // Nand_qspiSetOpcode(hwHandle);
            Nand_enterQspiMode(hwHandle, saved_dac_mode, saved_phy_enable, saved_dtr_enable);

            if (ospiCfg.phyEnable)
            {
                if (params)
                {
                    Board_PhyTuningOptions phyTuningOptions = *(Board_PhyTuningOptions *)params;
                    if (phyTuningOptions.struct_type_indicator_magic_number == BOARD_PHY_TUNING_OPTIONS_SCRUCT_MAGIC
                            && phyTuningOptions.phy_tuning_options == PHY_TUNING_DO_TUNING)
                    {
                        if (Nand_spiPhyTune(hwHandle, NAND_TUNING_DATA_OFFSET) == NAND_FAIL)
                        {
                            nandHandle = (NAND_HANDLE)NULL;
                            return nandHandle;
                        }
                    }
                    else
                    {
                        Nand_enableDefaultPhyTuning(hwHandle);
                    }
                }
                else
                {
                    Nand_enableDefaultPhyTuning(hwHandle);
                }
            }
        }
        else
        {
            OSPI_close(hwHandle);
        }
    }

    return (nandHandle);
}

void Nand_qspiClose(NAND_HANDLE handle)
{
    NAND_Info    *nandOspiInfo;
    OSPI_Handle   spiHandle;

    if (handle)
    {
        nandOspiInfo = (NAND_Info *)handle;
        spiHandle = (OSPI_Handle)nandOspiInfo->hwHandle;

        if (spiHandle)
        {
            /* Reset OSPI peripheral back to SPI mode, reset Flash */
            Nand_enterSpiMode(spiHandle, true, false);
            Nand_qspiResetMemory(spiHandle);
            OSPI_close(spiHandle);
        }
    }
}

#ifdef	ENABLE_CONTINUOUS_READS
volatile uint32_t test_chunk_size = 32768U;
#endif

NAND_STATUS Nand_qspiRead(NAND_HANDLE handle, uint32_t addr, uint32_t len, uint8_t *buf)
{
    NAND_Info       *nandOspiInfo;
    OSPI_Handle      spiHandle;
    uint32_t         rdAddr;
    uint32_t         pageAddr;
    uint32_t         colmAddr;
    bool             ret = TRUE;
    OSPI_v0_HwAttrs *hwAttrs;
    OSPI_Transaction transaction;
    OSPI_v0_Object        *object;  /* OSPI object */
#ifdef ENABLE_CONTINUOUS_READS
    uint8_t          rep = 0;
    if (len <= 0x100000U) {
        test_chunk_size = 32768U; //32kb
    } else {
        test_chunk_size = 131072U; //128kb, max chunk size is 64MB for DMA transfer
    }
#endif

    if (!handle)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    nandOspiInfo = (NAND_Info *)handle;

    if (nandOspiInfo == NULL)
    {
        return NAND_FAIL;
    }

    spiHandle = (OSPI_Handle)nandOspiInfo->hwHandle;
    if (spiHandle == NULL)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    hwAttrs = (OSPI_v0_HwAttrs *)spiHandle->hwAttrs;

    if (hwAttrs == NULL)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    object = (OSPI_v0_Object *)spiHandle->object;

    if (object == NULL)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    bool savePhyEnable = hwAttrs->phyEnable;
    bool saveDtrEnable = hwAttrs->dtrEnable;

#ifdef ENABLE_CONTINUOUS_READS
    /* Only use continuous reads with DMA enabled */
    bool enableContinuousReads = hwAttrs->dmaEnable;
#endif

    /* Validate address input */
    if ((addr + len) > NAND_SIZE)
    {
        SPI_log("\n Failure in %s at line %d - addr: 0x%x, len: 0x%x \n", __func__, __LINE__, addr, len);
        return NAND_FAIL;
    }
#ifdef ENABLE_CONTINUOUS_READS
    rep = 1;
#endif	
    size_t remaining_bytes = len;
    size_t chunk_size = remaining_bytes < NAND_PAGE_SIZE ? remaining_bytes : NAND_PAGE_SIZE; 

    for(rdAddr = addr; rdAddr < (addr+len); rdAddr += chunk_size)
    {
        if (hwAttrs->xferLines != OSPI_XFER_LINES_SINGLE)
        {
            Nand_enterSpiMode(spiHandle, true, savePhyEnable);
        }

        /* Split the page and column addresses */
        pageAddr = rdAddr / NAND_PAGE_SIZE;
        colmAddr = rdAddr % NAND_PAGE_SIZE;
        remaining_bytes = addr + len - rdAddr;

#ifdef ENABLE_CONTINUOUS_READS
        uint8_t numReadRepetitions;
        if (colmAddr || !enableContinuousReads || remaining_bytes < test_chunk_size) 
		{
          /* Use Buffer Read mode (BUF=1) for reads starting mid-page. */

          /* For buffer read mode, CS de-assertions in the middle of a read are OK. The OSPI peripheral will
             re-issue the read command starting with a column address where it was interrupted and read the 
             remaining bytes from the Flash device's 1-page read buffer. For Continuous reads (BUF=0),
             the OSPI peripheral will behave the same way but the remainder of the transfer after the CS
             CS de-assertion will be corrupted because it's not allowed to re-issue a 2nd read command in the
             middle of a read in Continuous Read Mode. Testing has shown that the mid-read CS de-assertion only
             happens the first time we do a read of a given length. So in Continuous Read Mode, we can mitigate 
             the OSPI peripheral CS de-assertion problem by doing each read twice. */
          numReadRepetitions = 1;

            /* If We need to read starting mid-page, we need to switch the flash device into BUF=1, buffer-read mode,
               and read (at max) up to the next page boundary. The rest of the read can be done with continuous reads */
            chunk_size = (remaining_bytes < NAND_PAGE_SIZE - colmAddr) ? remaining_bytes : (NAND_PAGE_SIZE - colmAddr);
            if (!gBufferReadModeEnabled)
            {
                Nand_qspiSetBufferReadMode(spiHandle, true);
            }
        }
        else
        {
            /* Use Continuous Read Mode */

            /* In Continuous Read Mode (BUF=1) we need to do the entire read twice to mitigate the OSPI
            peripheral's CS de-assertion problem (see the numReadRepetitions=1
            comment above for more information). */
            if (rep == 1) 
			{
            	numReadRepetitions = 2;
                rep = 0;
            } 
			else
            {
                numReadRepetitions = 1;
            }
          //if (hwAttrs->dmaEnable) {
          /* The Flash device lets us read an arbitrary number of bytes in continuous read mode as long as the read
             starts from a page boundary. However, when using DMA reads, we can only read multiples of 32KB if the transfer is longer than 64KB.
             This is because of the way the UDMA transfers work, as a quad-nested-loop. We also are unable to simply modify
             the UDMA driver handle the remainder transfer because there will remain a gap between the first transfer and the
             remainder transfer, causing the OSPI peripheral to interrupt the read transfer, corrupting the rest of the read.
             */
//            if (remaining_bytes < NAND_PAGE_SIZE) {
//              chunk_size = remaining_bytes;
             // {
              /* For reads longer than 0xFFFF bytes (largest value that can fit in the iCnt[0] uint16_t specifier), 
                 the read must be N=1-0xFFFF pages (iCnt[0] = 0x800; iCnt[1] = N;).
                 In addition to requirement of reads lengths longer than 0xFFFF bytes being an integer number of pages,
                 there is an un-root-caused OSPI peripheral bug that results in any DMA read longer than 0x4000000 bytes
                 having a CS de-assertion after the first 0x4000000 bytes. MAX_DMA_XFER_SIZE corresponds to a transfer
                 0x4000000 bytes (which is less than 0x800*0xFFFF bytes). */

              /* Enforce read length being an integer number of pages. */
              //chunk_size = remaining_bytes - (remaining_bytes % NAND_PAGE_SIZE);
                chunk_size = test_chunk_size;

              /* Enforce read length being less than 0x4000000 bytes. */
                chunk_size = chunk_size < MAX_DMA_XFER_SIZE ? chunk_size : MAX_DMA_XFER_SIZE;
           // }
          //} else {
            /* Fewer restrictions for non-DMA mode. Reads must be less than MAX_NONDMA_XFER_SIZE. */
           // chunk_size = remaining_bytes < MAX_NONDMA_XFER_SIZE ? remaining_bytes : MAX_NONDMA_XFER_SIZE;
          //}

          /* Configure Flash device for BUF=0 (Continuous Read Mode). */
          if (gBufferReadModeEnabled) 
		  {
            Nand_qspiSetBufferReadMode(spiHandle, false);
          }
        }
#else 
        /* A lot simpler logic if we aren't allowing continuous reads: */
        chunk_size = (remaining_bytes < NAND_PAGE_SIZE - colmAddr) ? remaining_bytes : (NAND_PAGE_SIZE - colmAddr);
#endif  // defined ENABLE_CONTINUOUS_READS



        /* This loop is here to implement the "double read hack" for Continuous Read Mode to mitigate a CS-Deassertion bug.
          in some cases the first read will be corrupted in BUF=0 mode, but the 2nd read should (based on our testing) be
          correct. */
#ifdef ENABLE_CONTINUOUS_READS
/* If we're allowing continuous reads, we need to do each read twice for continuous reads and once for buffer reads */
        int repeat;
        for(repeat=0; repeat<numReadRepetitions; ++repeat)
        {
#endif
            if (NAND_SendPageReadCmd(spiHandle, pageAddr) != NAND_PASS)
            {
                SPI_log("\n ERROR: Sending Page Read Data command failed.\n");
                return NAND_FAIL;
            }

          Nand_enterQspiMode(spiHandle, true, savePhyEnable, saveDtrEnable);
          
            /* Set transfer mode and read type */
            /* Directly implement the following function call (ASSUMES dacEnable = 1):
               OSPI_control(spiHandle, OSPI_V0_CMD_SET_XFER_MODE, NULL);
               */
            object->ospiMode = (uint32_t)OSPI_OPER_MODE_DAC_XFER;

            /* Directly implement the following function call:
               OSPI_control(spiHandle, OSPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);
               */
            object->transactionType = SPI_TRANSACTION_TYPE_READ;

            /* Configure transfer paramteters. */
            transaction.arg   = (void *)(uintptr_t)colmAddr;
            transaction.txBuf = NULL;
            transaction.rxBuf = (void *)(buf+rdAddr-addr);
            transaction.count = chunk_size;

            if (hwAttrs->dmaEnable)
            {
                /* For DMA reads, there is an optimized function to read as fast as possible.
                   The OSPI_transfer call also works with dmaEnable but is slower */
                ret = Nand_qspiOptimizedQuadRead(spiHandle, &transaction);
            }
            else
            {
                ret = OSPI_transfer(spiHandle, &transaction);
            }
            if (ret == false)
            {
                SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
                return NAND_FAIL;
            }

#ifdef CHECK_ECC_ON_READS
/* Slower, but can detect errors in reads */
          Nand_enterSpiMode(spiHandle, true, savePhyEnable);

          uint8_t sr3 = 0xFF;
          /* Wait till the write operation completes */
          if (Nand_qspiWaitReady(spiHandle, NAND_WRR_WRITE_TIMEOUT, &sr3))
          {
              SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
              return NAND_FAIL;
          }
          if (sr3 & NAND_SR3_ECC1_MASK)
          {
              SPI_log("\nFlash read found uncorrectable (2+ bit error) on page %d\n", pageAddr);
              return NAND_FAIL;
          }
#endif  // CHECK_ECC_ON_READS

#ifdef ENABLE_CONTINUOUS_READS
        }
#endif  // ENABLE_CONTINUOUS_READS

    }

    Nand_enterQspiMode(spiHandle, true, savePhyEnable, saveDtrEnable);

    return NAND_PASS;
}

NAND_STATUS Nand_qspiWrite(NAND_HANDLE handle, uint32_t addr, uint32_t len, uint8_t *buf)
{
    NAND_Info       *nandOspiInfo;
    OSPI_Handle      spiHandle;
    bool             ret;
    uint32_t         byteAddr;
    uint32_t         pageAddr;
    uint32_t         colmAddr;
    uint32_t         wrSize = len;
    uint32_t         chunkLen;
    uint32_t         src_idx;
    uint32_t         transferType = SPI_TRANSACTION_TYPE_WRITE;
    OSPI_v0_HwAttrs *hwAttrs;
    uint8_t          progExecuteCmd[4];
    uint32_t         progExecuteCmdLen = 4;
    OSPI_Transaction transaction;

    if (!handle)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    nandOspiInfo = (NAND_Info *)handle;
    if (!nandOspiInfo->hwHandle)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    /* Validate address input */
    if ((addr + len) > NAND_SIZE)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    spiHandle = (OSPI_Handle)nandOspiInfo->hwHandle;
    hwAttrs = (OSPI_v0_HwAttrs *)spiHandle->hwAttrs;

    wrSize = NAND_PAGE_SIZE;
    byteAddr = addr & (wrSize - 1);

    for (src_idx = 0; src_idx < len; src_idx += chunkLen)
    {
        bool saveDacEnable = hwAttrs->dacEnable;
        bool savePhyEnable = hwAttrs->phyEnable;
        bool saveDtrEnable = hwAttrs->dtrEnable;

        int32_t saveXferLines = hwAttrs->xferLines;

        /* Send Page Program command */
        chunkLen = ((len - src_idx) < (wrSize - byteAddr) ?
                    (len - src_idx) : (wrSize - byteAddr));

        /* Split the page and column addresses */
        pageAddr = addr / NAND_PAGE_SIZE;
        colmAddr = addr % NAND_PAGE_SIZE;

        /* Sending the Page Read Data command loads the target page into the Flash device's 
           internal buffer. This prevents random bytes that happen to be in the buffer from
           being written to the Flash page along with the intended bytes during the
           Quad Random Load Program Data command. We need to use the Quad Random Load Program
           Data command (0x34) rather than the Quad Load Program Data command (0x32) because
           if there is a CS de-assertion mid-write, then the 0x32 command will set all the bytes
           in the buffer from before the CS de-assertion to 0xFF. */

        if (NAND_SendPageReadCmd(spiHandle, pageAddr) != NAND_PASS)
        {
            SPI_log("\n ERROR: Sending Page Read Data command failed.\n");
            return NAND_FAIL;
        }

        Nand_enterQspiMode(spiHandle, saveDacEnable, false, false);

        /* Set the transfer mode, write op code and tx lines */
        OSPI_control(spiHandle, OSPI_V0_CMD_SET_XFER_MODE, NULL);
        OSPI_control(spiHandle, OSPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);

        transaction.arg   = (void *)(uintptr_t)colmAddr;
        transaction.txBuf = (void *)(buf + src_idx);
        transaction.rxBuf = NULL;
        transaction.count = chunkLen;

        /* Perform Write data transfer (Load Program Data) */
        ret = OSPI_transfer(spiHandle, &transaction);
        if (ret == false)
        {
            SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
            return NAND_FAIL;
        }

        if (hwAttrs->xferLines == OSPI_XFER_LINES_QUAD)
        {
            Nand_enterSpiMode(spiHandle, saveDacEnable, savePhyEnable);
        }

        /* Send Program Execute command */
        progExecuteCmd[0] = NAND_CMD_PAGE_PROG_EXECUTE;
        progExecuteCmd[1] = 0x00;                       /* Dummy Byte */
        progExecuteCmd[2] = (pageAddr >>  8) & 0xff;    /* page address 2 bytes */
        progExecuteCmd[3] = (pageAddr >>  0) & 0xff;
        progExecuteCmdLen = 4;
        Nand_qspiCmdWrite(spiHandle, progExecuteCmd, progExecuteCmdLen, 0);

        addr += chunkLen;
        byteAddr = 0;

        /* Check P_FAIL bit in SR3 after the BUSY bit is reset*/
        uint8_t sr3 = 0xFF;
        if (Nand_qspiWaitReady(spiHandle, NAND_WRR_WRITE_TIMEOUT, &sr3))
        {
            SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
            return NAND_FAIL;
        }
        if (sr3 & NAND_SR3_P_FAIL_MASK)
        {
            SPI_log("\n Writing to page 0x%x Failed \n", pageAddr);
            return NAND_FAIL;
        }

        if (saveXferLines == OSPI_XFER_LINES_QUAD)
        {
            Nand_enterQspiMode(spiHandle, saveDacEnable, savePhyEnable, saveDtrEnable);
        }
    }

    return NAND_PASS;
}

NAND_STATUS Nand_qspiErase(NAND_HANDLE handle, int32_t erLoc)
{
    uint8_t          cmd[4];
    uint32_t         cmdLen;
    uint32_t         address = 0;
    uint8_t          cmdWren  = NAND_CMD_WREN;
    NAND_Info       *nandOspiInfo;
    OSPI_Handle      spiHandle;
    OSPI_v0_HwAttrs *hwAttrs;

    if (!handle)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    nandOspiInfo = (NAND_Info *)handle;
    if (!nandOspiInfo->hwHandle)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }
    spiHandle = (OSPI_Handle)nandOspiInfo->hwHandle;
    hwAttrs = (OSPI_v0_HwAttrs *)spiHandle->hwAttrs;

    if (erLoc >= NAND_NUM_BLOCKS)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    address = erLoc << 6;  // Address format is [<10-bit block addr> <6-bit page addr>]

    bool saveDacEnable = hwAttrs->dacEnable;
    bool savePhyEnable = hwAttrs->phyEnable;
    bool saveDtrEnable = hwAttrs->dtrEnable;

    int32_t saveXferLines = hwAttrs->xferLines;
    if (hwAttrs->xferLines == OSPI_XFER_LINES_QUAD)
    {
        Nand_enterSpiMode(spiHandle, saveDacEnable, savePhyEnable);
    }

    cmd[0] = NAND_CMD_BLOCK_ERASE;
    cmd[1] = 0x00;                  /* Dummy Byte */
    cmd[2] = (address >> 8) & 0xff; /* page address 2 bytes */
    cmd[3] = (address >> 0) & 0xff;
    cmdLen = 4;


    if (Nand_qspiWaitReady(spiHandle, NAND_WRR_WRITE_TIMEOUT, NULL))
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }
    
    /* Send Write Enable command */
    if (Nand_qspiCmdWrite(spiHandle, &cmdWren, 1, 0))
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    /* Wait for Flash device's BUSY but to clear */
    if (Nand_qspiWaitReady(spiHandle, NAND_WRR_WRITE_TIMEOUT, NULL))
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    /* Send Block Erase command */
    if (Nand_qspiCmdWrite(spiHandle, cmd, cmdLen, 0))
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    /* Wait for Flash device's BUSY but to clear and then check the EFAIL bit */
    uint8_t sr3 = 0xFF;
    if (Nand_qspiWaitReady(spiHandle, NAND_BULK_ERASE_TIMEOUT, &sr3))
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }
    if (sr3 & NAND_SR3_E_FAIL_MASK)
    {
        SPI_log("\n Erasing block 0x%x Failed \n", erLoc);
        return NAND_FAIL;
    }

    /* TODO (amendola) check E_FAIL bit in SR3 */

    if (saveXferLines == OSPI_XFER_LINES_QUAD)
    {
        Nand_enterQspiMode(spiHandle, saveDacEnable, savePhyEnable, saveDtrEnable);
    }

    return NAND_PASS;
}
