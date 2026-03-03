/// @file   TRSC_Inputs_Outputs.h
/// @brief  TRSC SM VC IPC Interface Data Structure definition
///
///  TRSC SM VC IPC Interface Data Structure definition
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author  Pravin Pawar (pravin.pawar@magna.com)
///

#ifndef TRSC_INPUTS_OUTPUTS_H_INCGUARD
#define TRSC_INPUTS_OUTPUTS_H_INCGUARD
#define MESSAGE_LENGTH  (int32_t)260

#include "../magna_apps/trsc/algo/_sharedutils/TbTRSCSmVc_TunParam.h"
#include "../magna_apps/trsc/algo/_sharedutils/TRSCSMVCtoDebugCAN.h"
#include "../magna_apps/trsc/algo/_sharedutils/rtwtypes.h"
#include "../magna_apps/trsc/algo/_sharedutils/Detection_Inputs_from_TRSC.h"
#include "../magna_apps/trsc/algo/_sharedutils/TeTRSC_e_SpdLmtReq.h"
#include "HMI_SVS.h"

#include "PlatformDataTypes.h"

static const uint16_t trailerDisconnectThresh_u16 = 150u;

/* trailerinfo::TrlrCalInfo::Enum */
#ifndef RTW_HEADER_TeTRSC_e_TrlrCalInfo_h_
#define RTW_HEADER_TeTRSC_e_TrlrCalInfo_h_
typedef enum
{
    TeTRSC_e_TrlrCalInfo_NotCalibrated = 0,/* Default value */
    TeTRSC_e_TrlrCalInfo_Calibrated = 1,
    TeTRSC_e_TrlrCalInfo_Undefined = 2,
    TeTRSC_e_TrlrCalInfo_Dummy = MAX_int32_T
} TeTRSC_e_TrlrCalInfo;
#endif
typedef enum
{
    TeTRSC_e_TrlrCalInfo_Calibrated_DID = 0, /* Default value */
    TeTRSC_e_TrlrCalInfo_NotCalibrated_DID = 1,
    TeTRSC_e_TrlrCalInfo_SNA_DID = 2,
    TeTRSC_e_TrlrCalInfo_Dummy_DID = MAX_int32_T
} TeTRSC_e_TrlrCalInfo_DID;

#ifndef RTW_HEADER_TeTRSC_e_TrlrRecogInfo_h_
#define RTW_HEADER_TeTRSC_e_TrlrRecogInfo_h_
typedef enum { TeTRSC_e_TrlrRecogInfo_Unknown = 0,
               TeTRSC_e_TrlrRecogInfo_Known = 1,
               TeTRSC_e_TrlrRecogInfo_Dummy = MAX_int32_T
             } TeTRSC_e_TrlrRecogInfo;
#endif

typedef enum 
{ 
  TeTRSC_e_TrlrRecogInfo_Known_DID = 0,
  TeTRSC_e_TrlrRecogInfo_Unknown_DID = 1,
  TeTRSC_e_TrlrRecogInfo_No_Trailer_Detected_DID = 2,
  TeTRSC_e_TrlrRecogInfo_SNA_DID = 3,
  TeTRSC_e_TrlrRecogInfo_Dummy_DID = MAX_int32_T
} TeTRSC_e_TrlrRecogInfo_DID;

#ifndef RTW_HEADER_TeTRSC_e_TrlrPrsntInfo_h_
#define RTW_HEADER_TeTRSC_e_TrlrPrsntInfo_h_
typedef enum
{
    TeTRSC_e_TrlrPrsntInfo_Unknown = 0,
    TeTRSC_e_TrlrPrsntInfo_NoTrlr = 1,
    TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt = 2,
    TeTRSC_e_TrlrPrsntInfo_Dummy = MAX_int32_T
} TeTRSC_e_TrlrPrsntInfo;
#endif

typedef enum
{
    TeTRSC_e_TrlrPrsntInfo_Not_Detected_DID = 0,
    TeTRSC_e_TrlrPrsntInfo_Detected_DID = 1,
    TeTRSC_e_TrlrPrsntInfo_SNA_DID = 2,
    TeTRSC_e_TrlrPrsntInfo_Dummy_DID = MAX_int32_T
} TeTRSC_e_TrlrPrsntInfo_DID;

