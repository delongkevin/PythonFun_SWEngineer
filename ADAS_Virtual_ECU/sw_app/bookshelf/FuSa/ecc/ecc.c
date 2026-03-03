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
 *  \file     ecc_main.c
 *
 * \brief This file demonstrates using the Error Correcting Code Module (ECC),
 *         utilizing the ECC and ESM Software Diagnostic Reference (SDL) functions.
 *
 *  \details  ESM Safety Example module tests
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "PlatformDataTypes.h"
#include <ti/drv/sciclient/sciclient.h>
#include <ti/osal/osal.h>
#include <ti/osal/TimerP.h>
#include <sdl_ecc.h>
#include <include/soc/j721s2/sdlr_intr_wkup_esm0.h>
#include <include/soc/j721s2/sdlr_intr_esm0.h>
#include <include/soc/j721s2/sdlr_intr_mcu_esm0.h>
#include <include/soc/j721s2/sdlr_soc_baseaddress.h>
#include "fusa_osal_interface_autosar.h"
#include "ecc_ddr.h"
#include "fusa_application.h"
#include "ecc_main.h"
#include "pmic.h"
#include "ErrorManagerSatellite.h"
#include "ErrorManagerShared.h"
#include "app_log.h"
#include "app_log_Boot.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
/*#define UART_PRINTS_ENABLED*/
/*#define UART_INTR_PRINTS_ENABLED*/


#define CDD_Safety_START_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* Part of DDR Fault Injecting test */
#if ( SDL_APP_DDR_ECC_SELFTEST_ENABLED == SDL_APP_ON )
volatile uint32_t gSecTestPass;
volatile uint32_t gDedTestPass;
#endif

#if defined (DEBUG_ECC_MAGNA)
volatile bool esmError = false;
extern uint8_t sdl_ecc_test;
#endif

#define CDD_Safety_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CDD_Safety_MemMap.h"

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

