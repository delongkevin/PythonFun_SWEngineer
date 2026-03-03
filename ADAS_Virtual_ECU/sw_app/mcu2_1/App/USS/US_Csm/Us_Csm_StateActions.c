/** \file Us_Csm_Rules.c
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This files contains state actions function definations.
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"
#include "Us_Csm_IntModule.h"
#include "Us_Csm_Conf.h"
#include "SSM_Defs.h"
#include "US_ME_Typedefs_Global.h"
#include "VoltageCurrent_data.h"
#include "SignalDef.h"
#include "US_PlatformCfg_Global.h"
#include "US_Data_Typedefs_Global.h"


/************************************************************************************************************************
                                                            Imported data
************************************************************************************************************************/
extern UsCsm_CsmStateChangeReason_Type UsCsmStateChangeReason_Internal;

extern fPtr_LocalModuleReqState_Type UsCsm_GetFunPtrOfReqState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId);
extern fPtr_LocalModuleGetState_Type UsCsm_GetFunPtrOfGetState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId);
extern UsCsm_StdReturn_Type UsCsm_Internal_ReqState(UsCsm_StateId_Type reqUsCsmStateId, UsCsm_CsmStateChangeReason_Type *ptr_stateChangeReason);
extern UsCsm_StdReturn_Type UsCsm_IsAllLocalModuleStateSetTo(UsCsm_LocalStateId_Type stateId);
extern UsCsm_StdReturn_Type UsCsm_SetAllLocalModuleStateSetTo(UsCsm_LocalStateId_Type stateId);
extern UsCsm_StdReturn_Type UsCsm_Execute_StateActionSeq(UsCsm_LocalModuleStateSeqId_Type seqId);
extern UsCsm_StdReturn_Type UsCsm_Verify_StateActionSeq(UsCsm_LocalModuleStateSeqId_Type seqId);
extern UsCsm_StdReturn_Type UsCsm_IsAnyConfirmedError(void);
/* Header file included for this, to remove QAC parse error */
/* extern "C" {
	 void SigMgr_PpSR_State_MCU2_State_2_0_Get(SSM_2_0_CoreStatus *data);
}*/
extern void US_TurnOnUSSPower(bool on);
uint8_t US_CheckUSSPower(void);

#if(US_CSM_REPORT_INTERNAL_ERR == US_CSM_STD_ON)
extern void UsCsm_Report_CsmInternalError(UsCsm_CsmInternalErrId_Type csmIntErrId, UsCsm_LocalErrState_Type errState);
#endif
#if(US_D_CUR_PLATFORM != US_D_PLATFORM_CVADAS)
extern UsCsm_StdReturn_Type UsCsm_IsErrorActive(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId,
                                              UsCsm_LocalErrorId_Type errId);
extern UsCsm_StdReturn_Type UsCsm_IsErrorConfirmed(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId,
                                              UsCsm_LocalErrorId_Type errId);
extern UsCsm_StateId_Type UsCsm_GetState(void);
#endif

/************************************************************************************************************************
                                                            Local #defines
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Global Variables
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Local Variables
************************************************************************************************************************/
static uint8_t dsi3PowerOnStatusReq = ME_FALSE;
static uint32_t CsmStateRetryCnt = US_CSM_SATE_RETRY_CNT_UNINIT;
static uint32_t CsmStateTimeout  = US_CSM_SATE_TIMEOUT_IN_MS_UNINIT;
/************************************************************************************************************************
                                                            Global Functions
************************************************************************************************************************/
UsCsm_StdReturn_Type UsCsm_StateAction_DuringUninit(void);
UsCsm_StdReturn_Type UsCsm_StateAction_ExitUninit(void);
UsCsm_StdReturn_Type UsCsm_StateAction_ChangeStateOfLocalModuleToShutdown(void);
UsCsm_StdReturn_Type UsCsm_StateAction_ExitInit(void);
UsCsm_StdReturn_Type UsCsm_StateAction_IsStateOfLocalModuleToActive(void);
 UsCsm_StdReturn_Type UsCsm_StateAction_OnEntryInitState(void);
UsCsm_StdReturn_Type UsCsm_StateAction_DuringInitState(void);
UsCsm_StdReturn_Type UsCsm_StateAction_OnEntryPreSafeState1(void);
UsCsm_StdReturn_Type UsCsm_StateAction_DuringPreSafestate1(void);
UsCsm_StdReturn_Type UsCsm_StateAction_ExitPreSafestate1(void);
UsCsm_StdReturn_Type UsCsm_StateAction_OnEntryPreShutdown(void);
UsCsm_StdReturn_Type UsCsm_StateAction_DuringPreShutdown(void);
UsCsm_StdReturn_Type UsCsm_StateAction_DuringDegraded(void);


