/** @file CBASS_safety.c 
 *  @brief  CBASS safety Application
 * 
 *  CBASS Safety Application
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Raghavender Yadagiri (Raghavender.Yadagiri@magna.com)
 */

/**
 * This file contains functions that monitors safety
 * for the CBASS module.
 *
 *  \details CBASS Safety module
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ti/osal/TimerP.h>
#include "app_log.h"
#include "app_log_Boot.h"
#include "fusa_application.h"
#include "CBASS_safety.h"
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/*#define SDL_APP_CBASS_UART_PRINTS_ENABLED*/
/* Enable this macro for time measurements  */
#ifndef STD_ON
#define STD_ON										  (1u)
#endif

#ifndef STD_OFF
#define STD_OFF										  (0u)
#endif

#define CBASS_PROFILING_EBABLE                        STD_OFF

#define CBASS_MAIN_REGISTERS_MISMATCH                 1u
#define CBASS_MCU_REGISTERS_MISMATCH                  2u

/* NAVSS North Bridge (NB) */
#define NAVSS0_NBSS_NB0_CFG_MMRS                      (0x03702000u)
/* Commented -- can be enabled in Future
* #define NAVSS0_NBSS_NB1_CFG_MMRS                      (0x03703000u)
*/
#define NAVSS0_NBSS_NB0_CFG_NB_THREADMAP              (NAVSS0_NBSS_NB0_CFG_MMRS + 0x10u)
/* Commented -- can be enabled in Future
* #define NAVSS0_NBSS_NB1_CFG_NB_THREADMAP              (NAVSS0_NBSS_NB1_CFG_MMRS + 0x10u)
*/

/**CBASS_AC_NONSAFE0_QOS_REGISTERS (MAIN DOMAIN - 45DC 0000H)**/
/*CBASS_AC_NONSAFE_IDMPAC_TOP_MAIN_0_DATA_MST_MAP0-MAP31 (offset - 0100h)*/
#define QOS_DMPAC0_DATA                               (0x45dc0100u)
#define QOS_DMPAC0_DATA_NUM_I_CH                      (32u)
#define QOS_DMPAC0_DATA_CBASS_MAP(i)                  (QOS_DMPAC0_DATA + (i) * 4U)

/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_0_SEC_M_VBUSM_R_ASYNC_SLV_LINKGRP_0_GRP_MAP1-MAP2 (offset - 0C00h)*/
/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_0_SEC_M_VBUSM_R_ASYNC_MAP0 (offset - 0D00h)*/
#define QOS_VPU0_SEC_RD                               (0x45dc0c00u)
#define QOS_VPU0_SEC_RD_NUM_J_CH                      (2u)
#define QOS_VPU0_SEC_RD_NUM_I_CH                      (1u)
#define QOS_VPU0_SEC_RD_CBASS_GRP_MAP(j)              (QOS_VPU0_SEC_RD + 0x0u + (j) * 8u)
#define QOS_VPU0_SEC_RD_CBASS_MAP(i)                  (QOS_VPU0_SEC_RD + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_0_SEC_M_VBUSM_W_ASYNC_SLV_LINKGRP_0_GRP_MAP1-MAP2 (offset - 1000h)*/
/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_0_SEC_M_VBUSM_W_ASYNC_MAP0 (offset - 1100h)*/
#define QOS_VPU0_SEC_WR                               (0x45dc1000u)
#define QOS_VPU0_SEC_WR_NUM_J_CH                      (2u)
#define QOS_VPU0_SEC_WR_NUM_I_CH                      (1u)
#define QOS_VPU0_SEC_WR_CBASS_GRP_MAP(j)              (QOS_VPU0_SEC_WR + 0x0u + (j) * 8u)
#define QOS_VPU0_SEC_WR_CBASS_MAP(i)                  (QOS_VPU0_SEC_WR + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IVPAC_TOP_MAIN_0_DATA_MST_0_MAP0-MAP31 (offset - 1500h)*/
#define QOS_VPAC0_DATA0                               (0x45dc1500u)
#define QOS_VPAC0_DATA0_NUM_I_CH                      (32u)
#define QOS_VPAC0_DATA0_CBASS_MAP(i)                  (QOS_VPAC0_DATA0 + (i) * 4u)

/*CBASS_AC_NONSAFE_IVPAC_TOP_MAIN_0_DATA_MST_1_MAP0-MAP63 (offset - 1900h)*/
#define QOS_VPAC0_DATA1                               (0x45dc1900u)
#define QOS_VPAC0_DATA1_NUM_I_CH                      (64u)
#define QOS_VPAC0_DATA1_CBASS_MAP(i)                  (QOS_VPAC0_DATA1 + (i) * 4u)

