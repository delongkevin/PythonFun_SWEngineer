#ifndef TASKDEFS_CFG_NAME_INCLUDEGUARD
#define TASKDEFS_CFG_NAME_INCLUDEGUARD


/* Debug Flags */
#define DEBUG_BSW_TASKS
#define DEBUG_APP_TASKS
//#define TASK_BSW_ADD_DEBUG_STARTUPDELAY
//#define TASK_APP_ADD_DEBUG_STARTUPDELAY
//#define ERRORMGR_TEST_MCU2_1
#define ENABLE_TASK_USS

#define TASK_ALIGNMENT                  (2048U)

#define MCU2_1_ASILB_DATA_BASE_ADDR                           (( void * )0xB6800000U)
#define MCU2_1_ASILB_DATA_LEN                                            0x400000U

/* Task Priorities */
#define TASK_PRIORITY_SAFETY_APP_50msec            (2U)
#define TASK_PRIORITY_SAFETY_BSW_10msec            (9U)

#define TASK_PRIORITY_BSW_QM_Idle                  (1U)
#define TASK_PRIORITY_BSW_QM_UssCfg                (5U)
#define TASK_PRIORITY_BSW_QM_10msec                (6U)
#define TASK_PRIORITY_BSW_QM1_10msec               (5U)
#define TASK_PRIORITY_BSW_B_10msec                 (6U)
#ifdef AUTO_PARK_EN
#define TASK_PRIORITY_Auto_Park_10msec             (5U)
#endif
#ifdef ENABLE_OBJECT_FUSION
#define TASK_PRIORITY_objectfusion_10msec          (5U)
#endif


#define TASK_PRIORITY_BSW_QM_1msec                  (10U)
#define TASK_PRIORITY_BSW_QM_HighPriority_Ev        (14U)

#define TASK_PRIORITY_APP_QM_10msec                 (2U)
#define TASK_PRIORITY_APP_B_10msec                  (3U)



/* Stack Sizes */
/* These stack sizes needs to be dtermined statically from a callgraph. 
But currently Gcc cannot find an option to generate callgraph */
#define TASK_STACKSIZE_BSW_QM_1msec                     (2048U)
#define TASK_STACKSIZE_BSW_QM_Idle                      (2048U)
#define TASK_STACKSIZE_BSW_QM_UssCfg                    (2048U)
#define TASK_STACKSIZE_BSW_QM_10msec                    (2048U)
#define TASK_STACKSIZE_BSW_QM1_10msec                   (8192U)  
#define TASK_STACKSIZE_BSW_B_10msec                     (8192U)
#define TASK_STACKSIZE_BSW_QM_HighPriority_Ev           (8192U)
#ifdef AUTO_PARK_EN
#define TASK_STACKSIZE_Auto_Park_10msec                 (8192U)
#endif
#ifdef ENABLE_OBJECT_FUSION
#define TASK_STACKSIZE_objectfusion_10msec              (8192U)
#endif

#define TASK_STACKSIZE_APP_QM_10msec                    (2048U)
#define TASK_STACKSIZE_APP_B_10msec                     (65536U)


#define TASK_STACKSIZE_SAFETY_APP_50msec                (32768U)
#define TASK_STACKSIZE_SAFETY_BSW_10msec                (2048U)
#define TASK_STACKSIZE_Startup                          (8192U)

//#define USS_FEATURE_DISABLED

#define TASK_WAITING_METHOD_TIMERSEMAPHORE   2
#define TASK_WAITING_METHOD_TASKSLEEP   1
//Todo::Temporatily putting to task sleep as there is some issue with Timer
#define TASK_WAITING_METHOD TASK_WAITING_METHOD_TIMERSEMAPHORE


#endif
