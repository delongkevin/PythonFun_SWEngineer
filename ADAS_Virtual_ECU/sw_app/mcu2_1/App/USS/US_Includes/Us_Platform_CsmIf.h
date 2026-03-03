/** \file Us_Platform_CsmIf.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This file contains the error list which can be reported by spi module.
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_CSM_LOCAL_MODULE_SPI_H_
#define _US_CSM_LOCAL_MODULE_SPI_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
/**
 * Number of instance of spi module.
*/
#define US_CSM_PLATFORM_INSTANCE_ID_0   (UsCsm_InstanceId_Type)0
#define US_CSM_PLATFORM_INSTANCE_ID_MAX (UsCsm_InstanceId_Type)1

/**
 * \brief UsCsmErrId_Platform_Type holds the error list reported by spi module.
 * 
 */
typedef enum
{        
	US_CSM_PLATFORM_ERR_ID_GPIO_INIT = 0U,
    US_CSM_PLATFORM_ERR_ID_DSI3REF_CLK_INIT,
    US_CSM_PLATFORM_ERR_ID_SPI_INIT,
    US_CSM_PLATFORM_ERR_ID_SPI_CRC,
    US_CSM_PLATFORM_ERR_ID_SPI_TX_FAIL,
	US_CSM_PLATFORM_ERR_ID_MAX
}UsCsmErrId_Platform_Type;

/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/
 UsCsm_StdReturn_Type Us_Platform_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState);
 UsCsm_LocalStateId_Type Us_Platform_GetState_Csm(UsCsm_InstanceId_Type instanceId);	

#endif