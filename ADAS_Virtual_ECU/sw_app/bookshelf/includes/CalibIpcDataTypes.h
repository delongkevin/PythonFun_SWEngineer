#ifndef CalibIpcDataTypes_H_INCGUARD
#define CalibIpcDataTypes_H_INCGUARD

#include "Rte_Type.h"



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

typedef enum ME_Hydra3defs_E_CalibrationID2_s
{
  CalibrationID2_Zero,
  CalibrationID2_EOL,
  CalibrationID2_SC,
  CalibrationID2_OC,
  CalibrationID2_Current,
  CalibrationID2_Size_Enforcer = 0xFFFFFFFF
} ME_Hydra3defs_E_CalibrationID2_t;

typedef struct aZynqM_S_CamMask
{
  uint8 camFront;
  uint8 camLeft ;
  uint8 camRear ;
  uint8 camRight;
} aZynqM_S_CamMask_t;

/* 
 * mcu_1_0 to A72
 * (Voltage Manager to SVS Camera Calib State Machine)
 */
typedef struct ME_TbSVS_e_VtgMgrOutputToSVSCamCalibSM_s
{
  aZynqM_S_SCConditions_t IsVoltageInRange_b;
} TbSVS_e_VtgMgrOutputToSVSCamCalibSM_t;

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
  boolean                             isRoutineRequested;
  uint8                               targetID;
  uint16                              targetDistance;
  aZynqM_S_CamMask_t                  cameraMask;
  ME_Hydra3defs_E_CalibrationID2_t    calibType;
  ME_Hydra3defs_E_EraseCalibNVMData_t EraseCalibNVMData;
} TbSVS_e_DiagMgrOutputToSVSCamCalibSM_t;



typedef enum
{
	TeTRSC_e_Unknown = 0,
	TeTRSC_e_Clear = 1,
	TeTRSC_e_TrailerCalibMemClearReq_Dummy = 0xFFFFFFFF
} TeTRSC_e_TrailerCalibMemClearReq;

typedef struct TRSC_CalibrationClear_s
{
	TeTRSC_e_TrailerCalibMemClearReq TRSC_Calib_Clear_Req;
}TRSC_CalibrationClear_t;

#endif
