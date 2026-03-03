
#include <osal.h>
#include <UART_stdio.h>
#include "main_domain_utils.h"
#include "mcu_timer_read_multicore.h"

/* Base Magna Software Includes */
#include "SignalMgr.h"
#include "SSM_Slave.h"
#include "ipc_manager.h"
#include "SignalDef.h"
#include "Safety_CDD.h"
#include "vim_mainR5.h"

#include "BaseSwTasks.h"
#include "ApplicationTasks.h"
#if 0
#include "WdgM.h"
#include "Wdg.h"
#endif
#include "SafetyTasks.h"
#if 0
#include "TimeManagerProxy.h"
#endif
/* SafeRTOS includes */
#include "SafeRTOS_API.h"
#include "SafeRTOSConfig.h"
#ifdef PERF_STATS_OUT
#include <app_perf_stats.h>
#endif
#include <assert.h>

#ifdef ENABLE_OBJECT_FUSION
#include "RAEB_ObjectFusion.h"
#endif

#if defined ERRORMGR_TEST_MCU2_1
#include "ErrorManagerSatelliteDef.h"
#endif
#include "ErrorManagerSatellite.h"
#ifdef FREERTOS
//cpu load utilisation
#include "cpu_load.h"
#endif

#include "WdgM.h"
#include "Wdg.h"

#ifdef ADDRUNTIMESTATS

// AddRuntimeStats
#include "AddRuntimeStats.h"
#include "RunTimeStats.h"
#endif

/** Uss csm include */
#ifndef USS_FEATURE_DISABLED
#include "Us_Csm_If.h"
#endif

extern void Wdg_Trigger(void);

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

void US_DrvTask(void);
void US_ControllerTask(void);
void US_USIntDeferProcessTask(uint32 Events);
void US_MgrAndODTask(void);
void US_SnrCfg_Cfg_Task(void);

#ifdef DEBUG_IPC
void IPC_f_SenderFxn_v(void);
#endif
#if 0
void US_SystemInit(void);
#endif
void US_InputOutputBuff_Task(void);

void Task_BSW_B_10msec(void *pvParameters);
void Task_BSW_QM_10msec(void *pvParameters);
void Task_BSW_QM1_10msec(void *pvParameters);
void Task_BSW_QM_BSW_QM_HighPriority_Ev(void *pvParameters);
void TaskFunc_BSW_QM_Idle(void *pvParameters);
#if 0
void TaskFunc_BSW_QM_UssCfg(void *pvParameters);
#endif
void TaskFunc_BSW_QM_1msec(void *pvParameters);
void StartupTask(void *pvParameters);
#ifdef AUTO_PARK_EN
void Task_Auto_Park_10msec(void *pvParameters);
#endif
#ifdef ENABLE_OBJECT_FUSION
void Task_objectfusion_10msec(void *pvParameters);
#endif
#ifdef ENABLE_TASK_USS
void Task_USS_CfgSemaphore(void *pvParameters);
#endif

#if defined ERRORMGR_TEST_MCU2_1
static uint8_t TestFault(ldef_ErrorMgr_enErrorNo errorNumber_e);
static void TestErrorManager(void);
#endif

static void Tasks_BSW_AddDebugStartDelay(void);


#ifdef DEBUG_BSW_TASKS
    static uint32_t Debug_BSW_Tasks_RunCount[en_Task_BSW_MAX]={0};
    static uint32_t Debug_tickirq_ct[en_Task_BSW_MAX]={0};
    static uint32_t Debug_BSW_Tasks_ErrCount[en_Task_BSW_MAX]={0};
#endif


static bool baseswtask_init = FALSE;
EventP_Handle TaskEventHandle_BSW_QM_Events_Ev;
EventP_Params TaskEvent_BSW_QM_EventsevtPrms;

configKERNEL_DATA_DEF static xTCB xBSW_QM_HighPriority_EvTaskTCB = { 0 };
static portInt8Type TaskStack_BSW_QM_HighPriority_Ev[TASK_STACKSIZE_BSW_QM_HighPriority_Ev]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_STACKSIZE_BSW_QM_HighPriority_Ev)))
#endif
;

configKERNEL_DATA_DEF static xTCB xBSW_QM_1msTaskTCB = { 0 };
static portInt8Type TaskStack_BSW_QM_1msec[TASK_STACKSIZE_BSW_QM_1msec]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_STACKSIZE_BSW_QM_1msec)))
#endif
;

configKERNEL_DATA_DEF static xTCB xStartupTaskTCB  = { 0 };
static portInt8Type TaskStack_Startup[TASK_STACKSIZE_Startup]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_STACKSIZE_Startup)))
#endif
;

configKERNEL_DATA_DEF static xTCB xBSW_QM_IdleTaskTCB = { 0 };
static portInt8Type TaskStack_BSW_QM_Idle[TASK_STACKSIZE_BSW_QM_Idle]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_STACKSIZE_BSW_QM_Idle)))
#endif
;



configKERNEL_DATA_DEF static xTCB xBSW_QM_10msTaskTCB = { 0 };
static portInt8Type TaskStack_BSW_QM_10msec[TASK_STACKSIZE_BSW_QM_10msec]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_STACKSIZE_BSW_QM_10msec)))
#endif
;

configKERNEL_DATA_DEF static xTCB xBSW_QM1_10msTaskTCB = { 0 };
static portInt8Type TaskStack_BSW_QM1_10msec[TASK_STACKSIZE_BSW_QM1_10msec] 
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_STACKSIZE_BSW_QM1_10msec))) 
#endif
;

configKERNEL_DATA_DEF static xTCB xBSW_B_10msTaskTCB = { 0 };
static portInt8Type TaskStack_BSW_B_10msec[TASK_STACKSIZE_BSW_B_10msec]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_STACKSIZE_BSW_B_10msec)))
#endif
;

static SemaphoreP_Handle sem_bsw_qm_10ms;
static SemaphoreP_Handle sem_bsw_qm1_10ms;
static SemaphoreP_Handle sem_bsw_b_10ms;
static SemaphoreP_Handle sem_bsw_qm_30ms;