/************************************************************************************************************************
                                                            Local Functions
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Function Definations
************************************************************************************************************************/

/**
 * \brief 
 * 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_StateAction_DuringUninit    
 * Remarks:  DD-ID: {435B7205-27C1-49bf-A650-97A7CE3B5939}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_StateAction_DuringUninit(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;
	SSM_2_0_CoreStatus core_status;
	fPtr_LocalModuleReqState_Type fPre_LocalModuleReqState;
	fPtr_LocalModuleGetState_Type fPre_LocalModuleGetState;
	UsCsm_CsmStateChangeReason_Type UsCsmStateChangeReasonUninit =
	{
		.LocalModuleId = US_CSM_LOCAL_MODULE_ID_CSM,
		.InstanceId    = US_CSM_CSM_INSTANCE_ID_0,
		.LocalErrId    = (uint8_t)US_CSM_CSM_ERR_ID_STATE_TIME_OUT_UNINIT,
		.LocalErrState = US_CSM_LOCAL_ERR_STATE_CONFIRM,
	};

    (void)SigMgr_PpSR_State_MCU2_State_2_0_Get(&core_status);

	if(CsmStateRetryCnt > ((uint32_t)ZERO))
	{
		if(CsmStateTimeout > ((uint32_t)ZERO))
		{
			CsmStateTimeout--;
			
			/** Request local module state change to init*/	
			if (SSM_SlaveCore_State_BSP_Init_Done_i <= core_status.CoreStatus )
			{		
				fPre_LocalModuleGetState = UsCsm_GetFunPtrOfGetState(US_CSM_LOCAL_MODULE_ID_HSD);
				if((uint8_t)ME_FALSE == dsi3PowerOnStatusReq)
				{			
					if((US_CSM_LOCAL_STATE_IDLE == fPre_LocalModuleGetState(US_CSM_HSD_INSTANCE_ID_FRONT)) &&
					   (US_CSM_LOCAL_STATE_IDLE == fPre_LocalModuleGetState(US_CSM_HSD_INSTANCE_ID_REAR)))
					{
						fPre_LocalModuleReqState = UsCsm_GetFunPtrOfReqState(US_CSM_LOCAL_MODULE_ID_HSD);
						(void)fPre_LocalModuleReqState(US_CSM_HSD_INSTANCE_ID_FRONT,US_CSM_LOCAL_STATE_ACTIVE);
						(void)fPre_LocalModuleReqState(US_CSM_HSD_INSTANCE_ID_REAR,US_CSM_LOCAL_STATE_ACTIVE);
						dsi3PowerOnStatusReq = ME_TRUE;
					}		
				}

				if((US_CSM_LOCAL_STATE_ACTIVE == fPre_LocalModuleGetState(US_CSM_HSD_INSTANCE_ID_FRONT)) &&
				   (US_CSM_LOCAL_STATE_ACTIVE == fPre_LocalModuleGetState(US_CSM_HSD_INSTANCE_ID_REAR)))
				{
					(void)UsCsm_Internal_ReqState(US_CSM_STATE_ID_INIT, (UsCsm_CsmStateChangeReason_Type *)&UsCsmStateChangeReason_Internal);
				}

			}
		}
		else
		{
#if(US_CSM_REPORT_INTERNAL_ERR == US_CSM_STD_ON)
			UsCsm_Report_CsmInternalError((UsCsm_CsmInternalErrId_Type)US_CSM_CSM_ERR_ID_STATE_TIME_OUT_UNINIT, US_CSM_LOCAL_ERR_STATE_ACTIVE);
#endif		
			dsi3PowerOnStatusReq = ME_FALSE;
			CsmStateTimeout  = US_CSM_SATE_TIMEOUT_IN_MS_UNINIT;
			CsmStateRetryCnt--;
		}
	}
	else
	{
#if(US_CSM_REPORT_INTERNAL_ERR == US_CSM_STD_ON)
		UsCsm_Report_CsmInternalError((UsCsm_CsmInternalErrId_Type)US_CSM_CSM_ERR_ID_STATE_TIME_OUT_UNINIT, US_CSM_LOCAL_ERR_STATE_CONFIRM);
		(void)UsCsm_Internal_ReqState(US_CSM_STATE_ID_PRE_SAFE_STATE_1, (UsCsm_CsmStateChangeReason_Type *)&UsCsmStateChangeReasonUninit);
#endif
	}

	return (stdRet);
}

