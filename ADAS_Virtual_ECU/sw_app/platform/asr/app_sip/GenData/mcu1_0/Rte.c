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
 *             File:  Rte.c
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0857 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */
#include "Ioc.h"
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_BswM.h"
#include "Rte_CDD_CryptoMgr.h"
#include "Rte_CDD_E2EWrapper.h"
#include "Rte_CDD_GenericBswM.h"
#include "Rte_CDD_IPCHandler.h"
#include "Rte_CDD_PMIC.h"
#include "Rte_CDD_Safety.h"
#include "Rte_CDD_WDG.h"
#include "Rte_CalDataProvider.h"
#include "Rte_Cdd_RunTimeStats_B.h"
#include "Rte_Cdd_RunTimeStats_QM.h"
#include "Rte_ComM.h"
#include "Rte_Csm.h"
#include "Rte_Dcm.h"
#include "Rte_DegManager_B.h"
#include "Rte_DegManager_QM.h"
#include "Rte_DemMaster_0.h"
#include "Rte_DemSatellite_0.h"
#include "Rte_Det.h"
#include "Rte_EcuM.h"
#include "Rte_ErrorMgrAgg_1_0_B.h"
#include "Rte_ErrorMgrAgg_1_0_QM.h"
#include "Rte_ErrorMgrSat_1_0_B.h"
#include "Rte_ErrorMgrSat_1_0_QM.h"
#include "Rte_IoHwAb.h"
#include "Rte_NvM.h"
#include "Rte_Os_OsCore0_swc.h"
#include "Rte_SSM_Master.h"
#include "Rte_SSM_Slave_1_0.h"
#include "Rte_SWC_DIDMgr.h"
#include "Rte_SWC_DTCMgr.h"
#include "Rte_SWC_KinematicModule.h"
#include "Rte_SWC_PartNumMgr.h"
#include "Rte_SWC_ProxiConfigMgr.h"
#include "Rte_SWC_RIDMgr.h"
#include "Rte_SWC_SafeVCANRx.h"
#include "Rte_SWC_SafeVCANTx.h"
#include "Rte_SWC_VCANRx.h"
#include "Rte_SWC_VCANTx.h"
#include "Rte_SWC_VoltageMgr.h"
#include "Rte_SWC_WdgFw.h"
#include "Rte_Safety_Guard.h"
#include "Rte_WdgM_SystemApplication_OsCore0.h"
#include "Rte_vRoE.h"
#include "SchM_Adc.h"
#include "SchM_BswM.h"
#include "SchM_CanIf.h"
#include "SchM_CanNm.h"
#include "SchM_CanSM.h"
#include "SchM_CanTp.h"
#include "SchM_CanTrcv_30_Tja1043.h"
#include "SchM_Can_30_Mcan.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Crypto_30_vHsm.h"
#include "SchM_Csm.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_Ea.h"
#include "SchM_EcuM.h"
#include "SchM_Eep_30_XXi2c01.h"
#include "SchM_I2c.h"
#include "SchM_IoHwAb.h"
#include "SchM_Nm.h"
#include "SchM_NvM.h"
#include "SchM_PduR.h"
#include "SchM_Wdg.h"
#include "SchM_WdgM.h"
#include "SchM_Xcp.h"
#include "SchM_vRoE.h"

#include "Rte_Hook.h"

#include "Com.h"
#if defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelUM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelUM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_8BIT
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState = RTE_STATE_UNINIT; /* PRQA S 3408 */ /* MD_Rte_3408 */
volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_StartTiming_InitState = RTE_STATE_UNINIT; /* PRQA S 0850, 3408, 1514 */ /* MD_MSR_MacroArgumentEmpty, MD_Rte_3408, MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Constants
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Array_15Bytes, RTE_CONST) Rte_C_Array_15Bytes_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorListArr_B, RTE_CONST) Rte_init_Errors_B = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorListArr_QM, RTE_CONST) Rte_init_Errors_QM = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FD14_Log_SnrMeasData_1, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FD14_Log_SnrMeasData_2, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_2_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FD14_Log_SnrMeasData_3, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_3_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FD14_Log_SnrMeasData_4, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_4_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FD14_Log_SnrMeasData_5, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_5_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FD14_Log_SnrMeasData_6, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_6_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FD14_Log_SnrMeasData_7, RTE_CONST) Rte_C_FD14_Log_SnrMeasData_7_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FD14_MAC_ADAS_FD_LANES_1, RTE_CONST) Rte_C_FD14_MAC_ADAS_FD_LANES_1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FD14_MAC_ADAS_FD_LANES_2, RTE_CONST) Rte_C_FD14_MAC_ADAS_FD_LANES_2_0 = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(FIDOutputArr_QM, RTE_CONST) Rte_C_FIDOutputArr_QM_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(MAC_ADAS_FD_LANES_1, RTE_CONST) Rte_C_MAC_ADAS_FD_LANES_1_0 = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(MAC_ADAS_FD_LANES_2, RTE_CONST) Rte_C_MAC_ADAS_FD_LANES_2_0 = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(MpuFltSts, RTE_CONST) Rte_C_MpuFltSts_0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(N_PDU, RTE_CONST) Rte_C_N_PDU_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(PmicStatus, RTE_CONST) Rte_C_PmicStatus_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Status, RTE_CONST) Rte_C_Status_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(StayActiveSource_FD02_PAM, RTE_CONST) Rte_C_StayActiveSource_FD02_PAM_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(VIN_DATA, RTE_CONST) Rte_C_VIN_DATA_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(VINlData_Arr, RTE_CONST) Rte_init_VINCurrentData = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(VINlData_Arr, RTE_CONST) Rte_init_VINOriginalData = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(WdgFltSts, RTE_CONST) Rte_C_WdgFltSts_0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(vRoE_MessageType, RTE_CONST) Rte_C_vRoE_MessageType_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CAM_CS_Curr_Monitor_t, RTE_CONST) Rte_C_CAM_CS_Curr_Monitor_t_0 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CAM_select_info_t, RTE_CONST) Rte_C_CAM_select_info_t_0 = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_CONST) Rte_C_CDP_TbSVS_S_SVSCamCurrentCalibData_t_0 = {
  0U, {{{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}
  }, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CalDataProvider_MCU_1_0_Def, RTE_CONST) Rte_C_CalDataProvider_MCU_1_0_Def_0 = {
  {{{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}, {
  {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}, {{{
  0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}, {{{
  0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}}, {{{{
  0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}, {{{
  0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}, {{{
  0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}, {{{
  0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}}, {{{
  0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, 
  FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 
  0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}
  }, 0U, 0U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Cam_and_Ser_EN_Status_t, RTE_CONST) Rte_C_Cam_and_Ser_EN_Status_t_0 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CpuLoadMcu2_0_t, RTE_CONST) Rte_C_CpuLoadMcu2_0_t_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(CpuLoadMcu2_1_t, RTE_CONST) Rte_C_CpuLoadMcu2_1_t_0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Debug_HMI_Curr_Displayed_Overlays, RTE_CONST) Rte_C_Debug_HMI_Curr_Displayed_Overlays_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Debug_HMI_Curr_Displayed_ProxiConfig, RTE_CONST) Rte_C_Debug_HMI_Curr_Displayed_ProxiConfig_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Debug_HMI_Curr_Requested_Overlays, RTE_CONST) Rte_C_Debug_HMI_Curr_Requested_Overlays_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Debug_HMI_Curr_Requested_ProxiConfig, RTE_CONST) Rte_C_Debug_HMI_Curr_Requested_ProxiConfig_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Debug_HMI_Input_Data_t, RTE_CONST) Rte_C_Debug_HMI_Input_Data_t_0 = {
  0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, 
  FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Debug_HMI_Internal_Data_t, RTE_CONST) Rte_C_Debug_HMI_Internal_Data_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 
  FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Debug_HMI_Trailer_Views_Data_t, RTE_CONST) Rte_C_Debug_HMI_Trailer_Views_Data_t_0 = {
  0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, 
  FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Detection_Inputs_from_TRSC_t, RTE_CONST) Rte_C_Detection_Inputs_from_TRSC_t_0 = {
  0U, 0.0F, 0.0F, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DtcAddData_B, RTE_CONST) Rte_init_Data_DtcAddData_B = {
  {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 
  0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {
  0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 
  0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {
  0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 
  0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {
  0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 
  0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {
  0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 
  0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DtcAddData_QM, RTE_CONST) Rte_init_Data_DtcAddData_QM = {
  {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DtcStatus_B, RTE_CONST) Rte_init_Data_DtcStatus_B = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(DtcStatus_QM, RTE_CONST) Rte_init_Data_DtcStatus_QM = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_1_0_B, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_1_0_B_0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{{0U, 0U, 0U, 0U
  }}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_1_0_B, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_1_0_B = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{{0U, 0U, 0U, 0U
  }}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_1_0_QM, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_1_0_QM_0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_1_0_QM, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_1_0_QM = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_2_0_B, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_2_0_B_0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  }, {{{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_2_0_B, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_2_0_B = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  }, {{{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_2_0_QM, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_2_0_QM_0 = {
  0U, 0U, {0U}, {0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_2_0_QM, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_2_0_QM = {
  0U, 0U, {0U}, {0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_2_1_B, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_2_1_B_0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_2_1_B, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_2_1_B = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 
  0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 
  0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{
  0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, 
  {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}
  }, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_2_1_QM, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_2_1_QM_0 = {
  0U, 0U, {0U}, {0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_2_1_QM, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_2_1_QM = {
  0U, 0U, {0U}, {0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_QNX_B, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_QNX_B_0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_QNX_B, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_QNX_B = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_QNX_QM, RTE_CONST) Rte_C_ErrorMgr_ErrorCommPack_QNX_QM_0 = {
  0U, 0U, {0U}, {0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ErrorMgr_ErrorCommPack_QNX_QM, RTE_CONST) Rte_init_Data_ErrorMgr_ErrorCommPack_QNX_QM = {
  0U, 0U, {0U}, {0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Error_Fault_MCU2_0_t, RTE_CONST) Rte_C_Error_Fault_MCU2_0_t_0 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Error_Fault_MCU2_1_t, RTE_CONST) Rte_C_Error_Fault_MCU2_1_t_0 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Error_Fault_MPU1_0_t, RTE_CONST) Rte_C_Error_Fault_MPU1_0_t_0 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(IDebug_FODObject_t, RTE_CONST) Rte_C_IDebug_FODObject_t_0 = {
  {{0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 
  0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}}, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(IFOD_Outputs_Arbitration_t, RTE_CONST) Rte_C_IFOD_Outputs_Arbitration_t_0 = {
  0U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(IFOD_Outputs_CVPAMFDData_t, RTE_CONST) Rte_C_IFOD_Outputs_CVPAMFDData_t_0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(IJobFPAOutput_t, RTE_CONST) Rte_C_IJobFPAOutput_t_0 = {
  FALSE, {{{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, 0.0F, 0.0F, 0U}, {0U}, {0U, {{{
  0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}}, {{{{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 
  0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE
  }, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {
  0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 
  0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}}, {{{0.0F, 0.0F}, {0.0F, 
  0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, 0.0F, 0.0F, {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE}, {0U, 
  0U, 0U, 0U, 0U, 0U}, FALSE}, {FALSE, FALSE, 0U, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 
  0U, FALSE}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(IJobPLDOutput_t, RTE_CONST) Rte_C_IJobPLDOutput_t_0 = {
  FALSE, {{{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {
  0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 
  0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F
  }, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 
  0U, 0U, FALSE}}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(IJobUSSObjectMapOutput_t, RTE_CONST) Rte_C_IJobUSSObjectMapOutput_t_0 = {
  FALSE, {{{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {
  0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 
  0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F
  }, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 
  0U, 0U, FALSE}}, 0U, 0U, {{{0.0F, 0.0F}, 0.0F, {{0.0F, 0.0F}, {0.0F, 0.0F}}, 0.0F, 0.0F, 0U, FALSE, FALSE}, {{0.0F, 
  0.0F}, 0.0F, {{0.0F, 0.0F}, {0.0F, 0.0F}}, 0.0F, 0.0F, 0U, FALSE, FALSE}, {{0.0F, 0.0F}, 0.0F, {{0.0F, 0.0F}, {0.0F, 
  0.0F}}, 0.0F, 0.0F, 0U, FALSE, FALSE}, {{0.0F, 0.0F}, 0.0F, {{0.0F, 0.0F}, {0.0F, 0.0F}}, 0.0F, 0.0F, 0U, FALSE, FALSE
  }}, {{{0.0F, 0.0F}, 0.0F, {{0.0F, 0.0F}, {0.0F, 0.0F}}, 0.0F, 0.0F, 0U, FALSE, FALSE}, {{0.0F, 0.0F}, 0.0F, {{0.0F, 
  0.0F}, {0.0F, 0.0F}}, 0.0F, 0.0F, 0U, FALSE, FALSE}, {{0.0F, 0.0F}, 0.0F, {{0.0F, 0.0F}, {0.0F, 0.0F}}, 0.0F, 0.0F, 
  0U, FALSE, FALSE}, {{0.0F, 0.0F}, 0.0F, {{0.0F, 0.0F}, {0.0F, 0.0F}}, 0.0F, 0.0F, 0U, FALSE, FALSE}}, {{{0.0F, 0.0F}, 
  {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(JobDLDOutput_t, RTE_CONST) Rte_C_JobDLDOutput_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(JobTHADetOutput_t, RTE_CONST) Rte_C_JobTHADetOutput_t_0 = {
  {0.0F, 0.0F, 0.0F}, {0, 0}, {0.0F, 0.0F, 0.0F}, {0, 0}, 0.0F, 0.0F, 0U, 0U, 0, 0, 0U, 0U, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(KeepAliveResponse_t, RTE_CONST) Rte_C_KeepAliveResponse_t_0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(LMD_Lane_Outputs_s, RTE_CONST) Rte_C_LMD_Lane_Outputs_s_0 = {
  {{{FALSE, 0U, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, 0, {0.0F, 0.0F, 0.0F}, 0.0F, 0U, 0, 0U, 0, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {FALSE, 0U, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, 0, {0.0F, 0.0F, 
  0.0F}, 0.0F, 0U, 0, 0U, 0, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}}, {{0, {{0, 0, 0, 0}, {0, 0, 0, 0}}, {0, 0}, {0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 0, 0, FALSE, FALSE}, {{{0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 
  0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 
  0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 
  0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 
  0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {
  0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, 
  FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 
  0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, 
  FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 
  0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 
  0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, 
  FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 
  0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, 
  FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 
  0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 
  0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 
  0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}
  }, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, 
  FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 
  0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 
  0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 
  0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE
  }, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, 
  FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 
  0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 
  0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 
  0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 
  0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {
  0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, 
  FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 
  0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, 
  FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 
  0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 
  0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, 
  FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 
  0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, 
  FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 
  0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 
  0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 
  0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}
  }, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, 
  FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 
  0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 
  0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 
  0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE
  }, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, 
  FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 
  0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 
  0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 
  0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 
  0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {
  0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, 
  FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 
  0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, 
  FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 
  0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 
  0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, 
  FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 
  0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, 
  FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 
  0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 
  0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 
  0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}
  }, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, 
  FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 0, FALSE, 
  0.0F, 0.0F, FALSE, FALSE}}, {0, 0, 0, 0, {0, 0, 0.0F, 0.0F, 0, FALSE, 0.0F, 0.0F, FALSE, FALSE}, {0, 0, 0.0F, 0.0F, 
  0, FALSE, 0.0F, 0.0F, FALSE, FALSE}}}, 0, 0, {{0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}}, {{0.0F, 0.0F, 0.0F}, {0.0F, 
  0.0F, 0.0F}}, {FALSE, FALSE}, {0U, 0U}, {{{0.0F, 0.0F, 0.0F}, 0, 0, 0, 0, 0, 0.0F, {0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, {
  0.0F, 0.0F}, 0.0F, 0.0F}, {{0.0F, 0.0F, 0.0F}, 0, 0, 0, 0, 0, 0.0F, {0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, {0.0F, 0.0F}, 
  0.0F, 0.0F}}}, 0U, 0U, FALSE}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(LMD_Outputs_CVPAMFDData2_t, RTE_CONST) Rte_C_LMD_Outputs_CVPAMFDData2_t_0 = {
  {0ULL, 0ULL, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  }, {0ULL, 0ULL, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ME_Hydra2defs_S_CodingTableExt_t, RTE_CONST) Rte_C_ME_Hydra2defs_S_CodingTableExt_t_1 = {
  FALSE, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_CONST) Rte_C_ME_Hydra2defs_S_PROXI_error_Data_t_0 = {
  {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ME_Proxi_MPU1_0_to_MCU1_0_t, RTE_CONST) Rte_C_ME_Proxi_MPU1_0_to_MCU1_0_t_0 = {
  0.0F, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ME_VehInp_to_IpcSignals_QM_t, RTE_CONST) Rte_C_ME_VehInp_to_IpcSignals_QM_t_0 = {
  {0U, 0U}, {0U}, {0U, 0U, 0U}, {0U}, {0U}, {FALSE, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ME_VehOut_TRSC_t, RTE_CONST) Rte_C_ME_VehOut_TRSC_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0U, 0U, 0U, FALSE, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(NFCD_Output, RTE_CONST) Rte_C_NFCD_Output_0 = {
  {{0U, {0.0F, 0.0F}, 0U, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 
  0.0F}, {0.0F, 0.0F}}, {0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, FALSE, 0U}, {0U, {0.0F, 0.0F}, 0U, {{0.0F, 0.0F}, {0.0F, 0.0F}, 
  {0.0F, 0.0F}, {0.0F, 0.0F}}, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {0.0F, 0.0F}, 0.0F, 0.0F, 
  0.0F, FALSE, 0U}, {0U, {0.0F, 0.0F}, 0U, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {{0.0F, 0.0F}, {
  0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, FALSE, 0U}, {0U, {0.0F, 0.0F}, 0U, {{0.0F, 
  0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {0.0F, 
  0.0F}, 0.0F, 0.0F, 0.0F, FALSE, 0U}, {0U, {0.0F, 0.0F}, 0U, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 
  {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, FALSE, 0U}, {0U, {0.0F, 0.0F
  }, 0U, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 
  0.0F}}, {0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, FALSE, 0U}, {0U, {0.0F, 0.0F}, 0U, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, 
  {0.0F, 0.0F}}, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, FALSE, 0U}, {
  0U, {0.0F, 0.0F}, 0U, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 
  0.0F}, {0.0F, 0.0F}}, {0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, FALSE, 0U}, {0U, {0.0F, 0.0F}, 0U, {{0.0F, 0.0F}, {0.0F, 0.0F}, 
  {0.0F, 0.0F}, {0.0F, 0.0F}}, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {0.0F, 0.0F}, 0.0F, 0.0F, 
  0.0F, FALSE, 0U}, {0U, {0.0F, 0.0F}, 0U, {{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {{0.0F, 0.0F}, {
  0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, {0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, FALSE, 0U}}, 0U, 0.0F, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(NVMSignalManager_t, RTE_CONST) Rte_C_NVMSignalManager_t_0 = {
  FALSE, FALSE, 0U, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(RunTimeStats_MCU2_0_t, RTE_CONST) Rte_C_RunTimeStats_MCU2_0_t_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(RunTimeStats_MCU2_1_t, RTE_CONST) Rte_C_RunTimeStats_MCU2_1_t_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(RunTimeStats_MPU1_0_t, RTE_CONST) Rte_C_RunTimeStats_MPU1_0_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SSM_1_0_CoreStatus, RTE_CONST) Rte_C_SSM_1_0_CoreStatus_0 = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SSM_2_0_CoreStatus, RTE_CONST) Rte_C_SSM_2_0_CoreStatus_0 = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SSM_2_1_CoreStatus, RTE_CONST) Rte_C_SSM_2_1_CoreStatus_0 = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SSM_QNX_CoreStatus, RTE_CONST) Rte_C_SSM_QNX_CoreStatus_0 = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SSM_SystemState, RTE_CONST) Rte_C_SSM_SystemState_0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SVSToDiag_t, RTE_CONST) Rte_C_SVSToDiag_t_0 = {
  0U, 0U, 0U, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SVS_NVMData_t, RTE_CONST) Rte_C_SVS_NVMData_t_0 = {
  FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SVStoTRSC_t, RTE_CONST) Rte_C_SVStoTRSC_t_0 = {
  0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SafeStateOpDef, RTE_CONST) Rte_Pkg_ErrorMgrAgg_1_0_B_Constant_init_SafeStateOp = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SafeStateOpDef, RTE_CONST) Rte_Pkg_ErrorMgrAgg_1_0_QM_Constant_init_SafeStateOp = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ScreenRequest_t, RTE_CONST) Rte_C_ScreenRequest_t_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{0U, 0U, FALSE, 0U, 0U}, {0U, 
  0U, FALSE, 0U, 0U}, {0U, 0U, FALSE, 0U, 0U}, {0U, 0U, FALSE, 0U, 0U}, {0U, 0U, FALSE, 0U, 0U}, {0U, 0U, FALSE, 0U, 0U}
  }, 0U, 0U, 0U, 0U, 0U, 0U, 0, 0, 0, 0, 0U, 0U, 0U, 0U, 0U, 0, 0U, 0U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ScreenResponse_t, RTE_CONST) Rte_C_ScreenResponse_t_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{0U, 0U, FALSE, 0U, 0U}, {0U, 
  0U, FALSE, 0U, 0U}, {0U, 0U, FALSE, 0U, 0U}, {0U, 0U, FALSE, 0U, 0U}, {0U, 0U, FALSE, 0U, 0U}, {0U, 0U, FALSE, 0U, 0U}
  }, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0U, 0, 0, 0, 0, 0U, 0U, 0U, 0U, 0U, 0, 0U, 0U, 0U, 0U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(StackUsage_MCU2_0_t, RTE_CONST) Rte_C_StackUsage_MCU2_0_t_0 = {
  {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(StackUsage_MCU2_1_t, RTE_CONST) Rte_C_StackUsage_MCU2_1_t_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U}, {0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SvsToTHA_t, RTE_CONST) Rte_C_SvsToTHA_t_0 = {
  0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SvsToVCAN_t, RTE_CONST) Rte_C_SvsToVCAN_t_0 = {
  FALSE, FALSE, FALSE, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Svs_CamEepromDataArray_t, RTE_CONST) Rte_C_Svs_CamEepromDataArray_t_0 = {
  {{{{0, 0}, {0, {0, 0}, {0, 0}, {0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0}, 0}, {{0, 0}, {0, 0, 0}, {0, 0, 0, 0}, {0}}, {0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
  }, {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0U, 0U, 0.0F, 0.0F, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}}, {0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}}}, {{{0, 0}, {0, {0, 0}, {
  0, 0}, {0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0}, 0}, {{0, 0}, {0, 0, 0}, {0, 0, 0, 0}, {0}}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0}, {0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}}, {{0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0U, 0U, 0.0F, 0.0F, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}}, {0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}}}, {{{0, 0}, {0, {0, 0}, {0, 0}, {0, 0, 0}, {0, 0, 
  0, 0, 0}, {0, 0}, 0}, {{0, 0}, {0, 0, 0}, {0, 0, 0, 0}, {0}}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0U, 
  0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}}, {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0}, 0U, 0U, 0.0F, 0.0F, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 0.0F, 0.0F, 
  0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}}, {0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}}}, {{{0, 0}, {0, {0, 0}, {0, 0}, {0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0}, 0}, {{
  0, 0}, {0, 0, 0}, {0, 0, 0, 0}, {0}}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0U, 0U}, {0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}}, {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0U, 0U, 0.0F, 
  0.0F, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, 0.0F, {0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  }}, {0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {
  0U, 0U, 0U, 0U}}}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TRSCSMVCtoDebugCAN_t, RTE_CONST) Rte_C_TRSCSMVCtoDebugCAN_t_0 = {
  0.0F, 0.0F, 0.0F, 0U, 0U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TRSCSMVCtoSVS_t, RTE_CONST) Rte_C_TRSCSMVCtoSVS_t_0 = {
  0U, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TRSC_Inputs_from_TrailerDetection_t, RTE_CONST) Rte_C_TRSC_Inputs_from_TrailerDetection_t_0 = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TRSCtoDiagMgr_t, RTE_CONST) Rte_C_TRSCtoDiagMgr_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_APSMPAOut_t, RTE_CONST) Rte_C_TbAP_APSMPAOut_t_0 = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_DebugOut, RTE_CONST) Rte_C_TbAP_DebugOut_0 = {
  0.0F, 0.0F, 0.0F, 0U, 0U, 0, 0, 0, 0, 0, 0, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 
  FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_DriveAssistStatOut_t, RTE_CONST) Rte_C_TbAP_DriveAssistStatOut_t_0 = {
  0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 
  FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_FPAWarnOut_t, RTE_CONST) Rte_C_TbAP_FPAWarnOut_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_PAStateOut_t, RTE_CONST) Rte_C_TbAP_PAStateOut_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_RPAWarnOut_t, RTE_CONST) Rte_C_TbAP_RPAWarnOut_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_SMDAInternalOut_t, RTE_CONST) Rte_C_TbAP_SMDAInternalOut_t_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_SMPAInternalOut_t, RTE_CONST) Rte_C_TbAP_SMPAInternalOut_t_0 = {
  0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_VCActuatorOut_t, RTE_CONST) Rte_C_TbAP_VCActuatorOut_t_0 = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_VCStateOut_t, RTE_CONST) Rte_C_TbAP_VCStateOut_t_0 = {
  0.0F, 0, 0U, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbAP_VrntTunParam_t, RTE_CONST) Rte_C_TbAP_VrntTunParam_t_0 = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbFA_ArbiterOutput_t, RTE_CONST) Rte_C_TbFA_ArbiterOutput_t_0 = {
  FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbFA_ResetKM_t, RTE_CONST) Rte_C_TbFA_ResetKM_t_0 = {
  FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, RTE_CONST) Rte_C_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_0 = {
  FALSE, 0U, {{{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 
  0U}}, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U
  }}, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}
  }, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}
  }, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbSVS_S_SVSCamEOLCalibDataToNVM_t, RTE_CONST) Rte_C_TbSVS_S_SVSCamEOLCalibDataToNVM_t_0 = {
  FALSE, 0U, {{{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 
  0U}}, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U
  }}, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}
  }, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}
  }, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbSVS_S_SVSCamOCCalibDataToNVM_t, RTE_CONST) Rte_C_TbSVS_S_SVSCamOCCalibDataToNVM_t_0 = {
  FALSE, 0U, 0U, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 
  0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbSVS_S_SVSCamSCCalibDataToNVM_t, RTE_CONST) Rte_C_TbSVS_S_SVSCamSCCalibDataToNVM_t_0 = {
  FALSE, 0U, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 
  0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbSVS_e_SVSOutputToDiagMgrCamCalib_t, RTE_CONST) Rte_C_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_0 = {
  FALSE, FALSE, FALSE, FALSE, {FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE}, {FALSE, 
  FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE}, {FALSE, FALSE, FALSE, FALSE, FALSE, 
  FALSE}, 0U, 0U, 0U, {{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, {0, 0, 0, 0, 0, 0, 0, 0}, 0U}, {0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0U, 0U, {0, 0, 0, 0, 0, 0, 0, 0}, 0U}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, {0, 0, 0, 0, 0, 
  0, 0, 0}, 0U}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, {0, 0, 0, 0, 0, 0, 0, 0}, 0U}}, {{0.0F, 0.0F, 0.0F, 0U, 
  0U, 0U, 0U, 0U, 0U}, {0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U}, {0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U}, {0.0F, 
  0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U}}, {{0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U}, {0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 
  0U, 0U}, {0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U}, {0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U}}, {0U, 0U, 0U, 0U}, {
  0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbSVS_e_SVSOutputToNVMCamCalibSM_t, RTE_CONST) Rte_C_TbSVS_e_SVSOutputToNVMCamCalibSM_t_0 = {
  FALSE, 0U, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U
  }}, {0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, {0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbTHASmVc_DiagMgr_t, RTE_CONST) Rte_C_TbTHASmVc_DiagMgr_t_0 = {
  0, 0.0F, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TbTHASmVc_FeatureOutputs_t, RTE_CONST) Rte_C_TbTHASmVc_FeatureOutputs_t_0 = {
  0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 
  FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(TrailerDetection_Output_DID_t, RTE_CONST) Rte_C_TrailerDetection_Output_DID_t_0 = {
  0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, {0U, FALSE}, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_BlockageBit_t, RTE_CONST) Rte_C_US_S_BlockageBit_t_0 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_CsmStateChangeReason_Type, RTE_CONST) Rte_C_US_S_CsmStateChangeReason_Type_0 = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_DebugMsg_t, RTE_CONST) Rte_C_US_S_DebugMsg_t_0 = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_MarriageSensorIDs_t, RTE_CONST) Rte_C_US_S_MarriageSensorIDs_t_0 = {
  FALSE, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_PointDistOutputBuff_t, RTE_CONST) Rte_C_US_S_PointDistOutputBuff_t_0 = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_PointMapGroup_t, RTE_CONST) Rte_C_US_S_PointMapGroup_t_0 = {
  {0U, 0U, 0U}, {0U, 0U, {0U, 0U, 0U}}, {0U, {{0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {
  0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U
  }, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 
  0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 
  0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 
  0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 
  0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 
  0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {
  0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U
  }, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 
  0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 
  0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 
  0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 
  0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 
  0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {
  0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U
  }, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 
  0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 
  0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 
  0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 0U, 0U, 0U, 0U}, {0, 0, 
  0U, 0U, 0U, 0U}}}, {0U, {0U, 0U, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_SnrDirEcho_t, RTE_CONST) Rte_C_US_S_SnrDirEcho_t_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 
  0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_USSConstantData_t, RTE_CONST) Rte_C_US_S_USSConstantData_t_0 = {
  {{0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, 
  {0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL}, {0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_USSDataCollectionData_t, RTE_CONST) Rte_C_US_S_USSDataCollectionData_t_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  }, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_USSErrorDiagData_t, RTE_CONST) Rte_C_US_S_USSErrorDiagData_t_0 = {
  {0U, 0U, 0U, 0U, 0U}, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_USSPeriodDiagData_t, RTE_CONST) Rte_C_US_S_USSPeriodDiagData_t_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_ZoneInfo_t, RTE_CONST) Rte_C_US_S_ZoneInfo_t_0 = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(UssPowerSense, RTE_CONST) Rte_C_UssPowerSense_0 = {
  0.0F, 0.0F, 0.0F, {0.0F, 0.0F}, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(UssTunningData_mcu2_1_t, RTE_CONST) Rte_C_UssTunningData_mcu2_1_t_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(VehInpAdapter_opVehSignals, RTE_CONST) Rte_C_VehInpAdapter_opVehSignals_0 = {
  {0U, 0U, 0U, 0U, 0U, 0.0F}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0.0F, 0U, 0U, 0U, 0.0F}, {0U, 0.0F, 0U, 0U, 0U, 0.0F}, 
  {0U, 0U}, {0U, 0U, 0.0F, 0.0F, 0U}, {0.0F, 0.0F}, {0U, 0U}, {0.0F, 0.0F, 0.0F}, {0U, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 
  0.0F, 0.0F}, {0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U}, {0.0F, 0.0F, 0.0F}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  }, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0.0F}, {0U}, {0U, 0U, 0U}, {0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {
  0.0F, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U
  }, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0.0F, 0.0F}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0.0F, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F}, {0U}, {0U, 
  0U, 0U, 0U, 0U}, {0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0U, 
  0U, 0U, 0U}, {0U}, {0.0F, 0.0F}, {0.0F, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0, 0, 0, 0, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(WdgCheckpointStatus_t, RTE_CONST) Rte_C_WdgCheckpointStatus_t_0 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Calibration Parameters (SW-C local and calibration component calibration parameters)
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SecondCounter_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200B_TimeSinceFirstDTC_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint32, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_ECU_LifeTime_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2002_OdoFlashing_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200A_IgOnCounter_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200C_TimeSinceIgnOnFirstDTC_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_200D_LastClearDTCOdo_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD74_BuffMarkCompErr_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD74_PHY_TuningErr_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint16, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Safety_Guard_SafeStat2_ResetReason_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessDelayFlag_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecAccessInvalidCount_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_DefaultValue = 55U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_191D_PowerLatch_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2002_ProgReqFlag_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD42_FailsafeAction_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD42_FailsafeDebug_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FDF0_SleepProcess_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_vRoE_Activation_State_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DTCMgr_DTC_APARequestSts_PAMRequestSts_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_DID_5201_PlantModeStatus_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_Lock_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_OdometerCnt_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(boolean, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_CertificateExpired_DefaultValue = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Array_15Bytes, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_NvMBlockDescriptor_SystemTimestamp_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Arr_2Byte, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_DefaultValue = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Arr_20Byte, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_2939_WakeupReason_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD33_MagnaTesting_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(DID_F110_Pin_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F110_Ecu_Diag_Info_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F132_EBOM_Ecu_PartNum_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F133_EBOM_Asm_PartNum_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F134_CODEP_Asm_PartNum_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data13ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F180_Boot_SW_Ver_Info_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F187_CODEP_Ecu_PartNum_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F188_FCA_ESLM_Ecu_SW_Num_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F18A_FCA_ESLM_Ecu_SW_Cal_Num_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data10ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F18B_FCA_ESLM_ECU_SW_App_Num_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data11ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F194_Supplier_Ecu_SW_PartNum_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data2ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_F195_Supplier_Ecu_SW_VerNum_DefaultValue = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Dcm_Data4ByteType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_DID_FD31_EOLCodingState_DefaultValue = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(VINlData_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_CurrentVal_DefaultValue = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(VINlData_Arr, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_RIDMgr_VIN_OriginalVal_DefaultValue = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(SecureLogRecord_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup1_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(SecureLogRecord_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_CryptoMgr_Rte_SWC_CDD_CryptoMngr_SecureLogGroup2_DefaultValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(INVMSignalManager_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CDD_IPCHandler_FPA_Slot_Data_DefaultValue = {
  FALSE, FALSE, 0U, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_FrontCamSerialNumber_DefaultValue = {
  {0, 0}, {0, 0, 0}, {0, 0, 0, 0}, {0}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_LeftCamSerialNumber_DefaultValue = {
  {0, 0}, {0, 0, 0}, {0, 0, 0, 0}, {0}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_RearCamSerialNumber_DefaultValue = {
  {0, 0}, {0, 0, 0}, {0, 0, 0, 0}, {0}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(FinalAssemblySerialNumber_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_RightCamSerialNumber_DefaultValue = {
  {0, 0}, {0, 0, 0}, {0, 0, 0, 0}, {0}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamCurrentCalibData_DefaultValue = {
  0U, {{{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}
  }, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(CDP_TbSVS_S_SVSCamEOLCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamEOLCalibData_DefaultValue = {
  0U, {{{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}
  }, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(CDP_TbSVS_S_SVSCamOCCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamOCCalibData_DefaultValue = {
  0U, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, 
  FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(CDP_TbSVS_S_SVSCamSCCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_CalDataProvider_SVSCamSCCalibData_DefaultValue = {
  0U, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, 
  FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(TbSVS_S_SVSCamCurrentCalibData_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD01_PrevCalibDataCopy_DefaultValue = {
  {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}, {{
  {0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}, {{{
  0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}, {{{
  0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(FunctionalSettings_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_FD86_FunctionalSettings_DefaultValue = {
  1U, 350U, 1U, 10U, 30U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(RearBrkEvent_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_RearBrakeEvent_DefaultValue = {
  0U, {{0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(SPMAbrtEvent_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_DIDMgr_DID_SPMAbrtEvent_DefaultValue = {
  0U, {{0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(US_S_MarriageSensorIDs_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_PartNumMgr_UssSensorMarrData_DefaultValue = {
  FALSE, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(ME_Hydra2defs_S_CodingTableExt_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_ProxiConfigMgr_ProxiConfigTable_DefaultValue = {
  FALSE, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, 0U, 
  8U, 0U, 0U, 1U, 1U, 1U, 0U, 2514U, 1U, 0U, 1U, 1U, 4U, 1U, 1U, 0U, 124U, 2U, 0U, 1U, 27U, 0U, 0U, 1U, 0U, 1U, 1U, 7U, 
  3U, 0U, 0U, 0U, 0U, 0U, 1U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_SWC_ProxiConfigMgr_ProxiErrorData_DefaultValue = {
  {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)


#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_ESH_Mode(BswM_ESH_Mode mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_NM_State(uint8 mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_CDD_GenericBswM_SYSModeRequestType(uint8 mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmEcuReset(Dcm_EcuResetType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_ESH_Mode(BswM_ESH_Mode mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 3U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 0U;
  }
  else if (mode == 3U)
  {
    ret = 4U;
  }
  else if (mode == 4U)
  {
    ret = 2U;
  }
  else
  {
    ret = 5U;
  }

  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_NM_State(uint8 mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 5U;
  }
  else if (mode == 1U)
  {
    ret = 0U;
  }
  else if (mode == 2U)
  {
    ret = 2U;
  }
  else if (mode == 3U)
  {
    ret = 3U;
  }
  else if (mode == 4U)
  {
    ret = 1U;
  }
  else if (mode == 5U)
  {
    ret = 4U;
  }
  else
  {
    ret = 6U;
  }

  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_CDD_GenericBswM_SYSModeRequestType(uint8 mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 1U;
  }
  else if (mode == 1U)
  {
    ret = 0U;
  }
  else if (mode == 2U)
  {
    ret = 3U;
  }
  else if (mode == 3U)
  {
    ret = 2U;
  }
  else
  {
    ret = 4U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmEcuReset(Dcm_EcuResetType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 5U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 4U;
  }
  else if (mode == 3U)
  {
    ret = 6U;
  }
  else if (mode == 4U)
  {
    ret = 2U;
  }
  else if (mode == 5U)
  {
    ret = 3U;
  }
  else if (mode == 6U)
  {
    ret = 0U;
  }
  else
  {
    ret = 7U;
  }

  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_SystemTimer
# define RTE_USEC_SystemTimer OS_US2TICKS_SystemTimer
#else
# define RTE_USEC_SystemTimer(val) ((TickType)RTE_CONST_USEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer
# define RTE_MSEC_SystemTimer OS_MS2TICKS_SystemTimer
#else
# define RTE_MSEC_SystemTimer(val) ((TickType)RTE_CONST_MSEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer
# define RTE_SEC_SystemTimer OS_SEC2TICKS_SystemTimer
#else
# define RTE_SEC_SystemTimer(val)  ((TickType)RTE_CONST_SEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#define RTE_CONST_MSEC_SystemTimer_0U (0UL)
#define RTE_CONST_MSEC_SystemTimer_10U (10UL)
#define RTE_CONST_MSEC_SystemTimer_200U (200UL)
#define RTE_CONST_MSEC_SystemTimer_5U (5UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num) /* PRQA S 3408, 1505 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
{
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = src[i];
  }
}

#define RTE_MEMCPY32ALIGN (sizeof(uint32) - 1U)

FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num)
{
  P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA) asrc = (P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR) adst = (P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i = 0;

  if (num >= 16U)
  {
    if (((((uint32)src) & RTE_MEMCPY32ALIGN) == 0U) && ((((uint32)dst) & RTE_MEMCPY32ALIGN) == 0U)) /* PRQA S 0306 */ /* MD_Rte_0306 */
    {
      uint32_least asize = num / sizeof(uint32);
      uint32_least rem = num & RTE_MEMCPY32ALIGN;
      for (i = 0; i < (asize - 3U); i += 4U)
      {
        adst[i] = asrc[i];
        adst[i+1U] = asrc[i+1U];
        adst[i+2U] = asrc[i+2U];
        adst[i+3U] = asrc[i+3U];
      }

      while (i < asize)
      {
        adst[i] = asrc[i];
        ++i;
      }
      i = num - rem;
    }
    else
    {
      for (i = 0; (i + 15U) < num; i += 16U)
      {
        dst[i] = src[i];
        dst[i+1U] = src[i+1U];
        dst[i+2U] = src[i+2U];
        dst[i+3U] = src[i+3U];
        dst[i+4U] = src[i+4U];
        dst[i+5U] = src[i+5U];
        dst[i+6U] = src[i+6U];
        dst[i+7U] = src[i+7U];
        dst[i+8U] = src[i+8U];
        dst[i+9U] = src[i+9U];
        dst[i+10U] = src[i+10U];
        dst[i+11U] = src[i+11U];
        dst[i+12U] = src[i+12U];
        dst[i+13U] = src[i+13U];
        dst[i+14U] = src[i+14U];
        dst[i+15U] = src[i+15U];
      }
    }

  }
  while (i < num)
  {
    dst[i] = src[i];
    ++i;
  }
}

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))ptr; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = 0;
  }
}

