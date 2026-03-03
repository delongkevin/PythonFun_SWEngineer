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
 *             File:  Rte_ErrorMgrSat_1_0_B_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <ErrorMgrSat_1_0_B>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_ERRORMGRSAT_1_0_B_TYPE_H
# define RTE_ERRORMGRSAT_1_0_B_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef ErrorMgr_Error_Battery_UnderVoltage
#   define ErrorMgr_Error_Battery_UnderVoltage (12U)
#  endif

#  ifndef ErrorMgr_Error_Battery_OverVoltage
#   define ErrorMgr_Error_Battery_OverVoltage (13U)
#  endif

#  ifndef ErrorMgr_Error_Vehicle_CanBusoff_CAN2
#   define ErrorMgr_Error_Vehicle_CanBusoff_CAN2 (14U)
#  endif

#  ifndef ErrorMgr_Error_Vehicle_CanBusoff_CAN14
#   define ErrorMgr_Error_Vehicle_CanBusoff_CAN14 (15U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_AGSM_FD2
#   define ErrorMgr_Error_MissingMessage_AGSM_FD2 (16U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_AGSM_FD2
#   define ErrorMgr_Error_DLC_Fault_AGSM_FD2 (17U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BCM_FD2
#   define ErrorMgr_Error_MissingMessage_BCM_FD2 (18U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BCM_FD2
#   define ErrorMgr_Error_DLC_Fault_BCM_FD2 (19U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BCM_FD9
#   define ErrorMgr_Error_MissingMessage_BCM_FD9 (20U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BCM_FD9
#   define ErrorMgr_Error_DLC_Fault_BCM_FD9 (21U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BCM_FD10
#   define ErrorMgr_Error_MissingMessage_BCM_FD10 (22U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BCM_FD10
#   define ErrorMgr_Error_DLC_Fault_BCM_FD10 (23U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BCM_FD12
#   define ErrorMgr_Error_MissingMessage_BCM_FD12 (24U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BCM_FD12
#   define ErrorMgr_Error_DLC_Fault_BCM_FD12 (25U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BCM_FD27
#   define ErrorMgr_Error_MissingMessage_BCM_FD27 (26U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BCM_FD27
#   define ErrorMgr_Error_DLC_Fault_BCM_FD27 (27U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BCM_FD29
#   define ErrorMgr_Error_MissingMessage_BCM_FD29 (28U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BCM_FD29
#   define ErrorMgr_Error_DLC_Fault_BCM_FD29 (29U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_DRIVETRAIN_FD3
#   define ErrorMgr_Error_MissingMessage_DRIVETRAIN_FD3 (30U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_DRIVETRAIN_FD3
#   define ErrorMgr_Error_DLC_Fault_DRIVETRAIN_FD3 (31U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_IPC_VEHICLE_SETUP
#   define ErrorMgr_Error_MissingMessage_IPC_VEHICLE_SETUP (32U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_IPC_VEHICLE_SETUP
#   define ErrorMgr_Error_DLC_Fault_IPC_VEHICLE_SETUP (33U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_IPC_FD1
#   define ErrorMgr_Error_MissingMessage_IPC_FD1 (34U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_IPC_FD1
#   define ErrorMgr_Error_DLC_Fault_IPC_FD1 (35U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_TRANSM_FD1
#   define ErrorMgr_Error_MissingMessage_TRANSM_FD1 (36U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_TRANSM_FD1
#   define ErrorMgr_Error_DLC_Fault_TRANSM_FD1 (37U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_TRANSM_FD2
#   define ErrorMgr_Error_MissingMessage_TRANSM_FD2 (38U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_TRANSM_FD2
#   define ErrorMgr_Error_DLC_Fault_TRANSM_FD2 (39U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_TRANSM_FD4
#   define ErrorMgr_Error_MissingMessage_TRANSM_FD4 (40U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_TRANSM_FD4
#   define ErrorMgr_Error_DLC_Fault_TRANSM_FD4 (41U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_ASCM_FD1
#   define ErrorMgr_Error_MissingMessage_ASCM_FD1 (42U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_ASCM_FD1
#   define ErrorMgr_Error_DLC_Fault_ASCM_FD1 (43U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_ASCM_FD2
#   define ErrorMgr_Error_MissingMessage_ASCM_FD2 (44U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_ASCM_FD2
#   define ErrorMgr_Error_DLC_Fault_ASCM_FD2 (45U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_VIN
#   define ErrorMgr_Error_MissingMessage_VIN (46U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_VIN
#   define ErrorMgr_Error_DLC_Fault_VIN (47U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_TELEMATIC_FD5
#   define ErrorMgr_Error_MissingMessage_TELEMATIC_FD5 (48U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_TELEMATIC_FD5
#   define ErrorMgr_Error_DLC_Fault_TELEMATIC_FD5 (49U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_TELEMATIC_FD14
#   define ErrorMgr_Error_MissingMessage_TELEMATIC_FD14 (50U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_TELEMATIC_FD14
#   define ErrorMgr_Error_DLC_Fault_TELEMATIC_FD14 (51U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_TELEMATIC_FD11
#   define ErrorMgr_Error_MissingMessage_TELEMATIC_FD11 (52U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_TELEMATIC_FD11
#   define ErrorMgr_Error_DLC_Fault_TELEMATIC_FD11 (53U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_Fault_Steering_RackPinion_Ratio_Incorr
#   define ErrorMgr_Error_PROXI_Fault_Steering_RackPinion_Ratio_Incorr (54U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_Fault_Tyre_Size_Incorr
#   define ErrorMgr_Error_PROXI_Fault_Tyre_Size_Incorr (55U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_Fault_PAM_TunSet_Incorr
#   define ErrorMgr_Error_PROXI_Fault_PAM_TunSet_Incorr (56U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_Fault_VehiLineConf_Incorr
#   define ErrorMgr_Error_PROXI_Fault_VehiLineConf_Incorr (57U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_Fault_WB_Incorr
#   define ErrorMgr_Error_PROXI_Fault_WB_Incorr (58U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_Fault_PAM_Config_Incorr
#   define ErrorMgr_Error_PROXI_Fault_PAM_Config_Incorr (59U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_Fault_Radio_Display_Type_Incorr
#   define ErrorMgr_Error_PROXI_Fault_Radio_Display_Type_Incorr (60U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_CAN_Node_Incorr
#   define ErrorMgr_Error_PROXI_CAN_Node_Incorr (61U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_GearBox_Type_Incorr
#   define ErrorMgr_Error_PROXI_GearBox_Type_Incorr (62U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_Model_Year_Incorr
#   define ErrorMgr_Error_PROXI_Model_Year_Incorr (63U)
#  endif

