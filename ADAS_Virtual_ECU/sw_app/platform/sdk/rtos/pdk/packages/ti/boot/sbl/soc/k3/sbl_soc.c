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

#include "sbl_soc.h"
#include "sbl_soc_cfg.h"
#include "sbl_log.h"
#include "sbl_profile.h"
#include "sbl_rprc_parse.h"
#include "sbl_sci_client.h"
#include "sbl_err_trap.h"
#include "sbl_qos.h"
#include <strings.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/board/board.h>
#include <ti/board/src/devices/board_devices.h>
#if defined(SOC_J721E)
#include <ti/board/src/j721e_evm/include/board_control.h>
#include <ti/board/src/j721e_evm/include/board_ethernet_config.h>
#endif
#if defined(SOC_J7200)
#include <ti/board/src/j7200_evm/include/board_control.h>
#include <ti/board/src/j7200_evm/include/board_ethernet_config.h>
#endif
#if defined(SOC_J784S4)
#include <ti/board/src/j784s4_evm/include/board_control.h>
#include <ti/board/src/j784s4_evm/include/board_ethernet_config.h>
#endif

#if SBL_USE_DMA
#include "sbl_dma.h"
#endif
#include <string.h>

//#define READBACK_DEBUG 1

sblProfileInfo_t sblProfileLog[MAX_PROFILE_LOG_ENTRIES];
uint32_t sblProfileLogIndx = 0, sblProfileLogOvrFlw = 0;

sblRatCfgInfo_t* sblRatCfgList = NULL;

//#define QOS_WORKAROUND_FOR_GPU
#define GPU_HARDWARE_BASE_ADDRESS_READ  0x45DC5100
#define GPU_HARDWARE_BASE_ADDRESS_WRITE 0x45DC5900
#define REGISTER_VALUE_DISABLE_SNOOP    0x30000000

static inline void _qos_work_around_for_gpu(uint32_t base)
{
    uint32_t offset;
    volatile uint32_t *reg_BASE_ADDR = (uint32_t *)base;
    
	for (offset = 0; offset < 160; offset++)
    {
        *reg_BASE_ADDR = REGISTER_VALUE_DISABLE_SNOOP;
        reg_BASE_ADDR += 1;
    }
		 
}

static void qos_work_around_for_gpu(void)
{
	_qos_work_around_for_gpu(GPU_HARDWARE_BASE_ADDRESS_READ);
	_qos_work_around_for_gpu(GPU_HARDWARE_BASE_ADDRESS_WRITE);
}

void SBL_init_profile(void)
{
    CSL_armR5PmuEnableAllCntrs(1);    /* Set/clear PMCR E-bit */
    CSL_armR5PmuResetCntrs();         /* Set PMCR P-bit */
    CSL_armR5PmuResetCycleCnt();      /* Set PMCR C-bit */
    CSL_armR5PmuEnableCntr(CSL_ARM_R5_PMU_CYCLE_COUNTER_NUM, 1);     /* Set PMCNTENSET for event */
    CSL_armR5PmuClearCntrOverflowStatus(0x80000007);
}

uint32_t SBL_readPmu(void)
{
    return (CSL_armR5PmuReadCntr(0x1F));
}

uint32_t SBL_LogCycleCount(uint8_t *fxn, uint32_t line)
{
    uint32_t indx = sblProfileLogIndx % MAX_PROFILE_LOG_ENTRIES;
    sblProfileInfo_t *sblProfileLogPtr = &(sblProfileLog[indx]);

    if (sblProfileLogIndx == MAX_PROFILE_LOG_ENTRIES)
    {
        sblProfileLogOvrFlw = 1;
    }

    sblProfileLogPtr->fxn = fxn;
    sblProfileLogPtr->line = line;
    sblProfileLogPtr->cycle_cnt = CSL_armR5PmuReadCntr(0x1F);

    sblProfileLogIndx++;

    return sblProfileLogPtr->cycle_cnt;
}

void SBL_printProfileLog(void)
{
#ifdef SBL_DISPLAY_PROFILE_INFO
    uint64_t mcu_clk_freq;
    uint32_t i = 0, prev_cycle_cnt = 0, cycles_per_usec;
    uint32_t lastlogIndx;

    SBL_ADD_PROFILE_POINT;

    Sciclient_pmGetModuleClkFreq(SBL_DEV_ID_MCU1_CPU0, SBL_CLK_ID_MCU1_CPU0, &mcu_clk_freq, SCICLIENT_SERVICE_WAIT_FOREVER);
    cycles_per_usec = (mcu_clk_freq / 1000000);

    SBL_log(SBL_LOG_ERR, "MCU @ %dHz.\n", uint64_to_int32(mcu_clk_freq));
    SBL_log(SBL_LOG_ERR, "cycles per usec  = %d\n", cycles_per_usec);

    lastlogIndx = sblProfileLogIndx;

    if (sblProfileLogOvrFlw)
    {
        i = sblProfileLogIndx;
        prev_cycle_cnt = sblProfileLog[i].cycle_cnt;
        lastlogIndx = MAX_PROFILE_LOG_ENTRIES;
        SBL_log(SBL_LOG_ERR, "Detected overflow, some profile entries might be lost.\n");
        SBL_log(SBL_LOG_ERR, "Rebuild with a larger vlaue of MAX_PROFILE_LOG_ENTRIES ??\n");
    }

    while((i % MAX_PROFILE_LOG_ENTRIES) < lastlogIndx)
    {
        uint32_t cycles_to_us;

        if (sblProfileLog[i].cycle_cnt < prev_cycle_cnt)
        {
            SBL_log(SBL_LOG_MAX,"**");
        }
        else
        {
            SBL_log(SBL_LOG_MAX,"  ");
        }
        cycles_to_us = sblProfileLog[i].cycle_cnt/cycles_per_usec;
        SBL_log(SBL_LOG_ERR,"fxn:%32s\t", sblProfileLog[i].fxn);
        SBL_log(SBL_LOG_ERR,"line:%4d\t", sblProfileLog[i].line);
        SBL_log(SBL_LOG_ERR,"cycle:%10d\t", sblProfileLog[i].cycle_cnt);
        SBL_log(SBL_LOG_ERR,"timestamp:%10dus\n", cycles_to_us);
        prev_cycle_cnt = sblProfileLog[i].cycle_cnt;
        i++;
    }
#else
    if (sblProfileLogOvrFlw)
    {
    }
#endif
}

void SBL_DCacheClean(void *addr, uint32_t size)
{
    uint32_t set = 0, way = 0;
    uint32_t cacheLineSize = CSL_armR5CacheGetDcacheLineSize();
    uintptr_t firstAddr = (uintptr_t ) addr & ~(cacheLineSize -1U);
    uintptr_t lastAddr = (uintptr_t) addr + size;
    uintptr_t num_iterations = (lastAddr - firstAddr) / cacheLineSize;

    if (num_iterations < 64 * 4)
    {
        /* Invalidate by MVA */
        CSL_armR5CacheWbInv((const void *)addr, uint32_to_int32(size), (bool)TRUE);
    }
    else
    {
        /* Invalidating full cache by set and way is more efficient */
    for (set = 0; set < 128; set ++)
        {
            for (way = 0; way < 4; way++)
            {
                CSL_armR5CacheCleanInvalidateDcacheSetWay(set, way);
            }
        }
    }

}

uint32_t SBL_GetCertLen(uint8_t *x509_cert_ptr)
{
    uint32_t cert_len = 0;
    uint8_t *cert_len_ptr = (uint8_t *)&cert_len;

    SBL_ADD_PROFILE_POINT;

    SBL_log(SBL_LOG_MAX,"Searching for X509 certificate ...");
    if ( *x509_cert_ptr != 0x30)
    {
        SBL_log(SBL_LOG_MAX,"not found\r\n");
        SBL_ADD_PROFILE_POINT;
        return 0;
    }

    cert_len = *(x509_cert_ptr + 1);

    /* If you need more than 2 bytes to store the cert length  */
    /* it means that the cert length is greater than 64 Kbytes */
    /* and we do not support it                                */
    if ((cert_len > 0x80) &&
        (cert_len != 0x82))
    {
        SBL_log(SBL_LOG_MAX,"size invalid\r\n");
        SBL_ADD_PROFILE_POINT;
        return 0;
    }

    SBL_log(SBL_LOG_MAX,"found @0x%x, ", x509_cert_ptr);

    if ( cert_len == 0x82)
    {
        *cert_len_ptr = *(x509_cert_ptr + 3);
        *(cert_len_ptr + 1) = *(x509_cert_ptr + 2);

        /* add current offset from start of x509 cert */
        cert_len += 3;
    }
    else
    {
        /* add current offset from start of x509 cert  */
        /* if cert len was obtained from 2nd byte i.e. */
        /* cert size is 127 bytes or less              */
        cert_len += 1;
    }

    /* cert_len now contains the offset of the last byte */
    /* of the cert from the ccert_start. To get the size */
    /* of certificate, add 1                             */
    SBL_log(SBL_LOG_MAX,"size = %d bytes\r\n", cert_len + 1);

    SBL_ADD_PROFILE_POINT;
    return cert_len + 1;
}

uint8_t *SBL_FindSeq(uint8_t *x509_cert_ptr, uint32_t x509_cert_size, uint8_t *seq_oid, uint8_t seq_len)
{
    uint8_t *x509_cert_end = x509_cert_ptr + x509_cert_size - seq_len;

    SBL_ADD_PROFILE_POINT;

    /* searching for the following byte seq in the cert */
    /* seq_id(0x30) seq_len(< 0x80) 0x06 0x09 0x2B...   */
    while (x509_cert_ptr < x509_cert_end)
    {
        if ((*x509_cert_ptr == seq_oid[0]) &&
            (*(x509_cert_ptr + 2) == seq_oid[2]) &&
            (*(x509_cert_ptr - 2) == 0x30))
        {
            if ((bcmp((const void *)x509_cert_ptr, (const void *)seq_oid, seq_len)) == 0)
            {
                SBL_ADD_PROFILE_POINT;
                /* return start boot_seq */
                return (x509_cert_ptr - 2);
            }
        }
        x509_cert_ptr++;
    }

    SBL_ADD_PROFILE_POINT;

    return NULL;
}

