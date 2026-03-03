/** \file Us_Csm_Types.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This files contains the all the datatype, #defines definitions used accross the csm module.
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_CSM_TYPES_H_
#define _US_CSM_TYPES_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h> 


/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
#ifndef NULL_PTR
#define NULL_PTR ((void*)0)
#endif

#define US_CSM_STD_OFF (0U)
#define US_CSM_STD_ON  (1U)
#define US_CSM_LOCAL_ERROR_MASK (0x3F)
/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/
/**
 * \brief UsCsm_LocalModuleId_Type holds the local module id i.e Us sub modules which are managed or required error to
 * csm modules.
*/
typedef uint8_t  UsCsm_LocalModuleId_Type;

/**
 * \brief UsCsm_LocalErrorId_Type holds the local error id reported by Us sub modules. Each local modules has error list
 * defined in <UsCsm_LocalModules_xyz.h file.
 * 
 */
typedef uint8_t  UsCsm_LocalErrorId_Type;

/**
 * \brief UsCsm_ErrorId_Type holds the error id reported by csm module to upper layer. This error id is combinations of
 * module id and local error id. 
 *      |<-Module Id->|<-----Local Error Id---->|
 * Bits | 15 14 13 12 |11 10 9 8 7 6 5 4 3 2 1 0|
 * 
 */
typedef uint16_t UsCsm_ErrorId_Type; /*Consist of local module Id(15-12th bit) and local error Id(11-0th bit)*/


/**
 * \brief 
 * 
 */
typedef uint8_t UsCsm_CsmInternalErrId_Type;


/**
 * \brief UsCsm_RuleId_Type holds the rule id, currently its not used. Resereved for future scope design.
 * 
 */
typedef uint8_t UsCsm_RuleId_Type;

/**
 * \brief UsCsm_ActionId_Type  holds the action id, currently its not used. Resereved for future scope design.
 * 
 */
typedef uint8_t UsCsm_ActionId_Type;

/**
 * \brief UsCsm_InstanceId_Type holds the instance of Us sub module. For example <Us high side driver> module
 * has two instance <front> and <rear> dsi3 bus power line. Every module must have atleast one instance.
 * 
 */
typedef uint8_t UsCsm_InstanceId_Type;


/**
 * \brief UsCsm_LocalErrProcessType_Type holds processing types of error when reported by local module. 
 * 
 */
typedef enum
{
	/**
	 * \brief Reported error is processed in periodic function <UsCsm_MainFunction>
	 * 
	 */
	US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED = 0U,

	/**
	 * \brief Reported error is processed within execution of reporting function <UsCsm_ReportLocalError>
	 * 
	 */
	US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE
}UsCsm_LocalErrProcessType_Type;


/**
 * \brief UsCsm_ErrProcessedStatus_Type holds processed status of reported local error.
 * 
 */
typedef enum
{
	US_CSM_ERR_PROCESSED_STATUS_NOT_PROCESSED = 0U,
	US_CSM_ERR_PROCESSED_STATUS_PROCESSED
}UsCsm_ErrProcessedStatus_Type;


/**
 * \brief UsCsm_StdReturn_Type holdes the standard returns used by function across the csm modules
 * 
 */
typedef enum
{
	US_CSM_STD_RET_OK = 0U,
	US_CSM_STD_RET_NOK,
	US_CSM_STD_RET_MAX
}UsCsm_StdReturn_Type;


/**
 * \brief UsCsm_LocalErrState_Type holds the local error state reported by Us sub modules.
 * 
 */
typedef enum
{
	US_CSM_LOCAL_ERR_STATE_PASSIVE = 0U,
	US_CSM_LOCAL_ERR_STATE_ACTIVE,
	US_CSM_LOCAL_ERR_STATE_CONFIRM,
	US_CSM_LOCAL_ERR_STATE_UNDEFINED,
	US_CSM_LOCAL_ERR_STATE_MAX
}UsCsm_LocalErrState_Type;


