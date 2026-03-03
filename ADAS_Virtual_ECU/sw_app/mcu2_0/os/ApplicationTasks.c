
/* ========================================================================== */
/*                          Header Inclusions                                */
/* ========================================================================== */

#include "ApplicationTasks.h"


#include <ti/osal/osal.h>
//#include <ti/osal/TaskP.h>

/* Base Magna Software Includes*/
#include "SSM_Slave.h"
#include "SignalDef.h"
#include "WdgM.h"

//#include "main_domain_utils.h"
//#include "mcu_timer_read_multicore.h"
#include <utils/console_io/include/app_log.h>
#include "ti/osal/TimerP.h"

/* Application Features Includes */
#include "HMI.h"
// AddRuntimeStats
#include "AddRuntimeStats.h"
#include "RunTimeStats.h"

#define HMI_TIME_PROFILING 0

#if HMI_TIME_PROFILING
    #include <ti/osal/TimerP.h>
    #include <ti/osal/osal.h>
    #include <utils/console_io/include/app_log.h>
    #define iterations 1000llu
    #define scheduling_ideal 10000llu
    #define scheduling_tolerence 5000llu /*1 ms*/
    static uint64_t start_time, end_time;
    static uint64_t prev_start_time;
    static uint64_t HMI_exec_counter = 0;
    static uint64_t HMI_scheduling_time[iterations];
    static uint64_t HMI_execution_time[iterations];
    static bool start_logs = FALSE;
#endif



/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void Task_APP_QM_10msec(void* arg0, void* arg1);
void Task_APP_B_10msec(void* arg0, void* arg1);
void Task_APP_B_30msec(void* arg0, void* arg1);



#ifdef DEBUG_APP_TASKS
    static uint32_t Debug_APP_Tasks_RunCount[en_Task_APP_MAX]={0};
    static uint32_t Debug_App_tickirq_ct[en_Task_APP_MAX]={0};
    static uint32_t Debug_App_Tasks_ErrCount[en_Task_APP_MAX]={0};
#endif

static TaskP_Params TaskParams_APP_QM_10msec;
static TaskP_Handle TaskHandle_APP_QM_10msec;
static uint8_t TaskStack_APP_QM_10msec[TASK_STACKSIZE_APP_QM_10msec]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_ALIGNMENT)))
#endif
;


static TaskP_Params TaskParams_APP_B_10msec;
static TaskP_Handle TaskHandle_APP_B_10msec;
static uint8_t TaskStack_APP_B_10msec[TASK_STACKSIZE_APP_B_10msec]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_ALIGNMENT)))
#endif
;

static TaskP_Params TaskParams_APP_B_30msec;
static TaskP_Handle TaskHandle_APP_B_30msec;
static uint8_t TaskStack_APP_B_30msec[TASK_STACKSIZE_APP_B_30msec]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_ALIGNMENT)))
#endif
;

SemaphoreP_Handle sem_app_qm_10ms;
SemaphoreP_Handle sem_app_b_10ms;
SemaphoreP_Handle sem_app_b_30ms;

volatile uint32_t Tasks_APP_AddDebugStartDelay_DelayCount=0;
volatile uint16_t v_MCU2_0_Preiodicity_t = 0;

void Tasks_APP_AddDebugStartDelay(void)
{
  /* DD-ID: {AF2033FE-12B8-4b7c-BC68-83CE1E8C8C6E}*/
    #ifdef TASK_APP_ADD_DEBUG_STARTUPDELAY    
    while(Tasks_APP_AddDebugStartDelay_DelayCount++ < 0x7FFFFFFF);
    #endif
}

void init_sem_appsw(void)
{
  /* DD-ID: {4DE74B73-C2A9-4579-BD07-E468DC33EC90}*/
    sem_app_qm_10ms = SemaphoreP_create(0, NULL);
    sem_app_b_10ms = SemaphoreP_create(0, NULL);
    sem_app_b_30ms = SemaphoreP_create(0, NULL);
}

