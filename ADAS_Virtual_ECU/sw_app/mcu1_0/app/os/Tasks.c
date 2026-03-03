/*
*
* Copyright (c) 2019 Texas Instruments Incorporated
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
 *  \file main_tirtos.c
 *
 *  \brief Main file for TI-RTOS build
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/soc.h>
#include <ti/csl/cslr.h>

#include <ti/osal/osal.h>
#include <ti/osal/TaskP.h>
#include <ti/osal/src/nonos/Nonos_config.h>

#include <ti/boot/sbl/soc/k3/sbl_soc_cfg.h> 

#include "boot_cfg.h"
#include "EcuM.h"
#include "Os.h"
#include "BswM.h"
#include "ComM.h"
#include "Os_IsrInt.h"
#include "CanIf.h"
#include "Dio.h"
#include "CanTrcv_30_Tja1043.h"
/*
 * #include "Rte_ADAS.h"
 */
#include "Rte_Type.h"
#include "Rte_CDD_Safety.h"
#include "Adc.h"
#include "Nm.h"
#include "Os_Types_Lcfg.h"
#include "MeOsProfiling.h"

#include "app_log.h"
#include "app_log_Boot.h"
#include <ti/board/src/j721s2_hyd/include/board_utils.h>
#include "app_log_Boot.h"
#include <ti/drv/sciclient/sciserver_autosaros.h>
#include <ti/drv/sciclient/sciclient.h>
#include <ti/drv/sciclient/sciserver.h>
#include <ti/csl/cslr.h>
#include <ti/csl/src/ip/vtm/V1/csl_vtm.h>
#include "pmic.h"
#include "pmic_utils.h"
#include <ti/board/src/j721s2_hyd/include/board_power.h>
#include <ti/board/board.h>
#include "AppDiag_Services.h"
#include "bist.h"
#include "OsHooks_RpStruct.h"

/*
 * #include "arti.h"
 */

#if (defined (BUILD_MCU1_0) && (defined (SOC_J721E) || defined (SOC_J7200)|| defined (SOC_J721S2)))
/*
 * #include <ti/drv/sciclient/sciserver_tirtos.h>
 */
#include <ti/csl/arch/r5/csl_vim.h>
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Test application stack size */

/**< Stack required for the stack */
/**< Task names */
/**< Task Priority Levels */


#define BOOTAPP_FUNCTION_ENABLE


#define USER_MCU_NAV_HIGH   0
#define USER_MAIN_NAV_HIGH  1
#define USER_MCU_NAV_LOW    2
#define USER_MAIN_NAV_LOW   3

#define NUM_TEMP_SENSORS   5U

#define CSL_PASS                        ( (int32_t) (0))
#define SCICLIENT_SERVICE_WAIT_TIMEOUT  (0x0BB8U) /* 3 sec wait timeout */

/* Module Specific Macros */
#define TASK_PRIO_ONE 1U
#define TASK_PRIO_FOUR 4u
#define HOOK_DEBUG_PATTERN_A5 0xA5A5A5A5u
#define HOOK_DEBUG_PATTERN_B5 0xB5B5B5B5u
#define GPIO_PIN_37 37u
#define OSAL_DELAY_2500MSEC   2500U

#define ISR_NUM_36 36u
#define ISR_NUM_37 37u
#define ISR_NUM_47 47u
#define ISR_NUM_48 48u
#define ISR_NUM_49 49u
#define ISR_NUM_53 53u
#define ISR_NUM_78 78u
#define ISR_NUM_79 79u
#define ISR_NUM_99 99u
#define ISR_NUM_98 98u
#define ISR_NUM_141 141u
#define ISR_NUM_140 140u
#define ISR_NUM_142 142u
#define ISR_NUM_100 100u
#define ISR_NUM_297 297u
#define ISR_NUM_298 298u
#define ISR_NUM_295 295u
#define ISR_NUM_296 296u
#define ISR_NUM_291 291u
#define ISR_NUM_299 299u
#define ISR_NUM_300 300u
#define ISR_NUM_317 317u
#define ISR_NUM_290 290u
#define ISR_NUM_312 312u
#define ISR_NUM_310 310u
#define ISR_NUM_314 314u
#define ISR_NUM_309 309u
#define ISR_NUM_307 307u
#define ISR_NUM_308 308u
#define ISR_NUM_306 306u
#define ISR_NUM_304 304u
#define ISR_NUM_305 305u
#define ISR_NUM_313 313u

