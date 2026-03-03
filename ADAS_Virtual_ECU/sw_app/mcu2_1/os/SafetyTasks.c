/* ========================================================================== */
/*                          Header Inclusions                                */
/* ========================================================================== */

#include "SafetyTasks.h"
#include "TaskDefscfg.h"
#include <stddef.h>
#include "compiler_asildefs.h"

/* TI PDK includes */
#include <ti/osal/osal.h>
#include <ti/osal/TaskP.h>
#include <ti/osal/SemaphoreP.h>

/* SafeRTOS includes */
#include "SafeRTOS_API.h"

#if 1
#include "WdgM.h"
#include "Wdg.h"

#endif
#include "ErrorManagerDef.h"
#include "ErrorManagerSatellite.h"
#ifdef TIME_MANAGER_PROXY
#include "TimeManagerProxy.h"
#endif
#include "SignalMgr.h"
#include "SignalDef.h"
#include "SafeRTOSConfig.h"
#include "SafetyTasks.h"
#include "Safety_CDD.h"
#ifdef ADDRUNTIMESTATS
#include "AddRuntimeStats.h"
#include "RunTimeStats.h"
#endif
/* Declare the TCB of the Safety App task. */

configKERNEL_DATA_DEF static xTCB xAppSafetyTaskTCB = { 0 };
configKERNEL_DATA_DEF static xTCB xBswSafetyTaskTCB = { 0 };

static portInt8Type AppSafetyTaskStack[ TASK_STACKSIZE_SAFETY_APP_50msec ]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ( ( aligned ( TASK_STACKSIZE_SAFETY_APP_50msec ) ) )
#endif
;
static portInt8Type BswSafetyTaskStack[ TASK_STACKSIZE_SAFETY_BSW_10msec ]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ( ( aligned ( TASK_STACKSIZE_SAFETY_BSW_10msec ) ) )
#endif
;

#ifdef DEBUG_SAFETY_TASKS
    static uint32_t Debug_Safety_Tasks_RunCount[en_Task_SAFETY_MAX]={0};
    static uint32_t Debug_tickirq_ct[en_Task_SAFETY_MAX]={0};
    static uint32_t Debug_Safety_Tasks_ErrCount[en_Task_SAFETY_MAX]={0};
#endif

extern void Wdg_Trigger(void);
static bool appsafetytasks_init = FALSE;
static bool bswsafetytasks_init = FALSE;
ASILB_DATA_SECTION static SemaphoreP_Handle sem_app_safety_50ms;
ASILB_DATA_SECTION static SemaphoreP_Handle sem_bsw_safety_10ms;


/* Function declarations */
static void Task_APP_Safety_50msec( void *pvParameters );
static void Task_BSW_Safety_10msec( void *pvParameters );

void init_sem_safetysw(void)
{
  /* DD-ID: {9FBF93D3-D9D9-4ba3-9793-DC08CBF0CF10}*/
    sem_app_safety_50ms = SemaphoreP_create(0, NULL);
	sem_bsw_safety_10ms = SemaphoreP_create(0, NULL);
}

void safetysw_tick_5ms(void)
{
  /* DD-ID: {8676699F-CC64-4836-ACD6-649BF3C665F5}*/
    static uint8_t Count;
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if (Count % 10 == 0)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        if (appsafetytasks_init != FALSE)
        {
            SemaphoreP_post(sem_app_safety_50ms);

#ifdef DEBUG_SAFETY_TASKS

            if (Debug_tickirq_ct[en_Task_SAFETY_APP_50msec] != Debug_Safety_Tasks_RunCount[en_Task_SAFETY_APP_50msec])
       {
                Debug_Safety_Tasks_ErrCount[en_Task_SAFETY_APP_50msec]++;
           /* reset the error */
                Debug_tickirq_ct[en_Task_SAFETY_APP_50msec] = Debug_Safety_Tasks_RunCount[en_Task_SAFETY_APP_50msec];
       }
            Debug_tickirq_ct[en_Task_SAFETY_APP_50msec]++;
#endif
        }
    }
    if (Count % 2 == 0)
    {
        if (bswsafetytasks_init != FALSE)
        {
            SemaphoreP_post(sem_bsw_safety_10ms);
#ifdef DEBUG_SAFETY_TASKS
       if (Debug_tickirq_ct[en_TasK_SAFETY_BSW_10msec] != Debug_Safety_Tasks_RunCount[en_TasK_SAFETY_BSW_10msec])
       {
           Debug_Safety_Tasks_ErrCount[en_TasK_SAFETY_BSW_10msec]++;
           /* reset the error */
           Debug_tickirq_ct[en_TasK_SAFETY_BSW_10msec] = Debug_Safety_Tasks_RunCount[en_TasK_SAFETY_BSW_10msec];
       }
       Debug_tickirq_ct[en_TasK_SAFETY_BSW_10msec]++;
#endif
        }
    }
    Count++;
}

