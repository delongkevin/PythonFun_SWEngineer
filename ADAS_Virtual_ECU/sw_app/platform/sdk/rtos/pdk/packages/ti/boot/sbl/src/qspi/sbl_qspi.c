/**
 *  \file    sbl_qspi.c
 *
 *  \brief   This file contains functions for QSPI read/write operations for SBL
 *
 */

/*
 * Copyright (C) 2020 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include "string.h"

/* SBL Header files. */
#include "sbl_soc.h"
#include "sbl_rprc_parse.h"
#include "sbl_soc_cfg.h"
#include "sbl_err_trap.h"

/* TI-RTOS Header files */
#include <ti/drv/spi/SPI.h>
#if SBL_USE_DMA
#include <ti/drv/udma/udma.h>
#endif

#include <ti/osal/DebugP.h>
#include <ti/drv/spi/src/SPI_osal.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/drv/spi/src/v0/OSPI_v0.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/arch/r5/csl_arm_r5.h>
#include <ti/csl/arch/r5/interrupt.h>
#include <ti/board/board_cfg.h>
#include <ti/board/src/flash/include/board_flash.h>
#include "sbl_qspi.h"

#if defined(j721s2_hyd)

#define QSPI_FLASH_ID           BOARD_FLASH_ID_W25N01GW

#undef  QSPI_OFFSET_SI
#define QSPI_OFFSET_SI              (0x200000U)
#undef  QSPI_OFFSET_HSM_APPIMAGE
#define QSPI_OFFSET_HSM_APPIMAGE    (0xc0000)

 
#endif 


/* Initialize the QSPI driver and the controller. */
static void SBL_QSPI_Initialize(void);

void SBL_DCacheClean(void *addr, uint32_t size);

static void *boardHandle = NULL;

#ifdef j721s2_hyd
static OSPI_v0_HwAttrs qspi_cfg;
#endif


#if SBL_USE_DMA
/*
 * Ring parameters
 */
/** \brief Number of ring entries - we can prime this much memcpy operations */
#define UDMA_TEST_APP_RING_ENTRIES      (1U)
/** \brief Size (in bytes) of each ring entry (Size of pointer - 64-bit) */
#define UDMA_TEST_APP_RING_ENTRY_SIZE   (sizeof(uint64_t))
/** \brief Total ring memory */
#define UDMA_TEST_APP_RING_MEM_SIZE     (UDMA_TEST_APP_RING_ENTRIES * \
                                         UDMA_TEST_APP_RING_ENTRY_SIZE)
/** \brief This ensures every channel memory is aligned */
#define UDMA_TEST_APP_RING_MEM_SIZE_ALIGN ((UDMA_TEST_APP_RING_MEM_SIZE + UDMA_CACHELINE_ALIGNMENT) & ~(UDMA_CACHELINE_ALIGNMENT - 1U))
/**
 *  \brief UDMA TR packet descriptor memory.
 *  This contains the CSL_UdmapCppi5TRPD + Padding to sizeof(CSL_UdmapTR15) +
 *  one Type_15 TR (CSL_UdmapTR15) + one TR response of 4 bytes.
 *  Since CSL_UdmapCppi5TRPD is less than CSL_UdmapTR15, size is just two times
 *  CSL_UdmapTR15 for alignment.
 */
#define UDMA_TEST_APP_TRPD_SIZE         ((sizeof(CSL_UdmapTR15) * 2U) + 4U)

/** \brief This ensures every channel memory is aligned */
#define UDMA_TEST_APP_TRPD_SIZE_ALIGN   ((UDMA_TEST_APP_TRPD_SIZE + UDMA_CACHELINE_ALIGNMENT) & ~(UDMA_CACHELINE_ALIGNMENT - 1U))

/*
 * UDMA driver objects
 */
struct Udma_DrvObj      gUdmaDrvObj;
struct Udma_ChObj       gUdmaChObj;
struct Udma_EventObj    gUdmaCqEventObj;

Udma_DrvHandle          gDrvHandle = NULL;
/*
 * UDMA Memories
 */
