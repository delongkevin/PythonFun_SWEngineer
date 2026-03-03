/** @file vtm.c
 *  @brief  VTM Module
 *
 *  Voltage and Thermal Monitor (VTM) Module
 *
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 *
 *  @author Matt Kloepfer (Matt.Kloepfer@magna.com)
 */


/**
 * This file contains functions that initialize
 * the Voltage and Thermal Monitor (VTM) module of the Software Diagnostics Library.
 *
 *  \details  VTM Safety module - The VTM utilizes onboard temperature sensors
 * to monitor for out-of-range values and will trigger interrupts at the configured
 * thresholds. Interrupts come through the ESM and to this module via the application callback
 * function.
 */
#include <string.h>
#include <ti/osal/osal.h>
#include <ti/drv/sciclient/sciclient.h>
#include <ti/boot/sbl/soc/k3/sbl_soc_cfg.h>

#include <sdl_esm.h>
#include <sdl_ip_vtm.h>
#include <sdl_vtm.h>

#include "fusa_osal_interface_autosar.h"
#include "fusa_application.h"
#include "vtm.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "pmic.h"
#include "bist_core_defs.h"
#include <src/sdl/sdl_pbist.h>

/* SCI Client */
#include <ti/drv/sciclient/sciclient.h>

#include "pbist_utils.h"
#include "pbist_defs.h"



/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/

extern int32_t SDL_ESM_VTM_applicationCallbackFunction(SDL_ESM_Inst esmInstType,
                                         SDL_ESM_IntType esmIntType,
                                         uint32_t grpChannel,
                                         uint32_t index,
                                         uint32_t intSrc,
                                         void *arg);
/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/
#define CSL_PASS                        ( (int32_t) (0))
/*Unused macro: #define UART_PRINTS_ENABLED*/
#define VTM_OVERTEMP_WARNING_THRESHOLD (120000) /* 120degC */
#define VTM_LOWERTEMP_WARNING_THRESHOLD (110000) /* 110degC */

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/*===========================================================================*/
/*                         Global Variables                                  */
/*===========================================================================*/
static volatile uint8_t gVtm_error_status = FUSA_VTM_NO_ERROR;
/*temperature in milli degrees Celsius*/
static int32_t Vtm_CurrTemps[SDL_VTM_INSTANCE_TS_MAX_NUM] = {0};

/*Expected values on static config registers*/
static SDL_VTM_staticRegsTs Vtm_staticRegsTs_Expected;
static SDL_VTM_staticRegsVd Vtm_staticRegsVd_Expected;

/*high/low temperature flags */
volatile static uint8_t gt_HighTempInterrupt_Flag = (uint8_t)FALSE;
volatile static uint8_t gt_LowTempInterrupt_Flag = (uint8_t)FALSE;

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

static int32_t deactivateTrigger(SDL_ESM_Inst esmInstType,
                                 SDL_ESM_IntType esmIntType,
                                 uint32_t intEsmSrc);

static void SDL_VTM_IntrruptGtThr1(void);
static void SDL_VTM_IntrruptLtThr0(void);
static void vtm_Periodic_ConfigRegCheck(void);

static void vtm_CheckForOvertemperatureWarning(void);
static void vtm_CheckForCoolingtemperatureWarning(void);


#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