/*CBASS_AC_NONSAFE_IVPAC_TOP_MAIN_0_LDC0_M_MST_SLV_LINKGRP_1_GRP_MAP1-MAP2 (offset - 1C00h)*/
/*CBASS_AC_NONSAFE_IVPAC_TOP_MAIN_0_LDC0_M_MST_MAP0- MAP2 (offset - 1D00h)*/
#define QOS_VPAC0_LDC0                                (0x45dc1c00u)
#define QOS_VPAC0_LDC0_NUM_J_CH                       (2u)
#define QOS_VPAC0_LDC0_NUM_I_CH                       (3u)
#define QOS_VPAC0_LDC0_CBASS_GRP_MAP(j)               (QOS_VPAC0_LDC0 + 0x0u + (j) * 8u)
#define QOS_VPAC0_LDC0_CBASS_MAP(i)                   (QOS_VPAC0_LDC0 + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IK3_DSS_MAIN_0_DSS_INST0_VBUSM_DMA_SLV_LINKGRP_1_GRP_MAP1-MAP2 (offset - 2000h)*/
/*CBASS_AC_NONSAFE_IK3_DSS_MAIN_0_DSS_INST0_VBUSM_DMA_MAP0-MAP9 (offset - 2100h)*/
#define QOS_DSS0_DMA                                  (0x45dc2000u)
#define QOS_DSS0_DMA_NUM_J_CH                         (2u)
#define QOS_DSS0_DMA_NUM_I_CH                         (10u)
#define QOS_DSS0_DMA_CBASS_GRP_MAP(j)                 (QOS_DSS0_DMA + 0x0u + (j) * 8u)
#define QOS_DSS0_DMA_CBASS_MAP(i)                     (QOS_DSS0_DMA + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IK3_DSS_MAIN_0_DSS_INST0_VBUSM_FBDC_SLV_LINKGRP_1_GRP_MAP1-MAP2 (offset - 2400h)*/
/*CBASS_AC_NONSAFE_IK3_DSS_MAIN_0_DSS_INST0_VBUSM_FBDC_MAP0-MAP9 (offset - 2500h)*/
#define QOS_DSS0_FBDC                                 (0x45dc2400u)
#define QOS_DSS0_FBDC_NUM_J_CH                        (2u)
#define QOS_DSS0_FBDC_NUM_I_CH                        (10u)
#define QOS_DSS0_FBDC_CBASS_GRP_MAP(j)                (QOS_DSS0_FBDC + 0x0u + (j) * 8u)
#define QOS_DSS0_FBDC_CBASS_MAP(i)                    (QOS_DSS0_FBDC + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IVPAC_TOP_MAIN_1_LDC0_M_MST_SLV_LINKGRP_1_GRP_MAP1-MAP2 (offset - 2800h)*/
/*CBASS_AC_NONSAFE_IVPAC_TOP_MAIN_1_LDC0_M_MST_MAP0-MAP31 (offset - 2900h)*/
#define QOS_VPAC1_LDC0                                (0x45dc2800u)
#define QOS_VPAC1_LDC0_NUM_J_CH                       (2u)
#define QOS_VPAC1_LDC0_NUM_I_CH                       (32u)
#define QOS_VPAC1_LDC0_CBASS_GRP_MAP(j)               (QOS_VPAC1_LDC0 + 0x0u + (j) * 8u)
#define QOS_VPAC1_LDC0_CBASS_MAP(i)                   (QOS_VPAC1_LDC0 + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IVPAC_TOP_MAIN_1_DATA_MST_1_MAP0-MAP63 (offset - 3100h)*/
#define QOS_VPAC1_DATA1                               (0x45dc3100u)
#define QOS_VPAC1_DATA1_NUM_I_CH                      (64u)
#define QOS_VPAC1_DATA1_CBASS_MAP(i)                  (QOS_VPAC1_DATA1 + (i) * 4u)