#define CDD_Safety_START_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static int32_t SDL_ESM_DDR_ECC_ErrorHandle(uint32_t intSrc)
{
  /* DD-ID: {BC57D441-1BA7-4376-B400-F4D1CBA89376}*/
    int32_t                             cslRet = CSL_PASS;
    CSL_ECCErrorInfo                    ECCErrorInfo;
    ldef_ErrorMgr_stAddData SDL_EccAddtionalData_au8 = {0u};

    switch (intSrc){
    case CSLR_ESM0_ESM_LVL_EVENT_DDR0_DDRSS_DRAM_ECC_CORR_ERR_LVL_0:
        /* Currently single bit correctable error are not reported so simply acknoledge the error and return */
        /* Read ECC registers and double check address */

        cslRet = CSL_emifGetECCErrorInfo((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE,
                                          &ECCErrorInfo);
        if (cslRet != CSL_PASS)
        {
#ifdef UART_PRINTS_ENABLED
            APP_log(APP_LOG_ERR,"\r\n CSL_emifConfig ");
#endif
            break;
        }

        if ((ECCErrorInfo.singlebitErrorAddress & (~0x7u))
            == (((uint32_t)DDR_ECC_TEST_ADDR- EMIF_DDR_START_ADDR) & (~0x7u)))
        {
        	/* Single DDR ECC Test */
#if ( SDL_APP_DDR_ECC_SELFTEST_ENABLED == SDL_APP_ON )
            gSecTestPass = TRUE;
#endif
        }

        /* Clear Specific ECC error */
        cslRet = CSL_emifClearECCError((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE,
                                       CSL_EMIF_ECC_ERROR_TYPE_SINGLE_BIT);
        if (cslRet != CSL_PASS)
        {
#ifdef UART_PRINTS_ENABLED
            APP_log(APP_LOG_ERR,"\r\n CSL_emifClearECCErrors  failed ");
#endif
            break;
        }

        /* Clear ECC interupt bits */
        cslRet = CSL_emifClearECCInterruptStatus((CSL_emif_sscfgRegs *)SDL_COMPUTE_CLUSTER0_DDR0_0_SS_CFG_BASE,
                                                 CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECC1BERR_EN_MASK
                                                 | CSL_EMIF_SSCFG_V2A_INT_SET_REG_ECCM1BERR_EN_MASK);
        if (cslRet != CSL_PASS)
        {
#ifdef UART_PRINTS_ENABLED
            APP_log(APP_LOG_ERR,"\r\n CSL_emifClearECCInterruptStatus Failed ");
#endif
            break;
        }
        break;
    case CSLR_ESM0_ESM_LVL_EVENT_DDR0_DDRSS_DRAM_ECC_UNCORR_ERR_LVL_0:

		#if ( SDL_APP_DDR_ECC_SELFTEST_ENABLED == SDL_APP_ON )
					gDedTestPass = TRUE;
		#endif

		(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_DDRSS0_Two_BIT_and_multibit_ECC_Failure_in_DDR_data,
                                    ldef_ErrorMgr_ErrorActive,
                                    &SDL_EccAddtionalData_au8);

					 /* Report error to CAN msg */
        f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_DDRSS0_Two_BIT_and_multibit_ECC_Failure_in_DDR_data);

#ifdef UART_PRINTS_ENABLED
        APP_log(APP_LOG_ERR,"\r\n DDR_ECC_DED_ERR_EVENT Event detected ");
#endif
        break;
#if defined(SDL_APP_DDR_PARITY_ENABLED)
    case CSLR_ESM0_ESM_LVL_EVENT_DDR0_DDRSS_CONTROLLER_GLOBAL_ERROR_FATAL_0:
#ifdef UART_PRINTS_ENABLED
        APP_log(APP_LOG_MAX,"\r\n DDR Controller PARITY Event detected ");
#endif
        (void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_DDRSS0_Parity_check_failure_in_DDRSS,
                                            ldef_ErrorMgr_ErrorActive,
                                            &SDL_EccAddtionalData_au8);
				 /* Report error to CAN msg */
        f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_DDRSS0_Parity_check_failure_in_DDRSS);
    break;

    case CSLR_ESM0_ESM_LVL_EVENT_DDR0_DDRSS_HS_PHY_GLOBAL_ERROR_0:
#ifdef UART_PRINTS_ENABLED
        APP_log(APP_LOG_MAX,"\r\n DDR PHY PARITY Event detected ");
#endif
        (void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_DDRSS0_Parity_check_failure_in_DDRSS,
                                            ldef_ErrorMgr_ErrorActive,
                                            &SDL_EccAddtionalData_au8);
			/* Report error to CAN msg */
        f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_DDRSS0_Parity_check_failure_in_DDRSS);
    break;
#endif
    default:
    	/* Do nothing */
        break;
    }

    return cslRet;
}