/* Callback to handle VTM reactions. Is called in
interrupt context by ESM after ESM receives interrupt */
int32_t SDL_ESM_VTM_applicationCallbackFunction(SDL_ESM_Inst esmInstType,
                                         SDL_ESM_IntType esmIntType,
                                         uint32_t grpChannel,
                                         uint32_t index,
                                         uint32_t intSrc,
                                         void *arg)
{
    /* DD-ID:{45804F6B-C76F-42c7-AE70-C4B6801A6997}*/

    /* DD-ID: {FC2FB758-5E64-43c3-BA85-AAC0BB6F4C04}*/
    int32_t retval = SDL_EFAIL;
    SDL_VTM_Stat_read_ctrl readCtrl;
    SDL_VTM_adc_code adc_code;
    SDL_VTM_Stat_val statusVal;

   (void)grpChannel;
   (void)index;
   (void)arg;
    /* Get current temperature value */
    readCtrl = SDL_VTM_TS_READ_DATA_OUT_VAL;
    (void)SDL_VTM_getSensorStatus(SDL_VTM_INSTANCE_TS_0, &readCtrl, &statusVal);
    adc_code = statusVal.data_out; /* data_out has the current temperature */
    (void)SDL_VTM_tsConvADCToTemp(adc_code, SDL_VTM_INSTANCE_TS_0, &(Vtm_CurrTemps[0u]));
#ifdef UART_PRINTS_ENABLED
    APP_log(APP_LOG_ERR,"\n  VTM Callback: ESM Call back function called : instType 0x%x, intType 0x%x, " \
                "grpChannel 0x%x, index 0x%x, intSrc 0x%x, Temp = %d mDeg\n",
				esmInstType, esmIntType, grpChannel, index, intSrc, Vtm_CurrTemps[0]);
#endif	/*UART_PRINTS_ENABLED*/

    /* Any additional customer-specific actions to address ESM event
     * can be added here */
    (void)deactivateTrigger(esmInstType, esmIntType, intSrc);

    return retval;
}

