/*
*
* Copyright (c) 2022 Texas Instruments Incorporated
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
 *  \file     bist.c
 *
 *  \brief    This file implements BIST task function
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/osal/osal.h>
#include <ti/osal/TaskP.h>

#include <ti/osal/HwiP.h>
#include <ti/csl/hw_types.h>

#include <ti/csl/csl_rat.h>
#include <soc.h>

#include <ti/drv/sciclient/sciclient.h>

#include <src/sdl/sdl_pbist.h>
#include <src/sdl/pbist/sdl_pbist_priv.h>
#if defined (BIST_SBL)
#include "sbl_log.h"
#include "fusa_osal_interface_nonos.h"
#elif defined (BIST_BOOT_APP)
#include "fusa_application.h"
#include "ErrorManagerSatellite.h"
#include "ErrorManagerShared.h"
#include "app_log.h"
#include "app_log_Boot.h"
#include "fusa_osal_interface_autosar.h"
#include "pmic.h"
#include "esm.h"
#endif

#include "bist.h"
#include "lbist_utils.h"
#include "pbist_utils.h"
#include "pbist_defs.h"
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define BIST_NAVSS_FAIL	(0x55U)
typedef struct{
	uint8_t instance[32];
	SDL_pbistRegs pbistRegsData[2];
}T_PbistRegsData;

#if defined(BIST_ERRMGR_LOG)
static struct BistResult{
	T_LbistResult lBistRes;
	T_PbistResult pBistRes;
}BistResults;
#endif	/*(BIST_ERRMGR_LOG)*/

#ifdef UART_PRINTS_ENABLED
#define PROFILE_BIST_TIMING
#endif
/*#define DEBUG_BIST_MAGNA*/
/*#define CLEC_EVENT_PBIST_A72_C7X*/
/*#define SKIP_BIST_TEST_ON_FIRST_FAILURE*/


/* Commented -- Can be enabled in Future
* #define GET_GTC_VALUE64 (*(volatile uint64_t*)(GTC_BASE_ADDR + 0x8U))
* #define GTC_TIMER_MAPPED_BASE       (0xa90000UL)
* #define GTC_TIMER_MAPPED_SIZE       (512)
* #define HZ_TO_MHZ (1000000)
*/

/* This flags enables gathering timing information for BIST stages */
#ifdef UART_PRINTS_ENABLED
#define GATHER_BIST_STAGE_DETAILS
#endif
/* For PBIST and LBIST stage tests, status is saved in bitfields.
 * For these bitfields, status is represented by below defines */
/* Commented -- Can be enabled in Future
* #define TEST_PASS_BIT         			(1)
* #define TEST_FAIL_NOT_RUN_BIT 			(0)
* #define INIT_VALUE_00_WAIT 				(0x00)
* #define INIT_VALUE_01_DONT_WAIT 		(0x01)
*/


/* ========================================================================== */
/*              Internal Function Declarations                                */
/* ========================================================================== */
static int32_t sdlApp_init(void);
static int32_t sdlApp_osalInit(void);

#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#if defined(DEBUG_BIST_MAGNA)
volatile T_PbistRegsData PbistInsRegsData[PBIST_MAX_INSTANCE];
static uintptr_t GTC_BASE_ADDR = 0;
static uint64_t mhzFreq = 0;
#endif


#if defined(PROFILE_BIST_TIMING)
volatile int32_t  tsFreqKHz;
volatile uint64_t temp_TimeStamp_start, temp_TimeStamp_end, temp_TimeStamp_diff;
volatile uint64_t temp_TimeStamp_all_start, temp_TimeStamp_all_end, temp_TimeStamp_all_diff;
#endif

static volatile uint8_t bist_test_failed_count = 0;

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

#if defined (UART_PRINTS_ENABLED)
static const char *testStatusPrint(int32_t status)
{
	  /* DD-ID: {E4D9B6FF-835A-436c-89A4-5445DDDCFBC4}*/
    char *name;

    switch(status)
    {
        case (TEST_PASS_BIT):
            name="PASS";
            break;
        case (TEST_FAIL_NOT_RUN_BIT):
            name="FAIL or NOT RUN";
            break;
        default:
            name="INVALID STATUS";
            break;
    }

    return name;
}
#endif	/*(UART_PRINTS_ENABLED)*/

