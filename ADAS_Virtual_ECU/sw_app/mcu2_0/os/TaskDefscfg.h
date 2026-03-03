#ifndef TASKDEFS_CFG_NAME_INCLUDEGUARD
#define TASKDEFS_CFG_NAME_INCLUDEGUARD


/* Debug Flags */
#define DEBUG_BSW_TASKS
#define DEBUG_APP_TASKS
//#define TASK_BSW_ADD_DEBUG_STARTUPDELAY
//#define TASK_APP_ADD_DEBUG_STARTUPDELAY
//#define ERRORMGR_TEST_MCU2_0

//#define DEBUG_IPC

#define TASK_ALIGNMENT                  (16384)

/* Task Priorities */
#define TASK_PRIORITY_BSW_QM_10msec                 (5U)
#define TASK_PRIORITY_BSW_QM1_10msec                (4U)
#define TASK_PRIORITY_BSW_QM_TI_100msec             (8) /* Do not change : The priority of this task should be 8 for the tweak tool to work */
#define TASK_PRIORITY_BSW_B_10msec                  (6U)
#define TASK_PRIORITY_BSW_QM_HighPriority_Ev        (14)
#define TASK_PRIORITY_APP_QM_10msec                 (4)
#define TASK_PRIORITY_APP_B_10msec                  (4)
#define TASK_PRIORITY_APP_B_30msec                  (6)

/* Stack Sizes */
/* These stack sizes needs to be dtermined statically from a callgraph. 
But currently Gcc cannot find an option to generate callgraph */
#define TASK_STACKSIZE_BSW_QM_10msec                    (2048)
#define TASK_STACKSIZE_BSW_QM1_10msec                   (2048U)
#define TASK_STACKSIZE_BSW_QM_TI_100msec                (8192)
#define TASK_STACKSIZE_BSW_B_10msec                     (8192)
#define TASK_STACKSIZE_BSW_QM_HighPriority_Ev           (8192)

#define TASK_STACKSIZE_APP_QM_10msec                    (2048)
#define TASK_STACKSIZE_APP_B_10msec                     (16384)
#define TASK_STACKSIZE_APP_B_30msec                     (16384)

#endif
