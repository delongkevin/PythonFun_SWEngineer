/* Copyright (c) 2021 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

 /**
 *  \file     sdl_pok_example.c
 *
 *  \brief    This file contains POK example code.
 *
 *  \details  POK example
 **/

/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
#include "pok.h"
#include "esm.h"
#include "fusa_application.h"
#include "ErrorManagerSatellite.h"
#include "ErrorManagerShared.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "pmic.h"
/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/
/*#define SDL_APP_POK_UART_PRINTS_ENABLED*/

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/
static int32_t deactivate_trigger(uint32_t *esm_err_sig );
static void sdlGetInstance(SDL_POK_Inst *instance, uint32_t *esm_err_sig);
static int32_t        SDL_POK_setConfig(SDL_POK_Inst instance, SDL_POK_config *pPokCfg);

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*===========================================================================*/
/*                         Function definitions                              */
/*===========================================================================*/
int32_t SDL_ESM_POK_applicationCallbackFunction(SDL_ESM_Inst esmInst,
                                            SDL_ESM_IntType esmIntrType,
                                            uint32_t grpChannel,
                                            uint32_t index,
                                            uint32_t intSrc,
                                            void *arg)
{
    /* DD-ID: {CFDD76DC-619F-4820-B5E6-66EE071FCA07}*/
    int32_t retVal = SDL_PASS;
    ldef_ErrorMgr_stAddData SDL_PokAddtionalData_au8 = {0u};
#if defined(SDL_APP_POK_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_ERR,"\n  POK Call back function called : instType 0x%x, intType 0x%x, " \
    		"grpChannel 0x%x, index 0x%x, intSrc 0x%x \n",
			esmInst, esmIntrType, grpChannel, index, intSrc);
    APP_log(APP_LOG_MAX,"  Take action \n");
#endif

   (void)esmInst;
   (void)esmIntrType;
   (void)grpChannel;
   (void)index;
   (void)arg;

    /* Disable the ESM Interrupt */
    if((intSrc == SDLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_2) ||
       (intSrc == SDLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_2))
    {
    	(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_PWR_Supply_Internal_POK_monitoring_VDD_CORE,
				ldef_ErrorMgr_ErrorActive,
				(const ldef_ErrorMgr_stAddData *)&SDL_PokAddtionalData_au8);
		Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_POK, (uint8_t)TRUE);
#if defined(SDL_APP_POK_UART_PRINTS_ENABLED)
		APP_log(APP_LOG_ERR,"SDL: POK -> Interrupt triggered:  POK_monitoring_VDD_CORE \n");
#endif

        /* Report error to CAN msg */
        f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_PWR_Supply_Internal_POK_monitoring_VDD_CORE);
    }
    else if((intSrc == SDLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_3) ||
	        (intSrc == SDLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_3))
    {
    	(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_PWR_Supply_Internal_POK_monitoring_VDD_CPU,
				ldef_ErrorMgr_ErrorActive,
				(const ldef_ErrorMgr_stAddData *)&SDL_PokAddtionalData_au8);
		Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_POK, (uint8_t)TRUE);
#if defined(SDL_APP_POK_UART_PRINTS_ENABLED)
		APP_log(APP_LOG_ERR,"SDL: POK -> Interrupt triggered:  POK_monitoring_VDD_CPU \n");
#endif
        /* Report error to CAN msg */
  		f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_PWR_Supply_Internal_POK_monitoring_VDD_CPU);
    }
    else{
    	/* Do nothing */
    }
    (void)deactivate_trigger(&intSrc);
    /*(void)SDL_ESM_clrNError(esmInst);*/
    /* Any additional customer specific actions can be added here */

    return retVal;
}