void bist_TaskFxn(bool isShutDwn)
{
	/* DD-ID: {A873DD3A-2485-40ca-BFDC-78E0CF24CB52}*/
	int32_t testResult = 0;
	uint32_t     i = 0u;
	uint32_t     j = 0u;
	const uint32_t    *pbist_array = NULL;
#if defined (BIST_BOOT_APP)
	const uint32_t    *lbist_array = NULL;
#endif

#if defined (UART_PRINTS_ENABLED)
	/* Bitmap representing status of each PBIST test in each boot stage */
	int32_t     pbist_stage_status[NUM_BOOT_STAGES_PBIST] = {0};
	/* Bitmap representing status of each negative PBIST test in each boot stage */
	int32_t     pbist_stage_neg_status[NUM_BOOT_STAGES_PBIST] = {0};
	/* Bitmap representing status of each LBIST test in each boot stage */
	int32_t     lbist_stage_status[NUM_BOOT_STAGES] = {0};
#endif

#if defined (BIST_BOOT_APP)
	/* Initialize boot stage status bitmaps to "not run/fail" */
    uint8_t shutDwnStatus = 0u;
    uint8_t reportError = 0u;
#endif	/*(BIST_BOOT_APP)*/
	/* Initialize GTC Timer */
#if defined(PROFILE_BIST_TIMING)
	temp_TimeStamp_all_start = TimerP_getTimeInUsecs();
#endif /* (PROFILE_BIST_TIMING) */
	bist_test_failed_count = 0u;

#if defined (BIST_BOOT_APP)
	Cdd_Safety_NVM_Read_PMICLastResetReason_BISTStatus(1u, &shutDwnStatus);
	if((uint8_t)BIST_NAVSS_FAIL != shutDwnStatus)
	{
		if(isShutDwn == false)
		{
#endif	/* (BIST_BOOT_APP) */

#if defined(BIST_ERRMGR_LOG)
			BistResults.lBistRes.hWord =  (uint16_t) 0u;
			BistResults.pBistRes.word = (uint32_t) 0u;
#endif	/*(BIST_ERRMGR_LOG)*/

			/* Init OSAL clock */
			testResult = sdlApp_init();

			if (testResult == SDL_PASS)
			{
				(void)sdlApp_osalInit();
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"\nBIST Example Application\r\n");
#endif	/*(UART_PRINTS_ENABLED)*/
			}
			else
			{
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"\r\nBoard Init failed. Exiting the app.\r\n");
#endif	/*(UART_PRINTS_ENABLED)*/
			}

			/* Initialize boot stage status bitmaps to "not run/fail" */
			for (i = 0; i <  (uint32_t)NUM_BOOT_STAGES; i++)
			{
#if defined (UART_PRINTS_ENABLED)
				pbist_stage_status[i] = 0x0;
				pbist_stage_neg_status[i] = 0x0;
#endif

#if defined (BIST_BOOT_APP) && defined(UART_PRINTS_ENABLED)
				lbist_stage_status[i] = 0x0;
#endif
			}
#if defined (BIST_BOOT_APP)
			/* CLEC Event is only needed for PBIST of C7x and A72. */
#if defined(CLEC_EVENT_PBIST_A72_C7X)
			testResult = PBIST_commonInit();
#endif
#endif
			if (testResult != 0)
			{
#if defined (BIST_BOOT_APP)
				/* CLEC Event is only needed for PBIST of C7x and A72. */
#if defined(CLEC_EVENT_PBIST_A72_C7X)
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"PBIST_commonInit ...FAILED \n");
#endif	/*(UART_PRINTS_ENABLED)*/
#endif	/*(CLEC_EVENT_PBIST_A72_C7X)*/
#endif	/*(BIST_BOOT_APP)*/
			}
			else
			{
				/* This example presents a scenario in which the BISTs are performed in stages
				 * with booting of specific cores performed after certain stages. This example
				 * is adapted from the MCUSW Boot App for J721E. No cores are actually loaded
				 * in this example. Only the flow of performing BIST in stages is shown. */
				/* Run pre-boot-stage PBIST's.  The definitions of the pre-boot-stage PBIST's
				 * are found in soc/<SOC Device>/bist_core_defs.c.*/
				/* Run negative PBIST test */
				for (i = 0u; i < (uint32_t)num_pbists_pre_boot; i++)
				{
#if defined(SKIP_BIST_TEST_ON_FIRST_FAILURE)
					if((uint8_t)0x00 != bist_test_failed_count)
					{
						break;
					}
#endif	/*(SKIP_BIST_TEST_ON_FIRST_FAILURE)*/

#if defined(PROFILE_BIST_TIMING)
					temp_TimeStamp_start = TimerP_getTimeInUsecs();
#endif	/*(PROFILE_BIST_TIMING)*/
					/* Run negative test on selected instance */
					testResult = PBIST_runTest(pbist_pre_boot_stage[i], true);
					/* Convert signed return value (with -1 = failure and 0 = pass) to become
					 * 0 = failure and 1 = pass */
#if defined (UART_PRINTS_ENABLED)
					pbist_pre_boot_stage_neg_status[i] = testResult + 1;
#endif
					if ( testResult != 0)
					{
						bist_test_failed_count++;
#if defined (UART_PRINTS_ENABLED)
						BIST_PRINT_LOG(BIST_LOG_ERR,"PBIST negative test failed for %d - %s\n",
								pbist_pre_boot_stage[i], pbistName(pbist_pre_boot_stage[i]));
#endif	/*(UART_PRINTS_ENABLED)*/

#if defined(BIST_ERRMGR_LOG)
						BistResults.pBistRes.word |= (uint32_t)((uint32_t)1u  << pbist_pre_boot_stage[i]);
#endif	/*(BIST_ERRMGR_LOG)*/

						/* Report SS2 error */
						if(PBIST_HWPOST_MCU_INDEX == pbist_pre_boot_stage[i])
						{
							reportError = (uint8_t)SAFESTATE_REASON_SDL_PBIST_MCU_TNEG;
						}
						else
						{
							/* Do nothing */
						}
						break;
					}
					else
					{
#if defined (UART_PRINTS_ENABLED)
						BIST_PRINT_LOG(BIST_LOG_LEVEL,"PBIST negative test passed for %d - %s\n",
								pbist_pre_boot_stage[i], pbistName(pbist_pre_boot_stage[i]));
#endif	/*(UART_PRINTS_ENABLED)*/

					}

#if defined(PROFILE_BIST_TIMING)
					temp_TimeStamp_end = TimerP_getTimeInUsecs();
					temp_TimeStamp_diff = temp_TimeStamp_end - temp_TimeStamp_start;
#endif	/*(PROFILE_BIST_TIMING)*/
				}

				/* Run functional PBIST test */
				for (i = 0u; i < (uint32_t)num_pbists_pre_boot; i++)
				{
#if defined(SKIP_BIST_TEST_ON_FIRST_FAILURE)
					if((uint8_t)0x00 != bist_test_failed_count)
					{
						break;
					}
#endif	/*(SKIP_BIST_TEST_ON_FIRST_FAILURE)*/
#if defined(PROFILE_BIST_TIMING)
					temp_TimeStamp_start = TimerP_getTimeInUsecs();
#endif	/*(PROFILE_BIST_TIMING)*/
					/* Run functional test on selected instance */
					testResult = PBIST_runTest(pbist_pre_boot_stage[i], false);
					/* Convert signed return value (with -1 = failure and 0 = pass) to become
					 * 0 = failure and 1 = pass */
#if defined (UART_PRINTS_ENABLED)
					pbist_pre_boot_stage_status[i] = testResult + 1;
#endif
					if ( testResult != 0)
					{
						bist_test_failed_count++;
#if defined (UART_PRINTS_ENABLED)
						BIST_PRINT_LOG(BIST_LOG_ERR,"PBIST functional test failed for %d - %s\n",
								pbist_pre_boot_stage[i], pbistName(pbist_pre_boot_stage[i]));
#endif	/*(UART_PRINTS_ENABLED)*/

#if defined(BIST_ERRMGR_LOG)
						BistResults.pBistRes.word |= (uint32_t)((uint32_t)1u  << pbist_pre_boot_stage[i] );
#endif	/*(BIST_ERRMGR_LOG)*/

						/* Report SS2 error */
						if(PBIST_HWPOST_MCU_INDEX == pbist_pre_boot_stage[i])
						{
							reportError = (uint8_t)SAFESTATE_REASON_SDL_PBIST_MCU_TPOS;
						}
						else
						{
							/* Do nothing */
						}
						break;
					}
					else
					{
#if defined (UART_PRINTS_ENABLED)
						BIST_PRINT_LOG(BIST_LOG_LEVEL,"PBIST functional test passed for %d - %s\n",
								pbist_pre_boot_stage[i], pbistName(pbist_pre_boot_stage[i]));
#endif	/*(UART_PRINTS_ENABLED)*/
					}

#if defined(PROFILE_BIST_TIMING)
					temp_TimeStamp_end = TimerP_getTimeInUsecs();
					temp_TimeStamp_diff = temp_TimeStamp_end - temp_TimeStamp_start;
#endif	/*(PROFILE_BIST_TIMING)*/
				}
#if defined (BIST_BOOT_APP)
				/* Run pre-boot-stage LBIST's. The definitions of the pre-boot-stage LBIST's
				 * are found in soc/<SOC Device>/bist_core_defs.c. */
				for (i = 0; i < num_lbists_pre_boot; i++)
				{
#if defined(SKIP_BIST_TEST_ON_FIRST_FAILURE)
					if((uint8_t)0x00 != bist_test_failed_count)
					{
						break;
					}
#endif	/*(SKIP_BIST_TEST_ON_FIRST_FAILURE)*/
#if defined(PROFILE_BIST_TIMING)
					temp_TimeStamp_start = TimerP_getTimeInUsecs();
#endif	/*(PROFILE_BIST_TIMING)*/
					/* Run test on selected instance */
					testResult = LBIST_runTest(lbist_pre_boot_stage[i]);
#if defined (UART_PRINTS_ENABLED)
					lbist_pre_boot_stage_status[i] = testResult;
#endif
					if ((testResult == -1) ||
							(testResult == (int32_t)LBIST_POST_COMPLETED_FAILURE) ||
							(testResult == (int32_t)LBIST_POST_ATTEMPTED_TIMEOUT))
					{
						bist_test_failed_count++;
#if defined (UART_PRINTS_ENABLED)
						BIST_PRINT_LOG(BIST_LOG_ERR,"LBIST functional test failed for %d - %s\n",
								lbist_pre_boot_stage[i], lbistName(lbist_pre_boot_stage[i]));
#endif /*(UART_PRINTS_ENABLED)*/

#if defined(BIST_ERRMGR_LOG)
						BistResults.lBistRes.hWord |= (uint16_t)((uint16_t)1u << lbist_pre_boot_stage[i] );
#endif	/*(BIST_ERRMGR_LOG)*/

						/* Report SS2 error */
						if((uint32_t)LBIST_HWPOST_INST_SMS_INDEX == lbist_pre_boot_stage[i])
						{
							reportError = (uint8_t)SAFESTATE_REASON_SDL_LBIST_SMS;
						}
						else if((uint32_t)LBIST_HWPOST_INST_MCU_INDEX == lbist_pre_boot_stage[i])
						{
							reportError = (uint8_t)SAFESTATE_REASON_SDL_LBIST_MCU;
						}
						else
						{
							/* Do nothing */
						}
						break;
					}
					else
					{
#if defined (UART_PRINTS_ENABLED)
						BIST_PRINT_LOG(BIST_LOG_LEVEL,"LBIST functional test passed for %d - %s\n",
								lbist_pre_boot_stage[i], lbistName(lbist_pre_boot_stage[i]));
#endif	/*(UART_PRINTS_ENABLED)*/
					}

#if defined(PROFILE_BIST_TIMING)
					temp_TimeStamp_end = TimerP_getTimeInUsecs();
					temp_TimeStamp_diff = temp_TimeStamp_end - temp_TimeStamp_start;
#endif	/*(PROFILE_BIST_TIMING)*/
				}
				/* CLEC Event is only needed for PBIST of C7x and A72. */
#if defined(CLEC_EVENT_PBIST_A72_C7X)
				/* After running PBIST potentially on MSMC, re-initialize the CLEC */
				testResult = PBIST_commonInit();
				if (testResult != 0)
				{
					/* CLEC Event is only needed for PBIST of C7x and A72. */
#if defined(CLEC_EVENT_PBIST_A72_C7X)
#if defined (UART_PRINTS_ENABLED)
					BIST_PRINT_LOG(BIST_LOG_LEVEL,"PBIST_commonInit after pre-boot stage ...FAILED \n");
#endif	/*(CLEC_EVENT_PBIST_A72_C7X)*/
#endif	/*(UART_PRINTS_ENABLED)*/
				}
#endif

#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"\n *** pre-boot stage is complete,  ***\n\n");
#endif	/*(UART_PRINTS_ENABLED)*/
				/* Run LBIST and PBIST before each boot stage.  The definitions of the LBIST
				 * and PBIST sections for each stage are defined in
				 * soc/<SOC Device>/bist_core_defs.c. */
				for (j = 0; j < (uint32_t)NUM_BOOT_STAGES; j++)
				{
#if defined(SKIP_BIST_TEST_ON_FIRST_FAILURE)
					if((uint8_t)0x00 != bist_test_failed_count)
					{
						break;
					}
#endif	/*(SKIP_BIST_TEST_ON_FIRST_FAILURE)*/
					lbist_array = lbist_array_stage[j];
					pbist_array = pbist_array_stage[j];
					/* Run negative PBIST test */
					for (i = 0; i < num_pbists_per_boot_stage[j]; i++)
					{
#if defined(SKIP_BIST_TEST_ON_FIRST_FAILURE)
						if((uint8_t)0x00 != bist_test_failed_count)
						{
							break;
						}
#endif
#if defined(PROFILE_BIST_TIMING)
						temp_TimeStamp_start = TimerP_getTimeInUsecs();
#endif	/*(PROFILE_BIST_TIMING)*/

						/* CLEC Event is only needed for PBIST of C7x and A72. */
#if defined(CLEC_EVENT_PBIST_A72_C7X)
						PBIST_clecConfig(pbist_array[i]);
#endif	/*(PROFILE_BIST_TIMING)*/

						/* Run negative test on selected instance */
						testResult = PBIST_runTest(pbist_array[i], true);

#if defined (UART_PRINTS_ENABLED)
						/* Convert signed return value (with -1 = failure and 0 = pass) to become
						 * a single bit as part of bitfield with 0 = failure and 1 = pass */
						pbist_stage_neg_status[j] |= ((uint32_t)(testResult + 1) << i);
#endif
						if ( testResult != 0)
						{
							bist_test_failed_count++;
#if defined (UART_PRINTS_ENABLED)
							BIST_PRINT_LOG(BIST_LOG_ERR,"PBIST negative test failed for %d - %s\n",
									pbist_array[i], pbistName(pbist_array[i]));
#endif	/*(PROFILE_BIST_TIMING)*/

#if defined(BIST_ERRMGR_LOG)
							BistResults.pBistRes.word |= ( (uint32_t)1u  <<  pbist_pre_boot_stage[i] );
#endif	/*(BIST_ERRMGR_LOG)*/

							/* Report SS2 error */
							if(PBIST_INSTANCE_MAINR5F0 == pbist_array[i])
							{
								reportError = (uint8_t)SAFESTATE_REASON_SDL_PBIST_MAINR5_TNEG;
							}
							else
							{
								/* Do nothing */
							}
							break;
						}
						else
						{
#if defined (UART_PRINTS_ENABLED)
							BIST_PRINT_LOG(BIST_LOG_LEVEL,"PBIST negative test passed for %d - %s\n",
									pbist_array[i], pbistName(pbist_array[i]));
#endif	/*(PROFILE_BIST_TIMING)*/
						}

#if defined(PROFILE_BIST_TIMING)
						temp_TimeStamp_end = TimerP_getTimeInUsecs();
						temp_TimeStamp_diff = temp_TimeStamp_end - temp_TimeStamp_start;
#endif	/*(PROFILE_BIST_TIMING)*/
					}

					/* Run functional PBIST test */
					for (i = 0; i < num_pbists_per_boot_stage[j]; i++)
					{
#if defined(SKIP_BIST_TEST_ON_FIRST_FAILURE)
						if((uint8_t)0x00 != bist_test_failed_count)
						{
							break;
						}
#endif
#if defined(PROFILE_BIST_TIMING)
						temp_TimeStamp_start = TimerP_getTimeInUsecs();
#endif	/*(PROFILE_BIST_TIMING)*/
						/* Run functional test on selected instance */
						testResult = PBIST_runTest(pbist_array[i], false);

						/* Convert signed return value (with -1 = failure and 0 = pass) to become
						 * a single bit as part of bitfield with 0 = failure and 1 = pass */
#if defined (UART_PRINTS_ENABLED)
						pbist_stage_status[j] |= ((uint32_t)(testResult + 1) << i);
#endif	/*(UART_PRINTS_ENABLED)*/

						if ( testResult != 0)
						{
							bist_test_failed_count++;
#if defined (UART_PRINTS_ENABLED)
							BIST_PRINT_LOG(BIST_LOG_ERR,"PBIST functional test failed for %d - %s\n",
									pbist_array[i], pbistName(pbist_array[i]));
#endif	/*(UART_PRINTS_ENABLED)*/

#if defined(BIST_ERRMGR_LOG)
							BistResults.pBistRes.word |= (uint32_t)( (uint32_t)1u << pbist_array[i] );
#endif	/*(BIST_ERRMGR_LOG)*/

							/* Report SS2 error */
							if(PBIST_INSTANCE_MAINR5F0 == pbist_array[i])
							{
								reportError = (uint8_t)SAFESTATE_REASON_SDL_PBIST_MAINR5_TPOS;
							}
							else
							{
								/* Do nothing */
							}
							break;
						}
						else
						{
#if defined (UART_PRINTS_ENABLED)
							BIST_PRINT_LOG(BIST_LOG_LEVEL,"PBIST functional test passed for %d - %s\n",
									pbist_array[i], pbistName(pbist_array[i]));
#endif	/*(UART_PRINTS_ENABLED)*/
												/*BistResults.pBistRes.word &= ~( 1 << pbist_array[i] );*/
						}
#if defined(PROFILE_BIST_TIMING)
						temp_TimeStamp_end = TimerP_getTimeInUsecs();
						temp_TimeStamp_diff = temp_TimeStamp_end - temp_TimeStamp_start;
#endif	/*(PROFILE_BIST_TIMING)*/
					}
#if defined (UART_PRINTS_ENABLED)
					BIST_PRINT_LOG(BIST_LOG_LEVEL, "Ran PBIST for Stage %d\n", j);
#endif	/*(UART_PRINTS_ENABLED)*/
					/* Run functional LBIST test */
					for (i = 0; i < num_lbists_per_boot_stage[j]; i++)
					{
#if defined(SKIP_BIST_TEST_ON_FIRST_FAILURE)
						if((uint8_t)0x00 != bist_test_failed_count)
						{
							break;
						}
#endif	/*(SKIP_BIST_TEST_ON_FIRST_FAILURE)*/
#if defined(PROFILE_BIST_TIMING)
						temp_TimeStamp_start = TimerP_getTimeInUsecs();
#endif	/*(PROFILE_BIST_TIMING)*/
						testResult = LBIST_runTest(lbist_array[i]);

#if defined (UART_PRINTS_ENABLED)
						/* Convert signed return value (with -1 = failure and 0 = pass) to become
						 * a single bit as part of bitfield with 0 = failure and 1 = pass */
						lbist_stage_status[j] |= ((uint32_t)(testResult + 1) << i);
#endif
						if (testResult != 0)
						{
							bist_test_failed_count++;
#if defined (UART_PRINTS_ENABLED)
							BIST_PRINT_LOG(BIST_LOG_ERR,"\nLBIST functional test failed for %d - %s\n",
									lbist_array[i], lbistName(lbist_array[i]));
#endif	/*(UART_PRINTS_ENABLED)*/

#if defined(BIST_ERRMGR_LOG)
							BistResults.lBistRes.hWord |=  ( (uint32_t)1u << lbist_array[i] );
#endif	/*(BIST_ERRMGR_LOG)*/

							/* Report SS2 error */
							if((uint32_t)LBIST_INST_MAINR5F0_INDEX == lbist_array[i])
							{
								reportError = (uint8_t)SAFESTATE_REASON_SDL_LBIST_MAINR5;
							}
							else
							{
								/* Do nothing */
							}
							break;
						}
						else
						{
#if defined (UART_PRINTS_ENABLED)
							BIST_PRINT_LOG(BIST_LOG_LEVEL,"LBIST functional test passed for %d - %s\n",
									lbist_array[i], lbistName(lbist_array[i]));
#endif	/*(UART_PRINTS_ENABLED)*/
												/*BistResults.lBistRes.hWord &= ~( 1 << lbist_array[i] );*/
						}
#if defined(PROFILE_BIST_TIMING)
						temp_TimeStamp_end = TimerP_getTimeInUsecs();
						temp_TimeStamp_diff = temp_TimeStamp_end - temp_TimeStamp_start;
#endif	/*(PROFILE_BIST_TIMING)*/
					}
				}
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL, "Ran LBIST for Stage %d\n", j);
#endif	/*(UART_PRINTS_ENABLED)*/

