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
 *             File:  Rte_SWC_RIDMgr.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_RIDMgr>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_RIDMGR_H
# define RTE_SWC_RIDMGR_H

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

# include "Rte_SWC_RIDMgr_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpCalibRoutineTrigger_routine_b;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpCalibRoutineType_value;
extern VAR(CanDebugMode_t, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpCan14DbgRoutineState_Can14DbgRoutine;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpFailSafeReaction_State;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpPlantMode_Status;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DTCMgr_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpVINData_VINLockStatus;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpVINData_VINOdoCounter;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_VoltageMgr_PpTemperatureVal_GetTemperatureVal;
extern VAR(TotalOdometer, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PRX_CanNod27_b;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8;
extern VAR(ASCM_Stat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat;
extern VAR(CmdIgnSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts;
extern VAR(DriverDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts;
extern VAR(GearEngaged, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged;
extern VAR(LHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts;
extern VAR(PsngrDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts;
extern VAR(RHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts;
extern VAR(RHatchSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts;
extern VAR(ShiftLeverPosition, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition;
extern VAR(VIN_MSG, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG;
extern VAR(FD14_LwsAngle, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpCalibRoutineTrigger_routine_b (FALSE)
#  define Rte_InitValue_PpCalibRoutineType_value (0U)
#  define Rte_InitValue_PpCan14DbgRoutineState_Can14DbgRoutine (0U)
#  define Rte_InitValue_PpFailSafeReaction_State (FALSE)
#  define Rte_InitValue_PpPlantMode_Status (0U)
#  define Rte_InitValue_PpSnsrFnctnlTstFlg_SensorFunctionalTestFlag (TRUE)
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_RIDMgr_R_SSM_2_State_State_2_0(P2VAR(SSM_2_0_CoreStatus, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_RIDMgr_R_SSM_2_State_State_2_1(P2VAR(SSM_2_1_CoreStatus, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_RIDMgr_RpCalDataProviderNvmData_CalData_mcu1_0(P2VAR(CalDataProvider_MCU_1_0_Def, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_RIDMgr_RpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(P2VAR(TbSVS_e_SVSOutputToDiagMgrCamCalib_t, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_RIDMgr_RpSVSToDiag_SVSToDiag_t(P2VAR(SVSToDiag_t, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_VIN_DATA(P2VAR(uint8, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_VIN_DATA(P2VAR(VIN_DATA, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_RIDMgr_RpTrailerDetectOP_TrailerDetection_Output_DID_t(P2VAR(TrailerDetection_Output_DID_t, AUTOMATIC, RTE_SWC_RIDMGR_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_RIDMgr_PpVINData_VINCurrentData(P2CONST(uint8, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_RIDMgr_PpVINData_VINCurrentData(P2CONST(VINlData_Arr, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_RIDMgr_PpVINData_VINOriginalData(P2CONST(uint8, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_RIDMgr_PpVINData_VINOriginalData(P2CONST(VINlData_Arr, AUTOMATIC, RTE_SWC_RIDMGR_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_SWC_RIDMgr_PpModeProgPreconditionCheck_ModeProgPreconditionCheck(uint8 nextMode);

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_SSM_2_State_State_2_0 Rte_Read_SWC_RIDMgr_R_SSM_2_State_State_2_0
#  define Rte_Read_R_SSM_2_State_State_2_1 Rte_Read_SWC_RIDMgr_R_SSM_2_State_State_2_1
#  define Rte_Read_RpCalDataProviderNvmData_CalData_mcu1_0 Rte_Read_SWC_RIDMgr_RpCalDataProviderNvmData_CalData_mcu1_0
#  define Rte_Read_RpProxiToSWC_PRX_CanNod27_b Rte_Read_SWC_RIDMgr_RpProxiToSWC_PRX_CanNod27_b
#  define Rte_Read_SWC_RIDMgr_RpProxiToSWC_PRX_CanNod27_b(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PRX_CanNod27_b, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpProxiToSWC_SurroundViewCam_u8 Rte_Read_SWC_RIDMgr_RpProxiToSWC_SurroundViewCam_u8
#  define Rte_Read_SWC_RIDMgr_RpProxiToSWC_SurroundViewCam_u8(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t Rte_Read_SWC_RIDMgr_RpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t
#  define Rte_Read_RpSVSToDiag_SVSToDiag_t Rte_Read_SWC_RIDMgr_RpSVSToDiag_SVSToDiag_t
#  define Rte_Read_RpTemperatureVal_GetTemperatureVal Rte_Read_SWC_RIDMgr_RpTemperatureVal_GetTemperatureVal
#  define Rte_Read_SWC_RIDMgr_RpTemperatureVal_GetTemperatureVal(data) (*(data) = Rte_SWC_VoltageMgr_PpTemperatureVal_GetTemperatureVal, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_TotalOdometer Rte_Read_SWC_RIDMgr_RpToSwcFD02Rx_TotalOdometer
#  define Rte_Read_SWC_RIDMgr_RpToSwcFD02Rx_TotalOdometer(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_ASCM_Stat Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_ASCM_Stat
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_ASCM_Stat(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_CmdIgnSts Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_CmdIgnSts
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_CmdIgnSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_DriverDoorSts Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_DriverDoorSts
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_DriverDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_GearEngaged Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_GearEngaged
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_GearEngaged(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_LHRDoorSts Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_LHRDoorSts
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_LHRDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_PsngrDoorSts Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_PsngrDoorSts
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_PsngrDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_RHRDoorSts Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_RHRDoorSts
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_RHRDoorSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_RHatchSts Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_RHatchSts
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_RHatchSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_ShiftLeverPosition Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_ShiftLeverPosition
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_ShiftLeverPosition(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_VIN_DATA Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_VIN_DATA
#  define Rte_Read_RpToSwcSafeFD02Rx_VIN_MSG Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_VIN_MSG
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD02Rx_VIN_MSG(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_LwsAngle Rte_Read_SWC_RIDMgr_RpToSwcSafeFD14Rx_FD14_LwsAngle
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD14Rx_FD14_LwsAngle(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig Rte_Read_SWC_RIDMgr_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig
#  define Rte_Read_SWC_RIDMgr_RpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpTrailerDetectOP_TrailerDetection_Output_DID_t Rte_Read_SWC_RIDMgr_RpTrailerDetectOP_TrailerDetection_Output_DID_t


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpCalibRoutineTrigger_routine_b Rte_Write_SWC_RIDMgr_PpCalibRoutineTrigger_routine_b
#  define Rte_Write_SWC_RIDMgr_PpCalibRoutineTrigger_routine_b(data) (Rte_SWC_RIDMgr_PpCalibRoutineTrigger_routine_b = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpCalibRoutineType_value Rte_Write_SWC_RIDMgr_PpCalibRoutineType_value
#  define Rte_Write_SWC_RIDMgr_PpCalibRoutineType_value(data) (Rte_SWC_RIDMgr_PpCalibRoutineType_value = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpCan14DbgRoutineState_Can14DbgRoutine Rte_Write_SWC_RIDMgr_PpCan14DbgRoutineState_Can14DbgRoutine
#  define Rte_Write_SWC_RIDMgr_PpCan14DbgRoutineState_Can14DbgRoutine(data) (Rte_SWC_RIDMgr_PpCan14DbgRoutineState_Can14DbgRoutine = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpFailSafeReaction_State Rte_Write_SWC_RIDMgr_PpFailSafeReaction_State
#  define Rte_Write_SWC_RIDMgr_PpFailSafeReaction_State(data) (Rte_SWC_RIDMgr_PpFailSafeReaction_State = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpPlantMode_Status Rte_Write_SWC_RIDMgr_PpPlantMode_Status
#  define Rte_Write_SWC_RIDMgr_PpPlantMode_Status(data) (Rte_SWC_RIDMgr_PpPlantMode_Status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpSnsrFnctnlTstFlg_SensorFunctionalTestFlag Rte_Write_SWC_RIDMgr_PpSnsrFnctnlTstFlg_SensorFunctionalTestFlag
#  define Rte_Write_SWC_RIDMgr_PpSnsrFnctnlTstFlg_SensorFunctionalTestFlag(data) (Rte_SWC_DTCMgr_PpRpSnsrFnctnlTstFlg_SensorFunctionalTestFlag = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpVINData_VINCurrentData Rte_Write_SWC_RIDMgr_PpVINData_VINCurrentData
#  define Rte_Write_PpVINData_VINLockStatus Rte_Write_SWC_RIDMgr_PpVINData_VINLockStatus
#  define Rte_Write_SWC_RIDMgr_PpVINData_VINLockStatus(data) (Rte_SWC_RIDMgr_PpVINData_VINLockStatus = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpVINData_VINOdoCounter Rte_Write_SWC_RIDMgr_PpVINData_VINOdoCounter
#  define Rte_Write_SWC_RIDMgr_PpVINData_VINOdoCounter(data) (Rte_SWC_RIDMgr_PpVINData_VINOdoCounter = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpVINData_VINOriginalData Rte_Write_SWC_RIDMgr_PpVINData_VINOriginalData


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_PpModeProgPreconditionCheck_ModeProgPreconditionCheck Rte_Switch_SWC_RIDMgr_PpModeProgPreconditionCheck_ModeProgPreconditionCheck


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CDD_IPCHANDLER_APPL_CODE) RE_IpcTxData(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CDD_PMIC_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUReadDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUReadDeviceRegData(DeviceAddress DeviceAdd, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) RegAddress); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CDD_PMIC_APPL_CODE) RE_MCUWriteDeviceReg(DeviceAddress DeviceAdd, uint16 RegAddress, uint16 RegData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_PMIC_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CALDATAPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CALDATAPROVIDER_APPL_CODE) RE_CalDataProvider_Nvm_SVSCamCalibReset(P2CONST(TbSVS_S_SVSCamCalibReset_t, AUTOMATIC, RTE_VAR_NOINIT) v_SVSCamCalibReset); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CALDATAPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DEMSATELLITE_0_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_DEMSATELLITE_0_APPL_CODE) Dem_GetEventUdsStatus(Dem_EventIdType parg0, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_VAR_NOINIT) UDSStatusByte); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DEMSATELLITE_0_APPL_CODE
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

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_VAR_NOINIT) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SWC_VOLTAGEMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_SWC_VOLTAGEMGR_APPL_CODE) RE_VoltageMgr_EtGetADCVoltageInfo(VoltMgr_Enum_VoltageMON Channel_ID, P2VAR(float32, AUTOMATIC, RTE_VAR_NOINIT) Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SWC_VOLTAGEMGR_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_DID_5201_PlantModeStatus_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)42, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_DID_5201_PlantModeStatus_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)42, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_VIN_CurrentVal_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)43, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_VIN_CurrentVal_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)43, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_VIN_Lock_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)44, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_VIN_Lock_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)44, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_VIN_OdometerCnt_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)45, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_VIN_OdometerCnt_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)45, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_VIN_OriginalVal_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)26, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_VIN_OriginalVal_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)26, arg1))
#  define Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B RE_ReportErrorStatus1_0_B
#  define Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM RE_ReportErrorStatus1_0_QM
#  define Rte_Call_RpEventDTC_B217A1C_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)58, arg1))
#  define Rte_Call_RpEventDTC_B217A92_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)59, arg1))
#  define Rte_Call_RpEventDTC_B23C51C_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)6, arg1))
#  define Rte_Call_RpEventDTC_B23C592_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)7, arg1))
#  define Rte_Call_RpEventDTC_B23C61C_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)20, arg1))
#  define Rte_Call_RpEventDTC_B23C692_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)21, arg1))
#  define Rte_Call_RpEventDTC_B23C71C_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)63, arg1))
#  define Rte_Call_RpEventDTC_B23C792_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)64, arg1))
#  define Rte_Call_RpEventDTC_U026400_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)31, arg1))
#  define Rte_Call_RpEventDTC_U026500_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)28, arg1))
#  define Rte_Call_RpEventDTC_U026600_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)29, arg1))
#  define Rte_Call_RpEventDTC_U026700_GetEventStatus(arg1) (Dem_GetEventUdsStatus((Dem_EventIdType)32, arg1))
#  define Rte_Call_RpIpcTxData_IPC_Write_v(arg1, arg2, arg3) (RE_IpcTxData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpMCUDeviceRegReadWrit_MCUReadDeviceReg RE_MCUReadDeviceReg
#  define Rte_Call_RpMCUDeviceRegReadWrit_MCUReadDeviceRegData RE_MCUReadDeviceRegData
#  define Rte_Call_RpMCUDeviceRegReadWrit_MCUWriteDeviceReg RE_MCUWriteDeviceReg
#  define Rte_Call_RpReadVoltInfo_GetVoltageInfo(arg1, arg2) (RE_VoltageMgr_EtGetADCVoltageInfo(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpSVSCamCalibReset_WriteBlock RE_CalDataProvider_Nvm_SVSCamCalibReset

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_Lock_DefaultValue;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_OdometerCnt_DefaultValue;
extern CONST(VINlData_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_CurrentVal_DefaultValue;
extern CONST(VINlData_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_OriginalVal_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_DID_5201_PlantModeStatus_DefaultValue() (Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_DefaultValue)

#  define Rte_CData_VIN_Lock_DefaultValue() (Rte_SWC_RIDMgr_VIN_Lock_DefaultValue)

#  define Rte_CData_VIN_OdometerCnt_DefaultValue() (Rte_SWC_RIDMgr_VIN_OdometerCnt_DefaultValue)

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_VIN_CurrentVal_DefaultValue() (&(Rte_SWC_RIDMgr_VIN_CurrentVal_DefaultValue[0]))
#  else
#   define Rte_CData_VIN_CurrentVal_DefaultValue() (&Rte_SWC_RIDMgr_VIN_CurrentVal_DefaultValue)
#  endif

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_CData_VIN_OriginalVal_DefaultValue() (&(Rte_SWC_RIDMgr_VIN_OriginalVal_DefaultValue[0]))
#  else
#   define Rte_CData_VIN_OriginalVal_DefaultValue() (&Rte_SWC_RIDMgr_VIN_OriginalVal_DefaultValue)
#  endif

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_RIDMgr_VIN_Lock_MirrorBlock;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_RIDMgr_VIN_OdometerCnt_MirrorBlock;
extern VAR(VINlData_Arr, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_RIDMgr_VIN_CurrentVal_MirrorBlock;
extern VAR(VINlData_Arr, RTE_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP) Rte_SWC_RIDMgr_VIN_OriginalVal_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_QM_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_DID_5201_PlantModeStatus_MirrorBlock() \
  (&Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_VIN_Lock_MirrorBlock() \
  (&Rte_SWC_RIDMgr_VIN_Lock_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_VIN_OdometerCnt_MirrorBlock() \
  (&Rte_SWC_RIDMgr_VIN_OdometerCnt_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_VIN_CurrentVal_MirrorBlock() (&((*RtePim_VIN_CurrentVal_MirrorBlock())[0]))
#  else
#   define Rte_Pim_VIN_CurrentVal_MirrorBlock() RtePim_VIN_CurrentVal_MirrorBlock()
#  endif
#  define RtePim_VIN_CurrentVal_MirrorBlock() \
  (&Rte_SWC_RIDMgr_VIN_CurrentVal_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
#   define Rte_Pim_VIN_OriginalVal_MirrorBlock() (&((*RtePim_VIN_OriginalVal_MirrorBlock())[0]))
#  else
#   define Rte_Pim_VIN_OriginalVal_MirrorBlock() RtePim_VIN_OriginalVal_MirrorBlock()
#  endif
#  define RtePim_VIN_OriginalVal_MirrorBlock() \
  (&Rte_SWC_RIDMgr_VIN_OriginalVal_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define SWC_RIDMgr_START_SEC_CODE
# include "SWC_RIDMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_RIDMgr_Main RE_RIDMgr_Main
#  define RTE_RUNNABLE_RE_RIDMgrr_Init RE_RIDMgrr_Init
#  define RTE_RUNNABLE_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_31012000_Original_VIN_Lock_Start RoutineServices_Routine_31012000_Original_VIN_Lock_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_31012001_Original_VIN_Unlock_Start RoutineServices_Routine_31012001_Original_VIN_Unlock_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults
#  define RTE_RUNNABLE_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults
#  define RTE_RUNNABLE_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults
#  define RTE_RUNNABLE_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults
#  define RTE_RUNNABLE_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop
#  define RTE_RUNNABLE_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start
#  define RTE_RUNNABLE_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop
#  define RTE_RUNNABLE_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start
# endif

FUNC(void, SWC_RIDMgr_CODE) RE_RIDMgr_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_RIDMgr_CODE) RE_RIDMgrr_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31012000_Original_VIN_Lock_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31012001_Original_VIN_Unlock_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31013000_XCP_Enable_Disable_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31013000_XCP_Enable_Disable_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015000_Park_Assist_ON_OFF_State_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015200_Plant_Mode_Routine_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015200_Plant_Mode_Routine_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015400_Camera_EOL_Calibration_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015400_Camera_EOL_Calibration_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_Start(P2CONST(Dcm_StartDataIn_Routine_31015401_Camera_Service_Calibration_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015401_Camera_Service_Calibration_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartFlexibleOutArrayData_Routine_3101D002_Check_Programming_Preconditions_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(uint16, AUTOMATIC, RTE_VAR_NOINIT) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE01_Calibration_Data_Reset_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FE01_Calibration_Data_Reset_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE02_Test_Write_PMIC_Register_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FE0E_Test_Pattern_Control_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FE0E_Test_Pattern_Control_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataArrayType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, SWC_RIDMgr_CODE) RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_Start(P2CONST(Dcm_StartDataIn_Routine_3101FF03_Test_Read_PMIC_Register_Start_In_ReqDataType, AUTOMATIC, RTE_VAR_NOINIT) In_ReqData, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_3101FF03_Test_Read_PMIC_Register_Start_Out_ResDataType, AUTOMATIC, RTE_VAR_NOINIT) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_VAR_NOINIT) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define SWC_RIDMgr_STOP_SEC_CODE
# include "SWC_RIDMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DiagnosticMonitor_E_NOT_OK (1U)

#  define RTE_E_IF_MCUDeviceRegReadWrite_E_NOT_OK (1U)

#  define RTE_E_IF_SVSCamCalibReset_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_P_Error_CS_E_NOK (1U)

#  define RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31011000_USS_Debug_Signals_Enable_Disable_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31012000_Original_VIN_Lock_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31012001_Original_VIN_Unlock_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31012001_Original_VIN_Unlock_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31012001_Original_VIN_Unlock_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31013000_XCP_Enable_Disable_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015000_Park_Assist_ON_OFF_State_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015101_Sensor_Functional_Test_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015200_Plant_Mode_Routine_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015400_Camera_EOL_Calibration_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015401_Camera_Service_Calibration_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_31015502_TRSC_Trailer_Calibration_Memory_Clear_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101D001_Disable_Fail_safe_reaction_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101D002_Check_Programming_Preconditions_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101FE01_Calibration_Data_Reset_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101FE02_Test_Write_PMIC_Register_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101FE0E_Test_Pattern_Control_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_3101FF03_Test_Read_PMIC_Register_Start_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_RIDMGR_H */

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
