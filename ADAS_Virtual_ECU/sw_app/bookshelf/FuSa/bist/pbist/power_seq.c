/*
*
* Copyright (c) 2020 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  \file power_seq.c
 *
 *  \brief Custom core power sequence functions needed for proper powering
 *         beyond just control of SYSFW devices.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <sdl_types.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/sciclient/sciclient.h>

#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)
#include "armv8_power_utils.h"
#include "power_seq.h"
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            External Variables                              */
/* ========================================================================== */

/* None */

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* Custom core power restore sequence contains any core-custom power steps
 * needed prior to powering up, outside of device/power domain controls */
int32_t customPrepareForPowerUpSequence(uint8_t processorId)
{
  /* DD-ID: {8875C585-C3E2-4505-958B-3582602843CE}*/
    int32_t status = SDL_EFAIL;

    switch(processorId)
    {
#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)
        case (SCICLIENT_PROC_ID_A72SS0_CORE0):
            status = armv8_powerPrepareForPowerUpSequence(processorId);
            break;
#endif
        default:
        	/* Do nothing */
#ifdef 	Enable_Printf
            UART_printf("customPrepareForPowerUpSequence - Invalid ProcId %d\n",
                            processorId);
#endif
            break;
    }

    return (status);
}

/* Custom core power down sequence contains any core-custom powerdown steps
 * needed to be properly powered down, outside of device/power domain controls */
int32_t customPowerDownSequence(uint8_t processorId)
{
  /* DD-ID: {CE058174-CE28-48e3-9BC8-637CCC8A2590}*/
    int32_t status = SDL_EFAIL;

    switch(processorId)
    {
#if defined (SOC_J721E) || defined (SOC_J7200) || defined (SOC_J721S2)
        case (SCICLIENT_PROC_ID_A72SS0_CORE0):
            status = armv8_powerDownSequence(processorId);
            break;
#endif
        default:
        	/* Do nothing */
#ifdef 	Enable_Printf
            UART_printf("customPowerDownSequence - Invalid ProcId %d\n",
                            processorId);
#endif
            break;
    }

    return (status);
}

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
