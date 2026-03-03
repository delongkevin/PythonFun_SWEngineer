/**
 * @file fusa_application.c
 * @brief Application component to call the SDL apis
 *
 * @details Configures the SDL components and contains ESM callback for error handling
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2022.  Magna Electronics owns all
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
 * @author Matt Kloepfer (matt.kloepfer@magna.com)
 */

 /* ===========================================================================
*
*   Include Files
*
* ========================================================================= */
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <ti/board/board.h>
#include <ti/drv/sciclient/sciclient.h>
#include <ti/osal/osal.h>
#include <ti/osal/TimerP.h>

#include "app_log_priv.h"

#include <sdl_types.h>
#include "fusa_application.h"
#include "fusa_osal_interface_autosar.h"
#include "esm.h"
#include "bist.h"
#include "vtm.h"
#include "pok_app.h"
#include "ecc_main.h"
#include "DDR_safety.h"
#include "CBASS_safety.h"
#include "ccm.h"
#include "dcc.h"
#include "tog_main.h"
#include "vim.h"
#include "MSMC_Safety.h"
#include "adc_safety.h"
#include "GPIO_Safety.h"
#include "reset_safety.h"
#include "mmr_safety.h"
#include "timer_fusa.h"
#include "ErrorManagerSatellite.h"
#include "ErrorManagerShared.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "ecc_ddr.h"
/* ===========================================================================
*
*   Defines
*
* ========================================================================= */
/*#define UART_PRINTS_ENABLED*/

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ===========================================================================

*   Global variables
*
* ========================================================================= */
uint8_t gSDL_Running = (uint8_t)false;
#if defined (BIST_ERRMGR_LOG)
volatile uint8_t bistFaultStatus = FALSE;
volatile T_LbistResult lbistFaultStatus = {.hWord = 0u};
volatile T_PbistResult pbistFaultStatus = {.word = 0u};
#endif
/* CCM Vars */
static volatile uint8_t gCcmSafetyCriticalConfigFailFlagValue = (uint8_t)false;
static volatile uint8_t gCcmErrorFlagValue = (uint8_t)false;
static volatile uint8_t gEsmSafetyCriticalConfigFailFlagValue = (uint8_t)false;
/* DDR Vars */
static volatile uint8_t gDDRSafetyCriticalConfigFailFlagValue = (uint8_t)false;
static volatile uint8_t gSDLErrorLog[e_errLog_Max] = {0u};
/* Fault status Vars */
static volatile uint8_t gAdcSafetyCriticalConfigFailFlagValue = (uint8_t)false;
static volatile uint8_t gCbassSafetyCriticalConfigFailFlagValue = (uint8_t)false;
static volatile uint8_t gResetSafetyCriticalConfigFailFlagValue = (uint8_t)false;
static volatile uint8_t gGpioSafetyCriticalConfigFailFlagValue = (uint8_t)false;
static volatile uint8_t gMcuWkupMMRSafetyCriticalConfigFailFlagValue = (uint8_t)false;
static volatile uint8_t gMainMMRSafetyCriticalConfigFailFlagValue = (uint8_t)false;
static volatile uint8_t gMSMCCfgErrorFlagValue = (uint8_t)false;
static volatile uint8_t gWkupClkDetErrorFlagValue = (uint8_t)false;
static volatile uint8_t gPllSlipMcuErrorFlagValue = (uint8_t)false;
static volatile uint8_t gPllSlipMainErrorFlagValue = (uint8_t)false;
static volatile uint8_t gMcuDCCErrorFlagValue = (uint8_t)false;
static volatile uint8_t gMainDCCErrorFlagValue = (uint8_t)false;
static volatile uint8_t gDccErrorFlagValue = (uint8_t)false;
static volatile uint8_t gPLLreadbackErrorFlagValue = (uint8_t)false;

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

/* ===========================================================================
*
* Private functions
*
* ========================================================================= */
/* None */

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ========================================================================== */
/*                          Function Implementation                           */
/* ========================================================================== */