#ifdef TASK_BSW_ADD_DEBUG_STARTUPDELAY
static volatile uint32_t Task_Debug_BSW_DelayCount=0;
#endif
void Tasks_BSW_AddDebugStartDelay(void)
{
  /* DD-ID: {72F695A7-1D2D-4b0a-98CF-0D84E917BA0A}*/
#ifdef TASK_BSW_ADD_DEBUG_STARTUPDELAY    
	while(Task_Debug_BSW_DelayCount++ < 0x7FFFFFFF);
#endif
}
void init_sem_basesw(void)
{
  /* DD-ID: {CC7D1739-D04F-47ab-B58C-84EF53F507EC}*/

    sem_bsw_b_10ms  = SemaphoreP_create(0, NULL);
    sem_bsw_qm_10ms = SemaphoreP_create(0, NULL);
    sem_bsw_qm1_10ms = SemaphoreP_create(0, NULL);
    sem_bsw_qm_30ms = SemaphoreP_create(0, NULL);
}

void basesw_tick_5ms(void)
{
  /* DD-ID: {F43163B0-67EB-41af-B4B8-BBFF6893352A}*/
    static uint8_t Count;
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if((Count % TICKCOUNT_10MS) == 0)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
	        /* post sem only if the tasks are created */
        if (baseswtask_init != FALSE)
        {
		
            SemaphoreP_post((sem_bsw_b_10ms));
            SemaphoreP_post((sem_bsw_qm_10ms));
            SemaphoreP_post((sem_bsw_qm1_10ms));
            /* VCAST Jenkins requirement - do not modify */
            /* VCAST Jenkins requirement - do not modify */
            if((Count % TICKCOUNT_30MS) ==0)
            /* VCAST Jenkins requirement - do not modify */
            /* VCAST Jenkins requirement - do not modify */
            {
                SemaphoreP_post(sem_bsw_qm_30ms);
            }
#ifdef DEBUG_BSW_TASKS

		    if (Debug_tickirq_ct[en_TasK_BSW_QM_10msec] != Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM_10msec])
		    {
		    	Debug_BSW_Tasks_ErrCount[en_TasK_BSW_QM_10msec]++;
		    	/* reset the error */
		    	Debug_tickirq_ct[en_TasK_BSW_QM_10msec] = Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM_10msec];
		    }
		    Debug_tickirq_ct[en_TasK_BSW_QM_10msec]++;
		    if (Debug_tickirq_ct[en_Task_BSW_B_10msec] != Debug_BSW_Tasks_RunCount[en_Task_BSW_B_10msec])
		    {
		    	Debug_BSW_Tasks_ErrCount[en_Task_BSW_B_10msec]++;
		    	/* reset the error */
		    	Debug_tickirq_ct[en_Task_BSW_B_10msec] = Debug_BSW_Tasks_RunCount[en_Task_BSW_B_10msec];
		    }
		    Debug_tickirq_ct[en_Task_BSW_B_10msec]++;
#endif
        }
    }
    Count++;
}

