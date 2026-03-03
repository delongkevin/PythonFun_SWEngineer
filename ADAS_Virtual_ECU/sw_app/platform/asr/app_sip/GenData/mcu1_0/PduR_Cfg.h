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
 *            Module: PduR
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Cfg.h
 *   Generation Time: 2025-07-09 17:10:15
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (PDUR_CFG_H)
# define PDUR_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef PDUR_USE_DUMMY_STATEMENT
#define PDUR_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT_CONST
#define PDUR_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef PDUR_ATOMIC_VARIABLE_ACCESS
#define PDUR_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef PDUR_PROCESSOR_TDA4VE88
#define PDUR_PROCESSOR_TDA4VE88
#endif
#ifndef PDUR_COMP_LLVMTEXASINSTRUMENTS
#define PDUR_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef PDUR_GEN_GENERATOR_MSR
#define PDUR_GEN_GENERATOR_MSR
#endif
#ifndef PDUR_CPUTYPE_BITORDER_LSB2MSB
#define PDUR_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#define PDUR_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_LINKTIME
#define PDUR_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef PDUR_CONFIGURATION_VARIANT
#define PDUR_CONFIGURATION_VARIANT PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef PDUR_POSTBUILD_VARIANT_SUPPORT
#define PDUR_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



#define PDUR_DEV_ERROR_DETECT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSafeBswChecks] || /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */
#define PDUR_DEV_ERROR_REPORT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */

#define PDUR_EXTENDED_ERROR_CHECKS STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRExtendedErrorChecks] */

#define PDUR_METADATA_SUPPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRMetaDataSupport] */
#define PDUR_VERSION_INFO_API STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRVersionInfoApi] */

#define PDUR_ERROR_NOTIFICATION STD_OFF

#define PDUR_MAIN_FUNCTION STD_OFF

#define PDUR_MULTICORE STD_OFF /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] */

#define PduR_PBConfigIdType uint32

 
 /*  DET Error define list  */ 
#define PDUR_FCT_CANIFRXIND 0x01u 
#define PDUR_FCT_CANIFTX 0x09u 
#define PDUR_FCT_CANIFTXCFM 0x02u 
#define PDUR_FCT_CANTPRXIND 0x05u 
#define PDUR_FCT_CANTPTX 0x09u 
#define PDUR_FCT_CANTPTXCFM 0x08u 
#define PDUR_FCT_CANTPSOR 0x06u 
#define PDUR_FCT_CANTPCPYRX 0x04u 
#define PDUR_FCT_CANTPCPYTX 0x07u 
#define PDUR_FCT_COMTX 0x89u 
#define PDUR_FCT_DCMTX 0x99u 
#define PDUR_FCT_DCMCTX 0x9Au 
#define PDUR_FCT_CDD_USSLOGTX 0xC9u 
 /*   PduR_CanIfIfRxIndication  PduR_CanIfTransmit  PduR_CanIfTxConfirmation  PduR_CanTpTpRxIndication  PduR_CanTpTransmit  PduR_CanTpTxConfirmation  PduR_CanTpStartOfReception  PduR_CanTpCopyRxData  PduR_CanTpCopyTxData  PduR_ComTransmit  PduR_DcmTransmit  PduR_DcmCancelTransmit  PduR_Cdd_UssLogTransmit  */ 



