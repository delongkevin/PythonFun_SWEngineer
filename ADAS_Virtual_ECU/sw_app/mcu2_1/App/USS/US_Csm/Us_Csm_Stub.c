/** \file Us_Csm_Rules.c
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This files contain function definations of notification function invoked by csm module. Functions from this
 * files are optional and application can defines these functions in required application modules. 
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_If.h"
#include "US_Diagnostic_Global.h"

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
#if(US_CSM_REPORT_INTERNAL_ERR == US_CSM_STD_ON)
void UsCsm_Report_CsmInternalError(UsCsm_CsmInternalErrId_Type csmIntErrId, UsCsm_LocalErrState_Type errState);
#endif

/************************************************************************************************************************
                                                            Local Functions
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Function Definations
************************************************************************************************************************/
#if(US_CSM_STUB == US_CSM_STD_ON)
#if(US_CSM_ERROR_REPORT_UPPER_LAYER == US_CSM_STD_ON)
/**
 * \brief This function invoked by csm module, whenever confirmed error is reported by Us modules.
 * 
 * \param UsCsmErrorId This error Id encoded by module Id(Bits 15-12) and local error id (Bits 11-0)
 */
void UsCsm_Notification_Error(UsCsm_ErrorId_Type UsCsmErrorId)
{
	(void)UsCsmErrorId;
}
#endif/*US_CSM_ERROR_REPORT_UPPER_LAYER*/


#if(US_CSM_REPORT_INTERNAL_ERR == US_CSM_STD_ON)
/**
 * \brief This function invoked when csm detect internal error within csm handing.
 * 
 * \param csmIntErrId 
 */
/* ===========================================================================
 * Name: UsCsm_Report_CsmInternalError    
 * Remarks:  DD-ID: {F4143AD8-A346-4870-A977-81600F1DDD9B}
 * ===========================================================================*/
void UsCsm_Report_CsmInternalError(UsCsm_CsmInternalErrId_Type csmIntErrId, UsCsm_LocalErrState_Type errState)
{
    if((UsCsm_CsmInternalErrId_Type)US_CSM_CSM_ERR_ID_STATE_TIME_OUT_UNINIT == csmIntErrId)
    {
        if((US_CSM_LOCAL_ERR_STATE_ACTIVE == errState) || (US_CSM_LOCAL_ERR_STATE_CONFIRM == errState))
        {
            US_Diagnostic_SetECUFlag(DIAG_FLAG_ECU_USS_POWER_ON_ERR);
        }
        else
        {
           US_Diagnostic_ClrECUFlag(DIAG_FLAG_ECU_USS_POWER_ON_ERR);
        }
    }
    else
    {
        /*Report error to self*/
        UsCsm_ReportLocalError(US_CSM_LOCAL_MODULE_ID_CSM, US_CSM_CSM_INSTANCE_ID_0, csmIntErrId, errState);
    }
}
#endif /*US_CSM_REPORT_INTERNAL_ERR*/
#endif /*US_CSM_STUB*/
