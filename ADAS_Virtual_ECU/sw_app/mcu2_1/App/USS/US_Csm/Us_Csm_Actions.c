/** \file Us_Csm_Rules.c
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This files contains functions those performs actions on error reporting.
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
#include "US_Data_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"


/************************************************************************************************************************
                                                            Imported data
************************************************************************************************************************/
extern fPtr_LocalModuleReqState_Type UsCsm_GetFunPtrOfReqState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId);
extern fPtr_LocalModuleGetState_Type UsCsm_GetFunPtrOfGetState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId);
extern UsCsm_StdReturn_Type UsCsm_Internal_ReqState(UsCsm_StateId_Type UsCsmStateId, UsCsm_CsmStateChangeReason_Type *ptr_stateChangeReason);
#if(US_D_CUR_PLATFORM != US_D_PLATFORM_CVADAS)
extern UsCsm_StateId_Type UsCsm_GetState(void);
extern UsCsm_StdReturn_Type UsCsm_IsErrorActive(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId,
                                              UsCsm_LocalErrorId_Type errId);
extern UsCsm_StdReturn_Type UsCsm_IsErrorConfirmed(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId,
                                              UsCsm_LocalErrorId_Type errId);
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


/************************************************************************************************************************
                                                            Global Functions
************************************************************************************************************************/
UsCsm_StdReturn_Type UsCsm_Action_Degraded(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId,
										 UsCsm_LocalErrorId_Type UsCsmLocalErrorId,UsCsm_LocalErrState_Type UsCsmLocalErrState);
UsCsm_StdReturn_Type UsCsm_Action_SafeState1(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId,
										 UsCsm_LocalErrorId_Type UsCsmLocalErrorId,UsCsm_LocalErrState_Type UsCsmLocalErrState);

/************************************************************************************************************************
                                                            Local Functions
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Function Definations
************************************************************************************************************************/

/**
 * \brief 
 * 
 * \param UsCsmLocalModuleId 
 * \param instanceId 
 * \param UsCsmLocalErrorId 
 * \param UsCsmLocalErrState 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_Action_Degraded
 * Remarks:  DD-ID:{43DA0264-1E0A-44c3-A409-381D75B533B6}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_Action_Degraded(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId,
										 UsCsm_LocalErrorId_Type UsCsmLocalErrorId,UsCsm_LocalErrState_Type UsCsmLocalErrState)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
	UsCsm_CsmStateChangeReason_Type stateChangeReason;

	if(US_CSM_LOCAL_ERR_STATE_CONFIRM == UsCsmLocalErrState)
	{
		stateChangeReason.LocalModuleId = UsCsmLocalModuleId;
		stateChangeReason.InstanceId = instanceId;
		stateChangeReason.LocalErrId = UsCsmLocalErrorId;
		stateChangeReason.LocalErrState = UsCsmLocalErrState;

		(void)UsCsm_Internal_ReqState(US_CSM_STATE_ID_DEGRADED, &stateChangeReason);
		stdRet = US_CSM_STD_RET_OK;
	}
	return (stdRet);
}


/**
 * \brief 
 * 
 * \param UsCsmLocalModuleId 
 * \param instanceId 
 * \param UsCsmLocalErrorId 
 * \param UsCsmLocalErrState 
 * \return UsCsm_StdReturn_Type 
 */
/* ===========================================================================
 * Name: UsCsm_Action_SafeState1	
 * Remarks:  DD-ID: {577CF1A6-4777-4f3f-92BD-09FC2D350E89}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_Action_SafeState1(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId,
										 UsCsm_LocalErrorId_Type UsCsmLocalErrorId,UsCsm_LocalErrState_Type UsCsmLocalErrState)
{
	UsCsm_StdReturn_Type stdRet = US_CSM_STD_RET_NOK;
	UsCsm_CsmStateChangeReason_Type stateChangeReason;

	if(US_CSM_LOCAL_ERR_STATE_CONFIRM == UsCsmLocalErrState)
	{
		stateChangeReason.LocalModuleId = UsCsmLocalModuleId;
		stateChangeReason.InstanceId = instanceId;
		stateChangeReason.LocalErrId = UsCsmLocalErrorId;
		stateChangeReason.LocalErrState = UsCsmLocalErrState;

		(void)UsCsm_Internal_ReqState(US_CSM_STATE_ID_PRE_SAFE_STATE_1, &stateChangeReason);
		stdRet = US_CSM_STD_RET_OK;
	}
	return (stdRet);
}
