/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 * This document in its entirety is CONFIDENTIAL and may not be disclosed,
 * disseminated or distributed to parties outside MAGNA Electronics
 * without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:       SVS calibration Manager Module
 * DESIGN:      2022
 * DESCRIPTION: Handles SVS calibration state machine
 * ======================================================================== */

/**
 * \file     SVSCamCalibSM.c
 * \brief    SVS calibration Manager
 * \author   Prasad Pachpande
 * \version  $Revision: 1.0.0.0 $
 * \details  c file private description of module
 */
/* --- Defines, Includes ----------------------------------------------------------- */

#include "SVSCamCalibSM.h"
#include <string.h>       /* for using memset */ 
#include <math.h>

#if 0
#define ENABLE_CALSM_DEBUG_PRINT
#endif
 
#ifdef ENABLE_CALSM_DEBUG_PRINT
  #define CALSM_DEBUG_PRINT(x) ME_Debugger_F_Printf_v x
#else
  #define CALSM_DEBUG_PRINT(x)
#endif

/* --- Private Macros -------------------------------------------------------------- */
#define AZYNQM_D_EOL_CURRENT_CAM_TIMEOUT        1500  /* x * 10 msec */
#define AZYNQM_D_EOL_STM_TIMEOUT                1500  /* x * 10 msec */

#define ME_HYDRA3DEFS_EOLTARGETDISTANCE         2412u /* FCA in mm */
#define ME_HYDRA3DEFS_EOLTARGETID               1u    /* FCA */
#define APARAM_D_RECTIFIABLEDEVIATIONANGLE      5.0f  /* 5� */

#define AZYNQM_D_SC_CURRENT_CAM_TIMEOUT         12000 /* x * 10 msec */
#define AZYNQM_D_SC_STM_GETSTATUS_DELAY         20    /* x * 10 msec */
#define AZYNQM_D_SC_STM_TIMEOUT                 250   /* x * 10 msec */
#define AZYNQM_D_OC_STM_TIMEOUT                 250   /* x * 10 msec */

#define AZYNQM_D_ACCEPTEDVEHICLESPEEDMIN        5u   /* 5 kph */ /* Refer TSC Spec */
#define AZYNQM_D_ACCEPTEDVEHICLESPEEDMAX        25u  /* 25 kph */ /* Refer TSC Spec */

#define OCSPEEDLIMITMAX                         25u
#define OCSPEEDLIMITMIN                         4u
#define OC_PAUSE_TIMEOUT                        30u  /* 30 sec */
#define OC_LAST_CAM_BYTE                        0u

#define AZYNQM_D_ACCEPTEDSTEERINGWHEELANGLE     10.0f /* 10° */ /* Refer TSC Spec */
#define OC_WEIGHTING                            10.0

#define AZYNQM_D_ROUTINE_SC_SCREEN_RUNNING     0
#define AZYNQM_D_ROUTINE_SC_SCREEN_FINALIZING  1
#define AZYNQM_D_ROUTINE_SC_SCREEN_END         2
#define AZYNQM_D_ROUTINE_SC_SCREEN_CANCELLED   3

#define AZYNQM_D_ROUTINE_SC_SCREEN_FINALIZING_WAITTIME  250
#define AZYNQM_D_ROUTINE_SC_SCREEN_END_WAITTIME         500

#define AZYNQM_D_RC_STATE_IDLE       0
#define AZYNQM_D_RC_STATE_RUNNING    1

#define STEERING_WHEEL_ANGLE_SNA     0xFFFF
#define LAST_OC_CAM_ENABLED          1
#define LAST_OC_PAUSE_TIMER          1820u /* Maintain timeout of 1 min */

#define ENABLE_OC                    1u
#define SC_CAM_POS_ADJUSTMENT_ENABLE 1u
#define SC_CAM_ANGLE_ADJUSTMENT_ENABLE 1u
#define TUNABLE_SCALING              0.95f

/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */

static ME_Hydra3defs_E_CameraID_t aZynqM_v_EOLCamList_e[ME_HYDRA3DEFS_D_CAMERACOUNT];
static ME_Hydra3defs_E_CameraID_t aZynqM_v_SCCamList_e[ME_HYDRA3DEFS_D_CAMERACOUNT];

static ME_Hydra3defs_E_EOLErrorCode_t  aZynqM_v_EOLErrorStatus_e[ME_HYDRA3DEFS_D_CAMERACOUNT];
static ME_Hydra3defs_E_OCErrorCode_t   aZynqM_v_SCErrorStatus_e[ME_HYDRA3DEFS_D_CAMERACOUNT];
static ME_Hydra3defs_E_OCErrorCode_t   aZynqM_v_OCErrorStatus_e[ME_HYDRA3DEFS_D_CAMERACOUNT];

static ME_Hydra3defs_S_EOLTargetData_t aZynqM_v_EOLTargetData_e[ME_HYDRA3DEFS_D_CAMERACOUNT];

static uint8   aZynqM_EOL_v_CurrentCam_Index_u8;
static uint8   aZynqM_SC_v_CurrentCam_Index_u8;

static boolean aZynqM_OC_SM_Run_b;
static boolean aZynqM_SC_SM_Run_b;

static boolean aZynqM_SC_v_IsHmiEnabled_b;

static boolean aZynqM_v_EOLAlgoSelected_e;
static boolean aZynqM_v_SCAlgoSelected_e;
static boolean aZynqM_v_OCAlgoSelected_e;

static boolean aZynqM_v_EOLCompletedCurrentCycle;
static boolean aZynqM_v_SCCompletedCurrentCycle;

static boolean aZynqM_EOL_v_IsRequestedByDiag_b;
static boolean aZynqM_SC_v_IsRequestedByDiag_b;

static boolean IsSingleRearCamVariantActive_b;
static boolean v_IsOCDataIPCReady_b;

static uint32 aZynqM_EOL_v_CyclesInCurrentState_u32;
static uint16 aZynqM_SC_v_CyclesInCurrentState_u16;
static uint16 aZynqM_OC_v_CyclesInCurrentState_u16;

static uint32 aZynqM_EOL_v_CyclesInCurrentState_MAX_u32;
static uint16 aZynqM_SC_v_TimeOnCurrentCAM_u16;

static uint32 aZynqM_EOL_v_TimeOnCurrentCAM_u32;
static uint32 aZynqM_EOL_v_TimeOnCurrentCAM_MAX_u32;

static uint16 aZynqM_EOL_v_TargetDistance_u16;
static uint16 aZynqM_EOL_v_TargetID_u16;

static aZynqM_E_ModuleState_EOL_STM_t aZynqM_v_ModuleState_EOL_STM_e = aZynqM_E_EOL_STM_E_NotInit;
static aZynqM_E_ModuleState_SC_STM_t aZynqM_v_ModuleState_SC_STM_e   = aZynqM_E_SC_STM_E_NotInit;
static aZynqM_E_ModuleState_OC_STM_t aZynqM_v_ModuleState_OC_STM_e   = aZynqM_E_OC_STM_NotInit;

static uint8 aZynqM_SC_v_ScCalibrationState_u8 = AZYNQM_D_RC_STATE_IDLE;

static aZynqM_S_EOL_Conditions_t aZynqM_v_EOL_Conditions;
static aZynqM_S_SCConditions_t   aZynqM_v_SC_Conditions;
static aZynqM_S_OC_Conditions_t  aZynqM_v_OC_Conditions;
static aZynqM_S_OC_Conditions_OEM_t aZynqM_v_OC_Conditions_OEM;
#if 0
static uint32 aZynqM_SC_v_ValidFeatures_u32;
static uint32 aZynqM_SC_v_IgnoredFeatures_u32;
static uint32 aZynqM_SC_v_InvalidFeatures_u32;
#endif
static uint32 aZynqM_OC_v_ValidFeatures_u32;
static uint32 aZynqM_OC_v_IgnoredFeatures_u32;
static uint32 aZynqM_OC_v_InvalidFeatures_u32;
#if 0
static ME_Hydra3defs_E_OCAlgoState_t aZynqM_SC_v_AlgoState_e;
static ME_Hydra3defs_E_OCErrorCode_t aZynqM_SC_v_ErrorCode_e;
#endif
static ME_Hydra3defs_E_EOLAlgoState_t aZynqM_EOL_v_AlgoState_e;
static ME_Hydra3defs_E_EOLErrorCode_t aZynqM_EOL_v_ErrorCode_e;

static ME_Hydra3defs_E_OCAlgoState_t aZynqM_OC_v_AlgoState_e;
static ME_Hydra3defs_E_OCErrorCode_t aZynqM_OC_v_ErrorCode_e;

/* Statefunction Type needed for the EOL STM State Table - Typedefinition of Function Pointer for StateMachine */
typedef aZynqM_E_ModuleState_EOL_STM_t (*aZynqM_ModuleState_EOL_STM_fp_StateFunction_t)(void);

/* Statefunction Type needed for the SC STM State Table - Typedefinition of Function Pointer for StateMachine */
typedef aZynqM_E_ModuleState_SC_STM_t (*aZynqM_ModuleState_SC_STM_fp_StateFunction_t)(void);

/* Statefunction Type needed for the OC STM State Table - Typedefinition of Function Pointer for StateMachine */
typedef aZynqM_E_ModuleState_OC_STM_t (*aZynqM_ModuleState_OC_STM_fp_StateFunction_t)(void);

/* --- Private Function Declarations ----------------------------------------------- */

static void aZynqM_f_DoState_Init_e(void);

/* Run Function for the EOL STM called in 10msec Task */
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_f_EOL_STM_RunState_e(aZynqM_E_ModuleState_EOL_STM_t cur_state);

/* State Functions for the EOL STM */
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_NotInit(void);
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_Init(void);
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_Idle(void);
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_SelectCurrentCamera(void);
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_StartCameraCalibration(void);
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_CheckStatus(void);
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_Stop(void);
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_Error(void);
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_End(void);

/* State Table for the EOL State Machine */
static aZynqM_ModuleState_EOL_STM_fp_StateFunction_t const aZynqM_EOL_STM_a_StateTable[aZynqM_E_EOL_STM_NumStates] =
{
  &aZynqM_DoState_EOL_STM_E_NotInit,
  &aZynqM_DoState_EOL_STM_E_Init,
  &aZynqM_DoState_EOL_STM_E_Idle,
  &aZynqM_DoState_EOL_STM_E_SelectCurrentCamera,
  &aZynqM_DoState_EOL_STM_E_StartCameraCalibration,
  &aZynqM_DoState_EOL_STM_E_CheckStatus,
  &aZynqM_DoState_EOL_STM_E_Stop,
  &aZynqM_DoState_EOL_STM_E_Error,
  &aZynqM_DoState_EOL_STM_E_End
};

/* Run Function for the SC STM called in 10msec Task */
static aZynqM_E_ModuleState_SC_STM_t aZynqM_f_SC_STM_RunState_e(aZynqM_E_ModuleState_SC_STM_t cur_state);