int32_t SDL_ESM_ECC_applicationCallbackFunction(SDL_ESM_Inst esmInst,
                                            SDL_ESM_IntType esmIntrType,
                                            uint32_t grpChannel,
                                            uint32_t index,
                                            uint32_t intSrc,
                                            uintptr_t *arg)
{
    /* DD-ID: {9BD00118-4685-49a7-B2F9-156B8D46B495}*/
	SDL_ECC_MemType eccmemtype;
	SDL_Ecc_AggrIntrSrc eccIntrSrc;
	SDL_ECC_ErrorInfo_t eccErrorInfo;
	int32_t retVal;
	ldef_ErrorMgr_stAddData SDL_EccAddtionalData_au8 = {0u};

    (void)esmIntrType;
    (void)index;
    (void)arg;
    (void)grpChannel;

#ifdef UART_INTR_PRINTS_ENABLED
	APP_log(APP_LOG_MAX,"\n  ECC Call back function called \n");
#endif
#ifdef UART_PRINTS_ENABLED
	if(esmIntrType == 1u){
		APP_log(APP_LOG_MAX," High Priority Interrupt Executed\n");
	}
	else{
		APP_log(APP_LOG_MAX," Low Priority Interrupt Executed\n");
	}
#endif
	if ((esmInst == SDL_ESM_INST_MAIN_ESM0) && ((intSrc == SDLR_ESM0_ESM_LVL_EVENT_DDR0_DDRSS_DRAM_ECC_CORR_ERR_LVL_0)
			|| (intSrc == SDLR_ESM0_ESM_LVL_EVENT_DDR0_DDRSS_DRAM_ECC_UNCORR_ERR_LVL_0)
#if defined(SDL_APP_DDR_PARITY_ENABLED)
			|| (intSrc == SDLR_ESM0_ESM_LVL_EVENT_DDR0_DDRSS_CONTROLLER_GLOBAL_ERROR_FATAL_0)
			|| (intSrc == SDLR_ESM0_ESM_LVL_EVENT_DDR0_DDRSS_HS_PHY_GLOBAL_ERROR_0)
#endif
	))
	{
		retVal = SDL_ESM_DDR_ECC_ErrorHandle(intSrc);
	} else {


		retVal = SDL_ECC_getESMErrorInfo(esmInst, intSrc, &eccmemtype, &eccIntrSrc);

		/* Any additional customer specific actions can be added here */
		retVal = SDL_ECC_getErrorInfo(eccmemtype, eccIntrSrc, &eccErrorInfo);
#ifdef 	Enable_Printf		
		APP_log(APP_LOG_ERR,"\n  ECC Error Call back function called : eccMemType %d, errorSrc 0x%x, " \
				"ramId %d\n", \
				eccmemtype, eccIntrSrc, eccErrorInfo.memSubType);
#endif
		if (eccErrorInfo.injectBitErrCnt != 0u)
		{
			(void)SDL_ECC_clearNIntrPending(eccmemtype, eccErrorInfo.memSubType, eccIntrSrc, SDL_ECC_AGGR_ERROR_SUBTYPE_INJECT, eccErrorInfo.injectBitErrCnt);
		}
		else
		{
			(void)SDL_ECC_clearNIntrPending(eccmemtype, eccErrorInfo.memSubType, eccIntrSrc, SDL_ECC_AGGR_ERROR_SUBTYPE_NORMAL, eccErrorInfo.bitErrCnt);
		}

		retVal = SDL_ECC_ackIntr(eccmemtype, eccIntrSrc);
#if defined (DEBUG_ECC_MAGNA)
		if (sdl_ecc_test) {
			/* error occurred due to fault test */
			sdl_ecc_test = 0;
			esmError = true;
		}
		else
#endif
		{
			if (esmInst == SDL_ESM_INST_MAIN_ESM0) {
				switch (intSrc) {
				case SDLR_ESM0_ESM_PLS_EVENT0_R5FSS0_CORE0_ECC_CORRECTED_PULSE_0:
				case SDLR_ESM0_ESM_PLS_EVENT0_R5FSS0_CORE1_ECC_CORRECTED_PULSE_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR0_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR6_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR5_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR4_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR9_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR10_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_MAIN_IP_ECC_AGGR0_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_NAVSS0_MODSS_ECC_AGGR_0_ECC_CORRECTED_ERR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_1:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_3:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_5:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_48:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_63:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_10:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_8:
				case SDLR_ESM0_ESM_LVL_EVENT_CSI_RX_IF0_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_CSI_RX_IF1_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_CSI_TX_IF_V2_1_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_CSI_TX_IF_V2_1_CDNS_RAM_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_CSI_TX_IF_V2_0_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_CSI_TX_IF_V2_0_CDNS_RAM_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_MSRAM_512K0_ECC_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_MSRAM_512K1_ECC_CORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_NAVSS0_UDMASS_ECC_AGGR_0_ECC_CORRECTED_ERR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_NAVSS0_VIRTSS_ECC_AGGR_0_ECC_CORRECTED_ERR_LEVEL_0:
					/*SEC events are ignored*/
					break;

				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_2:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_47:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_4:
					if((SDL_ECC_MEMTYPE_MAIN_MSMC_AGGR0 == eccErrorInfo.eccMemType) &&
							((eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW0_CACHE_TAG_PIPE_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW0_RMW_TAG_UPDATE_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW1_CACHE_TAG_PIPE_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW1_RMW_TAG_UPDATE_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW2_CACHE_TAG_PIPE_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW2_RMW_TAG_UPDATE_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW3_CACHE_TAG_PIPE_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW3_RMW_TAG_UPDATE_BUSECC_RAM_ID)))
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_Err_SRAMTagData_SRAMData,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);

						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_Err_SRAMTagData_SRAMData);
					}
					else if((SDL_ECC_MEMTYPE_MAIN_MSMC_AGGR0 == eccErrorInfo.eccMemType) &&
							((eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_EN_MSMC_P0_BUSECC_SNOOP_CMD_ID_QUEUE_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_EN_MSMC_P0_BUSECC_SNP_DATA_BUF_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_EN_MSMC_P0_BUSECC_SNP_RESP_BUF_RAM_ID)))
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_MSMC_Lvl3_Cache_Snoop_On_Chip_SRAM_ParityErr,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_MSMC_Lvl3_Cache_Snoop_On_Chip_SRAM_ParityErr);
					}
					else if((SDL_ECC_MEMTYPE_MAIN_MSMC_AGGR0 == eccErrorInfo.eccMemType) &&
							((eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW0_SRAM_SF_PIPE_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_SRAM0_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW1_SRAM_SF_PIPE_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_SRAM1_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW2_SRAM_SF_PIPE_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_SRAM2_BUSECC_RAM_ID ) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_RMW3_SRAM_SF_PIPE_BUSECC_RAM_ID ) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_SRAM3_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_CLEC_SRAM_RAMECC_RAM_ID)))
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_MSMC_CtrlSig_MSMCIntrcnnct_Chache_Err,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_MSMC_CtrlSig_MSMCIntrcnnct_Chache_Err);
					}
					else if((SDL_ECC_MEMTYPE_MAIN_MSMC_AGGR0 == eccErrorInfo.eccMemType) &&
							((eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_DATARAM_BANK0_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_DATARAM_BANK1_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_DATARAM_BANK2_BUSECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_COMPUTE_CLUSTER0_COMPUTE_CLUSTER_J7AE_MSMC_EN_DRU_MSMC_EN_4MB_WRAP_MSMC_4MB_MSMC_WRAP_ECC_AGGR0_DATARAM_BANK3_BUSECC_RAM_ID)))
					{

						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_Err_in_MSMCIntrcnnct,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_Err_in_MSMCIntrcnnct);
					}
					else
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_MSMC_ECC_Err,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);

						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_MSMC_ECC_Err);
					}
					Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);
					break;

				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_62:
					(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_GIC_ECC_Failure,
							ldef_ErrorMgr_ErrorActive,
							&SDL_EccAddtionalData_au8);
					Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);
					/* Report error to CAN msg */
					f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_GIC_ECC_Failure);

					break;

				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR0_UNCORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR6_UNCORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR5_UNCORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR4_UNCORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR9_UNCORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_ECC_AGGR10_UNCORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_MAIN_IP_ECC_AGGR0_UNCORR_LEVEL_0:
					(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_CBASS_Parity_failure_of_override_registers,
							ldef_ErrorMgr_ErrorActive,
							&SDL_EccAddtionalData_au8);
					Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);

					/* Report error to CAN msg */
					f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_CBASS_Parity_failure_of_override_registers);

					/* Achieve SafeState2 by resetting SOC */
					Pmic_F_SafeState2_v(SAFESTATE_REASON_SDL_ECC_Main_CBASS_Parity);
					break;

				case SDLR_ESM0_ESM_PLS_EVENT0_R5FSS0_CORE0_ECC_UNCORRECTED_PULSE_0:
				case SDLR_ESM0_ESM_PLS_EVENT0_R5FSS0_CORE1_ECC_UNCORRECTED_PULSE_0:
					if(((SDL_R5FSS0_0_ECC_AGGR == eccErrorInfo.eccMemType) &&
							(eccErrorInfo.memSubType == SDL_R5FSS0_PULSAR_SL_CPU0_ECC_AGGR_CPU0_KS_VIM_RAMECC_RAM_ID)) ||
							((SDL_R5FSS0_1_ECC_AGGR == eccErrorInfo.eccMemType) &&
									(eccErrorInfo.memSubType == SDL_R5FSS0_PULSAR_SL_CPU1_ECC_AGGR_CPU1_KS_VIM_RAMECC_RAM_ID)))
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_VIM_ECC_Err,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);

						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_VIM_ECC_Err);
					}
					else
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_R5F_ECC_failure_R5F_memory,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);

						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_R5F_ECC_failure_R5F_memory);
					}
					Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);
					break;

					/*for A72 :Disabled*/
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_7:
				case SDLR_ESM0_ESM_LVL_EVENT_COMPUTE_CLUSTER0_CLEC_ESM_EVENTS_OUT_LEVEL_9:
					/*(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_A72_Ucorrectable_ECC_Error,
							ldef_ErrorMgr_ErrorActive,
							&SDL_EccAddtionalData_au8);
					Fusa_Application_ErrorLogForDID(e_errLog_ECC, TRUE);*/
					/* Report error to CAN msg */
					/*f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_A72_Ucorrectable_ECC_Error);*/
					break;

					/*Main MSRAM*/
				case SDLR_ESM0_ESM_LVL_EVENT_MSRAM_512K0_ECC_UNCORR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_MSRAM_512K1_ECC_UNCORR_LEVEL_0:
					(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_MSRAM_Uncorrectable_ECC_error,
							ldef_ErrorMgr_ErrorActive,
							&SDL_EccAddtionalData_au8);
					Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);

					/* Report error to CAN msg */
					f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_MSRAM_Uncorrectable_ECC_error);
					break;

