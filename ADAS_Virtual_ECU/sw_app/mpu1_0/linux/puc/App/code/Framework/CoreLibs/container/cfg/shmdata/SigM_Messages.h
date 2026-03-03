#ifndef SIGM_MESSAGES_H
#define SIGM_MESSAGES_H

#include "platform/stdlib/utils/DataSerializer.h"
#include "CommonDataTypeRef.h"
#include <bsp/io/tiovx/SvsCamTypes.h>
//#include "SignalMgrSigTypes.h"
#include "ipc_lookup_table.h"

//----A72 to mcu1_0----->
/****************************************************************************
 * Svs_CamEepromDataArray_t svs_CamEepromDataArray_t
 */

static const uint32_t c_EepromCRCResbytesSize_u32 = 60u;

#pragma pack(1) // exact fit - no padding // PRQA S 1040 // pragma needed for structures
// PRQA S 2000 EOF // global scope, this is a header file
// PRQA S 2400 EOF // global scope, this is a header file
// PRQA S 2300 EOF // global scope, this is a header file

/*  --- Structs --- */


typedef struct ErrorneousResponse_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint16_t ErrorMessageID_u16; /* The Message ID that could not be handled */
} ErrorneousResponse_t;

typedef struct BootStateRequest_s
{
  uint8_t BootState_u8; /* CuC State */
  uint8_t CamDeserSerEnable_u8; /* Camera Desrilizer Serializer Shut Down */
} BootStateRequest_t;

typedef struct BootStateResponse_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t VideoSubSystemState_u8; /* Video Subsystem State */
  uint8_t CamDeserSerEnableComplete_u8; /* Camera Deserilizer and Serilizer shut down status */
} BootStateResponse_t;

typedef struct ApplyConfigRequest_s
{
  uint16_t variantID_u16; /* Vehicle Variant Info */
  uint16_t varintConfig_u16; /* Other varintConfig */
} ApplyConfigRequest_t;

typedef struct ApplyConfigResponse_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint16_t variantID_u16; /* Vehicle Variant Info */
  uint16_t varintConfig_u16; /* Other varintConfig */
} ApplyConfigResponse_t;

typedef struct ErrorStateRequest_s
{
  uint8_t ErrorCategory_u8; /*   ErrorCategory_Camera = 0,  ErrorCategory_Others = 1 */
} ErrorStateRequest_t;

static const uint32_t c_ErrDataSize_u32 = 30;
typedef struct ErrorStateResponse_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t ErrorCategory_u8; /* see Request */
  uint8_t ErrData_au8[c_ErrDataSize_u32]; /* Depending on Request */
} ErrorStateResponse_t;

typedef struct KeepAliveRequest_s
{
  uint32_t Counter_u32; /* Counter */
} KeepAliveRequest_t;


typedef struct TestPatternRequest_s
{
  uint8_t CameraID_u8; /* CameraID */
  uint8_t RequestedTestPattern_u8; /* RequestedTestPattern */
} TestPatternRequest_t;

typedef struct TestPatternResponse_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CameraID_u8; /* CameraID */
  uint8_t RequestedTestPattern_u8; /* RequestedTestPattern */
} TestPatternResponse_t;

typedef struct InformationRequest_s
{
  sint8_t Requested_Information_s8; /* Requested_Information Identifier */
  uint8_t Payload_u8; /* Payload */
} InformationRequest_t;

static const uint32_t c_PayloadSize_u32 = 6;
typedef struct InformationResponse_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t Current_Information_u8; /* Current_Information Identifier */
  uint8_t Payload_au8[c_PayloadSize_u32]; /* Depending on Request */
} InformationResponse_t;

typedef struct Request_Control_ErrorState_s
{
  uint8_t ErrorCategory_u8; /* ErrorCategory */
  uint8_t Error_Data_No_Video_Output_u8; /* No video output error data */
  uint8_t Error_Data_Front_Cam_u8; /* Front camera error data */
  uint8_t Error_Data_Left_Cam_u8; /* left camera error data */
  uint8_t Error_Data_Rear_Cam_u8; /* Rear camera error data */
  uint8_t Error_Data_Right_Cam_u8; /* Right camera error data */
  uint8_t Error_Data_Bed_Cam_u8; /* Bed camera error data */
  uint8_t hold_time_0_u8; /* hold time 0 */
} Request_Control_ErrorState_t;

typedef struct Response_Control_ErrorState_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
} Response_Control_ErrorState_t;

typedef struct ControlRequest_s
{
  uint8_t RequestedControl_u8; /* Requested control */
  uint32_t Payload_u32; /* Payload for requested control */
} ControlRequest_t;

typedef struct ControlResponse_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
} ControlResponse_t;

typedef struct MiscRequest_s
{
  uint8_t TRANSTAT_u8;
  uint8_t GDEC_u8;
  uint8_t CANCEL_u8;
  uint8_t TORQUE_u8;
} MiscRequest_t;

typedef struct MiscResponse_s
{
  uint8_t Response_Code_MiscResponse_u8;
} MiscResponse_t;

typedef struct GearSignals_EPSdata_s
{
  uint8_t PCAN_B_P_u8 : 1;
  uint8_t PCAN_B_R_u8 : 1; /* Private CAN Reverse */
  uint8_t PCAN_B_D_u8 : 1;
  uint8_t PCAN_B_N_u8 : 1; /* Private CAN Neutral  */
  uint8_t REV_SW_u8 : 1; /* Reverse switch */
  uint8_t TraActiveLight_u8 : 1; /* 1 when TRA is active */
  uint8_t GearSignal_bit_6_u8 : 1; /* dummy bit_6 */
  uint8_t GearSignal_bit_7_u8 : 1; /* dummy bit_7 */
  uint8_t PCAN_EPSFAIL_u8 : 1;
  uint8_t PCAN_EPSSTS0_u8 : 1; /* PCAN_EPSSTS0 */
  uint8_t PCAN_EPSACT_u8 : 1;
  uint8_t PCAN_EPSSYS_u8 : 1; /* PCAN_EPSSYS */
  uint8_t EPSdata_bit_4_u8 : 1; /* dummy bit_4 */
  uint8_t EPSdata_bit_5_u8 : 1; /* dummy bit_5 */
  uint8_t EPSdata_bit_6_u8 : 1; /* dummy bit_6 */
  uint8_t EPSdata_bit_7_u8 : 1; /* dummy bit_7 */
} GearSignals_EPSdata_t;

typedef struct MCU_TRAGateway1Request_s
{
  GearSignals_EPSdata_t GearSignals_EPSdata; /* Park,Reverse,neutral,Drive bits */
  uint8_t PCAN_VWPSUMFL_u8; /* PCAN_VWPSUMFL */
  uint8_t PCAN_VWPSUMFR_u8; /* PCAN_VWPSUMFR */
  uint8_t PCAN_VWPSUMRL_u8; /* PCAN_VWPSUMRL */
  uint8_t PCAN_VWPSUMRR_u8; /* PCAN_VWPSUMRR */
} MCU_TRAGateway1Request_t;

typedef struct MCU_TRAGateway1Response_s
{
  uint8_t Response_Code_MCU_TRAGateway1_u8; /* Response_Code_MCU_TRAGateway1 */
} MCU_TRAGateway1Response_t;

typedef struct MCU_TRAGateway2Request_s
{
  uint16_t PCAN_VXFR_u16; /* Wheel Speed Front Right */
  uint16_t PCAN_VXFL_u16; /* Wheel Speed Front Left */
  uint16_t PCAN_VXRR_u16; /* Wheel Speed Rear Right */
  uint16_t PCAN_VXRL_u16; /* Wheel Speed Rear Left */
} MCU_TRAGateway2Request_t;

typedef struct MCU_TRAGateway2Response_s
{
  uint8_t Response_Code_MCU_TRAGateWay2_u8; /* Response_Code_MCU_TRAGateWay2 */
} MCU_TRAGateway2Response_t;

typedef struct SSA_SSASBits_s
{
  uint16_t PCAN_SSA_u16 : 12;
  sint16_t PCAN_SSAS_s16 : 4; /* PCAN Steering Angle Sensor */
} SSA_SSASBits_t;

typedef struct MCU_TRAGateway3Request_s
{
  uint16_t PCAN_SP1_u16; /* PCAN Speed */
  SSA_SSASBits_t SSA_SSASBits_s; /* SSA_SSASBits_s */
  uint16_t PCAN_VSC_YAW0_u16; /* PCAN Yaw Rate */
  sint16_t PCAN_SSAV_s16; /* PCAN Streering Angle Validity */
} MCU_TRAGateway3Request_t;

typedef struct MCU_TRAGateway3Response_s
{
  uint8_t ResponseCode_TRAGateway3_u8; /* Response_Code_TRAGateway3 */
  uint16_t TAD_angle_u16; /* TAD_angle */
  uint8_t Confidence_u8; /* confidence */
  uint16_t tadAngleRate_u16; /* angleRateOfChange */
  uint16_t frameNumber_u16; /* processed frame number */
} MCU_TRAGateway3Response_t;

typedef struct MCU_TRAGateway4Request_s
{
  uint16_t PCAN_EST2_u16; /* PCAN_EST2 */
} MCU_TRAGateway4Request_t;

typedef struct MCU_TRAGateway4Response_s
{
  uint8_t Response_Code_MCU_TRAGateway4_u8; /* Response_Code_MCU_TRAGateway4 */
  uint16_t TrailerBeamLength_u16; /* TrailerBeamLength */
  uint16_t HitchLength_u16; /* HitchLength */
  uint8_t TadState_u8; /* 0: idle, 1: Detection, 2: calibration, 3:Scanning, 4:Turnaround, 5:Angle Detection, 6: tracking lost */
  uint16_t TRATSA_u16; /* Target Steering Angle */
} MCU_TRAGateway4Response_t;

#ifdef USE_REQUEST_AND_RESPONSE
typedef struct OverlayBits_s
{
  uint8_t LayoutPartView_u8 : 1;
  uint8_t LayoutFullView_u8 : 1;
  uint8_t LayoutMtmView_u8 : 1;
  uint8_t LayoutConfirmView_u8 : 1;
  uint8_t IconGdlFrontCorner_u8 : 1;
  uint8_t IconGdlFrontWheel_u8 : 1;
  uint8_t IconGdlRearStatic_u8 : 1;
  uint8_t IconGdlRearDistance_u8 : 1;
  uint8_t IconGdlRearWheelDir_u8 : 1;
  uint8_t IconClearanceSonar_u8 : 1;
  uint8_t IconSoundOn_u8 : 1;
  uint8_t IconSoundOff_u8 : 1;
  uint8_t IconRcdOff_u8 : 1;
  uint8_t IconWarn_u8 : 1;
  uint8_t IconBrake_u8 : 1;
  uint8_t IconBrakeSwitch_u8 : 1;
  uint8_t IconBrakePress_u8 : 1;
  uint8_t Btn10kphDis_u8 : 1;
  uint8_t ButtonZoom_u8 : 1;
  uint8_t ButtonDblZoom_u8 : 1;
  uint8_t ButtonUnZoom_u8 : 1;
  uint8_t BtnExit_u8 : 1;
  uint8_t ButtonPvmFrontOn_u8 : 1;
  uint8_t ButtonPvmFrontOff_u8 : 1;
  uint8_t ButtonPvmRearOn_u8 : 1;
  uint8_t ButtonPvmRearOff_u8 : 1;
  uint8_t ButtonPvmFronSplitOn_u8 : 1;
  uint8_t ButtonPvmFrontSplitOff_u8 : 1;
  uint8_t ButtonPvmRearSplitOn_u8 : 1;
  uint8_t ButtonPvmRearSplitOff_u8 : 1;
  uint8_t ButtonPvmAuxOn_u8 : 1;
  uint8_t ButtonPvmAuxOff_u8 : 1;
  uint8_t ButtonPvmCargoOn_u8 : 1;
  uint8_t ButtonPvmCargoOff_u8 : 1;
  uint8_t ButtonPvmTopOn_u8 : 1;
  uint8_t ButtonPvmTopOnLock_u8 : 1;
  uint8_t ButtonPvmTopOff_u8 : 1;
  uint8_t ButtonPvmTopOffLock_u8 : 1;
  uint8_t ButtonMtmViewEnable_u8 : 1;
  uint8_t ButtonMtmViewDisable_u8 : 1;
  uint8_t ButtonTraOn_u8 : 1;
  uint8_t ButtonTraOff_u8 : 1;
  uint8_t ButtonTraDisable_u8 : 1;
  uint8_t ButtonTowOn_u8 : 1;
  uint8_t ButtonTowOff_u8 : 1;
  uint8_t ButtonPrevView_u8 : 1;
  uint8_t ButtonPanBar_u8 : 1;
  uint8_t ButtonPanLeArrow_u8 : 1;
  uint8_t ButtonPanRiArrow_u8 : 1;
  uint8_t ButtonAutoStartLock_u8 : 1;
  uint8_t ButtonAutoStartOn_u8 : 1;
  uint8_t ButtonAutoStartOff_u8 : 1;
  uint8_t IconWheelSlip_u8 : 1;
  uint8_t ButtonTowDisable_u8 : 1;
  uint8_t ButtonPvmTopDisable_u8 : 1;
  uint8_t IconAccelerationPressed_u8 : 1;
  uint8_t ButtonMtmFrontSideOn_u8 : 1;
  uint8_t ButtonMtmFrontSideOff_u8 : 1;
  uint8_t ButtonMtmUnderfloorSideOn_u8 : 1;
  uint8_t ButtonMtmUnderfloorSideOff_u8 : 1;
  uint8_t ButtonMtmRearSideOn_u8 : 1;
  uint8_t ButtonMtmRearSideOff_u8 : 1;
  uint8_t ButtonMtmRearWideOn_u8 : 1;
  uint8_t ButtonMtmRearWideOff_u8 : 1;
  uint8_t ButtonMtmAuxOn_u8 : 1;
  uint8_t ButtonMtmAuxOff_u8 : 1;
  uint8_t ButtonPvmViewEnable_u8 : 1;
  uint8_t ButtonPvmViewDisable_u8 : 1;
  uint8_t IconGdlSelectLocked_u8 : 1;
  uint8_t IconInclinometerDisable_u8 : 1;
  uint8_t IconInclinometer_u8 : 1;
  uint8_t ButtonMtmAutoStartOn_u8 : 1;
  uint8_t ButtonMtmAutoStartOff_u8 : 1;
  uint8_t ButtonConfirmViewFooter_u8 : 1;
  uint8_t TextPksbUnavailable_u8 : 1;
  uint8_t IconTrlSwingLeft_u8 : 1;
  uint8_t IconTrlSwingRight_u8 : 1;
  uint8_t IconRearCrossTrafficAlertTop_u8 : 1;
  uint8_t GuidelineRearDistancePrimary_u8 : 1;
  uint8_t GuidelineFrontCornerTop_u8 : 1;
  uint8_t GuidelineFrontPredictTop_u8 : 1;
  uint8_t GuidelineRearDistanceTop_u8 : 1;
  uint8_t GuidelineRearDynamicTop_u8 : 1;
  uint8_t GuidelineFrontBackwardTop_u8 : 1;
  uint8_t GuidelineRearParkTop_u8 : 1;
  uint8_t GuidelineFrontCornerPrimary_u8 : 1;
  uint8_t GuidelineFrontSplitPrimary_u8 : 1;
  uint8_t GuidelineRearStaticDistRedPrimary_u8 : 1;
  uint8_t GuidelineRearDynamicPrimary_u8 : 1;
  uint8_t GuidelineRearStaticPrimary_u8 : 1;
  uint8_t GuidelineRearParkPrimary_u8 : 1;
  uint8_t GuidelineTowPrimary_u8 : 1;
  uint8_t GuidelineConfirmTrailerMarkPrimary_u8 : 1;
  uint8_t GuidelineMtmFrontDistance_u8 : 1;
  uint8_t GuidelineMtmFrontMax_u8 : 1;
  uint8_t GuidelineMtmFrontDynamic_u8 : 1;
  uint8_t GuidelineMtmSideStatic_u8 : 1;
  uint8_t GuidelineMtmFrontOverallDynamic_u8 : 1;
  uint8_t GuidelineMtmRearOverallDynamic_u8 : 1;
  uint8_t GuidelineRearStaticDistBluePrimary_u8 : 1;
  uint8_t ButtonPvmFrontDisable_u8 : 1;
  uint8_t ButtonPvmRearDisable_u8 : 1;
  uint8_t ButtonPvmFrontSplitDisable_u8 : 1;
  uint8_t IconMtmUnderfloorVehicleContour_u8 : 1;
  uint8_t TextCheckSurrounding_u8 : 1;
  uint8_t TextTraMessages_u8 : 1;
  uint8_t BtnTraModeDisable_u8 : 1;
  uint8_t IconRearCrossTrafficAlertPrimary_u8 : 1;
  uint8_t ButtonPvmRearSplitDisable_u8 : 1;
  uint8_t ButtonPvmAuxDisable_u8 : 1;
  uint8_t ButtonPvmCargoDisable_u8 : 1;
  uint8_t ButtonFrontGdlSelectDisable_u8 : 1;
  uint8_t ButtonRearGdlSelectDisable_u8 : 1;
  uint8_t ButtonAutoStartDisable_u8 : 1;
  uint8_t ButtonMtmFrontSideDisable_u8 : 1;
  uint8_t ButtonMtmUnderfloorSideDisable_u8 : 1;
  uint8_t ButtonMtmRearSideDisable_u8 : 1;
  uint8_t ButtonMtmRearWideDisable_u8 : 1;
  uint8_t ButtonMtmAuxDisable_u8 : 1;
  uint8_t ButtonMtmAutoStartDisable_u8 : 1;
  uint8_t IconClearanceSonarGuidance_u8 : 1;
  uint8_t DealScrManualAdjust_u8 : 1;
  uint8_t DealScrCameraCheck_u8 : 1;
  uint8_t IconTrlSwingText_u8 : 1;
  uint8_t VehicleColorMenu_u8 : 1;
  uint8_t IconClearanceSonarTopView_u8 : 1;
  uint8_t Bit126_u8 : 1;
  uint8_t Bit127_u8 : 1;
} OverlayBits_t;

