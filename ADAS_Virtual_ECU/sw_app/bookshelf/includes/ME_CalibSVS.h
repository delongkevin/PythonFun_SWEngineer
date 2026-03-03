/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 * This document in its entirety is CONFIDENTIAL and may not be disclosed,
 * disseminated or distributed to parties outside MAGNA Electronics
 * without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:       Header File for SVS camera calibration State Machine
 * DESIGN:      2022
 * DESCRIPTION: Header File for SVS camera calibration State Machine
 * ======================================================================== */

/**
 * \file     ME_CalibSVS.h
 * \brief    Platform specific defines and typedefs
 * \author   Prasad Pachpande
 * \version  $Revision: 1.1 $
 * \details  h file public description of module
 */
 
 #ifndef ME_CALIB_SVS_H_
#define ME_CALIB_SVS_H_

#include "HMI_SVS.h"
#include "PlatformDataTypes.h"

#define EOL_ITERATION_COUNT             5
#define ME_HYDRA3DEFS_D_CAMERACOUNT     4
#define ME_HYDRA3DEFS_D_ALGOCONTROL_SIZE            (3) /* as defined per PrivateCAN protocol, sizeof does not work 'cause of compiler alignment with C bit fields */
#define ME_HYDRA3DEFS_D_ALGOCONTROLDATA_MAXLLENGTH  ((256+32) - ME_HYDRA3DEFS_D_ALGOCONTROL_SIZE)
#define SC_ALGO_ACTIVE_BYTE             4
#define EOL_ALGO_ACTIVE_BYTE            5
#define OC_ALGO_ACTIVE_BYTE             6

/**************************************************************************************************
 *
 * Description : Common structures/enum used for interfaces  
 *
 **************************************************************************************************/

