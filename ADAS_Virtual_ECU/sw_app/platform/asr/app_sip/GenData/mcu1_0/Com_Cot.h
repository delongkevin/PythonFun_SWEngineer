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
 *              File: Com_Cot.h
 *   Generation Time: 2025-04-10 16:40:27
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (COM_COT_H)
# define COM_COT_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Types.h"
/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

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
#define COM_START_SEC_APPL_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_MemMap */

/* Configurable interface TxPduCallout */
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ADAS_FD_LANES_1_oFDCAN14_7b05104b_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ADAS_FD_LANES_1_oFDCAN2_2258c462_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ADAS_FD_LANES_2_oFDCAN14_9032ab48_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ADAS_FD_LANES_2_oFDCAN2_1bd5f8a7_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_CVPAM_FD_Control_oFDCAN14_fab4999a_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_CVPAM_FD_Control_oFDCAN2_2dc7d8b6_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_CVPAM_FD_Info_oFDCAN14_f4e1b059_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_CVPAM_FD_Info_oFDCAN2_a36629be_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TRSCM_FD_1_oFDCAN14_f3c79e86_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TRSCM_FD_1_oFDCAN2_e88cefba_Tx(PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/* Configurable interface RxPduCallout */
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ADAS_FD_INFO_C2_oFDCAN2_f97a3a77_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ADAS_FD_INFO_oFDCAN14_fa8dfd08_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_AGSM_FD_2_oFDCAN2_97b68631_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ASCM_FD_1_oFDCAN2_d84f57a2_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ASCM_FD_2_oFDCAN2_e1c26b67_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_10_oFDCAN2_8d7683ae_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_12_oFDCAN2_a380ab28_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_27_oFDCAN2_02205564_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_29_oFDCAN2_cae28ef6_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_2_oFDCAN2_f3daca1a_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BCM_FD_9_oFDCAN2_718f54c7_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_1_oFDCAN14_02aef4ed_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_1_oFDCAN2_5504c66b_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_2_oFDCAN14_e9994fee_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_2_oFDCAN2_6c89faae_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_3_oFDCAN14_065b24d0_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_3_oFDCAN2_7bf2eeed_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_4_oFDCAN14_e4873fa9_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_4_oFDCAN2_1f938324_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_5_oFDCAN14_0b455497_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_5_oFDCAN2_08e89767_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_6_oFDCAN14_e072ef94_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_BRAKE_FD_7_oFDCAN14_0fb084aa_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_DRIVETRAIN_FD_3_oFDCAN2_8dcee934_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_2_oFDCAN14_2d544e1a_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_2_oFDCAN2_c0c2b657_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_5_oFDCAN14_cf885563_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_5_oFDCAN2_a4a3db9e_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_7_oFDCAN14_cb7d855e_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ENGINE_FD_7_oFDCAN2_8a55f318_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_EPS_FD_1_oFDCAN14_8851a155_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_EPS_FD_1_oFDCAN2_cf989270_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_EPS_FD_2_oFDCAN14_63661a56_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_EPS_FD_2_oFDCAN2_f615aeb5_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_GLOB_NAV_FD_C2_oFDCAN2_098ddc16_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_IPC_FD_1_oFDCAN2_0e087dd4_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_IPC_VEHICLE_SETUP_oFDCAN2_ddb2e91d_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_ORC_FD_1_oFDCAN2_f51fa5a1_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_PT_TORQUE_FD_1_oFDCAN14_c23d259d_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TELEMATIC_FD_11_oFDCAN2_ba15bfe5_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TELEMATIC_FD_14_oFDCAN2_f082faaa_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TELEMATIC_FD_5_oFDCAN2_e0161ca6_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TRANSM_FD_1_oFDCAN2_de4da8da_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TRANSM_FD_2_oFDCAN2_e7c0941f_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TRANSM_FD_4_oFDCAN2_94daed95_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_TRSKM_FD_1_oFDCAN2_2705233d_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);
FUNC(boolean, COM_APPL_CODE) ComIPduCallout_VIN_oFDCAN2_e2480108_Rx(PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);



#define COM_STOP_SEC_APPL_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_MemMap */

#endif  /* COM_COT_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cot.h
**********************************************************************************************************************/

