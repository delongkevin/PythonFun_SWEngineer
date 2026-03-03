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

/**
 *  \file main_tirtos.c
 *
 *  \brief Main file for TI-RTOS build
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include "PlatformDataTypes.h"

#include <osal.h>

#include <board.h>
#include <UART.h>
#include <UART_stdio.h>

#include <sciclient.h>
#include "SafeRTOS_API.h"
#include "Tasks.h"
#include "board_utils.h"
#include "uart_utils.h"
#include "main_domain_utils.h"
#include "mcu_timer_read_multicore.h"
#include "BaseSwTasks.h"
#include "ApplicationTasks.h"
#include "SafetyTasks.h"
#include "vim_mainR5.h"
#include "timer_fusa_utils.h"
#include "WdgM.h"

/* #include "US_SysMgr_Global.h" */

/* #include <app_log.h> */
#ifdef PERF_STATS_OUT
/* #include <app_perf_stats.h> */
#endif
#if 0 
#include "vim.h"
#include "safety_utils.h"
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* #define TIMERS_FUSA_ENABLE */ /* Disable 5ms and 1ms timer monitoring */

#ifdef SAFERTOS 
#define HARDWARE_TIMERCONFIG
#define TIMERID ( 5 )
#endif

#ifdef BUILD_C7X_1
#define  TASK_STACKSIZE  0x4000U
#else
#define  TASK_STACKSIZE  0x2000U
#endif

#define TIMER15   		0x03u
#define TIMER_PERIOD_US 5000u
#define ENABLE_UART
#define UART_CONSOLE
#define STABILIZE_TIME (10U*1000U*1000U)
/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */
/* app_log_shared_mem_t g_app_log_shared_mem */
/*__attribute__ ((section(".bss:app_log_mem")))*/
/*__attribute__ ((aligned(4096))) */
/* ; */

#ifdef PERF_STATS_OUT
static uint32_t timer_print_cnt;
#endif
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
#ifdef PERF_STATS_OUT
__extern void appIdleLoop(void);
#endif

static void initSciclient(void);
static void boardInit(void);
static void tick_timer_func(uintptr_t arg);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

static void initSciclient(void)
{
    /* DD-ID:{BB2098F8-B30C-4079-A319-34F991C5B9DC}*/
    Sciclient_ConfigPrms_t        config;

    /* Now reinitialize it as default parameter */
    Sciclient_configPrmsInit(&config);

    Sciclient_init(&config);

    return;
}

static void boardInit(void) /* QAC Message: 303 An empty parameter list in a function type has a different meaning in C++. */
{
  /* DD-ID: {A73F0D6A-3C66-4c2b-A2FA-A99B4817CC17}*/
#ifdef ENABLE_UART

	/* const Board_initCfg boardCfg = BOARD_INIT_UART_STDIO;  */
    Board_STATUS  status;

	/* status = Board_init(boardCfg); */
	status = Board_init((Board_initCfg)BOARD_INIT_UART_STDIO);

#if defined (UART_CONSOLE)
	if (status != BOARD_SOK)
	{
		UART_printf("\n[MCU2_1] Board_init() is not successful...unexpected results may happen \n");
	}
    else
    {
        UART_printf("\n[MCU2_1] Board_init() is successful...");   
    }
#endif
#endif
    return;
}

static volatile uint32_t Debug_tick_timer_func_count=0;

static void tick_timer_func(uintptr_t arg)
{
  /* DD-ID: {C1C641AD-AC42-41a4-A1ED-59611A7C10AC}*/
    Debug_tick_timer_func_count++;
#ifdef TIMERS_FUSA_ENABLE
   static uint64_t timestampPrev=0;
   uint64_t timestampCurrent=0,timeVal=0;
   timestampCurrent = TimerP_getTimeInUsecs();
   if(timestampCurrent> (uint64_t)STABILIZE_TIME)//10second after bootup to stabilize timer and bootup time.
   {
		timeVal=timestampCurrent-timestampPrev;
		(void)updateTaskThresholdCounterVal_5msec(timeVal,UPPER_THRESHOLD_TASK_5MSEC,LOWER_THRESHOLD_TASK_5MSEC);
   }
   timestampPrev=timestampCurrent;
#endif

#ifdef PERF_STATS_OUT
    timer_print_cnt++;
#endif
    basesw_tick_5ms();
    appsw_tick_5ms();
    safetysw_tick_5ms();
}