bool_t CreateStartupTask(void)
{
  /* DD-ID: {10112725-75A7-4ebf-B7E2-93A6B34C1FF2}*/
    bool bRet=TRUE;
    portBaseType xCreateResult;

    static const xTaskParameters xStartupTaskParams =
    {
        &StartupTask,                  /* The function that implements the task being created. */
        "StartupTask",     /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xStartupTaskTCB,                 /* TCB for the task. */
        TaskStack_Startup,               /* The buffer allocated for use as the task stack. */
        sizeof (TaskStack_Startup),  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        configMAX_PRIORITIES - 1,    /* Maximum priority for startuptask. */
        NULL,                           /* Thread Local Storage not used. */
        pdTRUE,                        /* task uses the FPU. */
        {                               /* MPU task parameters. */
            mpuPRIVILEGED_TASK,         /* task is privileged. */
            {
                { NULL, 0U, 0U, 0U },
                { NULL, 0U, 0U, 0U }
            }
        }
    };

    xCreateResult = xTaskCreate( &xStartupTaskParams, /* The structure containing the task parameters created at the start of this function. */
                                 NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */
    if (xCreateResult == pdFAIL)
    {
        bRet=FALSE;
    }
    return bRet;
}

void StartupTask(void *pvParameters)
{
    /* DD-ID: {B9BBEB57-8837-413e-8819-ABFE60F7B801}*/
    bool bRet=TRUE;
    uint32_t u32Ret;
    portBaseType xCreateResult;

    static const xTaskParameters xBSW_QM_IdleTaskParams =
    {
        &TaskFunc_BSW_QM_Idle,                  /* The function that implements the task being created. */
        "Task_BSW_QM_Idle",     /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xBSW_QM_IdleTaskTCB,                 /* TCB for the task. */
        TaskStack_BSW_QM_Idle,               /* The buffer allocated for use as the task stack. */
        sizeof (TaskStack_BSW_QM_Idle),  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_BSW_QM_Idle,    /* The priority to assigned to the task being created. */
        NULL,                           /* Thread Local Storage not used. */
        pdTRUE,                        /* task uses the FPU. */
        {                               /* MPU task parameters. */
            /* TO DO: Task is supposed to be running in mpuUNPRIVILEGED_TASK mode  */
            mpuPRIVILEGED_TASK,         /* task is unprivileged. */
            {                                                           
                {                                                       
                    MCU2_1_ASILB_DATA_BASE_ADDR,                  
                    MCU2_1_ASILB_DATA_LEN,                  
                    ( mpuREGION_PRIVILEGED_READ_WRITE_USER_READ_ONLY | 
                      mpuREGION_EXECUTE_NEVER |                         
                      mpuREGION_INTERNAL_RAM_DEFAULT_CACHE_POLICY ),    
                    mpuREGION_7TH_SUB_REGION_DISABLE | mpuREGION_8TH_SUB_REGION_DISABLE                   
                },                                                      
                { NULL, 0U, 0U, 0U }                                    
            }                                                           
        }
    };
#if 0
    static const xTaskParameters xBSW_QM_UssCfgTaskParams =
    {
        &TaskFunc_BSW_QM_UssCfg,                  /* The function that implements the task being created. */
        "Task_BSW_QM_UssCfg",     /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xBSW_QM_UssCfgTaskTCB,                 /* TCB for the task. */
        TaskStack_BSW_QM_UssCfg,               /* The buffer allocated for use as the task stack. */
        sizeof (TaskStack_BSW_QM_UssCfg),  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_BSW_QM_UssCfg,    /* The priority to assigned to the task being created. */
        NULL,                           /* Thread Local Storage not used. */
        pdTRUE,                        /* task uses the FPU. */
        {                               /* MPU task parameters. */
           /* TO DO: Task is supposed to be running in mpuUNPRIVILEGED_TASK mode  */
            mpuPRIVILEGED_TASK,         /* task is unprivileged. */
            {                                                           
                {                                                       
                    MCU2_1_ASILB_DATA_BASE_ADDR,                  
                    MCU2_1_ASILB_DATA_LEN,                  
                    ( mpuREGION_PRIVILEGED_READ_WRITE_USER_READ_ONLY | 
                      mpuREGION_EXECUTE_NEVER |                         
                      mpuREGION_INTERNAL_RAM_DEFAULT_CACHE_POLICY ),    
                    mpuREGION_7TH_SUB_REGION_DISABLE | mpuREGION_8TH_SUB_REGION_DISABLE                   
                },                                                      
                { NULL, 0U, 0U, 0U }                                    
            }                                                           
        }
    };
#endif
    static const xTaskParameters xBSW_QM_1msTaskParams =
    {
        &TaskFunc_BSW_QM_1msec,                  /* The function that implements the task being created. */
        "Task_BSW_QM_1msec",     /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xBSW_QM_1msTaskTCB,                 /* TCB for the task. */
        TaskStack_BSW_QM_1msec,               /* The buffer allocated for use as the task stack. */
        sizeof (TaskStack_BSW_QM_1msec),  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_BSW_QM_1msec,    /* The priority to assigned to the task being created. */
        NULL,                           /* Thread Local Storage not used. */
        pdTRUE,                        /* task uses the FPU. */
        {                               /* MPU task parameters. */
           /* TO DO: Task is supposed to be running in mpuUNPRIVILEGED_TASK mode  */
            mpuPRIVILEGED_TASK,         /* task is unprivileged. */
            {                                                           
                {                                                       
                    MCU2_1_ASILB_DATA_BASE_ADDR,                  
                    MCU2_1_ASILB_DATA_LEN,                  
                    ( mpuREGION_PRIVILEGED_READ_WRITE_USER_READ_ONLY | 
                      mpuREGION_EXECUTE_NEVER |                         
                      mpuREGION_INTERNAL_RAM_DEFAULT_CACHE_POLICY ),    
                    mpuREGION_7TH_SUB_REGION_DISABLE | mpuREGION_8TH_SUB_REGION_DISABLE                   
                },                                                      
                { NULL, 0U, 0U, 0U }                                    
            }                                                           
        }
    };
    static const xTaskParameters xBSW_QM_HighPriority_EvTaskParams =
    {
        &Task_BSW_QM_BSW_QM_HighPriority_Ev,                  /* The function that implements the task being created. */
        "Task_BSW_QM_HighPriority_Ev",     /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xBSW_QM_HighPriority_EvTaskTCB,                 /* TCB for the task. */
        TaskStack_BSW_QM_HighPriority_Ev,               /* The buffer allocated for use as the task stack. */
        sizeof (TaskStack_BSW_QM_HighPriority_Ev),  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_BSW_QM_HighPriority_Ev,    /* The priority to assigned to the task being created. */
        NULL,                           /* Thread Local Storage not used. */
        pdTRUE,                        /* task uses the FPU. */
        {                               /* MPU task parameters. */
           /* TO DO: Task is supposed to be running in mpuUNPRIVILEGED_TASK mode  */
            mpuPRIVILEGED_TASK,         /* task is unprivileged. */
            {                                                           
                {                                                       
                    MCU2_1_ASILB_DATA_BASE_ADDR,                  
                    MCU2_1_ASILB_DATA_LEN,                  
                    ( mpuREGION_PRIVILEGED_READ_WRITE_USER_READ_ONLY | 
                      mpuREGION_EXECUTE_NEVER |                         
                      mpuREGION_INTERNAL_RAM_DEFAULT_CACHE_POLICY ),    
                    mpuREGION_7TH_SUB_REGION_DISABLE | mpuREGION_8TH_SUB_REGION_DISABLE                   
                },                                                      
                { NULL, 0U, 0U, 0U }                                    
            }                                                           
        }
    };
    static const xTaskParameters xBSW_QM_10msTaskParams =
    {
        &Task_BSW_QM_10msec,                  /* The function that implements the task being created. */
        "Task_BSW_QM_10msec",     /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xBSW_QM_10msTaskTCB,                 /* TCB for the task. */
        TaskStack_BSW_QM_10msec,               /* The buffer allocated for use as the task stack. */
        sizeof (TaskStack_BSW_QM_10msec),  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_BSW_QM_10msec,    /* The priority to assigned to the task being created. */
        NULL,                           /* Thread Local Storage not used. */
        pdTRUE,                        /* task uses the FPU. */
        {                               /* MPU task parameters. */
           /* TO DO: Task is supposed to be running in mpuUNPRIVILEGED_TASK mode  */
            mpuPRIVILEGED_TASK,         /* task is unprivileged. */
            {                                                           
                {                                                       
                    MCU2_1_ASILB_DATA_BASE_ADDR,                  
                    MCU2_1_ASILB_DATA_LEN,                  
                    ( mpuREGION_PRIVILEGED_READ_WRITE_USER_READ_ONLY | 
                      mpuREGION_EXECUTE_NEVER |                         
                      mpuREGION_INTERNAL_RAM_DEFAULT_CACHE_POLICY ),    
                    mpuREGION_7TH_SUB_REGION_DISABLE | mpuREGION_8TH_SUB_REGION_DISABLE                   
                },                                                      
                { NULL, 0U, 0U, 0U }                                    
            }                                                           
        }
    };
    static const xTaskParameters xBSW_QM1_10msTaskParams =
    {
        &Task_BSW_QM1_10msec,                  /* The function that implements the task being created. */
        "Task_BSW_QM1_10msec",     /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xBSW_QM1_10msTaskTCB,                 /* TCB for the task. */
        TaskStack_BSW_QM1_10msec,               /* The buffer allocated for use as the task stack. */
        sizeof (TaskStack_BSW_QM1_10msec),  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_BSW_QM1_10msec,    /* The priority to assigned to the task being created. */
        NULL,                           /* Thread Local Storage not used. */
        pdTRUE,                        /* task uses the FPU. */
        {                               /* MPU task parameters. */
           /* TO DO: Task is supposed to be running in mpuUNPRIVILEGED_TASK mode  */
            mpuPRIVILEGED_TASK,         /* task is unprivileged. */
            {                                                           
                {                                                       
                    MCU2_1_ASILB_DATA_BASE_ADDR,                  
                    MCU2_1_ASILB_DATA_LEN,                  
                    ( mpuREGION_PRIVILEGED_READ_WRITE_USER_READ_ONLY | 
                      mpuREGION_EXECUTE_NEVER |                         
                      mpuREGION_INTERNAL_RAM_DEFAULT_CACHE_POLICY ),    
                    mpuREGION_7TH_SUB_REGION_DISABLE | mpuREGION_8TH_SUB_REGION_DISABLE                   
                },                                                      
                { NULL, 0U, 0U, 0U }                                    
            }                                                           
        }
    };
    static const xTaskParameters xBSW_B_10msTaskParams =
    {
        &Task_BSW_B_10msec,                  /* The function that implements the task being created. */
        "Task_BSW_B_10msec",     /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xBSW_B_10msTaskTCB,                 /* TCB for the task. */
        TaskStack_BSW_B_10msec,               /* The buffer allocated for use as the task stack. */
        sizeof (TaskStack_BSW_B_10msec),  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_BSW_B_10msec,    /* The priority to assigned to the task being created. */
        NULL,                           /* Thread Local Storage not used. */
        pdTRUE,                        /* task uses the FPU. */
        {                               /* MPU task parameters. */
           /* TO DO: Task is supposed to be running in mpuUNPRIVILEGED_TASK mode  */
            mpuPRIVILEGED_TASK,         /* task is unprivileged. */
            {                                                           
                {                                                       
                    MCU2_1_ASILB_DATA_BASE_ADDR,                  
                    MCU2_1_ASILB_DATA_LEN,                  
                    ( mpuREGION_PRIVILEGED_READ_WRITE_USER_READ_ONLY | 
                      mpuREGION_EXECUTE_NEVER |                         
                      mpuREGION_INTERNAL_RAM_DEFAULT_CACHE_POLICY ),    
                    mpuREGION_7TH_SUB_REGION_DISABLE | mpuREGION_8TH_SUB_REGION_DISABLE                   
                },                                                      
                { NULL, 0U, 0U, 0U }                                    
            }                                                           
        }
    };
    Tasks_BSW_AddDebugStartDelay();

    WdgM_F_Init_v();
    Wdg_Init();

    //Initialize safety tasks
    bRet = Tasks_Launch_BSWSafetyTasks();

    if (bRet != FALSE) 
    {
        //Initalize Base SW Items
        u32Ret=IPC_F_ManagerInit_u32();
        if(u32Ret != IPC_SOK)
        {
            bRet=FALSE;
        }
#if 0  //Pradeep      
        TimeManagerProxy_InitEndPoint(); 
#endif        
        //Initialize SSM
        SSM_Slave_Init();

        //Signal Manager
        SignalMgr_Init();

        //Error Manager
        ErrorMgrSatellite_Init_QM();
        ErrorMgrSatellite_Init_B();



        //Launch the tasks
        //Idle Task
        xCreateResult = xTaskCreate( &xBSW_QM_IdleTaskParams, /* The structure containing the task parameters created at the start of this function. */
                                         NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */

#ifdef PERF_STATS_OUT
        if (xCreateResult == pdPASS)
        {
            appPerfStatsRegisterTask(TaskHandle_BSW_QM_Idle, (char *)TaskParams_BSW_QM_Idle.instance->name);
        }
#endif
#if 0
        //USS Cfg Task
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if (xCreateResult == pdPASS)
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
    	    /*APP Task :*/
	        xCreateResult = xTaskCreate( &xBSW_QM_UssCfgTaskParams, /* The structure containing the task parameters created at the start of this function. */
                                     NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */
        }
#endif
#ifdef PERF_STATS_OUT
        if (xCreateResult == pdPASS)
        {
            appPerfStatsRegisterTask(TaskHandle_BSW_QM_UssCfg, (char *)TaskParams_BSW_QM_UssCfg.instance->name);
        }
#endif

        //BSW QM 1ms Task
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if (xCreateResult == pdPASS)
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
        	/*APP Asil B Task : Highest priority */
            xCreateResult = xTaskCreate( &xBSW_QM_1msTaskParams, /* The structure containing the task parameters created at the start of this function. */
            	                         NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */
        }
#ifdef PERF_STATS_OUT
        if (xCreateResult == pdPASS)
        {
            appPerfStatsRegisterTask(TaskHandle_BSW_QM_1msec, (char *)TaskParams_BSW_QM_1msec.instance->name);
        }
#endif

        //BSW QM Task HighPriority_Ev
        EventP_Params_init(&TaskEvent_BSW_QM_EventsevtPrms);
        TaskEventHandle_BSW_QM_Events_Ev = EventP_create(&TaskEvent_BSW_QM_EventsevtPrms);
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if (xCreateResult == pdPASS)
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
            /*APP Task */
            xCreateResult = xTaskCreate( &xBSW_QM_HighPriority_EvTaskParams, /* The structure containing the task parameters created at the start of this function. */
                                    NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */
        }
#ifdef PERF_STATS_OUT
        if (xCreateResult == pdPASS)
        {
           	appPerfStatsRegisterTask(TaskHandle_BSW_QM_HighPriority_Ev, (char *)TaskParams_BSW_QM_HighPriority_Ev.instance->name);
        }
#endif

        /* BSW_QM_10msTask*/
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if (xCreateResult == pdPASS)
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
        	/*APP Task */
        	xCreateResult = xTaskCreate( &xBSW_QM_10msTaskParams, /* The structure containing the task parameters created at the start of this function. */
                                     NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */
        }
#ifdef PERF_STATS_OUT
        if (xCreateResult == pdPASS)
        {
            appPerfStatsRegisterTask(TaskHandle_BSW_QM_10msec, (char *)TaskParams_BSW_QM_10msec.instance->name);
        }
#endif

        /* BSW_QM1_10msTask*/
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if (xCreateResult == pdPASS)
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
        	/*APP Task */
        	xCreateResult = xTaskCreate( &xBSW_QM1_10msTaskParams, /* The structure containing the task parameters created at the start of this function. */
                                     NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */
        }
#ifdef PERF_STATS_OUT
        if (xCreateResult == pdPASS)
        {
            appPerfStatsRegisterTask(TaskHandle_BSW_QM1_10msec, (char *)TaskParams_BSW_QM1_10msec.instance->name);
        }
#endif

        //BSW Asil B 10ms Task
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if (xCreateResult == pdPASS)
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
            /*APP Asil B Task :  */
            xCreateResult = xTaskCreate( &xBSW_B_10msTaskParams, /* The structure containing the task parameters created at the start of this function. */
                                 NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */
        }
#ifdef PERF_STATS_OUT
        if (xCreateResult == pdPASS)
        {
    	    appPerfStatsRegisterTask(TaskHandle_BSW_B_10msec, (char *)TaskParams_BSW_B_10msec.instance->name);
        }
#endif
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if ((xCreateResult != pdPASS) || (NULL == TaskEventHandle_BSW_QM_Events_Ev))
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
    	    bRet=FALSE;
        }
        else
        {
    	    /* All is fine*/
    
    	    // Initialize the Error manager application state for SSM.
    	    (void)SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_ErrorMgr,SSM_APPSTATE_INIT_i);
    	    /* End of BSP Initializations */
    	    //Set the SSM State to BSP init Done
    	    (void)SSM_Slave_RequestState(SSM_SlaveCore_State_BSP_Init_Done_i);

            baseswtask_init = TRUE; /* basesw tasks are created */
        }
	}
    #ifdef ADDRUNTIMESTATS
    TaskStackData[s_Task_BSW_B_Idle].Task_LowAdd = (uint32)xBSW_QM_IdleTaskParams.pcStackBuffer;
    TaskStackData[s_Task_BSW_B_Idle].Task_Size = xBSW_QM_IdleTaskParams.uxStackDepthBytes;
    if (TaskStackData[s_Task_BSW_B_Idle].Task_LowAdd <= (UINT32_MAX - TaskStackData[s_Task_BSW_B_Idle].Task_Size)) 
    {
        TaskStackData[s_Task_BSW_B_Idle].Task_HighAdd = TaskStackData[s_Task_BSW_B_Idle].Task_LowAdd + TaskStackData[s_Task_BSW_B_Idle].Task_Size;
    }
    else
    {
        TaskStackData[s_Task_BSW_B_Idle].Task_HighAdd = UINT32_MAX;
    }  

    TaskStackData[s_Task_BSW_B_1msec].Task_LowAdd = (uint32)xBSW_QM_1msTaskParams.pcStackBuffer;
    TaskStackData[s_Task_BSW_B_1msec].Task_Size = xBSW_QM_1msTaskParams.uxStackDepthBytes;
    if (TaskStackData[s_Task_BSW_B_1msec].Task_LowAdd <= (UINT32_MAX - TaskStackData[s_Task_BSW_B_1msec].Task_Size)) 
    {
        TaskStackData[s_Task_BSW_B_1msec].Task_HighAdd = TaskStackData[s_Task_BSW_B_1msec].Task_LowAdd + TaskStackData[s_Task_BSW_B_1msec].Task_Size;
    }
    else
    {
        TaskStackData[s_Task_BSW_B_1msec].Task_HighAdd = UINT32_MAX;
    }

    TaskStackData[s_Task_BSW_B_10msec].Task_LowAdd = (uint32)xBSW_B_10msTaskParams.pcStackBuffer;
    TaskStackData[s_Task_BSW_B_10msec].Task_Size = xBSW_B_10msTaskParams.uxStackDepthBytes;
    if (TaskStackData[s_Task_BSW_B_10msec].Task_LowAdd <= (UINT32_MAX - TaskStackData[s_Task_BSW_B_10msec].Task_Size)) 
    {
        TaskStackData[s_Task_BSW_B_10msec].Task_HighAdd = TaskStackData[s_Task_BSW_B_10msec].Task_LowAdd + TaskStackData[s_Task_BSW_B_10msec].Task_Size;
    }
    else
    {
        TaskStackData[s_Task_BSW_B_10msec].Task_HighAdd = UINT32_MAX;
    }
 
    TaskStackData[s_TasK_BSW_QM_10msec].Task_LowAdd =(uint32)xBSW_QM_10msTaskParams.pcStackBuffer;
    TaskStackData[s_TasK_BSW_QM_10msec].Task_Size = xBSW_QM_10msTaskParams.uxStackDepthBytes;
    if (TaskStackData[s_TasK_BSW_QM_10msec].Task_LowAdd <= (UINT32_MAX - TaskStackData[s_TasK_BSW_QM_10msec].Task_Size)) 
    {
        TaskStackData[s_TasK_BSW_QM_10msec].Task_HighAdd = TaskStackData[s_TasK_BSW_QM_10msec].Task_LowAdd + TaskStackData[s_TasK_BSW_QM_10msec].Task_Size;
    }
    else
    {
        TaskStackData[s_TasK_BSW_QM_10msec].Task_HighAdd = UINT32_MAX;
    }
    
    TaskStackData[s_TasK_BSW_QM1_10msec].Task_LowAdd =(uint32)xBSW_QM1_10msTaskParams.pcStackBuffer;
    TaskStackData[s_TasK_BSW_QM1_10msec].Task_Size = xBSW_QM1_10msTaskParams.uxStackDepthBytes;
    if (TaskStackData[s_TasK_BSW_QM1_10msec].Task_LowAdd <= (UINT32_MAX - TaskStackData[s_TasK_BSW_QM1_10msec].Task_Size)) 
    {
        TaskStackData[s_TasK_BSW_QM1_10msec].Task_HighAdd = TaskStackData[s_TasK_BSW_QM1_10msec].Task_LowAdd + TaskStackData[s_TasK_BSW_QM1_10msec].Task_Size;
    }
    else
    {
        TaskStackData[s_TasK_BSW_QM1_10msec].Task_HighAdd = UINT32_MAX;
    }

    TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_LowAdd = (uint32)xBSW_QM_HighPriority_EvTaskParams.pcStackBuffer;
    TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_Size = xBSW_QM_HighPriority_EvTaskParams.uxStackDepthBytes;
    if (TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_LowAdd <= (UINT32_MAX - TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_Size)) 
    {
        TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_HighAdd = TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_LowAdd + TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_Size;
    }
    else
    {
        TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_HighAdd = UINT32_MAX;
    }
    #endif
    /* The task deletes itself (indicated by the NULL parameter)
     * before reaching the end of the task function. */
    xTaskDelete( NULL );
}


