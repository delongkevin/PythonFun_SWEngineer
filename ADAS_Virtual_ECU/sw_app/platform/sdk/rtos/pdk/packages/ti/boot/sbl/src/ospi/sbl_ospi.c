/**
 *  \file    sbl_ospi.c
 *
 *  \brief   This file contains functions for OSPI read/write operations for SBL
 *
 */

/*
 * Copyright (C) 2018-2022 Texas Instruments Incorporated - http://www.ti.com/
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
#include "sbl_err_trap.h"
#include "sbl_sci_client.h"
#include "sbl_soc_cfg.h"

#if SBL_USE_DMA
#include "sbl_dma.h"
#endif

/* TI-RTOS Header files */
#include <ti/drv/spi/SPI.h>
#if SBL_USE_DMA
#include <ti/drv/udma/udma.h>
#endif

#include <ti/drv/spi/src/SPI_osal.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/drv/spi/src/v0/OSPI_v0.h>
#include <ti/drv/sciclient/sciclient.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/arch/r5/csl_arm_r5.h>
#include <ti/csl/arch/r5/interrupt.h>
#include <ti/board/board_cfg.h>
#include <ti/board/src/flash/include/board_flash.h>
#include "sbl_ospi.h"

/* Macro representing the offset where the App Image has to be written/Read from
   the OSPI Flash.
*/
#define OSPI_OFFSET_SEC_CERT        (0x6600200U)
#define OSPI_OFFSET_SI              (0x200000U)
#define OSPI_OFFSET_SYSFW           (0x80000U)
#define OSPI_OFFSET_HSM_APPIMAGE    (0xC0000U)
#define OSPI_MPU_REGION_NUM         (0x6)
#define OSPI_MPU_ENABLE_REGION      (0x1)

/** Modes for Write and Read operation: TODO: Shruthi R - This is not needed, not used for NAND but defined here to maintain same interface */
#define OSPI_FLASH_SINGLE_READ           (0U)
#define OSPI_FLASH_OCTAL_READ            (1U)

/* Phy Tuning at Init */
#define PHYTUNETESTSZ 512U
#define TEST_PHY_TUNE_FAIL_RETRY_MAX 1U

/* Macro to specify the counter number */
#define CNTR_NUMBER 0x1F

/* Initialize the OSPI driver and the controller. */
static void SBL_OSPI_Initialize(void);

void SBL_DCacheClean(void *addr, uint32_t size);

void SBL_SysFwLoad(void *dst, void *src, uint32_t size);

static void *boardHandle = NULL;

static OSPI_v0_HwAttrs ospi_cfg;

/* Global variable to check whether BUILD_XIP is defined or not */
bool isXIPEnable = false;

uint8_t __attribute__((section(".fcopy"))) tmpRxBuf[SBL_SYSFW_MAX_SIZE] = {0};

/* SBL scratch memory defined at compile time */
static uint8_t* sbl_scratch_mem = ((uint8_t*)(SBL_SCRATCH_MEM_START));
static uint32_t sbl_scratch_sz = SBL_SCRATCH_MEM_SIZE;

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
/**
 *  \brief UDMA TR packet descriptor memory.
 *  This contains the CSL_UdmapCppi5TRPD + Padding to sizeof(CSL_UdmapTR15) +
 *  one Type_15 TR (CSL_UdmapTR15) + one TR response of 4 bytes.
 *  Since CSL_UdmapCppi5TRPD is less than CSL_UdmapTR15, size is just two times
 *  CSL_UdmapTR15 for alignment.
 */
#define UDMA_TEST_APP_TRPD_SIZE         ((sizeof(CSL_UdmapTR15) * 2U) + 4U)

/*
 * UDMA driver objects
 */
struct Udma_DrvObj      gUdmaDrvObj;
struct Udma_ChObj       gUdmaChObj;
struct Udma_EventObj    gUdmaCqEventObj;

static Udma_DrvHandle          gDrvHandle = NULL;
/*
 * UDMA Memories
 */
