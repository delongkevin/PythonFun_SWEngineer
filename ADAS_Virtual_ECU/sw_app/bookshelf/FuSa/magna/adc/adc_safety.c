/** @file adc_safety.c 
 *  @brief  adc safety Application
 * 
 *  ADC Safety Application
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
 * for the ADC module.
 *
 *  \details  ADC Safety module
 */
 
/* ===========================================================================
*
*   Include Files
*
* ========================================================================= */

#include "sdlr_soc_baseaddress.h"
#include <ti/csl/src/ip/adc/V0/V0_1/hw_adc.h>
#include <string.h>
#include "app_log.h"
#include "fusa_application.h"

#include "adc_safety.h"

/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
#define MCU_ADC_CNT	(2U)
#define ADC_STEP_DELAY_REG_CNT	(16u)

/* ===========================================================================
*
* Typedefs
*
* ========================================================================= */

typedef struct adc_step_config_and_delay {
    uint32_t adc_step_config_j;
    uint32_t adc_step_delay_j;
}adc_step_config_and_delay_t;

typedef struct adc_fifo_count_and_threshold_and_dmaRequest {
    uint32_t adc_fifo_count_j;
    uint32_t adc_fifo_threshold_j;
    uint32_t adc_fifo_dmaRequest_j;
}adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_t;

typedef struct ADC_regs {
    uint32_t adc_revision;
    uint8_t  reserved_bytes_1[ADC_IRQ_EOI - ADC_REVISION - sizeof(uint32_t)];
    uint32_t adc_eoi;
    uint32_t adc_status_raw;
    uint32_t adc_status;
    uint32_t adc_enable_set;
    uint32_t adc_enable_clear;
    uint32_t adc_wakeup;    /*uint8_t reserved_bytes_2[ADC_DMAENABLE_SET - ADC_IRQENABLE_CLR - sizeof(uint32_t)]; */
    uint32_t adc_dma_enable_set;
    uint32_t adc_dma_enable_clear;
    uint32_t adc_control;
    uint32_t adc_sequencer_stat;
    uint32_t adc_range;
    uint32_t adc_clk_div;   /*uint8_t reserved_bytes_3[ADC_MISC - ADC_ADCRANGE - sizeof(uint32_t)]; */
    uint32_t adc_misc;
    uint32_t adc_step_enable;
    uint32_t adc_idle_config;   /*uint8_t reserved_bytes_4[ADC_TS_CHARGE_STEPCONFIG - ADC_STEPENABLE - sizeof(uint32_t)]; */
    uint32_t adc_ts_charge_step_config;   /*uint8_t reserved_bytes_5[ADC_TS_CHARGE_DELAY - ADC_IDLECONFIG - sizeof(uint32_t)]; */
    uint32_t adc_ts_charge_delay;   /*uint8_t reserved_bytes_6[ADC_STEPCONFIG(0) - ADC_TS_CHARGE_STEPCONFIG - sizeof(uint32_t)]; */
    adc_step_config_and_delay_t adc_step_config_and_delay_j[16];
    adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_t adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_j[2];
    uint32_t adc_fifo_data_j[100*2];
} ADC_regs_t;

typedef struct ADC_critical_regs {
    uint32_t adc_enable_set;
    uint32_t adc_dma_enable_set;
    uint32_t adc_control;
    uint32_t adc_range;
    uint32_t adc_misc;
    uint32_t adc_step_enable;
    adc_step_config_and_delay_t adc_step_config_and_delay_j[16];
    adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_t adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_j[2];
} ADC_critical_regs_t;


/* ===========================================================================
*
* Private functions
*
* ========================================================================= */

static void adc_safety_readStaticRegs(ADC_critical_regs_t* pdata);

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ===========================================================================
*
*   Private variables
*
* ========================================================================= */

static ADC_critical_regs_t gADC_regs_content[2];
static ADC_critical_regs_t tempADC_regs_content[2];

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
 * \brief   Read ADC HW register config function
 *
 * \param   pdata [IN]    pointer to HW reg storage 
 *
 * \retval  None 
 */
