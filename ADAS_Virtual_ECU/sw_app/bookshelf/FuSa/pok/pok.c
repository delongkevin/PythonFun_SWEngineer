/* Copyright (c) 2021 Texas Instruments Incorporated
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
 *  \brief    This file contains POK example code.
 *
 *  \details  POK example main
 **/

/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
#include <ti/osal/osal.h>
#include "pok.h"
#include "esm.h"
#include "fusa_osal_interface_autosar.h"
#include "pok_app.h"
#include "fusa_application.h"

/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/
typedef union {
    uint32_t addr;
    uint32_t *ptr;
} ptrCastUnionU32_t;

/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/
/* define the unlock values */
#define KICK0_UNLOCK_VAL (0x68EF3490U)
#define KICK1_UNLOCK_VAL (0xD172BC5AU)

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/*===========================================================================*/
/*                         Global Variables                                  */
/*===========================================================================*/
SDL_APP_POK_cfg_t SDL_APP_POK_cfg[SDL_APP_NUM_POK_INST] = {
    {
        .instEnabled = false,
        .instance = SDL_POK_VDDA_PMIC_IN_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 0u,
            .voltDetMode = SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
	{
		.instEnabled = true,
		.instance = SDL_POK_VDD_CORE_ID,
		.pok_cfg =
		{
			.voltDetMode = SDL_PWRSS_SET_PP_VOLTAGE_DET_ENABLE,
			.trim = 0u,
			.hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
			.detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
			.pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION,
			.hystCtrlOV = SDL_PWRSS_HYSTERESIS_NO_ACTION,
			.trimOV = 74u,
			.deglitch = SDL_PWRSS_DEGLITCH_NO_ACTION
		}
	},
    {
        .instEnabled = false,
		.instance = SDL_POK_VDDR_CORE_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 0u,
            .voltDetMode = SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
    {
        .instEnabled = true,
		.instance = SDL_POK_VDD_CPU_ID,
        .pok_cfg =
        {
			.voltDetMode = SDL_PWRSS_SET_PP_VOLTAGE_DET_ENABLE,
			.trim = 0u,
			.hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
			.detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
			.pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION,
			.hystCtrlOV = SDL_PWRSS_HYSTERESIS_NO_ACTION,
			.trimOV = 74u,
			.deglitch = SDL_PWRSS_DEGLITCH_NO_ACTION
        }
    },
    {
        .instEnabled = false,
        .instance = SDL_POK_VMON_EXT_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 0u,
            .voltDetMode = SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
    {
        .instEnabled = false,
        .instance = SDL_POK_VMON_EXT_MAIN_1P8_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 0u,
            .voltDetMode = SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
    {
        .instEnabled = false,
        .instance = SDL_POK_VMON_EXT_MAIN_3P3_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 0u,
            .voltDetMode = SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
    {
        .instEnabled = false,
        .instance = SDL_POK_VDDR_MCU_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 0u,
            .voltDetMode = SDL_PWRSS_SET_UNDER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
    {
        .instEnabled = false,
        .instance = SDL_POK_VDDSHV_WKUP_GEN_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 0u,
            .voltDetMode = SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
    {
        .instEnabled = false,
        .instance = SDL_POK_CAP_VDDS_MCU_GEN_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 127U,
            .voltDetMode = SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
    {
        .instEnabled = false,
        .instance = SDL_POK_VDD_MCU_OV_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 0u,
            .voltDetMode = SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
    {
        .instEnabled = false,
        .instance = SDL_POR_POKHV_UV_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 127u,
            .voltDetMode = SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
    {
        .instEnabled = false,
        .instance = SDL_POR_POKLVB_UV_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 0u,
            .voltDetMode = SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    },
    {
        .instEnabled = false,
        .instance = SDL_POR_POKLVA_OV_ID,
        .pok_cfg =
        {
            .detectionCtrl = SDL_POK_DETECTION_NO_ACTION,
            .hystCtrl = SDL_PWRSS_HYSTERESIS_NO_ACTION,
            .trim = 0u,
            .voltDetMode = SDL_PWRSS_SET_OVER_VOLTAGE_DET_ENABLE,
            .pokEnSelSrcCtrl = SDL_POK_ENSEL_NO_ACTION
        }
    }
};
#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/*===========================================================================*/
/*                   Local Function definitions                              */
/*===========================================================================*/

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*===========================================================================*/
/*                         Function definitions                              */
/*===========================================================================*/
void pok_init(void)
{
  /* DD-ID: {EA0C611E-321C-4047-BD31-79DC07CD18F0}*/
    /* Unlock the MMR in order to access the POK registers */
    ptrCastUnionU32_t mmrUnlock;
    /* *((uint32_t *)(SDL_WKUP_CTRL_MMR0_CFG0_BASE + SDL_WKUP_CTRL_MMR_CFG0_LOCK6_KICK0)) = KICK0_UNLOCK_VAL;*/
    mmrUnlock.addr = SDL_WKUP_CTRL_MMR0_CFG0_BASE + SDL_WKUP_CTRL_MMR_CFG0_LOCK6_KICK0;
    *mmrUnlock.ptr = KICK0_UNLOCK_VAL;
    /**((uint32_t *)(SDL_WKUP_CTRL_MMR0_CFG0_BASE + SDL_WKUP_CTRL_MMR_CFG0_LOCK6_KICK1)) = KICK1_UNLOCK_VAL;*/
    mmrUnlock.addr = SDL_WKUP_CTRL_MMR0_CFG0_BASE + SDL_WKUP_CTRL_MMR_CFG0_LOCK6_KICK1;
    *mmrUnlock.ptr = KICK1_UNLOCK_VAL;;
    pok_init_voltage_monitors();
}

/* Nothing past this point */

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