/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_0_PRI_M_VBUSM_R_ASYNC_SLV_LINKGRP_0_GRP_MAP1-MAP2 (offset - 3400h)*/
/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_0_PRI_M_VBUSM_R_ASYNC_MAP0-MAP4 (offset - 3500h)*/
#define QOS_VPU0_PRI_RD                               (0x45dc3400u)
#define QOS_VPU0_PRI_RD_NUM_J_CH                      (2u)
#define QOS_VPU0_PRI_RD_NUM_I_CH                      (5u)
#define QOS_VPU0_PRI_RD_CBASS_GRP_MAP(j)              (QOS_VPU0_PRI_RD + 0x0u + (j) * 8u)
#define QOS_VPU0_PRI_RD_CBASS_MAP(i)                  (QOS_VPU0_PRI_RD + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_0_PRI_M_VBUSM_W_ASYNC_SLV_LINKGRP_0_GRP_MAP1-MAP2 (offset - 3800h)*/
/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_0_PRI_M_VBUSM_W_ASYNC_MAP0-MAP4 (offset - 3900h)*/
#define QOS_VPU0_PRI_WR                               (0x45dc3800U)
#define QOS_VPU0_PRI_WR_NUM_J_CH                      (2U)
#define QOS_VPU0_PRI_WR_NUM_I_CH                      (5U)
#define QOS_VPU0_PRI_WR_CBASS_GRP_MAP(j)              (QOS_VPU0_PRI_WR + 0x0u + (j) * 8u)
#define QOS_VPU0_PRI_WR_CBASS_MAP(i)                  (QOS_VPU0_PRI_WR + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_1_SEC_M_VBUSM_R_ASYNC_SLV_LINKGRP_0_GRP_MAP1-MAP2 (offset - 3C00h)*/
/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_1_SEC_M_VBUSM_R_ASYNC_MAP0 (offset - 3D00h)*/
#define QOS_VPU1_SEC_RD                               (0x45dc3c00u)
#define QOS_VPU1_SEC_RD_NUM_J_CH                      (2u)
#define QOS_VPU1_SEC_RD_NUM_I_CH                      (1u)
#define QOS_VPU1_SEC_RD_CBASS_GRP_MAP(j)              (QOS_VPU1_SEC_RD + 0x0u + (j) * 8u)
#define QOS_VPU1_SEC_RD_CBASS_MAP(i)                  (QOS_VPU1_SEC_RD + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_1_SEC_M_VBUSM_W_ASYNC_SLV_LINKGRP_0_GRP_MAP1-MAP2 (offset - 4000h)*/
/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_1_SEC_M_VBUSM_W_ASYNC_MAP0 (offset - 4100h)*/
#define QOS_VPU1_SEC_WR                               (0x45dc4000u)
#define QOS_VPU1_SEC_WR_NUM_J_CH                      (2u)
#define QOS_VPU1_SEC_WR_NUM_I_CH                      (1u)
#define QOS_VPU1_SEC_WR_CBASS_GRP_MAP(j)              (QOS_VPU1_SEC_WR + 0x0u + (j) * 8u)
#define QOS_VPU1_SEC_WR_CBASS_MAP(i)                  (QOS_VPU1_SEC_WR + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_1_PRI_M_VBUSM_R_ASYNC_SLV_LINKGRP_0_GRP_MAP1-MAP2 (offset - 4400h)*/
/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_1_PRI_M_VBUSM_R_ASYNC_MAP0-MAP4 (offset - 4500h)*/
#define QOS_VPU1_PRI_RD                               (0x45dc4400u)
#define QOS_VPU1_PRI_RD_NUM_J_CH                      (2u)
#define QOS_VPU1_PRI_RD_NUM_I_CH                      (5u)
#define QOS_VPU1_PRI_RD_CBASS_GRP_MAP(j)              (QOS_VPU1_PRI_RD + 0x0u + (j) * 8u)
#define QOS_VPU1_PRI_RD_CBASS_MAP(i)                  (QOS_VPU1_PRI_RD + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_1_PRI_M_VBUSM_W_ASYNC_SLV_LINKGRP_0_GRP_MAP1-MAP2 (offset - 4800h)*/
/*CBASS_AC_NONSAFE_IK3_VPU_WAVE521CL_MAIN_1_PRI_M_VBUSM_W_ASYNC_MAP0-MAP4 (offset - 4900h)*/
#define QOS_VPU1_PRI_WR                               (0x45dc4800u)
#define QOS_VPU1_PRI_WR_NUM_J_CH                      (2u)
#define QOS_VPU1_PRI_WR_NUM_I_CH                      (5u)
#define QOS_VPU1_PRI_WR_CBASS_GRP_MAP(j)              (QOS_VPU1_PRI_WR + 0x0u + (j) * 8u)
#define QOS_VPU1_PRI_WR_CBASS_MAP(i)                  (QOS_VPU1_PRI_WR + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IGPU_BXS464_WRAP_MAIN_0_M_VBUSM_R_SYNC_SLV_LINKGRP_0_GRP_MAP1-MAP2 (offset - 5000h)*/
/*CBASS_AC_NONSAFE_IGPU_BXS464_WRAP_MAIN_0_M_VBUSM_R_SYNC_MAP0-MAP159 (offset - 5100h)*/
#define QOS_GPU0_M0_RD                                (0x45dc5000u)
#define QOS_GPU0_M0_RD_NUM_J_CH                       (2u)
#define QOS_GPU0_M0_RD_NUM_I_CH                       (160u)
#define QOS_GPU0_M0_RD_CBASS_GRP_MAP(j)               (QOS_GPU0_M0_RD + 0x0u + (j) * 8u)
#define QOS_GPU0_M0_RD_CBASS_MAP(i)                   (QOS_GPU0_M0_RD + 0x100u + (i) * 4u)

/*CBASS_AC_NONSAFE_IGPU_BXS464_WRAP_MAIN_0_M_VBUSM_W_SYNC_SLV_LINKGRP_0_GRP_MAP1-MAP2 (offset - 5800h)*/
/*CBASS_AC_NONSAFE_IGPU_BXS464_WRAP_MAIN_0_M_VBUSM_W_SYNC_MAP0-MAP159 (offset - 5900h)*/
#define QOS_GPU0_M0_WR                                (0x45dc5800u)
#define QOS_GPU0_M0_WR_NUM_J_CH                       (2u)
#define QOS_GPU0_M0_WR_NUM_I_CH                       (160u)
#define QOS_GPU0_M0_WR_CBASS_GRP_MAP(j)               (QOS_GPU0_M0_WR + 0x0u + (j) * 8u)
#define QOS_GPU0_M0_WR_CBASS_MAP(i)                   (QOS_GPU0_M0_WR + 0x100u + (i) * 4u)

/**WKUP_CBASS0_QOS_REGISTERS (WKUP DOMAIN - 45D0 0100H)**/
/*CBASS_ISMS_WKUP_0_TIFS_VBUSP_M_MAP0 (offset - 0100h)*/
#define QOS_SMS_TIFS                                  (0x45d00100u)
#define QOS_SMS_TIFS_NUM_I_CH                         (1u)
#define QOS_SMS_TIFS_CBASS_MAP(i)                     (QOS_SMS_TIFS + (i) * 4u)

/*CBASS_ISMS_WKUP_0_HSM_VBUSP_M_MAP0 (offset - 0500h)*/
#define QOS_SMS_HSM                                   (0x45dc1500u)
#define QOS_SMS_HSM_NUM_I_CH                          (1u)
#define QOS_SMS_HSM_CBASS_MAP(i)                      (QOS_SMS_HSM + (i) * 4u)

