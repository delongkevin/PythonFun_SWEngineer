/**
 * @file MSMC_Safetty.c
 * @brief Implement MSMC FuSa requirement
 *
 * @details This file implement functons that satisfy FuSa requirment for MSMC
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2023.  Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status.  Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author Fengyi Chen (fengyi.chen@magna.com)
 */

/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */

#include "sdlr_soc_baseaddress.h"
#include <string.h>
#include "MSMC_Safety.h"
#include "fusa_application.h"
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
#define MSMC_PID            (0x0U)
#define MSMC_CACHE_CTRL     (0x1000U)
#define MSMC_RT_WAY_SELECT  (0x1010U)
#define MSMC_NRT_WAY_SELECT (0x1018U)
#define MSMC_COHCTRL        (0x2048U)
#define MSMC_SMEDCC         (0x3080U)
#define MSMC_SMESTAT        (0x5000U)
/* Commented -- Can be enabled in Future
* #define MSMC_SMIRSTAT       (0x5008U)
* #define MSMC_SMIRWS         (0x5008U)
* #define MSMC_SMIRC          (0x5010U)
* #define MSMC_SMIESTAT       (0x5018U)
* #define MSMC_SMIEWS         (0x5018U)
*/
#define MSMC_SMIEC          (0x5020U)
#define MSMC_SBNDCOH0       (0x6000U)
/* Commented -- Can be enabled in Future
* #define MSMC_SBNDCOH1       (0x6008U)
* #define MSMC_SBNDCOH2       (0x6010U)
* #define MSMC_SBNDCOH3       (0x6018U)
* #define MSMC_SBNDCOH4       (0x6020U)
* #define MSMC_SBNDCOH5       (0x6028U)
* #define MSMC_SBNDCOH6       (0x6030U)
* #define MSMC_SBNDCOH7       (0x6038U)
* #define MSMC_SBNDCOH8       (0x6040U)
* #define MSMC_SBNDCOH9       (0x6048U)
* #define MSMC_SBNDCOH10      (0x6050U)
* #define MSMC_SBNDCOH11      (0x6058U)
*/
#define MSMC_SBNDCOH12      (0x6060U)
#define MSMC_SBNDDRU        (0x6100U)
#define MSMC_SBNDRESP       (0x6200U)
#define MSMC_DBGTAGCTL      (0x7000U)
#define MSMC_DBGTAGVIEW     (0x7080U)
#define MSMC_NULL_SLV_STAT0 (0xA000U)
#define MSMC_NULL_SLV_STAT1 (0xA008U)
#define MSMC_NULL_SLV_CNT   (0xA018U)


/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */

typedef struct MSMC_regs_struct {
    uint64_t msmc_pid;
    uint8_t reserved_bytes_1[MSMC_CACHE_CTRL - MSMC_PID - sizeof(uint64_t)];
    uint64_t msmc_cache_ctrl;
    uint8_t reserved_bytes_2[MSMC_RT_WAY_SELECT - MSMC_CACHE_CTRL - sizeof(uint64_t)];
    uint64_t msmc_rt_way_select;
    uint64_t msmc_nrt_way_select;
    uint8_t reserved_bytes_3[MSMC_COHCTRL - MSMC_NRT_WAY_SELECT - sizeof(uint64_t)];
    uint64_t msmc_cohctrl;
    uint8_t reserved_bytes_4[MSMC_SMEDCC - MSMC_COHCTRL - sizeof(uint64_t)];
    uint64_t msmc_smedcc;
    uint8_t reserved_bytes_5[MSMC_SMESTAT - MSMC_SMEDCC - sizeof(uint64_t)];
    uint64_t msmc_smestat;
    uint64_t msmc_smirstat;
    uint64_t msmc_smirc;
    uint64_t msmc_smiestat;
    uint64_t msmc_smiec;
    uint8_t reserved_bytes_6[MSMC_SBNDCOH0 - MSMC_SMIEC - sizeof(uint64_t)];
    uint64_t msmc_sbndcoh0;
    uint64_t msmc_sbndcoh1;
    uint64_t msmc_sbndcoh2;
    uint64_t msmc_sbndcoh3;
    uint64_t msmc_sbndcoh4;
    uint64_t msmc_sbndcoh5;
    uint64_t msmc_sbndcoh6;
    uint64_t msmc_sbndcoh7;
    uint64_t msmc_sbndcoh8;
    uint64_t msmc_sbndcoh9;
    uint64_t msmc_sbndcoh10;
    uint64_t msmc_sbndcoh11;
    uint64_t msmc_sbndcoh12;
    uint8_t reserved_bytes_7[MSMC_SBNDDRU - MSMC_SBNDCOH12 - sizeof(uint64_t)];
    uint64_t msmc_sbnddru;
    uint8_t reserved_bytes_8[MSMC_SBNDRESP - MSMC_SBNDDRU - sizeof(uint64_t)];
    uint64_t msmc_sbndresp;
    uint8_t reserved_bytes_9[MSMC_DBGTAGCTL - MSMC_SBNDRESP - sizeof(uint64_t)];
    uint64_t msmc_dbgtagctl;
    uint8_t reserved_bytes_10[MSMC_DBGTAGVIEW - MSMC_DBGTAGCTL - sizeof(uint64_t)];
    uint64_t msmc_dbgtagview;
    uint8_t reserved_bytes_11[MSMC_NULL_SLV_STAT0 - MSMC_DBGTAGVIEW - sizeof(uint64_t)];
    uint64_t msmc_null_slv_stat0;
    uint64_t msmc_null_slv_stat1;
    uint8_t reserved_bytes_12[MSMC_NULL_SLV_CNT - MSMC_NULL_SLV_STAT1 - sizeof(uint64_t)];
    uint64_t msmc_null_slv_cnt;
} MSMC_regs;

