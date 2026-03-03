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
 *             File:  Rte_CDD_GenericBswM.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <CDD_GenericBswM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_GENERICBSWM_H
# define RTE_CDD_GENERICBSWM_H

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

# include "Rte_CDD_GenericBswM_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpBSWM_PostRunRequest_0_requestedMode;
extern VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpBSWM_PostRunRequest_1_requestedMode;
extern VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpBSWM_RunRequest_0_requestedMode;
extern VAR(BswM_ESH_RunRequest, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpBSWM_RunRequest_1_requestedMode;
extern VAR(BswM_BswM_PreviousNMState, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpBswM_PreviousNMState_requestedMode;
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpGetFirstDTCStatus_DeFirstDTCStatus;
extern VAR(boolean, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpNmStateInfo_v_IsNmStateNormal_b;
extern VAR(SystemState, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpSystemStateManager_SysM_State;
extern VAR(CurrentCanNMState_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_CurrentCanNMState_FD02_PAM;
extern VAR(CurrentFailSts_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_CurrentFailSts_FD02_PAM;
extern VAR(DES_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_DES_FD02_PAM;
extern VAR(GenericFailSts_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_GenericFailSts_FD02_PAM;
extern VAR(PreviousCanNMState_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_PreviousCanNMState_FD02_PAM;
extern VAR(WakeupSource_FD02_PAM, RTE_VAR_INIT) Rte_CDD_GenericBswM_PpToComFD02Tx_WakeupSource_FD02_PAM;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpSleepProcessState_status;
extern VAR(TotalOdometer, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer;
extern VAR(udtBatteryVoltageStatus, RTE_VAR_INIT) Rte_SWC_VoltageMgr_PpVoltageChannelStatus_BatteryVoltageStatus;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiReset_ProxiDataflag_b;
extern VAR(CmdIgnSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpBswM_PreviousNMState_requestedMode (0U)
#  define Rte_InitValue_PpGetFirstDTCStatus_DeFirstDTCStatus (FALSE)
#  define Rte_InitValue_PpNmStateInfo_v_IsNmStateNormal_b (FALSE)
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
#  define Rte_InitValue_RpProxiReset_ProxiDataflag_b (FALSE)
#  define Rte_InitValue_RpSleepProcessState_status (0U)
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
#  define Rte_InitValue_RpVoltageChannelStatus_BatteryVoltageStatus (0U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_OsApplication_QM_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(ChangeSYSState_t, RTE_VAR_INIT) Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq;
extern VAR(uint16, RTE_VAR_INIT) Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState;

#  define RTE_STOP_SEC_VAR_OsApplication_QM_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_GenericBswM_PpToComFD02Tx_StayActiveSource_FD02_PAM(P2CONST(Rte_DT_StayActiveSource_FD02_PAM_0, AUTOMATIC, RTE_CDD_GENERICBSWM_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_GenericBswM_PpToComFD02Tx_StayActiveSource_FD02_PAM(P2CONST(StayActiveSource_FD02_PAM, AUTOMATIC, RTE_CDD_GENERICBSWM_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(uint8, RTE_CODE) Rte_Mode_CDD_GenericBswM_RpNM_State_Mode(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_CDD_GenericBswM_PpDiagRequestNtfy_SYSModeRequestType(uint8 nextMode);

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RpProxiReset_ProxiDataflag_b Rte_Read_CDD_GenericBswM_RpProxiReset_ProxiDataflag_b
#  define Rte_Read_CDD_GenericBswM_RpProxiReset_ProxiDataflag_b(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiReset_ProxiDataflag_b, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpSleepProcessState_status Rte_Read_CDD_GenericBswM_RpSleepProcessState_status
#  define Rte_Read_CDD_GenericBswM_RpSleepProcessState_status(data) (*(data) = Rte_SWC_DIDMgr_PpSleepProcessState_status, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_TotalOdometer Rte_Read_CDD_GenericBswM_RpToSwcFD02Rx_TotalOdometer
#  define Rte_Read_CDD_GenericBswM_RpToSwcFD02Rx_TotalOdometer(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts Rte_Read_CDD_GenericBswM_RpToSwcSafeFD02Rx_CmdIgnSts
#  define Rte_Read_CDD_GenericBswM_RpToSwcSafeFD02Rx_CmdIgnSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpVoltageChannelStatus_BatteryVoltageStatus Rte_Read_CDD_GenericBswM_RpVoltageChannelStatus_BatteryVoltageStatus
#  define Rte_Read_CDD_GenericBswM_RpVoltageChannelStatus_BatteryVoltageStatus(data) (*(data) = Rte_SWC_VoltageMgr_PpVoltageChannelStatus_BatteryVoltageStatus, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpBSWM_PostRunRequest_0_requestedMode Rte_Write_CDD_GenericBswM_PpBSWM_PostRunRequest_0_requestedMode
#  define Rte_Write_CDD_GenericBswM_PpBSWM_PostRunRequest_0_requestedMode(data) (Rte_CDD_GenericBswM_PpBSWM_PostRunRequest_0_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpBSWM_PostRunRequest_1_requestedMode Rte_Write_CDD_GenericBswM_PpBSWM_PostRunRequest_1_requestedMode
#  define Rte_Write_CDD_GenericBswM_PpBSWM_PostRunRequest_1_requestedMode(data) (Rte_CDD_GenericBswM_PpBSWM_PostRunRequest_1_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpBSWM_RunRequest_0_requestedMode Rte_Write_CDD_GenericBswM_PpBSWM_RunRequest_0_requestedMode
#  define Rte_Write_CDD_GenericBswM_PpBSWM_RunRequest_0_requestedMode(data) (Rte_CDD_GenericBswM_PpBSWM_RunRequest_0_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpBSWM_RunRequest_1_requestedMode Rte_Write_CDD_GenericBswM_PpBSWM_RunRequest_1_requestedMode
#  define Rte_Write_CDD_GenericBswM_PpBSWM_RunRequest_1_requestedMode(data) (Rte_CDD_GenericBswM_PpBSWM_RunRequest_1_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpBswM_PreviousNMState_requestedMode Rte_Write_CDD_GenericBswM_PpBswM_PreviousNMState_requestedMode
#  define Rte_Write_CDD_GenericBswM_PpBswM_PreviousNMState_requestedMode(data) (Rte_CDD_GenericBswM_PpBswM_PreviousNMState_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpGetFirstDTCStatus_DeFirstDTCStatus Rte_Write_CDD_GenericBswM_PpGetFirstDTCStatus_DeFirstDTCStatus
#  define Rte_Write_CDD_GenericBswM_PpGetFirstDTCStatus_DeFirstDTCStatus(data) (Rte_CDD_GenericBswM_PpGetFirstDTCStatus_DeFirstDTCStatus = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpNmStateInfo_v_IsNmStateNormal_b Rte_Write_CDD_GenericBswM_PpNmStateInfo_v_IsNmStateNormal_b
#  define Rte_Write_CDD_GenericBswM_PpNmStateInfo_v_IsNmStateNormal_b(data) (Rte_CDD_GenericBswM_PpNmStateInfo_v_IsNmStateNormal_b = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpSystemStateManager_SysM_State Rte_Write_CDD_GenericBswM_PpSystemStateManager_SysM_State
#  define Rte_Write_CDD_GenericBswM_PpSystemStateManager_SysM_State(data) (Rte_CDD_GenericBswM_PpSystemStateManager_SysM_State = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToComFD02Tx_CurrentCanNMState_FD02_PAM Rte_Write_CDD_GenericBswM_PpToComFD02Tx_CurrentCanNMState_FD02_PAM
#  define Rte_Write_CDD_GenericBswM_PpToComFD02Tx_CurrentCanNMState_FD02_PAM(data) (Rte_CDD_GenericBswM_PpToComFD02Tx_CurrentCanNMState_FD02_PAM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToComFD02Tx_CurrentFailSts_FD02_PAM Rte_Write_CDD_GenericBswM_PpToComFD02Tx_CurrentFailSts_FD02_PAM
#  define Rte_Write_CDD_GenericBswM_PpToComFD02Tx_CurrentFailSts_FD02_PAM(data) (Rte_CDD_GenericBswM_PpToComFD02Tx_CurrentFailSts_FD02_PAM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToComFD02Tx_DES_FD02_PAM Rte_Write_CDD_GenericBswM_PpToComFD02Tx_DES_FD02_PAM
#  define Rte_Write_CDD_GenericBswM_PpToComFD02Tx_DES_FD02_PAM(data) (Rte_CDD_GenericBswM_PpToComFD02Tx_DES_FD02_PAM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToComFD02Tx_GenericFailSts_FD02_PAM Rte_Write_CDD_GenericBswM_PpToComFD02Tx_GenericFailSts_FD02_PAM
#  define Rte_Write_CDD_GenericBswM_PpToComFD02Tx_GenericFailSts_FD02_PAM(data) (Rte_CDD_GenericBswM_PpToComFD02Tx_GenericFailSts_FD02_PAM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToComFD02Tx_PreviousCanNMState_FD02_PAM Rte_Write_CDD_GenericBswM_PpToComFD02Tx_PreviousCanNMState_FD02_PAM
#  define Rte_Write_CDD_GenericBswM_PpToComFD02Tx_PreviousCanNMState_FD02_PAM(data) (Rte_CDD_GenericBswM_PpToComFD02Tx_PreviousCanNMState_FD02_PAM = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToComFD02Tx_StayActiveSource_FD02_PAM Rte_Write_CDD_GenericBswM_PpToComFD02Tx_StayActiveSource_FD02_PAM
#  define Rte_Write_PpToComFD02Tx_WakeupSource_FD02_PAM Rte_Write_CDD_GenericBswM_PpToComFD02Tx_WakeupSource_FD02_PAM
#  define Rte_Write_CDD_GenericBswM_PpToComFD02Tx_WakeupSource_FD02_PAM(data) (Rte_CDD_GenericBswM_PpToComFD02Tx_WakeupSource_FD02_PAM = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_RpNM_State_Mode Rte_Mode_CDD_GenericBswM_RpNM_State_Mode


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_PpDiagRequestNtfy_SYSModeRequestType Rte_Switch_CDD_GenericBswM_PpDiagRequestNtfy_SYSModeRequestType


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_PMIC_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUReadDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUReadDeviceRegData(DeviceAddress DeviceAdd, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) RegAddress); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUWriteDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress, uint16 RegData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_PMIC_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_COMM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_COMM_APPL_CODE) ComM_RequestComMode(ComM_UserHandleType parg0, ComM_ModeType ComMode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_COMM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DCM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DCM_APPL_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_VAR_NOINIT) SesCtrlType); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DCM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DEMMASTER_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DEMMASTER_0_APPL_CODE) Dem_GetEventUdsStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_VAR_NOINIT) UDSStatusByte); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DEMMASTER_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERRORMGRSAT_1_0_QM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_ERRORMGRSAT_1_0_QM_APPL_CODE) RE_ReportErrorStatus1_0_QM(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, P2CONST(ErrorMgr_stAddData, AUTOMATIC, RTE_VAR_NOINIT) addData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERRORMGRSAT_1_0_QM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_GeneralDiagnosticInfo_GetEventUdsStatus Dem_GetEventUdsStatus
#  define Rte_Call_RpComM_UserRequest_FDCAN14_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)0, arg1))
#  define Rte_Call_RpComM_UserRequest_FDCAN2_RequestComMode(arg1) (ComM_RequestComMode((ComM_UserHandleType)1, arg1))
#  define Rte_Call_RpDCMServices_GetSesCtrlType Dcm_GetSesCtrlType
#  define Rte_Call_RpError_CS_ReportErrorStatus1_0_QM RE_ReportErrorStatus1_0_QM
#  define Rte_Call_RpMCUDeviceRegReadWrite_MCUReadDeviceReg RE_MCUReadDeviceReg
#  define Rte_Call_RpMCUDeviceRegReadWrite_MCUReadDeviceRegData RE_MCUReadDeviceRegData
#  define Rte_Call_RpMCUDeviceRegReadWrite_MCUWriteDeviceReg RE_MCUWriteDeviceReg

/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RE_GenBswSysMgr_Init_Irv_ChangeSYSStateReq() \
  Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RE_GenBswSysMgr_Init_Irv_PreviousNMState() \
  Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RE_GenBswSysMgr_Init_Irv_ChangeSYSStateReq(data) \
  (Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RE_GenBswSysMgr_Init_Irv_PreviousNMState(data) \
  (Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RE_GenBswSysMgr_Main_Irv_ChangeSYSStateReq() \
  Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RE_GenBswSysMgr_Main_Irv_PreviousNMState() \
  Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RE_GenBswSysMgr_Main_Irv_ChangeSYSStateReq(data) \
  (Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RE_GenBswSysMgr_Main_Irv_PreviousNMState(data) \
  (Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RE_GenericBswM_HARDResetReq_Irv_ChangeSYSStateReq() \
  Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RE_GenericBswM_HARDResetReq_Irv_PreviousNMState() \
  Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RE_GenericBswM_HARDResetReq_Irv_ChangeSYSStateReq(data) \
  (Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RE_GenericBswM_HARDResetReq_Irv_PreviousNMState(data) \
  (Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RE_GenericBswM_JumpToBootReq_Irv_ChangeSYSStateReq() \
  Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RE_GenericBswM_JumpToBootReq_Irv_PreviousNMState() \
  Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RE_GenericBswM_JumpToBootReq_Irv_ChangeSYSStateReq(data) \
  (Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RE_GenericBswM_JumpToBootReq_Irv_PreviousNMState(data) \
  (Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RE_UpdateNMState_Irv_ChangeSYSStateReq() \
  Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_RE_UpdateNMState_Irv_PreviousNMState() \
  Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RE_UpdateNMState_Irv_ChangeSYSStateReq(data) \
  (Rte_Irv_CDD_GenericBswM_Irv_ChangeSYSStateReq = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_RE_UpdateNMState_Irv_PreviousNMState(data) \
  (Rte_Irv_CDD_GenericBswM_Irv_PreviousNMState = (data))
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define CDD_GenericBswM_START_SEC_CODE
# include "CDD_GenericBswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_GenBswSysMgr_Init RE_GenBswSysMgr_Init
#  define RTE_RUNNABLE_RE_GenBswSysMgr_Main RE_GenBswSysMgr_Main
#  define RTE_RUNNABLE_RE_GenericBswM_HARDResetReq RE_GenericBswM_HARDResetReq
#  define RTE_RUNNABLE_RE_GenericBswM_JumpToBootReq RE_GenericBswM_JumpToBootReq
#  define RTE_RUNNABLE_RE_UpdateNMState RE_UpdateNMState
# endif

FUNC(void, CDD_GenericBswM_CODE) RE_GenBswSysMgr_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CDD_GenericBswM_CODE) RE_GenBswSysMgr_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CDD_GenericBswM_CODE) RE_GenericBswM_HARDResetReq(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CDD_GenericBswM_CODE) RE_GenericBswM_JumpToBootReq(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CDD_GenericBswM_CODE) RE_UpdateNMState(Rte_ActivatingEvent_RE_UpdateNMState activationVector); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define CDD_GenericBswM_STOP_SEC_CODE
# include "CDD_GenericBswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_ComM_UserRequest_E_MODE_LIMITATION (2U)

#  define RTE_E_ComM_UserRequest_E_NOT_OK (1U)

#  define RTE_E_DCMServices_E_OK (0U)

#  define RTE_E_GeneralDiagnosticInfo_E_NOT_OK (1U)

#  define RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK (1U)

#  define RTE_E_P_Error_CS_E_NOK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_GENERICBSWM_H */

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