typedef struct
{
    /* Device id of a core. */
    int32_t    tisci_dev_id;
    /* Proc id of a core. */
    int32_t    tisci_proc_id;
}M_ST_MAINDOMAINCORE_RESET_T;

#define NUM_OF_MainDomainCores 4u

/* Below Macro Pattern using for NVM Write */
#define NVM_WRITE_ALL_PATTERN_INIT    0xC5C5
#define NVM_WRITE_ALL_PATTERN_BEFORE  0xD5D5
#define NVM_WRITE_ALL_PATTERN_AFTER   0xE5E5
/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

app_log_shared_mem_t g_app_log_shared_mem
__attribute__ ((section(".bss:app_log_mem")))
__attribute__ ((aligned(4096)));

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
#if defined(BOOT_TASK_ENABLED)
void Boot_App_Temp(void);
#endif
sint32 SetupSciServer(void);
extern void CSL_armR5StartupIntrEnableVic( uint32_t enable );
extern void Osal_intrHandler(uint32_t intvecnum);
extern void f_Send_Dbg_Os_hook_CanTx(ME_OsHookDebugData_t s_ME_OsHookDebugData_RPRAM_as);

extern ME_OsHookDebugData_t s_ME_OsHookDebugData_RPRAM_as;
/*
 * void utilsCopyVecs2ATcm( void ) 3
 */
void ADCPowerClk(void);
void init_vtm_temp(void);
uint8_t GetIsOSInitialized(void);
void SW_ResetMainDomainCores(void);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
volatile uint8 debug_mcu1 = 0u;
volatile uint8 debug_mcuVar = 0u;
static boolean gSciInitDone = (boolean)FALSE;
static boolean gOSInitialized= (boolean)FALSE;
uintptr_t AdcSchM_IntKey;
volatile BOOL v_FdF2HookErrorStatus = FALSE;


/* ========================================================================== */
/*                            External Variables                              */
/* ========================================================================== */

/**< CAN IF Driver Status, defined in CanIf.c */

#ifdef Enable_Printf
static int32_t apploginit(void)
{
	/* DD-ID: {F50B1B20-09A5-4f74-9224-211AC87DDE94} */
	int32_t status = 0;
    char coreName[7] = {'M','C','U','1','_','0'};
    app_log_init_prm_t log_init_prm;

    /* Initialize the timer used to include in logging */
    (void)appLogGlobalTimeInit();
    appLogInitPrmSetDefault(&log_init_prm);
    log_init_prm.shared_mem = &g_app_log_shared_mem;
    log_init_prm.self_cpu_index = APP_IPC_CPU_MCU1_0;
  /*
   * strncpy((char *)log_init_prm.self_cpu_name, "MCU1_0" , APP_LOG_MAX_CPU_NAME);
   */
    for(uint8 i =0; i < 7 ; i++)
    {
        log_init_prm.self_cpu_name[i] = coreName[i];
    }
    status = appLogWrInit(&log_init_prm);

	return status;
}
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int main(void)
{
    sint32 ret;
    

    CSL_armR5StartupIntrEnableVic(0u); /* Disable VIC */

    #ifdef Enable_Printf
    UART_HwAttrs uart_cfg;
	apploginit();

    UART_socGetInitCfg(0u, &uart_cfg);
    /* Use UART fclk freq setup by ROM */
    uart_cfg.frequency = 96000000U;
    /* Disable the UART interrupt */
    uart_cfg.enableInterrupt = FALSE;
    UART_socSetInitCfg(0u, &uart_cfg);
    /* Init UART for logging. */
    UART_stdioInit(0u);
    #endif
    /*
     * while (debug_mcu1 == 0)
     */
    (void)Pmic_F_EarlyInit_s32();
#ifdef BOOTAPP_FUNCTION_ENABLE
    ret = SetupSciServer();
#endif
    if (ret == CSL_PASS)
    {
        gSciInitDone = (boolean)TRUE;
    }
    else
    {
        /* TBD - Error case, need to handle via reset of the ECU or enter Safe state */
        while ((uint8)0u == debug_mcu1)
        {
        	/* Do Nothing */
        }
    }
    /* Initialize and configure for PMIC External Watchdog */
    (void)Pmic_F_Init_s32();
    Os_InitMemory();
    MeOsProf_Init();
    Os_Init();
    gOSInitialized = (boolean)TRUE;
    /*Autosar Start */
    EcuM_Init();

    return(0);
}


