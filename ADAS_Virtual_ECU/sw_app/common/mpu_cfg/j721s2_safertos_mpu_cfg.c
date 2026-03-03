/*
 *  Copyright (c) Texas Instruments Incorporated 2020
 *  All rights reserved.
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

#include <stdlib.h>
#include <stdint.h>
#include <ti/csl/arch/r5/csl_arm_r5.h>
#include <ti/csl/arch/r5/csl_arm_r5_mpu.h>
#include <ti/csl/arch/r5/interrupt.h>
#include <ti/csl/arch/r5/csl_cache.h>
#include <app_mem_map.h>

/* SafeRTOS includes */
#include "SafeRTOS_API.h"
#include <ti/osal/SafeRTOS_MPU.h>
#include "mpuARM.h"

/**
 * \brief  TEX[2:0], C and B values.
 *         CSL_ArmR5MemAttr is used as intex here.
 *         gMemAttr[x][0]: TEX[2:0] values
 *         gMemAttr[x][1]: C bit value
 *         gMemAttr[x][2]: B bit value
 */
static const uint32_t gMemAttr[CSL_ARM_R5_MEM_ATTR_MAX][3U] =
{
/*    TEX[2:0], C,     B bits */
    {   0x0U,   0x0U,  0x0U,}, /* Strongly-ordered.*/
    {   0x0U,   0x0U,  0x1U,}, /* Shareable Device.*/
    {   0x0U,   0x1U,  0x0U,}, /* Outer and Inner write-through, no write-allocate. */
    {   0x0U,   0x1U,  0x1U,}, /* Outer and Inner write-back, no write-allocate. */
    {   0x1U,   0x0U,  0x0U,}, /* Outer and Inner Non-cacheable. */
    {   0x1U,   0x1U,  0x1U,}, /* Outer and Inner write-back, write-allocate.*/
    {   0x2U,   0x0U,  0x0U,}, /* Non-shareable Device.*/
};