/* Initialize the vtm module in the SDL */
void TASK_vtm_app_init(void)
{
  /* DD-ID: {48695C69-0C49-4fa4-88E2-C4F391D523C7}*/

    int32_t sdlResult_Vd = SDL_PASS;
    int32_t sdlResult_Ts = SDL_PASS;
    SDL_VTM_tsThrVal thr_val;
    SDL_VTM_configTs cfgTs;
    SDL_VTM_adc_code adc_code_gt_thr1;
    SDL_VTM_adc_code adc_code_gt_thr0;
   
    /*high/low temperature Thresholds */
    const int32_t gt_thr1_val = VTM_OVERTEMP_WARNING_THRESHOLD;
    const int32_t gt_thr0_val = VTM_LOWERTEMP_WARNING_THRESHOLD;

    /*int32_t gt_thr1_val = VTM_OVERTEMP_WARNING_THRESHOLD;*/

    /* Required to call this to initialize the number of sensors in the SoC
    We are passing in bad values on purpose. The sensors are initialized before arg checks */
    (void)SDL_VTM_tsConvADCToTemp((SDL_VTM_adc_code)-1, SDL_VTM_INSTANCE_TS_0, NULL);

    /* convert the temp thresholds to adcs */
    (void)SDL_VTM_tsConvTempToAdc(gt_thr1_val, SDL_VTM_INSTANCE_TS_0, &adc_code_gt_thr1);
    (void)SDL_VTM_tsConvTempToAdc(gt_thr0_val, SDL_VTM_INSTANCE_TS_0, &adc_code_gt_thr0);

    thr_val.thrValidMap = SDL_VTM_GT_TH1_VALID | \
                          SDL_VTM_GT_TH2_VALID | \
                          SDL_VTM_LT_TH0_VALID;

    /* Set the temperature thresholds for VTM interrupts */
    thr_val.gtTh2En     = (bool)FALSE; /* disable high temp threshold 2 (maximum temp) */
    thr_val.gtTh2       = (SDL_VTM_adc_code)0;
    thr_val.gtTh1En     = (bool) TRUE;  /* enable high temp threshold 1 (warning temp) */
    thr_val.gtTh1       = adc_code_gt_thr1;
    thr_val.ltTh0En     = (bool)TRUE; /* enable "low" temp threshold - used to trigger a recovery from a high temp */
    thr_val.ltTh0       = adc_code_gt_thr0;
    cfgTs.thr_val       = thr_val;
    cfgTs.configTsCtrl = SDL_VTM_VD_CONFIG_CTRL_SET_THR |
                         SDL_VTM_VD_CONFIG_CTRL_SET_CTL;

    cfgTs.tsCtrl_cfg.valid_map = SDL_VTM_TS_CTRL_MODE_VALID |
                                 SDL_VTM_TS_CTRL_RESET_CTRL_VALID;
    cfgTs.tsCtrl_cfg.maxt_outrg_alert_en = 0;
    cfgTs.tsCtrl_cfg.tsReset = SDL_VTM_TS_CTRL_SENSOR_NORM_OP;
    cfgTs.tsCtrl_cfg.adc_stat = 0;
    cfgTs.tsCtrl_cfg.mode = SDL_VTM_TS_CTRL_CONTINUOUS_MODE;

    /* Set the temperature thresholds for all temperature sensors */
    (void)SDL_VTM_initTs(SDL_VTM_INSTANCE_TS_0 , &cfgTs);
    (void)SDL_VTM_initTs(SDL_VTM_INSTANCE_TS_1 , &cfgTs);
    (void)SDL_VTM_initTs(SDL_VTM_INSTANCE_TS_2 , &cfgTs);
    (void)SDL_VTM_initTs(SDL_VTM_INSTANCE_TS_3 , &cfgTs);
    (void)SDL_VTM_initTs(SDL_VTM_INSTANCE_TS_4 , &cfgTs);

    /* Software readback of written configuration */
    sdlResult_Ts = SDL_VTM_verifyConfigTs(SDL_VTM_INSTANCE_TS_0, &cfgTs);
    if(sdlResult_Ts == SDL_PASS)
    {
        sdlResult_Ts = SDL_VTM_getStaticRegistersTs(SDL_VTM_INSTANCE_TS_0, (SDL_VTM_staticRegsTs*)&Vtm_staticRegsTs_Expected);
    }
#ifdef UART_PRINTS_ENABLED
    else{
    		APP_log(APP_LOG_ERR,"ERR: SDL_VTM_getStaticRegistersTs failed \n");
    }
#endif

    /* Enable the threshold interrupts */
    SDL_VTM_intrCtrl ctrl;
    ctrl    = SDL_VTM_VD_GT_THR2_INTR_EN_CLR | \
              SDL_VTM_VD_GT_THR1_INTR_EN_SET | \
              SDL_VTM_VD_LT_THR0_INTR_EN_CLR;
    (void)SDL_VTM_intrCntrl(SDL_VTM_INSTANCE_VD_DOMAIN_2, ctrl);

    /* Configure the voltage domain for temperature sensor monitoring */
    SDL_VTM_configVd cfgVd;
    cfgVd.configVdCtrl = SDL_VTM_VD_CONFIG_CTRL_EVT_SEL;
    cfgVd.vd_temp_evts = SDL_VTM_VD_EVT_SELECT_TEMP_SENSOR_0 |
                         SDL_VTM_VD_EVT_SELECT_TEMP_SENSOR_1 |
                         SDL_VTM_VD_EVT_SELECT_TEMP_SENSOR_2 |
                         SDL_VTM_VD_EVT_SELECT_TEMP_SENSOR_3 |
                         SDL_VTM_VD_EVT_SELECT_TEMP_SENSOR_4;

    SDL_VTM_tsGlobal_cfg   tsGlobalCfg;
    tsGlobalCfg.validMap = 0;
    tsGlobalCfg.clkSel = 0;
    tsGlobalCfg.clkDiv = 0;
    tsGlobalCfg.any_maxt_outrg_alert_en = 0;
    tsGlobalCfg.maxt_outrg_alert_thr0 = 0;
    tsGlobalCfg.maxt_outrg_alert_thr = 0;
    tsGlobalCfg.samplesPerCnt = 0;
    cfgVd.tsGlobal_cfg = tsGlobalCfg;

    /* enable the tracking of temperature events on this VD */
    (void)SDL_VTM_initVd(SDL_VTM_INSTANCE_VD_DOMAIN_2, &cfgVd);

    /* VTM4: Software readback of written configuration */
    sdlResult_Vd = SDL_VTM_verifyConfigVd(SDL_VTM_INSTANCE_VD_DOMAIN_2, &cfgVd);

    if(sdlResult_Vd == SDL_PASS)
    {
        sdlResult_Vd = SDL_VTM_getStaticRegistersVd(SDL_VTM_INSTANCE_VD_DOMAIN_2, (SDL_VTM_staticRegsVd*) &Vtm_staticRegsVd_Expected);
    }
#ifdef UART_PRINTS_ENABLED
    else{
    		APP_log(APP_LOG_ERR,"ERR: SDL_VTM_verifyConfigVd failed \n");
    }
#endif

    if ( (sdlResult_Ts != SDL_PASS) || (sdlResult_Vd != SDL_PASS) )
    {
       /* while(1) {} */
    }
}

