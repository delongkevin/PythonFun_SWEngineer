/** \file Us_InterfaceMapping.h
 *  \version 1.00
 *  \date 2013-06-05
 *  \author Amol Gore (Amol.Gore\magna.com)
 *  \brief This file contains interface mapping for ipc, Can, callbacks etc. Any other mapping could added here
 *         This file is platform specific and will differ from platform to platform.
 *
 *  \copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 */

#ifndef _US_STUB_IF_MAP_H_
#define _US_STUB_IF_MAP_H_
/************************************************************************************************************************
                                                            Includes
************************************************************************************************************************/
#include "US_FeatureConf.h"

/************************************************************************************************************************
                                                            #defines
************************************************************************************************************************/
/**
 * List of output interface mapping
*/
#define UsStubOutput_WriteIf_PointDist             SigMgr_PpPointDistOpBuff_US_S_PointDistOutputBuff_t_Put
#define UsStubOutput_WriteIf_PointMap              SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Put
#define UsStubOutput_WriteIf_ZoneInfo              SigMgr_PpUssZoneInfo_US_S_ZoneInfo_t_Put
#define UsStubOutput_WriteIf_DirEcho               SigMgr_PpSnrDirEcho_US_S_SnrDirEcho_t_Put
#define UsStubOutput_WriteIf_BlockageBit           SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Put
#define UsStubOutput_WriteIf_ConstantData          SigMgr_PpUSSConstantData_US_S_USSConstantData_t_Put
#define UsStubOutput_WriteIf_PeriodDiagData        SigMgr_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t_Put
#define UsStubOutput_WriteIf_ErrorDiagData         SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Put
#define UsStubOutput_WriteIf_MarriageSnrId         SigMgr_PpUssMrrgData_US_S_MarriageSensorIDs_t_Put
#define UsStubOutput_WriteIf_DataCollection        SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_Put
#define UsStubOutput_WriteIf_CsmStateChangeReason  SigMgr_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type_Put
#define UsStubOutput_WriteIf_DebugMsg              SigMgr_PpUssDebugMsg_US_S_DebugMsg_t_Put
#define UsStubOutput_WriteIf_PntDebugData          SigMgr_PpPntDebugData_USS_S_PntDebugDataOutput_t_Put

/**
 * List of input interface mapping
 * 
 */
#define UsStubInput_ReadIf_MarriageSnrId    SigMgr_Data_US_S_MarriageSensorIDs_t_Get 
#define UsStubInput_ReadIf_CalibData        SigMgr_Data_USS_Calibration_Data_t_Get
#define UsStubInput_ReadIf_CalibData_2      SigMgr_Data_USS_Calibration_data_2_t_Get
#define UsStubInput_ReadIf_Proxy            SigMgr_Data_ME_ProxiToMCU2_1_Def_t_GetDataObjRef    
#define UsStubInput_ReadIf_IKinematicData   SigMgr_Data_IKinematicData_t_Get  
#define UsStubInput_ReadIf_UsPowerSelect    SigMgr_Data1_USS_PowerSelect_t_Get  
#define UsStubInput_ReadIf_TbAP_USSStateOut SigMgr_Data_TbAP_USSStateOut_t_Get  


/**
 * List of ref (data pointers) interface mapping
 * 
 */
#define UsStubOutput_RefIf_CalibData        SigMgr_Data_USS_Calibration_Data_t_GetDataObjRef
#define UsStubOutput_RefIf_CalibData_2      SigMgr_Data_USS_Calibration_data_2_t_GetDataObjRef

/**
 * List of callback registration
 * 
 */
#define UsStubCbk_RegisterCbk_VehicleInfo	 SigMgr_ME_VehInp_to_IpcSignals_data_f_RegisterCallback
#define UsStubCbk_RegisterCbk_ParkingMode	 SigMgr_Data_TbFA_USSStateOutput_t_RegisterCallback
#define UsStubCbk_RegisterCbk_CurrVoltValues SigMgr_Data_USS_Curr_Volt_Monitor_t_RegisterCallback
#define UsStubCbk_RegisterCbk_DataCollection SigMgr_PpUssDataCollection_US_S_USSDataCollectionData_t_RegisterCallback
#define UsStubCbk_RegisterCbk_DynamicCalData SigMgr_Data_UssTunningData_mcu1_0_t_RegisterCallback

#define TUNING_DATA_MAX_SIZE (3072u)

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