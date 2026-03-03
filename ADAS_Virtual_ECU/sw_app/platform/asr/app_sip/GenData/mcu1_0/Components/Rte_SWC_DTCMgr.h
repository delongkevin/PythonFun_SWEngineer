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
 *             File:  Rte_SWC_DTCMgr.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_DTCMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_DTCMGR_H
# define RTE_SWC_DTCMGR_H

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

# include "Rte_SWC_DTCMgr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(BswM_DtcSettingClearFlagModeGrp, RTE_VAR_INIT) Rte_SWC_DTCMgr_PRpDtcSettingClearFlagModeGrp_requestedMode;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DTCMgr_PpDtcB12852AData_v_DtcData_u8;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DTCMgr_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag;
extern VAR(uint32, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpECUTimeSinceIGON_ECUTimeStamp_IGON;
extern VAR(uint32, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpECUTimeStamp_ECUTimeStamp;
extern VAR(uint32, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpIgOnCounter_IGCounter;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpPlantMode_Status;
extern VAR(SystemState, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpSystemStateManager_SysM_State;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_Battery_Volt_1;
extern VAR(OperationalModeSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_OperationalModeSts;
extern VAR(TRSC_EnableBtn_Sts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TRSC_EnableBtn_Sts;
extern VAR(TotalOdometer, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer;
extern VAR(THA_STAT, RTE_VAR_INIT) Rte_SWC_VCANTx_PpToSwcFD02Tx_THA_STAT;
extern VAR(TRSC_STAT, RTE_VAR_INIT) Rte_SWC_VCANTx_PpToSwcFD02Tx_TRSC_STAT;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Pamtuningset;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16;
extern VAR(APARequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts;
extern VAR(CM_TCH_STAT, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT;
extern VAR(CM_TCH_X_COORD, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD;
extern VAR(CM_TCH_Y_COORD, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD;
extern VAR(CameraDisplaySts2, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2;
extern VAR(CmdIgnSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts;
extern VAR(DriverDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature;
extern VAR(Fwrd_Cam_Guidelines, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines;
extern VAR(GearEngaged, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged;
extern VAR(LHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts;
extern VAR(PsngrDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts;
extern VAR(RHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts;
extern VAR(RHatchSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts;
extern VAR(ShiftLeverPosition, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition;
extern VAR(TGW_CAMERA_DISP_STAT, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT;
extern VAR(DisplayView2, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2;
extern VAR(ParkingManeuverActive, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ParkingManeuverActive;
extern VAR(FD14_ESS_ENG_ST_W, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W;
extern VAR(FD14_LwsAngle, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PRpDtcSettingClearFlagModeGrp_requestedMode (0U)
#  define Rte_InitValue_PpDtcB12852AData_v_DtcData_u8 (0U)
#  define Rte_InitValue_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag (FALSE)
#  define Rte_InitValue_PpToComFD02Tx_CurrentCanNMState_FD02_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_CurrentFailSts_FD02_PAM (FALSE)
#  define Rte_InitValue_PpToComFD02Tx_DES_FD02_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_01_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_02_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_03_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_04_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_05_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_06_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_07_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_08_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_09_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_10_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_Digit_11_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_EOL_FD02_PAM (FALSE)
#  define Rte_InitValue_PpToComFD02Tx_GenericFailSts_FD02_PAM (FALSE)
#  define Rte_InitValue_PpToComFD02Tx_PreviousCanNMState_FD02_PAM (0U)
#  define Rte_InitValue_PpToComFD02Tx_THA_EPB_Req (0U)
#  define Rte_InitValue_PpToComFD02Tx_THA_STAT (0U)
#  define Rte_InitValue_PpToComFD02Tx_THA_SpeedLimit_Req (0U)
#  define Rte_InitValue_PpToComFD02Tx_THA_Speed_Limit (0U)
#  define Rte_InitValue_PpToComFD02Tx_THA_SteeringDamping (100U)
#  define Rte_InitValue_PpToComFD02Tx_THA_SteeringTorqueInfo (1024U)
#  define Rte_InitValue_PpToComFD02Tx_THA_SteeringTorqueReq (0U)
#  define Rte_InitValue_PpToComFD02Tx_TRSCMoreCamRQSts (FALSE)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_PopupDisp_Info (0U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_PopupDisp_Info2 (0U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_STAT (1U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_SpeedLimit_Req (0U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_SteeringDamping (128U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_SteeringTorqueInfo (1024U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_SteeringTorqueReq (0U)
#  define Rte_InitValue_PpToComFD02Tx_TRSC_VehicleStop_Req (3U)
#  define Rte_InitValue_PpToComFD02Tx_Trailer_Angle (0U)
#  define Rte_InitValue_PpToComFD02Tx_Trailer_Angle_Sign (0U)
#  define Rte_InitValue_PpToComFD02Tx_Trailer_Calibration (0U)
#  define Rte_InitValue_PpToComFD02Tx_TrlrHitchLight_Cntrl (0U)
#  define Rte_InitValue_PpToComFD02Tx_WakeupSource_FD02_PAM (0U)
#  define Rte_InitValue_RpECUTimeSinceIGON_ECUTimeStamp_IGON (0U)
#  define Rte_InitValue_RpECUTimeStamp_ECUTimeStamp (0U)
#  define Rte_InitValue_RpIgOnCounter_IGCounter (0U)
#  define Rte_InitValue_RpSystemStateManager_SysM_State (0U)
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
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_R_DtcData_B_Data_DtcAddData_B(P2VAR(DtcAddData_B, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_R_DtcData_B_Data_DtcStatus_B(P2VAR(DtcStatus_B, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_R_DtcData_QM_Data_DtcAddData_QM(P2VAR(DtcAddData_QM, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_R_DtcData_QM_Data_DtcStatus_QM(P2VAR(DtcStatus_QM, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_RoEMessageSRI_Data(P2VAR(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_RoEMessageSRI_Data(P2VAR(vRoE_MessageType, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_RpAPSMPAOut_TbAP_APSMPAOut_t(P2VAR(TbAP_APSMPAOut_t, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_RpCalDataProviderNvmData_CalData_mcu1_0(P2VAR(CalDataProvider_MCU_1_0_Def, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_RpDLDOutput_JobDLDOutput_t(P2VAR(JobDLDOutput_t, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_RpErrors_B_Errors_B(P2VAR(uint32, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_RpErrors_B_Errors_B(P2VAR(ErrorListArr_B, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_RpErrors_QM_Errors_QM(P2VAR(uint32, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_DTCMgr_RpErrors_QM_Errors_QM(P2VAR(ErrorListArr_QM, AUTOMATIC, RTE_SWC_DTCMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_DTCMgr_PpToComFD02Tx_N_PDU(P2CONST(uint8, AUTOMATIC, RTE_SWC_DTCMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_DTCMgr_PpToComFD02Tx_N_PDU(P2CONST(N_PDU, AUTOMATIC, RTE_SWC_DTCMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_PRpDtcSettingClearFlagModeGrp_requestedMode Rte_Read_SWC_DTCMgr_PRpDtcSettingClearFlagModeGrp_requestedMode
#  define Rte_Read_SWC_DTCMgr_PRpDtcSettingClearFlagModeGrp_requestedMode(data) (*(data) = Rte_SWC_DTCMgr_PRpDtcSettingClearFlagModeGrp_requestedMode, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag Rte_Read_SWC_DTCMgr_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag
#  define Rte_Read_SWC_DTCMgr_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag(data) (*(data) = Rte_SWC_DTCMgr_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_R_DtcData_B_Data_DtcAddData_B Rte_Read_SWC_DTCMgr_R_DtcData_B_Data_DtcAddData_B
#  define Rte_Read_R_DtcData_B_Data_DtcStatus_B Rte_Read_SWC_DTCMgr_R_DtcData_B_Data_DtcStatus_B
#  define Rte_Read_R_DtcData_QM_Data_DtcAddData_QM Rte_Read_SWC_DTCMgr_R_DtcData_QM_Data_DtcAddData_QM
#  define Rte_Read_R_DtcData_QM_Data_DtcStatus_QM Rte_Read_SWC_DTCMgr_R_DtcData_QM_Data_DtcStatus_QM
#  define Rte_Read_RoEMessageSRI_Data Rte_Read_SWC_DTCMgr_RoEMessageSRI_Data
#  define Rte_Read_RpAPSMPAOut_TbAP_APSMPAOut_t Rte_Read_SWC_DTCMgr_RpAPSMPAOut_TbAP_APSMPAOut_t
#  define Rte_Read_RpCalDataProviderNvmData_CalData_mcu1_0 Rte_Read_SWC_DTCMgr_RpCalDataProviderNvmData_CalData_mcu1_0
#  define Rte_Read_RpDLDOutput_JobDLDOutput_t Rte_Read_SWC_DTCMgr_RpDLDOutput_JobDLDOutput_t
#  define Rte_Read_RpECUTimeSinceIGON_ECUTimeStamp_IGON Rte_Read_SWC_DTCMgr_RpECUTimeSinceIGON_ECUTimeStamp_IGON
#  define Rte_Read_SWC_DTCMgr_RpECUTimeSinceIGON_ECUTimeStamp_IGON(data) (*(data) = Rte_SWC_DIDMgr_PpECUTimeSinceIGON_ECUTimeStamp_IGON, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpECUTimeStamp_ECUTimeStamp Rte_Read_SWC_DTCMgr_RpECUTimeStamp_ECUTimeStamp
#  define Rte_Read_SWC_DTCMgr_RpECUTimeStamp_ECUTimeStamp(data) (*(data) = Rte_SWC_DIDMgr_PpECUTimeStamp_ECUTimeStamp, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpErrors_B_Errors_B Rte_Read_SWC_DTCMgr_RpErrors_B_Errors_B
#  define Rte_Read_RpErrors_QM_Errors_QM Rte_Read_SWC_DTCMgr_RpErrors_QM_Errors_QM
#  define Rte_Read_RpIgOnCounter_IGCounter Rte_Read_SWC_DTCMgr_RpIgOnCounter_IGCounter
#  define Rte_Read_SWC_DTCMgr_RpIgOnCounter_IGCounter(data) (*(data) = Rte_SWC_DIDMgr_PpIgOnCounter_IGCounter, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpPlantMode_Status Rte_Read_SWC_DTCMgr_RpPlantMode_Status
#  define Rte_Read_SWC_DTCMgr_RpPlantMode_Status(data) (*(data) = Rte_SWC_RIDMgr_PpPlantMode_Status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_Fullautomaticparking Rte_Read_SWC_DTCMgr_RpProxiToSWC_Fullautomaticparking
#  define Rte_Read_SWC_DTCMgr_RpProxiToSWC_Fullautomaticparking(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_Pamtuningset Rte_Read_SWC_DTCMgr_RpProxiToSWC_Pamtuningset
#  define Rte_Read_SWC_DTCMgr_RpProxiToSWC_Pamtuningset(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Pamtuningset, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_SurroundViewCam_u8 Rte_Read_SWC_DTCMgr_RpProxiToSWC_SurroundViewCam_u8
#  define Rte_Read_SWC_DTCMgr_RpProxiToSWC_SurroundViewCam_u8(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_TyreSz_u16 Rte_Read_SWC_DTCMgr_RpProxiToSWC_TyreSz_u16
#  define Rte_Read_SWC_DTCMgr_RpProxiToSWC_TyreSz_u16(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpSystemStateManager_SysM_State Rte_Read_SWC_DTCMgr_RpSystemStateManager_SysM_State
#  define Rte_Read_SWC_DTCMgr_RpSystemStateManager_SysM_State(data) (*(data) = Rte_CDD_GenericBswM_PpSystemStateManager_SysM_State, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_Battery_Volt_1 Rte_Read_SWC_DTCMgr_RpToSwcFD02Rx_Battery_Volt_1
#  define Rte_Read_SWC_DTCMgr_RpToSwcFD02Rx_Battery_Volt_1(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_Battery_Volt_1, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_OperationalModeSts Rte_Read_SWC_DTCMgr_RpToSwcFD02Rx_OperationalModeSts
#  define Rte_Read_SWC_DTCMgr_RpToSwcFD02Rx_OperationalModeSts(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_OperationalModeSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_TRSC_EnableBtn_Sts Rte_Read_SWC_DTCMgr_RpToSwcFD02Rx_TRSC_EnableBtn_Sts
#  define Rte_Read_SWC_DTCMgr_RpToSwcFD02Rx_TRSC_EnableBtn_Sts(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_TRSC_EnableBtn_Sts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_TotalOdometer Rte_Read_SWC_DTCMgr_RpToSwcFD02Rx_TotalOdometer
#  define Rte_Read_SWC_DTCMgr_RpToSwcFD02Rx_TotalOdometer(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Tx_THA_STAT Rte_Read_SWC_DTCMgr_RpToSwcFD02Tx_THA_STAT
#  define Rte_Read_SWC_DTCMgr_RpToSwcFD02Tx_THA_STAT(data) (*(data) = Rte_SWC_VCANTx_PpToSwcFD02Tx_THA_STAT, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Tx_TRSC_STAT Rte_Read_SWC_DTCMgr_RpToSwcFD02Tx_TRSC_STAT
#  define Rte_Read_SWC_DTCMgr_RpToSwcFD02Tx_TRSC_STAT(data) (*(data) = Rte_SWC_VCANTx_PpToSwcFD02Tx_TRSC_STAT, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_APARequestSts Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_APARequestSts
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_APARequestSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_STAT Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_CM_TCH_STAT
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_CM_TCH_STAT(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_X_COORD Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_CM_TCH_X_COORD
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_CM_TCH_X_COORD(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CM_TCH_Y_COORD Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_CM_TCH_Y_COORD
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_CM_TCH_Y_COORD(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CameraDisplaySts2 Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_CameraDisplaySts2
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_CameraDisplaySts2(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_CmdIgnSts
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_CmdIgnSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_DriverDoorSts Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_DriverDoorSts
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_DriverDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_ExternalTemperature Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_ExternalTemperature
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_ExternalTemperature(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_GearEngaged Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_GearEngaged
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_GearEngaged(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_LHRDoorSts Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_LHRDoorSts
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_LHRDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_PsngrDoorSts Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_PsngrDoorSts
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_PsngrDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_RHRDoorSts Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_RHRDoorSts
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_RHRDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_RHatchSts Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_RHatchSts
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_RHatchSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_ShiftLeverPosition Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_ShiftLeverPosition
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_ShiftLeverPosition(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_DisplayView2 Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Tx_DisplayView2
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Tx_DisplayView2(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Tx_ParkingManeuverActive Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Tx_ParkingManeuverActive
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD02Tx_ParkingManeuverActive(data) (*(data) = Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ParkingManeuverActive, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W Rte_Read_SWC_DTCMgr_RpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle Rte_Read_SWC_DTCMgr_RpToSwcSafeFD14Rx_FD14_LwsAngle
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD14Rx_FD14_LwsAngle(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig Rte_Read_SWC_DTCMgr_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig
#  define Rte_Read_SWC_DTCMgr_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PRpDtcSettingClearFlagModeGrp_requestedMode Rte_Write_SWC_DTCMgr_PRpDtcSettingClearFlagModeGrp_requestedMode
#  define Rte_Write_SWC_DTCMgr_PRpDtcSettingClearFlagModeGrp_requestedMode(data) (Rte_SWC_DTCMgr_PRpDtcSettingClearFlagModeGrp_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpDtcB12852AData_v_DtcData_u8 Rte_Write_SWC_DTCMgr_PpDtcB12852AData_v_DtcData_u8
#  define Rte_Write_SWC_DTCMgr_PpDtcB12852AData_v_DtcData_u8(data) (Rte_SWC_DTCMgr_PpDtcB12852AData_v_DtcData_u8 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag Rte_Write_SWC_DTCMgr_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag
#  define Rte_Write_SWC_DTCMgr_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag(data) (Rte_SWC_DTCMgr_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToComFD02Tx_N_PDU Rte_Write_SWC_DTCMgr_PpToComFD02Tx_N_PDU


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CDD_IPCHANDLER_APPL_CODE) RE_IpcTxData(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SetEnableCondition(uint8 parg0, boolean ConditionFulfilled); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetOperationCycleState(uint8 parg0, P2VAR(Dem_OperationCycleStateType, AUTOMATIC, RTE_VAR_NOINIT) CycleState); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_SetOperationCycleState(uint8 parg0, Dem_OperationCycleStateType CycleState); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_SetEventStatus(Dem_EventIdType parg0, Dem_EventStatusType EventStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventUdsStatus(Dem_EventIdType parg0, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_VAR_NOINIT) UDSStatusByte); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SWC_VOLTAGEMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SWC_VOLTAGEMGR_APPL_CODE) RE_VoltageMgr_EtGetADCVoltageInfo(VoltMgr_Enum_VoltageMON Channel_ID, P2VAR(float32, AUTOMATIC, RTE_VAR_NOINIT) Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SWC_VOLTAGEMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_Dem_EnableCondition1_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)1, arg1))
#  define Rte_Call_Dem_EnableCondition10_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)9, arg1))
#  define Rte_Call_Dem_EnableCondition1_4_8_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)2, arg1))
#  define Rte_Call_Dem_EnableCondition1_8_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)3, arg1))
#  define Rte_Call_Dem_EnableCondition2_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)4, arg1))
#  define Rte_Call_Dem_EnableCondition4_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)5, arg1))
#  define Rte_Call_Dem_EnableCondition5_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)6, arg1))
#  define Rte_Call_Dem_EnableCondition7_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)7, arg1))
#  define Rte_Call_Dem_EnableCondition9_SetEnableCondition(arg1) (Dem_SetEnableCondition((uint8)8, arg1))
#  define Rte_Call_Dem_OperationCycle_GetOperationCycleState(arg1) (Dem_GetOperationCycleState((uint8)0, arg1))
#  define Rte_Call_Dem_OperationCycle_SetOperationCycleState(arg1) (Dem_SetOperationCycleState((uint8)0, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DTC_APARequestSts_PAMRequestSts_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)83, arg1))
#  define Rte_Call_RpEventDTC_B12852A_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)57, arg1))
#  define Rte_Call_RpEventDTC_B128E13_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)34, arg1))
#  define Rte_Call_RpEventDTC_B128E92_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)35, arg1))
#  define Rte_Call_RpEventDTC_B128F13_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)36, arg1))
#  define Rte_Call_RpEventDTC_B128F92_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)37, arg1))
#  define Rte_Call_RpEventDTC_B129013_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)38, arg1))
#  define Rte_Call_RpEventDTC_B129092_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)39, arg1))
#  define Rte_Call_RpEventDTC_B129113_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)40, arg1))
#  define Rte_Call_RpEventDTC_B129192_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)41, arg1))
#  define Rte_Call_RpEventDTC_B129213_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)42, arg1))
#  define Rte_Call_RpEventDTC_B129292_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)43, arg1))
#  define Rte_Call_RpEventDTC_B129313_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)44, arg1))
#  define Rte_Call_RpEventDTC_B129392_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)66, arg1))
#  define Rte_Call_RpEventDTC_B129413_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)45, arg1))
#  define Rte_Call_RpEventDTC_B129492_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)46, arg1))
#  define Rte_Call_RpEventDTC_B129513_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)47, arg1))
#  define Rte_Call_RpEventDTC_B129592_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)48, arg1))
#  define Rte_Call_RpEventDTC_B129613_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)49, arg1))
#  define Rte_Call_RpEventDTC_B129692_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)50, arg1))
#  define Rte_Call_RpEventDTC_B129713_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)51, arg1))
#  define Rte_Call_RpEventDTC_B129792_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)52, arg1))
#  define Rte_Call_RpEventDTC_B129813_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)53, arg1))
#  define Rte_Call_RpEventDTC_B129892_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)54, arg1))
#  define Rte_Call_RpEventDTC_B129913_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)55, arg1))
#  define Rte_Call_RpEventDTC_B129992_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)56, arg1))
#  define Rte_Call_RpEventDTC_B12B22A_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)33, arg1))
#  define Rte_Call_RpEventDTC_B210C16_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)2, arg1))
#  define Rte_Call_RpEventDTC_B210C17_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)1, arg1))
#  define Rte_Call_RpEventDTC_B212A08_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)8, arg1))
#  define Rte_Call_RpEventDTC_B212A16_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)10, arg1))
#  define Rte_Call_RpEventDTC_B212A17_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)9, arg1))
#  define Rte_Call_RpEventDTC_B212B08_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)60, arg1))
#  define Rte_Call_RpEventDTC_B212B16_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)62, arg1))
#  define Rte_Call_RpEventDTC_B212B17_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)61, arg1))
#  define Rte_Call_RpEventDTC_B217A1C_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)58, arg1))
#  define Rte_Call_RpEventDTC_B217A92_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)59, arg1))
#  define Rte_Call_RpEventDTC_B223B00_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)65, arg1))
#  define Rte_Call_RpEventDTC_B228600_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)3, arg1))
#  define Rte_Call_RpEventDTC_B22A900_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)5, arg1))
#  define Rte_Call_RpEventDTC_B23C51C_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)6, arg1))
#  define Rte_Call_RpEventDTC_B23C592_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)7, arg1))
#  define Rte_Call_RpEventDTC_B23C61C_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)20, arg1))
#  define Rte_Call_RpEventDTC_B23C692_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)21, arg1))
#  define Rte_Call_RpEventDTC_B23C71C_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)63, arg1))
#  define Rte_Call_RpEventDTC_B23C792_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)64, arg1))
#  define Rte_Call_RpEventDTC_C221200_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)4, arg1))
#  define Rte_Call_RpEventDTC_P060200_SetEventStatus(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_RpEventDTC_U010000_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)23, arg1))
#  define Rte_Call_RpEventDTC_U012900_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)25, arg1))
#  define Rte_Call_RpEventDTC_U013100_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)26, arg1))
#  define Rte_Call_RpEventDTC_U014000_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)24, arg1))
#  define Rte_Call_RpEventDTC_U015100_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)30, arg1))
#  define Rte_Call_RpEventDTC_U018400_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)27, arg1))
#  define Rte_Call_RpEventDTC_U026400_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)31, arg1))
#  define Rte_Call_RpEventDTC_U026500_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)28, arg1))
#  define Rte_Call_RpEventDTC_U026600_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)29, arg1))
#  define Rte_Call_RpEventDTC_U026700_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)32, arg1))
#  define Rte_Call_RpEventDTC_U040100_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)18, arg1))
#  define Rte_Call_RpEventDTC_U041800_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)13, arg1))
#  define Rte_Call_RpEventDTC_U042000_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)19, arg1))
#  define Rte_Call_RpEventDTC_U042200_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)14, arg1))
#  define Rte_Call_RpEventDTC_U045500_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)16, arg1))
#  define Rte_Call_RpEventDTC_U048500_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)15, arg1))
#  define Rte_Call_RpEventDTC_U100B00_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)12, arg1))
#  define Rte_Call_RpEventDTC_U104E00_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)11, arg1))
#  define Rte_Call_RpEventDTC_U104E00_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)11, arg1))
#  define Rte_Call_RpEventDTC_U12B900_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)22, arg1))
#  define Rte_Call_RpEventDTC_U14A000_SetEventStatus(arg1) (Dem_SetEventStatus((Dem_EventIdType)17, arg1))
#  define Rte_Call_RpIpcTxData_IPC_Write_v(arg1, arg2, arg3) (RE_IpcTxData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpReadVoltInfo_GetVoltageInfo(arg1, arg2) (RE_VoltageMgr_EtGetADCVoltageInfo(arg1, arg2), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_DTC_APARequestSts_PAMRequestSts_DefaultValue() (Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DTC_APARequestSts_PAMRequestSts_MirrorBlock() \
  (&Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SWC_DTCMgr_START_SEC_CODE
# include "SWC_DTCMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_ReadData CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_DID_0x1004_Battery_Voltage_24_ReadData CSDataServices_Data_DID_0x1004_Battery_Voltage_24_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_ReadData CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_DID_0x1921_CombinedSignal_ReadData CSDataServices_Data_DID_0x1921_CombinedSignal_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_DID_0x2001_Odometer_24_ReadData CSDataServices_Data_DID_0x2001_Odometer_24_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_ReadData CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_ReadData CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_ReadData CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Calibration_Pending_ReadData CSDataServices_Data_OccurrenceCounter_Calibration_Pending_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Calibration_Running_ReadData CSDataServices_Data_OccurrenceCounter_Calibration_Running_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_ReadData CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Current_Gear_ReadData CSDataServices_Data_OccurrenceCounter_Current_Gear_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_DisplayStatus_ReadData CSDataServices_Data_OccurrenceCounter_DisplayStatus_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Door_Status_ReadData CSDataServices_Data_OccurrenceCounter_Door_Status_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_ECU_Voltage_ReadData CSDataServices_Data_OccurrenceCounter_ECU_Voltage_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_External_Temperature_ReadData CSDataServices_Data_OccurrenceCounter_External_Temperature_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_LiftgateAjar_ReadData CSDataServices_Data_OccurrenceCounter_LiftgateAjar_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_New_Bit_Field_ReadData CSDataServices_Data_OccurrenceCounter_New_Bit_Field_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Odometer_Value_ReadData CSDataServices_Data_OccurrenceCounter_Odometer_Value_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_ReadData CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Reserved_1_ReadData CSDataServices_Data_OccurrenceCounter_Reserved_1_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Reserved_2_ReadData CSDataServices_Data_OccurrenceCounter_Reserved_2_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Reserved_ReadData CSDataServices_Data_OccurrenceCounter_Reserved_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_THA_state_ReadData CSDataServices_Data_OccurrenceCounter_THA_state_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_TRSC_Stat_ReadData CSDataServices_Data_OccurrenceCounter_TRSC_Stat_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_TireLines_ReadData CSDataServices_Data_OccurrenceCounter_TireLines_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_ReadData CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData
#  define RTE_RUNNABLE_CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_ReadData CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_ReadData
#  define RTE_RUNNABLE_RE_ClearDTCSettingStatus RE_ClearDTCSettingStatus
#  define RTE_RUNNABLE_RE_DTCMgr_EtROEMessage RE_DTCMgr_EtROEMessage
#  define RTE_RUNNABLE_RE_DTCMgr_Init RE_DTCMgr_Init
#  define RTE_RUNNABLE_RE_DTCMgr_Main RE_DTCMgr_Main
# endif

# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1004_Battery_Voltage_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1004_Battery_Voltage_24_ReadData(P2VAR(DataArrayType_uint8_1, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_ReadData(P2VAR(DataArrayType_uint8_3, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1921_CombinedSignal_ReadData(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x1921_CombinedSignal_ReadData(P2VAR(DataArrayType_uint8_9, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x2001_Odometer_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x2001_Odometer_24_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_ReadData(P2VAR(DataArrayType_uint8_2, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Calibration_Pending_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Calibration_Running_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Current_Gear_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_DisplayStatus_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Door_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_ECU_Voltage_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_External_Temperature_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_LiftgateAjar_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_New_Bit_Field_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Odometer_Value_ReadData(P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Odometer_Value_ReadData(P2VAR(DataArrayType_uint8_3, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Reserved_1_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Reserved_2_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Reserved_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData(Dem_EventIdType EventId, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_ReadData(Dem_EventIdType EventId, P2VAR(DataArrayType_uint8_9, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_THA_state_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_TRSC_Stat_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_TireLines_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_DTCMgr_CODE) CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_VAR_NOINIT) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SWC_DTCMgr_CODE) RE_ClearDTCSettingStatus(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, SWC_DTCMgr_CODE) RE_DTCMgr_EtROEMessage(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_DTCMgr_CODE) RE_DTCMgr_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_DTCMgr_CODE) RE_DTCMgr_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_DTCMgr_STOP_SEC_CODE
# include "SWC_DTCMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CSDataServices_Data_DID_0x1002_Vehicle_Speed_24_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1004_Battery_Voltage_24_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1008_ECU_Life_Time_24_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1009_ECU_Time_Since_Ignition_ON_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x1921_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x2001_Odometer_24_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_DID_0x200a_Ignition_ON_Counter_24_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Aging_Counter_ID_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Calibrated_Successfully_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Aborted_Failed_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Not_Started_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Pending_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Calibration_Running_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Camera_Occlusion_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Current_Gear_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Cycles_to_Switch_off_the_Warning_Indication_ID_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_DisplayStatus_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Door_Status_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_ECU_Voltage_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_External_Temperature_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Frequency_Counter_ID_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_LiftgateAjar_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_New_Bit_Field_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Odometer_Value_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Radio_Display_Status_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Reserved_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Reserved_1_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Reserved_2_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Steering_Wheel_Angle_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Supplier_Internal_Code_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_THA_state_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_TRSC_Stat_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_TRSKM_and_USS_status_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_TireLines_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Touch_Screen_Status_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Touch_Screen_X_Coordinate_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Touch_Screen_Y_Coordinate_E_NOT_OK (1U)

#  define RTE_E_CSDataServices_Data_OccurrenceCounter_Vehicle_Speed_E_NOT_OK (1U)

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_EnableCondition_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_NOT_OK (1U)

#  define RTE_E_OperationCycle_E_OK (0U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_DTCMGR_H */

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