sint32 SetupSciServer(void)
{

    Sciserver_osCfgPrms_t appPrms;
    Sciclient_ConfigPrms_t clientPrms;
    sint32 ret;

    appPrms.taskPriority[SCISERVER_TASK_USER_LO] = TASK_PRIO_ONE;
    appPrms.taskPriority[SCISERVER_TASK_USER_HI] = TASK_PRIO_FOUR;

    /* Sciclient needs to be initialized before Sciserver. Sciserver depends on
     * Sciclient API to execute message forwarding */
    ret = Sciclient_configPrmsInit(&clientPrms);
    if (ret == CSL_PASS)
    {
    	ret = Sciclient_init(&clientPrms);
    }
    else
    {
    	/* Do Nothing */
    }

    if (ret == CSL_PASS)
    {
        /*
         * ret = Sciserver_tirtosInit(&appPrms)
         */
        ret = Sciserver_osInit(&appPrms);
    }
    else
    {
    	/* Do Nothing */
    }

    return ret;
}

TASK(StartUpTask)
{

    (void)Os_InitialEnableInterruptSources(1u);
    BswM_PreInit(ECUM_BSWM_CONFIG_POINTER);
	/*Dio Initialization*/
    Dio_Init();
    ADCPowerClk();
    EcuM_StartupTwo();
    init_vtm_temp();

    /* Check for NVMWriteAll stuck -- Compare patterns */		
    if ((uint16)NVM_WRITE_ALL_PATTERN_BEFORE == s_ME_OsHookDebugData_RPRAM_as.NVM_WriteAll_Pattern ) {
#ifdef Enable_Printf
        appLogPrintf("\n  Patterns do not match after NVM write!  ");
#endif
		/* Handle error-  Error in NVM WriteAll */
		s_ME_OsHookDebugData_RPRAM_as.NVM_WriteAll_Fail_Status = TRUE;
        
    } else {
#ifdef Enable_Printf
        appLogPrintf("\n  Patterns match after NVM write.  ");
#endif
    	/* NVM WriteAll happens properly */
		s_ME_OsHookDebugData_RPRAM_as.NVM_WriteAll_Fail_Status = FALSE;
    }
	/* Initialize pattern */
    s_ME_OsHookDebugData_RPRAM_as.NVM_WriteAll_Pattern = NVM_WRITE_ALL_PATTERN_INIT;

    /* Check if ECU stucke at Hooks */
    if(((uint32)HOOK_DEBUG_PATTERN_A5 == s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_PresentPtr_MCU1_0) ||
       ((uint32)HOOK_DEBUG_PATTERN_B5 == s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_PresentPtr_MCU1_0) ||
	   ((uint8)TRUE == s_ME_OsHookDebugData_RPRAM_as.NVM_WriteAll_Fail_Status))
    {
	    f_Send_Dbg_Os_hook_CanTx(s_ME_OsHookDebugData_RPRAM_as);
        if((uint32)HOOK_DEBUG_PATTERN_A5 == s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_PresentPtr_MCU1_0)
        {
        	/* Notify FDF2 about ECU stuck at HOOKs */
        	v_FdF2HookErrorStatus = TRUE;
        	/* Clear Present Ptr */
            s_ME_OsHookDebugData_RPRAM_as.FD14_1_Hook_PresentPtr_MCU1_0 = HOOK_DEBUG_PATTERN_B5;
        }
        else
        {
        	v_FdF2HookErrorStatus = FALSE;
        }
    }
    else
    {
    	/* Do Nothing */
    }
    #ifdef Enable_Printf
     appLogPrintf("\n Welcome to StartUpTask of MCU1_0 AUTOSAR !! ");
    #endif

    /* Read PMIC last reset reason from NvM */
    Pmic_utils_NvMRead_PMICLastResetReason();

#ifdef BOOTAPP_FUNCTION_ENABLE
	(void)ActivateTask(SciServerHighOsTask);
    (void)ActivateTask(SciServerLowOsTask);
    (void)ActivateTask(BootAppOsTask);
#endif
   /*
    * while(debug_mcu1==0)
    */
    (void)TerminateTask();
}

