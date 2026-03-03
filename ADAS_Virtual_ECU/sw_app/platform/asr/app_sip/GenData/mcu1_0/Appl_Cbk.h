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
 *              File: Appl_Cbk.h
 *   Generation Time: 2024-02-13 13:07:46
 *           Project: L2H4060_CVADAS_MCU1_0 - Version 1.0
 *          Delivery: CBD2101089_D08
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (APPL_CBK_H)
# define APPL_CBK_H

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
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

/* Configurable notification interface prototypes */
FUNC(void, COM_APPL_CODE) ComErrorNotification_DES_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4b879cc8_Tx(void);
FUNC(void, COM_APPL_CODE) ComNotification_DES_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4b879cc8_Tx(void);
FUNC(void, COM_APPL_CODE) ComNotification_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_ASCM_Stat_oASCM_FD_2_oFDCAN2_58854b4a_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_Active_Park_Mode_oIPC_VEHICLE_SETUP_oFDCAN2_6a2a58c7_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_CM_TCH_STAT_oTELEMATIC_FD_5_oFDCAN2_64ce192d_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_CmdIgnSts_oBCM_FD_10_oFDCAN2_06c30ef2_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN14_cecdbc25_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_ECM_THA_Resp_oENGINE_FD_7_oFDCAN14_284045ab_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN14_994d6c00_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_EPBSts_oBRAKE_FD_4_oFDCAN14_c0ca10e6_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN14_e3df5684_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_FL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_GearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_HU_TRSC_EnableBtn_Sts_oTELEMATIC_FD_11_oFDCAN2_298c059b_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_ITBM_TrlrStat_oBCM_FD_29_oFDCAN2_144a42ca_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_PAMRequestSts_oBCM_FD_12_oFDCAN2_006058fe_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_RHRDoorSts_oBCM_FD_9_oFDCAN2_724acffd_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_SBR1RowDriverSeatSts_oORC_FD_1_oFDCAN2_bc99e8d7_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_ShiftLeverPosition_oTRANSM_FD_4_oFDCAN2_e41ef7f4_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_Shifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TCASERANGESTATUS_oDRIVETRAIN_FD_3_oFDCAN2_eee864ec_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TGW_CAMERA_DISP_STAT_oTELEMATIC_FD_14_oFDCAN2_9304ed4e_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TRSC_CenterBtn_Sts_oTRSKM_FD_1_oFDCAN2_08058c70_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_TurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx(void);
FUNC(void, COM_APPL_CODE) ComTimeoutNotification_VIN_MSG_oVIN_oFDCAN2_f39912b4_Rx(void);


#define COM_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

#endif  /* APPL_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Appl_Cbk.h
**********************************************************************************************************************/