uint8_t gTxRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
uint8_t gTxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
uint8_t gTxTdCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
uint8_t gUdmaTprdMem[UDMA_TEST_APP_TRPD_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
OSPI_dmaInfo gUdmaInfo;

static int32_t Ospi_udma_deinit(void);
static int32_t Ospi_udma_init(OSPI_v0_HwAttrs *cfg);

static int32_t Ospi_udma_init(OSPI_v0_HwAttrs *cfg)
{
    int32_t         retVal = UDMA_SOK;
    Udma_InitPrms   initPrms;
    uint32_t        instId;

    if (gDrvHandle == (Udma_DrvHandle)uint32_to_void_ptr(0U))
    {
        /* UDMA driver init */
        instId = UDMA_INST_ID_MCU_0;

        UdmaInitPrms_init(instId, &initPrms);
        retVal = Udma_init(&gUdmaDrvObj, &initPrms);
        if(UDMA_SOK == retVal)
        {
            gDrvHandle = &gUdmaDrvObj;
        }
    }

    if(gDrvHandle)
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

static int32_t Ospi_udma_deinit(void)
{
    int32_t         retVal = UDMA_SOK;

    if (gDrvHandle)
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

int32_t SBL_ReadSysfwImage(void **pBuffer, uint32_t num_bytes)
{
#if !defined(SBL_BYPASS_OSPI_DRIVER) && !defined(SBL_BYPASS_OSPI_DRIVER_FOR_SYSFW_DOWNLOAD)
    Board_flashHandle h;

    /* Init SPI driver */
    OSPI_init();

    /* Get default OSPI cfg */
    OSPI_socGetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);

    ospi_cfg.cacheEnable = true;
    ospi_cfg.dacEnable = true;
    ospi_cfg.dmaEnable = false; /* If required enable the DMA after reading SYSFW to avoid firewall conflicts */
    ospi_cfg.xipEnable = false;
    ospi_cfg.phyEnable = false;
    ospi_cfg.dtrEnable = false;
    ospi_cfg.xferLines = OSPI_XFER_LINES_OCTAL;
    ospi_cfg.intrEnable = false;
    ospi_cfg.funcClk = OSPI_MODULE_CLK_200M;
    ospi_cfg.pageSize = 4096;
    ospi_cfg.blkSize = 64 * 4096;
    ospi_cfg.baudRateDiv = 4;

#if 0
#if defined(SOC_J7200) || defined(SOC_J721S2) || defined(SOC_J784S4)
    ospi_cfg.funcClk = OSPI_MODULE_CLK_200M;
#else
    ospi_cfg.funcClk = OSPI_MODULE_CLK_133M;
#endif

    /* false: unstable, cpu read @ 120Mbytes per sec          */
    /*        can work with direct ROM load once it is stable */
    /* true:  stable, CPU read @60Mbytes per sec, will not    */
    /*        work with ROM, as ROM needs byte accesses       */
    ospi_cfg.dtrEnable = true;

    /* OSPI clock is set to 200MHz by RBL on J7200, J721S2 & J784S4 platforms.
     * PHY mode cannot be used until sysfw is loaded and OSPI clock is
     * configured to 133MHz.
     */
#if defined(SIM_BUILD) || defined(SOC_J7200) || defined(SOC_J721S2) || defined(SOC_J784S4)
    ospi_cfg.phyEnable = false;
#endif

if (isXIPEnable == true)
{
    ospi_cfg.phyEnable = false;
    /* OSPI baud rate = (master reference clock) / (baud rate devisor)
     * Default baud rate devisor is 32
     * Using a smaller devisor to get higher speeds */
    ospi_cfg.baudRateDiv = 6;
}
else
{
    #if defined(SOC_J721E)
        ospi_cfg.phyEnable = false;
        /* OSPI baud rate = (master reference clock) / (baud rate devisor)
        * Default baud rate devisor is 32
        * Using a smaller devisor to get higher speeds */
        ospi_cfg.baudRateDiv = 6;
    #endif
}

    /* Set the default SPI init configurations */
    ospi_cfg.cacheEnable = 1;
#endif
    OSPI_socSetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);

#if defined(SOC_J7200) || defined(SOC_J721S2) || defined(SOC_J784S4) || defined(SOC_AM64X)
    h = Board_flashOpen(BOARD_FLASH_ID_W35N01JWTBAG,
                        BOARD_OSPI_NOR_INSTANCE, NULL);
#else
    h = Board_flashOpen(BOARD_FLASH_ID_MT35XU512ABA1G12,
                        BOARD_OSPI_NOR_INSTANCE, NULL);
#endif

    if (h)
    {

        /* Disable PHY pipeline mode */
        CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(ospi_cfg.baseAddr), FALSE);

#if defined(SOC_J7200) || defined(SOC_J721S2) || defined(SOC_J784S4)
        /* Until OSPI PHY + DMA is enabled at this early stage, the
         * ROM can more efficiently load the SYSFW directly from xSPI flash */

        Board_flashRead(h, 0x80000 , &tmpRxBuf[0], SBL_SYSFW_MAX_SIZE , NULL);

        if(pBuffer)
        {
            /* Set up ROM to load system firmware */
            *pBuffer = (void*)(tmpRxBuf);
            //*pBuffer = (void *)(ospi_cfg.dataAddr + OSPI_OFFSET_SYSFW);
        }
#else
        /* Optimized CPU copy loop - can be removed once ROM load is working */
        SBL_SysFwLoad((void *)(*pBuffer), (void *)(ospi_cfg.dataAddr + OSPI_OFFSET_SYSFW), num_bytes);
#endif

        /* Update handle for later use*/
        boardHandle = (void *)h;
    }
    else
    {
        SBL_log(SBL_LOG_ERR, "Board_flashOpen failed!\n");
        SblErrLoop(__FILE__, __LINE__);
    }

    return CSL_PASS;
#else

     /* Get default OSPI cfg */
    OSPI_socGetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);

   if(pBuffer)
   {
      /* Set up ROM to load system firmware */
      *pBuffer = (void *)(ospi_cfg.dataAddr + OSPI_OFFSET_SYSFW);
   }

   return CSL_PASS;
