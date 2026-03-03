/** \file Us_Hsd_CsmIf.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This file contains the error list which can be reported by high side driver module.
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_CSM_LOCAL_MODULE_HSD_H_
#define _US_CSM_LOCAL_MODULE_HSD_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
/**
 * Number of instance of high side driver module.
*/
#define US_CSM_HSD_INSTANCE_ID_FRONT (UsCsm_InstanceId_Type)0
#define US_CSM_HSD_INSTANCE_ID_REAR  (UsCsm_InstanceId_Type)1
#define US_CSM_HSD_INSTANCE_ID_MAX   (UsCsm_InstanceId_Type)2


/**
 * \brief UsCsmErrId_Hsd_Type holds the error list reported by high side driver module.
 * 
 */
typedef enum
{       
	US_CSM_HSD_ERR_ID_short_to_GND = 0,
	US_CSM_HSD_ERR_ID_voltage_OOR_Low,
	US_CSM_HSD_ERR_ID_Short_to_Bat,
	US_CSM_HSD_ERR_ID_voltage_OOR_High,
    US_CSM_HSD_ERR_ID_OpenCircuit,
	US_CSM_HSD_ERR_ID_MAX
}UsCsmErrId_Hsd_Type;


/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/
 UsCsm_StdReturn_Type Us_Hsd_ReqState_Csm(const UsCsm_InstanceId_Type instanceId,const UsCsm_LocalStateId_Type reqState);
 UsCsm_LocalStateId_Type Us_Hsd_GetState_Csm(const UsCsm_InstanceId_Type instanceId);	

#endif