void Task_BSW_QM_BSW_QM_HighPriority_Ev(void *pvParameters)
{
  /* DD-ID: {BD9EE24C-1BB0-4bd1-B9C8-EE427E5C64B1}*/
#ifndef USS_FEATURE_DISABLED
		uint32_t events;
#endif
	while(TRUE)
	{
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Start_Task(en_Task_en_TasK_BSW_QM_HighPriority_OnEvent);
        #endif
#ifdef DEBUG_BSW_TASKS
	    Debug_BSW_Tasks_RunCount[en_Task_en_TasK_BSW_QM_HighPriority_OnEvent]+=1;
#endif
#ifndef USS_FEATURE_DISABLED
		events = EventP_wait(TaskEventHandle_BSW_QM_Events_Ev, EventP_ID_00 + EventP_ID_01 + EventP_ID_02,EventP_WaitMode_ANY, EventP_WAIT_FOREVER);
		//If they are SPI Events
		//Currently has dependencies wWill enable back afer discussin with Jaing
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Start_Function(AddRuntimeStats_USIntDeferProcessTask_QM_RUN);
        #endif
		US_USIntDeferProcessTask(events);
        
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_USIntDeferProcessTask_QM_RUN);
        #endif
	    /* Un-comment the below SSM set status after above functions are active */
		//(void)SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_USS,SSM_APPSTATE_RUNNING_i);

#else
		//Sleep:Since it a high priority task and USS is disabled
        TaskP_sleep(1000);
#endif
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Stop_Task(en_Task_en_TasK_BSW_QM_HighPriority_OnEvent);
        #endif
}
}

