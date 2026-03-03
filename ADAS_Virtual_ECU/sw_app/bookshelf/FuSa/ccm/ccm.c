/** @file ccm.c 
 *  @brief  CCM Application
 * 
 *  CPU Compare module (CCM) Application
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
 *
 *  This file contains R5F-CPU Safety Example showing usage of R5F Lockstep as a safety mechanism to detect errors in R5F execution. 
 *
 *  \details  R5F-CPU running in locksetpu mode
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */


/* For Timer functions */
#include <ti/osal/osal.h>
#include <ti/drv/sciclient/sciclient.h>

#include "src/ip/r5/sdl_mcu_armss_ccmr5.h"
#include <src/sdl/sdl_ccm.h>

#include "sdl_esm.h"
#include <sdl_types.h>
#include "fusa_osal_interface_autosar.h"
#include "fusa_application.h"
#include <string.h>
#include <stdio.h>
#include "app_log.h"
#include "app_log_Boot.h"
#include "ccm.h"

/* ========================================================================== */
/*                                Macros and typedefs                         */
/* ========================================================================== */
/* Commented -- Can be enabled in Future
*#define SDL_APP_CCM_UART_PRINTS_ENABLED
*/


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

int32_t SDL_ESM_CCM_applicationCallbackFunction(SDL_ESM_Inst esmInst,
                                            SDL_ESM_IntType esmIntrType,
                                            uint32_t grpChannel,
                                            uint32_t index,
                                            uint32_t intSrc,
                                            void *arg);


static int32_t CCM_app_init (void);
#if (SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)
static int32_t App_CCMSelfTest(void);
static int32_t App_CCMSelfTestErrorForce(void);
static int32_t App_CCMInjectError(void);
#endif /*(SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)*/

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#if (SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)
static uint8_t ccm_app_init_success;
#endif	/*(SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)*/

static SDL_CCM_staticRegs gCCMstaticRegs;

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

#if (SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)
/*********************************************************************
 * @fn      App_CCMSelfTest
 *
 * @brief   Execute CCM Self test
 *
 * @param   None
 *
 * @return  0 : Success; < 0 for failures
 */
static int32_t App_CCMSelfTest(void)
{
  /* DD-ID: {56AE42AD-F07A-4e87-A6DB-002E4CBDECD4}*/
    int32_t result;
    int32_t retVal=0;

    #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_MAX,"\n R5F-CPU example application CCM self test: starting");
    #endif

    result = SDL_CCM_selfTest(SDL_CCM_MCU_R5F0,
	                          SDL_CCM_MONITOR_TYPE_OUTPUT_COMPARE_BLOCK,
                              SDL_CCM_SELFTEST_TYPE_NORMAL, 0U,
                              10000000);

    if (result != SDL_PASS ) 
    {
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n R5F-CPU example application CCM self test failed\n");
        #endif
        retVal = -1;
    } 
    else 
    {
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n R5F-CPU example application CCM Self Test complete\n");
        #endif
    }

    return retVal;
}


/*********************************************************************
 * @fn      App_CCMSelfTestErrorForce
 *
 * @brief   Execute CCM Self test with error force
 *
 * @param   None
 *
 * @return  0 : Success; < 0 for failures
 */
static int32_t App_CCMSelfTestErrorForce(void)
{
  /* DD-ID:{55023C15-D352-41b1-B2B3-580CD04F3457}*/
    int32_t result;
    int32_t retVal=0;

    #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_MAX,"\n R5F-CPU example application CCM self test with error forcing: starting");
    #endif

    result = SDL_CCM_selfTest(SDL_CCM_MCU_R5F0,
	                          SDL_CCM_MONITOR_TYPE_OUTPUT_COMPARE_BLOCK,
                              SDL_CCM_SELFTEST_TYPE_ERROR_FORCING, 0U,
                              20000000);

    if (result != SDL_PASS ) 
    {
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n R5F-CPU example application CCM self test with error forcing failed");
        #endif
        retVal = -1;
    } 
    else 
    {
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n R5F-CPU example application CCM Self Test with error forcing complete");
        #endif
    }

    return retVal;
}

/*********************************************************************
 * @fn      App_CCMInjectError
 *
 * @brief   Execute CCM Inject Error test
 *
 * @param   None
 *
 * @return  0 : Success; < 0 for failures
 */
static int32_t App_CCMInjectError(void)
{
  /* DD-ID: {210754D8-02B8-4c1e-9AB6-DB94750974A1}*/
    int32_t result;
    int32_t retVal=0;

    #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_MAX,"\n R5F-CPU example application CCM inject  error: test starting");
    #endif

    result = SDL_CCM_injectError(SDL_CCM_MCU_R5F0, SDL_CCM_MONITOR_TYPE_OUTPUT_COMPARE_BLOCK);

    if (result != SDL_PASS ) 
    {
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n R5F-CPU example application CCM inject failed");
        #endif
        retVal = -1;
    } 
    else 
    {
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n R5F-CPU example application CCM inject Test complete");
        #endif
    }

    return retVal;
}

