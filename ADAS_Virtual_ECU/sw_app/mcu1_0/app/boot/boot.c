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
 *  \file     boot.c
 *
 *  \brief    This file implements booting of main domain core applications
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "Std_Types.h"
#include <stdio.h>

#include <ti/boot/sbl/src/rprc/sbl_rprc_parse.h>
#if defined(BOOT_MMCSD)
#include <ti/boot/sbl/src/mmcsd/sbl_mmcsd.h>
#endif
#if defined(BOOT_OSPI)
#include <ti/boot/sbl/src/ospi/sbl_ospi.h>
#include <ti/board/src/flash/nand/ospi/nand_spi_phy_tune.h>
#endif
#if defined(BOOT_QSPI)
#include <ti/boot/sbl/src/qspi/sbl_qspi.h>
#endif
#include <ti/boot/sbl/soc/sbl_soc.h>
#include <ti/boot/sbl/soc/k3/sbl_slave_core_boot.h>
#include <ti/boot/sbl/soc/k3/sbl_profile.h>
#include <ti/boot/sbl/soc/k3/sbl_soc_cfg.h>
#include <ti/boot/sbl/soc/k3/sbl_qos.h>
#include <ti/boot/sbl/soc/k3/sbl_log.h>
#include <ti/boot/sbl/soc/k3/sbl_qos.h>

#include <ti/csl/cslr_gtc.h>

#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
#include <ti/drv/mmcsd/src/MMCSD_osal.h>

#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/board/board.h>
#include <ti/board/board_cfg.h>
#include <ti/board/src/flash/include/board_flash.h>
#if defined(SOC_J721E)
#include <ti/board/src/j721e_evm/include/board_control.h>
#endif
#if defined(SOC_J7200)
#include <ti/board/src/j7200_evm/include/board_control.h>
#endif
#include "app_log.h"
#include "app_log_Boot.h"
#include "boot_cfg.h"
#include "boot_core_defs.h"
#include "boot_feature_calib.h"
//#include "app_utils.h"
//#include "mcu_timer_multicore.h"
#include "bist.h"

#include <ti/osal/osal.h>
#include <ti/osal/TaskP.h>

#include "Rte_SWC_ProxiConfigMgr.h"
#include "CalDataProvider_defs.h"
#include "NvM.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define BIST_TASK_PRIORITY   (3)
#define BIST_TASK_STACKSIZE  (10U * 1024U)
#define FEATURE_CALIBRATION_CRC_ENABLE
/*PRQA S  2880 EOF*/
#if defined(FEATURE_CALIBRATION_CRC_ENABLE)


#define CRC32_POLY 0xEDB88320U
#define CRC32_INIT 0xFFFFFFFFU
#define CRC32_FINI 0xFFFFFFFFU



#endif
/* Enables SBL logs */
/* #define SBL_BOOTLOG_OUTPUT_ENABLED */

#if !defined(SOC_J721E) && !defined(SOC_J7200) && !defined(SOC_J721S2)
/* Performs Sciclient board setup for DEVGRP_01 */
#define BOOTAPP_MAINDOMAIN_BOARD_SETUP
#endif

/* Includes timestamps for OSPI memcpy's.
 * Should only be defined for OSPI build */
/* #define PROFILE_OSPI_READS_ENABLED */
/* Includes printout of Boot Stage core requests and image copies */
/* #define GATHER_STAGE_DETAILS */

/* NOTE: Secure boot is not yet supported on J721E */
/* #define SECURE_BOOT */

#define SBL_MPU_CLOCK_RECONFIG (6)
#define DEF_MAX_PHYTUNE_FAIL_CNT (65535u)
extern uint16 Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_MirrorBlock;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

#if defined(BOOTAPP_MAINDOMAIN_BOARD_SETUP)
struct bootApp_boardcfg_rm_resasg
{
    struct tisci_boardcfg_substructure_header subhdr;
    uint16_t                    resasg_entries_size;
    uint16_t                    reserved;
} __attribute__((__packed__));

struct bootApp_boardcfg_rm
{
    struct tisci_boardcfg_abi_rev     rev;
    struct tisci_boardcfg_rm_host_cfg host_cfg;
    struct bootApp_boardcfg_rm_resasg resasg;
} __attribute__((__packed__));

struct bootApp_local_rm_boardcfg
{
    struct bootApp_boardcfg_rm            rm_boardcfg;
    struct tisci_boardcfg_rm_resasg_entry resasg_entries[TISCI_RESASG_ENTRIES_MAX];
};

struct tisci_boardcfg bootAppBoardCfg __attribute__((section(".sysfw_data_cfg_board")));
struct bootApp_local_rm_boardcfg bootAppBoardCfg_rm __attribute__((section(".sysfw_data_cfg_board_rm")));
struct tisci_boardcfg_sec bootAppBoardCfg_sec __attribute__((section(".sysfw_data_cfg_board_sec")));
#endif /* BOOTAPP_MAINDOMAIN_BOARD_SETUP */

typedef struct
{
    uint8_t     sbl_boot_buff[SBL_MAX_BOOT_BUFF_SIZE+1];
    uint32_t    sbl_boot_size;
    uint32_t    sbl_boot_buff_idx;
} SBL_incomingBootData_S;

/* ========================================================================== */
/*              Internal Function Declarations                                */
/* ========================================================================== */
static void Read_Feature_Offset_Data(void);
static void Read_Feature_Calibration_Data(void);
static void Read_USS_Calibration_Data(void);
static void Read_THA_Calibration_Data(void);
static void Read_SVS_Calibration_Data(void);
static void Read_TRSC_Calibration_Data(void);
static void Read_APA_Calibration_Data(void);
static void Read_FOD_Calibration_Data(void);
static void Read_LMD_Calibration_Data(void);
static void SBL_ChangeMPUClock(uint32_t idx);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#if defined(BIST_TASK_ENABLED)
static uint8_t Bist_TaskStack[BIST_TASK_STACKSIZE] __attribute__((aligned(32)));
#endif

#if defined(BOOT_OSPI)
/* Offset into app image that is being processed */
/* static uint32_t xipMemBase = 0x50000000; */

static OSPI_v0_HwAttrs ospi_cfg;

static void *boardHandle = NULL;
#endif

#if defined(BOOT_QSPI)
/* TODO (amendola) implement XIP if needed */
/* Offset into app image that is being processed */
//static uint32_t xipMemBase = 0x50000000;

static OSPI_v0_HwAttrs qspi_cfg;

static void *boardHandle = NULL;
#endif

sblEntryPoint_t k3xx_evmEntry;
SBL_incomingBootData_S sblInBootData __attribute__ ((section (".sblbootbuff")));

/*Feature Calibartion data structures */
Features_Cal_Offset_Header_t Feature_Cal_Offset_Data;
USS_Calibration_Data_t  USS_Calib_Data;         //Due to IPC massage Size limit devided USS into 60KB + 10KB
USS_Calibration_data_2_t USS_Calib_Data_2;
THA_Calibration_data_t  THA_Calib_Data;
TRSC_Calibration_data_t TRSC_Calib_Data;
TRSC_Calibration_data_t TRSC_Calib_Data_1;       // temparaty Workaround for TRSC Data, Need to Revisit it
APA_Calibration_data_t  APA_Calib_Data;
APA_Calibration_data_t  APA_Calib_Data_1;
SVS_Calibration_data_t  SVS_Calib_Data;
SVS_Calibration_data_t  SVS_Calib_Data_1;
FOD_Calibration_data_t  FOD_Calib_Data;
LMD_Calibration_data_t  LMD_Calib_Data;

static bool uss_read_error;
static bool tha_read_error;
static bool apa_read_error;
static bool trsc_read_error;
static bool fod_read_error;
static bool lmd_read_error;
static bool svs_read_error;
static bool feature_offset_read_error;

bool APACalib_CRC_flag  = (bool)FALSE;
bool TRSCCalib_CRC_flag = (bool)FALSE;
bool SVSCalib_CRC_flag  = (bool)FALSE;
bool THACalib_CRC_flag  = (bool)FALSE;
bool FODCalib_CRC_flag  = (bool)FALSE;
//volatile uint8_t d_enable_bist = false;
/*Vehicle to USS Variant Mapping*/
/************************************************************************/
/* ---------------------------------
    Vehicle Variant | USS Variant |
   ----------------------------------
|     1,12,13       |      1       |
|      2,6,8        |      2       |
|      3,7,9        |      3       |
|       4,5         |      4       |
|      10,11        |      5       |
|      14,15        |      6       |
______________________________________
*/
static uint8_t Vehicle_To_USS_Variant[15] = {1,2,3,4,4,2,3,2,3,5,5,1,1,6,6};
/***************************************************************************/

/* ========================================================================== */
/*                            External Variables                              */
/* ========================================================================== */

/* SBL functions required for standard boot */
extern uint32_t SBL_IsSysfwEnc(uint8_t *x509_cert_ptr);
extern int32_t  SBL_FileRead(void  *buff, void *fileptr, uint32_t size);
extern void     SBL_FileSeek(void *fileptr, uint32_t location);
extern void     SBL_DCacheClean(void *addr, uint32_t size);
/* Function Pointer used while reading data from the storage. */
extern int32_t   (*fp_readData)(void *dstAddr, void *srcAddr, uint32_t length);
extern void     (*fp_seek)(void *srcAddr, uint32_t location);

/* Get the vehicle variant */
extern void Get_Vehicle_Variant(uint8_t *variant);

/* Functions required for Startup data Handling */
static int32_t Load_StartupData(void);
/* SBL structures required for standard boot */
/* FATFS Handle */
extern FATFS_Handle  sbl_fatfsHandle;
extern FATFS_HwAttrs FATFS_initCfg[_VOLUMES];

