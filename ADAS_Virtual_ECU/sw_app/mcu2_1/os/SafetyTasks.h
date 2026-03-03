#ifndef SAFETY_TASKS_INCLUDEGUARD
#define SAFETY_TASKS_INCLUDEGUARD

#include "PlatformDataTypes.h"

//#define DEBUG_SAFETY_TASKS

#if defined(DEBUG_SAFETY_TASKS) || defined(ADDRUNTIMESTATS)

typedef enum
{
    en_Task_SAFETY_APP_50msec,
    en_TasK_SAFETY_BSW_10msec,
    en_Task_SAFETY_MAX,
}en_SAFETY_Tasks_Def;

#endif


extern bool_t Tasks_Launch_AppSafetyTasks(void);
bool_t Tasks_Launch_BSWSafetyTasks(void);
extern void init_sem_safetysw(void);
extern void safetysw_tick_5ms(void);
#endif
