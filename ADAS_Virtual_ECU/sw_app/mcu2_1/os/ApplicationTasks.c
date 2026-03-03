
/* ========================================================================== */
/*                          Header Inclusions                                */
/* ========================================================================== */

#include "ApplicationTasks.h"

#include <osal.h>
#include <UART_stdio.h>

#include "uart_utils.h"
#include "main_domain_utils.h"
#include "mcu_timer_read_multicore.h"


/* QAC Warning Resolve: Removed some Unused Packages*/
#include "SSM_Slave.h"
#include "SignalDef.h"

#ifdef PERF_STATS_OUT
#include <app_perf_stats.h>
#endif

#ifdef ADDRUNTIMESTATS
#include "AddRuntimeStats.h"
#include "RunTimeStats.h"
#endif

#ifdef AUTO_PARK_EN
#include "AP.h"
#endif /* AUTO_PARK_EN*/

#ifdef ENABLE_THA_SM_VC
#include "THA_SM.h"
#endif

#ifdef FOD_EN
#include "FOD.h"
#endif

#ifdef ARBITER_EN
#include "Arbiter.h"
#endif

#ifdef ENABLE_TRSC
#include "TRSC.h"
#endif

#include "SafeRTOS_API.h"
#include "SafeRTOSConfig.h"
#if 0
#include "WdgM.h"
#endif

#include "WdgM.h"

volatile uint16_t v_MCU2_1_Preiodicity_t = 0;
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void Task_APP_QM_10msec(void *pvParameters);
void Task_APP_B_10msec(void *pvParameters);



#ifdef DEBUG_APP_TASKS
    static uint32_t Debug_APP_Tasks_RunCount[en_Task_APP_MAX]={0};
    static uint32_t Debug_App_tickirq_ct[en_Task_APP_MAX]={0};
    static uint32_t Debug_App_Tasks_ErrCount[en_Task_APP_MAX]={0};
#endif

static bool apptask_init = FALSE;

configKERNEL_DATA_DEF static xTCB xAPP_QM_10msTaskTCB = { 0 };
static portInt8Type TaskStack_APP_QM_10msec[TASK_STACKSIZE_APP_QM_10msec]
#if !defined(VCAST)
__attribute__((section(".bss:taskStackSection")))
__attribute__((aligned(TASK_STACKSIZE_APP_QM_10msec)))
#endif
;


configKERNEL_DATA_DEF static xTCB xAPP_B_10msTaskTCB = { 0 };
static portInt8Type TaskStack_APP_B_10msec[TASK_STACKSIZE_APP_B_10msec]
#if !defined(VCAST)
__attribute__((section(".bss:taskStackSection")))
__attribute__((aligned(TASK_STACKSIZE_APP_B_10msec))) 
#endif
;


static SemaphoreP_Handle sem_app_qm_10ms;
static SemaphoreP_Handle sem_app_b_10ms;

static volatile uint32_t Tasks_APP_AddDebugStartDelay_DelayCount=0;

static void Tasks_APP_AddDebugStartDelay(void);


static void Tasks_APP_AddDebugStartDelay(void)
{
  /* DD-ID: {DEF5A92C-11EA-4e0c-B5C8-B2080357BA4A}*/
#ifdef TASK_APP_ADD_DEBUG_STARTUPDELAY    
    while(Tasks_APP_AddDebugStartDelay_DelayCount++ < 0x7FFFFFFF);
#endif
}
void init_sem_appsw(void)
{
  /* DD-ID: {9A3C0650-6C4C-4f27-8C42-8292740358F9}*/
    SemaphoreP_Params SemParams;
    
    SemaphoreP_Params_init(&SemParams);
    SemParams.mode = SemaphoreP_Mode_BINARY;

    sem_app_qm_10ms = SemaphoreP_create(0, &SemParams);
    sem_app_b_10ms = SemaphoreP_create(0, &SemParams);
}