/* Functions required for secure boot */
extern int32_t  SBL_loadMMCSDBootFile(FIL * fp);
extern uint32_t SBL_authentication(void *addr);
extern uint32_t SBL_startSK(void);
extern int32_t  SBL_MemRead(void *buff, void *srcAddr, uint32_t size);
extern void     SBL_MemSeek(void *srcAddr, uint32_t location);
extern int32_t  SBL_loadOSPIBootData(void);
extern uint8_t GetIsOSInitialized(void);
/* Structured needed for performing SBL logging */
extern sblProfileInfo_t *sblProfileLogAddr;
extern uint32_t         *sblProfileLogIndxAddr;
extern uint32_t         *sblProfileLogOvrFlwAddr;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#if defined(BOOTAPP_MAINDOMAIN_BOARD_SETUP)
/*        This function uses the Global Timebase Counter (GTC)
 *        Important: the GTC clock is different than the ARM PMU clock.
 *                Function assumes input clock has already been set.
 *                Make sure to check freq. used for SoC!
 *  Note:
 *        For Jacinto 7 SoCs this register requires a SECURE WRITE so it only works
 *        if A53/A72 is in EL3 state.
 */
static void CSL_initGTC(void)
{
    volatile uint32_t *gtcRegister = (uint32_t *) CSL_GTC0_GTC_CFG1_BASE;
    /* Enable GTC */
    *gtcRegister = *gtcRegister | CSL_GTC_CFG1_CNTCR_EN_MASK | CSL_GTC_CFG1_CNTCR_HDBG_MASK;
}
#endif

#if defined(MPU1_HLOS_BOOT_ENABLED) || defined(MPU1_HLOS_BOOT_ONLY_ENABLED)
/* Function to clean the MCU R5 cache for a given start address and given memory size */
void Mcu_DCacheClean(void *addr, uint32_t size)
{
    /* Invalidate by MVA */
    CSL_armR5CacheWbInv((const void *)addr, uint32_to_int32(size), (bool)TRUE);
}
#endif

#if defined(BOOT_OSPI)
static int32_t OSPIBootImageLate(sblEntryPoint_t *pEntry, uint32_t imageOffset)
{
    int32_t retVal = E_FAIL;

#    ifdef SECURE_BOOT
    uint32_t authenticated = 0;
    uint32_t srcAddr = 0;
    uint32_t imgOffset = 0;
#    else
    uint32_t offset = 0;
#    endif

#    ifndef SECURE_BOOT
    /* Load the MAIN domain remotecore images included in the appimage */
    offset = imageOffset;

    fp_readData = &SBL_OSPI_ReadSectors;
    fp_seek     = &SBL_OSPI_seek;

    retVal = SBL_MulticoreImageParse((void *) &offset,
                                      imageOffset,
                                      pEntry,
                                      SBL_SKIP_BOOT_AFTER_COPY);
#    else
    retVal = SBL_loadOSPIBootData();

    if (retVal == E_PASS)
    {
        /* authentiate it */
        authenticated = SBL_authentication(sblInBootData.sbl_boot_buff);
        if (authenticated == 0)
        {
            /* fails authentiation */
            //SBL_log(SBL_LOG_ERR, "\n OSPI Boot - fail authentication\n");

            retVal = E_FAIL;
        }
        else
        {
            /* need to skip the TOC headers */
            imgOffset = ((uint32_t*)sblInBootData.sbl_boot_buff)[0];
            srcAddr = (uint32_t)(sblInBootData.sbl_boot_buff) + imgOffset;
            retVal = SBL_MulticoreImageParse((void *)srcAddr, 0, pEntry,
                                             SBL_SKIP_BOOT_AFTER_COPY);
        }
    }
    else
    {
        retVal = E_FAIL;
        //SBL_log(SBL_LOG_ERR, "\n OSPI Boot - problem processing image \n");
    }
#    endif

    //if (retVal != E_PASS)

       //AppUtils_Printf(MSG_NORMAL, "Error parsing Main Domain appimage\n");

    return retVal;
}

/* Boot all the OSPI images defined in the array */

static int32_t OSPIBootStageImage(sblEntryPoint_t *pEntry, uint32_t address)
{
    int32_t status = E_FAIL;

    if ((0U != address) && (NULL != pEntry))
    {
        if (address != MAIN_DOMAIN_HLOS)
        {
#    if !defined(MPU1_HLOS_BOOT_ONLY_ENABLED)
            /* non-HLOS image */
            status = OSPIBootImageLate(&k3xx_evmEntry, address);
#    else
            status = E_PASS;
#    endif
        }
#    if defined(MPU1_HLOS_BOOT_ENABLED) || defined(MPU1_HLOS_BOOT_ONLY_ENABLED)
        else
        {
            /* Load the HLOS appimages */
            status = OSPIBootImageLate(&k3xx_evmEntry, OSPI_OFFSET_A72IMG1);
            if (status != E_PASS)
            {
               // AppUtils_Printf(MSG_NORMAL,
                                //"Error parsing A72 appimage #1 for HLOS boot\n");
            }
            else
            {
                status = OSPIBootImageLate(&k3xx_evmEntry, OSPI_OFFSET_A72IMG2);
                if (status != E_PASS)
                {
                   // AppUtils_Printf(MSG_NORMAL,
                                  //  "Error parsing A72 appimage #2 for HLOS boot\n");
                }
#        if defined(HLOS_BOOT_LINUX_OS)
                else
                {
                    status = OSPIBootImageLate(&k3xx_evmEntry, OSPI_OFFSET_A72IMG3);
                    if (status != E_PASS)
                       // AppUtils_Printf(MSG_NORMAL,
                                       // "Error parsing A72 appimage #3 for HLOS boot\n");
                }
#        endif
            }

            if (status == E_PASS)
            {
                /* Set the A72 entry point at the ATF address */
                (&k3xx_evmEntry)->CpuEntryPoint[MPU1_CPU0_ID] = ATF_START_RAM_ADDR;
                /* Copied this from MMCSDBootStageImage(). Without it, the A72 won't start due to
                   "Unhandled Exception in EL3" */
                Mcu_DCacheClean((void *)0x70000000, 0x20000);/*PRQA S 0326*/
            }
        } /* if (address == MAIN_DOMAIN_HLOS) */
#    endif /* #if defined(MPU1_HLOS_BOOT_ENABLED)*/
    } /* if ((NULL != address) && (NULL != pEntry)) */

    return status;
}

int32_t OSPILeaveConfigSPI()
{
    int32_t retVal = E_PASS;
    Board_flashHandle h;
    Board_FlashInfo *flashInfo;

#if defined(UART_PRINT_DEBUG)
  //  AppUtils_Printf(MSG_NORMAL,"Entered OSPILeaveConfigSPI function...\n");
#endif

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
    ospi_cfg.baudRateDiv = 32;

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
      //  AppUtils_Printf(MSG_NORMAL,"OSPI flash left configured in Legacy SPI mode.\n");
        flashInfo = (Board_FlashInfo *)h;
      //  AppUtils_Printf(MSG_NORMAL,"\n OSPI NOR device ID: 0x%x, manufacturer ID: 0x%x \n",
    //                flashInfo->device_id, flashInfo->manufacturer_id);
        Board_flashClose(h);
    }
    else
    {
      //  AppUtils_Printf(MSG_NORMAL,"Board_flashOpen failed in SPI mode!!\n");
        retVal = E_FAIL;
    }

    return(retVal);
}
#endif /* defined(BOOT_OSPI) */


#if defined(BOOT_QSPI)
#    if defined(PROFILE_QSPI_READS_ENABLED)
uint64 total_memcpy_time = 0;
uint64 total_memcpy_size = 0;
#    endif


static int32_t QSPIBootImageLate(sblEntryPoint_t *pEntry, uint32_t imageOffset)
{
    int32_t retVal = E_FAIL;

#    ifdef SECURE_BOOT
    uint32_t authenticated = 0;
    uint32_t srcAddr = 0;
    uint32_t imgOffset = 0;
#    else
    uint32_t offset = 0;
#    endif

#    ifndef SECURE_BOOT
    /* Load the MAIN domain remotecore images included in the appimage */
    offset = imageOffset;

    /* Always use the SBL_QSPI implementations: DMA is disabled for NAND, but we always
       want to use the SBL_QSPI_xxx read and seek function pointers. */
    fp_readData = &SBL_QSPI_ReadSectors;
    fp_seek     = &SBL_QSPI_seek;

    retVal = SBL_MulticoreImageParse((void *) &offset,
                                      imageOffset,
                                      pEntry,
                                      SBL_SKIP_BOOT_AFTER_COPY);

#    else
    retVal = SBL_loadQSPIBootData();

    if (retVal == E_PASS)
    {
        /* authentiate it */
        authenticated = SBL_authentication(sblInBootData.sbl_boot_buff);
        if (authenticated == 0)
        {
            /* fails authentiation */
            SBL_log(SBL_LOG_ERR, "\n QSPI Boot - fail authentication\n");

            retVal = E_FAIL;
        }
        else
        {
            /* need to skip the TOC headers */
            imgOffset = ((uint32_t*)sblInBootData.sbl_boot_buff)[0];
            srcAddr = (uint32_t)(sblInBootData.sbl_boot_buff) + imgOffset;
            retVal = SBL_MulticoreImageParse((void *)srcAddr, 0, pEntry,
                                             SBL_SKIP_BOOT_AFTER_COPY);
        }
    }
    else
    {
        retVal = E_FAIL;
        SBL_log(SBL_LOG_ERR, "\n QSPI Boot - problem processing image \n");
    }
#    endif

    if (retVal != E_PASS)
    {
        //  AppUtils_Printf(MSG_NORMAL, "Error parsing Main Domain appimage\n");
    }

    return retVal;
}

/* Boot all the QSPI images defined in the array */