uint32_t SBL_GetMsgLen(uint8_t *x509_cert_ptr, uint32_t x509_cert_size)
{
    uint8_t *boot_seq_ptr;
    uint32_t msg_len = 0, boot_seq_len;
    uint8_t *msg_len_ptr = (uint8_t *)&msg_len;
    /* oid encoding of boot_seq extension - 1.3.6.1.4.1.294.1.1 */
    uint8_t boot_seq_oid[] = {0x06, 0x09, 0x2B, 0x06, 0x01, 0x04, 0x01, 0x82, 0x26, 0x01, 0x01};

    SBL_ADD_PROFILE_POINT;

    boot_seq_ptr = SBL_FindSeq(x509_cert_ptr, x509_cert_size, boot_seq_oid, sizeof(boot_seq_oid));
    SBL_log(SBL_LOG_MAX,"Found seq @ 0x%x\r\n", boot_seq_ptr);

    /* length of seq is stored in the byte after the 0x30 seq_id */
    /* length of seq is stored as offset of the last byte of seq */
    /* from current offset. Jump to the end of the boot seq as   */
    /* the length of the message  is the last field of this seq  */
    boot_seq_len = *(++boot_seq_ptr);
    boot_seq_ptr = boot_seq_ptr + boot_seq_len;

    /* The last integer in this sequence is the msg length    */
    /* integers are tagged 0x20, so search backwards for 0x20 */
    /* The msg size can be encoded in 1, 2, 3 or 4 bytes      */
    /* 0x02 0x01 0x##                                         */
    /* 0x02 0x02 0x## 0x##                                    */
    /* 0x02 0x03 0x## 0x## 0x##                               */
    /* 0x02 0x04 0x## 0x## 0x## 0x##                          */
    if ( (*(boot_seq_ptr - 5) == 0x02) &&
         (*(boot_seq_ptr - 4) == 0x04) )
    {
        /* msg length encoded in 4 bytes */
        *msg_len_ptr = *boot_seq_ptr;
        *(msg_len_ptr + 1) = *(boot_seq_ptr - 1);
        *(msg_len_ptr + 2) = *(boot_seq_ptr - 2);
        *(msg_len_ptr + 3) = *(boot_seq_ptr - 3);
    }
    else if ( (*(boot_seq_ptr - 4) == 0x02) &&
         (*(boot_seq_ptr - 3) == 0x03) )
    {
        /* msg length encoded in 3 bytes */
        *msg_len_ptr = *boot_seq_ptr;
        *(msg_len_ptr + 1) = *(boot_seq_ptr - 1);
        *(msg_len_ptr + 2) = *(boot_seq_ptr - 2);
    }
    else if ( (*(boot_seq_ptr - 3) == 0x02) &&
         (*(boot_seq_ptr - 2) == 0x02) )
    {
        /* msg length encoded in 2 bytes */
        *msg_len_ptr = *boot_seq_ptr;
        *(msg_len_ptr + 1) = *(boot_seq_ptr - 1);
    }
    else if ( (*(boot_seq_ptr - 2) == 0x02) &&
         (*(boot_seq_ptr - 1) == 0x01) )
    {
        /* msg length encoded in 1 byte */
        *msg_len_ptr = *boot_seq_ptr;
    }

    SBL_log(SBL_LOG_MAX,"image length = %d bytes\r\n", msg_len);

    SBL_ADD_PROFILE_POINT;

    return msg_len;
}

/* Keep all boot media read offsets and read sizes */
/* word aligned throughout the function in case    */
/* boot media cannot handle byte accesses          */
int32_t SBL_VerifyMulticoreImage(void **img_handle,
                                 uint32_t *ImageOffsetPtr,
                                 uint8_t *scratch_mem,
                                 uint32_t scratch_sz)
{
    uint8_t *scratch_mem_ptr;
    uint32_t cert_len = 0, img_len, cert_load_addr;
    int32_t retVal = E_FAIL, auth_retval = E_FAIL;
    uint32_t SBL_GetCertLen(uint8_t *x509_cert_ptr);
    uint32_t SBL_GetMsgLen(uint8_t *x509_cert_ptr, uint32_t x509_cert_size);
    struct tisci_msg_sys_reset_req request;
    struct tisci_msg_sys_reset_resp response = {0};

    Sciclient_ReqPrm_t reqParam;
    Sciclient_RespPrm_t respParam;

    SBL_ADD_PROFILE_POINT;

    if ((fp_readData != NULL) && (fp_seek != NULL))
    {
        uint8_t x509Header[4];
        /* Read first 4 bytes of image to */
        /* determine if it is a x509 img  */
        fp_readData(x509Header, *img_handle, 4);
        fp_seek(*img_handle, *ImageOffsetPtr);
        cert_len = SBL_GetCertLen(x509Header);
    }

    /* Check if cert size is within valid range */
    if ((cert_len > 0x100) &&
        (cert_len < 0x800) &&
        (scratch_mem !=NULL) &&
        (scratch_sz != 0))
    {
        uint8_t unaligned_bytes = cert_len % 4;
        uint8_t pad_align = 4 - unaligned_bytes;

        SBL_log(SBL_LOG_MAX,"SBL reserved memory Found: Start = @ 0x%x, Size = 0x%x\r\n", scratch_mem, scratch_sz);
        /* adjust cert load addr so that the */
        /* msg is always word aligned        */
        scratch_mem_ptr = scratch_mem + pad_align;
        SBL_log(SBL_LOG_MAX,"Copying %d bytes from app to 0x%x\r\n", cert_len + pad_align, scratch_mem_ptr);
        fp_readData(scratch_mem_ptr, *img_handle, cert_len + pad_align);
        fp_seek(*img_handle, *ImageOffsetPtr);
        cert_load_addr = (uint32_t)scratch_mem_ptr;

        img_len = SBL_GetMsgLen(scratch_mem_ptr, cert_len);
        if ((scratch_mem_ptr + cert_len + img_len)  <
            (scratch_mem + scratch_sz))
        {
            struct tisci_msg_proc_auth_boot_req authReq;

            fp_seek(*img_handle, (*ImageOffsetPtr + cert_len - unaligned_bytes));
            scratch_mem_ptr += (cert_len - unaligned_bytes);

            img_len += unaligned_bytes;
            unaligned_bytes = img_len % 4;
            pad_align = 4 - unaligned_bytes;
            img_len += pad_align;

            SBL_log(SBL_LOG_MAX,"Copying %d bytes from offset 0x%x to 0x%x...", img_len, *ImageOffsetPtr + cert_len - unaligned_bytes, scratch_mem_ptr);
            fp_readData(scratch_mem_ptr, *img_handle, img_len);
            fp_seek(*img_handle, *ImageOffsetPtr);

            /* Request DMSC to authenticate the image */
            authReq.certificate_address_hi = 0;
            authReq.certificate_address_lo = cert_load_addr;
            SBL_log(SBL_LOG_MAX,"Cert @ 0x%x ...", authReq.certificate_address_lo);

            SBL_ADD_PROFILE_POINT;

            retVal = auth_retval = Sciclient_procBootAuthAndStart(&authReq, SCICLIENT_SERVICE_WAIT_FOREVER);
            if (retVal == CSL_PASS)
            {
                SBL_log(SBL_LOG_MAX,"Verify Passed...");
            }
            else
            {
                if (SBL_IsAuthReq() == SBL_NEVER_AUTH_APP)
                {
                    SBL_log(SBL_LOG_MAX,"Ignored on GP...");
                }
                else
                {
                    SBL_log(SBL_LOG_ERR,"Verify Failed!!\n\r");
                    SBL_log(SBL_LOG_ERR,"Boot Halted!!\n\r");
                    //SblErrLoop(__FILE__, __LINE__);
                
                    memset(&request,0, sizeof(request));
                    request.domain = 0x0; /* Whole System reset */
                
                    reqParam.messageType    = (uint16_t) TISCI_MSG_SYS_RESET;
                    reqParam.flags          = (uint32_t) TISCI_MSG_FLAG_AOP;
                    reqParam.pReqPayload    = (const uint8_t *) &request;
                    reqParam.reqPayloadSize = (uint32_t) sizeof (request);
                    reqParam.timeout        = (uint32_t) SCICLIENT_SERVICE_NO_WAIT;
                    respParam.flags           = (uint32_t) 0;   /* Populated by the API */
                    respParam.pRespPayload    = (uint8_t *) &response;
                    respParam.respPayloadSize = (uint32_t) sizeof (response);
                
                    Sciclient_service(&reqParam, &respParam);
                    //Sciclient_pmDeviceReset(SCICLIENT_SERVICE_NO_WAIT);
                }
            }

            SBL_ADD_PROFILE_POINT;

            /* Image is loaded. RPRC parsing no longer */
            /* neeeds to access the boot media. Update */
            /* caller with image load address          */
            #if defined(SOC_J721E) && SBL_USE_DMA
            if(SBL_isUdmaInitDone())
            {
                SBL_udmaSeekMem(NULL, 0);
                SBL_SetMulticoreImageImgReadfxn((void *)SBL_udmaReadData, (void *)SBL_udmaSeekMem);
            }
            else
            {
                SBL_SeekMem(NULL, 0);
                SBL_SetMulticoreImageImgReadfxn((void *)SBL_ReadMem, (void *)SBL_SeekMem);
            }
            #else
            SBL_SeekMem(NULL, 0);
            SBL_SetMulticoreImageImgReadfxn((void *)SBL_ReadMem, (void *)SBL_SeekMem);
            #endif
            *img_handle = (void *)(cert_load_addr+cert_len);
            *ImageOffsetPtr = 0;
            SBL_log(SBL_LOG_MAX,"done\r\n", img_len, scratch_mem_ptr);
            retVal = E_PASS;
        }
    }

    if ((auth_retval != CSL_PASS) &&
        (SBL_IsAuthReq() != SBL_NEVER_AUTH_APP))
    {
        SBL_log(SBL_LOG_ERR,"Is app signed correctly??\n\r");
        SBL_log(SBL_LOG_ERR,"App verification fails!! Boot Halted!!\n\r");
        SblErrLoop(__FILE__, __LINE__);
    }
    SBL_ADD_PROFILE_POINT;

    return retVal;
}

void SBL_RAT_Config(sblRatCfgInfo_t* remap_list)
{
    if (remap_list)
    {
    }
    else
    {
        return;
    }
}

void SBL_ConfigureCommonRails(sblCfgPmic_t *pmicVoltCfg, uint8_t powerResource)
{
    uint32_t pmicVoltCfgSz = SBL_MAX_VTM_VDS;
    uint16_t commonRailMaxVoltage = 0;
    sblCfgPmic_t *commonRailPmicCfgPtr = NULL;
    sblCfgPmic_t commonRailPmicCfg;

    /* Save the fist instance of a ganged rail */
    commonRailPmicCfgPtr = pmicVoltCfg;
    commonRailPmicCfg = *commonRailPmicCfgPtr;

    /* A ganged rail is a single source that is used  */
    /* to power multiple voltage domains that can run */
    /* at the same voltage, even though each domain   */
    /* is capable of ACS class0                       */
    while (pmicVoltCfgSz--)
    {
        if(pmicVoltCfg->powerResource == powerResource)
        {
            if(pmicVoltCfg->millivolts > commonRailMaxVoltage)
            {
                /* Ganged rails must be set to the max value */
                commonRailMaxVoltage = pmicVoltCfg->millivolts;
            }

            /* Zero out any ganged rails here    */
            /* the first ganged rail is stored   */
            /* in commonRailPmicCfg and will     */
            /* be used setup the correct voltage */
            /* for all the ganged rails          */
            pmicVoltCfg->millivolts = 0;
            pmicVoltCfg->slaveAddr = 0;
            pmicVoltCfg->powerResource = 0;

        }
        pmicVoltCfg++;
    }

    commonRailPmicCfg.millivolts = commonRailMaxVoltage;
    *commonRailPmicCfgPtr = commonRailPmicCfg;
    SBL_log(SBL_LOG_MAX, "Common rail: Slave:0x%x, Res:0x%x @ %dmV\r\n", commonRailPmicCfg.slaveAddr, commonRailPmicCfg.powerResource, commonRailPmicCfg.millivolts);
}

