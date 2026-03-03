/*
 *   Copyright (c) Texas Instruments Incorporated 2022
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
 *  \file     mtog_main.c
 *
 *  \brief    This file contains MTOG Example code for R5 core.
 *
 *  \details  MTOG Safety Example
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "mtog_main.h"
#include "mtog_func.h"
#include "fusa_application.h"
#include <ti/drv/sciclient/sciclient.h>
#include <ti/osal/osal.h>
#include <ti/osal/TimerP.h>

#ifdef UNITY_INCLUDE_CONFIG_H
#include <test/unity/src/unity.h>
#include <test/unity/config/unity_config.h>
#endif

/* #define DEBUG_TEST_CPU_FREQUENCY */

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* define the unlock and lock values */
#define KICK0_UNLOCK_VAL (0x68EF3490)
#define KICK1_UNLOCK_VAL (0xD172BC5A)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

MTOG_InstHandle_t MTOG_InstHandleArray[SDL_INSTANCE_MTOG_MAX+1] =
{
    /* MAIN_MTOG0 */
    {
        .instanceName           = "MAIN_MTOG0",
        .instance               = SDL_INSTANCE_MAIN_MTOG0,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET0_TIMED_OUT_0,
        .instEn                 = true,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG1 */
    {
        .instanceName           = "MAIN_MTOG1",
        .instance               = SDL_INSTANCE_MAIN_MTOG1,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET1_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG4 */
    {
        .instanceName           = "MAIN_MTOG4",
        .instance               = SDL_INSTANCE_MAIN_MTOG4,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET4_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG5 */
    {
        .instanceName           = "MAIN_MTOG5",
        .instance               = SDL_INSTANCE_MAIN_MTOG5,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET5_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG14 */
    {
        .instanceName           = "MAIN_MTOG14",
        .instance               = SDL_INSTANCE_MAIN_MTOG14,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_NAVSS0_VIRTSS_VIRTSS_FFI_PVU0_DST_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG24 */
    {
        .instanceName           = "MAIN_MTOG24",
        .instance               = SDL_INSTANCE_MAIN_MTOG24,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET24_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG25 */
    {
        .instanceName           = "MAIN_MTOG25",
        .instance               = SDL_INSTANCE_MAIN_MTOG25,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET25_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG32 */
    {
        .instanceName           = "MAIN_MTOG32",
        .instance               = SDL_INSTANCE_MAIN_MTOG32,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET32_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG33 */
    {
        .instanceName           = "MAIN_MTOG33",
        .instance               = SDL_INSTANCE_MAIN_MTOG33,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET33_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG34 */
    {
        .instanceName           = "MAIN_MTOG34",
        .instance               = SDL_INSTANCE_MAIN_MTOG34,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET34_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG35 */
    {
        .instanceName           = "MAIN_MTOG35",
        .instance               = SDL_INSTANCE_MAIN_MTOG35,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET35_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG36 */
    {
        .instanceName           = "MAIN_MTOG36",
        .instance               = SDL_INSTANCE_MAIN_MTOG36,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET36_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG37 */
    {
        .instanceName           = "MAIN_MTOG37",
        .instance               = SDL_INSTANCE_MAIN_MTOG37,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET37_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG38 */
    {
        .instanceName           = "MAIN_MTOG38",
        .instance               = SDL_INSTANCE_MAIN_MTOG38,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET38_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MAIN_MTOG39 */
    {
        .instanceName           = "MAIN_MTOG39",
        .instance               = SDL_INSTANCE_MAIN_MTOG39,
        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET39_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MCU_MTOG0 */
    {
        .instanceName           = "MCU_MTOG0",
        .instance               = SDL_INSTANCE_MCU_MTOG0,
        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_MASTER_SAFETY_GASKET0_TIMED_OUT_0,
        .instEn                 = true,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MCU_MTOG16 */
    {
        .instanceName           = "MCU_MTOG16",
        .instance               = SDL_INSTANCE_MCU_MTOG16,
        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET16_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MCU_MTOG17 */
    {
        .instanceName           = "MCU_MTOG17",
        .instance               = SDL_INSTANCE_MCU_MTOG17,
        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET17_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MCU_MTOG18 */
    {
        .instanceName           = "MCU_MTOG18",
        .instance               = SDL_INSTANCE_MCU_MTOG18,
        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET18_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MCU_MTOG19 */
    {
        .instanceName           = "MCU_MTOG19",
        .instance               = SDL_INSTANCE_MCU_MTOG19,
        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET19_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MCU_MTOG20 */
    {
        .instanceName           = "MCU_MTOG20",
        .instance               = SDL_INSTANCE_MCU_MTOG20,
        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET20_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MCU_MTOG21 */
    {
        .instanceName           = "MCU_MTOG21",
        .instance               = SDL_INSTANCE_MCU_MTOG21,
        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET21_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MCU_MTOG22 */
    {
        .instanceName           = "MCU_MTOG22",
        .instance               = SDL_INSTANCE_MCU_MTOG22,
        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET22_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
    /* MCU_MTOG23 */
    {
        .instanceName           = "MCU_MTOG23",
        .instance               = SDL_INSTANCE_MCU_MTOG23,
        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MASTER_SAFETY_GASKET23_TIMED_OUT_0,
        .instEn                 = false,
		.timeOut                = SDL_MTOG_VAL_64K
    },
};
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */
#ifdef UNITY_INCLUDE_CONFIG_H
/*
 *  ======== Unity set up and tear down ========
 */
void setUp(void)
{
  /* DD-ID: {70AA32D6-F09F-4ab9-92B4-FCD2E7DD6E09}*/
    /* Do nothing */
}

void tearDown(void)
{
  /* DD-ID: {D723DC61-5C14-4410-91B0-C8CC3477F4FD}*/
    /* Do nothing */
}
#endif

static int32_t MTOG_appInitBoard(void)
{
  /* DD-ID: {14480D94-07AF-4835-BF17-800B3704258C}*/
    Board_initCfg     boardCfg;
    Board_STATUS      boardStatus;
    int32_t           testResult = SDL_PASS;
    uint64_t          mcuClkFreq;
#ifdef DEBUG_TEST_CPU_FREQUENCY
    volatile uint64_t prevTimeStamp, curTimeStamp, timeStampDiff = 0;
    int i;
#endif

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        testResult = SDL_EFAIL;
        UART_printf("[Error] Board init failed!!\n");
    }

    /* Following code is needed to set Osal timing */
#if defined (SOC_J7200) || defined (SOC_J721S2)
    /* Get the clock frequency */
    testResult = Sciclient_pmGetModuleClkFreq(TISCI_DEV_MCU_R5FSS0_CORE0,
                                              TISCI_DEV_MCU_R5FSS0_CORE0_CPU_CLK,
                                              &mcuClkFreq,
                                              SCICLIENT_SERVICE_WAIT_FOREVER);
#else
#error "SOC NOT supported please check"
#endif
    if (testResult == 0)
    {
        Osal_HwAttrs  hwAttrs;
        uint32_t      ctrlBitmap;

        testResult = Osal_getHwAttrs(&hwAttrs);
        if (testResult == 0)
        {
            /*
             * Change the timer input clock frequency configuration
               based on R5 CPU clock configured
             */
            hwAttrs.cpuFreqKHz = (int32_t)(mcuClkFreq/1000U);
            ctrlBitmap         = OSAL_HWATTR_SET_CPU_FREQ;
            testResult = Osal_setHwAttrs(ctrlBitmap, &hwAttrs);
        }
    }
    UART_printf("mcuClkFreq %d\n", (uint32_t)mcuClkFreq);

#ifdef DEBUG_TEST_CPU_FREQUENCY
    /* Print 10 dots, with 10 seconds elapsing between each dot */
    for (i = 0; i < 10; i++)
    {
        prevTimeStamp = TimerP_getTimeInUsecs();

        do
        {
            curTimeStamp = TimerP_getTimeInUsecs();
            timeStampDiff = curTimeStamp - prevTimeStamp;
        } while(timeStampDiff < 10000000U);
        UART_printf(".");
    }
#endif
    return (testResult);
}

void test_sdl_mtog_test_app(void)
{
  /* DD-ID: {D58ABE4E-CDD3-468a-8469-A4AC12373620}*/
    /* @description: Run mtog tests

    @cores: mcu1_0 */
    int32_t  testResult;

    *((uint32_t *)(SDL_CTRL_MMR0_CFG0_BASE + SDL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK0)) = KICK0_UNLOCK_VAL;
    *((uint32_t *)(SDL_CTRL_MMR0_CFG0_BASE + SDL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK1)) = KICK1_UNLOCK_VAL;

    *((uint32_t *)(SDL_MCU_CTRL_MMR0_CFG0_BASE + SDL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0)) = KICK0_UNLOCK_VAL;
    *((uint32_t *)(SDL_MCU_CTRL_MMR0_CFG0_BASE + SDL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1)) = KICK1_UNLOCK_VAL;

    testResult = MTOG_func();

    if (testResult == SDL_PASS)
    {
        sdlApp_appLogPrintf("\r\n MTOG Saftey Example passed. \r\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_PASS();
#endif
    }
    else
    {
        sdlApp_appLogPrintf("\r\nMTOG Saftey Example failed. \r\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_FAIL();
#endif
    }
}

void mtog_init(void)
{
  /* DD-ID: {58D324EF-99D9-4b0d-A10D-FD11FBF2BA3E}*/
    /* @description: Run mtog tests

    @cores: mcu1_0 */
    int32_t  testResult;
	uint32_t instanceIndex;

    *((uint32_t *)(SDL_CTRL_MMR0_CFG0_BASE + SDL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK0)) = KICK0_UNLOCK_VAL;
    *((uint32_t *)(SDL_CTRL_MMR0_CFG0_BASE + SDL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK1)) = KICK1_UNLOCK_VAL;

    *((uint32_t *)(SDL_MCU_CTRL_MMR0_CFG0_BASE + SDL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0)) = KICK0_UNLOCK_VAL;
    *((uint32_t *)(SDL_MCU_CTRL_MMR0_CFG0_BASE + SDL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1)) = KICK1_UNLOCK_VAL;

#if (SDL_APP_MTOG_SELFTEST_ENABLED == SDL_APP_ON)

    testResult = MTOG_func();

    if (testResult == SDL_PASS)
    {
        sdlApp_appLogPrintf("\r\n MTOG Saftey Example passed. \r\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_PASS();
#endif
    }
    else
    {
        sdlApp_appLogPrintf("\r\nMTOG Saftey Example failed. \r\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_FAIL();
#endif
    }
#else
    SDL_MTOG_Inst currMtogInst = SDL_INSTANCE_MAIN_MTOG0;
    for ( currMtogInst = SDL_INSTANCE_MAIN_MTOG0; currMtogInst<=(SDL_INSTANCE_MTOG_MAX); currMtogInst++ ){
        if ( true == MTOG_InstHandleArray[currMtogInst].instEn )
        {
            (void)MTOG_AppInit( &MTOG_InstHandleArray[currMtogInst] );
        }
    }
#endif
}

void test_sdl_mtog_test_app_runner(void)
{
  /* DD-ID:{2C15A8B9-927A-46f9-8DB9-A66DF4752D3E}*/
    /* @description: Test runner for MTOG tests

       @cores: mcu1_0 */

#ifdef UNITY_INCLUDE_CONFIG_H
    UNITY_BEGIN();
    RUN_TEST(test_sdl_mtog_test_app);
    UNITY_END();
    /* Function to print results defined in our unity_config.h file */
    print_unityOutputBuffer_usingUARTstdio();
#else
    test_sdl_mtog_test_app();
#endif
}

#if 0
int32_t main(void)
{
  /* DD-ID: {177C6830-FE65-411f-83BD-4C792E473A53}*/
    /* Declaration of variables */
    int32_t  testResult;

    /* Init Board */
    testResult = MTOG_appInitBoard();

    *((uint32_t *)(SDL_CTRL_MMR0_CFG0_BASE + SDL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK0)) = KICK0_UNLOCK_VAL;
    *((uint32_t *)(SDL_CTRL_MMR0_CFG0_BASE + SDL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK1)) = KICK1_UNLOCK_VAL;

    if (testResult == SDL_PASS)
    {
        UART_printf("\nMTOG Safety Example\r\n");
        test_sdl_mtog_test_app_runner();
    }

    return (0);
}
#endif

/* Nothing past this point */