static int32_t QSPIBootStageImage(sblEntryPoint_t *pEntry, uint32_t address)
{
    int32_t status = E_FAIL;

    if ((0U != address) && (NULL != pEntry))
    {
        if (address != MAIN_DOMAIN_HLOS)
        {
#    if !defined(MPU1_HLOS_BOOT_ONLY_ENABLED)
            /* non-HLOS image */
            status = QSPIBootImageLate(&k3xx_evmEntry, address);
#    else
            status = E_PASS;
#    endif
        }
#    if defined(MPU1_HLOS_BOOT_ENABLED) || defined(MPU1_HLOS_BOOT_ONLY_ENABLED)
        else
        {
            /* Load the HLOS appimages */
            status = QSPIBootImageLate(&k3xx_evmEntry, OSPI_OFFSET_A72IMG1);
            if (status != E_PASS)
            {
               /* AppUtils_Printf(MSG_NORMAL,
                                "Error parsing A72 appimage #1 for HLOS boot\n"); */
            }
            else
            {
                status = QSPIBootImageLate(&k3xx_evmEntry, OSPI_OFFSET_A72IMG2);
                if (status != E_PASS)
                {
                   /* AppUtils_Printf(MSG_NORMAL,
                                    "Error parsing A72 appimage #2 for HLOS boot\n"); */
                }
#        if defined(HLOS_BOOT_LINUX_OS)
                else
                {
                    status = QSPIBootImageLate(&k3xx_evmEntry, OSPI_OFFSET_A72IMG3);
                    if (status != E_PASS)
                    /*    AppUtils_Printf(MSG_NORMAL,
                                        "Error parsing A72 appimage #3 for HLOS boot\n"); */
                }
#        endif
            }

            if (status == E_PASS)
            {
                /* Set the A72 entry point at the ATF address */
                (&k3xx_evmEntry)->CpuEntryPoint[MPU1_CPU0_ID] = ATF_START_RAM_ADDR;
                /* Copied this from MMCSDBootStageImage(). Without it, the A72 won't start due to
                   "Unhandled Exception in EL3" */
                Mcu_DCacheClean((void *)0x70000000, 0x20000);
            }
        } /* if (address == MAIN_DOMAIN_HLOS) */
#    endif /* #if defined(MPU1_HLOS_BOOT_ENABLED)*/
    } /* if ((NULL != address) && (NULL != pEntry)) */

    return status;
}
#endif /* defined(BOOT_QSPI) */

#if defined(BOOT_MMCSD)

static int32_t MMCBootImageInit()
{
    int32_t retVal = E_PASS;
    MMCSD_v2_HwAttrs hwAttrsConfig;

    if (MMCSD_socGetInitCfg(FATFS_initCfg[0].drvInst,&hwAttrsConfig) != 0)
    {
        UART_printf("\nUnable to get config.Exiting. TEST FAILED.\r\n");
        retVal = E_FAIL;
    }

    hwAttrsConfig.enableInterrupt = ((uint32_t)(0U));
    hwAttrsConfig.configSocIntrPath=NULL;

    if (MMCSD_socSetInitCfg(FATFS_initCfg[0].drvInst,&hwAttrsConfig) != 0)
    {
        UART_printf("\nUnable to set config.Exiting. TEST FAILED.\r\n");
        retVal = E_FAIL;
    }

    /* Initialization of the driver. */
    FATFS_init();

    /* MMCSD FATFS initialization */
    FATFS_open(0U, NULL, &sbl_fatfsHandle);

    return (retVal);
}

static void MMCBootImageDeInit()
{
    FATFS_close(sbl_fatfsHandle);
    sbl_fatfsHandle = NULL;
}

static int32_t MMCBootImageLate(sblEntryPoint_t *pEntry,
                                TCHAR *fileName)
{
    int32_t  retVal = E_PASS;
    FIL      fp     = {0};
    FRESULT  fresult;

#    ifdef SECURE_BOOT
    uint32_t authenticated = 0;
    uint32_t srcAddr       = 0;
    uint32_t imgOffset     = 0;
#    endif

    fresult = f_open(&fp, fileName, ((BYTE)FA_READ));
    if (fresult != FR_OK)
    {
        //UART_printf("\n SD Boot - File open fails \n");
        retVal = E_FAIL;
    }
    else
    {
#    ifndef SECURE_BOOT
#        if defined(UART_PRINT_DEBUG)
        UART_printf("\n MMCBootImageLate: fp 0x 0x%x, fileName is %s\n",
                    (unsigned int)((void *) &fp),
                    fileName);
#        endif
        fp_readData = &SBL_FileRead;
        fp_seek     = &SBL_FileSeek;

        retVal = SBL_MulticoreImageParse((void *) &fp, 0, pEntry,
                                         SBL_SKIP_BOOT_AFTER_COPY);

#        if defined(UART_PRINT_DEBUG)
        UART_printf("\n Called SBL_MulticoreImageParse, status = %d\n", retVal);
#        endif
#    else
        fp_readData = &SBL_MemRead;
        fp_seek     = &SBL_MemSeek;
        /* handling secure boot image */
        if (E_PASS == SBL_loadMMCSDBootFile(&fp))
        {
            /* successfully loading boot image */
            /* authentiate it */
            authenticated = SBL_authentication(sblInBootData.sbl_boot_buff);
            if (authenticated == 0)
            {
                /* fails authentiation */
                //UART_printf("\n SD Boot - fail authentication\n");

                retVal = E_FAIL;
            }
            else
            {
                /* need to skip the TOC headers */
                imgOffset = ((uint32_t*)sblInBootData.sbl_boot_buff)[0];
                srcAddr = (uint32_t)(sblInBootData.sbl_boot_buff) + imgOffset;
                retVal = SBL_MulticoreImageParse((void *)srcAddr, 0, pEntry,
                                                 SBL_SKIP_BOOT_AFTER_COPY);
            }
        }
        else
        {
            //UART_printf("\n SD sec Boot - incorrect image\n");

            retVal = E_FAIL;
        }
#    endif

        f_close(&fp);
    }

#    ifdef SECURE_BOOT
    /* install RAM Secure Kernel to overwrite DSP secure server*/
    //UART_printf("\n Starting Secure Kernel on DSP...\n");
    SBL_startSK();
#    endif

    return retVal;
}

static int32_t MMCSDBootStageImage(sblEntryPoint_t *pEntry, TCHAR *fileName)
{
    int32_t status      = E_FAIL;
#    if defined(MPU1_HLOS_BOOT_ENABLED) || defined(MPU1_HLOS_BOOT_ONLY_ENABLED)
    TCHAR  *fileNameAtf = "0:/atf_optee.appimage";
#        ifdef HLOS_BOOT_QNX_OS
    TCHAR  *fileHLOS    = "0:/ifs_qnx.appimage";
#        else
    TCHAR  *fileNameDtb = "0:/tidtb_linux.appimage";
    TCHAR  *fileHLOS    = "0:/tikernelimage_linux.appimage";
#        endif
#    endif

    if ((NULL != fileName) && (NULL != pEntry))
    {
        if (strcmp(fileName, MAIN_DOMAIN_HLOS_NAME) != 0)
        {
#    if !defined(MPU1_HLOS_BOOT_ONLY_ENABLED)
            /* non-HLOS image */
            status = MMCBootImageLate(&k3xx_evmEntry, fileName);
#    else
            status = E_PASS;
#    endif
        }
#    if defined(MPU1_HLOS_BOOT_ENABLED) || defined(MPU1_HLOS_BOOT_ONLY_ENABLED)
        else
        {
            /* Read & Parse images for MPU1 HLOS boot from other files */
            status = MMCBootImageLate(&k3xx_evmEntry, fileNameAtf);
            if (status != CSL_PASS)
            {
                //AppUtils_Printf(MSG_NORMAL,
                                "Error copying and parsing A72 appimage #1 for HLOS boot\n");
            }
            else
            {
                status = MMCBootImageLate(&k3xx_evmEntry, fileHLOS);
                if (status != CSL_PASS)
                {
                 //   AppUtils_Printf(MSG_NORMAL,
                                    "Error copying and parsing A72 appimage #2 for HLOS boot\n");
                }
#        if defined(HLOS_BOOT_LINUX_OS)
                else
                {
                    status = MMCBootImageLate(&k3xx_evmEntry, fileNameDtb);
                    if (status != CSL_PASS)
                    {
                     //   AppUtils_Printf(MSG_NORMAL,
                                        "Error copying and parsing A72 appimage #3 for HLOS boot\n");
                    }
                }
#        endif
            }
            if (status == CSL_PASS)
            {
                /* Set the A72 entry point at the ATF address */
                (&k3xx_evmEntry)->CpuEntryPoint[MPU1_CPU0_ID] = ATF_START_RAM_ADDR;
                Mcu_DCacheClean((void *)0x70000000, 0x20000);
            }
        } /* if (address == MAIN_DOMAIN_HLOS) */
#    endif /* #if defined(MPU1_HLOS_BOOT_ENABLED)*/
    } /* if ((NULL != fileName) && (NULL != pEntry)) */

    return status;
}
#endif /* defined(BOOT_MMCSD) */

#if defined(SBL_BOOTLOG_OUTPUT_ENABLED)
static void BOOT_PERF_TEST_printSblProfileLog(sblProfileInfo_t *sblProfileLog,
                                              uint32_t sblProfileLogIndx,
                                              uint32_t sblProfileLogOvrFlw)
{
    uint64_t mcu_clk_freq = SBL_MCU1_CPU0_FREQ_HZ;
    uint32_t i = 0, prev_cycle_cnt = 0, cycles_per_usec;
    uint32_t lastlogIndx;
    char sbl_test_str[256];

    Sciclient_pmGetModuleClkFreq(SBL_DEV_ID_MCU1_CPU0,
                                 SBL_CLK_ID_MCU1_CPU0,
                                 &mcu_clk_freq,
                                 SCICLIENT_SERVICE_WAIT_FOREVER);
    cycles_per_usec = (mcu_clk_freq / 1000000);

   // AppUtils_Printf(MSG_NORMAL,
                    "\r\nProfiling info ....\r\n");
   // sprintf(sbl_test_str,"MCU @ %uHz.\r\n", ((uint32_t)mcu_clk_freq));
   // AppUtils_Printf(MSG_NORMAL,sbl_test_str);
   // sprintf(sbl_test_str,"cycles per usec  = %u\r\n", cycles_per_usec);