TASK(BootAppOsTask)
{
#ifdef BOOTAPP_FUNCTION_ENABLE    
 #ifdef Enable_Printf  
  appLogPrintf("\n SOC Type : TI- TDA4 Mid-Eco ( SOC_J721S2)");
 #endif
  (void)Boot_App();
 #ifdef Enable_Printf  
  appLogPrintf("\n MCU1_0 and other images booted Success");
 #endif
#endif
  CDD_Safety_Init();    /* Pmic configuration step 1 (for fusa requirement) */
  Pmic_F_Config_step1_v();
  (void)TerminateTask();
}
TASK(SciServerLowOsTask)
{
    sint32 ret;
    EventMaskType ev;
    for (;;)
    {
        (void)WaitEvent(SciServerTrigger_UserMainLo | SciServerTrigger_UserMcuLo);         /* PRQA S 3417 */
        (void)GetEvent(SciServerLowOsTask, &ev);                                           /* PRQA S 3417 */
        (void)ClearEvent(ev & (SciServerTrigger_UserMainLo | SciServerTrigger_UserMcuLo)); /* PRQA S 3417 */

        if ((ev & SciServerTrigger_UserMcuLo) != (EventMaskType)0)
        {
            (void)GetResource(OsResource_SciServerSync);
            ret = Sciserver_osprocesstask((uint8_t)SCISERVER_TASK_USER_LO);
            (void)ReleaseResource(OsResource_SciServerSync);

            if (ret != CSL_PASS)
            {
                /* TBD - Error case, need to handle via reset of the ECU or enter Safe state */
            }
            else
            {
            	/* Do Nothing */
            }
            (void)Os_Api_EnableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn3, 0u);
        }
        else
        {
        	/* Do Nothing */
        }
        if ((ev & SciServerTrigger_UserMainLo) != (EventMaskType)0)
        {
            (void)GetResource(OsResource_SciServerSync);
            ret = Sciserver_osprocesstask((uint8_t)SCISERVER_TASK_USER_LO);
            (void)ReleaseResource(OsResource_SciServerSync);

            if (ret != CSL_PASS)
            {
                /* TBD - Error case, need to handle via reset of the ECU or enter Safe state */
            }
            else
            {
            	/* Do Nothing */
            }
            (void)Os_Api_EnableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn4, 0u);
        }
        else
        {
        	/* Do nothing */
        }
    }
    
}


TASK(SciServerHighOsTask)
{
    sint32 ret;
    EventMaskType ev;
    for (;;)
    {
        (void)WaitEvent(SciServerTrigger_UserMainHi | SciServerTrigger_UserMcuHi);         /* PRQA S 3417 */
        (void)GetEvent(SciServerHighOsTask, &ev);                                          /* PRQA S 3417 */
        (void)ClearEvent(ev & (SciServerTrigger_UserMainHi | SciServerTrigger_UserMcuHi)); /* PRQA S 3417 */

        if ((ev & SciServerTrigger_UserMcuHi) != (EventMaskType)0)
        {
            (void)GetResource(OsResource_SciServerSync);
            ret = Sciserver_osprocesstask((uint8_t)SCISERVER_TASK_USER_HI);
            (void)ReleaseResource(OsResource_SciServerSync);

            if (ret != CSL_PASS)
            {
                /* TBD - Error case, need to handle via reset of the ECU or enter Safe state */
            }
            else
            {
            	/* Do Nothing */
            }
            (void)Os_Api_EnableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn1, 0u);
        }
        else
        {
        	/* Do Nothing */
        }

        if ((ev & SciServerTrigger_UserMainHi) != (EventMaskType)0)
        {
            (void)GetResource(OsResource_SciServerSync);
            ret = Sciserver_osprocesstask((uint8_t)SCISERVER_TASK_USER_HI);
            (void)ReleaseResource(OsResource_SciServerSync);

            if (ret != CSL_PASS)
            {
                /* TBD - Error case, need to handle via reset of the ECU or enter Safe state */
            }
            else
            {
            	/* Do Nothing */
            }
            (void)Os_Api_EnableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn2, 0u);
        }
        else
        {
        	/* Do Nothing */
        }
    }

}

