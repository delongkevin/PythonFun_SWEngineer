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
 *             File:  Rte_OsApplication_Safety.c
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
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_APSMPAOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpAPSMPAOut_TbAP_APSMPAOut_t = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CAM_select_info_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCAMSelInfo_CAM_select_info_t = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(IFOD_Outputs_CVPAMFDData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(LMD_Outputs_CVPAMFDData2_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t = {
  {0ULL, 0ULL, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  }, {0ULL, 0ULL, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CAM_CS_Curr_Monitor_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCamCsData_CAM_CS_Curr_Monitor_t = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Svs_CamEepromDataArray_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCamEepromData_Svs_CamEepromDataArray_t = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Cam_and_Ser_EN_Status_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCamSerENStat_Cam_and_Ser_EN_Status_t = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CpuLoadMcu2_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CpuLoadMcu2_1_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(JobDLDOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDLDOutput_JobDLDOutput_t = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Debug_HMI_Curr_Requested_Overlays, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Debug_HMI_Curr_Displayed_Overlays, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Debug_HMI_Curr_Displayed_ProxiConfig, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Debug_HMI_Curr_Requested_ProxiConfig, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Debug_HMI_Input_Data_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebHmiInput_Debug_HMI_Input_Data_t = {
  0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, 
  FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Debug_HMI_Internal_Data_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebHmiInternal_Debug_HMI_Internal_Data_t = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 
  FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Debug_HMI_Trailer_Views_Data_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t = {
  0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, 
  FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Detection_Inputs_from_TRSC_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDetInpTrsc_Detection_Inputs_from_TRSC_t = {
  0U, 0.0F, 0.0F, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_DriveAssistStatOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t = {
  0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 
  FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Error_Fault_MCU2_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpErrFltMcu2_0_Error_Fault_MCU2_0_t = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Error_Fault_MCU2_1_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpErrFltMcu2_1_Error_Fault_MCU2_1_t = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Error_Fault_MPU1_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpErrFltMpu1_0_Error_Fault_MPU1_0_t = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_FPAWarnOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpFPAWarnOut_TbAP_FPAWarnOut_t = {
  0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbTHASmVc_FeatureOutputs_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t = {
  0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 
  FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(IDebug_FODObject_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpIDebugFODObject_IDebug_FODObject_t = {
  {{0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 
  0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}}, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(IFOD_Outputs_Arbitration_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t = {
  0U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(IJobUSSObjectMapOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(IJobFPAOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpJobFPAData_IJobFPAOutput_t = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(IJobPLDOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpJobPLDData_IJobPLDOutput_t = {
  FALSE, {{{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {
  0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 
  0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F
  }, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 
  0U, 0U, FALSE}}, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(JobTHADetOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpJobTHADetOutput_JobTHADetOutput_t = {
  {0.0F, 0.0F, 0.0F}, {0, 0}, {0.0F, 0.0F, 0.0F}, {0, 0}, 0.0F, 0.0F, 0U, 0U, 0, 0, 0U, 0U, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(KeepAliveResponse_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpKeepAliveResponse_KeepAliveResponse_t = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(LMD_Lane_Outputs_s, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpLMDLaneOp_LMD_Lane_Outputs_s = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t = {
  0.0F, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(NFCD_Output, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpNFCDOutput_NFCD_Output = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbSVS_e_SVSOutputToNVMCamCalibSM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t = {
  FALSE, 0U, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U
  }}, {0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, {0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(NVMSignalManager_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpNVMSignMgr_NVMSignalManager_t = {
  FALSE, FALSE, 0U, {{{0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}, {0.0F, 0.0F}}, 0U, 0U, 0U, FALSE}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpPAM2BTIpcTxStatus_IpcTxDone = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_PAStateOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpPAStateOut_TbAP_PAStateOut_t = {
  0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_PointDistOutputBuff_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpPointDistOpBuff_US_S_PointDistOutputBuff_t = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_RPAWarnOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpRPAWarnOut_TbAP_RPAWarnOut_t = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RunTimeStats_MCU2_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RunTimeStats_MCU2_1_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RunTimeStats_MPU1_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_SMDAInternalOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSMDAInternal_TbAP_SMDAInternalOut_t = {
  0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SSM_2_0_CoreStatus, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_0 = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SSM_2_1_CoreStatus, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_1 = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SSM_QNX_CoreStatus, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSR_State_QNX_State_QNX = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t = {
  FALSE, 0U, {{{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 
  0U}}, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U
  }}, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}
  }, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}
  }, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbSVS_S_SVSCamEOLCalibDataToNVM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t = {
  FALSE, 0U, {{{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 
  0U}}, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U
  }}, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}
  }, 0U}, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}
  }, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbSVS_S_SVSCamOCCalibDataToNVM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t = {
  FALSE, 0U, 0U, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 
  0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbSVS_S_SVSCamSCCalibDataToNVM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t = {
  FALSE, 0U, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 
  0.0F, 0U, FALSE, FALSE}, 0U}, {{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SVS_NVMData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSNVMData_SVS_NVMData_t = {
  FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbSVS_e_SVSOutputToDiagMgrCamCalib_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SVSToDiag_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVSToDiag_SVSToDiag_t = {
  0U, 0U, 0U, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SVStoTRSC_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSVStoTRSC_SVStoTRSC_t = {
  0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ErrorMgr_ErrorCommPack_1_0_B, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ErrorMgr_ErrorCommPack_2_0_B, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ErrorMgr_ErrorCommPack_2_1_B, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ErrorMgr_ErrorCommPack_QNX_B, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 
  0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}, {{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ErrorMgr_ErrorCommPack_2_0_QM, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM = {
  0U, 0U, {0U}, {0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ErrorMgr_ErrorCommPack_2_1_QM, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM = {
  0U, 0U, {0U}, {0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ErrorMgr_ErrorCommPack_QNX_QM, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM = {
  0U, 0U, {0U}, {0U, 0U, 0U}, {{{0U, 0U, 0U, 0U}}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ScreenRequest_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpScreenRequest_ScreenRequest_t = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_SnrDirEcho_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSnrDirEcho_US_S_SnrDirEcho_t = {
  {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 
  0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(StackUsage_MCU2_0_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t = {
  {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(StackUsage_MCU2_1_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t = {
  {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U}, {0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SvsToTHA_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSvsToTHA_SvsToTHA_t = {
  0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SvsToVCAN_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpSvsToVCAN_SvsToVCAN_t = {
  FALSE, FALSE, FALSE, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ME_VehOut_TRSC_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTRSC_ME_VehOut_TRSC_t = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0U, 0U, 0U, FALSE, 0.0F, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSCSMVCtoDebugCAN_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t = {
  0.0F, 0.0F, 0.0F, 0U, 0U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_DebugOut, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTbAPDebugOut_TbAP_DebugOut = {
  0.0F, 0.0F, 0.0F, 0U, 0U, 0, 0, 0, 0, 0, 0, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 
  FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_SMPAInternalOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t = {
  0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbFA_ArbiterOutput_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t = {
  FALSE, FALSE, FALSE, FALSE, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbFA_ResetKM_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTbFAResetKM_TbFA_ResetKM_t = {
  FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbTHASmVc_DiagMgr_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t = {
  0, 0.0F, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TrailerDetection_Output_DID_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTrailerDetectOP_TrailerDetection_Output_DID_t = {
  0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, {0U, FALSE}, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSCSMVCtoSVS_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t = {
  0U, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSCtoDiagMgr_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTrscToDiag_TRSCtoDiagMgr_t = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSC_Inputs_from_TrailerDetection_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_BlockageBit_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUSSBlockageBit_US_S_BlockageBit_t = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_USSConstantData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUSSConstantData_US_S_USSConstantData_t = {
  {{0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, 
  {0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL, 0ULL}, {0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_USSErrorDiagData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUSSErrorDiagData_US_S_USSErrorDiagData_t = {
  {0U, 0U, 0U, 0U, 0U}, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_USSPeriodDiagData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_CsmStateChangeReason_Type, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_USSDataCollectionData_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssDataCollection_US_S_USSDataCollectionData_t = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_DebugMsg_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssDebugMsg_US_S_DebugMsg_t = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_MarriageSensorIDs_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssMrrgData_US_S_MarriageSensorIDs_t = {
  FALSE, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_PointMapGroup_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssPointMapGrp_US_S_PointMapGroup_t = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(UssTunningData_mcu2_1_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssTunData_UssTunningData_mcu2_1_t = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(US_S_ZoneInfo_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpUssZoneInfo_US_S_ZoneInfo_t = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_VCActuatorOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpVCActuatorOut_TbAP_VCActuatorOut_t = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_VCStateOut_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpVCState_TbAP_VCStateOut_t = {
  0.0F, 0, 0U, FALSE, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(WdgCheckpointStatus_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(WdgCheckpointStatus_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(WdgCheckpointStatus_t, RTE_VAR_INIT) Rte_CDD_IPCHandler_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PmicStatus, RTE_VAR_INIT) Rte_CDD_PMIC_PpPMICFaultstatus_Sts = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(WdgFltSts, RTE_VAR_INIT) Rte_CDD_PMIC_PpWDGFaultStatus_Sts = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(MpuFltSts, RTE_VAR_INIT) Rte_CDD_Safety_PpMPUFaultStatus_Sts = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Status, RTE_VAR_INIT) Rte_CDD_Safety_PpSDLFaultstatus_Sts = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CalDataProvider_MCU_1_0_Def, RTE_VAR_INIT) Rte_CalDataProvider_P_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0 = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_CalDataProSCCalStatus, RTE_VAR_INIT) Rte_CalDataProvider_P_Request_BswM_ScCalStatus_requestedMode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_VrntTunParam_t, RTE_VAR_INIT) Rte_CalDataProvider_PpAPVarTunParam_TbAP_VrntTunParam_t = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_VAR_INIT) Rte_CalDataProvider_PpPreviousCamData_Data = {
  0U, {{{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U
  }, {{{0.0F, 0.0F, 0.0F, 0U, FALSE, FALSE}, 0.0F, 0.0F, 0.0F, {0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U}}, 0U}
  }, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(DtcAddData_B, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcAddData_B = {
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
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(DtcStatus_B, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcStatus_B = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ErrorListArr_B, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_Errors_B_Errors_B = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SafeStateOpDef, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_SafeState_SafeStateOp = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_ErrorMgrAgg_1_0_B_P_SafeState2Reason_FaultEnum_u16 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ME_Hydra2defs_S_CodingTableExt_t, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiConfigData_ProxiData = {
  FALSE, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiErrorData_Error = {
  {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiReset_ProxiDataflag_b = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PAMConfig_u8 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PRX_CanNod27_b = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Pamtuningset = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Parkwithstop_u8 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Trailerhitchassist_u8 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CurrentCanNMState_FD02_PAM, RTE_VAR_INIT) Rte_CurrentCanNMState_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_b8d48ce4_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CurrentFailSts_FD02_PAM, RTE_VAR_INIT) Rte_CurrentFailSts_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_c3249b61_Tx_1 = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(DES_FD02_PAM, RTE_VAR_INIT) Rte_DES_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4b879cc8_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_01_PAM, RTE_VAR_INIT) Rte_Digit_01_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_35ebeb6b_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_02_PAM, RTE_VAR_INIT) Rte_Digit_02_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_510b9095_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_03_PAM, RTE_VAR_INIT) Rte_Digit_03_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_c47b4400_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_04_PAM, RTE_VAR_INIT) Rte_Digit_04_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_98cb6769_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_05_PAM, RTE_VAR_INIT) Rte_Digit_05_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_0dbbb3fc_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_06_PAM, RTE_VAR_INIT) Rte_Digit_06_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_695bc802_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_07_PAM, RTE_VAR_INIT) Rte_Digit_07_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_fc2b1c97_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_08_PAM, RTE_VAR_INIT) Rte_Digit_08_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_d03b8ed0_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_09_PAM, RTE_VAR_INIT) Rte_Digit_09_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_454b5a45_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_10_PAM, RTE_VAR_INIT) Rte_Digit_10_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_206b28e1_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Digit_11_PAM, RTE_VAR_INIT) Rte_Digit_11_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_b51bfc74_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(EOL_FD02_PAM, RTE_VAR_INIT) Rte_EOL_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ccb11d67_Tx_1 = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(GenericFailSts_FD02_PAM, RTE_VAR_INIT) Rte_GenericFailSts_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_d914f704_Tx_1 = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(N_PDU, RTE_VAR_INIT) Rte_N_PDU_oDIAGNOSTIC_ROE_FD_PAM_oFDCAN2_32bc31eb_Tx_1 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PreviousCanNMState_FD02_PAM, RTE_VAR_INIT) Rte_PreviousCanNMState_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ea522b89_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(StayActiveSource_FD02_PAM, RTE_VAR_INIT) Rte_StayActiveSource_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4ba3a17d_Tx_1 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(THA_EPB_Req, RTE_VAR_INIT) Rte_THA_EPB_Req_oTRSCM_FD_1_oFDCAN2_330530e0_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(THA_STAT, RTE_VAR_INIT) Rte_THA_STAT_oTRSCM_FD_1_oFDCAN2_ae81c3b8_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(THA_SpeedLimit_Req, RTE_VAR_INIT) Rte_THA_SpeedLimit_Req_oTRSCM_FD_1_oFDCAN2_99923097_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(THA_Speed_Limit, RTE_VAR_INIT) Rte_THA_Speed_Limit_oTRSCM_FD_1_oFDCAN2_7015673d_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_THA_SteeringDamping_oTRSCM_FD_1_oFDCAN2_5077858c_Tx_1 = 100U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_THA_SteeringTorqueInfo_oTRSCM_FD_1_oFDCAN2_5437f775_Tx_1 = 1024U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(THA_SteeringTorqueReq, RTE_VAR_INIT) Rte_THA_SteeringTorqueReq_oTRSCM_FD_1_oFDCAN2_d5c7823f_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSCMoreCamRQSts, RTE_VAR_INIT) Rte_TRSCMoreCamRQSts_oTRSCM_FD_1_oFDCAN2_6a0ec540_Tx_1 = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSC_PopupDisp_Info, RTE_VAR_INIT) Rte_TRSC_PopupDisp_Info_oTRSCM_FD_1_oFDCAN2_53c36afe_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSC_PopupDisp_Info2, RTE_VAR_INIT) Rte_TRSC_PopupDisp_Info2_oTRSCM_FD_1_oFDCAN2_e00c3444_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSC_STAT, RTE_VAR_INIT) Rte_TRSC_STAT_oTRSCM_FD_1_oFDCAN2_37cfdfd9_Tx_1 = 1U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSC_SpeedLimit_Req, RTE_VAR_INIT) Rte_TRSC_SpeedLimit_Req_oTRSCM_FD_1_oFDCAN2_ab040d8c_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_TRSC_SteeringDamping_oTRSCM_FD_1_oFDCAN2_da20da5d_Tx_1 = 128U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_TRSC_SteeringTorqueInfo_oTRSCM_FD_1_oFDCAN2_10502d34_Tx_1 = 1024U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSC_SteeringTorqueReq, RTE_VAR_INIT) Rte_TRSC_SteeringTorqueReq_oTRSCM_FD_1_oFDCAN2_b630b053_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSC_VehicleStop_Req, RTE_VAR_INIT) Rte_TRSC_VehicleStop_Req_oTRSCM_FD_1_oFDCAN2_756072d1_Tx_1 = 3U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Trailer_Angle, RTE_VAR_INIT) Rte_Trailer_Angle_oTRSCM_FD_1_oFDCAN2_d1a864a3_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Trailer_Angle_Sign, RTE_VAR_INIT) Rte_Trailer_Angle_Sign_oTRSCM_FD_1_oFDCAN2_2b9f0ec4_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Trailer_Calibration, RTE_VAR_INIT) Rte_Trailer_Calibration_oTRSCM_FD_1_oFDCAN2_30ba6b34_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TrlrHitchLight_Cntrl, RTE_VAR_INIT) Rte_TrlrHitchLight_Cntrl_oTRSCM_FD_1_oFDCAN2_ba4f30d9_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(WakeupSource_FD02_PAM, RTE_VAR_INIT) Rte_WakeupSource_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_13de1caf_Tx_1 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_INIT) Rte_SWC_ProxiConfigMgr_PpVariantData_Variant = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(APARequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ASCM_Stat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Brk_Stat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Brk_Stat = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CM_TCH_STAT, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CM_TCH_X_COORD, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CM_TCH_Y_COORD, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CameraDisplaySts2, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(CmdIgnSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(DriverDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(EngineSts_W, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EngineSts_W = 3U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ExternalTemperature, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature = 170U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Fwrd_Cam_Guidelines, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(GearEngaged, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ITBM_TrlrStat, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ITBM_TrlrStat = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(LHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(LanguageSelection, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LanguageSelection = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(LwsAngle, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngle = 7200U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(LwsSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsSpeed = 2000U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAMRequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PAMRequestSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PamChimeVolumeFront, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeFront = 1U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PamChimeVolumeRear, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeRear = 1U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PsngrDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RHRDoorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RHatchSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Rear_Brk_Asst, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Rear_Brk_Asst = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SVC_Guidelines, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_SVC_Guidelines = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ShiftLeverPosition, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TCASERANGESTATUS, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TCASERANGESTATUS = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TGW_CAMERA_DISP_STAT, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TargetGear, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TargetGear = 15U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TrailerConnectionSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(VIN_DATA, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_DATA = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(VIN_MSG, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG = 3U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(VehicleSpeedVSOSig, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_EPS_HandsOnRecognition, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_ESS_ENG_ST_W, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W = 15U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LHFWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LHF_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LHF_Spin, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_Spin = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LHRWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LHR_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LatAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LatAcceleration_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM = 4095U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LongAccelerationFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LongAcceleration_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM = 4095U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LwsAngle, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle = 7200U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LwsAngleType, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngleType = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_LwsSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsSpeed = 2000U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PAM_Brk_Rq_RspSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PdlPosActual, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PdlPosActual = 3U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RHFWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RHF_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RHF_Spin, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_Spin = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RHF_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RHRWheelSpeed, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RHR_FastPulseCounter, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RHR_WheelSensorFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_SPM_Lat_Ctrl_ResponseSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Steering_Column_Torque, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque = 1024U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_VehicleSpeedVSOSig, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_VehicleSpeedVSOSig_B2, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_VehicleStandStillSts, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts = 1U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_YawRateFailSts_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_YawRate_BSM, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRate_BSM = 4095U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_InvalidValueFlag = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_INIT) Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_MissingMessageFlag = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_AliveCntr_MCU2_0, RTE_VAR_INIT) Rte_FD14_1_AliveCntr_MCU2_0_oME_SystemDebugData_1_oFDCAN14_e65282c6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_AliveCntr_MCU2_1, RTE_VAR_INIT) Rte_FD14_1_AliveCntr_MCU2_1_oME_SystemDebugData_1_oFDCAN14_1788876c_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_AliveCntr_MPU1_0, RTE_VAR_INIT) Rte_FD14_1_AliveCntr_MPU1_0_oME_SystemDebugData_1_oFDCAN14_0e75683e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_ErrFaultInfo_MCU2_0, RTE_VAR_INIT) Rte_FD14_1_ErrFaultInfo_MCU2_0_oME_SystemDebugData_1_oFDCAN14_09f994d2_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Err_FaultInfo_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Err_FaultInfo_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f3e84bf0_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Err_FaultInfo_MCU2_1, RTE_VAR_INIT) Rte_FD14_1_Err_FaultInfo_MCU2_1_oME_SystemDebugData_1_oFDCAN14_6fb4bd00_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Err_FaultInfo_MPU1_0, RTE_VAR_INIT) Rte_FD14_1_Err_FaultInfo_MPU1_0_oME_SystemDebugData_1_oFDCAN14_76495252_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Err_FaultNum_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Err_FaultNum_MCU1_0_oME_SystemDebugData_1_oFDCAN14_44f26807_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Err_FaultNum_MCU2_0, RTE_VAR_INIT) Rte_FD14_1_Err_FaultNum_MCU2_0_oME_SystemDebugData_1_oFDCAN14_29749b5d_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Err_FaultNum_MCU2_1, RTE_VAR_INIT) Rte_FD14_1_Err_FaultNum_MCU2_1_oME_SystemDebugData_1_oFDCAN14_d8ae9ef7_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Err_FaultNum_MPU1_0, RTE_VAR_INIT) Rte_FD14_1_Err_FaultNum_MPU1_0_oME_SystemDebugData_1_oFDCAN14_c15371a5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Hook_DtErr_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_DtErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d4fc990e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Hook_Error_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_Error_MCU1_0_oME_SystemDebugData_1_oFDCAN14_082f9b06_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Hook_PresentPtr_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_PresentPtr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_46e0c48b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Hook_Reserved_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_4252166b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Hook_Service_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_Service_MCU1_0_oME_SystemDebugData_1_oFDCAN14_443850ea_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Hook_Type_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_Type_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6517d66f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Hook_actTsk_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_actTsk_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e5cab5c_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Hook_fatalErr_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Hook_fatalErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_db1493b6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_ADFSR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_ADFSR_oME_MCUOsDebugData1_oFDCAN14_56600f18_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_AIFSR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_AIFSR_oME_MCUOsDebugData1_oFDCAN14_d7bd5dfe_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_DFAR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_DFAR_oME_MCUOsDebugData1_oFDCAN14_73a0eaa5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_DFSR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_DFSR_oME_MCUOsDebugData1_oFDCAN14_8011b617_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_IFAR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_IFAR_oME_MCUOsDebugData1_oFDCAN14_f27db843_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_IFSR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_IFSR_oME_MCUOsDebugData1_oFDCAN14_01cce4f1_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Link, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Link_oME_MCUOsDebugData1_oFDCAN14_b350e9be_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_SPSR, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_SPSR_oME_MCUOsDebugData1_oFDCAN14_8d113eaa_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Stack0, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack0_oME_MCUOsDebugData2_oFDCAN14_def0054e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Stack1, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack1_oME_MCUOsDebugData2_oFDCAN14_e290e646_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Stack2, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack2_oME_MCUOsDebugData2_oFDCAN14_a631c35e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Stack3, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack3_oME_MCUOsDebugData2_oFDCAN14_9a512056_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Stack4, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack4_oME_MCUOsDebugData2_oFDCAN14_2f73896e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Stack5, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack5_oME_MCUOsDebugData2_oFDCAN14_13136a66_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Stack6, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack6_oME_MCUOsDebugData2_oFDCAN14_57b24f7e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Stack7, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack7_oME_MCUOsDebugData2_oFDCAN14_6bd2ac76_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Stack8, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack8_oME_MCUOsDebugData2_oFDCAN14_e6861b4f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_OsRegMCU_Stack9, RTE_VAR_INIT) Rte_FD14_1_OsRegMCU_Stack9_oME_MCUOsDebugData2_oFDCAN14_dae6f847_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Reserved_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5ce4f1ef_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Reserved_MCU2_0, RTE_VAR_INIT) Rte_FD14_1_Reserved_MCU2_0_oME_SystemDebugData_1_oFDCAN14_316202b5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Reserved_MCU2_1, RTE_VAR_INIT) Rte_FD14_1_Reserved_MCU2_1_oME_SystemDebugData_1_oFDCAN14_c0b8071f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_Reserved_MPU1_0, RTE_VAR_INIT) Rte_FD14_1_Reserved_MPU1_0_oME_SystemDebugData_1_oFDCAN14_d945e84d_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SDL_Fault_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SDL_Fault_MCU1_0_oME_SystemDebugData_1_oFDCAN14_80e1e586_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData10_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData10_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6272ae84_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData11_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData11_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2cfba52d_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData12_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData12_MCU1_0_oME_SystemDebugData_1_oFDCAN14_ff60b9d6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData13_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData13_MCU1_0_oME_SystemDebugData_1_oFDCAN14_b1e9b27f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData14_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData14_MCU1_0_oME_SystemDebugData_1_oFDCAN14_83278661_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData15_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData15_MCU1_0_oME_SystemDebugData_1_oFDCAN14_cdae8dc8_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData16_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData16_MCU1_0_oME_SystemDebugData_1_oFDCAN14_1e359133_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData17_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData17_MCU1_0_oME_SystemDebugData_1_oFDCAN14_50bc9a9a_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData18_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData18_MCU1_0_oME_SystemDebugData_1_oFDCAN14_7ba9f90f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData1_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData1_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e3538b4_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData2_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData2_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5dae244f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData3_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData3_MCU1_0_oME_SystemDebugData_1_oFDCAN14_13272fe6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData4_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData4_MCU1_0_oME_SystemDebugData_1_oFDCAN14_21e91bf8_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData5_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData5_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6f601051_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData6_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData6_MCU1_0_oME_SystemDebugData_1_oFDCAN14_bcfb0caa_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData7_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData7_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f2720703_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData8_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData8_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d9676496_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_FltData9_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_SSM_FltData9_MCU1_0_oME_SystemDebugData_1_oFDCAN14_97ee6f3f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_SSM_SystemStateReq, RTE_VAR_INIT) Rte_FD14_1_SSM_SystemStateReq_oME_SystemDebugData_1_oFDCAN14_1a98cea3_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_TimeSincePowerON, RTE_VAR_INIT) Rte_FD14_1_TimeSincePowerON_oME_SystemDebugData_1_oFDCAN14_144841c6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_1_WDG_Error_ID_MCU1_0, RTE_VAR_INIT) Rte_FD14_1_WDG_Error_ID_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2488c0c2_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(AUXCamsRQSts, RTE_VAR_INIT) Rte_AUXCamsRQSts_oCVPAM_FD_Info_oFDCAN2_cb5ede6d_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_CHF, RTE_VAR_INIT) Rte_Alert_CHF_oCVPAM_FD_Info_oFDCAN2_10e5899e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_CHR, RTE_VAR_INIT) Rte_Alert_CHR_oCVPAM_FD_Info_oFDCAN2_068868fc_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_LHF, RTE_VAR_INIT) Rte_Alert_LHF_oCVPAM_FD_Info_oFDCAN2_9d0fdf04_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_LHR, RTE_VAR_INIT) Rte_Alert_LHR_oCVPAM_FD_Info_oFDCAN2_8b623e66_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_RHF, RTE_VAR_INIT) Rte_Alert_RHF_oCVPAM_FD_Info_oFDCAN2_5daa7471_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_RHR, RTE_VAR_INIT) Rte_Alert_RHR_oCVPAM_FD_Info_oFDCAN2_4bc79513_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Camera_Status, RTE_VAR_INIT) Rte_Camera_Status_oADAS_FD_LANES_1_oFDCAN2_64f6e4de_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ChimeActivation_LHF, RTE_VAR_INIT) Rte_ChimeActivation_LHF_oCVPAM_FD_Info_oFDCAN2_18ea8591_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ChimeActivation_LHR, RTE_VAR_INIT) Rte_ChimeActivation_LHR_oCVPAM_FD_Info_oFDCAN2_0e8764f3_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ChimeActivation_RHF, RTE_VAR_INIT) Rte_ChimeActivation_RHF_oCVPAM_FD_Info_oFDCAN2_d84f2ee4_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ChimeActivation_RHR, RTE_VAR_INIT) Rte_ChimeActivation_RHR_oCVPAM_FD_Info_oFDCAN2_ce22cf86_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Cntr_ADAS_FD_LANES_1, RTE_VAR_INIT) Rte_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_af11a5df_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Cntr_ADAS_FD_LANES_2, RTE_VAR_INIT) Rte_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_64cb74e2_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(DisplayView2, RTE_VAR_INIT) Rte_DisplayView2_oCVPAM_FD_Info_oFDCAN2_73efd9c8_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FOD_Confidence, RTE_VAR_INIT) Rte_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN2_998d9b03_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FT_PAM_LedControlSts, RTE_VAR_INIT) Rte_FT_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_767c2572_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Frame_Index_Lanes_1, RTE_VAR_INIT) Rte_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN2_1ad54467_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Frame_Index_Lanes_2, RTE_VAR_INIT) Rte_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN2_d10f955a_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FrontSensorSts, RTE_VAR_INIT) Rte_FrontSensorSts_oCVPAM_FD_Info_oFDCAN2_e08a5c16_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_CHF, RTE_VAR_INIT) Rte_Graphic_CHF_oCVPAM_FD_Info_oFDCAN2_4b6ea313_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_CHR, RTE_VAR_INIT) Rte_Graphic_CHR_oCVPAM_FD_Info_oFDCAN2_5d034271_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_LHF, RTE_VAR_INIT) Rte_Graphic_LHF_oCVPAM_FD_Info_oFDCAN2_c684f589_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_LHR, RTE_VAR_INIT) Rte_Graphic_LHR_oCVPAM_FD_Info_oFDCAN2_d0e914eb_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_RHF, RTE_VAR_INIT) Rte_Graphic_RHF_oCVPAM_FD_Info_oFDCAN2_06215efc_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_RHR, RTE_VAR_INIT) Rte_Graphic_RHR_oCVPAM_FD_Info_oFDCAN2_104cbf9e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(HMICode, RTE_VAR_INIT) Rte_HMICode_oCVPAM_FD_Info_oFDCAN2_5dec6edf_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Health_Front_Object_Detection, RTE_VAR_INIT) Rte_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN2_e8d5db74_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Health_Lane_Detection, RTE_VAR_INIT) Rte_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN2_1cdf1820_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ImageDefeatRQSts, RTE_VAR_INIT) Rte_ImageDefeatRQSts_oCVPAM_FD_Info_oFDCAN2_7d4e09fb_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_1_Confidence, RTE_VAR_INIT) Rte_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN2_2534fe9b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_1_Curvature, RTE_VAR_INIT) Rte_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN2_09082d9e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_1_Curvature_Rate, RTE_VAR_INIT) Rte_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_93fb8a81_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_1_End_Range, RTE_VAR_INIT) Rte_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN2_34dd811a_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_1_Heading, RTE_VAR_INIT) Rte_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN2_3e17383d_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_1_Offset, RTE_VAR_INIT) Rte_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN2_ad232516_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_1_Start_Range, RTE_VAR_INIT) Rte_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN2_293a5620_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_1_Type, RTE_VAR_INIT) Rte_Line_1_Type_oADAS_FD_LANES_1_oFDCAN2_3e24410a_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_2_Confidence, RTE_VAR_INIT) Rte_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN2_7f55c1fb_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_2_Curvature, RTE_VAR_INIT) Rte_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN2_6de85660_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_2_Curvature_Rate, RTE_VAR_INIT) Rte_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_70b23d23_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_2_End_Range, RTE_VAR_INIT) Rte_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN2_503dfae4_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_2_Heading, RTE_VAR_INIT) Rte_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN2_5391cb67_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_2_Offset, RTE_VAR_INIT) Rte_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN2_f6349403_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_2_Start_Range, RTE_VAR_INIT) Rte_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN2_64d25647_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_2_Type, RTE_VAR_INIT) Rte_Line_2_Type_oADAS_FD_LANES_1_oFDCAN2_2d0c7879_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_3_Confidence, RTE_VAR_INIT) Rte_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN2_ffa5d6e4_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_3_Curvature, RTE_VAR_INIT) Rte_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN2_f89882f5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_3_Curvature_Rate, RTE_VAR_INIT) Rte_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_98a5ad82_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_3_End_Range, RTE_VAR_INIT) Rte_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN2_c54d2e71_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_3_Heading, RTE_VAR_INIT) Rte_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN2_77139a51_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_3_Offset, RTE_VAR_INIT) Rte_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN2_c0c604f0_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_3_Start_Range, RTE_VAR_INIT) Rte_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN2_e95aaba5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_3_Type, RTE_VAR_INIT) Rte_Line_3_Type_oADAS_FD_LANES_1_oFDCAN2_23eb90a8_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_4_Confidence, RTE_VAR_INIT) Rte_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN2_cb97bf3b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_4_Curvature, RTE_VAR_INIT) Rte_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN2_a428a19c_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_4_Curvature_Rate, RTE_VAR_INIT) Rte_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_6d505426_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_4_End_Range, RTE_VAR_INIT) Rte_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN2_99fd0d18_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_4_Heading, RTE_VAR_INIT) Rte_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN2_889c2dd3_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_4_Offset, RTE_VAR_INIT) Rte_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN2_401bf629_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_4_Start_Range, RTE_VAR_INIT) Rte_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN2_ff025689_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Line_4_Type, RTE_VAR_INIT) Rte_Line_4_Type_oADAS_FD_LANES_1_oFDCAN2_0b5c0a9f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(MAC_ADAS_FD_LANES_1, RTE_VAR_INIT) Rte_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_9c565bdf_Tx = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(MAC_ADAS_FD_LANES_2, RTE_VAR_INIT) Rte_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_578c8ae2_Tx = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(MoreCamsRQSts, RTE_VAR_INIT) Rte_MoreCamsRQSts_oCVPAM_FD_Info_oFDCAN2_ba84adf5_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAMSystemFault, RTE_VAR_INIT) Rte_PAMSystemFault_oCVPAM_FD_Info_oFDCAN2_eab32332_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_CHIME_REP_RATESts, RTE_VAR_INIT) Rte_PAM_CHIME_REP_RATESts_oCVPAM_FD_Info_oFDCAN2_ec85c7c5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_CHIME_TYPE, RTE_VAR_INIT) Rte_PAM_CHIME_TYPE_oCVPAM_FD_Info_oFDCAN2_0558f070_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_LedControlSts, RTE_VAR_INIT) Rte_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_63c5d79e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_Off_Status, RTE_VAR_INIT) Rte_PAM_Off_Status_oCVPAM_FD_Info_oFDCAN2_796d8062_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_Off_Status_2BT, RTE_VAR_INIT) Rte_PAM_Off_Status_2BT_oCVPAM_FD_Info_oFDCAN2_514378c1_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_PopUpRqst, RTE_VAR_INIT) Rte_PAM_PopUpRqst_oCVPAM_FD_Info_oFDCAN2_657f86c2_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_Volume, RTE_VAR_INIT) Rte_PAM_Volume_oCVPAM_FD_Info_oFDCAN2_4f8f6792_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PPPA_TurnIndicatorRqst, RTE_VAR_INIT) Rte_PPPA_TurnIndicatorRqst_oCVPAM_FD_Control_oFDCAN2_507419a7_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ParkingManeuverActive, RTE_VAR_INIT) Rte_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN2_ad1c7c90_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN2_92ae92ff_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RR_PAM_Dist, RTE_VAR_INIT) Rte_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN2_48ca8ca5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RR_PAM_StopControlSts, RTE_VAR_INIT) Rte_RR_PAM_StopControlSts_oCVPAM_FD_Control_oFDCAN2_2f143404_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RearSensorSts, RTE_VAR_INIT) Rte_RearSensorSts_oCVPAM_FD_Info_oFDCAN2_a2ccce85_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Reserved_for_functional_safety, RTE_VAR_INIT) Rte_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN2_82a794a5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SPMControlSts, RTE_VAR_INIT) Rte_SPMControlSts_oCVPAM_FD_Info_oFDCAN2_a3ff073d_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SPMFailSts, RTE_VAR_INIT) Rte_SPMFailSts_oCVPAM_FD_Info_oFDCAN2_85d98ec8_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SPMSystemFault, RTE_VAR_INIT) Rte_SPMSystemFault_oCVPAM_FD_Info_oFDCAN2_c4e3aa9b_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SPM_LedControlSts, RTE_VAR_INIT) Rte_SPM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_3446c3a9_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SPM_Screen_Rqst, RTE_VAR_INIT) Rte_SPM_Screen_Rqst_oCVPAM_FD_Info_oFDCAN2_4e673fb0_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_1_Confidence, RTE_VAR_INIT) Rte_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN2_d5c06647_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_1_ID, RTE_VAR_INIT) Rte_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN2_124eba08_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_1_X1, RTE_VAR_INIT) Rte_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN2_0e62b6bf_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_1_X2, RTE_VAR_INIT) Rte_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN2_fc355b47_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_1_Y1, RTE_VAR_INIT) Rte_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN2_60eeadfe_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_1_Y2, RTE_VAR_INIT) Rte_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN2_92b94006_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_2_Confidence, RTE_VAR_INIT) Rte_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN2_8fa15927_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_2_ID, RTE_VAR_INIT) Rte_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN2_b746d164_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_2_X1, RTE_VAR_INIT) Rte_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN2_ab6addd3_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_2_X2, RTE_VAR_INIT) Rte_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN2_593d302b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_2_Y1, RTE_VAR_INIT) Rte_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN2_c5e6c692_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_2_Y2, RTE_VAR_INIT) Rte_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN2_37b12b6a_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_3_Confidence, RTE_VAR_INIT) Rte_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN2_0f514e38_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_3_ID, RTE_VAR_INIT) Rte_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN2_d4410840_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_3_X1, RTE_VAR_INIT) Rte_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN2_c86d04f7_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_3_X2, RTE_VAR_INIT) Rte_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN2_3a3ae90f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_3_Y1, RTE_VAR_INIT) Rte_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN2_a6e11fb6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_3_Y2, RTE_VAR_INIT) Rte_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN2_54b6f24e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_4_Confidence, RTE_VAR_INIT) Rte_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN2_3b6327e7_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_4_ID, RTE_VAR_INIT) Rte_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN2_262701fd_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_4_X1, RTE_VAR_INIT) Rte_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN2_3a0b0d4a_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_4_X2, RTE_VAR_INIT) Rte_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN2_c85ce0b2_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_4_Y1, RTE_VAR_INIT) Rte_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN2_5487160b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_4_Y2, RTE_VAR_INIT) Rte_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN2_a6d0fbf3_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_5_Confidence, RTE_VAR_INIT) Rte_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN2_bb9330f8_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_5_ID, RTE_VAR_INIT) Rte_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN2_4520d8d9_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_5_X1, RTE_VAR_INIT) Rte_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN2_590cd46e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_5_X2, RTE_VAR_INIT) Rte_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN2_ab5b3996_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_5_Y1, RTE_VAR_INIT) Rte_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN2_3780cf2f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_5_Y2, RTE_VAR_INIT) Rte_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN2_c5d722d7_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_6_Confidence, RTE_VAR_INIT) Rte_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN2_e1f20f98_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_6_ID, RTE_VAR_INIT) Rte_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN2_e028b3b5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_6_X1, RTE_VAR_INIT) Rte_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN2_fc04bf02_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_6_X2, RTE_VAR_INIT) Rte_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN2_0e5352fa_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_6_Y1, RTE_VAR_INIT) Rte_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN2_9288a443_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_6_Y2, RTE_VAR_INIT) Rte_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN2_60df49bb_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_7_Confidence, RTE_VAR_INIT) Rte_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN2_61021887_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_7_ID, RTE_VAR_INIT) Rte_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN2_832f6a91_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_7_X1, RTE_VAR_INIT) Rte_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN2_9f036626_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_7_X2, RTE_VAR_INIT) Rte_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN2_6d548bde_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_7_Y1, RTE_VAR_INIT) Rte_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN2_f18f7d67_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_7_Y2, RTE_VAR_INIT) Rte_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN2_03d8909f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_8_Confidence, RTE_VAR_INIT) Rte_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN2_8996dc26_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_8_ID, RTE_VAR_INIT) Rte_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN2_df95a68e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_8_X1, RTE_VAR_INIT) Rte_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN2_c3b9aa39_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_8_X2, RTE_VAR_INIT) Rte_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN2_31ee47c1_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_8_Y1, RTE_VAR_INIT) Rte_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN2_ad35b178_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Segment_8_Y2, RTE_VAR_INIT) Rte_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN2_5f625c80_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TRSC_LED_Stat, RTE_VAR_INIT) Rte_TRSC_LED_Stat_oCVPAM_FD_Info_oFDCAN2_546afbba_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Camera_Status, RTE_VAR_INIT) Rte_FD14_Camera_Status_oADAS_FD_LANES_1_oFDCAN14_02ee5263_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Cntr_ADAS_FD_LANES_1, RTE_VAR_INIT) Rte_FD14_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_83e8745c_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Cntr_ADAS_FD_LANES_2, RTE_VAR_INIT) Rte_FD14_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_db4be29c_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_FOD_Confidence, RTE_VAR_INIT) Rte_FD14_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN14_07d950b0_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Frame_Index_Lanes_1, RTE_VAR_INIT) Rte_FD14_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN14_09d47624_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Frame_Index_Lanes_2, RTE_VAR_INIT) Rte_FD14_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN14_5177e0e4_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Health_Front_Object_Detection, RTE_VAR_INIT) Rte_FD14_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN14_67ae32c5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Health_Lane_Detection, RTE_VAR_INIT) Rte_FD14_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN14_0b1cd3fa_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_1_Confidence, RTE_VAR_INIT) Rte_FD14_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN14_3d68d9cb_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_1_Curvature, RTE_VAR_INIT) Rte_FD14_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN14_cc3e3dc3_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_1_Curvature_Rate, RTE_VAR_INIT) Rte_FD14_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_aa426416_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_1_End_Range, RTE_VAR_INIT) Rte_FD14_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN14_26d6af56_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_1_Heading, RTE_VAR_INIT) Rte_FD14_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN14_c61fd7b8_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_1_Offset, RTE_VAR_INIT) Rte_FD14_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN14_9798cd20_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_1_Start_Range, RTE_VAR_INIT) Rte_FD14_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN14_0d5038a6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_1_Type, RTE_VAR_INIT) Rte_FD14_Line_1_Type_oADAS_FD_LANES_1_oFDCAN14_dd59b9e0_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_2_Confidence, RTE_VAR_INIT) Rte_FD14_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN14_7080d9ac_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_2_Curvature, RTE_VAR_INIT) Rte_FD14_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN14_965f02a3_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_2_Curvature_Rate, RTE_VAR_INIT) Rte_FD14_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_9279ef65_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_2_End_Range, RTE_VAR_INIT) Rte_FD14_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN14_7cb79036_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_2_Heading, RTE_VAR_INIT) Rte_FD14_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN14_4dcce9a1_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_2_Offset, RTE_VAR_INIT) Rte_FD14_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN14_fa1e3e7a_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_2_Start_Range, RTE_VAR_INIT) Rte_FD14_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN14_decb245d_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_2_Type, RTE_VAR_INIT) Rte_FD14_Line_2_Type_oADAS_FD_LANES_1_oFDCAN14_1446b15f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_3_Confidence, RTE_VAR_INIT) Rte_FD14_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN14_fd08244e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_3_Curvature, RTE_VAR_INIT) Rte_FD14_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN14_16af15bc_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_3_Curvature_Rate, RTE_VAR_INIT) Rte_FD14_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_33406b8b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_3_End_Range, RTE_VAR_INIT) Rte_FD14_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN14_fc478729_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_3_Heading, RTE_VAR_INIT) Rte_FD14_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN14_8252fe69_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_3_Offset, RTE_VAR_INIT) Rte_FD14_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN14_de9c6f4c_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_3_Start_Range, RTE_VAR_INIT) Rte_FD14_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN14_90422ff4_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_3_Type, RTE_VAR_INIT) Rte_FD14_Line_3_Type_oADAS_FD_LANES_1_oFDCAN14_e59cb4f5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_4_Confidence, RTE_VAR_INIT) Rte_FD14_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN14_eb50d962_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_4_Curvature, RTE_VAR_INIT) Rte_FD14_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN14_229d7c63_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_4_Curvature_Rate, RTE_VAR_INIT) Rte_FD14_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_e20ef983_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_4_End_Range, RTE_VAR_INIT) Rte_FD14_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN14_c875eef6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_4_Heading, RTE_VAR_INIT) Rte_FD14_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN14_811b93d2_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_4_Offset, RTE_VAR_INIT) Rte_FD14_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN14_2113d8ce_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_4_Start_Range, RTE_VAR_INIT) Rte_FD14_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN14_a28c1bea_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Line_4_Type, RTE_VAR_INIT) Rte_FD14_Line_4_Type_oADAS_FD_LANES_1_oFDCAN14_5d09a660_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_MAC_ADAS_FD_LANES_1, RTE_VAR_INIT) Rte_FD14_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_cce8ce85_Tx = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_MAC_ADAS_FD_LANES_2, RTE_VAR_INIT) Rte_FD14_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_944b5845_Tx = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_ManoeuvrePhase, RTE_VAR_INIT) Rte_FD14_ManoeuvrePhase_oCVPAM_FD_Control_oFDCAN14_6f7ff602_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_AccelMax, RTE_VAR_INIT) Rte_FD14_PPPA_AccelMax_oCVPAM_FD_Control_oFDCAN14_c98fde99_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_AccelMin, RTE_VAR_INIT) Rte_FD14_PPPA_AccelMin_oCVPAM_FD_Control_oFDCAN14_79b0c4a5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_DecelMax, RTE_VAR_INIT) Rte_FD14_PPPA_DecelMax_oCVPAM_FD_Control_oFDCAN14_55867c47_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_DecelMin, RTE_VAR_INIT) Rte_FD14_PPPA_DecelMin_oCVPAM_FD_Control_oFDCAN14_e5b9667b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_Interface_BSM, RTE_VAR_INIT) Rte_FD14_PPPA_Interface_BSM_oCVPAM_FD_Control_oFDCAN14_5d761341_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_JerkAccelMax, RTE_VAR_INIT) Rte_FD14_PPPA_JerkAccelMax_oCVPAM_FD_Control_oFDCAN14_05f086d0_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_JerkAccelMin, RTE_VAR_INIT) Rte_FD14_PPPA_JerkAccelMin_oCVPAM_FD_Control_oFDCAN14_b5cf9cec_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_JerkDecelMax, RTE_VAR_INIT) Rte_FD14_PPPA_JerkDecelMax_oCVPAM_FD_Control_oFDCAN14_99f9240e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_JerkDecelMin, RTE_VAR_INIT) Rte_FD14_PPPA_JerkDecelMin_oCVPAM_FD_Control_oFDCAN14_29c63e32_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_MaxSpeed, RTE_VAR_INIT) Rte_FD14_PPPA_MaxSpeed_oCVPAM_FD_Control_oFDCAN14_7ef0b86c_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_StandstillRqst, RTE_VAR_INIT) Rte_FD14_PPPA_StandstillRqst_oCVPAM_FD_Control_oFDCAN14_cc940d9b_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_PPPA_TargetDistance, RTE_VAR_INIT) Rte_FD14_PPPA_TargetDistance_oCVPAM_FD_Control_oFDCAN14_3437c295_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_ParkingGearShiftReq, RTE_VAR_INIT) Rte_FD14_ParkingGearShiftReq_oCVPAM_FD_Control_oFDCAN14_47412e73_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_ParkingManeuverActive, RTE_VAR_INIT) Rte_FD14_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN14_2abad8a3_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_FD14_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN14_7700e6e6_Tx = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RR_PAM_Dist, RTE_VAR_INIT) Rte_FD14_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN14_0f3b79a5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Reserved_for_functional_safety, RTE_VAR_INIT) Rte_FD14_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN14_e529cfa2_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_SPM_Lat_Ctrl_RequestSts, RTE_VAR_INIT) Rte_FD14_SPM_Lat_Ctrl_RequestSts_oCVPAM_FD_Control_oFDCAN14_6d94d6ac_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_1_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN14_7d46bee9_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_1_ID, RTE_VAR_INIT) Rte_FD14_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN14_a70622c6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_1_X1, RTE_VAR_INIT) Rte_FD14_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN14_f21f28e5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_1_X2, RTE_VAR_INIT) Rte_FD14_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN14_418b0526_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_1_Y1, RTE_VAR_INIT) Rte_FD14_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN14_f3aad5f8_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_1_Y2, RTE_VAR_INIT) Rte_FD14_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN14_403ef83b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_2_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN14_30aebe8e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_2_ID, RTE_VAR_INIT) Rte_FD14_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN14_e3a707de_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_2_X1, RTE_VAR_INIT) Rte_FD14_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN14_b6be0dfd_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_2_X2, RTE_VAR_INIT) Rte_FD14_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN14_052a203e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_2_Y1, RTE_VAR_INIT) Rte_FD14_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN14_b70bf0e0_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_2_Y2, RTE_VAR_INIT) Rte_FD14_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN14_049fdd23_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_3_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN14_bd26436c_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_3_ID, RTE_VAR_INIT) Rte_FD14_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN14_dfc7e4d6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_3_X1, RTE_VAR_INIT) Rte_FD14_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN14_8adeeef5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_3_X2, RTE_VAR_INIT) Rte_FD14_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN14_394ac336_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_3_Y1, RTE_VAR_INIT) Rte_FD14_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN14_8b6b13e8_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_3_Y2, RTE_VAR_INIT) Rte_FD14_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN14_38ff3e2b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_4_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN14_ab7ebe40_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_4_ID, RTE_VAR_INIT) Rte_FD14_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN14_6ae54dee_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_4_X1, RTE_VAR_INIT) Rte_FD14_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN14_3ffc47cd_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_4_X2, RTE_VAR_INIT) Rte_FD14_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN14_8c686a0e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_4_Y1, RTE_VAR_INIT) Rte_FD14_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN14_3e49bad0_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_4_Y2, RTE_VAR_INIT) Rte_FD14_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN14_8ddd9713_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_5_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN14_26f643a2_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_5_ID, RTE_VAR_INIT) Rte_FD14_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN14_5685aee6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_5_X1, RTE_VAR_INIT) Rte_FD14_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN14_039ca4c5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_5_X2, RTE_VAR_INIT) Rte_FD14_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN14_b0088906_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_5_Y1, RTE_VAR_INIT) Rte_FD14_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN14_022959d8_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_5_Y2, RTE_VAR_INIT) Rte_FD14_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN14_b1bd741b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_6_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN14_6b1e43c5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_6_ID, RTE_VAR_INIT) Rte_FD14_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN14_12248bfe_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_6_X1, RTE_VAR_INIT) Rte_FD14_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN14_473d81dd_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_6_X2, RTE_VAR_INIT) Rte_FD14_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN14_f4a9ac1e_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_6_Y1, RTE_VAR_INIT) Rte_FD14_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN14_46887cc0_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_6_Y2, RTE_VAR_INIT) Rte_FD14_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN14_f51c5103_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_7_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN14_e696be27_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_7_ID, RTE_VAR_INIT) Rte_FD14_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN14_2e4468f6_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_7_X1, RTE_VAR_INIT) Rte_FD14_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN14_7b5d62d5_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_7_X2, RTE_VAR_INIT) Rte_FD14_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN14_c8c94f16_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_7_Y1, RTE_VAR_INIT) Rte_FD14_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN14_7ae89fc8_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_7_Y2, RTE_VAR_INIT) Rte_FD14_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN14_c97cb20b_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_8_Confidence, RTE_VAR_INIT) Rte_FD14_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN14_47afb99d_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_8_ID, RTE_VAR_INIT) Rte_FD14_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN14_a310dfcf_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_8_X1, RTE_VAR_INIT) Rte_FD14_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN14_f609d5ec_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_8_X2, RTE_VAR_INIT) Rte_FD14_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN14_459df82f_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_8_Y1, RTE_VAR_INIT) Rte_FD14_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN14_f7bc28f1_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_Segment_8_Y2, RTE_VAR_INIT) Rte_FD14_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN14_44280532_Tx = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_TorqueOverlaySteeringReq_SPM, RTE_VAR_INIT) Rte_FD14_TorqueOverlaySteeringReq_SPM_oCVPAM_FD_Control_oFDCAN14_593889ae_Tx = 1024U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_CHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHF = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_CHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHR = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHF = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHR = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHF = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Alert_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHR = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ChimeActivation_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHF = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ChimeActivation_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHR = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ChimeActivation_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHF = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ChimeActivation_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHR = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(DisplayView2, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2 = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FrontSensorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FrontSensorSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_CHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHF = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_CHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHR = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHF = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHR = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHF = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Graphic_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHR = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(HMICode, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_HMICode = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ImageDefeatRQSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ImageDefeatRQSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAMSystemFault, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAMSystemFault = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_CHIME_REP_RATESts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_CHIME_TYPE, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_LedControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_LedControlSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_Off_Status, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_PopUpRqst, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_PopUpRqst = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(PAM_Volume, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Volume = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(ParkingManeuverActive, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ParkingManeuverActive = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RR_PAM_Dist, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Dist = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RR_PAM_StopControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RearSensorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RearSensorSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SPMControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMControlSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SPMFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMFailSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SPMSystemFault, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMSystemFault = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SPM_LedControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_LedControlSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SPM_Screen_Rqst, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_Screen_Rqst = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_ManoeuvrePhase, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts = FALSE;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_RR_PAM_Dist, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_SPM_Lat_Ctrl_RequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(FD14_TorqueOverlaySteeringReq_SPM, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM = 1024U;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(IFOD_Outputs_CVPAMFDData_t, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(LMD_Outputs_CVPAMFDData2_t, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t = {
  {0ULL, 0ULL, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
  }, {0ULL, 0ULL, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_PAStateOut_t, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeGuardPAStateOut_TbAP_PAStateOut_t = {
  0U, 0U, 0U, 0U, 0U, 0U, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SvsToVCAN_t, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeGuardSvsToVCAN_SvsToVCAN_t = {
  FALSE, FALSE, FALSE, FALSE, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(TbAP_VCActuatorOut_t, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_INIT) Rte_Safety_Guard_PpSafeState2RSTReason_FaultEnum_u16 = 0U;
/* PRQA L:L1 */

#define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Arr_2Byte, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CDD_Safety_CDD_PMICLastResetReason_BISTStatus_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(INVMSignalManager_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CDD_IPCHandler_FPA_Slot_Data_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_FrontCamSerialNumber_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_LeftCamSerialNumber_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_RearCamSerialNumber_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(FinalAssemblySerialNumber_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_RightCamSerialNumber_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(CDP_TbSVS_S_SVSCamCurrentCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamCurrentCalibData_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(CDP_TbSVS_S_SVSCamEOLCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamEOLCalibData_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(CDP_TbSVS_S_SVSCamOCCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamOCCalibData_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(CDP_TbSVS_S_SVSCamSCCalibData_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_CalDataProvider_SVSCamSCCalibData_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(ME_Hydra2defs_S_CodingTableExt_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_SWC_ProxiConfigMgr_ProxiConfigTable_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(ME_Hydra2defs_S_PROXI_error_Data_t, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_SWC_ProxiConfigMgr_ProxiErrorData_MirrorBlock; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514, 1533 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT) Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock = 0U; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
/* PRQA L:L1 */

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * TxUpdate Flags for each external Tx Signal over Rte_ComSendSignalProxy without IOCs
 *********************************************************************************************************************/
#define RTE_START_SEC_VAR_OsApplication_Safety_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsApplication_Safety_TxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Safety_TxUpdateFlags = {
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U
};

#define RTE_STOP_SEC_VAR_OsApplication_Safety_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsApplication_Safety_TxUpdateFlagsInit() (Rte_MemClr(&Rte_OsApplication_Safety_TxUpdateFlags, sizeof(Rte_OsApplication_Safety_TxUpdateFlagsType)))

/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Update Flags for each Receiver with enableUpdate != 0
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_OsApplication_Safety_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_OsApplication_Safety_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Safety_RxUpdateFlags = {
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U
};

#define RTE_STOP_SEC_VAR_OsApplication_Safety_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_OsApplication_Safety_RxUpdateFlagsInit() (Rte_MemClr(&Rte_OsApplication_Safety_RxUpdateFlags, sizeof(Rte_OsApplication_Safety_RxUpdateFlagsType)))

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


/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_SWC_SafeVCANRx_PpMode_VehicleSpeedCheck_Mode = RTE_MODE_SWC_SafeVCANRx_VehicleSpeedCheck_VehicleSpeedZero; /* PRQA S 3408 */ /* MD_Rte_3408 */
#define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(uint8, RTE_VAR_INIT) Rte_ModeMachine_Safety_Guard_SafetyGuard_SafeState_Mode_Mode = RTE_MODE_Safety_Guard_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL; /* PRQA S 3408 */ /* MD_Rte_3408 */
#define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
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

#define RTE_START_SEC_OSAPPLICATION_SAFETY_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


FUNC(void, RTE_CODE) Rte_InitMemory_OsApplication_Safety(void)
{
  /* reset Tx Update Flags */
  Rte_OsApplication_Safety_TxUpdateFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* initialize flags for update handling */
  Rte_OsApplication_Safety_RxUpdateFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* set default values for internal data */
  Rte_CDD_IPCHandler_PpAPSMPAOut_TbAP_APSMPAOut_t = Rte_C_TbAP_APSMPAOut_t_0;
  Rte_CDD_IPCHandler_PpCAMSelInfo_CAM_select_info_t = Rte_C_CAM_select_info_t_0;
  Rte_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t = Rte_C_IFOD_Outputs_CVPAMFDData_t_0;
  Rte_CDD_IPCHandler_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t = Rte_C_LMD_Outputs_CVPAMFDData2_t_0;
  Rte_CDD_IPCHandler_PpCamCsData_CAM_CS_Curr_Monitor_t = Rte_C_CAM_CS_Curr_Monitor_t_0;
  Rte_CDD_IPCHandler_PpCamEepromData_Svs_CamEepromDataArray_t = Rte_C_Svs_CamEepromDataArray_t_0;
  Rte_CDD_IPCHandler_PpCamSerENStat_Cam_and_Ser_EN_Status_t = Rte_C_Cam_and_Ser_EN_Status_t_0;
  Rte_CDD_IPCHandler_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t = Rte_C_CpuLoadMcu2_0_t_0;
  Rte_CDD_IPCHandler_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t = Rte_C_CpuLoadMcu2_1_t_0;
  Rte_CDD_IPCHandler_PpDLDOutput_JobDLDOutput_t = Rte_C_JobDLDOutput_t_0;
  Rte_CDD_IPCHandler_PpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays = Rte_C_Debug_HMI_Curr_Requested_Overlays_0;
  Rte_CDD_IPCHandler_PpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays = Rte_C_Debug_HMI_Curr_Displayed_Overlays_0;
  Rte_CDD_IPCHandler_PpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig = Rte_C_Debug_HMI_Curr_Displayed_ProxiConfig_0;
  Rte_CDD_IPCHandler_PpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig = Rte_C_Debug_HMI_Curr_Requested_ProxiConfig_0;
  Rte_CDD_IPCHandler_PpDebHmiInput_Debug_HMI_Input_Data_t = Rte_C_Debug_HMI_Input_Data_t_0;
  Rte_CDD_IPCHandler_PpDebHmiInternal_Debug_HMI_Internal_Data_t = Rte_C_Debug_HMI_Internal_Data_t_0;
  Rte_CDD_IPCHandler_PpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t = Rte_C_Debug_HMI_Trailer_Views_Data_t_0;
  Rte_CDD_IPCHandler_PpDetInpTrsc_Detection_Inputs_from_TRSC_t = Rte_C_Detection_Inputs_from_TRSC_t_0;
  Rte_CDD_IPCHandler_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t = Rte_C_TbAP_DriveAssistStatOut_t_0;
  Rte_CDD_IPCHandler_PpErrFltMcu2_0_Error_Fault_MCU2_0_t = Rte_C_Error_Fault_MCU2_0_t_0;
  Rte_CDD_IPCHandler_PpErrFltMcu2_1_Error_Fault_MCU2_1_t = Rte_C_Error_Fault_MCU2_1_t_0;
  Rte_CDD_IPCHandler_PpErrFltMpu1_0_Error_Fault_MPU1_0_t = Rte_C_Error_Fault_MPU1_0_t_0;
  Rte_CDD_IPCHandler_PpFPAWarnOut_TbAP_FPAWarnOut_t = Rte_C_TbAP_FPAWarnOut_t_0;
  Rte_CDD_IPCHandler_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t = Rte_C_TbTHASmVc_FeatureOutputs_t_0;
  Rte_CDD_IPCHandler_PpIDebugFODObject_IDebug_FODObject_t = Rte_C_IDebug_FODObject_t_0;
  Rte_CDD_IPCHandler_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t = Rte_C_IFOD_Outputs_Arbitration_t_0;
  Rte_CDD_IPCHandler_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t = Rte_C_IJobUSSObjectMapOutput_t_0;
  Rte_CDD_IPCHandler_PpJobFPAData_IJobFPAOutput_t = Rte_C_IJobFPAOutput_t_0;
  Rte_CDD_IPCHandler_PpJobPLDData_IJobPLDOutput_t = Rte_C_IJobPLDOutput_t_0;
  Rte_CDD_IPCHandler_PpJobTHADetOutput_JobTHADetOutput_t = Rte_C_JobTHADetOutput_t_0;
  Rte_CDD_IPCHandler_PpKeepAliveResponse_KeepAliveResponse_t = Rte_C_KeepAliveResponse_t_0;
  Rte_CDD_IPCHandler_PpLMDLaneOp_LMD_Lane_Outputs_s = Rte_C_LMD_Lane_Outputs_s_0;
  Rte_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t = Rte_C_ME_Proxi_MPU1_0_to_MCU1_0_t_0;
  Rte_CDD_IPCHandler_PpNFCDOutput_NFCD_Output = Rte_C_NFCD_Output_0;
  Rte_CDD_IPCHandler_PpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t = Rte_C_TbSVS_e_SVSOutputToNVMCamCalibSM_t_0;
  Rte_CDD_IPCHandler_PpNVMSignMgr_NVMSignalManager_t = Rte_C_NVMSignalManager_t_0;
  Rte_CDD_IPCHandler_PpPAM2BTIpcTxStatus_IpcTxDone = FALSE;
  Rte_CDD_IPCHandler_PpPAStateOut_TbAP_PAStateOut_t = Rte_C_TbAP_PAStateOut_t_0;
  Rte_CDD_IPCHandler_PpPointDistOpBuff_US_S_PointDistOutputBuff_t = Rte_C_US_S_PointDistOutputBuff_t_0;
  Rte_CDD_IPCHandler_PpRPAWarnOut_TbAP_RPAWarnOut_t = Rte_C_TbAP_RPAWarnOut_t_0;
  Rte_CDD_IPCHandler_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t = Rte_C_RunTimeStats_MCU2_0_t_0;
  Rte_CDD_IPCHandler_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t = Rte_C_RunTimeStats_MCU2_1_t_0;
  Rte_CDD_IPCHandler_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t = Rte_C_RunTimeStats_MPU1_0_t_0;
  Rte_CDD_IPCHandler_PpSMDAInternal_TbAP_SMDAInternalOut_t = Rte_C_TbAP_SMDAInternalOut_t_0;
  Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_0 = Rte_C_SSM_2_0_CoreStatus_0;
  Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_1 = Rte_C_SSM_2_1_CoreStatus_0;
  Rte_CDD_IPCHandler_PpSR_State_QNX_State_QNX = Rte_C_SSM_QNX_CoreStatus_0;
  Rte_CDD_IPCHandler_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t = Rte_C_TbSVS_S_SVSCamCurrentCalibDataToNVM_t_0;
  Rte_CDD_IPCHandler_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t = Rte_C_TbSVS_S_SVSCamEOLCalibDataToNVM_t_0;
  Rte_CDD_IPCHandler_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t = Rte_C_TbSVS_S_SVSCamOCCalibDataToNVM_t_0;
  Rte_CDD_IPCHandler_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t = Rte_C_TbSVS_S_SVSCamSCCalibDataToNVM_t_0;
  Rte_CDD_IPCHandler_PpSVSNVMData_SVS_NVMData_t = Rte_C_SVS_NVMData_t_0;
  Rte_CDD_IPCHandler_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t = Rte_C_TbSVS_e_SVSOutputToDiagMgrCamCalib_t_0;
  Rte_CDD_IPCHandler_PpSVSToDiag_SVSToDiag_t = Rte_C_SVSToDiag_t_0;
  Rte_CDD_IPCHandler_PpSVStoTRSC_SVStoTRSC_t = Rte_C_SVStoTRSC_t_0;
  Rte_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B = Rte_init_Data_ErrorMgr_ErrorCommPack_1_0_B;
  Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B = Rte_init_Data_ErrorMgr_ErrorCommPack_2_0_B;
  Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B = Rte_init_Data_ErrorMgr_ErrorCommPack_2_1_B;
  Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B = Rte_init_Data_ErrorMgr_ErrorCommPack_QNX_B;
  Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM = Rte_init_Data_ErrorMgr_ErrorCommPack_2_0_QM;
  Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM = Rte_init_Data_ErrorMgr_ErrorCommPack_2_1_QM;
  Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM = Rte_init_Data_ErrorMgr_ErrorCommPack_QNX_QM;
  Rte_CDD_IPCHandler_PpScreenRequest_ScreenRequest_t = Rte_C_ScreenRequest_t_0;
  Rte_CDD_IPCHandler_PpSnrDirEcho_US_S_SnrDirEcho_t = Rte_C_US_S_SnrDirEcho_t_0;
  Rte_CDD_IPCHandler_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t = Rte_C_StackUsage_MCU2_0_t_0;
  Rte_CDD_IPCHandler_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t = Rte_C_StackUsage_MCU2_1_t_0;
  Rte_CDD_IPCHandler_PpSvsToTHA_SvsToTHA_t = Rte_C_SvsToTHA_t_0;
  Rte_CDD_IPCHandler_PpSvsToVCAN_SvsToVCAN_t = Rte_C_SvsToVCAN_t_0;
  Rte_CDD_IPCHandler_PpTRSC_ME_VehOut_TRSC_t = Rte_C_ME_VehOut_TRSC_t_0;
  Rte_CDD_IPCHandler_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t = Rte_C_TRSCSMVCtoDebugCAN_t_0;
  Rte_CDD_IPCHandler_PpTbAPDebugOut_TbAP_DebugOut = Rte_C_TbAP_DebugOut_0;
  Rte_CDD_IPCHandler_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t = Rte_C_TbAP_SMPAInternalOut_t_0;
  Rte_CDD_IPCHandler_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t = Rte_C_TbFA_ArbiterOutput_t_0;
  Rte_CDD_IPCHandler_PpTbFAResetKM_TbFA_ResetKM_t = Rte_C_TbFA_ResetKM_t_0;
  Rte_CDD_IPCHandler_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t = Rte_C_TbTHASmVc_DiagMgr_t_0;
  Rte_CDD_IPCHandler_PpTrailerDetectOP_TrailerDetection_Output_DID_t = Rte_C_TrailerDetection_Output_DID_t_0;
  Rte_CDD_IPCHandler_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t = Rte_C_TRSCSMVCtoSVS_t_0;
  Rte_CDD_IPCHandler_PpTrscToDiag_TRSCtoDiagMgr_t = Rte_C_TRSCtoDiagMgr_t_0;
  Rte_CDD_IPCHandler_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t = Rte_C_TRSC_Inputs_from_TrailerDetection_t_0;
  Rte_CDD_IPCHandler_PpUSSBlockageBit_US_S_BlockageBit_t = Rte_C_US_S_BlockageBit_t_0;
  Rte_CDD_IPCHandler_PpUSSConstantData_US_S_USSConstantData_t = Rte_C_US_S_USSConstantData_t_0;
  Rte_CDD_IPCHandler_PpUSSErrorDiagData_US_S_USSErrorDiagData_t = Rte_C_US_S_USSErrorDiagData_t_0;
  Rte_CDD_IPCHandler_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t = Rte_C_US_S_USSPeriodDiagData_t_0;
  Rte_CDD_IPCHandler_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type = Rte_C_US_S_CsmStateChangeReason_Type_0;
  Rte_CDD_IPCHandler_PpUssDataCollection_US_S_USSDataCollectionData_t = Rte_C_US_S_USSDataCollectionData_t_0;
  Rte_CDD_IPCHandler_PpUssDebugMsg_US_S_DebugMsg_t = Rte_C_US_S_DebugMsg_t_0;
  Rte_CDD_IPCHandler_PpUssMrrgData_US_S_MarriageSensorIDs_t = Rte_C_US_S_MarriageSensorIDs_t_0;
  Rte_CDD_IPCHandler_PpUssPointMapGrp_US_S_PointMapGroup_t = Rte_C_US_S_PointMapGroup_t_0;
  Rte_CDD_IPCHandler_PpUssTunData_UssTunningData_mcu2_1_t = Rte_C_UssTunningData_mcu2_1_t_0;
  Rte_CDD_IPCHandler_PpUssZoneInfo_US_S_ZoneInfo_t = Rte_C_US_S_ZoneInfo_t_0;
  Rte_CDD_IPCHandler_PpVCActuatorOut_TbAP_VCActuatorOut_t = Rte_C_TbAP_VCActuatorOut_t_0;
  Rte_CDD_IPCHandler_PpVCState_TbAP_VCStateOut_t = Rte_C_TbAP_VCStateOut_t_0;
  Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t = Rte_C_WdgCheckpointStatus_t_0;
  Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t = Rte_C_WdgCheckpointStatus_t_0;
  Rte_CDD_IPCHandler_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t = Rte_C_WdgCheckpointStatus_t_0;
  Rte_MemCpy(Rte_CDD_PMIC_PpPMICFaultstatus_Sts, Rte_C_PmicStatus_0, sizeof(PmicStatus)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy(Rte_CDD_PMIC_PpWDGFaultStatus_Sts, Rte_C_WdgFltSts_0, sizeof(WdgFltSts)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy(Rte_CDD_Safety_PpMPUFaultStatus_Sts, Rte_C_MpuFltSts_0, sizeof(MpuFltSts)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy(Rte_CDD_Safety_PpSDLFaultstatus_Sts, Rte_C_Status_0, sizeof(Status)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_CalDataProvider_P_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0 = Rte_C_CalDataProvider_MCU_1_0_Def_0;
  Rte_CalDataProvider_P_Request_BswM_ScCalStatus_requestedMode = 0U;
  Rte_CalDataProvider_PpAPVarTunParam_TbAP_VrntTunParam_t = Rte_C_TbAP_VrntTunParam_t_0;
  Rte_CalDataProvider_PpPreviousCamData_Data = Rte_C_CDP_TbSVS_S_SVSCamCurrentCalibData_t_0;
  Rte_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcAddData_B = Rte_init_Data_DtcAddData_B;
  Rte_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcStatus_B = Rte_init_Data_DtcStatus_B;
  Rte_MemCpy32(Rte_ErrorMgrAgg_1_0_B_P_Errors_B_Errors_B, Rte_init_Errors_B, sizeof(ErrorListArr_B)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_ErrorMgrAgg_1_0_B_P_SafeState_SafeStateOp = Rte_Pkg_ErrorMgrAgg_1_0_B_Constant_init_SafeStateOp;
  Rte_ErrorMgrAgg_1_0_B_P_SafeState2Reason_FaultEnum_u16 = 0U;
  Rte_SWC_ProxiConfigMgr_PpProxiConfigData_ProxiData = Rte_C_ME_Hydra2defs_S_CodingTableExt_t_1;
  Rte_SWC_ProxiConfigMgr_PpProxiErrorData_Error = Rte_C_ME_Hydra2defs_S_PROXI_error_Data_t_0;
  Rte_SWC_ProxiConfigMgr_PpProxiReset_ProxiDataflag_b = FALSE;
  Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Fullautomaticparking = 0U;
  Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PAMConfig_u8 = 0U;
  Rte_SWC_ProxiConfigMgr_PpProxiToSWC_PRX_CanNod27_b = FALSE;
  Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Pamtuningset = 0U;
  Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Parkwithstop_u8 = 0U;
  Rte_SWC_ProxiConfigMgr_PpProxiToSWC_SurroundViewCam_u8 = 0U;
  Rte_SWC_ProxiConfigMgr_PpProxiToSWC_Trailerhitchassist_u8 = 0U;
  Rte_SWC_ProxiConfigMgr_PpProxiToSWC_TyreSz_u16 = 0U;
  Rte_SWC_ProxiConfigMgr_PpVariantData_Variant = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_APARequestSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ASCM_Stat = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Brk_Stat = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_STAT = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_X_COORD = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CM_TCH_Y_COORD = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CameraDisplaySts2 = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_CmdIgnSts = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_DriverDoorSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_EngineSts_W = 3U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ExternalTemperature = 170U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Fwrd_Cam_Guidelines = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_GearEngaged = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ITBM_TrlrStat = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LHRDoorSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LanguageSelection = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsAngle = 7200U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_LwsSpeed = 2000U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PAMRequestSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeFront = 1U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PamChimeVolumeRear = 1U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_PsngrDoorSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHRDoorSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_RHatchSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_Rear_Brk_Asst = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_SVC_Guidelines = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_ShiftLeverPosition = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TCASERANGESTATUS = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TGW_CAMERA_DISP_STAT = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TargetGear = 15U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_TrailerConnectionSts = 0U;
  Rte_MemCpy(Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_DATA, Rte_C_VIN_DATA_0, sizeof(VIN_DATA)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_MSG = 3U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VehicleSpeedVSOSig = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_EPS_HandsOnRecognition = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_ESS_ENG_ST_W = 15U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHFWheelSpeed = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_FastPulseCounter = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_Spin = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHF_WheelSensorFailSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHRWheelSpeed = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_FastPulseCounter = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LHR_WheelSensorFailSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAccelerationFailSts_BSM = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LatAcceleration_BSM = 4095U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAccelerationFailSts_BSM = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LongAcceleration_BSM = 4095U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngle = 7200U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsAngleType = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_LwsSpeed = 2000U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PAM_Brk_Rq_RspSts = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_PdlPosActual = 3U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHFWheelSpeed = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_FastPulseCounter = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_Spin = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHF_WheelSensorFailSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHRWheelSpeed = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_FastPulseCounter = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_RHR_WheelSensorFailSts = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_SPM_Lat_Ctrl_ResponseSts = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_Steering_Column_Torque = 1024U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleSpeedVSOSig_B2 = 0U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_VehicleStandStillSts = 1U;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRateFailSts_BSM = FALSE;
  Rte_SWC_SafeVCANRx_PpToSwcSafeFD14Rx_FD14_YawRate_BSM = 4095U;
  Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_InvalidValueFlag = FALSE;
  Rte_SWC_SafeVCANRx_PpVIN_MessageFault_VIN_MissingMessageFlag = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHF = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHR = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHF = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHR = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHF = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHR = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHF = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHR = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHF = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHR = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2 = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FrontSensorSts = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHF = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHR = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHF = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHR = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHF = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHR = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_HMICode = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ImageDefeatRQSts = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAMSystemFault = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_LedControlSts = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_PopUpRqst = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Volume = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ParkingManeuverActive = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Dist = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RearSensorSts = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMControlSts = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMFailSts = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMSystemFault = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_LedControlSts = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_Screen_Rqst = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts = FALSE;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts = 0U;
  Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM = 1024U;
  Rte_Safety_Guard_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t = Rte_C_IFOD_Outputs_CVPAMFDData_t_0;
  Rte_Safety_Guard_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t = Rte_C_LMD_Outputs_CVPAMFDData2_t_0;
  Rte_Safety_Guard_PpSafeGuardPAStateOut_TbAP_PAStateOut_t = Rte_C_TbAP_PAStateOut_t_0;
  Rte_Safety_Guard_PpSafeGuardSvsToVCAN_SvsToVCAN_t = Rte_C_SvsToVCAN_t_0;
  Rte_Safety_Guard_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t = Rte_C_TbAP_VCActuatorOut_t_0;
  Rte_Safety_Guard_PpSafeState2RSTReason_FaultEnum_u16 = 0U;
  Rte_CurrentCanNMState_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_b8d48ce4_Tx_1 = 0U;
  Rte_CurrentFailSts_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_c3249b61_Tx_1 = FALSE;
  Rte_DES_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4b879cc8_Tx_1 = 0U;
  Rte_Digit_01_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_35ebeb6b_Tx_1 = 0U;
  Rte_Digit_02_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_510b9095_Tx_1 = 0U;
  Rte_Digit_03_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_c47b4400_Tx_1 = 0U;
  Rte_Digit_04_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_98cb6769_Tx_1 = 0U;
  Rte_Digit_05_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_0dbbb3fc_Tx_1 = 0U;
  Rte_Digit_06_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_695bc802_Tx_1 = 0U;
  Rte_Digit_07_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_fc2b1c97_Tx_1 = 0U;
  Rte_Digit_08_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_d03b8ed0_Tx_1 = 0U;
  Rte_Digit_09_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_454b5a45_Tx_1 = 0U;
  Rte_Digit_10_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_206b28e1_Tx_1 = 0U;
  Rte_Digit_11_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_b51bfc74_Tx_1 = 0U;
  Rte_EOL_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ccb11d67_Tx_1 = FALSE;
  Rte_GenericFailSts_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_d914f704_Tx_1 = FALSE;
  Rte_MemCpy(Rte_N_PDU_oDIAGNOSTIC_ROE_FD_PAM_oFDCAN2_32bc31eb_Tx_1, Rte_C_N_PDU_0, sizeof(N_PDU)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_PreviousCanNMState_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ea522b89_Tx_1 = 0U;
  Rte_MemCpy(Rte_StayActiveSource_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_4ba3a17d_Tx_1, Rte_C_StayActiveSource_FD02_PAM_0, sizeof(StayActiveSource_FD02_PAM)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_THA_EPB_Req_oTRSCM_FD_1_oFDCAN2_330530e0_Tx_1 = 0U;
  Rte_THA_STAT_oTRSCM_FD_1_oFDCAN2_ae81c3b8_Tx_1 = 0U;
  Rte_THA_SpeedLimit_Req_oTRSCM_FD_1_oFDCAN2_99923097_Tx_1 = 0U;
  Rte_THA_Speed_Limit_oTRSCM_FD_1_oFDCAN2_7015673d_Tx_1 = 0U;
  Rte_THA_SteeringDamping_oTRSCM_FD_1_oFDCAN2_5077858c_Tx_1 = 100U;
  Rte_THA_SteeringTorqueInfo_oTRSCM_FD_1_oFDCAN2_5437f775_Tx_1 = 1024U;
  Rte_THA_SteeringTorqueReq_oTRSCM_FD_1_oFDCAN2_d5c7823f_Tx_1 = 0U;
  Rte_TRSCMoreCamRQSts_oTRSCM_FD_1_oFDCAN2_6a0ec540_Tx_1 = FALSE;
  Rte_TRSC_PopupDisp_Info_oTRSCM_FD_1_oFDCAN2_53c36afe_Tx_1 = 0U;
  Rte_TRSC_PopupDisp_Info2_oTRSCM_FD_1_oFDCAN2_e00c3444_Tx_1 = 0U;
  Rte_TRSC_STAT_oTRSCM_FD_1_oFDCAN2_37cfdfd9_Tx_1 = 1U;
  Rte_TRSC_SpeedLimit_Req_oTRSCM_FD_1_oFDCAN2_ab040d8c_Tx_1 = 0U;
  Rte_TRSC_SteeringDamping_oTRSCM_FD_1_oFDCAN2_da20da5d_Tx_1 = 128U;
  Rte_TRSC_SteeringTorqueInfo_oTRSCM_FD_1_oFDCAN2_10502d34_Tx_1 = 1024U;
  Rte_TRSC_SteeringTorqueReq_oTRSCM_FD_1_oFDCAN2_b630b053_Tx_1 = 0U;
  Rte_TRSC_VehicleStop_Req_oTRSCM_FD_1_oFDCAN2_756072d1_Tx_1 = 3U;
  Rte_Trailer_Angle_oTRSCM_FD_1_oFDCAN2_d1a864a3_Tx_1 = 0U;
  Rte_Trailer_Angle_Sign_oTRSCM_FD_1_oFDCAN2_2b9f0ec4_Tx_1 = 0U;
  Rte_Trailer_Calibration_oTRSCM_FD_1_oFDCAN2_30ba6b34_Tx_1 = 0U;
  Rte_TrlrHitchLight_Cntrl_oTRSCM_FD_1_oFDCAN2_ba4f30d9_Tx_1 = 0U;
  Rte_WakeupSource_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_13de1caf_Tx_1 = 0U;
  Rte_FD14_1_AliveCntr_MCU2_0_oME_SystemDebugData_1_oFDCAN14_e65282c6_Tx = 0U;
  Rte_FD14_1_AliveCntr_MCU2_1_oME_SystemDebugData_1_oFDCAN14_1788876c_Tx = 0U;
  Rte_FD14_1_AliveCntr_MPU1_0_oME_SystemDebugData_1_oFDCAN14_0e75683e_Tx = 0U;
  Rte_FD14_1_ErrFaultInfo_MCU2_0_oME_SystemDebugData_1_oFDCAN14_09f994d2_Tx = 0U;
  Rte_FD14_1_Err_FaultInfo_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f3e84bf0_Tx = 0U;
  Rte_FD14_1_Err_FaultInfo_MCU2_1_oME_SystemDebugData_1_oFDCAN14_6fb4bd00_Tx = 0U;
  Rte_FD14_1_Err_FaultInfo_MPU1_0_oME_SystemDebugData_1_oFDCAN14_76495252_Tx = 0U;
  Rte_FD14_1_Err_FaultNum_MCU1_0_oME_SystemDebugData_1_oFDCAN14_44f26807_Tx = 0U;
  Rte_FD14_1_Err_FaultNum_MCU2_0_oME_SystemDebugData_1_oFDCAN14_29749b5d_Tx = 0U;
  Rte_FD14_1_Err_FaultNum_MCU2_1_oME_SystemDebugData_1_oFDCAN14_d8ae9ef7_Tx = 0U;
  Rte_FD14_1_Err_FaultNum_MPU1_0_oME_SystemDebugData_1_oFDCAN14_c15371a5_Tx = 0U;
  Rte_FD14_1_Hook_DtErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d4fc990e_Tx = 0U;
  Rte_FD14_1_Hook_Error_MCU1_0_oME_SystemDebugData_1_oFDCAN14_082f9b06_Tx = 0U;
  Rte_FD14_1_Hook_PresentPtr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_46e0c48b_Tx = 0U;
  Rte_FD14_1_Hook_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_4252166b_Tx = 0U;
  Rte_FD14_1_Hook_Service_MCU1_0_oME_SystemDebugData_1_oFDCAN14_443850ea_Tx = 0U;
  Rte_FD14_1_Hook_Type_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6517d66f_Tx = 0U;
  Rte_FD14_1_Hook_actTsk_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e5cab5c_Tx = 0U;
  Rte_FD14_1_Hook_fatalErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_db1493b6_Tx = 0U;
  Rte_FD14_1_OsRegMCU_ADFSR_oME_MCUOsDebugData1_oFDCAN14_56600f18_Tx = 0U;
  Rte_FD14_1_OsRegMCU_AIFSR_oME_MCUOsDebugData1_oFDCAN14_d7bd5dfe_Tx = 0U;
  Rte_FD14_1_OsRegMCU_DFAR_oME_MCUOsDebugData1_oFDCAN14_73a0eaa5_Tx = 0U;
  Rte_FD14_1_OsRegMCU_DFSR_oME_MCUOsDebugData1_oFDCAN14_8011b617_Tx = 0U;
  Rte_FD14_1_OsRegMCU_IFAR_oME_MCUOsDebugData1_oFDCAN14_f27db843_Tx = 0U;
  Rte_FD14_1_OsRegMCU_IFSR_oME_MCUOsDebugData1_oFDCAN14_01cce4f1_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Link_oME_MCUOsDebugData1_oFDCAN14_b350e9be_Tx = 0U;
  Rte_FD14_1_OsRegMCU_SPSR_oME_MCUOsDebugData1_oFDCAN14_8d113eaa_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Stack0_oME_MCUOsDebugData2_oFDCAN14_def0054e_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Stack1_oME_MCUOsDebugData2_oFDCAN14_e290e646_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Stack2_oME_MCUOsDebugData2_oFDCAN14_a631c35e_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Stack3_oME_MCUOsDebugData2_oFDCAN14_9a512056_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Stack4_oME_MCUOsDebugData2_oFDCAN14_2f73896e_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Stack5_oME_MCUOsDebugData2_oFDCAN14_13136a66_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Stack6_oME_MCUOsDebugData2_oFDCAN14_57b24f7e_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Stack7_oME_MCUOsDebugData2_oFDCAN14_6bd2ac76_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Stack8_oME_MCUOsDebugData2_oFDCAN14_e6861b4f_Tx = 0U;
  Rte_FD14_1_OsRegMCU_Stack9_oME_MCUOsDebugData2_oFDCAN14_dae6f847_Tx = 0U;
  Rte_FD14_1_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5ce4f1ef_Tx = 0U;
  Rte_FD14_1_Reserved_MCU2_0_oME_SystemDebugData_1_oFDCAN14_316202b5_Tx = 0U;
  Rte_FD14_1_Reserved_MCU2_1_oME_SystemDebugData_1_oFDCAN14_c0b8071f_Tx = 0U;
  Rte_FD14_1_Reserved_MPU1_0_oME_SystemDebugData_1_oFDCAN14_d945e84d_Tx = 0U;
  Rte_FD14_1_SDL_Fault_MCU1_0_oME_SystemDebugData_1_oFDCAN14_80e1e586_Tx = 0U;
  Rte_FD14_1_SSM_FltData10_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6272ae84_Tx = 0U;
  Rte_FD14_1_SSM_FltData11_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2cfba52d_Tx = 0U;
  Rte_FD14_1_SSM_FltData12_MCU1_0_oME_SystemDebugData_1_oFDCAN14_ff60b9d6_Tx = 0U;
  Rte_FD14_1_SSM_FltData13_MCU1_0_oME_SystemDebugData_1_oFDCAN14_b1e9b27f_Tx = 0U;
  Rte_FD14_1_SSM_FltData14_MCU1_0_oME_SystemDebugData_1_oFDCAN14_83278661_Tx = 0U;
  Rte_FD14_1_SSM_FltData15_MCU1_0_oME_SystemDebugData_1_oFDCAN14_cdae8dc8_Tx = 0U;
  Rte_FD14_1_SSM_FltData16_MCU1_0_oME_SystemDebugData_1_oFDCAN14_1e359133_Tx = 0U;
  Rte_FD14_1_SSM_FltData17_MCU1_0_oME_SystemDebugData_1_oFDCAN14_50bc9a9a_Tx = 0U;
  Rte_FD14_1_SSM_FltData18_MCU1_0_oME_SystemDebugData_1_oFDCAN14_7ba9f90f_Tx = 0U;
  Rte_FD14_1_SSM_FltData1_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e3538b4_Tx = 0U;
  Rte_FD14_1_SSM_FltData2_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5dae244f_Tx = 0U;
  Rte_FD14_1_SSM_FltData3_MCU1_0_oME_SystemDebugData_1_oFDCAN14_13272fe6_Tx = 0U;
  Rte_FD14_1_SSM_FltData4_MCU1_0_oME_SystemDebugData_1_oFDCAN14_21e91bf8_Tx = 0U;
  Rte_FD14_1_SSM_FltData5_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6f601051_Tx = 0U;
  Rte_FD14_1_SSM_FltData6_MCU1_0_oME_SystemDebugData_1_oFDCAN14_bcfb0caa_Tx = 0U;
  Rte_FD14_1_SSM_FltData7_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f2720703_Tx = 0U;
  Rte_FD14_1_SSM_FltData8_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d9676496_Tx = 0U;
  Rte_FD14_1_SSM_FltData9_MCU1_0_oME_SystemDebugData_1_oFDCAN14_97ee6f3f_Tx = 0U;
  Rte_FD14_1_SSM_SystemStateReq_oME_SystemDebugData_1_oFDCAN14_1a98cea3_Tx = 0U;
  Rte_FD14_1_TimeSincePowerON_oME_SystemDebugData_1_oFDCAN14_144841c6_Tx = 0U;
  Rte_FD14_1_WDG_Error_ID_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2488c0c2_Tx = 0U;
  Rte_AUXCamsRQSts_oCVPAM_FD_Info_oFDCAN2_cb5ede6d_Tx = FALSE;
  Rte_Alert_CHF_oCVPAM_FD_Info_oFDCAN2_10e5899e_Tx = 0U;
  Rte_Alert_CHR_oCVPAM_FD_Info_oFDCAN2_068868fc_Tx = 0U;
  Rte_Alert_LHF_oCVPAM_FD_Info_oFDCAN2_9d0fdf04_Tx = 0U;
  Rte_Alert_LHR_oCVPAM_FD_Info_oFDCAN2_8b623e66_Tx = 0U;
  Rte_Alert_RHF_oCVPAM_FD_Info_oFDCAN2_5daa7471_Tx = 0U;
  Rte_Alert_RHR_oCVPAM_FD_Info_oFDCAN2_4bc79513_Tx = 0U;
  Rte_Camera_Status_oADAS_FD_LANES_1_oFDCAN2_64f6e4de_Tx = 0U;
  Rte_ChimeActivation_LHF_oCVPAM_FD_Info_oFDCAN2_18ea8591_Tx = FALSE;
  Rte_ChimeActivation_LHR_oCVPAM_FD_Info_oFDCAN2_0e8764f3_Tx = FALSE;
  Rte_ChimeActivation_RHF_oCVPAM_FD_Info_oFDCAN2_d84f2ee4_Tx = FALSE;
  Rte_ChimeActivation_RHR_oCVPAM_FD_Info_oFDCAN2_ce22cf86_Tx = FALSE;
  Rte_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_af11a5df_Tx = 0U;
  Rte_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_64cb74e2_Tx = 0U;
  Rte_DisplayView2_oCVPAM_FD_Info_oFDCAN2_73efd9c8_Tx = 0U;
  Rte_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN2_998d9b03_Tx = 0U;
  Rte_FT_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_767c2572_Tx = 0U;
  Rte_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN2_1ad54467_Tx = 0U;
  Rte_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN2_d10f955a_Tx = 0U;
  Rte_FrontSensorSts_oCVPAM_FD_Info_oFDCAN2_e08a5c16_Tx = 0U;
  Rte_Graphic_CHF_oCVPAM_FD_Info_oFDCAN2_4b6ea313_Tx = 0U;
  Rte_Graphic_CHR_oCVPAM_FD_Info_oFDCAN2_5d034271_Tx = 0U;
  Rte_Graphic_LHF_oCVPAM_FD_Info_oFDCAN2_c684f589_Tx = 0U;
  Rte_Graphic_LHR_oCVPAM_FD_Info_oFDCAN2_d0e914eb_Tx = 0U;
  Rte_Graphic_RHF_oCVPAM_FD_Info_oFDCAN2_06215efc_Tx = 0U;
  Rte_Graphic_RHR_oCVPAM_FD_Info_oFDCAN2_104cbf9e_Tx = 0U;
  Rte_HMICode_oCVPAM_FD_Info_oFDCAN2_5dec6edf_Tx = 0U;
  Rte_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN2_e8d5db74_Tx = 0U;
  Rte_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN2_1cdf1820_Tx = 0U;
  Rte_ImageDefeatRQSts_oCVPAM_FD_Info_oFDCAN2_7d4e09fb_Tx = FALSE;
  Rte_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN2_2534fe9b_Tx = 0U;
  Rte_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN2_09082d9e_Tx = 0U;
  Rte_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_93fb8a81_Tx = 0U;
  Rte_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN2_34dd811a_Tx = 0U;
  Rte_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN2_3e17383d_Tx = 0U;
  Rte_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN2_ad232516_Tx = 0U;
  Rte_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN2_293a5620_Tx = 0U;
  Rte_Line_1_Type_oADAS_FD_LANES_1_oFDCAN2_3e24410a_Tx = 0U;
  Rte_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN2_7f55c1fb_Tx = 0U;
  Rte_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN2_6de85660_Tx = 0U;
  Rte_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_70b23d23_Tx = 0U;
  Rte_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN2_503dfae4_Tx = 0U;
  Rte_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN2_5391cb67_Tx = 0U;
  Rte_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN2_f6349403_Tx = 0U;
  Rte_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN2_64d25647_Tx = 0U;
  Rte_Line_2_Type_oADAS_FD_LANES_1_oFDCAN2_2d0c7879_Tx = 0U;
  Rte_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN2_ffa5d6e4_Tx = 0U;
  Rte_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN2_f89882f5_Tx = 0U;
  Rte_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_98a5ad82_Tx = 0U;
  Rte_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN2_c54d2e71_Tx = 0U;
  Rte_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN2_77139a51_Tx = 0U;
  Rte_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN2_c0c604f0_Tx = 0U;
  Rte_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN2_e95aaba5_Tx = 0U;
  Rte_Line_3_Type_oADAS_FD_LANES_1_oFDCAN2_23eb90a8_Tx = 0U;
  Rte_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN2_cb97bf3b_Tx = 0U;
  Rte_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN2_a428a19c_Tx = 0U;
  Rte_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_6d505426_Tx = 0U;
  Rte_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN2_99fd0d18_Tx = 0U;
  Rte_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN2_889c2dd3_Tx = 0U;
  Rte_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN2_401bf629_Tx = 0U;
  Rte_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN2_ff025689_Tx = 0U;
  Rte_Line_4_Type_oADAS_FD_LANES_1_oFDCAN2_0b5c0a9f_Tx = 0U;
  Rte_MemCpy(Rte_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_9c565bdf_Tx, Rte_C_MAC_ADAS_FD_LANES_1_0, sizeof(MAC_ADAS_FD_LANES_1)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy(Rte_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_578c8ae2_Tx, Rte_C_MAC_ADAS_FD_LANES_2_0, sizeof(MAC_ADAS_FD_LANES_2)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MoreCamsRQSts_oCVPAM_FD_Info_oFDCAN2_ba84adf5_Tx = FALSE;
  Rte_PAMSystemFault_oCVPAM_FD_Info_oFDCAN2_eab32332_Tx = 0U;
  Rte_PAM_CHIME_REP_RATESts_oCVPAM_FD_Info_oFDCAN2_ec85c7c5_Tx = 0U;
  Rte_PAM_CHIME_TYPE_oCVPAM_FD_Info_oFDCAN2_0558f070_Tx = 0U;
  Rte_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_63c5d79e_Tx = 0U;
  Rte_PAM_Off_Status_oCVPAM_FD_Info_oFDCAN2_796d8062_Tx = FALSE;
  Rte_PAM_Off_Status_2BT_oCVPAM_FD_Info_oFDCAN2_514378c1_Tx = 0U;
  Rte_PAM_PopUpRqst_oCVPAM_FD_Info_oFDCAN2_657f86c2_Tx = 0U;
  Rte_PAM_Volume_oCVPAM_FD_Info_oFDCAN2_4f8f6792_Tx = 0U;
  Rte_PPPA_TurnIndicatorRqst_oCVPAM_FD_Control_oFDCAN2_507419a7_Tx = 0U;
  Rte_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN2_ad1c7c90_Tx = 0U;
  Rte_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN2_92ae92ff_Tx = FALSE;
  Rte_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN2_48ca8ca5_Tx = 0U;
  Rte_RR_PAM_StopControlSts_oCVPAM_FD_Control_oFDCAN2_2f143404_Tx = FALSE;
  Rte_RearSensorSts_oCVPAM_FD_Info_oFDCAN2_a2ccce85_Tx = 0U;
  Rte_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN2_82a794a5_Tx = 0U;
  Rte_SPMControlSts_oCVPAM_FD_Info_oFDCAN2_a3ff073d_Tx = 0U;
  Rte_SPMFailSts_oCVPAM_FD_Info_oFDCAN2_85d98ec8_Tx = FALSE;
  Rte_SPMSystemFault_oCVPAM_FD_Info_oFDCAN2_c4e3aa9b_Tx = FALSE;
  Rte_SPM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_3446c3a9_Tx = 0U;
  Rte_SPM_Screen_Rqst_oCVPAM_FD_Info_oFDCAN2_4e673fb0_Tx = FALSE;
  Rte_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN2_d5c06647_Tx = 0U;
  Rte_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN2_124eba08_Tx = 0U;
  Rte_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN2_0e62b6bf_Tx = 0U;
  Rte_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN2_fc355b47_Tx = 0U;
  Rte_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN2_60eeadfe_Tx = 0U;
  Rte_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN2_92b94006_Tx = 0U;
  Rte_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN2_8fa15927_Tx = 0U;
  Rte_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN2_b746d164_Tx = 0U;
  Rte_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN2_ab6addd3_Tx = 0U;
  Rte_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN2_593d302b_Tx = 0U;
  Rte_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN2_c5e6c692_Tx = 0U;
  Rte_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN2_37b12b6a_Tx = 0U;
  Rte_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN2_0f514e38_Tx = 0U;
  Rte_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN2_d4410840_Tx = 0U;
  Rte_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN2_c86d04f7_Tx = 0U;
  Rte_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN2_3a3ae90f_Tx = 0U;
  Rte_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN2_a6e11fb6_Tx = 0U;
  Rte_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN2_54b6f24e_Tx = 0U;
  Rte_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN2_3b6327e7_Tx = 0U;
  Rte_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN2_262701fd_Tx = 0U;
  Rte_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN2_3a0b0d4a_Tx = 0U;
  Rte_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN2_c85ce0b2_Tx = 0U;
  Rte_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN2_5487160b_Tx = 0U;
  Rte_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN2_a6d0fbf3_Tx = 0U;
  Rte_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN2_bb9330f8_Tx = 0U;
  Rte_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN2_4520d8d9_Tx = 0U;
  Rte_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN2_590cd46e_Tx = 0U;
  Rte_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN2_ab5b3996_Tx = 0U;
  Rte_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN2_3780cf2f_Tx = 0U;
  Rte_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN2_c5d722d7_Tx = 0U;
  Rte_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN2_e1f20f98_Tx = 0U;
  Rte_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN2_e028b3b5_Tx = 0U;
  Rte_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN2_fc04bf02_Tx = 0U;
  Rte_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN2_0e5352fa_Tx = 0U;
  Rte_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN2_9288a443_Tx = 0U;
  Rte_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN2_60df49bb_Tx = 0U;
  Rte_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN2_61021887_Tx = 0U;
  Rte_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN2_832f6a91_Tx = 0U;
  Rte_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN2_9f036626_Tx = 0U;
  Rte_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN2_6d548bde_Tx = 0U;
  Rte_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN2_f18f7d67_Tx = 0U;
  Rte_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN2_03d8909f_Tx = 0U;
  Rte_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN2_8996dc26_Tx = 0U;
  Rte_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN2_df95a68e_Tx = 0U;
  Rte_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN2_c3b9aa39_Tx = 0U;
  Rte_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN2_31ee47c1_Tx = 0U;
  Rte_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN2_ad35b178_Tx = 0U;
  Rte_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN2_5f625c80_Tx = 0U;
  Rte_TRSC_LED_Stat_oCVPAM_FD_Info_oFDCAN2_546afbba_Tx = 0U;
  Rte_FD14_Camera_Status_oADAS_FD_LANES_1_oFDCAN14_02ee5263_Tx = 0U;
  Rte_FD14_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_83e8745c_Tx = 0U;
  Rte_FD14_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_db4be29c_Tx = 0U;
  Rte_FD14_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN14_07d950b0_Tx = 0U;
  Rte_FD14_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN14_09d47624_Tx = 0U;
  Rte_FD14_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN14_5177e0e4_Tx = 0U;
  Rte_FD14_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN14_67ae32c5_Tx = 0U;
  Rte_FD14_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN14_0b1cd3fa_Tx = 0U;
  Rte_FD14_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN14_3d68d9cb_Tx = 0U;
  Rte_FD14_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN14_cc3e3dc3_Tx = 0U;
  Rte_FD14_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_aa426416_Tx = 0U;
  Rte_FD14_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN14_26d6af56_Tx = 0U;
  Rte_FD14_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN14_c61fd7b8_Tx = 0U;
  Rte_FD14_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN14_9798cd20_Tx = 0U;
  Rte_FD14_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN14_0d5038a6_Tx = 0U;
  Rte_FD14_Line_1_Type_oADAS_FD_LANES_1_oFDCAN14_dd59b9e0_Tx = 0U;
  Rte_FD14_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN14_7080d9ac_Tx = 0U;
  Rte_FD14_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN14_965f02a3_Tx = 0U;
  Rte_FD14_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_9279ef65_Tx = 0U;
  Rte_FD14_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN14_7cb79036_Tx = 0U;
  Rte_FD14_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN14_4dcce9a1_Tx = 0U;
  Rte_FD14_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN14_fa1e3e7a_Tx = 0U;
  Rte_FD14_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN14_decb245d_Tx = 0U;
  Rte_FD14_Line_2_Type_oADAS_FD_LANES_1_oFDCAN14_1446b15f_Tx = 0U;
  Rte_FD14_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN14_fd08244e_Tx = 0U;
  Rte_FD14_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN14_16af15bc_Tx = 0U;
  Rte_FD14_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_33406b8b_Tx = 0U;
  Rte_FD14_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN14_fc478729_Tx = 0U;
  Rte_FD14_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN14_8252fe69_Tx = 0U;
  Rte_FD14_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN14_de9c6f4c_Tx = 0U;
  Rte_FD14_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN14_90422ff4_Tx = 0U;
  Rte_FD14_Line_3_Type_oADAS_FD_LANES_1_oFDCAN14_e59cb4f5_Tx = 0U;
  Rte_FD14_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN14_eb50d962_Tx = 0U;
  Rte_FD14_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN14_229d7c63_Tx = 0U;
  Rte_FD14_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_e20ef983_Tx = 0U;
  Rte_FD14_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN14_c875eef6_Tx = 0U;
  Rte_FD14_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN14_811b93d2_Tx = 0U;
  Rte_FD14_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN14_2113d8ce_Tx = 0U;
  Rte_FD14_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN14_a28c1bea_Tx = 0U;
  Rte_FD14_Line_4_Type_oADAS_FD_LANES_1_oFDCAN14_5d09a660_Tx = 0U;
  Rte_MemCpy(Rte_FD14_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_cce8ce85_Tx, Rte_C_FD14_MAC_ADAS_FD_LANES_1_0, sizeof(FD14_MAC_ADAS_FD_LANES_1)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy(Rte_FD14_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_944b5845_Tx, Rte_C_FD14_MAC_ADAS_FD_LANES_2_0, sizeof(FD14_MAC_ADAS_FD_LANES_2)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_FD14_ManoeuvrePhase_oCVPAM_FD_Control_oFDCAN14_6f7ff602_Tx = FALSE;
  Rte_FD14_PPPA_AccelMax_oCVPAM_FD_Control_oFDCAN14_c98fde99_Tx = 0U;
  Rte_FD14_PPPA_AccelMin_oCVPAM_FD_Control_oFDCAN14_79b0c4a5_Tx = 0U;
  Rte_FD14_PPPA_DecelMax_oCVPAM_FD_Control_oFDCAN14_55867c47_Tx = 0U;
  Rte_FD14_PPPA_DecelMin_oCVPAM_FD_Control_oFDCAN14_e5b9667b_Tx = 0U;
  Rte_FD14_PPPA_Interface_BSM_oCVPAM_FD_Control_oFDCAN14_5d761341_Tx = 0U;
  Rte_FD14_PPPA_JerkAccelMax_oCVPAM_FD_Control_oFDCAN14_05f086d0_Tx = 0U;
  Rte_FD14_PPPA_JerkAccelMin_oCVPAM_FD_Control_oFDCAN14_b5cf9cec_Tx = 0U;
  Rte_FD14_PPPA_JerkDecelMax_oCVPAM_FD_Control_oFDCAN14_99f9240e_Tx = 0U;
  Rte_FD14_PPPA_JerkDecelMin_oCVPAM_FD_Control_oFDCAN14_29c63e32_Tx = 0U;
  Rte_FD14_PPPA_MaxSpeed_oCVPAM_FD_Control_oFDCAN14_7ef0b86c_Tx = 0U;
  Rte_FD14_PPPA_StandstillRqst_oCVPAM_FD_Control_oFDCAN14_cc940d9b_Tx = FALSE;
  Rte_FD14_PPPA_TargetDistance_oCVPAM_FD_Control_oFDCAN14_3437c295_Tx = 0U;
  Rte_FD14_ParkingGearShiftReq_oCVPAM_FD_Control_oFDCAN14_47412e73_Tx = 0U;
  Rte_FD14_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN14_2abad8a3_Tx = 0U;
  Rte_FD14_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN14_7700e6e6_Tx = FALSE;
  Rte_FD14_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN14_0f3b79a5_Tx = 0U;
  Rte_FD14_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN14_e529cfa2_Tx = 0U;
  Rte_FD14_SPM_Lat_Ctrl_RequestSts_oCVPAM_FD_Control_oFDCAN14_6d94d6ac_Tx = 0U;
  Rte_FD14_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN14_7d46bee9_Tx = 0U;
  Rte_FD14_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN14_a70622c6_Tx = 0U;
  Rte_FD14_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN14_f21f28e5_Tx = 0U;
  Rte_FD14_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN14_418b0526_Tx = 0U;
  Rte_FD14_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN14_f3aad5f8_Tx = 0U;
  Rte_FD14_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN14_403ef83b_Tx = 0U;
  Rte_FD14_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN14_30aebe8e_Tx = 0U;
  Rte_FD14_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN14_e3a707de_Tx = 0U;
  Rte_FD14_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN14_b6be0dfd_Tx = 0U;
  Rte_FD14_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN14_052a203e_Tx = 0U;
  Rte_FD14_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN14_b70bf0e0_Tx = 0U;
  Rte_FD14_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN14_049fdd23_Tx = 0U;
  Rte_FD14_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN14_bd26436c_Tx = 0U;
  Rte_FD14_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN14_dfc7e4d6_Tx = 0U;
  Rte_FD14_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN14_8adeeef5_Tx = 0U;
  Rte_FD14_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN14_394ac336_Tx = 0U;
  Rte_FD14_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN14_8b6b13e8_Tx = 0U;
  Rte_FD14_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN14_38ff3e2b_Tx = 0U;
  Rte_FD14_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN14_ab7ebe40_Tx = 0U;
  Rte_FD14_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN14_6ae54dee_Tx = 0U;
  Rte_FD14_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN14_3ffc47cd_Tx = 0U;
  Rte_FD14_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN14_8c686a0e_Tx = 0U;
  Rte_FD14_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN14_3e49bad0_Tx = 0U;
  Rte_FD14_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN14_8ddd9713_Tx = 0U;
  Rte_FD14_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN14_26f643a2_Tx = 0U;
  Rte_FD14_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN14_5685aee6_Tx = 0U;
  Rte_FD14_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN14_039ca4c5_Tx = 0U;
  Rte_FD14_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN14_b0088906_Tx = 0U;
  Rte_FD14_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN14_022959d8_Tx = 0U;
  Rte_FD14_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN14_b1bd741b_Tx = 0U;
  Rte_FD14_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN14_6b1e43c5_Tx = 0U;
  Rte_FD14_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN14_12248bfe_Tx = 0U;
  Rte_FD14_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN14_473d81dd_Tx = 0U;
  Rte_FD14_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN14_f4a9ac1e_Tx = 0U;
  Rte_FD14_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN14_46887cc0_Tx = 0U;
  Rte_FD14_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN14_f51c5103_Tx = 0U;
  Rte_FD14_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN14_e696be27_Tx = 0U;
  Rte_FD14_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN14_2e4468f6_Tx = 0U;
  Rte_FD14_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN14_7b5d62d5_Tx = 0U;
  Rte_FD14_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN14_c8c94f16_Tx = 0U;
  Rte_FD14_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN14_7ae89fc8_Tx = 0U;
  Rte_FD14_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN14_c97cb20b_Tx = 0U;
  Rte_FD14_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN14_47afb99d_Tx = 0U;
  Rte_FD14_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN14_a310dfcf_Tx = 0U;
  Rte_FD14_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN14_f609d5ec_Tx = 0U;
  Rte_FD14_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN14_459df82f_Tx = 0U;
  Rte_FD14_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN14_f7bc28f1_Tx = 0U;
  Rte_FD14_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN14_44280532_Tx = 0U;
  Rte_FD14_TorqueOverlaySteeringReq_SPM_oCVPAM_FD_Control_oFDCAN14_593889ae_Tx = 1024U;

  /* initialize per-instance memory variables */
  Rte_CDD_IPCHandler_FeatureAP_HMI_NvMData_MirrorBlock = 0U;
  /* mode management initialization part 1 */

  Rte_ModeMachine_SWC_SafeVCANRx_PpMode_VehicleSpeedCheck_Mode = RTE_MODE_SWC_SafeVCANRx_VehicleSpeedCheck_VehicleSpeedZero;

  Rte_ModeMachine_Safety_Guard_SafetyGuard_SafeState_Mode_Mode = RTE_MODE_Safety_Guard_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpAPSMPAOut_TbAP_APSMPAOut_t(P2CONST(TbAP_APSMPAOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpAPSMPAOut_TbAP_APSMPAOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCAMSelInfo_CAM_select_info_t(P2CONST(CAM_select_info_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpCAMSelInfo_CAM_select_info_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2CONST(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2CONST(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCamCsData_CAM_CS_Curr_Monitor_t(P2CONST(CAM_CS_Curr_Monitor_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpCamCsData_CAM_CS_Curr_Monitor_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCamEepromData_Svs_CamEepromDataArray_t(P2CONST(Svs_CamEepromDataArray_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpCamEepromData_Svs_CamEepromDataArray_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCamSerENStat_Cam_and_Ser_EN_Status_t(P2CONST(Cam_and_Ser_EN_Status_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpCamSerENStat_Cam_and_Ser_EN_Status_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t(P2CONST(CpuLoadMcu2_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpCpuLoadMcu2_0_CpuLoadMcu2_0_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t(P2CONST(CpuLoadMcu2_1_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpCpuLoadMcu2_1_CpuLoadMcu2_1_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDLDOutput_JobDLDOutput_t(P2CONST(JobDLDOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpDLDOutput_JobDLDOutput_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays(P2CONST(Debug_HMI_Curr_Requested_Overlays, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays(P2CONST(Debug_HMI_Curr_Displayed_Overlays, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig(P2CONST(Debug_HMI_Curr_Displayed_ProxiConfig, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig(P2CONST(Debug_HMI_Curr_Requested_ProxiConfig, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebHmiInput_Debug_HMI_Input_Data_t(P2CONST(Debug_HMI_Input_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpDebHmiInput_Debug_HMI_Input_Data_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebHmiInternal_Debug_HMI_Internal_Data_t(P2CONST(Debug_HMI_Internal_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpDebHmiInternal_Debug_HMI_Internal_Data_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t(P2CONST(Debug_HMI_Trailer_Views_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDetInpTrsc_Detection_Inputs_from_TRSC_t(P2CONST(Detection_Inputs_from_TRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpDetInpTrsc_Detection_Inputs_from_TRSC_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(P2CONST(TbAP_DriveAssistStatOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpErrFltMcu2_0_Error_Fault_MCU2_0_t(P2CONST(Error_Fault_MCU2_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpErrFltMcu2_0_Error_Fault_MCU2_0_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpErrFltMcu2_1_Error_Fault_MCU2_1_t(P2CONST(Error_Fault_MCU2_1_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpErrFltMcu2_1_Error_Fault_MCU2_1_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpErrFltMpu1_0_Error_Fault_MPU1_0_t(P2CONST(Error_Fault_MPU1_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpErrFltMpu1_0_Error_Fault_MPU1_0_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpFPAWarnOut_TbAP_FPAWarnOut_t(P2CONST(TbAP_FPAWarnOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpFPAWarnOut_TbAP_FPAWarnOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(P2CONST(TbTHASmVc_FeatureOutputs_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpIDebugFODObject_IDebug_FODObject_t(P2CONST(IDebug_FODObject_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_CDD_IPCHandler_PpIDebugFODObject_IDebug_FODObject_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t(P2CONST(IFOD_Outputs_Arbitration_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t(P2CONST(IJobUSSObjectMapOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpJobFPAData_IJobFPAOutput_t(P2CONST(IJobFPAOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpJobFPAData_IJobFPAOutput_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpJobPLDData_IJobPLDOutput_t(P2CONST(IJobPLDOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpJobPLDData_IJobPLDOutput_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpJobTHADetOutput_JobTHADetOutput_t(P2CONST(JobTHADetOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpJobTHADetOutput_JobTHADetOutput_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpKeepAliveResponse_KeepAliveResponse_t(P2CONST(KeepAliveResponse_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpKeepAliveResponse_KeepAliveResponse_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpLMDLaneOp_LMD_Lane_Outputs_s(P2CONST(LMD_Lane_Outputs_s, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpLMDLaneOp_LMD_Lane_Outputs_s = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2CONST(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpNFCDOutput_NFCD_Output(P2CONST(NFCD_Output, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpNFCDOutput_NFCD_Output = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t(P2CONST(TbSVS_e_SVSOutputToNVMCamCalibSM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpNVMCamCalibSM_TbSVS_e_SVSOutputToNVMCamCalibSM_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpNVMSignMgr_NVMSignalManager_t(P2CONST(NVMSignalManager_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpNVMSignMgr_NVMSignalManager_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpPAStateOut_TbAP_PAStateOut_t(P2CONST(TbAP_PAStateOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpPAStateOut_TbAP_PAStateOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpPointDistOpBuff_US_S_PointDistOutputBuff_t(P2CONST(US_S_PointDistOutputBuff_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpPointDistOpBuff_US_S_PointDistOutputBuff_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpRPAWarnOut_TbAP_RPAWarnOut_t(P2CONST(TbAP_RPAWarnOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpRPAWarnOut_TbAP_RPAWarnOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t(P2CONST(RunTimeStats_MCU2_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpRunTimeStats_MCU2_0_RunTimeStats_MCU2_0_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t(P2CONST(RunTimeStats_MCU2_1_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpRunTimeStats_MCU2_1_RunTimeStats_MCU2_1_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t(P2CONST(RunTimeStats_MPU1_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpRunTimeStats_MPU1_0_RunTimeStats_MPU1_0_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSMDAInternal_TbAP_SMDAInternalOut_t(P2CONST(TbAP_SMDAInternalOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSMDAInternal_TbAP_SMDAInternalOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSR_State_MCU2_State_2_0(P2CONST(SSM_2_0_CoreStatus, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_0 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSR_State_MCU2_State_2_1(P2CONST(SSM_2_1_CoreStatus, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_1 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSR_State_QNX_State_QNX(P2CONST(SSM_QNX_CoreStatus, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSR_State_QNX_State_QNX = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(P2CONST(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t(P2CONST(TbSVS_S_SVSCamEOLCalibDataToNVM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t(P2CONST(TbSVS_S_SVSCamOCCalibDataToNVM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t(P2CONST(TbSVS_S_SVSCamSCCalibDataToNVM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSNVMData_SVS_NVMData_t(P2CONST(SVS_NVMData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSVSNVMData_SVS_NVMData_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t(P2CONST(TbSVS_e_SVSOutputToDiagMgrCamCalib_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSVSOutputToDiagMgr_TbSVS_e_SVSOutputToDiagMgrCamCalib_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVSToDiag_SVSToDiag_t(P2CONST(SVSToDiag_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSVSToDiag_SVSToDiag_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSVStoTRSC_SVStoTRSC_t(P2CONST(SVStoTRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSVStoTRSC_SVStoTRSC_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_1_0_B(P2CONST(ErrorMgr_ErrorCommPack_1_0_B, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B(P2CONST(ErrorMgr_ErrorCommPack_2_0_B, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B(P2CONST(ErrorMgr_ErrorCommPack_2_1_B, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B(P2CONST(ErrorMgr_ErrorCommPack_QNX_B, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_1_0_QM(P2CONST(ErrorMgr_ErrorCommPack_1_0_QM, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  (void)IocWrite_Rte_ErrorMgrAgg_1_0_QM_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_QM_0(data); /* PRQA S 0310 */ /* MD_Rte_0310 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM(P2CONST(ErrorMgr_ErrorCommPack_2_0_QM, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_0_QM = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM(P2CONST(ErrorMgr_ErrorCommPack_2_1_QM, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_2_1_QM = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM(P2CONST(ErrorMgr_ErrorCommPack_QNX_QM, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSatError_QM_Data_ErrorMgr_ErrorCommPack_QNX_QM = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpScreenRequest_ScreenRequest_t(P2CONST(ScreenRequest_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpScreenRequest_ScreenRequest_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSnrDirEcho_US_S_SnrDirEcho_t(P2CONST(US_S_SnrDirEcho_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSnrDirEcho_US_S_SnrDirEcho_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t(P2CONST(StackUsage_MCU2_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpStackUsage_MCU2_0_StackUsage_MCU2_0_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t(P2CONST(StackUsage_MCU2_1_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpStackUsage_MCU2_1_StackUsage_MCU2_1_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSvsToTHA_SvsToTHA_t(P2CONST(SvsToTHA_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSvsToTHA_SvsToTHA_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpSvsToVCAN_SvsToVCAN_t(P2CONST(SvsToVCAN_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpSvsToVCAN_SvsToVCAN_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTRSC_ME_VehOut_TRSC_t(P2CONST(ME_VehOut_TRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTRSC_ME_VehOut_TRSC_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t(P2CONST(TRSCSMVCtoDebugCAN_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTbAPDebugOut_TbAP_DebugOut(P2CONST(TbAP_DebugOut, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTbAPDebugOut_TbAP_DebugOut = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t(P2CONST(TbAP_SMPAInternalOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t(P2CONST(TbFA_ArbiterOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTbFAResetKM_TbFA_ResetKM_t(P2CONST(TbFA_ResetKM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTbFAResetKM_TbFA_ResetKM_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t(P2CONST(TbTHASmVc_DiagMgr_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTbTHASmVcDiag_TbTHASmVc_DiagMgr_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTrailerDetectOP_TrailerDetection_Output_DID_t(P2CONST(TrailerDetection_Output_DID_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTrailerDetectOP_TrailerDetection_Output_DID_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t(P2CONST(TRSCSMVCtoSVS_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTrscToDiag_TRSCtoDiagMgr_t(P2CONST(TRSCtoDiagMgr_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTrscToDiag_TRSCtoDiagMgr_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(P2CONST(TRSC_Inputs_from_TrailerDetection_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUSSBlockageBit_US_S_BlockageBit_t(P2CONST(US_S_BlockageBit_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUSSBlockageBit_US_S_BlockageBit_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUSSConstantData_US_S_USSConstantData_t(P2CONST(US_S_USSConstantData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUSSConstantData_US_S_USSConstantData_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUSSErrorDiagData_US_S_USSErrorDiagData_t(P2CONST(US_S_USSErrorDiagData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUSSErrorDiagData_US_S_USSErrorDiagData_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t(P2CONST(US_S_USSPeriodDiagData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUSSPeriodDiagData_US_S_USSPeriodDiagData_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type(P2CONST(US_S_CsmStateChangeReason_Type, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUsCsmStatCngRsn_US_S_CsmStateChangeReason_Type = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssDataCollection_US_S_USSDataCollectionData_t(P2CONST(US_S_USSDataCollectionData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUssDataCollection_US_S_USSDataCollectionData_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssDebugMsg_US_S_DebugMsg_t(P2CONST(US_S_DebugMsg_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUssDebugMsg_US_S_DebugMsg_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssMrrgData_US_S_MarriageSensorIDs_t(P2CONST(US_S_MarriageSensorIDs_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUssMrrgData_US_S_MarriageSensorIDs_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssPointMapGrp_US_S_PointMapGroup_t(P2CONST(US_S_PointMapGroup_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUssPointMapGrp_US_S_PointMapGroup_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssTunData_UssTunningData_mcu2_1_t(P2CONST(UssTunningData_mcu2_1_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUssTunData_UssTunningData_mcu2_1_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpUssZoneInfo_US_S_ZoneInfo_t(P2CONST(US_S_ZoneInfo_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpUssZoneInfo_US_S_ZoneInfo_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpVCActuatorOut_TbAP_VCActuatorOut_t(P2CONST(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpVCActuatorOut_TbAP_VCActuatorOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpVCState_TbAP_VCStateOut_t(P2CONST(TbAP_VCStateOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpVCState_TbAP_VCStateOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(P2CONST(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(P2CONST(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_IPCHandler_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(P2CONST(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_CDD_IPCHandler_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_PMIC_PpPMICFaultstatus_Sts(P2CONST(uint8, AUTOMATIC, RTE_CDD_PMIC_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(Rte_CDD_PMIC_PpPMICFaultstatus_Sts, data, sizeof(PmicStatus)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_PMIC_PpWDGFaultStatus_Sts(P2CONST(uint8, AUTOMATIC, RTE_CDD_PMIC_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(Rte_CDD_PMIC_PpWDGFaultStatus_Sts, data, sizeof(WdgFltSts)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_Safety_PpMPUFaultStatus_Sts(P2CONST(uint8, AUTOMATIC, RTE_CDD_SAFETY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(Rte_CDD_Safety_PpMPUFaultStatus_Sts, data, sizeof(MpuFltSts)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDD_Safety_PpSDLFaultstatus_Sts(P2CONST(uint8, AUTOMATIC, RTE_CDD_SAFETY_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(Rte_CDD_Safety_PpSDLFaultstatus_Sts, data, sizeof(Status)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CalDataProvider_P_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0(P2CONST(CalDataProvider_MCU_1_0_Def, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_CalDataProvider_P_CalDataProvider_MCU1_0_Nvm_Data_CalData_mcu1_0 = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CalDataProvider_PpAPVarTunParam_TbAP_VrntTunParam_t(P2CONST(TbAP_VrntTunParam_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_CalDataProvider_PpAPVarTunParam_TbAP_VrntTunParam_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CalDataProvider_PpPreviousCamData_Data(P2CONST(CDP_TbSVS_S_SVSCamCurrentCalibData_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_CalDataProvider_PpPreviousCamData_Data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcAddData_B(P2CONST(DtcAddData_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcAddData_B = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcStatus_B(P2CONST(DtcStatus_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_ErrorMgrAgg_1_0_B_P_DtcData_Data_DtcStatus_B = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ErrorMgrAgg_1_0_B_P_Errors_B_Errors_B(P2CONST(uint32, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(Rte_ErrorMgrAgg_1_0_B_P_Errors_B_Errors_B, data, sizeof(ErrorListArr_B)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ErrorMgrAgg_1_0_B_P_SafeState_SafeStateOp(P2CONST(SafeStateOpDef, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_ErrorMgrAgg_1_0_B_P_SafeState_SafeStateOp = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ErrorMgrSat_1_0_B_P_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B(P2CONST(ErrorMgr_ErrorCommPack_1_0_B, AUTOMATIC, RTE_ERRORMGRSAT_1_0_B_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpProxiConfigData_ProxiData(P2CONST(ME_Hydra2defs_S_CodingTableExt_t, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_ProxiConfigMgr_PpProxiConfigData_ProxiData = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpProxiErrorData_Error(P2CONST(ME_Hydra2defs_S_PROXI_error_Data_t, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SWC_ProxiConfigMgr_PpProxiErrorData_Error = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM(Digit_01_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_01_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_35ebeb6b_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_01_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM(Digit_02_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_02_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_510b9095_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_02_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM(Digit_03_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_03_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_c47b4400_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_03_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM(Digit_04_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_04_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_98cb6769_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_04_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM(Digit_05_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_05_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_0dbbb3fc_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_05_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM(Digit_06_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_06_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_695bc802_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_06_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM(Digit_07_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_07_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_fc2b1c97_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_07_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM(Digit_08_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_08_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_d03b8ed0_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_08_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM(Digit_09_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_09_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_454b5a45_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_09_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM(Digit_10_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_10_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_206b28e1_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_10_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM(Digit_11_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Digit_11_PAM_oCFG_DATA_CODE_RSP_PAM_oFDCAN2_b51bfc74_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_Digit_11_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM(EOL_FD02_PAM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_EOL_FD02_PAM_oPDC_INFO_FD_PAM_oFDCAN2_ccb11d67_Tx_1 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_ProxiConfigMgr_PpToComFD02Tx_EOL_FD02_PAM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_DATA(P2CONST(uint8, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(Rte_SWC_SafeVCANRx_PpToSwcSafeFD02Rx_VIN_DATA, data, sizeof(VIN_DATA)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0(FD14_1_AliveCntr_MCU2_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_AliveCntr_MCU2_0_oME_SystemDebugData_1_oFDCAN14_e65282c6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1(FD14_1_AliveCntr_MCU2_1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_AliveCntr_MCU2_1_oME_SystemDebugData_1_oFDCAN14_1788876c_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0(FD14_1_AliveCntr_MPU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_AliveCntr_MPU1_0_oME_SystemDebugData_1_oFDCAN14_0e75683e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0(FD14_1_ErrFaultInfo_MCU2_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_ErrFaultInfo_MCU2_0_oME_SystemDebugData_1_oFDCAN14_09f994d2_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0(FD14_1_Err_FaultInfo_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Err_FaultInfo_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f3e84bf0_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1(FD14_1_Err_FaultInfo_MCU2_1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Err_FaultInfo_MCU2_1_oME_SystemDebugData_1_oFDCAN14_6fb4bd00_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0(FD14_1_Err_FaultInfo_MPU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Err_FaultInfo_MPU1_0_oME_SystemDebugData_1_oFDCAN14_76495252_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0(FD14_1_Err_FaultNum_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Err_FaultNum_MCU1_0_oME_SystemDebugData_1_oFDCAN14_44f26807_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0(FD14_1_Err_FaultNum_MCU2_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Err_FaultNum_MCU2_0_oME_SystemDebugData_1_oFDCAN14_29749b5d_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1(FD14_1_Err_FaultNum_MCU2_1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Err_FaultNum_MCU2_1_oME_SystemDebugData_1_oFDCAN14_d8ae9ef7_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0(FD14_1_Err_FaultNum_MPU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Err_FaultNum_MPU1_0_oME_SystemDebugData_1_oFDCAN14_c15371a5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0(FD14_1_Hook_DtErr_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Hook_DtErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d4fc990e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0(FD14_1_Hook_Error_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Hook_Error_MCU1_0_oME_SystemDebugData_1_oFDCAN14_082f9b06_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0(FD14_1_Hook_PresentPtr_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Hook_PresentPtr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_46e0c48b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0(FD14_1_Hook_Reserved_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Hook_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_4252166b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0(FD14_1_Hook_Service_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Hook_Service_MCU1_0_oME_SystemDebugData_1_oFDCAN14_443850ea_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0(FD14_1_Hook_Type_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Hook_Type_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6517d66f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0(FD14_1_Hook_actTsk_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Hook_actTsk_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e5cab5c_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0(FD14_1_Hook_fatalErr_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Hook_fatalErr_MCU1_0_oME_SystemDebugData_1_oFDCAN14_db1493b6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR(FD14_1_OsRegMCU_ADFSR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_ADFSR_oME_MCUOsDebugData1_oFDCAN14_56600f18_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR(FD14_1_OsRegMCU_AIFSR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_AIFSR_oME_MCUOsDebugData1_oFDCAN14_d7bd5dfe_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR(FD14_1_OsRegMCU_DFAR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_DFAR_oME_MCUOsDebugData1_oFDCAN14_73a0eaa5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR(FD14_1_OsRegMCU_DFSR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_DFSR_oME_MCUOsDebugData1_oFDCAN14_8011b617_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR(FD14_1_OsRegMCU_IFAR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_IFAR_oME_MCUOsDebugData1_oFDCAN14_f27db843_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR(FD14_1_OsRegMCU_IFSR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_IFSR_oME_MCUOsDebugData1_oFDCAN14_01cce4f1_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link(FD14_1_OsRegMCU_Link data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Link_oME_MCUOsDebugData1_oFDCAN14_b350e9be_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR(FD14_1_OsRegMCU_SPSR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_SPSR_oME_MCUOsDebugData1_oFDCAN14_8d113eaa_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0(FD14_1_OsRegMCU_Stack0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Stack0_oME_MCUOsDebugData2_oFDCAN14_def0054e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1(FD14_1_OsRegMCU_Stack1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Stack1_oME_MCUOsDebugData2_oFDCAN14_e290e646_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2(FD14_1_OsRegMCU_Stack2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Stack2_oME_MCUOsDebugData2_oFDCAN14_a631c35e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3(FD14_1_OsRegMCU_Stack3 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Stack3_oME_MCUOsDebugData2_oFDCAN14_9a512056_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4(FD14_1_OsRegMCU_Stack4 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Stack4_oME_MCUOsDebugData2_oFDCAN14_2f73896e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5(FD14_1_OsRegMCU_Stack5 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Stack5_oME_MCUOsDebugData2_oFDCAN14_13136a66_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6(FD14_1_OsRegMCU_Stack6 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Stack6_oME_MCUOsDebugData2_oFDCAN14_57b24f7e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7(FD14_1_OsRegMCU_Stack7 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Stack7_oME_MCUOsDebugData2_oFDCAN14_6bd2ac76_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8(FD14_1_OsRegMCU_Stack8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Stack8_oME_MCUOsDebugData2_oFDCAN14_e6861b4f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9(FD14_1_OsRegMCU_Stack9 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_OsRegMCU_Stack9_oME_MCUOsDebugData2_oFDCAN14_dae6f847_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0(FD14_1_Reserved_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Reserved_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5ce4f1ef_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0(FD14_1_Reserved_MCU2_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Reserved_MCU2_0_oME_SystemDebugData_1_oFDCAN14_316202b5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1(FD14_1_Reserved_MCU2_1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Reserved_MCU2_1_oME_SystemDebugData_1_oFDCAN14_c0b8071f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0(FD14_1_Reserved_MPU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_Reserved_MPU1_0_oME_SystemDebugData_1_oFDCAN14_d945e84d_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0(FD14_1_SDL_Fault_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SDL_Fault_MCU1_0_oME_SystemDebugData_1_oFDCAN14_80e1e586_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0(FD14_1_SSM_FltData10_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData10_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6272ae84_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0(FD14_1_SSM_FltData11_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData11_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2cfba52d_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0(FD14_1_SSM_FltData12_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData12_MCU1_0_oME_SystemDebugData_1_oFDCAN14_ff60b9d6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0(FD14_1_SSM_FltData13_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData13_MCU1_0_oME_SystemDebugData_1_oFDCAN14_b1e9b27f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0(FD14_1_SSM_FltData14_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData14_MCU1_0_oME_SystemDebugData_1_oFDCAN14_83278661_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0(FD14_1_SSM_FltData15_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData15_MCU1_0_oME_SystemDebugData_1_oFDCAN14_cdae8dc8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0(FD14_1_SSM_FltData16_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData16_MCU1_0_oME_SystemDebugData_1_oFDCAN14_1e359133_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0(FD14_1_SSM_FltData17_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData17_MCU1_0_oME_SystemDebugData_1_oFDCAN14_50bc9a9a_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0(FD14_1_SSM_FltData18_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData18_MCU1_0_oME_SystemDebugData_1_oFDCAN14_7ba9f90f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0(FD14_1_SSM_FltData1_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData1_MCU1_0_oME_SystemDebugData_1_oFDCAN14_8e3538b4_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0(FD14_1_SSM_FltData2_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData2_MCU1_0_oME_SystemDebugData_1_oFDCAN14_5dae244f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0(FD14_1_SSM_FltData3_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData3_MCU1_0_oME_SystemDebugData_1_oFDCAN14_13272fe6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0(FD14_1_SSM_FltData4_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData4_MCU1_0_oME_SystemDebugData_1_oFDCAN14_21e91bf8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0(FD14_1_SSM_FltData5_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData5_MCU1_0_oME_SystemDebugData_1_oFDCAN14_6f601051_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0(FD14_1_SSM_FltData6_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData6_MCU1_0_oME_SystemDebugData_1_oFDCAN14_bcfb0caa_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0(FD14_1_SSM_FltData7_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData7_MCU1_0_oME_SystemDebugData_1_oFDCAN14_f2720703_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0(FD14_1_SSM_FltData8_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData8_MCU1_0_oME_SystemDebugData_1_oFDCAN14_d9676496_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0(FD14_1_SSM_FltData9_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_FltData9_MCU1_0_oME_SystemDebugData_1_oFDCAN14_97ee6f3f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq(FD14_1_SSM_SystemStateReq data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_SSM_SystemStateReq_oME_SystemDebugData_1_oFDCAN14_1a98cea3_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON(FD14_1_TimeSincePowerON data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_TimeSincePowerON_oME_SystemDebugData_1_oFDCAN14_144841c6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0(FD14_1_WDG_Error_ID_MCU1_0 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_1_WDG_Error_ID_MCU1_0_oME_SystemDebugData_1_oFDCAN14_2488c0c2_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts(AUXCamsRQSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_AUXCamsRQSts_oCVPAM_FD_Info_oFDCAN2_cb5ede6d_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF(Alert_CHF data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Alert_CHF_oCVPAM_FD_Info_oFDCAN2_10e5899e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR(Alert_CHR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Alert_CHR_oCVPAM_FD_Info_oFDCAN2_068868fc_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF(Alert_LHF data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Alert_LHF_oCVPAM_FD_Info_oFDCAN2_9d0fdf04_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR(Alert_LHR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Alert_LHR_oCVPAM_FD_Info_oFDCAN2_8b623e66_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF(Alert_RHF data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Alert_RHF_oCVPAM_FD_Info_oFDCAN2_5daa7471_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR(Alert_RHR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Alert_RHR_oCVPAM_FD_Info_oFDCAN2_4bc79513_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status(Camera_Status data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Camera_Status_oADAS_FD_LANES_1_oFDCAN2_64f6e4de_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF(ChimeActivation_LHF data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_ChimeActivation_LHF_oCVPAM_FD_Info_oFDCAN2_18ea8591_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR(ChimeActivation_LHR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_ChimeActivation_LHR_oCVPAM_FD_Info_oFDCAN2_0e8764f3_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF(ChimeActivation_RHF data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_ChimeActivation_RHF_oCVPAM_FD_Info_oFDCAN2_d84f2ee4_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR(ChimeActivation_RHR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_ChimeActivation_RHR_oCVPAM_FD_Info_oFDCAN2_ce22cf86_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1(Cntr_ADAS_FD_LANES_1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_af11a5df_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2(Cntr_ADAS_FD_LANES_2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_64cb74e2_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2(DisplayView2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_DisplayView2_oCVPAM_FD_Info_oFDCAN2_73efd9c8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence(FOD_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN2_998d9b03_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts(FT_PAM_LedControlSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FT_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_767c2572_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1(Frame_Index_Lanes_1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN2_1ad54467_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2(Frame_Index_Lanes_2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN2_d10f955a_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts(FrontSensorSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FrontSensorSts_oCVPAM_FD_Info_oFDCAN2_e08a5c16_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF(Graphic_CHF data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Graphic_CHF_oCVPAM_FD_Info_oFDCAN2_4b6ea313_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR(Graphic_CHR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Graphic_CHR_oCVPAM_FD_Info_oFDCAN2_5d034271_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF(Graphic_LHF data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Graphic_LHF_oCVPAM_FD_Info_oFDCAN2_c684f589_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR(Graphic_LHR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Graphic_LHR_oCVPAM_FD_Info_oFDCAN2_d0e914eb_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF(Graphic_RHF data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Graphic_RHF_oCVPAM_FD_Info_oFDCAN2_06215efc_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR(Graphic_RHR data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Graphic_RHR_oCVPAM_FD_Info_oFDCAN2_104cbf9e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode(HMICode data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_HMICode_oCVPAM_FD_Info_oFDCAN2_5dec6edf_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection(Health_Front_Object_Detection data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN2_e8d5db74_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection(Health_Lane_Detection data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN2_1cdf1820_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts(ImageDefeatRQSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_ImageDefeatRQSts_oCVPAM_FD_Info_oFDCAN2_7d4e09fb_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence(Line_1_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN2_2534fe9b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature(Line_1_Curvature data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN2_09082d9e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate(Line_1_Curvature_Rate data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_93fb8a81_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range(Line_1_End_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN2_34dd811a_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading(Line_1_Heading data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN2_3e17383d_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset(Line_1_Offset data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN2_ad232516_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range(Line_1_Start_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN2_293a5620_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type(Line_1_Type data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_1_Type_oADAS_FD_LANES_1_oFDCAN2_3e24410a_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence(Line_2_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN2_7f55c1fb_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature(Line_2_Curvature data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN2_6de85660_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate(Line_2_Curvature_Rate data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_70b23d23_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range(Line_2_End_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN2_503dfae4_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading(Line_2_Heading data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN2_5391cb67_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset(Line_2_Offset data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN2_f6349403_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range(Line_2_Start_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN2_64d25647_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type(Line_2_Type data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_2_Type_oADAS_FD_LANES_1_oFDCAN2_2d0c7879_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence(Line_3_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN2_ffa5d6e4_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature(Line_3_Curvature data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN2_f89882f5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate(Line_3_Curvature_Rate data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_98a5ad82_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range(Line_3_End_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN2_c54d2e71_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading(Line_3_Heading data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN2_77139a51_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset(Line_3_Offset data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN2_c0c604f0_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range(Line_3_Start_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN2_e95aaba5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type(Line_3_Type data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_3_Type_oADAS_FD_LANES_1_oFDCAN2_23eb90a8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence(Line_4_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN2_cb97bf3b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature(Line_4_Curvature data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN2_a428a19c_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate(Line_4_Curvature_Rate data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN2_6d505426_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range(Line_4_End_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN2_99fd0d18_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading(Line_4_Heading data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN2_889c2dd3_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset(Line_4_Offset data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN2_401bf629_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range(Line_4_Start_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN2_ff025689_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type(Line_4_Type data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Line_4_Type_oADAS_FD_LANES_1_oFDCAN2_0b5c0a9f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1(P2CONST(uint8, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(Rte_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN2_9c565bdf_Tx, data, sizeof(MAC_ADAS_FD_LANES_1)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2(P2CONST(uint8, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(Rte_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN2_578c8ae2_Tx, data, sizeof(MAC_ADAS_FD_LANES_2)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts(MoreCamsRQSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MoreCamsRQSts_oCVPAM_FD_Info_oFDCAN2_ba84adf5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault(PAMSystemFault data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_PAMSystemFault_oCVPAM_FD_Info_oFDCAN2_eab32332_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts(PAM_CHIME_REP_RATESts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_PAM_CHIME_REP_RATESts_oCVPAM_FD_Info_oFDCAN2_ec85c7c5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE(PAM_CHIME_TYPE data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_PAM_CHIME_TYPE_oCVPAM_FD_Info_oFDCAN2_0558f070_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts(PAM_LedControlSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_PAM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_63c5d79e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status(PAM_Off_Status data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_PAM_Off_Status_oCVPAM_FD_Info_oFDCAN2_796d8062_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT(PAM_Off_Status_2BT data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_PAM_Off_Status_2BT_oCVPAM_FD_Info_oFDCAN2_514378c1_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst(PAM_PopUpRqst data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_PAM_PopUpRqst_oCVPAM_FD_Info_oFDCAN2_657f86c2_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume(PAM_Volume data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_PAM_Volume_oCVPAM_FD_Info_oFDCAN2_4f8f6792_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst(PPPA_TurnIndicatorRqst data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_PPPA_TurnIndicatorRqst_oCVPAM_FD_Control_oFDCAN2_507419a7_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive(ParkingManeuverActive data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN2_ad1c7c90_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts(RR_PAM_Brk_RqSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN2_92ae92ff_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist(RR_PAM_Dist data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN2_48ca8ca5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts(RR_PAM_StopControlSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RR_PAM_StopControlSts_oCVPAM_FD_Control_oFDCAN2_2f143404_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts(RearSensorSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RearSensorSts_oCVPAM_FD_Info_oFDCAN2_a2ccce85_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety(Reserved_for_functional_safety data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN2_82a794a5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts(SPMControlSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SPMControlSts_oCVPAM_FD_Info_oFDCAN2_a3ff073d_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts(SPMFailSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SPMFailSts_oCVPAM_FD_Info_oFDCAN2_85d98ec8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault(SPMSystemFault data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SPMSystemFault_oCVPAM_FD_Info_oFDCAN2_c4e3aa9b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts(SPM_LedControlSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SPM_LedControlSts_oCVPAM_FD_Info_oFDCAN2_3446c3a9_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst(SPM_Screen_Rqst data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_SPM_Screen_Rqst_oCVPAM_FD_Info_oFDCAN2_4e673fb0_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence(Segment_1_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN2_d5c06647_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID(Segment_1_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN2_124eba08_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1(Segment_1_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN2_0e62b6bf_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2(Segment_1_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN2_fc355b47_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1(Segment_1_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN2_60eeadfe_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2(Segment_1_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN2_92b94006_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence(Segment_2_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN2_8fa15927_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID(Segment_2_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN2_b746d164_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1(Segment_2_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN2_ab6addd3_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2(Segment_2_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN2_593d302b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1(Segment_2_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN2_c5e6c692_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2(Segment_2_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN2_37b12b6a_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence(Segment_3_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN2_0f514e38_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID(Segment_3_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN2_d4410840_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1(Segment_3_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN2_c86d04f7_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2(Segment_3_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN2_3a3ae90f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1(Segment_3_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN2_a6e11fb6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2(Segment_3_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN2_54b6f24e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence(Segment_4_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN2_3b6327e7_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID(Segment_4_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN2_262701fd_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1(Segment_4_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN2_3a0b0d4a_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2(Segment_4_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN2_c85ce0b2_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1(Segment_4_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN2_5487160b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2(Segment_4_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN2_a6d0fbf3_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence(Segment_5_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN2_bb9330f8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID(Segment_5_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN2_4520d8d9_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1(Segment_5_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN2_590cd46e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2(Segment_5_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN2_ab5b3996_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1(Segment_5_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN2_3780cf2f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2(Segment_5_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN2_c5d722d7_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence(Segment_6_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN2_e1f20f98_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID(Segment_6_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN2_e028b3b5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1(Segment_6_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN2_fc04bf02_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2(Segment_6_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN2_0e5352fa_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1(Segment_6_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN2_9288a443_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2(Segment_6_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN2_60df49bb_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence(Segment_7_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN2_61021887_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID(Segment_7_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN2_832f6a91_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1(Segment_7_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN2_9f036626_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2(Segment_7_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN2_6d548bde_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1(Segment_7_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN2_f18f7d67_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2(Segment_7_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN2_03d8909f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence(Segment_8_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN2_8996dc26_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID(Segment_8_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN2_df95a68e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1(Segment_8_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN2_c3b9aa39_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2(Segment_8_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN2_31ee47c1_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1(Segment_8_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN2_ad35b178_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2(Segment_8_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN2_5f625c80_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat(TRSC_LED_Stat data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_TRSC_LED_Stat_oCVPAM_FD_Info_oFDCAN2_546afbba_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status(FD14_Camera_Status data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Camera_Status_oADAS_FD_LANES_1_oFDCAN14_02ee5263_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1(FD14_Cntr_ADAS_FD_LANES_1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Cntr_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_83e8745c_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2(FD14_Cntr_ADAS_FD_LANES_2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Cntr_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_db4be29c_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence(FD14_FOD_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_FOD_Confidence_oADAS_FD_LANES_1_oFDCAN14_07d950b0_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1(FD14_Frame_Index_Lanes_1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Frame_Index_Lanes_1_oADAS_FD_LANES_1_oFDCAN14_09d47624_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2(FD14_Frame_Index_Lanes_2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Frame_Index_Lanes_2_oADAS_FD_LANES_2_oFDCAN14_5177e0e4_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection(FD14_Health_Front_Object_Detection data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Health_Front_Object_Detection_oADAS_FD_LANES_1_oFDCAN14_67ae32c5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection(FD14_Health_Lane_Detection data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Health_Lane_Detection_oADAS_FD_LANES_1_oFDCAN14_0b1cd3fa_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence(FD14_Line_1_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_1_Confidence_oADAS_FD_LANES_1_oFDCAN14_3d68d9cb_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature(FD14_Line_1_Curvature data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_1_Curvature_oADAS_FD_LANES_1_oFDCAN14_cc3e3dc3_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate(FD14_Line_1_Curvature_Rate data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_1_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_aa426416_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range(FD14_Line_1_End_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_1_End_Range_oADAS_FD_LANES_1_oFDCAN14_26d6af56_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading(FD14_Line_1_Heading data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_1_Heading_oADAS_FD_LANES_1_oFDCAN14_c61fd7b8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset(FD14_Line_1_Offset data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_1_Offset_oADAS_FD_LANES_1_oFDCAN14_9798cd20_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range(FD14_Line_1_Start_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_1_Start_Range_oADAS_FD_LANES_1_oFDCAN14_0d5038a6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type(FD14_Line_1_Type data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_1_Type_oADAS_FD_LANES_1_oFDCAN14_dd59b9e0_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence(FD14_Line_2_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_2_Confidence_oADAS_FD_LANES_1_oFDCAN14_7080d9ac_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature(FD14_Line_2_Curvature data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_2_Curvature_oADAS_FD_LANES_1_oFDCAN14_965f02a3_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate(FD14_Line_2_Curvature_Rate data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_2_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_9279ef65_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range(FD14_Line_2_End_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_2_End_Range_oADAS_FD_LANES_1_oFDCAN14_7cb79036_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading(FD14_Line_2_Heading data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_2_Heading_oADAS_FD_LANES_1_oFDCAN14_4dcce9a1_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset(FD14_Line_2_Offset data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_2_Offset_oADAS_FD_LANES_1_oFDCAN14_fa1e3e7a_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range(FD14_Line_2_Start_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_2_Start_Range_oADAS_FD_LANES_1_oFDCAN14_decb245d_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type(FD14_Line_2_Type data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_2_Type_oADAS_FD_LANES_1_oFDCAN14_1446b15f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence(FD14_Line_3_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_3_Confidence_oADAS_FD_LANES_1_oFDCAN14_fd08244e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature(FD14_Line_3_Curvature data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_3_Curvature_oADAS_FD_LANES_1_oFDCAN14_16af15bc_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate(FD14_Line_3_Curvature_Rate data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_3_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_33406b8b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range(FD14_Line_3_End_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_3_End_Range_oADAS_FD_LANES_1_oFDCAN14_fc478729_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading(FD14_Line_3_Heading data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_3_Heading_oADAS_FD_LANES_1_oFDCAN14_8252fe69_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset(FD14_Line_3_Offset data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_3_Offset_oADAS_FD_LANES_1_oFDCAN14_de9c6f4c_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range(FD14_Line_3_Start_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_3_Start_Range_oADAS_FD_LANES_1_oFDCAN14_90422ff4_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type(FD14_Line_3_Type data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_3_Type_oADAS_FD_LANES_1_oFDCAN14_e59cb4f5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence(FD14_Line_4_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_4_Confidence_oADAS_FD_LANES_1_oFDCAN14_eb50d962_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature(FD14_Line_4_Curvature data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_4_Curvature_oADAS_FD_LANES_1_oFDCAN14_229d7c63_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate(FD14_Line_4_Curvature_Rate data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_4_Curvature_Rate_oADAS_FD_LANES_1_oFDCAN14_e20ef983_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range(FD14_Line_4_End_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_4_End_Range_oADAS_FD_LANES_1_oFDCAN14_c875eef6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading(FD14_Line_4_Heading data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_4_Heading_oADAS_FD_LANES_1_oFDCAN14_811b93d2_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset(FD14_Line_4_Offset data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_4_Offset_oADAS_FD_LANES_1_oFDCAN14_2113d8ce_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range(FD14_Line_4_Start_Range data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_4_Start_Range_oADAS_FD_LANES_1_oFDCAN14_a28c1bea_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type(FD14_Line_4_Type data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Line_4_Type_oADAS_FD_LANES_1_oFDCAN14_5d09a660_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1(P2CONST(uint8, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(Rte_FD14_MAC_ADAS_FD_LANES_1_oADAS_FD_LANES_1_oFDCAN14_cce8ce85_Tx, data, sizeof(FD14_MAC_ADAS_FD_LANES_1)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2(P2CONST(uint8, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(Rte_FD14_MAC_ADAS_FD_LANES_2_oADAS_FD_LANES_2_oFDCAN14_944b5845_Tx, data, sizeof(FD14_MAC_ADAS_FD_LANES_2)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase(FD14_ManoeuvrePhase data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_ManoeuvrePhase_oCVPAM_FD_Control_oFDCAN14_6f7ff602_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax(FD14_PPPA_AccelMax data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_AccelMax_oCVPAM_FD_Control_oFDCAN14_c98fde99_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin(FD14_PPPA_AccelMin data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_AccelMin_oCVPAM_FD_Control_oFDCAN14_79b0c4a5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax(FD14_PPPA_DecelMax data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_DecelMax_oCVPAM_FD_Control_oFDCAN14_55867c47_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin(FD14_PPPA_DecelMin data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_DecelMin_oCVPAM_FD_Control_oFDCAN14_e5b9667b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM(FD14_PPPA_Interface_BSM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_Interface_BSM_oCVPAM_FD_Control_oFDCAN14_5d761341_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax(FD14_PPPA_JerkAccelMax data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_JerkAccelMax_oCVPAM_FD_Control_oFDCAN14_05f086d0_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin(FD14_PPPA_JerkAccelMin data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_JerkAccelMin_oCVPAM_FD_Control_oFDCAN14_b5cf9cec_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax(FD14_PPPA_JerkDecelMax data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_JerkDecelMax_oCVPAM_FD_Control_oFDCAN14_99f9240e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin(FD14_PPPA_JerkDecelMin data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_JerkDecelMin_oCVPAM_FD_Control_oFDCAN14_29c63e32_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed(FD14_PPPA_MaxSpeed data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_MaxSpeed_oCVPAM_FD_Control_oFDCAN14_7ef0b86c_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst(FD14_PPPA_StandstillRqst data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_StandstillRqst_oCVPAM_FD_Control_oFDCAN14_cc940d9b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance(FD14_PPPA_TargetDistance data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_PPPA_TargetDistance_oCVPAM_FD_Control_oFDCAN14_3437c295_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq(FD14_ParkingGearShiftReq data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_ParkingGearShiftReq_oCVPAM_FD_Control_oFDCAN14_47412e73_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive(FD14_ParkingManeuverActive data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_ParkingManeuverActive_oCVPAM_FD_Info_oFDCAN14_2abad8a3_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts(FD14_RR_PAM_Brk_RqSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_RR_PAM_Brk_RqSts_oCVPAM_FD_Control_oFDCAN14_7700e6e6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist(FD14_RR_PAM_Dist data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_RR_PAM_Dist_oCVPAM_FD_Control_oFDCAN14_0f3b79a5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety(FD14_Reserved_for_functional_safety data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Reserved_for_functional_safety_oADAS_FD_LANES_1_oFDCAN14_e529cfa2_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts(FD14_SPM_Lat_Ctrl_RequestSts data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_SPM_Lat_Ctrl_RequestSts_oCVPAM_FD_Control_oFDCAN14_6d94d6ac_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence(FD14_Segment_1_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_1_Confidence_oADAS_FD_LANES_2_oFDCAN14_7d46bee9_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID(FD14_Segment_1_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_1_ID_oADAS_FD_LANES_2_oFDCAN14_a70622c6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1(FD14_Segment_1_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_1_X1_oADAS_FD_LANES_2_oFDCAN14_f21f28e5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2(FD14_Segment_1_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_1_X2_oADAS_FD_LANES_2_oFDCAN14_418b0526_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1(FD14_Segment_1_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_1_Y1_oADAS_FD_LANES_2_oFDCAN14_f3aad5f8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2(FD14_Segment_1_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_1_Y2_oADAS_FD_LANES_2_oFDCAN14_403ef83b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence(FD14_Segment_2_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_2_Confidence_oADAS_FD_LANES_2_oFDCAN14_30aebe8e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID(FD14_Segment_2_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_2_ID_oADAS_FD_LANES_2_oFDCAN14_e3a707de_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1(FD14_Segment_2_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_2_X1_oADAS_FD_LANES_2_oFDCAN14_b6be0dfd_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2(FD14_Segment_2_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_2_X2_oADAS_FD_LANES_2_oFDCAN14_052a203e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1(FD14_Segment_2_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_2_Y1_oADAS_FD_LANES_2_oFDCAN14_b70bf0e0_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2(FD14_Segment_2_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_2_Y2_oADAS_FD_LANES_2_oFDCAN14_049fdd23_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence(FD14_Segment_3_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_3_Confidence_oADAS_FD_LANES_2_oFDCAN14_bd26436c_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID(FD14_Segment_3_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_3_ID_oADAS_FD_LANES_2_oFDCAN14_dfc7e4d6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1(FD14_Segment_3_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_3_X1_oADAS_FD_LANES_2_oFDCAN14_8adeeef5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2(FD14_Segment_3_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_3_X2_oADAS_FD_LANES_2_oFDCAN14_394ac336_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1(FD14_Segment_3_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_3_Y1_oADAS_FD_LANES_2_oFDCAN14_8b6b13e8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2(FD14_Segment_3_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_3_Y2_oADAS_FD_LANES_2_oFDCAN14_38ff3e2b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence(FD14_Segment_4_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_4_Confidence_oADAS_FD_LANES_2_oFDCAN14_ab7ebe40_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID(FD14_Segment_4_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_4_ID_oADAS_FD_LANES_2_oFDCAN14_6ae54dee_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1(FD14_Segment_4_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_4_X1_oADAS_FD_LANES_2_oFDCAN14_3ffc47cd_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2(FD14_Segment_4_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_4_X2_oADAS_FD_LANES_2_oFDCAN14_8c686a0e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1(FD14_Segment_4_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_4_Y1_oADAS_FD_LANES_2_oFDCAN14_3e49bad0_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2(FD14_Segment_4_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_4_Y2_oADAS_FD_LANES_2_oFDCAN14_8ddd9713_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence(FD14_Segment_5_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_5_Confidence_oADAS_FD_LANES_2_oFDCAN14_26f643a2_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID(FD14_Segment_5_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_5_ID_oADAS_FD_LANES_2_oFDCAN14_5685aee6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1(FD14_Segment_5_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_5_X1_oADAS_FD_LANES_2_oFDCAN14_039ca4c5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2(FD14_Segment_5_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_5_X2_oADAS_FD_LANES_2_oFDCAN14_b0088906_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1(FD14_Segment_5_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_5_Y1_oADAS_FD_LANES_2_oFDCAN14_022959d8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2(FD14_Segment_5_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_5_Y2_oADAS_FD_LANES_2_oFDCAN14_b1bd741b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence(FD14_Segment_6_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_6_Confidence_oADAS_FD_LANES_2_oFDCAN14_6b1e43c5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID(FD14_Segment_6_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_6_ID_oADAS_FD_LANES_2_oFDCAN14_12248bfe_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1(FD14_Segment_6_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_6_X1_oADAS_FD_LANES_2_oFDCAN14_473d81dd_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2(FD14_Segment_6_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_6_X2_oADAS_FD_LANES_2_oFDCAN14_f4a9ac1e_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1(FD14_Segment_6_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_6_Y1_oADAS_FD_LANES_2_oFDCAN14_46887cc0_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2(FD14_Segment_6_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_6_Y2_oADAS_FD_LANES_2_oFDCAN14_f51c5103_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence(FD14_Segment_7_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_7_Confidence_oADAS_FD_LANES_2_oFDCAN14_e696be27_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID(FD14_Segment_7_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_7_ID_oADAS_FD_LANES_2_oFDCAN14_2e4468f6_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1(FD14_Segment_7_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_7_X1_oADAS_FD_LANES_2_oFDCAN14_7b5d62d5_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2(FD14_Segment_7_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_7_X2_oADAS_FD_LANES_2_oFDCAN14_c8c94f16_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1(FD14_Segment_7_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_7_Y1_oADAS_FD_LANES_2_oFDCAN14_7ae89fc8_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2(FD14_Segment_7_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_7_Y2_oADAS_FD_LANES_2_oFDCAN14_c97cb20b_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence(FD14_Segment_8_Confidence data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_8_Confidence_oADAS_FD_LANES_2_oFDCAN14_47afb99d_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID(FD14_Segment_8_ID data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_8_ID_oADAS_FD_LANES_2_oFDCAN14_a310dfcf_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1(FD14_Segment_8_X1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_8_X1_oADAS_FD_LANES_2_oFDCAN14_f609d5ec_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2(FD14_Segment_8_X2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_8_X2_oADAS_FD_LANES_2_oFDCAN14_459df82f_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1(FD14_Segment_8_Y1 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_8_Y1_oADAS_FD_LANES_2_oFDCAN14_f7bc28f1_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2(FD14_Segment_8_Y2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_Segment_8_Y2_oADAS_FD_LANES_2_oFDCAN14_44280532_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2 = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2 = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM(FD14_TorqueOverlaySteeringReq_SPM data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_FD14_TorqueOverlaySteeringReq_SPM_oCVPAM_FD_Control_oFDCAN14_593889ae_Tx = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdate_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM = RTE_COM_SENDSIGNALPROXY_SEND;
  Rte_OsApplication_Safety_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM = !Rte_OsApplication_QM_TxUpdateFlags.Rte_TxUpdateProxy_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM; /* PRQA S 4116, 4404, 4558 */ /* MD_Rte_4116, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Safety_Guard_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2CONST(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Safety_Guard_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Safety_Guard_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2CONST(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Safety_Guard_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Safety_Guard_PpSafeGuardPAStateOut_TbAP_PAStateOut_t(P2CONST(TbAP_PAStateOut_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Safety_Guard_PpSafeGuardPAStateOut_TbAP_PAStateOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Safety_Guard_PpSafeGuardSvsToVCAN_SvsToVCAN_t(P2CONST(SvsToVCAN_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Safety_Guard_PpSafeGuardSvsToVCAN_SvsToVCAN_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Safety_Guard_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t(P2CONST(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_Safety_Guard_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpAPSMPAOut_TbAP_APSMPAOut_t(P2VAR(TbAP_APSMPAOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpAPSMPAOut_TbAP_APSMPAOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2VAR(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2VAR(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays(P2VAR(Debug_HMI_Curr_Requested_Overlays, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpDebCurReqOverlay_Debug_HMI_Curr_Requested_Overlays; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays(P2VAR(Debug_HMI_Curr_Displayed_Overlays, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpDebCurrDispOverlay_Debug_HMI_Curr_Displayed_Overlays; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig(P2VAR(Debug_HMI_Curr_Displayed_ProxiConfig, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpDebCurrDispProxiCfg_Debug_HMI_Curr_Displayed_ProxiConfig; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig(P2VAR(Debug_HMI_Curr_Requested_ProxiConfig, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpDebCurrReqProxiCfg_Debug_HMI_Curr_Requested_ProxiConfig; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebHmiInput_Debug_HMI_Input_Data_t(P2VAR(Debug_HMI_Input_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpDebHmiInput_Debug_HMI_Input_Data_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebHmiInternal_Debug_HMI_Internal_Data_t(P2VAR(Debug_HMI_Internal_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpDebHmiInternal_Debug_HMI_Internal_Data_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t(P2VAR(Debug_HMI_Trailer_Views_Data_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpDebHmiTrailViews_Debug_HMI_Trailer_Views_Data_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDetInpTrsc_Detection_Inputs_from_TRSC_t(P2VAR(Detection_Inputs_from_TRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpDetInpTrsc_Detection_Inputs_from_TRSC_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(P2VAR(TbAP_DriveAssistStatOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpFPAWarnOut_TbAP_FPAWarnOut_t(P2VAR(TbAP_FPAWarnOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpFPAWarnOut_TbAP_FPAWarnOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(P2VAR(TbTHASmVc_FeatureOutputs_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpIDebugFODObject_IDebug_FODObject_t(P2VAR(IDebug_FODObject_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_CDD_IPCHandler_PpIDebugFODObject_IDebug_FODObject_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpIFODOpArbitration_IFOD_Outputs_Arbitration_t(P2VAR(IFOD_Outputs_Arbitration_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpIFODOpArbitration_IFOD_Outputs_Arbitration_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpIJobUSSObjOp_IJobUSSObjectMapOutput_t(P2VAR(IJobUSSObjectMapOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpIJobUSSObjOp_IJobUSSObjectMapOutput_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpJobFPAData_IJobFPAOutput_t(P2VAR(IJobFPAOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpJobFPAData_IJobFPAOutput_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpJobPLDData_IJobPLDOutput_t(P2VAR(IJobPLDOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpJobPLDData_IJobPLDOutput_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpJobTHADetOutput_JobTHADetOutput_t(P2VAR(JobTHADetOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpJobTHADetOutput_JobTHADetOutput_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpLMDLaneOp_LMD_Lane_Outputs_s(P2VAR(LMD_Lane_Outputs_s, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpLMDLaneOp_LMD_Lane_Outputs_s; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpNFCDOutput_NFCD_Output(P2VAR(NFCD_Output, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpNFCDOutput_NFCD_Output; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpNVMSignMgr_NVMSignalManager_t(P2VAR(NVMSignalManager_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpNVMSignMgr_NVMSignalManager_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpPAStateOut_TbAP_PAStateOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpPointDistOpBuff_US_S_PointDistOutputBuff_t(P2VAR(US_S_PointDistOutputBuff_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpPointDistOpBuff_US_S_PointDistOutputBuff_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpRPAWarnOut_TbAP_RPAWarnOut_t(P2VAR(TbAP_RPAWarnOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpRPAWarnOut_TbAP_RPAWarnOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSMDAInternal_TbAP_SMDAInternalOut_t(P2VAR(TbAP_SMDAInternalOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpSMDAInternal_TbAP_SMDAInternalOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSR_State_MCU2_State_2_0(P2VAR(SSM_2_0_CoreStatus, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_0; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSR_State_MCU2_State_2_1(P2VAR(SSM_2_1_CoreStatus, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_1; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSVSNVMData_SVS_NVMData_t(P2VAR(SVS_NVMData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpSVSNVMData_SVS_NVMData_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSVStoTRSC_SVStoTRSC_t(P2VAR(SVStoTRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpSVStoTRSC_SVStoTRSC_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpScreenRequest_ScreenRequest_t(P2VAR(ScreenRequest_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpScreenRequest_ScreenRequest_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSvsToTHA_SvsToTHA_t(P2VAR(SvsToTHA_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpSvsToTHA_SvsToTHA_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpSvsToVCAN_SvsToVCAN_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTRSC_ME_VehOut_TRSC_t(P2VAR(ME_VehOut_TRSC_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpTRSC_ME_VehOut_TRSC_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTbAPDebugOut_TbAP_DebugOut(P2VAR(TbAP_DebugOut, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpTbAPDebugOut_TbAP_DebugOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTbAPSMPAOut_TbAP_SMPAInternalOut_t(P2VAR(TbAP_SMPAInternalOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t(P2VAR(TbFA_ArbiterOutput_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTbFAResetKM_TbFA_ResetKM_t(P2VAR(TbFA_ResetKM_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpTbFAResetKM_TbFA_ResetKM_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTrailerDetectOP_TrailerDetection_Output_DID_t(P2VAR(TrailerDetection_Output_DID_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpTrailerDetectOP_TrailerDetection_Output_DID_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTrscSmvctoSvs_TRSCSMVCtoSVS_t(P2VAR(TRSCSMVCtoSVS_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTrscToDiag_TRSCtoDiagMgr_t(P2VAR(TRSCtoDiagMgr_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpTrscToDiag_TRSCtoDiagMgr_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t(P2VAR(TRSC_Inputs_from_TrailerDetection_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpUSSBlockageBit_US_S_BlockageBit_t(P2VAR(US_S_BlockageBit_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpUSSBlockageBit_US_S_BlockageBit_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpUSSErrorDiagData_US_S_USSErrorDiagData_t(P2VAR(US_S_USSErrorDiagData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpUSSErrorDiagData_US_S_USSErrorDiagData_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpUssDataCollection_US_S_USSDataCollectionData_t(P2VAR(US_S_USSDataCollectionData_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpUssDataCollection_US_S_USSDataCollectionData_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpUssPointMapGrp_US_S_PointMapGroup_t(P2VAR(US_S_PointMapGroup_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpUssPointMapGrp_US_S_PointMapGroup_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpUssZoneInfo_US_S_ZoneInfo_t(P2VAR(US_S_ZoneInfo_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpUssZoneInfo_US_S_ZoneInfo_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpVCActuatorOut_TbAP_VCActuatorOut_t(P2VAR(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpVCActuatorOut_TbAP_VCActuatorOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_IPCHandler_RpVCState_TbAP_VCStateOut_t(P2VAR(TbAP_VCStateOut_t, AUTOMATIC, RTE_CDD_IPCHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpVCState_TbAP_VCStateOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_Safety_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_CDD_SAFETY_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_SSM_Master_P_SystemState_SystemState; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_WDG_RpKeepAliveResponse_KeepAliveResponse_t(P2VAR(KeepAliveResponse_t, AUTOMATIC, RTE_CDD_WDG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpKeepAliveResponse_KeepAliveResponse_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_WDG_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_WDG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_WDG_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_WDG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDD_WDG_RpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_CDD_WDG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_CDD_IPCHandler_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamCurrentCalibData_TbSVS_S_SVSCamCurrentCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamCurrentCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSVSCamCurrentCalib_TbSVS_S_SVSCamCurrentCalibDataToNVM_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamEOLCalibData_TbSVS_S_SVSCamEOLCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamEOLCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSVSCamEOLCalib_TbSVS_S_SVSCamEOLCalibDataToNVM_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamOCCalibData_TbSVS_S_SVSCamOCCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamOCCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSVSCamOCCalib_TbSVS_S_SVSCamOCCalibDataToNVM_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_CalDataProvider_Nvm_SVSCamSCCalibData_TbSVS_S_SVSCamSCCalibDataToNVM_t(P2VAR(TbSVS_S_SVSCamSCCalibDataToNVM_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSVSCamSCCalib_TbSVS_S_SVSCamSCCalibDataToNVM_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_SSM_1_0_State_State_1_0(P2VAR(SSM_1_0_CoreStatus, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SSM_Slave_1_0_P_SSM_1_0_State_State_1_0; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_SSM_2_State_State_2_0(P2VAR(SSM_2_0_CoreStatus, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_0; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_SSM_2_State_State_2_1(P2VAR(SSM_2_1_CoreStatus, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_1; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_SSM_QNXState_State_QNX(P2VAR(SSM_QNX_CoreStatus, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSR_State_QNX_State_QNX; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SSM_Master_P_SystemState_SystemState; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_RpCamEepromData_Svs_CamEepromDataArray_t(P2VAR(Svs_CamEepromDataArray_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpCamEepromData_Svs_CamEepromDataArray_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CalDataProvider_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_CALDATAPROVIDER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DegManager_B_R_Errors_B_Errors_B(P2VAR(uint32, AUTOMATIC, RTE_DEGMANAGER_B_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy32(data, Rte_ErrorMgrAgg_1_0_B_P_Errors_B_Errors_B, sizeof(ErrorListArr_B)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B(P2VAR(ErrorMgr_ErrorCommPack_1_0_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_1_0_B; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_2_0_B(P2VAR(ErrorMgr_ErrorCommPack_2_0_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_0_B; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_2_1_B(P2VAR(ErrorMgr_ErrorCommPack_2_1_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_2_1_B; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ErrorMgrAgg_1_0_B_R_SatError_Data_ErrorMgr_ErrorCommPack_QNX_B(P2VAR(ErrorMgr_ErrorCommPack_QNX_B, AUTOMATIC, RTE_ERRORMGRAGG_1_0_B_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_CDD_IPCHandler_PpSatError_B_Data_ErrorMgr_ErrorCommPack_QNX_B; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_R_SSM_1_0_State_State_1_0(P2VAR(SSM_1_0_CoreStatus, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SSM_Slave_1_0_P_SSM_1_0_State_State_1_0; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_R_SSM_2_State_State_2_0(P2VAR(SSM_2_0_CoreStatus, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_0; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_R_SSM_2_State_State_2_1(P2VAR(SSM_2_1_CoreStatus, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_1; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_R_SSM_QNXState_State_QNX(P2VAR(SSM_QNX_CoreStatus, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSR_State_QNX_State_QNX; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SSM_Master_P_SystemState_SystemState; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_ProxiConfigMgr_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_SWC_PROXICONFIGMGR_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_R_SSM_2_State_State_2_0(P2VAR(SSM_2_0_CoreStatus, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_0; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_R_SSM_2_State_State_2_1(P2VAR(SSM_2_1_CoreStatus, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSR_State_MCU2_State_2_1; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_R_SSM_QNXState_State_QNX(P2VAR(SSM_QNX_CoreStatus, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSR_State_QNX_State_QNX; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SSM_Master_P_SystemState_SystemState; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpAPSMPAOut_TbAP_APSMPAOut_t(P2VAR(TbAP_APSMPAOut_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpAPSMPAOut_TbAP_APSMPAOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2VAR(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(P2VAR(TbAP_DriveAssistStatOut_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t(P2VAR(TbTHASmVc_FeatureOutputs_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts(P2VAR(APARequestSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_APARequestSts_oBCM_FD_12_oFDCAN2_c58fc45d_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_APARequestSts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat(P2VAR(ASCM_Stat, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_ASCM_Stat_oASCM_FD_2_oFDCAN2_58854b4a_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_Stat_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail(P2VAR(ASCM_SysFail, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_ASCM_SysFail_oASCM_FD_2_oFDCAN2_9d00e371_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ASCM_SysFail_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode(P2VAR(Active_Park_Mode, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Active_Park_Mode_oIPC_VEHICLE_SETUP_oFDCAN2_6a2a58c7_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Mode_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime(P2VAR(Active_Park_Prox_Chime, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Active_Park_Prox_Chime_oIPC_VEHICLE_SETUP_oFDCAN2_ae5aba94_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Active_Park_Prox_Chime_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay(P2VAR(Backup_Cam_Delay, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Backup_Cam_Delay_oIPC_VEHICLE_SETUP_oFDCAN2_4de26278_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Backup_Cam_Delay_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT(P2VAR(CM_TCH_STAT, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CM_TCH_STAT_oTELEMATIC_FD_5_oFDCAN2_64ce192d_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_STAT_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD(P2VAR(CM_TCH_X_COORD, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CM_TCH_X_COORD_oTELEMATIC_FD_5_oFDCAN2_0177f5f2_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_X_COORD_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD(P2VAR(CM_TCH_Y_COORD, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CM_TCH_Y_COORD_oTELEMATIC_FD_5_oFDCAN2_0f901d23_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CM_TCH_Y_COORD_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2(P2VAR(CameraDisplaySts2, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CameraDisplaySts2_oTELEMATIC_FD_5_oFDCAN2_3ea6a9f0_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2 = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CameraDisplaySts2_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts(P2VAR(CmdIgnSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CmdIgnSts_oBCM_FD_10_oFDCAN2_06c30ef2_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_CmdIgnSts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts(P2VAR(DriverDoorSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_DriverDoorSts_oBCM_FD_9_oFDCAN2_5b5b4a2d_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_DriverDoorSts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp(P2VAR(ECM_THA_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_ECM_THA_Resp_oENGINE_FD_7_oFDCAN2_4f167839_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_THA_Resp_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp(P2VAR(ECM_TRSC_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN2_7dcf088b_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ECM_TRSC_Resp_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts(P2VAR(FT_PAMRequestSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_FT_PAMRequestSts_oBCM_FD_12_oFDCAN2_eca5b16e_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_FT_PAMRequestSts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines(P2VAR(Fwrd_Cam_Guidelines, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Fwrd_Cam_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_195fae0b_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Fwrd_Cam_Guidelines_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged(P2VAR(GearEngaged, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_GearEngaged_oTRANSM_FD_4_oFDCAN2_d9ac16c5_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_GearEngaged_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts(P2VAR(HU_TRSC_EnableBtn_Sts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_HU_TRSC_EnableBtn_Sts_oTELEMATIC_FD_11_oFDCAN2_298c059b_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_HU_TRSC_EnableBtn_Sts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat(P2VAR(ITBM_TrlrStat, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_ITBM_TrlrStat_oBCM_FD_29_oFDCAN2_144a42ca_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ITBM_TrlrStat_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts(P2VAR(LHRDoorSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_LHRDoorSts_oBCM_FD_9_oFDCAN2_6106f88b_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LHRDoorSts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection(P2VAR(LanguageSelection, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_LanguageSelection_oIPC_VEHICLE_SETUP_oFDCAN2_99c6c76e_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_LanguageSelection_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts(P2VAR(PAMRequestSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_PAMRequestSts_oBCM_FD_12_oFDCAN2_006058fe_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PAMRequestSts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront(P2VAR(PamChimeVolumeFront, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_PamChimeVolumeFront_oIPC_VEHICLE_SETUP_oFDCAN2_6b01781e_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeFront_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear(P2VAR(PamChimeVolumeRear, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_PamChimeVolumeRear_oIPC_VEHICLE_SETUP_oFDCAN2_f55f4149_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PamChimeVolumeRear_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts(P2VAR(PsngrDoorSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_PsngrDoorSts_oBCM_FD_9_oFDCAN2_661d805a_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_PsngrDoorSts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts(P2VAR(RHRDoorSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_RHRDoorSts_oBCM_FD_9_oFDCAN2_724acffd_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHRDoorSts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts(P2VAR(RHatchSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_RHatchSts_oBCM_FD_9_oFDCAN2_9f16b516_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_RHatchSts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst(P2VAR(Rear_Brk_Asst, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Rear_Brk_Asst_oIPC_VEHICLE_SETUP_oFDCAN2_96e3f1cb_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_Rear_Brk_Asst_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines(P2VAR(SVC_Guidelines, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SVC_Guidelines_oIPC_VEHICLE_SETUP_oFDCAN2_3eb27f57_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_SVC_Guidelines_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition(P2VAR(ShiftLeverPosition, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_ShiftLeverPosition_oTRANSM_FD_4_oFDCAN2_e41ef7f4_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPosition_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq(P2VAR(ShiftLeverPositionReq, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_ShiftLeverPositionReq_oAGSM_FD_2_oFDCAN2_dff8c8a2_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_ShiftLeverPositionReq_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS(P2VAR(TCASERANGESTATUS, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_TCASERANGESTATUS_oDRIVETRAIN_FD_3_oFDCAN2_eee864ec_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TCASERANGESTATUS_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT(P2VAR(TGW_CAMERA_DISP_STAT, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_TGW_CAMERA_DISP_STAT_oTELEMATIC_FD_14_oFDCAN2_9304ed4e_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD02Rx_TGW_CAMERA_DISP_STAT_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD02Rx_VIN_DATA(P2VAR(uint8, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_MemCpy(data, Rte_VIN_DATA_oVIN_oFDCAN2_c66224e9_Rx, sizeof(VIN_DATA)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp(P2VAR(FD14_BSM_THA_Brk_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_FD14_BSM_THA_Brk_Resp_oBRAKE_FD_5_oFDCAN14_cecdbc25_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_BSM_THA_Brk_Resp_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp(P2VAR(FD14_ECM_THA_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_FD14_ECM_THA_Resp_oENGINE_FD_7_oFDCAN14_284045ab_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_THA_Resp_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp(P2VAR(FD14_ECM_TRSC_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_FD14_ECM_TRSC_Resp_oENGINE_FD_7_oFDCAN14_994d6c00_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ECM_TRSC_Resp_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts(P2VAR(FD14_EPBSts, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_FD14_EPBSts_oBRAKE_FD_4_oFDCAN14_c0ca10e6_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_EPBSts_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp(P2VAR(FD14_ESC_TRSC_Brk_Resp, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_FD14_ESC_TRSC_Brk_Resp_oBRAKE_FD_5_oFDCAN14_2f38fcaf_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESC_TRSC_Brk_Resp_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W(P2VAR(FD14_ESS_ENG_ST_W, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_FD14_ESS_ENG_ST_W_oENGINE_FD_2_oFDCAN14_e3df5684_Rx; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_OsApplication_Safety_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W = Rte_OsApplication_QM_RxUpdateFlags.Rte_RxUpdate_SWC_SafeVCANRx_RpFromComSafeFD14Rx_FD14_ESS_ENG_ST_W_Sender;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t(P2VAR(ME_Proxi_MPU1_0_to_MCU1_0_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpMEProxi_ME_Proxi_MPU1_0_to_MCU1_0_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpProxiConfigData_ProxiData(P2VAR(ME_Hydra2defs_S_CodingTableExt_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_ProxiConfigMgr_PpProxiConfigData_ProxiData; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpSafeGuardPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Safety_Guard_PpSafeGuardPAStateOut_TbAP_PAStateOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpSafeGuardSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Safety_Guard_PpSafeGuardSvsToVCAN_SvsToVCAN_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpTRSC_ME_VehOut_TRSC_t(P2VAR(ME_VehOut_TRSC_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpTRSC_ME_VehOut_TRSC_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANRx_RpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t(P2VAR(ME_VehInp_to_IpcSignals_QM_t, AUTOMATIC, RTE_SWC_SAFEVCANRX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SWC_VCANRx_PpVcanRxQM_ME_VehInp_to_IpcSignals_QM_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_SSM_Master_P_SystemState_SystemState; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpAPSMPAOut_TbAP_APSMPAOut_t(P2VAR(TbAP_APSMPAOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpAPSMPAOut_TbAP_APSMPAOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2VAR(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2VAR(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(P2VAR(TbAP_DriveAssistStatOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpErrFltMcu2_0_Error_Fault_MCU2_0_t(P2VAR(Error_Fault_MCU2_0_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpErrFltMcu2_0_Error_Fault_MCU2_0_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpErrFltMcu2_1_Error_Fault_MCU2_1_t(P2VAR(Error_Fault_MCU2_1_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpErrFltMcu2_1_Error_Fault_MCU2_1_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpErrFltMpu1_0_Error_Fault_MPU1_0_t(P2VAR(Error_Fault_MPU1_0_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpErrFltMpu1_0_Error_Fault_MPU1_0_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpFPAWarnOut_TbAP_FPAWarnOut_t(P2VAR(TbAP_FPAWarnOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpFPAWarnOut_TbAP_FPAWarnOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpKeepAliveResponse_KeepAliveResponse_t(P2VAR(KeepAliveResponse_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpKeepAliveResponse_KeepAliveResponse_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpPAStateOut_TbAP_PAStateOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpRPAWarnOut_TbAP_RPAWarnOut_t(P2VAR(TbAP_RPAWarnOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpRPAWarnOut_TbAP_RPAWarnOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2VAR(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Safety_Guard_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2VAR(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Safety_Guard_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSafeGuardPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Safety_Guard_PpSafeGuardPAStateOut_TbAP_PAStateOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSafeGuardSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Safety_Guard_PpSafeGuardSvsToVCAN_SvsToVCAN_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t(P2VAR(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_Safety_Guard_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSvsToVCAN_SvsToVCAN_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpTRSC_ME_VehOut_TRSC_t(P2VAR(ME_VehOut_TRSC_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpTRSC_ME_VehOut_TRSC_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpTbAPDebugOut_TbAP_DebugOut(P2VAR(TbAP_DebugOut, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpTbAPDebugOut_TbAP_DebugOut; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpTbAPSMPAOut_TbAP_SMPAInternalOut_t(P2VAR(TbAP_SMPAInternalOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t(P2VAR(TbFA_ArbiterOutput_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpTbFAArbiterOutput_TbFA_ArbiterOutput_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpVCActuatorOut_TbAP_VCActuatorOut_t(P2VAR(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpVCActuatorOut_TbAP_VCActuatorOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_R_SafeState_B_SafeStateOp(P2VAR(SafeStateOpDef, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_ErrorMgrAgg_1_0_B_P_SafeState_SafeStateOp; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_R_SafeState_QM_SafeStateOp(P2VAR(SafeStateOpDef, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_ErrorMgrAgg_1_0_QM_P_SafeState_SafeStateOp; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2VAR(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2VAR(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_RpPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpPAStateOut_TbAP_PAStateOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_RpSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpSvsToVCAN_SvsToVCAN_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Safety_Guard_RpVCActuatorOut_TbAP_VCActuatorOut_t(P2VAR(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_SAFETY_GUARD_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CDD_IPCHandler_PpVCActuatorOut_TbAP_VCActuatorOut_t; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_SWC_SafeVCANRx_PpMode_VehicleSpeedCheck_Mode(uint8 nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 currentMode;
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  currentMode = Rte_ModeMachine_SWC_SafeVCANRx_PpMode_VehicleSpeedCheck_Mode;
  if (nextMode >= 2U)
  {
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    ret = RTE_E_LIMIT;
  }
  else if (currentMode >= 2U)
  {
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_SWC_SafeVCANRx_PpMode_VehicleSpeedCheck_Mode = nextMode;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Safety_Guard_SafetyGuard_SafeState_Mode_Mode(uint8 nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 currentMode;
  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  currentMode = Rte_ModeMachine_Safety_Guard_SafetyGuard_SafeState_Mode_Mode;
  if (nextMode >= 2U)
  {
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    ret = RTE_E_LIMIT;
  }
  else if (currentMode >= 2U)
  {
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_Safety_Guard_SafetyGuard_SafeState_Mode_Mode = nextMode;
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

#define RTE_STOP_SEC_OSAPPLICATION_SAFETY_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/
#define RTE_START_SEC_SAFETY_TASK_00_10MS_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Safety_Task_00_10ms
 * Priority: 79
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Safety_Task_00_10ms) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  /* call runnable */
  Cdd_RunTimeStats_B_Safety_Task_00_10ms_Start(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_SafeVCANRx_Main(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_SafeVCANTx_Main(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  WdgFw_Safety_Task_00_10ms_CP_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PMIC_Main(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_ProxiConfigMgr_Main(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Periodic_CalDataProvider(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  CDD_Safety_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Cdd_RunTimeStats_B_Safety_Task_00_10ms_Stop(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_SAFETY_TASK_00_10MS_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_SAFETY_TASK_01_10MS_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Safety_Task_01_10ms
 * Priority: 78
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Safety_Task_01_10ms) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  /* call runnable */
  Cdd_RunTimeStats_B_Safety_Task_01_10ms_Start(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  WdgFw_Safety_Task_01_10ms_CP_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_CddIpcHandler_Main(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Periodic_ErrorMgrSat_1_0_B(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Periodic_ErrorMgrAgg_1_0_B(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Periodic_DegManager_B(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  SafetyGuard_Main(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Cdd_RunTimeStats_B_Safety_Task_01_10ms_Stop(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_SAFETY_TASK_01_10MS_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_SAFETY_TASK_200MS_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Safety_Task_200ms
 * Priority: 44
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Safety_Task_200ms) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic_Safety_Task_200ms_0_200ms | Rte_Ev_Run_SWC_ProxiConfigMgr_RE_ProxiMgr_ConfigDataRSP); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Safety_Task_200ms, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_Safety_Task_200ms_0_200ms | Rte_Ev_Run_SWC_ProxiConfigMgr_RE_ProxiMgr_ConfigDataRSP)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_Safety_Task_200ms_0_200ms) != (EventMaskType)0)
    {
      /* call runnable */
      Cdd_RunTimeStats_B_Safety_Task_200ms_Start(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      WdgFw_Safety_Task_200ms_CP_200ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SWC_ProxiConfigMgr_RE_ProxiMgr_ConfigDataRSP) != (EventMaskType)0)
    {
      /* call runnable */
      RE_ProxiMgr_ConfigDataRSP(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Safety_Task_200ms_0_200ms) != (EventMaskType)0)
    {
      /* call runnable */
      Cdd_RunTimeStats_B_Safety_Task_200ms_Stop(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_SAFETY_TASK_200MS_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_SAFETY_TASK_INIT_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Safety_Task_Init
 * Priority: 90
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Safety_Task_Init) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  /* call runnable */
  Cdd_RunTimeStats_B_Safety_Task_Init_Start(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_SafeVCANRx_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_SafeVCANTx_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_CddIpcHandler_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_ProxiConfigMgr_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Init_ErrorMgrSat_1_0_B(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_E2EWrapper_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Init_ErrorMgrAgg_1_0_B(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_CalDataProvider_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_Init_DegManager_B(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_PMIC_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RE_WDG_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Cdd_RunTimeStats_B_Safety_Task_Init_Stop(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_SAFETY_TASK_INIT_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_SAFETY_WDGTASK_10MS_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Safety_WdgTask_10ms
 * Priority: 84
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Safety_WdgTask_10ms) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_Safety_WdgTask_10ms_0_10ms | Rte_Ev_Cyclic_Safety_WdgTask_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Safety_WdgTask_10ms, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_Safety_WdgTask_10ms_0_10ms | Rte_Ev_Cyclic_Safety_WdgTask_10ms_0_10ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_Safety_WdgTask_10ms_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Cdd_RunTimeStats_B_Safety_WdgTask_10ms_Start(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      WdgFw_Safety_Task_Com_10ms_CP_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      RE_WDG_Main(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      WdgM_MainFunction_Call_Cntr_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      WdgFw_10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_Safety_WdgTask_10ms_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      WdgM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_Safety_WdgTask_10ms_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Cdd_RunTimeStats_B_Safety_WdgTask_10ms_Stop(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_SAFETY_WDGTASK_10MS_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0310:  MISRA rule: Rule11.3
     Reason:     APIs called by Rte use complex array data types whereas Rte is called with base types.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_0314:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to void is performed.
     Prevention: Not required.

   MD_Rte_0315:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because generic access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0316:  MISRA rule: Dir1.1
     Reason:     Pointer cast to uint8* because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_1339:  MISRA rule: Rule17.8
     Reason:     Passing elements by pointer is a well known concept.
     Risk:       No functional risk. Data flow is handled with care.
     Prevention: Not required.

   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_1533:  MISRA rule: Rule8.9
     Reason:     Object is referenced by more than one function in different configurations.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_2982:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2983:  MISRA rule: Rule2.2
     Reason:     For generated code it is difficult to check the usage of each object.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2987:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
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