void appsw_tick_5ms(void)
{
  /* DD-ID: {A9F72B0F-BFDE-4240-BE50-F831FFDE2586}*/
    static uint32_t Count;
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if ((Count % TICKCOUNT_30MS) == 0)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        if (apptask_init != FALSE)
        {
            SemaphoreP_post((void*)sem_app_b_10ms);
            SemaphoreP_post((void*)sem_app_qm_10ms);

#ifdef DEBUG_APP_TASKS
            if (Debug_App_tickirq_ct[en_TasK_APP_QM_10msec] != Debug_APP_Tasks_RunCount[en_TasK_APP_QM_10msec])
            {
                Debug_App_Tasks_ErrCount[en_TasK_APP_QM_10msec]++;
                /* reset the error */
                Debug_App_tickirq_ct[en_TasK_APP_QM_10msec] = Debug_APP_Tasks_RunCount[en_TasK_APP_QM_10msec];
            }
            Debug_App_tickirq_ct[en_TasK_APP_QM_10msec]++;
            if (Debug_App_tickirq_ct[en_Task_APP_B_10msec] != Debug_APP_Tasks_RunCount[en_Task_APP_B_10msec])
            {
                Debug_App_Tasks_ErrCount[en_Task_APP_B_10msec]++;
                /* reset the error */
                Debug_App_tickirq_ct[en_Task_APP_B_10msec] = Debug_APP_Tasks_RunCount[en_Task_APP_B_10msec];
            }
            Debug_App_tickirq_ct[en_Task_APP_B_10msec]++;
#endif
		}
    }
    Count++;
}

