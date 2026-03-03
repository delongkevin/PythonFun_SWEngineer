#ifndef VehicleInputAdapterDataTypes_H_INCGUARD
#define VehicleInputAdapterDataTypes_H_INCGUARD

#include "PlatformDataTypes.h"

#if defined(BUILD_MCU1_0) || defined(BUILD_MCU3_1)
#define float32_t float32
#define uint8_t uint8
#define uint16_t uint16
#define sint16_t sint16
#else
#define float32 float32_t
#define uint8 uint8_t
#define uint16 uint16_t
#define sint16 sint16_t
#endif

/* Magna Output structure for Message ME_VehInp_BCM_FD_10*/
typedef struct BCM_FD_10
{
	uint8 CmdIgnSts;
} ME_VehInp_BCM_FD_10;

/* Magna Output structure for Message ME_VehInp_BCM_FD_27*/
typedef struct BCM_FD_27
{
	uint8 TrailerConnectionSts;
} ME_VehInp_BCM_FD_27;

/* Magna Output structure for Message ME_VehInp_BCM_FD_29*/
typedef struct BCM_FD_29
{
	uint8 ITBM_TrlrStat;
} ME_VehInp_BCM_FD_29;

/* Magna Output structure for Message ME_VehInp_BCM_FD_9*/
typedef struct BCM_FD_9
{
	float32 ExternalTemperature;
	uint8 DriverDoorSts;
	uint8 RHatchSts;
	uint8 RHRDoorSts;
	uint8 LHRDoorSts;
	uint8 PsngrDoorSts;
} ME_VehInp_BCM_FD_9;

/* Magna Output structure for Message TELEMATIC_FD14*/
typedef struct TELEMATIC_FD_14
{
	uint8 TGW_CAMERA_DISP_STAT;
} ME_VehInp_TELEMATIC_FD_14;

/* Magna Output structure for Message TELEMATIC_FD_5*/
typedef struct TELEMATIC_FD_5
{
	uint8 CM_TCH_STAT;
	uint8 CameraDisplaySts2;
	uint16 CM_TCH_X_COORD;
	uint16 CM_TCH_Y_COORD;
} ME_VehInp_TELEMATIC_FD_5;

/* Magna Output structure for Message TELEMATIC_FD_11*/
typedef struct TELEMATIC_FD_11
{
	uint8 HU_TRSC_EnableBtn_Sts;
} ME_VehInp_TELEMATIC_FD_11;

/* Magna Output structure for Message TRANSM_FD_4*/
typedef struct TRANSM_FD_4
{
	uint8 ShiftLeverPosition;
	uint8 GearEngaged;
} ME_VehInp_TRANSM_FD_4;

/* Magna Output structure for Message TRANSM_FD_4*/
typedef struct ORC_FD_1
{
	uint8 SBR1RowDriverSeatSts;
} ME_VehInp_ORC_FD_1;

/* Magna Output structure for Message ASCM_FD_1*/
typedef struct ASCM_FD_1
{
	sint16 FL_Lvl;
	sint16 FR_Lvl;
	sint16 RL_Lvl;
	sint16 RR_Lvl;
	uint8 FL_Lvl_Adj;
	uint8 FR_Lvl_Adj;
	uint8 RL_Lvl_Adj;
	uint8 RR_Lvl_Adj;
} ME_VehInp_ASCM_FD_1;

/* Magna Output structure for Message ASCM_FD_2*/
typedef struct ASCM_FD_2
{
	uint8 ASCM_Stat;
	uint8 ASCM_SysFail;
} ME_VehInp_ASCM_FD_2;

/* Magna Output structure for Message TRANSM_FD_2*/
typedef struct TRANSM_FD_2
{
	uint8 GearEngagedForDisplay;
} ME_VehInp_TRANSM_FD_2;

/* Magna Output structure for Message TRSKM_FD_1*/
typedef struct TRSKM_FD_1
{
	uint8 TRSC_CenterBtn_Sts;
	uint8 TRSC_EnableBtn_Sts;
	uint16 TRSC_RawKnob;
} ME_VehInp_TRSKM_FD_1;

/* Magna Output structure for Message ME_VehInp_BCM_FD_12*/
typedef struct BCM_FD_12
{
	uint8 FT_PAMRequestSts;
	uint8 PAMRequestSts;
	uint8 APARequestSts;
} ME_VehInp_BCM_FD_12;

/* Magna Output structure for Message ME_VehInp_AGSM_FD_2*/
typedef struct AGSM_FD_2
{
	uint8 Shifter_ADAS_Inhibit;
	uint8 ShiftLeverPositionReq;
} ME_VehInp_AGSM_FD_2;