TASK(ShutdownTask)
{
	/* Disable Ext Watchdog */
#ifdef Enable_Printf
	appLogPrintf("\n  In ShutdownTask  ");  /* SSMTEST */
#endif
	(void)Pmic_AppEnterInLongWindow();

	(void)Osal_delay(OSAL_DELAY_2500MSEC); /* Added for shutdown synchronization with other cores - Optimization required */

	SW_ResetMainDomainCores();

	/* PBIST Test */
	bist_TaskFxn((bool)TRUE);
	
	/* pattern Before NVM write */
    s_ME_OsHookDebugData_RPRAM_as.NVM_WriteAll_Pattern = NVM_WRITE_ALL_PATTERN_BEFORE;

	/* NVM Write All */
    BswM_NvM_WriteAll();

	/* pattern after NVM write */
    s_ME_OsHookDebugData_RPRAM_as.NVM_WriteAll_Pattern = NVM_WRITE_ALL_PATTERN_AFTER;

    /* shutdown ECU */
    EEP_Shutdown();

    (void)TerminateTask();

}


void SW_ResetMainDomainCores(void)
{
	static const M_ST_MAINDOMAINCORE_RESET_T MAINDOMAINCORE_RESET[NUM_OF_MainDomainCores] =
	{
			{(int32_t)SBL_DEV_ID_MCU2_CPU1, (int32_t)SBL_PROC_ID_MCU2_CPU1,},
			{(int32_t)SBL_DEV_ID_MCU2_CPU0, (int32_t)SBL_PROC_ID_MCU2_CPU0,},
			{(int32_t)SBL_DEV_ID_DSP1_C7X, (int32_t)SBL_PROC_ID_DSP1_C7X,},
			{(int32_t)SBL_DEV_ID_MPU_CLUSTER0, (int32_t)SBL_PROC_ID_MPU1_CPU0,},
	};

	uint8_t index;

	for(index = 0u; index < (uint8_t)NUM_OF_MainDomainCores; index++)
	{
		if (CSL_PASS != Sciclient_procBootRequestProcessor((uint8_t )MAINDOMAINCORE_RESET[index].tisci_proc_id,
				SCICLIENT_SERVICE_WAIT_TIMEOUT))
		{

#ifdef Enable_Printf
APP_log(APP_LOG_ERR,"\n %d acquiring proc failed\n", MAINDOMAINCORE_RESET[index].tisci_proc_id);
#endif
		}
		else
		{
			if (CSL_PASS == Sciclient_pmSetModuleRst((int32_t )MAINDOMAINCORE_RESET[index].tisci_dev_id, 1u, SCICLIENT_SERVICE_WAIT_TIMEOUT))
			{
#ifdef Enable_Printf
				APP_log(APP_LOG_MAX,"\n %d reset\n", MAINDOMAINCORE_RESET[index].tisci_dev_id);
#endif

			}
			else
			{
#ifdef Enable_Printf
				APP_log(APP_LOG_ERR,"\n %d reset failed\n", MAINDOMAINCORE_RESET[index].tisci_dev_id);
#endif

			}
		}
	}
}


