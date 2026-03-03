
#include <ti/osal/osal.h>

//#include "main_domain_utils.h"
//#include "mcu_timer_read_multicore.h"

/* Base Magna Software Includes */
#include "SignalMgr.h"
#include "ErrorManagerSatellite.h"
#include "SSM_Slave.h"
#include "ipc_manager.h"
#include "VoltageCurrent_data.h"
#include "SignalDef.h"

#include "BaseSwTasks.h"
#include "ApplicationTasks.h"
#include "diagnostics.h"
#include "safety.h"
#include "WdgM.h"
#include "Wdg.h"
#if defined(VCAST)
#include "WdgGlobal.h"
#endif
#include <app.h>
#include <utils/console_io/include/app_log.h>
#include <utils/iss/include/app_iss.h>
#include "Safety_CDD.h"
#include "vim_mainR5.h"

#if defined ERRORMGR_TEST_MCU2_0
#include "ErrorManagerSatelliteDef.h"
#endif

//cpu load utilisation
#include "cpu_load.h"
// AddRuntimeStats
#include "AddRuntimeStats.h"
#include "RunTimeStats.h"

extern void SigMgr_Data_USS_PowerSelect_t_Get(USS_PowerSelect_t *data);
extern bool_t SigMgr_Data1_USS_PowerSelect_t_Put(USS_PowerSelect_t *data);
extern bool_t SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Put(WdgCheckpointStatus_t *data);
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

#ifdef DEBUG_IPC
void IPC_f_SenderFxn_v(void);
#endif

#if defined ERRORMGR_TEST_MCU2_0
static uint8_t TestFault(ldef_ErrorMgr_enErrorNo errorNumber_e);
static void TestErrorManager(void);
#endif

void Task_BSW_B_10msec(void* arg0, void* arg1);
void Task_BSW_QM_10msec(void* arg0, void* arg1);
void Task_BSW_QM1_10msec(void* arg0, void* arg1);
void Task_BSW_QM_BSW_QM_HighPriority_Ev(void* arg0, void* arg1);
void Task_BSW_QM_TI_100msec(void* arg0, void* arg1);


#ifdef DEBUG_BSW_TASKS
    static uint32_t Debug_BSW_Tasks_RunCount[en_Task_BSW_MAX]={0};
    static uint32_t Debug_tickirq_ct[en_Task_BSW_MAX]={0};
    static uint32_t Debug_BSW_Tasks_ErrCount[en_Task_BSW_MAX]={0};
#endif


EventP_Handle TaskEventHandle_BSW_QM_Events_Ev;
static TaskP_Params TaskParams_BSW_QM_HighPriority_Ev;
static TaskP_Handle TaskHandle_BSW_QM_HighPriority_Ev;
static uint8_t TaskStack_BSW_QM_HighPriority_Ev[TASK_STACKSIZE_BSW_QM_HighPriority_Ev]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_ALIGNMENT)))
#endif
;



static TaskP_Params TaskParams_BSW_QM_10msec;
static TaskP_Handle TaskHandle_BSW_QM_10msec;
static uint8_t TaskStack_BSW_QM_10msec[TASK_STACKSIZE_BSW_QM_10msec]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_ALIGNMENT)))
#endif
;

static TaskP_Params TaskParams_BSW_QM1_10msec;
static TaskP_Handle TaskHandle_BSW_QM1_10msec;
static uint8_t TaskStack_BSW_QM1_10msec[TASK_STACKSIZE_BSW_QM1_10msec]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_ALIGNMENT)))
#endif
;

static TaskP_Params TaskParams_BSW_QM_TI_100msec;
static TaskP_Handle TaskHandle_BSW_QM_TI_100msec;
static uint8_t TaskStack_BSW_QM_TI_100msec[TASK_STACKSIZE_BSW_QM_TI_100msec]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_ALIGNMENT)))
#endif
;