void appsw_tick_5ms(void)
{
  /* DD-ID: {24322D65-EFE8-4fdd-B00E-A451421BA316}*/
    static uint32_t Count;
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if ((Count % 2) == 0)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        SemaphoreP_post(sem_app_b_10ms);
        SemaphoreP_post(sem_app_qm_10ms);

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

    if ((Count % 6) == 0)
    {
        SemaphoreP_post(sem_app_b_30ms);
        
#ifdef DEBUG_APP_TASKS
        if (Debug_App_tickirq_ct[en_Task_APP_B_30msec] != Debug_APP_Tasks_RunCount[en_Task_APP_B_30msec])
        {
            Debug_App_Tasks_ErrCount[en_Task_APP_B_30msec]++;
            /* reset the error */
            Debug_App_tickirq_ct[en_Task_APP_B_30msec] = Debug_APP_Tasks_RunCount[en_Task_APP_B_30msec];
        }
        Debug_App_tickirq_ct[en_Task_APP_B_30msec]++;
#endif
    }

    Count++;
}

bool_t Tasks_Launch_AppTasks(void)
{
  /* DD-ID: {A736F6DE-EB3E-4355-BCB5-EBD39BE314D2}*/
    bool bRet=TRUE;

    Tasks_APP_AddDebugStartDelay();

    //Initalize Application Inits here 

    SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_HMIMgr,SSM_APPSTATE_INIT_i);
    HMI_Init();
    //SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_KM,SSM_APPSTATE_INIT_i);
    //HSFIntgr_Init();
    //SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_HSF,SSM_APPSTATE_INIT_i);
    //AP_StateMachine_Init();
    //SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_APStateMachine,SSM_APPSTATE_INIT_i);
    /* Will be enabled after testing */

    //Launch the tasks

    //QM Tasks
    TaskP_Params_init(&TaskParams_APP_QM_10msec);
    /* Set the task priority higher than the default priority (1) */
    TaskParams_APP_QM_10msec.name="Task_APP_QM_10msec";
    TaskParams_APP_QM_10msec.arg0 = (void*) NULL;
    TaskParams_APP_QM_10msec.arg1 = (void*) NULL;
    TaskParams_APP_QM_10msec.priority = TASK_PRIORITY_APP_QM_10msec;
    TaskParams_APP_QM_10msec.stack = TaskStack_APP_QM_10msec;
    TaskParams_APP_QM_10msec.stacksize = sizeof (TaskStack_APP_QM_10msec);

    TaskHandle_APP_QM_10msec = TaskP_create(Task_APP_QM_10msec, &TaskParams_APP_QM_10msec);


    //APP Asil B Task
    TaskP_Params_init(&TaskParams_APP_B_10msec);
    /* Set the task priority higher than the default priority (1) */
    TaskParams_APP_B_10msec.name="Task_APP_B_10msec";
    TaskParams_APP_B_10msec.arg0 = (void*) NULL;
    TaskParams_APP_B_10msec.arg1 = (void*) NULL;
    TaskParams_APP_B_10msec.priority = TASK_PRIORITY_APP_B_10msec;
    TaskParams_APP_B_10msec.stack = TaskStack_APP_B_10msec;
    TaskParams_APP_B_10msec.stacksize = sizeof (TaskStack_APP_B_10msec);

    TaskHandle_APP_B_10msec = TaskP_create(Task_APP_B_10msec, &TaskParams_APP_B_10msec);

   //APP Asil B Task
    TaskP_Params_init(&TaskParams_APP_B_30msec);
    /* Set the task priority higher than the default priority (1) */
    TaskParams_APP_B_30msec.name="Task_APP_B_30msec";
    TaskParams_APP_B_30msec.arg0 = (void*) NULL;
    TaskParams_APP_B_30msec.arg1 = (void*) NULL;
    TaskParams_APP_B_30msec.priority = TASK_PRIORITY_APP_B_30msec;
    TaskParams_APP_B_30msec.stack = TaskStack_APP_B_30msec;
    TaskParams_APP_B_30msec.stacksize = sizeof (TaskStack_APP_B_30msec);

    TaskHandle_APP_B_30msec = TaskP_create(Task_APP_B_30msec, &TaskParams_APP_B_30msec);

    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if((NULL == TaskHandle_APP_QM_10msec)  || (NULL == TaskHandle_APP_B_10msec) || (NULL == TaskHandle_APP_B_30msec))
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {

        bRet=FALSE;
    }
    #ifdef ADDRUNTIMESTATS
    TaskStackData[s_Task_APP_B_10msec].Task_LowAdd = (uint32)TaskParams_APP_B_10msec.stack;
    TaskStackData[s_Task_APP_B_10msec].Task_Size = TaskParams_APP_B_10msec.stacksize;
    TaskStackData[s_Task_APP_B_10msec].Task_HighAdd = TaskStackData[s_Task_APP_B_10msec].Task_LowAdd  + TaskStackData[s_Task_APP_B_10msec].Task_Size;

    TaskStackData[s_TasK_APP_QM_10msec].Task_LowAdd = (uint32)TaskParams_APP_QM_10msec.stack;
    TaskStackData[s_TasK_APP_QM_10msec].Task_Size = TaskParams_APP_QM_10msec.stacksize;
    TaskStackData[s_TasK_APP_QM_10msec].Task_HighAdd = TaskStackData[s_TasK_APP_QM_10msec].Task_LowAdd  + TaskStackData[s_TasK_APP_QM_10msec].Task_Size;

    TaskStackData[s_Task_APP_B_30msec].Task_LowAdd = (uint32)TaskParams_APP_B_30msec.stack;
    TaskStackData[s_Task_APP_B_30msec].Task_Size = TaskParams_APP_B_30msec.stacksize;
    TaskStackData[s_Task_APP_B_30msec].Task_HighAdd = TaskStackData[s_Task_APP_B_30msec].Task_LowAdd  + TaskStackData[s_Task_APP_B_30msec].Task_Size;
    #endif
    return bRet;

}