/*
 * Purpose: Initalize the ESM
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_Init(void)
{
  /* DD-ID: {F3D5E48A-9F03-4eb9-93C5-B93E7F439DE2}*/

    /* Timestamp Vars */
    static uint64_t fusa_initTStart, fusa_initTEnd, fusa_initTAll;
    fusa_initTStart = TimerP_getTimeInUsecs();
#ifdef UART_PRINTS_ENABLED
    APP_log(APP_LOG_MAX,"\n  Fusa-Init Started \n");
#endif

    (void)Fusa_TimestampInit();

    TASK_esm_app_init();

#if (SDL_APP_CCM_ENABLED == SDL_APP_ON)
    TASK_ccm_app_init();
#endif	/* SDL_APP_CCM_ENABLED */

#if ( SDL_APP_VTM_ENABLED == SDL_APP_ON )
    TASK_vtm_app_init();
#endif 	/* ( SDL_APP_VTM_ENABLED == SDL_APP_ON ) */

#if ( SDL_APP_ECC_ENABLED == SDL_APP_ON )
    (void)ECC_init();
#endif

#if ( SDL_APP_DDR_ECC_ENABLED == SDL_APP_ON )
    DDREccInit();
#endif

#if (SDL_APP_POK_ENABLED == SDL_APP_ON)
    pok_init();
#endif

#if (SDL_APP_DCC_ENABLED == SDL_APP_ON)
    dcc_init();
#endif

#if (SDL_APP_TOG_ENABLED == SDL_APP_ON)
	tog_init();
#endif

#if ( SDL_APP_DDR_ENABLED == SDL_APP_ON )
    TASK_DDR_safety_init();
#endif

#if (SDL_APP_VIM_ENABLED == SDL_APP_ON)
    vim_init();
#endif

#if (SDL_APP_CBASS_ENABLED == SDL_APP_ON)
    TASK_CBASS_safety_init();
#endif

#if ( SDL_APP_ADC_ENABLED == SDL_APP_ON )
	TASK_adc_safety_init();
#endif

#if ( SDL_APP_RESET_ENABLED == SDL_APP_ON )
	TASK_reset_safety_init();
#endif

	TASK_gpio_safety_init();

#if ( SDL_APP_MMR_ENABLED == SDL_APP_ON )
	TASK_mmr_safety_init();
#endif

#if ( SDL_APP_MSMC_ENABLED == SDL_APP_ON )
	Sdl_Application_MSMC_init();
#endif

#if defined (BIST_ERRMGR_LOG)
    Bist_GetBistStatus((T_LbistResult*)&lbistFaultStatus, (T_PbistResult*)&pbistFaultStatus);
	if(bistFaultStatus == FALSE)
	{
		bistFaultStatus = TRUE;
		/* LBIST checks */
		if(lbistFaultStatus.bits.resLBIST_HWPOST_INST_SMS_INDEX == TRUE)
		{
			ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_DMSC_LBIST_error,
					ldef_ErrorMgr_ErrorActive,
					(const ldef_ErrorMgr_stAddData *)NULL);
		}

		if(lbistFaultStatus.bits.resLBIST_HWPOST_INST_MCU_INDEX == TRUE)
		{
			ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_R5F_LBIST_error,
					ldef_ErrorMgr_ErrorActive,
					(const ldef_ErrorMgr_stAddData *)NULL);
		}

		if(lbistFaultStatus.bits.resLBIST_INST_MAINR5F1_INDEX == TRUE)
		{
			ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_R5F_LBIST_error,
					ldef_ErrorMgr_ErrorActive,
					(const ldef_ErrorMgr_stAddData *)NULL);
		}

		/* PBIST checks */
		if(pbistFaultStatus.bits.resPBIST_HWPOST_MCU_INDEX == TRUE)
		{
			ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_R5F_PBIST_check_MemError_Internal_RAMCache_and_Config_registers,
					ldef_ErrorMgr_ErrorActive,
					(const ldef_ErrorMgr_stAddData *)NULL);
		}

		if(pbistFaultStatus.bits.resPBIST_INSTANCE_MAINR5F0 == TRUE)
		{
			ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_R5F_PBIST_check_MemError_Internal_RAMCache_and_Config_registers,
					ldef_ErrorMgr_ErrorActive,
					(const ldef_ErrorMgr_stAddData *)NULL);
		}
	}