#  ifndef ErrorMgr_Error_PROXI_AutoPark_Sys_Incorr
#   define ErrorMgr_Error_PROXI_AutoPark_Sys_Incorr (64U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BRAKE_FD_1
#   define ErrorMgr_Error_MissingMessage_BRAKE_FD_1 (65U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BRAKE_FD_1
#   define ErrorMgr_Error_DLC_Fault_BRAKE_FD_1 (66U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BRAKE_FD_2
#   define ErrorMgr_Error_MissingMessage_BRAKE_FD_2 (67U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BRAKE_FD_2
#   define ErrorMgr_Error_DLC_Fault_BRAKE_FD_2 (68U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BRAKE_FD_3
#   define ErrorMgr_Error_MissingMessage_BRAKE_FD_3 (69U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BRAKE_FD_3
#   define ErrorMgr_Error_DLC_Fault_BRAKE_FD_3 (70U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BRAKE_FD_4
#   define ErrorMgr_Error_MissingMessage_BRAKE_FD_4 (71U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BRAKE_FD_4
#   define ErrorMgr_Error_DLC_Fault_BRAKE_FD_4 (72U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BRAKE_FD_7
#   define ErrorMgr_Error_MissingMessage_BRAKE_FD_7 (73U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BRAKE_FD_7
#   define ErrorMgr_Error_DLC_Fault_BRAKE_FD_7 (74U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_EPS_FD_2
#   define ErrorMgr_Error_MissingMessage_EPS_FD_2 (75U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_EPS_FD_2
#   define ErrorMgr_Error_DLC_Fault_EPS_FD_2 (76U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_EPS_FD_1
#   define ErrorMgr_Error_MissingMessage_EPS_FD_1 (77U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_EPS_FD_1
#   define ErrorMgr_Error_DLC_Fault_EPS_FD_1 (78U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE1_REF_VEH_SPD_Invld
#   define ErrorMgr_Error_BRAKE1_REF_VEH_SPD_Invld (79U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE1_VehStandStillSts_Invld
#   define ErrorMgr_Error_BRAKE1_VehStandStillSts_Invld (80U)
#  endif

#  ifndef ErrorMgr_Error_BRAKEFD1_ExternalBrkRequestsDisabled
#   define ErrorMgr_Error_BRAKEFD1_ExternalBrkRequestsDisabled (81U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE2_LatAcc_Invld
#   define ErrorMgr_Error_BRAKE2_LatAcc_Invld (82U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE2_LatAcc_FailSts_Invld
#   define ErrorMgr_Error_BRAKE2_LatAcc_FailSts_Invld (83U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE2_LongAcc_Invld
#   define ErrorMgr_Error_BRAKE2_LongAcc_Invld (84U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE2_LongAcc_FailSts_Invld
#   define ErrorMgr_Error_BRAKE2_LongAcc_FailSts_Invld (85U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE2_VehSpd_VSO_Invld
#   define ErrorMgr_Error_BRAKE2_VehSpd_VSO_Invld (86U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE2_YawRate_Invld
#   define ErrorMgr_Error_BRAKE2_YawRate_Invld (87U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE2_YawRate_FailSts_Invld
#   define ErrorMgr_Error_BRAKE2_YawRate_FailSts_Invld (88U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_LatAcc_Offset_Invld
#   define ErrorMgr_Error_BRAKE3_LatAcc_Offset_Invld (89U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_LongAcc_Offset_Invld
#   define ErrorMgr_Error_BRAKE3_LongAcc_Offset_Invld (90U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_LHF_FastPulseCntr_Invld
#   define ErrorMgr_Error_BRAKE3_LHF_FastPulseCntr_Invld (91U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_LHF_Spin_Invld
#   define ErrorMgr_Error_BRAKE3_LHF_Spin_Invld (92U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_LHF_WhlSenFailSts_Invld
#   define ErrorMgr_Error_BRAKE3_LHF_WhlSenFailSts_Invld (93U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_LHR_FastPulseCntr_Invld
#   define ErrorMgr_Error_BRAKE3_LHR_FastPulseCntr_Invld (94U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_LHR_Spin_Invld
#   define ErrorMgr_Error_BRAKE3_LHR_Spin_Invld (95U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_LHR_WhlSenFailSts_Invld
#   define ErrorMgr_Error_BRAKE3_LHR_WhlSenFailSts_Invld (96U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_RHF_FastPulseCntr_Invld
#   define ErrorMgr_Error_BRAKE3_RHF_FastPulseCntr_Invld (97U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_RHF_Spin_Invld
#   define ErrorMgr_Error_BRAKE3_RHF_Spin_Invld (98U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_RHF_WhlSenFailSts_Invld
#   define ErrorMgr_Error_BRAKE3_RHF_WhlSenFailSts_Invld (99U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_RHR_FastPulseCntr_Invld
#   define ErrorMgr_Error_BRAKE3_RHR_FastPulseCntr_Invld (100U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_RHR_Spin_Invld
#   define ErrorMgr_Error_BRAKE3_RHR_Spin_Invld (101U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_RHR_WhlSenFailSts_Invld
#   define ErrorMgr_Error_BRAKE3_RHR_WhlSenFailSts_Invld (102U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_LHF_WhlSpd_Invld
#   define ErrorMgr_Error_BRAKE3_LHF_WhlSpd_Invld (103U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_LHR_WhlSpd_Invld
#   define ErrorMgr_Error_BRAKE3_LHR_WhlSpd_Invld (104U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_RHF_WhlSpd_Invld
#   define ErrorMgr_Error_BRAKE3_RHF_WhlSpd_Invld (105U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE3_RHR_WhlSpd_Invld
#   define ErrorMgr_Error_BRAKE3_RHR_WhlSpd_Invld (106U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE4_EPBSts_Invld
#   define ErrorMgr_Error_BRAKE4_EPBSts_Invld (107U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE5_BSM_THABrkResp_Invld
#   define ErrorMgr_Error_BRAKE5_BSM_THABrkResp_Invld (108U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_BRAKE_FD_5
#   define ErrorMgr_Error_MissingMessage_BRAKE_FD_5 (109U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_BRAKE_FD_5
#   define ErrorMgr_Error_DLC_Fault_BRAKE_FD_5 (110U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE5_ESC_TRSCBrkResp_Invld
#   define ErrorMgr_Error_BRAKE5_ESC_TRSCBrkResp_Invld (111U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BRAKE5
#   define ErrorMgr_Error_CRC_Fault_BRAKE5 (112U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BRAKE5
#   define ErrorMgr_Error_MC_Fault_BRAKE5 (113U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BRAKE2
#   define ErrorMgr_Error_CRC_Fault_BRAKE2 (114U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BRAKE3
#   define ErrorMgr_Error_CRC_Fault_BRAKE3 (115U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BRAKE1
#   define ErrorMgr_Error_CRC_Fault_BRAKE1 (116U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BRAKE4
#   define ErrorMgr_Error_CRC_Fault_BRAKE4 (117U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BRAKE2
#   define ErrorMgr_Error_MC_Fault_BRAKE2 (118U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BRAKE3
#   define ErrorMgr_Error_MC_Fault_BRAKE3 (119U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BRAKE1
#   define ErrorMgr_Error_MC_Fault_BRAKE1 (120U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BRAKE4
#   define ErrorMgr_Error_MC_Fault_BRAKE4 (121U)
#  endif

#  ifndef ErrorMgr_Error_EPS2_THA_DrivrTqOvrride_Invld
#   define ErrorMgr_Error_EPS2_THA_DrivrTqOvrride_Invld (122U)
#  endif

#  ifndef ErrorMgr_Error_EPS2_THA_SteeringTqResp_Invld
#   define ErrorMgr_Error_EPS2_THA_SteeringTqResp_Invld (123U)
#  endif

#  ifndef ErrorMgr_Error_EPS1_SPM_LAT_Ctrl_Resp_Invld
#   define ErrorMgr_Error_EPS1_SPM_LAT_Ctrl_Resp_Invld (124U)
#  endif

#  ifndef ErrorMgr_Error_EPS1_LWS_Angle_Invld
#   define ErrorMgr_Error_EPS1_LWS_Angle_Invld (125U)
#  endif

