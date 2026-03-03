/** \file Us_Csm.c
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This files contain the Us central state machine handling
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Main.h"
#include "Us_Csm_Conf.h"
#include "Us_Csm_Actions_If.h"
#include "US_Data_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"


/************************************************************************************************************************
                                                            Imported data
************************************************************************************************************************/
extern UsCsm_LocalModuleConf_Type UsCsmLocalModuleConf[US_CSM_LOCAL_MODULE_ID_MAX];
extern UsCsm_StateConf_Type UsCsmStateConf[US_CSM_STATE_ID_MAX];
extern UsCsm_CsmStateActionSeqConf_Type UsCsm_CsmStateActionSeqConf[US_CSM_LOCAL_STATE_SEQ_MAX];
extern UsCsm_CsmStateChangeReason_Type UsCsmStateChangeReason_Internal;

/************************************************************************************************************************
                                                            Local #defines
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Global Variables
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Local Variables
************************************************************************************************************************/
/**
* Make sure that <UsCsmState> must not changed directly by assignment operator, use <UsCsm_Internal_ReqState> to 
* function to change <UsCsmState> 
*/
static UsCsm_StateId_Type UsCsmState = US_CSM_STATE_ID_UN_INIT;
static UsCsm_StateId_Type UsCsmPrevState = US_CSM_STATE_ID_UN_INIT;
static UsCsm_CsmStateChangeReason_Type UsCsmStateChangeReason;

/************************************************************************************************************************
                                                            Global Functions
************************************************************************************************************************/
void UsCsm_Init(void);
void UsCsm_MainFunction(void);
UsCsm_StdReturn_Type UsCsm_ReqState(UsCsm_StateId_Type reqCsmStateId);
UsCsm_StdReturn_Type UsCsm_Internal_ReqState(UsCsm_StateId_Type reqUsCsmStateId, UsCsm_CsmStateChangeReason_Type *ptr_stateChangeReason);
UsCsm_StateId_Type UsCsm_GetState(void);
UsCsm_StdReturn_Type UsCsm_IsAllLocalModuleStateSetTo(UsCsm_LocalStateId_Type stateId);
UsCsm_StdReturn_Type UsCsm_SetAllLocalModuleStateSetTo(UsCsm_LocalStateId_Type stateId);
UsCsm_StdReturn_Type UsCsm_Execute_StateActionSeq(UsCsm_LocalModuleStateSeqId_Type seqId);
UsCsm_StdReturn_Type UsCsm_Verify_StateActionSeq(UsCsm_LocalModuleStateSeqId_Type seqId);
UsCsm_StdReturn_Type UsCsm_IsAnyConfirmedError(void);
UsCsm_StdReturn_Type UsCsm_IsAnyActiveError(void);
UsCsm_StdReturn_Type UsCsm_IsErrorActive(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId,
                                              UsCsm_LocalErrorId_Type errId);
UsCsm_StdReturn_Type UsCsm_IsErrorConfirmed(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId,
                                              UsCsm_LocalErrorId_Type errId);

#if(US_CSM_ERROR_REPORT_UPPER_LAYER == US_CSM_STD_ON)
void UsCsm_Notification_Error(UsCsm_ErrorId_Type UsCsmErrorId);
#endif

void UsCsm_ReportLocalError(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId,UsCsm_LocalErrorId_Type UsCsmLocalErrorId,
                              UsCsm_LocalErrState_Type UsCsmLocalErrState);
fPtr_LocalModuleReqState_Type UsCsm_GetFunPtrOfReqState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId);
fPtr_LocalModuleGetState_Type UsCsm_GetFunPtrOfGetState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId);

#if(USS_FEATURE_CSM_NOTIFICATION == US_FEATURE_ON)
void UsCsm_Notification_CsmStateChange(UsCsm_StateId_Type currentState, UsCsm_StateId_Type prevState, UsCsm_CsmStateChangeReason_Type csmStateChangeReason);
#endif

void UsCsm_GetCsmStateChnageReason(UsCsm_CsmStateChangeReason_Type *ptr_stateChangeReason);


/************************************************************************************************************************
                                                            Local Functions
************************************************************************************************************************/
static UsCsm_ErrConf_Type* UsCsm_GetPointer_ErrConf(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId);
static UsCsm_LocalErrSts_Type* UsCsm_GetPointer_ErrState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId);
static void UsCsm_ProcessError(void);
static UsCsm_StdReturn_Type UsCsm_VerifyCsmStateInterlock(UsCsm_StateId_Type reqUsCsmStateId)	;

/************************************************************************************************************************
                                                            Function Definations
************************************************************************************************************************/


/**
 * \brief This function initialize the internal variables of csm and change the csm state to init.
 * 
 */
 /* ===========================================================================
 * Name: UsCsm_Init    
 * Remarks:  DD-ID: {C7222B78-A7A7-4842-9404-FECCDC5BA537}
 * ===========================================================================*/