#endif
#ifdef UART_PRINTS_ENABLED
    APP_log(APP_LOG_MAX,"\n  Fusa-Init Ended \n");
#endif
    fusa_initTEnd = TimerP_getTimeInUsecs();
    fusa_initTAll = (fusa_initTEnd > fusa_initTStart) ? (fusa_initTEnd - fusa_initTStart) : ( fusa_initTStart - fusa_initTEnd);
}

/*
 * Purpose: run self test for the SDL components
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_RunSelfTest(void)
{
  /* DD-ID: {772EE274-023F-4077-B1B8-6DD135CD9403}*/
    uint8_t isInitDone = IsEsmAppInitComplete();
    if(ESM_INIT_NOT_DONE != isInitDone)
    {
#ifdef UART_PRINTS_ENABLED
    	APP_log(APP_LOG_MAX,"\n  Fusa-SelfTest Started \n");
#endif
    	gSDL_Running = (uint8_t)true;
#if ( SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON )
    	TASK_ccm_app_self_test();
#endif	/* ( SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON )*/

#if ( SDL_APP_ECC_SELFTEST_ENABLED == SDL_APP_ON )
    	ECC_funcTest();
#endif	/*( SDL_APP_ECC_SELFTEST_ENABLED == SDL_APP_ON )*/
    	gSDL_Running = (uint8_t)false;
#ifdef UART_PRINTS_ENABLED
    	APP_log(APP_LOG_MAX,"\n  Fusa-SelfTest Ended \n");
#endif

 /*  SDL_APP_DDR_ECC_SELFTEST_ENABLED macro enable will corrupt the DDR,never change it
  * Only for the DDR Inline ECC memory test prupose.
  * Not production intened , only for self test
  */
#if ( SDL_APP_DDR_ECC_SELFTEST_ENABLED == SDL_APP_ON )
     DDREccTest();
#endif
   /* DDR Inline ECC self test End */

    }
}