#  ifndef ErrorMgr_Error_EPS1_LWS_Spd_Invld
#   define ErrorMgr_Error_EPS1_LWS_Spd_Invld (126U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_EPS2
#   define ErrorMgr_Error_CRC_Fault_EPS2 (127U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_EPS2
#   define ErrorMgr_Error_MC_Fault_EPS2 (128U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_EPS1
#   define ErrorMgr_Error_CRC_Fault_EPS1 (129U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_EPS1
#   define ErrorMgr_Error_MC_Fault_EPS1 (130U)
#  endif

#  ifndef ErrorMgr_Error_AGSMD_ShifrLevrPosReq_Invld
#   define ErrorMgr_Error_AGSMD_ShifrLevrPosReq_Invld (131U)
#  endif

#  ifndef ErrorMgr_Error_BCM9_Ext_Temp_Invld
#   define ErrorMgr_Error_BCM9_Ext_Temp_Invld (132U)
#  endif

#  ifndef ErrorMgr_Error_BCM10_CmdIgnSt_Invld
#   define ErrorMgr_Error_BCM10_CmdIgnSt_Invld (133U)
#  endif

#  ifndef ErrorMgr_Error_BCM27_TrailrConnSts_Invld
#   define ErrorMgr_Error_BCM27_TrailrConnSts_Invld (134U)
#  endif

#  ifndef ErrorMgr_Error_BCM29_ITBM_TrailrStat_Invld
#   define ErrorMgr_Error_BCM29_ITBM_TrailrStat_Invld (135U)
#  endif

#  ifndef ErrorMgr_Error_DRIVETRAIN3_TCASERANGESts_Invld
#   define ErrorMgr_Error_DRIVETRAIN3_TCASERANGESts_Invld (136U)
#  endif

#  ifndef ErrorMgr_Error_IPC_VEH_SETUP_LangSel_Invld
#   define ErrorMgr_Error_IPC_VEH_SETUP_LangSel_Invld (137U)
#  endif

#  ifndef ErrorMgr_Error_IPC_VEH_SETUP_PAMChmVol_F_Invld
#   define ErrorMgr_Error_IPC_VEH_SETUP_PAMChmVol_F_Invld (138U)
#  endif

#  ifndef ErrorMgr_Error_IPC_VEH_SETUP_PAMChmVol_R_Invld
#   define ErrorMgr_Error_IPC_VEH_SETUP_PAMChmVol_R_Invld (139U)
#  endif

#  ifndef ErrorMgr_Error_TRANSM1_TargetGear_Invld
#   define ErrorMgr_Error_TRANSM1_TargetGear_Invld (140U)
#  endif

#  ifndef ErrorMgr_Error_TRANSM1_ADAS_Inhibit_Invld
#   define ErrorMgr_Error_TRANSM1_ADAS_Inhibit_Invld (141U)
#  endif

#  ifndef ErrorMgr_Error_TRANSM4_GearEngd_Invld
#   define ErrorMgr_Error_TRANSM4_GearEngd_Invld (142U)
#  endif

#  ifndef ErrorMgr_Error_TRANSM4_ShiftLvrPos_Invld
#   define ErrorMgr_Error_TRANSM4_ShiftLvrPos_Invld (143U)
#  endif

#  ifndef ErrorMgr_Error_VIN_Msg_Invld
#   define ErrorMgr_Error_VIN_Msg_Invld (144U)
#  endif

#  ifndef ErrorMgr_Error_ASCM1_FL_Lvl_Invld
#   define ErrorMgr_Error_ASCM1_FL_Lvl_Invld (145U)
#  endif

#  ifndef ErrorMgr_Error_ASCM1_FR_Lvl_Invld
#   define ErrorMgr_Error_ASCM1_FR_Lvl_Invld (146U)
#  endif

#  ifndef ErrorMgr_Error_ASCM1_RL_Lvl_Invld
#   define ErrorMgr_Error_ASCM1_RL_Lvl_Invld (147U)
#  endif

#  ifndef ErrorMgr_Error_ASCM1_RR_Lvl_Invld
#   define ErrorMgr_Error_ASCM1_RR_Lvl_Invld (148U)
#  endif

#  ifndef ErrorMgr_Error_ASCM2_Stat_Invld
#   define ErrorMgr_Error_ASCM2_Stat_Invld (149U)
#  endif

#  ifndef ErrorMgr_Error_ASCM2_SysFail_Fault
#   define ErrorMgr_Error_ASCM2_SysFail_Fault (150U)
#  endif

#  ifndef ErrorMgr_Error_TRANSM2_GearEngdForDisp_Invld
#   define ErrorMgr_Error_TRANSM2_GearEngdForDisp_Invld (151U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BCM9
#   define ErrorMgr_Error_CRC_Fault_BCM9 (152U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BCM10
#   define ErrorMgr_Error_CRC_Fault_BCM10 (153U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BCM12
#   define ErrorMgr_Error_CRC_Fault_BCM12 (154U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_DRIVETRAIN3
#   define ErrorMgr_Error_CRC_Fault_DRIVETRAIN3 (155U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_TRANSM1
#   define ErrorMgr_Error_CRC_Fault_TRANSM1 (156U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_TRANSM2
#   define ErrorMgr_Error_CRC_Fault_TRANSM2 (157U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_TRANSM4
#   define ErrorMgr_Error_CRC_Fault_TRANSM4 (158U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BCM27
#   define ErrorMgr_Error_CRC_Fault_BCM27 (159U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BCM29
#   define ErrorMgr_Error_CRC_Fault_BCM29 (160U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_AGSM2
#   define ErrorMgr_Error_CRC_Fault_AGSM2 (161U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BCM2
#   define ErrorMgr_Error_MC_Fault_BCM2 (162U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BCM9
#   define ErrorMgr_Error_MC_Fault_BCM9 (163U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BCM10
#   define ErrorMgr_Error_MC_Fault_BCM10 (164U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BCM12
#   define ErrorMgr_Error_MC_Fault_BCM12 (165U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BCM27
#   define ErrorMgr_Error_MC_Fault_BCM27 (166U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BCM29
#   define ErrorMgr_Error_MC_Fault_BCM29 (167U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_DRIVETRAIN3
#   define ErrorMgr_Error_MC_Fault_DRIVETRAIN3 (168U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_TRANSM1
#   define ErrorMgr_Error_MC_Fault_TRANSM1 (169U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_TRANSM2
#   define ErrorMgr_Error_MC_Fault_TRANSM2 (170U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_TRANSM4
#   define ErrorMgr_Error_MC_Fault_TRANSM4 (171U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_AGSM2
#   define ErrorMgr_Error_MC_Fault_AGSM2 (172U)
#  endif

#  ifndef ErrorMgr_Error_TELEMATIC5_CM_TCH_STAT_Invld
#   define ErrorMgr_Error_TELEMATIC5_CM_TCH_STAT_Invld (173U)
#  endif

#  ifndef ErrorMgr_Error_TELEMATIC5_CM_TCH_X_COORD_Invld
#   define ErrorMgr_Error_TELEMATIC5_CM_TCH_X_COORD_Invld (174U)
#  endif

#  ifndef ErrorMgr_Error_TELEMATIC5_CM_TCH_Y_COORD_Invld
#   define ErrorMgr_Error_TELEMATIC5_CM_TCH_Y_COORD_Invld (175U)
#  endif

#  ifndef ErrorMgr_Error_TELEMT11_HU_TRSC_EnBtnSts_Invld
#   define ErrorMgr_Error_TELEMT11_HU_TRSC_EnBtnSts_Invld (176U)
#  endif

