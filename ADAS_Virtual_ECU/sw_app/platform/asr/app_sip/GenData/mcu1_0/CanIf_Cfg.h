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
 *            Module: CanIf
 *           Program: MSR FCA SLP5 (MSR_Fca_SLP5)
 *          Customer: Magna Electronics
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TDA4VE88
 *    License Scope : The usage is restricted to CBD2101089_D08
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Cfg.h
 *   Generation Time: 2025-07-09 17:10:17
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined(CANIF_CFG_H)
#define CANIF_CFG_H


/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/
#include "Can_30_Mcan.h"




/**********************************************************************************************************************
  \def  Version defines
**********************************************************************************************************************/

#define CANIF_CFG5_VERSION                                 0x0504u
#define CANIF_CFG5_RELEASE_VERSION                         0x00u
#define IF_ASRIFCAN_GENTOOL_CFG5_MAJOR_VERSION             0x05u
#define IF_ASRIFCAN_GENTOOL_CFG5_MINOR_VERSION             0x04u
#define IF_ASRIFCAN_GENTOOL_CFG5_PATCH_VERSION             0x00u

#define CANIF_CFG5_GENERATOR_COMPATIBILITY_VERSION         0x0212u

/**********************************************************************************************************************
  \def  Switches
**********************************************************************************************************************/

#define CANIF_TRANSMIT_BUFFER                              STD_ON /* Signals if Tx-buffer is enabled at all in CanIf. The value is determined from parameter "CanIfPublicTxBuffering". */
#define CANIF_TRANSMIT_BUFFER_PRIO_BY_CANID                STD_ON
#define CANIF_TRANSMIT_BUFFER_FIFO                         STD_OFF
#define CANIF_BITQUEUE                                     STD_OFF
#define CANIF_STATIC_FD_TXQUEUE                            STD_ON
#define CANIF_WAKEUP_SUPPORT                               STD_ON
#define CANIF_WAKEUP_VALIDATION                            STD_OFF
#define CANIF_WAKEUP_VALID_ALL_RX_MSGS                     STD_OFF
#define CANIF_WAKEUP_VALID_ONLY_NM_RX_MSGS                 STD_OFF
#define CANIF_CHECK_WAKEUP_CAN_RET_TYPE                    STD_OFF
#define CANIF_DEV_ERROR_DETECT                             STD_ON
#define CANIF_DEV_ERROR_REPORT                             STD_ON
#define CANIF_TRANSMIT_CANCELLATION                        STD_OFF
#define CANIF_CANCEL_SUPPORT_API                           STD_OFF
#define CANIF_VERSION_INFO_API                             STD_OFF
#define CANIF_DLC_CHECK                                    STD_ON
#define CANIF_SUPPORT_NMOSEK_INDICATION                    STD_OFF
#define CANIF_TRCV_HANDLING                                STD_ON
#define CANIF_TRCV_MAPPING                                 STD_OFF
#define CANIF_PN_TRCV_HANDLING                             STD_OFF
#define CANIF_EXTENDEDID_SUPPORT                           STD_ON
#define CANIF_SETDYNAMICTXID_API                           STD_OFF
#define CANIF_PN_WU_TX_PDU_FILTER                          STD_OFF
#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT            STD_OFF
#define CANIF_RX_INDICATION_TYPE_I_IS_USED                 STD_OFF
#define CANIF_RX_INDICATION_TYPE_IV_IS_USED                STD_OFF
#define CANIF_CHANGE_BAUDRATE_SUPPORT                      STD_OFF
#define CANIF_SET_BAUDRATE_API                             STD_OFF
#define CANIF_META_DATA_RX_SUPPORT                         STD_OFF
#define CANIF_META_DATA_TX_SUPPORT                         STD_OFF
#define CANIF_J1939_DYN_ADDR_SUPPORT                       CANIF_J1939_DYN_ADDR_DISABLED
#define CANIF_MULTIPLE_CANDRV_SUPPORT                      STD_OFF
#define CANIF_RX_SEARCH_CONSIDER_MSG_TYPE                  STD_ON
#define CANIF_ECUC_SAFE_BSW_CHECKS                         STD_OFF
#define CANIF_EXTENDED_RAM_CHECK_SUPPORT                   STD_OFF
#define CANIF_DATA_CHECKSUM_RX_SUPPORT                     STD_OFF
#define CANIF_DATA_CHECKSUM_TX_SUPPORT                     STD_OFF
#define CANIF_SET_PDU_RECEPTION_MODE_SUPPORT               STD_OFF
#define CANIF_BUS_MIRRORING_SUPPORT                        STD_OFF
#define CANIF_ENABLE_SECURITY_EVENT_REPORTING              STD_OFF
#define CANIF_SUPPORT_CANDRV_ASR440                        STD_OFF
#define CANIF_SUPPORT_MULTIPARTITION                       STD_OFF

#define CANIF_SUPPRESS_EXTENDED_VERSION_CHECK

#ifndef CANIF_USE_DUMMY_STATEMENT
#define CANIF_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_DUMMY_STATEMENT
#define CANIF_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_DUMMY_STATEMENT_CONST
#define CANIF_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_ON /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANIF_ATOMIC_VARIABLE_ACCESS
#define CANIF_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANIF_PROCESSOR_TDA4VE88
#define CANIF_PROCESSOR_TDA4VE88
#endif
#ifndef CANIF_COMP_LLVMTEXASINSTRUMENTS
#define CANIF_COMP_LLVMTEXASINSTRUMENTS
#endif
#ifndef CANIF_GEN_GENERATOR_MSR
#define CANIF_GEN_GENERATOR_MSR
#endif
#ifndef CANIF_CPUTYPE_BITORDER_LSB2MSB
#define CANIF_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#define CANIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_LINKTIME
#define CANIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANIF_CONFIGURATION_VARIANT
#define CANIF_CONFIGURATION_VARIANT CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANIF_POSTBUILD_VARIANT_SUPPORT
#define CANIF_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CANIF_CPU_TYPE_SET_IN_ECUC_MODULE                  CPU_TYPE_32

/**********************************************************************************************************************
  \def  Search algorithm
**********************************************************************************************************************/
#define CANIF_SEARCH_ALGORITHM                             CANIF_DOUBLE_HASH


/**********************************************************************************************************************
  \def  Configuration variant
**********************************************************************************************************************/
#define CANIF_CONFIG_VARIANT                               CANIF_CFGVAR_PRECOMPILETIME


/**********************************************************************************************************************
  Type definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
  \def  Tx-buffer - queue size type
**********************************************************************************************************************/
typedef uint8 CanIf_TxBufferSizeType;


/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
#include "CanIf_Types.h"

/**********************************************************************************************************************
  \def  Memory mapping keywords
**********************************************************************************************************************/
#define CANIF_XCFG                                         CANIF_CONST
#define CANIF_VAR_XCFG_NOINIT                              CANIF_VAR_NOINIT


/**********************************************************************************************************************
  \def  Invalid PDU handle
**********************************************************************************************************************/
#define CanIf_TxPduHnd_INVALID                             0xFFFFu
#define CanIf_RxPduHnd_INVALID                             0xFFFFu


/**********************************************************************************************************************
  \def  Tx-buffer - handling types
**********************************************************************************************************************/
#define CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID                                                             1u
#define CANIF_TXBUFFER_HANDLINGTYPE_FIFO                                                                    2u
#define CANIF_TXBUFFER_HANDLINGTYPE_NONE                                                                    3u



/**********************************************************************************************************************
  \def  CAN controller - symbolic handles
**********************************************************************************************************************/

#define CanIfConf_CanIfCtrlCfg_CT_FDCAN2_c5d3d1a7                                                   0u
#define CanIfConf_CanIfCtrlCfg_CT_FDCAN14_90ecad61                                                  1u


/**********************************************************************************************************************
  \def  CAN transceiver - symbolic handles
**********************************************************************************************************************/

#define CanIfConf_CanIfTrcvCfg_CanIfTrcvCfg                                                         0u



/**********************************************************************************************************************
  \def  Indirection macros for CAN driver with VendorApiInfix
**********************************************************************************************************************/
#define Can_SetControllerMode                                                                       Can_30_Mcan_SetControllerMode
#define Can_Write                                                                                   Can_30_Mcan_Write
#define Can_CheckWakeup                                                                             Can_30_Mcan_CheckWakeup



/**********************************************************************************************************************
  \def  Transceiver handling APIs
**********************************************************************************************************************/
 
#define CanTrcv_SetOpMode                                  CanTrcv_30_Tja1043_SetOpMode
#define CanTrcv_GetOpMode                                  CanTrcv_30_Tja1043_GetOpMode
#define CanTrcv_GetBusWuReason                             CanTrcv_30_Tja1043_GetBusWuReason
#define CanTrcv_SetWakeupMode                              CanTrcv_30_Tja1043_SetWakeupMode
#define CanTrcv_CheckWakeup                                CanTrcv_30_Tja1043_CheckWakeup


/**********************************************************************************************************************
  \def  Tx PDU handles
**********************************************************************************************************************/

#define CanIfTxPduHnd_XCP_Tx_oFDCAN2_dec73f67_Tx                                                    0u
#define CanIfTxPduHnd_NM_PAM_oFDCAN2_28cff7c5_Tx                                                    1u
#define CanIfTxPduHnd_PDC_INFO_FD_PAM_oFDCAN2_f59fee66_Tx                                           2u
#define CanIfTxPduHnd_CFG_DATA_CODE_RSP_PAM_oFDCAN2_9eaffcee_Tx                                     3u
#define CanIfTxPduHnd_DIAGNOSTIC_ROE_FD_PAM_oFDCAN2_5f1d7fc3_Tx                                     4u
#define CanIfTxPduHnd_DIAGNOSTIC_ROE_PAM_oFDCAN2_d9a769b3_Tx                                        5u
#define CanIfTxPduHnd_DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_3daa27dc_Tx                             6u
#define CanIfTxPduHnd_DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_20_a02181d6_Tx                          7u
#define CanIfTxPduHnd_DIAGNOSTIC_RESPONSE_PAM_Tp_oFDCAN2_dc079c65_Tx                                8u
#define CanIfTxPduHnd_TRSCM_FD_1_oFDCAN2_a03575fe_Tx                                                9u
#define CanIfTxPduHnd_CVPAM_FD_Info_oFDCAN2_63faf907_Tx                                             10u
#define CanIfTxPduHnd_ADAS_FD_LANES_2_oFDCAN2_b32c517d_Tx                                           11u
#define CanIfTxPduHnd_ADAS_FD_LANES_1_oFDCAN2_60bc77b3_Tx                                           12u
#define CanIfTxPduHnd_CVPAM_FD_Control_oFDCAN2_4eff2f96_Tx                                          13u
#define CanIfTxPduHnd_UssCsmStateChangeReasons_oFDCAN14_9fbeef37_Tx                                 14u
#define CanIfTxPduHnd_USS_SectorInfoFB_oFDCAN14_14389c16_Tx                                         15u
#define CanIfTxPduHnd_PntDebugData_3_oFDCAN14_603295cf_Tx                                           16u
#define CanIfTxPduHnd_PntDebugData_2_oFDCAN14_9304bca8_Tx                                           17u
#define CanIfTxPduHnd_PntDebugData_1_oFDCAN14_5d2fc140_Tx                                           18u
#define CanIfTxPduHnd_PntDebugData_0_oFDCAN14_ae19e827_Tx                                           19u
#define CanIfTxPduHnd_Minimum_Sensor_Distance_3_oFDCAN14_29aa616f_Tx                                20u
#define CanIfTxPduHnd_Minimum_Sensor_Distance_2_oFDCAN14_23601cc6_Tx                                21u
#define CanIfTxPduHnd_Minimum_Sensor_Distance_1_oFDCAN14_3c3e9a3d_Tx                                22u
#define CanIfTxPduHnd_Log_PackedDiagFlagData2_v_oFDCAN14_b3328600_Tx                                23u
#define CanIfTxPduHnd_Log_PackedNoiseMeasData_oFDCAN14_32d10e8e_Tx                                  24u
#define CanIfTxPduHnd_Log_PackedDiagFlagData1_v_oFDCAN14_40a1873d_Tx                                25u
#define CanIfTxPduHnd_Log_SnrMeasData_03_oFDCAN14_11beb26e_Tx                                       26u
#define CanIfTxPduHnd_ME_SystemStatus_oFDCAN14_3392fde0_Tx                                          27u
#define CanIfTxPduHnd_ME_DebugMsgUnsigned_oFDCAN14_e8b674cc_Tx                                      28u
#define CanIfTxPduHnd_ME_DebugMsgSigned_oFDCAN14_16ce7da0_Tx                                        29u
#define CanIfTxPduHnd_Log_SnrTemperature_oFDCAN14_4577f469_Tx                                       30u
#define CanIfTxPduHnd_Log_SnrMeasData_07_oFDCAN14_1045d0af_Tx                                       31u
#define CanIfTxPduHnd_Log_SnrMeasData_06_oFDCAN14_66e7498f_Tx                                       32u
#define CanIfTxPduHnd_Log_SnrMeasData_05_oFDCAN14_fd00e2ef_Tx                                       33u
#define CanIfTxPduHnd_Log_SnrMeasData_04_oFDCAN14_8ba27bcf_Tx                                       34u
#define CanIfTxPduHnd_DebugModelOutput_Feature_KPI_Tx_oFDCAN14_fae6f83c_Tx                          35u
#define CanIfTxPduHnd_Log_SnrMeasData_02_oFDCAN14_671c2b4e_Tx                                       36u
#define CanIfTxPduHnd_Log_SnrMeasData_01_oFDCAN14_fcfb802e_Tx                                       37u
#define CanIfTxPduHnd_Diagnostics_Flags_oFDCAN14_82d05e9d_Tx                                        38u
#define CanIfTxPduHnd_Blockage_Flags_oFDCAN14_cd9c3e01_Tx                                           39u
#define CanIfTxPduHnd_ME_MCUOsDebugData2_oFDCAN14_977545dd_Tx                                       40u
#define CanIfTxPduHnd_ME_MCUOsDebugData1_oFDCAN14_0c92eebd_Tx                                       41u
#define CanIfTxPduHnd_ME_SystemDebugData_1_oFDCAN14_6a0508c3_Tx                                     42u
#define CanIfTxPduHnd_ME_SnsDat_Rear_Direct_oFDCAN14_6726d174_Tx                                    43u
#define CanIfTxPduHnd_ME_SnsDat_Front_Direct_oFDCAN14_92d50a6c_Tx                                   44u
#define CanIfTxPduHnd_ME_SnsDat_Rear_Direct_2_oFDCAN14_762da0cc_Tx                                  45u
#define CanIfTxPduHnd_ME_SnsDat_Front_Direct_2_oFDCAN14_d7e5c444_Tx                                 46u
#define CanIfTxPduHnd_ME_SnsDat_Rear_Indirect_1_oFDCAN14_75ed542b_Tx                                47u
#define CanIfTxPduHnd_ME_SnsDat_Front_Indirect_1_oFDCAN14_a0b9888a_Tx                               48u
#define CanIfTxPduHnd_ME_SnsDat_Rear_Indirect_2_oFDCAN14_6ab3d2d0_Tx                                49u
#define CanIfTxPduHnd_ME_SnsDat_Front_Indirect_2_oFDCAN14_38edffe1_Tx                               50u
#define CanIfTxPduHnd_ME_Debug_SensorTestData_3_oFDCAN14_ffe1e91c_Tx                                51u
#define CanIfTxPduHnd_ME_Debug_SensorTestData_2_oFDCAN14_f52b94b5_Tx                                52u
#define CanIfTxPduHnd_ME_Debug_SensorTestData_1_oFDCAN14_ea75124e_Tx                                53u
#define CanIfTxPduHnd_FPADebugInfo1_oFDCAN14_ba73bd7c_Tx                                            54u
#define CanIfTxPduHnd_USSDebugInfo2_oFDCAN14_a2853d8e_Tx                                            55u
#define CanIfTxPduHnd_USSDebugInfo1_oFDCAN14_71151b40_Tx                                            56u
#define CanIfTxPduHnd_PLDDebugInfo2_oFDCAN14_12211571_Tx                                            57u
#define CanIfTxPduHnd_PLDDebugInfo1_oFDCAN14_c1b133bf_Tx                                            58u
#define CanIfTxPduHnd_LMD_SegmentDebug_2_2_oFDCAN14_be3e1ae4_Tx                                     59u
#define CanIfTxPduHnd_LMD_SegmentDebug_2_1_oFDCAN14_01887f27_Tx                                     60u
#define CanIfTxPduHnd_LMD_SegmentDebug_1_2_oFDCAN14_6331b408_Tx                                     61u
#define CanIfTxPduHnd_LMD_SegmentDebug_1_oFDCAN14_3a13c4d8_Tx                                       62u
#define CanIfTxPduHnd_LMD_LaneLinesDebug_2_oFDCAN14_965d36d3_Tx                                     63u
#define CanIfTxPduHnd_Debug_ModuleState_oFDCAN14_96e19c7d_Tx                                        64u
#define CanIfTxPduHnd_Debug_CalibSts_oFDCAN14_58546a56_Tx                                           65u
#define CanIfTxPduHnd_Debug_ErrCodeAlgo_oFDCAN14_78756c50_Tx                                        66u
#define CanIfTxPduHnd_Firing_Sequence_oFDCAN14_afdc26b0_Tx                                          67u
#define CanIfTxPduHnd_Firing_Sensors_oFDCAN14_474d0a36_Tx                                           68u
#define CanIfTxPduHnd_Firing_Mode_oFDCAN14_60360c0e_Tx                                              69u
#define CanIfTxPduHnd_Distance_Point_Map_11_oFDCAN14_2ace4b8f_Tx                                    70u
#define CanIfTxPduHnd_Distance_Point_Map_10_oFDCAN14_4563a97d_Tx                                    71u
#define CanIfTxPduHnd_Distance_Point_Map_9_oFDCAN14_ed3689c6_Tx                                     72u
#define CanIfTxPduHnd_Distance_Point_Map_8_oFDCAN14_87a4aa87_Tx                                     73u
#define CanIfTxPduHnd_Distance_Point_Map_7_oFDCAN14_ab58528b_Tx                                     74u
#define CanIfTxPduHnd_Distance_Point_Map_6_oFDCAN14_c1ca71ca_Tx                                     75u
#define CanIfTxPduHnd_Distance_Point_Map_5_oFDCAN14_7e7c1409_Tx                                     76u
#define CanIfTxPduHnd_Distance_Point_Map_4_oFDCAN14_14ee3748_Tx                                     77u
#define CanIfTxPduHnd_Distance_Point_Map_3_oFDCAN14_da61d9ce_Tx                                     78u
#define CanIfTxPduHnd_Distance_Point_Map_2_oFDCAN14_b0f3fa8f_Tx                                     79u
#define CanIfTxPduHnd_Distance_Point_Map_1_oFDCAN14_0f459f4c_Tx                                     80u
#define CanIfTxPduHnd_Distance_Point_Map_0_oFDCAN14_65d7bc0d_Tx                                     81u
#define CanIfTxPduHnd_DebugModelOutput_oFDCAN14_6b4c9d3e_Tx                                         82u
#define CanIfTxPduHnd_FODDebug_oFDCAN14_0f411cd7_Tx                                                 83u
#define CanIfTxPduHnd_THADebugInfo2_oFDCAN14_062cf8ad_Tx                                            84u
#define CanIfTxPduHnd_THADebugInfo1_oFDCAN14_d5bcde63_Tx                                            85u
#define CanIfTxPduHnd_LMD_LaneLinesDebug_1_oFDCAN14_29eb5310_Tx                                     86u
#define CanIfTxPduHnd_MOT_Obj_8_9_oFDCAN14_bd8ad539_Tx                                              87u
#define CanIfTxPduHnd_MOT_Obj_6_7_oFDCAN14_35343c77_Tx                                              88u
#define CanIfTxPduHnd_MOT_Obj_4_5_oFDCAN14_cf8dc798_Tx                                              89u
#define CanIfTxPduHnd_MOT_Obj_2_3_oFDCAN14_1b36cde8_Tx                                              90u
#define CanIfTxPduHnd_MOT_Obj_0_1_oFDCAN14_e18f3607_Tx                                              91u
#define CanIfTxPduHnd_Debug_FPA_HMI_InfoToVC_oFDCAN14_0eea4eb6_Tx                                   92u
#define CanIfTxPduHnd_Debug_NFCD_Obj_5_9_oFDCAN14_b99541d7_Tx                                       93u
#define CanIfTxPduHnd_Debug_NFCD_Obj_0_4_oFDCAN14_a030e1d4_Tx                                       94u
#define CanIfTxPduHnd_Debug_AP_Variables_oFDCAN14_07efddff_Tx                                       95u
#define CanIfTxPduHnd_TRSC_FID_DebugMessage_oFDCAN14_04f18303_Tx                                    96u
#define CanIfTxPduHnd_TRSC_Detection_DebugMessage_oFDCAN14_e6f5f3c5_Tx                              97u
#define CanIfTxPduHnd_TRSC_Debug_Message3_oFDCAN14_35eb5fb3_Tx                                      98u
#define CanIfTxPduHnd_TRSC_Debug_Message2_oFDCAN14_60efdc35_Tx                                      99u
#define CanIfTxPduHnd_Debug_EOLCalib_Data_2_oFDCAN14_1ed59804_Tx                                    100u
#define CanIfTxPduHnd_Debug_CurrentCalib_Data_2_oFDCAN14_192cb625_Tx                                101u
#define CanIfTxPduHnd_Debug_FeatureCollection_oFDCAN14_4fc45f26_Tx                                  102u
#define CanIfTxPduHnd_Debug_TargetData_oFDCAN14_78b5aec6_Tx                                         103u
#define CanIfTxPduHnd_Debug_OCCalib_Data_oFDCAN14_99914301_Tx                                       104u
#define CanIfTxPduHnd_Debug_SCCalib_Data_oFDCAN14_415523bc_Tx                                       105u
#define CanIfTxPduHnd_Debug_EOLCalib_Data_1_oFDCAN14_ae23bf12_Tx                                    106u
#define CanIfTxPduHnd_TRSC_Debug_Message1_oFDCAN14_9fe258bf_Tx                                      107u
#define CanIfTxPduHnd_Debug_HMI_Internal_Data_oFDCAN14_49de4f3c_Tx                                  108u
#define CanIfTxPduHnd_Debug_HMI_Input_Data_oFDCAN14_3b9e1113_Tx                                     109u
#define CanIfTxPduHnd_Debug_HMI_Trailer_Views_Data_oFDCAN14_a612f060_Tx                             110u
#define CanIfTxPduHnd_HMI_Curr_Displayed_ProxiConfig_oFDCAN14_4ee7a674_Tx                           111u
#define CanIfTxPduHnd_HMI_Curr_Requested_ProxiConfig_oFDCAN14_69d6981b_Tx                           112u
#define CanIfTxPduHnd_HMI_Curr_Displayed_Overlays_oFDCAN14_228998f0_Tx                              113u
#define CanIfTxPduHnd_HMI_Curr_Requested_Overlays_oFDCAN14_5ad84df2_Tx                              114u
#define CanIfTxPduHnd_NM_PAM_oFDCAN14_636c02e4_Tx                                                   115u
#define CanIfTxPduHnd_TRSCM_FD_1_oFDCAN14_24b0a50e_Tx                                               116u
#define CanIfTxPduHnd_CVPAM_FD_Info_oFDCAN14_98d10c56_Tx                                            117u
#define CanIfTxPduHnd_ADAS_FD_LANES_2_oFDCAN14_1fc7bdbe_Tx                                          118u
#define CanIfTxPduHnd_ADAS_FD_LANES_1_oFDCAN14_03fcfef0_Tx                                          119u
#define CanIfTxPduHnd_CVPAM_FD_Control_oFDCAN14_f55d7751_Tx                                         120u