/* Magna Output structure for Message ME_VehInp_BCM_FD_2*/
typedef struct BCM_FD_2
{
	uint8 RemStActvSts;
	uint8 TurnIndicatorSts;
} ME_VehInp_BCM_FD_2;

/* Magna Output structure for Message ME_VehInp_BCM_FD_21*/
typedef struct BCM_FD_21
{
	uint8 Snow_Plow_Presence; /* Not available in DBC */
} ME_VehInp_BCM_FD_21;

/* Magna Output structure for Message ME_VehInp_DRIVETRAIN_FD_3*/
typedef struct DRIVERTRAIN_FD_3
{
	uint8 TCASERANGESTATUS;
} ME_VehInp_DRIVETRAIN_FD_3;

/* Magna Output structure for Message ME_VehInp_IPC_VEHICLE_SETUP*/
typedef struct IPC_VEHICLE_SETUP
{
	uint8 Active_Park_Mode;
	uint8 Active_Park_Prox_Chime;
	uint8 LanguageSelection;
	uint8 PamChimeVolumeFront;
	uint8 PamChimeVolumeRear;
	uint8 Rear_Brk_Asst;
	uint8 SVC_Guidelines;
	uint8 StaticGrid;
	uint8 Fwrd_Cam_Guidelines;
	uint8 DynamicGrid;
} ME_VehInp_IPC_VEHICLE_SETUP;

/* Magna Output structure for Message ME_VehInp_TRANSM_FD_1*/
typedef struct TRANSM_FD_1
{
	uint8 TargetGear;
	uint8 TRANS_ADAS_Inhibit;
	uint8 TransmissionSailingSts;
} ME_VehInp_TRANSM_FD_1;

/* Magna Output structure for Message ME_VehInp_ADAS_FD_INFO_C2*/
typedef struct ADAS_FD_INFO_C2
{
	uint8 HAS_Status_C2;
} ME_VehInp_ADAS_FD_INFO_C2;

/* Magna Output structure for Message ME_VehInp_FD14_BRAKE_FD_2*/
typedef struct FD14_BRAKE_FD2
{
	float32 FD14_LatAcceleration_BSM;
	float32 FD14_LongAcceleration_BSM;
	float32 FD14_YawRate_BSM;
	float32 FD14_VehicleSpeedVSOSig;
	uint8 FD14_ParkingInterventionSts;
	uint8 FD14_LatAccelerationFailSts_BSM;
	uint8 FD14_LongAccelerationFailSts_BSM;
	uint8 FD14_ParkingGearShiftReq_BSM;
	uint8 FD14_YawRateFailSts_BSM;
	sint8 FD14_Slope;
	uint8 FD14_Brk_Stat;
	sint8 FD14_ABSActive; /* Not available in DBC */
} ME_VehInp_FD14_BRAKE_FD_2;

/* Magna Output structure for Message ME_VehInp_FD14_BRAKE_FD_3*/
typedef struct FD14_BRAKE_FD3
{
	float32 FD14_LHFWheelSpeed;
	float32 FD14_LHRWheelSpeed;
	float32 FD14_RHFWheelSpeed;
	float32 FD14_RHRWheelSpeed;
	float32 FD14_LatAccelerationOffset_BSM;
	float32 FD14_LongAccelerationOffset_BSM;
	uint8 FD14_LHF_FastPulseCounter;
	uint8 FD14_LHR_FastPulseCounter;
	uint8 FD14_RHF_FastPulseCounter;
	uint8 FD14_RHR_FastPulseCounter;
	uint8 FD14_LHF_Spin;
	uint8 FD14_LHR_Spin;
	uint8 FD14_RHF_Spin;
	uint8 FD14_RHR_Spin;
	uint8 FD14_LHF_WheelSensorFailSts;
	uint8 FD14_LHR_WheelSensorFailSts;
	uint8 FD14_RHF_WheelSensorFailSts;
	uint8 FD14_RHR_WheelSensorFailSts;
} ME_VehInp_FD14_BRAKE_FD_3;

/* Magna Output structure for Message ME_VehInp_FD14_BRAKE_FD_4*/
typedef struct FD14_BRAKE_FD_4
{
	uint8 FD14_EPBSts;
} ME_VehInp_FD14_BRAKE_FD_4;

/* Magna Output structure for Message ME_VehInp_FD14_BRAKE_FD_5*/
typedef struct FD14_BRAKE_FD_5
{
	uint8 FD14_ESC_TRSC_Brk_Resp;
	uint8 FD14_BSM_THA_Brk_Resp;
} ME_VehInp_FD14_BRAKE_FD_5;

