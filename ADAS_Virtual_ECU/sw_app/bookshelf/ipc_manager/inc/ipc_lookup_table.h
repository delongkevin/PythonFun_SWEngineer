/**
 * @file ipc_lookup_table.h
 * @brief Maintains look up table
 *
 * @details This file maintains look up table using which Destination Core or
 *          Destination software module can be identified in association with
 *          Message ID
 *
 * --------------------------------------------------------------------------
 * @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *
 *   This is an unpublished work of authorship, which contains
 *   trade secrets, created in 2021. Magna Electronics owns all
 *   rights to this work and intends to maintain it in confidence
 *   to preserve its trade secret status. Magna Electronics
 *   reserves the right, under the copyright laws of the United
 *   States or those of any other country that may have jurisdiction,
 *   to protect this work as an unpublished work, in the event of
 *   an inadvertent or deliberate unauthorized publication.
 *   Magna Electronics also reserves its rights under all copyright
 *   laws to protect this work as a published work, when appropriate.
 *   Those having access to this work may not copy it, use it,
 *   modify it, or disclose the information contained in it without
 *   the written authorization of Magna Electronics.
 *
 * --------------------------------------------------------------------------
 * @author ---- (---- @magna.com)
 */

#ifndef IPC_LOOKUP_TABLE_H_
#define IPC_LOOKUP_TABLE_H_
/* ===========================================================================
 *
 *   Include Files
 *
 * ======================================================================== */

#include <stdio.h>
#include <stdint.h>
/* ===========================================================================
 *
 *   Defines
 *
 * ======================================================================== */
/* Number of Message ID configured to transmit and receive */
#if defined(BUILD_MPU1_0)
#define D_NUMBER_OF_TX_MESSAGES            (31U)  /* IPC lookup table size for TX */
#define D_NUMBER_OF_RX_MESSAGES            (29U)  /* IPC lookup table size for RX */
#endif

#if defined(BUILD_MCU1_0)
#define D_NUMBER_OF_TX_MESSAGES            (39U)  /* IPC lookup table size for TX */
#define D_NUMBER_OF_RX_MESSAGES            (85U)  /* IPC lookup table size for RX */
#endif

#if defined(BUILD_MCU2_0)
#define D_NUMBER_OF_TX_MESSAGES            (26U)  /* IPC lookup table size for TX */
#define D_NUMBER_OF_RX_MESSAGES            (34U)  /* IPC lookup table size for RX */
#endif

#if defined(BUILD_MCU2_1)
#define D_NUMBER_OF_TX_MESSAGES            (57U)  /* IPC lookup table size for TX */
#define D_NUMBER_OF_RX_MESSAGES            (41U)  /* IPC lookup table size for RX */
#endif

#if defined(BUILD_MCU3_0)
#define D_NUMBER_OF_TX_MESSAGES            (0U)   /* IPC lookup table size for TX */
#define D_NUMBER_OF_RX_MESSAGES            (0U)   /* IPC lookup table size for RX */
#endif

#if defined(BUILD_MCU3_1)
#define D_NUMBER_OF_TX_MESSAGES            (0U)   /* IPC lookup table size for TX */
#define D_NUMBER_OF_RX_MESSAGES            (0U)   /* IPC lookup table size for RX */
#endif

#if defined(BUILD_C66x_1)
#define D_NUMBER_OF_TX_MESSAGES            (0U)   /* IPC lookup table size for TX */
#define D_NUMBER_OF_RX_MESSAGES            (0U)   /* IPC lookup table size for RX */
#endif

#if defined(BUILD_C66x_2)
#define D_NUMBER_OF_TX_MESSAGES            (0U)   /* IPC lookup table size for TX */
#define D_NUMBER_OF_RX_MESSAGES            (0U)   /* IPC lookup table size for RX */
#endif

/* ===========================================================================
 *
 *   Global Data Types
 *
 * ======================================================================== */