void SBL_SetupPmicCfg(sblCfgPmic_t *pmicVoltCfg, uint32_t opp)
{
    uint32_t vd, vtmDevInfo, vtmOppVid;
    uint32_t vtmOppVidMask = (SBL_VTM_OPP_VID_MASK << opp);
    sblCfgPmic_t *pmicCfg;

    SBL_ADD_PROFILE_POINT;

    for (vd = 0; vd < SBL_MAX_VTM_VDS; vd++)
    {
        vtmDevInfo = CSL_REG32_RD(SBL_VTM_CFG_BASE + CSL_VTM_CFG1_VD_DEVINFO(vd));
        vtmOppVid = CSL_REG32_RD(SBL_VTM_CFG_BASE + CSL_VTM_CFG1_VD_OPPVID(vd));
        pmicCfg = pmicVoltCfg + vd;
        if (vtmDevInfo & CSL_VTM_CFG1_DEVINFO_AVS0_SUP_MASK)
        {
            vtmOppVid = (vtmOppVid & vtmOppVidMask) >> opp;
            pmicCfg->millivolts = sblMapOtpVidToMilliVolts[vtmOppVid];
            SBL_log(SBL_LOG_MAX, "Efuse xlated: VD %d to %d mV (OppVid: 0x%x, Slave:0x%x, Res:0x%x)\r\n", vd, pmicCfg->millivolts, vtmOppVid, pmicCfg->slaveAddr, pmicCfg->powerResource);
        }
    }

    SBL_ADD_PROFILE_POINT;
}

#if defined(SOC_J721E) || defined(SOC_J7200) || defined(SOC_J784S4)
void SBL_ConfigureEthernet(void)
{
#if !defined(SBL_USE_MCU_DOMAIN_ONLY) && !defined(SBL_ENABLE_DEV_GRP_MCU)
    Board_STATUS status = BOARD_SOK;
#if defined(SOC_J721E)
    bool gesiDetected = false;
#endif
    bool qenetDetected = false;

#if defined(SOC_J721E)
    /* Ethernet config: set proper board muxes for Eth. firmware */
    /* Set IO Expander to use RMII on GESI board */
    gesiDetected = Board_detectBoard(BOARD_ID_GESI);
    if (gesiDetected)
    {
        status = Board_control(BOARD_CTRL_CMD_SET_RMII_DATA_MUX, NULL);
        if (status != BOARD_SOK)
        {
            SBL_log(SBL_LOG_MAX,"Board_control failed to configure RMII pins\r\n");
        }
    }

    /* Enable CPSW9G MDIO mux */
    if (gesiDetected)
    {
        status = Board_control(BOARD_CTRL_CMD_SET_GESI_CPSW_MDIO_MUX, NULL);
        if (status != BOARD_SOK)
        {
            SBL_log(SBL_LOG_MAX,"Board_control failed to configure CPSW9G MDIO mux\r\n");
        }
    }
#endif

#if defined(SOC_J784S4)
    /* Set MUX2 A <-> B2, needed for MDIO clock */
    status = Board_control(BOARD_CTRL_CMD_SET_IO_MUX_PORTB2, NULL);
    if (status != BOARD_SOK)
    {
        SBL_log(SBL_LOG_MAX,"Board_control failed to configure MUX2 A <-> B2\r\n");
    }
#endif

    qenetDetected = Board_detectBoard(BOARD_ID_ENET);
    if (qenetDetected)
    {
        /* Release PHY reset */
        status = Board_cpswEnetExpPhyReset(0U);
        if (status != BOARD_SOK)
        {
            SBL_log(SBL_LOG_MAX,"Board_cpswEnetExpPhyReset failed to reset the ENET PHY\r\n");
        }
        /* Release the COMA_MODE pin */
        status = Board_cpswEnetExpComaModeCfg(0U);
        if (status != BOARD_SOK)
        {
            SBL_log(SBL_LOG_MAX,"Board_cpswEnetExpComaModeCfg failed to release COMA_MODE pin\r\n");
        }
    }
#endif
}
#endif

/**********************************************************************
 ******************* SoC Specific Initilization ***********************
 **********************************************************************/
/* Workarounds for J721E SoC */
#if defined(SOC_J721E)
#include <ti/board/src/j721e_evm/include/board_internal.h>

static sblCfgPmic_t pmicAvsVoltCfg[] =
{
    {0, 0, 0},
    {0, 0, 0},
    {BOARD_I2C_LEO_PMIC_A_ADDR, BOARD_TPS65941_BUCK1_RESOURCE, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

void J721E_SetLeoPmicVoltages(void *handle, sblCfgPmic_t *pmicVoltCfg)
{
    int32_t retStatus = 0;
    uint32_t pmicVoltCfgSz = SBL_MAX_VTM_VDS;

    while (pmicVoltCfgSz--)
    {
        if(pmicVoltCfg->millivolts)
        {
            SBL_ADD_PROFILE_POINT;
            retStatus = Board_tps65941SetVoltage(handle, pmicVoltCfg->slaveAddr, pmicVoltCfg->powerResource, pmicVoltCfg->millivolts);
            if(retStatus != BOARD_SOK)
            {
                SBL_ADD_PROFILE_POINT;
                SBL_log(SBL_LOG_MAX,"Failed to set voltage to %d mV for Slave:0x%x, Res:0x%x\r\n", pmicVoltCfg->millivolts, pmicVoltCfg->slaveAddr, pmicVoltCfg->powerResource);
            }
            else
            {
                SBL_ADD_PROFILE_POINT;
                SBL_log(SBL_LOG_MAX,"Successfully set voltage to %d mV for Slave:0x%x, Res:0x%x\r\n", pmicVoltCfg->millivolts, pmicVoltCfg->slaveAddr, pmicVoltCfg->powerResource)
            }
        }
        pmicVoltCfg++;
    }
}

static void J721E_SetupLeoPmicAvs(uint32_t opp)
{
    I2C_Handle handle = NULL;

    SBL_ADD_PROFILE_POINT;

    handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP, BOARD_I2C_PMIC_INSTANCE);
    if(handle == NULL)
    {
        SBL_log(SBL_LOG_MAX,"I2C Open Failed\n\r");
        SblErrLoop(__FILE__, __LINE__);
    }
    SBL_SetupPmicCfg(pmicAvsVoltCfg, opp);
    J721E_SetLeoPmicVoltages(handle, pmicAvsVoltCfg);

    SBL_ADD_PROFILE_POINT;
}


#define J72XX_MAX_TEMP_VAL  (125000)
#define J72XX_SAFE_TEMP_VAL (105000)
static void J721E_EnableThermalMaxTempAlert(void)
{
    uint8_t id, numSens = 5;
    int32_t retStatus = 0;
    CSL_vtm_ts_ctrl_cfg ts_ctrl_cfg;
    CSL_vtm_cfg2Regs    *p_vtm_cfg2_regs;

    p_vtm_cfg2_regs = (CSL_vtm_cfg2Regs *) CSL_WKUP_VTM0_MMR_VBUSP_CFG2_BASE;

    /* Cycle through all Temp sensors configs and program the Thermal shutdown values for each */
    for (id = 0; id < numSens; id++)
    {
        ts_ctrl_cfg.valid_map = CSL_VTM_TS_CTRL_MAXT_OUTG_ALERT_VALID   |
                                CSL_VTM_TS_CTRL_RESET_CTRL_VALID        |
                                CSL_VTM_TS_CTRL_SOC_VALID               |
                                CSL_VTM_TS_CTRL_MODE_VALID;

        retStatus = CSL_vtmTsGetCtrl(p_vtm_cfg2_regs, id, &ts_ctrl_cfg);
        if(retStatus != CSL_PASS)
            SBL_log(SBL_LOG_ERR,"Failed to get Global Cfg values for Sensor ID %d \r\n", id);

        ts_ctrl_cfg.valid_map = CSL_VTM_TS_CTRL_RESET_CTRL_VALID        |
                                CSL_VTM_TS_CTRL_SOC_VALID               |
                                CSL_VTM_TS_CTRL_MODE_VALID;

        ts_ctrl_cfg.adc_stat   = CSL_VTM_TS_CTRL_SINGLESHOT_ADC_CONV_IN_PROGRESS;
        ts_ctrl_cfg.mode       = CSL_VTM_TS_CTRL_CONTINUOUS_MODE;
        ts_ctrl_cfg.tsReset    = CSL_VTM_TS_CTRL_SENSOR_NORM_OP;

        retStatus = CSL_vtmTsSetCtrl(p_vtm_cfg2_regs, id, &ts_ctrl_cfg, FALSE);
        if(retStatus != CSL_PASS)
            SBL_log(SBL_LOG_ERR,"Failed to Set Global Cfg values for Sensor ID %d \r\n", id);

        /* Set allowed Max Temp at which SoC will run, and the Safe Temp it needs to return to after hitting the Max */
        retStatus = CSL_vtmTsSetMaxTOutRgAlertThr(p_vtm_cfg2_regs, id, (int32_t)J72XX_MAX_TEMP_VAL, (int32_t)J72XX_SAFE_TEMP_VAL);
        if(retStatus != CSL_PASS)
            SBL_log(SBL_LOG_ERR,"Failed to program TSHUT temp values for Sensor ID %d \r\n", id);
    }
}

void SBL_SocLateInit(void)
{
    J721E_EnableThermalMaxTempAlert();

    SBL_ADD_PROFILE_POINT;

    J721E_SetupLeoPmicAvs(SBL_OPP_NOM);

#if !defined(SBL_ENABLE_DEV_GRP_MCU) && !defined(SBL_USE_MCU_DOMAIN_ONLY)
    SBL_SetQoS();
#endif

    SBL_ADD_PROFILE_POINT;
}

static void J721E_UART_InitPwrClk(void)
{
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK0_OFFSET, SBL_UART_PLL_KICK0_UNLOCK_VAL);
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK1_OFFSET, SBL_UART_PLL_KICK1_UNLOCK_VAL);

    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_DIV_OFFSET, SBL_UART_PLL_DIV_VAL);

    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK0_OFFSET, SBL_UART_PLL_KICK_LOCK_VAL);
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK1_OFFSET, SBL_UART_PLL_KICK_LOCK_VAL);
}

