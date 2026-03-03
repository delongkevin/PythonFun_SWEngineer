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
 *  \file     main.h
 *
 *  \brief    This file contains DCC Function test code declarations
 *
 **/

/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
/*===========================================================================*/
#include <sdl_dcc.h>
#include <sdl_esm.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <src/sdl/sdl_types.h>
#include <src/sdl/hw_types.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>
#include <ti/osal/osal.h>
#include <src/ip/sdl_ip_esm.h>
#include <src/sdl/sdl_esm.h>
#include <sdlr_main_pll_mmr.h>
#include <sdlr_mcu_pll_mmr.h>

/* Interrupt Registrations */
#ifdef UNITY_INCLUDE_CONFIG_H
#include <ti/build/unit-test/Unity/src/unity.h>
#include <ti/build/unit-test/config/unity_config.h>
#endif


#if !defined(SDL_DCC_TEST_H)
#define SDL_DCC_TEST_H

/* ========================================================================== */
/*                     Dependant macros in sdl_dcc_funcTest.c                  */
/* ========================================================================== */

#define APP_DCC_STR                     "SDL DCC FUNCTION TEST"
/**< Example Common display string */
#define APP_DCC_MODULE_INST             (SDL_DCC0_BASE)
/**< Instance of DCC. While changing the instance, ensure update clock sources*/
#define APP_DCC_MODE                    (SDL_DCC_MODE_CONTINUOUS)
/**< One Shot mode, Stop counting when Counter 1, reaches 0. */
#define APP_DCC_SRC0_MAX_VAL            (0xFFFFFU)
/**< Maximum value that can be held in the COUNT0 register (ref clock) */
#define APP_DCC_SRC0_VALID_MAX_VAL      (0x0FFFFU)
/**< Maximum value that can be held in the VALID0 register (ref clock) */
#define APP_DCC_SRC1_MAX_VAL            (0xFFFFFU)
/**< Maximum value that can be held in the COUNT1 register (test clock) */

/* Defines that control the clock inputs to DCC and allowed variance */
#define APP_DCC_REF_CLOCK_SRC_0         (SDL_DCC_CLK0_SRC_CLOCK0_1)
#define APP_DCC_TEST_CLOCK_SRC_1        (SDL_DCC_CLK1_SRC_CLOCKSRC3)

#define APP_DCC_TEST_CLOCK_SRC_1_DRIFT  (5U)
/**< Allowed drift in percentage (+/-) */

#if defined (SOC_J721E) || defined (SOC_J7200)
#define APP_DCC_REF_CLOCK_FREQ_IN_KHZ   (19200U)
/**< Clock source for Counter 0, 19.2 MHz for J721e/J7200 */
#define APP_DCC_TEST_CLOCK_FREQ_IN_KHZ  (333334U)
/**< Expected test clock frequency in KHz */
/**< Clock source for Counter 1, 333 MHz for DRA80x/AM65x */
#define APP_DCC_TEST_CLOCK_SRC_1_HIGHER (DCC_DCCCLKSRC1_CLKSRC_2)
/**< Clock source for Counter 1, expected to be higher than
        APP_DCC_TEST_CLOCK_SRC_1, in this Test to simulate an error*/
#elif defined (SOC_AM64X)
#define APP_DCC_REF_CLOCK_FREQ_IN_KHZ   (25000U)
/**< Clock source for Counter 0, 25 MHz for AM64x */
#define APP_DCC_TEST_CLOCK_FREQ_IN_KHZ  (200000U)
/**< Expected test clock frequency in KHz */
/**< Clock source for Counter 1, 200 MHz for AM64x */
#define APP_DCC_TEST_CLOCK_SRC_1_HIGHER (DCC_DCCCLKSRC1_CLKSRC_2)
/**< Clock source for Counter 1, expected to be higher than
        APP_DCC_TEST_CLOCK_SRC_1, in this Test to simulate an error*/
#else
#define APP_DCC_REF_CLOCK_FREQ_IN_KHZ   (25000U)
/**< Clock source for Counter 0, 25 MHz for DRA80x/AM65x */
#define APP_DCC_TEST_CLOCK_FREQ_IN_KHZ  (60000U)
/**< Expected test clock frequency in KHz */
/**< Clock source for Counter 1, 60 MHz for DRA80x/AM65x */
#define APP_DCC_TEST_CLOCK_SRC_1_HIGHER (DCC_DCCCLKSRC1_CLKSRC_1)
/**< Clock source for Counter 1, expected to be higher than
        APP_DCC_TEST_CLOCK_SRC_1, in this Test to simulate an error.
        80 MHz for DRA80x/AM65x */
#endif

#define SAFETY_MCU_PLL_MMR_CFG_REGS_BASE  (0x40D00000)
#define SAFETY_MAIN_PLL_MMR_CFG_REGS_BASE (0x00680000)