static TaskP_Params TaskParams_BSW_B_10msec;
static TaskP_Handle TaskHandle_BSW_B_10msec;
static uint8_t TaskStack_BSW_B_10msec[TASK_STACKSIZE_BSW_B_10msec]
#if !defined(VCAST)
__attribute__ ((section(".bss:taskStackSection")))
__attribute__ ((aligned(TASK_ALIGNMENT)))
#endif
;

static SemaphoreP_Handle sem_bsw_qm_10ms;
static SemaphoreP_Handle sem_bsw_qm1_10ms;
static SemaphoreP_Handle sem_bsw_b_10ms;

#define TOTAL_NO_OF_CAMERAS 	4u


#ifdef TASK_BSW_ADD_DEBUG_STARTUPDELAY
volatile uint32_t Task_Debug_BSW_DelayCount=0;
#endif
void Tasks_BSW_AddDebugStartDelay(void)
{
  /* DD-ID: {BA914136-7D38-4760-BD62-39CA182F777B}*/
    #ifdef TASK_BSW_ADD_DEBUG_STARTUPDELAY

    while(Task_Debug_BSW_DelayCount++ < 0x7FFFFFFF);
    #endif
}

void init_sem_basesw(void)
{
  /* DD-ID: {A4897902-AB96-4238-BD1D-9F8BA6FD4D35}*/
    sem_bsw_b_10ms = SemaphoreP_create(0, NULL);
    sem_bsw_qm_10ms = SemaphoreP_create(0, NULL);
    sem_bsw_qm1_10ms = SemaphoreP_create(0, NULL);
}

volatile int basesw_tick_5ms_Count =0;
void basesw_tick_5ms(void)
{
  /* DD-ID: {56670A8A-9EE9-4e1c-8949-4DC029651980}*/
    static uint8_t Count;
    basesw_tick_5ms_Count+=1;
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if (Count % 2 == 0)
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        SemaphoreP_post(sem_bsw_b_10ms);
        SemaphoreP_post(sem_bsw_qm_10ms);
        SemaphoreP_post(sem_bsw_qm1_10ms);

#ifdef DEBUG_BSW_TASKS

       if (Debug_tickirq_ct[en_TasK_BSW_QM_10msec] != Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM_10msec])
       {
           Debug_BSW_Tasks_ErrCount[en_TasK_BSW_QM_10msec]++;
           /* reset the error */
           Debug_tickirq_ct[en_TasK_BSW_QM_10msec] = Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM_10msec];
       }
       Debug_tickirq_ct[en_TasK_BSW_QM_10msec]++;
       if (Debug_tickirq_ct[en_TasK_BSW_QM1_10msec] != Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM1_10msec])
       {
           Debug_BSW_Tasks_ErrCount[en_TasK_BSW_QM1_10msec]++;
           /* reset the error */
           Debug_tickirq_ct[en_TasK_BSW_QM1_10msec] = Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM1_10msec];
       }
       Debug_tickirq_ct[en_TasK_BSW_QM1_10msec]++;
       if (Debug_tickirq_ct[en_Task_BSW_B_10msec] != Debug_BSW_Tasks_RunCount[en_Task_BSW_B_10msec])
       {
           Debug_BSW_Tasks_ErrCount[en_Task_BSW_B_10msec]++;
           /* reset the error */
           Debug_tickirq_ct[en_Task_BSW_B_10msec] = Debug_BSW_Tasks_RunCount[en_Task_BSW_B_10msec];
       }
       Debug_tickirq_ct[en_Task_BSW_B_10msec]++;
#endif
    }
    Count++;
}