/**
 * \brief This function invoked on exit of uninit state.
 * 
 * \return UsCsm_StdReturn_Type 
 */
 /* ===========================================================================
 * Name: UsCsm_StateAction_ExitUninit    
 * Remarks:  DD-ID: {28F33A9A-ACCF-4c3c-9B05-A03CB3F59C87}
 * ===========================================================================*/
 UsCsm_StdReturn_Type UsCsm_StateAction_ExitUninit(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;

	/** Request local module state change to init*/	
	stdRet = UsCsm_Execute_StateActionSeq(US_CSM_LOCAL_STATE_SEQ_INIT);
	
	return (stdRet);
}


/**
 * \brief This function invoked on exit of init state.
 * 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_StateAction_ExitInit    
 * Remarks:  DD-ID: {5C6D06C1-1F00-4428-B9DF-C86E082EB0D1}
 * ===========================================================================*/
 UsCsm_StdReturn_Type UsCsm_StateAction_ExitInit(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;
	
	/** Request local module state change to active*/
	stdRet = UsCsm_SetAllLocalModuleStateSetTo(US_CSM_LOCAL_STATE_ACTIVE);
	
	return (stdRet);
}

#if(US_D_CUR_PLATFORM != US_D_PLATFORM_CVADAS)
/**
 * \brief This function checks if all local module state set to active.
 * 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_StateAction_IsStateOfLocalModuleToActive    
 * Remarks:  DD-ID: {96FB21F9-D643-4249-A42D-09C00C1DEB91}
 * ===========================================================================*/  
 UsCsm_StdReturn_Type UsCsm_StateAction_IsStateOfLocalModuleToActive(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;

    stdRet = UsCsm_IsAllLocalModuleStateSetTo(US_CSM_LOCAL_STATE_ACTIVE);

	return (stdRet);
}
#endif
/**
 * \brief This function checks if all local module state set to active.
 * 
 * \return UsCsm_StdReturn_Type 
 */
 /* ===========================================================================
 * Name:  UsCsm_StateAction_OnEntryInitState   
 * Remarks:  DD-ID: {244A4930-231B-47f2-844F-BA89FECACE30}
 * ===========================================================================*/
 UsCsm_StdReturn_Type UsCsm_StateAction_OnEntryInitState(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;

    CsmStateTimeout = US_CSM_SATE_TIMEOUT_IN_MS_INIT;

	return (stdRet);
}


/**
 * \brief This function checks if all local module state set to init.
 * \return UsCsm_StdReturn_Type 
 * \
 */
 /* ===========================================================================
 * Name: UsCsm_StateAction_DuringInitState    
 * Remarks:  DD-ID: {6233025C-2558-436d-BFDC-777034FA2ADA}
 * ===========================================================================*/
 UsCsm_StdReturn_Type UsCsm_StateAction_DuringInitState(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;

    stdRet = UsCsm_Verify_StateActionSeq(US_CSM_LOCAL_STATE_SEQ_INIT);

	if(US_CSM_STD_RET_OK == stdRet)
	{
		/*All uss sub modules are initialized move to csm to active state*/
		(void)UsCsm_Internal_ReqState(US_CSM_STATE_ID_ACTIVE, (UsCsm_CsmStateChangeReason_Type *)&UsCsmStateChangeReason_Internal);
	}
	else
	{
		if(CsmStateTimeout > ((uint32_t)ZERO))
		{
			CsmStateTimeout--;
		}
		else
		{

#if(US_CSM_REPORT_INTERNAL_ERR == US_CSM_STD_ON)
		UsCsm_Report_CsmInternalError((UsCsm_CsmInternalErrId_Type)US_CSM_CSM_ERR_ID_STATE_TIME_OUT_INIT, US_CSM_LOCAL_ERR_STATE_CONFIRM);
#endif

		}
	}

	return (stdRet);
}

/**
 * \brief This function set all local module state to shutdown.
 * 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name:  UsCsm_StateAction_ChangeStateOfLocalModuleToShutdown   
 * Remarks:  DD-ID: {C48113B5-B14F-4665-9FA5-138F7AC09821}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_StateAction_ChangeStateOfLocalModuleToShutdown(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;	

	stdRet = UsCsm_Execute_StateActionSeq(US_CSM_LOCAL_STATE_SEQ_SHUTDOWN);	

	return (stdRet);
}


/**
 * \brief This function set all local module state to shutdown.
 * 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name:  UsCsm_StateAction_OnEntryPreShutdown   
 * Remarks:  DD-ID: {2003AC00-0A64-476e-A3B2-6E94C696C909}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_StateAction_OnEntryPreShutdown(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;	

    CsmStateTimeout = US_CSM_SATE_TIMEOUT_IN_MS_SHUTDOWN;
    stdRet = UsCsm_StateAction_ChangeStateOfLocalModuleToShutdown();	

	return (stdRet);
}


/**
 * \brief This function gets invoked during pre shutdown state
 * 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_StateAction_DuringPreShutdown    
 * Remarks:  DD-ID: {81149776-6493-4415-B6AE-496F53005E88}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_StateAction_DuringPreShutdown(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;

    /*Check if all local modules are in shutdown state*/
	stdRet = UsCsm_Verify_StateActionSeq(US_CSM_LOCAL_STATE_SEQ_SHUTDOWN);

	if(US_CSM_STD_RET_OK == stdRet)
	{
		/*change csm state to active shutdown as all local module state has chnaged to shutdown*/
		(void)UsCsm_Internal_ReqState(US_CSM_STATE_ID_SHUTDOWN, NULL_PTR_CSM_STATE_CHANHE_REASON);
	}
	else
	{
		if(CsmStateTimeout > ((uint32_t)ZERO))
		{
			CsmStateTimeout--;
		}
		else
		{

#if(US_CSM_REPORT_INTERNAL_ERR == US_CSM_STD_ON)
		UsCsm_Report_CsmInternalError((UsCsm_CsmInternalErrId_Type)US_CSM_CSM_ERR_ID_STATE_TIME_OUT_SHUTDOWN, US_CSM_LOCAL_ERR_STATE_CONFIRM);
#endif

		}
	}

	return (stdRet);
}