#if defined ERRORMGR_TEST_MCU2_1
uint8_t AsilFltLvl2Tst_u8=0x0u;
#endif
void Task_BSW_QM_10msec(void *pvParameters)
{
  /* DD-ID: {949B84BF-1B61-4be7-AB8F-990F0018DA1C}*/
    static uint32_t cnt = 0;
#ifdef DEBUG_IPC
    static volatile uint16 Count=0;
#endif
	SSM_SystemState_i SSMSystemState;
	static SSM_SystemStateDef_i previous_SystemState = SSM_STATE_MAX_i;


    while(TRUE)
    {
#if TASK_WAITING_METHOD == TASK_WAITING_METHOD_TASKSLEEP
		TaskP_sleep(10);
#elif TASK_WAITING_METHOD == TASK_WAITING_METHOD_TIMERSEMAPHORE
		(void)SemaphoreP_pend(sem_bsw_qm_10ms, SemaphoreP_WAIT_FOREVER);
#else
		static_asset(0,"Invalid Task Waiting Method");
#endif
#ifdef ADDRUNTIMESTATS
RunTimeStats_BSW_Start_Task(en_TasK_BSW_QM_10msec);
#endif
#ifdef DEBUG_BSW_TASKS
		Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM_10msec]+=1;
#endif

    //Run IPC Manager   
    #ifdef ADDRUNTIMESTATS
    AdditionalRuntimeStats_Start_Function(AddRuntimeStats_IpcManager_QM_RUN);
    #endif
    IPC_F_IpcManager_v();
    #ifdef ADDRUNTIMESTATS
    AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_IpcManager_QM_RUN);
    #endif