/**********************************************************************************************************************
  \def  Rx PDU handles (Rx indication function specific ones)
**********************************************************************************************************************/

/* These definitions can change at Post-build configuration time. Use them wisely. */
/* Assigned to: NULL_PTR*/
#define CanIfRxPduHnd_SetUSSParkingMode_oFDCAN14_120f62ca_Rx                                        0u
/* Assigned to: CanNm_RxIndication*/
#define CanIfRxPduHnd_CVADAS_95874157_Rx                                                            0u
#define CanIfRxPduHnd_CVADAS_efa31eaf_Rx                                                            1u
/* Assigned to: CanTp_RxIndication*/
#define CanIfRxPduHnd_DIAGNOSTIC_REQUEST_FD_FUNCTIONAL_Tp_oFDCAN2_75504700_Rx                       0u
#define CanIfRxPduHnd_DIAGNOSTIC_REQUEST_FD_FUNCTIONAL_Tp_oFDCAN2_20_89fbaae9_Rx                    1u
#define CanIfRxPduHnd_DIAGNOSTIC_REQUEST_FUNCTIONAL_Tp_oFDCAN2_32bd5e48_Rx                          2u
#define CanIfRxPduHnd_DIAGNOSTIC_REQUEST_FD_PAM_Tp_oFDCAN2_a33697dc_Rx                              3u
#define CanIfRxPduHnd_DIAGNOSTIC_REQUEST_FD_PAM_Tp_oFDCAN2_20_b2dd874c_Rx                           4u
#define CanIfRxPduHnd_DIAGNOSTIC_REQUEST_PAM_Tp_oFDCAN2_85a60f0e_Rx                                 5u
/* Assigned to: PduR_CanIfRxIndication*/
#define CanIfRxPduHnd_PDC_INFO_FD_TRLR_REV_oFDCAN2_76ae5916_Rx                                      0u
#define CanIfRxPduHnd_PDC_INFO_FD_BSM2_oFDCAN2_555bedb6_Rx                                          1u
#define CanIfRxPduHnd_PDC_INFO_FD_CADM2_oFDCAN2_9d0a5374_Rx                                         2u
#define CanIfRxPduHnd_PDC_INFO_FD_SGW_oFDCAN2_8b0ead97_Rx                                           3u
#define CanIfRxPduHnd_PDC_INFO_FD_ADCM_oFDCAN2_43f16f06_Rx                                          4u
#define CanIfRxPduHnd_PDC_INFO_FD_ORC_oFDCAN2_c0f4295b_Rx                                           5u
#define CanIfRxPduHnd_PDC_INFO_FD_EPS_oFDCAN2_0100550f_Rx                                           6u
#define CanIfRxPduHnd_PDC_INFO_FD_BCM_oFDCAN2_51e02ec5_Rx                                           7u
#define CanIfRxPduHnd_CFG_DATA_CODE_REQUEST_oFDCAN2_a6af4d1a_Rx                                     8u
#define CanIfRxPduHnd_IPC_FD_1_oFDCAN2_255aca61_Rx                                                  9u
#define CanIfRxPduHnd_BCM_FD_7_oFDCAN2_1c05063e_Rx                                                  10u
#define CanIfRxPduHnd_TRSKM_FD_1_oFDCAN2_6974e197_Rx                                                11u
#define CanIfRxPduHnd_BCM_FD_29_oFDCAN2_a9ee0c40_Rx                                                 12u
#define CanIfRxPduHnd_TELEMATIC_FD_14_oFDCAN2_95ebb865_Rx                                           13u
#define CanIfRxPduHnd_TRANSM_FD_4_oFDCAN2_2b2bdf8f_Rx                                               14u
#define CanIfRxPduHnd_ENGINE_FD_7_oFDCAN2_75464136_Rx                                               15u
#define CanIfRxPduHnd_ASCM_FD_2_oFDCAN2_e0d28be9_Rx                                                 16u
#define CanIfRxPduHnd_IPC_VEHICLE_SETUP_oFDCAN2_ad6c5915_Rx                                         17u
#define CanIfRxPduHnd_BCM_FD_27_oFDCAN2_5243ac07_Rx                                                 18u
#define CanIfRxPduHnd_BCM_FD_12_oFDCAN2_f75168bb_Rx                                                 19u
#define CanIfRxPduHnd_TELEMATIC_FD_5_oFDCAN2_d3090214_Rx                                            20u
#define CanIfRxPduHnd_ASCM_FD_1_oFDCAN2_b0efc15e_Rx                                                 21u
#define CanIfRxPduHnd_BRAKE_FD_5_oFDCAN2_9836b6c3_Rx                                                22u
#define CanIfRxPduHnd_BCM_FD_10_oFDCAN2_9778e461_Rx                                                 23u
#define CanIfRxPduHnd_DRIVETRAIN_FD_3_oFDCAN2_d0fa3352_Rx                                           24u
#define CanIfRxPduHnd_BCM_FD_9_oFDCAN2_82510968_Rx                                                  25u
#define CanIfRxPduHnd_EPS_FD_2_oFDCAN2_002075f8_Rx                                                  26u
#define CanIfRxPduHnd_VIN_oFDCAN2_de66582f_Rx                                                       27u
#define CanIfRxPduHnd_BCM_FD_3_oFDCAN2_f21ddb5c_Rx                                                  28u
#define CanIfRxPduHnd_ORC_FD_1_oFDCAN2_9afbe59f_Rx                                                  29u
#define CanIfRxPduHnd_BRAKE_FD_4_oFDCAN2_c519be37_Rx                                                30u
#define CanIfRxPduHnd_TELEMATIC_FD_11_oFDCAN2_3a2ad576_Rx                                           31u
#define CanIfRxPduHnd_GLOB_NAV_FD_C2_oFDCAN2_7d3f2e2d_Rx                                            32u
#define CanIfRxPduHnd_TRANSM_FD_2_oFDCAN2_bdde8790_Rx                                               33u
#define CanIfRxPduHnd_ENGINE_FD_5_oFDCAN2_071576c3_Rx                                               34u
#define CanIfRxPduHnd_BRAKE_FD_1_oFDCAN2_37fb9352_Rx                                                35u
#define CanIfRxPduHnd_AGSM_FD_2_oFDCAN2_b4392bd1_Rx                                                 36u
#define CanIfRxPduHnd_ADAS_FD_INFO_C2_oFDCAN2_b80f734c_Rx                                           37u
#define CanIfRxPduHnd_TRANSM_FD_1_oFDCAN2_1b1ca8bf_Rx                                               38u
#define CanIfRxPduHnd_EPS_FD_1_oFDCAN2_a112af31_Rx                                                  39u
#define CanIfRxPduHnd_ENGINE_FD_2_oFDCAN2_45713606_Rx                                               40u
#define CanIfRxPduHnd_BRAKE_FD_3_oFDCAN2_8da582ba_Rx                                                41u
#define CanIfRxPduHnd_BRAKE_FD_2_oFDCAN2_d08a8a4e_Rx                                                42u
#define CanIfRxPduHnd_BRAKE2_FD_1_oFDCAN2_a11783f2_Rx                                               43u
#define CanIfRxPduHnd_BCM_FD_2_oFDCAN2_24236f24_Rx                                                  44u
#define CanIfRxPduHnd_PntDebugData_Rx_oFDCAN14_6aed7921_Rx                                          45u
#define CanIfRxPduHnd_ENGINE_FD_7_oFDCAN14_6291a34e_Rx                                              46u
#define CanIfRxPduHnd_BRAKE_FD_5_oFDCAN14_2f8081eb_Rx                                               47u
#define CanIfRxPduHnd_EPS_FD_2_oFDCAN14_e882ffe3_Rx                                                 48u
#define CanIfRxPduHnd_BRAKE_FD_4_oFDCAN14_274e2aee_Rx                                               49u
#define CanIfRxPduHnd_ENGINE_FD_5_oFDCAN14_5e6dd4a8_Rx                                              50u
#define CanIfRxPduHnd_BRAKE_FD_7_oFDCAN14_3e1dd7e1_Rx                                               51u
#define CanIfRxPduHnd_BRAKE_FD_1_oFDCAN14_0cba2dff_Rx                                               52u
#define CanIfRxPduHnd_ADAS_FD_INFO_oFDCAN14_23de1d3b_Rx                                             53u
#define CanIfRxPduHnd_EPS_FD_1_oFDCAN14_0ff3e6ff_Rx                                                 54u
#define CanIfRxPduHnd_ENGINE_FD_2_oFDCAN14_05177771_Rx                                              55u
#define CanIfRxPduHnd_BRAKE_FD_3_oFDCAN14_1d277bf5_Rx                                               56u
#define CanIfRxPduHnd_BRAKE_FD_2_oFDCAN14_15e9d0f0_Rx                                               57u
#define CanIfRxPduHnd_BRAKE2_FD_1_oFDCAN14_d8d4c6d0_Rx                                              58u
#define CanIfRxPduHnd_PT_TORQUE_FD_1_oFDCAN14_a0affdba_Rx                                           59u
#define CanIfRxPduHnd_BRAKE_FD_6_oFDCAN14_36d37ce4_Rx                                               60u
/* Assigned to: Xcp_CanIfRxIndication*/
#define CanIfRxPduHnd_XCP_Rx_oFDCAN2_957ff1e4_Rx                                                    0u