/**
 * \brief This function set all local module state to shutdown.
 * 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_StateAction_OnEntryPreSafeState1    
 * Remarks:  DD-ID: {2477F9C9-8840-41db-8E2F-1CF97BC02027}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_StateAction_OnEntryPreSafeState1(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;	
	
    CsmStateTimeout = US_CSM_SATE_TIMEOUT_IN_MS_SAFE_STATE_1;
    stdRet = UsCsm_Execute_StateActionSeq(US_CSM_LOCAL_STATE_SEQ_SAFE_STATE_1);	

	return (stdRet);
}

/**
 * \brief This function gets invoked during pre safe state 1
 * 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_StateAction_DuringPreSafestate1    
 * Remarks:  DD-ID: {72C86BCF-5B6E-4028-9362-85E12296F525}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_StateAction_DuringPreSafestate1(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
    
	/*Check if all local modules are in shutdown state*/
	stdRet = UsCsm_Verify_StateActionSeq(US_CSM_LOCAL_STATE_SEQ_SAFE_STATE_1);
	
	if(US_CSM_STD_RET_OK == stdRet)
	{
		/*change csm state to active safe state 1 as all local module state has chnaged to shutdown*/
		(void)UsCsm_Internal_ReqState(US_CSM_STATE_ID_SAFE_STATE_1, NULL_PTR_CSM_STATE_CHANHE_REASON);
	}
	else
	{
		if(CsmStateTimeout > ((uint32_t)ZERO))
		{
			CsmStateTimeout--;
		}
		else
		{

#if(US_CSM_REPORT_INTERNAL_ERR == US_CSM_STD_ON)
		UsCsm_Report_CsmInternalError((UsCsm_CsmInternalErrId_Type)US_CSM_CSM_ERR_ID_STATE_TIME_OUT_SAFE_STATE_1, US_CSM_LOCAL_ERR_STATE_CONFIRM);
#endif

		}
	}

	return (stdRet);
}

#if(US_D_CUR_PLATFORM != US_D_PLATFORM_CVADAS)
/**
 * \brief This function inviked on exit of pre safe state-1
 * 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_StateAction_ExitPreSafestate1    
 * Remarks:  DD-ID: {FA6B4E9A-F9FB-413a-BC9D-70B611DB9DFC}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_StateAction_ExitPreSafestate1(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
	return (stdRet);
}
#endif

/**
 * \brief This function inviked during the degraded state
 * 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_StateAction_DuringDegraded    
 * Remarks:  DD-ID: {B37459D5-D3DB-4476-9753-88F6C4F26050}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_StateAction_DuringDegraded(void)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_OK;
	UsCsm_CsmStateChangeReason_Type stateChangeReason =
	{
		.LocalModuleId = US_CSM_LOCAL_MODULE_ID_CSM,
		.InstanceId    = US_CSM_CSM_INSTANCE_ID_0,
		.LocalErrId    = (UsCsm_CsmInternalErrId_Type)US_CSM_CSM_ERR_ID_STATE_DEGRADED_RECOVERY,
		.LocalErrState = US_CSM_LOCAL_ERR_STATE_PASSIVE,
	};

	/*Check if there are no any confirmed error, If no confirm error then change state to active,
	else remain in degraded state*/
	
	if(US_CSM_STD_RET_NOK ==  UsCsm_IsAnyConfirmedError())
	{
		/*as there are no any confirmed error from local module so change state to active*/
		(void)UsCsm_Internal_ReqState(US_CSM_STATE_ID_ACTIVE, &stateChangeReason);
	}

	return (stdRet);
}