volatile bool_t bDebug_Tasks_Launch_BaseTasks_PostAppInit=0;
bool_t Tasks_Launch_BaseTasks_PostAppInit(void)
{
  /* DD-ID:{5FCDF526-1290-4711-96AE-8C0750C5BF87}*/
    bool bRet=TRUE;
    uint32_t errorStatus_e = D_IPC_NO_ERROR;

    EventP_Params   eventParams;
    EventP_Status   status;

    //while(bDebug_Tasks_Launch_BaseTasks_PostAppInit == 0);

    //Initalize Base SW Items

    errorStatus_e = IPC_F_ManagerInit_u32();
    if(errorStatus_e != D_IPC_NO_ERROR)
    {
        bRet=FALSE;
    }

    //appInit();

    //SSM Init
    SSM_Slave_Init();
    //Signal Manager
    SignalMgr_Init();
    //Error Manager
    ErrorMgrSatellite_Init_QM();
    ErrorMgrSatellite_Init_B();
    SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_ErrorMgr,SSM_APPSTATE_INIT_i);

    //Set the SSM State to BSP init Done
    SSM_Slave_RequestState(SSM_SlaveCore_State_BSP_Init_Done_i);

    /* TO DO:[Pradeep.I.V.] Temporarily enabling USS Power at startup */
    appSetI2cExpPinDir(1, 4u, 1u, 0u/*GPIO_PIN_LOW*/); // USS_PWR_EN_A IO2_04
    appSetI2cExpPinDir(1, 5u, 1u, 0u/*GPIO_PIN_LOW*/); // USS_PWR_EN_B IO2_05

    appSetI2cExpPinDir(0, 12u, 0u, 1u/* Ignored for Input Pins */); // CAM_FAULT_A IO1_14
    appSetI2cExpPinDir(0, 14u, 1u, 0u/*GPIO_PIN_LOW*/); // CAM_SEH IO2_16
    appSetI2cExpPinDir(0, 15u, 1u, 0u/*GPIO_PIN_LOW*/); // CAM_SEL IO2_17

    SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_USS_Pwr, SSM_APPSTATE_INIT_i);

    //Launch the tasks

    //BSW Asil B Task
    EventP_Params_init(&eventParams);
    TaskEventHandle_BSW_QM_Events_Ev = EventP_create(&eventParams);

    TaskP_Params_init(&TaskParams_BSW_QM_HighPriority_Ev);
    TaskParams_BSW_QM_HighPriority_Ev.name="Task_BSW_QM_HighPriority_Ev";
    TaskParams_BSW_QM_HighPriority_Ev.arg0 = (void*) NULL;
    TaskParams_BSW_QM_HighPriority_Ev.arg1 = (void*) NULL;
    TaskParams_BSW_QM_HighPriority_Ev.priority = TASK_PRIORITY_BSW_QM_HighPriority_Ev;
    TaskParams_BSW_QM_HighPriority_Ev.stack = TaskStack_BSW_QM_HighPriority_Ev;
    TaskParams_BSW_QM_HighPriority_Ev.stacksize = sizeof (TaskStack_BSW_QM_HighPriority_Ev);

    TaskHandle_BSW_QM_HighPriority_Ev = TaskP_create(Task_BSW_QM_BSW_QM_HighPriority_Ev, &TaskParams_BSW_QM_HighPriority_Ev);

    //QM Tasks
    TaskP_Params_init(&TaskParams_BSW_QM_10msec);
    TaskParams_BSW_QM_10msec.name="Task_BSW_QM_10msec";
    TaskParams_BSW_QM_10msec.arg0 = (void*) NULL;
    TaskParams_BSW_QM_10msec.arg1 = (void*) NULL;
    TaskParams_BSW_QM_10msec.priority = TASK_PRIORITY_BSW_QM_10msec;
    TaskParams_BSW_QM_10msec.stack = TaskStack_BSW_QM_10msec;
    TaskParams_BSW_QM_10msec.stacksize = sizeof (TaskStack_BSW_QM_10msec);

    TaskHandle_BSW_QM_10msec = TaskP_create(Task_BSW_QM_10msec, &TaskParams_BSW_QM_10msec);

    TaskP_Params_init(&TaskParams_BSW_QM1_10msec);
    TaskParams_BSW_QM1_10msec.name="Task_BSW_QM1_10msec";
    TaskParams_BSW_QM1_10msec.arg0 = (void*) NULL;
    TaskParams_BSW_QM1_10msec.arg1 = (void*) NULL;
    TaskParams_BSW_QM1_10msec.priority = TASK_PRIORITY_BSW_QM1_10msec;
    TaskParams_BSW_QM1_10msec.stack = TaskStack_BSW_QM1_10msec;
    TaskParams_BSW_QM1_10msec.stacksize = sizeof (TaskStack_BSW_QM1_10msec);

    TaskHandle_BSW_QM1_10msec = TaskP_create(Task_BSW_QM1_10msec, &TaskParams_BSW_QM1_10msec);

    //BSW Asil B Task
    TaskP_Params_init(&TaskParams_BSW_B_10msec);
    TaskParams_BSW_B_10msec.name="Task_BSW_B_10msec";
    TaskParams_BSW_B_10msec.arg0 = (void*) NULL;
    TaskParams_BSW_B_10msec.arg1 = (void*) NULL;
    TaskParams_BSW_B_10msec.priority = TASK_PRIORITY_BSW_B_10msec;
    TaskParams_BSW_B_10msec.stack = TaskStack_BSW_B_10msec;
    TaskParams_BSW_B_10msec.stacksize = sizeof (TaskStack_BSW_B_10msec);

    TaskHandle_BSW_B_10msec = TaskP_create(Task_BSW_B_10msec, &TaskParams_BSW_B_10msec);
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    if((NULL == TaskHandle_BSW_QM_10msec)  || (NULL == TaskHandle_BSW_B_10msec) || (TaskHandle_BSW_QM_HighPriority_Ev == NULL))
    /* VCAST Jenkins requirement - do not modify */
    /* VCAST Jenkins requirement - do not modify */
    {
        bRet=FALSE;
    }

    /* Initialize WDGM and WDG */
    //WdgM_F_Init_v();
    //Wdg_Init();
    #ifdef ADDRUNTIMESTATS
    TaskStackData[s_Task_BSW_B_10msec].Task_LowAdd = (uint32)TaskParams_BSW_B_10msec.stack;
    TaskStackData[s_Task_BSW_B_10msec].Task_Size = TaskParams_BSW_B_10msec.stacksize;
    TaskStackData[s_Task_BSW_B_10msec].Task_HighAdd = TaskStackData[s_Task_BSW_B_10msec].Task_LowAdd  + TaskStackData[s_Task_BSW_B_10msec].Task_Size;

    TaskStackData[s_TasK_BSW_QM_10msec].Task_LowAdd = (uint32)TaskParams_BSW_QM_10msec.stack;
    TaskStackData[s_TasK_BSW_QM_10msec].Task_Size = TaskParams_BSW_QM_10msec.stacksize;
    TaskStackData[s_TasK_BSW_QM_10msec].Task_HighAdd = TaskStackData[s_TasK_BSW_QM_10msec].Task_LowAdd  + TaskStackData[s_TasK_BSW_QM_10msec].Task_Size;

    TaskStackData[s_TasK_BSW_QM1_10msec].Task_LowAdd = (uint32)TaskParams_BSW_QM1_10msec.stack;
    TaskStackData[s_TasK_BSW_QM1_10msec].Task_Size = TaskParams_BSW_QM1_10msec.stacksize;
    TaskStackData[s_TasK_BSW_QM1_10msec].Task_HighAdd = TaskStackData[s_TasK_BSW_QM1_10msec].Task_LowAdd  + TaskStackData[s_TasK_BSW_QM1_10msec].Task_Size;

    TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_LowAdd = (uint32)TaskParams_BSW_QM_HighPriority_Ev.stack;
    TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_Size = TaskParams_BSW_QM_HighPriority_Ev.stacksize;
    TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_HighAdd = TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_LowAdd  + TaskStackData[s_Task_en_TasK_BSW_QM_HighPriority_OnEvent].Task_Size;
    #endif
    return bRet;

}
bool_t Tasks_Launch_BaseTasks(void)
{
  /* DD-ID:{D8170BF2-59E3-46f6-9FE2-A84BD320D068}*/
  /* DD-ID :{C1771B95-6A53-4ec4-B2A0-EB6A9BE0DBFE}*/
    bool bRet=TRUE;
    //errorStatus_t errorStatus_e = NO_ERROR;

    Tasks_BSW_AddDebugStartDelay();



    TaskP_Params_init(&TaskParams_BSW_QM_TI_100msec);
    TaskParams_BSW_QM_TI_100msec.name="Task_BSW_QM_TI_100msec";
    TaskParams_BSW_QM_TI_100msec.arg0 = (void*) NULL;
    TaskParams_BSW_QM_TI_100msec.arg1 = (void*) NULL;
    TaskParams_BSW_QM_TI_100msec.priority = TASK_PRIORITY_BSW_QM_TI_100msec;
    TaskParams_BSW_QM_TI_100msec.stack = TaskStack_BSW_QM_TI_100msec;
    TaskParams_BSW_QM_TI_100msec.stacksize = sizeof (TaskStack_BSW_QM_TI_100msec);

    TaskHandle_BSW_QM_TI_100msec = TaskP_create(Task_BSW_QM_TI_100msec, &TaskParams_BSW_QM_TI_100msec);



    if((NULL == TaskHandle_BSW_QM_TI_100msec))
    {
        bRet=FALSE;
    }
    #ifdef ADDRUNTIMESTATS
    TaskStackData[s_TasK_BSW_QM_TI_100msec].Task_LowAdd = (uint32)TaskParams_BSW_QM_TI_100msec.stack;
    TaskStackData[s_TasK_BSW_QM_TI_100msec].Task_Size = TaskParams_BSW_QM_TI_100msec.stacksize;
    TaskStackData[s_TasK_BSW_QM_TI_100msec].Task_HighAdd = TaskStackData[s_TasK_BSW_QM_TI_100msec].Task_LowAdd  + TaskStackData[s_TasK_BSW_QM_TI_100msec].Task_Size;
    #endif
    return bRet;

}