static void J721E_SetupLvCmosDriveStrength(void)
{
    volatile uint32_t *reg1 = (uint32_t *)0x43005008;
    volatile uint32_t *reg2 = (uint32_t *)0x4300500C;
    volatile uint32_t *lvcmos_drv_h_base = (uint32_t *)0x430060c0;
    volatile uint32_t *lvcmos_drv_v_base = (uint32_t *)0x430060d0;
    volatile uint32_t i;

    *reg1 = 0x68EF3490;
    *reg2 = 0xD172BC5A;
    /* Workaround for fixing lvcmos drive strength */
    for (i = 0; i < 4; i++)
    {
       *(lvcmos_drv_h_base + i) = 0xD;
       *(lvcmos_drv_v_base + i ) = 0xD;
    }
}

void SBL_SocEarlyInit()
{
    J721E_SetupLvCmosDriveStrength();
    J721E_UART_InitPwrClk();
}

#endif

#if defined(SOC_J7200)
#include <ti/board/src/j7200_evm/include/board_internal.h>

static void J7200_UART_InitPwrClk(void)
{
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK0_OFFSET, SBL_UART_PLL_KICK0_UNLOCK_VAL);
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK1_OFFSET, SBL_UART_PLL_KICK1_UNLOCK_VAL);

    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_DIV_OFFSET, SBL_UART_PLL_DIV_VAL);

    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK0_OFFSET, SBL_UART_PLL_KICK_LOCK_VAL);
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK1_OFFSET, SBL_UART_PLL_KICK_LOCK_VAL);
}

void SBL_SocEarlyInit()
{
    J7200_UART_InitPwrClk();
}

void SBL_SocLateInit(void)
{
}
#endif

#if defined(SOC_J721S2)
#if defined(j721s2_evm)
#include <ti/board/src/j721s2_evm/include/board_internal.h>
#elif defined(j721s2_hyd)
#include <ti/board/src/j721s2_hyd/include/board_internal.h>
#else
#error No board define
#endif

/*****************************************************************************
 * Name         : J721S2_SetLeoPmicVoltages
 * Parameters   : addr     = PMIC I2C Slave Address
 *                resource = PMIC Power resource driving AVS VDD_CPU
 * Return Values: BOARD_SOK                 = VDD_CPU AVS Success
 *                BOARD_INVALID_PARAM       = Invalid Power Resource parameter
 *                BOARD_I2C_OPEN_FAIL       = I2C Handle request has failed
 *                BOARD_I2C_TRANSFER_FAIL   = I2C Read or Write has failed
 * Description  : This function evaluates and sends Automatic Voltage Scaling
 *                commmand to PMIC for J721S2 VDD_CPU.
 *
 * Note         : The voltage VDD_CPU domain is defined by voltage domain 2,
 *                therefore VTM_VD_DEVINFO_2 and VTM_VD_OPPVID_2 registers
 *                must be evaluated before sending PMIC AVS command.
 *                If VTM_VD_DEVINFO_2[12].AVS0_SUP is set, then the device
 *                should set the voltage defined in VTM_VD_OPPVID_2[15-8].OPP_1.
 *                The voltage is encoded according to table 5-15 in the J721S2
 *                Technical Reference Manuel.
 ****************************************************************************/
static Board_STATUS J721S2_SetLeoPmicVoltages(uint8_t addr, uint8_t resource)
{
    uint8_t opp1             = 0;
    I2C_Handle handle        = NULL;
    Board_STATUS status      = BOARD_SOK;
    uint32_t devInfo, oppVid = 0;

    /* Get VTM_VD_DEVINFO_2 register value */
    devInfo = CSL_REG32_RD(SBL_VTM_CFG_BASE + CSL_VTM_CFG1_VD_DEVINFO(2));

    /* Evaluate VTM_VD_DEVINFO_2[12].AVS0_SUP bit for AVS support */
    if(devInfo & CSL_VTM_CFG1_DEVINFO_AVS0_SUP_MASK)
    {
        /* Get the AVS voltage from VTM_VTM_VD_OPPVID_2[15-8].OPP_1 */
        oppVid  = CSL_REG32_RD(SBL_VTM_CFG_BASE + CSL_VTM_CFG1_VD_OPPVID(2));
        opp1 = ((oppVid & CSL_VTM_CFG1_VTM_VD_OPPVID_OPP_1_MASK) >> (CSL_VTM_CFG1_VTM_VD_OPPVID_OPP_1_SHIFT));

        /* Get WKUP Domain I2C Driver Handle */
        handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP, BOARD_I2C_PMIC_INSTANCE);

        if (handle != NULL)
        {
            /* Send TPS65941 AVS Voltage Command */
            status = Board_tps65941SetVoltage(handle, addr, resource, sblMapOtpVidToMilliVolts[opp1]);
            SBL_log(SBL_LOG_MAX, "VTM_VD_OPPVID_2[15-8].OPP_1 = 0x%x, Voltage = %d, PMIC I2C Addr = 0x%x, Power Resource = 0x%x\r\n", opp1, sblMapOtpVidToMilliVolts[opp1], addr, resource);
        }
        else
        {   /* I2C Handle Failure */
            status = BOARD_I2C_OPEN_FAIL;
        }
    }
    return status;
}


static void J721S2_SetVpacClkMux(void)
{

    int32_t retVal = 0;

    /* Set VPAC Clock Mux to use 600 Mhz clock */
    retVal = Sciclient_pmSetModuleClkParent(SBL_DEV_VPAC0,
                                            SBL_DEV_VPAC0_MAIN_CLK,
                                            SBL_DEV_VPAC0_MAIN_CLK_PARENT_HSDIV4_16FFT_MAIN_2_HSDIVOUT1_CLK,
                                            SCICLIENT_SERVICE_WAIT_FOREVER);
    if(retVal != CSL_PASS)
	{
        SBL_log(SBL_LOG_ERR,"Sciclient_pmSetModuleClkParent for VPAC Clock Mux Failed \r\n");
	}
}

static void J721S2_UART_InitPwrClk(void)
{
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK0_OFFSET, SBL_UART_PLL_KICK0_UNLOCK_VAL);
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK1_OFFSET, SBL_UART_PLL_KICK1_UNLOCK_VAL);

    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_DIV_OFFSET, SBL_UART_PLL_DIV_VAL);

    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK0_OFFSET, SBL_UART_PLL_KICK_LOCK_VAL);
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK1_OFFSET, SBL_UART_PLL_KICK_LOCK_VAL);
}

void SBL_SocEarlyInit()
{
    J721S2_UART_InitPwrClk();
}

Board_STATUS SBL_moduleClockDisable(uint32_t moduleId)
{
    Board_STATUS retVal = BOARD_SOK;
    int32_t      status = CSL_EFAIL;
    uint32_t     moduleState = 0U;
    uint32_t     resetState = 0U;
    uint32_t     contextLossState = 0U;

    /* Get the module state.
       No need to change the module state if it
       is already OFF
     */
    status = Sciclient_pmGetModuleState(moduleId,
                                        &moduleState,
                                        &resetState,
                                        &contextLossState,
                                        SCICLIENT_SERVICE_WAIT_FOREVER);
    if(moduleState != TISCI_MSG_VALUE_DEVICE_HW_STATE_OFF)
    {
        status = Sciclient_pmSetModuleState(moduleId,
                                            TISCI_MSG_VALUE_DEVICE_SW_STATE_AUTO_OFF,
                                            (TISCI_MSG_FLAG_AOP |
                                             TISCI_MSG_FLAG_DEVICE_RESET_ISO),
                                             SCICLIENT_SERVICE_WAIT_FOREVER);
        if (status == CSL_PASS)
        {
            status = Sciclient_pmSetModuleRst (moduleId,
                                               0x1U,
                                               SCICLIENT_SERVICE_WAIT_FOREVER);
            if (status != CSL_PASS)
            {
                retVal = CSL_EFAIL;
            }
        }
        else
        {
            retVal = CSL_EFAIL;
        }
    }

    return retVal;
}


void SBL_SocLateInit(void)
{
	int32_t retVal = 0;
	
	J721S2_SetVpacClkMux();

	/* Attempt to turn off DMPAC */
    retVal = SBL_moduleClockDisable(SBL_DEV_DMPAC0);
    if(retVal != CSL_PASS)
    {
        SBL_log(SBL_LOG_ERR,"Failed to power off DMPAC\r\n");
    }

	/* Attempt to turn off CODEC */
    retVal = SBL_moduleClockDisable(SBL_DEV_CODEC0);
    if(retVal != CSL_PASS)
    {
        SBL_log(SBL_LOG_ERR,"Failed to power off CODEC\r\n");
    }

#if defined(QOS_WORKAROUND_FOR_GPU)
    qos_work_around_for_gpu();
#endif
    /* Perform Adaptive Voltage Scaling for VDD_CPU rail */
    retVal = J721S2_SetLeoPmicVoltages(BOARD_I2C_LEO_PMIC_A_ADDR, BOARD_TPS65941_BUCK1_RESOURCE);    
    if (retVal != BOARD_SOK)
    {
        SBL_log(SBL_LOG_ERR,"Failed to perform Adaptive Voltage Scaling for VDD_CPU\r\n");
    }
}
#endif

#if defined(SOC_J784S4)
#include <ti/board/src/j784s4_evm/include/board_internal.h>

static void J784S4_UART_InitPwrClk(void)
{
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK0_OFFSET, SBL_UART_PLL_KICK0_UNLOCK_VAL);
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK1_OFFSET, SBL_UART_PLL_KICK1_UNLOCK_VAL);

    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_DIV_OFFSET, SBL_UART_PLL_DIV_VAL);

    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK0_OFFSET, SBL_UART_PLL_KICK_LOCK_VAL);
    HW_WR_REG32(SBL_UART_PLL_BASE + SBL_UART_PLL_KICK1_OFFSET, SBL_UART_PLL_KICK_LOCK_VAL);
}

void SBL_SocEarlyInit()
{
    J784S4_UART_InitPwrClk();
}

void SBL_SocLateInit(void)
{
#if !defined(SBL_USE_MCU_DOMAIN_ONLY)
    SBL_SetQoS();
#endif
}
#endif