#if (SDL_APP_NAVSS_MAILBOX_ENABLED == SDL_APP_ON)
					/*NAVSS Mail box amd Parity*/
				case SDLR_ESM0_ESM_LVL_EVENT_NAVSS0_MODSS_ECC_AGGR_0_ECC_UNCORRECTED_ERR_LEVEL_0:
				case SDLR_ESM0_ESM_LVL_EVENT_NAVSS0_UDMASS_ECC_AGGR_0_ECC_UNCORRECTED_ERR_LEVEL_0:

					if((SDL_NAVSS0_1_ECC_AGGR == eccErrorInfo.eccMemType) &&
							((eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MAILBOX1_RAM_ECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MAILBOX0_RAM_ECC_RAM_ID)))
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_Memory_ECC_Err,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);

						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_Memory_ECC_Err);
					}
					else if((SDL_NAVSS0_1_ECC_AGGR == eccErrorInfo.eccMemType) &&
							((eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MAILBOX1_EDC_CTRL_0_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MAILBOX1_EDC_CTRL_1_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MAILBOX1_EDC_CTRL_2_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MAILBOX0_EDC_CTRL_0_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MAILBOX0_EDC_CTRL_1_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MAILBOX0_EDC_CTRL_2_RAM_ID)))
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_1Bit_ParityCheck_Err,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);
						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_1Bit_ParityCheck_Err);
					}
					else if((SDL_NAVSS0_1_ECC_AGGR == eccErrorInfo.eccMemType) &&
							((eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_PROXY0_BUF_STRAM_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_PROXY0_BUF_BUFRAM_ECC_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_PROXY0_BUF_DST_BR_SRC_EDC_CTRL_0_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_PROXY0_EDC_CTRL_0_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_PROXY0_CFG_FW_CH_VBUSP_TABLE_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_PROXY0_SRC_FW_CH_VBUSM_TABLE_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_PROXY0_CFG_FW_CH_VBUSP_BR_EDC_CTRL_0_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_PROXY0_CFG_FW_CH_VBUSP_EDC_CTRL_0_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_SEC_PROXY0_SRC_FW_CH_VBUSM_EDC_CTRL_0_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_CBASS_CH_PROXY0_CFG_MMRS_P2P_BRIDGE_EDC_CTRL_0_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_CBASS_CH_PROXY0_SRC_MMRS_P2P_BRIDGE_EDC_CTRL_0_RAM_ID)))
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_ECC_error,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);
						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_ECC_error);
					}
					else if(((SDL_NAVSS0_3_ECC_AGGR == eccErrorInfo.eccMemType) &&
							((eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_UDMASS_UDMASS_ECCAGGR0_NAVSS512J7AM_UDMASS_UDMASS_INTA0_EDC_CTRL_0_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_UDMASS_UDMASS_ECCAGGR0_NAVSS512J7AM_UDMASS_UDMASS_INTA0_STATREG_SR_SPRAM_256X128_SWW_SR_RAM_ID) ||
									(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_UDMASS_UDMASS_ECCAGGR0_NAVSS512J7AM_UDMASS_UDMASS_INTA0_COMMON_IM_TPRAM_3656X34_SWW_SR_RAM_ID))) ||
							((SDL_NAVSS0_1_ECC_AGGR == eccErrorInfo.eccMemType) &&
									((eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MODSS_INTA1_EDC_CTRL_0_RAM_ID) ||
											(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MODSS_INTA1_STATREG_SR_SPRAM_64X128_SWW_SR_RAM_ID) ||
											(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_MODSS_INTA1_COMMON_IM_TPRAM_512X34_SWW_SR_RAM_ID) ||
											(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_MODSS_INTA1_CFG_FW_CH_VBUSP_TABLE_RAM_ID) ||
											(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_MODSS_INTA1_CFG_FW_CH_VBUSP_BR_EDC_CTRL_0_RAM_ID) ||
											(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_MODSS_INTA1_CFG_FW_CH_VBUSP_EDC_CTRL_0_RAM_ID) ||
											(eccErrorInfo.memSubType == SDL_NAVSS0_NAVSS512J7AM_MODSS_ECCAGGR0_NAVSS512J7AM_MODSS_CBASS_CBASS_CH_MODSS_INTA1_CFG_MMRS_P2P_BRIDGE_EDC_CTRL_0_RAM_ID))))
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_NAVSS_IA_MemSpace_ECC_Err,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);

						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_NAVSS_IA_MemSpace_ECC_Err);
					}
					else if(SDL_NAVSS0_3_ECC_AGGR == eccErrorInfo.eccMemType)
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_Main_UDMA_Uncorrectable_ECC_error,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);
						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_Main_UDMA_Uncorrectable_ECC_error);

					}
					else{
						/* Do nothing*/
					}
					break;
