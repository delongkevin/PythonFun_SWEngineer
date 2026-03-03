/*
 * TOG Example
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
 *  \file tog_main.c
 *
 *  \brief This file demonstrates using the Timeout Gasket (TOG)
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/drv/sciclient/sciclient.h>
#include <test/r5f_startup/interrupt.h>
#include <string.h>
#include <stdio.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>
#include "tog_main.h"
#include "fusa_application.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "ErrorManagerSatellite.h"
#include "ErrorManagerShared.h"
#include "pmic.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
typedef union {
    uint32_t addr;
    uint32_t *ptr;
} ptrCastUnionU32_t;
/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
extern int32_t tog_minTimeout(SDL_APP_TOG_cfg_t* togCfg);
#endif /*(SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)*/

#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
void TOG_datAbortExceptionHandler(void *param);
#endif /*(SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)*/
static void tog_Periodic_ConfigRegCheck(void);

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
const SDL_R5ExptnHandlers TOG_R5ExptnHandlers =
{
    .udefExptnHandler = NULL,
    .swiExptnHandler = NULL,
    .pabtExptnHandler = NULL,
    .dabtExptnHandler = &TOG_datAbortExceptionHandler,
    .irqExptnHandler = NULL,
    .fiqExptnHandler = NULL,
    .udefExptnHandlerArgs = ((void *)0u),
    .swiExptnHandlerArgs = ((void *)0u),
    .pabtExptnHandlerArgs = ((void *)0u),
    .dabtExptnHandlerArgs = ((void *)0u),
    .irqExptnHandlerArgs = ((void *)0u),
};
#endif

SDL_APP_TOG_cfg_t SDL_APP_TOG_cfg[SDL_TOG_MAX_INSTANCE+1u] = {
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG0,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "NAVSS_TO_AC",
	        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_AM_NAVSS_TO_AC_NON_SAFE_STOG4_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                 		/* Initialize done flag */
	        .timeoutValue           = 0x1000000U,                   /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
			.endPointAccess         = 0x4F00000000,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG1,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "AC_CFG_TO_AC",
	        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_AM_AC_CFG_TO_AC_CFG_NON_SAFE_STOG9_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
			.endPointAccess         = 0x0F400000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG2,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
        {
            .instanceName           = "AC_CFG",
            .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_AM_AC_CFG_TO_AC_CFG_NON_SAFE_STOG2_TRANS_ERR_LVL_0, /* TOG ESM event number */
            .doneFlag               = false,                 /* Initialize done flag */
            .timeoutValue           = 0x10000000U,              /* timeout value */
            .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
    		.endPointAccess         = 0x04210000 ,
        }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG3,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "RC_TO_HC2",
	        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_AM_RC_TO_HC2_STOG6_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
			.endPointAccess         = 0x18000000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG4,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "RC_TO_HC2_2",
	        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_AM_RC_TO_HC2_STOG7_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
	        .endPointAccess         = 0x18000000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG5,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "HC2_TO_HC",
	        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_AM_HC2_TO_HC_CFG_STOG5_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
	        .endPointAccess         = 0x04104000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG6,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "RC_TO_RC",
	        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_AM_RC_TO_RC_CFG_STOG3_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
	        .endPointAccess         = 0x05380000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG7,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "IPPHY_TO_RTI",
	        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_AM_IPPHY_TO_RTI_GPU_STOG8_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
	        .endPointAccess         = 0x022F0000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG8,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "IPPHY_TO_IPPHY",
	        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_AM_IPPHY_TO_IPPHY_STOG1_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
	        .endPointAccess         = 0x02200000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG9,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "MAIN_INFRA",
	        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_AM_MAIN_INFRA_TO_MAIN_INFRA_STOG0_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
	        .endPointAccess         = 0x00A30000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG10,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "PVU0_CFG",
	        .ESMEventNumber         = SDLR_ESM0_ESM_LVL_EVENT_NAVSS0_VIRTSS_VIRTSS_FFI_PVU0_CFG_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
			.endPointAccess         = 0x30F80000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG11,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "WKUP_VDC_INFRA",
	        .ESMEventNumber         = SDLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_VDC_INFRA_VBUSP_32B_SRC_SAFEG0_INFRA_SAFEG_TRANS_ERR_LVL_0,/* TOG ESM event number */
	        .doneFlag               = false,                 /* Initialize done flag */
	        .timeoutValue           = 0x100000U,              /* timeout value */
	        .intSrcBitmap           = 0x0U,
			.endPointAccess         = 0x00410000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG12,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "TIMEOUT_64B2",
	        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_TIMEOUT_64B2_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
			.endPointAccess         = 0x02400000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG13,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "TIMEOUT_64B3",
	        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_TIMEOUT_64B3_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
			.endPointAccess         = 0x50000000 ,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG14,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "TIMEOUT_64B4",
	        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_TIMEOUT_64B4_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                 /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,              /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
			.endPointAccess         = 0x58000000 ,
	    }
