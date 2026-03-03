/** \file Us_FeatureConf.h
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

#ifndef _US_FEATURE_CONF_H_
#define _US_FEATURE_CONF_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
#define US_STD_OFF 0
#define US_STD_ON  1

#define US_FEATURE_OFF 0
#define US_FEATURE_ON  1

#define USS_FEATURE_POINT_MAP         US_STD_ON
#define USS_FEATURE_POINT_DIST        US_STD_ON
#define USS_FEATURE_ZONE_INFO         US_STD_OFF
#define USS_FEATURE_CSM_NOTIFICATION (US_FEATURE_ON)

#define USS_FEATURE_USS_IO_DATA_ON_CAN  US_STD_OFF /*USS data on CAN bus*/
#define USS_FEATURE_USS_IO_DATA_ON_ETH  US_STD_OFF /*USS data on ethernet bus*/
#define USS_FEATURE_USS_IO_DATA_ON_IPC  US_STD_ON  /*USS data on IPC*/
#define USS_FEATURE_USS_IO_DATA_ON_CBK  US_STD_OFF /*USS data on lib callback*/

#if(USS_FEATURE_POINT_MAP == US_STD_ON)
	#define USS_COM_DATA_SHARE_ENBL_POINT_MAP      US_STD_ON
#endif

#if(USS_FEATURE_POINT_DIST == US_STD_ON)
	#define USS_COM_DATA_SHARE_ENBL_POINT_DIST     US_STD_ON
#endif

#if(USS_FEATURE_ZONE_INFO == US_STD_ON)
	#define USS_COM_DATA_SHARE_ENBL_ZONE_INFO      US_STD_OFF
#endif

/***********************************************************START OF OUTPUT CONF***************************************/
#define USS_COM_DATA_SHARE_ENBL_FIRING_SNR         (US_STD_ON)
#define USS_COM_DATA_SHARE_ENBL_BLOCKAGE_FLAG      (US_STD_ON)
#define USS_COM_DATA_SHARE_ENBL_DIRECT_ECHO        (US_STD_ON)
#define USS_COM_DATA_SHARE_ENBL_MARRIAGE_SNR_ID    (US_STD_ON)
#define USS_COM_DATA_SHARE_ENBL_ERR_DIAG           (US_STD_ON)
#define USS_COM_DATA_SHARE_ENBL_PART_NO_VERSION    (US_STD_ON)
#define USS_COM_DATA_SHARE_ENBL_PERIODIC_DIAG      (US_STD_ON)
#define USS_COM_DATA_SHARE_ENBL_ODOMETRY_DATA      (US_STD_ON)  
#define USS_COM_DATA_SHARE_ENBL_DEBUG_SIGNAL       (US_STD_ON) 
#define USS_COM_DATA_SHARE_ENBL_POINT_DEBUG        (US_STD_ON) 
#define USS_COM_DATA_SHARE_ENBL_DATACOLLECTION     (US_STD_ON) 
#define USS_FEATURE_OUTPUT_CSM_STATE_CHANGE_REASON (US_FEATURE_ON) 
/***********************************************************END OF OUTPUT CONF****************************************/


/***********************************************************START OF HSD FEATURE CONF**********************************/
#define US_FEATURE_HSD_FAULT_DET_SHORT_TO_GND (US_FEATURE_OFF)
#define US_FEATURE_HSD_FAULT_DET_SHORT_TO_BAT (US_FEATURE_ON)
#define US_FEATURE_HSD_FAULT_DET_VTG_OOR_LOW  (US_FEATURE_ON)
#define US_FEATURE_HSD_FAULT_DET_VTG_OOR_HIGH (US_FEATURE_ON)
#define US_FEATURE_HSD_FAULT_DET_OPEN_CIRCUIT (US_FEATURE_OFF)
/***********************************************************END OF HSD FEATURE CONF************************************/


/***********************************************************START OF INPUT CONF****************************************/
#define USS_FEATURE_INPUT_PROCESS_AMBIENT_TEMP (US_FEATURE_ON)
#define USS_FEATURE_INPUT_PROCESS_VEH_SPEED    (US_FEATURE_ON)
#define USS_FEATURE_INPUT_PROCESS_GEAR         (US_FEATURE_ON)
/***********************************************************END OF INPUT CONF******************************************/




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