/*
 * Purpose: Run periodic check of SDL
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_MainFunction(void)
{
    /* DD-ID: {25C88DCF-BD12-4e8f-AF1F-693A1F4AB407}*/
    uint8_t isInitDone = IsEsmAppInitComplete();
    /* MainFunction Counter Vars */
    static volatile uint8_t gSdlApplication_MainFunctionCounter=0;
    /* Timer Checks, to be called at 10ms */
    Timers_SafetyChecks_MainFunction();

    if(ESM_INIT_NOT_DONE != isInitDone)
    {
        gSdlApplication_MainFunctionCounter += (uint8_t)SDL_CDD_MAIN_TASK_RATE;

        switch(gSdlApplication_MainFunctionCounter)
        {
            #if ( SDL_APP_VTM_ENABLED == SDL_APP_ON )
            case    SDL_APP_VTM_MAIN_FUNCTION_OFFSET:
                    {
                        Vtm_MainFunction();
                    }
            break;
            #endif

            case   SDL_APP_ESM_MAIN_FUNCTION_OFFSET:
                    {
                        TASK_esm_MainFunction();
                    }
            break;

            #if ( SDL_APP_CCM_ENABLED == SDL_APP_ON )
            case    SDL_APP_CCM_MAIN_FUNCTION_OFFSET:
                    {
                        TASK_ccm_app_MainFunction();
                    }
            break;
            #endif

            #if ( SDL_APP_DCC_ENABLED == SDL_APP_ON )
            case    SDL_APP_DCC_MAIN_FUNCTION_OFFSET:
                    {
                        dcc_MainFunction();
                    }
            break;
            #endif

            #if ( SDL_APP_TOG_ENABLED == SDL_APP_ON )
            case    SDL_APP_TOG_MAIN_FUNCTION_OFFSET:
                    {
                        tog_MainFunction();
                    }
            break;
            #endif

            #if ( SDL_APP_CBASS_ENABLED == SDL_APP_ON )
            case    SDL_APP_CBASS_MAIN_FUNCTION_OFFSET:
                    {
                        TASK_CBASS_safety_MainFunction();
                    }
            break;
            #endif

            case    SDL_APP_ADC_MAIN_FUNCTION_OFFSET:
#if ( SDL_APP_ADC_ENABLED == SDL_APP_ON )
                    {
                        TASK_adc_safety_MainFunction();
                    }
#endif
            		TASK_mmr_safety_MainFunction();
            break;

            #if ( SDL_APP_DDR_ENABLED == SDL_APP_ON )
            case    SDL_APP_DDR_MAIN_FUNCTION_OFFSET:
                    {
                        TASK_DDR_safety_MainFunction();
                    }
            break;
            #endif

            #if ( SDL_APP_RESET_ENABLED == SDL_APP_ON )
            case    SDL_APP_RESET_MAIN_FUNCTION_OFFSET:
                    {
                		TASK_reset_safety_MainFunction();
                    }
            break;
            #endif
			#if (SDL_APP_VIM_ENABLED == SDL_APP_ON)
            case    SDL_APP_VIM_MAIN_FUNCTION_OFFSET:
                    {
                		vim_MainFunction();
                    }
            break;
			#endif

            case 	SDL_APP_GPIO_MAIN_FUNCTION_OFFSET:
            		{
            			TASK_gpio_safety_MainFunction();

#if ( SDL_APP_MSMC_ENABLED == SDL_APP_ON )
            			/* Periodically check for MSMC register configurations */
            			Sdl_Application_MSMC_Safety();
#endif
            		}
            break;

            default:
                    if((uint8_t)SDL_CDD_ERROR_MANAGER_REPORT_TIME_EXPIRED <= gSdlApplication_MainFunctionCounter)
                    {
                        gSdlApplication_MainFunctionCounter = (uint8_t)0;
                    }
            break;
        }
    }
}

int32_t Fusa_TimestampInit(void)
{
  /* DD-ID: {A0E22942-0AC4-4eb4-A129-C453662F978B}*/
    int32_t             tsFreqKHz;
    tsFreqKHz = FUSA_autosar_GlobalTimeInit();
    tsFreqKHz = 1;
    return tsFreqKHz;
}

uint64_t Fusa_GetTimestamp(void)
{
  /* DD-ID: {5FC5E6FD-4A05-4736-9637-C571B42C1740}*/
    uint64_t            temp_TimeStamp;
    temp_TimeStamp = FUSA_autosar_GetGlobalTimeInUsec();
    return temp_TimeStamp;
}

/*
 * Purpose: Read CCM SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_GetCcmSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {21076CB8-BC34-4ee1-AAF6-FB4C495639A3}*/
    return (gCcmSafetyCriticalConfigFailFlagValue);
}

/*
 * Purpose: Set CCM SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_SetCcmSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {8E46060F-D581-4e19-AE80-743E3B57B900}*/
    gCcmSafetyCriticalConfigFailFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear CCM SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_ClearCcmSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {4B926976-E2F7-4ffe-9508-D22A8F9ED758}*/
    gCcmSafetyCriticalConfigFailFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Read CCM Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_GetCcmErrorFlag(void)
{
  /* DD-ID: {0495137F-D5B0-4218-84F2-AA3630F78038}*/
    return (gCcmErrorFlagValue);
}

/*
 * Purpose: Set CCM Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_SetCcmErrorFlag(void)
{
  /* DD-ID: {05CCEEA8-09C4-45cd-ACD0-BC9956C25BB0}*/
    gCcmErrorFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear CCM Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_ClearCcmErrorFlag(void)
{
  /* DD-ID: {B2D58112-3970-46a3-A78B-21A2775048AD}*/
    gCcmErrorFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Read ADC SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_GetAdcSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {B9C31599-AF4C-41d2-801C-E81205A06A55}*/
    return (gAdcSafetyCriticalConfigFailFlagValue);
}