#endif

}

void SBL_OSPICfg(void)
{
    /*Confgure SBL at SDR50MHZ*/
    (void)SBL_ospiInit(&boardHandle, false);
}

#if defined(SOC_J721E) || defined(SOC_J7200) || defined(SOC_J721S2) || defined(SOC_J784S4)
void OSPI_configClk(uint32_t freq)
{
    OSPI_v0_HwAttrs ospi_cfg;
	int32_t retVal;
    uint64_t ospi_rclk_freq;
    uint32_t parClk;
    uint32_t clkID[] = {
                           TISCI_DEV_MCU_FSS0_OSPI_0_OSPI_RCLK_CLK,
                           TISCI_DEV_MCU_FSS0_OSPI_1_OSPI_RCLK_CLK
    };
    uint32_t devID[] = {
                           TISCI_DEV_MCU_FSS0_OSPI_0,
                           TISCI_DEV_MCU_FSS0_OSPI_1
    };

    /* Get the default SPI init configurations */
    OSPI_socGetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);

    retVal = Sciclient_pmModuleClkRequest(devID[BOARD_OSPI_NOR_INSTANCE],
                                          clkID[BOARD_OSPI_NOR_INSTANCE],
                                          TISCI_MSG_VALUE_CLOCK_SW_STATE_REQ,
                                          TISCI_MSG_FLAG_AOP,
                                          SCICLIENT_SERVICE_WAIT_FOREVER);
    if (retVal != CSL_PASS)
    {
        SBL_log(SBL_LOG_MAX, "Sciclient_pmModuleClkRequest failed \n");
    }

    /* Max clocks */
    if((freq == OSPI_MODULE_CLK_166M) || (freq == OSPI_MODULE_CLK_200M))
    {
        parClk = TISCI_DEV_MCU_FSS0_OSPI_0_OSPI_RCLK_CLK_PARENT_HSDIV4_16FFT_MCU_2_HSDIVOUT4_CLK;

        retVal = Sciclient_pmSetModuleClkParent(devID[BOARD_OSPI_NOR_INSTANCE],
                                                clkID[BOARD_OSPI_NOR_INSTANCE],
                                                parClk,
                                                SCICLIENT_SERVICE_WAIT_FOREVER);
    }
    else
    {
        parClk = TISCI_DEV_MCU_FSS0_OSPI_0_OSPI_RCLK_CLK_PARENT_HSDIV4_16FFT_MCU_1_HSDIVOUT4_CLK;
        retVal = Sciclient_pmSetModuleClkParent(devID[BOARD_OSPI_NOR_INSTANCE],
                                                clkID[BOARD_OSPI_NOR_INSTANCE],
                                                parClk,
                                                SCICLIENT_SERVICE_WAIT_FOREVER);
    }

    if (retVal != CSL_PASS)
    {
        SBL_log(SBL_LOG_MAX, "Sciclient_pmSetModuleClkParent failed \n");
    }

    ospi_cfg.funcClk = freq;
    OSPI_socSetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);

    ospi_rclk_freq = (uint64_t)freq;
    retVal = Sciclient_pmSetModuleClkFreq(devID[BOARD_OSPI_NOR_INSTANCE],
                                          clkID[BOARD_OSPI_NOR_INSTANCE],
                                          ospi_rclk_freq,
                                          TISCI_MSG_FLAG_AOP,
                                          SCICLIENT_SERVICE_WAIT_FOREVER);

    if (retVal != CSL_PASS)
    {
        SBL_log(SBL_LOG_MAX, "Sciclient_pmSetModuleClkFreq failed \n");
    }

    ospi_rclk_freq = 0;
    retVal = Sciclient_pmGetModuleClkFreq(devID[BOARD_OSPI_NOR_INSTANCE],
                                          clkID[BOARD_OSPI_NOR_INSTANCE],
                                          &ospi_rclk_freq,
                                          SCICLIENT_SERVICE_WAIT_FOREVER);
    if (retVal != CSL_PASS)
    {
        SBL_log(SBL_LOG_MAX, "Sciclient_pmGetModuleClkFreq failed \n");
    }

    SBL_log(SBL_LOG_MAX, "OSPI RCLK running at %d MHz. \n", (uint32_t)ospi_rclk_freq);

}
#endif