void Task_BSW_QM_BSW_QM_HighPriority_Ev(void* arg0, void* arg1)
{
  /* DD-ID: {0AE6DF6B-534A-40d2-A584-BB9033C3B4DF}*/
    //uint32_t events;
    while(TRUE)
    {       
            #ifdef ADDRUNTIMESTATS
            RunTimeStats_BSW_Start_Task(en_Task_en_TasK_BSW_QM_HighPriority_OnEvent);
            #endif
            #ifdef DEBUG_BSW_TASKS
                Debug_BSW_Tasks_RunCount[en_Task_en_TasK_BSW_QM_HighPriority_OnEvent]+=1;
            #endif
            //events = Event_pend(TaskEventHandle_BSW_QM_Events_Ev, Event_Id_NONE, Event_Id_00 + Event_Id_01, osal_WAIT_FOREVER);

            TaskP_sleep(10);
            #ifdef ADDRUNTIMESTATS
            RunTimeStats_BSW_Stop_Task(en_Task_en_TasK_BSW_QM_HighPriority_OnEvent);
            #endif
    }
}

//volatile int debug_Task_BSW_QM_TI_100msec=0;
void Task_BSW_QM_TI_100msec(void* arg0, void* arg1)
{
  /* DD-ID: {4B061F5F-0011-43b8-A1CE-1D2FD6FE6C22}*/
    //uint32_t events;
    //while(debug_Task_BSW_QM_TI_100msec == 0);
    appInit();

    Tasks_Launch_BaseTasks_PostAppInit();
     appRun();
    while(TRUE)
    {
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Start_Task(en_TasK_BSW_QM_TI_100msec);
        #endif
            #ifdef DEBUG_BSW_TASKS
                Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM_TI_100msec]+=1;
            #endif
            TaskP_sleep(10);
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Stop_Task(en_TasK_BSW_QM_TI_100msec);
        #endif 
    }
}