/*********************************************************************
 * @fn      CCM_runTest
 *
 * @brief   Execute CCM_runTest
 *
 * @param   None
 *
 * @return  0 : Success; < 0 for failures
 */
static int32_t CCM_runTest(uint32_t instanceId)
{
  /* DD-ID: {85250F39-513E-4cfc-A22E-09BBC1417948}*/
	int32_t       testResult = 0;
    SDL_ErrType_t sdlResult;

    if(testResult == 0)
	{
		sdlResult = App_CCMSelfTest();
		if (sdlResult != SDL_PASS)
		{
			#if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
			APP_log(APP_LOG_MAX,"\n R5F-CPU example application CCMSelfTest: failure on line no. %d \n", __LINE__);
			#endif
			testResult = -1;
		}
	}

	if(testResult == 0)
	{
        sdlResult = App_CCMSelfTestErrorForce();
    	if (sdlResult != SDL_PASS)
    	{
    	 	#if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"\n CCMSelfTestErrorForce: failure on line no. %d \n", __LINE__);
            #endif
    		testResult = -1;
    	}
	}

	if(testResult == 0)
	{
        sdlResult = App_CCMInjectError();
        if (sdlResult != SDL_PASS)
    	{
            #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"\n App_CCMInjectError: failure on line no. %d \n", __LINE__);
            #endif
            testResult = -1;
        }
    }

    return (testResult);
}
#endif /*(SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)*/

/*********************************************************************
* @fn      ccm_app_init
*
* @brief   Initializes ccm_app_init
*
* @param   None
*
* @return    None
*/

/* ccm_app_init: Function to initialize/test the CCM on HYDRA3.
*/
static int32_t CCM_app_init (void)
{
  /* DD-ID: {E3274991-1DAB-4955-AD1D-7B790B60AC63}*/
    int32_t result, retValue=0;

    /* Initialize CCM */
    result = SDL_CCM_init(SDL_CCM_MCU_R5F0);
    if (result != SDL_PASS)
    {
#if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
    	/* print error and quit */
    	APP_log(APP_LOG_MAX,"\n CCM_app_init: Error result = %d\n", result);
#endif
    	retValue = -1;
    }
    else
    {
#if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
    	APP_log(APP_LOG_MAX,"\n CCM_Test_init: CCM Init complete \n");
#endif
    }

    /* Verify CCM config */
    result = SDL_CCM_verifyConfig(SDL_CCM_MCU_R5F0);
    if (result != SDL_PASS)
    {
#if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
    	/* print error and quit */
    	APP_log(APP_LOG_MAX,"\n SDL_CCM_verifyConfig: Error result = %d\n", result);
#endif
    	retValue = -1;
    }
    else
    {
#if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
    	APP_log(APP_LOG_MAX,"\n SDL_CCM_verifyConfig: CCM Init complete \n");
#endif
    }

    return retValue;
}

/*********************************************************************
 * @fn      SDL_ESM_CCM_applicationCallbackFunction
 *
 * @brief   Execute SDL_ESM_CCM_applicationCallbackFunction
 *
 * @param   see function parameters
 *
 * @return  0 : Success; < 0 for failures
 */
/* TBD: need to replace SDL_ESM_CCM_applicationCallbackFunction with SDL_ESM_applicationCallbackFunction
* which is a master call back function for in esm.c file for ESM module in HYDRA3.
*/
int32_t SDL_ESM_CCM_applicationCallbackFunction(SDL_ESM_Inst esmInst,
                                            SDL_ESM_IntType esmIntrType,
                                            uint32_t grpChannel,
                                            uint32_t index,
                                            uint32_t intSrc,
                                            void *arg)
{
   /* DD-ID: {7FEA2E04-B600-4f65-934F-1A88620DEA42}*/
    int32_t retVal = 0;
    SDL_CCM_MonitorType monitorType;
    #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_ERR,"\n CCM Call back function called : instType 0x%x, intType 0x%x, " \
                "grpChannel 0x%x, index 0x%x, intSrc 0x%x \n",
                esmInst, esmIntrType, grpChannel, index, intSrc);
    APP_log(APP_LOG_MAX,"\n Take action \n");
    #endif
   
   (void)esmInst;
   (void)esmIntrType;
   (void)grpChannel;
   (void)index;
   (void)arg;

    (void)SDL_CCM_getErrorType(SDL_CCM_MCU_R5F0, intSrc, &monitorType);
    (void)SDL_CCM_clearError(SDL_CCM_MCU_R5F0, monitorType);

	Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_CCM,(uint8_t) TRUE);

   return retVal;
}


/*********************************************************************
* @fn      TASK_ccm_app_init
*
* @brief   Initializes TASK_ccm_app_init
*
* @param   None
*
* @return    None
*/

/* TASK_ccm_app_init: Function to initialize/test the CCM on HYDRA3.
*/
/* define the unlock and lock values */
/* Commented -- Can be enabled in Future
* #define KICK0_UNLOCK_VAL 0x68EF3490
* #define KICK1_UNLOCK_VAL 0xD172BC5A
*/

