/** \file Us_SnrDrv_CsmIf.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This file contains the error list which can be reported by sensor driver module. 
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_CSM_LOCAL_MODULE_SNR_DRV_H_
#define _US_CSM_LOCAL_MODULE_SNR_DRV_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
/**
 * Number of instance of sensor driver module.
*/
#define US_CSM_SNR_DRV_INSTANCE_ID_0   (UsCsm_InstanceId_Type)0
#define US_CSM_SNR_DRV_INSTANCE_ID_MAX (UsCsm_InstanceId_Type)1


/**
 * \brief UsCsmErrId_Platform_Type holds the error list reported by sensor driver module.
 * 
 */
typedef enum
{       
    US_CSM_SNR_DRV_ERR_ID_SNR_1_FAULTS = 0U,
    US_CSM_SNR_DRV_ERR_ID_SNR_2_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_3_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_4_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_5_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_6_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_7_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_8_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_9_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_10_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_11_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_12_FAULTS,
	US_CSM_SNR_DRV_ERR_ID_MAX
}UsCsmErrId_SnrDrv_Type;


/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/
 UsCsm_StdReturn_Type Us_SnrDrv_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState);
 UsCsm_LocalStateId_Type Us_SnrDrv_GetState_Csm(UsCsm_InstanceId_Type instanceId);	

#endif