static const uint32_t c_ReqScreenDataSize_u32 = 10;
typedef struct ScreenRequest_s
{
  uint8_t Version_u8; /* Version */
  uint8_t ViewID_u8; /* View Identifier */
  uint8_t ZoomFactor_u8; /* Zoom Factor */
  uint8_t ColorCode_u8; /* ColorCode */
  uint8_t NaviScrMsg_u8; /* NaviScrMsg */
  uint8_t ToggleCount_u8; /* ToggleCount */
  OverlayBits_t OverlayBits_s; /* Struct Comment */
  uint8_t ButtonId_u8; /* aPerfM_E_HmiSoftButton_t */
  uint8_t ButtonState_u8; /* aPerfM_E_HmiSoftButtonStatus_t */
  uint8_t ScreenID_u8; /* ScreenID_t */
  uint8_t ScreenData_au8[c_ReqScreenDataSize_u32]; /* Depending on Request */
  uint8_t ButtonIdReset_u8; /* ButtonIdReset_t */
  uint16_t CRC16_u16; /* CRC */
} ScreenRequest_t;

static const uint32_t c_ResScreenDataSize_u32 = 10;
typedef struct ScreenResponse_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t Version_u8; /* Version */
  uint8_t ViewID_u8; /* View Identifier */
  uint8_t ZoomFactor_u8; /* Zoom Factor */
  uint8_t ColorCode_u8; /* ColorCode */
  uint8_t NaviScrMsg_u8; /* NaviScrMsg */
  uint8_t ToggleCount_u8; /* ToggleCount */
  OverlayBits_t OverlayBits_s; /* Struct Comment */
  uint8_t ButtonId_u8; /* aPerfM_E_HmiSoftButton_t */
  uint8_t ButtonState_u8; /* aPerfM_E_HmiSoftButtonStatus_t */
  uint8_t ScreenID_u8; /* ScreenID_t */
  uint8_t ScreenData_au8[c_ResScreenDataSize_u32]; /* Depending on Request */
  uint8_t ButtonIdReset_u8; /* ButtonIdReset_t */
  uint16_t CRC16_u16; /* CRC */
} ScreenResponse_t;
#endif

typedef struct TRA_Data_Request_s
{
  uint8_t Emptiness1_u8; /* nothing */
  uint8_t Emptiness2_u8; /* TAD Tracking Status */
  uint8_t Emptiness3_u8; /* TAD Tracking Status */
  uint8_t IeTRIO_b_ClrTrlrCal_u8; /* Clear Trailer Calibration */
  uint8_t IeTRIO_e_TADTrackStat_u8; /* TAD Tracking Status */
  uint8_t IeTRIO_b_TRAACT_u8; /* TAD Tracking Status */
  uint8_t IeTRIO_e_TRAStrCtrlStat_u8; /* TAD Tracking Status */
  uint8_t IeTRIO_e_TrlrActStat_u8; /* Trailer Active Status */
  uint8_t IeTRIO_e_TrlrCalStat_u8; /* Trailer Calibration Status */
  uint8_t IeTRIO_e_TrlrID_u8; /* Trailer ID */
  uint8_t IeTRIO_b_RqstArmVlidPar_u8; /* Trailer ID */
  uint8_t IeTRIO_e_TrlrAgeStat_u8; /* Trailer Tracking Status */
  uint16_t IeTRIO_deg_MaxSWR_u16; /* Maximum Steering Wheel Range */
  uint16_t IeTRIO_deg_MaxTsaAllwd_u16; /* ??? */
} TRA_Data_Request_t;

typedef struct TRA_Data_Response_s
{
  uint8_t Emptiness1_u8; /* nothing */
  uint8_t Emptiness2_u8; /* TAD Tracking Status */
  uint8_t Emptiness3_u8; /* TAD Tracking Status */
  uint8_t Emptiness4_u8; /* TAD Tracking Status */
  uint8_t IeTRIA_e_TrlrDimEstStat_u8; /* Trailer Dimension Estimate State */
  uint8_t IeTRIA_e_StrIcon_u8; /* Trailer Calibration Step #1 state */
  uint8_t IeTRIA_e_TrlrDirIcon_u8; /* Calibration State */
  uint8_t IeTRIA_e_ArmTrnPrcss_u8; /* Trailer Dimension Estimate State */
  uint8_t IeTRIA_e_ArmSaveData_u8; /* Trailer Dimension Estimate State */
  uint8_t IeTRIA_e_TADAcqStat_u8; /* Trailer Dimension Estimate State */
  uint8_t IeTRIA_b_TrlrDataV_u8; /* Trailer Dimension Estimate State */
  uint8_t IeTRIA_b_ASRACT_u8; /* Trailer Dimension Estimate State */
  float32_t IeTRIA_deg_TADAngAct_f32; /* Actual TAD Angle */
  float32_t IeTRIA_deg_TrgtStrAng_f32; /* Trailer Dimension Estimate State */
  float32_t IeTRIA_ddeg_TADAngRateAct_f32; /* Trailer Dimension Estimate State */
  float32_t IeTRIA_deg_TrlrAngTh_f32; /* Trailer Dimension Estimate State */
  float32_t IeTRIA_deg_TADAngPred_f32; /* TAD angle prediction */
} TRA_Data_Response_t;

static const uint32_t c_ReservedSize_u32 = 8;
typedef struct Request_Camera_GetEeprom_s
{
  uint8_t v_CameraID_u8; /* Cam Identifier */
  uint8_t v_ReadOffset_u8; /* Cam Data Read Offset */
  uint8_t v_Reserved_au8[c_ReservedSize_u32]; /* Reserved */
} Request_Camera_GetEeprom_t;

static const uint32_t c_DataSize_u32 = 40;
typedef struct Response_Camera_GetEeprom_s
{
  uint8_t v_ResponseCode_u8; /* ResponseCode */
  uint8_t v_data_au8[c_DataSize_u32]; /* Response Camera data */
} Response_Camera_GetEeprom_t;

typedef struct Request_Camera_SetRegister_s
{
  uint8_t CameraID_u8; /* Cam Identifier */
  uint8_t DeviceID_u8; /* Device Identifier */
  uint16_t RegisterAddress_u16; /* RegisterAddress */
  uint16_t RegisterValue_u16; /* RegisterValue */
} Request_Camera_SetRegister_t;

typedef struct Response_Camera_SetRegister_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CameraID_u8; /* Cam Identifier */
  uint8_t DeviceID_u8; /* Device Identifier */
} Response_Camera_SetRegister_t;

typedef struct Request_Camera_GetRegister_s
{
  uint8_t CameraID_u8; /* Cam Identifier */
  uint8_t DeviceID_u8; /* Device Identifier */
  uint16_t RegisterAddress_u16; /* RegisterAddress */
} Request_Camera_GetRegister_t;

typedef struct Response_Camera_GetRegister_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CameraID_u8; /* Cam Identifier */
  uint8_t DeviceID_u8; /* Device Identifier */
  uint16_t RegisterAddress_u16; /* RegisterAddress */
  uint16_t RegisterValue_u16; /* RegisterValue */
} Response_Camera_GetRegister_t;

typedef struct Request_Camera_Debug_s
{
  uint8_t CamID_u8; /* unused must be 0xFF */
  uint8_t DebugEnable_u8; /* DebugEnable */
  uint8_t FailsafeBehavior_u8; /* FailsafeBehavior */
  uint8_t CamToMemStatusThreshold_u8; /* CamToMemStatusThreshold */
  uint8_t CamMinRestartInterval_u8; /* CamMinRestartInterval */
} Request_Camera_Debug_t;

typedef struct Response_Camera_Debug_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* unused must be 0x0 */
  uint8_t DebugEnable_u8; /* DebugEnable */
  uint8_t FailsafeBehavior_u8; /* FailsafeBehavior */
  uint8_t CamToMemStatusThreshold_u8; /* CamToMemStatusThreshold */
  uint8_t CamMinRestartInterval_u8; /* CamMinRestartInterval */
} Response_Camera_Debug_t;

typedef struct Request_Camera_ApplyCalib_s
{
  uint8_t CameraID_u8; /* camera ID */
  float32_t Pitch_f32; /* Pitch front */
  float32_t Yaw_f32; /* Yaw front */
  float32_t Roll_f32; /* Roll front */
  float32_t X_f32; /* X front */
  float32_t Y_f32; /* Y front */
  float32_t Z_f32; /* Z front */
} Request_Camera_ApplyCalib_t;

typedef struct Response_Camera_ApplyCalib_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
} Response_Camera_ApplyCalib_t;

typedef struct Request_EOL_Start_s
{
  uint8_t CamID_u8; /* Cam Identifier */
  uint8_t Algo_Selected_u8; /* Algo selection */
  sint32_t targetX1_s32; /* X-( center -)position of target 1 */
  sint32_t targetY1_s32; /* Y-( center -)position of target 1 */
  sint32_t targetX2_s32; /* X-( center -)position of target 2 */
  sint32_t targetY2_s32; /* Y-( center -)position of target 2 */
} Request_EOL_Start_t;

typedef struct Response_EOL_Start_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_EOL_Start_t;

typedef struct Request_EOL_Stop_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_EOL_Stop_t;

typedef struct Response_EOL_Stop_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_EOL_Stop_t;

typedef struct Request_EOL_Pause_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_EOL_Pause_t;

typedef struct Response_EOL_Pause_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_EOL_Pause_t;

typedef struct Request_EOL_Resume_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_EOL_Resume_t;

typedef struct Response_EOL_Resume_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_EOL_Resume_t;

typedef struct Request_EOL_Status_s
{
  uint8_t CamID_u8; /* Cam Identifier */
  uint8_t Algo_Selected_u8; /* Algo select */
  uint8_t Read_Offset_u8; /* Read offset */
} Request_EOL_Status_t;

static const uint32_t c_TargetMarkerDataSize_u32 = 20;
typedef struct Response_EOL_Status_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t ErrorState_u8; /* ErrorState_u8 */
  uint16_t TargetMarkerData_au16[c_TargetMarkerDataSize_u32]; /* Depending on Request */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
} Response_EOL_Status_t;

typedef struct Request_EOL_Debug_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_EOL_Debug_t;

typedef struct Response_EOL_Debug_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint16_t markerDetectionLeft0_u16; /* markerDetectionLeft0_u16 */
  uint16_t markerDetectionLeft1_u16; /* markerDetectionLeft1_u16 */
  uint16_t markerDetectionLeft2_u16; /* markerDetectionLeft2_u16 */
  uint16_t markerDetectionLeft3_u16; /* markerDetectionLeft3_u16 */
  uint16_t markerDetectionLeft4_u16; /* markerDetectionLeft4_u16 */
  uint16_t markerDetectionLeft5_u16; /* markerDetectionLeft5_u16 */
  uint16_t markerDetectionLeft6_u16; /* markerDetectionLeft6_u16 */
  uint16_t markerDetectionLeft7_u16; /* markerDetectionLeft7_u16 */
  uint16_t markerDetectionLeft8_u16; /* markerDetectionLeft8_u16 */
  uint16_t markerDetectionLeft9_u16; /* markerDetectionLeft9_u16 */
  uint16_t markerDetectionRight0_u16; /* markerDetectionRight0_u16 */
  uint16_t markerDetectionRight1_u16; /* markerDetectionRight1_u16 */
  uint16_t markerDetectionRight2_u16; /* markerDetectionRight2_u16 */
  uint16_t markerDetectionRight3_u16; /* markerDetectionRight3_u16 */
  uint16_t markerDetectionRight4_u16; /* markerDetectionRight4_u16 */
  uint16_t markerDetectionRight5_u16; /* markerDetectionRight5_u16 */
  uint16_t markerDetectionRight6_u16; /* markerDetectionRight6_u16 */
  uint16_t markerDetectionRight7_u16; /* markerDetectionRight7_u16 */
  uint16_t markerDetectionRight8_u16; /* markerDetectionRight8_u16 */
  uint16_t markerDetectionRight9_u16; /* markerDetectionRight9_u16 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_EOL_Debug_t;

typedef struct Request_OC_Start_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_OC_Start_t;

typedef struct Response_OC_Start_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_OC_Start_t;

typedef struct Request_OC_Stop_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_OC_Stop_t;

typedef struct Response_OC_Stop_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_OC_Stop_t;

typedef struct Request_OC_Pause_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_OC_Pause_t;

typedef struct Response_OC_Pause_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_OC_Pause_t;

typedef struct Request_OC_Resume_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_OC_Resume_t;

typedef struct Response_OC_Resume_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_OC_Resume_t;

typedef struct Request_OC_Status_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_OC_Status_t;

typedef struct Response_OC_Status_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_OC_Status_t;

typedef struct Request_OC_Debug_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_OC_Debug_t;

typedef struct Response_OC_Debug_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_OC_Debug_t;

typedef struct Request_SC_Start_s
{
  uint8_t CamID_u8; /* Cam Identifier */
  uint8_t numberOfTargets_u8; /* Total number of targets ( max = 4) */
  uint32_t numberOfSquares1_u32; /* number of squares for target 1 */
  uint32_t targetWidth1_u32; /* width of target 1 */
  uint32_t targetHeight1_u32; /* height of target 1 */
  sint32_t targetX1_s32; /* X-( center -)position of target 1 */
  sint32_t targetY1_s32; /* Y-( center -)position of target 1 */
  sint32_t targetZ1_s32; /* Z-( center -)position of target 1 */
  sint32_t orientation1_s32; /* orientation of target 1 in degrees */
  uint32_t numberOfSquares2_u32; /* number of squares for target 2 */
  uint32_t targetWidth2_u32; /* width of target 2 */
  uint32_t targetHeight2_u32; /* height of target 2 */
  sint32_t targetX2_s32; /* X-( center -)position of target 2 */
  sint32_t targetY2_s32; /* Y-( center -)position of target 2 */
  sint32_t targetZ2_s32; /* Z-( center -)position of target 2 */
  sint32_t orientation2_s32; /* orientation of target 2 in degrees */
  uint32_t numberOfSquares3_u32; /* number of squares for target 3 */
  uint32_t targetWidth3_u32; /* width of target 3 */
  uint32_t targetHeight3_u32; /* height of target 3 */
  sint32_t targetX3_s32; /* X-( center -)position of target 3 */
  sint32_t targetY3_s32; /* Y-( center -)position of target 3 */
  sint32_t targetZ3_s32; /* Z-( center -)position of target 3 */
  sint32_t orientation3_s32; /* orientation of target 3 in degrees */
  uint32_t numberOfSquares4_u32; /* number of squares for target 4 */
  uint32_t targetWidth4_u32; /* width of target 4 */
  uint32_t targetHeight4_u32; /* height of target 4 */
  sint32_t targetX4_s32; /* X-( center -)position of target 4 */
  sint32_t targetY4_s32; /* Y-( center -)position of target 4 */
  sint32_t targetZ4_s32; /* Z-( center -)position of target 4 */
  sint32_t orientation4_s32; /* orientation of target 4 in degrees */
} Request_SC_Start_t;

