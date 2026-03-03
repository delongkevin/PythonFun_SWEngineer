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
 *  \file     bist.h
 *
 *  \brief    This header provides BIST task function.
 */

#ifndef __BIST__
#define __BIST__

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/*#define BIST_ERRMGR_LOG*/
/*#define UART_PRINTS_ENABLED*/

#if defined (BIST_SBL)
	#define BIST_PRINT_LOG	SBL_log
	#define BIST_LOG_ERR	SBL_LOG_ERR
	#define BIST_LOG_MIN	SBL_LOG_MIN
	#define BIST_LOG_MAX	SBL_LOG_MAX
#elif defined (BIST_BOOT_APP)
	#define BIST_PRINT_LOG	APP_log
	#define BIST_LOG_ERR	APP_LOG_ERR
	#define BIST_LOG_MIN	APP_LOG_MIN
	#define BIST_LOG_MAX	APP_LOG_MAX
#endif
	#define BIST_LOG_LEVEL	BIST_LOG_MAX

typedef union{
	struct{
		uint32_t resPBIST_HWPOST_MCU_INDEX       :1; /*     (0U)   */
		uint32_t resPBIST_INSTANCE_VPAC_0        :1; /*     (1U)   */
		uint32_t resPBIST_INSTANCE_MAININFRA_1   :1; /*     (2U)   */
		uint32_t resPBIST_INSTANCE_DMPAC         :1; /*     (3U)   */
		uint32_t resPBIST_INSTANCE_MAINR5F0      :1; /*     (4U)   */
		uint32_t resPBIST_INSTANCE_MAINR5F1      :1; /*     (5U)   */
		uint32_t resPBIST_INSTANCE_MAININFRA_0   :1; /*     (6U)   */
		uint32_t resPBIST_INSTANCE_HC            :1; /*     (7U)   */
		uint32_t resPBIST_INSTANCE_NAVSS         :1; /*     (8U)   */
		uint32_t resPBIST_INSTANCE_CODEC_1       :1; /*     (9U)   */
		uint32_t resPBIST_INSTANCE_GPU           :1; /*     (10U)  */
		uint32_t resPBIST_INSTANCE_DSS           :1; /*     (11U)  */
		uint32_t resPBIST_INSTANCE_MCUR5F1       :1; /*     (12U)  */
		uint32_t resPBIST_INSTANCE_MCU_1         :1; /*     (13U)  */
		uint32_t resPBIST_INSTANCE_MCU_0         :1; /*     (14U)  */
		uint32_t resPBIST_INSTANCE_C7x_0         :1; /*     (15U)  */
		uint32_t resPBIST_INSTANCE_A72_0         :1; /*     (16U)  */
		uint32_t resPBIST_INSTANCE_MSMC          :1; /*     (17U)  */
		uint32_t resPBIST_INSTANCE_C7x_1         :1; /*     (18U)  */
		uint32_t								 :13;
	}bits;
	uint32_t word;
}T_PbistResult;

typedef union{
	struct{
		uint16_t resLBIST_HWPOST_INST_SMS_INDEX  :1; /*   0 */
		uint16_t resLBIST_HWPOST_INST_MCU_INDEX  :1; /*   1 */
		uint16_t resLBIST_INST_MAINR5F0_INDEX    :1; /*   2 */
		uint16_t resLBIST_INST_MAINR5F1_INDEX    :1; /*   3 */
		uint16_t resLBIST_INST_C7X0_INDEX        :1; /*   4 */
		uint16_t resLBIST_INST_C7X1_INDEX        :1; /*   5 */
		uint16_t resLBIST_INST_VPAC0_INDEX       :1; /*   6 */
		uint16_t resLBIST_INST_DMPAC_INDEX       :1; /*   7 */
		uint16_t resLBIST_INST_A72_0_INDEX       :1; /*   8 */
		uint16_t								 :7;
	}bits;
	uint16_t hWord;
}T_LbistResult;
/* Function prototypes */
void bist_TaskFxn(bool isShutDwn);
#if defined(BIST_ERRMGR_LOG)
void Bist_GetBistStatus(T_LbistResult* failedTstLBist, T_PbistResult* failedTstPBist);
#endif

#endif /* __BIST__ */