void OSPI_Cfg_SDR50TAPS(void)
{
    /* Get default OSPI cfg */
    OSPI_socGetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);
    ospi_cfg.cacheEnable = true;
    ospi_cfg.dacEnable = true;
    ospi_cfg.dmaEnable = false;
    ospi_cfg.xipEnable = false;
    ospi_cfg.phyEnable = false;
    ospi_cfg.dtrEnable = false;
    ospi_cfg.xferLines = OSPI_XFER_LINES_OCTAL;
    ospi_cfg.intrEnable = false;
    ospi_cfg.pageSize = 4096;
    ospi_cfg.blkSize = 64 * 4096;

    ospi_cfg.devDelays[0] = 0u;
    ospi_cfg.devDelays[1] = 0u;
    ospi_cfg.devDelays[2] = 0u;
    ospi_cfg.devDelays[3] = OSPI_DEV_DELAY_CSDA_3;
    ospi_cfg.baudRateDiv = 4;
    ospi_cfg.funcClk = (OSPI_MODULE_CLK_200M);
    OSPI_configClk(ospi_cfg.funcClk);

#if SBL_USE_DMA
    //Ospi_udma_init(&ospi_cfg);
#endif

    /* Set the default SPI init configurations */
    OSPI_socSetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);
}


void OSPI_Cfg_SDR166PHY(void)
{
    /* Get default OSPI cfg */
    OSPI_socGetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);
    ospi_cfg.cacheEnable = true;
    ospi_cfg.dacEnable = true;
#if SBL_USE_DMA
    ospi_cfg.dmaEnable = true;
#else
    ospi_cfg.dmaEnable = false;
#endif
    ospi_cfg.xipEnable = false;
    ospi_cfg.phyEnable = true;
    ospi_cfg.dtrEnable = false;
    ospi_cfg.xferLines = OSPI_XFER_LINES_OCTAL;
    ospi_cfg.intrEnable = false;
    ospi_cfg.pageSize = 4096;
    ospi_cfg.blkSize = 64 * 4096;

    ospi_cfg.funcClk = (OSPI_MODULE_CLK_166M);
    ospi_cfg.phyOpMode = CSL_OSPI_CFG_PHY_OP_MODE_MASTER;
    ospi_cfg.phyLockCycle = CSL_OSPI_LOCK_CYCLE_HALF;
    ospi_cfg.baudRateDiv = 0U;
    /* TODO : Check the following delays with Electrical for production usecase */
    ospi_cfg.devDelays[0] = 0x0AU;
    ospi_cfg.devDelays[1] = 0x0AU;
    ospi_cfg.devDelays[2] = 0x0AU;
    ospi_cfg.devDelays[3] = 0x0AU;

    OSPI_configClk(ospi_cfg.funcClk);

#if SBL_USE_DMA
    Ospi_udma_init(&ospi_cfg);
#endif

    /* Set the default SPI init configurations */
    OSPI_socSetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);
}