static uint8_t gTxRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gTxTdCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gUdmaTprdMem[UDMA_TEST_APP_TRPD_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static OSPI_dmaInfo gUdmaInfo;


int32_t Ospi_udma_init(OSPI_v0_HwAttrs *cfg)
{
    int32_t         retVal = UDMA_SOK;
    Udma_InitPrms   initPrms;
    uint32_t        instId;

    if (gDrvHandle == NULL)
    {
        /* UDMA driver init */
        /* Use MCU NAVSS for MCU domain cores. Rest cores all uses Main NAVSS */
#if defined (BUILD_MCU1_0) || defined (BUILD_MCU1_1)
        instId = UDMA_INST_ID_MCU_0;
#else
        instId = UDMA_INST_ID_MAIN_0;
#endif

        UdmaInitPrms_init(instId, &initPrms);
        initPrms.printFxn = NULL;
        retVal = Udma_init(&gUdmaDrvObj, &initPrms);
        if(UDMA_SOK == retVal)
        {
            gDrvHandle = &gUdmaDrvObj;
        }
    }

    if(gDrvHandle != NULL)
    {
        gUdmaInfo.drvHandle      = (void *)gDrvHandle;
        gUdmaInfo.chHandle       = (void *)&gUdmaChObj;
        gUdmaInfo.ringMem        = (void *)&gTxRingMem[0];
        gUdmaInfo.cqRingMem      = (void *)&gTxCompRingMem[0];
        gUdmaInfo.tdCqRingMem    = (void *)&gTxTdCompRingMem[0];
        gUdmaInfo.tprdMem        = (void *)&gUdmaTprdMem[0];
        gUdmaInfo.eventHandle    = (void *)&gUdmaCqEventObj;
        cfg->dmaInfo             = &gUdmaInfo;
    }

    return (retVal);
}

int32_t Ospi_udma_deinit(void)
{

    int32_t         retVal = UDMA_SOK;

    if (gDrvHandle != NULL)
    {
        retVal = Udma_deinit(gDrvHandle);
        if(UDMA_SOK == retVal)
        {
            gDrvHandle = NULL;
        }
    }

    return (retVal);
}
#endif


int32_t SBL_qspiInit(void *handle)
{
#if !defined(SBL_BYPASS_QSPI_DRIVER)
    Board_flashHandle h = *(Board_flashHandle *) handle;
    int32_t retVal; 
    uint32_t qspiClkFreq;

    SBL_ADD_PROFILE_POINT;

    if (h)
    {
        Board_flashClose(h);
        SBL_ADD_PROFILE_POINT;
    }
    retVal = OSPI_socGetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NAND_INSTANCE, &qspi_cfg);
    DebugP_assert(retVal == 0);
#if defined(j721s2_hyd)
    qspiClkFreq = OSPI_MODULE_CLK_80M;
    qspi_cfg.cacheEnable = true;
    qspi_cfg.dacEnable = true;
    qspi_cfg.dmaEnable = true;
    qspi_cfg.xipEnable = false;
    qspi_cfg.phyEnable = true;  /* does not work on 8.04 yet */
    qspi_cfg.dtrEnable = true;  /* has to be false when phyEnable is false */
    qspi_cfg.xferLines = OSPI_XFER_LINES_QUAD;
    qspi_cfg.intrEnable = false;
    qspi_cfg.pageSize = 2048;
    qspi_cfg.blkSize = 64 * 2048;
    qspi_cfg.baudRateDiv = 32;
#else
    #error "Configure QSPI qspiClkFreq for the SOC"
    qspiClkFreq = 0;
#endif

#ifdef j721s2_hyd
    /* Pulled from sbl_ospi.c */
    retVal = Sciclient_pmSetModuleClkFreq(SBL_DEV_ID_OSPI0, SBL_CLK_ID_OSPI0, qspiClkFreq, TISCI_MSG_FLAG_AOP, SCICLIENT_SERVICE_WAIT_FOREVER);
    DebugP_assert(retVal == CSL_PASS);
#endif

    qspi_cfg.funcClk = qspiClkFreq;

#if SBL_USE_DMA
    if (qspi_cfg.dmaEnable) {
        retVal = Ospi_udma_init(&qspi_cfg);
        DebugP_assert(retVal == UDMA_SOK);
    }
#else
    DebugP_assert(qspi_cfg.dmaEnable == false);
#endif

    /* Set the default SPI init configurations */
    OSPI_socSetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NAND_INSTANCE, &qspi_cfg);

    /* Use this parameter struct to enable PHY tuning. The driver will first check
       for an existing PHY tuning saved in RAM and reuse it if it exists (for example,
       if the SBL already tuned the PHY, the Boot App can reuse the tuning).
       If no tuning exists yet, it will do the tuning algorithm and save the results to RAM.
       To disable PHY tuning and use a hard-coded default tuning built into the driver binary,
       change phy_tuning_options to PHY_TUNING_USE_DEFAULT_TUNING_POINT. */
    Board_PhyTuningOptions phyTuningOptions;
    phyTuningOptions.struct_type_indicator_magic_number = BOARD_PHY_TUNING_OPTIONS_SCRUCT_MAGIC;
    phyTuningOptions.phy_tuning_options = PHY_TUNING_DO_TUNING;

    h = Board_flashOpen(QSPI_FLASH_ID,
                        BOARD_OSPI_NAND_INSTANCE, (void*)&phyTuningOptions);
    if (h)
    {
        *(Board_flashHandle *) handle = h;
        /* Update the static handle as well, for later use */
        boardHandle = (void *)h;
// #if !(SBL_USE_DMA) && !defined(SOC_J721E) && !defined(BUILD_XIP)
//         /* Disable PHY pipeline mode if not using DMA */
//         CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(qspi_cfg.baseAddr), FALSE);
// #endif
    }
    else
    {
        SBL_log(SBL_LOG_ERR, "Board_flashOpen failed!\n");
        SblErrLoop(__FILE__, __LINE__);
    }

    SBL_ADD_PROFILE_POINT;

    return 0;