bool_t Tasks_Launch_AppSafetyTasks(void)
{
  /* DD-ID: {83F15FB1-AAEB-43af-8FAE-D203CF3FB5EF}*/
	bool bRet = FALSE;
    portBaseType xCreateResult;
  
    /* The structure passed to xTaskCreate() to create the App Safety task. */
    static const xTaskParameters xAppSafetyTaskParams =
    {
        &Task_APP_Safety_50msec,                  /* The function that implements the task being created. */
        "Application Safety 50msec Task",                   /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xAppSafetyTaskTCB,                 /* TCB for the task. */
        AppSafetyTaskStack,               /* The buffer allocated for use as the task stack. */
        TASK_STACKSIZE_SAFETY_APP_50msec,  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_SAFETY_APP_50msec,    /* The priority to assigned to the task being created. */
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
                { NULL, 0U, 0U, 0U },
            }                                                           
        }
    };


    /* Create the tasks. */
    xCreateResult = xTaskCreate( &xAppSafetyTaskParams, /* The structure containing the task parameters created at the start of this function. */
                                 NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */
	
    if( pdPASS == xCreateResult )
    {
		appsafetytasks_init = TRUE; /* App Safety tasks initialized */
		bRet = TRUE;
	}
	else
	{		    	
	}
    #ifdef ADDRUNTIMESTATS
   	TaskStackData[s_Task_SAFETY_APP_50msec].Task_LowAdd = (uint32)xAppSafetyTaskParams.pcStackBuffer;
    TaskStackData[s_Task_SAFETY_APP_50msec].Task_Size = xAppSafetyTaskParams.uxStackDepthBytes;
    if (TaskStackData[s_Task_SAFETY_APP_50msec].Task_LowAdd <= (UINT32_MAX - TaskStackData[s_Task_SAFETY_APP_50msec].Task_Size)) 
    {
        TaskStackData[s_Task_SAFETY_APP_50msec].Task_HighAdd = TaskStackData[s_Task_SAFETY_APP_50msec].Task_LowAdd + TaskStackData[s_Task_SAFETY_APP_50msec].Task_Size;
    }
    else
    {
        TaskStackData[s_Task_SAFETY_APP_50msec].Task_HighAdd = UINT32_MAX;
    }
    #endif
	return bRet; 
}