typedef struct Response_SC_Start_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t targetInit_s8; /* Target Init */
  sint8_t targetLimitFront_s8; /* Target Limit Front */
  sint8_t targetLimitRear_s8; /* Target Limit Rear */
  sint8_t targetDetectLeftFront_s8; /* Target detect left front */
  sint8_t targetDetectLeftRear_s8; /* Target detect left rear */
  sint8_t targetDetectRightFront_s8; /* Target detect right front */
  sint8_t targetDetectRightRear_s8; /* Target detect right rear */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_SC_Start_t;

typedef struct Request_SC_Stop_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_SC_Stop_t;

typedef struct Response_SC_Stop_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t targetInit_s8; /* Target Init */
  sint8_t targetLimitFront_s8; /* Target Limit Front */
  sint8_t targetLimitRear_s8; /* Target Limit Rear */
  sint8_t targetDetectLeftFront_s8; /* Target detect left front */
  sint8_t targetDetectLeftRear_s8; /* Target detect left rear */
  sint8_t targetDetectRightFront_s8; /* Target detect right front */
  sint8_t targetDetectRightRear_s8; /* Target detect right rear */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_SC_Stop_t;

typedef struct Request_SC_Pause_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_SC_Pause_t;

typedef struct Response_SC_Pause_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t targetInit_s8; /* Target Init */
  sint8_t targetLimitFront_s8; /* Target Limit Front */
  sint8_t targetLimitRear_s8; /* Target Limit Rear */
  sint8_t targetDetectLeftFront_s8; /* Target detect left front */
  sint8_t targetDetectLeftRear_s8; /* Target detect left rear */
  sint8_t targetDetectRightFront_s8; /* Target detect right front */
  sint8_t targetDetectRightRear_s8; /* Target detect right rear */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_SC_Pause_t;

typedef struct Request_SC_Resume_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_SC_Resume_t;

typedef struct Response_SC_Resume_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t targetInit_s8; /* Target Init */
  sint8_t targetLimitFront_s8; /* Target Limit Front */
  sint8_t targetLimitRear_s8; /* Target Limit Rear */
  sint8_t targetDetectLeftFront_s8; /* Target detect left front */
  sint8_t targetDetectLeftRear_s8; /* Target detect left rear */
  sint8_t targetDetectRightFront_s8; /* Target detect right front */
  sint8_t targetDetectRightRear_s8; /* Target detect right rear */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_SC_Resume_t;

typedef struct Request_SC_Status_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_SC_Status_t;

typedef struct Response_SC_Status_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t targetInit_s8; /* Target Init */
  sint8_t targetLimitFront_s8; /* Target Limit Front */
  sint8_t targetLimitRear_s8; /* Target Limit Rear */
  sint8_t targetDetectLeftFront_s8; /* Target detect left front */
  sint8_t targetDetectLeftRear_s8; /* Target detect left rear */
  sint8_t targetDetectRightFront_s8; /* Target detect right front */
  sint8_t targetDetectRightRear_s8; /* Target detect right rear */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_SC_Status_t;

typedef struct Request_SC_Debug_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_SC_Debug_t;

typedef struct Response_SC_Debug_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  float32_t deltaX_f32; /* deltaX_f32 */
  float32_t deltaY_f32; /* deltaY_f32 */
  float32_t deltaZ_f32; /* deltaZ_f32 */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorState_u32; /* errorState_e */
  sint8_t targetInit_s8; /* Target Init */
  sint8_t targetLimitFront_s8; /* Target Limit Front */
  sint8_t targetLimitRear_s8; /* Target Limit Rear */
  sint8_t targetDetectLeftFront_s8; /* Target detect left front */
  sint8_t targetDetectLeftRear_s8; /* Target detect left rear */
  sint8_t targetDetectRightFront_s8; /* Target detect right front */
  sint8_t targetDetectRightRear_s8; /* Target detect right rear */
  sint8_t reserved_s8_s8; /* Reserved */
} Response_SC_Debug_t;

typedef struct Request_TEOL_Start_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_TEOL_Start_t;

typedef struct Response_TEOL_Start_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_TEOL_Start_t;

typedef struct Request_TEOL_Stop_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_TEOL_Stop_t;

typedef struct Response_TEOL_Stop_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_TEOL_Stop_t;

typedef struct Request_TEOL_Pause_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_TEOL_Pause_t;

typedef struct Response_TEOL_Pause_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_TEOL_Pause_t;

typedef struct Request_TEOL_Resume_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_TEOL_Resume_t;

typedef struct Response_TEOL_Resume_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_TEOL_Resume_t;

typedef struct Request_TEOL_Status_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_TEOL_Status_t;

typedef struct Response_TEOL_Status_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_TEOL_Status_t;

typedef struct Request_TEOL_Debug_s
{
  uint8_t CamID_u8; /* Cam Identifier */
} Request_TEOL_Debug_t;

typedef struct Response_TEOL_Debug_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint8_t CamID_u8; /* Cam Identifier */
  float32_t deltaPitch_f32; /* deltaPitch_f32 */
  float32_t deltaYaw_f32; /* deltaYaw_f32 */
  float32_t deltaRoll_f32; /* deltaRoll_f32 */
  uint32_t validFeatures_u32; /* Valid features */
  uint32_t ignoredFeatures_u32; /* Ignored features */
  sint32_t invalidFeatures_s32; /* Invalid features */
  uint32_t algoState_u32; /* algoState_e */
  uint32_t errorCode_u32; /* errorCode_e */
} Response_TEOL_Debug_t;

typedef struct StateBits_s
{
  uint8_t PdcFrontRight_u8 : 3; /* FrontRight */
  uint8_t PdcRearRight_u8 : 3; /* RearRight */
  uint8_t RctaRight_u8 : 2;
  uint8_t PdcFrontLeft_u8 : 3; /* FrontLeft */
  uint8_t PdcRearLeft_u8 : 3; /* RearLeft */
  uint8_t RctaLeft_u8 : 2;
  uint8_t PdcFrontRightCenter_u8 : 3;
  uint8_t PdcFrontLeftCenter_u8 : 3; /* RearLeftCenter */
  uint8_t WheelSlipFrontRight_u8 : 1;
  uint8_t WheelSlipFrontLeft_u8 : 1;
  uint8_t PdcRearRightCenter_u8 : 3; /* RearRightCenter */
  uint8_t PdcRearLeftCenter_u8 : 3; /* FrontLeftCenter */
  uint8_t WheelSlipRearRight_u8 : 1;
  uint8_t WheelSlipRearLeft_u8 : 1;
  uint8_t PdcBoundFrontLeft_u8 : 1; /* PdcBoundFrontLeft */
  uint8_t PdcBoundFrontLeftCenter_u8 : 1; /* PdcBoundFrontLeftCenter */
  uint8_t PdcBoundFrontRightCenter_u8 : 1;
  uint8_t PdcBoundFrontRight_u8 : 1;
  uint8_t PdcBoundRearLeft_u8 : 1; /* PdcBoundRearLeft */
  uint8_t PdcBoundRearLeftCenter_u8 : 1; /* PdcBoundRearLeftCenter */
  uint8_t PdcBoundRearRightCenter_u8 : 1;
  uint8_t PdcBoundRearRight_u8 : 1;
} StateBits_t;

typedef struct VehicleStateRequest_s
{
  float32_t VehicleLevel_f32; /* VehicleLevel */
  float32_t SteeringAngle_f32; /* SteeringAngel */
  float32_t SteeringWheelAngle_f32; /* SteeringWheelAngel */
  uint8_t DayNightStatus_u8; /* dayNightStatus */
  uint8_t GearInformation_u8; /* GearInformation */
  uint8_t LanguageId_u8; /* LanguageInformation */
  uint8_t DoorStatus_u8; /* DoorStatus */
  float32_t VehSpeed_f32;
  StateBits_t stateBits_s; /* StateBits_s */
  uint8_t Reserved2_u8;
  uint8_t Reserved3_u8;
  sint8_t VehiclePitch_s8;
  sint8_t VehicleRoll_s8;
  uint16_t Crc16_u16; /* Crc16 */
} VehicleStateRequest_t;

typedef struct VehicleStateResponse_s
{
  uint8_t ResponseCode_u8; /* ResponseCode */
  uint16_t Crc16_u16; /* Crc16 */
} VehicleStateResponse_t;

typedef struct TestAllDataTypes_s
{
  uint8_t Test_u8;
  uint16_t Test_u16;
  uint32_t Test_u32;
  uint64_t Test_u64;
  sint8_t Test_s8;
  sint16_t Test_s16;
  sint32_t Test_s32;
  sint64_t Test_s64;
  float32_t Test_f32;
} TestAllDataTypes_t;


/*  --- Message Type to Index Mapping --- */
typedef enum MessageIndex_e
{
	e_SvsToTHADet_tIndx,
	e_ScreenRequestIndx,
	e_ME_VehInp_to_IpcSignals_tIndx,
	e_Detection_Inputs_from_TRSC_tIndx,
	e_SSM_2_0_CoreStatusIndx,
	e_SSM_2_1_CoreStatusIndx,
	e_SSM_SystemStateIndx,
	e_CalDataProvider_MPU_1_0_DefIndx,
	e_FunctionalSettingsNVMToSVSCalibSM_tIndx,
	e_TbSVS_e_DiagMgrOutputToSVSCamCalibSMIndx,
	e_TbTHASmVc_FeatureOutputs_tIndx,
	e_IFPAInfoToPLDIndx,
	e_IKinematicDataIndx,
	e_TbAP_DriveAssistStatOut_tIndx,
	e_FID_STRUCT_QM_Indx,
	e_FID_STRUCT_BIndx,
	e_US_S_BlockageBit_tIndx ,
	e_US_S_USSErrorDiagData_tIndx,
	e_THARelated_ScreenReq_tIndx,
	e_ME_Proxi_to_IpcSignals_tIndx ,
	e_TRSCDebug_ScrReq_tIndx,
	e_ME_CanDebugRIDStatus_tIndx,
	e_THA_Calibration_data_MPU1_0_tIndx,
	e_APA_Calibration_data_MPU1_0_tIndx,
	e_LMD_Calibration_data_tIndx,
	e_TRSC_Calibration_data_MPU1_0_tIndx,
  e_TRSC_CalibrationClear_tIndx,
  e_PerformanceStatsEnable_tIndx,
  e_CamHotplugStatus_tIndx,
	e_Message_count
} MessageIndex_t;


/*  --- Message Type to Index Mapping --- */
typedef enum MessageIndexTx_e
{
  e_ScreenResponseIndx,
  e_ErrorMgr_ErrorCommPack_QNX_QMIndx,
  e_ErrorMgr_ErrorCommPack_QNX_BIndx,
  e_TRSC_Inputs_from_TrailerDetection_tIndx,
  e_MeDLD_e_RrCamSts_tIndx,
  e_QNX_State_QNXIndx,
  e_TbSVS_e_SVSCalibSMToAlgoCamCalib_tIndx,
  e_TbSVS_e_SVSCalibAlgoToSMCamCalib_tIndx,
  e_TbSVS_S_SVSCamCurrentCalibDataToNVM_tIndx,
  e_TbSVS_S_SVSCamOCCalibDataToNVM_tIndx,
  e_TbSVS_S_SVSCamSCCalibDataToNVM_tIndx,
  e_TbSVS_S_SVSCamEOLCalibDataToNVM_tIndx,
  e_TbSVS_e_SVSOutputToDiagMgrCamCalibIndx,
  e_JobTHADetOutput_tIndx,
  e_IJobPLDOutputIndx,
  e_IParkingSlotInformationIndx,
  e_MOT_OutputIndx,
  e_Svs_CamEepromDataArrayIndx,
  e_LMD_Outputs_CVPAMFDData2_tIndx,
  e_TrailerDetection_Output_DID_tIndx,
  e_LMD_Lane_Outputs_sIndx,
  e_TbSVS_e_SVSCalibSMToHmi_tIndx,
  e_ME_Proxi_MPU1_0_to_MCU1_0_tIndx,
  e_TrailerDetection_Output_HMI_tIndx,
  e_JobDLDOutput_tIndx,
  e_Error_Fault_MPU1_0_tIndx,
  e_RunTimeStats_MPU1_0_tIndx,
  e_MessageTx_count
} MessageIndexTx_t;


typedef struct MessageStatus_s
{
  uint32_t messageID_u32;
  bool_t  sender_Status_b;
  bool_t  receiver_Status_b;
} MessageStatus_t;

/* Advances data pointer and returns the message ID */
ME_INLINE IpcMsgId_t getMessageId_e(const uint8_t* b_data_pu8, uint32_t* b_IDLength_pu32)
{
	IpcMsgId_t v_Enum_e = e_IpcMsgId_data_UnknownMsg_t;
  uint32_t v_Index_u32 = 0;
  
  /* Read Id from Data Pointer */
  //v_Enum_e = static_cast<IpcMsgId_t>(ME_DataSerializer_Read_u16(b_data_pu8, &v_Index_u32, true));
  uint16_t v_DataId_u16 = ME_DataSerializer_Read_u16(b_data_pu8, &v_Index_u32, true);
  
  if(v_DataId_u16 <= e_IpcMsgId_MAX_COUNT)
  {
    v_Enum_e = static_cast<IpcMsgId_t>(v_DataId_u16);
  }
  if (NULL != b_IDLength_pu32)
  {
    if(e_IpcMsgId_data_UnknownMsg_t != v_Enum_e)
    {
      *b_IDLength_pu32 = v_Index_u32;
    }
    else
    {
      *b_IDLength_pu32 = 0;
    }
  }
  
  return v_Enum_e;
}

/*  --- AddHeaderToMessage --- */
/*  --- Usage: &array[0] and for further read/write use array[2] index 2 is returned by this function because we write 2 bytes in this protocol --- */
ME_INLINE uint32_t addHeaderToMessage_u32(uint8_t* b_Data_pc, IpcMsgId_t i_MessageID_t)
{
  uint32_t v_Index_u32 = 0;
  
  ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, (uint16_t)i_MessageID_t, true);
  
  return v_Index_u32;
};

/*  --- Read Functions --- */
/*ME_INLINE bool_t readVehInpAdapter_opVehSignals_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32,  VehInpAdapter_opVehSignals_t* b_VehInpAdapter_opVehSignals_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    //currently the deserilaization is simple as aggreed.

    memcpy( b_VehInpAdapter_opVehSignals_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}*/