/**
 * \brief UsCsm_StateId_Type holds the Us cms state machine states.
 * 
 */
typedef enum{
	US_CSM_STATE_ID_UN_INIT = 0U,
	US_CSM_STATE_ID_INIT,
	US_CSM_STATE_ID_ACTIVE,
	US_CSM_STATE_ID_PREDEGRADE,
	US_CSM_STATE_ID_DEGRADED,
	US_CSM_STATE_ID_PRE_SAFE_STATE_1,
	US_CSM_STATE_ID_SAFE_STATE_1,
	US_CSM_STATE_ID_PRESHUTDOWN,
	US_CSM_STATE_ID_SHUTDOWN,
	US_CSM_STATE_ID_MAX
}UsCsm_StateId_Type;


/**
 * \brief UsCsm_LocalStateId_Type holds the states of local error modules. This states are requested 
 * by the csm modules. Us sub module has to take action on state request. If Us sub module already in
 * state which has requested by csm module then Us sub module has to ignore these request.
 * 
 */
typedef enum{
	US_CSM_LOCAL_STATE_UN_INIT = 0U,
	US_CSM_LOCAL_STATE_INIT,
	US_CSM_LOCAL_STATE_ACTIVE,
	US_CSM_LOCAL_STATE_IDLE,
	US_CSM_LOCAL_STATE_SHUTDOWN,
	US_CSM_LOCAL_STATE_FAULT,
	US_CSM_LOCAL_STATE_UNDEFINED,
	US_CSM_LOCAL_STATE_MAX
}UsCsm_LocalStateId_Type;

/**
 * \brief UsCsm_LocalModuleStateSeqId_Type holds the state sequence  
 * 
 */
typedef enum{
US_CSM_LOCAL_STATE_SEQ_INIT = 0U,
US_CSM_LOCAL_STATE_SEQ_SHUTDOWN,
US_CSM_LOCAL_STATE_SEQ_SAFE_STATE_1,	
US_CSM_LOCAL_STATE_SEQ_MAX
}UsCsm_LocalModuleStateSeqId_Type;

/**
 * \brief fPtr_LocalModuleReqState_Type holds the function prototype of Local module set state function
 * 
 */
typedef UsCsm_StdReturn_Type (* fPtr_LocalModuleReqState_Type)(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState);
#define NULL_PTR_REQ_STATE ((fPtr_LocalModuleReqState_Type)0)

/**
 * \brief fPtr_LocalModuleGetState_Type holds the function prototype of Local module get state function
 * 
 */
typedef UsCsm_LocalStateId_Type (* fPtr_LocalModuleGetState_Type)(UsCsm_InstanceId_Type instanceId);
#define NULL_PTR_GET_STATE ((fPtr_LocalModuleGetState_Type)0)	

/**
 * \brief fPtr_UsCsm_ExecuteRule_Type holds the function prototype of execute rule function
 * 
 */
typedef UsCsm_StdReturn_Type (* fPtr_UsCsm_ExecuteRule_Type)(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId, UsCsm_LocalErrorId_Type UsCsmLocalErrorId,
							  UsCsm_LocalErrState_Type UsCsmLocalErrState);
#define NULL_PTR_EXECUTE_RULE ((fPtr_UsCsm_ExecuteRule_Type)0)	

/**
 * \brief fPtr_UsCsm_ExecuteAction_Type holds the function prototype of execute action function
 * 
 */
typedef UsCsm_StdReturn_Type (* fPtr_UsCsm_ExecuteAction_Type)(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId, UsCsm_LocalErrorId_Type UsCsmLocalErrorId,
							  UsCsm_LocalErrState_Type UsCsmLocalErrState);
#define NULL_PTR_EXECUTE_ACTION ((fPtr_UsCsm_ExecuteAction_Type)0)	

/**
 * \brief fPtr_UsCsm_StateAction_Type holds the function prototype of state actions function
 * 
 */