/* State Functions for the SC STM */
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_NotInit(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Init(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Idle(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_WaitForEEPromRead(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_SelectCurrentCamera(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_StartCameraCalibration(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_CheckStatus(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Pause(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Paused(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Resume(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Stop(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Error(void);
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_End(void);

/* State Table for the SC State Machine */
static aZynqM_ModuleState_SC_STM_fp_StateFunction_t const aZynqM_SC_STM_a_StateTable[aZynqM_E_SC_STM_NumStates] =
{
  &aZynqM_DoState_SC_STM_E_NotInit,
  &aZynqM_DoState_SC_STM_E_Init,
  &aZynqM_DoState_SC_STM_E_Idle,
  &aZynqM_DoState_SC_STM_E_WaitForEEPromRead,
  &aZynqM_DoState_SC_STM_E_SelectCurrentCamera,
  &aZynqM_DoState_SC_STM_E_StartCameraCalibration,
  &aZynqM_DoState_SC_STM_E_CheckStatus,
  &aZynqM_DoState_SC_STM_E_Pause,
  &aZynqM_DoState_SC_STM_E_Paused,
  &aZynqM_DoState_SC_STM_E_Resume,
  &aZynqM_DoState_SC_STM_E_Stop,
  &aZynqM_DoState_SC_STM_E_Error,
  &aZynqM_DoState_SC_STM_E_End
};

/* Run Function for the OC STM called in 10msec Task */
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_OC_STM_RunState_e(aZynqM_E_ModuleState_OC_STM_t cur_state);

/* State Functions for the OC STM */
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_NotInit_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Init_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Idle_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_SelectCurrentCamera_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_StartCameraCalibration_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_CheckStatus_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Pause_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Paused_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Resume_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Stop_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Error_e(void);
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_End_e(void);

/* State Table for the OC State Machine */
static aZynqM_ModuleState_OC_STM_fp_StateFunction_t const aZynqM_OC_STM_a_StateTable[aZynqM_E_OC_STM_NumStates] =
{
  &aZynqM_f_DoState_OC_STM_NotInit_e,
  &aZynqM_f_DoState_OC_STM_Init_e,
  &aZynqM_f_DoState_OC_STM_Idle_e,
  &aZynqM_f_DoState_OC_STM_SelectCurrentCamera_e,
  &aZynqM_f_DoState_OC_STM_StartCameraCalibration_e,
  &aZynqM_f_DoState_OC_STM_CheckStatus_e,
  &aZynqM_f_DoState_OC_STM_Pause_e,
  &aZynqM_f_DoState_OC_STM_Paused_e,
  &aZynqM_f_DoState_OC_STM_Resume_e,
  &aZynqM_f_DoState_OC_STM_Stop_e,
  &aZynqM_f_DoState_OC_STM_Error_e,
  &aZynqM_f_DoState_OC_STM_End_e
};

static boolean aZynqM_CalibrationSelector_f_SelectCalibration_b(void);
static boolean aZynqM_F_IsShutdownTriggered_v(void);
static ME_Hydra3defs_S_CamCalibData_t aZynqM_CalibrationSelector_f_CalibdataWeighting_e(ME_Hydra3defs_S_CamCalibData_t v_BaseCalibData, ME_Hydra3defs_S_CamCalibData_t v_AdditionalCalibData, uint8 v_Weighting_u8);

static void aZynqM_AlgoSelector_f_SelectAlgo_v(boolean OcConditions, boolean ScConditions, boolean EOLConditions);
static void  aZynqM_f_AlgoControlHandling_v(void);

static void  aZynqM_F_EOL_ResetCalibrationData_v(void);
static void aZynqM_F_SC_ResetCalibrationData_v(void);
static void aZynqM_F_OC_ResetCalibrationData_v(void);

static void  aZynqM_EOL_f_SelectAlgo_v(boolean select);
static void aZynqM_SC_f_SelectAlgo_v(boolean select);
static void aZynqM_OC_f_SelectAlgo_v(boolean select);

static boolean aZynqM_EOL_f_GetConditions_b(void);   /* for Select and Stop Algo */
static boolean aZynqM_SC_f_GetConditions_b(void);    /* for Select and Stop Algo */
static boolean aZynqM_OC_f_GetConditions_b(void);

static boolean aZynqM_EOL_f_IsAlgoRunning_b(void);
static boolean aZynqM_SC_f_IsAlgoRunning_b(void);
static boolean aZynqM_OC_f_IsAlgoRunning_b(void);

#if 0
static void aZynqM_f_ApplyCalibrationDataForAllCameras_b(void);
#endif

static boolean aZynqM_CalibrationSelector_f_RangeCheck_e(ME_Hydra3defs_S_CamCalibData_t v_AdditionalCalibData);
Std_E_ReturnType_t aZynqM_F_SetAlgoControl_Tx_Request_v(ME_Hydra3defs_S_AlgoControlHeader_t const * AlgoControl_header, ME_Hydra3defs_S_AlgoControlData_t const * AlgoControl_data);

static void aParaM_F_Clear_EOLCalibData_s(ME_Hydra3defs_E_CameraID_t cam);
static void aParaM_F_Set_EOLCalibData_s(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_S_CamEOLCalibData_t EOLCalibData);
static ME_Hydra3defs_S_CamEOLCalibData_t aParaM_F_Get_EOLCalibData_s(ME_Hydra3defs_E_CameraID_t CamID);

static void aParaM_F_Clear_SCCalibData_s(ME_Hydra3defs_E_CameraID_t cam);
static void aParaM_F_Set_SCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_S_CamCalibData_t SCCalibData);
static ME_Hydra3defs_S_CamCalibData_t aParaM_F_Get_SCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID);

static void aParaM_F_Clear_OCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID);
static void aParaM_F_Set_OCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_S_CamCalibData_t OCCalibData);
static ME_Hydra3defs_S_CamCalibData_t aParaM_F_Get_OCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID);

static void aParaM_F_Clear_CurrentCalibData_v(ME_Hydra3defs_E_CameraID_t CamID);
static void aParaM_F_Set_CurrentCalibData_v(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_S_CamEOLCalibData_t CurrentCalibData);
static ME_Hydra3defs_S_CamEOLCalibData_t aParaM_F_Get_CurrentCalibData_s(ME_Hydra3defs_E_CameraID_t CamID);
static void aParaM_F_Set_CurrentCalibID_v(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_E_CalibrationID_t calibID);
static ME_Hydra3defs_E_CalibrationID_t aParaM_F_Get_CurrentCalibID_s(ME_Hydra3defs_E_CameraID_t CamID);

static ME_Hydra3defs_E_CameraID_t aZynqM_OC_f_GetNextCamera_e(ME_Hydra3defs_E_CameraID_t v_currentCam);

static boolean aZynqM_SC_f_GetRunConditions_b(void); /* for Pause and Resume Algo */
static boolean aZynqM_OC_f_GetRunConditions_b(void);
static boolean aZynqM_OC_F_GetRunConditions_OEM_b(void);
static boolean aZynqM_OC_f_GetRunConditionsPlatform_b(void);

static boolean aParaM_F_GetOCConfiguration_b(void);
static ME_Hydra3defs_E_CameraID_t aParaM_F_GetLastOCCurrentCam_e(void);
static void aParaM_F_SetLastOCCurrentCam_v(ME_Hydra3defs_E_CameraID_t cam);

static void aZynqM_F_SC_GetCamList_v(ME_Hydra3defs_E_CameraID_t camlist[]);

/* TSC Screen */
static void aZynqM_f_HandleRoutineRunning_v(void);
static void aZynqM_F_DoSCScreenHandling_v(uint32 SCstate);
static void aZynqM_F_GetScreen_v(aZynqM_S_ScScreenType_t *screen);
static void aZynqM_F_SetScreen_v(const aZynqM_S_ScScreenType_t *screen);
static uint8 aZynqM_f_SCScreen_GetCamOrder_uint8(uint8 camorderlist[]);
static uint8 aZynqM_f_SCScreen_GetPercentage_uint8(ME_Hydra3defs_E_CameraID_t currentCamID);
static uint8 aZynqM_f_SCScreen_GetCamPercentage_uint8(ME_Hydra3defs_E_CameraID_t currentCamID);

static boolean aZynqM_F_GetEOLStatusPrevCycle(void);
static boolean aZynqM_F_GetSCStatusPrevCycle(void);

static boolean aZynqM_F_IsSingleCamVariantRequested(void);

#if SC_CAM_POS_ADJUSTMENT_ENABLE
static void aZynqM_F_SetEolPosDeltaCopy_b(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_S_CamEOLCalibData_t EOLCalibData);
static ME_Hydra3defs_S_CamEOLCalibData_t aZynqM_F_GetEolPosDeltaCopy_b(ME_Hydra3defs_E_CameraID_t CamID);
SVS_S_EOLTranslationData_t m_SCPosAdjustment;
#endif

/* --- Public Typedefinitions, Enumerations, Defines ------------------------------ */
aSigConverterTypes_S_Rx_ZynqMRelatedData_t Rx_ZynqRelatedData;

ME_Hydra3defs_S_AlgoControlHeader_t        AlgoControl_header;
ME_Hydra3defs_S_AlgoControlData_t          algoControl_data;

ME_Hydra3defs_S_EOLStatus_t                EOLrxStatus;
ME_Hydra3defs_S_OCStatus_t                 SCrxStatus;
ME_Hydra3defs_S_OCStatus_t                 OCrxStatus;

TbSVS_S_SVSCamEOLCalibDataToNVM_t          EOLCalibDataToNVM;
TbSVS_S_SVSCamSCCalibDataToNVM_t           SCCalibDataToNVM;
TbSVS_S_SVSCamOCCalibDataToNVM_t           OCCalibDataToNVM;
TbSVS_S_SVSCamCurrentCalibDataToNVM_t      CurrentCalibDataToNVM;

ME_Hydra3defs_E_CalibStatus_t              aZynqM_v_EOLCamListStatus_e[ME_HYDRA3DEFS_D_CAMERACOUNT];
ME_Hydra3defs_E_CalibStatus_t              aZynqM_v_SCCamListStatus_e[ME_HYDRA3DEFS_D_CAMERACOUNT];
ME_Hydra3defs_E_CalibStatus_t              aZynqM_v_OCCamListStatus_e[ME_HYDRA3DEFS_D_CAMERACOUNT];

ME_Hydra3defs_E_CameraID_t                 aZynqM_v_EOLCurrentCam_e;
ME_Hydra3defs_E_CameraID_t                 aZynqM_v_SCCurrentCam_e;
ME_Hydra3defs_E_CameraID_t                 aZynqM_v_OCCurrentCam_e;

boolean                                    aZynqM_v_NVMInitDone_e;
boolean                                    aZynqM_v_ShutdownTriggered_b;
boolean                                    bIsEolSuccessPrevCycle;
boolean                                    bIsSCSuccessPrevCycle;

TbSVS_e_SVSOutputToDiagMgrCamCalib_t       v_Calib_Diag_data;
TbSVS_e_FunctionalSettingsNVMToSVSCalibSM_t functionalSettingsNVM;

aZynqM_S_ScScreenType_t aZynqM_v_TscSetScreen;
aZynqM_S_ScScreenType_t aZynqM_v_TscGetScreen;

/* Calibration FIDs */
CalsmFIDs_t m_calsmFIDs;

boolean IsEOLFsdataUpdateReq;

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_Init_e
 * Description   : SVS Camera calibration initialized.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_f_DoState_Init_e(void)
{
  /* DD-ID: {9A917699-9D5E-4a9d-9E47-627F5565E045}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_Init_e()\n"));

  aZynqM_OC_SM_Run_b = FALSE;
  aZynqM_SC_SM_Run_b = FALSE;

  IsEOLFsdataUpdateReq = FALSE;

  aZynqM_v_NVMInitDone_e = FALSE;
  aZynqM_v_ShutdownTriggered_b = FALSE;

  aZynqM_SC_v_IsHmiEnabled_b = TRUE;
  IsSingleRearCamVariantActive_b = FALSE;

  aZynqM_v_EOLAlgoSelected_e = FALSE;
  aZynqM_v_SCAlgoSelected_e  = FALSE;
  aZynqM_v_OCAlgoSelected_e  = FALSE;

  bIsEolSuccessPrevCycle = FALSE;
  bIsSCSuccessPrevCycle = FALSE;

  aZynqM_F_EOL_ResetCalibrationData_v();
  aZynqM_F_SC_ResetCalibrationData_v();
  aZynqM_F_OC_ResetCalibrationData_v();

  aZynqM_EOL_v_CurrentCam_Index_u8 = 0;
  aZynqM_SC_v_CurrentCam_Index_u8  = 0;
#if 0
  aZynqM_v_EOLCurrentCam_e = CamID_None; /* Can be removed as it is already handled in aZynqM_F_EOL_ResetCalibrationData_v() */
  aZynqM_v_SCCurrentCam_e  = CamID_None; /* Can be removed as it is already handled in aZynqM_F_SC_ResetCalibrationData_v()  */
#endif
  aZynqM_EOL_v_IsRequestedByDiag_b = FALSE;
  aZynqM_SC_v_IsRequestedByDiag_b  = FALSE;

  aZynqM_EOL_v_CyclesInCurrentState_u32 = 0;
  aZynqM_SC_v_CyclesInCurrentState_u16  = 0;
  aZynqM_OC_v_CyclesInCurrentState_u16  = 0;

  aZynqM_EOL_v_TimeOnCurrentCAM_u32 = 0;
  aZynqM_SC_v_TimeOnCurrentCAM_u16 = 0;

  aZynqM_EOL_v_CyclesInCurrentState_MAX_u32 = AZYNQM_D_EOL_STM_TIMEOUT;
  aZynqM_EOL_v_TimeOnCurrentCAM_MAX_u32 = AZYNQM_D_EOL_CURRENT_CAM_TIMEOUT;

  aZynqM_EOL_v_TargetDistance_u16 = ME_HYDRA3DEFS_EOLTARGETDISTANCE;
  aZynqM_EOL_v_TargetID_u16 = ME_HYDRA3DEFS_EOLTARGETID;

  AlgoControl_header.AlgoCommand = AlgoCommand_Unknown;
  AlgoControl_header.AlgoID = AlgoID_None;
  AlgoControl_header.CurrentCamID = CamID_None;
  (void)memset(&algoControl_data, FALSE, sizeof(algoControl_data));

  (void)memset(&aZynqM_v_EOL_Conditions, TRUE, sizeof(aZynqM_v_EOL_Conditions));
  (void)memset(&aZynqM_v_SC_Conditions, TRUE, sizeof(aZynqM_v_SC_Conditions));
  (void)memset(&aZynqM_v_OC_Conditions, TRUE, sizeof(aZynqM_v_OC_Conditions));

  (void)memset(&EOLCalibDataToNVM, 0x00, sizeof(EOLCalibDataToNVM));
  (void)memset(&SCCalibDataToNVM, 0x00, sizeof(SCCalibDataToNVM));
  (void)memset(&OCCalibDataToNVM, 0x00, sizeof(OCCalibDataToNVM));
  (void)memset(&CurrentCalibDataToNVM, 0x00, sizeof(CurrentCalibDataToNVM));

  (void)memset(&v_Calib_Diag_data, 0x00, sizeof(v_Calib_Diag_data));

  (void)memset(aZynqM_v_EOLCamListStatus_e, ME_Hydra3defs_E_CalibNotStarted, sizeof(aZynqM_v_EOLCamListStatus_e));
  (void)memset(aZynqM_v_SCCamListStatus_e, ME_Hydra3defs_E_CalibNotStarted, sizeof(aZynqM_v_SCCamListStatus_e));
  (void)memset(aZynqM_v_OCCamListStatus_e, ME_Hydra3defs_E_CalibNotStarted, sizeof(aZynqM_v_OCCamListStatus_e));

  aZynqM_v_EOLCompletedCurrentCycle = FALSE;
  aZynqM_v_SCCompletedCurrentCycle  = FALSE;

  return ; /* first working state */
}

/**************************************************************************************************
 * Function Name : aZynqM_F_IsSingleCamVariantRequested
 * Description   : Error state - lost camera
 * Input         : camID
 * Output        : TRUE if error
 **************************************************************************************************/
static boolean aZynqM_F_IsSingleCamVariantRequested(void)
{
  /* DD-ID: {00BA9C15-618B-4b96-9B58-79AE3ADD2E15}*/
  /* If true indicates the single cam (rear) variant is selected */
  CALSM_DEBUG_PRINT(("Value of IsSingleRearCamVariantActive_b = %d \n", IsSingleRearCamVariantActive_b));
  return IsSingleRearCamVariantActive_b;

}

/* --------------------------------------------------------------------------------------------------------------------------------- */

#define EOL_CONTINUEONTIMEOUT

/* EOL State Machine */
/**************************************************************************************************
 * Function Name : aZynqM_f_EOL_STM_RunState_e
 * Description   : Executing the states of the EOL calibration state machine
 * Input         : None
 * Output        : cur_state - current state of the EOL calibration state machine
 **************************************************************************************************/
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_f_EOL_STM_RunState_e(aZynqM_E_ModuleState_EOL_STM_t cur_state)
{
  /* DD-ID: {C0B6DC7F-7418-4fd0-99BB-B0822EFA85FE}*/
  aZynqM_E_ModuleState_EOL_STM_t retstate;
  if(aZynqM_EOL_v_CyclesInCurrentState_u32 > aZynqM_EOL_v_CyclesInCurrentState_MAX_u32)
  {
    aZynqM_EOL_v_CyclesInCurrentState_u32 = 0;
    aZynqM_v_EOLCamListStatus_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = ME_Hydra3defs_E_CalibAbortedFailed;
#ifdef EOL_CONTINUEONTIMEOUT
    if (TRUE == aZynqM_EOL_F_IsAlgoSelected_b())
    {
      aZynqM_EOL_v_CurrentCam_Index_u8++; /* go to next cam */
      retstate = aZynqM_E_EOL_STM_E_SelectCurrentCamera; /* start over and handle next cam */
    }
    else
    {
      retstate = aZynqM_E_EOL_STM_E_Error;
    }
#else
    retstate = aZynqM_E_EOL_STM_E_Error;
#endif
  }
  else
  {
    aZynqM_EOL_v_CyclesInCurrentState_u32++;
    CALSM_DEBUG_PRINT(("CALSM aZynqM_f_EOL_STM_RunState_e() for [%d]\n", cur_state));
    retstate = aZynqM_EOL_STM_a_StateTable[cur_state](); /* call of State Function */
  }
  return retstate;
}

/* State Functions for the EOL STM */

/**************************************************************************************************
 * Function Name : aZynqM_DoState_EOL_STM_E_NotInit
 * Description   : SVS Camera calibration state machine is not initialize
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_NotInit(void)
{
  /* DD-ID: {8FDF5077-180B-4128-BA88-A48F55BC833C}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_EOL_STM_E_NotInit()\n"));
  return aZynqM_E_EOL_STM_E_NotInit; /* stay in this state */
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_EOL_STM_E_Init
 * Description   : SVS Camera calibration state machine is initialized.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_Init(void)
{
  /* DD-ID: {DC0C9AF2-F45E-4f95-B7E6-283A39800D18}*/
  aZynqM_E_ModuleState_EOL_STM_t retstate;
  aZynqM_EOL_v_CurrentCam_Index_u8 = 0;
  aZynqM_v_EOLCurrentCam_e = CamID_None;
  
  aZynqM_EOL_v_AlgoState_e = e_EOLNotInit;
  aZynqM_EOL_v_ErrorCode_e = e_EOL_NOT_CALIBRATED;

  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_EOL_STM_E_Init()\n"));
  
  if(aZynqM_v_NVMInitDone_e)
  {
    retstate = aZynqM_E_EOL_STM_E_Idle; /* switch to idle */
  }
  else
  {
    retstate = aZynqM_E_EOL_STM_E_Init; /* stay in init */
  }

  aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* do not handle timeout in init state */

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_EOL_STM_E_Idle
 * Description   : SVS Camera calibration state machine is in idel state.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_Idle(void)
{
  /* DD-ID: {A26ACD15-4E42-44e3-9454-8CA67D30A309}*/
  aZynqM_E_ModuleState_EOL_STM_t retstate;
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_EOL_STM_E_Idle()\n"));
  if(TRUE == aZynqM_EOL_F_IsAlgoSelected_b())
  {
    retstate = aZynqM_E_EOL_STM_E_SelectCurrentCamera; /* switch to next state */
  }
  else
  {
    retstate = aZynqM_E_EOL_STM_E_Idle; /* stay here until the Algo gets selected */
  }

  aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* do not handle timeout in idle state */
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_EOL_STM_E_SelectCurrentCamera
 * Description   : Camera will be selected for performing calibration.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_SelectCurrentCamera(void)
{
  /* DD-ID: {8BF23660-EE86-480b-919A-A70654714648}*/
  aZynqM_E_ModuleState_EOL_STM_t retstate;
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_EOL_STM_E_SelectCurrentCamera()\n"));
  aZynqM_EOL_v_TimeOnCurrentCAM_u32 = 0;  /* reset the time on the current CAM to Zero if we are here */
  if(TRUE == aZynqM_EOL_F_IsAlgoSelected_b())
  {
    /* triggers start of calibration according to aZynqM_v_EOLCamList_e[] */
    if(aZynqM_EOL_v_CurrentCam_Index_u8 < ME_HYDRA3DEFS_D_CAMERACOUNT ) /* check if index is valid */
    {
      aZynqM_v_EOLCurrentCam_e = aZynqM_v_EOLCamList_e[aZynqM_EOL_v_CurrentCam_Index_u8];
      if((aZynqM_v_EOLCurrentCam_e > CamID_None) && (aZynqM_v_EOLCurrentCam_e <= ME_HYDRA3DEFS_D_CAMERACOUNT)) /* check if cam is valid */
      {
        /* start calibration of currentCam */
        retstate = aZynqM_E_EOL_STM_E_StartCameraCalibration; /* go to next state */
      }
      else
      {
        /* cam is not a valid cam index */
        aZynqM_EOL_v_CurrentCam_Index_u8++; /* go to next cam */
        retstate = aZynqM_E_EOL_STM_E_SelectCurrentCamera; /* stay in this state */
      }
    }
    else
    {
      /* all items of aZynqM_v_EOLCamList_e[] handled */
      aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* reset cycle counter */
      retstate = aZynqM_E_EOL_STM_E_End;
    }
  }
  else
  {
    aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* reset cycle counter */
    retstate = aZynqM_E_EOL_STM_E_End;
  }
  
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_EOL_STM_E_StartCameraCalibration
 * Description   : Calibration will be executed for selected camera.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_StartCameraCalibration(void)
{
  /* DD-ID: {7EA20131-D093-4f21-909A-AB6AD1259DCF}*/
  aZynqM_E_ModuleState_EOL_STM_t retstate;
  Std_E_ReturnType_t ret;
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_EOL_STM_E_StartCameraCalibration()\n"));
  
  if(TRUE == aZynqM_EOL_F_IsAlgoSelected_b())
  {
    /* start calibration of currentCam */
    AlgoControl_header.AlgoID       = AlgoID_EOL;
    AlgoControl_header.AlgoCommand  = AlgoCommand_Start;
    AlgoControl_header.CurrentCamID = aZynqM_v_EOLCurrentCam_e;
    (void)memset(&algoControl_data, 0x00, sizeof(algoControl_data));

    (void)memcpy(&algoControl_data.data[0], &aZynqM_EOL_v_TargetDistance_u16, sizeof(aZynqM_EOL_v_TargetDistance_u16));
    (void)memcpy(&algoControl_data.data[2], &aZynqM_EOL_v_TargetID_u16, sizeof(aZynqM_EOL_v_TargetID_u16));
    algoControl_data.length = (sizeof(aZynqM_EOL_v_TargetDistance_u16) + sizeof(aZynqM_EOL_v_TargetID_u16));

    ret = aZynqM_F_SetAlgoControl_Tx_Request_v(&AlgoControl_header, &algoControl_data);
    if(Std_E_RetType_Successful == ret)
    {
      //aZynqM_EOLSCOC_v_TxHeader_s = AlgoControl_header; /* save Tx Header */
      aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* reset cycle counter */
      retstate = aZynqM_E_EOL_STM_E_CheckStatus; /* switch to next state */
    }
    else
    {
      retstate = aZynqM_E_EOL_STM_E_StartCameraCalibration; /* stay in this state */
    }
  }
  else
  {
    aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* reset cycle counter */
    retstate = aZynqM_E_EOL_STM_E_End;
  }
  
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_EOL_STM_E_CheckStatus
 * Description   : Checking the status of the calibration algorithm whether the execution is
 *                 successfully completed or not with no error.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_CheckStatus(void)
{
  /* DD-ID: {5B4024F2-C39C-4a7d-BDB8-B865E5555A5D}*/
  aZynqM_E_ModuleState_EOL_STM_t retstate;
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_EOL_STM_E_CheckStatus()\n"));

  aZynqM_EOL_v_AlgoState_e = EOLrxStatus.algoState_e;
  aZynqM_EOL_v_ErrorCode_e = EOLrxStatus.errorCode_e;

  switch(EOLrxStatus.algoState_e)
  {
    case e_EOLNotInit:
     aZynqM_v_EOLCamListStatus_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = ME_Hydra3defs_E_CalibPending; /* set to pending, cause this is a workaround */ /* TODO */
     aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* reset cycle counter */
     retstate = aZynqM_E_EOL_STM_E_CheckStatus; /* go back to get status state */ /* polling loop */
     break;
    case e_EOLRunning:
      aZynqM_v_EOLCamListStatus_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = ME_Hydra3defs_E_CalibRunning;
      aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* reset cycle counter */
      retstate = aZynqM_E_EOL_STM_E_CheckStatus; /* go back to get status state */ /* polling loop */
      break;
    case e_EOLFinished:
      switch(EOLrxStatus.errorCode_e)
      {
        case e_EOL_CALIBRATION_SUCCESS:
        {
          ME_Hydra3defs_S_CamEOLCalibData_t EOLCalibData;
          ME_Hydra3defs_E_CalibStatus_t calibStatus;
          boolean EOLRangeValid_b;
          (void)memset(&EOLCalibData, 0x00, sizeof(EOLCalibData));

          EOLCalibData.calibdata.CalibStatus_e = ME_Hydra3defs_E_CalibCompletedSuccessful;
          EOLCalibData.calibdata.Pitch_f32 = EOLrxStatus.deltaPitch_f32;
          EOLCalibData.calibdata.Yaw_f32   = EOLrxStatus.deltaYaw_f32;
          EOLCalibData.calibdata.Roll_f32  = EOLrxStatus.deltaRoll_f32;

          EOLCalibData.X_f32 = EOLrxStatus.deltaX_f32;
          EOLCalibData.Y_f32 = EOLrxStatus.deltaY_f32;
          EOLCalibData.Z_f32 = EOLrxStatus.deltaZ_f32;

          EOLRangeValid_b = aZynqM_CalibrationSelector_f_RangeCheck_e(EOLCalibData.calibdata);
          if(TRUE == EOLRangeValid_b)
          {
            calibStatus = ME_Hydra3defs_E_CalibCompletedSuccessful;
            aZynqM_v_EOLCompletedCurrentCycle = TRUE;
          }
          else
          {
        	EOLrxStatus.errorCode_e = e_EOL_RESULT_EXCEED_QUALITY_LIMIT;
            calibStatus = ME_Hydra3defs_E_CalibAbortedFailed;
          }

          EOLCalibData.calibdata.CalibStatus_e = calibStatus;

          aParaM_F_Set_EOLCalibData_s(aZynqM_v_EOLCurrentCam_e, EOLCalibData);

          aZynqM_v_EOLCamListStatus_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = calibStatus;
          aZynqM_v_EOLErrorStatus_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = EOLrxStatus.errorCode_e;
          aZynqM_v_EOLTargetData_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = EOLrxStatus.targetData_s;

          break;
        }
        default:
        {
          /* data is not valid */
          ME_Hydra3defs_S_CamEOLCalibData_t EOLCalibData;
          (void)memset(&EOLCalibData, 0x00, sizeof(EOLCalibData));

          EOLCalibData.calibdata.CalibStatus_e = ME_Hydra3defs_E_CalibAbortedFailed;

          aParaM_F_Set_EOLCalibData_s(aZynqM_v_EOLCurrentCam_e, EOLCalibData);

          aZynqM_v_EOLCamListStatus_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = ME_Hydra3defs_E_CalibAbortedFailed;
          aZynqM_v_EOLErrorStatus_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = EOLrxStatus.errorCode_e;
          aZynqM_v_EOLTargetData_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = EOLrxStatus.targetData_s;
          break;
        }
      }
      aZynqM_EOL_v_CurrentCam_Index_u8++; /* go to next cam */
      aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* reset cycle counter */
      retstate = aZynqM_E_EOL_STM_E_SelectCurrentCamera;
      break;
    default:
      aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* reset cycle counter */
      retstate = aZynqM_E_EOL_STM_E_Error; /* error state */
      break;
  }

  /* TIMEOUT HANDLING IF WE STAY TOO LONG ON ONE CAMERA */
  aZynqM_EOL_v_TimeOnCurrentCAM_u32++;
  if(aZynqM_EOL_v_TimeOnCurrentCAM_MAX_u32 < aZynqM_EOL_v_TimeOnCurrentCAM_u32)
  {
    aZynqM_EOL_v_CyclesInCurrentState_u32 = 0;
    aZynqM_v_EOLCamListStatus_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = ME_Hydra3defs_E_CalibAbortedFailed;
    aZynqM_EOL_v_CurrentCam_Index_u8++; /* go to next cam */
    retstate = aZynqM_E_EOL_STM_E_SelectCurrentCamera; /* start over and handle next cam */
  }
  else{/*continue calibration*/}

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_EOL_STM_E_Stop
 * Description   : Stop the calibration.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_Stop(void)
{
  /* DD-ID: {03305BEA-F28C-4970-9DA0-C46F9AA7197E}*/
  aZynqM_E_ModuleState_EOL_STM_t retstate;
  Std_E_ReturnType_t ret;
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_EOL_STM_E_Stop()\n"));
  
  AlgoControl_header.AlgoID = AlgoID_EOL;
  AlgoControl_header.AlgoCommand = AlgoCommand_Stop;
  AlgoControl_header.CurrentCamID = aZynqM_v_EOLCurrentCam_e;
  (void)memset(&algoControl_data, 0x00, sizeof(algoControl_data));

  ret = aZynqM_F_SetAlgoControl_Tx_Request_v(&AlgoControl_header, &algoControl_data);
  if(Std_E_RetType_Successful == ret)
  {
    aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* reset cycle counter */
    retstate = aZynqM_E_EOL_STM_E_End; /* switch to next state */
  }
  else
  {
    retstate = aZynqM_E_EOL_STM_E_Stop; /* stay in this state */
  }
  
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_EOL_STM_E_Error
 * Description   : Calibration state machine will stay in error state if the error occured during
 *                 calibration algorithm is running.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_Error(void)
{
  /* DD-ID: {900B30FA-D17A-4ac7-8C01-6CE5BAEC508E}*/
  aZynqM_E_ModuleState_EOL_STM_t retstate;
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_EOL_STM_E_Error()\n"));

  if(TRUE == aZynqM_EOL_F_IsAlgoSelected_b())
  {
    aZynqM_v_EOLCamListStatus_e[aZynqM_v_EOLCurrentCam_e - CamID_Front] = ME_Hydra3defs_E_CalibAbortedFailed;
    retstate = aZynqM_E_EOL_STM_E_Error; /* stay here until the Algo gets UN selected */
  }
  else
  {
    aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* do not handle timeout in idle state */
    retstate = aZynqM_E_EOL_STM_E_Init; /* go back to init */
  }
  
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_EOL_STM_E_End
 * Description   : Calibration state machine will end the EOL calibration state machine execution
 *                 and write the camera part number to NVM.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_EOL_STM_t aZynqM_DoState_EOL_STM_E_End(void)
{
  /* DD-ID: {5C3AEA16-8891-40c7-882A-C72B2F90236F}*/
  aZynqM_E_ModuleState_EOL_STM_t retstate;
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_EOL_STM_E_End()\n"));

#ifdef EOL_STAYINEND
  if(TRUE == aZynqM_EOL_F_IsAlgoSelected_b())
  {
    aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* do not handle timeout in end state */
    retstate = aZynqM_E_EOL_STM_E_End; /* stay here until the Algo gets UN selected */
  }
  else
  {
    aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* do not handle timeout in init state */
    retstate = aZynqM_E_EOL_STM_E_Init; /* go back to init */
  }
#else
  aZynqM_EOL_f_SelectAlgo_v(FALSE);
  aZynqM_EOL_v_IsRequestedByDiag_b = FALSE;

  aZynqM_EOL_v_CyclesInCurrentState_u32 = 0; /* do not handle timeout in init state */
  retstate = aZynqM_E_EOL_STM_E_Init; /* go back to init */
#if 0 /* TODO - ( Check if these are required? ) */
  aParaM_F_SetFrontCamPartNr_v(aZynqM_F_GetCamPartNumbers(CamID_Front));
  aParaM_F_SetLeftCamPartNr_v(aZynqM_F_GetCamPartNumbers(CamID_Left));
  aParaM_F_SetRearCamPartNr_v(aZynqM_F_GetCamPartNumbers(CamID_Rear));
  aParaM_F_SetRightCamPartNr_v(aZynqM_F_GetCamPartNumbers(CamID_Right));
#endif
#endif

  return retstate;
}

/*===========================================================================================*/

#define SC_CONTINUEONTIMEOUT
/* SC State Machine */
static aZynqM_E_ModuleState_SC_STM_t aZynqM_f_SC_STM_RunState_e(aZynqM_E_ModuleState_SC_STM_t cur_state)
{
  /* DD-ID: {F723348F-FB7E-4169-861A-C979477331EE}*/
  aZynqM_E_ModuleState_SC_STM_t retstate;
  if(aZynqM_SC_v_CyclesInCurrentState_u16 > AZYNQM_D_SC_STM_TIMEOUT)
  {
    aZynqM_SC_v_CyclesInCurrentState_u16 = 0;
    aZynqM_v_SCCamListStatus_e[aZynqM_v_SCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;
#ifdef SC_CONTINUEONTIMEOUT
    if (TRUE == aZynqM_SC_F_IsAlgoSelected_b())
    {
      aZynqM_SC_v_CurrentCam_Index_u8++; /* go to next cam */
      retstate = aZynqM_E_SC_STM_E_SelectCurrentCamera; /* start over and handle next cam */
    }
    else
    {
      retstate = aZynqM_E_SC_STM_E_Error;
    }

#else
    retstate = aZynqM_E_SC_STM_E_Error;
#endif
  }
  else
  {
    aZynqM_SC_v_CyclesInCurrentState_u16++;
    CALSM_DEBUG_PRINT(("CALSM aZynqM_f_SC_STM_RunState_e() for [%d]\n", cur_state));
    retstate = aZynqM_SC_STM_a_StateTable[cur_state](); /* call of State Function */
  }
  return retstate;
}

/* State Functions for the SC STM */
/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_NotInit
 * Description   :
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_NotInit(void)
{
  /* DD-ID: {74500C22-F786-4ba1-8A0A-F5C828C87D10}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_NotInit()\n"));
  return aZynqM_E_SC_STM_E_NotInit; /* stay in this state */
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_Init
 * Description   : SC state - aZynqM_E_SC_STM_E_Init
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Init(void)
{
  /* DD-ID: {60D3D2DF-82CA-4b1f-BE47-D794DE0A37E5}*/
  aZynqM_E_ModuleState_SC_STM_t retstate;

  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_Init()\n"));

  aZynqM_SC_v_CurrentCam_Index_u8 = 0;
  aZynqM_v_SCCurrentCam_e = CamID_None;

  aZynqM_OC_v_ValidFeatures_u32 = 0;
  aZynqM_OC_v_IgnoredFeatures_u32 = 0;
  aZynqM_OC_v_InvalidFeatures_u32 = 0;

  aZynqM_OC_v_AlgoState_e = e_OC_Uninit;
  aZynqM_OC_v_ErrorCode_e = e_OC_NoError;

  if(aZynqM_v_NVMInitDone_e)
  {
    retstate = aZynqM_E_SC_STM_E_Idle; /* switch to idle */
  }
  else
  {
    retstate = aZynqM_E_SC_STM_E_Init; /* stay in init */
  }

  aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in init state */
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_Idle
 * Description   : SC state - aZynqM_E_SC_STM_E_Idle
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Idle(void)
{
  /* DD-ID: {2A468171-1084-47cc-8EB7-43D7C4A90C7B}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_Idle()\n"));

  aZynqM_E_ModuleState_SC_STM_t retstate;
  if(TRUE == aZynqM_SC_F_IsAlgoSelected_b())
  {
    if( (TRUE == aZynqM_SC_f_GetRunConditions_b()) && (FALSE == aZynqM_OC_SM_Run_b) )
    {
      /* If SC will start, reset all Data of OC */
      ME_Hydra3defs_E_CameraID_t CamID;

      for(CamID = CamID_Front; CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT; CamID++) /* PRQA S 1481 */ /* Suppress warning: "Object of enum type is being modified with an increment or decrement operator." - This is intended and range check is done */
      {
        aParaM_F_Clear_SCCalibData_s(CamID);
      }
      retstate = aZynqM_E_SC_STM_E_WaitForEEPROMRead; /* switch to next state */
    }
    else
    {
      retstate = aZynqM_E_SC_STM_E_Idle; /* stay here until the Algo gets selected */
    }
  }
  else
  {
    retstate = aZynqM_E_SC_STM_E_Idle; /* stay here until the Algo gets selected */
  }

  aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in idle state */
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_WaitForEEPromRead
 * Description   : SC state - aZynqM_E_SC_STM_E_WaitForEEPromRead
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_WaitForEEPromRead(void)
{
  /* DD-ID: {5D57BDD7-15F5-4c3a-917B-CB4D772FB495}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_WaitForEEPromRead()\n"));
    aZynqM_E_ModuleState_SC_STM_t retstate = aZynqM_E_SC_STM_E_WaitForEEPROMRead;

    if (aZynqM_v_NVMInitDone_e == TRUE)
    {
        retstate = aZynqM_E_SC_STM_E_SelectCurrentCamera;
    }
    else
    {
        /*Do Nothing*/
    }

    return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_SelectCurrentCamera
 * Description   : SC state - aZynqM_E_SC_STM_E_SelectCurrentCamera
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_SelectCurrentCamera(void)
{
  /* DD-ID: {1AF73873-82AA-40ea-BA72-FEDEA207045D}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_SelectCurrentCamera()\n"));
  aZynqM_E_ModuleState_SC_STM_t retstate;
  aZynqM_SC_v_TimeOnCurrentCAM_u16 = 0;  /* reset the time on the current CAM to Zero if we are here */
  if(TRUE == aZynqM_SC_F_IsAlgoSelected_b())
  {
    /* triggers start of calibration according to aZynqM_v_SCCamList_e[] */
    if(aZynqM_SC_v_CurrentCam_Index_u8 < ME_HYDRA3DEFS_D_CAMERACOUNT ) /* check if index is valid */
    {
      aZynqM_v_SCCurrentCam_e = aZynqM_v_SCCamList_e[aZynqM_SC_v_CurrentCam_Index_u8];

      if((aZynqM_v_SCCurrentCam_e > CamID_None) && (aZynqM_v_SCCurrentCam_e <= ME_HYDRA3DEFS_D_CAMERACOUNT)) /* check if cam is valid */
      {
        /* start calibration of currentCam */
        retstate = aZynqM_E_SC_STM_E_StartCameraCalibration; /* go to next state */
        CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_SelectCurrentCamera() : StartCameraCalibration: aZynqM_v_SCCurrentCam_e =%d\n", aZynqM_v_SCCurrentCam_e));
      }
      else
      {
        /* cam is not a valid cam index */
        aZynqM_SC_v_CurrentCam_Index_u8++; /* go to next cam */
        retstate = aZynqM_E_SC_STM_E_SelectCurrentCamera; /* stay in this state */
        CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_SelectCurrentCamera(): aZynqM_E_SC_STM_E_SelectCurrentCamera : aZynqM_SC_v_CurrentCam_Index_u8 =%d\n", aZynqM_SC_v_CurrentCam_Index_u8));
      }
    }
    else
    {
      /* all items of aZynqM_v_SCCamList_e[] handled */
      aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
      retstate = aZynqM_E_SC_STM_E_End;
      CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_SelectCurrentCamera(): aZynqM_E_SC_STM_E_End : aZynqM_SC_v_CurrentCam_Index_u8 =%d\n", aZynqM_SC_v_CurrentCam_Index_u8));
    }
  }
  else
  {
    aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
    retstate = aZynqM_E_SC_STM_E_End;
  }

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_StartCameraCalibration
 * Description   : SC state - aZynqM_E_SC_STM_E_StartCameraCalibration
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_StartCameraCalibration(void)
{
  /* DD-ID: {D6F75175-8055-4fba-AF30-999A089F9EC4}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_StartCameraCalibration()\n"));
  aZynqM_E_ModuleState_SC_STM_t retstate;
  if(TRUE == aZynqM_SC_F_IsAlgoSelected_b())
  {
    /* start calibration of currentCam */
    Std_E_ReturnType_t ret;

    AlgoControl_header.AlgoID = AlgoID_SC; /* SC uses OC as Algo on Zynq */
    AlgoControl_header.AlgoCommand = AlgoCommand_Start;
    AlgoControl_header.CurrentCamID = aZynqM_v_SCCurrentCam_e;
    (void)memset(&algoControl_data, 0x00, sizeof(algoControl_data));

    ret = aZynqM_F_SetAlgoControl_Tx_Request_v(&AlgoControl_header, &algoControl_data);
    if(Std_E_RetType_Successful == ret)
    {
      aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
      retstate = aZynqM_E_SC_STM_E_CheckStatus; /* switch to next state */
    }
    else
    {
      retstate = aZynqM_E_SC_STM_E_StartCameraCalibration; /* stay in this state */
    }
  }
  else
  {
    aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
    retstate = aZynqM_E_SC_STM_E_Stop;
  }

  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_StartCameraCalibration(): aZynqM_v_SCCurrentCam_e=%d, retstate=%d\n", aZynqM_v_SCCurrentCam_e, retstate));
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_CheckStatus
 * Description   : SC state - aZynqM_E_SC_STM_E_CheckStatus
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_CheckStatus(void)
{
  /* DD-ID: {C0CF6DD8-E324-4ff6-82A6-4493C5B09F96}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_CheckStatus()\n"));

  aZynqM_E_ModuleState_SC_STM_t retstate;
  ME_Hydra3defs_S_CamEOLCalibData_t EOLCopyCalibData;

  if(TRUE == aZynqM_SC_F_IsAlgoSelected_b())
  {
    if(TRUE == aZynqM_SC_f_GetRunConditions_b())
    {
      aZynqM_OC_v_AlgoState_e = SCrxStatus.algoState_e;
      aZynqM_OC_v_ErrorCode_e = SCrxStatus.errorCode_e;

      #if 0
      static ME_Hydra3defs_E_OCAlgoState_t v_PrevAlgoState = 0;
      static ME_Hydra3defs_E_OCErrorCode_t v_PrevErrCode = 0;

      if ((v_PrevAlgoState != SCrxStatus.algoState_e)  || (v_PrevErrCode != SCrxStatus.errorCode_e))
      {
    	CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_CheckStatus() : SCrxStatus.algoState_e =  %d, SCrxStatus.errorCode_e : %d\n", SCrxStatus.algoState_e, SCrxStatus.errorCode_e));
        v_PrevAlgoState = SCrxStatus.algoState_e;
        v_PrevErrCode = SCrxStatus.errorCode_e;
      }
      #endif

      aZynqM_v_SCErrorStatus_e[aZynqM_v_SCCurrentCam_e-1] = SCrxStatus.errorCode_e;

      switch(SCrxStatus.algoState_e)
      {
        case e_OC_Uninit:
        case e_OC_InitOk:
          aZynqM_v_SCCamListStatus_e[aZynqM_v_SCCurrentCam_e-1] = ME_Hydra3defs_E_CalibPending;
          aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
          retstate = aZynqM_E_SC_STM_E_CheckStatus; /* go back to get status state */ /* polling loop */
          break;
        case e_OC_FeatureCollection:
        case e_OC_FeatureCollectionCompleted:
        case e_OC_Calibration:
          aZynqM_v_SCCamListStatus_e[aZynqM_v_SCCurrentCam_e-1] = ME_Hydra3defs_E_CalibRunning;
          aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
          retstate = aZynqM_E_SC_STM_E_CheckStatus; /* go back to get status state */ /* polling loop */

          AlgoControl_header.AlgoID = AlgoID_SC;
          AlgoControl_header.AlgoCommand = AlgoCommand_Status;
          AlgoControl_header.CurrentCamID = aZynqM_v_SCCurrentCam_e;

          aZynqM_OC_v_ValidFeatures_u32 = SCrxStatus.ValidFeatures_u32;
          aZynqM_OC_v_IgnoredFeatures_u32 = SCrxStatus.IgnoredFeatures_u32;
          aZynqM_OC_v_InvalidFeatures_u32 = SCrxStatus.InvalidFeatures_u32;
          break;
        case e_OC_CalibrationCompleted:
          switch(SCrxStatus.errorCode_e)
          {
            case e_OC_NoError:
            {
              ME_Hydra3defs_S_CamCalibData_t OCCalibData;
              ME_Hydra3defs_E_CalibStatus_t calibStatus;
              boolean SCRangeValid_b;
              (void)memset(&OCCalibData, 0x00, sizeof(OCCalibData));

              OCCalibData.NewValueAvailable_b = TRUE;
              OCCalibData.Pitch_f32 = SCrxStatus.deltaPitch_f32;
              OCCalibData.Yaw_f32   = SCrxStatus.deltaYaw_f32;
              OCCalibData.Roll_f32  = SCrxStatus.deltaRoll_f32;

              SCRangeValid_b = aZynqM_CalibrationSelector_f_RangeCheck_e(OCCalibData);
              if(TRUE == SCRangeValid_b)
              {
                calibStatus = ME_Hydra3defs_E_CalibCompletedSuccessful;
                aZynqM_v_SCCompletedCurrentCycle = TRUE;
              }
              else
              {
                calibStatus = ME_Hydra3defs_E_CalibAbortedFailed;
              }

              OCCalibData.CalibStatus_e = calibStatus;
            #if SC_CAM_ANGLE_ADJUSTMENT_ENABLE
              EOLCopyCalibData = aZynqM_F_GetEolPosDeltaCopy_b(aZynqM_v_SCCurrentCam_e);

              if (ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCopyCalibData.calibdata.CalibStatus_e)
              {
            	if ( (fabs(OCCalibData.Pitch_f32 - EOLCopyCalibData.calibdata.Pitch_f32) > 0.75f)&&
            		(fabs(OCCalibData.Yaw_f32 - EOLCopyCalibData.calibdata.Yaw_f32) > 0.75f)&&
					(fabs(OCCalibData.Roll_f32 - EOLCopyCalibData.calibdata.Roll_f32) > 0.75f) )
            	{
                  /* Do Nothing */
            	}
            	else
            	{
              	  if (fabs(OCCalibData.Pitch_f32 - EOLCopyCalibData.calibdata.Pitch_f32) > 0.2f)
              	  {
              	    OCCalibData.Pitch_f32 += (EOLCopyCalibData.calibdata.Pitch_f32 - OCCalibData.Pitch_f32) * TUNABLE_SCALING;
              	  }
              	  if (fabs(OCCalibData.Yaw_f32 - EOLCopyCalibData.calibdata.Yaw_f32) > 0.2f)
              	  {
              	    OCCalibData.Yaw_f32 += (EOLCopyCalibData.calibdata.Yaw_f32 - OCCalibData.Yaw_f32) * TUNABLE_SCALING;
              	  }
              	  if (fabs(OCCalibData.Roll_f32 - EOLCopyCalibData.calibdata.Roll_f32) > 0.2f)
              	  {
              	    OCCalibData.Roll_f32 += (EOLCopyCalibData.calibdata.Roll_f32 - OCCalibData.Roll_f32) * TUNABLE_SCALING;
              	  }
            	}
              }
              else
              {
                /* Do Nothing */
              }
              #endif

              aParaM_F_Set_SCCalibData_s(aZynqM_v_SCCurrentCam_e, OCCalibData); /* set OC result as SC result */

              aZynqM_v_SCCamListStatus_e[aZynqM_v_SCCurrentCam_e-1] = calibStatus;

              aZynqM_OC_v_ValidFeatures_u32 = SCrxStatus.ValidFeatures_u32;
              aZynqM_OC_v_IgnoredFeatures_u32 = SCrxStatus.IgnoredFeatures_u32;
              aZynqM_OC_v_InvalidFeatures_u32 = SCrxStatus.InvalidFeatures_u32;

              CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_CheckStatus() : e_OC_NoError : aZynqM_v_SCCurrentCam_e: %d\n",aZynqM_v_SCCurrentCam_e));
              break;
           }
           default:
           {
             /* data is not valid */
             ME_Hydra3defs_S_CamCalibData_t OCCalibData;
             (void)memset(&OCCalibData, 0x00, sizeof(OCCalibData));

             OCCalibData.CalibStatus_e = ME_Hydra3defs_E_CalibAbortedFailed;

             aParaM_F_Set_SCCalibData_s(aZynqM_v_SCCurrentCam_e, OCCalibData);

             aZynqM_v_SCCamListStatus_e[aZynqM_v_SCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;
             CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_CheckStatus() : default : aZynqM_v_SCCurrentCam_e: %d\n", aZynqM_v_SCCurrentCam_e));
             break;
           }
         }

         aZynqM_SC_v_CurrentCam_Index_u8++; /* go to next cam */
         aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
         retstate = aZynqM_E_SC_STM_E_SelectCurrentCamera;

         CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_CheckStatus() : completed aZynqM_v_SCCurrentCam_e = %d\n", aZynqM_v_SCCurrentCam_e));
         break;

        case e_OC_Error:
        case e_OC_Terminated:
          {
            /* data is not valid */
            ME_Hydra3defs_S_CamCalibData_t OCCalibData;
            (void)memset(&OCCalibData, 0x00, sizeof(OCCalibData));

            OCCalibData.CalibStatus_e = ME_Hydra3defs_E_CalibAbortedFailed;

            aParaM_F_Set_SCCalibData_s(aZynqM_v_SCCurrentCam_e, OCCalibData);

            aZynqM_v_SCCamListStatus_e[aZynqM_v_SCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;

            aZynqM_SC_v_CurrentCam_Index_u8++; /* go to next cam */
            aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
            retstate = aZynqM_E_SC_STM_E_SelectCurrentCamera; /* aZynqM_v_OCCurrentCam_e will be skipped on this selection */

            CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_CheckStatus() : e_OC_Terminated: aZynqM_v_SCCurrentCam_e = %d\n", aZynqM_v_SCCurrentCam_e));
            break;
          }
        case e_OC_Paused:
          retstate = aZynqM_E_SC_STM_E_Paused;
          break;
        case e_OC_Unknown:
        default:
          aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
          retstate = aZynqM_E_SC_STM_E_Error; /* error state */
          break;
      }

      /* TIMEOUT HANDLING IF WE STAY TOO LONG ON ONE CAMERA */
      aZynqM_SC_v_TimeOnCurrentCAM_u16++;

      if(AZYNQM_D_SC_CURRENT_CAM_TIMEOUT < aZynqM_SC_v_TimeOnCurrentCAM_u16)
      {
        aZynqM_SC_v_CyclesInCurrentState_u16 = 0;
        aZynqM_v_SCCamListStatus_e[aZynqM_v_SCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;
        aZynqM_SC_v_CurrentCam_Index_u8++; /* go to next cam */

        retstate = aZynqM_E_SC_STM_E_SelectCurrentCamera; /* start over and handle next cam */
      }
      else
      {
  	  /*continue calibration*/
      }
    }
    else
    {
      aZynqM_v_SCCamListStatus_e[aZynqM_v_SCCurrentCam_e-1] = ME_Hydra3defs_E_CalibPending;
      aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
      retstate = aZynqM_E_SC_STM_E_Pause; /* Ford */ /* OEM dependent */
    }
  }
  else
  {
    aZynqM_v_SCCamListStatus_e[aZynqM_v_SCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;
    aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
    retstate = aZynqM_E_SC_STM_E_Stop;
  }
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_Pause
 * Description   : SC state - aZynqM_E_SC_STM_E_Pause
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Pause(void)
{
  /* DD-ID: {58622EF9-873B-463d-962C-1FA9BD34B6F9}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_Pause()\n"));

  AlgoControl_header.AlgoID = AlgoID_SC;
  AlgoControl_header.AlgoCommand = AlgoCommand_Pause;
  AlgoControl_header.CurrentCamID = aZynqM_v_SCCurrentCam_e; /* stop must contain current cam, getstatus must have been called before */
  (void)memset(&algoControl_data, 0x00, sizeof(algoControl_data));

  aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */

  aZynqM_OC_v_AlgoState_e = SCrxStatus.algoState_e;
  aZynqM_OC_v_ErrorCode_e = SCrxStatus.errorCode_e;
  aZynqM_v_SCErrorStatus_e[aZynqM_v_SCCurrentCam_e-1] = SCrxStatus.errorCode_e;

  aZynqM_OC_v_ValidFeatures_u32   = SCrxStatus.ValidFeatures_u32;
  aZynqM_OC_v_IgnoredFeatures_u32 = SCrxStatus.IgnoredFeatures_u32;
  aZynqM_OC_v_InvalidFeatures_u32 = SCrxStatus.InvalidFeatures_u32;

  return aZynqM_E_SC_STM_E_Paused;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_Paused
 * Description   : SC state - aZynqM_E_SC_STM_E_Paused
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Paused(void)
{
  /* DD-ID: {0792955D-1708-4df3-B4B7-90A2940A85FD}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_Paused()\n"));
  aZynqM_E_ModuleState_SC_STM_t retstate;
  static aZynqM_E_ModuleState_SC_STM_t PrevretVal;

  if(TRUE == aZynqM_SC_F_IsAlgoSelected_b())
  {
    if(TRUE == aZynqM_SC_f_GetRunConditions_b())
    {
      aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
      retstate = aZynqM_E_SC_STM_E_Resume;
    }
    else
    {
      aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in paused state */
      retstate = aZynqM_E_SC_STM_E_Paused; /* stay here until the running conditions are up again, or the Algo gets UN selected */

      if (PrevretVal != retstate)
      {
    	CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_Paused() : retstate = %d\n", retstate));
        PrevretVal = retstate;
      }
    }
  }
  else
  {
    aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
    retstate = aZynqM_E_SC_STM_E_Stop;
  }

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_Resume
 * Description   : SC state - aZynqM_E_SC_STM_E_Resume
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Resume(void)
{
  /* DD-ID: {0998B0ED-6A35-4002-AAE5-F1F6DCCE9094}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_Resume()\n"));

  AlgoControl_header.AlgoID = AlgoID_SC;
  AlgoControl_header.AlgoCommand = AlgoCommand_Resume;
  AlgoControl_header.CurrentCamID = aZynqM_v_SCCurrentCam_e; /* stop must contain current cam, getstatus must have been called before */
  (void)memset(&algoControl_data, 0x00, sizeof(algoControl_data));

  aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */

  return aZynqM_E_SC_STM_E_CheckStatus;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_Stop
 * Description   : SC state - aZynqM_E_SC_STM_E_Stop
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Stop(void)
{
  /* DD-ID: {B07E5772-4A7D-4b86-B300-E30F9BF5E405}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_Stop() : aZynqM_v_SCCurrentCam_e =%d\n", aZynqM_v_SCCurrentCam_e));
  aZynqM_E_ModuleState_SC_STM_t retstate;

  Std_E_ReturnType_t ret;

  AlgoControl_header.AlgoID = AlgoID_SC;
  AlgoControl_header.AlgoCommand = AlgoCommand_Stop;
  AlgoControl_header.CurrentCamID = aZynqM_v_SCCurrentCam_e; /* stop must contain current cam, getstatus must have been called before */
  (void)memset(&algoControl_data, 0x00, sizeof(algoControl_data));

  aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */

  return aZynqM_E_SC_STM_E_End;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_Error
 * Description   : SC state - aZynqM_E_SC_STM_E_Error
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_Error(void)
{
  /* DD-ID: {615A3CB7-50C4-4830-B350-14B36E82839B}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_Error() : aZynqM_v_SCCurrentCam_e =%d\n", aZynqM_v_SCCurrentCam_e));

  aZynqM_E_ModuleState_SC_STM_t retstate;
  if(TRUE == aZynqM_SC_F_IsAlgoSelected_b())
  {
    aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
    aZynqM_v_SCCamListStatus_e[aZynqM_v_SCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;
    retstate = aZynqM_E_SC_STM_E_Error; /* stay here until the Algo gets UN selected */
  }
  else
  {
    aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in idle state */
    retstate = aZynqM_E_SC_STM_E_Init; /* go back to init */
  }

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_DoState_SC_STM_E_End
 * Description   : SC state - aZynqM_E_SC_STM_E_End
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_SC_STM_t aZynqM_DoState_SC_STM_E_End(void)
{
  /* DD-ID: {656BBA3A-EF2D-48d7-9E21-009206D04687}*/
  aZynqM_E_ModuleState_SC_STM_t retstate;

  CALSM_DEBUG_PRINT(("CALSM aZynqM_DoState_SC_STM_E_End()\n"));

#ifdef SC_STAYINEND
  if(TRUE == aZynqM_SC_F_IsAlgoSelected_b())
  {
    aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in end state */
    retstate = aZynqM_E_SC_STM_E_End; /* stay here until the Algo gets UN selected */
  }
  else
  {
    aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in init state */
    retstate = aZynqM_E_SC_STM_E_Init; /* go back to init */
  }
#else
  aZynqM_SC_f_SelectAlgo_v(FALSE);
  aZynqM_SC_v_IsRequestedByDiag_b = FALSE;

#if 0
  /* TODO write camera part numbers*/
  aParaM_F_SetFrontCamPartNr_v(aZynqM_F_GetCamPartNumbers(CamID_Front));
  aParaM_F_SetLeftCamPartNr_v(aZynqM_F_GetCamPartNumbers(CamID_Left));
  aParaM_F_SetRearCamPartNr_v(aZynqM_F_GetCamPartNumbers(CamID_Rear));
  aParaM_F_SetRightCamPartNr_v(aZynqM_F_GetCamPartNumbers(CamID_Right));
#endif
  aZynqM_SC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in init state */

  retstate = aZynqM_E_SC_STM_E_Init; /* go back to init */
#endif
  return retstate;
}

/* --------------------------------------------------------------------------------------------------------------------------------- */
#define OC_CONTINUEONTIMEOUT
/* OC State Machine */
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_OC_STM_RunState_e(aZynqM_E_ModuleState_OC_STM_t cur_state)
{
  /* DD-ID: {B5146F18-52BB-4e95-AF47-1FE149B38E7F}*/
  aZynqM_E_ModuleState_OC_STM_t retstate;
  if(aZynqM_OC_v_CyclesInCurrentState_u16 > AZYNQM_D_OC_STM_TIMEOUT)
  {
    aZynqM_OC_v_CyclesInCurrentState_u16 = 0;
    aZynqM_v_OCCamListStatus_e[aZynqM_v_OCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;

#ifdef OC_CONTINUEONTIMEOUT
    if (TRUE == aZynqM_OC_F_IsAlgoSelected_b())
    {
      retstate = aZynqM_E_OC_STM_SelectCurrentCamera; /* start over and handle next cam */
    }
    else
    {
      retstate = aZynqM_E_OC_STM_Error;
    }
#else
    retstate = aZynqM_E_OC_STM_Error;
#endif
  }
  else
  {
    aZynqM_OC_v_CyclesInCurrentState_u16++;
    retstate = aZynqM_OC_STM_a_StateTable[cur_state](); /* call of State Function */
  }
  return retstate;
}

/* State Functions for the OC STM */

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_NotInit_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_NotInit_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_NotInit_e(void)
{
  /* DD-ID: {D39BEEA3-C5D9-4706-9253-F707353C7A8D}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_NotInit_e()\n"));
  return aZynqM_E_OC_STM_NotInit; /* stay in this state */
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_Init_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_Init_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Init_e(void)
{
  /* DD-ID: {CE81AE8D-2CB6-4a27-ACF3-E673E2714D9B}*/
  aZynqM_E_ModuleState_OC_STM_t retstate;

  aZynqM_v_OCCurrentCam_e = CamID_None;

  aZynqM_OC_v_ValidFeatures_u32 = 0;
  aZynqM_OC_v_IgnoredFeatures_u32 = 0;
  aZynqM_OC_v_InvalidFeatures_u32 = 0;

  aZynqM_OC_v_AlgoState_e = e_OC_Uninit;
  aZynqM_OC_v_ErrorCode_e = e_OC_NoError;

  if(aZynqM_v_NVMInitDone_e)
  {
    retstate = aZynqM_E_OC_STM_Idle; /* switch to idle */
    aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in init state */
  }
  else
  {
    retstate = aZynqM_E_OC_STM_Init; /* stay in init */
    aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in init state */
  }

  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_Init_e()\n"));
  return retstate; /* switch to idle */
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_Idle_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_Idle_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Idle_e(void)
{
  /* DD-ID: {CF68488E-E916-49e0-8997-63AF59802671}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_Idle_e()\n"));

  aZynqM_E_ModuleState_OC_STM_t retstate;
  if(TRUE == aZynqM_OC_F_IsAlgoSelected_b())
  {
    (void)memset(&OCrxStatus, 0x00, sizeof(OCrxStatus));

    if(TRUE == aZynqM_OC_f_GetRunConditions_b())
    {
      aZynqM_OC_SM_Run_b = TRUE;
      aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
      retstate = aZynqM_E_OC_STM_SelectCurrentCamera; /* switch to next state */
    }
    else
    {
      aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in idle state */
      retstate = aZynqM_E_OC_STM_Idle; /* stay here until the Algo gets selected */
    }
  }
  else
  {
    aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in idle state */
    retstate = aZynqM_E_OC_STM_Idle; /* stay here until the Algo gets selected */
  }

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_SelectCurrentCamera_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_SelectCurrentCamera_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_SelectCurrentCamera_e(void)
{
  /* DD-ID: {ED19AAF9-D913-4ed4-8542-C3FC559057F8}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_SelectCurrentCamera_e()\n"));

  aZynqM_E_ModuleState_OC_STM_t retstate;

  if(TRUE == aZynqM_OC_F_IsAlgoSelected_b())
  {
    aZynqM_v_OCCurrentCam_e = aZynqM_OC_f_GetNextCamera_e(aZynqM_v_OCCurrentCam_e);

    aParaM_F_SetLastOCCurrentCam_v(aZynqM_v_OCCurrentCam_e);

    retstate = aZynqM_E_OC_STM_StartCameraCalibration; /* stay in this state */
  }
  else
  {
    aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
    retstate = aZynqM_E_OC_STM_Stop;
  }

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_StartCameraCalibration_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_StartCameraCalibration_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_StartCameraCalibration_e(void)
{
  /* DD-ID: {8E94503F-F276-4089-9B1F-EBC2E5E0E26A}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_StartCameraCalibration_e()\n"));

  aZynqM_E_ModuleState_OC_STM_t retstate;

  if(TRUE == aZynqM_OC_F_IsAlgoSelected_b())
  {
    /* start calibration of currentCam */
    AlgoControl_header.AlgoID = AlgoID_OC;
    AlgoControl_header.AlgoCommand = AlgoCommand_Start;
    AlgoControl_header.CurrentCamID = aZynqM_v_OCCurrentCam_e;
    (void)memset(&algoControl_data, 0x00, sizeof(algoControl_data));

    aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
    retstate = aZynqM_E_OC_STM_CheckStatus; /* switch to next state */
  }
  else
  {
    aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
    retstate = aZynqM_E_OC_STM_Stop;
  }

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_CheckStatus_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_CheckStatus_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_CheckStatus_e(void)
{
  /* DD-ID: {36238649-3FFD-433b-BB9D-A599BEAB1829}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_CheckStatus_e()\n"));

  aZynqM_E_ModuleState_OC_STM_t retstate;
  ME_Hydra3defs_S_CamEOLCalibData_t EOLCopyCalibData;

  #if 0
  static ME_Hydra3defs_E_OCAlgoState_t v_PrevAlgoState = 0;
  static ME_Hydra3defs_E_OCErrorCode_t v_PrevErrCode = 0;

  if ( (OCrxStatus.algoState_e != v_PrevAlgoState) || (OCrxStatus.errorCode_e != v_PrevErrCode) )
  {
	CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_CheckStatus_e() : OCrxStatus.algoState_e =  %d, OCrxStatus.errorCode_e : %d\n", OCrxStatus.algoState_e, OCrxStatus.errorCode_e));
    v_PrevAlgoState = OCrxStatus.algoState_e;
    v_PrevErrCode = OCrxStatus.errorCode_e;
  }
  #endif

  if(TRUE == aZynqM_OC_F_IsAlgoSelected_b())
  {
    if(TRUE == aZynqM_OC_f_GetRunConditions_b())
    {
      aZynqM_OC_v_AlgoState_e = OCrxStatus.algoState_e;
      aZynqM_OC_v_ErrorCode_e = OCrxStatus.errorCode_e;
      aZynqM_v_OCErrorStatus_e[aZynqM_v_OCCurrentCam_e-1] = OCrxStatus.errorCode_e;

      switch(OCrxStatus.algoState_e)
      {
        case e_OC_Uninit:
        case e_OC_InitOk:
          aZynqM_v_OCCamListStatus_e[aZynqM_v_OCCurrentCam_e-1] = ME_Hydra3defs_E_CalibPending;
          aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */

          retstate = aZynqM_E_OC_STM_CheckStatus; /* go back to get status state */ /* polling loop */
          break;

        case e_OC_FeatureCollection:
        case e_OC_FeatureCollectionCompleted:
        case e_OC_Calibration:
          aZynqM_v_OCCamListStatus_e[aZynqM_v_OCCurrentCam_e-1] = ME_Hydra3defs_E_CalibRunning;
          aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */

          AlgoControl_header.AlgoID = AlgoID_OC;
          AlgoControl_header.AlgoCommand = AlgoCommand_Status;
          AlgoControl_header.CurrentCamID = aZynqM_v_OCCurrentCam_e;

          aZynqM_OC_v_ValidFeatures_u32   = OCrxStatus.ValidFeatures_u32;
          aZynqM_OC_v_IgnoredFeatures_u32 = OCrxStatus.IgnoredFeatures_u32;
          aZynqM_OC_v_InvalidFeatures_u32 = OCrxStatus.InvalidFeatures_u32;

          retstate = aZynqM_E_OC_STM_CheckStatus; /* go back to get status state */ /* polling loop */
          break;

        case e_OC_CalibrationCompleted:
          switch(OCrxStatus.errorCode_e)
          {
            case e_OC_NoError:
            {
              ME_Hydra3defs_S_CamCalibData_t OCCalibData;
              (void)memset(&OCCalibData, 0x00, sizeof(OCCalibData));

              OCCalibData.CalibStatus_e = ME_Hydra3defs_E_CalibCompletedSuccessful;
              OCCalibData.NewValueAvailable_b = TRUE;
              OCCalibData.Pitch_f32 = OCrxStatus.deltaPitch_f32;
              OCCalibData.Yaw_f32   = OCrxStatus.deltaYaw_f32;
              OCCalibData.Roll_f32  = OCrxStatus.deltaRoll_f32;
              #if SC_CAM_ANGLE_ADJUSTMENT_ENABLE
              EOLCopyCalibData = aZynqM_F_GetEolPosDeltaCopy_b(aZynqM_v_OCCurrentCam_e);

              if (ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCopyCalibData.calibdata.CalibStatus_e)
              {
            	if ( (fabs(OCCalibData.Pitch_f32 - EOLCopyCalibData.calibdata.Pitch_f32) > 0.75f)&&
            		(fabs(OCCalibData.Yaw_f32 - EOLCopyCalibData.calibdata.Yaw_f32) > 0.75f)&&
					(fabs(OCCalibData.Roll_f32 - EOLCopyCalibData.calibdata.Roll_f32) > 0.75f) )
            	{
                  /* Do Nothing */
            	}
            	else
            	{
              	  if (fabs(OCCalibData.Pitch_f32 - EOLCopyCalibData.calibdata.Pitch_f32) > 0.2f)
              	  {
              	    OCCalibData.Pitch_f32 += (EOLCopyCalibData.calibdata.Pitch_f32 - OCCalibData.Pitch_f32) * TUNABLE_SCALING;
              	  }
              	  if (fabs(OCCalibData.Yaw_f32 - EOLCopyCalibData.calibdata.Yaw_f32) > 0.2f)
              	  {
              	    OCCalibData.Yaw_f32 += (EOLCopyCalibData.calibdata.Yaw_f32 - OCCalibData.Yaw_f32) * TUNABLE_SCALING;
              	  }
              	  if (fabs(OCCalibData.Roll_f32 - EOLCopyCalibData.calibdata.Roll_f32) > 0.2f)
              	  {
              	    OCCalibData.Roll_f32 += (EOLCopyCalibData.calibdata.Roll_f32 - OCCalibData.Roll_f32) * TUNABLE_SCALING;
              	  }
            	}
              }
              else
              {
                /* Do Nothing */
              }
              #endif
              aParaM_F_Set_OCCalibData_s(aZynqM_v_OCCurrentCam_e, OCCalibData);

              aZynqM_v_OCCamListStatus_e[aZynqM_v_OCCurrentCam_e-1] = ME_Hydra3defs_E_CalibCompletedSuccessful;

              aZynqM_OC_v_ValidFeatures_u32   = OCrxStatus.ValidFeatures_u32;
              aZynqM_OC_v_IgnoredFeatures_u32 = OCrxStatus.IgnoredFeatures_u32;
              aZynqM_OC_v_InvalidFeatures_u32 = OCrxStatus.InvalidFeatures_u32;
              break;
            }

            default:
              /* data is not valid */
              aZynqM_v_OCCamListStatus_e[aZynqM_v_OCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;
              break;
          }

          aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
          retstate = aZynqM_E_OC_STM_SelectCurrentCamera;
          break;

        case e_OC_Error:
        case e_OC_Terminated:
        {
          CALSM_DEBUG_PRINT(("CALSM e_OC_Terminated/e_OC_Error \n"));

          /* data is not valid */
          ME_Hydra3defs_S_CamCalibData_t OCCalibData;
          (void)memset(&OCCalibData, 0x00, sizeof(OCCalibData));

          OCCalibData.CalibStatus_e = ME_Hydra3defs_E_CalibAbortedFailed;

          aParaM_F_Set_OCCalibData_s(aZynqM_v_OCCurrentCam_e, OCCalibData);

          aZynqM_v_OCCamListStatus_e[aZynqM_v_OCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;

          aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
          retstate = aZynqM_E_OC_STM_SelectCurrentCamera; /* aZynqM_v_OCCurrentCam_e will be skipped on this selection */
          break;
        }

        case e_OC_Paused:
          retstate = aZynqM_E_OC_STM_Paused;
          break;

        default:
          aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
          retstate = aZynqM_E_OC_STM_Error; /* error state */
          break;
      }
    }
    else
    {
      aZynqM_v_OCCamListStatus_e[aZynqM_v_OCCurrentCam_e-1] = ME_Hydra3defs_E_CalibPending;
      aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
      retstate = aZynqM_E_OC_STM_Pause; /* OEM dependent */
    }
  }
  else
  {
    aZynqM_v_OCCamListStatus_e[aZynqM_v_OCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;
    aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
    retstate = aZynqM_E_OC_STM_Stop;
  }
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_Pause_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_Pause_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Pause_e(void)
{
  /* DD-ID: {BD4C5DD3-1674-4b66-B4FA-9E20656727A6}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_Pause_e()\n"));

  aZynqM_E_ModuleState_OC_STM_t retstate;

  AlgoControl_header.AlgoID = AlgoID_OC;
  AlgoControl_header.AlgoCommand = AlgoCommand_Pause;
  AlgoControl_header.CurrentCamID = aZynqM_v_OCCurrentCam_e; /* stop must contain current cam, getstatus must have been called before */
  (void)memset(&algoControl_data, 0x00, sizeof(algoControl_data));

  aZynqM_OC_v_AlgoState_e = OCrxStatus.algoState_e;
  aZynqM_OC_v_ErrorCode_e = OCrxStatus.errorCode_e;
  aZynqM_v_OCErrorStatus_e[aZynqM_v_OCCurrentCam_e-1] = OCrxStatus.errorCode_e;

  aZynqM_OC_v_ValidFeatures_u32   = OCrxStatus.ValidFeatures_u32;
  aZynqM_OC_v_IgnoredFeatures_u32 = OCrxStatus.IgnoredFeatures_u32;
  aZynqM_OC_v_InvalidFeatures_u32 = OCrxStatus.InvalidFeatures_u32;

  aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */

  retstate = aZynqM_E_OC_STM_Paused; /* switch to next state */

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_Paused_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_Paused_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Paused_e(void)
{
  /* DD-ID: {233D7EE3-D274-415e-8D8B-2EEFE9C58542}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_Paused_e()\n"));

  static uint32 v_PauseTimeoutCounter = 0;
  aZynqM_E_ModuleState_OC_STM_t retstate;
  static aZynqM_E_ModuleState_OC_STM_t Prevretstate;
  uint32 PauseTimeout;

  if(TRUE == aZynqM_OC_F_IsAlgoSelected_b())
  {
    if(TRUE == aZynqM_OC_f_GetRunConditions_b())
    {
      aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
      retstate = aZynqM_E_OC_STM_Resume;
    }
    else
    {
      aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in paused state */
      retstate = aZynqM_E_OC_STM_Paused; /* stay here until the running conditions are up again, or the Algo gets UN selected */
    }
  }
  else
  {
    aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
    retstate = aZynqM_E_OC_STM_Stop;
  }

  PauseTimeout = LAST_OC_PAUSE_TIMER * 100; /* convert to 10 msec*/

  if(PauseTimeout < v_PauseTimeoutCounter)
  {
    v_PauseTimeoutCounter = 0; /* reset counter for next entry of state */
    retstate = aZynqM_E_OC_STM_Stop;
  }
  else
  {
    v_PauseTimeoutCounter++;
  }

  if (Prevretstate != retstate)
  {
	CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_Paused_e() : retstate = %d\n", retstate));
    Prevretstate = retstate;
  }
  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_Resume_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_Resume_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Resume_e(void)
{
  /* DD-ID: {DD0FA5E4-28DC-4318-92E9-8DF1697C9F3C}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_Resume_e()\n"));

  Std_E_ReturnType_t ret;

  AlgoControl_header.AlgoID = AlgoID_OC;
  AlgoControl_header.AlgoCommand = AlgoCommand_Resume;
  AlgoControl_header.CurrentCamID = aZynqM_v_OCCurrentCam_e; /* stop must contain current cam, getstatus must have been called before */
  (void)memset(&algoControl_data, 0x00, sizeof(algoControl_data));

  aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */

  return aZynqM_E_OC_STM_CheckStatus;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_Stop_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_Stop_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Stop_e(void)
{
  /* DD-ID: {8EE675A5-F1D9-4807-B43C-8636AF0DF953}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_Stop_e() : aZynqM_v_OCCurrentCam_e=%d\n", aZynqM_v_OCCurrentCam_e));

  Std_E_ReturnType_t ret;

  AlgoControl_header.AlgoID = AlgoID_OC;
  AlgoControl_header.AlgoCommand = AlgoCommand_Stop;
  AlgoControl_header.CurrentCamID = aZynqM_v_OCCurrentCam_e; /* stop must contain current cam, getstatus must have been called before */

  (void)memset(&algoControl_data, 0x00, sizeof(algoControl_data));

  aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */

  return aZynqM_E_OC_STM_End;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_Error_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_Error_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_Error_e(void)
{
  /* DD-ID: {199C7016-F986-4c1a-8E0A-58CD55B4BE2D}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_Error_e()\n"));

  aZynqM_E_ModuleState_OC_STM_t retstate;

  aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* reset cycle counter */
  aZynqM_v_OCCamListStatus_e[aZynqM_v_OCCurrentCam_e-1] = ME_Hydra3defs_E_CalibAbortedFailed;
  retstate = aZynqM_E_OC_STM_Init; /* go back to init */

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_DoState_OC_STM_End_e
 * Description   : OC state - aZynqM_f_DoState_OC_STM_End_e
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static aZynqM_E_ModuleState_OC_STM_t aZynqM_f_DoState_OC_STM_End_e(void)
{
  /* DD-ID: {3142A591-20B6-48f7-9B97-3513B29E0B8A}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_f_DoState_OC_STM_End_e()\n"));

  aZynqM_E_ModuleState_OC_STM_t retstate;

  aZynqM_OC_SM_Run_b = FALSE;
  aZynqM_OC_v_CyclesInCurrentState_u16 = 0; /* do not handle timeout in end state */
  retstate = aZynqM_E_OC_STM_Init; /* go back to init */

  return retstate;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_AlgoControlHandling_v
 * Description   : EOL start condition will be evaluated. The EOL calibration is selected if the
 *                 start conditions are valid
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_f_AlgoControlHandling_v(void)
{
  /* DD-ID: {3C6024ED-A5CE-44ea-9551-583E60C4B27B}*/
  boolean v_OcConditions;
  boolean v_ScConditions;
  boolean v_EOLConditions;

  if(TRUE == aZynqM_F_IsShutdownTriggered_v())
  {
    /* if shutdown is triggered, no condition is met */
    v_OcConditions = FALSE;
    v_ScConditions = FALSE;
    v_EOLConditions = FALSE;
  }
  else
  {
    v_OcConditions = aZynqM_OC_f_GetConditions_b();
    v_ScConditions = aZynqM_SC_f_GetConditions_b();
    v_EOLConditions = aZynqM_EOL_f_GetConditions_b();
  }

  aZynqM_AlgoSelector_f_SelectAlgo_v(v_OcConditions, v_ScConditions, v_EOLConditions);

  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_f_InternalInit_v
 * Description   : EOL start conditions will be validated and EOL state machine will be
 *                 initialized.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void aZynqM_f_InternalInit_v(void)
{
  /* DD-ID: {34478F5D-E915-49e1-97B5-EE414E205C24}*/
  aZynqM_f_DoState_Init_e();
  aZynqM_f_AlgoControlHandling_v();

  aZynqM_v_ModuleState_EOL_STM_e = aZynqM_E_EOL_STM_E_Init;
  aZynqM_v_ModuleState_EOL_STM_e = aZynqM_f_EOL_STM_RunState_e(aZynqM_v_ModuleState_EOL_STM_e);

  aZynqM_v_ModuleState_SC_STM_e = aZynqM_E_SC_STM_E_Init;
  aZynqM_v_ModuleState_SC_STM_e = aZynqM_f_SC_STM_RunState_e(aZynqM_v_ModuleState_SC_STM_e);

  #if ENABLE_OC
  aZynqM_v_ModuleState_OC_STM_e = aZynqM_E_OC_STM_Init;
  aZynqM_v_ModuleState_OC_STM_e = aZynqM_f_OC_STM_RunState_e(aZynqM_v_ModuleState_OC_STM_e);
  #endif

  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_Task10msec_v
 * Description   : Task to validate the EOL start conditions and execute the EOL state machine.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void aZynqM_F_Task10msec_v(void)
{
  /* DD-ID: {4AECDB0F-6E10-40f6-ABAB-48D07F774099}*/
#if 0
  aZynqM_f_ApplyCalibrationDataForAllCameras_b();
  EOLCalibDataToNVM.bValid = FALSE; /* Mark this flag false at start */
#endif

#if 0
  /* This changes was not here previously for the EOL state machine, need to discuss */
  EOLCalibDataToNVM.bValid = FALSE; /* Mark this flag false at start */
  SCCalibDataToNVM.bValid  = FALSE; /* Mark this flag false at start */
  SCCalibDataToNVM.bValid  = FALSE; /* Mark this flag false at start */
  CurrentCalibDataToNVM.bValid = FALSE; /* Mark this flag false at start */
#endif

  static boolean aZynqM_v_ShutdownTriggered_PrevSts_b = FALSE;
  static boolean v_CurrentCalibDataComputeCnt_b = FALSE;
  static uint8 CurrentCalibSendRetryCnt_u8 = 0u;

  ME_Hydra3defs_E_CameraID_t CamID;
  ME_Hydra3defs_E_CalibrationID_t currentID;
  ME_Hydra3defs_S_CamEOLCalibData_t CurrentCalibData;
  ME_Hydra3defs_E_CameraID_t OcCurrentCamId;

  aZynqM_f_AlgoControlHandling_v();
  aZynqM_f_HandleRoutineRunning_v();

  aZynqM_v_ModuleState_EOL_STM_e = aZynqM_f_EOL_STM_RunState_e(aZynqM_v_ModuleState_EOL_STM_e); /* Run the State Machine */

  aZynqM_v_ModuleState_SC_STM_e  = aZynqM_f_SC_STM_RunState_e(aZynqM_v_ModuleState_SC_STM_e);   /* Run the State Machine */

  #if ENABLE_OC
  aZynqM_v_ModuleState_OC_STM_e  = aZynqM_f_OC_STM_RunState_e(aZynqM_v_ModuleState_OC_STM_e); /* Run the State Machine */
  #endif

  /* Awaiting for shutdown to trigger. The latest calibration data will be stored as a current calibration data */
  if ( (TRUE == aZynqM_F_IsShutdownTriggered_v()) && (aZynqM_v_ShutdownTriggered_PrevSts_b != aZynqM_F_IsShutdownTriggered_v()) )
  {
	  /* Compute the Current Calib Data only once */
	if (FALSE == v_CurrentCalibDataComputeCnt_b)
	{
	  /* The Current calib data will be computed only one time */
	  aZynqM_CalibrationSelector_f_SelectCalibration_b();

      /* OC Calib Data validity and acceptance should be done only once after shutdown triggered.
       * Three retry should be performed to send the data over IPC
       */
	  v_IsOCDataIPCReady_b = TRUE;

	  v_CurrentCalibDataComputeCnt_b = TRUE;
	}
	else
	{
      /* Three retry counts for Current Calib data will be made to ensure data validity over IPC */
      if(CurrentCalibSendRetryCnt_u8 > 2u)
      {
        aZynqM_v_ShutdownTriggered_PrevSts_b = aZynqM_F_IsShutdownTriggered_v();
      }
      else
      {
        for(CamID = CamID_Front; CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT; CamID++)
        {
      	  currentID = aParaM_F_Get_CurrentCalibID_s(CamID);
          aParaM_F_Set_CurrentCalibID_v(CamID, currentID);

          CurrentCalibData = aParaM_F_Get_CurrentCalibData_s(CamID);
          aParaM_F_Set_CurrentCalibData_v(CamID, CurrentCalibData);

          #if LAST_OC_CAM_ENABLED
            OcCurrentCamId = aZynqM_F_OC_GetCurrentCam_e ();
            aParaM_F_SetLastOCCurrentCam_v(OcCurrentCamId);
          #endif
        }

        CurrentCalibSendRetryCnt_u8++;
      }
    }
  }
  else
  {
    /* Do Nothing */
  }
  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_ModuleState_EOL_STM_GetModuleState_e
 * Description   : Get the EOL state machine module state.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
aZynqM_E_ModuleState_EOL_STM_t aZynqM_F_ModuleState_EOL_STM_GetModuleState_e(void)
{
  /* DD-ID: {CFB92EE1-16C3-4784-9D48-0198621E6E5A}*/
  return aZynqM_v_ModuleState_EOL_STM_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_ModuleState_SC_STM_GetModuleState_e
 * Description   : Get the SC state machine module state.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
aZynqM_E_ModuleState_SC_STM_t aZynqM_F_ModuleState_SC_STM_GetModuleState_e(void)
{
  /* DD-ID: {0E4485C2-2C34-4ca4-B23E-283674AD40A0}*/
  return aZynqM_v_ModuleState_SC_STM_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_ModuleState_OC_STM_GetModuleState_e
 * Description   : Get the OC state machine module state.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
aZynqM_E_ModuleState_OC_STM_t aZynqM_F_ModuleState_OC_STM_GetModuleState_e(void)
{
  /* DD-ID: {A5776DDB-ABE2-44df-BB45-25A376801331}*/
  return aZynqM_v_ModuleState_OC_STM_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_CalibrationSelector_f_RangeCheck_e
 * Description   : Six degree of freedom range check. It will validate the design values Vs actual
 *                 received value of six degrees of freedom.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_CalibrationSelector_f_RangeCheck_e(ME_Hydra3defs_S_CamCalibData_t v_AdditionalCalibData)
{
  /* DD-ID: {BB11D8C7-4D19-473d-8603-9146EE5354E7}*/
  boolean v_RangeValid_b;

  float32 v_deltaPitch_f32;
  float32 v_deltaYaw_f32;
  float32 v_deltaRoll_f32;

  v_deltaPitch_f32 = v_AdditionalCalibData.Pitch_f32;
  v_deltaYaw_f32   = v_AdditionalCalibData.Yaw_f32;
  v_deltaRoll_f32  = v_AdditionalCalibData.Roll_f32;

  CALSM_DEBUG_PRINT(("CALSM aZynqM_CalibrationSelector_f_RangeCheck_e()\n"));

  /* only use set of date if ALL values are within predefined area */
  if(    ((-1.0f*APARAM_D_RECTIFIABLEDEVIATIONANGLE) <= v_deltaPitch_f32) && (v_deltaPitch_f32 <= APARAM_D_RECTIFIABLEDEVIATIONANGLE)
      && ((-1.0f*APARAM_D_RECTIFIABLEDEVIATIONANGLE) <= v_deltaYaw_f32)   && (v_deltaYaw_f32   <= APARAM_D_RECTIFIABLEDEVIATIONANGLE)
      && ((-1.0f*APARAM_D_RECTIFIABLEDEVIATIONANGLE) <= v_deltaRoll_f32)  && (v_deltaRoll_f32  <= APARAM_D_RECTIFIABLEDEVIATIONANGLE)
    )
  {
    v_RangeValid_b = TRUE;
  }
  else
  {
    v_RangeValid_b = FALSE;
  }

  return v_RangeValid_b;
}


/*************************************************************************************************
 * Function Name : aZynqM_AlgoSelector_f_SelectAlgo_v
 * Description   : Select or de-select the EOL algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_AlgoSelector_f_SelectAlgo_v(boolean OcConditions, boolean ScConditions, boolean EOLConditions)
{
  /* DD-ID: {EB3564CF-3662-48ee-8EB8-827160443946}*/
	boolean v_SC_Run  = aZynqM_SC_f_IsAlgoRunning_b();
	boolean v_OC_Run  = aZynqM_OC_f_IsAlgoRunning_b();
	boolean v_EOL_Run = aZynqM_EOL_f_IsAlgoRunning_b();

	  if(TRUE == ScConditions)
	  { /*deselect all other algos*/
	    aZynqM_OC_f_SelectAlgo_v(FALSE); /* deselect OC */
	    aZynqM_EOL_f_SelectAlgo_v(FALSE); /* deselect EOL */

	    if( (FALSE == v_OC_Run) &&
	        (FALSE == v_EOL_Run))
	    {
	      if(FALSE == aZynqM_SC_F_IsAlgoSelected_b() )
	      {
	        /* select SC only if no other algo is activated or running */
	        aZynqM_SC_f_SelectAlgo_v(TRUE);  /* select SC */
	      }
	    }
	  }
	  else if(TRUE == EOLConditions)
	  { /*deselect all other algos*/
	    aZynqM_OC_f_SelectAlgo_v(FALSE); /* deselect OC */
	    aZynqM_SC_f_SelectAlgo_v(FALSE); /* deselect SC */

	    if( (FALSE == v_OC_Run) &&
	        (FALSE == v_SC_Run))
	    {
	      if(FALSE == aZynqM_EOL_F_IsAlgoSelected_b() )
	      {
	        /* select EOL only if no other algo is activated or running */
	        aZynqM_EOL_f_SelectAlgo_v(TRUE);  /* select EOL */
	      }
	    }
	  }
	  else if(TRUE == OcConditions)
	  { /*deselect all other algos*/
	    aZynqM_SC_f_SelectAlgo_v(FALSE); /* deselect SC */
	    aZynqM_EOL_f_SelectAlgo_v(FALSE); /* deselect EOL */

	    if( (FALSE == v_SC_Run) &&
	        (FALSE == v_EOL_Run))
	    {
	      if(FALSE == aZynqM_OC_F_IsAlgoSelected_b())
	      {
	        /* select OC only if no other algo is activated or running */
	        aZynqM_OC_f_SelectAlgo_v(TRUE);
	      }
	    }
	  }
	  else
	  {
	    /* deselect all algos */
	    aZynqM_SC_f_SelectAlgo_v(FALSE);
	    aZynqM_OC_f_SelectAlgo_v(FALSE);
	    aZynqM_EOL_f_SelectAlgo_v(FALSE);
	  }
	  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_EOL_f_SelectAlgo_v
 * Description   : Select the EOL algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_EOL_f_SelectAlgo_v(boolean select)
{
  /* DD-ID: {908B0CF0-518B-4a18-84E3-835B3B4150A8}*/
  aZynqM_v_EOLAlgoSelected_e = select;
  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_SC_f_SelectAlgo_v
 * Description   : Select the SC algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_SC_f_SelectAlgo_v(boolean select)
{
  /* DD-ID: {FF9F4B23-2FAD-4f81-A1B5-982C460B016F}*/
  aZynqM_v_SCAlgoSelected_e = select;
  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_OC_f_SelectAlgo_v
 * Description   : Select the OC algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_OC_f_SelectAlgo_v(boolean select)
{
  /* DD-ID: {99A88D65-F7BC-4e14-974F-642CEAAF19D6}*/
  aZynqM_v_OCAlgoSelected_e = select;
  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_EOL_f_GetConditions_b
 * Description   : Check the start conditions to execute EOL algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_EOL_f_GetConditions_b(void) /* for Select and Stop Algo */
{
  /* DD-ID: {417895A0-3F97-43bd-ACF6-A55D31AC4814}*/
  boolean retVal;
  boolean EOLStartConditions;

  EOLStartConditions = aZynqM_F_EOL_StartConditionsCorrect_b();
  /* Do evaluate ZynqM Related Data */
  if((TRUE == aZynqM_EOL_v_IsRequestedByDiag_b) && (TRUE == EOLStartConditions))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

/**************************************************************************************************
 * Function Name : aZynqM_EOL_f_GetConditions_b
 * Description   : Check the start conditions to execute EOL algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_SC_f_GetConditions_b(void) /* for Select and Stop Algo */
{
  /* DD-ID: {68FA3885-4AD9-4760-84FD-DBD9097F9517}*/
  boolean retVal;

  /* Do evaluate ZynqM Related Data */
  if(TRUE == aZynqM_SC_v_IsRequestedByDiag_b)
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }

  return retVal;
}

/**************************************************************************************************
* Function Name : aParaM_F_GetOCConfiguration_b
* Description   : Check the functional control setting for OC.
* Input         : None
* Output        : None
**************************************************************************************************/
static boolean aParaM_F_GetOCConfiguration_b(void)
{
  /* DD-ID: {DBBECAC0-E770-4f18-9B6C-B71685D28E80}*/
  boolean bRet;

  if(TRUE == functionalSettingsNVM.OC_Control_u8)
  {
    bRet = TRUE;
  }
  else
  {
    bRet= FALSE;
  }

  return bRet;
}

/**************************************************************************************************
 * Function Name : aZynqM_OC_f_GetConditions_b
 * Description   : Check the start conditions to execute OC algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_OC_f_GetConditions_b(void) /* for Select and Stop Algo */
{
  /* DD-ID: {738A8555-034E-46d7-8F1C-F9BE7B684EB6}*/
  boolean retVal = TRUE;
  ME_Hydra3defs_E_CameraID_t CamID;

  boolean OCConfiguration_b;

  OCConfiguration_b = aParaM_F_GetOCConfiguration_b();
  if(FALSE == OCConfiguration_b)
  {
    retVal = FALSE;
    aZynqM_v_OC_Conditions.Configuration_b = FALSE;
  }
  else
  {
    aZynqM_v_OC_Conditions.Configuration_b = TRUE;
  }
#ifdef to_do
  if(FALSE == aZynqM_OC_v_IsApprovedByApplication_b)
  {
    retVal = FALSE;
    aZynqM_v_OC_Conditions.ApprovedByApplication_b = FALSE;
  }
  else
  {
    aZynqM_v_OC_Conditions.ApprovedByApplication_b = TRUE;
  }
#endif
  /* condition is not met if one ore more cams are not calibrated successful with EOL*/
  for(CamID = CamID_Front; CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT; CamID++) /* PRQA S 1481 */ /* Suppress warning: "Object of enum type is being modified with an increment or decrement operator." - This is intended and range check is done */
  {
    ME_Hydra3defs_S_CamEOLCalibData_t EOLCalibData;
    ME_Hydra3defs_S_CamCalibData_t    SCCalibData;

    EOLCalibData = aParaM_F_Get_EOLCalibData_s(CamID);
    SCCalibData  = aParaM_F_Get_SCCalibData_s(CamID);

    /* OC calibration will execute in the next cycle if EOL or SC is successful */
    if( (TRUE == aZynqM_F_GetEOLStatusPrevCycle()) || (TRUE == aZynqM_F_GetSCStatusPrevCycle()) )
	{
      if( (ME_Hydra3defs_E_CalibCompletedSuccessful != EOLCalibData.calibdata.CalibStatus_e)&&
    	  (ME_Hydra3defs_E_CalibCompletedSuccessful != SCCalibData.CalibStatus_e) )
      {
        retVal = FALSE;
        aZynqM_v_OC_Conditions.EOLSCCalibration_b = FALSE;
        break;  /* reduce unnecessary runtime  - as soon as retVal will be FALSE we can leave the loop */
      }
      else
      {
        aZynqM_v_OC_Conditions.EOLSCCalibration_b = TRUE;
      }
	}
    else
    {
      retVal = FALSE;
    }
  }

  return retVal;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SC_GetRunConditions_s
 * Description   : Check the run conditions to execute SC algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
aZynqM_S_SCConditions_t aZynqM_F_SC_GetRunConditions_s(void)
{
  /* DD-ID: {358E393E-32F3-469a-A8E0-C3E152673515}*/
  Std_E_ReturnType_t eRet;
  float32 SteeringWheelAngle;
  boolean Reverse_GearActv_b;
  float32 angleHelper;

  boolean LVDS_Cam_DTC_Front;
  boolean LVDS_Cam_DTC_Left;
  boolean LVDS_Cam_DTC_Rear;
  boolean LVDS_Cam_DTC_Right;
  static boolean SC_VehicleLevelAS_b_prev;

  aZynqM_S_SCConditions_t scconditions;
  (void)memset(&scconditions, 0x00, sizeof(scconditions));

  SteeringWheelAngle = Rx_ZynqRelatedData.steeringAngle_f32;
#ifdef TEST
  /* We need to check this with system team It is oEM specifiv*/
  angleHelper = (float32)SteeringWheelAngle - 0x3E80; /* offset */
  SteeringWheelAngle = (float32)(angleHelper * 0.1); /* factor 0.1 */
  SteeringWheelAngle *= -1.0f; /* change sign */
#endif
  scconditions.LeftFrontDoor_b   = (e_DoorCLOSED == Rx_ZynqRelatedData.LeftFrontAJAR_e);
  scconditions.RightFrontDoor_b  = (e_DoorCLOSED == Rx_ZynqRelatedData.RightFrontAJAR_e);
  scconditions.LeftRearDoor_b    = (e_DoorCLOSED == Rx_ZynqRelatedData.LeftRearAJAR_e);
  scconditions.RightRearDoor_b   = (e_DoorCLOSED == Rx_ZynqRelatedData.RightRearAJAR_e);
  scconditions.Tailgate_b        = (e_DoorCLOSED == Rx_ZynqRelatedData.tlgAJAR_e);
  scconditions.Hood_b            = (e_DoorCLOSED == Rx_ZynqRelatedData.hoodAJAR_e);
  scconditions.LeftMirror_b      = (MirrorDrivingPosition == Rx_ZynqRelatedData.mirrorLefStatus_u8);
  scconditions.RightMirror_b     = (MirrorDrivingPosition == Rx_ZynqRelatedData.mirrorRigStatus_u8);

  if(e_D_GEAR == Rx_ZynqRelatedData.gearStatus_e)
  {
      scconditions.DrivingForward = TRUE;
  }
  else
  {
      scconditions.DrivingForward = FALSE;
  }

#ifdef to_do
  if(aZynqM_v_DTCSuppressionNumber_s.TransmType_Cfg_u1 == 0 )
  {
      if(e_D_GEAR == Rx_ZynqMRelatedData.gearStatus_e)
      {
          scconditions.DrivingForward = TRUE;
      }
      else
      {
          scconditions.DrivingForward = FALSE;
      }
  }
  else
  {
      if(e_R_GEAR == TRUE)
      {
          scconditions.DrivingForward = FALSE;
      }
      else
      {
          scconditions.DrivingForward = TRUE;
      }
  }
#endif

  if((AZYNQM_D_ACCEPTEDVEHICLESPEEDMIN <= Rx_ZynqRelatedData.vehSpeed_f32) && (Rx_ZynqRelatedData.vehSpeed_f32 <= AZYNQM_D_ACCEPTEDVEHICLESPEEDMAX))
  {
    scconditions.SpeedValid_b = TRUE;
  }
  else
  {
    scconditions.SpeedValid_b = FALSE;
  }

  scconditions.SteeringAngle_b = ((-AZYNQM_D_ACCEPTEDSTEERINGWHEELANGLE <= SteeringWheelAngle) && (SteeringWheelAngle <= AZYNQM_D_ACCEPTEDSTEERINGWHEELANGLE));

  /* Check for active DTCs relating Cameras */
  LVDS_Cam_DTC_Front = (FALSE != (boolean)m_calsmFIDs.FID_CALSM_FRONT_DISABLED);
  LVDS_Cam_DTC_Left =  (FALSE != (boolean)m_calsmFIDs.FID_CALSM_LEFT_DISABLED);
  LVDS_Cam_DTC_Rear =  (FALSE != (boolean)m_calsmFIDs.FID_CALSM_REAR_DISABLED);
  LVDS_Cam_DTC_Right = (FALSE != (boolean)m_calsmFIDs.FID_CALSM_RIGHT_DISABLED);

  scconditions.VoltageIPMB_b = (FALSE == LVDS_Cam_DTC_Front) &&
                               (FALSE == LVDS_Cam_DTC_Left) &&
                               (FALSE == LVDS_Cam_DTC_Rear) &&
                               (FALSE == LVDS_Cam_DTC_Right);

#if 0
  scconditions.VehicleLevel_b = (( (ME_Hydra2defs_E_VehicleLevel_NVL == currentVehLevel) || (ME_Hydra2defs_E_VehicleLevel_NVL_Zero == currentVehLevel)));
#endif

  /* Below are the dummy values set for TSC screen */
  scconditions.InnerTailgate_b = TRUE;
  scconditions.VehicleLevel_b  = TRUE;
  scconditions.ZynqModuleState_b = TRUE;


  /* Checking if the AirSuspension is Present or Absent */
  if (Rx_ZynqRelatedData.ProxiData_s.PRX_CanNod27_b == TRUE)
  {
    /* Checking if AirSuspension level is NVL */
    if (Rx_ZynqRelatedData.ASCMStatus_e == e_ASCM_Stat_NVL)
    {
      scconditions.VehicleLevel_b = TRUE;
    }
    else
    {
      scconditions.VehicleLevel_b = FALSE;
    }
  }
  else
  {
    scconditions.VehicleLevel_b = TRUE;
  }

  if (SC_VehicleLevelAS_b_prev != scconditions.VehicleLevel_b)
  {
    CALSM_DEBUG_PRINT(("SC VehicleLevel_b : %d \n ", scconditions.VehicleLevel_b));
    SC_VehicleLevelAS_b_prev = scconditions.VehicleLevel_b;
  }

  return scconditions;
}

/**************************************************************************************************
 * Function Name : aZynqM_SC_f_GetRunConditions_b
 * Description   : Check the run conditions to execute SC algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_SC_f_GetRunConditions_b(void) /* for Pause Resume Algo */
{
  /* DD-ID: {C254150F-E7EE-4f93-A195-3DC1BB0DB4F1}*/
  boolean retVal;
  aZynqM_S_SCConditions_t SCConditions;

  SCConditions = aZynqM_F_SC_GetRunConditions_s();

  if ((TRUE == SCConditions.LeftFrontDoor_b)  &&
      (TRUE == SCConditions.RightFrontDoor_b) &&
      (TRUE == SCConditions.LeftRearDoor_b)   &&
      (TRUE == SCConditions.RightRearDoor_b)  &&
      (TRUE == SCConditions.Hood_b)           &&
      (TRUE == SCConditions.Tailgate_b)       &&

      (TRUE == SCConditions.LeftMirror_b)     &&
      (TRUE == SCConditions.RightMirror_b)    &&

      (TRUE == SCConditions.DrivingForward)   &&
      (TRUE == SCConditions.SpeedValid_b)     &&
      (TRUE == SCConditions.VoltageIPMB_b)    &&
      (TRUE == SCConditions.SteeringAngle_b)  &&
      (TRUE == SCConditions.VehicleLevel_b))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

/**************************************************************************************************
 * Function Name : aZynqM_OC_f_GetRunConditions_b
 * Description   : Check the run conditions to execute OC algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_OC_f_GetRunConditions_b(void) /* for Pause Resume Algo */
{
  /* DD-ID: {36B4FA98-36B4-42aa-B443-EB36418ABBF6}*/
  boolean retVal;

  retVal = aZynqM_OC_f_GetRunConditionsPlatform_b();
  retVal &= aZynqM_OC_F_GetRunConditions_OEM_b();

  return retVal;
}

/**************************************************************************************************
 * Function Name : aZynqM_OC_f_GetRunConditionsPlatform_b
 * Description   : Check the platform specific run conditions to execute OC algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
/* Platform defined running conditions */
static boolean aZynqM_OC_f_GetRunConditionsPlatform_b(void) /* for Pause Resume Algo */
{
  /* DD-ID: {4CD0B8A3-0547-4882-B9DF-A10D5CCCE6E6}*/
  boolean retVal = TRUE;

#ifdef to_do
  Std_E_ReturnType_t ret;
  u16 OCSpeedLimitMax;
  u16 OCSpeedLimitMin;
  boolean Reverse_GearActv_b;

  OCSpeedLimitMax = aParaM_F_GetOCSpeedLimitMax_u16();
  OCSpeedLimitMin = aParaM_F_GetOCSpeedLimitMin_u16();

  aZynqM_v_DTCSuppressionNumber_s = aParaM_F_GetDTCSuppressionNumber_s(); /*get DE01*/
#endif

  if(e_D_GEAR == Rx_ZynqRelatedData.gearStatus_e)
  {
    aZynqM_v_OC_Conditions.DrivingForward = TRUE;
  }
  else
  {
    retVal = FALSE;
    aZynqM_v_OC_Conditions.DrivingForward = FALSE;
  }

#if to_do
  Reverse_GearActv_b = aSigConverter_F_IsReverseActive_b();

  ret = aSigConverter_F_GetZynqMRelatedSignals_e(&Rx_ZynqMRelatedData);
  if(Std_E_RetType_Failed == ret)
  {
    /* Function call failed */
    retVal = FALSE;
  }
  else
  {
        if(aZynqM_v_DTCSuppressionNumber_s.TransmType_Cfg_u1 == 0 )
        {

            if(Gear_STAT_D == Rx_ZynqMRelatedData.gearStatus_e)
            {
                  aZynqM_v_OC_Conditions.DrivingForward = TRUE;
            }
            else
            {
                  retVal = FALSE;
                  aZynqM_v_OC_Conditions.DrivingForward = FALSE;
            }
        }
        else
        {
            if(Reverse_GearActv_b == TRUE)
            {
                  retVal = FALSE;
                  aZynqM_v_OC_Conditions.DrivingForward = FALSE;
            }
            else
            {
                  aZynqM_v_OC_Conditions.DrivingForward = TRUE;
            }
        }

    if((OCSpeedLimitMin <= Rx_ZynqMRelatedData.vehSpeed_u16) && (Rx_ZynqMRelatedData.vehSpeed_u16 < OCSpeedLimitMax))
    {
      aZynqM_v_OC_Conditions.SpeedValid_b     = TRUE;
    }
    else
    {
      retVal = FALSE;
      aZynqM_v_OC_Conditions.SpeedValid_b     = FALSE;
    }
  }
#endif

  if((OCSPEEDLIMITMIN < Rx_ZynqRelatedData.vehSpeed_f32) && (Rx_ZynqRelatedData.vehSpeed_f32 <= OCSPEEDLIMITMAX))
  {
    aZynqM_v_OC_Conditions.SpeedValid_b = TRUE;
  }
  else
  {
    retVal = FALSE;
    aZynqM_v_OC_Conditions.SpeedValid_b = FALSE;
  }

  if((e_PW_MODE_RUN == Rx_ZynqRelatedData.ignitionStatus_e) ||
     (e_PW_MODE_IGN_ON == Rx_ZynqRelatedData.ignitionStatus_e))/*RQ: 163845*/
  {
    aZynqM_v_OC_Conditions.IgnitionState_b = TRUE;
  }
  else
  {
    retVal = FALSE;
    aZynqM_v_OC_Conditions.IgnitionState_b = FALSE;
  }
  return retVal;
}

/**************************************************************************************************
 * Function Name : aZynqM_OC_F_GetRunConditions_OEM_b
 * Description   : Check the OEM specific run conditions to execute OC algorithm.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_OC_F_GetRunConditions_OEM_b(void) /* for Pause Resume Algo */
{
  /* DD-ID: {F346C51C-4CA3-44a0-B63C-F6BCA826BEC2}*/
  boolean retVal;

  boolean LVDS_Cam_DTC_Front;
  boolean LVDS_Cam_DTC_Left;
  boolean LVDS_Cam_DTC_Rear;
  boolean LVDS_Cam_DTC_Right;
  static boolean OEMVehicleLevelAS_b_prev;

  aZynqM_v_OC_Conditions_OEM.LeftFrontDoor_b  = (e_DoorCLOSED == Rx_ZynqRelatedData.LeftFrontAJAR_e);
  aZynqM_v_OC_Conditions_OEM.RightFrontDoor_b = (e_DoorCLOSED == Rx_ZynqRelatedData.RightFrontAJAR_e);
  aZynqM_v_OC_Conditions_OEM.LeftRearDoor_b   = (e_DoorCLOSED == Rx_ZynqRelatedData.LeftRearAJAR_e);
  aZynqM_v_OC_Conditions_OEM.RightRearDoor_b  = (e_DoorCLOSED == Rx_ZynqRelatedData.RightRearAJAR_e);

  aZynqM_v_OC_Conditions_OEM.Hood_b           = (e_DoorCLOSED == Rx_ZynqRelatedData.hoodAJAR_e);
  aZynqM_v_OC_Conditions_OEM.Tailgate_b       = (e_DoorCLOSED == Rx_ZynqRelatedData.tlgAJAR_e);

  aZynqM_v_OC_Conditions_OEM.LeftMirror_b     = (MirrorDrivingPosition == Rx_ZynqRelatedData.mirrorLefStatus_u8);
  aZynqM_v_OC_Conditions_OEM.RightMirror_b    = (MirrorDrivingPosition == Rx_ZynqRelatedData.mirrorRigStatus_u8);

  /*RQ: 167257, 167259*/
  aZynqM_v_OC_Conditions_OEM.SteeringAngle_b = ((-AZYNQM_D_ACCEPTEDSTEERINGWHEELANGLE <= Rx_ZynqRelatedData.steeringAngle_f32) && (Rx_ZynqRelatedData.steeringAngle_f32 <= AZYNQM_D_ACCEPTEDSTEERINGWHEELANGLE));

  /* Check for active DTCs relating Cameras */
  LVDS_Cam_DTC_Front = (FALSE != (boolean)m_calsmFIDs.FID_CALSM_FRONT_DISABLED);
  LVDS_Cam_DTC_Left =  (FALSE != (boolean)m_calsmFIDs.FID_CALSM_LEFT_DISABLED);
  LVDS_Cam_DTC_Rear =  (FALSE != (boolean)m_calsmFIDs.FID_CALSM_REAR_DISABLED);
  LVDS_Cam_DTC_Right = (FALSE != (boolean)m_calsmFIDs.FID_CALSM_RIGHT_DISABLED);

  aZynqM_v_OC_Conditions_OEM.LVDS_Cam_shorted_b = (FALSE == LVDS_Cam_DTC_Front) &&
                                                  (FALSE == LVDS_Cam_DTC_Left) &&
                                                  (FALSE == LVDS_Cam_DTC_Rear) &&
                                                  (FALSE == LVDS_Cam_DTC_Right);

  /* Checking if the AirSuspension is Present or Absent */
  if (Rx_ZynqRelatedData.ProxiData_s.PRX_CanNod27_b == TRUE)
  {
    /* Checking if AirSuspension level is NVL */
    if (Rx_ZynqRelatedData.ASCMStatus_e == e_ASCM_Stat_NVL)
    {
      aZynqM_v_OC_Conditions_OEM.VehicleLevelAS_b = TRUE;
    }
    else
    {
      aZynqM_v_OC_Conditions_OEM.VehicleLevelAS_b = FALSE;
    }
  }
  else
  {
    aZynqM_v_OC_Conditions_OEM.VehicleLevelAS_b = TRUE;
  }

  if (OEMVehicleLevelAS_b_prev != aZynqM_v_OC_Conditions_OEM.VehicleLevelAS_b)
  {
    CALSM_DEBUG_PRINT(("OC VehicleLevelAS_b : %d \n ", aZynqM_v_OC_Conditions_OEM.VehicleLevelAS_b));
    OEMVehicleLevelAS_b_prev = aZynqM_v_OC_Conditions_OEM.VehicleLevelAS_b;
 }
  /* Do evaluate ZynqM Related Data */
  if(
      /* Req.ID: 1528419 */
      (aZynqM_v_OC_Conditions_OEM.LeftFrontDoor_b    == TRUE) &&
      (aZynqM_v_OC_Conditions_OEM.RightFrontDoor_b   == TRUE) &&
      (aZynqM_v_OC_Conditions_OEM.LeftRearDoor_b     == TRUE) &&
      (aZynqM_v_OC_Conditions_OEM.RightRearDoor_b    == TRUE) &&

      (aZynqM_v_OC_Conditions_OEM.Hood_b             == TRUE) &&
      (aZynqM_v_OC_Conditions_OEM.Tailgate_b         == TRUE) &&

      (aZynqM_v_OC_Conditions_OEM.LeftMirror_b       == TRUE) &&
      (aZynqM_v_OC_Conditions_OEM.RightMirror_b      == TRUE) &&

      (aZynqM_v_OC_Conditions_OEM.SteeringAngle_b    == TRUE) &&
      (aZynqM_v_OC_Conditions_OEM.LVDS_Cam_shorted_b == TRUE) &&
      (aZynqM_v_OC_Conditions_OEM.VehicleLevelAS_b == TRUE)
    )
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }

  return retVal;
}

/**************************************************************************************************
 * Function Name : aZynqM_EOL_f_IsAlgoRunning_b
 * Description   : Provides the running status of the EOL state machine.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_EOL_f_IsAlgoRunning_b(void)
{
  /* DD-ID: {CF6F3EFC-79F4-4e5d-9835-EA6C19A7493C}*/
  boolean retVal;

  if( ( aZynqM_E_EOL_STM_E_NotInit == aZynqM_v_ModuleState_EOL_STM_e) ||
      ( aZynqM_E_EOL_STM_E_Init    == aZynqM_v_ModuleState_EOL_STM_e) ||
      ( aZynqM_E_EOL_STM_E_Idle    == aZynqM_v_ModuleState_EOL_STM_e) ||
      ( aZynqM_E_EOL_STM_E_Error   == aZynqM_v_ModuleState_EOL_STM_e) ||
      ( aZynqM_E_EOL_STM_E_End     == aZynqM_v_ModuleState_EOL_STM_e)
    )
  {
    retVal = FALSE;
  }
  else
  {
    retVal = TRUE;
  }

  return retVal;
}

/**************************************************************************************************
 * Function Name : aZynqM_SC_f_IsAlgoRunning_b
 * Description   : Provides the running status of the SC state machine.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_SC_f_IsAlgoRunning_b(void)
{
  /* DD-ID: {23C0E2E6-7D9F-44de-A081-3D277271707F}*/
  boolean retVal;

  if( ( aZynqM_E_SC_STM_E_NotInit == aZynqM_v_ModuleState_SC_STM_e) ||
      ( aZynqM_E_SC_STM_E_Init    == aZynqM_v_ModuleState_SC_STM_e) ||
      ( aZynqM_E_SC_STM_E_Idle    == aZynqM_v_ModuleState_SC_STM_e) ||
      ( aZynqM_E_SC_STM_E_Error   == aZynqM_v_ModuleState_SC_STM_e) ||
      ( aZynqM_E_SC_STM_E_End     == aZynqM_v_ModuleState_SC_STM_e)
    )
  {
    retVal = FALSE;
  }
  else
  {
    retVal = TRUE;
  }

  return retVal;
}

/**************************************************************************************************
 * Function Name : aZynqM_OC_f_IsAlgoRunning_b
 * Description   : Provides the running status of the OC state machine.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_OC_f_IsAlgoRunning_b(void)
{
  /* DD-ID: {F2999BC8-308C-4bc7-BEB2-4349A1638B39}*/
  boolean retVal;

  if( ( aZynqM_E_OC_STM_NotInit == aZynqM_v_ModuleState_OC_STM_e) ||
      ( aZynqM_E_OC_STM_Init    == aZynqM_v_ModuleState_OC_STM_e) ||
      ( aZynqM_E_OC_STM_Idle    == aZynqM_v_ModuleState_OC_STM_e) ||
      ( aZynqM_E_OC_STM_Error   == aZynqM_v_ModuleState_OC_STM_e) ||
      ( aZynqM_E_OC_STM_End     == aZynqM_v_ModuleState_OC_STM_e)
    )
  {
    retVal = FALSE;
  }
  else
  {
    retVal = TRUE;
  }

  return retVal;
}

/**************************************************************************************************
 * Function Name : aZynqM_EOL_F_IsAlgoSelected_b
 * Description   : Provides the status of EOL algorithm whether the EOL is selected or not.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
boolean aZynqM_EOL_F_IsAlgoSelected_b(void)
{
  /* DD-ID: {D90C3AAA-E803-4c5e-BE71-C6CD4329F8C5}*/
  return aZynqM_v_EOLAlgoSelected_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_SC_F_IsAlgoSelected_b
 * Description   : Provides the status of SC algorithm whether the SC is selected or not.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
boolean aZynqM_SC_F_IsAlgoSelected_b(void)
{
  /* DD-ID: {DE9B90E1-5A9A-4ce9-82C3-0B04A951B860}*/
  return aZynqM_v_SCAlgoSelected_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_OC_F_IsAlgoSelected_b
 * Description   : Provides the status of OC algorithm whether the OC is selected or not.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
boolean aZynqM_OC_F_IsAlgoSelected_b(void)
{
  /* DD-ID: {86993CDF-9BD5-4bb3-BAF7-B49CCD8C1036}*/
  return aZynqM_v_OCAlgoSelected_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_Request_b
 * Description   : EOL RID triggered from Diagnostic manager to execute the EOL routine.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
boolean aZynqM_F_EOL_Request_b(boolean on_off, aZynqM_S_CamMask_t CamMask)
{
  /* DD-ID: {9ED8750A-6D81-4ec8-AA2E-2F32B6F6A593}*/

  /* TODO : Need to enable in future once the Diag manager is sending the expected target ID and target distance */
  #if 0
    aZynqM_EOL_v_TargetDistance_u16 = targetDistance;
    aZynqM_EOL_v_TargetID_u16 = targetID;
  #endif

  (void)memset(aZynqM_v_EOLCamList_e, CamID_None, sizeof(aZynqM_v_EOLCamList_e));

  /* fill list depending on mask */
  if(0 != CamMask.camFront)
  {
    aZynqM_v_EOLCamList_e[CamID_Front-1] = CamID_Front;
  }
  if(0 != CamMask.camLeft)
  {
    aZynqM_v_EOLCamList_e[CamID_Left-1] = CamID_Left;
  }
  if(0 != CamMask.camRear)
  {
    aZynqM_v_EOLCamList_e[CamID_Rear-1] = CamID_Rear;
  }
  if(0 != CamMask.camRight)
  {
    aZynqM_v_EOLCamList_e[CamID_Right-1] = CamID_Right;
  }

  /* Checking for all cameras masks are not available and only rear cam is requested */
  if ( (0 == CamMask.camFront) && (0 == CamMask.camLeft) && (0 != CamMask.camRear) && (0 == CamMask.camRight))
  {
    IsSingleRearCamVariantActive_b = TRUE;
  }

  ME_Hydra3defs_E_CameraID_t CamID;

  for (CamID = CamID_Front; CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT; CamID++) /* PRQA S 1481 */ /* Suppress warning: "Object of enum type is being modified with an increment or decrement operator." - This is intended and range check is done */
  {
    if ((aZynqM_v_EOLCamList_e[CamID-1] != CamID_None) && (TRUE == on_off))
    {
      aZynqM_v_EOLCamListStatus_e[CamID-1] = ME_Hydra3defs_E_CalibNotStarted; /* reset result information */
      aParaM_F_Clear_EOLCalibData_s(CamID);
      aParaM_F_Clear_SCCalibData_s(CamID);
      aParaM_F_Clear_OCCalibData_s(CamID);
      aParaM_F_Clear_CurrentCalibData_v(CamID);
    }
  }
  aZynqM_EOL_v_IsRequestedByDiag_b = on_off;

  if (FALSE == aZynqM_EOL_v_IsRequestedByDiag_b)
  {
    aZynqM_v_ModuleState_EOL_STM_e = aZynqM_E_EOL_STM_E_Stop;
  }

  return true;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SC_Request_b
 * Description   : SC RID triggered from Diagnostic manager to execute the SC routine.
 * Input         : on_off, CamMask
 * Output        : None
 **************************************************************************************************/
boolean aZynqM_F_SC_Request_b(boolean on_off, aZynqM_S_CamMask_t CamMask)
{
  /* DD-ID: {2BD3C4EF-96D7-48b0-B498-8D8E00A5DB7B}*/
  ME_Hydra3defs_E_CameraID_t CamID;
  boolean v_Ret_b = TRUE;
  ME_Hydra3defs_S_CamEOLCalibData_t EOLCopyCalibData;
  ME_Hydra3defs_S_CamEOLCalibData_t EOLCalibData;
  ME_Hydra3defs_S_CamEOLCalibData_t EOLfsCalibData;

  (void)memset(aZynqM_v_SCCamList_e, CamID_None, sizeof(aZynqM_v_SCCamList_e));
  (void)memset(&SCrxStatus, 0x00, sizeof(SCrxStatus));

  /* fill list depending on mask */
  if(0 != CamMask.camFront)
  {
    aZynqM_v_SCCamList_e[CamID_Front-1] = CamID_Front;
  }
  if(0 != CamMask.camLeft)
  {
    aZynqM_v_SCCamList_e[CamID_Left-1] = CamID_Left;
  }
  if(0 != CamMask.camRear)
  {
    aZynqM_v_SCCamList_e[CamID_Rear-1] = CamID_Rear;
  }
  if(0 != CamMask.camRight)
  {
    aZynqM_v_SCCamList_e[CamID_Right-1] = CamID_Right;
  }

    /* Checking for all cameras masks are not available and only rear cam is requested */
    if ( (0 == CamMask.camFront) && (0 == CamMask.camLeft) && (0 != CamMask.camRear) && (0 == CamMask.camRight))
    {
      IsSingleRearCamVariantActive_b = TRUE;
    }

    for (CamID = CamID_Front; CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT; CamID++) /* PRQA S 1481 */ /* Suppress warning: "Object of enum type is being modified with an increment or decrement operator." - This is intended and range check is done */
    {
      if ((aZynqM_v_SCCamList_e[CamID-1] != CamID_None) && (TRUE == on_off))
      {
        aZynqM_v_SCCamListStatus_e[CamID-1] = ME_Hydra3defs_E_CalibNotStarted; /* reset result information */

        aParaM_F_Clear_SCCalibData_s(CamID);
        aParaM_F_Clear_OCCalibData_s(CamID);
        aParaM_F_Clear_CurrentCalibData_v(CamID);

        /* Get the fsdata for each cam */
        EOLCopyCalibData = aZynqM_F_GetEolPosDeltaCopy_b(CamID);

        /* Check the validity of the EOL data written into the NAND flash */
        if (ME_Hydra3defs_E_CalibCompletedSuccessful != EOLCopyCalibData.calibdata.CalibStatus_e)
        {
          /* If the NAND flash does not contains the EOL valid data, copy the EOL NVM data to fsdata */
          EOLCalibData = aParaM_F_Get_EOLCalibData_s(CamID);

          EOLfsCalibData.X_f32 = EOLCalibData.X_f32;
          EOLfsCalibData.Y_f32 = EOLCalibData.Y_f32;
          EOLfsCalibData.Z_f32 = EOLCalibData.Z_f32;
          EOLfsCalibData.calibdata.Yaw_f32 = EOLCalibData.calibdata.Yaw_f32;
          EOLfsCalibData.calibdata.Roll_f32 = EOLCalibData.calibdata.Roll_f32;
          EOLfsCalibData.calibdata.Pitch_f32 = EOLCalibData.calibdata.Pitch_f32;
          EOLfsCalibData.calibdata.CalibStatus_e = EOLCalibData.calibdata.CalibStatus_e;

          /* Set the EOL NVM data as a fsdata and clear the NVM data for the respective camera */
		  aZynqM_F_SetEolPosDeltaCopy_b(CamID, EOLfsCalibData);

		  IsEOLFsdataUpdateReq = TRUE;
        }

        aParaM_F_Clear_EOLCalibData_s(CamID);
      }
    }

    aZynqM_SC_v_IsRequestedByDiag_b = on_off;
    aZynqM_SC_v_ScCalibrationState_u8 = AZYNQM_D_RC_STATE_RUNNING;
    aZynqM_SC_v_IsHmiEnabled_b = FALSE;

    if (FALSE == aZynqM_SC_v_IsRequestedByDiag_b)
    {
      aZynqM_v_ModuleState_SC_STM_e = aZynqM_E_SC_STM_E_Stop;
      aZynqM_F_DoSCScreenHandling_v(AZYNQM_D_ROUTINE_SC_SCREEN_CANCELLED);
      aZynqM_SC_v_ScCalibrationState_u8 = AZYNQM_D_RC_STATE_IDLE;
    }

  aZynqM_v_SCCompletedCurrentCycle = FALSE;

  return true;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_IsRequested_b
 * Description   : Provides the status whether the EOL algorithm is requested by Diagnostic manager
 *                 or not.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
boolean aZynqM_F_EOL_IsRequested_b(void)
{
  /* DD-ID: {A6E9BB1B-6A8F-4ee2-94E0-A7E7BD242F82}*/
  return aZynqM_EOL_v_IsRequestedByDiag_b;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SC_IsRequested_b
 * Description   : Provides the status whether the SC algorithm is requested by Diagnostic manager
 *                 or not.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
boolean aZynqM_F_SC_IsRequested_b(void)
{
  /* DD-ID: {D3DC3E63-C932-4c64-97CF-43ABF231299C}*/
  return aZynqM_SC_v_IsRequestedByDiag_b;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_GetResultCam_e
 * Description   : Get the EOL calibration result
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_CalibStatus_t aZynqM_F_EOL_GetResultCam_e(ME_Hydra3defs_E_CameraID_t camID)
{
  /* DD-ID: {EEE2C502-7C90-4f04-A6C2-1D345E009977}*/
  ME_Hydra3defs_E_CalibStatus_t ret;

  if((CamID_None < camID) && (camID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    ret = aZynqM_v_EOLCamListStatus_e[camID-1];
  }
  else
  {
    ret = ME_Hydra3defs_E_CalibAbortedFailed;
  }

  return ret;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SC_GetResultCam_e
 * Description   : Get the SC calibration result
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_CalibStatus_t aZynqM_F_SC_GetResultCam_e(ME_Hydra3defs_E_CameraID_t camID)
{
  /* DD-ID: {98E9254E-C78F-47f5-BEA2-1DE52C46CC83}*/
  ME_Hydra3defs_E_CalibStatus_t ret;

  if((CamID_None < camID) && (camID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    ret = aZynqM_v_SCCamListStatus_e[camID-1];
  }
  else
  {
    ret = ME_Hydra3defs_E_CalibAbortedFailed;
  }

  return ret;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_OC_GetResultCam_e
 * Description   : Get the OC calibration result
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_CalibStatus_t aZynqM_F_OC_GetResultCam_e(ME_Hydra3defs_E_CameraID_t camID)
{
  /* DD-ID: {B660A452-B0FB-456d-8B96-F6CDBEAB7E94}*/
  ME_Hydra3defs_E_CalibStatus_t ret;

  if((CamID_None < camID) && (camID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    ret = aZynqM_v_OCCamListStatus_e[camID-1];
  }
  else
  {
    ret = ME_Hydra3defs_E_CalibAbortedFailed;
  }

  return ret;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_OC_GetErrorCodeCam_e
 * Description   : Get the OC error code for selected camera
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_OCErrorCode_t aZynqM_F_OC_GetErrorCodeCam_e(ME_Hydra3defs_E_CameraID_t camID)
{
  /* DD-ID: {91E1CC92-5B3C-4e4a-BE14-47F1F8D532AF}*/
  ME_Hydra3defs_E_OCErrorCode_t ret;

  if((CamID_None < camID) && (camID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    ret = aZynqM_v_OCErrorStatus_e[camID-1];
  }
  else
  {
    ret = e_OC_InitFail;
  }

  return ret;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_GetAlgoState_e
 * Description   : Get the EOL algorithm state
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_EOLAlgoState_t aZynqM_F_EOL_GetAlgoState_e(void)
{
  /* DD-ID: {67EE490E-577B-4c32-A077-5243AE1D4538}*/
  return aZynqM_EOL_v_AlgoState_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_GetErrorCode_e
 * Description   : Get the EOL error code
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_EOLErrorCode_t aZynqM_F_EOL_GetErrorCode_e(void)
{
  /* DD-ID: {EDB81D36-A2FA-4cb3-B056-B8576863C895}*/
  return aZynqM_EOL_v_ErrorCode_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_GetCurrentCam_e
 * Description   : Get the EOL current camera
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_CameraID_t aZynqM_F_EOL_GetCurrentCam_e(void)
{
  /* DD-ID: {CE4E2E5F-79DD-4558-928D-688DF35F2D48}*/
  return aZynqM_v_EOLCurrentCam_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SC_GetCurrentCam_e
 * Description   : Get the SC current camera
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_CameraID_t aZynqM_F_SC_GetCurrentCam_e(void)
{
  /* DD-ID: {2DB793E1-0DA4-4dea-BF09-EEBD2E84D9A1}*/
  return aZynqM_v_SCCurrentCam_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_OC_GetCurrentCam_e
 * Description   : Get the OC current camera
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_CameraID_t aZynqM_F_OC_GetCurrentCam_e(void)
{
  /* DD-ID: {75EAD394-B92B-4f76-8CDC-32D8E4188CA1}*/
  return aZynqM_v_OCCurrentCam_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_OC_GetAlgoState_e
 * Description   : Get the OC algorithm state
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_OCAlgoState_t aZynqM_F_OC_GetAlgoState_e(void)
{
  /* DD-ID: {E0BD4B24-F865-404b-84A5-35406E33039F}*/
  return aZynqM_OC_v_AlgoState_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_OC_GetErrorCode_e
 * Description   : Get the OC error code
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_OCErrorCode_t aZynqM_F_OC_GetErrorCode_e(void)
{
  /* DD-ID: {987534FD-22E2-4311-AE53-2DDFD37C8A5E}*/
  return aZynqM_OC_v_ErrorCode_e;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_OC_GetFeatures_v
 * Description   : Get the OC feature values
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void aZynqM_F_OC_GetFeatures_v(uint32 *validFeatures, uint32 *ignoredFeatures, uint32 *invalidFeatures)
{
  /* DD-ID: {B0F26CBC-DA56-429b-B5C6-3102812D6E69}*/
  if(NULL != validFeatures)
  {
    *validFeatures = aZynqM_OC_v_ValidFeatures_u32;
  }

  if(NULL != ignoredFeatures)
  {
    *ignoredFeatures = aZynqM_OC_v_IgnoredFeatures_u32;
  }

  if(NULL != invalidFeatures)
  {
    *invalidFeatures = aZynqM_OC_v_InvalidFeatures_u32;
  }

  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_GetErrorCodeCam_e
 * Description   : Get the EOL calibration error code
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_EOLErrorCode_t aZynqM_F_EOL_GetErrorCodeCam_e(ME_Hydra3defs_E_CameraID_t camID)
{
  /* DD-ID: {2EA3C683-ED5E-404a-8A1D-9891FD47EBA6}*/
  ME_Hydra3defs_E_EOLErrorCode_t ret;

  if((CamID_None < camID) && (camID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    ret = aZynqM_v_EOLErrorStatus_e[camID-1];
  }
  else
  {
    ret = e_EOL_PRECONDITION_NOT_CORRECT;
  }

  return ret;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_GetTargetDataCam_e
 * Description   : Get the EOL calibration target data
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_S_EOLTargetData_t aZynqM_F_EOL_GetTargetDataCam_e(ME_Hydra3defs_E_CameraID_t camID)
{
  /* DD-ID: {796CE965-8433-4fe7-B295-109918A6246E}*/
  ME_Hydra3defs_S_EOLTargetData_t v_EOLTargetData;

  if((CamID_None < camID) && (camID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    v_EOLTargetData = aZynqM_v_EOLTargetData_e[camID-1];
  }
  else
  {
    (void)memset(&v_EOLTargetData, 0x00, sizeof(v_EOLTargetData));
  }

  return v_EOLTargetData;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_ResetCalibrationData_v
 * Description   : Reset the calibration data
 * Input         : None
 * Output        : None
 **************************************************************************************************/
void aZynqM_F_EOL_ResetCalibrationData_v(void)
{
  /* DD-ID: {BBE9807E-8B69-4d38-93D8-7DD0F1F044FF}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_F_EOL_ResetCalibrationData_v()\n"));

  ME_Hydra3defs_E_CameraID_t CamID;

  for(CamID = CamID_Front; CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT; CamID++) /* PRQA S 1481 */ /* Suppress warning: "Object of enum type is being modified with an increment or decrement operator." - This is intended and range check is done */
  {
    aZynqM_v_EOLErrorStatus_e[CamID-1] = e_EOL_NOT_CALIBRATED;
  }

  aZynqM_EOL_v_AlgoState_e = e_EOLNotInit;
  aZynqM_EOL_v_ErrorCode_e = e_EOL_NOT_CALIBRATED;

  (void)memset(aZynqM_v_EOLCamList_e, CamID_None, sizeof(aZynqM_v_EOLCamList_e));
  (void)memset(aZynqM_v_EOLCamListStatus_e, ME_Hydra3defs_E_CalibNotStarted, sizeof(aZynqM_v_EOLCamListStatus_e));
  (void)memset(aZynqM_v_EOLTargetData_e, 0x00, sizeof(aZynqM_v_EOLTargetData_e));

  aZynqM_v_EOLCurrentCam_e = CamID_None;

  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SC_GetErrorCodeCam_e
 * Description   : Get the SC calibration error code
 * Input         : None
 * Output        : None
 **************************************************************************************************/
ME_Hydra3defs_E_OCErrorCode_t aZynqM_F_SC_GetErrorCodeCam_e(ME_Hydra3defs_E_CameraID_t camID)
{
  /* DD-ID: {BC6A80F8-183E-40bc-A4D6-61A88B469F18}*/
  ME_Hydra3defs_E_OCErrorCode_t ret;

  if((CamID_None < camID) && (camID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    ret = aZynqM_v_SCErrorStatus_e[camID-1];
  }
  else
  {
    ret = e_OC_InitFail;
  }

  return ret;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SC_ResetCalibrationData_v
 * Description   : Reset the calibration data
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_F_SC_ResetCalibrationData_v(void)
{
  /* DD-ID: {BEF1CF47-8B0B-4024-ABA1-4651220A0070}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_F_SC_ResetCalibrationData_v()\n"));

  ME_Hydra3defs_E_CameraID_t CamID;

  for(CamID = CamID_Front; CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT; CamID++) /* PRQA S 1481 */ /* Suppress warning: "Object of enum type is being modified with an increment or decrement operator." - This is intended and range check is done */
  {
    aZynqM_v_SCErrorStatus_e[CamID-1] = e_OC_StartFail;
  }

  (void)memset(aZynqM_v_SCCamList_e, CamID_None, sizeof(aZynqM_v_SCCamList_e));
  (void)memset(aZynqM_v_SCCamListStatus_e, ME_Hydra3defs_E_CalibNotStarted, sizeof(aZynqM_v_SCCamListStatus_e));

  aZynqM_v_SCCurrentCam_e = CamID_None;

  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_OC_ResetCalibrationData_v
 * Description   : Reset the OC calibration data
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_F_OC_ResetCalibrationData_v(void)
{
  /* DD-ID: {11DD191D-33E6-4521-A1A7-FD33A2DED613}*/
  CALSM_DEBUG_PRINT(("CALSM aZynqM_F_SC_ResetCalibrationData_v()\n"));

  (void)memset(aZynqM_v_OCCamListStatus_e, ME_Hydra3defs_E_CalibNotStarted, sizeof(aZynqM_v_OCCamListStatus_e));
  (void)memset(aZynqM_v_OCErrorStatus_e, e_OC_NoError, sizeof(aZynqM_v_OCErrorStatus_e));

  aZynqM_OC_v_ValidFeatures_u32 = 0;
  aZynqM_OC_v_IgnoredFeatures_u32 = 0;
  aZynqM_OC_v_InvalidFeatures_u32 = 0;

  aZynqM_OC_v_AlgoState_e = e_OC_Uninit;
  aZynqM_OC_v_ErrorCode_e = e_OC_NoError;

  aZynqM_v_OCCurrentCam_e = CamID_None;

  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_StartConditionsCorrect_b
 * Description   : Check for the EOL start conditions
 * Input         : None
 * Output        : None
 **************************************************************************************************/
boolean aZynqM_F_EOL_StartConditionsCorrect_b(void)
{
  /* DD-ID: {EEE4182E-9B2F-4633-B724-7123279F38DA}*/
  boolean retVal = FALSE;
  static boolean EOL_VehicleLevelAS_b_prev;

  /* set EOL PreConditon details */
  aZynqM_v_EOL_Conditions.LeftFrontDoor_b   = (e_DoorCLOSED == Rx_ZynqRelatedData.LeftFrontAJAR_e);
  aZynqM_v_EOL_Conditions.RightFrontDoor_b  = (e_DoorCLOSED == Rx_ZynqRelatedData.RightFrontAJAR_e);
  aZynqM_v_EOL_Conditions.LeftRearDoor_b    = (e_DoorCLOSED == Rx_ZynqRelatedData.LeftRearAJAR_e);
  aZynqM_v_EOL_Conditions.RightRearDoor_b   = (e_DoorCLOSED == Rx_ZynqRelatedData.RightRearAJAR_e);
  aZynqM_v_EOL_Conditions.Tailgate_b        = (e_DoorCLOSED == Rx_ZynqRelatedData.tlgAJAR_e);
  aZynqM_v_EOL_Conditions.Hood_b            = (e_DoorCLOSED == Rx_ZynqRelatedData.hoodAJAR_e);
  aZynqM_v_EOL_Conditions.LeftMirror_b      = (MirrorDrivingPosition == Rx_ZynqRelatedData.mirrorLefStatus_u8);
  aZynqM_v_EOL_Conditions.RightMirror_b     = (MirrorDrivingPosition == Rx_ZynqRelatedData.mirrorRigStatus_u8);

  /* Checking if the AirSuspension is Present or Absent */
  if (Rx_ZynqRelatedData.ProxiData_s.PRX_CanNod27_b == TRUE)
  {
    /* Checking if AirSuspension level is NVL */
    if (Rx_ZynqRelatedData.ASCMStatus_e == e_ASCM_Stat_NVL)
    {
      aZynqM_v_EOL_Conditions.VehicleLevel_b = TRUE;
    }
    else
    {
      aZynqM_v_EOL_Conditions.VehicleLevel_b = FALSE;
    }
  }
  else
  {
    aZynqM_v_EOL_Conditions.VehicleLevel_b = TRUE;
  }

  /* Do evaluate ZynqM Related Data */
  if((TRUE == aZynqM_v_EOL_Conditions.LeftFrontDoor_b ) &&
      (TRUE == aZynqM_v_EOL_Conditions.RightFrontDoor_b) &&
      (TRUE == aZynqM_v_EOL_Conditions.LeftRearDoor_b  ) &&
      (TRUE == aZynqM_v_EOL_Conditions.RightRearDoor_b ) &&
      (TRUE == aZynqM_v_EOL_Conditions.Tailgate_b      ) &&
      (TRUE == aZynqM_v_EOL_Conditions.Hood_b          ) &&
      (TRUE == aZynqM_v_EOL_Conditions.LeftMirror_b    ) &&
      (TRUE == aZynqM_v_EOL_Conditions.RightMirror_b   ) &&
      (TRUE == aZynqM_v_EOL_Conditions.VehicleLevel_b)
    )
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }

  if (EOL_VehicleLevelAS_b_prev != aZynqM_v_EOL_Conditions.VehicleLevel_b)
  {
    CALSM_DEBUG_PRINT(("EOL VehicleLevel_b : %d \n ", aZynqM_v_EOL_Conditions.VehicleLevel_b));
    CALSM_DEBUG_PRINT(("aZynqM_F_EOL_StartConditionsCorrect_b : %d \n", retVal));
    EOL_VehicleLevelAS_b_prev = aZynqM_v_EOL_Conditions.VehicleLevel_b;
  }

  return retVal;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_GetEOLStatusCurrentCycle
 * Description   : Get EOL current cycle status
 * Input         : None
 * Output        : boolean
 **************************************************************************************************/
boolean aZynqM_F_GetEOLStatusCurrentCycle(void)
{
  /* DD-ID: {DCCF4B22-3C15-4ce3-BF34-40FF5391699C}*/
  return aZynqM_v_EOLCompletedCurrentCycle;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_GetSCStatusCurrentCycle
 * Description   : Get SC current cycle status
 * Input         : None
 * Output        : boolean
 **************************************************************************************************/
boolean aZynqM_F_GetSCStatusCurrentCycle(void)
{
  /* DD-ID: {59AEFEC9-CD70-4123-8778-EBF342BBA451}*/
  return aZynqM_v_SCCompletedCurrentCycle;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_EOL_GetStartConditionDetails_s
 * Description   : Get start conditions for EOL
 * Input         : None
 * Output        : aZynqM_S_EOL_Conditions_t
 **************************************************************************************************/
aZynqM_S_EOL_Conditions_t aZynqM_F_EOL_GetStartConditionDetails_s(void)
{
  /* DD-ID: {B3695A4D-879D-41bf-AA0D-A5D145EB89CD}*/
  return aZynqM_v_EOL_Conditions;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SC_GetStartConditionDetails_s
 * Description   : Get start conditions for SC
 * Input         : None
 * Output        : aZynqM_S_SCConditions_t
 **************************************************************************************************/
aZynqM_S_SCConditions_t aZynqM_F_SC_GetStartConditionDetails_s(void)
{
  /* DD-ID: {FFCE5FDB-8FE5-449d-8C37-F3319565FE68}*/
  return aZynqM_v_SC_Conditions;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SC_GetCamList_v
 * Description   : Get TSC camera list
 * Input         : None
 * Output        : aZynqM_S_SCConditions_t
 **************************************************************************************************/
static void aZynqM_F_SC_GetCamList_v(ME_Hydra3defs_E_CameraID_t camlist[])
{
  /* DD-ID: {9876833D-0E4B-4e36-B0CB-1F28ADE69A71}*/
  if(0 != camlist)
  {
    (void)memcpy(camlist, aZynqM_v_SCCamList_e, sizeof(aZynqM_v_SCCamList_e));
  }
  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SC_IsHmiEnabled_b
 * Description   : Thsi function describes the HMI is enabled or not.
 *                 or not.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
boolean aZynqM_F_SC_IsHmiEnabled_b(void)
{
  /* DD-ID: {B6CD9B6A-9676-430f-90C3-143FC223230F}*/
  return aZynqM_SC_v_IsHmiEnabled_b;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SetAlgoControl_Tx_Request_v
 * Description   : Set the algo header and algo data
 * Input         : None
 * Output        : None
 **************************************************************************************************/
Std_E_ReturnType_t aZynqM_F_SetAlgoControl_Tx_Request_v(ME_Hydra3defs_S_AlgoControlHeader_t const * AlgoControl_header, ME_Hydra3defs_S_AlgoControlData_t const * AlgoControl_data) /* PRQA S 1505 */ /* function is used by aDiagM.c */
{
  /* DD-ID: {84142EBD-C4C2-483a-A25C-29E250E40F8E}*/
  return Std_E_RetType_Successful;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_GetEOLStatusPrevCycle
 * Description   : Get EOL previous cycle calibration status
 * Input         : None
 * Output        : boolean
 **************************************************************************************************/
static boolean aZynqM_F_GetEOLStatusPrevCycle(void)
{
  /* DD-ID: {6FFC4F3D-1127-428b-A89E-C703D994C96A}*/
  return bIsEolSuccessPrevCycle;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_GeSCStatusPrevCycle
 * Description   : Get SC previous cycle calibration status
 * Input         : None
 * Output        : boolean
 **************************************************************************************************/
static boolean aZynqM_F_GetSCStatusPrevCycle(void)
{
  /* DD-ID: {EDA14370-F44E-4c6b-80C4-E526C4210D1A}*/
  return bIsSCSuccessPrevCycle;
}

/**************************************************************************************************
 * Function Name : aParaM_F_Clear_EOLCalibData_s
 * Description   : Clear EOL calibration Data
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aParaM_F_Clear_EOLCalibData_s(ME_Hydra3defs_E_CameraID_t CamID)
{
  /* DD-ID: {A1E0A0EC-4154-4e03-BD29-33413041B0AC}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Clear_EOLCalibData_s()\n"));

  ME_Hydra3defs_S_CamEOLCalibDataSTM_t v_calibdata;
  (void)memset(&v_calibdata, 0x00, sizeof(v_calibdata));

  if ((CamID_None < CamID) && (CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    EOLCalibDataToNVM.bValid = TRUE;
    EOLCalibDataToNVM.FreshnessCount++;
  }

  switch(CamID)
  {
    case CamID_Front:
      EOLCalibDataToNVM.CamEOL.CamFrontEOL = v_calibdata;
      break;
    case CamID_Left:
      EOLCalibDataToNVM.CamEOL.CamLeftEOL = v_calibdata;
      break;
    case CamID_Rear:
      EOLCalibDataToNVM.CamEOL.CamRearEOL = v_calibdata;
      break;
    case CamID_Right:
      EOLCalibDataToNVM.CamEOL.CamRightEOL = v_calibdata;
      break;
    default:
    {
      /* Do nothing */
      break;
    }
  }

  return;
}

/**************************************************************************************************
 * Function Name : aParaM_F_Set_EOLCalibData_s
 * Description   : Set EOL calibration Data
 * Input         : CamID, EOLCalibData
 * Output        : None
 **************************************************************************************************/
static void aParaM_F_Set_EOLCalibData_s(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_S_CamEOLCalibData_t EOLCalibData)
{
  /* DD-ID: {6BD807A2-7D98-45a9-881B-6445B7C07BF1}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Set_EOLCalibData_s() - %d\n", CamID));
  ME_Hydra3defs_S_CamEOLCalibData_t EOLfsCalibData;

  if ((CamID_None < CamID) && (CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    EOLCalibDataToNVM.bValid = TRUE;
    EOLCalibDataToNVM.FreshnessCount++;
  }

  if (TRUE == aZynqM_F_IsSingleCamVariantRequested())
  {
    /* Setting up the calibration type as EOL */
    EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibIDs_STM = CalibrationID_EOL;
    EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibIDs_STM = CalibrationID_EOL;
    EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibIDs_STM = CalibrationID_EOL;

    /* Setting up the default calibration status as successful */
	EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM.calibdata.CalibStatus_e = ME_Hydra3defs_E_CalibCompletedSuccessful;
	EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM.calibdata.CalibStatus_e = ME_Hydra3defs_E_CalibCompletedSuccessful;
	EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM.calibdata.CalibStatus_e = ME_Hydra3defs_E_CalibCompletedSuccessful;
  }

  switch(CamID)
  {
    case CamID_Front:
      EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM = EOLCalibData;
      EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibIDs_STM = CalibrationID_EOL;
      break;
    case CamID_Left:
      EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM = EOLCalibData;
      EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibIDs_STM = CalibrationID_EOL;
      break;
    case CamID_Rear:
      EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM = EOLCalibData;
      EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibIDs_STM = CalibrationID_EOL;
      break;
    case CamID_Right:
      EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM = EOLCalibData;
      EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibIDs_STM = CalibrationID_EOL;
      break;
    default:
      /* Do nothing */
      break;
  }

  /* copying the EOL NVM data (dX, dY and dZ) to use it for
   * SC position adjustment to enhance top view stitching.
   */
  EOLfsCalibData = EOLCalibData;
  aZynqM_F_SetEolPosDeltaCopy_b(CamID, EOLfsCalibData);

}

/**************************************************************************************************
 * Function Name : aParaM_F_Get_EOLCalibData_s
 * Description   : Get EOL calibration Data
 * Input         : CamID
 * Output        : None
 **************************************************************************************************/
static ME_Hydra3defs_S_CamEOLCalibData_t aParaM_F_Get_EOLCalibData_s(ME_Hydra3defs_E_CameraID_t CamID) /* PRQA S 1505 */ /* Suppress warning: "The function 'name' is only referenced in the translation unit where it is defined." - This function is used in ZynqM */
{
  /* DD-ID: {815F2A72-E38B-4ee7-9675-F72551440040}*/
  ME_Hydra3defs_S_CamEOLCalibData_t retCalib;
  (void)memset(&retCalib, 0x00, sizeof(retCalib));

  switch(CamID)
  {
    case CamID_Front:
      retCalib = EOLCalibDataToNVM.CamEOL.CamFrontEOL.CamCalibData_STM;
      break;
    case CamID_Left:
      retCalib = EOLCalibDataToNVM.CamEOL.CamLeftEOL.CamCalibData_STM;
      break;
    case CamID_Rear:
      retCalib = EOLCalibDataToNVM.CamEOL.CamRearEOL.CamCalibData_STM;
      break;
    case CamID_Right:
      retCalib = EOLCalibDataToNVM.CamEOL.CamRightEOL.CamCalibData_STM;
      break;
    default:
      /* Do nothing */
      break;
  }

  return retCalib;
}

/**************************************************************************************************
 * Function Name : aParaM_F_Clear_SCCalibData_s
 * Description   : Clear SC calibration Data
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aParaM_F_Clear_SCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID)
{
  /* DD-ID: {2D9AA927-443A-4be6-A07D-BA8FD741039B}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Clear_SCCalibData_s()\n"));

  ME_Hydra3defs_S_CamCalibDataSTM_t v_calibdata;
  (void)memset(&v_calibdata, 0x00, sizeof(v_calibdata));

  if ((CamID_None < CamID) && (CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    SCCalibDataToNVM.bValid = TRUE;
    SCCalibDataToNVM.FreshnessCount++;
  }

  switch(CamID)
  {
    case CamID_Front:
      SCCalibDataToNVM.CamSC.CamFrontSC = v_calibdata;
      break;
    case CamID_Left:
      SCCalibDataToNVM.CamSC.CamLeftSC = v_calibdata;
      break;
    case CamID_Rear:
      SCCalibDataToNVM.CamSC.CamRearSC = v_calibdata;
      break;
    case CamID_Right:
      SCCalibDataToNVM.CamSC.CamRightSC = v_calibdata;
      break;
    default:
    {
      /* Do nothing */
      break;
    }
  }

  return;
}

/**************************************************************************************************
 * Function Name : aParaM_F_Set_SCCalibData_s
 * Description   : Set SC calibration Data
 * Input         : CamID, SCCalibData
 * Output        : None
 **************************************************************************************************/
static void aParaM_F_Set_SCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_S_CamCalibData_t SCCalibData)
{
  /* DD-ID: {435A19ED-A068-47c5-B1E1-71D5E709EF29}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Set_SCCalibData_s() - %d\n", CamID));

  if ((CamID_None < CamID) && (CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    SCCalibDataToNVM.bValid = TRUE;
    SCCalibDataToNVM.FreshnessCount++;
  }

  if (TRUE == aZynqM_F_IsSingleCamVariantRequested())
  {
    /* Setting up the calibration type as EOL */
    SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibIDs_STM = CalibrationID_SC;
    SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibIDs_STM = CalibrationID_SC;
    SCCalibDataToNVM.CamSC.CamRightSC.CamCalibIDs_STM = CalibrationID_SC;

    /* Setting up the default calibration status as successful */
    SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibData_STM.CalibStatus_e = ME_Hydra3defs_E_CalibCompletedSuccessful;
    SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibData_STM.CalibStatus_e = ME_Hydra3defs_E_CalibCompletedSuccessful;
    SCCalibDataToNVM.CamSC.CamRightSC.CamCalibData_STM.CalibStatus_e = ME_Hydra3defs_E_CalibCompletedSuccessful;
  }

  switch(CamID)
  {
    case CamID_Front:
      SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibData_STM = SCCalibData;
      SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibIDs_STM = CalibrationID_SC;
      break;
    case CamID_Left:
      SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibData_STM = SCCalibData;
      SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibIDs_STM = CalibrationID_SC;
      break;
    case CamID_Rear:
      SCCalibDataToNVM.CamSC.CamRearSC.CamCalibData_STM = SCCalibData;
      SCCalibDataToNVM.CamSC.CamRearSC.CamCalibIDs_STM = CalibrationID_SC;
      break;
    case CamID_Right:
      SCCalibDataToNVM.CamSC.CamRightSC.CamCalibData_STM = SCCalibData;
      SCCalibDataToNVM.CamSC.CamRightSC.CamCalibIDs_STM = CalibrationID_SC;
      break;
    default:
      /* Do nothing */
      break;
  }
}

/**************************************************************************************************
 * Function Name : aParaM_F_Get_SCCalibData_s
 * Description   : Get SC calibration Data
 * Input         : CamID
 * Output        : None
 **************************************************************************************************/
static ME_Hydra3defs_S_CamCalibData_t aParaM_F_Get_SCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID) /* PRQA S 1505 */ /* Suppress warning: "The function 'name' is only referenced in the translation unit where it is defined." - This function is used in ZynqM */
{
  /* DD-ID: {C242505D-509F-4245-B31C-CF7D90B3CE39}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Get_SCCalibData_s() - %d\n", CamID));

  ME_Hydra3defs_S_CamCalibData_t retCalib;
  (void)memset(&retCalib, 0x00, sizeof(retCalib));

  switch(CamID)
  {
    case CamID_Front:
      retCalib = SCCalibDataToNVM.CamSC.CamFrontSC.CamCalibData_STM;
      break;
    case CamID_Left:
      retCalib = SCCalibDataToNVM.CamSC.CamLeftSC.CamCalibData_STM;
      break;
    case CamID_Rear:
      retCalib = SCCalibDataToNVM.CamSC.CamRearSC.CamCalibData_STM;
      break;
    case CamID_Right:
      retCalib = SCCalibDataToNVM.CamSC.CamRightSC.CamCalibData_STM;
      break;
    default:
    {
      /* Do nothing */
      break;
    }
  }

  return retCalib;
}

/**************************************************************************************************
 * Function Name : aParaM_F_Clear_OCCalibData_s
 * Description   : Clear SC calibration Data
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aParaM_F_Clear_OCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID)
{
  /* DD-ID: {53B55843-6CB8-4a64-8AFE-15EF40E529E2}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Clear_OCCalibData_s()\n"));

  ME_Hydra3defs_S_CamCalibDataSTM_t v_calibdata;
  (void)memset(&v_calibdata, 0x00, sizeof(v_calibdata));

  if ((CamID_None < CamID) && (CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    OCCalibDataToNVM.bValid = TRUE;
    OCCalibDataToNVM.FreshnessCount++;
  }

  switch(CamID)
  {
    case CamID_Front:
      OCCalibDataToNVM.CamOC.CamFrontOC = v_calibdata;
      break;
    case CamID_Left:
      OCCalibDataToNVM.CamOC.CamLeftOC = v_calibdata;
      break;
    case CamID_Rear:
      OCCalibDataToNVM.CamOC.CamRearOC = v_calibdata;
      break;
    case CamID_Right:
      OCCalibDataToNVM.CamOC.CamRightOC = v_calibdata;
      break;
    default:
    {
      /* Do nothing */
      break;
    }
  }

  return;
}

/**************************************************************************************************
 * Function Name : aParaM_F_Set_OCCalibData_s
 * Description   : Set SC calibration Data
 * Input         : CamID, SCCalibData
 * Output        : None
 **************************************************************************************************/
static void aParaM_F_Set_OCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_S_CamCalibData_t OCCalibData)
{
  /* DD-ID: {C695165C-ADEF-4ab5-BD4A-6F6922C64009}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Set_OCCalibData_s() - %d\n", CamID));

  if (false == aZynqM_F_IsOcDataIPCReady_v())
  {
    if ((CamID_None < CamID) && (CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
    {
      OCCalibDataToNVM.bValid = TRUE;
      OCCalibDataToNVM.FreshnessCount++;
    }

    switch(CamID)
    {
      case CamID_Front:
        OCCalibDataToNVM.CamOC.CamFrontOC.CamCalibData_STM = OCCalibData;
        OCCalibDataToNVM.CamOC.CamFrontOC.CamCalibIDs_STM = CalibrationID_OC;
        break;
      case CamID_Left:
        OCCalibDataToNVM.CamOC.CamLeftOC.CamCalibData_STM = OCCalibData;
        OCCalibDataToNVM.CamOC.CamLeftOC.CamCalibIDs_STM = CalibrationID_OC;
        break;
      case CamID_Rear:
        OCCalibDataToNVM.CamOC.CamRearOC.CamCalibData_STM = OCCalibData;
        OCCalibDataToNVM.CamOC.CamRearOC.CamCalibIDs_STM = CalibrationID_OC;
        break;
      case CamID_Right:
        OCCalibDataToNVM.CamOC.CamRightOC.CamCalibData_STM = OCCalibData;
        OCCalibDataToNVM.CamOC.CamRightOC.CamCalibIDs_STM = CalibrationID_OC;
        break;
      default:
        /* Do nothing */
        break;
    }
  }
  else
  {
	  /* No OC data will be saved to NVM once the shutdown signal is triggered */
  }
}

/**************************************************************************************************
 * Function Name : aParaM_F_Get_OCCalibData_s
 * Description   : Get SC calibration Data
 * Input         : CamID
 * Output        : None
 **************************************************************************************************/
static ME_Hydra3defs_S_CamCalibData_t aParaM_F_Get_OCCalibData_s(ME_Hydra3defs_E_CameraID_t CamID) /* PRQA S 1505 */ /* Suppress warning: "The function 'name' is only referenced in the translation unit where it is defined." - This function is used in ZynqM */
{
  /* DD-ID: {A021357E-F097-4874-B1F3-82737B8A8D85}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Get_OCCalibData_s() - %d\n", CamID));

  ME_Hydra3defs_S_CamCalibData_t retCalib;
  (void)memset(&retCalib, 0x00, sizeof(retCalib));

  switch(CamID)
  {
    case CamID_Front:
      retCalib = OCCalibDataToNVM.CamOC.CamFrontOC.CamCalibData_STM;
      break;
    case CamID_Left:
      retCalib = OCCalibDataToNVM.CamOC.CamLeftOC.CamCalibData_STM;
      break;
    case CamID_Rear:
      retCalib = OCCalibDataToNVM.CamOC.CamRearOC.CamCalibData_STM;
      break;
    case CamID_Right:
      retCalib = OCCalibDataToNVM.CamOC.CamRightOC.CamCalibData_STM;
      break;
    default:
    {
      /* Do nothing */
      break;
    }
  }

  return retCalib;
}

/**************************************************************************************************
 * Function Name : aParaM_F_Clear_CurrentCalibData_v
 * Description   : Clear Current calibration Data
 * Input         : CamID
 * Output        : None
 **************************************************************************************************/
static void aParaM_F_Clear_CurrentCalibData_v(ME_Hydra3defs_E_CameraID_t CamID)
{
  /* DD-ID: {9EA0274A-B955-4fb3-9734-074A179CB128}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Clear_CurrentCalibData_s()\n"));

  ME_Hydra3defs_S_CamEOLCalibDataSTM_t v_calibdata;
  (void)memset(&v_calibdata, 0x00, sizeof(v_calibdata));

  if ((CamID_None < CamID) && (CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    CurrentCalibDataToNVM.bValid = TRUE;
    CurrentCalibDataToNVM.FreshnessCount++;
  }

  switch(CamID)
  {
    case CamID_Front:
      CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent = v_calibdata;
      break;
    case CamID_Left:
      CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent = v_calibdata;
      break;
    case CamID_Rear:
      CurrentCalibDataToNVM.CamCurrent.CamRearCurrent = v_calibdata;
      break;
    case CamID_Right:
      CurrentCalibDataToNVM.CamCurrent.CamRightCurrent = v_calibdata;
      break;
    default:
    {
      /* Do nothing */
      break;
    }
  }

  return;
}

/**************************************************************************************************
 * Function Name : aParaM_F_Set_CurrentCalibData_v
 * Description   : Set Current calibration Data
 * Input         : CamID, CurrentCalibData
 * Output        : None
 **************************************************************************************************/
static void aParaM_F_Set_CurrentCalibData_v(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_S_CamEOLCalibData_t CurrentCalibData)
{
  /* DD-ID: {FF98C6DC-6307-4283-8A32-9BCE594DA407}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Set_CurrentCalibData_s() - %d\n", CamID));

  if ((CamID_None < CamID) && (CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    CurrentCalibDataToNVM.bValid = TRUE;
    CurrentCalibDataToNVM.FreshnessCount++; 
  }

  switch(CamID)
  {
    case CamID_Front:
      CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM = CurrentCalibData;
      break;
    case CamID_Left:
      CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM = CurrentCalibData;
      break;
    case CamID_Rear:
      CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM = CurrentCalibData;
      break;
    case CamID_Right:
      CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM = CurrentCalibData;
      break;
    default:
      /* Do nothing */
      break;
  }
}

/**************************************************************************************************
 * Function Name : aParaM_F_Get_CurrentCalibData_s
 * Description   : Get Current calibration Data
 * Input         : CamID
 * Output        : None
 **************************************************************************************************/
static ME_Hydra3defs_S_CamEOLCalibData_t aParaM_F_Get_CurrentCalibData_s(ME_Hydra3defs_E_CameraID_t CamID)
{
  /* DD-ID: {382F31E3-3D25-4127-BA92-177FCE6B9BA8}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Get_CurrentCalibData_s() - %d\n", CamID));

  ME_Hydra3defs_S_CamEOLCalibData_t retCalib;
  (void)memset(&retCalib, 0x00, sizeof(retCalib));

  switch(CamID)
  {
    case CamID_Front:
      retCalib = CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM;
      break;
    case CamID_Left:
      retCalib = CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM;
      break;
    case CamID_Rear:
      retCalib = CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM;
      break;
    case CamID_Right:
      retCalib = CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM;
      break;
    default:
    {
      /* Do nothing */
      break;
    }
  }

  return retCalib;
}

/**************************************************************************************************
 * Function Name : aParaM_F_Get_CurrentCalibID_s
 * Description   : Get Current calibration IDs
 * Input         : CamID
 * Output        : None
 **************************************************************************************************/
static ME_Hydra3defs_E_CalibrationID_t aParaM_F_Get_CurrentCalibID_s(ME_Hydra3defs_E_CameraID_t CamID)
{
  /* DD-ID: {1076812B-B08A-43cd-8C79-8BBD8D10DFB3}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Get_CurrentCalibID_s() - %d\n", CamID));

  ME_Hydra3defs_E_CalibrationID_t calibID;
  calibID = CalibrationID_Zero;

  switch(CamID)
  {
    case CamID_Front:
      calibID = CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibIDs_STM;
      break;
    case CamID_Left:
      calibID = CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibIDs_STM;
      break;
    case CamID_Rear:
      calibID = CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibIDs_STM;
      break;
    case CamID_Right:
      calibID = CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibIDs_STM;
      break;
    default:
      /* Do nothing */
      break;
  }

  return calibID;
}

/**************************************************************************************************
 * Function Name : aParaM_F_Set_CurrentCalibID_v
 * Description   : Set Current calibration IDs
 * Input         : CamID, CurrentCalibID
 * Output        : None
 **************************************************************************************************/
static void aParaM_F_Set_CurrentCalibID_v(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_E_CalibrationID_t calibID)
{
  /* DD-ID: {6329EAAE-D853-44ce-8B3D-D9B5218E2B86}*/
  CALSM_DEBUG_PRINT(("CALSM aParaM_F_Set_CurrentCalibID_v() - %d\n", CamID));

  if ((CamID_None < CamID) && (CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {
    CurrentCalibDataToNVM.bValid = TRUE;
    CurrentCalibDataToNVM.FreshnessCount++;
  }

  switch(CamID)
  {
    case CamID_Front:
      CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibIDs_STM = calibID;
      break;
    case CamID_Left:
      CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibIDs_STM = calibID;
      break;
    case CamID_Rear:
      CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibIDs_STM = calibID;
      break;
    case CamID_Right:
      CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibIDs_STM = calibID;
      break;
    default:
      /* Do nothing */
      break;
  }

  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_IsOcDataIPCReady_v
 * Description   : Ready to send the OC data over the IPC
 * Input         : None
 * Output        : None
 **************************************************************************************************/
boolean aZynqM_F_IsOcDataIPCReady_v(void)
{
  /* DD-ID: {93DD1801-4824-42d1-94BE-E3E8096A572D}*/
  return v_IsOCDataIPCReady_b;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_IsShutdownTriggered_v
 * Description   : Receive the shudwon signal
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_F_IsShutdownTriggered_v(void)
{
  /* DD-ID: {221573D5-442B-49b5-BEDA-43D9D2DFF6B6}*/
  return aZynqM_v_ShutdownTriggered_b;
}

/**************************************************************************************************
 * Function Name : aParaM_F_GetLastOCCurrentCam_e
 * Description   : Get last saved NVM camera
 * Input         : CamID, CurrentCalibID
 * Output        : None
 **************************************************************************************************/
static ME_Hydra3defs_E_CameraID_t aParaM_F_GetLastOCCurrentCam_e(void)
{
  /* DD-ID: {62EA899E-A6BF-4913-8F27-D3CF470D3B68}*/
#if LAST_OC_CAM_ENABLED
  ME_Hydra3defs_E_CameraID_t v_LastCam = CamID_None;

  if ( TRUE == CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] )
  {
    v_LastCam = CamID_Front;
  }
  else if ( TRUE == CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] )
  {
    v_LastCam = CamID_Left;
  }
  else if ( TRUE == CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] )
  {
    v_LastCam = CamID_Rear;
  }
  else if ( TRUE == CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] )
  {
    v_LastCam = CamID_Right;
  }
  else
  {
	  /* Do Nothing */
  }
#endif

#if LAST_OC_CAM_ENABLED
  return v_LastCam;
#else
  /* This part of code can be enable once the LastOCCurrentCam is stored to the NVM at mcu1_0 */
  return OCCalibDataToNVM.LastOCCurrentCam;
#endif
}

/**************************************************************************************************
 * Function Name : aParaM_F_SetLastOCCurrentCam_v
 * Description   : Set the last camera to NVM
 * Input         : CamID, CurrentCalibID
 * Output        : None
 **************************************************************************************************/
static void aParaM_F_SetLastOCCurrentCam_v(ME_Hydra3defs_E_CameraID_t cam)
{
  /* DD-ID: {848B7542-D752-4d6c-9EA3-5F62E7349011}*/
  if ((CamID_None < cam) && (cam <= ME_HYDRA3DEFS_D_CAMERACOUNT))
  {

  #if LAST_OC_CAM_ENABLED
    /* Below code is Hack for OC */
	switch(cam)
	{
	  case CamID_Front:
	    CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = TRUE;
	    CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
	    CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
	    CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
	    break;
	  case CamID_Left:
		CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
		CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = TRUE;
		CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
		CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
	    break;
	  case CamID_Rear:
		CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
		CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
		CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = TRUE;
		CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
	    break;
	  case CamID_Right:
		CurrentCalibDataToNVM.CamCurrent.CamFrontCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
		CurrentCalibDataToNVM.CamCurrent.CamLeftCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
		CurrentCalibDataToNVM.CamCurrent.CamRearCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = FALSE;
		CurrentCalibDataToNVM.CamCurrent.CamRightCurrent.CamCalibData_STM.Reserved_u8[OC_LAST_CAM_BYTE] = TRUE;
	    break;
	  default:
	    /* Do nothing */
	    break;
	}
  #else
	/* This part of code can be enable once the LastOCCurrentCam is stored to the NVM at mcu1_0 */
    OCCalibDataToNVM.bValid = TRUE;
    OCCalibDataToNVM.FreshnessCount++;
	OCCalibDataToNVM.LastOCCurrentCam = cam;
  #endif

  }
  else
  {
    /* Do Nothing */
  }

  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_OC_f_GetNextCamera_e
 * Description   : Get the next camera
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static ME_Hydra3defs_E_CameraID_t aZynqM_OC_f_GetNextCamera_e(ME_Hydra3defs_E_CameraID_t v_currentCam)
{
  /* DD-ID: {5D622518-ABB7-4e64-8FDC-F39657E1B73A}*/
  ME_Hydra3defs_E_CameraID_t v_nextCam;

  if(CamID_None == v_currentCam)
  {
    /* get from NVM */
    v_nextCam = aParaM_F_GetLastOCCurrentCam_e();
  }
  else
  {
    v_nextCam = v_currentCam;
    /* increment camID */
    v_nextCam++; /* PRQA S 1481 */ /* Suppress warning: "Object of enum type is being modified with an increment or decrement operator." - This is intended and range check is done */
  }

  /* range check */
  if( (ME_HYDRA3DEFS_D_CAMERACOUNT < v_nextCam) || (CamID_None == v_nextCam) )
  {
    v_nextCam = CamID_Front;
  }
  else
  {
    /* do nothing */
  }
  
  return v_nextCam;
}
/**************************************************************************************************
 * Function Name : aZynqM_CalibrationSelector_f_CalibdataWeighting_e
 * Description   : Averaging the yaw , roll and pitch values
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static ME_Hydra3defs_S_CamCalibData_t aZynqM_CalibrationSelector_f_CalibdataWeighting_e(ME_Hydra3defs_S_CamCalibData_t v_BaseCalibData, ME_Hydra3defs_S_CamCalibData_t v_AdditionalCalibData, uint8 v_Weighting_u8)
{
  /* DD-ID: {04F48918-40C9-4164-BE37-B6F88B76D7C6}*/
  ME_Hydra3defs_S_CamCalibData_t v_ResultCalibData;
  float32 v_deltaPitch_f32;
  float32 v_deltaYaw_f32;
  float32 v_deltaRoll_f32;

  v_ResultCalibData = v_BaseCalibData;

  v_deltaPitch_f32 = v_AdditionalCalibData.Pitch_f32;
  v_deltaYaw_f32   = v_AdditionalCalibData.Yaw_f32;
  v_deltaRoll_f32  = v_AdditionalCalibData.Roll_f32;

  if(v_Weighting_u8 <= 100) /* 100 % maximum */
  {
    float32 AdditionalFactor_f32 = ((float32)v_Weighting_u8 / 100.0f);
    float32 BaseFactor_f32 = (1.0f - AdditionalFactor_f32);

    v_ResultCalibData.Pitch_f32 = ((v_BaseCalibData.Pitch_f32 * BaseFactor_f32) + (v_deltaPitch_f32 * AdditionalFactor_f32));
    v_ResultCalibData.Yaw_f32   = ((v_BaseCalibData.Yaw_f32   * BaseFactor_f32) + (v_deltaYaw_f32   * AdditionalFactor_f32));
    v_ResultCalibData.Roll_f32  = ((v_BaseCalibData.Roll_f32  * BaseFactor_f32) + (v_deltaRoll_f32  * AdditionalFactor_f32));
  }
  else
  {
    /* do nothing */
  }

  return v_ResultCalibData;
}

/**************************************************************************************************
 * Function Name : aZynqM_CalibrationSelector_f_SelectCalibration_b
 * Description   : None
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static boolean aZynqM_CalibrationSelector_f_SelectCalibration_b(void)
{
  /* DD-ID: {2D40A4A6-2E9B-4d6c-A583-EFA97345DACE}*/
  /* choose between EOL OC SC */
  /* set to current calibration */
  /*
    Priority
    Highest: CurrentCalib
    High: OC
    Med: SC
    Low: EOL
  */
  ME_Hydra3defs_E_CameraID_t CamID;
  ME_Hydra3defs_S_CamCalibData_t OCCalibData;
  ME_Hydra3defs_S_CamCalibData_t SCCalibData;
  ME_Hydra3defs_S_CamEOLCalibData_t EOLCalibData;
  ME_Hydra3defs_S_CamEOLCalibData_t CurrentCalibData;
  ME_Hydra3defs_E_CalibrationID_t currentID;
  ME_Hydra3defs_S_CamEOLCalibData_t EOLCopyCalibData;

  uint8   v_WeightingOCResults_u8;
  boolean retVal;

#if ENABLE_OC
  boolean v_ApplyOCResults_b;
  v_ApplyOCResults_b      = (boolean)functionalSettingsNVM.OC_ApplyResults_u8;
  v_WeightingOCResults_u8 = functionalSettingsNVM.OC_Weighting_u8;
#endif
#if 0
  v_ApplyOCResults_b      = TRUE;
  v_WeightingOCResults_u8 = OC_WEIGHTING;
#endif

  for(CamID = CamID_Front; CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT; CamID++) /* PRQA S 1481 */ /* Suppress warning: "Object of enum type is being modified with an increment or decrement operator." - This is intended and range check is done */
  {
    currentID = aParaM_F_Get_CurrentCalibID_s(CamID);
    CurrentCalibData = aParaM_F_Get_CurrentCalibData_s(CamID);

#if ENABLE_OC
    if(ME_Hydra3defs_E_CalibCompletedSuccessful == CurrentCalibData.calibdata.CalibStatus_e)
    {
      /* Current Calibration has valid data for this cam, check if OC can be applied */
      if(TRUE == v_ApplyOCResults_b)
      {
        OCCalibData = aParaM_F_Get_OCCalibData_s(CamID);
        if( (ME_Hydra3defs_E_CalibCompletedSuccessful == OCCalibData.CalibStatus_e) &&
            (TRUE == OCCalibData.NewValueAvailable_b)
           )
        {
          boolean OCRangeValid_b;
          OCRangeValid_b = aZynqM_CalibrationSelector_f_RangeCheck_e(OCCalibData);

          if(TRUE == OCRangeValid_b)
          {
            #if SC_CAM_POS_ADJUSTMENT_ENABLE
            /* As the X Y Z are not calculated for SC, the same will be used
             * from EOL if the cameras for SC calibration are successfully
             * calibrated. This is to match the stitching offset.
             */
             EOLCopyCalibData = aZynqM_F_GetEolPosDeltaCopy_b(CamID);
             CurrentCalibData.X_f32 = EOLCopyCalibData.X_f32;
             CurrentCalibData.Y_f32 = EOLCopyCalibData.Y_f32;
             CurrentCalibData.Z_f32 = EOLCopyCalibData.Z_f32;
             #endif

            CurrentCalibData.calibdata = aZynqM_CalibrationSelector_f_CalibdataWeighting_e(CurrentCalibData.calibdata, OCCalibData, v_WeightingOCResults_u8); /* add OC calib data */

            currentID = CalibrationID_OC;

            /* only reset flag */
            OCCalibData.NewValueAvailable_b = FALSE;
            aParaM_F_Set_OCCalibData_s(CamID, OCCalibData);
          }
          else
          {
            /* OC data is out of range, do nothing */
          }
        }
        else if(ME_Hydra3defs_E_CalibAbortedFailed == OCCalibData.CalibStatus_e)
        {
          /* OC is not valid or no new value available for this cam, do nothing */
        }
        else
        {
          /* OC is not valid or no new value available for this cam, do nothing */
        }
      }
      else
      {
        /* OC values shall not be applied, do nothing */
      }
    }
    else
    {
#endif
      /* Current Calibration has no valid data for this cam */

      /* set Zero calibration if EOL calib data is invalid */
      (void)memset(&CurrentCalibData, 0x00, sizeof(CurrentCalibData));
      CurrentCalibData.calibdata.CalibStatus_e = ME_Hydra3defs_E_CalibNotStarted;
      currentID = CalibrationID_Zero;

      EOLCalibData = aParaM_F_Get_EOLCalibData_s(CamID);
      if(ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCalibData.calibdata.CalibStatus_e)
      {
        boolean EOLRangeValid_b;
        ME_Hydra3defs_S_CamCalibData_t EOLCalibData_PYR;

        EOLCalibData_PYR = EOLCalibData.calibdata;
        EOLRangeValid_b = aZynqM_CalibrationSelector_f_RangeCheck_e(EOLCalibData_PYR);

        if(TRUE == EOLRangeValid_b)
        {
          /* EOL is valid */
          CurrentCalibData = EOLCalibData;
          currentID = CalibrationID_EOL;
        }
        else
        {
            /* EOL data is out of range, do nothing */
            /* do nothing, currentID is set above for this branch */
        }
      }
      else if(ME_Hydra3defs_E_CalibAbortedFailed == EOLCalibData.calibdata.CalibStatus_e)
      {
        CurrentCalibData.calibdata.CalibStatus_e = ME_Hydra3defs_E_CalibAbortedFailed;
      }
      else
      {
        /* do nothing, currentID is set above for this branch */
      }

      SCCalibData = aParaM_F_Get_SCCalibData_s(CamID);
      if(ME_Hydra3defs_E_CalibCompletedSuccessful == SCCalibData.CalibStatus_e)
      {
        boolean SCRangeValid_b;
        SCRangeValid_b = aZynqM_CalibrationSelector_f_RangeCheck_e(SCCalibData);

        if(TRUE == SCRangeValid_b)
        {
          #if SC_CAM_POS_ADJUSTMENT_ENABLE
            /* As the X Y Z are not calculated for SC, the same will be used
             * from EOL if the cameras for SC calibration are successfully
             * calibrated. This is to match the stitching offset.
             */
          EOLCopyCalibData = aZynqM_F_GetEolPosDeltaCopy_b(CamID);
          CurrentCalibData.X_f32 = EOLCopyCalibData.X_f32;
          CurrentCalibData.Y_f32 = EOLCopyCalibData.Y_f32;
          CurrentCalibData.Z_f32 = EOLCopyCalibData.Z_f32;
          #endif

          CurrentCalibData.calibdata = SCCalibData; /* add SC calib data */

          currentID = CalibrationID_SC;
        }
        else
        {
          /* SC data is out of range, do nothing */
        }
      }
      else if(ME_Hydra3defs_E_CalibAbortedFailed == SCCalibData.CalibStatus_e)
      {
          CurrentCalibData.calibdata.CalibStatus_e = ME_Hydra3defs_E_CalibAbortedFailed;
      }
      else
      {
        /* do nothing, currentID is set above for this branch */
      }
#if ENABLE_OC
    }
#endif

    aParaM_F_Set_CurrentCalibID_v(CamID, currentID);
    aParaM_F_Set_CurrentCalibData_v(CamID, CurrentCalibData);

    #if LAST_OC_CAM_ENABLED
      aParaM_F_SetLastOCCurrentCam_v(aZynqM_v_OCCurrentCam_e);
    #endif
  }

  return TRUE;
}

/*
 * ========================= TSC SCREEN HANDLING ==================================================
 */

/**************************************************************************************************
 * Function Name : aCalsm_f_SCScreen_GetPercentage_uint8
 * Description   : This function describes the percentage of calibration process.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static uint8 aZynqM_f_SCScreen_GetPercentage_uint8(ME_Hydra3defs_E_CameraID_t currentCamID)
{
  /* DD-ID: {76ACA097-6861-4e05-B070-4378E7AED7F7}*/
  uint8 percentage = 0;
  static boolean isPer75Reached = FALSE;

  if (currentCamID != CamID_None)
  {
    /* Ignored Initial CamID_None. Corrected*/
    percentage = aZynqM_f_SCScreen_GetCamPercentage_uint8(currentCamID);
  }

  /* Percentage per Camera at 25 %  Refer TSC Spec*/
  if(percentage >= 25)
  {
    percentage = percentage - 25;
  }
  else
  {
    percentage = 0;
  }

  /*Check if 4th camera is completed then provide precentage as 100*/
  if (percentage >= 75)
  {
    isPer75Reached = TRUE;
  }
  if ((isPer75Reached == TRUE) && (percentage == 0))
  {
    percentage = 100;
  }


  return percentage;
}

/**************************************************************************************************
 * Function Name : aCalsm_f_SCScreen_GetCamPercentage_uint8
 * Description   : This function describes the percentage of camera calibrated.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static uint8 aZynqM_f_SCScreen_GetCamPercentage_uint8(ME_Hydra3defs_E_CameraID_t currentCamID)
{
  /* DD-ID: {97FF0C57-B9DF-47cb-B93E-5E61465F840E}*/
  uint8 count;
  uint8 percentage;
  uint8 camorderlist[ME_HYDRA3DEFS_D_CAMERACOUNT];

  count = aZynqM_f_SCScreen_GetCamOrder_uint8(camorderlist);

  if(0 == count)
  {
    percentage = 100;
  }
  else
  {
    percentage = (100 * camorderlist[currentCamID-1]) / count;

    /* limit to 100 */
    if(percentage > 100)
    {
      percentage = 100;
    }
  }

  return percentage;
}

/**************************************************************************************************
 * Function Name : aCalsm_f_SCScreen_GetCamOrder_uint8
 * Description   : This function describes the percentage of camera calibrated.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static uint8 aZynqM_f_SCScreen_GetCamOrder_uint8(uint8 camorderlist[])
{
  /* DD-ID: {7A36C45E-C557-468d-B8C6-C29A78C98AD3}*/
  ME_Hydra3defs_E_CameraID_t CamID;
  uint8 count = 0;
  ME_Hydra3defs_E_CameraID_t camlist[ME_HYDRA3DEFS_D_CAMERACOUNT];
  uint8 camorder[ME_HYDRA3DEFS_D_CAMERACOUNT];
  aZynqM_F_SC_GetCamList_v(camlist);

  for(CamID = CamID_Front; CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT; CamID++)
  {
    if(CamID == camlist[CamID-1])
    {
      count++;
      camorder[CamID-1] = count; /* set current index */
    }
    else
    {
      camorder[CamID-1] = 0; /* cam is not selected */
    }
  }

  if(0 != camorderlist)
  {
    (void)memcpy(camorderlist, camorder, sizeof(camorder));
  }

  return count;
}

/**************************************************************************************************
 * Function Name : aCalsm_f_HandleRoutineRunning_v
 * Description   : Get response from algorithm
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_f_HandleRoutineRunning_v(void)
{
  /* DD-ID: {2ED5D231-963C-4b65-9D37-81BC379920AD}*/
  if (aZynqM_SC_v_ScCalibrationState_u8 == AZYNQM_D_RC_STATE_RUNNING)
  {
    /* set routine to completed if not requested anymore => SC STM finished in ZynqM */
    if (FALSE == aZynqM_F_SC_IsRequested_b())
    {
      static uint32 waitcount_uint32 = 0;

      if (waitcount_uint32 < AZYNQM_D_ROUTINE_SC_SCREEN_END_WAITTIME)
      {
        aZynqM_F_DoSCScreenHandling_v(AZYNQM_D_ROUTINE_SC_SCREEN_END);
      }
      else
      {
        /* do nothing */
      }

      if (AZYNQM_D_ROUTINE_SC_SCREEN_END_WAITTIME == waitcount_uint32)
      {
        aZynqM_SC_v_ScCalibrationState_u8 = AZYNQM_D_RC_STATE_IDLE;
        aZynqM_SC_v_IsHmiEnabled_b = TRUE;
      }
      else
      {
        waitcount_uint32++;
      }
    }
    else
    {
      aZynqM_F_DoSCScreenHandling_v(AZYNQM_D_ROUTINE_SC_SCREEN_RUNNING);
    }
  }
  else
  {
	/* Enable the HMI and disable the TSC screen */
    aZynqM_SC_v_IsHmiEnabled_b = TRUE;
  }
  return;
}

/**************************************************************************************************
 * Function Name : aCalsm_f_SCScreen_GetCamOrder_uint8
 * Description   : This function describes the percentage of camera calibrated.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_F_DoSCScreenHandling_v(uint32 SCstate)
{
  /* DD-ID: {40F0298B-0CBF-4423-BD5C-48B8FF048D4D}*/
  aZynqM_S_ScScreenType_t prevScreen;
  ME_Hydra3defs_E_CameraID_t CamID;
  aZynqM_S_ScScreenType_t currentScreen;
  aZynqM_S_SCConditions_t scconditions;
  aZynqM_S_SCConditions_t scconditionsref;
  sint32 diff;
  ME_Hydra3defs_E_CameraID_t camlist[ME_HYDRA3DEFS_D_CAMERACOUNT];

  scconditions = aZynqM_F_SC_GetRunConditions_s();
  aZynqM_F_GetScreen_v(&prevScreen); /* get current screen */
  aZynqM_F_GetScreen_v(&currentScreen); /* get current screen */

  /* set all overlays to zero */
  (void)memset(&currentScreen.Tsc_OverlayBits, 0x00, sizeof(currentScreen.Tsc_OverlayBits));

  if (AZYNQM_D_ROUTINE_SC_SCREEN_CANCELLED != SCstate)
  {
    /* set corresponding overlay */
    currentScreen.Tsc_OverlayBits.SrvLayout_b = TRUE;

    if (TRUE == scconditions.SteeringAngle_b)
    {
      currentScreen.Tsc_OverlayBits.SrvStAngIndOk_b = TRUE;
      currentScreen.Tsc_OverlayBits.SrvStAngIndNok_b = FALSE;
    }
    else
    {
      currentScreen.Tsc_OverlayBits.SrvStAngIndOk_b = FALSE;
      currentScreen.Tsc_OverlayBits.SrvStAngIndNok_b = TRUE;
    }

    if (TRUE == scconditions.SpeedValid_b)
    {
      currentScreen.Tsc_OverlayBits.SrvSpOmIndOk_b = TRUE;
      currentScreen.Tsc_OverlayBits.SrvSpOmIndNok_b = FALSE;
    }
    else
    {
      currentScreen.Tsc_OverlayBits.SrvSpOmIndOk_b = FALSE;
      currentScreen.Tsc_OverlayBits.SrvSpOmIndNok_b = TRUE;
    }

    /* indication button */
    (void) memset(&scconditionsref, 0x01, sizeof(scconditionsref));
    diff = memcmp(&scconditions, &scconditionsref, sizeof(scconditions));
    if (0 == diff)
    {
      currentScreen.Tsc_OverlayBits.SrvChkIndCondNok_b = FALSE; /* red pause error */
      currentScreen.Tsc_OverlayBits.SrvChkIndRun_b = TRUE; /* green run symbol */
    }
    else
    {
      currentScreen.Tsc_OverlayBits.SrvChkIndCondNok_b = TRUE; /* red pause error */
      currentScreen.Tsc_OverlayBits.SrvChkIndRun_b = FALSE; /* green run symbol */
    }

    aZynqM_F_SC_GetCamList_v(camlist);
    /* set pending or none if cam is in list or not */
    if (CamID_Right == camlist[CamID_Right - 1])
    {
      ME_Hydra3defs_E_CalibStatus_t camstatus = aZynqM_F_SC_GetResultCam_e(CamID_Right);
      if (ME_Hydra3defs_E_CalibCompletedSuccessful == camstatus)
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndRiOk_b = TRUE;
      }
      else if (ME_Hydra3defs_E_CalibAbortedFailed == camstatus)
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndRiNok_b = TRUE;
      }
      else if ((ME_Hydra3defs_E_CalibRunning == camstatus) || (ME_Hydra3defs_E_CalibPending == camstatus))
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndRiPend_b = TRUE;
      }
      else
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndRiNone_b = TRUE;
      }
    }
    else
    {
      /* not selected for calibration, set no overlay for arrow */
    }
    if (CamID_Rear == camlist[CamID_Rear - 1])
    {
      ME_Hydra3defs_E_CalibStatus_t camstatus = aZynqM_F_SC_GetResultCam_e(CamID_Rear);
      if (ME_Hydra3defs_E_CalibCompletedSuccessful == camstatus)
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndBaOk_b = TRUE;
      }
      else if (ME_Hydra3defs_E_CalibAbortedFailed == camstatus)
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndBaNok_b = TRUE;
      }
      else if ((ME_Hydra3defs_E_CalibRunning == camstatus) || (ME_Hydra3defs_E_CalibPending == camstatus))
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndBaPend_b = TRUE;
      }
      else
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndBaNone_b = TRUE;
      }
    }
    else
    {
      /* not selected for calibration, set no overlay for arrow */
    }
    if (CamID_Left == camlist[CamID_Left - 1])
    {
      ME_Hydra3defs_E_CalibStatus_t camstatus = aZynqM_F_SC_GetResultCam_e(CamID_Left);
      if (ME_Hydra3defs_E_CalibCompletedSuccessful == camstatus)
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndLeOk_b = TRUE;
      }
      else if (ME_Hydra3defs_E_CalibAbortedFailed == camstatus)
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndLeNok_b = TRUE;
      }
      else if ((ME_Hydra3defs_E_CalibRunning == camstatus) || (ME_Hydra3defs_E_CalibPending == camstatus))
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndLePend_b = TRUE;
      }
      else
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndLeNone_b = TRUE;
      }
    }
    else
    {
      /* not selected for calibration, set no overlay for arrow */
    }
    if (CamID_Front == camlist[CamID_Front - 1])
    {
      ME_Hydra3defs_E_CalibStatus_t camstatus = aZynqM_F_SC_GetResultCam_e(CamID_Front);
      if (ME_Hydra3defs_E_CalibCompletedSuccessful == camstatus)
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndFrOk_b = TRUE;
      }
      else if (ME_Hydra3defs_E_CalibAbortedFailed == camstatus)
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndFrNok_b = TRUE;
      }
      else if ((ME_Hydra3defs_E_CalibRunning == camstatus) || (ME_Hydra3defs_E_CalibPending == camstatus))
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndFrPend_b = TRUE;
      }
      else
      {
        currentScreen.Tsc_OverlayBits.SrvCamIndFrNone_b = TRUE; /* selected, but not triggered yet *//* must be gray */
      }
    }
    else
    {
      /* not selected for calibration, set no overlay for arrow */
    }

    /* progress percentage calculation */
    {
      uint8 percentage;
      static uint8 percentageprev;

      CamID = aZynqM_F_SC_GetCurrentCam_e();

      /*Store and pass the prev percentage value when shutdown occurs*/
      if (FALSE == aZynqM_F_IsShutdownTriggered_v())
      {
        /* Get the progress bar status when shutdown is nto requested */
        percentage = aZynqM_f_SCScreen_GetPercentage_uint8(CamID);

        /* Store the previous progress bar status */
        percentageprev = percentage;
      }
      else
      {
        /* Fetch the old percentage bar status when shutdown is triggered */
        percentage = percentageprev;
      }


      if ((percentage == 100))// || (AZYNQM_D_ROUTINE_SC_SCREEN_END == SCstate))
      {
        currentScreen.Tsc_OverlayBits.SrvPrgBar100Per_b = TRUE;
      }
      else if (percentage >= 75)
      {
        currentScreen.Tsc_OverlayBits.SrvPrgBar75Per_b = TRUE;
      }
      else if (percentage >= 50)
      {
        currentScreen.Tsc_OverlayBits.SrvPrgBar50Per_b = TRUE;
      }
      else if (percentage >= 25)
      {
        currentScreen.Tsc_OverlayBits.SrvPrgBar25Per_b = TRUE;
      }
      else
      {
        currentScreen.Tsc_OverlayBits.SrvPrgBar0Per_b = TRUE;
      }
    }

    if (AZYNQM_D_ROUTINE_SC_SCREEN_END == SCstate)
    {
      boolean SCFailed = FALSE;

      for (CamID = CamID_Front; CamID <= ME_HYDRA3DEFS_D_CAMERACOUNT; CamID++) /* PRQA S 1481 *//* Suppress warning: "Object of enum type is being modified with an increment or decrement operator." - This is intended and range check is done */
      {
        if (CamID == camlist[CamID - 1])
        {
          /* cam is in list */
          ME_Hydra3defs_E_CalibStatus_t camstatus;
          camstatus = aZynqM_F_SC_GetResultCam_e(CamID);

          if (ME_Hydra3defs_E_CalibCompletedSuccessful != camstatus)
          {
            SCFailed = TRUE;
          }
        }
      }
      /* indication button */
      if (TRUE == SCFailed)
      {
        currentScreen.Tsc_OverlayBits.SrvChkIndOk_b = FALSE; /* green check */
        currentScreen.Tsc_OverlayBits.SrvChkIndNok_b = TRUE; /* red cross error */
        currentScreen.Tsc_OverlayBits.SrvChkIndCondNok_b = FALSE; /* red pause error */
        currentScreen.Tsc_OverlayBits.SrvChkIndRun_b = FALSE; /* green run symbol */
      }
      else
      {
        currentScreen.Tsc_OverlayBits.SrvChkIndOk_b = TRUE;
        currentScreen.Tsc_OverlayBits.SrvChkIndNok_b = FALSE;
        currentScreen.Tsc_OverlayBits.SrvChkIndCondNok_b = FALSE;
        currentScreen.Tsc_OverlayBits.SrvChkIndRun_b = FALSE;
      }
    }

    /* only send on change */
    diff = memcmp(&prevScreen, &currentScreen, sizeof(aZynqM_S_ScScreenType_t));
    if (0 != diff)
    {
      aZynqM_F_SetScreen_v(&currentScreen);
    }
  }
  else
  {
	/* Enable the HMI and disable the TSC screen */
    aZynqM_SC_v_IsHmiEnabled_b = TRUE;
  }
  return;
  
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SetScreen_v
 * Description   : This function set the view and overlay bits corresponding to TSC screen.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_F_SetScreen_v(const aZynqM_S_ScScreenType_t *screen)
{
  /* DD-ID: {E5058B59-09E6-466c-BC37-3D6883053ED8}*/
  if(NULL != screen)
  {
    /* Setting the TSC screen overlay bits */
    (void)memcpy(&aZynqM_v_TscSetScreen.Tsc_OverlayBits, &screen->Tsc_OverlayBits, sizeof(aZynqM_v_TscSetScreen.Tsc_OverlayBits));

    /* Setting the required view for TSC screen */
   // aZynqM_v_TscSetScreen.Tsc_view = screen->Tsc_view;
  }
  else
  {
    /*do nothing*/
  }

  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_GetScreen_v
 * Description   : This function get the view and overlay details from HMI (mcu2_0).
 * Input         : None
 * Output        : None
 **************************************************************************************************/
static void aZynqM_F_GetScreen_v(aZynqM_S_ScScreenType_t *screen)
{
  /* DD-ID: {F4EAED89-93C9-4c77-97B9-B241430DCF00}*/
  if (NULL != screen)
  {
	/* Ensuring no garbage values for TSC overlayBits and view */
    (void)memset(screen, 0x00, sizeof(aZynqM_S_ScScreenType_t));  /* be sure there is no garbage in passed structure */

    /* Getting the TSC screen overlay bits */
    (void)memcpy(&screen->Tsc_OverlayBits, &aZynqM_v_TscGetScreen.Tsc_OverlayBits, sizeof(screen->Tsc_OverlayBits));

    /* Getting the required view for TSC screen */
    //screen->Tsc_view = aZynqM_v_TscGetScreen.Tsc_view;
  }
  else
  {
    /* do nothing */
  }
  return;
}

/**************************************************************************************************
 * Function Name : aZynqM_F_SetEolPosDeltaCopy_b
 * Description   : Copy the EOL X Y and Z delta from the EOL to utilized it for SC.
 * Input         : None
 * Output        : None
 **************************************************************************************************/
#if SC_CAM_POS_ADJUSTMENT_ENABLE
static void aZynqM_F_SetEolPosDeltaCopy_b(ME_Hydra3defs_E_CameraID_t CamID, ME_Hydra3defs_S_CamEOLCalibData_t EOLCalibData)
{
  /* DD-ID: {CC24B31F-A69A-4b50-8589-EA03EE4801BA}*/
  if (ME_Hydra3defs_E_CalibCompletedSuccessful == EOLCalibData.calibdata.CalibStatus_e)
  {
    switch(CamID)
    {
	  case CamID_Front:
		  m_SCPosAdjustment.CamFrontEOL.X_f32 = EOLCalibData.X_f32;
		  m_SCPosAdjustment.CamFrontEOL.Y_f32 = EOLCalibData.Y_f32;
		  m_SCPosAdjustment.CamFrontEOL.Z_f32 = EOLCalibData.Z_f32;
          m_SCPosAdjustment.CamFrontEOL.Pitch_f32 = EOLCalibData.calibdata.Pitch_f32;
          m_SCPosAdjustment.CamFrontEOL.Yaw_f32 = EOLCalibData.calibdata.Yaw_f32;
          m_SCPosAdjustment.CamFrontEOL.Roll_f32 = EOLCalibData.calibdata.Roll_f32;
          m_SCPosAdjustment.CamFrontEOL.CalibStatus_e = EOLCalibData.calibdata.CalibStatus_e;
	      break;

	  case CamID_Left:
		  m_SCPosAdjustment.CamLeftEOL.X_f32 = EOLCalibData.X_f32;
		  m_SCPosAdjustment.CamLeftEOL.Y_f32 = EOLCalibData.Y_f32;
		  m_SCPosAdjustment.CamLeftEOL.Z_f32 = EOLCalibData.Z_f32;
          m_SCPosAdjustment.CamLeftEOL.Pitch_f32 = EOLCalibData.calibdata.Pitch_f32;
          m_SCPosAdjustment.CamLeftEOL.Yaw_f32 = EOLCalibData.calibdata.Yaw_f32;
          m_SCPosAdjustment.CamLeftEOL.Roll_f32 = EOLCalibData.calibdata.Roll_f32;
          m_SCPosAdjustment.CamLeftEOL.CalibStatus_e = EOLCalibData.calibdata.CalibStatus_e;
	      break;

	  case CamID_Rear:
		  m_SCPosAdjustment.CamRearEOL.X_f32 = EOLCalibData.X_f32;
		  m_SCPosAdjustment.CamRearEOL.Y_f32 = EOLCalibData.Y_f32;
		  m_SCPosAdjustment.CamRearEOL.Z_f32 = EOLCalibData.Z_f32;
          m_SCPosAdjustment.CamRearEOL.Pitch_f32 = EOLCalibData.calibdata.Pitch_f32;
          m_SCPosAdjustment.CamRearEOL.Yaw_f32 = EOLCalibData.calibdata.Yaw_f32;
          m_SCPosAdjustment.CamRearEOL.Roll_f32 = EOLCalibData.calibdata.Roll_f32;
          m_SCPosAdjustment.CamRearEOL.CalibStatus_e = EOLCalibData.calibdata.CalibStatus_e;
	      break;

	  case CamID_Right:
		  m_SCPosAdjustment.CamRightEOL.X_f32 = EOLCalibData.X_f32;
		  m_SCPosAdjustment.CamRightEOL.Y_f32 = EOLCalibData.Y_f32;
		  m_SCPosAdjustment.CamRightEOL.Z_f32 = EOLCalibData.Z_f32;
          m_SCPosAdjustment.CamRightEOL.Pitch_f32 = EOLCalibData.calibdata.Pitch_f32;
          m_SCPosAdjustment.CamRightEOL.Yaw_f32 = EOLCalibData.calibdata.Yaw_f32;
          m_SCPosAdjustment.CamRightEOL.Roll_f32 = EOLCalibData.calibdata.Roll_f32;
          m_SCPosAdjustment.CamRightEOL.CalibStatus_e = EOLCalibData.calibdata.CalibStatus_e;
	      break;
	  default:
	      /* Do nothing */
	      break;
    }
  }
}
#endif
/**************************************************************************************************
 * Function Name : aZynqM_F_GetEolDeltaPositionCopy_b
 * Description   : Get the copy the EOL dX dY dZ and dYaw, dRoll, dPitch delta from the EOL to
 * utilized it for SC.
 * Input         : Camera ID
 * Output        : None
 **************************************************************************************************/
#if SC_CAM_POS_ADJUSTMENT_ENABLE
static ME_Hydra3defs_S_CamEOLCalibData_t aZynqM_F_GetEolPosDeltaCopy_b(ME_Hydra3defs_E_CameraID_t CamID)
{
  /* DD-ID: {F9EE7B40-57B9-422e-9F3D-4A544D69F0C6}*/
  ME_Hydra3defs_S_CamEOLCalibData_t EOLCalibData;

  switch(CamID)
  {
	case CamID_Front:
		EOLCalibData.X_f32 = m_SCPosAdjustment.CamFrontEOL.X_f32;
		EOLCalibData.Y_f32 = m_SCPosAdjustment.CamFrontEOL.Y_f32;
		EOLCalibData.Z_f32 = m_SCPosAdjustment.CamFrontEOL.Z_f32;
        EOLCalibData.calibdata.Pitch_f32 = m_SCPosAdjustment.CamFrontEOL.Pitch_f32;
		EOLCalibData.calibdata.Yaw_f32 = m_SCPosAdjustment.CamFrontEOL.Yaw_f32;
		EOLCalibData.calibdata.Roll_f32 = m_SCPosAdjustment.CamFrontEOL.Roll_f32;
		EOLCalibData.calibdata.CalibStatus_e = m_SCPosAdjustment.CamFrontEOL.CalibStatus_e;
	    break;

	case CamID_Left:
		EOLCalibData.X_f32 = m_SCPosAdjustment.CamLeftEOL.X_f32;
		EOLCalibData.Y_f32 = m_SCPosAdjustment.CamLeftEOL.Y_f32;
		EOLCalibData.Z_f32 = m_SCPosAdjustment.CamLeftEOL.Z_f32;
        EOLCalibData.calibdata.Pitch_f32 = m_SCPosAdjustment.CamLeftEOL.Pitch_f32;
        EOLCalibData.calibdata.Yaw_f32 = m_SCPosAdjustment.CamLeftEOL.Yaw_f32;
        EOLCalibData.calibdata.Roll_f32 = m_SCPosAdjustment.CamLeftEOL.Roll_f32;
        EOLCalibData.calibdata.CalibStatus_e = m_SCPosAdjustment.CamLeftEOL.CalibStatus_e;
	    break;

	case CamID_Rear:
		EOLCalibData.X_f32 = m_SCPosAdjustment.CamRearEOL.X_f32;
		EOLCalibData.Y_f32 = m_SCPosAdjustment.CamRearEOL.Y_f32;
		EOLCalibData.Z_f32 = m_SCPosAdjustment.CamRearEOL.Z_f32;
        EOLCalibData.calibdata.Pitch_f32 = m_SCPosAdjustment.CamRearEOL.Pitch_f32;
        EOLCalibData.calibdata.Yaw_f32 = m_SCPosAdjustment.CamRearEOL.Yaw_f32;
        EOLCalibData.calibdata.Roll_f32 = m_SCPosAdjustment.CamRearEOL.Roll_f32;
        EOLCalibData.calibdata.CalibStatus_e = m_SCPosAdjustment.CamRearEOL.CalibStatus_e;
	    break;

	case CamID_Right:
		EOLCalibData.X_f32 = m_SCPosAdjustment.CamRightEOL.X_f32;
		EOLCalibData.Y_f32 = m_SCPosAdjustment.CamRightEOL.Y_f32;
		EOLCalibData.Z_f32 = m_SCPosAdjustment.CamRightEOL.Z_f32;
        EOLCalibData.calibdata.Pitch_f32 = m_SCPosAdjustment.CamRightEOL.Pitch_f32;
        EOLCalibData.calibdata.Yaw_f32 = m_SCPosAdjustment.CamRightEOL.Yaw_f32;
        EOLCalibData.calibdata.Roll_f32 = m_SCPosAdjustment.CamRightEOL.Roll_f32;
        EOLCalibData.calibdata.CalibStatus_e = m_SCPosAdjustment.CamRightEOL.CalibStatus_e;
	    break;

	default:
	    /* Do nothing */
	    break;
  }
  return EOLCalibData;
}
#endif

/* --------------------------------------------------------------------------------- */
/* END OF FILE: SVSCamCalibSM.c */