#if defined (UART_PRINTS_ENABLED)
				/* Signal Boot Task that BIST for the stage is completed */
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"\n *** Boot stage %d is complete, cores for this stage may now be loaded ***\n\n", j);
#endif	/*(UART_PRINTS_ENABLED)*/
#endif
			}
#if defined (BIST_BOOT_APP)
		}
		else
		{
			/* Reset ESM configuration */
			ESM_DeInit();
			pbist_array = pbist_array_stage[1];
			/* Run negative PBIST test */
			for (i = 0; i < num_pbists_per_boot_stage[1]; i++)
			{
#if defined(PROFILE_BIST_TIMING)
				temp_TimeStamp_start = TimerP_getTimeInUsecs();
#endif	/*(PROFILE_BIST_TIMING)*/

				/* Run negative test on selected instance */
				testResult = PBIST_runTest(pbist_array[i], true);

#if defined (UART_PRINTS_ENABLED)
				/* Convert signed return value (with -1 = failure and 0 = pass) to become
				 * a single bit as part of bitfield with 0 = failure and 1 = pass */
				pbist_stage_neg_status[1] |= ((uint32_t)(testResult + 1) << i);
#endif	/*(UART_PRINTS_ENABLED)*/
				if ( testResult != 0)
				{
					bist_test_failed_count++;
#if defined (UART_PRINTS_ENABLED)
					BIST_PRINT_LOG(BIST_LOG_ERR,"PBIST negative test failed for %d - %s\n",
							pbist_array[i], pbistName(pbist_array[i]));
#endif	/*(PROFILE_BIST_TIMING)*/

#if defined(BIST_ERRMGR_LOG)
					BistResults.pBistRes.word |= (uint32_t)( (uint32_t)1u << pbist_pre_boot_stage[i] );
#endif	/*(BIST_ERRMGR_LOG)*/
					break;
				}
				else
				{
#if defined (UART_PRINTS_ENABLED)
					BIST_PRINT_LOG(BIST_LOG_LEVEL,"PBIST negative test passed for %d - %s\n",
							pbist_array[i], pbistName(pbist_array[i]));
#endif	/*(PROFILE_BIST_TIMING)*/
				}

#if defined(PROFILE_BIST_TIMING)
				temp_TimeStamp_end = TimerP_getTimeInUsecs();
				temp_TimeStamp_diff = temp_TimeStamp_end - temp_TimeStamp_start;
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"\n Time taken by negative PBIST - %s = %d mS =============\n", pbistName(pbist_array[i]), (uint32_t)temp_TimeStamp_diff/1000u);
#endif	/*(PROFILE_BIST_TIMING)*/
			}

			/* Run functional PBIST test */
			for (i = 0; i < num_pbists_per_boot_stage[1]; i++)
			{
#if defined(PROFILE_BIST_TIMING)
				temp_TimeStamp_start = TimerP_getTimeInUsecs();
#endif	/*(PROFILE_BIST_TIMING)*/
				/* Run functional test on selected instance */
				testResult = PBIST_runTest(pbist_array[i], false);

#if defined (UART_PRINTS_ENABLED)
				/* Convert signed return value (with -1 = failure and 0 = pass) to become
				 * a single bit as part of bitfield with 0 = failure and 1 = pass */
				pbist_stage_status[1] |= ((uint32_t)(testResult + 1u) << i);
#endif
				if ( testResult != 0)
				{
					bist_test_failed_count++;
#if defined (UART_PRINTS_ENABLED)
					BIST_PRINT_LOG(BIST_LOG_ERR,"\nShutdown Test: PBIST functional test failed for %d - %s\n",
							pbist_array[i], pbistName(pbist_array[i]));
#endif	/*(UART_PRINTS_ENABLED)*/

#if defined(BIST_ERRMGR_LOG)
					BistResults.pBistRes.word |= (uint32_t)( (uint32_t)1u << pbist_array[i] );
#endif	/*(BIST_ERRMGR_LOG)*/
					break;
				}
				else
				{
#if defined (UART_PRINTS_ENABLED)
					BIST_PRINT_LOG(BIST_LOG_LEVEL,"\nShutdown Test: PBIST functional test passed for %d - %s\n",
							pbist_array[i], pbistName(pbist_array[i]));
#endif	/*(UART_PRINTS_ENABLED)*/
				}
#if defined(PROFILE_BIST_TIMING)
				temp_TimeStamp_end = TimerP_getTimeInUsecs();
				temp_TimeStamp_diff = temp_TimeStamp_end - temp_TimeStamp_start;
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"\n Time taken by Functional PBIST - %s = %d mS =============\n", pbistName(pbist_array[i]), (uint32_t)temp_TimeStamp_diff/1000u);
#endif	/*(PROFILE_BIST_TIMING)*/
			}
		}
	}