#ifndef RTW_HEADER_TeTRSC_e_TrailerCalibMemClearReq_h_
#define RTW_HEADER_TeTRSC_e_TrailerCalibMemClearReq_h_
typedef enum
{
	TeTRSC_e_Unknown = 0,
	TeTRSC_e_Clear = 1,
	TeTRSC_e_TrailerCalibMemClearReq_Dummy = MAX_int32_T
} TeTRSC_e_TrailerCalibMemClearReq;
#endif
#ifndef RTW_HEADER_TeTRSC_e_TrailerCalibMemClearResponse_h_
#define RTW_HEADER_TeTRSC_e_TrailerCalibMemClearResponse_h_
typedef enum
{
	TeTRSC_e_Completed = 0,
	TeTRSC_e_Abort = 1,
	TeTRSC_e_TrailerCalibMemClearResponse_Dummy = MAX_int32_T
} TeTRSC_e_TrailerCalibMemClearResponse;
#endif
#ifndef RTW_HEADER_TeTRSC_e_TrailerCalibMemClearResponse_s
#define RTW_HEADER_TeTRSC_e_TrailerCalibMemClearResponse_s
typedef struct TeTRSC_e_TrailerCalibMemClearResponse_s
{
	TeTRSC_e_TrailerCalibMemClearResponse CalibMemClearResponse;
  bool_t bValid;
} TeTRSC_e_TrailerCalibMemClearResponse_t;
#endif
#ifndef RTW_HEADER_TeTRSC_e_TADState_h_
#define RTW_HEADER_TeTRSC_e_TADState_h_
typedef enum
{
    TeTRSC_e_TADState_Idle = 0,
    TeTRSC_e_TADState_TrailerDetection = 1,
    TeTRSC_e_TADState_TrailerRecognition = 2,
    TeTRSC_e_TADState_Calibration = 3,
    TeTRSC_e_TADState_ScanningForTrailer = 4,
    TeTRSC_e_TADState_Turnaround = 5,
    TeTRSC_e_TADState_AngleDetection = 6,
    TeTRSC_e_TADState_Trackinglost = 7,
    TeTRSC_e_TADState_Dummy = MAX_int32_T
} TeTRSC_e_TADState;
#endif

typedef enum
{
    TeTRSC_e_CamBlockSts_CameraBlocked,
    TeTRSC_e_CamBlockSts_CameraClear,
    TeTRSC_e_CamBlockSts_LowLight,
    TeTRSC_e_CamBlockSts_SNA,
    TeTRSC_e_CamBlockSts_Dummy = MAX_int32_T
} TeTRSC_e_CamBlockSts;

typedef enum TrlrCalInfo_e
{
  NotCalibrated,
  Calibrated,
  undefined,
  TrlrCalInfo_MAX = 0xFFFFFFFF
}TrlrCalInfo_t;

/* calibration::State::Enum*/
typedef enum State_e
{
  DriveStraight,
  TurnLeftOrRight,
  Wait,
  State_MAX = 0xFFFFFFFF
}State_t;


/* trailerinfo::TrailerCalibrationFailInfo::Enum*/
typedef enum TrailerCalibrationFailInfo_e
{
  No_Failure,
  Camera_Blocked,
  Gear_IN_Reverse,
  TrailerCalibrationFailInfo_MAX = 0xFFFFFFFF
}TrailerCalibrationFailInfo_t;

typedef enum TrailerCalibrationFailInfo_e_DID
{
  More_Turn_Radius_or_Arc_Length_DID = 0,
  More_Straight_driving_DID = 1,
  Camera_Blocked_or_low_Light = 2,
  No_Failure_DID = 3,
  SNA_DID = 4,
  TrailerCalibrationFailInfo_MAX_DID = 0xFFFFFFFF
}TrailerCalibrationFailInfo_DID_t;

/* trailerinfo::TrailerPresentInfo::Enum*/
typedef enum TrailerPresentInfo_e
{
  UNKNOWN,
  NO_TRAILER,
  TRAILERPRESENT,
  TrailerPresentInfo_MAX = 0xFFFFFFFF
}TrailerPresentInfo_t;

