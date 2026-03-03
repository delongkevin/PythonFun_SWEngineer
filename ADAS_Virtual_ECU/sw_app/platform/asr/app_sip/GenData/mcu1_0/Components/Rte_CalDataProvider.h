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
 *             File:  Rte_CalDataProvider.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <CalDataProvider>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CALDATAPROVIDER_H
# define RTE_CALDATAPROVIDER_H

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

# include "Rte_CalDataProvider_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpCalibRoutineTrigger_routine_b;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_RIDMgr_PpCalibRoutineType_value;
extern VAR(boolean, RTE_VAR_INIT) Rte_SWC_DIDMgr_PpResetNvmFlag_V_ResetNvmFlag_b;
extern VAR(TotalOdometer, RTE_VAR_INIT) Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer;
extern VAR(uint16, RTE_VAR_INIT) Rte_SWC_DIDMgr_Pp_PlantOdoData_PlantOdoData;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(BswM_CalDataProSCCalStatus, RTE_VAR_INIT) Rte_CalDataProvider_P_Request_BswM_ScCalStatus_requestedMode;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8;
extern VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpVariantData_Variant;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_RpCalibRoutineTrigger_routine_b (FALSE)
#  define Rte_InitValue_RpCalibRoutineType_value (0U)
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
#  define Rte_InitValue_RpVariantData_Variant (0U)
#  define Rte_InitValue_Rp_PlantOdoData_PlantOdoData (0U)
# endif