/**MCU_CBASS0_QOS_REGISTERS (MCU DOMAIN - 45D1 0100H)**/
/*CBASS_IPULSAR_SL_MCU_0_CPU0_RMST_MAP0 (offset - 0100h)*/
#define QOS_CPU0_RMST                                 (0x45d00100u)
#define QOS_CPU0_RMST_NUM_I_CH                        (1u)
#define QOS_CPU0_RMST_CBASS_MAP(i)                    (QOS_CPU0_RMST + (i) * 4u)

/*CBASS_IPULSAR_SL_MCU_0_CPU0_WMST_MAP0 (offset - 0500h)*/
#define QOS_CPU0_WMST                                 (0x45d00100u)
#define QOS_CPU0_WMST_NUM_I_CH                        (1u)
#define QOS_CPU0_WMST_CBASS_MAP(i)                    (QOS_CPU0_WMST + (i) * 4u)

/*CBASS_IPULSAR_SL_MCU_0_CPU0_PMST_MAP0 (offset - 0900h)*/
#define QOS_CPU0_PMST                                 (0x45d00100u)
#define QOS_CPU0_PMST_NUM_I_CH                        (1u)
#define QOS_CPU0_PMST_CBASS_MAP(i)                    (QOS_CPU0_PMST + (i) * 4u)

/*CBASS_IPULSAR_SL_MCU_0_CPU1_RMST_MAP0 (offset - 1100h)*/
#define QOS_CPU1_RMST                                 (0x45d00100u)
#define QOS_CPU1_RMST_NUM_I_CH                        (1u)
#define QOS_CPU1_RMST_CBASS_MAP(i)                    (QOS_CPU1_RMST + (i) * 4u)

/*CBASS_IPULSAR_SL_MCU_0_CPU1_WMST_MAP0 (offset - 1500h)*/
#define QOS_CPU1_WMST                                 (0x45d00100u)
#define QOS_CPU1_WMST_NUM_I_CH                        (1u)
#define QOS_CPU1_WMST_CBASS_MAP(i)                    (QOS_CPU1_WMST + (i) * 4u)

/*CBASS_IPULSAR_SL_MCU_0_CPU1_PMST_MAP0 (offset - 1900h)*/
#define QOS_CPU1_PMST                                 (0x45d00100u)
#define QOS_CPU1_PMST_NUM_I_CH                        (1u)
#define QOS_CPU1_PMST_CBASS_MAP(i)                    (QOS_CPU1_PMST + (i) * 4u)

/*CBASS_ISA3SS_AM62_MCU_0_CTXCACH_EXT_DMA_MAP0 (offset - 3100h)*/
#define QOS_CTXCACH_EXT                               (0x45d00100u)
#define QOS_CTXCACH_EXT_NUM_I_CH                      (1u)
#define QOS_CTXCACH_EXT_CBASS_MAP(i)                  (QOS_CTXCACH_EXT + (i) * 4u)

