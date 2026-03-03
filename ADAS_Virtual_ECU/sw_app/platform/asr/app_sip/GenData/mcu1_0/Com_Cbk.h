/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Com
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Cbk.h
 *   Generation Time: 2025-07-09 17:10:16
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (COM_CBK_H)
# define COM_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Cot.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/



/**
 * \defgroup ComHandleIdsComRxPdu Handle IDs of handle space ComRxPdu.
 * \brief Rx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_ADAS_FD_INFO_C2_oFDCAN2_f97a3a77_Rx           0u
#define ComConf_ComIPdu_ADAS_FD_INFO_oFDCAN14_fa8dfd08_Rx             1u
#define ComConf_ComIPdu_AGSM_FD_2_oFDCAN2_97b68631_Rx                 2u
#define ComConf_ComIPdu_ASCM_FD_1_oFDCAN2_d84f57a2_Rx                 3u
#define ComConf_ComIPdu_ASCM_FD_2_oFDCAN2_e1c26b67_Rx                 4u
#define ComConf_ComIPdu_BCM_FD_2_oFDCAN2_f3daca1a_Rx                  5u
#define ComConf_ComIPdu_BCM_FD_3_oFDCAN2_e4a1de59_Rx                  6u
#define ComConf_ComIPdu_BCM_FD_7_oFDCAN2_b94d8f55_Rx                  7u
#define ComConf_ComIPdu_BCM_FD_9_oFDCAN2_718f54c7_Rx                  8u
#define ComConf_ComIPdu_BCM_FD_10_oFDCAN2_8d7683ae_Rx                 9u
#define ComConf_ComIPdu_BCM_FD_12_oFDCAN2_a380ab28_Rx                 10u
#define ComConf_ComIPdu_BCM_FD_27_oFDCAN2_02205564_Rx                 11u
#define ComConf_ComIPdu_BCM_FD_29_oFDCAN2_cae28ef6_Rx                 12u
#define ComConf_ComIPdu_BRAKE2_FD_1_oFDCAN2_f0e909db_Rx               13u
#define ComConf_ComIPdu_BRAKE2_FD_1_oFDCAN14_c96aaaae_Rx              14u
#define ComConf_ComIPdu_BRAKE_FD_1_oFDCAN2_5504c66b_Rx                15u
#define ComConf_ComIPdu_BRAKE_FD_1_oFDCAN14_02aef4ed_Rx               16u
#define ComConf_ComIPdu_BRAKE_FD_2_oFDCAN2_6c89faae_Rx                17u
#define ComConf_ComIPdu_BRAKE_FD_2_oFDCAN14_e9994fee_Rx               18u
#define ComConf_ComIPdu_BRAKE_FD_3_oFDCAN2_7bf2eeed_Rx                19u
#define ComConf_ComIPdu_BRAKE_FD_3_oFDCAN14_065b24d0_Rx               20u
#define ComConf_ComIPdu_BRAKE_FD_4_oFDCAN2_1f938324_Rx                21u
#define ComConf_ComIPdu_BRAKE_FD_4_oFDCAN14_e4873fa9_Rx               22u
#define ComConf_ComIPdu_BRAKE_FD_5_oFDCAN2_08e89767_Rx                23u
#define ComConf_ComIPdu_BRAKE_FD_5_oFDCAN14_0b455497_Rx               24u
#define ComConf_ComIPdu_BRAKE_FD_6_oFDCAN14_e072ef94_Rx               25u
#define ComConf_ComIPdu_BRAKE_FD_7_oFDCAN14_0fb084aa_Rx               26u
#define ComConf_ComIPdu_CFG_DATA_CODE_REQUEST_oFDCAN2_03b9e23f_Rx     27u
#define ComConf_ComIPdu_DRIVETRAIN_FD_3_oFDCAN2_8dcee934_Rx           28u
#define ComConf_ComIPdu_ENGINE_FD_2_oFDCAN2_c0c2b657_Rx               29u
#define ComConf_ComIPdu_ENGINE_FD_2_oFDCAN14_2d544e1a_Rx              30u
#define ComConf_ComIPdu_ENGINE_FD_5_oFDCAN2_a4a3db9e_Rx               31u
#define ComConf_ComIPdu_ENGINE_FD_5_oFDCAN14_cf885563_Rx              32u
#define ComConf_ComIPdu_ENGINE_FD_7_oFDCAN2_8a55f318_Rx               33u
#define ComConf_ComIPdu_ENGINE_FD_7_oFDCAN14_cb7d855e_Rx              34u
#define ComConf_ComIPdu_EPS_FD_1_oFDCAN2_cf989270_Rx                  35u
#define ComConf_ComIPdu_EPS_FD_1_oFDCAN14_8851a155_Rx                 36u
#define ComConf_ComIPdu_EPS_FD_2_oFDCAN2_f615aeb5_Rx                  37u
#define ComConf_ComIPdu_EPS_FD_2_oFDCAN14_63661a56_Rx                 38u
#define ComConf_ComIPdu_GLOB_NAV_FD_C2_oFDCAN2_098ddc16_Rx            39u
#define ComConf_ComIPdu_IPC_FD_1_oFDCAN2_0e087dd4_Rx                  40u
#define ComConf_ComIPdu_IPC_VEHICLE_SETUP_oFDCAN2_ddb2e91d_Rx         41u
#define ComConf_ComIPdu_ORC_FD_1_oFDCAN2_f51fa5a1_Rx                  42u
#define ComConf_ComIPdu_PDC_INFO_FD_ADCM_oFDCAN2_36bf9aab_Rx          43u
#define ComConf_ComIPdu_PDC_INFO_FD_BCM_oFDCAN2_8ca0d2c1_Rx           44u
#define ComConf_ComIPdu_PDC_INFO_FD_BSM2_oFDCAN2_f73fa5a4_Rx          45u
#define ComConf_ComIPdu_PDC_INFO_FD_CADM2_oFDCAN2_25d021b9_Rx         46u
#define ComConf_ComIPdu_PDC_INFO_FD_EPS_oFDCAN2_0d00644a_Rx           47u
#define ComConf_ComIPdu_PDC_INFO_FD_ORC_oFDCAN2_479aae82_Rx           48u
#define ComConf_ComIPdu_PDC_INFO_FD_SGW_oFDCAN2_d3dda15f_Rx           49u
#define ComConf_ComIPdu_PDC_INFO_FD_TRLR_REV_oFDCAN2_2234319b_Rx      50u
#define ComConf_ComIPdu_PT_TORQUE_FD_1_oFDCAN14_c23d259d_Rx           51u
#define ComConf_ComIPdu_PntDebugData_Rx_oFDCAN14_5e3489b7_Rx          52u
#define ComConf_ComIPdu_SetUSSParkingMode_oFDCAN14_a3a751a8_Rx        53u
#define ComConf_ComIPdu_TELEMATIC_FD_5_oFDCAN2_e0161ca6_Rx            54u
#define ComConf_ComIPdu_TELEMATIC_FD_11_oFDCAN2_ba15bfe5_Rx           55u
#define ComConf_ComIPdu_TELEMATIC_FD_14_oFDCAN2_f082faaa_Rx           56u
#define ComConf_ComIPdu_TRANSM_FD_1_oFDCAN2_de4da8da_Rx               57u
#define ComConf_ComIPdu_TRANSM_FD_2_oFDCAN2_e7c0941f_Rx               58u
#define ComConf_ComIPdu_TRANSM_FD_4_oFDCAN2_94daed95_Rx               59u
#define ComConf_ComIPdu_TRSKM_FD_1_oFDCAN2_2705233d_Rx                60u
#define ComConf_ComIPdu_VIN_oFDCAN2_e2480108_Rx                       61u
/**\} */

