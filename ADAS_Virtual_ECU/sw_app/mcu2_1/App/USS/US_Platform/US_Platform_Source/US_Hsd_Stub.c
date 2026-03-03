/*PRQA S 0292,3408,4424 EOF */
/** \file Us_Hsd_Stub.c
 *  \version 1.00
 *  \date 2023-10-18
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This files contain function definations of notification function invoked by HSD module. Functions from this
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
#include <stdint.h>
#include <stdio.h>
#include "US_HsdLocal.h"
#include "US_Hsd_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_Data_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_Platform_Global.h"
#include "US_ErrMgr_Global.h"

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_Hsd_CsmIf.h"
#endif


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
                                                            Local Variables/Constant
************************************************************************************************************************/
/**
 * \brief This constant structure holds mapping to error manager
 * 
 */
const US_E_ECUFaultReason_t errmapHsd[Uss_Hsd_Channel_Max][US_HSD_ERR_ID_MAX] = 
{
	{
		DIAG_FLAG_FRONT_BUMPER_SHRT_TO_GND,
		DIAG_FLAG_FRONT_BUMPER_OOR_LOW,
		DIAG_FLAG_FRONT_BUMPER_SHRT_TO_BAT,
		DIAG_FLAG_FRONT_BUMPER_OOR_HIGH,
		DIAG_FLAG_FRONT_BUMPER_OPEN,
	},
	{
		DIAG_FLAG_REAR_BUMPER_SHRT_TO_GND,
		DIAG_FLAG_REAR_BUMPER_OOR_LOW,
		DIAG_FLAG_REAR_BUMPER_SHRT_TO_BAT,
		DIAG_FLAG_REAR_BUMPER_OOR_HIGH,
		DIAG_FLAG_REAR_BUMPER_OPEN
	}
};

#if(US_CSM_ENABLE == ME_TRUE)
const UsCsmErrId_Hsd_Type CsmErrMapHsd[US_HSD_ERR_ID_MAX] = 
{
	US_CSM_HSD_ERR_ID_short_to_GND,
	US_CSM_HSD_ERR_ID_voltage_OOR_Low,
	US_CSM_HSD_ERR_ID_Short_to_Bat,
	US_CSM_HSD_ERR_ID_voltage_OOR_High,
    US_CSM_HSD_ERR_ID_OpenCircuit,
};
#endif


/************************************************************************************************************************
                                                            Global Functions
************************************************************************************************************************/
void UssHsd_Report_InternalError(uint8_t ChannelID,UsHsd_ErrId_Type errId, UsHsd_ErrState_Type errState);

/************************************************************************************************************************
                                                            Local Functions
************************************************************************************************************************/


/************************************************************************************************************************
                                                            Function Definations
************************************************************************************************************************/

/**
 * \brief This function report HSD internal errors
 * DD-ID: {D1EAE4F1-B793-4247-A39B-9A7F0F9D1E67}
 * \param ChannelID 
 * \param errId 
 * \param errState 
 */
/* ===========================================================================
	* Name:	 UssHsd_Report_InternalError
	* Remarks:  DD-ID: {E578249C-491A-4839-9E9B-9B0116DD912F}
	* ===========================================================================*/
void UssHsd_Report_InternalError(uint8_t ChannelID,UsHsd_ErrId_Type errId, UsHsd_ErrState_Type errState)
{
	if((ChannelID < (uint8_t)Uss_Hsd_Channel_Max) && (US_HSD_ERR_ID_MAX > errId))
	{
		switch(errState)
		{
			case US_HSD_ERR_STATE_CONFIRM:
			UssErrMgr_UpdateECUDiagFlagStatus(errmapHsd[ChannelID][errId], ME_TRUE);
#if(US_CSM_ENABLE == ME_TRUE)
			UsCsm_ReportLocalError(US_CSM_LOCAL_MODULE_ID_HSD,(UsCsm_InstanceId_Type) ChannelID, CsmErrMapHsd[errId], US_CSM_LOCAL_ERR_STATE_CONFIRM);
#endif
			break;

			case US_HSD_ERR_STATE_PASSIVE:
			UssErrMgr_UpdateECUDiagFlagStatus(errmapHsd[ChannelID][errId], ME_FALSE);
#if(US_CSM_ENABLE == ME_TRUE)
			UsCsm_ReportLocalError(US_CSM_LOCAL_MODULE_ID_HSD, (UsCsm_InstanceId_Type)ChannelID, CsmErrMapHsd[errId], US_CSM_LOCAL_ERR_STATE_PASSIVE);
#endif
			break;

			case US_HSD_ERR_STATE_ACTIVE:
			break;

			default: /*empty */
			break;
		}
	}
	else
	{
		;/* No Action */
	}
}