int32_t SBL_SpiPhyTune(void)
{
    Board_flashHandle h;
    static uint32_t enableTuning = TRUE;
    int32_t ret_val=0u;
    uint32_t readMode = OSPI_FLASH_OCTAL_READ;

#if (SBL_USE_DMA)
    uint8_t rxBuf[PHYTUNETESTSZ]  __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
#else
    uint8_t rxBuf[PHYTUNETESTSZ]  __attribute__((aligned(128U)));
#endif
    uint8_t phyTuneRetryCnt;
    NAND_STATUS flashStatus;
    phyTuneRetryCnt = TEST_PHY_TUNE_FAIL_RETRY_MAX;
    while(phyTuneRetryCnt)
    {

        flashStatus = Board_flashRead((Board_flashHandle)boardHandle, 0U, &rxBuf[0], PHYTUNETESTSZ, (void *)(&readMode));
        if(flashStatus != 0u)
        {
            if(flashStatus == BOARD_FLASH_PHY_TUNE_FAIL)
            {
                if(phyTuneRetryCnt)
                {
                    SBL_log(SBL_LOG_ERR, " PHY tuning Failed for iteration %d. Retrying...\n",
                            (TEST_PHY_TUNE_FAIL_RETRY_MAX - phyTuneRetryCnt));
                    phyTuneRetryCnt--;
                }
            }
            else
            {
                SBL_log(SBL_LOG_ERR, " PHY Tuning Fail exceeded Max Retried, switching to SDR50MHz TAPs. \n");
                if(BOARD_FLASH_EOK != Board_flashClose((Board_flashHandle)boardHandle))
                {
                    SBL_log(SBL_LOG_ERR, "Board_flashClose failed at SDR166MHz PHY. NAND Error. \n");
                    SblErrLoop(__FILE__, __LINE__);
                }
                else
                {

#if SBL_USE_DMA
                    Ospi_udma_deinit();
#endif
                }
                phyTuneRetryCnt = 0u;
            }
            ret_val = -1;
        }
        else
        {
            SBL_log(SBL_LOG_ERR, "\n PHY Tuning Success");
            phyTuneRetryCnt = 0u;
            ret_val = 0;
        }


    }

    return ret_val;
}

int32_t SBL_ospiInit(void *handle, bool phyena)
{
#if (!defined(SBL_BYPASS_OSPI_DRIVER) \
     /* In simulation, we must ALWAYS bypass the OSPI driver regardless of what */ \
     /* .. bypass option is requested. REMOVE WHEN SIMULATION IS IRRELEVANT. */ \
     && !(defined(SBL_BYPASS_OSPI_DRIVER_FOR_SYSFW_DOWNLOAD) && defined(SIM_BUILD)))

    Board_flashHandle h = *(Board_flashHandle *) handle;
    static uint32_t enableTuning;
    int32_t ret_val=0u;

    if (h)
    {
        Board_flashClose(h);
    }

    /* OSPI_Cfg_SDR50TAPS(); */ /*TODO: Make this runtime or build time configurable if needed*/

    if(phyena)
    {
        OSPI_Cfg_SDR166PHY();
        enableTuning = TRUE;
    }
    else
    {
        OSPI_Cfg_SDR50TAPS();
        enableTuning = FALSE;
    }

    h = Board_flashOpen(BOARD_FLASH_ID_W35N01JWTBAG,
                        BOARD_OSPI_NAND_INSTANCE, (void *)(&enableTuning));

    if (h)
    {
        *(Board_flashHandle *) handle = h;
        /* Update the static handle as well, for later use */
        boardHandle = (void *)h;
#if !(SBL_USE_DMA)
        /* Disable PHY pipeline mode if not using DMA */
        CSL_ospiPipelinePhyEnable((const CSL_ospi_flash_cfgRegs *)(ospi_cfg.baseAddr), FALSE);
#endif
        if(phyena)
        {
            ret_val = SBL_SpiPhyTune();
        }
    }
    else
    {
        SBL_log(SBL_LOG_ERR, "Board_flashOpen failed! phyena=%d\n",phyena);
        SblErrLoop(__FILE__, __LINE__);
    }
    return ret_val;
#else
    return 0;
#endif
}