ISR(SciServer_OsIsr_UserMsgHwiFxn1)
{
     Sciserver_hwiData *const uhd = Getsciserver_hwi_list((uint8_t)USER_MCU_NAV_HIGH);
    int32_t ret;
    bool soft_error = (bool)false;

    (void)Os_Api_DisableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn1);
    ret = Sciserver_interruptHandler(uhd, (bool *)&soft_error);

    if ((ret != CSL_PASS) && (soft_error == (bool)TRUE))
    {
        (void)Os_Api_EnableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn1, 0u);
    }
    else
    {
        (void)SetEvent(SciServerHighOsTask, SciServerTrigger_UserMcuHi);
    }
    (void)Os_Api_ClearPendingInterrupt(SciServer_OsIsr_UserMsgHwiFxn1);

    if ((ret != CSL_PASS) && (soft_error != (bool)true))
    {
        /* At this point secure proxy is broken so halt */
        /* TBD - Error case, need to handle via reset of the ECU or enter Safe state */
    }
    else
    {
    	/* Do Nothing */
    }
}
ISR(SciServer_OsIsr_UserMsgHwiFxn2)
{
    Sciserver_hwiData *const uhd = Getsciserver_hwi_list((uint8_t)USER_MAIN_NAV_HIGH);
    int32_t ret;
    bool soft_error = (bool)false;

    (void)Os_Api_DisableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn2);
    ret = Sciserver_interruptHandler(uhd, (bool*)&soft_error);

    if ((ret != CSL_PASS) && (soft_error == (bool)true))
    {
        (void)Os_Api_EnableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn2, 0u);
    }
    else
    {
        (void)SetEvent(SciServerHighOsTask, SciServerTrigger_UserMainHi);
    }
    (void)Os_Api_ClearPendingInterrupt(SciServer_OsIsr_UserMsgHwiFxn2);

    if ((ret != CSL_PASS) && (soft_error != (bool)true))
    {
        /* At this point secure proxy is broken so halt */
        /* TBD - Error case, need to handle via reset of the ECU or enter Safe state */
    }
    else
    {
    	/* Do Nothing */
    }
}

ISR(SciServer_OsIsr_UserMsgHwiFxn3)
{
    Sciserver_hwiData *const uhd = Getsciserver_hwi_list((uint8_t)USER_MCU_NAV_LOW);
    int32_t ret;
    bool soft_error = (bool)false;

    (void)Os_Api_DisableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn3);
    ret = Sciserver_interruptHandler(uhd, (bool*)&soft_error);
    if ((ret != CSL_PASS) && (soft_error == (bool)true))
    {
        (void)Os_Api_EnableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn3, 0u);
    }
    else
    {
        (void)SetEvent(SciServerLowOsTask, SciServerTrigger_UserMcuLo);
    }
    (void)Os_Api_ClearPendingInterrupt(SciServer_OsIsr_UserMsgHwiFxn3);

    if ((ret != CSL_PASS) && (soft_error != (bool)true))
    {
        /* At this point secure proxy is broken so halt */
        /* TBD - Error case, need to handle via reset of the ECU or enter Safe state */
    }
    else
    {
    	/* Do Nothing */
    }
}

ISR(SciServer_OsIsr_UserMsgHwiFxn4)
{
    Sciserver_hwiData *const uhd = Getsciserver_hwi_list((uint8_t)USER_MAIN_NAV_LOW);
    int32_t ret;
    bool soft_error = (bool)false;

    (void)Os_Api_DisableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn4);
    ret = Sciserver_interruptHandler(uhd,(bool*)&soft_error);
    if ((ret != CSL_PASS) && (soft_error == (bool)true))
    {
        (void)Os_Api_EnableInterruptSource(SciServer_OsIsr_UserMsgHwiFxn4, 0u);
    }
    else
    {
        (void)SetEvent(SciServerLowOsTask, SciServerTrigger_UserMainLo);
    }
    (void)Os_Api_ClearPendingInterrupt(SciServer_OsIsr_UserMsgHwiFxn4);

    if ((ret != CSL_PASS) && (soft_error != (bool)true))
    {
        /* At this point secure proxy is broken so halt */
        /* TBD - Error case, need to handle via reset of the ECU or enter Safe state */
    }
    else
    {
    	/* Do Nothing */
    }
}

ISR(MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_78)
{
    Osal_intrHandler(ISR_NUM_78);
}

ISR(MCU_NAVSS0_UDMASS_INTA_0_INTAGGR_VINTR_PEND_79)
{
    Osal_intrHandler(ISR_NUM_79);
}
ISR(MCU_ESM0_ESM_INT_HI_LVL_0) {
    Osal_intrHandler(ISR_NUM_49);
}

ISR(MCU_ESM0_ESM_INT_LOW_LVL_0) {
    Osal_intrHandler(ISR_NUM_48);
}

ISR(MCU_ESM0_ESM_INT_CFG_LVL_0)
{
    Osal_intrHandler(ISR_NUM_53);
}

ISR(MAIN_ESM0_ESM_INT_HI_LVL_0) {
    Osal_intrHandler(ISR_NUM_141);
}

ISR(MAIN_ESM0_ESM_INT_LOW_LVL_0) {
    Osal_intrHandler(ISR_NUM_140);
}