typedef UsCsm_StdReturn_Type (* fPtr_UsCsm_StateAction_Type)(void);
#define NULL_PTR_STATE_ACTION ((fPtr_UsCsm_StateAction_Type)0)

/**
 * \brief This structure holds the local error state and and processed status.
 * 
 */
typedef struct
{
	UsCsm_LocalErrState_Type LocalErrStateLog;
	UsCsm_ErrProcessedStatus_Type ErrProcessedStatus;
}UsCsm_LocalErrSts_Type;
#define NULL_PTR_US_CSM_LOCAL_ERR_STS ((UsCsm_LocalErrSts_Type *)0)


/**
 * \brief This structure holds the error processing type and rule and action for local error.
 * 
 */
typedef struct{
	UsCsm_LocalErrProcessType_Type LocalErrProcessType;
	fPtr_UsCsm_ExecuteRule_Type fPtr_ExecuteRule;
	fPtr_UsCsm_ExecuteAction_Type fPtr_ExecuteAction;
}UsCsm_ErrConf_Type;
#define NULL_PTR_US_CSM_ERR_CONF ((UsCsm_ErrConf_Type *)0)


/**
 * \brief This structure holds the mapping of error
 * 
 */
typedef struct
{
	UsCsm_LocalErrSts_Type   *LocalErrSts_Ptr;
	UsCsm_ErrConf_Type 	  *ErrConf_Ptr;
	UsCsm_LocalErrorId_Type  LocalErrorIdMax;
}UsCsm_LocalErr_Type;

/**
 * \brief This structure hold the local module static configuration.
 * 
 */
typedef struct{
	fPtr_LocalModuleReqState_Type fPtr_LocalModuleReqState;
	fPtr_LocalModuleGetState_Type fPtr_LocalModuleGetState;
	UsCsm_InstanceId_Type NumOfInstance;
	UsCsm_LocalErr_Type LocalErrConf;
}UsCsm_LocalModuleConf_Type;


/**
 * \brief This structure holds the state action on state entry function pointer, during and state exit.
 * csm state transion must be avoided in entry and exit action.csm state change can be done
 * in state during action.
 * 
 */
typedef struct 
{
	fPtr_UsCsm_StateAction_Type StateActionOnEntry;
	fPtr_UsCsm_StateAction_Type StateActionOnDuring;
	fPtr_UsCsm_StateAction_Type StateActionOnExit;
}UsCsm_StateConf_Type;

typedef struct 
{
	UsCsm_LocalModuleId_Type LocalModuleId;
	UsCsm_LocalStateId_Type LocalStateId;
}UsCsm_LocalModuleStateActionConf_Type;

/**
 * \brief This structure holds the uss submodule sequence list and  state Id, which required in
 * any submodule state change request.
 * 
 */
typedef struct 
{
	UsCsm_LocalModuleStateActionConf_Type *ptrMappedLocalModuleList;
	UsCsm_LocalModuleId_Type NumOfMappedLocalModule; 
}UsCsm_CsmStateActionSeqConf_Type;


/**
 * \brief This structure holds the reason information which is responsible for csm state change.
 * This information may very useful while debug.
 */
typedef struct 
{
	UsCsm_LocalModuleId_Type LocalModuleId;
	UsCsm_InstanceId_Type InstanceId;
	UsCsm_LocalErrorId_Type LocalErrId;
	UsCsm_LocalErrState_Type LocalErrState;
}UsCsm_CsmStateChangeReason_Type;
#define NULL_PTR_CSM_STATE_CHANHE_REASON ((UsCsm_CsmStateChangeReason_Type *)0)

typedef struct 
{
	UsCsm_LocalModuleId_Type LocalModuleId;
	UsCsm_InstanceId_Type InstanceId;
	UsCsm_LocalErrorId_Type LocalErrId;
}UsCsm_MappingId_Type;

/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/
#endif