xMPU_CONFIG_PARAMETERS __attribute__((section(".startupData"))) /*__attribute__((weak))*/ gMPUConfigParms[CSL_ARM_R5F_MPU_REGIONS_MAX] =
{
	{
		/* Region 0 configuration: complete 32 bit address space = 4Gbits add one more 2gb */
		/* ulRegionNumber */
		.ulRegionNumber         = 0U,
		/* Starting address */
		.ulRegionBeginAddress   = 0x0U,
		/* Access permission */
		{
			.ulexeNeverControl  = 1U,
			.ulaccessPermission = CSL_ARM_R5_ACC_PERM_NO_ACCESS,
			.ulshareable        = 0U,
			.ulcacheable        = 0U,
			.ulcachePolicy      = 0U,
			.ulmemAttr          = 0U,
		},
		/* Region size is 4GB */
		.ulRegionSize           = CSL_ARM_R5_MPU_REGION_SIZE_4GB,
		/* ulSubRegionDisable */
		.ulSubRegionDisable     = mpuREGION_ALL_SUB_REGIONS_ENABLED,
	},
	{
		/* 0 to 0x70000000 is configured as strongly ordered for register access.
		 * This region was given the read and write permission for Privilege mode.
		 * For use mode, only read permission is there.Once all the tasks are moved
		 * to Un-privilege mode, then to access this register area, the function has
		 * to execute privilege mode enter functions to access these area.	 *
		 */
		/* ulRegionNumber */
		.ulRegionNumber         = 1U,
		/* Starting address */
		.ulRegionBeginAddress   = 0x0U,
		/* Access permission */
		{
			.ulexeNeverControl  = 1U,
			.ulaccessPermission = CSL_ARM_R5_ACC_PERM_PRIV_RD_WR_USR_RD,
			.ulshareable        = 0U,
			.ulcacheable        = 0U,
			.ulcachePolicy      = 0U,
			.ulmemAttr          = 0U,
		},
		.ulRegionSize           = 0x80000000UL,
		/* ulSubRegionDisable. mpuREGION_8TH_SUB_REGION_DISABLE restricts configuration
		   until 0x70000000. */
		.ulSubRegionDisable     = mpuREGION_8TH_SUB_REGION_DISABLE,
	},
	{
		/* Region 2 configuration: ATCM memory */
		/* ulRegionNumber */
		.ulRegionNumber         = 2U,
		/* Starting address */
		.ulRegionBeginAddress   = 0x0U,
		/* Access permission */
		{
			.ulexeNeverControl  = 0U,
			.ulaccessPermission = CSL_ARM_R5_ACC_PERM_PRIV_RD_WR_USR_RD,
			.ulshareable        = 0U,
			.ulcacheable        = 1U,
			.ulcachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
			.ulmemAttr          = 0U,
		},
		/* ulRegionSize 32KB */
		.ulRegionSize           = (32U * 1024U),
		/* ulSubRegionDisable */
		.ulSubRegionDisable     = mpuREGION_ALL_SUB_REGIONS_ENABLED,
	},
	{
		/* Region 3 configuration: 32 KB BTCM */
		/* Address of ATCM/BTCM are configured via MCU_SEC_MMR registers
		   It can either be '0x0' or '0x41010000'. Application/Boot-loader shall
		   take care this configurations and linker command file shall be
		   in sync with this. For either of the above configurations,
		   MPU configurations will not changes as both regions will have same
		   set of permissions in almost all scenarios.
		   Application can chose to overwrite this MPU configuration if needed.
		   The same is true for the region corresponding to ATCM. */
		/* ulRegionNumber */
		.ulRegionNumber         = 3U,
		/* Starting address */
		.ulRegionBeginAddress   = 0x41010000u,
		/* Access permission */
		{
			.ulexeNeverControl  = 0U,
			.ulaccessPermission = CSL_ARM_R5_ACC_PERM_PRIV_RD_WR_USR_RD,
			.ulshareable        = 0U,
			.ulcacheable        = 1U,
			.ulcachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
			.ulmemAttr          = 0U,
		},
		/* size is 32KB */
		.ulRegionSize           = (32U * 1024U),
		/* ulSubRegionDisable */
		.ulSubRegionDisable     = mpuREGION_ALL_SUB_REGIONS_ENABLED,
	},
	{
		/* Region 4 configuration: 4 MB MCMS3 RAM */
		/* ulRegionNumber */
		.ulRegionNumber         = 4U,
		/* Starting address */
		.ulRegionBeginAddress   = 0xD0000000u,
		/* Access permission */
		{
			.ulexeNeverControl  = 0U,
			.ulaccessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
			.ulshareable        = 0U,
			.ulcacheable        = 1U,
			.ulcachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
			.ulmemAttr          = 0U,
		},
		/* Size is 4MB */
		.ulRegionSize           = (512U * 1024U),
		/* ulSubRegionDisable */
		.ulSubRegionDisable     = mpuREGION_ALL_SUB_REGIONS_ENABLED,
	},
    {
        /* Region 5 configuration: 40MB DDR and 16MB local heap for MCU2_0  */
        /* ulRegionNumber */
        .ulRegionNumber         = 5U,
        /* Starting address */
        .ulRegionBeginAddress   = 0x98000000u,
        /* Access permission */
        {
            .ulexeNeverControl  = 1U,
            .ulaccessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
            .ulshareable        = 0U,
            .ulcacheable        = 1U,
            .ulcachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
            .ulmemAttr          = 0U,
        },
        /* size is 64MB */
        .ulRegionSize           = (64U * 1024U *1024U),
        /* ulSubRegionDisable */
        .ulSubRegionDisable     = mpuREGION_8TH_SUB_REGION_DISABLE,
    },
    {
        /* Region 6 configuration: 	4 MB DDR for Code and Constants */
        /* ulRegionNumber */
        .ulRegionNumber         = 6U,
        /* Starting address */
        .ulRegionBeginAddress   = 0x98000000u,
        /* Access permission */
        {
            .ulexeNeverControl  = 0U,
            .ulaccessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD,
            .ulshareable        = 0U,
            .ulcacheable        = 1U,
            .ulcachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
            .ulmemAttr          = 0U,
        },
        /* size is 4MB */
        .ulRegionSize           = (4U * 1024U * 1024U),
        /* ulSubRegionDisable */
        .ulSubRegionDisable     = mpuREGION_ALL_SUB_REGIONS_ENABLED,
    },
    {
        /* Region 7 configuration: Ring buffer */
        /* ulRegionNumber */
        .ulRegionNumber         = 7U,
        /* Starting address */
        .ulRegionBeginAddress   = IPC_VRING_MEM_ADDR,
        /* Access permission */
        {
            .ulexeNeverControl  = 1U,
            .ulaccessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
            .ulshareable        = 0U,
            .ulcacheable        = 0U,
            .ulcachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
            .ulmemAttr          = 4U,
        },
        /* ulRegionSize */
        .ulRegionSize           = IPC_VRING_MEM_SIZE,
        /* ulSubRegionDisable */
        .ulSubRegionDisable     = mpuREGION_ALL_SUB_REGIONS_ENABLED,
    },
    {
        /* Region 8 configuration: app log and TIOVX area buffer */
        /* APP_LOG_MEM_ADDR        =0xA0000000u; Size=256KB*/
        /* TIOVX_OBJ_DESC_MEM_ADDR =0xA0040000u; Size=63.75MB*/
        /* TIOVX_LOG_RT_MEM_ADDR   =0xA4000000u; Size=32MB*/
        /* DDR_SHARED_MEM_ADDR     =0xA6000000u; Size=256MB*/
        /* ulRegionNumber */
        .ulRegionNumber         = 8U,
        /* Starting address */
        .ulRegionBeginAddress   = 0xA0000000u,
        /* Access permission */
        {
            .ulexeNeverControl  = 1U,
            .ulaccessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
            .ulshareable        = 1U,
            .ulcacheable        = 0U,
            .ulcachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
            .ulmemAttr          = 0U,
        },
        /* ulRegionSize 512MB */
        .ulRegionSize           = (512U * 1024U * 1024U),
        /* ulSubRegionDisable */
        .ulSubRegionDisable     = (mpuREGION_7TH_SUB_REGION_DISABLE | mpuREGION_8TH_SUB_REGION_DISABLE),
    },
    {
        /* Region 9 configuration: 4MB ASIL DDR for MCU2_0  */
        /* ulRegionNumber */
        .ulRegionNumber         = 9U,
        /* Starting address */
        .ulRegionBeginAddress   = 0xB6000000u,
        /* Access permission */
        {
            .ulexeNeverControl  = 1U,
            .ulaccessPermission = CSL_ARM_R5_ACC_PERM_PRIV_RD_WR,
            .ulshareable        = 0U,
            .ulcacheable        = 1U,
            .ulcachePolicy      = CSL_ARM_R5_CACHE_POLICY_WB_WA,
            .ulmemAttr          = 0U,
        },
        /* size is 32MB */
        .ulRegionSize           = (32U * 1024U *1024U),
        /* ulSubRegionDisable */
        .ulSubRegionDisable     = (mpuREGION_1ST_SUB_REGION_DISABLE |  \
        						   mpuREGION_3RD_SUB_REGION_DISABLE |  \
        						   mpuREGION_4TH_SUB_REGION_DISABLE |  \
								   mpuREGION_5TH_SUB_REGION_DISABLE |  \
								   mpuREGION_6TH_SUB_REGION_DISABLE |  \
								   mpuREGION_7TH_SUB_REGION_DISABLE |  \
								   mpuREGION_8TH_SUB_REGION_DISABLE),
    },
    {
        /* Region 10 configuration: IPC Shared mem uncached.... */
        /* ulRegionNumber */
        .ulRegionNumber         = 10U,
        /* Starting address */
        .ulRegionBeginAddress   = 0xB6C00000u,
        /* Access permission */
        {
            .ulexeNeverControl  = 1U,
            .ulaccessPermission = CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR,
            .ulshareable        = 0U,
            .ulcacheable        = 0U,
            .ulcachePolicy      = CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE,
            .ulmemAttr          = 4U,
        },
        /* size is 4 MB */
        .ulRegionSize           = (4U * 1024U * 1024U),
        /* ulSubRegionDisable */
        .ulSubRegionDisable     = mpuREGION_ALL_SUB_REGIONS_ENABLED,
    },

};