static int32_t deactivate_trigger(uint32_t *esm_err_sig )
{
  /* DD-ID: {B6B6DC54-1026-426f-9553-0C4B27FB7B7E}*/
    SDL_POK_Inst               instance;
    SDL_POK_config             pPokCfg;
    SDL_pokVal_t               pPokVal;
    SDL_wkupCtrlRegsBase_t    *pBaseAddr = (SDL_wkupCtrlRegsBase_t *) SDL_POK_MMR_BASE;
    int32_t                    sdlRet = SDL_EFAIL;

    sdlGetInstance(&instance, esm_err_sig);

    pPokCfg.hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION;
    pPokCfg.voltDetMode = SDL_PWRSS_GET_VOLTAGE_DET_MODE;
    pPokCfg.trim = SDL_PWRSS_TRIM_NO_ACTION;
    pPokCfg.detectionCtrl = SDL_POK_DETECTION_NO_ACTION;
    pPokCfg.pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION;
    pPokCfg.hystCtrlOV = SDL_PWRSS_HYSTERESIS_NO_ACTION;
    pPokCfg.trimOV = SDL_PWRSS_TRIM_NO_ACTION;
    pPokCfg.deglitch = SDL_PWRSS_DEGLITCH_NO_ACTION;
    (void)SDL_pokGetControl (pBaseAddr,&pPokCfg,&pPokVal,instance);
    /* Re-configure to "good" setting */
    if (pPokVal.voltDetMode == SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE)
    {
        pPokCfg.trim = 0;
        pPokCfg.trimOV = SDL_PWRSS_TRIM_NO_ACTION;
    }
    else
    {
        pPokCfg.trimOV = 45;
        pPokCfg.trim = SDL_PWRSS_TRIM_NO_ACTION;
    }

    pPokCfg.hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION;
    pPokCfg.voltDetMode = pPokVal.voltDetMode;
    pPokCfg.detectionCtrl = SDL_POK_DETECTION_NO_ACTION;
    pPokCfg.pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION;
    pPokCfg.hystCtrlOV = SDL_PWRSS_HYSTERESIS_NO_ACTION;
    pPokCfg.deglitch = SDL_PWRSS_DEGLITCH_NO_ACTION;
    sdlRet = SDL_POK_init(instance,&pPokCfg);

#if defined(SDL_APP_POK_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_ERR,"\n  POK Deactivate Trigger function called : Instance = %d, trim %d, trimOV %d \n",
    		instance, pPokCfg.trim, pPokCfg.trimOV);
    APP_log(APP_LOG_MAX,"  Take action \n");
#endif

    return sdlRet;
}

static int32_t SDL_POK_setConfig(SDL_POK_Inst instance, SDL_POK_config *pPokCfg)
{
  /* DD-ID: {0664A904-3296-4a63-8131-B601BE9463B0}*/
    int32_t sdlRet = SDL_EFAIL;

    #if defined(SDL_APP_POK_UART_PRINTS_ENABLED)
    if ( pPokCfg->voltDetMode == SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE )
    {
        APP_log(APP_LOG_MAX,"\n\n POK ID = %d , monitoring set to OV. Trim: %d\n", instance, pPokCfg->trim);
    }
    else if ( pPokCfg->voltDetMode == SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE )
    {
        APP_log(APP_LOG_MAX,"\n\n POK ID = %d , monitoring set to UV. Trim: %d\n", instance, pPokCfg->trim);
    }
    else
    {
        APP_log(APP_LOG_MAX,"\n\n POK ID = %d , monitoring set to OV-UV. Trim: %d\n", instance, pPokCfg->trim);
    }
    #endif

    sdlRet = SDL_POK_init(instance, pPokCfg);
    if (sdlRet != SDL_PASS)
    {
        #if defined(SDL_APP_POK_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX," SDL_POK_init failed! \n");
        #endif
    }
    else
    {
    }
    return(sdlRet);
}

