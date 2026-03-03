/** \file Us_Csm_Conf.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief 
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_CSM_CONF_H_
#define _US_CSM_CONF_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "Us_Csm_Types.h"
#include "US_FeatureConf.h"
/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
#define US_CSM_ERROR_REPORT_UPPER_LAYER (US_CSM_STD_OFF)
#define US_CSM_EXECUTE_ACTION           (US_CSM_STD_ON)
#define US_CSM_STUB                     (US_CSM_STD_ON)
#define US_CSM_REPORT_INTERNAL_ERR      (US_CSM_STD_ON)

#define US_CSM_LOCAL_MODULE_ID_CSM          (0U) /*Self*/
#define US_CSM_LOCAL_MODULE_ID_PLATFORM     (1U)
#define US_CSM_LOCAL_MODULE_ID_HSD          (2U)
#define US_CSM_LOCAL_MODULE_ID_DSI3_TRCV    (3U)
#define US_CSM_LOCAL_MODULE_ID_SNR_DRV      (4U)
#define US_CSM_LOCAL_MODULE_ID_SNR_CNTRL    (5U)
#define US_CSM_LOCAL_MODULE_ID_OBJ_DET_MNGR (6U)
#define US_CSM_LOCAL_MODULE_ID_CALIB        (7U)
#define US_CSM_LOCAL_MODULE_ID_MAX          (8U)

#define US_CSM_LOCAL_MODULE_ID_UP_LAYER          (254U)
#define US_CSM_LOCAL_MODULE_INSTANCE_ID_DEAFULT  (255U)
#define US_CSM_LOCAL_MODULE_ERR_ID_INT_DEAFULT   (255U)

#define US_CSM_CSM_INSTANCE_ID_0   (UsCsm_InstanceId_Type)0
#define US_CSM_CSM_INSTANCE_ID_MAX (UsCsm_InstanceId_Type)1

/**List of error from csm internal*/
typedef enum
{
    US_CSM_CSM_ERR_ID_STATE_TIME_OUT_UNINIT = (0U),
    US_CSM_CSM_ERR_ID_STATE_TIME_OUT_INIT,
    US_CSM_CSM_ERR_ID_STATE_TIME_OUT_ACTIVE ,
    US_CSM_CSM_ERR_ID_STATE_TIME_OUT_DEGRADED ,
    US_CSM_CSM_ERR_ID_STATE_TIME_OUT_SAFE_STATE_1,
    US_CSM_CSM_ERR_ID_STATE_TIME_OUT_SHUTDOWN,
    US_CSM_CSM_ERR_ID_STATE_DEGRADED_RECOVERY,
    US_CSM_CSM_ERR_ID_MAX
}UsCsmErrId_Csm_Type;

/*List of timeout of values for csm states*/
#define US_CSM_SATE_MAIN_FUNCTION_BAST_TIME_IN_MS (10U)
#define US_CSM_SATE_TIMEOUT_IN_MS_UNINIT       (100U / US_CSM_SATE_MAIN_FUNCTION_BAST_TIME_IN_MS) /** currently core up time is more than 60sec*/
#define US_CSM_SATE_TIMEOUT_IN_MS_INIT         (250U / US_CSM_SATE_MAIN_FUNCTION_BAST_TIME_IN_MS)
#define US_CSM_SATE_TIMEOUT_IN_MS_ACTIVE       (250U / US_CSM_SATE_MAIN_FUNCTION_BAST_TIME_IN_MS)
#define US_CSM_SATE_TIMEOUT_IN_MS_DEGRADED     (250U / US_CSM_SATE_MAIN_FUNCTION_BAST_TIME_IN_MS)
#define US_CSM_SATE_TIMEOUT_IN_MS_SAFE_STATE_1 (250U / US_CSM_SATE_MAIN_FUNCTION_BAST_TIME_IN_MS)
#define US_CSM_SATE_TIMEOUT_IN_MS_SHUTDOWN     (250U / US_CSM_SATE_MAIN_FUNCTION_BAST_TIME_IN_MS)

#define US_CSM_SATE_RETRY_CNT_UNINIT (200U)

/************************************************************************************************************************
                                                            #typedef
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Variables(optional)
************************************************************************************************************************/


/************************************************************************************************************************
                                                            extern Functions(optional)
************************************************************************************************************************/


#endif