ISR(MAIN_ESM0_ESM_INT_CFG_LVL_0)
{
    Osal_intrHandler(ISR_NUM_142);
}

ISR(WKUP_ESM0_ESM_INT_HI_LVL_0) {
    Osal_intrHandler(ISR_NUM_99);
}

ISR(WKUP_ESM0_ESM_INT_LOW_LVL_0) {
    Osal_intrHandler(ISR_NUM_98);
}

ISR(WKUP_ESM0_ESM_INT_CFG_LVL_0)
{
    Osal_intrHandler(ISR_NUM_100);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR0_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_297)
{
    Osal_intrHandler(ISR_NUM_297);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_MAIN_PULSAR1_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_298)
{
    Osal_intrHandler(ISR_NUM_298);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_4_DFT_LBIST_DFT_LBIST_BIST_DONE_0_295)
{
    Osal_intrHandler(ISR_NUM_295);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_AC71_5_DFT_LBIST_DFT_LBIST_BIST_DONE_0_296)
{
    Osal_intrHandler(ISR_NUM_296);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_ARM0_DFT_LBIST_DFT_LBIST_BIST_DONE_0_291)
{
    Osal_intrHandler(ISR_NUM_291);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_DMPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_299)
{
    Osal_intrHandler(ISR_NUM_299);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_GLUELOGIC_VPAC_LBIST_GLUE_DFT_LBIST_BIST_DONE_0_300)
{
    Osal_intrHandler(ISR_NUM_300);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_AEP_GPU_BXS464_WRAP0_DFT_EMBED_PBIST_0_DFT_PBIST_CPU_0_317)
{
    Osal_intrHandler(ISR_NUM_317);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_COMPUTE_CLUSTER0_PBIST_WRAP_0_DFT_PBIST_CPU_0_290)
{
    Osal_intrHandler(ISR_NUM_290);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST0_DFT_PBIST_CPU_0_47)
{
    Osal_intrHandler(ISR_NUM_47);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST1_DFT_PBIST_CPU_0_36)
{
    Osal_intrHandler(ISR_NUM_36);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_MCU_PBIST2_DFT_PBIST_CPU_0_37)
{
    Osal_intrHandler(ISR_NUM_37);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_PBIST0_DFT_PBIST_CPU_0_312)
{
    Osal_intrHandler(ISR_NUM_312);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_PBIST10_DFT_PBIST_CPU_0_310)
{
    Osal_intrHandler(ISR_NUM_310);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_PBIST11_DFT_PBIST_CPU_0_314)
{
    Osal_intrHandler(ISR_NUM_314);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_PBIST2_DFT_PBIST_CPU_0_309)
{
    Osal_intrHandler(ISR_NUM_309);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_PBIST3_DFT_PBIST_CPU_0_307)
{
    Osal_intrHandler(ISR_NUM_307);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_PBIST4_DFT_PBIST_CPU_0_308)
{
    Osal_intrHandler(ISR_NUM_308);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_PBIST5_DFT_PBIST_CPU_0_306)
{
    Osal_intrHandler(ISR_NUM_306);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_PBIST7_DFT_PBIST_CPU_0_304)
{
    Osal_intrHandler(ISR_NUM_304);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_PBIST8_DFT_PBIST_CPU_0_305)
{
    Osal_intrHandler(ISR_NUM_305);
}

ISR(SDLR_MCU_R5FSS0_CORE0_INTR_PBIST1_DFT_PBIST_CPU_0_313)
{
    Osal_intrHandler(ISR_NUM_313);
}

uint8_t GetIsOSInitialized(void)
{
    return gOSInitialized;
}

uint8 GetIsSciInitDone(void) /* Required for OSAL autosarOs compile */
{
    return gSciInitDone;
}

FUNC(void, RTE_CODE) SchM_Enter_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_6(void)
{

}
FUNC(void, RTE_CODE) SchM_Exit_Can_30_Mcan_CAN_30_MCAN_EXCLUSIVE_AREA_6(void)
{
    
}

FUNC(void, RTE_CODE) SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0(void)
{

}
FUNC(void, RTE_CODE) SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0(void)
{

}
FUNC(void, RTE_CODE) SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_1(void)
{

}
FUNC(void, RTE_CODE) SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_1(void)
{

}
FUNC(void, RTE_CODE) SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_4(void)/*PRQA S 0777*/
{

}
FUNC(void, RTE_CODE) SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_4(void)/*PRQA S 0777*/
{

}