void UsCsm_Init(void)
{
	UsCsm_LocalModuleId_Type lclModIdIndex;
	UsCsm_LocalErrorId_Type lclErrIdIndex;
	UsCsm_InstanceId_Type instanceId;
	UsCsm_LocalErrSts_Type *UsCsm_LocalErrState_Ptr;
	
	/*Init internal data variables*/
	for(lclModIdIndex = 0U; lclModIdIndex < US_CSM_LOCAL_MODULE_ID_MAX; lclModIdIndex++)
	{
		for(instanceId = 0U; instanceId < UsCsmLocalModuleConf[lclModIdIndex].NumOfInstance; instanceId++)
		{
			UsCsm_LocalErrState_Ptr = UsCsm_GetPointer_ErrState(lclModIdIndex,instanceId);				
			if(NULL_PTR_US_CSM_LOCAL_ERR_STS != UsCsm_LocalErrState_Ptr)
			{
				for(lclErrIdIndex = 0U; lclErrIdIndex < UsCsmLocalModuleConf[lclModIdIndex].LocalErrConf.LocalErrorIdMax; lclErrIdIndex++)
				{
					UsCsm_LocalErrState_Ptr[lclErrIdIndex].LocalErrStateLog = US_CSM_LOCAL_ERR_STATE_PASSIVE;
					UsCsm_LocalErrState_Ptr[lclErrIdIndex].ErrProcessedStatus = US_CSM_ERR_PROCESSED_STATUS_PROCESSED;
				}
			}
		}
	}

   UsCsmStateChangeReason = UsCsmStateChangeReason_Internal;
}


/**
* \brief        This function control the central state machine for Us.
* \details      Provides details about the function
*
* \param[in]    void
*
* \return     	void
*/
/* ===========================================================================
 * Name: UsCsm_MainFunction    
 * Remarks:  DD-ID: {C7540EE8-4F62-4cc0-BACF-C1F626043866}
 * ===========================================================================*/
void UsCsm_MainFunction(void)
{
    /*Process the deffered error type*/
	if((US_CSM_STATE_ID_UN_INIT != UsCsmState) && 
       (US_CSM_STATE_ID_SHUTDOWN != UsCsmState))
	{
		UsCsm_ProcessError();
	}

    /*Process the action configured during state*/
    if(UsCsmState < US_CSM_STATE_ID_MAX)
	{
		/*Execute action during state entry if action configured*/
		if(NULL_PTR_STATE_ACTION != UsCsmStateConf[UsCsmState].StateActionOnDuring)
		{
			(void)UsCsmStateConf[UsCsmState].StateActionOnDuring();
		}
	}

	/*store the previous csm state and invoke notification function if csm state changed*/
	if(UsCsmPrevState != UsCsmState)
	{
#if(USS_FEATURE_CSM_NOTIFICATION == US_FEATURE_ON)
		UsCsm_Notification_CsmStateChange(UsCsmState, UsCsmPrevState, UsCsmStateChangeReason);
#endif
		UsCsmPrevState = UsCsmState;
	}
    else
    {
     	/* Do nothing */
    }
}

/**
 * \brief This function request csm state change. This funation can be invoked by application above the <UsCsm> Module.
 * 
 * \param reqCsmStateId 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_ReqState    
 * Remarks:  DD-ID: {2470B77B-A3C5-46d5-A038-2A410058917E}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_ReqState(UsCsm_StateId_Type reqCsmStateId)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;
	UsCsm_CsmStateChangeReason_Type stateChangeReason =
	{
		.LocalModuleId = US_CSM_LOCAL_MODULE_ID_UP_LAYER,
		.InstanceId    = US_CSM_LOCAL_MODULE_INSTANCE_ID_DEAFULT,
		.LocalErrId    = US_CSM_LOCAL_MODULE_ERR_ID_INT_DEAFULT,
		.LocalErrState = US_CSM_LOCAL_ERR_STATE_CONFIRM
	};

	switch(reqCsmStateId)
	{
		case US_CSM_STATE_ID_UN_INIT:
		break;

		case US_CSM_STATE_ID_SAFE_STATE_1:
		(void)UsCsm_Internal_ReqState(US_CSM_STATE_ID_PRE_SAFE_STATE_1, &stateChangeReason);
		break;

		case US_CSM_STATE_ID_SHUTDOWN:
		(void)UsCsm_Internal_ReqState(US_CSM_STATE_ID_PRESHUTDOWN, &stateChangeReason);
		break;

		default:
		stdRet = US_CSM_STD_RET_NOK;
		break;
	}	

	return (stdRet);
}

/**
 * \brief This function set the csm state and invoke the configured state action on state enrty and exit.
 * 
 * \param reqUsCsmStateId 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_Internal_ReqState    
 * Remarks:  DD-ID: {2CF6F8DA-0D70-4261-81A8-BA2B0D8D343B}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_Internal_ReqState(UsCsm_StateId_Type reqUsCsmStateId, UsCsm_CsmStateChangeReason_Type *ptr_stateChangeReason)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
	if(reqUsCsmStateId < US_CSM_STATE_ID_MAX)
	{
		if(US_CSM_STD_RET_OK == UsCsm_VerifyCsmStateInterlock(reqUsCsmStateId))
		{
			/*Execute state action on state exit if action is configured*/
			if(NULL_PTR_STATE_ACTION != UsCsmStateConf[UsCsmState].StateActionOnExit)
			{
				UsCsmStateConf[UsCsmState].StateActionOnExit();
			}	
			else
            {
                ;/* Do nothing */
            }		

			/*Execute state action on state entry if action is configured*/
			if(NULL_PTR_STATE_ACTION != UsCsmStateConf[reqUsCsmStateId].StateActionOnEntry)
			{
				UsCsmStateConf[reqUsCsmStateId].StateActionOnEntry();
			}
			else
            {
                ;/* Do nothing */
            }
			
			UsCsmState = reqUsCsmStateId;
			if(NULL_PTR_CSM_STATE_CHANHE_REASON != ptr_stateChangeReason)
			{
				UsCsmStateChangeReason = *ptr_stateChangeReason;
			}
			else
            {
                ;/* Do nothing */
            }
			stdRet = US_CSM_STD_RET_OK;
		}
        else
        {
          ;/* Do nothing */
        }
	}
	else
    {
         ;/* Do nothing */
     }
	return (stdRet);
}