/* Check the error status of the VTM module */
uint8_t Vtm_app_check_error_status(void)
{
  /* DD-ID: {1F9CFF97-DBD4-40cb-8EDA-7F09719BC723}*/
    return gVtm_error_status;
}

static int32_t deactivateTrigger(SDL_ESM_Inst esmInstType,
                                 SDL_ESM_IntType esmIntType,
                                 uint32_t intEsmSrc)
{
      /* DD-ID: {84D64D42-BFCA-4cf8-B59F-05C2856E8E9B}*/
    int32_t retVal = 0;

    if ((esmInstType == SDL_ESM_INST_WKUP_ESM0) && (esmIntType == SDL_ESM_INT_TYPE_LO)) {
    	/* UC-1: Low Priority interrupt on WKUP ESM -
    	 * VTM greater than THR1 */
    	if (intEsmSrc == SDLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_VTM0_THERM_LVL_GT_TH1_INTR_0)
    	{
    		SDL_VTM_IntrruptGtThr1();
    		gVtm_error_status |= VTM_Overtemperature_detected;

    	}
        else if (intEsmSrc ==
                   SDLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_VTM0_THERM_LVL_LT_TH0_INTR_0)
        {
            SDL_VTM_IntrruptLtThr0();
            /* clear the over temp bits */
            gVtm_error_status &= ~(VTM_Overtemperature_detected);
        }
        else {
#ifdef UART_PRINTS_ENABLED
    		APP_log(APP_LOG_ERR,"ERR: Unexpected ESM Instance %d and ESM Interrupt Type %d \n",
    				esmInstType, esmIntType);
#endif
    		retVal = -1;
    	}
    }

   return (retVal);
}

/*
* This function clears VTM THR0 interrupt (Less Than Temp event)
* for VTM input events to the ESM.
* It resets the VTM module to look for high temperature events again.
*/
static void SDL_VTM_IntrruptLtThr0(void)
{
  /* DD-ID: {9E76CAEB-2C60-4583-9E23-245D3147B566}*/
    SDL_VTM_intrCtrl ctrl;

    /* Ack the interrupt, by clearing the pending bit */
    ctrl = (SDL_VTM_VD_LT_THR0_INTR_EN_CLR | \
            SDL_VTM_VD_GT_THR1_INTR_EN_CLR | \
            SDL_VTM_VD_GT_THR2_INTR_EN_CLR | \
            SDL_VTM_VD_LT_THR0_INTR_RAW_CLR | \
            SDL_VTM_VD_GT_THR1_INTR_RAW_CLR | \
            SDL_VTM_VD_GT_THR2_INTR_RAW_CLR);
    (void)SDL_VTM_intrCntrl(SDL_VTM_INSTANCE_VD_DOMAIN_2, ctrl);
    /* Print output ESM event to the screen */
#ifdef UART_PRINTS_ENABLED
    APP_log(APP_LOG_MAX,"\n    THR0 interrupt occured, COOLDOWN is in progress \n");
#endif

    gt_LowTempInterrupt_Flag = (uint8_t)TRUE;
}

