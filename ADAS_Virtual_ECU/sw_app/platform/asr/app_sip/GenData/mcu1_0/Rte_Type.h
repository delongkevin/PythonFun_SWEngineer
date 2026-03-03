/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/* double include prevention */
#ifndef RTE_TYPE_H
# define RTE_TYPE_H

# include "Rte.h"
# ifdef RTE_CORE
/**********************************************************************************************************************
 * Type definitions for mode management
 *********************************************************************************************************************/
typedef EventMaskType Rte_EventMaskType;
# endif /* defined(RTE_CORE) */

/* PRQA S 1039 EOF */ /* MD_Rte_1039 */

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

# define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

# define Rte_TypeDef_ChangeSYSState_t
typedef uint16 ChangeSYSState_t;

# define Rte_TypeDef_SystemState
typedef uint8 SystemState;

# define Rte_TypeDef_AdditionalData_arr
typedef uint8 AdditionalData_arr[4];

# define Rte_TypeDef_Arr_20Byte
typedef uint8 Arr_20Byte[20];

# define Rte_TypeDef_Arr_2Byte
typedef uint8 Arr_2Byte[2];

# define Rte_TypeDef_Array_04Byte
typedef uint8 Array_04Byte[4];

# define Rte_TypeDef_Array_10Byte
typedef uint8 Array_10Byte[10];

# define Rte_TypeDef_Array_11Byte
typedef uint8 Array_11Byte[11];

# define Rte_TypeDef_Array_15Bytes
typedef uint8 Array_15Bytes[15];

# define Rte_TypeDef_DID_F110_Pin_Arr
typedef uint8 DID_F110_Pin_Arr[6];

# define Rte_TypeDef_DataArrayType_uint8_1
typedef uint8 DataArrayType_uint8_1[1];

# define Rte_TypeDef_DataArrayType_uint8_2
typedef uint8 DataArrayType_uint8_2[2];

# define Rte_TypeDef_DataArrayType_uint8_3
typedef uint8 DataArrayType_uint8_3[3];

# define Rte_TypeDef_DataArrayType_uint8_9
typedef uint8 DataArrayType_uint8_9[9];

# define Rte_TypeDef_Dcm_Data1056ByteType
typedef uint8 Dcm_Data1056ByteType[1056];

# define Rte_TypeDef_Dcm_Data10ByteType
typedef uint8 Dcm_Data10ByteType[10];

# define Rte_TypeDef_Dcm_Data11ByteType
typedef uint8 Dcm_Data11ByteType[11];

# define Rte_TypeDef_Dcm_Data1296ByteType
typedef uint8 Dcm_Data1296ByteType[1296];

# define Rte_TypeDef_Dcm_Data12ByteType
typedef uint8 Dcm_Data12ByteType[12];

# define Rte_TypeDef_Dcm_Data138ByteType
typedef uint8 Dcm_Data138ByteType[138];

# define Rte_TypeDef_Dcm_Data13ByteType
typedef uint8 Dcm_Data13ByteType[13];

# define Rte_TypeDef_Dcm_Data14ByteType
typedef uint8 Dcm_Data14ByteType[14];

# define Rte_TypeDef_Dcm_Data15ByteType
typedef uint8 Dcm_Data15ByteType[15];

# define Rte_TypeDef_Dcm_Data16ByteType
typedef uint8 Dcm_Data16ByteType[16];

# define Rte_TypeDef_Dcm_Data176ByteType
typedef uint8 Dcm_Data176ByteType[176];

# define Rte_TypeDef_Dcm_Data17ByteType
typedef uint8 Dcm_Data17ByteType[17];

# define Rte_TypeDef_Dcm_Data19ByteType
typedef uint8 Dcm_Data19ByteType[19];

# define Rte_TypeDef_Dcm_Data1ByteType
typedef uint8 Dcm_Data1ByteType[1];

# define Rte_TypeDef_Dcm_Data200ByteType
typedef uint8 Dcm_Data200ByteType[200];

# define Rte_TypeDef_Dcm_Data20ByteType
typedef uint8 Dcm_Data20ByteType[20];

# define Rte_TypeDef_Dcm_Data21ByteType
typedef uint8 Dcm_Data21ByteType[21];

# define Rte_TypeDef_Dcm_Data24ByteType
typedef uint8 Dcm_Data24ByteType[24];

# define Rte_TypeDef_Dcm_Data255ByteType
typedef uint8 Dcm_Data255ByteType[255];

# define Rte_TypeDef_Dcm_Data256ByteType
typedef uint8 Dcm_Data256ByteType[256];

# define Rte_TypeDef_Dcm_Data28ByteType
typedef uint8 Dcm_Data28ByteType[28];

# define Rte_TypeDef_Dcm_Data2ByteType
typedef uint8 Dcm_Data2ByteType[2];

# define Rte_TypeDef_Dcm_Data306ByteType
typedef uint8 Dcm_Data306ByteType[306];

# define Rte_TypeDef_Dcm_Data3072ByteType
typedef uint8 Dcm_Data3072ByteType[3072];

# define Rte_TypeDef_Dcm_Data32ByteType
typedef uint8 Dcm_Data32ByteType[32];

# define Rte_TypeDef_Dcm_Data34ByteType
typedef uint8 Dcm_Data34ByteType[34];

# define Rte_TypeDef_Dcm_Data352ByteType
typedef uint8 Dcm_Data352ByteType[352];

# define Rte_TypeDef_Dcm_Data37ByteType
typedef uint8 Dcm_Data37ByteType[37];

# define Rte_TypeDef_Dcm_Data3ByteType
typedef uint8 Dcm_Data3ByteType[3];

# define Rte_TypeDef_Dcm_Data40ByteType
typedef uint8 Dcm_Data40ByteType[40];

# define Rte_TypeDef_Dcm_Data41ByteType
typedef uint8 Dcm_Data41ByteType[41];

# define Rte_TypeDef_Dcm_Data42ByteType
typedef uint8 Dcm_Data42ByteType[42];

# define Rte_TypeDef_Dcm_Data43ByteType
typedef uint8 Dcm_Data43ByteType[43];

# define Rte_TypeDef_Dcm_Data44ByteType
typedef uint8 Dcm_Data44ByteType[44];

# define Rte_TypeDef_Dcm_Data48ByteType
typedef uint8 Dcm_Data48ByteType[48];

# define Rte_TypeDef_Dcm_Data4ByteType
typedef uint8 Dcm_Data4ByteType[4];

# define Rte_TypeDef_Dcm_Data50ByteType
typedef uint8 Dcm_Data50ByteType[50];

# define Rte_TypeDef_Dcm_Data52ByteType
typedef uint8 Dcm_Data52ByteType[52];

# define Rte_TypeDef_Dcm_Data54ByteType
typedef uint8 Dcm_Data54ByteType[54];

# define Rte_TypeDef_Dcm_Data5ByteType
typedef uint8 Dcm_Data5ByteType[5];

# define Rte_TypeDef_Dcm_Data64ByteType
typedef uint8 Dcm_Data64ByteType[64];

# define Rte_TypeDef_Dcm_Data66ByteType
typedef uint8 Dcm_Data66ByteType[66];

# define Rte_TypeDef_Dcm_Data6ByteType
typedef uint8 Dcm_Data6ByteType[6];

# define Rte_TypeDef_Dcm_Data71ByteType
typedef uint8 Dcm_Data71ByteType[71];

# define Rte_TypeDef_Dcm_Data8ByteType
typedef uint8 Dcm_Data8ByteType[8];

# define Rte_TypeDef_Dcm_Data90ByteType
typedef uint8 Dcm_Data90ByteType[90];

# define Rte_TypeDef_Dcm_Data960ByteType
typedef uint8 Dcm_Data960ByteType[960];

# define Rte_TypeDef_Dcm_Data96ByteType
typedef uint8 Dcm_Data96ByteType[96];

# define Rte_TypeDef_Dcm_Data9ByteType
typedef uint8 Dcm_Data9ByteType[9];

# define Rte_TypeDef_Dcm_StartFlexibleOutArrayData_Routine_3101D002_Check_Programming_Preconditions_Start_Out_ResDataType
typedef uint8 Dcm_StartFlexibleOutArrayData_Routine_3101D002_Check_Programming_Preconditions_Start_Out_ResDataType[256];

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[51];

# define Rte_TypeDef_DistanceToClosestPoint_Array
typedef float32 DistanceToClosestPoint_Array[2];

# define Rte_TypeDef_EOLIterationData_arr
typedef uint8 EOLIterationData_arr[5];

# define Rte_TypeDef_ErrorListArr_B
typedef uint32 ErrorListArr_B[35];

# define Rte_TypeDef_ErrorListArr_QM
typedef uint32 ErrorListArr_QM[1];

# define Rte_TypeDef_FD14_Log_Sensor_Temperature
typedef uint8 FD14_Log_Sensor_Temperature[8];

# define Rte_TypeDef_FD14_Log_SnrMeasData_1
typedef uint8 FD14_Log_SnrMeasData_1[8];

# define Rte_TypeDef_FD14_Log_SnrMeasData_2
typedef uint8 FD14_Log_SnrMeasData_2[8];

# define Rte_TypeDef_FD14_Log_SnrMeasData_3
typedef uint8 FD14_Log_SnrMeasData_3[8];

# define Rte_TypeDef_FD14_Log_SnrMeasData_4
typedef uint8 FD14_Log_SnrMeasData_4[8];

# define Rte_TypeDef_FD14_Log_SnrMeasData_5
typedef uint8 FD14_Log_SnrMeasData_5[8];

# define Rte_TypeDef_FD14_Log_SnrMeasData_6
typedef uint8 FD14_Log_SnrMeasData_6[8];

# define Rte_TypeDef_FD14_Log_SnrMeasData_7
typedef uint8 FD14_Log_SnrMeasData_7[8];

# define Rte_TypeDef_FD14_MAC_ADAS_FD_LANES_1
typedef uint8 FD14_MAC_ADAS_FD_LANES_1[6];

# define Rte_TypeDef_FD14_MAC_ADAS_FD_LANES_2
typedef uint8 FD14_MAC_ADAS_FD_LANES_2[6];

# define Rte_TypeDef_FD14_Pntdebugdata_0
typedef uint8 FD14_Pntdebugdata_0[8];

# define Rte_TypeDef_FD14_Pntdebugdata_1
typedef uint8 FD14_Pntdebugdata_1[8];

# define Rte_TypeDef_FD14_Pntdebugdata_2
typedef uint8 FD14_Pntdebugdata_2[8];

# define Rte_TypeDef_FD14_Pntdebugdata_3
typedef uint8 FD14_Pntdebugdata_3[8];

# define Rte_TypeDef_FD14_macCvpamFdData1_u64
typedef uint8 FD14_macCvpamFdData1_u64[8];

# define Rte_TypeDef_FIDOutputArr_B
typedef uint32 FIDOutputArr_B[2];

# define Rte_TypeDef_FIDOutputArr_QM
typedef uint32 FIDOutputArr_QM[1];

# define Rte_TypeDef_K_Overlap_Thrsld_RAEB_Array
typedef float32 K_Overlap_Thrsld_RAEB_Array[5];

# define Rte_TypeDef_Log_PackedDiagFlagData1_v_Array
typedef uint8 Log_PackedDiagFlagData1_v_Array[64];

# define Rte_TypeDef_Log_PackedDiagFlagData2_v_Array
typedef uint8 Log_PackedDiagFlagData2_v_Array[64];

# define Rte_TypeDef_Log_PackedNoiseMeasData_Array
typedef uint8 Log_PackedNoiseMeasData_Array[64];

# define Rte_TypeDef_Log_SnrMeasData1_Array
typedef uint8 Log_SnrMeasData1_Array[64];

# define Rte_TypeDef_Log_SnrMeasData2_Array
typedef uint8 Log_SnrMeasData2_Array[64];

# define Rte_TypeDef_Log_SnrMeasData3_Array
typedef uint8 Log_SnrMeasData3_Array[64];

# define Rte_TypeDef_Log_SnrMeasData4_Array
typedef uint8 Log_SnrMeasData4_Array[64];

# define Rte_TypeDef_Log_SnrMeasData5_Array
typedef uint8 Log_SnrMeasData5_Array[64];

# define Rte_TypeDef_Log_SnrMeasData6_Array
typedef uint8 Log_SnrMeasData6_Array[64];

# define Rte_TypeDef_Log_SnrMeasData7_Array
typedef uint8 Log_SnrMeasData7_Array[64];

# define Rte_TypeDef_Log_SnrTemperature_Array
typedef sint16 Log_SnrTemperature_Array[32];

# define Rte_TypeDef_MAC_ADAS_FD_LANES_1
typedef uint8 MAC_ADAS_FD_LANES_1[6];

# define Rte_TypeDef_MAC_ADAS_FD_LANES_2
typedef uint8 MAC_ADAS_FD_LANES_2[6];

# define Rte_TypeDef_MpuFltSts
typedef uint8 MpuFltSts[2];

# define Rte_TypeDef_N_PDU
typedef uint8 N_PDU[8];

# define Rte_TypeDef_Obj_DistTable_Array
typedef float32 Obj_DistTable_Array[5];

# define Rte_TypeDef_ObjectDimensions_Array
typedef float32 ObjectDimensions_Array[2];

# define Rte_TypeDef_PmicStatus
typedef uint8 PmicStatus[8];

# define Rte_TypeDef_ProxiErrData_Arr
typedef uint8 ProxiErrData_Arr[3];

# define Rte_TypeDef_Proxi_255byte
typedef uint8 Proxi_255byte[255];

# define Rte_TypeDef_RESOutputArr_B
typedef uint32 RESOutputArr_B[1];

# define Rte_TypeDef_RESOutputArr_QM
typedef uint32 RESOutputArr_QM[1];

# define Rte_TypeDef_RLDFeatureCountInSubRois_Array
typedef sint32 RLDFeatureCountInSubRois_Array[2];

# define Rte_TypeDef_Reserved_arr
typedef uint8 Reserved_arr[7];

# define Rte_TypeDef_Rte_DT_RunTimeStats_MCU2_0_t_0
typedef uint32 Rte_DT_RunTimeStats_MCU2_0_t_0[10];

# define Rte_TypeDef_Rte_DT_RunTimeStats_MCU2_0_t_1
typedef uint32 Rte_DT_RunTimeStats_MCU2_0_t_1[6];

# define Rte_TypeDef_Rte_DT_RunTimeStats_MCU2_1_t_0
typedef uint32 Rte_DT_RunTimeStats_MCU2_1_t_0[14];

# define Rte_TypeDef_Rte_DT_RunTimeStats_MCU2_1_t_1
typedef uint32 Rte_DT_RunTimeStats_MCU2_1_t_1[4];

# define Rte_TypeDef_Rte_DT_RunTimeStats_MCU2_1_t_2
typedef uint32 Rte_DT_RunTimeStats_MCU2_1_t_2[4];

# define Rte_TypeDef_Rte_DT_SecureLogRecord_t_4_0
typedef uint8 Rte_DT_SecureLogRecord_t_4_0[48];

# define Rte_TypeDef_Rte_DT_StackUsage_MCU2_0_t_0
typedef uint8 Rte_DT_StackUsage_MCU2_0_t_0[5];

# define Rte_TypeDef_Rte_DT_StackUsage_MCU2_0_t_1
typedef uint8 Rte_DT_StackUsage_MCU2_0_t_1[3];

# define Rte_TypeDef_Rte_DT_StackUsage_MCU2_1_t_0
typedef uint8 Rte_DT_StackUsage_MCU2_1_t_0[6];

# define Rte_TypeDef_Rte_DT_StackUsage_MCU2_1_t_1
typedef uint8 Rte_DT_StackUsage_MCU2_1_t_1[2];

# define Rte_TypeDef_Rte_DT_StackUsage_MCU2_1_t_2
typedef uint8 Rte_DT_StackUsage_MCU2_1_t_2[2];

# define Rte_TypeDef_Rte_DT_UssPowerSense_3
typedef float32 Rte_DT_UssPowerSense_3[2];

# define Rte_TypeDef_Rte_DT_laneCoef_2dArray_0
typedef float32 Rte_DT_laneCoef_2dArray_0[3];

# define Rte_TypeDef_Rte_DT_laneCoef_TVG_2dArray_0
typedef float32 Rte_DT_laneCoef_TVG_2dArray_0[3];

# define Rte_TypeDef_RunTimeStatData
typedef uint16 RunTimeStatData[38];

# define Rte_TypeDef_SafeStateActive_arr
typedef uint8 SafeStateActive_arr[16];

# define Rte_TypeDef_Sig_Debug_Signal_Arr
typedef sint16 Sig_Debug_Signal_Arr[32];

# define Rte_TypeDef_StackData_MCU1_0
typedef float32 StackData_MCU1_0[19];

# define Rte_TypeDef_Status
typedef uint8 Status[14];

# define Rte_TypeDef_Unsig_Debug_Signal_Arr
typedef uint16 Unsig_Debug_Signal_Arr[32];

# define Rte_TypeDef_UssTunningDataOut_arr
typedef uint8 UssTunningDataOut_arr[3072];

# define Rte_TypeDef_VIN_DATA
typedef uint8 VIN_DATA[7];

# define Rte_TypeDef_VINlData_Arr
typedef uint8 VINlData_Arr[17];

# define Rte_TypeDef_WdgFltSts
typedef uint8 WdgFltSts[2];

# define Rte_TypeDef_coef_img_Array
typedef float32 coef_img_Array[3];

# define Rte_TypeDef_eepromMapRevision_au16
typedef uint16 eepromMapRevision_au16[2];

# define Rte_TypeDef_firstReservedBytes_au8
typedef uint8 firstReservedBytes_au8[56];

# define Rte_TypeDef_keVehParam_e_StrWhlRatioBrkPnts_Array
typedef float32 keVehParam_e_StrWhlRatioBrkPnts_Array[19];

# define Rte_TypeDef_keVehParam_e_VehSteerRatioTable_Array
typedef float32 keVehParam_e_VehSteerRatioTable_Array[19];

# define Rte_TypeDef_laneCoef_TVG_valid_Array
typedef boolean laneCoef_TVG_valid_Array[2];

# define Rte_TypeDef_m_Parkable_Array
typedef boolean m_Parkable_Array[6];

# define Rte_TypeDef_midDist_Array
typedef uint16 midDist_Array[12];

# define Rte_TypeDef_minDist_Array
typedef uint16 minDist_Array[16];

# define Rte_TypeDef_para_Array
typedef float32 para_Array[10];

# define Rte_TypeDef_polyImage2World_af32
typedef float32 polyImage2World_af32[6];

# define Rte_TypeDef_polyWorld2Image_af32
typedef float32 polyWorld2Image_af32[6];

# define Rte_TypeDef_reservedBytesIntrinsic_au8
typedef uint8 reservedBytesIntrinsic_au8[32];

# define Rte_TypeDef_reservedBytes_au8
typedef uint8 reservedBytes_au8[16];

# define Rte_TypeDef_rev_arr
typedef uint8 rev_arr[2];

# define Rte_TypeDef_rsv_Array
typedef uint8 rsv_Array[3];

# define Rte_TypeDef_secondReservedBytes_au8
typedef uint8 secondReservedBytes_au8[4];

# define Rte_TypeDef_uSavedSensorIDs_au32
typedef uint32 uSavedSensorIDs_au32[12];

# define Rte_TypeDef_uUSSPartNumPDC_FIL_arr
typedef uint8 uUSSPartNumPDC_FIL_arr[13];

# define Rte_TypeDef_uUSSPartNumPDC_FIR_arr
typedef uint8 uUSSPartNumPDC_FIR_arr[13];

# define Rte_TypeDef_uUSSPartNumPDC_FOL_arr
typedef uint8 uUSSPartNumPDC_FOL_arr[13];

# define Rte_TypeDef_uUSSPartNumPDC_FOR_arr
typedef uint8 uUSSPartNumPDC_FOR_arr[13];

# define Rte_TypeDef_uUSSPartNumPDC_RIL_arr
typedef uint8 uUSSPartNumPDC_RIL_arr[13];

# define Rte_TypeDef_uUSSPartNumPDC_RIR_arr
typedef uint8 uUSSPartNumPDC_RIR_arr[13];

# define Rte_TypeDef_uUSSPartNumPDC_ROL_arr
typedef uint8 uUSSPartNumPDC_ROL_arr[13];

# define Rte_TypeDef_uUSSPartNumPDC_ROR_arr
typedef uint8 uUSSPartNumPDC_ROR_arr[13];

# define Rte_TypeDef_uUSSPartNumPDC_RSL_arr
typedef uint8 uUSSPartNumPDC_RSL_arr[13];

# define Rte_TypeDef_uUSSPartNumPDC_RSR_arr
typedef uint8 uUSSPartNumPDC_RSR_arr[13];

# define Rte_TypeDef_uUSSPartNumPSM_FSL_arr
typedef uint8 uUSSPartNumPSM_FSL_arr[13];

# define Rte_TypeDef_uUSSPartNumPSM_FSR_arr
typedef uint8 uUSSPartNumPSM_FSR_arr[13];

# define Rte_TypeDef_vRoE_MessageType
typedef uint8 vRoE_MessageType[8];

# define Rte_TypeDef_CAM_CS_Curr_Monitor_t
typedef struct
{
  uint8 s_Front_CAM_CS_A;
  uint8 s_Right_CAM_CS_A;
  uint8 s_Left_CAM_CS_A;
  uint8 s_Rear_CAM_CS_A;
  uint8 s_FreshnessCounter;
} CAM_CS_Curr_Monitor_t;

# define Rte_TypeDef_CAM_select_info_t
typedef struct
{
  uint8 s_Cam_ChId;
  uint8 s_Cam_PwrEn_Sts;
  uint8 rsvd1;
  uint8 rsvd2;
} CAM_select_info_t;

# define Rte_TypeDef_Cam_and_Ser_EN_Status_t
typedef struct
{
  uint8 Cam1_en_stat;
  uint8 Cam2_en_stat;
  uint8 Cam3_en_stat;
  uint8 Cam4_en_stat;
  uint8 SER_en_stat;
} Cam_and_Ser_EN_Status_t;

# define Rte_TypeDef_ColumnRowParams
typedef struct
{
  sint32 START_ROW;
  sint32 END_ROW;
  sint32 START_COL;
  sint32 END_COL;
} ColumnRowParams;

# define Rte_TypeDef_CpuLoadMcu2_0_t
typedef struct
{
  uint32 CpluLoad_MCU2_0_u32;
} CpuLoadMcu2_0_t;

# define Rte_TypeDef_CpuLoadMcu2_1_t
typedef struct
{
  uint32 CpluLoad_MCU2_1_u32;
} CpuLoadMcu2_1_t;

# define Rte_TypeDef_CurveModel
typedef struct
{
  float32 C0;
  float32 C1;
  float32 C2;
} CurveModel;

# define Rte_TypeDef_Debug_HMI_Input_Data_t
typedef struct
{
  float32 steeringWheelAngle_f32;
  float32 vehicleSpeed_f32;
  uint32 lrwsST_e;
  uint32 revGear_e;
  uint32 trscStat_e;
  uint32 NetCfg_TRSCM_e;
  uint32 ignitionStatus_e;
  uint32 transEquipped_e;
  uint32 prndStatus_e;
  uint32 CameraDisplaySts2_e;
  uint32 tgwDispStatus_e;
  uint32 ImageDefeat_Error_e;
  uint32 SoftBtn_Error_e;
  uint32 DynOvl_Error_e;
  uint32 View_Error_e;
  uint32 tchScrnStatus_e;
  uint16 tchScrnCoordX_s;
  uint16 tchScrnCoordY_s;
  uint8 CAM_NA_Bitfield_u8;
  uint8 vehicleLine_e;
  uint8 LanguageSelection_u8;
  boolean TopVideoBlanked_b;
  boolean SVC_Dynamic_Gridlines_Feature_b;
  boolean SVC_Static_Gridlines_Feature_b;
  boolean SVC_FFCV_Gridlines_Feature_b;
  boolean SVC_Delay_Feature_b;
  boolean GW_C_I6_timeout_b;
} Debug_HMI_Input_Data_t;

# define Rte_TypeDef_Debug_HMI_Internal_Data_t
typedef struct
{
  uint32 M_BURV_Memory_e;
  uint32 M_FFClatch_e;
  uint32 Curr_SystemState_e;
  uint32 Prev_SystemState_e;
  uint32 Curr_RequestedViewByHmiM_e;
  uint32 Prev_RequestedViewByHmiM_e;
  uint32 Curr_DisplayedViewByAcore_e;
  uint32 Prev_DisplayedViewByAcore_e;
  uint32 LastViewBeforeTestPattern_e;
  uint8 ZoomFactor_u8;
  boolean IgnoreVehicleOffSpeed;
  boolean X_BTN_PRESSED_b;
  boolean MAGNIFIER_BTN_PRESSED_b;
  boolean REAR_TOP_BTN_PRESSED_b;
  boolean FRONT_TOP_BTN_PRESSED_b;
  boolean REAR_CROSS_BTN_PRESSED_b;
  boolean FRONT_CROSS_BTN_PRESSED_b;
  boolean FFCV_BTN_PRESSED_b;
  boolean RVCONLY_BTN_PRESSED_b;
  boolean VC_OFFROAD_PRSNT_AUXCAM_BTN_PRESSED_b;
  boolean VC_OFFROAD_ABSNT_AUXCAM_BTN_PRESSED_b;
  boolean VC_OFFROAD_PRSNT_MC_BTN_PRESSED_b;
  boolean VC_OFFROAD_ABSNT_MC_BTN_PRESSED_b;
} Debug_HMI_Internal_Data_t;

# define Rte_TypeDef_Debug_HMI_ProxiConfig_t
typedef struct
{
  uint8 MePRX_e_VariantID;
  uint8 MePRX_e_VehLineCfg;
  uint8 MePRX_e_Wheelbase;
  uint8 MePRX_e_SteerRatRackPinionType;
  uint8 MePRX_e_RadDispType;
  uint8 MePRX_e_MirrorType;
  uint8 MePRX_e_PAMTunSet;
  uint8 MePRX_e_AutonomyLvl;
  boolean MePRX_b_SurroundViewCamera;
  boolean MePRX_b_FrwFacingCam;
  boolean MePRX_b_AuxTrlrCam;
  boolean MePRX_b_CANNode95;
  boolean MePRX_b_CanNode27;
  boolean MePRX_b_TRGPresence;
  boolean MePRX_b_TRSCPresence;
} Debug_HMI_ProxiConfig_t;

# define Rte_TypeDef_Debug_HMI_Trailer_Views_Data_t
typedef struct
{
  float32 TadAngle;
  float32 MaxTadAngle;
  float32 KnobAngle;
  float32 JackKnifeAngle;
  uint32 TrscStatus;
  uint32 TrailerAngleSign;
  uint32 TrailerCalibrationStatus;
  uint32 Curr_TRG_Stat;
  uint32 Prev_TRG_Stat;
  uint8 M_CPLR_POS_X_u;
  uint8 M_CPLR_POS_Y_u;
  uint8 M_Cplr_Htch_Distance;
  uint8 M_Progress_Bar_Distance;
  uint8 M_Maneuver_Initial_Run;
  uint8 M_Progress_Bar_Percentage;
  uint8 M_Current_THA_State_On_Zync;
  uint8 M_Current_THA_State_On_Screen;
  uint8 M_Requested_THA_State;
  uint8 TrailerWheelBase;
  uint8 TrailerConnectionStatus;
  uint8 ItbmTrailerStatus;
  boolean M_VIEW_ZOOM_STS_b;
  boolean M_VIEW_SCRN_TCH_STS_b;
  boolean M_CONFIRM_BTN_PRESSED_b;
  boolean M_START_BTN_PRESSED_b;
  boolean M_THA_SFT_BTN_PRESSED_b;
  boolean aHmiM_STM_v_TRGLEFT_BTN_PRESSED_b;
  boolean aHmiM_STM_v_TRGRIGHT_BTN_PRESSED_b;
  boolean aHmiM_STM_v_TRGAUTO_BTN_PRESSED_b;
} Debug_HMI_Trailer_Views_Data_t;

# define Rte_TypeDef_DtcStatus_B
typedef struct
{
  uint8 b210c_16_0;
  uint8 b210c_17_0;
  uint8 u104e_0_0;
  uint8 u100b_0_0;
  uint8 u0140_0_0;
  uint8 u0184_0_0;
  uint8 b223b_0_0;
  uint8 u0129_0_0;
  uint8 u0131_0_0;
  uint8 u0418_0_0;
  uint8 u0420_0_0;
  uint8 u0422_0_0;
  uint8 u0485_0_0;
  uint8 b12b2_2a_0;
  uint8 b1285_2a_0;
  uint8 b128e_13_0;
  uint8 b128f_13_0;
  uint8 b1290_13_0;
  uint8 b1291_13_0;
  uint8 b1292_13_0;
  uint8 b1293_13_0;
  uint8 b1294_13_0;
  uint8 b1295_13_0;
  uint8 b1296_13_0;
  uint8 b1297_13_0;
  uint8 b1298_13_0;
  uint8 b1299_13_0;
  uint8 b128e_92_0;
  uint8 b128f_92_0;
  uint8 b1290_92_0;
  uint8 b1291_92_0;
  uint8 b1292_92_0;
  uint8 b1293_92_0;
  uint8 b1294_92_0;
  uint8 b1295_92_0;
  uint8 b1296_92_0;
  uint8 b1297_92_0;
  uint8 b1298_92_0;
  uint8 b1299_92_0;
  uint8 b212a_16_0;
  uint8 b212b_16_0;
  uint8 b22a9_0_0;
  uint8 b23c6_92_0;
  uint8 u0267_0_0;
  uint8 b23c7_92_0;
  uint8 u0266_0_0;
  uint8 u0264_0_0;
  uint8 b217a_92_0;
  uint8 u0265_0_0;
  uint8 b23c5_92_0;
  uint8 b217a_1c_0;
  uint8 b23c5_1c_0;
  uint8 b23c6_1c_0;
  uint8 b23c7_1c_0;
  uint8 b2286_0_0;
  uint8 c2212_0_0;
  uint8 b212a_17_0;
  uint8 b212b_17_0;
  uint8 u0100_0_0;
  uint8 u0401_0_0;
  uint8 b212a_8_0;
  uint8 b212b_8_0;
} DtcStatus_B;

# define Rte_TypeDef_DtcStatus_QM
typedef struct
{
  uint8 u0151_0_0;
  uint8 u12b9_0_0;
  uint8 u14a0_0_0;
  uint8 u0455_0_0;
} DtcStatus_QM;

# define Rte_TypeDef_E2E_MEP_ProtectStateType
typedef struct
{
  uint8 Counter;
} E2E_MEP_ProtectStateType;

# define Rte_TypeDef_Error_Fault_MCU2_0_t
typedef struct
{
  uint16 Err_FaultInfo_MCU2_0;
  uint8 Err_FaultNum_MCU2_0;
  uint8 Reserved;
} Error_Fault_MCU2_0_t;

# define Rte_TypeDef_Error_Fault_MCU2_1_t
typedef struct
{
  uint16 Err_FaultInfo_MCU2_1;
  uint8 Err_FaultNum_MCU2_1;
  uint8 Reserved;
} Error_Fault_MCU2_1_t;

# define Rte_TypeDef_Error_Fault_MPU1_0_t
typedef struct
{
  uint16 Err_FaultInfo_MPU1_0;
  uint8 Err_FaultNum_MPU1_0;
  uint8 Reserved;
} Error_Fault_MPU1_0_t;

# define Rte_TypeDef_Float2
typedef struct
{
  float32 x;
  float32 y;
} Float2;

# define Rte_TypeDef_FunctionalSettings_t
typedef struct
{
  uint8 Oc_Control;
  uint16 Oc_Speedlimit;
  uint8 OC_ApplyResults;
  uint8 OC_Weighting;
  uint8 Framerate;
} FunctionalSettings_t;

# define Rte_TypeDef_IFOD_Outputs_Arbitration_t
typedef struct
{
  uint8 IeFOD_e_FODStatus;
  uint8 MeFOD_e_USSFiringMode;
  boolean IeFOD_b_ResetKM;
} IFOD_Outputs_Arbitration_t;

# define Rte_TypeDef_IFOD_Outputs_CVPAMFDData_t
typedef struct
{
  uint32 IeFOD_e_FODHealth;
  uint32 IeFOD_e_FODConfidence;
} IFOD_Outputs_CVPAMFDData_t;

# define Rte_TypeDef_ILMD_Outputs_ADASFDLANES2_t
typedef struct
{
  uint64 IeLMD_e_FrameIndexLanes2;
  uint64 IeLMD_e_CntrAdasFdLanes2;
  float32 IeLMD_e_LineSeg1Conf;
  float32 IeLMD_e_LineSeg2Conf;
  float32 IeLMD_e_LineSeg3Conf;
  float32 IeLMD_e_LineSeg4Conf;
  float32 IeLMD_e_LineSeg5Conf;
  float32 IeLMD_e_LineSeg6Conf;
  float32 IeLMD_e_LineSeg7Conf;
  float32 IeLMD_e_LineSeg8Conf;
  float32 IeLMD_m_LineSeg1X1;
  float32 IeLMD_m_LineSeg2X1;
  float32 IeLMD_m_LineSeg3X1;
  float32 IeLMD_m_LineSeg4X1;
  float32 IeLMD_m_LineSeg5X1;
  float32 IeLMD_m_LineSeg6X1;
  float32 IeLMD_m_LineSeg7X1;
  float32 IeLMD_m_LineSeg8X1;
  float32 IeLMD_m_LineSeg1X2;
  float32 IeLMD_m_LineSeg2X2;
  float32 IeLMD_m_LineSeg3X2;
  float32 IeLMD_m_LineSeg4X2;
  float32 IeLMD_m_LineSeg5X2;
  float32 IeLMD_m_LineSeg6X2;
  float32 IeLMD_m_LineSeg7X2;
  float32 IeLMD_m_LineSeg8X2;
  float32 IeLMD_m_LineSeg1Y1;
  float32 IeLMD_m_LineSeg2Y1;
  float32 IeLMD_m_LineSeg3Y1;
  float32 IeLMD_m_LineSeg4Y1;
  float32 IeLMD_m_LineSeg5Y1;
  float32 IeLMD_m_LineSeg6Y1;
  float32 IeLMD_m_LineSeg7Y1;
  float32 IeLMD_m_LineSeg8Y1;
  float32 IeLMD_m_LineSeg1Y2;
  float32 IeLMD_m_LineSeg2Y2;
  float32 IeLMD_m_LineSeg3Y2;
  float32 IeLMD_m_LineSeg4Y2;
  float32 IeLMD_m_LineSeg5Y2;
  float32 IeLMD_m_LineSeg6Y2;
  float32 IeLMD_m_LineSeg7Y2;
  float32 IeLMD_m_LineSeg8Y2;
  uint16 IeLMD_e_CrcAdasFdLanes2;
  uint8 IeLMD_e_LineSeg1Id;
  uint8 IeLMD_e_LineSeg2Id;
  uint8 IeLMD_e_LineSeg3Id;
  uint8 IeLMD_e_LineSeg4Id;
  uint8 IeLMD_e_LineSeg5Id;
  uint8 IeLMD_e_LineSeg6Id;
  uint8 IeLMD_e_LineSeg7Id;
  uint8 IeLMD_e_LineSeg8Id;
  uint8 IeLMD_e_MsgCntrAdasFdLanes2;
  uint8 IeLMD_e_MacAdasFdLanes2;
  uint8 IeLMD_e_ReservedForFunctionalSafety2;
  uint8 Dummy1_2_b;
  uint8 Dummy2_2_b;
  uint8 Dummy3_2_b;
} ILMD_Outputs_ADASFDLANES2_t;

# define Rte_TypeDef_IobjectSignals_t
typedef struct
{
  float32 objAge_f32;
  float32 objDistance_f32;
  float32 ObjDistToClosestPointX_f32;
  float32 ObjDistToClosestPointY_f32;
} IobjectSignals_t;

# define Rte_TypeDef_KeepAliveResponse_t
typedef struct
{
  uint32 FrameID_u32;
  uint8 ResponseCode_u8;
} KeepAliveResponse_t;

# define Rte_TypeDef_LC_LnPnt
typedef struct
{
  sint32 x;
  sint32 y;
  float32 x_World_mm;
  float32 y_World_mm;
  sint32 confidanceScore;
  boolean valid;
  float32 angle;
  float32 rho;
  boolean selectCurveFit;
  boolean IsInnerPoint;
} LC_LnPnt;

# define Rte_TypeDef_ME_Hydra3defs_S_EOLTargetData_t
typedef struct
{
  sint8 TargetInit_s8;
  sint8 TargetLimitFront_s8;
  sint8 TargetLimitRear_s8;
  sint8 TargetDetectLeftFront_s8;
  sint8 TargetDetectLeftRear_s8;
  sint8 TargetDetectRightFront_s8;
  sint8 TargetDetectRightRear_s8;
  sint8 Reserved_s8;
} ME_Hydra3defs_S_EOLTargetData_t;

# define Rte_TypeDef_ME_VehInpAdp_ACU_0x159
typedef struct
{
  uint8 ACU_Pass_OCS_St;
  uint8 ACU_AirBagSysAlrmLampSts;
  uint8 ACU_Pass_Airbag_LED;
  uint8 ACU_Drvr_Occpt_St;
  uint8 ACU_BucSwtStFrntDrvr;
  uint8 ACU_BucSwtStFrntPass;
} ME_VehInpAdp_ACU_0x159;

# define Rte_TypeDef_ME_VehInpAdp_ACU_0x59
typedef struct
{
  uint8 ACU_FrntCrashOutpSts;
  uint8 ACU_RiSideCrashOutpSts;
  uint8 ACU_LeSideCrashOutpSts;
  uint8 ACU_RearCrashOutpSts;
} ME_VehInpAdp_ACU_0x59;

# define Rte_TypeDef_ME_VehInpAdp_BCM_0x333
typedef struct
{
  uint8 BCM_IG1Sts;
  uint8 BCM_PwrMod;
  uint8 BCM_BrkSwtSts;
  uint8 BCM_IG2Sts;
} ME_VehInpAdp_BCM_0x333;

# define Rte_TypeDef_ME_VehInpAdp_BCM_0x335
typedef struct
{
  uint8 BCM_ReWiprBackSwtSts;
  uint8 BCM_LeTrunLampOutpCmd;
  uint8 BCM_RiTrunLampOutpCmd;
  uint8 BCM_BrkLampSwtSts;
  uint8 BCM_HiBeamOutpCmd;
  uint8 BCM_LoBeamOutpCmd;
  uint8 BCM_PosnLampOutpCmd;
  uint8 BCM_FrntWiprSpd;
  uint8 BCM_VehAmbBri;
} ME_VehInpAdp_BCM_0x335;

# define Rte_TypeDef_ME_VehInpAdp_BCM_0x343
typedef struct
{
  uint8 BCM_FrntHoodLidSts;
  uint8 BCM_FrntLeDoorLockSts;
  uint8 BCM_LockAllDoorCmd;
  uint8 BCM_LeFrntDoorSts;
  uint8 BCM_RiFrntDoorSts;
  uint8 BCM_RiReDoorSts;
  uint8 BCM_LeReDoorSts;
  uint8 BCM_SteerWhlVbrnAlrmAvl;
} ME_VehInpAdp_BCM_0x343;

# define Rte_TypeDef_ME_VehInpAdp_CIM_0x310
typedef struct
{
  uint8 CIM_TurnLampSwtSts;
  uint8 CIM_HiBeamSwtSts;
  uint8 CIM_FrntWiprSwtSts;
} ME_VehInpAdp_CIM_0x310;

# define Rte_TypeDef_ME_VehInpAdp_ECC_0x373
typedef struct
{
  float32 ECC_OutdT;
} ME_VehInpAdp_ECC_0x373;

# define Rte_TypeDef_ME_VehInpAdp_EPS_0x1C2
typedef struct
{
  float32 EPS_SteerWhlAgSig;
  float32 EPS_SteerWhlRotSpd;
  float32 EPS_MaxSftyTq;
} ME_VehInpAdp_EPS_0x1C2;

# define Rte_TypeDef_ME_VehInpAdp_EPS_0x1C4
typedef struct
{
  uint8 EPS_DrvrSteerTqDir;
  float32 EPS_DrvrSteerTq;
  uint8 EPS_EPSAvl;
  uint8 EPS_DrvrIntvSteerWhlDetd;
  uint8 EPS_DrvrIntvSteerWhlVld;
  uint8 EPS_SteerSnsrSts;
  uint8 EPS_SysAvlSts;
  uint8 EPS_LatMtnCtrlSts;
  float32 EPS_MinSftyTq;
  float32 EPS_PinionAg;
} ME_VehInpAdp_EPS_0x1C4;

# define Rte_TypeDef_ME_VehInpAdp_EPS_0x475
typedef struct
{
  uint8 EPS_ModSts;
} ME_VehInpAdp_EPS_0x475;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x120
typedef struct
{
  uint8 ESP_ActvSig_ABS;
  uint8 ESP_VmcVseYawRateAvlCpby;
  float32 ESP_MstCylP;
  float32 ESP_MstCylPOffs;
  uint16 ESP_TotBrkTqReq;
} ME_VehInpAdp_ESP_0x120;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x122
typedef struct
{
  float32 ESP_VmcVseAxOvrGrnd;
  float32 ESP_VmcVsevVeh;
} ME_VehInpAdp_ESP_0x122;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x125
typedef struct
{
  uint8 ESP_WhlOdoEdges_FL;
  uint8 ESP_WhlOdoEdges_FR;
  uint8 ESP_WhlOdoEdges_RL;
  uint8 ESP_WhlOdoEdges_RR;
} ME_VehInpAdp_ESP_0x125;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x1B8
typedef struct
{
  uint8 ESP_VehStopSts;
  uint8 ESP_VehStandstillSts;
  uint8 ESP_VMC_PrefillActv;
  uint8 ESP_VLC_APCtrlSaturated;
  uint8 ESP_RoadSlopVld;
  uint8 ESP_AEBRdy;
  uint8 ESP_ParkRdy;
  uint8 ESP_ReAEBRdy;
  uint8 ESP_VlcApVehIsSecured;
  float32 ESP_RoadSlop;
} ME_VehInpAdp_ESP_0x1B8;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x261
typedef struct
{
  uint8 ESP_ActvSig;
  uint8 ESP_ActvSig_TCS;
  uint8 ESP_WarningOn;
  uint8 ESP_ActvIndcn_AEB;
  uint8 ESP_FltIndcn_AEB;
  uint8 ESP_VehStandstillIndcn;
  uint8 ESP_BrkOverTIndcn;
} ME_VehInpAdp_ESP_0x261;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x262
typedef struct
{
  uint8 ESP_ApaDrvOverrideFcn;
} ME_VehInpAdp_ESP_0x262;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x268
typedef struct
{
  uint8 ESP_SysSts_EPB;
  uint8 ESP_EPBSwtichPosition;
} ME_VehInpAdp_ESP_0x268;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x305
typedef struct
{
  uint8 ESP_WhlSpdVld_RF;
  float32 ESP_WhlSpd_RF;
  uint8 ESP_WhlMovgDir_RF;
  uint8 ESP_WhlMovgDir_LF;
  uint8 ESP_WhlSpdVld_LF;
  float32 ESP_WhlSpd_LF;
} ME_VehInpAdp_ESP_0x305;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x306
typedef struct
{
  uint8 ESP_WhlSpdVld_RR;
  float32 ESP_WhlSpd_RR;
  uint8 ESP_WhlMovgDir_RR;
  uint8 ESP_WhlMovgDir_RL;
  uint8 ESP_WhlSpdVld_RL;
  float32 ESP_WhlSpd_RL;
} ME_VehInpAdp_ESP_0x306;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x30A
typedef struct
{
  float32 ESP_LgtOffs;
  float32 ESP_LatOffs;
  float32 ESP_YAWVOffs;
} ME_VehInpAdp_ESP_0x30A;

# define Rte_TypeDef_ME_VehInpAdp_ESP_0x318
typedef struct
{
  uint8 ESP_BrkPedlSts;
  uint8 ESP_BrkPedlStsVld;
  uint8 ESP_VehSpdVld;
  uint8 ESP_SysActv;
  uint8 ESP_FltIndcn_ABS;
  float32 ESP_VehSpd;
} ME_VehInpAdp_ESP_0x318;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x250
typedef struct
{
  uint8 ICC_SegMsgType;
  uint16 ICC_SegOffset;
  uint8 ICC_SegPathIdx;
  uint8 ICC_SegCycCnt;
  uint8 ICC_SegUpdate;
  uint8 ICC_SegRetr;
  uint8 ICC_SegBuildUpArea;
  uint8 ICC_SegBridge;
  uint8 ICC_SegTunnel;
  uint8 ICC_SegFuncRoadClass;
  uint8 ICC_SegRelProbb;
  uint8 ICC_SegFormOfWay;
  uint8 ICC_SegCmplxInsct;
  uint8 ICC_SegPartOfCalcRoute;
  uint8 ICC_SegEffSpdLmtType;
  uint8 ICC_SegEffSpdLmt;
  uint8 ICC_SegNumOfLaneDrvDir;
  uint8 ICC_SegNumOfLaneOppDir;
  uint8 ICC_SegDividedRoad;
} ME_VehInpAdp_ICC_0x250;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x251
typedef struct
{
  uint8 ICC_StubMsgType;
  uint16 ICC_StubOffset;
  uint8 ICC_StubPathIdx;
  uint8 ICC_StubCycCnt;
  uint8 ICC_StubUpdate;
  uint8 ICC_StubRetr;
  uint8 ICC_StubStubPathIdx;
  uint8 ICC_StubFuncRoadClass;
  uint8 ICC_StubRelProbb;
  uint8 ICC_StubFormOfWay;
  uint8 ICC_StubCmplxInsct;
  uint8 ICC_StubPartOfCalcRout;
  uint8 ICC_StubTurnAngl;
  uint8 ICC_StubNumOfLaneDrvDir;
  uint8 ICC_StubNumOfLaneOppDir;
  uint8 ICC_StubRtOfWay;
  uint8 ICC_StubLastStub;
} ME_VehInpAdp_ICC_0x251;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x252
typedef struct
{
  uint16 ICC_ProfLongOffset;
  uint8 ICC_ProfLongMsgType;
  uint8 ICC_ProfLongPathIdx;
  uint8 ICC_ProfLongCycCnt;
  uint8 ICC_ProfLongUpdate;
  uint8 ICC_ProfLongRetr;
  uint8 ICC_ProfLongCtrlPoint;
  uint8 ICC_ProfLongProfType;
  uint8 ICC_ProfLongSignType;
  uint8 ICC_ProfLongSignValue;
  uint8 ICC_ProfLongSignTimeSpec;
  uint8 ICC_ProfLongSignVehSpec;
  uint8 ICC_ProfLongSignLane;
  uint8 ICC_0x252_Reserved;
  uint8 ICC_ProfLongSignLocation;
  uint8 ICC_ProfLongSignCondition;
} ME_VehInpAdp_ICC_0x252;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x253
typedef struct
{
  uint8 ICC_0x253_ProfShortMsgType;
  uint8 ICC_0x253_ProfShortOffset;
  uint8 ICC_0x253_ProfShortPathIdx;
  uint8 ICC_0x253_ProfShortCycCnt;
  uint8 ICC_0x253_ProfShortUpdate;
  uint8 ICC_0x253_ProfShortRetr;
  uint8 ICC_0x253_ProfShortCtrlPoint;
  uint8 ICC_0x253_ProfShortProfType;
  uint8 ICC_0x253_ProfShortAccurClass;
  uint8 ICC_0x253_ProfShortDist1;
  uint8 ICC_0x253_ProfShortValue0;
  uint8 ICC_0x253_ProfShortValue1;
} ME_VehInpAdp_ICC_0x253;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x255
typedef struct
{
  uint16 ICC_ProfShortOffset;
  uint8 ICC_ProfShortMsgType;
  uint8 ICC_ProfShortPathIdx;
  uint8 ICC_ProfShortCycCnt;
  uint8 ICC_ProfShortUpdate;
  uint8 ICC_ProfShortRetr;
  uint8 ICC_ProfShortCtrlPoint;
  uint8 ICC_ProfShortProfType;
  uint8 ICC_ProfShortAccurClass;
  uint16 ICC_ProfShortDist1;
  uint16 ICC_ProfShortValue0;
  uint16 ICC_ProfShortValue1;
} ME_VehInpAdp_ICC_0x255;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x361
typedef struct
{
  uint8 ICC_PosnMsgTye;
  uint16 ICC_PosnOffset;
  uint8 ICC_PosnPathldx;
  uint8 ICC_PosnCycCnt;
  uint8 ICC_PosnPosProbb;
  uint8 ICC_PosnIdx;
  uint16 ICC_PosnAge;
  uint8 ICC_PosnCurLane;
  uint8 ICC_PosnPosConfdc;
  float32 ICC_PosnSpd;
  float32 ICC_PosnRehead;
} ME_VehInpAdp_ICC_0x361;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x362
typedef struct
{
  uint8 ICC_MetaMapProvider;
  uint8 ICC_MetaMsgType;
  uint16 ICC_MetaCountryCode;
  uint8 ICC_MetaProtVerMinorSub;
  uint8 ICC_MetaProtVerMajor;
  uint8 ICC_MetaCycCnt;
  uint16 ICC_MetaHwVer;
  uint8 ICC_MetaDrvSide;
  uint16 ICC_MetaRegionCode;
  uint8 ICC_MetaMapVerYear;
  uint8 ICC_MetaMapVerQtr;
  uint8 ICC_MetaProtVerMinor;
  uint8 ICC_MetaSpdUnits;
  uint8 ICC_Reserved;
} ME_VehInpAdp_ICC_0x362;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x52A
typedef struct
{
  uint8 ICC_ACCAutoSpdSts;
  uint8 ICC_ACCSpdStepSize;
  uint8 ICC_UsrProfTimeGapSet;
  uint8 ICC_ACCFuncTyp;
  uint8 ICC_AutomaticViewReq;
  uint8 ICC_OperationType;
  uint8 ICC_ZOOM_Start;
  uint8 ICC_ZOOM_End;
  float32 ICC_ZOOM_ScalingFactor;
  uint8 ICC_BSDSetting;
  uint8 ICC_ESA_Setting;
  uint8 ICC_ViewReq;
  uint8 ICC_AEB_WarningSetting;
  uint8 ICC_AEB_Sensitivity;
  uint8 ICC_BACM_Setting;
  uint8 ICC_BACM_WarningSetting;
  uint8 ICC_BACM_Sensitivity;
  uint8 ICC_LKA_Setting;
  uint8 ICC_ELKA_Setting;
  uint8 ICC_ELKASteeringInterventionSet;
  uint8 ICC_AHBA_Setting;
  uint8 ICC_TLR_Setting;
  uint8 ICC_TRS_Setting;
  uint8 ICC_ISASetting;
  uint8 ICC_ISASpeedOffset;
  uint8 ICC_AEB_Setting;
  uint8 ICC_DOW_Setting;
  uint8 ICC_LaneTrajectorySetting;
} ME_VehInpAdp_ICC_0x52A;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x530
typedef struct
{
  uint8 ICC_NavCtryCod;
  uint8 ICC_NavRoadTyp;
  uint8 ADAS_LgtCtrl_Sts;
  uint8 ADAS_LgtCtr_StsVld;
  uint8 ADAS_LgtCtrl_DrvrOvrdSts;
  uint8 ADAS_LgtCtrl_DrvrOvrdVld;
  uint8 ADAS_ParkStandstillReq;
  uint8 ADAS_ParkStandstillVld;
  uint8 ADAS_ParkGearReq;
  uint8 ADAS_ParkGearReqVld;
  uint8 ADAS_LgtCtrl_Typ;
  uint8 ADAS_LgtCtrl_AccelVld;
  float32 ADAS_LgtCtrl_AccelReq;
  uint8 ADAS_LatCtrl_Sts;
  uint8 ADAS_LatCtrl_StsVld;
  uint8 ADAS_LatCtrl_DrvrOvrd;
  uint8 ADAS_LatCtrl_DrvrOvrdVld;
  uint8 ADAS_LatCtrl_Typ;
  uint8 ADAS_LatCtrl_ReqVld;
  uint8 ADAS_LatCtrl_Req;
  float32 ADAS_LatCtrl_SteerAnReq;
  float32 ADAS_LatCtrl_SteerTqReq;
  uint8 ADAS_AEB_Ctrl_Sts;
  uint8 ADAS_AEB_Ctrl_Vld;
  uint8 ADAS_AEB_DrvrOvrdSts;
  uint8 ADAS_AEB_DrvrOvrdVld;
  uint8 ADAS_AEB_HBAReq;
  uint8 ADAS_AEB_HBAVld;
  uint8 ADAS_AEB_StandstillReq;
  uint8 ADAS_AEB_StandstillVld;
  uint8 ADAS_AEB_JerkReq;
  uint8 ADAS_AEB_JerkReqVld;
  uint8 ADAS_AEB_BrkPrefillReq;
  uint8 ADAS_AEB_BrkPrefillVld;
  uint8 ADAS_AEB_ActvTyp;
  uint8 ADAS_AEB_DecelVld;
  float32 ADAS_AEB_DecelReq;
  uint8 ADAS_CamSts;
  uint8 ADAS_ObjNr;
  uint8 ADAS_DispSpd_ACC;
  uint8 ADAS_DispSpdUnit_ACC;
  uint8 ADAS_TiGapSet_ACC;
  uint8 ADAS_LatCtrl_LeTurnLampReq;
  uint8 ADAS_LatCtrl_RiTurnLampReq;
  uint8 ADAS_LatCtrl_HapticReq;
  uint8 ADAS_Warn_TLA;
} ME_VehInpAdp_ICC_0x530;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x531
typedef struct
{
  float32 ICM_TotMilg_ODO;
  uint8 ICM_DispVehSpd;
  uint8 ICM_DispVehSpdUnit;
} ME_VehInpAdp_ICC_0x531;

# define Rte_TypeDef_ME_VehInpAdp_MCU_F_0x150
typedef struct
{
  uint8 MCU_F_CrtRotDir;
  uint16 MCU_F_CrtSpd;
} ME_VehInpAdp_MCU_F_0x150;

# define Rte_TypeDef_ME_VehInpAdp_MFS_0x514
typedef struct
{
  uint8 MFS_LeBtnNorth;
  uint8 MFS_LeBtnSouth;
  uint8 MFS_LeBtnWest;
  uint8 MFS_LeBtnEast;
  uint8 MFS_LeRollUp;
  uint8 MFS_LeRollDwn;
  uint8 MFS_LeRollPress;
  uint8 MFS_RiBtnNorth;
  uint8 MFS_RiBtnSouth;
  uint8 MFS_RiBtnWest;
  uint8 MFS_RiBtnEast;
  uint8 MFS_RiRollUp;
  uint8 MFS_RiRollDwn;
  uint8 MFS_RiRollPress;
} ME_VehInpAdp_MFS_0x514;

# define Rte_TypeDef_ME_VehInpAdp_PLGM_0x471
typedef struct
{
  uint8 PLGM_TrSts;
} ME_VehInpAdp_PLGM_0x471;

# define Rte_TypeDef_ME_VehInpAdp_TBOX_0x24B
typedef struct
{
  float32 TBOX_XAcce;
  float32 TBOX_YAcce;
  float32 TBOX_ZAcce;
  float32 TBOX_XVelocity;
  float32 TBOX_YVelocity;
  float32 TBOX_ZVelocity;
  float32 TBOX_XAgrRate;
  float32 TBOX_YAgrRate;
  float32 TBOX_ZAgrRate;
  float32 TBOX_VehMovg;
  float32 TBOX_Roll;
  float32 TBOX_Pitch;
  float32 TBOX_Yaw;
} ME_VehInpAdp_TBOX_0x24B;

# define Rte_TypeDef_ME_VehInpAdp_TBOX_0x24C
typedef struct
{
  uint8 TBOX_SatellitesNr;
  uint16 TBOX_GNSSReckoningTi;
  uint16 TBOX_GPSNumSatellitesVld;
  uint8 TBOX_SysSts;
} ME_VehInpAdp_TBOX_0x24C;

# define Rte_TypeDef_ME_VehInpAdp_TBOX_0x36
typedef struct
{
  uint8 TBOX_BusWakeupMsg;
} ME_VehInpAdp_TBOX_0x36;

# define Rte_TypeDef_ME_VehInpAdp_TBOX_0x525
typedef struct
{
  float32 TBOX_GPSLongi;
  float32 TBOX_GPSLati;
} ME_VehInpAdp_TBOX_0x525;

# define Rte_TypeDef_ME_VehInpAdp_TRM_0x348
typedef struct
{
  uint8 TRM_TrailerSts;
  uint8 TRM_IndcrLeSts;
  uint8 TRM_IndcrRiSts;
  uint8 TRM_RvsSts;
  uint8 TRM_HitchSts;
} ME_VehInpAdp_TRM_0x348;

# define Rte_TypeDef_ME_VehInpAdp_VCU_0x1BA
typedef struct
{
  uint8 VCU_VehConfig;
  float32 VCU_DrvrAPSPerc;
  uint8 VCU_PrkgCmd;
  uint8 VCU_Decoup_Dyn;
  uint8 VCU_DrvrAPSGrdt;
} ME_VehInpAdp_VCU_0x1BA;

# define Rte_TypeDef_ME_VehInpAdp_VCU_0x214
typedef struct
{
  uint8 VCU_StgyGearSig;
  uint8 VCU_GearSigVld;
  uint8 VCU_GearSig;
  uint8 VCU_ACCRdy;
  uint8 VCU_ParkRdy;
  uint8 VCU_APSPercVld;
  uint8 VCU_VehSt;
  uint8 VCU_APSPerc;
  uint8 VCU_BrkSig;
} ME_VehInpAdp_VCU_0x214;

# define Rte_TypeDef_ME_VehInpAdp_VCU_0x225
typedef struct
{
  uint8 VCU_MotChkACCFltFbFlg;
  uint8 VCU_VehTqFltSts;
} ME_VehInpAdp_VCU_0x225;

# define Rte_TypeDef_ME_VehInpAdp_YRS_0x242
typedef struct
{
  float32 YRS_LatAcce;
  float32 YRS_YawRate;
} ME_VehInpAdp_YRS_0x242;

# define Rte_TypeDef_ME_VehInpAdp_YRS_0x246
typedef struct
{
  float32 YRS_LgtAcce;
  uint8 BCM_LightReqReason_RLS;
} ME_VehInpAdp_YRS_0x246;

# define Rte_TypeDef_ME_VehInpAdp_iBooster_0x271
typedef struct
{
  uint8 iBooster_WarnOn;
  uint8 iBooster_BrkPedlAppld;
} ME_VehInpAdp_iBooster_0x271;

# define Rte_TypeDef_ME_VehInp_BCM_FD_21_QM
typedef struct
{
  uint8 Snow_Plow_Presence;
} ME_VehInp_BCM_FD_21_QM;

# define Rte_TypeDef_ME_VehInp_BCM_FD_2_QM
typedef struct
{
  uint8 RemStActvSts;
  uint8 TurnIndicatorSts;
} ME_VehInp_BCM_FD_2_QM;

# define Rte_TypeDef_ME_VehInp_FD14_BRAKE_FD_6_QM
typedef struct
{
  uint8 FD14_DriverReq_AxleTrq_Enabled_BSM;
} ME_VehInp_FD14_BRAKE_FD_6_QM;

# define Rte_TypeDef_ME_VehInp_FD14_PT_TORQUE_FD_1_QM
typedef struct
{
  boolean FD14_Accel_Pedal_Override;
  uint8 FD14_PPPA_TrqEnblRq_Allowed;
} ME_VehInp_FD14_PT_TORQUE_FD_1_QM;

# define Rte_TypeDef_ME_VehInp_ORC_FD_1_QM
typedef struct
{
  uint8 SBR1RowDriverSeatSts;
} ME_VehInp_ORC_FD_1_QM;

# define Rte_TypeDef_ME_VehInp_TRSKM_FD_1_QM
typedef struct
{
  uint8 TRSC_CenterBtn_Sts;
  uint8 TRSC_EnableBtn_Sts;
  uint16 TRSC_RawKnob;
} ME_VehInp_TRSKM_FD_1_QM;

# define Rte_TypeDef_OverlayBits_t
typedef struct
{
  uint8 TopRearButtonSelect_b;
  uint8 TopRearButtonNoSelect_b;
  uint8 RearCrossButtonSelect_b;
  uint8 RearCrossButtonNoSelect_b;
  uint8 FrontCrossButtonSelect_b;
  uint8 FrontCrossButtonNoSelect_b;
  uint8 TopFrontButtonNoSelect_b;
  uint8 TopFrontButtonSelect_b;
  uint8 BackupRearCamButtonNoSelect_b;
  uint8 BackupRearCamButtonSelect_b;
  uint8 FrontFaceCamButtonNoSelect_b;
  uint8 FrontFaceCamButtonSelect_b;
  uint8 AuxCamButton1NoSelect_b;
  uint8 AuxCamButton1Select_b;
  uint8 AuxCamButton2NoSelect_b;
  uint8 AuxCamButton2Select_b;
  uint8 MoreCamsButton1NoSelect_b;
  uint8 MoreCamsButton1Select_b;
  uint8 MoreCamsButton2NoSelect_b;
  uint8 MoreCamsButton2Select_b;
  uint8 XIcon_b;
  uint8 Frameset1AndTopRearText_b;
  uint8 Frameset1AndTopFrontText_b;
  uint8 Frameset2AndRearCrossText_b;
  uint8 Frameset2AndFrontCrossText_b;
  uint8 ZoomPlus_Selectable_b;
  uint8 ZoomPlus_Not_Selectable_b;
  uint8 ZoomMinus_Selectable_b;
  uint8 ZoomMinus_Not_Selectable_b;
  uint8 MoreCamsIconFullScreenNoSelect_b;
  uint8 Auto_NoSelect_b;
  uint8 Auto_Select_b;
  uint8 TopViewFrontDynamics_b;
  uint8 FrontViewDynamics_b;
  uint8 TopViewRearDynamics_b;
  uint8 RearViewDynamics_b;
  uint8 FrontTireTracks_b;
  uint8 BackDoorClose_Icon_b;
  uint8 RightDoorRearClose_Icon_b;
  uint8 RightDoorFrontClose_Icon_b;
  uint8 LeftDoorRearClose_Icon_b;
  uint8 LeftDoorFrontClose_Icon_b;
  uint8 BackDoorOpen_Icon_b;
  uint8 RightDoorRearOpen_Icon_b;
  uint8 RightDoorFrontOpen_Icon_b;
  uint8 LeftDoorRearOpen_Icon_b;
  uint8 LeftDoorFrontOpen_Icon_b;
  uint8 TopViewBlack_b;
  uint8 RightCam_NA_b;
  uint8 BackCam_NA_b;
  uint8 LeftCam_NA_b;
  uint8 FrontCam_NA_b;
  uint8 DefaultEngLang_b;
  uint8 EnableStaticGuidelines_b;
  uint8 DoorSigFault_b;
  uint8 Reserved_15_b;
  uint8 TRSC_TrailerRed;
  uint8 TRSC_Enable;
  uint8 THA_Updated_b;
  uint8 THA_ProgressBar;
  uint8 THA_StartButton;
  uint8 THA_ConfirmButton;
  uint8 THA_ButtonSelectable;
  uint8 THA_ButtonGrey;
  uint8 THA_CouplerBulletIcon;
  uint8 THA_TriangleOverlay;
  uint8 PDC_RearLeft_Red_b;
  uint8 PDC_RearLeft_Yellow_b;
  uint8 PDC_RearRight_Red_b;
  uint8 PDC_RearRight_Yellow_b;
  uint8 PDC_RearCenter_Red_b;
  uint8 PDC_RearCenter_Yellow_b;
  uint8 PDC_FrontLeft_Red_b;
  uint8 PDC_FrontLeft_Yellow_b;
  uint8 PDC_FrontRight_Red_b;
  uint8 PDC_FrontRight_Yellow_b;
  uint8 PDC_FrontCenter_Red_b;
  uint8 PDC_FrontCenter_Yellow_b;
  uint8 AP_BackBtn;
  uint8 AP_ParkBtn_Selected;
  uint8 AP_ParkBtn_Not_Selected;
  uint8 AP_ExitBtn_Selected;
  uint8 AP_ExitBtn_Not_Selected;
  uint8 AP_Disclaimer_Core;
  uint8 AP_BG_Main;
  uint8 AP_Para_Exit_Core;
  uint8 AP_Forward_LeftBtn_Selected;
  uint8 AP_Forward_LeftBtn_Not_Selected;
  uint8 AP_Forward_RightBtn_Selected;
  uint8 AP_Forward_RightBtn_Not_Selected;
  uint8 AP_Perp_Right_Core;
  uint8 AP_Perp_Left_Core;
  uint8 AP_RearInBtn_Not_Selected;
  uint8 AP_RearInBtn_Selected;
  uint8 AP_FrontInBtn_Not_Selected;
  uint8 AP_FrontInBtn_Selected;
  uint8 AP_RearInBtn_Not_Avail;
  uint8 AP_FrontInBtn_Not_Avail;
  uint8 AP_Parkout_Done;
  uint8 AP_ParkIn_Done;
  uint8 AP_Scanning_Core;
  uint8 AP_Grey_Banner1;
  uint8 AP_Grey_Banner2;
  uint8 AP_Scan_Select_Space_Text;
  uint8 AP_Scan_Space_Found_Text;
  uint8 AP_Scan_STOP_Text;
  uint8 AP_Scan_Searching_Text;
  uint8 AP_Scan_Keep_Moving_Forward_Text;
  uint8 AP_Scan_Reduce_Speed_Text;
  uint8 AP_FullscreenText_Updated;
  uint8 AP_ParksenseUnavailable;
  uint8 AP_TopBlackBannerUpdated;
  uint8 AP_BottomBlackBannerUpdated;
  uint8 AP_RedBannerUpdated;
  uint8 AP_ParkSlots_Updated;
  uint8 SrvPrgBar999Per_b;
  uint8 SrvPrgBar100Per_b;
  uint8 SrvPrgBar75Per_b;
  uint8 SrvPrgBar50Per_b;
  uint8 SrvPrgBar25Per_b;
  uint8 SrvPrgBar0Per_b;
  uint8 SrvCamIndRiNone_b;
  uint8 SrvCamIndRiPend_b;
  uint8 SrvCamIndRiNok_b;
  uint8 SrvCamIndRiOk_b;
  uint8 SrvCamIndBaNone_b;
  uint8 SrvCamIndBaPend_b;
  uint8 SrvCamIndBaNok_b;
  uint8 SrvCamIndBaOk_b;
  uint8 SrvCamIndLeNone_b;
  uint8 SrvCamIndLePend_b;
  uint8 SrvCamIndLeNok_b;
  uint8 SrvCamIndLeOk_b;
  uint8 SrvCamIndFrNone_b;
  uint8 SrvCamIndFrPend_b;
  uint8 SrvCamIndFrNok_b;
  uint8 SrvCamIndFrOk_b;
  uint8 SrvChkIndCondNok_b;
  uint8 SrvChkIndNok_b;
  uint8 SrvChkIndOk_b;
  uint8 SrvChkIndRun_b;
  uint8 SrvSpOmIndNok_b;
  uint8 SrvSpOmIndOk_b;
  uint8 SrvStAngIndNok_b;
  uint8 SrvStAngIndOk_b;
  uint8 SrvLayout_b;
  uint8 Reserved_01_b;
  uint8 Reserved_02_b;
  uint8 Reserved_03_b;
  uint8 Reserved_04_b;
  uint8 Reserved_05_b;
  uint8 Reserved_06_b;
  uint8 Reserved_07_b;
  uint8 Reserved_08_b;
  uint8 Reserved_09_b;
  uint8 Reserved_10_b;
  uint8 Reserved_11_b;
  uint8 Reserved_12_b;
  uint8 Reserved_13_b;
  uint8 Reserved_14_b;
  uint8 OneCam_ZoomPlus_Selectable_b;
  uint8 OneCam_ZoomPlus_Not_Selectable_b;
  uint8 OneCam_ZoomMinus_Selectable_b;
  uint8 OneCam_ZoomMinus_Not_Selectable_b;
  uint8 OneCam_AuxCamButtonSelect_b;
  uint8 OneCam_AuxCamButtonNoSelect_b;
} OverlayBits_t;

# define Rte_TypeDef_Point2f_c
typedef struct
{
  float32 x;
  float32 y;
} Point2f_c;

# define Rte_TypeDef_Point2i_c
typedef struct
{
  sint32 x;
  sint32 y;
} Point2i_c;

# define Rte_TypeDef_Point3f_c
typedef struct
{
  float32 x;
  float32 y;
  float32 z;
} Point3f_c;

# define Rte_TypeDef_RearBrkData_t
typedef struct
{
  uint16 Odometer_u16;
  uint16 GasPedalPosEvntStart_u16;
  uint16 StreeringWhlAngEvntStart_u16;
  uint16 VehicleSpeed_u16;
  uint8 ExtTemp_u8;
  uint16 DistToObjEvntStart_u16;
  uint16 DistToObjEvntEnd_u16;
} RearBrkData_t;

# define Rte_TypeDef_RunTimeStats_MPU1_0_t
typedef struct
{
  uint32 APA_Runtime;
  uint32 CALSM_Runtime;
  uint32 CALSMThread_Runtime;
  uint32 DLDThread_Runtime;
  uint32 DLD_Runtime;
  uint32 PLDThread_Runtime;
  uint32 EOL_Runtime;
  uint32 EOLThread_Runtime;
  uint32 MOT_Runtime;
  uint32 OC_Runtime;
  uint32 OCThread_Runtime;
  uint32 OD_Runtime;
  uint32 ODThread_Runtime;
  uint32 OVL3D_Runtime;
  uint32 RenderThread_Runtime;
  uint32 TAD_Runtime;
  uint32 TADThread_Runtime;
  uint32 THA_Runtime;
  uint32 THAThread_Runtime;
  uint32 TIOVXThread_Runtime;
  uint32 TIOVX_Runtime;
  uint32 CameraCalib_Runtime;
  uint32 VideoInput_Runtime;
  uint32 AppM_Runtime;
  uint32 LogM_Runtime;
  uint32 KeepAlive_Runtime;
  uint32 ThreadMsgSndr_Runtime;
  uint32 SigM_Runtime;
  uint32 ThreadSigM_Runtime;
  uint32 Sys_Runtime;
  uint32 SysMon_Runtime;
  uint32 VarM_Runtime;
  uint32 AlgoViewThread_Runtime;
} RunTimeStats_MPU1_0_t;

# define Rte_TypeDef_SPMAbrtData_t
typedef struct
{
  uint8 ManeuverType_u8;
  uint8 CurbDetected_u8;
  uint8 SideofVehicle_u8;
  uint8 Reserved_u8;
  uint16 MeasuredSlotSize_u16;
  uint8 SWA_State_u8;
  uint8 TTC_State_u8;
  uint8 YRS_State_u8;
  uint16 ExternalTemperature_u16;
  uint8 Reserved1_u8;
  uint16 CalculatedTireSize_u16;
  uint8 NumofManeuvers_u8;
  uint8 AbortCnd_u8;
} SPMAbrtData_t;

# define Rte_TypeDef_SVS_NVMData_t
typedef struct
{
  boolean IeSVS_b_isDynGridPrstFromNVM;
  boolean IeSVS_b_isFwdCamGridPrstFromNVM;
} SVS_NVMData_t;

# define Rte_TypeDef_TbAP_VCStateOut_t
typedef struct
{
  float32 MeAP_e_Park_state;
  sint8 MeAP_e_PP_state;
  uint8 IeAP_cnt_CurrentVehSweep;
  boolean MeAP_b_ManeuverAbort;
  boolean MeAP_b_ManeuverSuccess;
  boolean MeAP_b_PosMet;
  boolean MeAP_b_SteerActionReq;
  boolean IeAP_b_MnvPosOk;
} TbAP_VCStateOut_t;

# define Rte_TypeDef_TbFA_ResetKM_t
typedef struct
{
  boolean MeFA_b_ResetKM;
} TbFA_ResetKM_t;

# define Rte_TypeDef_US_ME_FiringSensorsOutputBuff_t
typedef struct
{
  uint32 timestamp;
  uint16 firingSensors;
  uint16 rsv;
} US_ME_FiringSensorsOutputBuff_t;

# define Rte_TypeDef_US_ME_SnsDat_Front_Direct_2_t
typedef struct
{
  uint16 Sig_SnrDat_FSR_Dir2_cm;
  uint16 Sig_SnrDat_FOR_Dir2_cm;
  uint16 Sig_SnrDat_FIR_Dir2_cm;
  uint16 Sig_SnrDat_FIL_Dir2_cm;
  uint16 Sig_SnrDat_FOL_Dir2_cm;
  uint16 Sig_SnrDat_FSL_Dir2_cm;
} US_ME_SnsDat_Front_Direct_2_t;

# define Rte_TypeDef_US_ME_SnsDat_Front_Direct_t
typedef struct
{
  uint16 Sig_SnrDat_FSR_Dir1_cm;
  uint16 Sig_SnrDat_FOR_Dir1_cm;
  uint16 Sig_SnrDat_FIR_Dir1_cm;
  uint16 Sig_SnrDat_FIL_Dir1_cm;
  uint16 Sig_SnrDat_FOL_Dir1_cm;
  uint16 Sig_SnrDat_FSL_Dir1_cm;
} US_ME_SnsDat_Front_Direct_t;

# define Rte_TypeDef_US_ME_SnsDat_RearSide_Echoes_t
typedef struct
{
  uint16 Sig_SnsDat_RSL_Timestamp_us;
  uint16 Sig_SnsDat_RSL_DirEcho1_cm;
  uint16 Sig_SnsDat_RSL_DirEcho2_cm;
  uint16 Sig_SnsDat_RSR_Timestamp_us;
  uint16 Sig_SnsDat_RSR_DirEcho1_cm;
  uint16 Sig_SnsDat_RSR_DirEcho2_cm;
} US_ME_SnsDat_RearSide_Echoes_t;

# define Rte_TypeDef_US_ME_SnsDat_Rear_Direct_2_t
typedef struct
{
  uint16 Sig_SnrDat_RSR_Dir2_cm;
  uint16 Sig_SnrDat_ROR_Dir2_cm;
  uint16 Sig_SnrDat_RIR_Dir2_cm;
  uint16 Sig_SnrDat_RIL_Dir2_cm;
  uint16 Sig_SnrDat_ROL_Dir2_cm;
  uint16 Sig_SnrDat_RSL_Dir2_cm;
} US_ME_SnsDat_Rear_Direct_2_t;

# define Rte_TypeDef_US_ME_SnsDat_Rear_Direct_t
typedef struct
{
  uint16 Sig_SnrDat_RSR_Dir1_cm;
  uint16 Sig_SnrDat_ROR_Dir1_cm;
  uint16 Sig_SnrDat_RIR_Dir1_cm;
  uint16 Sig_SnrDat_RIL_Dir1_cm;
  uint16 Sig_SnrDat_ROL_Dir1_cm;
  uint16 Sig_SnrDat_RSL_Dir1_cm;
} US_ME_SnsDat_Rear_Direct_t;

# define Rte_TypeDef_US_S_BlockageBit_t
typedef struct
{
  uint32 timestamp;
  uint16 blockageFlagBits;
  uint16 Rsv;
} US_S_BlockageBit_t;

# define Rte_TypeDef_US_S_CsmStateChangeReason_Type
typedef struct
{
  uint8 CsmStateCurrent;
  uint8 CsmStatePreviuos;
  uint8 CsmLocalModuleId;
  uint8 CsmLocalModuleInstanceId;
  uint8 CsmLocalErrOrEventId;
  uint8 CsmLocalErrOrEventState;
} US_S_CsmStateChangeReason_Type;

# define Rte_TypeDef_US_S_DiagnosticsOutputBuff_t
typedef struct
{
  uint32 timestamp;
  uint16 overTempFault;
  uint16 commFault;
  uint16 commUnknown;
  uint16 hardwareFault;
} US_S_DiagnosticsOutputBuff_t;

# define Rte_TypeDef_US_S_DrivingFrequency_t
typedef struct
{
  uint16 uDrvFreq_FSR;
  uint16 uDrvFreq_FOR;
  uint16 uDrvFreq_FIR;
  uint16 uDrvFreq_FIL;
  uint16 uDrvFreq_FOL;
  uint16 uDrvFreq_FSL;
  uint16 uDrvFreq_RSR;
  uint16 uDrvFreq_ROR;
  uint16 uDrvFreq_RIR;
  uint16 uDrvFreq_RIL;
  uint16 uDrvFreq_ROL;
  uint16 uDrvFreq_RSL;
} US_S_DrivingFrequency_t;

# define Rte_TypeDef_US_S_PointOutputBuff_t
typedef struct
{
  sint16 x;
  sint16 y;
  uint8 height;
  uint8 Cruising_Age;
  uint8 confidence;
  uint8 age;
} US_S_PointOutputBuff_t;

# define Rte_TypeDef_US_S_RigningFrequency_t
typedef struct
{
  uint16 uRingFreq_FSR;
  uint16 uRingFreq_FOR;
  uint16 uRingFreq_FIR;
  uint16 uRingFreq_FIL;
  uint16 uRingFreq_FOL;
  uint16 uRingFreq_FSL;
  uint16 uRingFreq_RSR;
  uint16 uRingFreq_ROR;
  uint16 uRingFreq_RIR;
  uint16 uRingFreq_RIL;
  uint16 uRingFreq_ROL;
  uint16 uRingFreq_RSL;
} US_S_RigningFrequency_t;

# define Rte_TypeDef_US_S_RigningTime_t
typedef struct
{
  uint16 uRingTime_FSR;
  uint16 uRingTime_FOR;
  uint16 uRingTime_FIR;
  uint16 uRingTime_FIL;
  uint16 uRingTime_FOL;
  uint16 uRingTime_FSL;
  uint16 uRingTime_RSR;
  uint16 uRingTime_ROR;
  uint16 uRingTime_RIR;
  uint16 uRingTime_RIL;
  uint16 uRingTime_ROL;
  uint16 uRingTime_RSL;
} US_S_RigningTime_t;

# define Rte_TypeDef_US_S_SnrIMESerialNum_t
typedef struct
{
  uint32 uSnrIMESerialNum_FSR;
  uint32 uSnrIMESerialNum_FOR;
  uint32 uSnrIMESerialNum_FIR;
  uint32 uSnrIMESerialNum_FIL;
  uint32 uSnrIMESerialNum_FOL;
  uint32 uSnrIMESerialNum_FSL;
  uint32 uSnrIMESerialNum_RSR;
  uint32 uSnrIMESerialNum_ROR;
  uint32 uSnrIMESerialNum_RIR;
  uint32 uSnrIMESerialNum_RIL;
  uint32 uSnrIMESerialNum_ROL;
  uint32 uSnrIMESerialNum_RSL;
} US_S_SnrIMESerialNum_t;

# define Rte_TypeDef_US_S_SnrMurataSerialNum_t
typedef struct
{
  uint64 uSnrMurataSerialNum_FSR;
  uint64 uSnrMurataSerialNum_FOR;
  uint64 uSnrMurataSerialNum_FIR;
  uint64 uSnrMurataSerialNum_FIL;
  uint64 uSnrMurataSerialNum_FOL;
  uint64 uSnrMurataSerialNum_FSL;
  uint64 uSnrMurataSerialNum_RSR;
  uint64 uSnrMurataSerialNum_ROR;
  uint64 uSnrMurataSerialNum_RIR;
  uint64 uSnrMurataSerialNum_RIL;
  uint64 uSnrMurataSerialNum_ROL;
  uint64 uSnrMurataSerialNum_RSL;
} US_S_SnrMurataSerialNum_t;

# define Rte_TypeDef_US_S_SnrPowerSupply_t
typedef struct
{
  uint16 uUSSPowerAMonVtg;
  uint16 uUSSPowerBMonVtg;
  uint16 uUSSPowerCMonVtg;
  uint16 uUSSPowerIS1Current;
  uint16 uUSSPowerIS2Current;
  uint16 Reserved;
} US_S_SnrPowerSupply_t;

# define Rte_TypeDef_US_S_uBlockageClrCnt_t
typedef struct
{
  uint16 uBlockageClrCnt_FSR;
  uint16 uBlockageClrCnt_FOR;
  uint16 uBlockageClrCnt_FIR;
  uint16 uBlockageClrCnt_FIL;
  uint16 uBlockageClrCnt_FOL;
  uint16 uBlockageClrCnt_FSL;
  uint16 uBlockageClrCnt_RSR;
  uint16 uBlockageClrCnt_ROR;
  uint16 uBlockageClrCnt_RIR;
  uint16 uBlockageClrCnt_RIL;
  uint16 uBlockageClrCnt_ROL;
  uint16 uBlockageClrCnt_RSL;
} US_S_uBlockageClrCnt_t;

# define Rte_TypeDef_US_S_uBlockageSetCnt_t
typedef struct
{
  uint16 uBlockageSetCnt_FSR;
  uint16 uBlockageSetCnt_FOR;
  uint16 uBlockageSetCnt_FIR;
  uint16 uBlockageSetCnt_FIL;
  uint16 uBlockageSetCnt_FOL;
  uint16 uBlockageSetCnt_FSL;
  uint16 uBlockageSetCnt_RSR;
  uint16 uBlockageSetCnt_ROR;
  uint16 uBlockageSetCnt_RIR;
  uint16 uBlockageSetCnt_RIL;
  uint16 uBlockageSetCnt_ROL;
  uint16 uBlockageSetCnt_RSL;
} US_S_uBlockageSetCnt_t;

# define Rte_TypeDef_WdgCheckpointStatus_t
typedef struct
{
  uint16 timeoutCntr_u16;
  uint16 seid_s;
  uint32 wdgDataLiveCntr_u32;
} WdgCheckpointStatus_t;

# define Rte_TypeDef_aZynqM_S_EOL_Conditions_t
typedef struct
{
  boolean LeftFrontDoor_b;
  boolean RightFrontDoor_b;
  boolean LeftRearDoor_b;
  boolean RightRearDoor_b;
  boolean Hood_b;
  boolean Tailgate_b;
  boolean InnerTailgate_b;
  boolean LeftMirror_b;
  boolean RightMirror_b;
  boolean VehicleLevel_b;
  boolean ZynqModuleState_b;
} aZynqM_S_EOL_Conditions_t;

# define Rte_TypeDef_aZynqM_S_OC_Conditions_t
typedef struct
{
  boolean Configuration_b;
  boolean ApprovedByApplication_b;
  boolean EOLSCCalibration_b;
  boolean DrivingForward;
  boolean SpeedValid_b;
  boolean IgnitionState_b;
} aZynqM_S_OC_Conditions_t;

# define Rte_TypeDef_aZynqM_S_SCConditions_t
typedef struct
{
  boolean LeftFrontDoor_b;
  boolean RightFrontDoor_b;
  boolean LeftRearDoor_b;
  boolean RightRearDoor_b;
  boolean Hood_b;
  boolean Tailgate_b;
  boolean DrivingForward;
  boolean SpeedValid_b;
  boolean LeftMirror_b;
  boolean RightMirror_b;
  boolean VehicleLevel_b;
  boolean SteeringAngle_b;
} aZynqM_S_SCConditions_t;

# define Rte_TypeDef_ADAStatusType
typedef uint8 ADAStatusType;

# define Rte_TypeDef_CM_TCH_X_COORD
typedef uint16 CM_TCH_X_COORD;

# define Rte_TypeDef_CM_TCH_Y_COORD
typedef uint16 CM_TCH_Y_COORD;

# define Rte_TypeDef_CRC_ADAS_INFO_C2
typedef uint8 CRC_ADAS_INFO_C2;

# define Rte_TypeDef_CRC_AGSM2
typedef uint8 CRC_AGSM2;

# define Rte_TypeDef_CRC_BCM10
typedef uint8 CRC_BCM10;

# define Rte_TypeDef_CRC_BCM12
typedef uint8 CRC_BCM12;

# define Rte_TypeDef_CRC_BCM2
typedef uint8 CRC_BCM2;

# define Rte_TypeDef_CRC_BCM27
typedef uint8 CRC_BCM27;

# define Rte_TypeDef_CRC_BCM29
typedef uint8 CRC_BCM29;

# define Rte_TypeDef_CRC_BCM9
typedef uint8 CRC_BCM9;

# define Rte_TypeDef_CRC_BRAKE1
typedef uint8 CRC_BRAKE1;

# define Rte_TypeDef_CRC_BRAKE2
typedef uint8 CRC_BRAKE2;

# define Rte_TypeDef_CRC_BRAKE2_1
typedef uint8 CRC_BRAKE2_1;

# define Rte_TypeDef_CRC_BRAKE4
typedef uint8 CRC_BRAKE4;

# define Rte_TypeDef_CRC_BRAKE5
typedef uint8 CRC_BRAKE5;

# define Rte_TypeDef_CRC_BRAKE7
typedef uint8 CRC_BRAKE7;

# define Rte_TypeDef_CRC_CVPAM_FD_Control
typedef uint8 CRC_CVPAM_FD_Control;

# define Rte_TypeDef_CRC_CVPAM_FD_Data
typedef uint8 CRC_CVPAM_FD_Data;

# define Rte_TypeDef_CRC_CVPAM_FD_Data2
typedef uint8 CRC_CVPAM_FD_Data2;

# define Rte_TypeDef_CRC_CVPAM_FD_Info
typedef uint8 CRC_CVPAM_FD_Info;

# define Rte_TypeDef_CRC_ENGINE2
typedef uint8 CRC_ENGINE2;

# define Rte_TypeDef_CRC_ENGINE5
typedef uint8 CRC_ENGINE5;

# define Rte_TypeDef_CRC_ENGINE7
typedef uint8 CRC_ENGINE7;

# define Rte_TypeDef_CRC_EPS1
typedef uint8 CRC_EPS1;

# define Rte_TypeDef_CRC_EPS2
typedef uint8 CRC_EPS2;

# define Rte_TypeDef_CRC_GLOB_NAV_C2
typedef uint8 CRC_GLOB_NAV_C2;

# define Rte_TypeDef_CRC_TRANSM1
typedef uint8 CRC_TRANSM1;

# define Rte_TypeDef_CRC_TRANSM2
typedef uint8 CRC_TRANSM2;

# define Rte_TypeDef_CRC_TRANSM4
typedef uint8 CRC_TRANSM4;

# define Rte_TypeDef_CRC_TRSCM1
typedef uint8 CRC_TRSCM1;

# define Rte_TypeDef_CRC_TRSKM_FD_1
typedef uint8 CRC_TRSKM_FD_1;

# define Rte_TypeDef_CRC_Telematic11
typedef uint8 CRC_Telematic11;

# define Rte_TypeDef_CRC_Telematic14
typedef uint8 CRC_Telematic14;

# define Rte_TypeDef_CRC_Telematic5
typedef uint8 CRC_Telematic5;

# define Rte_TypeDef_CRC__BRAKE3
typedef uint8 CRC__BRAKE3;

# define Rte_TypeDef_CRC__DRIVETRAIN3
typedef uint8 CRC__DRIVETRAIN3;

# define Rte_TypeDef_Cntr_ADAS_FD_LANES_1
typedef uint16 Cntr_ADAS_FD_LANES_1;

# define Rte_TypeDef_Cntr_ADAS_FD_LANES_2
typedef uint16 Cntr_ADAS_FD_LANES_2;

# define Rte_TypeDef_Cntr_CVPAM_FD_Data
typedef uint16 Cntr_CVPAM_FD_Data;

# define Rte_TypeDef_Cntr_CVPAM_FD_Data2
typedef uint16 Cntr_CVPAM_FD_Data2;

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint16 ComM_UserHandleType;

# define Rte_TypeDef_Csm_ConfigIdType
typedef uint16 Csm_ConfigIdType;

# define Rte_TypeDef_DataPrimitiveType_uint16
typedef uint16 DataPrimitiveType_uint16;

# define Rte_TypeDef_DataPrimitiveType_uint8
typedef uint8 DataPrimitiveType_uint8;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType
typedef uint8 Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType
typedef uint8 Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType
typedef uint8 Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType
typedef uint8 Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_3101D003_Application_Logical_Block_Hash_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_3101D003_Application_Logical_Block_Hash_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType
typedef uint8 Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101D003_Application_Logical_Block_Hash_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_3101D003_Application_Logical_Block_Hash_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101F000_Check_Program_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_3101F000_Check_Program_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101FF00_FlashErase_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_3101FF00_FlashErase_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType
typedef uint8 Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType;

# define Rte_TypeDef_Dem_DTCGroupType
typedef uint32 Dem_DTCGroupType;

# define Rte_TypeDef_Dem_DTCStatusMaskType
typedef uint8 Dem_DTCStatusMaskType;

# define Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;

# define Rte_TypeDef_Dem_RatioIdType
typedef uint16 Dem_RatioIdType;

# define Rte_TypeDef_DeviceAddress
typedef uint8 DeviceAddress;

# define Rte_TypeDef_Digit_01
typedef uint8 Digit_01;

# define Rte_TypeDef_Digit_01_PAM
typedef uint8 Digit_01_PAM;

# define Rte_TypeDef_Digit_02
typedef uint8 Digit_02;

# define Rte_TypeDef_Digit_02_PAM
typedef uint8 Digit_02_PAM;

# define Rte_TypeDef_Digit_03
typedef uint8 Digit_03;

# define Rte_TypeDef_Digit_03_PAM
typedef uint8 Digit_03_PAM;

# define Rte_TypeDef_Digit_04
typedef uint8 Digit_04;

# define Rte_TypeDef_Digit_04_PAM
typedef uint8 Digit_04_PAM;

# define Rte_TypeDef_Digit_05
typedef uint8 Digit_05;

# define Rte_TypeDef_Digit_05_PAM
typedef uint8 Digit_05_PAM;

# define Rte_TypeDef_Digit_06
typedef uint8 Digit_06;

# define Rte_TypeDef_Digit_06_PAM
typedef uint8 Digit_06_PAM;

# define Rte_TypeDef_Digit_07
typedef uint8 Digit_07;

# define Rte_TypeDef_Digit_07_PAM
typedef uint8 Digit_07_PAM;

# define Rte_TypeDef_Digit_08
typedef uint8 Digit_08;

# define Rte_TypeDef_Digit_08_PAM
typedef uint8 Digit_08_PAM;

# define Rte_TypeDef_Digit_09
typedef uint8 Digit_09;

# define Rte_TypeDef_Digit_09_PAM
typedef uint8 Digit_09_PAM;

# define Rte_TypeDef_Digit_10
typedef uint8 Digit_10;

# define Rte_TypeDef_Digit_10_PAM
typedef uint8 Digit_10_PAM;

# define Rte_TypeDef_Digit_11
typedef uint8 Digit_11;

# define Rte_TypeDef_Digit_11_PAM
typedef uint8 Digit_11_PAM;

# define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_ErrorMgr_ErrorField
typedef uint8 ErrorMgr_ErrorField;

# define Rte_TypeDef_FD02_CADM2_64
typedef uint64 FD02_CADM2_64;

# define Rte_TypeDef_FD02_TRLR_REV_64
typedef uint64 FD02_TRLR_REV_64;

# define Rte_TypeDef_FD14_1_AliveCntr_MCU2_0
typedef uint8 FD14_1_AliveCntr_MCU2_0;

# define Rte_TypeDef_FD14_1_AliveCntr_MCU2_1
typedef uint8 FD14_1_AliveCntr_MCU2_1;

# define Rte_TypeDef_FD14_1_AliveCntr_MPU1_0
typedef uint8 FD14_1_AliveCntr_MPU1_0;

# define Rte_TypeDef_FD14_1_ErrFaultInfo_MCU2_0
typedef uint16 FD14_1_ErrFaultInfo_MCU2_0;

# define Rte_TypeDef_FD14_1_Err_FaultInfo_MCU1_0
typedef uint16 FD14_1_Err_FaultInfo_MCU1_0;

# define Rte_TypeDef_FD14_1_Err_FaultInfo_MCU2_1
typedef uint16 FD14_1_Err_FaultInfo_MCU2_1;

# define Rte_TypeDef_FD14_1_Err_FaultInfo_MPU1_0
typedef uint16 FD14_1_Err_FaultInfo_MPU1_0;

# define Rte_TypeDef_FD14_1_Err_FaultNum_MCU1_0
typedef uint8 FD14_1_Err_FaultNum_MCU1_0;

# define Rte_TypeDef_FD14_1_Err_FaultNum_MCU2_0
typedef uint8 FD14_1_Err_FaultNum_MCU2_0;

# define Rte_TypeDef_FD14_1_Err_FaultNum_MCU2_1
typedef uint8 FD14_1_Err_FaultNum_MCU2_1;

# define Rte_TypeDef_FD14_1_Err_FaultNum_MPU1_0
typedef uint8 FD14_1_Err_FaultNum_MPU1_0;

# define Rte_TypeDef_FD14_1_Hook_DtErr_MCU1_0
typedef uint16 FD14_1_Hook_DtErr_MCU1_0;

# define Rte_TypeDef_FD14_1_Hook_Error_MCU1_0
typedef uint8 FD14_1_Hook_Error_MCU1_0;

# define Rte_TypeDef_FD14_1_Hook_PresentPtr_MCU1_0
typedef uint32 FD14_1_Hook_PresentPtr_MCU1_0;

# define Rte_TypeDef_FD14_1_Hook_Reserved_MCU1_0
typedef uint16 FD14_1_Hook_Reserved_MCU1_0;

# define Rte_TypeDef_FD14_1_Hook_Service_MCU1_0
typedef uint16 FD14_1_Hook_Service_MCU1_0;

# define Rte_TypeDef_FD14_1_Hook_Type_MCU1_0
typedef uint8 FD14_1_Hook_Type_MCU1_0;

# define Rte_TypeDef_FD14_1_Hook_actTsk_MCU1_0
typedef uint8 FD14_1_Hook_actTsk_MCU1_0;

# define Rte_TypeDef_FD14_1_Hook_fatalErr_MCU1_0
typedef uint8 FD14_1_Hook_fatalErr_MCU1_0;

# define Rte_TypeDef_FD14_1_OsRegMCU_ADFSR
typedef uint32 FD14_1_OsRegMCU_ADFSR;

# define Rte_TypeDef_FD14_1_OsRegMCU_AIFSR
typedef uint32 FD14_1_OsRegMCU_AIFSR;

# define Rte_TypeDef_FD14_1_OsRegMCU_DFAR
typedef uint32 FD14_1_OsRegMCU_DFAR;

# define Rte_TypeDef_FD14_1_OsRegMCU_DFSR
typedef uint32 FD14_1_OsRegMCU_DFSR;

# define Rte_TypeDef_FD14_1_OsRegMCU_IFAR
typedef uint32 FD14_1_OsRegMCU_IFAR;

# define Rte_TypeDef_FD14_1_OsRegMCU_IFSR
typedef uint32 FD14_1_OsRegMCU_IFSR;

# define Rte_TypeDef_FD14_1_OsRegMCU_Link
typedef uint32 FD14_1_OsRegMCU_Link;

# define Rte_TypeDef_FD14_1_OsRegMCU_SPSR
typedef uint32 FD14_1_OsRegMCU_SPSR;

# define Rte_TypeDef_FD14_1_OsRegMCU_Stack0
typedef uint32 FD14_1_OsRegMCU_Stack0;

# define Rte_TypeDef_FD14_1_OsRegMCU_Stack1
typedef uint32 FD14_1_OsRegMCU_Stack1;

# define Rte_TypeDef_FD14_1_OsRegMCU_Stack2
typedef uint32 FD14_1_OsRegMCU_Stack2;

# define Rte_TypeDef_FD14_1_OsRegMCU_Stack3
typedef uint32 FD14_1_OsRegMCU_Stack3;

# define Rte_TypeDef_FD14_1_OsRegMCU_Stack4
typedef uint32 FD14_1_OsRegMCU_Stack4;

# define Rte_TypeDef_FD14_1_OsRegMCU_Stack5
typedef uint32 FD14_1_OsRegMCU_Stack5;

# define Rte_TypeDef_FD14_1_OsRegMCU_Stack6
typedef uint32 FD14_1_OsRegMCU_Stack6;

# define Rte_TypeDef_FD14_1_OsRegMCU_Stack7
typedef uint32 FD14_1_OsRegMCU_Stack7;

# define Rte_TypeDef_FD14_1_OsRegMCU_Stack8
typedef uint32 FD14_1_OsRegMCU_Stack8;

# define Rte_TypeDef_FD14_1_OsRegMCU_Stack9
typedef uint32 FD14_1_OsRegMCU_Stack9;

# define Rte_TypeDef_FD14_1_Reserved_MCU1_0
typedef uint8 FD14_1_Reserved_MCU1_0;

# define Rte_TypeDef_FD14_1_Reserved_MCU2_0
typedef uint8 FD14_1_Reserved_MCU2_0;

# define Rte_TypeDef_FD14_1_Reserved_MCU2_1
typedef uint8 FD14_1_Reserved_MCU2_1;

# define Rte_TypeDef_FD14_1_Reserved_MPU1_0
typedef uint8 FD14_1_Reserved_MPU1_0;

# define Rte_TypeDef_FD14_1_SDL_Fault_MCU1_0
typedef uint16 FD14_1_SDL_Fault_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData10_MCU1_0
typedef uint8 FD14_1_SSM_FltData10_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData11_MCU1_0
typedef uint8 FD14_1_SSM_FltData11_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData12_MCU1_0
typedef uint8 FD14_1_SSM_FltData12_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData13_MCU1_0
typedef uint8 FD14_1_SSM_FltData13_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData14_MCU1_0
typedef uint8 FD14_1_SSM_FltData14_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData15_MCU1_0
typedef uint8 FD14_1_SSM_FltData15_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData16_MCU1_0
typedef uint8 FD14_1_SSM_FltData16_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData17_MCU1_0
typedef uint8 FD14_1_SSM_FltData17_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData18_MCU1_0
typedef uint8 FD14_1_SSM_FltData18_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData1_MCU1_0
typedef uint8 FD14_1_SSM_FltData1_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData2_MCU1_0
typedef uint8 FD14_1_SSM_FltData2_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData3_MCU1_0
typedef uint8 FD14_1_SSM_FltData3_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData4_MCU1_0
typedef uint8 FD14_1_SSM_FltData4_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData5_MCU1_0
typedef uint8 FD14_1_SSM_FltData5_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData6_MCU1_0
typedef uint8 FD14_1_SSM_FltData6_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData7_MCU1_0
typedef uint8 FD14_1_SSM_FltData7_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData8_MCU1_0
typedef uint8 FD14_1_SSM_FltData8_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_FltData9_MCU1_0
typedef uint8 FD14_1_SSM_FltData9_MCU1_0;

# define Rte_TypeDef_FD14_1_SSM_SystemStateReq
typedef uint8 FD14_1_SSM_SystemStateReq;

# define Rte_TypeDef_FD14_1_TimeSincePowerON
typedef uint32 FD14_1_TimeSincePowerON;

# define Rte_TypeDef_FD14_1_WDG_Error_ID_MCU1_0
typedef uint16 FD14_1_WDG_Error_ID_MCU1_0;

# define Rte_TypeDef_FD14_AOL_CommUnknown
typedef boolean FD14_AOL_CommUnknown;

# define Rte_TypeDef_FD14_AOL_MinDistance
typedef uint16 FD14_AOL_MinDistance;

# define Rte_TypeDef_FD14_AOL_comm_Fault
typedef boolean FD14_AOL_comm_Fault;

# define Rte_TypeDef_FD14_AOL_hardware_Fault
typedef boolean FD14_AOL_hardware_Fault;

# define Rte_TypeDef_FD14_AOL_overTemp_Fault
typedef boolean FD14_AOL_overTemp_Fault;

# define Rte_TypeDef_FD14_AOR_CommUnknown
typedef boolean FD14_AOR_CommUnknown;

# define Rte_TypeDef_FD14_AOR_MinDistance
typedef uint16 FD14_AOR_MinDistance;

# define Rte_TypeDef_FD14_AOR_comm_Fault
typedef boolean FD14_AOR_comm_Fault;

# define Rte_TypeDef_FD14_AOR_hardware_Fault
typedef boolean FD14_AOR_hardware_Fault;

# define Rte_TypeDef_FD14_AOR_overTemp_Fault
typedef boolean FD14_AOR_overTemp_Fault;

# define Rte_TypeDef_FD14_AutoParkInitializedStatus_b
typedef boolean FD14_AutoParkInitializedStatus_b;

# define Rte_TypeDef_FD14_AuxCamButton1NoSelect_b
typedef boolean FD14_AuxCamButton1NoSelect_b;

# define Rte_TypeDef_FD14_AuxCamButton1Select_b
typedef boolean FD14_AuxCamButton1Select_b;

# define Rte_TypeDef_FD14_AuxCamButton2NoSelect_b
typedef boolean FD14_AuxCamButton2NoSelect_b;

# define Rte_TypeDef_FD14_AuxCamButton2Select_b
typedef boolean FD14_AuxCamButton2Select_b;

# define Rte_TypeDef_FD14_BOL_CommUnknown
typedef boolean FD14_BOL_CommUnknown;

# define Rte_TypeDef_FD14_BOL_MinDistance
typedef uint16 FD14_BOL_MinDistance;

# define Rte_TypeDef_FD14_BOL_comm_Fault
typedef boolean FD14_BOL_comm_Fault;

# define Rte_TypeDef_FD14_BOL_hardware_Fault
typedef boolean FD14_BOL_hardware_Fault;

# define Rte_TypeDef_FD14_BOL_overTemp_Fault
typedef boolean FD14_BOL_overTemp_Fault;

# define Rte_TypeDef_FD14_BOR_CommUnknown
typedef boolean FD14_BOR_CommUnknown;

# define Rte_TypeDef_FD14_BOR_MinDistance
typedef uint16 FD14_BOR_MinDistance;

# define Rte_TypeDef_FD14_BOR_comm_Fault
typedef boolean FD14_BOR_comm_Fault;

# define Rte_TypeDef_FD14_BOR_hardware_Fault
typedef boolean FD14_BOR_hardware_Fault;

# define Rte_TypeDef_FD14_BOR_overTemp_Fault
typedef boolean FD14_BOR_overTemp_Fault;

# define Rte_TypeDef_FD14_BackCam_NA_b
typedef boolean FD14_BackCam_NA_b;

# define Rte_TypeDef_FD14_BackDoorOpen_Icon_b
typedef boolean FD14_BackDoorOpen_Icon_b;

# define Rte_TypeDef_FD14_BackupRearCamButtonNoSelect_b
typedef boolean FD14_BackupRearCamButtonNoSelect_b;

# define Rte_TypeDef_FD14_BackupRearCamButtonSelect_b
typedef boolean FD14_BackupRearCamButtonSelect_b;

# define Rte_TypeDef_FD14_BumberStatus_Front
typedef uint8 FD14_BumberStatus_Front;

# define Rte_TypeDef_FD14_BumberStatus_Left_Side
typedef uint8 FD14_BumberStatus_Left_Side;

# define Rte_TypeDef_FD14_BumberStatus_Rear
typedef uint8 FD14_BumberStatus_Rear;

# define Rte_TypeDef_FD14_BumberStatus_Right_Side
typedef uint8 FD14_BumberStatus_Right_Side;

# define Rte_TypeDef_FD14_CAM_NA_Bitfield_u8
typedef uint8 FD14_CAM_NA_Bitfield_u8;

# define Rte_TypeDef_FD14_CRC_ADAS_FD_INFO
typedef uint8 FD14_CRC_ADAS_FD_INFO;

# define Rte_TypeDef_FD14_CRC_BRAKE1
typedef uint8 FD14_CRC_BRAKE1;

# define Rte_TypeDef_FD14_CRC_BRAKE2
typedef uint8 FD14_CRC_BRAKE2;

# define Rte_TypeDef_FD14_CRC_BRAKE4
typedef uint8 FD14_CRC_BRAKE4;

# define Rte_TypeDef_FD14_CRC_BRAKE5
typedef uint8 FD14_CRC_BRAKE5;

# define Rte_TypeDef_FD14_CRC_BRAKE7
typedef uint8 FD14_CRC_BRAKE7;

# define Rte_TypeDef_FD14_CRC_CVPAM_FD_Control
typedef uint8 FD14_CRC_CVPAM_FD_Control;

# define Rte_TypeDef_FD14_CRC_CVPAM_FD_Data
typedef uint8 FD14_CRC_CVPAM_FD_Data;

# define Rte_TypeDef_FD14_CRC_CVPAM_FD_Data2
typedef uint8 FD14_CRC_CVPAM_FD_Data2;

# define Rte_TypeDef_FD14_CRC_ENGINE2
typedef uint8 FD14_CRC_ENGINE2;

# define Rte_TypeDef_FD14_CRC_ENGINE7
typedef uint8 FD14_CRC_ENGINE7;

# define Rte_TypeDef_FD14_CRC_EPS1
typedef uint8 FD14_CRC_EPS1;

# define Rte_TypeDef_FD14_CRC_EPS2
typedef uint8 FD14_CRC_EPS2;

# define Rte_TypeDef_FD14_CRC__BRAKE3
typedef uint8 FD14_CRC__BRAKE3;

# define Rte_TypeDef_FD14_Cntr_ADAS_FD_LANES_1
typedef uint16 FD14_Cntr_ADAS_FD_LANES_1;

# define Rte_TypeDef_FD14_Cntr_ADAS_FD_LANES_2
typedef uint16 FD14_Cntr_ADAS_FD_LANES_2;

# define Rte_TypeDef_FD14_Cntr_CVPAM_FD_Data
typedef uint16 FD14_Cntr_CVPAM_FD_Data;

# define Rte_TypeDef_FD14_Cntr_CVPAM_FD_Data2
typedef uint16 FD14_Cntr_CVPAM_FD_Data2;

# define Rte_TypeDef_FD14_CsmLocalErrOrEventId
typedef uint8 FD14_CsmLocalErrOrEventId;

# define Rte_TypeDef_FD14_CsmLocalModuleInstanceId
typedef uint8 FD14_CsmLocalModuleInstanceId;

# define Rte_TypeDef_FD14_CurrentTrailer_ID
typedef uint8 FD14_CurrentTrailer_ID;

# define Rte_TypeDef_FD14_Current_Firing_Sequence
typedef uint8 FD14_Current_Firing_Sequence;

# define Rte_TypeDef_FD14_Debug_Signal_1
typedef sint16 FD14_Debug_Signal_1;

# define Rte_TypeDef_FD14_Debug_Signal_2
typedef sint16 FD14_Debug_Signal_2;

# define Rte_TypeDef_FD14_Debug_Signal_3
typedef sint16 FD14_Debug_Signal_3;

# define Rte_TypeDef_FD14_Debug_Signal_4
typedef sint16 FD14_Debug_Signal_4;

# define Rte_TypeDef_FD14_Debug_Signal_5
typedef uint16 FD14_Debug_Signal_5;

# define Rte_TypeDef_FD14_Debug_Signal_6
typedef uint16 FD14_Debug_Signal_6;

# define Rte_TypeDef_FD14_Debug_Signal_7
typedef uint16 FD14_Debug_Signal_7;

# define Rte_TypeDef_FD14_Debug_Signal_8
typedef uint16 FD14_Debug_Signal_8;

# define Rte_TypeDef_FD14_FFCV_BTN_PRESSED_b
typedef boolean FD14_FFCV_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_FIL_CommUnknown
typedef boolean FD14_FIL_CommUnknown;

# define Rte_TypeDef_FD14_FIL_MinDistance
typedef uint16 FD14_FIL_MinDistance;

# define Rte_TypeDef_FD14_FIL_comm_Fault
typedef boolean FD14_FIL_comm_Fault;

# define Rte_TypeDef_FD14_FIL_hardware_Fault
typedef boolean FD14_FIL_hardware_Fault;

# define Rte_TypeDef_FD14_FIL_overTemp_Fault
typedef boolean FD14_FIL_overTemp_Fault;

# define Rte_TypeDef_FD14_FIR_CommUnknown
typedef boolean FD14_FIR_CommUnknown;

# define Rte_TypeDef_FD14_FIR_MinDistance
typedef uint16 FD14_FIR_MinDistance;

# define Rte_TypeDef_FD14_FIR_comm_Fault
typedef boolean FD14_FIR_comm_Fault;

# define Rte_TypeDef_FD14_FIR_hardware_Fault
typedef boolean FD14_FIR_hardware_Fault;

# define Rte_TypeDef_FD14_FIR_overTemp_Fault
typedef boolean FD14_FIR_overTemp_Fault;

# define Rte_TypeDef_FD14_FOL_CommUnknown
typedef boolean FD14_FOL_CommUnknown;

# define Rte_TypeDef_FD14_FOL_MinDistance
typedef uint16 FD14_FOL_MinDistance;

# define Rte_TypeDef_FD14_FOL_comm_Fault
typedef boolean FD14_FOL_comm_Fault;

# define Rte_TypeDef_FD14_FOL_hardware_Fault
typedef boolean FD14_FOL_hardware_Fault;

# define Rte_TypeDef_FD14_FOL_overTemp_Fault
typedef boolean FD14_FOL_overTemp_Fault;

# define Rte_TypeDef_FD14_FOR_CommUnknown
typedef boolean FD14_FOR_CommUnknown;

# define Rte_TypeDef_FD14_FOR_MinDistance
typedef uint16 FD14_FOR_MinDistance;

# define Rte_TypeDef_FD14_FOR_comm_Fault
typedef boolean FD14_FOR_comm_Fault;

# define Rte_TypeDef_FD14_FOR_hardware_Fault
typedef boolean FD14_FOR_hardware_Fault;

# define Rte_TypeDef_FD14_FOR_overTemp_Fault
typedef boolean FD14_FOR_overTemp_Fault;

# define Rte_TypeDef_FD14_FRONT_CROSS_BTN_PRESSED_b
typedef boolean FD14_FRONT_CROSS_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_FRONT_TOP_BTN_PRESSED_b
typedef boolean FD14_FRONT_TOP_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_FSL_CommUnknown
typedef boolean FD14_FSL_CommUnknown;

# define Rte_TypeDef_FD14_FSL_MinDistance
typedef uint16 FD14_FSL_MinDistance;

# define Rte_TypeDef_FD14_FSL_comm_Fault
typedef boolean FD14_FSL_comm_Fault;

# define Rte_TypeDef_FD14_FSL_hardware_Fault
typedef boolean FD14_FSL_hardware_Fault;

# define Rte_TypeDef_FD14_FSL_overTemp_Fault
typedef boolean FD14_FSL_overTemp_Fault;

# define Rte_TypeDef_FD14_FSR_CommUnknown
typedef boolean FD14_FSR_CommUnknown;

# define Rte_TypeDef_FD14_FSR_MinDistance
typedef uint16 FD14_FSR_MinDistance;

# define Rte_TypeDef_FD14_FSR_comm_Fault
typedef boolean FD14_FSR_comm_Fault;

# define Rte_TypeDef_FD14_FSR_hardware_Fault
typedef boolean FD14_FSR_hardware_Fault;

# define Rte_TypeDef_FD14_FSR_overTemp_Fault
typedef boolean FD14_FSR_overTemp_Fault;

# define Rte_TypeDef_FD14_FiringMode_TimeStamp
typedef uint32 FD14_FiringMode_TimeStamp;

# define Rte_TypeDef_FD14_FiringSnr_TimeStamp
typedef uint32 FD14_FiringSnr_TimeStamp;

# define Rte_TypeDef_FD14_Firing_Mode_Seq
typedef uint8 FD14_Firing_Mode_Seq;

# define Rte_TypeDef_FD14_Firing_Sensor
typedef uint16 FD14_Firing_Sensor;

# define Rte_TypeDef_FD14_Firing_Sensor_Info_F
typedef uint8 FD14_Firing_Sensor_Info_F;

# define Rte_TypeDef_FD14_Firing_Sensor_Info_R
typedef uint8 FD14_Firing_Sensor_Info_R;

# define Rte_TypeDef_FD14_Frame_Index_Lanes_1
typedef uint16 FD14_Frame_Index_Lanes_1;

# define Rte_TypeDef_FD14_Frame_Index_Lanes_2
typedef uint16 FD14_Frame_Index_Lanes_2;

# define Rte_TypeDef_FD14_Frame_Index_Lanes__1
typedef uint32 FD14_Frame_Index_Lanes__1;

# define Rte_TypeDef_FD14_Frameset1AndTopFrontText_b
typedef boolean FD14_Frameset1AndTopFrontText_b;

# define Rte_TypeDef_FD14_Frameset1AndTopRearText_b
typedef boolean FD14_Frameset1AndTopRearText_b;

# define Rte_TypeDef_FD14_Frameset2AndFrontCrossText_b
typedef boolean FD14_Frameset2AndFrontCrossText_b;

# define Rte_TypeDef_FD14_Frameset2AndRearCrossText_b
typedef boolean FD14_Frameset2AndRearCrossText_b;

# define Rte_TypeDef_FD14_FrontCam_NA_b
typedef boolean FD14_FrontCam_NA_b;

# define Rte_TypeDef_FD14_FrontCrossButtonNoSelect_b
typedef boolean FD14_FrontCrossButtonNoSelect_b;

# define Rte_TypeDef_FD14_FrontCrossButtonSelect_b
typedef boolean FD14_FrontCrossButtonSelect_b;

# define Rte_TypeDef_FD14_FrontFaceCamButtonNoSelect_b
typedef boolean FD14_FrontFaceCamButtonNoSelect_b;

# define Rte_TypeDef_FD14_FrontFaceCamButtonSelect_b
typedef boolean FD14_FrontFaceCamButtonSelect_b;

# define Rte_TypeDef_FD14_FrontTireTracks_b
typedef boolean FD14_FrontTireTracks_b;

# define Rte_TypeDef_FD14_FrontViewDynamics_b
typedef boolean FD14_FrontViewDynamics_b;

# define Rte_TypeDef_FD14_GW_C_I6_timeout_b
typedef boolean FD14_GW_C_I6_timeout_b;

# define Rte_TypeDef_FD14_IeAP_b_MnvPosOk
typedef boolean FD14_IeAP_b_MnvPosOk;

# define Rte_TypeDef_FD14_IeAP_cm_FrntCenterMinXDist
typedef uint16 FD14_IeAP_cm_FrntCenterMinXDist;

# define Rte_TypeDef_FD14_IeAP_cm_FrntCenterMinXDist_KPI
typedef uint16 FD14_IeAP_cm_FrntCenterMinXDist_KPI;

# define Rte_TypeDef_FD14_IeAP_cm_FrntLeftMinXDist
typedef uint16 FD14_IeAP_cm_FrntLeftMinXDist;

# define Rte_TypeDef_FD14_IeAP_cm_FrntLeftMinXDist_KPI
typedef uint16 FD14_IeAP_cm_FrntLeftMinXDist_KPI;

# define Rte_TypeDef_FD14_IeAP_cm_FrntRightMinXDist
typedef uint16 FD14_IeAP_cm_FrntRightMinXDist;

# define Rte_TypeDef_FD14_IeAP_cm_FrntRightMinXDist_KPI
typedef uint16 FD14_IeAP_cm_FrntRightMinXDist_KPI;

# define Rte_TypeDef_FD14_IeAP_cm_RearCenterMinXDist
typedef uint16 FD14_IeAP_cm_RearCenterMinXDist;

# define Rte_TypeDef_FD14_IeAP_cm_RearCenterMinXDist_KPI
typedef uint16 FD14_IeAP_cm_RearCenterMinXDist_KPI;

# define Rte_TypeDef_FD14_IeAP_cm_RearLeftMinXDist
typedef uint16 FD14_IeAP_cm_RearLeftMinXDist;

# define Rte_TypeDef_FD14_IeAP_cm_RearLeftMinXDist_KPI
typedef uint16 FD14_IeAP_cm_RearLeftMinXDist_KPI;

# define Rte_TypeDef_FD14_IeAP_cm_RearRightMinXDist
typedef uint16 FD14_IeAP_cm_RearRightMinXDist;

# define Rte_TypeDef_FD14_IeAP_cm_RearRightMinXDist_KPI
typedef uint16 FD14_IeAP_cm_RearRightMinXDist_KPI;

# define Rte_TypeDef_FD14_IeAP_cnt_CurrentVehSweep
typedef uint8 FD14_IeAP_cnt_CurrentVehSweep;

# define Rte_TypeDef_FD14_IeAP_e_AbortCon
typedef uint8 FD14_IeAP_e_AbortCon;

# define Rte_TypeDef_FD14_IeLMD_e_CameraStatus
typedef uint8 FD14_IeLMD_e_CameraStatus;

# define Rte_TypeDef_FD14_IeTHA_b_ChimeActvLhf
typedef boolean FD14_IeTHA_b_ChimeActvLhf;

# define Rte_TypeDef_FD14_IeTHA_b_ChimeActvRhf
typedef boolean FD14_IeTHA_b_ChimeActvRhf;

# define Rte_TypeDef_FD14_IeTHA_e_PamChimeTyp
typedef uint8 FD14_IeTHA_e_PamChimeTyp;

# define Rte_TypeDef_FD14_IeTHA_e_PamVol
typedef uint8 FD14_IeTHA_e_PamVol;

# define Rte_TypeDef_FD14_IeTRSC_M_TRSCStrTrq
typedef float32 FD14_IeTRSC_M_TRSCStrTrq;

# define Rte_TypeDef_FD14_IeTRSC_cnt_KnobPos
typedef uint8 FD14_IeTRSC_cnt_KnobPos;

# define Rte_TypeDef_FD14_IeTRSC_cnt_TrlrCalibFailCnt
typedef uint16 FD14_IeTRSC_cnt_TrlrCalibFailCnt;

# define Rte_TypeDef_FD14_IeTRSC_cnt_TrlrCalibFailCntCurr
typedef uint16 FD14_IeTRSC_cnt_TrlrCalibFailCntCurr;

# define Rte_TypeDef_FD14_IeTRSC_cnt_TrlrCalibPassCnt
typedef uint16 FD14_IeTRSC_cnt_TrlrCalibPassCnt;

# define Rte_TypeDef_FD14_IeTRSC_cnt_TrlrCalibPassCntCurr
typedef uint16 FD14_IeTRSC_cnt_TrlrCalibPassCntCurr;

# define Rte_TypeDef_FD14_IeTRSC_deg_FrntWhlAng
typedef float32 FD14_IeTRSC_deg_FrntWhlAng;

# define Rte_TypeDef_FD14_IeTRSC_deg_JackknifeThrAngle
typedef float32 FD14_IeTRSC_deg_JackknifeThrAngle;

# define Rte_TypeDef_FD14_IeTRSC_deg_TADAngle
typedef float32 FD14_IeTRSC_deg_TADAngle;

# define Rte_TypeDef_FD14_IeTRSC_deg_TrlrAngKnob
typedef float32 FD14_IeTRSC_deg_TrlrAngKnob;

# define Rte_TypeDef_FD14_IeTRSC_kph_VehSpeedVSOSig
typedef float32 FD14_IeTRSC_kph_VehSpeedVSOSig;

# define Rte_TypeDef_FD14_IeTRSC_m_TrlrWhlBaseEff
typedef float32 FD14_IeTRSC_m_TrlrWhlBaseEff;

# define Rte_TypeDef_FD14_IeTRSC_pct_TrlrDetConf
typedef float32 FD14_IeTRSC_pct_TrlrDetConf;

# define Rte_TypeDef_FD14_IeTRSC_pct_TrlrRecogConf
typedef float32 FD14_IeTRSC_pct_TrlrRecogConf;

# define Rte_TypeDef_FD14_IeTRSC_pct_TrlrTrackConf
typedef float32 FD14_IeTRSC_pct_TrlrTrackConf;

# define Rte_TypeDef_FD14_IeVBII_nfcd_MinDisToCollisionObj
typedef float32 FD14_IeVBII_nfcd_MinDisToCollisionObj;

# define Rte_TypeDef_FD14_IgnoreVehicleOffSpeed
typedef boolean FD14_IgnoreVehicleOffSpeed;

# define Rte_TypeDef_FD14_IgnoredFeatures_Front_u32
typedef uint32 FD14_IgnoredFeatures_Front_u32;

# define Rte_TypeDef_FD14_IgnoredFeatures_Left_u32
typedef uint32 FD14_IgnoredFeatures_Left_u32;

# define Rte_TypeDef_FD14_IgnoredFeatures_Rear_u32
typedef uint32 FD14_IgnoredFeatures_Rear_u32;

# define Rte_TypeDef_FD14_IgnoredFeatures_Right_u32
typedef uint32 FD14_IgnoredFeatures_Right_u32;

# define Rte_TypeDef_FD14_InvalidFeatures_Front_u32
typedef uint32 FD14_InvalidFeatures_Front_u32;

# define Rte_TypeDef_FD14_InvalidFeatures_Left_u32
typedef uint32 FD14_InvalidFeatures_Left_u32;

# define Rte_TypeDef_FD14_InvalidFeatures_Rear_u32
typedef uint32 FD14_InvalidFeatures_Rear_u32;

# define Rte_TypeDef_FD14_InvalidFeatures_Right_u32
typedef uint32 FD14_InvalidFeatures_Right_u32;

# define Rte_TypeDef_FD14_IsBackSftbtnSel
typedef boolean FD14_IsBackSftbtnSel;

# define Rte_TypeDef_FD14_IsExitSftBtnSel
typedef boolean FD14_IsExitSftBtnSel;

# define Rte_TypeDef_FD14_IsParkSftBtnSel
typedef boolean FD14_IsParkSftBtnSel;

# define Rte_TypeDef_FD14_IsSlotSel
typedef boolean FD14_IsSlotSel;

# define Rte_TypeDef_FD14_ItbmTrailerStatus
typedef uint8 FD14_ItbmTrailerStatus;

# define Rte_TypeDef_FD14_JackknifeAngle
typedef float32 FD14_JackknifeAngle;

# define Rte_TypeDef_FD14_JackknifeThrAngle
typedef float32 FD14_JackknifeThrAngle;

# define Rte_TypeDef_FD14_KnobAngle
typedef float32 FD14_KnobAngle;

# define Rte_TypeDef_FD14_LMD_e_Line_1_Type
typedef uint8 FD14_LMD_e_Line_1_Type;

# define Rte_TypeDef_FD14_LMD_e_Line_2_Type
typedef uint8 FD14_LMD_e_Line_2_Type;

# define Rte_TypeDef_FD14_LMD_e_Line_3_Type
typedef uint8 FD14_LMD_e_Line_3_Type;

# define Rte_TypeDef_FD14_LMD_e_Line_4_Type
typedef uint8 FD14_LMD_e_Line_4_Type;

# define Rte_TypeDef_FD14_LMD_e_Segment_1_ID
typedef uint8 FD14_LMD_e_Segment_1_ID;

# define Rte_TypeDef_FD14_LMD_e_Segment_2_ID
typedef uint8 FD14_LMD_e_Segment_2_ID;

# define Rte_TypeDef_FD14_LMD_e_Segment_3_ID
typedef uint8 FD14_LMD_e_Segment_3_ID;

# define Rte_TypeDef_FD14_LMD_e_Segment_4_ID
typedef uint8 FD14_LMD_e_Segment_4_ID;

# define Rte_TypeDef_FD14_LMD_e_Segment_5_ID
typedef uint8 FD14_LMD_e_Segment_5_ID;

# define Rte_TypeDef_FD14_LMD_e_Segment_6_ID
typedef uint8 FD14_LMD_e_Segment_6_ID;

# define Rte_TypeDef_FD14_LMD_e_Segment_7_ID
typedef uint8 FD14_LMD_e_Segment_7_ID;

# define Rte_TypeDef_FD14_LMD_e_Segment_8_ID
typedef uint8 FD14_LMD_e_Segment_8_ID;

# define Rte_TypeDef_FD14_LMD_m_Line_1_End_Range
typedef float32 FD14_LMD_m_Line_1_End_Range;

# define Rte_TypeDef_FD14_LMD_m_Line_1_Offset
typedef float32 FD14_LMD_m_Line_1_Offset;

# define Rte_TypeDef_FD14_LMD_m_Line_1_Start_Range
typedef float32 FD14_LMD_m_Line_1_Start_Range;

# define Rte_TypeDef_FD14_LMD_m_Line_2_End_Range
typedef float32 FD14_LMD_m_Line_2_End_Range;

# define Rte_TypeDef_FD14_LMD_m_Line_2_Offset
typedef float32 FD14_LMD_m_Line_2_Offset;

# define Rte_TypeDef_FD14_LMD_m_Line_2_Start_Range
typedef float32 FD14_LMD_m_Line_2_Start_Range;

# define Rte_TypeDef_FD14_LMD_m_Line_3_End_Range
typedef float32 FD14_LMD_m_Line_3_End_Range;

# define Rte_TypeDef_FD14_LMD_m_Line_3_Offset
typedef float32 FD14_LMD_m_Line_3_Offset;

# define Rte_TypeDef_FD14_LMD_m_Line_3_Start_Range
typedef float32 FD14_LMD_m_Line_3_Start_Range;

# define Rte_TypeDef_FD14_LMD_m_Line_4_End_Range
typedef float32 FD14_LMD_m_Line_4_End_Range;

# define Rte_TypeDef_FD14_LMD_m_Line_4_Offset
typedef float32 FD14_LMD_m_Line_4_Offset;

# define Rte_TypeDef_FD14_LMD_m_Line_4_Start_Range
typedef float32 FD14_LMD_m_Line_4_Start_Range;

# define Rte_TypeDef_FD14_LMD_m_Segment_1_X1
typedef float32 FD14_LMD_m_Segment_1_X1;

# define Rte_TypeDef_FD14_LMD_m_Segment_1_X2
typedef float32 FD14_LMD_m_Segment_1_X2;

# define Rte_TypeDef_FD14_LMD_m_Segment_1_Y1
typedef float32 FD14_LMD_m_Segment_1_Y1;

# define Rte_TypeDef_FD14_LMD_m_Segment_1_Y2
typedef float32 FD14_LMD_m_Segment_1_Y2;

# define Rte_TypeDef_FD14_LMD_m_Segment_2_X1
typedef float32 FD14_LMD_m_Segment_2_X1;

# define Rte_TypeDef_FD14_LMD_m_Segment_2_X2
typedef float32 FD14_LMD_m_Segment_2_X2;

# define Rte_TypeDef_FD14_LMD_m_Segment_2_Y1
typedef float32 FD14_LMD_m_Segment_2_Y1;

# define Rte_TypeDef_FD14_LMD_m_Segment_2_Y2
typedef float32 FD14_LMD_m_Segment_2_Y2;

# define Rte_TypeDef_FD14_LMD_m_Segment_3_X1
typedef float32 FD14_LMD_m_Segment_3_X1;

# define Rte_TypeDef_FD14_LMD_m_Segment_3_X2
typedef float32 FD14_LMD_m_Segment_3_X2;

# define Rte_TypeDef_FD14_LMD_m_Segment_3_Y1
typedef float32 FD14_LMD_m_Segment_3_Y1;

# define Rte_TypeDef_FD14_LMD_m_Segment_3_Y2
typedef float32 FD14_LMD_m_Segment_3_Y2;

# define Rte_TypeDef_FD14_LMD_m_Segment_4_X1
typedef float32 FD14_LMD_m_Segment_4_X1;

# define Rte_TypeDef_FD14_LMD_m_Segment_4_X2
typedef float32 FD14_LMD_m_Segment_4_X2;

# define Rte_TypeDef_FD14_LMD_m_Segment_4_Y1
typedef float32 FD14_LMD_m_Segment_4_Y1;

# define Rte_TypeDef_FD14_LMD_m_Segment_4_Y2
typedef float32 FD14_LMD_m_Segment_4_Y2;

# define Rte_TypeDef_FD14_LMD_m_Segment_5_X1
typedef float32 FD14_LMD_m_Segment_5_X1;

# define Rte_TypeDef_FD14_LMD_m_Segment_5_X2
typedef float32 FD14_LMD_m_Segment_5_X2;

# define Rte_TypeDef_FD14_LMD_m_Segment_5_Y1
typedef float32 FD14_LMD_m_Segment_5_Y1;

# define Rte_TypeDef_FD14_LMD_m_Segment_5_Y2
typedef float32 FD14_LMD_m_Segment_5_Y2;

# define Rte_TypeDef_FD14_LMD_m_Segment_6_X1
typedef float32 FD14_LMD_m_Segment_6_X1;

# define Rte_TypeDef_FD14_LMD_m_Segment_6_X2
typedef float32 FD14_LMD_m_Segment_6_X2;

# define Rte_TypeDef_FD14_LMD_m_Segment_6_Y1
typedef float32 FD14_LMD_m_Segment_6_Y1;

# define Rte_TypeDef_FD14_LMD_m_Segment_6_Y2
typedef float32 FD14_LMD_m_Segment_6_Y2;

# define Rte_TypeDef_FD14_LMD_m_Segment_7_X1
typedef float32 FD14_LMD_m_Segment_7_X1;

# define Rte_TypeDef_FD14_LMD_m_Segment_7_X2
typedef float32 FD14_LMD_m_Segment_7_X2;

# define Rte_TypeDef_FD14_LMD_m_Segment_7_Y1
typedef float32 FD14_LMD_m_Segment_7_Y1;

# define Rte_TypeDef_FD14_LMD_m_Segment_7_Y2
typedef float32 FD14_LMD_m_Segment_7_Y2;

# define Rte_TypeDef_FD14_LMD_m_Segment_8_X1
typedef float32 FD14_LMD_m_Segment_8_X1;

# define Rte_TypeDef_FD14_LMD_m_Segment_8_X2
typedef float32 FD14_LMD_m_Segment_8_X2;

# define Rte_TypeDef_FD14_LMD_m_Segment_8_Y1
typedef float32 FD14_LMD_m_Segment_8_Y1;

# define Rte_TypeDef_FD14_LMD_m_Segment_8_Y2
typedef float32 FD14_LMD_m_Segment_8_Y2;

# define Rte_TypeDef_FD14_LMD_pct_Line_1_Confidence
typedef float32 FD14_LMD_pct_Line_1_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Line_2_Confidence
typedef float32 FD14_LMD_pct_Line_2_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Line_3_Confidence
typedef float32 FD14_LMD_pct_Line_3_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Line_4_Confidence
typedef float32 FD14_LMD_pct_Line_4_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Segment_1_Confidence
typedef float32 FD14_LMD_pct_Segment_1_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Segment_2_Confidence
typedef float32 FD14_LMD_pct_Segment_2_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Segment_3_Confidence
typedef float32 FD14_LMD_pct_Segment_3_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Segment_4_Confidence
typedef float32 FD14_LMD_pct_Segment_4_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Segment_5_Confidence
typedef float32 FD14_LMD_pct_Segment_5_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Segment_6_Confidence
typedef float32 FD14_LMD_pct_Segment_6_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Segment_7_Confidence
typedef float32 FD14_LMD_pct_Segment_7_Confidence;

# define Rte_TypeDef_FD14_LMD_pct_Segment_8_Confidence
typedef float32 FD14_LMD_pct_Segment_8_Confidence;

# define Rte_TypeDef_FD14_LMD_px_Line_1_Curvature
typedef float32 FD14_LMD_px_Line_1_Curvature;

# define Rte_TypeDef_FD14_LMD_px_Line_2_Curvature
typedef float32 FD14_LMD_px_Line_2_Curvature;

# define Rte_TypeDef_FD14_LMD_px_Line_3_Curvature
typedef float32 FD14_LMD_px_Line_3_Curvature;

# define Rte_TypeDef_FD14_LMD_px_Line_4_Curvature
typedef float32 FD14_LMD_px_Line_4_Curvature;

# define Rte_TypeDef_FD14_LMD_rad_Line_1_Heading
typedef float32 FD14_LMD_rad_Line_1_Heading;

# define Rte_TypeDef_FD14_LMD_rad_Line_2_Heading
typedef float32 FD14_LMD_rad_Line_2_Heading;

# define Rte_TypeDef_FD14_LMD_rad_Line_3_Heading
typedef float32 FD14_LMD_rad_Line_3_Heading;

# define Rte_TypeDef_FD14_LMD_rad_Line_4_Heading
typedef float32 FD14_LMD_rad_Line_4_Heading;

# define Rte_TypeDef_FD14_LanguageSelection_u8
typedef uint8 FD14_LanguageSelection_u8;

# define Rte_TypeDef_FD14_LeftCam_NA_b
typedef boolean FD14_LeftCam_NA_b;

# define Rte_TypeDef_FD14_LeftDoorFrontClose_Icon_b
typedef boolean FD14_LeftDoorFrontClose_Icon_b;

# define Rte_TypeDef_FD14_LeftDoorFrontOpen_Icon_b
typedef boolean FD14_LeftDoorFrontOpen_Icon_b;

# define Rte_TypeDef_FD14_LeftDoorRearClose_Icon_b
typedef boolean FD14_LeftDoorRearClose_Icon_b;

# define Rte_TypeDef_FD14_LeftDoorRearOpen_Icon_b
typedef boolean FD14_LeftDoorRearOpen_Icon_b;

# define Rte_TypeDef_FD14_Line_1_Confidence
typedef uint8 FD14_Line_1_Confidence;

# define Rte_TypeDef_FD14_Line_1_Curvature
typedef uint16 FD14_Line_1_Curvature;

# define Rte_TypeDef_FD14_Line_1_Curvature_Rate
typedef uint16 FD14_Line_1_Curvature_Rate;

# define Rte_TypeDef_FD14_Line_1_End_Range
typedef uint8 FD14_Line_1_End_Range;

# define Rte_TypeDef_FD14_Line_1_Heading
typedef uint16 FD14_Line_1_Heading;

# define Rte_TypeDef_FD14_Line_1_Offset
typedef uint16 FD14_Line_1_Offset;

# define Rte_TypeDef_FD14_Line_1_Start_Range
typedef uint8 FD14_Line_1_Start_Range;

# define Rte_TypeDef_FD14_Line_2_Confidence
typedef uint8 FD14_Line_2_Confidence;

# define Rte_TypeDef_FD14_Line_2_Curvature
typedef uint16 FD14_Line_2_Curvature;

# define Rte_TypeDef_FD14_Line_2_Curvature_Rate
typedef uint16 FD14_Line_2_Curvature_Rate;

# define Rte_TypeDef_FD14_Line_2_End_Range
typedef uint8 FD14_Line_2_End_Range;

# define Rte_TypeDef_FD14_Line_2_Heading
typedef uint16 FD14_Line_2_Heading;

# define Rte_TypeDef_FD14_Line_2_Offset
typedef uint16 FD14_Line_2_Offset;

# define Rte_TypeDef_FD14_Line_2_Start_Range
typedef uint8 FD14_Line_2_Start_Range;

# define Rte_TypeDef_FD14_Line_3_Confidence
typedef uint8 FD14_Line_3_Confidence;

# define Rte_TypeDef_FD14_Line_3_Curvature
typedef uint16 FD14_Line_3_Curvature;

# define Rte_TypeDef_FD14_Line_3_Curvature_Rate
typedef uint16 FD14_Line_3_Curvature_Rate;

# define Rte_TypeDef_FD14_Line_3_End_Range
typedef uint8 FD14_Line_3_End_Range;

# define Rte_TypeDef_FD14_Line_3_Heading
typedef uint16 FD14_Line_3_Heading;

# define Rte_TypeDef_FD14_Line_3_Offset
typedef uint16 FD14_Line_3_Offset;

# define Rte_TypeDef_FD14_Line_3_Start_Range
typedef uint8 FD14_Line_3_Start_Range;

# define Rte_TypeDef_FD14_Line_4_Confidence
typedef uint8 FD14_Line_4_Confidence;

# define Rte_TypeDef_FD14_Line_4_Curvature
typedef uint16 FD14_Line_4_Curvature;

# define Rte_TypeDef_FD14_Line_4_Curvature_Rate
typedef uint16 FD14_Line_4_Curvature_Rate;

# define Rte_TypeDef_FD14_Line_4_End_Range
typedef uint8 FD14_Line_4_End_Range;

# define Rte_TypeDef_FD14_Line_4_Heading
typedef uint16 FD14_Line_4_Heading;

# define Rte_TypeDef_FD14_Line_4_Offset
typedef uint16 FD14_Line_4_Offset;

# define Rte_TypeDef_FD14_Line_4_Start_Range
typedef uint8 FD14_Line_4_Start_Range;

# define Rte_TypeDef_FD14_MAGNIFIER_BTN_PRESSED_b
typedef boolean FD14_MAGNIFIER_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_0_0
typedef float32 FD14_MOT_ClosestPntDist_0_0;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_0_1
typedef float32 FD14_MOT_ClosestPntDist_0_1;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_0_2
typedef float32 FD14_MOT_ClosestPntDist_0_2;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_0_3
typedef float32 FD14_MOT_ClosestPntDist_0_3;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_0_4
typedef float32 FD14_MOT_ClosestPntDist_0_4;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_0_5
typedef float32 FD14_MOT_ClosestPntDist_0_5;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_0_6
typedef float32 FD14_MOT_ClosestPntDist_0_6;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_0_7
typedef float32 FD14_MOT_ClosestPntDist_0_7;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_0_8
typedef float32 FD14_MOT_ClosestPntDist_0_8;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_0_9
typedef float32 FD14_MOT_ClosestPntDist_0_9;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_1_0
typedef float32 FD14_MOT_ClosestPntDist_1_0;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_1_1
typedef float32 FD14_MOT_ClosestPntDist_1_1;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_1_2
typedef float32 FD14_MOT_ClosestPntDist_1_2;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_1_3
typedef float32 FD14_MOT_ClosestPntDist_1_3;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_1_4
typedef float32 FD14_MOT_ClosestPntDist_1_4;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_1_5
typedef float32 FD14_MOT_ClosestPntDist_1_5;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_1_6
typedef float32 FD14_MOT_ClosestPntDist_1_6;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_1_7
typedef float32 FD14_MOT_ClosestPntDist_1_7;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_1_8
typedef float32 FD14_MOT_ClosestPntDist_1_8;

# define Rte_TypeDef_FD14_MOT_ClosestPntDist_1_9
typedef float32 FD14_MOT_ClosestPntDist_1_9;

# define Rte_TypeDef_FD14_MOT_ObjValid_0
typedef boolean FD14_MOT_ObjValid_0;

# define Rte_TypeDef_FD14_MOT_ObjValid_1
typedef boolean FD14_MOT_ObjValid_1;

# define Rte_TypeDef_FD14_MOT_ObjValid_2
typedef boolean FD14_MOT_ObjValid_2;

# define Rte_TypeDef_FD14_MOT_ObjValid_3
typedef boolean FD14_MOT_ObjValid_3;

# define Rte_TypeDef_FD14_MOT_ObjValid_4
typedef boolean FD14_MOT_ObjValid_4;

# define Rte_TypeDef_FD14_MOT_ObjValid_5
typedef boolean FD14_MOT_ObjValid_5;

# define Rte_TypeDef_FD14_MOT_ObjValid_6
typedef boolean FD14_MOT_ObjValid_6;

# define Rte_TypeDef_FD14_MOT_ObjValid_7
typedef boolean FD14_MOT_ObjValid_7;

# define Rte_TypeDef_FD14_MOT_ObjValid_8
typedef boolean FD14_MOT_ObjValid_8;

# define Rte_TypeDef_FD14_MOT_ObjValid_9
typedef boolean FD14_MOT_ObjValid_9;

# define Rte_TypeDef_FD14_MOT_ObjVelX_0
typedef float32 FD14_MOT_ObjVelX_0;

# define Rte_TypeDef_FD14_MOT_ObjVelX_1
typedef float32 FD14_MOT_ObjVelX_1;

# define Rte_TypeDef_FD14_MOT_ObjVelX_2
typedef float32 FD14_MOT_ObjVelX_2;

# define Rte_TypeDef_FD14_MOT_ObjVelX_3
typedef float32 FD14_MOT_ObjVelX_3;

# define Rte_TypeDef_FD14_MOT_ObjVelX_4
typedef float32 FD14_MOT_ObjVelX_4;

# define Rte_TypeDef_FD14_MOT_ObjVelX_5
typedef float32 FD14_MOT_ObjVelX_5;

# define Rte_TypeDef_FD14_MOT_ObjVelX_6
typedef float32 FD14_MOT_ObjVelX_6;

# define Rte_TypeDef_FD14_MOT_ObjVelX_7
typedef float32 FD14_MOT_ObjVelX_7;

# define Rte_TypeDef_FD14_MOT_ObjVelX_8
typedef float32 FD14_MOT_ObjVelX_8;

# define Rte_TypeDef_FD14_MOT_ObjVelX_9
typedef float32 FD14_MOT_ObjVelX_9;

# define Rte_TypeDef_FD14_MOT_ObjVelY_0
typedef float32 FD14_MOT_ObjVelY_0;

# define Rte_TypeDef_FD14_MOT_ObjVelY_1
typedef float32 FD14_MOT_ObjVelY_1;

# define Rte_TypeDef_FD14_MOT_ObjVelY_2
typedef float32 FD14_MOT_ObjVelY_2;

# define Rte_TypeDef_FD14_MOT_ObjVelY_3
typedef float32 FD14_MOT_ObjVelY_3;

# define Rte_TypeDef_FD14_MOT_ObjVelY_4
typedef float32 FD14_MOT_ObjVelY_4;

# define Rte_TypeDef_FD14_MOT_ObjVelY_5
typedef float32 FD14_MOT_ObjVelY_5;

# define Rte_TypeDef_FD14_MOT_ObjVelY_6
typedef float32 FD14_MOT_ObjVelY_6;

# define Rte_TypeDef_FD14_MOT_ObjVelY_7
typedef float32 FD14_MOT_ObjVelY_7;

# define Rte_TypeDef_FD14_MOT_ObjVelY_8
typedef float32 FD14_MOT_ObjVelY_8;

# define Rte_TypeDef_FD14_MOT_ObjVelY_9
typedef float32 FD14_MOT_ObjVelY_9;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_0_0
typedef float32 FD14_MOT_ObjectDimensions_0_0;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_0_1
typedef float32 FD14_MOT_ObjectDimensions_0_1;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_0_2
typedef float32 FD14_MOT_ObjectDimensions_0_2;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_0_3
typedef float32 FD14_MOT_ObjectDimensions_0_3;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_0_4
typedef float32 FD14_MOT_ObjectDimensions_0_4;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_0_5
typedef float32 FD14_MOT_ObjectDimensions_0_5;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_0_6
typedef float32 FD14_MOT_ObjectDimensions_0_6;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_0_7
typedef float32 FD14_MOT_ObjectDimensions_0_7;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_0_8
typedef float32 FD14_MOT_ObjectDimensions_0_8;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_0_9
typedef float32 FD14_MOT_ObjectDimensions_0_9;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_1_0
typedef float32 FD14_MOT_ObjectDimensions_1_0;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_1_1
typedef float32 FD14_MOT_ObjectDimensions_1_1;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_1_2
typedef float32 FD14_MOT_ObjectDimensions_1_2;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_1_3
typedef float32 FD14_MOT_ObjectDimensions_1_3;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_1_4
typedef float32 FD14_MOT_ObjectDimensions_1_4;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_1_5
typedef float32 FD14_MOT_ObjectDimensions_1_5;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_1_6
typedef float32 FD14_MOT_ObjectDimensions_1_6;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_1_7
typedef float32 FD14_MOT_ObjectDimensions_1_7;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_1_8
typedef float32 FD14_MOT_ObjectDimensions_1_8;

# define Rte_TypeDef_FD14_MOT_ObjectDimensions_1_9
typedef float32 FD14_MOT_ObjectDimensions_1_9;

# define Rte_TypeDef_FD14_M_CONFIRM_BTN_PRESSED_b
typedef boolean FD14_M_CONFIRM_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_M_CPLR_POS_X_u
typedef uint8 FD14_M_CPLR_POS_X_u;

# define Rte_TypeDef_FD14_M_CPLR_POS_Y_u
typedef uint8 FD14_M_CPLR_POS_Y_u;

# define Rte_TypeDef_FD14_M_Cplr_Htch_Distance
typedef uint8 FD14_M_Cplr_Htch_Distance;

# define Rte_TypeDef_FD14_M_Current_THA_State_On_Screen
typedef uint8 FD14_M_Current_THA_State_On_Screen;

# define Rte_TypeDef_FD14_M_Current_THA_State_On_Zync
typedef uint8 FD14_M_Current_THA_State_On_Zync;

# define Rte_TypeDef_FD14_M_Maneuver_Initial_Run
typedef uint8 FD14_M_Maneuver_Initial_Run;

# define Rte_TypeDef_FD14_M_Progress_Bar_Distance
typedef uint8 FD14_M_Progress_Bar_Distance;

# define Rte_TypeDef_FD14_M_Progress_Bar_Percentage
typedef uint8 FD14_M_Progress_Bar_Percentage;

# define Rte_TypeDef_FD14_M_Requested_THA_State
typedef uint8 FD14_M_Requested_THA_State;

# define Rte_TypeDef_FD14_M_START_BTN_PRESSED_b
typedef boolean FD14_M_START_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_M_THA_SFT_BTN_PRESSED_b
typedef boolean FD14_M_THA_SFT_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_M_VIEW_SCRN_TCH_STS_b
typedef boolean FD14_M_VIEW_SCRN_TCH_STS_b;

# define Rte_TypeDef_FD14_M_VIEW_ZOOM_STS_b
typedef boolean FD14_M_VIEW_ZOOM_STS_b;

# define Rte_TypeDef_FD14_MaAP_m_ParkSpot1FrntStreetX
typedef float32 FD14_MaAP_m_ParkSpot1FrntStreetX;

# define Rte_TypeDef_FD14_MaAP_m_ParkSpot1FrntStreetY
typedef float32 FD14_MaAP_m_ParkSpot1FrntStreetY;

# define Rte_TypeDef_FD14_MaAP_m_ParkSpot2FrntBorderX
typedef float32 FD14_MaAP_m_ParkSpot2FrntBorderX;

# define Rte_TypeDef_FD14_MaAP_m_ParkSpot2FrntBorderY
typedef float32 FD14_MaAP_m_ParkSpot2FrntBorderY;

# define Rte_TypeDef_FD14_MaAP_m_ParkSpot3RearBorderX
typedef float32 FD14_MaAP_m_ParkSpot3RearBorderX;

# define Rte_TypeDef_FD14_MaAP_m_ParkSpot3RearBorderY
typedef float32 FD14_MaAP_m_ParkSpot3RearBorderY;

# define Rte_TypeDef_FD14_MaAP_m_ParkSpot4RearStreetX
typedef float32 FD14_MaAP_m_ParkSpot4RearStreetX;

# define Rte_TypeDef_FD14_MaAP_m_ParkSpot4RearStreetY
typedef float32 FD14_MaAP_m_ParkSpot4RearStreetY;

# define Rte_TypeDef_FD14_MaxTadAngle
typedef float32 FD14_MaxTadAngle;

# define Rte_TypeDef_FD14_MeAP_a_BrkCmd
typedef float32 FD14_MeAP_a_BrkCmd;

# define Rte_TypeDef_FD14_MeAP_a_ThrtlCmd
typedef float32 FD14_MeAP_a_ThrtlCmd;

# define Rte_TypeDef_FD14_MeAP_b_APInitSts
typedef boolean FD14_MeAP_b_APInitSts;

# define Rte_TypeDef_FD14_MeAP_b_BSMHandshakeActv
typedef boolean FD14_MeAP_b_BSMHandshakeActv;

# define Rte_TypeDef_FD14_MeAP_b_BSMInterfaceTimeout
typedef boolean FD14_MeAP_b_BSMInterfaceTimeout;

# define Rte_TypeDef_FD14_MeAP_b_CamHandshakeTimeout
typedef boolean FD14_MeAP_b_CamHandshakeTimeout;

# define Rte_TypeDef_FD14_MeAP_b_DriverOverride
typedef boolean FD14_MeAP_b_DriverOverride;

# define Rte_TypeDef_FD14_MeAP_b_EPSInterfaceTimeout
typedef boolean FD14_MeAP_b_EPSInterfaceTimeout;

# define Rte_TypeDef_FD14_MeAP_b_FPADisable
typedef boolean FD14_MeAP_b_FPADisable;

# define Rte_TypeDef_FD14_MeAP_b_FPAStatus
typedef boolean FD14_MeAP_b_FPAStatus;

# define Rte_TypeDef_FD14_MeAP_b_FPAVolDefMed
typedef boolean FD14_MeAP_b_FPAVolDefMed;

# define Rte_TypeDef_FD14_MeAP_b_FeatureEnbl
typedef boolean FD14_MeAP_b_FeatureEnbl;

# define Rte_TypeDef_FD14_MeAP_b_GearShiftWaitTimeout
typedef boolean FD14_MeAP_b_GearShiftWaitTimeout;

# define Rte_TypeDef_FD14_MeAP_b_ManeuverAbort
typedef boolean FD14_MeAP_b_ManeuverAbort;

# define Rte_TypeDef_FD14_MeAP_b_ManeuverSuccess
typedef boolean FD14_MeAP_b_ManeuverSuccess;

# define Rte_TypeDef_FD14_MeAP_b_ObjInPathTimeout
typedef boolean FD14_MeAP_b_ObjInPathTimeout;

# define Rte_TypeDef_FD14_MeAP_b_PARBActv4LOW
typedef boolean FD14_MeAP_b_PARBActv4LOW;

# define Rte_TypeDef_FD14_MeAP_b_PARBActvTrlr
typedef boolean FD14_MeAP_b_PARBActvTrlr;

# define Rte_TypeDef_FD14_MeAP_b_PARBDisable
typedef boolean FD14_MeAP_b_PARBDisable;

# define Rte_TypeDef_FD14_MeAP_b_PAVolDefMed
typedef boolean FD14_MeAP_b_PAVolDefMed;

# define Rte_TypeDef_FD14_MeAP_b_PPPAActv4LOW
typedef boolean FD14_MeAP_b_PPPAActv4LOW;

# define Rte_TypeDef_FD14_MeAP_b_PPPAActvTrlr
typedef boolean FD14_MeAP_b_PPPAActvTrlr;

# define Rte_TypeDef_FD14_MeAP_b_PPPADefEng
typedef boolean FD14_MeAP_b_PPPADefEng;

# define Rte_TypeDef_FD14_MeAP_b_PPPADisable
typedef boolean FD14_MeAP_b_PPPADisable;

# define Rte_TypeDef_FD14_MeAP_b_PausedPressBtnTimeout
typedef boolean FD14_MeAP_b_PausedPressBtnTimeout;

# define Rte_TypeDef_FD14_MeAP_b_PosMet
typedef boolean FD14_MeAP_b_PosMet;

# define Rte_TypeDef_FD14_MeAP_b_RPAActvTrlr
typedef boolean FD14_MeAP_b_RPAActvTrlr;

# define Rte_TypeDef_FD14_MeAP_b_RPADisable
typedef boolean FD14_MeAP_b_RPADisable;

# define Rte_TypeDef_FD14_MeAP_b_RPAStatus
typedef boolean FD14_MeAP_b_RPAStatus;

# define Rte_TypeDef_FD14_MeAP_b_RPAVolDefMed
typedef boolean FD14_MeAP_b_RPAVolDefMed;

# define Rte_TypeDef_FD14_MeAP_b_RPAwithBrkStatus
typedef boolean FD14_MeAP_b_RPAwithBrkStatus;

# define Rte_TypeDef_FD14_MeAP_b_SeekSpdExceedTimeout
typedef boolean FD14_MeAP_b_SeekSpdExceedTimeout;

# define Rte_TypeDef_FD14_MeAP_b_StandStill
typedef boolean FD14_MeAP_b_StandStill;

# define Rte_TypeDef_FD14_MeAP_b_SteerActionReq
typedef boolean FD14_MeAP_b_SteerActionReq;

# define Rte_TypeDef_FD14_MeAP_b_VCOpPaused
typedef boolean FD14_MeAP_b_VCOpPaused;

# define Rte_TypeDef_FD14_MeAP_b_VehCndSts
typedef boolean FD14_MeAP_b_VehCndSts;

# define Rte_TypeDef_FD14_MeAP_cm_FrntCenterMinXDist
typedef sint16 FD14_MeAP_cm_FrntCenterMinXDist;

# define Rte_TypeDef_FD14_MeAP_cm_FrntLeftMinXDist
typedef sint16 FD14_MeAP_cm_FrntLeftMinXDist;

# define Rte_TypeDef_FD14_MeAP_cm_FrntRightMinXDist
typedef sint16 FD14_MeAP_cm_FrntRightMinXDist;

# define Rte_TypeDef_FD14_MeAP_cm_RearCenterMinXDist
typedef sint16 FD14_MeAP_cm_RearCenterMinXDist;

# define Rte_TypeDef_FD14_MeAP_cm_RearLeftMinXDist
typedef sint16 FD14_MeAP_cm_RearLeftMinXDist;

# define Rte_TypeDef_FD14_MeAP_cm_RearRightMinXDist
typedef sint16 FD14_MeAP_cm_RearRightMinXDist;

# define Rte_TypeDef_FD14_MeAP_cnt_StateDebugVar
typedef uint16 FD14_MeAP_cnt_StateDebugVar;

# define Rte_TypeDef_FD14_MeAP_cnt_TransDebugVar
typedef uint16 FD14_MeAP_cnt_TransDebugVar;

# define Rte_TypeDef_FD14_MeAP_cnt_TransDebugVar_Copy_1
typedef sint16 FD14_MeAP_cnt_TransDebugVar_Copy_1;

# define Rte_TypeDef_FD14_MeAP_deg_StrCmd
typedef float32 FD14_MeAP_deg_StrCmd;

# define Rte_TypeDef_FD14_MeAP_e_PP_state
typedef sint8 FD14_MeAP_e_PP_state;

# define Rte_TypeDef_FD14_MeAP_e_Park_state
typedef float32 FD14_MeAP_e_Park_state;

# define Rte_TypeDef_FD14_MePRX_b_AuxTrlrCam
typedef boolean FD14_MePRX_b_AuxTrlrCam;

# define Rte_TypeDef_FD14_MePRX_b_CANNode95
typedef boolean FD14_MePRX_b_CANNode95;

# define Rte_TypeDef_FD14_MePRX_b_CanNode27
typedef boolean FD14_MePRX_b_CanNode27;

# define Rte_TypeDef_FD14_MePRX_b_FrwFacingCam
typedef boolean FD14_MePRX_b_FrwFacingCam;

# define Rte_TypeDef_FD14_MePRX_b_SurroundViewCamera
typedef boolean FD14_MePRX_b_SurroundViewCamera;

# define Rte_TypeDef_FD14_MePRX_b_TRGPresence
typedef boolean FD14_MePRX_b_TRGPresence;

# define Rte_TypeDef_FD14_MePRX_b_TRSCPresence
typedef boolean FD14_MePRX_b_TRSCPresence;

# define Rte_TypeDef_FD14_MePRX_e_AutonomyLvl
typedef uint8 FD14_MePRX_e_AutonomyLvl;

# define Rte_TypeDef_FD14_MePRX_e_MirrorType
typedef uint8 FD14_MePRX_e_MirrorType;

# define Rte_TypeDef_FD14_MePRX_e_PAMTunSet
typedef uint8 FD14_MePRX_e_PAMTunSet;

# define Rte_TypeDef_FD14_MePRX_e_RadDispType
typedef uint8 FD14_MePRX_e_RadDispType;

# define Rte_TypeDef_FD14_MePRX_e_SteerRatRackPinionType
typedef uint8 FD14_MePRX_e_SteerRatRackPinionType;

# define Rte_TypeDef_FD14_MePRX_e_VariantID
typedef uint8 FD14_MePRX_e_VariantID;

# define Rte_TypeDef_FD14_MePRX_e_VehLineCfg
typedef uint8 FD14_MePRX_e_VehLineCfg;

# define Rte_TypeDef_FD14_MePRX_e_Wheelbase
typedef uint8 FD14_MePRX_e_Wheelbase;

# define Rte_TypeDef_FD14_MeSVS_b_MoreCamReqSts
typedef boolean FD14_MeSVS_b_MoreCamReqSts;

# define Rte_TypeDef_FD14_MeTHA_b_EnblRearParkAsstTrg
typedef boolean FD14_MeTHA_b_EnblRearParkAsstTrg;

# define Rte_TypeDef_FD14_MeTHA_b_THAAbortStatus
typedef boolean FD14_MeTHA_b_THAAbortStatus;

# define Rte_TypeDef_FD14_MeTHA_b_TrlrCplrStatus
typedef boolean FD14_MeTHA_b_TrlrCplrStatus;

# define Rte_TypeDef_FD14_MeTHA_b_UsrCplrSelCnfm
typedef boolean FD14_MeTHA_b_UsrCplrSelCnfm;

# define Rte_TypeDef_FD14_MeTHA_b_UsrHitchCnfm
typedef boolean FD14_MeTHA_b_UsrHitchCnfm;

# define Rte_TypeDef_FD14_MeTHA_deg_CplrAng
typedef float32 FD14_MeTHA_deg_CplrAng;

# define Rte_TypeDef_FD14_MeTHA_deg_RoadWhlAng
typedef float32 FD14_MeTHA_deg_RoadWhlAng;

# define Rte_TypeDef_FD14_MeTHA_e_CplrDetctStatus
typedef uint8 FD14_MeTHA_e_CplrDetctStatus;

# define Rte_TypeDef_FD14_MeTHA_e_HitchDetctStatus
typedef uint8 FD14_MeTHA_e_HitchDetctStatus;

# define Rte_TypeDef_FD14_MeTHA_e_RearBrkSupprInfo
typedef uint8 FD14_MeTHA_e_RearBrkSupprInfo;

# define Rte_TypeDef_FD14_MeTHA_e_ScreenRequest
typedef uint8 FD14_MeTHA_e_ScreenRequest;

# define Rte_TypeDef_FD14_MeTHA_e_THAStateInfo
typedef uint8 FD14_MeTHA_e_THAStateInfo;

# define Rte_TypeDef_FD14_MeTHA_pct_CplrDetConf
typedef uint8 FD14_MeTHA_pct_CplrDetConf;

# define Rte_TypeDef_FD14_MeTHA_pct_CplrTrckConf
typedef uint8 FD14_MeTHA_pct_CplrTrckConf;

# define Rte_TypeDef_FD14_MeTHA_px_CplrPntX
typedef sint32 FD14_MeTHA_px_CplrPntX;

# define Rte_TypeDef_FD14_MeTHA_px_CplrPntY
typedef sint32 FD14_MeTHA_px_CplrPntY;

# define Rte_TypeDef_FD14_MeTHA_px_HitchCplrPixDiffLat
typedef sint32 FD14_MeTHA_px_HitchCplrPixDiffLat;

# define Rte_TypeDef_FD14_MeTHA_px_HitchCplrPixDiffLong
typedef sint32 FD14_MeTHA_px_HitchCplrPixDiffLong;

# define Rte_TypeDef_FD14_MeTHA_px_HitchPntX
typedef sint32 FD14_MeTHA_px_HitchPntX;

# define Rte_TypeDef_FD14_MeTHA_px_HitchPntY
typedef sint32 FD14_MeTHA_px_HitchPntY;

# define Rte_TypeDef_FD14_MeTRSC_M_SteeringTorqInfo
typedef float32 FD14_MeTRSC_M_SteeringTorqInfo;

# define Rte_TypeDef_FD14_MeTRSC_b_MoreCamSoftButtEnbl
typedef boolean FD14_MeTRSC_b_MoreCamSoftButtEnbl;

# define Rte_TypeDef_FD14_MeTRSC_b_OBTLRecalibrate
typedef boolean FD14_MeTRSC_b_OBTLRecalibrate;

# define Rte_TypeDef_FD14_MeTRSC_b_OTBLReset
typedef uint8 FD14_MeTRSC_b_OTBLReset;

# define Rte_TypeDef_FD14_MeTRSC_b_TBLComputationDone
typedef uint8 FD14_MeTRSC_b_TBLComputationDone;

# define Rte_TypeDef_FD14_MeTRSC_b_TRSCSwitchPressed
typedef boolean FD14_MeTRSC_b_TRSCSwitchPressed;

# define Rte_TypeDef_FD14_MeTRSC_b_TrlrCalibDelayInfo
typedef boolean FD14_MeTRSC_b_TrlrCalibDelayInfo;

# define Rte_TypeDef_FD14_MeTRSC_b_TrlrCalibPopInfo
typedef boolean FD14_MeTRSC_b_TrlrCalibPopInfo;

# define Rte_TypeDef_FD14_MeTRSC_b_TrlrRevSteeringStsInfo
typedef boolean FD14_MeTRSC_b_TrlrRevSteeringStsInfo;

# define Rte_TypeDef_FD14_MeTRSC_cnt_TRSCAliveCounter
typedef uint16 FD14_MeTRSC_cnt_TRSCAliveCounter;

# define Rte_TypeDef_FD14_MeTRSC_cnt_TrlrCalibFailCntInfo
typedef uint32 FD14_MeTRSC_cnt_TrlrCalibFailCntInfo;

# define Rte_TypeDef_FD14_MeTRSC_deg_DetJackKnifeAngle
typedef float32 FD14_MeTRSC_deg_DetJackKnifeAngle;

# define Rte_TypeDef_FD14_MeTRSC_deg_DetJackknifeThrAngle
typedef float32 FD14_MeTRSC_deg_DetJackknifeThrAngle;

# define Rte_TypeDef_FD14_MeTRSC_deg_JackKnifeAngle
typedef float32 FD14_MeTRSC_deg_JackKnifeAngle;

# define Rte_TypeDef_FD14_MeTRSC_deg_JackknifeThrAngle
typedef float32 FD14_MeTRSC_deg_JackknifeThrAngle;

# define Rte_TypeDef_FD14_MeTRSC_deg_KnobAngle
typedef float32 FD14_MeTRSC_deg_KnobAngle;

# define Rte_TypeDef_FD14_MeTRSC_deg_MaxAllowedTADAngle
typedef float32 FD14_MeTRSC_deg_MaxAllowedTADAngle;

# define Rte_TypeDef_FD14_MeTRSC_deg_StrCMD
typedef sint32 FD14_MeTRSC_deg_StrCMD;

# define Rte_TypeDef_FD14_MeTRSC_deg_TADAngle
typedef float32 FD14_MeTRSC_deg_TADAngle;

# define Rte_TypeDef_FD14_MeTRSC_deg_TADAngleRate
typedef float32 FD14_MeTRSC_deg_TADAngleRate;

# define Rte_TypeDef_FD14_MeTRSC_deg_TADAngleSMVC
typedef float32 FD14_MeTRSC_deg_TADAngleSMVC;

# define Rte_TypeDef_FD14_MeTRSC_e_TrlrCalInfoSMVC
typedef uint8 FD14_MeTRSC_e_TrlrCalInfoSMVC;

# define Rte_TypeDef_FD14_MeTRSC_m_DetTrailerBeamLen
typedef float32 FD14_MeTRSC_m_DetTrailerBeamLen;

# define Rte_TypeDef_FD14_MeTRSC_m_HitchLength
typedef float32 FD14_MeTRSC_m_HitchLength;

# define Rte_TypeDef_FD14_MeTRSC_m_TrailerBeamLen
typedef float32 FD14_MeTRSC_m_TrailerBeamLen;

# define Rte_TypeDef_FD14_MeTRSC_s_TRSCPeriodicity
typedef uint16 FD14_MeTRSC_s_TRSCPeriodicity;

# define Rte_TypeDef_FD14_MeTRSC_s_TRSCTimeTaken
typedef uint16 FD14_MeTRSC_s_TRSCTimeTaken;

# define Rte_TypeDef_FD14_MessageCounter_ADAS_FD_INFO
typedef uint8 FD14_MessageCounter_ADAS_FD_INFO;

# define Rte_TypeDef_FD14_MessageCounter_BRAKE1
typedef uint8 FD14_MessageCounter_BRAKE1;

# define Rte_TypeDef_FD14_MessageCounter_BRAKE2
typedef uint8 FD14_MessageCounter_BRAKE2;

# define Rte_TypeDef_FD14_MessageCounter_BRAKE3
typedef uint8 FD14_MessageCounter_BRAKE3;

# define Rte_TypeDef_FD14_MessageCounter_BRAKE4
typedef uint8 FD14_MessageCounter_BRAKE4;

# define Rte_TypeDef_FD14_MessageCounter_BRAKE5
typedef uint8 FD14_MessageCounter_BRAKE5;

# define Rte_TypeDef_FD14_MessageCounter_BRAKE7
typedef uint8 FD14_MessageCounter_BRAKE7;

# define Rte_TypeDef_FD14_MessageCounter_CVPAM_FD_Control
typedef uint8 FD14_MessageCounter_CVPAM_FD_Control;

# define Rte_TypeDef_FD14_MessageCounter_CVPAM_FD_Data
typedef uint8 FD14_MessageCounter_CVPAM_FD_Data;

# define Rte_TypeDef_FD14_MessageCounter_CVPAM_FD_Data2
typedef uint8 FD14_MessageCounter_CVPAM_FD_Data2;

# define Rte_TypeDef_FD14_MessageCounter_ENGINE2
typedef uint8 FD14_MessageCounter_ENGINE2;

# define Rte_TypeDef_FD14_MessageCounter_ENGINE7
typedef uint8 FD14_MessageCounter_ENGINE7;

# define Rte_TypeDef_FD14_MessageCounter_EPS1
typedef uint8 FD14_MessageCounter_EPS1;

# define Rte_TypeDef_FD14_MessageCounter_EPS2
typedef uint8 FD14_MessageCounter_EPS2;

# define Rte_TypeDef_FD14_MinDistance_TimeStamp
typedef uint32 FD14_MinDistance_TimeStamp;

# define Rte_TypeDef_FD14_MoreCamsButton1NoSelect_b
typedef boolean FD14_MoreCamsButton1NoSelect_b;

# define Rte_TypeDef_FD14_MoreCamsButton1Select_b
typedef boolean FD14_MoreCamsButton1Select_b;

# define Rte_TypeDef_FD14_MoreCamsButton2NoSelect_b
typedef boolean FD14_MoreCamsButton2NoSelect_b;

# define Rte_TypeDef_FD14_MoreCamsButton2Select_b
typedef boolean FD14_MoreCamsButton2Select_b;

# define Rte_TypeDef_FD14_MoreCamsIconFullScreenNoSelect_b
typedef boolean FD14_MoreCamsIconFullScreenNoSelect_b;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_0_0
typedef float32 FD14_NFCD_DistanceToClosestPoint_0_0;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_0_1
typedef float32 FD14_NFCD_DistanceToClosestPoint_0_1;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_0_2
typedef float32 FD14_NFCD_DistanceToClosestPoint_0_2;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_0_3
typedef float32 FD14_NFCD_DistanceToClosestPoint_0_3;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_0_4
typedef float32 FD14_NFCD_DistanceToClosestPoint_0_4;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_0_5
typedef float32 FD14_NFCD_DistanceToClosestPoint_0_5;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_0_6
typedef float32 FD14_NFCD_DistanceToClosestPoint_0_6;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_0_7
typedef float32 FD14_NFCD_DistanceToClosestPoint_0_7;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_0_8
typedef float32 FD14_NFCD_DistanceToClosestPoint_0_8;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_0_9
typedef float32 FD14_NFCD_DistanceToClosestPoint_0_9;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_1_0
typedef float32 FD14_NFCD_DistanceToClosestPoint_1_0;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_1_1
typedef float32 FD14_NFCD_DistanceToClosestPoint_1_1;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_1_2
typedef float32 FD14_NFCD_DistanceToClosestPoint_1_2;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_1_3
typedef float32 FD14_NFCD_DistanceToClosestPoint_1_3;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_1_4
typedef float32 FD14_NFCD_DistanceToClosestPoint_1_4;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_1_5
typedef float32 FD14_NFCD_DistanceToClosestPoint_1_5;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_1_6
typedef float32 FD14_NFCD_DistanceToClosestPoint_1_6;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_1_7
typedef float32 FD14_NFCD_DistanceToClosestPoint_1_7;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_1_8
typedef float32 FD14_NFCD_DistanceToClosestPoint_1_8;

# define Rte_TypeDef_FD14_NFCD_DistanceToClosestPoint_1_9
typedef float32 FD14_NFCD_DistanceToClosestPoint_1_9;

# define Rte_TypeDef_FD14_NFCD_ObjValid_0
typedef boolean FD14_NFCD_ObjValid_0;

# define Rte_TypeDef_FD14_NFCD_ObjValid_1
typedef boolean FD14_NFCD_ObjValid_1;

# define Rte_TypeDef_FD14_NFCD_ObjValid_2
typedef boolean FD14_NFCD_ObjValid_2;

# define Rte_TypeDef_FD14_NFCD_ObjValid_3
typedef boolean FD14_NFCD_ObjValid_3;

# define Rte_TypeDef_FD14_NFCD_ObjValid_4
typedef boolean FD14_NFCD_ObjValid_4;

# define Rte_TypeDef_FD14_NFCD_ObjValid_5
typedef boolean FD14_NFCD_ObjValid_5;

# define Rte_TypeDef_FD14_NFCD_ObjValid_6
typedef boolean FD14_NFCD_ObjValid_6;

# define Rte_TypeDef_FD14_NFCD_ObjValid_7
typedef boolean FD14_NFCD_ObjValid_7;

# define Rte_TypeDef_FD14_NFCD_ObjValid_8
typedef boolean FD14_NFCD_ObjValid_8;

# define Rte_TypeDef_FD14_NFCD_ObjValid_9
typedef boolean FD14_NFCD_ObjValid_9;

# define Rte_TypeDef_FD14_OBTLRecalibrate
typedef boolean FD14_OBTLRecalibrate;

# define Rte_TypeDef_FD14_OFFRD_ABSNT_AUXCAM_BTN_PRESSED_b
typedef boolean FD14_OFFRD_ABSNT_AUXCAM_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_OFFRD_PRSNT_AUXCAM_BTN_PRESSED_b
typedef boolean FD14_OFFRD_PRSNT_AUXCAM_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_OFFROAD_ABSNT_MC_BTN_PRESSED_b
typedef boolean FD14_OFFROAD_ABSNT_MC_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_OFFROAD_PRSNT_MC_BTN_PRESSED_b
typedef boolean FD14_OFFROAD_PRSNT_MC_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_PA_Front_Sensor_Det_Health
typedef uint8 FD14_PA_Front_Sensor_Det_Health;

# define Rte_TypeDef_FD14_PA_Lane_Dection_Health
typedef uint8 FD14_PA_Lane_Dection_Health;

# define Rte_TypeDef_FD14_PA_Left_Sensor_Det_Health
typedef uint8 FD14_PA_Left_Sensor_Det_Health;

# define Rte_TypeDef_FD14_PA_Line_LM_Color
typedef uint8 FD14_PA_Line_LM_Color;

# define Rte_TypeDef_FD14_PA_Line_LM_Distance
typedef uint16 FD14_PA_Line_LM_Distance;

# define Rte_TypeDef_FD14_PA_Line_LM_Distance_Conf
typedef uint8 FD14_PA_Line_LM_Distance_Conf;

# define Rte_TypeDef_FD14_PA_Line_LM_Heading
typedef uint16 FD14_PA_Line_LM_Heading;

# define Rte_TypeDef_FD14_PA_Line_LM_Heading_Conf
typedef uint8 FD14_PA_Line_LM_Heading_Conf;

# define Rte_TypeDef_FD14_PA_Line_LM_Style
typedef uint8 FD14_PA_Line_LM_Style;

# define Rte_TypeDef_FD14_PA_Line_RM_Color
typedef uint8 FD14_PA_Line_RM_Color;

# define Rte_TypeDef_FD14_PA_Line_RM_Distance
typedef uint16 FD14_PA_Line_RM_Distance;

# define Rte_TypeDef_FD14_PA_Line_RM_Distance_Conf
typedef uint8 FD14_PA_Line_RM_Distance_Conf;

# define Rte_TypeDef_FD14_PA_Line_RM_Heading
typedef uint16 FD14_PA_Line_RM_Heading;

# define Rte_TypeDef_FD14_PA_Line_RM_Heading_Conf
typedef uint8 FD14_PA_Line_RM_Heading_Conf;

# define Rte_TypeDef_FD14_PA_Line_RM_Style
typedef uint8 FD14_PA_Line_RM_Style;

# define Rte_TypeDef_FD14_PA_Obj1_Angle
typedef uint16 FD14_PA_Obj1_Angle;

# define Rte_TypeDef_FD14_PA_Obj1_Angle_2
typedef uint16 FD14_PA_Obj1_Angle_2;

# define Rte_TypeDef_FD14_PA_Obj1_Conf
typedef uint8 FD14_PA_Obj1_Conf;

# define Rte_TypeDef_FD14_PA_Obj1_Range
typedef uint16 FD14_PA_Obj1_Range;

# define Rte_TypeDef_FD14_PA_Obj1_Range_2
typedef uint16 FD14_PA_Obj1_Range_2;

# define Rte_TypeDef_FD14_PA_Obj1_Type
typedef uint8 FD14_PA_Obj1_Type;

# define Rte_TypeDef_FD14_PA_Obj2_Angle
typedef uint16 FD14_PA_Obj2_Angle;

# define Rte_TypeDef_FD14_PA_Obj2_Angle_2
typedef uint16 FD14_PA_Obj2_Angle_2;

# define Rte_TypeDef_FD14_PA_Obj2_Conf
typedef uint8 FD14_PA_Obj2_Conf;

# define Rte_TypeDef_FD14_PA_Obj2_Range
typedef uint16 FD14_PA_Obj2_Range;

# define Rte_TypeDef_FD14_PA_Obj2_Range_2
typedef uint16 FD14_PA_Obj2_Range_2;

# define Rte_TypeDef_FD14_PA_Obj2_Type
typedef uint8 FD14_PA_Obj2_Type;

# define Rte_TypeDef_FD14_PA_Obj3_Angle
typedef uint16 FD14_PA_Obj3_Angle;

# define Rte_TypeDef_FD14_PA_Obj3_Angle_2
typedef uint16 FD14_PA_Obj3_Angle_2;

# define Rte_TypeDef_FD14_PA_Obj3_Conf
typedef uint8 FD14_PA_Obj3_Conf;

# define Rte_TypeDef_FD14_PA_Obj3_Range
typedef uint16 FD14_PA_Obj3_Range;

# define Rte_TypeDef_FD14_PA_Obj3_Range_2
typedef uint16 FD14_PA_Obj3_Range_2;

# define Rte_TypeDef_FD14_PA_Obj3_Type
typedef uint8 FD14_PA_Obj3_Type;

# define Rte_TypeDef_FD14_PA_Obj4_Angle
typedef uint16 FD14_PA_Obj4_Angle;

# define Rte_TypeDef_FD14_PA_Obj4_Angle_2
typedef uint16 FD14_PA_Obj4_Angle_2;

# define Rte_TypeDef_FD14_PA_Obj4_Conf
typedef uint8 FD14_PA_Obj4_Conf;

# define Rte_TypeDef_FD14_PA_Obj4_Range
typedef uint16 FD14_PA_Obj4_Range;

# define Rte_TypeDef_FD14_PA_Obj4_Range_2
typedef uint16 FD14_PA_Obj4_Range_2;

# define Rte_TypeDef_FD14_PA_Obj4_Type
typedef uint8 FD14_PA_Obj4_Type;

# define Rte_TypeDef_FD14_PA_Obj5_Angle
typedef uint16 FD14_PA_Obj5_Angle;

# define Rte_TypeDef_FD14_PA_Obj5_Angle_2
typedef uint16 FD14_PA_Obj5_Angle_2;

# define Rte_TypeDef_FD14_PA_Obj5_Conf
typedef uint8 FD14_PA_Obj5_Conf;

# define Rte_TypeDef_FD14_PA_Obj5_Range
typedef uint16 FD14_PA_Obj5_Range;

# define Rte_TypeDef_FD14_PA_Obj5_Range_2
typedef uint16 FD14_PA_Obj5_Range_2;

# define Rte_TypeDef_FD14_PA_Obj5_Type
typedef uint8 FD14_PA_Obj5_Type;

# define Rte_TypeDef_FD14_PA_Obj6_Angle
typedef uint16 FD14_PA_Obj6_Angle;

# define Rte_TypeDef_FD14_PA_Obj6_Angle_2
typedef uint16 FD14_PA_Obj6_Angle_2;

# define Rte_TypeDef_FD14_PA_Obj6_Conf
typedef uint8 FD14_PA_Obj6_Conf;

# define Rte_TypeDef_FD14_PA_Obj6_Range
typedef uint16 FD14_PA_Obj6_Range;

# define Rte_TypeDef_FD14_PA_Obj6_Range_2
typedef uint16 FD14_PA_Obj6_Range_2;

# define Rte_TypeDef_FD14_PA_Obj6_Type
typedef uint8 FD14_PA_Obj6_Type;

# define Rte_TypeDef_FD14_PA_Right_Sensor_Det_Health
typedef uint8 FD14_PA_Right_Sensor_Det_Health;

# define Rte_TypeDef_FD14_PA_SideSensor_FrontLeft_Conf
typedef uint8 FD14_PA_SideSensor_FrontLeft_Conf;

# define Rte_TypeDef_FD14_PA_SideSensor_FrontLeft_Dist
typedef uint16 FD14_PA_SideSensor_FrontLeft_Dist;

# define Rte_TypeDef_FD14_PA_SideSensor_FrontRight_Conf
typedef uint8 FD14_PA_SideSensor_FrontRight_Conf;

# define Rte_TypeDef_FD14_PA_SideSensor_FrontRight_Dist
typedef uint16 FD14_PA_SideSensor_FrontRight_Dist;

# define Rte_TypeDef_FD14_PA_SideSensor_RearLeft_Conf
typedef uint8 FD14_PA_SideSensor_RearLeft_Conf;

# define Rte_TypeDef_FD14_PA_SideSensor_RearLeft_Dist
typedef uint16 FD14_PA_SideSensor_RearLeft_Dist;

# define Rte_TypeDef_FD14_PA_SideSensor_RearRight_Conf
typedef uint8 FD14_PA_SideSensor_RearRight_Conf;

# define Rte_TypeDef_FD14_PA_SideSensor_RearRight_Dist
typedef uint16 FD14_PA_SideSensor_RearRight_Dist;

# define Rte_TypeDef_FD14_PDC_FrontCenter_Red_b
typedef boolean FD14_PDC_FrontCenter_Red_b;

# define Rte_TypeDef_FD14_PDC_FrontCenter_Yellow_b
typedef boolean FD14_PDC_FrontCenter_Yellow_b;

# define Rte_TypeDef_FD14_PDC_FrontLeft_Red_b
typedef boolean FD14_PDC_FrontLeft_Red_b;

# define Rte_TypeDef_FD14_PDC_FrontLeft_Yellow_b
typedef boolean FD14_PDC_FrontLeft_Yellow_b;

# define Rte_TypeDef_FD14_PDC_FrontRight_Red_b
typedef boolean FD14_PDC_FrontRight_Red_b;

# define Rte_TypeDef_FD14_PDC_FrontRight_Yellow_b
typedef boolean FD14_PDC_FrontRight_Yellow_b;

# define Rte_TypeDef_FD14_PDC_RearCenter_Red_b
typedef boolean FD14_PDC_RearCenter_Red_b;

# define Rte_TypeDef_FD14_PDC_RearCenter_Yellow_b
typedef boolean FD14_PDC_RearCenter_Yellow_b;

# define Rte_TypeDef_FD14_PDC_RearLeft_Red_b
typedef boolean FD14_PDC_RearLeft_Red_b;

# define Rte_TypeDef_FD14_PDC_RearLeft_Yellow_b
typedef boolean FD14_PDC_RearLeft_Yellow_b;

# define Rte_TypeDef_FD14_PDC_RearRight_Red_b
typedef boolean FD14_PDC_RearRight_Red_b;

# define Rte_TypeDef_FD14_PDC_RearRight_Yellow_b
typedef boolean FD14_PDC_RearRight_Yellow_b;

# define Rte_TypeDef_FD14_PPPA_AccelMax
typedef uint8 FD14_PPPA_AccelMax;

# define Rte_TypeDef_FD14_PPPA_AccelMin
typedef uint8 FD14_PPPA_AccelMin;

# define Rte_TypeDef_FD14_PPPA_DecelMax
typedef uint8 FD14_PPPA_DecelMax;

# define Rte_TypeDef_FD14_PPPA_DecelMin
typedef uint8 FD14_PPPA_DecelMin;

# define Rte_TypeDef_FD14_PPPA_JerkAccelMax
typedef uint8 FD14_PPPA_JerkAccelMax;

# define Rte_TypeDef_FD14_PPPA_JerkAccelMin
typedef uint8 FD14_PPPA_JerkAccelMin;

# define Rte_TypeDef_FD14_PPPA_JerkDecelMax
typedef uint8 FD14_PPPA_JerkDecelMax;

# define Rte_TypeDef_FD14_PPPA_JerkDecelMin
typedef uint8 FD14_PPPA_JerkDecelMin;

# define Rte_TypeDef_FD14_Pitch_f32_Current_Rear
typedef float32 FD14_Pitch_f32_Current_Rear;

# define Rte_TypeDef_FD14_Pitch_f32_Current_Right
typedef float32 FD14_Pitch_f32_Current_Right;

# define Rte_TypeDef_FD14_Pitch_f32_EOL_Front
typedef float32 FD14_Pitch_f32_EOL_Front;

# define Rte_TypeDef_FD14_Pitch_f32_EOL_Left
typedef float32 FD14_Pitch_f32_EOL_Left;

# define Rte_TypeDef_FD14_Pitch_f32_EOL_Rear
typedef float32 FD14_Pitch_f32_EOL_Rear;

# define Rte_TypeDef_FD14_Pitch_f32_EOL_Right
typedef float32 FD14_Pitch_f32_EOL_Right;

# define Rte_TypeDef_FD14_Pitch_f32_OC_Front
typedef float32 FD14_Pitch_f32_OC_Front;

# define Rte_TypeDef_FD14_Pitch_f32_OC_Left
typedef float32 FD14_Pitch_f32_OC_Left;

# define Rte_TypeDef_FD14_Pitch_f32_OC_Rear
typedef float32 FD14_Pitch_f32_OC_Rear;

# define Rte_TypeDef_FD14_Pitch_f32_OC_Right
typedef float32 FD14_Pitch_f32_OC_Right;

# define Rte_TypeDef_FD14_Pitch_f32_SC_Front
typedef float32 FD14_Pitch_f32_SC_Front;

# define Rte_TypeDef_FD14_Pitch_f32_SC_Left
typedef float32 FD14_Pitch_f32_SC_Left;

# define Rte_TypeDef_FD14_Pitch_f32_SC_Rear
typedef float32 FD14_Pitch_f32_SC_Rear;

# define Rte_TypeDef_FD14_Pitch_f32_SC_Right
typedef float32 FD14_Pitch_f32_SC_Right;

# define Rte_TypeDef_FD14_Point_Map_Age_0
typedef uint8 FD14_Point_Map_Age_0;

# define Rte_TypeDef_FD14_Point_Map_Age_1
typedef uint8 FD14_Point_Map_Age_1;

# define Rte_TypeDef_FD14_Point_Map_Age_10
typedef uint8 FD14_Point_Map_Age_10;

# define Rte_TypeDef_FD14_Point_Map_Age_11
typedef uint8 FD14_Point_Map_Age_11;

# define Rte_TypeDef_FD14_Point_Map_Age_12
typedef uint8 FD14_Point_Map_Age_12;

# define Rte_TypeDef_FD14_Point_Map_Age_13
typedef uint8 FD14_Point_Map_Age_13;

# define Rte_TypeDef_FD14_Point_Map_Age_14
typedef uint8 FD14_Point_Map_Age_14;

# define Rte_TypeDef_FD14_Point_Map_Age_15
typedef uint8 FD14_Point_Map_Age_15;

# define Rte_TypeDef_FD14_Point_Map_Age_16
typedef uint8 FD14_Point_Map_Age_16;

# define Rte_TypeDef_FD14_Point_Map_Age_17
typedef uint8 FD14_Point_Map_Age_17;

# define Rte_TypeDef_FD14_Point_Map_Age_18
typedef uint8 FD14_Point_Map_Age_18;

# define Rte_TypeDef_FD14_Point_Map_Age_19
typedef uint8 FD14_Point_Map_Age_19;

# define Rte_TypeDef_FD14_Point_Map_Age_2
typedef uint8 FD14_Point_Map_Age_2;

# define Rte_TypeDef_FD14_Point_Map_Age_20
typedef uint8 FD14_Point_Map_Age_20;

# define Rte_TypeDef_FD14_Point_Map_Age_21
typedef uint8 FD14_Point_Map_Age_21;

# define Rte_TypeDef_FD14_Point_Map_Age_22
typedef uint8 FD14_Point_Map_Age_22;

# define Rte_TypeDef_FD14_Point_Map_Age_23
typedef uint8 FD14_Point_Map_Age_23;

# define Rte_TypeDef_FD14_Point_Map_Age_24
typedef uint8 FD14_Point_Map_Age_24;

# define Rte_TypeDef_FD14_Point_Map_Age_25
typedef uint8 FD14_Point_Map_Age_25;

# define Rte_TypeDef_FD14_Point_Map_Age_26
typedef uint8 FD14_Point_Map_Age_26;

# define Rte_TypeDef_FD14_Point_Map_Age_27
typedef uint8 FD14_Point_Map_Age_27;

# define Rte_TypeDef_FD14_Point_Map_Age_28
typedef uint8 FD14_Point_Map_Age_28;

# define Rte_TypeDef_FD14_Point_Map_Age_29
typedef uint8 FD14_Point_Map_Age_29;

# define Rte_TypeDef_FD14_Point_Map_Age_3
typedef uint8 FD14_Point_Map_Age_3;

# define Rte_TypeDef_FD14_Point_Map_Age_30
typedef uint8 FD14_Point_Map_Age_30;

# define Rte_TypeDef_FD14_Point_Map_Age_31
typedef uint8 FD14_Point_Map_Age_31;

# define Rte_TypeDef_FD14_Point_Map_Age_32
typedef uint8 FD14_Point_Map_Age_32;

# define Rte_TypeDef_FD14_Point_Map_Age_33
typedef uint8 FD14_Point_Map_Age_33;

# define Rte_TypeDef_FD14_Point_Map_Age_34
typedef uint8 FD14_Point_Map_Age_34;

# define Rte_TypeDef_FD14_Point_Map_Age_35
typedef uint8 FD14_Point_Map_Age_35;

# define Rte_TypeDef_FD14_Point_Map_Age_36
typedef uint8 FD14_Point_Map_Age_36;

# define Rte_TypeDef_FD14_Point_Map_Age_37
typedef uint8 FD14_Point_Map_Age_37;

# define Rte_TypeDef_FD14_Point_Map_Age_38
typedef uint8 FD14_Point_Map_Age_38;

# define Rte_TypeDef_FD14_Point_Map_Age_39
typedef uint8 FD14_Point_Map_Age_39;

# define Rte_TypeDef_FD14_Point_Map_Age_4
typedef uint8 FD14_Point_Map_Age_4;

# define Rte_TypeDef_FD14_Point_Map_Age_40
typedef uint8 FD14_Point_Map_Age_40;

# define Rte_TypeDef_FD14_Point_Map_Age_41
typedef uint8 FD14_Point_Map_Age_41;

# define Rte_TypeDef_FD14_Point_Map_Age_42
typedef uint8 FD14_Point_Map_Age_42;

# define Rte_TypeDef_FD14_Point_Map_Age_43
typedef uint8 FD14_Point_Map_Age_43;

# define Rte_TypeDef_FD14_Point_Map_Age_44
typedef uint8 FD14_Point_Map_Age_44;

# define Rte_TypeDef_FD14_Point_Map_Age_45
typedef uint8 FD14_Point_Map_Age_45;

# define Rte_TypeDef_FD14_Point_Map_Age_46
typedef uint8 FD14_Point_Map_Age_46;

# define Rte_TypeDef_FD14_Point_Map_Age_47
typedef uint8 FD14_Point_Map_Age_47;

# define Rte_TypeDef_FD14_Point_Map_Age_48
typedef uint8 FD14_Point_Map_Age_48;

# define Rte_TypeDef_FD14_Point_Map_Age_49
typedef uint8 FD14_Point_Map_Age_49;

# define Rte_TypeDef_FD14_Point_Map_Age_5
typedef uint8 FD14_Point_Map_Age_5;

# define Rte_TypeDef_FD14_Point_Map_Age_50
typedef uint8 FD14_Point_Map_Age_50;

# define Rte_TypeDef_FD14_Point_Map_Age_51
typedef uint8 FD14_Point_Map_Age_51;

# define Rte_TypeDef_FD14_Point_Map_Age_52
typedef uint8 FD14_Point_Map_Age_52;

# define Rte_TypeDef_FD14_Point_Map_Age_53
typedef uint8 FD14_Point_Map_Age_53;

# define Rte_TypeDef_FD14_Point_Map_Age_54
typedef uint8 FD14_Point_Map_Age_54;

# define Rte_TypeDef_FD14_Point_Map_Age_55
typedef uint8 FD14_Point_Map_Age_55;

# define Rte_TypeDef_FD14_Point_Map_Age_56
typedef uint8 FD14_Point_Map_Age_56;

# define Rte_TypeDef_FD14_Point_Map_Age_57
typedef uint8 FD14_Point_Map_Age_57;

# define Rte_TypeDef_FD14_Point_Map_Age_58
typedef uint8 FD14_Point_Map_Age_58;

# define Rte_TypeDef_FD14_Point_Map_Age_59
typedef uint8 FD14_Point_Map_Age_59;

# define Rte_TypeDef_FD14_Point_Map_Age_6
typedef uint8 FD14_Point_Map_Age_6;

# define Rte_TypeDef_FD14_Point_Map_Age_60
typedef uint8 FD14_Point_Map_Age_60;

# define Rte_TypeDef_FD14_Point_Map_Age_61
typedef uint8 FD14_Point_Map_Age_61;

# define Rte_TypeDef_FD14_Point_Map_Age_62
typedef uint8 FD14_Point_Map_Age_62;

# define Rte_TypeDef_FD14_Point_Map_Age_63
typedef uint8 FD14_Point_Map_Age_63;

# define Rte_TypeDef_FD14_Point_Map_Age_64
typedef uint8 FD14_Point_Map_Age_64;

# define Rte_TypeDef_FD14_Point_Map_Age_65
typedef uint8 FD14_Point_Map_Age_65;

# define Rte_TypeDef_FD14_Point_Map_Age_66
typedef uint8 FD14_Point_Map_Age_66;

# define Rte_TypeDef_FD14_Point_Map_Age_67
typedef uint8 FD14_Point_Map_Age_67;

# define Rte_TypeDef_FD14_Point_Map_Age_68
typedef uint8 FD14_Point_Map_Age_68;

# define Rte_TypeDef_FD14_Point_Map_Age_69
typedef uint8 FD14_Point_Map_Age_69;

# define Rte_TypeDef_FD14_Point_Map_Age_7
typedef uint8 FD14_Point_Map_Age_7;

# define Rte_TypeDef_FD14_Point_Map_Age_70
typedef uint8 FD14_Point_Map_Age_70;

# define Rte_TypeDef_FD14_Point_Map_Age_71
typedef uint8 FD14_Point_Map_Age_71;

# define Rte_TypeDef_FD14_Point_Map_Age_72
typedef uint8 FD14_Point_Map_Age_72;

# define Rte_TypeDef_FD14_Point_Map_Age_73
typedef uint8 FD14_Point_Map_Age_73;

# define Rte_TypeDef_FD14_Point_Map_Age_74
typedef uint8 FD14_Point_Map_Age_74;

# define Rte_TypeDef_FD14_Point_Map_Age_75
typedef uint8 FD14_Point_Map_Age_75;

# define Rte_TypeDef_FD14_Point_Map_Age_76
typedef uint8 FD14_Point_Map_Age_76;

# define Rte_TypeDef_FD14_Point_Map_Age_77
typedef uint8 FD14_Point_Map_Age_77;

# define Rte_TypeDef_FD14_Point_Map_Age_78
typedef uint8 FD14_Point_Map_Age_78;

# define Rte_TypeDef_FD14_Point_Map_Age_79
typedef uint8 FD14_Point_Map_Age_79;

# define Rte_TypeDef_FD14_Point_Map_Age_8
typedef uint8 FD14_Point_Map_Age_8;

# define Rte_TypeDef_FD14_Point_Map_Age_80
typedef uint8 FD14_Point_Map_Age_80;

# define Rte_TypeDef_FD14_Point_Map_Age_81
typedef uint8 FD14_Point_Map_Age_81;

# define Rte_TypeDef_FD14_Point_Map_Age_82
typedef uint8 FD14_Point_Map_Age_82;

# define Rte_TypeDef_FD14_Point_Map_Age_83
typedef uint8 FD14_Point_Map_Age_83;

# define Rte_TypeDef_FD14_Point_Map_Age_84
typedef uint8 FD14_Point_Map_Age_84;

# define Rte_TypeDef_FD14_Point_Map_Age_85
typedef uint8 FD14_Point_Map_Age_85;

# define Rte_TypeDef_FD14_Point_Map_Age_86
typedef uint8 FD14_Point_Map_Age_86;

# define Rte_TypeDef_FD14_Point_Map_Age_87
typedef uint8 FD14_Point_Map_Age_87;

# define Rte_TypeDef_FD14_Point_Map_Age_88
typedef uint8 FD14_Point_Map_Age_88;

# define Rte_TypeDef_FD14_Point_Map_Age_89
typedef uint8 FD14_Point_Map_Age_89;

# define Rte_TypeDef_FD14_Point_Map_Age_9
typedef uint8 FD14_Point_Map_Age_9;

# define Rte_TypeDef_FD14_Point_Map_Age_90
typedef uint8 FD14_Point_Map_Age_90;

# define Rte_TypeDef_FD14_Point_Map_Age_91
typedef uint8 FD14_Point_Map_Age_91;

# define Rte_TypeDef_FD14_Point_Map_Age_92
typedef uint8 FD14_Point_Map_Age_92;

# define Rte_TypeDef_FD14_Point_Map_Age_93
typedef uint8 FD14_Point_Map_Age_93;

# define Rte_TypeDef_FD14_Point_Map_Age_94
typedef uint8 FD14_Point_Map_Age_94;

# define Rte_TypeDef_FD14_Point_Map_Age_95
typedef uint8 FD14_Point_Map_Age_95;

# define Rte_TypeDef_FD14_Point_Map_Confidence_0
typedef uint8 FD14_Point_Map_Confidence_0;

# define Rte_TypeDef_FD14_Point_Map_Confidence_1
typedef uint8 FD14_Point_Map_Confidence_1;

# define Rte_TypeDef_FD14_Point_Map_Confidence_10
typedef uint8 FD14_Point_Map_Confidence_10;

# define Rte_TypeDef_FD14_Point_Map_Confidence_11
typedef uint8 FD14_Point_Map_Confidence_11;

# define Rte_TypeDef_FD14_Point_Map_Confidence_12
typedef uint8 FD14_Point_Map_Confidence_12;

# define Rte_TypeDef_FD14_Point_Map_Confidence_13
typedef uint8 FD14_Point_Map_Confidence_13;

# define Rte_TypeDef_FD14_Point_Map_Confidence_14
typedef uint8 FD14_Point_Map_Confidence_14;

# define Rte_TypeDef_FD14_Point_Map_Confidence_15
typedef uint8 FD14_Point_Map_Confidence_15;

# define Rte_TypeDef_FD14_Point_Map_Confidence_16
typedef uint8 FD14_Point_Map_Confidence_16;

# define Rte_TypeDef_FD14_Point_Map_Confidence_17
typedef uint8 FD14_Point_Map_Confidence_17;

# define Rte_TypeDef_FD14_Point_Map_Confidence_18
typedef uint8 FD14_Point_Map_Confidence_18;

# define Rte_TypeDef_FD14_Point_Map_Confidence_19
typedef uint8 FD14_Point_Map_Confidence_19;

# define Rte_TypeDef_FD14_Point_Map_Confidence_2
typedef uint8 FD14_Point_Map_Confidence_2;

# define Rte_TypeDef_FD14_Point_Map_Confidence_20
typedef uint8 FD14_Point_Map_Confidence_20;

# define Rte_TypeDef_FD14_Point_Map_Confidence_21
typedef uint8 FD14_Point_Map_Confidence_21;

# define Rte_TypeDef_FD14_Point_Map_Confidence_22
typedef uint8 FD14_Point_Map_Confidence_22;

# define Rte_TypeDef_FD14_Point_Map_Confidence_23
typedef uint8 FD14_Point_Map_Confidence_23;

# define Rte_TypeDef_FD14_Point_Map_Confidence_24
typedef uint8 FD14_Point_Map_Confidence_24;

# define Rte_TypeDef_FD14_Point_Map_Confidence_25
typedef uint8 FD14_Point_Map_Confidence_25;

# define Rte_TypeDef_FD14_Point_Map_Confidence_26
typedef uint8 FD14_Point_Map_Confidence_26;

# define Rte_TypeDef_FD14_Point_Map_Confidence_27
typedef uint8 FD14_Point_Map_Confidence_27;

# define Rte_TypeDef_FD14_Point_Map_Confidence_28
typedef uint8 FD14_Point_Map_Confidence_28;

# define Rte_TypeDef_FD14_Point_Map_Confidence_29
typedef uint8 FD14_Point_Map_Confidence_29;

# define Rte_TypeDef_FD14_Point_Map_Confidence_3
typedef uint8 FD14_Point_Map_Confidence_3;

# define Rte_TypeDef_FD14_Point_Map_Confidence_30
typedef uint8 FD14_Point_Map_Confidence_30;

# define Rte_TypeDef_FD14_Point_Map_Confidence_31
typedef uint8 FD14_Point_Map_Confidence_31;

# define Rte_TypeDef_FD14_Point_Map_Confidence_32
typedef uint8 FD14_Point_Map_Confidence_32;

# define Rte_TypeDef_FD14_Point_Map_Confidence_33
typedef uint8 FD14_Point_Map_Confidence_33;

# define Rte_TypeDef_FD14_Point_Map_Confidence_34
typedef uint8 FD14_Point_Map_Confidence_34;

# define Rte_TypeDef_FD14_Point_Map_Confidence_35
typedef uint8 FD14_Point_Map_Confidence_35;

# define Rte_TypeDef_FD14_Point_Map_Confidence_36
typedef uint8 FD14_Point_Map_Confidence_36;

# define Rte_TypeDef_FD14_Point_Map_Confidence_37
typedef uint8 FD14_Point_Map_Confidence_37;

# define Rte_TypeDef_FD14_Point_Map_Confidence_38
typedef uint8 FD14_Point_Map_Confidence_38;

# define Rte_TypeDef_FD14_Point_Map_Confidence_39
typedef uint8 FD14_Point_Map_Confidence_39;

# define Rte_TypeDef_FD14_Point_Map_Confidence_4
typedef uint8 FD14_Point_Map_Confidence_4;

# define Rte_TypeDef_FD14_Point_Map_Confidence_40
typedef uint8 FD14_Point_Map_Confidence_40;

# define Rte_TypeDef_FD14_Point_Map_Confidence_41
typedef uint8 FD14_Point_Map_Confidence_41;

# define Rte_TypeDef_FD14_Point_Map_Confidence_42
typedef uint8 FD14_Point_Map_Confidence_42;

# define Rte_TypeDef_FD14_Point_Map_Confidence_43
typedef uint8 FD14_Point_Map_Confidence_43;

# define Rte_TypeDef_FD14_Point_Map_Confidence_44
typedef uint8 FD14_Point_Map_Confidence_44;

# define Rte_TypeDef_FD14_Point_Map_Confidence_45
typedef uint8 FD14_Point_Map_Confidence_45;

# define Rte_TypeDef_FD14_Point_Map_Confidence_46
typedef uint8 FD14_Point_Map_Confidence_46;

# define Rte_TypeDef_FD14_Point_Map_Confidence_47
typedef uint8 FD14_Point_Map_Confidence_47;

# define Rte_TypeDef_FD14_Point_Map_Confidence_48
typedef uint8 FD14_Point_Map_Confidence_48;

# define Rte_TypeDef_FD14_Point_Map_Confidence_49
typedef uint8 FD14_Point_Map_Confidence_49;

# define Rte_TypeDef_FD14_Point_Map_Confidence_5
typedef uint8 FD14_Point_Map_Confidence_5;

# define Rte_TypeDef_FD14_Point_Map_Confidence_50
typedef uint8 FD14_Point_Map_Confidence_50;

# define Rte_TypeDef_FD14_Point_Map_Confidence_51
typedef uint8 FD14_Point_Map_Confidence_51;

# define Rte_TypeDef_FD14_Point_Map_Confidence_52
typedef uint8 FD14_Point_Map_Confidence_52;

# define Rte_TypeDef_FD14_Point_Map_Confidence_53
typedef uint8 FD14_Point_Map_Confidence_53;

# define Rte_TypeDef_FD14_Point_Map_Confidence_54
typedef uint8 FD14_Point_Map_Confidence_54;

# define Rte_TypeDef_FD14_Point_Map_Confidence_55
typedef uint8 FD14_Point_Map_Confidence_55;

# define Rte_TypeDef_FD14_Point_Map_Confidence_56
typedef uint8 FD14_Point_Map_Confidence_56;

# define Rte_TypeDef_FD14_Point_Map_Confidence_57
typedef uint8 FD14_Point_Map_Confidence_57;

# define Rte_TypeDef_FD14_Point_Map_Confidence_58
typedef uint8 FD14_Point_Map_Confidence_58;

# define Rte_TypeDef_FD14_Point_Map_Confidence_59
typedef uint8 FD14_Point_Map_Confidence_59;

# define Rte_TypeDef_FD14_Point_Map_Confidence_6
typedef uint8 FD14_Point_Map_Confidence_6;

# define Rte_TypeDef_FD14_Point_Map_Confidence_60
typedef uint8 FD14_Point_Map_Confidence_60;

# define Rte_TypeDef_FD14_Point_Map_Confidence_61
typedef uint8 FD14_Point_Map_Confidence_61;

# define Rte_TypeDef_FD14_Point_Map_Confidence_62
typedef uint8 FD14_Point_Map_Confidence_62;

# define Rte_TypeDef_FD14_Point_Map_Confidence_63
typedef uint8 FD14_Point_Map_Confidence_63;

# define Rte_TypeDef_FD14_Point_Map_Confidence_64
typedef uint8 FD14_Point_Map_Confidence_64;

# define Rte_TypeDef_FD14_Point_Map_Confidence_65
typedef uint8 FD14_Point_Map_Confidence_65;

# define Rte_TypeDef_FD14_Point_Map_Confidence_66
typedef uint8 FD14_Point_Map_Confidence_66;

# define Rte_TypeDef_FD14_Point_Map_Confidence_67
typedef uint8 FD14_Point_Map_Confidence_67;

# define Rte_TypeDef_FD14_Point_Map_Confidence_68
typedef uint8 FD14_Point_Map_Confidence_68;

# define Rte_TypeDef_FD14_Point_Map_Confidence_69
typedef uint8 FD14_Point_Map_Confidence_69;

# define Rte_TypeDef_FD14_Point_Map_Confidence_7
typedef uint8 FD14_Point_Map_Confidence_7;

# define Rte_TypeDef_FD14_Point_Map_Confidence_70
typedef uint8 FD14_Point_Map_Confidence_70;

# define Rte_TypeDef_FD14_Point_Map_Confidence_71
typedef uint8 FD14_Point_Map_Confidence_71;

# define Rte_TypeDef_FD14_Point_Map_Confidence_72
typedef uint8 FD14_Point_Map_Confidence_72;

# define Rte_TypeDef_FD14_Point_Map_Confidence_73
typedef uint8 FD14_Point_Map_Confidence_73;

# define Rte_TypeDef_FD14_Point_Map_Confidence_74
typedef uint8 FD14_Point_Map_Confidence_74;

# define Rte_TypeDef_FD14_Point_Map_Confidence_75
typedef uint8 FD14_Point_Map_Confidence_75;

# define Rte_TypeDef_FD14_Point_Map_Confidence_76
typedef uint8 FD14_Point_Map_Confidence_76;

# define Rte_TypeDef_FD14_Point_Map_Confidence_77
typedef uint8 FD14_Point_Map_Confidence_77;

# define Rte_TypeDef_FD14_Point_Map_Confidence_78
typedef uint8 FD14_Point_Map_Confidence_78;

# define Rte_TypeDef_FD14_Point_Map_Confidence_79
typedef uint8 FD14_Point_Map_Confidence_79;

# define Rte_TypeDef_FD14_Point_Map_Confidence_8
typedef uint8 FD14_Point_Map_Confidence_8;

# define Rte_TypeDef_FD14_Point_Map_Confidence_80
typedef uint8 FD14_Point_Map_Confidence_80;

# define Rte_TypeDef_FD14_Point_Map_Confidence_81
typedef uint8 FD14_Point_Map_Confidence_81;

# define Rte_TypeDef_FD14_Point_Map_Confidence_82
typedef uint8 FD14_Point_Map_Confidence_82;

# define Rte_TypeDef_FD14_Point_Map_Confidence_83
typedef uint8 FD14_Point_Map_Confidence_83;

# define Rte_TypeDef_FD14_Point_Map_Confidence_84
typedef uint8 FD14_Point_Map_Confidence_84;

# define Rte_TypeDef_FD14_Point_Map_Confidence_85
typedef uint8 FD14_Point_Map_Confidence_85;

# define Rte_TypeDef_FD14_Point_Map_Confidence_86
typedef uint8 FD14_Point_Map_Confidence_86;

# define Rte_TypeDef_FD14_Point_Map_Confidence_87
typedef uint8 FD14_Point_Map_Confidence_87;

# define Rte_TypeDef_FD14_Point_Map_Confidence_88
typedef uint8 FD14_Point_Map_Confidence_88;

# define Rte_TypeDef_FD14_Point_Map_Confidence_89
typedef uint8 FD14_Point_Map_Confidence_89;

# define Rte_TypeDef_FD14_Point_Map_Confidence_9
typedef uint8 FD14_Point_Map_Confidence_9;

# define Rte_TypeDef_FD14_Point_Map_Confidence_90
typedef uint8 FD14_Point_Map_Confidence_90;

# define Rte_TypeDef_FD14_Point_Map_Confidence_91
typedef uint8 FD14_Point_Map_Confidence_91;

# define Rte_TypeDef_FD14_Point_Map_Confidence_92
typedef uint8 FD14_Point_Map_Confidence_92;

# define Rte_TypeDef_FD14_Point_Map_Confidence_93
typedef uint8 FD14_Point_Map_Confidence_93;

# define Rte_TypeDef_FD14_Point_Map_Confidence_94
typedef uint8 FD14_Point_Map_Confidence_94;

# define Rte_TypeDef_FD14_Point_Map_Confidence_95
typedef uint8 FD14_Point_Map_Confidence_95;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_0
typedef uint8 FD14_Point_Map_Cruising_Age_0;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_1
typedef uint8 FD14_Point_Map_Cruising_Age_1;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_10
typedef uint8 FD14_Point_Map_Cruising_Age_10;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_11
typedef uint8 FD14_Point_Map_Cruising_Age_11;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_12
typedef uint8 FD14_Point_Map_Cruising_Age_12;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_13
typedef uint8 FD14_Point_Map_Cruising_Age_13;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_14
typedef uint8 FD14_Point_Map_Cruising_Age_14;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_15
typedef uint8 FD14_Point_Map_Cruising_Age_15;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_16
typedef uint8 FD14_Point_Map_Cruising_Age_16;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_17
typedef uint8 FD14_Point_Map_Cruising_Age_17;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_18
typedef uint8 FD14_Point_Map_Cruising_Age_18;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_19
typedef uint8 FD14_Point_Map_Cruising_Age_19;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_2
typedef uint8 FD14_Point_Map_Cruising_Age_2;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_20
typedef uint8 FD14_Point_Map_Cruising_Age_20;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_21
typedef uint8 FD14_Point_Map_Cruising_Age_21;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_22
typedef uint8 FD14_Point_Map_Cruising_Age_22;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_23
typedef uint8 FD14_Point_Map_Cruising_Age_23;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_24
typedef uint8 FD14_Point_Map_Cruising_Age_24;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_25
typedef uint8 FD14_Point_Map_Cruising_Age_25;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_26
typedef uint8 FD14_Point_Map_Cruising_Age_26;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_27
typedef uint8 FD14_Point_Map_Cruising_Age_27;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_28
typedef uint8 FD14_Point_Map_Cruising_Age_28;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_29
typedef uint8 FD14_Point_Map_Cruising_Age_29;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_3
typedef uint8 FD14_Point_Map_Cruising_Age_3;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_30
typedef uint8 FD14_Point_Map_Cruising_Age_30;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_31
typedef uint8 FD14_Point_Map_Cruising_Age_31;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_32
typedef uint8 FD14_Point_Map_Cruising_Age_32;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_33
typedef uint8 FD14_Point_Map_Cruising_Age_33;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_34
typedef uint8 FD14_Point_Map_Cruising_Age_34;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_35
typedef uint8 FD14_Point_Map_Cruising_Age_35;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_36
typedef uint8 FD14_Point_Map_Cruising_Age_36;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_37
typedef uint8 FD14_Point_Map_Cruising_Age_37;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_38
typedef uint8 FD14_Point_Map_Cruising_Age_38;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_39
typedef uint8 FD14_Point_Map_Cruising_Age_39;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_4
typedef uint8 FD14_Point_Map_Cruising_Age_4;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_40
typedef uint8 FD14_Point_Map_Cruising_Age_40;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_41
typedef uint8 FD14_Point_Map_Cruising_Age_41;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_42
typedef uint8 FD14_Point_Map_Cruising_Age_42;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_43
typedef uint8 FD14_Point_Map_Cruising_Age_43;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_44
typedef uint8 FD14_Point_Map_Cruising_Age_44;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_45
typedef uint8 FD14_Point_Map_Cruising_Age_45;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_46
typedef uint8 FD14_Point_Map_Cruising_Age_46;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_47
typedef uint8 FD14_Point_Map_Cruising_Age_47;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_48
typedef uint8 FD14_Point_Map_Cruising_Age_48;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_49
typedef uint8 FD14_Point_Map_Cruising_Age_49;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_5
typedef uint8 FD14_Point_Map_Cruising_Age_5;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_50
typedef uint8 FD14_Point_Map_Cruising_Age_50;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_51
typedef uint8 FD14_Point_Map_Cruising_Age_51;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_52
typedef uint8 FD14_Point_Map_Cruising_Age_52;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_53
typedef uint8 FD14_Point_Map_Cruising_Age_53;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_54
typedef uint8 FD14_Point_Map_Cruising_Age_54;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_55
typedef uint8 FD14_Point_Map_Cruising_Age_55;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_56
typedef uint8 FD14_Point_Map_Cruising_Age_56;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_57
typedef uint8 FD14_Point_Map_Cruising_Age_57;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_58
typedef uint8 FD14_Point_Map_Cruising_Age_58;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_59
typedef uint8 FD14_Point_Map_Cruising_Age_59;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_6
typedef uint8 FD14_Point_Map_Cruising_Age_6;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_60
typedef uint8 FD14_Point_Map_Cruising_Age_60;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_61
typedef uint8 FD14_Point_Map_Cruising_Age_61;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_62
typedef uint8 FD14_Point_Map_Cruising_Age_62;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_63
typedef uint8 FD14_Point_Map_Cruising_Age_63;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_64
typedef uint8 FD14_Point_Map_Cruising_Age_64;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_65
typedef uint8 FD14_Point_Map_Cruising_Age_65;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_66
typedef uint8 FD14_Point_Map_Cruising_Age_66;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_67
typedef uint8 FD14_Point_Map_Cruising_Age_67;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_68
typedef uint8 FD14_Point_Map_Cruising_Age_68;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_69
typedef uint8 FD14_Point_Map_Cruising_Age_69;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_7
typedef uint8 FD14_Point_Map_Cruising_Age_7;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_70
typedef uint8 FD14_Point_Map_Cruising_Age_70;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_71
typedef uint8 FD14_Point_Map_Cruising_Age_71;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_72
typedef uint8 FD14_Point_Map_Cruising_Age_72;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_73
typedef uint8 FD14_Point_Map_Cruising_Age_73;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_74
typedef uint8 FD14_Point_Map_Cruising_Age_74;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_75
typedef uint8 FD14_Point_Map_Cruising_Age_75;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_76
typedef uint8 FD14_Point_Map_Cruising_Age_76;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_77
typedef uint8 FD14_Point_Map_Cruising_Age_77;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_78
typedef uint8 FD14_Point_Map_Cruising_Age_78;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_79
typedef uint8 FD14_Point_Map_Cruising_Age_79;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_8
typedef uint8 FD14_Point_Map_Cruising_Age_8;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_80
typedef uint8 FD14_Point_Map_Cruising_Age_80;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_81
typedef uint8 FD14_Point_Map_Cruising_Age_81;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_82
typedef uint8 FD14_Point_Map_Cruising_Age_82;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_83
typedef uint8 FD14_Point_Map_Cruising_Age_83;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_84
typedef uint8 FD14_Point_Map_Cruising_Age_84;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_85
typedef uint8 FD14_Point_Map_Cruising_Age_85;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_86
typedef uint8 FD14_Point_Map_Cruising_Age_86;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_87
typedef uint8 FD14_Point_Map_Cruising_Age_87;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_88
typedef uint8 FD14_Point_Map_Cruising_Age_88;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_89
typedef uint8 FD14_Point_Map_Cruising_Age_89;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_9
typedef uint8 FD14_Point_Map_Cruising_Age_9;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_90
typedef uint8 FD14_Point_Map_Cruising_Age_90;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_91
typedef uint8 FD14_Point_Map_Cruising_Age_91;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_92
typedef uint8 FD14_Point_Map_Cruising_Age_92;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_93
typedef uint8 FD14_Point_Map_Cruising_Age_93;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_94
typedef uint8 FD14_Point_Map_Cruising_Age_94;

# define Rte_TypeDef_FD14_Point_Map_Cruising_Age_95
typedef uint8 FD14_Point_Map_Cruising_Age_95;

# define Rte_TypeDef_FD14_Point_Map_Height_0
typedef uint8 FD14_Point_Map_Height_0;

# define Rte_TypeDef_FD14_Point_Map_Height_1
typedef uint8 FD14_Point_Map_Height_1;

# define Rte_TypeDef_FD14_Point_Map_Height_10
typedef uint8 FD14_Point_Map_Height_10;

# define Rte_TypeDef_FD14_Point_Map_Height_11
typedef uint8 FD14_Point_Map_Height_11;

# define Rte_TypeDef_FD14_Point_Map_Height_12
typedef uint8 FD14_Point_Map_Height_12;

# define Rte_TypeDef_FD14_Point_Map_Height_13
typedef uint8 FD14_Point_Map_Height_13;

# define Rte_TypeDef_FD14_Point_Map_Height_14
typedef uint8 FD14_Point_Map_Height_14;

# define Rte_TypeDef_FD14_Point_Map_Height_15
typedef uint8 FD14_Point_Map_Height_15;

# define Rte_TypeDef_FD14_Point_Map_Height_16
typedef uint8 FD14_Point_Map_Height_16;

# define Rte_TypeDef_FD14_Point_Map_Height_17
typedef uint8 FD14_Point_Map_Height_17;

# define Rte_TypeDef_FD14_Point_Map_Height_18
typedef uint8 FD14_Point_Map_Height_18;

# define Rte_TypeDef_FD14_Point_Map_Height_19
typedef uint8 FD14_Point_Map_Height_19;

# define Rte_TypeDef_FD14_Point_Map_Height_2
typedef uint8 FD14_Point_Map_Height_2;

# define Rte_TypeDef_FD14_Point_Map_Height_20
typedef uint8 FD14_Point_Map_Height_20;

# define Rte_TypeDef_FD14_Point_Map_Height_21
typedef uint8 FD14_Point_Map_Height_21;

# define Rte_TypeDef_FD14_Point_Map_Height_22
typedef uint8 FD14_Point_Map_Height_22;

# define Rte_TypeDef_FD14_Point_Map_Height_23
typedef uint8 FD14_Point_Map_Height_23;

# define Rte_TypeDef_FD14_Point_Map_Height_24
typedef uint8 FD14_Point_Map_Height_24;

# define Rte_TypeDef_FD14_Point_Map_Height_25
typedef uint8 FD14_Point_Map_Height_25;

# define Rte_TypeDef_FD14_Point_Map_Height_26
typedef uint8 FD14_Point_Map_Height_26;

# define Rte_TypeDef_FD14_Point_Map_Height_27
typedef uint8 FD14_Point_Map_Height_27;

# define Rte_TypeDef_FD14_Point_Map_Height_28
typedef uint8 FD14_Point_Map_Height_28;

# define Rte_TypeDef_FD14_Point_Map_Height_29
typedef uint8 FD14_Point_Map_Height_29;

# define Rte_TypeDef_FD14_Point_Map_Height_3
typedef uint8 FD14_Point_Map_Height_3;

# define Rte_TypeDef_FD14_Point_Map_Height_30
typedef uint8 FD14_Point_Map_Height_30;

# define Rte_TypeDef_FD14_Point_Map_Height_31
typedef uint8 FD14_Point_Map_Height_31;

# define Rte_TypeDef_FD14_Point_Map_Height_32
typedef uint8 FD14_Point_Map_Height_32;

# define Rte_TypeDef_FD14_Point_Map_Height_33
typedef uint8 FD14_Point_Map_Height_33;

# define Rte_TypeDef_FD14_Point_Map_Height_34
typedef uint8 FD14_Point_Map_Height_34;

# define Rte_TypeDef_FD14_Point_Map_Height_35
typedef uint8 FD14_Point_Map_Height_35;

# define Rte_TypeDef_FD14_Point_Map_Height_36
typedef uint8 FD14_Point_Map_Height_36;

# define Rte_TypeDef_FD14_Point_Map_Height_37
typedef uint8 FD14_Point_Map_Height_37;

# define Rte_TypeDef_FD14_Point_Map_Height_38
typedef uint8 FD14_Point_Map_Height_38;

# define Rte_TypeDef_FD14_Point_Map_Height_39
typedef uint8 FD14_Point_Map_Height_39;

# define Rte_TypeDef_FD14_Point_Map_Height_4
typedef uint8 FD14_Point_Map_Height_4;

# define Rte_TypeDef_FD14_Point_Map_Height_40
typedef uint8 FD14_Point_Map_Height_40;

# define Rte_TypeDef_FD14_Point_Map_Height_41
typedef uint8 FD14_Point_Map_Height_41;

# define Rte_TypeDef_FD14_Point_Map_Height_42
typedef uint8 FD14_Point_Map_Height_42;

# define Rte_TypeDef_FD14_Point_Map_Height_43
typedef uint8 FD14_Point_Map_Height_43;

# define Rte_TypeDef_FD14_Point_Map_Height_44
typedef uint8 FD14_Point_Map_Height_44;

# define Rte_TypeDef_FD14_Point_Map_Height_45
typedef uint8 FD14_Point_Map_Height_45;

# define Rte_TypeDef_FD14_Point_Map_Height_46
typedef uint8 FD14_Point_Map_Height_46;

# define Rte_TypeDef_FD14_Point_Map_Height_47
typedef uint8 FD14_Point_Map_Height_47;

# define Rte_TypeDef_FD14_Point_Map_Height_48
typedef uint8 FD14_Point_Map_Height_48;

# define Rte_TypeDef_FD14_Point_Map_Height_49
typedef uint8 FD14_Point_Map_Height_49;

# define Rte_TypeDef_FD14_Point_Map_Height_5
typedef uint8 FD14_Point_Map_Height_5;

# define Rte_TypeDef_FD14_Point_Map_Height_50
typedef uint8 FD14_Point_Map_Height_50;

# define Rte_TypeDef_FD14_Point_Map_Height_51
typedef uint8 FD14_Point_Map_Height_51;

# define Rte_TypeDef_FD14_Point_Map_Height_52
typedef uint8 FD14_Point_Map_Height_52;

# define Rte_TypeDef_FD14_Point_Map_Height_53
typedef uint8 FD14_Point_Map_Height_53;

# define Rte_TypeDef_FD14_Point_Map_Height_54
typedef uint8 FD14_Point_Map_Height_54;

# define Rte_TypeDef_FD14_Point_Map_Height_55
typedef uint8 FD14_Point_Map_Height_55;

# define Rte_TypeDef_FD14_Point_Map_Height_56
typedef uint8 FD14_Point_Map_Height_56;

# define Rte_TypeDef_FD14_Point_Map_Height_57
typedef uint8 FD14_Point_Map_Height_57;

# define Rte_TypeDef_FD14_Point_Map_Height_58
typedef uint8 FD14_Point_Map_Height_58;

# define Rte_TypeDef_FD14_Point_Map_Height_59
typedef uint8 FD14_Point_Map_Height_59;

# define Rte_TypeDef_FD14_Point_Map_Height_6
typedef uint8 FD14_Point_Map_Height_6;

# define Rte_TypeDef_FD14_Point_Map_Height_60
typedef uint8 FD14_Point_Map_Height_60;

# define Rte_TypeDef_FD14_Point_Map_Height_61
typedef uint8 FD14_Point_Map_Height_61;

# define Rte_TypeDef_FD14_Point_Map_Height_62
typedef uint8 FD14_Point_Map_Height_62;

# define Rte_TypeDef_FD14_Point_Map_Height_63
typedef uint8 FD14_Point_Map_Height_63;

# define Rte_TypeDef_FD14_Point_Map_Height_64
typedef uint8 FD14_Point_Map_Height_64;

# define Rte_TypeDef_FD14_Point_Map_Height_65
typedef uint8 FD14_Point_Map_Height_65;

# define Rte_TypeDef_FD14_Point_Map_Height_66
typedef uint8 FD14_Point_Map_Height_66;

# define Rte_TypeDef_FD14_Point_Map_Height_67
typedef uint8 FD14_Point_Map_Height_67;

# define Rte_TypeDef_FD14_Point_Map_Height_68
typedef uint8 FD14_Point_Map_Height_68;

# define Rte_TypeDef_FD14_Point_Map_Height_69
typedef uint8 FD14_Point_Map_Height_69;

# define Rte_TypeDef_FD14_Point_Map_Height_7
typedef uint8 FD14_Point_Map_Height_7;

# define Rte_TypeDef_FD14_Point_Map_Height_70
typedef uint8 FD14_Point_Map_Height_70;

# define Rte_TypeDef_FD14_Point_Map_Height_71
typedef uint8 FD14_Point_Map_Height_71;

# define Rte_TypeDef_FD14_Point_Map_Height_72
typedef uint8 FD14_Point_Map_Height_72;

# define Rte_TypeDef_FD14_Point_Map_Height_73
typedef uint8 FD14_Point_Map_Height_73;

# define Rte_TypeDef_FD14_Point_Map_Height_74
typedef uint8 FD14_Point_Map_Height_74;

# define Rte_TypeDef_FD14_Point_Map_Height_75
typedef uint8 FD14_Point_Map_Height_75;

# define Rte_TypeDef_FD14_Point_Map_Height_76
typedef uint8 FD14_Point_Map_Height_76;

# define Rte_TypeDef_FD14_Point_Map_Height_77
typedef uint8 FD14_Point_Map_Height_77;

# define Rte_TypeDef_FD14_Point_Map_Height_78
typedef uint8 FD14_Point_Map_Height_78;

# define Rte_TypeDef_FD14_Point_Map_Height_79
typedef uint8 FD14_Point_Map_Height_79;

# define Rte_TypeDef_FD14_Point_Map_Height_8
typedef uint8 FD14_Point_Map_Height_8;

# define Rte_TypeDef_FD14_Point_Map_Height_80
typedef uint8 FD14_Point_Map_Height_80;

# define Rte_TypeDef_FD14_Point_Map_Height_81
typedef uint8 FD14_Point_Map_Height_81;

# define Rte_TypeDef_FD14_Point_Map_Height_82
typedef uint8 FD14_Point_Map_Height_82;

# define Rte_TypeDef_FD14_Point_Map_Height_83
typedef uint8 FD14_Point_Map_Height_83;

# define Rte_TypeDef_FD14_Point_Map_Height_84
typedef uint8 FD14_Point_Map_Height_84;

# define Rte_TypeDef_FD14_Point_Map_Height_85
typedef uint8 FD14_Point_Map_Height_85;

# define Rte_TypeDef_FD14_Point_Map_Height_86
typedef uint8 FD14_Point_Map_Height_86;

# define Rte_TypeDef_FD14_Point_Map_Height_87
typedef uint8 FD14_Point_Map_Height_87;

# define Rte_TypeDef_FD14_Point_Map_Height_88
typedef uint8 FD14_Point_Map_Height_88;

# define Rte_TypeDef_FD14_Point_Map_Height_89
typedef uint8 FD14_Point_Map_Height_89;

# define Rte_TypeDef_FD14_Point_Map_Height_9
typedef uint8 FD14_Point_Map_Height_9;

# define Rte_TypeDef_FD14_Point_Map_Height_90
typedef uint8 FD14_Point_Map_Height_90;

# define Rte_TypeDef_FD14_Point_Map_Height_91
typedef uint8 FD14_Point_Map_Height_91;

# define Rte_TypeDef_FD14_Point_Map_Height_92
typedef uint8 FD14_Point_Map_Height_92;

# define Rte_TypeDef_FD14_Point_Map_Height_93
typedef uint8 FD14_Point_Map_Height_93;

# define Rte_TypeDef_FD14_Point_Map_Height_94
typedef uint8 FD14_Point_Map_Height_94;

# define Rte_TypeDef_FD14_Point_Map_Height_95
typedef uint8 FD14_Point_Map_Height_95;

# define Rte_TypeDef_FD14_Point_Map_Reserved_0
typedef uint8 FD14_Point_Map_Reserved_0;

# define Rte_TypeDef_FD14_Point_Map_Reserved_1
typedef uint8 FD14_Point_Map_Reserved_1;

# define Rte_TypeDef_FD14_Point_Map_Reserved_10
typedef uint8 FD14_Point_Map_Reserved_10;

# define Rte_TypeDef_FD14_Point_Map_Reserved_11
typedef uint8 FD14_Point_Map_Reserved_11;

# define Rte_TypeDef_FD14_Point_Map_Reserved_12
typedef uint8 FD14_Point_Map_Reserved_12;

# define Rte_TypeDef_FD14_Point_Map_Reserved_13
typedef uint8 FD14_Point_Map_Reserved_13;

# define Rte_TypeDef_FD14_Point_Map_Reserved_14
typedef uint8 FD14_Point_Map_Reserved_14;

# define Rte_TypeDef_FD14_Point_Map_Reserved_15
typedef uint8 FD14_Point_Map_Reserved_15;

# define Rte_TypeDef_FD14_Point_Map_Reserved_16
typedef uint8 FD14_Point_Map_Reserved_16;

# define Rte_TypeDef_FD14_Point_Map_Reserved_17
typedef uint8 FD14_Point_Map_Reserved_17;

# define Rte_TypeDef_FD14_Point_Map_Reserved_18
typedef uint8 FD14_Point_Map_Reserved_18;

# define Rte_TypeDef_FD14_Point_Map_Reserved_19
typedef uint8 FD14_Point_Map_Reserved_19;

# define Rte_TypeDef_FD14_Point_Map_Reserved_2
typedef uint8 FD14_Point_Map_Reserved_2;

# define Rte_TypeDef_FD14_Point_Map_Reserved_20
typedef uint8 FD14_Point_Map_Reserved_20;

# define Rte_TypeDef_FD14_Point_Map_Reserved_21
typedef uint8 FD14_Point_Map_Reserved_21;

# define Rte_TypeDef_FD14_Point_Map_Reserved_22
typedef uint8 FD14_Point_Map_Reserved_22;

# define Rte_TypeDef_FD14_Point_Map_Reserved_23
typedef uint8 FD14_Point_Map_Reserved_23;

# define Rte_TypeDef_FD14_Point_Map_Reserved_24
typedef uint8 FD14_Point_Map_Reserved_24;

# define Rte_TypeDef_FD14_Point_Map_Reserved_25
typedef uint8 FD14_Point_Map_Reserved_25;

# define Rte_TypeDef_FD14_Point_Map_Reserved_26
typedef uint8 FD14_Point_Map_Reserved_26;

# define Rte_TypeDef_FD14_Point_Map_Reserved_27
typedef uint8 FD14_Point_Map_Reserved_27;

# define Rte_TypeDef_FD14_Point_Map_Reserved_28
typedef uint8 FD14_Point_Map_Reserved_28;

# define Rte_TypeDef_FD14_Point_Map_Reserved_29
typedef uint8 FD14_Point_Map_Reserved_29;

# define Rte_TypeDef_FD14_Point_Map_Reserved_3
typedef uint8 FD14_Point_Map_Reserved_3;

# define Rte_TypeDef_FD14_Point_Map_Reserved_30
typedef uint8 FD14_Point_Map_Reserved_30;

# define Rte_TypeDef_FD14_Point_Map_Reserved_31
typedef uint8 FD14_Point_Map_Reserved_31;

# define Rte_TypeDef_FD14_Point_Map_Reserved_32
typedef uint8 FD14_Point_Map_Reserved_32;

# define Rte_TypeDef_FD14_Point_Map_Reserved_33
typedef uint8 FD14_Point_Map_Reserved_33;

# define Rte_TypeDef_FD14_Point_Map_Reserved_34
typedef uint8 FD14_Point_Map_Reserved_34;

# define Rte_TypeDef_FD14_Point_Map_Reserved_35
typedef uint8 FD14_Point_Map_Reserved_35;

# define Rte_TypeDef_FD14_Point_Map_Reserved_36
typedef uint8 FD14_Point_Map_Reserved_36;

# define Rte_TypeDef_FD14_Point_Map_Reserved_37
typedef uint8 FD14_Point_Map_Reserved_37;

# define Rte_TypeDef_FD14_Point_Map_Reserved_38
typedef uint8 FD14_Point_Map_Reserved_38;

# define Rte_TypeDef_FD14_Point_Map_Reserved_39
typedef uint8 FD14_Point_Map_Reserved_39;

# define Rte_TypeDef_FD14_Point_Map_Reserved_4
typedef uint8 FD14_Point_Map_Reserved_4;

# define Rte_TypeDef_FD14_Point_Map_Reserved_40
typedef uint8 FD14_Point_Map_Reserved_40;

# define Rte_TypeDef_FD14_Point_Map_Reserved_41
typedef uint8 FD14_Point_Map_Reserved_41;

# define Rte_TypeDef_FD14_Point_Map_Reserved_42
typedef uint8 FD14_Point_Map_Reserved_42;

# define Rte_TypeDef_FD14_Point_Map_Reserved_43
typedef uint8 FD14_Point_Map_Reserved_43;

# define Rte_TypeDef_FD14_Point_Map_Reserved_44
typedef uint8 FD14_Point_Map_Reserved_44;

# define Rte_TypeDef_FD14_Point_Map_Reserved_45
typedef uint8 FD14_Point_Map_Reserved_45;

# define Rte_TypeDef_FD14_Point_Map_Reserved_46
typedef uint8 FD14_Point_Map_Reserved_46;

# define Rte_TypeDef_FD14_Point_Map_Reserved_47
typedef uint8 FD14_Point_Map_Reserved_47;

# define Rte_TypeDef_FD14_Point_Map_Reserved_48
typedef uint8 FD14_Point_Map_Reserved_48;

# define Rte_TypeDef_FD14_Point_Map_Reserved_49
typedef uint8 FD14_Point_Map_Reserved_49;

# define Rte_TypeDef_FD14_Point_Map_Reserved_5
typedef uint8 FD14_Point_Map_Reserved_5;

# define Rte_TypeDef_FD14_Point_Map_Reserved_50
typedef uint8 FD14_Point_Map_Reserved_50;

# define Rte_TypeDef_FD14_Point_Map_Reserved_51
typedef uint8 FD14_Point_Map_Reserved_51;

# define Rte_TypeDef_FD14_Point_Map_Reserved_52
typedef uint8 FD14_Point_Map_Reserved_52;

# define Rte_TypeDef_FD14_Point_Map_Reserved_53
typedef uint8 FD14_Point_Map_Reserved_53;

# define Rte_TypeDef_FD14_Point_Map_Reserved_54
typedef uint8 FD14_Point_Map_Reserved_54;

# define Rte_TypeDef_FD14_Point_Map_Reserved_55
typedef uint8 FD14_Point_Map_Reserved_55;

# define Rte_TypeDef_FD14_Point_Map_Reserved_56
typedef uint8 FD14_Point_Map_Reserved_56;

# define Rte_TypeDef_FD14_Point_Map_Reserved_57
typedef uint8 FD14_Point_Map_Reserved_57;

# define Rte_TypeDef_FD14_Point_Map_Reserved_58
typedef uint8 FD14_Point_Map_Reserved_58;

# define Rte_TypeDef_FD14_Point_Map_Reserved_59
typedef uint8 FD14_Point_Map_Reserved_59;

# define Rte_TypeDef_FD14_Point_Map_Reserved_6
typedef uint8 FD14_Point_Map_Reserved_6;

# define Rte_TypeDef_FD14_Point_Map_Reserved_60
typedef uint8 FD14_Point_Map_Reserved_60;

# define Rte_TypeDef_FD14_Point_Map_Reserved_61
typedef uint8 FD14_Point_Map_Reserved_61;

# define Rte_TypeDef_FD14_Point_Map_Reserved_62
typedef uint8 FD14_Point_Map_Reserved_62;

# define Rte_TypeDef_FD14_Point_Map_Reserved_63
typedef uint8 FD14_Point_Map_Reserved_63;

# define Rte_TypeDef_FD14_Point_Map_Reserved_64
typedef uint8 FD14_Point_Map_Reserved_64;

# define Rte_TypeDef_FD14_Point_Map_Reserved_65
typedef uint8 FD14_Point_Map_Reserved_65;

# define Rte_TypeDef_FD14_Point_Map_Reserved_66
typedef uint8 FD14_Point_Map_Reserved_66;

# define Rte_TypeDef_FD14_Point_Map_Reserved_67
typedef uint8 FD14_Point_Map_Reserved_67;

# define Rte_TypeDef_FD14_Point_Map_Reserved_68
typedef uint8 FD14_Point_Map_Reserved_68;

# define Rte_TypeDef_FD14_Point_Map_Reserved_69
typedef uint8 FD14_Point_Map_Reserved_69;

# define Rte_TypeDef_FD14_Point_Map_Reserved_7
typedef uint8 FD14_Point_Map_Reserved_7;

# define Rte_TypeDef_FD14_Point_Map_Reserved_70
typedef uint8 FD14_Point_Map_Reserved_70;

# define Rte_TypeDef_FD14_Point_Map_Reserved_71
typedef uint8 FD14_Point_Map_Reserved_71;

# define Rte_TypeDef_FD14_Point_Map_Reserved_72
typedef uint8 FD14_Point_Map_Reserved_72;

# define Rte_TypeDef_FD14_Point_Map_Reserved_73
typedef uint8 FD14_Point_Map_Reserved_73;

# define Rte_TypeDef_FD14_Point_Map_Reserved_74
typedef uint8 FD14_Point_Map_Reserved_74;

# define Rte_TypeDef_FD14_Point_Map_Reserved_75
typedef uint8 FD14_Point_Map_Reserved_75;

# define Rte_TypeDef_FD14_Point_Map_Reserved_76
typedef uint8 FD14_Point_Map_Reserved_76;

# define Rte_TypeDef_FD14_Point_Map_Reserved_77
typedef uint8 FD14_Point_Map_Reserved_77;

# define Rte_TypeDef_FD14_Point_Map_Reserved_78
typedef uint8 FD14_Point_Map_Reserved_78;

# define Rte_TypeDef_FD14_Point_Map_Reserved_79
typedef uint8 FD14_Point_Map_Reserved_79;

# define Rte_TypeDef_FD14_Point_Map_Reserved_8
typedef uint8 FD14_Point_Map_Reserved_8;

# define Rte_TypeDef_FD14_Point_Map_Reserved_80
typedef uint8 FD14_Point_Map_Reserved_80;

# define Rte_TypeDef_FD14_Point_Map_Reserved_81
typedef uint8 FD14_Point_Map_Reserved_81;

# define Rte_TypeDef_FD14_Point_Map_Reserved_82
typedef uint8 FD14_Point_Map_Reserved_82;

# define Rte_TypeDef_FD14_Point_Map_Reserved_83
typedef uint8 FD14_Point_Map_Reserved_83;

# define Rte_TypeDef_FD14_Point_Map_Reserved_84
typedef uint8 FD14_Point_Map_Reserved_84;

# define Rte_TypeDef_FD14_Point_Map_Reserved_85
typedef uint8 FD14_Point_Map_Reserved_85;

# define Rte_TypeDef_FD14_Point_Map_Reserved_86
typedef uint8 FD14_Point_Map_Reserved_86;

# define Rte_TypeDef_FD14_Point_Map_Reserved_87
typedef uint8 FD14_Point_Map_Reserved_87;

# define Rte_TypeDef_FD14_Point_Map_Reserved_88
typedef uint8 FD14_Point_Map_Reserved_88;

# define Rte_TypeDef_FD14_Point_Map_Reserved_89
typedef uint8 FD14_Point_Map_Reserved_89;

# define Rte_TypeDef_FD14_Point_Map_Reserved_9
typedef uint8 FD14_Point_Map_Reserved_9;

# define Rte_TypeDef_FD14_Point_Map_Reserved_90
typedef uint8 FD14_Point_Map_Reserved_90;

# define Rte_TypeDef_FD14_Point_Map_Reserved_91
typedef uint8 FD14_Point_Map_Reserved_91;

# define Rte_TypeDef_FD14_Point_Map_Reserved_92
typedef uint8 FD14_Point_Map_Reserved_92;

# define Rte_TypeDef_FD14_Point_Map_Reserved_93
typedef uint8 FD14_Point_Map_Reserved_93;

# define Rte_TypeDef_FD14_Point_Map_Reserved_94
typedef uint8 FD14_Point_Map_Reserved_94;

# define Rte_TypeDef_FD14_Point_Map_Reserved_95
typedef uint8 FD14_Point_Map_Reserved_95;

# define Rte_TypeDef_FD14_Point_Map_X_0
typedef sint16 FD14_Point_Map_X_0;

# define Rte_TypeDef_FD14_Point_Map_X_1
typedef sint16 FD14_Point_Map_X_1;

# define Rte_TypeDef_FD14_Point_Map_X_10
typedef sint16 FD14_Point_Map_X_10;

# define Rte_TypeDef_FD14_Point_Map_X_11
typedef sint16 FD14_Point_Map_X_11;

# define Rte_TypeDef_FD14_Point_Map_X_12
typedef sint16 FD14_Point_Map_X_12;

# define Rte_TypeDef_FD14_Point_Map_X_13
typedef sint16 FD14_Point_Map_X_13;

# define Rte_TypeDef_FD14_Point_Map_X_14
typedef sint16 FD14_Point_Map_X_14;

# define Rte_TypeDef_FD14_Point_Map_X_15
typedef sint16 FD14_Point_Map_X_15;

# define Rte_TypeDef_FD14_Point_Map_X_16
typedef sint16 FD14_Point_Map_X_16;

# define Rte_TypeDef_FD14_Point_Map_X_17
typedef sint16 FD14_Point_Map_X_17;

# define Rte_TypeDef_FD14_Point_Map_X_18
typedef sint16 FD14_Point_Map_X_18;

# define Rte_TypeDef_FD14_Point_Map_X_19
typedef sint16 FD14_Point_Map_X_19;

# define Rte_TypeDef_FD14_Point_Map_X_2
typedef sint16 FD14_Point_Map_X_2;

# define Rte_TypeDef_FD14_Point_Map_X_20
typedef sint16 FD14_Point_Map_X_20;

# define Rte_TypeDef_FD14_Point_Map_X_21
typedef sint16 FD14_Point_Map_X_21;

# define Rte_TypeDef_FD14_Point_Map_X_22
typedef sint16 FD14_Point_Map_X_22;

# define Rte_TypeDef_FD14_Point_Map_X_23
typedef sint16 FD14_Point_Map_X_23;

# define Rte_TypeDef_FD14_Point_Map_X_24
typedef sint16 FD14_Point_Map_X_24;

# define Rte_TypeDef_FD14_Point_Map_X_25
typedef sint16 FD14_Point_Map_X_25;

# define Rte_TypeDef_FD14_Point_Map_X_26
typedef sint16 FD14_Point_Map_X_26;

# define Rte_TypeDef_FD14_Point_Map_X_27
typedef sint16 FD14_Point_Map_X_27;

# define Rte_TypeDef_FD14_Point_Map_X_28
typedef sint16 FD14_Point_Map_X_28;

# define Rte_TypeDef_FD14_Point_Map_X_29
typedef sint16 FD14_Point_Map_X_29;

# define Rte_TypeDef_FD14_Point_Map_X_3
typedef sint16 FD14_Point_Map_X_3;

# define Rte_TypeDef_FD14_Point_Map_X_30
typedef sint16 FD14_Point_Map_X_30;

# define Rte_TypeDef_FD14_Point_Map_X_31
typedef sint16 FD14_Point_Map_X_31;

# define Rte_TypeDef_FD14_Point_Map_X_32
typedef sint16 FD14_Point_Map_X_32;

# define Rte_TypeDef_FD14_Point_Map_X_33
typedef sint16 FD14_Point_Map_X_33;

# define Rte_TypeDef_FD14_Point_Map_X_34
typedef sint16 FD14_Point_Map_X_34;

# define Rte_TypeDef_FD14_Point_Map_X_35
typedef sint16 FD14_Point_Map_X_35;

# define Rte_TypeDef_FD14_Point_Map_X_36
typedef sint16 FD14_Point_Map_X_36;

# define Rte_TypeDef_FD14_Point_Map_X_37
typedef sint16 FD14_Point_Map_X_37;

# define Rte_TypeDef_FD14_Point_Map_X_38
typedef sint16 FD14_Point_Map_X_38;

# define Rte_TypeDef_FD14_Point_Map_X_39
typedef sint16 FD14_Point_Map_X_39;

# define Rte_TypeDef_FD14_Point_Map_X_4
typedef sint16 FD14_Point_Map_X_4;

# define Rte_TypeDef_FD14_Point_Map_X_40
typedef sint16 FD14_Point_Map_X_40;

# define Rte_TypeDef_FD14_Point_Map_X_41
typedef sint16 FD14_Point_Map_X_41;

# define Rte_TypeDef_FD14_Point_Map_X_42
typedef sint16 FD14_Point_Map_X_42;

# define Rte_TypeDef_FD14_Point_Map_X_43
typedef sint16 FD14_Point_Map_X_43;

# define Rte_TypeDef_FD14_Point_Map_X_44
typedef sint16 FD14_Point_Map_X_44;

# define Rte_TypeDef_FD14_Point_Map_X_45
typedef sint16 FD14_Point_Map_X_45;

# define Rte_TypeDef_FD14_Point_Map_X_46
typedef sint16 FD14_Point_Map_X_46;

# define Rte_TypeDef_FD14_Point_Map_X_47
typedef sint16 FD14_Point_Map_X_47;

# define Rte_TypeDef_FD14_Point_Map_X_48
typedef sint16 FD14_Point_Map_X_48;

# define Rte_TypeDef_FD14_Point_Map_X_49
typedef sint16 FD14_Point_Map_X_49;

# define Rte_TypeDef_FD14_Point_Map_X_5
typedef sint16 FD14_Point_Map_X_5;

# define Rte_TypeDef_FD14_Point_Map_X_50
typedef sint16 FD14_Point_Map_X_50;

# define Rte_TypeDef_FD14_Point_Map_X_51
typedef sint16 FD14_Point_Map_X_51;

# define Rte_TypeDef_FD14_Point_Map_X_52
typedef sint16 FD14_Point_Map_X_52;

# define Rte_TypeDef_FD14_Point_Map_X_53
typedef sint16 FD14_Point_Map_X_53;

# define Rte_TypeDef_FD14_Point_Map_X_54
typedef sint16 FD14_Point_Map_X_54;

# define Rte_TypeDef_FD14_Point_Map_X_55
typedef sint16 FD14_Point_Map_X_55;

# define Rte_TypeDef_FD14_Point_Map_X_56
typedef sint16 FD14_Point_Map_X_56;

# define Rte_TypeDef_FD14_Point_Map_X_57
typedef sint16 FD14_Point_Map_X_57;

# define Rte_TypeDef_FD14_Point_Map_X_58
typedef sint16 FD14_Point_Map_X_58;

# define Rte_TypeDef_FD14_Point_Map_X_59
typedef sint16 FD14_Point_Map_X_59;

# define Rte_TypeDef_FD14_Point_Map_X_6
typedef sint16 FD14_Point_Map_X_6;

# define Rte_TypeDef_FD14_Point_Map_X_60
typedef sint16 FD14_Point_Map_X_60;

# define Rte_TypeDef_FD14_Point_Map_X_61
typedef sint16 FD14_Point_Map_X_61;

# define Rte_TypeDef_FD14_Point_Map_X_62
typedef sint16 FD14_Point_Map_X_62;

# define Rte_TypeDef_FD14_Point_Map_X_63
typedef sint16 FD14_Point_Map_X_63;

# define Rte_TypeDef_FD14_Point_Map_X_64
typedef sint16 FD14_Point_Map_X_64;

# define Rte_TypeDef_FD14_Point_Map_X_65
typedef sint16 FD14_Point_Map_X_65;

# define Rte_TypeDef_FD14_Point_Map_X_66
typedef sint16 FD14_Point_Map_X_66;

# define Rte_TypeDef_FD14_Point_Map_X_67
typedef sint16 FD14_Point_Map_X_67;

# define Rte_TypeDef_FD14_Point_Map_X_68
typedef sint16 FD14_Point_Map_X_68;

# define Rte_TypeDef_FD14_Point_Map_X_69
typedef sint16 FD14_Point_Map_X_69;

# define Rte_TypeDef_FD14_Point_Map_X_7
typedef sint16 FD14_Point_Map_X_7;

# define Rte_TypeDef_FD14_Point_Map_X_70
typedef sint16 FD14_Point_Map_X_70;

# define Rte_TypeDef_FD14_Point_Map_X_71
typedef sint16 FD14_Point_Map_X_71;

# define Rte_TypeDef_FD14_Point_Map_X_72
typedef sint16 FD14_Point_Map_X_72;

# define Rte_TypeDef_FD14_Point_Map_X_73
typedef sint16 FD14_Point_Map_X_73;

# define Rte_TypeDef_FD14_Point_Map_X_74
typedef sint16 FD14_Point_Map_X_74;

# define Rte_TypeDef_FD14_Point_Map_X_75
typedef sint16 FD14_Point_Map_X_75;

# define Rte_TypeDef_FD14_Point_Map_X_76
typedef sint16 FD14_Point_Map_X_76;

# define Rte_TypeDef_FD14_Point_Map_X_77
typedef sint16 FD14_Point_Map_X_77;

# define Rte_TypeDef_FD14_Point_Map_X_78
typedef sint16 FD14_Point_Map_X_78;

# define Rte_TypeDef_FD14_Point_Map_X_79
typedef sint16 FD14_Point_Map_X_79;

# define Rte_TypeDef_FD14_Point_Map_X_8
typedef sint16 FD14_Point_Map_X_8;

# define Rte_TypeDef_FD14_Point_Map_X_80
typedef sint16 FD14_Point_Map_X_80;

# define Rte_TypeDef_FD14_Point_Map_X_81
typedef sint16 FD14_Point_Map_X_81;

# define Rte_TypeDef_FD14_Point_Map_X_82
typedef sint16 FD14_Point_Map_X_82;

# define Rte_TypeDef_FD14_Point_Map_X_83
typedef sint16 FD14_Point_Map_X_83;

# define Rte_TypeDef_FD14_Point_Map_X_84
typedef sint16 FD14_Point_Map_X_84;

# define Rte_TypeDef_FD14_Point_Map_X_85
typedef sint16 FD14_Point_Map_X_85;

# define Rte_TypeDef_FD14_Point_Map_X_86
typedef sint16 FD14_Point_Map_X_86;

# define Rte_TypeDef_FD14_Point_Map_X_87
typedef sint16 FD14_Point_Map_X_87;

# define Rte_TypeDef_FD14_Point_Map_X_88
typedef sint16 FD14_Point_Map_X_88;

# define Rte_TypeDef_FD14_Point_Map_X_89
typedef sint16 FD14_Point_Map_X_89;

# define Rte_TypeDef_FD14_Point_Map_X_9
typedef sint16 FD14_Point_Map_X_9;

# define Rte_TypeDef_FD14_Point_Map_X_90
typedef sint16 FD14_Point_Map_X_90;

# define Rte_TypeDef_FD14_Point_Map_X_91
typedef sint16 FD14_Point_Map_X_91;

# define Rte_TypeDef_FD14_Point_Map_X_92
typedef sint16 FD14_Point_Map_X_92;

# define Rte_TypeDef_FD14_Point_Map_X_93
typedef sint16 FD14_Point_Map_X_93;

# define Rte_TypeDef_FD14_Point_Map_X_94
typedef sint16 FD14_Point_Map_X_94;

# define Rte_TypeDef_FD14_Point_Map_X_95
typedef sint16 FD14_Point_Map_X_95;

# define Rte_TypeDef_FD14_Point_Map_Y_0
typedef sint16 FD14_Point_Map_Y_0;

# define Rte_TypeDef_FD14_Point_Map_Y_1
typedef sint16 FD14_Point_Map_Y_1;

# define Rte_TypeDef_FD14_Point_Map_Y_10
typedef sint16 FD14_Point_Map_Y_10;

# define Rte_TypeDef_FD14_Point_Map_Y_11
typedef sint16 FD14_Point_Map_Y_11;

# define Rte_TypeDef_FD14_Point_Map_Y_12
typedef sint16 FD14_Point_Map_Y_12;

# define Rte_TypeDef_FD14_Point_Map_Y_13
typedef sint16 FD14_Point_Map_Y_13;

# define Rte_TypeDef_FD14_Point_Map_Y_14
typedef sint16 FD14_Point_Map_Y_14;

# define Rte_TypeDef_FD14_Point_Map_Y_15
typedef sint16 FD14_Point_Map_Y_15;

# define Rte_TypeDef_FD14_Point_Map_Y_16
typedef sint16 FD14_Point_Map_Y_16;

# define Rte_TypeDef_FD14_Point_Map_Y_17
typedef sint16 FD14_Point_Map_Y_17;

# define Rte_TypeDef_FD14_Point_Map_Y_18
typedef sint16 FD14_Point_Map_Y_18;

# define Rte_TypeDef_FD14_Point_Map_Y_19
typedef sint16 FD14_Point_Map_Y_19;

# define Rte_TypeDef_FD14_Point_Map_Y_2
typedef sint16 FD14_Point_Map_Y_2;

# define Rte_TypeDef_FD14_Point_Map_Y_20
typedef sint16 FD14_Point_Map_Y_20;

# define Rte_TypeDef_FD14_Point_Map_Y_21
typedef sint16 FD14_Point_Map_Y_21;

# define Rte_TypeDef_FD14_Point_Map_Y_22
typedef sint16 FD14_Point_Map_Y_22;

# define Rte_TypeDef_FD14_Point_Map_Y_23
typedef sint16 FD14_Point_Map_Y_23;

# define Rte_TypeDef_FD14_Point_Map_Y_24
typedef sint16 FD14_Point_Map_Y_24;

# define Rte_TypeDef_FD14_Point_Map_Y_25
typedef sint16 FD14_Point_Map_Y_25;

# define Rte_TypeDef_FD14_Point_Map_Y_26
typedef sint16 FD14_Point_Map_Y_26;

# define Rte_TypeDef_FD14_Point_Map_Y_27
typedef sint16 FD14_Point_Map_Y_27;

# define Rte_TypeDef_FD14_Point_Map_Y_28
typedef sint16 FD14_Point_Map_Y_28;

# define Rte_TypeDef_FD14_Point_Map_Y_29
typedef sint16 FD14_Point_Map_Y_29;

# define Rte_TypeDef_FD14_Point_Map_Y_3
typedef sint16 FD14_Point_Map_Y_3;

# define Rte_TypeDef_FD14_Point_Map_Y_30
typedef sint16 FD14_Point_Map_Y_30;

# define Rte_TypeDef_FD14_Point_Map_Y_31
typedef sint16 FD14_Point_Map_Y_31;

# define Rte_TypeDef_FD14_Point_Map_Y_32
typedef sint16 FD14_Point_Map_Y_32;

# define Rte_TypeDef_FD14_Point_Map_Y_33
typedef sint16 FD14_Point_Map_Y_33;

# define Rte_TypeDef_FD14_Point_Map_Y_34
typedef sint16 FD14_Point_Map_Y_34;

# define Rte_TypeDef_FD14_Point_Map_Y_35
typedef sint16 FD14_Point_Map_Y_35;

# define Rte_TypeDef_FD14_Point_Map_Y_36
typedef sint16 FD14_Point_Map_Y_36;

# define Rte_TypeDef_FD14_Point_Map_Y_37
typedef sint16 FD14_Point_Map_Y_37;

# define Rte_TypeDef_FD14_Point_Map_Y_38
typedef sint16 FD14_Point_Map_Y_38;

# define Rte_TypeDef_FD14_Point_Map_Y_39
typedef sint16 FD14_Point_Map_Y_39;

# define Rte_TypeDef_FD14_Point_Map_Y_4
typedef sint16 FD14_Point_Map_Y_4;

# define Rte_TypeDef_FD14_Point_Map_Y_40
typedef sint16 FD14_Point_Map_Y_40;

# define Rte_TypeDef_FD14_Point_Map_Y_41
typedef sint16 FD14_Point_Map_Y_41;

# define Rte_TypeDef_FD14_Point_Map_Y_42
typedef sint16 FD14_Point_Map_Y_42;

# define Rte_TypeDef_FD14_Point_Map_Y_43
typedef sint16 FD14_Point_Map_Y_43;

# define Rte_TypeDef_FD14_Point_Map_Y_44
typedef sint16 FD14_Point_Map_Y_44;

# define Rte_TypeDef_FD14_Point_Map_Y_45
typedef sint16 FD14_Point_Map_Y_45;

# define Rte_TypeDef_FD14_Point_Map_Y_46
typedef sint16 FD14_Point_Map_Y_46;

# define Rte_TypeDef_FD14_Point_Map_Y_47
typedef sint16 FD14_Point_Map_Y_47;

# define Rte_TypeDef_FD14_Point_Map_Y_48
typedef sint16 FD14_Point_Map_Y_48;

# define Rte_TypeDef_FD14_Point_Map_Y_49
typedef sint16 FD14_Point_Map_Y_49;

# define Rte_TypeDef_FD14_Point_Map_Y_5
typedef sint16 FD14_Point_Map_Y_5;

# define Rte_TypeDef_FD14_Point_Map_Y_50
typedef sint16 FD14_Point_Map_Y_50;

# define Rte_TypeDef_FD14_Point_Map_Y_51
typedef sint16 FD14_Point_Map_Y_51;

# define Rte_TypeDef_FD14_Point_Map_Y_52
typedef sint16 FD14_Point_Map_Y_52;

# define Rte_TypeDef_FD14_Point_Map_Y_53
typedef sint16 FD14_Point_Map_Y_53;

# define Rte_TypeDef_FD14_Point_Map_Y_54
typedef sint16 FD14_Point_Map_Y_54;

# define Rte_TypeDef_FD14_Point_Map_Y_55
typedef sint16 FD14_Point_Map_Y_55;

# define Rte_TypeDef_FD14_Point_Map_Y_56
typedef sint16 FD14_Point_Map_Y_56;

# define Rte_TypeDef_FD14_Point_Map_Y_57
typedef sint16 FD14_Point_Map_Y_57;

# define Rte_TypeDef_FD14_Point_Map_Y_58
typedef sint16 FD14_Point_Map_Y_58;

# define Rte_TypeDef_FD14_Point_Map_Y_59
typedef sint16 FD14_Point_Map_Y_59;

# define Rte_TypeDef_FD14_Point_Map_Y_6
typedef sint16 FD14_Point_Map_Y_6;

# define Rte_TypeDef_FD14_Point_Map_Y_60
typedef sint16 FD14_Point_Map_Y_60;

# define Rte_TypeDef_FD14_Point_Map_Y_61
typedef sint16 FD14_Point_Map_Y_61;

# define Rte_TypeDef_FD14_Point_Map_Y_62
typedef sint16 FD14_Point_Map_Y_62;

# define Rte_TypeDef_FD14_Point_Map_Y_63
typedef sint16 FD14_Point_Map_Y_63;

# define Rte_TypeDef_FD14_Point_Map_Y_64
typedef sint16 FD14_Point_Map_Y_64;

# define Rte_TypeDef_FD14_Point_Map_Y_65
typedef sint16 FD14_Point_Map_Y_65;

# define Rte_TypeDef_FD14_Point_Map_Y_66
typedef sint16 FD14_Point_Map_Y_66;

# define Rte_TypeDef_FD14_Point_Map_Y_67
typedef sint16 FD14_Point_Map_Y_67;

# define Rte_TypeDef_FD14_Point_Map_Y_68
typedef sint16 FD14_Point_Map_Y_68;

# define Rte_TypeDef_FD14_Point_Map_Y_69
typedef sint16 FD14_Point_Map_Y_69;

# define Rte_TypeDef_FD14_Point_Map_Y_7
typedef sint16 FD14_Point_Map_Y_7;

# define Rte_TypeDef_FD14_Point_Map_Y_70
typedef sint16 FD14_Point_Map_Y_70;

# define Rte_TypeDef_FD14_Point_Map_Y_71
typedef sint16 FD14_Point_Map_Y_71;

# define Rte_TypeDef_FD14_Point_Map_Y_72
typedef sint16 FD14_Point_Map_Y_72;

# define Rte_TypeDef_FD14_Point_Map_Y_73
typedef sint16 FD14_Point_Map_Y_73;

# define Rte_TypeDef_FD14_Point_Map_Y_74
typedef sint16 FD14_Point_Map_Y_74;

# define Rte_TypeDef_FD14_Point_Map_Y_75
typedef sint16 FD14_Point_Map_Y_75;

# define Rte_TypeDef_FD14_Point_Map_Y_76
typedef sint16 FD14_Point_Map_Y_76;

# define Rte_TypeDef_FD14_Point_Map_Y_77
typedef sint16 FD14_Point_Map_Y_77;

# define Rte_TypeDef_FD14_Point_Map_Y_78
typedef sint16 FD14_Point_Map_Y_78;

# define Rte_TypeDef_FD14_Point_Map_Y_79
typedef sint16 FD14_Point_Map_Y_79;

# define Rte_TypeDef_FD14_Point_Map_Y_8
typedef sint16 FD14_Point_Map_Y_8;

# define Rte_TypeDef_FD14_Point_Map_Y_80
typedef sint16 FD14_Point_Map_Y_80;

# define Rte_TypeDef_FD14_Point_Map_Y_81
typedef sint16 FD14_Point_Map_Y_81;

# define Rte_TypeDef_FD14_Point_Map_Y_82
typedef sint16 FD14_Point_Map_Y_82;

# define Rte_TypeDef_FD14_Point_Map_Y_83
typedef sint16 FD14_Point_Map_Y_83;

# define Rte_TypeDef_FD14_Point_Map_Y_84
typedef sint16 FD14_Point_Map_Y_84;

# define Rte_TypeDef_FD14_Point_Map_Y_85
typedef sint16 FD14_Point_Map_Y_85;

# define Rte_TypeDef_FD14_Point_Map_Y_86
typedef sint16 FD14_Point_Map_Y_86;

# define Rte_TypeDef_FD14_Point_Map_Y_87
typedef sint16 FD14_Point_Map_Y_87;

# define Rte_TypeDef_FD14_Point_Map_Y_88
typedef sint16 FD14_Point_Map_Y_88;

# define Rte_TypeDef_FD14_Point_Map_Y_89
typedef sint16 FD14_Point_Map_Y_89;

# define Rte_TypeDef_FD14_Point_Map_Y_9
typedef sint16 FD14_Point_Map_Y_9;

# define Rte_TypeDef_FD14_Point_Map_Y_90
typedef sint16 FD14_Point_Map_Y_90;

# define Rte_TypeDef_FD14_Point_Map_Y_91
typedef sint16 FD14_Point_Map_Y_91;

# define Rte_TypeDef_FD14_Point_Map_Y_92
typedef sint16 FD14_Point_Map_Y_92;

# define Rte_TypeDef_FD14_Point_Map_Y_93
typedef sint16 FD14_Point_Map_Y_93;

# define Rte_TypeDef_FD14_Point_Map_Y_94
typedef sint16 FD14_Point_Map_Y_94;

# define Rte_TypeDef_FD14_Point_Map_Y_95
typedef sint16 FD14_Point_Map_Y_95;

# define Rte_TypeDef_FD14_Presentinfo
typedef uint8 FD14_Presentinfo;

# define Rte_TypeDef_FD14_REAR_CROSS_BTN_PRESSED_b
typedef boolean FD14_REAR_CROSS_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_REAR_TOP_BTN_PRESSED_b
typedef boolean FD14_REAR_TOP_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_RIL_CommUnknown
typedef boolean FD14_RIL_CommUnknown;

# define Rte_TypeDef_FD14_RIL_MinDistance
typedef uint16 FD14_RIL_MinDistance;

# define Rte_TypeDef_FD14_RIL_comm_Fault
typedef boolean FD14_RIL_comm_Fault;

# define Rte_TypeDef_FD14_RIL_hardware_Fault
typedef boolean FD14_RIL_hardware_Fault;

# define Rte_TypeDef_FD14_RIL_overTemp_Fault
typedef boolean FD14_RIL_overTemp_Fault;

# define Rte_TypeDef_FD14_RIR_CommUnknown
typedef boolean FD14_RIR_CommUnknown;

# define Rte_TypeDef_FD14_RIR_MinDistance
typedef uint16 FD14_RIR_MinDistance;

# define Rte_TypeDef_FD14_RIR_comm_Fault
typedef boolean FD14_RIR_comm_Fault;

# define Rte_TypeDef_FD14_RIR_hardware_Fault
typedef boolean FD14_RIR_hardware_Fault;

# define Rte_TypeDef_FD14_RIR_overTemp_Fault
typedef boolean FD14_RIR_overTemp_Fault;

# define Rte_TypeDef_FD14_ROL_CommUnknown
typedef boolean FD14_ROL_CommUnknown;

# define Rte_TypeDef_FD14_ROL_MinDistance
typedef uint16 FD14_ROL_MinDistance;

# define Rte_TypeDef_FD14_ROL_comm_Fault
typedef boolean FD14_ROL_comm_Fault;

# define Rte_TypeDef_FD14_ROL_hardware_Fault
typedef boolean FD14_ROL_hardware_Fault;

# define Rte_TypeDef_FD14_ROL_overTemp_Fault
typedef boolean FD14_ROL_overTemp_Fault;

# define Rte_TypeDef_FD14_ROR_CommUnknown
typedef boolean FD14_ROR_CommUnknown;

# define Rte_TypeDef_FD14_ROR_MinDistance
typedef uint16 FD14_ROR_MinDistance;

# define Rte_TypeDef_FD14_ROR_comm_Fault
typedef boolean FD14_ROR_comm_Fault;

# define Rte_TypeDef_FD14_ROR_hardware_Fault
typedef boolean FD14_ROR_hardware_Fault;

# define Rte_TypeDef_FD14_ROR_overTemp_Fault
typedef boolean FD14_ROR_overTemp_Fault;

# define Rte_TypeDef_FD14_RSL_CommUnknown
typedef boolean FD14_RSL_CommUnknown;

# define Rte_TypeDef_FD14_RSL_MinDistance
typedef uint16 FD14_RSL_MinDistance;

# define Rte_TypeDef_FD14_RSL_comm_Fault
typedef boolean FD14_RSL_comm_Fault;

# define Rte_TypeDef_FD14_RSL_hardware_Fault
typedef boolean FD14_RSL_hardware_Fault;

# define Rte_TypeDef_FD14_RSL_overTemp_Fault
typedef boolean FD14_RSL_overTemp_Fault;

# define Rte_TypeDef_FD14_RSR_CommUnknown
typedef boolean FD14_RSR_CommUnknown;

# define Rte_TypeDef_FD14_RSR_MinDistance
typedef uint16 FD14_RSR_MinDistance;

# define Rte_TypeDef_FD14_RSR_comm_Fault
typedef boolean FD14_RSR_comm_Fault;

# define Rte_TypeDef_FD14_RSR_hardware_Fault
typedef boolean FD14_RSR_hardware_Fault;

# define Rte_TypeDef_FD14_RSR_overTemp_Fault
typedef boolean FD14_RSR_overTemp_Fault;

# define Rte_TypeDef_FD14_RVCONLY_BTN_PRESSED_b
typedef boolean FD14_RVCONLY_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_RearCrossButtonNoSelect_b
typedef boolean FD14_RearCrossButtonNoSelect_b;

# define Rte_TypeDef_FD14_RearCrossButtonSelect_b
typedef boolean FD14_RearCrossButtonSelect_b;

# define Rte_TypeDef_FD14_RearViewDynamics_b
typedef boolean FD14_RearViewDynamics_b;

# define Rte_TypeDef_FD14_RecognitionInfo
typedef boolean FD14_RecognitionInfo;

# define Rte_TypeDef_FD14_Reserved08_b
typedef boolean FD14_Reserved08_b;

# define Rte_TypeDef_FD14_Reserved09_b
typedef boolean FD14_Reserved09_b;

# define Rte_TypeDef_FD14_Reserved0_b
typedef boolean FD14_Reserved0_b;

# define Rte_TypeDef_FD14_Reserved10_b
typedef boolean FD14_Reserved10_b;

# define Rte_TypeDef_FD14_Reserved11_b
typedef boolean FD14_Reserved11_b;

# define Rte_TypeDef_FD14_Reserved12_b
typedef boolean FD14_Reserved12_b;

# define Rte_TypeDef_FD14_Reserved13_b
typedef boolean FD14_Reserved13_b;

# define Rte_TypeDef_FD14_Reserved1_b
typedef boolean FD14_Reserved1_b;

# define Rte_TypeDef_FD14_Reserved2_b
typedef boolean FD14_Reserved2_b;

# define Rte_TypeDef_FD14_Reserved3_b
typedef boolean FD14_Reserved3_b;

# define Rte_TypeDef_FD14_ReservedSignal1
typedef float32 FD14_ReservedSignal1;

# define Rte_TypeDef_FD14_ReservedSignal2
typedef float32 FD14_ReservedSignal2;

# define Rte_TypeDef_FD14_ReservedTRSCSig1
typedef float32 FD14_ReservedTRSCSig1;

# define Rte_TypeDef_FD14_ReservedTRSCSig2
typedef float32 FD14_ReservedTRSCSig2;

# define Rte_TypeDef_FD14_Reserved_for_functional_safety
typedef uint16 FD14_Reserved_for_functional_safety;

# define Rte_TypeDef_FD14_RightCam_NA_b
typedef boolean FD14_RightCam_NA_b;

# define Rte_TypeDef_FD14_RightDoorFrontClose_Icon_b
typedef boolean FD14_RightDoorFrontClose_Icon_b;

# define Rte_TypeDef_FD14_RightDoorFrontOpen_Icon_b
typedef boolean FD14_RightDoorFrontOpen_Icon_b;

# define Rte_TypeDef_FD14_RightDoorRearClose_Icon_b
typedef boolean FD14_RightDoorRearClose_Icon_b;

# define Rte_TypeDef_FD14_RightDoorRearOpen_Icon_b
typedef boolean FD14_RightDoorRearOpen_Icon_b;

# define Rte_TypeDef_FD14_Roll_f32_Current_Rear
typedef float32 FD14_Roll_f32_Current_Rear;

# define Rte_TypeDef_FD14_Roll_f32_Current_Right
typedef float32 FD14_Roll_f32_Current_Right;

# define Rte_TypeDef_FD14_Roll_f32_EOL_Front
typedef float32 FD14_Roll_f32_EOL_Front;

# define Rte_TypeDef_FD14_Roll_f32_EOL_Left
typedef float32 FD14_Roll_f32_EOL_Left;

# define Rte_TypeDef_FD14_Roll_f32_EOL_Rear
typedef float32 FD14_Roll_f32_EOL_Rear;

# define Rte_TypeDef_FD14_Roll_f32_EOL_Right
typedef float32 FD14_Roll_f32_EOL_Right;

# define Rte_TypeDef_FD14_Roll_f32_OC_Front
typedef float32 FD14_Roll_f32_OC_Front;

# define Rte_TypeDef_FD14_Roll_f32_OC_Left
typedef float32 FD14_Roll_f32_OC_Left;

# define Rte_TypeDef_FD14_Roll_f32_OC_Rear
typedef float32 FD14_Roll_f32_OC_Rear;

# define Rte_TypeDef_FD14_Roll_f32_OC_Right
typedef float32 FD14_Roll_f32_OC_Right;

# define Rte_TypeDef_FD14_Roll_f32_SC_Front
typedef float32 FD14_Roll_f32_SC_Front;

# define Rte_TypeDef_FD14_Roll_f32_SC_Left
typedef float32 FD14_Roll_f32_SC_Left;

# define Rte_TypeDef_FD14_Roll_f32_SC_Rear
typedef float32 FD14_Roll_f32_SC_Rear;

# define Rte_TypeDef_FD14_Roll_f32_SC_Right
typedef float32 FD14_Roll_f32_SC_Right;

# define Rte_TypeDef_FD14_STM_v_TRGAUTO_BTN_PRESSED_b
typedef boolean FD14_STM_v_TRGAUTO_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_STM_v_TRGLEFT_BTN_PRESSED_b
typedef boolean FD14_STM_v_TRGLEFT_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_STM_v_TRGRIGHT_BTN_PRESSED_b
typedef boolean FD14_STM_v_TRGRIGHT_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_SVC_Delay_Feature_b
typedef boolean FD14_SVC_Delay_Feature_b;

# define Rte_TypeDef_FD14_SVC_Dynamic_Gridlines_Feature_b
typedef boolean FD14_SVC_Dynamic_Gridlines_Feature_b;

# define Rte_TypeDef_FD14_SVC_FFCV_Gridlines_Feature_b
typedef boolean FD14_SVC_FFCV_Gridlines_Feature_b;

# define Rte_TypeDef_FD14_SVC_Static_Gridlines_Feature_b
typedef boolean FD14_SVC_Static_Gridlines_Feature_b;

# define Rte_TypeDef_FD14_Segment_1_Confidence
typedef uint8 FD14_Segment_1_Confidence;

# define Rte_TypeDef_FD14_Segment_1_ID
typedef uint8 FD14_Segment_1_ID;

# define Rte_TypeDef_FD14_Segment_1_X1
typedef uint16 FD14_Segment_1_X1;

# define Rte_TypeDef_FD14_Segment_1_X2
typedef uint16 FD14_Segment_1_X2;

# define Rte_TypeDef_FD14_Segment_1_Y1
typedef uint16 FD14_Segment_1_Y1;

# define Rte_TypeDef_FD14_Segment_1_Y2
typedef uint16 FD14_Segment_1_Y2;

# define Rte_TypeDef_FD14_Segment_2_Confidence
typedef uint8 FD14_Segment_2_Confidence;

# define Rte_TypeDef_FD14_Segment_2_ID
typedef uint8 FD14_Segment_2_ID;

# define Rte_TypeDef_FD14_Segment_2_X1
typedef uint16 FD14_Segment_2_X1;

# define Rte_TypeDef_FD14_Segment_2_X2
typedef uint16 FD14_Segment_2_X2;

# define Rte_TypeDef_FD14_Segment_2_Y1
typedef uint16 FD14_Segment_2_Y1;

# define Rte_TypeDef_FD14_Segment_2_Y2
typedef uint16 FD14_Segment_2_Y2;

# define Rte_TypeDef_FD14_Segment_3_Confidence
typedef uint8 FD14_Segment_3_Confidence;

# define Rte_TypeDef_FD14_Segment_3_ID
typedef uint8 FD14_Segment_3_ID;

# define Rte_TypeDef_FD14_Segment_3_X1
typedef uint16 FD14_Segment_3_X1;

# define Rte_TypeDef_FD14_Segment_3_X2
typedef uint16 FD14_Segment_3_X2;

# define Rte_TypeDef_FD14_Segment_3_Y1
typedef uint16 FD14_Segment_3_Y1;

# define Rte_TypeDef_FD14_Segment_3_Y2
typedef uint16 FD14_Segment_3_Y2;

# define Rte_TypeDef_FD14_Segment_4_Confidence
typedef uint8 FD14_Segment_4_Confidence;

# define Rte_TypeDef_FD14_Segment_4_ID
typedef uint8 FD14_Segment_4_ID;

# define Rte_TypeDef_FD14_Segment_4_X1
typedef uint16 FD14_Segment_4_X1;

# define Rte_TypeDef_FD14_Segment_4_X2
typedef uint16 FD14_Segment_4_X2;

# define Rte_TypeDef_FD14_Segment_4_Y1
typedef uint16 FD14_Segment_4_Y1;

# define Rte_TypeDef_FD14_Segment_4_Y2
typedef uint16 FD14_Segment_4_Y2;

# define Rte_TypeDef_FD14_Segment_5_Confidence
typedef uint8 FD14_Segment_5_Confidence;

# define Rte_TypeDef_FD14_Segment_5_ID
typedef uint8 FD14_Segment_5_ID;

# define Rte_TypeDef_FD14_Segment_5_X1
typedef uint16 FD14_Segment_5_X1;

# define Rte_TypeDef_FD14_Segment_5_X2
typedef uint16 FD14_Segment_5_X2;

# define Rte_TypeDef_FD14_Segment_5_Y1
typedef uint16 FD14_Segment_5_Y1;

# define Rte_TypeDef_FD14_Segment_5_Y2
typedef uint16 FD14_Segment_5_Y2;

# define Rte_TypeDef_FD14_Segment_6_Confidence
typedef uint8 FD14_Segment_6_Confidence;

# define Rte_TypeDef_FD14_Segment_6_ID
typedef uint8 FD14_Segment_6_ID;

# define Rte_TypeDef_FD14_Segment_6_X1
typedef uint16 FD14_Segment_6_X1;

# define Rte_TypeDef_FD14_Segment_6_X2
typedef uint16 FD14_Segment_6_X2;

# define Rte_TypeDef_FD14_Segment_6_Y1
typedef uint16 FD14_Segment_6_Y1;

# define Rte_TypeDef_FD14_Segment_6_Y2
typedef uint16 FD14_Segment_6_Y2;

# define Rte_TypeDef_FD14_Segment_7_Confidence
typedef uint8 FD14_Segment_7_Confidence;

# define Rte_TypeDef_FD14_Segment_7_ID
typedef uint8 FD14_Segment_7_ID;

# define Rte_TypeDef_FD14_Segment_7_X1
typedef uint16 FD14_Segment_7_X1;

# define Rte_TypeDef_FD14_Segment_7_X2
typedef uint16 FD14_Segment_7_X2;

# define Rte_TypeDef_FD14_Segment_7_Y1
typedef uint16 FD14_Segment_7_Y1;

# define Rte_TypeDef_FD14_Segment_7_Y2
typedef uint16 FD14_Segment_7_Y2;

# define Rte_TypeDef_FD14_Segment_8_Confidence
typedef uint8 FD14_Segment_8_Confidence;

# define Rte_TypeDef_FD14_Segment_8_ID
typedef uint8 FD14_Segment_8_ID;

# define Rte_TypeDef_FD14_Segment_8_X1
typedef uint16 FD14_Segment_8_X1;

# define Rte_TypeDef_FD14_Segment_8_X2
typedef uint16 FD14_Segment_8_X2;

# define Rte_TypeDef_FD14_Segment_8_Y1
typedef uint16 FD14_Segment_8_Y1;

# define Rte_TypeDef_FD14_Segment_8_Y2
typedef uint16 FD14_Segment_8_Y2;

# define Rte_TypeDef_FD14_SnrDat_FIL_Dir1_cm
typedef uint16 FD14_SnrDat_FIL_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_FIL_Dir2_cm
typedef uint16 FD14_SnrDat_FIL_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_FIR_Dir1_cm
typedef uint16 FD14_SnrDat_FIR_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_FIR_Dir2_cm
typedef uint16 FD14_SnrDat_FIR_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_FOL_Dir1_cm
typedef uint16 FD14_SnrDat_FOL_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_FOL_Dir2_cm
typedef uint16 FD14_SnrDat_FOL_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_FOR_Dir1_cm
typedef uint16 FD14_SnrDat_FOR_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_FOR_Dir2_cm
typedef uint16 FD14_SnrDat_FOR_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_FSL_Dir1_cm
typedef uint16 FD14_SnrDat_FSL_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_FSL_Dir2_cm
typedef uint16 FD14_SnrDat_FSL_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_FSR_Dir1_cm
typedef uint16 FD14_SnrDat_FSR_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_FSR_Dir2_cm
typedef uint16 FD14_SnrDat_FSR_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_RIL_Dir1_cm
typedef uint16 FD14_SnrDat_RIL_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_RIL_Dir2_cm
typedef uint16 FD14_SnrDat_RIL_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_RIR_Dir1_cm
typedef uint16 FD14_SnrDat_RIR_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_RIR_Dir2_cm
typedef uint16 FD14_SnrDat_RIR_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_ROL_Dir1_cm
typedef uint16 FD14_SnrDat_ROL_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_ROL_Dir2_cm
typedef uint16 FD14_SnrDat_ROL_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_ROR_Dir1_cm
typedef uint16 FD14_SnrDat_ROR_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_ROR_Dir2_cm
typedef uint16 FD14_SnrDat_ROR_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_RSL_Dir1_cm
typedef uint16 FD14_SnrDat_RSL_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_RSL_Dir2_cm
typedef uint16 FD14_SnrDat_RSL_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_RSR_Dir1_cm
typedef uint16 FD14_SnrDat_RSR_Dir1_cm;

# define Rte_TypeDef_FD14_SnrDat_RSR_Dir2_cm
typedef uint16 FD14_SnrDat_RSR_Dir2_cm;

# define Rte_TypeDef_FD14_SnrDat_sFIL_Indir_FIR_cm
typedef uint16 FD14_SnrDat_sFIL_Indir_FIR_cm;

# define Rte_TypeDef_FD14_SnrDat_sFIL_Indir_FOL_cm
typedef uint16 FD14_SnrDat_sFIL_Indir_FOL_cm;

# define Rte_TypeDef_FD14_SnrDat_sFIR_Indir_FIL_cm
typedef uint16 FD14_SnrDat_sFIR_Indir_FIL_cm;

# define Rte_TypeDef_FD14_SnrDat_sFIR_Indir_FOR_cm
typedef uint16 FD14_SnrDat_sFIR_Indir_FOR_cm;

# define Rte_TypeDef_FD14_SnrDat_sFOL_Indir_FIL_cm
typedef uint16 FD14_SnrDat_sFOL_Indir_FIL_cm;

# define Rte_TypeDef_FD14_SnrDat_sFOL_Indir_FSL_cm
typedef uint16 FD14_SnrDat_sFOL_Indir_FSL_cm;

# define Rte_TypeDef_FD14_SnrDat_sFOR_Indir_FIR_cm
typedef uint16 FD14_SnrDat_sFOR_Indir_FIR_cm;

# define Rte_TypeDef_FD14_SnrDat_sFOR_Indir_FSR_cm
typedef uint16 FD14_SnrDat_sFOR_Indir_FSR_cm;

# define Rte_TypeDef_FD14_SnrDat_sFSL_Indir_FOL_cm
typedef uint16 FD14_SnrDat_sFSL_Indir_FOL_cm;

# define Rte_TypeDef_FD14_SnrDat_sFSR_Indir_FOR_cm
typedef uint16 FD14_SnrDat_sFSR_Indir_FOR_cm;

# define Rte_TypeDef_FD14_SnrDat_sRIL_Indir_RIR_cm
typedef uint16 FD14_SnrDat_sRIL_Indir_RIR_cm;

# define Rte_TypeDef_FD14_SnrDat_sRIL_Indir_ROL_cm
typedef uint16 FD14_SnrDat_sRIL_Indir_ROL_cm;

# define Rte_TypeDef_FD14_SnrDat_sRIR_Indir_RIL_cm
typedef uint16 FD14_SnrDat_sRIR_Indir_RIL_cm;

# define Rte_TypeDef_FD14_SnrDat_sRIR_Indir_ROR_cm
typedef uint16 FD14_SnrDat_sRIR_Indir_ROR_cm;

# define Rte_TypeDef_FD14_SnrDat_sROL_Indir_RIL_cm
typedef uint16 FD14_SnrDat_sROL_Indir_RIL_cm;

# define Rte_TypeDef_FD14_SnrDat_sROL_Indir_RSL_cm
typedef uint16 FD14_SnrDat_sROL_Indir_RSL_cm;

# define Rte_TypeDef_FD14_SnrDat_sROR_Indir_RIR_cm
typedef uint16 FD14_SnrDat_sROR_Indir_RIR_cm;

# define Rte_TypeDef_FD14_SnrDat_sROR_Indir_RSR_cm
typedef uint16 FD14_SnrDat_sROR_Indir_RSR_cm;

# define Rte_TypeDef_FD14_SnrDat_sRSL_Indir_ROL_cm
typedef uint16 FD14_SnrDat_sRSL_Indir_ROL_cm;

# define Rte_TypeDef_FD14_SnrDat_sRSR_Indir_ROR_cm
typedef uint16 FD14_SnrDat_sRSR_Indir_ROR_cm;

# define Rte_TypeDef_FD14_SnrMeasDataChecksum
typedef uint32 FD14_SnrMeasDataChecksum;

# define Rte_TypeDef_FD14_SrvCamIndBaNok_b
typedef boolean FD14_SrvCamIndBaNok_b;

# define Rte_TypeDef_FD14_SrvCamIndBaNone_b
typedef boolean FD14_SrvCamIndBaNone_b;

# define Rte_TypeDef_FD14_SrvCamIndBaOk_b
typedef boolean FD14_SrvCamIndBaOk_b;

# define Rte_TypeDef_FD14_SrvCamIndBaPend_b
typedef boolean FD14_SrvCamIndBaPend_b;

# define Rte_TypeDef_FD14_SrvCamIndFrNok_b
typedef boolean FD14_SrvCamIndFrNok_b;

# define Rte_TypeDef_FD14_SrvCamIndFrNone_b
typedef boolean FD14_SrvCamIndFrNone_b;

# define Rte_TypeDef_FD14_SrvCamIndFrOk_b
typedef boolean FD14_SrvCamIndFrOk_b;

# define Rte_TypeDef_FD14_SrvCamIndFrPend_b
typedef boolean FD14_SrvCamIndFrPend_b;

# define Rte_TypeDef_FD14_SrvCamIndLeNok_b
typedef boolean FD14_SrvCamIndLeNok_b;

# define Rte_TypeDef_FD14_SrvCamIndLeNone_b
typedef boolean FD14_SrvCamIndLeNone_b;

# define Rte_TypeDef_FD14_SrvCamIndLeOk_b
typedef boolean FD14_SrvCamIndLeOk_b;

# define Rte_TypeDef_FD14_SrvCamIndLePend_b
typedef boolean FD14_SrvCamIndLePend_b;

# define Rte_TypeDef_FD14_SrvCamIndRiNok_b
typedef boolean FD14_SrvCamIndRiNok_b;

# define Rte_TypeDef_FD14_SrvCamIndRiNone_b
typedef boolean FD14_SrvCamIndRiNone_b;

# define Rte_TypeDef_FD14_SrvCamIndRiOk_b
typedef boolean FD14_SrvCamIndRiOk_b;

# define Rte_TypeDef_FD14_SrvCamIndRiPend_b
typedef boolean FD14_SrvCamIndRiPend_b;

# define Rte_TypeDef_FD14_SrvChkIndCondNok_b
typedef boolean FD14_SrvChkIndCondNok_b;

# define Rte_TypeDef_FD14_SrvChkIndNok_b
typedef boolean FD14_SrvChkIndNok_b;

# define Rte_TypeDef_FD14_SrvChkIndOk_b
typedef boolean FD14_SrvChkIndOk_b;

# define Rte_TypeDef_FD14_SrvChkIndRun_b
typedef boolean FD14_SrvChkIndRun_b;

# define Rte_TypeDef_FD14_SrvLayout_b
typedef boolean FD14_SrvLayout_b;

# define Rte_TypeDef_FD14_SrvPrgBar0Per_b
typedef boolean FD14_SrvPrgBar0Per_b;

# define Rte_TypeDef_FD14_SrvPrgBar100Per_b
typedef boolean FD14_SrvPrgBar100Per_b;

# define Rte_TypeDef_FD14_SrvPrgBar20Per_b
typedef boolean FD14_SrvPrgBar20Per_b;

# define Rte_TypeDef_FD14_SrvPrgBar40Per_b
typedef boolean FD14_SrvPrgBar40Per_b;

# define Rte_TypeDef_FD14_SrvPrgBar60Per_b
typedef boolean FD14_SrvPrgBar60Per_b;

# define Rte_TypeDef_FD14_SrvPrgBar80Per_b
typedef boolean FD14_SrvPrgBar80Per_b;

# define Rte_TypeDef_FD14_SrvSpOmIndNok_b
typedef boolean FD14_SrvSpOmIndNok_b;

# define Rte_TypeDef_FD14_SrvSpOmIndOk_b
typedef boolean FD14_SrvSpOmIndOk_b;

# define Rte_TypeDef_FD14_SrvStAngIndNok_b
typedef boolean FD14_SrvStAngIndNok_b;

# define Rte_TypeDef_FD14_SrvStAngIndOk_b
typedef boolean FD14_SrvStAngIndOk_b;

# define Rte_TypeDef_FD14_SystemMode
typedef uint16 FD14_SystemMode;

# define Rte_TypeDef_FD14_SystemStatus
typedef uint8 FD14_SystemStatus;

# define Rte_TypeDef_FD14_TADAngleRate
typedef float32 FD14_TADAngleRate;

# define Rte_TypeDef_FD14_THAButtonGrey
typedef boolean FD14_THAButtonGrey;

# define Rte_TypeDef_FD14_THAButtonSelectable
typedef boolean FD14_THAButtonSelectable;

# define Rte_TypeDef_FD14_THAConfirmButton
typedef boolean FD14_THAConfirmButton;

# define Rte_TypeDef_FD14_THACouplerBulletIcon
typedef boolean FD14_THACouplerBulletIcon;

# define Rte_TypeDef_FD14_THAProgressBar
typedef boolean FD14_THAProgressBar;

# define Rte_TypeDef_FD14_THAStartButton
typedef boolean FD14_THAStartButton;

# define Rte_TypeDef_FD14_THATriangleOverlay
typedef boolean FD14_THATriangleOverlay;

# define Rte_TypeDef_FD14_THA_SteeringDamping
typedef uint8 FD14_THA_SteeringDamping;

# define Rte_TypeDef_FD14_THA_SteeringTorqueInfo
typedef uint16 FD14_THA_SteeringTorqueInfo;

# define Rte_TypeDef_FD14_TRSC_SteeringTorqueInfo
typedef uint16 FD14_TRSC_SteeringTorqueInfo;

# define Rte_TypeDef_FD14_TadAngle
typedef float32 FD14_TadAngle;

# define Rte_TypeDef_FD14_TargetDetectLeftFront_Front_s8
typedef sint8 FD14_TargetDetectLeftFront_Front_s8;

# define Rte_TypeDef_FD14_TargetDetectLeftFront_Left_s8
typedef sint8 FD14_TargetDetectLeftFront_Left_s8;

# define Rte_TypeDef_FD14_TargetDetectLeftFront_Rear_s8
typedef sint8 FD14_TargetDetectLeftFront_Rear_s8;

# define Rte_TypeDef_FD14_TargetDetectLeftFront_Right_s8
typedef sint8 FD14_TargetDetectLeftFront_Right_s8;

# define Rte_TypeDef_FD14_TargetDetectLeftRear_Front_s8
typedef sint8 FD14_TargetDetectLeftRear_Front_s8;

# define Rte_TypeDef_FD14_TargetDetectLeftRear_Rear_s8
typedef sint8 FD14_TargetDetectLeftRear_Rear_s8;

# define Rte_TypeDef_FD14_TargetDetectLeftRear_Right_s8
typedef sint8 FD14_TargetDetectLeftRear_Right_s8;

# define Rte_TypeDef_FD14_TargetDetectRightFront_Front_s8
typedef sint8 FD14_TargetDetectRightFront_Front_s8;

# define Rte_TypeDef_FD14_TargetDetectRightFront_Left_s8
typedef sint8 FD14_TargetDetectRightFront_Left_s8;

# define Rte_TypeDef_FD14_TargetDetectRightFront_Rear_s8
typedef sint8 FD14_TargetDetectRightFront_Rear_s8;

# define Rte_TypeDef_FD14_TargetDetectRightFront_Right_s8
typedef sint8 FD14_TargetDetectRightFront_Right_s8;

# define Rte_TypeDef_FD14_TargetDetectRightRear_Front_s8
typedef sint8 FD14_TargetDetectRightRear_Front_s8;

# define Rte_TypeDef_FD14_TargetDetectRightRear_Left_s8
typedef sint8 FD14_TargetDetectRightRear_Left_s8;

# define Rte_TypeDef_FD14_TargetDetectRightRear_Rear_s8
typedef sint8 FD14_TargetDetectRightRear_Rear_s8;

# define Rte_TypeDef_FD14_TargetDetectRightRear_Right_s8
typedef sint8 FD14_TargetDetectRightRear_Right_s8;

# define Rte_TypeDef_FD14_TargetInit_Front_s8
typedef sint8 FD14_TargetInit_Front_s8;

# define Rte_TypeDef_FD14_TargetInit_Left_s8
typedef sint8 FD14_TargetInit_Left_s8;

# define Rte_TypeDef_FD14_TargetInit_Rear_s8
typedef sint8 FD14_TargetInit_Rear_s8;

# define Rte_TypeDef_FD14_TargetInit_Right_s8
typedef sint8 FD14_TargetInit_Right_s8;

# define Rte_TypeDef_FD14_TargetLimitFront_Front_s8
typedef sint8 FD14_TargetLimitFront_Front_s8;

# define Rte_TypeDef_FD14_TargetLimitFront_Left_s8
typedef sint8 FD14_TargetLimitFront_Left_s8;

# define Rte_TypeDef_FD14_TargetLimitFront_Rear_s8
typedef sint8 FD14_TargetLimitFront_Rear_s8;

# define Rte_TypeDef_FD14_TargetLimitFront_Right_s8
typedef sint8 FD14_TargetLimitFront_Right_s8;

# define Rte_TypeDef_FD14_TargetLimitRear_Front_s8
typedef sint8 FD14_TargetLimitRear_Front_s8;

# define Rte_TypeDef_FD14_TargetLimitRear_Left_s8
typedef sint8 FD14_TargetLimitRear_Left_s8;

# define Rte_TypeDef_FD14_TargetLimitRear_Rear_s8
typedef sint8 FD14_TargetLimitRear_Rear_s8;

# define Rte_TypeDef_FD14_TargetLimitRear_Right_s8
typedef sint8 FD14_TargetLimitRear_Right_s8;

# define Rte_TypeDef_FD14_TimeStamp_SystemStatus
typedef uint32 FD14_TimeStamp_SystemStatus;

# define Rte_TypeDef_FD14_TopFrontButtonNoSelect_b
typedef boolean FD14_TopFrontButtonNoSelect_b;

# define Rte_TypeDef_FD14_TopFrontButtonSelect_b
typedef boolean FD14_TopFrontButtonSelect_b;

# define Rte_TypeDef_FD14_TopRearButtonNoSelect_b
typedef boolean FD14_TopRearButtonNoSelect_b;

# define Rte_TypeDef_FD14_TopRearButtonSelect_b
typedef boolean FD14_TopRearButtonSelect_b;

# define Rte_TypeDef_FD14_TopVideoBlanked_b
typedef boolean FD14_TopVideoBlanked_b;

# define Rte_TypeDef_FD14_TopViewBlack_b
typedef boolean FD14_TopViewBlack_b;

# define Rte_TypeDef_FD14_TopViewFrontDynamics_b
typedef boolean FD14_TopViewFrontDynamics_b;

# define Rte_TypeDef_FD14_TopViewRearDynamics_b
typedef boolean FD14_TopViewRearDynamics_b;

# define Rte_TypeDef_FD14_TorqueOverlaySteeringReq_SPM
typedef uint16 FD14_TorqueOverlaySteeringReq_SPM;

# define Rte_TypeDef_FD14_Total_lines_count
typedef uint8 FD14_Total_lines_count;

# define Rte_TypeDef_FD14_TrailerCalFailInfo
typedef uint8 FD14_TrailerCalFailInfo;

# define Rte_TypeDef_FD14_TrailerConnectionStatus
typedef uint8 FD14_TrailerConnectionStatus;

# define Rte_TypeDef_FD14_TrailerWheelBase
typedef uint8 FD14_TrailerWheelBase;

# define Rte_TypeDef_FD14_Trailer_Recognition_Confidence
typedef float32 FD14_Trailer_Recognition_Confidence;

# define Rte_TypeDef_FD14_Trailer_tracking_confidence
typedef float32 FD14_Trailer_tracking_confidence;

# define Rte_TypeDef_FD14_Trailercalinfo
typedef uint8 FD14_Trailercalinfo;

# define Rte_TypeDef_FD14_TrscJackKnifeOrange
typedef boolean FD14_TrscJackKnifeOrange;

# define Rte_TypeDef_FD14_TrscJackKnifeRed
typedef boolean FD14_TrscJackKnifeRed;

# define Rte_TypeDef_FD14_TrscOvl
typedef boolean FD14_TrscOvl;

# define Rte_TypeDef_FD14_TrscTrailerRed
typedef boolean FD14_TrscTrailerRed;

# define Rte_TypeDef_FD14_Tstr_SD_FIL_DrvFreq
typedef uint16 FD14_Tstr_SD_FIL_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FIL_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_FIL_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_FIL_RingFreq
typedef uint16 FD14_Tstr_SD_FIL_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FIL_Ringtime_us
typedef uint16 FD14_Tstr_SD_FIL_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_FIL_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_FIL_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FIL_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_FIL_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FIL_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_FIL_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_FIL_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_FIL_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_FIR_DrvFreq
typedef uint16 FD14_Tstr_SD_FIR_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FIR_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_FIR_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_FIR_RingFreq
typedef uint16 FD14_Tstr_SD_FIR_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FIR_Ringtime_us
typedef uint16 FD14_Tstr_SD_FIR_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_FIR_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_FIR_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FIR_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_FIR_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FIR_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_FIR_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_FIR_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_FIR_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_FOL_DrvFreq
typedef uint16 FD14_Tstr_SD_FOL_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FOL_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_FOL_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_FOL_RingFreq
typedef uint16 FD14_Tstr_SD_FOL_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FOL_Ringtime_us
typedef uint16 FD14_Tstr_SD_FOL_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_FOL_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_FOL_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FOL_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_FOL_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FOL_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_FOL_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_FOL_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_FOL_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_FOR_DrvFreq
typedef uint16 FD14_Tstr_SD_FOR_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FOR_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_FOR_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_FOR_RingFreq
typedef uint16 FD14_Tstr_SD_FOR_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FOR_Ringtime_us
typedef uint16 FD14_Tstr_SD_FOR_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_FOR_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_FOR_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FOR_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_FOR_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FOR_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_FOR_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_FOR_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_FOR_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_FSL_DrvFreq
typedef uint16 FD14_Tstr_SD_FSL_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FSL_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_FSL_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_FSL_RingFreq
typedef uint16 FD14_Tstr_SD_FSL_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FSL_Ringtime_us
typedef uint16 FD14_Tstr_SD_FSL_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_FSL_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_FSL_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FSL_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_FSL_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FSL_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_FSL_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_FSL_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_FSL_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_FSR_DrvFreq
typedef uint16 FD14_Tstr_SD_FSR_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FSR_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_FSR_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_FSR_RingFreq
typedef uint16 FD14_Tstr_SD_FSR_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_FSR_Ringtime_us
typedef uint16 FD14_Tstr_SD_FSR_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_FSR_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_FSR_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FSR_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_FSR_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_FSR_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_FSR_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_FSR_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_FSR_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_RIL_DrvFreq
typedef uint16 FD14_Tstr_SD_RIL_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_RIL_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_RIL_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_RIL_RingFreq
typedef uint16 FD14_Tstr_SD_RIL_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_RIL_Ringtime_us
typedef uint16 FD14_Tstr_SD_RIL_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_RIL_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_RIL_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_RIL_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_RIL_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_RIL_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_RIL_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_RIL_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_RIL_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_RIR_DrvFreq
typedef uint16 FD14_Tstr_SD_RIR_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_RIR_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_RIR_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_RIR_RingFreq
typedef uint16 FD14_Tstr_SD_RIR_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_RIR_Ringtime_us
typedef uint16 FD14_Tstr_SD_RIR_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_RIR_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_RIR_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_RIR_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_RIR_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_RIR_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_RIR_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_RIR_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_RIR_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_ROL_DrvFreq
typedef uint16 FD14_Tstr_SD_ROL_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_ROL_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_ROL_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_ROL_RingFreq
typedef uint16 FD14_Tstr_SD_ROL_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_ROL_Ringtime_us
typedef uint16 FD14_Tstr_SD_ROL_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_ROL_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_ROL_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_ROL_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_ROL_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_ROL_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_ROL_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_ROL_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_ROL_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_ROR_DrvFreq
typedef uint16 FD14_Tstr_SD_ROR_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_ROR_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_ROR_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_ROR_RingFreq
typedef uint16 FD14_Tstr_SD_ROR_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_ROR_Ringtime_us
typedef uint16 FD14_Tstr_SD_ROR_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_ROR_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_ROR_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_ROR_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_ROR_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_ROR_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_ROR_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_ROR_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_ROR_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_RSL_DrvFreq
typedef uint16 FD14_Tstr_SD_RSL_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_RSL_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_RSL_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_RSL_RingFreq
typedef uint16 FD14_Tstr_SD_RSL_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_RSL_Ringtime_us
typedef uint16 FD14_Tstr_SD_RSL_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_RSL_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_RSL_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_RSL_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_RSL_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_RSL_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_RSL_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_RSL_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_RSL_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_Tstr_SD_RSR_DrvFreq
typedef uint16 FD14_Tstr_SD_RSR_DrvFreq;

# define Rte_TypeDef_FD14_Tstr_SD_RSR_EchoHeight_adc
typedef uint8 FD14_Tstr_SD_RSR_EchoHeight_adc;

# define Rte_TypeDef_FD14_Tstr_SD_RSR_RingFreq
typedef uint16 FD14_Tstr_SD_RSR_RingFreq;

# define Rte_TypeDef_FD14_Tstr_SD_RSR_Ringtime_us
typedef uint16 FD14_Tstr_SD_RSR_Ringtime_us;

# define Rte_TypeDef_FD14_Tstr_SD_RSR_SensorBlkgClrCounter
typedef uint8 FD14_Tstr_SD_RSR_SensorBlkgClrCounter;

# define Rte_TypeDef_FD14_Tstr_SD_RSR_SensorBlkgSetCounter
typedef uint8 FD14_Tstr_SD_RSR_SensorBlkgSetCounter;

# define Rte_TypeDef_FD14_Tstr_SD_RSR_Unfiltered_DirDist1
typedef uint16 FD14_Tstr_SD_RSR_Unfiltered_DirDist1;

# define Rte_TypeDef_FD14_Tstr_SD_RSR_Unfiltered_DirDist2
typedef uint16 FD14_Tstr_SD_RSR_Unfiltered_DirDist2;

# define Rte_TypeDef_FD14_USS_MPAZoneB00
typedef uint8 FD14_USS_MPAZoneB00;

# define Rte_TypeDef_FD14_USS_MPAZoneB01
typedef uint8 FD14_USS_MPAZoneB01;

# define Rte_TypeDef_FD14_USS_MPAZoneB02
typedef uint8 FD14_USS_MPAZoneB02;

# define Rte_TypeDef_FD14_USS_MPAZoneB03
typedef uint8 FD14_USS_MPAZoneB03;

# define Rte_TypeDef_FD14_USS_MPAZoneF00
typedef uint8 FD14_USS_MPAZoneF00;

# define Rte_TypeDef_FD14_USS_MPAZoneF01
typedef uint8 FD14_USS_MPAZoneF01;

# define Rte_TypeDef_FD14_USS_MPAZoneF02
typedef uint8 FD14_USS_MPAZoneF02;

# define Rte_TypeDef_FD14_USS_MPAZoneF03
typedef uint8 FD14_USS_MPAZoneF03;

# define Rte_TypeDef_FD14_ValidFeatures_Front_u32
typedef uint32 FD14_ValidFeatures_Front_u32;

# define Rte_TypeDef_FD14_ValidFeatures_Left_u32
typedef uint32 FD14_ValidFeatures_Left_u32;

# define Rte_TypeDef_FD14_ValidFeatures_Rear_u32
typedef uint32 FD14_ValidFeatures_Rear_u32;

# define Rte_TypeDef_FD14_ValidFeatures_Right_u32
typedef uint32 FD14_ValidFeatures_Right_u32;

# define Rte_TypeDef_FD14_XIcon_b
typedef boolean FD14_XIcon_b;

# define Rte_TypeDef_FD14_X_BTN_PRESSED_b
typedef boolean FD14_X_BTN_PRESSED_b;

# define Rte_TypeDef_FD14_X_f32_Current_Rear
typedef float32 FD14_X_f32_Current_Rear;

# define Rte_TypeDef_FD14_X_f32_Current_Right
typedef float32 FD14_X_f32_Current_Right;

# define Rte_TypeDef_FD14_X_f32_EOL_Front
typedef float32 FD14_X_f32_EOL_Front;

# define Rte_TypeDef_FD14_X_f32_EOL_Left
typedef float32 FD14_X_f32_EOL_Left;

# define Rte_TypeDef_FD14_X_f32_EOL_Rear
typedef float32 FD14_X_f32_EOL_Rear;

# define Rte_TypeDef_FD14_X_f32_EOL_Right
typedef float32 FD14_X_f32_EOL_Right;

# define Rte_TypeDef_FD14_Y_f32_Current_Rear
typedef float32 FD14_Y_f32_Current_Rear;

# define Rte_TypeDef_FD14_Y_f32_Current_Right
typedef float32 FD14_Y_f32_Current_Right;

# define Rte_TypeDef_FD14_Y_f32_EOL_Front
typedef float32 FD14_Y_f32_EOL_Front;

# define Rte_TypeDef_FD14_Y_f32_EOL_Left
typedef float32 FD14_Y_f32_EOL_Left;

# define Rte_TypeDef_FD14_Y_f32_EOL_Rear
typedef float32 FD14_Y_f32_EOL_Rear;

# define Rte_TypeDef_FD14_Y_f32_EOL_Right
typedef float32 FD14_Y_f32_EOL_Right;

# define Rte_TypeDef_FD14_Yaw_f32_Current_Rear
typedef float32 FD14_Yaw_f32_Current_Rear;

# define Rte_TypeDef_FD14_Yaw_f32_Current_Right
typedef float32 FD14_Yaw_f32_Current_Right;

# define Rte_TypeDef_FD14_Yaw_f32_EOL_Front
typedef float32 FD14_Yaw_f32_EOL_Front;

# define Rte_TypeDef_FD14_Yaw_f32_EOL_Left
typedef float32 FD14_Yaw_f32_EOL_Left;

# define Rte_TypeDef_FD14_Yaw_f32_EOL_Rear
typedef float32 FD14_Yaw_f32_EOL_Rear;

# define Rte_TypeDef_FD14_Yaw_f32_EOL_Right
typedef float32 FD14_Yaw_f32_EOL_Right;

# define Rte_TypeDef_FD14_Yaw_f32_OC_Front
typedef float32 FD14_Yaw_f32_OC_Front;

# define Rte_TypeDef_FD14_Yaw_f32_OC_Left
typedef float32 FD14_Yaw_f32_OC_Left;

# define Rte_TypeDef_FD14_Yaw_f32_OC_Rear
typedef float32 FD14_Yaw_f32_OC_Rear;

# define Rte_TypeDef_FD14_Yaw_f32_OC_Right
typedef float32 FD14_Yaw_f32_OC_Right;

# define Rte_TypeDef_FD14_Yaw_f32_SC_Front
typedef float32 FD14_Yaw_f32_SC_Front;

# define Rte_TypeDef_FD14_Yaw_f32_SC_Left
typedef float32 FD14_Yaw_f32_SC_Left;

# define Rte_TypeDef_FD14_Yaw_f32_SC_Rear
typedef float32 FD14_Yaw_f32_SC_Rear;

# define Rte_TypeDef_FD14_Yaw_f32_SC_Right
typedef float32 FD14_Yaw_f32_SC_Right;

# define Rte_TypeDef_FD14_Z_f32_Current_Rear
typedef float32 FD14_Z_f32_Current_Rear;

# define Rte_TypeDef_FD14_Z_f32_Current_Right
typedef float32 FD14_Z_f32_Current_Right;

# define Rte_TypeDef_FD14_Z_f32_EOL_Front
typedef float32 FD14_Z_f32_EOL_Front;

# define Rte_TypeDef_FD14_Z_f32_EOL_Left
typedef float32 FD14_Z_f32_EOL_Left;

# define Rte_TypeDef_FD14_Z_f32_EOL_Rear
typedef float32 FD14_Z_f32_EOL_Rear;

# define Rte_TypeDef_FD14_Z_f32_EOL_Right
typedef float32 FD14_Z_f32_EOL_Right;

# define Rte_TypeDef_FD14_ZoomButtonDisable_b
typedef boolean FD14_ZoomButtonDisable_b;

# define Rte_TypeDef_FD14_ZoomFactor_u8
typedef uint8 FD14_ZoomFactor_u8;

# define Rte_TypeDef_FD14_ZoomMinusIcon_b
typedef boolean FD14_ZoomMinusIcon_b;

# define Rte_TypeDef_FD14_ZoomPlusIcon_b
typedef boolean FD14_ZoomPlusIcon_b;

# define Rte_TypeDef_FD14__JackKnifeAngle
typedef float32 FD14__JackKnifeAngle;

# define Rte_TypeDef_FD14_averageIllumination
typedef uint32 FD14_averageIllumination;

# define Rte_TypeDef_FD14_calibrationCompleted
typedef boolean FD14_calibrationCompleted;

# define Rte_TypeDef_FD14_calibrationSubState
typedef uint8 FD14_calibrationSubState;

# define Rte_TypeDef_FD14_cntrCvpamFdData1_u16
typedef uint16 FD14_cntrCvpamFdData1_u16;

# define Rte_TypeDef_FD14_crcCvpamFdData1_u8
typedef uint8 FD14_crcCvpamFdData1_u8;

# define Rte_TypeDef_FD14_curState
typedef uint8 FD14_curState;

# define Rte_TypeDef_FD14_hitchCalibrationAngle
typedef sint32 FD14_hitchCalibrationAngle;

# define Rte_TypeDef_FD14_hitchLength
typedef float32 FD14_hitchLength;

# define Rte_TypeDef_FD14_isPLDInitSuccess_b
typedef boolean FD14_isPLDInitSuccess_b;

# define Rte_TypeDef_FD14_isUSSInitSuccess_b
typedef boolean FD14_isUSSInitSuccess_b;

# define Rte_TypeDef_FD14_leLMD_e_HealthStatus
typedef uint8 FD14_leLMD_e_HealthStatus;

# define Rte_TypeDef_FD14_leftCalibrationAngle
typedef sint32 FD14_leftCalibrationAngle;

# define Rte_TypeDef_FD14_m_FPAInfoToPLDSlotID
typedef uint8 FD14_m_FPAInfoToPLDSlotID;

# define Rte_TypeDef_FD14_m_FPAInfoToUSSOMSlotID
typedef uint8 FD14_m_FPAInfoToUSSOMSlotID;

# define Rte_TypeDef_FD14_m_FPAToNVMParkInStyle
typedef uint8 FD14_m_FPAToNVMParkInStyle;

# define Rte_TypeDef_FD14_m_FPAToNVMReadNVMParam_b
typedef boolean FD14_m_FPAToNVMReadNVMParam_b;

# define Rte_TypeDef_FD14_m_FPAToNVMWriteNVMParam_b
typedef boolean FD14_m_FPAToNVMWriteNVMParam_b;

# define Rte_TypeDef_FD14_m_FpaInfoToVCParkOutStyle
typedef uint8 FD14_m_FpaInfoToVCParkOutStyle;

# define Rte_TypeDef_FD14_m_QM_FID_TRSC_ASCMDef
typedef uint8 FD14_m_QM_FID_TRSC_ASCMDef;

# define Rte_TypeDef_FD14_m_QM_FID_TRSC_CAM_CAL_ABORT
typedef uint8 FD14_m_QM_FID_TRSC_CAM_CAL_ABORT;

# define Rte_TypeDef_FD14_m_QM_FID_TRSC_DISABLED
typedef uint8 FD14_m_QM_FID_TRSC_DISABLED;

# define Rte_TypeDef_FD14_m_QM_FID_TRSC_LIMITED_DefView
typedef uint8 FD14_m_QM_FID_TRSC_LIMITED_DefView;

# define Rte_TypeDef_FD14_m_QM_FID_TRSC_LIMITED_View
typedef uint8 FD14_m_QM_FID_TRSC_LIMITED_View;

# define Rte_TypeDef_FD14_msgcntrCvpamFdData1_u8
typedef uint8 FD14_msgcntrCvpamFdData1_u8;

# define Rte_TypeDef_FD14_obj_Pos_Lat
typedef float32 FD14_obj_Pos_Lat;

# define Rte_TypeDef_FD14_obj_Pos_Longi
typedef float32 FD14_obj_Pos_Longi;

# define Rte_TypeDef_FD14_rightCalibrationAngle
typedef sint32 FD14_rightCalibrationAngle;

# define Rte_TypeDef_FD14_stFPAInfoToHMISlot1Valid
typedef boolean FD14_stFPAInfoToHMISlot1Valid;

# define Rte_TypeDef_FD14_stFPAInfoToHMISlot2Valid
typedef boolean FD14_stFPAInfoToHMISlot2Valid;

# define Rte_TypeDef_FD14_stFPAInfoToHMISlot3Valid
typedef boolean FD14_stFPAInfoToHMISlot3Valid;

# define Rte_TypeDef_FD14_stFPAInfoToHMISlot4Valid
typedef boolean FD14_stFPAInfoToHMISlot4Valid;

# define Rte_TypeDef_FD14_stFPAInfoToHMISlot5Valid
typedef boolean FD14_stFPAInfoToHMISlot5Valid;

# define Rte_TypeDef_FD14_stFPAInfoToHMISlot6Valid
typedef boolean FD14_stFPAInfoToHMISlot6Valid;

# define Rte_TypeDef_FD14_stFPAInfoToVCLockedSlotFrntLeftX
typedef float32 FD14_stFPAInfoToVCLockedSlotFrntLeftX;

# define Rte_TypeDef_FD14_stFPAInfoToVCLockedSlotFrntLeftY
typedef float32 FD14_stFPAInfoToVCLockedSlotFrntLeftY;

# define Rte_TypeDef_FD14_stFPAInfoToVCLockedSlotID
typedef uint8 FD14_stFPAInfoToVCLockedSlotID;

# define Rte_TypeDef_FD14_stFPAInfoToVCLockedSlotRearRghtX
typedef float32 FD14_stFPAInfoToVCLockedSlotRearRghtX;

# define Rte_TypeDef_FD14_stFPAInfoToVCLockedSlotRearRghtY
typedef float32 FD14_stFPAInfoToVCLockedSlotRearRghtY;

# define Rte_TypeDef_FD14_stFPAInfoToVCLockedSlotSide
typedef uint8 FD14_stFPAInfoToVCLockedSlotSide;

# define Rte_TypeDef_FD14_stFPAInfoToVCLockedSlotType
typedef uint8 FD14_stFPAInfoToVCLockedSlotType;

# define Rte_TypeDef_FD14_stFPAInfoToVCLockedSlotValid
typedef boolean FD14_stFPAInfoToVCLockedSlotValid;

# define Rte_TypeDef_FD14_stLeftObjectList1Valid
typedef boolean FD14_stLeftObjectList1Valid;

# define Rte_TypeDef_FD14_stLeftObjectList2Valid
typedef boolean FD14_stLeftObjectList2Valid;

# define Rte_TypeDef_FD14_stLeftObjectList3Valid
typedef boolean FD14_stLeftObjectList3Valid;

# define Rte_TypeDef_FD14_stLeftObjectList4Valid
typedef boolean FD14_stLeftObjectList4Valid;

# define Rte_TypeDef_FD14_stPLDLockedSlotDataFrontLeftX
typedef float32 FD14_stPLDLockedSlotDataFrontLeftX;

# define Rte_TypeDef_FD14_stPLDLockedSlotDataFrontLeftY
typedef float32 FD14_stPLDLockedSlotDataFrontLeftY;

# define Rte_TypeDef_FD14_stPLDLockedSlotDataRearRightX
typedef float32 FD14_stPLDLockedSlotDataRearRightX;

# define Rte_TypeDef_FD14_stPLDLockedSlotDataRearRightY
typedef float32 FD14_stPLDLockedSlotDataRearRightY;

# define Rte_TypeDef_FD14_stPLDLockedSlotDataSlotID
typedef uint8 FD14_stPLDLockedSlotDataSlotID;

# define Rte_TypeDef_FD14_stPLDLockedSlotDataSlotSide
typedef uint8 FD14_stPLDLockedSlotDataSlotSide;

# define Rte_TypeDef_FD14_stPLDLockedSlotDataSlotType
typedef uint8 FD14_stPLDLockedSlotDataSlotType;

# define Rte_TypeDef_FD14_stPLDLockedSlotDataSlotValid
typedef boolean FD14_stPLDLockedSlotDataSlotValid;

# define Rte_TypeDef_FD14_stPLDParkingSlot1DataSlotID
typedef uint8 FD14_stPLDParkingSlot1DataSlotID;

# define Rte_TypeDef_FD14_stPLDParkingSlot1DataSlotSide
typedef uint8 FD14_stPLDParkingSlot1DataSlotSide;

# define Rte_TypeDef_FD14_stPLDParkingSlot1FrontLeftX
typedef float32 FD14_stPLDParkingSlot1FrontLeftX;

# define Rte_TypeDef_FD14_stPLDParkingSlot1FrontLeftY
typedef float32 FD14_stPLDParkingSlot1FrontLeftY;

# define Rte_TypeDef_FD14_stPLDParkingSlot1RearRightX
typedef float32 FD14_stPLDParkingSlot1RearRightX;

# define Rte_TypeDef_FD14_stPLDParkingSlot1RearRightY
typedef float32 FD14_stPLDParkingSlot1RearRightY;

# define Rte_TypeDef_FD14_stPLDParkingSlot1SlotType
typedef uint8 FD14_stPLDParkingSlot1SlotType;

# define Rte_TypeDef_FD14_stPLDParkingSlot1SlotValid
typedef boolean FD14_stPLDParkingSlot1SlotValid;

# define Rte_TypeDef_FD14_stPLDParkingSlot2SlotValid
typedef boolean FD14_stPLDParkingSlot2SlotValid;

# define Rte_TypeDef_FD14_stPLDParkingSlot3SlotValid
typedef boolean FD14_stPLDParkingSlot3SlotValid;

# define Rte_TypeDef_FD14_stPLDParkingSlot4DataSlotID
typedef uint8 FD14_stPLDParkingSlot4DataSlotID;

# define Rte_TypeDef_FD14_stPLDParkingSlot4DataSlotSide
typedef uint8 FD14_stPLDParkingSlot4DataSlotSide;

# define Rte_TypeDef_FD14_stPLDParkingSlot4FrontLeftX
typedef float32 FD14_stPLDParkingSlot4FrontLeftX;

# define Rte_TypeDef_FD14_stPLDParkingSlot4FrontLeftY
typedef float32 FD14_stPLDParkingSlot4FrontLeftY;

# define Rte_TypeDef_FD14_stPLDParkingSlot4RearRightX
typedef float32 FD14_stPLDParkingSlot4RearRightX;

# define Rte_TypeDef_FD14_stPLDParkingSlot4RearRightY
typedef float32 FD14_stPLDParkingSlot4RearRightY;

# define Rte_TypeDef_FD14_stPLDParkingSlot4SlotType
typedef uint8 FD14_stPLDParkingSlot4SlotType;

# define Rte_TypeDef_FD14_stPLDParkingSlot4SlotValid
typedef boolean FD14_stPLDParkingSlot4SlotValid;

# define Rte_TypeDef_FD14_stPLDParkingSlot5SlotValid
typedef boolean FD14_stPLDParkingSlot5SlotValid;

# define Rte_TypeDef_FD14_stPLDParkingSlot6SlotValid
typedef boolean FD14_stPLDParkingSlot6SlotValid;

# define Rte_TypeDef_FD14_stRightObjectList1Valid
typedef boolean FD14_stRightObjectList1Valid;

# define Rte_TypeDef_FD14_stRightObjectList2Valid
typedef boolean FD14_stRightObjectList2Valid;

# define Rte_TypeDef_FD14_stRightObjectList3Valid
typedef boolean FD14_stRightObjectList3Valid;

# define Rte_TypeDef_FD14_stRightObjectList4Valid
typedef boolean FD14_stRightObjectList4Valid;

# define Rte_TypeDef_FD14_stUSSLockedSlotDataFrontLeftX
typedef float32 FD14_stUSSLockedSlotDataFrontLeftX;

# define Rte_TypeDef_FD14_stUSSLockedSlotDataFrontLeftY
typedef float32 FD14_stUSSLockedSlotDataFrontLeftY;

# define Rte_TypeDef_FD14_stUSSLockedSlotDataRearRightX
typedef float32 FD14_stUSSLockedSlotDataRearRightX;

# define Rte_TypeDef_FD14_stUSSLockedSlotDataRearRightY
typedef float32 FD14_stUSSLockedSlotDataRearRightY;

# define Rte_TypeDef_FD14_stUSSLockedSlotDataSlotID
typedef uint8 FD14_stUSSLockedSlotDataSlotID;

# define Rte_TypeDef_FD14_stUSSLockedSlotDataSlotSide
typedef uint8 FD14_stUSSLockedSlotDataSlotSide;

# define Rte_TypeDef_FD14_stUSSLockedSlotDataSlotType
typedef uint8 FD14_stUSSLockedSlotDataSlotType;

# define Rte_TypeDef_FD14_stUSSLockedSlotDataSlotValid
typedef boolean FD14_stUSSLockedSlotDataSlotValid;

# define Rte_TypeDef_FD14_stUSSParkingSlot1DataSlotID
typedef uint8 FD14_stUSSParkingSlot1DataSlotID;

# define Rte_TypeDef_FD14_stUSSParkingSlot1DataSlotSide
typedef uint8 FD14_stUSSParkingSlot1DataSlotSide;

# define Rte_TypeDef_FD14_stUSSParkingSlot1FrontLeftX
typedef float32 FD14_stUSSParkingSlot1FrontLeftX;

# define Rte_TypeDef_FD14_stUSSParkingSlot1FrontLeftY
typedef float32 FD14_stUSSParkingSlot1FrontLeftY;

# define Rte_TypeDef_FD14_stUSSParkingSlot1RearRightX
typedef float32 FD14_stUSSParkingSlot1RearRightX;

# define Rte_TypeDef_FD14_stUSSParkingSlot1RearRightY
typedef float32 FD14_stUSSParkingSlot1RearRightY;

# define Rte_TypeDef_FD14_stUSSParkingSlot1SlotType
typedef uint8 FD14_stUSSParkingSlot1SlotType;

# define Rte_TypeDef_FD14_stUSSParkingSlot1SlotValid
typedef boolean FD14_stUSSParkingSlot1SlotValid;

# define Rte_TypeDef_FD14_stUSSParkingSlot2SlotValid
typedef boolean FD14_stUSSParkingSlot2SlotValid;

# define Rte_TypeDef_FD14_stUSSParkingSlot3SlotValid
typedef boolean FD14_stUSSParkingSlot3SlotValid;

# define Rte_TypeDef_FD14_stUSSParkingSlot4DataSlotSide
typedef uint8 FD14_stUSSParkingSlot4DataSlotSide;

# define Rte_TypeDef_FD14_stUSSParkingSlot4FrontLeftX
typedef float32 FD14_stUSSParkingSlot4FrontLeftX;

# define Rte_TypeDef_FD14_stUSSParkingSlot4FrontLeftY
typedef float32 FD14_stUSSParkingSlot4FrontLeftY;

# define Rte_TypeDef_FD14_stUSSParkingSlot4RearRightX
typedef float32 FD14_stUSSParkingSlot4RearRightX;

# define Rte_TypeDef_FD14_stUSSParkingSlot4RearRightY
typedef float32 FD14_stUSSParkingSlot4RearRightY;

# define Rte_TypeDef_FD14_stUSSParkingSlot4SlotType
typedef uint8 FD14_stUSSParkingSlot4SlotType;

# define Rte_TypeDef_FD14_stUSSParkingSlot4SlotValid
typedef boolean FD14_stUSSParkingSlot4SlotValid;

# define Rte_TypeDef_FD14_stUSSParkingSlot5SlotValid
typedef boolean FD14_stUSSParkingSlot5SlotValid;

# define Rte_TypeDef_FD14_stUSSParkingSlot6SlotValid
typedef boolean FD14_stUSSParkingSlot6SlotValid;

# define Rte_TypeDef_FD14_steeringWheelAngle_f32
typedef float32 FD14_steeringWheelAngle_f32;

# define Rte_TypeDef_FD14_stnumPointsL
typedef uint16 FD14_stnumPointsL;

# define Rte_TypeDef_FD14_stnumPointsR
typedef uint16 FD14_stnumPointsR;

# define Rte_TypeDef_FD14_tchScrnCoord_s_X_u16
typedef uint8 FD14_tchScrnCoord_s_X_u16;

# define Rte_TypeDef_FD14_tchScrnCoord_s_Y_u16
typedef uint8 FD14_tchScrnCoord_s_Y_u16;

# define Rte_TypeDef_FD14_trailerAngle
typedef float32 FD14_trailerAngle;

# define Rte_TypeDef_FD14_trailerCalibrationCount
typedef uint16 FD14_trailerCalibrationCount;

# define Rte_TypeDef_FD14_trailerCalibrationDelay
typedef boolean FD14_trailerCalibrationDelay;

# define Rte_TypeDef_FD14_turnaroundSubState
typedef uint8 FD14_turnaroundSubState;

# define Rte_TypeDef_FD14_vehicleLine_e
typedef uint8 FD14_vehicleLine_e;

# define Rte_TypeDef_FD14_vehicleSpeed_f32
typedef float32 FD14_vehicleSpeed_f32;

# define Rte_TypeDef_Frame_Index_Lanes_1
typedef uint16 Frame_Index_Lanes_1;

# define Rte_TypeDef_Frame_Index_Lanes_2
typedef uint16 Frame_Index_Lanes_2;

# define Rte_TypeDef_HMICode
typedef uint8 HMICode;

# define Rte_TypeDef_IOHWAB_BOOL
typedef boolean IOHWAB_BOOL;

# define Rte_TypeDef_IOHWAB_UINT16
typedef uint16 IOHWAB_UINT16;

# define Rte_TypeDef_IOHWAB_UINT8
typedef uint8 IOHWAB_UINT8;

# define Rte_TypeDef_IgnitionOnCounter
typedef uint16 IgnitionOnCounter;

# define Rte_TypeDef_Line_1_Confidence
typedef uint8 Line_1_Confidence;

# define Rte_TypeDef_Line_1_Curvature
typedef uint16 Line_1_Curvature;

# define Rte_TypeDef_Line_1_Curvature_Rate
typedef uint16 Line_1_Curvature_Rate;

# define Rte_TypeDef_Line_1_End_Range
typedef uint8 Line_1_End_Range;

# define Rte_TypeDef_Line_1_Heading
typedef uint16 Line_1_Heading;

# define Rte_TypeDef_Line_1_Offset
typedef uint16 Line_1_Offset;

# define Rte_TypeDef_Line_1_Start_Range
typedef uint8 Line_1_Start_Range;

# define Rte_TypeDef_Line_2_Confidence
typedef uint8 Line_2_Confidence;

# define Rte_TypeDef_Line_2_Curvature
typedef uint16 Line_2_Curvature;

# define Rte_TypeDef_Line_2_Curvature_Rate
typedef uint16 Line_2_Curvature_Rate;

# define Rte_TypeDef_Line_2_End_Range
typedef uint8 Line_2_End_Range;

# define Rte_TypeDef_Line_2_Heading
typedef uint16 Line_2_Heading;

# define Rte_TypeDef_Line_2_Offset
typedef uint16 Line_2_Offset;

# define Rte_TypeDef_Line_2_Start_Range
typedef uint8 Line_2_Start_Range;

# define Rte_TypeDef_Line_3_Confidence
typedef uint8 Line_3_Confidence;

# define Rte_TypeDef_Line_3_Curvature
typedef uint16 Line_3_Curvature;

# define Rte_TypeDef_Line_3_Curvature_Rate
typedef uint16 Line_3_Curvature_Rate;

# define Rte_TypeDef_Line_3_End_Range
typedef uint8 Line_3_End_Range;

# define Rte_TypeDef_Line_3_Heading
typedef uint16 Line_3_Heading;

# define Rte_TypeDef_Line_3_Offset
typedef uint16 Line_3_Offset;

# define Rte_TypeDef_Line_3_Start_Range
typedef uint8 Line_3_Start_Range;

# define Rte_TypeDef_Line_4_Confidence
typedef uint8 Line_4_Confidence;

# define Rte_TypeDef_Line_4_Curvature
typedef uint16 Line_4_Curvature;

# define Rte_TypeDef_Line_4_Curvature_Rate
typedef uint16 Line_4_Curvature_Rate;

# define Rte_TypeDef_Line_4_End_Range
typedef uint8 Line_4_End_Range;

# define Rte_TypeDef_Line_4_Heading
typedef uint16 Line_4_Heading;

# define Rte_TypeDef_Line_4_Offset
typedef uint16 Line_4_Offset;

# define Rte_TypeDef_Line_4_Start_Range
typedef uint8 Line_4_Start_Range;

# define Rte_TypeDef_MessageCounter_ADAS_INFO_C2
typedef uint8 MessageCounter_ADAS_INFO_C2;

# define Rte_TypeDef_MessageCounter_AGSM2
typedef uint8 MessageCounter_AGSM2;

# define Rte_TypeDef_MessageCounter_BCM10
typedef uint8 MessageCounter_BCM10;

# define Rte_TypeDef_MessageCounter_BCM12
typedef uint8 MessageCounter_BCM12;

# define Rte_TypeDef_MessageCounter_BCM2
typedef uint8 MessageCounter_BCM2;

# define Rte_TypeDef_MessageCounter_BCM27
typedef uint8 MessageCounter_BCM27;

# define Rte_TypeDef_MessageCounter_BCM29
typedef uint8 MessageCounter_BCM29;

# define Rte_TypeDef_MessageCounter_BCM9
typedef uint8 MessageCounter_BCM9;

# define Rte_TypeDef_MessageCounter_BRAKE1
typedef uint8 MessageCounter_BRAKE1;

# define Rte_TypeDef_MessageCounter_BRAKE2
typedef uint8 MessageCounter_BRAKE2;

# define Rte_TypeDef_MessageCounter_BRAKE2_1
typedef uint8 MessageCounter_BRAKE2_1;

# define Rte_TypeDef_MessageCounter_BRAKE3
typedef uint8 MessageCounter_BRAKE3;

# define Rte_TypeDef_MessageCounter_BRAKE4
typedef uint8 MessageCounter_BRAKE4;

# define Rte_TypeDef_MessageCounter_BRAKE5
typedef uint8 MessageCounter_BRAKE5;

# define Rte_TypeDef_MessageCounter_BRAKE7
typedef uint8 MessageCounter_BRAKE7;

# define Rte_TypeDef_MessageCounter_CVPAM_FD_Control
typedef uint8 MessageCounter_CVPAM_FD_Control;

# define Rte_TypeDef_MessageCounter_CVPAM_FD_Data
typedef uint8 MessageCounter_CVPAM_FD_Data;

# define Rte_TypeDef_MessageCounter_CVPAM_FD_Data2
typedef uint8 MessageCounter_CVPAM_FD_Data2;

# define Rte_TypeDef_MessageCounter_CVPAM_FD_Info
typedef uint8 MessageCounter_CVPAM_FD_Info;

# define Rte_TypeDef_MessageCounter_DRIVETRAIN3
typedef uint8 MessageCounter_DRIVETRAIN3;

# define Rte_TypeDef_MessageCounter_ENGINE2
typedef uint8 MessageCounter_ENGINE2;

# define Rte_TypeDef_MessageCounter_ENGINE5
typedef uint8 MessageCounter_ENGINE5;

# define Rte_TypeDef_MessageCounter_ENGINE7
typedef uint8 MessageCounter_ENGINE7;

# define Rte_TypeDef_MessageCounter_EPS1
typedef uint8 MessageCounter_EPS1;

# define Rte_TypeDef_MessageCounter_EPS2
typedef uint8 MessageCounter_EPS2;

# define Rte_TypeDef_MessageCounter_GLOB_NAV_C2
typedef uint8 MessageCounter_GLOB_NAV_C2;

# define Rte_TypeDef_MessageCounter_TRANSM1
typedef uint8 MessageCounter_TRANSM1;

# define Rte_TypeDef_MessageCounter_TRANSM2
typedef uint8 MessageCounter_TRANSM2;

# define Rte_TypeDef_MessageCounter_TRANSM4
typedef uint8 MessageCounter_TRANSM4;

# define Rte_TypeDef_MessageCounter_TRSCM1
typedef uint8 MessageCounter_TRSCM1;

# define Rte_TypeDef_MessageCounter_TRSKM_FD_1
typedef uint8 MessageCounter_TRSKM_FD_1;

# define Rte_TypeDef_MessageCounter_Telematic11
typedef uint8 MessageCounter_Telematic11;

# define Rte_TypeDef_MessageCounter_Telematic14
typedef uint8 MessageCounter_Telematic14;

# define Rte_TypeDef_MessageCounter_Telematic5
typedef uint8 MessageCounter_Telematic5;

# define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;

# define Rte_TypeDef_PA_Line_LM_Distance
typedef uint16 PA_Line_LM_Distance;

# define Rte_TypeDef_PA_Line_LM_Heading
typedef uint16 PA_Line_LM_Heading;

# define Rte_TypeDef_PA_Line_RM_Distance
typedef uint16 PA_Line_RM_Distance;

# define Rte_TypeDef_PA_Line_RM_Heading
typedef uint16 PA_Line_RM_Heading;

# define Rte_TypeDef_PA_Obj1_Angle
typedef uint16 PA_Obj1_Angle;

# define Rte_TypeDef_PA_Obj1_Angle_2
typedef uint16 PA_Obj1_Angle_2;

# define Rte_TypeDef_PA_Obj1_Range
typedef uint16 PA_Obj1_Range;

# define Rte_TypeDef_PA_Obj1_Range_2
typedef uint16 PA_Obj1_Range_2;

# define Rte_TypeDef_PA_Obj2_Angle
typedef uint16 PA_Obj2_Angle;

# define Rte_TypeDef_PA_Obj2_Angle_2
typedef uint16 PA_Obj2_Angle_2;

# define Rte_TypeDef_PA_Obj2_Range
typedef uint16 PA_Obj2_Range;

# define Rte_TypeDef_PA_Obj2_Range_2
typedef uint16 PA_Obj2_Range_2;

# define Rte_TypeDef_PA_Obj3_Angle
typedef uint16 PA_Obj3_Angle;

# define Rte_TypeDef_PA_Obj3_Angle_2
typedef uint16 PA_Obj3_Angle_2;

# define Rte_TypeDef_PA_Obj3_Range
typedef uint16 PA_Obj3_Range;

# define Rte_TypeDef_PA_Obj3_Range_2
typedef uint16 PA_Obj3_Range_2;

# define Rte_TypeDef_PA_Obj4_Angle
typedef uint16 PA_Obj4_Angle;

# define Rte_TypeDef_PA_Obj4_Angle_2
typedef uint16 PA_Obj4_Angle_2;

# define Rte_TypeDef_PA_Obj4_Range
typedef uint16 PA_Obj4_Range;

# define Rte_TypeDef_PA_Obj4_Range_2
typedef uint16 PA_Obj4_Range_2;

# define Rte_TypeDef_PA_Obj5_Angle
typedef uint16 PA_Obj5_Angle;

# define Rte_TypeDef_PA_Obj5_Angle_2
typedef uint16 PA_Obj5_Angle_2;

# define Rte_TypeDef_PA_Obj5_Range
typedef uint16 PA_Obj5_Range;

# define Rte_TypeDef_PA_Obj5_Range_2
typedef uint16 PA_Obj5_Range_2;

# define Rte_TypeDef_PA_Obj6_Angle
typedef uint16 PA_Obj6_Angle;

# define Rte_TypeDef_PA_Obj6_Angle_2
typedef uint16 PA_Obj6_Angle_2;

# define Rte_TypeDef_PA_Obj6_Range
typedef uint16 PA_Obj6_Range;

# define Rte_TypeDef_PA_Obj6_Range_2
typedef uint16 PA_Obj6_Range_2;

# define Rte_TypeDef_Reserved_for_functional_safety
typedef uint16 Reserved_for_functional_safety;

# define Rte_TypeDef_Segment_1_Confidence
typedef uint8 Segment_1_Confidence;

# define Rte_TypeDef_Segment_1_ID
typedef uint8 Segment_1_ID;

# define Rte_TypeDef_Segment_1_X1
typedef uint16 Segment_1_X1;

# define Rte_TypeDef_Segment_1_X2
typedef uint16 Segment_1_X2;

# define Rte_TypeDef_Segment_1_Y1
typedef uint16 Segment_1_Y1;

# define Rte_TypeDef_Segment_1_Y2
typedef uint16 Segment_1_Y2;

# define Rte_TypeDef_Segment_2_Confidence
typedef uint8 Segment_2_Confidence;

# define Rte_TypeDef_Segment_2_ID
typedef uint8 Segment_2_ID;

# define Rte_TypeDef_Segment_2_X1
typedef uint16 Segment_2_X1;

# define Rte_TypeDef_Segment_2_X2
typedef uint16 Segment_2_X2;

# define Rte_TypeDef_Segment_2_Y1
typedef uint16 Segment_2_Y1;

# define Rte_TypeDef_Segment_2_Y2
typedef uint16 Segment_2_Y2;

# define Rte_TypeDef_Segment_3_Confidence
typedef uint8 Segment_3_Confidence;

# define Rte_TypeDef_Segment_3_ID
typedef uint8 Segment_3_ID;

# define Rte_TypeDef_Segment_3_X1
typedef uint16 Segment_3_X1;

# define Rte_TypeDef_Segment_3_X2
typedef uint16 Segment_3_X2;

# define Rte_TypeDef_Segment_3_Y1
typedef uint16 Segment_3_Y1;

# define Rte_TypeDef_Segment_3_Y2
typedef uint16 Segment_3_Y2;

# define Rte_TypeDef_Segment_4_Confidence
typedef uint8 Segment_4_Confidence;

# define Rte_TypeDef_Segment_4_ID
typedef uint8 Segment_4_ID;

# define Rte_TypeDef_Segment_4_X1
typedef uint16 Segment_4_X1;

# define Rte_TypeDef_Segment_4_X2
typedef uint16 Segment_4_X2;

# define Rte_TypeDef_Segment_4_Y1
typedef uint16 Segment_4_Y1;

# define Rte_TypeDef_Segment_4_Y2
typedef uint16 Segment_4_Y2;

# define Rte_TypeDef_Segment_5_Confidence
typedef uint8 Segment_5_Confidence;

# define Rte_TypeDef_Segment_5_ID
typedef uint8 Segment_5_ID;

# define Rte_TypeDef_Segment_5_X1
typedef uint16 Segment_5_X1;

# define Rte_TypeDef_Segment_5_X2
typedef uint16 Segment_5_X2;

# define Rte_TypeDef_Segment_5_Y1
typedef uint16 Segment_5_Y1;

# define Rte_TypeDef_Segment_5_Y2
typedef uint16 Segment_5_Y2;

# define Rte_TypeDef_Segment_6_Confidence
typedef uint8 Segment_6_Confidence;

# define Rte_TypeDef_Segment_6_ID
typedef uint8 Segment_6_ID;

# define Rte_TypeDef_Segment_6_X1
typedef uint16 Segment_6_X1;

# define Rte_TypeDef_Segment_6_X2
typedef uint16 Segment_6_X2;

# define Rte_TypeDef_Segment_6_Y1
typedef uint16 Segment_6_Y1;

# define Rte_TypeDef_Segment_6_Y2
typedef uint16 Segment_6_Y2;

# define Rte_TypeDef_Segment_7_Confidence
typedef uint8 Segment_7_Confidence;

# define Rte_TypeDef_Segment_7_ID
typedef uint8 Segment_7_ID;

# define Rte_TypeDef_Segment_7_X1
typedef uint16 Segment_7_X1;

# define Rte_TypeDef_Segment_7_X2
typedef uint16 Segment_7_X2;

# define Rte_TypeDef_Segment_7_Y1
typedef uint16 Segment_7_Y1;

# define Rte_TypeDef_Segment_7_Y2
typedef uint16 Segment_7_Y2;

# define Rte_TypeDef_Segment_8_Confidence
typedef uint8 Segment_8_Confidence;

# define Rte_TypeDef_Segment_8_ID
typedef uint8 Segment_8_ID;

# define Rte_TypeDef_Segment_8_X1
typedef uint16 Segment_8_X1;

# define Rte_TypeDef_Segment_8_X2
typedef uint16 Segment_8_X2;

# define Rte_TypeDef_Segment_8_Y1
typedef uint16 Segment_8_Y1;

# define Rte_TypeDef_Segment_8_Y2
typedef uint16 Segment_8_Y2;

# define Rte_TypeDef_THA_SteeringDamping
typedef uint8 THA_SteeringDamping;

# define Rte_TypeDef_THA_SteeringTorqueInfo
typedef uint16 THA_SteeringTorqueInfo;

# define Rte_TypeDef_TRSC_RawKnob
typedef uint16 TRSC_RawKnob;

# define Rte_TypeDef_TRSC_SteeringTorqueInfo
typedef uint16 TRSC_SteeringTorqueInfo;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_TotalOdometer
typedef uint32 TotalOdometer;

# define Rte_TypeDef_Trailer_Angle
typedef uint8 Trailer_Angle;

# define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;

# define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;

# define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;

# define Rte_TypeDef_bool_t
typedef boolean bool_t;

# define Rte_TypeDef_char_T
typedef sint8 char_T;

# define Rte_TypeDef_real32_T
typedef float32 real32_T;

# define Rte_TypeDef_sint16_t
typedef sint16 sint16_t;

# define Rte_TypeDef_APARequestSts
typedef boolean APARequestSts;

# define Rte_TypeDef_AP_HMI_BottomBlackBanner_t
typedef uint32 AP_HMI_BottomBlackBanner_t;

# define Rte_TypeDef_AP_HMI_Fullscreen_t
typedef uint32 AP_HMI_Fullscreen_t;

# define Rte_TypeDef_AP_HMI_TopBlackBanner_t
typedef uint32 AP_HMI_TopBlackBanner_t;

# define Rte_TypeDef_AP_HMI_TopRedBanner_t
typedef uint32 AP_HMI_TopRedBanner_t;

# define Rte_TypeDef_ASCM_Stat
typedef uint8 ASCM_Stat;

# define Rte_TypeDef_ASCM_SysFail
typedef boolean ASCM_SysFail;

# define Rte_TypeDef_AUXCamsRQSts
typedef boolean AUXCamsRQSts;

# define Rte_TypeDef_Active_Park_Mode
typedef boolean Active_Park_Mode;

# define Rte_TypeDef_Active_Park_Prox_Chime
typedef boolean Active_Park_Prox_Chime;

# define Rte_TypeDef_Alert_CHF
typedef uint8 Alert_CHF;

# define Rte_TypeDef_Alert_CHR
typedef uint8 Alert_CHR;

# define Rte_TypeDef_Alert_LHF
typedef uint8 Alert_LHF;

# define Rte_TypeDef_Alert_LHR
typedef uint8 Alert_LHR;

# define Rte_TypeDef_Alert_RHF
typedef uint8 Alert_RHF;

# define Rte_TypeDef_Alert_RHR
typedef uint8 Alert_RHR;

# define Rte_TypeDef_Altitude_RMSE_C2
typedef uint8 Altitude_RMSE_C2;

# define Rte_TypeDef_BSM_THA_Brk_Resp
typedef uint8 BSM_THA_Brk_Resp;

# define Rte_TypeDef_Backup_Cam_Delay
typedef boolean Backup_Cam_Delay;

# define Rte_TypeDef_Battery_Volt_1
typedef uint16 Battery_Volt_1;

# define Rte_TypeDef_Brk_Stat
typedef uint8 Brk_Stat;

# define Rte_TypeDef_BswM_BswM_PreviousNMState
typedef uint8 BswM_BswM_PreviousNMState;

# define Rte_TypeDef_BswM_CalDataProSCCalStatus
typedef uint8 BswM_CalDataProSCCalStatus;

# define Rte_TypeDef_BswM_DtcSettingClearFlagModeGrp
typedef uint8 BswM_DtcSettingClearFlagModeGrp;

# define Rte_TypeDef_BswM_ESH_Mode
typedef uint8 BswM_ESH_Mode;

# define Rte_TypeDef_BswM_ESH_RunRequest
typedef uint8 BswM_ESH_RunRequest;

# define Rte_TypeDef_CM_TCH_STAT
typedef uint8 CM_TCH_STAT;

# define Rte_TypeDef_CalibrationState_DID_t
typedef uint32 CalibrationState_DID_t;

# define Rte_TypeDef_CalibrationState_t
typedef uint32 CalibrationState_t;

# define Rte_TypeDef_CameraDisplaySts2
typedef uint8 CameraDisplaySts2;

# define Rte_TypeDef_CameraStatus_t
typedef uint32 CameraStatus_t;

# define Rte_TypeDef_Camera_Status
typedef uint8 Camera_Status;

# define Rte_TypeDef_CanDebugMode_t
typedef uint32 CanDebugMode_t;

# define Rte_TypeDef_ChimeActivation_LHF
typedef boolean ChimeActivation_LHF;

# define Rte_TypeDef_ChimeActivation_LHR
typedef boolean ChimeActivation_LHR;

# define Rte_TypeDef_ChimeActivation_RHF
typedef boolean ChimeActivation_RHF;

# define Rte_TypeDef_ChimeActivation_RHR
typedef boolean ChimeActivation_RHR;

# define Rte_TypeDef_CmdIgnSts
typedef uint8 CmdIgnSts;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_CplrDetStatus_e
typedef uint32 CplrDetStatus_e;

# define Rte_TypeDef_Crypto_OperationModeType
typedef uint8 Crypto_OperationModeType;

# define Rte_TypeDef_Crypto_ResultType
typedef uint8 Crypto_ResultType;

# define Rte_TypeDef_Crypto_VerifyResultType
typedef uint8 Crypto_VerifyResultType;

# define Rte_TypeDef_Csm_KeyElementEnumType
typedef uint32 Csm_KeyElementEnumType;

# define Rte_TypeDef_Csm_ResultType
typedef uint8 Csm_ResultType;

# define Rte_TypeDef_Csm_VerifyResultType
typedef uint8 Csm_VerifyResultType;

# define Rte_TypeDef_CurrentCanNMState_FD01_BCM
typedef uint8 CurrentCanNMState_FD01_BCM;

# define Rte_TypeDef_CurrentCanNMState_FD01_SGW
typedef uint8 CurrentCanNMState_FD01_SGW;

# define Rte_TypeDef_CurrentCanNMState_FD02_BCM
typedef uint8 CurrentCanNMState_FD02_BCM;

# define Rte_TypeDef_CurrentCanNMState_FD02_BSM2
typedef uint8 CurrentCanNMState_FD02_BSM2;

# define Rte_TypeDef_CurrentCanNMState_FD02_CADM2
typedef uint8 CurrentCanNMState_FD02_CADM2;

# define Rte_TypeDef_CurrentCanNMState_FD02_EPS
typedef uint8 CurrentCanNMState_FD02_EPS;

# define Rte_TypeDef_CurrentCanNMState_FD02_ORC
typedef uint8 CurrentCanNMState_FD02_ORC;

# define Rte_TypeDef_CurrentCanNMState_FD02_PAM
typedef uint8 CurrentCanNMState_FD02_PAM;

# define Rte_TypeDef_CurrentCanNMState_FD02_SGW
typedef uint8 CurrentCanNMState_FD02_SGW;

# define Rte_TypeDef_CurrentCanNMState_FD02_TRLR_REV
typedef uint8 CurrentCanNMState_FD02_TRLR_REV;

# define Rte_TypeDef_CurrentCanNMState_FD03_BCM
typedef uint8 CurrentCanNMState_FD03_BCM;

# define Rte_TypeDef_CurrentCanNMState_FD03_SGW
typedef uint8 CurrentCanNMState_FD03_SGW;

# define Rte_TypeDef_CurrentCanNMState_FD04_BCM
typedef uint8 CurrentCanNMState_FD04_BCM;

# define Rte_TypeDef_CurrentCanNMState_FD08_SGW
typedef uint8 CurrentCanNMState_FD08_SGW;

# define Rte_TypeDef_CurrentCanNMState_FD11_SGW
typedef uint8 CurrentCanNMState_FD11_SGW;

# define Rte_TypeDef_CurrentFailSts_FD01_BCM
typedef boolean CurrentFailSts_FD01_BCM;

# define Rte_TypeDef_CurrentFailSts_FD01_SGW
typedef boolean CurrentFailSts_FD01_SGW;

# define Rte_TypeDef_CurrentFailSts_FD02_BCM
typedef boolean CurrentFailSts_FD02_BCM;

# define Rte_TypeDef_CurrentFailSts_FD02_BSM2
typedef boolean CurrentFailSts_FD02_BSM2;

# define Rte_TypeDef_CurrentFailSts_FD02_CADM2
typedef boolean CurrentFailSts_FD02_CADM2;

# define Rte_TypeDef_CurrentFailSts_FD02_EPS
typedef boolean CurrentFailSts_FD02_EPS;

# define Rte_TypeDef_CurrentFailSts_FD02_ORC
typedef boolean CurrentFailSts_FD02_ORC;

# define Rte_TypeDef_CurrentFailSts_FD02_PAM
typedef boolean CurrentFailSts_FD02_PAM;

# define Rte_TypeDef_CurrentFailSts_FD02_SGW
typedef boolean CurrentFailSts_FD02_SGW;

# define Rte_TypeDef_CurrentFailSts_FD02_TRLR_REV
typedef boolean CurrentFailSts_FD02_TRLR_REV;

# define Rte_TypeDef_CurrentFailSts_FD03_BCM
typedef boolean CurrentFailSts_FD03_BCM;

# define Rte_TypeDef_CurrentFailSts_FD03_SGW
typedef boolean CurrentFailSts_FD03_SGW;

# define Rte_TypeDef_CurrentFailSts_FD04_BCM
typedef boolean CurrentFailSts_FD04_BCM;

# define Rte_TypeDef_CurrentFailSts_FD08_SGW
typedef boolean CurrentFailSts_FD08_SGW;

# define Rte_TypeDef_CurrentFailSts_FD11_SGW
typedef boolean CurrentFailSts_FD11_SGW;

# define Rte_TypeDef_DES_FD01_BCM
typedef uint8 DES_FD01_BCM;

# define Rte_TypeDef_DES_FD01_SGW
typedef uint8 DES_FD01_SGW;

# define Rte_TypeDef_DES_FD02_BCM
typedef uint8 DES_FD02_BCM;

# define Rte_TypeDef_DES_FD02_BSM2
typedef uint8 DES_FD02_BSM2;

# define Rte_TypeDef_DES_FD02_CADM2
typedef uint8 DES_FD02_CADM2;

# define Rte_TypeDef_DES_FD02_EPS
typedef uint8 DES_FD02_EPS;

# define Rte_TypeDef_DES_FD02_ORC
typedef uint8 DES_FD02_ORC;

# define Rte_TypeDef_DES_FD02_PAM
typedef uint8 DES_FD02_PAM;

# define Rte_TypeDef_DES_FD02_SGW
typedef uint8 DES_FD02_SGW;

# define Rte_TypeDef_DES_FD02_TRLR_REV
typedef uint8 DES_FD02_TRLR_REV;

# define Rte_TypeDef_DES_FD03_BCM
typedef uint8 DES_FD03_BCM;

# define Rte_TypeDef_DES_FD03_SGW
typedef uint8 DES_FD03_SGW;

# define Rte_TypeDef_DES_FD04_BCM
typedef uint8 DES_FD04_BCM;

# define Rte_TypeDef_DES_FD08_SGW
typedef uint8 DES_FD08_SGW;

# define Rte_TypeDef_DES_FD11_SGW
typedef uint8 DES_FD11_SGW;

# define Rte_TypeDef_DLDCamSts_t
typedef uint32 DLDCamSts_t;

# define Rte_TypeDef_Dcm_CommunicationModeType
typedef uint8 Dcm_CommunicationModeType;

# define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;

# define Rte_TypeDef_Dcm_ControlDtcSettingType
typedef uint8 Dcm_ControlDtcSettingType;

# define Rte_TypeDef_Dcm_DiagnosticSessionControlType
typedef uint8 Dcm_DiagnosticSessionControlType;

# define Rte_TypeDef_Dcm_EcuResetType
typedef uint8 Dcm_EcuResetType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

# define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;

# define Rte_TypeDef_Dcm_RequestKindType
typedef uint8 Dcm_RequestKindType;

# define Rte_TypeDef_Dcm_SecLevelType
typedef uint8 Dcm_SecLevelType;

# define Rte_TypeDef_Dcm_SesCtrlType
typedef uint8 Dcm_SesCtrlType;

# define Rte_TypeDef_DeltaTimestamp_IMUdata
typedef uint8 DeltaTimestamp_IMUdata;

# define Rte_TypeDef_Dem_DTCFormatType
typedef uint8 Dem_DTCFormatType;

# define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;

# define Rte_TypeDef_Dem_DTCOriginType
typedef uint16 Dem_DTCOriginType;

# define Rte_TypeDef_Dem_DTCSeverityType
typedef uint8 Dem_DTCSeverityType;

# define Rte_TypeDef_Dem_DTRControlType
typedef uint8 Dem_DTRControlType;

# define Rte_TypeDef_Dem_DebounceResetStatusType
typedef uint8 Dem_DebounceResetStatusType;

# define Rte_TypeDef_Dem_DebouncingStateType
typedef uint8 Dem_DebouncingStateType;

# define Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;

# define Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;

# define Rte_TypeDef_Dem_InitMonitorReasonType
typedef uint8 Dem_InitMonitorReasonType;

# define Rte_TypeDef_Dem_IumprDenomCondIdType
typedef uint8 Dem_IumprDenomCondIdType;

# define Rte_TypeDef_Dem_IumprDenomCondStatusType
typedef uint8 Dem_IumprDenomCondStatusType;

# define Rte_TypeDef_Dem_IumprReadinessGroupType
typedef uint8 Dem_IumprReadinessGroupType;

# define Rte_TypeDef_Dem_MonitorStatusType
typedef uint8 Dem_MonitorStatusType;

# define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;

# define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;

# define Rte_TypeDef_DetectionFailInfo_DID_t
typedef uint32 DetectionFailInfo_DID_t;

# define Rte_TypeDef_DetectionFailInfo_t
typedef uint32 DetectionFailInfo_t;

# define Rte_TypeDef_DisplayView2
typedef uint8 DisplayView2;

# define Rte_TypeDef_DriverDoorSts
typedef boolean DriverDoorSts;

# define Rte_TypeDef_DynamicGrid
typedef boolean DynamicGrid;

# define Rte_TypeDef_E2E_MEP_CheckStatusType
typedef uint8 E2E_MEP_CheckStatusType;

# define Rte_TypeDef_E2E_MEP_DataIDMode
typedef uint8 E2E_MEP_DataIDMode;

# define Rte_TypeDef_ECM_THA_Resp
typedef uint8 ECM_THA_Resp;

# define Rte_TypeDef_ECM_TRSC_Resp
typedef uint8 ECM_TRSC_Resp;

# define Rte_TypeDef_EOL_FD01_BCM
typedef boolean EOL_FD01_BCM;

# define Rte_TypeDef_EOL_FD01_SGW
typedef boolean EOL_FD01_SGW;

# define Rte_TypeDef_EOL_FD02_BCM
typedef boolean EOL_FD02_BCM;

# define Rte_TypeDef_EOL_FD02_BSM2
typedef boolean EOL_FD02_BSM2;

# define Rte_TypeDef_EOL_FD02_CADM2
typedef boolean EOL_FD02_CADM2;

# define Rte_TypeDef_EOL_FD02_EPS
typedef boolean EOL_FD02_EPS;

# define Rte_TypeDef_EOL_FD02_ORC
typedef boolean EOL_FD02_ORC;

# define Rte_TypeDef_EOL_FD02_PAM
typedef boolean EOL_FD02_PAM;

# define Rte_TypeDef_EOL_FD02_SGW
typedef boolean EOL_FD02_SGW;

# define Rte_TypeDef_EOL_FD02_TRLR_REV
typedef boolean EOL_FD02_TRLR_REV;

# define Rte_TypeDef_EOL_FD03_BCM
typedef boolean EOL_FD03_BCM;

# define Rte_TypeDef_EOL_FD03_SGW
typedef boolean EOL_FD03_SGW;

# define Rte_TypeDef_EOL_FD04_BCM
typedef boolean EOL_FD04_BCM;

# define Rte_TypeDef_EOL_FD08_SGW
typedef boolean EOL_FD08_SGW;

# define Rte_TypeDef_EOL_FD11_SGW
typedef boolean EOL_FD11_SGW;

# define Rte_TypeDef_EPBSts
typedef uint8 EPBSts;

# define Rte_TypeDef_EPS_SteeringTouchStat
typedef boolean EPS_SteeringTouchStat;

# define Rte_TypeDef_EPS_SteeringTouq_Resp
typedef uint8 EPS_SteeringTouq_Resp;

# define Rte_TypeDef_EPS_THA_DriverTorqueOverride
typedef uint8 EPS_THA_DriverTorqueOverride;

# define Rte_TypeDef_EPS_THA_SteeringTorqueResp
typedef uint8 EPS_THA_SteeringTorqueResp;

# define Rte_TypeDef_ESS_ENG_ST_W
typedef uint8 ESS_ENG_ST_W;

# define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;

# define Rte_TypeDef_EcuM_ModeType
typedef uint8 EcuM_ModeType;

# define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;

# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;

# define Rte_TypeDef_EngineSts_W
typedef uint8 EngineSts_W;

# define Rte_TypeDef_ErrorMgr_enErrorNo
typedef uint32 ErrorMgr_enErrorNo;

# define Rte_TypeDef_ErrorMgr_enErrorStatus
typedef uint32 ErrorMgr_enErrorStatus;

# define Rte_TypeDef_ExternalTemperature
typedef uint16 ExternalTemperature;

# define Rte_TypeDef_FD01_BCM_64
typedef uint64 FD01_BCM_64;

# define Rte_TypeDef_FD01_SGW_64
typedef uint64 FD01_SGW_64;

# define Rte_TypeDef_FD02_BCM_64
typedef uint64 FD02_BCM_64;

# define Rte_TypeDef_FD02_BSM2_64
typedef uint64 FD02_BSM2_64;

# define Rte_TypeDef_FD02_EPS_64
typedef uint64 FD02_EPS_64;

# define Rte_TypeDef_FD02_ORC_64
typedef uint64 FD02_ORC_64;

# define Rte_TypeDef_FD02_SGW_64
typedef uint64 FD02_SGW_64;

# define Rte_TypeDef_FD03_BCM_64
typedef uint64 FD03_BCM_64;

# define Rte_TypeDef_FD03_SGW_64
typedef uint64 FD03_SGW_64;

# define Rte_TypeDef_FD04_BCM_64
typedef uint64 FD04_BCM_64;

# define Rte_TypeDef_FD08_SGW_64
typedef uint64 FD08_SGW_64;

# define Rte_TypeDef_FD11_SGW_64
typedef uint64 FD11_SGW_64;

# define Rte_TypeDef_FD14_ACC_Systemsts
typedef uint8 FD14_ACC_Systemsts;

# define Rte_TypeDef_FD14_AOL_Blockage
typedef boolean FD14_AOL_Blockage;

# define Rte_TypeDef_FD14_AOR_Blockage
typedef boolean FD14_AOR_Blockage;

# define Rte_TypeDef_FD14_Accel_Pedal_Override
typedef boolean FD14_Accel_Pedal_Override;

# define Rte_TypeDef_FD14_BOL_Blockage
typedef boolean FD14_BOL_Blockage;

# define Rte_TypeDef_FD14_BOR_Blockage
typedef boolean FD14_BOR_Blockage;

# define Rte_TypeDef_FD14_BSM_THA_Brk_Resp
typedef uint8 FD14_BSM_THA_Brk_Resp;

# define Rte_TypeDef_FD14_BrkPdl_Stat
typedef uint8 FD14_BrkPdl_Stat;

# define Rte_TypeDef_FD14_BrkTrq
typedef uint16 FD14_BrkTrq;

# define Rte_TypeDef_FD14_BrkTrq_Driver
typedef uint16 FD14_BrkTrq_Driver;

# define Rte_TypeDef_FD14_Brk_Stat
typedef uint8 FD14_Brk_Stat;

# define Rte_TypeDef_FD14_CalibStatus_STM_Current_Front
typedef uint8 FD14_CalibStatus_STM_Current_Front;

# define Rte_TypeDef_FD14_CalibStatus_STM_Current_Left
typedef uint8 FD14_CalibStatus_STM_Current_Left;

# define Rte_TypeDef_FD14_CalibStatus_STM_Current_Rear
typedef uint8 FD14_CalibStatus_STM_Current_Rear;

# define Rte_TypeDef_FD14_CalibStatus_STM_Current_Right
typedef uint8 FD14_CalibStatus_STM_Current_Right;

# define Rte_TypeDef_FD14_CalibStatus_STM_EOL_Front
typedef uint8 FD14_CalibStatus_STM_EOL_Front;

# define Rte_TypeDef_FD14_CalibStatus_STM_EOL_Left
typedef uint8 FD14_CalibStatus_STM_EOL_Left;

# define Rte_TypeDef_FD14_CalibStatus_STM_EOL_Rear
typedef uint8 FD14_CalibStatus_STM_EOL_Rear;

# define Rte_TypeDef_FD14_CalibStatus_STM_EOL_Right
typedef uint8 FD14_CalibStatus_STM_EOL_Right;

# define Rte_TypeDef_FD14_CalibStatus_STM_OC_Front
typedef uint8 FD14_CalibStatus_STM_OC_Front;

# define Rte_TypeDef_FD14_CalibStatus_STM_OC_Left
typedef uint8 FD14_CalibStatus_STM_OC_Left;

# define Rte_TypeDef_FD14_CalibStatus_STM_OC_Rear
typedef uint8 FD14_CalibStatus_STM_OC_Rear;

# define Rte_TypeDef_FD14_CalibStatus_STM_OC_Right
typedef uint8 FD14_CalibStatus_STM_OC_Right;

# define Rte_TypeDef_FD14_CalibStatus_STM_SC_Front
typedef uint8 FD14_CalibStatus_STM_SC_Front;

# define Rte_TypeDef_FD14_CalibStatus_STM_SC_Left
typedef uint8 FD14_CalibStatus_STM_SC_Left;

# define Rte_TypeDef_FD14_CalibStatus_STM_SC_Rear
typedef uint8 FD14_CalibStatus_STM_SC_Rear;

# define Rte_TypeDef_FD14_CalibStatus_STM_SC_Right
typedef uint8 FD14_CalibStatus_STM_SC_Right;

# define Rte_TypeDef_FD14_CameraDisplaySts2_e
typedef uint8 FD14_CameraDisplaySts2_e;

# define Rte_TypeDef_FD14_Camera_Status
typedef uint8 FD14_Camera_Status;

# define Rte_TypeDef_FD14_CsmLocalErrOrEventState
typedef uint8 FD14_CsmLocalErrOrEventState;

# define Rte_TypeDef_FD14_CsmLocalModuleId
typedef uint8 FD14_CsmLocalModuleId;

# define Rte_TypeDef_FD14_CsmStateCurrent
typedef uint8 FD14_CsmStateCurrent;

# define Rte_TypeDef_FD14_CsmStatePrevious
typedef uint8 FD14_CsmStatePrevious;

# define Rte_TypeDef_FD14_Curr_DisplayedViewByAcore_e
typedef uint8 FD14_Curr_DisplayedViewByAcore_e;

# define Rte_TypeDef_FD14_Curr_RequestedViewByHmiM_e
typedef uint8 FD14_Curr_RequestedViewByHmiM_e;

# define Rte_TypeDef_FD14_Curr_SystemState_e
typedef uint8 FD14_Curr_SystemState_e;

# define Rte_TypeDef_FD14_Curr_TRG_Stat
typedef uint8 FD14_Curr_TRG_Stat;

# define Rte_TypeDef_FD14_DriverReq_AxleTrq_Enabled_BSM
typedef uint8 FD14_DriverReq_AxleTrq_Enabled_BSM;

# define Rte_TypeDef_FD14_DynOvl_Error_e
typedef boolean FD14_DynOvl_Error_e;

# define Rte_TypeDef_FD14_ECM_THA_Resp
typedef uint8 FD14_ECM_THA_Resp;

# define Rte_TypeDef_FD14_ECM_TRSC_Resp
typedef uint8 FD14_ECM_TRSC_Resp;

# define Rte_TypeDef_FD14_EOL_ModuleState_STM_Front
typedef uint8 FD14_EOL_ModuleState_STM_Front;

# define Rte_TypeDef_FD14_EOL_ModuleState_STM_Left
typedef uint8 FD14_EOL_ModuleState_STM_Left;

# define Rte_TypeDef_FD14_EOL_ModuleState_STM_Rear
typedef uint8 FD14_EOL_ModuleState_STM_Rear;

# define Rte_TypeDef_FD14_EOL_ModuleState_STM_Right
typedef uint8 FD14_EOL_ModuleState_STM_Right;

# define Rte_TypeDef_FD14_EPBSts
typedef uint8 FD14_EPBSts;

# define Rte_TypeDef_FD14_EPS_HandsOnRecognition
typedef boolean FD14_EPS_HandsOnRecognition;

# define Rte_TypeDef_FD14_EPS_SteeringTouchStat
typedef boolean FD14_EPS_SteeringTouchStat;

# define Rte_TypeDef_FD14_EPS_SteeringTouq_Resp
typedef uint8 FD14_EPS_SteeringTouq_Resp;

# define Rte_TypeDef_FD14_EPS_THA_DriverTorqueOverride
typedef uint8 FD14_EPS_THA_DriverTorqueOverride;

# define Rte_TypeDef_FD14_EPS_THA_SteeringTorqueResp
typedef uint8 FD14_EPS_THA_SteeringTorqueResp;

# define Rte_TypeDef_FD14_ESC_TRSC_Brk_Resp
typedef uint8 FD14_ESC_TRSC_Brk_Resp;

# define Rte_TypeDef_FD14_ESS_ENG_ST_W
typedef uint8 FD14_ESS_ENG_ST_W;

# define Rte_TypeDef_FD14_EngineSts_W
typedef uint8 FD14_EngineSts_W;

# define Rte_TypeDef_FD14_Err_Code_EOL_Front
typedef uint8 FD14_Err_Code_EOL_Front;

# define Rte_TypeDef_FD14_Err_Code_EOL_Left
typedef uint8 FD14_Err_Code_EOL_Left;

# define Rte_TypeDef_FD14_Err_Code_EOL_Rear
typedef uint8 FD14_Err_Code_EOL_Rear;

# define Rte_TypeDef_FD14_Err_Code_EOL_Rear_Copy_1
typedef uint8 FD14_Err_Code_EOL_Rear_Copy_1;

# define Rte_TypeDef_FD14_Err_Code_OC_Front
typedef uint8 FD14_Err_Code_OC_Front;

# define Rte_TypeDef_FD14_Err_Code_OC_Left
typedef uint8 FD14_Err_Code_OC_Left;

# define Rte_TypeDef_FD14_Err_Code_OC_Rear
typedef uint8 FD14_Err_Code_OC_Rear;

# define Rte_TypeDef_FD14_Err_Code_OC_Right
typedef uint8 FD14_Err_Code_OC_Right;

# define Rte_TypeDef_FD14_Err_Code_SC_Front
typedef uint8 FD14_Err_Code_SC_Front;

# define Rte_TypeDef_FD14_Err_Code_SC_Left
typedef uint8 FD14_Err_Code_SC_Left;

# define Rte_TypeDef_FD14_Err_Code_SC_Rear
typedef uint8 FD14_Err_Code_SC_Rear;

# define Rte_TypeDef_FD14_Err_Code_SC_Right
typedef uint8 FD14_Err_Code_SC_Right;

# define Rte_TypeDef_FD14_ExternalBrkRequestsDisabled
typedef uint8 FD14_ExternalBrkRequestsDisabled;

# define Rte_TypeDef_FD14_FIL_Blockage
typedef boolean FD14_FIL_Blockage;

# define Rte_TypeDef_FD14_FIR_Blockage
typedef boolean FD14_FIR_Blockage;

# define Rte_TypeDef_FD14_FOD_Confidence
typedef uint8 FD14_FOD_Confidence;

# define Rte_TypeDef_FD14_FOL_Blockage
typedef boolean FD14_FOL_Blockage;

# define Rte_TypeDef_FD14_FOR_Blockage
typedef boolean FD14_FOR_Blockage;

# define Rte_TypeDef_FD14_FSL_Blockage
typedef boolean FD14_FSL_Blockage;

# define Rte_TypeDef_FD14_FSR_Blockage
typedef boolean FD14_FSR_Blockage;

# define Rte_TypeDef_FD14_FrontSensorDetHealth_e
typedef uint8 FD14_FrontSensorDetHealth_e;

# define Rte_TypeDef_FD14_HAS_Status
typedef uint8 FD14_HAS_Status;

# define Rte_TypeDef_FD14_Health_Front_Object_Detection
typedef uint8 FD14_Health_Front_Object_Detection;

# define Rte_TypeDef_FD14_Health_Lane_Detection
typedef uint8 FD14_Health_Lane_Detection;

# define Rte_TypeDef_FD14_IeAP_e_AutoParkStatus
typedef uint8 FD14_IeAP_e_AutoParkStatus;

# define Rte_TypeDef_FD14_IeAutoPark_e_AlgoState
typedef uint8 FD14_IeAutoPark_e_AlgoState;

# define Rte_TypeDef_FD14_IeTRSC_e_CamBlockSts
typedef uint8 FD14_IeTRSC_e_CamBlockSts;

# define Rte_TypeDef_FD14_IeTRSC_e_GearShiftSts
typedef uint8 FD14_IeTRSC_e_GearShiftSts;

# define Rte_TypeDef_FD14_IeTRSC_e_TRSCAbortReas
typedef uint32 FD14_IeTRSC_e_TRSCAbortReas;

# define Rte_TypeDef_FD14_IeTRSC_e_TRSCUnavailReas
typedef uint32 FD14_IeTRSC_e_TRSCUnavailReas;

# define Rte_TypeDef_FD14_IeTRSC_e_TRSKMBtnSts
typedef uint8 FD14_IeTRSC_e_TRSKMBtnSts;

# define Rte_TypeDef_FD14_IeTRSC_e_TRSKMCenBtnSts
typedef uint8 FD14_IeTRSC_e_TRSKMCenBtnSts;

# define Rte_TypeDef_FD14_IeTRSC_e_TRSKMSts
typedef uint8 FD14_IeTRSC_e_TRSKMSts;

# define Rte_TypeDef_FD14_IeTRSC_e_TrailerID
typedef uint8 FD14_IeTRSC_e_TrailerID;

# define Rte_TypeDef_FD14_IeTRSC_e_TrlrAngGrapOverSts
typedef uint32 FD14_IeTRSC_e_TrlrAngGrapOverSts;

# define Rte_TypeDef_FD14_IeTRSC_e_TrlrCalibFailReas
typedef uint8 FD14_IeTRSC_e_TrlrCalibFailReas;

# define Rte_TypeDef_FD14_IeTRSC_e_TrlrCalibManState
typedef uint8 FD14_IeTRSC_e_TrlrCalibManState;

# define Rte_TypeDef_FD14_IeTRSC_e_TrlrCalibSts
typedef uint8 FD14_IeTRSC_e_TrlrCalibSts;

# define Rte_TypeDef_FD14_IeTRSC_e_TrlrPrsntFailReas
typedef uint8 FD14_IeTRSC_e_TrlrPrsntFailReas;

# define Rte_TypeDef_FD14_IeTRSC_e_TrlrPrsntSts
typedef uint8 FD14_IeTRSC_e_TrlrPrsntSts;

# define Rte_TypeDef_FD14_IeTRSC_e_TrlrRecogInfo
typedef uint8 FD14_IeTRSC_e_TrlrRecogInfo;

# define Rte_TypeDef_FD14_ImageDefeat_Error_e
typedef uint8 FD14_ImageDefeat_Error_e;

# define Rte_TypeDef_FD14_LHFWheelSpeed
typedef uint16 FD14_LHFWheelSpeed;

# define Rte_TypeDef_FD14_LHF_FastPulseCounter
typedef uint8 FD14_LHF_FastPulseCounter;

# define Rte_TypeDef_FD14_LHF_Spin
typedef uint8 FD14_LHF_Spin;

# define Rte_TypeDef_FD14_LHF_WheelSensorFailSts
typedef boolean FD14_LHF_WheelSensorFailSts;

# define Rte_TypeDef_FD14_LHRWheelSpeed
typedef uint16 FD14_LHRWheelSpeed;

# define Rte_TypeDef_FD14_LHR_FastPulseCounter
typedef uint8 FD14_LHR_FastPulseCounter;

# define Rte_TypeDef_FD14_LHR_Spin
typedef uint8 FD14_LHR_Spin;

# define Rte_TypeDef_FD14_LHR_WheelSensorFailSts
typedef boolean FD14_LHR_WheelSensorFailSts;

# define Rte_TypeDef_FD14_LastViewBeforeTestPattern_e
typedef uint8 FD14_LastViewBeforeTestPattern_e;

# define Rte_TypeDef_FD14_LatAccelerationFailSts_BSM
typedef boolean FD14_LatAccelerationFailSts_BSM;

# define Rte_TypeDef_FD14_LatAccelerationOffset_BSM
typedef uint8 FD14_LatAccelerationOffset_BSM;

# define Rte_TypeDef_FD14_LatAcceleration_BSM
typedef uint16 FD14_LatAcceleration_BSM;

# define Rte_TypeDef_FD14_Line_1_Type
typedef uint8 FD14_Line_1_Type;

# define Rte_TypeDef_FD14_Line_2_Type
typedef uint8 FD14_Line_2_Type;

# define Rte_TypeDef_FD14_Line_3_Type
typedef uint8 FD14_Line_3_Type;

# define Rte_TypeDef_FD14_Line_4_Type
typedef uint8 FD14_Line_4_Type;

# define Rte_TypeDef_FD14_LongAccelerationFailSts_BSM
typedef boolean FD14_LongAccelerationFailSts_BSM;

# define Rte_TypeDef_FD14_LongAccelerationOffset_BSM
typedef uint8 FD14_LongAccelerationOffset_BSM;

# define Rte_TypeDef_FD14_LongAcceleration_BSM
typedef uint16 FD14_LongAcceleration_BSM;

# define Rte_TypeDef_FD14_LwsAngle
typedef uint16 FD14_LwsAngle;

# define Rte_TypeDef_FD14_LwsAngleType
typedef uint8 FD14_LwsAngleType;

# define Rte_TypeDef_FD14_LwsSpeed
typedef uint16 FD14_LwsSpeed;

# define Rte_TypeDef_FD14_M_BURV_Memory_e
typedef boolean FD14_M_BURV_Memory_e;

# define Rte_TypeDef_FD14_M_FFClatch_e
typedef boolean FD14_M_FFClatch_e;

# define Rte_TypeDef_FD14_ManoeuvrePhase
typedef boolean FD14_ManoeuvrePhase;

# define Rte_TypeDef_FD14_MeAP_e_ParkAssistStatus
typedef uint8 FD14_MeAP_e_ParkAssistStatus;

# define Rte_TypeDef_FD14_MeSVS_e_DispView2Info
typedef uint16 FD14_MeSVS_e_DispView2Info;

# define Rte_TypeDef_FD14_MeTRSC_e_CalFail
typedef uint8 FD14_MeTRSC_e_CalFail;

# define Rte_TypeDef_FD14_MeTRSC_e_TADCalibrationSubstate
typedef uint8 FD14_MeTRSC_e_TADCalibrationSubstate;

# define Rte_TypeDef_FD14_MeTRSC_e_TADState
typedef uint8 FD14_MeTRSC_e_TADState;

# define Rte_TypeDef_FD14_MeTRSC_e_TRSCStat
typedef uint8 FD14_MeTRSC_e_TRSCStat;

# define Rte_TypeDef_FD14_MeTRSC_e_TrailerID
typedef uint8 FD14_MeTRSC_e_TrailerID;

# define Rte_TypeDef_FD14_MeTRSC_e_TrlrAngSign
typedef boolean FD14_MeTRSC_e_TrlrAngSign;

# define Rte_TypeDef_FD14_MeTRSC_e_TrlrCalInfo
typedef boolean FD14_MeTRSC_e_TrlrCalInfo;

# define Rte_TypeDef_FD14_MeTRSC_e_TrlrPrsntInfo
typedef boolean FD14_MeTRSC_e_TrlrPrsntInfo;

# define Rte_TypeDef_FD14_MeTRSC_e_TrlrPrsntInfoCAN
typedef uint8 FD14_MeTRSC_e_TrlrPrsntInfoCAN;

# define Rte_TypeDef_FD14_MeTRSC_e_TrlrRecogInfo
typedef boolean FD14_MeTRSC_e_TrlrRecogInfo;

# define Rte_TypeDef_FD14_MeTRSC_e_TurnAroundSubState
typedef uint8 FD14_MeTRSC_e_TurnAroundSubState;

# define Rte_TypeDef_FD14_NetCfg_TRSCM_e
typedef uint8 FD14_NetCfg_TRSCM_e;

# define Rte_TypeDef_FD14_OC_ModuleState_STM_Front
typedef uint8 FD14_OC_ModuleState_STM_Front;

# define Rte_TypeDef_FD14_OC_ModuleState_STM_Left
typedef uint8 FD14_OC_ModuleState_STM_Left;

# define Rte_TypeDef_FD14_OC_ModuleState_STM_Rear
typedef uint8 FD14_OC_ModuleState_STM_Rear;

# define Rte_TypeDef_FD14_OC_ModuleState_STM_Right
typedef uint8 FD14_OC_ModuleState_STM_Right;

# define Rte_TypeDef_FD14_PAM_Brk_Rq_RspSts
typedef uint8 FD14_PAM_Brk_Rq_RspSts;

# define Rte_TypeDef_FD14_PPPA_Interface_BSM
typedef uint8 FD14_PPPA_Interface_BSM;

# define Rte_TypeDef_FD14_PPPA_MaxSpeed
typedef uint8 FD14_PPPA_MaxSpeed;

# define Rte_TypeDef_FD14_PPPA_StandstillRqst
typedef boolean FD14_PPPA_StandstillRqst;

# define Rte_TypeDef_FD14_PPPA_TargetDistance
typedef uint16 FD14_PPPA_TargetDistance;

# define Rte_TypeDef_FD14_PPPA_TrqEnblRq_Allowed
typedef boolean FD14_PPPA_TrqEnblRq_Allowed;

# define Rte_TypeDef_FD14_ParkingGearShiftReq
typedef uint8 FD14_ParkingGearShiftReq;

# define Rte_TypeDef_FD14_ParkingGearShiftReq_BSM
typedef uint8 FD14_ParkingGearShiftReq_BSM;

# define Rte_TypeDef_FD14_ParkingInterventionSts
typedef uint8 FD14_ParkingInterventionSts;

# define Rte_TypeDef_FD14_ParkingManeuverActive
typedef uint8 FD14_ParkingManeuverActive;

# define Rte_TypeDef_FD14_PdlPosActual
typedef uint8 FD14_PdlPosActual;

# define Rte_TypeDef_FD14_Prev_DisplayedViewByAcore_e
typedef uint8 FD14_Prev_DisplayedViewByAcore_e;

# define Rte_TypeDef_FD14_Prev_RequestedViewByHmiM_e
typedef uint8 FD14_Prev_RequestedViewByHmiM_e;

# define Rte_TypeDef_FD14_Prev_SystemState_e
typedef uint8 FD14_Prev_SystemState_e;

# define Rte_TypeDef_FD14_Prev_TRG_Stat
typedef uint8 FD14_Prev_TRG_Stat;

# define Rte_TypeDef_FD14_REF_VEH_SPEED
typedef uint16 FD14_REF_VEH_SPEED;

# define Rte_TypeDef_FD14_RHFWheelSpeed
typedef uint16 FD14_RHFWheelSpeed;

# define Rte_TypeDef_FD14_RHF_FastPulseCounter
typedef uint8 FD14_RHF_FastPulseCounter;

# define Rte_TypeDef_FD14_RHF_Spin
typedef uint8 FD14_RHF_Spin;

# define Rte_TypeDef_FD14_RHF_WheelSensorFailSts
typedef boolean FD14_RHF_WheelSensorFailSts;

# define Rte_TypeDef_FD14_RHRWheelSpeed
typedef uint16 FD14_RHRWheelSpeed;

# define Rte_TypeDef_FD14_RHR_FastPulseCounter
typedef uint8 FD14_RHR_FastPulseCounter;

# define Rte_TypeDef_FD14_RHR_Spin
typedef uint8 FD14_RHR_Spin;

# define Rte_TypeDef_FD14_RHR_WheelSensorFailSts
typedef boolean FD14_RHR_WheelSensorFailSts;

# define Rte_TypeDef_FD14_RIL_Blockage
typedef boolean FD14_RIL_Blockage;

# define Rte_TypeDef_FD14_RIR_Blockage
typedef boolean FD14_RIR_Blockage;

# define Rte_TypeDef_FD14_ROL_Blockage
typedef boolean FD14_ROL_Blockage;

# define Rte_TypeDef_FD14_ROR_Blockage
typedef boolean FD14_ROR_Blockage;

# define Rte_TypeDef_FD14_RR_PAM_Brk_RqSts
typedef boolean FD14_RR_PAM_Brk_RqSts;

# define Rte_TypeDef_FD14_RR_PAM_Dist
typedef uint16 FD14_RR_PAM_Dist;

# define Rte_TypeDef_FD14_RSL_Blockage
typedef boolean FD14_RSL_Blockage;

# define Rte_TypeDef_FD14_RSR_Blockage
typedef boolean FD14_RSR_Blockage;

# define Rte_TypeDef_FD14_SC_ModuleState_STM_Front
typedef uint8 FD14_SC_ModuleState_STM_Front;

# define Rte_TypeDef_FD14_SC_ModuleState_STM_Left
typedef uint8 FD14_SC_ModuleState_STM_Left;

# define Rte_TypeDef_FD14_SC_ModuleState_STM_Rear
typedef uint8 FD14_SC_ModuleState_STM_Rear;

# define Rte_TypeDef_FD14_SC_ModuleState_STM_Right
typedef uint8 FD14_SC_ModuleState_STM_Right;

# define Rte_TypeDef_FD14_SPM_Lat_Ctrl_RequestSts
typedef uint8 FD14_SPM_Lat_Ctrl_RequestSts;

# define Rte_TypeDef_FD14_SPM_Lat_Ctrl_ResponseSts
typedef uint8 FD14_SPM_Lat_Ctrl_ResponseSts;

# define Rte_TypeDef_FD14_Slope
typedef uint8 FD14_Slope;

# define Rte_TypeDef_FD14_SoftBtn_Error_e
typedef boolean FD14_SoftBtn_Error_e;

# define Rte_TypeDef_FD14_Steering_Column_Torque
typedef uint16 FD14_Steering_Column_Torque;

# define Rte_TypeDef_FD14_THA_EPB_Req
typedef uint8 FD14_THA_EPB_Req;

# define Rte_TypeDef_FD14_THA_STAT
typedef uint8 FD14_THA_STAT;

# define Rte_TypeDef_FD14_THA_SpeedLimit_Req
typedef uint8 FD14_THA_SpeedLimit_Req;

# define Rte_TypeDef_FD14_THA_Speed_Limit
typedef uint8 FD14_THA_Speed_Limit;

# define Rte_TypeDef_FD14_THA_SteeringTorqueReq
typedef uint8 FD14_THA_SteeringTorqueReq;

# define Rte_TypeDef_FD14_THA_SteeringTouchStat
typedef uint8 FD14_THA_SteeringTouchStat;

# define Rte_TypeDef_FD14_TRSC_STAT
typedef uint8 FD14_TRSC_STAT;

# define Rte_TypeDef_FD14_TRSC_SpeedLimit_Req
typedef uint8 FD14_TRSC_SpeedLimit_Req;

# define Rte_TypeDef_FD14_TRSC_SteeringDamping
typedef uint8 FD14_TRSC_SteeringDamping;

# define Rte_TypeDef_FD14_TRSC_SteeringTorqueReq
typedef uint8 FD14_TRSC_SteeringTorqueReq;

# define Rte_TypeDef_FD14_TRSC_VehicleStop_Req
typedef uint8 FD14_TRSC_VehicleStop_Req;

# define Rte_TypeDef_FD14_TrailerAngleSign
typedef boolean FD14_TrailerAngleSign;

# define Rte_TypeDef_FD14_TrailerCalibrationStatus
typedef uint8 FD14_TrailerCalibrationStatus;

# define Rte_TypeDef_FD14_TrscStatus
typedef uint8 FD14_TrscStatus;

# define Rte_TypeDef_FD14_VehicleSpeedVSOSig
typedef uint16 FD14_VehicleSpeedVSOSig;

# define Rte_TypeDef_FD14_VehicleSpeedVSOSig_B2
typedef uint16 FD14_VehicleSpeedVSOSig_B2;

# define Rte_TypeDef_FD14_VehicleStandStillSts
typedef uint8 FD14_VehicleStandStillSts;

# define Rte_TypeDef_FD14_View_Error_e
typedef boolean FD14_View_Error_e;

# define Rte_TypeDef_FD14_YawRateFailSts_BSM
typedef boolean FD14_YawRateFailSts_BSM;

# define Rte_TypeDef_FD14_YawRate_BSM
typedef uint16 FD14_YawRate_BSM;

# define Rte_TypeDef_FD14_ignitionStatus_e
typedef uint8 FD14_ignitionStatus_e;

# define Rte_TypeDef_FD14_lrwsST_e
typedef uint8 FD14_lrwsST_e;

# define Rte_TypeDef_FD14_objConf_e
typedef uint8 FD14_objConf_e;

# define Rte_TypeDef_FD14_parkExtSideSel
typedef uint8 FD14_parkExtSideSel;

# define Rte_TypeDef_FD14_parkingDirection
typedef uint8 FD14_parkingDirection;

# define Rte_TypeDef_FD14_parkingSlotType
typedef uint8 FD14_parkingSlotType;

# define Rte_TypeDef_FD14_perpParkDirectionSel
typedef uint8 FD14_perpParkDirectionSel;

# define Rte_TypeDef_FD14_prndStatus_e
typedef uint8 FD14_prndStatus_e;

# define Rte_TypeDef_FD14_revGear_e
typedef uint8 FD14_revGear_e;

# define Rte_TypeDef_FD14_slotSide
typedef uint8 FD14_slotSide;

# define Rte_TypeDef_FD14_tchScrnStatus_e
typedef uint8 FD14_tchScrnStatus_e;

# define Rte_TypeDef_FD14_tgwDispStatus_e
typedef uint8 FD14_tgwDispStatus_e;

# define Rte_TypeDef_FD14_transEquipped_e
typedef uint8 FD14_transEquipped_e;

# define Rte_TypeDef_FD14_trscStat_e
typedef uint8 FD14_trscStat_e;

# define Rte_TypeDef_FL_Lvl
typedef uint8 FL_Lvl;

# define Rte_TypeDef_FL_Lvl_Adj
typedef boolean FL_Lvl_Adj;

# define Rte_TypeDef_FOD_Confidence
typedef uint8 FOD_Confidence;

# define Rte_TypeDef_FR_Lvl
typedef uint8 FR_Lvl;

# define Rte_TypeDef_FR_Lvl_Adj
typedef boolean FR_Lvl_Adj;

# define Rte_TypeDef_FT_PAMRequestSts
typedef boolean FT_PAMRequestSts;

# define Rte_TypeDef_FT_PAM_LedControlSts
typedef uint8 FT_PAM_LedControlSts;

# define Rte_TypeDef_FrontSensorSts
typedef uint8 FrontSensorSts;

# define Rte_TypeDef_Fwrd_Cam_Guidelines
typedef boolean Fwrd_Cam_Guidelines;

# define Rte_TypeDef_GearEngaged
typedef uint8 GearEngaged;

# define Rte_TypeDef_GearEngagedForDisplay
typedef uint8 GearEngagedForDisplay;

# define Rte_TypeDef_GenericFailSts_FD01_BCM
typedef boolean GenericFailSts_FD01_BCM;

# define Rte_TypeDef_GenericFailSts_FD01_SGW
typedef boolean GenericFailSts_FD01_SGW;

# define Rte_TypeDef_GenericFailSts_FD02_BCM
typedef boolean GenericFailSts_FD02_BCM;

# define Rte_TypeDef_GenericFailSts_FD02_BSM2
typedef boolean GenericFailSts_FD02_BSM2;

# define Rte_TypeDef_GenericFailSts_FD02_CADM2
typedef boolean GenericFailSts_FD02_CADM2;

# define Rte_TypeDef_GenericFailSts_FD02_EPS
typedef boolean GenericFailSts_FD02_EPS;

# define Rte_TypeDef_GenericFailSts_FD02_ORC
typedef boolean GenericFailSts_FD02_ORC;

# define Rte_TypeDef_GenericFailSts_FD02_PAM
typedef boolean GenericFailSts_FD02_PAM;

# define Rte_TypeDef_GenericFailSts_FD02_SGW
typedef boolean GenericFailSts_FD02_SGW;

# define Rte_TypeDef_GenericFailSts_FD02_TRLR_REV
typedef boolean GenericFailSts_FD02_TRLR_REV;

# define Rte_TypeDef_GenericFailSts_FD03_BCM
typedef boolean GenericFailSts_FD03_BCM;

# define Rte_TypeDef_GenericFailSts_FD03_SGW
typedef boolean GenericFailSts_FD03_SGW;

# define Rte_TypeDef_GenericFailSts_FD04_BCM
typedef boolean GenericFailSts_FD04_BCM;

# define Rte_TypeDef_GenericFailSts_FD08_SGW
typedef boolean GenericFailSts_FD08_SGW;

# define Rte_TypeDef_GenericFailSts_FD11_SGW
typedef boolean GenericFailSts_FD11_SGW;

# define Rte_TypeDef_Graphic_CHF
typedef uint8 Graphic_CHF;

# define Rte_TypeDef_Graphic_CHR
typedef uint8 Graphic_CHR;

# define Rte_TypeDef_Graphic_LHF
typedef uint8 Graphic_LHF;

# define Rte_TypeDef_Graphic_LHR
typedef uint8 Graphic_LHR;

# define Rte_TypeDef_Graphic_RHF
typedef uint8 Graphic_RHF;

# define Rte_TypeDef_Graphic_RHR
typedef uint8 Graphic_RHR;

# define Rte_TypeDef_HAS_Status_C2
typedef uint8 HAS_Status_C2;

# define Rte_TypeDef_HU_TRSC_EnableBtn_Sts
typedef uint8 HU_TRSC_EnableBtn_Sts;

# define Rte_TypeDef_Heading_Angle_C2
typedef uint16 Heading_Angle_C2;

# define Rte_TypeDef_Health_Front_Object_Detection
typedef uint8 Health_Front_Object_Detection;

# define Rte_TypeDef_Health_Lane_Detection
typedef uint8 Health_Lane_Detection;

# define Rte_TypeDef_HitchDetStatus_e
typedef uint32 HitchDetStatus_e;

# define Rte_TypeDef_IAllowedParkingDirection_t
typedef uint32 IAllowedParkingDirection_t;

# define Rte_TypeDef_ITBM_TrlrStat
typedef uint8 ITBM_TrlrStat;

# define Rte_TypeDef_ImageDefeatRQSts
typedef boolean ImageDefeatRQSts;

# define Rte_TypeDef_LHFWheelSpeed
typedef uint16 LHFWheelSpeed;

# define Rte_TypeDef_LHF_FastPulseCounter
typedef uint8 LHF_FastPulseCounter;

# define Rte_TypeDef_LHF_Spin
typedef uint8 LHF_Spin;

# define Rte_TypeDef_LHRDoorSts
typedef boolean LHRDoorSts;

# define Rte_TypeDef_LHRWheelSpeed
typedef uint16 LHRWheelSpeed;

# define Rte_TypeDef_LHR_FastPulseCounter
typedef uint8 LHR_FastPulseCounter;

# define Rte_TypeDef_LHR_Spin
typedef uint8 LHR_Spin;

# define Rte_TypeDef_LaneColor_t
typedef uint32 LaneColor_t;

# define Rte_TypeDef_LaneDetHealth_t
typedef uint32 LaneDetHealth_t;

# define Rte_TypeDef_LaneTrackState
typedef uint32 LaneTrackState;

# define Rte_TypeDef_LaneType_t
typedef uint32 LaneType_t;

# define Rte_TypeDef_LanguageSelection
typedef uint8 LanguageSelection;

# define Rte_TypeDef_LatAccelerationOffset_BSM
typedef uint8 LatAccelerationOffset_BSM;

# define Rte_TypeDef_LatAcceleration_BSM
typedef uint16 LatAcceleration_BSM;

# define Rte_TypeDef_LatAcceleration_C2
typedef uint16 LatAcceleration_C2;

# define Rte_TypeDef_Latitude_RMSE_C2
typedef uint8 Latitude_RMSE_C2;

# define Rte_TypeDef_Line_1_Type
typedef uint8 Line_1_Type;

# define Rte_TypeDef_Line_2_Type
typedef uint8 Line_2_Type;

# define Rte_TypeDef_Line_3_Type
typedef uint8 Line_3_Type;

# define Rte_TypeDef_Line_4_Type
typedef uint8 Line_4_Type;

# define Rte_TypeDef_LongAccelerationOffset_BSM
typedef uint8 LongAccelerationOffset_BSM;

# define Rte_TypeDef_LongAcceleration_BSM
typedef uint16 LongAcceleration_BSM;

# define Rte_TypeDef_LongAcceleration_C2
typedef uint16 LongAcceleration_C2;

# define Rte_TypeDef_Longitude_RMSE_C2
typedef uint8 Longitude_RMSE_C2;

# define Rte_TypeDef_LwsAngle
typedef uint16 LwsAngle;

# define Rte_TypeDef_LwsAngleType
typedef uint8 LwsAngleType;

# define Rte_TypeDef_LwsSpeed
typedef uint16 LwsSpeed;

# define Rte_TypeDef_ME_Hydra3defs_E_CalibStatus_t
typedef uint32 ME_Hydra3defs_E_CalibStatus_t;

# define Rte_TypeDef_ME_Hydra3defs_E_CalibrationID_t
typedef uint32 ME_Hydra3defs_E_CalibrationID_t;

# define Rte_TypeDef_ME_Hydra3defs_E_CameraID_t
typedef uint32 ME_Hydra3defs_E_CameraID_t;

# define Rte_TypeDef_ME_Hydra3defs_E_EOLAlgoState_t
typedef uint32 ME_Hydra3defs_E_EOLAlgoState_t;

# define Rte_TypeDef_ME_Hydra3defs_E_EOLErrorCode_t
typedef uint32 ME_Hydra3defs_E_EOLErrorCode_t;

# define Rte_TypeDef_ME_Hydra3defs_E_NRCType_t
typedef uint32 ME_Hydra3defs_E_NRCType_t;

# define Rte_TypeDef_ME_Hydra3defs_E_OCAlgoState_t
typedef uint32 ME_Hydra3defs_E_OCAlgoState_t;

# define Rte_TypeDef_ME_Hydra3defs_E_OCErrorCode_t
typedef uint32 ME_Hydra3defs_E_OCErrorCode_t;

# define Rte_TypeDef_ME_Hydra3defs_E_RoutineType_t
typedef uint32 ME_Hydra3defs_E_RoutineType_t;

# define Rte_TypeDef_ME_Hydra3defs_E_TestPatternType_t
typedef uint32 ME_Hydra3defs_E_TestPatternType_t;

# define Rte_TypeDef_MRM_STATUS_C2
typedef uint8 MRM_STATUS_C2;

# define Rte_TypeDef_MoreCamsRQSts
typedef boolean MoreCamsRQSts;

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

# define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

# define Rte_TypeDef_OperationalModeSts
typedef uint8 OperationalModeSts;

# define Rte_TypeDef_PAMRequestSts
typedef boolean PAMRequestSts;

# define Rte_TypeDef_PAMSystemFault
typedef uint8 PAMSystemFault;

# define Rte_TypeDef_PAM_CHIME_REP_RATESts
typedef uint8 PAM_CHIME_REP_RATESts;

# define Rte_TypeDef_PAM_CHIME_TYPE
typedef uint8 PAM_CHIME_TYPE;

# define Rte_TypeDef_PAM_LedControlSts
typedef uint8 PAM_LedControlSts;

# define Rte_TypeDef_PAM_Off_Status
typedef boolean PAM_Off_Status;

# define Rte_TypeDef_PAM_Off_Status_2BT
typedef uint8 PAM_Off_Status_2BT;

# define Rte_TypeDef_PAM_PopUpRqst
typedef uint8 PAM_PopUpRqst;

# define Rte_TypeDef_PAM_Volume
typedef uint8 PAM_Volume;

# define Rte_TypeDef_PA_Front_Sensor_Det_Health
typedef uint8 PA_Front_Sensor_Det_Health;

# define Rte_TypeDef_PA_Lane_Dection_Health
typedef uint8 PA_Lane_Dection_Health;

# define Rte_TypeDef_PA_Left_Sensor_Det_Health
typedef uint8 PA_Left_Sensor_Det_Health;

# define Rte_TypeDef_PA_Line_LM_Color
typedef uint8 PA_Line_LM_Color;

# define Rte_TypeDef_PA_Line_LM_Distance_Conf
typedef uint8 PA_Line_LM_Distance_Conf;

# define Rte_TypeDef_PA_Line_LM_Heading_Conf
typedef uint8 PA_Line_LM_Heading_Conf;

# define Rte_TypeDef_PA_Line_LM_Style
typedef uint8 PA_Line_LM_Style;

# define Rte_TypeDef_PA_Line_RM_Color
typedef uint8 PA_Line_RM_Color;

# define Rte_TypeDef_PA_Line_RM_Distance_Conf
typedef uint8 PA_Line_RM_Distance_Conf;

# define Rte_TypeDef_PA_Line_RM_Heading_Conf
typedef uint8 PA_Line_RM_Heading_Conf;

# define Rte_TypeDef_PA_Line_RM_Style
typedef uint8 PA_Line_RM_Style;

# define Rte_TypeDef_PA_Obj1_Conf
typedef uint8 PA_Obj1_Conf;

# define Rte_TypeDef_PA_Obj1_Type
typedef uint8 PA_Obj1_Type;

# define Rte_TypeDef_PA_Obj2_Conf
typedef uint8 PA_Obj2_Conf;

# define Rte_TypeDef_PA_Obj2_Type
typedef uint8 PA_Obj2_Type;

# define Rte_TypeDef_PA_Obj3_Conf
typedef uint8 PA_Obj3_Conf;

# define Rte_TypeDef_PA_Obj3_Type
typedef uint8 PA_Obj3_Type;

# define Rte_TypeDef_PA_Obj4_Conf
typedef uint8 PA_Obj4_Conf;

# define Rte_TypeDef_PA_Obj4_Type
typedef uint8 PA_Obj4_Type;

# define Rte_TypeDef_PA_Obj5_Conf
typedef uint8 PA_Obj5_Conf;

# define Rte_TypeDef_PA_Obj5_Type
typedef uint8 PA_Obj5_Type;

# define Rte_TypeDef_PA_Obj6_Conf
typedef uint8 PA_Obj6_Conf;

# define Rte_TypeDef_PA_Obj6_Type
typedef uint8 PA_Obj6_Type;

# define Rte_TypeDef_PA_Right_Sensor_Det_Health
typedef uint8 PA_Right_Sensor_Det_Health;

# define Rte_TypeDef_PA_SideSensor_FrontLeft_Conf
typedef uint8 PA_SideSensor_FrontLeft_Conf;

# define Rte_TypeDef_PA_SideSensor_FrontLeft_Dist
typedef uint16 PA_SideSensor_FrontLeft_Dist;

# define Rte_TypeDef_PA_SideSensor_FrontRight_Conf
typedef uint8 PA_SideSensor_FrontRight_Conf;

# define Rte_TypeDef_PA_SideSensor_FrontRight_Dist
typedef uint16 PA_SideSensor_FrontRight_Dist;

# define Rte_TypeDef_PA_SideSensor_RearLeft_Conf
typedef uint8 PA_SideSensor_RearLeft_Conf;

# define Rte_TypeDef_PA_SideSensor_RearLeft_Dist
typedef uint16 PA_SideSensor_RearLeft_Dist;

# define Rte_TypeDef_PA_SideSensor_RearRight_Conf
typedef uint8 PA_SideSensor_RearRight_Conf;

# define Rte_TypeDef_PA_SideSensor_RearRight_Dist
typedef uint16 PA_SideSensor_RearRight_Dist;

# define Rte_TypeDef_PPPA_TurnIndicatorRqst
typedef uint8 PPPA_TurnIndicatorRqst;

# define Rte_TypeDef_PamChimeVolumeFront
typedef uint8 PamChimeVolumeFront;

# define Rte_TypeDef_PamChimeVolumeRear
typedef uint8 PamChimeVolumeRear;

# define Rte_TypeDef_ParkINStyle_t
typedef uint32 ParkINStyle_t;

# define Rte_TypeDef_ParkOutStyle_t
typedef uint32 ParkOutStyle_t;

# define Rte_TypeDef_ParkingManeuverActive
typedef uint8 ParkingManeuverActive;

# define Rte_TypeDef_ParkingSlotID_t
typedef uint32 ParkingSlotID_t;

# define Rte_TypeDef_ParkingSlotType_t
typedef uint32 ParkingSlotType_t;

# define Rte_TypeDef_PdlPosActual
typedef uint8 PdlPosActual;

# define Rte_TypeDef_PitchRate_C2
typedef uint16 PitchRate_C2;

# define Rte_TypeDef_Pitch_RMSE_C2
typedef uint8 Pitch_RMSE_C2;

# define Rte_TypeDef_PreviousCanNMState_FD01_BCM
typedef uint8 PreviousCanNMState_FD01_BCM;

# define Rte_TypeDef_PreviousCanNMState_FD01_SGW
typedef uint8 PreviousCanNMState_FD01_SGW;

# define Rte_TypeDef_PreviousCanNMState_FD02_BCM
typedef uint8 PreviousCanNMState_FD02_BCM;

# define Rte_TypeDef_PreviousCanNMState_FD02_BSM2
typedef uint8 PreviousCanNMState_FD02_BSM2;

# define Rte_TypeDef_PreviousCanNMState_FD02_CADM2
typedef uint8 PreviousCanNMState_FD02_CADM2;

# define Rte_TypeDef_PreviousCanNMState_FD02_EPS
typedef uint8 PreviousCanNMState_FD02_EPS;

# define Rte_TypeDef_PreviousCanNMState_FD02_ORC
typedef uint8 PreviousCanNMState_FD02_ORC;

# define Rte_TypeDef_PreviousCanNMState_FD02_PAM
typedef uint8 PreviousCanNMState_FD02_PAM;

# define Rte_TypeDef_PreviousCanNMState_FD02_SGW
typedef uint8 PreviousCanNMState_FD02_SGW;

# define Rte_TypeDef_PreviousCanNMState_FD02_TRLR_REV
typedef uint8 PreviousCanNMState_FD02_TRLR_REV;

# define Rte_TypeDef_PreviousCanNMState_FD03_BCM
typedef uint8 PreviousCanNMState_FD03_BCM;

# define Rte_TypeDef_PreviousCanNMState_FD03_SGW
typedef uint8 PreviousCanNMState_FD03_SGW;

# define Rte_TypeDef_PreviousCanNMState_FD04_BCM
typedef uint8 PreviousCanNMState_FD04_BCM;

# define Rte_TypeDef_PreviousCanNMState_FD08_SGW
typedef uint8 PreviousCanNMState_FD08_SGW;

# define Rte_TypeDef_PreviousCanNMState_FD11_SGW
typedef uint8 PreviousCanNMState_FD11_SGW;

# define Rte_TypeDef_PsngrDoorSts
typedef boolean PsngrDoorSts;

# define Rte_TypeDef_REF_VEH_SPEED
typedef uint16 REF_VEH_SPEED;

# define Rte_TypeDef_RHFWheelSpeed
typedef uint16 RHFWheelSpeed;

# define Rte_TypeDef_RHF_FastPulseCounter
typedef uint8 RHF_FastPulseCounter;

# define Rte_TypeDef_RHF_Spin
typedef uint8 RHF_Spin;

# define Rte_TypeDef_RHRDoorSts
typedef boolean RHRDoorSts;

# define Rte_TypeDef_RHRWheelSpeed
typedef uint16 RHRWheelSpeed;

# define Rte_TypeDef_RHR_FastPulseCounter
typedef uint8 RHR_FastPulseCounter;

# define Rte_TypeDef_RHR_Spin
typedef uint8 RHR_Spin;

# define Rte_TypeDef_RHatchSts
typedef boolean RHatchSts;

# define Rte_TypeDef_RL_Lvl
typedef uint8 RL_Lvl;

# define Rte_TypeDef_RL_Lvl_Adj
typedef boolean RL_Lvl_Adj;

# define Rte_TypeDef_RR_Lvl
typedef uint8 RR_Lvl;

# define Rte_TypeDef_RR_Lvl_Adj
typedef boolean RR_Lvl_Adj;

# define Rte_TypeDef_RR_PAM_Brk_RqSts
typedef boolean RR_PAM_Brk_RqSts;

# define Rte_TypeDef_RR_PAM_Dist
typedef uint16 RR_PAM_Dist;

# define Rte_TypeDef_RR_PAM_StopControlSts
typedef boolean RR_PAM_StopControlSts;

# define Rte_TypeDef_RearSensorSts
typedef uint8 RearSensorSts;

# define Rte_TypeDef_Rear_Brk_Asst
typedef boolean Rear_Brk_Asst;

# define Rte_TypeDef_RecognitionInfo_t
typedef uint32 RecognitionInfo_t;

# define Rte_TypeDef_RemStActvSts
typedef boolean RemStActvSts;

# define Rte_TypeDef_RollRate_C2
typedef uint16 RollRate_C2;

# define Rte_TypeDef_Roll_RMSE_C2
typedef uint8 Roll_RMSE_C2;

# define Rte_TypeDef_Rte_DT_CamNvmReadSts_0
typedef uint8 Rte_DT_CamNvmReadSts_0;

# define Rte_TypeDef_Rte_DT_CamNvmReadSts_1
typedef uint8 Rte_DT_CamNvmReadSts_1;

# define Rte_TypeDef_Rte_DT_CamNvmReadSts_2
typedef uint8 Rte_DT_CamNvmReadSts_2;

# define Rte_TypeDef_Rte_DT_CamNvmReadSts_3
typedef uint8 Rte_DT_CamNvmReadSts_3;

# define Rte_TypeDef_Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1
typedef uint32 Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1;

# define Rte_TypeDef_Rte_DT_ME_VehOut_TRSC_t_10
typedef uint32 Rte_DT_ME_VehOut_TRSC_t_10;

# define Rte_TypeDef_Rte_DT_ME_VehOut_TRSC_t_11
typedef uint32 Rte_DT_ME_VehOut_TRSC_t_11;

# define Rte_TypeDef_Rte_DT_StayActiveSource_FD02_PAM_0
typedef uint8 Rte_DT_StayActiveSource_FD02_PAM_0;

# define Rte_TypeDef_Rte_DT_TbFA_ArbiterOutput_t_4
typedef uint32 Rte_DT_TbFA_ArbiterOutput_t_4;

# define Rte_TypeDef_Rte_DT_TbFA_ArbiterOutput_t_5
typedef uint32 Rte_DT_TbFA_ArbiterOutput_t_5;

# define Rte_TypeDef_Rte_DT_TbFA_ArbiterOutput_t_6
typedef uint32 Rte_DT_TbFA_ArbiterOutput_t_6;

# define Rte_TypeDef_Rte_DT_TeTRSC_e_TrailerCalibMemClearResponse_t_0
typedef uint32 Rte_DT_TeTRSC_e_TrailerCalibMemClearResponse_t_0;

# define Rte_TypeDef_SBR1RowDriverSeatSts
typedef uint8 SBR1RowDriverSeatSts;

# define Rte_TypeDef_SPMControlSts
typedef uint8 SPMControlSts;

# define Rte_TypeDef_SPMFailSts
typedef boolean SPMFailSts;

# define Rte_TypeDef_SPMSystemFault
typedef boolean SPMSystemFault;

# define Rte_TypeDef_SPM_LedControlSts
typedef uint8 SPM_LedControlSts;

# define Rte_TypeDef_SPM_Screen_Rqst
typedef boolean SPM_Screen_Rqst;

# define Rte_TypeDef_SSM_ApplicationStatus
typedef uint32 SSM_ApplicationStatus;

# define Rte_TypeDef_SSM_CoreSlaveCoreStateDef
typedef uint32 SSM_CoreSlaveCoreStateDef;

# define Rte_TypeDef_SSM_DegradedState
typedef uint32 SSM_DegradedState;

# define Rte_TypeDef_SSM_SystemStateDef
typedef uint32 SSM_SystemStateDef;

# define Rte_TypeDef_SVC_Guidelines
typedef boolean SVC_Guidelines;

# define Rte_TypeDef_ShiftLeverPosition
typedef uint8 ShiftLeverPosition;

# define Rte_TypeDef_ShiftLeverPositionReq
typedef uint8 ShiftLeverPositionReq;

# define Rte_TypeDef_Shifter_ADAS_Inhibit
typedef boolean Shifter_ADAS_Inhibit;

# define Rte_TypeDef_SlotSide_t
typedef uint32 SlotSide_t;

# define Rte_TypeDef_State_t
typedef uint32 State_t;

# define Rte_TypeDef_StaticGrid
typedef boolean StaticGrid;

# define Rte_TypeDef_TCASERANGESTATUS
typedef uint8 TCASERANGESTATUS;

# define Rte_TypeDef_TGW_CAMERA_DISP_STAT
typedef uint8 TGW_CAMERA_DISP_STAT;

# define Rte_TypeDef_THA_EPB_Req
typedef uint8 THA_EPB_Req;

# define Rte_TypeDef_THA_STAT
typedef uint8 THA_STAT;

# define Rte_TypeDef_THA_SpeedLimit_Req
typedef uint8 THA_SpeedLimit_Req;

# define Rte_TypeDef_THA_Speed_Limit
typedef uint8 THA_Speed_Limit;

# define Rte_TypeDef_THA_SteeringTorqueReq
typedef uint8 THA_SteeringTorqueReq;

# define Rte_TypeDef_THA_SteeringTouchStat
typedef uint8 THA_SteeringTouchStat;

# define Rte_TypeDef_TRANS_ADAS_Inhibit
typedef boolean TRANS_ADAS_Inhibit;

# define Rte_TypeDef_TRSCMoreCamRQSts
typedef boolean TRSCMoreCamRQSts;

# define Rte_TypeDef_TRSC_CenterBtn_Sts
typedef uint8 TRSC_CenterBtn_Sts;

# define Rte_TypeDef_TRSC_EnableBtn_Sts
typedef uint8 TRSC_EnableBtn_Sts;

# define Rte_TypeDef_TRSC_LED_Stat
typedef uint8 TRSC_LED_Stat;

# define Rte_TypeDef_TRSC_PopupDisp_Info
typedef uint8 TRSC_PopupDisp_Info;

# define Rte_TypeDef_TRSC_PopupDisp_Info2
typedef uint8 TRSC_PopupDisp_Info2;

# define Rte_TypeDef_TRSC_STAT
typedef uint8 TRSC_STAT;

# define Rte_TypeDef_TRSC_SpeedLimit_Req
typedef uint8 TRSC_SpeedLimit_Req;

# define Rte_TypeDef_TRSC_SteeringDamping
typedef uint8 TRSC_SteeringDamping;

# define Rte_TypeDef_TRSC_SteeringTorqueReq
typedef uint8 TRSC_SteeringTorqueReq;

# define Rte_TypeDef_TRSC_VehicleStop_Req
typedef uint8 TRSC_VehicleStop_Req;

# define Rte_TypeDef_TargetGear
typedef uint8 TargetGear;

# define Rte_TypeDef_TeAP_e_Alert
typedef uint32 TeAP_e_Alert;

# define Rte_TypeDef_TeAP_e_AlgoState
typedef uint32 TeAP_e_AlgoState;

# define Rte_TypeDef_TeAP_e_DispView2
typedef uint32 TeAP_e_DispView2;

# define Rte_TypeDef_TeAP_e_FrntSnsrStatus
typedef uint32 TeAP_e_FrntSnsrStatus;

# define Rte_TypeDef_TeAP_e_GearShiftReq
typedef uint32 TeAP_e_GearShiftReq;

# define Rte_TypeDef_TeAP_e_GraphicFlshRate
typedef uint32 TeAP_e_GraphicFlshRate;

# define Rte_TypeDef_TeAP_e_HMIPopUp
typedef uint32 TeAP_e_HMIPopUp;

# define Rte_TypeDef_TeAP_e_InterfaceBSM
typedef uint32 TeAP_e_InterfaceBSM;

# define Rte_TypeDef_TeAP_e_PAMChimeRepnRate
typedef uint32 TeAP_e_PAMChimeRepnRate;

# define Rte_TypeDef_TeAP_e_PAMChimeTyp
typedef uint32 TeAP_e_PAMChimeTyp;

# define Rte_TypeDef_TeAP_e_PAMLedCtrlStatus
typedef uint32 TeAP_e_PAMLedCtrlStatus;

# define Rte_TypeDef_TeAP_e_PAMOffStatus2BT
typedef uint32 TeAP_e_PAMOffStatus2BT;

# define Rte_TypeDef_TeAP_e_PAMPopUpReq
typedef uint32 TeAP_e_PAMPopUpReq;

# define Rte_TypeDef_TeAP_e_PAMSystemFault
typedef uint32 TeAP_e_PAMSystemFault;

# define Rte_TypeDef_TeAP_e_PAMVolSig
typedef uint32 TeAP_e_PAMVolSig;

# define Rte_TypeDef_TeAP_e_PAMVolume
typedef uint32 TeAP_e_PAMVolume;

# define Rte_TypeDef_TeAP_e_ParKMnvrActv
typedef uint32 TeAP_e_ParKMnvrActv;

# define Rte_TypeDef_TeAP_e_ParkAssistStatus
typedef uint32 TeAP_e_ParkAssistStatus;

# define Rte_TypeDef_TeAP_e_RearSnsrStatus
typedef uint32 TeAP_e_RearSnsrStatus;

# define Rte_TypeDef_TeAP_e_SPMActvStat
typedef uint32 TeAP_e_SPMActvStat;

# define Rte_TypeDef_TeAP_e_SPMLatCtrlReqSts
typedef uint32 TeAP_e_SPMLatCtrlReqSts;

# define Rte_TypeDef_TeAutoPark_e_AutoParkStatus
typedef uint32 TeAutoPark_e_AutoParkStatus;

# define Rte_TypeDef_TeAutoPark_e_ChimeReq
typedef uint32 TeAutoPark_e_ChimeReq;

# define Rte_TypeDef_TeAutoPark_e_GearCmd
typedef uint32 TeAutoPark_e_GearCmd;

# define Rte_TypeDef_TeAutoPark_e_ScanDir
typedef uint32 TeAutoPark_e_ScanDir;

# define Rte_TypeDef_TeEnv_e_NFCDState
typedef uint32 TeEnv_e_NFCDState;

# define Rte_TypeDef_TeEnv_e_ObjClass
typedef uint32 TeEnv_e_ObjClass;

# define Rte_TypeDef_TeTHA_e_EPBReq
typedef uint32 TeTHA_e_EPBReq;

# define Rte_TypeDef_TeTHA_e_PamChimeRepRateSts
typedef uint32 TeTHA_e_PamChimeRepRateSts;

# define Rte_TypeDef_TeTHA_e_PamChimeTyp
typedef uint32 TeTHA_e_PamChimeTyp;

# define Rte_TypeDef_TeTHA_e_PamVol
typedef uint32 TeTHA_e_PamVol;

# define Rte_TypeDef_TeTHA_e_RearBrkSupprInfo
typedef uint32 TeTHA_e_RearBrkSupprInfo;

# define Rte_TypeDef_TeTHA_e_ScreenRequest
typedef uint32 TeTHA_e_ScreenRequest;

# define Rte_TypeDef_TeTHA_e_THARmpUpDwnSpd
typedef uint32 TeTHA_e_THARmpUpDwnSpd;

# define Rte_TypeDef_TeTHA_e_THASpdLimReq
typedef uint32 TeTHA_e_THASpdLimReq;

# define Rte_TypeDef_TeTHA_e_THAState
typedef uint32 TeTHA_e_THAState;

# define Rte_TypeDef_TeTHA_e_THAStateInfo
typedef uint32 TeTHA_e_THAStateInfo;

# define Rte_TypeDef_TeTHA_e_THASteerTrqReq
typedef uint32 TeTHA_e_THASteerTrqReq;

# define Rte_TypeDef_TeTRSC_e_CamBlockSts
typedef uint32 TeTRSC_e_CamBlockSts;

# define Rte_TypeDef_TeTRSC_e_DispView2_DID
typedef uint32 TeTRSC_e_DispView2_DID;

# define Rte_TypeDef_TeTRSC_e_GearShiftSts_DID
typedef uint32 TeTRSC_e_GearShiftSts_DID;

# define Rte_TypeDef_TeTRSC_e_GraphicOverlay_Sts
typedef uint32 TeTRSC_e_GraphicOverlay_Sts;

# define Rte_TypeDef_TeTRSC_e_SpdLmtReq
typedef uint32 TeTRSC_e_SpdLmtReq;

# define Rte_TypeDef_TeTRSC_e_TADState
typedef uint32 TeTRSC_e_TADState;

# define Rte_TypeDef_TeTRSC_e_TRSCAbortReason_DID
typedef uint32 TeTRSC_e_TRSCAbortReason_DID;

# define Rte_TypeDef_TeTRSC_e_TRSCLedSts
typedef uint32 TeTRSC_e_TRSCLedSts;

# define Rte_TypeDef_TeTRSC_e_TRSCPopupDispInfo
typedef uint32 TeTRSC_e_TRSCPopupDispInfo;

# define Rte_TypeDef_TeTRSC_e_TRSCStat
typedef uint32 TeTRSC_e_TRSCStat;

# define Rte_TypeDef_TeTRSC_e_TRSCStrTrqActvReq
typedef uint32 TeTRSC_e_TRSCStrTrqActvReq;

# define Rte_TypeDef_TeTRSC_e_TRSCSts
typedef uint32 TeTRSC_e_TRSCSts;

# define Rte_TypeDef_TeTRSC_e_TRSCUnavailReas_DID
typedef uint32 TeTRSC_e_TRSCUnavailReas_DID;

# define Rte_TypeDef_TeTRSC_e_TRSKMBtnSts_DID
typedef uint32 TeTRSC_e_TRSKMBtnSts_DID;

# define Rte_TypeDef_TeTRSC_e_TRSKMCenBtnSts_DID
typedef uint32 TeTRSC_e_TRSKMCenBtnSts_DID;

# define Rte_TypeDef_TeTRSC_e_TRSKMSts
typedef uint32 TeTRSC_e_TRSKMSts;

# define Rte_TypeDef_TeTRSC_e_TRSKMSts_DID
typedef uint32 TeTRSC_e_TRSKMSts_DID;

# define Rte_TypeDef_TeTRSC_e_TrlrCalInfo
typedef uint32 TeTRSC_e_TrlrCalInfo;

# define Rte_TypeDef_TeTRSC_e_TrlrCalInfo_DID
typedef uint32 TeTRSC_e_TrlrCalInfo_DID;

# define Rte_TypeDef_TeTRSC_e_TrlrHitchLightCtrl
typedef uint32 TeTRSC_e_TrlrHitchLightCtrl;

# define Rte_TypeDef_TeTRSC_e_TrlrPrsntInfo
typedef uint32 TeTRSC_e_TrlrPrsntInfo;

# define Rte_TypeDef_TeTRSC_e_TrlrPrsntInfo_DID
typedef uint32 TeTRSC_e_TrlrPrsntInfo_DID;

# define Rte_TypeDef_TeTRSC_e_TrlrRecogInfo
typedef uint32 TeTRSC_e_TrlrRecogInfo;

# define Rte_TypeDef_TeTRSC_e_TrlrRecogInfo_DID
typedef uint32 TeTRSC_e_TrlrRecogInfo_DID;

# define Rte_TypeDef_TeTRSC_e_VehStpReq
typedef uint32 TeTRSC_e_VehStpReq;

# define Rte_TypeDef_TeTRSC_e_VehStpReq_DID
typedef uint32 TeTRSC_e_VehStpReq_DID;

# define Rte_TypeDef_TeVBII_e_CenterBtnSts
typedef uint32 TeVBII_e_CenterBtnSts;

# define Rte_TypeDef_TeVBII_e_DrverSecuBltAlrmSts
typedef uint32 TeVBII_e_DrverSecuBltAlrmSts;

# define Rte_TypeDef_TeVBII_e_EnblBtnSts
typedef uint32 TeVBII_e_EnblBtnSts;

# define Rte_TypeDef_TeVBII_e_GearEngagedForDsply
typedef uint32 TeVBII_e_GearEngagedForDsply;

# define Rte_TypeDef_TrailerAngleSign_t
typedef uint32 TrailerAngleSign_t;

# define Rte_TypeDef_TrailerCalibrationFailInfo_DID_t
typedef uint32 TrailerCalibrationFailInfo_DID_t;

# define Rte_TypeDef_TrailerCalibrationFailInfo_t
typedef uint32 TrailerCalibrationFailInfo_t;

# define Rte_TypeDef_TrailerConnectionSts
typedef uint8 TrailerConnectionSts;

# define Rte_TypeDef_TrailerID_t
typedef uint32 TrailerID_t;

# define Rte_TypeDef_TrailerPresentInfo_t
typedef uint32 TrailerPresentInfo_t;

# define Rte_TypeDef_Trailer_Angle_Sign
typedef uint8 Trailer_Angle_Sign;

# define Rte_TypeDef_Trailer_Calibration
typedef uint8 Trailer_Calibration;

# define Rte_TypeDef_TransmissionSailingSts
typedef uint8 TransmissionSailingSts;

# define Rte_TypeDef_TrlrCalInfo_t
typedef uint32 TrlrCalInfo_t;

# define Rte_TypeDef_TrlrHitchLight_Cntrl
typedef uint8 TrlrHitchLight_Cntrl;

# define Rte_TypeDef_TurnAroundState_t
typedef uint32 TurnAroundState_t;

# define Rte_TypeDef_TurnIndicatorSts
typedef uint8 TurnIndicatorSts;

# define Rte_TypeDef_US_E_Zoneinfo_list_t
typedef uint32 US_E_Zoneinfo_list_t;

# define Rte_TypeDef_VIN_MSG
typedef uint8 VIN_MSG;

# define Rte_TypeDef_VehicleSpeedVSOSig
typedef uint16 VehicleSpeedVSOSig;

# define Rte_TypeDef_VehicleStandStillSts
typedef uint8 VehicleStandStillSts;

# define Rte_TypeDef_VerticalAcceleration_C2
typedef uint16 VerticalAcceleration_C2;

# define Rte_TypeDef_VoltMgr_Enum_VoltageMON
typedef uint8 VoltMgr_Enum_VoltageMON;

# define Rte_TypeDef_WakeupSource_FD01_ADCM
typedef uint8 WakeupSource_FD01_ADCM;

# define Rte_TypeDef_WakeupSource_FD01_BCM
typedef uint8 WakeupSource_FD01_BCM;

# define Rte_TypeDef_WakeupSource_FD01_SGW
typedef uint8 WakeupSource_FD01_SGW;

# define Rte_TypeDef_WakeupSource_FD02_BCM
typedef uint8 WakeupSource_FD02_BCM;

# define Rte_TypeDef_WakeupSource_FD02_BSM2
typedef uint8 WakeupSource_FD02_BSM2;

# define Rte_TypeDef_WakeupSource_FD02_CADM2
typedef uint8 WakeupSource_FD02_CADM2;

# define Rte_TypeDef_WakeupSource_FD02_EPS
typedef uint8 WakeupSource_FD02_EPS;

# define Rte_TypeDef_WakeupSource_FD02_ORC
typedef uint8 WakeupSource_FD02_ORC;

# define Rte_TypeDef_WakeupSource_FD02_PAM
typedef uint8 WakeupSource_FD02_PAM;

# define Rte_TypeDef_WakeupSource_FD02_SGW
typedef uint8 WakeupSource_FD02_SGW;

# define Rte_TypeDef_WakeupSource_FD02_TRLR_REV
typedef uint8 WakeupSource_FD02_TRLR_REV;

# define Rte_TypeDef_WakeupSource_FD03_BCM
typedef uint8 WakeupSource_FD03_BCM;

# define Rte_TypeDef_WakeupSource_FD03_SGW
typedef uint8 WakeupSource_FD03_SGW;

# define Rte_TypeDef_WakeupSource_FD04_BCM
typedef uint8 WakeupSource_FD04_BCM;

# define Rte_TypeDef_WakeupSource_FD08_SGW
typedef uint8 WakeupSource_FD08_SGW;

# define Rte_TypeDef_WakeupSource_FD11_SGW
typedef uint8 WakeupSource_FD11_SGW;

# define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;

# define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;

# define Rte_TypeDef_YawRate_BSM
typedef uint16 YawRate_BSM;

# define Rte_TypeDef_YawRate_C2
typedef uint16 YawRate_C2;

# define Rte_TypeDef_YawRate_RMSE_C2
typedef uint8 YawRate_RMSE_C2;

# define Rte_TypeDef_aSigConverter_E_DisplayView2_t
typedef uint32 aSigConverter_E_DisplayView2_t;

# define Rte_TypeDef_aSigConverter_E_THAScreenRequest_t
typedef uint32 aSigConverter_E_THAScreenRequest_t;

# define Rte_TypeDef_aZynqM_E_ModuleState_EOL_STM_t
typedef uint32 aZynqM_E_ModuleState_EOL_STM_t;

# define Rte_TypeDef_aZynqM_E_ModuleState_OC_STM_t
typedef uint32 aZynqM_E_ModuleState_OC_STM_t;

# define Rte_TypeDef_aZynqM_E_ModuleState_SC_STM_t
typedef uint32 aZynqM_E_ModuleState_SC_STM_t;

# define Rte_TypeDef_e_SensorSource
typedef uint32 e_SensorSource;

# define Rte_TypeDef_udtBatteryVoltageStatus
typedef uint8 udtBatteryVoltageStatus;

# define Rte_TypeDef_vRoE_ActivationStateType
typedef uint8 vRoE_ActivationStateType;

# define Rte_TypeDef_vRoE_NegativeResponseCodeType
typedef uint8 vRoE_NegativeResponseCodeType;

# define Rte_TypeDef_vRoE_OpStatusType
typedef uint8 vRoE_OpStatusType;

# define Rte_TypeDef_BoundingBox_Real_Array
typedef Float2 BoundingBox_Real_Array[4];

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataType
typedef Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataType[1];

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType
typedef Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType[8];

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType
typedef Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType[9];

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType
typedef Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType[2];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataType
typedef Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataType[1];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataType
typedef Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataType[1];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataType
typedef Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataType[1];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataType
typedef Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataType[1];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataType
typedef Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataType[1];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataType
typedef Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataType[1];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_3101D003_Application_Logical_Block_Hash_In_ReqDataType
typedef Dcm_StartDataIn_Routine_3101D003_Application_Logical_Block_Hash_In_ReqDataArrayType Dcm_StartDataIn_Routine_3101D003_Application_Logical_Block_Hash_In_ReqDataType[1];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataType
typedef Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataType[2];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataType
typedef Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataType[5];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataType
typedef Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataType[2];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataType
typedef Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataType[3];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataType[1];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataType[1];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType[1];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType[1];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType[1];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101D003_Application_Logical_Block_Hash_Out_ResDataType
typedef Dcm_StartDataOut_Routine_3101D003_Application_Logical_Block_Hash_Out_ResDataArrayType Dcm_StartDataOut_Routine_3101D003_Application_Logical_Block_Hash_Out_ResDataType[32];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101F000_Check_Program_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_3101F000_Check_Program_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_3101F000_Check_Program_Start_Out_ResDataType[1];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataType[2];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataType[2];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101FF00_FlashErase_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_3101FF00_FlashErase_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_3101FF00_FlashErase_Start_Out_ResDataType[9];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_3101FF01_checkProgrammingDependencies_FlashChecksum_Start_Out_ResDataType[1];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataType
typedef Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataType[2];

# define Rte_TypeDef_Error1_0B_arr
typedef ErrorMgr_ErrorField Error1_0B_arr[400];

# define Rte_TypeDef_Error1_0QM_arr
typedef ErrorMgr_ErrorField Error1_0QM_arr[12];

# define Rte_TypeDef_Error2_0B_arr
typedef ErrorMgr_ErrorField Error2_0B_arr[144];

# define Rte_TypeDef_Error2_0QM_arr
typedef ErrorMgr_ErrorField Error2_0QM_arr[1];

# define Rte_TypeDef_Error2_1B_arr
typedef ErrorMgr_ErrorField Error2_1B_arr[548];

# define Rte_TypeDef_Error2_1QM_arr
typedef ErrorMgr_ErrorField Error2_1QM_arr[1];

# define Rte_TypeDef_ErrorQNXB_arr
typedef ErrorMgr_ErrorField ErrorQNXB_arr[8];

# define Rte_TypeDef_ErrorQNXQM_arr
typedef ErrorMgr_ErrorField ErrorQNXQM_arr[1];

# define Rte_TypeDef_Float2_Array
typedef Float2 Float2_Array[4];

# define Rte_TypeDef_IAllowedParkingDirection_Array
typedef IAllowedParkingDirection_t IAllowedParkingDirection_Array[6];

# define Rte_TypeDef_IobjectSignals_Arr
typedef IobjectSignals_t IobjectSignals_Arr[6];

# define Rte_TypeDef_ME_Hydra3defs_E_CalibStatus_arr
typedef ME_Hydra3defs_E_CalibStatus_t ME_Hydra3defs_E_CalibStatus_arr[4];

# define Rte_TypeDef_ObjectPos_Real_Array
typedef Float2 ObjectPos_Real_Array[4];

# define Rte_TypeDef_Padding2_0QM_arr
typedef ErrorMgr_ErrorField Padding2_0QM_arr[3];

# define Rte_TypeDef_Padding2_1QM_arr
typedef ErrorMgr_ErrorField Padding2_1QM_arr[3];

# define Rte_TypeDef_PaddingQNXQM_arr
typedef ErrorMgr_ErrorField PaddingQNXQM_arr[3];

# define Rte_TypeDef_Rte_DT_RearBrkEvent_t_1
typedef RearBrkData_t Rte_DT_RearBrkEvent_t_1[3];

# define Rte_TypeDef_Rte_DT_SPMAbrtEvent_t_1
typedef SPMAbrtData_t Rte_DT_SPMAbrtEvent_t_1[3];

# define Rte_TypeDef_Rte_DT_SecureLogRecord_t_4
typedef Rte_DT_SecureLogRecord_t_4_0 Rte_DT_SecureLogRecord_t_4[10];

# define Rte_TypeDef_SSM_MCU_1_0_LocalAppStatus_Arr
typedef SSM_ApplicationStatus SSM_MCU_1_0_LocalAppStatus_Arr[20];

# define Rte_TypeDef_SSM_MCU_2_0_LocalAppStatus_Arr
typedef SSM_ApplicationStatus SSM_MCU_2_0_LocalAppStatus_Arr[20];

# define Rte_TypeDef_SSM_MCU_2_1_LocalAppStatus_Arr
typedef SSM_ApplicationStatus SSM_MCU_2_1_LocalAppStatus_Arr[20];

# define Rte_TypeDef_SSM_MCU_QNX_LocalAppStatus_Arr
typedef SSM_ApplicationStatus SSM_MCU_QNX_LocalAppStatus_Arr[20];

# define Rte_TypeDef_StayActiveSource_FD02_PAM
typedef Rte_DT_StayActiveSource_FD02_PAM_0 StayActiveSource_FD02_PAM[8];

# define Rte_TypeDef_SubRois_Array
typedef ColumnRowParams SubRois_Array[2];

# define Rte_TypeDef_US_E_Zoneinfo_list_Array
typedef US_E_Zoneinfo_list_t US_E_Zoneinfo_list_Array[16];

# define Rte_TypeDef_US_S_PointOutputBuff_Array
typedef US_S_PointOutputBuff_t US_S_PointOutputBuff_Array[96];

# define Rte_TypeDef_constantStartSequence_ac
typedef char_T constantStartSequence_ac[2];

# define Rte_TypeDef_endpoints_Array
typedef Float2 endpoints_Array[2];

# define Rte_TypeDef_finalAssemblyDay_ac
typedef char_T finalAssemblyDay_ac[3];

# define Rte_TypeDef_finalAssemblyFocusAndAlign_ac
typedef char_T finalAssemblyFocusAndAlign_ac[1];

# define Rte_TypeDef_finalAssemblyPartNumber_ac
typedef char_T finalAssemblyPartNumber_ac[16];

# define Rte_TypeDef_finalAssemblySerialNumber_ac
typedef char_T finalAssemblySerialNumber_ac[4];

# define Rte_TypeDef_finalAssemblyYear_ac
typedef char_T finalAssemblyYear_ac[2];

# define Rte_TypeDef_intrinsicAlgoRevision_ac
typedef char_T intrinsicAlgoRevision_ac[16];

# define Rte_TypeDef_lanTrack_s_Array
typedef LaneTrackState lanTrack_s_Array[2];

# define Rte_TypeDef_laneCoef_2dArray
typedef Rte_DT_laneCoef_2dArray_0 laneCoef_2dArray[2];

# define Rte_TypeDef_laneCoef_TVG_2dArray
typedef Rte_DT_laneCoef_TVG_2dArray_0 laneCoef_TVG_2dArray[2];

# define Rte_TypeDef_productionBoardSerialNumber_ac
typedef char_T productionBoardSerialNumber_ac[2];

# define Rte_TypeDef_productionDay_ac
typedef char_T productionDay_ac[3];

# define Rte_TypeDef_productionLineNumber_ac
typedef char_T productionLineNumber_ac[2];

# define Rte_TypeDef_productionSerialNumber_ac
typedef char_T productionSerialNumber_ac[5];

# define Rte_TypeDef_productionYear_ac
typedef char_T productionYear_ac[2];

# define Rte_TypeDef_vRoE_ActivationStateArrayType
typedef vRoE_ActivationStateType vRoE_ActivationStateArrayType[1];

# define Rte_TypeDef_AP_HMI_ParkSlot_t
typedef struct
{
  ParkingSlotID_t SlotID;
  ParkingSlotType_t SlotType;
  boolean SlotSelected;
  uint16 SlotPixelCoordinate_X;
  uint16 SlotPixelCoordinate_Y;
} AP_HMI_ParkSlot_t;

# define Rte_TypeDef_CamEepromCrcData_t
typedef struct
{
  uint32 crc_u32;
  firstReservedBytes_au8 firstReservedBytes;
  secondReservedBytes_au8 secondReservedBytes;
} CamEepromCrcData_t;

# define Rte_TypeDef_CamEepromIntrinsicData_t
typedef struct
{
  intrinsicAlgoRevision_ac intrinsicAlgoRevision;
  uint32 imageWidth_u32;
  uint32 imageHeight_u32;
  float32 ppx_f32;
  float32 ppy_f32;
  polyImage2World_af32 polyImage2World;
  polyWorld2Image_af32 polyWorld2Image;
  float32 pixelSizeX_f32;
  float32 pixelSizeY_f32;
  float32 fieldOfView_f32;
  float32 effectiveFocalLength_f32;
  reservedBytesIntrinsic_au8 reservedBytes;
} CamEepromIntrinsicData_t;

# define Rte_TypeDef_CamNvmReadSts
typedef struct
{
  Rte_DT_CamNvmReadSts_0 FrontCameraNVMStatus;
  Rte_DT_CamNvmReadSts_1 LeftCameraNVMStatus;
  Rte_DT_CamNvmReadSts_2 RearCameraNVMStatus;
  Rte_DT_CamNvmReadSts_3 RightCameraNVMStatus;
} CamNvmReadSts;

# define Rte_TypeDef_Debug_HMI_Curr_Displayed_Overlays
typedef OverlayBits_t Debug_HMI_Curr_Displayed_Overlays;

# define Rte_TypeDef_Debug_HMI_Curr_Displayed_ProxiConfig
typedef Debug_HMI_ProxiConfig_t Debug_HMI_Curr_Displayed_ProxiConfig;

# define Rte_TypeDef_Debug_HMI_Curr_Requested_Overlays
typedef OverlayBits_t Debug_HMI_Curr_Requested_Overlays;

# define Rte_TypeDef_Debug_HMI_Curr_Requested_ProxiConfig
typedef Debug_HMI_ProxiConfig_t Debug_HMI_Curr_Requested_ProxiConfig;

# define Rte_TypeDef_Detection_Inputs_from_TRSC_t
typedef struct
{
  TeTRSC_e_TRSCStat MeTRSC_e_TRSCStat;
  real32_T MeTRSC_deg_JackKnifeAngle;
  real32_T MeTRSC_m_TrailerBeamLen;
  TeTRSC_e_TrlrPrsntInfo MeTRSC_e_TrlrPrsntInfoCAN;
  boolean MeTRSC_b_TRSCSwitchPressed;
  boolean MeTRSC_b_OTBLReset;
  boolean MeTRSC_b_TBLComputationDone;
  boolean dummy;
} Detection_Inputs_from_TRSC_t;

# define Rte_TypeDef_DtcAddData_B
typedef struct
{
  AdditionalData_arr b210c_16_0;
  AdditionalData_arr b210c_17_0;
  AdditionalData_arr u104e_0_0;
  AdditionalData_arr u100b_0_0;
  AdditionalData_arr u0140_0_0;
  AdditionalData_arr u0184_0_0;
  AdditionalData_arr b223b_0_0;
  AdditionalData_arr u0129_0_0;
  AdditionalData_arr u0131_0_0;
  AdditionalData_arr u0418_0_0;
  AdditionalData_arr u0420_0_0;
  AdditionalData_arr u0422_0_0;
  AdditionalData_arr u0485_0_0;
  AdditionalData_arr b12b2_2a_0;
  AdditionalData_arr b1285_2a_0;
  AdditionalData_arr b128e_13_0;
  AdditionalData_arr b128f_13_0;
  AdditionalData_arr b1290_13_0;
  AdditionalData_arr b1291_13_0;
  AdditionalData_arr b1292_13_0;
  AdditionalData_arr b1293_13_0;
  AdditionalData_arr b1294_13_0;
  AdditionalData_arr b1295_13_0;
  AdditionalData_arr b1296_13_0;
  AdditionalData_arr b1297_13_0;
  AdditionalData_arr b1298_13_0;
  AdditionalData_arr b1299_13_0;
  AdditionalData_arr b128e_92_0;
  AdditionalData_arr b128f_92_0;
  AdditionalData_arr b1290_92_0;
  AdditionalData_arr b1291_92_0;
  AdditionalData_arr b1292_92_0;
  AdditionalData_arr b1293_92_0;
  AdditionalData_arr b1294_92_0;
  AdditionalData_arr b1295_92_0;
  AdditionalData_arr b1296_92_0;
  AdditionalData_arr b1297_92_0;
  AdditionalData_arr b1298_92_0;
  AdditionalData_arr b1299_92_0;
  AdditionalData_arr b212a_16_0;
  AdditionalData_arr b212b_16_0;
  AdditionalData_arr b22a9_0_0;
  AdditionalData_arr b23c6_92_0;
  AdditionalData_arr u0267_0_0;
  AdditionalData_arr b23c7_92_0;
  AdditionalData_arr u0266_0_0;
  AdditionalData_arr u0264_0_0;
  AdditionalData_arr b217a_92_0;
  AdditionalData_arr u0265_0_0;
  AdditionalData_arr b23c5_92_0;
  AdditionalData_arr b217a_1c_0;
  AdditionalData_arr b23c5_1c_0;
  AdditionalData_arr b23c6_1c_0;
  AdditionalData_arr b23c7_1c_0;
  AdditionalData_arr b2286_0_0;
  AdditionalData_arr c2212_0_0;
  AdditionalData_arr b212a_17_0;
  AdditionalData_arr b212b_17_0;
  AdditionalData_arr u0100_0_0;
  AdditionalData_arr u0401_0_0;
  AdditionalData_arr b212a_8_0;
  AdditionalData_arr b212b_8_0;
} DtcAddData_B;

# define Rte_TypeDef_DtcAddData_QM
typedef struct
{
  AdditionalData_arr u0151_0_0;
  AdditionalData_arr u12b9_0_0;
  AdditionalData_arr u14a0_0_0;
  AdditionalData_arr u0455_0_0;
} DtcAddData_QM;

# define Rte_TypeDef_E2E_MEP_CheckStateType
typedef struct
{
  uint8 LastValidCounter;
  uint8 MaxDeltaCounter;
  boolean WaitForFirstData;
  boolean NewDataAvailable;
  uint8 LostData;
  E2E_MEP_CheckStatusType Status;
  uint8 SyncCounter;
  uint8 NoNewOrRepeatedDataCounter;
} E2E_MEP_CheckStateType;

# define Rte_TypeDef_E2E_MEP_ConfigType
typedef struct
{
  uint16 CounterOffset;
  uint16 CRCOffset;
  uint16 DataID;
  uint16 DataIDNibbleOffset;
  E2E_MEP_DataIDMode DataIDMode;
  uint16 DataLength;
  uint8 MaxDeltaCounterInit;
  uint8 MaxNoNewOrRepeatedData;
  uint8 SyncCounterInit;
} E2E_MEP_ConfigType;

# define Rte_TypeDef_ErrorMgr_stAddData
typedef struct
{
  AdditionalData_arr AdditionalData;
} ErrorMgr_stAddData;

# define Rte_TypeDef_FinalAssemblySerialNumber_t
typedef struct
{
  finalAssemblyYear_ac finalAssemblyYear;
  finalAssemblyDay_ac finalAssemblyDay;
  finalAssemblySerialNumber_ac finalAssemblySerialNumber;
  finalAssemblyFocusAndAlign_ac finalAssemblyFocusAndAlign;
} FinalAssemblySerialNumber_t;

# define Rte_TypeDef_IDebug_FODObject_t
typedef struct
{
  IobjectSignals_Arr Debug_FODObjectInfo_s;
  float32 IeVBII_nfcd_MinDistanceToCollisionObject;
  float32 latDistance_f32;
  float32 longiDistance_f32;
  float32 vehiclePosX1_f32;
  float32 vehiclePosY1_f32;
  float32 vehiclePosX2_f32;
  float32 vehiclePosY2_f32;
  float32 IeFOD_e_FODConfidence;
  uint8 IeVBII_cnt_nfcd_currDetection;
} IDebug_FODObject_t;

# define Rte_TypeDef_IFPAInfoToPLD_t
typedef struct
{
  ParkingSlotID_t PLDSlotID;
} IFPAInfoToPLD_t;

# define Rte_TypeDef_ILMD_Outputs_ADASFDLANES1_t
typedef struct
{
  uint64 IeLMD_e_FrameIndexLanes1;
  uint64 IeLMD_e_CntrAdasFdLanes1;
  float32 IeLMD_e_Line1Confidence;
  float32 IeLMD_e_Line2Confidence;
  float32 IeLMD_e_Line3Confidence;
  float32 IeLMD_e_Line4Confidence;
  float32 IeLMD_m_Line1Offset;
  float32 IeLMD_m_Line2Offset;
  float32 IeLMD_m_Line3Offset;
  float32 IeLMD_m_Line4Offset;
  float32 IeLMD_rad_Line1Heading;
  float32 IeLMD_rad_Line2Heading;
  float32 IeLMD_rad_Line3Heading;
  float32 IeLMD_rad_Line4Heading;
  float32 IeLMD_m_Line1StartRange;
  float32 IeLMD_m_Line2StartRange;
  float32 IeLMD_m_Line3StartRange;
  float32 IeLMD_m_Line4StartRange;
  float32 IeLMD_m_Line1EndRange;
  float32 IeLMD_m_Line2EndRange;
  float32 IeLMD_m_Line3EndRange;
  float32 IeLMD_m_Line4EndRange;
  float32 IeLMD_e_Line1Curvature;
  float32 IeLMD_e_Line2Curvature;
  float32 IeLMD_e_Line3Curvature;
  float32 IeLMD_e_Line4Curvature;
  float32 IeLMD_e_Line1CurvatureRate;
  float32 IeLMD_e_Line2CurvatureRate;
  float32 IeLMD_e_Line3CurvatureRate;
  float32 IeLMD_e_Line4CurvatureRate;
  LaneType_t IeLMD_e_Line1Type;
  LaneType_t IeLMD_e_Line2Type;
  LaneType_t IeLMD_e_Line3Type;
  LaneType_t IeLMD_e_Line4Type;
  LaneDetHealth_t IeLMD_e_LaneDetectionHealth;
  CameraStatus_t IeLMD_e_CameraStatus;
  uint16 IeLMD_e_CrcAdasFdLanes1;
  uint8 IeLMD_e_MsgCntrAdasFdLanes1;
  uint8 IeLMD_e_MacAdasFdLanes1;
  uint8 IeLMD_e_ReservedForFunctionalSafety1;
  uint8 Dummy1_1_b;
  uint8 Dummy2_1_b;
  uint8 Dummy3_1_b;
} ILMD_Outputs_ADASFDLANES1_t;

# define Rte_TypeDef_IParkingSlotData_t
typedef struct
{
  Float2_Array Vertices;
  ParkingSlotType_t m_SlotType;
  SlotSide_t m_SlotSide;
  ParkingSlotID_t m_SlotID;
  boolean m_isSlotValid_b;
} IParkingSlotData_t;

# define Rte_TypeDef_IaNFCD_e_BlobList
typedef struct
{
  uint8 ObjectID;
  DistanceToClosestPoint_Array DistanceToClosestPoint;
  e_SensorSource SensorSource;
  ObjectPos_Real_Array ObjectPos_Real;
  BoundingBox_Real_Array BoundingBox_Real;
  ObjectDimensions_Array ObjectDimensions;
  float32 ObjVelX;
  float32 ObjVelY;
  float32 ObjAge;
  boolean ObjValid;
  TeEnv_e_ObjClass ObjClass;
} IaNFCD_e_BlobList;

# define Rte_TypeDef_IntrinsicCamID
typedef struct
{
  FinalAssemblySerialNumber_t FrontCamera;
  FinalAssemblySerialNumber_t LeftCamera;
  FinalAssemblySerialNumber_t RearCamera;
  FinalAssemblySerialNumber_t RightCamera;
} IntrinsicCamID;

# define Rte_TypeDef_IobjectEdge_t
typedef struct
{
  Float2 center;
  float32 curvature;
  endpoints_Array endpoints;
  float32 fit_err;
  float32 hitratio;
  uint16 numPoint;
  boolean isCurve;
  boolean valid;
} IobjectEdge_t;

# define Rte_TypeDef_JobDLDOutput_t
typedef struct
{
  DLDCamSts_t IeDLD_e_FrCamSts;
  DLDCamSts_t IeDLD_e_RrCamSts;
  DLDCamSts_t IeDLD_e_RyCamSts;
  DLDCamSts_t IeDLD_e_LyCamSts;
  uint8 IeDLD_p_FrCamOcclnPerc;
  uint8 IeDLD_p_FrCamLoLumPerc;
  uint8 IeDLD_p_RrCamOcclnPerc;
  uint8 IeDLD_p_RrCamLoLumPerc;
  uint8 IeDLD_p_LyCamOcclnPerc;
  uint8 IeDLD_p_LyCamLoLumPerc;
  uint8 IeDLD_p_RyCamOcclnPerc;
  uint8 IeDLD_p_RyCamLoLumPerc;
  boolean IeDLD_b_FrCamOcclnSts;
  boolean IeDLD_b_FrCamLoLumSts;
  boolean IeDLD_b_RrCamOcclnSts;
  boolean IeDLD_b_RrCamLoLumSts;
  boolean IeDLD_b_LyCamOcclnSts;
  boolean IeDLD_b_LyCamLoLumSts;
  boolean IeDLD_b_RyCamOcclnSts;
  boolean IeDLD_b_RyCamLoLumSts;
} JobDLDOutput_t;

# define Rte_TypeDef_JobTHADetOutput_t
typedef struct
{
  Point3f_c HitchLoc_p3f;
  Point2i_c HitchPix_p2d;
  Point3f_c CplrLoc_p3f;
  Point2i_c CplrPix_p2d;
  float32 CplrAng_f32;
  float32 CplrDist_f32;
  HitchDetStatus_e HitchDetctStatus_e;
  CplrDetStatus_e CplrDetctStatus_e;
  sint32 HitchCplrPixDiffLongY_s32;
  sint32 HitchCplrPixDiffLatX_s32;
  uint8 CplrDetctConf_u8;
  uint8 CplrTrackConf_u8;
  boolean StatusCplrZone_b;
  boolean CplrAngFound_b;
  boolean TrlrCplrStatus_b;
} JobTHADetOutput_t;

# define Rte_TypeDef_LC_LnCup
typedef struct
{
  sint32 width;
  sint32 height;
  sint32 startPositionX;
  sint32 startPositionY;
  LC_LnPnt leftPoint;
  LC_LnPnt rightPoint;
} LC_LnCup;

# define Rte_TypeDef_LMD_Outputs_CVPAMFDData2_t
typedef struct
{
  ILMD_Outputs_ADASFDLANES1_t LMD_Outputs_ADASFDLANES1_s;
  ILMD_Outputs_ADASFDLANES2_t LMD_Outputs_ADASFDLANES2_s;
} LMD_Outputs_CVPAMFDData2_t;

# define Rte_TypeDef_LaneParams_s
typedef struct
{
  boolean m_valid;
  uint8 m_LineID;
  Point2f_c m_DetectionPoint_Front_5m;
  Point2f_c m_DetectionPoint_Front_12m;
  Point2f_c m_DetectionPoint_Rear_5m;
  Point2f_c m_DetectionPoint_Side_0m;
  sint32 m_LaneConfidence;
  CurveModel m_curveModel;
  float32 m_radiusOfCurvature;
  LaneType_t m_LaneType;
  sint32 m_LaneTypeConfidance;
  LaneColor_t m_LaneColor;
  sint32 m_LaneColorConfidance;
  float32 m_LaneWidth;
  float32 m_LateralDistToLaneFront;
  float32 m_LateralDistToLaneRear;
  float32 m_LongitudinalDistToLane;
  float32 m_TimeToLaneCrossing;
} LaneParams_s;

# define Rte_TypeDef_ME_Hydra2defs_S_CodingTableExt_t
typedef struct
{
  boolean bValid;
  Array_11Byte ConfigCode;
  Array_10Byte TesterCode;
  Array_04Byte ProductionDate;
  uint8 CanNode14trscm_uint8;
  uint8 Variant_ID;
  uint8 CanNode27Asm_uint8;
  uint8 CanNode63ttm_uint8;
  uint8 CanNode67dtcm_uint8;
  uint8 CanNode95itcm_uint8;
  uint8 StopandStart;
  uint8 DriverSide;
  uint16 Tyresize_uint16;
  uint8 Wheelbase;
  uint8 Rearviewcamera;
  uint8 Parkwithstop;
  uint8 SteeringRatio_uint8;
  uint8 Gearboxtype;
  uint8 Drivetypevariant;
  uint8 Pamtuningset;
  uint8 Semiautopark;
  uint8 VehicleLineConfiguration_uint8;
  uint8 CountryCode_uint8;
  uint8 Srt;
  uint8 PAMConfig_uint8;
  uint8 ModelYear_uint8;
  uint8 Hybridtype;
  uint8 Pulloutcontrol;
  uint8 Surroundviewcamera;
  uint8 Forwardfacingcamera;
  uint8 Autonomylevel;
  uint8 Fullautomaticparking;
  uint8 Radiodisplay;
  uint8 Mirrortype;
  uint8 Auxiliarycamera;
  uint8 Trailerreverseguide;
  uint8 Trailersurround;
  uint8 Trailerreversesteering;
  uint8 Trailerhitchassist;
  uint8 CVPAM_Presence_uint8;
  uint8 SideDistanceWarning;
  uint8 PROXIWriteCounter;
} ME_Hydra2defs_S_CodingTableExt_t;

# define Rte_TypeDef_ME_Hydra2defs_S_PROXI_error_Data_t
typedef struct
{
  ProxiErrData_Arr ErrorFound;
  ProxiErrData_Arr ByteWithError;
  ProxiErrData_Arr BitInformationMask;
} ME_Hydra2defs_S_PROXI_error_Data_t;

# define Rte_TypeDef_ME_Hydra3defs_S_CamCalibData_t
typedef struct
{
  float32 Pitch_f32;
  float32 Yaw_f32;
  float32 Roll_f32;
  ME_Hydra3defs_E_CalibStatus_t CalibStatus_e;
  boolean NewValueAvailable_b;
  boolean OverwriteStatus_b;
} ME_Hydra3defs_S_CamCalibData_t;

# define Rte_TypeDef_ME_Hydra3defs_S_CamEOLCalibData_t
typedef struct
{
  ME_Hydra3defs_S_CamCalibData_t calibdata;
  float32 X_f32;
  float32 Y_f32;
  float32 Z_f32;
  EOLIterationData_arr EOLIterationData_au8;
  Reserved_arr Reserved_au8;
} ME_Hydra3defs_S_CamEOLCalibData_t;

# define Rte_TypeDef_ME_Hydra3defs_S_EOLStatus_t
typedef struct
{
  float32 deltaPitch_f32;
  float32 deltaYaw_f32;
  float32 deltaRoll_f32;
  float32 deltaX_f32;
  float32 deltaY_f32;
  float32 deltaZ_f32;
  ME_Hydra3defs_E_EOLAlgoState_t algoState_e;
  ME_Hydra3defs_E_EOLErrorCode_t errorCode_e;
  ME_Hydra3defs_S_EOLTargetData_t targetData_s;
  ME_Hydra3defs_E_CameraID_t camID_e;
} ME_Hydra3defs_S_EOLStatus_t;

# define Rte_TypeDef_ME_Hydra3defs_S_OCStatus_t
typedef struct
{
  float32 deltaPitch_f32;
  float32 deltaYaw_f32;
  float32 deltaRoll_f32;
  uint32 ValidFeatures_u32;
  uint32 IgnoredFeatures_u32;
  uint32 InvalidFeatures_u32;
  ME_Hydra3defs_E_OCAlgoState_t algoState_e;
  ME_Hydra3defs_E_OCErrorCode_t errorCode_e;
  ME_Hydra3defs_E_CameraID_t camID_e;
} ME_Hydra3defs_S_OCStatus_t;

# define Rte_TypeDef_ME_Proxi_MPU1_0_to_MCU1_0_t
typedef struct
{
  float32 a72_cpu_load;
  Rte_DT_ME_Proxi_MPU1_0_to_MCU1_0_t_1 state;
  uint8 PRX_RadioDispTyp_u8;
  uint8 PRX_variantID_u8;
} ME_Proxi_MPU1_0_to_MCU1_0_t;

# define Rte_TypeDef_ME_VehInpAdp_ICC_0x171
typedef struct
{
  sint16_t ICC_Start_X_Coordinate;
  sint16_t ICC_Start_Y_Coordinate;
  sint16_t ICC_dX_Coordinate;
  sint16_t ICC_dY_Coordinate;
  uint8 ADAS_DOW_Sts;
  uint8 ADAS_BSDSts;
  uint8 ADAS_DMSSts;
  uint8 ADAS_Sts_ACC_ICC;
  uint8 ADAS_ESAState;
  uint8 AEB_Sts;
  uint8 AEB_RCTB_Sts;
  uint8 AEB_ReAEB_Sts;
  uint8 ADAS_AHAB_Sts;
  uint8 ADAS_Sts_TLA;
  uint8 ADAS_TSRSts;
  uint8 ADAS_ISASts;
  uint8 ADAS_ThreatIDLeft;
  uint8 ADAS_ThreatIDRight;
  uint8 ADAS_DOW_Threat_Status;
  uint8 ADAS_DOWLeMirrWarnReq;
  uint8 ADAS_DOWRiMirrWarnReq;
  uint8 ADAS_ACCPrimTgtID;
  uint8 ADAS_ACCScndTgtID;
  uint8 ADAS_BSD_ObjDetnSts;
  uint8 ADAS_BSD_MirrWarnReq;
  uint8 ADAS_BSDLeMirrWarnReq;
  uint8 ADAS_BSDLeftThreatID;
  uint8 ADAS_BSDRightThreatID;
  uint8 ADAS_BSDWarnSetting;
  uint8 ADAS_BSDRiMirrWarnReq;
  uint8 ADAS_RAEB_ThreatID;
  uint8 ADAS_AEBThreatID;
  uint8 ADAS_RAEBAvl;
  uint8 ADAS_AEBWarnSts;
  uint8 ADAS_AEB_RCTA_WarnSide;
  uint8 ADAS_AEB_RAEB_WarnReq;
  uint8 ADAS_BrakeIntrvntnSt;
  uint8 ADAS_AEB_Typ;
  uint8 ADAS_LCA_TrajectoryX;
  uint8 ADAS_LCA_TrajectoryY;
  uint8 ADAS_LCA_TrajectoryHeadingAngle;
  uint8 ADAS_LaneCenteringHandsOnRew;
  uint8 ADAS_TLA_WarnReq;
  uint8 ADAS_TSRSignCondition;
  uint8 ADAS_SpeedLimitUnit;
  uint8 ADAS_TSRPassingCondition;
  uint8 ADAS_TSRSpeedLimitAddOn;
  uint8 ADAS_TSRSpeedLimit;
  uint8 ADAS_TSRSignName;
  uint8 ADAS_ISAOverSpeedWarning;
} ME_VehInpAdp_ICC_0x171;

# define Rte_TypeDef_ME_VehInp_to_IpcSignals_QM_t
typedef struct
{
  ME_VehInp_BCM_FD_2_QM DataInp_BCM_FD_2;
  ME_VehInp_BCM_FD_21_QM DataInp_BCM_FD_21;
  ME_VehInp_TRSKM_FD_1_QM DataInp_TRSKM_FD_1;
  ME_VehInp_FD14_BRAKE_FD_6_QM DataInp_FD14_BRAKE_FD_6;
  ME_VehInp_ORC_FD_1_QM DataInp_ORC_FD_1;
  ME_VehInp_FD14_PT_TORQUE_FD_1_QM DataInp_FD14_PT_TORQUE_FD_1;
} ME_VehInp_to_IpcSignals_QM_t;

# define Rte_TypeDef_ME_VehOut_TRSC_t
typedef struct
{
  TeTRSC_e_SpdLmtReq IeTRSC_e_SpdLmtReq;
  TeTRSC_e_VehStpReq IeTRSC_e_VehStpReq;
  TeTRSC_e_TRSCLedSts IeTRSC_e_TRSCLedSts;
  TeTRSC_e_TRSCPopupDispInfo IeTRSC_e_TRSCPopupDispInfo;
  TeTRSC_e_TRSCSts IeTRSC_e_TRSCSts;
  TeTRSC_e_TRSCStrTrqActvReq IeTRSC_e_TRSCStrTrqActvReq;
  TeTRSC_e_TrlrHitchLightCtrl IeTRSC_e_TrlrHitchLightCtrl;
  real32_T IeTRSC_M_TRSCStrTrq;
  real32_T IeTRSC_pct_TRSCStrDmp;
  uint8 IeTRSC_deg_TADAngAct;
  Rte_DT_ME_VehOut_TRSC_t_10 IeTRSC_e_TADAngActSign;
  Rte_DT_ME_VehOut_TRSC_t_11 IeTRSC_e_TrlrCalInfo;
  boolean IeTRSC_b_MoreCamReqSts;
  real32_T IeTRSC_kph_SpdLmtReq_DID;
  TeTRSC_e_VehStpReq_DID IeTRSC_e_VehStpReq_DID;
} ME_VehOut_TRSC_t;

# define Rte_TypeDef_MagnaSerialNumber_t
typedef struct
{
  char_T initialCharacter_c;
  productionLineNumber_ac productionLineNumber;
  productionYear_ac productionYear;
  productionDay_ac productionDay;
  productionSerialNumber_ac productionSerialNumber;
  productionBoardSerialNumber_ac productionBoardSerialNumber;
  char_T zeroCharacter_c;
} MagnaSerialNumber_t;

# define Rte_TypeDef_NVMSignalManager_t
typedef struct
{
  boolean m_ReadNVMParam_b;
  boolean m_WriteNVMParam_b;
  ParkINStyle_t m_ParkINStyle_e;
  IParkingSlotData_t m_ParkInSlotData;
} NVMSignalManager_t;

# define Rte_TypeDef_OutLaneInfo
typedef struct
{
  coef_img_Array coef_img;
  sint32 laneType;
  sint32 laneType_conf;
  sint32 laneDetect_conf;
  sint32 laneColor;
  sint32 laneColor_conf;
  float32 laneWidth;
  Point2f_c distantToLane_pix;
  float32 distantToLaneFront;
  float32 distantToLaneRear;
  float32 radiusOfCurvature;
  Point2f_c longituCrossCrossLanePoint_pix;
  float32 longituCrossLaneDist;
  float32 TTLC;
} OutLaneInfo;

# define Rte_TypeDef_RearBrkEvent_t
typedef struct
{
  uint8 BlockIdx_u8;
  Rte_DT_RearBrkEvent_t_1 RearBrkEvent_Arr;
} RearBrkEvent_t;

# define Rte_TypeDef_Rois
typedef struct
{
  sint32 ValidNum;
  SubRois_Array SubRois;
  RLDFeatureCountInSubRois_Array RLDFeatureCountInSubRois;
  para_Array para;
  sint32 LDW_REG_DYNAMIC_ROI_MAX_OFFSET_BTW_ROI_AND_CENTRAL_LINE;
  sint32 LDW_REG_DYNAMIC_ROI_MAX_RLD_PIXEL_COUNT;
  boolean isLeft2Right;
  boolean isRight2Left;
} Rois;

# define Rte_TypeDef_RunTimeStats_MCU2_0_t
typedef struct
{
  Rte_DT_RunTimeStats_MCU2_0_t_0 en_Task_BSWTaskTime;
  Rte_DT_RunTimeStats_MCU2_0_t_1 en_Task_APPTaskTime;
} RunTimeStats_MCU2_0_t;

# define Rte_TypeDef_RunTimeStats_MCU2_1_t
typedef struct
{
  Rte_DT_RunTimeStats_MCU2_1_t_0 en_Task_BSWTaskTime;
  Rte_DT_RunTimeStats_MCU2_1_t_1 en_Task_APPTaskTime;
  Rte_DT_RunTimeStats_MCU2_1_t_2 en_Task_SAFETYTaskTime;
} RunTimeStats_MCU2_1_t;

# define Rte_TypeDef_SPMAbrtEvent_t
typedef struct
{
  uint8 BlockIdx_u8;
  Rte_DT_SPMAbrtEvent_t_1 SPMAbrtEvent_Arr;
} SPMAbrtEvent_t;

# define Rte_TypeDef_SSM_1_0_CoreStatus
typedef struct
{
  SSM_CoreSlaveCoreStateDef CoreStatus;
  SSM_MCU_1_0_LocalAppStatus_Arr LocalAppStatus;
} SSM_1_0_CoreStatus;

# define Rte_TypeDef_SSM_2_0_CoreStatus
typedef struct
{
  SSM_CoreSlaveCoreStateDef CoreStatus;
  SSM_MCU_2_0_LocalAppStatus_Arr LocalAppStatus;
} SSM_2_0_CoreStatus;

# define Rte_TypeDef_SSM_2_1_CoreStatus
typedef struct
{
  SSM_CoreSlaveCoreStateDef CoreStatus;
  SSM_MCU_2_1_LocalAppStatus_Arr LocalAppStatus;
} SSM_2_1_CoreStatus;

# define Rte_TypeDef_SSM_QNX_CoreStatus
typedef struct
{
  SSM_CoreSlaveCoreStateDef CoreStatus;
  SSM_MCU_QNX_LocalAppStatus_Arr LocalAppStatus;
} SSM_QNX_CoreStatus;

# define Rte_TypeDef_SSM_SystemState
typedef struct
{
  SSM_SystemStateDef SystemState;
  SSM_DegradedState DegradedState;
} SSM_SystemState;

# define Rte_TypeDef_SVSToDiag_t
typedef struct
{
  ME_Hydra3defs_E_RoutineType_t Routine_ID;
  ME_Hydra3defs_E_CameraID_t Camera_ID;
  ME_Hydra3defs_E_TestPatternType_t TestPattern_ID;
  boolean Response_Ack;
  ME_Hydra3defs_E_NRCType_t NRC_ID;
} SVSToDiag_t;

# define Rte_TypeDef_SVStoTRSC_t
typedef struct
{
  aSigConverter_E_DisplayView2_t MeSVS_e_DispView2Info;
  bool_t MeSVS_b_MoreCamReq;
} SVStoTRSC_t;

# define Rte_TypeDef_SafeStateOpDef
typedef struct
{
  SafeStateActive_arr SafeStateActive;
} SafeStateOpDef;

# define Rte_TypeDef_SecureLogRecord_t
typedef struct
{
  uint8 Valid;
  uint8 RecId;
  uint16 SecId;
  uint32 GroupCnt;
  Rte_DT_SecureLogRecord_t_4 RecordEntry;
} SecureLogRecord_t;

# define Rte_TypeDef_StackUsage_MCU2_0_t
typedef struct
{
  Rte_DT_StackUsage_MCU2_0_t_0 en_Task_BSWTaskTime;
  Rte_DT_StackUsage_MCU2_0_t_1 en_Task_APPTaskTime;
} StackUsage_MCU2_0_t;

# define Rte_TypeDef_StackUsage_MCU2_1_t
typedef struct
{
  Rte_DT_StackUsage_MCU2_1_t_0 en_Task_BSWTaskTime;
  Rte_DT_StackUsage_MCU2_1_t_1 en_Task_APPTaskTime;
  Rte_DT_StackUsage_MCU2_1_t_2 en_Task_SAFETYTaskTime;
} StackUsage_MCU2_1_t;

# define Rte_TypeDef_SvsToTHA_t
typedef struct
{
  aSigConverter_E_THAScreenRequest_t MeSVS_e_THAScrResp;
  boolean MeSVS_b_THASftBtnPrsdStsToTHA;
  boolean MeSVS_b_IsConfirmBtnPrsd;
  boolean MeSVS_b_ImgDefeatReqSts;
  boolean MeSVS_b_ViewZoomSts;
  boolean MeSVS_b_THAMnvrStartBtnPrsd;
  boolean MeSVS_b_THAScrTchSts;
  boolean MeSVS_b_THAAbortReq;
} SvsToTHA_t;

# define Rte_TypeDef_SvsToVCAN_t
typedef struct
{
  boolean IeSVS_b_SPMScrnReq;
  boolean IeSVS_b_ImgDefeatReqSts;
  boolean IeSVS_b_MoreCamsReqSts;
  boolean IeSVS_b_AUXCamReqSts;
  aSigConverter_E_DisplayView2_t IeSVS_e_DispView2;
} SvsToVCAN_t;

# define Rte_TypeDef_TRSCSMVCtoDebugCAN_t
typedef struct
{
  real32_T MeTRSC_deg_StrCMD;
  real32_T ReservedTRSCSig1;
  real32_T ReservedTRSCSig2;
  uint16 MeTRSC_s_TRSCPeriodicity;
  uint16 MeTRSC_s_TRSCTimeTaken;
  uint16 MeTRSC_cnt_TRSCAliveCounter;
  boolean MeTRSC_b_TrlrCalibPopInfo;
} TRSCSMVCtoDebugCAN_t;

# define Rte_TypeDef_TRSCSMVCtoSVS_t
typedef struct
{
  TeTRSC_e_TRSCStat MeTRSC_e_TRSCStat;
  TeTRSC_e_TrlrCalInfo MeTRSC_e_TrlrCalInfoSMVC;
  real32_T MeTRSC_deg_JackKnifeAngle;
  real32_T MeTRSC_deg_JackknifeThrAngle;
  real32_T MeTRSC_deg_MaxAllowedTADAngle;
  real32_T MeTRSC_deg_KnobAngle;
  real32_T MeTRSC_M_SteeringTorqInfo;
  real32_T MeTRSC_deg_TADAngleSMVC;
  real32_T ReservedSignal1;
  real32_T ReservedSignal2;
  boolean MeTRSC_b_MoreCamSoftButtEnbl;
  boolean MeTRSC_b_TrlrRevSteeringStsInfo;
} TRSCSMVCtoSVS_t;

# define Rte_TypeDef_TRSC_Inputs_from_TrailerDetection_t
typedef struct
{
  float32 m_leftCalibrationAngle;
  float32 m_rightCalibrationAngle;
  float32 m_hitchCalibrationAngle;
  float32 m_averageIllumination;
  float32 MeTRSC_deg_TADAngle;
  float32 MeTRSC_deg_TADAngleRate;
  float32 MeTRSC_m_DetTrailerBeamLen;
  float32 MeTRSC_m_HitchLength;
  float32 MeTRSC_deg_DetJackknifeThrAngle;
  float32 MeTRSC_deg_DetJackKnifeAngle;
  uint32 MeTRSC_cnt_TrlrCalibFailCntInfo;
  TrailerAngleSign_t MeTRSC_e_TrlrAngSign;
  TrailerID_t MeTRSC_e_TrailerID;
  TeTRSC_e_TADState MeTRSC_e_TADState;
  CalibrationState_t MeTRSC_e_TADCalibrationSubstate;
  TurnAroundState_t MeTRSC_e_TurnAroundSubState;
  TeTRSC_e_TrlrCalInfo MeTRSC_e_TrlrCalInfo;
  TeTRSC_e_TrlrRecogInfo MeTRSC_e_TrlrRecogInfo;
  TeTRSC_e_TrlrPrsntInfo MeTRSC_e_TrlrPrsntInfo;
  TrailerCalibrationFailInfo_t MeTRSC_e_CalFail;
  boolean MeTRSC_b_OBTLRecalibrate;
  boolean MeTRSC_b_TrlrCalibDelayInfo;
} TRSC_Inputs_from_TrailerDetection_t;

# define Rte_TypeDef_TRSCtoDiagMgr_t
typedef struct
{
  TeVBII_e_EnblBtnSts IeTRSC_e_TRSKMBtnSts;
  TeTRSC_e_TRSKMBtnSts_DID IeTRSC_e_TRSKMBtnSts_DID;
  TeVBII_e_CenterBtnSts IeTRSC_e_TRSKMCenBtnSts;
  TeTRSC_e_TRSKMCenBtnSts_DID IeTRSC_e_TRSKMCenBtnSts_DID;
  TeTRSC_e_TRSKMSts IeTRSC_e_TRSKMSts;
  TeTRSC_e_TRSKMSts_DID IeTRSC_e_TRSKMSts_DID;
  TeVBII_e_GearEngagedForDsply IeTRSC_e_GearShiftSts;
  TeTRSC_e_GearShiftSts_DID IeTRSC_e_GearShiftSts_DID;
  uint32 IeTRSC_e_TRSCUnavailReas;
  TeTRSC_e_TRSCUnavailReas_DID IeTRSC_e_TRSCUnavailReas_DID;
  uint32 IeTRSC_e_TRSCAbortReas;
  TeTRSC_e_TRSCAbortReason_DID IeTRSC_e_TRSCAbortReas_DID;
  real32_T IeTRSC_kph_VehSpeedVSOSig;
  real32_T IeTRSC_m_TrlrWhlBaseEff;
  real32_T IeTRSC_deg_FrntWhlAng;
  real32_T IeTRSC_deg_TrlrAngKnob;
  real32_T IeTRSC_deg_JackknifeThrAngle;
  real32_T IeTRSC_M_TRSCStrTrq;
  uint16 IeTRSC_cnt_KnobPos;
  TeTRSC_e_DispView2_DID MeSVS_e_DispView2Info_DID;
  TeTRSC_e_GraphicOverlay_Sts IeTRSC_e_GraphicOverlay_Sts;
} TRSCtoDiagMgr_t;

# define Rte_TypeDef_TbAP_APSMPAOut_t
typedef struct
{
  TeAP_e_PAMSystemFault IeAP_e_PAMFlt;
  TeAP_e_PAMOffStatus2BT IeAP_e_FrntRearParkSts;
  TeAP_e_FrntSnsrStatus IeAP_e_FrntSensorActvSts;
  TeAP_e_RearSnsrStatus IeAP_e_RearSnsrActvSts;
} TbAP_APSMPAOut_t;

# define Rte_TypeDef_TbAP_DebugOut
typedef struct
{
  real32_T MeAP_deg_StrCmd;
  real32_T MeAP_a_BrkCmd;
  real32_T MeAP_a_ThrtlCmd;
  uint16 MeAP_cnt_StateDebugVar;
  uint16 MeAP_cnt_TransDebugVar;
  sint16 MeAP_cm_FrntCenterMinXDist;
  sint16 MeAP_cm_FrntLeftMinXDist;
  sint16 MeAP_cm_FrntRightMinXDist;
  sint16 MeAP_cm_RearCenterMinXDist;
  sint16 MeAP_cm_RearLeftMinXDist;
  sint16 MeAP_cm_RearRightMinXDist;
  boolean MeAP_b_VCOpPaused;
  boolean MeAP_b_BSMInterfaceTimeout;
  boolean MeAP_b_EPSInterfaceTimeout;
  boolean MeAP_b_GearShiftWaitTimeout;
  boolean MeAP_b_CamHandshakeTimeout;
  boolean MeAP_b_ObjInPathTimeout;
  boolean MeAP_b_PausedPressBtnTimeout;
  boolean MeAP_b_SeekSpdExceedTimeout;
  boolean MeAP_b_APInitSts;
  boolean MeAP_b_DriverOverride;
  boolean MeAP_b_StandStill;
  boolean MeAP_b_BSMHandshakeActv;
  boolean MeAP_b_VehCndSts;
  boolean MeAP_b_FeatureEnbl;
  boolean MeAP_b_FPADisable;
  boolean MeAP_b_RPADisable;
  boolean MeAP_b_RPAActvTrlr;
  boolean MeAP_b_PAVolDefMed;
  boolean MeAP_b_FPAVolDefMed;
  boolean MeAP_b_RPAVolDefMed;
  boolean MeAP_b_PARBActvTrlr;
  boolean MeAP_b_PARBActv4LOW;
  boolean MeAP_b_PARBDiable;
  boolean MeAP_b_PPPAActvTrlr;
  boolean MeAP_b_PPPAActv4LOW;
  boolean MeAP_b_PPPADefEng;
  boolean MeAP_b_PPPADisable;
} TbAP_DebugOut;

# define Rte_TypeDef_TbAP_DriveAssistStatOut_t
typedef struct
{
  real32_T MeAP_s_FaultWaitTime;
  TeAutoPark_e_ChimeReq IeAutoPark_e_ChimeReq;
  TeAutoPark_e_ScanDir IeAP_e_ScanDir;
  TeAutoPark_e_AutoParkStatus IeAP_e_AutoParkStatus;
  TeAP_e_AlgoState IeAP_e_AlgoState;
  TeAP_e_ParKMnvrActv IeAP_e_ParKMnvrActv;
  TeAP_e_InterfaceBSM IeAP_e_InterfaceBSM;
  TeAP_e_SPMLatCtrlReqSts IeAP_e_SPMLatCtrlReqSts;
  TeAP_e_PAMLedCtrlStatus IeAP_e_SPMLedSts;
  TeAP_e_SPMActvStat IeAP_e_SPMActvStat;
  TeAP_e_DispView2 IeAP_e_DispView2;
  TeAP_e_GearShiftReq IeAP_e_GearShiftReq;
  TeAP_e_PAMVolSig MeAP_e_PAMVolSigSVM;
  TeAP_e_PAMChimeTyp MeAP_e_PAMChimeTypSVM;
  TeAP_e_PAMChimeRepnRate MeAP_e_PAMChimeRepnRateSVM;
  uint8 IeAP_e_HMIDispReq;
  boolean IeAP_b_WrngSpdExceed;
  boolean IeAP_b_FaultStatus;
  boolean IeAP_b_ParkInOutSuccess;
  boolean IeAP_b_ParkInOutAbort;
  boolean IeAP_b_FeatureAvl;
  boolean IeAP_b_ParkOutAvailable;
  boolean IeAP_b_ImgDefeatReqSts;
  boolean IeAP_b_SPMScrnReq;
  boolean IeAP_b_SPMFailSts;
  boolean IeAP_b_SPMFaultSts;
  boolean IeAP_b_VehMnvrDirSPM;
  boolean IeAP_b_AutoParkOverride;
  boolean MeAP_b_SensorFltSts;
  boolean MeAP_b_ChimeActvReqLHFSVM;
  boolean MeAP_b_ChimeActvReqLHRSVM;
  boolean MeAP_b_ChimeActvReqRHFSVM;
  boolean MeAP_b_ChimeActvReqRHRSVM;
} TbAP_DriveAssistStatOut_t;

# define Rte_TypeDef_TbAP_FPAWarnOut_t
typedef struct
{
  TeAP_e_Alert IeAP_e_DispArcCHF;
  TeAP_e_Alert IeAP_e_DispArcLHF;
  TeAP_e_Alert IeAP_e_DispArcRHF;
  TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateLHF;
  TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateRHF;
  TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateCHF;
  boolean IeAP_b_ChimeActvReqLHF;
  boolean IeAP_b_ChimeActvReqRHF;
} TbAP_FPAWarnOut_t;

# define Rte_TypeDef_TbAP_PAStateOut_t
typedef struct
{
  TeAP_e_PAMChimeRepnRate IeAP_e_PAMChimeRepnRate;
  TeAP_e_PAMVolume IeAP_e_PAMVolSig;
  TeAP_e_PAMLedCtrlStatus IeAP_e_FrntParkLEDSts;
  TeAP_e_PAMLedCtrlStatus IeAP_e_PAMLedCtrl;
  TeAP_e_PAMChimeTyp IeAP_e_PAMChimeTyp;
  TeAP_e_PAMPopUpReq IeAP_e_ParkSensePopUpReq;
  boolean IeAP_b_PAMRearBrkReq;
  boolean IeAP_b_PAMRearCtrlSts;
} TbAP_PAStateOut_t;

# define Rte_TypeDef_TbAP_RPAWarnOut_t
typedef struct
{
  TeAP_e_Alert IeAP_e_DispArcCHR;
  TeAP_e_Alert IeAP_e_DispArcLHR;
  TeAP_e_Alert IeAP_e_DispArcRHR;
  TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateCHR;
  TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateLHR;
  TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateRHR;
  uint16 IeAP_cm_RearDisttoNearObst;
  boolean IeAP_b_ChimeActvReqLHR;
  boolean IeAP_b_ChimeActvReqRHR;
} TbAP_RPAWarnOut_t;

# define Rte_TypeDef_TbAP_SMDAInternalOut_t
typedef struct
{
  TeAP_e_ParkAssistStatus MeAP_e_ParkAssistStatus;
  TeAutoPark_e_GearCmd MeAP_e_GearCmdToHMI;
  uint8 IeAP_e_MnvActvStat;
  uint8 IeAP_e_AbortCon;
  uint8 IeAP_e_SemiParkSysSts;
  uint8 IeAP_e_DIDHMICode;
  boolean MeAP_b_AutoParkEnblSwtStuckStatus;
  boolean MeAP_b_ScanSts;
  boolean MeAP_b_ParkSlotDetctSts;
  boolean MeAP_b_ResetKM;
} TbAP_SMDAInternalOut_t;

# define Rte_TypeDef_TbAP_SMPAInternalOut_t
typedef struct
{
  TeAP_e_HMIPopUp MeAP_e_HMIPopUp;
  boolean MeAP_b_FPAStatus;
  boolean MeAP_b_RPAStatus;
  boolean MeAP_b_FPASwtStatus;
  boolean MeAP_b_RPASwtStatus;
  boolean MeAP_b_DisableDiag;
  boolean MeAP_b_RPAwithBrkStatus;
  boolean MeAP_b_SystemFail;
  boolean MeAP_b_ExternalFail;
  boolean MeAP_b_TempFail;
  boolean MeAP_b_RPAwithBrkDisable;
  boolean MeAP_b_RPADisable;
  boolean MeAP_b_FPADisable;
} TbAP_SMPAInternalOut_t;

# define Rte_TypeDef_TbAP_VCActuatorOut_t
typedef struct
{
  real32_T IeAP_nm_StrwTrqReq;
  real32_T IeAP_a_DecelMax;
  real32_T IeAP_a_DecelMin;
  real32_T IeAP_a_JerkDecelMax;
  real32_T IeAP_a_JerkDecelMin;
  real32_T IeAP_a_AcclMin;
  real32_T IeAP_a_AcclMax;
  real32_T IeAP_da_JerkAcclMax;
  real32_T IeAP_da_JerkAcclMin;
  real32_T IeAP_cm_TrgtDist;
  real32_T IeAP_kph_TrgtVehSpd;
  sint32 IeAP_e_TurnIndicReq;
  boolean IeAP_b_StandstillReq;
} TbAP_VCActuatorOut_t;

# define Rte_TypeDef_TbAP_VrntTunParam_t
typedef struct
{
  float32 KeAP_degC_OperatingTempThd;
  float32 KeAP_kph_EnblHysThd;
  float32 KeAP_kph_FrntWarnMaxSpdThd;
  float32 KeAP_kph_ParkMnvThd;
  float32 KeAP_kph_PSDOffThd;
  float32 KeAP_kph_PSDOnThd;
  float32 KeAP_kph_RearWarnMaxSpdThd;
  float32 KeAP_kph_USSActiveSpdThd;
  float32 K_e_RAEB_VehicleWidth;
  K_Overlap_Thrsld_RAEB_Array K_Overlap_Thrsld_RAEB;
  float32 KeTOS_s_InTurnDbncTm;
  float32 KeTOS_s_StrDrvDbncTm;
  float32 KeTOS_s_TurnExitDbncTm;
  float32 KeTOS_x_InTurnThd;
  float32 KeTOS_x_TurnExitThd;
  float32 keVehParam_m_DistWhlBse;
  Obj_DistTable_Array Obj_DistTable;
  float32 Overlap_Thrsld_Switch;
  float32 RAEB_Envelope_Offset;
  float32 RAEB_Lateral_Distance_Notification;
  float32 RAEB_Minimum_Object_Heigh;
  float32 sampling_time;
  keVehParam_e_VehSteerRatioTable_Array keVehParam_e_VehSteerRatioTable;
  keVehParam_e_StrWhlRatioBrkPnts_Array keVehParam_e_StrWhlRatioBrkPnts;
  float32 keInpAdptr_e_StWhOffset;
  float32 Straight_Driving_Thresold_rads2;
  float32 Steering_Angle_DeadZone_Start;
  float32 Steering_Angle_DeadZone_End;
  float32 KeAP_k_PathSepaMinSpd;
  float32 KeAP_k_PathSepaSpdRampGrd;
  float32 KeAP_k_DetWP_PreviewTime;
  float32 KeAP_k_LatPathDevPGain;
  float32 KeAP_k_LatPathDevIGain;
  float32 KeAP_k_LatPathDevDGain;
  float32 KeAP_k_LatHeadDevPGain;
  float32 KeAP_k_LatHeadDevIGain;
  float32 KeAP_k_LatHeadDevDGain;
  float32 KeAP_k_SteerUpperLimit;
  float32 KeAP_k_SteerLowerLimit;
  float32 KeAP_k_CtrlOutCollDetActivate;
  float32 KeAP_k_CtrlOutRemainDistNA;
  float32 KeAP_k_CtrlOutCollDetCollDistLimit;
  float32 KeAP_k_CtrlOutCollDetRedStopVal;
  float32 KeAP_k_CtrlOutVehSpdMaxSpotStrTime;
  float32 KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd;
  float32 KeAP_k_CtrlOutVehSpdMaxSpotSteer;
  float32 KeAP_k_BrakePGain;
  float32 KeAP_k_BrakeIGain;
  float32 KeAP_k_BrakeUpperLimit;
  float32 KeAP_k_BrakeLowerLimit;
  float32 KeAP_k_CtrlOutGearDrive;
  float32 KeAP_k_CtrlOutGearReverse;
  float32 KeAP_k_CtrlOutGearPark;
  float32 KeAP_k_WhlCircum;
  uint16 KeAP_cnt_ChimeVolChgAlert;
  uint16 KeAP_cnt_FrntChimeDisTimeThd;
  uint16 KeAP_cnt_HalfSecChimeAlert;
  uint16 KeAP_cnt_LEDBlinkTimeThd;
  uint16 KeAP_cnt_VehKeyOnTimeThd;
  uint16 KeAP_Cnt_GearFiltTimeThd;
  uint16 KeAP_cnt_TimeStep;
  uint16 KeAP_cm_ObjPrestFCDistThd;
  uint16 KeAP_cm_ObjPrestRCDistThd;
  uint16 KeAP_cm_VehicleWidth;
  uint16 KeAP_Cnt_GearOverrideTimeThd;
  uint16 KeAP_cnt_SwtStuckTimeThd;
  uint16 KeAP_s_BSMInterfaceCntTimeout;
  uint16 KeAP_s_CamHandshakeDur;
  uint16 KeAP_s_EPSInterfaceCntTimeout;
  uint16 KeAP_s_GearShiftWaitCntTimeout;
  uint16 KeAP_s_MaxStandstillTimeThd;
  uint16 KeAP_s_ObjInPathTimeoutDur;
  uint16 KeAP_s_PausedPressBtnTimeoutDur;
  uint16 KeAP_s_SeekPhaseTimeoutDur;
  uint16 KeAP_s_SpdExceedDur;
  uint16 KeAP_cnt_SPMBlinkLEDDur;
  sint16 KeAP_cm_VehContour_FSL_x;
  sint16 KeAP_cm_VehContour_FOL_x;
  sint16 KeAP_cm_VehContour_FIL_x;
  sint16 KeAP_cm_VehContour_FIR_x;
  sint16 KeAP_cm_VehContour_FOR_x;
  sint16 KeAP_cm_VehContour_FSR_x;
  sint16 KeAP_cm_VehContour_FSL_y;
  sint16 KeAP_cm_VehContour_FOL_y;
  sint16 KeAP_cm_VehContour_FIL_y;
  sint16 KeAP_cm_VehContour_FIR_y;
  sint16 KeAP_cm_VehContour_FOR_y;
  sint16 KeAP_cm_VehContour_FSR_y;
  sint16 KeAP_cm_VehContour_RSR_x;
  sint16 KeAP_cm_VehContour_ROR_x;
  sint16 KeAP_cm_VehContour_RIR_x;
  sint16 KeAP_cm_VehContour_RIL_x;
  sint16 KeAP_cm_VehContour_ROL_x;
  sint16 KeAP_cm_VehContour_RSL_x;
  sint16 KeAP_cm_VehContour_RSR_y;
  sint16 KeAP_cm_VehContour_ROR_y;
  sint16 KeAP_cm_VehContour_RIR_y;
  sint16 KeAP_cm_VehContour_RIL_y;
  sint16 KeAP_cm_VehContour_ROL_y;
  sint16 KeAP_cm_VehContour_RSL_y;
  sint16 KeAP_cm_DistZone1;
  sint16 KeAP_cm_DistZone2;
  sint16 KeAP_cm_DistZone3;
  sint16 KeAP_cm_DistZone4;
  sint16 KeAP_cm_DistZone5;
  sint16 KeAP_cm_DistZone6;
  sint16 KeAP_cnt_DebounceTimeThd;
  sint16 KeAP_cm_FrntLongDistAdj;
  sint16 KeAP_cm_HalfVehicleWidth;
  sint16 KeAP_cm_HookDistOffset;
  sint16 KeAP_cm_MaxNoObjDetctDist;
  sint16 KeAP_cm_RearLongDistAdj;
  sint16 KeAP_cm_WarnOffset;
  uint8 KeAP_e_GbTypAT;
  uint8 KeAP_pct_ObjConfidenceThd;
  uint8 Reverse_Gr_num;
  uint8 KeAP_b_AutoParkEn;
  uint8 KeAP_b_FPAEn;
  uint8 KeAP_b_FullAutoPark;
  uint8 KeAP_b_HookConnected;
  uint8 KeAP_b_RPAwithBrk;
  uint8 KeAP_b_RPAwithSurroundView;
  uint8 KeAP_b_SteerOnlyAutoPark;
  uint8 KeCMbB_b_EnblOncObjDbnc;
  uint8 dummy;
  uint8 dummy1;
  uint8 dummy2;
} TbAP_VrntTunParam_t;

# define Rte_TypeDef_TbFA_ArbiterOutput_t
typedef struct
{
  boolean IeFA_b_ChimeActvLhf;
  boolean IeFA_b_ChimeActvRhf;
  boolean IeFA_b_ChimeActvLhr;
  boolean IeFA_b_ChimeActvRhr;
  Rte_DT_TbFA_ArbiterOutput_t_4 IeFA_e_PamChimeRepRateSts;
  Rte_DT_TbFA_ArbiterOutput_t_5 IeFA_e_PamChimeTyp;
  Rte_DT_TbFA_ArbiterOutput_t_6 IeFA_e_PamVol;
} TbFA_ArbiterOutput_t;

# define Rte_TypeDef_TbSVS_S_SVSCamCalibReset_t
typedef struct
{
  ME_Hydra3defs_E_CalibrationID_t CalibrationID;
  ME_Hydra3defs_E_CameraID_t CameraID;
} TbSVS_S_SVSCamCalibReset_t;

# define Rte_TypeDef_TbSVS_e_CamCalibNVMBlockSM_t
typedef struct
{
  ME_Hydra3defs_S_CamEOLCalibData_t EOL_CamEOLCalibData_STM;
  ME_Hydra3defs_S_CamCalibData_t SC_CamCalibData_STM;
  ME_Hydra3defs_S_CamCalibData_t OC_CamCalibData_STM;
  ME_Hydra3defs_E_CameraID_t CamIDNVM_STM;
  ME_Hydra3defs_E_CalibrationID_t CamCalibIDs_STM;
} TbSVS_e_CamCalibNVMBlockSM_t;

# define Rte_TypeDef_TbSVS_e_SVSOutputToNVMCamCalibSM_t
typedef struct
{
  boolean bValid;
  uint32 FreshnessCount;
  TbSVS_e_CamCalibNVMBlockSM_t CamCalibNVMBlock_STM;
} TbSVS_e_SVSOutputToNVMCamCalibSM_t;

# define Rte_TypeDef_TbTHASmVc_DiagMgr_t
typedef struct
{
  sint32 MeTHA_px_HitchCplrPixDiffLongAtStrt;
  real32_T MeTHA_deg_RoadWhlAng;
  TeTHA_e_THASpdLimReq MeTHA_e_THASpdLimReq;
  TeTHA_e_THASteerTrqReq MeTHA_e_THASteerTrqReq;
  TeTHA_e_THARmpUpDwnSpd MeTHA_e_THARmpUpDwnSpd;
  TeTHA_e_EPBReq MeTHA_e_EPBReq;
  TeTHA_e_THAStateInfo MeTHA_e_THAStateInfo;
  boolean MeTHA_b_UsrCplrSelCnfm;
  boolean MeTHA_b_TrlrCplrStatus;
  boolean MeTHA_b_THAAbortStatus;
  boolean MeTHA_b_UsrInputTimeOut;
  boolean MeTHA_b_ViewZoomSts;
  boolean MeTHA_b_CamOccluLoLi;
} TbTHASmVc_DiagMgr_t;

# define Rte_TypeDef_TbTHASmVc_FeatureOutputs_t
typedef struct
{
  real32_T IeTHA_M_THASteerTrqInfo;
  real32_T IeTHA_pct_THAStrDamp;
  real32_T MeTHA_deg_RoadWhlAng;
  TeTHA_e_THAState IeTHA_e_THAState;
  TeTHA_e_THASpdLimReq IeTHA_e_THASpdLimReq;
  TeTHA_e_PamVol IeTHA_e_PamVol;
  TeTHA_e_PamChimeTyp IeTHA_e_PamChimeTyp;
  TeTHA_e_PamChimeRepRateSts IeTHA_e_PamChimeRepRateSts;
  TeTHA_e_THASteerTrqReq IeTHA_e_THASteerTrqReq;
  TeTHA_e_THARmpUpDwnSpd IeTHA_e_THARmpUpDwnSpd;
  TeTHA_e_EPBReq IeTHA_e_EPBReq;
  TeTHA_e_THAStateInfo MeTHA_e_THAStateInfo;
  TeTHA_e_ScreenRequest MeTHA_e_ScreenRequest;
  TeTHA_e_RearBrkSupprInfo MeTHA_e_RearBrkSupprInfo;
  boolean IeTHA_b_ChimeActvLhf;
  boolean IeTHA_b_ChimeActvRhf;
  boolean IeTHA_b_ChimeActvLhr;
  boolean IeTHA_b_ChimeActvRhr;
  boolean MeTHA_b_EnblRearParkAsstTrg;
  boolean MeTHA_b_UsrHitchCnfm;
  boolean MeTHA_b_UsrCplrSelCnfm;
  boolean MeTHA_b_TrlrCplrStatus;
  boolean MeTHA_b_THAAbortStatus;
} TbTHASmVc_FeatureOutputs_t;

# define Rte_TypeDef_TeTRSC_e_TrailerCalibMemClearResponse_t
typedef struct
{
  Rte_DT_TeTRSC_e_TrailerCalibMemClearResponse_t_0 CalibMemClearResponse;
  boolean bValid;
} TeTRSC_e_TrailerCalibMemClearResponse_t;

# define Rte_TypeDef_TrailerDetection_Output_DID_t
typedef struct
{
  float32 Trailer_tracking_confidence;
  float32 Trailer_Recognition_Confidence;
  TrlrCalInfo_t Trailer_Calibration_Status;
  State_t Trailer_Calibration_maneuver_State;
  uint32 Trailer_Calibration_Fail_Count;
  TrailerCalibrationFailInfo_t Trailer_Calibration_Fail_Reason;
  uint32 Trailer_Calibration_Pass_Count;
  TrailerPresentInfo_t Trailer_Presence_detection;
  TrailerID_t Trailer_Recognition_ID;
  RecognitionInfo_t Trailer_known_or_Unknown;
  DetectionFailInfo_t trailerDetectionFailReason;
  float32 Trailer_Angle_current;
  TeTRSC_e_CamBlockSts IeTRSC_e_CamBlockSts;
  TeTRSC_e_TrailerCalibMemClearResponse_t IeTRSC_e_TrailerCalibMemClearResponse_t;
  CalibrationState_DID_t Trailer_Calibration_maneuver_State_DID;
  TeTRSC_e_TrlrCalInfo_DID Trailer_Calibration_Status_DID;
  uint32 Trailer_Calibration_Fail_Count_Current_key_cycle;
  TrailerCalibrationFailInfo_DID_t Trailer_Calibration_Fail_Reason_DID;
  uint32 Trailer_Calibration_Pass_Count_Current_key_cycle;
  TeTRSC_e_TrlrPrsntInfo_DID Trailer_Presence_detection_DID;
  DetectionFailInfo_DID_t trailerDetectionFailReason_DID;
  TeTRSC_e_TrlrRecogInfo_DID Trailer_known_or_Unknown_DID;
  float32 Trailer_detection_Confidence;
} TrailerDetection_Output_DID_t;

# define Rte_TypeDef_US_ME_SensorFiringModeOutputBuff_t
typedef struct
{
  uint32 timestamp;
  uint8 sensorFiringMode;
  rsv_Array rsv;
} US_ME_SensorFiringModeOutputBuff_t;

# define Rte_TypeDef_US_ME_SnsDat_FrontPSM_Echoes_t
typedef struct
{
  uint16 Sig_SnsDat_FSL_Timestamp_us;
  uint16 Sig_SnsDat_FSL_DirEcho1_cm;
  uint16 Sig_SnsDat_FSL_DirEcho2_cm;
  sint16_t Sig_SnsDat_FSR_Timestamp_us;
  uint16 Sig_SnsDat_FSR_DirEcho1_cm;
  uint16 Sig_SnsDat_FSR_DirEcho2_cm;
} US_ME_SnsDat_FrontPSM_Echoes_t;

# define Rte_TypeDef_US_S_DebugMsg_t
typedef struct
{
  Sig_Debug_Signal_Arr Sig_Debug_Signal;
  Unsig_Debug_Signal_Arr Unsig_Debug_Signal;
} US_S_DebugMsg_t;

# define Rte_TypeDef_US_S_Firing_Sequence_t
typedef struct
{
  uint8 Sig_Current_Firing_Sequence;
  rsv_Array rsv;
} US_S_Firing_Sequence_t;

# define Rte_TypeDef_US_S_MarriageSensorIDs_t
typedef struct
{
  boolean bValid;
  uint32 uMarriageStatus;
  uSavedSensorIDs_au32 uSavedSensorIDs;
} US_S_MarriageSensorIDs_t;

# define Rte_TypeDef_US_S_PointDistOutputBuff_t
typedef struct
{
  uint32 timestamp;
  minDist_Array minDist;
  midDist_Array midDist;
} US_S_PointDistOutputBuff_t;

# define Rte_TypeDef_US_S_PointMapOutputBuff_t
typedef struct
{
  uint32 timestamp;
  US_S_PointOutputBuff_Array pointMap;
} US_S_PointMapOutputBuff_t;

# define Rte_TypeDef_US_S_SensorTemp_t
typedef struct
{
  sint16_t sSensorTemp_FSR;
  sint16_t sSensorTemp_FOR;
  sint16_t sSensorTemp_FIR;
  sint16_t sSensorTemp_FIL;
  sint16_t sSensorTemp_FOL;
  sint16_t sSensorTemp_FSL;
  sint16_t sSensorTemp_RSR;
  sint16_t sSensorTemp_ROR;
  sint16_t sSensorTemp_RIR;
  sint16_t sSensorTemp_RIL;
  sint16_t sSensorTemp_ROL;
  sint16_t sSensorTemp_RSL;
} US_S_SensorTemp_t;

# define Rte_TypeDef_US_S_SnrDirEcho_t
typedef struct
{
  US_ME_SnsDat_Front_Direct_t FrontSnrDirEcho1;
  US_ME_SnsDat_Front_Direct_2_t FrontSnrDirEcho2;
  US_ME_SnsDat_FrontPSM_Echoes_t FrontPSMEcho;
  US_ME_SnsDat_Rear_Direct_t RearSnrDirEcho1;
  US_ME_SnsDat_Rear_Direct_2_t RearSnrDirEcho2;
  US_ME_SnsDat_RearSide_Echoes_t RearSideEcho;
} US_S_SnrDirEcho_t;

# define Rte_TypeDef_US_S_USSDataCollectionData_t
typedef struct
{
  Log_SnrMeasData1_Array Log_SnrMeasData_01;
  Log_SnrMeasData2_Array Log_SnrMeasData_02;
  Log_SnrMeasData3_Array Log_SnrMeasData_03;
  Log_SnrMeasData4_Array Log_SnrMeasData_04;
  Log_SnrMeasData5_Array Log_SnrMeasData_05;
  Log_SnrMeasData6_Array Log_SnrMeasData_06;
  Log_SnrMeasData7_Array Log_SnrMeasData_07;
  Log_SnrTemperature_Array Log_SnrTemperature;
  Log_PackedNoiseMeasData_Array Log_PackedNoiseMeasData;
  Log_PackedDiagFlagData1_v_Array Log_PackedDiagFlagData1_v;
  Log_PackedDiagFlagData2_v_Array Log_PackedDiagFlagData2_v;
} US_S_USSDataCollectionData_t;

# define Rte_TypeDef_US_S_USSErrorDiagData_t
typedef struct
{
  US_S_DiagnosticsOutputBuff_t ErrorMsg;
  uint16 live_detection;
  uint16 rsv_u16;
} US_S_USSErrorDiagData_t;

# define Rte_TypeDef_US_S_USSPartNumberData_t
typedef struct
{
  uUSSPartNumPSM_FSR_arr uUSSPartNum_FSR;
  uUSSPartNumPDC_FOR_arr uUSSPartNum_FOR;
  uUSSPartNumPDC_FIR_arr uUSSPartNum_FIR;
  uUSSPartNumPDC_FIL_arr uUSSPartNum_FIL;
  uUSSPartNumPDC_FOL_arr uUSSPartNum_FOL;
  uUSSPartNumPSM_FSL_arr uUSSPartNum_FSL;
  uUSSPartNumPDC_RSR_arr uUSSPartNum_RSR;
  uUSSPartNumPDC_ROR_arr uUSSPartNum_ROR;
  uUSSPartNumPDC_RIR_arr uUSSPartNum_RIR;
  uUSSPartNumPDC_RIL_arr uUSSPartNum_RIL;
  uUSSPartNumPDC_ROL_arr uUSSPartNum_ROL;
  uUSSPartNumPDC_RSL_arr uUSSPartNum_RSL;
} US_S_USSPartNumberData_t;

# define Rte_TypeDef_US_S_USSPeriodDiagData_t
typedef struct
{
  US_S_DrivingFrequency_t SnrDrvFreq;
  US_S_RigningFrequency_t SnrRingFreq;
  US_S_RigningTime_t SnrRingTime;
  US_S_SensorTemp_t SnrTemperature;
  US_S_SnrPowerSupply_t SnrPwr;
  US_S_uBlockageSetCnt_t BlockageSetCnt;
  US_S_uBlockageClrCnt_t BlockageClrCnt;
} US_S_USSPeriodDiagData_t;

# define Rte_TypeDef_US_S_USSVersion_t
typedef struct
{
  uint32 US_CalVer;
  uint16 US_SnrVer;
  uint8 US_ModuleVer_YEAR;
  uint8 US_ModuleVer_WEEK;
  uint8 US_ModuleVer_DAY;
  uint8 US_ModuleVer_BUILD;
  rev_arr Rsv;
} US_S_USSVersion_t;

# define Rte_TypeDef_US_S_ZoneInfo_t
typedef struct
{
  uint32 timestamp;
  US_E_Zoneinfo_list_Array zoneInfo;
} US_S_ZoneInfo_t;

# define Rte_TypeDef_UssPowerSense
typedef struct
{
  float32 v_USS_PWR_A_MON_f32;
  float32 v_USS_PWR_B_MON_f32;
  float32 v_USS_PWR_C_MON_f32;
  Rte_DT_UssPowerSense_3 v_USS_PWR_IS1_MON_MON_f32;
  float32 v_USS_PWR_IS2_MON_MON_f32;
} UssPowerSense;

# define Rte_TypeDef_UssTunningData_mcu2_1_t
typedef struct
{
  UssTunningDataOut_arr UssTunningDataOut;
} UssTunningData_mcu2_1_t;

# define Rte_TypeDef_VehInpAdapter_opVehSignals
typedef struct
{
  ME_VehInpAdp_ESP_0x318 dt_ESP_0x318;
  ME_VehInpAdp_ESP_0x261 dt_ESP_0x261;
  ME_VehInpAdp_ESP_0x305 dt_ESP_0x305;
  ME_VehInpAdp_ESP_0x306 dt_ESP_0x306;
  ME_VehInpAdp_ESP_0x268 dt_ESP_0x268;
  ME_VehInpAdp_ESP_0x120 dt_ESP_0x120;
  ME_VehInpAdp_ESP_0x122 dt_ESP_0x122;
  ME_VehInpAdp_iBooster_0x271 dt_iBooster_0x271;
  ME_VehInpAdp_EPS_0x1C2 dt_EPS_0x1C2;
  ME_VehInpAdp_EPS_0x1C4 dt_EPS_0x1C4;
  ME_VehInpAdp_EPS_0x475 dt_EPS_0x475;
  ME_VehInpAdp_ACU_0x59 dt_ACU_0x59;
  ME_VehInpAdp_ACU_0x159 dt_ACU_0x159;
  ME_VehInpAdp_ESP_0x30A dt_ESP_0x30A;
  ME_VehInpAdp_BCM_0x335 dt_BCM_0x335;
  ME_VehInpAdp_BCM_0x343 dt_BCM_0x343;
  ME_VehInpAdp_ECC_0x373 dt_ECC_0x373;
  ME_VehInpAdp_PLGM_0x471 dt_PLGM_0x471;
  ME_VehInpAdp_CIM_0x310 dt_CIM_0x310;
  ME_VehInpAdp_VCU_0x225 dt_VCU_0x225;
  ME_VehInpAdp_VCU_0x214 dt_VCU_0x214;
  ME_VehInpAdp_ICC_0x531 dt_ICC_0x531;
  ME_VehInpAdp_ICC_0x530 dt_ICC_0x530;
  ME_VehInpAdp_BCM_0x333 dt_BCM_0x333;
  ME_VehInpAdp_MCU_F_0x150 dt_MCU_F_0x150;
  ME_VehInpAdp_ESP_0x125 dt_ESP_0x125;
  ME_VehInpAdp_MFS_0x514 dt_MFS_0x514;
  ME_VehInpAdp_ICC_0x361 dt_ICC_0x361;
  ME_VehInpAdp_ICC_0x250 dt_ICC_0x250;
  ME_VehInpAdp_ICC_0x251 dt_ICC_0x251;
  ME_VehInpAdp_ICC_0x362 dt_ICC_0x362;
  ME_VehInpAdp_ICC_0x252 dt_ICC_0x252;
  ME_VehInpAdp_ICC_0x253 dt_ICC_0x253;
  ME_VehInpAdp_ICC_0x255 dt_ICC_0x255;
  ME_VehInpAdp_VCU_0x1BA dt_VCU_0x1BA;
  ME_VehInpAdp_ESP_0x1B8 dt_ESP_0x1B8;
  ME_VehInpAdp_ESP_0x262 dt_ESP_0x262;
  ME_VehInpAdp_TRM_0x348 dt_TRM_0x348;
  ME_VehInpAdp_TBOX_0x525 dt_TBOX_0x525;
  ME_VehInpAdp_TBOX_0x24B dt_TBOX_0x24B;
  ME_VehInpAdp_TBOX_0x24C dt_TBOX_0x24C;
  ME_VehInpAdp_TBOX_0x36 dt_TBOX_0x36;
  ME_VehInpAdp_YRS_0x242 dt_YRS_0x242;
  ME_VehInpAdp_YRS_0x246 dt_YRS_0x246;
  ME_VehInpAdp_ICC_0x52A dt_ICC_0x52A;
  ME_VehInpAdp_ICC_0x171 dt_ICC_0x171;
} VehInpAdapter_opVehSignals;

# define Rte_TypeDef_AP_HMI_ParkSlot_Array
typedef AP_HMI_ParkSlot_t AP_HMI_ParkSlot_Array[6];

# define Rte_TypeDef_Data1_0B_arr
typedef ErrorMgr_stAddData Data1_0B_arr[400];

# define Rte_TypeDef_Data1_0QM_arr
typedef ErrorMgr_stAddData Data1_0QM_arr[12];

# define Rte_TypeDef_Data2_0B_arr
typedef ErrorMgr_stAddData Data2_0B_arr[144];

# define Rte_TypeDef_Data2_0QM_arr
typedef ErrorMgr_stAddData Data2_0QM_arr[1];

# define Rte_TypeDef_Data2_1B_arr
typedef ErrorMgr_stAddData Data2_1B_arr[548];

# define Rte_TypeDef_Data2_1QM_arr
typedef ErrorMgr_stAddData Data2_1QM_arr[1];

# define Rte_TypeDef_DataQNXB_arr
typedef ErrorMgr_stAddData DataQNXB_arr[8];

# define Rte_TypeDef_DataQNXQM_arr
typedef ErrorMgr_stAddData DataQNXQM_arr[1];

# define Rte_TypeDef_IParkingSlotData_Array
typedef IParkingSlotData_t IParkingSlotData_Array[6];

# define Rte_TypeDef_LeftObjectList_Array
typedef IobjectEdge_t LeftObjectList_Array[4];

# define Rte_TypeDef_ME_Hydra3defs_S_EOLStatus_arr
typedef ME_Hydra3defs_S_EOLStatus_t ME_Hydra3defs_S_EOLStatus_arr[4];

# define Rte_TypeDef_ME_Hydra3defs_S_OCStatus_arr
typedef ME_Hydra3defs_S_OCStatus_t ME_Hydra3defs_S_OCStatus_arr[4];

# define Rte_TypeDef_NFCD_EnvSignals_Array
typedef IaNFCD_e_BlobList NFCD_EnvSignals_Array[10];

# define Rte_TypeDef_RightObjectList_Array
typedef IobjectEdge_t RightObjectList_Array[4];

# define Rte_TypeDef_output_Array
typedef OutLaneInfo output_Array[2];

# define Rte_TypeDef_stUSSParkingSlotData_Array
typedef IParkingSlotData_t stUSSParkingSlotData_Array[6];

# define Rte_TypeDef_stepArray_Array
typedef LC_LnCup stepArray_Array[60];

# define Rte_TypeDef_CamEepromProductionData_t
typedef struct
{
  constantStartSequence_ac constantStartSequence;
  MagnaSerialNumber_t magnaSerialNumber_s;
  FinalAssemblySerialNumber_t finalAssemblySerialNumber_s;
  finalAssemblyPartNumber_ac finalAssemblyPartNumber;
  eepromMapRevision_au16 eepromMapRevision;
  reservedBytes_au8 reservedBytes;
} CamEepromProductionData_t;

# define Rte_TypeDef_CameraEepromData_t
typedef struct
{
  CamEepromProductionData_t camProductionData_s;
  CamEepromIntrinsicData_t camIntrinsicData_s;
  CamEepromCrcData_t camCrcData_s;
} CameraEepromData_t;

# define Rte_TypeDef_ErrorMgr_ErrorCommPack_1_0_B
typedef struct
{
  uint32 RunningCounter;
  uint32 Checksum;
  Error1_0B_arr Error;
  Data1_0B_arr Data;
} ErrorMgr_ErrorCommPack_1_0_B;

# define Rte_TypeDef_ErrorMgr_ErrorCommPack_1_0_QM
typedef struct
{
  uint32 RunningCounter;
  uint32 Checksum;
  Error1_0QM_arr Error;
  Data1_0QM_arr Data;
} ErrorMgr_ErrorCommPack_1_0_QM;

# define Rte_TypeDef_ErrorMgr_ErrorCommPack_2_0_B
typedef struct
{
  uint32 RunningCounter;
  uint32 Checksum;
  Error2_0B_arr Error;
  Data2_0B_arr Data;
} ErrorMgr_ErrorCommPack_2_0_B;

# define Rte_TypeDef_ErrorMgr_ErrorCommPack_2_0_QM
typedef struct
{
  uint32 RunningCounter;
  uint32 Checksum;
  Error2_0QM_arr Error;
  Padding2_0QM_arr Padding;
  Data2_0QM_arr Data;
} ErrorMgr_ErrorCommPack_2_0_QM;

# define Rte_TypeDef_ErrorMgr_ErrorCommPack_2_1_B
typedef struct
{
  uint32 RunningCounter;
  uint32 Checksum;
  Error2_1B_arr Error;
  Data2_1B_arr Data;
} ErrorMgr_ErrorCommPack_2_1_B;

# define Rte_TypeDef_ErrorMgr_ErrorCommPack_2_1_QM
typedef struct
{
  uint32 RunningCounter;
  uint32 Checksum;
  Error2_1QM_arr Error;
  Padding2_1QM_arr Padding;
  Data2_1QM_arr Data;
} ErrorMgr_ErrorCommPack_2_1_QM;

# define Rte_TypeDef_ErrorMgr_ErrorCommPack_QNX_B
typedef struct
{
  uint32 RunningCounter;
  uint32 Checksum;
  ErrorQNXB_arr Error;
  DataQNXB_arr Data;
} ErrorMgr_ErrorCommPack_QNX_B;

# define Rte_TypeDef_ErrorMgr_ErrorCommPack_QNX_QM
typedef struct
{
  uint32 RunningCounter;
  uint32 Checksum;
  ErrorQNXQM_arr Error;
  PaddingQNXQM_arr Padding;
  DataQNXQM_arr Data;
} ErrorMgr_ErrorCommPack_QNX_QM;

# define Rte_TypeDef_IFPAInfoToHMI_t
typedef struct
{
  IParkingSlotData_Array stFPAParkingSlotData;
  IParkingSlotData_t stFPALockedSlotData;
  float32 LockedSlotWidth;
  float32 LockedSlotDepth;
  m_Parkable_Array m_Parkable;
  IAllowedParkingDirection_Array m_ParkableInDIrection;
  boolean ParkOutEnableFlag;
} IFPAInfoToHMI_t;

# define Rte_TypeDef_IFPAInfoToUSSOM_t
typedef struct
{
  ParkingSlotID_t USSOMSlotID;
  IParkingSlotData_t ParkOutSlotData;
} IFPAInfoToUSSOM_t;

# define Rte_TypeDef_IFPAInfoToVC_t
typedef struct
{
  IParkingSlotData_t stFPALockedSlotData;
  float32 LockedSlotWidth;
  float32 LockedSlotDepth;
  ParkOutStyle_t parkOutStyle;
} IFPAInfoToVC_t;

# define Rte_TypeDef_IJobPLDOutput_t
typedef struct
{
  boolean isPLDInitSuccess_b;
  IParkingSlotData_Array stPLDParkingSlotData;
  IParkingSlotData_t stPLDLockedSlotData;
} IJobPLDOutput_t;

# define Rte_TypeDef_IJobUSSObjectMapOutput_t
typedef struct
{
  boolean isUSSOMInitSuccess_b;
  stUSSParkingSlotData_Array stUSSParkingSlotData;
  uint16 numPointsL;
  uint16 numPointsR;
  LeftObjectList_Array LeftObjectList;
  RightObjectList_Array RightObjectList;
  IParkingSlotData_t stUSSLockedSlotData;
} IJobUSSObjectMapOutput_t;

# define Rte_TypeDef_INVMSignalManager_t
typedef struct
{
  boolean m_ReadNVMParam_b;
  boolean m_WriteNVMParam_b;
  ParkINStyle_t m_ParkINStyle_e;
  IParkingSlotData_t m_ParkInSlotData;
} INVMSignalManager_t;

# define Rte_TypeDef_LC_LnModel
typedef struct
{
  stepArray_Array stepArray;
  sint32 averageLaneWidth;
  sint32 countLaneStep;
  laneCoef_2dArray laneCoef;
  laneCoef_TVG_2dArray laneCoef_TVG;
  laneCoef_TVG_valid_Array laneCoef_TVG_valid;
  lanTrack_s_Array lanTrack_s;
  output_Array output;
} LC_LnModel;

# define Rte_TypeDef_LaneLists_s
typedef struct
{
  LaneParams_s m_LeftLane;
  LaneParams_s m_RightLane;
} LaneLists_s;

# define Rte_TypeDef_ME_Hydra3defs_S_CamCalibDataSTM_t
typedef struct
{
  ME_Hydra3defs_S_CamCalibData_t CamCalibData_STM;
  ME_Hydra3defs_E_CalibrationID_t CamCalibIDs_STM;
} ME_Hydra3defs_S_CamCalibDataSTM_t;

# define Rte_TypeDef_ME_Hydra3defs_S_CamEOLCalibDataSTM_t
typedef struct
{
  ME_Hydra3defs_S_CamEOLCalibData_t CamCalibData_STM;
  ME_Hydra3defs_E_CalibrationID_t CamCalibIDs_STM;
} ME_Hydra3defs_S_CamEOLCalibDataSTM_t;

# define Rte_TypeDef_NFCD_Output
typedef struct
{
  NFCD_EnvSignals_Array NFCD_EnvSignals;
  uint8 IeVBII_cnt_nfcd_currDetection;
  float32 IeVBII_nfcd_DetectionTimestamp;
  float32 IeVBII_nfcd_MinDistanceToCollisionObject;
  TeEnv_e_NFCDState NFCDState;
} NFCD_Output;

# define Rte_TypeDef_ScreenRequest_t
typedef struct
{
  OverlayBits_t MbSVS_bf_OverlayBitsReq;
  AP_HMI_ParkSlot_Array AP_HMI_ParkSlot;
  ParkingSlotID_t AP_HMI_SelectedSlot;
  AP_HMI_Fullscreen_t AP_HMI_Fullscreen;
  AP_HMI_TopBlackBanner_t AP_HMI_TopBlackBanner;
  AP_HMI_TopRedBanner_t AP_HMI_TopRedBanner;
  AP_HMI_BottomBlackBanner_t AP_HMI_BottomBlackBanner;
  aSigConverter_E_THAScreenRequest_t MeSVS_e_THAScreenRequesttoA72;
  sint8 MeSVS_DesiredTrailerAngle;
  sint8 MeSVS_ActualTrailerAngle;
  sint8 MeSVS_Orage_Arc_StartAngle;
  sint8 MeSVS_Red_Arc_StartAngle;
  uint16 MeSVS_pct_ProgressBar;
  uint16 MeSVS_px_CplrPosX;
  uint16 MeSVS_px_CplrPosY;
  uint16 MeSVS_px_ScrnTchX;
  uint16 MeSVS_px_ScrnTchY;
  sint16 MeSVS_deg_StrWhlAng;
  uint16 MeSVS_e_CRCRReq;
  uint8 MeSVS_e_ViewEngReqCode;
  uint8 ZoomFactor_u8;
  boolean MeSVS_b_ZoomPressedReq;
} ScreenRequest_t;

# define Rte_TypeDef_ScreenResponse_t
typedef struct
{
  OverlayBits_t MbSVS_bf_OverlayBitsRes;
  AP_HMI_ParkSlot_Array AP_HMI_ParkSlot;
  ParkingSlotID_t AP_HMI_SelectedSlot;
  AP_HMI_Fullscreen_t AP_HMI_Fullscreen;
  AP_HMI_TopBlackBanner_t AP_HMI_TopBlackBanner;
  AP_HMI_TopRedBanner_t AP_HMI_TopRedBanner;
  AP_HMI_BottomBlackBanner_t AP_HMI_BottomBlackBanner;
  float32 Pixel_X_to_RealWord_X_cm;
  float32 Pixel_Y_to_RealWord_Y_cm;
  aSigConverter_E_THAScreenRequest_t MeSVS_e_THAScreenResponse;
  sint8 MeSVS_DesiredTrailerAngle;
  sint8 MeSVS_ActualTrailerAngle;
  sint8 MeSVS_Orage_Arc_StartAngle;
  sint8 MeSVS_Red_Arc_StartAngle;
  uint16 MeSVS_pct_ProgressBar;
  uint16 MeSVS_px_CplrPosX;
  uint16 MeSVS_px_CplrPosY;
  uint16 MeSVS_px_ScrnTchX;
  uint16 MeSVS_px_ScrnTchY;
  sint16 MeSVS_deg_StrWhlAng;
  uint16 MeSVS_e_CRCRReq;
  uint8 MeSVS_e_ViewEngResCode;
  uint8 ZoomFactor_u8;
  uint8 RenderedRadioDispType;
  uint8 MeSVS_b_ZoomPressedRes;
  boolean THAViewZoomResponse;
} ScreenResponse_t;

# define Rte_TypeDef_TbSVS_S_SVSCamCurrentCalibData_t
typedef struct
{
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamFrontCurrent;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamLeftCurrent;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamRearCurrent;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamRightCurrent;
} TbSVS_S_SVSCamCurrentCalibData_t;

# define Rte_TypeDef_TbSVS_S_SVSCamEOLCalibData_t
typedef struct
{
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamFrontEOL;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamLeftEOL;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamRearEOL;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamRightEOL;
} TbSVS_S_SVSCamEOLCalibData_t;

# define Rte_TypeDef_TbSVS_S_SVSCamOCCalibData_t
typedef struct
{
  ME_Hydra3defs_S_CamCalibDataSTM_t CamFrontOC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamLeftOC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamRearOC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamRightOC;
} TbSVS_S_SVSCamOCCalibData_t;

# define Rte_TypeDef_TbSVS_S_SVSCamSCCalibData_t
typedef struct
{
  ME_Hydra3defs_S_CamCalibDataSTM_t CamFrontSC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamLeftSC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamRearSC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamRightSC;
} TbSVS_S_SVSCamSCCalibData_t;

# define Rte_TypeDef_TbSVS_e_SVSOutputToDiagMgrCamCalib_t
typedef struct
{
  boolean EOL_v_IsRequestedByDiag_b;
  boolean SC_v_IsRequestedByDiag_b;
  boolean EOLCompletedCurrentCycle;
  boolean SCCompletedCurrentCycle;
  aZynqM_S_EOL_Conditions_t EOL_StartConditions_STM;
  aZynqM_S_SCConditions_t SC_StartConditions_STM;
  aZynqM_S_OC_Conditions_t OC_StartConditions_STM;
  aZynqM_E_ModuleState_EOL_STM_t EOL_ModuleState_STM;
  aZynqM_E_ModuleState_SC_STM_t SC_ModuleState_STM;
  aZynqM_E_ModuleState_OC_STM_t OC_ModuleState_STM;
  ME_Hydra3defs_S_EOLStatus_arr EOL_Status_STM;
  ME_Hydra3defs_S_OCStatus_arr SC_Status_STM;
  ME_Hydra3defs_S_OCStatus_arr OC_Status_STM;
  ME_Hydra3defs_E_CalibStatus_arr EOL_CalibStatus_STM;
  ME_Hydra3defs_E_CalibStatus_arr SC_CalibStatus_STM;
  ME_Hydra3defs_E_CalibStatus_arr OC_CalibStatus_STM;
} TbSVS_e_SVSOutputToDiagMgrCamCalib_t;

# define Rte_TypeDef_US_S_PointMapGroup_t
typedef struct
{
  US_ME_FiringSensorsOutputBuff_t FiringSensors;
  US_ME_SensorFiringModeOutputBuff_t FiringMode;
  US_S_PointMapOutputBuff_t PointMap;
  US_S_Firing_Sequence_t FiringSequence;
} US_S_PointMapGroup_t;

# define Rte_TypeDef_US_S_USSConstantData_t
typedef struct
{
  US_S_USSPartNumberData_t SensorPartNum;
  US_S_SnrIMESerialNum_t SensorIMESerialNum;
  US_S_SnrMurataSerialNum_t SensorMurataSerialNum;
  US_S_USSVersion_t USS_Ver;
} US_S_USSConstantData_t;

# define Rte_TypeDef_CameraEepromData_arr
typedef CameraEepromData_t CameraEepromData_arr[4];

# define Rte_TypeDef_CDP_TbSVS_S_SVSCamCurrentCalibData_t
typedef struct
{
  uint8 calibrated;
  TbSVS_S_SVSCamCurrentCalibData_t data;
  uint16 PrevOdoValue;
} CDP_TbSVS_S_SVSCamCurrentCalibData_t;

# define Rte_TypeDef_CDP_TbSVS_S_SVSCamEOLCalibData_t
typedef struct
{
  uint8 calibrated;
  TbSVS_S_SVSCamEOLCalibData_t data;
  uint16 PlantOdoValue;
} CDP_TbSVS_S_SVSCamEOLCalibData_t;

# define Rte_TypeDef_CDP_TbSVS_S_SVSCamOCCalibData_t
typedef struct
{
  uint8 calibrated;
  TbSVS_S_SVSCamOCCalibData_t data;
} CDP_TbSVS_S_SVSCamOCCalibData_t;

# define Rte_TypeDef_CDP_TbSVS_S_SVSCamSCCalibData_t
typedef struct
{
  uint8 calibrated;
  TbSVS_S_SVSCamSCCalibData_t data;
} CDP_TbSVS_S_SVSCamSCCalibData_t;

# define Rte_TypeDef_CalDataProvider_MCU_1_0_Def
typedef struct
{
  TbSVS_S_SVSCamCurrentCalibData_t CalData_SVSCamCurrentCalibData;
  TbSVS_S_SVSCamEOLCalibData_t CalData_SVSCamEOLCalibData;
  TbSVS_S_SVSCamOCCalibData_t CalData_SVSCamOCCalibData;
  TbSVS_S_SVSCamSCCalibData_t CalData_SVSCamSCCalibData;
  uint32 FreshnessCount;
  uint16 CalData_PlantOdoValue;
  uint16 CalData_PrevOdoValue;
  boolean bValid;
} CalDataProvider_MCU_1_0_Def;

# define Rte_TypeDef_DebugDumpAlgo
typedef struct
{
  Rois o_ProcessRoi;
  LC_LnModel o_egoLaneModel;
  uint32 imgWidth;
  uint32 imgHeight;
  boolean showLaneInfo;
} DebugDumpAlgo;

# define Rte_TypeDef_IJobFPAOutput_t
typedef struct
{
  boolean AutoParkInitializedStatus_b;
  IFPAInfoToVC_t m_FpaInfoToVC;
  IFPAInfoToPLD_t m_FPAInfoToPLD;
  IFPAInfoToUSSOM_t m_FPAInfoToUSSOM;
  IFPAInfoToHMI_t m_FPAInfoToHMI;
  INVMSignalManager_t m_FPAToNVM;
} IJobFPAOutput_t;

# define Rte_TypeDef_Lane_Outputs_Debug_t
typedef struct
{
  LaneLists_s m_TotalLanes;
  DebugDumpAlgo m_DebugInfo;
} Lane_Outputs_Debug_t;

# define Rte_TypeDef_Svs_CamEepromDataArray_t
typedef struct
{
  CameraEepromData_arr CameraEepromData;
} Svs_CamEepromDataArray_t;

# define Rte_TypeDef_TbSVS_S_SVSCamCurrentCalibDataToNVM_t
typedef struct
{
  boolean bValid;
  uint32 FreshnessCount;
  TbSVS_S_SVSCamCurrentCalibData_t CamCurrent;
} TbSVS_S_SVSCamCurrentCalibDataToNVM_t;

# define Rte_TypeDef_TbSVS_S_SVSCamEOLCalibDataToNVM_t
typedef struct
{
  boolean bValid;
  uint32 FreshnessCount;
  TbSVS_S_SVSCamEOLCalibData_t CamEOL;
} TbSVS_S_SVSCamEOLCalibDataToNVM_t;

# define Rte_TypeDef_TbSVS_S_SVSCamOCCalibDataToNVM_t
typedef struct
{
  boolean bValid;
  uint32 FreshnessCount;
  ME_Hydra3defs_E_CameraID_t LastOCCurrentCam;
  TbSVS_S_SVSCamOCCalibData_t CamOC;
} TbSVS_S_SVSCamOCCalibDataToNVM_t;

# define Rte_TypeDef_TbSVS_S_SVSCamSCCalibDataToNVM_t
typedef struct
{
  boolean bValid;
  uint32 FreshnessCount;
  TbSVS_S_SVSCamSCCalibData_t CamSC;
} TbSVS_S_SVSCamSCCalibDataToNVM_t;

# define Rte_TypeDef_LMD_Lane_Outputs_s
typedef struct
{
  Lane_Outputs_Debug_t Lane_Outputs_Debug_s;
} LMD_Lane_Outputs_s;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_Csm_DataPtr
typedef uint8 * Csm_DataPtr;

#  define Rte_TypeDef_Csm_LengthPtr
typedef uint32 * Csm_LengthPtr;

#  define Rte_TypeDef_Csm_const_DataPtr
typedef const uint8 * Csm_const_DataPtr;

#  define Rte_TypeDef_Dcm_Data5003ByteType
typedef uint8 Dcm_Data5003ByteType[5003];

#  define Rte_TypeDef_Dummy4_b_Array
typedef uint32 Dummy4_b_Array[187];

#  define Rte_TypeDef_FD14_MAC_CVPAM_FD_Data
typedef uint8 FD14_MAC_CVPAM_FD_Data[6];

#  define Rte_TypeDef_FD14_MAC_CVPAM_FD_Data2
typedef uint8 FD14_MAC_CVPAM_FD_Data2[6];

#  define Rte_TypeDef_FD14_RawPntDebugSignal
typedef uint8 FD14_RawPntDebugSignal[8];

#  define Rte_TypeDef_FirstEchoIdxF_Array
typedef uint16 FirstEchoIdxF_Array[6];

#  define Rte_TypeDef_FirstEchoIdxR_Array
typedef uint16 FirstEchoIdxR_Array[6];

#  define Rte_TypeDef_FrontDir_Echo1_Array
typedef uint16 FrontDir_Echo1_Array[6];

#  define Rte_TypeDef_FrontDir_Echo2_Array
typedef uint16 FrontDir_Echo2_Array[6];

#  define Rte_TypeDef_FrontDistances_Array
typedef float32 FrontDistances_Array[6];

#  define Rte_TypeDef_FrontInDir_Array
typedef uint16 FrontInDir_Array[10];

#  define Rte_TypeDef_FrontZones_Array
typedef uint8 FrontZones_Array[6];

#  define Rte_TypeDef_KsTHA_deg_StrToRdWhlAngTD_Array
typedef float32 KsTHA_deg_StrToRdWhlAngTD_Array[17];

#  define Rte_TypeDef_KsTHA_k_ErrxHeadingErrTD_Array
typedef float32 KsTHA_k_ErrxHeadingErrTD_Array[4];

#  define Rte_TypeDef_KsTHA_k_ErrxPropGainTD_Array
typedef float32 KsTHA_k_ErrxPropGainTD_Array[5];

#  define Rte_TypeDef_KsTHA_k_StrToRdWhlAngGain_Array
typedef float32 KsTHA_k_StrToRdWhlAngGain_Array[3];

#  define Rte_TypeDef_KsTHA_k_StrToRdWhlAngOffset_Array
typedef float32 KsTHA_k_StrToRdWhlAngOffset_Array[3];

#  define Rte_TypeDef_KsTHA_kph_DistSpdTD_Array
typedef float32 KsTHA_kph_DistSpdTD_Array[6];

#  define Rte_TypeDef_KsTHA_mps_DistSpdTD_Array
typedef float32 KsTHA_mps_DistSpdTD_Array[6];

#  define Rte_TypeDef_MAC_CVPAM_FD_Data
typedef uint8 MAC_CVPAM_FD_Data[6];

#  define Rte_TypeDef_MAC_CVPAM_FD_Data2
typedef uint8 MAC_CVPAM_FD_Data2[6];

#  define Rte_TypeDef_RearDir_Echo1_Array
typedef uint16 RearDir_Echo1_Array[6];

#  define Rte_TypeDef_RearDir_Echo2_Array
typedef uint16 RearDir_Echo2_Array[6];

#  define Rte_TypeDef_RearDistances_Array
typedef float32 RearDistances_Array[6];

#  define Rte_TypeDef_RearInDir_Array
typedef uint16 RearInDir_Array[10];

#  define Rte_TypeDef_RearZones_Array
typedef uint8 RearZones_Array[6];

#  define Rte_TypeDef_StayActiveSource_FD02_CADM2
typedef uint64 StayActiveSource_FD02_CADM2[8];

#  define Rte_TypeDef_StayActiveSource_FD02_TRLR_REV
typedef uint64 StayActiveSource_FD02_TRLR_REV[8];

#  define Rte_TypeDef_USS_Bumper_Layout_Array
typedef float32 USS_Bumper_Layout_Array[48];

#  define Rte_TypeDef_adas_feature_RSVD
typedef uint32 adas_feature_RSVD[128];

#  define Rte_TypeDef_adas_feature_StrngRatio_t
typedef float32 adas_feature_StrngRatio_t[51];

#  define Rte_TypeDef_defaultHitchPoint_Array
typedef sint32 defaultHitchPoint_Array[2];

#  define Rte_TypeDef_dummy2_Array
typedef uint32 dummy2_Array[235];

#  define Rte_TypeDef_hitchYOffset_Array
typedef uint32 hitchYOffset_Array[2];

#  define Rte_TypeDef_reserved_Array
typedef uint8 reserved_Array[2];

#  define Rte_TypeDef_sensor_sensitivity_Array
typedef uint8 sensor_sensitivity_Array[32];

#  define Rte_TypeDef_trailerBeamLengthRange_mm_Array
typedef float32 trailerBeamLengthRange_mm_Array[2];

#  define Rte_TypeDef_uPntDebugData_Array
typedef uint8 uPntDebugData_Array[64];

#  define Rte_TypeDef_CanDebugSts
typedef struct
{
  uint8 Routine_Sts;
} CanDebugSts;

#  define Rte_TypeDef_HmiSM_Generic_t
typedef struct
{
  float32 HmiGen_Reserve_01;
  float32 HmiGen_Reserve_02;
  float32 HmiGen_Reserve_03;
  float32 HmiGen_Reserve_10;
  float32 HmiGen_Reserve_11;
  float32 HmiGen_Reserve_12;
  float32 HmiGen_Reserve_13;
  float32 HmiGen_Reserve_20;
  float32 HmiGen_Reserve_21;
  float32 HmiGen_Reserve_22;
  float32 HmiGen_Reserve_23;
  float32 HmiGen_Reserve_30;
  float32 HmiGen_Reserve_31;
  float32 HmiGen_Reserve_32;
  float32 HmiGen_Reserve_33;
} HmiSM_Generic_t;

#  define Rte_TypeDef_HmiSM_Tuning_t
typedef struct
{
  uint8 HMI_XCP_LOCKOUTWAITCYCLES;
  uint8 HMI_XCP_SCREENREQ_TIMEOUT;
  uint8 HMI_XCP_K_TDELAYPRND;
  float32 HMI_XCP_VIDEO_ON_SPEED;
  float32 HMI_XCP_VIDEO_OFF_SPEED;
  float32 HMI_XCP_PDC_THRESHOLD_SPEED;
  float32 HMI_XCP_RVC_VIEWRESET_SPEED;
  float32 HMI_XCP_TRG_PANGUARD_SPEED;
  float32 TRG_LEFT_TAD_MAX;
  float32 TRG_LEFT_TAD_MIN;
  float32 TRG_75L25R_TAD_MAX;
  float32 TRG_75L25R_TAD_MIN;
  float32 TRG_50L50R_TAD_MAX;
  float32 TRG_50L50R_TAD_MIN;
  float32 TRG_25L75R_TAD_MAX;
  float32 TRG_25L75R_TAD_MIN;
  float32 TRG_RIGHT_TAD_MAX;
  float32 TRG_RIGHT_TAD_MIN;
} HmiSM_Tuning_t;

#  define Rte_TypeDef_ITbFOD_VrntTunParam_s
typedef struct
{
  float32 KeFOD_mm_LongiDistThd;
  float32 KeFOD_mm_LatiDistThd;
  float32 KeFOD_mm_DistY1Thd;
  float32 KeFOD_mm_DistY2Thd;
  float32 KeFOD_cm_ObjDetctXThd;
} ITbFOD_VrntTunParam_s;

#  define Rte_TypeDef_ITbLMD_VrntTunParam_t
typedef struct
{
  float32 KeLMD_rollThd;
  float32 KeLMD_yawThd;
  float32 KeLMD_PitchThd;
  uint32 keVehParam_m_WhlBse;
  float32 Straight_Driving_Thresold;
  uint32 Steering_Angle;
  float32 keLMD_offset1Thd;
  float32 keLMD_curvature1Thd;
  float32 keLMD_Heading1Thd;
  float32 keLMD_confidence1Thd;
  float32 keLMD_offset2Thd;
  float32 keLMD_curvature2Thd;
  float32 keLMD_Heading2Thd;
  float32 keLMD_confidence2Thd;
  float32 keLMD_offset3Thd;
  float32 keLMD_curvature3Thd;
  float32 keLMD_Heading3Thd;
  float32 keLMD_confidence3Thd;
  float32 keLMD_offset4Thd;
  float32 keLMD_curvature4Thd;
  float32 keLMD_Heading4Thd;
  float32 keLMD_confidence4Thd;
  float32 keLMD_segmentConf1_Thd;
  float32 keLMD_segmentConf2_Thd;
  float32 keLMD_segmentConf3_Thd;
  float32 keLMD_segmentConf4_Thd;
  float32 keLMD_segmentConf5_Thd;
  float32 keLMD_segmentConf6_Thd;
  float32 keLMD_segmentConf7_Thd;
  float32 keLMD_segmentConf8_Thd;
} ITbLMD_VrntTunParam_t;

#  define Rte_TypeDef_PointOnImage
typedef struct
{
  sint16 cord_x;
  sint16 cord_y;
} PointOnImage;

#  define Rte_TypeDef_TbAPFPA_AlgoTunParam_t
typedef struct
{
  float32 TOPVIEW_IMAGE_RESOLUTION_X;
  float32 TOPVIEW_IMAGE_RESOLUTION_Y;
  float32 PERP_DEFAULT_LENGTH;
  float32 PERP_DEFAULT_WIDTH;
  float32 PARA_DEFAULT_LENGTH;
  float32 PARA_DEFAULT_WIDTH;
  float32 PERP_MINIMUM_LENGTH;
  float32 PERP_MINIMUM_WIDTH;
  float32 PARA_MINIMUM_LENGTH;
  float32 PARA_MINIMUM_WIDTH;
  float32 PARKABLE_PERP_MINIMUM_LENGTH;
  float32 PARKABLE_PERP_MINIMUM_WIDTH;
  float32 PARKABLE_PARA_MINIMUM_LENGTH;
  float32 PARKABLE_PARA_MINIMUM_WIDTH;
  float32 MinParaLongDist;
  float32 MinParaLatDist;
  float32 MinPerpLongDist;
  float32 MinPerpLatDist;
  float32 MaxParaLongDist;
  float32 MaxParaLatDist;
  float32 MaxPerpLongDist;
  float32 MaxPerpLatDist;
  float32 IOU_CUTOFF;
  float32 NUM_USSPOINTS;
  float32 SIDE_OFFSET;
  float32 REQ_SLOT_WIDTH;
  float32 PIX_OFFSET;
  float32 REQ_SLOT_DEPTH;
  float32 MIN_CAR_WIDTH;
  float32 MIN_CAR_DEPTH;
  float32 AP_PARA_Maximum_Slot_Depth;
  float32 AP_PARA_Maximum_Slot_Width;
  float32 AP_PERP_Maximum_Slot_Depth;
  float32 AP_PERP_Maximum_Slot_Width;
  float32 AP_PERP_Minimum_Slot_Depth;
  float32 AP_PERP_Minimum_Slot_Width;
  float32 AP_PARA_Minimum_Slot_Depth;
  float32 AP_PARA_Minimum_Slot_Width;
  float32 AP_PARA_Slot_Width_Parking_Gap;
  float32 AP_PERP_Slot_Width_Parking_Gap;
  float32 AP_PERP_Parking_Gap_Slot_Depth;
  uint8 AP_Distance_D1_Lower_Limit;
  uint8 AP_Distance_D2_Upper_Limit;
  uint8 AP_Angle_Tolerance;
  sint8 FUSION_ENABLE;
  uint8 PLD_Enable;
  uint8 USSOM_Enable;
  uint8 dummy1;
  uint8 dummy2;
} TbAPFPA_AlgoTunParam_t;

#  define Rte_TypeDef_TbAPPLD_AlgoTunParam_t
typedef struct
{
  float32 WHEEL_BASE_M;
  float32 TOPVIEW_IMAGE_RESOLUTION_X;
  float32 TOPVIEW_IMAGE_RESOLUTION_Y;
  float32 Variant_WhlAngCFWt;
  float32 Variant_WhlAngCFBias;
  uint16 scanPerpLineMin;
  uint16 scanPerpLineMax;
  uint16 scanParaLineMin;
  uint16 scanParaLineMax;
  uint16 scanFishLineMin;
  uint16 scanFishLineMax;
  uint16 perpGapWidthMin;
  uint16 perpGapWidthMax;
  uint16 paraGapWidthMin;
  uint16 paraGapWidthMax;
  uint16 fishGapWidthMin;
  uint16 fishGapWidthMax;
  uint16 gapLockDistance;
  uint16 maximumIDThreshold;
  uint16 scanSmallROI_x_L;
  uint16 scanSmallROI_y_L;
  uint16 scanSmallROI_width_L;
  uint16 scanSmallROI_height_L;
  uint16 scanBigROI_x_L;
  uint16 scanBigROI_y_L;
  uint16 scanBigROI_width_L;
  uint16 scanBigROI_height_L;
  uint16 scanSmallROI_x;
  uint16 scanSmallROI_y;
  uint16 scanSmallROI_width;
  uint16 scanSmallROI_height;
  uint16 scanBigROI_x;
  uint16 scanBigROI_y;
  uint16 scanBigROI_width;
  uint16 scanBigROI_height;
  uint8 lineBufferSize;
  uint8 lineBufferSize_L;
  uint8 LINE_INPUT_ENABLE_L;
  uint8 LINE_INPUT_ENABLE;
} TbAPPLD_AlgoTunParam_t;

#  define Rte_TypeDef_UssCom_S_DebugMsgSigned_t
typedef struct
{
  sint16 Sig_Debug_Signal_4;
  sint16 Sig_Debug_Signal_3;
  sint16 Sig_Debug_Signal_2;
  sint16 Sig_Debug_Signal_1;
} UssCom_S_DebugMsgSigned_t;

#  define Rte_TypeDef_UssCom_S_DebugMsgUnsigned_t
typedef struct
{
  uint16 Sig_Debug_Signal_8;
  uint16 Sig_Debug_Signal_7;
  uint16 Sig_Debug_Signal_6;
  uint16 Sig_Debug_Signal_5;
} UssCom_S_DebugMsgUnsigned_t;

#  define Rte_TypeDef_UssCom_S_ObjectDetOutputBuff_t
typedef struct
{
  sint16 centerX;
  sint16 centerY;
  sint16 closeX;
  sint16 closeY;
  uint8 height;
  uint8 confidence;
  uint8 age;
  uint8 diameter;
} UssCom_S_ObjectDetOutputBuff_t;

#  define Rte_TypeDef_UssCom_S_OdometryData_t
typedef struct
{
  float32 dx_m;
  float32 dy_m;
  float32 dyaw_rad;
  uint32 timestamp_s;
} UssCom_S_OdometryData_t;

#  define Rte_TypeDef_UssCom_S_SnrPowerSupply_t
typedef struct
{
  uint16 uUSSPowerAMonVtg;
  uint16 uUSSPowerBMonVtg;
  uint16 uUSSPowerCMonVtg;
  uint16 uUSSPowerIS1Current;
  uint16 uUSSPowerIS2Current;
  uint16 Reserved;
} UssCom_S_SnrPowerSupply_t;

#  define Rte_TypeDef_UssCom_S_SnsDatLeftSidePanelEchoesMsg_t
typedef struct
{
  uint16 Sig_SnrDat_sBOL_Indir_AOL_cm;
  uint16 Sig_SnrDat_sAOL_Indir_BOL_cm;
  uint16 Sig_SnrDat_BOL_Dir2_cm;
  uint16 Sig_SnrDat_BOL_Dir1_cm;
  uint16 Sig_SnrDat_AOL_Dir2_cm;
  uint16 Sig_SnrDat_AOL_Dir1_cm;
} UssCom_S_SnsDatLeftSidePanelEchoesMsg_t;

#  define Rte_TypeDef_UssCom_S_SnsDatRightSidePanelEchoesMsg_t
typedef struct
{
  uint16 Sig_SnrDat_sBOR_Indir_AOR_cm;
  uint16 Sig_SnrDat_sAOR_Indir_BOR_cm;
  uint16 Sig_SnrDat_BOR_Dir2_cm;
  uint16 Sig_SnrDat_BOR_Dir1_cm;
  uint16 Sig_SnrDat_AOR_Dir2_cm;
  uint16 Sig_SnrDat_AOR_Dir1_cm;
} UssCom_S_SnsDatRightSidePanelEchoesMsg_t;

#  define Rte_TypeDef_UssCom_S_SnsDat_EchoIndex_t
typedef struct
{
  uint8 Sig_SnrDat_FSR_EchoIndex;
  uint8 Sig_SnrDat_FOR_EchoIndex;
  uint8 Sig_SnrDat_FIR_EchoIndex;
  uint8 Sig_SnrDat_FIL_EchoIndex;
  uint8 Sig_SnrDat_FOL_EchoIndex;
  uint8 Sig_SnrDat_FSL_EchoIndex;
  uint8 Sig_SnrDat_RSR_EchoIndex;
  uint8 Sig_SnrDat_ROR_EchoIndex;
  uint8 Sig_SnrDat_RIR_EchoIndex;
  uint8 Sig_SnrDat_RIL_EchoIndex;
  uint8 Sig_SnrDat_ROL_EchoIndex;
  uint8 Sig_SnrDat_RSL_EchoIndex;
} UssCom_S_SnsDat_EchoIndex_t;

#  define Rte_TypeDef_UssCom_S_SnsDat_Front_Indirect_1_t
typedef struct
{
  uint16 Sig_SnrDat_sFSR_Indir_FOR_cm;
  uint16 Sig_SnrDat_sFOR_Indir_FSR_cm;
  uint16 Sig_SnrDat_sFOR_Indir_FIR_cm;
  uint16 Sig_SnrDat_sFIR_Indir_FOR_cm;
  uint16 Sig_SnrDat_sFIR_Indir_FIL_cm;
  uint16 Sig_SnrDat_sFIL_Indir_FIR_cm;
} UssCom_S_SnsDat_Front_Indirect_1_t;

#  define Rte_TypeDef_UssCom_S_SnsDat_Front_Indirect_2_t
typedef struct
{
  uint16 Sig_SnrDat_sFIL_Indir_FOL_cm;
  uint16 Sig_SnrDat_sFOL_Indir_FIL_cm;
  uint16 Sig_SnrDat_sFOL_Indir_FSL_cm;
  uint16 Sig_SnrDat_sFSL_Indir_FOL_cm;
} UssCom_S_SnsDat_Front_Indirect_2_t;

#  define Rte_TypeDef_UssCom_S_SnsDat_Rear_Indirect_1_t
typedef struct
{
  uint16 Sig_SnrDat_sRIR_Indir_RIL_cm;
  uint16 Sig_SnrDat_sRIL_Indir_RIR_cm;
  uint16 Sig_SnrDat_sRIL_Indir_ROL_cm;
  uint16 Sig_SnrDat_sROL_Indir_RIL_cm;
  uint16 Sig_SnrDat_sROL_Indir_RSL_cm;
  uint16 Sig_SnrDat_sRSL_Indir_ROL_cm;
} UssCom_S_SnsDat_Rear_Indirect_1_t;

#  define Rte_TypeDef_UssCom_S_SnsDat_Rear_Indirect_2_t
typedef struct
{
  uint16 Sig_SnrDat_sRSR_Indir_ROR_cm;
  uint16 Sig_SnrDat_sROR_Indir_RSR_cm;
  uint16 Sig_SnrDat_sROR_Indir_RIR_cm;
  uint16 Sig_SnrDat_sRIR_Indir_ROR_cm;
} UssCom_S_SnsDat_Rear_Indirect_2_t;

#  define Rte_TypeDef_UssCom_S_SnsDataDirectEco_t
typedef struct
{
  uint16 SnsDataFSLTimestamp;
  uint16 SnsDataFSLDirEcho1_cm;
  uint16 SnsDataFSLDirEcho2_cm;
  uint16 SnsDataFSRTimestamp;
  uint16 SnsDataFSRDirEcho1_cm;
  uint16 SnsDataFSRDirEcho2_cm;
  uint16 SnsDataRSLTimestamp;
  uint16 SnsDataRSLDirEcho1_cm;
  uint16 SnsDataRSLDirEcho2_cm;
  uint16 SnsDataRSRTimestamp;
  uint16 SnsDataRSRDirEcho1_cm;
  uint16 SnsDataRSRDirEcho2_cm;
} UssCom_S_SnsDataDirectEco_t;

#  define Rte_TypeDef_UssCom_S_TestDataMux_t
typedef struct
{
  uint16 uDirEcho;
  uint16 uEchoHeight;
  uint16 uRingTime;
  uint16 uDrvFreq;
  uint16 uRingFreq;
  uint8 uBlockageSetCnt;
  uint8 uBlockageClrCnt;
} UssCom_S_TestDataMux_t;

#  define Rte_TypeDef_aZynqM_S_EOLCamMask_t
typedef struct
{
  uint8 camFront;
  uint8 camLeft;
  uint8 camRear;
  uint8 camRight;
} aZynqM_S_EOLCamMask_t;

#  define Rte_TypeDef_AlgoState_e
typedef uint32 AlgoState_e;

#  define Rte_TypeDef_BOOL
typedef boolean BOOL;

#  define Rte_TypeDef_CplrHitchSts_e
typedef uint32 CplrHitchSts_e;

#  define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;

#  define Rte_TypeDef_ErrorMgr_enSafeStates
typedef uint32 ErrorMgr_enSafeStates;

#  define Rte_TypeDef_FD14_1_ErrHook_CurrErr_MCU1_0
typedef uint8 FD14_1_ErrHook_CurrErr_MCU1_0;

#  define Rte_TypeDef_FD14_1_ErrHook_DtErr_MCU1_0
typedef uint8 FD14_1_ErrHook_DtErr_MCU1_0;

#  define Rte_TypeDef_FD14_1_ErrHook_Error_MCU1_0
typedef uint8 FD14_1_ErrHook_Error_MCU1_0;

#  define Rte_TypeDef_FD14_1_ErrHook_Service_MCU1_0
typedef uint8 FD14_1_ErrHook_Service_MCU1_0;

#  define Rte_TypeDef_FD14_1_ErrHook_actTsk_MCU1_0
typedef uint8 FD14_1_ErrHook_actTsk_MCU1_0;

#  define Rte_TypeDef_FD14_1_Panic_Hook_MCU1_0
typedef uint32 FD14_1_Panic_Hook_MCU1_0;

#  define Rte_TypeDef_FD14_1_ProtHook_CurrErr_MCU1_0
typedef uint8 FD14_1_ProtHook_CurrErr_MCU1_0;

#  define Rte_TypeDef_FD14_1_ProtHook_DtErr_MCU1_0
typedef uint8 FD14_1_ProtHook_DtErr_MCU1_0;

#  define Rte_TypeDef_FD14_1_ProtHook_Error_MCU1_0
typedef uint8 FD14_1_ProtHook_Error_MCU1_0;

#  define Rte_TypeDef_FD14_1_ProtHook_Service_MCU1_0
typedef uint8 FD14_1_ProtHook_Service_MCU1_0;

#  define Rte_TypeDef_FD14_1_ProtHook_actTsk_MCU1_0
typedef uint8 FD14_1_ProtHook_actTsk_MCU1_0;

#  define Rte_TypeDef_FD14_UssParkingModeSignal
typedef uint8 FD14_UssParkingModeSignal;

#  define Rte_TypeDef_FLOAT32
typedef float32 FLOAT32;

#  define Rte_TypeDef_FLOAT64
typedef float64 FLOAT64;

#  define Rte_TypeDef_IeParkAssist_e_Front_ChimeReq
typedef uint32 IeParkAssist_e_Front_ChimeReq;

#  define Rte_TypeDef_IeParkAssist_e_OpState
typedef uint32 IeParkAssist_e_OpState;

#  define Rte_TypeDef_IeParkAssist_e_Rear_ChimeReq
typedef uint32 IeParkAssist_e_Rear_ChimeReq;

#  define Rte_TypeDef_ParkingMode
typedef uint32 ParkingMode;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD01_BCM_0
typedef uint8 Rte_DT_StayActiveSource_FD01_BCM_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD01_SGW_0
typedef uint8 Rte_DT_StayActiveSource_FD01_SGW_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD02_BCM_0
typedef uint8 Rte_DT_StayActiveSource_FD02_BCM_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD02_BSM2_0
typedef uint8 Rte_DT_StayActiveSource_FD02_BSM2_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD02_EPS_0
typedef uint8 Rte_DT_StayActiveSource_FD02_EPS_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD02_ORC_0
typedef uint8 Rte_DT_StayActiveSource_FD02_ORC_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD02_SGW_0
typedef uint8 Rte_DT_StayActiveSource_FD02_SGW_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD03_BCM_0
typedef uint8 Rte_DT_StayActiveSource_FD03_BCM_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD03_SGW_0
typedef uint8 Rte_DT_StayActiveSource_FD03_SGW_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD04_BCM_0
typedef uint8 Rte_DT_StayActiveSource_FD04_BCM_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD08_SGW_0
typedef uint8 Rte_DT_StayActiveSource_FD08_SGW_0;

#  define Rte_TypeDef_Rte_DT_StayActiveSource_FD11_SGW_0
typedef uint8 Rte_DT_StayActiveSource_FD11_SGW_0;

#  define Rte_TypeDef_SINT16
typedef sint16 SINT16;

#  define Rte_TypeDef_SINT32
typedef sint32 SINT32;

#  define Rte_TypeDef_SINT8
typedef sint8 SINT8;

#  define Rte_TypeDef_TeFA_e_PamChimeRepRateSts
typedef uint32 TeFA_e_PamChimeRepRateSts;

#  define Rte_TypeDef_TeFA_e_PamChimeTyp
typedef uint32 TeFA_e_PamChimeTyp;

#  define Rte_TypeDef_TeFA_e_PamVol
typedef uint32 TeFA_e_PamVol;

#  define Rte_TypeDef_UINT16
typedef uint16 UINT16;

#  define Rte_TypeDef_UINT32
typedef uint32 UINT32;

#  define Rte_TypeDef_UINT64
typedef uint64 UINT64;

#  define Rte_TypeDef_UINT8
typedef uint8 UINT8;

#  define Rte_TypeDef_UssCom_E_BumperState_t
typedef uint32 UssCom_E_BumperState_t;

#  define Rte_TypeDef_UssCom_E_SystemState_t
typedef uint32 UssCom_E_SystemState_t;

#  define Rte_TypeDef_aSigConverter_E_ViewReq_t
typedef uint32 aSigConverter_E_ViewReq_t;

#  define Rte_TypeDef_int32_T
typedef sint32 int32_T;

#  define Rte_TypeDef_m_Parkable
typedef boolean m_Parkable;

#  define Rte_TypeDef_Error1_0A_arr
typedef ErrorMgr_ErrorField Error1_0A_arr[1];

#  define Rte_TypeDef_Error2_0A_arr
typedef ErrorMgr_ErrorField Error2_0A_arr[1];

#  define Rte_TypeDef_Error2_1A_arr
typedef ErrorMgr_ErrorField Error2_1A_arr[1];

#  define Rte_TypeDef_ErrorQNXA_arr
typedef ErrorMgr_ErrorField ErrorQNXA_arr[1];

#  define Rte_TypeDef_KaTRA_deg_TADLUTBrkPts_Array
typedef real32_T KaTRA_deg_TADLUTBrkPts_Array[3];

#  define Rte_TypeDef_KaTRA_deg_TADLUTTblData_Array
typedef real32_T KaTRA_deg_TADLUTTblData_Array[3];

#  define Rte_TypeDef_KaTRA_deg_TAD_IGainLUTBrkPts_Array
typedef real32_T KaTRA_deg_TAD_IGainLUTBrkPts_Array[2];

#  define Rte_TypeDef_KaTRA_k_PGainLUTTblData_Array
typedef real32_T KaTRA_k_PGainLUTTblData_Array[4];

#  define Rte_TypeDef_KaTRA_k_TADLUTTblData_Array
typedef real32_T KaTRA_k_TADLUTTblData_Array[3];

#  define Rte_TypeDef_KaTRA_k_TAD_IGainLUTTblData_Array
typedef real32_T KaTRA_k_TAD_IGainLUTTblData_Array[2];

#  define Rte_TypeDef_KaTRA_k_TravDistLUTTblData_Array
typedef real32_T KaTRA_k_TravDistLUTTblData_Array[2];

#  define Rte_TypeDef_KaTRA_k_VehSpdLUTTblData_Array
typedef real32_T KaTRA_k_VehSpdLUTTblData_Array[2];

#  define Rte_TypeDef_KaTRA_k_VehSpd_HdgDeviatLUTTblData_Array
typedef real32_T KaTRA_k_VehSpd_HdgDeviatLUTTblData_Array[3];

#  define Rte_TypeDef_KaTRA_k_VehSpd_IGainLUTTblData_Array
typedef real32_T KaTRA_k_VehSpd_IGainLUTTblData_Array[2];

#  define Rte_TypeDef_KaTRA_m_PGainLUTYBrkPts_Array
typedef real32_T KaTRA_m_PGainLUTYBrkPts_Array[2];

#  define Rte_TypeDef_KaTRA_m_TravDistLUTBrkPts_Array
typedef real32_T KaTRA_m_TravDistLUTBrkPts_Array[2];

#  define Rte_TypeDef_KaTRA_rate_RateGuardXdat_Array
typedef real32_T KaTRA_rate_RateGuardXdat_Array[8];

#  define Rte_TypeDef_KaTRA_rate_RateGuardYdat_Array
typedef real32_T KaTRA_rate_RateGuardYdat_Array[8];

#  define Rte_TypeDef_KaTRA_v_PGainLUTXBrkPts_Array
typedef real32_T KaTRA_v_PGainLUTXBrkPts_Array[2];

#  define Rte_TypeDef_KaTRA_v_VehSpdLUTBrkPts_Array
typedef real32_T KaTRA_v_VehSpdLUTBrkPts_Array[2];

#  define Rte_TypeDef_KaTRA_v_VehSpd_HdgDeviatLUTBrkPts_Array
typedef real32_T KaTRA_v_VehSpd_HdgDeviatLUTBrkPts_Array[3];

#  define Rte_TypeDef_KaTRA_v_VehSpd_IGainLUTBrkPts_Array
typedef real32_T KaTRA_v_VehSpd_IGainLUTBrkPts_Array[2];

#  define Rte_TypeDef_KaTRSC_deg_FtWhlAngPts_Array
typedef real32_T KaTRSC_deg_FtWhlAngPts_Array[37];

#  define Rte_TypeDef_KaTRSC_deg_PGainLUTYBrkPts_Arr
typedef real32_T KaTRSC_deg_PGainLUTYBrkPts_Arr[5];

#  define Rte_TypeDef_KaTRSC_deg_StwAngPts_Array
typedef real32_T KaTRSC_deg_StwAngPts_Array[37];

#  define Rte_TypeDef_KaTRSC_k_DampingGainTblData_Arr
typedef real32_T KaTRSC_k_DampingGainTblData_Arr[4];

#  define Rte_TypeDef_KaTRSC_k_DiffGainTblData_Arr
typedef real32_T KaTRSC_k_DiffGainTblData_Arr[4];

#  define Rte_TypeDef_KaTRSC_k_InputRateLimTblData_Arr
typedef real32_T KaTRSC_k_InputRateLimTblData_Arr[4];

#  define Rte_TypeDef_KaTRSC_k_IntegratorExtSatTblData_Arr
typedef real32_T KaTRSC_k_IntegratorExtSatTblData_Arr[4];

#  define Rte_TypeDef_KaTRSC_k_IntegratorGainTblData_Arr
typedef real32_T KaTRSC_k_IntegratorGainTblData_Arr[4];

#  define Rte_TypeDef_KaTRSC_k_PGainLUTTblData_Arr
typedef real32_T KaTRSC_k_PGainLUTTblData_Arr[20];

#  define Rte_TypeDef_KaTRSC_kph_DampingGainBrkPts_Arr
typedef real32_T KaTRSC_kph_DampingGainBrkPts_Arr[4];

#  define Rte_TypeDef_KaTRSC_kph_DiffGainBrkPts_Arr
typedef real32_T KaTRSC_kph_DiffGainBrkPts_Arr[4];

#  define Rte_TypeDef_KaTRSC_kph_InputRateLimBrkPts_Arr
typedef real32_T KaTRSC_kph_InputRateLimBrkPts_Arr[4];

#  define Rte_TypeDef_KaTRSC_kph_IntegratorExtSatBrkPts_Arr
typedef real32_T KaTRSC_kph_IntegratorExtSatBrkPts_Arr[4];

#  define Rte_TypeDef_KaTRSC_kph_IntegratorGainBrkPts_Arr
typedef real32_T KaTRSC_kph_IntegratorGainBrkPts_Arr[4];

#  define Rte_TypeDef_KaTRSC_kph_PGainLUTXBrkPts_Arr
typedef real32_T KaTRSC_kph_PGainLUTXBrkPts_Arr[4];

#  define Rte_TypeDef_KeKM_k_UpdateIMU_H_Array
typedef real32_T KeKM_k_UpdateIMU_H_Array[3];

#  define Rte_TypeDef_KeKM_k_UpdateRPM_H_Array
typedef real32_T KeKM_k_UpdateRPM_H_Array[3];

#  define Rte_TypeDef_KeKM_k_UpdateTAD_H_Array
typedef real32_T KeKM_k_UpdateTAD_H_Array[3];

#  define Rte_TypeDef_KeTRA_deg_TrailerBeamLenYBrkPts_Array
typedef real32_T KeTRA_deg_TrailerBeamLenYBrkPts_Array[3];

#  define Rte_TypeDef_KeTRA_m_TrailerBeamLenXBrkPts_Array
typedef real32_T KeTRA_m_TrailerBeamLenXBrkPts_Array[3];

#  define Rte_TypeDef_Padding1_0A_arr
typedef ErrorMgr_ErrorField Padding1_0A_arr[3];

#  define Rte_TypeDef_Padding1_0B_arr
typedef ErrorMgr_ErrorField Padding1_0B_arr[3];

#  define Rte_TypeDef_Padding1_0QM_arr
typedef ErrorMgr_ErrorField Padding1_0QM_arr[3];

#  define Rte_TypeDef_Padding2_0A_arr
typedef ErrorMgr_ErrorField Padding2_0A_arr[3];

#  define Rte_TypeDef_Padding2_0B_arr
typedef ErrorMgr_ErrorField Padding2_0B_arr[1];

#  define Rte_TypeDef_Padding2_1A_arr
typedef ErrorMgr_ErrorField Padding2_1A_arr[3];

#  define Rte_TypeDef_Padding2_1B_arr
typedef ErrorMgr_ErrorField Padding2_1B_arr[1];

#  define Rte_TypeDef_PaddingQNXA_arr
typedef ErrorMgr_ErrorField PaddingQNXA_arr[3];

#  define Rte_TypeDef_PaddingQNXB_arr
typedef ErrorMgr_ErrorField PaddingQNXB_arr[3];

#  define Rte_TypeDef_StayActiveSource_FD01_BCM
typedef Rte_DT_StayActiveSource_FD01_BCM_0 StayActiveSource_FD01_BCM[8];

#  define Rte_TypeDef_StayActiveSource_FD01_SGW
typedef Rte_DT_StayActiveSource_FD01_SGW_0 StayActiveSource_FD01_SGW[8];

#  define Rte_TypeDef_StayActiveSource_FD02_BCM
typedef Rte_DT_StayActiveSource_FD02_BCM_0 StayActiveSource_FD02_BCM[8];

#  define Rte_TypeDef_StayActiveSource_FD02_BSM2
typedef Rte_DT_StayActiveSource_FD02_BSM2_0 StayActiveSource_FD02_BSM2[8];

#  define Rte_TypeDef_StayActiveSource_FD02_EPS
typedef Rte_DT_StayActiveSource_FD02_EPS_0 StayActiveSource_FD02_EPS[8];

#  define Rte_TypeDef_StayActiveSource_FD02_ORC
typedef Rte_DT_StayActiveSource_FD02_ORC_0 StayActiveSource_FD02_ORC[8];

#  define Rte_TypeDef_StayActiveSource_FD02_SGW
typedef Rte_DT_StayActiveSource_FD02_SGW_0 StayActiveSource_FD02_SGW[8];

#  define Rte_TypeDef_StayActiveSource_FD03_BCM
typedef Rte_DT_StayActiveSource_FD03_BCM_0 StayActiveSource_FD03_BCM[8];

#  define Rte_TypeDef_StayActiveSource_FD03_SGW
typedef Rte_DT_StayActiveSource_FD03_SGW_0 StayActiveSource_FD03_SGW[8];

#  define Rte_TypeDef_StayActiveSource_FD04_BCM
typedef Rte_DT_StayActiveSource_FD04_BCM_0 StayActiveSource_FD04_BCM[8];

#  define Rte_TypeDef_StayActiveSource_FD08_SGW
typedef Rte_DT_StayActiveSource_FD08_SGW_0 StayActiveSource_FD08_SGW[8];

#  define Rte_TypeDef_StayActiveSource_FD11_SGW
typedef Rte_DT_StayActiveSource_FD11_SGW_0 StayActiveSource_FD11_SGW[8];

#  define Rte_TypeDef_UssCom_E_BumperState_Array
typedef UssCom_E_BumperState_t UssCom_E_BumperState_Array[4];

#  define Rte_TypeDef_UssCom_S_ObjectDetOutputBuff_Array
typedef UssCom_S_ObjectDetOutputBuff_t UssCom_S_ObjectDetOutputBuff_Array[48];

#  define Rte_TypeDef_UssCom_S_TestDataMux_Array
typedef UssCom_S_TestDataMux_t UssCom_S_TestDataMux_Array[12];

#  define Rte_TypeDef_THADet_Inputs_from_CalData_t
typedef struct
{
  float32 THAVehSpeedThresh_f32;
  float32 DefaultTrailerAngleDeg_f32;
  float32 CouplerConfThresh_f32;
  float32 CouplerToHitchThresh_f32;
  float32 TrailerAngleThreshDeg_f32;
  float32 KcfMinPeakValueThresh_f32;
  sint32 DefaultHitchXmm_s32;
  sint32 DefaultHitchYmm_s32;
  sint32 DefaultHitchZmm_s32;
  sint32 DefaultHitchXpix_s32;
  sint32 DefaultHitchYpix_s32;
  sint32 CouplerHeight_s32;
  uint16 ROIWidth_u16;
  uint16 ROIHeight_u16;
  uint8 UtilizeTrailerTracker_b;
  uint8 IsCouplerToHitchThreshInPix_b;
  uint8 EnableKFSmooth_b;
  uint8 EnableODONNXCrop_b;
  uint32 DefaultBallDiameter_u32;
  uint32 Dummy2_b;
  uint32 Dummy3_b;
  Dummy4_b_Array Dummy4_b;
} THADet_Inputs_from_CalData_t;

#  define Rte_TypeDef_TRSC_Tunable_Param_t
typedef struct
{
  trailerBeamLengthRange_mm_Array trailerBeamLengthRange_mm;
  hitchYOffset_Array hitchYOffset;
  defaultHitchPoint_Array defaultHitchPoint;
  float32 rearBumper2hitch_mm;
  sint32 pointY;
  float32 threshold;
  float32 assumedInitialAngle;
  float32 angleTolerance_deg;
  uint32 hitchXPos;
  float32 topViewPixelInfo;
  float32 weightFactor;
  uint32 outputFilterSize;
  float32 TrackingLostThreshold;
  float32 angleToReachBeforeRecalibrating;
  float32 angleTolerance;
  float32 maxAngleOffset;
  sint32 trailerID;
  sint32 showCalibrationAngles;
  uint32 rateOfAngleChangeBufSize;
  float32 length_mm;
  float32 width_mm;
  float32 frontOverhang_mm;
  float32 rearOverhang_mm;
  float32 wheelBase_mm;
  float32 WhlAngCFWt;
  float32 WhlAngCFBias;
  uint8 kinematicsEnabled;
  uint8 simulateTimeStamp;
  uint8 vehicleWheelAngleClockwise;
  uint8 enabledTrailerPresenceDetection;
  uint8 enabledTrailerRecognition;
  uint8 enabledCollisionAngleSetction;
  uint8 enabledTrailerAngleCalibration;
  uint8 enabledHitchDetection;
  uint8 hitchMaskEnabled;
  uint8 PreprocessingEnabled;
  uint8 enabledTurnAround;
  uint8 stopMatchingWhenVehicleStopped;
  uint8 TrackingLost;
  uint8 DynamicWindowSize;
  uint8 AngleFilerEnable;
  uint8 enableContinuousCalibration;
  uint8 onlyCalibrateWhenAngleIsOff;
  uint8 allowQuickCalibration;
  uint8 calibrateNewTrailer;
  uint8 calibrateHitchPoint;
  uint8 showSecondAngle;
  uint8 dummy1;
  uint8 dummy2;
  uint8 dummy3;
} TRSC_Tunable_Param_t;

#  define Rte_TypeDef_TbAPNFCD_VrntTunParam_t
typedef struct
{
  float32 Variant_WhlAngCFWt;
  float32 Variant_WhlAngCFBias;
  uint16 VEHICLE_LENGTH;
  uint16 VEHICLE_WIDTH;
  uint16 FRONT_OVERHANG;
  uint16 REAR_OVERHANG;
  uint16 WHEEL_BASE;
  uint8 dummy1;
  dummy2_Array dummy2;
} TbAPNFCD_VrntTunParam_t;

#  define Rte_TypeDef_TbAPUSSOM_AlgoTunParam_t
typedef struct
{
  USS_Bumper_Layout_Array USS_Bumper_Layout;
  float32 AngPar_1_2;
  float32 AngPar_2_3;
  float32 AngPar_2_4;
  float32 AngPar_2_5;
  float32 AngPar_3_4;
  float32 AngPar_3_5;
  float32 AngPar_4_5;
  float32 AngPar_5_6;
  float32 AngPar_7_8;
  float32 AngPar_7_9;
  float32 AngPar_7_10;
  float32 AngPar_8_9;
  float32 AngPar_8_10;
  float32 AngPar_8_11;
  float32 AngPar_9_10;
  float32 AngPar_9_11;
  float32 AngPar_9_12;
  float32 AngPar_10_11;
  float32 AngPar_10_12;
  float32 AngPar_11_12;
  sint32 VehicleType;
  uint8 BeforeVehicleSlotDetection;
  uint8 AfterVehicleSlotDetection;
  uint8 Tail_Point_Adjustment;
  uint8 Head_Point_Adjustment;
  uint8 MABxEgoMotion;
  uint8 SlotWidth;
  uint8 SlotDepth;
  uint8 Distance_from_car;
  uint8 USSCalPoints;
  uint8 USSslotOffset;
  uint8 dummy1;
  uint8 dummy2;
} TbAPUSSOM_AlgoTunParam_t;

#  define Rte_TypeDef_TbTHASmVc_VrntTunParam_t
typedef struct
{
  KsTHA_deg_StrToRdWhlAngTD_Array KsTHA_deg_StrToRdWhlAngTD;
  KsTHA_mps_DistSpdTD_Array KsTHA_mps_DistSpdTD;
  KsTHA_k_ErrxPropGainTD_Array KsTHA_k_ErrxPropGainTD;
  KsTHA_k_ErrxHeadingErrTD_Array KsTHA_k_ErrxHeadingErrTD;
  float32 KeTHA_M_SteerTweakTrq;
  float32 KeTHA_s_SteerTweakTime;
  float32 KeTHA_k_SteerTrqCtrlKp;
  float32 KeTHA_k_SteerTrqCtrlKi;
  float32 KeTHA_k_SteerTrqCtrlKd;
  float32 KeTHA_k_SteerTrqCtrlFiltCoef;
  float32 KeTHA_k_TrqCtrlKp;
  float32 KeTHA_k_TrqCtrlKi;
  float32 KeTHA_k_TrqCtrlKd;
  float32 KeTHA_k_TrqCtrlFiltCoef;
  float32 KeTHA_k_HeadingErrGain;
  float32 KeTHA_m_WhlCircumference;
  uint16 KeTHA_px_HitchCplrDeltaThd1;
  uint16 KeTHA_px_HitchCplrDeltaThd2;
  uint16 KeTHA_px_RearBrkSuppDist;
  uint16 KeTHA_ddeg_StrRateLimFinal;
  uint16 KeTHA_ddeg_StrRateLimInit;
  uint8 KeTHA_b_Dummy1;
  uint8 KeTHA_b_Dummy2;
} TbTHASmVc_VrntTunParam_t;

#  define Rte_TypeDef_TbTRSCSmVc_TunParam_t
typedef struct
{
  real32_T KeKM_k_GyroYawCov;
  real32_T KeKM_k_NumWheelPulses;
  real32_T KeKM_k_TADCov;
  KeKM_k_UpdateIMU_H_Array KeKM_k_UpdateIMU_H;
  KeKM_k_UpdateRPM_H_Array KeKM_k_UpdateRPM_H;
  KeKM_k_UpdateTAD_H_Array KeKM_k_UpdateTAD_H;
  real32_T KeKM_k_WhlPlsCnt_high_lim;
  real32_T KeKM_k_WhlPlsCnt_low_lim;
  real32_T KeKM_k_WhlRPMYawCov;
  real32_T KeKM_m_TrackWidth;
  real32_T KeKM_m_WheelCircumference;
  real32_T KeKM_s_SampleTime;
  real32_T KeKM_k_KM_YawRateGyroBiasInit;
  real32_T KeKM_k_KM_SF_RelAngCov;
  real32_T KeKM_k_KM_SF_RelAngRateCov;
  real32_T KeKM_k_KM_SF_YawRateCov;
  real32_T KeTRA_m_K_beta;
  real32_T KeKM_deg_AngTh;
  KaTRA_k_PGainLUTTblData_Array KaTRA_k_PGainLUTTblData;
  KaTRA_k_VehSpd_IGainLUTTblData_Array KaTRA_k_VehSpd_IGainLUTTblData;
  KaTRA_k_VehSpd_HdgDeviatLUTTblData_Array KaTRA_k_VehSpd_HdgDeviatLUTTblData;
  KaTRA_k_TADLUTTblData_Array KaTRA_k_TADLUTTblData;
  KaTRA_k_TravDistLUTTblData_Array KaTRA_k_TravDistLUTTblData;
  KaTRA_k_VehSpdLUTTblData_Array KaTRA_k_VehSpdLUTTblData;
  real32_T KeTRA_k_Kp;
  KaTRA_k_TAD_IGainLUTTblData_Array KaTRA_k_TAD_IGainLUTTblData;
  KeTRA_deg_TrailerBeamLenYBrkPts_Array KeTRA_deg_TrailerBeamLenYBrkPts;
  KeTRA_m_TrailerBeamLenXBrkPts_Array KeTRA_m_TrailerBeamLenXBrkPts;
  real32_T KeKM_k_SWA_Res;
  KaTRA_deg_TADLUTBrkPts_Array KaTRA_deg_TADLUTBrkPts;
  KaTRA_deg_TAD_IGainLUTBrkPts_Array KaTRA_deg_TAD_IGainLUTBrkPts;
  KaTRA_m_PGainLUTYBrkPts_Array KaTRA_m_PGainLUTYBrkPts;
  KaTRA_m_TravDistLUTBrkPts_Array KaTRA_m_TravDistLUTBrkPts;
  KaTRA_v_PGainLUTXBrkPts_Array KaTRA_v_PGainLUTXBrkPts;
  KaTRA_v_VehSpdLUTBrkPts_Array KaTRA_v_VehSpdLUTBrkPts;
  KaTRA_v_VehSpd_HdgDeviatLUTBrkPts_Array KaTRA_v_VehSpd_HdgDeviatLUTBrkPts;
  KaTRA_v_VehSpd_IGainLUTBrkPts_Array KaTRA_v_VehSpd_IGainLUTBrkPts;
  KaTRSC_deg_FtWhlAngPts_Array KaTRSC_deg_FtWhlAngPts;
  KaTRSC_deg_StwAngPts_Array KaTRSC_deg_StwAngPts;
  real32_T KeTRA_k_SteerAngRateLmt;
  KaTRA_rate_RateGuardXdat_Array KaTRA_rate_RateGuardXdat;
  KaTRA_rate_RateGuardYdat_Array KaTRA_rate_RateGuardYdat;
  real32_T KeTRSC_m_WheelBase;
  real32_T KeTRSC_deg_MaxStrAngle;
  real32_T KeTRSC_deg_MaxStrAngle_Up_Limit;
  real32_T KeTRSC_deg_MaxStrAngle_Low_Limit;
  real32_T KeTRSC_m_WheelBase_Up_Limit;
  real32_T KeTRSC_m_WheelBase_Low_Limit;
  real32_T KeTRSC_deg_KnobHys;
  real32_T KeTRSC_pct_JackKnifePerc;
  real32_T KeTRSC_deg_MaxKnobAngle;
  real32_T KeTRSC_deg_MaxTrlrAngl;
  real32_T KeTRSC_TADdes_k_PIDKd;
  real32_T KeTRSC_TADep_k_PIDKp;
  KaTRA_deg_TADLUTTblData_Array KaTRA_deg_TADLUTTblData;
  real32_T KeTRSC_deg_TGTADdesRateChange;
  real32_T KeTRSC_deg_TAD_DesRateUpLim;
  real32_T KeTRSC_deg_TrqCnt_UpLimit;
  real32_T KeTRSC_deg_TrqCnt_LowLimit;
  real32_T KeTRSC_k_JKAngle_UpLimit;
  real32_T KeTRSC_k_JKAngle_LowLimit;
  real32_T KeTRSC_k_LogVecLength;
  real32_T KeKM_m_BeamLength;
  real32_T KeTRSC_m_TBL_UpLimit;
  real32_T KeTRSC_m_TBL_LowLimit;
  real32_T KeTRSC_kph_DeactivationSpd;
  real32_T KeTRSC_pct_TrlrJackKnifePerc;
  real32_T KeTRSC_s_ActTransRevDbnc2;
  real32_T KeTRSC_s_CalibDlyTh;
  real32_T KeTRSC_s_EpsRespTmOut;
  real32_T KeTRSC_s_GearDbncTh;
  real32_T KeTRSC_s_LEDTmrTh;
  real32_T KeTRSC_s_RespNotRcvdTmOut;
  real32_T KeTRSC_s_TrlrUnkwnSet;
  real32_T KeTRSC_k_WhlAngCFWt;
  real32_T KeTRSC_k_WhlAngCFBias;
  KaTRSC_kph_InputRateLimBrkPts_Arr KaTRSC_kph_InputRateLimBrkPts;
  KaTRSC_k_InputRateLimTblData_Arr KaTRSC_k_InputRateLimTblData;
  KaTRSC_kph_IntegratorGainBrkPts_Arr KaTRSC_kph_IntegratorGainBrkPts;
  KaTRSC_k_IntegratorGainTblData_Arr KaTRSC_k_IntegratorGainTblData;
  KaTRSC_kph_IntegratorExtSatBrkPts_Arr KaTRSC_kph_IntegratorExtSatBrkPts;
  KaTRSC_k_IntegratorExtSatTblData_Arr KaTRSC_k_IntegratorExtSatTblData;
  KaTRSC_kph_PGainLUTXBrkPts_Arr KaTRSC_kph_PGainLUTXBrkPts;
  KaTRSC_deg_PGainLUTYBrkPts_Arr KaTRSC_deg_PGainLUTYBrkPts;
  KaTRSC_k_PGainLUTTblData_Arr KaTRSC_k_PGainLUTTblData;
  KaTRSC_kph_DiffGainBrkPts_Arr KaTRSC_kph_DiffGainBrkPts;
  KaTRSC_k_DiffGainTblData_Arr KaTRSC_k_DiffGainTblData;
  KaTRSC_kph_DampingGainBrkPts_Arr KaTRSC_kph_DampingGainBrkPts;
  KaTRSC_k_DampingGainTblData_Arr KaTRSC_k_DampingGainTblData;
  real32_T KeTRSC_k_TrqConstRateLim;
  real32_T KeTRSC_k_TrqConstSatLim;
  uint8 KeTRSC_k_VariantID;
  uint8 KeTRSC_Cnt_FailedCnt;
  uint8 KeTRSC_e_CamBlockAcceptLvl;
  uint8 KeTRSC_b_bValidFlag;
} TbTRSCSmVc_TunParam_t;

#  define Rte_TypeDef_USSSectorData
typedef struct
{
  FrontZones_Array FrontZones;
  RearZones_Array RearZones;
} USSSectorData;

#  define Rte_TypeDef_USSSectorDistances
typedef struct
{
  FrontDistances_Array FrontDistances;
  RearDistances_Array RearDistances;
} USSSectorDistances;

#  define Rte_TypeDef_UssCom_S_ObjectMapOutputBuff_t
typedef struct
{
  uint32 timestamp;
  UssCom_S_ObjectDetOutputBuff_Array objects;
} UssCom_S_ObjectMapOutputBuff_t;

#  define Rte_TypeDef_UssCom_S_SensorSenstivityOutputBuff_t
typedef struct
{
  sensor_sensitivity_Array sensor_sensitivity;
} UssCom_S_SensorSenstivityOutputBuff_t;

#  define Rte_TypeDef_UssCom_S_SystemStatusOutputBuff_t
typedef struct
{
  uint32 timestamp;
  UssCom_E_BumperState_Array bumperStatus;
  UssCom_E_SystemState_t systemStatus;
  uint16 systemMode;
} UssCom_S_SystemStatusOutputBuff_t;

#  define Rte_TypeDef_UssCom_S_TestDataCluster_t
typedef struct
{
  FrontDir_Echo1_Array FrontDir_Echo1;
  RearDir_Echo1_Array RearDir_Echo1;
  FrontDir_Echo2_Array FrontDir_Echo2;
  RearDir_Echo2_Array RearDir_Echo2;
  FirstEchoIdxF_Array FirstEchoIdxF;
  FirstEchoIdxR_Array FirstEchoIdxR;
  FrontInDir_Array FrontInDir;
  RearInDir_Array RearInDir;
  UssCom_S_TestDataMux_Array sDataMux;
  UssCom_S_SnsDataDirectEco_t US_S_SnsDataDirectEco;
} UssCom_S_TestDataCluster_t;

#  define Rte_TypeDef_adas_feature_T_leGVP_t
typedef struct
{
  uint32 ADAS_Feature_GVP_start;
  float32 ADAS_Feature_T_IeGVP_kg_VhclGrossWt;
  float32 ADAS_Feature_T_IeGVP_m_BpillarX;
  float32 ADAS_Feature_T_IeGVP_m_FrntBmprLongPos;
  float32 ADAS_Feature_T_IeGVP_m_CamMainDistToLtWhl;
  float32 ADAS_Feature_T_IeGVP_m_CamMainDistToRtWhl;
  float32 ADAS_Feature_T_IeGVP_m_BpillarY;
  float32 ADAS_Feature_T_IeGVP_m_FrntTireLatPosVehCr;
  float32 ADAS_Feature_T_IeGVP_m_FrntTireLongPosVehCr;
  float32 ADAS_Feature_T_IeGVP_m_CamLongPosVehCrd;
  float32 ADAS_Feature_T_IeGVP_m_CarLen;
  float32 ADAS_Feature_T_IeGVP_m_CarWidthWithMirr;
  float32 ADAS_Feature_T_IeGVP_m_DistBtwnAxles;
  float32 ADAS_Feature_T_IeGVP_m_TireDynamicRideCRollRad;
  float32 ADAS_Feature_T_IeGVP_m_TireStaticRad;
  float32 ADAS_Feature_T_IeGVP_m_CGDistFrntAxl;
  float32 ADAS_Feature_T_IeGVP_m_CGDistRearAxl;
  float32 ADAS_Feature_T_IeGVP_radpa_UndrStrGradAWD;
  float32 ADAS_Feature_T_IeGVP_radpa_UndrStrGradFWD;
  adas_feature_StrngRatio_t ADAS_Feature_T_IaGVP_deg_StrngRatio_X;
  adas_feature_StrngRatio_t ADAS_Feature_T_IaGVP_k_StrngRatio_Y;
  float32 ADAS_Feature_T_IeGVP_Npdeg_FrntCrnrngStffnss;
  float32 ADAS_Feature_T_IeGVP_Npdeg_RearCrnrngStffnss;
  float32 ADAS_Feature_T_IeGVP_cnt_WhlPulsePerRev;
  float32 ADAS_Feature_T_IeGVP_m_CamHeiPosVehCrd;
  float32 ADAS_Feature_T_IeGVP_m_CamLatPosVehCrd;
  float32 ADAS_Feature_T_IeGVP_m_CamLongMinViewDist;
  adas_feature_RSVD ADAS_Feature_RSVD;
  uint32 ADAS_Feature_GVP_end;
} adas_feature_T_leGVP_t;

#  define Rte_TypeDef_Csm_VerifyResultPtr
typedef Csm_VerifyResultType * Csm_VerifyResultPtr;

#  define Rte_TypeDef_Data1_0A_arr
typedef ErrorMgr_stAddData Data1_0A_arr[1];

#  define Rte_TypeDef_Data2_0A_arr
typedef ErrorMgr_stAddData Data2_0A_arr[1];

#  define Rte_TypeDef_Data2_1A_arr
typedef ErrorMgr_stAddData Data2_1A_arr[1];

#  define Rte_TypeDef_DataQNXA_arr
typedef ErrorMgr_stAddData DataQNXA_arr[1];

#  define Rte_TypeDef_USSData_Output
typedef struct
{
  ParkingMode m_SetUSSParkingMode;
  USSSectorData m_sectorZoneData;
  USSSectorDistances m_sectorZoneDist;
} USSData_Output;

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Array_15Bytes, RTE_CONST) Rte_C_Array_15Bytes_0;

extern CONST(ErrorListArr_B, RTE_CONST) Rte_init_Errors_B;

extern CONST(ErrorListArr_QM, RTE_CONST) Rte_init_Errors_QM;

extern CONST(FD14_Log_SnrMeasData_1, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_1_0;

extern CONST(FD14_Log_SnrMeasData_2, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_2_0;

extern CONST(FD14_Log_SnrMeasData_3, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_3_0;

extern CONST(FD14_Log_SnrMeasData_4, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_4_0;

extern CONST(FD14_Log_SnrMeasData_5, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_5_0;

extern CONST(FD14_Log_SnrMeasData_6, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_6_0;

extern CONST(FD14_Log_SnrMeasData_7, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_7_0;

extern CONST(FD14_MAC_ADAS_FD_LANES_1, RTE_CONST) Rte_C_FD14_MAC_ADAS_FD_LANES_1_0;

extern CONST(FD14_MAC_ADAS_FD_LANES_2, RTE_CONST) Rte_C_FD14_MAC_ADAS_FD_LANES_2_0;

extern CONST(FIDOutputArr_QM, RTE_CONST) Rte_C_FIDOutputArr_QM_0;

extern CONST(MAC_ADAS_FD_LANES_1, RTE_CONST) Rte_C_MAC_ADAS_FD_LANES_1_0;

extern CONST(MAC_ADAS_FD_LANES_2, RTE_CONST) Rte_C_MAC_ADAS_FD_LANES_2_0;

extern CONST(MpuFltSts, RTE_CONST) Rte_C_MpuFltSts_0;

extern CONST(N_PDU, RTE_CONST) Rte_C_N_PDU_0;

extern CONST(PmicStatus, RTE_CONST) Rte_C_PmicStatus_0;

extern CONST(Status, RTE_CONST) Rte_C_Status_0;

extern CONST(StayActiveSource_FD02_PAM, RTE_CONST) Rte_C_StayActiveSource_FD02_PAM_0;

extern CONST(VIN_DATA, RTE_CONST) Rte_C_VIN_DATA_0;

extern CONST(VINlData_Arr, RTE_CONST) Rte_init_VINCurrentData;

extern CONST(VINlData_Arr, RTE_CONST) Rte_init_VINOriginalData;

extern CONST(WdgFltSts, RTE_CONST) Rte_C_WdgFltSts_0;

extern CONST(vRoE_MessageType, RTE_CONST) Rte_C_vRoE_MessageType_0;

extern CONST(CAM_CS_Curr_Monitor_t, RTE_CONST) Rte_C_CAM_CS_Curr_Monitor_t_0;

extern CONST(CAM_select_info_t, RTE_CONST) Rte_C_CAM_select_info_t_0;

extern CONST(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_CONST) Rte_C_CDP_TbSVS_S_SVSCamCurrentCalibData_t_0;

extern CONST(CalDataProvider_MCU_1_0_Def, RTE_CONST) Rte_C_CalDataProvider_MCU_1_0_Def_0;

extern CONST(Cam_and_Ser_EN_Status_t, RTE_CONST) Rte_C_Cam_and_Ser_EN_Status_t_0;

extern CONST(CpuLoadMcu2_0_t, RTE_CONST) Rte_C_CpuLoadMcu2_0_t_0;

extern CONST(CpuLoadMcu2_1_t, RTE_CONST) Rte_C_CpuLoadMcu2_1_t_0;

extern CONST(Debug_HMI_Curr_Displayed_Overlays, RTE_CONST) Rte_C_Debug_HMI_Curr_Displayed_Overlays_0;

extern CONST(Debug_HMI_Curr_Displayed_ProxiConfig, RTE_CONST) Rte_C_Debug_HMI_Curr_Displayed_ProxiConfig_0;

extern CONST(Debug_HMI_Curr_Requested_Overlays, RTE_CONST) Rte_C_Debug_HMI_Curr_Requested_Overlays_0;

extern CONST(Debug_HMI_Curr_Requested_ProxiConfig, RTE_CONST) Rte_C_Debug_HMI_Curr_Requested_ProxiConfig_0;

extern CONST(Debug_HMI_Input_Data_t, RTE_CONST) Rte_C_Debug_HMI_Input_Data_t_0;

extern CONST(Debug_HMI_Internal_Data_t, RTE_CONST) Rte_C_Debug_HMI_Internal_Data_t_0;

extern CONST(Debug_HMI_Trailer_Views_Data_t, RTE_CONST) Rte_C_Debug_HMI_Trailer_Views_Data_t_0;

extern CONST(Detection_Inputs_from_TRSC_t, RTE_CONST) Rte_C_Detection_Inputs_from_TRSC_t_0;

extern CONST(DtcAddData_B, RTE_CONST) Rte_init_Data_DtcAddData_B;

extern CONST(DtcAddData_QM, RTE_CONST) Rte_init_Data_DtcAddData_QM;

extern CONST(DtcStatus_B, RTE_CONST) Rte_init_Data_DtcStatus_B;

extern CONST(DtcStatus_QM, RTE_CONST) Rte_init_Data_DtcStatus_QM;

extern CONST(ErrorMgr_ErrorCommPack_1_0_B, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_1_0_B_0;

extern CONST(ErrorMgr_ErrorCommPack_1_0_B, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_1_0_B;

extern CONST(ErrorMgr_ErrorCommPack_1_0_QM, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_1_0_QM_0;

extern CONST(ErrorMgr_ErrorCommPack_1_0_QM, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_1_0_QM;

extern CONST(ErrorMgr_ErrorCommPack_2_0_B, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_2_0_B_0;

extern CONST(ErrorMgr_ErrorCommPack_2_0_B, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_2_0_B;

extern CONST(ErrorMgr_ErrorCommPack_2_0_QM, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_2_0_QM_0;

extern CONST(ErrorMgr_ErrorCommPack_2_0_QM, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_2_0_QM;

extern CONST(ErrorMgr_ErrorCommPack_2_1_B, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_2_1_B_0;

extern CONST(ErrorMgr_ErrorCommPack_2_1_B, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_2_1_B;

extern CONST(ErrorMgr_ErrorCommPack_2_1_QM, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_2_1_QM_0;

extern CONST(ErrorMgr_ErrorCommPack_2_1_QM, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_2_1_QM;

extern CONST(ErrorMgr_ErrorCommPack_QNX_B, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_QNX_B_0;

extern CONST(ErrorMgr_ErrorCommPack_QNX_B, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_QNX_B;

extern CONST(ErrorMgr_ErrorCommPack_QNX_QM, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_QNX_QM_0;

extern CONST(ErrorMgr_ErrorCommPack_QNX_QM, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_QNX_QM;

extern CONST(Error_Fault_MCU2_0_t, RTE_CONST) Rte_C_Error_Fault_MCU2_0_t_0;

extern CONST(Error_Fault_MCU2_1_t, RTE_CONST) Rte_C_Error_Fault_MCU2_1_t_0;

extern CONST(Error_Fault_MPU1_0_t, RTE_CONST) Rte_C_Error_Fault_MPU1_0_t_0;

extern CONST(IDebug_FODObject_t, RTE_CONST) Rte_C_IDebug_FODObject_t_0;

extern CONST(IFOD_Outputs_Arbitration_t, RTE_CONST) Rte_C_IFOD_Outputs_Arbitration_t_0;

extern CONST(IFOD_Outputs_CVPAMFDData_t, RTE_CONST) Rte_C_IFOD_Outputs_CVPAMFDData_t_0;

extern CONST(IJobFPAOutput_t, RTE_CONST) Rte_C_IJobFPAOutput_t_0;

extern CONST(IJobPLDOutput_t, RTE_CONST) Rte_C_IJobPLDOutput_t_0;

extern CONST(IJobUSSObjectMapOutput_t, RTE_CONST) Rte_C_IJobUSSObjectMapOutput_t_0;

extern CONST(JobDLDOutput_t, RTE_CONST) Rte_C_JobDLDOutput_t_0;

extern CONST(JobTHADetOutput_t, RTE_CONST) Rte_C_JobTHADetOutput_t_0;

extern CONST(KeepAliveResponse_t, RTE_CONST) Rte_C_KeepAliveResponse_t_0;

extern CONST(LMD_Lane_Outputs_s, RTE_CONST) Rte_C_LMD_Lane_Outputs_s_0;

extern CONST(LMD_Outputs_CVPAMFDData2_t, RTE_CONST) Rte_C_LMD_Outputs_CVPAMFDData2_t_0;

extern CONST(ME_Hydra2defs_S_CodingTableExt_t, RTE_CONST) Rte_C_ME_Hydra2defs_S_CodingTableExt_t_1;

extern CONST(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_CONST) Rte_C_ME_Hydra2defs_S_PROXI_error_Data_t_0;

extern CONST(ME_Proxi_MPU1_0_to_MCU1_0_t, RTE_CONST) Rte_C_ME_Proxi_MPU1_0_to_MCU1_0_t_0;

extern CONST(ME_VehInp_to_IpcSignals_QM_t, RTE_CONST) Rte_C_ME_VehInp_to_IpcSignals_QM_t_0;

extern CONST(ME_VehOut_TRSC_t, RTE_CONST) Rte_C_ME_VehOut_TRSC_t_0;

extern CONST(NFCD_Output, RTE_CONST) Rte_C_NFCD_Output_0;

extern CONST(NVMSignalManager_t, RTE_CONST) Rte_C_NVMSignalManager_t_0;

extern CONST(RunTimeStats_MCU2_0_t, RTE_CONST) Rte_C_RunTimeStats_MCU2_0_t_0;

extern CONST(RunTimeStats_MCU2_1_t, RTE_CONST) Rte_C_RunTimeStats_MCU2_1_t_0;

extern CONST(RunTimeStats_MPU1_0_t, RTE_CONST) Rte_C_RunTimeStats_MPU1_0_t_0;

extern CONST(SSM_1_0_CoreStatus, RTE_CONST) Rte_C_SSM_1_0_CoreStatus_0;

extern CONST(SSM_2_0_CoreStatus, RTE_CONST) Rte_C_SSM_2_0_CoreStatus_0;

extern CONST(SSM_2_1_CoreStatus, RTE_CONST) Rte_C_SSM_2_1_CoreStatus_0;

extern CONST(SSM_QNX_CoreStatus, RTE_CONST) Rte_C_SSM_QNX_CoreStatus_0;

extern CONST(SSM_SystemState, RTE_CONST) Rte_C_SSM_SystemState_0;

extern CONST(SVSToDiag_t, RTE_CONST) Rte_C_SVSToDiag_t_0;

extern CONST(SVS_NVMData_t, RTE_CONST) Rte_C_SVS_NVMData_t_0;

extern CONST(SVStoTRSC_t, RTE_CONST) Rte_C_SVStoTRSC_t_0;

extern CONST(SafeStateOpDef, RTE_CONST) Rte_Pkg_ErrorMgrAgg_1_0_B_Constant_init_SafeStateOp;

extern CONST(SafeStateOpDef, RTE_CONST) Rte_Pkg_ErrorMgrAgg_1_0_QM_Constant_init_SafeStateOp;

extern CONST(ScreenRequest_t, RTE_CONST) Rte_C_ScreenRequest_t_0;

extern CONST(ScreenResponse_t, RTE_CONST) Rte_C_ScreenResponse_t_0;

extern CONST(StackUsage_MCU2_0_t, RTE_CONST) Rte_C_StackUsage_MCU2_0_t_0;

extern CONST(StackUsage_MCU2_1_t, RTE_CONST) Rte_C_StackUsage_MCU2_1_t_0;

extern CONST(SvsToTHA_t, RTE_CONST) Rte_C_SvsToTHA_t_0;

extern CONST(SvsToVCAN_t, RTE_CONST) Rte_C_SvsToVCAN_t_0;

extern CONST(Svs_CamEepromDataArray_t, RTE_CONST) Rte_C_Svs_CamEepromDataArray_t_0;

extern CONST(TRSCSMVCtoDebugCAN_t, RTE_CONST) Rte_C_TRSCSMVCtoDebugCAN_t_0;

extern CONST(TRSCSMVCtoSVS_t, RTE_CONST) Rte_C_TRSCSMVCtoSVS_t_0;

extern CONST(TRSC_Inputs_from_TrailerDetection_t, RTE_CONST) Rte_C_TRSC_Inputs_from_TrailerDetection_t_0;

extern CONST(TRSCtoDiagMgr_t, RTE_CONST) Rte_C_TRSCtoDiagMgr_t_0;

extern CONST(TbAP_APSMPAOut_t, RTE_CONST) Rte_C_TbAP_APSMPAOut_t_0;

extern CONST(TbAP_DebugOut, RTE_CONST) Rte_C_TbAP_DebugOut_0;

extern CONST(TbAP_DriveAssistStatOut_t, RTE_CONST) Rte_C_TbAP_DriveAssistStatOut_t_0;

extern CONST(TbAP_FPAWarnOut_t, RTE_CONST) Rte_C_TbAP_FPAWarnOut_t_0;

extern CONST(TbAP_PAStateOut_t, RTE_CONST) Rte_C_TbAP_PAStateOut_t_0;

extern CONST(TbAP_RPAWarnOut_t, RTE_CONST) Rte_C_TbAP_RPAWarnOut_t_0;

extern CONST(TbAP_SMDAInternalOut_t, RTE_CONST) Rte_C_TbAP_SMDAInternalOut_t_0;

extern CONST(TbAP_SMPAInternalOut_t, RTE_CONST) Rte_C_TbAP_SMPAInternalOut_t_0;

extern CONST(TbAP_VCActuatorOut_t, RTE_CONST) Rte_C_TbAP_VCActuatorOut_t_0;

extern CONST(TbAP_VCStateOut_t, RTE_CONST) Rte_C_TbAP_VCStateOut_t_0;

extern CONST(TbAP_VrntTunParam_t, RTE_CONST) Rte_C_TbAP_VrntTunParam_t_0;

extern CONST(TbFA_ArbiterOutput_t, RTE_CONST) Rte_C_TbFA_ArbiterOutput_t_0;

extern CONST(TbFA_ResetKM_t, RTE_CONST) Rte_C_TbFA_ResetKM_t_0;

extern CONST(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, RTE_CONST) Rte_C_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_0;

extern CONST(TbSVS_S_SVSCamEOLCalibDataToNVM_t, RTE_CONST) Rte_C_TbSVS_S_SVSCamEOLCalibDataToNVM_t_0;

extern CONST(TbSVS_S_SVSCamOCCalibDataToNVM_t, RTE_CONST) Rte_C_TbSVS_S_SVSCamOCCalibDataToNVM_t_0;

extern CONST(TbSVS_S_SVSCamSCCalibDataToNVM_t, RTE_CONST) Rte_C_TbSVS_S_SVSCamSCCalibDataToNVM_t_0;

extern CONST(TbSVS_e_SVSOutputToDiagMgrCamCalib_t, RTE_CONST) Rte_C_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_0;

extern CONST(TbSVS_e_SVSOutputToNVMCamCalibSM_t, RTE_CONST) Rte_C_TbSVS_e_SVSOutputToNVMCamCalibSM_t_0;

extern CONST(TbTHASmVc_DiagMgr_t, RTE_CONST) Rte_C_TbTHASmVc_DiagMgr_t_0;

extern CONST(TbTHASmVc_FeatureOutputs_t, RTE_CONST) Rte_C_TbTHASmVc_FeatureOutputs_t_0;

extern CONST(TrailerDetection_Output_DID_t, RTE_CONST) Rte_C_TrailerDetection_Output_DID_t_0;

extern CONST(US_S_BlockageBit_t, RTE_CONST) Rte_C_US_S_BlockageBit_t_0;

extern CONST(US_S_CsmStateChangeReason_Type, RTE_CONST) Rte_C_US_S_CsmStateChangeReason_Type_0;

extern CONST(US_S_DebugMsg_t, RTE_CONST) Rte_C_US_S_DebugMsg_t_0;

extern CONST(US_S_MarriageSensorIDs_t, RTE_CONST) Rte_C_US_S_MarriageSensorIDs_t_0;

extern CONST(US_S_PointDistOutputBuff_t, RTE_CONST) Rte_C_US_S_PointDistOutputBuff_t_0;

extern CONST(US_S_PointMapGroup_t, RTE_CONST) Rte_C_US_S_PointMapGroup_t_0;

extern CONST(US_S_SnrDirEcho_t, RTE_CONST) Rte_C_US_S_SnrDirEcho_t_0;

extern CONST(US_S_USSConstantData_t, RTE_CONST) Rte_C_US_S_USSConstantData_t_0;

extern CONST(US_S_USSDataCollectionData_t, RTE_CONST) Rte_C_US_S_USSDataCollectionData_t_0;

extern CONST(US_S_USSErrorDiagData_t, RTE_CONST) Rte_C_US_S_USSErrorDiagData_t_0;

extern CONST(US_S_USSPeriodDiagData_t, RTE_CONST) Rte_C_US_S_USSPeriodDiagData_t_0;

extern CONST(US_S_ZoneInfo_t, RTE_CONST) Rte_C_US_S_ZoneInfo_t_0;

extern CONST(UssPowerSense, RTE_CONST) Rte_C_UssPowerSense_0;

extern CONST(UssTunningData_mcu2_1_t, RTE_CONST) Rte_C_UssTunningData_mcu2_1_t_0;

extern CONST(VehInpAdapter_opVehSignals, RTE_CONST) Rte_C_VehInpAdapter_opVehSignals_0;

extern CONST(WdgCheckpointStatus_t, RTE_CONST) Rte_C_WdgCheckpointStatus_t_0;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * IOC Init Constant value definitions
 *********************************************************************************************************************/

# define Rte_IocInitValue_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM Rte_init_Data_ErrorMgr_ErrorCommPack_1_0_QM

# include "Rte_DataHandleType.h"

# ifdef RTE_MICROSAR_PIM_EXPORT


/**********************************************************************************************************************
 * Calibration component and SW-C local calibration parameters
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SecondCounter_DefaultValue;
extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_DefaultValue;
extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_ECU_LifeTime_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2002_OdoFlashing_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200A_IgOnCounter_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD74_BuffMarkCompErr_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Safety_Guard_SafeStat2_ResetReason_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_191D_PowerLatch_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD42_FailsafeAction_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_vRoE_Activation_State_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_Lock_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_OdometerCnt_DefaultValue;
extern CONST(boolean, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_CertificateExpired_DefaultValue;
extern CONST(Array_15Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_DefaultValue;
extern CONST(Arr_2Byte, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_DefaultValue;
extern CONST(Arr_20Byte, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2939_WakeupReason_DefaultValue;
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_DefaultValue;
extern CONST(DID_F110_Pin_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_DefaultValue;
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_DefaultValue;
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_DefaultValue;
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_DefaultValue;
extern CONST(Dcm_Data13ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_DefaultValue;
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_DefaultValue;
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_DefaultValue;
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue;
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue;
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue;
extern CONST(Dcm_Data2ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue;
extern CONST(Dcm_Data4ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_DefaultValue;
extern CONST(VINlData_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_CurrentVal_DefaultValue;
extern CONST(VINlData_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_OriginalVal_DefaultValue;
extern CONST(SecureLogRecord_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_DefaultValue;
extern CONST(SecureLogRecord_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_DefaultValue;
extern CONST(INVMSignalManager_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_IPCHandler_FPA_Slot_Data_DefaultValue;
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_FrontCamSerialNumber_DefaultValue;
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_LeftCamSerialNumber_DefaultValue;
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_RearCamSerialNumber_DefaultValue;
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_RightCamSerialNumber_DefaultValue;
extern CONST(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue;
extern CONST(CDP_TbSVS_S_SVSCamEOLCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue;
extern CONST(CDP_TbSVS_S_SVSCamOCCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue;
extern CONST(CDP_TbSVS_S_SVSCamSCCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue;
extern CONST(TbSVS_S_SVSCamCurrentCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_DefaultValue;
extern CONST(FunctionalSettings_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_DefaultValue;
extern CONST(RearBrkEvent_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_RearBrakeEvent_DefaultValue;
extern CONST(SPMAbrtEvent_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_SPMAbrtEvent_DefaultValue;
extern CONST(US_S_MarriageSensorIDs_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_UssSensorMarrData_DefaultValue;
extern CONST(ME_Hydra2defs_S_CodingTableExt_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_ProxiConfigMgr_ProxiConfigTable_DefaultValue;
extern CONST(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_ProxiConfigMgr_ProxiErrorData_DefaultValue;

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_MirrorBlock;
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_ECU_LifeTime_MirrorBlock;
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_2002_OdoFlashing_MirrorBlock;
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_200A_IgOnCounter_MirrorBlock;
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_MirrorBlock;
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_MirrorBlock;
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_FD74_BuffMarkCompErr_MirrorBlock;
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_191D_PowerLatch_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_vRoE_Activation_State_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_RIDMgr_VIN_Lock_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_RIDMgr_VIN_OdometerCnt_MirrorBlock;
extern VAR(Arr_20Byte, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_2939_WakeupReason_MirrorBlock;
extern VAR(Dcm_Data10ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_MirrorBlock;
extern VAR(DID_F110_Pin_Arr, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_MirrorBlock;
extern VAR(Dcm_Data10ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_MirrorBlock;
extern VAR(Dcm_Data10ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_MirrorBlock;
extern VAR(Dcm_Data11ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_MirrorBlock;
extern VAR(Dcm_Data13ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_MirrorBlock;
extern VAR(Dcm_Data11ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_MirrorBlock;
extern VAR(Dcm_Data11ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_MirrorBlock;
extern VAR(Dcm_Data10ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_MirrorBlock;
extern VAR(Dcm_Data10ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_MirrorBlock;
extern VAR(Dcm_Data11ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_MirrorBlock;
extern VAR(Dcm_Data2ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_MirrorBlock;
extern VAR(Dcm_Data4ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_MirrorBlock;
extern VAR(VINlData_Arr, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_RIDMgr_VIN_CurrentVal_MirrorBlock;
extern VAR(VINlData_Arr, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_RIDMgr_VIN_OriginalVal_MirrorBlock;
extern VAR(SecureLogRecord_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_MirrorBlock;
extern VAR(SecureLogRecord_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_MirrorBlock;
extern VAR(TbSVS_S_SVSCamCurrentCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_MirrorBlock;
extern VAR(FunctionalSettings_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_MirrorBlock;
extern VAR(RearBrkEvent_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_RearBrakeEvent_MirrorBlock;
extern VAR(SPMAbrtEvent_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_SPMAbrtEvent_MirrorBlock;
extern VAR(US_S_MarriageSensorIDs_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_PartNumMgr_UssSensorMarrData_MirrorBlock;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint32, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SecondCounter_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_MirrorBlock;
extern VAR(boolean, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_CDD_CryptoMgr_NvMBlockDescriptor_CertificateExpired_MirrorBlock;
extern VAR(Array_15Bytes, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_MirrorBlock;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock;
extern VAR(Arr_2Byte, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock;
extern VAR(INVMSignalManager_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock;
extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock;
extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock;
extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock;
extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock;
extern VAR(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock;
extern VAR(CDP_TbSVS_S_SVSCamEOLCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock;
extern VAR(CDP_TbSVS_S_SVSCamOCCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock;
extern VAR(CDP_TbSVS_S_SVSCamSCCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock;
extern VAR(ME_Hydra2defs_S_CodingTableExt_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock;
extern VAR(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT) Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# endif

/**********************************************************************************************************************
 * Type definitions for activation reasons of runnables
 *********************************************************************************************************************/

typedef uint8 Rte_ActivatingEvent_RE_UpdateNMState; /* PRQA S 0786 */ /* MD_Rte_0786 */
# define Rte_ActivatingEvent_RE_UpdateNMState_ActReason_BUSSLEEP    2U
# define Rte_ActivatingEvent_RE_UpdateNMState_ActReason_NORMAL    16U
# define Rte_ActivatingEvent_RE_UpdateNMState_ActReason_PREPARESLEEP    4U
# define Rte_ActivatingEvent_RE_UpdateNMState_ActReason_READYSLEEP    8U
# define Rte_ActivatingEvent_RE_UpdateNMState_ActReason_REPEATMSG    32U
# define Rte_ActivatingEvent_RE_UpdateNMState_ActReason_UNINIT    1U

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned int Rte_BitType;
/**********************************************************************************************************************
 * type and extern declarations of RTE internal variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

# define RTE_STATE_UNINIT     (0U)
# define RTE_STATE_SCHM_START (1U)
# define RTE_STATE_SCHM_INIT  (2U)
# define RTE_STATE_INIT       (3U)

# define RTE_START_SEC_VAR_ZERO_INIT_8BIT
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState; /* PRQA S 3408 */ /* MD_Rte_3408 */
extern volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_StartTiming_InitState; /* PRQA S 0850, 3408 */ /* MD_MSR_MacroArgumentEmpty, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef RTE_CORE

/**********************************************************************************************************************
 * Calibration Parameters (SW-C local and calibration component calibration parameters)
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SecondCounter_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_ECU_LifeTime_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2002_OdoFlashing_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200A_IgOnCounter_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD74_BuffMarkCompErr_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Safety_Guard_SafeStat2_ResetReason_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_191D_PowerLatch_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD42_FailsafeAction_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_vRoE_Activation_State_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_Lock_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_OdometerCnt_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(boolean, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_CertificateExpired_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Array_15Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Arr_2Byte, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Arr_20Byte, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2939_WakeupReason_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(DID_F110_Pin_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data13ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data2ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Dcm_Data4ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(VINlData_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_CurrentVal_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(VINlData_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_OriginalVal_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(SecureLogRecord_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(SecureLogRecord_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(INVMSignalManager_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_IPCHandler_FPA_Slot_Data_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_FrontCamSerialNumber_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_LeftCamSerialNumber_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_RearCamSerialNumber_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_RightCamSerialNumber_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(CDP_TbSVS_S_SVSCamEOLCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(CDP_TbSVS_S_SVSCamOCCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(CDP_TbSVS_S_SVSCamSCCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(TbSVS_S_SVSCamCurrentCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(FunctionalSettings_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(RearBrkEvent_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_RearBrakeEvent_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(SPMAbrtEvent_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_SPMAbrtEvent_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(US_S_MarriageSensorIDs_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_UssSensorMarrData_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(ME_Hydra2defs_S_CodingTableExt_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_ProxiConfigMgr_ProxiConfigTable_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_ProxiConfigMgr_ProxiErrorData_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(BswM_DtcSettingClearFlagModeGrp, RTE_VAR_INIT) Rte_SWC_DTCMgr_PRpDtcSettingClearFlagModeGrp_requestedMode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpBSWM_PostRunRequest_0_requestedMode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpBSWM_PostRunRequest_1_requestedMode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpBSWM_RunRequest_0_requestedMode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpBSWM_RunRequest_1_requestedMode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(BswM_BswM_PreviousNMState, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpBswM_PreviousNMState_requestedMode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpGetFirstDTCStatus_DeFirstDTCStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpNmStateInfo_v_IsNmStateNormal_b; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SystemState, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpSystemStateManager_SysM_State; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_CurrentCanNMState_FD02_PAM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_CurrentFailSts_FD02_PAM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_DES_FD02_PAM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_GenericFailSts_FD02_PAM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_PreviousCanNMState_FD02_PAM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(StayActiveSource_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_StayActiveSource_FD02_PAM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_WakeupSource_FD02_PAM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FIDOutputArr_QM, RTE_VAR_INIT) Rte_DegManager_QM_P_FID_Output_QM_FID_QM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DtcAddData_QM, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_QM_P_DtcData_Data_DtcAddData_QM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DtcStatus_QM, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_QM_P_DtcData_Data_DtcStatus_QM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ErrorListArr_QM, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_QM_P_Errors_QM_Errors_QM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SafeStateOpDef, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_QM_P_SafeState_SafeStateOp; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SSM_SystemState, RTE_VAR_INIT) Rte_SSM_Master_P_SystemState_SystemState; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SSM_1_0_CoreStatus, RTE_VAR_INIT) Rte_SSM_Slave_1_0_P_SSM_1_0_State_State_1_0; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint32, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpECUTimeSinceIGON_ECUTimeStamp_IGON; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint32, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpECUTimeStamp_ECUTimeStamp; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpFailsafeAction_FailSafe_State; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpFailsafeDebug_Debugflag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpGearPosition_GearValue; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpGearPosition_ShortTermAdjActiveFlag_b; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint32, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpIgOnCounter_IGCounter; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpPerformanceStatsEnable_RunTimeStatsEnable; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpPerformanceStatsEnable_StackUsageStatsEnable; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpResetNvmFlag_V_ResetNvmFlag_b; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpSleepProcessState_status; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_DIDMgr_Pp_PlantOdoData_PlantOdoData; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DTCMgr_PpDtcB12852AData_v_DtcData_u8; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DTCMgr_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_PartNumMgr_PpFlashSts_v_FlashSts_u16; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_Altitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_89a927da_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(BSM_THA_Brk_Resp, RTE_VAR_INIT) Rte_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN2_c6b9d212_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_Battery_Volt_1_oBCM_FD_3_oFDCAN2_c3a895dd_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD01_BCM, RTE_VAR_INIT) Rte_CurrentCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_cb3619a3_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD01_SGW, RTE_VAR_INIT) Rte_CurrentCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_05d1101e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD02_BCM, RTE_VAR_INIT) Rte_CurrentCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_8f973cbb_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD02_BSM2, RTE_VAR_INIT) Rte_CurrentCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_3f8b7635_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD02_CADM2, RTE_VAR_INIT) Rte_CurrentCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f804ab44_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD02_EPS, RTE_VAR_INIT) Rte_CurrentCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_277b5480_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD02_ORC, RTE_VAR_INIT) Rte_CurrentCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_146fe160_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD02_SGW, RTE_VAR_INIT) Rte_CurrentCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_41703506_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD02_TRLR_REV, RTE_VAR_INIT) Rte_CurrentCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_e2caab79_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD03_BCM, RTE_VAR_INIT) Rte_CurrentCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b3f7dfb3_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD03_SGW, RTE_VAR_INIT) Rte_CurrentCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7d10d60e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD04_BCM, RTE_VAR_INIT) Rte_CurrentCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_06d5768b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD08_SGW, RTE_VAR_INIT) Rte_CurrentCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_01c7ed17_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD11_SGW, RTE_VAR_INIT) Rte_CurrentCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0b36f8cf_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD01_BCM, RTE_VAR_INIT) Rte_CurrentFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b0c60e26_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD01_SGW, RTE_VAR_INIT) Rte_CurrentFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7e21079b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD02_BCM, RTE_VAR_INIT) Rte_CurrentFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f4672b3e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD02_BSM2, RTE_VAR_INIT) Rte_CurrentFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_faace40c_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD02_CADM2, RTE_VAR_INIT) Rte_CurrentFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_e88111b1_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD02_EPS, RTE_VAR_INIT) Rte_CurrentFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_5c8b4305_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD02_ORC, RTE_VAR_INIT) Rte_CurrentFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_6f9ff6e5_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD02_SGW, RTE_VAR_INIT) Rte_CurrentFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3a802283_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD02_TRLR_REV, RTE_VAR_INIT) Rte_CurrentFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_3b43d61f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD03_BCM, RTE_VAR_INIT) Rte_CurrentFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c807c836_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD03_SGW, RTE_VAR_INIT) Rte_CurrentFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_06e0c18b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD04_BCM, RTE_VAR_INIT) Rte_CurrentFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7d25610e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD08_SGW, RTE_VAR_INIT) Rte_CurrentFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7a37fa92_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD11_SGW, RTE_VAR_INIT) Rte_CurrentFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_70c6ef4a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD01_BCM, RTE_VAR_INIT) Rte_DES_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3865098f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD01_SGW, RTE_VAR_INIT) Rte_DES_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6820032_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD02_BCM, RTE_VAR_INIT) Rte_DES_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7cc42c97_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD02_BSM2, RTE_VAR_INIT) Rte_DES_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_1b0dfeac_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD02_CADM2, RTE_VAR_INIT) Rte_DES_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_bbe4b583_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD02_EPS, RTE_VAR_INIT) Rte_DES_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d42844ac_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD02_ORC, RTE_VAR_INIT) Rte_DES_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e73cf14c_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD02_SGW, RTE_VAR_INIT) Rte_DES_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b223252a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD02_TRLR_REV, RTE_VAR_INIT) Rte_DES_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9554de37_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD03_BCM, RTE_VAR_INIT) Rte_DES_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_40a4cf9f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD03_SGW, RTE_VAR_INIT) Rte_DES_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e43c622_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD04_BCM, RTE_VAR_INIT) Rte_DES_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f58666a7_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD08_SGW, RTE_VAR_INIT) Rte_DES_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f294fd3b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD11_SGW, RTE_VAR_INIT) Rte_DES_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f865e8e3_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DeltaTimestamp_IMUdata, RTE_VAR_INIT) Rte_DeltaTimestamp_IMUdata_oGLOB_NAV_FD_C2_oFDCAN2_bb3ce8c3_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_01, RTE_VAR_INIT) Rte_Digit_01_oCFG_DATA_CODE_REQUEST_oFDCAN2_c824c64f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_02, RTE_VAR_INIT) Rte_Digit_02_oCFG_DATA_CODE_REQUEST_oFDCAN2_013bcef0_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_03, RTE_VAR_INIT) Rte_Digit_03_oCFG_DATA_CODE_REQUEST_oFDCAN2_f0e1cb5a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_04, RTE_VAR_INIT) Rte_Digit_04_oCFG_DATA_CODE_REQUEST_oFDCAN2_4874d9cf_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_05, RTE_VAR_INIT) Rte_Digit_05_oCFG_DATA_CODE_REQUEST_oFDCAN2_b9aedc65_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_06, RTE_VAR_INIT) Rte_Digit_06_oCFG_DATA_CODE_REQUEST_oFDCAN2_70b1d4da_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_07, RTE_VAR_INIT) Rte_Digit_07_oCFG_DATA_CODE_REQUEST_oFDCAN2_816bd170_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_08, RTE_VAR_INIT) Rte_Digit_08_oCFG_DATA_CODE_REQUEST_oFDCAN2_daeaf7b1_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_09, RTE_VAR_INIT) Rte_Digit_09_oCFG_DATA_CODE_REQUEST_oFDCAN2_2b30f21b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_10, RTE_VAR_INIT) Rte_Digit_10_oCFG_DATA_CODE_REQUEST_oFDCAN2_0f0c5316_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_11, RTE_VAR_INIT) Rte_Digit_11_oCFG_DATA_CODE_REQUEST_oFDCAN2_fed656bc_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD01_BCM, RTE_VAR_INIT) Rte_EOL_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_bf538820_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD01_SGW, RTE_VAR_INIT) Rte_EOL_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_71b4819d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD02_BCM, RTE_VAR_INIT) Rte_EOL_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_fbf2ad38_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD02_BSM2, RTE_VAR_INIT) Rte_EOL_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a82d6a0a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD02_CADM2, RTE_VAR_INIT) Rte_EOL_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_b4db4a91_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD02_EPS, RTE_VAR_INIT) Rte_EOL_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_531ec503_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD02_ORC, RTE_VAR_INIT) Rte_EOL_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_600a70e3_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD02_SGW, RTE_VAR_INIT) Rte_EOL_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3515a485_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD02_TRLR_REV, RTE_VAR_INIT) Rte_EOL_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_b23a15e1_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD03_BCM, RTE_VAR_INIT) Rte_EOL_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c7924e30_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD03_SGW, RTE_VAR_INIT) Rte_EOL_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0975478d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD04_BCM, RTE_VAR_INIT) Rte_EOL_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_72b0e708_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD08_SGW, RTE_VAR_INIT) Rte_EOL_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_75a27c94_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD11_SGW, RTE_VAR_INIT) Rte_EOL_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7f53694c_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EPBSts, RTE_VAR_INIT) Rte_EPBSts_oBRAKE_FD_4_oFDCAN2_4e811a74_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD01_BCM, RTE_VAR_INIT) Rte_GenericFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_aaf66243_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD01_SGW, RTE_VAR_INIT) Rte_GenericFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_64116bfe_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD02_BCM, RTE_VAR_INIT) Rte_GenericFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_ee57475b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD02_BSM2, RTE_VAR_INIT) Rte_GenericFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a6224cad_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD02_CADM2, RTE_VAR_INIT) Rte_GenericFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_8790eb4d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD02_EPS, RTE_VAR_INIT) Rte_GenericFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_46bb2f60_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD02_ORC, RTE_VAR_INIT) Rte_GenericFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_75af9a80_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD02_SGW, RTE_VAR_INIT) Rte_GenericFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_20b04ee6_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD02_TRLR_REV, RTE_VAR_INIT) Rte_GenericFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_f0b9fb66_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD03_BCM, RTE_VAR_INIT) Rte_GenericFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_d237a453_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD03_SGW, RTE_VAR_INIT) Rte_GenericFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_1cd0adee_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD04_BCM, RTE_VAR_INIT) Rte_GenericFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_67150d6b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD08_SGW, RTE_VAR_INIT) Rte_GenericFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_600796f7_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD11_SGW, RTE_VAR_INIT) Rte_GenericFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_6af6832f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_Heading_Angle_C2_oGLOB_NAV_FD_C2_oFDCAN2_3c56c554_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(IgnitionOnCounter, RTE_VAR_INIT) Rte_IgnitionOnCounter_oBCM_FD_7_oFDCAN2_72afbff6_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_01eb70e0_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LHF_FastPulseCounter, RTE_VAR_INIT) Rte_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_1316f7bd_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LHF_Spin, RTE_VAR_INIT) Rte_LHF_Spin_oBRAKE_FD_3_oFDCAN2_ddb3a606_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d40a5eb4_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LHR_FastPulseCounter, RTE_VAR_INIT) Rte_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_fd14f99b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LHR_Spin, RTE_VAR_INIT) Rte_LHR_Spin_oBRAKE_FD_3_oFDCAN2_5d756ba0_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_18f7c44e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_LatAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_faefb913_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_Latitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_3a18037a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_a123ae38_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_LongAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_38530c91_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_Longitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1b6c4b2a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(OperationalModeSts, RTE_VAR_INIT) Rte_OperationalModeSts_oBCM_FD_2_oFDCAN2_92d9b16a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_PitchRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_3e30fc55_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_Pitch_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1cc85bc5_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD01_BCM, RTE_VAR_INIT) Rte_PreviousCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_99b0bece_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD01_SGW, RTE_VAR_INIT) Rte_PreviousCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_5757b773_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD02_BCM, RTE_VAR_INIT) Rte_PreviousCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_dd119bd6_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD02_BSM2, RTE_VAR_INIT) Rte_PreviousCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a76a0712_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD02_CADM2, RTE_VAR_INIT) Rte_PreviousCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_05c3c06a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD02_EPS, RTE_VAR_INIT) Rte_PreviousCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_75fdf3ed_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD02_ORC, RTE_VAR_INIT) Rte_PreviousCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_46e9460d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD02_SGW, RTE_VAR_INIT) Rte_PreviousCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_13f6926b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD02_TRLR_REV, RTE_VAR_INIT) Rte_PreviousCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_6708bf5f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD03_BCM, RTE_VAR_INIT) Rte_PreviousCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_e17178de_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD03_SGW, RTE_VAR_INIT) Rte_PreviousCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_2f967163_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD04_BCM, RTE_VAR_INIT) Rte_PreviousCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_5453d1e6_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD08_SGW, RTE_VAR_INIT) Rte_PreviousCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_53414a7a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD11_SGW, RTE_VAR_INIT) Rte_PreviousCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_59b05fa2_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN2_6b1619cb_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_02ea90a1_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RHF_FastPulseCounter, RTE_VAR_INIT) Rte_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_c8fb14ac_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RHF_Spin, RTE_VAR_INIT) Rte_RHF_Spin_oBRAKE_FD_3_oFDCAN2_ceff9170_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d70bbef5_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RHR_FastPulseCounter, RTE_VAR_INIT) Rte_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_26f91a8a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RHR_Spin, RTE_VAR_INIT) Rte_RHR_Spin_oBRAKE_FD_3_oFDCAN2_4e395cd6_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RemStActvSts, RTE_VAR_INIT) Rte_RemStActvSts_oBCM_FD_2_oFDCAN2_fb4ede64_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_RollRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_d526080b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_Roll_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_90f031c2_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SBR1RowDriverSeatSts, RTE_VAR_INIT) Rte_SBR1RowDriverSeatSts_oORC_FD_1_oFDCAN2_bc99e8d7_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD01_BCM_64, RTE_VAR_INIT) Rte_StayActiveSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3841343a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD01_SGW_64, RTE_VAR_INIT) Rte_StayActiveSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6a63d87_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD02_BCM_64, RTE_VAR_INIT) Rte_StayActiveSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7ce01122_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD02_BSM2_64, RTE_VAR_INIT) Rte_StayActiveSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dad7e864_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD02_CADM2_64, RTE_VAR_INIT) Rte_StayActiveSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_4c139c4e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD02_EPS_64, RTE_VAR_INIT) Rte_StayActiveSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d40c7919_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD02_ORC_64, RTE_VAR_INIT) Rte_StayActiveSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e718ccf9_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD02_SGW_64, RTE_VAR_INIT) Rte_StayActiveSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b207189f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD02_TRLR_REV_64, RTE_VAR_INIT) Rte_StayActiveSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_5fc9d563_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD03_BCM_64, RTE_VAR_INIT) Rte_StayActiveSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_4080f22a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD03_SGW_64, RTE_VAR_INIT) Rte_StayActiveSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e67fb97_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD04_BCM_64, RTE_VAR_INIT) Rte_StayActiveSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f5a25b12_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD08_SGW_64, RTE_VAR_INIT) Rte_StayActiveSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f2b0c08e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD11_SGW_64, RTE_VAR_INIT) Rte_StayActiveSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f841d556_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_CenterBtn_Sts, RTE_VAR_INIT) Rte_TRSC_CenterBtn_Sts_oTRSKM_FD_1_oFDCAN2_08058c70_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_EnableBtn_Sts, RTE_VAR_INIT) Rte_TRSC_EnableBtn_Sts_oTRSKM_FD_1_oFDCAN2_e08a4639_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_RawKnob, RTE_VAR_INIT) Rte_TRSC_RawKnob_oTRSKM_FD_1_oFDCAN2_88488965_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TotalOdometer, RTE_VAR_INIT) Rte_TotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TurnIndicatorSts, RTE_VAR_INIT) Rte_TurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(VehicleStandStillSts, RTE_VAR_INIT) Rte_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN2_ae5f13a6_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_VerticalAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_10e58c6b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD01_ADCM, RTE_VAR_INIT) Rte_WakeupSource_FD01_ADCM_oPDC_INFO_FD_ADCM_oFDCAN2_bce36ee5_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD01_BCM, RTE_VAR_INIT) Rte_WakeupSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_603c89e8_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD01_SGW, RTE_VAR_INIT) Rte_WakeupSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aedb8055_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD02_BCM, RTE_VAR_INIT) Rte_WakeupSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_249dacf0_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD02_BSM2, RTE_VAR_INIT) Rte_WakeupSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dc09d8b5_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD02_CADM2, RTE_VAR_INIT) Rte_WakeupSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f2e95e62_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD02_EPS, RTE_VAR_INIT) Rte_WakeupSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_8c71c4cb_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD02_ORC, RTE_VAR_INIT) Rte_WakeupSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_bf65712b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD02_SGW, RTE_VAR_INIT) Rte_WakeupSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_ea7aa54d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD02_TRLR_REV, RTE_VAR_INIT) Rte_WakeupSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9a698e4c_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD03_BCM, RTE_VAR_INIT) Rte_WakeupSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_18fd4ff8_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD03_SGW, RTE_VAR_INIT) Rte_WakeupSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_d61a4645_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD04_BCM, RTE_VAR_INIT) Rte_WakeupSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_addfe6c0_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD08_SGW, RTE_VAR_INIT) Rte_WakeupSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aacd7d5c_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD11_SGW, RTE_VAR_INIT) Rte_WakeupSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_a03c6884_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_YawRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_f8e96c1f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_YawRate_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_c10121c7_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpCalibRoutineTrigger_routine_b; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpCalibRoutineType_value; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CanDebugMode_t, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpCan14DbgRoutineState_Can14DbgRoutine; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpFailSafeReaction_State; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpPlantMode_Status; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(VINlData_Arr, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpVINData_VINCurrentData; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpVINData_VINLockStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpVINData_VINOdoCounter; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(VINlData_Arr, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpVINData_VINOriginalData; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(APARequestSts, RTE_VAR_INIT) Rte_APARequestSts_oBCM_FD_12_oFDCAN2_c58fc45d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ASCM_Stat, RTE_VAR_INIT) Rte_ASCM_Stat_oASCM_FD_2_oFDCAN2_58854b4a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ASCM_SysFail, RTE_VAR_INIT) Rte_ASCM_SysFail_oASCM_FD_2_oFDCAN2_9d00e371_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Active_Park_Mode, RTE_VAR_INIT) Rte_Active_Park_Mode_oIPC_VEHICLE_SETUP_oFDCAN2_6a2a58c7_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Active_Park_Prox_Chime, RTE_VAR_INIT) Rte_Active_Park_Prox_Chime_oIPC_VEHICLE_SETUP_oFDCAN2_ae5aba94_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Backup_Cam_Delay, RTE_VAR_INIT) Rte_Backup_Cam_Delay_oIPC_VEHICLE_SETUP_oFDCAN2_4de26278_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Brk_Stat, RTE_VAR_INIT) Rte_Brk_Stat_oBRAKE_FD_2_oFDCAN2_1b647924_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CM_TCH_STAT, RTE_VAR_INIT) Rte_CM_TCH_STAT_oTELEMATIC_FD_5_oFDCAN2_64ce192d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CM_TCH_X_COORD, RTE_VAR_INIT) Rte_CM_TCH_X_COORD_oTELEMATIC_FD_5_oFDCAN2_0177f5f2_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CM_TCH_Y_COORD, RTE_VAR_INIT) Rte_CM_TCH_Y_COORD_oTELEMATIC_FD_5_oFDCAN2_0f901d23_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CameraDisplaySts2, RTE_VAR_INIT) Rte_CameraDisplaySts2_oTELEMATIC_FD_5_oFDCAN2_3ea6a9f0_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CmdIgnSts, RTE_VAR_INIT) Rte_CmdIgnSts_oBCM_FD_10_oFDCAN2_06c30ef2_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DriverDoorSts, RTE_VAR_INIT) Rte_DriverDoorSts_oBCM_FD_9_oFDCAN2_5b5b4a2d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DynamicGrid, RTE_VAR_INIT) Rte_DynamicGrid_oIPC_VEHICLE_SETUP_oFDCAN2_8defe0e1_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ECM_THA_Resp, RTE_VAR_INIT) Rte_ECM_THA_Resp_oENGINE_FD_7_oFDCAN2_4f167839_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ECM_TRSC_Resp, RTE_VAR_INIT) Rte_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN2_7dcf088b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EPS_SteeringTouchStat, RTE_VAR_INIT) Rte_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN2_70168af6_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EPS_SteeringTouq_Resp, RTE_VAR_INIT) Rte_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN2_a31e0e47_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EPS_THA_DriverTorqueOverride, RTE_VAR_INIT) Rte_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN2_0e3a0a14_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EPS_THA_SteeringTorqueResp, RTE_VAR_INIT) Rte_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN2_2f8c0396_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ESS_ENG_ST_W, RTE_VAR_INIT) Rte_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN2_b1b6db89_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EngineSts_W, RTE_VAR_INIT) Rte_EngineSts_W_oENGINE_FD_2_oFDCAN2_7417ef03_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ExternalTemperature, RTE_VAR_INIT) Rte_ExternalTemperature_oBCM_FD_9_oFDCAN2_fd16cd2c_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FL_Lvl, RTE_VAR_INIT) Rte_FL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FL_Lvl_Adj, RTE_VAR_INIT) Rte_FL_Lvl_Adj_oASCM_FD_1_oFDCAN2_959485e3_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FR_Lvl, RTE_VAR_INIT) Rte_FR_Lvl_oASCM_FD_1_oFDCAN2_6f14419a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FR_Lvl_Adj, RTE_VAR_INIT) Rte_FR_Lvl_Adj_oASCM_FD_1_oFDCAN2_86d8b295_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FT_PAMRequestSts, RTE_VAR_INIT) Rte_FT_PAMRequestSts_oBCM_FD_12_oFDCAN2_eca5b16e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Fwrd_Cam_Guidelines, RTE_VAR_INIT) Rte_Fwrd_Cam_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_195fae0b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GearEngaged, RTE_VAR_INIT) Rte_GearEngaged_oTRANSM_FD_4_oFDCAN2_d9ac16c5_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GearEngagedForDisplay, RTE_VAR_INIT) Rte_GearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(HAS_Status_C2, RTE_VAR_INIT) Rte_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(HU_TRSC_EnableBtn_Sts, RTE_VAR_INIT) Rte_HU_TRSC_EnableBtn_Sts_oTELEMATIC_FD_11_oFDCAN2_298c059b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ITBM_TrlrStat, RTE_VAR_INIT) Rte_ITBM_TrlrStat_oBCM_FD_29_oFDCAN2_144a42ca_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LHRDoorSts, RTE_VAR_INIT) Rte_LHRDoorSts_oBCM_FD_9_oFDCAN2_6106f88b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LanguageSelection, RTE_VAR_INIT) Rte_LanguageSelection_oIPC_VEHICLE_SETUP_oFDCAN2_99c6c76e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LatAcceleration_BSM, RTE_VAR_INIT) Rte_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_318e470e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LongAcceleration_BSM, RTE_VAR_INIT) Rte_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_f132a23a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LwsAngle, RTE_VAR_INIT) Rte_LwsAngle_oEPS_FD_1_oFDCAN2_4dcc502d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LwsAngleType, RTE_VAR_INIT) Rte_LwsAngleType_oEPS_FD_1_oFDCAN2_aea1ae81_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LwsSpeed, RTE_VAR_INIT) Rte_LwsSpeed_oEPS_FD_1_oFDCAN2_08f75f98_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(MRM_STATUS_C2, RTE_VAR_INIT) Rte_MRM_STATUS_C2_oADAS_FD_INFO_C2_oFDCAN2_8ba84d40_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAMRequestSts, RTE_VAR_INIT) Rte_PAMRequestSts_oBCM_FD_12_oFDCAN2_006058fe_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PamChimeVolumeFront, RTE_VAR_INIT) Rte_PamChimeVolumeFront_oIPC_VEHICLE_SETUP_oFDCAN2_6b01781e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PamChimeVolumeRear, RTE_VAR_INIT) Rte_PamChimeVolumeRear_oIPC_VEHICLE_SETUP_oFDCAN2_f55f4149_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PdlPosActual, RTE_VAR_INIT) Rte_PdlPosActual_oENGINE_FD_5_oFDCAN2_743309cb_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PsngrDoorSts, RTE_VAR_INIT) Rte_PsngrDoorSts_oBCM_FD_9_oFDCAN2_661d805a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RHRDoorSts, RTE_VAR_INIT) Rte_RHRDoorSts_oBCM_FD_9_oFDCAN2_724acffd_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RHatchSts, RTE_VAR_INIT) Rte_RHatchSts_oBCM_FD_9_oFDCAN2_9f16b516_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RL_Lvl, RTE_VAR_INIT) Rte_RL_Lvl_oASCM_FD_1_oFDCAN2_d1e53ddc_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RL_Lvl_Adj, RTE_VAR_INIT) Rte_RL_Lvl_Adj_oASCM_FD_1_oFDCAN2_44326a37_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RR_Lvl, RTE_VAR_INIT) Rte_RR_Lvl_oASCM_FD_1_oFDCAN2_ccbe2c0f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RR_Lvl_Adj, RTE_VAR_INIT) Rte_RR_Lvl_Adj_oASCM_FD_1_oFDCAN2_577e5d41_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Rear_Brk_Asst, RTE_VAR_INIT) Rte_Rear_Brk_Asst_oIPC_VEHICLE_SETUP_oFDCAN2_96e3f1cb_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SVC_Guidelines, RTE_VAR_INIT) Rte_SVC_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_3eb27f57_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ShiftLeverPosition, RTE_VAR_INIT) Rte_ShiftLeverPosition_oTRANSM_FD_4_oFDCAN2_e41ef7f4_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ShiftLeverPositionReq, RTE_VAR_INIT) Rte_ShiftLeverPositionReq_oAGSM_FD_2_oFDCAN2_dff8c8a2_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Shifter_ADAS_Inhibit, RTE_VAR_INIT) Rte_Shifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TCASERANGESTATUS, RTE_VAR_INIT) Rte_TCASERANGESTATUS_oDRIVETRAIN_FD_3_oFDCAN2_eee864ec_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TGW_CAMERA_DISP_STAT, RTE_VAR_INIT) Rte_TGW_CAMERA_DISP_STAT_oTELEMATIC_FD_14_oFDCAN2_9304ed4e_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(THA_SteeringTouchStat, RTE_VAR_INIT) Rte_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN2_b7575370_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRANS_ADAS_Inhibit, RTE_VAR_INIT) Rte_TRANS_ADAS_Inhibit_oTRANSM_FD_1_oFDCAN2_6ec0c415_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TargetGear, RTE_VAR_INIT) Rte_TargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TrailerConnectionSts, RTE_VAR_INIT) Rte_TrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TransmissionSailingSts, RTE_VAR_INIT) Rte_TransmissionSailingSts_oTRANSM_FD_1_oFDCAN2_86af8834_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(VIN_DATA, RTE_VAR_INIT) Rte_VIN_DATA_oVIN_oFDCAN2_c66224e9_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(VIN_MSG, RTE_VAR_INIT) Rte_VIN_MSG_oVIN_oFDCAN2_f39912b4_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(VehicleSpeedVSOSig, RTE_VAR_INIT) Rte_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN2_53fecdc7_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(YawRate_BSM, RTE_VAR_INIT) Rte_YawRate_BSM_oBRAKE_FD_2_oFDCAN2_64569af1_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ACC_Systemsts, RTE_VAR_INIT) Rte_FD14_ACC_Systemsts_oADAS_FD_INFO_oFDCAN14_2086cf20_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_BSM_THA_Brk_Resp, RTE_VAR_INIT) Rte_FD14_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN14_cecdbc25_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_BrkPdl_Stat, RTE_VAR_INIT) Rte_FD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_BrkTrq, RTE_VAR_INIT) Rte_FD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_BrkTrq_Driver, RTE_VAR_INIT) Rte_FD14_BrkTrq_Driver_oBRAKE_FD_1_oFDCAN14_f4f61916_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Brk_Stat, RTE_VAR_INIT) Rte_FD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ECM_THA_Resp, RTE_VAR_INIT) Rte_FD14_ECM_THA_Resp_oENGINE_FD_7_oFDCAN14_284045ab_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ECM_TRSC_Resp, RTE_VAR_INIT) Rte_FD14_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN14_994d6c00_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_EPBSts, RTE_VAR_INIT) Rte_FD14_EPBSts_oBRAKE_FD_4_oFDCAN14_c0ca10e6_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_EPS_HandsOnRecognition, RTE_VAR_INIT) Rte_FD14_EPS_HandsOnRecognition_oEPS_FD_1_oFDCAN14_58e651a9_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_EPS_SteeringTouchStat, RTE_VAR_INIT) Rte_FD14_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cae7cd32_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_EPS_SteeringTouq_Resp, RTE_VAR_INIT) Rte_FD14_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN14_765246ac_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_EPS_THA_DriverTorqueOverride, RTE_VAR_INIT) Rte_FD14_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN14_2abac25d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_EPS_THA_SteeringTorqueResp, RTE_VAR_INIT) Rte_FD14_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN14_c35bede9_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ESC_TRSC_Brk_Resp, RTE_VAR_INIT) Rte_FD14_ESC_TRSC_Brk_Resp_oBRAKE_FD_5_oFDCAN14_2f38fcaf_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ESS_ENG_ST_W, RTE_VAR_INIT) Rte_FD14_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN14_e3df5684_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_EngineSts_W, RTE_VAR_INIT) Rte_FD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ExternalBrkRequestsDisabled, RTE_VAR_INIT) Rte_FD14_ExternalBrkRequestsDisabled_oBRAKE_FD_1_oFDCAN14_3622ec06_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_HAS_Status, RTE_VAR_INIT) Rte_FD14_HAS_Status_oADAS_FD_INFO_oFDCAN14_368cf8df_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHFWheelSpeed, RTE_VAR_INIT) Rte_FD14_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d701d2d3_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHF_FastPulseCounter, RTE_VAR_INIT) Rte_FD14_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_c079cbbf_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHF_Spin, RTE_VAR_INIT) Rte_FD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_FD14_LHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_3a28d00b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHRWheelSpeed, RTE_VAR_INIT) Rte_FD14_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_bbd2a610_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHR_FastPulseCounter, RTE_VAR_INIT) Rte_FD14_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_129a4c4c_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHR_Spin, RTE_VAR_INIT) Rte_FD14_LHR_Spin_oBRAKE_FD_3_oFDCAN14_eda6ba5c_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_FD14_LHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_7665a615_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LatAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_FD14_LatAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_b6857dc3_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LatAccelerationOffset_BSM, RTE_VAR_INIT) Rte_FD14_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_045731ef_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LatAcceleration_BSM, RTE_VAR_INIT) Rte_FD14_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_79c02fd1_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LongAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_FD14_LongAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_7b4ee1d6_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LongAccelerationOffset_BSM, RTE_VAR_INIT) Rte_FD14_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_18cdb71a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LongAcceleration_BSM, RTE_VAR_INIT) Rte_FD14_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_b347f969_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LwsAngle, RTE_VAR_INIT) Rte_FD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LwsAngleType, RTE_VAR_INIT) Rte_FD14_LwsAngleType_oEPS_FD_1_oFDCAN14_8f61bc22_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LwsSpeed, RTE_VAR_INIT) Rte_FD14_LwsSpeed_oEPS_FD_1_oFDCAN14_6930c8f0_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PAM_Brk_Rq_RspSts, RTE_VAR_INIT) Rte_FD14_PAM_Brk_Rq_RspSts_oBRAKE_FD_7_oFDCAN14_65c28072_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ParkingGearShiftReq_BSM, RTE_VAR_INIT) Rte_FD14_ParkingGearShiftReq_BSM_oBRAKE_FD_2_oFDCAN14_45df8c18_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ParkingInterventionSts, RTE_VAR_INIT) Rte_FD14_ParkingInterventionSts_oBRAKE_FD_2_oFDCAN14_9b11ef29_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PdlPosActual, RTE_VAR_INIT) Rte_FD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_REF_VEH_SPEED, RTE_VAR_INIT) Rte_FD14_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN14_7bd7d6fa_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHFWheelSpeed, RTE_VAR_INIT) Rte_FD14_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d6d9a235_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHF_FastPulseCounter, RTE_VAR_INIT) Rte_FD14_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_aa1206ae_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHF_Spin, RTE_VAR_INIT) Rte_FD14_RHF_Spin_oBRAKE_FD_3_oFDCAN14_6be6e272_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_FD14_RHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_8c24277d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHRWheelSpeed, RTE_VAR_INIT) Rte_FD14_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_ba0ad6f6_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHR_FastPulseCounter, RTE_VAR_INIT) Rte_FD14_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_78f1815d_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHR_Spin, RTE_VAR_INIT) Rte_FD14_RHR_Spin_oBRAKE_FD_3_oFDCAN14_54d32262_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_FD14_RHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_c0695163_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_SPM_Lat_Ctrl_ResponseSts, RTE_VAR_INIT) Rte_FD14_SPM_Lat_Ctrl_ResponseSts_oEPS_FD_1_oFDCAN14_35f1e4d0_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Slope, RTE_VAR_INIT) Rte_FD14_Slope_oBRAKE_FD_2_oFDCAN14_a6806d2f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Steering_Column_Torque, RTE_VAR_INIT) Rte_FD14_Steering_Column_Torque_oEPS_FD_1_oFDCAN14_485a089f_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_THA_SteeringTouchStat, RTE_VAR_INIT) Rte_FD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_VehicleSpeedVSOSig, RTE_VAR_INIT) Rte_FD14_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN14_66b2f28a_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_VehicleSpeedVSOSig_B2, RTE_VAR_INIT) Rte_FD14_VehicleSpeedVSOSig_B2_oBRAKE2_FD_1_oFDCAN14_1870b968_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_VehicleStandStillSts, RTE_VAR_INIT) Rte_FD14_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN14_4aa14bb7_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_YawRateFailSts_BSM, RTE_VAR_INIT) Rte_FD14_YawRateFailSts_BSM_oBRAKE_FD_2_oFDCAN14_07cbb027_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_YawRate_BSM, RTE_VAR_INIT) Rte_FD14_YawRate_BSM_oBRAKE_FD_2_oFDCAN14_feebc52b_Rx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_VCANRx_PpBusOffIndication_V_BusOffIndicationFlagRte_u8; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Battery_Volt_1, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_Battery_Volt_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EPBSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_EPBSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(IgnitionOnCounter, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_IgnitionOnCounter; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(OperationalModeSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_OperationalModeSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RemStActvSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_RemStActvSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_EnableBtn_Sts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TRSC_EnableBtn_Sts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TotalOdometer, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TurnIndicatorSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TurnIndicatorSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ME_VehInp_to_IpcSignals_QM_t, RTE_VAR_INIT) Rte_SWC_VCANRx_PpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD02_PAM, RTE_VAR_INIT) Rte_SWC_VCANTx_PpToSwcFD02Tx_CurrentFailSts_FD02_PAM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD02_PAM, RTE_VAR_INIT) Rte_SWC_VCANTx_PpToSwcFD02Tx_GenericFailSts_FD02_PAM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(THA_STAT, RTE_VAR_INIT) Rte_SWC_VCANTx_PpToSwcFD02Tx_THA_STAT; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_STAT, RTE_VAR_INIT) Rte_SWC_VCANTx_PpToSwcFD02Tx_TRSC_STAT; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_VoltageMgr_PpTemperatureVal_GetTemperatureVal; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UssPowerSense, RTE_VAR_INIT) Rte_SWC_VoltageMgr_PpUssPowerData_UssPower; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(udtBatteryVoltageStatus, RTE_VAR_INIT) Rte_SWC_VoltageMgr_PpVoltageChannelStatus_BatteryVoltageStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(vRoE_MessageType, RTE_VAR_INIT) Rte_vRoE_RoEMessage_Data; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(TbAP_APSMPAOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpAPSMPAOut_TbAP_APSMPAOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CAM_select_info_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCAMSelInfo_CAM_select_info_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(IFOD_Outputs_CVPAMFDData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LMD_Outputs_CVPAMFDData2_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CAM_CS_Curr_Monitor_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCamCsData_CAM_CS_Curr_Monitor_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Svs_CamEepromDataArray_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCamEepromData_Svs_CamEepromDataArray_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Cam_and_Ser_EN_Status_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCamSerENStat_Cam_and_Ser_EN_Status_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CpuLoadMcu2_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CpuLoadMcu2_1_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(JobDLDOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDLDOutput_JobDLDOutput_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Debug_HMI_Curr_Requested_Overlays, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Debug_HMI_Curr_Displayed_Overlays, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Debug_HMI_Curr_Displayed_ProxiConfig, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Debug_HMI_Curr_Requested_ProxiConfig, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Debug_HMI_Input_Data_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebHmiInput_Debug_HMI_Input_Data_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Debug_HMI_Internal_Data_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebHmiInternal_Debug_HMI_Internal_Data_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Debug_HMI_Trailer_Views_Data_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Detection_Inputs_from_TRSC_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDetInpTrsc_Detection_Inputs_from_TRSC_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_DriveAssistStatOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Error_Fault_MCU2_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpErrFltMcu2_0_Error_Fault_MCU2_0_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Error_Fault_MCU2_1_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpErrFltMcu2_1_Error_Fault_MCU2_1_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Error_Fault_MPU1_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpErrFltMpu1_0_Error_Fault_MPU1_0_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_FPAWarnOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpFPAWarnOut_TbAP_FPAWarnOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbTHASmVc_FeatureOutputs_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(IDebug_FODObject_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpIDebugFODObject_IDebug_FODObject_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(IFOD_Outputs_Arbitration_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(IJobUSSObjectMapOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(IJobFPAOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpJobFPAData_IJobFPAOutput_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(IJobPLDOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpJobPLDData_IJobPLDOutput_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(JobTHADetOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpJobTHADetOutput_JobTHADetOutput_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(KeepAliveResponse_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpKeepAliveResponse_KeepAliveResponse_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LMD_Lane_Outputs_s, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpLMDLaneOp_LMD_Lane_Outputs_s; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(NFCD_Output, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpNFCDOutput_NFCD_Output; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbSVS_e_SVSOutputToNVMCamCalibSM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(NVMSignalManager_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpNVMSignMgr_NVMSignalManager_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpPAM2BTIpcTxStatus_IpcTxDone; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_PAStateOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpPAStateOut_TbAP_PAStateOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_PointDistOutputBuff_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpPointDistOpBuff_US_S_PointDistOutputBuff_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_RPAWarnOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpRPAWarnOut_TbAP_RPAWarnOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RunTimeStats_MCU2_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RunTimeStats_MCU2_1_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RunTimeStats_MPU1_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_SMDAInternalOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSMDAInternal_TbAP_SMDAInternalOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SSM_2_0_CoreStatus, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_0; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SSM_2_1_CoreStatus, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SSM_QNX_CoreStatus, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSR_State_QNX_State_QNX; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbSVS_S_SVSCamEOLCalibDataToNVM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbSVS_S_SVSCamOCCalibDataToNVM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbSVS_S_SVSCamSCCalibDataToNVM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SVS_NVMData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSNVMData_SVS_NVMData_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbSVS_e_SVSOutputToDiagMgrCamCalib_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SVSToDiag_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSToDiag_SVSToDiag_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SVStoTRSC_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVStoTRSC_SVStoTRSC_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ErrorMgr_ErrorCommPack_1_0_B, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ErrorMgr_ErrorCommPack_2_0_B, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ErrorMgr_ErrorCommPack_2_1_B, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ErrorMgr_ErrorCommPack_QNX_B, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ErrorMgr_ErrorCommPack_2_0_QM, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ErrorMgr_ErrorCommPack_2_1_QM, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ErrorMgr_ErrorCommPack_QNX_QM, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ScreenRequest_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpScreenRequest_ScreenRequest_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_SnrDirEcho_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSnrDirEcho_US_S_SnrDirEcho_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(StackUsage_MCU2_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(StackUsage_MCU2_1_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SvsToTHA_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSvsToTHA_SvsToTHA_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SvsToVCAN_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSvsToVCAN_SvsToVCAN_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ME_VehOut_TRSC_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTRSC_ME_VehOut_TRSC_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSCSMVCtoDebugCAN_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_DebugOut, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTbAPDebugOut_TbAP_DebugOut; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_SMPAInternalOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbFA_ArbiterOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbFA_ResetKM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTbFAResetKM_TbFA_ResetKM_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbTHASmVc_DiagMgr_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TrailerDetection_Output_DID_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTrailerDetectOP_TrailerDetection_Output_DID_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSCSMVCtoSVS_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSCtoDiagMgr_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTrscToDiag_TRSCtoDiagMgr_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_Inputs_from_TrailerDetection_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_BlockageBit_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUSSBlockageBit_US_S_BlockageBit_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_USSConstantData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUSSConstantData_US_S_USSConstantData_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_USSErrorDiagData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUSSErrorDiagData_US_S_USSErrorDiagData_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_USSPeriodDiagData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_CsmStateChangeReason_Type, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_USSDataCollectionData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssDataCollection_US_S_USSDataCollectionData_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_DebugMsg_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssDebugMsg_US_S_DebugMsg_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_MarriageSensorIDs_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssMrrgData_US_S_MarriageSensorIDs_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_PointMapGroup_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssPointMapGrp_US_S_PointMapGroup_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UssTunningData_mcu2_1_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssTunData_UssTunningData_mcu2_1_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(US_S_ZoneInfo_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssZoneInfo_US_S_ZoneInfo_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_VCActuatorOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpVCActuatorOut_TbAP_VCActuatorOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_VCStateOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpVCState_TbAP_VCStateOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WdgCheckpointStatus_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WdgCheckpointStatus_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WdgCheckpointStatus_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PmicStatus, RTE_VAR_INIT) Rte_CDD_PMIC_PpPMICFaultstatus_Sts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WdgFltSts, RTE_VAR_INIT) Rte_CDD_PMIC_PpWDGFaultStatus_Sts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(MpuFltSts, RTE_VAR_INIT) Rte_CDD_Safety_PpMPUFaultStatus_Sts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Status, RTE_VAR_INIT) Rte_CDD_Safety_PpSDLFaultstatus_Sts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CalDataProvider_MCU_1_0_Def, RTE_VAR_INIT) Rte_CalDataProvider_P_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(BswM_CalDataProSCCalStatus, RTE_VAR_INIT) Rte_CalDataProvider_P_Request_BswM_ScCalStatus_requestedMode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_VrntTunParam_t, RTE_VAR_INIT) Rte_CalDataProvider_PpAPVarTunParam_TbAP_VrntTunParam_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_VAR_INIT) Rte_CalDataProvider_PpPreviousCamData_Data; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DtcAddData_B, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcAddData_B; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DtcStatus_B, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcStatus_B; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ErrorListArr_B, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_Errors_B_Errors_B; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SafeStateOpDef, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_SafeState_SafeStateOp; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_SafeState2Reason_FaultEnum_u16; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ME_Hydra2defs_S_CodingTableExt_t, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiConfigData_ProxiData; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiErrorData_Error; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiReset_ProxiDataflag_b; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PAMConfig_u8; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PRX_CanNod27_b; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Pamtuningset; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Parkwithstop_u8; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Trailerhitchassist_u8; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentCanNMState_FD02_PAM, RTE_VAR_INIT) Rte_CurrentCanNMState_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_b8d48ce4_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CurrentFailSts_FD02_PAM, RTE_VAR_INIT) Rte_CurrentFailSts_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_c3249b61_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DES_FD02_PAM, RTE_VAR_INIT) Rte_DES_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4b879cc8_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_01_PAM, RTE_VAR_INIT) Rte_Digit_01_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_35ebeb6b_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_02_PAM, RTE_VAR_INIT) Rte_Digit_02_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_510b9095_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_03_PAM, RTE_VAR_INIT) Rte_Digit_03_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_c47b4400_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_04_PAM, RTE_VAR_INIT) Rte_Digit_04_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_98cb6769_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_05_PAM, RTE_VAR_INIT) Rte_Digit_05_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_0dbbb3fc_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_06_PAM, RTE_VAR_INIT) Rte_Digit_06_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_695bc802_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_07_PAM, RTE_VAR_INIT) Rte_Digit_07_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_fc2b1c97_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_08_PAM, RTE_VAR_INIT) Rte_Digit_08_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_d03b8ed0_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_09_PAM, RTE_VAR_INIT) Rte_Digit_09_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_454b5a45_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_10_PAM, RTE_VAR_INIT) Rte_Digit_10_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_206b28e1_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Digit_11_PAM, RTE_VAR_INIT) Rte_Digit_11_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_b51bfc74_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EOL_FD02_PAM, RTE_VAR_INIT) Rte_EOL_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ccb11d67_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GenericFailSts_FD02_PAM, RTE_VAR_INIT) Rte_GenericFailSts_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_d914f704_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(N_PDU, RTE_VAR_INIT) Rte_N_PDU_oDIAGNOSTIC_ROE_FD_PAM_oFDCAN2_32bc31eb_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PreviousCanNMState_FD02_PAM, RTE_VAR_INIT) Rte_PreviousCanNMState_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ea522b89_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(StayActiveSource_FD02_PAM, RTE_VAR_INIT) Rte_StayActiveSource_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4ba3a17d_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(THA_EPB_Req, RTE_VAR_INIT) Rte_THA_EPB_Req_oTRSCM_FD_1_oFDCAN2_330530e0_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(THA_STAT, RTE_VAR_INIT) Rte_THA_STAT_oTRSCM_FD_1_oFDCAN2_ae81c3b8_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(THA_SpeedLimit_Req, RTE_VAR_INIT) Rte_THA_SpeedLimit_Req_oTRSCM_FD_1_oFDCAN2_99923097_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(THA_Speed_Limit, RTE_VAR_INIT) Rte_THA_Speed_Limit_oTRSCM_FD_1_oFDCAN2_7015673d_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_THA_SteeringDamping_oTRSCM_FD_1_oFDCAN2_5077858c_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_THA_SteeringTorqueInfo_oTRSCM_FD_1_oFDCAN2_5437f775_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(THA_SteeringTorqueReq, RTE_VAR_INIT) Rte_THA_SteeringTorqueReq_oTRSCM_FD_1_oFDCAN2_d5c7823f_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSCMoreCamRQSts, RTE_VAR_INIT) Rte_TRSCMoreCamRQSts_oTRSCM_FD_1_oFDCAN2_6a0ec540_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_PopupDisp_Info, RTE_VAR_INIT) Rte_TRSC_PopupDisp_Info_oTRSCM_FD_1_oFDCAN2_53c36afe_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_PopupDisp_Info2, RTE_VAR_INIT) Rte_TRSC_PopupDisp_Info2_oTRSCM_FD_1_oFDCAN2_e00c3444_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_STAT, RTE_VAR_INIT) Rte_TRSC_STAT_oTRSCM_FD_1_oFDCAN2_37cfdfd9_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_SpeedLimit_Req, RTE_VAR_INIT) Rte_TRSC_SpeedLimit_Req_oTRSCM_FD_1_oFDCAN2_ab040d8c_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_TRSC_SteeringDamping_oTRSCM_FD_1_oFDCAN2_da20da5d_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_TRSC_SteeringTorqueInfo_oTRSCM_FD_1_oFDCAN2_10502d34_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_SteeringTorqueReq, RTE_VAR_INIT) Rte_TRSC_SteeringTorqueReq_oTRSCM_FD_1_oFDCAN2_b630b053_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_VehicleStop_Req, RTE_VAR_INIT) Rte_TRSC_VehicleStop_Req_oTRSCM_FD_1_oFDCAN2_756072d1_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Trailer_Angle, RTE_VAR_INIT) Rte_Trailer_Angle_oTRSCM_FD_1_oFDCAN2_d1a864a3_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Trailer_Angle_Sign, RTE_VAR_INIT) Rte_Trailer_Angle_Sign_oTRSCM_FD_1_oFDCAN2_2b9f0ec4_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Trailer_Calibration, RTE_VAR_INIT) Rte_Trailer_Calibration_oTRSCM_FD_1_oFDCAN2_30ba6b34_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TrlrHitchLight_Cntrl, RTE_VAR_INIT) Rte_TrlrHitchLight_Cntrl_oTRSCM_FD_1_oFDCAN2_ba4f30d9_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(WakeupSource_FD02_PAM, RTE_VAR_INIT) Rte_WakeupSource_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_13de1caf_Tx_1; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpVariantData_Variant; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(APARequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ASCM_Stat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Brk_Stat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Brk_Stat; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CM_TCH_STAT, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CM_TCH_X_COORD, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CM_TCH_Y_COORD, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CameraDisplaySts2, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(CmdIgnSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DriverDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(EngineSts_W, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EngineSts_W; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ExternalTemperature, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Fwrd_Cam_Guidelines, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(GearEngaged, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ITBM_TrlrStat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ITBM_TrlrStat; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LanguageSelection, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LanguageSelection; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LwsAngle, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngle; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LwsSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsSpeed; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAMRequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PAMRequestSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PamChimeVolumeFront, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeFront; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PamChimeVolumeRear, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeRear; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PsngrDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RHatchSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Rear_Brk_Asst, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Rear_Brk_Asst; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SVC_Guidelines, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_SVC_Guidelines; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ShiftLeverPosition, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TCASERANGESTATUS, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TCASERANGESTATUS; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TGW_CAMERA_DISP_STAT, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TargetGear, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TargetGear; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TrailerConnectionSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(VIN_DATA, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_DATA; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(VIN_MSG, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(VehicleSpeedVSOSig, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_EPS_HandsOnRecognition, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ESS_ENG_ST_W, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHFWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHF_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHF_Spin, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_Spin; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHRWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHR_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LatAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LatAcceleration_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LongAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LongAcceleration_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LwsAngle, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LwsAngleType, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngleType; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_LwsSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsSpeed; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PAM_Brk_Rq_RspSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PdlPosActual, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PdlPosActual; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHFWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHF_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHF_Spin, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_Spin; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHRWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHR_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_SPM_Lat_Ctrl_ResponseSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Steering_Column_Torque, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_VehicleSpeedVSOSig, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_VehicleSpeedVSOSig_B2, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_VehicleStandStillSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_YawRateFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_YawRate_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRate_BSM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_InvalidValueFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_MissingMessageFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_AliveCntr_MCU2_0, RTE_VAR_INIT) Rte_FD14_1_AliveCntr_MCU2_0_oME_SystemDebugData_1_oFDCAN14_e65282c6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_AliveCntr_MCU2_1, RTE_VAR_INIT) Rte_FD14_1_AliveCntr_MCU2_1_oME_SystemDebugData_1_oFDCAN14_1788876c_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_AliveCntr_MPU1_0, RTE_VAR_INIT) Rte_FD14_1_AliveCntr_MPU1_0_oME_SystemDebugData_1_oFDCAN14_0e75683e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_ErrFaultInfo_MCU2_0, RTE_VAR_INIT) Rte_FD14_1_ErrFaultInfo_MCU2_0_oME_SystemDebugData_1_oFDCAN14_09f994d2_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Err_FaultInfo_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Err_FaultInfo_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f3e84bf0_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Err_FaultInfo_MCU2_1, RTE_VAR_INIT) Rte_FD14_1_Err_FaultInfo_MCU2_1_oME_SystemDebugData_1_oFDCAN14_6fb4bd00_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Err_FaultInfo_MPU1_0, RTE_VAR_INIT) Rte_FD14_1_Err_FaultInfo_MPU1_0_oME_SystemDebugData_1_oFDCAN14_76495252_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Err_FaultNum_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Err_FaultNum_MCU1_0_oME_SystemDebugData_1_oFDCAN14_44f26807_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Err_FaultNum_MCU2_0, RTE_VAR_INIT) Rte_FD14_1_Err_FaultNum_MCU2_0_oME_SystemDebugData_1_oFDCAN14_29749b5d_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Err_FaultNum_MCU2_1, RTE_VAR_INIT) Rte_FD14_1_Err_FaultNum_MCU2_1_oME_SystemDebugData_1_oFDCAN14_d8ae9ef7_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Err_FaultNum_MPU1_0, RTE_VAR_INIT) Rte_FD14_1_Err_FaultNum_MPU1_0_oME_SystemDebugData_1_oFDCAN14_c15371a5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Hook_DtErr_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_DtErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d4fc990e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Hook_Error_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_Error_MCU1_0_oME_SystemDebugData_1_oFDCAN14_082f9b06_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Hook_PresentPtr_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_PresentPtr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_46e0c48b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Hook_Reserved_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_4252166b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Hook_Service_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_Service_MCU1_0_oME_SystemDebugData_1_oFDCAN14_443850ea_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Hook_Type_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_Type_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6517d66f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Hook_actTsk_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_actTsk_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e5cab5c_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Hook_fatalErr_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_fatalErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_db1493b6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_ADFSR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_ADFSR_oME_MCUOsDebugData1_oFDCAN14_56600f18_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_AIFSR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_AIFSR_oME_MCUOsDebugData1_oFDCAN14_d7bd5dfe_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_DFAR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_DFAR_oME_MCUOsDebugData1_oFDCAN14_73a0eaa5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_DFSR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_DFSR_oME_MCUOsDebugData1_oFDCAN14_8011b617_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_IFAR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_IFAR_oME_MCUOsDebugData1_oFDCAN14_f27db843_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_IFSR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_IFSR_oME_MCUOsDebugData1_oFDCAN14_01cce4f1_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Link, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Link_oME_MCUOsDebugData1_oFDCAN14_b350e9be_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_SPSR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_SPSR_oME_MCUOsDebugData1_oFDCAN14_8d113eaa_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Stack0, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack0_oME_MCUOsDebugData2_oFDCAN14_def0054e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Stack1, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack1_oME_MCUOsDebugData2_oFDCAN14_e290e646_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Stack2, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack2_oME_MCUOsDebugData2_oFDCAN14_a631c35e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Stack3, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack3_oME_MCUOsDebugData2_oFDCAN14_9a512056_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Stack4, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack4_oME_MCUOsDebugData2_oFDCAN14_2f73896e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Stack5, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack5_oME_MCUOsDebugData2_oFDCAN14_13136a66_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Stack6, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack6_oME_MCUOsDebugData2_oFDCAN14_57b24f7e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Stack7, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack7_oME_MCUOsDebugData2_oFDCAN14_6bd2ac76_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Stack8, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack8_oME_MCUOsDebugData2_oFDCAN14_e6861b4f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_OsRegMCU_Stack9, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack9_oME_MCUOsDebugData2_oFDCAN14_dae6f847_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Reserved_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5ce4f1ef_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Reserved_MCU2_0, RTE_VAR_INIT) Rte_FD14_1_Reserved_MCU2_0_oME_SystemDebugData_1_oFDCAN14_316202b5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Reserved_MCU2_1, RTE_VAR_INIT) Rte_FD14_1_Reserved_MCU2_1_oME_SystemDebugData_1_oFDCAN14_c0b8071f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_Reserved_MPU1_0, RTE_VAR_INIT) Rte_FD14_1_Reserved_MPU1_0_oME_SystemDebugData_1_oFDCAN14_d945e84d_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SDL_Fault_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SDL_Fault_MCU1_0_oME_SystemDebugData_1_oFDCAN14_80e1e586_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData10_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData10_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6272ae84_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData11_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData11_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2cfba52d_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData12_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData12_MCU1_0_oME_SystemDebugData_1_oFDCAN14_ff60b9d6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData13_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData13_MCU1_0_oME_SystemDebugData_1_oFDCAN14_b1e9b27f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData14_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData14_MCU1_0_oME_SystemDebugData_1_oFDCAN14_83278661_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData15_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData15_MCU1_0_oME_SystemDebugData_1_oFDCAN14_cdae8dc8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData16_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData16_MCU1_0_oME_SystemDebugData_1_oFDCAN14_1e359133_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData17_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData17_MCU1_0_oME_SystemDebugData_1_oFDCAN14_50bc9a9a_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData18_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData18_MCU1_0_oME_SystemDebugData_1_oFDCAN14_7ba9f90f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData1_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData1_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e3538b4_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData2_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData2_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5dae244f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData3_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData3_MCU1_0_oME_SystemDebugData_1_oFDCAN14_13272fe6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData4_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData4_MCU1_0_oME_SystemDebugData_1_oFDCAN14_21e91bf8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData5_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData5_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6f601051_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData6_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData6_MCU1_0_oME_SystemDebugData_1_oFDCAN14_bcfb0caa_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData7_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData7_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f2720703_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData8_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData8_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d9676496_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_FltData9_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData9_MCU1_0_oME_SystemDebugData_1_oFDCAN14_97ee6f3f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_SSM_SystemStateReq, RTE_VAR_INIT) Rte_FD14_1_SSM_SystemStateReq_oME_SystemDebugData_1_oFDCAN14_1a98cea3_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_TimeSincePowerON, RTE_VAR_INIT) Rte_FD14_1_TimeSincePowerON_oME_SystemDebugData_1_oFDCAN14_144841c6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_1_WDG_Error_ID_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_WDG_Error_ID_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2488c0c2_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(AUXCamsRQSts, RTE_VAR_INIT) Rte_AUXCamsRQSts_oCVPAM_FD_Info_oFDCAN2_cb5ede6d_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_CHF, RTE_VAR_INIT) Rte_Alert_CHF_oCVPAM_FD_Info_oFDCAN2_10e5899e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_CHR, RTE_VAR_INIT) Rte_Alert_CHR_oCVPAM_FD_Info_oFDCAN2_068868fc_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_LHF, RTE_VAR_INIT) Rte_Alert_LHF_oCVPAM_FD_Info_oFDCAN2_9d0fdf04_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_LHR, RTE_VAR_INIT) Rte_Alert_LHR_oCVPAM_FD_Info_oFDCAN2_8b623e66_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_RHF, RTE_VAR_INIT) Rte_Alert_RHF_oCVPAM_FD_Info_oFDCAN2_5daa7471_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_RHR, RTE_VAR_INIT) Rte_Alert_RHR_oCVPAM_FD_Info_oFDCAN2_4bc79513_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Camera_Status, RTE_VAR_INIT) Rte_Camera_Status_oADAS_FD_LANES_1_oFDCAN2_64f6e4de_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ChimeActivation_LHF, RTE_VAR_INIT) Rte_ChimeActivation_LHF_oCVPAM_FD_Info_oFDCAN2_18ea8591_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ChimeActivation_LHR, RTE_VAR_INIT) Rte_ChimeActivation_LHR_oCVPAM_FD_Info_oFDCAN2_0e8764f3_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ChimeActivation_RHF, RTE_VAR_INIT) Rte_ChimeActivation_RHF_oCVPAM_FD_Info_oFDCAN2_d84f2ee4_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ChimeActivation_RHR, RTE_VAR_INIT) Rte_ChimeActivation_RHR_oCVPAM_FD_Info_oFDCAN2_ce22cf86_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Cntr_ADAS_FD_LANES_1, RTE_VAR_INIT) Rte_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_af11a5df_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Cntr_ADAS_FD_LANES_2, RTE_VAR_INIT) Rte_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_64cb74e2_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DisplayView2, RTE_VAR_INIT) Rte_DisplayView2_oCVPAM_FD_Info_oFDCAN2_73efd9c8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FOD_Confidence, RTE_VAR_INIT) Rte_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN2_998d9b03_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FT_PAM_LedControlSts, RTE_VAR_INIT) Rte_FT_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_767c2572_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Frame_Index_Lanes_1, RTE_VAR_INIT) Rte_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN2_1ad54467_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Frame_Index_Lanes_2, RTE_VAR_INIT) Rte_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN2_d10f955a_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FrontSensorSts, RTE_VAR_INIT) Rte_FrontSensorSts_oCVPAM_FD_Info_oFDCAN2_e08a5c16_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_CHF, RTE_VAR_INIT) Rte_Graphic_CHF_oCVPAM_FD_Info_oFDCAN2_4b6ea313_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_CHR, RTE_VAR_INIT) Rte_Graphic_CHR_oCVPAM_FD_Info_oFDCAN2_5d034271_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_LHF, RTE_VAR_INIT) Rte_Graphic_LHF_oCVPAM_FD_Info_oFDCAN2_c684f589_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_LHR, RTE_VAR_INIT) Rte_Graphic_LHR_oCVPAM_FD_Info_oFDCAN2_d0e914eb_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_RHF, RTE_VAR_INIT) Rte_Graphic_RHF_oCVPAM_FD_Info_oFDCAN2_06215efc_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_RHR, RTE_VAR_INIT) Rte_Graphic_RHR_oCVPAM_FD_Info_oFDCAN2_104cbf9e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(HMICode, RTE_VAR_INIT) Rte_HMICode_oCVPAM_FD_Info_oFDCAN2_5dec6edf_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Health_Front_Object_Detection, RTE_VAR_INIT) Rte_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN2_e8d5db74_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Health_Lane_Detection, RTE_VAR_INIT) Rte_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN2_1cdf1820_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ImageDefeatRQSts, RTE_VAR_INIT) Rte_ImageDefeatRQSts_oCVPAM_FD_Info_oFDCAN2_7d4e09fb_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_1_Confidence, RTE_VAR_INIT) Rte_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN2_2534fe9b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_1_Curvature, RTE_VAR_INIT) Rte_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN2_09082d9e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_1_Curvature_Rate, RTE_VAR_INIT) Rte_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_93fb8a81_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_1_End_Range, RTE_VAR_INIT) Rte_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN2_34dd811a_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_1_Heading, RTE_VAR_INIT) Rte_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN2_3e17383d_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_1_Offset, RTE_VAR_INIT) Rte_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN2_ad232516_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_1_Start_Range, RTE_VAR_INIT) Rte_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN2_293a5620_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_1_Type, RTE_VAR_INIT) Rte_Line_1_Type_oADAS_FD_LANES_1_oFDCAN2_3e24410a_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_2_Confidence, RTE_VAR_INIT) Rte_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN2_7f55c1fb_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_2_Curvature, RTE_VAR_INIT) Rte_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN2_6de85660_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_2_Curvature_Rate, RTE_VAR_INIT) Rte_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_70b23d23_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_2_End_Range, RTE_VAR_INIT) Rte_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN2_503dfae4_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_2_Heading, RTE_VAR_INIT) Rte_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN2_5391cb67_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_2_Offset, RTE_VAR_INIT) Rte_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN2_f6349403_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_2_Start_Range, RTE_VAR_INIT) Rte_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN2_64d25647_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_2_Type, RTE_VAR_INIT) Rte_Line_2_Type_oADAS_FD_LANES_1_oFDCAN2_2d0c7879_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_3_Confidence, RTE_VAR_INIT) Rte_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN2_ffa5d6e4_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_3_Curvature, RTE_VAR_INIT) Rte_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN2_f89882f5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_3_Curvature_Rate, RTE_VAR_INIT) Rte_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_98a5ad82_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_3_End_Range, RTE_VAR_INIT) Rte_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN2_c54d2e71_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_3_Heading, RTE_VAR_INIT) Rte_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN2_77139a51_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_3_Offset, RTE_VAR_INIT) Rte_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN2_c0c604f0_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_3_Start_Range, RTE_VAR_INIT) Rte_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN2_e95aaba5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_3_Type, RTE_VAR_INIT) Rte_Line_3_Type_oADAS_FD_LANES_1_oFDCAN2_23eb90a8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_4_Confidence, RTE_VAR_INIT) Rte_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN2_cb97bf3b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_4_Curvature, RTE_VAR_INIT) Rte_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN2_a428a19c_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_4_Curvature_Rate, RTE_VAR_INIT) Rte_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_6d505426_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_4_End_Range, RTE_VAR_INIT) Rte_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN2_99fd0d18_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_4_Heading, RTE_VAR_INIT) Rte_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN2_889c2dd3_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_4_Offset, RTE_VAR_INIT) Rte_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN2_401bf629_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_4_Start_Range, RTE_VAR_INIT) Rte_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN2_ff025689_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Line_4_Type, RTE_VAR_INIT) Rte_Line_4_Type_oADAS_FD_LANES_1_oFDCAN2_0b5c0a9f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(MAC_ADAS_FD_LANES_1, RTE_VAR_INIT) Rte_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_9c565bdf_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(MAC_ADAS_FD_LANES_2, RTE_VAR_INIT) Rte_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_578c8ae2_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(MoreCamsRQSts, RTE_VAR_INIT) Rte_MoreCamsRQSts_oCVPAM_FD_Info_oFDCAN2_ba84adf5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAMSystemFault, RTE_VAR_INIT) Rte_PAMSystemFault_oCVPAM_FD_Info_oFDCAN2_eab32332_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_CHIME_REP_RATESts, RTE_VAR_INIT) Rte_PAM_CHIME_REP_RATESts_oCVPAM_FD_Info_oFDCAN2_ec85c7c5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_CHIME_TYPE, RTE_VAR_INIT) Rte_PAM_CHIME_TYPE_oCVPAM_FD_Info_oFDCAN2_0558f070_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_LedControlSts, RTE_VAR_INIT) Rte_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_63c5d79e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_Off_Status, RTE_VAR_INIT) Rte_PAM_Off_Status_oCVPAM_FD_Info_oFDCAN2_796d8062_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_Off_Status_2BT, RTE_VAR_INIT) Rte_PAM_Off_Status_2BT_oCVPAM_FD_Info_oFDCAN2_514378c1_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_PopUpRqst, RTE_VAR_INIT) Rte_PAM_PopUpRqst_oCVPAM_FD_Info_oFDCAN2_657f86c2_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_Volume, RTE_VAR_INIT) Rte_PAM_Volume_oCVPAM_FD_Info_oFDCAN2_4f8f6792_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PPPA_TurnIndicatorRqst, RTE_VAR_INIT) Rte_PPPA_TurnIndicatorRqst_oCVPAM_FD_Control_oFDCAN2_507419a7_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ParkingManeuverActive, RTE_VAR_INIT) Rte_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN2_ad1c7c90_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN2_92ae92ff_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RR_PAM_Dist, RTE_VAR_INIT) Rte_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN2_48ca8ca5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RR_PAM_StopControlSts, RTE_VAR_INIT) Rte_RR_PAM_StopControlSts_oCVPAM_FD_Control_oFDCAN2_2f143404_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RearSensorSts, RTE_VAR_INIT) Rte_RearSensorSts_oCVPAM_FD_Info_oFDCAN2_a2ccce85_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Reserved_for_functional_safety, RTE_VAR_INIT) Rte_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN2_82a794a5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SPMControlSts, RTE_VAR_INIT) Rte_SPMControlSts_oCVPAM_FD_Info_oFDCAN2_a3ff073d_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SPMFailSts, RTE_VAR_INIT) Rte_SPMFailSts_oCVPAM_FD_Info_oFDCAN2_85d98ec8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SPMSystemFault, RTE_VAR_INIT) Rte_SPMSystemFault_oCVPAM_FD_Info_oFDCAN2_c4e3aa9b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SPM_LedControlSts, RTE_VAR_INIT) Rte_SPM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_3446c3a9_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SPM_Screen_Rqst, RTE_VAR_INIT) Rte_SPM_Screen_Rqst_oCVPAM_FD_Info_oFDCAN2_4e673fb0_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_1_Confidence, RTE_VAR_INIT) Rte_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN2_d5c06647_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_1_ID, RTE_VAR_INIT) Rte_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN2_124eba08_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_1_X1, RTE_VAR_INIT) Rte_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN2_0e62b6bf_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_1_X2, RTE_VAR_INIT) Rte_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN2_fc355b47_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_1_Y1, RTE_VAR_INIT) Rte_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN2_60eeadfe_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_1_Y2, RTE_VAR_INIT) Rte_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN2_92b94006_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_2_Confidence, RTE_VAR_INIT) Rte_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN2_8fa15927_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_2_ID, RTE_VAR_INIT) Rte_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN2_b746d164_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_2_X1, RTE_VAR_INIT) Rte_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN2_ab6addd3_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_2_X2, RTE_VAR_INIT) Rte_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN2_593d302b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_2_Y1, RTE_VAR_INIT) Rte_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN2_c5e6c692_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_2_Y2, RTE_VAR_INIT) Rte_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN2_37b12b6a_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_3_Confidence, RTE_VAR_INIT) Rte_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN2_0f514e38_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_3_ID, RTE_VAR_INIT) Rte_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN2_d4410840_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_3_X1, RTE_VAR_INIT) Rte_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN2_c86d04f7_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_3_X2, RTE_VAR_INIT) Rte_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN2_3a3ae90f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_3_Y1, RTE_VAR_INIT) Rte_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN2_a6e11fb6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_3_Y2, RTE_VAR_INIT) Rte_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN2_54b6f24e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_4_Confidence, RTE_VAR_INIT) Rte_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN2_3b6327e7_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_4_ID, RTE_VAR_INIT) Rte_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN2_262701fd_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_4_X1, RTE_VAR_INIT) Rte_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN2_3a0b0d4a_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_4_X2, RTE_VAR_INIT) Rte_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN2_c85ce0b2_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_4_Y1, RTE_VAR_INIT) Rte_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN2_5487160b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_4_Y2, RTE_VAR_INIT) Rte_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN2_a6d0fbf3_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_5_Confidence, RTE_VAR_INIT) Rte_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN2_bb9330f8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_5_ID, RTE_VAR_INIT) Rte_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN2_4520d8d9_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_5_X1, RTE_VAR_INIT) Rte_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN2_590cd46e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_5_X2, RTE_VAR_INIT) Rte_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN2_ab5b3996_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_5_Y1, RTE_VAR_INIT) Rte_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN2_3780cf2f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_5_Y2, RTE_VAR_INIT) Rte_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN2_c5d722d7_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_6_Confidence, RTE_VAR_INIT) Rte_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN2_e1f20f98_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_6_ID, RTE_VAR_INIT) Rte_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN2_e028b3b5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_6_X1, RTE_VAR_INIT) Rte_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN2_fc04bf02_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_6_X2, RTE_VAR_INIT) Rte_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN2_0e5352fa_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_6_Y1, RTE_VAR_INIT) Rte_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN2_9288a443_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_6_Y2, RTE_VAR_INIT) Rte_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN2_60df49bb_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_7_Confidence, RTE_VAR_INIT) Rte_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN2_61021887_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_7_ID, RTE_VAR_INIT) Rte_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN2_832f6a91_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_7_X1, RTE_VAR_INIT) Rte_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN2_9f036626_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_7_X2, RTE_VAR_INIT) Rte_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN2_6d548bde_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_7_Y1, RTE_VAR_INIT) Rte_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN2_f18f7d67_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_7_Y2, RTE_VAR_INIT) Rte_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN2_03d8909f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_8_Confidence, RTE_VAR_INIT) Rte_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN2_8996dc26_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_8_ID, RTE_VAR_INIT) Rte_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN2_df95a68e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_8_X1, RTE_VAR_INIT) Rte_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN2_c3b9aa39_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_8_X2, RTE_VAR_INIT) Rte_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN2_31ee47c1_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_8_Y1, RTE_VAR_INIT) Rte_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN2_ad35b178_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Segment_8_Y2, RTE_VAR_INIT) Rte_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN2_5f625c80_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TRSC_LED_Stat, RTE_VAR_INIT) Rte_TRSC_LED_Stat_oCVPAM_FD_Info_oFDCAN2_546afbba_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Camera_Status, RTE_VAR_INIT) Rte_FD14_Camera_Status_oADAS_FD_LANES_1_oFDCAN14_02ee5263_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Cntr_ADAS_FD_LANES_1, RTE_VAR_INIT) Rte_FD14_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_83e8745c_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Cntr_ADAS_FD_LANES_2, RTE_VAR_INIT) Rte_FD14_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_db4be29c_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_FOD_Confidence, RTE_VAR_INIT) Rte_FD14_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN14_07d950b0_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Frame_Index_Lanes_1, RTE_VAR_INIT) Rte_FD14_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN14_09d47624_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Frame_Index_Lanes_2, RTE_VAR_INIT) Rte_FD14_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN14_5177e0e4_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Health_Front_Object_Detection, RTE_VAR_INIT) Rte_FD14_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN14_67ae32c5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Health_Lane_Detection, RTE_VAR_INIT) Rte_FD14_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN14_0b1cd3fa_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_1_Confidence, RTE_VAR_INIT) Rte_FD14_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN14_3d68d9cb_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_1_Curvature, RTE_VAR_INIT) Rte_FD14_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN14_cc3e3dc3_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_1_Curvature_Rate, RTE_VAR_INIT) Rte_FD14_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_aa426416_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_1_End_Range, RTE_VAR_INIT) Rte_FD14_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN14_26d6af56_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_1_Heading, RTE_VAR_INIT) Rte_FD14_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN14_c61fd7b8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_1_Offset, RTE_VAR_INIT) Rte_FD14_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN14_9798cd20_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_1_Start_Range, RTE_VAR_INIT) Rte_FD14_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN14_0d5038a6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_1_Type, RTE_VAR_INIT) Rte_FD14_Line_1_Type_oADAS_FD_LANES_1_oFDCAN14_dd59b9e0_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_2_Confidence, RTE_VAR_INIT) Rte_FD14_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN14_7080d9ac_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_2_Curvature, RTE_VAR_INIT) Rte_FD14_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN14_965f02a3_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_2_Curvature_Rate, RTE_VAR_INIT) Rte_FD14_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_9279ef65_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_2_End_Range, RTE_VAR_INIT) Rte_FD14_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN14_7cb79036_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_2_Heading, RTE_VAR_INIT) Rte_FD14_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN14_4dcce9a1_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_2_Offset, RTE_VAR_INIT) Rte_FD14_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN14_fa1e3e7a_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_2_Start_Range, RTE_VAR_INIT) Rte_FD14_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN14_decb245d_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_2_Type, RTE_VAR_INIT) Rte_FD14_Line_2_Type_oADAS_FD_LANES_1_oFDCAN14_1446b15f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_3_Confidence, RTE_VAR_INIT) Rte_FD14_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN14_fd08244e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_3_Curvature, RTE_VAR_INIT) Rte_FD14_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN14_16af15bc_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_3_Curvature_Rate, RTE_VAR_INIT) Rte_FD14_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_33406b8b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_3_End_Range, RTE_VAR_INIT) Rte_FD14_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN14_fc478729_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_3_Heading, RTE_VAR_INIT) Rte_FD14_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN14_8252fe69_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_3_Offset, RTE_VAR_INIT) Rte_FD14_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN14_de9c6f4c_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_3_Start_Range, RTE_VAR_INIT) Rte_FD14_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN14_90422ff4_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_3_Type, RTE_VAR_INIT) Rte_FD14_Line_3_Type_oADAS_FD_LANES_1_oFDCAN14_e59cb4f5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_4_Confidence, RTE_VAR_INIT) Rte_FD14_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN14_eb50d962_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_4_Curvature, RTE_VAR_INIT) Rte_FD14_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN14_229d7c63_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_4_Curvature_Rate, RTE_VAR_INIT) Rte_FD14_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_e20ef983_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_4_End_Range, RTE_VAR_INIT) Rte_FD14_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN14_c875eef6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_4_Heading, RTE_VAR_INIT) Rte_FD14_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN14_811b93d2_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_4_Offset, RTE_VAR_INIT) Rte_FD14_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN14_2113d8ce_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_4_Start_Range, RTE_VAR_INIT) Rte_FD14_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN14_a28c1bea_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Line_4_Type, RTE_VAR_INIT) Rte_FD14_Line_4_Type_oADAS_FD_LANES_1_oFDCAN14_5d09a660_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_MAC_ADAS_FD_LANES_1, RTE_VAR_INIT) Rte_FD14_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_cce8ce85_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_MAC_ADAS_FD_LANES_2, RTE_VAR_INIT) Rte_FD14_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_944b5845_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ManoeuvrePhase, RTE_VAR_INIT) Rte_FD14_ManoeuvrePhase_oCVPAM_FD_Control_oFDCAN14_6f7ff602_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_AccelMax, RTE_VAR_INIT) Rte_FD14_PPPA_AccelMax_oCVPAM_FD_Control_oFDCAN14_c98fde99_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_AccelMin, RTE_VAR_INIT) Rte_FD14_PPPA_AccelMin_oCVPAM_FD_Control_oFDCAN14_79b0c4a5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_DecelMax, RTE_VAR_INIT) Rte_FD14_PPPA_DecelMax_oCVPAM_FD_Control_oFDCAN14_55867c47_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_DecelMin, RTE_VAR_INIT) Rte_FD14_PPPA_DecelMin_oCVPAM_FD_Control_oFDCAN14_e5b9667b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_Interface_BSM, RTE_VAR_INIT) Rte_FD14_PPPA_Interface_BSM_oCVPAM_FD_Control_oFDCAN14_5d761341_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_JerkAccelMax, RTE_VAR_INIT) Rte_FD14_PPPA_JerkAccelMax_oCVPAM_FD_Control_oFDCAN14_05f086d0_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_JerkAccelMin, RTE_VAR_INIT) Rte_FD14_PPPA_JerkAccelMin_oCVPAM_FD_Control_oFDCAN14_b5cf9cec_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_JerkDecelMax, RTE_VAR_INIT) Rte_FD14_PPPA_JerkDecelMax_oCVPAM_FD_Control_oFDCAN14_99f9240e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_JerkDecelMin, RTE_VAR_INIT) Rte_FD14_PPPA_JerkDecelMin_oCVPAM_FD_Control_oFDCAN14_29c63e32_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_MaxSpeed, RTE_VAR_INIT) Rte_FD14_PPPA_MaxSpeed_oCVPAM_FD_Control_oFDCAN14_7ef0b86c_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_StandstillRqst, RTE_VAR_INIT) Rte_FD14_PPPA_StandstillRqst_oCVPAM_FD_Control_oFDCAN14_cc940d9b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_PPPA_TargetDistance, RTE_VAR_INIT) Rte_FD14_PPPA_TargetDistance_oCVPAM_FD_Control_oFDCAN14_3437c295_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ParkingGearShiftReq, RTE_VAR_INIT) Rte_FD14_ParkingGearShiftReq_oCVPAM_FD_Control_oFDCAN14_47412e73_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ParkingManeuverActive, RTE_VAR_INIT) Rte_FD14_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN14_2abad8a3_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_FD14_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN14_7700e6e6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RR_PAM_Dist, RTE_VAR_INIT) Rte_FD14_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN14_0f3b79a5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Reserved_for_functional_safety, RTE_VAR_INIT) Rte_FD14_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN14_e529cfa2_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_SPM_Lat_Ctrl_RequestSts, RTE_VAR_INIT) Rte_FD14_SPM_Lat_Ctrl_RequestSts_oCVPAM_FD_Control_oFDCAN14_6d94d6ac_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_1_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN14_7d46bee9_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_1_ID, RTE_VAR_INIT) Rte_FD14_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN14_a70622c6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_1_X1, RTE_VAR_INIT) Rte_FD14_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN14_f21f28e5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_1_X2, RTE_VAR_INIT) Rte_FD14_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN14_418b0526_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_1_Y1, RTE_VAR_INIT) Rte_FD14_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN14_f3aad5f8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_1_Y2, RTE_VAR_INIT) Rte_FD14_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN14_403ef83b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_2_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN14_30aebe8e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_2_ID, RTE_VAR_INIT) Rte_FD14_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN14_e3a707de_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_2_X1, RTE_VAR_INIT) Rte_FD14_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN14_b6be0dfd_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_2_X2, RTE_VAR_INIT) Rte_FD14_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN14_052a203e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_2_Y1, RTE_VAR_INIT) Rte_FD14_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN14_b70bf0e0_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_2_Y2, RTE_VAR_INIT) Rte_FD14_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN14_049fdd23_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_3_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN14_bd26436c_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_3_ID, RTE_VAR_INIT) Rte_FD14_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN14_dfc7e4d6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_3_X1, RTE_VAR_INIT) Rte_FD14_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN14_8adeeef5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_3_X2, RTE_VAR_INIT) Rte_FD14_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN14_394ac336_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_3_Y1, RTE_VAR_INIT) Rte_FD14_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN14_8b6b13e8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_3_Y2, RTE_VAR_INIT) Rte_FD14_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN14_38ff3e2b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_4_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN14_ab7ebe40_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_4_ID, RTE_VAR_INIT) Rte_FD14_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN14_6ae54dee_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_4_X1, RTE_VAR_INIT) Rte_FD14_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN14_3ffc47cd_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_4_X2, RTE_VAR_INIT) Rte_FD14_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN14_8c686a0e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_4_Y1, RTE_VAR_INIT) Rte_FD14_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN14_3e49bad0_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_4_Y2, RTE_VAR_INIT) Rte_FD14_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN14_8ddd9713_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_5_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN14_26f643a2_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_5_ID, RTE_VAR_INIT) Rte_FD14_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN14_5685aee6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_5_X1, RTE_VAR_INIT) Rte_FD14_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN14_039ca4c5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_5_X2, RTE_VAR_INIT) Rte_FD14_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN14_b0088906_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_5_Y1, RTE_VAR_INIT) Rte_FD14_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN14_022959d8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_5_Y2, RTE_VAR_INIT) Rte_FD14_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN14_b1bd741b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_6_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN14_6b1e43c5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_6_ID, RTE_VAR_INIT) Rte_FD14_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN14_12248bfe_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_6_X1, RTE_VAR_INIT) Rte_FD14_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN14_473d81dd_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_6_X2, RTE_VAR_INIT) Rte_FD14_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN14_f4a9ac1e_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_6_Y1, RTE_VAR_INIT) Rte_FD14_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN14_46887cc0_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_6_Y2, RTE_VAR_INIT) Rte_FD14_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN14_f51c5103_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_7_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN14_e696be27_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_7_ID, RTE_VAR_INIT) Rte_FD14_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN14_2e4468f6_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_7_X1, RTE_VAR_INIT) Rte_FD14_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN14_7b5d62d5_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_7_X2, RTE_VAR_INIT) Rte_FD14_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN14_c8c94f16_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_7_Y1, RTE_VAR_INIT) Rte_FD14_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN14_7ae89fc8_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_7_Y2, RTE_VAR_INIT) Rte_FD14_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN14_c97cb20b_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_8_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN14_47afb99d_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_8_ID, RTE_VAR_INIT) Rte_FD14_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN14_a310dfcf_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_8_X1, RTE_VAR_INIT) Rte_FD14_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN14_f609d5ec_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_8_X2, RTE_VAR_INIT) Rte_FD14_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN14_459df82f_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_8_Y1, RTE_VAR_INIT) Rte_FD14_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN14_f7bc28f1_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_Segment_8_Y2, RTE_VAR_INIT) Rte_FD14_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN14_44280532_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_TorqueOverlaySteeringReq_SPM, RTE_VAR_INIT) Rte_FD14_TorqueOverlaySteeringReq_SPM_oCVPAM_FD_Control_oFDCAN14_593889ae_Tx; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_CHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHF; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_CHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHR; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHF; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHR; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHF; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Alert_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHR; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ChimeActivation_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHF; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ChimeActivation_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHR; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ChimeActivation_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHF; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ChimeActivation_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHR; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(DisplayView2, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FrontSensorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FrontSensorSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_CHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHF; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_CHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHR; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHF; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHR; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHF; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Graphic_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHR; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(HMICode, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_HMICode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ImageDefeatRQSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ImageDefeatRQSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAMSystemFault, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAMSystemFault; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_CHIME_REP_RATESts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_CHIME_TYPE, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_LedControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_LedControlSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_Off_Status, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_PopUpRqst, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_PopUpRqst; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(PAM_Volume, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Volume; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(ParkingManeuverActive, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ParkingManeuverActive; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RR_PAM_Dist, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Dist; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RR_PAM_StopControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RearSensorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RearSensorSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SPMControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMControlSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SPMFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMFailSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SPMSystemFault, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMSystemFault; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SPM_LedControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_LedControlSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SPM_Screen_Rqst, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_Screen_Rqst; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_ManoeuvrePhase, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_RR_PAM_Dist, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_SPM_Lat_Ctrl_RequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(FD14_TorqueOverlaySteeringReq_SPM, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(IFOD_Outputs_CVPAMFDData_t, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(LMD_Outputs_CVPAMFDData2_t, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_PAStateOut_t, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeGuardPAStateOut_TbAP_PAStateOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SvsToVCAN_t, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeGuardSvsToVCAN_SvsToVCAN_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(TbAP_VCActuatorOut_t, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeState2RSTReason_FaultEnum_u16; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* TxUpdateFlags for ComSendSignalProxy without IOCs */

typedef struct
{
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentCanNMState_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentFailSts_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_DES_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_GenericFailSts_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_N_PDU;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_PreviousCanNMState_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_StayActiveSource_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_EPB_Req;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_STAT;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SpeedLimit_Req;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_Speed_Limit;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringDamping;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueInfo;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueReq;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSCMoreCamRQSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info2;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_STAT;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SpeedLimit_Req;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringDamping;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueInfo;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueReq;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_VehicleStop_Req;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle_Sign;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Calibration;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TrlrHitchLight_Cntrl;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_WakeupSource_FD02_PAM;
} Rte_OsApplication_QM_TxUpdateFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_OsApplication_QM_TxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_QM_TxUpdateFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* TxUpdateFlags for ComSendSignalProxy without IOCs */

typedef struct
{
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentCanNMState_FD02_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentFailSts_FD02_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_DES_FD02_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_GenericFailSts_FD02_PAM;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_N_PDU;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_PreviousCanNMState_FD02_PAM;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_StayActiveSource_FD02_PAM;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_EPB_Req;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_STAT;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SpeedLimit_Req;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_Speed_Limit;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringDamping;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueInfo;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueReq;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSCMoreCamRQSts;
  uint8 Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info2;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_STAT;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SpeedLimit_Req;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringDamping;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueInfo;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueReq;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_VehicleStop_Req;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle_Sign;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Calibration;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TrlrHitchLight_Cntrl;
  uint8 Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_WakeupSource_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentCanNMState_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentFailSts_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_DES_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_GenericFailSts_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_N_PDU;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_PreviousCanNMState_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_StayActiveSource_FD02_PAM;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_EPB_Req;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_STAT;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SpeedLimit_Req;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_Speed_Limit;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringDamping;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueInfo;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueReq;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSCMoreCamRQSts;
  uint8 Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info2;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_STAT;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SpeedLimit_Req;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringDamping;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueInfo;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueReq;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_VehicleStop_Req;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle_Sign;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Calibration;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TrlrHitchLight_Cntrl;
  uint8 Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_WakeupSource_FD02_PAM;
} Rte_OsApplication_Safety_TxUpdateFlagsType;

#  define RTE_START_SEC_VAR_OsApplication_Safety_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_OsApplication_Safety_TxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Safety_TxUpdateFlags;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


typedef struct
{
  uint8 Rte_ModeSwitchAck_BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode_Ack;
  uint8 Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack;
} Rte_OsApplication_QM_AckFlagsType;

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_OsApplication_QM_AckFlagsType, RTE_VAR_INIT) Rte_OsApplication_QM_AckFlags;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Buffer for inter-runnable variables
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_OsApplication_QM_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(ChangeSYSState_t, RTE_VAR_INIT) Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_INIT) Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */

#  define RTE_STOP_SEC_VAR_OsApplication_QM_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * RTE internal IOC replacement
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_OsApplication_QM_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode_Queue[1];

#  define RTE_STOP_SEC_VAR_OsApplication_QM_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_QM_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_QM_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_QM_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_M_BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode_head;

#  define RTE_STOP_SEC_VAR_OsApplication_QM_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_QM_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_NOINIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[1];

#  define RTE_STOP_SEC_VAR_OsApplication_QM_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_QM_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_QM_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_QM_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head;

#  define RTE_STOP_SEC_VAR_OsApplication_QM_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#  define RTE_START_SEC_CONST_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, RTE_CONST) Rte_ModeTransitionEventId_Dcm_DcmEcuReset_DcmEcuReset[7][7];

#  define RTE_STOP_SEC_CONST_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_BswMSwitchPort_BswmToSysNmIndication_Mode;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(BswM_ESH_Mode, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_SSM_BSW_SystemState_Mode;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_CDD_GenericBswM_PpDiagRequestNtfy_SYSModeRequestType;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_CDD_GenericBswM_PpCmdIgnitionStatus_Current_CmdIgnition;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dcm_EcuResetType, RTE_VAR_INIT) Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_SWC_RIDMgr_PpModeProgPreconditionCheck_ModeProgPreconditionCheck;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_SWC_SafeVCANRx_PpMode_VehicleSpeedCheck_Mode;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_Safety_Guard_SafetyGuard_SafeState_Mode_Mode;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Rte Internal Events for OsApplication_QM
 *********************************************************************************************************************/
typedef struct
{
  uint8 Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run1_CDD_GenericBswM_RE_UpdateNMState;
  uint8 Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run2_CDD_GenericBswM_RE_UpdateNMState;
  uint8 Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run3_CDD_GenericBswM_RE_UpdateNMState;
  uint8 Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run4_CDD_GenericBswM_RE_UpdateNMState;
  uint8 Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run5_CDD_GenericBswM_RE_UpdateNMState;
  uint8 Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run6_CDD_GenericBswM_RE_UpdateNMState;
  uint8 Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_HARDResetReq;
  uint8 Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_JumpToBootReq;
  uint8 Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_SWC_DTCMgr_RE_DTCMgr_EtROEMessage;
} Rte_OsApplication_QM_InternalEventFlagsType;

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_OsApplication_QM_InternalEventFlagsType, RTE_VAR_INIT) Rte_OsApplication_QM_InternalEventFlags;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

 /* PRQA S 0791 L1 */ /* MD_Rte_0791 */
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Is_Rte_Ev_Run1_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run1_CDD_GenericBswM_RE_UpdateNMState)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Set_Rte_Ev_Run1_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run1_CDD_GenericBswM_RE_UpdateNMState = 1U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Reset_Rte_Ev_Run1_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run1_CDD_GenericBswM_RE_UpdateNMState = 0U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Is_Rte_Ev_Run2_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run2_CDD_GenericBswM_RE_UpdateNMState)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Set_Rte_Ev_Run2_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run2_CDD_GenericBswM_RE_UpdateNMState = 1U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Reset_Rte_Ev_Run2_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run2_CDD_GenericBswM_RE_UpdateNMState = 0U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Is_Rte_Ev_Run3_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run3_CDD_GenericBswM_RE_UpdateNMState)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Set_Rte_Ev_Run3_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run3_CDD_GenericBswM_RE_UpdateNMState = 1U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Reset_Rte_Ev_Run3_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run3_CDD_GenericBswM_RE_UpdateNMState = 0U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Is_Rte_Ev_Run4_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run4_CDD_GenericBswM_RE_UpdateNMState)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Set_Rte_Ev_Run4_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run4_CDD_GenericBswM_RE_UpdateNMState = 1U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Reset_Rte_Ev_Run4_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run4_CDD_GenericBswM_RE_UpdateNMState = 0U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Is_Rte_Ev_Run5_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run5_CDD_GenericBswM_RE_UpdateNMState)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Set_Rte_Ev_Run5_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run5_CDD_GenericBswM_RE_UpdateNMState = 1U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Reset_Rte_Ev_Run5_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run5_CDD_GenericBswM_RE_UpdateNMState = 0U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Is_Rte_Ev_Run6_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run6_CDD_GenericBswM_RE_UpdateNMState)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Set_Rte_Ev_Run6_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run6_CDD_GenericBswM_RE_UpdateNMState = 1U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Reset_Rte_Ev_Run6_CDD_GenericBswM_RE_UpdateNMState() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run6_CDD_GenericBswM_RE_UpdateNMState = 0U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Is_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_HARDResetReq() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_HARDResetReq)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Set_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_HARDResetReq() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_HARDResetReq = 1U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Reset_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_HARDResetReq() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_HARDResetReq = 0U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Is_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_JumpToBootReq() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_JumpToBootReq)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Set_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_JumpToBootReq() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_JumpToBootReq = 1U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Reset_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_JumpToBootReq() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_CDD_GenericBswM_RE_GenericBswM_JumpToBootReq = 0U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Is_Rte_Ev_Run_SWC_DTCMgr_RE_DTCMgr_EtROEMessage() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_SWC_DTCMgr_RE_DTCMgr_EtROEMessage)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Set_Rte_Ev_Run_SWC_DTCMgr_RE_DTCMgr_EtROEMessage() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_SWC_DTCMgr_RE_DTCMgr_EtROEMessage = 1U)
#  define Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Reset_Rte_Ev_Run_SWC_DTCMgr_RE_DTCMgr_EtROEMessage() (Rte_OsApplication_QM_InternalEventFlags.Rte_InternalEventFlag_OsApplication_QM_Rte_Ev_Run_SWC_DTCMgr_RE_DTCMgr_EtROEMessage = 0U)
/* PRQA L:L1 */

# endif /* defined(RTE_CORE) */

/**********************************************************************************************************************
 * extern declaration of RTE Update Flags for optimized macro implementation
 *********************************************************************************************************************/
typedef struct
{
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp_Sender;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W_Sender;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_BSM_THA_Brk_Resp;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_BSM_THA_Brk_Resp_Sender;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_EPBSts;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_EPBSts_Sender;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_SBR1RowDriverSeatSts;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_SBR1RowDriverSeatSts_Sender;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_CenterBtn_Sts;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_CenterBtn_Sts_Sender;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_EnableBtn_Sts;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_EnableBtn_Sts_Sender;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_RawKnob;
  uint8 Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_RawKnob_Sender;
} Rte_OsApplication_QM_RxUpdateFlagsType;

typedef struct
{
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp;
  uint8 Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W;
} Rte_OsApplication_Safety_RxUpdateFlagsType;

# define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_OsApplication_QM_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_QM_RxUpdateFlags;

# define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define RTE_START_SEC_VAR_OsApplication_Safety_ZERO_INIT_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_OsApplication_Safety_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Safety_RxUpdateFlags;

# define RTE_STOP_SEC_VAR_OsApplication_Safety_ZERO_INIT_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* RTE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_0791:  MISRA rule: -
     Reason:     Rte names are derived from the configuration.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_1039:  MISRA rule: Rule1.2
     Reason:     Same macro and function names are required to meet AUTOSAR spec.
     Risk:       No functional risk. Macro will be undefined before function definition.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