/**
 * \brief This function check if csm state can be changed
 * 
 * \param reqUsCsmStateId 
 * \return UsCsm_StateId_Type 
 */
/* ===========================================================================
 * Name: UsCsm_VerifyCsmStateInterlock    
 * Remarks:  DD-ID: {03A5D889-74E7-4535-9757-EA066C07FE26}
 * ===========================================================================*/
static UsCsm_StdReturn_Type UsCsm_VerifyCsmStateInterlock(UsCsm_StateId_Type reqUsCsmStateId)	
{
    UsCsm_StdReturn_Type ret = US_CSM_STD_RET_NOK;

	/*Do not accept request if requested and current csm state is same*/
	if(UsCsmState != reqUsCsmStateId)
	{
		switch(UsCsmState)
		{
			case US_CSM_STATE_ID_UN_INIT:
				if((US_CSM_STATE_ID_INIT == reqUsCsmStateId)         ||
				   (US_CSM_STATE_ID_SAFE_STATE_1 == reqUsCsmStateId) ||
				   (US_CSM_STATE_ID_PRE_SAFE_STATE_1 == reqUsCsmStateId))
				{
					ret = US_CSM_STD_RET_OK;
				}
			break;

			case US_CSM_STATE_ID_INIT:
			case US_CSM_STATE_ID_ACTIVE:
				ret = US_CSM_STD_RET_OK;
			break;
						
			case US_CSM_STATE_ID_PREDEGRADE:
				if(US_CSM_STATE_ID_DEGRADED != reqUsCsmStateId )
				{
					ret = US_CSM_STD_RET_OK;
				}
			break;

			case US_CSM_STATE_ID_DEGRADED:
				if(US_CSM_STATE_ID_PREDEGRADE != reqUsCsmStateId)
				{
					ret = US_CSM_STD_RET_OK;
				}
			break;

			case US_CSM_STATE_ID_PRE_SAFE_STATE_1:
				if((US_CSM_STATE_ID_PRESHUTDOWN == reqUsCsmStateId) ||
				   (US_CSM_STATE_ID_SHUTDOWN == reqUsCsmStateId)    ||
				   (US_CSM_STATE_ID_SAFE_STATE_1 == reqUsCsmStateId))
				{
					ret = US_CSM_STD_RET_OK;
				}
			break;

			case US_CSM_STATE_ID_SAFE_STATE_1:	

				if((US_CSM_STATE_ID_PRESHUTDOWN == reqUsCsmStateId) ||
				   (US_CSM_STATE_ID_SHUTDOWN == reqUsCsmStateId))
				{
					ret = US_CSM_STD_RET_OK;
				}

			break;

			case US_CSM_STATE_ID_PRESHUTDOWN:	
				if((US_CSM_STATE_ID_SHUTDOWN == reqUsCsmStateId) ||
				   (US_CSM_STATE_ID_INIT == reqUsCsmStateId))
				{
					ret = US_CSM_STD_RET_OK;
				}	
			break;

			case US_CSM_STATE_ID_SHUTDOWN:
				if(US_CSM_STATE_ID_INIT == reqUsCsmStateId)
				{
					ret = US_CSM_STD_RET_OK;
				}
			break;
	
			default:
			break;
		}
	}
	return (ret);
}
#if(US_D_CUR_PLATFORM != US_D_PLATFORM_CVADAS)
/**
 * \brief This function return the current state of csm.
 * 
 * \return UsCsm_StateId_Type 
 */
/* ===========================================================================
 * Name: UsCsm_GetState    
 * Remarks:  DD-ID: {7C6F685E-24F3-4bff-A6A1-76BEDD32EA8B}
 * ===========================================================================*/
UsCsm_StateId_Type UsCsm_GetState(void)
{
	return (UsCsmState);
}
#endif 


/**
 * \brief This function is invoked by the local modules when error detected as passive,active or confirmed.
 *        This function process the error within execution of this call if error is configured for immidiate
 *        process else it marked for processing in execution of UsCsm_MainFunction i.e deffered process.Avoid
 * 		  this function invoking on periodic basic, it can be invoked on error event basis. 
 * \param UsCsmLocalModuleId 
 * \param instanceId 
 * \param UsCsmLocalErrorId 
 * \param UsCsmLocalErrState 
 */
/* ===========================================================================
 * Name: UsCsm_ReportLocalError    
 * Remarks:  DD-ID: {B10DA037-574F-4c9b-99AE-248B7DF3B29E}
 * ===========================================================================*/
