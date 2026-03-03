/** \file Us_SnrCntrl_CsmIf.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This file contains the error list which can be reported by sensor control module.
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_CSM_LOCAL_MODULE_SNR_CNTRL_H_
#define _US_CSM_LOCAL_MODULE_SNR_CNTRL_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
/**
 * Number of instance of sensor control module.
*/
#define US_CSM_SNR_CNTRL_INSTANCE_ID_0   (UsCsm_InstanceId_Type)0
#define US_CSM_SNR_CNTRL_INSTANCE_ID_MAX (UsCsm_InstanceId_Type)1

/**
 * \brief UsCsmErrId_SnrCntrl_Type holds the error list reported by sensor control module.
 * 
 */
typedef enum
{       
	US_CSM_SNR_CNTRL_ERR_ID_NONE = 0,
	US_CSM_SNR_CNTRL_ERR_ID_MAX
}UsCsmErrId_SnrCntrl_Type;


/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/
 UsCsm_StdReturn_Type Us_SnrCntrl_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState);
 UsCsm_LocalStateId_Type Us_SnrCntrl_GetState_Csm(UsCsm_InstanceId_Type instanceId);	

#endif