/*
 * Purpose: Set ADC SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_SetAdcSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {2E28D72F-71B9-43e7-A924-42C3D6328681}*/
    gAdcSafetyCriticalConfigFailFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear ADC SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_ClearAdcSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {06267737-A345-4452-AB77-1E19C18939DE}*/
    gAdcSafetyCriticalConfigFailFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Read CBASS SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_GetCbassSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {D38E4D61-EDE1-446f-AC31-B47E6A0AA8A9}*/
    return (gCbassSafetyCriticalConfigFailFlagValue);
}

/*
 * Purpose: Set CBASS SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_SetCbassSafetyCriticalConfigFailFlag(uint8_t val)
{
  /* DD-ID: {E9297177-3E3D-46d4-A4AD-993A8C22FB0D}*/
    gCbassSafetyCriticalConfigFailFlagValue = val;
}

/*
 * Purpose: Clear CBASS SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_ClearCbassSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {18AD0FE2-E439-4d5a-A9DD-5C4C0EFE3244}*/
    gCbassSafetyCriticalConfigFailFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Read RESET SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_GetResetSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {577711D4-8E51-418c-A848-4795B3E1D4E4}*/
    return (gResetSafetyCriticalConfigFailFlagValue);
}

/*
 * Purpose: Set RESET SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_SetResetSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {04746171-C473-4885-909E-A351FBE36E08}*/
    gResetSafetyCriticalConfigFailFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear RESET SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_ClearResetSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {D0841E20-1E24-42a1-AD00-0CCB1E8C91F8}*/
    gResetSafetyCriticalConfigFailFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Read GPIO SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_GetGpioSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {BCC6A6EF-AA22-4faa-BFF4-B55F2E22D172}*/
    return (gGpioSafetyCriticalConfigFailFlagValue);
}

/*
 * Purpose: Set GPIO SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_SetGpioSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {8A4EEE2C-48BE-456e-99AE-A5461EB01BD9}*/
    gGpioSafetyCriticalConfigFailFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear GPIO CriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_ClearGpioSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {FB9C297C-E5B0-4cb5-B0DD-689DE733EA8B}*/
    gGpioSafetyCriticalConfigFailFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Read MCU_WKUP MMR SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_GetMcuWkupMMRSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {3410D764-39D6-4e07-A9C3-2BA1BF627299}*/
    return (gMcuWkupMMRSafetyCriticalConfigFailFlagValue);
}

/*
 * Purpose: Set MCU_WKUP MMR SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_SetMcuWkupMMRSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {57E43791-3FB2-4884-8937-345B7326F2A4}*/
    gMcuWkupMMRSafetyCriticalConfigFailFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear MCU_WKUP MMR SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_ClearMcuWkupMMRSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {247D24B7-1640-4f7b-B5EF-1A181F180F40}*/
    gMcuWkupMMRSafetyCriticalConfigFailFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Read MAIN MMR SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_GetMainMMRSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {B7FD9C6A-9323-4fc8-8612-A93476653D14}*/
    return (gMainMMRSafetyCriticalConfigFailFlagValue);
}

/*
 * Purpose: Set MAIN MMR SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_SetMainMMRSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {5F64E9E1-B439-445d-B771-DD7980D8BCCD}*/
    gMainMMRSafetyCriticalConfigFailFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear MAIN MMR SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_ClearMainMMRSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {9FD8AE32-2707-4ce9-90AB-4D6C1AE9B911}*/
    gMainMMRSafetyCriticalConfigFailFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Read ESM SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_GetEsmSafetyCriticalConfigFailFlag(uint8_t bitPosition)
{
  /* DD-ID: {14AF99ED-7FB3-48c3-A8D2-06D0066FC42F}*/
    return ((gEsmSafetyCriticalConfigFailFlagValue >> bitPosition) & FAULT_STATUS_NOK);
}