#endif /*(BIST_BOOT_APP)*/

#if defined(PROFILE_BIST_TIMING)
    temp_TimeStamp_all_end = TimerP_getTimeInUsecs();
    temp_TimeStamp_all_diff = temp_TimeStamp_all_end - temp_TimeStamp_all_start;
#endif	/*(PROFILE_BIST_TIMING)*/

#if defined (UART_PRINTS_ENABLED)
	if (testResult == 0)
	{
		BIST_PRINT_LOG(BIST_LOG_LEVEL,"==========================\n");
		BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Example App Summary:\n");
		BIST_PRINT_LOG(BIST_LOG_LEVEL,"==========================\n");
#if defined (BIST_BOOT_APP)
		if (FALSE == isShutDwn)
		{
#endif	/*(BIST_BOOT_APP)*/
#if defined (UART_PRINTS_ENABLED)
			BIST_PRINT_LOG(BIST_LOG_LEVEL,"PBIST Results:	\n");
#endif
			for (i = 0; i < num_pbists_pre_boot; i++)
			{
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Pre-boot Stage - Ran negative PBIST ID - %s, Result = %s\n",
						pbistName(pbist_pre_boot_stage[i]),
						testStatusPrint(pbist_pre_boot_stage_neg_status[i]));
#endif
			}
#if defined (UART_PRINTS_ENABLED)
			BIST_PRINT_LOG(BIST_LOG_LEVEL,"Pre-boot stage - Ran %d negative PBIST total sections\n",
					num_pbists_pre_boot);
#endif
			for (i = 0; i < num_pbists_pre_boot; i++)
			{
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Pre-boot Stage - Ran PBIST ID - %s, Result = %s\n",
						pbistName(pbist_pre_boot_stage[i]),
						testStatusPrint(pbist_pre_boot_stage_status[i]));
#endif
			}
