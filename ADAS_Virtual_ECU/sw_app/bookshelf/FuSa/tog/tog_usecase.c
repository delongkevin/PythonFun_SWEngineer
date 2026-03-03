/*
 * TOG Usecases
 *
 * Timeout Gasket (TOG) Example Application
 *
 *  Copyright (c) 2021 Texas Instruments Incorporated
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
 */
/**
 *  \file tog_usecase.c
 *
 *  \brief This file triggers input for the Timeout Gasket (TOG) example
 */

#include "tog_main.h"
#include "sdl_tog.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "fusa_application.h"
#include "ErrorManagerSatellite.h"
#include "ErrorManagerShared.h"
#include "pmic.h"
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/sciclient/sciclient.h>
#include <include/soc/j721s2/sdlr_soc_baseaddress.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
#define ESM_CFG_BASE                (SDL_ESM0_CFG_BASE)
#define TOG_TEST_TIMEOUTVAL 		(0x10000U)
#define END_POINT_ACCESS 			(0x00A90000U)
#endif /*(SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)*/

/* Commented -- Can be enabled in Future
* #define TOG_INSTANCE_MCU_INFRA0_CFG         0
*/

#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
__attribute((section(".text:TOG_test"))) int32_t tog_minTimeout(SDL_APP_TOG_cfg_t* togCfg);
__attribute((section(".text:TOG_test"))) void TOG_injectMCUINFRATimeoutError(uint32_t instanceIndex);
__attribute((section(".text:TOG_test"))) static void TOG_injectESMError(SDL_APP_TOG_cfg_t* togCfg);
static void tog_getTimeForIntr(uint32_t instanceIndex, uint8_t action);
#endif	/*(SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)*/

__attribute((section(".text:ESMApp_Handlers"))) int32_t SDL_ESM_TOG_applicationCallbackFunction(SDL_ESM_Inst esmInst,
                                                            SDL_ESM_IntType esmIntrType, uint32_t grpChannel,
                                                            uint32_t index, uint32_t intSrc, void *arg);

__attribute((section(".text:TOG_test"))) static void TOG_eventHandler(uint32_t instanceIndex);


#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

static volatile bool handlerFlag __attribute__((section(".data:TOG_test"))) = false;
static volatile bool tog_ipHung[SDL_TOG_MAX_INSTANCE+1u] = {0u};

#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
static uint32_t arg;
volatile uint64_t temp_TimeStamp_tog_start[SDL_TOG_MAX_INSTANCE+1u] = {0u};
volatile uint64_t temp_TimeStamp_tog_end[SDL_TOG_MAX_INSTANCE+1u] = {0u};
volatile uint64_t temp_TimeStamp_tog_diff[SDL_TOG_MAX_INSTANCE+1u] = {0u};
volatile static uint16_t togTimeoutValue = 50u;
#endif /*(SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)*/

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

int32_t SDL_ESM_TOG_applicationCallbackFunction(SDL_ESM_Inst esmInst,
                                            SDL_ESM_IntType esmIntrType,
                                            uint32_t grpChannel,
                                            uint32_t index,
                                            uint32_t intSrc,
                                            void *arg)
{
     /* DD-ID: {7EFB0A76-86ED-4d13-9A04-41F32A8E9F98}*/
    int32_t retVal = SDL_PASS;
    ldef_ErrorMgr_stAddData SDL_TogAddtionalData_au8 = {0u};

   (void)esmInst;
   (void)esmIntrType;
   (void)grpChannel;
   (void)index;
   (void)arg;

#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_ERR,"\n  TOG Call back function called : instType 0x%x, intType 0x%x, " \
                "grpChannel 0x%x, index 0x%x, intSrc 0x%x \n",
                esmInst, esmIntrType, grpChannel, index, intSrc);
    APP_log(APP_LOG_MAX,"  Take action \n");