/* Magna Output structure for Message ME_VehInp_FD14_BRAKE_FD_6*/
typedef struct FD14_BRAKE_FD_6
{
	uint8 FD14_DriverReq_AxleTrq_Enabled_BSM;
} ME_VehInp_FD14_BRAKE_FD_6;

/* Magna Output structure for Message ME_VehInp_FD14_BRAKE_FD_7*/
typedef struct FD14_BRAKE_FD_7
{
	uint8 FD14_BrkPdl_Stat;
	uint8 FD14_PAM_Brk_Rq_RspSts;
} ME_VehInp_FD14_BRAKE_FD_7;

/* Magna Output structure for Message ME_VehInp_FD14_EPS_FD_1*/
typedef struct FD14_EPS_FD_1
{
	float32 FD14_LwsAngle;
	float32 FD14_Steering_Column_Torque;
	uint8 FD14_SPM_Lat_Ctrl_ResponseSts;
	sint16 FD14_LwsSpeed;
	uint8 FD14_LwsAngleType;
	uint8 FD14_EPS_HandsOnRecognition;
} ME_VehInp_FD14_EPS_FD_1;

/* Magna Output structure for Message ME_VehInp_FD14_EPS_FD2*/
typedef struct FD14_EPS_FD_2
{
	uint8 FD14_EPS_SteeringTouchStat;
	uint8 FD14_EPS_SteeringTouq_Resp;
	uint8 FD14_EPS_THA_DriverTorqueOverride;
	uint8 FD14_EPS_THA_SteeringTorqueResp;
	uint8 FD14_THA_SteeringTouchStat;
} ME_VehInp_FD14_EPS_FD_2;

/* Magna Output structure for Message ME_VehInp_FD14_ENGINE_FD_2*/
typedef struct FD14_ENGINE_FD_2
{
	uint8 FD14_EngineSts_W;
	uint8 FD14_ESS_ENG_ST_W;
} ME_VehInp_FD14_ENGINE_FD_2;

/* Magna Output structure for Message ME_VehInp_FD14_ENGINE_FD_3*/
typedef struct FD14_ENGINE_FD_3
{
	uint8 FD14_Override;  /* Not available in DBC */
} ME_VehInp_FD14_ENGINE_FD_3;

/* Magna Output structure for Message ME_VehInp_FD14_ENGINE_FD_5*/
typedef struct FD14_ENGINE_FD_5
{
	float32 FD14_PdlPosActual;
} ME_VehInp_FD14_ENGINE_FD_5;

/* Magna Output structure for Message ME_VehInp_FD14_ENGINE_FD_7*/
typedef struct FD14_ENGINE_FD_7
{
	uint8 FD14_ECM_TRSC_Resp;
	uint8 FD14_ECM_THA_Resp;
} ME_VehInp_FD14_ENGINE_FD_7;

/* Magna Output structure for Message ME_VehInp_FD14_BRAKE_FD_1*/
typedef struct FD14_BRAKE_FD_1
{
	float32 FD14_REF_VEH_SPEED;
	uint32 FD14_BrkTrq;
	uint32 FD14_BrkTrq_Driver;
	uint8 FD14_VehicleStandStillSts;
	uint8 FD14_ExternalBrkRequestsDisabled;
} ME_VehInp_FD14_BRAKE_FD_1;

/* Magna Output structure for Message ME_VehInp_FD14_BRAKE2_FD_1*/
typedef struct FD14_BRAKE2_FD_1
{
	float32 FD14_VehicleSpeedVSOSig_B2;    
} ME_VehInp_FD14_BRAKE2_FD_1;

/* Magna Output structure for Message ME_VehInp_FD14_ADAS_FD_INFO*/
typedef struct FD14_ADAS_FD_INFO
{
	uint8 FD14_ACC_Systemsts;
	uint8 FD14_HAS_Status;
} ME_VehInp_FD14_ADAS_FD_INFO;

/* Magna Output structure for Message ME_VehInp_FD14_PT_TORQUE_FD_1*/
typedef struct FD14_PT_TORQUE_FD_1
{
	boolean FD14_Accel_Pedal_Override;
	uint8 FD14_PPPA_TrqEnblRq_Allowed;
} ME_VehInp_FD14_PT_TORQUE_FD_1;