#endif

				default:
					/* Do nothing */
					break;
				}
			} else if (esmInst == SDL_ESM_INST_MCU_ESM0) {
				switch (intSrc) {
				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_MSRAM_1MB0_ECC_CORR_LEVEL_0:
				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_R5FSS0_CORE0_ECC_CORRECTED_LEVEL_0:
				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_ADC12FCC0_ECC_CORRECTED_ERR_LEVEL_0:
				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_ADC12FCC1_ECC_CORRECTED_ERR_LEVEL_0:
				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCUM_MCU_ECC_AGGR0_CORR_LEVEL_0:
				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_NAVSS0_UDMASS_ECC_AGGR0_ECC_CORRECTED_ERR_LEVEL_0:
					/*SEC events are ignored*/
					break;
				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_MSRAM_1MB0_ECC_UNCORR_LEVEL_0:

					(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_MSRAM_Uncorrectable_ECC_error,
							ldef_ErrorMgr_ErrorActive,
							&SDL_EccAddtionalData_au8);
					Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);

					/* Report error to CAN msg */
					f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_MSRAM_Uncorrectable_ECC_error);
					break;

				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_R5FSS0_CORE0_ECC_UNCORRECTED_LEVEL_0:
					/*DED event*/
					if(eccErrorInfo.memSubType == SDL_MCU_R5FSS0_PULSAR_SL_CPU0_ECC_AGGR_CPU0_KS_VIM_RAMECC_RAM_ID)
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_VIM_ECC_Err,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);
						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_VIM_ECC_Err);
					}
					else
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_R5F_ECC_failure_R5F_memory,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);

						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_R5F_ECC_failure_R5F_memory);
					}
					break;

				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_ADC12FCC0_ECC_UNCORRECTED_ERR_LEVEL_0:
				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_ADC12FCC1_ECC_UNCORRECTED_ERR_LEVEL_0:
					(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_ADC_uncorrectable_ECC,
							ldef_ErrorMgr_ErrorActive,
							&SDL_EccAddtionalData_au8);
					Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);
					/* Report error to CAN msg */
					f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_ADC_uncorrectable_ECC);
					break;

				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCUM_MCU_ECC_AGGR0_UNCORR_LEVEL_0:
					if((eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_IVDC_DATA_SAFEG_VBUSM_64B_REF_RD_RAMECC_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_IVDC_DATA_SAFEG_VBUSM_64B_REF_EDC_CTRL_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_I7_MCU_VBUSM_FSS0_SAFETY_GASKET_EDC_CTRL_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_I7_MCU_VBUSM_FSS0_SAFETY_GASKET_RD_RAMECC_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_I7_MCU_VBUSM_FSS0_SAFETY_GASKET_WR_RAMECC_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_I7_MCU_VBUSM_FSS1_SAFETY_GASKET_EDC_CTRL_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_I7_MCU_VBUSM_FSS1_SAFETY_GASKET_RD_RAMECC_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_I7_MCU_VBUSM_FSS1_SAFETY_GASKET_WR_RAMECC_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_IJ7VCL_IEXPORT_VBUSM_64B_MST_MCU_0_MST_MTOG_EDC_CTRL_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_J7AM_MCU_CBASS_MCU_0_J7AM_MCU_CBASS_EXPORT_J7AM_WKUP_TO_MCU_VBUSM_L0_M2M_BRIDGE_J7AM_MCU_CBASS_EXPORT_J7AM_WKUP_TO_MCU_VBUSM_L0_M2M_BRIDGE_SRC_EDC_CTRL_BUSECC_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_J7AM_MCU_CBASS_MCU_0_J7AM_MCU_CBASS_IJ7_MCU_VBUSM_SAFETY_GASKET_MCU2MAIN_0_CFG_P2P_BRIDGE_IJ7_MCU_VBUSM_SAFETY_GASKET_MCU2MAIN_0_CFG_BRIDGE_BUSECC_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_J7AM_MCU_CBASS_MCU_0_J7AM_MCU_CBASS_IJ7_MCU_VBUSM_SAFETY_GASKET_MCU_FSS_0_CFG_P2P_BRIDGE_IJ7_MCU_VBUSM_SAFETY_GASKET_MCU_FSS_0_CFG_BRIDGE_BUSECC_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCUM_MCU_ECC_AGGR0_J7AM_MCU_ECC_AGGR_J7AM_MCU_CBASS_MCU_0_J7AM_MCU_CBASS_IJ7_MCU_VBUSM_SAFETY_GASKET_MCU_FSS_1_CFG_P2P_BRIDGE_IJ7_MCU_VBUSM_SAFETY_GASKET_MCU_FSS_1_CFG_BRIDGE_BUSECC_RAM_ID))
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_VBUSM_Uncorrectable_ECC_Error,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);
						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_VBUSM_Uncorrectable_ECC_Error);

					}
					else
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_CBASS_Parity_failure_of_override_registers,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);

						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_CBASS_Parity_failure_of_override_registers);
					}
					break;

				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_NAVSS0_UDMASS_ECC_AGGR0_ECC_UNCORRECTED_ERR_LEVEL_0:
					/* No Req. */
					break;

				case SDLR_MCU_ESM0_ESM_LVL_EVENT_MCU_NAVSS0_MODSS_ECC_AGGR0_ECC_UNCORRECTED_ERR_LEVEL_0:

					if((eccErrorInfo.memSubType == SDL_MCU_NAVSS0_NAVSS_MCU_J7_MODSS_ECCAGGR0_NAVSS_MCU_J7_MODSS_CBASS_UDMASS_INTA0_CFG_FW_CH_VBUSP_TABLE_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCU_NAVSS0_NAVSS_MCU_J7_MODSS_ECCAGGR0_NAVSS_MCU_J7_MODSS_CBASS_UDMASS_INTA0_CFG_FW_CH_VBUSP_BR_EDC_CTRL_0_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCU_NAVSS0_NAVSS_MCU_J7_MODSS_ECCAGGR0_NAVSS_MCU_J7_MODSS_CBASS_UDMASS_INTA0_CFG_FW_CH_VBUSP_EDC_CTRL_0_RAM_ID) ||
							(eccErrorInfo.memSubType == SDL_MCU_NAVSS0_NAVSS_MCU_J7_MODSS_ECCAGGR0_NAVSS_MCU_J7_MODSS_CBASS_CBASS_CH_UDMASS_INTA0_CFG_MMRS_P2P_BRIDGE_EDC_CTRL_0_RAM_ID))
					{
						(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_MCU_NAVSS_NAVSS_IA_Mem_ECC_Err,
								ldef_ErrorMgr_ErrorActive,
								&SDL_EccAddtionalData_au8);
						Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);

						/* Report error to CAN msg */
						f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_MCU_NAVSS_NAVSS_IA_Mem_ECC_Err);
					}
					break;

				default:
				    /* Do nothing */
					break;
				}
			}
			else if (esmInst == SDL_ESM_INST_WKUP_ESM0) {
				switch (intSrc) {
				case SDLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_VTM0_CORR_LEVEL_0:
				case SDLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_ECC_AGGR0_CORR_LEVEL_0:
					/* SEC events are ignored*/
					break;
				case SDLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_VTM0_UNCORR_LEVEL_0:
					/* TODO: find error manager error definition to report to error manager*/
					/*Pmic_F_SafeState2_v();*/
					break;

				case SDLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_ECC_AGGR0_UNCORR_LEVEL_0:
					/*WKUP CBASS*/
					Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);
					/* TODO: To Remove Pmic_F_SafeState2_v() once find error manager error definition to report to error-man*/
					/* Achieve SafeState2 by resetting SOC */
					/* Report error to CAN msg */
					f_Send_Dbg_SDLFault_CanTx((uint16)SDL_ERR_SAFESTATE_REASON_SDL_ECC_WKUP);
					Pmic_F_SafeState2_v(SAFESTATE_REASON_SDL_ECC_WKUP);
					break;

					/*For SMS: Not Done*/
				case SDLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_SMS0_ECC_AGGR_0_ECC_UNCORRECTED_LEVEL_0:
					(void)ErrorMgrSatellite_ReportErrorStatus(ldef_ErrorMgr_Error_SysIntFlt_DMSC_ECC_failure_SMS_SRAM,
							ldef_ErrorMgr_ErrorActive, &SDL_EccAddtionalData_au8);
					Fusa_Application_ErrorLogForDID((uint8_t)e_errLog_ECC, (uint8_t)TRUE);

					/* Report error to CAN msg */
					f_Send_Dbg_SDLFault_CanTx((uint16)ldef_ErrorMgr_Error_SysIntFlt_DMSC_ECC_failure_SMS_SRAM);
					break;

				default:
					/* Do Nothing */
					break;
				}
			}
			else
			{
				/* Do nothing */
			}
		}
	}

	return retVal;
}