FUNC(void, RTE_CODE) SchM_Start(void)
{
  Rte_InitState = RTE_STATE_SCHM_START;
}

FUNC(void, RTE_CODE) SchM_Init(void)
{
  /* activate the tasks */
  (void)ActivateTask(QM_ComTask_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(QM_ComTask_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(QM_DiagTask_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(QM_MemTask_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(QM_Task_200ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Safety_WdgTask_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;
}

FUNC(void, RTE_CODE) SchM_StartTiming(void)
{
  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_QM_ComTask_5ms_5_5ms, RTE_MSEC_SystemTimer(5U) + (TickType)1U, RTE_MSEC_SystemTimer(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Safety_WdgTask_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_QM_ComTask_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_QM_DiagTask_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_QM_MemTask_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_QM_Task_200ms_0_200ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(200U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{
  /* activate the tasks */
  (void)ActivateTask(QM_Task_Init); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Safety_Task_200ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(Safety_Task_Init); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_QM_ComTask_5ms_0_5ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Safety_WdgTask_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_QM_ComTask_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Safety_Task_00_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Safety_Task_01_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_QM_DiagTask_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_QM_MemTask_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_QM_Task_00_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_QM_Task_01_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_QM_Task_200ms_0_200ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(200U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Safety_Task_200ms_0_200ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(200U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

  Rte_StartTiming_InitState = RTE_STATE_INIT;
  /* mode management initialization part 2 */
  Rte_OsApplication_QM_InternalEventFlag_OsApplication_QM_Set_Rte_Ev_Run1_CDD_GenericBswM_RE_UpdateNMState();
  (void)SetEvent(QM_Task_200ms, Rte_Ev_InternalEventHandling); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_INIT;

  return RTE_E_OK;
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
  Rte_StartTiming_InitState = RTE_STATE_UNINIT;
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_QM_ComTask_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_QM_ComTask_5ms_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_QM_DiagTask_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_QM_MemTask_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_QM_Task_00_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_QM_Task_01_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_QM_Task_200ms_0_200ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Safety_Task_00_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Safety_Task_01_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Safety_Task_200ms_0_200ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Safety_WdgTask_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_QM_ComTask_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_QM_ComTask_5ms_5_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_QM_DiagTask_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_QM_MemTask_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_QM_Task_200ms_0_200ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_Safety_WdgTask_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_UNINIT;
}

FUNC(void, RTE_CODE) Rte_InitMemory(void)
{
  Rte_InitState = RTE_STATE_UNINIT;
  Rte_StartTiming_InitState = RTE_STATE_UNINIT;

  Rte_InitMemory_OsApplication_QM();
  Rte_InitMemory_OsApplication_Safety();
  Rte_InitMemory_SystemApplication_OsCore0();
}


/**********************************************************************************************************************
 * COM-Callbacks for DataReceivedEvent triggered runnables, inter-ECU client/server communication, for queued com. and for Rx timeout / Rx inv. flag (reset)
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_APARequestSts_oBCM_FD_12_oFDCAN2_c58fc45d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_APARequestSts_oBCM_FD_12_oFDCAN2_c58fc45d_Rx, (&Rte_APARequestSts_oBCM_FD_12_oFDCAN2_c58fc45d_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ASCM_Stat_oASCM_FD_2_oFDCAN2_58854b4a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_ASCM_Stat_oASCM_FD_2_oFDCAN2_58854b4a_Rx, (&Rte_ASCM_Stat_oASCM_FD_2_oFDCAN2_58854b4a_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ASCM_SysFail_oASCM_FD_2_oFDCAN2_9d00e371_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_ASCM_SysFail_oASCM_FD_2_oFDCAN2_9d00e371_Rx, (&Rte_ASCM_SysFail_oASCM_FD_2_oFDCAN2_9d00e371_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Active_Park_Mode_oIPC_VEHICLE_SETUP_oFDCAN2_6a2a58c7_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_Active_Park_Mode_oIPC_VEHICLE_SETUP_oFDCAN2_6a2a58c7_Rx, (&Rte_Active_Park_Mode_oIPC_VEHICLE_SETUP_oFDCAN2_6a2a58c7_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Active_Park_Prox_Chime_oIPC_VEHICLE_SETUP_oFDCAN2_ae5aba94_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_Active_Park_Prox_Chime_oIPC_VEHICLE_SETUP_oFDCAN2_ae5aba94_Rx, (&Rte_Active_Park_Prox_Chime_oIPC_VEHICLE_SETUP_oFDCAN2_ae5aba94_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Altitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_89a927da_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint8 localAltitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_89a927da_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Altitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_89a927da_Rx, &localAltitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_89a927da_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Altitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_89a927da_Rx)) = localAltitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_89a927da_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN2_c6b9d212_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN2_c6b9d212_Rx, (&Rte_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN2_c6b9d212_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_BSM_THA_Brk_Resp_Sender = !Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_BSM_THA_Brk_Resp; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Backup_Cam_Delay_oIPC_VEHICLE_SETUP_oFDCAN2_4de26278_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_Backup_Cam_Delay_oIPC_VEHICLE_SETUP_oFDCAN2_4de26278_Rx, (&Rte_Backup_Cam_Delay_oIPC_VEHICLE_SETUP_oFDCAN2_4de26278_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Battery_Volt_1_oBCM_FD_3_oFDCAN2_c3a895dd_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localBattery_Volt_1_oBCM_FD_3_oFDCAN2_c3a895dd_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Battery_Volt_1_oBCM_FD_3_oFDCAN2_c3a895dd_Rx, &localBattery_Volt_1_oBCM_FD_3_oFDCAN2_c3a895dd_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Battery_Volt_1_oBCM_FD_3_oFDCAN2_c3a895dd_Rx)) = localBattery_Volt_1_oBCM_FD_3_oFDCAN2_c3a895dd_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Brk_Stat_oBRAKE_FD_2_oFDCAN2_1b647924_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Brk_Stat localBrk_Stat_oBRAKE_FD_2_oFDCAN2_1b647924_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Brk_Stat_oBRAKE_FD_2_oFDCAN2_1b647924_Rx, &localBrk_Stat_oBRAKE_FD_2_oFDCAN2_1b647924_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Brk_Stat_oBRAKE_FD_2_oFDCAN2_1b647924_Rx)) = localBrk_Stat_oBRAKE_FD_2_oFDCAN2_1b647924_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CM_TCH_STAT_oTELEMATIC_FD_5_oFDCAN2_64ce192d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_CM_TCH_STAT_oTELEMATIC_FD_5_oFDCAN2_64ce192d_Rx, (&Rte_CM_TCH_STAT_oTELEMATIC_FD_5_oFDCAN2_64ce192d_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CM_TCH_X_COORD_oTELEMATIC_FD_5_oFDCAN2_0177f5f2_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_CM_TCH_X_COORD_oTELEMATIC_FD_5_oFDCAN2_0177f5f2_Rx, (&Rte_CM_TCH_X_COORD_oTELEMATIC_FD_5_oFDCAN2_0177f5f2_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CM_TCH_Y_COORD_oTELEMATIC_FD_5_oFDCAN2_0f901d23_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_CM_TCH_Y_COORD_oTELEMATIC_FD_5_oFDCAN2_0f901d23_Rx, (&Rte_CM_TCH_Y_COORD_oTELEMATIC_FD_5_oFDCAN2_0f901d23_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CameraDisplaySts2_oTELEMATIC_FD_5_oFDCAN2_3ea6a9f0_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_CameraDisplaySts2_oTELEMATIC_FD_5_oFDCAN2_3ea6a9f0_Rx, (&Rte_CameraDisplaySts2_oTELEMATIC_FD_5_oFDCAN2_3ea6a9f0_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CmdIgnSts_oBCM_FD_10_oFDCAN2_06c30ef2_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_CmdIgnSts_oBCM_FD_10_oFDCAN2_06c30ef2_Rx, (&Rte_CmdIgnSts_oBCM_FD_10_oFDCAN2_06c30ef2_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_cb3619a3_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD01_BCM localCurrentCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_cb3619a3_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_cb3619a3_Rx, &localCurrentCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_cb3619a3_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_cb3619a3_Rx)) = localCurrentCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_cb3619a3_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_05d1101e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD01_SGW localCurrentCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_05d1101e_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_05d1101e_Rx, &localCurrentCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_05d1101e_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_05d1101e_Rx)) = localCurrentCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_05d1101e_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_8f973cbb_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD02_BCM localCurrentCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_8f973cbb_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_8f973cbb_Rx, &localCurrentCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_8f973cbb_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_8f973cbb_Rx)) = localCurrentCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_8f973cbb_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_3f8b7635_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD02_BSM2 localCurrentCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_3f8b7635_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_3f8b7635_Rx, &localCurrentCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_3f8b7635_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_3f8b7635_Rx)) = localCurrentCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_3f8b7635_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f804ab44_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD02_CADM2 localCurrentCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f804ab44_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f804ab44_Rx, &localCurrentCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f804ab44_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f804ab44_Rx)) = localCurrentCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f804ab44_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_277b5480_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD02_EPS localCurrentCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_277b5480_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_277b5480_Rx, &localCurrentCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_277b5480_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_277b5480_Rx)) = localCurrentCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_277b5480_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_146fe160_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD02_ORC localCurrentCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_146fe160_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_146fe160_Rx, &localCurrentCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_146fe160_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_146fe160_Rx)) = localCurrentCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_146fe160_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_41703506_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD02_SGW localCurrentCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_41703506_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_41703506_Rx, &localCurrentCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_41703506_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_41703506_Rx)) = localCurrentCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_41703506_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_e2caab79_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD02_TRLR_REV localCurrentCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_e2caab79_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_e2caab79_Rx, &localCurrentCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_e2caab79_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_e2caab79_Rx)) = localCurrentCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_e2caab79_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b3f7dfb3_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD03_BCM localCurrentCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b3f7dfb3_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b3f7dfb3_Rx, &localCurrentCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b3f7dfb3_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b3f7dfb3_Rx)) = localCurrentCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b3f7dfb3_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7d10d60e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD03_SGW localCurrentCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7d10d60e_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7d10d60e_Rx, &localCurrentCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7d10d60e_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7d10d60e_Rx)) = localCurrentCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7d10d60e_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_06d5768b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD04_BCM localCurrentCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_06d5768b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_06d5768b_Rx, &localCurrentCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_06d5768b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_06d5768b_Rx)) = localCurrentCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_06d5768b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_01c7ed17_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD08_SGW localCurrentCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_01c7ed17_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_01c7ed17_Rx, &localCurrentCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_01c7ed17_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_01c7ed17_Rx)) = localCurrentCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_01c7ed17_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0b36f8cf_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentCanNMState_FD11_SGW localCurrentCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0b36f8cf_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0b36f8cf_Rx, &localCurrentCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0b36f8cf_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0b36f8cf_Rx)) = localCurrentCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0b36f8cf_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b0c60e26_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD01_BCM localCurrentFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b0c60e26_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b0c60e26_Rx, &localCurrentFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b0c60e26_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b0c60e26_Rx)) = localCurrentFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_b0c60e26_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7e21079b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD01_SGW localCurrentFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7e21079b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7e21079b_Rx, &localCurrentFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7e21079b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7e21079b_Rx)) = localCurrentFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7e21079b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f4672b3e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD02_BCM localCurrentFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f4672b3e_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f4672b3e_Rx, &localCurrentFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f4672b3e_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f4672b3e_Rx)) = localCurrentFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f4672b3e_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_faace40c_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD02_BSM2 localCurrentFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_faace40c_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_faace40c_Rx, &localCurrentFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_faace40c_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_faace40c_Rx)) = localCurrentFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_faace40c_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_e88111b1_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD02_CADM2 localCurrentFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_e88111b1_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_e88111b1_Rx, &localCurrentFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_e88111b1_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_e88111b1_Rx)) = localCurrentFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_e88111b1_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_5c8b4305_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD02_EPS localCurrentFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_5c8b4305_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_5c8b4305_Rx, &localCurrentFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_5c8b4305_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_5c8b4305_Rx)) = localCurrentFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_5c8b4305_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_6f9ff6e5_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD02_ORC localCurrentFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_6f9ff6e5_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_6f9ff6e5_Rx, &localCurrentFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_6f9ff6e5_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_6f9ff6e5_Rx)) = localCurrentFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_6f9ff6e5_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3a802283_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD02_SGW localCurrentFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3a802283_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3a802283_Rx, &localCurrentFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3a802283_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3a802283_Rx)) = localCurrentFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3a802283_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_3b43d61f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD02_TRLR_REV localCurrentFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_3b43d61f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_3b43d61f_Rx, &localCurrentFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_3b43d61f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_3b43d61f_Rx)) = localCurrentFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_3b43d61f_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c807c836_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD03_BCM localCurrentFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c807c836_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c807c836_Rx, &localCurrentFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c807c836_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c807c836_Rx)) = localCurrentFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c807c836_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_06e0c18b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD03_SGW localCurrentFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_06e0c18b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_06e0c18b_Rx, &localCurrentFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_06e0c18b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_06e0c18b_Rx)) = localCurrentFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_06e0c18b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7d25610e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD04_BCM localCurrentFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7d25610e_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7d25610e_Rx, &localCurrentFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7d25610e_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7d25610e_Rx)) = localCurrentFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7d25610e_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7a37fa92_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD08_SGW localCurrentFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7a37fa92_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7a37fa92_Rx, &localCurrentFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7a37fa92_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7a37fa92_Rx)) = localCurrentFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7a37fa92_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_CurrentFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_70c6ef4a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      CurrentFailSts_FD11_SGW localCurrentFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_70c6ef4a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_CurrentFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_70c6ef4a_Rx, &localCurrentFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_70c6ef4a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_CurrentFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_70c6ef4a_Rx)) = localCurrentFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_70c6ef4a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3865098f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD01_BCM localDES_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3865098f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3865098f_Rx, &localDES_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3865098f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3865098f_Rx)) = localDES_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3865098f_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6820032_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD01_SGW localDES_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6820032_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6820032_Rx, &localDES_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6820032_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6820032_Rx)) = localDES_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6820032_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7cc42c97_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD02_BCM localDES_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7cc42c97_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7cc42c97_Rx, &localDES_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7cc42c97_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7cc42c97_Rx)) = localDES_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7cc42c97_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_1b0dfeac_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD02_BSM2 localDES_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_1b0dfeac_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_1b0dfeac_Rx, &localDES_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_1b0dfeac_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_1b0dfeac_Rx)) = localDES_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_1b0dfeac_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_bbe4b583_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD02_CADM2 localDES_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_bbe4b583_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_bbe4b583_Rx, &localDES_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_bbe4b583_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_bbe4b583_Rx)) = localDES_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_bbe4b583_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d42844ac_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD02_EPS localDES_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d42844ac_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d42844ac_Rx, &localDES_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d42844ac_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d42844ac_Rx)) = localDES_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d42844ac_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e73cf14c_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD02_ORC localDES_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e73cf14c_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e73cf14c_Rx, &localDES_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e73cf14c_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e73cf14c_Rx)) = localDES_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e73cf14c_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b223252a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD02_SGW localDES_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b223252a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b223252a_Rx, &localDES_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b223252a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b223252a_Rx)) = localDES_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b223252a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9554de37_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD02_TRLR_REV localDES_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9554de37_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9554de37_Rx, &localDES_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9554de37_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9554de37_Rx)) = localDES_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9554de37_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_40a4cf9f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD03_BCM localDES_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_40a4cf9f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_40a4cf9f_Rx, &localDES_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_40a4cf9f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_40a4cf9f_Rx)) = localDES_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_40a4cf9f_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e43c622_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD03_SGW localDES_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e43c622_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e43c622_Rx, &localDES_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e43c622_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e43c622_Rx)) = localDES_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e43c622_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f58666a7_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD04_BCM localDES_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f58666a7_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f58666a7_Rx, &localDES_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f58666a7_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f58666a7_Rx)) = localDES_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f58666a7_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f294fd3b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD08_SGW localDES_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f294fd3b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f294fd3b_Rx, &localDES_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f294fd3b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f294fd3b_Rx)) = localDES_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f294fd3b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DES_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f865e8e3_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DES_FD11_SGW localDES_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f865e8e3_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DES_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f865e8e3_Rx, &localDES_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f865e8e3_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DES_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f865e8e3_Rx)) = localDES_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f865e8e3_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DeltaTimestamp_IMUdata_oGLOB_NAV_FD_C2_oFDCAN2_bb3ce8c3_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DeltaTimestamp_IMUdata localDeltaTimestamp_IMUdata_oGLOB_NAV_FD_C2_oFDCAN2_bb3ce8c3_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DeltaTimestamp_IMUdata_oGLOB_NAV_FD_C2_oFDCAN2_bb3ce8c3_Rx, &localDeltaTimestamp_IMUdata_oGLOB_NAV_FD_C2_oFDCAN2_bb3ce8c3_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DeltaTimestamp_IMUdata_oGLOB_NAV_FD_C2_oFDCAN2_bb3ce8c3_Rx)) = localDeltaTimestamp_IMUdata_oGLOB_NAV_FD_C2_oFDCAN2_bb3ce8c3_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_01_oCFG_DATA_CODE_REQUEST_oFDCAN2_c824c64f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_01 localDigit_01_oCFG_DATA_CODE_REQUEST_oFDCAN2_c824c64f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_01_oCFG_DATA_CODE_REQUEST_oFDCAN2_c824c64f_Rx, &localDigit_01_oCFG_DATA_CODE_REQUEST_oFDCAN2_c824c64f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_01_oCFG_DATA_CODE_REQUEST_oFDCAN2_c824c64f_Rx)) = localDigit_01_oCFG_DATA_CODE_REQUEST_oFDCAN2_c824c64f_Rx;
    }
    /* scheduled trigger for runnables: RE_ProxiMgr_ConfigDataRSP */
    (void)SetEvent(Safety_Task_200ms, Rte_Ev_Run_SWC_ProxiConfigMgr_RE_ProxiMgr_ConfigDataRSP); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_02_oCFG_DATA_CODE_REQUEST_oFDCAN2_013bcef0_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_02 localDigit_02_oCFG_DATA_CODE_REQUEST_oFDCAN2_013bcef0_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_02_oCFG_DATA_CODE_REQUEST_oFDCAN2_013bcef0_Rx, &localDigit_02_oCFG_DATA_CODE_REQUEST_oFDCAN2_013bcef0_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_02_oCFG_DATA_CODE_REQUEST_oFDCAN2_013bcef0_Rx)) = localDigit_02_oCFG_DATA_CODE_REQUEST_oFDCAN2_013bcef0_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_03_oCFG_DATA_CODE_REQUEST_oFDCAN2_f0e1cb5a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_03 localDigit_03_oCFG_DATA_CODE_REQUEST_oFDCAN2_f0e1cb5a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_03_oCFG_DATA_CODE_REQUEST_oFDCAN2_f0e1cb5a_Rx, &localDigit_03_oCFG_DATA_CODE_REQUEST_oFDCAN2_f0e1cb5a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_03_oCFG_DATA_CODE_REQUEST_oFDCAN2_f0e1cb5a_Rx)) = localDigit_03_oCFG_DATA_CODE_REQUEST_oFDCAN2_f0e1cb5a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_04_oCFG_DATA_CODE_REQUEST_oFDCAN2_4874d9cf_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_04 localDigit_04_oCFG_DATA_CODE_REQUEST_oFDCAN2_4874d9cf_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_04_oCFG_DATA_CODE_REQUEST_oFDCAN2_4874d9cf_Rx, &localDigit_04_oCFG_DATA_CODE_REQUEST_oFDCAN2_4874d9cf_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_04_oCFG_DATA_CODE_REQUEST_oFDCAN2_4874d9cf_Rx)) = localDigit_04_oCFG_DATA_CODE_REQUEST_oFDCAN2_4874d9cf_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_05_oCFG_DATA_CODE_REQUEST_oFDCAN2_b9aedc65_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_05 localDigit_05_oCFG_DATA_CODE_REQUEST_oFDCAN2_b9aedc65_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_05_oCFG_DATA_CODE_REQUEST_oFDCAN2_b9aedc65_Rx, &localDigit_05_oCFG_DATA_CODE_REQUEST_oFDCAN2_b9aedc65_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_05_oCFG_DATA_CODE_REQUEST_oFDCAN2_b9aedc65_Rx)) = localDigit_05_oCFG_DATA_CODE_REQUEST_oFDCAN2_b9aedc65_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_06_oCFG_DATA_CODE_REQUEST_oFDCAN2_70b1d4da_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_06 localDigit_06_oCFG_DATA_CODE_REQUEST_oFDCAN2_70b1d4da_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_06_oCFG_DATA_CODE_REQUEST_oFDCAN2_70b1d4da_Rx, &localDigit_06_oCFG_DATA_CODE_REQUEST_oFDCAN2_70b1d4da_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_06_oCFG_DATA_CODE_REQUEST_oFDCAN2_70b1d4da_Rx)) = localDigit_06_oCFG_DATA_CODE_REQUEST_oFDCAN2_70b1d4da_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_07_oCFG_DATA_CODE_REQUEST_oFDCAN2_816bd170_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_07 localDigit_07_oCFG_DATA_CODE_REQUEST_oFDCAN2_816bd170_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_07_oCFG_DATA_CODE_REQUEST_oFDCAN2_816bd170_Rx, &localDigit_07_oCFG_DATA_CODE_REQUEST_oFDCAN2_816bd170_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_07_oCFG_DATA_CODE_REQUEST_oFDCAN2_816bd170_Rx)) = localDigit_07_oCFG_DATA_CODE_REQUEST_oFDCAN2_816bd170_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_08_oCFG_DATA_CODE_REQUEST_oFDCAN2_daeaf7b1_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_08 localDigit_08_oCFG_DATA_CODE_REQUEST_oFDCAN2_daeaf7b1_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_08_oCFG_DATA_CODE_REQUEST_oFDCAN2_daeaf7b1_Rx, &localDigit_08_oCFG_DATA_CODE_REQUEST_oFDCAN2_daeaf7b1_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_08_oCFG_DATA_CODE_REQUEST_oFDCAN2_daeaf7b1_Rx)) = localDigit_08_oCFG_DATA_CODE_REQUEST_oFDCAN2_daeaf7b1_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_09_oCFG_DATA_CODE_REQUEST_oFDCAN2_2b30f21b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_09 localDigit_09_oCFG_DATA_CODE_REQUEST_oFDCAN2_2b30f21b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_09_oCFG_DATA_CODE_REQUEST_oFDCAN2_2b30f21b_Rx, &localDigit_09_oCFG_DATA_CODE_REQUEST_oFDCAN2_2b30f21b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_09_oCFG_DATA_CODE_REQUEST_oFDCAN2_2b30f21b_Rx)) = localDigit_09_oCFG_DATA_CODE_REQUEST_oFDCAN2_2b30f21b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_10_oCFG_DATA_CODE_REQUEST_oFDCAN2_0f0c5316_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_10 localDigit_10_oCFG_DATA_CODE_REQUEST_oFDCAN2_0f0c5316_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_10_oCFG_DATA_CODE_REQUEST_oFDCAN2_0f0c5316_Rx, &localDigit_10_oCFG_DATA_CODE_REQUEST_oFDCAN2_0f0c5316_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_10_oCFG_DATA_CODE_REQUEST_oFDCAN2_0f0c5316_Rx)) = localDigit_10_oCFG_DATA_CODE_REQUEST_oFDCAN2_0f0c5316_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Digit_11_oCFG_DATA_CODE_REQUEST_oFDCAN2_fed656bc_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Digit_11 localDigit_11_oCFG_DATA_CODE_REQUEST_oFDCAN2_fed656bc_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Digit_11_oCFG_DATA_CODE_REQUEST_oFDCAN2_fed656bc_Rx, &localDigit_11_oCFG_DATA_CODE_REQUEST_oFDCAN2_fed656bc_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Digit_11_oCFG_DATA_CODE_REQUEST_oFDCAN2_fed656bc_Rx)) = localDigit_11_oCFG_DATA_CODE_REQUEST_oFDCAN2_fed656bc_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DriverDoorSts_oBCM_FD_9_oFDCAN2_5b5b4a2d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_DriverDoorSts_oBCM_FD_9_oFDCAN2_5b5b4a2d_Rx, (&Rte_DriverDoorSts_oBCM_FD_9_oFDCAN2_5b5b4a2d_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_DynamicGrid_oIPC_VEHICLE_SETUP_oFDCAN2_8defe0e1_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      DynamicGrid localDynamicGrid_oIPC_VEHICLE_SETUP_oFDCAN2_8defe0e1_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_DynamicGrid_oIPC_VEHICLE_SETUP_oFDCAN2_8defe0e1_Rx, &localDynamicGrid_oIPC_VEHICLE_SETUP_oFDCAN2_8defe0e1_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_DynamicGrid_oIPC_VEHICLE_SETUP_oFDCAN2_8defe0e1_Rx)) = localDynamicGrid_oIPC_VEHICLE_SETUP_oFDCAN2_8defe0e1_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ECM_THA_Resp_oENGINE_FD_7_oFDCAN2_4f167839_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_ECM_THA_Resp_oENGINE_FD_7_oFDCAN2_4f167839_Rx, (&Rte_ECM_THA_Resp_oENGINE_FD_7_oFDCAN2_4f167839_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN2_7dcf088b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN2_7dcf088b_Rx, (&Rte_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN2_7dcf088b_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_bf538820_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD01_BCM localEOL_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_bf538820_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_bf538820_Rx, &localEOL_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_bf538820_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_bf538820_Rx)) = localEOL_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_bf538820_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_71b4819d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD01_SGW localEOL_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_71b4819d_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_71b4819d_Rx, &localEOL_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_71b4819d_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_71b4819d_Rx)) = localEOL_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_71b4819d_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_fbf2ad38_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD02_BCM localEOL_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_fbf2ad38_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_fbf2ad38_Rx, &localEOL_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_fbf2ad38_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_fbf2ad38_Rx)) = localEOL_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_fbf2ad38_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a82d6a0a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD02_BSM2 localEOL_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a82d6a0a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a82d6a0a_Rx, &localEOL_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a82d6a0a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a82d6a0a_Rx)) = localEOL_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a82d6a0a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_b4db4a91_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD02_CADM2 localEOL_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_b4db4a91_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_b4db4a91_Rx, &localEOL_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_b4db4a91_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_b4db4a91_Rx)) = localEOL_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_b4db4a91_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_531ec503_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD02_EPS localEOL_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_531ec503_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_531ec503_Rx, &localEOL_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_531ec503_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_531ec503_Rx)) = localEOL_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_531ec503_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_600a70e3_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD02_ORC localEOL_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_600a70e3_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_600a70e3_Rx, &localEOL_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_600a70e3_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_600a70e3_Rx)) = localEOL_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_600a70e3_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3515a485_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD02_SGW localEOL_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3515a485_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3515a485_Rx, &localEOL_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3515a485_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3515a485_Rx)) = localEOL_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_3515a485_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_b23a15e1_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD02_TRLR_REV localEOL_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_b23a15e1_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_b23a15e1_Rx, &localEOL_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_b23a15e1_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_b23a15e1_Rx)) = localEOL_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_b23a15e1_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c7924e30_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD03_BCM localEOL_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c7924e30_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c7924e30_Rx, &localEOL_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c7924e30_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c7924e30_Rx)) = localEOL_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_c7924e30_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0975478d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD03_SGW localEOL_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0975478d_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0975478d_Rx, &localEOL_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0975478d_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0975478d_Rx)) = localEOL_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_0975478d_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_72b0e708_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD04_BCM localEOL_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_72b0e708_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_72b0e708_Rx, &localEOL_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_72b0e708_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_72b0e708_Rx)) = localEOL_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_72b0e708_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_75a27c94_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD08_SGW localEOL_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_75a27c94_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_75a27c94_Rx, &localEOL_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_75a27c94_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_75a27c94_Rx)) = localEOL_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_75a27c94_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EOL_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7f53694c_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EOL_FD11_SGW localEOL_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7f53694c_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EOL_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7f53694c_Rx, &localEOL_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7f53694c_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EOL_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7f53694c_Rx)) = localEOL_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_7f53694c_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EPBSts_oBRAKE_FD_4_oFDCAN2_4e811a74_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_EPBSts_oBRAKE_FD_4_oFDCAN2_4e811a74_Rx, (&Rte_EPBSts_oBRAKE_FD_4_oFDCAN2_4e811a74_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_EPBSts_Sender = !Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_EPBSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN2_70168af6_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EPS_SteeringTouchStat localEPS_SteeringTouchStat_oEPS_FD_2_oFDCAN2_70168af6_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN2_70168af6_Rx, &localEPS_SteeringTouchStat_oEPS_FD_2_oFDCAN2_70168af6_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN2_70168af6_Rx)) = localEPS_SteeringTouchStat_oEPS_FD_2_oFDCAN2_70168af6_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN2_a31e0e47_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EPS_SteeringTouq_Resp localEPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN2_a31e0e47_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN2_a31e0e47_Rx, &localEPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN2_a31e0e47_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN2_a31e0e47_Rx)) = localEPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN2_a31e0e47_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN2_0e3a0a14_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EPS_THA_DriverTorqueOverride localEPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN2_0e3a0a14_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN2_0e3a0a14_Rx, &localEPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN2_0e3a0a14_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN2_0e3a0a14_Rx)) = localEPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN2_0e3a0a14_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN2_2f8c0396_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EPS_THA_SteeringTorqueResp localEPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN2_2f8c0396_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN2_2f8c0396_Rx, &localEPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN2_2f8c0396_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN2_2f8c0396_Rx)) = localEPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN2_2f8c0396_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN2_b1b6db89_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      ESS_ENG_ST_W localESS_ENG_ST_W_oENGINE_FD_2_oFDCAN2_b1b6db89_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN2_b1b6db89_Rx, &localESS_ENG_ST_W_oENGINE_FD_2_oFDCAN2_b1b6db89_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN2_b1b6db89_Rx)) = localESS_ENG_ST_W_oENGINE_FD_2_oFDCAN2_b1b6db89_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_EngineSts_W_oENGINE_FD_2_oFDCAN2_7417ef03_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      EngineSts_W localEngineSts_W_oENGINE_FD_2_oFDCAN2_7417ef03_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_EngineSts_W_oENGINE_FD_2_oFDCAN2_7417ef03_Rx, &localEngineSts_W_oENGINE_FD_2_oFDCAN2_7417ef03_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_EngineSts_W_oENGINE_FD_2_oFDCAN2_7417ef03_Rx)) = localEngineSts_W_oENGINE_FD_2_oFDCAN2_7417ef03_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ExternalTemperature_oBCM_FD_9_oFDCAN2_fd16cd2c_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      ExternalTemperature localExternalTemperature_oBCM_FD_9_oFDCAN2_fd16cd2c_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_ExternalTemperature_oBCM_FD_9_oFDCAN2_fd16cd2c_Rx, &localExternalTemperature_oBCM_FD_9_oFDCAN2_fd16cd2c_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_ExternalTemperature_oBCM_FD_9_oFDCAN2_fd16cd2c_Rx)) = localExternalTemperature_oBCM_FD_9_oFDCAN2_fd16cd2c_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ACC_Systemsts_oADAS_FD_INFO_oFDCAN14_2086cf20_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_ACC_Systemsts localFD14_ACC_Systemsts_oADAS_FD_INFO_oFDCAN14_2086cf20_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_ACC_Systemsts_oADAS_FD_INFO_oFDCAN14_2086cf20_Rx, &localFD14_ACC_Systemsts_oADAS_FD_INFO_oFDCAN14_2086cf20_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_ACC_Systemsts_oADAS_FD_INFO_oFDCAN14_2086cf20_Rx)) = localFD14_ACC_Systemsts_oADAS_FD_INFO_oFDCAN14_2086cf20_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN14_cecdbc25_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN14_cecdbc25_Rx, (&Rte_FD14_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN14_cecdbc25_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_BrkPdl_Stat localFD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx, &localFD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx)) = localFD14_BrkPdl_Stat_oBRAKE_FD_7_oFDCAN14_d494c4ed_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_BrkTrq_Driver_oBRAKE_FD_1_oFDCAN14_f4f61916_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_BrkTrq_Driver localFD14_BrkTrq_Driver_oBRAKE_FD_1_oFDCAN14_f4f61916_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_BrkTrq_Driver_oBRAKE_FD_1_oFDCAN14_f4f61916_Rx, &localFD14_BrkTrq_Driver_oBRAKE_FD_1_oFDCAN14_f4f61916_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_BrkTrq_Driver_oBRAKE_FD_1_oFDCAN14_f4f61916_Rx)) = localFD14_BrkTrq_Driver_oBRAKE_FD_1_oFDCAN14_f4f61916_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_BrkTrq localFD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx, &localFD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx)) = localFD14_BrkTrq_oBRAKE_FD_1_oFDCAN14_a585a712_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_Brk_Stat localFD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx, &localFD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx)) = localFD14_Brk_Stat_oBRAKE_FD_2_oFDCAN14_0735ec77_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ECM_THA_Resp_oENGINE_FD_7_oFDCAN14_284045ab_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_ECM_THA_Resp_oENGINE_FD_7_oFDCAN14_284045ab_Rx, (&Rte_FD14_ECM_THA_Resp_oENGINE_FD_7_oFDCAN14_284045ab_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN14_994d6c00_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN14_994d6c00_Rx, (&Rte_FD14_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN14_994d6c00_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPBSts_oBRAKE_FD_4_oFDCAN14_c0ca10e6_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_EPBSts_oBRAKE_FD_4_oFDCAN14_c0ca10e6_Rx, (&Rte_FD14_EPBSts_oBRAKE_FD_4_oFDCAN14_c0ca10e6_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPS_HandsOnRecognition_oEPS_FD_1_oFDCAN14_58e651a9_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_EPS_HandsOnRecognition localFD14_EPS_HandsOnRecognition_oEPS_FD_1_oFDCAN14_58e651a9_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_EPS_HandsOnRecognition_oEPS_FD_1_oFDCAN14_58e651a9_Rx, &localFD14_EPS_HandsOnRecognition_oEPS_FD_1_oFDCAN14_58e651a9_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_EPS_HandsOnRecognition_oEPS_FD_1_oFDCAN14_58e651a9_Rx)) = localFD14_EPS_HandsOnRecognition_oEPS_FD_1_oFDCAN14_58e651a9_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cae7cd32_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_EPS_SteeringTouchStat localFD14_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cae7cd32_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cae7cd32_Rx, &localFD14_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cae7cd32_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cae7cd32_Rx)) = localFD14_EPS_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cae7cd32_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN14_765246ac_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_EPS_SteeringTouq_Resp localFD14_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN14_765246ac_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN14_765246ac_Rx, &localFD14_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN14_765246ac_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN14_765246ac_Rx)) = localFD14_EPS_SteeringTouq_Resp_oEPS_FD_2_oFDCAN14_765246ac_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN14_2abac25d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_EPS_THA_DriverTorqueOverride localFD14_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN14_2abac25d_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN14_2abac25d_Rx, &localFD14_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN14_2abac25d_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN14_2abac25d_Rx)) = localFD14_EPS_THA_DriverTorqueOverride_oEPS_FD_2_oFDCAN14_2abac25d_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN14_c35bede9_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_EPS_THA_SteeringTorqueResp localFD14_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN14_c35bede9_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN14_c35bede9_Rx, &localFD14_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN14_c35bede9_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN14_c35bede9_Rx)) = localFD14_EPS_THA_SteeringTorqueResp_oEPS_FD_2_oFDCAN14_c35bede9_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ESC_TRSC_Brk_Resp_oBRAKE_FD_5_oFDCAN14_2f38fcaf_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_ESC_TRSC_Brk_Resp_oBRAKE_FD_5_oFDCAN14_2f38fcaf_Rx, (&Rte_FD14_ESC_TRSC_Brk_Resp_oBRAKE_FD_5_oFDCAN14_2f38fcaf_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN14_e3df5684_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN14_e3df5684_Rx, (&Rte_FD14_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN14_e3df5684_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_EngineSts_W localFD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx, &localFD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx)) = localFD14_EngineSts_W_oENGINE_FD_2_oFDCAN14_da6e6207_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ExternalBrkRequestsDisabled_oBRAKE_FD_1_oFDCAN14_3622ec06_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_ExternalBrkRequestsDisabled localFD14_ExternalBrkRequestsDisabled_oBRAKE_FD_1_oFDCAN14_3622ec06_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_ExternalBrkRequestsDisabled_oBRAKE_FD_1_oFDCAN14_3622ec06_Rx, &localFD14_ExternalBrkRequestsDisabled_oBRAKE_FD_1_oFDCAN14_3622ec06_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_ExternalBrkRequestsDisabled_oBRAKE_FD_1_oFDCAN14_3622ec06_Rx)) = localFD14_ExternalBrkRequestsDisabled_oBRAKE_FD_1_oFDCAN14_3622ec06_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_HAS_Status_oADAS_FD_INFO_oFDCAN14_368cf8df_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_HAS_Status localFD14_HAS_Status_oADAS_FD_INFO_oFDCAN14_368cf8df_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_HAS_Status_oADAS_FD_INFO_oFDCAN14_368cf8df_Rx, &localFD14_HAS_Status_oADAS_FD_INFO_oFDCAN14_368cf8df_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_HAS_Status_oADAS_FD_INFO_oFDCAN14_368cf8df_Rx)) = localFD14_HAS_Status_oADAS_FD_INFO_oFDCAN14_368cf8df_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d701d2d3_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LHFWheelSpeed localFD14_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d701d2d3_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d701d2d3_Rx, &localFD14_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d701d2d3_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d701d2d3_Rx)) = localFD14_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d701d2d3_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_c079cbbf_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LHF_FastPulseCounter localFD14_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_c079cbbf_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_c079cbbf_Rx, &localFD14_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_c079cbbf_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_c079cbbf_Rx)) = localFD14_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_c079cbbf_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LHF_Spin localFD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx, &localFD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx)) = localFD14_LHF_Spin_oBRAKE_FD_3_oFDCAN14_d2937a4c_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_3a28d00b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LHF_WheelSensorFailSts localFD14_LHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_3a28d00b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_3a28d00b_Rx, &localFD14_LHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_3a28d00b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_3a28d00b_Rx)) = localFD14_LHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_3a28d00b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_bbd2a610_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LHRWheelSpeed localFD14_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_bbd2a610_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_bbd2a610_Rx, &localFD14_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_bbd2a610_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_bbd2a610_Rx)) = localFD14_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_bbd2a610_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_129a4c4c_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LHR_FastPulseCounter localFD14_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_129a4c4c_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_129a4c4c_Rx, &localFD14_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_129a4c4c_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_129a4c4c_Rx)) = localFD14_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_129a4c4c_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHR_Spin_oBRAKE_FD_3_oFDCAN14_eda6ba5c_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LHR_Spin localFD14_LHR_Spin_oBRAKE_FD_3_oFDCAN14_eda6ba5c_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LHR_Spin_oBRAKE_FD_3_oFDCAN14_eda6ba5c_Rx, &localFD14_LHR_Spin_oBRAKE_FD_3_oFDCAN14_eda6ba5c_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LHR_Spin_oBRAKE_FD_3_oFDCAN14_eda6ba5c_Rx)) = localFD14_LHR_Spin_oBRAKE_FD_3_oFDCAN14_eda6ba5c_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_7665a615_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LHR_WheelSensorFailSts localFD14_LHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_7665a615_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_7665a615_Rx, &localFD14_LHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_7665a615_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_7665a615_Rx)) = localFD14_LHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_7665a615_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LatAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_b6857dc3_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LatAccelerationFailSts_BSM localFD14_LatAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_b6857dc3_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LatAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_b6857dc3_Rx, &localFD14_LatAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_b6857dc3_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LatAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_b6857dc3_Rx)) = localFD14_LatAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_b6857dc3_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_045731ef_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LatAccelerationOffset_BSM localFD14_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_045731ef_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_045731ef_Rx, &localFD14_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_045731ef_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_045731ef_Rx)) = localFD14_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_045731ef_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_79c02fd1_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LatAcceleration_BSM localFD14_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_79c02fd1_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_79c02fd1_Rx, &localFD14_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_79c02fd1_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_79c02fd1_Rx)) = localFD14_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_79c02fd1_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LongAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_7b4ee1d6_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LongAccelerationFailSts_BSM localFD14_LongAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_7b4ee1d6_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LongAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_7b4ee1d6_Rx, &localFD14_LongAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_7b4ee1d6_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LongAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_7b4ee1d6_Rx)) = localFD14_LongAccelerationFailSts_BSM_oBRAKE_FD_2_oFDCAN14_7b4ee1d6_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_18cdb71a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LongAccelerationOffset_BSM localFD14_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_18cdb71a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_18cdb71a_Rx, &localFD14_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_18cdb71a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_18cdb71a_Rx)) = localFD14_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN14_18cdb71a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_b347f969_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LongAcceleration_BSM localFD14_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_b347f969_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_b347f969_Rx, &localFD14_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_b347f969_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_b347f969_Rx)) = localFD14_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN14_b347f969_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LwsAngleType_oEPS_FD_1_oFDCAN14_8f61bc22_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LwsAngleType localFD14_LwsAngleType_oEPS_FD_1_oFDCAN14_8f61bc22_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LwsAngleType_oEPS_FD_1_oFDCAN14_8f61bc22_Rx, &localFD14_LwsAngleType_oEPS_FD_1_oFDCAN14_8f61bc22_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LwsAngleType_oEPS_FD_1_oFDCAN14_8f61bc22_Rx)) = localFD14_LwsAngleType_oEPS_FD_1_oFDCAN14_8f61bc22_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LwsAngle localFD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx, &localFD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx)) = localFD14_LwsAngle_oEPS_FD_1_oFDCAN14_d27eb4fc_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_LwsSpeed_oEPS_FD_1_oFDCAN14_6930c8f0_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_LwsSpeed localFD14_LwsSpeed_oEPS_FD_1_oFDCAN14_6930c8f0_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_LwsSpeed_oEPS_FD_1_oFDCAN14_6930c8f0_Rx, &localFD14_LwsSpeed_oEPS_FD_1_oFDCAN14_6930c8f0_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_LwsSpeed_oEPS_FD_1_oFDCAN14_6930c8f0_Rx)) = localFD14_LwsSpeed_oEPS_FD_1_oFDCAN14_6930c8f0_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_PAM_Brk_Rq_RspSts_oBRAKE_FD_7_oFDCAN14_65c28072_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_PAM_Brk_Rq_RspSts localFD14_PAM_Brk_Rq_RspSts_oBRAKE_FD_7_oFDCAN14_65c28072_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_PAM_Brk_Rq_RspSts_oBRAKE_FD_7_oFDCAN14_65c28072_Rx, &localFD14_PAM_Brk_Rq_RspSts_oBRAKE_FD_7_oFDCAN14_65c28072_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_PAM_Brk_Rq_RspSts_oBRAKE_FD_7_oFDCAN14_65c28072_Rx)) = localFD14_PAM_Brk_Rq_RspSts_oBRAKE_FD_7_oFDCAN14_65c28072_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ParkingGearShiftReq_BSM_oBRAKE_FD_2_oFDCAN14_45df8c18_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_ParkingGearShiftReq_BSM localFD14_ParkingGearShiftReq_BSM_oBRAKE_FD_2_oFDCAN14_45df8c18_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_ParkingGearShiftReq_BSM_oBRAKE_FD_2_oFDCAN14_45df8c18_Rx, &localFD14_ParkingGearShiftReq_BSM_oBRAKE_FD_2_oFDCAN14_45df8c18_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_ParkingGearShiftReq_BSM_oBRAKE_FD_2_oFDCAN14_45df8c18_Rx)) = localFD14_ParkingGearShiftReq_BSM_oBRAKE_FD_2_oFDCAN14_45df8c18_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_ParkingInterventionSts_oBRAKE_FD_2_oFDCAN14_9b11ef29_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_ParkingInterventionSts localFD14_ParkingInterventionSts_oBRAKE_FD_2_oFDCAN14_9b11ef29_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_ParkingInterventionSts_oBRAKE_FD_2_oFDCAN14_9b11ef29_Rx, &localFD14_ParkingInterventionSts_oBRAKE_FD_2_oFDCAN14_9b11ef29_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_ParkingInterventionSts_oBRAKE_FD_2_oFDCAN14_9b11ef29_Rx)) = localFD14_ParkingInterventionSts_oBRAKE_FD_2_oFDCAN14_9b11ef29_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_PdlPosActual localFD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx, &localFD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx)) = localFD14_PdlPosActual_oENGINE_FD_5_oFDCAN14_7bc8f3ea_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN14_7bd7d6fa_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_REF_VEH_SPEED localFD14_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN14_7bd7d6fa_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN14_7bd7d6fa_Rx, &localFD14_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN14_7bd7d6fa_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN14_7bd7d6fa_Rx)) = localFD14_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN14_7bd7d6fa_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d6d9a235_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_RHFWheelSpeed localFD14_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d6d9a235_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d6d9a235_Rx, &localFD14_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d6d9a235_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d6d9a235_Rx)) = localFD14_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN14_d6d9a235_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_aa1206ae_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_RHF_FastPulseCounter localFD14_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_aa1206ae_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_aa1206ae_Rx, &localFD14_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_aa1206ae_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_aa1206ae_Rx)) = localFD14_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_aa1206ae_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHF_Spin_oBRAKE_FD_3_oFDCAN14_6be6e272_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_RHF_Spin localFD14_RHF_Spin_oBRAKE_FD_3_oFDCAN14_6be6e272_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_RHF_Spin_oBRAKE_FD_3_oFDCAN14_6be6e272_Rx, &localFD14_RHF_Spin_oBRAKE_FD_3_oFDCAN14_6be6e272_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_RHF_Spin_oBRAKE_FD_3_oFDCAN14_6be6e272_Rx)) = localFD14_RHF_Spin_oBRAKE_FD_3_oFDCAN14_6be6e272_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_8c24277d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_RHF_WheelSensorFailSts localFD14_RHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_8c24277d_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_RHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_8c24277d_Rx, &localFD14_RHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_8c24277d_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_RHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_8c24277d_Rx)) = localFD14_RHF_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_8c24277d_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_ba0ad6f6_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_RHRWheelSpeed localFD14_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_ba0ad6f6_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_ba0ad6f6_Rx, &localFD14_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_ba0ad6f6_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_ba0ad6f6_Rx)) = localFD14_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN14_ba0ad6f6_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_78f1815d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_RHR_FastPulseCounter localFD14_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_78f1815d_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_78f1815d_Rx, &localFD14_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_78f1815d_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_78f1815d_Rx)) = localFD14_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN14_78f1815d_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHR_Spin_oBRAKE_FD_3_oFDCAN14_54d32262_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_RHR_Spin localFD14_RHR_Spin_oBRAKE_FD_3_oFDCAN14_54d32262_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_RHR_Spin_oBRAKE_FD_3_oFDCAN14_54d32262_Rx, &localFD14_RHR_Spin_oBRAKE_FD_3_oFDCAN14_54d32262_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_RHR_Spin_oBRAKE_FD_3_oFDCAN14_54d32262_Rx)) = localFD14_RHR_Spin_oBRAKE_FD_3_oFDCAN14_54d32262_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_RHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_c0695163_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_RHR_WheelSensorFailSts localFD14_RHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_c0695163_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_RHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_c0695163_Rx, &localFD14_RHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_c0695163_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_RHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_c0695163_Rx)) = localFD14_RHR_WheelSensorFailSts_oBRAKE_FD_3_oFDCAN14_c0695163_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_SPM_Lat_Ctrl_ResponseSts_oEPS_FD_1_oFDCAN14_35f1e4d0_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_SPM_Lat_Ctrl_ResponseSts localFD14_SPM_Lat_Ctrl_ResponseSts_oEPS_FD_1_oFDCAN14_35f1e4d0_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_SPM_Lat_Ctrl_ResponseSts_oEPS_FD_1_oFDCAN14_35f1e4d0_Rx, &localFD14_SPM_Lat_Ctrl_ResponseSts_oEPS_FD_1_oFDCAN14_35f1e4d0_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_SPM_Lat_Ctrl_ResponseSts_oEPS_FD_1_oFDCAN14_35f1e4d0_Rx)) = localFD14_SPM_Lat_Ctrl_ResponseSts_oEPS_FD_1_oFDCAN14_35f1e4d0_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_Slope_oBRAKE_FD_2_oFDCAN14_a6806d2f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_Slope localFD14_Slope_oBRAKE_FD_2_oFDCAN14_a6806d2f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_Slope_oBRAKE_FD_2_oFDCAN14_a6806d2f_Rx, &localFD14_Slope_oBRAKE_FD_2_oFDCAN14_a6806d2f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_Slope_oBRAKE_FD_2_oFDCAN14_a6806d2f_Rx)) = localFD14_Slope_oBRAKE_FD_2_oFDCAN14_a6806d2f_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_Steering_Column_Torque_oEPS_FD_1_oFDCAN14_485a089f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_Steering_Column_Torque localFD14_Steering_Column_Torque_oEPS_FD_1_oFDCAN14_485a089f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_Steering_Column_Torque_oEPS_FD_1_oFDCAN14_485a089f_Rx, &localFD14_Steering_Column_Torque_oEPS_FD_1_oFDCAN14_485a089f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_Steering_Column_Torque_oEPS_FD_1_oFDCAN14_485a089f_Rx)) = localFD14_Steering_Column_Torque_oEPS_FD_1_oFDCAN14_485a089f_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_THA_SteeringTouchStat localFD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx, &localFD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx)) = localFD14_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN14_cefbaafe_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_VehicleSpeedVSOSig_B2_oBRAKE2_FD_1_oFDCAN14_1870b968_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_VehicleSpeedVSOSig_B2 localFD14_VehicleSpeedVSOSig_B2_oBRAKE2_FD_1_oFDCAN14_1870b968_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_VehicleSpeedVSOSig_B2_oBRAKE2_FD_1_oFDCAN14_1870b968_Rx, &localFD14_VehicleSpeedVSOSig_B2_oBRAKE2_FD_1_oFDCAN14_1870b968_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_VehicleSpeedVSOSig_B2_oBRAKE2_FD_1_oFDCAN14_1870b968_Rx)) = localFD14_VehicleSpeedVSOSig_B2_oBRAKE2_FD_1_oFDCAN14_1870b968_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN14_66b2f28a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_VehicleSpeedVSOSig localFD14_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN14_66b2f28a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN14_66b2f28a_Rx, &localFD14_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN14_66b2f28a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN14_66b2f28a_Rx)) = localFD14_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN14_66b2f28a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN14_4aa14bb7_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_VehicleStandStillSts localFD14_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN14_4aa14bb7_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN14_4aa14bb7_Rx, &localFD14_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN14_4aa14bb7_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN14_4aa14bb7_Rx)) = localFD14_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN14_4aa14bb7_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_YawRateFailSts_BSM_oBRAKE_FD_2_oFDCAN14_07cbb027_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_YawRateFailSts_BSM localFD14_YawRateFailSts_BSM_oBRAKE_FD_2_oFDCAN14_07cbb027_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_YawRateFailSts_BSM_oBRAKE_FD_2_oFDCAN14_07cbb027_Rx, &localFD14_YawRateFailSts_BSM_oBRAKE_FD_2_oFDCAN14_07cbb027_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_YawRateFailSts_BSM_oBRAKE_FD_2_oFDCAN14_07cbb027_Rx)) = localFD14_YawRateFailSts_BSM_oBRAKE_FD_2_oFDCAN14_07cbb027_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FD14_YawRate_BSM_oBRAKE_FD_2_oFDCAN14_feebc52b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FD14_YawRate_BSM localFD14_YawRate_BSM_oBRAKE_FD_2_oFDCAN14_feebc52b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FD14_YawRate_BSM_oBRAKE_FD_2_oFDCAN14_feebc52b_Rx, &localFD14_YawRate_BSM_oBRAKE_FD_2_oFDCAN14_feebc52b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FD14_YawRate_BSM_oBRAKE_FD_2_oFDCAN14_feebc52b_Rx)) = localFD14_YawRate_BSM_oBRAKE_FD_2_oFDCAN14_feebc52b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FL_Lvl_Adj_oASCM_FD_1_oFDCAN2_959485e3_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FL_Lvl_Adj localFL_Lvl_Adj_oASCM_FD_1_oFDCAN2_959485e3_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FL_Lvl_Adj_oASCM_FD_1_oFDCAN2_959485e3_Rx, &localFL_Lvl_Adj_oASCM_FD_1_oFDCAN2_959485e3_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FL_Lvl_Adj_oASCM_FD_1_oFDCAN2_959485e3_Rx)) = localFL_Lvl_Adj_oASCM_FD_1_oFDCAN2_959485e3_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FL_Lvl localFL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx, &localFL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx)) = localFL_Lvl_oASCM_FD_1_oFDCAN2_724f5049_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FR_Lvl_Adj_oASCM_FD_1_oFDCAN2_86d8b295_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FR_Lvl_Adj localFR_Lvl_Adj_oASCM_FD_1_oFDCAN2_86d8b295_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FR_Lvl_Adj_oASCM_FD_1_oFDCAN2_86d8b295_Rx, &localFR_Lvl_Adj_oASCM_FD_1_oFDCAN2_86d8b295_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FR_Lvl_Adj_oASCM_FD_1_oFDCAN2_86d8b295_Rx)) = localFR_Lvl_Adj_oASCM_FD_1_oFDCAN2_86d8b295_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FR_Lvl_oASCM_FD_1_oFDCAN2_6f14419a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      FR_Lvl localFR_Lvl_oASCM_FD_1_oFDCAN2_6f14419a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_FR_Lvl_oASCM_FD_1_oFDCAN2_6f14419a_Rx, &localFR_Lvl_oASCM_FD_1_oFDCAN2_6f14419a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_FR_Lvl_oASCM_FD_1_oFDCAN2_6f14419a_Rx)) = localFR_Lvl_oASCM_FD_1_oFDCAN2_6f14419a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_FT_PAMRequestSts_oBCM_FD_12_oFDCAN2_eca5b16e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_FT_PAMRequestSts_oBCM_FD_12_oFDCAN2_eca5b16e_Rx, (&Rte_FT_PAMRequestSts_oBCM_FD_12_oFDCAN2_eca5b16e_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Fwrd_Cam_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_195fae0b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_Fwrd_Cam_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_195fae0b_Rx, (&Rte_Fwrd_Cam_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_195fae0b_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GearEngagedForDisplay localGearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx, &localGearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx)) = localGearEngagedForDisplay_oTRANSM_FD_2_oFDCAN2_375443ce_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GearEngaged_oTRANSM_FD_4_oFDCAN2_d9ac16c5_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_GearEngaged_oTRANSM_FD_4_oFDCAN2_d9ac16c5_Rx, (&Rte_GearEngaged_oTRANSM_FD_4_oFDCAN2_d9ac16c5_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_aaf66243_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD01_BCM localGenericFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_aaf66243_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_aaf66243_Rx, &localGenericFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_aaf66243_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_aaf66243_Rx)) = localGenericFailSts_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_aaf66243_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_64116bfe_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD01_SGW localGenericFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_64116bfe_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_64116bfe_Rx, &localGenericFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_64116bfe_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_64116bfe_Rx)) = localGenericFailSts_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_64116bfe_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_ee57475b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD02_BCM localGenericFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_ee57475b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_ee57475b_Rx, &localGenericFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_ee57475b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_ee57475b_Rx)) = localGenericFailSts_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_ee57475b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a6224cad_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD02_BSM2 localGenericFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a6224cad_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a6224cad_Rx, &localGenericFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a6224cad_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a6224cad_Rx)) = localGenericFailSts_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a6224cad_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_8790eb4d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD02_CADM2 localGenericFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_8790eb4d_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_8790eb4d_Rx, &localGenericFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_8790eb4d_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_8790eb4d_Rx)) = localGenericFailSts_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_8790eb4d_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_46bb2f60_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD02_EPS localGenericFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_46bb2f60_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_46bb2f60_Rx, &localGenericFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_46bb2f60_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_46bb2f60_Rx)) = localGenericFailSts_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_46bb2f60_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_75af9a80_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD02_ORC localGenericFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_75af9a80_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_75af9a80_Rx, &localGenericFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_75af9a80_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_75af9a80_Rx)) = localGenericFailSts_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_75af9a80_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_20b04ee6_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD02_SGW localGenericFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_20b04ee6_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_20b04ee6_Rx, &localGenericFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_20b04ee6_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_20b04ee6_Rx)) = localGenericFailSts_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_20b04ee6_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_f0b9fb66_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD02_TRLR_REV localGenericFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_f0b9fb66_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_f0b9fb66_Rx, &localGenericFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_f0b9fb66_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_f0b9fb66_Rx)) = localGenericFailSts_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_f0b9fb66_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_d237a453_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD03_BCM localGenericFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_d237a453_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_d237a453_Rx, &localGenericFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_d237a453_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_d237a453_Rx)) = localGenericFailSts_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_d237a453_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_1cd0adee_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD03_SGW localGenericFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_1cd0adee_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_1cd0adee_Rx, &localGenericFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_1cd0adee_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_1cd0adee_Rx)) = localGenericFailSts_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_1cd0adee_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_67150d6b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD04_BCM localGenericFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_67150d6b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_67150d6b_Rx, &localGenericFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_67150d6b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_67150d6b_Rx)) = localGenericFailSts_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_67150d6b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_600796f7_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD08_SGW localGenericFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_600796f7_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_600796f7_Rx, &localGenericFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_600796f7_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_600796f7_Rx)) = localGenericFailSts_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_600796f7_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_GenericFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_6af6832f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      GenericFailSts_FD11_SGW localGenericFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_6af6832f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_GenericFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_6af6832f_Rx, &localGenericFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_6af6832f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_GenericFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_6af6832f_Rx)) = localGenericFailSts_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_6af6832f_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      HAS_Status_C2 localHAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx, &localHAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_HAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx)) = localHAS_Status_C2_oADAS_FD_INFO_C2_oFDCAN2_5f0dae63_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_HU_TRSC_EnableBtn_Sts_oTELEMATIC_FD_11_oFDCAN2_298c059b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_HU_TRSC_EnableBtn_Sts_oTELEMATIC_FD_11_oFDCAN2_298c059b_Rx, (&Rte_HU_TRSC_EnableBtn_Sts_oTELEMATIC_FD_11_oFDCAN2_298c059b_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Heading_Angle_C2_oGLOB_NAV_FD_C2_oFDCAN2_3c56c554_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localHeading_Angle_C2_oGLOB_NAV_FD_C2_oFDCAN2_3c56c554_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Heading_Angle_C2_oGLOB_NAV_FD_C2_oFDCAN2_3c56c554_Rx, &localHeading_Angle_C2_oGLOB_NAV_FD_C2_oFDCAN2_3c56c554_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Heading_Angle_C2_oGLOB_NAV_FD_C2_oFDCAN2_3c56c554_Rx)) = localHeading_Angle_C2_oGLOB_NAV_FD_C2_oFDCAN2_3c56c554_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ITBM_TrlrStat_oBCM_FD_29_oFDCAN2_144a42ca_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_ITBM_TrlrStat_oBCM_FD_29_oFDCAN2_144a42ca_Rx, (&Rte_ITBM_TrlrStat_oBCM_FD_29_oFDCAN2_144a42ca_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_IgnitionOnCounter_oBCM_FD_7_oFDCAN2_72afbff6_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      IgnitionOnCounter localIgnitionOnCounter_oBCM_FD_7_oFDCAN2_72afbff6_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_IgnitionOnCounter_oBCM_FD_7_oFDCAN2_72afbff6_Rx, &localIgnitionOnCounter_oBCM_FD_7_oFDCAN2_72afbff6_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_IgnitionOnCounter_oBCM_FD_7_oFDCAN2_72afbff6_Rx)) = localIgnitionOnCounter_oBCM_FD_7_oFDCAN2_72afbff6_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_01eb70e0_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localLHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_01eb70e0_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_01eb70e0_Rx, &localLHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_01eb70e0_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_01eb70e0_Rx)) = localLHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_01eb70e0_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_1316f7bd_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      LHF_FastPulseCounter localLHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_1316f7bd_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_1316f7bd_Rx, &localLHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_1316f7bd_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_1316f7bd_Rx)) = localLHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_1316f7bd_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LHF_Spin_oBRAKE_FD_3_oFDCAN2_ddb3a606_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      LHF_Spin localLHF_Spin_oBRAKE_FD_3_oFDCAN2_ddb3a606_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LHF_Spin_oBRAKE_FD_3_oFDCAN2_ddb3a606_Rx, &localLHF_Spin_oBRAKE_FD_3_oFDCAN2_ddb3a606_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LHF_Spin_oBRAKE_FD_3_oFDCAN2_ddb3a606_Rx)) = localLHF_Spin_oBRAKE_FD_3_oFDCAN2_ddb3a606_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LHRDoorSts_oBCM_FD_9_oFDCAN2_6106f88b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_LHRDoorSts_oBCM_FD_9_oFDCAN2_6106f88b_Rx, (&Rte_LHRDoorSts_oBCM_FD_9_oFDCAN2_6106f88b_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d40a5eb4_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localLHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d40a5eb4_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d40a5eb4_Rx, &localLHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d40a5eb4_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d40a5eb4_Rx)) = localLHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d40a5eb4_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_fd14f99b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      LHR_FastPulseCounter localLHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_fd14f99b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_fd14f99b_Rx, &localLHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_fd14f99b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_fd14f99b_Rx)) = localLHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_fd14f99b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LHR_Spin_oBRAKE_FD_3_oFDCAN2_5d756ba0_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      LHR_Spin localLHR_Spin_oBRAKE_FD_3_oFDCAN2_5d756ba0_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LHR_Spin_oBRAKE_FD_3_oFDCAN2_5d756ba0_Rx, &localLHR_Spin_oBRAKE_FD_3_oFDCAN2_5d756ba0_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LHR_Spin_oBRAKE_FD_3_oFDCAN2_5d756ba0_Rx)) = localLHR_Spin_oBRAKE_FD_3_oFDCAN2_5d756ba0_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LanguageSelection_oIPC_VEHICLE_SETUP_oFDCAN2_99c6c76e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_LanguageSelection_oIPC_VEHICLE_SETUP_oFDCAN2_99c6c76e_Rx, (&Rte_LanguageSelection_oIPC_VEHICLE_SETUP_oFDCAN2_99c6c76e_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_18f7c44e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint8 localLatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_18f7c44e_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_18f7c44e_Rx, &localLatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_18f7c44e_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_18f7c44e_Rx)) = localLatAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_18f7c44e_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_318e470e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      LatAcceleration_BSM localLatAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_318e470e_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_318e470e_Rx, &localLatAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_318e470e_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LatAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_318e470e_Rx)) = localLatAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_318e470e_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LatAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_faefb913_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localLatAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_faefb913_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LatAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_faefb913_Rx, &localLatAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_faefb913_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LatAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_faefb913_Rx)) = localLatAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_faefb913_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Latitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_3a18037a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint8 localLatitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_3a18037a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Latitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_3a18037a_Rx, &localLatitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_3a18037a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Latitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_3a18037a_Rx)) = localLatitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_3a18037a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_a123ae38_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint8 localLongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_a123ae38_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_a123ae38_Rx, &localLongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_a123ae38_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_a123ae38_Rx)) = localLongAccelerationOffset_BSM_oBRAKE_FD_3_oFDCAN2_a123ae38_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_f132a23a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      LongAcceleration_BSM localLongAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_f132a23a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_f132a23a_Rx, &localLongAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_f132a23a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LongAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_f132a23a_Rx)) = localLongAcceleration_BSM_oBRAKE_FD_2_oFDCAN2_f132a23a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LongAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_38530c91_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localLongAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_38530c91_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LongAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_38530c91_Rx, &localLongAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_38530c91_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LongAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_38530c91_Rx)) = localLongAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_38530c91_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Longitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1b6c4b2a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint8 localLongitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1b6c4b2a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Longitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1b6c4b2a_Rx, &localLongitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1b6c4b2a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Longitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1b6c4b2a_Rx)) = localLongitude_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1b6c4b2a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LwsAngleType_oEPS_FD_1_oFDCAN2_aea1ae81_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      LwsAngleType localLwsAngleType_oEPS_FD_1_oFDCAN2_aea1ae81_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LwsAngleType_oEPS_FD_1_oFDCAN2_aea1ae81_Rx, &localLwsAngleType_oEPS_FD_1_oFDCAN2_aea1ae81_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LwsAngleType_oEPS_FD_1_oFDCAN2_aea1ae81_Rx)) = localLwsAngleType_oEPS_FD_1_oFDCAN2_aea1ae81_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LwsAngle_oEPS_FD_1_oFDCAN2_4dcc502d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      LwsAngle localLwsAngle_oEPS_FD_1_oFDCAN2_4dcc502d_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LwsAngle_oEPS_FD_1_oFDCAN2_4dcc502d_Rx, &localLwsAngle_oEPS_FD_1_oFDCAN2_4dcc502d_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LwsAngle_oEPS_FD_1_oFDCAN2_4dcc502d_Rx)) = localLwsAngle_oEPS_FD_1_oFDCAN2_4dcc502d_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_LwsSpeed_oEPS_FD_1_oFDCAN2_08f75f98_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      LwsSpeed localLwsSpeed_oEPS_FD_1_oFDCAN2_08f75f98_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_LwsSpeed_oEPS_FD_1_oFDCAN2_08f75f98_Rx, &localLwsSpeed_oEPS_FD_1_oFDCAN2_08f75f98_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_LwsSpeed_oEPS_FD_1_oFDCAN2_08f75f98_Rx)) = localLwsSpeed_oEPS_FD_1_oFDCAN2_08f75f98_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_MRM_STATUS_C2_oADAS_FD_INFO_C2_oFDCAN2_8ba84d40_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      MRM_STATUS_C2 localMRM_STATUS_C2_oADAS_FD_INFO_C2_oFDCAN2_8ba84d40_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_MRM_STATUS_C2_oADAS_FD_INFO_C2_oFDCAN2_8ba84d40_Rx, &localMRM_STATUS_C2_oADAS_FD_INFO_C2_oFDCAN2_8ba84d40_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_MRM_STATUS_C2_oADAS_FD_INFO_C2_oFDCAN2_8ba84d40_Rx)) = localMRM_STATUS_C2_oADAS_FD_INFO_C2_oFDCAN2_8ba84d40_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_OperationalModeSts_oBCM_FD_2_oFDCAN2_92d9b16a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      OperationalModeSts localOperationalModeSts_oBCM_FD_2_oFDCAN2_92d9b16a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_OperationalModeSts_oBCM_FD_2_oFDCAN2_92d9b16a_Rx, &localOperationalModeSts_oBCM_FD_2_oFDCAN2_92d9b16a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_OperationalModeSts_oBCM_FD_2_oFDCAN2_92d9b16a_Rx)) = localOperationalModeSts_oBCM_FD_2_oFDCAN2_92d9b16a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PAMRequestSts_oBCM_FD_12_oFDCAN2_006058fe_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_PAMRequestSts_oBCM_FD_12_oFDCAN2_006058fe_Rx, (&Rte_PAMRequestSts_oBCM_FD_12_oFDCAN2_006058fe_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PamChimeVolumeFront_oIPC_VEHICLE_SETUP_oFDCAN2_6b01781e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_PamChimeVolumeFront_oIPC_VEHICLE_SETUP_oFDCAN2_6b01781e_Rx, (&Rte_PamChimeVolumeFront_oIPC_VEHICLE_SETUP_oFDCAN2_6b01781e_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PamChimeVolumeRear_oIPC_VEHICLE_SETUP_oFDCAN2_f55f4149_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_PamChimeVolumeRear_oIPC_VEHICLE_SETUP_oFDCAN2_f55f4149_Rx, (&Rte_PamChimeVolumeRear_oIPC_VEHICLE_SETUP_oFDCAN2_f55f4149_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PdlPosActual_oENGINE_FD_5_oFDCAN2_743309cb_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PdlPosActual localPdlPosActual_oENGINE_FD_5_oFDCAN2_743309cb_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PdlPosActual_oENGINE_FD_5_oFDCAN2_743309cb_Rx, &localPdlPosActual_oENGINE_FD_5_oFDCAN2_743309cb_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PdlPosActual_oENGINE_FD_5_oFDCAN2_743309cb_Rx)) = localPdlPosActual_oENGINE_FD_5_oFDCAN2_743309cb_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PitchRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_3e30fc55_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localPitchRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_3e30fc55_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PitchRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_3e30fc55_Rx, &localPitchRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_3e30fc55_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PitchRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_3e30fc55_Rx)) = localPitchRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_3e30fc55_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Pitch_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1cc85bc5_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint8 localPitch_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1cc85bc5_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Pitch_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1cc85bc5_Rx, &localPitch_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1cc85bc5_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Pitch_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1cc85bc5_Rx)) = localPitch_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_1cc85bc5_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_99b0bece_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD01_BCM localPreviousCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_99b0bece_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_99b0bece_Rx, &localPreviousCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_99b0bece_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_99b0bece_Rx)) = localPreviousCanNMState_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_99b0bece_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_5757b773_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD01_SGW localPreviousCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_5757b773_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_5757b773_Rx, &localPreviousCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_5757b773_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_5757b773_Rx)) = localPreviousCanNMState_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_5757b773_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_dd119bd6_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD02_BCM localPreviousCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_dd119bd6_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_dd119bd6_Rx, &localPreviousCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_dd119bd6_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_dd119bd6_Rx)) = localPreviousCanNMState_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_dd119bd6_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a76a0712_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD02_BSM2 localPreviousCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a76a0712_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a76a0712_Rx, &localPreviousCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a76a0712_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a76a0712_Rx)) = localPreviousCanNMState_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_a76a0712_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_05c3c06a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD02_CADM2 localPreviousCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_05c3c06a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_05c3c06a_Rx, &localPreviousCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_05c3c06a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_05c3c06a_Rx)) = localPreviousCanNMState_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_05c3c06a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_75fdf3ed_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD02_EPS localPreviousCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_75fdf3ed_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_75fdf3ed_Rx, &localPreviousCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_75fdf3ed_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_75fdf3ed_Rx)) = localPreviousCanNMState_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_75fdf3ed_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_46e9460d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD02_ORC localPreviousCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_46e9460d_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_46e9460d_Rx, &localPreviousCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_46e9460d_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_46e9460d_Rx)) = localPreviousCanNMState_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_46e9460d_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_13f6926b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD02_SGW localPreviousCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_13f6926b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_13f6926b_Rx, &localPreviousCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_13f6926b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_13f6926b_Rx)) = localPreviousCanNMState_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_13f6926b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_6708bf5f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD02_TRLR_REV localPreviousCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_6708bf5f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_6708bf5f_Rx, &localPreviousCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_6708bf5f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_6708bf5f_Rx)) = localPreviousCanNMState_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_6708bf5f_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_e17178de_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD03_BCM localPreviousCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_e17178de_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_e17178de_Rx, &localPreviousCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_e17178de_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_e17178de_Rx)) = localPreviousCanNMState_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_e17178de_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_2f967163_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD03_SGW localPreviousCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_2f967163_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_2f967163_Rx, &localPreviousCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_2f967163_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_2f967163_Rx)) = localPreviousCanNMState_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_2f967163_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_5453d1e6_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD04_BCM localPreviousCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_5453d1e6_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_5453d1e6_Rx, &localPreviousCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_5453d1e6_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_5453d1e6_Rx)) = localPreviousCanNMState_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_5453d1e6_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_53414a7a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD08_SGW localPreviousCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_53414a7a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_53414a7a_Rx, &localPreviousCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_53414a7a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_53414a7a_Rx)) = localPreviousCanNMState_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_53414a7a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PreviousCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_59b05fa2_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      PreviousCanNMState_FD11_SGW localPreviousCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_59b05fa2_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_PreviousCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_59b05fa2_Rx, &localPreviousCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_59b05fa2_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_PreviousCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_59b05fa2_Rx)) = localPreviousCanNMState_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_59b05fa2_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_PsngrDoorSts_oBCM_FD_9_oFDCAN2_661d805a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_PsngrDoorSts_oBCM_FD_9_oFDCAN2_661d805a_Rx, (&Rte_PsngrDoorSts_oBCM_FD_9_oFDCAN2_661d805a_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN2_6b1619cb_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localREF_VEH_SPEED_oBRAKE_FD_1_oFDCAN2_6b1619cb_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN2_6b1619cb_Rx, &localREF_VEH_SPEED_oBRAKE_FD_1_oFDCAN2_6b1619cb_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_REF_VEH_SPEED_oBRAKE_FD_1_oFDCAN2_6b1619cb_Rx)) = localREF_VEH_SPEED_oBRAKE_FD_1_oFDCAN2_6b1619cb_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_02ea90a1_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localRHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_02ea90a1_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_02ea90a1_Rx, &localRHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_02ea90a1_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_02ea90a1_Rx)) = localRHFWheelSpeed_oBRAKE_FD_3_oFDCAN2_02ea90a1_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_c8fb14ac_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      RHF_FastPulseCounter localRHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_c8fb14ac_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_c8fb14ac_Rx, &localRHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_c8fb14ac_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_c8fb14ac_Rx)) = localRHF_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_c8fb14ac_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RHF_Spin_oBRAKE_FD_3_oFDCAN2_ceff9170_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      RHF_Spin localRHF_Spin_oBRAKE_FD_3_oFDCAN2_ceff9170_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RHF_Spin_oBRAKE_FD_3_oFDCAN2_ceff9170_Rx, &localRHF_Spin_oBRAKE_FD_3_oFDCAN2_ceff9170_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RHF_Spin_oBRAKE_FD_3_oFDCAN2_ceff9170_Rx)) = localRHF_Spin_oBRAKE_FD_3_oFDCAN2_ceff9170_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RHRDoorSts_oBCM_FD_9_oFDCAN2_724acffd_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_RHRDoorSts_oBCM_FD_9_oFDCAN2_724acffd_Rx, (&Rte_RHRDoorSts_oBCM_FD_9_oFDCAN2_724acffd_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d70bbef5_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localRHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d70bbef5_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d70bbef5_Rx, &localRHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d70bbef5_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d70bbef5_Rx)) = localRHRWheelSpeed_oBRAKE_FD_3_oFDCAN2_d70bbef5_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_26f91a8a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      RHR_FastPulseCounter localRHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_26f91a8a_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_26f91a8a_Rx, &localRHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_26f91a8a_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_26f91a8a_Rx)) = localRHR_FastPulseCounter_oBRAKE_FD_3_oFDCAN2_26f91a8a_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RHR_Spin_oBRAKE_FD_3_oFDCAN2_4e395cd6_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      RHR_Spin localRHR_Spin_oBRAKE_FD_3_oFDCAN2_4e395cd6_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RHR_Spin_oBRAKE_FD_3_oFDCAN2_4e395cd6_Rx, &localRHR_Spin_oBRAKE_FD_3_oFDCAN2_4e395cd6_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RHR_Spin_oBRAKE_FD_3_oFDCAN2_4e395cd6_Rx)) = localRHR_Spin_oBRAKE_FD_3_oFDCAN2_4e395cd6_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RHatchSts_oBCM_FD_9_oFDCAN2_9f16b516_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_RHatchSts_oBCM_FD_9_oFDCAN2_9f16b516_Rx, (&Rte_RHatchSts_oBCM_FD_9_oFDCAN2_9f16b516_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RL_Lvl_Adj_oASCM_FD_1_oFDCAN2_44326a37_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      RL_Lvl_Adj localRL_Lvl_Adj_oASCM_FD_1_oFDCAN2_44326a37_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RL_Lvl_Adj_oASCM_FD_1_oFDCAN2_44326a37_Rx, &localRL_Lvl_Adj_oASCM_FD_1_oFDCAN2_44326a37_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RL_Lvl_Adj_oASCM_FD_1_oFDCAN2_44326a37_Rx)) = localRL_Lvl_Adj_oASCM_FD_1_oFDCAN2_44326a37_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RL_Lvl_oASCM_FD_1_oFDCAN2_d1e53ddc_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      RL_Lvl localRL_Lvl_oASCM_FD_1_oFDCAN2_d1e53ddc_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RL_Lvl_oASCM_FD_1_oFDCAN2_d1e53ddc_Rx, &localRL_Lvl_oASCM_FD_1_oFDCAN2_d1e53ddc_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RL_Lvl_oASCM_FD_1_oFDCAN2_d1e53ddc_Rx)) = localRL_Lvl_oASCM_FD_1_oFDCAN2_d1e53ddc_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RR_Lvl_Adj_oASCM_FD_1_oFDCAN2_577e5d41_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      RR_Lvl_Adj localRR_Lvl_Adj_oASCM_FD_1_oFDCAN2_577e5d41_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RR_Lvl_Adj_oASCM_FD_1_oFDCAN2_577e5d41_Rx, &localRR_Lvl_Adj_oASCM_FD_1_oFDCAN2_577e5d41_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RR_Lvl_Adj_oASCM_FD_1_oFDCAN2_577e5d41_Rx)) = localRR_Lvl_Adj_oASCM_FD_1_oFDCAN2_577e5d41_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RR_Lvl_oASCM_FD_1_oFDCAN2_ccbe2c0f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      RR_Lvl localRR_Lvl_oASCM_FD_1_oFDCAN2_ccbe2c0f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RR_Lvl_oASCM_FD_1_oFDCAN2_ccbe2c0f_Rx, &localRR_Lvl_oASCM_FD_1_oFDCAN2_ccbe2c0f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RR_Lvl_oASCM_FD_1_oFDCAN2_ccbe2c0f_Rx)) = localRR_Lvl_oASCM_FD_1_oFDCAN2_ccbe2c0f_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Rear_Brk_Asst_oIPC_VEHICLE_SETUP_oFDCAN2_96e3f1cb_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_Rear_Brk_Asst_oIPC_VEHICLE_SETUP_oFDCAN2_96e3f1cb_Rx, (&Rte_Rear_Brk_Asst_oIPC_VEHICLE_SETUP_oFDCAN2_96e3f1cb_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RemStActvSts_oBCM_FD_2_oFDCAN2_fb4ede64_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      RemStActvSts localRemStActvSts_oBCM_FD_2_oFDCAN2_fb4ede64_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RemStActvSts_oBCM_FD_2_oFDCAN2_fb4ede64_Rx, &localRemStActvSts_oBCM_FD_2_oFDCAN2_fb4ede64_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RemStActvSts_oBCM_FD_2_oFDCAN2_fb4ede64_Rx)) = localRemStActvSts_oBCM_FD_2_oFDCAN2_fb4ede64_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_RollRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_d526080b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localRollRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_d526080b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_RollRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_d526080b_Rx, &localRollRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_d526080b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_RollRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_d526080b_Rx)) = localRollRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_d526080b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Roll_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_90f031c2_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint8 localRoll_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_90f031c2_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Roll_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_90f031c2_Rx, &localRoll_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_90f031c2_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Roll_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_90f031c2_Rx)) = localRoll_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_90f031c2_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_SBR1RowDriverSeatSts_oORC_FD_1_oFDCAN2_bc99e8d7_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_SBR1RowDriverSeatSts_oORC_FD_1_oFDCAN2_bc99e8d7_Rx, (&Rte_SBR1RowDriverSeatSts_oORC_FD_1_oFDCAN2_bc99e8d7_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_SBR1RowDriverSeatSts_Sender = !Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_SBR1RowDriverSeatSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_SVC_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_3eb27f57_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_SVC_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_3eb27f57_Rx, (&Rte_SVC_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_3eb27f57_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ShiftLeverPositionReq_oAGSM_FD_2_oFDCAN2_dff8c8a2_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_ShiftLeverPositionReq_oAGSM_FD_2_oFDCAN2_dff8c8a2_Rx, (&Rte_ShiftLeverPositionReq_oAGSM_FD_2_oFDCAN2_dff8c8a2_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_ShiftLeverPosition_oTRANSM_FD_4_oFDCAN2_e41ef7f4_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_ShiftLeverPosition_oTRANSM_FD_4_oFDCAN2_e41ef7f4_Rx, (&Rte_ShiftLeverPosition_oTRANSM_FD_4_oFDCAN2_e41ef7f4_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_Shifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      Shifter_ADAS_Inhibit localShifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_Shifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx, &localShifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_Shifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx)) = localShifter_ADAS_Inhibit_oAGSM_FD_2_oFDCAN2_633e22f5_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3841343a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3841343a_Rx, (&Rte_StayActiveSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_3841343a_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6a63d87_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6a63d87_Rx, (&Rte_StayActiveSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f6a63d87_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7ce01122_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7ce01122_Rx, (&Rte_StayActiveSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_7ce01122_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dad7e864_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dad7e864_Rx, (&Rte_StayActiveSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dad7e864_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_4c139c4e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_4c139c4e_Rx, (&Rte_StayActiveSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_4c139c4e_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d40c7919_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d40c7919_Rx, (&Rte_StayActiveSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_d40c7919_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e718ccf9_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e718ccf9_Rx, (&Rte_StayActiveSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_e718ccf9_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b207189f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b207189f_Rx, (&Rte_StayActiveSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_b207189f_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_5fc9d563_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_5fc9d563_Rx, (&Rte_StayActiveSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_5fc9d563_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_4080f22a_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_4080f22a_Rx, (&Rte_StayActiveSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_4080f22a_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e67fb97_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e67fb97_Rx, (&Rte_StayActiveSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_8e67fb97_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f5a25b12_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f5a25b12_Rx, (&Rte_StayActiveSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_f5a25b12_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f2b0c08e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f2b0c08e_Rx, (&Rte_StayActiveSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f2b0c08e_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_StayActiveSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f841d556_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_StayActiveSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f841d556_Rx, (&Rte_StayActiveSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_f841d556_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TCASERANGESTATUS_oDRIVETRAIN_FD_3_oFDCAN2_eee864ec_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_TCASERANGESTATUS_oDRIVETRAIN_FD_3_oFDCAN2_eee864ec_Rx, (&Rte_TCASERANGESTATUS_oDRIVETRAIN_FD_3_oFDCAN2_eee864ec_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TGW_CAMERA_DISP_STAT_oTELEMATIC_FD_14_oFDCAN2_9304ed4e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_TGW_CAMERA_DISP_STAT_oTELEMATIC_FD_14_oFDCAN2_9304ed4e_Rx, (&Rte_TGW_CAMERA_DISP_STAT_oTELEMATIC_FD_14_oFDCAN2_9304ed4e_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT_Sender = !Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN2_b7575370_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      THA_SteeringTouchStat localTHA_SteeringTouchStat_oEPS_FD_2_oFDCAN2_b7575370_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN2_b7575370_Rx, &localTHA_SteeringTouchStat_oEPS_FD_2_oFDCAN2_b7575370_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_THA_SteeringTouchStat_oEPS_FD_2_oFDCAN2_b7575370_Rx)) = localTHA_SteeringTouchStat_oEPS_FD_2_oFDCAN2_b7575370_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TRANS_ADAS_Inhibit_oTRANSM_FD_1_oFDCAN2_6ec0c415_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      TRANS_ADAS_Inhibit localTRANS_ADAS_Inhibit_oTRANSM_FD_1_oFDCAN2_6ec0c415_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_TRANS_ADAS_Inhibit_oTRANSM_FD_1_oFDCAN2_6ec0c415_Rx, &localTRANS_ADAS_Inhibit_oTRANSM_FD_1_oFDCAN2_6ec0c415_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_TRANS_ADAS_Inhibit_oTRANSM_FD_1_oFDCAN2_6ec0c415_Rx)) = localTRANS_ADAS_Inhibit_oTRANSM_FD_1_oFDCAN2_6ec0c415_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TRSC_CenterBtn_Sts_oTRSKM_FD_1_oFDCAN2_08058c70_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_TRSC_CenterBtn_Sts_oTRSKM_FD_1_oFDCAN2_08058c70_Rx, (&Rte_TRSC_CenterBtn_Sts_oTRSKM_FD_1_oFDCAN2_08058c70_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_CenterBtn_Sts_Sender = !Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_CenterBtn_Sts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TRSC_EnableBtn_Sts_oTRSKM_FD_1_oFDCAN2_e08a4639_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_TRSC_EnableBtn_Sts_oTRSKM_FD_1_oFDCAN2_e08a4639_Rx, (&Rte_TRSC_EnableBtn_Sts_oTRSKM_FD_1_oFDCAN2_e08a4639_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_EnableBtn_Sts_Sender = !Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_EnableBtn_Sts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TRSC_RawKnob_oTRSKM_FD_1_oFDCAN2_88488965_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_TRSC_RawKnob_oTRSKM_FD_1_oFDCAN2_88488965_Rx, (&Rte_TRSC_RawKnob_oTRSKM_FD_1_oFDCAN2_88488965_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_RawKnob_Sender = !Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_VCANRx_RpFromComFD02Rx_TRSC_RawKnob; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      TargetGear localTargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_TargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx, &localTargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_TargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx)) = localTargetGear_oTRANSM_FD_1_oFDCAN2_b75950f9_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      TotalOdometer localTotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_TotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx, &localTotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_TotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx)) = localTotalOdometer_oIPC_FD_1_oFDCAN2_602313ac_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      TrailerConnectionSts localTrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_TrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx, &localTrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_TrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx)) = localTrailerConnectionSts_oBCM_FD_27_oFDCAN2_e828ec43_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TransmissionSailingSts_oTRANSM_FD_1_oFDCAN2_86af8834_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      TransmissionSailingSts localTransmissionSailingSts_oTRANSM_FD_1_oFDCAN2_86af8834_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_TransmissionSailingSts_oTRANSM_FD_1_oFDCAN2_86af8834_Rx, &localTransmissionSailingSts_oTRANSM_FD_1_oFDCAN2_86af8834_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_TransmissionSailingSts_oTRANSM_FD_1_oFDCAN2_86af8834_Rx)) = localTransmissionSailingSts_oTRANSM_FD_1_oFDCAN2_86af8834_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_TurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      TurnIndicatorSts localTurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_TurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx, &localTurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_TurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx)) = localTurnIndicatorSts_oBCM_FD_2_oFDCAN2_8b65568f_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_VIN_DATA_oVIN_oFDCAN2_c66224e9_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    {
      (void)Com_ReceiveSignal(ComConf_ComSignal_VIN_DATA_oVIN_oFDCAN2_c66224e9_Rx, (Rte_VIN_DATA_oVIN_oFDCAN2_c66224e9_Rx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    }
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_VIN_MSG_oVIN_oFDCAN2_f39912b4_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      VIN_MSG localVIN_MSG_oVIN_oFDCAN2_f39912b4_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_VIN_MSG_oVIN_oFDCAN2_f39912b4_Rx, &localVIN_MSG_oVIN_oFDCAN2_f39912b4_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_VIN_MSG_oVIN_oFDCAN2_f39912b4_Rx)) = localVIN_MSG_oVIN_oFDCAN2_f39912b4_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN2_53fecdc7_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      VehicleSpeedVSOSig localVehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN2_53fecdc7_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN2_53fecdc7_Rx, &localVehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN2_53fecdc7_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_VehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN2_53fecdc7_Rx)) = localVehicleSpeedVSOSig_oBRAKE_FD_2_oFDCAN2_53fecdc7_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN2_ae5f13a6_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      VehicleStandStillSts localVehicleStandStillSts_oBRAKE_FD_1_oFDCAN2_ae5f13a6_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN2_ae5f13a6_Rx, &localVehicleStandStillSts_oBRAKE_FD_1_oFDCAN2_ae5f13a6_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_VehicleStandStillSts_oBRAKE_FD_1_oFDCAN2_ae5f13a6_Rx)) = localVehicleStandStillSts_oBRAKE_FD_1_oFDCAN2_ae5f13a6_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_VerticalAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_10e58c6b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localVerticalAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_10e58c6b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_VerticalAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_10e58c6b_Rx, &localVerticalAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_10e58c6b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_VerticalAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_10e58c6b_Rx)) = localVerticalAcceleration_C2_oGLOB_NAV_FD_C2_oFDCAN2_10e58c6b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD01_ADCM_oPDC_INFO_FD_ADCM_oFDCAN2_bce36ee5_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD01_ADCM localWakeupSource_FD01_ADCM_oPDC_INFO_FD_ADCM_oFDCAN2_bce36ee5_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD01_ADCM_oPDC_INFO_FD_ADCM_oFDCAN2_bce36ee5_Rx, &localWakeupSource_FD01_ADCM_oPDC_INFO_FD_ADCM_oFDCAN2_bce36ee5_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD01_ADCM_oPDC_INFO_FD_ADCM_oFDCAN2_bce36ee5_Rx)) = localWakeupSource_FD01_ADCM_oPDC_INFO_FD_ADCM_oFDCAN2_bce36ee5_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_603c89e8_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD01_BCM localWakeupSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_603c89e8_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_603c89e8_Rx, &localWakeupSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_603c89e8_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_603c89e8_Rx)) = localWakeupSource_FD01_BCM_oPDC_INFO_FD_BCM_oFDCAN2_603c89e8_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aedb8055_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD01_SGW localWakeupSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aedb8055_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aedb8055_Rx, &localWakeupSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aedb8055_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aedb8055_Rx)) = localWakeupSource_FD01_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aedb8055_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_249dacf0_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD02_BCM localWakeupSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_249dacf0_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_249dacf0_Rx, &localWakeupSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_249dacf0_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_249dacf0_Rx)) = localWakeupSource_FD02_BCM_oPDC_INFO_FD_BCM_oFDCAN2_249dacf0_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dc09d8b5_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD02_BSM2 localWakeupSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dc09d8b5_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dc09d8b5_Rx, &localWakeupSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dc09d8b5_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dc09d8b5_Rx)) = localWakeupSource_FD02_BSM2_oPDC_INFO_FD_BSM2_oFDCAN2_dc09d8b5_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f2e95e62_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD02_CADM2 localWakeupSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f2e95e62_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f2e95e62_Rx, &localWakeupSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f2e95e62_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f2e95e62_Rx)) = localWakeupSource_FD02_CADM2_oPDC_INFO_FD_CADM2_oFDCAN2_f2e95e62_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_8c71c4cb_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD02_EPS localWakeupSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_8c71c4cb_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_8c71c4cb_Rx, &localWakeupSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_8c71c4cb_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_8c71c4cb_Rx)) = localWakeupSource_FD02_EPS_oPDC_INFO_FD_EPS_oFDCAN2_8c71c4cb_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_bf65712b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD02_ORC localWakeupSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_bf65712b_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_bf65712b_Rx, &localWakeupSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_bf65712b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_bf65712b_Rx)) = localWakeupSource_FD02_ORC_oPDC_INFO_FD_ORC_oFDCAN2_bf65712b_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_ea7aa54d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD02_SGW localWakeupSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_ea7aa54d_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_ea7aa54d_Rx, &localWakeupSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_ea7aa54d_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_ea7aa54d_Rx)) = localWakeupSource_FD02_SGW_oPDC_INFO_FD_SGW_oFDCAN2_ea7aa54d_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9a698e4c_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD02_TRLR_REV localWakeupSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9a698e4c_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9a698e4c_Rx, &localWakeupSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9a698e4c_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9a698e4c_Rx)) = localWakeupSource_FD02_TRLR_REV_oPDC_INFO_FD_TRLR_REV_oFDCAN2_9a698e4c_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_18fd4ff8_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD03_BCM localWakeupSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_18fd4ff8_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_18fd4ff8_Rx, &localWakeupSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_18fd4ff8_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_18fd4ff8_Rx)) = localWakeupSource_FD03_BCM_oPDC_INFO_FD_BCM_oFDCAN2_18fd4ff8_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_d61a4645_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD03_SGW localWakeupSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_d61a4645_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_d61a4645_Rx, &localWakeupSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_d61a4645_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_d61a4645_Rx)) = localWakeupSource_FD03_SGW_oPDC_INFO_FD_SGW_oFDCAN2_d61a4645_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_addfe6c0_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD04_BCM localWakeupSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_addfe6c0_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_addfe6c0_Rx, &localWakeupSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_addfe6c0_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_addfe6c0_Rx)) = localWakeupSource_FD04_BCM_oPDC_INFO_FD_BCM_oFDCAN2_addfe6c0_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aacd7d5c_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD08_SGW localWakeupSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aacd7d5c_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aacd7d5c_Rx, &localWakeupSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aacd7d5c_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aacd7d5c_Rx)) = localWakeupSource_FD08_SGW_oPDC_INFO_FD_SGW_oFDCAN2_aacd7d5c_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_WakeupSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_a03c6884_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      WakeupSource_FD11_SGW localWakeupSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_a03c6884_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_WakeupSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_a03c6884_Rx, &localWakeupSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_a03c6884_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_WakeupSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_a03c6884_Rx)) = localWakeupSource_FD11_SGW_oPDC_INFO_FD_SGW_oFDCAN2_a03c6884_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_YawRate_BSM_oBRAKE_FD_2_oFDCAN2_64569af1_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      YawRate_BSM localYawRate_BSM_oBRAKE_FD_2_oFDCAN2_64569af1_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_YawRate_BSM_oBRAKE_FD_2_oFDCAN2_64569af1_Rx, &localYawRate_BSM_oBRAKE_FD_2_oFDCAN2_64569af1_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_YawRate_BSM_oBRAKE_FD_2_oFDCAN2_64569af1_Rx)) = localYawRate_BSM_oBRAKE_FD_2_oFDCAN2_64569af1_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_YawRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_f8e96c1f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint16 localYawRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_f8e96c1f_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_YawRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_f8e96c1f_Rx, &localYawRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_f8e96c1f_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_YawRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_f8e96c1f_Rx)) = localYawRate_C2_oGLOB_NAV_FD_C2_oFDCAN2_f8e96c1f_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