#ifdef FREERTOS
    // CPU utilization for Free-rtos
    cnt += 1;
    if (cnt % 500 ==0)
    {
        // cpu load gets call after every 5 sec
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Start_Function(AddRuntimeStats_cpu_load_MCU2_1_QM_RUN);
        #endif
        cpu_load_MCU2_1();
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_cpu_load_MCU2_1_QM_RUN);
        #endif
        cnt = 0; 
    }
#endif

#if defined ERRORMGR_TEST_MCU2_1
        TestErrorManager();
#endif
#ifdef ADDRUNTIMESTATS
AdditionalRuntimeStats_Start_Function(AddRuntimeStats_ERRORMGR_QM_RUN);
#endif
    //Errror manager : Collect the error
      ErrorMgrSatellite_PeriodicFunction_QM();
#ifdef ADDRUNTIMESTATS
AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_ERRORMGR_QM_RUN);
#endif

	  SSM_Slave_MainTask();

	// Read the Master SSM state and update the application status and shutdown activities.
        SigMgr_Data_SSM_SystemState_Get(&SSMSystemState);
        if(previous_SystemState != SSMSystemState.SystemState)
        {
            /* VCAST Jenkins requirement - do not modify */
            /* VCAST Jenkins requirement - do not modify */
            switch(SSMSystemState.SystemState)
            /* VCAST Jenkins requirement - do not modify */
            /* VCAST Jenkins requirement - do not modify */
            {
                case SSM_STATE_BOOTING_i:
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_ErrorMgr, SSM_APPSTATE_INIT_i);
                break;
                case SSM_STATE_IPCREADY_i:
                case SSM_STATE_RUNNING_i:
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_ErrorMgr, SSM_APPSTATE_RUNNING_i);
                break;
                case SSM_STATE_DEGRADED_i:
                case SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP_i:
                case SSM_STATE_OFF_i:
				/* All software specific shutdown activities has to be done here */

				/* End of shutdown activities */

				    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_ErrorMgr, SSM_APPSTATE_STOPPED_i);
              break;
              case SSM_STATE_SHUTTINGDOWN_REMOTECORES_i:
              case SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE_i:
                  while(1)
                  {
				     #if !defined(VCAST)
                     asm volatile(" wfi");
                     #else
                     break;
                     #endif
                  }
                break;
                default:
                break;
            }
            previous_SystemState = SSMSystemState.SystemState;
        }
        #ifdef ADDRUNTIMESTATS
      	RunTimeStats_BSW_Stop_Task(en_TasK_BSW_QM_10msec);
      	#endif
    }
}