# define RTE_START_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamCurrentCalibData_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamEOLCalibData_TbSVS_S_SVSCamEOLCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamEOLCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamOCCalibData_TbSVS_S_SVSCamOCCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamOCCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamSCCalibData_TbSVS_S_SVSCamSCCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamSCCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_SSM_1_0_State_State_1_0(P2VAR(SSM_1_0_CoreStatus, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_SSM_2_State_State_2_0(P2VAR(SSM_2_0_CoreStatus, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_SSM_2_State_State_2_1(P2VAR(SSM_2_1_CoreStatus, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_SSM_QNXState_State_QNX(P2VAR(SSM_QNX_CoreStatus, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_RpCamEepromData_Svs_CamEepromDataArray_t(P2VAR(Svs_CamEepromDataArray_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CalDataProvider_P_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0(P2CONST(CalDataProvider_MCU_1_0_Def, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CalDataProvider_PpAPVarTunParam_TbAP_VrntTunParam_t(P2CONST(TbAP_VrntTunParam_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CalDataProvider_PpPreviousCamData_Data(P2CONST(CDP_TbSVS_S_SVSCamCurrentCalibData_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_CalDataProvider_Nvm_SVSCamCurrentCalibData_TbSVS_S_SVSCamCurrentCalibDataToNVM_t Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamCurrentCalibData_TbSVS_S_SVSCamCurrentCalibDataToNVM_t
#  define Rte_Read_R_CalDataProvider_Nvm_SVSCamEOLCalibData_TbSVS_S_SVSCamEOLCalibDataToNVM_t Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamEOLCalibData_TbSVS_S_SVSCamEOLCalibDataToNVM_t
#  define Rte_Read_R_CalDataProvider_Nvm_SVSCamOCCalibData_TbSVS_S_SVSCamOCCalibDataToNVM_t Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamOCCalibData_TbSVS_S_SVSCamOCCalibDataToNVM_t
#  define Rte_Read_R_CalDataProvider_Nvm_SVSCamSCCalibData_TbSVS_S_SVSCamSCCalibDataToNVM_t Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamSCCalibData_TbSVS_S_SVSCamSCCalibDataToNVM_t
#  define Rte_Read_R_SSM_1_0_State_State_1_0 Rte_Read_CalDataProvider_R_SSM_1_0_State_State_1_0
#  define Rte_Read_R_SSM_2_State_State_2_0 Rte_Read_CalDataProvider_R_SSM_2_State_State_2_0
#  define Rte_Read_R_SSM_2_State_State_2_1 Rte_Read_CalDataProvider_R_SSM_2_State_State_2_1
#  define Rte_Read_R_SSM_QNXState_State_QNX Rte_Read_CalDataProvider_R_SSM_QNXState_State_QNX
#  define Rte_Read_R_SystemState_SystemState Rte_Read_CalDataProvider_R_SystemState_SystemState
#  define Rte_Read_RpCalibRoutineTrigger_routine_b Rte_Read_CalDataProvider_RpCalibRoutineTrigger_routine_b
#  define Rte_Read_CalDataProvider_RpCalibRoutineTrigger_routine_b(data) (*(data) = Rte_SWC_RIDMgr_PpCalibRoutineTrigger_routine_b, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpCalibRoutineType_value Rte_Read_CalDataProvider_RpCalibRoutineType_value
#  define Rte_Read_CalDataProvider_RpCalibRoutineType_value(data) (*(data) = Rte_SWC_RIDMgr_PpCalibRoutineType_value, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpCamEepromData_Svs_CamEepromDataArray_t Rte_Read_CalDataProvider_RpCamEepromData_Svs_CamEepromDataArray_t
#  define Rte_Read_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t Rte_Read_CalDataProvider_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t
#  define Rte_Read_RpProxiToSWC_SurroundViewCam_u8 Rte_Read_CalDataProvider_RpProxiToSWC_SurroundViewCam_u8
#  define Rte_Read_CalDataProvider_RpProxiToSWC_SurroundViewCam_u8(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpResetNvmFlag_V_ResetNvmFlag_b Rte_Read_CalDataProvider_RpResetNvmFlag_V_ResetNvmFlag_b
#  define Rte_Read_CalDataProvider_RpResetNvmFlag_V_ResetNvmFlag_b(data) (*(data) = Rte_SWC_DIDMgr_PpResetNvmFlag_V_ResetNvmFlag_b, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpToSwcFD02Rx_TotalOdometer Rte_Read_CalDataProvider_RpToSwcFD02Rx_TotalOdometer
#  define Rte_Read_CalDataProvider_RpToSwcFD02Rx_TotalOdometer(data) (*(data) = Rte_SWC_VCANRx_PpToSwcFD02Rx_TotalOdometer, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_RpVariantData_Variant Rte_Read_CalDataProvider_RpVariantData_Variant
#  define Rte_Read_CalDataProvider_RpVariantData_Variant(data) (*(data) = Rte_SWC_ProxiConfigMgr_PpVariantData_Variant, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Rp_PlantOdoData_PlantOdoData Rte_Read_CalDataProvider_Rp_PlantOdoData_PlantOdoData
#  define Rte_Read_CalDataProvider_Rp_PlantOdoData_PlantOdoData(data) (*(data) = Rte_SWC_DIDMgr_Pp_PlantOdoData_PlantOdoData, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0 Rte_Write_CalDataProvider_P_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0
#  define Rte_Write_P_Request_BswM_ScCalStatus_requestedMode Rte_Write_CalDataProvider_P_Request_BswM_ScCalStatus_requestedMode
#  define Rte_Write_CalDataProvider_P_Request_BswM_ScCalStatus_requestedMode(data) (Rte_CalDataProvider_P_Request_BswM_ScCalStatus_requestedMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpAPVarTunParam_TbAP_VrntTunParam_t Rte_Write_CalDataProvider_PpAPVarTunParam_TbAP_VrntTunParam_t
#  define Rte_Write_PpPreviousCamData_Data Rte_Write_CalDataProvider_PpPreviousCamData_Data


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
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

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_VAR_NOINIT) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_NvMService_AC3_SRBS_FrontCamSerialNumber_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)73, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_FrontCamSerialNumber_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)73, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_FrontCamSerialNumber_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)73, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_LeftCamSerialNumber_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)74, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_LeftCamSerialNumber_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)74, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_LeftCamSerialNumber_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)74, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_RearCamSerialNumber_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)75, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_RearCamSerialNumber_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)75, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_RearCamSerialNumber_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)75, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_RightCamSerialNumber_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)76, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_RightCamSerialNumber_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)76, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_RightCamSerialNumber_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)76, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SVSCamCurrentCalibData_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)58, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SVSCamCurrentCalibData_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)58, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SVSCamEOLCalibData_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)59, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SVSCamEOLCalibData_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)59, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SVSCamOCCalibData_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)60, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SVSCamOCCalibData_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)60, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SVSCamSCCalibData_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)61, arg1))
#  define Rte_Call_NvMService_AC3_SRBS_SVSCamSCCalibData_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)61, arg1))
#  define Rte_Call_R_CalDataProvider_ErrorMgrSat_1_0_QM_Error_CS_ReportErrorStatus1_0_QM RE_ReportErrorStatus1_0_QM
#  define Rte_Call_R_IPC_IPC_Write_v(arg1, arg2, arg3) (RE_IpcTxData(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B RE_ReportErrorStatus1_0_B