#endif
    },
    {
        .instEnabled = true,
        .instance = SDL_TOG_INSTANCE_STOG15,	/* NOTE: IPC related transactions */
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "MCU FW1",
	        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_VDC_SOC_FW_VBUSP_32B_SRC_SAFEG1_SOC_FW_SAFEG_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x1000000U,               /* timeout value */
	        .intSrcBitmap           = 0x0U,
	    }
#endif
    },
    {
        .instEnabled = false,
        .instance = SDL_TOG_INSTANCE_STOG16,
        .cfg =
        {
            .timeoutVal = SDL_APP_TOG_TIMEOUTVAL,
            .cfgCtrl = SDL_TOG_CFG_TIMEOUT,
            .intrSrcs = (SDL_TOG_INTRSRC_UNEXPECTED_RESPONSE | SDL_TOG_INTRSRC_TRANSACTION_TIMEOUT)
        },
#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
		.cfg2 =
	    {
	        .instanceName           = "MCU_VDC_INFRA",		/* To be confirmed if it is for RAT transactions: Exception occurs for timeout < 55 */
	        .ESMEventNumber         = SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_VDC_INFRA_VBUSP_32B_SRC_SAFEG0_INFRA_SAFEG_TRANS_ERR_LVL_0, /* TOG ESM event number */
	        .doneFlag               = false,                  /* Initialize done flag */
	        .timeoutValue           = 0x10000000U,               /* timeout value */
	        .intSrcBitmap           = SDL_TOG_INTRSRC_ALL,
			.endPointAccess         = 0x00A90000 ,
	    }
#endif
    }
};

SDL_TOG_staticRegs SDL_TOG_staticRegs_Expected[SDL_TOG_MAX_INSTANCE+1u] = {
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},
		{
				.CFG = 0,
				.ENABLE = 0,
				.ERR = 0,
				.FLUSH = 0,
				.PID = 0,
				.TIMEOUT = 0
		},

};
#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

/* ========================================================================== */
/*                            External Variables                              */
/* ========================================================================== */



#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */


/*****************************************************************************
 * This is the main function for the Timeout Gasket (TOG) example
 * application.
 * It runs through the use case to demonstrate usage of the TOG modules
 */