#endif
    if(intSrc == SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_VDC_SOC_FW_VBUSP_32B_SRC_SAFEG1_SOC_FW_SAFEG_TRANS_ERR_LVL_0){
    	if(FALSE == tog_ipHung[SDL_TOG_INSTANCE_STOG15])
    	{
    		tog_ipHung[SDL_TOG_INSTANCE_STOG15] = TRUE;
    		TOG_eventHandler(15);
    		/* Report to Error-Manager */
    		(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_VBUSM_ESM_error_interrupt_IP_hung,
    				ldef_ErrorMgr_ErrorActive,
					(const ldef_ErrorMgr_stAddData *)&SDL_TogAddtionalData_au8);
    		(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_ESMErrInterrupt_Timeout,
    				ldef_ErrorMgr_ErrorActive,
					(const ldef_ErrorMgr_stAddData *)&SDL_TogAddtionalData_au8);

              /* Report error to CAN msg */
            f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_Timer_ESMErrInterrupt_Timeout);
    	}
    	else
    	{
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    	    APP_log(APP_LOG_ERR,"\nSDL_ESM_TOG_applicationCallbackFunction : Pmic_F_SafeState2_v\n");
#endif
    		/* TODO: Find out Error-Manager def and Report to it */

            /* Report error to CAN msg */
            f_Send_Dbg_SDLFault_CanTx((uint16)SAFESTATE_REASON_SDL_TOG);
			/* Achieve SafeState2 by resetting SOC */
    		Pmic_F_SafeState2_v(SAFESTATE_REASON_SDL_TOG);
    	}
    	Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_TOG, (uint8_t)TRUE);
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
    	tog_getTimeForIntr(15, true);
#endif
    }
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
    else if (intSrc == SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_VDC_INFRA_VBUSP_32B_SRC_SAFEG0_INFRA_SAFEG_TRANS_ERR_LVL_0){
        TOG_eventHandler(16);
        SDL_TOG_stop( 16 );
		tog_getTimeForIntr(16, true);
    }
	else if(intSrc == SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_TIMEOUT_64B3_TRANS_ERR_LVL_0)
	{
	    TOG_eventHandler(14);
        SDL_TOG_stop( 14 );
		tog_getTimeForIntr(14, true);
	}
	else if(intSrc == SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_TIMEOUT_64B4_TRANS_ERR_LVL_0)
	{
	    TOG_eventHandler(13);
        SDL_TOG_stop( 13 );
		tog_getTimeForIntr(13, true);
	}
#endif /*(SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)*/
	else{
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
	    APP_log(APP_LOG_MAX,"Invalid ISR source\n");
#endif
	}

    /* Any additional customer specific actions can be added here */

    return retVal;
}

static void TOG_eventHandler( uint32_t instanceIndex )
{
  /* DD-ID: {BCB44899-52B1-41e6-B3E0-7826D8C98361}*/
    int32_t status = SDL_PASS;
    uint32_t pendInts;
    uint32_t intCount;
    SDL_TOG_errInfo errInfo;
    SDL_TOG_config cfg;
    SDL_TOG_Inst instance;
    SDL_TOG_IntrSrc intSrc;
    intSrc = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE |
              SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT);

    instance = (SDL_TOG_Inst)instanceIndex;
    cfg.cfgCtrl = SDL_TOG_CFG_TIMEOUT;

