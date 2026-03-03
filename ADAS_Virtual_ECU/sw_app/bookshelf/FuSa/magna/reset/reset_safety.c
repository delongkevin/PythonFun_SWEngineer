/** @file reset_safety.c 
 *  @brief  reset safety Application
 * 
 *  RESET Safety Application
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Anonymous Author (Anonymous.Author@magna.com)
 */

/**
 * This file contains functions that monitors safety
 * for the RESET module.
 *
 *  \details  RESET Safety module
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */

#include "sdlr_soc_baseaddress.h"
#include <string.h>
#include "app_log.h"
#include "fusa_application.h"

#include "reset_safety.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
#define CTRLMMR_WKUP_POR_STAT_PROXI0_OFFSET     (0x18004U)
/* Commenting this macro - can enabled in futueif needed .
*  #define CTRLMMR_WKUP_POR_STAT_PROXI1_OFFSET     (0x1A004U)
*/

#define CTRLMMR_WKUP_RST_STAT_PROXI0_OFFSET     (0x18178U)
/* Commenting this macro - can enabled in futueif needed .
*  #define CTRLMMR_WKUP_RST_STAT_PROXI1_OFFSET     (0x1A178U)
*/
/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */


typedef struct RESET_regs_type {
    uint32_t register_data;
    uint32_t register_proxy0_offset;
    uint32_t register_proxy1_offset;
} RESET_regs_type_t;

typedef struct RESET_wkup_ctrl_mmr0_critical_regs {
    uint32_t reset_CTRLMMR_WKUP_POR_STAT;
    uint32_t reset_CTRLMMR_WKUP_RST_STAT;
} RESET_wkup_ctrl_mmr0_critical_regs_t;


/* ===========================================================================
*
* Private functions
*
* ========================================================================= */

static void reset_safety_readStaticRegs(RESET_wkup_ctrl_mmr0_critical_regs_t* pdata);

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */

static RESET_wkup_ctrl_mmr0_critical_regs_t gRESET_regs_content;

/* ===========================================================================
*
*   Global variables
*
* ========================================================================= */

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \brief   Read RESET HW register config function
 *
 * \param   pdata [IN]    pointer to HW reg storage 
 *
 * \retval  None 
 */
static void reset_safety_readStaticRegs(RESET_wkup_ctrl_mmr0_critical_regs_t* pdata)
{
  /* DD-ID: {E0A4D489-7114-4fc1-AE2D-BED75FA4ECAB}*/
    uint32_t register_offset;

    /* base address WKUP_CTRL_MMR0 + offset */
    /* Read safety critical registers for RESET */
    register_offset = CTRLMMR_WKUP_POR_STAT_PROXI0_OFFSET;
    pdata->reset_CTRLMMR_WKUP_POR_STAT  = *((uint32_t *)(SDL_WKUP_CTRL_MMR0_CFG0_BASE + register_offset));
    
    register_offset = CTRLMMR_WKUP_RST_STAT_PROXI0_OFFSET;
    pdata->reset_CTRLMMR_WKUP_RST_STAT  = *((uint32_t *)(SDL_WKUP_CTRL_MMR0_CFG0_BASE + register_offset));

}

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Initialize reset safety and Read the first pass RESET registers 
 * Description: Readback RESET HW registers after initialization 
 * Return Type : void 
 */

void TASK_reset_safety_init(void)
{
  /* DD-ID: {0543CD6D-D6EA-4489-9943-AFF24269D003}*/
    #if ( SDL_APP_RESET_ENABLED == SDL_APP_ON )
    /* Read RESET Static Registers for future compare */
    reset_safety_readStaticRegs(&gRESET_regs_content);
    #endif
}

/*
 * Purpose: RESET safety mainfunction to check registers against first pass values 
 * Description: Will set fault if mismatch 
 * Return Type : void 
 */
void TASK_reset_safety_MainFunction(void)
{
  /* DD-ID: {8CAEB7DA-7D6B-41b0-9308-78363DAA4408}*/
    static RESET_wkup_ctrl_mmr0_critical_regs_t tempRESET_regs_content;

    const uint8_t *tempRegPtr = (uint8_t *)&tempRESET_regs_content;
    const uint8_t *regPtr = (uint8_t *)&gRESET_regs_content;

    #if ( SDL_APP_RESET_ENABLED == SDL_APP_ON )
    /* Read RESET Static Registers */
    reset_safety_readStaticRegs(&tempRESET_regs_content);

    /* Check current read of tempRESET_regs_content matches the intial gRESET_regs_content */
    if (0x00 != memcmp((const uint8_t *)regPtr, (const uint8_t *)tempRegPtr, sizeof(RESET_wkup_ctrl_mmr0_critical_regs_t)))
    {
        #if defined (SDL_APP_RESET_UART_PRINTS_ENABLED)
        UART_printf("reset_safety_readStaticRegs: Compare failure for RESET on line no. %d \n", __LINE__);
        #endif
        Fusa_Application_SetResetSafetyCriticalConfigFailFlag();
    } 
    else
    {
        #if defined (SDL_APP_RESET_UART_PRINTS_ENABLED)
        UART_printf("reset_safety_readStaticRegs: PASS for RESET\n");
        #endif
    }
    #endif
}

/* Nothing past this point */

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
