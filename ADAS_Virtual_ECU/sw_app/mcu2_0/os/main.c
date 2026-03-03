/*
 *
 * Copyright (c) 2018 Texas Instruments Incorporated
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

#include <app.h>
#include <app_mem_map.h>
#include <utils/console_io/include/app_log.h>
#include <utils/ethfw/include/app_ethfw.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <app_ipc_rsctable.h>
#include "app_cfg_mcu2_0.h"
#include "BaseSwTasks.h"
#include "ApplicationTasks.h"
#include <ti/osal/osal.h>
#include "vim_mainR5.h"
#include "SafeRTOS_API.h"
#include "timer_fusa_utils.h"

/* #define TIMERS_FUSA_ENABLE */ /* Disable 5ms and 1ms timer monitoring */
#define STABILIZE_TIME (10U*1000U*1000U)
#ifdef SAFERTOS 
#define TIMERID ( 4 )
/*FreeRTOS uses software timer & SAFERTOS uses Hardware timer*/
#define HARDWARE_TIMERCONFIG 
#endif

#ifdef HARDWARE_TIMERCONFIG
#include <ti/osal/TimerP.h>
#else
#include <ti/osal/ClockP.h>
#endif
static void tick_timer_func(uintptr_t arg)
{
  /* DD-ID: {C3ADEB1F-CEDB-4c5b-A76E-50636EBFD038}*/
#ifdef TIMERS_FUSA_ENABLE
   static uint64_t timestampPrev=0;
   uint64_t timestampCurrent=0,timeVal=0;
   timestampCurrent = appLogGetTimeInUsec();
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
}
void StartupEmulatorWaitFxn (void)
{
  /* DD-ID: {5F38F04D-9376-4dfd-9C28-C2EF241B2B79}*/
    volatile uint32_t enableDebug = 1;
    do
    {
    }while (enableDebug == 0);
}

void vApplicationTickHook( void )
{
  /* DD-ID: {7D418A7F-5753-4d19-B7C8-6B2130C0A9F3}*/
#ifdef TIMERS_FUSA_ENABLE
   static uint64_t timestampPrev=0;
   uint64_t timestampCurrent=0,timeVal=0;
   timestampCurrent = appLogGetTimeInUsec();
   if(timestampCurrent> (uint64_t)STABILIZE_TIME)//10second after bootup to stabilize timer and bootup time.
   {
		timeVal=timestampCurrent-timestampPrev;
		(void)updateTaskThresholdCounterVal_1msec(timeVal,UPPER_THRESHOLD_TASK_1MSEC,LOWER_THRESHOLD_TASK_1MSEC);
   }
   timestampPrev=timestampCurrent;
#endif
	
}

int main(void)
{
  /* DD-ID: {6A54E920-C764-4017-AF52-44922E215C63}*/
#ifdef HARDWARE_TIMERCONFIG
    TimerP_Params   timerParams;
    TimerP_Handle   timerhandle;
#else
    ClockP_Params   clockParams;
    ClockP_Handle   clockHandle;
#endif
    OS_init();
    
    /* This is moved before the wait function as NDK comes up with BIOS 
        and looks for semaphore handle created by appEthFwEarlyInit() */
#ifdef ENABLE_ETHFW
    appEthFwEarlyInit();
#endif
    init_sem_basesw();
    init_sem_appsw();

    Safety_VIM_setDedVectorAddr((uint32_t)&VIM_VIMDEDInterruptHandler);

#ifdef HARDWARE_TIMERCONFIG
    TimerP_Params_init(&timerParams);
    timerParams.period = 5000;
    timerParams.periodType = TimerP_PeriodType_MICROSECS;
    timerParams.arg = (void *)NULL;
    /* Create Timer for Pin Control */
    timerhandle = TimerP_create((int32_t)TIMERID,
                                      (TimerP_Fxn)&tick_timer_func,
                                      &timerParams);

    TimerP_start(timerhandle);
#else
    ClockP_Params_init(&clockParams);
    clockParams.startMode = ClockP_StartMode_AUTO;
    clockParams.period    = 5; // 5 msec 
    clockParams.runMode   = ClockP_RunMode_CONTINUOUS;
    clockParams.arg       = (void*)NULL;
    clockHandle = ClockP_create((void *)tick_timer_func, &clockParams);
#endif
    /* This is for debug purpose - see the description of function header */
    StartupEmulatorWaitFxn(); 

    Tasks_Launch_BaseTasks(); 

    OS_start();

    return 0;
}

uint32_t appGetDdrSharedHeapSize()
{
  /* DD-ID: {10B9D480-129D-4da6-9D73-ED189798BB3F}*/
    return DDR_SHARED_MEM_SIZE;

}

/*RAT configuration to MAP MSRAM memory:
MSRAM has 64bit address so need to use RAT to map the 32 bit adress
*/
#define CSL_R5FSS0_RAT_CFG_BASE      (0x0FF90000U)
void extended_system_pre_init(void)
{
	/* DD-ID: {0F5CBF96-7249-4ca2-AB75-25F77EF98742}*/
    //while(debug_mcu20_rat == 0);
    *(unsigned int *)(CSL_R5FSS0_RAT_CFG_BASE + 0x64) = 0xD0000000U;
    *(unsigned int *)(CSL_R5FSS0_RAT_CFG_BASE + 0x68) = 0x02000000U;
    *(unsigned int *)(CSL_R5FSS0_RAT_CFG_BASE + 0x6C) = 0x0000004FU;
    *(unsigned int *)(CSL_R5FSS0_RAT_CFG_BASE + 0x60) = 0x80000013U;
}