#  ifndef ErrorMgr_Error_TELEMT14_TGW_Cam_Disp_St_Invld
#   define ErrorMgr_Error_TELEMT14_TGW_Cam_Disp_St_Invld (177U)
#  endif

#  ifndef ErrorMgr_Error_TELEMT5_CamDispSts_Invld
#   define ErrorMgr_Error_TELEMT5_CamDispSts_Invld (178U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_TELEMT14
#   define ErrorMgr_Error_CRC_Fault_TELEMT14 (179U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_TELEMT14
#   define ErrorMgr_Error_MC_Fault_TELEMT14 (180U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_TELEMT11
#   define ErrorMgr_Error_CRC_Fault_TELEMT11 (181U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_TELEMT11
#   define ErrorMgr_Error_MC_Fault_TELEMT11 (182U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_TELEMT5
#   define ErrorMgr_Error_CRC_Fault_TELEMT5 (183U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_TELEMT5
#   define ErrorMgr_Error_MC_Fault_TELEMT5 (184U)
#  endif

#  ifndef ErrorMgr_Error_BCM12_APAReqSts_Stuck_Fault
#   define ErrorMgr_Error_BCM12_APAReqSts_Stuck_Fault (185U)
#  endif

#  ifndef ErrorMgr_Error_BCM12_PAMReqSts_Stuck_Fault
#   define ErrorMgr_Error_BCM12_PAMReqSts_Stuck_Fault (186U)
#  endif

#  ifndef ErrorMgr_Error_BCM12_FTPAMReqSts_Stuck_Fault
#   define ErrorMgr_Error_BCM12_FTPAMReqSts_Stuck_Fault (187U)
#  endif

#  ifndef ErrorMgr_Error_BRAKE7_PAM_BrkRqRspSts_Invld
#   define ErrorMgr_Error_BRAKE7_PAM_BrkRqRspSts_Invld (188U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BRAKE7
#   define ErrorMgr_Error_CRC_Fault_BRAKE7 (189U)
#  endif

#  ifndef ErrorMgr_Error_MC_Fault_BRAKE7
#   define ErrorMgr_Error_MC_Fault_BRAKE7 (190U)
#  endif

#  ifndef ErrorMgr_Error_EPS1_LWS_Angle_Typ_Invld
#   define ErrorMgr_Error_EPS1_LWS_Angle_Typ_Invld (191U)
#  endif

#  ifndef ErrorMgr_Error_CRC_Fault_BCM2
#   define ErrorMgr_Error_CRC_Fault_BCM2 (192U)
#  endif

#  ifndef ErrorMgr_Error_V_Meas_RearCam_ADC_Ctrl_OORL
#   define ErrorMgr_Error_V_Meas_RearCam_ADC_Ctrl_OORL (193U)
#  endif

#  ifndef ErrorMgr_Error_V_Meas_RearCam_ADC_Ctrl_OORH
#   define ErrorMgr_Error_V_Meas_RearCam_ADC_Ctrl_OORH (194U)
#  endif

#  ifndef ErrorMgr_Error_V_Meas_FrontCam_ADC_Ctrl_OORL
#   define ErrorMgr_Error_V_Meas_FrontCam_ADC_Ctrl_OORL (195U)
#  endif

#  ifndef ErrorMgr_Error_V_Meas_FrontCam_ADC_Ctrl_OORH
#   define ErrorMgr_Error_V_Meas_FrontCam_ADC_Ctrl_OORH (196U)
#  endif

#  ifndef ErrorMgr_Error_V_Meas_LeftCam_ADC_Ctrl_OORL
#   define ErrorMgr_Error_V_Meas_LeftCam_ADC_Ctrl_OORL (197U)
#  endif

#  ifndef ErrorMgr_Error_V_Meas_LeftCam_ADC_Ctrl_OORH
#   define ErrorMgr_Error_V_Meas_LeftCam_ADC_Ctrl_OORH (198U)
#  endif

#  ifndef ErrorMgr_Error_V_Meas_RightCam_ADC_Ctrl_OORL
#   define ErrorMgr_Error_V_Meas_RightCam_ADC_Ctrl_OORL (199U)
#  endif

#  ifndef ErrorMgr_Error_V_Meas_RightCam_ADC_Ctrl_OORH
#   define ErrorMgr_Error_V_Meas_RightCam_ADC_Ctrl_OORH (200U)
#  endif

#  ifndef ErrorMgr_Error_SVC_Cam_Calibration_Fault
#   define ErrorMgr_Error_SVC_Cam_Calibration_Fault (201U)
#  endif

#  ifndef ErrorMgr_Error_ECU_In_Plant_Mode_Fault
#   define ErrorMgr_Error_ECU_In_Plant_Mode_Fault (202U)
#  endif

#  ifndef ErrorMgr_Error_EPS2_EPS_SteeringTqResp_Invld
#   define ErrorMgr_Error_EPS2_EPS_SteeringTqResp_Invld (203U)
#  endif

#  ifndef ErrorMgr_Error_EPS2_THA_SteerTouchStat_Invld
#   define ErrorMgr_Error_EPS2_THA_SteerTouchStat_Invld (204U)
#  endif

#  ifndef ErrorMgr_Error_AGSM2_Shiftr_ADAS_Inhbt_Invld
#   define ErrorMgr_Error_AGSM2_Shiftr_ADAS_Inhbt_Invld (205U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD2
#   define ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD2 (206U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD5
#   define ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD5 (207U)
#  endif

#  ifndef ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD7
#   define ErrorMgr_Error_MissingMessage_ECM_ENGINE_FD7 (208U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD2
#   define ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD2 (209U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD5
#   define ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD5 (210U)
#  endif

#  ifndef ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD7
#   define ErrorMgr_Error_DLC_Fault_ECM_ENGINE_FD7 (211U)
#  endif

#  ifndef ErrorMgr_Error_Engine2_EngineSts_W_ECM_Invld
#   define ErrorMgr_Error_Engine2_EngineSts_W_ECM_Invld (212U)
#  endif

#  ifndef ErrorMgr_Error_Engine_FD_5_ECM_PdlPosActual
#   define ErrorMgr_Error_Engine_FD_5_ECM_PdlPosActual (213U)
#  endif

#  ifndef ErrorMgr_Error_Engine_FD_7_ECM_TRSC_Resp_Invld
#   define ErrorMgr_Error_Engine_FD_7_ECM_TRSC_Resp_Invld (214U)
#  endif

#  ifndef ErrorMgr_Error_Engine_FD_7_ECM_THA_Resp_Invld
#   define ErrorMgr_Error_Engine_FD_7_ECM_THA_Resp_Invld (215U)
#  endif

#  ifndef ErrorMgr_Error_ECM_CRC_Fault_ENGINE2
#   define ErrorMgr_Error_ECM_CRC_Fault_ENGINE2 (216U)
#  endif

#  ifndef ErrorMgr_Error_ECM_MC_Fault_ENGINE2
#   define ErrorMgr_Error_ECM_MC_Fault_ENGINE2 (217U)
#  endif

#  ifndef ErrorMgr_Error_ECM_CRC_Fault_ENGINE7
#   define ErrorMgr_Error_ECM_CRC_Fault_ENGINE7 (218U)
#  endif

#  ifndef ErrorMgr_Error_ECM_MC_Fault_ENGINE7
#   define ErrorMgr_Error_ECM_MC_Fault_ENGINE7 (219U)
#  endif

#  ifndef ErrorMgr_Error_SVC_Rear_Incorrect_Device_ID_Fault
#   define ErrorMgr_Error_SVC_Rear_Incorrect_Device_ID_Fault (220U)
#  endif