void Task_BSW_QM1_10msec(void *pvParameters)
{
  /* DD-ID: {1AC4E9D0-324B-457e-A7D5-692051612857}*/
    SSM_SystemState_i SSMSystemState;
	static SSM_SystemStateDef_i previous_SystemState = SSM_STATE_MAX_i;

    while(TRUE)
    {
        #if TASK_WAITING_METHOD == TASK_WAITING_METHOD_TASKSLEEP
		TaskP_sleep(10);
        #elif TASK_WAITING_METHOD == TASK_WAITING_METHOD_TIMERSEMAPHORE
		(void)SemaphoreP_pend(sem_bsw_qm1_10ms, SemaphoreP_WAIT_FOREVER);
        #else		
        static_asset(0,"Invalid Task Waiting Method");
        #endif
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Start_Task(en_TasK_BSW_QM1_10msec);
        #endif
    #ifdef DEBUG_BSW_TASKS
		Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM1_10msec]+=1;
    #endif

        /* Mark checkpoint progress */
        #if !defined(VCAST)
        WdgM_F_CheckpointReached_v(e_WdgmCpid_TaskBSWQM10msec);
        #endif
        #ifndef USS_FEATURE_DISABLED
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Start_Function(AddRuntimeStats_US_ControllerTask_QM_RUN);
        #endif
        US_ControllerTask();
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_US_ControllerTask_QM_RUN);
        AdditionalRuntimeStats_Start_Function(AddRuntimeStats_US_MgrAndODTask_QM_RUN);
        #endif
        US_MgrAndODTask();
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_US_MgrAndODTask_QM_RUN);
        AdditionalRuntimeStats_Start_Function(AddRuntimeStats_US_InputOutputBuffTask_QM_RUN);
        #endif
        US_InputOutputBuff_Task();
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_US_InputOutputBuffTask_QM_RUN);
        #endif
        #endif
        
		// Read the Master SSM state and update the application status and shutdown activities.
        SigMgr_Data_SSM_SystemState_Get(&SSMSystemState);
        if(previous_SystemState != SSMSystemState.SystemState)
        {
            /* VCAST Jenkins requirement - do not modify */
            /* VCAST Jenkins requirement - do not modify */
            switch(SSMSystemState.SystemState)
            /* VCAST Jenkins requirement - do not modify */
            /* VCAST Jenkins requirement - do not modify */
            {
                case SSM_STATE_BOOTING_i:
                break;

                case SSM_STATE_IPCREADY_i:
                case SSM_STATE_RUNNING_i:
                break;

                case SSM_STATE_DEGRADED_i:
                case SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP_i:
                case SSM_STATE_OFF_i:
#ifndef USS_FEATURE_DISABLED
                (void)UsCsm_ReqState(US_CSM_STATE_ID_SHUTDOWN);
#endif
                break;

                case SSM_STATE_SHUTTINGDOWN_REMOTECORES_i:
                case SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE_i:
                break;
                default:
                break;
            }
            previous_SystemState = SSMSystemState.SystemState;
        }
 #ifdef ADDRUNTIMESTATS
 RunTimeStats_BSW_Stop_Task(en_TasK_BSW_QM1_10msec);
 #endif
    }
}

void Task_BSW_B_10msec(void *pvParameters)
{
  /* DD-ID: {90EAFF26-E277-4a7d-8110-B7344ACD0B23}*/
    while(TRUE)
    {
#if TASK_WAITING_METHOD == TASK_WAITING_METHOD_TASKSLEEP
		TaskP_sleep(10);
#elif TASK_WAITING_METHOD == TASK_WAITING_METHOD_TIMERSEMAPHORE
		(void)SemaphoreP_pend(sem_bsw_b_10ms, SemaphoreP_WAIT_FOREVER);
#else
		static_asset(0,"Invalid Task Waiting Method");
#endif
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Start_Task(en_Task_BSW_B_10msec);
        #endif
#ifdef DEBUG_BSW_TASKS
		Debug_BSW_Tasks_RunCount[en_Task_BSW_B_10msec]+=1;
#endif
#if 0
        /* Mark checkpoint progress */
        WdgM_F_CheckpointReached_v(e_WdgmCpid_TaskBswB10msec);
        /* WDGM scheduled function */
        WdgM_F_MainFunction_v();

       /* WDG scheduled function */ 
        Wdg_Trigger();


#endif 
#if 0
        //Error manager : Collect the error
        ErrorMgrSatellite_PeriodicFunction_B();
#endif  
      
    #ifdef ADDRUNTIMESTATS
    (void)RunTimeStatsData_SendData();
    (void)AddRuntimeStats_StackUsage();
	RunTimeStats_BSW_Stop_Task(en_Task_BSW_B_10msec);
    #endif

    }

}

#ifdef ENABLE_OBJECT_FUSION_CALL
void Task_objectfusion_10msec(void *pvParameters)
{
  /* DD-ID: {AEFD144B-CC3C-4f99-8EA0-75965CC98A2F}*/
    while (TRUE)
    {
#if TASK_WAITING_METHOD == TASK_WAITING_METHOD_TASKSLEEP
        TaskP_sleep(10);
#elif TASK_WAITING_METHOD == TASK_WAITING_METHOD_TIMERSEMAPHORE
        (void)SemaphoreP_pend(sem_bsw_qm_30ms, SemaphoreP_WAIT_FOREVER);
#else
        static_asset(0, "Invalid Task Waiting Method");
#endif
        TaskP_sleep(10);
        F_RAEB_ObjectFusion_Run_v();
#ifdef DEBUG_BSW_TASKS
        Debug_BSW_Tasks_RunCount[en_Task_BSW_B_10msec] += 1;
#endif
    }
}
#endif

#if 0
void TaskFunc_BSW_QM_UssCfg(void *pvParameters)
{
  /* DD-ID: {AB27DBE8-C7CF-4d9b-AC13-74FC70BBA30D}*/
    US_SystemInit();

    while(TRUE)
    {
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Start_Task(en_Task_BSW_QM_UssCfg);
        #endif        
 	    
        US_SnrCfg_Cfg_Task();

        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Stop_Task(en_Task_BSW_QM_UssCfg);
        #endif
    }
}

#endif

void TaskFunc_BSW_QM_Idle(void *pvParameters)
{
  /* DD-ID: {BFE45C81-B358-4373-B34F-DBC391234388}*/

    //US_SystemInit actually return after the tasks are fully running so there is no point to set the state as INIT after that

    /* Un-comment the below SSM set status after above functions are active */
    //(void)SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_USS,SSM_APPSTATE_INIT_i);

    while(TRUE)
    {
		TaskP_sleep(SEC_TO_MILLISEC_COUNT);
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Start_Task(en_Task_BSW_B_Idle);
        #endif

        #ifdef DEBUG_BSW_TASKS
		Debug_BSW_Tasks_RunCount[en_Task_BSW_B_Idle]+=1;
        #endif

        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Stop_Task(en_Task_BSW_B_Idle);
        #endif
    }

}