/*
* This function clears VTM THR1 interrupts for VTM input event to the ESM.
*/
static void SDL_VTM_IntrruptGtThr1(void)
{
  /* DD-ID: {86255C19-C38C-441e-83AF-0DEE99153FA4}*/
    SDL_VTM_intrCtrl ctrl;
    /*
    - disable the gt1 interrupt
    - clear the gt1 interrupt
    - clear the lt0 interrupt
    - enable the lt0 intterupt
    */
    ctrl = (SDL_VTM_VD_GT_THR1_INTR_EN_CLR  |  \
            SDL_VTM_VD_GT_THR1_INTR_RAW_CLR |  \
            SDL_VTM_VD_LT_THR0_INTR_EN_SET | \
            SDL_VTM_VD_LT_THR0_INTR_RAW_CLR);

    /* Ack and Re-enable the LT_THR0 interrupt to let system know if coolings
     * took place */
    (void)SDL_VTM_intrCntrl(SDL_VTM_INSTANCE_VD_DOMAIN_2, ctrl);

    /* Print output ESM event to the screen */
#ifdef UART_PRINTS_ENABLED
    APP_log(APP_LOG_MAX,"\n    THR1 interrupt occured, Cooling required \n");
#endif

    gt_HighTempInterrupt_Flag = (uint8_t)TRUE;
}

/* VTM5: Periodic software readback of static configuration registers */
static void vtm_Periodic_ConfigRegCheck(void)
{
  /* DD-ID: {2625D9AF-3C20-414b-8497-92464807DBA4}*/
    /* set the var to true in the case that a config mis match is detected */
    bool configMisMatchFlag = false;
    static SDL_VTM_staticRegsTs Vtm_staticRegsTs = {0u};
    static SDL_VTM_staticRegsVd Vtm_staticRegsVd = {0u};
    uint8_t *tempRegPtr;
    uint8_t *regPtr;
    sint32_t regStatus;

    regStatus = SDL_VTM_getStaticRegistersTs(SDL_VTM_INSTANCE_TS_0, (SDL_VTM_staticRegsTs*)&Vtm_staticRegsTs);
    if ( SDL_PASS == regStatus )
    {
        tempRegPtr = (uint8_t *)&Vtm_staticRegsTs;
        regPtr = (uint8_t *)&Vtm_staticRegsTs_Expected;
        /* Check current read of Vtm_staticRegsTs matches the intial Vtm_staticRegsTs_Expected */
        if(0x00 != memcmp((const uint8_t*)tempRegPtr, (const uint8_t*)regPtr, sizeof(SDL_VTM_staticRegsTs)))
        {
            configMisMatchFlag = true;
#ifdef UART_PRINTS_ENABLED
            APP_log(APP_LOG_MAX,"\n vtm_Periodic_ConfigRegCheck: Readback register failure on line no. %d \n", __LINE__);
#endif
        }
    }
    else
    {
        configMisMatchFlag = true;
#ifdef UART_PRINTS_ENABLED
            APP_log(APP_LOG_MAX,"\n vtm_Periodic_ConfigRegCheck: Read failure: SDL_VTM_getStaticRegistersTs on line no. %d \n", __LINE__);
#endif
    }
    
    regStatus = SDL_VTM_getStaticRegistersVd(SDL_VTM_INSTANCE_VD_DOMAIN_2, (SDL_VTM_staticRegsVd*) &Vtm_staticRegsVd );
    if ( SDL_PASS == regStatus )
    {
        tempRegPtr = (uint8_t *)&Vtm_staticRegsVd;
        regPtr = (uint8_t *)&Vtm_staticRegsVd_Expected;
        /* Check current read of Vtm_staticRegsVd matches the intial Vtm_staticRegsVd_Expected */
        if(0x00 != memcmp((const uint8_t*)tempRegPtr, (const uint8_t*)regPtr, sizeof(SDL_VTM_staticRegsVd)))
        {
            configMisMatchFlag = true;
#ifdef UART_PRINTS_ENABLED
            APP_log(APP_LOG_MAX,"\n vtm_Periodic_ConfigRegCheck: Readback register failure on line no. %d \n", __LINE__);
#endif
        }
    }
    else
    {
        configMisMatchFlag = true;
#ifdef UART_PRINTS_ENABLED
            APP_log(APP_LOG_MAX,"\n vtm_Periodic_ConfigRegCheck: Read failure: SDL_VTM_getStaticRegistersVd on line no. %d \n", __LINE__);
#endif
    }

    if ( configMisMatchFlag )
    {
        gVtm_error_status |= VTM_Configuration_readback_error_VTM_registers;
    }
    else
    {
        gVtm_error_status &= ~(VTM_Configuration_readback_error_VTM_registers);
    }
}