/* tad::TrailerID::Enum*/
typedef enum TrailerID_e
{
    Trailer_ID1,
    Trailer_ID2,
    Trailer_ID3,
    Trailer_ID4,
    Trailer_ID5,
    // Trailer_ID6, // remove 1 memory from memorypool.h
    Trailer_MAX,
    TrailerID_MAX = 0xFFFFFFFF
} TrailerID_t;

/* trailerinfo::RecognitionInfo::Enum*/
typedef enum RecognitionInfo_e
{
  unknown,
  known,
  RecognitionInfo_MAX = 0xFFFFFFFF
}RecognitionInfo_t;

typedef enum DetectionFailInfo_e
{
  DetectionFailInfo_SNA,
  DetectionFailInfo_NONE,
  DetectionFailInfo_OCCULSION,
  DetectionFailInfo_MAX = 0xFFFFFFFF
}DetectionFailInfo_t;

typedef enum DetectionFailInfo_DID_e
{
  DetectionFailInfo_OCCULSION_or_LOWLIGHT_DID,
  DetectionFailInfo_NONE_DID,
  DetectionFailInfo_SNA_DID,
  DetectionFailInfo_MAX_DID = 0xFFFFFFFF
}DetectionFailInfo_DID_t;

typedef enum CalibrationState_e
{
    CalibrationState_DriveStraight,
    CalibrationState_TurnLeftOrRight,
    CalibrationState_Wait,
    CalibrationState_MAX = 0xFFFFFFFF
} CalibrationState_t;

typedef enum CalibrationState_DID_e
{
    CalibrationState_DriveStraight_DID,
    CalibrationState_TurnLeftOrRight_DID,
    CalibrationState_None_DID,
    CalibrationState_SNA_DID,
    CalibrationState_MAX_DID = 0xFFFFFFFF
} CalibrationState_DID_t;

typedef enum TurnAroundState_s
{
    TurnAroundState_DriveStraight,
    TurnAroundState_TurnLeftOrRight,
    TurnAroundState_Wait,
    TurnAroundState_MAX = 0xFFFFFFFF
} TurnAroundState_t;
//PP
/*TAD to Diagnotics, A72 to mcu1_0*/
#ifndef RTW_HEADER_TrailerDetection_Output_DID_s
#define RTW_HEADER_TrailerDetection_Output_DID_s
typedef struct TrailerDetection_Output_DID_s
{
  // Trailer Tracking Confidence
  float32_t Trailer_tracking_confidence; // IeTRSC_pct_TrlrTrackConf
  // trailer recognition confidence
  float32_t Trailer_Recognition_Confidence; // IeTRSC_pct_TrlrRecogConf
  // trailer calibration status
  TeTRSC_e_TrlrCalInfo Trailer_Calibration_Status; // IeTRSC_e_TrlrCalibSts
  // trailer maeuver state
  CalibrationState_t Trailer_Calibration_maneuver_State; // IeTRSC_e_TrlrCalibManState
  // calibration fail count
  uint32_t Trailer_Calibration_Fail_Count; // IeTRSC_cnt_TrlrCalibFailCnt
  // calibration fail reason
  TrailerCalibrationFailInfo_t Trailer_Calibration_Fail_Reason; // IeTRSC_e_TrlrCalibFailReas
  // trailer calibration pass count
  uint32_t Trailer_Calibration_Pass_Count; // IeTRSC_cnt_TrlrCalibPassCnt
  // trailer presence detection
  TeTRSC_e_TrlrPrsntInfo Trailer_Presence_detection; // IeTRSC_e_TrlrPrsntSts
  // trailer ID
  TrailerID_t Trailer_Recognition_ID; // IeTRSC_e_TrailerID
  // trailer known or unknown
  TeTRSC_e_TrlrRecogInfo Trailer_known_or_Unknown; // IeTRSC_e_TrlrRecogInfo
  //Trailer detection fail info
  DetectionFailInfo_t trailerDetectionFailReason;
  // trailer angle
  float32_t Trailer_Angle_current; // IeTRSC_deg_TADAngle
    TeTRSC_e_CamBlockSts IeTRSC_e_CamBlockSts;
	TeTRSC_e_TrailerCalibMemClearResponse_t IeTRSC_e_TrailerCalibMemClearResponse;
  //Trailer Calibration maneuver State
  CalibrationState_DID_t Trailer_Calibration_maneuver_State_DID;
  //Trailer Calibration Status
  TeTRSC_e_TrlrCalInfo_DID Trailer_Calibration_Status_DID;
  //Trailer Trailer_Calibration_Fail_Count Current key cycle
  uint32_t Trailer_Calibration_Fail_Count_Current_key_cycle;
  //Trailer_Calibration_Fail_Reason
  TrailerCalibrationFailInfo_DID_t Trailer_Calibration_Fail_Reason_DID;
  //Trailer_Calibration_Pass_Count
  uint32_t Trailer_Calibration_Pass_Count_Current_key_cycle;
  //Trailer_Presence_detection
  TeTRSC_e_TrlrPrsntInfo_DID Trailer_Presence_detection_DID;
  //Trailer Presence detection failure reason
  DetectionFailInfo_DID_t trailerDetectionFailReason_DID;
  //Trailer_known_or_Unknown
  TeTRSC_e_TrlrRecogInfo_DID Trailer_known_or_Unknown_DID;
  //Trailer detection confidence
  float32_t Trailer_detection_Confidence;
} TrailerDetection_Output_DID_t;
#endif