/**
 * \defgroup ComHandleIdsComTxPdu Handle IDs of handle space ComTxPdu.
 * \brief Tx Pdus
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_ADAS_FD_LANES_1_oFDCAN2_2258c462_Tx           0u
#define ComConf_ComIPdu_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx          1u
#define ComConf_ComIPdu_ADAS_FD_LANES_2_oFDCAN2_1bd5f8a7_Tx           2u
#define ComConf_ComIPdu_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx          3u
#define ComConf_ComIPdu_Blockage_Flags_oFDCAN14_a22d2269_Tx           4u
#define ComConf_ComIPdu_CFG_DATA_CODE_RSP_PAM_oFDCAN2_56f16977_Tx     5u
#define ComConf_ComIPdu_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx          6u
#define ComConf_ComIPdu_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx         7u
#define ComConf_ComIPdu_CVPAM_FD_Info_oFDCAN2_a36629be_Tx             8u
#define ComConf_ComIPdu_CVPAM_FD_Info_oFDCAN14_f4e1b059_Tx            9u
#define ComConf_ComIPdu_DIAGNOSTIC_ROE_FD_PAM_oFDCAN2_60d4d54e_Tx     10u
#define ComConf_ComIPdu_DIAGNOSTIC_ROE_PAM_oFDCAN2_f10c61f5_Tx        11u
#define ComConf_ComIPdu_DebugModelOutput_Feature_KPI_Tx_oFDCAN14_b487b5f0_Tx 12u
#define ComConf_ComIPdu_DebugModelOutput_oFDCAN14_00a76e2b_Tx         13u
#define ComConf_ComIPdu_Debug_AP_Variables_oFDCAN14_ad556bd1_Tx       14u
#define ComConf_ComIPdu_Debug_CalibSts_oFDCAN14_5de91463_Tx           15u
#define ComConf_ComIPdu_Debug_CurrentCalib_Data_2_oFDCAN14_a1406486_Tx 16u
#define ComConf_ComIPdu_Debug_EOLCalib_Data_1_oFDCAN14_ced31c72_Tx    17u
#define ComConf_ComIPdu_Debug_EOLCalib_Data_2_oFDCAN14_25e4a771_Tx    18u
#define ComConf_ComIPdu_Debug_ErrCodeAlgo_oFDCAN14_53b8e02d_Tx        19u
#define ComConf_ComIPdu_Debug_FPA_HMI_InfoToVC_oFDCAN14_2e591963_Tx   20u
#define ComConf_ComIPdu_Debug_FeatureCollection_oFDCAN14_c41747ae_Tx  21u
#define ComConf_ComIPdu_Debug_HMI_Input_Data_oFDCAN14_d0bca7c0_Tx     22u
#define ComConf_ComIPdu_Debug_HMI_Internal_Data_oFDCAN14_66bd4100_Tx  23u
#define ComConf_ComIPdu_Debug_HMI_Trailer_Views_Data_oFDCAN14_a6759e51_Tx 24u
#define ComConf_ComIPdu_Debug_ModuleState_oFDCAN14_33fb6c71_Tx        25u
#define ComConf_ComIPdu_Debug_NFCD_Obj_0_4_oFDCAN14_839692dc_Tx       26u
#define ComConf_ComIPdu_Debug_NFCD_Obj_5_9_oFDCAN14_eecb6e7c_Tx       27u
#define ComConf_ComIPdu_Debug_OCCalib_Data_oFDCAN14_81599a4c_Tx       28u
#define ComConf_ComIPdu_Debug_SCCalib_Data_oFDCAN14_fdb6856d_Tx       29u
#define ComConf_ComIPdu_Debug_TargetData_oFDCAN14_de74b1f2_Tx         30u
#define ComConf_ComIPdu_Diagnostics_Flags_oFDCAN14_e99d3c05_Tx        31u
#define ComConf_ComIPdu_Distance_Point_Map_0_oFDCAN14_5a40db7a_Tx     32u
#define ComConf_ComIPdu_Distance_Point_Map_1_oFDCAN14_b582b044_Tx     33u
#define ComConf_ComIPdu_Distance_Point_Map_2_oFDCAN14_5eb50b47_Tx     34u
#define ComConf_ComIPdu_Distance_Point_Map_3_oFDCAN14_b1776079_Tx     35u
#define ComConf_ComIPdu_Distance_Point_Map_4_oFDCAN14_53ab7b00_Tx     36u
#define ComConf_ComIPdu_Distance_Point_Map_5_oFDCAN14_bc69103e_Tx     37u
#define ComConf_ComIPdu_Distance_Point_Map_6_oFDCAN14_575eab3d_Tx     38u
#define ComConf_ComIPdu_Distance_Point_Map_7_oFDCAN14_b89cc003_Tx     39u
#define ComConf_ComIPdu_Distance_Point_Map_8_oFDCAN14_49979b8e_Tx     40u
#define ComConf_ComIPdu_Distance_Point_Map_9_oFDCAN14_a655f0b0_Tx     41u
#define ComConf_ComIPdu_Distance_Point_Map_10_oFDCAN14_e0b543dc_Tx    42u
#define ComConf_ComIPdu_Distance_Point_Map_11_oFDCAN14_0f7728e2_Tx    43u
#define ComConf_ComIPdu_FODDebug_oFDCAN14_6c6e4cde_Tx                 44u
#define ComConf_ComIPdu_FPADebugInfo1_oFDCAN14_58ac202e_Tx            45u
#define ComConf_ComIPdu_Firing_Mode_oFDCAN14_be6e2cf4_Tx              46u
#define ComConf_ComIPdu_Firing_Sensors_oFDCAN14_e037c3cb_Tx           47u
#define ComConf_ComIPdu_Firing_Sequence_oFDCAN14_b74930e6_Tx          48u
#define ComConf_ComIPdu_HMI_Curr_Displayed_Overlays_oFDCAN14_7030d45b_Tx 49u
#define ComConf_ComIPdu_HMI_Curr_Displayed_ProxiConfig_oFDCAN14_5938af7a_Tx 50u
#define ComConf_ComIPdu_HMI_Curr_Requested_Overlays_oFDCAN14_2159e0ee_Tx 51u
#define ComConf_ComIPdu_HMI_Curr_Requested_ProxiConfig_oFDCAN14_15e9b9db_Tx 52u
#define ComConf_ComIPdu_LMD_LaneLinesDebug_1_oFDCAN14_b8b33555_Tx     53u
#define ComConf_ComIPdu_LMD_LaneLinesDebug_2_oFDCAN14_53848e56_Tx     54u
#define ComConf_ComIPdu_LMD_SegmentDebug_1_2_oFDCAN14_dccdef77_Tx     55u
#define ComConf_ComIPdu_LMD_SegmentDebug_1_oFDCAN14_bff9c431_Tx       56u
#define ComConf_ComIPdu_LMD_SegmentDebug_2_1_oFDCAN14_40648684_Tx     57u
#define ComConf_ComIPdu_LMD_SegmentDebug_2_2_oFDCAN14_ab533d87_Tx     58u
#define ComConf_ComIPdu_Log_SnrTemperature_oFDCAN14_a74624f8_Tx       59u
#define ComConf_ComIPdu_ME_DebugMsgSigned_oFDCAN14_128e3dcd_Tx        60u
#define ComConf_ComIPdu_ME_DebugMsgUnsigned_oFDCAN14_a51f0125_Tx      61u
#define ComConf_ComIPdu_ME_Debug_SensorTestData_1_oFDCAN14_368f818b_Tx 62u
#define ComConf_ComIPdu_ME_Debug_SensorTestData_2_oFDCAN14_ddb83a88_Tx 63u
#define ComConf_ComIPdu_ME_Debug_SensorTestData_3_oFDCAN14_327a51b6_Tx 64u
#define ComConf_ComIPdu_ME_MCUOsDebugData1_oFDCAN14_0343bfd6_Tx       65u
#define ComConf_ComIPdu_ME_MCUOsDebugData2_oFDCAN14_e87404d5_Tx       66u
#define ComConf_ComIPdu_ME_SnsDat_Front_Direct_2_oFDCAN14_8dab0270_Tx 67u
#define ComConf_ComIPdu_ME_SnsDat_Front_Direct_oFDCAN14_ef61fa06_Tx   68u
#define ComConf_ComIPdu_ME_SnsDat_Front_Indirect_1_oFDCAN14_2964c778_Tx 69u
#define ComConf_ComIPdu_ME_SnsDat_Front_Indirect_2_oFDCAN14_c2537c7b_Tx 70u
#define ComConf_ComIPdu_ME_SnsDat_Rear_Direct_2_oFDCAN14_b9e07ed5_Tx  71u
#define ComConf_ComIPdu_ME_SnsDat_Rear_Direct_oFDCAN14_25ea33b4_Tx    72u
#define ComConf_ComIPdu_ME_SnsDat_Rear_Indirect_1_oFDCAN14_a3a78688_Tx 73u
#define ComConf_ComIPdu_ME_SnsDat_Rear_Indirect_2_oFDCAN14_48903d8b_Tx 74u
#define ComConf_ComIPdu_ME_SystemDebugData_1_oFDCAN14_73975cf6_Tx     75u
#define ComConf_ComIPdu_ME_SystemStatus_oFDCAN14_19d0baf4_Tx          76u
#define ComConf_ComIPdu_MOT_Obj_0_1_oFDCAN14_7e1d9089_Tx              77u
#define ComConf_ComIPdu_MOT_Obj_2_3_oFDCAN14_96d3de2b_Tx              78u
#define ComConf_ComIPdu_MOT_Obj_4_5_oFDCAN14_74f00b8c_Tx              79u
#define ComConf_ComIPdu_MOT_Obj_6_7_oFDCAN14_9c3e452e_Tx              80u
#define ComConf_ComIPdu_MOT_Obj_8_9_oFDCAN14_6bc6a683_Tx              81u
#define ComConf_ComIPdu_Minimum_Sensor_Distance_1_oFDCAN14_c7b01029_Tx 82u
#define ComConf_ComIPdu_Minimum_Sensor_Distance_2_oFDCAN14_2c87ab2a_Tx 83u
#define ComConf_ComIPdu_Minimum_Sensor_Distance_3_oFDCAN14_c345c014_Tx 84u
#define ComConf_ComIPdu_PDC_INFO_FD_PAM_oFDCAN2_7ecf7ff6_Tx           85u
#define ComConf_ComIPdu_PLDDebugInfo1_oFDCAN14_d4cfffd1_Tx            86u
#define ComConf_ComIPdu_PLDDebugInfo2_oFDCAN14_3ff844d2_Tx            87u
#define ComConf_ComIPdu_PntDebugData_0_oFDCAN14_8f00be64_Tx           88u
#define ComConf_ComIPdu_PntDebugData_1_oFDCAN14_60c2d55a_Tx           89u
#define ComConf_ComIPdu_PntDebugData_2_oFDCAN14_8bf56e59_Tx           90u
#define ComConf_ComIPdu_PntDebugData_3_oFDCAN14_64370567_Tx           91u
#define ComConf_ComIPdu_THADebugInfo1_oFDCAN14_b11db875_Tx            92u
#define ComConf_ComIPdu_THADebugInfo2_oFDCAN14_5a2a0376_Tx            93u
#define ComConf_ComIPdu_TRSCM_FD_1_oFDCAN2_e88cefba_Tx                94u
#define ComConf_ComIPdu_TRSCM_FD_1_oFDCAN14_f3c79e86_Tx               95u
#define ComConf_ComIPdu_TRSC_Debug_Message1_oFDCAN14_4a774fd0_Tx      96u
#define ComConf_ComIPdu_TRSC_Debug_Message2_oFDCAN14_a140f4d3_Tx      97u
#define ComConf_ComIPdu_TRSC_Debug_Message3_oFDCAN14_4e829fed_Tx      98u
#define ComConf_ComIPdu_TRSC_Detection_DebugMessage_oFDCAN14_8347a9d4_Tx 99u
#define ComConf_ComIPdu_TRSC_FID_DebugMessage_oFDCAN14_6fc274ff_Tx    100u
#define ComConf_ComIPdu_USSDebugInfo1_oFDCAN14_99359865_Tx            101u
#define ComConf_ComIPdu_USSDebugInfo2_oFDCAN14_72022366_Tx            102u
#define ComConf_ComIPdu_USS_SectorInfoFB_oFDCAN14_4d009437_Tx         103u
#define ComConf_ComIPdu_UssCsmStateChangeReasons_oFDCAN14_338dbf06_Tx 104u
/**\} */

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /*MD_MSR_MemMap */
/**********************************************************************************************************************
  Com_RxIndication
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after an I-PDU has been received.
    \param[in]    RxPduId      ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
                               Range: 0..(maximum number of I-PDU IDs received by AUTOSAR COM) - 1
    \param[in]    PduInfoPtr   Payload information of the received I-PDU (pointer to data and data length).
    \return       none
    \context      The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used.
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737026
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
  Com_TxConfirmation
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after the PDU has been transmitted on the network.
                  A confirmation that is received for an I-PDU that does not require a confirmation is silently discarded.
    \param[in]    TxPduId   ID of AUTOSAR COM I-PDU that has been transmitted.
                            Range: 0..(maximum number of I-PDU IDs transmitted by AUTOSAR COM) - 1
    \return       none
    \context      The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used.
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737028
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType TxPduId);



#define COM_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_MemMap */

#endif  /* COM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cbk.h
**********************************************************************************************************************/

