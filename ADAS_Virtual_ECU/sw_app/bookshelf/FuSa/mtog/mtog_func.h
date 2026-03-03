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
 *  \file     mtog_func.h
 *
 *  \brief    This file contains Master TOG function structures
 *
 *  \details  Master TOG function structures
 **/
#ifndef MTOG_FUNC_H
#define MTOG_FUNC_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <string.h>
#include <src/sdl/sdl_types.h>
#include <include/soc.h>
#include <src/sdl/sdl_mtog.h>
#include <src/sdl/sdl_types.h>
#include <sdl_esm.h>

/* ========================================================================== */
/*                                Data Structures                             */
/* ========================================================================== */

typedef struct MTOG_TestHandle_s
{
    /** Instance name */
	uint32_t instance;
    /** Instance name */
    char instanceName[16];
    /** ESM error event number */
    uint32_t ESMEventNumber;
    /** Flag to instance enabled for MTOG */
    volatile bool instEn;
    /** Timeout values */
    SDL_MTOGVal timeOut;
} MTOG_InstHandle_t;

/* ========================================================================== */
/*                                Function Declarations                       */
/* ========================================================================== */
void MTOG_eventHandler(uint32_t instanceIndex);
int32_t MTOG_AppInit(MTOG_InstHandle_t* instCfg);

#ifdef __cplusplus
}
#endif

int32_t MTOG_runTest(uint32_t instanceIndex);

#endif /* MTOG_FUNC_H */

/* Nothing past this point */