#if defined (UART_PRINTS_ENABLED)
			BIST_PRINT_LOG(BIST_LOG_LEVEL,"Pre-boot stage - Ran %d PBIST total sections\n",
					num_pbists_pre_boot);
#endif

#if defined (BIST_BOOT_APP)
			for (j = 0; j < NUM_BOOT_STAGES; j++)
			{
				pbist_array = pbist_array_stage[j];
#if defined(GATHER_BIST_STAGE_DETAILS)
				for (i = 0; i < num_pbists_per_boot_stage[j]; i++)
				{
#if defined (UART_PRINTS_ENABLED)
					BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Stage %d - Ran negative PBIST ID - %s, Result = %s\n",
							j, pbistName(pbist_array[i]),
							testStatusPrint((pbist_stage_neg_status[j] >> i) & 0x1));
#endif
				}
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Stage %d - Ran %d negative PBIST total sections\n",
						j, (uint32_t)num_pbists_per_boot_stage[j]);
#endif

				for (i = 0; i < num_pbists_per_boot_stage[j]; i++)
				{
#if defined (UART_PRINTS_ENABLED)
					BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Stage %d - Ran PBIST ID - %s, Result = %s\n",
							j, pbistName(pbist_array[i]),
							testStatusPrint((pbist_stage_status[j] >> i) & 0x1));