/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_FrontCamSerialNumber_DefaultValue;
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_LeftCamSerialNumber_DefaultValue;
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_RearCamSerialNumber_DefaultValue;
extern CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_RightCamSerialNumber_DefaultValue;
extern CONST(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue;
extern CONST(CDP_TbSVS_S_SVSCamEOLCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue;
extern CONST(CDP_TbSVS_S_SVSCamOCCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue;
extern CONST(CDP_TbSVS_S_SVSCamSCCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_FrontCamSerialNumber_DefaultValue() (&Rte_CalDataProvider_FrontCamSerialNumber_DefaultValue)

#  define Rte_CData_LeftCamSerialNumber_DefaultValue() (&Rte_CalDataProvider_LeftCamSerialNumber_DefaultValue)

#  define Rte_CData_RearCamSerialNumber_DefaultValue() (&Rte_CalDataProvider_RearCamSerialNumber_DefaultValue)

#  define Rte_CData_RightCamSerialNumber_DefaultValue() (&Rte_CalDataProvider_RightCamSerialNumber_DefaultValue)

#  define Rte_CData_SVSCamCurrentCalibData_DefaultValue() (&Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue)

#  define Rte_CData_SVSCamEOLCalibData_DefaultValue() (&Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue)

#  define Rte_CData_SVSCamOCCalibData_DefaultValue() (&Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue)

#  define Rte_CData_SVSCamSCCalibData_DefaultValue() (&Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock;
extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock;
extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock;
extern VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock;
extern VAR(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock;
extern VAR(CDP_TbSVS_S_SVSCamEOLCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock;
extern VAR(CDP_TbSVS_S_SVSCamOCCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock;
extern VAR(CDP_TbSVS_S_SVSCamSCCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_FrontCamSerialNumber_MirrorBlock() \
  (&Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_LeftCamSerialNumber_MirrorBlock() \
  (&Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_RearCamSerialNumber_MirrorBlock() \
  (&Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_RightCamSerialNumber_MirrorBlock() \
  (&Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_SVSCamCurrentCalibData_MirrorBlock() \
  (&Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_SVSCamEOLCalibData_MirrorBlock() \
  (&Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_SVSCamOCCalibData_MirrorBlock() \
  (&Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock)
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_SVSCamSCCalibData_MirrorBlock() \
  (&Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define CalDataProvider_START_SEC_CODE
# include "CalDataProvider_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_CalDataProvider_Init RE_CalDataProvider_Init
#  define RTE_RUNNABLE_RE_CalDataProvider_Nvm_SVSCamCalibReset RE_CalDataProvider_Nvm_SVSCamCalibReset
#  define RTE_RUNNABLE_RE_CalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock RE_CalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock
#  define RTE_RUNNABLE_RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock
#  define RTE_RUNNABLE_RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock
#  define RTE_RUNNABLE_RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock
#  define RTE_RUNNABLE_RE_IntrinsicCameraSN_Readblock RE_IntrinsicCameraSN_Readblock
#  define RTE_RUNNABLE_RE_Periodic_CalDataProvider RE_Periodic_CalDataProvider
# endif

FUNC(void, CalDataProvider_CODE) RE_CalDataProvider_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamCalibReset(P2CONST(TbSVS_S_SVSCamCalibReset_t, AUTOMATIC, RTE_VAR_NOINIT) v_SVSCamCalibReset); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamCurrentCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, AUTOMATIC, RTE_VAR_NOINIT) v_SVSCamCurrentCalibData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamEOLCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamEOLCalibDataToNVM_t, AUTOMATIC, RTE_VAR_NOINIT) v_SVSCamEOLCalibData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamOCCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamOCCalibDataToNVM_t, AUTOMATIC, RTE_VAR_NOINIT) v_SVSCamOCCalibData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, CalDataProvider_CODE) RE_CalDataProvider_Nvm_SVSCamSCCalibData_WriteBlock(P2CONST(TbSVS_S_SVSCamSCCalibDataToNVM_t, AUTOMATIC, RTE_VAR_NOINIT) v_SVSCamSCCalibData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, CalDataProvider_CODE) RE_IntrinsicCameraSN_Readblock(P2VAR(IntrinsicCamID, AUTOMATIC, RTE_VAR_NOINIT) CamNvmData, P2VAR(CamNvmReadSts, AUTOMATIC, RTE_VAR_NOINIT) NvmCamSts); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CalDataProvider_CODE) RE_Periodic_CalDataProvider(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define CalDataProvider_STOP_SEC_CODE
# include "CalDataProvider_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_IF_IntrinsicCameraSN_E_NOT_OK (1U)

#  define RTE_E_IF_IntrinsicCameraSN_E_OK (0U)

#  define RTE_E_IF_SVSCamCalibReset_E_NOT_OK (1U)

#  define RTE_E_IF_SWC_CalDataProvider_SVSCamCurrentCalibData_E_NOT_OK (1U)

#  define RTE_E_IF_SWC_CalDataProvider_SVSCamEOLCalibData_E_NOT_OK (1U)

#  define RTE_E_IF_SWC_CalDataProvider_SVSCamOCCalibData_E_NOT_OK (1U)

#  define RTE_E_IF_SWC_CalDataProvider_SVSCamSCCalibData_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)

#  define RTE_E_P_Error_CS_E_NOK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CALDATAPROVIDER_H */

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