//AppUtils_Printf(MSG_NORMAL,sbl_test_str);

    lastlogIndx = sblProfileLogIndx;

    if (sblProfileLogOvrFlw)
    {
        i = sblProfileLogIndx;
        prev_cycle_cnt = sblProfileLog[i].cycle_cnt;
        lastlogIndx = MAX_PROFILE_LOG_ENTRIES;
      //  AppUtils_Printf(MSG_NORMAL,
                        "Detected overflow, some profile entries might be lost.\r\n");
       // AppUtils_Printf(MSG_NORMAL,
                        "Rebuild with a larger vlaue of MAX_PROFILE_LOG_ENTRIES ??\r\n");
    }

    while((i % MAX_PROFILE_LOG_ENTRIES) < lastlogIndx)
    {
        uint32_t cycles_to_us;

        if (sblProfileLog[i].cycle_cnt < prev_cycle_cnt)
        {
           // AppUtils_Printf(MSG_NORMAL,"**");
        }
        else
        {
            //AppUtils_Printf(MSG_NORMAL,"  ");
        }
        cycles_to_us = sblProfileLog[i].cycle_cnt/cycles_per_usec;
        // sprintf(sbl_test_str,"fxn:%32s\t", sblProfileLog[i].fxn);
        // AppUtils_Printf(MSG_NORMAL,sbl_test_str);
        // sprintf(sbl_test_str,"line:%4u\t", sblProfileLog[i].line);
        // AppUtils_Printf(MSG_NORMAL,sbl_test_str);
        // sprintf(sbl_test_str,"cycle:%10u\t", sblProfileLog[i].cycle_cnt);
        // AppUtils_Printf(MSG_NORMAL,sbl_test_str);
        // sprintf(sbl_test_str,"timestamp:%10uus\r\n", cycles_to_us);
        // AppUtils_Printf(MSG_NORMAL,sbl_test_str);
        prev_cycle_cnt = sblProfileLog[i].cycle_cnt;
        i++;
    }
}
#endif


#if (defined(BOOT_OSPI) || defined(BOOT_QSPI))

static void MainDomainBootSetup(void)
{
#    if defined(BOOTAPP_MAINDOMAIN_BOARD_SETUP)
    int32_t retVal;
#        if defined(UART_PRINT_DEBUG)
    // AppUtils_Printf(MSG_NORMAL,
                    "Configuring Sciclient_board for MAIN domain\n");
#        endif

    Sciclient_BoardCfgPrms_t bootAppBoardCfgPrms = {
                                                    .boardConfigLow = (uint32_t)&bootAppBoardCfg,
                                                    .boardConfigHigh = 0,
                                                    .boardConfigSize = sizeof(bootAppBoardCfg),
                                                    .devGrp = DEVGRP_01
                                                   };
    Sciclient_BoardCfgPrms_t bootAppBoardCfgPmPrms = {
                                                      .boardConfigLow = (uint32_t)NULL,
                                                      .boardConfigHigh = 0,
                                                      .boardConfigSize = 0,
                                                      .devGrp = DEVGRP_01
                                                     };
    Sciclient_BoardCfgPrms_t bootAppBoardCfgRmPrms = {
                                                      .boardConfigLow = (uint32_t)&bootAppBoardCfg_rm,
                                                      .boardConfigHigh = 0,
                                                      .boardConfigSize = sizeof(bootAppBoardCfg_rm),
                                                      .devGrp = DEVGRP_01
                                                     };
    Sciclient_BoardCfgPrms_t bootAppBoardCfgSecPrms = {
                                                       .boardConfigLow = (uint32_t)&bootAppBoardCfg_sec,
                                                       .boardConfigHigh = 0,
                                                       .boardConfigSize = sizeof(bootAppBoardCfg_sec),
                                                       .devGrp = DEVGRP_01
                                                      };

    retVal = Sciclient_boardCfg(&bootAppBoardCfgPrms);
    if (retVal != CSL_PASS)
    {
        //  AppUtils_Printf(MSG_NORMAL, "Sciclient_boardCfg() failed.\n");
    }
    retVal = Sciclient_boardCfgPm(&bootAppBoardCfgPmPrms);
    if (retVal != CSL_PASS)
    {
        //  AppUtils_Printf(MSG_NORMAL, "Sciclient_boardCfgPm() failed.\n");
    }
    retVal = Sciclient_boardCfgRm(&bootAppBoardCfgRmPrms);
    if (retVal != CSL_PASS)
    {
        //  AppUtils_Printf(MSG_NORMAL, "Sciclient_boardCfgRm() failed.\n");
    }
    retVal = Sciclient_boardCfgSec(&bootAppBoardCfgSecPrms);
    if (retVal != CSL_PASS)
    {
        //  AppUtils_Printf(MSG_NORMAL, "Sciclient_boardCfgSec() failed.\n");
    }

    Board_init(BOARD_INIT_PLL_MAIN);
    Board_init(BOARD_INIT_MODULE_CLOCK_MAIN);

    SBL_SetQoS();

#    endif /* defined(BOOTAPP_MAINDOMAIN_BOARD_SETUP) */

#    ifdef BOOT_OSPI
#        if (1) //defined(ENABLE_DMA)
    fp_readData = &SBL_OSPI_ReadSectors;
    fp_seek     = &SBL_OSPI_seek;
#        else
    fp_readData = &XIP_ReadMem;
    fp_seek     = &XIP_SeekMem;
#        endif
#    endif // BOOT_OSPI

#    ifdef BOOT_QSPI
    /* Always use the SBL_QSPI implementations: DMA is disabled for NAND, but we always
       want to use the SBL_QSPI_xxx read and seek function pointers. */
#        if (1) // defined(ENABLE_DMA)
    fp_readData = &SBL_QSPI_ReadSectors;
    fp_seek     = &SBL_QSPI_seek;
#        else
    fp_readData = &XIP_ReadMem;
    fp_seek     = &XIP_SeekMem;
#        endif
#    endif // BOOT_QSPI
    return;
}
#endif /* #if defined(BOOT_OSPI) */

static void SBL_ChangeMPUClock(uint32_t idx)
{
    uint32_t i, max;
    struct pll_config
    {
        uint32_t fb_div;
        uint32_t frac_div;
        uint32_t pre_div;
        uint32_t post_div1;
        uint32_t post_div2;
        uint32_t hs_div0;
   } pll_cfg[] =
    {
        {104, 2796203,  1, 1, 1, 0}, /* config for 2GHz      */
        {52,  1398101,  1, 1, 1, 0}, /* config for 1GHz      */
        {114, 9786709,  1, 1, 1, 1}, /* config for 1.1GHz    */
        {125,       0,  1, 1, 1, 1}, /* config for 1.2GHz   */
        {135, 6990507,  1, 1, 1, 1}, /* config for 1.3GHz   */
        {156, 4194304,  1, 1, 1, 1}, /* config for 1.5GHz    */
        {166, 11184811, 1, 1, 1, 1}  /* config for 1.6Ghz  */
    };

    max = sizeof(pll_cfg) / sizeof(struct pll_config);

    if (idx < max)
    {

        SBL_log(SBL_LOG_MAX, "SBL_ChangeMPUClock Changing MPU Clock Frequency to Index/%d\n", idx);

        /* Unlock PLL */
        *(volatile uint32_t *)0x00688010u = 0x68EF3490; /*PLL_CFG_PLL0_LOCKKEY0*/
        *(volatile uint32_t *)0x00688014u = 0xD172BC5A; /*PLL_CFG_PLL0_LOCKKEY1*/

        /* Put PLL in External Bypass */
        *(volatile uint32_t *)0x00688020u |= (0x1u << 31); /*PLL_CFG_PLL0_CTRL*/

        /* Disable PLL */
        *(volatile uint32_t *)0x00688020u &= ~(0x1u << 15); /*PLL_CFG_PLL0_CTRL*/

        /* Integer multiplier does not require DAC and DSM to be enabled */
        if (pll_cfg[idx].frac_div == 0u)
        {
            /* Disable DAC_EN */
            *(volatile uint32_t *)0x00688020u &= ~(1u); /*PLL_CFG_PLL0_CTRL*/

            /* Set DMEN (Enable Delta-Sigma Modulator) */
            *(volatile uint32_t *)0x00688020u &= ~(2u); /*PLL_CFG_PLL0_CTRL*/
        }
        else
        {
            /* Set DACEN (Enable Factional DAC) */
            *(volatile uint32_t *)0x00688020u |= 1u; /*PLL_CFG_PLL0_CTRL*/

            /* Set DMEN (Enable Delta-Sigma Modulator) */
            *(volatile uint32_t *)0x00688020u |= 2u; /*PLL_CFG_PLL0_CTRL*/
        }

        /* Set REF_DIV in DIV_CTRL register */
        *(volatile uint32_t *)0x00688038u &= ~(0x3Fu); /*PLL_CFG_PLL0_DIV_CTRL*/
        *(volatile uint32_t *)0x00688038u |= pll_cfg[idx].pre_div; /*PLL_CFG_PLL0_DIV_CTRL*/

        /* Set FB Divisors */
        *(volatile uint32_t *)0x00688030u = pll_cfg[idx].fb_div; /*PLL_CFG_PLL0_FREQ_CTRL0*/
        *(volatile uint32_t *)0x00688034u = pll_cfg[idx].frac_div; /*PLL_CFG_PLL0_FREQ_CTRL1*/

        /* Disable the 4-phase clock generator */
        *(volatile uint32_t *)0x00688020u &= ~(0x1u << 5); /*PLL_CFG_PLL0_CTRL*/

        /* Set clk_postdiv_en (enables all the post-divider clocks, 4-phase, and synch. clocks) */
        *(volatile uint32_t *)0x00688020u |= (1 << 4); /*PLL_CFG_PLL0_CTRL*/

        /* Set POSTDIV1 */
        *(volatile uint32_t *)0x00688038u &= ~(0x7u << 16u); /*PLL_CFG_PLL0_DIV_CTRL*/
        *(volatile uint32_t *)0x00688038u |= (pll_cfg[idx].post_div1 << 16u); /*PLL_CFG_PLL0_DIV_CTRL*/

        /* Set POSTDIV2 */
        *(volatile uint32_t *)0x00688038u &= ~(0x7u << 24u); /*PLL_CFG_PLL0_DIV_CTRL*/
        *(volatile uint32_t *)0x00688038u |= (pll_cfg[idx].post_div2 << 24u); /*PLL_CFG_PLL0_DIV_CTRL*/

        /* Set Post DIV */
        *(volatile uint32_t *)0x00688080u &= ~(0x7Fu); /*PLL_CFG_PLL0_HSDIV_CTRL0*/
        *(volatile uint32_t *)0x00688080u |= pll_cfg[idx].hs_div0; /*PLL_CFG_PLL0_HSDIV_CTRL0*/

        /* Set WAVE_SEL */
        *(volatile uint32_t *)0x00688040u |= (0x1u); /*PLL_CFG_PLL0_SS_CTRL*/

        //Wait 1us
        i = 0; //Clear i just in case.
        for(i = 0; i < 1000000; i++);

        /* Set the PLL enable bit. */
        *(volatile uint32_t *)0x00688020u |= (0x1 << 15); /*PLL_CFG_PLL0_CTRL*/

        /* Wait untill it is locked */
        do {
            i = *(volatile uint32_t *)0x00688024u; /*PLL_CFG_PLL0_STAT*/
            i = i * 0x1;
        } while (i == 0);


        //De-assert the PLL_EXTBYPASS bit to engage the PLL and HSDIV outputs with the rest of the SoC.
        *(volatile uint32_t *)0x00688020u &= ~(0x1u << 31); /*PLL_CFG_PLL0_CTRL*/

        /* Lock PLL */
        *(volatile uint32_t *)0x00688010u = 0; /*PLL_CFG_PLL0_LOCKKEY0*/
        *(volatile uint32_t *)0x00688014u = 0; /*PLL_CFG_PLL0_LOCKKEY1*/
    }
	else
	{
        //SBL_log(SBL_LOG_ERR, "SBL_ChangeMPUClock unknown Index/%d\n", idx);
        //SblErrLoop(__FILE__, __LINE__);
	}
}