int32_t SBL_VerifyCertStore(void** img_handle,
    uint32_t* ImageOffsetPtr,
    uint8_t* scratch_mem,
    uint32_t scratch_sz)
{
    uint8_t* scratch_mem_ptr;
    uint32_t cert_len = 0, img_len, cert_load_addr;
    int32_t retVal = E_FAIL;
    uint32_t SBL_GetCertLen(uint8_t * x509_cert_ptr);
    uint32_t SBL_GetMsgLen(uint8_t * x509_cert_ptr, uint32_t x509_cert_size);

    SBL_ADD_PROFILE_POINT;

    if ((fp_readData != NULL) && (fp_seek != NULL))
    {
        uint8_t x509Header[4];
        /* Read first 4 bytes of image to */
        /* determine if it is a x509 img  */
        fp_readData(x509Header, *img_handle, 4);
        fp_seek(*img_handle, *ImageOffsetPtr);
        cert_len = SBL_GetCertLen(x509Header);
    }

    /* Check if cert size is within valid range */
    if ((cert_len > 0x100) &&
        (cert_len < 0x800) &&
        (scratch_mem != NULL) &&
        (scratch_sz != 0))
    {
        uint8_t unaligned_bytes = cert_len % 4;
        uint8_t pad_align = 4 - unaligned_bytes;

        SBL_log(SBL_LOG_MAX, "SBL reserved memory Found: Start = @ 0x%x, Size = 0x%x\r\n", scratch_mem, scratch_sz);
        /* adjust cert load addr so that the */
        /* msg is always word aligned        */
        scratch_mem_ptr = scratch_mem + pad_align;
        SBL_log(SBL_LOG_MAX, "Copying %d bytes from app to 0x%x\r\n", cert_len + pad_align, scratch_mem_ptr);
        fp_readData(scratch_mem_ptr, *img_handle, cert_len + pad_align);
        fp_seek(*img_handle, *ImageOffsetPtr);
        cert_load_addr = (uint32_t)scratch_mem_ptr;

        img_len = SBL_GetMsgLen(scratch_mem_ptr, cert_len);
        if ((scratch_mem_ptr + cert_len + img_len) <
            (scratch_mem + scratch_sz))
        {
            struct tisci_msg_proc_auth_boot_req authReq = {0};

            fp_seek(*img_handle, (*ImageOffsetPtr + cert_len - unaligned_bytes));
            scratch_mem_ptr += (cert_len - unaligned_bytes);

            img_len += unaligned_bytes;
            unaligned_bytes = img_len % 4;
            pad_align = 4 - unaligned_bytes;
            img_len += pad_align;

            SBL_log(SBL_LOG_MAX, "Copying %d bytes from offset 0x%x to 0x%x...", img_len, *ImageOffsetPtr + cert_len - unaligned_bytes, scratch_mem_ptr);
            fp_readData(scratch_mem_ptr, *img_handle, img_len);
            fp_seek(*img_handle, *ImageOffsetPtr);

            /* Request DMSC to authenticate the image */
            authReq.certificate_address_hi = 0;
            authReq.certificate_address_lo = cert_load_addr;
            SBL_log(SBL_LOG_MAX, "Cert @ 0x%x ...", authReq.certificate_address_lo);

            SBL_ADD_PROFILE_POINT;

            retVal = Sciclient_procBootAuthAndStart(&authReq, SCICLIENT_SERVICE_WAIT_FOREVER);

            SBL_ADD_PROFILE_POINT;
        }
    }
	
    SBL_ADD_PROFILE_POINT;

    return retVal;
}

#if defined(PMIC_PATCH)
#if defined(SOC_J721E) || defined(SOC_J721S2)
////////////////////////////////////////////////////////////////////////////////
//
// TPS65941 NVM Example Code
//
#include <ti/board/src/devices/pmic/tps65941.h>

/* Structure holding information about the Leo PMIC configuration*/
typedef struct
{
    /* Device Address */
	uint8_t    devAddr;
    /* Address / Offset */
    uint8_t    regAddr;
    /* Value to be written. */
    uint8_t    value;
} SBL_TPS659541_AddrValuePair_t;

/* Wait for transfer to complete */
static const SBL_TPS659541_AddrValuePair_t nvm_update_check_transfer_complete[1] =
{
    {0x49,0xF3,0x00}
};

static const SBL_TPS659541_AddrValuePair_t nvm_update_check_eeprom[3] =
{
    {0x48,0xA7,0x00}, // "Read Customer NVM ID register. If 0x01, code doesn't need to run. "},
    {0x48,0x02,0x13}, // a0497134 - 11/17/2023, Read TI NVM ID register. If NOT 0x13 do not run code
    {0x48,0x03,0x04}  // a0497134 - 11/17/2023, Read TI NVM REV. If NOT 0x04 do not run code.
};


/* Readback CRC values, to write at alternate location */
static const SBL_TPS659541_AddrValuePair_t nvm_update_read_crc[2] =
{
    {0x49,0xEE,0x00}, // Read for writeback to different location. Variable REGMAP_CONFIG_CRC16_LOW
    {0x49,0xED,0x00} // Read for writeback to different location. Variable REGMAP_CONFIG_CRC16_HIGH
};


/* Power cycle PMIC */
//static const SBL_TPS659541_AddrValuePair_t nvm_update_power_cycle[2] =
//{
//    {0x48,0xC3,0x60},
//    {0x48,0xAB,0x01} /// PMIC will power cycle and use new power up sequence.
//};

/* Values to be written to unlock NVM */
static SBL_TPS659541_AddrValuePair_t nvm_update_unlock_eeprom[] =
{
    {0x48,0xA2,0x00}, // "Unlocking commands, must be done as consecutive commands"},
    {0x48,0xA2,0x98},
    {0x48,0xA2,0xB8},
    {0x48,0xA2,0x13},
    {0x48,0xA2,0x7D},
    {0x49,0x18,0x05}, // Disable register CRC
    {0x49,0xE1,0x2E}, // Configure for in-system mode and EEPROM Bank0
    {0x48,0xA3,0xC1}, // Set programming mode
    {0x49,0xE2,0x38},

    //{0x49,0xE7,0x02}, // On 11/15/2023 received updated XLS for these values
    //{0x49,0xE8,0xD0},
    //{0x49,0xE9,0x00},
    //{0x49,0xEA,0x19},
    {0x49,0xE7,0x00}, // On 11/15/2023 received updated XLS for these values
    {0x49,0xE8,0x00},
    {0x49,0xE9,0x02},
    {0x49,0xEA,0x01},

    {0x49,0xEF,0x02}, // "Point of No Return, after executing this write, the NVM update must  continue. "},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

	{0xFF,0xFF,0xFF}
};