/*
 * Purpose: Set ESM SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_SetEsmSafetyCriticalConfigFailFlag(uint8_t bitPosition)
{
  /* DD-ID: {FB7A14B7-93AE-46f7-BB44-541A7D3750F6}*/
    gEsmSafetyCriticalConfigFailFlagValue |= ((uint8_t)0x01 << bitPosition);
}

/*
 * Purpose: Clear ESM SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Fusa_Application_ClearEsmSafetyCriticalConfigFailFlag(uint8_t bitPosition)
{
  /* DD-ID: {DB4333E3-79C1-4a1c-9D27-438CCEECF789}*/
    gEsmSafetyCriticalConfigFailFlagValue &= ((uint8_t)(~((uint8_t)0x01 << bitPosition)));  
}

/*
 * Purpose:
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_Get_Thermal_Pre_warning_detected(void)
{
  /* DD-ID: {0A760349-9474-474f-9F26-0A225CB5AC33}*/
    uint8_t currVtmErrors = Vtm_app_check_error_status();
    if ( VTM_Thermal_Pre_warning_detected == (currVtmErrors&VTM_Thermal_Pre_warning_detected) )
    {
        return 0xFFu;
    }
    else
    {
        return 0x00u;
    }
}

/*
 * Purpose:
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_Get_Overtemperature_detected(void)
{
  /* DD-ID: {3443ABCC-8E7C-4455-8A5C-21ED2F69AFD5}*/
    uint8_t currVtmErrors = Vtm_app_check_error_status();
    if ( VTM_Overtemperature_detected == (currVtmErrors&VTM_Overtemperature_detected) )
    {
        return SDL_VTM_TSD_DETECTED;
    }
    else
    {
        return SDL_VTM_TSD_NOT_DETECTED;
    }
}

/*
 * Purpose:
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_Get_Parity_error_on_VTM_configuration_registers(void)
{
  /* DD-ID: {B2C7E44B-C891-4dc3-9103-F9BE2F65DE51}*/
    uint8_t currVtmErrors = Vtm_app_check_error_status();
    if ( VTM_Parity_error_on_VTM_configuration_registers == (currVtmErrors&VTM_Parity_error_on_VTM_configuration_registers) )
    {
        return 0xFFu;
    }
    else
    {
        return 0x00u;
    }
}

/*
 * Purpose:
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_Get_Configuration_readback_error_VTM_registers(void)
{
  /* DD-ID: {61F16AD3-C4CA-485d-9037-F76CD348148D}*/
    uint8_t currVtmErrors = Vtm_app_check_error_status();
    if ( VTM_Configuration_readback_error_VTM_registers == (currVtmErrors&VTM_Configuration_readback_error_VTM_registers) )
    {
        return 0xFFu;
    }
    else
    {
        return 0x00u;
    }
}

/*
 * Purpose:
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_Get_Fault_inject_test_failure_on_Over_temperature_detection(void)
{
  /* DD-ID: {993DD356-0054-457d-BEC0-E3E6009DB997}*/
    uint8_t currVtmErrors = Vtm_app_check_error_status();
    if ( VTM_Fault_inject_test_failure_on_Over_temperature_detection == (currVtmErrors&VTM_Fault_inject_test_failure_on_Over_temperature_detection) )
    {
        return 0xFFu;
    }
    else
    {
        return 0x00u;
    }
}

/*
 * Purpose:
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Fusa_Application_Get_Fault_inject_test_error_on_Parity_detection_logic__VTM_configuration_registers(void)
{
  /* DD-ID: {CA4E80E9-3F08-4d41-A211-5D837BE10DE4}*/
    uint8_t currVtmErrors = Vtm_app_check_error_status();
    if ( VTM_Fault_inject_test_error_on_Parity_detection_logic__VTM_configuration_registers == (currVtmErrors & VTM_Fault_inject_test_error_on_Parity_detection_logic__VTM_configuration_registers) )
    {
        return 0xFFu;
    }
    else
    {
        return 0x00u;
    }
}