/* Local functions common between OSPI and MMCSD functionality */
static int32_t RequestStageCores(uint8_t stageNum)
{
    uint32_t i;
    int32_t  status = CSL_EFAIL;
    uint8_t  stage  = stageNum;

    for (i = 0; i < MAX_CORES_PER_STAGE; i++)
    {
        if (sbl_late_slave_core_stages_info[stage][i].tisci_proc_id != SBL_INVALID_CORE)
        {
#if defined(UART_PRINT_DEBUG)
            // AppUtils_Printf(MSG_NORMAL,
                            "Calling Sciclient_procBootRequestProcessor, ProcId 0x%x... \n",
                            sbl_late_slave_core_stages_info[stage][i].tisci_proc_id);
#else
            //SBL_log(SBL_LOG_MAX,
                   // "Calling Sciclient_procBootRequestProcessor, ProcId 0x%x... \n",
                   // sbl_late_slave_core_stages_info[stage][i].tisci_proc_id);
#endif
            status = Sciclient_procBootRequestProcessor(sbl_late_slave_core_stages_info[stage][i].tisci_proc_id,
                                                        SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
#if defined(UART_PRINT_DEBUG)
                // AppUtils_Printf(MSG_NORMAL,
                                "Sciclient_procBootRequestProcessor, ProcId 0x%x...FAILED \n",
                                sbl_late_slave_core_stages_info[stage][i].tisci_proc_id);
#else
               // SBL_log(SBL_LOG_MAX,
                      //  "Sciclient_procBootRequestProcessor, ProcId 0x%x...FAILED \n",
                      //  sbl_late_slave_core_stages_info[stage][i].tisci_proc_id);
#endif
                break;
            }
        }
    }

    return (status);
}

static int32_t ReleaseStageCores(uint8_t stageNum)
{
    uint32_t i;
    int32_t  status   = CSL_EFAIL;
    uint8_t  stage  = stageNum;

    for (i = 0; i < MAX_CORES_PER_STAGE; i++)
    {
        if (sbl_late_slave_core_stages_info[stage][i].tisci_proc_id != SBL_INVALID_CORE)
        {
#if defined(UART_PRINT_DEBUG)
            // AppUtils_Printf(MSG_NORMAL,
                            "Sciclient_procBootReleaseProcessor, ProcId 0x%x...\n",
                            sbl_late_slave_core_stages_info[stage][i].tisci_proc_id);
#else
            SBL_log(SBL_LOG_MAX,
                    "Sciclient_procBootReleaseProcessor, ProcId 0x%x...\n",
                    sbl_late_slave_core_stages_info[stage][i].tisci_proc_id);
#endif
            status = Sciclient_procBootReleaseProcessor(sbl_late_slave_core_stages_info[stage][i].tisci_proc_id,
                                                        TISCI_MSG_FLAG_AOP,
                                                        SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
#if defined(UART_PRINT_DEBUG)
                // AppUtils_Printf(MSG_NORMAL,
                                "Sciclient_procBootReleaseProcessor, ProcId 0x%x...FAILED \n",
                                sbl_late_slave_core_stages_info[stage][i].tisci_proc_id);
#else
                SBL_log(SBL_LOG_MAX,
                        "Sciclient_procBootReleaseProcessor, ProcId 0x%x...FAILED \n",
                        sbl_late_slave_core_stages_info[stage][i].tisci_proc_id);
#endif
                break;
            }
        }
    }

    return (status);
}

static void AppSetup(void)
{
#if defined(SOC_J721E)
    Board_STATUS status;

    /* Ethernet config: set proper board muxes for J712E Eth. firmware */
    /* Set IO Expander to use RMII on GESI board */
    status = Board_control(BOARD_CTRL_CMD_SET_RMII_DATA_MUX, NULL);
    if (status != BOARD_SOK)
    {
        // AppUtils_Printf(MSG_NORMAL,"Board_control failed to configure RMII pins\n");
    }
    /* Enable CPSW9G MDIO mux */
    status = Board_control(BOARD_CTRL_CMD_SET_GESI_CPSW_MDIO_MUX, NULL);
    if (status != BOARD_SOK)
    {
        // AppUtils_Printf(MSG_NORMAL,"Board_control failed to configure CPSW9G MDIO mux\n");
    }
#endif
}

/* Main Boot task */
signed long Boot_App()
{
#if defined(BIST_TASK_ENABLED)
    SemaphoreP_Params bistSemParams;
    SemaphoreP_Handle bistSemHandle;
    TaskP_Params      bistParams;
    TaskP_Handle      bistTask;
#endif
    sint32         retVal;
    int32_t         uss_ret;
    cpu_core_id_t  core_id;
    cpu_core_id_t  booted_core_ids[DSP2_C7X_ID];
    uint8          i, j;
    cpu_core_id_t *boot_array;
    uint8          num_cores_to_boot;
    uint8          num_booted_cores = 0;
    int32_t        ospiInitret=(int32_t)E_OK;

#if defined(GATHER_STAGE_DETAILS)
    uint64         time_request_all_cores_start[NUM_BOOT_STAGES];
    uint64         time_request_all_cores_end[NUM_BOOT_STAGES];
    uint64         time_boot_image_late_start[NUM_BOOT_STAGES];
    uint64         time_boot_image_late_end[NUM_BOOT_STAGES];
    uint64         time_boot_stage_finish[NUM_BOOT_STAGES];
#endif
    uint64         time_boot_core_finish[DSP2_C7X_ID];

#if (defined(BOOT_OSPI) || defined(BOOT_QSPI))
#    if defined(PROFILE_OSPI_READS_ENABLED)
    uint64 stage_memcpy_time[NUM_BOOT_STAGES];
    uint64 stage_memcpy_size[NUM_BOOT_STAGES];
#    endif
#endif
    bist_TaskFxn((bool)FALSE);

/*RAT configuration to MAP MSRAM memory:
MSRAM has 64bit address so need to use RAT to map the 32 bit adress
*/
#define RAT_BASE (0x40F90000)
#define REGION_ID (0x0)
    *(uint32_t *)(RAT_BASE + 0x44 + (REGION_ID*0x10)) = 0xD0000000U; //IN ADDRESS
    *(uint32_t *)(RAT_BASE + 0x48 + (REGION_ID*0x10)) = 0x02000000U;
    *(uint32_t *)(RAT_BASE + 0x4C + (REGION_ID*0x10)) = 0x0000004FU; //Upper 16 bits of the real physical address.
    *(uint32_t *)(RAT_BASE + 0x40 + (REGION_ID*0x10)) = 0x80000013U;

#if defined(BOOT_OSPI)

    gNandPhyTuningPoint = (*(NAND_PhyConfig *)0x41c7ffe0U);

    MainDomainBootSetup();

    (void)SBL_SPI_init();
    ospiInitret = SBL_ospiInit(&boardHandle,true);
    if(ospiInitret !=(int32_t)E_OK)
    {
      (void)SBL_ospiInit(&boardHandle, false);
   
      if(Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_MirrorBlock <(uint16)DEF_MAX_PHYTUNE_FAIL_CNT)
      {
         Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_MirrorBlock = Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_MirrorBlock +1u;
      }
      else
      {
        Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_MirrorBlock =(uint16)DEF_MAX_PHYTUNE_FAIL_CNT;
      }
 
      /*set NVM block status for WriteAll*/
      (void)NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_SWC_DIDMgrDID_FD74_PHY_TuningErr,TRUE); 
#if defined(Enable_Printf)
      APP_log(APP_LOG_ERR,"\n MCU1_0:Phytune failed:switched to SDR50MHZ :%d",Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_MirrorBlock);
#endif
    }
    else
    {
#if defined(Enable_Printf)
      APP_log(APP_LOG_ERR,"\n MCU1_0:PHY Tuning Success");
#else
      /* Do nothing */
#endif
    }
#endif

#if defined(BOOT_QSPI)
    MainDomainBootSetup();

    SBL_SPI_init();

    SBL_qspiInit(&boardHandle);

#endif

    /* Configuration of items needed by apps on some cores, before they boot */
    AppSetup();

#if defined(BOOT_MMCSD)

    retVal = MMCBootImageInit();
    if (retVal != CSL_PASS)
    {
        // AppUtils_Printf(MSG_NORMAL,
                       // "Failure during MMCBootImageInit\n\n");
    }
#endif
#if defined(BIST_TASK_ENABLED)
    SemaphoreP_Params_init(&bistSemParams);

    //bistSemParams.instance->name = "bistSem";
    bistSemHandle = SemaphoreP_create(0, &bistSemParams);

    if (NULL != bistSemHandle)
    {
        TaskP_Params_init(&bistParams);
        bistParams.priority   = BIST_TASK_PRIORITY;
        bistParams.stack      = Bist_TaskStack;
        bistParams.stacksize  = sizeof (Bist_TaskStack);
        bistParams.arg0       = (void*)bistSemHandle;

        /* Start the BIST task.  This task is defined in bist.c, and it controls what BIST
         * sections are run for each stage. Before each boot stage is run in boot.c, it waits
         * for the semaphore from the BIST task before proceeding with its booting.
         * Care should be taken to ensure that desired BIST sections are defined in
         * soc/<SOC Device>/bist_core_defs.c, and the BIST definition for each stage matches
         * the desired Main Domain boot cores chosen in soc/<SOC Device>/boot_core_defs.c.
         * It is important to note for each boot stage, the associate BIST sections are first
         * run/checked prior to the boot stage beginning. */
        bistTask              = TaskP_create(bist_TaskFxn, &bistParams);

        if (NULL == bistTask)
        {
#    if defined(UART_ENABLED)
            // AppUtils_Printf(MSG_NORMAL, "\nBIST Task creation failed\r\n");
#    endif
        }
    }