/**
 * \defgroup PduRHandleIdsIfRxDest Handle IDs of handle space IfRxDest.
 * \brief Communication interface Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_ADAS_FD_INFO_C2_oFDCAN2_3ce9cdd9_Rx_c7180dec_Rx 0u
#define PduRConf_PduRDestPdu_ADAS_FD_INFO_oFDCAN14_a55fd54d_Rx_a7c45d7d_Rx 1u
#define PduRConf_PduRDestPdu_AGSM_FD_2_oFDCAN2_9af9f599_Rx_edfa5d4e_Rx 2u
#define PduRConf_PduRDestPdu_ASCM_FD_1_oFDCAN2_2db9ba19_Rx_1edc6963_Rx 3u
#define PduRConf_PduRDestPdu_ASCM_FD_2_oFDCAN2_18540c4a_Rx_ede52381_Rx 4u
#define PduRConf_PduRDestPdu_BCM_FD_2_oFDCAN2_3071d90c_Rx_44196b0f_Rx 5u
#define PduRConf_PduRDestPdu_BCM_FD_3_oFDCAN2_95fa4902_Rx_bf2e5cd2_Rx 6u
#define PduRConf_PduRDestPdu_BCM_FD_7_oFDCAN2_6e4703f9_Rx_7d500349_Rx 7u
#define PduRConf_PduRDestPdu_BCM_FD_9_oFDCAN2_2997fce8_Rx_ffb63425_Rx 8u
#define PduRConf_PduRDestPdu_BCM_FD_10_oFDCAN2_d1dc27ad_Rx_88cfc416_Rx 9u
#define PduRConf_PduRDestPdu_BCM_FD_12_oFDCAN2_41ba01f0_Rx_9203d069_Rx 10u
#define PduRConf_PduRDestPdu_BCM_FD_27_oFDCAN2_eddb36fd_Rx_5542795d_Rx 11u
#define PduRConf_PduRDestPdu_BCM_FD_29_oFDCAN2_aa0bc9ec_Rx_f737c45a_Rx 12u
#define PduRConf_PduRDestPdu_BRAKE2_FD_1_oFDCAN2_13e6bf8d_Rx_f29b81fe_Rx 13u
#define PduRConf_PduRDestPdu_BRAKE2_FD_1_oFDCAN14_e3eb706b_Rx_a31db230_Rx 14u
#define PduRConf_PduRDestPdu_BRAKE_FD_1_oFDCAN2_d89892a0_Rx_571b255a_Rx 15u
#define PduRConf_PduRDestPdu_BRAKE_FD_1_oFDCAN14_861ebd8f_Rx_010cb7aa_Rx 16u
#define PduRConf_PduRDestPdu_BRAKE_FD_2_oFDCAN2_ed7524f3_Rx_69af14e5_Rx 17u
#define PduRConf_PduRDestPdu_BRAKE_FD_2_oFDCAN14_358a904c_Rx_9c687493_Rx 18u
#define PduRConf_PduRDestPdu_BRAKE_FD_3_oFDCAN2_48feb4fd_Rx_a96d8b06_Rx 19u
#define PduRConf_PduRDestPdu_BRAKE_FD_3_oFDCAN14_5b068b0d_Rx_536023d7_Rx 20u
#define PduRConf_PduRDestPdu_BRAKE_FD_4_oFDCAN2_86ae4855_Rx_8bfd03c9_Rx 21u
#define PduRConf_PduRDestPdu_BRAKE_FD_4_oFDCAN14_89d3cd8b_Rx_3917797c_Rx 22u
#define PduRConf_PduRDestPdu_BRAKE_FD_5_oFDCAN2_2325d85b_Rx_7b57434e_Rx 23u
#define PduRConf_PduRDestPdu_BRAKE_FD_5_oFDCAN14_e75fd6ca_Rx_22a4d3fd_Rx 24u
#define PduRConf_PduRDestPdu_BRAKE_FD_6_oFDCAN14_54cbfb09_Rx_7cdde702_Rx 25u
#define PduRConf_PduRDestPdu_BRAKE_FD_7_oFDCAN14_3a47e048_Rx_ea1aa754_Rx 26u
#define PduRConf_PduRDestPdu_CFG_DATA_CODE_REQUEST_oFDCAN2_f0797e1f_Rx_fcb49c19_Rx 27u
#define PduRConf_PduRDestPdu_DRIVETRAIN_FD_3_oFDCAN2_a178c37e_Rx_ded4397c_Rx 28u
#define PduRConf_PduRDestPdu_ENGINE_FD_2_oFDCAN2_bbb4bd5c_Rx_7be870cb_Rx 29u
#define PduRConf_PduRDestPdu_ENGINE_FD_2_oFDCAN14_95c64d4b_Rx_5302daec_Rx 30u
#define PduRConf_PduRDestPdu_ENGINE_FD_5_oFDCAN2_75e441f4_Rx_1160b0c4_Rx 31u
#define PduRConf_PduRDestPdu_ENGINE_FD_5_oFDCAN14_47130bcd_Rx_60b0950b_Rx 32u
#define PduRConf_PduRDestPdu_ENGINE_FD_7_oFDCAN2_e58267a9_Rx_91888c03_Rx 33u
#define PduRConf_PduRDestPdu_ENGINE_FD_7_oFDCAN14_9a0b3d4f_Rx_78022248_Rx 34u
#define PduRConf_PduRDestPdu_EPS_FD_1_oFDCAN2_8187a19a_Rx_da0c1a40_Rx 35u
#define PduRConf_PduRDestPdu_EPS_FD_1_oFDCAN14_1c675bff_Rx_3c3be572_Rx 36u
#define PduRConf_PduRDestPdu_EPS_FD_2_oFDCAN2_b46a17c9_Rx_0f370d19_Rx 37u
#define PduRConf_PduRDestPdu_EPS_FD_2_oFDCAN14_aff3763c_Rx_aa61fa9f_Rx 38u
#define PduRConf_PduRDestPdu_GLOB_NAV_FD_C2_oFDCAN2_93cc1f91_Rx_e918f131_Rx 39u
#define PduRConf_PduRDestPdu_IPC_FD_1_oFDCAN2_63f5b3e6_Rx_02099541_Rx 40u
#define PduRConf_PduRDestPdu_IPC_VEHICLE_SETUP_oFDCAN2_a22ca3c4_Rx_d78ab2ca_Rx 41u
#define PduRConf_PduRDestPdu_ORC_FD_1_oFDCAN2_3775757b_Rx_6630d5d3_Rx 42u
#define PduRConf_PduRDestPdu_PDC_INFO_FD_ADCM_oFDCAN2_b5d3e253_Rx_8a512cba_Rx 43u
#define PduRConf_PduRDestPdu_PDC_INFO_FD_BCM_oFDCAN2_d0394486_Rx_7ea80a52_Rx 44u
#define PduRConf_PduRDestPdu_PDC_INFO_FD_BSM2_oFDCAN2_e01465fe_Rx_6911e70b_Rx 45u
#define PduRConf_PduRDestPdu_PDC_INFO_FD_CADM2_oFDCAN2_5b04fff1_Rx_29906768_Rx 46u
#define PduRConf_PduRDestPdu_PDC_INFO_FD_EPS_oFDCAN2_452e6cff_Rx_41ead865_Rx 47u
#define PduRConf_PduRDestPdu_PDC_INFO_FD_ORC_oFDCAN2_17e9e0f6_Rx_fb43a35e_Rx 48u
#define PduRConf_PduRDestPdu_PDC_INFO_FD_SGW_oFDCAN2_2e2ff0c8_Rx_e656730e_Rx 49u
#define PduRConf_PduRDestPdu_PDC_INFO_FD_TRLR_REV_oFDCAN2_e488d728_Rx_62f2c61a_Rx 50u
#define PduRConf_PduRDestPdu_PT_TORQUE_FD_1_oFDCAN14_0134da63_Rx_8efc5a15_Rx 51u
#define PduRConf_PduRDestPdu_PntDebugData_Rx_oFDCAN14_481d274d_Rx_92dfc557_Rx 52u
#define PduRConf_PduRDestPdu_SetUSSParkingMode_oFDCAN14_bb071e4b_Rx_b7893264_Rx 53u
#define PduRConf_PduRDestPdu_TELEMATIC_FD_5_oFDCAN2_39a02182_Rx_9ce57069_Rx 54u
#define PduRConf_PduRDestPdu_TELEMATIC_FD_11_oFDCAN2_a69db35a_Rx_1f2567dc_Rx 55u
#define PduRConf_PduRDestPdu_TELEMATIC_FD_14_oFDCAN2_f8ab69af_Rx_8c549050_Rx 56u
#define PduRConf_PduRDestPdu_TRANSM_FD_1_oFDCAN2_dc1464b5_Rx_f9e5605f_Rx 57u
#define PduRConf_PduRDestPdu_TRANSM_FD_2_oFDCAN2_e9f9d2e6_Rx_a2f37aee_Rx 58u
#define PduRConf_PduRDestPdu_TRANSM_FD_4_oFDCAN2_8222be40_Rx_3f93ac02_Rx 59u
#define PduRConf_PduRDestPdu_TRSKM_FD_1_oFDCAN2_3bc9104a_Rx_caa8877e_Rx 60u
#define PduRConf_PduRDestPdu_VIN_oFDCAN2_664087b5_Rx_b7bdbd30_Rx      61u
/**\} */