void vApplicationTickHook( void )
{
  /* DD-ID: {6D7932BC-D659-412c-A5B9-51E21C0FB2F5}*/
#ifdef TIMERS_FUSA_ENABLE
   static uint64_t timestampPrev=0;
   uint64_t timestampCurrent=0,timeVal=0;
   timestampCurrent = TimerP_getTimeInUsecs();
   if(timestampCurrent> (uint64_t)STABILIZE_TIME)//10second after bootup to stabilize timer and bootup time.
   {
		timeVal=timestampCurrent-timestampPrev;
		(void)updateTaskThresholdCounterVal_1msec(timeVal,UPPER_THRESHOLD_TASK_1MSEC,LOWER_THRESHOLD_TASK_1MSEC);
   }
   timestampPrev=timestampCurrent;
#endif
	
}
#ifdef ENABLE_UART
static void appLogDeviceWrite(char *string, uint32_t max_size)
{
  /* DD-ID: {7B0A59BF-B407-414a-96AA-318CFEF7B638}*/
    UART_puts(string, max_size);
}
#endif

/* static int32_t apploginit(void)
   {
    int32_t status = 0;
    app_log_init_prm_t log_init_prm; */

    /* Initialize the timer used to include in logging */
/*  appLogGlobalTimeInit();
    appLogInitPrmSetDefault(&log_init_prm);
    log_init_prm.shared_mem = &g_app_log_shared_mem;
    log_init_prm.self_cpu_index = APP_IPC_CPU_MCU3_0;
    strncpy(log_init_prm.self_cpu_name, "MCU3_0" , APP_LOG_MAX_CPU_NAME);

    #ifdef ENABLE_UART
    log_init_prm.log_rd_max_cpus = APP_IPC_CPU_MAX;
    log_init_prm.device_write = appLogDeviceWrite;
    log_init_prm.log_rd_cpu_enable[APP_IPC_CPU_MCU2_0] = 1;
    log_init_prm.log_rd_cpu_enable[APP_IPC_CPU_MCU2_1] = 1;
    log_init_prm.log_rd_cpu_enable[APP_IPC_CPU_MCU3_0] = 1;
    #endif	

    #ifdef ENABLE_UART
    status = appLogRdInit(&log_init_prm);
    #endif

    if (status == 0)
    {
        status = appLogWrInit(&log_init_prm);
    }

    return status;
}*/

#ifdef PERF_STATS_OUT
void appIdleLoop(void)
{
  /* DD-ID: {FB0665BC-B22E-4120-8126-A87287788031}*/

    if (timer_print_cnt > 2500u)
	{
        timer_print_cnt = 0;
        /* appPerfStatsPrintAll(); */
    }
}
#endif
 
#define  USS_DEBUG
#undef   USS_DEBUG
 
#ifdef USS_DEBUG
void US_DSI3Drv_test(void);  
volatile int mcu2_1_dbg = 0;
#endif

#define BOARD_INIT_MSG "\n[MCU2_1] Board Init Done!"