#  ifndef ErrorMgr_Error_SVC_Front_Incorrect_Device_ID_Fault
#   define ErrorMgr_Error_SVC_Front_Incorrect_Device_ID_Fault (221U)
#  endif

#  ifndef ErrorMgr_Error_SVC_Left_Incorrect_Device_ID_Fault
#   define ErrorMgr_Error_SVC_Left_Incorrect_Device_ID_Fault (222U)
#  endif

#  ifndef ErrorMgr_Error_SVC_Right_Incorrect_Device_ID_Fault
#   define ErrorMgr_Error_SVC_Right_Incorrect_Device_ID_Fault (223U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_MSPI_E2E_Protect_Fail
#   define ErrorMgr_Error_SysIntFlt_MCU_MSPI_E2E_Protect_Fail (224U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ADC_uncorrectable_ECC
#   define ErrorMgr_Error_SysIntFlt_MCU_ADC_uncorrectable_ECC (225U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ADC_Memory_Violation
#   define ErrorMgr_Error_SysIntFlt_MCU_ADC_Memory_Violation (226U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ADC_Input_Failure
#   define ErrorMgr_Error_SysIntFlt_MCU_ADC_Input_Failure (227U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_UDMA_Configuration_register_mismatch
#   define ErrorMgr_Error_SysIntFlt_Main_UDMA_Configuration_register_mismatch (228U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_UDMA_E2E_protection_failure
#   define ErrorMgr_Error_SysIntFlt_Main_UDMA_E2E_protection_failure (229U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_UDMA_Uncorrectable_ECC_error
#   define ErrorMgr_Error_SysIntFlt_Main_UDMA_Uncorrectable_ECC_error (230U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_CRC_Failure_in_Safety_critical_data_primary_copy
#   define ErrorMgr_Error_SysIntFlt_MCU_CRC_Failure_in_Safety_critical_data_primary_copy (231U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_CRC_Failure_in_Safety_critical_data_second_copy
#   define ErrorMgr_Error_SysIntFlt_MCU_CRC_Failure_in_Safety_critical_data_second_copy (232U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_CRC_Failure_in_Safety_critical_data_primary_second_copy
#   define ErrorMgr_Error_SysIntFlt_MCU_CRC_Failure_in_Safety_critical_data_primary_second_copy (233U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_WD_RST_INT
#   define ErrorMgr_Error_SysIntFlt_MCU_WD_RST_INT (234U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_PMIC_WD_FAIL_CNT
#   define ErrorMgr_Error_SysIntFlt_MCU_PMIC_WD_FAIL_CNT (235U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM7_ILIM_Reached_Threshold
#   define ErrorMgr_Error_SysIntFlt_MCU_SM7_ILIM_Reached_Threshold (236U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM8_Thermal_prewarning_Interrupt
#   define ErrorMgr_Error_SysIntFlt_MCU_SM8_Thermal_prewarning_Interrupt (237U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM12_Redundant_Readback_Error_GPIO_Pin_nRSTOUT_SoC_Pin
#   define ErrorMgr_Error_SysIntFlt_MCU_SM12_Redundant_Readback_Error_GPIO_Pin_nRSTOUT_SoC_Pin (238U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM17_CRC_Error_I2C1_Channel
#   define ErrorMgr_Error_SysIntFlt_MCU_SM17_CRC_Error_I2C1_Channel (239U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors
#   define ErrorMgr_Error_SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors (240U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM4_UV_OV_threshold_reached_in_slave_MCU_Rail_group
#   define ErrorMgr_Error_SysIntFlt_MCU_SM4_UV_OV_threshold_reached_in_slave_MCU_Rail_group (241U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM7_ILIM_Reached_Threshold_Slave
#   define ErrorMgr_Error_SysIntFlt_MCU_SM7_ILIM_Reached_Threshold_Slave (242U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM8_Thermal_prewarning_Interrupt_Slave
#   define ErrorMgr_Error_SysIntFlt_MCU_SM8_Thermal_prewarning_Interrupt_Slave (243U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM17_CRC_Error_I2C1_Channel_Slave
#   define ErrorMgr_Error_SysIntFlt_MCU_SM17_CRC_Error_I2C1_Channel_Slave (244U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors_Slave
#   define ErrorMgr_Error_SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors_Slave (245U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM7_ILIM_Reached_Threshold_HERA
#   define ErrorMgr_Error_SysIntFlt_MCU_SM7_ILIM_Reached_Threshold_HERA (246U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM8_Thermal_prewarning_Interrupt_HERA
#   define ErrorMgr_Error_SysIntFlt_MCU_SM8_Thermal_prewarning_Interrupt_HERA (247U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM17_CRC_Error_I2C1_Channel_HERA
#   define ErrorMgr_Error_SysIntFlt_MCU_SM17_CRC_Error_I2C1_Channel_HERA (248U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors_HERA
#   define ErrorMgr_Error_SysIntFlt_MCU_SM22_Notify_Host_Previously_Detected_Errors_HERA (249U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_DDRSS0_DDRSS_registers_readback_error
#   define ErrorMgr_Error_SysIntFlt_Main_DDRSS0_DDRSS_registers_readback_error (250U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_DDRSS0_Parity_check_failure_in_DDRSS
#   define ErrorMgr_Error_SysIntFlt_Main_DDRSS0_Parity_check_failure_in_DDRSS (251U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_DDRSS0_Two_BIT_and_multibit_ECC_Failure_in_DDR_data
#   define ErrorMgr_Error_SysIntFlt_Main_DDRSS0_Two_BIT_and_multibit_ECC_Failure_in_DDR_data (252U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_CBASS_Mismatch_registers
#   define ErrorMgr_Error_SysIntFlt_MCU_CBASS_Mismatch_registers (253U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_CBASS_Mismatch_registers
#   define ErrorMgr_Error_SysIntFlt_Main_CBASS_Mismatch_registers (254U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_CBASS_Parity_failure_of_override_registers
#   define ErrorMgr_Error_SysIntFlt_MCU_CBASS_Parity_failure_of_override_registers (255U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_CBASS_Parity_failure_of_override_registers
#   define ErrorMgr_Error_SysIntFlt_Main_CBASS_Parity_failure_of_override_registers (256U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_Clock_Loss_input_detected
#   define ErrorMgr_Error_SysIntFlt_MCU_Clock_Loss_input_detected (257U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_Clock_reference_error
#   define ErrorMgr_Error_SysIntFlt_MCU_Clock_reference_error (258U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_Domain_clock_reference_error
#   define ErrorMgr_Error_SysIntFlt_Main_Domain_clock_reference_error (259U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_Clock_failure_detected_safety_relevant_peripheral_clock
#   define ErrorMgr_Error_SysIntFlt_MCU_Clock_failure_detected_safety_relevant_peripheral_clock (260U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_Clock_failure_detected_safety_relevant_peripheral_clock
#   define ErrorMgr_Error_SysIntFlt_Main_Clock_failure_detected_safety_relevant_peripheral_clock (261U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_Clock_PLL_slip_detected
#   define ErrorMgr_Error_SysIntFlt_MCU_Clock_PLL_slip_detected (262U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_Clock_PLL_slip_detected
#   define ErrorMgr_Error_SysIntFlt_Main_Clock_PLL_slip_detected (263U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_Configuration_registers_of_CLK_CTRL_and_PLL_readback_error
#   define ErrorMgr_Error_SysIntFlt_Main_Configuration_registers_of_CLK_CTRL_and_PLL_readback_error (264U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_PWR_Supply_Internal_POK_monitoring_VDD_CORE
#   define ErrorMgr_Error_SysIntFlt_MCU_PWR_Supply_Internal_POK_monitoring_VDD_CORE (265U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_PWR_Supply_Internal_POK_monitoring_VDD_CPU
#   define ErrorMgr_Error_SysIntFlt_Main_PWR_Supply_Internal_POK_monitoring_VDD_CPU (266U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_DMSC_LBIST_error
#   define ErrorMgr_Error_SysIntFlt_DMSC_LBIST_error (267U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_DMSC_ECC_failure_SMS_SRAM
#   define ErrorMgr_Error_SysIntFlt_DMSC_ECC_failure_SMS_SRAM (268U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_DMSC_PBIST_failure_for_memory_space
#   define ErrorMgr_Error_SysIntFlt_DMSC_PBIST_failure_for_memory_space (269U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ESM_Memory_violation_WKUP_ESM0_configuration_registers
#   define ErrorMgr_Error_SysIntFlt_MCU_ESM_Memory_violation_WKUP_ESM0_configuration_registers (270U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ESM_Memory_violation_MCU_ESM0_configuration_registers
#   define ErrorMgr_Error_SysIntFlt_MCU_ESM_Memory_violation_MCU_ESM0_configuration_registers (271U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_ESM_Mismatich_ESM0_configuration_registers
#   define ErrorMgr_Error_SysIntFlt_Main_ESM_Mismatich_ESM0_configuration_registers (272U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ESM_WKUP_I2C0_E2E_protection_failure
#   define ErrorMgr_Error_SysIntFlt_MCU_ESM_WKUP_I2C0_E2E_protection_failure (273U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ESM_I2C_E2E_protection_failure
#   define ErrorMgr_Error_SysIntFlt_MCU_ESM_I2C_E2E_protection_failure (274U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ESM_Memory_violation_in_WKUP_I2C_and_MCU_I2C_configuration_registers
#   define ErrorMgr_Error_SysIntFlt_MCU_ESM_Memory_violation_in_WKUP_I2C_and_MCU_I2C_configuration_registers (275U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_Reset_POST_failure
#   define ErrorMgr_Error_SysIntFlt_MCU_Reset_POST_failure (276U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_Reset_Reset_Configuration_registers_error
#   define ErrorMgr_Error_SysIntFlt_MCU_Reset_Reset_Configuration_registers_error (277U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_Failure_reported_Lockstep_core
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_Failure_reported_Lockstep_core (278U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_LBIST_error
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_LBIST_error (279U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_MPU_Violation_in_R5F_Domain_Core
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_MPU_Violation_in_R5F_Domain_Core (280U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_Illegal_operations_and_instructions_R5F
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_Illegal_operations_and_instructions_R5F (281U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_CPU_Configuration_registers_readback_error
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_CPU_Configuration_registers_readback_error (282U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_ECC_failure_R5F_memory
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_ECC_failure_R5F_memory (283U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_PBIST_check_MemError_Internal_RAMCache_and_Config_registers
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_PBIST_check_MemError_Internal_RAMCache_and_Config_registers (284U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_R5F_PBIST_check_MemError_Internal_RAMCache_and_Config_registers
#   define ErrorMgr_Error_SysIntFlt_Main_R5F_PBIST_check_MemError_Internal_RAMCache_and_Config_registers (285U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_Fault_inject_Test_Failure_on_Memory_ECC
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_Fault_inject_Test_Failure_on_Memory_ECC (286U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_Fault_inject_Test_Failur_on_MPU_functionality
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_Fault_inject_Test_Failur_on_MPU_functionality (287U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_Fault_inject_test_failure_on_illegal_operation_and_instruction
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_Fault_inject_test_failure_on_illegal_operation_and_instruction (288U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_R5F_Fault_inject_Test_Failure_on_Lockstep_Compare
#   define ErrorMgr_Error_SysIntFlt_MCU_R5F_Fault_inject_Test_Failure_on_Lockstep_Compare (289U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_R5F_Program_sequence_error
#   define ErrorMgr_Error_SysIntFlt_Main_R5F_Program_sequence_error (290U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_R5F_LBIST_error
#   define ErrorMgr_Error_SysIntFlt_Main_R5F_LBIST_error (291U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_R5F_CPU_Configuration_registers_readback_error
#   define ErrorMgr_Error_SysIntFlt_Main_R5F_CPU_Configuration_registers_readback_error (292U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_R5F_R5F_Memory_violation
#   define ErrorMgr_Error_SysIntFlt_Main_R5F_R5F_Memory_violation (293U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_R5F_ECC_failure_R5F_memory
#   define ErrorMgr_Error_SysIntFlt_Main_R5F_ECC_failure_R5F_memory (294U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_R5F_Fault_inject_Test_Failur_on_MPU_functionality
#   define ErrorMgr_Error_SysIntFlt_Main_R5F_Fault_inject_Test_Failur_on_MPU_functionality (295U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_R5F_Fault_inject_test_failure_on_illegal_operation_and_instruction
#   define ErrorMgr_Error_SysIntFlt_Main_R5F_Fault_inject_test_failure_on_illegal_operation_and_instruction (296U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_MSRAM_Uncorrectable_ECC_error
#   define ErrorMgr_Error_SysIntFlt_MCU_MSRAM_Uncorrectable_ECC_error (297U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSRAM_Uncorrectable_ECC_error
#   define ErrorMgr_Error_SysIntFlt_Main_MSRAM_Uncorrectable_ECC_error (298U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_MSRAM_Fault_inject_failure_ECC
#   define ErrorMgr_Error_SysIntFlt_MCU_MSRAM_Fault_inject_failure_ECC (299U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSRAM_Fault_inject_failure_ECC
#   define ErrorMgr_Error_SysIntFlt_Main_MSRAM_Fault_inject_failure_ECC (300U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_MSRAM_PBIST_error
#   define ErrorMgr_Error_SysIntFlt_MCU_MSRAM_PBIST_error (301U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSRAM_PBIST_error
#   define ErrorMgr_Error_SysIntFlt_Main_MSRAM_PBIST_error (302U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_MMR_MCUCtrl_WKUPCtrl_Mismatch
#   define ErrorMgr_Error_SysIntFlt_MCU_MMR_MCUCtrl_WKUPCtrl_Mismatch (303U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_MMR_MPU_MemViolation
#   define ErrorMgr_Error_SysIntFlt_MCU_MMR_MPU_MemViolation (304U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_MMR_1_Bit_MCUCtrl_WKUPCtrl_Register_Err
#   define ErrorMgr_Error_SysIntFlt_MCU_MMR_1_Bit_MCUCtrl_WKUPCtrl_Register_Err (305U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_MMR_Parity_Failure
#   define ErrorMgr_Error_SysIntFlt_MCU_MMR_Parity_Failure (306U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MMR_ParityErr_FaultInjection
#   define ErrorMgr_Error_SysIntFlt_Main_MMR_ParityErr_FaultInjection (307U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MMR_CTRL_MMR0_Mismatch
#   define ErrorMgr_Error_SysIntFlt_Main_MMR_CTRL_MMR0_Mismatch (308U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_VTM_OverTemp_Interrupt
#   define ErrorMgr_Error_SysIntFlt_Main_VTM_OverTemp_Interrupt (309U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_VTM_Registers_Mismatch
#   define ErrorMgr_Error_SysIntFlt_Main_VTM_Registers_Mismatch (310U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_GPIO_ConfigReg_Mismatch
#   define ErrorMgr_Error_SysIntFlt_MCU_GPIO_ConfigReg_Mismatch (311U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_GPIO_Memory_Violation
#   define ErrorMgr_Error_SysIntFlt_Main_GPIO_Memory_Violation (312U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_GPIO_Config_Mismatch
#   define ErrorMgr_Error_SysIntFlt_Main_GPIO_Config_Mismatch (313U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSMC_Ctrl_Address_Sig_ParityErr
#   define ErrorMgr_Error_SysIntFlt_Main_MSMC_Ctrl_Address_Sig_ParityErr (314U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_MSMC_ECC_Err
#   define ErrorMgr_Error_SysIntFlt_MCU_MSMC_ECC_Err (315U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSMC_Config_Register_Mismatch
#   define ErrorMgr_Error_SysIntFlt_Main_MSMC_Config_Register_Mismatch (316U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_MSMCParityErr_FaultInjection
#   define ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_MSMCParityErr_FaultInjection (317U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_Err_in_MSMCIntrcnnct
#   define ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_Err_in_MSMCIntrcnnct (318U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSMC_CtrlSig_MSMCIntrcnnct_Chache_Err
#   define ErrorMgr_Error_SysIntFlt_Main_MSMC_CtrlSig_MSMCIntrcnnct_Chache_Err (319U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_Err_in_MSMC_Cache_Tag_Memory
#   define ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_Err_in_MSMC_Cache_Tag_Memory (320U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_Err_SRAMTagData_SRAMData
#   define ErrorMgr_Error_SysIntFlt_Main_MSMC_ECC_Err_SRAMTagData_SRAMData (321U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSMC_Lvl3_Cache_Snoop_On_Chip_SRAM_ParityErr
#   define ErrorMgr_Error_SysIntFlt_Main_MSMC_Lvl3_Cache_Snoop_On_Chip_SRAM_ParityErr (322U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSMC_SRAM_PBIST_Check_Fail
#   define ErrorMgr_Error_SysIntFlt_Main_MSMC_SRAM_PBIST_Check_Fail (323U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_MSMC_Memory_Violation
#   define ErrorMgr_Error_SysIntFlt_Main_MSMC_Memory_Violation (324U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_NAVSS_FaultInjection_Routing_Interrupt_Err
#   define ErrorMgr_Error_SysIntFlt_MCU_NAVSS_FaultInjection_Routing_Interrupt_Err (325U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_NAVSS_NAVSS_Interrupt_Router_Mismatch
#   define ErrorMgr_Error_SysIntFlt_MCU_NAVSS_NAVSS_Interrupt_Router_Mismatch (326U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_Interrupt_FaultInjection_Err
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_Interrupt_FaultInjection_Err (327U)
#  endif

#  ifndef ErrorMgr_Error_SysInrnlFlt_Main_NAVSS_InterruptRouter_Registers_Mismatch
#   define ErrorMgr_Error_SysInrnlFlt_Main_NAVSS_InterruptRouter_Registers_Mismatch (328U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSSInterruptAggregator_Mismatch
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSSInterruptAggregator_Mismatch (329U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_IA_MemSpace_ECC_Err
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_IA_MemSpace_ECC_Err (330U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_FaultInjection_IA_Config_Register_ECC_Err
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_FaultInjection_IA_Config_Register_ECC_Err (331U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_PBIST_Check_Fail
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_PBIST_Check_Fail (332U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_IA_1Bit_Parity_Err
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_IA_1Bit_Parity_Err (333U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_Poll_SourceRegisters_Interrupts_Err
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_Poll_SourceRegisters_Interrupts_Err (334U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_NAVSS_Registers_Mismatch
#   define ErrorMgr_Error_SysIntFlt_MCU_NAVSS_Registers_Mismatch (335U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_NAVSS_NAVSS_IA_Mem_ECC_Err
#   define ErrorMgr_Error_SysIntFlt_MCU_NAVSS_NAVSS_IA_Mem_ECC_Err (336U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_NAVSS_FaultInjection_ECC_Err
#   define ErrorMgr_Error_SysIntFlt_MCU_NAVSS_FaultInjection_ECC_Err (337U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_NAVSS_PBIST_Check_Fail
#   define ErrorMgr_Error_SysIntFlt_MCU_NAVSS_PBIST_Check_Fail (338U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_NAVSS_1Bit_Parity_Err
#   define ErrorMgr_Error_SysIntFlt_MCU_NAVSS_1Bit_Parity_Err (339U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_NAVSS_SourceRegister_Interrupts_Polling_Err
#   define ErrorMgr_Error_SysIntFlt_MCU_NAVSS_SourceRegister_Interrupts_Polling_Err (340U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_NAVSS_FaultInjection_ParityCheck_Err
#   define ErrorMgr_Error_SysIntFlt_MCU_NAVSS_FaultInjection_ParityCheck_Err (341U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_Memory_ECC_Err
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_Memory_ECC_Err (342U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_FaultInjection_ECC_Err
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_FaultInjection_ECC_Err (343U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_1Bit_ParityCheck_Err
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_1Bit_ParityCheck_Err (344U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_FaultInjection_ParityCheck_Err
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_FaultInjection_ParityCheck_Err (345U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_PBIST_Memory_Err
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSSMailbox_PBIST_Memory_Err (346U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck
#   define ErrorMgr_Error_SysIntFlt_MCU_Timer_2TimerSyncCheck (347U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_Timer_SW_Test_Fail
#   define ErrorMgr_Error_SysIntFlt_MCU_Timer_SW_Test_Fail (348U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain
#   define ErrorMgr_Error_SysIntFlt_Main_Timer_2TimerSyncCheck_MainDomain (349U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_Timer_Memory_Violation
#   define ErrorMgr_Error_SysIntFlt_Main_Timer_Memory_Violation (350U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_Timer_StartUpSWTest_Timer
#   define ErrorMgr_Error_SysIntFlt_Main_Timer_StartUpSWTest_Timer (351U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_Timer_ESMErrInterrupt_Timeout
#   define ErrorMgr_Error_SysIntFlt_MCU_Timer_ESMErrInterrupt_Timeout (352U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_VIM_ECC_Err
#   define ErrorMgr_Error_SysIntFlt_MCU_VIM_ECC_Err (353U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_VIM_Register_Config_Mismatch
#   define ErrorMgr_Error_SysIntFlt_MCU_VIM_Register_Config_Mismatch (354U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_VIM_PBIST_MemoryCheck_Fail
#   define ErrorMgr_Error_SysIntFlt_MCU_VIM_PBIST_MemoryCheck_Fail (355U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_VIM_FaultInjection_ECC_Err
#   define ErrorMgr_Error_SysIntFlt_MCU_VIM_FaultInjection_ECC_Err (356U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_VIM_ECC_Err
#   define ErrorMgr_Error_SysIntFlt_Main_VIM_ECC_Err (357U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_VIM_PBIST_MemoryCheck_Err
#   define ErrorMgr_Error_SysIntFlt_Main_VIM_PBIST_MemoryCheck_Err (358U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_VIM_FaultInjection_ECC_err
#   define ErrorMgr_Error_SysIntFlt_Main_VIM_FaultInjection_ECC_err (359U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_VBUSM_ESM_error_interrupt_IP_hung
#   define ErrorMgr_Error_SysIntFlt_Main_VBUSM_ESM_error_interrupt_IP_hung (360U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_VBUSM_parity_protection_Single_bit_error
#   define ErrorMgr_Error_SysIntFlt_MCU_VBUSM_parity_protection_Single_bit_error (361U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_VBUSM_Configuration_mismatch_timeout
#   define ErrorMgr_Error_SysIntFlt_MCU_VBUSM_Configuration_mismatch_timeout (362U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_VBUSM_PBIST_memory_Failure
#   define ErrorMgr_Error_SysIntFlt_MCU_VBUSM_PBIST_memory_Failure (363U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_VBUSM_Parity_detection_Error
#   define ErrorMgr_Error_SysIntFlt_MCU_VBUSM_Parity_detection_Error (364U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_VBUSM_Uncorrectable_ECC_Error
#   define ErrorMgr_Error_SysIntFlt_MCU_VBUSM_Uncorrectable_ECC_Error (365U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_A72_alive_supervision_error
#   define ErrorMgr_Error_SysIntFlt_Main_A72_alive_supervision_error (366U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_A72__configuration_Error
#   define ErrorMgr_Error_SysIntFlt_MCU_A72__configuration_Error (367U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_A72_Ucorrectable_ECC_Error
#   define ErrorMgr_Error_SysIntFlt_MCU_A72_Ucorrectable_ECC_Error (368U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_ePWM_Functionality_error
#   define ErrorMgr_Error_SysIntFlt_Main_ePWM_Functionality_error (369U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_GIC_ECC_Failure
#   define ErrorMgr_Error_SysIntFlt_MCU_GIC_ECC_Failure (370U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ADC_Self_test_failure
#   define ErrorMgr_Error_SysIntFlt_MCU_ADC_Self_test_failure (371U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ADC_PBIST_error
#   define ErrorMgr_Error_SysIntFlt_MCU_ADC_PBIST_error (372U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_ADC_ECC_error
#   define ErrorMgr_Error_SysIntFlt_MCU_ADC_ECC_error (373U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_Memory_Violation
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_Memory_Violation (374U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_Functionality_Error
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_Functionality_Error (375U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_FFI_Memory_Violation
#   define ErrorMgr_Error_SysIntFlt_MCU_FFI_Memory_Violation (376U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_FFI_Memory_Violation
#   define ErrorMgr_Error_SysIntFlt_Main_FFI_Memory_Violation (377U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_FFI_Main_core_MCU_core_Communication__E2E_Protection_error
#   define ErrorMgr_Error_SysIntFlt_MCU_FFI_Main_core_MCU_core_Communication__E2E_Protection_error (378U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_FFI_Main_intra_core_Communication_E2E_Protection_error
#   define ErrorMgr_Error_SysIntFlt_MCU_FFI_Main_intra_core_Communication_E2E_Protection_error (379U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_R1_2_0__FFI_Exec_Timing_error
#   define ErrorMgr_Error_SysIntFlt_R1_2_0__FFI_Exec_Timing_error (380U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_UDMA_Memory_violation_error
#   define ErrorMgr_Error_SysIntFlt_MCU_UDMA_Memory_violation_error (381U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_UDMA_peripheral_inject_error
#   define ErrorMgr_Error_SysIntFlt_Main_UDMA_peripheral_inject_error (382U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_Fault_inject_failure_ECC
#   define ErrorMgr_Error_SysIntFlt_Main_Fault_inject_failure_ECC (383U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_UDMA_PBIST_error
#   define ErrorMgr_Error_SysIntFlt_Main_UDMA_PBIST_error (384U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_UDMA_Fault_inject_failure_ECC
#   define ErrorMgr_Error_SysIntFlt_Main_UDMA_Fault_inject_failure_ECC (385U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_UDMA_ESM_error_invalid_range
#   define ErrorMgr_Error_SysIntFlt_Main_UDMA_ESM_error_invalid_range (386U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_ECC_error
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_ECC_error (387U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_configuration_register_runtime_error
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_configuration_register_runtime_error (388U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_peripheral_inject_error
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_peripheral_inject_error (389U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_Fault_inject_failure_ECC
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_Fault_inject_failure_ECC (390U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_PBIST_error
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_PBIST_error (391U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_Memory_violation_error
#   define ErrorMgr_Error_SysIntFlt_Main_NAVSS_RA_PROXY_Memory_violation_error (392U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_A72_alive_supervision_error
#   define ErrorMgr_Error_SysIntFlt_MCU_A72_alive_supervision_error (393U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_A72_configuration_register_mismatch
#   define ErrorMgr_Error_SysIntFlt_MCU_A72_configuration_register_mismatch (394U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_A72_ECC_uncorrectable_error
#   define ErrorMgr_Error_SysIntFlt_MCU_A72_ECC_uncorrectable_error (395U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_A72_MMU_error
#   define ErrorMgr_Error_SysIntFlt_MCU_A72_MMU_error (396U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_A72_stack_overflow_underflow_error
#   define ErrorMgr_Error_SysIntFlt_MCU_A72_stack_overflow_underflow_error (397U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_A72_heart_beat_signal_not_recieved
#   define ErrorMgr_Error_SysIntFlt_MCU_A72_heart_beat_signal_not_recieved (398U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_GPU_safety_critical_registers_mismatch
#   define ErrorMgr_Error_SysIntFlt_MCU_GPU_safety_critical_registers_mismatch (399U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_GPU_stitching_time_out_error
#   define ErrorMgr_Error_SysIntFlt_MCU_GPU_stitching_time_out_error (400U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_2_1_Main_Domain
#   define ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_2_1_Main_Domain (401U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_2_0_Main_Domain
#   define ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_2_0_Main_Domain (402U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_1_0_MCU_Domain
#   define ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_1_0_MCU_Domain (403U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_1_0_MPU_Domain
#   define ErrorMgr_Error_SysIntFlt_WDG_Health_Monitoring_Failure_1_0_MPU_Domain (404U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM4_UV_OV_threshold_reached_in_Master_MCU_Rail_group
#   define ErrorMgr_Error_SysIntFlt_MCU_SM4_UV_OV_threshold_reached_in_Master_MCU_Rail_group (405U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SM4_UV_OV_threshold_reached_in_HERA_MCU_Rail_group
#   define ErrorMgr_Error_SysIntFlt_MCU_SM4_UV_OV_threshold_reached_in_HERA_MCU_Rail_group (406U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_TRSCCalib_CRC_Error
#   define ErrorMgr_Error_SysIntFlt_MCU_TRSCCalib_CRC_Error (407U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_THACalib_CRC_Error
#   define ErrorMgr_Error_SysIntFlt_MCU_THACalib_CRC_Error (408U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_FODCalib_CRC_Error
#   define ErrorMgr_Error_SysIntFlt_MCU_FODCalib_CRC_Error (409U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_SVSCalib_CRC_Error
#   define ErrorMgr_Error_SysIntFlt_MCU_SVSCalib_CRC_Error (410U)
#  endif

#  ifndef ErrorMgr_Error_SysIntFlt_MCU_APACalib_CRC_Error
#   define ErrorMgr_Error_SysIntFlt_MCU_APACalib_CRC_Error (411U)
#  endif

#  ifndef ErrorMgr_ErrorNum_Max
#   define ErrorMgr_ErrorNum_Max (1112U)
#  endif

#  ifndef ErrorMgr_Invalid
#   define ErrorMgr_Invalid (0U)
#  endif

#  ifndef ErrorMgr_ErrorInactive
#   define ErrorMgr_ErrorInactive (1U)
#  endif

#  ifndef ErrorMgr_ErrorActive
#   define ErrorMgr_ErrorActive (2U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_ERRORMGRSAT_1_0_B_TYPE_H */