#endif
				}
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Stage %d - Ran %d PBIST total sections\n",
						j, (uint32_t)num_pbists_per_boot_stage[j]);
#endif
#endif	/*(GATHER_BIST_STAGE_DETAILS)*/
			}

#if defined (UART_PRINTS_ENABLED)
			BIST_PRINT_LOG(BIST_LOG_LEVEL,"LBIST Results:	\n");
#endif
			for (i = 0; i < num_lbists_pre_boot; i++)
			{
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Pre-boot Stage - Ran LBIST ID - %s, Result = %s\n",
						lbistName(lbist_pre_boot_stage[i]),
						LBIST_hwPostStatusPrint(lbist_pre_boot_stage_status[i]));
#endif
			}
#if defined (UART_PRINTS_ENABLED)
			BIST_PRINT_LOG(BIST_LOG_LEVEL,"Pre-boot stage - Ran %d LBIST total sections\n",
					num_lbists_pre_boot);
#endif

			for (j = 0; j < NUM_BOOT_STAGES; j++)
			{
				lbist_array = lbist_array_stage[j];
#if defined(GATHER_BIST_STAGE_DETAILS)
				for (i = 0; i < num_lbists_per_boot_stage[j]; i++)
				{
#if defined (UART_PRINTS_ENABLED)
					BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Stage %d - Ran LBIST ID - %s, Result = %s\n",
							j, lbistName(lbist_array[i]),
#endif
							testStatusPrint((lbist_stage_status[j] >> i) & 0x1));
				}
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Stage %d - Ran %d LBIST sections\n",
						j, (uint32_t)num_lbists_per_boot_stage[j]);
