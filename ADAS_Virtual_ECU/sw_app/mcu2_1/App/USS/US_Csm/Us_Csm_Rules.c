/** \file Us_Csm_Rules.c
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This files contains the rules functions definations.
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


/************************************************************************************************************************
                                                            Imported data
************************************************************************************************************************/


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
UsCsm_StdReturn_Type UsCsm_Rule_CheckAndExecuteRule_AlwaysPass(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId,
										 UsCsm_LocalErrorId_Type UsCsmLocalErrorId,UsCsm_LocalErrState_Type UsCsmLocalErrState);

/************************************************************************************************************************
                                                            Local Functions
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Function Definations
************************************************************************************************************************/

/**
 * \brief This is the dummy rule which always return OK. This rule is configured for error which does not have any rule but action to
 * executed.
 * 
 * \param UsCsmLocalModuleId 
 * \param instanceId 
 * \param UsCsmLocalErrorId 
 * \param UsCsmLocalErrState 
 * \return UsCsm_StdReturn_Type 
 */
 /* ===========================================================================
 * Name: UsCsm_Rule_CheckAndExecuteRule_AlwaysPass    
 * Remarks:  DD-ID: {CBF440A0-A219-4257-99C3-966BE13804FE}
 * ===========================================================================*/
UsCsm_StdReturn_Type UsCsm_Rule_CheckAndExecuteRule_AlwaysPass(UsCsm_LocalModuleId_Type UsCsmLocalModuleId, UsCsm_InstanceId_Type instanceId,
										 UsCsm_LocalErrorId_Type UsCsmLocalErrorId,UsCsm_LocalErrState_Type UsCsmLocalErrState)
{
	(void)UsCsmLocalModuleId;
	(void)instanceId;
	(void)UsCsmLocalErrState;
	(void)UsCsmLocalErrorId;
	return (US_CSM_STD_RET_OK);
}