/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */
typedef struct {
    /* dmpac0_qos */
    uint32_t cbass_QOS_DMPAC0_DATA_CBASS_MAP[QOS_DMPAC0_DATA_NUM_I_CH];         /*offset - 0100h*/
    
    /* vpu0_qos */
    uint64_t cbass_QOS_VPU0_SEC_RD_CBASS_GRP_MAP[QOS_VPU0_SEC_RD_NUM_J_CH];     /*offset - 0C00h*/
    uint32_t cbass_QOS_VPU0_SEC_RD_CBASS_MAP[QOS_VPU0_SEC_RD_NUM_I_CH];         /*offset - 0D00h*/
    
    uint64_t cbass_QOS_VPU0_SEC_WR_CBASS_GRP_MAP[QOS_VPU0_SEC_WR_NUM_J_CH];     /*offset - 1000h*/
    uint32_t cbass_QOS_VPU0_SEC_WR_CBASS_MAP[QOS_VPU0_SEC_WR_NUM_I_CH];         /*offset - 1100h*/
    
    uint64_t cbass_QOS_VPU0_PRI_RD_CBASS_GRP_MAP[QOS_VPU0_PRI_RD_NUM_J_CH];     /*offset - 3400h*/
    uint32_t cbass_QOS_VPU0_PRI_RD_CBASS_MAP[QOS_VPU0_PRI_RD_NUM_I_CH];         /*offset - 3500h*/
    
    uint64_t cbass_QOS_VPU0_PRI_WR_CBASS_GRP_MAP[QOS_VPU0_PRI_WR_NUM_J_CH];     /*offset - 3800h*/
    uint32_t cbass_QOS_VPU0_PRI_WR_CBASS_MAP[QOS_VPU0_PRI_WR_NUM_I_CH];         /*offset - 3900h*/
    
    /* vpu1_qos */
    uint64_t cbass_QOS_VPU1_SEC_RD_CBASS_GRP_MAP[QOS_VPU1_SEC_RD_NUM_J_CH];     /*offset - 3C00h*/
    uint32_t cbass_QOS_VPU1_SEC_RD_CBASS_MAP[QOS_VPU1_SEC_RD_NUM_I_CH];         /*offset - 3D00h*/
    
    uint64_t cbass_QOS_VPU1_SEC_WR_CBASS_GRP_MAP[QOS_VPU1_SEC_WR_NUM_J_CH];     /*offset - 4000h*/
    uint32_t cbass_QOS_VPU1_SEC_WR_CBASS_MAP[QOS_VPU1_SEC_WR_NUM_I_CH];         /*offset - 4100h*/
    
    uint64_t cbass_QOS_VPU1_PRI_RD_CBASS_GRP_MAP[QOS_VPU1_PRI_RD_NUM_J_CH];     /*offset - 4400h*/
    uint32_t cbass_QOS_VPU1_PRI_RD_CBASS_MAP[QOS_VPU1_PRI_RD_NUM_I_CH];         /*offset - 4500h*/
    
    uint64_t cbass_QOS_VPU1_PRI_WR_CBASS_GRP_MAP[QOS_VPU1_PRI_WR_NUM_J_CH];     /*offset - 4800h*/
    uint32_t cbass_QOS_VPU1_PRI_WR_CBASS_MAP[QOS_VPU1_PRI_WR_NUM_I_CH];         /*offset - 4900h*/
    
    /* vpac0_qos */
    uint32_t cbass_QOS_VPAC0_DATA0_CBASS_MAP[QOS_VPAC0_DATA0_NUM_I_CH];         /*offset - 1500h*/
    uint32_t cbass_QOS_VPAC0_DATA1_CBASS_MAP[QOS_VPAC0_DATA1_NUM_I_CH];         /*offset - 1900h*/
    
    uint64_t cbass_QOS_VPAC0_LDC0_CBASS_GRP_MAP[QOS_VPAC0_LDC0_NUM_J_CH];       /*offset - 1C00h*/
    uint32_t cbass_QOS_VPAC0_LDC0_CBASS_MAP[QOS_VPAC0_LDC0_NUM_I_CH];           /*offset - 1D00h*/
    
    /* vpac1_qos */
    uint32_t cbass_QOS_VPAC1_DATA1_CBASS_MAP[QOS_VPAC1_DATA1_NUM_I_CH];         /*offset - 3100h*/
    
    uint64_t cbass_QOS_VPAC1_LDC0_CBASS_GRP_MAP[QOS_VPAC1_LDC0_NUM_J_CH];       /*offset - 2800h*/
    uint32_t cbass_QOS_VPAC1_LDC0_CBASS_MAP[QOS_VPAC1_LDC0_NUM_I_CH];           /*offset - 2900h*/
    
    /* dss0_qos */
    uint64_t cbass_QOS_DSS0_DMA_CBASS_GRP_MAP[QOS_DSS0_DMA_NUM_J_CH];           /*offset - 2000h*/
    uint32_t cbass_QOS_DSS0_DMA_CBASS_MAP[QOS_DSS0_DMA_NUM_I_CH];               /*offset - 2100h*/
    
    uint64_t cbass_QOS_DSS0_FBDC_CBASS_GRP_MAP[QOS_DSS0_FBDC_NUM_J_CH];         /*offset - 2400h*/
    uint32_t QOS_QOS_DSS0_FBDC_CBASS_MAP[QOS_DSS0_FBDC_NUM_I_CH];               /*offset - 2500h*/
    
    /* gpu0_qos */
    uint64_t cbass_QOS_GPU0_M0_RD_CBASS_GRP_MAP[QOS_GPU0_M0_RD_NUM_J_CH];       /*offset - 5000h*/
    uint32_t cbass_QOS_GPU0_M0_RD_CBASS_MAP[QOS_GPU0_M0_RD_NUM_I_CH];           /*offset - 5100h*/
    
    uint64_t cbass_QOS_GPU0_M0_WR_CBASS_GRP_MAP[QOS_GPU0_M0_WR_NUM_J_CH];       /*offset - 5800h*/
    uint32_t cbass_QOS_GPU0_M0_WR_CBASS_MAP[QOS_GPU0_M0_WR_NUM_I_CH];           /*offset - 5900h*/
} CBASS_MainDomain_regs_t; 

typedef struct {
    /* WKUP_CBASS0_QOS_REGISTERS */
    uint32_t cbass_QOS_SMS_TIFS_CBASS_MAP[QOS_SMS_TIFS_NUM_I_CH];               /*offset - 1500h*/
    uint32_t cbass_QOS_SMS_HSM_CBASS_MAP[QOS_SMS_HSM_NUM_I_CH];                 /*offset - 1500h*/
    
    /* MCU_CBASS0_QOS_REGISTERS */
    uint32_t cbass_QOS_CPU0_RMST_CBASS_MAP[QOS_CPU0_RMST_NUM_I_CH];             /*offset - 1500h*/
    uint32_t cbass_QOS_CPU0_WMST_CBASS_MAP[QOS_CPU0_WMST_NUM_I_CH];             /*offset - 1500h*/
    uint32_t cbass_QOS_CPU0_PMST_CBASS_MAP[QOS_CPU0_PMST_NUM_I_CH];             /*offset - 1500h*/
    uint32_t cbass_QOS_CPU1_RMST_CBASS_MAP[QOS_CPU1_RMST_NUM_I_CH];             /*offset - 1500h*/
    uint32_t cbass_QOS_CPU1_WMST_CBASS_MAP[QOS_CPU1_WMST_NUM_I_CH];             /*offset - 1500h*/
    uint32_t cbass_QOS_CPU1_PMST_CBASS_MAP[QOS_CPU1_PMST_NUM_I_CH];             /*offset - 1500h*/
    uint32_t cbass_QOS_CTXCACH_EXT_CBASS_MAP[QOS_CTXCACH_EXT_NUM_I_CH];         /*offset - 1500h*/
} CBASS_McuWkupDomain_regs_t; 

 typedef struct {
    uint32_t cbass_NAVSS0_NBSS_NB0_CFG_NB_THREADMAP;
    uint32_t cbass_NAVSS0_NBSS_NB1_CFG_NB_THREADMAP;
    CBASS_MainDomain_regs_t      MainDomain;
    CBASS_McuWkupDomain_regs_t   McuWkupDoamin;
} CBASS_critical_regs_t;

