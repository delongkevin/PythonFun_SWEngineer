/** \file Us_Dsi3Trcv_CsmIf.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This file contains the error list which can be reported by dsi3 transreceiver module. 
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _Us_CSM_LOCAL_MODULE_DSI3_TRCV_H_
#define _Us_CSM_LOCAL_MODULE_DSI3_TRCV_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
/**
 * Number of instance of dsi3 transreceiver module.
*/
#define US_CSM_DSI3_TRCV_INSTANCE_ID_0   (UsCsm_InstanceId_Type)0
#define US_CSM_DSI3_TRCV_INSTANCE_ID_MAX (UsCsm_InstanceId_Type)1


/**
 * \brief UsCsmErrId_Dsi3Trcv_Type holds the error list reported by dsi3 transreceiver module.
 * 
 */
typedef enum
{       
	US_CSM_DSI3_TRCV_ERR_ID_RFC_ERR = 0,
    US_CSM_DSI3_TRCV_ERR_ID_VCCUV,
    US_CSM_DSI3_TRCV_ERR_ID_OT,
    US_CSM_DSI3_TRCV_ERR_ID_VDSIUV,
    US_CSM_DSI3_TRCV_ERR_ID_CLKREF,
    US_CSM_DSI3_TRCV_ERR_ID_SPI_RX_CRC,
    US_CSM_DSI3_TRCV_ERR_ID_DSI_UV_CH1,
    US_CSM_DSI3_TRCV_ERR_ID_DSI_UV_CH2,
    US_CSM_DSI3_TRCV_ERR_ID_DSI_OC_CH1,
    US_CSM_DSI3_TRCV_ERR_ID_DSI_OC_CH2,
    US_CSM_DSI3_TRCV_ERR_ID_DSI_PDCM_CRC_CH1,
    US_CSM_DSI3_TRCV_ERR_ID_DSI_PDCM_CRC_CH2,
    US_CSM_DSI3_TRCV_ERR_ID_DSI_CRM_CRC_CH1,
    US_CSM_DSI3_TRCV_ERR_ID_DSI_CRM_CRC_CH2,
    US_CSM_DSI3_TRCV_ERR_ID_RAM_BIST_FAIL,
    US_CSM_DSI3_TRCV_ERR_ID_DSI_FSM_RESET,
    US_CSM_DSI3_TRCV_ERR_ID_COMM_ERR,
    US_CSM_DSI3_TRCV_ERR_ID_REG_MISMATCH,
	US_CSM_DSI3_TRCV_ERR_ID_MAX
}UsCsmErrId_Dsi3Trcv_Type;


/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/
 UsCsm_StdReturn_Type Us_Dsi3Trcv_ReqState_Csm(UsCsm_InstanceId_Type instanceId, UsCsm_LocalStateId_Type reqState);
 UsCsm_LocalStateId_Type Us_Dsi3Trcv_GetState_Csm(UsCsm_InstanceId_Type instanceId);	

#endif