/*  --- Read Functions --- */
/*ME_INLINE bool_t readTbVCAN_e_BusInputToSVSCamCalibSM_t(const VehInpAdapter_opVehSignals_t* i_Data_pc, uint32_t i_DataLength_u32,  TbVCAN_e_BusInputToSVSCamCalibSM_t* b_TbVCAN_e_BusInputToSVSCamCalibSM_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
     //feature/app to get the can signals from global structure.
#if 0
	b_TbVCAN_e_BusInputToSVSCamCalibSM_ps->IeVCU_e_GearSig = static_cast<TeSVS_e_GearPosCamCalib> (i_Data_pc->dt_VCU_0x214.VCU_GearSig);
	b_TbVCAN_e_BusInputToSVSCamCalibSM_ps->IeBCM_e_PwrMod = static_cast<TeSVS_e_PowerModeCamCalib>(i_Data_pc->dt_BCM_0x333.BCM_PwrMod);
	b_TbVCAN_e_BusInputToSVSCamCalibSM_ps->IeBCM_e_LeFrntDoorSts = static_cast<TeSVS_e_DoorStsCamCalib>(i_Data_pc->dt_BCM_0x343.BCM_LeFrntDoorSts);
	b_TbVCAN_e_BusInputToSVSCamCalibSM_ps->IeBCM_e_RiFrntDoorSts =  static_cast<TeSVS_e_DoorStsCamCalib>(i_Data_pc->dt_BCM_0x343.BCM_RiFrntDoorSts);
	b_TbVCAN_e_BusInputToSVSCamCalibSM_ps->IeBCM_e_RiReDoorSts = static_cast<TeSVS_e_DoorStsCamCalib>(i_Data_pc->dt_BCM_0x343.BCM_RiReDoorSts);
	b_TbVCAN_e_BusInputToSVSCamCalibSM_ps->IeBCM_e_LeReDoorSts = static_cast<TeSVS_e_DoorStsCamCalib>(i_Data_pc->dt_BCM_0x343.BCM_LeReDoorSts);
	b_TbVCAN_e_BusInputToSVSCamCalibSM_ps->IePLGM_e_TrSts = static_cast<TeSVS_e_DoorStsCamCalib>(i_Data_pc->dt_PLGM_0x471.PLGM_TrSts);
	b_TbVCAN_e_BusInputToSVSCamCalibSM_ps->IeBCM_e_FrntHoodLidSts = static_cast<TeSVS_e_DoorStsCamCalib>(i_Data_pc->dt_BCM_0x343.BCM_FrntHoodLidSts);

	b_TbVCAN_e_BusInputToSVSCamCalibSM_ps->IeESP_kph_VehSpd = i_Data_pc->dt_ESP_0x318.ESP_VehSpd;
	b_TbVCAN_e_BusInputToSVSCamCalibSM_ps->IeEPS_deg_SteerWhlAgSig = i_Data_pc->dt_EPS_0x1C2.EPS_SteerWhlAgSig;
#endif

  }

  return v_Valid_b;
}
*/
ME_INLINE bool_t readIKinematicData_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32,  IKinematicData_t* b_IKinematicData_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    //currently the deserilaization is simple as aggreed.

    memcpy( b_IKinematicData_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}
/*
ME_INLINE bool_t readIFPAInfoToPLD_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32,  IFPAInfoToPLD_t* b_IFPAInfoToPLD_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    //currently the deserilaization is simple as aggreed.

    memcpy( b_IFPAInfoToPLD_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}
*/
// ME_INLINE bool_t readTbADAS_LSFeatureOutputs_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32,  TbADAS_LSFeatureOutputs_T* b_TbADAS_LSFeatureOutputs_ps)
// {
//   bool_t v_Valid_b = (i_DataLength_u32 > 0);

//   if (true == v_Valid_b)
//   {
//     uint32_t v_Index_u32 = 0;
//     //currently the deserilaization is simple as aggreed.

//     memcpy( b_TbADAS_LSFeatureOutputs_ps, i_Data_pc,i_DataLength_u32);

//   }

//   return v_Valid_b;
// }

// ME_INLINE bool_t readLwSpdStateToPLD_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32,  LwSpdStateToPLD_t* b_LwSpdStateToPLD_ps)
// {
//   bool_t v_Valid_b = (i_DataLength_u32 > 0);

//   if (true == v_Valid_b)
//   {
//     uint32_t v_Index_u32 = 0;
//     //currently the deserilaization is simple as aggreed.

//     memcpy( b_LwSpdStateToPLD_ps, i_Data_pc,i_DataLength_u32);

//   }

//   return v_Valid_b;
// }


ME_INLINE bool_t readErrorneousResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ErrorneousResponse_t* b_ErrorneousResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_ErrorneousResponse_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ErrorneousResponse_ps->ErrorMessageID_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}


/*
ME_INLINE bool_t readDmsIpcCryptoRespType_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, DmsIpcCryptoRespType_t* b_DmsIpcCryptoRespType_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 1);

  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    memcpy( b_DmsIpcCryptoRespType_ps, i_Data_pc,i_DataLength_u32);
  }

  return v_Valid_b;
}

ME_INLINE bool_t readDmsIpcCanIpSgnlType_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, DmsIpcCanIpSgnlType_t* b_DmsIpcCanIpSgnlType_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 1);

  if (true == v_Valid_b)
  {
    memcpy( b_DmsIpcCanIpSgnlType_ps, i_Data_pc,i_DataLength_u32);
  }

  return v_Valid_b;
}

ME_INLINE bool_t readDmsIpcCryptoStartupData_b(const DMSCryptoKey_t* i_Data_pc,  uint32_t i_DataLength_u32, DmsIpcCryptoRespType_t* b_DmsIpcCryptoRespType_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 1);

  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    memcpy( b_DmsIpcCryptoRespType_ps, i_Data_pc, i_DataLength_u32);
  }

  return v_Valid_b;
}

ME_INLINE bool_t readMCU_1_0_toA72_StartupData_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MCU_1_0_toA72_StartupData_t* b_MCU_1_0_toA72_StartupData_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 1);

  if (true == v_Valid_b)
  {
    memcpy( b_MCU_1_0_toA72_StartupData_ps, i_Data_pc,i_DataLength_u32);


  }

  return v_Valid_b;
}
*/
ME_INLINE bool_t readBootStateRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, BootStateRequest_t* b_BootStateRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 2);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_BootStateRequest_ps->BootState_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_BootStateRequest_ps->CamDeserSerEnable_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readBootStateResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, BootStateResponse_t* b_BootStateResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_BootStateResponse_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_BootStateResponse_ps->VideoSubSystemState_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_BootStateResponse_ps->CamDeserSerEnableComplete_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readApplyConfigRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ApplyConfigRequest_t* b_ApplyConfigRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 4);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_ApplyConfigRequest_ps->variantID_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_ApplyConfigRequest_ps->varintConfig_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readApplyConfigResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ApplyConfigResponse_t* b_ApplyConfigResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 5);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_ApplyConfigResponse_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ApplyConfigResponse_ps->variantID_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_ApplyConfigResponse_ps->varintConfig_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readErrorStateRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ErrorStateRequest_t* b_ErrorStateRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_ErrorStateRequest_ps->ErrorCategory_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readErrorStateResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ErrorStateResponse_t* b_ErrorStateResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 32);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_ErrorStateResponse_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ErrorStateResponse_ps->ErrorCategory_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < c_ErrDataSize_u32; ++v_I_u32)
    {
      b_ErrorStateResponse_ps->ErrData_au8[v_I_u32] = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    }
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readKeepAliveRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, KeepAliveRequest_t* b_KeepAliveRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 4);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_KeepAliveRequest_ps->Counter_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

/*
ME_INLINE bool_t readKeepAliveResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, KeepAliveResponse_t* b_KeepAliveResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 5);

  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;

    b_KeepAliveResponse_ps->FrameID_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }

  return v_Valid_b;
}
*/

ME_INLINE bool_t readTestPatternRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, TestPatternRequest_t* b_TestPatternRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 2);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_TestPatternRequest_ps->CameraID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TestPatternRequest_ps->RequestedTestPattern_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readTestPatternResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, TestPatternResponse_t* b_TestPatternResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_TestPatternResponse_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TestPatternResponse_ps->CameraID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TestPatternResponse_ps->RequestedTestPattern_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readInformationRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, InformationRequest_t* b_InformationRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 2);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_InformationRequest_ps->Requested_Information_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_InformationRequest_ps->Payload_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readInformationResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, InformationResponse_t* b_InformationResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_InformationResponse_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_InformationResponse_ps->Current_Information_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < c_PayloadSize_u32; ++v_I_u32)
    {
      b_InformationResponse_ps->Payload_au8[v_I_u32] = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    }
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_Control_ErrorState_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_Control_ErrorState_t* b_Request_Control_ErrorState_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_Control_ErrorState_ps->ErrorCategory_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Control_ErrorState_ps->Error_Data_No_Video_Output_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Control_ErrorState_ps->Error_Data_Front_Cam_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Control_ErrorState_ps->Error_Data_Left_Cam_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Control_ErrorState_ps->Error_Data_Rear_Cam_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Control_ErrorState_ps->Error_Data_Right_Cam_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Control_ErrorState_ps->Error_Data_Bed_Cam_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Control_ErrorState_ps->hold_time_0_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_Control_ErrorState_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_Control_ErrorState_t* b_Response_Control_ErrorState_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_Control_ErrorState_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readControlRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ControlRequest_t* b_ControlRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 5);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_ControlRequest_ps->RequestedControl_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ControlRequest_ps->Payload_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readControlResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ControlResponse_t* b_ControlResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_ControlResponse_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readMiscRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MiscRequest_t* b_MiscRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 4);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_MiscRequest_ps->TRANSTAT_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MiscRequest_ps->GDEC_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MiscRequest_ps->CANCEL_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MiscRequest_ps->TORQUE_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readMiscResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MiscResponse_t* b_MiscResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_MiscResponse_ps->Response_Code_MiscResponse_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readMCU_TRAGateway1Request_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MCU_TRAGateway1Request_t* b_MCU_TRAGateway1Request_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 6);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    uint8_t v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_B_P_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_B_R_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_B_D_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_B_N_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.REV_SW_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.TraActiveLight_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.GearSignal_bit_6_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.GearSignal_bit_7_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_EPSFAIL_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_EPSSTS0_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_EPSACT_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_EPSSYS_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.EPSdata_bit_4_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.EPSdata_bit_5_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.EPSdata_bit_6_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.EPSdata_bit_7_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    b_MCU_TRAGateway1Request_ps->PCAN_VWPSUMFL_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway1Request_ps->PCAN_VWPSUMFR_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway1Request_ps->PCAN_VWPSUMRL_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway1Request_ps->PCAN_VWPSUMRR_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readMCU_TRAGateway1Response_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MCU_TRAGateway1Response_t* b_MCU_TRAGateway1Response_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_MCU_TRAGateway1Response_ps->Response_Code_MCU_TRAGateway1_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readMCU_TRAGateway2Request_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MCU_TRAGateway2Request_t* b_MCU_TRAGateway2Request_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_MCU_TRAGateway2Request_ps->PCAN_VXFR_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway2Request_ps->PCAN_VXFL_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway2Request_ps->PCAN_VXRR_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway2Request_ps->PCAN_VXRL_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readMCU_TRAGateway2Response_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MCU_TRAGateway2Response_t* b_MCU_TRAGateway2Response_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_MCU_TRAGateway2Response_ps->Response_Code_MCU_TRAGateWay2_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readMCU_TRAGateway3Request_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MCU_TRAGateway3Request_t* b_MCU_TRAGateway3Request_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_MCU_TRAGateway3Request_ps->PCAN_SP1_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    uint8_t v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 = ((v_BitFieldData_u8 & (1 << 0)) << 0);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 1)) << 0);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 2)) << 0);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 3)) << 0);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 4)) << 0);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 5)) << 0);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 6)) << 0);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 7)) << 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 0)) << 8);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 1)) << 8);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 2)) << 8);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 |= ((v_BitFieldData_u8 & (1 << 3)) << 8);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSAS_s16 = ((v_BitFieldData_u8 & (1 << 4)) >> 4);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSAS_s16 |= ((v_BitFieldData_u8 & (1 << 5)) >> 4);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSAS_s16 |= ((v_BitFieldData_u8 & (1 << 6)) >> 4);
    b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSAS_s16 |= ((v_BitFieldData_u8 & (1 << 7)) >> 4);
    
    b_MCU_TRAGateway3Request_ps->PCAN_VSC_YAW0_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway3Request_ps->PCAN_SSAV_s16 = ME_DataSerializer_Read_s16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readMCU_TRAGateway3Response_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MCU_TRAGateway3Response_t* b_MCU_TRAGateway3Response_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_MCU_TRAGateway3Response_ps->ResponseCode_TRAGateway3_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway3Response_ps->TAD_angle_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway3Response_ps->Confidence_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway3Response_ps->tadAngleRate_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway3Response_ps->frameNumber_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readMCU_TRAGateway4Request_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MCU_TRAGateway4Request_t* b_MCU_TRAGateway4Request_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 2);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_MCU_TRAGateway4Request_ps->PCAN_EST2_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readMCU_TRAGateway4Response_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, MCU_TRAGateway4Response_t* b_MCU_TRAGateway4Response_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_MCU_TRAGateway4Response_ps->Response_Code_MCU_TRAGateway4_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway4Response_ps->TrailerBeamLength_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway4Response_ps->HitchLength_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway4Response_ps->TadState_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_MCU_TRAGateway4Response_ps->TRATSA_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

#ifdef USE_REQUEST_AND_RESPONSE

ME_INLINE bool_t readScreenRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ScreenRequest_t* b_ScreenRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 38);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_ScreenRequest_ps->Version_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->ViewID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->ZoomFactor_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->ColorCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->NaviScrMsg_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->ToggleCount_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    uint8_t v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.LayoutPartView_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.LayoutFullView_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.LayoutMtmView_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.LayoutConfirmView_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconGdlFrontCorner_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconGdlFrontWheel_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconGdlRearStatic_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconGdlRearDistance_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.IconGdlRearWheelDir_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconClearanceSonar_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconSoundOn_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconSoundOff_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconRcdOff_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconWarn_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconBrake_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconBrakeSwitch_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.IconBrakePress_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.Btn10kphDis_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonZoom_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonDblZoom_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonUnZoom_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.BtnExit_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFrontOn_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFrontOff_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearOn_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearOff_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFronSplitOn_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFrontSplitOff_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearSplitOn_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearSplitOff_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmAuxOn_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmAuxOff_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmCargoOn_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmCargoOff_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmTopOn_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmTopOnLock_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmTopOff_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmTopOffLock_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmViewEnable_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmViewDisable_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.ButtonTraOn_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonTraOff_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonTraDisable_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonTowOn_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonTowOff_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPrevView_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPanBar_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPanLeArrow_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPanRiArrow_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonAutoStartLock_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonAutoStartOn_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonAutoStartOff_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconWheelSlip_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonTowDisable_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmTopDisable_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconAccelerationPressed_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmFrontSideOn_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmFrontSideOff_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmUnderfloorSideOn_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmUnderfloorSideOff_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearSideOn_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearSideOff_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearWideOn_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearWideOff_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAuxOn_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAuxOff_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmViewEnable_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmViewDisable_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconGdlSelectLocked_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconInclinometerDisable_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconInclinometer_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAutoStartOn_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAutoStartOff_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonConfirmViewFooter_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.TextPksbUnavailable_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconTrlSwingLeft_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconTrlSwingRight_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconRearCrossTrafficAlertTop_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineRearDistancePrimary_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineFrontCornerTop_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineFrontPredictTop_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineRearDistanceTop_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineRearDynamicTop_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineFrontBackwardTop_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineRearParkTop_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineFrontCornerPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineFrontSplitPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineRearStaticDistRedPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineRearDynamicPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineRearStaticPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineRearParkPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineTowPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineConfirmTrailerMarkPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmFrontDistance_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmFrontMax_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmFrontDynamic_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmSideStatic_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmFrontOverallDynamic_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmRearOverallDynamic_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.GuidelineRearStaticDistBluePrimary_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFrontDisable_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearDisable_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFrontSplitDisable_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconMtmUnderfloorVehicleContour_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.TextCheckSurrounding_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.TextTraMessages_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.BtnTraModeDisable_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconRearCrossTrafficAlertPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearSplitDisable_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmAuxDisable_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonPvmCargoDisable_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonFrontGdlSelectDisable_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.ButtonRearGdlSelectDisable_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonAutoStartDisable_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmFrontSideDisable_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmUnderfloorSideDisable_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearSideDisable_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearWideDisable_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAuxDisable_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAutoStartDisable_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->OverlayBits_s.IconClearanceSonarGuidance_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.DealScrManualAdjust_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.DealScrCameraCheck_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconTrlSwingText_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.VehicleColorMenu_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.IconClearanceSonarTopView_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.Bit126_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenRequest_ps->OverlayBits_s.Bit127_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    b_ScreenRequest_ps->ButtonId_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->ButtonState_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->ScreenID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < c_ReqScreenDataSize_u32; ++v_I_u32)
    {
      b_ScreenRequest_ps->ScreenData_au8[v_I_u32] = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    }
    b_ScreenRequest_ps->ButtonIdReset_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenRequest_ps->CRC16_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}