static void adc_safety_readStaticRegs(ADC_critical_regs_t* pdata)
{
  /* DD-ID: {0FA9AB79-B1B3-4565-8F6F-F214D888ADE4}*/
    /* For MCU_ADC0 */
    ADC_regs_t* ptr1 = (ADC_regs_t*) SDL_MCU_ADC0_BASE;
    /* For MCU_ADC1 */
    ADC_regs_t* ptr2 = (ADC_regs_t*) SDL_MCU_ADC1_BASE;

    /* Read safety critical registers for MCU_ADC0 */
    pdata[0].adc_enable_set     = ptr1->adc_enable_set;
    pdata[0].adc_dma_enable_set = ptr1->adc_dma_enable_set;
    pdata[0].adc_control        = ptr1->adc_control;
    pdata[0].adc_range          = ptr1->adc_range;
    pdata[0].adc_misc           = ptr1->adc_misc;
    pdata[0].adc_step_enable    = ptr1->adc_step_enable;
    (void)memcpy((adc_step_config_and_delay_t *)&(pdata[0].adc_step_config_and_delay_j[0]), (adc_step_config_and_delay_t *)&(ptr1->adc_step_config_and_delay_j[0]), (sizeof(adc_step_config_and_delay_t) * ADC_STEP_DELAY_REG_CNT));
    (void)memcpy((adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_t *)&(pdata[0].adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_j[0]), (adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_t *)&(ptr1->adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_j[0]), (sizeof(adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_t) * MCU_ADC_CNT));

    /* Read safety critical registers for MCU_ADC1 */
    pdata[1].adc_enable_set     = ptr2->adc_enable_set;
    pdata[1].adc_dma_enable_set = ptr2->adc_dma_enable_set;
    pdata[1].adc_control        = ptr2->adc_control;
    pdata[1].adc_range          = ptr2->adc_range;
    pdata[1].adc_misc           = ptr2->adc_misc;
    pdata[1].adc_step_enable    = ptr2->adc_step_enable;
    (void)memcpy((adc_step_config_and_delay_t *)&(pdata[1].adc_step_config_and_delay_j[0]), (adc_step_config_and_delay_t *)&(ptr2->adc_step_config_and_delay_j[0]), (sizeof(adc_step_config_and_delay_t) * ADC_STEP_DELAY_REG_CNT));
    (void)memcpy((adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_t *)&(pdata[1].adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_j[0]), (adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_t *)&(ptr2->adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_j[0]), (sizeof(adc_fifo_count_and_thresholdLevel_and_dmaRequestLevel_t) * MCU_ADC_CNT));
}

/* ===========================================================================
*
*   Global functions
*
* ========================================================================= */
/*
 * Purpose: Initialize adc safety and Read the first pass ADC registers 
 * Description: Readback ADC HW registers after initialization 
 * Return Type : void 
 */

void TASK_adc_safety_init(void)
{
  /* DD-ID: {F44FDA9D-71B1-4e8c-9E42-5923739E48D2}*/
    #if ( SDL_APP_ADC_ENABLED == SDL_APP_ON )
    /* Read ADC Static Registers for future compare */
    adc_safety_readStaticRegs(&gADC_regs_content[0]);
    #endif
}

/*
 * Purpose: ADC safety mainfunction to check registers against first pass values 
 * Description: Will set fault if mismatch 
 * Return Type : void 
 */
void TASK_adc_safety_MainFunction(void)
{
  /* DD-ID: {B48F3A28-AC4D-44f3-B4B6-895F4032E178}*/
	const uint8_t *tempRegPtr = (uint8_t *)&tempADC_regs_content;
	const uint8_t *regPtrWKup = (uint8_t *)&gADC_regs_content;

    #if ( SDL_APP_ADC_ENABLED == SDL_APP_ON )
    /* Read ADC Static Registers */
    adc_safety_readStaticRegs(&tempADC_regs_content[0]);

    /* Check current read of tempADC_regs_content matches the intial gADC_regs_content */
    if (0x00 != memcmp((const uint8_t*)regPtrWKup, (const uint8_t*)tempRegPtr, (MCU_ADC_CNT * sizeof(ADC_critical_regs_t))))
    {
        #if defined (SDL_APP_ADC_UART_PRINTS_ENABLED)
        UART_printf("adc_safety_readStaticRegs: Compare failure for ADC on line no. %d \n", __LINE__);
        #endif
        Fusa_Application_SetAdcSafetyCriticalConfigFailFlag();
    } 
    else
    {
        #if defined (SDL_APP_ADC_UART_PRINTS_ENABLED)
        UART_printf("adc_safety_readStaticRegs: PASS for ADC\n");
        #endif
    }
    #endif
}

/* Nothing past this point */

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
