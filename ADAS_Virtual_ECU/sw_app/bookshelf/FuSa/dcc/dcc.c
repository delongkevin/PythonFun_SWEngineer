/*
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
 *
 */

 /**
 *  \file     main.c
 *
 *  \brief    This file contains DCC Function test code.
 *
 *  \details  DCC tests
 **/

/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
#include "dcc.h"
#include <sdl_dcc.h>
#include "sdl_esm.h"
#include <sdl_types.h>
#include "fusa_application.h"
#include <ti/osal/osal.h>
#include <ti/drv/sciclient/sciclient.h>
#include "fusa_osal_interface_autosar.h"
#include <include/soc/j721s2/sdlr_intr_wkup_esm0.h>
#include <include/soc/j721s2/sdlr_intr_esm0.h>
#include <include/soc/j721s2/sdlr_intr_mcu_esm0.h>
#include "app_log.h"
#include "app_log_Boot.h"


/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/
/* None */

#define APP_DCC_REF_CLOCK_FREQ_IN_HZ        (19200000U)
#define APP_MCU_DCC0_TEST_CLOCK1_FREQ_IN_HZ (333333333U)
#define APP_MCU_DCC1_TEST_FICLK_FREQ_IN_HZ  (166666666U)
#define APP_DCC4_TEST_CLOCKSRC4_FREQ_IN_HZ  (250000000U)
#define APP_DCC4_TEST_CLOCKSRC5_FREQ_IN_HZ  (250000000U)
#define APP_DCC4_TEST_CLOCKSRC2_FREQ_IN_HZ  (266625000U)
#define APP_DCC6_TEST_CLOCK1_FREQ_IN_HZ     (125000000U)
#define APP_DCC8_TEST_CLOCKSRC6_FREQ_IN_HZ  (200000000U)

/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/

/*#define SDL_APP_DCC_UART_PRINTS_ENABLED*/

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

#if ( SDL_APP_DCC_ENABLED == SDL_APP_ON )
static void SDL_PLL_getStaticRegs(SDL_PLL_staticRegs* regs);
#endif

/*===========================================================================*/
/*                         Global Variables                                  */
/*===========================================================================*/

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined (DEBUG_DCC_MAGNA)
sdlDccTest_t  sdlDccTestList[] = {
    {SDL_DCC_funcTest, "DCC FUNCTION TEST" ,     SDL_APP_TEST_NOT_RUN },
    {NULL,             "TERMINATING CONDITION",  SDL_APP_TEST_NOT_RUN }
};

#endif /*DEBUG_DCC_MAGNA*/