#else
ME_INLINE bool_t readScreenRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ScreenRequest_t* b_ScreenRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    //currently the deserilaization is simple as aggreed.
    memcpy( b_ScreenRequest_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}

#endif

#ifdef USE_REQUEST_AND_RESPONSE
ME_INLINE bool_t readScreenResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, ScreenResponse_t* b_ScreenResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 39);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_ScreenResponse_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->Version_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->ViewID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->ZoomFactor_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->ColorCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->NaviScrMsg_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->ToggleCount_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    uint8_t v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.LayoutPartView_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.LayoutFullView_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.LayoutMtmView_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.LayoutConfirmView_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconGdlFrontCorner_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconGdlFrontWheel_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconGdlRearStatic_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconGdlRearDistance_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.IconGdlRearWheelDir_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconClearanceSonar_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconSoundOn_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconSoundOff_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconRcdOff_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconWarn_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconBrake_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconBrakeSwitch_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.IconBrakePress_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.Btn10kphDis_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonZoom_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonDblZoom_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonUnZoom_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.BtnExit_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFrontOn_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFrontOff_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearOn_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearOff_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFronSplitOn_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFrontSplitOff_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearSplitOn_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearSplitOff_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmAuxOn_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmAuxOff_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmCargoOn_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmCargoOff_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmTopOn_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmTopOnLock_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmTopOff_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmTopOffLock_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmViewEnable_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmViewDisable_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.ButtonTraOn_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonTraOff_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonTraDisable_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonTowOn_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonTowOff_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPrevView_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPanBar_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPanLeArrow_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPanRiArrow_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonAutoStartLock_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonAutoStartOn_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonAutoStartOff_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconWheelSlip_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonTowDisable_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmTopDisable_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconAccelerationPressed_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmFrontSideOn_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmFrontSideOff_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmUnderfloorSideOn_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmUnderfloorSideOff_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearSideOn_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearSideOff_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearWideOn_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearWideOff_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAuxOn_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAuxOff_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmViewEnable_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmViewDisable_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconGdlSelectLocked_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconInclinometerDisable_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconInclinometer_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAutoStartOn_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAutoStartOff_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonConfirmViewFooter_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.TextPksbUnavailable_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconTrlSwingLeft_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconTrlSwingRight_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconRearCrossTrafficAlertTop_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineRearDistancePrimary_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineFrontCornerTop_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineFrontPredictTop_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineRearDistanceTop_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineRearDynamicTop_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineFrontBackwardTop_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineRearParkTop_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineFrontCornerPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineFrontSplitPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineRearStaticDistRedPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineRearDynamicPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineRearStaticPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineRearParkPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineTowPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineConfirmTrailerMarkPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmFrontDistance_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmFrontMax_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmFrontDynamic_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmSideStatic_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmFrontOverallDynamic_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmRearOverallDynamic_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.GuidelineRearStaticDistBluePrimary_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFrontDisable_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearDisable_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFrontSplitDisable_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconMtmUnderfloorVehicleContour_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.TextCheckSurrounding_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.TextTraMessages_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.BtnTraModeDisable_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconRearCrossTrafficAlertPrimary_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearSplitDisable_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmAuxDisable_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonPvmCargoDisable_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonFrontGdlSelectDisable_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.ButtonRearGdlSelectDisable_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonAutoStartDisable_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmFrontSideDisable_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmUnderfloorSideDisable_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearSideDisable_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearWideDisable_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAuxDisable_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAutoStartDisable_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->OverlayBits_s.IconClearanceSonarGuidance_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.DealScrManualAdjust_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.DealScrCameraCheck_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconTrlSwingText_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.VehicleColorMenu_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.IconClearanceSonarTopView_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.Bit126_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_ScreenResponse_ps->OverlayBits_s.Bit127_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    b_ScreenResponse_ps->ButtonId_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->ButtonState_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->ScreenID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < c_ResScreenDataSize_u32; ++v_I_u32)
    {
      b_ScreenResponse_ps->ScreenData_au8[v_I_u32] = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    }
    b_ScreenResponse_ps->ButtonIdReset_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_ScreenResponse_ps->CRC16_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

#endif

/*
ME_INLINE bool_t readVehSpdWhlSpdData_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, VehSpdWhlSpdData_t* b_VehSpdWhlSpdData_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    //currently the deserilaization is simple as aggreed.
    memcpy( b_VehSpdWhlSpdData_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}
*/

/*ME_INLINE bool_t readCrsTrfData_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, CrsTrfData_t* b_CrsTrfData_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    //currently the deserilaization is simple as aggreed.
    memcpy( b_CrsTrfData_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}*/

#ifdef ME_PLATFORM_FISKER

ME_INLINE bool_t readPrkSns_AreaInfo_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, PrkSns_AreaInfo_t* b_PrkSns_AreaInfo_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    //currently the deserilaization is simple as aggreed.
    memcpy( b_PrkSns_AreaInfo_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}
ME_INLINE bool_t readSSM_SystemState_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, SSM_SystemState_t* b_SSM_SystemState_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    //currently the deserilaization is simple as aggreed.
    memcpy( b_SSM_SystemState_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}


ME_INLINE bool_t readCalDataProvider_MPU_1_0_Def_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, CalDataProvider_MPU_1_0_Def_t* b_CalDataProvider_MPU_1_0_Def_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    //currently the deserilaization is simple as aggreed.
    memcpy( b_CalDataProvider_MPU_1_0_Def_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}
#endif
ME_INLINE bool_t readTbSVS_e_DiagMgrOutputToSVSCamCalibSM_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t* b_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    //currently the deserilaization is simple as aggreed.
    memcpy( b_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}

/*ME_INLINE bool_t readTbSVS_e_NVMToCalibSTMNVMCamCalibSM_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, TbSVS_e_NVMToCalibSTMNVMCamCalibSM_t* b_TbSVS_e_NVMToCalibSTMNVMCamCalibSM_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    //currently the deserilaization is simple as aggreed.
    memcpy( b_TbSVS_e_NVMToCalibSTMNVMCamCalibSM_ps, i_Data_pc,i_DataLength_u32);

  }

  return v_Valid_b;
}*/