/**
 * \defgroup PduRHandleIdsIfRxSrc Handle IDs of handle space IfRxSrc.
 * \brief Communication interface Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0f370d19                       37u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1edc6963                       3u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1f2567dc                       55u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3c3be572                       36u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3f93ac02                       59u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7b57434e                       23u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7be870cb                       29u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7cdde702                       25u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7d500349                       7u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7ea80a52                       44u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8a512cba                       43u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8bfd03c9                       21u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8c549050                       56u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8efc5a15                       51u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9c687493                       18u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9ce57069                       54u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_22a4d3fd                       24u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_41ead865                       47u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_60b0950b                       32u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_62f2c61a                       50u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_69af14e5                       17u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_88cfc416                       9u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_92dfc557                       52u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_010cb7aa                       16u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_571b255a                       15u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1160b0c4                       31u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5302daec                       30u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6630d5d3                       42u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6911e70b                       45u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9203d069                       10u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_44196b0f                       5u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_91888c03                       33u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_536023d7                       20u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3917797c                       22u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5542795d                       11u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_02099541                       40u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_29906768                       46u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_78022248                       34u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a2f37aee                       58u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a7c45d7d                       1u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a31db230                       14u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a96d8b06                       19u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_aa61fa9f                       38u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b7bdbd30                       61u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b7893264                       53u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bf2e5cd2                       6u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c7180dec                       0u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_caa8877e                       60u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d78ab2ca                       41u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_da0c1a40                       35u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ded4397c                       28u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e918f131                       39u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e656730e                       49u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ea1aa754                       26u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ede52381                       4u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_edfa5d4e                       2u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f9e5605f                       57u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f29b81fe                       13u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f737c45a                       12u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fb43a35e                       48u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fcb49c19                       27u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ffb63425                       8u
/**\} */