#endif
#endif	/* (GATHER_BIST_STAGE_DETAILS)*/
			}
		}
		else
		{
#if defined (UART_PRINTS_ENABLED)
			BIST_PRINT_LOG(BIST_LOG_LEVEL,"PBIST TEST AT SHUTDOWN Results:	\n");
#endif
			pbist_array = pbist_array_stage[1];
#if defined(GATHER_BIST_STAGE_DETAILS)
			for (i = 0; i < num_pbists_per_boot_stage[1]; i++)
			{
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Stage %d - Ran negative PBIST ID - %s, Result = %s\n",
						2, pbistName(pbist_array[i]),
						testStatusPrint((pbist_stage_neg_status[1] >> i) & 0x1));
#endif
			}
#if defined (UART_PRINTS_ENABLED)
			BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Stage %d - Ran %d negative PBIST total sections\n",
					2, (uint32_t)num_pbists_per_boot_stage[1]);
#endif
			for (i = 0; i < num_pbists_per_boot_stage[1]; i++)
			{
#if defined (UART_PRINTS_ENABLED)
				BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Stage %d - Ran PBIST ID - %s, Result = %s\n",
						2, pbistName(pbist_array[i]),
						testStatusPrint((pbist_stage_status[1] >> i) & 0x1));
#endif
			}
#if defined (UART_PRINTS_ENABLED)
			BIST_PRINT_LOG(BIST_LOG_LEVEL,"BIST: Stage %d - Ran %d PBIST total sections\n",
					2, (uint32_t)num_pbists_per_boot_stage[1]);
#endif
#endif	/* (GATHER_BIST_STAGE_DETAILS)*/
		}
#endif	/*(BIST_BOOT_APP)*/
	}
#endif /*(UART_PRINTS_ENABLED)*/

#if defined (UART_PRINTS_ENABLED)
	BIST_PRINT_LOG(BIST_LOG_LEVEL,"\n============= Time taken by PBIST/LBIST = %d mS =============\n", (uint32_t)temp_TimeStamp_all_diff/1000);
#endif /*(UART_PRINTS_ENABLED)*/