/* enum for IPC message Ids */
typedef enum IpcMsgId_e
{
    e_IpcMsgId_data_UnknownMsg_t                                               ,    /* 0x0000 */
    e_IpcMsgId_data_SvsToTHADet_t = 1                                          ,    /* 0x0001 */
    e_IpcMsgId_PpSvsToVCAN_SvsToVCAN_t                                         ,    /* 0x0002 */
    e_IpcMsgId_PpSVStoTRSC_SVStoTRSC_t                                         ,    /* 0x0003 */
    e_IpcMsgId_PpScreenRequest_ScreenRequest_t                                 ,    /* 0x0004 */
    e_IpcMsgId_PpSvsToTHA_SvsToTHA_t                                           ,    /* 0x0005 */
    e_IpcMsgId_PpScreenResponse_ScreenResponse_t                               ,    /* 0x0006 */
    e_IpcMsgId_ME_VehInp_to_IpcSignals_data_f                                  ,    /* 0x0007 */
    e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM                ,    /* 0x0008 */
    e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B                  ,    /* 0x0009 */
    e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM                ,    /* 0x000A */
    e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B                  ,    /* 0x000B */
    e_IpcMsgId_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM                ,    /* 0x000C */
    e_IpcMsgId_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B                  ,    /* 0x000D */
    e_IpcMsgId_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t               ,    /* 0x000E */
    e_IpcMsgId_data_MeDLD_e_RrCamSts_t                                         ,    /* 0x000F */
    e_IpcMsgId_PpTRSC_ME_VehOut_TRSC_t                                         ,    /* 0x0010 */
    e_IpcMsgId_data_SVStoTRSCSMVC_t                                            ,    /* 0x0011 */
    e_IpcMsgId_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t                                 ,    /* 0x0012 */
    e_IpcMsgId_PpDetInpTrsc_Detection_Inputs_from_TRSC_t                       ,    /* 0x0013 */
    e_IpcMsgId_PpSR_State_MCU2_State_2_0                                       ,    /* 0x0014 */
    e_IpcMsgId_PpSR_State_MCU2_State_2_1                                       ,    /* 0x0015 */
    e_IpcMsgId_PpSR_State_QNX_State_QNX                                        ,    /* 0x0016 */
    e_IpcMsgId_Data_SSM_SystemState                                            ,    /* 0x0017 */
    e_IpcMsgId_Data_CalDataProvider_MPU_1_0_Def                                ,    /* 0x0018 */
    e_IpcMsgId_Data_CalDataProvider_MCU_2_0_Def                                ,    /* 0x0019 */
    e_IpcMsgId_Data_CalDataProvider_MCU_2_1_Def                                ,    /* 0x001A */
    e_IpcMsgId_Data_TbSVS_e_SVSCalibSMToAlgoCamCalib_t                         ,    /* 0x001B */
    e_IpcMsgId_Data_TbSVS_e_SVSCalibAlgoToSMCamCalib_t                         ,    /* 0x001C */
    e_IpcMsgId_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t      ,    /* 0x001D */
    e_IpcMsgId_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t                ,    /* 0x001E */
    e_IpcMsgId_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t                ,    /* 0x001F */
    e_IpcMsgId_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t              ,    /* 0x0020 */
    e_IpcMsgId_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t       ,    /* 0x0021 */
    e_IpcMsgId_Data_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t                ,    /* 0x0022 */
    e_IpcMsgId_Data_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t                     ,    /* 0x0023 */
    e_IpcMsgId_Data_ME_Proxi_to_IpcSignals_t                                   ,    /* 0x0024 */
    e_IpcMsgId_PpJobTHADetOutput_JobTHADetOutput_t                             ,    /* 0x0025 */
    e_IpcMsgId_PpAPSMPAOut_TbAP_APSMPAOut_t                                    ,    /* 0x0026 */
    e_IpcMsgId_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t                  ,    /* 0x0027 */
    e_IpcMsgId_Data_IFPAInfoToHMI_t                                            ,    /* 0x0028 */
    e_IpcMsgId_Data_IFPAInfoToVC_t                                             ,    /* 0x0029 */
    e_IpcMsgId_Data_IFPAInfoToPLD_t                                            ,    /* 0x002A */
    e_IpcMsgId_Data_IHMIInfoToFPA_t                                            ,    /* 0x002B */
    e_IpcMsgId_PpJobPLDData_IJobPLDOutput_t                                    ,    /* 0x002C */
    e_IpcMsgId_Data_IUPASensorDataV2_t                                         ,    /* 0x002D */
    e_IpcMsgId_Data_IPathPlannerState_t                                        ,    /* 0x002E */
    e_IpcMsgId_Data_IKinematicData_t                                           ,    /* 0x002F */
    e_IpcMsgId_Data_ExtY_Kinematic_T                                           ,    /* 0x0030 */
    e_IpcMsgId_Data_IParkingSlotInformation_t                                  ,    /* 0x0031 */
    e_IpcMsgId_PpJobFPAData_IJobFPAOutput_t                                    ,    /* 0x0032 */
    e_IpcMsgId_Data_IAutoParkingState_t                                        ,    /* 0x0033 */
    e_IpcMsgId_Data_IParkingSlotID_t                                           ,    /* 0x0034 */
    e_IpcMsgId_PpNFCDOutput_NFCD_Output                                        ,    /* 0x0035 */
    e_IpcMsgId_Data_MOT_Output                                                 ,    /* 0x0036 */
    e_IpcMsgId_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t                  ,    /* 0x0037 */
    e_IpcMsgId_PpSMDAInternal_TbAP_SMDAInternalOut_t                           ,    /* 0x0038 */
    e_IpcMsgId_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t                            ,    /* 0x0039 */
    e_IpcMsgId_PpFPAWarnOut_TbAP_FPAWarnOut_t                                  ,    /* 0x003A */
    e_IpcMsgId_PpRPAWarnOut_TbAP_RPAWarnOut_t                                  ,    /* 0x003B */
    e_IpcMsgId_PpPAStateOut_TbAP_PAStateOut_t                                  ,    /* 0x003C */
    e_IpcMsgId_PpVCActuatorOut_TbAP_VCActuatorOut_t                            ,    /* 0x003D */
    e_IpcMsgId_PpVCTrajOut_TbAP_VCTrajOut_t                                    ,    /* 0x003E */
    e_IpcMsgId_PpVCState_TbAP_VCStateOut_t                                     ,    /* 0x003F */
    e_IpcMsgId_Data_FID_STRUCT_QM                                              ,    /* 0x0040 */
    e_IpcMsgId_Data_FID_STRUCT_B                                               ,    /* 0x0041 */
    e_IpcMsgId_PpUssPointMapGrp_US_S_PointMapGroup_t                           ,    /* 0x0042 */
    e_IpcMsgId_PpSnrDirEcho_US_S_SnrDirEcho_t                                  ,    /* 0x0043 */
    e_IpcMsgId_PpUssZoneInfo_US_S_ZoneInfo_t                                   ,    /* 0x0044 */
    e_IpcMsgId_PpUSSBlockageBit_US_S_BlockageBit_t                             ,    /* 0x0045 */
    e_IpcMsgId_PpUSSConstantData_US_S_USSConstantData_t                        ,    /* 0x0046 */
    e_IpcMsgId_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t                    ,    /* 0x0047 */
    e_IpcMsgId_PpUSSErrorDiagData_US_S_USSErrorDiagData_t                      ,    /* 0x0048 */
    e_IpcMsgId_Data_USS_Curr_Volt_Monitor_t                                    ,    /* 0x0049 */
    e_IpcMsgId_Data_THARelated_ScreenReq_t                                     ,    /* 0x004A */
    e_IpcMsgId_PpCamEepromData_Svs_CamEepromDataArray_t                        ,    /* 0x004B */
    e_IpcMsgId_Data_DiagToSVS_t                                                ,    /* 0x004C */
    e_IpcMsgId_PpSVSToDiag_SVSToDiag_t                                         ,    /* 0x004D */
    e_IpcMsgId_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t                        ,    /* 0x004E */
    e_IpcMsgId_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t                       ,    /* 0x004F */
    e_IpcMsgId_Data_CAM_Curr_Volt_Monitor_t                                    ,    /* 0x0050 */
    e_IpcMsgId_PpCamCsData_CAM_CS_Curr_Monitor_t                               ,    /* 0x0051 */
    e_IpcMsgId_PpUssMrrgData_US_S_MarriageSensorIDs_t                          ,    /* 0x0052 */
    e_IpcMsgId_Data_US_S_MarriageSensorIDs_t                                   ,    /* 0x0053 */
    e_IpcMsgId_PpTrscToDiag_TRSCtoDiagMgr_t                                    ,    /* 0x0054 */
    e_IpcMsgId_PpTrailerDetectOP_TrailerDetection_Output_DID_t                 ,    /* 0x0055 */
    e_IpcMsgId_Data_TbAP_USSStateOut_t                                         ,    /* 0x0056 */
    e_IpcMsgId_Data_HMIInfoToAP_t                                              ,    /* 0x0057 */
    e_IpcMsgId_Data_DiagToParkAssist_t                                         ,    /* 0x0058 */
    e_IpcMsgId_Data_USS_PowerSelect_t                                          ,    /* 0x0059 */
    e_IpcMsgId_Data1_USS_PowerSelect_t                                         ,    /* 0x005A */
    e_IpcMsgId_Data_ME_ProxiToMPU1_0_Def_t                                     ,    /* 0x005B */
    e_IpcMsgId_Data_ME_ProxiToMCU2_0_Def_t                                     ,    /* 0x005C */
    e_IpcMsgId_Data_ME_ProxiToMCU2_1_Def_t                                     ,    /* 0x005D */
    e_IpcMsgId_Data_TrscDebug_ScrRes_t                                         ,    /* 0x005E */
    e_IpcMsgId_Data_TRSCDebug_ScrReq_t                                         ,    /* 0x005F */
    e_IpcMsgId_PpUssDataCollection_US_S_USSDataCollectionData_t                ,    /* 0x0060 */
    e_IpcMsgId_PpPointDistOpBuff_US_S_PointDistOutputBuff_t                    ,    /* 0x0061 */
    e_IpcMsgId_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t                                 ,    /* 0x0062 */
    e_IpcMsgId_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t                                 ,    /* 0x0063 */
    e_IpcMsgId_Data_TbNVM_ReadParam                                            ,    /* 0x0064 */
    e_IpcMsgId_Data_ME_CanDebugRIDStatus_t                                     ,    /* 0x0065 */
    e_IpcMsgId_Data_SVS_NVMData_t                                              ,    /* 0x0066 */
    e_IpcMsgId_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t                         ,    /* 0x0067 */
    e_IpcMsgId_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t                        ,    /* 0x0068 */
    e_IpcMsgId_PpSVSNVMData_SVS_NVMData_t                                      ,    /* 0x0069 */
    e_IpcMsgId_Data_USS_Calibration_Data_t                                     ,    /* 0x006A */
    e_IpcMsgId_PpTbAPDebugOut_TbAP_DebugOut                                    ,    /* 0x006B */
    e_IpcMsgId_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t               ,    /* 0x006C */
    e_IpcMsgId_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t               ,    /* 0x006D */
    e_IpcMsgId_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t               ,    /* 0x006E */
    e_IpcMsgId_Data_ParkingMode_t                                              ,    /* 0x006F */
    e_IpcMsgId_PpLMDLaneOp_LMD_Lane_Outputs_s                                  ,    /* 0x0070 */
    e_IpcMsgId_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t                             ,    /* 0x0071 */
    e_IpcMsgId_Data_THA_Calibration_data_MCU2_1_t                              ,    /* 0x0072 */
    e_IpcMsgId_Data_THA_Calibration_data_MPU1_0_t                              ,    /* 0x0073 */
    e_IpcMsgId_Data_TRSC_Calibration_data_MCU2_1_t                             ,    /* 0x0074 */
    e_IpcMsgId_Data_APA_Calibration_data_MPU1_0_t                              ,    /* 0x0075 */
    e_IpcMsgId_Data_APA_Calibration_data_MCU2_1_t                              ,    /* 0x0076 */
    e_IpcMsgId_Data_SVS_Calibration_data_t                                     ,    /* 0x0077 */
    e_IpcMsgId_Data_FOD_Calibration_data_t                                     ,    /* 0x0078 */
    e_IpcMsgId_Data_LMD_Calibration_data_t                                     ,    /* 0x0079 */
    e_IpcMsgId_Data_TRSC_Calibration_data_MPU1_0_t                             ,    /* 0x007A */
    e_IpcMsgId_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t                  ,    /* 0x007B */
    e_IpcMsgId_PpIDebugFODObject_IDebug_FODObject_t                            ,    /* 0x007C */
    e_IpcMsgId_Data_TbFA_USSStateOutput_t                                      ,    /* 0x007D */
    e_IpcMsgId_PpTbFAResetKM_TbFA_ResetKM_t                                    ,    /* 0x007E */
    e_IpcMsgId_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t                           ,    /* 0x007F */
    e_IpcMsgId_Data_TbSVS_e_SVSCalibSMToHmi_t                                  ,    /* 0x0080 */
    e_IpcMsgId_Data_USS_Calibration_data_2_t                                   ,    /* 0x0081 */
    e_IpcMsgId_PpCamSerENStat_Cam_and_Ser_EN_Status_t                          ,    /* 0x0082 */
    e_IpcMsgId_Data_TrailerDetection_Output_HMI_t                              ,    /* 0x0083 */
    e_IpcMsgId_PpDLDOutput_JobDLDOutput_t                                      ,    /* 0x0084 */
    e_IpcMsgId_Data_INVMSignalManager_t                                        ,    /* 0x0085 */
    e_IpcMsgId_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t                          ,    /* 0x0086 */
    e_IpcMsgId_Data_TimeManagerProxy_TimeStamp_t                               ,    /* 0x0087 */
    e_IpcMsgId_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type                ,    /* 0x0088 */
    e_IpcMsgId_PpKeepAliveResponse_KeepAliveResponse_t                         ,    /* 0x0089 */
    e_IpcMsgId_PpUssDebugMsg_US_S_DebugMsg_t                                   ,    /* 0x008A */
    e_IpcMsgId_PpCAMSelInfo_CAM_select_info_t                                  ,    /* 0x008B */
    e_IpcMsgId_PpErrFltMcu2_0_Error_Fault_MCU2_0_t                             ,    /* 0x008C */
    e_IpcMsgId_PpErrFltMcu2_1_Error_Fault_MCU2_1_t                             ,    /* 0x008D */
    e_IpcMsgId_PpErrFltMpu1_0_Error_Fault_MPU1_0_t                             ,    /* 0x008E */
    e_IpcMsgId_Data_TRSC_CalibrationClear_t                                    ,    /* 0x008F */
    e_IpcMsgId_Data_UssTunningData_mcu1_0_t                                    ,    /* 0x0090 */
    e_IpcMsgId_PpUssTunData_UssTunningData_mcu2_1_t                            ,    /* 0x0091 */
    e_IpcMsgId_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t                     ,    /* 0x0092 */
    e_IpcMsgId_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t                     ,    /* 0x0093 */
    e_IpcMsgId_Data_PerformanceStatsEnable_t                                   ,    /* 0x0094 */
    e_IpcMsgId_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t                     ,    /* 0x0095 */
    e_IpcMsgId_Data_CamHotplugStatus_t                                         ,    /* 0x0096 */
    e_IpcMsgId_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t                         ,    /* 0x0097 */
    e_IpcMsgId_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t                         ,    /* 0x0098 */
    e_IpcMsgId_MAX_COUNT                                        , 
} IpcMsgId_t;

/* ===========================================================================
*
*   Global Variables
*
* ========================================================================= */

/* ===========================================================================
*
*   Function Prototypes
*
* ========================================================================= */

/* ===========================================================================
 *
 *   End of Header File
 *
 * ======================================================================== */
#endif // IPC_LOOKUP_TABLE_H_
