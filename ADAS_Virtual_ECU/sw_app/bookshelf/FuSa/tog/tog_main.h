/*
 *   Copyright (c) Texas Instruments Incorporated 2021
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
 *  \file     tog_main.h
 *
 *  \brief    TOG Example main functions
 *
 *  \details  This file contains C prototype
 *
 **/

#include <src/sdl/sdl_tog.h>
#include <src/sdl/sdl_types.h>
#include <sdl_esm.h>
#include "tog_test_utils.h"
#include <soc.h>

#ifdef UNITY_INCLUDE_CONFIG_H
#include <test/unity/src/unity.h>
#include <test/unity/config/unity_config.h>
#endif

#define TOG_MAX_USECASE                 2
#define TOG_MAX_TEST_TIMEOUT_VALUE      (10000000u)
#define MCU_ESM_BASE                    (SDL_MCU_ESM0_CFG_BASE)


typedef struct TOG_TestHandle_s
{
    /** Instance name */
    char instanceName[16];
    /** Interrupt number for error event */
    uint32_t interruptNumber;
    /** ESM Instance to be used */
    uint32_t ESMInstance;
    /** ESM error event number */
    uint32_t ESMEventNumber;
    /** Flag to indicate test done, will be set when interrupt event comes */
    volatile bool doneFlag;
    /** Timeout configuration for test */
    uint32_t timeoutValue;
    /** Interrupt source for test */
    uint32_t intSrcBitmap;
    /** Flush mode for test */
    bool flushMode;
    /** Access endpoint */
    uint64_t endPointAccess;
} TOG_TestHandle_t;

/* TOG config type */
typedef struct {
    bool instEnabled;
    SDL_TOG_Inst instance;
    SDL_TOG_config cfg;
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
    TOG_TestHandle_t cfg2;
#endif
} SDL_APP_TOG_cfg_t;

typedef void (*TOG_injectFunction)(uint32_t instanceIndex);

/*#define SDL_APP_TOG_UART_PRINTS_ENABLED*/

void tog_init(void);
void tog_MainFunction(void);
int32_t tog_AppInit(SDL_APP_TOG_cfg_t* togCfg);

extern SDL_APP_TOG_cfg_t SDL_APP_TOG_cfg[SDL_TOG_MAX_INSTANCE+1u];
extern SDL_TOG_staticRegs SDL_TOG_staticRegs_Expected[SDL_TOG_MAX_INSTANCE+1u];
/* Nothing past this point */