int32_t SBL_ospiFlashRead(const void *handle, uint8_t *dst, uint32_t length, uint32_t offset)
{
    uint32_t start_time = CSL_armR5PmuReadCntr(CNTR_NUMBER);
    uint32_t end_time = 0;

#if (!defined(SBL_BYPASS_OSPI_DRIVER) \
     /* In simulation, we must ALWAYS bypass the OSPI driver regardless of what */ \
     /* .. bypass option is requested. REMOVE WHEN SIMULATION IS IRRELEVANT. */ \
     && !(defined(SBL_BYPASS_OSPI_DRIVER_FOR_SYSFW_DOWNLOAD) && defined(SIM_BUILD)))

#if SBL_USE_DMA
    Board_flashHandle h = *(const Board_flashHandle *) handle;
    uint32_t ioMode = OSPI_FLASH_OCTAL_READ;

    if (length > 4 * 1024)
    {
        /* split transfer if not reading from 16 byte aligned flash offset */
        uint32_t dma_offset  = (offset + 0xF) & (~0xF);
        uint32_t non_aligned_bytes = dma_offset - offset;
        uint8_t *dma_dst = (dst + non_aligned_bytes);
        uint32_t dma_len = length - non_aligned_bytes;

        SBL_DCacheClean((void *)dst, length);

        if ((non_aligned_bytes) && (Board_flashRead(h, offset, dst, non_aligned_bytes, (void *)(&ioMode))))
        {
            SBL_log(SBL_LOG_ERR, "Board_flashRead failed!\n");
            SblErrLoop(__FILE__, __LINE__);
        }

        if (Board_flashRead(h, dma_offset, dma_dst, dma_len, (void *)(&ioMode)))
        {
            SBL_log(SBL_LOG_ERR, "Board_flashRead failed!\n");
            SblErrLoop(__FILE__, __LINE__);
        }
    }
    else
    {
        SBL_DCacheClean((void *)dst, length);
        Board_flashRead(h, offset, dst, length, (void *)(&ioMode));
    }

#else

    if(isXIPEnable == true)
    {
        Board_flashHandle h = *(const Board_flashHandle *) handle;
        uint32_t ioMode = OSPI_FLASH_OCTAL_READ;
        SBL_DCacheClean((void *)dst, length);
        Board_flashRead(h, offset, dst, length, (void *)(&ioMode));
    }
    else
    {
        #if defined(SOC_J721E) || defined(SOC_J721S2)
            Board_flashHandle h = *(const Board_flashHandle *) handle;
            uint32_t ioMode = OSPI_FLASH_OCTAL_READ;
            SBL_DCacheClean((void *)dst, length);
            Board_flashRead(h, offset, dst, length, (void *)(&ioMode));
        #else
            memcpy((void *)dst, (void *)(ospi_cfg.dataAddr + offset), length);
        #endif
    }

#endif /* #if SBL_USE_DMA */

#else
    memcpy((void *)dst, (void *)(ospi_cfg.dataAddr + offset), length);
#endif /* #if !defined(SBL_BYPASS_OSPI_DRIVER) */

    end_time = CSL_armR5PmuReadCntr(CNTR_NUMBER);

    SBL_log(SBL_LOG_MAX, "Ospi Read speed for 0x%x bytes from offset 0x%x = %d Mbytes per sec\n", length, offset, ((400000000 / (end_time-start_time)) * length)/0x100000);

    return 0;
}

static void SBL_ospiClkRestore(const void *handle)
{
    Board_flashHandle h;
    Board_FlashInfo *flashInfo;

    /* Get default OSPI cfg */
    OSPI_socGetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);

    ospi_cfg.cacheEnable = true;
    ospi_cfg.dacEnable = true;
    ospi_cfg.dmaEnable = false;
    ospi_cfg.xipEnable = false;
    ospi_cfg.phyEnable = false;
    ospi_cfg.dtrEnable = false;
    ospi_cfg.xferLines = OSPI_XFER_LINES_OCTAL;
    ospi_cfg.intrEnable = false;
    ospi_cfg.funcClk = OSPI_MODULE_CLK_200M;
    ospi_cfg.pageSize = 4096;
    ospi_cfg.blkSize = 64 * 4096;
    ospi_cfg.baudRateDiv = 4;
    ospi_cfg.devDelays[0] = 0;
    ospi_cfg.devDelays[1] = 0;
    ospi_cfg.devDelays[2] = 0;
    ospi_cfg.devDelays[3] = OSPI_DEV_DELAY_CSDA_3;
    OSPI_socSetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);
    OSPI_configClk(ospi_cfg.funcClk);
    h = Board_flashOpen(BOARD_FLASH_ID_W35N01JWTBAG,
                        BOARD_OSPI_NOR_INSTANCE, NULL);

    if (h)
    {
        SBL_log(SBL_LOG_MAX, "OSPI flash left configured in SDR50MHz Mode.\n");
        flashInfo = (Board_FlashInfo *)h;
        SBL_log(SBL_LOG_MAX, "\n OSPI NAND device ID: 0x%x, manufacturer ID: 0x%x \n",
                flashInfo->device_id, flashInfo->manufacturer_id);
        Board_flashClose(h);
    }
    else
    {
        SBL_log(SBL_LOG_ERR, "Board_flashOpen failed while restoring to SPI SDR50MHz mode!!\n");
    }

}