/**
 * \defgroup PduRHandleIdsIfTpTxSrc Handle IDs of handle space IfTpTxSrc.
 * \brief Communication interface and transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0d83ad0d                       15u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0d89d795                       82u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0f917068                       71u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1fd96fd5                       30u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2c9622aa                       57u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2f74beb6                       105u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3d4f267c                       109u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3d54ad71                       91u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3e6363a7                       53u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3fe80968                       104u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4a89c027                       117u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4c3354d5                       64u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4d0e8da8                       56u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4fd42681                       94u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5cbdc88a                       102u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5dfea50f                       98u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6a3bdec4                       70u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6a05b7f9                       21u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6bf8a708                       95u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6db30f7a                       26u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7b41086b                       69u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7c7d83cb                       103u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7fd1469a                       6u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8a4f2322                       40u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8b616172                       12u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8e993e9d                       2u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9b3a0dc2                       62u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9bc0124e                       33u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9d508691                       78u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9da562d1                       8u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_06add09a                       5u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_14e82cb0                       75u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_23d3eab5                       114u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_24e0c614                       36u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_29cc8cc9                       112u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_31f1f327                       92u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_43c8c80b                       106u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_45b1ddd7                       84u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_46a165ae                       18u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_46f4792c                       58u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_52d1ab4f                       47u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_54c672cc                       31u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_55fe29ee                       34u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_56bb1cda                       32u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_64c495bf                       22u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_69d38c9c                       116u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_81d06a10                       79u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_89f2f86d                       43u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_036d6a43                       80u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_042e3f8c                       10u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_046ba2f9                       97u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_088b5cb2                       19u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_449ee227                       88u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_549ae1db                       45u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_603bb742                       110u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_615c44f0                       68u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_634dabfc                       23u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_703eb300                       101u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_919e7b1e                       65u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1042f3c2                       50u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3925f43f                       13u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5010c127                       27u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5718ac60                       81u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6038e225                       93u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_20355d3f                       85u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_50134c72                       63u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_51493f0c                       61u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_74298cac                       74u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_95755eb6                       111u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_098444c3                       59u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_135671e0                       14u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_770508de                       66u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_782325e5                       4u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4239045a                       87u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a25cde99                       83u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a27f7930                       11u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a61fa37b                       52u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ac70e828                       29u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ae34d87e                       9u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_aef6db3c                       86u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b1ea4624                       89u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b2a869ec                       17u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b34a10e6                       0u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b134addd                       77u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b3669d95                       41u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b6572f92                       108u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bc471ad4                       67u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_be85d26b                       60u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_be063e34                       113u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c4e0a670                       99u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c9b02821                       72u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c37785b8                       46u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_cc1d86f5                       76u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d8aac21d                       1u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d27a4076                       24u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d40b95bf                       28u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d8825a77                       44u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d5379018                       55u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dadc8b69                       96u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e0b39384                       73u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e5b1c164                       90u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e80ef8c0                       51u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e95b61d0                       7u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e8988ff7                       20u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e33865f2                       42u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_eeb2db14                       107u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ef46a1ae                       35u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ef84c718                       48u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f0d8d493                       54u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f9f2a2bd                       25u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f26cd3a4                       39u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f30a0b0c                       49u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f900a90f                       115u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f01792f6                       16u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f65201f2                       38u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fb2e887f                       3u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fc7ecfd5                       100u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ff0919c6                       37u
/**\} */