typedef enum TADState_e
{
  TADState_Idle,
  TADState_TrailerDetection,
  TADState_TrailerRecognition,
  TADState_Calibration,
  TADState_ScanningForTrailer,
  TADState_Turnaround,
  TADState_AngleDetection,
  TADState_Trackinglost
}TADState_t;

typedef struct TrailerParameters_s
{
  float32_t beamLength_mm;
  float32_t width_mm;
  float32_t frontOverhang_mm;
}TrailerParameters_t;
typedef enum TrailerAngleSign_e
{
  TrailerAngleSign_Clockwise,
  TrailerAngleSign_Anticlockwise,
  TrailerAngleSign_None,
  TrailerAngleSign_MAX = 0xFFFFFFFF
}TrailerAngleSign_t;

typedef struct TRSC_Inputs_from_TrailerDetection_s
{
  // --- Debug CAN output variables for TAD
  float32_t m_leftCalibrationAngle;
  float32_t m_rightCalibrationAngle;
  float32_t m_hitchCalibrationAngle;
  float32_t m_averageIllumination;
  // --- Main output variables
  // the current trailer angle (deg)
  float32_t MeTRSC_deg_TADAngle;//trailerAngle;
  // angle rate of change
  float32_t MeTRSC_deg_TADAngleRate;//TADAngleRate;
  // Beam Length supposedly gotten from Turnaround State
  float32_t MeTRSC_m_DetTrailerBeamLen;// beamLength; // MeTRSC_m_DetTrailerBeamLen - NVM Read
  float32_t MeTRSC_m_HitchLength;//hitchLength; // MeTRSC_m_HitchLength
  float32_t MeTRSC_deg_DetJackknifeThrAngle; // MeTRSC_deg_DetJackknifeThrAngle - NVM Read
  float32_t MeTRSC_deg_DetJackKnifeAngle; // MeTRSC_deg_DetJackKnifeAngle - NVM Read
  // trailer calibration fail count
  uint32_t MeTRSC_cnt_TrlrCalibFailCntInfo; // MeTRSC_cnt_TrlrCalibFailCntInfo
  // trailer Angle Sign
  TrailerAngleSign_t MeTRSC_e_TrlrAngSign; //TrailerAngleSign
  // return current Trailer ID
  TrailerID_t MeTRSC_e_TrailerID; //CurrentTrailer_ID
  // --- States
  // the current state
  TeTRSC_e_TADState MeTRSC_e_TADState;//curState; // MeTRSC_e_TADState
  // the current sub-state
  CalibrationState_t MeTRSC_e_TADCalibrationSubstate; // MeTRSC_e_TADCalibrationSubstate
  // the current TurnAround sub-state
  TurnAroundState_t MeTRSC_e_TurnAroundSubState; // MeTRSC_e_TurnAroundSubState
  // trailer calibration info
  TeTRSC_e_TrlrCalInfo MeTRSC_e_TrlrCalInfo; //MeTRSC_e_TrlrCalInfo
  // trailer Recognition info
  TeTRSC_e_TrlrRecogInfo MeTRSC_e_TrlrRecogInfo; //MeTRSC_e_TrlrRecogInfo
  // trailer Present info
  TeTRSC_e_TrlrPrsntInfo MeTRSC_e_TrlrPrsntInfo; //MeTRSC_e_TrlrPrsntInfo
  // trailer CalibrationFail Info
  TrailerCalibrationFailInfo_t MeTRSC_e_CalFail; // MeTRSC_e_CalFail
  // OTBL recalibrate
  bool_t MeTRSC_b_OBTLRecalibrate; //MeTRSC_b_OBTLRecalibrate
  // Trailer Calibration Delay
  bool_t MeTRSC_b_TrlrCalibDelayInfo; // MeTRSC_b_TrlrCalibDelayInfo
} TRSC_Inputs_from_TrailerDetection_t;


