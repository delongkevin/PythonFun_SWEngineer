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
 *             File:  Rte_SWC_SafeVCANTx.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application header file for SW-C <SWC_SafeVCANTx>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_SAFEVCANTX_H
# define RTE_SWC_SAFEVCANTX_H

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

# include "Rte_SWC_SafeVCANTx_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Alert_CHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHF;
extern VAR(Alert_CHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHR;
extern VAR(Alert_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHF;
extern VAR(Alert_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHR;
extern VAR(Alert_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHF;
extern VAR(Alert_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHR;
extern VAR(ChimeActivation_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHF;
extern VAR(ChimeActivation_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHR;
extern VAR(ChimeActivation_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHF;
extern VAR(ChimeActivation_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHR;
extern VAR(DisplayView2, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2;
extern VAR(FrontSensorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FrontSensorSts;
extern VAR(Graphic_CHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHF;
extern VAR(Graphic_CHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHR;
extern VAR(Graphic_LHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHF;
extern VAR(Graphic_LHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHR;
extern VAR(Graphic_RHF, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHF;
extern VAR(Graphic_RHR, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHR;
extern VAR(HMICode, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_HMICode;
extern VAR(ImageDefeatRQSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ImageDefeatRQSts;
extern VAR(PAMSystemFault, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAMSystemFault;
extern VAR(PAM_CHIME_REP_RATESts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts;
extern VAR(PAM_CHIME_TYPE, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE;
extern VAR(PAM_LedControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_LedControlSts;
extern VAR(PAM_Off_Status, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status;
extern VAR(PAM_PopUpRqst, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_PopUpRqst;
extern VAR(PAM_Volume, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Volume;
extern VAR(ParkingManeuverActive, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ParkingManeuverActive;
extern VAR(RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts;
extern VAR(RR_PAM_Dist, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Dist;
extern VAR(RR_PAM_StopControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts;
extern VAR(RearSensorSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RearSensorSts;
extern VAR(SPMControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMControlSts;
extern VAR(SPMFailSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMFailSts;
extern VAR(SPMSystemFault, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMSystemFault;
extern VAR(SPM_LedControlSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_LedControlSts;
extern VAR(SPM_Screen_Rqst, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_Screen_Rqst;
extern VAR(FD14_ManoeuvrePhase, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase;
extern VAR(FD14_RR_PAM_Brk_RqSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts;
extern VAR(FD14_RR_PAM_Dist, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist;
extern VAR(FD14_SPM_Lat_Ctrl_RequestSts, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts;
extern VAR(FD14_TorqueOverlaySteeringReq_SPM, RTE_VAR_INIT) Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM;

#  define RTE_STOP_SEC_VAR_OsApplication_Safety_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */

# ifndef RTE_CORE

#  define RTE_START_SEC_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* RTE Helper-Functions */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);

#  define RTE_STOP_SEC_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0 (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON (0U)
#  define Rte_InitValue_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_AUXCamsRQSts (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_Alert_CHF (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Alert_CHR (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Alert_LHF (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Alert_LHR (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Alert_RHF (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Alert_RHR (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Camera_Status (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_ChimeActivation_LHF (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_ChimeActivation_LHR (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_ChimeActivation_RHF (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_ChimeActivation_RHR (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_DisplayView2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_FOD_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_FT_PAM_LedControlSts (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Frame_Index_Lanes_1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Frame_Index_Lanes_2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_FrontSensorSts (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Graphic_CHF (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Graphic_CHR (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Graphic_LHF (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Graphic_LHR (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Graphic_RHF (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Graphic_RHR (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_HMICode (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Health_Front_Object_Detection (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Health_Lane_Detection (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_ImageDefeatRQSts (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_1_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_1_Curvature (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_1_Curvature_Rate (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_1_End_Range (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_1_Heading (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_1_Offset (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_1_Start_Range (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_1_Type (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_2_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_2_Curvature (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_2_Curvature_Rate (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_2_End_Range (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_2_Heading (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_2_Offset (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_2_Start_Range (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_2_Type (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_3_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_3_Curvature (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_3_Curvature_Rate (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_3_End_Range (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_3_Heading (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_3_Offset (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_3_Start_Range (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_3_Type (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_4_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_4_Curvature (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_4_Curvature_Rate (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_4_End_Range (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_4_Heading (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_4_Offset (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_4_Start_Range (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Line_4_Type (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_MoreCamsRQSts (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_PAMSystemFault (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_PAM_CHIME_TYPE (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_PAM_LedControlSts (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_PAM_Off_Status (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_PAM_Off_Status_2BT (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_PAM_PopUpRqst (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_PAM_Volume (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_ParkingManeuverActive (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_RR_PAM_Dist (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_RR_PAM_StopControlSts (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_RearSensorSts (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Reserved_for_functional_safety (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_SPMControlSts (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_SPMFailSts (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_SPMSystemFault (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_SPM_LedControlSts (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_SPM_Screen_Rqst (FALSE)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_1_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_1_ID (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_1_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_1_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_1_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_1_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_2_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_2_ID (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_2_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_2_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_2_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_2_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_3_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_3_ID (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_3_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_3_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_3_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_3_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_4_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_4_ID (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_4_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_4_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_4_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_4_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_5_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_5_ID (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_5_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_5_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_5_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_5_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_6_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_6_ID (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_6_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_6_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_6_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_6_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_7_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_7_ID (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_7_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_7_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_7_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_7_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_8_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_8_ID (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_8_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_8_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_8_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_Segment_8_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD02Tx_TRSC_LED_Stat (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Camera_Status (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_FOD_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Health_Lane_Detection (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_1_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_1_Curvature (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_1_End_Range (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_1_Heading (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_1_Offset (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_1_Start_Range (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_1_Type (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_2_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_2_Curvature (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_2_End_Range (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_2_Heading (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_2_Offset (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_2_Start_Range (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_2_Type (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_3_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_3_Curvature (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_3_End_Range (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_3_Heading (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_3_Offset (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_3_Start_Range (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_3_Type (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_4_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_4_Curvature (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_4_End_Range (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_4_Heading (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_4_Offset (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_4_Start_Range (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Line_4_Type (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_ManoeuvrePhase (FALSE)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_AccelMax (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_AccelMin (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_DecelMax (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_DecelMin (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst (FALSE)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_ParkingManeuverActive (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts (FALSE)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_RR_PAM_Dist (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_1_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_1_ID (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_1_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_1_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_1_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_1_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_2_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_2_ID (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_2_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_2_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_2_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_2_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_3_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_3_ID (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_3_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_3_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_3_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_3_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_4_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_4_ID (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_4_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_4_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_4_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_4_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_5_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_5_ID (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_5_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_5_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_5_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_5_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_6_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_6_ID (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_6_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_6_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_6_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_6_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_7_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_7_ID (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_7_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_7_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_7_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_7_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_8_Confidence (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_8_ID (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_8_X1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_8_X2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_8_Y1 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_Segment_8_Y2 (0U)
#  define Rte_InitValue_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM (1024U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_AUXCamsRQSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Alert_CHF (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Alert_CHR (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Alert_LHF (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Alert_LHR (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Alert_RHF (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Alert_RHR (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Camera_Status (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_ChimeActivation_LHF (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_ChimeActivation_LHR (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_ChimeActivation_RHF (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_ChimeActivation_RHR (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_DisplayView2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_FOD_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_FT_PAM_LedControlSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Frame_Index_Lanes_1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Frame_Index_Lanes_2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_FrontSensorSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Graphic_CHF (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Graphic_CHR (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Graphic_LHF (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Graphic_LHR (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Graphic_RHF (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Graphic_RHR (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_HMICode (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Health_Front_Object_Detection (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Health_Lane_Detection (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_ImageDefeatRQSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_1_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_1_Curvature (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_1_Curvature_Rate (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_1_End_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_1_Heading (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_1_Offset (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_1_Start_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_1_Type (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_2_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_2_Curvature (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_2_Curvature_Rate (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_2_End_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_2_Heading (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_2_Offset (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_2_Start_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_2_Type (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_3_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_3_Curvature (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_3_Curvature_Rate (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_3_End_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_3_Heading (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_3_Offset (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_3_Start_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_3_Type (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_4_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_4_Curvature (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_4_Curvature_Rate (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_4_End_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_4_Heading (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_4_Offset (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_4_Start_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Line_4_Type (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_MoreCamsRQSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_PAMSystemFault (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_PAM_LedControlSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_PAM_Off_Status (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_PAM_Off_Status_2BT (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_PAM_PopUpRqst (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_PAM_Volume (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_PPPA_TurnIndicatorRqst (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_ParkingManeuverActive (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_RR_PAM_Dist (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_RearSensorSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Reserved_for_functional_safety (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_SPMControlSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_SPMFailSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_SPMSystemFault (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_SPM_LedControlSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_SPM_Screen_Rqst (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_1_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_1_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_1_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_1_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_1_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_1_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_2_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_2_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_2_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_2_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_2_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_2_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_3_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_3_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_3_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_3_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_3_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_3_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_4_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_4_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_4_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_4_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_4_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_4_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_5_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_5_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_5_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_5_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_5_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_5_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_6_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_6_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_6_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_6_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_6_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_6_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_7_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_7_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_7_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_7_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_7_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_7_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_8_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_8_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_8_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_8_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_8_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_Segment_8_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD02Tx_TRSC_LED_Stat (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Camera_Status (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_FOD_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Frame_Index_Lanes_1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Frame_Index_Lanes_2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Health_Front_Object_Detection (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Health_Lane_Detection (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_1_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_1_Curvature (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_1_Curvature_Rate (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_1_End_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_1_Heading (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_1_Offset (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_1_Start_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_1_Type (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_2_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_2_Curvature (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_2_Curvature_Rate (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_2_End_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_2_Heading (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_2_Offset (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_2_Start_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_2_Type (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_3_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_3_Curvature (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_3_Curvature_Rate (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_3_End_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_3_Heading (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_3_Offset (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_3_Start_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_3_Type (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_4_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_4_Curvature (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_4_Curvature_Rate (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_4_End_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_4_Heading (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_4_Offset (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_4_Start_Range (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Line_4_Type (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_AccelMax (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_AccelMin (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_DecelMax (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_DecelMin (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_Interface_BSM (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_JerkAccelMax (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_JerkAccelMin (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_JerkDecelMax (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_JerkDecelMin (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_MaxSpeed (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_StandstillRqst (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_PPPA_TargetDistance (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_ParkingGearShiftReq (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_ParkingManeuverActive (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts (FALSE)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Reserved_for_functional_safety (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_1_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_1_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_1_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_1_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_1_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_1_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_2_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_2_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_2_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_2_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_2_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_2_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_3_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_3_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_3_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_3_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_3_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_3_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_4_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_4_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_4_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_4_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_4_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_4_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_5_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_5_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_5_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_5_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_5_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_5_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_6_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_6_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_6_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_6_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_6_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_6_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_7_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_7_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_7_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_7_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_7_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_7_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_8_Confidence (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_8_ID (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_8_X1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_8_X2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_8_Y1 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_Segment_8_Y2 (0U)
#  define Rte_InitValue_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM (1024U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_AUXCamsRQSts (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Alert_CHF (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Alert_CHR (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Alert_LHF (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Alert_LHR (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Alert_RHF (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Alert_RHR (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Camera_Status (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_ChimeActivation_LHF (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_ChimeActivation_LHR (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_ChimeActivation_RHF (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_ChimeActivation_RHR (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_DisplayView2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_FOD_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_FT_PAM_LedControlSts (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Frame_Index_Lanes_1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Frame_Index_Lanes_2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_FrontSensorSts (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Graphic_CHF (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Graphic_CHR (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Graphic_LHF (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Graphic_LHR (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Graphic_RHF (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Graphic_RHR (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_HMICode (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Health_Front_Object_Detection (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Health_Lane_Detection (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_ImageDefeatRQSts (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_1_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_1_Curvature (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_1_Curvature_Rate (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_1_End_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_1_Heading (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_1_Offset (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_1_Start_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_1_Type (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_2_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_2_Curvature (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_2_Curvature_Rate (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_2_End_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_2_Heading (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_2_Offset (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_2_Start_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_2_Type (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_3_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_3_Curvature (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_3_Curvature_Rate (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_3_End_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_3_Heading (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_3_Offset (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_3_Start_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_3_Type (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_4_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_4_Curvature (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_4_Curvature_Rate (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_4_End_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_4_Heading (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_4_Offset (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_4_Start_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Line_4_Type (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_MoreCamsRQSts (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_PAMSystemFault (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_PAM_CHIME_REP_RATESts (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_PAM_CHIME_TYPE (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_PAM_LedControlSts (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_PAM_Off_Status (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_PAM_Off_Status_2BT (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_PAM_PopUpRqst (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_PAM_Volume (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_PPPA_TurnIndicatorRqst (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_ParkingManeuverActive (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_RR_PAM_Brk_RqSts (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_RR_PAM_Dist (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_RR_PAM_StopControlSts (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_RearSensorSts (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Reserved_for_functional_safety (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_SPMControlSts (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_SPMFailSts (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_SPMSystemFault (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_SPM_LedControlSts (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_SPM_Screen_Rqst (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_1_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_1_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_1_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_1_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_1_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_1_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_2_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_2_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_2_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_2_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_2_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_2_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_3_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_3_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_3_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_3_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_3_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_3_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_4_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_4_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_4_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_4_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_4_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_4_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_5_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_5_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_5_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_5_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_5_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_5_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_6_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_6_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_6_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_6_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_6_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_6_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_7_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_7_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_7_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_7_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_7_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_7_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_8_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_8_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_8_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_8_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_8_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_Segment_8_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD02Tx_TRSC_LED_Stat (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Camera_Status (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_FOD_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Frame_Index_Lanes_1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Frame_Index_Lanes_2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Health_Front_Object_Detection (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Health_Lane_Detection (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_1_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_1_Curvature (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_1_Curvature_Rate (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_1_End_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_1_Heading (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_1_Offset (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_1_Start_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_1_Type (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_2_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_2_Curvature (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_2_Curvature_Rate (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_2_End_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_2_Heading (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_2_Offset (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_2_Start_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_2_Type (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_3_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_3_Curvature (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_3_Curvature_Rate (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_3_End_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_3_Heading (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_3_Offset (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_3_Start_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_3_Type (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_4_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_4_Curvature (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_4_Curvature_Rate (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_4_End_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_4_Heading (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_4_Offset (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_4_Start_Range (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Line_4_Type (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_ManoeuvrePhase (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_AccelMax (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_AccelMin (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_DecelMax (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_DecelMin (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_Interface_BSM (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkAccelMax (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkAccelMin (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkDecelMax (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkDecelMin (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_MaxSpeed (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_StandstillRqst (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_PPPA_TargetDistance (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_ParkingGearShiftReq (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_ParkingManeuverActive (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts (FALSE)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_RR_PAM_Dist (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Reserved_for_functional_safety (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_1_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_1_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_1_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_1_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_1_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_1_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_2_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_2_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_2_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_2_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_2_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_2_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_3_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_3_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_3_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_3_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_3_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_3_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_4_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_4_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_4_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_4_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_4_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_4_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_5_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_5_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_5_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_5_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_5_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_5_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_6_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_6_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_6_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_6_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_6_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_6_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_7_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_7_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_7_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_7_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_7_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_7_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_8_Confidence (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_8_ID (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_8_X1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_8_X2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_8_Y1 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_Segment_8_Y2 (0U)
#  define Rte_InitValue_RpFromSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM (1024U)
# endif


# define RTE_START_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_R_SystemState_SystemState(P2VAR(SSM_SystemState, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpAPSMPAOut_TbAP_APSMPAOut_t(P2VAR(TbAP_APSMPAOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2VAR(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2VAR(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t(P2VAR(TbAP_DriveAssistStatOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpErrFltMcu2_0_Error_Fault_MCU2_0_t(P2VAR(Error_Fault_MCU2_0_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpErrFltMcu2_1_Error_Fault_MCU2_1_t(P2VAR(Error_Fault_MCU2_1_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpErrFltMpu1_0_Error_Fault_MPU1_0_t(P2VAR(Error_Fault_MPU1_0_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpFPAWarnOut_TbAP_FPAWarnOut_t(P2VAR(TbAP_FPAWarnOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpKeepAliveResponse_KeepAliveResponse_t(P2VAR(KeepAliveResponse_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpRPAWarnOut_TbAP_RPAWarnOut_t(P2VAR(TbAP_RPAWarnOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(P2VAR(IFOD_Outputs_CVPAMFDData_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(P2VAR(LMD_Outputs_CVPAMFDData2_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSafeGuardPAStateOut_TbAP_PAStateOut_t(P2VAR(TbAP_PAStateOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSafeGuardSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t(P2VAR(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpSvsToVCAN_SvsToVCAN_t(P2VAR(SvsToVCAN_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpTRSC_ME_VehOut_TRSC_t(P2VAR(ME_VehOut_TRSC_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpTbAPDebugOut_TbAP_DebugOut(P2VAR(TbAP_DebugOut, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpTbAPSMPAOut_TbAP_SMPAInternalOut_t(P2VAR(TbAP_SMPAInternalOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t(P2VAR(TbFA_ArbiterOutput_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpVCActuatorOut_TbAP_VCActuatorOut_t(P2VAR(TbAP_VCActuatorOut_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_SafeVCANTx_RpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t(P2VAR(WdgCheckpointStatus_t, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0(FD14_1_AliveCntr_MCU2_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1(FD14_1_AliveCntr_MCU2_1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0(FD14_1_AliveCntr_MPU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0(FD14_1_ErrFaultInfo_MCU2_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0(FD14_1_Err_FaultInfo_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1(FD14_1_Err_FaultInfo_MCU2_1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0(FD14_1_Err_FaultInfo_MPU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0(FD14_1_Err_FaultNum_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0(FD14_1_Err_FaultNum_MCU2_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1(FD14_1_Err_FaultNum_MCU2_1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0(FD14_1_Err_FaultNum_MPU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0(FD14_1_Hook_DtErr_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0(FD14_1_Hook_Error_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0(FD14_1_Hook_PresentPtr_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0(FD14_1_Hook_Reserved_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0(FD14_1_Hook_Service_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0(FD14_1_Hook_Type_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0(FD14_1_Hook_actTsk_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0(FD14_1_Hook_fatalErr_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR(FD14_1_OsRegMCU_ADFSR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR(FD14_1_OsRegMCU_AIFSR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR(FD14_1_OsRegMCU_DFAR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR(FD14_1_OsRegMCU_DFSR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR(FD14_1_OsRegMCU_IFAR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR(FD14_1_OsRegMCU_IFSR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link(FD14_1_OsRegMCU_Link data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR(FD14_1_OsRegMCU_SPSR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0(FD14_1_OsRegMCU_Stack0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1(FD14_1_OsRegMCU_Stack1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2(FD14_1_OsRegMCU_Stack2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3(FD14_1_OsRegMCU_Stack3 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4(FD14_1_OsRegMCU_Stack4 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5(FD14_1_OsRegMCU_Stack5 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6(FD14_1_OsRegMCU_Stack6 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7(FD14_1_OsRegMCU_Stack7 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8(FD14_1_OsRegMCU_Stack8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9(FD14_1_OsRegMCU_Stack9 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0(FD14_1_Reserved_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0(FD14_1_Reserved_MCU2_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1(FD14_1_Reserved_MCU2_1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0(FD14_1_Reserved_MPU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0(FD14_1_SDL_Fault_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0(FD14_1_SSM_FltData10_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0(FD14_1_SSM_FltData11_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0(FD14_1_SSM_FltData12_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0(FD14_1_SSM_FltData13_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0(FD14_1_SSM_FltData14_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0(FD14_1_SSM_FltData15_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0(FD14_1_SSM_FltData16_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0(FD14_1_SSM_FltData17_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0(FD14_1_SSM_FltData18_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0(FD14_1_SSM_FltData1_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0(FD14_1_SSM_FltData2_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0(FD14_1_SSM_FltData3_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0(FD14_1_SSM_FltData4_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0(FD14_1_SSM_FltData5_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0(FD14_1_SSM_FltData6_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0(FD14_1_SSM_FltData7_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0(FD14_1_SSM_FltData8_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0(FD14_1_SSM_FltData9_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq(FD14_1_SSM_SystemStateReq data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON(FD14_1_TimeSincePowerON data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0(FD14_1_WDG_Error_ID_MCU1_0 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts(AUXCamsRQSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF(Alert_CHF data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR(Alert_CHR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF(Alert_LHF data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR(Alert_LHR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF(Alert_RHF data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR(Alert_RHR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status(Camera_Status data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF(ChimeActivation_LHF data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR(ChimeActivation_LHR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF(ChimeActivation_RHF data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR(ChimeActivation_RHR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1(Cntr_ADAS_FD_LANES_1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2(Cntr_ADAS_FD_LANES_2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2(DisplayView2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence(FOD_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts(FT_PAM_LedControlSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1(Frame_Index_Lanes_1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2(Frame_Index_Lanes_2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts(FrontSensorSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF(Graphic_CHF data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR(Graphic_CHR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF(Graphic_LHF data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR(Graphic_LHR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF(Graphic_RHF data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR(Graphic_RHR data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode(HMICode data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection(Health_Front_Object_Detection data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection(Health_Lane_Detection data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts(ImageDefeatRQSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence(Line_1_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature(Line_1_Curvature data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate(Line_1_Curvature_Rate data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range(Line_1_End_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading(Line_1_Heading data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset(Line_1_Offset data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range(Line_1_Start_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type(Line_1_Type data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence(Line_2_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature(Line_2_Curvature data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate(Line_2_Curvature_Rate data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range(Line_2_End_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading(Line_2_Heading data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset(Line_2_Offset data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range(Line_2_Start_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type(Line_2_Type data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence(Line_3_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature(Line_3_Curvature data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate(Line_3_Curvature_Rate data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range(Line_3_End_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading(Line_3_Heading data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset(Line_3_Offset data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range(Line_3_Start_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type(Line_3_Type data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence(Line_4_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature(Line_4_Curvature data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate(Line_4_Curvature_Rate data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range(Line_4_End_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading(Line_4_Heading data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset(Line_4_Offset data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range(Line_4_Start_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type(Line_4_Type data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1(P2CONST(uint8, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1(P2CONST(MAC_ADAS_FD_LANES_1, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2(P2CONST(uint8, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2(P2CONST(MAC_ADAS_FD_LANES_2, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts(MoreCamsRQSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault(PAMSystemFault data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts(PAM_CHIME_REP_RATESts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE(PAM_CHIME_TYPE data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts(PAM_LedControlSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status(PAM_Off_Status data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT(PAM_Off_Status_2BT data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst(PAM_PopUpRqst data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume(PAM_Volume data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst(PPPA_TurnIndicatorRqst data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive(ParkingManeuverActive data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts(RR_PAM_Brk_RqSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist(RR_PAM_Dist data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts(RR_PAM_StopControlSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts(RearSensorSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety(Reserved_for_functional_safety data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts(SPMControlSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts(SPMFailSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault(SPMSystemFault data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts(SPM_LedControlSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst(SPM_Screen_Rqst data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence(Segment_1_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID(Segment_1_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1(Segment_1_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2(Segment_1_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1(Segment_1_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2(Segment_1_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence(Segment_2_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID(Segment_2_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1(Segment_2_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2(Segment_2_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1(Segment_2_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2(Segment_2_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence(Segment_3_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID(Segment_3_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1(Segment_3_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2(Segment_3_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1(Segment_3_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2(Segment_3_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence(Segment_4_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID(Segment_4_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1(Segment_4_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2(Segment_4_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1(Segment_4_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2(Segment_4_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence(Segment_5_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID(Segment_5_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1(Segment_5_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2(Segment_5_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1(Segment_5_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2(Segment_5_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence(Segment_6_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID(Segment_6_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1(Segment_6_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2(Segment_6_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1(Segment_6_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2(Segment_6_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence(Segment_7_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID(Segment_7_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1(Segment_7_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2(Segment_7_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1(Segment_7_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2(Segment_7_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence(Segment_8_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID(Segment_8_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1(Segment_8_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2(Segment_8_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1(Segment_8_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2(Segment_8_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat(TRSC_LED_Stat data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status(FD14_Camera_Status data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1(FD14_Cntr_ADAS_FD_LANES_1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2(FD14_Cntr_ADAS_FD_LANES_2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence(FD14_FOD_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1(FD14_Frame_Index_Lanes_1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2(FD14_Frame_Index_Lanes_2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection(FD14_Health_Front_Object_Detection data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection(FD14_Health_Lane_Detection data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence(FD14_Line_1_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature(FD14_Line_1_Curvature data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate(FD14_Line_1_Curvature_Rate data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range(FD14_Line_1_End_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading(FD14_Line_1_Heading data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset(FD14_Line_1_Offset data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range(FD14_Line_1_Start_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type(FD14_Line_1_Type data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence(FD14_Line_2_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature(FD14_Line_2_Curvature data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate(FD14_Line_2_Curvature_Rate data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range(FD14_Line_2_End_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading(FD14_Line_2_Heading data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset(FD14_Line_2_Offset data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range(FD14_Line_2_Start_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type(FD14_Line_2_Type data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence(FD14_Line_3_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature(FD14_Line_3_Curvature data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate(FD14_Line_3_Curvature_Rate data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range(FD14_Line_3_End_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading(FD14_Line_3_Heading data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset(FD14_Line_3_Offset data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range(FD14_Line_3_Start_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type(FD14_Line_3_Type data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence(FD14_Line_4_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature(FD14_Line_4_Curvature data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate(FD14_Line_4_Curvature_Rate data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range(FD14_Line_4_End_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading(FD14_Line_4_Heading data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset(FD14_Line_4_Offset data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range(FD14_Line_4_Start_Range data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type(FD14_Line_4_Type data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1(P2CONST(uint8, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1(P2CONST(FD14_MAC_ADAS_FD_LANES_1, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2(P2CONST(uint8, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2(P2CONST(FD14_MAC_ADAS_FD_LANES_2, AUTOMATIC, RTE_SWC_SAFEVCANTX_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase(FD14_ManoeuvrePhase data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax(FD14_PPPA_AccelMax data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin(FD14_PPPA_AccelMin data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax(FD14_PPPA_DecelMax data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin(FD14_PPPA_DecelMin data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM(FD14_PPPA_Interface_BSM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax(FD14_PPPA_JerkAccelMax data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin(FD14_PPPA_JerkAccelMin data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax(FD14_PPPA_JerkDecelMax data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin(FD14_PPPA_JerkDecelMin data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed(FD14_PPPA_MaxSpeed data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst(FD14_PPPA_StandstillRqst data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance(FD14_PPPA_TargetDistance data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq(FD14_ParkingGearShiftReq data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive(FD14_ParkingManeuverActive data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts(FD14_RR_PAM_Brk_RqSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist(FD14_RR_PAM_Dist data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety(FD14_Reserved_for_functional_safety data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts(FD14_SPM_Lat_Ctrl_RequestSts data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence(FD14_Segment_1_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID(FD14_Segment_1_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1(FD14_Segment_1_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2(FD14_Segment_1_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1(FD14_Segment_1_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2(FD14_Segment_1_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence(FD14_Segment_2_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID(FD14_Segment_2_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1(FD14_Segment_2_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2(FD14_Segment_2_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1(FD14_Segment_2_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2(FD14_Segment_2_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence(FD14_Segment_3_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID(FD14_Segment_3_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1(FD14_Segment_3_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2(FD14_Segment_3_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1(FD14_Segment_3_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2(FD14_Segment_3_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence(FD14_Segment_4_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID(FD14_Segment_4_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1(FD14_Segment_4_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2(FD14_Segment_4_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1(FD14_Segment_4_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2(FD14_Segment_4_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence(FD14_Segment_5_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID(FD14_Segment_5_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1(FD14_Segment_5_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2(FD14_Segment_5_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1(FD14_Segment_5_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2(FD14_Segment_5_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence(FD14_Segment_6_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID(FD14_Segment_6_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1(FD14_Segment_6_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2(FD14_Segment_6_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1(FD14_Segment_6_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2(FD14_Segment_6_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence(FD14_Segment_7_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID(FD14_Segment_7_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1(FD14_Segment_7_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2(FD14_Segment_7_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1(FD14_Segment_7_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2(FD14_Segment_7_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence(FD14_Segment_8_Confidence data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID(FD14_Segment_8_ID data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1(FD14_Segment_8_X1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2(FD14_Segment_8_X2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1(FD14_Segment_8_Y1 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2(FD14_Segment_8_Y2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM(FD14_TorqueOverlaySteeringReq_SPM data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_OSAPPLICATION_SAFETY_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_SystemState_SystemState Rte_Read_SWC_SafeVCANTx_R_SystemState_SystemState
#  define Rte_Read_RpAPSMPAOut_TbAP_APSMPAOut_t Rte_Read_SWC_SafeVCANTx_RpAPSMPAOut_TbAP_APSMPAOut_t
#  define Rte_Read_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t Rte_Read_SWC_SafeVCANTx_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t
#  define Rte_Read_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t Rte_Read_SWC_SafeVCANTx_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t
#  define Rte_Read_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t Rte_Read_SWC_SafeVCANTx_RpDriveAssistStatOut_TbAP_DriveAssistStatOut_t
#  define Rte_Read_RpErrFltMcu2_0_Error_Fault_MCU2_0_t Rte_Read_SWC_SafeVCANTx_RpErrFltMcu2_0_Error_Fault_MCU2_0_t
#  define Rte_Read_RpErrFltMcu2_1_Error_Fault_MCU2_1_t Rte_Read_SWC_SafeVCANTx_RpErrFltMcu2_1_Error_Fault_MCU2_1_t
#  define Rte_Read_RpErrFltMpu1_0_Error_Fault_MPU1_0_t Rte_Read_SWC_SafeVCANTx_RpErrFltMpu1_0_Error_Fault_MPU1_0_t
#  define Rte_Read_RpFPAWarnOut_TbAP_FPAWarnOut_t Rte_Read_SWC_SafeVCANTx_RpFPAWarnOut_TbAP_FPAWarnOut_t
#  define Rte_Read_RpFromSwcSafeFD02Tx_AUXCamsRQSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_AUXCamsRQSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_AUXCamsRQSts(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Alert_CHF Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_CHF

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_CHF(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Alert_CHR Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_CHR

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_CHR(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Alert_LHF Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_LHF

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_LHF(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Alert_LHR Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_LHR

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_LHR(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Alert_RHF Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_RHF

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_RHF(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Alert_RHR Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_RHR

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Alert_RHR(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Camera_Status Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Camera_Status

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Camera_Status(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_ChimeActivation_LHF Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ChimeActivation_LHF

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ChimeActivation_LHF(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_ChimeActivation_LHR Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ChimeActivation_LHR

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ChimeActivation_LHR(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_ChimeActivation_RHF Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ChimeActivation_RHF

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ChimeActivation_RHF(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_ChimeActivation_RHR Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ChimeActivation_RHR

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ChimeActivation_RHR(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_DisplayView2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_DisplayView2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_DisplayView2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_FOD_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_FOD_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_FOD_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_FT_PAM_LedControlSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_FT_PAM_LedControlSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_FT_PAM_LedControlSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Frame_Index_Lanes_1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Frame_Index_Lanes_1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Frame_Index_Lanes_1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Frame_Index_Lanes_2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Frame_Index_Lanes_2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Frame_Index_Lanes_2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_FrontSensorSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_FrontSensorSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_FrontSensorSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Graphic_CHF Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_CHF

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_CHF(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Graphic_CHR Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_CHR

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_CHR(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Graphic_LHF Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_LHF

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_LHF(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Graphic_LHR Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_LHR

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_LHR(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Graphic_RHF Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_RHF

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_RHF(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Graphic_RHR Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_RHR

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Graphic_RHR(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_HMICode Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_HMICode

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_HMICode(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Health_Front_Object_Detection Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Health_Front_Object_Detection

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Health_Front_Object_Detection(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Health_Lane_Detection Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Health_Lane_Detection

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Health_Lane_Detection(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_ImageDefeatRQSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ImageDefeatRQSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ImageDefeatRQSts(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Curvature Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Curvature

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Curvature(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Curvature_Rate Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Curvature_Rate

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Curvature_Rate(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_1_End_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_End_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_End_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Heading Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Heading

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Heading(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Offset Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Offset

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Offset(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Start_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Start_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Start_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_1_Type Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Type

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_1_Type(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Curvature Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Curvature

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Curvature(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Curvature_Rate Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Curvature_Rate

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Curvature_Rate(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_2_End_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_End_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_End_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Heading Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Heading

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Heading(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Offset Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Offset

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Offset(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Start_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Start_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Start_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_2_Type Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Type

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_2_Type(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Curvature Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Curvature

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Curvature(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Curvature_Rate Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Curvature_Rate

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Curvature_Rate(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_3_End_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_End_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_End_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Heading Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Heading

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Heading(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Offset Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Offset

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Offset(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Start_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Start_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Start_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_3_Type Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Type

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_3_Type(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Curvature Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Curvature

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Curvature(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Curvature_Rate Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Curvature_Rate

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Curvature_Rate(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_4_End_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_End_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_End_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Heading Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Heading

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Heading(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Offset Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Offset

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Offset(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Start_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Start_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Start_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Line_4_Type Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Type

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Line_4_Type(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_MAC_ADAS_FD_LANES_1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_MAC_ADAS_FD_LANES_1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_MAC_ADAS_FD_LANES_1(data) ( \
    Rte_MemCpy(data, Rte_C_MAC_ADAS_FD_LANES_1_0, sizeof(MAC_ADAS_FD_LANES_1)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_MAC_ADAS_FD_LANES_2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_MAC_ADAS_FD_LANES_2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_MAC_ADAS_FD_LANES_2(data) ( \
    Rte_MemCpy(data, Rte_C_MAC_ADAS_FD_LANES_2_0, sizeof(MAC_ADAS_FD_LANES_2)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_MoreCamsRQSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_MoreCamsRQSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_MoreCamsRQSts(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_PAMSystemFault Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAMSystemFault

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAMSystemFault(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_PAM_CHIME_REP_RATESts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_CHIME_REP_RATESts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_CHIME_REP_RATESts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_PAM_CHIME_TYPE Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_CHIME_TYPE

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_CHIME_TYPE(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_PAM_LedControlSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_LedControlSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_LedControlSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_PAM_Off_Status Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_Off_Status

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_Off_Status(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_PAM_Off_Status_2BT Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_Off_Status_2BT

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_Off_Status_2BT(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_PAM_PopUpRqst Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_PopUpRqst

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_PopUpRqst(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_PAM_Volume Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_Volume

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PAM_Volume(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_PPPA_TurnIndicatorRqst Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PPPA_TurnIndicatorRqst

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_PPPA_TurnIndicatorRqst(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_ParkingManeuverActive Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ParkingManeuverActive

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_ParkingManeuverActive(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_RR_PAM_Brk_RqSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_RR_PAM_Brk_RqSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_RR_PAM_Brk_RqSts(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_RR_PAM_Dist Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_RR_PAM_Dist

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_RR_PAM_Dist(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_RR_PAM_StopControlSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_RR_PAM_StopControlSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_RR_PAM_StopControlSts(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_RearSensorSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_RearSensorSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_RearSensorSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Reserved_for_functional_safety Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Reserved_for_functional_safety

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Reserved_for_functional_safety(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_SPMControlSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_SPMControlSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_SPMControlSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_SPMFailSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_SPMFailSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_SPMFailSts(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_SPMSystemFault Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_SPMSystemFault

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_SPMSystemFault(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_SPM_LedControlSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_SPM_LedControlSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_SPM_LedControlSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_SPM_Screen_Rqst Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_SPM_Screen_Rqst

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_SPM_Screen_Rqst(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_1_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_1_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_2_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_2_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_3_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_3_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_4_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_4_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_5_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_5_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_6_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_6_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_7_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_7_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_Segment_8_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_Segment_8_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD02Tx_TRSC_LED_Stat Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_TRSC_LED_Stat

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD02Tx_TRSC_LED_Stat(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Camera_Status Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Camera_Status

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Camera_Status(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_FOD_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_FOD_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_FOD_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Frame_Index_Lanes_1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Frame_Index_Lanes_1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Frame_Index_Lanes_1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Frame_Index_Lanes_2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Frame_Index_Lanes_2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Frame_Index_Lanes_2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Health_Front_Object_Detection Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Health_Front_Object_Detection

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Health_Front_Object_Detection(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Health_Lane_Detection Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Health_Lane_Detection

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Health_Lane_Detection(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Curvature Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Curvature

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Curvature(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Curvature_Rate Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Curvature_Rate

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Curvature_Rate(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_End_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_End_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_End_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Heading Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Heading

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Heading(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Offset Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Offset

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Offset(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Start_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Start_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Start_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_1_Type Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Type

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_1_Type(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Curvature Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Curvature

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Curvature(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Curvature_Rate Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Curvature_Rate

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Curvature_Rate(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_End_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_End_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_End_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Heading Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Heading

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Heading(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Offset Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Offset

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Offset(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Start_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Start_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Start_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_2_Type Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Type

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_2_Type(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Curvature Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Curvature

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Curvature(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Curvature_Rate Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Curvature_Rate

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Curvature_Rate(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_End_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_End_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_End_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Heading Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Heading

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Heading(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Offset Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Offset

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Offset(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Start_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Start_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Start_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_3_Type Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Type

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_3_Type(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Curvature Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Curvature

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Curvature(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Curvature_Rate Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Curvature_Rate

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Curvature_Rate(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_End_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_End_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_End_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Heading Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Heading

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Heading(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Offset Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Offset

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Offset(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Start_Range Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Start_Range

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Start_Range(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Line_4_Type Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Type

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Line_4_Type(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1(data) ( \
    Rte_MemCpy(data, Rte_C_FD14_MAC_ADAS_FD_LANES_1_0, sizeof(FD14_MAC_ADAS_FD_LANES_1)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2(data) ( \
    Rte_MemCpy(data, Rte_C_FD14_MAC_ADAS_FD_LANES_2_0, sizeof(FD14_MAC_ADAS_FD_LANES_2)) \
    ,((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_ManoeuvrePhase Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_ManoeuvrePhase

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_ManoeuvrePhase(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_AccelMax Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_AccelMax

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_AccelMax(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_AccelMin Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_AccelMin

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_AccelMin(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_DecelMax Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_DecelMax

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_DecelMax(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_DecelMin Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_DecelMin

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_DecelMin(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_Interface_BSM Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_Interface_BSM

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_Interface_BSM(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkAccelMax Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkAccelMax

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkAccelMax(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkAccelMin Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkAccelMin

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkAccelMin(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkDecelMax Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkDecelMax

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkDecelMax(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkDecelMin Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkDecelMin

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_JerkDecelMin(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_MaxSpeed Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_MaxSpeed

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_MaxSpeed(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_StandstillRqst Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_StandstillRqst

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_StandstillRqst(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_PPPA_TargetDistance Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_TargetDistance

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_PPPA_TargetDistance(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_ParkingGearShiftReq Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_ParkingGearShiftReq

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_ParkingGearShiftReq(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_ParkingManeuverActive Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_ParkingManeuverActive

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_ParkingManeuverActive(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts(data) (*(data) = FALSE, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_RR_PAM_Dist Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_RR_PAM_Dist

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_RR_PAM_Dist(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Reserved_for_functional_safety Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Reserved_for_functional_safety

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Reserved_for_functional_safety(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_1_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_1_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_2_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_2_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_3_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_3_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_4_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_4_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_5_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_5_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_6_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_6_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_7_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_7_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_Confidence Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_Confidence

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_Confidence(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_ID Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_ID

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_ID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_X1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_X1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_X1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_X2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_X2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_X2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_Y1 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_Y1

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_Y1(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_Segment_8_Y2 Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_Y2

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_Segment_8_Y2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpFromSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM

#  define Rte_Read_SWC_SafeVCANTx_RpFromSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM(data) (*(data) = 1024U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_RpKeepAliveResponse_KeepAliveResponse_t Rte_Read_SWC_SafeVCANTx_RpKeepAliveResponse_KeepAliveResponse_t
#  define Rte_Read_RpPAStateOut_TbAP_PAStateOut_t Rte_Read_SWC_SafeVCANTx_RpPAStateOut_TbAP_PAStateOut_t
#  define Rte_Read_RpRPAWarnOut_TbAP_RPAWarnOut_t Rte_Read_SWC_SafeVCANTx_RpRPAWarnOut_TbAP_RPAWarnOut_t
#  define Rte_Read_RpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t Rte_Read_SWC_SafeVCANTx_RpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t
#  define Rte_Read_RpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t Rte_Read_SWC_SafeVCANTx_RpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t
#  define Rte_Read_RpSafeGuardPAStateOut_TbAP_PAStateOut_t Rte_Read_SWC_SafeVCANTx_RpSafeGuardPAStateOut_TbAP_PAStateOut_t
#  define Rte_Read_RpSafeGuardSvsToVCAN_SvsToVCAN_t Rte_Read_SWC_SafeVCANTx_RpSafeGuardSvsToVCAN_SvsToVCAN_t
#  define Rte_Read_RpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t Rte_Read_SWC_SafeVCANTx_RpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t
#  define Rte_Read_RpSvsToVCAN_SvsToVCAN_t Rte_Read_SWC_SafeVCANTx_RpSvsToVCAN_SvsToVCAN_t
#  define Rte_Read_RpTRSC_ME_VehOut_TRSC_t Rte_Read_SWC_SafeVCANTx_RpTRSC_ME_VehOut_TRSC_t
#  define Rte_Read_RpTbAPDebugOut_TbAP_DebugOut Rte_Read_SWC_SafeVCANTx_RpTbAPDebugOut_TbAP_DebugOut
#  define Rte_Read_RpTbAPSMPAOut_TbAP_SMPAInternalOut_t Rte_Read_SWC_SafeVCANTx_RpTbAPSMPAOut_TbAP_SMPAInternalOut_t
#  define Rte_Read_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t Rte_Read_SWC_SafeVCANTx_RpTbFAArbiterOutput_TbFA_ArbiterOutput_t
#  define Rte_Read_RpVCActuatorOut_TbAP_VCActuatorOut_t Rte_Read_SWC_SafeVCANTx_RpVCActuatorOut_TbAP_VCActuatorOut_t
#  define Rte_Read_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t Rte_Read_SWC_SafeVCANTx_RpWdgCheckpointStatusMcu2_0_WdgCheckpointStatus_t
#  define Rte_Read_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t Rte_Read_SWC_SafeVCANTx_RpWdgCheckpointStatusMcu2_1_WdgCheckpointStatus_t
#  define Rte_Read_RpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t Rte_Read_SWC_SafeVCANTx_RpWdgCheckpointStatusMpu1_0_WdgCheckpointStatus_t


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MCU2_1
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_AliveCntr_MPU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_ErrFaultInfo_MCU2_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MCU2_1
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultInfo_MPU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MCU2_1
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Err_FaultNum_MPU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_DtErr_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Error_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_PresentPtr_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Reserved_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Service_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_Type_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_actTsk_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Hook_fatalErr_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_ADFSR
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_AIFSR
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFAR
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_DFSR
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFAR
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_IFSR
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Link
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_SPSR
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack1
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack2
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack3
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack4
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack5
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack6
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack7
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack8
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_OsRegMCU_Stack9
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MCU2_1
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_Reserved_MPU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SDL_Fault_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData10_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData11_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData12_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData13_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData14_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData15_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData16_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData17_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData18_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData1_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData2_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData3_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData4_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData5_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData6_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData7_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData8_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_FltData9_MCU1_0
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_SSM_SystemStateReq
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_TimeSincePowerON
#  define Rte_Write_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0 Rte_Write_SWC_SafeVCANTx_PpToComDbgSafeFD14Tx_FD14_1_WDG_Error_ID_MCU1_0
#  define Rte_Write_PpToComSafeFD02Tx_AUXCamsRQSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_AUXCamsRQSts
#  define Rte_Write_PpToComSafeFD02Tx_Alert_CHF Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHF
#  define Rte_Write_PpToComSafeFD02Tx_Alert_CHR Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_CHR
#  define Rte_Write_PpToComSafeFD02Tx_Alert_LHF Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHF
#  define Rte_Write_PpToComSafeFD02Tx_Alert_LHR Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_LHR
#  define Rte_Write_PpToComSafeFD02Tx_Alert_RHF Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHF
#  define Rte_Write_PpToComSafeFD02Tx_Alert_RHR Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Alert_RHR
#  define Rte_Write_PpToComSafeFD02Tx_Camera_Status Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Camera_Status
#  define Rte_Write_PpToComSafeFD02Tx_ChimeActivation_LHF Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHF
#  define Rte_Write_PpToComSafeFD02Tx_ChimeActivation_LHR Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_LHR
#  define Rte_Write_PpToComSafeFD02Tx_ChimeActivation_RHF Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHF
#  define Rte_Write_PpToComSafeFD02Tx_ChimeActivation_RHR Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ChimeActivation_RHR
#  define Rte_Write_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_1
#  define Rte_Write_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Cntr_ADAS_FD_LANES_2
#  define Rte_Write_PpToComSafeFD02Tx_DisplayView2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_DisplayView2
#  define Rte_Write_PpToComSafeFD02Tx_FOD_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_FOD_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_FT_PAM_LedControlSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_FT_PAM_LedControlSts
#  define Rte_Write_PpToComSafeFD02Tx_Frame_Index_Lanes_1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_1
#  define Rte_Write_PpToComSafeFD02Tx_Frame_Index_Lanes_2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Frame_Index_Lanes_2
#  define Rte_Write_PpToComSafeFD02Tx_FrontSensorSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_FrontSensorSts
#  define Rte_Write_PpToComSafeFD02Tx_Graphic_CHF Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHF
#  define Rte_Write_PpToComSafeFD02Tx_Graphic_CHR Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_CHR
#  define Rte_Write_PpToComSafeFD02Tx_Graphic_LHF Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHF
#  define Rte_Write_PpToComSafeFD02Tx_Graphic_LHR Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_LHR
#  define Rte_Write_PpToComSafeFD02Tx_Graphic_RHF Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHF
#  define Rte_Write_PpToComSafeFD02Tx_Graphic_RHR Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Graphic_RHR
#  define Rte_Write_PpToComSafeFD02Tx_HMICode Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_HMICode
#  define Rte_Write_PpToComSafeFD02Tx_Health_Front_Object_Detection Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Front_Object_Detection
#  define Rte_Write_PpToComSafeFD02Tx_Health_Lane_Detection Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Health_Lane_Detection
#  define Rte_Write_PpToComSafeFD02Tx_ImageDefeatRQSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ImageDefeatRQSts
#  define Rte_Write_PpToComSafeFD02Tx_Line_1_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Line_1_Curvature Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature
#  define Rte_Write_PpToComSafeFD02Tx_Line_1_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Curvature_Rate
#  define Rte_Write_PpToComSafeFD02Tx_Line_1_End_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_End_Range
#  define Rte_Write_PpToComSafeFD02Tx_Line_1_Heading Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Heading
#  define Rte_Write_PpToComSafeFD02Tx_Line_1_Offset Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Offset
#  define Rte_Write_PpToComSafeFD02Tx_Line_1_Start_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Start_Range
#  define Rte_Write_PpToComSafeFD02Tx_Line_1_Type Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_1_Type
#  define Rte_Write_PpToComSafeFD02Tx_Line_2_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Line_2_Curvature Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature
#  define Rte_Write_PpToComSafeFD02Tx_Line_2_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Curvature_Rate
#  define Rte_Write_PpToComSafeFD02Tx_Line_2_End_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_End_Range
#  define Rte_Write_PpToComSafeFD02Tx_Line_2_Heading Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Heading
#  define Rte_Write_PpToComSafeFD02Tx_Line_2_Offset Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Offset
#  define Rte_Write_PpToComSafeFD02Tx_Line_2_Start_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Start_Range
#  define Rte_Write_PpToComSafeFD02Tx_Line_2_Type Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_2_Type
#  define Rte_Write_PpToComSafeFD02Tx_Line_3_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Line_3_Curvature Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature
#  define Rte_Write_PpToComSafeFD02Tx_Line_3_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Curvature_Rate
#  define Rte_Write_PpToComSafeFD02Tx_Line_3_End_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_End_Range
#  define Rte_Write_PpToComSafeFD02Tx_Line_3_Heading Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Heading
#  define Rte_Write_PpToComSafeFD02Tx_Line_3_Offset Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Offset
#  define Rte_Write_PpToComSafeFD02Tx_Line_3_Start_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Start_Range
#  define Rte_Write_PpToComSafeFD02Tx_Line_3_Type Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_3_Type
#  define Rte_Write_PpToComSafeFD02Tx_Line_4_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Line_4_Curvature Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature
#  define Rte_Write_PpToComSafeFD02Tx_Line_4_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Curvature_Rate
#  define Rte_Write_PpToComSafeFD02Tx_Line_4_End_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_End_Range
#  define Rte_Write_PpToComSafeFD02Tx_Line_4_Heading Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Heading
#  define Rte_Write_PpToComSafeFD02Tx_Line_4_Offset Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Offset
#  define Rte_Write_PpToComSafeFD02Tx_Line_4_Start_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Start_Range
#  define Rte_Write_PpToComSafeFD02Tx_Line_4_Type Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Line_4_Type
#  define Rte_Write_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_1
#  define Rte_Write_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MAC_ADAS_FD_LANES_2
#  define Rte_Write_PpToComSafeFD02Tx_MoreCamsRQSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_MoreCamsRQSts
#  define Rte_Write_PpToComSafeFD02Tx_PAMSystemFault Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAMSystemFault
#  define Rte_Write_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_REP_RATESts
#  define Rte_Write_PpToComSafeFD02Tx_PAM_CHIME_TYPE Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_CHIME_TYPE
#  define Rte_Write_PpToComSafeFD02Tx_PAM_LedControlSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_LedControlSts
#  define Rte_Write_PpToComSafeFD02Tx_PAM_Off_Status Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status
#  define Rte_Write_PpToComSafeFD02Tx_PAM_Off_Status_2BT Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Off_Status_2BT
#  define Rte_Write_PpToComSafeFD02Tx_PAM_PopUpRqst Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_PopUpRqst
#  define Rte_Write_PpToComSafeFD02Tx_PAM_Volume Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PAM_Volume
#  define Rte_Write_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_PPPA_TurnIndicatorRqst
#  define Rte_Write_PpToComSafeFD02Tx_ParkingManeuverActive Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_ParkingManeuverActive
#  define Rte_Write_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Brk_RqSts
#  define Rte_Write_PpToComSafeFD02Tx_RR_PAM_Dist Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_Dist
#  define Rte_Write_PpToComSafeFD02Tx_RR_PAM_StopControlSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RR_PAM_StopControlSts
#  define Rte_Write_PpToComSafeFD02Tx_RearSensorSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_RearSensorSts
#  define Rte_Write_PpToComSafeFD02Tx_Reserved_for_functional_safety Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Reserved_for_functional_safety
#  define Rte_Write_PpToComSafeFD02Tx_SPMControlSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMControlSts
#  define Rte_Write_PpToComSafeFD02Tx_SPMFailSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMFailSts
#  define Rte_Write_PpToComSafeFD02Tx_SPMSystemFault Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPMSystemFault
#  define Rte_Write_PpToComSafeFD02Tx_SPM_LedControlSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_LedControlSts
#  define Rte_Write_PpToComSafeFD02Tx_SPM_Screen_Rqst Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_SPM_Screen_Rqst
#  define Rte_Write_PpToComSafeFD02Tx_Segment_1_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Segment_1_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_ID
#  define Rte_Write_PpToComSafeFD02Tx_Segment_1_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_1_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_X2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_1_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_1_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_1_Y2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_2_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Segment_2_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_ID
#  define Rte_Write_PpToComSafeFD02Tx_Segment_2_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_2_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_X2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_2_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_2_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_2_Y2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_3_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Segment_3_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_ID
#  define Rte_Write_PpToComSafeFD02Tx_Segment_3_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_3_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_X2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_3_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_3_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_3_Y2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_4_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Segment_4_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_ID
#  define Rte_Write_PpToComSafeFD02Tx_Segment_4_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_4_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_X2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_4_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_4_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_4_Y2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_5_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Segment_5_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_ID
#  define Rte_Write_PpToComSafeFD02Tx_Segment_5_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_5_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_X2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_5_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_5_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_5_Y2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_6_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Segment_6_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_ID
#  define Rte_Write_PpToComSafeFD02Tx_Segment_6_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_6_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_X2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_6_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_6_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_6_Y2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_7_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Segment_7_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_ID
#  define Rte_Write_PpToComSafeFD02Tx_Segment_7_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_7_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_X2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_7_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_7_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_7_Y2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_8_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Confidence
#  define Rte_Write_PpToComSafeFD02Tx_Segment_8_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_ID
#  define Rte_Write_PpToComSafeFD02Tx_Segment_8_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_8_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_X2
#  define Rte_Write_PpToComSafeFD02Tx_Segment_8_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y1
#  define Rte_Write_PpToComSafeFD02Tx_Segment_8_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_Segment_8_Y2
#  define Rte_Write_PpToComSafeFD02Tx_TRSC_LED_Stat Rte_Write_SWC_SafeVCANTx_PpToComSafeFD02Tx_TRSC_LED_Stat
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Camera_Status Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Camera_Status
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_FOD_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_FOD_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Frame_Index_Lanes_2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Front_Object_Detection
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Health_Lane_Detection Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Health_Lane_Detection
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Curvature Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Curvature_Rate
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_End_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_End_Range
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Heading Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Heading
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Offset Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Offset
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Start_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Start_Range
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_1_Type Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_1_Type
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Curvature Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Curvature_Rate
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_End_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_End_Range
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Heading Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Heading
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Offset Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Offset
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Start_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Start_Range
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_2_Type Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_2_Type
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Curvature Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Curvature_Rate
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_End_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_End_Range
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Heading Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Heading
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Offset Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Offset
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Start_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Start_Range
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_3_Type Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_3_Type
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Curvature Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Curvature_Rate
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_End_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_End_Range
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Heading Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Heading
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Offset Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Offset
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Start_Range Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Start_Range
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Line_4_Type Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Line_4_Type
#  define Rte_Write_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_ManoeuvrePhase Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ManoeuvrePhase
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_AccelMax Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMax
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_AccelMin Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_AccelMin
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_DecelMax Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMax
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_DecelMin Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_DecelMin
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_Interface_BSM
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMax
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkAccelMin
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMax
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_JerkDecelMin
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_MaxSpeed
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_StandstillRqst
#  define Rte_Write_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_PPPA_TargetDistance
#  define Rte_Write_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingGearShiftReq
#  define Rte_Write_PpToComSafeFD14Tx_FD14_ParkingManeuverActive Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_ParkingManeuverActive
#  define Rte_Write_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Brk_RqSts
#  define Rte_Write_PpToComSafeFD14Tx_FD14_RR_PAM_Dist Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_RR_PAM_Dist
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Reserved_for_functional_safety
#  define Rte_Write_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_ID
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_X2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_1_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_1_Y2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_ID
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_X2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_2_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_2_Y2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_ID
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_X2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_3_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_3_Y2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_ID
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_X2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_4_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_4_Y2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_ID
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_X2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_5_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_5_Y2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_ID
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_X2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_6_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_6_Y2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_ID
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_X2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_7_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_7_Y2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_Confidence Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Confidence
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_ID Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_ID
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_X1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_X2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_X2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_Y1 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y1
#  define Rte_Write_PpToComSafeFD14Tx_FD14_Segment_8_Y2 Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_Segment_8_Y2
#  define Rte_Write_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM Rte_Write_SWC_SafeVCANTx_PpToComSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM
#  define Rte_Write_PpToSwcSafeFD02Tx_AUXCamsRQSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_AUXCamsRQSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_AUXCamsRQSts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Alert_CHF Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHF
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHF(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHF = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Alert_CHR Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHR
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHR(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_CHR = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Alert_LHF Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHF
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHF(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHF = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Alert_LHR Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHR
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHR(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_LHR = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Alert_RHF Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHF
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHF(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHF = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Alert_RHR Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHR
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHR(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Alert_RHR = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Camera_Status Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Camera_Status
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Camera_Status(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_ChimeActivation_LHF Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHF
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHF(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHF = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_ChimeActivation_LHR Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHR
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHR(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_LHR = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_ChimeActivation_RHF Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHF
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHF(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHF = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_ChimeActivation_RHR Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHR
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHR(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ChimeActivation_RHR = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Cntr_ADAS_FD_LANES_2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_DisplayView2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_DisplayView2 = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_FOD_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FOD_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FOD_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_FT_PAM_LedControlSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FT_PAM_LedControlSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FT_PAM_LedControlSts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Frame_Index_Lanes_1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Frame_Index_Lanes_1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Frame_Index_Lanes_1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Frame_Index_Lanes_2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Frame_Index_Lanes_2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Frame_Index_Lanes_2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_FrontSensorSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FrontSensorSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FrontSensorSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_FrontSensorSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Graphic_CHF Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHF
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHF(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHF = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Graphic_CHR Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHR
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHR(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_CHR = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Graphic_LHF Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHF
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHF(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHF = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Graphic_LHR Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHR
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHR(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_LHR = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Graphic_RHF Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHF
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHF(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHF = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Graphic_RHR Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHR
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHR(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Graphic_RHR = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_HMICode Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_HMICode
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_HMICode(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_HMICode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Health_Front_Object_Detection Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Health_Front_Object_Detection
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Health_Front_Object_Detection(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Health_Lane_Detection Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Health_Lane_Detection
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Health_Lane_Detection(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_ImageDefeatRQSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ImageDefeatRQSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ImageDefeatRQSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ImageDefeatRQSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_1_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_1_Curvature Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Curvature
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Curvature(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_1_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Curvature_Rate
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Curvature_Rate(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_1_End_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_End_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_End_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_1_Heading Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Heading
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Heading(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_1_Offset Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Offset
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Offset(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_1_Start_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Start_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Start_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_1_Type Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Type
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_1_Type(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_2_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_2_Curvature Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Curvature
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Curvature(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_2_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Curvature_Rate
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Curvature_Rate(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_2_End_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_End_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_End_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_2_Heading Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Heading
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Heading(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_2_Offset Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Offset
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Offset(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_2_Start_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Start_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Start_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_2_Type Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Type
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_2_Type(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_3_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_3_Curvature Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Curvature
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Curvature(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_3_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Curvature_Rate
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Curvature_Rate(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_3_End_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_End_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_End_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_3_Heading Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Heading
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Heading(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_3_Offset Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Offset
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Offset(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_3_Start_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Start_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Start_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_3_Type Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Type
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_3_Type(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_4_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_4_Curvature Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Curvature
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Curvature(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_4_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Curvature_Rate
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Curvature_Rate(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_4_End_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_End_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_End_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_4_Heading Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Heading
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Heading(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_4_Offset Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Offset
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Offset(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_4_Start_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Start_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Start_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Line_4_Type Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Type
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Line_4_Type(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_MAC_ADAS_FD_LANES_1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_MAC_ADAS_FD_LANES_1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_MAC_ADAS_FD_LANES_1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_MAC_ADAS_FD_LANES_2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_MAC_ADAS_FD_LANES_2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_MAC_ADAS_FD_LANES_2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_MoreCamsRQSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_MoreCamsRQSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_MoreCamsRQSts(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_PAMSystemFault Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAMSystemFault
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAMSystemFault(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAMSystemFault = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_REP_RATESts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_CHIME_TYPE = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_PAM_LedControlSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_LedControlSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_LedControlSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_LedControlSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_PAM_Off_Status Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_PAM_Off_Status_2BT Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status_2BT
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Off_Status_2BT(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_PAM_PopUpRqst Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_PopUpRqst
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_PopUpRqst(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_PopUpRqst = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_PAM_Volume Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Volume
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Volume(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PAM_Volume = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_PPPA_TurnIndicatorRqst Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PPPA_TurnIndicatorRqst
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_PPPA_TurnIndicatorRqst(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_ParkingManeuverActive Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ParkingManeuverActive
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ParkingManeuverActive(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_ParkingManeuverActive = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Brk_RqSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_RR_PAM_Dist Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Dist
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Dist(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_Dist = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RR_PAM_StopControlSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_RearSensorSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RearSensorSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RearSensorSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_RearSensorSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Reserved_for_functional_safety Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Reserved_for_functional_safety
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Reserved_for_functional_safety(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_SPMControlSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMControlSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMControlSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMControlSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_SPMFailSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMFailSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMFailSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMFailSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_SPMSystemFault Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMSystemFault
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMSystemFault(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPMSystemFault = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_SPM_LedControlSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_LedControlSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_LedControlSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_LedControlSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_SPM_Screen_Rqst Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_Screen_Rqst
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_Screen_Rqst(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_SPM_Screen_Rqst = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_1_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_1_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_1_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_1_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_1_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_1_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_1_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_2_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_2_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_2_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_2_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_2_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_2_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_2_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_3_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_3_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_3_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_3_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_3_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_3_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_3_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_4_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_4_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_4_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_4_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_4_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_4_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_4_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_5_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_5_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_5_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_5_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_5_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_5_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_5_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_6_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_6_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_6_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_6_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_6_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_6_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_6_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_7_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_7_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_7_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_7_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_7_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_7_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_7_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_8_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_8_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_8_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_8_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_8_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_Segment_8_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_Segment_8_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD02Tx_TRSC_LED_Stat Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_TRSC_LED_Stat
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD02Tx_TRSC_LED_Stat(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Camera_Status Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Camera_Status
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Camera_Status(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Cntr_ADAS_FD_LANES_2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_FOD_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_FOD_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_FOD_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Frame_Index_Lanes_1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Frame_Index_Lanes_1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Frame_Index_Lanes_1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Frame_Index_Lanes_2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Frame_Index_Lanes_2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Frame_Index_Lanes_2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Health_Front_Object_Detection Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Health_Front_Object_Detection
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Health_Front_Object_Detection(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Health_Lane_Detection Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Health_Lane_Detection
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Health_Lane_Detection(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Curvature Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Curvature
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Curvature(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Curvature_Rate
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Curvature_Rate(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_End_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_End_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_End_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Heading Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Heading
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Heading(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Offset Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Offset
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Offset(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Start_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Start_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Start_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_1_Type Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Type
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_1_Type(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Curvature Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Curvature
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Curvature(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Curvature_Rate
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Curvature_Rate(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_End_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_End_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_End_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Heading Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Heading
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Heading(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Offset Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Offset
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Offset(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Start_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Start_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Start_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_2_Type Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Type
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_2_Type(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Curvature Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Curvature
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Curvature(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Curvature_Rate
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Curvature_Rate(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_End_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_End_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_End_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Heading Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Heading
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Heading(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Offset Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Offset
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Offset(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Start_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Start_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Start_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_3_Type Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Type
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_3_Type(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Curvature Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Curvature
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Curvature(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Curvature_Rate Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Curvature_Rate
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Curvature_Rate(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_End_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_End_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_End_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Heading Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Heading
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Heading(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Offset Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Offset
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Offset(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Start_Range Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Start_Range
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Start_Range(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Line_4_Type Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Type
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Line_4_Type(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_MAC_ADAS_FD_LANES_2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ManoeuvrePhase = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_AccelMax Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_AccelMax
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_AccelMax(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_AccelMin Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_AccelMin
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_AccelMin(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_DecelMax Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_DecelMax
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_DecelMax(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_DecelMin Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_DecelMin
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_DecelMin(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_Interface_BSM Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_Interface_BSM
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_Interface_BSM(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_JerkAccelMax Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_JerkAccelMax
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_JerkAccelMax(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_JerkAccelMin Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_JerkAccelMin
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_JerkAccelMin(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_JerkDecelMax Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_JerkDecelMax
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_JerkDecelMax(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_JerkDecelMin Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_JerkDecelMin
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_JerkDecelMin(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_MaxSpeed Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_MaxSpeed
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_MaxSpeed(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_StandstillRqst Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_StandstillRqst
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_StandstillRqst(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_PPPA_TargetDistance Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_TargetDistance
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_PPPA_TargetDistance(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_ParkingGearShiftReq Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ParkingGearShiftReq
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ParkingGearShiftReq(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_ParkingManeuverActive Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ParkingManeuverActive
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_ParkingManeuverActive(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Brk_RqSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_RR_PAM_Dist = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Reserved_for_functional_safety Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Reserved_for_functional_safety
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Reserved_for_functional_safety(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_SPM_Lat_Ctrl_RequestSts = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_1_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_1_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_2_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_2_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_3_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_3_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_4_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_4_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_5_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_5_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_6_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_6_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_7_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_7_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_Confidence Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_Confidence
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_Confidence(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_ID Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_ID
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_ID(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_X1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_X1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_X1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_X2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_X2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_X2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_Y1 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_Y1
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_Y1(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_Segment_8_Y2 Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_Y2
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_Segment_8_Y2(data) (RTE_E_OK)
#  define Rte_Write_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM
#  define Rte_Write_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM(data) (Rte_SWC_SafeVCANTx_PpToSwcSafeFD14Tx_FD14_TorqueOverlaySteeringReq_SPM = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CDD_E2EWRAPPER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CDD_E2EWRAPPER_APPL_CODE) RE_E2EWrapperProtect(P2VAR(E2E_MEP_ConfigType, AUTOMATIC, RTE_VAR_NOINIT) ConfigPtr, P2VAR(E2E_MEP_ProtectStateType, AUTOMATIC, RTE_VAR_NOINIT) StatePtr, P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) DataPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CDD_E2EWRAPPER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_RpE2EServices_ME_E2E_Protect RE_E2EWrapperProtect

# endif /* !defined(RTE_CORE) */


# define SWC_SafeVCANTx_START_SEC_CODE
# include "SWC_SafeVCANTx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RE_SafeVCANTx_Init RE_SafeVCANTx_Init
#  define RTE_RUNNABLE_RE_SafeVCANTx_Main RE_SafeVCANTx_Main
# endif

FUNC(void, SWC_SafeVCANTx_CODE) RE_SafeVCANTx_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_SafeVCANTx_CODE) RE_SafeVCANTx_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define SWC_SafeVCANTx_STOP_SEC_CODE
# include "SWC_SafeVCANTx_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_NULL (19U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_INPUTERR_WRONG (23U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_INTERR (25U)

#  define RTE_E_IF_E2EServices_ME_E2E_E_WRONGSTATE (26U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_SAFEVCANTX_H */

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