static void sdlGetInstance(SDL_POK_Inst *instance, uint32_t *esm_err_sig)
{
  /* DD-ID: {F7CF76B0-9BAB-4d08-93EF-DD1465543C83}*/
    switch (*esm_err_sig)
    {
        case WKUP_ESM_ERR_SIG_VDD_CORE_UV:
        case WKUP_ESM_ERR_SIG_VDD_CORE_OV:
            *instance    = SDL_POK_VDD_CORE_ID;
            break;
        case WKUP_ESM_ERR_SIG_VDDR_CORE_UV:
        case WKUP_ESM_ERR_SIG_VDDR_CORE_OV:
            *instance    = SDL_POK_VDDR_CORE_ID;
            break;
        case WKUP_ESM_ERR_SIG_VDD_CPU_UV:
        case WKUP_ESM_ERR_SIG_VDD_CPU_OV:
            *instance    = SDL_POK_VDD_CPU_ID;
            break;
        case WKUP_ESM_ERR_SIG_VMON_EXT_UV:
        case WKUP_ESM_ERR_SIG_VMON_EXT_OV:
            *instance    = SDL_POK_VMON_EXT_ID;
            break;
        case WKUP_ESM_ERR_SIG_VMON_EXT_MAIN_1P8_OV:
        case WKUP_ESM_ERR_SIG_VMON_EXT_MAIN_1P8_UV:
            *instance    = SDL_POK_VMON_EXT_MAIN_1P8_ID;
            break;
        case WKUP_ESM_ERR_SIG_VMON_EXT_MAIN_3P3_OV:
        case WKUP_ESM_ERR_SIG_VMON_EXT_MAIN_3P3_UV:
            *instance = SDL_POK_VMON_EXT_MAIN_3P3_ID;
            break;
        case WKUP_ESM_ERR_SIG_VDD_MCU_OV:
            *instance = SDL_POK_VDD_MCU_OV_ID;
            break;
        case WKUP_ESM_ERR_SIG_VDD_MCU_UV:
            *instance = SDL_POR_POKLVB_UV_ID;
            break;
        case WKUP_ESM_ERR_SIG_VDDR_MCU_UV:
        case WKUP_ESM_ERR_SIG_VDDR_MCU_OV:
            *instance = SDL_POK_VDDR_MCU_ID;
            break;
        case WKUP_ESM_ERR_SIG_VDDSHV_WKUP_GEN_UV:
        case WKUP_ESM_ERR_SIG_VDDSHV_WKUP_GEN_OV:
            *instance = SDL_POK_VDDSHV_WKUP_GEN_ID;
            break;
        case WKUP_ESM_ERR_SIG_CAP_VDDS_MCU_GEN_UV:
        case WKUP_ESM_ERR_SIG_CAP_VDDS_MCU_GEN_OV:
            *instance = SDL_POK_CAP_VDDS_MCU_GEN_ID;
            break;
        case WKUP_ESM_ERR_SIG_VDDA_PMIC_IN_UV:
            *instance = SDL_POK_VDDA_PMIC_IN_ID;
            break;
        case WKUP_ESM_ERR_SIG_VDDA_MCU_UV:
            *instance = SDL_POR_POKHV_UV_ID;
            break;
        case WKUP_ESM_ERR_SIG_VDDA_MCU_OV:
            *instance = SDL_POR_POKLVA_OV_ID;
            break;
        default:
            *instance = (SDL_POK_Inst)(-1);
            break;
    }
    return;
}

void pok_init_voltage_monitors(void)
{
  /* DD-ID:{A145893A-3C9B-4744-BD0E-6C1933DEA761}*/
    SDL_POK_Inst currPOKInst = SDL_FIRST_POK_ID;

    int32_t sdl_ppRsl = SDL_POK_enablePP(SDL_POK_PRG_MAIN_ID, true);

    if(sdl_ppRsl == SDL_PASS)
    {
    	for ( currPOKInst = SDL_FIRST_POK_ID; currPOKInst < SDL_APP_NUM_POK_INST; currPOKInst++ )
    	{
    		if ( true == SDL_APP_POK_cfg[currPOKInst].instEnabled )
    		{
    			(void)SDL_POK_setConfig( SDL_APP_POK_cfg[currPOKInst].instance, &SDL_APP_POK_cfg[currPOKInst].pok_cfg );
    		}
    	}
    }

    /*
    ** SDL POK API's (e.g. SDL_POK_init) overwrites WKUP_ESM0 configurations to check
    ** POK module status but doesn't restore it to original value.
    */
    (void)ESM_init_WKUP_ESM0();

}

/* Nothing past this point */

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