#endif

#if defined(BOOTAPP_MAINDOMAIN_BOARD_SETUP)
    /* Initialize GTC required by Cortex-Axx */
    CSL_initGTC();
#endif


    /* Read_Feature_Calibration_Data */
    Read_Feature_Calibration_Data();


    /* Initialize the entry point array to 0. */
    for (core_id = MPU1_CPU0_ID; core_id < NUM_CORES; core_id ++)
{
        (&k3xx_evmEntry)->CpuEntryPoint[core_id] = SBL_INVALID_ENTRY_ADDR;
}

    for (j = 0; j < (uint32)NUM_BOOT_STAGES; j++)
    {
#if defined(BIST_TASK_ENABLED)
        if ((NULL != bistSemHandle) && (NULL != bistTask))
        {
            (void)SemaphoreP_pend(bistSemHandle, SemaphoreP_WAIT_FOREVER);
        }
#endif
#if defined(GATHER_STAGE_DETAILS)
        time_request_all_cores_start[j] = get_usec_timestamp();
#endif

        retVal = RequestStageCores(j);

#if defined(GATHER_STAGE_DETAILS)
        time_request_all_cores_end[j] = get_usec_timestamp();
#endif

        if (retVal != CSL_PASS)
        {
            // AppUtils_Printf(MSG_NORMAL,
                          //  "Failed to request all late cores in Stage %d\n\n",
                          //  j);
            ReleaseStageCores(j);
        } else
        {
#if defined(UART_PRINT_DEBUG)
            // AppUtils_Printf(MSG_NORMAL,"Loading BootImage\n");
#else
            SBL_log(SBL_LOG_MAX,
                   "Loading BootImage\n");
#endif
#if defined(GATHER_STAGE_DETAILS)
            time_boot_image_late_start[j] = get_usec_timestamp();
#endif

#if defined(BOOT_MMCSD)
            retVal = MMCSDBootStageImage(&k3xx_evmEntry,
                                         mmcsd_main_domain_rtos_image_name[j]);
#    if defined(GATHER_STAGE_DETAILS)
            time_boot_image_late_end[j] = get_usec_timestamp();
#    endif

#endif

#if defined(BOOT_OSPI)
#    if defined(PROFILE_OSPI_READS_ENABLED)
            /* Reset the global variable for memcpy time and size */
            total_memcpy_time = 0;
            total_memcpy_size = 0;
#    endif

            retVal = OSPIBootStageImage(&k3xx_evmEntry,
                                        ospi_main_domain_flash_rtos_images[j]);

#    if defined(PROFILE_OSPI_READS_ENABLED)
            /* Save global variable for memcpy time and size, which has been
             * incremented within OSPIBootStageImage function */
            stage_memcpy_time[j] = total_memcpy_time;
            stage_memcpy_size[j] = total_memcpy_size;
#    endif
#endif
#if defined(BOOT_QSPI)
#    if defined(PROFILE_QSPI_READS_ENABLED)
            /* Reset the global variable for memcpy time and size */
            total_memcpy_time = 0;
            total_memcpy_size = 0;
#    endif

            retVal = QSPIBootStageImage(&k3xx_evmEntry,
                                        ospi_main_domain_flash_rtos_images[j]);

#    if defined(PROFILE_QSPI_READS_ENABLED)
            /* Save global variable for memcpy time and size, which has been
             * incremented within OSPIBootStageImage function */
            stage_memcpy_time[j] = total_memcpy_time;
            stage_memcpy_size[j] = total_memcpy_size;
#    endif
#endif
#if defined(GATHER_STAGE_DETAILS)
            time_boot_image_late_end[j] = get_usec_timestamp();
#endif
#if defined(UART_PRINT_DEBUG)
            // AppUtils_Printf(MSG_NORMAL,
                            "BootImage completed, status = %d\n",
                            retVal);
#else
            //SBL_log(SBL_LOG_MAX,
                    //"BootImage completed, status = %d\n",
                   // retVal);
#endif

            if (retVal != CSL_PASS)
            {
                // AppUtils_Printf(MSG_NORMAL,
                              //  "Failure during image copy and parsing\n\n");
            } else
            {
                retVal = ReleaseStageCores(j);
                if (retVal != CSL_PASS)
                {
                    // AppUtils_Printf(MSG_NORMAL,
                                 //   "Failed to release all late cores\n\n");
                }
            }
        } /* if (retVal != CSL_PASS) */

        if (retVal == CSL_PASS)
        {
            /* Start the individual cores for the boot stage */
            num_cores_to_boot = num_cores_per_boot_stage[j];
            boot_array        = boot_array_stage[j];
            for (i = 0; i < num_cores_to_boot; i++)
            {
                core_id = boot_array[i];
                /* Try booting all cores other than the cluster running the SBL */
                if ((k3xx_evmEntry.CpuEntryPoint[core_id] != SBL_INVALID_ENTRY_ADDR) &&
                    ((core_id != MCU1_CPU1_ID) && (core_id != MCU1_CPU0_ID)))
                {
					if ((core_id == MPU1_CPU0_ID) || (core_id == MPU1_CPU1_ID) ||
                    (core_id == MPU1_CPU2_ID) || (core_id == MPU1_CPU3_ID) ||
                    (core_id == MPU2_CPU0_ID) || (core_id == MPU2_CPU1_ID) ||
                    (core_id == MPU1_SMP_ID) || (core_id == MPU2_SMP_ID))
					{
						SBL_ChangeMPUClock(SBL_MPU_CLOCK_RECONFIG);
					}
                    SBL_SlaveCoreBoot(core_id, 0, &k3xx_evmEntry, SBL_REQUEST_CORE);
#if defined(UART_PRINT_DEBUG)
                    // AppUtils_Printf(MSG_NORMAL,
                                   // "SBL_SlaveCoreBoot completed for Core ID#%d, Entry point is 0x%x\n",
                                  //  core_id, k3xx_evmEntry.CpuEntryPoint[core_id]);
#endif
                    booted_core_ids[num_booted_cores] = core_id;
                   // time_boot_core_finish[num_booted_cores] = get_usec_timestamp();
                    num_booted_cores++;
                }
            }
#if defined(GATHER_STAGE_DETAILS)
            time_boot_stage_finish[j] = get_usec_timestamp();
#endif
        } /* if (retVal == CSL_PASS) */

    } /* for (j = 0; j < NUM_BOOT_STAGES; j++) */

#if defined(BOOT_MMCSD)
    MMCBootImageDeInit();
#endif

#if defined(BOOT_OSPI)
    SBL_ospiClose(&boardHandle);

    OSPILeaveConfigSPI();
#endif
#if defined(BOOT_QSPI)
    SBL_qspiClose(&boardHandle);

    /* TODO (amendola) Implement this if we need it */
    //QSPILeaveConfigSPI();
#endif

    /* Delay print out of boot log to avoid prints by other tasks */
   // TaskP_sleep(4000);

    if (retVal == CSL_PASS)
    {
        /* Print boot log, including all gathered timestamps */
        // AppUtils_Printf(MSG_NORMAL,
                      //  "Boot App: Started at %d usec\n",
                       // (uint32)time_boot_app_start);
#if defined(GATHER_STAGE_DETAILS)
        for (j = 0; j < NUM_BOOT_STAGES; j++)
        {
            // AppUtils_Printf(MSG_NORMAL,
            //                 "Boot App: Stage %d - Started requesting all cores at %d usec\n",
            //                 j, (uint32)time_request_all_cores_start[j]);
            // AppUtils_Printf(MSG_NORMAL,
            //                 "Boot App: Stage %d - Completed requesting all cores at %d usec\n",
            //                 j, (uint32)time_request_all_cores_end[j]);
            // AppUtils_Printf(MSG_NORMAL,
            //                 "Boot App: Stage %d - Started copying and image parsing at %d usec\n",
            //                 j, (uint32)time_boot_image_late_start[j]);
            // AppUtils_Printf(MSG_NORMAL,
            //                 "Boot App: Stage %d - Completed copying and image parsing at %d usec\n",
            //                 j, (uint32)time_boot_image_late_end[j]);
#    if defined(PROFILE_OSPI_READS_ENABLED)
            // AppUtils_Printf(MSG_NORMAL,
            //                 "Boot App: Stage %d - stage_memcpy_time = %ju, stage_memcpy_size = %ju\n",
            //                 j, stage_memcpy_time[j], stage_memcpy_size[j]);
#    endif
            // AppUtils_Printf(MSG_NORMAL,
            //                 "Boot App: Stage %d finished at %d usecs\n",
            //                 j,
            //                 (uint32)time_boot_stage_finish[j]);
        }
#endif
        // AppUtils_Printf(MSG_NORMAL,
                      //  "Boot App: Total Num booted cores = %d\n",
                     //   num_booted_cores);

        // for (core_id = 0; core_id < num_booted_cores; core_id++)
        // {
        //     AppUtils_Printf(MSG_NORMAL,
        //                     "Boot App: Booted Core ID #%d at %d usecs\n",
        //                     booted_core_ids[core_id],
        //                     (uint32)time_boot_core_finish[core_id]);
        // }
    } /* if (retVal == CSL_PASS) */
    else
    {
        // AppUtils_Printf(MSG_NORMAL,
                      //  "Boot App: Failure occurred in boot sequence\n");
    }

#if defined(SBL_BOOTLOG_OUTPUT_ENABLED)
    BOOT_PERF_TEST_printSblProfileLog(sblProfileLogAddr,
                                      *sblProfileLogIndxAddr,
                                      *sblProfileLogOvrFlwAddr);
#endif

    return (retVal);
}

static uint8_t vehicle_variant;