void UsCsm_ReportLocalError(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId,
                              UsCsm_LocalErrorId_Type UsCsmLocalErrorId,UsCsm_LocalErrState_Type UsCsmLocalErrState)
{
	UsCsm_LocalErrSts_Type *localErrState_Ptr;
	UsCsm_ErrConf_Type *errConf_Ptr;


	if(UsCsmLocalModuleId < US_CSM_LOCAL_MODULE_ID_MAX)
	{
		if(NULL_PTR_US_CSM_LOCAL_ERR_STS != UsCsmLocalModuleConf[UsCsmLocalModuleId].LocalErrConf.LocalErrSts_Ptr)
		{
			if(UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance > instanceId)
			{
				if(UsCsmLocalModuleConf[UsCsmLocalModuleId].LocalErrConf.LocalErrorIdMax > UsCsmLocalErrorId)
				{
					if(UsCsmLocalErrState < US_CSM_LOCAL_ERR_STATE_MAX)
					{				
						errConf_Ptr = UsCsm_GetPointer_ErrConf(UsCsmLocalModuleId,instanceId);						
						localErrState_Ptr = UsCsm_GetPointer_ErrState(UsCsmLocalModuleId,instanceId);
						if(NULL_PTR_US_CSM_LOCAL_ERR_STS != localErrState_Ptr)
						{
							/*Check if the error state has been changed*/
							if(UsCsmLocalErrState != localErrState_Ptr[UsCsmLocalErrorId].LocalErrStateLog)
							{					
								if((US_CSM_LOCAL_ERR_PROCESS_TYPE_IMMIGIATE == errConf_Ptr[UsCsmLocalErrorId].LocalErrProcessType)) 
								{								
#if(US_CSM_ERROR_REPORT_UPPER_LAYER == US_CSM_STD_ON)
									/*Only notify confirmed error to application layer (above to UsCsm layers)*/
									if(US_CSM_LOCAL_ERR_STATE_CONFIRM == localErrState_Ptr[UsCsmLocalErrorId].LocalErrStateLog)
									{
										UsCsm_Notification_Error((UsCsm_LocalErrorId_Type)(( UsCsmLocalModuleId << 12 ) | (UsCsmLocalErrorId & US_CSM_LOCAL_ERROR_MASK)));
									}
#endif													
									if(NULL_PTR_EXECUTE_RULE != (errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteRule))
									{
										/*Execute the respective rule configured*/
										if(US_CSM_STD_RET_OK == errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteRule(UsCsmLocalModuleId, instanceId, UsCsmLocalErrorId,UsCsmLocalErrState))
										{
#if(US_CSM_EXECUTE_ACTION == US_CSM_STD_ON)
											if(NULL_PTR_EXECUTE_ACTION != (errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteAction))
											{
												/*Execute action configured*/
												(void)errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteAction(UsCsmLocalModuleId, instanceId,UsCsmLocalErrorId,UsCsmLocalErrState);
											}
#endif
										}
									}
								}
								else
								{
								/*Ignore the reported error if no action and rule configured for reported error*/
								if((NULL_PTR_EXECUTE_RULE != (errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteRule)) && 
									(NULL_PTR_EXECUTE_ACTION != (errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteAction)))
									{
										if(US_CSM_STD_RET_OK == errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteRule(UsCsmLocalModuleId, instanceId, UsCsmLocalErrorId,UsCsmLocalErrState))
										{	
											localErrState_Ptr[UsCsmLocalErrorId].ErrProcessedStatus = US_CSM_ERR_PROCESSED_STATUS_NOT_PROCESSED;
										}
									}
								}
			
								/*Ignore the reported error if no action and rule configured for reported error*/
								if((NULL_PTR_EXECUTE_RULE != (errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteRule)) && 
								   (NULL_PTR_EXECUTE_ACTION != (errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteAction)))
								{
									/*Save the error state*/
									if(US_CSM_STD_RET_OK == errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteRule(UsCsmLocalModuleId, instanceId, UsCsmLocalErrorId,UsCsmLocalErrState))
									{
										localErrState_Ptr[UsCsmLocalErrorId].LocalErrStateLog = UsCsmLocalErrState;	
									}
								}						
							}
						}
					}
				}
			}
		}
	}
}
#if(US_D_CUR_PLATFORM != US_D_PLATFORM_CVADAS)
/**
 * \brief This function return the error state.
 * 
 * \param UsCsmLocalModuleId 
 * \param instanceId 
 * \param errId 
 * \return UsCsm_LocalErrState_Type 
 */
/* ===========================================================================
 * Name: UsCsm_GetLocalErrorState    
 * Remarks:  DD-ID: {B10DA037-574F-4c9b-99AE-248B7DF3B29E}
 * ===========================================================================*/
UsCsm_LocalErrState_Type UsCsm_GetLocalErrorState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId,
                                              UsCsm_LocalErrorId_Type errId)
{
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalErrSts_Type *localErrState_Ptr;
	UsCsm_LocalErrState_Type retState = US_CSM_LOCAL_ERR_STATE_UNDEFINED;

	if(US_CSM_LOCAL_MODULE_ID_MAX > UsCsmLocalModuleId)
	{			
		if(UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance > instanceId)
		{
			localErrState_Ptr = UsCsm_GetPointer_ErrState(UsCsmLocalModuleId,instanceId);
			if(NULL_PTR_US_CSM_LOCAL_ERR_STS != localErrState_Ptr)
			{
				if(errId < UsCsmLocalModuleConf[UsCsmLocalModuleId].LocalErrConf.LocalErrorIdMax)
				{
					retState = localErrState_Ptr[errId].LocalErrStateLog;
				}
			}
		}
	}

	return (retState);
}
#endif
/**
 * \brief This function process the error which are configired as deffered for processing.
 * 
 */