/**********************************************************************************************************************
  \def  AUTOSAR Tx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfTxPduCfg_XCP_Tx_oFDCAN2_dec73f67_Tx                                          0u
#define CanIfConf_CanIfTxPduCfg_NM_PAM_oFDCAN2_28cff7c5_Tx                                          1u
#define CanIfConf_CanIfTxPduCfg_PDC_INFO_FD_PAM_oFDCAN2_f59fee66_Tx                                 2u
#define CanIfConf_CanIfTxPduCfg_CFG_DATA_CODE_RSP_PAM_oFDCAN2_9eaffcee_Tx                           3u
#define CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_ROE_FD_PAM_oFDCAN2_5f1d7fc3_Tx                           4u
#define CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_ROE_PAM_oFDCAN2_d9a769b3_Tx                              5u
#define CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_3daa27dc_Tx                   6u
#define CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_20_a02181d6_Tx                7u
#define CanIfConf_CanIfTxPduCfg_DIAGNOSTIC_RESPONSE_PAM_Tp_oFDCAN2_dc079c65_Tx                      8u
#define CanIfConf_CanIfTxPduCfg_TRSCM_FD_1_oFDCAN2_a03575fe_Tx                                      9u
#define CanIfConf_CanIfTxPduCfg_CVPAM_FD_Info_oFDCAN2_63faf907_Tx                                   10u
#define CanIfConf_CanIfTxPduCfg_ADAS_FD_LANES_2_oFDCAN2_b32c517d_Tx                                 11u
#define CanIfConf_CanIfTxPduCfg_ADAS_FD_LANES_1_oFDCAN2_60bc77b3_Tx                                 12u
#define CanIfConf_CanIfTxPduCfg_CVPAM_FD_Control_oFDCAN2_4eff2f96_Tx                                13u
#define CanIfConf_CanIfTxPduCfg_UssCsmStateChangeReasons_oFDCAN14_9fbeef37_Tx                       14u
#define CanIfConf_CanIfTxPduCfg_USS_SectorInfoFB_oFDCAN14_14389c16_Tx                               15u
#define CanIfConf_CanIfTxPduCfg_PntDebugData_3_oFDCAN14_603295cf_Tx                                 16u
#define CanIfConf_CanIfTxPduCfg_PntDebugData_2_oFDCAN14_9304bca8_Tx                                 17u
#define CanIfConf_CanIfTxPduCfg_PntDebugData_1_oFDCAN14_5d2fc140_Tx                                 18u
#define CanIfConf_CanIfTxPduCfg_PntDebugData_0_oFDCAN14_ae19e827_Tx                                 19u
#define CanIfConf_CanIfTxPduCfg_Minimum_Sensor_Distance_3_oFDCAN14_29aa616f_Tx                      20u
#define CanIfConf_CanIfTxPduCfg_Minimum_Sensor_Distance_2_oFDCAN14_23601cc6_Tx                      21u
#define CanIfConf_CanIfTxPduCfg_Minimum_Sensor_Distance_1_oFDCAN14_3c3e9a3d_Tx                      22u
#define CanIfConf_CanIfTxPduCfg_Log_PackedDiagFlagData2_v_oFDCAN14_b3328600_Tx                      23u
#define CanIfConf_CanIfTxPduCfg_Log_PackedNoiseMeasData_oFDCAN14_32d10e8e_Tx                        24u
#define CanIfConf_CanIfTxPduCfg_Log_PackedDiagFlagData1_v_oFDCAN14_40a1873d_Tx                      25u
#define CanIfConf_CanIfTxPduCfg_Log_SnrMeasData_03_oFDCAN14_11beb26e_Tx                             26u
#define CanIfConf_CanIfTxPduCfg_ME_SystemStatus_oFDCAN14_3392fde0_Tx                                27u
#define CanIfConf_CanIfTxPduCfg_ME_DebugMsgUnsigned_oFDCAN14_e8b674cc_Tx                            28u
#define CanIfConf_CanIfTxPduCfg_ME_DebugMsgSigned_oFDCAN14_16ce7da0_Tx                              29u
#define CanIfConf_CanIfTxPduCfg_Log_SnrTemperature_oFDCAN14_4577f469_Tx                             30u
#define CanIfConf_CanIfTxPduCfg_Log_SnrMeasData_07_oFDCAN14_1045d0af_Tx                             31u
#define CanIfConf_CanIfTxPduCfg_Log_SnrMeasData_06_oFDCAN14_66e7498f_Tx                             32u
#define CanIfConf_CanIfTxPduCfg_Log_SnrMeasData_05_oFDCAN14_fd00e2ef_Tx                             33u
#define CanIfConf_CanIfTxPduCfg_Log_SnrMeasData_04_oFDCAN14_8ba27bcf_Tx                             34u
#define CanIfConf_CanIfTxPduCfg_DebugModelOutput_Feature_KPI_Tx_oFDCAN14_fae6f83c_Tx                35u
#define CanIfConf_CanIfTxPduCfg_Log_SnrMeasData_02_oFDCAN14_671c2b4e_Tx                             36u
#define CanIfConf_CanIfTxPduCfg_Log_SnrMeasData_01_oFDCAN14_fcfb802e_Tx                             37u
#define CanIfConf_CanIfTxPduCfg_Diagnostics_Flags_oFDCAN14_82d05e9d_Tx                              38u
#define CanIfConf_CanIfTxPduCfg_Blockage_Flags_oFDCAN14_cd9c3e01_Tx                                 39u
#define CanIfConf_CanIfTxPduCfg_ME_MCUOsDebugData2_oFDCAN14_977545dd_Tx                             40u
#define CanIfConf_CanIfTxPduCfg_ME_MCUOsDebugData1_oFDCAN14_0c92eebd_Tx                             41u
#define CanIfConf_CanIfTxPduCfg_ME_SystemDebugData_1_oFDCAN14_6a0508c3_Tx                           42u
#define CanIfConf_CanIfTxPduCfg_ME_SnsDat_Rear_Direct_oFDCAN14_6726d174_Tx                          43u
#define CanIfConf_CanIfTxPduCfg_ME_SnsDat_Front_Direct_oFDCAN14_92d50a6c_Tx                         44u
#define CanIfConf_CanIfTxPduCfg_ME_SnsDat_Rear_Direct_2_oFDCAN14_762da0cc_Tx                        45u
#define CanIfConf_CanIfTxPduCfg_ME_SnsDat_Front_Direct_2_oFDCAN14_d7e5c444_Tx                       46u
#define CanIfConf_CanIfTxPduCfg_ME_SnsDat_Rear_Indirect_1_oFDCAN14_75ed542b_Tx                      47u
#define CanIfConf_CanIfTxPduCfg_ME_SnsDat_Front_Indirect_1_oFDCAN14_a0b9888a_Tx                     48u
#define CanIfConf_CanIfTxPduCfg_ME_SnsDat_Rear_Indirect_2_oFDCAN14_6ab3d2d0_Tx                      49u
#define CanIfConf_CanIfTxPduCfg_ME_SnsDat_Front_Indirect_2_oFDCAN14_38edffe1_Tx                     50u
#define CanIfConf_CanIfTxPduCfg_ME_Debug_SensorTestData_3_oFDCAN14_ffe1e91c_Tx                      51u
#define CanIfConf_CanIfTxPduCfg_ME_Debug_SensorTestData_2_oFDCAN14_f52b94b5_Tx                      52u
#define CanIfConf_CanIfTxPduCfg_ME_Debug_SensorTestData_1_oFDCAN14_ea75124e_Tx                      53u
#define CanIfConf_CanIfTxPduCfg_FPADebugInfo1_oFDCAN14_ba73bd7c_Tx                                  54u
#define CanIfConf_CanIfTxPduCfg_USSDebugInfo2_oFDCAN14_a2853d8e_Tx                                  55u
#define CanIfConf_CanIfTxPduCfg_USSDebugInfo1_oFDCAN14_71151b40_Tx                                  56u
#define CanIfConf_CanIfTxPduCfg_PLDDebugInfo2_oFDCAN14_12211571_Tx                                  57u
#define CanIfConf_CanIfTxPduCfg_PLDDebugInfo1_oFDCAN14_c1b133bf_Tx                                  58u
#define CanIfConf_CanIfTxPduCfg_LMD_SegmentDebug_2_2_oFDCAN14_be3e1ae4_Tx                           59u
#define CanIfConf_CanIfTxPduCfg_LMD_SegmentDebug_2_1_oFDCAN14_01887f27_Tx                           60u
#define CanIfConf_CanIfTxPduCfg_LMD_SegmentDebug_1_2_oFDCAN14_6331b408_Tx                           61u
#define CanIfConf_CanIfTxPduCfg_LMD_SegmentDebug_1_oFDCAN14_3a13c4d8_Tx                             62u
#define CanIfConf_CanIfTxPduCfg_LMD_LaneLinesDebug_2_oFDCAN14_965d36d3_Tx                           63u
#define CanIfConf_CanIfTxPduCfg_Debug_ModuleState_oFDCAN14_96e19c7d_Tx                              64u
#define CanIfConf_CanIfTxPduCfg_Debug_CalibSts_oFDCAN14_58546a56_Tx                                 65u
#define CanIfConf_CanIfTxPduCfg_Debug_ErrCodeAlgo_oFDCAN14_78756c50_Tx                              66u
#define CanIfConf_CanIfTxPduCfg_Firing_Sequence_oFDCAN14_afdc26b0_Tx                                67u
#define CanIfConf_CanIfTxPduCfg_Firing_Sensors_oFDCAN14_474d0a36_Tx                                 68u
#define CanIfConf_CanIfTxPduCfg_Firing_Mode_oFDCAN14_60360c0e_Tx                                    69u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_11_oFDCAN14_2ace4b8f_Tx                          70u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_10_oFDCAN14_4563a97d_Tx                          71u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_9_oFDCAN14_ed3689c6_Tx                           72u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_8_oFDCAN14_87a4aa87_Tx                           73u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_7_oFDCAN14_ab58528b_Tx                           74u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_6_oFDCAN14_c1ca71ca_Tx                           75u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_5_oFDCAN14_7e7c1409_Tx                           76u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_4_oFDCAN14_14ee3748_Tx                           77u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_3_oFDCAN14_da61d9ce_Tx                           78u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_2_oFDCAN14_b0f3fa8f_Tx                           79u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_1_oFDCAN14_0f459f4c_Tx                           80u
#define CanIfConf_CanIfTxPduCfg_Distance_Point_Map_0_oFDCAN14_65d7bc0d_Tx                           81u
#define CanIfConf_CanIfTxPduCfg_DebugModelOutput_oFDCAN14_6b4c9d3e_Tx                               82u
#define CanIfConf_CanIfTxPduCfg_FODDebug_oFDCAN14_0f411cd7_Tx                                       83u
#define CanIfConf_CanIfTxPduCfg_THADebugInfo2_oFDCAN14_062cf8ad_Tx                                  84u
#define CanIfConf_CanIfTxPduCfg_THADebugInfo1_oFDCAN14_d5bcde63_Tx                                  85u
#define CanIfConf_CanIfTxPduCfg_LMD_LaneLinesDebug_1_oFDCAN14_29eb5310_Tx                           86u
#define CanIfConf_CanIfTxPduCfg_MOT_Obj_8_9_oFDCAN14_bd8ad539_Tx                                    87u
#define CanIfConf_CanIfTxPduCfg_MOT_Obj_6_7_oFDCAN14_35343c77_Tx                                    88u
#define CanIfConf_CanIfTxPduCfg_MOT_Obj_4_5_oFDCAN14_cf8dc798_Tx                                    89u
#define CanIfConf_CanIfTxPduCfg_MOT_Obj_2_3_oFDCAN14_1b36cde8_Tx                                    90u
#define CanIfConf_CanIfTxPduCfg_MOT_Obj_0_1_oFDCAN14_e18f3607_Tx                                    91u
#define CanIfConf_CanIfTxPduCfg_Debug_FPA_HMI_InfoToVC_oFDCAN14_0eea4eb6_Tx                         92u
#define CanIfConf_CanIfTxPduCfg_Debug_NFCD_Obj_5_9_oFDCAN14_b99541d7_Tx                             93u
#define CanIfConf_CanIfTxPduCfg_Debug_NFCD_Obj_0_4_oFDCAN14_a030e1d4_Tx                             94u
#define CanIfConf_CanIfTxPduCfg_Debug_AP_Variables_oFDCAN14_07efddff_Tx                             95u
#define CanIfConf_CanIfTxPduCfg_TRSC_FID_DebugMessage_oFDCAN14_04f18303_Tx                          96u
#define CanIfConf_CanIfTxPduCfg_TRSC_Detection_DebugMessage_oFDCAN14_e6f5f3c5_Tx                    97u
#define CanIfConf_CanIfTxPduCfg_TRSC_Debug_Message3_oFDCAN14_35eb5fb3_Tx                            98u
#define CanIfConf_CanIfTxPduCfg_TRSC_Debug_Message2_oFDCAN14_60efdc35_Tx                            99u
#define CanIfConf_CanIfTxPduCfg_Debug_EOLCalib_Data_2_oFDCAN14_1ed59804_Tx                          100u
#define CanIfConf_CanIfTxPduCfg_Debug_CurrentCalib_Data_2_oFDCAN14_192cb625_Tx                      101u
#define CanIfConf_CanIfTxPduCfg_Debug_FeatureCollection_oFDCAN14_4fc45f26_Tx                        102u
#define CanIfConf_CanIfTxPduCfg_Debug_TargetData_oFDCAN14_78b5aec6_Tx                               103u
#define CanIfConf_CanIfTxPduCfg_Debug_OCCalib_Data_oFDCAN14_99914301_Tx                             104u
#define CanIfConf_CanIfTxPduCfg_Debug_SCCalib_Data_oFDCAN14_415523bc_Tx                             105u
#define CanIfConf_CanIfTxPduCfg_Debug_EOLCalib_Data_1_oFDCAN14_ae23bf12_Tx                          106u
#define CanIfConf_CanIfTxPduCfg_TRSC_Debug_Message1_oFDCAN14_9fe258bf_Tx                            107u
#define CanIfConf_CanIfTxPduCfg_Debug_HMI_Internal_Data_oFDCAN14_49de4f3c_Tx                        108u
#define CanIfConf_CanIfTxPduCfg_Debug_HMI_Input_Data_oFDCAN14_3b9e1113_Tx                           109u
#define CanIfConf_CanIfTxPduCfg_Debug_HMI_Trailer_Views_Data_oFDCAN14_a612f060_Tx                   110u
#define CanIfConf_CanIfTxPduCfg_HMI_Curr_Displayed_ProxiConfig_oFDCAN14_4ee7a674_Tx                 111u
#define CanIfConf_CanIfTxPduCfg_HMI_Curr_Requested_ProxiConfig_oFDCAN14_69d6981b_Tx                 112u
#define CanIfConf_CanIfTxPduCfg_HMI_Curr_Displayed_Overlays_oFDCAN14_228998f0_Tx                    113u
#define CanIfConf_CanIfTxPduCfg_HMI_Curr_Requested_Overlays_oFDCAN14_5ad84df2_Tx                    114u
#define CanIfConf_CanIfTxPduCfg_NM_PAM_oFDCAN14_636c02e4_Tx                                         115u
#define CanIfConf_CanIfTxPduCfg_TRSCM_FD_1_oFDCAN14_24b0a50e_Tx                                     116u
#define CanIfConf_CanIfTxPduCfg_CVPAM_FD_Info_oFDCAN14_98d10c56_Tx                                  117u
#define CanIfConf_CanIfTxPduCfg_ADAS_FD_LANES_2_oFDCAN14_1fc7bdbe_Tx                                118u
#define CanIfConf_CanIfTxPduCfg_ADAS_FD_LANES_1_oFDCAN14_03fcfef0_Tx                                119u
#define CanIfConf_CanIfTxPduCfg_CVPAM_FD_Control_oFDCAN14_f55d7751_Tx                               120u


/**********************************************************************************************************************
  \def  AUTOSAR Rx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfRxPduCfg_CVADAS_95874157_Rx                                                  0u
#define CanIfConf_CanIfRxPduCfg_XCP_Rx_oFDCAN2_957ff1e4_Rx                                          1u
#define CanIfConf_CanIfRxPduCfg_PDC_INFO_FD_TRLR_REV_oFDCAN2_76ae5916_Rx                            2u
#define CanIfConf_CanIfRxPduCfg_PDC_INFO_FD_BSM2_oFDCAN2_555bedb6_Rx                                3u
#define CanIfConf_CanIfRxPduCfg_PDC_INFO_FD_CADM2_oFDCAN2_9d0a5374_Rx                               4u
#define CanIfConf_CanIfRxPduCfg_PDC_INFO_FD_SGW_oFDCAN2_8b0ead97_Rx                                 5u
#define CanIfConf_CanIfRxPduCfg_PDC_INFO_FD_ADCM_oFDCAN2_43f16f06_Rx                                6u
#define CanIfConf_CanIfRxPduCfg_PDC_INFO_FD_ORC_oFDCAN2_c0f4295b_Rx                                 7u
#define CanIfConf_CanIfRxPduCfg_PDC_INFO_FD_EPS_oFDCAN2_0100550f_Rx                                 8u
#define CanIfConf_CanIfRxPduCfg_PDC_INFO_FD_BCM_oFDCAN2_51e02ec5_Rx                                 9u
#define CanIfConf_CanIfRxPduCfg_CFG_DATA_CODE_REQUEST_oFDCAN2_a6af4d1a_Rx                           10u
#define CanIfConf_CanIfRxPduCfg_IPC_FD_1_oFDCAN2_255aca61_Rx                                        11u
#define CanIfConf_CanIfRxPduCfg_BCM_FD_7_oFDCAN2_1c05063e_Rx                                        12u
#define CanIfConf_CanIfRxPduCfg_DIAGNOSTIC_REQUEST_FD_FUNCTIONAL_Tp_oFDCAN2_75504700_Rx             13u
#define CanIfConf_CanIfRxPduCfg_DIAGNOSTIC_REQUEST_FD_FUNCTIONAL_Tp_oFDCAN2_20_89fbaae9_Rx          14u
#define CanIfConf_CanIfRxPduCfg_DIAGNOSTIC_REQUEST_FUNCTIONAL_Tp_oFDCAN2_32bd5e48_Rx                15u
#define CanIfConf_CanIfRxPduCfg_DIAGNOSTIC_REQUEST_FD_PAM_Tp_oFDCAN2_a33697dc_Rx                    16u
#define CanIfConf_CanIfRxPduCfg_DIAGNOSTIC_REQUEST_FD_PAM_Tp_oFDCAN2_20_b2dd874c_Rx                 17u
#define CanIfConf_CanIfRxPduCfg_DIAGNOSTIC_REQUEST_PAM_Tp_oFDCAN2_85a60f0e_Rx                       18u
#define CanIfConf_CanIfRxPduCfg_TRSKM_FD_1_oFDCAN2_6974e197_Rx                                      19u
#define CanIfConf_CanIfRxPduCfg_BCM_FD_29_oFDCAN2_a9ee0c40_Rx                                       20u
#define CanIfConf_CanIfRxPduCfg_TELEMATIC_FD_14_oFDCAN2_95ebb865_Rx                                 21u
#define CanIfConf_CanIfRxPduCfg_TRANSM_FD_4_oFDCAN2_2b2bdf8f_Rx                                     22u
#define CanIfConf_CanIfRxPduCfg_ENGINE_FD_7_oFDCAN2_75464136_Rx                                     23u
#define CanIfConf_CanIfRxPduCfg_ASCM_FD_2_oFDCAN2_e0d28be9_Rx                                       24u
#define CanIfConf_CanIfRxPduCfg_IPC_VEHICLE_SETUP_oFDCAN2_ad6c5915_Rx                               25u
#define CanIfConf_CanIfRxPduCfg_BCM_FD_27_oFDCAN2_5243ac07_Rx                                       26u
#define CanIfConf_CanIfRxPduCfg_BCM_FD_12_oFDCAN2_f75168bb_Rx                                       27u
#define CanIfConf_CanIfRxPduCfg_TELEMATIC_FD_5_oFDCAN2_d3090214_Rx                                  28u
#define CanIfConf_CanIfRxPduCfg_ASCM_FD_1_oFDCAN2_b0efc15e_Rx                                       29u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_5_oFDCAN2_9836b6c3_Rx                                      30u
#define CanIfConf_CanIfRxPduCfg_BCM_FD_10_oFDCAN2_9778e461_Rx                                       31u
#define CanIfConf_CanIfRxPduCfg_DRIVETRAIN_FD_3_oFDCAN2_d0fa3352_Rx                                 32u
#define CanIfConf_CanIfRxPduCfg_BCM_FD_9_oFDCAN2_82510968_Rx                                        33u
#define CanIfConf_CanIfRxPduCfg_EPS_FD_2_oFDCAN2_002075f8_Rx                                        34u
#define CanIfConf_CanIfRxPduCfg_VIN_oFDCAN2_de66582f_Rx                                             35u
#define CanIfConf_CanIfRxPduCfg_BCM_FD_3_oFDCAN2_f21ddb5c_Rx                                        36u
#define CanIfConf_CanIfRxPduCfg_ORC_FD_1_oFDCAN2_9afbe59f_Rx                                        37u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_4_oFDCAN2_c519be37_Rx                                      38u
#define CanIfConf_CanIfRxPduCfg_TELEMATIC_FD_11_oFDCAN2_3a2ad576_Rx                                 39u
#define CanIfConf_CanIfRxPduCfg_GLOB_NAV_FD_C2_oFDCAN2_7d3f2e2d_Rx                                  40u
#define CanIfConf_CanIfRxPduCfg_TRANSM_FD_2_oFDCAN2_bdde8790_Rx                                     41u
#define CanIfConf_CanIfRxPduCfg_ENGINE_FD_5_oFDCAN2_071576c3_Rx                                     42u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_1_oFDCAN2_37fb9352_Rx                                      43u
#define CanIfConf_CanIfRxPduCfg_AGSM_FD_2_oFDCAN2_b4392bd1_Rx                                       44u
#define CanIfConf_CanIfRxPduCfg_ADAS_FD_INFO_C2_oFDCAN2_b80f734c_Rx                                 45u
#define CanIfConf_CanIfRxPduCfg_TRANSM_FD_1_oFDCAN2_1b1ca8bf_Rx                                     46u
#define CanIfConf_CanIfRxPduCfg_EPS_FD_1_oFDCAN2_a112af31_Rx                                        47u
#define CanIfConf_CanIfRxPduCfg_ENGINE_FD_2_oFDCAN2_45713606_Rx                                     48u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_3_oFDCAN2_8da582ba_Rx                                      49u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_2_oFDCAN2_d08a8a4e_Rx                                      50u
#define CanIfConf_CanIfRxPduCfg_BRAKE2_FD_1_oFDCAN2_a11783f2_Rx                                     51u
#define CanIfConf_CanIfRxPduCfg_BCM_FD_2_oFDCAN2_24236f24_Rx                                        52u
#define CanIfConf_CanIfRxPduCfg_CVADAS_efa31eaf_Rx                                                  53u
#define CanIfConf_CanIfRxPduCfg_SetUSSParkingMode_oFDCAN14_120f62ca_Rx                              54u
#define CanIfConf_CanIfRxPduCfg_PntDebugData_Rx_oFDCAN14_6aed7921_Rx                                55u
#define CanIfConf_CanIfRxPduCfg_ENGINE_FD_7_oFDCAN14_6291a34e_Rx                                    56u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_5_oFDCAN14_2f8081eb_Rx                                     57u
#define CanIfConf_CanIfRxPduCfg_EPS_FD_2_oFDCAN14_e882ffe3_Rx                                       58u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_4_oFDCAN14_274e2aee_Rx                                     59u
#define CanIfConf_CanIfRxPduCfg_ENGINE_FD_5_oFDCAN14_5e6dd4a8_Rx                                    60u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_7_oFDCAN14_3e1dd7e1_Rx                                     61u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_1_oFDCAN14_0cba2dff_Rx                                     62u
#define CanIfConf_CanIfRxPduCfg_ADAS_FD_INFO_oFDCAN14_23de1d3b_Rx                                   63u
#define CanIfConf_CanIfRxPduCfg_EPS_FD_1_oFDCAN14_0ff3e6ff_Rx                                       64u
#define CanIfConf_CanIfRxPduCfg_ENGINE_FD_2_oFDCAN14_05177771_Rx                                    65u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_3_oFDCAN14_1d277bf5_Rx                                     66u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_2_oFDCAN14_15e9d0f0_Rx                                     67u
#define CanIfConf_CanIfRxPduCfg_BRAKE2_FD_1_oFDCAN14_d8d4c6d0_Rx                                    68u
#define CanIfConf_CanIfRxPduCfg_PT_TORQUE_FD_1_oFDCAN14_a0affdba_Rx                                 69u
#define CanIfConf_CanIfRxPduCfg_BRAKE_FD_6_oFDCAN14_36d37ce4_Rx                                     70u



/**********************************************************************************************************************
  \def  Tx buffer type
**********************************************************************************************************************/

#define CanIfTxBufferType                    BYTE_QUEUE

/**********************************************************************************************************************
  \def  For ASR4.0.3/ASR4.2.2 compatibility - indirection macros
**********************************************************************************************************************/
#define  CanIf_30_Mcan_RxIndication(Hrh, CanId, CanDlc, CanSduPtr) CanIf_RxIndicationAsr403((Hrh), (CanId), (CanDlc), (CanSduPtr)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/**********************************************************************************************************************
  \def  Multiple CAN driver / CAN driver with VendorApiInfix - indirection macros
**********************************************************************************************************************/
#define CanIf_30_Mcan_TxConfirmation(CanTxPduId)                                                    (CanIf_TxConfirmation((CanTxPduId))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define CanIf_30_Mcan_ControllerBusOff(ControllerId)                                                (CanIf_ControllerBusOff((ControllerId))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define CanIf_30_Mcan_ControllerModeIndication(ControllerId, ControllerMode)                        (CanIf_ControllerModeIndication((ControllerId), (ControllerMode))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */



/**********************************************************************************************************************
  \def  Transceiver handling indirection macros
**********************************************************************************************************************/

#define CanIf_30_Tja1043_TrcvModeIndication(TransceiverId, TransceiverMode)                         (CanIf_TrcvModeIndication((TransceiverId), TransceiverMode)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */





/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/


