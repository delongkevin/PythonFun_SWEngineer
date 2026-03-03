/*
 *  Copyright (C) 2020 Texas Instruments Incorporated
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
 *  \file sciserver_tirtos.c
 *
 *  \brief Example Library functions for an application including Sciserver
 *         This file is only for TIRTOS based applications.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */


#include <stdint.h>
#include <string.h>
#include <ti/csl/csl_types.h>
#include <ti/drv/sciclient/sciserver.h>
#include <ti/drv/sciclient/sciserver_autosaros.h>

#include <lib/strncpy.h>

#include <sciserver_hwiData.h>
#include "sciserver_secproxyTransfer.h"
#include <ti/drv/sciclient/examples/common/sciclient_appCommon.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static void CtApSciserverHigh_Init(void);
static void CtApSciserverLow_Init(void);

static Sciserver_taskData *utdHigh = NULL;
static volatile int highIsrEnableVal = 0;
static Sciserver_taskData *utdLow = NULL;
static volatile int lowIsrEnableVal = 0;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
Sciserver_hwiData * Getsciserver_hwi_list(uint8_t index)
{
    return((Sciserver_hwiData *) &sciserver_hwi_list[index]);
}

int32_t Sciserver_osInit(Sciserver_osCfgPrms_t *pAppPrms)
{
    Sciserver_CfgPrms_t prms;
    int32_t ret = CSL_PASS;

    if (pAppPrms == NULL)
    {
        ret = CSL_EBADARGS;
    }

    /* Initialize the Init Parameters for the Sciserver */
    if (ret == CSL_PASS)
    {
        ret = Sciserver_initPrms_Init(&prms);
    }
    /* Initialize the Sciserver */
    if (ret == CSL_PASS)
    {
        ret = Sciserver_init(&prms);
    }

    /* Set the process State */
    if (ret == CSL_PASS)
    {
        CtApSciserverHigh_Init();
        CtApSciserverLow_Init();
    }

    /* Set the process State */
    if (ret == CSL_PASS)
    {
        Sciserver_setCtrlState(SCISERVER_PROCESS_STATE_RUN);
        if (Sciserver_getCtrlState() != SCISERVER_PROCESS_STATE_RUN)
        {
            ret = CSL_EFAIL;
        }
    }

    return ret;
}


static void CtApSciserverHigh_Init(void)
{
    utdHigh = (Sciserver_taskData *) &gSciserverTaskList[SCISERVER_TASK_USER_HI];
    /* Set the pending State first */
    utdHigh->state->state = SCISERVER_TASK_PENDING;
}

static void CtApSciserverLow_Init(void)
{
    utdLow = (Sciserver_taskData *) &gSciserverTaskList[SCISERVER_TASK_USER_LO];
    /* Set the pending State first */
    utdLow->state->state = SCISERVER_TASK_PENDING;
}

int32_t Sciserver_osprocesstask(uint8_t index)
{
    int32_t ret = CSL_EFAIL;
    if(SCISERVER_TASK_USER_HI == index)
    {
        ret = Sciserver_processtask(utdHigh);
    }
    else if(SCISERVER_TASK_USER_LO == index)
    {
        ret = Sciserver_processtask(utdLow);
    }
    else
    {
        /* Do Nothing */
    }
    return ret;
}