void TASK_ccm_app_init(void)
{
  /* DD-ID: {9E79A3BE-D0AC-4d35-BB1E-7215273B09F8}*/
    int32_t  testResult = SDL_PASS;

    testResult = CCM_app_init();

    if (testResult == SDL_PASS)
    {
		#if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
		APP_log(APP_LOG_MAX,"\n CCM_app_init: Success\n");
		#endif
        /* Read CCM Static Registers for SDL_CCM_MCU_R5F0 instance and compare it later for errors */
        testResult = SDL_CCM_getStaticRegisters(SDL_CCM_MCU_R5F0, &gCCMstaticRegs);
        if (testResult != SDL_PASS)
        {
            #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"\n SDL_CCM_getStaticRegisters: Read failure for CCM instance: SDL_CCM_MCU_R5F0 on line no. %d \n", __LINE__);
            #endif
        }
        else
        {
            /* Verify CCM Written config for SDL_CCM_MCU_R5F0 instance */
            testResult = SDL_CCM_verifyConfig(SDL_CCM_MCU_R5F0);
            if (testResult != SDL_PASS)
            {
                #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
                APP_log(APP_LOG_MAX,"\n SDL_CCM_verifyConfig: failure for CCM instance: SDL_CCM_MCU_R5F0 on line no. %d \n", __LINE__);
                #endif
            }
            else
            {
#ifdef 	Enable_Printf
        		APP_log(APP_LOG_MAX,"\n SDL_CCM_verifyConfig: Success\n");
#endif
#if (SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)
                ccm_app_init_success = (uint8_t)1;
#endif /*(SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)*/
            }
        }
    }
    else
    {
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n CCM SDL API tests: unsuccessful");
        APP_log(APP_LOG_MAX,"\n CCM Init failed. Exiting the app.\r\n");
        #endif
    }

}

#if (SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)
/*********************************************************************
* @fn      TASK_ccm_app_self_test
*
* @brief   tests ccm module selftest, forces error and injects error
*
* @param   None
*
* @return    None
*/

/* TASK_ccm_app_self_test: Function to test the CCM on HYDRA3.
*/
void TASK_ccm_app_self_test(void)
{
  /* DD-ID: {737185F8-97DE-4cdb-89DF-AE65EEB7DF49}*/
    int32_t  testResult = SDL_PASS;

    if(FALSE != (uint8_t)ccm_app_init_success)
    {
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n CCM Functional Test \r\n");
        #endif
        /* Run the test for diagnostics first */
        testResult = CCM_runTest(SDL_CCM_MCU_R5F0);

        if (testResult == SDL_PASS)
        {
            #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"\n All tests have passed. \r\n");
            #endif

        }
        else
        {
            #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
            APP_log(APP_LOG_MAX,"\n Some tests have failed. \r\n");
            #endif
        }

        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n CCM Example Application: Complete");
        #endif
    }
}
#endif /*(SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)*/

/*********************************************************************
* @fn      TASK_ccm_app_MainFunction
*
* @brief   Function to check CCM health.
*
* @param   None
*
* @return    None
*/

/* TASK_ccm_app_MainFunction: Function to test the CCM on HYDRA3.
*/
void TASK_ccm_app_MainFunction(void)
{
  /* DD-ID: {70F6F43B-7655-4987-AFFE-F4E0AE8F74C7}*/
    /* Declaration of variables */
    int32_t  testResult;
    SDL_CCM_staticRegs staticRegs;
    const uint8_t *tempRegPtr = (uint8_t *)&staticRegs;
    const uint8_t *regPtr = (uint8_t *)&gCCMstaticRegs;

    /* Read CCM Static Registers for SDL_CCM_MCU_R5F0 instance */
    testResult = SDL_CCM_getStaticRegisters(SDL_CCM_MCU_R5F0, &staticRegs);
    if (testResult != SDL_PASS)
    {
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n SDL_CCM_getStaticRegisters: Read failure for CCM instance: SDL_CCM_MCU_R5F0 on line no. %d \n", __LINE__);
        #endif
    }
    /* for SDL_PASS */
    /* Check current read of staticRegs matches the intial gCCMstaticRegs */
    /*else if(0x00 != memcmp((const SDL_CCM_staticRegs*)&staticRegs, (const SDL_CCM_staticRegs*)&gCCMstaticRegs, sizeof(SDL_CCM_staticRegs)))*/
    else if(0x00 != memcmp((const uint8_t*)regPtr, (const uint8_t*)tempRegPtr, sizeof(SDL_CCM_staticRegs)))
    {
        testResult = SDL_EFAIL;
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n SDL_CCM_getStaticRegisters: Compare failure for CCM instance: SDL_CCM_MCU_R5F0 on line no. %d \n", __LINE__);
        #endif
    }
    else
    {
        #if defined (SDL_APP_CCM_UART_PRINTS_ENABLED)
        APP_log(APP_LOG_MAX,"\n SDL_CCM_getStaticRegisters: PASS for CCM instance: SDL_CCM_MCU_R5F0\n");
        #endif
    }

    if(testResult != SDL_PASS)
    {
    	Fusa_Application_SetCcmSafetyCriticalConfigFailFlag();
    	Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_CCM, (uint8_t)TRUE);
    }
    
}
/* Nothing past this point */
#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