FUNC(void, RTE_CODE) SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1(void)
{

}
FUNC(void, RTE_CODE) SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1(void)
{
    
}
FUNC(void, RTE_CODE) SchM_Enter_Eep_30_XXi2c01_EEP_30_XXI2C01_EXCLUSIVE_AREA_0(void)
{

}
FUNC(void, RTE_CODE) SchM_Exit_Eep_30_XXi2c01_EEP_30_XXI2C01_EXCLUSIVE_AREA_0(void)
{

}

FUNC(void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_0(void)

{

    AdcSchM_IntKey = CSL_armR5GetCpsrRegVal();

    /* Disable IRQ and FIQ */

    CSL_armR5DisableIrqFiq();

}

FUNC(void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_0(void)

{

    (void)CSL_armR5EnableIrqFiq(AdcSchM_IntKey);

}
void ADCPowerClk(void)
{
    uint32 regVal;
    /* Unlock lock key registers for Partition 0: IO PAD configuration registers in MCU_CTRL_MMR */
    /* write Partition 0 Lock Key 0 Register */
    CSL_REG32_WR(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0, 0x68EF3490U);
    /* write Partition 1 Lock Key 1 Register */
    CSL_REG32_WR(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1, 0xD172BC5AU);
    /* Check for unlock */
    regVal = CSL_REG32_RD(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0);
    while ((regVal & (uint32)0x1U) != 0x1U)
    {
        /* Check for unlock */
        regVal = CSL_REG32_RD(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0);
    }
    /* Select clock frequency 25 MHZ */
    CSL_REG32_FINS(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_MCU_ADC1_CLKSEL,
                   MCU_CTRL_MMR_CFG0_MCU_ADC1_CLKSEL_PROXY_MCU_ADC1_CLKSEL_CLK_SEL_PROXY,
                   0U);
}

void init_vtm_temp(void)
{
    int32_t ts_id;
    CSL_vtm_cfg2Regs *const p_vtm_cfg2_regs = (CSL_vtm_cfg2Regs *) CSL_WKUP_VTM0_MMR_VBUSP_CFG2_BASE;
    CSL_vtm_ts_ctrl_cfg ts_ctrl_cfg;

    for (ts_id = 0; ts_id <(int32_t) NUM_TEMP_SENSORS; ts_id++)/*PRQA S 1822*/
    {

        ts_ctrl_cfg.valid_map = CSL_VTM_TS_CTRL_MAXT_OUTG_ALERT_VALID | CSL_VTM_TS_CTRL_RESET_CTRL_VALID | CSL_VTM_TS_CTRL_SOC_VALID | CSL_VTM_TS_CTRL_MODE_VALID;

        (void) CSL_vtmTsGetCtrl(p_vtm_cfg2_regs, ts_id, &ts_ctrl_cfg);

        ts_ctrl_cfg.valid_map  = CSL_VTM_TS_CTRL_RESET_CTRL_VALID | CSL_VTM_TS_CTRL_SOC_VALID | CSL_VTM_TS_CTRL_MODE_VALID;
        ts_ctrl_cfg.adc_stat   = CSL_VTM_TS_CTRL_SINGLESHOT_ADC_CONV_IN_PROGRESS;
        ts_ctrl_cfg.mode       = CSL_VTM_TS_CTRL_CONTINUOUS_MODE;
        ts_ctrl_cfg.tsReset    = CSL_VTM_TS_CTRL_SENSOR_NORM_OP;
        (void) CSL_vtmTsSetCtrl (p_vtm_cfg2_regs, ts_id, &ts_ctrl_cfg, FALSE);
    }

}
void SetEventOSPI(void)
{
    (void)SetEvent(BootAppOsTask, ospi_dma_event);
}

void WaitEventOSPI(void)
{
    EventMaskType ev;
	(void)WaitEvent(ospi_dma_event);         /* PRQA S 3417 */
	(void)GetEvent(BootAppOsTask, &ev);                                           /* PRQA S 3417 */
	(void)ClearEvent(ev & (ospi_dma_event)); /* PRQA S 3417 */
}