/* ===========================================================================
 * Name: UsCsm_ProcessError    
 * Remarks:  DD-ID: {7E88463E-401C-4e3e-A98C-8DAEAF872913}
 * ===========================================================================*/
static void UsCsm_ProcessError(void)
{
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalModuleId_Type UsCsmLocalModuleId;
	UsCsm_LocalErrSts_Type *localErrState_Ptr;
	UsCsm_ErrConf_Type *errConf_Ptr;
	UsCsm_LocalErrorId_Type UsCsmLocalErrorId;
	

	for(UsCsmLocalModuleId = 0; UsCsmLocalModuleId < US_CSM_LOCAL_MODULE_ID_MAX; UsCsmLocalModuleId++)
	{
		for(instanceIdIndex = 0; instanceIdIndex < UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance; instanceIdIndex++)
		{
			errConf_Ptr = UsCsm_GetPointer_ErrConf(UsCsmLocalModuleId,instanceIdIndex);						
			localErrState_Ptr = UsCsm_GetPointer_ErrState(UsCsmLocalModuleId,instanceIdIndex);

			if((NULL_PTR_US_CSM_ERR_CONF != errConf_Ptr) && (NULL_PTR_US_CSM_LOCAL_ERR_STS != localErrState_Ptr))
			{
				for(UsCsmLocalErrorId = 0; UsCsmLocalErrorId < UsCsmLocalModuleConf[UsCsmLocalModuleId].LocalErrConf.LocalErrorIdMax; UsCsmLocalErrorId++)
				{				
					if((US_CSM_LOCAL_ERR_PROCESS_TYPE_DEFEERED == errConf_Ptr[UsCsmLocalErrorId].LocalErrProcessType)) 
					{
						if(US_CSM_ERR_PROCESSED_STATUS_NOT_PROCESSED == localErrState_Ptr[UsCsmLocalErrorId].ErrProcessedStatus)
						{
							
#if(US_CSM_ERROR_REPORT_UPPER_LAYER == US_CSM_STD_ON)
							/*Only notify confirmed error to application layer (above to UsCsm layers)*/
							if(US_CSM_LOCAL_ERR_STATE_CONFIRM == localErrState_Ptr[UsCsmLocalErrorId].LocalErrStateLog)
							{
								UsCsm_Notification_Error((UsCsm_LocalErrorId_Type)(( UsCsmLocalModuleId << 12 ) | (UsCsmLocalErrorId & Us_CSM_LOCAL_ERROR_MASK)));
							}
#endif					
							if(NULL_PTR != (errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteRule))
							{
								/*Execute the respective rule configured*/
								if(US_CSM_STD_RET_OK == errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteRule(UsCsmLocalModuleId, instanceIdIndex, UsCsmLocalErrorId, localErrState_Ptr[UsCsmLocalErrorId].LocalErrStateLog))
								{
#if(US_CSM_EXECUTE_ACTION == US_CSM_STD_ON)
									if(NULL_PTR != (errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteAction))
									{
										/*Execute respecyive action configured*/
										(void)errConf_Ptr[UsCsmLocalErrorId].fPtr_ExecuteAction(UsCsmLocalModuleId, instanceIdIndex,UsCsmLocalErrorId, localErrState_Ptr[UsCsmLocalErrorId].LocalErrStateLog);
									}
#endif
								}
							}
							localErrState_Ptr[UsCsmLocalErrorId].ErrProcessedStatus = US_CSM_ERR_PROCESSED_STATUS_PROCESSED;
						}
					}
				}/*End of error index loop*/
			}						

		}/*End of instance index lopp*/
	}/*End of module index loop*/
}


/**
 * \brief This function return the function pointer for set state of requested local module.
 *        for example Us_Hsd_ReqState_Csm
 * \param UsCsmLocalModuleId 
 * \return fPtr_LocalModuleReqState_Type 
 */
/* ===========================================================================
 * Name: UsCsm_GetFunPtrOfReqState    
 * Remarks:  DD-ID: {B027CDDD-AF3C-4c73-AE80-D114E173B426}
 * ===========================================================================*/
fPtr_LocalModuleReqState_Type UsCsm_GetFunPtrOfReqState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId)
{
	fPtr_LocalModuleReqState_Type retFunPtr = NULL_PTR_REQ_STATE;

	if(UsCsmLocalModuleId < US_CSM_LOCAL_MODULE_ID_MAX)
	{
		retFunPtr = UsCsmLocalModuleConf[UsCsmLocalModuleId].fPtr_LocalModuleReqState;
	}

	return (retFunPtr);
}


/**
 * \brief This function return the function pointer for get state of requested local module.
 *         for example Us_Hsd_GetState_Csm
 * \param UsCsmLocalModuleId 
 * \return fPtr_LocalModuleGetState_Type 
 */
/* ===========================================================================
 * Name: UsCsm_GetFunPtrOfGetState    
 * Remarks:  DD-ID: {9522D459-C5E8-43d8-BC29-8C103C3B6BD0}
 * ===========================================================================*/