FUNC(void, RTE_CODE) Rte_COMCbk_YawRate_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_c10121c7_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    {
      uint8 localYawRate_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_c10121c7_Rx;
      (void)Com_ReceiveSignal(ComConf_ComSignal_YawRate_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_c10121c7_Rx, &localYawRate_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_c10121c7_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
      *((&Rte_YawRate_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_c10121c7_Rx)) = localYawRate_RMSE_C2_oGLOB_NAV_FD_C2_oFDCAN2_c10121c7_Rx;
    }
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */


/**********************************************************************************************************************
 * RTE Schedulable entity for COM-Access from different partitions
 *********************************************************************************************************************/
FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic(void)
{
  uint8 updateAction;
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentCanNMState_FD02_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentCanNMState_FD02_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentCanNMState_FD02_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_CurrentCanNMState_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_b8d48ce4_Tx, (&Rte_CurrentCanNMState_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_b8d48ce4_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentCanNMState_FD02_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentCanNMState_FD02_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentFailSts_FD02_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentFailSts_FD02_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentFailSts_FD02_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_CurrentFailSts_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_c3249b61_Tx, (&Rte_CurrentFailSts_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_c3249b61_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentFailSts_FD02_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_CurrentFailSts_FD02_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_DES_FD02_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_DES_FD02_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_DES_FD02_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_DES_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4b879cc8_Tx, (&Rte_DES_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4b879cc8_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_DES_FD02_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_DES_FD02_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_01_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_35ebeb6b_Tx, (&Rte_Digit_01_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_35ebeb6b_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_02_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_510b9095_Tx, (&Rte_Digit_02_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_510b9095_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_03_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_c47b4400_Tx, (&Rte_Digit_03_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_c47b4400_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_04_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_98cb6769_Tx, (&Rte_Digit_04_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_98cb6769_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_05_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_0dbbb3fc_Tx, (&Rte_Digit_05_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_0dbbb3fc_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_06_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_695bc802_Tx, (&Rte_Digit_06_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_695bc802_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_07_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_fc2b1c97_Tx, (&Rte_Digit_07_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_fc2b1c97_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_08_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_d03b8ed0_Tx, (&Rte_Digit_08_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_d03b8ed0_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_09_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_454b5a45_Tx, (&Rte_Digit_09_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_454b5a45_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_10_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_206b28e1_Tx, (&Rte_Digit_10_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_206b28e1_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Digit_11_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_b51bfc74_Tx, (&Rte_Digit_11_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_b51bfc74_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_EOL_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ccb11d67_Tx, (&Rte_EOL_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ccb11d67_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_GenericFailSts_FD02_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_GenericFailSts_FD02_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_GenericFailSts_FD02_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_GenericFailSts_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_d914f704_Tx, (&Rte_GenericFailSts_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_d914f704_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_GenericFailSts_FD02_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_GenericFailSts_FD02_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_N_PDU != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_N_PDU)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_N_PDU;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_N_PDU_oDIAGNOSTIC_ROE_FD_PAM_oFDCAN2_32bc31eb_Tx, *(&Rte_N_PDU_oDIAGNOSTIC_ROE_FD_PAM_oFDCAN2_32bc31eb_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    (void)Com_SendSignal(ComConf_ComSignal_N_PDU_oDIAGNOSTIC_ROE_PAM_oFDCAN2_d40a7eb0_Tx, *(&Rte_N_PDU_oDIAGNOSTIC_ROE_FD_PAM_oFDCAN2_32bc31eb_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_N_PDU = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_N_PDU;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_PreviousCanNMState_FD02_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_PreviousCanNMState_FD02_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_PreviousCanNMState_FD02_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_PreviousCanNMState_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ea522b89_Tx, (&Rte_PreviousCanNMState_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ea522b89_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_PreviousCanNMState_FD02_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_PreviousCanNMState_FD02_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_StayActiveSource_FD02_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_StayActiveSource_FD02_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_StayActiveSource_FD02_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_StayActiveSource_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4ba3a17d_Tx, *(&Rte_StayActiveSource_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4ba3a17d_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_StayActiveSource_FD02_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_StayActiveSource_FD02_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_EPB_Req != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_EPB_Req)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_EPB_Req;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_THA_EPB_Req_oTRSCM_FD_1_oFDCAN2_330530e0_Tx, (&Rte_THA_EPB_Req_oTRSCM_FD_1_oFDCAN2_330530e0_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_EPB_Req = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_EPB_Req;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_STAT != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_STAT)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_STAT;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_THA_STAT_oTRSCM_FD_1_oFDCAN2_ae81c3b8_Tx, (&Rte_THA_STAT_oTRSCM_FD_1_oFDCAN2_ae81c3b8_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_STAT = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_STAT;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SpeedLimit_Req != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SpeedLimit_Req)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SpeedLimit_Req;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_THA_SpeedLimit_Req_oTRSCM_FD_1_oFDCAN2_99923097_Tx, (&Rte_THA_SpeedLimit_Req_oTRSCM_FD_1_oFDCAN2_99923097_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SpeedLimit_Req = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SpeedLimit_Req;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_Speed_Limit != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_Speed_Limit)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_Speed_Limit;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_THA_Speed_Limit_oTRSCM_FD_1_oFDCAN2_7015673d_Tx, (&Rte_THA_Speed_Limit_oTRSCM_FD_1_oFDCAN2_7015673d_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_Speed_Limit = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_Speed_Limit;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringDamping != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringDamping)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringDamping;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_THA_SteeringDamping_oTRSCM_FD_1_oFDCAN2_5077858c_Tx, (&Rte_THA_SteeringDamping_oTRSCM_FD_1_oFDCAN2_5077858c_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringDamping = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringDamping;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueInfo != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueInfo)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueInfo;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_THA_SteeringTorqueInfo_oTRSCM_FD_1_oFDCAN2_5437f775_Tx, (&Rte_THA_SteeringTorqueInfo_oTRSCM_FD_1_oFDCAN2_5437f775_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueInfo = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueInfo;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueReq != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueReq)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueReq;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_THA_SteeringTorqueReq_oTRSCM_FD_1_oFDCAN2_d5c7823f_Tx, (&Rte_THA_SteeringTorqueReq_oTRSCM_FD_1_oFDCAN2_d5c7823f_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueReq = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_THA_SteeringTorqueReq;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSCMoreCamRQSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSCMoreCamRQSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSCMoreCamRQSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TRSCMoreCamRQSts_oTRSCM_FD_1_oFDCAN2_6a0ec540_Tx, (&Rte_TRSCMoreCamRQSts_oTRSCM_FD_1_oFDCAN2_6a0ec540_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSCMoreCamRQSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSCMoreCamRQSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TRSC_PopupDisp_Info_oTRSCM_FD_1_oFDCAN2_53c36afe_Tx, (&Rte_TRSC_PopupDisp_Info_oTRSCM_FD_1_oFDCAN2_53c36afe_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TRSC_PopupDisp_Info2_oTRSCM_FD_1_oFDCAN2_e00c3444_Tx, (&Rte_TRSC_PopupDisp_Info2_oTRSCM_FD_1_oFDCAN2_e00c3444_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_PopupDisp_Info2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_STAT != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_STAT)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_STAT;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TRSC_STAT_oTRSCM_FD_1_oFDCAN2_37cfdfd9_Tx, (&Rte_TRSC_STAT_oTRSCM_FD_1_oFDCAN2_37cfdfd9_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_STAT = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_STAT;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SpeedLimit_Req != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SpeedLimit_Req)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SpeedLimit_Req;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TRSC_SpeedLimit_Req_oTRSCM_FD_1_oFDCAN2_ab040d8c_Tx, (&Rte_TRSC_SpeedLimit_Req_oTRSCM_FD_1_oFDCAN2_ab040d8c_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SpeedLimit_Req = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SpeedLimit_Req;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringDamping != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringDamping)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringDamping;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TRSC_SteeringDamping_oTRSCM_FD_1_oFDCAN2_da20da5d_Tx, (&Rte_TRSC_SteeringDamping_oTRSCM_FD_1_oFDCAN2_da20da5d_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringDamping = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringDamping;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueInfo != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueInfo)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueInfo;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TRSC_SteeringTorqueInfo_oTRSCM_FD_1_oFDCAN2_10502d34_Tx, (&Rte_TRSC_SteeringTorqueInfo_oTRSCM_FD_1_oFDCAN2_10502d34_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueInfo = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueInfo;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueReq != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueReq)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueReq;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TRSC_SteeringTorqueReq_oTRSCM_FD_1_oFDCAN2_b630b053_Tx, (&Rte_TRSC_SteeringTorqueReq_oTRSCM_FD_1_oFDCAN2_b630b053_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueReq = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_SteeringTorqueReq;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_VehicleStop_Req != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_VehicleStop_Req)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_VehicleStop_Req;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TRSC_VehicleStop_Req_oTRSCM_FD_1_oFDCAN2_756072d1_Tx, (&Rte_TRSC_VehicleStop_Req_oTRSCM_FD_1_oFDCAN2_756072d1_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_VehicleStop_Req = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TRSC_VehicleStop_Req;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Trailer_Angle_oTRSCM_FD_1_oFDCAN2_d1a864a3_Tx, (&Rte_Trailer_Angle_oTRSCM_FD_1_oFDCAN2_d1a864a3_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle_Sign != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle_Sign)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle_Sign;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Trailer_Angle_Sign_oTRSCM_FD_1_oFDCAN2_2b9f0ec4_Tx, (&Rte_Trailer_Angle_Sign_oTRSCM_FD_1_oFDCAN2_2b9f0ec4_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle_Sign = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Angle_Sign;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Calibration != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Calibration)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Calibration;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Trailer_Calibration_oTRSCM_FD_1_oFDCAN2_30ba6b34_Tx, (&Rte_Trailer_Calibration_oTRSCM_FD_1_oFDCAN2_30ba6b34_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Calibration = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Trailer_Calibration;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TrlrHitchLight_Cntrl != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TrlrHitchLight_Cntrl)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_TrlrHitchLight_Cntrl;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TrlrHitchLight_Cntrl_oTRSCM_FD_1_oFDCAN2_ba4f30d9_Tx, (&Rte_TrlrHitchLight_Cntrl_oTRSCM_FD_1_oFDCAN2_ba4f30d9_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TrlrHitchLight_Cntrl = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_TrlrHitchLight_Cntrl;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_WakeupSource_FD02_PAM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_WakeupSource_FD02_PAM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_WakeupSource_FD02_PAM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_WakeupSource_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_13de1caf_Tx, (&Rte_WakeupSource_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_13de1caf_Tx_1)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_WakeupSource_FD02_PAM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_WakeupSource_FD02_PAM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_AliveCntr_MCU2_0_oME_SystemDebugData_1_oFDCAN14_e65282c6_Tx, (&Rte_FD14_1_AliveCntr_MCU2_0_oME_SystemDebugData_1_oFDCAN14_e65282c6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_AliveCntr_MCU2_1_oME_SystemDebugData_1_oFDCAN14_1788876c_Tx, (&Rte_FD14_1_AliveCntr_MCU2_1_oME_SystemDebugData_1_oFDCAN14_1788876c_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_AliveCntr_MPU1_0_oME_SystemDebugData_1_oFDCAN14_0e75683e_Tx, (&Rte_FD14_1_AliveCntr_MPU1_0_oME_SystemDebugData_1_oFDCAN14_0e75683e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_ErrFaultInfo_MCU2_0_oME_SystemDebugData_1_oFDCAN14_09f994d2_Tx, (&Rte_FD14_1_ErrFaultInfo_MCU2_0_oME_SystemDebugData_1_oFDCAN14_09f994d2_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Err_FaultInfo_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f3e84bf0_Tx, (&Rte_FD14_1_Err_FaultInfo_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f3e84bf0_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Err_FaultInfo_MCU2_1_oME_SystemDebugData_1_oFDCAN14_6fb4bd00_Tx, (&Rte_FD14_1_Err_FaultInfo_MCU2_1_oME_SystemDebugData_1_oFDCAN14_6fb4bd00_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Err_FaultInfo_MPU1_0_oME_SystemDebugData_1_oFDCAN14_76495252_Tx, (&Rte_FD14_1_Err_FaultInfo_MPU1_0_oME_SystemDebugData_1_oFDCAN14_76495252_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Err_FaultNum_MCU1_0_oME_SystemDebugData_1_oFDCAN14_44f26807_Tx, (&Rte_FD14_1_Err_FaultNum_MCU1_0_oME_SystemDebugData_1_oFDCAN14_44f26807_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Err_FaultNum_MCU2_0_oME_SystemDebugData_1_oFDCAN14_29749b5d_Tx, (&Rte_FD14_1_Err_FaultNum_MCU2_0_oME_SystemDebugData_1_oFDCAN14_29749b5d_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Err_FaultNum_MCU2_1_oME_SystemDebugData_1_oFDCAN14_d8ae9ef7_Tx, (&Rte_FD14_1_Err_FaultNum_MCU2_1_oME_SystemDebugData_1_oFDCAN14_d8ae9ef7_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Err_FaultNum_MPU1_0_oME_SystemDebugData_1_oFDCAN14_c15371a5_Tx, (&Rte_FD14_1_Err_FaultNum_MPU1_0_oME_SystemDebugData_1_oFDCAN14_c15371a5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Hook_DtErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d4fc990e_Tx, (&Rte_FD14_1_Hook_DtErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d4fc990e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Hook_Error_MCU1_0_oME_SystemDebugData_1_oFDCAN14_082f9b06_Tx, (&Rte_FD14_1_Hook_Error_MCU1_0_oME_SystemDebugData_1_oFDCAN14_082f9b06_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Hook_PresentPtr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_46e0c48b_Tx, (&Rte_FD14_1_Hook_PresentPtr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_46e0c48b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Hook_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_4252166b_Tx, (&Rte_FD14_1_Hook_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_4252166b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Hook_Service_MCU1_0_oME_SystemDebugData_1_oFDCAN14_443850ea_Tx, (&Rte_FD14_1_Hook_Service_MCU1_0_oME_SystemDebugData_1_oFDCAN14_443850ea_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Hook_Type_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6517d66f_Tx, (&Rte_FD14_1_Hook_Type_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6517d66f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Hook_actTsk_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e5cab5c_Tx, (&Rte_FD14_1_Hook_actTsk_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e5cab5c_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Hook_fatalErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_db1493b6_Tx, (&Rte_FD14_1_Hook_fatalErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_db1493b6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_ADFSR_oME_MCUOsDebugData1_oFDCAN14_56600f18_Tx, (&Rte_FD14_1_OsRegMCU_ADFSR_oME_MCUOsDebugData1_oFDCAN14_56600f18_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_AIFSR_oME_MCUOsDebugData1_oFDCAN14_d7bd5dfe_Tx, (&Rte_FD14_1_OsRegMCU_AIFSR_oME_MCUOsDebugData1_oFDCAN14_d7bd5dfe_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_DFAR_oME_MCUOsDebugData1_oFDCAN14_73a0eaa5_Tx, (&Rte_FD14_1_OsRegMCU_DFAR_oME_MCUOsDebugData1_oFDCAN14_73a0eaa5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_DFSR_oME_MCUOsDebugData1_oFDCAN14_8011b617_Tx, (&Rte_FD14_1_OsRegMCU_DFSR_oME_MCUOsDebugData1_oFDCAN14_8011b617_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_IFAR_oME_MCUOsDebugData1_oFDCAN14_f27db843_Tx, (&Rte_FD14_1_OsRegMCU_IFAR_oME_MCUOsDebugData1_oFDCAN14_f27db843_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_IFSR_oME_MCUOsDebugData1_oFDCAN14_01cce4f1_Tx, (&Rte_FD14_1_OsRegMCU_IFSR_oME_MCUOsDebugData1_oFDCAN14_01cce4f1_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Link_oME_MCUOsDebugData1_oFDCAN14_b350e9be_Tx, (&Rte_FD14_1_OsRegMCU_Link_oME_MCUOsDebugData1_oFDCAN14_b350e9be_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_SPSR_oME_MCUOsDebugData1_oFDCAN14_8d113eaa_Tx, (&Rte_FD14_1_OsRegMCU_SPSR_oME_MCUOsDebugData1_oFDCAN14_8d113eaa_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Stack0_oME_MCUOsDebugData2_oFDCAN14_def0054e_Tx, (&Rte_FD14_1_OsRegMCU_Stack0_oME_MCUOsDebugData2_oFDCAN14_def0054e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Stack1_oME_MCUOsDebugData2_oFDCAN14_e290e646_Tx, (&Rte_FD14_1_OsRegMCU_Stack1_oME_MCUOsDebugData2_oFDCAN14_e290e646_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Stack2_oME_MCUOsDebugData2_oFDCAN14_a631c35e_Tx, (&Rte_FD14_1_OsRegMCU_Stack2_oME_MCUOsDebugData2_oFDCAN14_a631c35e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Stack3_oME_MCUOsDebugData2_oFDCAN14_9a512056_Tx, (&Rte_FD14_1_OsRegMCU_Stack3_oME_MCUOsDebugData2_oFDCAN14_9a512056_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Stack4_oME_MCUOsDebugData2_oFDCAN14_2f73896e_Tx, (&Rte_FD14_1_OsRegMCU_Stack4_oME_MCUOsDebugData2_oFDCAN14_2f73896e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Stack5_oME_MCUOsDebugData2_oFDCAN14_13136a66_Tx, (&Rte_FD14_1_OsRegMCU_Stack5_oME_MCUOsDebugData2_oFDCAN14_13136a66_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Stack6_oME_MCUOsDebugData2_oFDCAN14_57b24f7e_Tx, (&Rte_FD14_1_OsRegMCU_Stack6_oME_MCUOsDebugData2_oFDCAN14_57b24f7e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Stack7_oME_MCUOsDebugData2_oFDCAN14_6bd2ac76_Tx, (&Rte_FD14_1_OsRegMCU_Stack7_oME_MCUOsDebugData2_oFDCAN14_6bd2ac76_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Stack8_oME_MCUOsDebugData2_oFDCAN14_e6861b4f_Tx, (&Rte_FD14_1_OsRegMCU_Stack8_oME_MCUOsDebugData2_oFDCAN14_e6861b4f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_OsRegMCU_Stack9_oME_MCUOsDebugData2_oFDCAN14_dae6f847_Tx, (&Rte_FD14_1_OsRegMCU_Stack9_oME_MCUOsDebugData2_oFDCAN14_dae6f847_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5ce4f1ef_Tx, (&Rte_FD14_1_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5ce4f1ef_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Reserved_MCU2_0_oME_SystemDebugData_1_oFDCAN14_316202b5_Tx, (&Rte_FD14_1_Reserved_MCU2_0_oME_SystemDebugData_1_oFDCAN14_316202b5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Reserved_MCU2_1_oME_SystemDebugData_1_oFDCAN14_c0b8071f_Tx, (&Rte_FD14_1_Reserved_MCU2_1_oME_SystemDebugData_1_oFDCAN14_c0b8071f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_Reserved_MPU1_0_oME_SystemDebugData_1_oFDCAN14_d945e84d_Tx, (&Rte_FD14_1_Reserved_MPU1_0_oME_SystemDebugData_1_oFDCAN14_d945e84d_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SDL_Fault_MCU1_0_oME_SystemDebugData_1_oFDCAN14_80e1e586_Tx, (&Rte_FD14_1_SDL_Fault_MCU1_0_oME_SystemDebugData_1_oFDCAN14_80e1e586_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData10_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6272ae84_Tx, (&Rte_FD14_1_SSM_FltData10_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6272ae84_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData11_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2cfba52d_Tx, (&Rte_FD14_1_SSM_FltData11_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2cfba52d_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData12_MCU1_0_oME_SystemDebugData_1_oFDCAN14_ff60b9d6_Tx, (&Rte_FD14_1_SSM_FltData12_MCU1_0_oME_SystemDebugData_1_oFDCAN14_ff60b9d6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData13_MCU1_0_oME_SystemDebugData_1_oFDCAN14_b1e9b27f_Tx, (&Rte_FD14_1_SSM_FltData13_MCU1_0_oME_SystemDebugData_1_oFDCAN14_b1e9b27f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData14_MCU1_0_oME_SystemDebugData_1_oFDCAN14_83278661_Tx, (&Rte_FD14_1_SSM_FltData14_MCU1_0_oME_SystemDebugData_1_oFDCAN14_83278661_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData15_MCU1_0_oME_SystemDebugData_1_oFDCAN14_cdae8dc8_Tx, (&Rte_FD14_1_SSM_FltData15_MCU1_0_oME_SystemDebugData_1_oFDCAN14_cdae8dc8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData16_MCU1_0_oME_SystemDebugData_1_oFDCAN14_1e359133_Tx, (&Rte_FD14_1_SSM_FltData16_MCU1_0_oME_SystemDebugData_1_oFDCAN14_1e359133_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData17_MCU1_0_oME_SystemDebugData_1_oFDCAN14_50bc9a9a_Tx, (&Rte_FD14_1_SSM_FltData17_MCU1_0_oME_SystemDebugData_1_oFDCAN14_50bc9a9a_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData18_MCU1_0_oME_SystemDebugData_1_oFDCAN14_7ba9f90f_Tx, (&Rte_FD14_1_SSM_FltData18_MCU1_0_oME_SystemDebugData_1_oFDCAN14_7ba9f90f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData1_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e3538b4_Tx, (&Rte_FD14_1_SSM_FltData1_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e3538b4_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData2_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5dae244f_Tx, (&Rte_FD14_1_SSM_FltData2_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5dae244f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData3_MCU1_0_oME_SystemDebugData_1_oFDCAN14_13272fe6_Tx, (&Rte_FD14_1_SSM_FltData3_MCU1_0_oME_SystemDebugData_1_oFDCAN14_13272fe6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData4_MCU1_0_oME_SystemDebugData_1_oFDCAN14_21e91bf8_Tx, (&Rte_FD14_1_SSM_FltData4_MCU1_0_oME_SystemDebugData_1_oFDCAN14_21e91bf8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData5_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6f601051_Tx, (&Rte_FD14_1_SSM_FltData5_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6f601051_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData6_MCU1_0_oME_SystemDebugData_1_oFDCAN14_bcfb0caa_Tx, (&Rte_FD14_1_SSM_FltData6_MCU1_0_oME_SystemDebugData_1_oFDCAN14_bcfb0caa_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData7_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f2720703_Tx, (&Rte_FD14_1_SSM_FltData7_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f2720703_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData8_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d9676496_Tx, (&Rte_FD14_1_SSM_FltData8_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d9676496_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_FltData9_MCU1_0_oME_SystemDebugData_1_oFDCAN14_97ee6f3f_Tx, (&Rte_FD14_1_SSM_FltData9_MCU1_0_oME_SystemDebugData_1_oFDCAN14_97ee6f3f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_SSM_SystemStateReq_oME_SystemDebugData_1_oFDCAN14_1a98cea3_Tx, (&Rte_FD14_1_SSM_SystemStateReq_oME_SystemDebugData_1_oFDCAN14_1a98cea3_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_TimeSincePowerON_oME_SystemDebugData_1_oFDCAN14_144841c6_Tx, (&Rte_FD14_1_TimeSincePowerON_oME_SystemDebugData_1_oFDCAN14_144841c6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_1_WDG_Error_ID_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2488c0c2_Tx, (&Rte_FD14_1_WDG_Error_ID_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2488c0c2_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_AUXCamsRQSts_oCVPAM_FD_Info_oFDCAN2_cb5ede6d_Tx, (&Rte_AUXCamsRQSts_oCVPAM_FD_Info_oFDCAN2_cb5ede6d_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Alert_CHF_oCVPAM_FD_Info_oFDCAN2_10e5899e_Tx, (&Rte_Alert_CHF_oCVPAM_FD_Info_oFDCAN2_10e5899e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Alert_CHR_oCVPAM_FD_Info_oFDCAN2_068868fc_Tx, (&Rte_Alert_CHR_oCVPAM_FD_Info_oFDCAN2_068868fc_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Alert_LHF_oCVPAM_FD_Info_oFDCAN2_9d0fdf04_Tx, (&Rte_Alert_LHF_oCVPAM_FD_Info_oFDCAN2_9d0fdf04_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Alert_LHR_oCVPAM_FD_Info_oFDCAN2_8b623e66_Tx, (&Rte_Alert_LHR_oCVPAM_FD_Info_oFDCAN2_8b623e66_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Alert_RHF_oCVPAM_FD_Info_oFDCAN2_5daa7471_Tx, (&Rte_Alert_RHF_oCVPAM_FD_Info_oFDCAN2_5daa7471_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Alert_RHR_oCVPAM_FD_Info_oFDCAN2_4bc79513_Tx, (&Rte_Alert_RHR_oCVPAM_FD_Info_oFDCAN2_4bc79513_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Camera_Status_oADAS_FD_LANES_1_oFDCAN2_64f6e4de_Tx, (&Rte_Camera_Status_oADAS_FD_LANES_1_oFDCAN2_64f6e4de_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_ChimeActivation_LHF_oCVPAM_FD_Info_oFDCAN2_18ea8591_Tx, (&Rte_ChimeActivation_LHF_oCVPAM_FD_Info_oFDCAN2_18ea8591_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_ChimeActivation_LHR_oCVPAM_FD_Info_oFDCAN2_0e8764f3_Tx, (&Rte_ChimeActivation_LHR_oCVPAM_FD_Info_oFDCAN2_0e8764f3_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_ChimeActivation_RHF_oCVPAM_FD_Info_oFDCAN2_d84f2ee4_Tx, (&Rte_ChimeActivation_RHF_oCVPAM_FD_Info_oFDCAN2_d84f2ee4_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_ChimeActivation_RHR_oCVPAM_FD_Info_oFDCAN2_ce22cf86_Tx, (&Rte_ChimeActivation_RHR_oCVPAM_FD_Info_oFDCAN2_ce22cf86_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_af11a5df_Tx, (&Rte_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_af11a5df_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_64cb74e2_Tx, (&Rte_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_64cb74e2_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_DisplayView2_oCVPAM_FD_Info_oFDCAN2_73efd9c8_Tx, (&Rte_DisplayView2_oCVPAM_FD_Info_oFDCAN2_73efd9c8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN2_998d9b03_Tx, (&Rte_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN2_998d9b03_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FT_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_767c2572_Tx, (&Rte_FT_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_767c2572_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN2_1ad54467_Tx, (&Rte_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN2_1ad54467_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN2_d10f955a_Tx, (&Rte_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN2_d10f955a_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FrontSensorSts_oCVPAM_FD_Info_oFDCAN2_e08a5c16_Tx, (&Rte_FrontSensorSts_oCVPAM_FD_Info_oFDCAN2_e08a5c16_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Graphic_CHF_oCVPAM_FD_Info_oFDCAN2_4b6ea313_Tx, (&Rte_Graphic_CHF_oCVPAM_FD_Info_oFDCAN2_4b6ea313_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Graphic_CHR_oCVPAM_FD_Info_oFDCAN2_5d034271_Tx, (&Rte_Graphic_CHR_oCVPAM_FD_Info_oFDCAN2_5d034271_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Graphic_LHF_oCVPAM_FD_Info_oFDCAN2_c684f589_Tx, (&Rte_Graphic_LHF_oCVPAM_FD_Info_oFDCAN2_c684f589_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Graphic_LHR_oCVPAM_FD_Info_oFDCAN2_d0e914eb_Tx, (&Rte_Graphic_LHR_oCVPAM_FD_Info_oFDCAN2_d0e914eb_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Graphic_RHF_oCVPAM_FD_Info_oFDCAN2_06215efc_Tx, (&Rte_Graphic_RHF_oCVPAM_FD_Info_oFDCAN2_06215efc_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Graphic_RHR_oCVPAM_FD_Info_oFDCAN2_104cbf9e_Tx, (&Rte_Graphic_RHR_oCVPAM_FD_Info_oFDCAN2_104cbf9e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_HMICode_oCVPAM_FD_Info_oFDCAN2_5dec6edf_Tx, (&Rte_HMICode_oCVPAM_FD_Info_oFDCAN2_5dec6edf_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN2_e8d5db74_Tx, (&Rte_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN2_e8d5db74_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN2_1cdf1820_Tx, (&Rte_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN2_1cdf1820_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_ImageDefeatRQSts_oCVPAM_FD_Info_oFDCAN2_7d4e09fb_Tx, (&Rte_ImageDefeatRQSts_oCVPAM_FD_Info_oFDCAN2_7d4e09fb_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN2_2534fe9b_Tx, (&Rte_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN2_2534fe9b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN2_09082d9e_Tx, (&Rte_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN2_09082d9e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_93fb8a81_Tx, (&Rte_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_93fb8a81_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN2_34dd811a_Tx, (&Rte_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN2_34dd811a_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN2_3e17383d_Tx, (&Rte_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN2_3e17383d_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN2_ad232516_Tx, (&Rte_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN2_ad232516_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN2_293a5620_Tx, (&Rte_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN2_293a5620_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_1_Type_oADAS_FD_LANES_1_oFDCAN2_3e24410a_Tx, (&Rte_Line_1_Type_oADAS_FD_LANES_1_oFDCAN2_3e24410a_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN2_7f55c1fb_Tx, (&Rte_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN2_7f55c1fb_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN2_6de85660_Tx, (&Rte_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN2_6de85660_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_70b23d23_Tx, (&Rte_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_70b23d23_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN2_503dfae4_Tx, (&Rte_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN2_503dfae4_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN2_5391cb67_Tx, (&Rte_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN2_5391cb67_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN2_f6349403_Tx, (&Rte_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN2_f6349403_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN2_64d25647_Tx, (&Rte_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN2_64d25647_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_2_Type_oADAS_FD_LANES_1_oFDCAN2_2d0c7879_Tx, (&Rte_Line_2_Type_oADAS_FD_LANES_1_oFDCAN2_2d0c7879_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN2_ffa5d6e4_Tx, (&Rte_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN2_ffa5d6e4_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN2_f89882f5_Tx, (&Rte_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN2_f89882f5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_98a5ad82_Tx, (&Rte_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_98a5ad82_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN2_c54d2e71_Tx, (&Rte_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN2_c54d2e71_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN2_77139a51_Tx, (&Rte_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN2_77139a51_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN2_c0c604f0_Tx, (&Rte_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN2_c0c604f0_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN2_e95aaba5_Tx, (&Rte_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN2_e95aaba5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_3_Type_oADAS_FD_LANES_1_oFDCAN2_23eb90a8_Tx, (&Rte_Line_3_Type_oADAS_FD_LANES_1_oFDCAN2_23eb90a8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN2_cb97bf3b_Tx, (&Rte_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN2_cb97bf3b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN2_a428a19c_Tx, (&Rte_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN2_a428a19c_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_6d505426_Tx, (&Rte_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_6d505426_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN2_99fd0d18_Tx, (&Rte_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN2_99fd0d18_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN2_889c2dd3_Tx, (&Rte_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN2_889c2dd3_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN2_401bf629_Tx, (&Rte_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN2_401bf629_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN2_ff025689_Tx, (&Rte_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN2_ff025689_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Line_4_Type_oADAS_FD_LANES_1_oFDCAN2_0b5c0a9f_Tx, (&Rte_Line_4_Type_oADAS_FD_LANES_1_oFDCAN2_0b5c0a9f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_9c565bdf_Tx, *(&Rte_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_9c565bdf_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_578c8ae2_Tx, *(&Rte_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_578c8ae2_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_MoreCamsRQSts_oCVPAM_FD_Info_oFDCAN2_ba84adf5_Tx, (&Rte_MoreCamsRQSts_oCVPAM_FD_Info_oFDCAN2_ba84adf5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_PAMSystemFault_oCVPAM_FD_Info_oFDCAN2_eab32332_Tx, (&Rte_PAMSystemFault_oCVPAM_FD_Info_oFDCAN2_eab32332_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_PAM_CHIME_REP_RATESts_oCVPAM_FD_Info_oFDCAN2_ec85c7c5_Tx, (&Rte_PAM_CHIME_REP_RATESts_oCVPAM_FD_Info_oFDCAN2_ec85c7c5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_PAM_CHIME_TYPE_oCVPAM_FD_Info_oFDCAN2_0558f070_Tx, (&Rte_PAM_CHIME_TYPE_oCVPAM_FD_Info_oFDCAN2_0558f070_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_63c5d79e_Tx, (&Rte_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_63c5d79e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_PAM_Off_Status_oCVPAM_FD_Info_oFDCAN2_796d8062_Tx, (&Rte_PAM_Off_Status_oCVPAM_FD_Info_oFDCAN2_796d8062_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_PAM_Off_Status_2BT_oCVPAM_FD_Info_oFDCAN2_514378c1_Tx, (&Rte_PAM_Off_Status_2BT_oCVPAM_FD_Info_oFDCAN2_514378c1_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_PAM_PopUpRqst_oCVPAM_FD_Info_oFDCAN2_657f86c2_Tx, (&Rte_PAM_PopUpRqst_oCVPAM_FD_Info_oFDCAN2_657f86c2_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_PAM_Volume_oCVPAM_FD_Info_oFDCAN2_4f8f6792_Tx, (&Rte_PAM_Volume_oCVPAM_FD_Info_oFDCAN2_4f8f6792_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_PPPA_TurnIndicatorRqst_oCVPAM_FD_Control_oFDCAN2_507419a7_Tx, (&Rte_PPPA_TurnIndicatorRqst_oCVPAM_FD_Control_oFDCAN2_507419a7_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN2_ad1c7c90_Tx, (&Rte_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN2_ad1c7c90_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN2_92ae92ff_Tx, (&Rte_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN2_92ae92ff_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN2_48ca8ca5_Tx, (&Rte_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN2_48ca8ca5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_RR_PAM_StopControlSts_oCVPAM_FD_Control_oFDCAN2_2f143404_Tx, (&Rte_RR_PAM_StopControlSts_oCVPAM_FD_Control_oFDCAN2_2f143404_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_RearSensorSts_oCVPAM_FD_Info_oFDCAN2_a2ccce85_Tx, (&Rte_RearSensorSts_oCVPAM_FD_Info_oFDCAN2_a2ccce85_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN2_82a794a5_Tx, (&Rte_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN2_82a794a5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    (void)Com_SendSignal(ComConf_ComSignal_Reserved_for_functional_safety_oADAS_FD_LANES_2_oFDCAN2_bb2aa860_Tx, (&Rte_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN2_82a794a5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_SPMControlSts_oCVPAM_FD_Info_oFDCAN2_a3ff073d_Tx, (&Rte_SPMControlSts_oCVPAM_FD_Info_oFDCAN2_a3ff073d_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_SPMFailSts_oCVPAM_FD_Info_oFDCAN2_85d98ec8_Tx, (&Rte_SPMFailSts_oCVPAM_FD_Info_oFDCAN2_85d98ec8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_SPMSystemFault_oCVPAM_FD_Info_oFDCAN2_c4e3aa9b_Tx, (&Rte_SPMSystemFault_oCVPAM_FD_Info_oFDCAN2_c4e3aa9b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_SPM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_3446c3a9_Tx, (&Rte_SPM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_3446c3a9_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_SPM_Screen_Rqst_oCVPAM_FD_Info_oFDCAN2_4e673fb0_Tx, (&Rte_SPM_Screen_Rqst_oCVPAM_FD_Info_oFDCAN2_4e673fb0_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN2_d5c06647_Tx, (&Rte_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN2_d5c06647_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN2_124eba08_Tx, (&Rte_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN2_124eba08_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN2_0e62b6bf_Tx, (&Rte_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN2_0e62b6bf_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN2_fc355b47_Tx, (&Rte_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN2_fc355b47_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN2_60eeadfe_Tx, (&Rte_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN2_60eeadfe_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN2_92b94006_Tx, (&Rte_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN2_92b94006_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN2_8fa15927_Tx, (&Rte_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN2_8fa15927_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN2_b746d164_Tx, (&Rte_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN2_b746d164_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN2_ab6addd3_Tx, (&Rte_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN2_ab6addd3_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN2_593d302b_Tx, (&Rte_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN2_593d302b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN2_c5e6c692_Tx, (&Rte_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN2_c5e6c692_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN2_37b12b6a_Tx, (&Rte_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN2_37b12b6a_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN2_0f514e38_Tx, (&Rte_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN2_0f514e38_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN2_d4410840_Tx, (&Rte_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN2_d4410840_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN2_c86d04f7_Tx, (&Rte_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN2_c86d04f7_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN2_3a3ae90f_Tx, (&Rte_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN2_3a3ae90f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN2_a6e11fb6_Tx, (&Rte_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN2_a6e11fb6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN2_54b6f24e_Tx, (&Rte_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN2_54b6f24e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN2_3b6327e7_Tx, (&Rte_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN2_3b6327e7_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN2_262701fd_Tx, (&Rte_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN2_262701fd_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN2_3a0b0d4a_Tx, (&Rte_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN2_3a0b0d4a_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN2_c85ce0b2_Tx, (&Rte_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN2_c85ce0b2_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN2_5487160b_Tx, (&Rte_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN2_5487160b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN2_a6d0fbf3_Tx, (&Rte_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN2_a6d0fbf3_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN2_bb9330f8_Tx, (&Rte_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN2_bb9330f8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN2_4520d8d9_Tx, (&Rte_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN2_4520d8d9_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN2_590cd46e_Tx, (&Rte_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN2_590cd46e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN2_ab5b3996_Tx, (&Rte_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN2_ab5b3996_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN2_3780cf2f_Tx, (&Rte_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN2_3780cf2f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN2_c5d722d7_Tx, (&Rte_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN2_c5d722d7_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN2_e1f20f98_Tx, (&Rte_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN2_e1f20f98_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN2_e028b3b5_Tx, (&Rte_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN2_e028b3b5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN2_fc04bf02_Tx, (&Rte_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN2_fc04bf02_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN2_0e5352fa_Tx, (&Rte_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN2_0e5352fa_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN2_9288a443_Tx, (&Rte_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN2_9288a443_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN2_60df49bb_Tx, (&Rte_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN2_60df49bb_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN2_61021887_Tx, (&Rte_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN2_61021887_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN2_832f6a91_Tx, (&Rte_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN2_832f6a91_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN2_9f036626_Tx, (&Rte_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN2_9f036626_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN2_6d548bde_Tx, (&Rte_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN2_6d548bde_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN2_f18f7d67_Tx, (&Rte_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN2_f18f7d67_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN2_03d8909f_Tx, (&Rte_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN2_03d8909f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN2_8996dc26_Tx, (&Rte_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN2_8996dc26_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN2_df95a68e_Tx, (&Rte_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN2_df95a68e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN2_c3b9aa39_Tx, (&Rte_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN2_c3b9aa39_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN2_31ee47c1_Tx, (&Rte_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN2_31ee47c1_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN2_ad35b178_Tx, (&Rte_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN2_ad35b178_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN2_5f625c80_Tx, (&Rte_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN2_5f625c80_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_TRSC_LED_Stat_oCVPAM_FD_Info_oFDCAN2_546afbba_Tx, (&Rte_TRSC_LED_Stat_oCVPAM_FD_Info_oFDCAN2_546afbba_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Camera_Status_oADAS_FD_LANES_1_oFDCAN14_02ee5263_Tx, (&Rte_FD14_Camera_Status_oADAS_FD_LANES_1_oFDCAN14_02ee5263_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_83e8745c_Tx, (&Rte_FD14_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_83e8745c_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_db4be29c_Tx, (&Rte_FD14_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_db4be29c_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN14_07d950b0_Tx, (&Rte_FD14_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN14_07d950b0_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN14_09d47624_Tx, (&Rte_FD14_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN14_09d47624_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN14_5177e0e4_Tx, (&Rte_FD14_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN14_5177e0e4_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN14_67ae32c5_Tx, (&Rte_FD14_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN14_67ae32c5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN14_0b1cd3fa_Tx, (&Rte_FD14_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN14_0b1cd3fa_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN14_3d68d9cb_Tx, (&Rte_FD14_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN14_3d68d9cb_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN14_cc3e3dc3_Tx, (&Rte_FD14_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN14_cc3e3dc3_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_aa426416_Tx, (&Rte_FD14_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_aa426416_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN14_26d6af56_Tx, (&Rte_FD14_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN14_26d6af56_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN14_c61fd7b8_Tx, (&Rte_FD14_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN14_c61fd7b8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN14_9798cd20_Tx, (&Rte_FD14_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN14_9798cd20_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN14_0d5038a6_Tx, (&Rte_FD14_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN14_0d5038a6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_1_Type_oADAS_FD_LANES_1_oFDCAN14_dd59b9e0_Tx, (&Rte_FD14_Line_1_Type_oADAS_FD_LANES_1_oFDCAN14_dd59b9e0_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN14_7080d9ac_Tx, (&Rte_FD14_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN14_7080d9ac_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN14_965f02a3_Tx, (&Rte_FD14_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN14_965f02a3_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_9279ef65_Tx, (&Rte_FD14_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_9279ef65_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN14_7cb79036_Tx, (&Rte_FD14_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN14_7cb79036_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN14_4dcce9a1_Tx, (&Rte_FD14_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN14_4dcce9a1_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN14_fa1e3e7a_Tx, (&Rte_FD14_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN14_fa1e3e7a_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN14_decb245d_Tx, (&Rte_FD14_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN14_decb245d_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_2_Type_oADAS_FD_LANES_1_oFDCAN14_1446b15f_Tx, (&Rte_FD14_Line_2_Type_oADAS_FD_LANES_1_oFDCAN14_1446b15f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN14_fd08244e_Tx, (&Rte_FD14_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN14_fd08244e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN14_16af15bc_Tx, (&Rte_FD14_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN14_16af15bc_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_33406b8b_Tx, (&Rte_FD14_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_33406b8b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN14_fc478729_Tx, (&Rte_FD14_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN14_fc478729_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN14_8252fe69_Tx, (&Rte_FD14_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN14_8252fe69_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN14_de9c6f4c_Tx, (&Rte_FD14_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN14_de9c6f4c_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN14_90422ff4_Tx, (&Rte_FD14_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN14_90422ff4_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_3_Type_oADAS_FD_LANES_1_oFDCAN14_e59cb4f5_Tx, (&Rte_FD14_Line_3_Type_oADAS_FD_LANES_1_oFDCAN14_e59cb4f5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN14_eb50d962_Tx, (&Rte_FD14_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN14_eb50d962_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN14_229d7c63_Tx, (&Rte_FD14_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN14_229d7c63_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_e20ef983_Tx, (&Rte_FD14_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_e20ef983_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN14_c875eef6_Tx, (&Rte_FD14_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN14_c875eef6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN14_811b93d2_Tx, (&Rte_FD14_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN14_811b93d2_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN14_2113d8ce_Tx, (&Rte_FD14_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN14_2113d8ce_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN14_a28c1bea_Tx, (&Rte_FD14_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN14_a28c1bea_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Line_4_Type_oADAS_FD_LANES_1_oFDCAN14_5d09a660_Tx, (&Rte_FD14_Line_4_Type_oADAS_FD_LANES_1_oFDCAN14_5d09a660_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_cce8ce85_Tx, *(&Rte_FD14_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_cce8ce85_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_944b5845_Tx, *(&Rte_FD14_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_944b5845_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_ManoeuvrePhase_oCVPAM_FD_Control_oFDCAN14_6f7ff602_Tx, (&Rte_FD14_ManoeuvrePhase_oCVPAM_FD_Control_oFDCAN14_6f7ff602_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_AccelMax_oCVPAM_FD_Control_oFDCAN14_c98fde99_Tx, (&Rte_FD14_PPPA_AccelMax_oCVPAM_FD_Control_oFDCAN14_c98fde99_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_AccelMin_oCVPAM_FD_Control_oFDCAN14_79b0c4a5_Tx, (&Rte_FD14_PPPA_AccelMin_oCVPAM_FD_Control_oFDCAN14_79b0c4a5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_DecelMax_oCVPAM_FD_Control_oFDCAN14_55867c47_Tx, (&Rte_FD14_PPPA_DecelMax_oCVPAM_FD_Control_oFDCAN14_55867c47_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_DecelMin_oCVPAM_FD_Control_oFDCAN14_e5b9667b_Tx, (&Rte_FD14_PPPA_DecelMin_oCVPAM_FD_Control_oFDCAN14_e5b9667b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_Interface_BSM_oCVPAM_FD_Control_oFDCAN14_5d761341_Tx, (&Rte_FD14_PPPA_Interface_BSM_oCVPAM_FD_Control_oFDCAN14_5d761341_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_JerkAccelMax_oCVPAM_FD_Control_oFDCAN14_05f086d0_Tx, (&Rte_FD14_PPPA_JerkAccelMax_oCVPAM_FD_Control_oFDCAN14_05f086d0_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_JerkAccelMin_oCVPAM_FD_Control_oFDCAN14_b5cf9cec_Tx, (&Rte_FD14_PPPA_JerkAccelMin_oCVPAM_FD_Control_oFDCAN14_b5cf9cec_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_JerkDecelMax_oCVPAM_FD_Control_oFDCAN14_99f9240e_Tx, (&Rte_FD14_PPPA_JerkDecelMax_oCVPAM_FD_Control_oFDCAN14_99f9240e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_JerkDecelMin_oCVPAM_FD_Control_oFDCAN14_29c63e32_Tx, (&Rte_FD14_PPPA_JerkDecelMin_oCVPAM_FD_Control_oFDCAN14_29c63e32_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_MaxSpeed_oCVPAM_FD_Control_oFDCAN14_7ef0b86c_Tx, (&Rte_FD14_PPPA_MaxSpeed_oCVPAM_FD_Control_oFDCAN14_7ef0b86c_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_StandstillRqst_oCVPAM_FD_Control_oFDCAN14_cc940d9b_Tx, (&Rte_FD14_PPPA_StandstillRqst_oCVPAM_FD_Control_oFDCAN14_cc940d9b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_PPPA_TargetDistance_oCVPAM_FD_Control_oFDCAN14_3437c295_Tx, (&Rte_FD14_PPPA_TargetDistance_oCVPAM_FD_Control_oFDCAN14_3437c295_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_ParkingGearShiftReq_oCVPAM_FD_Control_oFDCAN14_47412e73_Tx, (&Rte_FD14_ParkingGearShiftReq_oCVPAM_FD_Control_oFDCAN14_47412e73_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN14_2abad8a3_Tx, (&Rte_FD14_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN14_2abad8a3_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN14_7700e6e6_Tx, (&Rte_FD14_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN14_7700e6e6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN14_0f3b79a5_Tx, (&Rte_FD14_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN14_0f3b79a5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN14_e529cfa2_Tx, (&Rte_FD14_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN14_e529cfa2_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Reserved_for_functional_safety_oADAS_FD_LANES_2_oFDCAN14_0e1e74a1_Tx, (&Rte_FD14_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN14_e529cfa2_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_SPM_Lat_Ctrl_RequestSts_oCVPAM_FD_Control_oFDCAN14_6d94d6ac_Tx, (&Rte_FD14_SPM_Lat_Ctrl_RequestSts_oCVPAM_FD_Control_oFDCAN14_6d94d6ac_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN14_7d46bee9_Tx, (&Rte_FD14_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN14_7d46bee9_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN14_a70622c6_Tx, (&Rte_FD14_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN14_a70622c6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN14_f21f28e5_Tx, (&Rte_FD14_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN14_f21f28e5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN14_418b0526_Tx, (&Rte_FD14_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN14_418b0526_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN14_f3aad5f8_Tx, (&Rte_FD14_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN14_f3aad5f8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN14_403ef83b_Tx, (&Rte_FD14_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN14_403ef83b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN14_30aebe8e_Tx, (&Rte_FD14_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN14_30aebe8e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN14_e3a707de_Tx, (&Rte_FD14_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN14_e3a707de_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN14_b6be0dfd_Tx, (&Rte_FD14_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN14_b6be0dfd_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN14_052a203e_Tx, (&Rte_FD14_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN14_052a203e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN14_b70bf0e0_Tx, (&Rte_FD14_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN14_b70bf0e0_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN14_049fdd23_Tx, (&Rte_FD14_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN14_049fdd23_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN14_bd26436c_Tx, (&Rte_FD14_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN14_bd26436c_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN14_dfc7e4d6_Tx, (&Rte_FD14_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN14_dfc7e4d6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN14_8adeeef5_Tx, (&Rte_FD14_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN14_8adeeef5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN14_394ac336_Tx, (&Rte_FD14_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN14_394ac336_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN14_8b6b13e8_Tx, (&Rte_FD14_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN14_8b6b13e8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN14_38ff3e2b_Tx, (&Rte_FD14_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN14_38ff3e2b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN14_ab7ebe40_Tx, (&Rte_FD14_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN14_ab7ebe40_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN14_6ae54dee_Tx, (&Rte_FD14_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN14_6ae54dee_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN14_3ffc47cd_Tx, (&Rte_FD14_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN14_3ffc47cd_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN14_8c686a0e_Tx, (&Rte_FD14_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN14_8c686a0e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN14_3e49bad0_Tx, (&Rte_FD14_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN14_3e49bad0_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN14_8ddd9713_Tx, (&Rte_FD14_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN14_8ddd9713_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN14_26f643a2_Tx, (&Rte_FD14_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN14_26f643a2_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN14_5685aee6_Tx, (&Rte_FD14_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN14_5685aee6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN14_039ca4c5_Tx, (&Rte_FD14_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN14_039ca4c5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN14_b0088906_Tx, (&Rte_FD14_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN14_b0088906_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN14_022959d8_Tx, (&Rte_FD14_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN14_022959d8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN14_b1bd741b_Tx, (&Rte_FD14_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN14_b1bd741b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN14_6b1e43c5_Tx, (&Rte_FD14_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN14_6b1e43c5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN14_12248bfe_Tx, (&Rte_FD14_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN14_12248bfe_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN14_473d81dd_Tx, (&Rte_FD14_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN14_473d81dd_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN14_f4a9ac1e_Tx, (&Rte_FD14_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN14_f4a9ac1e_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN14_46887cc0_Tx, (&Rte_FD14_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN14_46887cc0_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN14_f51c5103_Tx, (&Rte_FD14_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN14_f51c5103_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN14_e696be27_Tx, (&Rte_FD14_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN14_e696be27_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN14_2e4468f6_Tx, (&Rte_FD14_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN14_2e4468f6_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN14_7b5d62d5_Tx, (&Rte_FD14_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN14_7b5d62d5_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN14_c8c94f16_Tx, (&Rte_FD14_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN14_c8c94f16_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN14_7ae89fc8_Tx, (&Rte_FD14_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN14_7ae89fc8_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN14_c97cb20b_Tx, (&Rte_FD14_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN14_c97cb20b_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN14_47afb99d_Tx, (&Rte_FD14_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN14_47afb99d_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN14_a310dfcf_Tx, (&Rte_FD14_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN14_a310dfcf_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN14_f609d5ec_Tx, (&Rte_FD14_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN14_f609d5ec_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN14_459df82f_Tx, (&Rte_FD14_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN14_459df82f_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN14_f7bc28f1_Tx, (&Rte_FD14_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN14_f7bc28f1_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2 != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN14_44280532_Tx, (&Rte_FD14_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN14_44280532_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2 = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM != Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM)
  {
    updateAction = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)Com_SendSignal(ComConf_ComSignal_FD14_TorqueOverlaySteeringReq_SPM_oCVPAM_FD_Control_oFDCAN14_593889ae_Tx, (&Rte_FD14_TorqueOverlaySteeringReq_SPM_oCVPAM_FD_Control_oFDCAN14_593889ae_Tx)); /* PRQA S 0315 */ /* MD_Rte_0315 */
    Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM = Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0306:  MISRA rule: Rule11.4
     Reason:     An optimized copy algorithm can be used for aligned data. To check if pointers are aligned, pointers need to be casted to an integer type.
     Risk:       No functional risk. Only the lower 8 bits of the address are checked, therefore all integer types are sufficient.
     Prevention: Not required.

   MD_Rte_0315:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because generic access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0316:  MISRA rule: Dir1.1
     Reason:     Pointer cast to uint8* because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_1533:  MISRA rule: Rule8.9
     Reason:     Object is referenced by more than one function in different configurations.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_2983:  MISRA rule: Rule2.2
     Reason:     For generated code it is difficult to check the usage of each object.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_4116:  MISRA rule: Rule12.6
     Reason:     Operand can only be 0 or 1 in special case of queue size equal to 1.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