SDL_DCC_staticRegs DCC_staticRegs[SDL_DCC_MAX_INSTANCE];
SDL_APP_DCC_cfg_t SDL_APP_DCC_cfg[SDL_APP_NUM_DCC_INST] = {
    {
        .instEnabled = true,
        .instance = SDL_DCC_INST_MCU_DCC0,
        .mode = SDL_DCC_MODE_CONTINUOUS,
        .srcClk = SDL_DCC_CLK0_SRC_CLOCK0_0,
        .srcFreq = APP_DCC_REF_CLOCK_FREQ_IN_HZ,
        .testClk = SDL_DCC_CLK1_SRC_CLOCK1,
        .testFreq = APP_MCU_DCC0_TEST_CLOCK1_FREQ_IN_HZ, 
    }, /* MCU_SYSCLK/3 */
    {
        .instEnabled = true,
        .instance = SDL_DCC_INST_MCU_DCC1,
        .mode = SDL_DCC_MODE_CONTINUOUS,
        .srcClk = SDL_DCC_CLK0_SRC_CLOCK0_0,
        .srcFreq = APP_DCC_REF_CLOCK_FREQ_IN_HZ,
        .testClk = SDL_DCC_CLK1_SRC_FICLK,
        .testFreq = APP_MCU_DCC1_TEST_FICLK_FREQ_IN_HZ, 
    }, /* MCU_SYSCLK/6 */
    {
        .instEnabled = true,
        .instance = SDL_DCC_INST_DCC8,
        .mode = SDL_DCC_MODE_CONTINUOUS,
        .srcClk = SDL_DCC_CLK0_SRC_CLOCK0_0,
        .srcFreq = APP_DCC_REF_CLOCK_FREQ_IN_HZ,
        .testClk = SDL_DCC_CLK1_SRC_CLOCKSRC6,
        .testFreq = APP_DCC8_TEST_CLOCKSRC6_FREQ_IN_HZ, 
    }, /* MAIN_PLL3_HSDIV1_CLKOUT */
    {
        .instEnabled = false,
        .instance = SDL_DCC_INST_DCC4,
        .mode = SDL_DCC_MODE_SINGLE_SHOT_2,
        .srcClk = SDL_DCC_CLK0_SRC_CLOCK0_0,
        .srcFreq = APP_DCC_REF_CLOCK_FREQ_IN_HZ,
        .testClk = SDL_DCC_CLK1_SRC_CLOCKSRC4,
        .testFreq = APP_DCC4_TEST_CLOCKSRC4_FREQ_IN_HZ, 
    }, /* MAIN_PLL14_HSDIV0_CLKOUT_DIV4 */
    {
        .instEnabled = false,
        .instance = SDL_DCC_INST_DCC4,
        .mode = SDL_DCC_MODE_SINGLE_SHOT_2,
        .srcClk = SDL_DCC_CLK0_SRC_CLOCK0_0,
        .srcFreq = APP_DCC_REF_CLOCK_FREQ_IN_HZ,
        .testClk = SDL_DCC_CLK1_SRC_CLOCKSRC5,
        .testFreq = APP_DCC4_TEST_CLOCKSRC5_FREQ_IN_HZ, 
    }, /* MAIN_PLL14_HSDIV1_CLKOUT_DIV4 */
    {
        .instEnabled = true,
        .instance = SDL_DCC_INST_DCC6,
        .mode = SDL_DCC_MODE_CONTINUOUS,
        .srcClk = SDL_DCC_CLK0_SRC_CLOCK0_0,
        .srcFreq = APP_DCC_REF_CLOCK_FREQ_IN_HZ,
        .testClk = SDL_DCC_CLK1_SRC_CLOCK1,
        .testFreq = APP_DCC6_TEST_CLOCK1_FREQ_IN_HZ, 
    }, /* MAIN_SYSCLK0_CLK1/4 */
    {
        .instEnabled = true,
        .instance = SDL_DCC_INST_DCC4,
        .mode = SDL_DCC_MODE_CONTINUOUS,
        .srcClk = SDL_DCC_CLK0_SRC_CLOCK0_0,
        .srcFreq = APP_DCC_REF_CLOCK_FREQ_IN_HZ,
        .testClk = SDL_DCC_CLK1_SRC_CLOCKSRC2,
        .testFreq = APP_DCC4_TEST_CLOCKSRC2_FREQ_IN_HZ, 
    }, /* MAIN_PLL12_HSDIV0_CLKOUT_DIV4 */
};
static const SDL_PLL_staticRegs PLL_staticRegs_cfg = 
{
    0x30801, /* MCU_PLL0 */
    0x1,
    0x1F0801, /* MCU_PLL1 */
    0x1,
    0x1F0801, /* MCU_PLL2 */
    0x1,
    0x1FF0801, /* PLL0 */
    0x1,
    0x1FF0801, /* PLL1 */
    0x1,
    0xFF0801, /* PLL2 */
    0x1,
    0x70801,   /* PLL4 */
    0x1,
    0x30801, /* PLL5 */
    0x1,
    0x10801, /* PLL6 */
    0x1,
    0x10801, /* PLL7 */
    0x1,
    0x10801, /* PLL8 */
    0x0,
    0x10801, /* PLL12 */
    0x0,
    0x70801, /* PLL14 */
    0x1,
    0x30801, /* PLL16 */
    0x1,
    0x30801, /* PLL17 */
    0x1,
    0x30801, /* PLL19 */
    0x1,
    0x30801, /* PLL25 */
    0x1,
    0x10801, /* PLL27 */
    0x0,
    0x10801, /* PLL28 */
    0x0,
};

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*===========================================================================*/
/*                   Local Function definitions                              */
/*===========================================================================*/


/*===========================================================================*/
/*                         Function definitions                              */
/*===========================================================================*/

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
void dcc_init (void)
{
  /* DD-ID: {A1084832-B7D5-4d9f-87B9-892684CAE755}*/
#if ( SDL_APP_DCC_SELFTEST_ENABLED )
    /* Declarations of variables */
    int32_t    testResult = SDL_APP_TEST_PASS;
    int32_t    i, result;
    void *ptr = (void *)&arg;

    UART_printf("\n DCC Function Test Application\r\n");

    for ( i = 0; sdlDccTestList[i].testFunction != NULL; i++)
    {
        testResult = sdlDccTestList[i].testFunction();
        sdlDccTestList[i].testStatus = testResult;
    }

    testResult = SDL_APP_TEST_PASS;
    for ( i = 0; sdlDccTestList[i].testFunction != NULL; i++)
    {
        if (sdlDccTestList[i].testStatus != SDL_APP_TEST_PASS)
        {
            UART_printf("\nTest Name: %s  FAILED \n", sdlDccTestList[i].name);
            testResult = SDL_APP_TEST_FAILED;
            break;
        }
        else
        {
            UART_printf("\nTest Name: %s  PASSED \n", sdlDccTestList[i].name);
        }
    }

    if (testResult == SDL_APP_TEST_PASS)
    {
        UART_printStatus("\n All tests have passed. \n");
    }
    else
    {
        UART_printStatus("\n Few/all tests Failed \n");
    }
#else
    for(uint32_t i = 0u; i < SDL_APP_NUM_DCC_INST; i++)
    {
        if (SDL_APP_DCC_cfg[i].instEnabled == true)
        {
            (void)dcc_init_inst(i);
        }
    }
#endif
}