/**
 * \defgroup PduRHandleIdsIfTxDest Handle IDs of handle space IfTxDest.
 * \brief Communication interface Tx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_ADAS_FD_LANES_1_oFDCAN2_671c0d83_Tx      0u
#define PduRConf_PduRDestPdu_ADAS_FD_LANES_1_oFDCAN14_5807fbbf_Tx     1u
#define PduRConf_PduRDestPdu_ADAS_FD_LANES_2_oFDCAN2_52f1bbd0_Tx      2u
#define PduRConf_PduRDestPdu_ADAS_FD_LANES_2_oFDCAN14_eb93d67c_Tx     3u
#define PduRConf_PduRDestPdu_Blockage_Flags_oFDCAN14_99421024_Tx      4u
#define PduRConf_PduRDestPdu_CFG_DATA_CODE_RSP_PAM_oFDCAN2_5b222c4a_Tx 5u
#define PduRConf_PduRDestPdu_CVPAM_FD_Control_oFDCAN2_b23be072_Tx     6u
#define PduRConf_PduRDestPdu_CVPAM_FD_Control_oFDCAN14_8b1b60a1_Tx    7u
#define PduRConf_PduRDestPdu_CVPAM_FD_Info_oFDCAN2_b99cd129_Tx        8u
#define PduRConf_PduRDestPdu_CVPAM_FD_Info_oFDCAN14_838aefa3_Tx       9u
#define PduRConf_PduRDestPdu_DIAGNOSTIC_ROE_FD_PAM_oFDCAN2_5ecfbbbe_Tx 10u
#define PduRConf_PduRDestPdu_DIAGNOSTIC_ROE_PAM_oFDCAN2_ff776c1c_Tx   11u
#define PduRConf_PduRDestPdu_DebugModelOutput_Feature_KPI_Tx_oFDCAN14_2d37299a_Tx 12u
#define PduRConf_PduRDestPdu_DebugModelOutput_oFDCAN14_1f951e1f_Tx    13u
#define PduRConf_PduRDestPdu_Debug_AP_Variables_oFDCAN14_9068652c_Tx  14u
#define PduRConf_PduRDestPdu_Debug_CalibSts_oFDCAN14_386fe58e_Tx      15u
#define PduRConf_PduRDestPdu_Debug_CurrentCalib_Data_2_oFDCAN14_2917323d_Tx 16u
#define PduRConf_PduRDestPdu_Debug_EOLCalib_Data_1_oFDCAN14_e983026d_Tx 17u
#define PduRConf_PduRDestPdu_Debug_EOLCalib_Data_2_oFDCAN14_5a172fae_Tx 18u
#define PduRConf_PduRDestPdu_Debug_ErrCodeAlgo_oFDCAN14_8f5e00dc_Tx   19u
#define PduRConf_PduRDestPdu_Debug_FPA_HMI_InfoToVC_oFDCAN14_250b6023_Tx 20u
#define PduRConf_PduRDestPdu_Debug_FeatureCollection_oFDCAN14_c2b58aba_Tx 21u
#define PduRConf_PduRDestPdu_Debug_HMI_Input_Data_oFDCAN14_f2609efd_Tx 22u
#define PduRConf_PduRDestPdu_Debug_HMI_Internal_Data_oFDCAN14_4a1b027e_Tx 23u
#define PduRConf_PduRDestPdu_Debug_HMI_Trailer_Views_Data_oFDCAN14_14db284c_Tx 24u
#define PduRConf_PduRDestPdu_Debug_ModuleState_oFDCAN14_fcd53415_Tx   25u
#define PduRConf_PduRDestPdu_Debug_NFCD_Obj_0_4_oFDCAN14_4fc85aea_Tx  26u
#define PduRConf_PduRDestPdu_Debug_NFCD_Obj_5_9_oFDCAN14_b6ee4791_Tx  27u
#define PduRConf_PduRDestPdu_Debug_OCCalib_Data_oFDCAN14_a09c1bc6_Tx  28u
#define PduRConf_PduRDestPdu_Debug_SCCalib_Data_oFDCAN14_f9ffef76_Tx  29u
#define PduRConf_PduRDestPdu_Debug_TargetData_oFDCAN14_2a76e006_Tx    30u
#define PduRConf_PduRDestPdu_Diagnostics_Flags_oFDCAN14_35bb7a38_Tx   31u
#define PduRConf_PduRDestPdu_Distance_Point_Map_0_oFDCAN14_671cf790_Tx 32u
#define PduRConf_PduRDestPdu_Distance_Point_Map_1_oFDCAN14_0990ecd1_Tx 33u
#define PduRConf_PduRDestPdu_Distance_Point_Map_2_oFDCAN14_ba04c112_Tx 34u
#define PduRConf_PduRDestPdu_Distance_Point_Map_3_oFDCAN14_d488da53_Tx 35u
#define PduRConf_PduRDestPdu_Distance_Point_Map_4_oFDCAN14_065d9cd5_Tx 36u
#define PduRConf_PduRDestPdu_Distance_Point_Map_5_oFDCAN14_68d18794_Tx 37u
#define PduRConf_PduRDestPdu_Distance_Point_Map_6_oFDCAN14_db45aa57_Tx 38u
#define PduRConf_PduRDestPdu_Distance_Point_Map_7_oFDCAN14_b5c9b116_Tx 39u
#define PduRConf_PduRDestPdu_Distance_Point_Map_8_oFDCAN14_a59e211a_Tx 40u
#define PduRConf_PduRDestPdu_Distance_Point_Map_9_oFDCAN14_cb123a5b_Tx 41u
#define PduRConf_PduRDestPdu_Distance_Point_Map_10_oFDCAN14_1c0010fe_Tx 42u
#define PduRConf_PduRDestPdu_Distance_Point_Map_11_oFDCAN14_728c0bbf_Tx 43u
#define PduRConf_PduRDestPdu_FODDebug_oFDCAN14_f1ba2bbb_Tx            44u
#define PduRConf_PduRDestPdu_FPADebugInfo1_oFDCAN14_2f618197_Tx       45u
#define PduRConf_PduRDestPdu_Firing_Mode_oFDCAN14_9162ab4d_Tx         46u
#define PduRConf_PduRDestPdu_Firing_Sensors_oFDCAN14_913f5916_Tx      47u
#define PduRConf_PduRDestPdu_Firing_Sequence_oFDCAN14_ae988165_Tx     48u
#define PduRConf_PduRDestPdu_HMI_Curr_Displayed_Overlays_oFDCAN14_59fc11fc_Tx 49u
#define PduRConf_PduRDestPdu_HMI_Curr_Displayed_ProxiConfig_oFDCAN14_d9ff3bfe_Tx 50u
#define PduRConf_PduRDestPdu_HMI_Curr_Requested_Overlays_oFDCAN14_854dec1c_Tx 51u
#define PduRConf_PduRDestPdu_HMI_Curr_Requested_ProxiConfig_oFDCAN14_6d69f768_Tx 52u
#define PduRConf_PduRDestPdu_LMD_LaneLinesDebug_1_oFDCAN14_7d65846f_Tx 53u
#define PduRConf_PduRDestPdu_LMD_LaneLinesDebug_2_oFDCAN14_cef1a9ac_Tx 54u
#define PduRConf_PduRDestPdu_LMD_SegmentDebug_1_2_oFDCAN14_99b37b05_Tx 55u
#define PduRConf_PduRDestPdu_LMD_SegmentDebug_1_oFDCAN14_98429779_Tx  56u
#define PduRConf_PduRDestPdu_LMD_SegmentDebug_2_1_oFDCAN14_8f2f3daa_Tx 57u
#define PduRConf_PduRDestPdu_LMD_SegmentDebug_2_2_oFDCAN14_3cbb1069_Tx 58u
#define PduRConf_PduRDestPdu_Log_PackedDiagFlagData1_v_oFDCAN14_a37af45a_Tx 59u
#define PduRConf_PduRDestPdu_Log_PackedDiagFlagData2_v_oFDCAN14_06729f36_Tx 60u
#define PduRConf_PduRDestPdu_Log_PackedNoiseMeasData_oFDCAN14_967b3578_Tx 61u
#define PduRConf_PduRDestPdu_Log_SnrMeasData_01_oFDCAN14_481955b6_Tx  62u
#define PduRConf_PduRDestPdu_Log_SnrMeasData_02_oFDCAN14_fb8d7875_Tx  63u
#define PduRConf_PduRDestPdu_Log_SnrMeasData_03_oFDCAN14_95016334_Tx  64u
#define PduRConf_PduRDestPdu_Log_SnrMeasData_04_oFDCAN14_47d425b2_Tx  65u
#define PduRConf_PduRDestPdu_Log_SnrMeasData_05_oFDCAN14_29583ef3_Tx  66u
#define PduRConf_PduRDestPdu_Log_SnrMeasData_06_oFDCAN14_9acc1330_Tx  67u
#define PduRConf_PduRDestPdu_Log_SnrMeasData_07_oFDCAN14_f4400871_Tx  68u
#define PduRConf_PduRDestPdu_Log_SnrTemperature_oFDCAN14_f8c16d66_Tx  69u
#define PduRConf_PduRDestPdu_ME_DebugMsgSigned_oFDCAN14_e9329857_Tx   70u
#define PduRConf_PduRDestPdu_ME_DebugMsgUnsigned_oFDCAN14_6e07688e_Tx 71u
#define PduRConf_PduRDestPdu_ME_Debug_SensorTestData_1_oFDCAN14_74b41d5f_Tx 72u
#define PduRConf_PduRDestPdu_ME_Debug_SensorTestData_2_oFDCAN14_c720309c_Tx 73u
#define PduRConf_PduRDestPdu_ME_Debug_SensorTestData_3_oFDCAN14_a9ac2bdd_Tx 74u
#define PduRConf_PduRDestPdu_ME_MCUOsDebugData1_oFDCAN14_137bf977_Tx  75u
#define PduRConf_PduRDestPdu_ME_MCUOsDebugData2_oFDCAN14_a0efd4b4_Tx  76u
#define PduRConf_PduRDestPdu_ME_SnsDat_Front_Direct_2_oFDCAN14_0f179e9e_Tx 77u
#define PduRConf_PduRDestPdu_ME_SnsDat_Front_Direct_oFDCAN14_b2df9b13_Tx 78u
#define PduRConf_PduRDestPdu_ME_SnsDat_Front_Indirect_1_oFDCAN14_66924762_Tx 79u
#define PduRConf_PduRDestPdu_ME_SnsDat_Front_Indirect_2_oFDCAN14_d5066aa1_Tx 80u
#define PduRConf_PduRDestPdu_ME_SnsDat_Rear_Direct_2_oFDCAN14_b1a7fdfd_Tx 81u
#define PduRConf_PduRDestPdu_ME_SnsDat_Rear_Direct_oFDCAN14_caebeaa6_Tx 82u
#define PduRConf_PduRDestPdu_ME_SnsDat_Rear_Indirect_1_oFDCAN14_fcf9f154_Tx 83u
#define PduRConf_PduRDestPdu_ME_SnsDat_Rear_Indirect_2_oFDCAN14_4f6ddc97_Tx 84u
#define PduRConf_PduRDestPdu_ME_SystemDebugData_1_oFDCAN14_d1a1dda3_Tx 85u
#define PduRConf_PduRDestPdu_ME_SystemStatus_oFDCAN14_3ca06526_Tx     86u
#define PduRConf_PduRDestPdu_MOT_Obj_0_1_oFDCAN14_38441535_Tx         87u
#define PduRConf_PduRDestPdu_MOT_Obj_2_3_oFDCAN14_235391ff_Tx         88u
#define PduRConf_PduRDestPdu_MOT_Obj_4_5_oFDCAN14_0e6b1ca1_Tx         89u
#define PduRConf_PduRDestPdu_MOT_Obj_6_7_oFDCAN14_157c986b_Tx         90u
#define PduRConf_PduRDestPdu_MOT_Obj_8_9_oFDCAN14_541a061d_Tx         91u
#define PduRConf_PduRDestPdu_Minimum_Sensor_Distance_1_oFDCAN14_4c29e9ec_Tx 92u
#define PduRConf_PduRDestPdu_Minimum_Sensor_Distance_2_oFDCAN14_ffbdc42f_Tx 93u
#define PduRConf_PduRDestPdu_Minimum_Sensor_Distance_3_oFDCAN14_9131df6e_Tx 94u
#define PduRConf_PduRDestPdu_PDC_INFO_FD_PAM_oFDCAN2_461f923e_Tx      95u
#define PduRConf_PduRDestPdu_PLDDebugInfo1_oFDCAN14_d750a426_Tx       96u
#define PduRConf_PduRDestPdu_PLDDebugInfo2_oFDCAN14_64c489e5_Tx       97u
#define PduRConf_PduRDestPdu_PntDebugData_0_oFDCAN14_9851f785_Tx      98u
#define PduRConf_PduRDestPdu_PntDebugData_1_oFDCAN14_f6ddecc4_Tx      99u
#define PduRConf_PduRDestPdu_PntDebugData_2_oFDCAN14_4549c107_Tx      100u
#define PduRConf_PduRDestPdu_PntDebugData_3_oFDCAN14_2bc5da46_Tx      101u
#define PduRConf_PduRDestPdu_THADebugInfo1_oFDCAN14_83163028_Tx       102u
#define PduRConf_PduRDestPdu_THADebugInfo2_oFDCAN14_30821deb_Tx       103u
#define PduRConf_PduRDestPdu_TRSCM_FD_1_oFDCAN2_4cf656c2_Tx           104u
#define PduRConf_PduRDestPdu_TRSCM_FD_1_oFDCAN14_4ddc266d_Tx          105u
#define PduRConf_PduRDestPdu_TRSC_Debug_Message1_oFDCAN14_9ee0dc91_Tx 106u
#define PduRConf_PduRDestPdu_TRSC_Debug_Message2_oFDCAN14_2d74f152_Tx 107u
#define PduRConf_PduRDestPdu_TRSC_Debug_Message3_oFDCAN14_43f8ea13_Tx 108u
#define PduRConf_PduRDestPdu_TRSC_Detection_DebugMessage_oFDCAN14_7bfeb44b_Tx 109u
#define PduRConf_PduRDestPdu_TRSC_FID_DebugMessage_oFDCAN14_25624ab4_Tx 110u
#define PduRConf_PduRDestPdu_USSDebugInfo1_oFDCAN14_3a0946df_Tx       111u
#define PduRConf_PduRDestPdu_USSDebugInfo2_oFDCAN14_899d6b1c_Tx       112u
#define PduRConf_PduRDestPdu_USS_SectorInfoFB_oFDCAN14_41f44d67_Tx    113u
#define PduRConf_PduRDestPdu_UssCsmStateChangeReasons_oFDCAN14_21391911_Tx 114u
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxDest Handle IDs of handle space TpRxDest.
 * \brief Transport protocol Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DIAGNOSTIC_REQUEST_FD_FUNCTIONAL_oFDCAN2_20_73727a47_Rx_d1f51245_Rx 0u
#define PduRConf_PduRDestPdu_DIAGNOSTIC_REQUEST_FD_FUNCTIONAL_oFDCAN2_56e1939c_Rx_74e62a6c_Rx 1u
#define PduRConf_PduRDestPdu_DIAGNOSTIC_REQUEST_FD_PAM_oFDCAN2_20_f5723a9b_Rx_ff4aa4e5_Rx 2u
#define PduRConf_PduRDestPdu_DIAGNOSTIC_REQUEST_FD_PAM_oFDCAN2_aee787f0_Rx_e393916e_Rx 3u
#define PduRConf_PduRDestPdu_DIAGNOSTIC_REQUEST_FUNCTIONAL_oFDCAN2_fa8f9425_Rx_ec401e20_Rx 4u
#define PduRConf_PduRDestPdu_DIAGNOSTIC_REQUEST_PAM_oFDCAN2_d3c55b76_Rx_274afd95_Rx 5u
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxSrc Handle IDs of handle space TpRxSrc.
 * \brief Transport protocol Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_74e62a6c                       1u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_274afd95                       5u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d1f51245                       0u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e393916e                       3u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ec401e20                       4u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ff4aa4e5                       2u
/**\} */

/**
 * \defgroup PduRHandleIdsTpTxDest Handle IDs of handle space TpTxDest.
 * \brief Transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_DIAGNOSTIC_RESPONSE_FD_PAM_oFDCAN2_20_25761d2e_Tx 0u
#define PduRConf_PduRDestPdu_DIAGNOSTIC_RESPONSE_FD_PAM_oFDCAN2_411d850e_Tx 1u
#define PduRConf_PduRDestPdu_DIAGNOSTIC_RESPONSE_PAM_oFDCAN2_7c9fd6f9_Tx 2u
/**\} */


/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* PDUR_CFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Cfg.h
 *********************************************************************************************************************/