void Task_APP_QM_10msec(void* arg0, void* arg1)
{
  /* DD-ID: {1AEF6016-815F-4c70-8B68-BD1687321996}*/

    while(TRUE)
    {
        (void)SemaphoreP_pend(sem_app_qm_10ms, SemaphoreP_WAIT_FOREVER);
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

void Task_APP_B_30msec(void* arg0, void* arg1)
{
  /* DD-ID: {5C158F59-0BE4-4b6e-A8D8-68A9C5310817}*/
    uint64_t u64PrevStartTime = TimerP_getTimeInUsecs();
    uint64_t u64StartTime = 0;

    while(TRUE)
    {
        (void)SemaphoreP_pend(sem_app_b_30ms, SemaphoreP_WAIT_FOREVER);
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_APP_Start_Task(en_Task_APP_B_30msec);
        #endif
        u64StartTime = TimerP_getTimeInUsecs();
        v_MCU2_0_Preiodicity_t ^= 1;
#if DEBUG_TRSC_INTERVAL
        appLogPrintf("Task_APP_B_30msec Running: %lld : Interval %u us\n",u64StartTime,(uint32_t)(u64StartTime - u64PrevStartTime));
#endif
        u64PrevStartTime = u64StartTime;
        #ifdef DEBUG_APP_TASKS
            Debug_APP_Tasks_RunCount[en_Task_APP_B_30msec]+=1;
        #endif 
        // WdgM_F_CheckpointReached_v(e_WdgmCpid_TaskAppB30msec);

        #ifdef ADDRUNTIMESTATS
        RunTimeStats_APP_Stop_Task(en_Task_APP_B_30msec);
        #endif
    }

}

void Task_APP_B_10msec(void* arg0, void* arg1)
{
  /* DD-ID: {EEAB076B-1FC0-42e0-AF30-71EF2D40FA87}*/
    SSM_SystemState_i SSMSystemState;
    static SSM_SystemStateDef_i previous_SystemState = SSM_STATE_MAX_i;

    while(TRUE)
    {
        (void)SemaphoreP_pend(sem_app_b_10ms, SemaphoreP_WAIT_FOREVER);
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_APP_Start_Task(en_Task_APP_B_10msec);
        #endif
	    #if HMI_TIME_PROFILING  
            
            prev_start_time = start_time;
            start_time = TimerP_getTimeInUsecs();

            if(iterations > HMI_exec_counter)
                HMI_scheduling_time[HMI_exec_counter] = start_time - prev_start_time;
            else
                appLogPrintf("\n Core Crash Avoided sch!!!! \n");
        #endif
	    HMI_Run();
        #if HMI_TIME_PROFILING
            end_time = TimerP_getTimeInUsecs();
            
            if(iterations > HMI_exec_counter)
                HMI_execution_time[HMI_exec_counter] = end_time - start_time;
            else
                appLogPrintf("\n Core Crash Avoided exe!!!! \n");

            HMI_exec_counter++;
            if(iterations == HMI_exec_counter)
            {
                // appLogPrintf("nth iteration timestamp = %llu", start_time);
                HMI_exec_counter = 0;
                uint64_t sum_exe = 0, sum_sch = 0;
                uint64_t min_exe_index, max_exe_index, min_sch_index, max_sch_index;
                uint64_t min_time_exe = -1, max_time_exe = 0;
                uint64_t min_time_sch = -1, max_time_sch = 0;
                uint64_t times_delay_sch = 0, times_prior_sch = 0;

                for(uint64_t index = 0; index<iterations; index++)
                {
                    sum_exe += HMI_execution_time[index];
                    sum_sch += HMI_scheduling_time[index];

                    if(max_time_exe < HMI_execution_time[index])
                    {
                        max_time_exe = HMI_execution_time[index];
                        max_exe_index = index;
                    }

                    if(min_time_exe > HMI_execution_time[index])
                    {
                        min_time_exe = HMI_execution_time[index];
                        min_exe_index = index;
                    }

                    if(max_time_sch < HMI_scheduling_time[index])
                    {
                        max_time_sch = HMI_scheduling_time[index];
                        max_sch_index = index;
                    }

                    if(min_time_sch > HMI_scheduling_time[index])
                    {
                        min_time_sch = HMI_scheduling_time[index];
                        min_sch_index = index;
                    }

                    if(scheduling_ideal > HMI_scheduling_time[index])
                    {
                        if((scheduling_ideal - HMI_scheduling_time[index]) > scheduling_tolerence)
                            times_prior_sch++;
                    }
                    else
                    {
                        if((HMI_scheduling_time[index] - scheduling_ideal) > scheduling_tolerence)
                            times_delay_sch++;  
                    }
                }

                if((50000000llu < TimerP_getTimeInUsecs()) && (FALSE == start_logs))
                {
                    start_logs = TRUE;
                    appLogPrintf("HMI: Iterations, Tolerence, Times_Prior_Scheduled, Times_Delayed_Scheduled, Avg_Exe_Time, Max_Exe_Time, Max_Exe_Index, Min_Exe_Time, Min_Exe_Index, Avg_Sch_Time, Max_Sch_Time, Max_Sch_Index, Min_Sch_Time, Min_Sch_Index\n");
                }

                if(start_logs)
                {
                    appLogPrintf("HMI: %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu, %llu\n"
                    ,iterations
                    ,scheduling_tolerence
                    ,times_prior_sch
                    ,times_delay_sch
                    ,(sum_exe/iterations)
                    ,max_time_exe
                    ,max_exe_index
                    ,min_time_exe
                    ,min_exe_index
                    ,(sum_sch/iterations)
                    ,max_time_sch
                    ,max_sch_index
                    ,min_time_sch
                    ,min_sch_index
                    );
                }
            }
        #endif
	    //SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_HMIMgr,SSM_APPSTATE_RUNNING_i);
        #ifdef DEBUG_APP_TASKS
            Debug_APP_Tasks_RunCount[en_Task_APP_B_10msec]+=1;
        #endif
        /* Mark checkpoint progress */
        // WdgM_F_CheckpointReached_v(e_WdgmCpid_TaskAppB10msec);
        // TODO: Is this needed for Stellantis?
        //HMI_STM_Run(HMI_STM_new());

        // Read the Master SSM state and update the application status
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
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_HMIMgr, SSM_APPSTATE_INIT_i);
                break;
                case SSM_STATE_IPCREADY_i:
                case SSM_STATE_RUNNING_i:
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_HMIMgr, SSM_APPSTATE_RUNNING_i);
                break;
                case SSM_STATE_DEGRADED_i:
                case SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP_i:
                case SSM_STATE_OFF_i:
                case SSM_STATE_SHUTTINGDOWN_REMOTECORES_i:
                case SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE_i:
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_HMIMgr, SSM_APPSTATE_STOPPED_i);
                break;
                default:
                break;
            }
            previous_SystemState = SSMSystemState.SystemState;
        }

        //SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_KM,SSM_APPSTATE_RUNNING_i);
        //HSFIntgr_Run();
        //SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_HSF,SSM_APPSTATE_RUNNING_i);
        //AP_StateMachine_Run();  
        //SSM_Slave_SetApplicationStatus(SSM_MCU_2_1_Application_APStateMachine,SSM_APPSTATE_RUNNING_i);
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_APP_Stop_Task(en_Task_APP_B_10msec);
        #endif
    }
    
}