typedef union {
    uint32_t addr;
    uint32_t *ptr;
} ptrCastUnionU32_t;

typedef union {
    uint64_t addr;
    uint64_t *ptr;
} ptrCastUnionU64_t;
/* ===========================================================================
*
* Private functions
*
* ========================================================================= */

static void CBASS_safety_readStaticRegs(CBASS_critical_regs_t* pdata);

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */
#if (CBASS_PROFILING_EBABLE==STD_ON)
static uint64_t Cbass_TimeStamp_all_end=0u;
static uint64_t Cbass_TimeStamp_all_diff=0u;
static uint64_t Cbass_TimeStamp_all_diff_min=0u;
static uint64_t Cbass_TimeStamp_all_diff_max=0u;
static uint64_t Cbass_TimeStamp_all_start=0u;
static uint32_t Cbass_diff_count=0u;
#endif
static CBASS_critical_regs_t gCBASS_regs_content;
static CBASS_critical_regs_t tempCBASS_regs_content;

/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

/*!
 * \brief   Read CBASS HW register config function
 *
 * \param   pdata [IN]    pointer to HW reg storage 
 *
 * \retval  None 
 */
static void CBASS_safety_readStaticRegs(CBASS_critical_regs_t* pdata)
{
  /* DD-ID: {B88C4092-B064-4d4b-B169-326BDA02FAC0}*/
    #if (CBASS_PROFILING_EBABLE==STD_ON)
    Cbass_TimeStamp_all_start = TimerP_getTimeInUsecs();
    #endif
    ptrCastUnionU32_t qosU32Data;
    ptrCastUnionU64_t qosU64Data;

    /* Read safety critical registers for CBASSSS */
    
    /* CBASS navss_nb readback*/
    pdata->cbass_NAVSS0_NBSS_NB0_CFG_NB_THREADMAP= *( (uint32_t *)(NAVSS0_NBSS_NB0_CFG_NB_THREADMAP) );
    pdata->cbass_NAVSS0_NBSS_NB1_CFG_NB_THREADMAP= *( (uint32_t *)(NAVSS0_NBSS_NB0_CFG_NB_THREADMAP) );

    /* dmpac0_qos */
    qosU32Data.addr = QOS_DMPAC0_DATA_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_DMPAC0_DATA_CBASS_MAP[0u], (uint32_t *)qosU32Data.ptr,
           ((QOS_DMPAC0_DATA_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_DMPAC0_DATA_CBASS_MAP[0u] )));
    
    /* vpUu0_qos */
    qosU64Data.addr = QOS_VPU0_SEC_RD_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_VPU0_SEC_RD_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_VPU0_SEC_RD_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU0_SEC_RD_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_VPU0_SEC_RD_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPU0_SEC_RD_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
          ((QOS_VPU0_SEC_RD_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU0_SEC_RD_CBASS_MAP[0u] )));

    qosU64Data.addr = QOS_VPU0_SEC_WR_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_VPU0_SEC_WR_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_VPU0_SEC_WR_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU0_SEC_WR_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_VPU0_SEC_WR_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPU0_SEC_WR_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_VPU0_SEC_WR_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU0_SEC_WR_CBASS_MAP[0u] )));

    qosU64Data.addr = QOS_VPU0_PRI_RD_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_VPU0_PRI_RD_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_VPU0_PRI_RD_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU0_PRI_RD_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_VPU0_PRI_RD_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPU0_PRI_RD_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
          ((QOS_VPU0_PRI_RD_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU0_PRI_RD_CBASS_MAP[0u] )));

    qosU64Data.addr = QOS_VPU0_PRI_WR_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_VPU0_PRI_WR_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_VPU0_PRI_WR_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU0_PRI_WR_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_VPU0_PRI_WR_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPU0_PRI_WR_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_VPU0_PRI_WR_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU0_PRI_WR_CBASS_MAP[0u] )));
    
    /* vpu1_qos */
    qosU64Data.addr = QOS_VPU1_SEC_RD_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_VPU1_SEC_RD_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_VPU1_SEC_RD_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU1_SEC_RD_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_VPU1_SEC_RD_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPU1_SEC_RD_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
          ((QOS_VPU1_SEC_RD_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU1_SEC_RD_CBASS_MAP[0u] )));

    qosU64Data.addr = QOS_VPU1_SEC_WR_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_VPU1_SEC_WR_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_VPU1_SEC_WR_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU1_SEC_WR_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_VPU1_SEC_WR_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPU1_SEC_WR_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_VPU1_SEC_WR_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU1_SEC_WR_CBASS_MAP[0u] )));

    qosU64Data.addr = QOS_VPU1_PRI_RD_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_VPU1_PRI_RD_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_VPU1_PRI_RD_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU1_PRI_RD_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_VPU1_PRI_RD_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPU1_PRI_RD_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
          ((QOS_VPU1_PRI_RD_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU1_PRI_RD_CBASS_MAP[0u] )));

    qosU64Data.addr = QOS_VPU1_PRI_WR_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_VPU1_PRI_WR_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_VPU1_PRI_WR_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU1_PRI_WR_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_VPU1_PRI_WR_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPU1_PRI_WR_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_VPU1_PRI_WR_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPU1_PRI_WR_CBASS_MAP[0u] )));
    
    /* vpac0_qos */
    qosU32Data.addr = QOS_VPAC0_DATA0_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPAC0_DATA0_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_VPAC0_DATA0_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPAC0_DATA0_CBASS_MAP[0u] )));

    qosU32Data.addr = QOS_VPAC0_DATA1_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPAC0_DATA1_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_VPAC0_DATA1_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPAC0_DATA1_CBASS_MAP[0u] )));

    qosU64Data.addr = QOS_VPAC0_LDC0_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_VPAC0_LDC0_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_VPAC0_LDC0_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPAC0_LDC0_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_VPAC0_LDC0_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPAC0_LDC0_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_VPAC0_LDC0_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPAC0_LDC0_CBASS_MAP[0u] )));
    
    /* vpac1_qos */
    qosU32Data.addr = QOS_VPAC1_DATA1_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPAC1_DATA1_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_VPAC1_DATA1_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPAC1_DATA1_CBASS_MAP[0u] )));

    qosU64Data.addr = QOS_VPAC1_LDC0_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_VPAC1_LDC0_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_VPAC1_LDC0_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPAC1_LDC0_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_VPAC1_LDC0_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_VPAC1_LDC0_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_VPAC1_LDC0_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_VPAC1_LDC0_CBASS_MAP[0u] )));
    
    /* dss0_qos */
    qosU64Data.addr = QOS_DSS0_DMA_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_DSS0_DMA_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_DSS0_DMA_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_DSS0_DMA_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_DSS0_DMA_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_DSS0_DMA_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_DSS0_DMA_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_DSS0_DMA_CBASS_MAP[0u] )));

    qosU64Data.addr = QOS_DSS0_FBDC_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_DSS0_FBDC_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_DSS0_FBDC_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_DSS0_FBDC_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_DSS0_FBDC_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.QOS_QOS_DSS0_FBDC_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_DSS0_FBDC_NUM_I_CH) * sizeof( pdata->MainDomain.QOS_QOS_DSS0_FBDC_CBASS_MAP[0u] )));
    
    /* gpu0_qos */
    qosU64Data.addr = QOS_GPU0_M0_RD_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_GPU0_M0_RD_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_GPU0_M0_RD_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_GPU0_M0_RD_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_GPU0_M0_RD_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_GPU0_M0_RD_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_GPU0_M0_RD_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_GPU0_M0_RD_CBASS_MAP[0u] )));

    qosU64Data.addr = QOS_GPU0_M0_WR_CBASS_GRP_MAP(0u);
    (void)memcpy((uint64_t *)&pdata->MainDomain.cbass_QOS_GPU0_M0_WR_CBASS_GRP_MAP[0u],(uint64_t*)qosU64Data.ptr,
           ((QOS_GPU0_M0_WR_NUM_J_CH) * sizeof( pdata->MainDomain.cbass_QOS_GPU0_M0_WR_CBASS_GRP_MAP[0u] )));

    qosU32Data.addr = QOS_GPU0_M0_WR_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->MainDomain.cbass_QOS_GPU0_M0_WR_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_GPU0_M0_WR_NUM_I_CH) * sizeof( pdata->MainDomain.cbass_QOS_GPU0_M0_WR_CBASS_MAP[0u] )));
    
    /* vpac0_qos */
    qosU32Data.addr = QOS_SMS_TIFS_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->McuWkupDoamin.cbass_QOS_SMS_TIFS_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_SMS_TIFS_NUM_I_CH) * sizeof( pdata->McuWkupDoamin.cbass_QOS_SMS_TIFS_CBASS_MAP[0u] )));

    qosU32Data.addr = QOS_SMS_HSM_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->McuWkupDoamin.cbass_QOS_SMS_HSM_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_SMS_HSM_NUM_I_CH) * sizeof( pdata->McuWkupDoamin.cbass_QOS_SMS_HSM_CBASS_MAP[0u] )));
    
    /* vpac0_qos */
    qosU32Data.addr = QOS_CPU0_RMST_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->McuWkupDoamin.cbass_QOS_CPU0_RMST_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_CPU0_RMST_NUM_I_CH) * sizeof( pdata->McuWkupDoamin.cbass_QOS_CPU0_RMST_CBASS_MAP[0u] )));

    qosU32Data.addr = QOS_CPU0_WMST_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->McuWkupDoamin.cbass_QOS_CPU0_WMST_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_CPU0_WMST_NUM_I_CH) * sizeof( pdata->McuWkupDoamin.cbass_QOS_CPU0_WMST_CBASS_MAP[0u] )));

    qosU32Data.addr = QOS_CPU0_PMST_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->McuWkupDoamin.cbass_QOS_CPU0_PMST_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_CPU0_PMST_NUM_I_CH) * sizeof( pdata->McuWkupDoamin.cbass_QOS_CPU0_PMST_CBASS_MAP[0u] )));

    qosU32Data.addr = QOS_CPU1_RMST_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->McuWkupDoamin.cbass_QOS_CPU1_RMST_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_CPU1_RMST_NUM_I_CH) * sizeof( pdata->McuWkupDoamin.cbass_QOS_CPU1_RMST_CBASS_MAP[0u] )));

    qosU32Data.addr = QOS_CPU1_WMST_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->McuWkupDoamin.cbass_QOS_CPU1_WMST_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_CPU1_WMST_NUM_I_CH) * sizeof( pdata->McuWkupDoamin.cbass_QOS_CPU1_WMST_CBASS_MAP[0u] )));

    qosU32Data.addr = QOS_CPU1_PMST_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->McuWkupDoamin.cbass_QOS_CPU1_PMST_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_CPU1_PMST_NUM_I_CH) * sizeof( pdata->McuWkupDoamin.cbass_QOS_CPU1_PMST_CBASS_MAP[0u] )));

    qosU32Data.addr = QOS_CTXCACH_EXT_CBASS_MAP(0u);
    (void)memcpy((uint32_t *)&pdata->McuWkupDoamin.cbass_QOS_CTXCACH_EXT_CBASS_MAP[0u],(uint32_t*)qosU32Data.ptr,
           ((QOS_CTXCACH_EXT_NUM_I_CH) * sizeof( pdata->McuWkupDoamin.cbass_QOS_CTXCACH_EXT_CBASS_MAP[0u] )));

    #if (CBASS_PROFILING_EBABLE==STD_ON)
    Cbass_TimeStamp_all_end = TimerP_getTimeInUsecs();
    Cbass_TimeStamp_all_diff = Cbass_TimeStamp_all_end - Cbass_TimeStamp_all_start;
    Cbass_diff_count=(uint32_t)Cbass_TimeStamp_all_diff;
    if((Cbass_TimeStamp_all_diff_min>Cbass_TimeStamp_all_diff)||(Cbass_TimeStamp_all_diff_min==0u))
    {
       Cbass_TimeStamp_all_diff_min=Cbass_TimeStamp_all_diff;
    }
    else if(Cbass_TimeStamp_all_diff_max<Cbass_TimeStamp_all_diff)
    {
       Cbass_TimeStamp_all_diff_max=Cbass_TimeStamp_all_diff;
    }
    else{
    	/* Do nothing */
    }
