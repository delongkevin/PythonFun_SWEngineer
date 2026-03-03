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
 *             File:  Rte_SWC_DIDMgr.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_DIDMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_DIDMGR_H
# define RTE_SWC_DIDMGR_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_SWC_DIDMgr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint32, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpECUTimeSinceIGON_ECUTimeStamp_IGON;
extern VAR(uint32, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpECUTimeStamp_ECUTimeStamp;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpFailsafeAction_FailSafe_State;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpFailsafeDebug_Debugflag;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpGearPosition_GearValue;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpGearPosition_ShortTermAdjActiveFlag_b;
extern VAR(uint32, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpIgOnCounter_IGCounter;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpPerformanceStatsEnable_RunTimeStatsEnable;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpPerformanceStatsEnable_StackUsageStatsEnable;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpResetNvmFlag_V_ResetNvmFlag_b;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpSleepProcessState_status;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_DIDMgr_Pp_PlantOdoData_PlantOdoData;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpCalibRoutineTrigger_routine_b;
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpGetFirstDTCStatus_DeFirstDTCStatus;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpPlantMode_Status;
extern VAR(EPBSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_EPBSts;
extern VAR(IgnitionOnCounter, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_IgnitionOnCounter;
extern VAR(OperationalModeSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_OperationalModeSts;
extern VAR(RemStActvSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_RemStActvSts;
extern VAR(TotalOdometer, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer;
extern VAR(TurnIndicatorSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TurnIndicatorSts;
extern VAR(CurrentFailSts_FD02_PAM, RTE_VAR_INIT) Rte_SWC_VCANTx_PpToSwcFD02Tx_CurrentFailSts_FD02_PAM;
extern VAR(GenericFailSts_FD02_PAM, RTE_VAR_INIT) Rte_SWC_VCANTx_PpToSwcFD02Tx_GenericFailSts_FD02_PAM;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpVINData_VINLockStatus;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpVINData_VINOdoCounter;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16;
extern VAR(uint16, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeState2RSTReason_FaultEnum_u16;
extern VAR(APARequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts;
extern VAR(ASCM_Stat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat;
extern VAR(Brk_Stat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Brk_Stat;
extern VAR(CM_TCH_STAT, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT;
extern VAR(CM_TCH_X_COORD, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD;
extern VAR(CM_TCH_Y_COORD, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD;
extern VAR(CameraDisplaySts2, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2;
extern VAR(CmdIgnSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts;
extern VAR(DriverDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts;
extern VAR(EngineSts_W, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EngineSts_W;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature;
extern VAR(Fwrd_Cam_Guidelines, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines;
extern VAR(GearEngaged, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged;
extern VAR(LHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts;
extern VAR(LanguageSelection, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LanguageSelection;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngle;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsSpeed;
extern VAR(PAMRequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PAMRequestSts;
extern VAR(PamChimeVolumeFront, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeFront;
extern VAR(PamChimeVolumeRear, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeRear;
extern VAR(PsngrDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts;
extern VAR(RHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts;
extern VAR(RHatchSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts;
extern VAR(Rear_Brk_Asst, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Rear_Brk_Asst;
extern VAR(SVC_Guidelines, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_SVC_Guidelines;
extern VAR(ShiftLeverPosition, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition;
extern VAR(TCASERANGESTATUS, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TCASERANGESTATUS;
extern VAR(TGW_CAMERA_DISP_STAT, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT;
extern VAR(TargetGear, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TargetGear;
extern VAR(TrailerConnectionSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts;
extern VAR(VIN_MSG, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig;
extern VAR(Alert_CHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHF;
extern VAR(Alert_CHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHR;
extern VAR(Alert_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHF;
extern VAR(Alert_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHR;
extern VAR(Alert_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHF;
extern VAR(Alert_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHR;
extern VAR(ChimeActivation_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHF;
extern VAR(ChimeActivation_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHR;
extern VAR(ChimeActivation_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHF;
extern VAR(ChimeActivation_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHR;
extern VAR(DisplayView2, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2;
extern VAR(FrontSensorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FrontSensorSts;
extern VAR(Graphic_CHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHF;
extern VAR(Graphic_CHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHR;
extern VAR(Graphic_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHF;
extern VAR(Graphic_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHR;
extern VAR(Graphic_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHF;
extern VAR(Graphic_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHR;
extern VAR(HMICode, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_HMICode;
extern VAR(ImageDefeatRQSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ImageDefeatRQSts;
extern VAR(PAMSystemFault, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAMSystemFault;
extern VAR(PAM_CHIME_REP_RATESts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts;
extern VAR(PAM_CHIME_TYPE, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE;
extern VAR(PAM_LedControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_LedControlSts;
extern VAR(PAM_Off_Status, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status;
extern VAR(PAM_PopUpRqst, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_PopUpRqst;
extern VAR(PAM_Volume, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Volume;
extern VAR(RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts;
extern VAR(RR_PAM_Dist, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Dist;
extern VAR(RR_PAM_StopControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts;
extern VAR(RearSensorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RearSensorSts;
extern VAR(SPMControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMControlSts;
extern VAR(SPMFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMFailSts;
extern VAR(SPMSystemFault, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMSystemFault;
extern VAR(SPM_LedControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_LedControlSts;
extern VAR(SPM_Screen_Rqst, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_Screen_Rqst;
extern VAR(FD14_EPS_HandsOnRecognition, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition;
extern VAR(FD14_ESS_ENG_ST_W, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed;
extern VAR(FD14_LHF_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter;
extern VAR(FD14_LHF_Spin, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_Spin;
extern VAR(FD14_LHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed;
extern VAR(FD14_LHR_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter;
extern VAR(FD14_LHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts;
extern VAR(FD14_LatAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM;
extern VAR(FD14_LongAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM;
extern VAR(FD14_LwsAngle, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle;
extern VAR(FD14_LwsAngleType, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngleType;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsSpeed;
extern VAR(FD14_PAM_Brk_Rq_RspSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts;
extern VAR(FD14_PdlPosActual, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PdlPosActual;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed;
extern VAR(FD14_RHF_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter;
extern VAR(FD14_RHF_Spin, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_Spin;
extern VAR(FD14_RHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed;
extern VAR(FD14_RHR_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter;
extern VAR(FD14_RHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts;
extern VAR(FD14_SPM_Lat_Ctrl_ResponseSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2;
extern VAR(FD14_VehicleStandStillSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts;
extern VAR(FD14_YawRateFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRate_BSM;
extern VAR(FD14_ManoeuvrePhase, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase;
extern VAR(FD14_RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts;
extern VAR(FD14_RR_PAM_Dist, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist;
extern VAR(FD14_SPM_Lat_Ctrl_RequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts;
extern VAR(FD14_TorqueOverlaySteeringReq_SPM, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_InvalidValueFlag;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_MissingMessageFlag;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpVariantData_Variant;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpECUTimeSinceIGON_ECUTimeStamp_IGON (0U)
#  define Rte_InitValue_PpECUTimeStamp_ECUTimeStamp (0U)
#  define Rte_InitValue_PpFailsafeAction_FailSafe_State (0U)
#  define Rte_InitValue_PpFailsafeDebug_Debugflag (0U)
#  define Rte_InitValue_PpGearPosition_GearValue (0U)
#  define Rte_InitValue_PpGearPosition_ShortTermAdjActiveFlag_b (FALSE)
#  define Rte_InitValue_PpIgOnCounter_IGCounter (0U)
#  define Rte_InitValue_PpPerformanceStatsEnable_RunTimeStatsEnable (FALSE)
#  define Rte_InitValue_PpResetNvmFlag_V_ResetNvmFlag_b (FALSE)
#  define Rte_InitValue_PpSleepProcessState_status (0U)
#  define Rte_InitValue_Pp_PlantOdoData_PlantOdoData (0U)
#  define Rte_InitValue_RpCalibRoutineTrigger_routine_b (FALSE)
#  define Rte_InitValue_RpSafeState2RSTReason_FaultEnum_u16 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Altitude_RMSE_C2 (128U)
#  define Rte_InitValue_RpToSwcFD02Rx_BSM_THA_Brk_Resp (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Battery_Volt_1 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD01_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD01_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD02_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD02_BSM2 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD02_CADM2 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD02_EPS (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD02_ORC (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD02_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD03_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD03_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD04_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD08_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentCanNMState_FD11_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD01_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD01_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD02_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD02_BSM2 (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD02_CADM2 (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD02_EPS (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD02_ORC (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD02_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD03_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD03_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD04_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD08_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_CurrentFailSts_FD11_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD01_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD01_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD02_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD02_BSM2 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD02_CADM2 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD02_EPS (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD02_ORC (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD02_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD03_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD03_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD04_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD08_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DES_FD11_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_DeltaTimestamp_IMUdata (255U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_01 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_02 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_03 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_04 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_05 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_06 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_07 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_08 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_09 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_10 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_Digit_11 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD01_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD01_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD02_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD02_BSM2 (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD02_CADM2 (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD02_EPS (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD02_ORC (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD02_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD03_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD03_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD04_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD08_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EOL_FD11_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_EPBSts (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD01_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD01_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD02_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD02_BSM2 (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD02_CADM2 (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD02_EPS (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD02_ORC (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD02_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD03_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD03_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD04_BCM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD08_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_GenericFailSts_FD11_SGW (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_Heading_Angle_C2 (65535U)
#  define Rte_InitValue_RpToSwcFD02Rx_IgnitionOnCounter (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_LHFWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_LHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_LHF_Spin (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_LHRWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_LHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_LHR_Spin (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_LatAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpToSwcFD02Rx_LatAcceleration_C2 (4095U)
#  define Rte_InitValue_RpToSwcFD02Rx_Latitude_RMSE_C2 (128U)
#  define Rte_InitValue_RpToSwcFD02Rx_LongAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpToSwcFD02Rx_LongAcceleration_C2 (4095U)
#  define Rte_InitValue_RpToSwcFD02Rx_Longitude_RMSE_C2 (128U)
#  define Rte_InitValue_RpToSwcFD02Rx_OperationalModeSts (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PitchRate_C2 (4095U)
#  define Rte_InitValue_RpToSwcFD02Rx_Pitch_RMSE_C2 (128U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD01_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD01_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD02_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD02_BSM2 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD02_CADM2 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD02_EPS (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD02_ORC (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD02_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD03_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD03_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD04_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD08_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_PreviousCanNMState_FD11_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_REF_VEH_SPEED (1023U)
#  define Rte_InitValue_RpToSwcFD02Rx_RHFWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_RHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_RHF_Spin (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_RHRWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_RHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_RHR_Spin (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_RemStActvSts (FALSE)
#  define Rte_InitValue_RpToSwcFD02Rx_RollRate_C2 (4095U)
#  define Rte_InitValue_RpToSwcFD02Rx_Roll_RMSE_C2 (128U)
#  define Rte_InitValue_RpToSwcFD02Rx_SBR1RowDriverSeatSts (3U)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD01_BCM (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD01_SGW (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD02_BCM (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD02_BSM2 (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD02_CADM2 (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD02_EPS (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD02_ORC (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD02_SGW (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD02_TRLR_REV (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD03_BCM (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD03_SGW (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD04_BCM (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD08_SGW (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_StayActiveSource_FD11_SGW (0ULL)
#  define Rte_InitValue_RpToSwcFD02Rx_TRSC_CenterBtn_Sts (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_TRSC_EnableBtn_Sts (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_TRSC_RawKnob (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_TotalOdometer (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_TurnIndicatorSts (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_VehicleStandStillSts (1U)
#  define Rte_InitValue_RpToSwcFD02Rx_VerticalAcceleration_C2 (4095U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD01_ADCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD01_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD01_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD02_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD02_BSM2 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD02_CADM2 (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD02_EPS (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD02_ORC (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD02_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD03_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD03_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD04_BCM (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD08_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_WakeupSource_FD11_SGW (0U)
#  define Rte_InitValue_RpToSwcFD02Rx_YawRate_C2 (4095U)
#  define Rte_InitValue_RpToSwcFD02Rx_YawRate_RMSE_C2 (128U)
#  define Rte_InitValue_RpToSwcFD02Tx_CurrentCanNMState_FD02_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_CurrentFailSts_FD02_PAM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Tx_DES_FD02_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_01_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_02_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_03_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_04_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_05_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_06_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_07_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_08_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_09_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_10_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Digit_11_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_EOL_FD02_PAM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Tx_GenericFailSts_FD02_PAM (FALSE)
#  define Rte_InitValue_RpToSwcFD02Tx_PreviousCanNMState_FD02_PAM (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_THA_EPB_Req (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_THA_STAT (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_THA_SpeedLimit_Req (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_THA_Speed_Limit (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_THA_SteeringDamping (100U)
#  define Rte_InitValue_RpToSwcFD02Tx_THA_SteeringTorqueInfo (1024U)
#  define Rte_InitValue_RpToSwcFD02Tx_THA_SteeringTorqueReq (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_TRSCMoreCamRQSts (FALSE)
#  define Rte_InitValue_RpToSwcFD02Tx_TRSC_PopupDisp_Info (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_TRSC_PopupDisp_Info2 (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_TRSC_STAT (1U)
#  define Rte_InitValue_RpToSwcFD02Tx_TRSC_SpeedLimit_Req (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_TRSC_SteeringDamping (128U)
#  define Rte_InitValue_RpToSwcFD02Tx_TRSC_SteeringTorqueInfo (1024U)
#  define Rte_InitValue_RpToSwcFD02Tx_TRSC_SteeringTorqueReq (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_TRSC_VehicleStop_Req (3U)
#  define Rte_InitValue_RpToSwcFD02Tx_Trailer_Angle (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Trailer_Angle_Sign (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_Trailer_Calibration (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_TrlrHitchLight_Cntrl (0U)
#  define Rte_InitValue_RpToSwcFD02Tx_WakeupSource_FD02_PAM (0U)
#  define Rte_InitValue_RpToSwcFD14Rx_FD14_Accel_Pedal_Override (FALSE)
#  define Rte_InitValue_RpToSwcFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM (0U)
#  define Rte_InitValue_RpToSwcFD14Rx_FD14_PPPA_TrqEnblRq_Allowed (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_APARequestSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Active_Park_Mode (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Active_Park_Prox_Chime (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Backup_Cam_Delay (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Brk_Stat (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_CmdIgnSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_DriverDoorSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_DynamicGrid (TRUE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_ExternalTemperature (170U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_FT_PAMRequestSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_GearEngaged (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_HAS_Status_C2 (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LHRDoorSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LanguageSelection (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LatAcceleration_BSM (4095U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LongAcceleration_BSM (4095U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LwsAngle (7200U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LwsAngleType (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_LwsSpeed (2000U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_MRM_STATUS_C2 (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_PAMRequestSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_PamChimeVolumeFront (1U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_PamChimeVolumeRear (1U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_PsngrDoorSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_RHRDoorSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_RHatchSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_Rear_Brk_Asst (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_SVC_Guidelines (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_ShiftLeverPosition (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TCASERANGESTATUS (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TRANS_ADAS_Inhibit (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TargetGear (15U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TrailerConnectionSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_TransmissionSailingSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_VehicleSpeedVSOSig (0U)
#  define Rte_InitValue_RpToSwcSafeFD02Rx_YawRate_BSM (4095U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_ACC_Systemsts (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_BSM_THA_Brk_Resp (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_BrkPdl_Stat (3U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_BrkTrq (10922U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_BrkTrq_Driver (10922U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_Brk_Stat (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_EPBSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_ExternalBrkRequestsDisabled (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_HAS_Status (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHFWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHF_Spin (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHRWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHR_Spin (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LatAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM (4095U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LongAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM (4095U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LwsAngle (7200U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LwsAngleType (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_LwsSpeed (2000U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_ParkingGearShiftReq_BSM (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_ParkingInterventionSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_REF_VEH_SPEED (1023U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHFWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHF_Spin (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHRWheelSpeed (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHR_Spin (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_Slope (100U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_Steering_Column_Torque (1024U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2 (0U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_VehicleStandStillSts (1U)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM (FALSE)
#  define Rte_InitValue_RpToSwcSafeFD14Rx_FD14_YawRate_BSM (4095U)
#  define Rte_InitValue_RpVIN_MessageFault_VIN_InvalidValueFlag (FALSE)
#  define Rte_InitValue_RpVIN_MessageFault_VIN_MissingMessageFlag (FALSE)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpCalDataProviderNvmData_CalData_mcu1_0(P2VAR(CalDataProvider_MCU_1_0_Def, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpCamCsData_CAM_CS_Curr_Monitor_t(P2VAR(CAM_CS_Curr_Monitor_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpCamEepromData_Svs_CamEepromDataArray_t(P2VAR(Svs_CamEepromDataArray_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpCamSerENStat_Cam_and_Ser_EN_Status_t(P2VAR(Cam_and_Ser_EN_Status_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpCpuLoadMcu2_0_CpuLoadMcu2_0_t(P2VAR(CpuLoadMcu2_0_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpCpuLoadMcu2_1_CpuLoadMcu2_1_t(P2VAR(CpuLoadMcu2_1_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpErrors_B_Errors_B(P2VAR(uint32, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpErrors_B_Errors_B(P2VAR(ErrorListArr_B, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpErrors_QM_Errors_QM(P2VAR(uint32, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpErrors_QM_Errors_QM(P2VAR(ErrorListArr_QM, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(P2VAR(TbTHASmVc_FeatureOutputs_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpJobFPAData_IJobFPAOutput_t(P2VAR(IJobFPAOutput_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpJobPLDData_IJobPLDOutput_t(P2VAR(IJobPLDOutput_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpJobTHADetOutput_JobTHADetOutput_t(P2VAR(JobTHADetOutput_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpMPUFaultStatus_Sts(P2VAR(uint8, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpMPUFaultStatus_Sts(P2VAR(MpuFltSts, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t(P2VAR(TbSVS_e_SVSOutputToNVMCamCalibSM_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpPMICFaultstatus_Sts(P2VAR(uint8, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpPMICFaultstatus_Sts(P2VAR(PmicStatus, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpPointDistOpBuff_US_S_PointDistOutputBuff_t(P2VAR(US_S_PointDistOutputBuff_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpPreviousCamData_Data(P2VAR(CDP_TbSVS_S_SVSCamCurrentCalibData_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpProxiConfigData_ProxiData(P2VAR(ME_Hydra2defs_S_CodingTableExt_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpProxiErrorData_Error(P2VAR(ME_Hydra2defs_S_PROXI_error_Data_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpRPAWarnOut_TbAP_RPAWarnOut_t(P2VAR(TbAP_RPAWarnOut_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t(P2VAR(RunTimeStats_MCU2_0_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t(P2VAR(RunTimeStats_MCU2_1_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t(P2VAR(RunTimeStats_MPU1_0_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSDLFaultstatus_Sts(P2VAR(uint8, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSDLFaultstatus_Sts(P2VAR(Status, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSMDAInternal_TbAP_SMDAInternalOut_t(P2VAR(TbAP_SMDAInternalOut_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamEOLCalibDataToNVM_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamOCCalibDataToNVM_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamSCCalibDataToNVM_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(P2VAR(TbSVS_e_SVSOutputToDiagMgrCamCalib_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpScreenRequest_ScreenRequest_t(P2VAR(ScreenRequest_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSnrDirEcho_US_S_SnrDirEcho_t(P2VAR(US_S_SnrDirEcho_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpStackUsage_MCU2_0_StackUsage_MCU2_0_t(P2VAR(StackUsage_MCU2_0_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpStackUsage_MCU2_1_StackUsage_MCU2_1_t(P2VAR(StackUsage_MCU2_1_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSvsToTHA_SvsToTHA_t(P2VAR(SvsToTHA_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpTRSC_ME_VehOut_TRSC_t(P2VAR(ME_VehOut_TRSC_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t(P2VAR(TbTHASmVc_DiagMgr_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_VIN_DATA(P2VAR(uint8, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_VIN_DATA(P2VAR(VIN_DATA, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpTrailerDetectOP_TrailerDetection_Output_DID_t(P2VAR(TrailerDetection_Output_DID_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpTrscToDiag_TRSCtoDiagMgr_t(P2VAR(TRSCtoDiagMgr_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpUSSBlockageBit_US_S_BlockageBit_t(P2VAR(US_S_BlockageBit_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpUSSConstantData_US_S_USSConstantData_t(P2VAR(US_S_USSConstantData_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpUSSErrorDiagData_US_S_USSErrorDiagData_t(P2VAR(US_S_USSErrorDiagData_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpUSSPeriodDiagData_US_S_USSPeriodDiagData_t(P2VAR(US_S_USSPeriodDiagData_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpUssPowerData_UssPower(P2VAR(UssPowerSense, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpUssTunData_UssTunningData_mcu2_1_t(P2VAR(UssTunningData_mcu2_1_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpVCState_TbAP_VCStateOut_t(P2VAR(TbAP_VCStateOut_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpVINData_VINCurrentData(P2VAR(uint8, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpVINData_VINCurrentData(P2VAR(VINlData_Arr, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpVINData_VINOriginalData(P2VAR(uint8, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpVINData_VINOriginalData(P2VAR(VINlData_Arr, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpWDGFaultStatus_Sts(P2VAR(uint8, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_RpWDGFaultStatus_Sts(P2VAR(WdgFltSts, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_Rp_DLDOutput_JobDLDOutput_t(P2VAR(JobDLDOutput_t, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DIDMgr_Rp_SafeState_SR_SafeStateOp(P2VAR(SafeStateOpDef, AUTOMATIC, RTE_SWC_DIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RpCalDataProviderNvmData_CalData_mcu1_0 Rte_Read_SWC_DIDMgr_RpCalDataProviderNvmData_CalData_mcu1_0
#  define Rte_Read_RpCalibRoutineTrigger_routine_b Rte_Read_SWC_DIDMgr_RpCalibRoutineTrigger_routine_b
#  define Rte_Read_SWC_DIDMgr_RpCalibRoutineTrigger_routine_b(data) (*(data) = Rte_SWC_RIDMgr_PpCalibRoutineTrigger_routine_b, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpCamCsData_CAM_CS_Curr_Monitor_t Rte_Read_SWC_DIDMgr_RpCamCsData_CAM_CS_Curr_Monitor_t
#  define Rte_Read_RpCamEepromData_Svs_CamEepromDataArray_t Rte_Read_SWC_DIDMgr_RpCamEepromData_Svs_CamEepromDataArray_t
#  define Rte_Read_RpCamSerENStat_Cam_and_Ser_EN_Status_t Rte_Read_SWC_DIDMgr_RpCamSerENStat_Cam_and_Ser_EN_Status_t
#  define Rte_Read_RpCpuLoadMcu2_0_CpuLoadMcu2_0_t Rte_Read_SWC_DIDMgr_RpCpuLoadMcu2_0_CpuLoadMcu2_0_t
#  define Rte_Read_RpCpuLoadMcu2_1_CpuLoadMcu2_1_t Rte_Read_SWC_DIDMgr_RpCpuLoadMcu2_1_CpuLoadMcu2_1_t
#  define Rte_Read_RpErrors_B_Errors_B Rte_Read_SWC_DIDMgr_RpErrors_B_Errors_B
#  define Rte_Read_RpErrors_QM_Errors_QM Rte_Read_SWC_DIDMgr_RpErrors_QM_Errors_QM
#  define Rte_Read_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t Rte_Read_SWC_DIDMgr_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t
#  define Rte_Read_RpGetFirstDTCStatus_DeFirstDTCStatus Rte_Read_SWC_DIDMgr_RpGetFirstDTCStatus_DeFirstDTCStatus
#  define Rte_Read_SWC_DIDMgr_RpGetFirstDTCStatus_DeFirstDTCStatus(data) (*(data) = Rte_CDD_GenericBswM_PpGetFirstDTCStatus_DeFirstDTCStatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpJobFPAData_IJobFPAOutput_t Rte_Read_SWC_DIDMgr_RpJobFPAData_IJobFPAOutput_t
#  define Rte_Read_RpJobPLDData_IJobPLDOutput_t Rte_Read_SWC_DIDMgr_RpJobPLDData_IJobPLDOutput_t
#  define Rte_Read_RpJobTHADetOutput_JobTHADetOutput_t Rte_Read_SWC_DIDMgr_RpJobTHADetOutput_JobTHADetOutput_t
#  define Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t Rte_Read_SWC_DIDMgr_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t
#  define Rte_Read_RpMPUFaultStatus_Sts Rte_Read_SWC_DIDMgr_RpMPUFaultStatus_Sts
#  define Rte_Read_RpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t Rte_Read_SWC_DIDMgr_RpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t
#  define Rte_Read_RpPAStateOut_TbAP_PAStateOut_t Rte_Read_SWC_DIDMgr_RpPAStateOut_TbAP_PAStateOut_t
#  define Rte_Read_RpPMICFaultstatus_Sts Rte_Read_SWC_DIDMgr_RpPMICFaultstatus_Sts
#  define Rte_Read_RpPlantMode_Status Rte_Read_SWC_DIDMgr_RpPlantMode_Status
#  define Rte_Read_SWC_DIDMgr_RpPlantMode_Status(data) (*(data) = Rte_SWC_RIDMgr_PpPlantMode_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpPointDistOpBuff_US_S_PointDistOutputBuff_t Rte_Read_SWC_DIDMgr_RpPointDistOpBuff_US_S_PointDistOutputBuff_t
#  define Rte_Read_RpPreviousCamData_Data Rte_Read_SWC_DIDMgr_RpPreviousCamData_Data
#  define Rte_Read_RpProxiConfigData_ProxiData Rte_Read_SWC_DIDMgr_RpProxiConfigData_ProxiData
#  define Rte_Read_RpProxiErrorData_Error Rte_Read_SWC_DIDMgr_RpProxiErrorData_Error
#  define Rte_Read_RpProxiToSWC_SurroundViewCam_u8 Rte_Read_SWC_DIDMgr_RpProxiToSWC_SurroundViewCam_u8
#  define Rte_Read_SWC_DIDMgr_RpProxiToSWC_SurroundViewCam_u8(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_TyreSz_u16 Rte_Read_SWC_DIDMgr_RpProxiToSWC_TyreSz_u16
#  define Rte_Read_SWC_DIDMgr_RpProxiToSWC_TyreSz_u16(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpRPAWarnOut_TbAP_RPAWarnOut_t Rte_Read_SWC_DIDMgr_RpRPAWarnOut_TbAP_RPAWarnOut_t
#  define Rte_Read_RpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t Rte_Read_SWC_DIDMgr_RpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t
#  define Rte_Read_RpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t Rte_Read_SWC_DIDMgr_RpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t
#  define Rte_Read_RpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t Rte_Read_SWC_DIDMgr_RpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t
#  define Rte_Read_RpSDLFaultstatus_Sts Rte_Read_SWC_DIDMgr_RpSDLFaultstatus_Sts
#  define Rte_Read_RpSMDAInternal_TbAP_SMDAInternalOut_t Rte_Read_SWC_DIDMgr_RpSMDAInternal_TbAP_SMDAInternalOut_t
#  define Rte_Read_RpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t Rte_Read_SWC_DIDMgr_RpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t
#  define Rte_Read_RpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t Rte_Read_SWC_DIDMgr_RpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t
#  define Rte_Read_RpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t Rte_Read_SWC_DIDMgr_RpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t
#  define Rte_Read_RpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t Rte_Read_SWC_DIDMgr_RpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t
#  define Rte_Read_RpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t Rte_Read_SWC_DIDMgr_RpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t
#  define Rte_Read_RpSafeState2RSTReason_FaultEnum_u16 Rte_Read_SWC_DIDMgr_RpSafeState2RSTReason_FaultEnum_u16
#  define Rte_Read_SWC_DIDMgr_RpSafeState2RSTReason_FaultEnum_u16(data) (*(data) = Rte_Safety_Guard_PpSafeState2RSTReason_FaultEnum_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpScreenRequest_ScreenRequest_t Rte_Read_SWC_DIDMgr_RpScreenRequest_ScreenRequest_t
#  define Rte_Read_RpSnrDirEcho_US_S_SnrDirEcho_t Rte_Read_SWC_DIDMgr_RpSnrDirEcho_US_S_SnrDirEcho_t
#  define Rte_Read_RpStackUsage_MCU2_0_StackUsage_MCU2_0_t Rte_Read_SWC_DIDMgr_RpStackUsage_MCU2_0_StackUsage_MCU2_0_t
#  define Rte_Read_RpStackUsage_MCU2_1_StackUsage_MCU2_1_t Rte_Read_SWC_DIDMgr_RpStackUsage_MCU2_1_StackUsage_MCU2_1_t
#  define Rte_Read_RpSvsToTHA_SvsToTHA_t Rte_Read_SWC_DIDMgr_RpSvsToTHA_SvsToTHA_t
#  define Rte_Read_RpSvsToVCAN_SvsToVCAN_t Rte_Read_SWC_DIDMgr_RpSvsToVCAN_SvsToVCAN_t
#  define Rte_Read_RpTRSC_ME_VehOut_TRSC_t Rte_Read_SWC_DIDMgr_RpTRSC_ME_VehOut_TRSC_t
#  define Rte_Read_RpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t Rte_Read_SWC_DIDMgr_RpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t
#  define Rte_Read_RpToSwcFD02Rx_EPBSts Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_EPBSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_EPBSts(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_EPBSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_IgnitionOnCounter Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_IgnitionOnCounter
#  define Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_IgnitionOnCounter(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_IgnitionOnCounter, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_OperationalModeSts Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_OperationalModeSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_OperationalModeSts(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_OperationalModeSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_RemStActvSts Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_RemStActvSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_RemStActvSts(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_RemStActvSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_TotalOdometer Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_TotalOdometer
#  define Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_TotalOdometer(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_TurnIndicatorSts Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_TurnIndicatorSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcFD02Rx_TurnIndicatorSts(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_TurnIndicatorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Tx_CurrentFailSts_FD02_PAM Rte_Read_SWC_DIDMgr_RpToSwcFD02Tx_CurrentFailSts_FD02_PAM
#  define Rte_Read_SWC_DIDMgr_RpToSwcFD02Tx_CurrentFailSts_FD02_PAM(data) (*(data) = Rte_SWC_VCANTx_PpToSwcFD02Tx_CurrentFailSts_FD02_PAM, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Tx_GenericFailSts_FD02_PAM Rte_Read_SWC_DIDMgr_RpToSwcFD02Tx_GenericFailSts_FD02_PAM
#  define Rte_Read_SWC_DIDMgr_RpToSwcFD02Tx_GenericFailSts_FD02_PAM(data) (*(data) = Rte_SWC_VCANTx_PpToSwcFD02Tx_GenericFailSts_FD02_PAM, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_APARequestSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_APARequestSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_APARequestSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_ASCM_Stat Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_ASCM_Stat
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_ASCM_Stat(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_Brk_Stat Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_Brk_Stat
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_Brk_Stat(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Brk_Stat, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_STAT Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_CM_TCH_STAT
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_CM_TCH_STAT(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_X_COORD Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_CM_TCH_X_COORD
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_CM_TCH_X_COORD(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_Y_COORD Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_CM_TCH_Y_COORD
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_CM_TCH_Y_COORD(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CameraDisplaySts2 Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_CameraDisplaySts2
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_CameraDisplaySts2(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_CmdIgnSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_CmdIgnSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_DriverDoorSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_DriverDoorSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_DriverDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_EngineSts_W Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_EngineSts_W
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_EngineSts_W(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EngineSts_W, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_ExternalTemperature Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_ExternalTemperature
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_ExternalTemperature(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_GearEngaged Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_GearEngaged
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_GearEngaged(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_LHRDoorSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_LHRDoorSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_LHRDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_LanguageSelection Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_LanguageSelection
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_LanguageSelection(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LanguageSelection, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_LwsAngle Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_LwsAngle
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_LwsAngle(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngle, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_LwsSpeed Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_LwsSpeed
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_LwsSpeed(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsSpeed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_PAMRequestSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_PAMRequestSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_PAMRequestSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PAMRequestSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_PamChimeVolumeFront Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_PamChimeVolumeFront
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_PamChimeVolumeFront(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeFront, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_PamChimeVolumeRear Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_PamChimeVolumeRear
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_PamChimeVolumeRear(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeRear, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_PsngrDoorSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_PsngrDoorSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_PsngrDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_RHRDoorSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_RHRDoorSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_RHRDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_RHatchSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_RHatchSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_RHatchSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_Rear_Brk_Asst Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_Rear_Brk_Asst
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_Rear_Brk_Asst(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Rear_Brk_Asst, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_SVC_Guidelines Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_SVC_Guidelines
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_SVC_Guidelines(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_SVC_Guidelines, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_ShiftLeverPosition Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_ShiftLeverPosition
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_ShiftLeverPosition(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_TCASERANGESTATUS Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_TCASERANGESTATUS
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_TCASERANGESTATUS(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TCASERANGESTATUS, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_TargetGear Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_TargetGear
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_TargetGear(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TargetGear, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_TrailerConnectionSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_TrailerConnectionSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_TrailerConnectionSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_VIN_DATA Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_VIN_DATA
#  define Rte_Read_RpToSwcSafeFD02Rx_VIN_MSG Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_VIN_MSG
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_VIN_MSG(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_VehicleSpeedVSOSig Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_VehicleSpeedVSOSig
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Rx_VehicleSpeedVSOSig(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Alert_CHF Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_CHF
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_CHF(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHF, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Alert_CHR Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_CHR
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_CHR(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHR, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Alert_LHF Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_LHF
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_LHF(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHF, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Alert_LHR Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_LHR
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_LHR(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHR, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Alert_RHF Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_RHF
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_RHF(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHF, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Alert_RHR Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_RHR
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Alert_RHR(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHR, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_ChimeActivation_LHF Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_ChimeActivation_LHF
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_ChimeActivation_LHF(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHF, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_ChimeActivation_LHR Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_ChimeActivation_LHR
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_ChimeActivation_LHR(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHR, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_ChimeActivation_RHF Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_ChimeActivation_RHF
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_ChimeActivation_RHF(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHF, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_ChimeActivation_RHR Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_ChimeActivation_RHR
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_ChimeActivation_RHR(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHR, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_DisplayView2 Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_DisplayView2
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_DisplayView2(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_FrontSensorSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_FrontSensorSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_FrontSensorSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FrontSensorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Graphic_CHF Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_CHF
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_CHF(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHF, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Graphic_CHR Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_CHR
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_CHR(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHR, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Graphic_LHF Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_LHF
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_LHF(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHF, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Graphic_LHR Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_LHR
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_LHR(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHR, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Graphic_RHF Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_RHF
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_RHF(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHF, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_Graphic_RHR Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_RHR
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_Graphic_RHR(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHR, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_HMICode Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_HMICode
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_HMICode(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_HMICode, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_ImageDefeatRQSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_ImageDefeatRQSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_ImageDefeatRQSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ImageDefeatRQSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_PAMSystemFault Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAMSystemFault
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAMSystemFault(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAMSystemFault, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_PAM_CHIME_TYPE Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_CHIME_TYPE
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_CHIME_TYPE(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_PAM_LedControlSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_LedControlSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_LedControlSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_LedControlSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_PAM_Off_Status Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_Off_Status
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_Off_Status(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_PAM_PopUpRqst Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_PopUpRqst
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_PopUpRqst(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_PopUpRqst, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_PAM_Volume Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_Volume
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_PAM_Volume(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Volume, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_RR_PAM_Dist Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_RR_PAM_Dist
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_RR_PAM_Dist(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Dist, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_RR_PAM_StopControlSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_RR_PAM_StopControlSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_RR_PAM_StopControlSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_RearSensorSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_RearSensorSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_RearSensorSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RearSensorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_SPMControlSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_SPMControlSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_SPMControlSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMControlSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_SPMFailSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_SPMFailSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_SPMFailSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMFailSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_SPMSystemFault Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_SPMSystemFault
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_SPMSystemFault(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMSystemFault, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_SPM_LedControlSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_SPM_LedControlSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_SPM_LedControlSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_LedControlSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_SPM_Screen_Rqst Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_SPM_Screen_Rqst
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD02Tx_SPM_Screen_Rqst(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_Screen_Rqst, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LHFWheelSpeed Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHFWheelSpeed
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHFWheelSpeed(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LHF_Spin Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHF_Spin
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHF_Spin(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_Spin, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LHRWheelSpeed Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHRWheelSpeed
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHRWheelSpeed(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LwsAngle
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LwsAngle(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngleType Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LwsAngleType
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LwsAngleType(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngleType, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsSpeed Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LwsSpeed
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_LwsSpeed(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsSpeed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_PdlPosActual Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_PdlPosActual
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_PdlPosActual(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PdlPosActual, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_RHFWheelSpeed Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHFWheelSpeed
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHFWheelSpeed(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_RHF_Spin Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHF_Spin
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHF_Spin(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_Spin, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_RHRWheelSpeed Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHRWheelSpeed
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHRWheelSpeed(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_Steering_Column_Torque Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_Steering_Column_Torque
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_Steering_Column_Torque(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2 Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleStandStillSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_VehicleStandStillSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_VehicleStandStillSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_YawRate_BSM Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_YawRate_BSM
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Rx_FD14_YawRate_BSM(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRate_BSM, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Tx_FD14_ManoeuvrePhase Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Tx_FD14_ManoeuvrePhase
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Tx_FD14_ManoeuvrePhase(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Tx_FD14_RR_PAM_Dist Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Tx_FD14_RR_PAM_Dist
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Tx_FD14_RR_PAM_Dist(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM
#  define Rte_Read_SWC_DIDMgr_RpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpTrailerDetectOP_TrailerDetection_Output_DID_t Rte_Read_SWC_DIDMgr_RpTrailerDetectOP_TrailerDetection_Output_DID_t
#  define Rte_Read_RpTrscToDiag_TRSCtoDiagMgr_t Rte_Read_SWC_DIDMgr_RpTrscToDiag_TRSCtoDiagMgr_t
#  define Rte_Read_RpUSSBlockageBit_US_S_BlockageBit_t Rte_Read_SWC_DIDMgr_RpUSSBlockageBit_US_S_BlockageBit_t
#  define Rte_Read_RpUSSConstantData_US_S_USSConstantData_t Rte_Read_SWC_DIDMgr_RpUSSConstantData_US_S_USSConstantData_t
#  define Rte_Read_RpUSSErrorDiagData_US_S_USSErrorDiagData_t Rte_Read_SWC_DIDMgr_RpUSSErrorDiagData_US_S_USSErrorDiagData_t
#  define Rte_Read_RpUSSPeriodDiagData_US_S_USSPeriodDiagData_t Rte_Read_SWC_DIDMgr_RpUSSPeriodDiagData_US_S_USSPeriodDiagData_t
#  define Rte_Read_RpUssPowerData_UssPower Rte_Read_SWC_DIDMgr_RpUssPowerData_UssPower
#  define Rte_Read_RpUssTunData_UssTunningData_mcu2_1_t Rte_Read_SWC_DIDMgr_RpUssTunData_UssTunningData_mcu2_1_t
#  define Rte_Read_RpVCState_TbAP_VCStateOut_t Rte_Read_SWC_DIDMgr_RpVCState_TbAP_VCStateOut_t
#  define Rte_Read_RpVINData_VINCurrentData Rte_Read_SWC_DIDMgr_RpVINData_VINCurrentData
#  define Rte_Read_RpVINData_VINLockStatus Rte_Read_SWC_DIDMgr_RpVINData_VINLockStatus
#  define Rte_Read_SWC_DIDMgr_RpVINData_VINLockStatus(data) (*(data) = Rte_SWC_RIDMgr_PpVINData_VINLockStatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpVINData_VINOdoCounter Rte_Read_SWC_DIDMgr_RpVINData_VINOdoCounter
#  define Rte_Read_SWC_DIDMgr_RpVINData_VINOdoCounter(data) (*(data) = Rte_SWC_RIDMgr_PpVINData_VINOdoCounter, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpVINData_VINOriginalData Rte_Read_SWC_DIDMgr_RpVINData_VINOriginalData
#  define Rte_Read_RpVIN_MessageFault_VIN_InvalidValueFlag Rte_Read_SWC_DIDMgr_RpVIN_MessageFault_VIN_InvalidValueFlag
#  define Rte_Read_SWC_DIDMgr_RpVIN_MessageFault_VIN_InvalidValueFlag(data) (*(data) = Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_InvalidValueFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpVIN_MessageFault_VIN_MissingMessageFlag Rte_Read_SWC_DIDMgr_RpVIN_MessageFault_VIN_MissingMessageFlag
#  define Rte_Read_SWC_DIDMgr_RpVIN_MessageFault_VIN_MissingMessageFlag(data) (*(data) = Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_MissingMessageFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpVariantData_Variant Rte_Read_SWC_DIDMgr_RpVariantData_Variant
#  define Rte_Read_SWC_DIDMgr_RpVariantData_Variant(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpVariantData_Variant, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpWDGFaultStatus_Sts Rte_Read_SWC_DIDMgr_RpWDGFaultStatus_Sts
#  define Rte_Read_Rp_DLDOutput_JobDLDOutput_t Rte_Read_SWC_DIDMgr_Rp_DLDOutput_JobDLDOutput_t
#  define Rte_Read_Rp_SafeState_SR_SafeStateOp Rte_Read_SWC_DIDMgr_Rp_SafeState_SR_SafeStateOp


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpECUTimeSinceIGON_ECUTimeStamp_IGON Rte_Write_SWC_DIDMgr_PpECUTimeSinceIGON_ECUTimeStamp_IGON
#  define Rte_Write_SWC_DIDMgr_PpECUTimeSinceIGON_ECUTimeStamp_IGON(data) (Rte_SWC_DIDMgr_PpECUTimeSinceIGON_ECUTimeStamp_IGON = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpECUTimeStamp_ECUTimeStamp Rte_Write_SWC_DIDMgr_PpECUTimeStamp_ECUTimeStamp
#  define Rte_Write_SWC_DIDMgr_PpECUTimeStamp_ECUTimeStamp(data) (Rte_SWC_DIDMgr_PpECUTimeStamp_ECUTimeStamp = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpFailsafeAction_FailSafe_State Rte_Write_SWC_DIDMgr_PpFailsafeAction_FailSafe_State
#  define Rte_Write_SWC_DIDMgr_PpFailsafeAction_FailSafe_State(data) (Rte_SWC_DIDMgr_PpFailsafeAction_FailSafe_State = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpFailsafeDebug_Debugflag Rte_Write_SWC_DIDMgr_PpFailsafeDebug_Debugflag
#  define Rte_Write_SWC_DIDMgr_PpFailsafeDebug_Debugflag(data) (Rte_SWC_DIDMgr_PpFailsafeDebug_Debugflag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpGearPosition_GearValue Rte_Write_SWC_DIDMgr_PpGearPosition_GearValue
#  define Rte_Write_SWC_DIDMgr_PpGearPosition_GearValue(data) (Rte_SWC_DIDMgr_PpGearPosition_GearValue = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpGearPosition_ShortTermAdjActiveFlag_b Rte_Write_SWC_DIDMgr_PpGearPosition_ShortTermAdjActiveFlag_b
#  define Rte_Write_SWC_DIDMgr_PpGearPosition_ShortTermAdjActiveFlag_b(data) (Rte_SWC_DIDMgr_PpGearPosition_ShortTermAdjActiveFlag_b = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpIgOnCounter_IGCounter Rte_Write_SWC_DIDMgr_PpIgOnCounter_IGCounter
#  define Rte_Write_SWC_DIDMgr_PpIgOnCounter_IGCounter(data) (Rte_SWC_DIDMgr_PpIgOnCounter_IGCounter = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpPerformanceStatsEnable_RunTimeStatsEnable Rte_Write_SWC_DIDMgr_PpPerformanceStatsEnable_RunTimeStatsEnable
#  define Rte_Write_SWC_DIDMgr_PpPerformanceStatsEnable_RunTimeStatsEnable(data) (Rte_SWC_DIDMgr_PpPerformanceStatsEnable_RunTimeStatsEnable = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpPerformanceStatsEnable_StackUsageStatsEnable Rte_Write_SWC_DIDMgr_PpPerformanceStatsEnable_StackUsageStatsEnable
#  define Rte_Write_SWC_DIDMgr_PpPerformanceStatsEnable_StackUsageStatsEnable(data) (Rte_SWC_DIDMgr_PpPerformanceStatsEnable_StackUsageStatsEnable = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpResetNvmFlag_V_ResetNvmFlag_b Rte_Write_SWC_DIDMgr_PpResetNvmFlag_V_ResetNvmFlag_b
#  define Rte_Write_SWC_DIDMgr_PpResetNvmFlag_V_ResetNvmFlag_b(data) (Rte_SWC_DIDMgr_PpResetNvmFlag_V_ResetNvmFlag_b = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpSleepProcessState_status Rte_Write_SWC_DIDMgr_PpSleepProcessState_status
#  define Rte_Write_SWC_DIDMgr_PpSleepProcessState_status(data) (Rte_SWC_DIDMgr_PpSleepProcessState_status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_PlantOdoData_PlantOdoData Rte_Write_SWC_DIDMgr_Pp_PlantOdoData_PlantOdoData
#  define Rte_Write_SWC_DIDMgr_Pp_PlantOdoData_PlantOdoData(data) (Rte_SWC_DIDMgr_Pp_PlantOdoData_PlantOdoData = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_CRYPTOMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CDD_CRYPTOMGR_APPL_CODE) RE_CryptoArray_CryptoArray(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) CertPtr, uint16 CertLen); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_CDD_CRYPTOMGR_APPL_CODE) RE_Get_SecureAuthenticationStatus(P2VAR(ADAStatusType, AUTOMATIC, RTE_VAR_NOINIT) ADAStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_CRYPTOMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CDD_IPCHANDLER_APPL_CODE) RE_IpcTxData(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CALDATAPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CALDATAPROVIDER_APPL_CODE) RE_CalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, AUTOMATIC, RTE_VAR_NOINIT) v_SVSCamCurrentCalibData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CALDATAPROVIDER_APPL_CODE) RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamEOLCalibDataToNVM_t, AUTOMATIC, RTE_VAR_NOINIT) v_SVSCamEOLCalibData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CALDATAPROVIDER_APPL_CODE) RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamOCCalibDataToNVM_t, AUTOMATIC, RTE_VAR_NOINIT) v_SVSCamOCCalibData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CALDATAPROVIDER_APPL_CODE) RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamSCCalibDataToNVM_t, AUTOMATIC, RTE_VAR_NOINIT) v_SVSCamSCCalibData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CALDATAPROVIDER_APPL_CODE) RE_IntrinsicCameraSN_Readblock(P2VAR(IntrinsicCamID, AUTOMATIC, RTE_VAR_NOINIT) CamNvmData, P2VAR(CamNvmReadSts, AUTOMATIC, RTE_VAR_NOINIT) NvmCamSts); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CALDATAPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CDD_RUNTIMESTATS_QM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(void, RTE_CDD_RUNTIMESTATS_QM_APPL_CODE) RE_GetTaskStackUsage_Data(P2VAR(float32, AUTOMATIC, RTE_VAR_NOINIT) Stackusage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_CDD_RUNTIMESTATS_QM_APPL_CODE) RE_GetTaskStackUsage_Data(P2VAR(StackData_MCU1_0, AUTOMATIC, RTE_VAR_NOINIT) Stackusage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(void, RTE_CDD_RUNTIMESTATS_QM_APPL_CODE) RE_PpRunTimeStatCSData_GetData(P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) runTimeDataVoid); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_CDD_RUNTIMESTATS_QM_APPL_CODE) RE_PpRunTimeStatCSData_GetData(P2VAR(RunTimeStatData, AUTOMATIC, RTE_VAR_NOINIT) runTimeDataVoid); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_CDD_RUNTIMESTATS_QM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DCM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_VAR_NOINIT) SesCtrlType); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERRORMGRSAT_1_0_B_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_ERRORMGRSAT_1_0_B_APPL_CODE) RE_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, P2CONST(ErrorMgr_stAddData, AUTOMATIC, RTE_VAR_NOINIT) addData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERRORMGRSAT_1_0_B_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERRORMGRSAT_1_0_QM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_ERRORMGRSAT_1_0_QM_APPL_CODE) RE_ReportErrorStatus1_0_QM(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, P2CONST(ErrorMgr_stAddData, AUTOMATIC, RTE_VAR_NOINIT) addData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERRORMGRSAT_1_0_QM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_VAR_NOINIT) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SWC_DTCMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SWC_DTCMGR_APPL_CODE) RE_ClearDTCSettingStatus(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SWC_DTCMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SWC_PROXICONFIGMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(void, RTE_SWC_PROXICONFIGMGR_APPL_CODE) RE_DID2023_ProxiData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 Datalength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) Errorcode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(void, RTE_SWC_PROXICONFIGMGR_APPL_CODE) RE_DID2023_ProxiData(P2CONST(Proxi_255byte, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 Datalength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) Errorcode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SWC_PROXICONFIGMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SWC_VOLTAGEMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SWC_VOLTAGEMGR_APPL_CODE) RE_VoltageMgr_EtGetADCVoltageInfo(VoltMgr_Enum_VoltageMON Channel_ID, P2VAR(float32, AUTOMATIC, RTE_VAR_NOINIT) Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SWC_VOLTAGEMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VROE_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_VROE_APPL_CODE) vRoE_SetActivationState(P2CONST(vRoE_ActivationStateType, AUTOMATIC, RTE_VAR_NOINIT) data, vRoE_OpStatusType opStatus, P2VAR(vRoE_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_VROE_APPL_CODE) vRoE_SetActivationState(P2CONST(vRoE_ActivationStateArrayType, AUTOMATIC, RTE_VAR_NOINIT) data, vRoE_OpStatusType opStatus, P2VAR(vRoE_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) errorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_VROE_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_DID_191D_PowerLatch_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)47, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_2002_OdoFlashing_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)25, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_2002_ProgReqFlag_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)55, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_200A_IgOnCounter_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)48, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_200B_TimeSinceFirstDTC_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)49, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_200C_TimeSinceIgnOnFirstDTC_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)50, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_200D_LastClearDTCOdo_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)51, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_2939_WakeupReason_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)40, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_FD01_PrevCalibDataCopy_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)63, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_FD33_MagnaTesting_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)56, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_FD74_BuffMarkCompErr_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)81, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_FD74_PHY_TuningErr_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)82, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_FD86_FunctionalSettings_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)70, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_FDF0_SleepProcess_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)41, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_FDF0_SleepProcess_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)41, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_RearBrakeEvent_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)65, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_RearBrakeEvent_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)65, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_RearBrakeEvent_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)65, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_SPMAbrtEvent_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)66, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_SPMAbrtEvent_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)66, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_SPMAbrtEvent_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)66, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_Defs_DID_FD42_FailsafeDebug_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)64, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_Defs_DID_FD42_FailsafeDebug_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)64, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_ECU_LifeTime_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)52, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_vRoE_Activation_State_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)46, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_vRoE_Activation_State_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)46, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_vRoE_Activation_State_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)46, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_vRoE_Activation_State_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)46, arg1))
#  define Rte_Call_RoEActivationCSI_WriteData vRoE_SetActivationState
#  define Rte_Call_Rp2023_ProxiData_WriteData(arg1, arg2, arg3) (RE_DID2023_ProxiData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpCalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock RE_CalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock
#  define Rte_Call_RpCalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
#  define Rte_Call_RpCalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
#  define Rte_Call_RpCalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
#  define Rte_Call_RpClearDTCSettingStatus_ClearDTCSettingStatus() (RE_ClearDTCSettingStatus(), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpCryptoArray_CryptoArray(arg1, arg2) (RE_CryptoArray_CryptoArray(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpDCMServices_GetStatus_GetSesCtrlType Dcm_GetSesCtrlType
#  define Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B RE_ReportErrorStatus1_0_B
#  define Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM RE_ReportErrorStatus1_0_QM
#  define Rte_Call_RpGetTaskStackUsage_Data(arg1) (RE_GetTaskStackUsage_Data(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpIntrinsicCameraSN_Readblock RE_IntrinsicCameraSN_Readblock
#  define Rte_Call_RpIpcTxData_IPC_Write_v(arg1, arg2, arg3) (RE_IpcTxData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpReadVoltInfo_GetVoltageInfo(arg1, arg2) (RE_VoltageMgr_EtGetADCVoltageInfo(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpRunTimeStatCSData_Cdd_RunTimeStatQM_GetData(arg1) (RE_PpRunTimeStatCSData_GetData(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpSecureAuthenticationStatus_Get_ADAStatus(arg1) (RE_Get_SecureAuthenticationStatus(arg1), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_DefaultValue;
extern CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_ECU_LifeTime_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2002_OdoFlashing_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200A_IgOnCounter_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD74_BuffMarkCompErr_DefaultValue;
extern CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_191D_PowerLatch_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD42_FailsafeAction_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_vRoE_Activation_State_DefaultValue;
extern CONST(Arr_20Byte, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2939_WakeupReason_DefaultValue;
extern CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_DefaultValue;
extern CONST(TbSVS_S_SVSCamCurrentCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_DefaultValue;
extern CONST(FunctionalSettings_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_DefaultValue;
extern CONST(RearBrkEvent_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_RearBrakeEvent_DefaultValue;
extern CONST(SPMAbrtEvent_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_SPMAbrtEvent_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_DID_200B_TimeSinceFirstDTC_DefaultValue() (Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_DefaultValue)

#  define Rte_CData_ECU_LifeTime_DefaultValue() (Rte_SWC_DIDMgr_ECU_LifeTime_DefaultValue)

#  define Rte_CData_DID_2002_OdoFlashing_DefaultValue() (Rte_SWC_DIDMgr_DID_2002_OdoFlashing_DefaultValue)

#  define Rte_CData_DID_200A_IgOnCounter_DefaultValue() (Rte_SWC_DIDMgr_DID_200A_IgOnCounter_DefaultValue)

#  define Rte_CData_DID_200C_TimeSinceIgnOnFirstDTC_DefaultValue() (Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_DefaultValue)

#  define Rte_CData_DID_200D_LastClearDTCOdo_DefaultValue() (Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_DefaultValue)

#  define Rte_CData_DID_FD74_BuffMarkCompErr_DefaultValue() (Rte_SWC_DIDMgr_DID_FD74_BuffMarkCompErr_DefaultValue)

#  define Rte_CData_DID_FD74_PHY_TuningErr_DefaultValue() (Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_DefaultValue)

#  define Rte_CData_DID_191D_PowerLatch_DefaultValue() (Rte_SWC_DIDMgr_DID_191D_PowerLatch_DefaultValue)

#  define Rte_CData_DID_2002_ProgReqFlag_DefaultValue() (Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_DefaultValue)

#  define Rte_CData_DID_FD42_FailsafeAction_DefaultValue() (Rte_SWC_DIDMgr_DID_FD42_FailsafeAction_DefaultValue)

#  define Rte_CData_DID_FD42_FailsafeDebug_DefaultValue() (Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_DefaultValue)

#  define Rte_CData_DID_FDF0_SleepProcess_DefaultValue() (Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_DefaultValue)

#  define Rte_CData_vRoE_Activation_State_DefaultValue() (Rte_SWC_DIDMgr_vRoE_Activation_State_DefaultValue)

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_2939_WakeupReason_DefaultValue() (&(Rte_SWC_DIDMgr_DID_2939_WakeupReason_DefaultValue[0]))
#  else
#   define Rte_CData_DID_2939_WakeupReason_DefaultValue() (&Rte_SWC_DIDMgr_DID_2939_WakeupReason_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_DID_FD33_MagnaTesting_DefaultValue() (&(Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_DefaultValue[0]))
#  else
#   define Rte_CData_DID_FD33_MagnaTesting_DefaultValue() (&Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_DefaultValue)
#  endif

#  define Rte_CData_DID_FD01_PrevCalibDataCopy_DefaultValue() (&Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_DefaultValue)

#  define Rte_CData_DID_FD86_FunctionalSettings_DefaultValue() (&Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_DefaultValue)

#  define Rte_CData_DID_RearBrakeEvent_DefaultValue() (&Rte_SWC_DIDMgr_DID_RearBrakeEvent_DefaultValue)

#  define Rte_CData_DID_SPMAbrtEvent_DefaultValue() (&Rte_SWC_DIDMgr_DID_SPMAbrtEvent_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
extern VAR(Arr_20Byte, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_2939_WakeupReason_MirrorBlock;
extern VAR(Dcm_Data10ByteType, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_MirrorBlock;
extern VAR(TbSVS_S_SVSCamCurrentCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_MirrorBlock;
extern VAR(FunctionalSettings_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_MirrorBlock;
extern VAR(RearBrkEvent_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_RearBrakeEvent_MirrorBlock;
extern VAR(SPMAbrtEvent_t, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DIDMgr_DID_SPMAbrtEvent_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_200B_TimeSinceFirstDTC_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_ECU_LifeTime_MirrorBlock() \
  (&Rte_SWC_DIDMgr_ECU_LifeTime_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_2002_OdoFlashing_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_2002_OdoFlashing_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_200A_IgOnCounter_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_200A_IgOnCounter_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_200C_TimeSinceIgnOnFirstDTC_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_200D_LastClearDTCOdo_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_FD74_BuffMarkCompErr_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_FD74_BuffMarkCompErr_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_FD74_PHY_TuningErr_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_191D_PowerLatch_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_191D_PowerLatch_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_2002_ProgReqFlag_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_FDF0_SleepProcess_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_vRoE_Activation_State_MirrorBlock() \
  (&Rte_SWC_DIDMgr_vRoE_Activation_State_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_2939_WakeupReason_MirrorBlock() (&((*RtePim_DID_2939_WakeupReason_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_2939_WakeupReason_MirrorBlock() RtePim_DID_2939_WakeupReason_MirrorBlock()
#  endif
#  define RtePim_DID_2939_WakeupReason_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_2939_WakeupReason_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_DID_FD33_MagnaTesting_MirrorBlock() (&((*RtePim_DID_FD33_MagnaTesting_MirrorBlock())[0]))
#  else
#   define Rte_Pim_DID_FD33_MagnaTesting_MirrorBlock() RtePim_DID_FD33_MagnaTesting_MirrorBlock()
#  endif
#  define RtePim_DID_FD33_MagnaTesting_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_FD01_PrevCalibDataCopy_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_FD86_FunctionalSettings_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_RearBrakeEvent_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_RearBrakeEvent_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_SPMAbrtEvent_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_SPMAbrtEvent_MirrorBlock)
/* PRQA L:L1 */

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT) Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_INIT_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_FD42_FailsafeDebug_MirrorBlock() \
  (&Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SWC_DIDMgr_START_SEC_CODE
# include "SWC_DIDMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DataServices_Data_220103_VIN_Lock_Status_ReadData DataServices_Data_220103_VIN_Lock_Status_ReadData
#  define RTE_RUNNABLE_DataServices_Data_220107_RoE_Activation_State_ReadData DataServices_Data_220107_RoE_Activation_State_ReadData
#  define RTE_RUNNABLE_DataServices_Data_220107_RoE_Activation_State_WriteData DataServices_Data_220107_RoE_Activation_State_WriteData
#  define RTE_RUNNABLE_DataServices_Data_221002_Vehicle_Speed_ReadData DataServices_Data_221002_Vehicle_Speed_ReadData
#  define RTE_RUNNABLE_DataServices_Data_221004_Battery_Voltage_ReadData DataServices_Data_221004_Battery_Voltage_ReadData
#  define RTE_RUNNABLE_DataServices_Data_221008_ECU_Life_Time_ReadData DataServices_Data_221008_ECU_Life_Time_ReadData
#  define RTE_RUNNABLE_DataServices_Data_221009_ECU_Time_Since_Ignition_ON_ReadData DataServices_Data_221009_ECU_Time_Since_Ignition_ON_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_ReadData DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22102A_Check_EOL_Configuration_Data_ReadData DataServices_Data_22102A_Check_EOL_Configuration_Data_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22191D_Time_of_Power_Latch_ReadData DataServices_Data_22191D_Time_of_Power_Latch_ReadData
#  define RTE_RUNNABLE_DataServices_Data_221921_Operational_Mode_Status_ReadData DataServices_Data_221921_Operational_Mode_Status_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222001_Odometer_ReadData DataServices_Data_222001_Odometer_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222002_Odometer_at_last_Flash_programming_ReadData DataServices_Data_222002_Odometer_at_last_Flash_programming_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_ReadData DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22200A_Ignition_ON_Counter_ReadData DataServices_Data_22200A_Ignition_ON_Counter_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22200B_Time_First_DTC_Detection_ReadData DataServices_Data_22200B_Time_First_DTC_Detection_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_ReadData DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_ReadData DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222010_Programming_Status_ReadData DataServices_Data_222010_Programming_Status_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222013_VIN_Lock_State_Read_ReadData DataServices_Data_222013_VIN_Lock_State_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222024_Read_ECU_PROXI_Data_ReadData DataServices_Data_222024_Read_ECU_PROXI_Data_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222024_Read_ECU_PROXI_Data_ReadDataLength DataServices_Data_222024_Read_ECU_PROXI_Data_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Data_222026_CAN_Overrun_Counters_ReadData DataServices_Data_222026_CAN_Overrun_Counters_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22292E_PROXI_Write_Counter_ReadData DataServices_Data_22292E_PROXI_Write_Counter_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_ReadData DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222945_Flow_Control_Test_ReadData DataServices_Data_222945_Flow_Control_Test_ReadData
#  define RTE_RUNNABLE_DataServices_Data_222945_Flow_Control_Test_WriteData DataServices_Data_222945_Flow_Control_Test_WriteData
#  define RTE_RUNNABLE_DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_ReadData DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_224422_USS_Sensor2_Part_Number_Read_ReadData DataServices_Data_224422_USS_Sensor2_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_ReadData DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_ReadData DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_ReadData DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_ReadData DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_ReadData DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_ReadData DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_ReadData DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_ReadData DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_ReadData DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_ReadData DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_224451_EOL_Calibration_State_Read_ReadData DataServices_Data_224451_EOL_Calibration_State_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225100_SPM_status_Read_ReadData DataServices_Data_225100_SPM_status_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_ReadData DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_ReadData DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_ReadData DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_ReadData DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225201_Plant_Mode_Status_Read_ReadData DataServices_Data_225201_Plant_Mode_Status_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225300_Rear_Braking_Event_1_Read_ReadData DataServices_Data_225300_Rear_Braking_Event_1_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225301_Rear_Braking_Event_2_Read_ReadData DataServices_Data_225301_Rear_Braking_Event_2_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225302_Rear_Braking_Event_3_Read_ReadData DataServices_Data_225302_Rear_Braking_Event_3_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225303_SPM_Event_Abort_1_Read_ReadData DataServices_Data_225303_SPM_Event_Abort_1_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225304_SPM_Event_Abort_2_Read_ReadData DataServices_Data_225304_SPM_Event_Abort_2_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225305_SPM_Event_Abort_3_Read_ReadData DataServices_Data_225305_SPM_Event_Abort_3_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_ReadData DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_ReadData DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F10B_ECU_Qualification_ReadData DataServices_Data_22F10B_ECU_Qualification_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F186_Active_Diagnostic_Session_ReadData DataServices_Data_22F186_Active_Diagnostic_Session_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F190_VIN_Original_ReadData DataServices_Data_22F190_VIN_Original_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F1A1_Configuration_Code_ReadData DataServices_Data_22F1A1_Configuration_Code_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F1A6_Message_Matrix_ReadData DataServices_Data_22F1A6_Message_Matrix_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22F1B0_VIN_Current_ReadData DataServices_Data_22F1B0_VIN_Current_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD00_Plant_Camera_Calibration_Data_ReadData DataServices_Data_22FD00_Plant_Camera_Calibration_Data_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD00_Plant_Camera_Calibration_Data_WriteData DataServices_Data_22FD00_Plant_Camera_Calibration_Data_WriteData
#  define RTE_RUNNABLE_DataServices_Data_22FD01_Previous_Camera_Calibration_Data_ReadData DataServices_Data_22FD01_Previous_Camera_Calibration_Data_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadData DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadDataLength DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadDataLength
#  define RTE_RUNNABLE_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_WriteData DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_WriteData
#  define RTE_RUNNABLE_DataServices_Data_22FD07_OC_Result_Read_ReadData DataServices_Data_22FD07_OC_Result_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD08_OC_Data_Read_ReadData DataServices_Data_22FD08_OC_Data_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD08_OC_Data_Read_WriteData DataServices_Data_22FD08_OC_Data_Read_WriteData
#  define RTE_RUNNABLE_DataServices_Data_22FD0A_SC_Data_Read_ReadData DataServices_Data_22FD0A_SC_Data_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD0A_SC_Data_Read_WriteData DataServices_Data_22FD0A_SC_Data_Read_WriteData
#  define RTE_RUNNABLE_DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_ReadData DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_ReadData DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_ReadData DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_ReadData DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_ReadData DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD1E_Calibration_Status_Read_ReadData DataServices_Data_22FD1E_Calibration_Status_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD20_ECU_PinStates_Read_ReadData DataServices_Data_22FD20_ECU_PinStates_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD28_USS_Ringing_Frequency_Read_ReadData DataServices_Data_22FD28_USS_Ringing_Frequency_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD29_USS_Driving_Frequency_Read_ReadData DataServices_Data_22FD29_USS_Driving_Frequency_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD2A_USS_Ringing_Time_Read_ReadData DataServices_Data_22FD2A_USS_Ringing_Time_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_ReadData DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD2C_USS_Temperature_Read_ReadData DataServices_Data_22FD2C_USS_Temperature_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_ReadData DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_ReadData DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD33_Magna_Testing_2_Read_ReadData DataServices_Data_22FD33_Magna_Testing_2_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD33_Magna_Testing_2_Read_WriteData DataServices_Data_22FD33_Magna_Testing_2_Read_WriteData
#  define RTE_RUNNABLE_DataServices_Data_22FD42_Failsafe_Behaviour_Read_ReadData DataServices_Data_22FD42_Failsafe_Behaviour_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD42_Failsafe_Behaviour_Read_WriteData DataServices_Data_22FD42_Failsafe_Behaviour_Read_WriteData
#  define RTE_RUNNABLE_DataServices_Data_22FD43_Active_Safe_State_Read DataServices_Data_22FD43_Active_Safe_State_Read
#  define RTE_RUNNABLE_DataServices_Data_22FD44_Error_Flags_Read DataServices_Data_22FD44_Error_Flags_Read
#  define RTE_RUNNABLE_DataServices_Data_22FD46_Camera_Power_Supply_Read_ReadData DataServices_Data_22FD46_Camera_Power_Supply_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_ReadData DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD48_PCBA_Temperature_Read_ReadData DataServices_Data_22FD48_PCBA_Temperature_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_ReadData DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_ReadData DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD60_ECU_Software_Status_Read_ReadData DataServices_Data_22FD60_ECU_Software_Status_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_ReadData DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_ReadData DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_ReadData DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD65_FuSa_Module_Status_Read_ReadData DataServices_Data_22FD65_FuSa_Module_Status_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read
#  define RTE_RUNNABLE_DataServices_Data_22FD67_Camera_DLD_Status_Read DataServices_Data_22FD67_Camera_DLD_Status_Read
#  define RTE_RUNNABLE_DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_ReadData DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD86_Functional_Settings_Read_ReadData DataServices_Data_22FD86_Functional_Settings_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FD86_Functional_Settings_Read_WriteData DataServices_Data_22FD86_Functional_Settings_Read_WriteData
#  define RTE_RUNNABLE_DataServices_Data_22FDF0_ECU_shutdown_process_Read_ReadData DataServices_Data_22FDF0_ECU_shutdown_process_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FDF0_ECU_shutdown_process_Read_WriteData DataServices_Data_22FDF0_ECU_shutdown_process_Read_WriteData
#  define RTE_RUNNABLE_DataServices_Data_22FDF1_CPU_Load_Read_ReadData DataServices_Data_22FDF1_CPU_Load_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FDF2_Reset_Reason_Read_ReadData DataServices_Data_22FDF2_Reset_Reason_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FDF5_PerformanceStatEnable_Read_ReadData DataServices_Data_22FDF5_PerformanceStatEnable_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FDF5_PerformanceStatEnable_Read_WriteData DataServices_Data_22FDF5_PerformanceStatEnable_Read_WriteData
#  define RTE_RUNNABLE_DataServices_Data_22FDF6_RunTimeStatsData_Read_ReadData DataServices_Data_22FDF6_RunTimeStatsData_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_ReadData DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_22FDF8_StackUsage_Read_ReadData DataServices_Data_22FDF8_StackUsage_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_2E2023_PROXI_Data_WriteData DataServices_Data_2E2023_PROXI_Data_WriteData
#  define RTE_RUNNABLE_DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_WriteData DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_WriteData
#  define RTE_RUNNABLE_DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_WriteData DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_WriteData
#  define RTE_RUNNABLE_DataServices_Data_2EFD4E_Reset_NVM_Write_WriteData DataServices_Data_2EFD4E_Reset_NVM_Write_WriteData
#  define RTE_RUNNABLE_DataServices_Data_2F5001_Gear_Position_Read_ReadData DataServices_Data_2F5001_Gear_Position_Read_ReadData
#  define RTE_RUNNABLE_DataServices_Data_2F5001_Gear_Position_Read_ReturnControlToECU DataServices_Data_2F5001_Gear_Position_Read_ReturnControlToECU
#  define RTE_RUNNABLE_DataServices_Data_2F5001_Gear_Position_Read_ShortTermAdjustment DataServices_Data_2F5001_Gear_Position_Read_ShortTermAdjustment
#  define RTE_RUNNABLE_Pp_NVM_Write_ProxiConfigTable_ProxiconfigTable_Nvm_write_confirmation Pp_NVM_Write_ProxiConfigTable_ProxiconfigTable_Nvm_write_confirmation
#  define RTE_RUNNABLE_RE_DIDMgr_Init RE_DIDMgr_Init
#  define RTE_RUNNABLE_RE_DIDMgr_Main RE_DIDMgr_Main
#  define RTE_RUNNABLE_RE_periodic_CPU_Load RE_periodic_CPU_Load
# endif

# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_220103_VIN_Lock_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_220103_VIN_Lock_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_220107_RoE_Activation_State_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_220107_RoE_Activation_State_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_220107_RoE_Activation_State_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_220107_RoE_Activation_State_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_221002_Vehicle_Speed_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_221002_Vehicle_Speed_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_221004_Battery_Voltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_221004_Battery_Voltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_221008_ECU_Life_Time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_221008_ECU_Life_Time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_221009_ECU_Time_Since_Ignition_ON_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_221009_ECU_Time_Since_Ignition_ON_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22102A_Check_EOL_Configuration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22102A_Check_EOL_Configuration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data9ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22191D_Time_of_Power_Latch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22191D_Time_of_Power_Latch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_221921_Operational_Mode_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_221921_Operational_Mode_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data9ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222001_Odometer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222001_Odometer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222002_Odometer_at_last_Flash_programming_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222002_Odometer_at_last_Flash_programming_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22200A_Ignition_ON_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22200A_Ignition_ON_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22200B_Time_First_DTC_Detection_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22200B_Time_First_DTC_Detection_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222010_Programming_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222010_Programming_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222013_VIN_Lock_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222013_VIN_Lock_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222024_Read_ECU_PROXI_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222024_Read_ECU_PROXI_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data255ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222024_Read_ECU_PROXI_Data_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222026_CAN_Overrun_Counters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222026_CAN_Overrun_Counters_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22292E_PROXI_Write_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22292E_PROXI_Write_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222945_Flow_Control_Test_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222945_Flow_Control_Test_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data200ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222945_Flow_Control_Test_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_222945_Flow_Control_Test_WriteData(P2CONST(Dcm_Data200ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224422_USS_Sensor2_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224422_USS_Sensor2_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224451_EOL_Calibration_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_224451_EOL_Calibration_State_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data44ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225100_SPM_status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225100_SPM_status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data34ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data41ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data19ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data15ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225201_Plant_Mode_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225201_Plant_Mode_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225300_Rear_Braking_Event_1_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225300_Rear_Braking_Event_1_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225301_Rear_Braking_Event_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225301_Rear_Braking_Event_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225302_Rear_Braking_Event_3_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225302_Rear_Braking_Event_3_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225303_SPM_Event_Abort_1_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225303_SPM_Event_Abort_1_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225304_SPM_Event_Abort_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225304_SPM_Event_Abort_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225305_SPM_Event_Abort_3_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225305_SPM_Event_Abort_3_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data42ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data48ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F10B_ECU_Qualification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F10B_ECU_Qualification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F186_Active_Diagnostic_Session_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F186_Active_Diagnostic_Session_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F190_VIN_Original_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F190_VIN_Original_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data17ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F1A1_Configuration_Code_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F1A1_Configuration_Code_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data11ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F1A6_Message_Matrix_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F1A6_Message_Matrix_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F1B0_VIN_Current_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22F1B0_VIN_Current_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data17ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD00_Plant_Camera_Calibration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD00_Plant_Camera_Calibration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data54ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD00_Plant_Camera_Calibration_Data_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD00_Plant_Camera_Calibration_Data_WriteData(P2CONST(Dcm_Data54ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD01_Previous_Camera_Calibration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD01_Previous_Camera_Calibration_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data50ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3072ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_WriteData(P2CONST(Dcm_Data3072ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD07_OC_Result_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD07_OC_Result_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD08_OC_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD08_OC_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data28ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD08_OC_Data_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD08_OC_Data_Read_WriteData(P2CONST(Dcm_Data28ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0A_SC_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0A_SC_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data28ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0A_SC_Data_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0A_SC_Data_Read_WriteData(P2CONST(Dcm_Data28ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data256ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data256ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data256ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data256ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data52ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD1E_Calibration_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD1E_Calibration_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data21ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD20_ECU_PinStates_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD20_ECU_PinStates_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD28_USS_Ringing_Frequency_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD28_USS_Ringing_Frequency_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD29_USS_Driving_Frequency_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD29_USS_Driving_Frequency_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD2A_USS_Ringing_Time_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD2A_USS_Ringing_Time_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD2C_USS_Temperature_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD2C_USS_Temperature_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data24ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data48ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data48ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD33_Magna_Testing_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD33_Magna_Testing_2_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD33_Magna_Testing_2_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD33_Magna_Testing_2_Read_WriteData(P2CONST(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD42_Failsafe_Behaviour_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD42_Failsafe_Behaviour_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD42_Failsafe_Behaviour_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD42_Failsafe_Behaviour_Read_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD43_Active_Safe_State_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD43_Active_Safe_State_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD44_Error_Flags_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD44_Error_Flags_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD46_Camera_Power_Supply_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD46_Camera_Power_Supply_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data8ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD48_PCBA_Temperature_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD48_PCBA_Temperature_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data16ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data9ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD60_ECU_Software_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD60_ECU_Software_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data138ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD65_FuSa_Module_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD65_FuSa_Module_Status_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data28ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data9ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD67_Camera_DLD_Status_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD67_Camera_DLD_Status_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD86_Functional_Settings_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD86_Functional_Settings_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data6ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD86_Functional_Settings_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FD86_Functional_Settings_Read_WriteData(P2CONST(Dcm_Data6ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF0_ECU_shutdown_process_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF0_ECU_shutdown_process_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF0_ECU_shutdown_process_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF0_ECU_shutdown_process_Read_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF1_CPU_Load_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF1_CPU_Load_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF2_Reset_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF2_Reset_Reason_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF5_PerformanceStatEnable_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF5_PerformanceStatEnable_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF5_PerformanceStatEnable_Read_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF5_PerformanceStatEnable_Read_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF6_RunTimeStatsData_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF6_RunTimeStatsData_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data306ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data44ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF8_StackUsage_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_22FDF8_StackUsage_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data37ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2E2023_PROXI_Data_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2E2023_PROXI_Data_WriteData(P2CONST(Dcm_Data255ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_WriteData(P2CONST(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_WriteData(P2CONST(Dcm_Data14ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2EFD4E_Reset_NVM_Write_WriteData(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2EFD4E_Reset_NVM_Write_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2F5001_Gear_Position_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2F5001_Gear_Position_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2F5001_Gear_Position_Read_ReturnControlToECU(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2F5001_Gear_Position_Read_ShortTermAdjustment(P2CONST(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DIDMgr_CODE) DataServices_Data_2F5001_Gear_Position_Read_ShortTermAdjustment(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_VAR_NOINIT) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, SWC_DIDMgr_CODE) Pp_NVM_Write_ProxiConfigTable_ProxiconfigTable_Nvm_write_confirmation(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SWC_DIDMgr_CODE) RE_DIDMgr_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_DIDMgr_CODE) RE_DIDMgr_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_DIDMgr_CODE) RE_periodic_CPU_Load(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_DIDMgr_STOP_SEC_CODE
# include "SWC_DIDMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_DataServices_Data_220103_VIN_Lock_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_220103_VIN_Lock_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_220107_RoE_Activation_State_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_220107_RoE_Activation_State_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_221002_Vehicle_Speed_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_221002_Vehicle_Speed_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_221004_Battery_Voltage_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_221004_Battery_Voltage_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_221008_ECU_Life_Time_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_221008_ECU_Life_Time_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_221009_ECU_Time_Since_Ignition_ON_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_221009_ECU_Time_Since_Ignition_ON_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22100B_Diagnostic_Tool_and_Session_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22102A_Check_EOL_Configuration_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22102A_Check_EOL_Configuration_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22191D_Time_of_Power_Latch_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22191D_Time_of_Power_Latch_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_221921_Operational_Mode_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_221921_Operational_Mode_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222001_Odometer_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222001_Odometer_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222002_Odometer_at_last_Flash_programming_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222002_Odometer_at_last_Flash_programming_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222008_ECU_Life_Time_Not_Volatile_Memory_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22200A_Ignition_ON_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22200A_Ignition_ON_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22200B_Time_First_DTC_Detection_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22200B_Time_First_DTC_Detection_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22200C_Time_Since_Ignition_ON_of_first_DTC_Detection_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22200D_Odometer_Last_Clear_Data_Trouble_Code_DTC_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222010_Programming_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222010_Programming_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222013_VIN_Lock_State_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222013_VIN_Lock_State_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222024_Read_ECU_PROXI_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222024_Read_ECU_PROXI_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222026_CAN_Overrun_Counters_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222026_CAN_Overrun_Counters_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22292E_PROXI_Write_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22292E_PROXI_Write_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222939_FDCAN2_BUS_Network_WakeUp_Reason_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_222945_Flow_Control_Test_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_222945_Flow_Control_Test_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224421_USS_Sensor_1_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224422_USS_Sensor2_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224422_USS_Sensor2_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224423_USS_Sensor_3_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224424_USS_Sensor_4_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224425_USS_Sensor_5_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224426_USS_Sensor_6_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224427_USS_Sensor_7_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224428_USS_Sensor_8_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224429_USS_Sensor_9_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22442A_USS_Sensor_10_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22442B_USS_Sensor_11_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22442C_USS_Sensor_12_Part_Number_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_224451_EOL_Calibration_State_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_224451_EOL_Calibration_State_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225100_SPM_status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225100_SPM_status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225102_FD_CAN14_Rx_Signals_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225103_FD_CAN2_Rx_Signals_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225104_FD_CAN14_Tx_Signals_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225105_FD_CAN2_Tx_Signals_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225107_Front_Sensor_HealthBlockage_LiveDetection_Check_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225109_Rear_Sensor_HealthBlockage_LiveDetection_Check_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225201_Plant_Mode_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225201_Plant_Mode_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225300_Rear_Braking_Event_1_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225300_Rear_Braking_Event_1_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225301_Rear_Braking_Event_2_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225301_Rear_Braking_Event_2_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225302_Rear_Braking_Event_3_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225302_Rear_Braking_Event_3_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225303_SPM_Event_Abort_1_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225303_SPM_Event_Abort_1_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225304_SPM_Event_Abort_2_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225304_SPM_Event_Abort_2_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225305_SPM_Event_Abort_3_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225305_SPM_Event_Abort_3_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225500_Trailer_Sense_and_Drive_Function_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_225501_Trailer_coupler_sense_detection_Function_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F10B_ECU_Qualification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F10B_ECU_Qualification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F186_Active_Diagnostic_Session_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F186_Active_Diagnostic_Session_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F190_VIN_Original_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F190_VIN_Original_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1A1_Configuration_Code_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1A1_Configuration_Code_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1A6_Message_Matrix_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1A6_Message_Matrix_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22F1B0_VIN_Current_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22F1B0_VIN_Current_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD00_Plant_Camera_Calibration_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD00_Plant_Camera_Calibration_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD01_Previous_Camera_Calibration_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD01_Previous_Camera_Calibration_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD04_USS_Sensor_tuning_values_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD07_OC_Result_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD07_OC_Result_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD08_OC_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD08_OC_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD0A_SC_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD0A_SC_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD0C_Front_Camera_Data_EEPROM_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD0D_Left_Camera_Data_EEPROM_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD0E_Rear_Camera_Data_EEPROM_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD0F_Right_Camera_Data_EEPROM_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD1C_Current_Camera_Calibration_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD1E_Calibration_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD1E_Calibration_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD20_ECU_PinStates_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD20_ECU_PinStates_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD28_USS_Ringing_Frequency_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD28_USS_Ringing_Frequency_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD29_USS_Driving_Frequency_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD29_USS_Driving_Frequency_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD2A_USS_Ringing_Time_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD2A_USS_Ringing_Time_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD2B_USS_Direct_Distance_0xFD2B_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD2C_USS_Temperature_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD2C_USS_Temperature_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD2D_USS_Sensor_ID_IME_SN_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD2E_USS_Sensor_ID_Murata_SN_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD33_Magna_Testing_2_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD33_Magna_Testing_2_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD42_Failsafe_Behaviour_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD42_Failsafe_Behaviour_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD43_Active_Safe_State_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD43_Active_Safe_State_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD44_Error_Flags_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD44_Error_Flags_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD46_Camera_Power_Supply_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD46_Camera_Power_Supply_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD47_SoC_Temperature_0xFD47_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD48_PCBA_Temperature_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD48_PCBA_Temperature_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD49_SoC_Die_Temperature_ID_0xFD49_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD4A_Ultrasonic_Sensors_Power_supply_and_Current_Level_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD60_ECU_Software_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD60_ECU_Software_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD61_Vehicle_Variant_Coding_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD62_ASIL_QM_Fault_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD64_ASIL_B_Fault_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD65_FuSa_Module_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD65_FuSa_Module_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD66_Camera_occlusion_and_low_light_status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD67_Camera_DLD_Status_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD67_Camera_DLD_Status_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD74_PHY_Tunning_Error_And_Buffer_Mark_Error_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FD86_Functional_Settings_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FD86_Functional_Settings_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF0_ECU_shutdown_process_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF0_ECU_shutdown_process_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF1_CPU_Load_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF1_CPU_Load_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF2_Reset_Reason_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF2_Reset_Reason_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF5_PerformanceStatEnable_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF5_PerformanceStatEnable_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF6_RunTimeStatsData_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF6_RunTimeStatsData_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF7_Intrinsic_Camera_NvM_Data_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_22FDF8_StackUsage_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_22FDF8_StackUsage_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_2E2023_PROXI_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_2E2023_PROXI_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_2EF184_Application_Software_Fingerprint_writing_information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_2EF185_Application_Data_Software_Fingerprint_Writing_Information_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_2EFD4E_Reset_NVM_Write_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_2EFD4E_Reset_NVM_Write_E_NOT_OK (1U)

#  define RTE_E_DataServices_Data_2F5001_Gear_Position_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Data_2F5001_Gear_Position_Read_E_NOT_OK (1U)

#  define RTE_E_IF_IntrinsicCameraSN_E_NOT_OK (1U)

#  define RTE_E_IF_IntrinsicCameraSN_E_OK (0U)

#  define RTE_E_IF_SWC_CalDataProvider_SVSCamCurrentCalibData_E_NOT_OK (1U)

#  define RTE_E_IF_SWC_CalDataProvider_SVSCamEOLCalibData_E_NOT_OK (1U)

#  define RTE_E_IF_SWC_CalDataProvider_SVSCamOCCalibData_E_NOT_OK (1U)

#  define RTE_E_IF_SWC_CalDataProvider_SVSCamSCCalibData_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

#  define RTE_E_P_Error_CS_E_NOK (1U)

#  define RTE_E_RoEActivationCSI_DCM_E_PENDING (10U)

#  define RTE_E_RoEActivationCSI_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_DIDMGR_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
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