#define sdl_load_pll_cfg(DOMAIN, NUM, PTR) (((regs)->DOMAIN##_PLL##NUM##_CFG) = (uint32_t)((PTR)->PLL##NUM##_CFG) \
& (SDL_##DOMAIN##_PLL_MMR_CFG_PLL##NUM##_CFG_HSDIV_PRSNT_MASK \
 | SDL_##DOMAIN##_PLL_MMR_CFG_PLL##NUM##_CFG_SSM_TYPE_MASK \
 | SDL_##DOMAIN##_PLL_MMR_CFG_PLL##NUM##_CFG_SSM_WVTBL_MASK \
 | SDL_##DOMAIN##_PLL_MMR_CFG_PLL##NUM##_CFG_PLL_TYPE_MASK))
/* e.g. regs->MCU_PLL0_CFG = pll_mcu->PLL0_CFG & (SDL_MCU_PLL_MMR_CFG_PLL0_CFG_HSDIV_PRSNT_MASK 
  | SDL_MCU_PLL_MMR_CFG_PLL0_CFG_SSM_TYPE_MASK | SDL_MCU_PLL_MMR_CFG_PLL0_CFG_SSM_WVTBL_MASK
  | SDL_MCU_PLL_MMR_CFG_PLL0_CFG_PLL_TYPE_MASK); */
#define sdl_load_pll_lock(DOMAIN, NUM, PTR) (((regs)->DOMAIN##_PLL##NUM##_LOCKKEY0_UNLOCKED) = \
		(uint32_t)((PTR)->PLL##NUM##_LOCKKEY0) & (SDL_##DOMAIN##_PLL_MMR_CFG_PLL##NUM##_LOCKKEY0_UNLOCKED_MASK))
/* e.g. regs->MCU_PLL0_LOCKKEY0_UNLOCKED = pll_mcu->PLL0_LOCKKEY0 & SDL_MCU_PLL_MMR_CFG_PLL0_LOCKKEY0_UNLOCKED_MASK;*/

/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/

/* Define the test interface */
typedef struct sdlDccTest_s
{
    int32_t  (*testFunction)(void);   /* The code that runs the test */
    char      *name;                  /* The test name */
    int32_t    testStatus;            /* Test Status */
} sdlDccTest_t;

typedef struct _SDL_PLL_staticRegs 
{
    uint32_t MCU_PLL0_CFG;
    uint32_t MCU_PLL0_LOCKKEY0_UNLOCKED;
    uint32_t MCU_PLL1_CFG;
    uint32_t MCU_PLL1_LOCKKEY0_UNLOCKED;
    uint32_t MCU_PLL2_CFG;
    uint32_t MCU_PLL2_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL0_CFG;
    uint32_t MAIN_PLL0_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL1_CFG;
    uint32_t MAIN_PLL1_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL2_CFG;
    uint32_t MAIN_PLL2_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL4_CFG;
    uint32_t MAIN_PLL4_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL5_CFG;
    uint32_t MAIN_PLL5_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL6_CFG;
    uint32_t MAIN_PLL6_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL7_CFG;
    uint32_t MAIN_PLL7_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL8_CFG;
    uint32_t MAIN_PLL8_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL12_CFG;
    uint32_t MAIN_PLL12_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL14_CFG;
    uint32_t MAIN_PLL14_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL16_CFG;
    uint32_t MAIN_PLL16_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL17_CFG;
    uint32_t MAIN_PLL17_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL19_CFG;
    uint32_t MAIN_PLL19_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL25_CFG;
    uint32_t MAIN_PLL25_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL27_CFG;
    uint32_t MAIN_PLL27_LOCKKEY0_UNLOCKED;
    uint32_t MAIN_PLL28_CFG;
    uint32_t MAIN_PLL28_LOCKKEY0_UNLOCKED;
} SDL_PLL_staticRegs;

extern SDL_DCC_config DCC_configParams[SDL_DCC_MAX_INSTANCE];
extern SDL_DCC_staticRegs DCC_staticRegs[SDL_DCC_MAX_INSTANCE];
/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/

#define SDL_APP_TEST_NOT_RUN        (-(int32_t) (2))
#define SDL_APP_TEST_FAILED         (-(int32_t) (1))
#define SDL_APP_TEST_PASS           ( (int32_t) (0))

#define DCC_NO_INTERRUPT    		(0u)
#define DCC_INTERRUPT				(1u)

/*#define DEBUG_DCC_MAGNA*/

/*===========================================================================*/
/*                         External function declarations                    */
/*===========================================================================*/


#if defined (DEBUG_DCC_MAGNA)
extern int32_t SDL_DCC_funcTest(void);
#endif
void dcc_init (void);
void dcc_MainFunction(void);
extern int32_t dcc_init_inst(uint32_t dccInst);
int32_t SDL_ESM_DCC_applicationCallbackFunction(SDL_ESM_Inst esmInst, SDL_ESM_IntType esmIntrType,
                                            uint32_t grpChannel,  uint32_t index, uint32_t intSrc, void *arg);
/*===========================================================================*/
/*                         Local Function definitions                        */
/*===========================================================================*/

#endif /* SDL_DCC_TEST_H */
/* Nothing past this point */
