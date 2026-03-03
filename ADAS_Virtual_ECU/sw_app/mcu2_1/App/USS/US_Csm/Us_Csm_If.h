/** \file Us_Csm_If.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This file contains the list of functions which can be used by other applcation modules i.e upper layer
 * to <UsCsm>
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _Us_CSM_IF_H_
#define _Us_CSM_IF_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"
#include "Us_Csm_Conf.h"

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/


/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/
extern void UsCsm_Init(void);
extern void UsCsm_MainFunction(void);
extern UsCsm_StdReturn_Type UsCsm_ReqState(UsCsm_StateId_Type reqCsmStateId);
extern void UsCsm_ReportLocalError(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId,
                              UsCsm_LocalErrorId_Type UsCsmLocalErrorId,UsCsm_LocalErrState_Type UsCsmLocalErrState);

#if(US_CSM_ERROR_REPORT_UPPER_LAYER == US_CSM_STD_ON)
void UsCsm_Notification_Error(UsCsm_ErrorId_Type UsCsmErrorId);
#endif

#if(USS_FEATURE_CSM_NOTIFICATION == US_FEATURE_ON)
extern void UsCsm_Notification_CsmStateChange(UsCsm_StateId_Type currentState, UsCsm_StateId_Type prevState, UsCsm_CsmStateChangeReason_Type csmStateChangeReason);
#endif

#if(US_D_CUR_PLATFORM != US_D_PLATFORM_CVADAS)
extern void UsCsm_GetCsmStateChnageReason(UsCsm_CsmStateChangeReason_Type *ptr_stateChangeReason);
extern UsCsm_StateId_Type UsCsm_GetState(void);
extern UsCsm_LocalErrState_Type UsCsm_GetLocalErrorState(UsCsm_LocalModuleId_Type UsCsmLocalModuleId,UsCsm_InstanceId_Type instanceId,
                                              UsCsm_LocalErrorId_Type errId);

#endif
#endif
