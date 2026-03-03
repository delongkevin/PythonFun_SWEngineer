#ifndef APPLICATION_TASKS_INCLUDEGUARD
#define APPLICATION_TASKS_INCLUDEGUARD

#include "PlatformDataTypes.h"


#include "TaskDefscfg.h"


#define TICKCOUNT_10MS (2u)
#define TICKCOUNT_30MS (6u)
#define SEC_TO_MILLISEC_COUNT (1000u)
#define DEBUG_SECONDS_PRINTF (3u)

#ifdef DEBUG_APP_TASKS

typedef enum
{
    en_Task_APP_B_10msec,
    en_TasK_APP_QM_10msec,
    en_Task_APP_MAX,
}en_APP_Tasks_Def;

#endif

bool_t Tasks_Launch_AppTasks(void);
void appsw_tick_5ms(void);
void init_sem_appsw(void);

#endif
