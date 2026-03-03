/** \file Us_ObjDet_CsmIf.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This file contains the error list which can be reported by object detection module.
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_CSM_LOCAL_MODULE_OBJ_DET_MNGR_H_
#define _US_CSM_LOCAL_MODULE_OBJ_DET_MNGR_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
/**
 * Number of instance of object detection manager module.
*/
#define US_CSM_OBJ_DET_MNGR_INSTANCE_ID_0   (UsCsm_InstanceId_Type)0
#define US_CSM_OBJ_DET_MNGR_INSTANCE_ID_MAX (UsCsm_InstanceId_Type)1

/**
 * \brief UsCsmErrId_ObjDetMngr_Type holds the error list reported by object detection module.
 * 
 */
typedef enum
{       
	US_CSM_OBJ_DET_MNGR_ERR_ID_BLOCKAGE_NONE = 0,
	US_CSM_OBJ_DET_MNGR_ERR_ID_MAX
}UsCsmErrId_ObjDetMngr_Type;


/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/
 UsCsm_StdReturn_Type Us_ObjDetMngr_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState);
 UsCsm_LocalStateId_Type Us_ObjDetMngr_GetState_Csm(UsCsm_InstanceId_Type instanceId);	

#endif