int32_t SBL_ospiClose(const void *handle)
{
#if (!defined(SBL_BYPASS_OSPI_DRIVER) \
     /* In simulation, we must ALWAYS bypass the OSPI driver regardless of what */ \
     /* .. bypass option is requested. REMOVE WHEN SIMULATION IS IRRELEVANT. */ \
     && !(defined(SBL_BYPASS_OSPI_DRIVER_FOR_SYSFW_DOWNLOAD) && defined(SIM_BUILD)))

    Board_flashHandle h = *(const Board_flashHandle *) handle;

    SBL_log(SBL_LOG_MAX, "SBL_ospiClose called\n");
    Board_flashClose(h);
#if SBL_USE_DMA
    Ospi_udma_deinit();
#endif
#else
#endif
    return 0;
}

#if defined(SBL_HLOS_OWNS_FLASH) && !defined(SBL_USE_MCU_DOMAIN_ONLY)
/* Only put OSPI flash back into SPI mode if we're going to directly boot ATF/U-boot/Linux from SBL */
int32_t SBL_ospiLeaveConfigSPI()
{
    int32_t retVal = E_PASS;
    Board_flashHandle h;
    Board_FlashInfo *flashInfo;

    /* Get default OSPI cfg */
    OSPI_socGetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);

    ospi_cfg.funcClk = OSPI_MODULE_CLK_133M;
    /* Configure the flash for SPI mode */
    ospi_cfg.xferLines = OSPI_XFER_LINES_SINGLE;
    /* Put controller in DAC mode so flash ID can be read directly */
    ospi_cfg.dacEnable = true;
    /* Disable PHY in legacy SPI mode (1-1-1) */
    ospi_cfg.phyEnable = false;
    ospi_cfg.dtrEnable = false;
    ospi_cfg.xipEnable = false;

    /* Set the default SPI init configurations */
    OSPI_socSetInitCfg(BOARD_OSPI_DOMAIN, BOARD_OSPI_NOR_INSTANCE, &ospi_cfg);

#if defined(SOC_J7200) || defined(SOC_J721S2) || defined(SOC_J784S4)
    h = Board_flashOpen(BOARD_FLASH_ID_W35N01JWTBAG,
                        BOARD_OSPI_NOR_INSTANCE, NULL);
#else
    h = Board_flashOpen(BOARD_FLASH_ID_MT35XU512ABA1G12,
                        BOARD_OSPI_NOR_INSTANCE, NULL);
#endif

    if (h)
    {
        SBL_log(SBL_LOG_MAX, "OSPI flash left configured in Legacy SPI mode.\n");
        flashInfo = (Board_FlashInfo *)h;
        SBL_log(SBL_LOG_MAX, "\n OSPI NOR device ID: 0x%x, manufacturer ID: 0x%x \n",
                flashInfo->device_id, flashInfo->manufacturer_id);
        Board_flashClose(h);
    }
    else
    {
        SBL_log(SBL_LOG_ERR, "Board_flashOpen failed in SPI mode!!\n");
        retVal = E_FAIL;
    }


    return(retVal);
}
#endif