fPtr_LocalModuleGetState_Type UsCsm_GetFunPtrOfGetState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId)
{
	fPtr_LocalModuleGetState_Type retFunPtr = NULL_PTR_GET_STATE;

	if(UsCsmLocalModuleId < US_CSM_LOCAL_MODULE_ID_MAX)
	{
		retFunPtr = UsCsmLocalModuleConf[UsCsmLocalModuleId].fPtr_LocalModuleGetState;
	}

	return (retFunPtr);
}


/**
 * \brief This function verify state of all the local modules are to set requested state.
 * 
 * \param stateId 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_IsAllLocalModuleStateSetTo    
 * Remarks:  DD-ID: {F07C5C98-9EC3-44e3-A462-A9C734B3C8AE}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_IsAllLocalModuleStateSetTo(UsCsm_LocalStateId_Type stateId)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalModuleId_Type UsCsmLocalModuleId;

	for(UsCsmLocalModuleId = 0; UsCsmLocalModuleId < US_CSM_LOCAL_MODULE_ID_MAX; UsCsmLocalModuleId++)
	{
		for(instanceIdIndex = 0; instanceIdIndex < UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance; instanceIdIndex++)
		{						
			if(NULL_PTR_GET_STATE != UsCsmLocalModuleConf[UsCsmLocalModuleId].fPtr_LocalModuleGetState)
			{
				if(stateId ==  UsCsmLocalModuleConf[UsCsmLocalModuleId].fPtr_LocalModuleGetState(instanceIdIndex))
				{
					stdRet = US_CSM_STD_RET_OK;
				}
				else
				{
					stdRet = US_CSM_STD_RET_NOK;
					break;
				}
			}
		}
	}

	return (stdRet);
}


/**
 * \brief This function invokes function <UsCsm_GetState_xyz> of all the local module to set requested state of 
 * local module. 
 * 
 * \param stateId 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_SetAllLocalModuleStateSetTo    
 * Remarks:  DD-ID: {B595DA51-D09B-47a7-8323-9C5BE5963E12}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_SetAllLocalModuleStateSetTo(UsCsm_LocalStateId_Type stateId)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalModuleId_Type UsCsmLocalModuleId;

	for(UsCsmLocalModuleId = 0; UsCsmLocalModuleId < US_CSM_LOCAL_MODULE_ID_MAX; UsCsmLocalModuleId++)
	{
		for(instanceIdIndex = 0; instanceIdIndex < UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance; instanceIdIndex++)
		{	
			if(NULL_PTR_REQ_STATE != UsCsmLocalModuleConf[UsCsmLocalModuleId].fPtr_LocalModuleReqState)
			{					
				(void)UsCsmLocalModuleConf[UsCsmLocalModuleId].fPtr_LocalModuleReqState(instanceIdIndex,stateId);
			}
		}
	}

	return (stdRet);
}

/**
 * \brief This function invokes function <UsCsm_GetState_xyz> of all the local module to set  state to init
 * 
 * \param stateId 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_Execute_StateActionSeq    
 * Remarks:  DD-ID: {D554D4C6-FB60-4156-80CE-40B2719228D6}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_Execute_StateActionSeq(UsCsm_LocalModuleStateSeqId_Type seqId)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalModuleId_Type UsCsmLocalModuleId;
	UsCsm_LocalModuleId_Type mappedLocalModuleId;

	if(seqId < US_CSM_LOCAL_STATE_SEQ_MAX)
	{
		for(UsCsmLocalModuleId = 0; UsCsmLocalModuleId < UsCsm_CsmStateActionSeqConf[seqId].NumOfMappedLocalModule; UsCsmLocalModuleId++)
		{
			mappedLocalModuleId = UsCsm_CsmStateActionSeqConf[seqId].ptrMappedLocalModuleList[UsCsmLocalModuleId].LocalModuleId;
		
			if(mappedLocalModuleId < US_CSM_LOCAL_MODULE_ID_MAX)
			{
				for(instanceIdIndex = 0; instanceIdIndex < UsCsmLocalModuleConf[mappedLocalModuleId].NumOfInstance; instanceIdIndex++)
				{						
					if(NULL_PTR_REQ_STATE != UsCsmLocalModuleConf[mappedLocalModuleId].fPtr_LocalModuleReqState)
					{
						(void)UsCsmLocalModuleConf[mappedLocalModuleId].fPtr_LocalModuleReqState(instanceIdIndex,
						                                                                         UsCsm_CsmStateActionSeqConf[seqId].ptrMappedLocalModuleList[UsCsmLocalModuleId].LocalStateId);
					}
				}
			}
		}
	}

	return (stdRet);
}

/**
 * \brief This function invokes function <UsCsm_GetState_xyz> of all the local module to set  state to init
 * 
 * \param stateId 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_Verify_StateActionSeq    
 * Remarks:  DD-ID: {AEEF5C99-8125-4215-84E3-CC54C2AAAD9F}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_Verify_StateActionSeq(UsCsm_LocalModuleStateSeqId_Type seqId)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalModuleId_Type UsCsmLocalModuleId;
	UsCsm_LocalModuleId_Type mappedLocalModuleId;
	UsCsm_LocalStateId_Type stateId;

	if(seqId < US_CSM_LOCAL_STATE_SEQ_MAX)
	{
		for(UsCsmLocalModuleId = 0; UsCsmLocalModuleId < UsCsm_CsmStateActionSeqConf[seqId].NumOfMappedLocalModule; UsCsmLocalModuleId++)
		{
			mappedLocalModuleId = UsCsm_CsmStateActionSeqConf[seqId].ptrMappedLocalModuleList[UsCsmLocalModuleId].LocalModuleId;
		
			if(mappedLocalModuleId < US_CSM_LOCAL_MODULE_ID_MAX)
			{
				for(instanceIdIndex = 0; instanceIdIndex < UsCsmLocalModuleConf[mappedLocalModuleId].NumOfInstance; instanceIdIndex++)
				{						
					if(NULL_PTR_GET_STATE != UsCsmLocalModuleConf[mappedLocalModuleId].fPtr_LocalModuleGetState)
					{
						stdRet = US_CSM_STD_RET_OK;
						stateId = UsCsmLocalModuleConf[mappedLocalModuleId].fPtr_LocalModuleGetState(instanceIdIndex);
						if(stateId != UsCsm_CsmStateActionSeqConf[seqId].ptrMappedLocalModuleList[UsCsmLocalModuleId].LocalStateId)
						{
							stdRet = US_CSM_STD_RET_NOK;
							break;
						}
					}
				}
			}
		}
	}

	return (stdRet);
}


/**
 * \brief This function checks if is there any confirmed errors and return US_CSM_STD_RET_OK
 * 
 * \param UsCsmLocalModuleId 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_IsAnyConfirmedError
 * Remarks:  DD-ID: {22A70F25-2B6B-4ead-B97A-5BF8F84C2FAC}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_IsAnyConfirmedError(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
	UsCsm_LocalErrorId_Type errId;
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalErrSts_Type *localErrState_Ptr = NULL_PTR_US_CSM_LOCAL_ERR_STS;
	UsCsm_LocalModuleId_Type UsCsmLocalModuleId;

	for(UsCsmLocalModuleId = 0; UsCsmLocalModuleId < US_CSM_LOCAL_MODULE_ID_MAX; UsCsmLocalModuleId++)
	{
		for(instanceIdIndex = 0; instanceIdIndex < UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance; instanceIdIndex++)
		{						
			localErrState_Ptr = UsCsm_GetPointer_ErrState(UsCsmLocalModuleId,instanceIdIndex);

			if(NULL_PTR_US_CSM_LOCAL_ERR_STS != localErrState_Ptr)
			{
				for(errId = 0; errId < UsCsmLocalModuleConf[UsCsmLocalModuleId].LocalErrConf.LocalErrorIdMax; errId++)
				{
					if(US_CSM_LOCAL_ERR_STATE_CONFIRM == localErrState_Ptr[errId].LocalErrStateLog)
					{
						stdRet = US_CSM_STD_RET_OK;
						break;
					}
				}
			}
		}
	}

	return (stdRet);
}

#if(US_D_CUR_PLATFORM != US_D_PLATFORM_CVADAS)
/**
 * \brief This function checks if is there any active errors and return US_CSM_STD_RET_OK
 * 
 * \param UsCsmLocalModuleId 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_IsAnyActiveError	
 * Remarks:  DD-ID: {CAF37B34-C43A-4474-BF9E-F733DC8B6D29}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_IsAnyActiveError(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
	UsCsm_LocalErrorId_Type errId;
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalErrSts_Type *localErrState_Ptr = NULL_PTR_US_CSM_LOCAL_ERR_STS;
	UsCsm_LocalModuleId_Type UsCsmLocalModuleId;

	for(UsCsmLocalModuleId = 0; UsCsmLocalModuleId < US_CSM_LOCAL_MODULE_ID_MAX; UsCsmLocalModuleId++)
	{
		for(instanceIdIndex = 0; instanceIdIndex < UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance; instanceIdIndex++)
		{						
			localErrState_Ptr = UsCsm_GetPointer_ErrState(UsCsmLocalModuleId,instanceIdIndex);

			if(NULL_PTR_US_CSM_LOCAL_ERR_STS != localErrState_Ptr)
			{
				for(errId = 0; errId < UsCsmLocalModuleConf[UsCsmLocalModuleId].LocalErrConf.LocalErrorIdMax; errId++)
				{
					if(US_CSM_LOCAL_ERR_STATE_ACTIVE == localErrState_Ptr[errId].LocalErrStateLog)
					{
						stdRet = US_CSM_STD_RET_OK;
						break;
					}
				}
			}
		}
	}

	return (stdRet);
}


/**
 * \brief This function checks if respective error is active error.
 * 
 * \param UsCsmLocalModuleId 
 * \param errId 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_IsErrorActive	
 * Remarks:  DD-ID: {9F45CDE6-56BE-4a2a-B32D-C039CC40060C}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_IsErrorActive(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId,
                                              UsCsm_LocalErrorId_Type errId)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalErrSts_Type *localErrState_Ptr = NULL_PTR_US_CSM_LOCAL_ERR_STS;

	if(US_CSM_LOCAL_MODULE_ID_MAX > UsCsmLocalModuleId)
	{			
		if(UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance > instanceId)
		{
			localErrState_Ptr = UsCsm_GetPointer_ErrState(UsCsmLocalModuleId,instanceId);
			
			if(NULL_PTR_US_CSM_LOCAL_ERR_STS != localErrState_Ptr)
			{
				if(US_CSM_LOCAL_ERR_STATE_ACTIVE == localErrState_Ptr[errId].LocalErrStateLog)
				{
					stdRet = US_CSM_STD_RET_OK;
				}
			}
		}
	}

	return (stdRet);
}


/**
 * \brief This function checks if respective error is confirmed error.
 * 
 * \param UsCsmLocalModuleId 
 * \param errId 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name:UsCsm_IsErrorConfirmed	
 * Remarks:  DD-ID: {44A343B9-92BC-47b9-9F0B-9FB71A7B0F88}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_IsErrorConfirmed(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId,
                                              UsCsm_LocalErrorId_Type errId)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalErrSts_Type *localErrState_Ptr = NULL_PTR_US_CSM_LOCAL_ERR_STS;

	if(US_CSM_LOCAL_MODULE_ID_MAX > UsCsmLocalModuleId)
	{			
		if(UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance > instanceId)
		{
			localErrState_Ptr = UsCsm_GetPointer_ErrState(UsCsmLocalModuleId,instanceId);

			if(NULL_PTR_US_CSM_LOCAL_ERR_STS != localErrState_Ptr)
			{
				if(US_CSM_LOCAL_ERR_STATE_CONFIRM == localErrState_Ptr[errId].LocalErrStateLog)
				{
					stdRet = US_CSM_STD_RET_OK;
				}
			}
		}
	}
	
	return (stdRet);
}
#endif

/**
 * \brief This function return the errConf pointer of respective local module and instance.
 * 
 * \param UsCsmLocalModuleId 
 * \param instanceId 
 * \return UsCsm_ErrConf_Type* 
 */