void TaskFunc_BSW_QM_1msec(void *pvParameters)
{
  /* DD-ID: {4C63F0B5-3D6F-44d2-9A40-D4004B40E225}*/
    static uint32_t Count=0;
    static uint8_t v_WdgmCpCallCnt1ms_u8 = 0;
    #ifdef DEBUG_IPC
    static volatile uint16 Count_ipc=0;
    #endif

    while(TRUE)
    {
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Start_Task(en_Task_BSW_B_1msec);
        #endif
#ifdef DEBUG_BSW_TASKS
		Debug_BSW_Tasks_RunCount[en_Task_BSW_B_1msec]+=1;
#endif
        if(++v_WdgmCpCallCnt1ms_u8 == 5)   /* Checkpoint need to mark at every 10ms */
        {
            v_WdgmCpCallCnt1ms_u8 = 0;
            /* Mark checkpoint progress */
            #if !defined(VCAST)
            WdgM_F_CheckpointReached_v(e_WdgmCpid_TaskBSWQM1msec);
            #endif
        }

#ifndef USS_FEATURE_DISABLED
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Start_Function(AddRuntimeStats_US_DrvTask_QM_RUN);
        #endif
        US_DrvTask();
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_US_DrvTask_QM_RUN);
        #endif
#endif
        //Sleep for 2 msec
        TaskP_sleep(2);
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Stop_Task(en_Task_BSW_B_1msec);
        #endif
    }

}

#ifdef DEBUG_IPC
void IPC_f_SenderFxn_v()
{
  /* DD-ID: {A4AB25F5-B8B5-4b14-9CAF-3B0C3522F106}*/
    IPCMessage_Params_t ipcParams_s;
    ipcParams_s.IpcMsgID_u16 = 0x0003U;
    ipcParams_s.IpcMsgSize_u16 = 0x08U;
    uint8_t v_tx_msgData_u8[8] = {0xAAU, 0xBBU, 0xCCU, 0xDDU};
    ipcParams_s.IpcMsgData_v = &v_tx_msgData_u8[0];
    uint32_t v_status_u32 = 0x00U;

    v_status_u32 =  IPC_F_WrapperSend_u32(&ipcParams_s);

    if(0x00U != v_status_u32)
    {
        /* Set Error */
    }
}
#endif

#if defined ERRORMGR_TEST_MCU2_1
__attribute__((optnone)) static uint8_t TestFault(ldef_ErrorMgr_enErrorNo errorNumber_e)
{
  /* DD-ID: {B63ADF85-12C3-4d5e-B206-29F51AA608EA}*/
    static uint8_t Result_u8=0x0u;
    static uint16_t dly_u16 = 0x0u;
    static ldef_ErrorMgr_enErrorNo errorNumberPrev_e;
    if(errorNumberPrev_e != errorNumber_e)
    {
        dly_u16 = 0x0u;
        Result_u8 = 0x0u;
        errorNumberPrev_e = errorNumber_e;
    }

    if(dly_u16 < 1000u)
    {
        (void)ErrorMgrSatellite_ReportErrorStatus(errorNumber_e,ldef_ErrorMgr_ErrorActive,NULL);
        dly_u16++;
    }
    else if(dly_u16 < 2000u)
    {
        (void)ErrorMgrSatellite_ReportErrorStatus(errorNumber_e,ldef_ErrorMgr_ErrorInactive,NULL);
        dly_u16++;
    }
    else
    {
        /* Test is complete for this error */
        Result_u8 = 0x01u;
        dly_u16 = 0x0u;
        UART_printf("[MCU2_1] Error Manager Test for Error Number %d is complete\n",errorNumber_e);
    }

    return Result_u8;
}

__attribute__((optnone)) static void TestErrorManager(void)
{
  /* DD-ID: {B11D182A-552C-4563-8E7E-F83538E45D38}*/
  /* README ERRORMGR_TEST_MCU2_1
   * AsilFltLvl2Tst_u8
   * = 0x0u for ErrorMgr_Asil_QM Test
   * = 0x1u for ErrorMgr_Asil_B  Test
  */
  const ErrorMgr_ErrorDescExt * ErrDescTblPtr_s;
  const ErrorMgr_ErrorDesc* ErrDesc_s;
  static uint16_t NumFlt2Tst_u16 = 72u;
  static uint16_t currFltNum_u16=0u;
  static uint8_t PrevAsilFltLvl2Tst_u8=0xFFu;
  static uint8_t TestComplete_u8=0u;
  ldef_ErrorMgr_enErrorNo errorNumber_e;
  if(AsilFltLvl2Tst_u8 < ErrorMgr_Asil_MAX)
  {
      ErrDescTblPtr_s = ErrorMgr_getGetErrorLocalDesc();
      if (ErrDescTblPtr_s != NULL)
      {
          if(PrevAsilFltLvl2Tst_u8 != AsilFltLvl2Tst_u8)
          {
              /* Reset Static Variables on Test Change */
              TestComplete_u8 = 0x0u;
              currFltNum_u16 = 0x0u;
              NumFlt2Tst_u16 = ErrDescTblPtr_s[AsilFltLvl2Tst_u8].Count;
              PrevAsilFltLvl2Tst_u8=AsilFltLvl2Tst_u8;
          }

          if((TestComplete_u8 == 0x00u) && (NumFlt2Tst_u16!=0x0u))
          {
              ErrDesc_s = ErrDescTblPtr_s[AsilFltLvl2Tst_u8].ErrorDesc;
              errorNumber_e = ErrDesc_s[currFltNum_u16].enError;
              TestComplete_u8 = TestFault(errorNumber_e);
          }

          if(TestComplete_u8 == 0x01u)
          {
              TestComplete_u8 = 0x0u;
              if(currFltNum_u16 == NumFlt2Tst_u16-1)
              {
                  /* QM Error Tests Complete*/
                  if(AsilFltLvl2Tst_u8 == 0x0u)
                  {
                      UART_printf("[MCU2_1] Error Manager Tests are complete for QM Faults\n");
                  }
                  else if(AsilFltLvl2Tst_u8 == 0x01u)
                  {
                      UART_printf("[MCU2_1] Error Manager Tests are complete for ASIL B Faults\n");
                  }
                  else
                  {
                      /* Not a Valid ASIL Level */
                  }
                  currFltNum_u16 = 0x0u;
              }
              else
              {
                  /* Go To Next Error */
                  UART_printf("[MCU2_1] errorNumber_e=%d has been Tested\n",errorNumber_e);
                  currFltNum_u16++;
              }
          }
          else
          {
              /* Do Nothing - Test not yet complete */
          }
      }
      else
      {
          /* Error Descriptor is NULL */
      }
  }
  else
  {
      /* Invalid ASIL Level - Cannot run tests */
  }
}
#endif