#if defined ERRORMGR_TEST_MCU2_0
uint8_t AsilFltLvl2Tst_u8=0x0u;
#endif
void Task_BSW_QM_10msec(void* arg0, void* arg1)
{
  /* DD-ID: {BA3538F9-4B1C-45ba-A2EA-AF80D72774DB}*/
    uint16 Count=0;
 
    while(TRUE)
    {
        (void)SemaphoreP_pend(sem_bsw_qm_10ms, SemaphoreP_WAIT_FOREVER);
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Start_Task(en_TasK_BSW_QM_10msec);
        #endif
        #ifdef DEBUG_BSW_TASKS
            Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM_10msec]+=1;
        #endif

        //Errror manager : Collect the error
        #if defined ERRORMGR_TEST_MCU2_0
        TestErrorManager();
        #endif
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Start_Function(AddRuntimeStats_ErrorMgrSatellite_RUN);
        #endif
        ErrorMgrSatellite_PeriodicFunction_QM();
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_ErrorMgrSatellite_RUN);
        //Run IPC Manager
        AdditionalRuntimeStats_Start_Function(AddRuntimeStats_IPC_F_IpcManager_RUN);
        #endif
        IPC_F_IpcManager_v();
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_IPC_F_IpcManager_RUN);
        #endif
#ifdef DEBUG_IPC
        //Runs every 5 sec
        Count = Count + 1u;
        if(Count%5000 == 0u)
        {
            IPC_f_SenderFxn_v();
            Count = 0u;
        }