/* Coded in RxPduCanId of table CanIf_RxPduConfig[] */
#define CANIF_MASKCODE_RANGE_FLAG                                                                   0x20000000u
#define CANIF_FD_FLAG                                                                               0x40000000u
#define CANIF_FD_FLAG_MASKOUT                                                                       0xBFFFFFFFu
#define CANIF_FD_FLAG_SHIFTPOS                                                                      30u
/* Coded in RxPduMask of table CanIf_RxPduConfig[] */
#define CANIF_STOP_FLAG                                                                             0x40000000u
#define CANIF_RANGE_FLAG                                                                            0x20000000u
#define CANIF_STOP_RANGE_FLAG                                                                       0x60000000u
#define CANIF_STOP_RANGE_FLAG_MASKOUT                                                               0x9FFFFFFFu


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCDataSwitches  CanIf Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_BUSOFFNOTIFICATIONFCTPTR                                                              STD_ON
#define CANIF_CANCONTROLLERIDUPTOLOWMAP                                                             STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBLIDXOFCANCONTROLLERIDUPTOLOWMAP                                            STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBLUSEDOFCANCONTROLLERIDUPTOLOWMAP                                           STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CONTROLLEROFCANCONTROLLERIDUPTOLOWMAP                                                 STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBL                                                                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANCELTXFCTOFCANDRVFCTTBL                                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CancelTxFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHANGEBAUDRATEFCTOFCANDRVFCTTBL                                                       STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHECKBAUDRATEFCTOFCANDRVFCTTBL                                                        STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHECKWAKEUPFCTOFCANDRVFCTTBL                                                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERERRORSTATEFCTOFCANDRVFCTTBL                                              STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERRXERRORCOUNTEROFCANDRVFCTTBL                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERTXERRORCOUNTEROFCANDRVFCTTBL                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKENABLECONTROLLERFCTOFCANDRVFCTTBL                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKENABLEMAILBOXFCTOFCANDRVFCTTBL                                                STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKEXECUTEFCTOFCANDRVFCTTBL                                                      STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_SETBAUDRATEFCTOFCANDRVFCTTBL                                                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_SETCONTROLLERMODEFCTOFCANDRVFCTTBL                                                    STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_WRITEFCTOFCANDRVFCTTBL                                                                STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIG                                                     STD_ON
#define CANIF_INVALIDHNDOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                                         STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfig.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' */
#define CANIF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                        STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                      STD_ON
#define CANIF_CANTRCVFCTTBL                                                                         STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CHECKWAKEFLAGFCTOFCANTRCVFCTTBL                                                       STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CHECKWAKEUPFCTOFCANTRCVFCTTBL                                                         STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CLEARTRCVWUFFLAGFCTOFCANTRCVFCTTBL                                                    STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_GETBUSWUREASONFCTOFCANTRCVFCTTBL                                                      STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_GETOPMODEFCTOFCANTRCVFCTTBL                                                           STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_SETOPMODEFCTOFCANTRCVFCTTBL                                                           STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_SETWAKEUPMODEFCTOFCANTRCVFCTTBL                                                       STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CTRLCONFIG                                                                            STD_ON
#define CANIF_FEATUREPNWUTXPDUFILTERENABLEDOFCTRLCONFIG                                             STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'PN wake-up Tx-PDU filter is deactivated.' */
#define CANIF_J1939DYNADDROFFSETOFCTRLCONFIG                                                        STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'J1939 dynamic address support is deactivated.' */
#define CANIF_J1939DYNADDRSUPPORTOFCTRLCONFIG                                                       STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'J1939 dynamic address support is deactivated.' */
#define CANIF_RXDHRANDOMNUMBER1OFCTRLCONFIG                                                         STD_ON
#define CANIF_RXDHRANDOMNUMBER2OFCTRLCONFIG                                                         STD_ON
#define CANIF_CTRLMODEINDICATIONFCTPTR                                                              STD_ON
#define CANIF_CTRLSTATES                                                                            STD_ON
#define CANIF_CTRLMODEOFCTRLSTATES                                                                  STD_ON
#define CANIF_PDUMODEOFCTRLSTATES                                                                   STD_ON
#define CANIF_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'CanIf_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSION                                                         STD_ON
#define CANIF_GENERATORVERSION                                                                      STD_ON
#define CANIF_HXHOFFSET                                                                             STD_OFF  /**< Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'CanIf_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIG                                                                         STD_ON
#define CANIF_CTRLSTATESIDXOFMAILBOXCONFIG                                                          STD_ON
#define CANIF_MAILBOXTYPEOFMAILBOXCONFIG                                                            STD_ON
#define CANIF_PDUIDFIRSTOFMAILBOXCONFIG                                                             STD_ON
#define CANIF_PDUIDLASTOFMAILBOXCONFIG                                                              STD_ON
#define CANIF_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                         STD_ON
#define CANIF_TXBUFFERCFGOFMAILBOXCONFIG                                                            STD_ON
#define CANIF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                                                        STD_ON
#define CANIF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                                                   STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIG                                                                 STD_ON
#define CANIF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                                               STD_ON
#define CANIF_MAXTRCVHANDLEIDPLUSONE                                                                STD_ON
#define CANIF_MAXWAKEUPSOURCES                                                                      STD_ON
#define CANIF_PDURXMODE                                                                             STD_OFF  /**< Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANIF_RXDHADJUST                                                                            STD_ON
#define CANIF_RXINDICATIONFCTLIST                                                                   STD_ON
#define CANIF_RXINDICATIONFCTOFRXINDICATIONFCTLIST                                                  STD_ON
#define CANIF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                                               STD_ON
#define CANIF_RXPDUCONFIG                                                                           STD_ON
#define CANIF_CANIFRXPDUIDOFRXPDUCONFIG                                                             STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfig.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' */
#define CANIF_ISCANNMRXPDUOFRXPDUCONFIG                                                             STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfig.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' */
#define CANIF_ISDATACHECKSUMRXPDUOFRXPDUCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfig.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' */
#define CANIF_MSGTYPEOFRXPDUCONFIG                                                                  STD_ON
#define CANIF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                                                   STD_ON
#define CANIF_RXMETADATALENGTHOFRXPDUCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfig.RxMetaDataLength' Reason: 'Rx meta data support is deactivated.' */
#define CANIF_RXPDUCANIDOFRXPDUCONFIG                                                               STD_ON
#define CANIF_RXPDUDLCOFRXPDUCONFIG                                                                 STD_ON
#define CANIF_RXPDUMASKOFRXPDUCONFIG                                                                STD_ON
#define CANIF_UPPERPDUIDOFRXPDUCONFIG                                                               STD_ON
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                                               STD_ON
#define CANIF_SIZEOFCTRLCONFIG                                                                      STD_ON
#define CANIF_SIZEOFCTRLSTATES                                                                      STD_ON
#define CANIF_SIZEOFMAILBOXCONFIG                                                                   STD_ON
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIG                                                           STD_ON
#define CANIF_SIZEOFRXDHADJUST                                                                      STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLIST                                                             STD_ON
#define CANIF_SIZEOFRXPDUCONFIG                                                                     STD_ON
#define CANIF_SIZEOFTRCVTOCTRLMAP                                                                   STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASE                                                         STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                                              STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS                                        STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLIST                                                           STD_ON
#define CANIF_SIZEOFTXPDUCONFIG                                                                     STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEX                                                                 STD_ON
#define CANIF_SIZEOFTXQUEUE                                                                         STD_ON
#define CANIF_SIZEOFTXQUEUEDATA                                                                     STD_ON
#define CANIF_SIZEOFTXQUEUEINDEX2DATASTARTSTOP                                                      STD_ON
#define CANIF_SIZEOFWAKEUPCONFIG                                                                    STD_ON
#define CANIF_TRANSCEIVERUPTOLOWMAP                                                                 STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CANTRCVFCTTBLIDXOFTRANSCEIVERUPTOLOWMAP                                               STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_TRANSCEIVEROFTRANSCEIVERUPTOLOWMAP                                                    STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_TRANSCEIVERUPTOUPPERMAP                                                               STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_TRCVMODEINDICATIONFCTPTR                                                              STD_ON
#define CANIF_TRCVTOCTRLMAP                                                                         STD_ON
#define CANIF_TXBUFFERFIFOCONFIG                                                                    STD_OFF  /**< Deactivateable: 'CanIf_TxBufferFifoConfig' Reason: 'Tx-buffer FIFO support is deactivated.' */
#define CANIF_SIZEOFONEPAYLOADELOFTXBUFFERFIFOCONFIG                                                STD_OFF  /**< Deactivateable: 'CanIf_TxBufferFifoConfig.SizeOfOnePayloadEl' Reason: 'Tx-buffer FIFO support is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBASE                                                               STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBITQUEUECONFIG                                                     STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdBitQueueConfig' Reason: 'Tx-buffer PRIO_BY_CANID support as BIT_QUEUE is deactivated.' */
#define CANIF_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                               STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdBitQueueConfig.BitPos2TxPduIdOffset' Reason: 'Tx-buffer PRIO_BY_CANID support as BIT_QUEUE is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                                                    STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                        STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG    STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG    STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG  STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS                                              STD_ON
#define CANIF_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS                              STD_ON
#define CANIF_TXCONFIRMATIONFCTLIST                                                                 STD_ON
#define CANIF_TXPDUCONFIG                                                                           STD_ON
#define CANIF_CANIDOFTXPDUCONFIG                                                                    STD_ON
#define CANIF_CANIDTXMASKOFTXPDUCONFIG                                                              STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.CanIdTxMask' Reason: 'Tx meta data support is deactivated.' */
#define CANIF_CTRLSTATESIDXOFTXPDUCONFIG                                                            STD_ON
#define CANIF_ISDATACHECKSUMTXPDUOFTXPDUCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' */
#define CANIF_ISPNWUTXPDUOFTXPDUCONFIG                                                              STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' */
#define CANIF_ISTXPDUTRUNCATIONOFTXPDUCONFIG                                                        STD_ON
#define CANIF_MAILBOXCONFIGIDXOFTXPDUCONFIG                                                         STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                                                 STD_ON
#define CANIF_TXMETADATALENGTHOFTXPDUCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.TxMetaDataLength' Reason: 'Tx meta data support is deactivated.' */
#define CANIF_TXPDULENGTHOFTXPDUCONFIG                                                              STD_ON
#define CANIF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                                                        STD_ON
#define CANIF_TXPDUQUEUEINDEX                                                                       STD_ON
#define CANIF_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                           STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX                                        STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOPUSEDOFTXPDUQUEUEINDEX                                       STD_ON
#define CANIF_TXQUEUEOFTXPDUQUEUEINDEX                                                              STD_ON
#define CANIF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                                                          STD_ON
#define CANIF_TXPDUSTATIC2DYNAMICINDIRECTION                                                        STD_OFF  /**< Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' */
#define CANIF_TXQUEUE                                                                               STD_ON
#define CANIF_TXQUEUEDATA                                                                           STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOP                                                            STD_ON
#define CANIF_TXQUEUEDATAENDIDXOFTXQUEUEINDEX2DATASTARTSTOP                                         STD_ON
#define CANIF_TXQUEUEDATALENGTHOFTXQUEUEINDEX2DATASTARTSTOP                                         STD_ON
#define CANIF_TXQUEUEDATASTARTIDXOFTXQUEUEINDEX2DATASTARTSTOP                                       STD_ON
#define CANIF_TXQUEUEDATAUSEDOFTXQUEUEINDEX2DATASTARTSTOP                                           STD_ON
#define CANIF_ULRXPDUID2INTERNALRXPDUID                                                             STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_RXPDUCONFIGIDXOFULRXPDUID2INTERNALRXPDUID                                             STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_RXPDUCONFIGUSEDOFULRXPDUID2INTERNALRXPDUID                                            STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_ULTXPDUID2INTERNALTXPDUID                                                             STD_OFF  /**< Deactivateable: 'CanIf_UlTxPduId2InternalTxPduId' Reason: 'Configuration variant is Pre-compile!' */
#define CANIF_WAKEUPCONFIG                                                                          STD_ON
#define CANIF_CONTROLLERIDOFWAKEUPCONFIG                                                            STD_ON
#define CANIF_WAKEUPSOURCEOFWAKEUPCONFIG                                                            STD_ON
#define CANIF_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                                                     STD_ON
#define CANIF_WAKEUPTARGETMODULEOFWAKEUPCONFIG                                                      STD_ON
#define CANIF_PCCONFIG                                                                              STD_ON
#define CANIF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                                                    STD_ON
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                           STD_ON
#define CANIF_CTRLCONFIGOFPCCONFIG                                                                  STD_ON
#define CANIF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                                                    STD_ON
#define CANIF_CTRLSTATESOFPCCONFIG                                                                  STD_ON
#define CANIF_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                               STD_ON
#define CANIF_GENERATORVERSIONOFPCCONFIG                                                            STD_ON
#define CANIF_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIGOFPCCONFIG                                                               STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                       STD_ON
#define CANIF_MAXTRCVHANDLEIDPLUSONEOFPCCONFIG                                                      STD_ON
#define CANIF_MAXWAKEUPSOURCESOFPCCONFIG                                                            STD_ON
#define CANIF_RXDHADJUSTOFPCCONFIG                                                                  STD_ON
#define CANIF_RXINDICATIONFCTLISTOFPCCONFIG                                                         STD_ON
#define CANIF_RXPDUCONFIGOFPCCONFIG                                                                 STD_ON
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                     STD_ON
#define CANIF_SIZEOFCTRLCONFIGOFPCCONFIG                                                            STD_ON
#define CANIF_SIZEOFCTRLSTATESOFPCCONFIG                                                            STD_ON
#define CANIF_SIZEOFMAILBOXCONFIGOFPCCONFIG                                                         STD_ON
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                 STD_ON
#define CANIF_SIZEOFRXDHADJUSTOFPCCONFIG                                                            STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLISTOFPCCONFIG                                                   STD_ON
#define CANIF_SIZEOFRXPDUCONFIGOFPCCONFIG                                                           STD_ON
#define CANIF_SIZEOFTRCVTOCTRLMAPOFPCCONFIG                                                         STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                               STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG                                    STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG                              STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLISTOFPCCONFIG                                                 STD_ON
#define CANIF_SIZEOFTXPDUCONFIGOFPCCONFIG                                                           STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEXOFPCCONFIG                                                       STD_ON
#define CANIF_SIZEOFTXQUEUEDATAOFPCCONFIG                                                           STD_ON
#define CANIF_SIZEOFTXQUEUEINDEX2DATASTARTSTOPOFPCCONFIG                                            STD_ON
#define CANIF_SIZEOFTXQUEUEOFPCCONFIG                                                               STD_ON
#define CANIF_SIZEOFWAKEUPCONFIGOFPCCONFIG                                                          STD_ON
#define CANIF_TRCVMODEINDICATIONFCTPTROFPCCONFIG                                                    STD_ON
#define CANIF_TRCVTOCTRLMAPOFPCCONFIG                                                               STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                                     STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG                                          STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG                                    STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTOFPCCONFIG                                                       STD_ON
#define CANIF_TXPDUCONFIGOFPCCONFIG                                                                 STD_ON
#define CANIF_TXPDUQUEUEINDEXOFPCCONFIG                                                             STD_ON
#define CANIF_TXQUEUEDATAOFPCCONFIG                                                                 STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOPOFPCCONFIG                                                  STD_ON
#define CANIF_TXQUEUEOFPCCONFIG                                                                     STD_ON
#define CANIF_WAKEUPCONFIGOFPCCONFIG                                                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCMinNumericValueDefines  CanIf Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CANIF_MIN_TXQUEUEDATA                                                                       0u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCMaxNumericValueDefines  CanIf Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CANIF_MAX_TXQUEUEDATA                                                                       255u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCNoReferenceDefines  CanIf No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                      255u
#define CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                        255u
#define CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX                                     255u
#define CANIF_NO_TXQUEUEDATAENDIDXOFTXQUEUEINDEX2DATASTARTSTOP                                      65535u
#define CANIF_NO_TXQUEUEDATASTARTIDXOFTXQUEUEINDEX2DATASTARTSTOP                                    65535u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEnumExistsDefines  CanIf Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define CANIF_EXISTS_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG_TXBUFFERCFGOFMAILBOXCONFIG                  STD_ON
#define CANIF_EXISTS_NO_TXBUFFERCFGOFMAILBOXCONFIG                                                  STD_ON
#define CANIF_EXISTS_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX                                               STD_ON
#define CANIF_EXISTS_NO_TXQUEUEOFTXPDUQUEUEINDEX                                                    STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEnumDefines  CanIf Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG_TXBUFFERCFGOFMAILBOXCONFIG                         0x00u
#define CANIF_NO_TXBUFFERCFGOFMAILBOXCONFIG                                                         0xFFu
#define CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX                                                      0x00u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIsReducedToDefineDefines  CanIf Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                  STD_OFF
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                STD_OFF
#define CANIF_ISDEF_RXDHRANDOMNUMBER1OFCTRLCONFIG                                                   STD_OFF
#define CANIF_ISDEF_RXDHRANDOMNUMBER2OFCTRLCONFIG                                                   STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFMAILBOXCONFIG                                                    STD_OFF
#define CANIF_ISDEF_MAILBOXTYPEOFMAILBOXCONFIG                                                      STD_OFF
#define CANIF_ISDEF_PDUIDFIRSTOFMAILBOXCONFIG                                                       STD_OFF
#define CANIF_ISDEF_PDUIDLASTOFMAILBOXCONFIG                                                        STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                   STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGOFMAILBOXCONFIG                                                      STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                                                  STD_OFF
#define CANIF_ISDEF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                                             STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                                         STD_OFF
#define CANIF_ISDEF_RXDHADJUST                                                                      STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTOFRXINDICATIONFCTLIST                                            STD_OFF
#define CANIF_ISDEF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                                         STD_OFF
#define CANIF_ISDEF_MSGTYPEOFRXPDUCONFIG                                                            STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                                             STD_OFF
#define CANIF_ISDEF_RXPDUCANIDOFRXPDUCONFIG                                                         STD_OFF
#define CANIF_ISDEF_RXPDUDLCOFRXPDUCONFIG                                                           STD_OFF
#define CANIF_ISDEF_RXPDUMASKOFRXPDUCONFIG                                                          STD_OFF
#define CANIF_ISDEF_UPPERPDUIDOFRXPDUCONFIG                                                         STD_OFF
#define CANIF_ISDEF_TRCVTOCTRLMAP                                                                   STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                  STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS                        STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLIST                                                           STD_OFF
#define CANIF_ISDEF_CANIDOFTXPDUCONFIG                                                              STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFTXPDUCONFIG                                                      STD_OFF
#define CANIF_ISDEF_ISTXPDUTRUNCATIONOFTXPDUCONFIG                                                  STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFTXPDUCONFIG                                                   STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                                           STD_OFF
#define CANIF_ISDEF_TXPDULENGTHOFTXPDUCONFIG                                                        STD_OFF
#define CANIF_ISDEF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                                                  STD_OFF
#define CANIF_ISDEF_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                     STD_OFF
#define CANIF_ISDEF_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX                                  STD_OFF
#define CANIF_ISDEF_TXQUEUEINDEX2DATASTARTSTOPUSEDOFTXPDUQUEUEINDEX                                 STD_OFF
#define CANIF_ISDEF_TXQUEUEOFTXPDUQUEUEINDEX                                                        STD_OFF
#define CANIF_ISDEF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                                                    STD_OFF
#define CANIF_ISDEF_TXQUEUEDATAENDIDXOFTXQUEUEINDEX2DATASTARTSTOP                                   STD_OFF
#define CANIF_ISDEF_TXQUEUEDATALENGTHOFTXQUEUEINDEX2DATASTARTSTOP                                   STD_OFF
#define CANIF_ISDEF_TXQUEUEDATASTARTIDXOFTXQUEUEINDEX2DATASTARTSTOP                                 STD_OFF
#define CANIF_ISDEF_TXQUEUEDATAUSEDOFTXQUEUEINDEX2DATASTARTSTOP                                     STD_OFF
#define CANIF_ISDEF_CONTROLLERIDOFWAKEUPCONFIG                                                      STD_OFF
#define CANIF_ISDEF_WAKEUPSOURCEOFWAKEUPCONFIG                                                      STD_OFF
#define CANIF_ISDEF_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                                               STD_OFF
#define CANIF_ISDEF_WAKEUPTARGETMODULEOFWAKEUPCONFIG                                                STD_OFF
#define CANIF_ISDEF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                                              STD_ON
#define CANIF_ISDEF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                     STD_ON
#define CANIF_ISDEF_CTRLCONFIGOFPCCONFIG                                                            STD_ON
#define CANIF_ISDEF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                                              STD_ON
#define CANIF_ISDEF_CTRLSTATESOFPCCONFIG                                                            STD_ON
#define CANIF_ISDEF_MAILBOXCONFIGOFPCCONFIG                                                         STD_ON
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                 STD_ON
#define CANIF_ISDEF_RXDHADJUSTOFPCCONFIG                                                            STD_ON
#define CANIF_ISDEF_RXINDICATIONFCTLISTOFPCCONFIG                                                   STD_ON
#define CANIF_ISDEF_RXPDUCONFIGOFPCCONFIG                                                           STD_ON
#define CANIF_ISDEF_TRCVMODEINDICATIONFCTPTROFPCCONFIG                                              STD_ON
#define CANIF_ISDEF_TRCVTOCTRLMAPOFPCCONFIG                                                         STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                               STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG                                    STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG                              STD_ON
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTOFPCCONFIG                                                 STD_ON
#define CANIF_ISDEF_TXPDUCONFIGOFPCCONFIG                                                           STD_ON
#define CANIF_ISDEF_TXPDUQUEUEINDEXOFPCCONFIG                                                       STD_ON
#define CANIF_ISDEF_TXQUEUEDATAOFPCCONFIG                                                           STD_ON
#define CANIF_ISDEF_TXQUEUEINDEX2DATASTARTSTOPOFPCCONFIG                                            STD_ON
#define CANIF_ISDEF_TXQUEUEOFPCCONFIG                                                               STD_ON
#define CANIF_ISDEF_WAKEUPCONFIGOFPCCONFIG                                                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEqualsAlwaysToDefines  CanIf Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                    
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                  
#define CANIF_EQ2_RXDHRANDOMNUMBER1OFCTRLCONFIG                                                     
#define CANIF_EQ2_RXDHRANDOMNUMBER2OFCTRLCONFIG                                                     
#define CANIF_EQ2_CTRLSTATESIDXOFMAILBOXCONFIG                                                      
#define CANIF_EQ2_MAILBOXTYPEOFMAILBOXCONFIG                                                        
#define CANIF_EQ2_PDUIDFIRSTOFMAILBOXCONFIG                                                         
#define CANIF_EQ2_PDUIDLASTOFMAILBOXCONFIG                                                          
#define CANIF_EQ2_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                     
#define CANIF_EQ2_TXBUFFERCFGOFMAILBOXCONFIG                                                        
#define CANIF_EQ2_TXBUFFERCFGUSEDOFMAILBOXCONFIG                                                    
#define CANIF_EQ2_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                                               
#define CANIF_EQ2_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                                           
#define CANIF_EQ2_RXDHADJUST                                                                        
#define CANIF_EQ2_RXINDICATIONFCTOFRXINDICATIONFCTLIST                                              
#define CANIF_EQ2_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                                           
#define CANIF_EQ2_MSGTYPEOFRXPDUCONFIG                                                              
#define CANIF_EQ2_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                                               
#define CANIF_EQ2_RXPDUCANIDOFRXPDUCONFIG                                                           
#define CANIF_EQ2_RXPDUDLCOFRXPDUCONFIG                                                             
#define CANIF_EQ2_RXPDUMASKOFRXPDUCONFIG                                                            
#define CANIF_EQ2_UPPERPDUIDOFRXPDUCONFIG                                                           
#define CANIF_EQ2_TRCVTOCTRLMAP                                                                     
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                    
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS                          
#define CANIF_EQ2_TXCONFIRMATIONFCTLIST                                                             
#define CANIF_EQ2_CANIDOFTXPDUCONFIG                                                                
#define CANIF_EQ2_CTRLSTATESIDXOFTXPDUCONFIG                                                        
#define CANIF_EQ2_ISTXPDUTRUNCATIONOFTXPDUCONFIG                                                    
#define CANIF_EQ2_MAILBOXCONFIGIDXOFTXPDUCONFIG                                                     
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                                             
#define CANIF_EQ2_TXPDULENGTHOFTXPDUCONFIG                                                          
#define CANIF_EQ2_UPPERLAYERTXPDUIDOFTXPDUCONFIG                                                    
#define CANIF_EQ2_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                       
#define CANIF_EQ2_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX                                    
#define CANIF_EQ2_TXQUEUEINDEX2DATASTARTSTOPUSEDOFTXPDUQUEUEINDEX                                   
#define CANIF_EQ2_TXQUEUEOFTXPDUQUEUEINDEX                                                          
#define CANIF_EQ2_TXQUEUEUSEDOFTXPDUQUEUEINDEX                                                      
#define CANIF_EQ2_TXQUEUEDATAENDIDXOFTXQUEUEINDEX2DATASTARTSTOP                                     
#define CANIF_EQ2_TXQUEUEDATALENGTHOFTXQUEUEINDEX2DATASTARTSTOP                                     
#define CANIF_EQ2_TXQUEUEDATASTARTIDXOFTXQUEUEINDEX2DATASTARTSTOP                                   
#define CANIF_EQ2_TXQUEUEDATAUSEDOFTXQUEUEINDEX2DATASTARTSTOP                                       
#define CANIF_EQ2_CONTROLLERIDOFWAKEUPCONFIG                                                        
#define CANIF_EQ2_WAKEUPSOURCEOFWAKEUPCONFIG                                                        
#define CANIF_EQ2_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                                                 
#define CANIF_EQ2_WAKEUPTARGETMODULEOFWAKEUPCONFIG                                                  
#define CANIF_EQ2_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                                                (&(CanIf_BusOffNotificationFctPtr))
#define CANIF_EQ2_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                       CanIf_CanIfCtrlId2MappedTxBuffersConfig
#define CANIF_EQ2_CTRLCONFIGOFPCCONFIG                                                              CanIf_CtrlConfig
#define CANIF_EQ2_CTRLMODEINDICATIONFCTPTROFPCCONFIG                                                (&(CanIf_CtrlModeIndicationFctPtr))
#define CANIF_EQ2_CTRLSTATESOFPCCONFIG                                                              CanIf_CtrlStates.raw
#define CANIF_EQ2_MAILBOXCONFIGOFPCCONFIG                                                           CanIf_MailBoxConfig
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                   CanIf_MappedTxBuffersConfig
#define CANIF_EQ2_RXDHADJUSTOFPCCONFIG                                                              CanIf_RxDHAdjust
#define CANIF_EQ2_RXINDICATIONFCTLISTOFPCCONFIG                                                     CanIf_RxIndicationFctList
#define CANIF_EQ2_RXPDUCONFIGOFPCCONFIG                                                             CanIf_RxPduConfig
#define CANIF_EQ2_TRCVMODEINDICATIONFCTPTROFPCCONFIG                                                (&(CanIf_TrcvModeIndicationFctPtr))
#define CANIF_EQ2_TRCVTOCTRLMAPOFPCCONFIG                                                           CanIf_TrcvToCtrlMap
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                                 CanIf_TxBufferPrioByCanIdBase.raw
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG                                      CanIf_TxBufferPrioByCanIdByteQueueConfig
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG                                CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTOFPCCONFIG                                                   CanIf_TxConfirmationFctList
#define CANIF_EQ2_TXPDUCONFIGOFPCCONFIG                                                             CanIf_TxPduConfig
#define CANIF_EQ2_TXPDUQUEUEINDEXOFPCCONFIG                                                         CanIf_TxPduQueueIndex
#define CANIF_EQ2_TXQUEUEDATAOFPCCONFIG                                                             CanIf_TxQueueData.raw
#define CANIF_EQ2_TXQUEUEINDEX2DATASTARTSTOPOFPCCONFIG                                              CanIf_TxQueueIndex2DataStartStop
#define CANIF_EQ2_TXQUEUEOFPCCONFIG                                                                 CanIf_TxQueue.raw
#define CANIF_EQ2_WAKEUPCONFIGOFPCCONFIG                                                            CanIf_WakeUpConfig
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSymbolicInitializationPointers  CanIf Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanIf_Config_Ptr                                                                            NULL_PTR  /**< symbolic identifier which shall be used to initialize 'CanIf' */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCInitializationSymbols  CanIf Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanIf_Config                                                                                NULL_PTR  /**< symbolic identifier which could be used to initialize 'CanIf */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGeneral  CanIf General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANIF_CHECK_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANIF_FINAL_MAGIC_NUMBER                                                                    0x3C1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanIf */
#define CANIF_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanIf' is not configured to be postbuild capable. */
#define CANIF_INIT_DATA                                                                             CANIF_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANIF_INIT_DATA_HASH_CODE                                                                   -713533440  /**< the precompile constant to validate the initialization structure at initialization time of CanIf with a hashcode. The seed value is '0x3C1Eu' */
#define CANIF_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANIF_USE_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer CanIf shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPBDataSwitches  CanIf Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_PBCONFIG                                                                              STD_OFF  /**< Deactivateable: 'CanIf_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANIF_LTCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'CanIf_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANIF_PCCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'CanIf_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCGetConstantDuplicatedRootDataMacros  CanIf Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanIf_GetBusOffNotificationFctPtrOfPCConfig()                                               (&(CanIf_BusOffNotificationFctPtr))  /**< the pointer to CanIf_BusOffNotificationFctPtr */
#define CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                      CanIf_CanIfCtrlId2MappedTxBuffersConfig  /**< the pointer to CanIf_CanIfCtrlId2MappedTxBuffersConfig */
#define CanIf_GetCtrlConfigOfPCConfig()                                                             CanIf_CtrlConfig  /**< the pointer to CanIf_CtrlConfig */
#define CanIf_GetCtrlModeIndicationFctPtrOfPCConfig()                                               (&(CanIf_CtrlModeIndicationFctPtr))  /**< the pointer to CanIf_CtrlModeIndicationFctPtr */
#define CanIf_GetCtrlStatesOfPCConfig()                                                             CanIf_CtrlStates.raw  /**< the pointer to CanIf_CtrlStates */
#define CanIf_GetGeneratorCompatibilityVersionOfPCConfig()                                          0x0212u
#define CanIf_GetGeneratorVersionOfPCConfig()                                                       0x00050400u
#define CanIf_GetMailBoxConfigOfPCConfig()                                                          CanIf_MailBoxConfig  /**< the pointer to CanIf_MailBoxConfig */
#define CanIf_GetMappedTxBuffersConfigOfPCConfig()                                                  CanIf_MappedTxBuffersConfig  /**< the pointer to CanIf_MappedTxBuffersConfig */
#define CanIf_GetMaxTrcvHandleIdPlusOneOfPCConfig()                                                 1u
#define CanIf_GetMaxWakeUpSourcesOfPCConfig()                                                       1u
#define CanIf_GetRxDHAdjustOfPCConfig()                                                             CanIf_RxDHAdjust  /**< the pointer to CanIf_RxDHAdjust */
#define CanIf_GetRxIndicationFctListOfPCConfig()                                                    CanIf_RxIndicationFctList  /**< the pointer to CanIf_RxIndicationFctList */
#define CanIf_GetRxPduConfigOfPCConfig()                                                            CanIf_RxPduConfig  /**< the pointer to CanIf_RxPduConfig */
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                2u  /**< the number of accomplishable value elements in CanIf_CanIfCtrlId2MappedTxBuffersConfig */
#define CanIf_GetSizeOfCtrlConfigOfPCConfig()                                                       2u  /**< the number of accomplishable value elements in CanIf_CtrlConfig */
#define CanIf_GetSizeOfCtrlStatesOfPCConfig()                                                       2u  /**< the number of accomplishable value elements in CanIf_CtrlStates */
#define CanIf_GetSizeOfMailBoxConfigOfPCConfig()                                                    4u  /**< the number of accomplishable value elements in CanIf_MailBoxConfig */
#define CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()                                            2u  /**< the number of accomplishable value elements in CanIf_MappedTxBuffersConfig */
#define CanIf_GetSizeOfRxDHAdjustOfPCConfig()                                                       99u  /**< the number of accomplishable value elements in CanIf_RxDHAdjust */
#define CanIf_GetSizeOfRxIndicationFctListOfPCConfig()                                              5u  /**< the number of accomplishable value elements in CanIf_RxIndicationFctList */
#define CanIf_GetSizeOfRxPduConfigOfPCConfig()                                                      71u  /**< the number of accomplishable value elements in CanIf_RxPduConfig */
#define CanIf_GetSizeOfTrcvToCtrlMapOfPCConfig()                                                    1u  /**< the number of accomplishable value elements in CanIf_TrcvToCtrlMap */
#define CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()                                          2u  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdBase */
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig()                               2u  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdByteQueueConfig */
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()                         121u  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
#define CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()                                            4u  /**< the number of accomplishable value elements in CanIf_TxConfirmationFctList */
#define CanIf_GetSizeOfTxPduConfigOfPCConfig()                                                      121u  /**< the number of accomplishable value elements in CanIf_TxPduConfig */
#define CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()                                                  121u  /**< the number of accomplishable value elements in CanIf_TxPduQueueIndex */
#define CanIf_GetSizeOfTxQueueDataOfPCConfig()                                                      5547u  /**< the number of accomplishable value elements in CanIf_TxQueueData */
#define CanIf_GetSizeOfTxQueueIndex2DataStartStopOfPCConfig()                                       121u  /**< the number of accomplishable value elements in CanIf_TxQueueIndex2DataStartStop */
#define CanIf_GetSizeOfTxQueueOfPCConfig()                                                          121u  /**< the number of accomplishable value elements in CanIf_TxQueue */
#define CanIf_GetSizeOfWakeUpConfigOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in CanIf_WakeUpConfig */
#define CanIf_GetTrcvModeIndicationFctPtrOfPCConfig()                                               (&(CanIf_TrcvModeIndicationFctPtr))  /**< the pointer to CanIf_TrcvModeIndicationFctPtr */
#define CanIf_GetTrcvToCtrlMapOfPCConfig()                                                          CanIf_TrcvToCtrlMap  /**< the pointer to CanIf_TrcvToCtrlMap */
#define CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()                                                CanIf_TxBufferPrioByCanIdBase.raw  /**< the pointer to CanIf_TxBufferPrioByCanIdBase */
#define CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()                                     CanIf_TxBufferPrioByCanIdByteQueueConfig  /**< the pointer to CanIf_TxBufferPrioByCanIdByteQueueConfig */
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()                               CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus  /**< the pointer to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
#define CanIf_GetTxConfirmationFctListOfPCConfig()                                                  CanIf_TxConfirmationFctList  /**< the pointer to CanIf_TxConfirmationFctList */
#define CanIf_GetTxPduConfigOfPCConfig()                                                            CanIf_TxPduConfig  /**< the pointer to CanIf_TxPduConfig */
#define CanIf_GetTxPduQueueIndexOfPCConfig()                                                        CanIf_TxPduQueueIndex  /**< the pointer to CanIf_TxPduQueueIndex */
#define CanIf_GetTxQueueDataOfPCConfig()                                                            CanIf_TxQueueData.raw  /**< the pointer to CanIf_TxQueueData */
#define CanIf_GetTxQueueIndex2DataStartStopOfPCConfig()                                             CanIf_TxQueueIndex2DataStartStop  /**< the pointer to CanIf_TxQueueIndex2DataStartStop */
#define CanIf_GetTxQueueOfPCConfig()                                                                CanIf_TxQueue.raw  /**< the pointer to CanIf_TxQueue */
#define CanIf_GetWakeUpConfigOfPCConfig()                                                           CanIf_WakeUpConfig  /**< the pointer to CanIf_WakeUpConfig */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetDataMacros  CanIf Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanIf_GetBusOffNotificationFctPtr()                                                         ((*(CanIf_GetBusOffNotificationFctPtrOfPCConfig())))
#define CanIf_GetMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index)              (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index)            (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetRxDHRandomNumber1OfCtrlConfig(Index)                                               (CanIf_GetCtrlConfigOfPCConfig()[(Index)].RxDHRandomNumber1OfCtrlConfig)
#define CanIf_GetRxDHRandomNumber2OfCtrlConfig(Index)                                               (CanIf_GetCtrlConfigOfPCConfig()[(Index)].RxDHRandomNumber2OfCtrlConfig)
#define CanIf_GetCtrlModeIndicationFctPtr()                                                         ((*(CanIf_GetCtrlModeIndicationFctPtrOfPCConfig())))
#define CanIf_GetCtrlModeOfCtrlStates(Index)                                                        (CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates)
#define CanIf_GetPduModeOfCtrlStates(Index)                                                         (CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates)
#define CanIf_GetCtrlStatesIdxOfMailBoxConfig(Index)                                                (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].CtrlStatesIdxOfMailBoxConfig)
#define CanIf_GetMailBoxTypeOfMailBoxConfig(Index)                                                  (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].MailBoxTypeOfMailBoxConfig)
#define CanIf_GetPduIdFirstOfMailBoxConfig(Index)                                                   (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdFirstOfMailBoxConfig)
#define CanIf_GetPduIdLastOfMailBoxConfig(Index)                                                    (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdLastOfMailBoxConfig)
#define CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index)                                               (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferCfgIdxOfMailBoxConfig)
#define CanIf_GetTxBufferCfgOfMailBoxConfig(Index)                                                  (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferCfgOfMailBoxConfig)
#define CanIf_GetTxBufferHandlingTypeOfMailBoxConfig(Index)                                         (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferHandlingTypeOfMailBoxConfig)
#define CanIf_GetMailBoxConfigIdxOfMappedTxBuffersConfig(Index)                                     (CanIf_GetMappedTxBuffersConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfMappedTxBuffersConfig)
#define CanIf_GetRxDHAdjust(Index)                                                                  (CanIf_GetRxDHAdjustOfPCConfig()[(Index)])
#define CanIf_GetRxIndicationFctOfRxIndicationFctList(Index)                                        (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationFctOfRxIndicationFctList)
#define CanIf_GetRxIndicationLayoutOfRxIndicationFctList(Index)                                     (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationLayoutOfRxIndicationFctList)
#define CanIf_GetMsgTypeOfRxPduConfig(Index)                                                        (CanIf_GetRxPduConfigOfPCConfig()[(Index)].MsgTypeOfRxPduConfig)
#define CanIf_GetRxIndicationFctListIdxOfRxPduConfig(Index)                                         (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxIndicationFctListIdxOfRxPduConfig)
#define CanIf_GetRxPduCanIdOfRxPduConfig(Index)                                                     (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduCanIdOfRxPduConfig)
#define CanIf_GetRxPduDlcOfRxPduConfig(Index)                                                       (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduDlcOfRxPduConfig)
#define CanIf_GetRxPduMaskOfRxPduConfig(Index)                                                      (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduMaskOfRxPduConfig)
#define CanIf_GetUpperPduIdOfRxPduConfig(Index)                                                     (CanIf_GetRxPduConfigOfPCConfig()[(Index)].UpperPduIdOfRxPduConfig)
#define CanIf_GetTrcvModeIndicationFctPtr()                                                         ((*(CanIf_GetTrcvModeIndicationFctPtrOfPCConfig())))
#define CanIf_GetTrcvToCtrlMap(Index)                                                               (CanIf_GetTrcvToCtrlMapOfPCConfig()[(Index)])
#define CanIf_GetTxBufferPrioByCanIdBase(Index)                                                     (CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)])
#define CanIf_GetTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig(Index)              (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus(Index)                    (CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()[(Index)].TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus)
#define CanIf_GetTxConfirmationFctList(Index)                                                       (CanIf_GetTxConfirmationFctListOfPCConfig()[(Index)])
#define CanIf_GetCanIdOfTxPduConfig(Index)                                                          (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CanIdOfTxPduConfig)
#define CanIf_GetCtrlStatesIdxOfTxPduConfig(Index)                                                  (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CtrlStatesIdxOfTxPduConfig)
#define CanIf_IsIsTxPduTruncationOfTxPduConfig(Index)                                               ((CanIf_GetTxPduConfigOfPCConfig()[(Index)].IsTxPduTruncationOfTxPduConfig) != FALSE)
#define CanIf_GetMailBoxConfigIdxOfTxPduConfig(Index)                                               (CanIf_GetTxPduConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfTxPduConfig)
#define CanIf_GetTxConfirmationFctListIdxOfTxPduConfig(Index)                                       (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxConfirmationFctListIdxOfTxPduConfig)
#define CanIf_GetTxPduLengthOfTxPduConfig(Index)                                                    (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxPduLengthOfTxPduConfig)
#define CanIf_GetUpperLayerTxPduIdOfTxPduConfig(Index)                                              (CanIf_GetTxPduConfigOfPCConfig()[(Index)].UpperLayerTxPduIdOfTxPduConfig)
#define CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index)                                                 (CanIf_GetTxPduQueueIndexOfPCConfig()[(Index)].TxQueueIdxOfTxPduQueueIndex)
#define CanIf_GetTxQueueIndex2DataStartStopIdxOfTxPduQueueIndex(Index)                              (CanIf_GetTxPduQueueIndexOfPCConfig()[(Index)].TxQueueIndex2DataStartStopIdxOfTxPduQueueIndex)
#define CanIf_GetTxQueueOfTxPduQueueIndex(Index)                                                    (CanIf_GetTxPduQueueIndexOfPCConfig()[(Index)].TxQueueOfTxPduQueueIndex)
#define CanIf_GetTxQueue(Index)                                                                     (CanIf_GetTxQueueOfPCConfig()[(Index)])
#define CanIf_GetTxQueueData(Index)                                                                 (CanIf_GetTxQueueDataOfPCConfig()[(Index)])
#define CanIf_GetTxQueueDataEndIdxOfTxQueueIndex2DataStartStop(Index)                               (CanIf_GetTxQueueIndex2DataStartStopOfPCConfig()[(Index)].TxQueueDataEndIdxOfTxQueueIndex2DataStartStop)
#define CanIf_GetTxQueueDataLengthOfTxQueueIndex2DataStartStop(Index)                               (CanIf_GetTxQueueIndex2DataStartStopOfPCConfig()[(Index)].TxQueueDataLengthOfTxQueueIndex2DataStartStop)
#define CanIf_GetTxQueueDataStartIdxOfTxQueueIndex2DataStartStop(Index)                             (CanIf_GetTxQueueIndex2DataStartStopOfPCConfig()[(Index)].TxQueueDataStartIdxOfTxQueueIndex2DataStartStop)
#define CanIf_GetControllerIdOfWakeUpConfig(Index)                                                  (CanIf_GetWakeUpConfigOfPCConfig()[(Index)].ControllerIdOfWakeUpConfig)
#define CanIf_GetWakeUpSourceOfWakeUpConfig(Index)                                                  ((EcuM_WakeupSourceType)CanIf_GetWakeUpConfigOfPCConfig()[(Index)].WakeUpSourceOfWakeUpConfig)
#define CanIf_GetWakeUpTargetAddressOfWakeUpConfig(Index)                                           (CanIf_GetWakeUpConfigOfPCConfig()[(Index)].WakeUpTargetAddressOfWakeUpConfig)
#define CanIf_GetWakeUpTargetModuleOfWakeUpConfig(Index)                                            (CanIf_GetWakeUpConfigOfPCConfig()[(Index)].WakeUpTargetModuleOfWakeUpConfig)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetDeduplicatedDataMacros  CanIf Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanIf_GetGeneratorCompatibilityVersion()                                                    CanIf_GetGeneratorCompatibilityVersionOfPCConfig()
#define CanIf_GetGeneratorVersion()                                                                 CanIf_GetGeneratorVersionOfPCConfig()
#define CanIf_IsTxBufferCfgUsedOfMailBoxConfig(Index)                                               (((boolean)(CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index) != CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig */
#define CanIf_GetMaxTrcvHandleIdPlusOne()                                                           CanIf_GetMaxTrcvHandleIdPlusOneOfPCConfig()
#define CanIf_GetMaxWakeUpSources()                                                                 CanIf_GetMaxWakeUpSourcesOfPCConfig()
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfig()                                          CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfCtrlConfig()                                                                 CanIf_GetSizeOfCtrlConfigOfPCConfig()
#define CanIf_GetSizeOfCtrlStates()                                                                 CanIf_GetSizeOfCtrlStatesOfPCConfig()
#define CanIf_GetSizeOfMailBoxConfig()                                                              CanIf_GetSizeOfMailBoxConfigOfPCConfig()
#define CanIf_GetSizeOfMappedTxBuffersConfig()                                                      CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfRxDHAdjust()                                                                 CanIf_GetSizeOfRxDHAdjustOfPCConfig()
#define CanIf_GetSizeOfRxIndicationFctList()                                                        CanIf_GetSizeOfRxIndicationFctListOfPCConfig()
#define CanIf_GetSizeOfRxPduConfig()                                                                CanIf_GetSizeOfRxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTrcvToCtrlMap()                                                              CanIf_GetSizeOfTrcvToCtrlMapOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdBase()                                                    CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfig()                                         CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus()                                   CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()
#define CanIf_GetSizeOfTxConfirmationFctList()                                                      CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()
#define CanIf_GetSizeOfTxPduConfig()                                                                CanIf_GetSizeOfTxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTxPduQueueIndex()                                                            CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()
#define CanIf_GetSizeOfTxQueue()                                                                    CanIf_GetSizeOfTxQueueOfPCConfig()
#define CanIf_GetSizeOfTxQueueData()                                                                CanIf_GetSizeOfTxQueueDataOfPCConfig()
#define CanIf_GetSizeOfTxQueueIndex2DataStartStop()                                                 CanIf_GetSizeOfTxQueueIndex2DataStartStopOfPCConfig()
#define CanIf_GetSizeOfWakeUpConfig()                                                               CanIf_GetSizeOfWakeUpConfigOfPCConfig()
#define CanIf_IsTxQueueIndex2DataStartStopUsedOfTxPduQueueIndex(Index)                              (((boolean)(CanIf_GetTxQueueIndex2DataStartStopIdxOfTxPduQueueIndex(Index) != CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxQueueIndex2DataStartStop */
#define CanIf_IsTxQueueUsedOfTxPduQueueIndex(Index)                                                 (((boolean)(CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index) != CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxQueue */
#define CanIf_IsTxQueueDataUsedOfTxQueueIndex2DataStartStop(Index)                                  (((boolean)(CanIf_GetTxQueueDataLengthOfTxQueueIndex2DataStartStop(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanIf_TxQueueData */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSetDataMacros  CanIf Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanIf_SetCtrlModeOfCtrlStates(Index, Value)                                                 CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates = (Value)
#define CanIf_SetPduModeOfCtrlStates(Index, Value)                                                  CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates = (Value)
#define CanIf_SetTxBufferPrioByCanIdBase(Index, Value)                                              CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxQueue(Index, Value)                                                              CanIf_GetTxQueueOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxQueueData(Index, Value)                                                          CanIf_GetTxQueueDataOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetAddressOfDataMacros  CanIf Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define CanIf_GetAddrTxQueueData(Index)                                                             (&CanIf_GetTxQueueData(Index))
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCHasMacros  CanIf Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanIf_HasBusOffNotificationFctPtr()                                                         (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfig()                                                (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig()                   (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig()                 (TRUE != FALSE)
#define CanIf_HasCtrlConfig()                                                                       (TRUE != FALSE)
#define CanIf_HasRxDHRandomNumber1OfCtrlConfig()                                                    (TRUE != FALSE)
#define CanIf_HasRxDHRandomNumber2OfCtrlConfig()                                                    (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtr()                                                         (TRUE != FALSE)
#define CanIf_HasCtrlStates()                                                                       (TRUE != FALSE)
#define CanIf_HasCtrlModeOfCtrlStates()                                                             (TRUE != FALSE)
#define CanIf_HasPduModeOfCtrlStates()                                                              (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersion()                                                    (TRUE != FALSE)
#define CanIf_HasGeneratorVersion()                                                                 (TRUE != FALSE)
#define CanIf_HasMailBoxConfig()                                                                    (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfMailBoxConfig()                                                     (TRUE != FALSE)
#define CanIf_HasMailBoxTypeOfMailBoxConfig()                                                       (TRUE != FALSE)
#define CanIf_HasPduIdFirstOfMailBoxConfig()                                                        (TRUE != FALSE)
#define CanIf_HasPduIdLastOfMailBoxConfig()                                                         (TRUE != FALSE)
#define CanIf_HasTxBufferCfgIdxOfMailBoxConfig()                                                    (TRUE != FALSE)
#define CanIf_HasTxBufferCfgOfMailBoxConfig()                                                       (TRUE != FALSE)
#define CanIf_HasTxBufferCfgUsedOfMailBoxConfig()                                                   (TRUE != FALSE)
#define CanIf_HasTxBufferHandlingTypeOfMailBoxConfig()                                              (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfig()                                                            (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfMappedTxBuffersConfig()                                          (TRUE != FALSE)
#define CanIf_HasMaxTrcvHandleIdPlusOne()                                                           (TRUE != FALSE)
#define CanIf_HasMaxWakeUpSources()                                                                 (TRUE != FALSE)
#define CanIf_HasRxDHAdjust()                                                                       (TRUE != FALSE)
#define CanIf_HasRxIndicationFctList()                                                              (TRUE != FALSE)
#define CanIf_HasRxIndicationFctOfRxIndicationFctList()                                             (TRUE != FALSE)
#define CanIf_HasRxIndicationLayoutOfRxIndicationFctList()                                          (TRUE != FALSE)
#define CanIf_HasRxPduConfig()                                                                      (TRUE != FALSE)
#define CanIf_HasMsgTypeOfRxPduConfig()                                                             (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListIdxOfRxPduConfig()                                              (TRUE != FALSE)
#define CanIf_HasRxPduCanIdOfRxPduConfig()                                                          (TRUE != FALSE)
#define CanIf_HasRxPduDlcOfRxPduConfig()                                                            (TRUE != FALSE)
#define CanIf_HasRxPduMaskOfRxPduConfig()                                                           (TRUE != FALSE)
#define CanIf_HasUpperPduIdOfRxPduConfig()                                                          (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfig()                                          (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlConfig()                                                                 (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStates()                                                                 (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfig()                                                              (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfig()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfRxDHAdjust()                                                                 (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctList()                                                        (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfig()                                                                (TRUE != FALSE)
#define CanIf_HasSizeOfTrcvToCtrlMap()                                                              (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBase()                                                    (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueConfig()                                         (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus()                                   (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctList()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfig()                                                                (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndex()                                                            (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueue()                                                                    (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueData()                                                                (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueIndex2DataStartStop()                                                 (TRUE != FALSE)
#define CanIf_HasSizeOfWakeUpConfig()                                                               (TRUE != FALSE)
#define CanIf_HasTrcvModeIndicationFctPtr()                                                         (TRUE != FALSE)
#define CanIf_HasTrcvToCtrlMap()                                                                    (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBase()                                                          (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueConfig()                                               (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig()                   (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdus()                                         (TRUE != FALSE)
#define CanIf_HasTxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus()                         (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctList()                                                            (TRUE != FALSE)
#define CanIf_HasTxPduConfig()                                                                      (TRUE != FALSE)
#define CanIf_HasCanIdOfTxPduConfig()                                                               (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfTxPduConfig()                                                       (TRUE != FALSE)
#define CanIf_HasIsTxPduTruncationOfTxPduConfig()                                                   (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfTxPduConfig()                                                    (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListIdxOfTxPduConfig()                                            (TRUE != FALSE)
#define CanIf_HasTxPduLengthOfTxPduConfig()                                                         (TRUE != FALSE)
#define CanIf_HasUpperLayerTxPduIdOfTxPduConfig()                                                   (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndex()                                                                  (TRUE != FALSE)
#define CanIf_HasTxQueueIdxOfTxPduQueueIndex()                                                      (TRUE != FALSE)
#define CanIf_HasTxQueueIndex2DataStartStopIdxOfTxPduQueueIndex()                                   (TRUE != FALSE)
#define CanIf_HasTxQueueIndex2DataStartStopUsedOfTxPduQueueIndex()                                  (TRUE != FALSE)
#define CanIf_HasTxQueueOfTxPduQueueIndex()                                                         (TRUE != FALSE)
#define CanIf_HasTxQueueUsedOfTxPduQueueIndex()                                                     (TRUE != FALSE)
#define CanIf_HasTxQueue()                                                                          (TRUE != FALSE)
#define CanIf_HasTxQueueData()                                                                      (TRUE != FALSE)
#define CanIf_HasTxQueueIndex2DataStartStop()                                                       (TRUE != FALSE)
#define CanIf_HasTxQueueDataEndIdxOfTxQueueIndex2DataStartStop()                                    (TRUE != FALSE)
#define CanIf_HasTxQueueDataLengthOfTxQueueIndex2DataStartStop()                                    (TRUE != FALSE)
#define CanIf_HasTxQueueDataStartIdxOfTxQueueIndex2DataStartStop()                                  (TRUE != FALSE)
#define CanIf_HasTxQueueDataUsedOfTxQueueIndex2DataStartStop()                                      (TRUE != FALSE)
#define CanIf_HasWakeUpConfig()                                                                     (TRUE != FALSE)
#define CanIf_HasControllerIdOfWakeUpConfig()                                                       (TRUE != FALSE)
#define CanIf_HasWakeUpSourceOfWakeUpConfig()                                                       (TRUE != FALSE)
#define CanIf_HasWakeUpTargetAddressOfWakeUpConfig()                                                (TRUE != FALSE)
#define CanIf_HasWakeUpTargetModuleOfWakeUpConfig()                                                 (TRUE != FALSE)
#define CanIf_HasPCConfig()                                                                         (TRUE != FALSE)
#define CanIf_HasBusOffNotificationFctPtrOfPCConfig()                                               (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                      (TRUE != FALSE)
#define CanIf_HasCtrlConfigOfPCConfig()                                                             (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtrOfPCConfig()                                               (TRUE != FALSE)
#define CanIf_HasCtrlStatesOfPCConfig()                                                             (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersionOfPCConfig()                                          (TRUE != FALSE)
#define CanIf_HasGeneratorVersionOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasMailBoxConfigOfPCConfig()                                                          (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasMaxTrcvHandleIdPlusOneOfPCConfig()                                                 (TRUE != FALSE)
#define CanIf_HasMaxWakeUpSourcesOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasRxDHAdjustOfPCConfig()                                                             (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListOfPCConfig()                                                    (TRUE != FALSE)
#define CanIf_HasRxPduConfigOfPCConfig()                                                            (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlConfigOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStatesOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfigOfPCConfig()                                                    (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfigOfPCConfig()                                            (TRUE != FALSE)
#define CanIf_HasSizeOfRxDHAdjustOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctListOfPCConfig()                                              (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfigOfPCConfig()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTrcvToCtrlMapOfPCConfig()                                                    (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBaseOfPCConfig()                                          (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig()                               (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctListOfPCConfig()                                            (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfigOfPCConfig()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndexOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueDataOfPCConfig()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueIndex2DataStartStopOfPCConfig()                                       (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueOfPCConfig()                                                          (TRUE != FALSE)
#define CanIf_HasSizeOfWakeUpConfigOfPCConfig()                                                     (TRUE != FALSE)
#define CanIf_HasTrcvModeIndicationFctPtrOfPCConfig()                                               (TRUE != FALSE)
#define CanIf_HasTrcvToCtrlMapOfPCConfig()                                                          (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseOfPCConfig()                                                (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueConfigOfPCConfig()                                     (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()                               (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasTxPduConfigOfPCConfig()                                                            (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndexOfPCConfig()                                                        (TRUE != FALSE)
#define CanIf_HasTxQueueDataOfPCConfig()                                                            (TRUE != FALSE)
#define CanIf_HasTxQueueIndex2DataStartStopOfPCConfig()                                             (TRUE != FALSE)
#define CanIf_HasTxQueueOfPCConfig()                                                                (TRUE != FALSE)
#define CanIf_HasWakeUpConfigOfPCConfig()                                                           (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIncrementDataMacros  CanIf Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanIf_IncCtrlModeOfCtrlStates(Index)                                                        CanIf_GetCtrlModeOfCtrlStates(Index)++
#define CanIf_IncPduModeOfCtrlStates(Index)                                                         CanIf_GetPduModeOfCtrlStates(Index)++
#define CanIf_IncTxBufferPrioByCanIdBase(Index)                                                     CanIf_GetTxBufferPrioByCanIdBase(Index)++
#define CanIf_IncTxQueue(Index)                                                                     CanIf_GetTxQueue(Index)++
#define CanIf_IncTxQueueData(Index)                                                                 CanIf_GetTxQueueData(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCDecrementDataMacros  CanIf Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanIf_DecCtrlModeOfCtrlStates(Index)                                                        CanIf_GetCtrlModeOfCtrlStates(Index)--
#define CanIf_DecPduModeOfCtrlStates(Index)                                                         CanIf_GetPduModeOfCtrlStates(Index)--
#define CanIf_DecTxBufferPrioByCanIdBase(Index)                                                     CanIf_GetTxBufferPrioByCanIdBase(Index)--
#define CanIf_DecTxQueue(Index)                                                                     CanIf_GetTxQueue(Index)--
#define CanIf_DecTxQueueData(Index)                                                                 CanIf_GetTxQueueData(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCAddDataMacros  CanIf Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define CanIf_AddCtrlModeOfCtrlStates(Index, Value)                                                 CanIf_SetCtrlModeOfCtrlStates(Index, (CanIf_GetCtrlModeOfCtrlStates(Index) + Value))
#define CanIf_AddPduModeOfCtrlStates(Index, Value)                                                  CanIf_SetPduModeOfCtrlStates(Index, (CanIf_GetPduModeOfCtrlStates(Index) + Value))
#define CanIf_AddTxBufferPrioByCanIdBase(Index, Value)                                              CanIf_SetTxBufferPrioByCanIdBase(Index, (CanIf_GetTxBufferPrioByCanIdBase(Index) + Value))
#define CanIf_AddTxQueue(Index, Value)                                                              CanIf_SetTxQueue(Index, (CanIf_GetTxQueue(Index) + Value))
#define CanIf_AddTxQueueData(Index, Value)                                                          CanIf_SetTxQueueData(Index, (CanIf_GetTxQueueData(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSubstractDataMacros  CanIf Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define CanIf_SubCtrlModeOfCtrlStates(Index, Value)                                                 CanIf_SetCtrlModeOfCtrlStates(Index, (CanIf_GetCtrlModeOfCtrlStates(Index) - Value))
#define CanIf_SubPduModeOfCtrlStates(Index, Value)                                                  CanIf_SetPduModeOfCtrlStates(Index, (CanIf_GetPduModeOfCtrlStates(Index) - Value))
#define CanIf_SubTxBufferPrioByCanIdBase(Index, Value)                                              CanIf_SetTxBufferPrioByCanIdBase(Index, (CanIf_GetTxBufferPrioByCanIdBase(Index) - Value))
#define CanIf_SubTxQueue(Index, Value)                                                              CanIf_SetTxQueue(Index, (CanIf_GetTxQueue(Index) - Value))
#define CanIf_SubTxQueueData(Index, Value)                                                          CanIf_SetTxQueueData(Index, (CanIf_GetTxQueueData(Index) - Value))
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCIterableTypes  CanIf Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef uint8_least CanIf_CanIfCtrlId2MappedTxBuffersConfigIterType;

/**   \brief  type used to iterate CanIf_CtrlConfig */
typedef uint8_least CanIf_CtrlConfigIterType;

/**   \brief  type used to iterate CanIf_CtrlStates */
typedef uint8_least CanIf_CtrlStatesIterType;

/**   \brief  type used to iterate CanIf_MailBoxConfig */
typedef uint8_least CanIf_MailBoxConfigIterType;

/**   \brief  type used to iterate CanIf_MappedTxBuffersConfig */
typedef uint8_least CanIf_MappedTxBuffersConfigIterType;

/**   \brief  type used to iterate CanIf_RxDHAdjust */
typedef uint8_least CanIf_RxDHAdjustIterType;

/**   \brief  type used to iterate CanIf_RxIndicationFctList */
typedef uint8_least CanIf_RxIndicationFctListIterType;

/**   \brief  type used to iterate CanIf_RxPduConfig */
typedef uint8_least CanIf_RxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TrcvToCtrlMap */
typedef uint8_least CanIf_TrcvToCtrlMapIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdBase */
typedef uint8_least CanIf_TxBufferPrioByCanIdBaseIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdByteQueueConfig */
typedef uint8_least CanIf_TxBufferPrioByCanIdByteQueueConfigIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef uint8_least CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusIterType;

/**   \brief  type used to iterate CanIf_TxConfirmationFctList */
typedef uint8_least CanIf_TxConfirmationFctListIterType;

/**   \brief  type used to iterate CanIf_TxPduConfig */
typedef uint8_least CanIf_TxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TxPduQueueIndex */
typedef uint8_least CanIf_TxPduQueueIndexIterType;

/**   \brief  type used to iterate CanIf_TxQueue */
typedef uint8_least CanIf_TxQueueIterType;

/**   \brief  type used to iterate CanIf_TxQueueData */
typedef uint16_least CanIf_TxQueueDataIterType;

/**   \brief  type used to iterate CanIf_TxQueueIndex2DataStartStop */
typedef uint8_least CanIf_TxQueueIndex2DataStartStopIterType;

/**   \brief  type used to iterate CanIf_WakeUpConfig */
typedef uint8_least CanIf_WakeUpConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCValueTypes  CanIf Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_RxDHRandomNumber1OfCtrlConfig */
typedef uint32 CanIf_RxDHRandomNumber1OfCtrlConfigType;

/**   \brief  value based type definition for CanIf_RxDHRandomNumber2OfCtrlConfig */
typedef uint32 CanIf_RxDHRandomNumber2OfCtrlConfigType;

/**   \brief  value based type definition for CanIf_GeneratorCompatibilityVersion */
typedef uint16 CanIf_GeneratorCompatibilityVersionType;

/**   \brief  value based type definition for CanIf_GeneratorVersion */
typedef uint32 CanIf_GeneratorVersionType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfMailBoxConfig */
typedef uint8 CanIf_CtrlStatesIdxOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_PduIdFirstOfMailBoxConfig */
typedef uint8 CanIf_PduIdFirstOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_PduIdLastOfMailBoxConfig */
typedef uint8 CanIf_PduIdLastOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgIdxOfMailBoxConfig */
typedef uint8 CanIf_TxBufferCfgIdxOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgOfMailBoxConfig */
typedef uint8 CanIf_TxBufferCfgOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgUsedOfMailBoxConfig */
typedef boolean CanIf_TxBufferCfgUsedOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferHandlingTypeOfMailBoxConfig */
typedef uint8 CanIf_TxBufferHandlingTypeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_MailBoxConfigIdxOfMappedTxBuffersConfig */
typedef uint8 CanIf_MailBoxConfigIdxOfMappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_MaxTrcvHandleIdPlusOne */
typedef uint8 CanIf_MaxTrcvHandleIdPlusOneType;

/**   \brief  value based type definition for CanIf_MaxWakeUpSources */
typedef uint8 CanIf_MaxWakeUpSourcesType;

/**   \brief  value based type definition for CanIf_RxDHAdjust */
typedef uint8 CanIf_RxDHAdjustType;

/**   \brief  value based type definition for CanIf_RxIndicationFctListIdxOfRxPduConfig */
typedef uint8 CanIf_RxIndicationFctListIdxOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduCanIdOfRxPduConfig */
typedef uint32 CanIf_RxPduCanIdOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduDlcOfRxPduConfig */
typedef uint8 CanIf_RxPduDlcOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduMaskOfRxPduConfig */
typedef uint32 CanIf_RxPduMaskOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_UpperPduIdOfRxPduConfig */
typedef PduIdType CanIf_UpperPduIdOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCtrlConfig */
typedef uint8 CanIf_SizeOfCtrlConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCtrlStates */
typedef uint8 CanIf_SizeOfCtrlStatesType;

/**   \brief  value based type definition for CanIf_SizeOfMailBoxConfig */
typedef uint8 CanIf_SizeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_SizeOfMappedTxBuffersConfig */
typedef uint8 CanIf_SizeOfMappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_SizeOfRxDHAdjust */
typedef uint8 CanIf_SizeOfRxDHAdjustType;

/**   \brief  value based type definition for CanIf_SizeOfRxIndicationFctList */
typedef uint8 CanIf_SizeOfRxIndicationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfRxPduConfig */
typedef uint8 CanIf_SizeOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTrcvToCtrlMap */
typedef uint8 CanIf_SizeOfTrcvToCtrlMapType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdBase */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdBaseType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusType;

/**   \brief  value based type definition for CanIf_SizeOfTxConfirmationFctList */
typedef uint8 CanIf_SizeOfTxConfirmationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduConfig */
typedef uint8 CanIf_SizeOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduQueueIndex */
typedef uint8 CanIf_SizeOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueue */
typedef uint8 CanIf_SizeOfTxQueueType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueueData */
typedef uint16 CanIf_SizeOfTxQueueDataType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueueIndex2DataStartStop */
typedef uint8 CanIf_SizeOfTxQueueIndex2DataStartStopType;

/**   \brief  value based type definition for CanIf_SizeOfWakeUpConfig */
typedef uint8 CanIf_SizeOfWakeUpConfigType;

/**   \brief  value based type definition for CanIf_TrcvToCtrlMap */
typedef uint8 CanIf_TrcvToCtrlMapType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef uint8 CanIf_TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdusType;

/**   \brief  value based type definition for CanIf_CanIdOfTxPduConfig */
typedef uint32 CanIf_CanIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfTxPduConfig */
typedef uint8 CanIf_CtrlStatesIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_IsTxPduTruncationOfTxPduConfig */
typedef boolean CanIf_IsTxPduTruncationOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_MailBoxConfigIdxOfTxPduConfig */
typedef uint8 CanIf_MailBoxConfigIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxConfirmationFctListIdxOfTxPduConfig */
typedef uint8 CanIf_TxConfirmationFctListIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxPduLengthOfTxPduConfig */
typedef uint8 CanIf_TxPduLengthOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_UpperLayerTxPduIdOfTxPduConfig */
typedef PduIdType CanIf_UpperLayerTxPduIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxQueueIdxOfTxPduQueueIndex */
typedef uint8 CanIf_TxQueueIdxOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueIndex2DataStartStopIdxOfTxPduQueueIndex */
typedef uint8 CanIf_TxQueueIndex2DataStartStopIdxOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueIndex2DataStartStopUsedOfTxPduQueueIndex */
typedef boolean CanIf_TxQueueIndex2DataStartStopUsedOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueOfTxPduQueueIndex */
typedef uint8 CanIf_TxQueueOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueUsedOfTxPduQueueIndex */
typedef boolean CanIf_TxQueueUsedOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueData */
typedef uint8 CanIf_TxQueueDataType;

/**   \brief  value based type definition for CanIf_TxQueueDataEndIdxOfTxQueueIndex2DataStartStop */
typedef uint16 CanIf_TxQueueDataEndIdxOfTxQueueIndex2DataStartStopType;

/**   \brief  value based type definition for CanIf_TxQueueDataLengthOfTxQueueIndex2DataStartStop */
typedef uint8 CanIf_TxQueueDataLengthOfTxQueueIndex2DataStartStopType;

/**   \brief  value based type definition for CanIf_TxQueueDataStartIdxOfTxQueueIndex2DataStartStop */
typedef uint16 CanIf_TxQueueDataStartIdxOfTxQueueIndex2DataStartStopType;

/**   \brief  value based type definition for CanIf_TxQueueDataUsedOfTxQueueIndex2DataStartStop */
typedef boolean CanIf_TxQueueDataUsedOfTxQueueIndex2DataStartStopType;

/**   \brief  value based type definition for CanIf_ControllerIdOfWakeUpConfig */
typedef uint8 CanIf_ControllerIdOfWakeUpConfigType;

/**   \brief  value based type definition for CanIf_WakeUpSourceOfWakeUpConfig */
typedef uint8 CanIf_WakeUpSourceOfWakeUpConfigType;

/**   \brief  value based type definition for CanIf_WakeUpTargetAddressOfWakeUpConfig */
typedef uint8 CanIf_WakeUpTargetAddressOfWakeUpConfigType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCStructTypes  CanIf Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanIf_CanIfCtrlId2MappedTxBuffersConfig */
/*! \spec weak type invariant () { 
 * (self.MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig < CanIf_GetSizeOfMappedTxBuffersConfig()) &&
 * (self.MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig < CanIf_GetSizeOfMappedTxBuffersConfig())
 * } */
typedef struct sCanIf_CanIfCtrlId2MappedTxBuffersConfigType
{
  CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfigType MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig;  /**< the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig */
  CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfigType MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig;  /**< the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig */
} CanIf_CanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  type used in CanIf_CtrlConfig */
typedef struct sCanIf_CtrlConfigType
{
  CanIf_RxDHRandomNumber1OfCtrlConfigType RxDHRandomNumber1OfCtrlConfig;  /**< Rx - DoubleHash - 1st random number. */
  CanIf_RxDHRandomNumber2OfCtrlConfigType RxDHRandomNumber2OfCtrlConfig;  /**< Rx - DoubleHash - 2nd random number. */
} CanIf_CtrlConfigType;

/**   \brief  type used in CanIf_CtrlStates */
typedef struct sCanIf_CtrlStatesType
{
  CanIf_ControllerModeType CtrlModeOfCtrlStates;  /**< Controller mode. */
  CanIf_PduGetModeType PduModeOfCtrlStates;  /**< PDU mode state. */
} CanIf_CtrlStatesType;

/**   \brief  type used in CanIf_MailBoxConfig */
/*! \spec weak type invariant () { 
 * (self.CtrlStatesIdxOfMailBoxConfig < CanIf_GetSizeOfCtrlStates()) &&
 * (!((self.TxBufferCfgIdxOfMailBoxConfig != CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG)) || ((( self.TxBufferCfgOfMailBoxConfig == CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG_TXBUFFERCFGOFMAILBOXCONFIG) && (self.TxBufferCfgIdxOfMailBoxConfig < CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfig()))))
 * } */
typedef struct sCanIf_MailBoxConfigType
{
  CanIf_CtrlStatesIdxOfMailBoxConfigType CtrlStatesIdxOfMailBoxConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_PduIdFirstOfMailBoxConfigType PduIdFirstOfMailBoxConfig;  /**< "First" PDU mapped to mailbox. */
  CanIf_PduIdLastOfMailBoxConfigType PduIdLastOfMailBoxConfig;  /**< "Last" PDU mapped to mailbox. */
  CanIf_TxBufferCfgOfMailBoxConfigType TxBufferCfgOfMailBoxConfig;
  CanIf_TxBufferCfgIdxOfMailBoxConfigType TxBufferCfgIdxOfMailBoxConfig;  /**< the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig */
  CanIf_TxBufferHandlingTypeOfMailBoxConfigType TxBufferHandlingTypeOfMailBoxConfig;
  CanIf_MailBoxTypeType MailBoxTypeOfMailBoxConfig;  /**< Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused. */
} CanIf_MailBoxConfigType;

/**   \brief  type used in CanIf_MappedTxBuffersConfig */
/*! \spec weak type invariant () { 
 * (self.MailBoxConfigIdxOfMappedTxBuffersConfig < CanIf_GetSizeOfMailBoxConfig())
 * } */
typedef struct sCanIf_MappedTxBuffersConfigType
{
  CanIf_MailBoxConfigIdxOfMappedTxBuffersConfigType MailBoxConfigIdxOfMappedTxBuffersConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
} CanIf_MappedTxBuffersConfigType;

/**   \brief  type used in CanIf_RxIndicationFctList */
typedef struct sCanIf_RxIndicationFctListType
{
  CanIf_RxIndicationFctType RxIndicationFctOfRxIndicationFctList;  /**< Rx indication function. */
  CanIf_RxIndicationLayoutType RxIndicationLayoutOfRxIndicationFctList;  /**< Layout of Rx indication function. */
} CanIf_RxIndicationFctListType;

/**   \brief  type used in CanIf_RxPduConfig */
/*! \spec weak type invariant () { 
 * (self.RxIndicationFctListIdxOfRxPduConfig < CanIf_GetSizeOfRxIndicationFctList())
 * } */
typedef struct sCanIf_RxPduConfigType
{
  CanIf_RxPduCanIdOfRxPduConfigType RxPduCanIdOfRxPduConfig;  /**< Rx-PDU: CAN identifier. */
  CanIf_RxPduMaskOfRxPduConfigType RxPduMaskOfRxPduConfig;  /**< Rx-PDU: CAN identifier mask. */
  CanIf_UpperPduIdOfRxPduConfigType UpperPduIdOfRxPduConfig;  /**< PDU ID defined by upper layer. */
  CanIf_RxIndicationFctListIdxOfRxPduConfigType RxIndicationFctListIdxOfRxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_RxIndicationFctList */
  CanIf_RxPduDlcOfRxPduConfigType RxPduDlcOfRxPduConfig;  /**< Rx-PDU length (DLC). */
  CanIf_MsgType MsgTypeOfRxPduConfig;  /**< Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0). */
} CanIf_RxPduConfigType;

/**   \brief  type used in CanIf_TxBufferPrioByCanIdByteQueueConfig */
/*! \spec weak type invariant () { 
 * (self.TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig < CanIf_GetSizeOfTxBufferPrioByCanIdBase()) &&
 * (self.TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig < CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus()) &&
 * (self.TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig < CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus())
 * } */
typedef struct sCanIf_TxBufferPrioByCanIdByteQueueConfigType
{
  CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase */
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig;  /**< the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig;  /**< the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig;  /**< the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
} CanIf_TxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  type used in CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
/*! \spec weak type invariant () { 
 * (self.TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus < CanIf_GetSizeOfTxPduConfig())
 * } */
typedef struct sCanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType
{
  CanIf_TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdusType TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus;  /**< the index of the 1:1 relation pointing to CanIf_TxPduConfig */
} CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType;

/**   \brief  type used in CanIf_TxPduConfig */
/*! \spec weak type invariant () { 
 * (self.CtrlStatesIdxOfTxPduConfig < CanIf_GetSizeOfCtrlStates()) &&
 * (self.MailBoxConfigIdxOfTxPduConfig < CanIf_GetSizeOfMailBoxConfig()) &&
 * (self.TxConfirmationFctListIdxOfTxPduConfig < CanIf_GetSizeOfTxConfirmationFctList())
 * } */
typedef struct sCanIf_TxPduConfigType
{
  CanIf_CanIdOfTxPduConfigType CanIdOfTxPduConfig;  /**< CAN identifier (16bit / 32bit). */
  CanIf_UpperLayerTxPduIdOfTxPduConfigType UpperLayerTxPduIdOfTxPduConfig;  /**< Upper layer handle-Id (8bit / 16bit). */
  CanIf_IsTxPduTruncationOfTxPduConfigType IsTxPduTruncationOfTxPduConfig;  /**< TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled */
  CanIf_CtrlStatesIdxOfTxPduConfigType CtrlStatesIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_MailBoxConfigIdxOfTxPduConfigType MailBoxConfigIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
  CanIf_TxConfirmationFctListIdxOfTxPduConfigType TxConfirmationFctListIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList */
  CanIf_TxPduLengthOfTxPduConfigType TxPduLengthOfTxPduConfig;  /**< Tx-PDU length. */
} CanIf_TxPduConfigType;

/**   \brief  type used in CanIf_TxPduQueueIndex */
/*! \spec weak type invariant () { 
 * (!((self.TxQueueIdxOfTxPduQueueIndex != CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX)) || ((( self.TxQueueOfTxPduQueueIndex == CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX) && (self.TxQueueIdxOfTxPduQueueIndex < CanIf_GetSizeOfTxQueue())))) &&
 * (!((self.TxQueueIndex2DataStartStopIdxOfTxPduQueueIndex != CANIF_NO_TXQUEUEINDEX2DATASTARTSTOPIDXOFTXPDUQUEUEINDEX)) || (self.TxQueueIndex2DataStartStopIdxOfTxPduQueueIndex < CanIf_GetSizeOfTxQueueIndex2DataStartStop()))
 * } */
typedef struct sCanIf_TxPduQueueIndexType
{
  CanIf_TxQueueOfTxPduQueueIndexType TxQueueOfTxPduQueueIndex;
  CanIf_TxQueueIdxOfTxPduQueueIndexType TxQueueIdxOfTxPduQueueIndex;  /**< the index of the 0:1 relation pointing to CanIf_TxQueue */
  CanIf_TxQueueIndex2DataStartStopIdxOfTxPduQueueIndexType TxQueueIndex2DataStartStopIdxOfTxPduQueueIndex;  /**< the index of the 0:1 relation pointing to CanIf_TxQueueIndex2DataStartStop */
} CanIf_TxPduQueueIndexType;

/**   \brief  type used in CanIf_TxQueueIndex2DataStartStop */
/*! \spec weak type invariant () { 
 * (!((self.TxQueueDataLengthOfTxQueueIndex2DataStartStop != 0u)) || (self.TxQueueDataStartIdxOfTxQueueIndex2DataStartStop < CanIf_GetSizeOfTxQueueData())) &&
 * (!((self.TxQueueDataLengthOfTxQueueIndex2DataStartStop != 0u)) || (self.TxQueueDataEndIdxOfTxQueueIndex2DataStartStop < CanIf_GetSizeOfTxQueueData()))
 * } */
typedef struct sCanIf_TxQueueIndex2DataStartStopType
{
  CanIf_TxQueueDataEndIdxOfTxQueueIndex2DataStartStopType TxQueueDataEndIdxOfTxQueueIndex2DataStartStop;  /**< the end index of the 0:n relation pointing to CanIf_TxQueueData */
  CanIf_TxQueueDataStartIdxOfTxQueueIndex2DataStartStopType TxQueueDataStartIdxOfTxQueueIndex2DataStartStop;  /**< the start index of the 0:n relation pointing to CanIf_TxQueueData */
  CanIf_TxQueueDataLengthOfTxQueueIndex2DataStartStopType TxQueueDataLengthOfTxQueueIndex2DataStartStop;  /**< the number of relations pointing to CanIf_TxQueueData */
} CanIf_TxQueueIndex2DataStartStopType;

/**   \brief  type used in CanIf_WakeUpConfig */
typedef struct sCanIf_WakeUpConfigType
{
  CanIf_ControllerIdOfWakeUpConfigType ControllerIdOfWakeUpConfig;  /**< ControllerId of this wake-up source configuration */
  CanIf_WakeUpSourceOfWakeUpConfigType WakeUpSourceOfWakeUpConfig;  /**< Wake-up source identifier */
  CanIf_WakeUpTargetAddressOfWakeUpConfigType WakeUpTargetAddressOfWakeUpConfig;  /**< Target address of wake up source (driver independent handle Id): CAN controller (ControllerId)/CAN transceiver (TransceiverId) */
  CanIf_WakeUpTargetType WakeUpTargetModuleOfWakeUpConfig;  /**< Target module of wake-up source: CAN driver/CAN transceiver driver */
} CanIf_WakeUpConfigType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSymbolicStructTypes  CanIf Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates */
typedef struct CanIf_CtrlStatesStructSTag
{
  CanIf_CtrlStatesType CT_FDCAN2_c5d3d1a7;
  CanIf_CtrlStatesType CT_FDCAN14_90ecad61;
} CanIf_CtrlStatesStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase */
typedef struct CanIf_TxBufferPrioByCanIdBaseStructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_7d164bae;
  CanIf_TxBufferPrioByCanIdBaseType CHNL_79fa912a;
} CanIf_TxBufferPrioByCanIdBaseStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue */
typedef struct CanIf_TxQueueStructSTag
{
  CanIf_TxPrioByCanIdByteQueueType XCP_Tx_oFDCAN2_dec73f67_Tx;
  CanIf_TxPrioByCanIdByteQueueType NM_PAM_oFDCAN2_28cff7c5_Tx;
  CanIf_TxPrioByCanIdByteQueueType PDC_INFO_FD_PAM_oFDCAN2_f59fee66_Tx;
  CanIf_TxPrioByCanIdByteQueueType CFG_DATA_CODE_RSP_PAM_oFDCAN2_9eaffcee_Tx;
  CanIf_TxPrioByCanIdByteQueueType DIAGNOSTIC_ROE_FD_PAM_oFDCAN2_5f1d7fc3_Tx;
  CanIf_TxPrioByCanIdByteQueueType DIAGNOSTIC_ROE_PAM_oFDCAN2_d9a769b3_Tx;
  CanIf_TxPrioByCanIdByteQueueType DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_3daa27dc_Tx;
  CanIf_TxPrioByCanIdByteQueueType DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_20_a02181d6_Tx;
  CanIf_TxPrioByCanIdByteQueueType DIAGNOSTIC_RESPONSE_PAM_Tp_oFDCAN2_dc079c65_Tx;
  CanIf_TxPrioByCanIdByteQueueType TRSCM_FD_1_oFDCAN2_a03575fe_Tx;
  CanIf_TxPrioByCanIdByteQueueType CVPAM_FD_Info_oFDCAN2_63faf907_Tx;
  CanIf_TxPrioByCanIdByteQueueType ADAS_FD_LANES_2_oFDCAN2_b32c517d_Tx;
  CanIf_TxPrioByCanIdByteQueueType ADAS_FD_LANES_1_oFDCAN2_60bc77b3_Tx;
  CanIf_TxPrioByCanIdByteQueueType CVPAM_FD_Control_oFDCAN2_4eff2f96_Tx;
  CanIf_TxPrioByCanIdByteQueueType UssCsmStateChangeReasons_oFDCAN14_9fbeef37_Tx;
  CanIf_TxPrioByCanIdByteQueueType USS_SectorInfoFB_oFDCAN14_14389c16_Tx;
  CanIf_TxPrioByCanIdByteQueueType PntDebugData_3_oFDCAN14_603295cf_Tx;
  CanIf_TxPrioByCanIdByteQueueType PntDebugData_2_oFDCAN14_9304bca8_Tx;
  CanIf_TxPrioByCanIdByteQueueType PntDebugData_1_oFDCAN14_5d2fc140_Tx;
  CanIf_TxPrioByCanIdByteQueueType PntDebugData_0_oFDCAN14_ae19e827_Tx;
  CanIf_TxPrioByCanIdByteQueueType Minimum_Sensor_Distance_3_oFDCAN14_29aa616f_Tx;
  CanIf_TxPrioByCanIdByteQueueType Minimum_Sensor_Distance_2_oFDCAN14_23601cc6_Tx;
  CanIf_TxPrioByCanIdByteQueueType Minimum_Sensor_Distance_1_oFDCAN14_3c3e9a3d_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_PackedDiagFlagData2_v_oFDCAN14_b3328600_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_PackedNoiseMeasData_oFDCAN14_32d10e8e_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_PackedDiagFlagData1_v_oFDCAN14_40a1873d_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_SnrMeasData_03_oFDCAN14_11beb26e_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_SystemStatus_oFDCAN14_3392fde0_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_DebugMsgUnsigned_oFDCAN14_e8b674cc_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_DebugMsgSigned_oFDCAN14_16ce7da0_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_SnrTemperature_oFDCAN14_4577f469_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_SnrMeasData_07_oFDCAN14_1045d0af_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_SnrMeasData_06_oFDCAN14_66e7498f_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_SnrMeasData_05_oFDCAN14_fd00e2ef_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_SnrMeasData_04_oFDCAN14_8ba27bcf_Tx;
  CanIf_TxPrioByCanIdByteQueueType DebugModelOutput_Feature_KPI_Tx_oFDCAN14_fae6f83c_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_SnrMeasData_02_oFDCAN14_671c2b4e_Tx;
  CanIf_TxPrioByCanIdByteQueueType Log_SnrMeasData_01_oFDCAN14_fcfb802e_Tx;
  CanIf_TxPrioByCanIdByteQueueType Diagnostics_Flags_oFDCAN14_82d05e9d_Tx;
  CanIf_TxPrioByCanIdByteQueueType Blockage_Flags_oFDCAN14_cd9c3e01_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_MCUOsDebugData2_oFDCAN14_977545dd_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_MCUOsDebugData1_oFDCAN14_0c92eebd_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_SystemDebugData_1_oFDCAN14_6a0508c3_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_SnsDat_Rear_Direct_oFDCAN14_6726d174_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_SnsDat_Front_Direct_oFDCAN14_92d50a6c_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_SnsDat_Rear_Direct_2_oFDCAN14_762da0cc_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_SnsDat_Front_Direct_2_oFDCAN14_d7e5c444_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_SnsDat_Rear_Indirect_1_oFDCAN14_75ed542b_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_SnsDat_Front_Indirect_1_oFDCAN14_a0b9888a_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_SnsDat_Rear_Indirect_2_oFDCAN14_6ab3d2d0_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_SnsDat_Front_Indirect_2_oFDCAN14_38edffe1_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_Debug_SensorTestData_3_oFDCAN14_ffe1e91c_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_Debug_SensorTestData_2_oFDCAN14_f52b94b5_Tx;
  CanIf_TxPrioByCanIdByteQueueType ME_Debug_SensorTestData_1_oFDCAN14_ea75124e_Tx;
  CanIf_TxPrioByCanIdByteQueueType FPADebugInfo1_oFDCAN14_ba73bd7c_Tx;
  CanIf_TxPrioByCanIdByteQueueType USSDebugInfo2_oFDCAN14_a2853d8e_Tx;
  CanIf_TxPrioByCanIdByteQueueType USSDebugInfo1_oFDCAN14_71151b40_Tx;
  CanIf_TxPrioByCanIdByteQueueType PLDDebugInfo2_oFDCAN14_12211571_Tx;
  CanIf_TxPrioByCanIdByteQueueType PLDDebugInfo1_oFDCAN14_c1b133bf_Tx;
  CanIf_TxPrioByCanIdByteQueueType LMD_SegmentDebug_2_2_oFDCAN14_be3e1ae4_Tx;
  CanIf_TxPrioByCanIdByteQueueType LMD_SegmentDebug_2_1_oFDCAN14_01887f27_Tx;
  CanIf_TxPrioByCanIdByteQueueType LMD_SegmentDebug_1_2_oFDCAN14_6331b408_Tx;
  CanIf_TxPrioByCanIdByteQueueType LMD_SegmentDebug_1_oFDCAN14_3a13c4d8_Tx;
  CanIf_TxPrioByCanIdByteQueueType LMD_LaneLinesDebug_2_oFDCAN14_965d36d3_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_ModuleState_oFDCAN14_96e19c7d_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_CalibSts_oFDCAN14_58546a56_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_ErrCodeAlgo_oFDCAN14_78756c50_Tx;
  CanIf_TxPrioByCanIdByteQueueType Firing_Sequence_oFDCAN14_afdc26b0_Tx;
  CanIf_TxPrioByCanIdByteQueueType Firing_Sensors_oFDCAN14_474d0a36_Tx;
  CanIf_TxPrioByCanIdByteQueueType Firing_Mode_oFDCAN14_60360c0e_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_11_oFDCAN14_2ace4b8f_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_10_oFDCAN14_4563a97d_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_9_oFDCAN14_ed3689c6_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_8_oFDCAN14_87a4aa87_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_7_oFDCAN14_ab58528b_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_6_oFDCAN14_c1ca71ca_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_5_oFDCAN14_7e7c1409_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_4_oFDCAN14_14ee3748_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_3_oFDCAN14_da61d9ce_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_2_oFDCAN14_b0f3fa8f_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_1_oFDCAN14_0f459f4c_Tx;
  CanIf_TxPrioByCanIdByteQueueType Distance_Point_Map_0_oFDCAN14_65d7bc0d_Tx;
  CanIf_TxPrioByCanIdByteQueueType DebugModelOutput_oFDCAN14_6b4c9d3e_Tx;
  CanIf_TxPrioByCanIdByteQueueType FODDebug_oFDCAN14_0f411cd7_Tx;
  CanIf_TxPrioByCanIdByteQueueType THADebugInfo2_oFDCAN14_062cf8ad_Tx;
  CanIf_TxPrioByCanIdByteQueueType THADebugInfo1_oFDCAN14_d5bcde63_Tx;
  CanIf_TxPrioByCanIdByteQueueType LMD_LaneLinesDebug_1_oFDCAN14_29eb5310_Tx;
  CanIf_TxPrioByCanIdByteQueueType MOT_Obj_8_9_oFDCAN14_bd8ad539_Tx;
  CanIf_TxPrioByCanIdByteQueueType MOT_Obj_6_7_oFDCAN14_35343c77_Tx;
  CanIf_TxPrioByCanIdByteQueueType MOT_Obj_4_5_oFDCAN14_cf8dc798_Tx;
  CanIf_TxPrioByCanIdByteQueueType MOT_Obj_2_3_oFDCAN14_1b36cde8_Tx;
  CanIf_TxPrioByCanIdByteQueueType MOT_Obj_0_1_oFDCAN14_e18f3607_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_FPA_HMI_InfoToVC_oFDCAN14_0eea4eb6_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_NFCD_Obj_5_9_oFDCAN14_b99541d7_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_NFCD_Obj_0_4_oFDCAN14_a030e1d4_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_AP_Variables_oFDCAN14_07efddff_Tx;
  CanIf_TxPrioByCanIdByteQueueType TRSC_FID_DebugMessage_oFDCAN14_04f18303_Tx;
  CanIf_TxPrioByCanIdByteQueueType TRSC_Detection_DebugMessage_oFDCAN14_e6f5f3c5_Tx;
  CanIf_TxPrioByCanIdByteQueueType TRSC_Debug_Message3_oFDCAN14_35eb5fb3_Tx;
  CanIf_TxPrioByCanIdByteQueueType TRSC_Debug_Message2_oFDCAN14_60efdc35_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_EOLCalib_Data_2_oFDCAN14_1ed59804_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_CurrentCalib_Data_2_oFDCAN14_192cb625_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_FeatureCollection_oFDCAN14_4fc45f26_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_TargetData_oFDCAN14_78b5aec6_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_OCCalib_Data_oFDCAN14_99914301_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_SCCalib_Data_oFDCAN14_415523bc_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_EOLCalib_Data_1_oFDCAN14_ae23bf12_Tx;
  CanIf_TxPrioByCanIdByteQueueType TRSC_Debug_Message1_oFDCAN14_9fe258bf_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_HMI_Internal_Data_oFDCAN14_49de4f3c_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_HMI_Input_Data_oFDCAN14_3b9e1113_Tx;
  CanIf_TxPrioByCanIdByteQueueType Debug_HMI_Trailer_Views_Data_oFDCAN14_a612f060_Tx;
  CanIf_TxPrioByCanIdByteQueueType HMI_Curr_Displayed_ProxiConfig_oFDCAN14_4ee7a674_Tx;
  CanIf_TxPrioByCanIdByteQueueType HMI_Curr_Requested_ProxiConfig_oFDCAN14_69d6981b_Tx;
  CanIf_TxPrioByCanIdByteQueueType HMI_Curr_Displayed_Overlays_oFDCAN14_228998f0_Tx;
  CanIf_TxPrioByCanIdByteQueueType HMI_Curr_Requested_Overlays_oFDCAN14_5ad84df2_Tx;
  CanIf_TxPrioByCanIdByteQueueType NM_PAM_oFDCAN14_636c02e4_Tx;
  CanIf_TxPrioByCanIdByteQueueType TRSCM_FD_1_oFDCAN14_24b0a50e_Tx;
  CanIf_TxPrioByCanIdByteQueueType CVPAM_FD_Info_oFDCAN14_98d10c56_Tx;
  CanIf_TxPrioByCanIdByteQueueType ADAS_FD_LANES_2_oFDCAN14_1fc7bdbe_Tx;
  CanIf_TxPrioByCanIdByteQueueType ADAS_FD_LANES_1_oFDCAN14_03fcfef0_Tx;
  CanIf_TxPrioByCanIdByteQueueType CVPAM_FD_Control_oFDCAN14_f55d7751_Tx;
} CanIf_TxQueueStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueData */
typedef struct CanIf_TxQueueDataStructSTag
{
  CanIf_TxQueueDataType XCP_Tx_oFDCAN2_dec73f67_Tx[8];
  CanIf_TxQueueDataType NM_PAM_oFDCAN2_28cff7c5_Tx[2];
  CanIf_TxQueueDataType PDC_INFO_FD_PAM_oFDCAN2_f59fee66_Tx[12];
  CanIf_TxQueueDataType CFG_DATA_CODE_RSP_PAM_oFDCAN2_9eaffcee_Tx[6];
  CanIf_TxQueueDataType DIAGNOSTIC_ROE_FD_PAM_oFDCAN2_5f1d7fc3_Tx[64];
  CanIf_TxQueueDataType DIAGNOSTIC_ROE_PAM_oFDCAN2_d9a769b3_Tx[8];
  CanIf_TxQueueDataType DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_3daa27dc_Tx[64];
  CanIf_TxQueueDataType DIAGNOSTIC_RESPONSE_FD_PAM_Tp_oFDCAN2_20_a02181d6_Tx[8];
  CanIf_TxQueueDataType DIAGNOSTIC_RESPONSE_PAM_Tp_oFDCAN2_dc079c65_Tx[8];
  CanIf_TxQueueDataType TRSCM_FD_1_oFDCAN2_a03575fe_Tx[32];
  CanIf_TxQueueDataType CVPAM_FD_Info_oFDCAN2_63faf907_Tx[32];
  CanIf_TxQueueDataType ADAS_FD_LANES_2_oFDCAN2_b32c517d_Tx[64];
  CanIf_TxQueueDataType ADAS_FD_LANES_1_oFDCAN2_60bc77b3_Tx[64];
  CanIf_TxQueueDataType CVPAM_FD_Control_oFDCAN2_4eff2f96_Tx[32];
  CanIf_TxQueueDataType UssCsmStateChangeReasons_oFDCAN14_9fbeef37_Tx[8];
  CanIf_TxQueueDataType USS_SectorInfoFB_oFDCAN14_14389c16_Tx[4];
  CanIf_TxQueueDataType PntDebugData_3_oFDCAN14_603295cf_Tx[64];
  CanIf_TxQueueDataType PntDebugData_2_oFDCAN14_9304bca8_Tx[64];
  CanIf_TxQueueDataType PntDebugData_1_oFDCAN14_5d2fc140_Tx[64];
  CanIf_TxQueueDataType PntDebugData_0_oFDCAN14_ae19e827_Tx[64];
  CanIf_TxQueueDataType Minimum_Sensor_Distance_3_oFDCAN14_29aa616f_Tx[7];
  CanIf_TxQueueDataType Minimum_Sensor_Distance_2_oFDCAN14_23601cc6_Tx[8];
  CanIf_TxQueueDataType Minimum_Sensor_Distance_1_oFDCAN14_3c3e9a3d_Tx[8];
  CanIf_TxQueueDataType Log_PackedDiagFlagData2_v_oFDCAN14_b3328600_Tx[64];
  CanIf_TxQueueDataType Log_PackedNoiseMeasData_oFDCAN14_32d10e8e_Tx[64];
  CanIf_TxQueueDataType Log_PackedDiagFlagData1_v_oFDCAN14_40a1873d_Tx[64];
  CanIf_TxQueueDataType Log_SnrMeasData_03_oFDCAN14_11beb26e_Tx[64];
  CanIf_TxQueueDataType ME_SystemStatus_oFDCAN14_3392fde0_Tx[8];
  CanIf_TxQueueDataType ME_DebugMsgUnsigned_oFDCAN14_e8b674cc_Tx[8];
  CanIf_TxQueueDataType ME_DebugMsgSigned_oFDCAN14_16ce7da0_Tx[8];
  CanIf_TxQueueDataType Log_SnrTemperature_oFDCAN14_4577f469_Tx[64];
  CanIf_TxQueueDataType Log_SnrMeasData_07_oFDCAN14_1045d0af_Tx[64];
  CanIf_TxQueueDataType Log_SnrMeasData_06_oFDCAN14_66e7498f_Tx[64];
  CanIf_TxQueueDataType Log_SnrMeasData_05_oFDCAN14_fd00e2ef_Tx[64];
  CanIf_TxQueueDataType Log_SnrMeasData_04_oFDCAN14_8ba27bcf_Tx[64];
  CanIf_TxQueueDataType DebugModelOutput_Feature_KPI_Tx_oFDCAN14_fae6f83c_Tx[64];
  CanIf_TxQueueDataType Log_SnrMeasData_02_oFDCAN14_671c2b4e_Tx[64];
  CanIf_TxQueueDataType Log_SnrMeasData_01_oFDCAN14_fcfb802e_Tx[64];
  CanIf_TxQueueDataType Diagnostics_Flags_oFDCAN14_82d05e9d_Tx[8];
  CanIf_TxQueueDataType Blockage_Flags_oFDCAN14_cd9c3e01_Tx[2];
  CanIf_TxQueueDataType ME_MCUOsDebugData2_oFDCAN14_977545dd_Tx[64];
  CanIf_TxQueueDataType ME_MCUOsDebugData1_oFDCAN14_0c92eebd_Tx[64];
  CanIf_TxQueueDataType ME_SystemDebugData_1_oFDCAN14_6a0508c3_Tx[64];
  CanIf_TxQueueDataType ME_SnsDat_Rear_Direct_oFDCAN14_6726d174_Tx[8];
  CanIf_TxQueueDataType ME_SnsDat_Front_Direct_oFDCAN14_92d50a6c_Tx[8];
  CanIf_TxQueueDataType ME_SnsDat_Rear_Direct_2_oFDCAN14_762da0cc_Tx[8];
  CanIf_TxQueueDataType ME_SnsDat_Front_Direct_2_oFDCAN14_d7e5c444_Tx[8];
  CanIf_TxQueueDataType ME_SnsDat_Rear_Indirect_1_oFDCAN14_75ed542b_Tx[8];
  CanIf_TxQueueDataType ME_SnsDat_Front_Indirect_1_oFDCAN14_a0b9888a_Tx[8];
  CanIf_TxQueueDataType ME_SnsDat_Rear_Indirect_2_oFDCAN14_6ab3d2d0_Tx[8];
  CanIf_TxQueueDataType ME_SnsDat_Front_Indirect_2_oFDCAN14_38edffe1_Tx[5];
  CanIf_TxQueueDataType ME_Debug_SensorTestData_3_oFDCAN14_ffe1e91c_Tx[64];
  CanIf_TxQueueDataType ME_Debug_SensorTestData_2_oFDCAN14_f52b94b5_Tx[64];
  CanIf_TxQueueDataType ME_Debug_SensorTestData_1_oFDCAN14_ea75124e_Tx[64];
  CanIf_TxQueueDataType FPADebugInfo1_oFDCAN14_ba73bd7c_Tx[64];
  CanIf_TxQueueDataType USSDebugInfo2_oFDCAN14_a2853d8e_Tx[64];
  CanIf_TxQueueDataType USSDebugInfo1_oFDCAN14_71151b40_Tx[64];
  CanIf_TxQueueDataType PLDDebugInfo2_oFDCAN14_12211571_Tx[20];
  CanIf_TxQueueDataType PLDDebugInfo1_oFDCAN14_c1b133bf_Tx[64];
  CanIf_TxQueueDataType LMD_SegmentDebug_2_2_oFDCAN14_be3e1ae4_Tx[48];
  CanIf_TxQueueDataType LMD_SegmentDebug_2_1_oFDCAN14_01887f27_Tx[64];
  CanIf_TxQueueDataType LMD_SegmentDebug_1_2_oFDCAN14_6331b408_Tx[12];
  CanIf_TxQueueDataType LMD_SegmentDebug_1_oFDCAN14_3a13c4d8_Tx[64];
  CanIf_TxQueueDataType LMD_LaneLinesDebug_2_oFDCAN14_965d36d3_Tx[64];
  CanIf_TxQueueDataType Debug_ModuleState_oFDCAN14_96e19c7d_Tx[64];
  CanIf_TxQueueDataType Debug_CalibSts_oFDCAN14_58546a56_Tx[64];
  CanIf_TxQueueDataType Debug_ErrCodeAlgo_oFDCAN14_78756c50_Tx[64];
  CanIf_TxQueueDataType Firing_Sequence_oFDCAN14_afdc26b0_Tx[8];
  CanIf_TxQueueDataType Firing_Sensors_oFDCAN14_474d0a36_Tx[6];
  CanIf_TxQueueDataType Firing_Mode_oFDCAN14_60360c0e_Tx[5];
  CanIf_TxQueueDataType Distance_Point_Map_11_oFDCAN14_2ace4b8f_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_10_oFDCAN14_4563a97d_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_9_oFDCAN14_ed3689c6_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_8_oFDCAN14_87a4aa87_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_7_oFDCAN14_ab58528b_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_6_oFDCAN14_c1ca71ca_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_5_oFDCAN14_7e7c1409_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_4_oFDCAN14_14ee3748_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_3_oFDCAN14_da61d9ce_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_2_oFDCAN14_b0f3fa8f_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_1_oFDCAN14_0f459f4c_Tx[64];
  CanIf_TxQueueDataType Distance_Point_Map_0_oFDCAN14_65d7bc0d_Tx[64];
  CanIf_TxQueueDataType DebugModelOutput_oFDCAN14_6b4c9d3e_Tx[64];
  CanIf_TxQueueDataType FODDebug_oFDCAN14_0f411cd7_Tx[64];
  CanIf_TxQueueDataType THADebugInfo2_oFDCAN14_062cf8ad_Tx[64];
  CanIf_TxQueueDataType THADebugInfo1_oFDCAN14_d5bcde63_Tx[64];
  CanIf_TxQueueDataType LMD_LaneLinesDebug_1_oFDCAN14_29eb5310_Tx[64];
  CanIf_TxQueueDataType MOT_Obj_8_9_oFDCAN14_bd8ad539_Tx[64];
  CanIf_TxQueueDataType MOT_Obj_6_7_oFDCAN14_35343c77_Tx[64];
  CanIf_TxQueueDataType MOT_Obj_4_5_oFDCAN14_cf8dc798_Tx[64];
  CanIf_TxQueueDataType MOT_Obj_2_3_oFDCAN14_1b36cde8_Tx[64];
  CanIf_TxQueueDataType MOT_Obj_0_1_oFDCAN14_e18f3607_Tx[64];
  CanIf_TxQueueDataType Debug_FPA_HMI_InfoToVC_oFDCAN14_0eea4eb6_Tx[64];
  CanIf_TxQueueDataType Debug_NFCD_Obj_5_9_oFDCAN14_b99541d7_Tx[64];
  CanIf_TxQueueDataType Debug_NFCD_Obj_0_4_oFDCAN14_a030e1d4_Tx[64];
  CanIf_TxQueueDataType Debug_AP_Variables_oFDCAN14_07efddff_Tx[64];
  CanIf_TxQueueDataType TRSC_FID_DebugMessage_oFDCAN14_04f18303_Tx[64];
  CanIf_TxQueueDataType TRSC_Detection_DebugMessage_oFDCAN14_e6f5f3c5_Tx[64];
  CanIf_TxQueueDataType TRSC_Debug_Message3_oFDCAN14_35eb5fb3_Tx[64];
  CanIf_TxQueueDataType TRSC_Debug_Message2_oFDCAN14_60efdc35_Tx[64];
  CanIf_TxQueueDataType Debug_EOLCalib_Data_2_oFDCAN14_1ed59804_Tx[64];
  CanIf_TxQueueDataType Debug_CurrentCalib_Data_2_oFDCAN14_192cb625_Tx[64];
  CanIf_TxQueueDataType Debug_FeatureCollection_oFDCAN14_4fc45f26_Tx[64];
  CanIf_TxQueueDataType Debug_TargetData_oFDCAN14_78b5aec6_Tx[64];
  CanIf_TxQueueDataType Debug_OCCalib_Data_oFDCAN14_99914301_Tx[64];
  CanIf_TxQueueDataType Debug_SCCalib_Data_oFDCAN14_415523bc_Tx[64];
  CanIf_TxQueueDataType Debug_EOLCalib_Data_1_oFDCAN14_ae23bf12_Tx[64];
  CanIf_TxQueueDataType TRSC_Debug_Message1_oFDCAN14_9fe258bf_Tx[64];
  CanIf_TxQueueDataType Debug_HMI_Internal_Data_oFDCAN14_49de4f3c_Tx[16];
  CanIf_TxQueueDataType Debug_HMI_Input_Data_oFDCAN14_3b9e1113_Tx[64];
  CanIf_TxQueueDataType Debug_HMI_Trailer_Views_Data_oFDCAN14_a612f060_Tx[64];
  CanIf_TxQueueDataType HMI_Curr_Displayed_ProxiConfig_oFDCAN14_4ee7a674_Tx[16];
  CanIf_TxQueueDataType HMI_Curr_Requested_ProxiConfig_oFDCAN14_69d6981b_Tx[16];
  CanIf_TxQueueDataType HMI_Curr_Displayed_Overlays_oFDCAN14_228998f0_Tx[16];
  CanIf_TxQueueDataType HMI_Curr_Requested_Overlays_oFDCAN14_5ad84df2_Tx[16];
  CanIf_TxQueueDataType NM_PAM_oFDCAN14_636c02e4_Tx[2];
  CanIf_TxQueueDataType TRSCM_FD_1_oFDCAN14_24b0a50e_Tx[32];
  CanIf_TxQueueDataType CVPAM_FD_Info_oFDCAN14_98d10c56_Tx[32];
  CanIf_TxQueueDataType ADAS_FD_LANES_2_oFDCAN14_1fc7bdbe_Tx[64];
  CanIf_TxQueueDataType ADAS_FD_LANES_1_oFDCAN14_03fcfef0_Tx[64];
  CanIf_TxQueueDataType CVPAM_FD_Control_oFDCAN14_f55d7751_Tx[32];
} CanIf_TxQueueDataStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCUnionIndexAndSymbolTypes  CanIf Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access CanIf_CtrlStates in an index and symbol based style. */
typedef union CanIf_CtrlStatesUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_CtrlStatesType raw[2];
  CanIf_CtrlStatesStructSType str;
} CanIf_CtrlStatesUType;

/**   \brief  type to access CanIf_TxBufferPrioByCanIdBase in an index and symbol based style. */
typedef union CanIf_TxBufferPrioByCanIdBaseUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxBufferPrioByCanIdBaseType raw[2];
  CanIf_TxBufferPrioByCanIdBaseStructSType str;
} CanIf_TxBufferPrioByCanIdBaseUType;

/**   \brief  type to access CanIf_TxQueue in an index and symbol based style. */
typedef union CanIf_TxQueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxPrioByCanIdByteQueueType raw[121];
  CanIf_TxQueueStructSType str;
} CanIf_TxQueueUType;