/* define the unlock and lock values */
#define KICK0_UNLOCK_VAL (0x68EF3490U)
#define KICK1_UNLOCK_VAL (0xD172BC5AU)
void tog_init(void)
{
  /* DD-ID: {90B08123-2060-4c87-BC21-5387E5C7AA6B}*/
	ptrCastUnionU32_t mmrUnlock;

    /**((uint32_t *)(SDL_CTRL_MMR0_CFG0_BASE + SDL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK0)) = KICK0_UNLOCK_VAL;*/
	mmrUnlock.addr = SDL_CTRL_MMR0_CFG0_BASE + SDL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK0;
	*mmrUnlock.ptr = KICK0_UNLOCK_VAL;
    /**((uint32_t *)(SDL_CTRL_MMR0_CFG0_BASE + SDL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK1)) = KICK1_UNLOCK_VAL;*/
	mmrUnlock.addr = SDL_CTRL_MMR0_CFG0_BASE + SDL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK1;
	*mmrUnlock.ptr = KICK1_UNLOCK_VAL;

    /**((uint32_t *)(SDL_MCU_CTRL_MMR0_CFG0_BASE + SDL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0)) = KICK0_UNLOCK_VAL;*/
	mmrUnlock.addr = SDL_MCU_CTRL_MMR0_CFG0_BASE + SDL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0;
	*mmrUnlock.ptr = KICK0_UNLOCK_VAL;
    /**((uint32_t *)(SDL_MCU_CTRL_MMR0_CFG0_BASE + SDL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1)) = KICK1_UNLOCK_VAL;*/
	mmrUnlock.addr = SDL_MCU_CTRL_MMR0_CFG0_BASE + SDL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1;
	*mmrUnlock.ptr = KICK1_UNLOCK_VAL;

    /* This is needed to handle data abort that can happen in the process of injecting the error */
#if ( SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
    Intc_RegisterExptnHandlers(&TOG_R5ExptnHandlers);
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    APP_log(APP_LOG_MAX,"\nTOG SelfTest Started \r\n");
#endif

    if (result == 0)
    {
    	SDL_TOG_Inst currTogInst = SDL_TOG_INSTANCE_STOG0;
    	for ( currTogInst = SDL_TOG_INSTANCE_STOG0; currTogInst<=(SDL_TOG_MAX_INSTANCE); currTogInst++ ){
            if ( true == SDL_APP_TOG_cfg[currTogInst].instEnabled )
            {
            	result = tog_minTimeout( &SDL_APP_TOG_cfg[currTogInst] );
            	if (result != 0)
            	{
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
            		APP_log(APP_LOG_MAX," \n  TOG SelfTest failed for currTogInst= %d\n",currTogInst);
#endif
            	}else{
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
            		APP_log(APP_LOG_MAX," \n  TOG SelfTest failed for currTogInst=%d\n",currTogInst);
#endif
            	}
            }
    	}
    }
#else
    SDL_TOG_Inst currTogInst = SDL_TOG_INSTANCE_STOG0;
    for ( currTogInst = SDL_TOG_INSTANCE_STOG0; currTogInst<=(SDL_TOG_MAX_INSTANCE); currTogInst++ ){
        if ( true == SDL_APP_TOG_cfg[currTogInst].instEnabled )
        {
            (void)tog_AppInit( &SDL_APP_TOG_cfg[currTogInst] );
        }
    }
#endif

    return;
}

#if (SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)
void TOG_datAbortExceptionHandler(void *param)
{
  /* DD-ID: {39512E19-E751-463d-BC35-77E1BBFD88D3}*/
    /* This is a fake exception so return */
}
#endif /*(SDL_APP_TOG_SELFTEST_ENABLED == SDL_APP_ON)*/