#endif
        SSM_Slave_MainTask();
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Stop_Task(en_TasK_BSW_QM_10msec);
        #endif
    }

}

void Task_BSW_QM1_10msec(void* arg0, void* arg1)
{
  /* DD-ID: {3D2D83A5-BA83-4d87-93E7-6A8C26A55338}*/
    USS_PowerSelect_t USS_PowerControl, USS_PowerControl_Prev;
    uint16 Count=0;
    uint8 USS_PWR_Status_A = 0;
    uint8 USS_PWR_Status_B = 0;
    while(TRUE)
    {
        (void)SemaphoreP_pend(sem_bsw_qm1_10ms, SemaphoreP_WAIT_FOREVER);
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Start_Task(en_TasK_BSW_QM1_10msec);
        #endif
        #ifdef DEBUG_BSW_TASKS
            Debug_BSW_Tasks_RunCount[en_TasK_BSW_QM1_10msec]+=1;
        #endif

        if(Count % 20 == 0)
        {
           /* Every 200ms */
            Safety_CSIrx_Run_200ms();
        }
        if(Count % 10 == 0)
        {
            Safety_Recovery_Run_100ms();
           /* Every 100ms monitor rate per DTCCM */
            #ifdef ADDRUNTIMESTATS
            AdditionalRuntimeStats_Start_Function(AddRuntimeStats_Diagnostics_RUN);
            #endif
            Diagnostics_Run();
            #ifdef ADDRUNTIMESTATS   
            AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_Diagnostics_RUN);
            #endif        
        }
#ifdef FREERTOS        
        //CPU_Utilization             
        if (Count % 500 == 0)
        {     
            /* Every 5s Prints CPU Load */
            #ifdef ADDRUNTIMESTATS
            AdditionalRuntimeStats_Start_Function(AddRuntimeStats_cpu_load_MCU2_0_RUN);
            #endif
            cpu_load_MCU2_0();
            #ifdef ADDRUNTIMESTATS
            AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_cpu_load_MCU2_0_RUN);
            #endif
        }      