bool_t Tasks_Launch_AppTasks(void)
{
  /* DD-ID: {75EE8FE5-F82F-4bfd-B91E-D9A137711EC1}*/
    bool bRet=TRUE;
    portBaseType xCreateResult;
    
    static const xTaskParameters xAPP_QM_10msecTaskParams =
    {
        &Task_APP_QM_10msec,                  /* The function that implements the task being created. */
        "Task_APP_QM_10msec",     /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xAPP_QM_10msTaskTCB,                 /* TCB for the task. */
        TaskStack_APP_QM_10msec,               /* The buffer allocated for use as the task stack. */
        sizeof (TaskStack_APP_QM_10msec),  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_APP_QM_10msec,    /* The priority to assigned to the task being created. */
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
    static const xTaskParameters xAPP_B_10msTaskParams =
    {
        &Task_APP_B_10msec,                  /* The function that implements the task being created. */
        "Task_APP_B_10msec",     /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xAPP_B_10msTaskTCB,                 /* TCB for the task. */
        TaskStack_APP_B_10msec,               /* The buffer allocated for use as the task stack. */
        sizeof (TaskStack_APP_B_10msec),  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_APP_B_10msec,    /* The priority to assigned to the task being created. */
        NULL,                           /* Thread Local Storage not used. */
        pdTRUE,                        /* task uses the FPU. */
        {                               /* MPU task parameters. */
           /* TO DO: Task is supposed to be running in mpuUNPRIVILEGED_TASK mode  */
            mpuPRIVILEGED_TASK,         /* task is unprivileged. */
            {                                                           
                {                                                       
                    MCU2_1_ASILB_DATA_BASE_ADDR,                  
                    MCU2_1_ASILB_DATA_LEN,                  
                    ( mpuREGION_PRIVILEGED_READ_WRITE_USER_READ_WRITE | 
                      mpuREGION_EXECUTE_NEVER |                         
                      mpuREGION_INTERNAL_RAM_DEFAULT_CACHE_POLICY ),    
                    mpuREGION_7TH_SUB_REGION_DISABLE | mpuREGION_8TH_SUB_REGION_DISABLE                   
                },                                                      
                { NULL, 0U, 0U, 0U }                                    
            }                                                           
        }
    };
    Tasks_APP_AddDebugStartDelay();

    /*Initalize Application Inits here*/
    F_TRSC_Init_v();
    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_TRSC, SSM_APPSTATE_INIT_i);
    F_THA_SM_Init();
    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_THASM, SSM_APPSTATE_INIT_i); 
    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_APFusion, SSM_APPSTATE_INIT_i);
    F_AP_Init_v();
    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_AutoPark, SSM_APPSTATE_INIT_i);
    F_FOD_Init_v();
    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_FOD, SSM_APPSTATE_INIT_i);
    F_Arbiter_Init_v();
    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_Arbiter, SSM_APPSTATE_INIT_i);

    /* Launch the tasks */

    /* QM Tasks */
    xCreateResult = xTaskCreate( &xAPP_QM_10msecTaskParams, /* The structure containing the task parameters created at the start of this function. */
                                 NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */

#ifdef PERF_STATS_OUT
	if (xCreateResult == pdPASS)
    {
        appPerfStatsRegisterTask(TaskHandle_APP_QM_10msec, (char *)TaskParams_APP_QM_10msec.instance->name);
    }
#endif

    /* APP Asil B Task */
    if (xCreateResult == pdPASS)
    {
        /* APP Asil B Task */
        xCreateResult = xTaskCreate( &xAPP_B_10msTaskParams, /* The structure containing the task parameters created at the start of this function. */
                                 NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */
    }
    
#ifdef PERF_STATS_OUT
	if (xCreateResult == pdPASS)
    {
        appPerfStatsRegisterTask(TaskHandle_APP_B_10msec, (char *)TaskParams_APP_B_10msec.instance->name);
    }
#endif

    if (xCreateResult != pdPASS)
    {
        UART_printf("\n[MCU2_1] Application Tasks Launch failed...!");
        bRet=FALSE;
    }
    else
    {
        /*UART_printf("\n[MCU2_1] Application Tasks created...!"); */
		apptask_init = TRUE; /* App tasks are initialized */  
    }

    #ifdef ADDRUNTIMESTATS
    TaskStackData[s_TasK_APP_QM_10msec].Task_LowAdd = (uint32)xAPP_QM_10msecTaskParams.pcStackBuffer;
    TaskStackData[s_TasK_APP_QM_10msec].Task_Size = xAPP_QM_10msecTaskParams.uxStackDepthBytes;
    if (TaskStackData[s_TasK_APP_QM_10msec].Task_LowAdd <= (UINT32_MAX - TaskStackData[s_TasK_APP_QM_10msec].Task_Size)) 
    {
        TaskStackData[s_TasK_APP_QM_10msec].Task_HighAdd = TaskStackData[s_TasK_APP_QM_10msec].Task_LowAdd + TaskStackData[s_TasK_APP_QM_10msec].Task_Size;
    }
    else
    {
        TaskStackData[s_TasK_APP_QM_10msec].Task_HighAdd = UINT32_MAX;
    }

    TaskStackData[s_Task_APP_B_10msec].Task_LowAdd = (uint32)xAPP_B_10msTaskParams.pcStackBuffer; 
    TaskStackData[s_Task_APP_B_10msec].Task_Size = xAPP_B_10msTaskParams.uxStackDepthBytes;
    if (TaskStackData[s_Task_APP_B_10msec].Task_LowAdd <= (UINT32_MAX - TaskStackData[s_Task_APP_B_10msec].Task_Size)) 
    {
        TaskStackData[s_Task_APP_B_10msec].Task_HighAdd = TaskStackData[s_Task_APP_B_10msec].Task_LowAdd + TaskStackData[s_Task_APP_B_10msec].Task_Size;
    }
    else
    {
        TaskStackData[s_Task_APP_B_10msec].Task_HighAdd = UINT32_MAX;
    }
    #endif
     
    return bRet;

}



void Task_APP_QM_10msec(void *pvParameters)
{
  /* DD-ID: {FB6D76D4-E794-4d2e-B504-BC8245354FDE}*/

	while(TRUE)
	{
#if TASK_WAITING_METHOD == TASK_WAITING_METHOD_TASKSLEEP
		TaskP_sleep(10);
#elif TASK_WAITING_METHOD == TASK_WAITING_METHOD_TIMERSEMAPHORE
		(void)SemaphoreP_pend(sem_app_qm_10ms, SemaphoreP_WAIT_FOREVER);
#else
		static_asset(0,"Invalid Task Waiting Method");
#endif
#ifdef ADDRUNTIMESTATS
RunTimeStats_APP_Start_Task(en_TasK_APP_QM_10msec);
#endif
#ifdef DEBUG_APP_TASKS
		Debug_APP_Tasks_RunCount[en_TasK_APP_QM_10msec]+=1;
#endif
#ifdef ADDRUNTIMESTATS
RunTimeStats_APP_Stop_Task(en_TasK_APP_QM_10msec);
#endif

	}
    
}

void Task_APP_B_10msec(void *pvParameters)
{
  /* DD-ID: {46816513-7D54-4865-A445-4814362AD668}*/
    SSM_SystemState_i SSMSystemState;
    static SSM_SystemStateDef_i previous_SystemState = SSM_STATE_MAX_i;
    while(TRUE)
    {
#if TASK_WAITING_METHOD == TASK_WAITING_METHOD_TASKSLEEP
		TaskP_sleep(10);
#elif TASK_WAITING_METHOD == TASK_WAITING_METHOD_TIMERSEMAPHORE
		(void)SemaphoreP_pend(sem_app_b_10ms, SemaphoreP_WAIT_FOREVER);
#else
		static_asset(0,"Invalid Task Waiting Method");
#endif

        /* Mark checkpoint progress */
		#if !defined(VCAST)
        WdgM_F_CheckpointReached_v(e_WdgmCpid_TaskAppB10msecHiPriority);
		#endif

        #ifdef ADDRUNTIMESTATS
        RunTimeStats_APP_Start_Task(en_Task_APP_B_10msec);
        #endif

#ifdef DEBUG_APP_TASKS
		Debug_APP_Tasks_RunCount[en_Task_APP_B_10msec]+=1;
#endif
        v_MCU2_1_Preiodicity_t ^= 1;
        /* Application Runs here */
		F_TRSC_Run_v();
        F_THA_SM_Run();
        /*SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_THASM, SSM_APPSTATE_RUNNING_i);*/
        /*SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_NFCD, SSM_APPSTATE_RUNNING_i);*/
        F_AP_Run_v();
        /*SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_AutoPark, SSM_APPSTATE_RUNNING_i);*/
        /*SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_APFusion, SSM_APPSTATE_RUNNING_i);*/
        F_FOD_Run_v();
        /*SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_FOD, SSM_APPSTATE_RUNNING_i);*/
        F_Arbiter_Run_v();
		
		/* Read master SSM state and update the application status*/
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
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_TRSC, SSM_APPSTATE_INIT_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_THASM, SSM_APPSTATE_INIT_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_APFusion, SSM_APPSTATE_INIT_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_AutoPark, SSM_APPSTATE_INIT_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_FOD, SSM_APPSTATE_INIT_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_Arbiter, SSM_APPSTATE_INIT_i);
                break;
                case SSM_STATE_IPCREADY_i:
                case SSM_STATE_RUNNING_i:
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_TRSC, SSM_APPSTATE_RUNNING_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_THASM, SSM_APPSTATE_RUNNING_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_APFusion, SSM_APPSTATE_RUNNING_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_AutoPark, SSM_APPSTATE_RUNNING_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_FOD, SSM_APPSTATE_RUNNING_i);
        SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_Arbiter, SSM_APPSTATE_RUNNING_i);
                break;
                case SSM_STATE_DEGRADED_i:
                case SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP_i:
                case SSM_STATE_OFF_i:
                case SSM_STATE_SHUTTINGDOWN_REMOTECORES_i:
                case SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE_i:
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_TRSC, SSM_APPSTATE_STOPPED_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_THASM, SSM_APPSTATE_STOPPED_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_APFusion, SSM_APPSTATE_STOPPED_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_AutoPark, SSM_APPSTATE_STOPPED_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_FOD, SSM_APPSTATE_STOPPED_i);
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_Arbiter, SSM_APPSTATE_STOPPED_i);
                break;
                default:
                break;
            }
            previous_SystemState = SSMSystemState.SystemState;
        }
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_APP_Stop_Task(en_Task_APP_B_10msec);
        #endif

    }
}



