#ifndef APPLICATION_TASKS_INCLUDEGUARD
#define APPLICATION_TASKS_INCLUDEGUARD

#include "PlatformDataTypes.h"


#include "TaskDefscfg.h"


#ifdef DEBUG_APP_TASKS

typedef enum
{
    en_Task_APP_B_10msec,
    en_TasK_APP_QM_10msec,
    en_Task_APP_B_30msec,
    en_Task_APP_MAX,
}en_APP_Tasks_Def;

#endif

bool_t Tasks_Launch_AppTasks(void);
void appsw_tick_5ms(void);
void init_sem_appsw(void);

#endif