int main(void)
{
  /* DD-ID: {3671BCAE-AC16-42bb-99B7-637D732850A4}*/
	
#ifdef HARDWARE_TIMERCONFIG
    TimerP_Params   timerParams;
    TimerP_Handle   timerhandle;
#else
    ClockP_Params   clockParams;
    ClockP_Handle   clockHandle;
#endif	
    bool_t bRet;

    OS_init();

    /* Init WdgM checkpoint feature (After scheduler init and before scheduler start) */
    WdgM_F_InitCheckpointFeature_v();
    /* Utils_setCpuFrequency();*/
    /*Init Sci client*/
    initSciclient();
    /*Board Init*/
    boardInit();
	
    #ifdef FREERTOS
        UART_printf("\n[MCU2_1] CPU running on FREERTOS!\n");
    #endif

    #ifdef SAFERTOS
        UART_printf("\n[MCU2_1] CPU running on SAFERTOS!\n");
    #endif
 
 #ifdef USS_DEBUG
	/* uncomment the following line to debug using lauterbach */
	while(mcu2_1_dbg == 0);
	
    if(mcu2_1_dbg == 2)
	{
      US_DSI3Drv_test();
	}
#endif
    /* UssMgr_SetSysState(SYSMGR_SYS_INIT);*/
    /* apploginit(); */

#ifdef PERF_STATS_OUT
    /* appPerfStatsInit(); */
#endif
    init_sem_basesw();
    init_sem_appsw();
    init_sem_safetysw();
    Safety_VIM_setDedVectorAddr((uint32_t)&VIM_VIMDEDInterruptHandler);

#ifdef HARDWARE_TIMERCONFIG
    TimerP_Params_init(&timerParams);
    timerParams.period = TIMER_PERIOD_US;
    timerParams.periodType = TimerP_PeriodType_MICROSECS;
    timerParams.runMode = TimerP_RunMode_CONTINUOUS;
    timerParams.arg = (void *)NULL;
    /* Create Timer for Pin Control */
    timerhandle = TimerP_create((int32_t)TIMERID,
                                      (TimerP_Fxn)&tick_timer_func,
                                      &timerParams);

    if(NULL_PTR != timerhandle)
    {
#else
    ClockP_Params_init(&clockParams);
    clockParams.startMode = ClockP_StartMode_AUTO;
    clockParams.period    = 5; // 5 msec 
    clockParams.runMode   = ClockP_RunMode_CONTINUOUS;
    clockParams.arg       = (void*)NULL;
	
	// Define a union to hold a function pointer and a void pointer
	union FunctionPointerUnion {
    void (*func)(uintptr_t arg); // Function pointer member with the correct function signature
    void *ptr; // Void pointer member to hold the converted function pointer
	};
	
	// Create an instance of the union
	union FunctionPointerUnion funcPtrUnion;
	
	// Assign the tick_timer_func to the function pointer member of the union
	funcPtrUnion.func = tick_timer_func;
	
	// Pass the void pointer member of the union to ClockP_create
    clockHandle = ClockP_create(funcPtrUnion.ptr, &clockParams); /* QAC 0307: Cast between a pointer to object and a pointer to function*/

    if(NULL_PTR != clockHandle)
    {
#endif
        bRet = CreateStartupTask();
        if(bRet == FALSE)
        {
            UART_printf("\n[MCU2_1] Tasks Launch failed..stop OS\n");
            /* This delay is required for the UART message to flush out message  on UART before OS shutdown*/
            for(int i=0; i<0xFFFF;i++); 
			OS_stop();
        }
        else
        {
            UART_printf("\n[MCU2_1] Tasks Launch success..starting OS\n");
            /* This delay is required for the UART message to flush out message on UART at startup*/
            for(int i=0; i<0xFFFF;i++);
            OS_start();
        }
    }
    else
    {
        UART_printf("\n[MCU2_1] Timer Task create failed..stop OS\n");
        /* This delay is required for the UART message to flush out message on UART before OS shutdown*/
        for(int i=0; i<0xFFFF;i++);
		OS_stop();
    }
    return(0);
}




#if 0 /* TODO : If any of the following are needed as features get added, uncomment the necessary code */
/*-----------------------------------------------------------*/
/*        Init UPA system                                    */    
/*-----------------------------------------------------------*/

static volatile uint8_t APA_RunCount=0;
static Void ME_Task_APA(UArg arg0, UArg arg1)
{
  /* DD-ID: {504A4A58-6384-4237-8FE1-5AE92A1E38F4}*/
    /*wait for 5 sec: Remove afterwards*/
    Task_sleep(10000);
#if DEBUG_PRINT
    UART_printf("\n[MCU3_0] APA Task");
    APA_Init();
#endif

#if OFFLINE_TESTING
	while(APA_RunCount < FRAME_COUNT)
     { 
		APA_RunCount++;
#else
    while(TRUE)
    {
#endif
        /* APA_Run(); ZB: 1/12/2022 This function seems to be blocking ipc communication from working.*/
        Task_sleep(10);/*100 */
    }
}

/*-----------------------------------------------------------*/
/*        High Speed Fusion                                  */    
/*-----------------------------------------------------------*/

static volatile uint8_t FUSION_RunCount=0;
static volatile uint8_t FUSION_status=1;
static Void ME_Task_FUSION(UArg arg0, UArg arg1)
{
  /* DD-ID: {BD4D4866-27DD-4119-920F-AD44C3AD9082}*/
    /*wait for 5 sec: Remove afterwards*/
    Task_sleep(10000);
    /*UART_printf("\n[MCU3_0] FUSION Task");*/
    FUSION_Init();
    /*UART_printf("\n[MCU3_0] FUSION Init Completed");*/
	
	while(FUSION_status)
    { 
       if(FUSION_RunCount == 1)
       {
           /*UART_printf("\n[MCU3_0] FUSION TaskRun end");*/
		   FUSION_status = 0;
       }
	   /*UART_printf("\n[MCU3_0] FUSION_Run begin ");*/
       FUSION_Run();
	   FUSION_RunCount++;
	   /*UART_printf("\n[MCU3_0] FUSION Run Completed ");*/
       Task_sleep(10);
    }
}

/*-----------------------------------------------------------*/
/*        				CD                                   */    
/*-----------------------------------------------------------*/

static volatile uint8_t CD_RunCount=0;
static volatile uint8_t CD_status=1;
static void ME_Task_CD(UArg arg0, UArg arg1)
{
  /* DD-ID: {FE34BC3F-F97F-49bb-9CCD-93857437A534}*/
    /*wait for 5 sec: TODO Remove afterwards*/
    Task_sleep(10000);
    CD_Init();
    UART_printf("\n[MCU3_0] CD Init done");
	while(CD_status)
    { 
        CD_Run();
		CD_RunCount++;
        UART_printf("\n[MCU3_0] CD Run done");
		if(CD_RunCount == 1)
        {
            UART_printf("\n [MCU3_0] CD TaskRun done ##########");
			CD_status = 0;
			break;
        }
        Task_sleep(10);
    }
}
#endif