/* SDL_ECC_applicationCallbackFunction is expected to be defined by the application. It is
 * required by the SDL ECC module. It is called by the SDL ECC module to notify the
 * application of certain ECC errors that are reported as Exception events.
 * Note, however, that it is not executed in this example */
void SDL_ECC_applicationCallbackFunction(SDL_ECC_MemType eccMemType,
                                         uint32_t errorSrc,
                                         uint32_t address,
                                         uint32_t ramId,
                                         uint64_t bitErrorOffset,
                                         uint32_t bitErrorGroup){
/* DD-ID: {23A57A44-FD35-46e0-BC86-3F72A67A1131}*/

#ifdef UART_PRINTS_ENABLED
    APP_log(APP_LOG_MAX,"\n  ECC Error Call back function called : eccMemType %d, errorSrc 0x%x, " \
                "address 0x%x, ramId %d, bitErrorOffset 0x%04x%04x, bitErrorGroup %d\n",
                eccMemType, errorSrc, address, ramId, (uint32_t)(bitErrorOffset >> 32),
                (uint32_t)(bitErrorOffset & 0x00000000FFFFFFFF), bitErrorGroup);
    APP_log(APP_LOG_MAX,"  Take action \n");
#endif

    (void)eccMemType;
    (void)errorSrc;
    (void)address;
    (void)ramId;
    (void)bitErrorOffset;
    (void)bitErrorGroup;
    /* Any additional customer specific actions can be added here */

}


/* Nothing past this point */

#define CDD_Safety_STOP_SEC_CODE
#include "CDD_Safety_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