typedef struct TRSC_Tunable_Param_s
{
    float32_t trailerBeamLengthRange_mm[2];
    uint32_t hitchYOffset[2];
    int32_t defaultHitchPoint[2];/*Index 0: X cordinate, Index 1: y cordinate*/
    float32_t rearBumper2hitch_mm;
    int32_t pointY;
    float32_t threshold;
    float32_t assumedInitialAngle;
    float32_t angleTolerance_deg;
    uint32_t hitchXPos;
    float32_t topViewPixelInfo;
    float32_t weightFactor;
    uint32_t outputFilterSize;
    float32_t TrackingLostThreshold;
    float32_t angleToReachBeforeRecalibrating;
    float32_t angleTolerance;
    float32_t maxAngleOffset;
    int32_t trailerID;
    int32_t showCalibrationAngles;
    uint32_t rateOfAngleChangeBufSize;
    float32_t length_mm;
    float32_t width_mm;
    float32_t frontOverhang_mm;
    float32_t rearOverhang_mm;
    float32_t wheelBase_mm;
    float32_t WhlAngCFWt;
    float32_t WhlAngCFBias;
    uint8_t kinematicsEnabled;
    uint8_t simulateTimeStamp;
    uint8_t vehicleWheelAngleClockwise;
    uint8_t enabledTrailerPresenceDetection;
    uint8_t enabledTrailerRecognition;
    uint8_t enabledCollisionAngleSetction;
    uint8_t enabledTrailerAngleCalibration;
    uint8_t enabledHitchDetection;
    uint8_t hitchMaskEnabled;
    uint8_t PreprocessingEnabled;
    uint8_t enabledTurnAround;
    uint8_t stopMatchingWhenVehicleStopped;
    uint8_t TrackingLost;
    uint8_t DynamicWindowSize;
    uint8_t AngleFilerEnable;
    uint8_t enableContinuousCalibration;
    uint8_t onlyCalibrateWhenAngleIsOff;
    uint8_t allowQuickCalibration;
    uint8_t calibrateNewTrailer;
    uint8_t calibrateHitchPoint;
    uint8_t showSecondAngle;
    uint8_t dummy1;
    uint8_t dummy2;
    uint8_t dummy3;
} TRSC_Tunable_Param_t;

typedef struct debugPointOnImage_tag
{
  uint16_t cordX;
  uint16_t cordY;
} debugPointOnImage;

typedef struct TrailerDetection_Output_HMI_s
{
  // the current trailer angle (deg)
  float32_t trailerAngle;
  // return current Trailer ID
  TrailerID_t CurrentTrailer_ID;
  // Trailer Tracking Confidence
  float32_t Trailer_tracking_confidence;
  // trailer recognition confidence
  float32_t Trailer_Recognition_Confidence;
  // the current state
  TeTRSC_e_TADState curState;
  // the current sub-state
  CalibrationState_t calibrationSubState;
  // the current TurnAround sub-state
  TurnAroundState_t turnaroundSubState;
  float32_t beamLength;
  float32_t hitchLength;
  float32_t JackknifeThrAngle;
  float32_t JackknifeAngle;
  // hitch point
  debugPointOnImage hitchpoint;
  //vehicle speed
  float32_t vehicle_speed;
  // wheel angle
  float32_t wheelAngle;
  // TAD angle
  debugPointOnImage Start_HitchPoint;
  debugPointOnImage End_AnglePoint;
  debugPointOnImage End_KniematicsPoint1;
  debugPointOnImage End_KniematicsPoint2;
  bool_t AngleON;
  bool_t KinematicsON;
} TrailerDetection_Output_HMI_t;