#endif        
        Count++;

        (void)SigMgr_Data_USS_PowerSelect_t_Get(&USS_PowerControl);
        if(USS_PowerControl_Prev.USS_PWR_EN_A != USS_PowerControl.USS_PWR_EN_A)
        {
           USS_PowerControl_Prev.USS_PWR_EN_A = USS_PowerControl.USS_PWR_EN_A;

           if( TRUE == USS_PowerControl.USS_PWR_EN_A)
           {  
               appSetI2cExpPinVal(1, 4u, 1u/*GPIO_PIN_HIGH*/); /* USS_PWR_EN_A IO2_04 */
               USS_PowerControl.status_A = USS_PWR_ENABLED; /* USS Power is enabled */
               USS_PWR_Status_A = USS_PWR_ENABLED; /* USS Power is enabled */

               SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_USS_Pwr, SSM_APPSTATE_RUNNING_i);
           }
           else
           {
               appSetI2cExpPinVal(1, 4u, 0u/*GPIO_PIN_LOW*/); /* USS_PWR_EN_A IO2_04 */
               USS_PowerControl.status_A = USS_PWR_DISABLED; /* USS Power is disabled */
               USS_PWR_Status_A = USS_PWR_DISABLED; /* USS Power is disabled */
           }
           (void)SigMgr_Data1_USS_PowerSelect_t_Put(&USS_PowerControl);
        }
        else
        {
            ;
        }

        if(USS_PowerControl_Prev.USS_PWR_EN_B != USS_PowerControl.USS_PWR_EN_B)
        {
           USS_PowerControl_Prev.USS_PWR_EN_B = USS_PowerControl.USS_PWR_EN_B;

           if( TRUE == USS_PowerControl.USS_PWR_EN_B)
           {  
               appSetI2cExpPinVal(1, 5u, 1u/*GPIO_PIN_HIGH*/); /* USS_PWR_EN_B IO2_05 */
               USS_PowerControl.status_B = USS_PWR_ENABLED; /* USS Power is enabled */
               USS_PWR_Status_B = USS_PWR_ENABLED; /* USS Power is enabled */

               SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_USS_Pwr, SSM_APPSTATE_RUNNING_i);
           }
           else
           {
               appSetI2cExpPinVal(1, 5u, 0u/*GPIO_PIN_LOW*/); /* USS_PWR_EN_B IO2_05 */
               USS_PowerControl.status_B = USS_PWR_DISABLED; /* USS Power is disabled */
               USS_PWR_Status_B = USS_PWR_DISABLED; /* USS Power is disabled */
           }
           (void)SigMgr_Data1_USS_PowerSelect_t_Put(&USS_PowerControl);
        }
        else
        {
            ;
        }

        /* Resending USS power status, status is requested from MCU2_1 using 0xBBu */
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        if (USS_PowerControl.status_A == 0xBBu || USS_PowerControl.status_B == 0xBBu)
        /* VCAST Jenkins requirement - do not modify */
        /* VCAST Jenkins requirement - do not modify */
        {
            USS_PowerControl.status_A = USS_PWR_Status_A;
            USS_PowerControl.status_B = USS_PWR_Status_B;
            (void)SigMgr_Data1_USS_PowerSelect_t_Put(&USS_PowerControl);
        }
        else
        {
            /*Do nothing*/
        }
        


        /* Stop the USS power application, if both the USS power lines are disabled. */
        if((USS_PWR_DISABLED == USS_PowerControl.status_A) &&
           (USS_PWR_DISABLED == USS_PowerControl.status_B))
        {
        	SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_USS_Pwr, SSM_APPSTATE_STOPPED_i);
        }

        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Stop_Task(en_TasK_BSW_QM1_10msec);
        #endif
    }
}