/* Camera ID */
#if !defined(BUILD_MCU2_0)
typedef enum ME_Hydra3defs_E_CameraID_e
{
  CamID_None,     /* 0 */
  CamID_Front,    /* 1 */
  CamID_Left,     /* 2 */
  CamID_Rear,     /* 3 */
  CamID_Right,    /* 4 */
  CamID_5th,      /* 5 */
  CamID_Invalid,  /* 6 */
  CamID_Size_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_CameraID_t;
#endif
typedef enum ME_Hydra3defs_E_CalibrationID_s
{
  CalibrationID_Zero,
  CalibrationID_EOL,
  CalibrationID_SC,
  CalibrationID_OC,
  CalibrationID_Current,
  CalibrationID_Size_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_CalibrationID_t;

typedef enum ME_Hydra3defs_E_EraseCameraID_e
{
  Erase_CalibrationID_None,
  Erase_CalibrationID_front,
  Erase_CalibrationID_left,
  Erase_CalibrationID_rear,
  Erase_CalibrationID_right,
  Erase_CalibrationID_chmsl,
  Erase_CalibrationID_all= 0xFF
 
} ME_Hydra3defs_E_EraseCameraID_t;

/* Calibration Status  */

typedef enum ME_Hydra3defs_E_CalibStatus_e
{
  ME_Hydra3defs_E_CalibNotStarted,
  ME_Hydra3defs_E_CalibPending,
  ME_Hydra3defs_E_CalibRunning,
  ME_Hydra3defs_E_CalibCompletedSuccessful,
  ME_Hydra3defs_E_CalibAbortedFailed,
  ME_Hydra3defs_E_CalibStatus_Size_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_CalibStatus_t;

/* EOL, SC and OC Algo States  */

typedef enum ME_Hydra3defs_E_EOLAlgoState_e
{
  e_EOLNotInit = 0,
  e_EOLRunning,
  e_EOLFinished,
  e_EOLAlgoState_Size_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_EOLAlgoState_t;

typedef enum ME_Hydra3defs_E_OCAlgoState_e
{
  e_OC_Uninit = 0,
  e_OC_InitOk,
  e_OC_Error,
  e_OC_FeatureCollection,          /* state after starting Algo */
  e_OC_FeatureCollectionCompleted, /* state after min. 100 features and min. 900 frames are collected */
  e_OC_Calibration,
  e_OC_CalibrationCompleted,       /* state after 1 cam is calibrated + e_OC_NoError => values in ME_Hydra2defs_S_OCStatus_t are valid */
  e_OC_Terminated,
  e_OC_Paused,
  e_OC_Unknown,
  e_OC_End,
  e_OC_AlgoState_Size_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_OCAlgoState_t;

/* EOL, SC and OC Error Codes  */

typedef enum ME_Hydra3defs_E_EOLErrorCode_e
{
  e_EOL_CALIBRATION_IN_PROCESS = 0,
  e_EOL_CALIBRATION_SUCCESS,
  e_EOL_MISSING_SOFTWARE,
  e_EOL_PRECONDITIONS_NOT_CORRECT_VRANGE,
  e_EOL_PRECONDITION_NOT_CORRECT_NUMCAMERAS,
  e_EOL_MISSING_INTERNAL_LINK,
  e_EOL_VARIANT_CODING_ISSUE,
  e_EOL_TARGET_NOT_FOUND_INIT,
  e_EOL_TARGET_NOT_FOUND_LEFT,
  e_EOL_TARGET_NOT_FOUND_RIGHT,
  e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT,
  e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT,
  e_EOL_RESULT_EXCEED_QUALITY_LIMIT,
  e_EOL_NOT_CALIBRATED,
  e_EOL_ABORTED,
  e_EOL_HMOGRAPHY_ESTIMATION_ERROR,
  e_EOL_PRECONDITION_NOT_CORRECT_VELOCITY,
  e_EOL_PRECONDITION_NOT_CORRECT_DOORS,
  e_EOL_WRONG_CAMERA_SOFTWARE,
  e_EOL_PRECONDITION_NOT_CORRECT,
  e_EOLErrorCode_Size_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_EOLErrorCode_t;

typedef enum ME_Hydra3defs_E_OCErrorCode_e
{
  e_OC_NoError = 0,
  e_OC_InitFail,
  e_OC_StartFail,
  e_OC_FeatureCollectionError,
  e_OC_CalibrationError,
  e_OC_InvalidConfiguration,
  e_OC_InvalidSavedData,
  e_OC_UnexpectedRequest,
  e_OC_Num,
  e_OCErrorCode_Size_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_OCErrorCode_t;

typedef struct ME_Hydra3defs_S_EOLTargetData_s
{
  sint8 TargetInit_s8;              /* Target Init               */
  sint8 TargetLimitFront_s8;        /* Target Limit Front        */
  sint8 TargetLimitRear_s8;         /* Target Limit Rear         */
  sint8 TargetDetectLeftFront_s8;   /* Target Detect Left-Front  */
  sint8 TargetDetectLeftRear_s8;    /* Target Detect Left-Rear   */
  sint8 TargetDetectRightFront_s8;  /* Target Detect Right-Front */
  sint8 TargetDetectRightRear_s8;   /* Target Detect Right-Rear  */
  sint8 Reserved_s8;
} ME_Hydra3defs_S_EOLTargetData_t;

/* EOL, SC and OC Status */

#if !defined(BUILD_MCU2_0)
typedef struct ME_Hydra2defs_S_EOLStatus_s
{
  float32 deltaPitch_f32;
  float32 deltaYaw_f32;
  float32 deltaRoll_f32;
  
  float32 deltaX_f32;
  float32 deltaY_f32;
  float32 deltaZ_f32;

  ME_Hydra3defs_E_EOLAlgoState_t    algoState_e;
  ME_Hydra3defs_E_EOLErrorCode_t    errorCode_e;
  ME_Hydra3defs_S_EOLTargetData_t   targetData_s;
  ME_Hydra3defs_E_CameraID_t        camID_e;
} ME_Hydra3defs_S_EOLStatus_t;
#endif

#if !defined(BUILD_MCU2_0)
typedef struct ME_Hydra3defs_S_OCStatus_s
{
  float32 deltaPitch_f32;
  float32 deltaYaw_f32;
  float32 deltaRoll_f32;

  uint32  ValidFeatures_u32;   /* Counter */
  uint32  IgnoredFeatures_u32; /* Counter */
  uint32  InvalidFeatures_u32; /* Counter */

  ME_Hydra3defs_E_OCAlgoState_t    algoState_e;
  ME_Hydra3defs_E_OCErrorCode_t    errorCode_e;
  ME_Hydra3defs_E_CameraID_t       camID_e;
} ME_Hydra3defs_S_OCStatus_t;
#endif

/**************************************************************************************************
 *
 * Description : Interfaces between SVS Camera Calibration State Machine (A72) and Communication 
 *               Bus/VCAN (mcu_1_0)
 *
 **************************************************************************************************/

/* Vehicle gear position */
typedef enum ME_TeSVS_e_GearPosCamCalib
{
  e_UNDEFINED_GEAR,  /* 0  */
  e_P_GEAR,          /* 1  */
  e_N_GEAR,          /* 2  */
  e_R_GEAR,          /* 3  */
  e_D_GEAR,          /* 4  */
  e_RESERVED_GEAR1,  /* 5  */
  e_E_GEAR,          /* 6  */
  e_S_GEAR,          /* 7  */
  e_RESERVED_GEAR2,  /* 8  */
  e_RESERVED_GEAR3,  /* 9  */
  e_RESERVED_GEAR4,  /* 10 */
  e_RESERVED_GEAR5,  /* 11 */
  e_RESERVED_GEAR6,  /* 12 */
  e_RESERVED_GEAR7,  /* 13 */
  e_RESERVED_GEAR8,  /* 14 */
  e_RESERVED_GEAR9   /* 15 */
} TeSVS_e_GearPosCamCalib;

/* Vehicle power mode */
typedef enum ME_TeSVS_e_PowerModeCamCalib
{
  e_PW_MODE_OFF=0,          /* 0 */
  e_PW_MODE_ACC,            /* 1 */
  e_PW_MODE_IGN_ON,         /* 2 */
  e_PW_MODE_CRANK_PENDING,  /* 3 */
  e_PW_MODE_RUN,            /* 4 */
  e_PW_MODE_CRANK_OFF,      /* 5 */
  e_PW_MODE_RESERVED1,      /* 6 */
  e_PW_MODE_RESERVED2       /* 7 */
} TeSVS_e_PowerModeCamCalib;   

/* Vehicle Doors position (Open/Closed) */
typedef enum ME_TeSVS_e_DoorStsCamCalib
{
  e_DoorCLOSED = 0x0, /* Door is closed */
  e_DoorOPEN   = 0x1  /* Door is open */
} TeSVS_e_DoorStsCamCalib;

/* 
 * mcu_1_0 to A72
 * (VCAN to Calib State Machine)
 * This is the extracted data from CAN message in A72. 
 * Need not to implement in communication. 
 */
typedef struct ME_TbVCAN_e_BusInputToSVSCamCalibSM_s
{
  TeSVS_e_GearPosCamCalib     IeVCU_e_GearSig;            /* VCU_0x214 */
  TeSVS_e_PowerModeCamCalib   IeBCM_e_PwrMod;             /* BCM_0x333 */
  TeSVS_e_DoorStsCamCalib     IeBCM_e_LeFrntDoorSts;      /* BCM_0x343 */
  TeSVS_e_DoorStsCamCalib     IeBCM_e_RiFrntDoorSts;      /* BCM_0x343 */
  TeSVS_e_DoorStsCamCalib     IeBCM_e_RiReDoorSts;        /* BCM_0x343 */
  TeSVS_e_DoorStsCamCalib     IeBCM_e_LeReDoorSts;        /* BCM_0x343 */
  TeSVS_e_DoorStsCamCalib     IePLGM_e_TrSts;             /* BCM_0x343 */
  TeSVS_e_DoorStsCamCalib     IeBCM_e_FrntHoodLidSts;     /* BCM_0x343 */
  float32                     IeESP_kph_VehSpd;           /* ESP_0x318 */
  float32                     IeEPS_deg_SteerWhlAgSig;    /* EPS_0x1C2 */ 
} TbVCAN_e_BusInputToSVSCamCalibSM_t;

/* Air Suspension Status*/
typedef enum ME_TeSVS_e_ASCMSts
{
  e_ASCM_Stat_NONE     = 0x0,
  e_ASCM_Stat_DUMP     = 0x1,
  e_ASCM_Stat_PARK     = 0x2,
  e_ASCM_Stat_AERO     = 0x3,
  e_ASCM_Stat_NVL      = 0x4,
  e_ASCM_Stat_OR1      = 0x5,
  e_ASCM_Stat_ORL2     = 0x6,
  e_ASCM_Stat_Lifter   = 0x7,
  e_ASCM_Stat_RAISE    = 0x8,
  e_ASCM_Stat_LOWER    = 0x9,
  e_ASCM_Stat_SYSFAIL  = 0xA,
  e_ASCM_Stat_SRVS     = 0xB,
  e_ASCM_Stat_AERO2    = 0xC,
  e_ASCM_Stat_SNA      = 0xF
  } TeSVS_e_ASCMSts;

/**************************************************************************************************
 *
 * Description : Interfaces between SVS Camera Calibration State Machine and Diag Manager
 *
 **************************************************************************************************/

typedef struct aZynqM_S_EOLCamMask
{
  uint8 camFront;
  uint8 camLeft ;
  uint8 camRear ;
  uint8 camRight;
} aZynqM_S_EOLCamMask_t;

typedef struct aZynqM_S_CamMask
{
  uint8 camFront;
  uint8 camLeft ;
  uint8 camRear ;
  uint8 camRight;
} aZynqM_S_CamMask_t;

/* EOL, SC and OC conditions */
typedef struct aZynqM_S_EOL_Conditions_s
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

typedef struct aZynqM_S_SCConditions
{
  boolean LeftFrontDoor_b;
  boolean RightFrontDoor_b;
  boolean LeftRearDoor_b;
  boolean RightRearDoor_b;
  
  boolean Hood_b;
  boolean Tailgate_b;
  boolean InnerTailgate_b;
  boolean DrivingForward;
  boolean SpeedValid_b;
  
  boolean LeftMirror_b;
  boolean RightMirror_b;
  
  boolean VehicleLevel_b;
  boolean ZynqModuleState_b;
  boolean SteeringAngle_b;
  boolean VoltageIPMB_b;
} aZynqM_S_SCConditions_t;

typedef struct aZynqM_S_OC_Conditions_s
{
  boolean Configuration_b;
  boolean ApprovedByApplication_b;
  boolean EOLSCCalibration_b;
  
  boolean DrivingForward;
  boolean SpeedValid_b;
  boolean IgnitionState_b;
} aZynqM_S_OC_Conditions_t;

/* EOL, SC and OC Module (State machine) State  */

typedef enum aZynqM_E_ModuleState_EOL_STM_e
{
  aZynqM_E_EOL_STM_E_NotInit = 0u,
  aZynqM_E_EOL_STM_E_Init,
  aZynqM_E_EOL_STM_E_Idle,
  aZynqM_E_EOL_STM_E_SelectCurrentCamera,
  aZynqM_E_EOL_STM_E_StartCameraCalibration,
  aZynqM_E_EOL_STM_E_CheckStatus,
  aZynqM_E_EOL_STM_E_Stop,
  aZynqM_E_EOL_STM_E_Error,
  aZynqM_E_EOL_STM_E_End,

  aZynqM_E_EOL_STM_NumStates,
  aZynqM_E_EOL_STM_Size_Enforcer = 0xFFFFFFFF
} aZynqM_E_ModuleState_EOL_STM_t;

typedef enum aZynqM_E_ModuleState_SC_STM_e
{
  aZynqM_E_SC_STM_E_NotInit = 0u,
  aZynqM_E_SC_STM_E_Init,
  aZynqM_E_SC_STM_E_Idle,
  aZynqM_E_SC_STM_E_WaitForEEPROMRead,
  aZynqM_E_SC_STM_E_SelectCurrentCamera,
  aZynqM_E_SC_STM_E_StartCameraCalibration,
  aZynqM_E_SC_STM_E_CheckStatus,
  aZynqM_E_SC_STM_E_Pause,
  aZynqM_E_SC_STM_E_Paused,
  aZynqM_E_SC_STM_E_Resume,
  aZynqM_E_SC_STM_E_Stop,
  aZynqM_E_SC_STM_E_Error,
  aZynqM_E_SC_STM_E_End,

  aZynqM_E_SC_STM_NumStates,
  aZynqM_E_SC_STM_Size_Enforcer = 0xFFFFFFFF
} aZynqM_E_ModuleState_SC_STM_t;

typedef enum aZynqM_E_ModuleState_OC_STM_e
{
  aZynqM_E_OC_STM_NotInit = 0u,
  aZynqM_E_OC_STM_Init,
  aZynqM_E_OC_STM_Idle,

  aZynqM_E_OC_STM_SelectCurrentCamera,

  aZynqM_E_OC_STM_StartCameraCalibration,

  aZynqM_E_OC_STM_CheckStatus,

  aZynqM_E_OC_STM_Pause,
  aZynqM_E_OC_STM_Paused,

  aZynqM_E_OC_STM_Resume,

  aZynqM_E_OC_STM_Stop,

  aZynqM_E_OC_STM_Error,
  aZynqM_E_OC_STM_End,

  aZynqM_E_OC_STM_NumStates,
  aZynqM_E_OC_STM_Size_Enforcer = 0xFFFFFFFF
} aZynqM_E_ModuleState_OC_STM_t;

/* 
 * A72 to mcu_1_0
 * (SVS Camera Calib State Machine to Diag Manager)
 */
 
#if !defined(BUILD_MCU2_0)
typedef struct ME_TbSVS_e_SVSOutputToDiagMgrCamCalib_s
{
  boolean EOL_v_IsRequestedByDiag_b;
  boolean SC_v_IsRequestedByDiag_b;
  
  boolean EOLCompletedCurrentCycle;
  boolean SCCompletedCurrentCycle;
  
  aZynqM_S_EOL_Conditions_t        EOL_StartConditions_STM;
  aZynqM_S_SCConditions_t          SC_StartConditions_STM;
  aZynqM_S_OC_Conditions_t         OC_StartConditions_STM;
  
  aZynqM_E_ModuleState_EOL_STM_t   EOL_ModuleState_STM; 
  aZynqM_E_ModuleState_SC_STM_t    SC_ModuleState_STM;
  aZynqM_E_ModuleState_OC_STM_t    OC_ModuleState_STM;

  ME_Hydra3defs_S_EOLStatus_t      EOL_Status_STM[ME_HYDRA3DEFS_D_CAMERACOUNT];
  ME_Hydra3defs_S_OCStatus_t       SC_Status_STM[ME_HYDRA3DEFS_D_CAMERACOUNT];
  ME_Hydra3defs_S_OCStatus_t       OC_Status_STM[ME_HYDRA3DEFS_D_CAMERACOUNT];

  ME_Hydra3defs_E_CalibStatus_t    EOL_CalibStatus_STM[ME_HYDRA3DEFS_D_CAMERACOUNT];
  ME_Hydra3defs_E_CalibStatus_t    SC_CalibStatus_STM[ME_HYDRA3DEFS_D_CAMERACOUNT];
  ME_Hydra3defs_E_CalibStatus_t    OC_CalibStatus_STM[ME_HYDRA3DEFS_D_CAMERACOUNT];
} TbSVS_e_SVSOutputToDiagMgrCamCalib_t;
#endif

/* 
 * mcu_1_0 to A72
 * (Diag Mgr to SVS Camera Calib State Machine)
 */
 
typedef struct ME_Hydra3defs_E_EraseCalibNVMData_s
{
  boolean                           isCalibNVMEraseRequested;
  boolean                           isCalibResetRoutineEraseRequested;
  ME_Hydra3defs_E_CalibrationID_t   EraseCalibType;
  ME_Hydra3defs_E_EraseCameraID_t   EraseCamId;
}ME_Hydra3defs_E_EraseCalibNVMData_t;
typedef struct ME_TbSVS_e_DiagMgrOutputToSVSCamCalibSM_s
{
  boolean                           isRoutineRequested;
  uint8                             targetID;
  uint16                            targetDistance;
  aZynqM_S_CamMask_t                cameraMask;
  ME_Hydra3defs_E_CalibrationID_t   calibType;
  ME_Hydra3defs_E_EraseCalibNVMData_t EraseCalibNVMData;
} TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t;

/**************************************************************************************************
 *
 * Description : Interfaces between SVS Camera Calibration State Machine and Algorithm 
 *
 **************************************************************************************************/

typedef enum ME_Hydra3defs_E_AlgoCommand_e
{
  AlgoCommand_Stop,
  AlgoCommand_Start,
  AlgoCommand_Pause,
  AlgoCommand_Status,
  AlgoCommand_Sync,
  AlgoCommand_GetResults,
  AlgoCommand_Resume,
  AlgoCommand_Set,
  AlgoCommand_Debug,
  AlgoCommand_Unknown    /* 'Unknown' must be last entry (VALID_ENTRY < AlgoCommand_Unknown) */
  /* AlgoCommand_XX */
} ME_Hydra3defs_E_AlgoCommand_t;

typedef enum ME_Hydra3defs_E_AlgoID_e
{
  /* Values 3 is not used to match with Algo type enums */
  AlgoID_None =0,
  AlgoID_EOL =1,
  AlgoID_OC = 2,
  AlgoID_SC = 4,
  AlgoID_Count = 5
  /* Algo_XX */
} ME_Hydra3defs_E_AlgoID_t;

#if !defined(BUILD_MCU2_0)
typedef struct ME_Hydra3defs_S_AlgoControlHeader_s
{
  ME_Hydra3defs_E_AlgoID_t      AlgoID          ;
  ME_Hydra3defs_E_AlgoCommand_t AlgoCommand     ;
  ME_Hydra3defs_E_CameraID_t    CurrentCamID    ;
} ME_Hydra3defs_S_AlgoControlHeader_t;

typedef struct ME_Hydra3defs_S_AlgoControlData_s
{
  uint8       data[ME_HYDRA3DEFS_D_ALGOCONTROLDATA_MAXLLENGTH];
  uint16      length;
} ME_Hydra3defs_S_AlgoControlData_t;

/* 
 * A72 to A72
 * (SVS Camera Calib State Machine to SVS Camera Calib Algo)
 */
typedef struct ME_TbSVS_e_SVSCalibSMToAlgoCamCalib_s
{
  ME_Hydra3defs_S_AlgoControlHeader_t AlgoCntrlHeader_t;
  ME_Hydra3defs_S_AlgoControlData_t   AlgoCntrlData_t;
} TbSVS_e_SVSCalibSMToAlgoCamCalib_t;
#endif

/* 
 * A72 to A72
 * (SVS Camera Calib Algo to SVS Camera Calib State Machine)
 */
#if !defined(BUILD_MCU2_0)
typedef struct ME_TbSVS_e_SVSCalibAlgoToSMCamCalib_s
{
  ME_Hydra3defs_E_AlgoID_t CalibAlgoType;
  ME_Hydra3defs_S_EOLStatus_t EOL_Status_STM;
#if 0
  ME_Hydra3defs_S_OCStatus_t  SC_Status_STM;
#endif
  ME_Hydra3defs_S_OCStatus_t  OC_Status_STM;
} TbSVS_e_SVSCalibAlgoToSMCamCalib_t;
#endif

/**************************************************************************************************
 *
 * Description : Interfaces between SVS Camera Calibration State Machine (A72) and HMI (mcu2_0) 
 *
 **************************************************************************************************/
typedef struct aZynqM_S_TscScreenType
{
  OverlayBits_t Tsc_OverlayBits;
} aZynqM_S_ScScreenType_t;

/*
 * A72 to mcu2_0
 * ( SVS Camera Calib State Machine to HMI )
 */
typedef struct ME_TbSVS_e_SVSCalibSMToHmi_s
{
  boolean IsHmiActive_b;
  boolean IsScRequestedByDiag_b;
  aZynqM_S_ScScreenType_t CalibScreen;
} TbSVS_e_SVSCalibSMToHmi_t;

/**************************************************************************************************
 *
 * Description : Interfaces between SVS Camera Calibration State Machine (A72) and NVM (mcu 1_0) 
 *
 **************************************************************************************************/

typedef struct ME_Hydra3defs_S_CamCalibData_s
{
  float32 Pitch_f32;
  float32 Yaw_f32;
  float32 Roll_f32;

  ME_Hydra3defs_E_CalibStatus_t CalibStatus_e      ;
  boolean                       NewValueAvailable_b;
  boolean                       OverwriteStatus_b  ;
} ME_Hydra3defs_S_CamCalibData_t;

typedef struct ME_Hydra3defs_S_CamEOLCalibData_s
{
  ME_Hydra3defs_S_CamCalibData_t calibdata; /* delta values compared to design */

  float32 X_f32; /* delta values compared to design */
  float32 Y_f32; /* delta values compared to design */
  float32 Z_f32; /* delta values compared to design */

  uint8   EOLIterationData_au8[EOL_ITERATION_COUNT];
  uint8   Reserved_u8[7];
} ME_Hydra3defs_S_CamEOLCalibData_t; 


/*
 * mcu_1_0 to A72
 * (NVM to Calibration state machine)
 */
typedef struct ME_TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_s
{
  uint8 OC_Control_u8;                     /* 0x0 == DISABLED; 0x1 == ENABLED */
  uint16 OC_SpeedLimit_u16;                /* km/h in steps of 1 km/h */
  uint8 OC_ApplyResults_u8;                /* 0x0 == DISABLED; 0x1 == ENABLED */
  uint8 OC_Weighting_u8;                   /* in Percent */
} TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t;

/* EOL/Current calib data */
typedef struct ME_Hydra3defs_S_CamEOLCalibDataSTM_s
{
  ME_Hydra3defs_S_CamEOLCalibData_t   CamCalibData_STM;
  ME_Hydra3defs_E_CalibrationID_t     CamCalibIDs_STM;
} ME_Hydra3defs_S_CamEOLCalibDataSTM_t;

/* SC/OC calib data */
typedef struct ME_Hydra3defs_S_CamCalibDataSTM_s
{
  ME_Hydra3defs_S_CamCalibData_t      CamCalibData_STM;
  ME_Hydra3defs_E_CalibrationID_t     CamCalibIDs_STM;
} ME_Hydra3defs_S_CamCalibDataSTM_t;

/*
 * A72 to mcu_1_0
 * (SVS EOL Camera Calib State Machine to NVM)
 */
typedef struct ME_Hydra3defs_S_SVSCamEOLCalibData_s
{
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamFrontEOL;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamLeftEOL;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamRearEOL;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamRightEOL;
} TbSVS_S_SVSCamEOLCalibData_t;

typedef struct ME_Hydra3defs_S_SVSCamEOLCalibDataToNVM_s
{
  boolean bValid;
  uint32  FreshnessCount;
  TbSVS_S_SVSCamEOLCalibData_t CamEOL;
} TbSVS_S_SVSCamEOLCalibDataToNVM_t;

/*
 * A72 to mcu_1_0
 * (SVS SC Camera Calib State Machine to NVM)
 */
typedef struct ME_Hydra3defs_S_SVSCamSCCalibData_s
{
  ME_Hydra3defs_S_CamCalibDataSTM_t CamFrontSC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamLeftSC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamRearSC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamRightSC;
} TbSVS_S_SVSCamSCCalibData_t;

typedef struct ME_Hydra3defs_S_SVSCamSCCalibDataToNVM_s
{
  boolean bValid;
  uint32  FreshnessCount;
  TbSVS_S_SVSCamSCCalibData_t CamSC;
} TbSVS_S_SVSCamSCCalibDataToNVM_t;

/*
 * A72 to mcu_1_0
 * (SVS OC Camera Calib State Machine to NVM)
 */
typedef struct ME_Hydra3defs_S_SVSCamOCCalibData_s
{
  ME_Hydra3defs_S_CamCalibDataSTM_t CamFrontOC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamLeftOC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamRearOC;
  ME_Hydra3defs_S_CamCalibDataSTM_t CamRightOC;
} TbSVS_S_SVSCamOCCalibData_t;

#if !defined(BUILD_MCU2_0)
typedef struct ME_Hydra3defs_S_SVSCamOCCalibDataToNVM_s
{
  boolean bValid;
  uint32  FreshnessCount;
  ME_Hydra3defs_E_CameraID_t LastOCCurrentCam;
  TbSVS_S_SVSCamOCCalibData_t CamOC;
} TbSVS_S_SVSCamOCCalibDataToNVM_t;
#endif 

/*
 * A72 to mcu_1_0
 * (SVS Current Camera Calib State Machine to NVM)
 */
typedef struct ME_Hydra3defs_S_SVSCamCurrentCalibData_s
{
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamFrontCurrent;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamLeftCurrent;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamRearCurrent;
  ME_Hydra3defs_S_CamEOLCalibDataSTM_t CamRightCurrent;
} TbSVS_S_SVSCamCurrentCalibData_t;

typedef struct ME_Hydra3defs_S_SVSCamCurrentCalibDataToNVM_s
{
  boolean bValid;
  uint32  FreshnessCount;
  TbSVS_S_SVSCamCurrentCalibData_t CamCurrent;
} TbSVS_S_SVSCamCurrentCalibDataToNVM_t;

/**************************************************************************************************
 *
 * Description : Interfaces between SVS Camera Calibration State Machine and Voltage Manager
 *
 **************************************************************************************************/

/* 
 * mcu_1_0 to A72
 * (Voltage Manager to SVS Camera Calib State Machine)
 */
typedef struct ME_TbSVS_e_VtgMgrOutputToSVSCamCalibSM_s
{
  aZynqM_S_SCConditions_t IsVoltageInRange_b;
} TbSVS_e_VtgMgrOutputToSVSCamCalibSM_t;


/**************************************************************************************************
 *
 * Description : Interfaces between mcu 2_0 and   SVS Camera Manager (A72). 
 *
 **************************************************************************************************/
typedef struct ME_CameraErrorData_s
{ 
  boolean Tested_b;            
  boolean EepromCrcError_b; 
  boolean CamDataError_b;    
  boolean CamOperationError_b; 
  boolean DESError_b;   
  boolean I2CError_b;     
  boolean RunningStatus_b;  
  boolean PowerStatus_b;   
  
} ME_CameraErrorData_t;
 
 /* 
 * mcu_2_0 to A72 
 * (Set camera state Error information to A72 Camera manager)
 */
typedef struct ME_SetCameraErrorData_s
{ 
  ME_CameraErrorData_t CameraErrorData[4]; //4 SVS camera
} ME_SetCameraErrorData_t;

/* Calibration FIDs */
typedef struct CalsmFIDs_s {
  uint8_t FID_CALSM_FRONT_DISABLED;
  uint8_t FID_CALSM_LEFT_DISABLED;
  uint8_t FID_CALSM_REAR_DISABLED;
  uint8_t FID_CALSM_RIGHT_DISABLED;
} CalsmFIDs_t;

/* The below structures need not to be considered for IPC
 * The structures are intrnal to state machine
 */
typedef struct ME_Hydra3defs_S_EOLCalibDelta_s
{
  float32 X_f32;
  float32 Y_f32;
  float32 Z_f32;
  float32 Pitch_f32;
  float32 Yaw_f32;
  float32 Roll_f32;
  ME_Hydra3defs_E_CalibStatus_t CalibStatus_e;
} ME_Hydra3defs_S_EOLCalibDelta_t;

typedef struct ME_Hydra3defs_S_EOLTranslationData_s
{
  ME_Hydra3defs_S_EOLCalibDelta_t CamFrontEOL;
  ME_Hydra3defs_S_EOLCalibDelta_t CamLeftEOL;
  ME_Hydra3defs_S_EOLCalibDelta_t CamRearEOL;
  ME_Hydra3defs_S_EOLCalibDelta_t CamRightEOL;
} SVS_S_EOLTranslationData_t;

#endif //ME_CALIB_SVS_H_