#ifndef RTW_HEADER_TRSC_Output_from_VehicleControl_t
#define RTW_HEADER_TRSC_Output_from_VehicleControl_t
typedef struct TRSC_Output_from_VehicleControl_s
{
    real32_T MeTRSC_M_TRSCStrTrq;          /* '<Root>/MeTRSC_M_TRSCStrTrq' */
    TeTRSC_e_SpdLmtReq MeTRSC_e_SpdLmtReq;/* '<Root>/MeTRSC_e_SpdLmtReq' */
    real32_T MeTRSC_e_KnobAngle;         /* '<Root>/MeTRSC_e_KnobAngle' */
    bool_t TwitchComp;                /* '<Root>/TwitchComp' */
    // ASR
    real32_T IPAACT;                     /* '<Root>/IPAACT' */
    real32_T STR_CMD_deg;                /* '<Root>/STR_CMD_deg' */
    real32_T str_msg_int_Left_Right;       /* '<Root>/str_msg_int_Left_Right' */
    real32_T steer_change;               /* '<Root>/steer_change' */
    real32_T TAD_predicted_deg;          /* '<Root>/TAD_predicted_deg' */
    real32_T TrailerSwing_int_LeftRight; /* '<Root>/TrailerSwing_int_LeftRight' */
    real32_T JackKnife_deg_out;          /* '<Root>/JackKnife_deg_out' */
    bool_t brak_msg;                  /* '<Root>/brak_msg' */
    bool_t showFlag;                  /* '<Root>/showFlag' */
    real32_T TLB_m;                      /* '<Root>/TLB_m' */
    real32_T KM_TAD;                     /* '<Root>/KM_TAD' */
    real32_T IeLSCAN_v_VehSp_pulse;      /* '<Root>/IeLSCAN_v_VehSp_pulse' */
    real32_T TBL_fail;                   /* '<Root>/TBL_fail' */
} TRSC_Output_from_VehicleControl_t;
#endif

#ifndef RTW_HEADER_TRSC_CALIBRATION_CLEAR_t
#define RTW_HEADER_TRSC_CALIBRATION_CLEAR_t
typedef struct TRSC_CalibrationClear_s
{
	TeTRSC_e_TrailerCalibMemClearReq TRSC_Calib_Clear_Req;
}TRSC_CalibrationClear_t;
#endif
typedef SVStoTRSC_t SVStoTRSCSMVC_t;

typedef struct {
  uint8_T MeTRSC_e_CamBlockSts;
} MeDLD_e_RrCamSts_t;

/*SVS to TRSC SMVC, mcu2_0 to mcu2_0*/
/*SVStoTRSCSMVC_t*/

/*TAD to TRSC, A72 to mcu2_0*/
/*TRSC_Inputs_from_TrailerDetection_t*/

/*DLD to TRSC SMVC, A72 to mcu2_0*/
/*MeDLD_e_RrCamSts_t*/

/*TRSC SMVC to VCAN, mcu2_0 to mcu1_0, mcu2_1*/
/*ME_VehOut_TRSC_t*/

/*TRSC SMVC to SVS, mcu2_0 to mcu2_0*/
/*TRSCSMVCtoSVS_t*/

/*TRSC SMVC to TAD, mcu2_0 to mcu2_0*/
/*Detection_Inputs_from_TRSC_t*/

/* TAD Algo to Diag, A72 to mcu1_0*/
/* TrailerDetection_Output_DID_t */

/* TRSC SMVC to Diag, mcu2_0 to mcu1_0*/
/* TRSCtoDiagMgr_t */

/* A72 to A72 */
/* JobTADDebugOutput */

/* mcu1_0 to mcu2_0*/
/* TbTRSCSmVc_TunParam_t */

/* mcu1_0 to A72*/
/* TRSC_Tunable_Param_t */

/* A72 to A72 */
/* TrailerDetection_Output_HMI_t */


#endif // TRSC_INPUTS_OUTPUTS_H_INCGUARD