static SBL_TPS659541_AddrValuePair_t nvm_update_program_eeprom[] =
{
    // Added 11/15/2023
	{0x49,	0xE2,	0x39},
	{0x49,	0xE7,	0xA5},
	{0x49,	0xE8,	0x00},
	{0x49,	0xE9,	0x1F},
	{0x49,	0xEA,	0xA0},
	{0x49,	0xEF,	0x02},
    //Read	0x49	0xF3		Do not continue until this doesn't equal 0x02

    {0x49,0xE1,0x2D}, // Configure for in-system mode and EEPROM Bank1
    {0x49,0xE2,0x0A},
    {0x49,0xE7,0xA8},
    {0x49,0xE8,0x80},
    {0x49,0xE9,0x90},
    {0x49,0xEA,0xAA},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    // Added 11/15/2023
	{0x49,	0xE2,	0x0B},
	{0x49,	0xE7,	0x00},
	{0x49,	0xE8,	0x45},
	{0x49,	0xE9,	0x42},
	{0x49,	0xEA,	0xBA},
	{0x49,	0xEF,	0x02},
    //Read	0x49	0xF3		Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x0C},
    {0x49,0xE7,0x9F},
    {0x49,0xE8,0x89},
    {0x49,0xE9,0x44},
    {0x49,0xEA,0xCA},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x0D},
    {0x49,0xE7,0xA7},
    {0x49,0xE8,0x80},
    {0x49,0xE9,0xFC},
    {0x49,0xEA,0xDA},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x0E},
    {0x49,0xE7,0xA8},
    {0x49,0xE8,0x00},
    {0x49,0xE9,0xFC},
    {0x49,0xEA,0xEA},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    // Added 11/15/2023
	{0x49,	0xE2,	0x0F},
	{0x49,	0xE7,	0x64},
	{0x49,	0xE8,	0x90},
	{0x49,	0xE9,	0x98},
	{0x49,	0xEA,	0xFA},
	{0x49,	0xEF,	0x02},
    //Read	0x49	0xF3		Do not continue until this doesn't equal 0x02


    {0x49,0xE2,0x12},
    {0x49,0xE7,0x7C},
    {0x49,0xE8,0x60},
    {0x49,0xE9,0x9F},
    {0x49,0xEA,0x2A},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x13},
    {0x49,0xE7,0x7C},
    {0x49,0xE8,0x60},
    {0x49,0xE9,0x9D},
    {0x49,0xEA,0x3A},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x14},
    {0x49,0xEA, 0x4a},
    {0x49,0xE9, 0x9b},
    {0x49,0xE8, 0x60},
    {0x49,0xE7, 0x7c},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x15},
    {0x49,0xEA, 0x5a},
    {0x49,0xE9, 0xa3},
    {0x49,0xE8, 0x30},
    {0x49,0xE7, 0x93},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x16},
    {0x49,0xEA, 0x6a},
    {0x49,0xE9, 0xa1},
    {0x49,0xE8, 0x30},
    {0x49,0xE7, 0x93},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x17},
    {0x49,0xEA, 0x7a},
    {0x49,0xE9, 0xc1},
    {0x49,0xE8, 0xb0},
    {0x49,0xE7, 0x46},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x18},
    {0x49,0xEA, 0x8a},
    {0x49,0xE9, 0xc7},
    {0x49,0xE8, 0xe0},
    {0x49,0xE7, 0xa5},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02


    // Added 11/15/2023
	{0x49,	0xE2,	0x19},
	{0x49,	0xEA,	0x9A},
	{0x49,	0xE9,	0x09},
	{0x49,	0xE8,	0x20},
	{0x49,	0xE7,	0x1C},
	{0x49,	0xEF,	0x02},
    //Read	0x49	0xF3		Do not continue until this doesn't equal 0x02


    {0x49,0xE1,0x2B}, // Configure for in-system mode and EEPROM Bank1
    {0x49,0xE2,0x30},
    {0x49,0xEA, 0x7b},
    {0x49,0xE9, 0xd3},
    {0x49,0xE8, 0xe0},
    {0x49,0xE7, 0xd0},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x31},
    {0x49,0xEA, 0x18},
    {0x49,0xE9, 0xe1},
    {0x49,0xE8, 0x5e},
    {0x49,0xE7, 0x10},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x32},
    {0x49,0xEA, 0x18},
    {0x49,0xE9, 0xe1},
    {0x49,0xE8, 0x5e},
    {0x49,0xE7, 0xf8},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x33},
    {0x49,0xEA, 0x47},
    {0x49,0xE9, 0x74},
    {0x49,0xE8, 0x50},
    {0x49,0xE7, 0x1a},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x34},
    {0x49,0xEA, 0xe1},
    {0x49,0xE9, 0xae},
    {0x49,0xE8, 0x34},
    {0x49,0xE7, 0x42},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x35},
    {0x49,0xEA, 0x5a},
    {0x49,0xE9, 0x33},
    {0x49,0xE8, 0x65},
    {0x49,0xE7, 0x90},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x36},
    {0x49,0xEA, 0x04},
    {0x49,0xE9, 0xc0},
    {0x49,0xE8, 0x0c},
    {0x49,0xE7, 0x4a},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x37},
    {0x49,0xEA, 0x00},
    {0x49,0xE9, 0xcc},
    {0x49,0xE8, 0xbe},
    {0x49,0xE7, 0x04},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x38},
    {0x49,0xEA, 0x38},
    {0x49,0xE9, 0xc0},
    {0x49,0xE8, 0x04},
    {0x49,0xE7, 0xc0},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x39},
    {0x49,0xEA, 0x0c},
    {0x49,0xE9, 0x4d},
    {0x49,0xE8, 0x00},
    {0x49,0xE7, 0xcc},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x3A},
    {0x49,0xEA, 0x2d},
    {0x49,0xE9, 0x68},
    {0x49,0xE8, 0x1e},
    {0x49,0xE7, 0x38},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x3B},
    {0x49,0xEA, 0x38},
    {0x49,0xE9, 0x8b},
    {0x49,0xE8, 0x30},
    {0x49,0xE7, 0x00},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x3C},
    {0x49,0xEA, 0xe0},
    {0x49,0xE9, 0xec},
    {0x49,0xE8, 0x81},
    {0x49,0xE7, 0x38},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x3D},
    {0x49,0xEA, 0xd0},
    {0x49,0xE9, 0x82},
    {0x49,0xE8, 0x48},
    {0x49,0xE7, 0x2a},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x3E},
    {0x49,0xEA, 0x80},
    {0x49,0xE9, 0x3b},
    {0x49,0xE8, 0xe6},
    {0x49,0xE7, 0x04},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x3F},
    {0x49,0xEA, 0xc0},
    {0x49,0xE9, 0x41},
    {0x49,0xE8, 0x24},
    {0x49,0xE7, 0x80},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE1,0x27}, // Configure for in-system mode and EEPROM Bank3
    {0x49,0xE2,0x00},
    {0x49,0xEA,0x7B},
    {0x49,0xE9, 0x71},
    {0x49,0xE8, 0x27},
    {0x49,0xE7, 0x40},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x01},
    {0x49,0xEA, 0xe0},
    {0x49,0xE9, 0x1d},
    {0x49,0xE8, 0xc0},
    {0x49,0xE7, 0x81},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x02},
    {0x49,0xEA, 0x05},
    {0x49,0xE9, 0xed},
    {0x49,0xE8, 0x13},
    {0x49,0xE7, 0x18},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x03},
    {0x49,0xEA, 0x61},
    {0x49,0xE9, 0x1d},
    {0x49,0xE8, 0x70},
    {0x49,0xE7, 0x28},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x04},
    {0x49,0xEA, 0x40},
    {0x49,0xE9, 0xe0},
    {0x49,0xE8, 0x4c},
    {0x49,0xE7, 0x83},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x05},
    {0x49,0xEA, 0x73},
    {0x49,0xE9, 0x67},
    {0x49,0xE8, 0x40},
    {0x49,0xE7, 0xe0},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x06},
    {0x49,0xEA, 0x1d},
    {0x49,0xE9, 0xd1},
    {0x49,0xE8, 0x61},
    {0x49,0xE7, 0x20},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x07},
    {0x49,0xEA, 0x70},
    {0x49,0xE9, 0x28},
    {0x49,0xE8, 0xc0},
    {0x49,0xE7, 0xe0},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x08},
    {0x49,0xEA, 0x4c},
    {0x49,0xE9, 0xf8},
    {0x49,0xE8, 0xe4},
    {0x49,0xE7, 0x4d},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x09},
    {0x49,0xEA, 0xf8},
    {0x49,0xE9, 0x04},
    {0x49,0xE8, 0x4a},
    {0x49,0xE7, 0x33},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x0A},
    {0x49,0xEA, 0xcc},
    {0x49,0xE9, 0x0e},
    {0x49,0xE8, 0x12},
    {0x49,0xE7, 0x1d},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x0B},
    {0x49,0xEA, 0x34},
    {0x49,0xE9, 0x46},
    {0x49,0xE8, 0xb8},
    {0x49,0xE7, 0x17},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x0C},
    {0x49,0xEA, 0x94},
    {0x49,0xE9, 0x46},
    {0x49,0xE8, 0xb8},
    {0x49,0xE7, 0x3f},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x0D},
    {0x49,0xEA, 0x8d},
    {0x49,0xE9, 0x90},
    {0x49,0xE8, 0xd6},
    {0x49,0xE7, 0x4c},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x0E},
    {0x49,0xEA, 0x19},
    {0x49,0xE9, 0x30},
    {0x49,0xE8, 0x01},
    {0x49,0xE7, 0x30},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x0F},
    {0x49,0xEA, 0x43},
    {0x49,0xE9, 0x13},
    {0x49,0xE8, 0x00},
    {0x49,0xE7, 0x33},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x10},
    {0x49,0xEA, 0x28},
    {0x49,0xE9, 0x01},
    {0x49,0xE8, 0x30},
    {0x49,0xE7, 0xbb},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x11},
    {0x49,0xEA, 0x20},
    {0x49,0xE9, 0x38},
    {0x49,0xE8, 0x74},
    {0x49,0xE7, 0x60},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x12},
    {0x49,0xEA, 0x2c},
    {0x49,0xE9, 0x3a},
    {0x49,0xE8, 0x19},
    {0x49,0xE7, 0x80},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x13},
    {0x49,0xEA, 0xb3},
    {0x49,0xE9, 0x07},
    {0x49,0xE8, 0x12},
    {0x49,0xE7, 0x8c},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x14},
    {0x49,0xEA, 0x0b},
    {0x49,0xE9, 0xe2},
    {0x49,0xE8, 0x03},
    {0x49,0xE7, 0x16},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x15},
    {0x49,0xEA, 0x34},
    {0x49,0xE9, 0x02},
    {0x49,0xE8, 0xba},
    {0x49,0xE7, 0x02},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x16},
    {0x49,0xEA, 0x70},
    {0x49,0xE9, 0xb8},
    {0x49,0xE8, 0x07},
    {0x49,0xE7, 0x70},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x17},
    {0x49,0xEA, 0x90},
    {0x49,0xE9, 0x0a},
    {0x49,0xE8, 0xe0},
    {0x49,0xE7, 0x4e},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x18},
    {0x49,0xEA, 0x39},
    {0x49,0xE9, 0x01},
    {0x49,0xE8, 0x70},
    {0x49,0xE7, 0x10},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x19},
    {0x49,0xEA, 0x09},
    {0x49,0xE9, 0xe0},
    {0x49,0xE8, 0x5e},
    {0x49,0xE7, 0x38},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x1A},
    {0x49,0xEA, 0x08},
    {0x49,0xE9, 0x70},
    {0x49,0xE8, 0xdc},
    {0x49,0xE7, 0x09},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x1B},
    {0x49,0xEA, 0x10},
    {0x49,0xE9, 0x78},
    {0x49,0xE8, 0x07},
    {0x49,0xE7, 0x70},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x1C},
    {0x49,0xEA, 0x60},
    {0x49,0xE9, 0x41},
    {0x49,0xE8, 0xfb},
    {0x49,0xE7, 0x80},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x1D},
    {0x49,0xEA, 0x07},
    {0x49,0xE9, 0x92},
    {0x49,0xE8, 0xc1},
    {0x49,0xE7, 0xa2},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x1E},
    {0x49,0xEA, 0xff},
    {0x49,0xE9, 0x81},
    {0x49,0xE8, 0xbf},
    {0x49,0xE7, 0x39},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x1F},
    {0x49,0xEA, 0x63},
    {0x49,0xE9, 0xca},
    {0x49,0xE8, 0x4d},
    {0x49,0xE7, 0x55},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x20},
    {0x49,0xEA, 0x21},
    {0x49,0xE9, 0x0a},
    {0x49,0xE8, 0x66},
    {0x49,0xE7, 0x88},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x21},
    {0x49,0xEA, 0x82},
    {0x49,0xE9, 0x1b},
    {0x49,0xE8, 0xa2},
    {0x49,0xE7, 0x4c},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x22},
    {0x49,0xEA, 0x84},
    {0x49,0xE9, 0x28},
    {0x49,0xE8, 0x7d},
    {0x49,0xE7, 0xa2},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x23},
    {0x49,0xEA, 0x91},
    {0x49,0xE9, 0x41},
    {0x49,0xE8, 0x7e},
    {0x49,0xE7, 0xbf},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x24},
    {0x49,0xEA, 0x0f},
    {0x49,0xE9, 0x52},
    {0x49,0xE8, 0x34},
    {0x49,0xE7, 0x15},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x25},
    {0x49,0xEA, 0x85},
    {0x49,0xE9, 0x28},
    {0x49,0xE8, 0x00},
    {0x49,0xE7, 0xdc},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x26},
    {0x49,0xEA, 0xc3},
    {0x49,0xE9, 0xbe},
    {0x49,0xE8, 0xf8},
    {0x49,0xE7, 0xfe},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x27},
    {0x49,0xEA, 0xff},
    {0x49,0xE9, 0xcf},
    {0x49,0xE8, 0x28},
    {0x49,0xE7, 0xc0},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x28},
    {0x49,0xEA, 0x28},
    {0x49,0xE9, 0xc0},
    {0x49,0xE8, 0x1e},
    {0x49,0xE7, 0x88},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x29},
    {0x49,0xEA, 0x03},
    {0x49,0xE9, 0x2d},
    {0x49,0xE8, 0x88},
    {0x49,0xE7, 0xa4},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x2A},
    {0x49,0xEA, 0x02},
    {0x49,0xE9, 0xb8},
    {0x49,0xE8, 0x63},
    {0x49,0xE7, 0x4e},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x2B},
    {0x49,0xEA, 0x00},
    {0x49,0xE9, 0x1c},
    {0x49,0xE8, 0x44},
    {0x49,0xE7, 0x02},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x2C},
    {0x49,0xEA, 0xb8},
    {0x49,0xE9, 0x17},
    {0x49,0xE8, 0x77},
    {0x49,0xE7, 0x02},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x2D},
    {0x49,0xEA, 0x04},
    {0x49,0xE9, 0xde},
    {0x49,0xE8, 0x01},
    {0x49,0xE7, 0x1c},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x2E},
    {0x49,0xEA, 0x8b},
    {0x49,0xE9, 0x4e},
    {0x49,0xE8, 0xfe},
    {0x49,0xE7, 0xe6},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x2F},
    {0x49,0xEA, 0xe6},
    {0x49,0xE9, 0x8c},
    {0x49,0xE8, 0x29},
    {0x49,0xE7, 0x03},
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    // CRC Writing


    // Added 11/15/2023
	{0x49,	0xE1,	0x2E},
	{0x49,	0xE2,	0x3C},
	{0x49,	0xEA,	0xC3},
	{0x49,	0xE9,	0xFF},
	{0x49,	0xE8,	0x00},
	{0x49,	0xE7,	0x00},
	{0x49,	0xEF,	0x02},
    //Read	0x49	0xF3		Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x3D},
    {0x49,0xEA,0x19}, // REGMAP_USER_INCLUDE_PERSIST_CRC16_LOW, (a0497134 - 11/17/2023 Updates)
    {0x49,0xE9,0xAC}, // REGMAP_USER_INCLUDE_PERSIST_CRC16_HIGH (a0497134 - 11/17/2023 Updates)
    {0x49,0xE8,0x5E}, // REGMAP_USER_EXCLUDE_PERSIST_CRC16_LOW  (a0497134 - 11/17/2023 Updates)
    {0x49,0xE7,0xF3}, // REGMAP_USER_EXCLUDE_PERSIST_CRC16_HIGH (a0497134 - 11/17/2023 Updates)
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    // Added 11/15/2023
	{0x49,	0xE2,	0x3E},
	{0x49,	0xEF,	0x01},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    // Read    {0x49,0xEE,,Store as variable REGMAP_CONFIG_CRC16_LOW},
    // Read    {0x49,0xED,,Store as variable REGMAP_CONFIG_CRC16_HIGH},
    {0x49,0xEA,0x99}, // Use  REGMAP_CONFIG_CRC16_LOW  read from 0xEE
    {0x49,0xE9,0x99}, // Used REGMAP_CONFIG_CRC16_HIGH read from 0xED
    {0x49,0xE8,0xB2}, // PFSM_BANK0_CRC16_LOW
    {0x49,0xE7,0X9E}, // PFSM_BANK0_CRC16_HIGH
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

    {0x49,0xE2,0x3F},
    {0x49,0xEA,0x72}, // PFSM_BANK1_CRC16_LOW
    {0x49,0xE9,0x3A}, // PFSM_BANK1_CRC16_HIGH
    {0x49,0xE8,0xD9}, // PFSM_BANK2_CRC16_LOW
    {0x49,0xE7,0x88}, // PFSM_BANK2_CRC16_HIGH
    {0x49,0xEF,0x02},
    // Read    {0x49,0xF3}, Do not continue until this doesn't equal 0x02

	{0xFF,0xFF,0xFF}
};