void Fusa_Application_ErrorLogForDID(uint8_t errId, uint8_t error)
{
  /* DD-ID: {F23A8BE0-8152-4152-946E-8692C2BA71DF}*/
	if(errId < (uint8_t)e_errLog_Max)
	{
		gSDLErrorLog[errId] = error;
	}
}

void Fusa_Application_GetLogErrorForDID(uint8_t *errTable)
{
  /* DD-ID: {82C45BE6-4127-47c5-A5C6-89B55739E47D}*/
	uint8_t i;
	if(errTable != NULL)
	{
		for(i = 0u; i<(uint8_t)e_errLog_Max; i++)
		{
			errTable[i] = gSDLErrorLog[i];
		}
	}
}
/*
 * Purpose: Read DDR SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t (uint8_t)
*/
uint8_t Sdl_Application_GetDDRSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {9BB7EAF4-9851-46d0-9827-D69133EDC90F}*/
    return (gDDRSafetyCriticalConfigFailFlagValue);
}

/*
 * Purpose: Set DDR SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_SetDDRSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {B5FDE537-DA02-441b-8BCD-6ED852DE3A6F}*/
    gDDRSafetyCriticalConfigFailFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear DDR SafetyCriticalConfig Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_ClearDDRSafetyCriticalConfigFailFlag(void)
{
  /* DD-ID: {DB75ADF6-90F5-44e4-9159-77629ADF487D}*/
    gDDRSafetyCriticalConfigFailFlagValue = FAULT_STATUS_OK;

}
/*
 * Purpose: Read MSMC Cfg Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Sdl_Application_GetMSMCCfgErrorFlag(void)
{
  /* DD-ID: {35670E47-69D7-43a5-B7CC-FD5107C68B10}*/
    return (gMSMCCfgErrorFlagValue);
}

/*
 * Purpose: Set MSMC Cfg Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_SetMSMCCfgErrorFlag(void)
{
  /* DD-ID: {868621BA-E529-4cc1-B073-F05545B04AC5}*/
    gMSMCCfgErrorFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear MSMC Cfg Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_ClearMSMCCfgErrorFlag(void)
{
  /* DD-ID: {2AD58D75-FA5E-47e2-8A04-33B6F9F1C078}*/
    gMSMCCfgErrorFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Read OCOLKDET Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Sdl_Application_GetClkDetErrorFlag(void)
{
  /* DD-ID: {9B6864C3-C073-468b-9AF4-E9F107F8882E}*/
    return (gWkupClkDetErrorFlagValue);
}

/*
 * Purpose: Set OCOLKDET Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_SetClkDetErrorFlag(void)
{
  /* DD-ID: {87214B49-3CBB-440d-A357-C620503599C4}*/
    gWkupClkDetErrorFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear OCOLKDET Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_ClearClkDetErrorFlag(void)
{
  /* DD-ID: {750BE476-45C1-439b-929F-6DB3C8E4E4B9}*/
    gWkupClkDetErrorFlagValue = FAULT_STATUS_OK;
}
/*
 * Purpose: Read PLL slip Mcu Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Sdl_Application_GetPllSlipMcuErrorFlag(void)
{
  /* DD-ID: {825FBB78-B6BD-45fc-AD11-881A9A7DF992}*/
    return (gPllSlipMcuErrorFlagValue);
}

/*
 * Purpose: Set PLL slip Mcu Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_SetPllSlipMcuErrorFlag(void)
{
  /* DD-ID: {BC4E32ED-38E0-4ab9-ADCA-D917CAECF39D}*/
    gPllSlipMcuErrorFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear PLL slip Mcu Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_ClearPllSlipMcuErrorFlag(void)
{
  /* DD-ID: {C658FDB5-7DEB-4289-90FF-25FA7E7E8A50}*/
    gPllSlipMcuErrorFlagValue = FAULT_STATUS_OK;
}
/*
 * Purpose: Read PLL slip Main Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Sdl_Application_GetPllSlipMainErrorFlag(void)
{
  /* DD-ID: {2092061C-99D4-473e-990A-A9198C1AA86D}*/
    return (gPllSlipMainErrorFlagValue);
}