bool_t Tasks_Launch_BSWSafetyTasks(void)
{
  /* DD-ID: {7D6F1DB6-29E5-412e-897E-4D403A39C018}*/
	bool bRet = FALSE;
    portBaseType xCreateResult;

    /* The structure passed to xTaskCreate() to create the App Safety task. */
    static const xTaskParameters xBSWSafetyTaskParams =
    {
        &Task_BSW_Safety_10msec,                  /* The function that implements the task being created. */
        "Application Safety 10msec Task",                   /* The name of the task being created. The kernel does not use this itself, its just to assist debugging. */
        &xBswSafetyTaskTCB,                 /* TCB for the task. */
        BswSafetyTaskStack,               /* The buffer allocated for use as the task stack. */
        TASK_STACKSIZE_SAFETY_BSW_10msec,  /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        NULL,                           /* The task parameter, not used in this case. */
        TASK_PRIORITY_SAFETY_BSW_10msec,    /* The priority to assigned to the task being created. */
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
                { NULL, 0U, 0U, 0U },
            }                                                           
        }
    };

    xCreateResult = xTaskCreate( &xBSWSafetyTaskParams, /* The structure containing the task parameters created at the start of this function. */
                             NULL );            /* This parameter can be used to receive a handle to the created task, but is not used in this case. */

    if( pdPASS == xCreateResult )
    {
		bswsafetytasks_init = TRUE; /* BSW Safety tasks initialized */
		bRet = TRUE;
	}
	else
	{
	
	}
    #ifdef ADDRUNTIMESTATS
	TaskStackData[s_TasK_SAFETY_BSW_10msec].Task_LowAdd = (uint32)xBSWSafetyTaskParams.pcStackBuffer;
    TaskStackData[s_TasK_SAFETY_BSW_10msec].Task_Size = xBSWSafetyTaskParams.uxStackDepthBytes;
    if (TaskStackData[s_TasK_SAFETY_BSW_10msec].Task_LowAdd <= (UINT32_MAX - TaskStackData[s_TasK_SAFETY_BSW_10msec].Task_Size)) 
    {
        TaskStackData[s_TasK_SAFETY_BSW_10msec].Task_HighAdd = TaskStackData[s_TasK_SAFETY_BSW_10msec].Task_LowAdd + TaskStackData[s_TasK_SAFETY_BSW_10msec].Task_Size;
    }
    else
    {
        TaskStackData[s_TasK_SAFETY_BSW_10msec].Task_HighAdd = UINT32_MAX;
    }
    #endif
	return bRet; 
}

//ASILB_CODE_SECTION static void Task_APP_Safety_10msec( void *pvParameters )
static void Task_APP_Safety_50msec( void *pvParameters )
{
  /* DD-ID: {5EE2E07C-66C0-43c3-9662-AB3694DC32BF}*/
    static uint8_t v_WdgmCpCallCnt_u8 = 0;
    while (1)
	{
		SemaphoreP_pend(sem_app_safety_50ms, SemaphoreP_WAIT_FOREVER);

        #ifdef ADDRUNTIMESTATS        
        RunTimeStats_AppSafety_Start_Task(en_Task_SAFETY_APP_50msec);
		#endif
		#ifdef DEBUG_SAFETY_TASKS
            Debug_Safety_Tasks_RunCount[en_Task_SAFETY_APP_50msec]+=1;
        #endif
#if 0

        if(++v_WdgmCpCallCnt_u8 == 4)   /* Checkpoint need to mark at every 200ms */
        {
            v_WdgmCpCallCnt_u8 = 0;
            WdgM_F_CheckpointReached_v(e_WdgmCpid_TaskSafetyApp200msec);
        }
#endif

		#ifdef ADDRUNTIMESTATS
        RunTimeStats_AppSafety_Stop_Task(en_Task_SAFETY_APP_50msec);
		#endif
	}

}


static void Task_BSW_Safety_10msec( void *pvParameters )
{
  /* DD-ID: {F90E1167-0037-4a3f-9C60-40A5CA43B51E}*/
    while (1)
	{
		SemaphoreP_pend(sem_bsw_safety_10ms, SemaphoreP_WAIT_FOREVER);
        #ifdef ADDRUNTIMESTATS        
        RunTimeStats_BswSafety_Start_Task(en_TasK_SAFETY_BSW_10msec);
		#endif
		#ifdef DEBUG_SAFETY_TASKS
            Debug_Safety_Tasks_RunCount[en_TasK_SAFETY_BSW_10msec]+=1;
        #endif
#if 1
        /* Mark checkpoint progress */
        #if !defined(VCAST)
        WdgM_F_CheckpointReached_v(e_WdgmCpid_TaskSafetyBsw10msec);
        #endif
        /* WDGM scheduled function */
        WdgM_F_MainFunction_v();

        /* WDG scheduled function */ 
        Wdg_Trigger();
#endif
#ifdef TIME_MANAGER_PROXY
        TimeManagerProxy_MainFunction();
#endif        
#if 0        
        SigMgr_PeriodicFunc_B();
#endif        
        //Error manager : Collect the error
        ErrorMgrSatellite_PeriodicFunction_B();
        Safety_MainFunction();

        #ifdef ADDRUNTIMESTATS        
        RunTimeStats_BswSafety_Stop_Task(en_TasK_SAFETY_BSW_10msec);
		#endif
	}

}