/* ===========================================================================
*
* Private functions
*
* ========================================================================= */

static void MSMC_readStaticRegs(uint64_t* arr);


#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */

/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */
static uint64_t MSMC_regs_copy[MSMC_REG_MAX];
#ifdef FUSA_MSMC_DEBUG
static uint64_t debug_MSMC_regs_copy[MSMC_REG_MAX];
#endif
#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

/*!
 * \brief   Read MSMC HW register config function
 *
 * \param   arr [IN]    pointer to HW reg array storage
 *
 * \retval  None
 */
static void MSMC_readStaticRegs(uint64_t* arr)
{
  /* DD-ID: {5CF8F290-4278-4df4-9C57-F5E2E5FB495C}*/
    MSMC_regs* ptr = (MSMC_regs*) SDL_COMPUTE_CLUSTER0_MSMC_CFGS0_BASE;
    for (uint32_t i = (uint32_t)CACHE_CTRL; i < (uint32_t)MSMC_REG_MAX; i++)
    {
        switch((required_regs)i)
        {
        case CACHE_CTRL:
            arr[i] = ptr->msmc_cache_ctrl;
            break;
        case RT_WAY_SELECT:
            arr[i] = ptr->msmc_rt_way_select;
            break;
        case NRT_WAY_SELECT:
            arr[i] = ptr->msmc_nrt_way_select;
            break;
        case COHCTRL:
            arr[i] = ptr->msmc_cohctrl;
            break;
        case SMEDCC:
            arr[i] = ptr->msmc_smedcc;
            break;
        case SMESTAT:
            arr[i] = ptr->msmc_smestat;
            break;
        case SBNDCOH0:
            arr[i] = ptr->msmc_sbndcoh0;
            break;
        case SBNDCOH1:
            arr[i] = ptr->msmc_sbndcoh1;
            break;
        case SBNDCOH2:
            arr[i] = ptr->msmc_sbndcoh2;
            break;
        case SBNDCOH3:
            arr[i] = ptr->msmc_sbndcoh3;
            break;
        case SBNDCOH4:
            arr[i] = ptr->msmc_sbndcoh4;
            break;
        case SBNDCOH5:
            arr[i] = ptr->msmc_sbndcoh5;
            break;
        case SBNDCOH6:
            arr[i] = ptr->msmc_sbndcoh6;
            break;
        case SBNDCOH7:
            arr[i] = ptr->msmc_sbndcoh7;
            break;
        case SBNDCOH8:
            arr[i] = ptr->msmc_sbndcoh8;
            break;
        case SBNDCOH9:
            arr[i] = ptr->msmc_sbndcoh9;
            break;
        case SBNDCOH10:
            arr[i] = ptr->msmc_sbndcoh10;
            break;
        case SBNDCOH11:
            arr[i] = ptr->msmc_sbndcoh11;
            break;
        case SBNDCOH12:
            arr[i] = ptr->msmc_sbndcoh12;
            break;
        case SBNDDRU:
            arr[i] = ptr->msmc_sbnddru;
            break;
        case SBNDRESP:
            arr[i] = ptr->msmc_sbndresp;
            break;
        default:
            /* Do nothing */
            break;
        }
    }
}

/*
 * Purpose: Read the first pass MSMC registers
 * Description: Readback MSMC HW registers after initialization
 * Return Type : void
 */

void Sdl_Application_MSMC_init(void)
{
  /* DD-ID: {3DD1C6F0-98AE-495f-9C5B-7CB6B68D292F}*/
    MSMC_readStaticRegs(MSMC_regs_copy);
}

/*
 * Purpose: Check MSMC registers against first pass values
 * Description: Will set fault if mismatch
 * Return Type : void
 */
void Sdl_Application_MSMC_Safety(void)
{
  /* DD-ID: {138F5D9E-4EFE-4a53-B41D-BF4E20D477AE}*/
    uint64_t regs[MSMC_REG_MAX];
    MSMC_readStaticRegs(regs);

    #ifdef FUSA_MSMC_DEBUG
    MSMC_readStaticRegs(debug_MSMC_regs_copy);
    #endif

    if (0 != memcmp(&regs, &MSMC_regs_copy, sizeof(regs)))
    {
        Sdl_Application_SetMSMCCfgErrorFlag();
    }
    else
    {
        Sdl_Application_ClearMSMCCfgErrorFlag();
    }
}

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