#if ( SDL_APP_DCC_ENABLED == SDL_APP_ON )
static void SDL_PLL_getStaticRegs(SDL_PLL_staticRegs* regs)
{
  /* DD-ID: {E514A761-FB75-4104-B1CB-D6D44054750C}*/
    SDL_main_pll_mmr_cfgRegs* pll_main = (SDL_main_pll_mmr_cfgRegs*)SAFETY_MAIN_PLL_MMR_CFG_REGS_BASE;
    SDL_mcu_pll_mmr_cfgRegs* pll_mcu   = (SDL_mcu_pll_mmr_cfgRegs*)SAFETY_MCU_PLL_MMR_CFG_REGS_BASE;

    sdl_load_pll_cfg (MCU, 0, pll_mcu);
    sdl_load_pll_lock(MCU, 0, pll_mcu);
    sdl_load_pll_cfg (MCU, 1, pll_mcu);
    sdl_load_pll_lock(MCU, 1, pll_mcu);
    sdl_load_pll_cfg (MCU, 2, pll_mcu);
    sdl_load_pll_lock(MCU, 2, pll_mcu);

    sdl_load_pll_cfg (MAIN, 0, pll_main);
    sdl_load_pll_lock(MAIN, 0, pll_main);
    sdl_load_pll_cfg (MAIN, 1, pll_main);
    sdl_load_pll_lock(MAIN, 1, pll_main);
    sdl_load_pll_cfg (MAIN, 2, pll_main);
    sdl_load_pll_lock(MAIN, 2, pll_main);
    sdl_load_pll_cfg (MAIN, 4, pll_main);
    sdl_load_pll_lock(MAIN, 4, pll_main);
    sdl_load_pll_cfg (MAIN, 5, pll_main);
    sdl_load_pll_lock(MAIN, 5, pll_main);
    sdl_load_pll_cfg (MAIN, 6, pll_main);
    sdl_load_pll_lock(MAIN, 6, pll_main);
    sdl_load_pll_cfg (MAIN, 7, pll_main);
    sdl_load_pll_lock(MAIN, 7, pll_main);
    sdl_load_pll_cfg (MAIN, 8, pll_main);
    sdl_load_pll_lock(MAIN, 8, pll_main);
    sdl_load_pll_cfg (MAIN, 12, pll_main);
    sdl_load_pll_lock(MAIN, 12, pll_main);
    sdl_load_pll_cfg (MAIN, 14, pll_main);
    sdl_load_pll_lock(MAIN, 14, pll_main);
    sdl_load_pll_cfg (MAIN, 16, pll_main);
    sdl_load_pll_lock(MAIN, 16, pll_main);
    sdl_load_pll_cfg (MAIN, 17, pll_main);
    sdl_load_pll_lock(MAIN, 17, pll_main);
    sdl_load_pll_cfg (MAIN, 19, pll_main);
    sdl_load_pll_lock(MAIN, 19, pll_main);
    sdl_load_pll_cfg (MAIN, 25, pll_main);
    sdl_load_pll_lock(MAIN, 25, pll_main);
    sdl_load_pll_cfg (MAIN, 27, pll_main);
    sdl_load_pll_lock(MAIN, 27, pll_main);
    sdl_load_pll_cfg (MAIN, 28, pll_main);
    sdl_load_pll_lock(MAIN, 28, pll_main);
}

/* Periodic function for DCC */
void dcc_MainFunction(void)
{   
  /* DD-ID: {4490BD8C-6481-49ac-AFA3-B87D56771927}*/
#if ( SDL_APP_DCC_ENABLED == SDL_APP_ON )
	static SDL_PLL_staticRegs PLL_staticRegs;
    SDL_DCC_staticRegs staticRegs;

    uint8_t *tempRegPtr = (uint8_t *)&staticRegs;
    uint8_t *regPtr;

    (void)SDL_DCC_getStaticRegs(SDL_DCC_INST_DCC0, &staticRegs);
    SDL_PLL_getStaticRegs(&PLL_staticRegs);

    /* Innocent until proven guilty */
    Sdl_Application_ClearDccErrorFlag();
    for (uint32_t i = 0; i < SDL_APP_NUM_DCC_INST; i++)
    {
        if (SDL_APP_DCC_cfg[i].instEnabled == true)
        {
            (void)SDL_DCC_getStaticRegs(SDL_APP_DCC_cfg[i].instance, &staticRegs);
            regPtr = (uint8_t *)&(DCC_staticRegs[SDL_APP_DCC_cfg[i].instance]);
            if (0 != memcmp((const uint8_t*)tempRegPtr, (const uint8_t*)regPtr, sizeof(staticRegs)))
            {
                Sdl_Application_SetDccErrorFlag();
            }
        }
    }

    tempRegPtr =  (uint8_t *)&PLL_staticRegs;
    regPtr =  (uint8_t *)&PLL_staticRegs_cfg;
	if (0 != memcmp((const uint8_t*)tempRegPtr, (const uint8_t*)regPtr, sizeof(PLL_staticRegs)))
    {
        Sdl_Application_SetPLLreadbackErrorFlag();
    }
    else
    {
        Sdl_Application_ClearPLLreadbackErrorFlag();
    }
#endif
}
#endif
#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Nothing past this point */
