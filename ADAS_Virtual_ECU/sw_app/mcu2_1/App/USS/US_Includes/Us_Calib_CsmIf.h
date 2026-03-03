/** \file Us_Calib_CsmIf.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This file contains the error list which can be reported by calib module.
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_CSM_LOCAL_MODULE_CALIB_H_
#define _US_CSM_LOCAL_MODULE_CALIB_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
/**
 * Number of instance of calibration module.
*/
#define US_CSM_CALIB_INSTANCE_ID_0   (UsCsm_InstanceId_Type)0
#define US_CSM_CALIB_INSTANCE_ID_MAX (UsCsm_InstanceId_Type)1

#define ME_TEST_Us_CSM_CALIB_ERR_ID_CALIB_NOT_AVBL (US_CSM_STD_OFF)


/**
 * \brief UsCsmErrId_Calib_Type holds the error list reported by calibration module.
 * 
 */
typedef enum
{       
	US_CSM_CALIB_ERR_ID_SNR_CFG = 0,
    US_CSM_CALIB_ERR_ID_CALIB_NOT_AVBL,
	US_CSM_CALIB_ERR_ID_MAX
}UsCsmErrId_Calib_Type;


/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/
 UsCsm_StdReturn_Type Us_Calib_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState);
 UsCsm_LocalStateId_Type Us_Calib_GetState_Csm(UsCsm_InstanceId_Type instanceId);	

#endif