#if defined (SDL_APP_CBASS_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_MAX,"\n\n CBASS readnacl usec: %d",Cbass_diff_count);
#endif
    #endif
}

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Initialize CBASS safety and Read the first pass CBASS registers 
 * Description: Readback CBASS HW registers after initialization 
 * Return Type : void 
 */

void TASK_CBASS_safety_init(void)
{
  /* DD-ID: {9FE7EE9B-A42E-436d-B09A-5136FE811FC4}*/
    /* Read CBASS Static Registers for future compare */
    CBASS_safety_readStaticRegs(&gCBASS_regs_content);
}

/*
 * Purpose: CBASS safety mainfunction to check registers against first pass values 
 * Description: Will set fault if mismatch 
 * Return Type : void 
 */
void TASK_CBASS_safety_MainFunction(void)
{
  /* DD-ID: {727E3129-12EF-4351-AAA9-0DC3B3C62114}*/
    const uint8_t *tempRegPtrMain = (uint8_t *)&tempCBASS_regs_content.MainDomain;
    const uint8_t *RegPtrMain = (uint8_t *)&gCBASS_regs_content.MainDomain;

    const uint8_t *tempRegPtrMcu = (uint8_t *)&tempCBASS_regs_content.McuWkupDoamin;
    const uint8_t *RegPtrMcu = (uint8_t *)&gCBASS_regs_content.McuWkupDoamin;

    /* Read CBASS Static Registers */
    CBASS_safety_readStaticRegs(&tempCBASS_regs_content);

    /* Check current read of tempCBASS_regs_content matches the intial gCBASS_regs_content */
    if (0x00 != memcmp((const uint8_t*)RegPtrMain, (const uint8_t*)tempRegPtrMain, (sizeof(CBASS_MainDomain_regs_t))))
    {
#if defined (SDL_APP_CBASS_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n\n CBASS_safety_readStaticRegs: Compare failure for CBASS on line no. %d", __LINE__);
#endif
        Fusa_Application_SetCbassSafetyCriticalConfigFailFlag(CBASS_MAIN_REGISTERS_MISMATCH);
    } 
    else if (0x00 != memcmp((const uint8_t*)RegPtrMcu, (const uint8_t*)tempRegPtrMcu, (sizeof(CBASS_McuWkupDomain_regs_t))))
    {
#if defined (SDL_APP_CBASS_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n\n CBASS_safety_readStaticRegs: Compare failure for CBASS on line no. %d", __LINE__);
#endif
        Fusa_Application_SetCbassSafetyCriticalConfigFailFlag(CBASS_MCU_REGISTERS_MISMATCH);
    } 
    else
    {
#if defined (SDL_APP_CBASS_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n\n CBASS_safety_readStaticRegs: PASS for CBASS");
#endif
    }
}

/* Nothing past this point */

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