/*From CAN FD 2*/
typedef struct VehInp_FromCAN2_IpcSignals
{
	ME_VehInp_ADAS_FD_INFO_C2 DataInp_ADAS_FD_INFO_C2;
	ME_VehInp_AGSM_FD_2 DataInp_AGSM_FD_2;
	ME_VehInp_ASCM_FD_1 DataInp_ASCM_FD_1;
	ME_VehInp_ASCM_FD_2 DataInp_ASCM_FD_2;
	ME_VehInp_BCM_FD_2 DataInp_BCM_FD_2;
	ME_VehInp_BCM_FD_9 DataInp_BCM_FD_9;
	ME_VehInp_BCM_FD_10 DataInp_BCM_FD_10;
	ME_VehInp_BCM_FD_12 DataInp_BCM_FD_12;
	ME_VehInp_BCM_FD_21 DataInp_BCM_FD_21;
	ME_VehInp_BCM_FD_27 DataInp_BCM_FD_27;
	ME_VehInp_BCM_FD_29 DataInp_BCM_FD_29;
	ME_VehInp_DRIVETRAIN_FD_3 DataInp_DRIVETRAIN_FD_3;
	ME_VehInp_IPC_VEHICLE_SETUP DataInp_IPC_VEHICLE_SETUP;
	ME_VehInp_ORC_FD_1 DataInp_ORC_FD_1;
	ME_VehInp_TELEMATIC_FD_5 DataInp_TELEMATIC_FD_5;
	ME_VehInp_TELEMATIC_FD_11 DataInp_TELEMATIC_FD_11;
	ME_VehInp_TELEMATIC_FD_14 DataInp_TELEMATIC_FD_14;
	ME_VehInp_TRANSM_FD_1 DataInp_TRANSM_FD_1;
	ME_VehInp_TRANSM_FD_2 DataInp_TRANSM_FD_2;
	ME_VehInp_TRANSM_FD_4 DataInp_TRANSM_FD_4;
	ME_VehInp_TRSKM_FD_1 DataInp_TRSKM_FD_1;
} ME_VehInp_FromCAN2_IpcSignals;

/*From CAN FD 14*/
typedef struct VehInp_FromCAN14_IpcSignals
{
	ME_VehInp_FD14_ADAS_FD_INFO DataInp_FD14_ADAS_FD_INFO;
	ME_VehInp_FD14_BRAKE_FD_1 DataInp_FD14_BRAKE_FD_1;
	ME_VehInp_FD14_BRAKE_FD_2 DataInp_FD14_BRAKE_FD_2;
	ME_VehInp_FD14_BRAKE_FD_3 DataInp_FD14_BRAKE_FD_3;
	ME_VehInp_FD14_BRAKE_FD_4 DataInp_FD14_BRAKE_FD_4;
	ME_VehInp_FD14_BRAKE_FD_5 DataInp_FD14_BRAKE_FD_5;
	ME_VehInp_FD14_BRAKE_FD_6 DataInp_FD14_BRAKE_FD_6;
	ME_VehInp_FD14_BRAKE_FD_7 DataInp_FD14_BRAKE_FD_7;
	ME_VehInp_FD14_BRAKE2_FD_1 DataInp_FD14_BRAKE2_FD_1;
	ME_VehInp_FD14_EPS_FD_1 DataInp_FD14_EPS_FD_1;
	ME_VehInp_FD14_EPS_FD_2 DataInp_FD14_EPS_FD_2;
	ME_VehInp_FD14_ENGINE_FD_2 DataInp_FD14_ENGINE_FD_2;
	ME_VehInp_FD14_ENGINE_FD_3 DataInp_FD14_ENGINE_FD_3;
	ME_VehInp_FD14_ENGINE_FD_5 DataInp_FD14_ENGINE_FD_5;
	ME_VehInp_FD14_ENGINE_FD_7 DataInp_FD14_ENGINE_FD_7;
	ME_VehInp_FD14_PT_TORQUE_FD_1 DataInp_FD14_PT_TORQUE_FD_1;
} ME_VehInp_FromCAN14_IpcSignals;

typedef struct ME_VehInp_to_IpcSignals_t
{
	ME_VehInp_FromCAN14_IpcSignals CAN14_to_IPC;
	ME_VehInp_FromCAN2_IpcSignals CAN2_to_IPC;
} ME_VehInp_to_IpcSignals_t;

typedef enum
{
  Production_Mode = 0u,/* Default value */
  Debug_Mode,
  Record_Mode,
  Record_UssDebug_Mode,
  Record_Debug_Mode,
  Replay_Mode,
  Replay_UssDebug_Mode,
  Replay_Debug_Mode,
  Uss_Debug_Mode,
  CanDebugMode_e_MAX = 0xFFFFFFFFU
} CanDebug_e_RIDSts;

typedef struct ME_CanDebugRIDStatus_s
{
    CanDebug_e_RIDSts CanDebugMode;
}ME_CanDebugRIDStatus_t;

#endif