/*
 * Purpose: Set PLL slip Main Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_SetPllSlipMainErrorFlag(void)
{
  /* DD-ID: {F9834541-D878-4907-9E31-FC33EC3D19FE}*/
    gPllSlipMainErrorFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear PLL slip Main Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_ClearPllSlipMainErrorFlag(void)
{
  /* DD-ID: {FB316937-D9A2-481d-B61C-58D4F78F2992}*/
    gPllSlipMainErrorFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Set MCU DCC Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_SetMcuDCCErrorFlag(void)
{
  /* DD-ID: {6CA0CD7C-2C10-4398-A521-3969B8894ECB}*/
    gMcuDCCErrorFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear MCU DCC Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_ClearMcuDCCErrorFlag(void)
{
  /* DD-ID: {CF9713D7-01AD-491a-977A-1542E3766C09}*/
    gMcuDCCErrorFlagValue = FAULT_STATUS_OK;
}
/*
 * Purpose: Read MCU DCC Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Sdl_Application_GetMcuDCCErrorFlag(void)
{
  /* DD-ID: {3DAA5DF1-5D0A-4adb-A2D4-DBF28EEA1A65}*/
    return (gMcuDCCErrorFlagValue);
}

/*
 * Purpose: Set Main DCC Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_SetMainDCCErrorFlag(void)
{
  /* DD-ID: {01183428-F6E5-477c-B754-BE03B6FBBCEB}*/
    gMainDCCErrorFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear Main DCC Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_ClearMainDCCErrorFlag(void)
{
  /* DD-ID: {9BE65B5D-47C5-4c10-9403-F6B07E41F6F5}*/
    gMainDCCErrorFlagValue = FAULT_STATUS_OK;
}
/*
 * Purpose: Read Main DCC Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Sdl_Application_GetMainDCCErrorFlag(void)
{
  /* DD-ID: {DB604689-7B29-44e5-BA1E-0C4F4CA7337C}*/
    return (gMainDCCErrorFlagValue);
}

/*
 * Purpose: Read DCC Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Sdl_Application_GetDccErrorFlag(void)
{
  /* DD-ID: {5494202D-E40A-4d02-BC15-B5145F4AAADA}*/
    return (gDccErrorFlagValue);
}

/*
 * Purpose: Set DCC Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_SetDccErrorFlag(void)
{
  /* DD-ID: {ABB6D737-C857-4e8c-B2E8-83E8B29AAEFE}*/
    gDccErrorFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear DCC Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_ClearDccErrorFlag(void)
{
  /* DD-ID: {414D35DB-6BA0-4edd-8619-231B21E6AE1C}*/
    gDccErrorFlagValue = FAULT_STATUS_OK;
}

/*
 * Purpose: Set PLL readback Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_SetPLLreadbackErrorFlag(void)
{
  /* DD-ID: {660B2B31-B091-4890-A69C-A51D3B7FBAF4}*/
    gPLLreadbackErrorFlagValue = FAULT_STATUS_NOK;
}

/*
 * Purpose: Clear PLL readback Error Flag
 * Description:
 * Precondition:
 * Return Type : void
*/
void Sdl_Application_ClearPLLreadbackErrorFlag(void)
{
  /* DD-ID: {923F948A-7C7F-4f2a-8A70-9FDDB5770D75}*/
    gPLLreadbackErrorFlagValue = FAULT_STATUS_OK;
}
/*
 * Purpose: Read PLL readback Error Flag
 * Description:
 * Precondition:
 * Return Type : uint8_t
*/
uint8_t Sdl_Application_GetPLLreadbackErrorFlag(void)
{
  /* DD-ID: {2004E8B1-2393-4871-94E9-C17ED0D8CC53}*/
    return (gPLLreadbackErrorFlagValue);
}
/*===============================End Of File========================================================*/
#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