static void vtm_CheckForOvertemperatureWarning(void)
{
  /* DD-ID: {8C98B2DA-0C53-4558-89A3-1F590EE27561}*/
    /* Check for Over Temperature warning */
    if(FALSE != gt_HighTempInterrupt_Flag)
    {
#ifdef UART_PRINTS_ENABLED
		APP_log(APP_LOG_ERR,"\nSDL: VTM: SOC Over-Temperature\n");
#endif
    	gt_HighTempInterrupt_Flag = (uint8_t)FALSE;
    	/* Trigger Thermal-Shutdown */
    	Cdd_Safety_SetTSDStatus(SDL_VTM_TSD_REQ);
    }
    else
    {
        /* DO Nothing */
    }
}

static void vtm_CheckForCoolingtemperatureWarning(void)
{
  /* DD-ID: {C245275E-92D6-4eb1-B39F-E06646ADF5BC}*/
    /* Check for High Temperature warning */
    if(FALSE != gt_LowTempInterrupt_Flag)
    {
        gt_LowTempInterrupt_Flag = (uint8_t)FALSE;
        /* Report error to CAN msg */
            f_Send_Dbg_SDLFault_CanTx((uint16_t)SDL_ERR_FAULT_LOW_TEMP_WARN);
        /* Achieve SafeState2 by resetting SOC */
		Pmic_F_SafeState2_v(SAFESTATE_REASON_VTM_TEMP);
    }
    else
    {
        /* DO Nothing */
    }
}

/* Periodic function for VTM */
void Vtm_MainFunction(void)
{
  /* DD-ID: {10C338DA-E93E-4cb6-B0F8-E312E5EB5119}*/
    SDL_VTM_Stat_read_ctrl readCtrl;
    SDL_VTM_adc_code adc_code;
    SDL_VTM_Stat_val statusVal;

    /* periodic register check */
    vtm_Periodic_ConfigRegCheck();

    /* Get current temperature value */
    readCtrl = SDL_VTM_TS_READ_DATA_OUT_VAL;
    (void)SDL_VTM_getSensorStatus(SDL_VTM_INSTANCE_TS_0, &readCtrl, &statusVal);
    adc_code = statusVal.data_out; /* data_out has the current temperature */
    (void)SDL_VTM_tsConvADCToTemp(adc_code, SDL_VTM_INSTANCE_TS_0, &(Vtm_CurrTemps[0u]));

    if(FUSA_VTM_NO_ERROR == gVtm_error_status)
    {
    	Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_VTM, (uint8_t)FALSE);
    }
    else
    {
    	Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_VTM, (uint8_t)TRUE);
    }

	/* Check for Over Temperature warning */
    vtm_CheckForOvertemperatureWarning();
    /* Check for Cooling Temperature warning */
    vtm_CheckForCoolingtemperatureWarning();
}
#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