#else
    SBL_ADD_PROFILE_POINT;

    SBL_ADD_PROFILE_POINT;
    return 0;
#endif
}

int32_t SBL_qspiFlashRead(void *handle, uint8_t *dst, uint32_t length,
    uint32_t offset)
{
    uint32_t start_time = SBL_ADD_PROFILE_POINT;
    uint32_t end_time = 0;
    Board_flash_STATUS result = 0;

#if !defined(SBL_BYPASS_QSPI_DRIVER)
    Board_flashHandle h = *(const Board_flashHandle *) handle;
    /* TODO @amendola is this needed? */
    SBL_DCacheClean((void *)dst, length);
    if (dst == 0x0) {
      /* This function may need to be able to write to 0x0 (when overwriting)
         the vector table during bootloading, hence this hack.
         TODO amendol figure out why the QSPI NAND driver didn't fail when 
         copying over the vector table */
      uint32_t write_to_addr_0_magic = WRITE_TO_ADDR_0_MAGIC;
      result = Board_flashRead(h, offset, dst, length, &write_to_addr_0_magic);
    } else {
      result = Board_flashRead(h, offset, dst, length, NULL);
    }
    if (result) {
      SBL_log(SBL_LOG_ERR, "\nProblem with Board_flashRead: %d\n", result);
    }
#else
    memcpy((void *)dst, (void *)(qspi_cfg.dataAddr + offset), length);
#endif /* #if !defined(SBL_BYPASS_QSPI_DRIVER) */

    end_time = SBL_ADD_PROFILE_POINT;

    SBL_log(SBL_LOG_MAX, "Qspi Read speed for 0x%x bytes from offset 0x%x = %d Mbytes per sec\n", length, offset, ((400000000 / (end_time-start_time)) * length)/0x100000);

    return result;
}

int32_t SBL_qspiClose(void *handle)
{
#if !defined(SBL_BYPASS_QSPI_DRIVER)
    Board_flashHandle h = *(const Board_flashHandle *) handle;

    SBL_ADD_PROFILE_POINT;

    SBL_log(SBL_LOG_MAX, "SBL_qspiClose called\n");
    Board_flashClose(h);
#if SBL_USE_DMA
    if (qspi_cfg.dmaEnable) {
      Ospi_udma_deinit();
    }
#endif
    SBL_ADD_PROFILE_POINT;
#else
    SBL_ADD_PROFILE_POINT;
    SBL_ADD_PROFILE_POINT;
#endif
    return 0;
}

int32_t SBL_QSPIBootImage(sblEntryPoint_t *pEntry)
{
    int32_t retVal;
#ifndef BUILD_HS
    uint32_t offset = QSPI_OFFSET_SI;
#else
    /*For HS devices HSM and Boot Manager should be combined in a multicore image*/
    uint32_t offset = QSPI_OFFSET_HSM_APPIMAGE;
#endif
    /* Initialization of the driver. */
    SBL_QSPI_Initialize();
#ifndef BUILD_HS
	retVal =  SBL_MulticoreImageParse((void *) &offset, QSPI_OFFSET_SI, pEntry, SBL_BOOT_AFTER_COPY);
#else
    retVal =  SBL_MulticoreImageParse((void *) &offset, QSPI_OFFSET_HSM_APPIMAGE, pEntry, SBL_BOOT_AFTER_COPY);
#endif
    SBL_qspiClose(&boardHandle);

    return retVal;
}

int32_t SBL_QSPIBootHsm(sblEntryPoint_t *pEntry)
{
    uint32_t offset = QSPI_OFFSET_HSM_APPIMAGE;

    /* Assume flash is already ready from TIFS load */
    fp_readData = &SBL_QSPI_ReadSectors;
    fp_seek     = &SBL_QSPI_seek;
    return SBL_MulticoreImageParse((void *) &offset, QSPI_OFFSET_HSM_APPIMAGE, pEntry, SBL_BOOT_AFTER_COPY);
}