void Task_BSW_B_10msec(void* arg0, void* arg1)
{
  /* DD-ID: {AEFED2C5-CDB2-490b-9D05-93A14EAC3FB8}*/
    SSM_SystemState_i SSMSystemState;
    static SSM_SystemStateDef_i previous_SystemState = SSM_STATE_MAX_i;
    uint32 cam_num;
    static WdgCheckpointStatus_t WdgCheckpointStatus_Data = {0};

    while(TRUE)
    {
        (void)SemaphoreP_pend(sem_bsw_b_10ms, SemaphoreP_WAIT_FOREVER);
        #ifdef ADDRUNTIMESTATS
        RunTimeStats_BSW_Start_Task(en_Task_BSW_B_10msec);
        #endif
        #ifdef DEBUG_BSW_TASKS
            Debug_BSW_Tasks_RunCount[en_Task_BSW_B_10msec]+=1;
        #endif

        Safety_MainFunction(); /* To be moved to Safety task after MPU Changes integration */

        //Error manager : Collect the error
        #ifdef ADDRUNTIMESTATS
        AdditionalRuntimeStats_Start_Function(AddRuntimeStats_ErrorMgrSatellite_b_RUN);
        #endif
        ErrorMgrSatellite_PeriodicFunction_B();
        #ifdef ADDRUNTIMESTATS
	    AdditionalRuntimeStats_Stop_Function(AddRuntimeStats_ErrorMgrSatellite_b_RUN);
        #endif
        /* Mark checkpoint progress */
        //WdgM_F_CheckpointReached_v(e_WdgmCpid_TaskBswB10msec);
        /* WDGM scheduled function */
        //WdgM_F_MainFunction_v();

        /* WDG scheduled function */ 
        //Wdg_Trigger();

        /* Wdg Alive Monitoring IPC data counter increment by 1 */
        WdgCheckpointStatus_Data.wdgDataLiveCntr_u32 += 1u;
        SigMgr_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t_Put(&WdgCheckpointStatus_Data);

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
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_ErrorMgr, SSM_APPSTATE_INIT_i);
                break;
                case SSM_STATE_IPCREADY_i:
                case SSM_STATE_RUNNING_i:
                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_ErrorMgr, SSM_APPSTATE_RUNNING_i);
                break;
                case SSM_STATE_DEGRADED_i:
                case SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP_i:
                case SSM_STATE_OFF_i:
                	/* Place holder to implement all software systematic shutdown activities here */

                	/* End of place holder */

                    SSM_Slave_SetApplicationStatus(SSM_MCU_2_0_Application_ErrorMgr, SSM_APPSTATE_STOPPED_i);
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
    (void)AddRuntimeStats_StackUsage();
    (void)RunTimeStatsData_SendData();
	RunTimeStats_BSW_Stop_Task(en_Task_BSW_B_10msec);
    #endif

    }
    
}

#ifdef DEBUG_IPC
#include "HMI_SVS.h"
extern bool_t SigMgr_data_ScreenRequest_t_Put(ScreenRequest_t *data); 
void IPC_f_SenderFxn_v()
{
  /* DD-ID: {47EE2AB6-09C9-4fa2-8D1B-201C25B90437}*/
#if 1
    ScreenRequest_t data;
    SigMgr_data_ScreenRequest_t_Put(&data);
    appLogPrintf("ScreenRequest sent... \n");
    appLogPrintf("ScreenRequest size:%d, ScreenResponse Size:%d \n", \
        sizeof(ScreenRequest_t), sizeof(ScreenResponse_t));
#else
    IPCMessage_Params_t ipcParams_s;
    ipcParams_s.IpcMsgID_u16 = 0x0003U;
    ipcParams_s.IpcMsgSize_u16 = 0x08U;
    uint8_t v_tx_msgData_u8[8] = {0xAAU, 0xBBU, 0xCCU, 0xDDU};
    ipcParams_s.IpcMsgData_v = &v_tx_msgData_u8[0];
    uint32_t status_e = D_IPC_NO_ERROR;

    status_e =  IPC_F_WrapperSend_u32(&ipcParams_s);

    if(D_IPC_NO_ERROR != status_e)
    {
        /* Set Error */
    }
#endif
}
#endif

#if defined ERRORMGR_TEST_MCU2_0
__attribute__((optnone)) static uint8_t TestFault(ldef_ErrorMgr_enErrorNo errorNumber_e)
{
  /* DD-ID: {923E0EA2-71F6-4bd2-B3CF-4160F0B2C68E}*/
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
  /* DD-ID: {77367181-033D-416f-96A1-FAA2EF0150E2}*/
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