/* currently there is no error manager event to be set in the case of a tog staic register check fail */
static void tog_Periodic_ConfigRegCheck(void)
{
  /* DD-ID: {02EE38AD-01E3-4b11-918A-7199DFE539EF}*/
    /* set the var to true in the case that a config mis match is detected */
    bool configMisMatchFlag = false;
    SDL_TOG_staticRegs SDL_TOG_staticRegs_curr = {0u};
    SDL_TOG_Inst currTogInst = SDL_TOG_INSTANCE_STOG0;
    ldef_ErrorMgr_stAddData SDL_TogAddtionalData_au8 = {0u};

    for ( currTogInst = SDL_TOG_INSTANCE_STOG0; currTogInst<=(SDL_TOG_MAX_INSTANCE); currTogInst++ )
    {
    	configMisMatchFlag = false;
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    	APP_log(APP_LOG_MAX,"\n currTogInst: currTogInst = %d\n",currTogInst);
#endif
    	if ( true == SDL_APP_TOG_cfg[currTogInst].instEnabled )
    	{
    		(void)SDL_TOG_getStaticRegisters(SDL_APP_TOG_cfg[currTogInst].instance, &SDL_TOG_staticRegs_curr);

    		if ( SDL_TOG_staticRegs_curr.CFG != SDL_TOG_staticRegs_Expected[currTogInst].CFG )
    		{
    			configMisMatchFlag = true;
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\n\nMismatch in Configuration Register: configMisMatchFlag = %d, Act_CFG = %d, Exp_CFG = %d\n",configMisMatchFlag, SDL_TOG_staticRegs_curr.CFG, SDL_TOG_staticRegs_Expected[currTogInst].CFG);
#endif
    		}
    		else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\n\nNo Mismatch in Configuration Register\n");
#endif
    		}

    		if ( SDL_TOG_staticRegs_curr.ENABLE != SDL_TOG_staticRegs_Expected[currTogInst].ENABLE )
    		{
    			configMisMatchFlag = true;
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\nMismatch in Enable Register: configMisMatchFlag = %d, Act_ENABLE = %d, Exp_ENABLE = %d\n",configMisMatchFlag, SDL_TOG_staticRegs_curr.ENABLE, SDL_TOG_staticRegs_Expected[currTogInst].ENABLE);
#endif
    		}
    		else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\nNo Mismatch in Enable Register\n");
#endif
    		}

    		if ( SDL_TOG_staticRegs_curr.ERR != SDL_TOG_staticRegs_Expected[currTogInst].ERR )
    		{
    			configMisMatchFlag = true;
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\nMismatch in Error Interrupt Enabled Status/Set Register: configMisMatchFlag = %d, Act_ERR = %d, Exp_ERR = %d\n",configMisMatchFlag, SDL_TOG_staticRegs_curr.ERR, SDL_TOG_staticRegs_Expected[currTogInst].ERR);
#endif
    		}
    		else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\nNo Mismatch in Error Interrupt Enabled Status/Set Register\n");
#endif
    		}

    		if ( SDL_TOG_staticRegs_curr.FLUSH != SDL_TOG_staticRegs_Expected[currTogInst].FLUSH )
    		{
    			configMisMatchFlag = true;
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\nMismatch in Flush Register: configMisMatchFlag = %d, Act_FLUSH = %d, Exp_FLUSH = %d\n",configMisMatchFlag, SDL_TOG_staticRegs_curr.FLUSH, SDL_TOG_staticRegs_Expected[currTogInst].FLUSH);
#endif
    		}
    		else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\nNo Mismatch in Flush Register\n");
#endif
    		}

    		if ( SDL_TOG_staticRegs_curr.PID != SDL_TOG_staticRegs_Expected[currTogInst].PID )
    		{
    			configMisMatchFlag = true;
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\nMismatch in PID Revision Register: configMisMatchFlag = %d, Act_PID = %d, Exp_PID = %d\n",configMisMatchFlag, SDL_TOG_staticRegs_curr.PID, SDL_TOG_staticRegs_Expected[currTogInst].PID);
#endif
    		}
    		else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\nNo Mismatch in PID Revision Register\n");
#endif
    		}

    		if ( SDL_TOG_staticRegs_curr.TIMEOUT != SDL_TOG_staticRegs_Expected[currTogInst].TIMEOUT )
    		{
    			configMisMatchFlag = true;
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\nMismatch in Timeout Value Register: configMisMatchFlag = %d, Act_TIMEOUT = %d, Exp_TIMEOUT = %d\n\n",configMisMatchFlag, SDL_TOG_staticRegs_curr.TIMEOUT, SDL_TOG_staticRegs_Expected[currTogInst].TIMEOUT);
#endif
    		}
    		else {
#if defined(SDL_APP_TOG_UART_PRINTS_ENABLED)
    			APP_log(APP_LOG_MAX,"\nNo Mismatch in Timeout Value Register\n\n");
#endif
    		}

    	    if((SDL_TOG_INSTANCE_STOG15 == currTogInst) && (true == configMisMatchFlag))
    	    {
    			(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_VBUSM_Configuration_mismatch_timeout,
    					ldef_ErrorMgr_ErrorActive,
    					(const ldef_ErrorMgr_stAddData *)&SDL_TogAddtionalData_au8);
    			Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_TOG, (uint8_t)TRUE);

    	    	/* Report error to CAN msg */
    	    	f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_VBUSM_Configuration_mismatch_timeout);

    	    }
    	}
    }
}

void tog_MainFunction(void)
{
  /* DD-ID: {9EEA4AFD-0AAB-4956-97B0-CA1A2319F6B5}*/
    tog_Periodic_ConfigRegCheck();
}

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