static void SBL_QSPI_Initialize(void)
{
    int32_t status = SBL_qspiInit(&boardHandle);

    if (status) {
        SBL_log(SBL_LOG_ERR, "SBL_qspiInit failed!\n");
        SblErrLoop(__FILE__, __LINE__);
    }

    /* Initialize the function pointers to parse through the RPRC format. */

    fp_readData = &SBL_QSPI_ReadSectors;
    fp_seek     = &SBL_QSPI_seek;

}

void SBL_SPI_init()
{
    SPI_init();
}

int32_t SBL_QSPI_ReadSectors(void *dstAddr,
                             void *srcOffsetAddr,
                             uint32_t length)
{
    int32_t ret;
    ret = SBL_qspiFlashRead(&boardHandle, (uint8_t *) dstAddr, length,
        *((uint32_t *) srcOffsetAddr));

    /* NOTE: for now we're panicking immediately if the read fails. We could remove this panic and allow the 
       caller to handle the failure as needed.
    */
    if (ret) {
        SBL_log(SBL_LOG_ERR, "SBL_qspiFlashRead failed!\n");
        SblErrLoop(__FILE__, __LINE__);
    }

    *((uint32_t *) srcOffsetAddr) += length;
    return ret;
}

void SBL_QSPI_seek(void *srcAddr, uint32_t location)
{
    *((uint32_t *) srcAddr) = location;
}

/* Copied from sbl_ospi.c */
int32_t SBL_ReadSysfwImage(void **pBuffer, uint32_t num_bytes)
{
#if !defined(SBL_BYPASS_QSPI_DRIVER) && !defined(SBL_BYPASS_QSPI_DRIVER_FOR_SYSFW_DOWNLOAD)
    Board_flashHandle h;

    SBL_ADD_PROFILE_POINT;

    /* Init SPI driver */
    OSPI_init();

    /* Get default OSPI cfg */
    OSPI_socGetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NAND_INSTANCE, &qspi_cfg);

    /* TODO amendola try speeding up by setting tap generator settings */
    qspi_cfg.cacheEnable = true;
    qspi_cfg.dacEnable = true;
    qspi_cfg.dmaEnable = false;
    qspi_cfg.xipEnable = false;
    qspi_cfg.phyEnable = false;
    qspi_cfg.dtrEnable = false;
    qspi_cfg.xferLines = OSPI_XFER_LINES_QUAD;
    qspi_cfg.intrEnable = false;
    qspi_cfg.funcClk = OSPI_MODULE_CLK_200M;
    qspi_cfg.pageSize = 2048;
    qspi_cfg.blkSize = 64 * 2048;
    qspi_cfg.baudRateDiv = 4;

    /* Set the default SPI init configurations */
    OSPI_socSetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NAND_INSTANCE, &qspi_cfg);

    h = Board_flashOpen(QSPI_FLASH_ID,
                        BOARD_OSPI_NAND_INSTANCE, (void*)NULL);

    if (h)
    {
        SBL_ADD_PROFILE_POINT;

        /* Disable PHY pipeline mode */
        CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(qspi_cfg.baseAddr), FALSE);

        if(pBuffer)
        {
            /* Set up ROM to load system firmware */
            int32_t result = SBL_qspiFlashRead((void*)&h, (void *)(*pBuffer), num_bytes, 0x80000);
            if (result) {
                SBL_log(SBL_LOG_ERR, "SBL_qspiFlashRead failed!\n");
                SblErrLoop(__FILE__, __LINE__);
            }
        }

        /* Update handle for later use*/
        boardHandle = (void *)h;
    }
    else
    {
        SBL_log(SBL_LOG_ERR, "Board_flashOpen failed!\n");
        SblErrLoop(__FILE__, __LINE__);
    }

    SBL_ADD_PROFILE_POINT;

    return CSL_PASS;
#else
   SBL_ADD_PROFILE_POINT;

     /* Get default OSPI cfg */
    OSPI_socGetInitCfg(BARD_OSPI_DOMAIN, BOARD_OSPI_NAND_INSTANCE, &qspi_cfg);

   if(pBuffer)
   {
      /* Set up ROM to load system firmware */
      *pBuffer = (void *)(qspi_cfg.dataAddr + OSPI_OFFSET_SYSFW);
   }

   SBL_ADD_PROFILE_POINT;

   return CSL_PASS;
#endif

}