ME_INLINE bool_t readTRA_Data_Request_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, TRA_Data_Request_t* b_TRA_Data_Request_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 16);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_TRA_Data_Request_ps->Emptiness1_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->Emptiness2_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->Emptiness3_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_b_ClrTrlrCal_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_e_TADTrackStat_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_b_TRAACT_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_e_TRAStrCtrlStat_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_e_TrlrActStat_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_e_TrlrCalStat_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_e_TrlrID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_b_RqstArmVlidPar_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_e_TrlrAgeStat_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_deg_MaxSWR_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Request_ps->IeTRIO_deg_MaxTsaAllwd_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readTRA_Data_Response_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, TRA_Data_Response_t* b_TRA_Data_Response_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 32);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_TRA_Data_Response_ps->Emptiness1_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->Emptiness2_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->Emptiness3_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->Emptiness4_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_e_TrlrDimEstStat_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_e_StrIcon_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_e_TrlrDirIcon_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_e_ArmTrnPrcss_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_e_ArmSaveData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_e_TADAcqStat_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_b_TrlrDataV_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_b_ASRACT_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_deg_TADAngAct_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_deg_TrgtStrAng_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_ddeg_TADAngRateAct_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_deg_TrlrAngTh_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_TRA_Data_Response_ps->IeTRIA_deg_TADAngPred_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_Camera_GetEeprom_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_Camera_GetEeprom_t* b_Request_Camera_GetEeprom_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 10);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_Camera_GetEeprom_ps->v_CameraID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_GetEeprom_ps->v_ReadOffset_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < c_ReservedSize_u32; ++v_I_u32)
    {
      b_Request_Camera_GetEeprom_ps->v_Reserved_au8[v_I_u32] = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    }
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_Camera_GetEeprom_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_Camera_GetEeprom_t* b_Response_Camera_GetEeprom_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 41);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_Camera_GetEeprom_ps->v_ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < c_DataSize_u32; ++v_I_u32)
    {
      b_Response_Camera_GetEeprom_ps->v_data_au8[v_I_u32] = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    }
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_Camera_SetRegister_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_Camera_SetRegister_t* b_Request_Camera_SetRegister_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 6);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_Camera_SetRegister_ps->CameraID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_SetRegister_ps->DeviceID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_SetRegister_ps->RegisterAddress_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_SetRegister_ps->RegisterValue_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_Camera_SetRegister_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_Camera_SetRegister_t* b_Response_Camera_SetRegister_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_Camera_SetRegister_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_SetRegister_ps->CameraID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_SetRegister_ps->DeviceID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_Camera_GetRegister_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_Camera_GetRegister_t* b_Request_Camera_GetRegister_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 4);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_Camera_GetRegister_ps->CameraID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_GetRegister_ps->DeviceID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_GetRegister_ps->RegisterAddress_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_Camera_GetRegister_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_Camera_GetRegister_t* b_Response_Camera_GetRegister_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 7);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_Camera_GetRegister_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_GetRegister_ps->CameraID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_GetRegister_ps->DeviceID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_GetRegister_ps->RegisterAddress_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_GetRegister_ps->RegisterValue_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_Camera_Debug_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_Camera_Debug_t* b_Request_Camera_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 5);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_Camera_Debug_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_Debug_ps->DebugEnable_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_Debug_ps->FailsafeBehavior_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_Debug_ps->CamToMemStatusThreshold_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_Debug_ps->CamMinRestartInterval_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_Camera_Debug_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_Camera_Debug_t* b_Response_Camera_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 6);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_Camera_Debug_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_Debug_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_Debug_ps->DebugEnable_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_Debug_ps->FailsafeBehavior_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_Debug_ps->CamToMemStatusThreshold_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_Camera_Debug_ps->CamMinRestartInterval_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_Camera_ApplyCalib_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_Camera_ApplyCalib_t* b_Request_Camera_ApplyCalib_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 25);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_Camera_ApplyCalib_ps->CameraID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_ApplyCalib_ps->Pitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_ApplyCalib_ps->Yaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_ApplyCalib_ps->Roll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_ApplyCalib_ps->X_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_ApplyCalib_ps->Y_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Request_Camera_ApplyCalib_ps->Z_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_Camera_ApplyCalib_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_Camera_ApplyCalib_t* b_Response_Camera_ApplyCalib_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_Camera_ApplyCalib_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_EOL_Start_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_EOL_Start_t* b_Request_EOL_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 18);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_EOL_Start_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_EOL_Start_ps->Algo_Selected_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_EOL_Start_ps->targetX1_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_EOL_Start_ps->targetY1_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_EOL_Start_ps->targetX2_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_EOL_Start_ps->targetY2_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_EOL_Start_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_EOL_Start_t* b_Response_EOL_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 35);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_EOL_Start_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Start_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Start_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Start_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Start_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Start_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Start_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Start_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Start_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Start_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Start_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_EOL_Stop_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_EOL_Stop_t* b_Request_EOL_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_EOL_Stop_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_EOL_Stop_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_EOL_Stop_t* b_Response_EOL_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 35);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_EOL_Stop_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Stop_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Stop_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Stop_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Stop_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Stop_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Stop_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Stop_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Stop_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Stop_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Stop_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_EOL_Pause_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_EOL_Pause_t* b_Request_EOL_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_EOL_Pause_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_EOL_Pause_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_EOL_Pause_t* b_Response_EOL_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 35);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_EOL_Pause_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Pause_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Pause_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Pause_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Pause_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Pause_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Pause_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Pause_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Pause_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Pause_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Pause_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_EOL_Resume_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_EOL_Resume_t* b_Request_EOL_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_EOL_Resume_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_EOL_Resume_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_EOL_Resume_t* b_Response_EOL_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 35);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_EOL_Resume_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Resume_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Resume_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Resume_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Resume_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Resume_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Resume_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Resume_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Resume_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Resume_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Resume_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_EOL_Status_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_EOL_Status_t* b_Request_EOL_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_EOL_Status_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_EOL_Status_ps->Algo_Selected_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_EOL_Status_ps->Read_Offset_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_EOL_Status_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_EOL_Status_t* b_Response_EOL_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 66);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_EOL_Status_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Status_ps->ErrorState_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < c_TargetMarkerDataSize_u32; ++v_I_u32)
    {
      b_Response_EOL_Status_ps->TargetMarkerData_au16[v_I_u32] = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    }
    b_Response_EOL_Status_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Status_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Status_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Status_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Status_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Status_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_EOL_Debug_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_EOL_Debug_t* b_Request_EOL_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_EOL_Debug_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_EOL_Debug_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_EOL_Debug_t* b_Response_EOL_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 75);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_EOL_Debug_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionLeft0_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionLeft1_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionLeft2_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionLeft3_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionLeft4_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionLeft5_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionLeft6_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionLeft7_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionLeft8_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionLeft9_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionRight0_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionRight1_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionRight2_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionRight3_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionRight4_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionRight5_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionRight6_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionRight7_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionRight8_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->markerDetectionRight9_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_EOL_Debug_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_OC_Start_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_OC_Start_t* b_Request_OC_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_OC_Start_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_OC_Start_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_OC_Start_t* b_Response_OC_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_OC_Start_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Start_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Start_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Start_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Start_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Start_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Start_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Start_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Start_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Start_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_OC_Stop_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_OC_Stop_t* b_Request_OC_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_OC_Stop_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_OC_Stop_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_OC_Stop_t* b_Response_OC_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_OC_Stop_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Stop_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Stop_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Stop_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Stop_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Stop_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Stop_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Stop_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Stop_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Stop_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_OC_Pause_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_OC_Pause_t* b_Request_OC_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_OC_Pause_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_OC_Pause_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_OC_Pause_t* b_Response_OC_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_OC_Pause_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Pause_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Pause_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Pause_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Pause_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Pause_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Pause_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Pause_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Pause_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Pause_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_OC_Resume_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_OC_Resume_t* b_Request_OC_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_OC_Resume_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_OC_Resume_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_OC_Resume_t* b_Response_OC_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_OC_Resume_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Resume_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Resume_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Resume_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Resume_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Resume_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Resume_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Resume_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Resume_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Resume_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_OC_Status_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_OC_Status_t* b_Request_OC_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_OC_Status_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_OC_Status_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_OC_Status_t* b_Response_OC_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_OC_Status_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Status_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Status_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Status_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Status_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Status_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Status_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Status_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Status_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Status_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_OC_Debug_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_OC_Debug_t* b_Request_OC_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_OC_Debug_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_OC_Debug_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_OC_Debug_t* b_Response_OC_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_OC_Debug_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Debug_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Debug_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Debug_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Debug_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Debug_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Debug_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Debug_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Debug_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_OC_Debug_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_SC_Start_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_SC_Start_t* b_Request_SC_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 114);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_SC_Start_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->numberOfTargets_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->numberOfSquares1_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetWidth1_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetHeight1_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetX1_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetY1_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetZ1_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->orientation1_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->numberOfSquares2_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetWidth2_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetHeight2_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetX2_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetY2_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetZ2_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->orientation2_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->numberOfSquares3_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetWidth3_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetHeight3_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetX3_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetY3_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetZ3_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->orientation3_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->numberOfSquares4_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetWidth4_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetHeight4_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetX4_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetY4_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->targetZ4_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Request_SC_Start_ps->orientation4_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_SC_Start_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_SC_Start_t* b_Response_SC_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_SC_Start_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->targetInit_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->targetLimitFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->targetLimitRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->targetDetectLeftFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->targetDetectLeftRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->targetDetectRightFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->targetDetectRightRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Start_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_SC_Stop_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_SC_Stop_t* b_Request_SC_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_SC_Stop_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_SC_Stop_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_SC_Stop_t* b_Response_SC_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_SC_Stop_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->targetInit_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->targetLimitFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->targetLimitRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->targetDetectLeftFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->targetDetectLeftRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->targetDetectRightFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->targetDetectRightRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Stop_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_SC_Pause_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_SC_Pause_t* b_Request_SC_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_SC_Pause_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_SC_Pause_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_SC_Pause_t* b_Response_SC_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_SC_Pause_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->targetInit_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->targetLimitFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->targetLimitRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->targetDetectLeftFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->targetDetectLeftRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->targetDetectRightFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->targetDetectRightRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Pause_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_SC_Resume_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_SC_Resume_t* b_Request_SC_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_SC_Resume_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_SC_Resume_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_SC_Resume_t* b_Response_SC_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_SC_Resume_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->targetInit_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->targetLimitFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->targetLimitRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->targetDetectLeftFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->targetDetectLeftRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->targetDetectRightFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->targetDetectRightRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Resume_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_SC_Status_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_SC_Status_t* b_Request_SC_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_SC_Status_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_SC_Status_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_SC_Status_t* b_Response_SC_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_SC_Status_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->targetInit_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->targetLimitFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->targetLimitRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->targetDetectLeftFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->targetDetectLeftRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->targetDetectRightFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->targetDetectRightRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Status_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_SC_Debug_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_SC_Debug_t* b_Request_SC_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_SC_Debug_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_SC_Debug_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_SC_Debug_t* b_Response_SC_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_SC_Debug_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->deltaX_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->deltaY_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->deltaZ_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->errorState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->targetInit_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->targetLimitFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->targetLimitRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->targetDetectLeftFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->targetDetectLeftRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->targetDetectRightFront_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->targetDetectRightRear_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_Response_SC_Debug_ps->reserved_s8_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_TEOL_Start_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_TEOL_Start_t* b_Request_TEOL_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_TEOL_Start_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_TEOL_Start_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_TEOL_Start_t* b_Response_TEOL_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_TEOL_Start_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Start_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Start_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Start_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Start_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Start_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Start_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Start_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Start_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Start_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_TEOL_Stop_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_TEOL_Stop_t* b_Request_TEOL_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_TEOL_Stop_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_TEOL_Stop_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_TEOL_Stop_t* b_Response_TEOL_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_TEOL_Stop_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Stop_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Stop_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Stop_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Stop_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Stop_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Stop_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Stop_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Stop_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Stop_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_TEOL_Pause_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_TEOL_Pause_t* b_Request_TEOL_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_TEOL_Pause_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_TEOL_Pause_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_TEOL_Pause_t* b_Response_TEOL_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_TEOL_Pause_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Pause_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Pause_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Pause_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Pause_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Pause_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Pause_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Pause_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Pause_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Pause_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_TEOL_Resume_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_TEOL_Resume_t* b_Request_TEOL_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_TEOL_Resume_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_TEOL_Resume_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_TEOL_Resume_t* b_Response_TEOL_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_TEOL_Resume_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Resume_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Resume_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Resume_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Resume_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Resume_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Resume_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Resume_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Resume_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Resume_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_TEOL_Status_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_TEOL_Status_t* b_Request_TEOL_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_TEOL_Status_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_TEOL_Status_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_TEOL_Status_t* b_Response_TEOL_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_TEOL_Status_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Status_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Status_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Status_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Status_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Status_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Status_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Status_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Status_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Status_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readRequest_TEOL_Debug_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Request_TEOL_Debug_t* b_Request_TEOL_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Request_TEOL_Debug_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readResponse_TEOL_Debug_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, Response_TEOL_Debug_t* b_Response_TEOL_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_Response_TEOL_Debug_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Debug_ps->CamID_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Debug_ps->deltaPitch_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Debug_ps->deltaYaw_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Debug_ps->deltaRoll_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Debug_ps->validFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Debug_ps->ignoredFeatures_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Debug_ps->invalidFeatures_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Debug_ps->algoState_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_Response_TEOL_Debug_ps->errorCode_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readVehicleStateRequest_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, VehicleStateRequest_t* b_VehicleStateRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 31);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_VehicleStateRequest_ps->VehicleLevel_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->SteeringAngle_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->SteeringWheelAngle_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->DayNightStatus_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->GearInformation_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->LanguageId_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->DoorStatus_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->VehSpeed_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
    uint8_t v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontRight_u8 = ((v_BitFieldData_u8 & (1 << 0)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontRight_u8 |= ((v_BitFieldData_u8 & (1 << 1)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontRight_u8 |= ((v_BitFieldData_u8 & (1 << 2)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearRight_u8 = ((v_BitFieldData_u8 & (1 << 3)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearRight_u8 |= ((v_BitFieldData_u8 & (1 << 4)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearRight_u8 |= ((v_BitFieldData_u8 & (1 << 5)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.RctaRight_u8 = ((v_BitFieldData_u8 & (1 << 6)) >> 6);
    b_VehicleStateRequest_ps->stateBits_s.RctaRight_u8 |= ((v_BitFieldData_u8 & (1 << 7)) >> 6);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeft_u8 = ((v_BitFieldData_u8 & (1 << 0)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeft_u8 |= ((v_BitFieldData_u8 & (1 << 1)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeft_u8 |= ((v_BitFieldData_u8 & (1 << 2)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearLeft_u8 = ((v_BitFieldData_u8 & (1 << 3)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearLeft_u8 |= ((v_BitFieldData_u8 & (1 << 4)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearLeft_u8 |= ((v_BitFieldData_u8 & (1 << 5)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.RctaLeft_u8 = ((v_BitFieldData_u8 & (1 << 6)) >> 6);
    b_VehicleStateRequest_ps->stateBits_s.RctaLeft_u8 |= ((v_BitFieldData_u8 & (1 << 7)) >> 6);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontRightCenter_u8 = ((v_BitFieldData_u8 & (1 << 0)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontRightCenter_u8 |= ((v_BitFieldData_u8 & (1 << 1)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontRightCenter_u8 |= ((v_BitFieldData_u8 & (1 << 2)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeftCenter_u8 = ((v_BitFieldData_u8 & (1 << 3)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeftCenter_u8 |= ((v_BitFieldData_u8 & (1 << 4)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeftCenter_u8 |= ((v_BitFieldData_u8 & (1 << 5)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.WheelSlipFrontRight_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_VehicleStateRequest_ps->stateBits_s.WheelSlipFrontLeft_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearRightCenter_u8 = ((v_BitFieldData_u8 & (1 << 0)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearRightCenter_u8 |= ((v_BitFieldData_u8 & (1 << 1)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearRightCenter_u8 |= ((v_BitFieldData_u8 & (1 << 2)) << 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearLeftCenter_u8 = ((v_BitFieldData_u8 & (1 << 3)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearLeftCenter_u8 |= ((v_BitFieldData_u8 & (1 << 4)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.PdcRearLeftCenter_u8 |= ((v_BitFieldData_u8 & (1 << 5)) >> 3);
    b_VehicleStateRequest_ps->stateBits_s.WheelSlipRearRight_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_VehicleStateRequest_ps->stateBits_s.WheelSlipRearLeft_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->stateBits_s.PdcBoundFrontLeft_u8 = ( (v_BitFieldData_u8 & (1 << 0)) != 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcBoundFrontLeftCenter_u8 = ( (v_BitFieldData_u8 & (1 << 1)) != 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcBoundFrontRightCenter_u8 = ( (v_BitFieldData_u8 & (1 << 2)) != 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcBoundFrontRight_u8 = ( (v_BitFieldData_u8 & (1 << 3)) != 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcBoundRearLeft_u8 = ( (v_BitFieldData_u8 & (1 << 4)) != 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcBoundRearLeftCenter_u8 = ( (v_BitFieldData_u8 & (1 << 5)) != 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcBoundRearRightCenter_u8 = ( (v_BitFieldData_u8 & (1 << 6)) != 0);
    b_VehicleStateRequest_ps->stateBits_s.PdcBoundRearRight_u8 = ( (v_BitFieldData_u8 & (1 << 7)) != 0);
    
    b_VehicleStateRequest_ps->Reserved2_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->Reserved3_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->VehiclePitch_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->VehicleRoll_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateRequest_ps->Crc16_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readVehicleStateResponse_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, VehicleStateResponse_t* b_VehicleStateResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_VehicleStateResponse_ps->ResponseCode_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_VehicleStateResponse_ps->Crc16_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t readTestAllDataTypes_b(const uint8_t* i_Data_pc, uint32_t i_DataLength_u32, TestAllDataTypes_t* b_TestAllDataTypes_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    b_TestAllDataTypes_ps->Test_u8 = ME_DataSerializer_Read_u8(i_Data_pc, &v_Index_u32, true);
    b_TestAllDataTypes_ps->Test_u16 = ME_DataSerializer_Read_u16(i_Data_pc, &v_Index_u32, true);
    b_TestAllDataTypes_ps->Test_u32 = ME_DataSerializer_Read_u32(i_Data_pc, &v_Index_u32, true);
    b_TestAllDataTypes_ps->Test_u64 = ME_DataSerializer_Read_u64(i_Data_pc, &v_Index_u32, true);
    b_TestAllDataTypes_ps->Test_s8 = ME_DataSerializer_Read_s8(i_Data_pc, &v_Index_u32, true);
    b_TestAllDataTypes_ps->Test_s16 = ME_DataSerializer_Read_s16(i_Data_pc, &v_Index_u32, true);
    b_TestAllDataTypes_ps->Test_s32 = ME_DataSerializer_Read_s32(i_Data_pc, &v_Index_u32, true);
    b_TestAllDataTypes_ps->Test_s64 = ME_DataSerializer_Read_s64(i_Data_pc, &v_Index_u32, true);
    b_TestAllDataTypes_ps->Test_f32 = ME_DataSerializer_Read_f32(i_Data_pc, &v_Index_u32, true);
  }
  
  return v_Valid_b;
}


/*  --- Write Functions --- */
ME_INLINE bool_t writeErrorneousResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ErrorneousResponse_t* b_ErrorneousResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ErrorneousResponse_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_ErrorneousResponse_ps->ErrorMessageID_u16, true);
  }
  
  return v_Valid_b;
}

/*
ME_INLINE bool_t writeDmsIpcCamCtrlDataType_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const DmsIpcCamCtrlDataType_t* b_DmsIpcCamCtrlDataType_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);
  
  if (true == v_Valid_b)
  {
        memcpy( b_Data_pc, b_DmsIpcCamCtrlDataType_ps,i_DataLength_u32);
  }
  
  return v_Valid_b;
}


ME_INLINE bool_t writeDmsIpcFeatureDataType_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const DmsIpcFeatureDataType_t* b_DmsIpcFeatureDataType_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);
  
  memcpy( b_Data_pc, b_DmsIpcFeatureDataType_ps,i_DataLength_u32);
  
  return v_Valid_b;
}
*/


ME_INLINE bool_t writeTbSVS_e_SVSOutputToDiagMgrCamCalib_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const TbSVS_e_SVSOutputToDiagMgrCamCalib_t* b_TbSVS_e_SVSOutputToDiagMgrCamCalib_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  memcpy( b_Data_pc, b_TbSVS_e_SVSOutputToDiagMgrCamCalib_ps,i_DataLength_u32);

  return v_Valid_b;
}
#ifdef ME_FISKER

ME_INLINE bool_t writeTbSVS_e_SVSOutputToNVMCamCalibSM_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const TbSVS_e_SVSOutputToNVMCamCalibSM_t* b_TbSVS_e_SVSOutputToNVMCamCalibSM_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  memcpy( b_Data_pc, b_TbSVS_e_SVSOutputToNVMCamCalibSM_ps,i_DataLength_u32);

  return v_Valid_b;
}

ME_INLINE bool_t writeErrorMgr_ErrorCommPack_QNX_B_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ErrorMgr_ErrorCommPack_QNX_B_t* b_ErrorMgr_ErrorCommPack_QNX_B_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  memcpy( b_Data_pc, b_ErrorMgr_ErrorCommPack_QNX_B_ps,i_DataLength_u32);

  return v_Valid_b;
}

ME_INLINE bool_t writeMOT_Output_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MOT_Output_t* b_MOT_Output_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  memcpy( b_Data_pc, b_MOT_Output_ps,i_DataLength_u32);

  return v_Valid_b;
}
ME_INLINE bool_t writeDNN_Output_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const DNN_Output_t* b_DNN_Output_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  memcpy( b_Data_pc, b_DNN_Output_ps,i_DataLength_u32);

  return v_Valid_b;
}
ME_INLINE bool_t writeSSM_QNX_CoreStatus_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const SSM_QNX_CoreStatus_t* b_SSM_QNX_CoreStatus_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  memcpy( b_Data_pc, b_SSM_QNX_CoreStatus_ps,i_DataLength_u32);

  return v_Valid_b;
}
ME_INLINE bool_t writeIJobPLDOutput_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const IJobPLDOutput_t* b_IJobPLDOutput_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  memcpy( b_Data_pc, b_IJobPLDOutput_ps,i_DataLength_u32);

  return v_Valid_b;
}
#endif

ME_INLINE bool_t writeBootStateRequest_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const BootStateRequest_t* b_BootStateRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 2);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_BootStateRequest_ps->BootState_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_BootStateRequest_ps->CamDeserSerEnable_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeBootStateResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const BootStateResponse_t* b_BootStateResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_BootStateResponse_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_BootStateResponse_ps->VideoSubSystemState_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_BootStateResponse_ps->CamDeserSerEnableComplete_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeApplyConfigRequest_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ApplyConfigRequest_t* b_ApplyConfigRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 4);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_ApplyConfigRequest_ps->variantID_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_ApplyConfigRequest_ps->varintConfig_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeApplyConfigResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ApplyConfigResponse_t* b_ApplyConfigResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 5);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ApplyConfigResponse_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_ApplyConfigResponse_ps->variantID_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_ApplyConfigResponse_ps->varintConfig_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeErrorStateRequest_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ErrorStateRequest_t* b_ErrorStateRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ErrorStateRequest_ps->ErrorCategory_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeErrorStateResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ErrorStateResponse_t* b_ErrorStateResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 32);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ErrorStateResponse_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ErrorStateResponse_ps->ErrorCategory_u8, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < 30; ++v_I_u32)
    {
      ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ErrorStateResponse_ps->ErrData_au8[v_I_u32], true);
    }
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeKeepAliveRequest_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const KeepAliveRequest_t* b_KeepAliveRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 4);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_KeepAliveRequest_ps->Counter_u32, true);
  }
  
  return v_Valid_b;
}

/*ME_INLINE bool_t writeKeepAliveResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const KeepAliveResponse_t* b_KeepAliveResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 5);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_KeepAliveResponse_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_KeepAliveResponse_ps->FrameID_u32, true);
  }
  
  return v_Valid_b;
}*/

ME_INLINE bool_t writeTestPatternRequest_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const TestPatternRequest_t* b_TestPatternRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 2);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TestPatternRequest_ps->CameraID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TestPatternRequest_ps->RequestedTestPattern_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeTestPatternResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const TestPatternResponse_t* b_TestPatternResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TestPatternResponse_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TestPatternResponse_ps->CameraID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TestPatternResponse_ps->RequestedTestPattern_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeInformationRequest_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const InformationRequest_t* b_InformationRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 2);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_InformationRequest_ps->Requested_Information_s8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_InformationRequest_ps->Payload_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeInformationResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const InformationResponse_t* b_InformationResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_InformationResponse_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_InformationResponse_ps->Current_Information_u8, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < 6; ++v_I_u32)
    {
      ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_InformationResponse_ps->Payload_au8[v_I_u32], true);
    }
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_Control_ErrorState_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_Control_ErrorState_t* b_Request_Control_ErrorState_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Control_ErrorState_ps->ErrorCategory_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Control_ErrorState_ps->Error_Data_No_Video_Output_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Control_ErrorState_ps->Error_Data_Front_Cam_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Control_ErrorState_ps->Error_Data_Left_Cam_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Control_ErrorState_ps->Error_Data_Rear_Cam_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Control_ErrorState_ps->Error_Data_Right_Cam_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Control_ErrorState_ps->Error_Data_Bed_Cam_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Control_ErrorState_ps->hold_time_0_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_Control_ErrorState_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_Control_ErrorState_t* b_Response_Control_ErrorState_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Control_ErrorState_ps->ResponseCode_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeControlRequest_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ControlRequest_t* b_ControlRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 5);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ControlRequest_ps->RequestedControl_u8, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_ControlRequest_ps->Payload_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeControlResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ControlResponse_t* b_ControlResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ControlResponse_ps->ResponseCode_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeMiscRequest_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MiscRequest_t* b_MiscRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 4);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MiscRequest_ps->TRANSTAT_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MiscRequest_ps->GDEC_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MiscRequest_ps->CANCEL_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MiscRequest_ps->TORQUE_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeMiscResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MiscResponse_t* b_MiscResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MiscResponse_ps->Response_Code_MiscResponse_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeMCU_TRAGateway1Request_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MCU_TRAGateway1Request_t* b_MCU_TRAGateway1Request_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 6);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    uint8_t v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_B_P_u8 << 0;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_B_R_u8 << 1;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_B_D_u8 << 2;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_B_N_u8 << 3;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.REV_SW_u8 << 4;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.TraActiveLight_u8 << 5;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.GearSignal_bit_6_u8 << 6;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.GearSignal_bit_7_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_EPSFAIL_u8 << 0;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_EPSSTS0_u8 << 1;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_EPSACT_u8 << 2;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.PCAN_EPSSYS_u8 << 3;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.EPSdata_bit_4_u8 << 4;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.EPSdata_bit_5_u8 << 5;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.EPSdata_bit_6_u8 << 6;
    v_BitFieldData_u8 |= b_MCU_TRAGateway1Request_ps->GearSignals_EPSdata.EPSdata_bit_7_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway1Request_ps->PCAN_VWPSUMFL_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway1Request_ps->PCAN_VWPSUMFR_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway1Request_ps->PCAN_VWPSUMRL_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway1Request_ps->PCAN_VWPSUMRR_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeMCU_TRAGateway1Response_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MCU_TRAGateway1Response_t* b_MCU_TRAGateway1Response_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway1Response_ps->Response_Code_MCU_TRAGateway1_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeMCU_TRAGateway2Request_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MCU_TRAGateway2Request_t* b_MCU_TRAGateway2Request_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway2Request_ps->PCAN_VXFR_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway2Request_ps->PCAN_VXFL_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway2Request_ps->PCAN_VXRR_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway2Request_ps->PCAN_VXRL_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeMCU_TRAGateway2Response_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MCU_TRAGateway2Response_t* b_MCU_TRAGateway2Response_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway2Response_ps->Response_Code_MCU_TRAGateWay2_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeMCU_TRAGateway3Request_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MCU_TRAGateway3Request_t* b_MCU_TRAGateway3Request_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway3Request_ps->PCAN_SP1_u16, true);
    uint8_t v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 0;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 1;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 2;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 3;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 4;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 5;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 6;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 0;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 1;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 2;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSA_u16 << 3;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSAS_s16 << 4;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSAS_s16 << 5;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSAS_s16 << 6;
    v_BitFieldData_u8 |= b_MCU_TRAGateway3Request_ps->SSA_SSASBits_s.PCAN_SSAS_s16 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway3Request_ps->PCAN_VSC_YAW0_u16, true);
    ME_DataSerializer_Write_s16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway3Request_ps->PCAN_SSAV_s16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeMCU_TRAGateway3Response_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MCU_TRAGateway3Response_t* b_MCU_TRAGateway3Response_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway3Response_ps->ResponseCode_TRAGateway3_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway3Response_ps->TAD_angle_u16, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway3Response_ps->Confidence_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway3Response_ps->tadAngleRate_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway3Response_ps->frameNumber_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeMCU_TRAGateway4Request_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MCU_TRAGateway4Request_t* b_MCU_TRAGateway4Request_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 2);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway4Request_ps->PCAN_EST2_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeMCU_TRAGateway4Response_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const MCU_TRAGateway4Response_t* b_MCU_TRAGateway4Response_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 8);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway4Response_ps->Response_Code_MCU_TRAGateway4_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway4Response_ps->TrailerBeamLength_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway4Response_ps->HitchLength_u16, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway4Response_ps->TadState_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_MCU_TRAGateway4Response_ps->TRATSA_u16, true);
  }
  
  return v_Valid_b;
}
#ifdef USE_REQUEST_AND_RESPONSE
ME_INLINE bool_t writeScreenRequest_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ScreenRequest_t* b_ScreenRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 38);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->Version_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->ViewID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->ZoomFactor_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->ColorCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->NaviScrMsg_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->ToggleCount_u8, true);
    uint8_t v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.LayoutPartView_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.LayoutFullView_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.LayoutMtmView_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.LayoutConfirmView_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconGdlFrontCorner_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconGdlFrontWheel_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconGdlRearStatic_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconGdlRearDistance_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconGdlRearWheelDir_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconClearanceSonar_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconSoundOn_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconSoundOff_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconRcdOff_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconWarn_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconBrake_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconBrakeSwitch_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconBrakePress_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.Btn10kphDis_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonZoom_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonDblZoom_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonUnZoom_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.BtnExit_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFrontOn_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFrontOff_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearOn_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearOff_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFronSplitOn_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFrontSplitOff_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearSplitOn_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearSplitOff_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmAuxOn_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmAuxOff_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmCargoOn_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmCargoOff_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmTopOn_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmTopOnLock_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmTopOff_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmTopOffLock_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmViewEnable_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmViewDisable_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonTraOn_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonTraOff_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonTraDisable_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonTowOn_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonTowOff_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPrevView_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPanBar_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPanLeArrow_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPanRiArrow_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonAutoStartLock_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonAutoStartOn_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonAutoStartOff_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconWheelSlip_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonTowDisable_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmTopDisable_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconAccelerationPressed_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmFrontSideOn_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmFrontSideOff_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmUnderfloorSideOn_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmUnderfloorSideOff_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearSideOn_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearSideOff_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearWideOn_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearWideOff_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAuxOn_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAuxOff_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmViewEnable_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmViewDisable_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconGdlSelectLocked_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconInclinometerDisable_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconInclinometer_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAutoStartOn_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAutoStartOff_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonConfirmViewFooter_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.TextPksbUnavailable_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconTrlSwingLeft_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconTrlSwingRight_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconRearCrossTrafficAlertTop_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineRearDistancePrimary_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineFrontCornerTop_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineFrontPredictTop_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineRearDistanceTop_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineRearDynamicTop_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineFrontBackwardTop_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineRearParkTop_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineFrontCornerPrimary_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineFrontSplitPrimary_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineRearStaticDistRedPrimary_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineRearDynamicPrimary_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineRearStaticPrimary_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineRearParkPrimary_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineTowPrimary_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineConfirmTrailerMarkPrimary_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmFrontDistance_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmFrontMax_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmFrontDynamic_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmSideStatic_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmFrontOverallDynamic_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineMtmRearOverallDynamic_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.GuidelineRearStaticDistBluePrimary_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFrontDisable_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearDisable_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmFrontSplitDisable_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconMtmUnderfloorVehicleContour_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.TextCheckSurrounding_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.TextTraMessages_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.BtnTraModeDisable_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconRearCrossTrafficAlertPrimary_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmRearSplitDisable_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmAuxDisable_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonPvmCargoDisable_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonFrontGdlSelectDisable_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonRearGdlSelectDisable_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonAutoStartDisable_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmFrontSideDisable_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmUnderfloorSideDisable_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearSideDisable_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmRearWideDisable_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAuxDisable_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.ButtonMtmAutoStartDisable_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconClearanceSonarGuidance_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.DealScrManualAdjust_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.DealScrCameraCheck_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconTrlSwingText_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.VehicleColorMenu_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.IconClearanceSonarTopView_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.Bit126_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenRequest_ps->OverlayBits_s.Bit127_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->ButtonId_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->ButtonState_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->ScreenID_u8, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < 10; ++v_I_u32)
    {
      ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->ScreenData_au8[v_I_u32], true);
    }
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->ButtonIdReset_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_ScreenRequest_ps->CRC16_u16, true);
  }
  
  return v_Valid_b;
}
#endif

#ifdef USE_REQUEST_AND_RESPONSE
ME_INLINE bool_t writeScreenResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ScreenResponse_t* b_ScreenResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 39);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->Version_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->ViewID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->ZoomFactor_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->ColorCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->NaviScrMsg_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->ToggleCount_u8, true);
    uint8_t v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.LayoutPartView_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.LayoutFullView_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.LayoutMtmView_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.LayoutConfirmView_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconGdlFrontCorner_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconGdlFrontWheel_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconGdlRearStatic_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconGdlRearDistance_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconGdlRearWheelDir_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconClearanceSonar_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconSoundOn_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconSoundOff_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconRcdOff_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconWarn_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconBrake_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconBrakeSwitch_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconBrakePress_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.Btn10kphDis_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonZoom_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonDblZoom_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonUnZoom_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.BtnExit_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFrontOn_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFrontOff_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearOn_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearOff_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFronSplitOn_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFrontSplitOff_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearSplitOn_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearSplitOff_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmAuxOn_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmAuxOff_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmCargoOn_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmCargoOff_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmTopOn_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmTopOnLock_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmTopOff_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmTopOffLock_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmViewEnable_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmViewDisable_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonTraOn_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonTraOff_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonTraDisable_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonTowOn_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonTowOff_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPrevView_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPanBar_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPanLeArrow_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPanRiArrow_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonAutoStartLock_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonAutoStartOn_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonAutoStartOff_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconWheelSlip_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonTowDisable_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmTopDisable_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconAccelerationPressed_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmFrontSideOn_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmFrontSideOff_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmUnderfloorSideOn_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmUnderfloorSideOff_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearSideOn_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearSideOff_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearWideOn_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearWideOff_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAuxOn_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAuxOff_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmViewEnable_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmViewDisable_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconGdlSelectLocked_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconInclinometerDisable_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconInclinometer_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAutoStartOn_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAutoStartOff_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonConfirmViewFooter_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.TextPksbUnavailable_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconTrlSwingLeft_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconTrlSwingRight_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconRearCrossTrafficAlertTop_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineRearDistancePrimary_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineFrontCornerTop_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineFrontPredictTop_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineRearDistanceTop_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineRearDynamicTop_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineFrontBackwardTop_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineRearParkTop_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineFrontCornerPrimary_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineFrontSplitPrimary_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineRearStaticDistRedPrimary_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineRearDynamicPrimary_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineRearStaticPrimary_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineRearParkPrimary_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineTowPrimary_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineConfirmTrailerMarkPrimary_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmFrontDistance_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmFrontMax_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmFrontDynamic_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmSideStatic_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmFrontOverallDynamic_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineMtmRearOverallDynamic_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.GuidelineRearStaticDistBluePrimary_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFrontDisable_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearDisable_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmFrontSplitDisable_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconMtmUnderfloorVehicleContour_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.TextCheckSurrounding_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.TextTraMessages_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.BtnTraModeDisable_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconRearCrossTrafficAlertPrimary_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmRearSplitDisable_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmAuxDisable_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonPvmCargoDisable_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonFrontGdlSelectDisable_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonRearGdlSelectDisable_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonAutoStartDisable_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmFrontSideDisable_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmUnderfloorSideDisable_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearSideDisable_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmRearWideDisable_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAuxDisable_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.ButtonMtmAutoStartDisable_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconClearanceSonarGuidance_u8 << 0;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.DealScrManualAdjust_u8 << 1;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.DealScrCameraCheck_u8 << 2;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconTrlSwingText_u8 << 3;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.VehicleColorMenu_u8 << 4;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.IconClearanceSonarTopView_u8 << 5;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.Bit126_u8 << 6;
    v_BitFieldData_u8 |= b_ScreenResponse_ps->OverlayBits_s.Bit127_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->ButtonId_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->ButtonState_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->ScreenID_u8, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < 10; ++v_I_u32)
    {
      ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->ScreenData_au8[v_I_u32], true);
    }
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->ButtonIdReset_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_ScreenResponse_ps->CRC16_u16, true);
  }
  
  return v_Valid_b;
}
#else
ME_INLINE bool_t writeScreenResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const ScreenResponse_t* b_ScreenResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  if (true == v_Valid_b)
  {
    memcpy( b_Data_pc, b_ScreenResponse_ps,i_DataLength_u32);
  }

  return v_Valid_b;
}
#endif

ME_INLINE bool_t writeTRA_Data_Request_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const TRA_Data_Request_t* b_TRA_Data_Request_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 16);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->Emptiness1_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->Emptiness2_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->Emptiness3_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_b_ClrTrlrCal_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_e_TADTrackStat_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_b_TRAACT_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_e_TRAStrCtrlStat_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_e_TrlrActStat_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_e_TrlrCalStat_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_e_TrlrID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_b_RqstArmVlidPar_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_e_TrlrAgeStat_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_deg_MaxSWR_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_TRA_Data_Request_ps->IeTRIO_deg_MaxTsaAllwd_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeTRA_Data_Response_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const TRA_Data_Response_t* b_TRA_Data_Response_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 32);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->Emptiness1_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->Emptiness2_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->Emptiness3_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->Emptiness4_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_e_TrlrDimEstStat_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_e_StrIcon_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_e_TrlrDirIcon_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_e_ArmTrnPrcss_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_e_ArmSaveData_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_e_TADAcqStat_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_b_TrlrDataV_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_b_ASRACT_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_deg_TADAngAct_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_deg_TrgtStrAng_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_ddeg_TADAngRateAct_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_deg_TrlrAngTh_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_TRA_Data_Response_ps->IeTRIA_deg_TADAngPred_f32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_Camera_GetEeprom_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_Camera_GetEeprom_t* b_Request_Camera_GetEeprom_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 10);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_GetEeprom_ps->v_CameraID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_GetEeprom_ps->v_ReadOffset_u8, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < 8; ++v_I_u32)
    {
      ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_GetEeprom_ps->v_Reserved_au8[v_I_u32], true);
    }
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_Camera_GetEeprom_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_Camera_GetEeprom_t* b_Response_Camera_GetEeprom_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 41);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_GetEeprom_ps->v_ResponseCode_u8, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < 40; ++v_I_u32)
    {
      ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_GetEeprom_ps->v_data_au8[v_I_u32], true);
    }
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_Camera_SetRegister_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_Camera_SetRegister_t* b_Request_Camera_SetRegister_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 6);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_SetRegister_ps->CameraID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_SetRegister_ps->DeviceID_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Request_Camera_SetRegister_ps->RegisterAddress_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Request_Camera_SetRegister_ps->RegisterValue_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_Camera_SetRegister_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_Camera_SetRegister_t* b_Response_Camera_SetRegister_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_SetRegister_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_SetRegister_ps->CameraID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_SetRegister_ps->DeviceID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_Camera_GetRegister_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_Camera_GetRegister_t* b_Request_Camera_GetRegister_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 4);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_GetRegister_ps->CameraID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_GetRegister_ps->DeviceID_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Request_Camera_GetRegister_ps->RegisterAddress_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_Camera_GetRegister_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_Camera_GetRegister_t* b_Response_Camera_GetRegister_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 7);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_GetRegister_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_GetRegister_ps->CameraID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_GetRegister_ps->DeviceID_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_Camera_GetRegister_ps->RegisterAddress_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_Camera_GetRegister_ps->RegisterValue_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_Camera_Debug_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_Camera_Debug_t* b_Request_Camera_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 5);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_Debug_ps->CamID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_Debug_ps->DebugEnable_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_Debug_ps->FailsafeBehavior_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_Debug_ps->CamToMemStatusThreshold_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_Debug_ps->CamMinRestartInterval_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_Camera_Debug_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_Camera_Debug_t* b_Response_Camera_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 6);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_Debug_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_Debug_ps->CamID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_Debug_ps->DebugEnable_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_Debug_ps->FailsafeBehavior_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_Debug_ps->CamToMemStatusThreshold_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_Debug_ps->CamMinRestartInterval_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_Camera_ApplyCalib_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_Camera_ApplyCalib_t* b_Request_Camera_ApplyCalib_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 25);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_Camera_ApplyCalib_ps->CameraID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Request_Camera_ApplyCalib_ps->Pitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Request_Camera_ApplyCalib_ps->Yaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Request_Camera_ApplyCalib_ps->Roll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Request_Camera_ApplyCalib_ps->X_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Request_Camera_ApplyCalib_ps->Y_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Request_Camera_ApplyCalib_ps->Z_f32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_Camera_ApplyCalib_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_Camera_ApplyCalib_t* b_Response_Camera_ApplyCalib_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_Camera_ApplyCalib_ps->ResponseCode_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeSvs_CamEepromDataArray_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const SVSEepromData_t* b_SVSEepromData_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  memcpy( b_Data_pc, b_SVSEepromData_ps,i_DataLength_u32);

  return v_Valid_b;
}