#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_MAX," \n  TOG_eventHandler  \n");
#endif
    if (intSrc != 0U)
    {
        /* Read error info */
        status = SDL_TOG_getErrInfo(instance, &errInfo);
#if defined(UNITY_INCLUDE_CONFIG_H)
        TEST_ASSERT_EQUAL_INT32(SDL_PASS, status);
#endif
    }

    if (0u != (intSrc & SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT))
    {
        /* Get Transaction timeout interrupt count */
        if (status == SDL_PASS)
        {
            status = SDL_TOG_getIntrCount(instance, SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT, &intCount);
#if defined(UNITY_INCLUDE_CONFIG_H)
            TEST_ASSERT_EQUAL_INT32(SDL_PASS, status);
#endif
        }

        /* Clear Transaction timeout interrupt events */
        if ((status == SDL_PASS) && (intCount != 0u))
        {
            status = SDL_TOG_ackIntr(instance, SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT, intCount);
#if defined(UNITY_INCLUDE_CONFIG_H)
            TEST_ASSERT_EQUAL_INT32(SDL_PASS, status);
#endif
        }
    }

    if (0u != (intSrc & SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE))
    {
        /* Get Unexpected Response interrupt count */
        if (status == SDL_PASS)
        {
            status = SDL_TOG_getIntrCount(instance, SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE, &intCount);

#if defined(UNITY_INCLUDE_CONFIG_H)
            TEST_ASSERT_EQUAL_INT32(SDL_PASS, status);
#endif
        }

        /* Clear Unexpected response interrupt events */
        if ((status == SDL_PASS) && (intCount != 0u))
        {
            status = SDL_TOG_ackIntr(instance, SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE, intCount);
#if defined(UNITY_INCLUDE_CONFIG_H)
            TEST_ASSERT_EQUAL_INT32(SDL_PASS, status);
#endif
        }
    }

    /* Get Pending interrupt count */
    if (status == SDL_PASS)
    {
        status = SDL_TOG_getIntrPending(instance, &pendInts );
#if defined(UNITY_INCLUDE_CONFIG_H)
        TEST_ASSERT_EQUAL_INT32(SDL_PASS, status);
#endif
    }

    /* Clear Pending interrupt */
    if (status == SDL_PASS)
    {
        status = SDL_TOG_clrIntrPending(instance, SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT);
#if defined(UNITY_INCLUDE_CONFIG_H)
        TEST_ASSERT_EQUAL_INT32(SDL_PASS, status);
#endif
    }

    if (status == SDL_PASS)
    {
        status = SDL_TOG_clrIntrPending(instance, SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE);
#if defined(UNITY_INCLUDE_CONFIG_H)
        TEST_ASSERT_EQUAL_INT32(SDL_PASS, status);
#endif
    }

    if (status == SDL_PASS)
    {
        handlerFlag = true;
        /* Call SDL API to configure back Timeout Gasket */
        cfg.timeoutVal = SDL_APP_TOG_cfg[instance].cfg.timeoutVal/*TOG_TEST_TIMEOUTVAL*/;
        status = SDL_TOG_init(instance, &cfg);
#if defined(UNITY_INCLUDE_CONFIG_H)
        TEST_ASSERT_EQUAL_INT32(SDL_PASS, status);
#endif

        /* Stop the Timeout Gasket */
        (void)SDL_TOG_stop( instance );

        /* Reset the Timeout gasket */
        (void)SDL_TOG_reset( instance );

        /* Start the Timeout gasket */
        (void)SDL_TOG_start( instance );
    }
    return;
}

#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
static void TOG_injectESMError(SDL_APP_TOG_cfg_t* togCfg)
{
  /* DD-ID: {2D54C0FF-B849-45ec-9152-8A364EFA39AB}*/
    SDL_TOG_Inst instance;
    SDL_TOG_config cfg;
    /*instance = instanceIndex;*/
    instance = togCfg->instance;
    cfg.cfgCtrl = SDL_TOG_CFG_TIMEOUT;
    int32_t status;
    volatile esmRevisionId_t esmRevisionId;
    int i;
    /* Injecting error can result in a Data abort, so disable temporarily */
    disableABORT();

    /* Call SDL API to set smaller timeout to trigger error */
    cfg.timeoutVal = togTimeoutValue;
    status = SDL_TOG_init(instance, &cfg);
    if (status != SDL_PASS)
    {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\nInject SDL_TOG_init TimeoutVal Failed \n");
#endif
        /* Assert */
    }
    else
    {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    	APP_log(APP_LOG_MAX,"\nInject SDL_TOG_init TimeoutVal Completed \n");
#endif
    }
    SDL_REG32_RD(togCfg->cfg2.endPointAccess);
#if 0
    for (i=0; (i< (sizeof(int)*sizeof(int))) && (!(handlerFlag)); i++)
    {
    	/* Do something to trigger transaction through the Gasket */
    	SDL_REG32_RD(togCfg->cfg2.endPointAccess);

        /* Access Main ESM to trigger transaction through the Gasket */
        (void)SDL_ESM_getRevisionId(ESM_CFG_BASE, (esmRevisionId_t *)&esmRevisionId);
    	/*gTestMSMCLocation[i] = 1U;*/
    }
#endif
#if 1
    /* Call SDL API to set configure back to original timeout value */
    cfg.timeoutVal = TOG_TEST_TIMEOUTVAL;
    status = SDL_TOG_init(instance, &cfg);
    if (status != SDL_PASS)
    {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"   Configure back SDL_TOG_init TimeoutVal Failed \n");
#endif
        /* Assert */
    }

