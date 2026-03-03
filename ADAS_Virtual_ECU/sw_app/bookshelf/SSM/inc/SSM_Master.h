#ifndef SSM_MASTER_H_INCGUARD
#define SSM_MASTER_H_INCGUARD

#include "PlatformDataTypes.h"
#include "SSM_Cfg.h"
#include "SSM_Defs.h"

#define SSM_QNX_MONITOR 0


#ifdef SSM_APPLICATION_MASTER
typedef struct 
{    
    uint32_t PeriodicRunnableCount;
    uint32_t u32CurrentStateCount;
    SSM_SystemState g_CurrentSystemState;
    uint32_t bShutDownRequested;
    uint32_t bRestartRequested;
    uint32_t bThermalShutDownRequested;
}SSM_MasterStateInfo;


typedef void (*SSM_SimpeState_OnExitFunc)(SSM_SystemStateDef NewState);
typedef void (*SSM_SimpeState_OnEntryFunc)(SSM_SystemStateDef OldState);
typedef void (*SSM_SimpeState_PeriodicFunc)();

typedef struct 
{
    SSM_SystemStateDef CurrentState;

    /* Three functions associated with the state*/
    SSM_SimpeState_OnEntryFunc  onEntry;
    SSM_SimpeState_OnExitFunc   onExit;
    SSM_SimpeState_PeriodicFunc Periodic;

    /*Max Duration in State */
    uint32_t u32MaxDuration;
    SSM_SystemStateDef TimedOutErrorState;
    bool_t  bAllowedTransitionTo[SSM_STATE_MAX];
}SSM_StateMachineStateInfo;


void SSM_Master_Init(void);
void SSM_Master_PeriodicRunnable(void);




#endif
#endif