#if defined(FEATURE_CALIBRATION_CRC_ENABLE)
/* ===========================================================================
*
*   Name:          PARAMGR_calcCrc32
*
*   Function:      Algorithm for CRC calculation without lookup table.
*
*   Inputs:        uint8 *data,
                   sint32 len
*
*   Outputs:       uint8 *data,
*
*   Returns:       crc
*
*   Traceability to SDD: {B12D289B-4BF6-448f-926C-41BB761D2985}
*
* ========================================================================= */

static uint32 PARAMGR_calcCrc32(uint8 *data, uint32 len)
{
  uint32 i, j;
  uint32 crc;

  crc = CRC32_INIT;
  if (NULL_PTR != data)
  {
    /* Calculate CRC32 with polynom 0xEDB88320U for the buffer with the given start address and length */
    for (i = 0u; i < len; i++)
    {
        crc = crc ^ data[i];
        for (j = 8u; j > 0u; j--)
        {
            crc = (crc >> 1) ^ (CRC32_POLY & (-(crc & 1U))); /* PRQA S 3101 */
        }
    }
  }

  /* Return the calculated CRC */
  return (~crc);
}
#endif

/* Read USS Calibration data */
static void Read_USS_Calibration_Data(void)
{

    int32_t ret;
    uint8_t uss_variant;
    uint32_t flash_addr;

    uss_variant = Vehicle_To_USS_Variant[vehicle_variant];

    flash_addr = FEATURE_CAL_DATA_FLASH_ADDR + (Feature_Cal_Offset_Data.USS_Start);
    ret = fp_readData(&USS_Calib_Data.CalData[0], &flash_addr,sizeof(USS_Calib_Data.CalData));
    if(ret != 0)
    {
        SBL_log(SBL_LOG_ERR, "\n fp_readData - problem reading the data from flash :USS1\n");
    }

    USS_Calib_Data.uss_caldata_start = 0x5A5A;//String for uss cal data bounday check
    USS_Calib_Data.uss_caldata_end = 0xA5A5;//String for uss cal data bounday check
    USS_Calib_Data.bValid = TRUE;
    flash_addr = FEATURE_CAL_DATA_FLASH_ADDR + (Feature_Cal_Offset_Data.USS_Start) + (sizeof(USS_Calib_Data.CalData));//3*sizeof(uint8) is added to align the Flash address
    ret = fp_readData(&USS_Calib_Data_2.CalData[0], &flash_addr, (sizeof(USS_Calib_Data_2.CalData)));

    USS_Calib_Data_2.uss_caldata_start = 0x5A5A;//String for uss cal data bounday check
    USS_Calib_Data_2.uss_caldata_end = 0xA5A5;//String for uss cal data bounday check
    if(ret != 0)
    {
        SBL_log(SBL_LOG_ERR, "\n fp_readData - problem reading the data from flash :USS2\n");
    }
   /*
    if((USS_Calib_Data.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) ||
       (USS_Calib_Data.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR))
    {
        uss_read_error = FALSE;
    }
    else
    {
        uss_read_error = TRUE;
    }
*/
}