#endif

    /* Enable back Abort */
    enableABORT();
}

int32_t tog_minTimeout(SDL_APP_TOG_cfg_t* togCfg)
{
  /* DD-ID: {8FBB8931-CA03-4715-B57D-4A354F70679B}*/
    SDL_TOG_Inst instance;
    SDL_TOG_config cfg;
    void *ptr = (void *)&arg;
    int32_t status = SDL_PASS;
    int32_t result = 0;
    volatile uint32_t timeoutCount = 0;
    instance = togCfg->instance;
    cfg.cfgCtrl = SDL_TOG_CFG_TIMEOUT;

    /* Initialize done flag */
    handlerFlag = false;

#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_MAX,"\n Demo for minimum value timeout \n");
#endif

    if (result == 0)
    {
        /* Enable interrupts */
        status = SDL_TOG_setIntrEnable(instance, SDL_TOG_INTRSRC_ALL, true);
        if (status != SDL_PASS)
        {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"   SDL_TOG_setIntrEnable Failed \n");
#endif
            result = -1;
        } else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"\nSDL_TOG_setIntrEnable complete \n");
#endif
        }

    }

    /** Step 2: Configure and enable Timeout Gasket */
    if (result == 0)
    {
        /* Call SDL API to configure Timeout Gasket */
        cfg.timeoutVal = TOG_TEST_TIMEOUTVAL;
        status = SDL_TOG_init(instance, &cfg);
        if (status != SDL_PASS)
        {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"\nSDL_TOG_init timeout Failed \n");
#endif
            result = -1;
        } else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"\nSDL_TOG_init.timeout complete \n");
#endif
        }
    }

    if (result == 0)
    {
        /* Call SDL API to enable Timeout Gasket */
        status = SDL_TOG_start(instance);
        if (status != SDL_PASS)
        {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"   SDL_TOG_start Failed \n");
#endif
            result = -1;
        } else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"\nSDL_TOG_start complete \n");
#endif
        }
    }

    /* Step 3: Inject timeout error */
    if (result == 0)
    {
        TOG_injectESMError(togCfg);
    }

    /**--- Step 3: Wait for TOG Interrupt ---*/
    if (result == 0)
    {
        /* Timeout if exceeds time */
        while ((!handlerFlag)
               && (timeoutCount < TOG_MAX_TEST_TIMEOUT_VALUE))
        {
            timeoutCount++;
        }

        if (!(handlerFlag))
        {
        	(void)SDL_TOG_stop( instance );
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"   TOG test timed out \n");
#endif
            result = -1;
        } else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"\nSDL_TOG_stop complete \n");
#endif
        }
        /* reset Done flag so we can run again */
        handlerFlag = false;
    }

    return (result);
}
#endif /*(SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)*/