#if defined (BIST_BOOT_APP)
	if((uint8_t)0x00 != bist_test_failed_count)
	{
		if(false == isShutDwn)
		{
#if defined (UART_PRINTS_ENABLED)
			BIST_PRINT_LOG(BIST_LOG_ERR,"\n PMIC: reset requested with Pmic_F_SafeState2_v: %d\n",reportError);
#endif /*(UART_PRINTS_ENABLED)*/

#if defined(BIST_ERRMGR_LOG)
			if(BistResults.lBistRes.hWord != 0u)
			{
				Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_LBIST, (uint8_t)TRUE);
			}

			if(BistResults.pBistRes.word != 0u)
			{
				Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_PBIST, (uint8_t)TRUE);
			}
#endif	/*(BIST_ERRMGR_LOG)*/

			/* Report error to CAN msg */
  			f_Send_Dbg_SDLFault_CanTx((uint16)reportError);
			/* Achieve SafeState2 by resetting SOC */
			Pmic_F_SafeState2_v(reportError);
		}
		else
		{
			Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus((uint8_t)1u,(uint8_t) BIST_NAVSS_FAIL,(uint8_t)TRUE);
		}
	}
#endif  /*(BIST_BOOT_APP)*/
}

static int32_t sdlApp_init(void)
{
  /* DD-ID: {4BB15D96-61C4-4382-81DE-A5F177760079}*/
    int32_t       testResult = SDL_PASS;

    uint64_t mcuClkFreq=1000000000U;

    /* Following code is needed to set Osal timing */
    testResult = Sciclient_pmGetModuleClkFreq(TISCI_DEV_MCU_R5FSS0_CORE0,
                                              TISCI_DEV_MCU_R5FSS0_CORE0_CPU_CLK,
                                              &mcuClkFreq,
                                              SCICLIENT_SERVICE_WAIT_FOREVER);
    if (testResult == SDL_PASS)
    {
        Osal_HwAttrs  hwAttrs;
        uint32_t      ctrlBitmap;

        testResult = Osal_getHwAttrs(&hwAttrs);
        if (testResult == 0)
        {
            /*
             * Change the timer input clock frequency configuration
               based on R5 CPU clock configured
             */
            hwAttrs.cpuFreqKHz = (int32_t)(mcuClkFreq/1000U);
            ctrlBitmap         = OSAL_HWATTR_SET_CPU_FREQ;
            testResult = Osal_setHwAttrs(ctrlBitmap, &hwAttrs);
        }
    }
    #if defined (UART_PRINTS_ENABLED)
    BIST_PRINT_LOG(BIST_LOG_LEVEL,"mcuClkFreq %d\n", (uint32_t)mcuClkFreq);
    #endif

    return (testResult);
}

static int32_t sdlApp_osalInit(void)
{
  /* DD-ID: {B929D93C-6B03-44da-B7BF-D26B5C5E6FBA}*/
	SDL_ErrType_t ret = SDL_PASS;

#if defined (BIST_SBL)
	ret = FUSA_freeRTOS_osalInit();
#elif defined (BIST_BOOT_APP)
	ret = FUSA_autosar_osalInit();
#endif

	if (ret != SDL_PASS)
	{
#if defined (UART_PRINTS_ENABLED)
		BIST_PRINT_LOG(BIST_LOG_ERR,"Error: Init Failed\n");
#endif
	}

	return ret;
}

#if defined(BIST_ERRMGR_LOG)
void Bist_GetBistStatus(T_LbistResult* failedTstLBist, T_PbistResult* failedTstPBist)
{
  /* DD-ID: {40B2D23E-C014-4e6e-8D65-5321FB7A0750}*/
	if((failedTstLBist != NULL) && (failedTstPBist != NULL))
	{
		failedTstLBist->hWord = BistResults.lBistRes.hWord;
		failedTstPBist->word = BistResults.pBistRes.word;
	}
}
#endif

#if defined(DEBUG_BIST_MAGNA)
void BIST_ReadPbistRegs(SDL_PBIST_testType testType, SDL_pbistRegs *pRegs)
{
  /* DD-ID: {1B8DAC79-DD06-4585-9C57-A4DFBBE1FC2B}*/
	uint8_t instance = 0u;
	uint8_t actInst = 0u;
	SDL_pbistInstInfo *pInfo = NULL;
	if(NULL != pRegs)
	{
		for(instance = 0u; instance < PBIST_MAX_INSTANCE; instance++)
		{
			pInfo = SDL_PBIST_getInstInfo(instance);
			if(pInfo->pPBISTRegs == pRegs)
			{
				/*BIST_PRINT_LOG(BIST_LOG_LEVEL,"\n\tInside BIST_ReadPbistRegs %d - %s, TestType = %d\n\n", instance, pbistName(instance), testType);*/
				break;
			}
		}


		if(instance<PBIST_MAX_INSTANCE)
		{
			actInst = instance + 1u;
			BIST_PRINT_LOG(BIST_LOG_ERR,"\n\tInside BIST_ReadPbistRegs %d - %s, TestType = %d\n\n", actInst, pbistName(actInst), testType);
			(void)strcpy((void *)&PbistInsRegsData[actInst].instance[0], (void *)pbistName(actInst));
			(void)memcpy((void *)&PbistInsRegsData[actInst].pbistRegsData[testType], (void *)pRegs,sizeof(SDL_pbistRegs));
		}
		pInfo = NULL;
	}
	if(PbistInsRegsData[actInst].pbistRegsData[testType].FSRC){}
}
#endif	/*DEBUG_BIST_MAGNA*/
/* Nothing Beyond this line*/
#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