//a0497134 - 11/17/2023, Function re-named
Board_STATUS SBL_TPS65941_ReadCustomerEepromId(I2C_Handle handle, uint8_t *regData)
{
	Board_STATUS boardStatus = BOARD_SOK;

   // If EEPROM is 'x', then i2406 has not been addressed, program EEPROM and
   // Reset, otherwise continue regular boot flow

   // Read the the TPS65941 PMIC CUSTOMER_NVM_ID_REG
   boardStatus = Board_i2c8BitRegRd(handle,
                                    nvm_update_check_eeprom[0].devAddr,
                                    nvm_update_check_eeprom[0].regAddr,
                                    regData,
                                    BOARD_I2C_NUM_OF_BYTES_01,
                                    BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x), eeprom register read failed\n\r",
            nvm_update_check_eeprom[0].devAddr,
            nvm_update_check_eeprom[0].regAddr);

    }
    else
    {
        SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register read\n\r",
            nvm_update_check_eeprom[0].devAddr,
            nvm_update_check_eeprom[0].regAddr, *regData);
    }
	return boardStatus;
}

//a0497134 - 11/17/2023, Added new function for reading TI_NVM_ID from NVM_CODE1
Board_STATUS SBL_TPS65941_ReadTIEepromId(I2C_Handle handle, uint8_t *regData)
{
	Board_STATUS boardStatus = BOARD_SOK;

   // If EEPROM is 'x', then i2406 has not been addressed, program EEPROM and
   // Reset, otherwise continue regular boot flow

   // Read the the TPS65941 PMIC TI_NVM_ID from NVM_CODE1 register
   boardStatus = Board_i2c8BitRegRd(handle,
                                    nvm_update_check_eeprom[1].devAddr,
                                    nvm_update_check_eeprom[1].regAddr,
                                    regData,
                                    BOARD_I2C_NUM_OF_BYTES_01,
                                    BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x), eeprom register read failed\n\r",
            nvm_update_check_eeprom[1].devAddr,
            nvm_update_check_eeprom[1].regAddr);

    }
    else
    {
        SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register read\n\r",
            nvm_update_check_eeprom[1].devAddr,
            nvm_update_check_eeprom[1].regAddr, *regData);
    }
    return boardStatus;
}

//a0497134 - 11/17/2023, Added new function for reading TI_NVM_REV from NVM_CODE2 register
Board_STATUS SBL_TPS65941_ReadTIEepromRev(I2C_Handle handle, uint8_t *regData)
{
	Board_STATUS boardStatus = BOARD_SOK;

   // If EEPROM is 'x', then i2406 has not been addressed, program EEPROM and
   // Reset, otherwise continue regular boot flow

   // Read the the TPS65941 PMIC TI_NVM_REV from NVM_CODE2 register
   boardStatus = Board_i2c8BitRegRd(handle,
                                    nvm_update_check_eeprom[2].devAddr,
                                    nvm_update_check_eeprom[2].regAddr,
                                    regData,
                                    BOARD_I2C_NUM_OF_BYTES_01,
                                    BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x), eeprom register read failed\n\r",
            nvm_update_check_eeprom[2].devAddr,
            nvm_update_check_eeprom[2].regAddr);

    }
    else
    {
        SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register read\n\r",
            nvm_update_check_eeprom[2].devAddr,
            nvm_update_check_eeprom[2].regAddr, *regData);
    }
    return boardStatus;
}

void SBL_TPS65941_waitforEepromTransferComplete(I2C_Handle handle)
{
   Board_STATUS boardStatus = BOARD_SOK;
   volatile uint8_t regData = 0x2;

   while((regData & 0x02) == 0x02)
   {
       boardStatus = Board_i2c8BitRegRd(handle,
                                        nvm_update_check_transfer_complete[0].devAddr,
                                        nvm_update_check_transfer_complete[0].regAddr,
                                        (uint8_t *) &regData,
                                        BOARD_I2C_NUM_OF_BYTES_01,
                                        BOARD_I2C_TRANSACTION_TIMEOUT);
       if(boardStatus != BOARD_SOK)
       {
           SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x), register read failed\n\r",
               nvm_update_check_transfer_complete[0].devAddr,
               nvm_update_check_transfer_complete[0].regAddr);
       }
       else
       {
           // Log Read
           SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value(0x%x), register read\n\r",
            nvm_update_check_transfer_complete[0].devAddr,
            nvm_update_check_transfer_complete[0].regAddr,
            regData);
       }
   }
}



Board_STATUS SBL_TPS65941_UnlockEeprom(I2C_Handle handle)
{
    uint32_t i = 0;
	Board_STATUS boardStatus = BOARD_SOK;
#ifdef READBACK_DEBUG
    uint8_t regData = 0;
#endif

    // Unlock the EEPROM
    i = 0;
    while(!((nvm_update_unlock_eeprom[i].devAddr == 0xFF) &&
           (nvm_update_unlock_eeprom[i].regAddr == 0xFF) &&
           (nvm_update_unlock_eeprom[i].value == 0xFF)))
    {
#ifndef READBACK_DEBUG
        // Not in debug mode, write everything
        boardStatus = Board_i2c8BitRegWr(handle,
                                 nvm_update_unlock_eeprom[i].devAddr,
                                 nvm_update_unlock_eeprom[i].regAddr,
                                 &nvm_update_unlock_eeprom[i].value,
                                 BOARD_I2C_NUM_OF_BYTES_01,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
#else
        // Skip the writes to 49,EF, 02 when in debug
        if(((nvm_update_unlock_eeprom[i].devAddr == 0x49) &&
            (nvm_update_unlock_eeprom[i].regAddr == 0xEF) &&
            (nvm_update_unlock_eeprom[i].value == 0x02 || nvm_update_unlock_eeprom[i].value == 0x01)))
        {
		    // Skip the write, log below
	    }
		else
		{
              boardStatus = Board_i2c8BitRegWr(handle,
                                       nvm_update_unlock_eeprom[i].devAddr,
                                       nvm_update_unlock_eeprom[i].regAddr,
                                       &nvm_update_unlock_eeprom[i].value,
                                       BOARD_I2C_NUM_OF_BYTES_01,
                                       BOARD_I2C_TRANSACTION_TIMEOUT);
		}
#endif

        if(boardStatus != BOARD_SOK)
        {
             SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register write failed\n\r",
                 nvm_update_unlock_eeprom[i].devAddr,
                 nvm_update_unlock_eeprom[i].regAddr,
                 nvm_update_unlock_eeprom[i].value);
            return BOARD_I2C_TRANSFER_FAIL;
        }
        else
        {
#ifdef READBACK_DEBUG
       // Don't write the transfer message when debugging
       if(((nvm_update_unlock_eeprom[i].devAddr == 0x49) &&
           (nvm_update_unlock_eeprom[i].regAddr == 0xEF) &&
           (nvm_update_unlock_eeprom[i].value == 0x02 || nvm_update_program_eeprom[i].value == 0x01)))
       {
            SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register write (not actually written) \n\r",
                                    nvm_update_unlock_eeprom[i].devAddr,
                                    nvm_update_unlock_eeprom[i].regAddr,
                                    nvm_update_unlock_eeprom[i].value);
       }
	   else
       {
            SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register write\n\r",
                                    nvm_update_unlock_eeprom[i].devAddr,
                                    nvm_update_unlock_eeprom[i].regAddr,
                                    nvm_update_unlock_eeprom[i].value);
       }
#else
             // Log Write
             SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register write\n\r",
                 nvm_update_unlock_eeprom[i].devAddr,
                 nvm_update_unlock_eeprom[i].regAddr,
                 nvm_update_unlock_eeprom[i].value);
#endif

#ifdef READBACK_DEBUG
           if(nvm_update_unlock_eeprom[i].regAddr != 0xA2)
		   {
                // Debug readback what was written and compare
                boardStatus = Board_i2c8BitRegRd(handle,
                                         nvm_update_unlock_eeprom[i].devAddr,
                                         nvm_update_unlock_eeprom[i].regAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         BOARD_I2C_TRANSACTION_TIMEOUT);
                if(boardStatus != BOARD_SOK)
                {
                    SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x), register read failed\n\r",
                                         nvm_update_unlock_eeprom[i].devAddr,
                                         nvm_update_unlock_eeprom[i].regAddr);
                }
                else
                {
                    // Log Read done for readback
                    SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register readback for debug\n\r",
                            nvm_update_unlock_eeprom[i].devAddr,
                            nvm_update_unlock_eeprom[i].regAddr,
                            regData);

                   if(regData != nvm_update_unlock_eeprom[i].value)
                   {
                       SBL_log(SBL_LOG_MIN,"----- Check above write/read for accuracy -----\n\r");
                   }
                }
			}
