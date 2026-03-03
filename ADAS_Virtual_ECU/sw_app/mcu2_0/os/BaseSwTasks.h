#ifndef BASESW_TASKS_INCLUDEGUARD
#define BASESW_TASKS_INCLUDEGUARD

#include "PlatformDataTypes.h"
#include "TaskDefscfg.h"


#ifdef DEBUG_BSW_TASKS

typedef enum
{
    en_Task_BSW_B_10msec,
    en_TasK_BSW_QM_10msec,
    en_TasK_BSW_QM1_10msec,
    en_Task_en_TasK_BSW_QM_HighPriority_OnEvent,
    en_TasK_BSW_QM_TI_100msec,
    en_Task_BSW_MAX,
}en_BSW_Tasks_Def;

#endif

bool_t Tasks_Launch_BaseTasks(void);
/* timer tick function */
void basesw_tick_5ms(void);
void init_sem_basesw(void);


#endif