/**   \brief  type to access CanIf_TxQueueData in an index and symbol based style. */
typedef union CanIf_TxQueueDataUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxQueueDataType raw[5547];
  CanIf_TxQueueDataStructSType str;
} CanIf_TxQueueDataUType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCRootPointerTypes  CanIf Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanIf_BusOffNotificationFctPtr */
typedef P2CONST(CanIf_BusOffNotificationFctType, TYPEDEF, CANIF_CONST) CanIf_BusOffNotificationFctPtrPtrType;

/**   \brief  type used to point to CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef P2CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, TYPEDEF, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfigPtrType;

/**   \brief  type used to point to CanIf_CtrlConfig */
typedef P2CONST(CanIf_CtrlConfigType, TYPEDEF, CANIF_CONST) CanIf_CtrlConfigPtrType;

/**   \brief  type used to point to CanIf_CtrlModeIndicationFctPtr */
typedef P2CONST(CanIf_CtrlModeIndicationFctType, TYPEDEF, CANIF_CONST) CanIf_CtrlModeIndicationFctPtrPtrType;

/**   \brief  type used to point to CanIf_CtrlStates */
typedef P2VAR(CanIf_CtrlStatesType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_CtrlStatesPtrType;

/**   \brief  type used to point to CanIf_MailBoxConfig */
typedef P2CONST(CanIf_MailBoxConfigType, TYPEDEF, CANIF_CONST) CanIf_MailBoxConfigPtrType;

/**   \brief  type used to point to CanIf_MappedTxBuffersConfig */
typedef P2CONST(CanIf_MappedTxBuffersConfigType, TYPEDEF, CANIF_CONST) CanIf_MappedTxBuffersConfigPtrType;

/**   \brief  type used to point to CanIf_RxDHAdjust */
typedef P2CONST(CanIf_RxDHAdjustType, TYPEDEF, CANIF_CONST) CanIf_RxDHAdjustPtrType;

/**   \brief  type used to point to CanIf_RxIndicationFctList */
typedef P2CONST(CanIf_RxIndicationFctListType, TYPEDEF, CANIF_CONST) CanIf_RxIndicationFctListPtrType;

/**   \brief  type used to point to CanIf_RxPduConfig */
typedef P2CONST(CanIf_RxPduConfigType, TYPEDEF, CANIF_CONST) CanIf_RxPduConfigPtrType;

/**   \brief  type used to point to CanIf_TrcvModeIndicationFctPtr */
typedef P2CONST(CanIf_TrcvModeIndicationFctType, TYPEDEF, CANIF_CONST) CanIf_TrcvModeIndicationFctPtrPtrType;

/**   \brief  type used to point to CanIf_TrcvToCtrlMap */
typedef P2CONST(CanIf_TrcvToCtrlMapType, TYPEDEF, CANIF_CONST) CanIf_TrcvToCtrlMapPtrType;

/**   \brief  type used to point to CanIf_TxBufferPrioByCanIdBase */
typedef P2VAR(CanIf_TxBufferPrioByCanIdBaseType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBasePtrType;

/**   \brief  type used to point to CanIf_TxBufferPrioByCanIdByteQueueConfig */
typedef P2CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, TYPEDEF, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfigPtrType;

/**   \brief  type used to point to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef P2CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, TYPEDEF, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusPtrType;

/**   \brief  type used to point to CanIf_TxConfirmationFctList */
typedef P2CONST(CanIf_TxConfirmationFctType, TYPEDEF, CANIF_CONST) CanIf_TxConfirmationFctListPtrType;

/**   \brief  type used to point to CanIf_TxPduConfig */
typedef P2CONST(CanIf_TxPduConfigType, TYPEDEF, CANIF_CONST) CanIf_TxPduConfigPtrType;

/**   \brief  type used to point to CanIf_TxPduQueueIndex */
typedef P2CONST(CanIf_TxPduQueueIndexType, TYPEDEF, CANIF_CONST) CanIf_TxPduQueueIndexPtrType;

/**   \brief  type used to point to CanIf_TxQueue */
typedef P2VAR(CanIf_TxPrioByCanIdByteQueueType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxQueuePtrType;

/**   \brief  type used to point to CanIf_TxQueueData */
typedef P2VAR(CanIf_TxQueueDataType, TYPEDEF, CANIF_VAR_NOINIT_FAST) CanIf_TxQueueDataPtrType;

/**   \brief  type used to point to CanIf_TxQueueIndex2DataStartStop */
typedef P2CONST(CanIf_TxQueueIndex2DataStartStopType, TYPEDEF, CANIF_CONST) CanIf_TxQueueIndex2DataStartStopPtrType;

/**   \brief  type used to point to CanIf_WakeUpConfig */
typedef P2CONST(CanIf_WakeUpConfigType, TYPEDEF, CANIF_CONST) CanIf_WakeUpConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCRootValueTypes  CanIf Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanIf_PCConfig */
typedef struct sCanIf_PCConfigType
{
  uint8 CanIf_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} CanIf_PCConfigType;

typedef CanIf_PCConfigType CanIf_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlConfig
  \details
  Element              Description
  RxDHRandomNumber1    Rx - DoubleHash - 1st random number.
  RxDHRandomNumber2    Rx - DoubleHash - 2nd random number.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_CtrlConfigType, CANIF_CONST) CanIf_CtrlConfig[2];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfg         
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[4];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[2];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxDHAdjust
**********************************************************************************************************************/
/** 
  \var    CanIf_RxDHAdjust
  \brief  Rx - DoubleHash - adjust values.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxDHAdjustType, CANIF_CONST) CanIf_RxDHAdjust[99];
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[5];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[71];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TrcvModeIndicationFctType, CANIF_CONST) CanIf_TrcvModeIndicationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TrcvToCtrlMap
**********************************************************************************************************************/
/** 
  \var    CanIf_TrcvToCtrlMap
  \brief  Indirection table: CAN transceiver driver independent transceiver handle-Id (TransceiverId) to CAN driver independent CAN controller handle-Id (ControllerId).
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TrcvToCtrlMapType, CANIF_CONST) CanIf_TrcvToCtrlMap[1];
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[2];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[121];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[4];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  IsTxPduTruncation           TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx-PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[121];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle-Id to corresponding Tx buffer handle-Id. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element                          Description
  TxQueue                      
  TxQueueIdx                       the index of the 0:1 relation pointing to CanIf_TxQueue
  TxQueueIndex2DataStartStopIdx    the index of the 0:1 relation pointing to CanIf_TxQueueIndex2DataStartStop
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[121];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueIndex2DataStartStop
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueIndex2DataStartStop
  \details
  Element                Description
  TxQueueDataEndIdx      the end index of the 0:n relation pointing to CanIf_TxQueueData
  TxQueueDataStartIdx    the start index of the 0:n relation pointing to CanIf_TxQueueData
  TxQueueDataLength      the number of relations pointing to CanIf_TxQueueData
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxQueueIndex2DataStartStopType, CANIF_CONST) CanIf_TxQueueIndex2DataStartStop[121];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_WakeUpConfig
  \brief  Wake-up source configuration
  \details
  Element                Description
  ControllerId           ControllerId of this wake-up source configuration
  WakeUpSource           Wake-up source identifier
  WakeUpTargetAddress    Target address of wake up source (driver independent handle Id): CAN controller (ControllerId)/CAN transceiver (TransceiverId)
  WakeUpTargetModule     Target module of wake-up source: CAN driver/CAN transceiver driver
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_WakeUpConfigType, CANIF_CONST) CanIf_WakeUpConfig[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueData
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueData
  \brief  Variable declaration - Tx queue data.
*/ 
#define CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxQueueDataUType, CANIF_VAR_NOINIT_FAST) CanIf_TxQueueData;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/




#endif  /* CANIF_CFG_H */
/**********************************************************************************************************************
  END OF FILE: CanIf_Cfg.h
**********************************************************************************************************************/