int32_t tog_AppInit(SDL_APP_TOG_cfg_t* togCfg)
{
  /* DD-ID: {C8422F40-3FEE-41ba-93C7-82DCA738AB90}*/
	SDL_TOG_Inst instance;
	SDL_TOG_config cfg;
	int32_t status = SDL_PASS;
	int32_t result = 0;
	instance = togCfg->instance;
	cfg.cfgCtrl = togCfg->cfg.cfgCtrl;

	/* Initialize done flag */
	handlerFlag = false;

#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
	APP_log(APP_LOG_MAX,"\n Demo for minimum value timeout \n");
#endif

	/* Enable interrupts */
	status = SDL_TOG_setIntrEnable(instance, togCfg->cfg.intrSrcs, true);
	if (status != SDL_PASS)
	{
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
		APP_log(APP_LOG_MAX,"   SDL_TOG_setIntrEnable Failed \n");
#endif
		result = -1;
	} else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
		APP_log(APP_LOG_MAX,"\nSDL_TOG_setIntrEnable complete \n");
#endif
	}

	/** Step 2: Configure and enable Timeout Gasket */
	if (result == 0)
	{
		/* Call SDL API to configure Timeout Gasket */
		cfg.timeoutVal = togCfg->cfg.timeoutVal;;
		status = SDL_TOG_init(instance, &cfg);
		if (status != SDL_PASS)
		{
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
			APP_log(APP_LOG_MAX,"   SDL_TOG_init timeout Failed \n");
#endif
			result = -1;
		} else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
			APP_log(APP_LOG_MAX,"\nSDL_TOG_init.timeout complete \n");
#endif
		}
	}

	/** Step 3: Verify the config is written as expected **/
	if (result == 0)
	{
		/* Call SDL API to configure Timeout Gasket */
		status = SDL_TOG_verifyConfig(instance, &cfg);
		if (status != SDL_PASS)
		{
			result = -1;
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
			APP_log(APP_LOG_MAX,"\ntog_AppInit: SDL_TOG_verifyConfig failed \n");
#endif
		} else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
			APP_log(APP_LOG_MAX,"\ntog_AppInit: SDL_TOG_verifyConfig complete \n");
#endif
		}
	}

	/** Step 4: Start the gasket **/
	if (result == 0)
	{
		/* Call SDL API to enable Timeout Gasket */
		status = SDL_TOG_start(instance);
		if (status != SDL_PASS)
		{
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
			APP_log(APP_LOG_MAX,"   SDL_TOG_start Failed \n");
#endif
			result = -1;
		} else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
			APP_log(APP_LOG_MAX,"\nSDL_TOG_start complete \n");
#endif

#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
			tog_getTimeForIntr(instance, false);
#endif
		}
	}

	/** Step 5: Read-back static registers **/
	if (result == 0)
	{
		(void)SDL_TOG_getStaticRegisters(instance, &SDL_TOG_staticRegs_Expected[instance]);

		if (status != SDL_PASS)
		{
			result = -1;
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
			APP_log(APP_LOG_MAX,"\ntog_AppInit: SDL_TOG_getStaticRegisters failed \n");
#endif
		} else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
			APP_log(APP_LOG_MAX,"\ntog_AppInit: SDL_TOG_getStaticRegisters complete \n");
#endif
		}
	}

	return (result);
}

#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
static void tog_getTimeForIntr(uint32_t instanceIndex, uint8_t action)
{
  /* DD-ID: {D24B1C08-8AE3-4b20-AF7E-3F848F0DA360}*/
	if(instanceIndex <= SDL_TOG_MAX_INSTANCE)
	{
		if(action == false)
		{
			temp_TimeStamp_tog_start[instanceIndex] = Fusa_GetTimestamp();
		}
		else if(action == true)
		{
			temp_TimeStamp_tog_end[instanceIndex] = Fusa_GetTimestamp();
			temp_TimeStamp_tog_diff[instanceIndex] = temp_TimeStamp_tog_end[instanceIndex] - temp_TimeStamp_tog_start[instanceIndex];
		}
		else
		{
			/* Do nothing */
		}
	}
}
#endif

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