#endif
        }

        // If this was a write of 0x2 or 0x1 to 0xEF, wait until the transfer completes
        if(((nvm_update_unlock_eeprom[i].devAddr == 0x49) &&
            (nvm_update_unlock_eeprom[i].regAddr == 0xEF) &&
            (nvm_update_unlock_eeprom[i].value == 0x02 || nvm_update_unlock_eeprom[i].value == 0x01)))
        {
            SBL_TPS65941_waitforEepromTransferComplete(handle);
        }

		i++;
	}
    return BOARD_SOK;
}


void SBL_TPS65941_programEeprom(I2C_Handle handle)
{
   uint32_t i = 0;
   Board_STATUS boardStatus = BOARD_SOK;
#ifdef READBACK_DEBUG
   uint8_t regData = 0;
#endif

   // Configure NVM for programming
   i = 0;
   while(!((nvm_update_program_eeprom[i].devAddr == 0xFF) &&
           (nvm_update_program_eeprom[i].regAddr == 0xFF) &&
           (nvm_update_program_eeprom[i].value   == 0xFF)))
   {
       // CRCs need to be read from one location, and written to another
       if(((nvm_update_program_eeprom[i].devAddr == 0x49) &&
           (nvm_update_program_eeprom[i].regAddr == 0xEA) &&
           (nvm_update_program_eeprom[i].value   == 0x99))) // 0x99 not used in any other entries
       {
           // Read 0x49,0xEE and store as variable REGMAP_CONFIG_CRC16_LOW into array
           boardStatus = Board_i2c8BitRegRd(handle,
                                    nvm_update_read_crc[0].devAddr,
                                    nvm_update_read_crc[0].regAddr,
                                    &nvm_update_program_eeprom[i].value, // REGMAP_CONFIG_CRC16_LOW
                                    BOARD_I2C_NUM_OF_BYTES_01,
                                    BOARD_I2C_TRANSACTION_TIMEOUT);
           if(boardStatus != BOARD_SOK)
           {
               SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x), register read failed\n\r",
                   nvm_update_read_crc[0].devAddr,
                   nvm_update_read_crc[0].regAddr);
		   }
           else
           {
               SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register read\n\r",
                   nvm_update_read_crc[0].devAddr,
                   nvm_update_read_crc[0].regAddr,
                   nvm_update_program_eeprom[i].value);
           }

           // Read 0x49,0xED and store as variable REGMAP_CONFIG_CRC16_LOW into array
           boardStatus = Board_i2c8BitRegRd(handle,
                                    nvm_update_read_crc[1].devAddr,
                                    nvm_update_read_crc[1].regAddr,
                                    &nvm_update_program_eeprom[i+1].value, // REGMAP_CONFIG_CRC16_HIGH,
                                    BOARD_I2C_NUM_OF_BYTES_01,
                                    BOARD_I2C_TRANSACTION_TIMEOUT);
           if(boardStatus != BOARD_SOK)
           {
               SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x), register read failed\n\r",
                   nvm_update_read_crc[1].devAddr,
                   nvm_update_read_crc[1].regAddr);
		   }
           else
           {
		       // Log Read
               SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register read\n\r",
                   nvm_update_read_crc[1].devAddr,
                   nvm_update_read_crc[1].regAddr,
                   nvm_update_program_eeprom[i+1].value);
           }
	   } // End of Read CRCs If Check
#ifdef READBACK_DEBUG
       // Don't write the transfer message when debugging
       if(((nvm_update_program_eeprom[i].devAddr == 0x49) &&
           (nvm_update_program_eeprom[i].regAddr == 0xEF) &&
           (nvm_update_program_eeprom[i].value == 0x02 || nvm_update_program_eeprom[i].value == 0x01)))
       {
            SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register write (not actually written), ignore next log \n\r",
                                    nvm_update_program_eeprom[i].devAddr,
                                    nvm_update_program_eeprom[i].regAddr,
                                    nvm_update_program_eeprom[i].value);
       }
	   else
	   {
#endif
           // Write Value from array to EEPRROM
           boardStatus = Board_i2c8BitRegWr(handle,
                                    nvm_update_program_eeprom[i].devAddr,
                                    nvm_update_program_eeprom[i].regAddr,
                                    &nvm_update_program_eeprom[i].value,
                                    BOARD_I2C_NUM_OF_BYTES_01,
                                    BOARD_I2C_TRANSACTION_TIMEOUT);
           if(boardStatus != BOARD_SOK)
           {
                SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register write failed\n\r",
                    nvm_update_program_eeprom[i].devAddr,
                    nvm_update_program_eeprom[i].regAddr,
                    nvm_update_program_eeprom[i].value);
           }
           else
           {
	            // Log Write
                SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register write\n\r",
                    nvm_update_program_eeprom[i].devAddr,
                    nvm_update_program_eeprom[i].regAddr,
                    nvm_update_program_eeprom[i].value);

#ifdef READBACK_DEBUG
                // Debug readback what was written and compare
                boardStatus = Board_i2c8BitRegRd(handle,
                                         nvm_update_program_eeprom[i].devAddr,
                                         nvm_update_program_eeprom[i].regAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         BOARD_I2C_TRANSACTION_TIMEOUT);
                if(boardStatus != BOARD_SOK)
                {
                    SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x), register read failed\n\r",
                                         nvm_update_program_eeprom[i].devAddr,
                                         nvm_update_program_eeprom[i].regAddr);
		        }
                else
                {
		            // Log Read done for readback
                    SBL_log(SBL_LOG_MIN,"TPS65941 (0x%x): Offset (0x%x) Value (0x%x), register readback for debug\n\r",
                            nvm_update_program_eeprom[i].devAddr,
                            nvm_update_program_eeprom[i].regAddr,
							regData);

                   if(regData != nvm_update_program_eeprom[i].value)
				   {
                       SBL_log(SBL_LOG_MIN,"----- Check above write/read for accuracy -----\n\r");
				   }
				}
#endif
            }

#ifdef READBACK_DEBUG
       } // End else write value to EEPROM
#endif

       // If this was a write of 0x2 or 0x1 to 0xEF, wait until the transfer completes
       if(((nvm_update_program_eeprom[i].devAddr == 0x49) &&
           (nvm_update_program_eeprom[i].regAddr == 0xEF) &&
           (nvm_update_program_eeprom[i].value == 0x02 || nvm_update_program_eeprom[i].value == 0x01)))
       {
           SBL_TPS65941_waitforEepromTransferComplete(handle);
       }

	   // Move to next array Entry
       i++;
    } // End While
}


//a0497134 Function Updated 11/17/2023
// Check if Non Volatile Memory requires update to // to address alert i2041
Board_STATUS SBL_TPS65941_NvmUpdate()
{
    I2C_Handle handle = NULL;
    volatile uint8_t ti_id   = 0;
    volatile uint8_t ti_rev  = 0;
    volatile uint8_t cust_id = 0;
    Board_STATUS boardStatus = BOARD_SOK;

    // Get I2C handle
    handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP, BOARD_I2C_PMIC_INSTANCE);
    if(handle == NULL)
    {
        SBL_log(SBL_LOG_MIN,"I2C Open Failed for NVM Update\n\r");
        //SblErrLoop(__FILE__, __LINE__); //Remove loop to continue boot sequence
        return BOARD_I2C_OPEN_FAIL;
    }

    // Read TI ID,Rev,and Customer ID to see if update is required to address advisory i2406
    boardStatus =  SBL_TPS65941_ReadCustomerEepromId(handle, (uint8_t *) &cust_id);
    boardStatus |= SBL_TPS65941_ReadTIEepromId(handle, (uint8_t *) &ti_id);
    boardStatus |= SBL_TPS65941_ReadTIEepromRev(handle, (uint8_t *) &ti_rev);
	if(boardStatus == BOARD_SOK)
	{
        if ((cust_id == 0x00) && (ti_id == 0x13) && (ti_rev == 0x04))
        {
            // EEPROM should be updated, continue with this function to update EEPROM
            SBL_log(SBL_LOG_MIN, "TPS65941 EEPROM Customer ID 0x%x, update is required\n\r", cust_id);
            SBL_log(SBL_LOG_MIN, "TPS65941 EEPROM TI ID 0x%x, update is required\n\r", ti_id);
            SBL_log(SBL_LOG_MIN, "TPS65941 EEPROM TI Revision 0x%x, update is required\n\r", ti_rev);
        }
        else
        {
            // EEPROM is up to date no update required, continue with regular boot.
            SBL_log(SBL_LOG_MIN, "TPS65941 EEPROM Customer ID 0x%x, up to date\n\r", cust_id);
            SBL_log(SBL_LOG_MIN, "TPS65941 EEPROM TI ID 0x%x, up to date\n\r", ti_id);
            SBL_log(SBL_LOG_MIN, "TPS65941 EEPROM TI Revision 0x%x, up to date\n\r", ti_rev);
            return BOARD_SOK;
        }
	}
	else
	{
        SBL_log(SBL_LOG_MIN,"TPS65941 EEPROM, Read ID failed\n\r");
        //SblErrLoop(__FILE__, __LINE__); //Remove loop to continue boot sequence
        return BOARD_INVALID_PARAM;
	}


    // Unlock the EEPROM
    if(SBL_TPS65941_UnlockEeprom(handle) != BOARD_SOK)
    {
        SBL_log(SBL_LOG_MIN,"TPS65941 EEPROM Customer ID 0x%x, update is required\n\r", cust_id);
        SBL_log(SBL_LOG_MIN,"TPS65941 EEPROM TI ID 0x%x, update is required\n\r", ti_id);
        SBL_log(SBL_LOG_MIN,"TPS65941 EEPROM TI Revision 0x%x, update is required\n\r", ti_rev);
        SBL_log(SBL_LOG_MIN,"TPS65941 EEPROM could not be unlocked, continuing with boot.\n\r");
        return BOARD_I2C_TRANSFER_FAIL;
    }

    // Configure NVM for programming
    SBL_TPS65941_programEeprom(handle);

    SBL_log(SBL_LOG_MIN,"------------------------------------------------------------\n\r");
    SBL_log(SBL_LOG_MIN,"TPS65941 EEPROM has been updated, reboot board to continue. \n\r");
    SBL_log(SBL_LOG_MIN,"    (Recommend removing power, then plugging back in)       \n\r");
    SBL_log(SBL_LOG_MIN,"------------------------------------------------------------\n\r");
    //SblErrLoop(__FILE__, __LINE__); //Remove loop to continue boot sequence

    return boardStatus;
}

//
// End TPS65941 NVM Update Example Code
//
////////////////////////////////////////////////////////////////////////////////

#endif
#endif /* PMIC_PATCH*/
