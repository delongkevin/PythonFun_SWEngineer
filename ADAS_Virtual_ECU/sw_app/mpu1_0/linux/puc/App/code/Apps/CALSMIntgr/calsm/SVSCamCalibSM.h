/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 * This document in its entirety is CONFIDENTIAL and may not be disclosed,
 * disseminated or distributed to parties outside MAGNA Electronics
 * without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:       Signalmanager for Zynq, responsible for sending and receiving Messages from Zynq
 * DESIGN:      2014
 * DESCRIPTION: Zynq Signalhandling
 * ======================================================================== */

/**
 * \file     SVSCamCalibSM.h
 * \brief    calibration handling
 * \author   Prasad Pachpande
 * \version  $Revision: 1.0 $
 * \details  h file public description of module
 */

#ifndef SVS_CAMCALIB_SM_H_
#define SVS_CAMCALIB_SM_H_

#ifdef __cplusplus
extern "C" {
#endif
/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */

#include "ME_CalibSVS.h"
#include "ProxiMgrIpcDataTypes.h"

typedef enum Std_E_ReturnType_e
{
  Std_E_RetType_Successful = 0u,
  Std_E_RetType_Failed
}Std_E_ReturnType_t;

typedef enum aSigConverter_E_MIRROR_STAT_e
{
  MirrorDrivingPosition = 0x0,
  MirrorPendingPosition = 0x1,
  MirrorParkingPosition = 0x2
} aSigConverter_E_MIRROR_STAT_t;

typedef struct aSigConverterTypes_S_Rx_ZynqMRelatedData
{
  TeSVS_e_DoorStsCamCalib  LeftFrontAJAR_e;      /* Left Front Door Open/Closed  BCM_0x343 */
  TeSVS_e_DoorStsCamCalib  RightFrontAJAR_e;     /* Right Front Door Open/Closed BCM_0x343 */
  TeSVS_e_DoorStsCamCalib  LeftRearAJAR_e;       /* Left Rear Door Open/Closed   BCM_0x343 */
  TeSVS_e_DoorStsCamCalib  RightRearAJAR_e;      /* Right Rear Door Open/Closed  BCM_0x343 */

  TeSVS_e_DoorStsCamCalib  tlgAJAR_e;            /* Trunkliftgate Open/Closed    BCM_0x343*/
  TeSVS_e_DoorStsCamCalib  innrtlgAJAR_e;        /* Inner Tailgate Open/Closed */
  TeSVS_e_DoorStsCamCalib  hoodAJAR_e;           /* Hood Open/Closed             BCM_0x343*/

  float32                  steeringAngle_f32;    /* Steering Angle - Do not confuse this with SteeringWheelAngle!  EPS_0x1C2*/

  uint8                    mirrorLefStatus_u8;   /* Left mirror folded/unfolded - TODO -> No Signal in Database */
  uint8                    mirrorRigStatus_u8;   /* Right mirror folded/unfolded - TODO -> No Signal in Database */

  uint8                    dayNightStatus_u8;    /* for future use */
  float32                  vehicleLevel_f32;     /* Level of Vehicle */
  uint16                   vehSpeed_u16;         /* km/h */
  float32                  vehSpeed_f32;         /* ESP_0x318 (in km/h) */
  TeSVS_e_GearPosCamCalib  gearStatus_e;         /* VCU_0x214 */
  TeSVS_e_PowerModeCamCalib ignitionStatus_e;     /* BCM_0x333 */

  ME_ProxiToMPU1_0_Def_t   ProxiData_s;           /* Proxi Data*/
  TeSVS_e_ASCMSts          ASCMStatus_e;          /* Air Suspension value */
} aSigConverterTypes_S_Rx_ZynqMRelatedData_t;

typedef struct aZynqM_S_OC_Conditions_OEM_s
{
  BOOL LeftFrontDoor_b;
  BOOL RightFrontDoor_b;
  BOOL LeftRearDoor_b;
  BOOL RightRearDoor_b;

  BOOL Hood_b;
  BOOL Tailgate_b;
  BOOL InnerTailgate_b;

  BOOL LeftMirror_b;
  BOOL RightMirror_b;

  BOOL SteeringAngle_b;
  BOOL LVDS_Cam_shorted_b;

  BOOL VehicleLevelAS_b;
} aZynqM_S_OC_Conditions_OEM_t;

extern void aZynqM_F_Task10msec_v(void);
extern void aZynqM_f_InternalInit_v(void);

extern boolean aZynqM_F_EOL_IsRequested_b(void);
extern boolean aZynqM_EOL_F_IsAlgoSelected_b(void);
extern boolean aZynqM_F_GetEOLStatusCurrentCycle(void);
extern boolean aZynqM_F_EOL_StartConditionsCorrect_b(void);
extern boolean aZynqM_F_EOL_Request_b(boolean on_off, aZynqM_S_CamMask_t CamMask);

extern ME_Hydra3defs_E_CalibStatus_t aZynqM_F_EOL_GetResultCam_e(ME_Hydra3defs_E_CameraID_t camID);
extern ME_Hydra3defs_E_EOLErrorCode_t aZynqM_F_EOL_GetErrorCodeCam_e(ME_Hydra3defs_E_CameraID_t camID);
extern ME_Hydra3defs_E_CameraID_t aZynqM_F_EOL_GetCurrentCam_e(void);
extern ME_Hydra3defs_S_EOLTargetData_t aZynqM_F_EOL_GetTargetDataCam_e(ME_Hydra3defs_E_CameraID_t camID);

extern aZynqM_S_EOL_Conditions_t aZynqM_F_EOL_GetStartConditionDetails_s(void);
extern aZynqM_E_ModuleState_EOL_STM_t aZynqM_F_ModuleState_EOL_STM_GetModuleState_e(void);

extern ME_Hydra3defs_E_EOLErrorCode_t aZynqM_F_EOL_GetErrorCode_e(void);
extern ME_Hydra3defs_E_EOLAlgoState_t aZynqM_F_EOL_GetAlgoState_e(void);

extern boolean aZynqM_F_SC_IsRequested_b(void);
extern boolean aZynqM_F_SC_IsHmiEnabled_b(void);
extern boolean aZynqM_SC_F_IsAlgoSelected_b(void);
extern boolean aZynqM_EOL_F_IsAlgoSelected_b(void);
extern boolean aZynqM_F_GetSCStatusCurrentCycle(void);
extern boolean aZynqM_F_SC_StartConditionsCorrect_b(void);
extern boolean aZynqM_F_SC_Request_b(boolean on_off, aZynqM_S_CamMask_t CamMask);

extern ME_Hydra3defs_E_CalibStatus_t aZynqM_F_SC_GetResultCam_e(ME_Hydra3defs_E_CameraID_t camID);
extern ME_Hydra3defs_E_OCErrorCode_t aZynqM_F_SC_GetErrorCodeCam_e(ME_Hydra3defs_E_CameraID_t camID);
extern ME_Hydra3defs_E_CameraID_t aZynqM_F_SC_GetCurrentCam_e(void);
extern aZynqM_S_SCConditions_t aZynqM_F_SC_GetStartConditionDetails_s(void);
extern aZynqM_E_ModuleState_SC_STM_t aZynqM_F_ModuleState_SC_STM_GetModuleState_e(void);

extern ME_Hydra3defs_E_CalibStatus_t aZynqM_F_OC_GetResultCam_e(ME_Hydra3defs_E_CameraID_t camID);
extern aZynqM_E_ModuleState_OC_STM_t aZynqM_F_ModuleState_OC_STM_GetModuleState_e(void);
extern ME_Hydra3defs_E_OCErrorCode_t aZynqM_F_OC_GetErrorCodeCam_e(ME_Hydra3defs_E_CameraID_t camID);
extern ME_Hydra3defs_E_CameraID_t aZynqM_F_OC_GetCurrentCam_e(void);
extern ME_Hydra3defs_E_OCAlgoState_t aZynqM_F_OC_GetAlgoState_e(void);
extern ME_Hydra3defs_E_OCErrorCode_t aZynqM_F_OC_GetErrorCode_e(void);
extern void aZynqM_F_OC_GetFeatures_v(uint32 *validFeatures, uint32 *ignoredFeatures, uint32 *invalidFeatures);
extern boolean aZynqM_OC_F_IsAlgoSelected_b(void);
extern boolean aZynqM_F_IsOcDataIPCReady_v(void);
#ifdef __cplusplus
} // closing brace for extern "C"
#endif

/* --------------------------------------------------------------------------------- */
#endif /* SVS_CAMCALIB_SM_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: aSigM_Zynq.h */