/* ===========================================================================
 * Name:UsCsm_GetPointer_ErrConf	
 * Remarks:  DD-ID:{07EC9A32-2659-443d-9B5F-73AFC0A80302} 
 * ===========================================================================*/
static UsCsm_ErrConf_Type* UsCsm_GetPointer_ErrConf(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId)
{
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalErrorId_Type localErrorIdIndex;
	UsCsm_ErrConf_Type *UsCsm_ErrConf_Ptr = NULL_PTR_US_CSM_ERR_CONF;

	if(US_CSM_LOCAL_MODULE_ID_MAX > UsCsmLocalModuleId)
	{
		if(UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance > instanceId)
		{
			UsCsm_ErrConf_Ptr = UsCsmLocalModuleConf[UsCsmLocalModuleId].LocalErrConf.ErrConf_Ptr;
			for( instanceIdIndex = 0; instanceIdIndex < instanceId; instanceIdIndex++)
			{
				for( localErrorIdIndex = 0; localErrorIdIndex < UsCsmLocalModuleConf[UsCsmLocalModuleId].LocalErrConf.LocalErrorIdMax ; localErrorIdIndex++)
				{
					UsCsm_ErrConf_Ptr++;
				}
			}
		}
	}
	return (UsCsm_ErrConf_Ptr);
}


