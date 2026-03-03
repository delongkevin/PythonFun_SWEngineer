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
 *             File:  Rte_Cbk.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Callback header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CBK_H
# define RTE_CBK_H

# include "Com.h"


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * COM Callbacks for Rx Indication
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_APARequestSts_oBCM_FD_12_oFDCAN2_c58fc45d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ASCM_Stat_oASCM_FD_2_oFDCAN2_58854b4a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ASCM_SysFail_oASCM_FD_2_oFDCAN2_9d00e371_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Active_Park_Mode_oIPC_VEHICLE_SETUP_oFDCAN2_6a2a58c7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Active_Park_Prox_Chime_oIPC_VEHICLE_SETUP_oFDCAN2_ae5aba94_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Altitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_89a927da_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN2_c6b9d212_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Backup_Cam_Delay_oIPC_VEHICLE_SETUP_oFDCAN2_4de26278_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Battery_Volt_1_oBCM_FD_3_oFDCAN2_c3a895dd_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Brk_Stat_oBRAKE_FD_2_oFDCAN2_1b647924_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CM_TCH_STAT_oTELEMATIC_FD_5_oFDCAN2_64ce192d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CM_TCH_X_COORD_oTELEMATIC_FD_5_oFDCAN2_0177f5f2_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CM_TCH_Y_COORD_oTELEMATIC_FD_5_oFDCAN2_0f901d23_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CameraDisplaySts2_oTELEMATIC_FD_5_oFDCAN2_3ea6a9f0_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CmdIgnSts_oBCM_FD_10_oFDCAN2_06c30ef2_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_cb3619a3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_05d1101e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_8f973cbb_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_3f8b7635_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f804ab44_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_277b5480_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_146fe160_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_41703506_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_e2caab79_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b3f7dfb3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7d10d60e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_06d5768b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_01c7ed17_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0b36f8cf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b0c60e26_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7e21079b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f4672b3e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_faace40c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_e88111b1_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_5c8b4305_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_6f9ff6e5_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3a802283_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_3b43d61f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c807c836_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_06e0c18b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7d25610e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7a37fa92_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_70c6ef4a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3865098f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6820032_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7cc42c97_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_1b0dfeac_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_bbe4b583_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d42844ac_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e73cf14c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b223252a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9554de37_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_40a4cf9f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e43c622_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f58666a7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f294fd3b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f865e8e3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DeltaTimestamp_IMUdata_oGLOB_NAV_FD_C2_oFDCAN2_bb3ce8c3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_01_oCFG_DATA_CODE_REQUEST_oFDCAN2_c824c64f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_02_oCFG_DATA_CODE_REQUEST_oFDCAN2_013bcef0_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_03_oCFG_DATA_CODE_REQUEST_oFDCAN2_f0e1cb5a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_04_oCFG_DATA_CODE_REQUEST_oFDCAN2_4874d9cf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_05_oCFG_DATA_CODE_REQUEST_oFDCAN2_b9aedc65_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_06_oCFG_DATA_CODE_REQUEST_oFDCAN2_70b1d4da_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_07_oCFG_DATA_CODE_REQUEST_oFDCAN2_816bd170_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_08_oCFG_DATA_CODE_REQUEST_oFDCAN2_daeaf7b1_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_09_oCFG_DATA_CODE_REQUEST_oFDCAN2_2b30f21b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_10_oCFG_DATA_CODE_REQUEST_oFDCAN2_0f0c5316_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Digit_11_oCFG_DATA_CODE_REQUEST_oFDCAN2_fed656bc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DriverDoorSts_oBCM_FD_9_oFDCAN2_5b5b4a2d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_DynamicGrid_oIPC_VEHICLE_SETUP_oFDCAN2_8defe0e1_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ECM_THA_Resp_oENGINE_FD_7_oFDCAN2_4f167839_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN2_7dcf088b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_bf538820_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_71b4819d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_fbf2ad38_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a82d6a0a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_b4db4a91_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_531ec503_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_600a70e3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3515a485_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_b23a15e1_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c7924e30_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0975478d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_72b0e708_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_75a27c94_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7f53694c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EPBSts_oBRAKE_FD_4_oFDCAN2_4e811a74_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN2_70168af6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN2_a31e0e47_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN2_0e3a0a14_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN2_2f8c0396_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN2_b1b6db89_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EngineSts_W_oENGINE_FD_2_oFDCAN2_7417ef03_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ExternalTemperature_oBCM_FD_9_oFDCAN2_fd16cd2c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ACC_Systemsts_oADAS_FD_INFO_oFDCAN14_2086cf20_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN14_cecdbc25_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_BrkTrq_Driver_oBRAKE_FD_1_oFDCAN14_f4f61916_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ECM_THA_Resp_oENGINE_FD_7_oFDCAN14_284045ab_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN14_994d6c00_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPBSts_oBRAKE_FD_4_oFDCAN14_c0ca10e6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPS_HandsOnRecognition_oEPS_FD_1_oFDCAN14_58e651a9_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cae7cd32_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN14_765246ac_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN14_2abac25d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN14_c35bede9_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ESC_TRSC_Brk_Resp_oBRAKE_FD_5_oFDCAN14_2f38fcaf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN14_e3df5684_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ExternalBrkRequestsDisabled_oBRAKE_FD_1_oFDCAN14_3622ec06_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_HAS_Status_oADAS_FD_INFO_oFDCAN14_368cf8df_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d701d2d3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_c079cbbf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_3a28d00b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_bbd2a610_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_129a4c4c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHR_Spin_oBRAKE_FD_3_oFDCAN14_eda6ba5c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_7665a615_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LatAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_b6857dc3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_045731ef_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_79c02fd1_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LongAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_7b4ee1d6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_18cdb71a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_b347f969_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LwsAngleType_oEPS_FD_1_oFDCAN14_8f61bc22_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LwsSpeed_oEPS_FD_1_oFDCAN14_6930c8f0_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_PAM_Brk_Rq_RspSts_oBRAKE_FD_7_oFDCAN14_65c28072_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ParkingGearShiftReq_BSM_oBRAKE_FD_2_oFDCAN14_45df8c18_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ParkingInterventionSts_oBRAKE_FD_2_oFDCAN14_9b11ef29_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN14_7bd7d6fa_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d6d9a235_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_aa1206ae_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHF_Spin_oBRAKE_FD_3_oFDCAN14_6be6e272_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_8c24277d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_ba0ad6f6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_78f1815d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHR_Spin_oBRAKE_FD_3_oFDCAN14_54d32262_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_c0695163_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_SPM_Lat_Ctrl_ResponseSts_oEPS_FD_1_oFDCAN14_35f1e4d0_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_Slope_oBRAKE_FD_2_oFDCAN14_a6806d2f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_Steering_Column_Torque_oEPS_FD_1_oFDCAN14_485a089f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_VehicleSpeedVSOSig_B2_oBRAKE2_FD_1_oFDCAN14_1870b968_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN14_66b2f28a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN14_4aa14bb7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_YawRateFailSts_BSM_oBRAKE_FD_2_oFDCAN14_07cbb027_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FD14_YawRate_BSM_oBRAKE_FD_2_oFDCAN14_feebc52b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FL_Lvl_Adj_oASCM_FD_1_oFDCAN2_959485e3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FR_Lvl_Adj_oASCM_FD_1_oFDCAN2_86d8b295_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FR_Lvl_oASCM_FD_1_oFDCAN2_6f14419a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_FT_PAMRequestSts_oBCM_FD_12_oFDCAN2_eca5b16e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Fwrd_Cam_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_195fae0b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GearEngaged_oTRANSM_FD_4_oFDCAN2_d9ac16c5_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_aaf66243_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_64116bfe_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_ee57475b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a6224cad_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_8790eb4d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_46bb2f60_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_75af9a80_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_20b04ee6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_f0b9fb66_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_d237a453_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_1cd0adee_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_67150d6b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_600796f7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_6af6832f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_HU_TRSC_EnableBtn_Sts_oTELEMATIC_FD_11_oFDCAN2_298c059b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Heading_Angle_C2_oGLOB_NAV_FD_C2_oFDCAN2_3c56c554_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ITBM_TrlrStat_oBCM_FD_29_oFDCAN2_144a42ca_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_IgnitionOnCounter_oBCM_FD_7_oFDCAN2_72afbff6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_01eb70e0_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_1316f7bd_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LHF_Spin_oBRAKE_FD_3_oFDCAN2_ddb3a606_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LHRDoorSts_oBCM_FD_9_oFDCAN2_6106f88b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d40a5eb4_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_fd14f99b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LHR_Spin_oBRAKE_FD_3_oFDCAN2_5d756ba0_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LanguageSelection_oIPC_VEHICLE_SETUP_oFDCAN2_99c6c76e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_18f7c44e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_318e470e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LatAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_faefb913_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Latitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_3a18037a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_a123ae38_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_f132a23a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LongAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_38530c91_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Longitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1b6c4b2a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LwsAngleType_oEPS_FD_1_oFDCAN2_aea1ae81_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LwsAngle_oEPS_FD_1_oFDCAN2_4dcc502d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_LwsSpeed_oEPS_FD_1_oFDCAN2_08f75f98_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_MRM_STATUS_C2_oADAS_FD_INFO_C2_oFDCAN2_8ba84d40_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_OperationalModeSts_oBCM_FD_2_oFDCAN2_92d9b16a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PAMRequestSts_oBCM_FD_12_oFDCAN2_006058fe_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PamChimeVolumeFront_oIPC_VEHICLE_SETUP_oFDCAN2_6b01781e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PamChimeVolumeRear_oIPC_VEHICLE_SETUP_oFDCAN2_f55f4149_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PdlPosActual_oENGINE_FD_5_oFDCAN2_743309cb_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PitchRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_3e30fc55_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Pitch_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1cc85bc5_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_99b0bece_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_5757b773_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_dd119bd6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a76a0712_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_05c3c06a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_75fdf3ed_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_46e9460d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_13f6926b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_6708bf5f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_e17178de_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_2f967163_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_5453d1e6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_53414a7a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_59b05fa2_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PsngrDoorSts_oBCM_FD_9_oFDCAN2_661d805a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN2_6b1619cb_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_02ea90a1_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_c8fb14ac_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RHF_Spin_oBRAKE_FD_3_oFDCAN2_ceff9170_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RHRDoorSts_oBCM_FD_9_oFDCAN2_724acffd_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d70bbef5_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_26f91a8a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RHR_Spin_oBRAKE_FD_3_oFDCAN2_4e395cd6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RHatchSts_oBCM_FD_9_oFDCAN2_9f16b516_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RL_Lvl_Adj_oASCM_FD_1_oFDCAN2_44326a37_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RL_Lvl_oASCM_FD_1_oFDCAN2_d1e53ddc_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RR_Lvl_Adj_oASCM_FD_1_oFDCAN2_577e5d41_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RR_Lvl_oASCM_FD_1_oFDCAN2_ccbe2c0f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Rear_Brk_Asst_oIPC_VEHICLE_SETUP_oFDCAN2_96e3f1cb_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RemStActvSts_oBCM_FD_2_oFDCAN2_fb4ede64_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_RollRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_d526080b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Roll_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_90f031c2_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_SBR1RowDriverSeatSts_oORC_FD_1_oFDCAN2_bc99e8d7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_SVC_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_3eb27f57_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ShiftLeverPositionReq_oAGSM_FD_2_oFDCAN2_dff8c8a2_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_ShiftLeverPosition_oTRANSM_FD_4_oFDCAN2_e41ef7f4_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Shifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3841343a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6a63d87_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7ce01122_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dad7e864_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_4c139c4e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d40c7919_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e718ccf9_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b207189f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_5fc9d563_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_4080f22a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e67fb97_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f5a25b12_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f2b0c08e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f841d556_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TCASERANGESTATUS_oDRIVETRAIN_FD_3_oFDCAN2_eee864ec_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TGW_CAMERA_DISP_STAT_oTELEMATIC_FD_14_oFDCAN2_9304ed4e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN2_b7575370_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TRANS_ADAS_Inhibit_oTRANSM_FD_1_oFDCAN2_6ec0c415_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TRSC_CenterBtn_Sts_oTRSKM_FD_1_oFDCAN2_08058c70_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TRSC_EnableBtn_Sts_oTRSKM_FD_1_oFDCAN2_e08a4639_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TRSC_RawKnob_oTRSKM_FD_1_oFDCAN2_88488965_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TransmissionSailingSts_oTRANSM_FD_1_oFDCAN2_86af8834_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_TurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VIN_DATA_oVIN_oFDCAN2_c66224e9_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VIN_MSG_oVIN_oFDCAN2_f39912b4_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN2_53fecdc7_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN2_ae5f13a6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VerticalAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_10e58c6b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD01_ADCM_oPDC_INFO_FD_ADCM_oFDCAN2_bce36ee5_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_603c89e8_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aedb8055_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_249dacf0_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dc09d8b5_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f2e95e62_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_8c71c4cb_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_bf65712b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_ea7aa54d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9a698e4c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_18fd4ff8_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_d61a4645_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_addfe6c0_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aacd7d5c_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_a03c6884_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_YawRate_BSM_oBRAKE_FD_2_oFDCAN2_64569af1_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_YawRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_f8e96c1f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_YawRate_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_c10121c7_Rx(void);

/**********************************************************************************************************************
 * RTE Schedulable entity for COM-Access from different partitions
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic(void);

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* RTE_CBK_H */
