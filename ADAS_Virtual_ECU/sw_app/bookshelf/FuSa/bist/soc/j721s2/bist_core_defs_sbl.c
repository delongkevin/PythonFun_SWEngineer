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
 *  \file     bist_core_defs.c
 *
 *  \brief    This file defines available main domain bist modules and order of bist per stage
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include "bist_core_defs.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* NOTE: The PBIST and LBIST tests that are run in each stage on this SOC are
 * defined in this file.  To make modifications, the user simply can add/remove/move
 * ID's in the following arrays.
 * Run before any booting of cores:
 * pbist_pre_boot_stage
 * lbist_pre_boot_stage
 * Run before the first boot stage:
 * pbist_first_boot_stage
 * lbist_first_boot_stage
 * Run before the second boot stage:
 * pbist_second_boot_stage
 * lbist_second_boot_stage
 * Run before the third boot stage:
 * pbist_third_boot_stage
 * lbist_third_boot_stage
 * Care should be taken to ensure that BIST sections for particular cores match
 * the boot cores selected for each boot stage in soc/<SOC Device>/boot_core_defs.c.
 * */

#if defined (BIST_SBL)
#else
#error "ERROR: This file is only for BIST running from SBL. For running BIST from BootApp, check bist_core_defs.c"
#endif

/* Defines PBIST's needed for all cores before the first stage of the Main Domain
 * boot sequence for J721S2 SOC */
int pbist_pre_boot_stage[] =
{
//    PBIST_INSTANCE_MAININFRA_0, /* Main Infra_0 */
	PBIST_INSTANCE_NAVSS,
//	PBIST_INSTANCE_MAINR5F0
//	PBIST_INSTANCE_DSS
};

int pbist_pre_boot_stage_status[] =
{
    0,  /* HW Post status */
    0,  /* Main Infra_0 */   
};

int pbist_pre_boot_stage_neg_status[] =
{
    0,  /* HW Post status */
    0,  /* Main Infra_0 */   
};

uint8_t num_pbists_pre_boot = sizeof(pbist_pre_boot_stage) / sizeof(int);

const char *pbistName(uint32_t pbistID)
{
    /* DD-ID:{AE49F223-9FCE-4eff-BB91-01DFAC10179E}*/
    char *name;

    switch(pbistID)
    {
        case (PBIST_HWPOST_MCU_INDEX):
            name="PBIST_HWPOST_MCU_INDEX";
            break;
        case (PBIST_INSTANCE_VPAC_0):
            name="PBIST_INSTANCE_VPAC_0";
            break;
        case (PBIST_INSTANCE_MAININFRA_1):
            name="PBIST_INSTANCE_MAININFRA_1";
            break;
        case (PBIST_INSTANCE_DMPAC):
            name="PBIST_INSTANCE_DMPAC";
            break;
        case (PBIST_INSTANCE_MAINR5F0):
            name="PBIST_INSTANCE_MAINR5F0";
            break;
        case (PBIST_INSTANCE_MAINR5F1):
            name="PBIST_INSTANCE_MAINR5F1";
            break;
        case (PBIST_INSTANCE_MAININFRA_0):
            name="PBIST_INSTANCE_MAININFRA_0";
            break;
        case (PBIST_INSTANCE_HC):
            name="PBIST_INSTANCE_HC";
            break;
        case (PBIST_INSTANCE_NAVSS):
            name="PBIST_INSTANCE_NAVSS";
            break;
        case (PBIST_INSTANCE_CODEC_1):
            name="PBIST_INSTANCE_CODEC_1";
            break;
        case (PBIST_INSTANCE_GPU):
            name="PBIST_INSTANCE_GPU";
            break;		
        case (PBIST_INSTANCE_A72_0):	
            name="PBIST_INSTANCE_A72_0";
            break;			
        case (PBIST_INSTANCE_C7x_0):
            name="PBIST_INSTANCE_C7x_0";
            break;	
        case (PBIST_INSTANCE_C7x_1):
            name="PBIST_INSTANCE_C7x_1";
            break;
        case (PBIST_INSTANCE_MSMC):
            name="PBIST_INSTANCE_MSMC";
        	break;
        case (PBIST_INSTANCE_DSS):
            name="PBIST_INSTANCE_DSS";
            break;		
        default:
            name="INVALID ID";
            break;
    }

    return name;
}