/**
 * \brief This function return the errState pointer of respective local module and instance.
 * 
 * \param UsCsmLocalModuleId 
 * \param instanceId 
 * \return UsCsm_ErrConf_Type* 
 */
/* ===========================================================================
 * Name: UsCsm_GetPointer_ErrState	
 * Remarks:  DD-ID: {A538AC89-5BF7-4445-8101-2701D5F1580A}
 * ===========================================================================*/
static 	UsCsm_LocalErrSts_Type* UsCsm_GetPointer_ErrState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId)
{
	UsCsm_InstanceId_Type instanceIdIndex;
	UsCsm_LocalErrorId_Type localErrorIdIndex;
	UsCsm_LocalErrSts_Type *localErrState_Ptr = NULL_PTR_US_CSM_LOCAL_ERR_STS;

	if(US_CSM_LOCAL_MODULE_ID_MAX > UsCsmLocalModuleId)
	{
		if(UsCsmLocalModuleConf[UsCsmLocalModuleId].NumOfInstance > instanceId)
		{
			localErrState_Ptr = UsCsmLocalModuleConf[UsCsmLocalModuleId].LocalErrConf.LocalErrSts_Ptr;

			if(NULL_PTR_US_CSM_LOCAL_ERR_STS != localErrState_Ptr)
			{
				for( instanceIdIndex = 0; instanceIdIndex < instanceId; instanceIdIndex++)
				{
					for( localErrorIdIndex = 0; localErrorIdIndex < UsCsmLocalModuleConf[UsCsmLocalModuleId].LocalErrConf.LocalErrorIdMax ; localErrorIdIndex++)
					{
						localErrState_Ptr++;
					}
				}
			}
		}
	}
	return (localErrState_Ptr);
}

#if(US_D_CUR_PLATFORM != US_D_PLATFORM_CVADAS)
/**
 * \brief This funtion provides the csm state change reasons.
 * 
 * \return UsCsm_CsmStateChangeReason_Type 
 */
/* ===========================================================================
 * Name:UsCsm_GetCsmStateChnageReason	
 * Remarks:  DD-ID:{0562B142-9497-46ba-89D3-063934EF8E60} 
 * ===========================================================================*/
void UsCsm_GetCsmStateChnageReason(UsCsm_CsmStateChangeReason_Type *ptr_stateChangeReason)
{
	if(NULL_PTR_CSM_STATE_CHANHE_REASON != ptr_stateChangeReason)
	{
		*ptr_stateChangeReason = UsCsmStateChangeReason;
	}
}
#endif