/* Read THA Calibration data */
static void Read_THA_Calibration_Data(void)
{

    int32_t ret, THA_crc;
    uint32_t flash_addr = FEATURE_CAL_DATA_FLASH_ADDR + (Feature_Cal_Offset_Data.THA_Start) + ((uint32)(vehicle_variant-1) * sizeof(THA_Calibration_data_t));
    ret = fp_readData(&THA_Calib_Data, &flash_addr, sizeof(THA_Calibration_data_t));

    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    THA_crc = PARAMGR_calcCrc32((uint8 *)&THA_Calib_Data, (sizeof(THA_Calibration_data_t)-8));
    #endif
    if(ret != 0)
    {
        SBL_log(SBL_LOG_ERR, "\n fp_readData - problem reading the data from flash:THA \n");
    }
    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    if((THA_Calib_Data.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (THA_Calib_Data.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR) && (THA_Calib_Data.checksum == (uint32)THA_crc))
    #else
    if((THA_Calib_Data.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (THA_Calib_Data.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR))
    #endif
    {
        tha_read_error = (bool)FALSE;
        THACalib_CRC_flag = (bool)FALSE;
    }
    else
    {
        tha_read_error = (bool)TRUE;
        THACalib_CRC_flag = (bool)TRUE;
    }

}

static void Read_TRSC_Calibration_Data(void)
{

    int32_t ret, TRSC_crc;
    uint32_t flash_addr = (FEATURE_CAL_DATA_FLASH_ADDR + (Feature_Cal_Offset_Data.TRSC_Start) + ((uint32)(vehicle_variant-1) * sizeof(TRSC_Calibration_data_t)));
    ret = fp_readData(&TRSC_Calib_Data_1, &flash_addr, sizeof(TRSC_Calibration_data_t));


    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    TRSC_crc = PARAMGR_calcCrc32((uint8 *)&TRSC_Calib_Data_1, (sizeof(TRSC_Calibration_data_t)-8));
    #endif
    if(ret != 0)
    {
        SBL_log(SBL_LOG_ERR, "\n fp_readData - problem reading the data from flash:TRSC \n");
    }
    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    if((TRSC_Calib_Data_1.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (TRSC_Calib_Data_1.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR) && (TRSC_Calib_Data_1.checksum == (uint32)TRSC_crc))
    #else
    if((TRSC_Calib_Data_1.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (TRSC_Calib_Data_1.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR))
    #endif
    {
        trsc_read_error = (bool)FALSE;
        TRSCCalib_CRC_flag = (bool)FALSE;
    }
    else
    {
        trsc_read_error = (bool)TRUE;
        TRSCCalib_CRC_flag = (bool)TRUE;
    }

}

/* Read APA Calibration data */
static void Read_APA_Calibration_Data(void)
{

    int32_t ret, APA_crc;
    uint32_t flash_addr = FEATURE_CAL_DATA_FLASH_ADDR + (Feature_Cal_Offset_Data.APA_Start) + ((uint32)(vehicle_variant-1) * sizeof(APA_Calibration_data_t));
    ret = fp_readData(&APA_Calib_Data_1, &flash_addr, sizeof(APA_Calibration_data_t));
    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    APA_crc = PARAMGR_calcCrc32((uint8 *)&APA_Calib_Data_1, (sizeof(APA_Calibration_data_t)-8));
    #endif
    if(ret != 0)
    {
        SBL_log(SBL_LOG_ERR, "\n fp_readData - problem reading the data from flash:APA \n");
    }
    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    if((APA_Calib_Data_1.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (APA_Calib_Data_1.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR) && (APA_Calib_Data_1.checksum == (uint32)APA_crc))
    #else
    if((APA_Calib_Data_1.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (APA_Calib_Data_1.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR))
    #endif
    {
        apa_read_error = (bool)FALSE;
        APACalib_CRC_flag = (bool)FALSE;
    }
    else
    {
        apa_read_error =(bool) TRUE;
        APACalib_CRC_flag = (bool)TRUE;
    }

}

/* Read LMD Calibration data */
static void Read_LMD_Calibration_Data(void)
{
    int32_t ret = 0; 
    uint32_t LMD_crc=0u;
    uint32_t flash_addr = (uint32_t)(FEATURE_CAL_DATA_FLASH_ADDR + (Feature_Cal_Offset_Data.LMD_Start) + ((vehicle_variant-1) * (sizeof(LMD_Calibration_data_t) - sizeof(uint32))));
    ret = fp_readData(&LMD_Calib_Data, &flash_addr, sizeof(LMD_Calibration_data_t));

    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    LMD_crc = PARAMGR_calcCrc32((uint8 *)&LMD_Calib_Data, (sizeof(LMD_Calibration_data_t)-12));
    #endif
    if(ret != 0)
    {
        SBL_log(SBL_LOG_ERR, "\n fp_readData - problem reading the data from flash:LMD \n");
    }

    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    if((LMD_Calib_Data.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (LMD_Calib_Data.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR) && (LMD_Calib_Data.checksum == (uint32)LMD_crc))
    #else
    if((LMD_Calib_Data.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (LMD_Calib_Data.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR))
    #endif
    {
        lmd_read_error = (bool)FALSE;
    }
    else
    {
        lmd_read_error = (bool)TRUE;
    }

}

/* Read FOD Calibration data */
static void Read_FOD_Calibration_Data(void)
{
    int32_t ret = 0;
    uint32_t FOD_crc = 0u;
    uint32_t flash_addr = (uint32_t)(FEATURE_CAL_DATA_FLASH_ADDR + (Feature_Cal_Offset_Data.FOD_Start) + ((vehicle_variant-1) * (sizeof(FOD_Calibration_data_t) - sizeof(uint32))));
    ret = fp_readData(&FOD_Calib_Data, &flash_addr, sizeof(FOD_Calibration_data_t));

    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    FOD_crc = PARAMGR_calcCrc32((uint8 *)&FOD_Calib_Data, (sizeof(FOD_Calibration_data_t)-12));
    #endif
    if(ret != 0)
    {
        SBL_log(SBL_LOG_ERR, "\n fp_readData - problem reading the data from flash:FOD \n");
    }

    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    if((FOD_Calib_Data.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (FOD_Calib_Data.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR) && (FOD_Calib_Data.checksum == (uint32)FOD_crc))
    #else
    if((FOD_Calib_Data.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (FOD_Calib_Data.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR))
    #endif
    {
        fod_read_error = (bool)FALSE;
        FODCalib_CRC_flag = (bool)FALSE;
    }
    else
    {
        fod_read_error = (bool)TRUE;
        FODCalib_CRC_flag = (bool)TRUE;
    }
}
/* Read SVS Calibration data */
static void Read_SVS_Calibration_Data(void)
{

    int32_t ret, SVS_crc;
    uint32_t flash_addr = FEATURE_CAL_DATA_FLASH_ADDR + (Feature_Cal_Offset_Data.SVS_Start) +((uint32)(vehicle_variant-1) * (sizeof(SVS_Calibration_data_t)-sizeof(uint32)));
    ret = fp_readData(&SVS_Calib_Data_1, &flash_addr, sizeof(SVS_Calibration_data_t));

    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    SVS_crc = PARAMGR_calcCrc32((uint8 *)&SVS_Calib_Data_1, (sizeof(SVS_Calibration_data_t)-12));
    #endif
    if(ret != 0)
    {
        SBL_log(SBL_LOG_ERR, "\n fp_readData - problem reading the data from flash:SVS \n");
    }

    #if defined(FEATURE_CALIBRATION_CRC_ENABLE)
    if((SVS_Calib_Data_1.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (SVS_Calib_Data_1.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR) && (SVS_Calib_Data_1.checksum == (uint32)SVS_crc))
    #else
    if((SVS_Calib_Data_1.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) && (SVS_Calib_Data_1.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR))
    #endif
    {
        svs_read_error = (bool)FALSE;
        SVSCalib_CRC_flag = (bool)FALSE;
    }
    else
    {
        svs_read_error = (bool)TRUE;
        SVSCalib_CRC_flag = (bool)TRUE;
    }

}

/* Read_Feature_Calibration_Data */
static void Read_Feature_Calibration_Data (void)
{

    Get_Vehicle_Variant(&vehicle_variant);
    #ifdef Enable_Printf
    appLogPrintf("\n MCU1_0 Autosar  Send calibration data for vehicle Variant %d",vehicle_variant);
    #endif
    Read_Feature_Offset_Data();
    Read_USS_Calibration_Data();
    Read_THA_Calibration_Data();
    Read_APA_Calibration_Data();
    Read_SVS_Calibration_Data();
    Read_TRSC_Calibration_Data();
    Read_FOD_Calibration_Data();
    Read_LMD_Calibration_Data();

}

static void Read_Feature_Offset_Data (void)
{
    int32_t ret;
    uint32_t flash_addr = FEATURE_CAL_OFFSET_HEADER_ADDR;
    ret = fp_readData(&Feature_Cal_Offset_Data, &flash_addr, sizeof(Features_Cal_Offset_Header_t));
    if(ret != 0)
    {
        SBL_log(SBL_LOG_ERR, "\n fp_readData - problem reading the data from flash:offset \n");
    }

    if((Feature_Cal_Offset_Data.magic_str_start == (uint32_t) FEATURE_CALIBRATION_START_STR) ||
       (Feature_Cal_Offset_Data.magic_str_end == (uint32_t) FEATURE_CALIBRATION_END_STR))
    {
        feature_offset_read_error = (bool)FALSE;
    }
    else
    {
        feature_offset_read_error = (bool) TRUE;
    }

}

/* Read USS Calibration data */
void Get_USS_Calibration_Data(USS_Calibration_Data_t* calData, USS_Calibration_data_2_t* calData_2)
{
    //if((NULL != calData_USS) && (uss_read_error == FALSE))
    {
        memcpy(calData, &USS_Calib_Data, sizeof(USS_Calibration_Data_t));
        memcpy(calData_2, &USS_Calib_Data_2, sizeof(USS_Calibration_data_2_t));
    }
    //else
    {
        /*Handle error*/
    }
}

/* Read THA Calibration data */
void Get_THA_Calibration_Data_MCU2_1(THA_Calibration_data_MCU2_1_t* calData)
{
    if(NULL != calData)
    {
        calData->bValid = FALSE;
        if(tha_read_error == FALSE)
        {
             calData->CalData_Version = THA_Calib_Data.CalData_Version;
             memcpy(&(calData->CalData), &(THA_Calib_Data.CalData1), sizeof(TbTHASmVc_VrntTunParam_t));
             calData->bValid = TRUE;
        }
        else
        {
             #ifdef Enable_Printf
             appLogPrintf("\nTHA Calibration Data MCU2_1 CRC Failed");
            #endif
        }

    }
    else
    {
        #ifdef Enable_Printf
        appLogPrintf("\nTHA CalData Buffer of  MCU2_1 is not valid");
        #endif
    }
}

void Get_THA_Calibration_Data_MPU1_0(THA_Calibration_data_MPU1_0_t* calData)
{
    if(NULL != calData)
    {
        calData->bValid = FALSE;
        if(tha_read_error == FALSE)
        {
             calData->CalData_Version = THA_Calib_Data.CalData_Version;
             memcpy(&(calData->CalData), &(THA_Calib_Data.CalData2), sizeof(THADet_Inputs_from_CalData_t));
             calData->bValid = TRUE;
        }
        else
        {
            #ifdef Enable_Printf
            appLogPrintf("\nTHA Calibration Data MPU1_0 CRC Failed");
            #endif
        }
    }
    else
    {
        #ifdef Enable_Printf
        appLogPrintf("\nTHA CalData Buffer of  MPU1_0 is not valid");
        #endif
    }
}

/* Read TRSC Calibration data */
void Get_TRSC_Calibration_Data_MCU2_1(TRSC_Calibration_data_MCU2_1_t* calData)
{
    if(NULL != calData)
    {
        calData->bValid = FALSE;
        if(trsc_read_error == FALSE)
        {
              calData->CalData_Version = TRSC_Calib_Data_1.CalData_Version;
              memcpy(&(calData->CalData), &(TRSC_Calib_Data_1.CalData1), sizeof(TbTRSCSmVc_TunParam_t));
              calData->bValid = TRUE;
        }
        else
        {
            #ifdef Enable_Printf
            appLogPrintf("\nTRSC Calibration Data MCU2_0 CRC Failed");
            #endif
        }
    }
    else
    {
        #ifdef Enable_Printf
        appLogPrintf("\nTRSC CalData Buffer of  MCU2_0  is not valid");
        #endif
    }
}

void Get_TRSC_Calibration_Data_MPU1_0(TRSC_Calibration_data_MPU1_0_t* calData)
{  
    if(NULL != calData)
    {
        calData->bValid = FALSE;
        if(trsc_read_error == FALSE)
        {
            calData->CalData_Version = TRSC_Calib_Data_1.CalData_Version;
            memcpy(&(calData->CalData), &(TRSC_Calib_Data_1.CalData2), sizeof(TRSC_Tunable_Param_t));
            calData->bValid = TRUE;
        }
        else
        {
            #ifdef Enable_Printf
            appLogPrintf("\nTRSC Calibration Data MPU1_0 CRC Failed");
            #endif
        }
    }
    else
    {
        #ifdef Enable_Printf
        appLogPrintf("\nTRSC CalData Buffer of  MPU1_0 is not valid");
        #endif
    }
}

/* Read APA Calibration data */
void Get_APA_Calibration_Data_MPU1_0(APA_Calibration_data_MPU1_0_t* calData)
{
    if(NULL != calData)
    {
        calData->bValid = FALSE;
        if(apa_read_error == FALSE)
        {
            calData->CalData_Version = APA_Calib_Data_1.CalData_Version;
            memcpy(&(calData->CalData), &(APA_Calib_Data_1.CalData3), sizeof(TbAPPLD_AlgoTunParam_t));
            calData->bValid = TRUE;
        }
        else
        {
            #ifdef Enable_Printf
            appLogPrintf("\nAPA Calibration Data  MPU1_0 CRC Failed");
            #endif
        }
    }
    else
     {
        #ifdef Enable_Printf
        appLogPrintf("\nAPA CalData Buffer of  MPU1_0 CRC is not valid");
        #endif
     }
}

void Get_APA_Calibration_Data_MCU2_1(APA_Calibration_data_MCU2_1_t* calData)
{
    
    if(NULL != calData)
    {
		calData->bValid = FALSE;
		if(apa_read_error == FALSE)
		{
			calData->CalData_Version = APA_Calib_Data_1.CalData_Version;
			memcpy(&(calData->CalData1), &(APA_Calib_Data_1.CalData1), sizeof(TbAP_VrntTunParam_t));
			memcpy(&(calData->CalData2), &(APA_Calib_Data_1.CalData2), sizeof(TbAPFPA_AlgoTunParam_t));
			memcpy(&(calData->CalData3), &(APA_Calib_Data_1.CalData4), sizeof(TbAPUSSOM_AlgoTunParam_t));
			memcpy(&(calData->CalData4), &(APA_Calib_Data_1.CalData5), sizeof(TbAPNFCD_VrntTunParam_t));
			calData->bValid = TRUE;
		}
		else
		{
			#ifdef Enable_Printf
			appLogPrintf("\nAPA Calibration Data MCU2_1 CRC Failed");
			#endif
		}

    }
    else
    {
        #ifdef Enable_Printf
        appLogPrintf("\nAPA CalData Buffer of  MCU2_1 is not valid");
        #endif
    }
}

/* Read FOD Calibration data */
void Get_FOD_Calibration_Data(FOD_Calibration_data_t* calData)
{
    
    if(NULL != calData)
    {
        calData->bValid = FALSE;
        if(fod_read_error == FALSE)
        {
            memcpy(calData, &FOD_Calib_Data, (sizeof(FOD_Calibration_data_t)-sizeof(uint32)));
            calData->bValid = TRUE;
        }
        else
        {
                    #ifdef Enable_Printf
                    appLogPrintf("\nFOD Calibration Data CRC Failed");
                    #endif
        }            
        
    }
    else
    {
        #ifdef Enable_Printf
        appLogPrintf("\nFOD CalData Buffer is not valid");
        #endif
    }
}

/* Read LMD Calibration data */
void Get_LMD_Calibration_Data(LMD_Calibration_data_t* calData)
{
    
   if((NULL != calData))
    {
        calData->bValid = FALSE;
        if(lmd_read_error == FALSE)
        {
            memcpy(calData, &LMD_Calib_Data, (sizeof(LMD_Calibration_data_t)-sizeof(uint32)));
            calData->bValid = TRUE;
        }
        else
        {
                    #ifdef Enable_Printf
                    appLogPrintf("\nLMD Calibration Data CRC Failed");
                    #endif
        }
    }
    else
    {
        #ifdef Enable_Printf
        appLogPrintf("\nLMD CalData Buffer is not valid");
        #endif
    }
}

/* Read SVS Calibration data */
void Get_SVS_Calibration_Data(SVS_Calibration_data_t* calData)
{
    
    if(NULL != calData)
    {
        calData->bValid = FALSE;
        if(svs_read_error == FALSE)
        {
                    memcpy(calData, &SVS_Calib_Data_1, (sizeof(SVS_Calibration_data_t)-sizeof(uint32)));
                    calData->bValid = TRUE;
        }
        else
        {
                    #ifdef Enable_Printf
                    appLogPrintf("\nSVS Calibration Data CRC Failed");
                    #endif
        }

    }
    else
    {
        #ifdef Enable_Printf
        appLogPrintf("\nSVS CalData Buffer is not valid");
        #endif
    }
}
