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
 *             File:  Rte_SWC_VCANRx.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_VCANRx>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_VCANRX_H
# define RTE_SWC_VCANRX_H

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

# include "Rte_SWC_VCANRx_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_VCANRx_PpBusOffIndication_V_BusOffIndicationFlagRte_u8;
extern VAR(Battery_Volt_1, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_Battery_Volt_1;
extern VAR(EPBSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_EPBSts;
extern VAR(IgnitionOnCounter, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_IgnitionOnCounter;
extern VAR(OperationalModeSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_OperationalModeSts;
extern VAR(RemStActvSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_RemStActvSts;
extern VAR(TRSC_EnableBtn_Sts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TRSC_EnableBtn_Sts;
extern VAR(TotalOdometer, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer;
extern VAR(TurnIndicatorSts, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TurnIndicatorSts;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpFailSafeReaction_State;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpGearPosition_GearValue;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpGearPosition_ShortTermAdjActiveFlag_b;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(ITBM_TrlrStat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ITBM_TrlrStat;
extern VAR(TrailerConnectionSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpBusOffIndication_V_BusOffIndicationFlagRte_u8 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Altitude_RMSE_C2 (128U)
#  define Rte_InitValue_PpToSwcFD02Rx_BSM_THA_Brk_Resp (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Battery_Volt_1 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD01_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD01_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD02_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD02_BSM2 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD02_CADM2 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD02_EPS (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD02_ORC (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD02_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD02_TRLR_REV (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD03_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD03_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD04_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD08_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentCanNMState_FD11_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD01_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD01_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD02_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD02_BSM2 (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD02_CADM2 (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD02_EPS (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD02_ORC (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD02_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD03_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD03_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD04_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD08_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_CurrentFailSts_FD11_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD01_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD01_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD02_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD02_BSM2 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD02_CADM2 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD02_EPS (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD02_ORC (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD02_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD02_TRLR_REV (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD03_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD03_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD04_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD08_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DES_FD11_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_DeltaTimestamp_IMUdata (255U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_01 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_02 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_03 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_04 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_05 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_06 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_07 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_08 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_09 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_10 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_Digit_11 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD01_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD01_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD02_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD02_BSM2 (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD02_CADM2 (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD02_EPS (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD02_ORC (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD02_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD03_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD03_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD04_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD08_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EOL_FD11_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_EPBSts (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD01_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD01_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD02_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD02_BSM2 (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD02_CADM2 (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD02_EPS (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD02_ORC (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD02_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD03_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD03_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD04_BCM (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD08_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_GenericFailSts_FD11_SGW (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_Heading_Angle_C2 (65535U)
#  define Rte_InitValue_PpToSwcFD02Rx_IgnitionOnCounter (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_LHFWheelSpeed (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_LHF_FastPulseCounter (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_LHF_Spin (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_LHRWheelSpeed (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_LHR_FastPulseCounter (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_LHR_Spin (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_LatAccelerationOffset_BSM (255U)
#  define Rte_InitValue_PpToSwcFD02Rx_LatAcceleration_C2 (4095U)
#  define Rte_InitValue_PpToSwcFD02Rx_Latitude_RMSE_C2 (128U)
#  define Rte_InitValue_PpToSwcFD02Rx_LongAccelerationOffset_BSM (255U)
#  define Rte_InitValue_PpToSwcFD02Rx_LongAcceleration_C2 (4095U)
#  define Rte_InitValue_PpToSwcFD02Rx_Longitude_RMSE_C2 (128U)
#  define Rte_InitValue_PpToSwcFD02Rx_OperationalModeSts (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PitchRate_C2 (4095U)
#  define Rte_InitValue_PpToSwcFD02Rx_Pitch_RMSE_C2 (128U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD01_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD01_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD02_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD02_BSM2 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD02_CADM2 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD02_EPS (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD02_ORC (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD02_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD02_TRLR_REV (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD03_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD03_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD04_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD08_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_PreviousCanNMState_FD11_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_REF_VEH_SPEED (1023U)
#  define Rte_InitValue_PpToSwcFD02Rx_RHFWheelSpeed (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_RHF_FastPulseCounter (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_RHF_Spin (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_RHRWheelSpeed (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_RHR_FastPulseCounter (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_RHR_Spin (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_RemStActvSts (FALSE)
#  define Rte_InitValue_PpToSwcFD02Rx_RollRate_C2 (4095U)
#  define Rte_InitValue_PpToSwcFD02Rx_Roll_RMSE_C2 (128U)
#  define Rte_InitValue_PpToSwcFD02Rx_SBR1RowDriverSeatSts (3U)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD01_BCM (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD01_SGW (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD02_BCM (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD02_BSM2 (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD02_CADM2 (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD02_EPS (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD02_ORC (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD02_SGW (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD02_TRLR_REV (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD03_BCM (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD03_SGW (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD04_BCM (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD08_SGW (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_StayActiveSource_FD11_SGW (0ULL)
#  define Rte_InitValue_PpToSwcFD02Rx_TRSC_CenterBtn_Sts (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_TRSC_EnableBtn_Sts (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_TRSC_RawKnob (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_TotalOdometer (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_TurnIndicatorSts (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_VehicleStandStillSts (1U)
#  define Rte_InitValue_PpToSwcFD02Rx_VerticalAcceleration_C2 (4095U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD01_ADCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD01_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD01_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD02_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD02_BSM2 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD02_CADM2 (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD02_EPS (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD02_ORC (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD02_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD02_TRLR_REV (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD03_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD03_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD04_BCM (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD08_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_WakeupSource_FD11_SGW (0U)
#  define Rte_InitValue_PpToSwcFD02Rx_YawRate_C2 (4095U)
#  define Rte_InitValue_PpToSwcFD02Rx_YawRate_RMSE_C2 (128U)
#  define Rte_InitValue_PpToSwcFD14Rx_FD14_Accel_Pedal_Override (FALSE)
#  define Rte_InitValue_PpToSwcFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM (0U)
#  define Rte_InitValue_PpToSwcFD14Rx_FD14_PPPA_TrqEnblRq_Allowed (FALSE)
#  define Rte_InitValue_RpFailSafeReaction_State (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_Altitude_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD02Rx_BSM_THA_Brk_Resp (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Battery_Volt_1 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD01_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD01_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_BSM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_CADM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_EPS (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_ORC (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD03_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD03_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD04_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD08_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentCanNMState_FD11_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD01_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD01_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_BSM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_CADM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_EPS (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_ORC (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD03_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD03_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD04_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD08_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_CurrentFailSts_FD11_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD01_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD01_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_BSM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_CADM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_EPS (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_ORC (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD03_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD03_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD04_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD08_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DES_FD11_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_DeltaTimestamp_IMUdata (255U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_01 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_02 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_03 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_04 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_05 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_06 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_07 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_08 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_09 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_10 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_Digit_11 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD01_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD01_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_BSM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_CADM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_EPS (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_ORC (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD03_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD03_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD04_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD08_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EOL_FD11_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_EPBSts (0U)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD01_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD01_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_BSM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_CADM2 (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_EPS (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_ORC (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD02_TRLR_REV (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD03_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD03_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD04_BCM (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD08_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_GenericFailSts_FD11_SGW (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_Heading_Angle_C2 (65535U)
#  define Rte_InitValue_RpFromComFD02Rx_IgnitionOnCounter (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHFWheelSpeed (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHF_Spin (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHRWheelSpeed (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LHR_Spin (0U)
#  define Rte_InitValue_RpFromComFD02Rx_LatAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpFromComFD02Rx_LatAcceleration_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_Latitude_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD02Rx_LongAccelerationOffset_BSM (255U)
#  define Rte_InitValue_RpFromComFD02Rx_LongAcceleration_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_Longitude_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD02Rx_OperationalModeSts (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PitchRate_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_Pitch_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD01_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD01_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_BSM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_CADM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_EPS (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_ORC (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD03_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD03_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD04_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD08_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_PreviousCanNMState_FD11_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_REF_VEH_SPEED (1023U)
#  define Rte_InitValue_RpFromComFD02Rx_RHFWheelSpeed (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RHF_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RHF_Spin (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RHRWheelSpeed (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RHR_FastPulseCounter (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RHR_Spin (0U)
#  define Rte_InitValue_RpFromComFD02Rx_RemStActvSts (FALSE)
#  define Rte_InitValue_RpFromComFD02Rx_RollRate_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_Roll_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD02Rx_SBR1RowDriverSeatSts (3U)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD01_BCM (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD01_SGW (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_BCM (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_BSM2 (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_CADM2 (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_EPS (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_ORC (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_SGW (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD02_TRLR_REV (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD03_BCM (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD03_SGW (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD04_BCM (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD08_SGW (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_StayActiveSource_FD11_SGW (0ULL)
#  define Rte_InitValue_RpFromComFD02Rx_TRSC_CenterBtn_Sts (0U)
#  define Rte_InitValue_RpFromComFD02Rx_TRSC_EnableBtn_Sts (0U)
#  define Rte_InitValue_RpFromComFD02Rx_TRSC_RawKnob (0U)
#  define Rte_InitValue_RpFromComFD02Rx_TotalOdometer (0U)
#  define Rte_InitValue_RpFromComFD02Rx_TurnIndicatorSts (0U)
#  define Rte_InitValue_RpFromComFD02Rx_VehicleStandStillSts (1U)
#  define Rte_InitValue_RpFromComFD02Rx_VerticalAcceleration_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD01_ADCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD01_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD01_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_BSM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_CADM2 (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_EPS (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_ORC (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD02_TRLR_REV (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD03_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD03_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD04_BCM (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD08_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_WakeupSource_FD11_SGW (0U)
#  define Rte_InitValue_RpFromComFD02Rx_YawRate_C2 (4095U)
#  define Rte_InitValue_RpFromComFD02Rx_YawRate_RMSE_C2 (128U)
#  define Rte_InitValue_RpFromComFD14Rx_FD14_Accel_Pedal_Override (FALSE)
#  define Rte_InitValue_RpFromComFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM (0U)
#  define Rte_InitValue_RpFromComFD14Rx_FD14_PPPA_TrqEnblRq_Allowed (FALSE)
#  define Rte_InitValue_RpGearPosition_GearValue (0U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_VCANRx_RpFromComFD02Rx_BSM_THA_Brk_Resp(P2VAR(BSM_THA_Brk_Resp, AUTOMATIC, RTE_SWC_VCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EPBSts(P2VAR(EPBSts, AUTOMATIC, RTE_SWC_VCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_VCANRx_RpFromComFD02Rx_SBR1RowDriverSeatSts(P2VAR(SBR1RowDriverSeatSts, AUTOMATIC, RTE_SWC_VCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_VCANRx_RpFromComFD02Rx_TRSC_CenterBtn_Sts(P2VAR(TRSC_CenterBtn_Sts, AUTOMATIC, RTE_SWC_VCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_VCANRx_RpFromComFD02Rx_TRSC_EnableBtn_Sts(P2VAR(TRSC_EnableBtn_Sts, AUTOMATIC, RTE_SWC_VCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_VCANRx_RpFromComFD02Rx_TRSC_RawKnob(P2VAR(TRSC_RawKnob, AUTOMATIC, RTE_SWC_VCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_VCANRx_RpTRSC_ME_VehOut_TRSC_t(P2VAR(ME_VehOut_TRSC_t, AUTOMATIC, RTE_SWC_VCANRX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_VCANRx_PpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t(P2CONST(ME_VehInp_to_IpcSignals_QM_t, AUTOMATIC, RTE_SWC_VCANRX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_RpFailSafeReaction_State Rte_Read_SWC_VCANRx_RpFailSafeReaction_State
#  define Rte_Read_SWC_VCANRx_RpFailSafeReaction_State(data) (*(data) = Rte_SWC_RIDMgr_PpFailSafeReaction_State, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpFromComFD02Rx_Altitude_RMSE_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Altitude_RMSE_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Altitude_RMSE_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_Altitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_89a927da_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_BSM_THA_Brk_Resp Rte_Read_SWC_VCANRx_RpFromComFD02Rx_BSM_THA_Brk_Resp
#  define Rte_Read_RpFromComFD02Rx_Battery_Volt_1 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Battery_Volt_1
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Battery_Volt_1(data) (Com_ReceiveSignal(ComConf_ComSignal_Battery_Volt_1_oBCM_FD_3_oFDCAN2_c3a895dd_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD01_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD01_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD01_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_cb3619a3_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD01_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD01_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD01_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_05d1101e_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_8f973cbb_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_BSM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_BSM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_BSM2(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_3f8b7635_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_CADM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_CADM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_CADM2(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f804ab44_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_EPS Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_EPS
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_EPS(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_277b5480_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_ORC Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_ORC
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_ORC(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_146fe160_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_41703506_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD02_TRLR_REV Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_TRLR_REV
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD02_TRLR_REV(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_e2caab79_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD03_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD03_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD03_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b3f7dfb3_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD03_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD03_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD03_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7d10d60e_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD04_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD04_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD04_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_06d5768b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD08_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD08_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD08_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_01c7ed17_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentCanNMState_FD11_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD11_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentCanNMState_FD11_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0b36f8cf_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD01_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD01_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD01_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b0c60e26_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD01_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD01_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD01_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7e21079b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f4672b3e_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_BSM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_BSM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_BSM2(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_faace40c_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_CADM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_CADM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_CADM2(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_e88111b1_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_EPS Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_EPS
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_EPS(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_5c8b4305_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_ORC Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_ORC
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_ORC(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_6f9ff6e5_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3a802283_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD02_TRLR_REV Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_TRLR_REV
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD02_TRLR_REV(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_3b43d61f_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD03_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD03_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD03_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c807c836_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD03_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD03_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD03_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_06e0c18b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD04_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD04_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD04_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7d25610e_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD08_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD08_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD08_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7a37fa92_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_CurrentFailSts_FD11_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD11_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_CurrentFailSts_FD11_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_70c6ef4a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD01_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD01_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD01_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3865098f_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD01_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD01_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD01_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6820032_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD02_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7cc42c97_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD02_BSM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_BSM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_BSM2(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_1b0dfeac_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD02_CADM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_CADM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_CADM2(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_bbe4b583_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD02_EPS Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_EPS
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_EPS(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d42844ac_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD02_ORC Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_ORC
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_ORC(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e73cf14c_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD02_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b223252a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD02_TRLR_REV Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_TRLR_REV
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD02_TRLR_REV(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9554de37_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD03_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD03_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD03_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_40a4cf9f_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD03_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD03_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD03_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e43c622_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD04_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD04_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD04_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f58666a7_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD08_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD08_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD08_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f294fd3b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DES_FD11_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD11_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DES_FD11_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_DES_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f865e8e3_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_DeltaTimestamp_IMUdata Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DeltaTimestamp_IMUdata
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_DeltaTimestamp_IMUdata(data) (Com_ReceiveSignal(ComConf_ComSignal_DeltaTimestamp_IMUdata_oGLOB_NAV_FD_C2_oFDCAN2_bb3ce8c3_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_01 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_01
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_01(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_01_oCFG_DATA_CODE_REQUEST_oFDCAN2_c824c64f_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_02 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_02
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_02(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_02_oCFG_DATA_CODE_REQUEST_oFDCAN2_013bcef0_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_03 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_03
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_03(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_03_oCFG_DATA_CODE_REQUEST_oFDCAN2_f0e1cb5a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_04 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_04
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_04(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_04_oCFG_DATA_CODE_REQUEST_oFDCAN2_4874d9cf_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_05 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_05
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_05(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_05_oCFG_DATA_CODE_REQUEST_oFDCAN2_b9aedc65_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_06 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_06
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_06(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_06_oCFG_DATA_CODE_REQUEST_oFDCAN2_70b1d4da_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_07 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_07
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_07(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_07_oCFG_DATA_CODE_REQUEST_oFDCAN2_816bd170_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_08 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_08
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_08(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_08_oCFG_DATA_CODE_REQUEST_oFDCAN2_daeaf7b1_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_09 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_09
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_09(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_09_oCFG_DATA_CODE_REQUEST_oFDCAN2_2b30f21b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_10 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_10
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_10(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_10_oCFG_DATA_CODE_REQUEST_oFDCAN2_0f0c5316_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Digit_11 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_11
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Digit_11(data) (Com_ReceiveSignal(ComConf_ComSignal_Digit_11_oCFG_DATA_CODE_REQUEST_oFDCAN2_fed656bc_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD01_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD01_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD01_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_bf538820_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD01_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD01_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD01_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_71b4819d_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD02_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_fbf2ad38_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD02_BSM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_BSM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_BSM2(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a82d6a0a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD02_CADM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_CADM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_CADM2(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_b4db4a91_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD02_EPS Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_EPS
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_EPS(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_531ec503_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD02_ORC Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_ORC
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_ORC(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_600a70e3_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD02_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3515a485_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD02_TRLR_REV Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_TRLR_REV
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD02_TRLR_REV(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_b23a15e1_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD03_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD03_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD03_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c7924e30_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD03_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD03_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD03_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0975478d_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD04_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD04_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD04_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_72b0e708_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD08_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD08_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD08_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_75a27c94_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EOL_FD11_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD11_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EOL_FD11_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_EOL_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7f53694c_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_EPBSts Rte_Read_SWC_VCANRx_RpFromComFD02Rx_EPBSts
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD01_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD01_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD01_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_aaf66243_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD01_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD01_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD01_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_64116bfe_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_ee57475b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_BSM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_BSM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_BSM2(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a6224cad_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_CADM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_CADM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_CADM2(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_8790eb4d_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_EPS Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_EPS
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_EPS(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_46bb2f60_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_ORC Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_ORC
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_ORC(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_75af9a80_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_20b04ee6_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD02_TRLR_REV Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_TRLR_REV
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD02_TRLR_REV(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_f0b9fb66_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD03_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD03_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD03_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_d237a453_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD03_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD03_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD03_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_1cd0adee_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD04_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD04_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD04_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_67150d6b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD08_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD08_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD08_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_600796f7_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_GenericFailSts_FD11_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD11_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_GenericFailSts_FD11_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_6af6832f_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Heading_Angle_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Heading_Angle_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Heading_Angle_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_Heading_Angle_C2_oGLOB_NAV_FD_C2_oFDCAN2_3c56c554_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_IgnitionOnCounter Rte_Read_SWC_VCANRx_RpFromComFD02Rx_IgnitionOnCounter
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_IgnitionOnCounter(data) (Com_ReceiveSignal(ComConf_ComSignal_IgnitionOnCounter_oBCM_FD_7_oFDCAN2_72afbff6_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_LHFWheelSpeed Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHFWheelSpeed
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHFWheelSpeed(data) (Com_ReceiveSignal(ComConf_ComSignal_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_01eb70e0_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_LHF_FastPulseCounter Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHF_FastPulseCounter
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHF_FastPulseCounter(data) (Com_ReceiveSignal(ComConf_ComSignal_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_1316f7bd_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_LHF_Spin Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHF_Spin
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHF_Spin(data) (Com_ReceiveSignal(ComConf_ComSignal_LHF_Spin_oBRAKE_FD_3_oFDCAN2_ddb3a606_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_LHRWheelSpeed Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHRWheelSpeed
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHRWheelSpeed(data) (Com_ReceiveSignal(ComConf_ComSignal_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d40a5eb4_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_LHR_FastPulseCounter Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHR_FastPulseCounter
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHR_FastPulseCounter(data) (Com_ReceiveSignal(ComConf_ComSignal_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_fd14f99b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_LHR_Spin Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHR_Spin
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LHR_Spin(data) (Com_ReceiveSignal(ComConf_ComSignal_LHR_Spin_oBRAKE_FD_3_oFDCAN2_5d756ba0_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_LatAccelerationOffset_BSM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LatAccelerationOffset_BSM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LatAccelerationOffset_BSM(data) (Com_ReceiveSignal(ComConf_ComSignal_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_18f7c44e_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_LatAcceleration_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LatAcceleration_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LatAcceleration_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_LatAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_faefb913_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Latitude_RMSE_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Latitude_RMSE_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Latitude_RMSE_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_Latitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_3a18037a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_LongAccelerationOffset_BSM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LongAccelerationOffset_BSM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LongAccelerationOffset_BSM(data) (Com_ReceiveSignal(ComConf_ComSignal_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_a123ae38_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_LongAcceleration_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LongAcceleration_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_LongAcceleration_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_LongAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_38530c91_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Longitude_RMSE_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Longitude_RMSE_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Longitude_RMSE_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_Longitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1b6c4b2a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_OperationalModeSts Rte_Read_SWC_VCANRx_RpFromComFD02Rx_OperationalModeSts
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_OperationalModeSts(data) (Com_ReceiveSignal(ComConf_ComSignal_OperationalModeSts_oBCM_FD_2_oFDCAN2_92d9b16a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PitchRate_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PitchRate_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PitchRate_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_PitchRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_3e30fc55_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Pitch_RMSE_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Pitch_RMSE_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Pitch_RMSE_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_Pitch_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1cc85bc5_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD01_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD01_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD01_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_99b0bece_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD01_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD01_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD01_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_5757b773_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_dd119bd6_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_BSM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_BSM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_BSM2(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a76a0712_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_CADM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_CADM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_CADM2(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_05c3c06a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_EPS Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_EPS
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_EPS(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_75fdf3ed_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_ORC Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_ORC
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_ORC(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_46e9460d_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_13f6926b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD02_TRLR_REV Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_TRLR_REV
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD02_TRLR_REV(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_6708bf5f_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD03_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD03_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD03_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_e17178de_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD03_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD03_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD03_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_2f967163_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD04_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD04_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD04_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_5453d1e6_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD08_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD08_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD08_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_53414a7a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_PreviousCanNMState_FD11_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD11_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_PreviousCanNMState_FD11_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_59b05fa2_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_REF_VEH_SPEED Rte_Read_SWC_VCANRx_RpFromComFD02Rx_REF_VEH_SPEED
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_REF_VEH_SPEED(data) (Com_ReceiveSignal(ComConf_ComSignal_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN2_6b1619cb_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_RHFWheelSpeed Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHFWheelSpeed
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHFWheelSpeed(data) (Com_ReceiveSignal(ComConf_ComSignal_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_02ea90a1_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_RHF_FastPulseCounter Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHF_FastPulseCounter
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHF_FastPulseCounter(data) (Com_ReceiveSignal(ComConf_ComSignal_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_c8fb14ac_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_RHF_Spin Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHF_Spin
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHF_Spin(data) (Com_ReceiveSignal(ComConf_ComSignal_RHF_Spin_oBRAKE_FD_3_oFDCAN2_ceff9170_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_RHRWheelSpeed Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHRWheelSpeed
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHRWheelSpeed(data) (Com_ReceiveSignal(ComConf_ComSignal_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d70bbef5_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_RHR_FastPulseCounter Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHR_FastPulseCounter
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHR_FastPulseCounter(data) (Com_ReceiveSignal(ComConf_ComSignal_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_26f91a8a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_RHR_Spin Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHR_Spin
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RHR_Spin(data) (Com_ReceiveSignal(ComConf_ComSignal_RHR_Spin_oBRAKE_FD_3_oFDCAN2_4e395cd6_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_RemStActvSts Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RemStActvSts
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RemStActvSts(data) (Com_ReceiveSignal(ComConf_ComSignal_RemStActvSts_oBCM_FD_2_oFDCAN2_fb4ede64_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_RollRate_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RollRate_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_RollRate_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_RollRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_d526080b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_Roll_RMSE_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Roll_RMSE_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_Roll_RMSE_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_Roll_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_90f031c2_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_SBR1RowDriverSeatSts Rte_Read_SWC_VCANRx_RpFromComFD02Rx_SBR1RowDriverSeatSts
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD01_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD01_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD01_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3841343a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD01_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD01_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD01_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6a63d87_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7ce01122_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_BSM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_BSM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_BSM2(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dad7e864_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_CADM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_CADM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_CADM2(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_4c139c4e_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_EPS Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_EPS
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_EPS(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d40c7919_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_ORC Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_ORC
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_ORC(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e718ccf9_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b207189f_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD02_TRLR_REV Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_TRLR_REV
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD02_TRLR_REV(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_5fc9d563_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD03_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD03_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD03_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_4080f22a_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD03_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD03_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD03_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e67fb97_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD04_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD04_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD04_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f5a25b12_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD08_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD08_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD08_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f2b0c08e_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_StayActiveSource_FD11_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD11_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_StayActiveSource_FD11_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f841d556_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_TRSC_CenterBtn_Sts Rte_Read_SWC_VCANRx_RpFromComFD02Rx_TRSC_CenterBtn_Sts
#  define Rte_Read_RpFromComFD02Rx_TRSC_EnableBtn_Sts Rte_Read_SWC_VCANRx_RpFromComFD02Rx_TRSC_EnableBtn_Sts
#  define Rte_Read_RpFromComFD02Rx_TRSC_RawKnob Rte_Read_SWC_VCANRx_RpFromComFD02Rx_TRSC_RawKnob
#  define Rte_Read_RpFromComFD02Rx_TotalOdometer Rte_Read_SWC_VCANRx_RpFromComFD02Rx_TotalOdometer
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_TotalOdometer(data) (Com_ReceiveSignal(ComConf_ComSignal_TotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_TurnIndicatorSts Rte_Read_SWC_VCANRx_RpFromComFD02Rx_TurnIndicatorSts
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_TurnIndicatorSts(data) (Com_ReceiveSignal(ComConf_ComSignal_TurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_VehicleStandStillSts Rte_Read_SWC_VCANRx_RpFromComFD02Rx_VehicleStandStillSts
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_VehicleStandStillSts(data) (Com_ReceiveSignal(ComConf_ComSignal_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN2_ae5f13a6_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_VerticalAcceleration_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_VerticalAcceleration_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_VerticalAcceleration_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_VerticalAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_10e58c6b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD01_ADCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD01_ADCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD01_ADCM(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD01_ADCM_oPDC_INFO_FD_ADCM_oFDCAN2_bce36ee5_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD01_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD01_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD01_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_603c89e8_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD01_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD01_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD01_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aedb8055_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_249dacf0_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_BSM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_BSM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_BSM2(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dc09d8b5_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_CADM2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_CADM2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_CADM2(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f2e95e62_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_EPS Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_EPS
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_EPS(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_8c71c4cb_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_ORC Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_ORC
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_ORC(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_bf65712b_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_ea7aa54d_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD02_TRLR_REV Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_TRLR_REV
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD02_TRLR_REV(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9a698e4c_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD03_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD03_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD03_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_18fd4ff8_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD03_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD03_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD03_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_d61a4645_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD04_BCM Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD04_BCM
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD04_BCM(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_addfe6c0_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD08_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD08_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD08_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aacd7d5c_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_WakeupSource_FD11_SGW Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD11_SGW
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_WakeupSource_FD11_SGW(data) (Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_a03c6884_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_YawRate_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_YawRate_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_YawRate_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_YawRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_f8e96c1f_Rx, (data)))
#  define Rte_Read_RpFromComFD02Rx_YawRate_RMSE_C2 Rte_Read_SWC_VCANRx_RpFromComFD02Rx_YawRate_RMSE_C2
#  define Rte_Read_SWC_VCANRx_RpFromComFD02Rx_YawRate_RMSE_C2(data) (Com_ReceiveSignal(ComConf_ComSignal_YawRate_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_c10121c7_Rx, (data)))
#  define Rte_Read_RpFromComFD14Rx_FD14_Accel_Pedal_Override Rte_Read_SWC_VCANRx_RpFromComFD14Rx_FD14_Accel_Pedal_Override
#  define Rte_Read_SWC_VCANRx_RpFromComFD14Rx_FD14_Accel_Pedal_Override(data) (Com_ReceiveSignal(ComConf_ComSignal_FD14_Accel_Pedal_Override_oPT_TORQUE_FD_1_oFDCAN14_335c6be7_Rx, (data)))
#  define Rte_Read_RpFromComFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM Rte_Read_SWC_VCANRx_RpFromComFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM
#  define Rte_Read_SWC_VCANRx_RpFromComFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM(data) (Com_ReceiveSignal(ComConf_ComSignal_FD14_DriverReq_AxleTrq_Enabled_BSM_oBRAKE_FD_6_oFDCAN14_e957fd54_Rx, (data)))
#  define Rte_Read_RpFromComFD14Rx_FD14_PPPA_TrqEnblRq_Allowed Rte_Read_SWC_VCANRx_RpFromComFD14Rx_FD14_PPPA_TrqEnblRq_Allowed
#  define Rte_Read_SWC_VCANRx_RpFromComFD14Rx_FD14_PPPA_TrqEnblRq_Allowed(data) (Com_ReceiveSignal(ComConf_ComSignal_FD14_PPPA_TrqEnblRq_Allowed_oPT_TORQUE_FD_1_oFDCAN14_ec3352c7_Rx, (data)))
#  define Rte_Read_RpGearPosition_GearValue Rte_Read_SWC_VCANRx_RpGearPosition_GearValue
#  define Rte_Read_SWC_VCANRx_RpGearPosition_GearValue(data) (*(data) = Rte_SWC_DIDMgr_PpGearPosition_GearValue, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpGearPosition_ShortTermAdjActiveFlag_b Rte_Read_SWC_VCANRx_RpGearPosition_ShortTermAdjActiveFlag_b
#  define Rte_Read_SWC_VCANRx_RpGearPosition_ShortTermAdjActiveFlag_b(data) (*(data) = Rte_SWC_DIDMgr_PpGearPosition_ShortTermAdjActiveFlag_b, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpTRSC_ME_VehOut_TRSC_t Rte_Read_SWC_VCANRx_RpTRSC_ME_VehOut_TRSC_t
#  define Rte_Read_RpToSwcSafeFD02Rx_ITBM_TrlrStat Rte_Read_SWC_VCANRx_RpToSwcSafeFD02Rx_ITBM_TrlrStat
#  define Rte_Read_SWC_VCANRx_RpToSwcSafeFD02Rx_ITBM_TrlrStat(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ITBM_TrlrStat, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcSafeFD02Rx_TrailerConnectionSts Rte_Read_SWC_VCANRx_RpToSwcSafeFD02Rx_TrailerConnectionSts
#  define Rte_Read_SWC_VCANRx_RpToSwcSafeFD02Rx_TrailerConnectionSts(data) (*(data) = Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_IsUpdated_RpFromComFD02Rx_BSM_THA_Brk_Resp Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_BSM_THA_Brk_Resp
#  define Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_BSM_THA_Brk_Resp() (Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_BSM_THA_Brk_Resp != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_BSM_THA_Brk_Resp_Sender)
#  define Rte_IsUpdated_RpFromComFD02Rx_EPBSts Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_EPBSts
#  define Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_EPBSts() (Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_EPBSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_EPBSts_Sender)
#  define Rte_IsUpdated_RpFromComFD02Rx_SBR1RowDriverSeatSts Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_SBR1RowDriverSeatSts
#  define Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_SBR1RowDriverSeatSts() (Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_SBR1RowDriverSeatSts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_SBR1RowDriverSeatSts_Sender)
#  define Rte_IsUpdated_RpFromComFD02Rx_TRSC_CenterBtn_Sts Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_TRSC_CenterBtn_Sts
#  define Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_TRSC_CenterBtn_Sts() (Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_CenterBtn_Sts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_CenterBtn_Sts_Sender)
#  define Rte_IsUpdated_RpFromComFD02Rx_TRSC_EnableBtn_Sts Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_TRSC_EnableBtn_Sts
#  define Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_TRSC_EnableBtn_Sts() (Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_EnableBtn_Sts != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_EnableBtn_Sts_Sender)
#  define Rte_IsUpdated_RpFromComFD02Rx_TRSC_RawKnob Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_TRSC_RawKnob
#  define Rte_IsUpdated_SWC_VCANRx_RpFromComFD02Rx_TRSC_RawKnob() (Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_RawKnob != Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_RawKnob_Sender)


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpBusOffIndication_V_BusOffIndicationFlagRte_u8 Rte_Write_SWC_VCANRx_PpBusOffIndication_V_BusOffIndicationFlagRte_u8
#  define Rte_Write_SWC_VCANRx_PpBusOffIndication_V_BusOffIndicationFlagRte_u8(data) (Rte_SWC_VCANRx_PpBusOffIndication_V_BusOffIndicationFlagRte_u8 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcFD02Rx_Altitude_RMSE_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Altitude_RMSE_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Altitude_RMSE_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_BSM_THA_Brk_Resp Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_BSM_THA_Brk_Resp
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_BSM_THA_Brk_Resp(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Battery_Volt_1 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Battery_Volt_1
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Battery_Volt_1(data) (Rte_SWC_VCANRx_PpToSwcFD02Rx_Battery_Volt_1 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD01_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD01_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD01_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD01_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD01_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD01_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_BSM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_BSM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_BSM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_CADM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_CADM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_CADM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_EPS Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_EPS
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_EPS(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_ORC Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_ORC
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_ORC(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD02_TRLR_REV Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_TRLR_REV
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD02_TRLR_REV(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD03_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD03_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD03_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD03_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD03_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD03_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD04_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD04_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD04_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD08_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD08_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD08_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentCanNMState_FD11_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD11_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentCanNMState_FD11_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD01_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD01_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD01_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD01_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD01_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD01_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_BSM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_BSM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_BSM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_CADM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_CADM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_CADM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_EPS Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_EPS
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_EPS(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_ORC Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_ORC
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_ORC(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD02_TRLR_REV Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_TRLR_REV
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD02_TRLR_REV(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD03_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD03_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD03_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD03_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD03_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD03_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD04_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD04_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD04_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD08_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD08_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD08_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_CurrentFailSts_FD11_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD11_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_CurrentFailSts_FD11_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD01_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD01_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD01_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD01_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD01_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD01_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD02_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD02_BSM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_BSM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_BSM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD02_CADM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_CADM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_CADM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD02_EPS Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_EPS
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_EPS(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD02_ORC Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_ORC
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_ORC(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD02_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD02_TRLR_REV Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_TRLR_REV
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD02_TRLR_REV(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD03_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD03_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD03_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD03_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD03_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD03_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD04_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD04_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD04_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD08_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD08_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD08_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DES_FD11_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD11_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DES_FD11_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_DeltaTimestamp_IMUdata Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DeltaTimestamp_IMUdata
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_DeltaTimestamp_IMUdata(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_01 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_01
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_01(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_02 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_02
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_02(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_03 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_03
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_03(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_04 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_04
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_04(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_05 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_05
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_05(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_06 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_06
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_06(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_07 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_07
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_07(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_08 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_08
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_08(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_09 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_09
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_09(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_10 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_10
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_10(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Digit_11 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_11
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Digit_11(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD01_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD01_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD01_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD01_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD01_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD01_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD02_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD02_BSM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_BSM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_BSM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD02_CADM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_CADM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_CADM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD02_EPS Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_EPS
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_EPS(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD02_ORC Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_ORC
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_ORC(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD02_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD02_TRLR_REV Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_TRLR_REV
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD02_TRLR_REV(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD03_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD03_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD03_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD03_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD03_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD03_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD04_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD04_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD04_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD08_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD08_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD08_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EOL_FD11_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD11_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EOL_FD11_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_EPBSts Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EPBSts
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_EPBSts(data) (Rte_SWC_VCANRx_PpToSwcFD02Rx_EPBSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD01_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD01_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD01_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD01_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD01_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD01_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_BSM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_BSM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_BSM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_CADM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_CADM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_CADM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_EPS Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_EPS
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_EPS(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_ORC Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_ORC
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_ORC(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD02_TRLR_REV Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_TRLR_REV
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD02_TRLR_REV(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD03_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD03_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD03_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD03_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD03_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD03_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD04_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD04_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD04_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD08_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD08_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD08_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_GenericFailSts_FD11_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD11_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_GenericFailSts_FD11_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Heading_Angle_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Heading_Angle_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Heading_Angle_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_IgnitionOnCounter Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_IgnitionOnCounter
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_IgnitionOnCounter(data) (Rte_SWC_VCANRx_PpToSwcFD02Rx_IgnitionOnCounter = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcFD02Rx_LHFWheelSpeed Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHFWheelSpeed
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHFWheelSpeed(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_LHF_FastPulseCounter Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHF_FastPulseCounter
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHF_FastPulseCounter(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_LHF_Spin Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHF_Spin
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHF_Spin(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_LHRWheelSpeed Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHRWheelSpeed
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHRWheelSpeed(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_LHR_FastPulseCounter Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHR_FastPulseCounter
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHR_FastPulseCounter(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_LHR_Spin Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHR_Spin
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LHR_Spin(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_LatAccelerationOffset_BSM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LatAccelerationOffset_BSM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LatAccelerationOffset_BSM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_LatAcceleration_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LatAcceleration_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LatAcceleration_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Latitude_RMSE_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Latitude_RMSE_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Latitude_RMSE_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_LongAccelerationOffset_BSM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LongAccelerationOffset_BSM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LongAccelerationOffset_BSM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_LongAcceleration_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LongAcceleration_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_LongAcceleration_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Longitude_RMSE_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Longitude_RMSE_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Longitude_RMSE_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_OperationalModeSts Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_OperationalModeSts
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_OperationalModeSts(data) (Rte_SWC_VCANRx_PpToSwcFD02Rx_OperationalModeSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcFD02Rx_PitchRate_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PitchRate_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PitchRate_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Pitch_RMSE_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Pitch_RMSE_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Pitch_RMSE_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD01_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD01_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD01_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD01_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD01_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD01_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_BSM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_BSM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_BSM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_CADM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_CADM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_CADM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_EPS Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_EPS
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_EPS(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_ORC Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_ORC
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_ORC(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD02_TRLR_REV Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_TRLR_REV
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD02_TRLR_REV(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD03_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD03_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD03_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD03_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD03_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD03_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD04_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD04_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD04_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD08_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD08_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD08_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_PreviousCanNMState_FD11_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD11_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_PreviousCanNMState_FD11_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_REF_VEH_SPEED Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_REF_VEH_SPEED
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_REF_VEH_SPEED(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_RHFWheelSpeed Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHFWheelSpeed
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHFWheelSpeed(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_RHF_FastPulseCounter Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHF_FastPulseCounter
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHF_FastPulseCounter(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_RHF_Spin Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHF_Spin
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHF_Spin(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_RHRWheelSpeed Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHRWheelSpeed
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHRWheelSpeed(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_RHR_FastPulseCounter Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHR_FastPulseCounter
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHR_FastPulseCounter(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_RHR_Spin Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHR_Spin
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RHR_Spin(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_RemStActvSts Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RemStActvSts
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RemStActvSts(data) (Rte_SWC_VCANRx_PpToSwcFD02Rx_RemStActvSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcFD02Rx_RollRate_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RollRate_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_RollRate_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_Roll_RMSE_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Roll_RMSE_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_Roll_RMSE_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_SBR1RowDriverSeatSts Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_SBR1RowDriverSeatSts
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_SBR1RowDriverSeatSts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD01_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD01_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD01_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD01_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD01_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD01_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_BSM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_BSM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_BSM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_CADM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_CADM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_CADM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_EPS Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_EPS
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_EPS(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_ORC Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_ORC
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_ORC(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD02_TRLR_REV Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_TRLR_REV
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD02_TRLR_REV(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD03_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD03_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD03_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD03_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD03_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD03_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD04_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD04_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD04_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD08_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD08_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD08_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_StayActiveSource_FD11_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD11_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_StayActiveSource_FD11_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_TRSC_CenterBtn_Sts Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_TRSC_CenterBtn_Sts
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_TRSC_CenterBtn_Sts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_TRSC_EnableBtn_Sts Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_TRSC_EnableBtn_Sts
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_TRSC_EnableBtn_Sts(data) (Rte_SWC_VCANRx_PpToSwcFD02Rx_TRSC_EnableBtn_Sts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcFD02Rx_TRSC_RawKnob Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_TRSC_RawKnob
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_TRSC_RawKnob(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_TotalOdometer Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer(data) (Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcFD02Rx_TurnIndicatorSts Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_TurnIndicatorSts
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_TurnIndicatorSts(data) (Rte_SWC_VCANRx_PpToSwcFD02Rx_TurnIndicatorSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcFD02Rx_VehicleStandStillSts Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_VehicleStandStillSts
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_VehicleStandStillSts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_VerticalAcceleration_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_VerticalAcceleration_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_VerticalAcceleration_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD01_ADCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD01_ADCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD01_ADCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD01_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD01_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD01_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD01_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD01_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD01_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_BSM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_BSM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_BSM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_CADM2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_CADM2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_CADM2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_EPS Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_EPS
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_EPS(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_ORC Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_ORC
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_ORC(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD02_TRLR_REV Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_TRLR_REV
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD02_TRLR_REV(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD03_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD03_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD03_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD03_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD03_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD03_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD04_BCM Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD04_BCM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD04_BCM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD08_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD08_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD08_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_WakeupSource_FD11_SGW Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD11_SGW
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_WakeupSource_FD11_SGW(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_YawRate_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_YawRate_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_YawRate_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD02Rx_YawRate_RMSE_C2 Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_YawRate_RMSE_C2
#  define Rte_Write_SWC_VCANRx_PpToSwcFD02Rx_YawRate_RMSE_C2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD14Rx_FD14_Accel_Pedal_Override Rte_Write_SWC_VCANRx_PpToSwcFD14Rx_FD14_Accel_Pedal_Override
#  define Rte_Write_SWC_VCANRx_PpToSwcFD14Rx_FD14_Accel_Pedal_Override(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM Rte_Write_SWC_VCANRx_PpToSwcFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM
#  define Rte_Write_SWC_VCANRx_PpToSwcFD14Rx_FD14_DriverReq_AxleTrq_Enabled_BSM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcFD14Rx_FD14_PPPA_TrqEnblRq_Allowed Rte_Write_SWC_VCANRx_PpToSwcFD14Rx_FD14_PPPA_TrqEnblRq_Allowed
#  define Rte_Write_SWC_VCANRx_PpToSwcFD14Rx_FD14_PPPA_TrqEnblRq_Allowed(data) (RTE_E_OK)
#  define Rte_Write_PpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t Rte_Write_SWC_VCANRx_PpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_E2EWRAPPER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CDD_E2EWRAPPER_APPL_CODE) RE_E2EWrapperCheck(P2VAR(E2E_MEP_ConfigType, AUTOMATIC, RTE_VAR_NOINIT) ConfigPtr, P2VAR(E2E_MEP_CheckStateType, AUTOMATIC, RTE_VAR_NOINIT) StatePtr, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) DataPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_E2EWRAPPER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CDD_IPCHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CDD_IPCHANDLER_APPL_CODE) RE_IpcTxData(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_IPCHANDLER_APPL_CODE
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

#  define Rte_Call_RpE2EServices_ME_E2E_Check RE_E2EWrapperCheck
#  define Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B RE_ReportErrorStatus1_0_B
#  define Rte_Call_RpError_CS_QM_ReportErrorStatus1_0_QM RE_ReportErrorStatus1_0_QM
#  define Rte_Call_RpIpcTxData_IPC_Write_v(arg1, arg2, arg3) (RE_IpcTxData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))

# endif /* !defined(RTE_CORE) */


# define SWC_VCANRx_START_SEC_CODE
# include "SWC_VCANRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_VCANRx_Init RE_VCANRx_Init
#  define RTE_RUNNABLE_RE_VCANRx_Main RE_VCANRx_Main
# endif

FUNC(void, SWC_VCANRx_CODE) RE_VCANRx_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_VCANRx_CODE) RE_VCANRx_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_VCANRx_STOP_SEC_CODE
# include "SWC_VCANRx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL (19U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG (23U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_INTERR (25U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE (26U)

#  define RTE_E_P_Error_CS_E_NOK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_VCANRX_H */

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