int32_t SBL_OSPIBootImage(sblEntryPoint_t *pEntry)
{
    int32_t retVal;
    uint32_t offsetCertStore = OSPI_OFFSET_SEC_CERT;
#ifndef BUILD_HS
    uint32_t offset = OSPI_OFFSET_SI;
#else
    /*For HS devices HSM and Boot Manager should be combined in a multicore image*/
    uint32_t offset = OSPI_OFFSET_HSM_APPIMAGE;
#endif
    SBL_ADD_PROFILE_POINT;
    /* Initialization of the driver. */
    SBL_OSPI_Initialize();

#if defined(SBL_ENABLE_HLOS_BOOT) && (defined(SOC_J721E) || defined(SOC_J7200) || defined(SOC_J721S2) || defined(SOC_J784S4))
    retVal =  SBL_MulticoreImageParse((void *) &offset, OSPI_OFFSET_SI, pEntry, SBL_SKIP_BOOT_AFTER_COPY);
#elif defined(BUILD_HS)
    retVal = SBL_MulticoreImageParse((void*)&offset, OSPI_OFFSET_HSM_APPIMAGE, pEntry, SBL_BOOT_AFTER_COPY);
#else
    retVal =  SBL_MulticoreImageParse((void *) &offset, OSPI_OFFSET_SI, pEntry, SBL_BOOT_AFTER_COPY);
#endif

/*Disable Cert store Authentification*/

#if 0
    /* Initialize the function pointers to read from flash */
    fp_readData = &SBL_OSPI_ReadSectors;
    fp_seek = &SBL_OSPI_seek;

    /* Verify Cert Signature */
    retVal = SBL_CertStoreImageParse((void *) &offsetCertStore, OSPI_OFFSET_SEC_CERT);
    /* Comunicate result to HSM*/
    if (retVal != 0)
    {
        SBL_log(SBL_LOG_ERR, "Cert Store authentication failed\n");
 //       (*(volatile uint32_t*)0x43C3FFF0) = 0x4C494146;
    }
    else
    {
        SBL_log(SBL_LOG_ERR, "Cert Store authentication succeeded\n");
 //       (*(volatile uint32_t*)0x43C3FFF0) = 0x53534150;
    }
#endif
    SBL_ospiClose(&boardHandle);
    SBL_ospiClkRestore(&boardHandle);

if(isXIPEnable == true)
{
    #if (defined(SOC_J7200) || defined(SOC_J721S2) || defined(SOC_J784S4))
        /* These fields are reset by Nor_xspiClose but are required for XIP */

        const CSL_ospi_flash_cfgRegs *pRegs = (const CSL_ospi_flash_cfgRegs *)(ospi_cfg.baseAddr);

        CSL_REG32_FINS(&pRegs->RD_DATA_CAPTURE_REG,
                        OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_SAMPLE_EDGE_SEL_FLD,
                        1);

        CSL_REG32_FINS(&pRegs->RD_DATA_CAPTURE_REG,
                        OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_DQS_ENABLE_FLD,
                        1);
    #endif
}

#if defined(SBL_HLOS_OWNS_FLASH) && !defined(SBL_USE_MCU_DOMAIN_ONLY)
/* Only put OSPI flash back into SPI mode if we're going to directly boot ATF/U-boot/Linux from SBL */
    SBL_ospiLeaveConfigSPI();
#endif

    return retVal;
}

int32_t SBL_OSPIBootHsm(sblEntryPoint_t *pEntry)
{
    uint32_t offset = OSPI_OFFSET_HSM_APPIMAGE;

    /* Assume flash is already ready from TIFS load */
    fp_readData = &SBL_OSPI_ReadSectors;
    fp_seek     = &SBL_OSPI_seek;
    return SBL_MulticoreImageParse((void *) &offset, OSPI_OFFSET_HSM_APPIMAGE, pEntry, SBL_BOOT_AFTER_COPY);
}


static void SBL_OSPI_Initialize(void)
{
    //SBL_ospiInit(&boardHandle, true);
    /* Initialize the function pointers to parse through the RPRC format. */
    fp_readData = &SBL_OSPI_ReadSectors;
    fp_seek     = &SBL_OSPI_seek;
}

void SBL_SPI_init()
{
    OSPI_init();
}

int32_t SBL_OSPI_ReadSectors(void *dstAddr,
                             void *srcOffsetAddr,
                             uint32_t length)
{
    int32_t ret;
    ret = SBL_ospiFlashRead(&boardHandle, (uint8_t *) dstAddr, length,
        *((uint32_t *) srcOffsetAddr));
    *((uint32_t *) srcOffsetAddr) += length;
    return ret;
}

void SBL_OSPI_seek(void *srcAddr, uint32_t location)
{
    *((uint32_t *) srcAddr) = location;
}

void SBL_enableXIPMode()
{
    isXIPEnable = true;
}