ME_INLINE bool_t writeSvs_CamEepromReservedCRCBytes_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const uint8_t* b_crcResBytes_p)
{
  bool_t v_Valid_b = (i_DataLength_u32 > 0);

  memcpy( b_Data_pc, b_crcResBytes_p,i_DataLength_u32);

  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_EOL_Start_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_EOL_Start_t* b_Request_EOL_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 18);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_EOL_Start_ps->CamID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_EOL_Start_ps->Algo_Selected_u8, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_EOL_Start_ps->targetX1_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_EOL_Start_ps->targetY1_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_EOL_Start_ps->targetX2_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_EOL_Start_ps->targetY2_s32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_EOL_Start_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_EOL_Start_t* b_Response_EOL_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 35);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_EOL_Start_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_EOL_Stop_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_EOL_Stop_t* b_Request_EOL_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_EOL_Stop_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_EOL_Stop_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_EOL_Stop_t* b_Response_EOL_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 35);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_EOL_Stop_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_EOL_Pause_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_EOL_Pause_t* b_Request_EOL_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_EOL_Pause_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_EOL_Pause_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_EOL_Pause_t* b_Response_EOL_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 35);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_EOL_Pause_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_EOL_Resume_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_EOL_Resume_t* b_Request_EOL_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_EOL_Resume_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_EOL_Resume_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_EOL_Resume_t* b_Response_EOL_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 35);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_EOL_Resume_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_EOL_Status_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_EOL_Status_t* b_Request_EOL_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_EOL_Status_ps->CamID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_EOL_Status_ps->Algo_Selected_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_EOL_Status_ps->Read_Offset_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_EOL_Status_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_EOL_Status_t* b_Response_EOL_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 66);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Status_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Status_ps->ErrorState_u8, true);
    
    for (uint32_t v_I_u32 = 0; v_I_u32 < 20; ++v_I_u32)
    {
      ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Status_ps->TargetMarkerData_au16[v_I_u32], true);
    }
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Status_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Status_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Status_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Status_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Status_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Status_ps->deltaZ_f32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_EOL_Debug_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_EOL_Debug_t* b_Request_EOL_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_EOL_Debug_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_EOL_Debug_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_EOL_Debug_t* b_Response_EOL_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 75);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionLeft0_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionLeft1_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionLeft2_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionLeft3_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionLeft4_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionLeft5_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionLeft6_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionLeft7_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionLeft8_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionLeft9_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionRight0_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionRight1_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionRight2_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionRight3_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionRight4_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionRight5_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionRight6_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionRight7_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionRight8_u16, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->markerDetectionRight9_u16, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_EOL_Debug_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_OC_Start_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_OC_Start_t* b_Request_OC_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_OC_Start_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_OC_Start_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_OC_Start_t* b_Response_OC_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Start_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Start_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Start_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Start_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Start_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Start_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Start_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_OC_Start_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Start_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Start_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_OC_Stop_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_OC_Stop_t* b_Request_OC_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_OC_Stop_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_OC_Stop_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_OC_Stop_t* b_Response_OC_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Stop_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Stop_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Stop_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Stop_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Stop_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Stop_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Stop_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_OC_Stop_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Stop_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Stop_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_OC_Pause_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_OC_Pause_t* b_Request_OC_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_OC_Pause_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_OC_Pause_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_OC_Pause_t* b_Response_OC_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Pause_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Pause_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Pause_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Pause_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Pause_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Pause_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Pause_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_OC_Pause_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Pause_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Pause_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_OC_Resume_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_OC_Resume_t* b_Request_OC_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_OC_Resume_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_OC_Resume_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_OC_Resume_t* b_Response_OC_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Resume_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Resume_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Resume_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Resume_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Resume_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Resume_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Resume_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_OC_Resume_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Resume_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Resume_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_OC_Status_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_OC_Status_t* b_Request_OC_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_OC_Status_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_OC_Status_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_OC_Status_t* b_Response_OC_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Status_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Status_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Status_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Status_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Status_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Status_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Status_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_OC_Status_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Status_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Status_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_OC_Debug_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_OC_Debug_t* b_Request_OC_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_OC_Debug_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_OC_Debug_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_OC_Debug_t* b_Response_OC_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Debug_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_OC_Debug_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Debug_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Debug_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_OC_Debug_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Debug_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Debug_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_OC_Debug_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Debug_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_OC_Debug_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_SC_Start_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_SC_Start_t* b_Request_SC_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 114);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->CamID_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->numberOfTargets_u8, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->numberOfSquares1_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetWidth1_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetHeight1_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetX1_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetY1_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetZ1_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->orientation1_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->numberOfSquares2_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetWidth2_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetHeight2_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetX2_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetY2_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetZ2_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->orientation2_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->numberOfSquares3_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetWidth3_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetHeight3_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetX3_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetY3_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetZ3_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->orientation3_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->numberOfSquares4_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetWidth4_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetHeight4_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetX4_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetY4_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->targetZ4_s32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Request_SC_Start_ps->orientation4_s32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_SC_Start_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_SC_Start_t* b_Response_SC_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->targetInit_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->targetLimitFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->targetLimitRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->targetDetectLeftFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->targetDetectLeftRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->targetDetectRightFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->targetDetectRightRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Start_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_SC_Stop_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_SC_Stop_t* b_Request_SC_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_SC_Stop_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_SC_Stop_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_SC_Stop_t* b_Response_SC_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->targetInit_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->targetLimitFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->targetLimitRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->targetDetectLeftFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->targetDetectLeftRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->targetDetectRightFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->targetDetectRightRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Stop_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_SC_Pause_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_SC_Pause_t* b_Request_SC_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_SC_Pause_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_SC_Pause_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_SC_Pause_t* b_Response_SC_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->targetInit_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->targetLimitFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->targetLimitRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->targetDetectLeftFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->targetDetectLeftRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->targetDetectRightFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->targetDetectRightRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Pause_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_SC_Resume_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_SC_Resume_t* b_Request_SC_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_SC_Resume_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_SC_Resume_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_SC_Resume_t* b_Response_SC_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->targetInit_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->targetLimitFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->targetLimitRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->targetDetectLeftFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->targetDetectLeftRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->targetDetectRightFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->targetDetectRightRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Resume_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_SC_Status_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_SC_Status_t* b_Request_SC_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_SC_Status_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_SC_Status_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_SC_Status_t* b_Response_SC_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->targetInit_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->targetLimitFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->targetLimitRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->targetDetectLeftFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->targetDetectLeftRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->targetDetectRightFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->targetDetectRightRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Status_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_SC_Debug_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_SC_Debug_t* b_Request_SC_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_SC_Debug_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_SC_Debug_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_SC_Debug_t* b_Response_SC_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 42);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->deltaX_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->deltaY_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->deltaZ_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->errorState_u32, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->targetInit_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->targetLimitFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->targetLimitRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->targetDetectLeftFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->targetDetectLeftRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->targetDetectRightFront_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->targetDetectRightRear_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_Response_SC_Debug_ps->reserved_s8_s8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_TEOL_Start_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_TEOL_Start_t* b_Request_TEOL_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_TEOL_Start_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_TEOL_Start_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_TEOL_Start_t* b_Response_TEOL_Start_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Start_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Start_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Start_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Start_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Start_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Start_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Start_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Start_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Start_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Start_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_TEOL_Stop_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_TEOL_Stop_t* b_Request_TEOL_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_TEOL_Stop_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_TEOL_Stop_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_TEOL_Stop_t* b_Response_TEOL_Stop_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Stop_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Stop_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Stop_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Stop_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Stop_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Stop_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Stop_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Stop_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Stop_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Stop_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_TEOL_Pause_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_TEOL_Pause_t* b_Request_TEOL_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_TEOL_Pause_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_TEOL_Pause_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_TEOL_Pause_t* b_Response_TEOL_Pause_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Pause_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Pause_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Pause_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Pause_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Pause_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Pause_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Pause_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Pause_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Pause_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Pause_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_TEOL_Resume_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_TEOL_Resume_t* b_Request_TEOL_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_TEOL_Resume_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_TEOL_Resume_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_TEOL_Resume_t* b_Response_TEOL_Resume_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Resume_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Resume_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Resume_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Resume_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Resume_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Resume_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Resume_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Resume_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Resume_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Resume_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_TEOL_Status_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_TEOL_Status_t* b_Request_TEOL_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_TEOL_Status_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_TEOL_Status_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_TEOL_Status_t* b_Response_TEOL_Status_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Status_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Status_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Status_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Status_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Status_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Status_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Status_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Status_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Status_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Status_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeRequest_TEOL_Debug_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Request_TEOL_Debug_t* b_Request_TEOL_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 1);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Request_TEOL_Debug_ps->CamID_u8, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeResponse_TEOL_Debug_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const Response_TEOL_Debug_t* b_Response_TEOL_Debug_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Debug_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_Response_TEOL_Debug_ps->CamID_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Debug_ps->deltaPitch_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Debug_ps->deltaYaw_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Debug_ps->deltaRoll_f32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Debug_ps->validFeatures_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Debug_ps->ignoredFeatures_u32, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Debug_ps->invalidFeatures_s32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Debug_ps->algoState_u32, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_Response_TEOL_Debug_ps->errorCode_u32, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeVehicleStateRequest_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const VehicleStateRequest_t* b_VehicleStateRequest_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 31);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->VehicleLevel_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->SteeringAngle_f32, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->SteeringWheelAngle_f32, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->DayNightStatus_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->GearInformation_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->LanguageId_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->DoorStatus_u8, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->VehSpeed_f32, true);
    uint8_t v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontRight_u8 << 0;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontRight_u8 << 1;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontRight_u8 << 2;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearRight_u8 << 3;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearRight_u8 << 4;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearRight_u8 << 5;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.RctaRight_u8 << 6;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.RctaRight_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeft_u8 << 0;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeft_u8 << 1;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeft_u8 << 2;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearLeft_u8 << 3;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearLeft_u8 << 4;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearLeft_u8 << 5;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.RctaLeft_u8 << 6;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.RctaLeft_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontRightCenter_u8 << 0;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontRightCenter_u8 << 1;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontRightCenter_u8 << 2;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeftCenter_u8 << 3;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeftCenter_u8 << 4;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcFrontLeftCenter_u8 << 5;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.WheelSlipFrontRight_u8 << 6;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.WheelSlipFrontLeft_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearRightCenter_u8 << 0;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearRightCenter_u8 << 1;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearRightCenter_u8 << 2;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearLeftCenter_u8 << 3;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearLeftCenter_u8 << 4;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcRearLeftCenter_u8 << 5;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.WheelSlipRearRight_u8 << 6;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.WheelSlipRearLeft_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    v_BitFieldData_u8 = 0;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcBoundFrontLeft_u8 << 0;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcBoundFrontLeftCenter_u8 << 1;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcBoundFrontRightCenter_u8 << 2;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcBoundFrontRight_u8 << 3;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcBoundRearLeft_u8 << 4;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcBoundRearLeftCenter_u8 << 5;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcBoundRearRightCenter_u8 << 6;
    v_BitFieldData_u8 |= b_VehicleStateRequest_ps->stateBits_s.PdcBoundRearRight_u8 << 7;
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, v_BitFieldData_u8, true);
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->Reserved2_u8, true);
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->Reserved3_u8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->VehiclePitch_s8, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->VehicleRoll_s8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_VehicleStateRequest_ps->Crc16_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeVehicleStateResponse_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const VehicleStateResponse_t* b_VehicleStateResponse_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 3);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_VehicleStateResponse_ps->ResponseCode_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_VehicleStateResponse_ps->Crc16_u16, true);
  }
  
  return v_Valid_b;
}

ME_INLINE bool_t writeTestAllDataTypes_b(uint8_t* b_Data_pc, uint32_t i_DataLength_u32, const TestAllDataTypes_t* b_TestAllDataTypes_ps)
{
  bool_t v_Valid_b = (i_DataLength_u32 >= 34);
  
  if (true == v_Valid_b)
  {
    uint32_t v_Index_u32 = 0;
    
    ME_DataSerializer_Write_u8(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_u8, true);
    ME_DataSerializer_Write_u16(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_u16, true);
    ME_DataSerializer_Write_u32(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_u32, true);
    ME_DataSerializer_Write_u64(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_u64, true);
    ME_DataSerializer_Write_s8(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_s8, true);
    ME_DataSerializer_Write_s16(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_s16, true);
    ME_DataSerializer_Write_s32(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_s32, true);
    ME_DataSerializer_Write_s64(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_s64, true);
    ME_DataSerializer_Write_f32(b_Data_pc, &v_Index_u32, b_TestAllDataTypes_ps->Test_f32, true);
  }
  
  return v_Valid_b;
}


#pragma pack() //back to whatever the previous packing mode was // PRQA S 1040 // pragma needed for structures

#endif
