/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Safety_Guard.c
 *           Config:  D:/git/L2H4060_Software_develop/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  Safety_Guard
 *  Generation Time:  2024-02-14 16:04:32
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <Safety_Guard>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * CameraStatus_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * LaneDetHealth_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * LaneType_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TeAP_e_PAMChimeRepnRate
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMChimeTyp
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMLedCtrlStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMPopUpReq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * TeAP_e_PAMVolume
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * aSigConverter_E_DisplayView2_t
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * real32_T
 *   float32 corresponds to the IEEE single-precision 32-bit floating point type
 *      [IEEE 754-1985]. The basic value space of float32 consists of the values 
 *      m * 2^e, where m is an integer whose absolute value is less than 2^24, 
 *      and e is an integer between -149 and 104, inclusive. In addition to the basic
 *      value space described above, the value space of float32 also contains the 
 *      following special values: positive and negative zero, positive and negative 
 *      infinity and not-a-number. The order-relation on float32 is: 
 *      x < y if y - x is positive. Positive zero is greater than negative zero.
 *      Not-a-number equals itself and is greater than all float values including positive infinity. 
 *      
 *      float32 values have a lexical representation consisting of a mantissa followed, 
 *      optionally, by the character "E" or "e", followed by an exponent. The exponent
 *      must be an integer. The mantissa must be a decimal number. The representations
 *      for exponent and mantissa must follow the lexical rules for integer and decimal.
 *      If the "E" or "e" and the following exponent are omitted, an exponent value 
 *      of 0 is assumed. 
 *      
 *      The special values positive and negative zero, positive and negative infinity
 *      and not-a-number have lexical representations 0, -0, INF, -INF and NaN, 
 *      respectively. 
 *      
 *      For example, -1E4, 1267.43233E12, 12.78e-2, 12 and INF are all legal literals
 *      for float32.
 *
 *********************************************************************************************************************/

#include "Rte_Safety_Guard.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "ErrorManagerDef.h"
#include "vstdlib.h"
#include "NvM.h"
#include "Ea.h"
#include "Eep_30_XXi2c01.h"
#include "fusa_application.h"

__attribute__ ((section("QMRAM"))) VAR(uint16, RTE_VAR_DEFAULT_RTE_OsApplication_Safety_PIM_GROUP) Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy;

#define Safety_Guard_START_SEC_VAR_INIT_UNSPECIFIED
#include "Safety_Guard_MemMap.h"

TbAP_PAStateOut_t SafetyGuard_PAStateOut_t = {0};
TbAP_VCActuatorOut_t SafetyGuard_VCActuatorOut_t = {0};
LMD_Outputs_CVPAMFDData2_t SafetyGuard_CVPAMFDData2_t = {0};
IFOD_Outputs_CVPAMFDData_t SafetyGuard_CVPAMFDData_t = {0};
SvsToVCAN_t SafetyGuard_SvsToVCAN_t = {0};
/* Safe State Inputs */
static SafeStateOpDef readSafeStateOp_B_Sg = {0};

#define Safety_Guard_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Safety_Guard_MemMap.h"


/* Update safe state macros based on Error Mgr enum (ldef_ErrorMgr_enSafeStates) definition  */
#define SAFESTATE1 ldef_ErrorMgr_SafeState_safestate1
#define SAFESTATE2 ldef_ErrorMgr_SafeState_safestate2
//#define SAFESTATE3 ldef_ErrorMgr_SafeState_safestate3
#define SAFESTATE4 ldef_ErrorMgr_SafeState_safestate4
#define SAFESTATE5 ldef_ErrorMgr_SafeState_safestate5
/* #define	  SAFESTATE6	ldef_ErrorMgr_SafeState_safestate6 */ /* Not defined in ErrorMgr Module*/
#define SAFESTATE7 ldef_ErrorMgr_SafeState_safestate7
//#define SAFESTATE8 ldef_ErrorMgr_SafeState_safestate8
#define SAFESTATE9 ldef_ErrorMgr_SafeState_safestate9
#define SAFESTATE10 ldef_ErrorMgr_SafeState_safestate10
#define SAFESTATE11 ldef_ErrorMgr_SafeState_safestate11
#define SAFESTATE12 ldef_ErrorMgr_SafeState_safestate12
#define SAFESTATE13 ldef_ErrorMgr_SafeState_safestate13
/* #define SAFESTATE14 ldef_ErrorMgr_SafeState_safestate14 */ /* Not defined in ErrorMgr Module*/
/* #define SAFESTATE15 ldef_ErrorMgr_SafeState_safestate15 */ /* Not defined in ErrorMgr Module*/
#define SAFESTATE16 ldef_ErrorMgr_SafeState_safestate16
#define SAFESTATE17 ldef_ErrorMgr_SafeState_safestate17
/* #define	  SAFESTATE18	ldef_ErrorMgr_SafeState_safestate18 */ /* Not defined in ErrorMgr Module*/
/* #define	  SAFESTATE19	ldef_ErrorMgr_SafeState_safestate19 */ /* Not defined in ErrorMgr Module*/
/* #define	  SAFESTATE20	ldef_ErrorMgr_SafeState_safestate20 */ /* Not defined in ErrorMgr Module*/
/* #define	  SAFESTATE21	ldef_ErrorMgr_SafeState_safestate21 */ /* Not defined in ErrorMgr Module*/
/* #define	  SAFESTATE22	ldef_ErrorMgr_SafeState_safestate22 */ /* Not defined in ErrorMgr Module*/
#define SAFESTATE23 ldef_ErrorMgr_SafeState_safestate23
#define SAFESTATE24 ldef_ErrorMgr_SafeState_safestate24
/* #define	  SAFESTATE25	ldef_ErrorMgr_SafeState_safestate25 */ /* Not defined in ErrorMgr Module*/

#define FAILSAFE_ACTIVE 0U

#define Safety_Guard_START_SEC_CODE
#include "Safety_Guard_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static void SafeGuard_PAStateOutOut(void);
static void SafeGuard_VCActuatorOut(void);
static void SafeGuard_CVPAMFDData2(void);
static void SafeGuard_CVPAMFDData(void);
static void SafeGuard_SvsToVCANData(void);

//void UART_printf(const char *pcString, ...);
#define Safety_Guard_STOP_SEC_CODE
#include "Safety_Guard_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * CameraStatus_t: Integer in interval [0...4294967295]
 * LaneDetHealth_t: Integer in interval [0...4294967295]
 * LaneType_t: Integer in interval [0...4294967295]
 * NvM_RequestResultType: Integer in interval [0...255]
 * TeAP_e_PAMChimeRepnRate: Integer in interval [0...4294967295]
 * TeAP_e_PAMChimeTyp: Integer in interval [0...4294967295]
 * TeAP_e_PAMLedCtrlStatus: Integer in interval [0...4294967295]
 * TeAP_e_PAMPopUpReq: Integer in interval [0...4294967295]
 * TeAP_e_PAMVolume: Integer in interval [0...4294967295]
 * aSigConverter_E_DisplayView2_t: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * dtRef_const_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * real32_T: Real in interval [-FLT_MAX...FLT_MAX] with single precision
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * SafeStateActive_arr: Array with 16 element(s) of type uint8
 * SafeStateActive_arr: Array with 16 element(s) of type uint8
 *
 * Record Types:
 * =============
 * IFOD_Outputs_CVPAMFDData_t: Record with elements
 *   IeFOD_e_FODHealth of type uint32
 *   IeFOD_e_FODConfidence of type uint32
 * ILMD_Outputs_ADASFDLANES1_t: Record with elements
 *   IeLMD_e_FrameIndexLanes1 of type uint64
 *   IeLMD_e_CntrAdasFdLanes1 of type uint64
 *   IeLMD_e_Line1Confidence of type float32
 *   IeLMD_e_Line2Confidence of type float32
 *   IeLMD_e_Line3Confidence of type float32
 *   IeLMD_e_Line4Confidence of type float32
 *   IeLMD_m_Line1Offset of type float32
 *   IeLMD_m_Line2Offset of type float32
 *   IeLMD_m_Line3Offset of type float32
 *   IeLMD_m_Line4Offset of type float32
 *   IeLMD_rad_Line1Heading of type float32
 *   IeLMD_rad_Line2Heading of type float32
 *   IeLMD_rad_Line3Heading of type float32
 *   IeLMD_rad_Line4Heading of type float32
 *   IeLMD_m_Line1StartRange of type float32
 *   IeLMD_m_Line2StartRange of type float32
 *   IeLMD_m_Line3StartRange of type float32
 *   IeLMD_m_Line4StartRange of type float32
 *   IeLMD_m_Line1EndRange of type float32
 *   IeLMD_m_Line2EndRange of type float32
 *   IeLMD_m_Line3EndRange of type float32
 *   IeLMD_m_Line4EndRange of type float32
 *   IeLMD_e_Line1Curvature of type float32
 *   IeLMD_e_Line2Curvature of type float32
 *   IeLMD_e_Line3Curvature of type float32
 *   IeLMD_e_Line4Curvature of type float32
 *   IeLMD_e_Line1CurvatureRate of type float32
 *   IeLMD_e_Line2CurvatureRate of type float32
 *   IeLMD_e_Line3CurvatureRate of type float32
 *   IeLMD_e_Line4CurvatureRate of type float32
 *   IeLMD_e_Line1Type of type LaneType_t
 *   IeLMD_e_Line2Type of type LaneType_t
 *   IeLMD_e_Line3Type of type LaneType_t
 *   IeLMD_e_Line4Type of type LaneType_t
 *   IeLMD_e_LaneDetectionHealth of type LaneDetHealth_t
 *   IeLMD_e_CameraStatus of type CameraStatus_t
 *   IeLMD_e_CrcAdasFdLanes1 of type uint16
 *   IeLMD_e_MsgCntrAdasFdLanes1 of type uint8
 *   IeLMD_e_MacAdasFdLanes1 of type uint8
 *   IeLMD_e_ReservedForFunctionalSafety1 of type uint8
 *   Dummy1_1_b of type uint8
 *   Dummy2_1_b of type uint8
 *   Dummy3_1_b of type uint8
 * ILMD_Outputs_ADASFDLANES2_t: Record with elements
 *   IeLMD_e_FrameIndexLanes2 of type uint64
 *   IeLMD_e_CntrAdasFdLanes2 of type uint64
 *   IeLMD_e_LineSeg1Conf of type float32
 *   IeLMD_e_LineSeg2Conf of type float32
 *   IeLMD_e_LineSeg3Conf of type float32
 *   IeLMD_e_LineSeg4Conf of type float32
 *   IeLMD_e_LineSeg5Conf of type float32
 *   IeLMD_e_LineSeg6Conf of type float32
 *   IeLMD_e_LineSeg7Conf of type float32
 *   IeLMD_e_LineSeg8Conf of type float32
 *   IeLMD_m_LineSeg1X1 of type float32
 *   IeLMD_m_LineSeg2X1 of type float32
 *   IeLMD_m_LineSeg3X1 of type float32
 *   IeLMD_m_LineSeg4X1 of type float32
 *   IeLMD_m_LineSeg5X1 of type float32
 *   IeLMD_m_LineSeg6X1 of type float32
 *   IeLMD_m_LineSeg7X1 of type float32
 *   IeLMD_m_LineSeg8X1 of type float32
 *   IeLMD_m_LineSeg1X2 of type float32
 *   IeLMD_m_LineSeg2X2 of type float32
 *   IeLMD_m_LineSeg3X2 of type float32
 *   IeLMD_m_LineSeg4X2 of type float32
 *   IeLMD_m_LineSeg5X2 of type float32
 *   IeLMD_m_LineSeg6X2 of type float32
 *   IeLMD_m_LineSeg7X2 of type float32
 *   IeLMD_m_LineSeg8X2 of type float32
 *   IeLMD_m_LineSeg1Y1 of type float32
 *   IeLMD_m_LineSeg2Y1 of type float32
 *   IeLMD_m_LineSeg3Y1 of type float32
 *   IeLMD_m_LineSeg4Y1 of type float32
 *   IeLMD_m_LineSeg5Y1 of type float32
 *   IeLMD_m_LineSeg6Y1 of type float32
 *   IeLMD_m_LineSeg7Y1 of type float32
 *   IeLMD_m_LineSeg8Y1 of type float32
 *   IeLMD_m_LineSeg1Y2 of type float32
 *   IeLMD_m_LineSeg2Y2 of type float32
 *   IeLMD_m_LineSeg3Y2 of type float32
 *   IeLMD_m_LineSeg4Y2 of type float32
 *   IeLMD_m_LineSeg5Y2 of type float32
 *   IeLMD_m_LineSeg6Y2 of type float32
 *   IeLMD_m_LineSeg7Y2 of type float32
 *   IeLMD_m_LineSeg8Y2 of type float32
 *   IeLMD_e_CrcAdasFdLanes2 of type uint16
 *   IeLMD_e_LineSeg1Id of type uint8
 *   IeLMD_e_LineSeg2Id of type uint8
 *   IeLMD_e_LineSeg3Id of type uint8
 *   IeLMD_e_LineSeg4Id of type uint8
 *   IeLMD_e_LineSeg5Id of type uint8
 *   IeLMD_e_LineSeg6Id of type uint8
 *   IeLMD_e_LineSeg7Id of type uint8
 *   IeLMD_e_LineSeg8Id of type uint8
 *   IeLMD_e_MsgCntrAdasFdLanes2 of type uint8
 *   IeLMD_e_MacAdasFdLanes2 of type uint8
 *   IeLMD_e_ReservedForFunctionalSafety2 of type uint8
 *   Dummy1_2_b of type uint8
 *   Dummy2_2_b of type uint8
 *   Dummy3_2_b of type uint8
 * LMD_Outputs_CVPAMFDData2_t: Record with elements
 *   LMD_Outputs_ADASFDLANES1_s of type ILMD_Outputs_ADASFDLANES1_t
 *   LMD_Outputs_ADASFDLANES2_s of type ILMD_Outputs_ADASFDLANES2_t
 * SafeStateOpDef: Record with elements
 *   SafeStateActive of type SafeStateActive_arr
 * SafeStateOpDef: Record with elements
 *   SafeStateActive of type SafeStateActive_arr
 * SvsToVCAN_t: Record with elements
 *   IeSVS_b_SPMScrnReq of type boolean
 *   IeSVS_b_ImgDefeatReqSts of type boolean
 *   IeSVS_b_MoreCamsReqSts of type boolean
 *   IeSVS_b_AUXCamReqSts of type boolean
 *   IeSVS_e_DispView2 of type aSigConverter_E_DisplayView2_t
 * TbAP_PAStateOut_t: Record with elements
 *   IeAP_e_PAMChimeRepnRate of type TeAP_e_PAMChimeRepnRate
 *   IeAP_e_PAMVolSig of type TeAP_e_PAMVolume
 *   IeAP_e_FrntParkLEDSts of type TeAP_e_PAMLedCtrlStatus
 *   IeAP_e_PAMLedCtrl of type TeAP_e_PAMLedCtrlStatus
 *   IeAP_e_PAMChimeTyp of type TeAP_e_PAMChimeTyp
 *   IeAP_e_ParkSensePopUpReq of type TeAP_e_PAMPopUpReq
 *   IeAP_b_PAMRearBrkReq of type boolean
 *   IeAP_b_PAMRearCtrlSts of type boolean
 * TbAP_VCActuatorOut_t: Record with elements
 *   IeAP_nm_StrwTrqReq of type real32_T
 *   IeAP_a_DecelMax of type real32_T
 *   IeAP_a_DecelMin of type real32_T
 *   IeAP_a_JerkDecelMax of type real32_T
 *   IeAP_a_JerkDecelMin of type real32_T
 *   IeAP_a_AcclMin of type real32_T
 *   IeAP_a_AcclMax of type real32_T
 *   IeAP_da_JerkAcclMax of type real32_T
 *   IeAP_da_JerkAcclMin of type real32_T
 *   IeAP_cm_TrgtDist of type real32_T
 *   IeAP_kph_TrgtVehSpd of type real32_T
 *   IeAP_e_TurnIndicReq of type sint32
 *   IeAP_b_StandstillReq of type boolean
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint16 *Rte_Pim_SafeStat2_ResetReason_MirrorBlock(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint16 Rte_CData_SafeStat2_ResetReason_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define Safety_Guard_START_SEC_CODE
#include "Safety_Guard_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SafetyGuard_Main
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_SafeState2Reason_FaultEnum_u16(uint16 *data)
 *   Std_ReturnType Rte_Read_R_SafeState_B_SafeStateOp(SafeStateOpDef *data)
 *   Std_ReturnType Rte_Read_R_SafeState_QM_SafeStateOp(SafeStateOpDef *data)
 *   Std_ReturnType Rte_Read_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(IFOD_Outputs_CVPAMFDData_t *data)
 *   Std_ReturnType Rte_Read_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(LMD_Outputs_CVPAMFDData2_t *data)
 *   Std_ReturnType Rte_Read_RpFailsafeAction_FailSafe_State(uint8 *data)
 *   Std_ReturnType Rte_Read_RpPAStateOut_TbAP_PAStateOut_t(TbAP_PAStateOut_t *data)
 *   Std_ReturnType Rte_Read_RpSvsToVCAN_SvsToVCAN_t(SvsToVCAN_t *data)
 *   Std_ReturnType Rte_Read_RpVCActuatorOut_TbAP_VCActuatorOut_t(TbAP_VCActuatorOut_t *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(const IFOD_Outputs_CVPAMFDData_t *data)
 *   Std_ReturnType Rte_Write_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(const LMD_Outputs_CVPAMFDData2_t *data)
 *   Std_ReturnType Rte_Write_PpSafeGuardPAStateOut_TbAP_PAStateOut_t(const TbAP_PAStateOut_t *data)
 *   Std_ReturnType Rte_Write_PpSafeGuardSvsToVCAN_SvsToVCAN_t(const SvsToVCAN_t *data)
 *   Std_ReturnType Rte_Write_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t(const TbAP_VCActuatorOut_t *data)
 *   Std_ReturnType Rte_Write_PpSafeState2RSTReason_FaultEnum_u16(uint16 data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_SafetyGuard_SafeState_Mode_Mode(uint8 mode)
 *   Modes of Rte_ModeType_SafetyGuard_BSWM_SafeMode:
 *   - RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL
 *   - RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETYGUARD_SAFESTATE_2_RESET
 *   - RTE_TRANSITION_SafetyGuard_BSWM_SafeMode
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SafeStat2_ResetReason_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_AC3_SRBS_SafeStat2_ResetReason_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SafetyGuard_Main_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Safety_Guard_CODE) SafetyGuard_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SafetyGuard_Main
 *********************************************************************************************************************/
  /* DD-ID: {CDD6B470-6DB3-485b-AD89-0C0CAE026BDA}*/
  uint8 v_failsafe_state_u8 = 0U;
  static volatile boolean v_initData_u8 = FALSE;
  static uint8 SafetyGuard_Task_10ms_counter = 0u;
  NvM_RequestResultType ErrorStatus_u8 = E_NOT_OK;
  /* Read Failsafe state */
  (void)Rte_Read_RpFailsafeAction_FailSafe_State(&v_failsafe_state_u8);
  /* Check if failsafe state is ACTIVE */
  if (FAILSAFE_ACTIVE == v_failsafe_state_u8)
  {
      (void)Rte_Read_R_SafeState_B_SafeStateOp(&readSafeStateOp_B_Sg);
  }
  else
  {
      /* Disable Safe states in case of failsafe is INACTIVE */
      VStdLib_MemClr(&readSafeStateOp_B_Sg, sizeof(SafeStateOpDef));
  }
  if(FALSE == v_initData_u8)
  {
//	  UART_printf("\nSafeState block NVM  : %d\n",(uint32_t)(Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock));
//	  UART_printf("\nSafeState block COPY  : %d\n",(uint32_t)(Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy));
      Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock = Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy;
      (void)Rte_Write_PpSafeState2RSTReason_FaultEnum_u16(Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy);
      v_initData_u8 = TRUE;
  }
  else
  {
      /**/
  }
  /* Update IPC structure elements based on Safestates */
  SafeGuard_PAStateOutOut();
  SafeGuard_VCActuatorOut();

  if ((SafetyGuard_Task_10ms_counter % 4u) == 0u)
  {
    SafeGuard_CVPAMFDData2();
    SafeGuard_CVPAMFDData();
    SafeGuard_SvsToVCANData();
    SafetyGuard_Task_10ms_counter = 0u;
  }
  else
  { /* Do nothing */
  }

  SafetyGuard_Task_10ms_counter++;

#ifdef SAFESTATE2
  /* Initiate system reset sequence, when SafeState_2 is active */
  if (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE2] == TRUE)
  {
	  /* Invoke SafeState2 Reset to PMIC */
	  (void)Rte_Switch_SafetyGuard_SafeState_Mode_Mode(RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETYGUARD_SAFESTATE_2_RESET);
  }
  else
  {
      (void)Rte_Switch_SafetyGuard_SafeState_Mode_Mode(RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL);
  }
#endif


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Safety_Guard_STOP_SEC_CODE
#include "Safety_Guard_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define Safety_Guard_START_SEC_CODE
#include "Safety_Guard_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static void SafeGuard_PAStateOutOut(void)
{
  /* DD-ID: {6554DD3C-E529-4434-B020-77B488126670}*/
  (void)Rte_Read_RpPAStateOut_TbAP_PAStateOut_t(&SafetyGuard_PAStateOut_t);
  if (
#ifdef SAFESTATE16
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE16] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE1
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE1] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE2
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE2] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE3
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE3] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE7
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE7] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
  )
  {
    SafetyGuard_PAStateOut_t.IeAP_b_PAMRearBrkReq = (boolean)0;
  }
  else
  { /* Do nothing */
  }

  (void)Rte_Write_PpSafeGuardPAStateOut_TbAP_PAStateOut_t(&SafetyGuard_PAStateOut_t);
}

static void SafeGuard_VCActuatorOut(void)
{
  /* DD-ID: {ABE77973-7A83-49e4-90D0-0A761F9B1952}*/
  (void)Rte_Read_RpVCActuatorOut_TbAP_VCActuatorOut_t(&SafetyGuard_VCActuatorOut_t);
  if (
#ifdef SAFESTATE17
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE17] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE1
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE1] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE2
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE2] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE3
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE3] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE23
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE23] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
  )
  {
    SafetyGuard_VCActuatorOut_t.IeAP_kph_TrgtVehSpd = (float32)0;
    SafetyGuard_VCActuatorOut_t.IeAP_cm_TrgtDist = (float32)0;
    SafetyGuard_VCActuatorOut_t.IeAP_b_StandstillReq = (boolean)1;
    SafetyGuard_VCActuatorOut_t.IeAP_nm_StrwTrqReq = (float32)0;
  }
  else
  { /* Do nothing */
  }

  (void)Rte_Write_PpSafeGuardVCActuatorOut_TbAP_VCActuatorOut_t(&SafetyGuard_VCActuatorOut_t);
}
static void SafeGuard_CVPAMFDData2(void)
{
  /* DD-ID:{38F5EB67-8608-4039-A8D2-306C6B54506B}*/
  (void)Rte_Read_RpCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(&SafetyGuard_CVPAMFDData2_t);

  if (
#ifdef SAFESTATE22
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE22] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE21
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE21] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE1
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE1] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE2
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE2] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE3
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE3] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE7
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE7] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE23
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE23] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
  )
  {
#ifdef SAFESTATE22
    if (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE22] == TRUE)
    {
      SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_LaneDetectionHealth = (uint32)1;
    }
    else
#endif
    {
      SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_LaneDetectionHealth = (uint32)0;
    }
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line1Confidence = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line2Confidence = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line3Confidence = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line4Confidence = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line1Offset = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line2Offset = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line3Offset = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line4Offset = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_rad_Line1Heading = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_rad_Line2Heading = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_rad_Line3Heading = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_rad_Line4Heading = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line1StartRange = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line2StartRange = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line3StartRange = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line4StartRange = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line1EndRange = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line2EndRange = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line3EndRange = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_m_Line4EndRange = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line1Curvature = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line2Curvature = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line3Curvature = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line4Curvature = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line1CurvatureRate = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line2CurvatureRate = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line3CurvatureRate = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line4CurvatureRate = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line1Type = (uint32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line2Type = (uint32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line3Type = (uint32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES1_s.IeLMD_e_Line4Type = (uint32)0;

    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg1Conf = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg2Conf = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg3Conf = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg4Conf = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg5Conf = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg6Conf = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg7Conf = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg8Conf = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg1X1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg2X1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg3X1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg4X1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg5X1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg6X1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg7X1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg8X1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg1X2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg2X2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg3X2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg4X2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg5X2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg6X2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg7X2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg8X2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg1Y1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg2Y1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg3Y1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg4Y1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg5Y1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg6Y1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg7Y1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg8Y1 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg1Y2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg2Y2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg3Y2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg4Y2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg5Y2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg6Y2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg7Y2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_m_LineSeg8Y2 = (float32)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg1Id = (uint8)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg2Id = (uint8)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg3Id = (uint8)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg4Id = (uint8)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg5Id = (uint8)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg6Id = (uint8)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg7Id = (uint8)0;
    SafetyGuard_CVPAMFDData2_t.LMD_Outputs_ADASFDLANES2_s.IeLMD_e_LineSeg8Id = (uint8)0;
  }
  else
  { /* Do nothing */
  }

  (void)Rte_Write_PpSafeGuardCVPAMFDData2_LMD_Outputs_CVPAMFDData2_t(&SafetyGuard_CVPAMFDData2_t);
}
static void SafeGuard_CVPAMFDData(void)
{
  /* DD-ID: {68917B63-05B8-4e9d-A1CD-EAB866D7BCCF}*/
  (void)Rte_Read_RpCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(&SafetyGuard_CVPAMFDData_t);
  if (
#ifdef SAFESTATE19
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE19] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE20
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE20] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE1
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE1] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE2
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE2] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE3
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE3] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE7
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE7] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
  )
  {
    SafetyGuard_CVPAMFDData_t.IeFOD_e_FODConfidence = (uint32)0;
#ifdef SAFESTATE20
    if (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE20] == TRUE)
    {
      SafetyGuard_CVPAMFDData_t.IeFOD_e_FODHealth = (uint32)1;
    }
    else
#endif
    {
      SafetyGuard_CVPAMFDData_t.IeFOD_e_FODHealth = (uint32)0;
    }
  }
  else
  { /* Do nothing */
  }

  if (
#ifdef SAFESTATE24
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE24] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
  )
  {
    SafetyGuard_CVPAMFDData_t.IeFOD_e_FODHealth = (uint32)0;
  }
  else
  { /* Do nothing */
  }

  (void)Rte_Write_PpSafeGuardCVPAMFDData_IFOD_Outputs_CVPAMFDData_t(&SafetyGuard_CVPAMFDData_t);
}


static void SafeGuard_SvsToVCANData(void)
{
  /* DD-ID: {1893AEB8-E517-45ad-9DCE-39BD03B8C812}*/

  (void)Rte_Read_RpSvsToVCAN_SvsToVCAN_t(&SafetyGuard_SvsToVCAN_t);

  if (
#ifdef SAFESTATE7
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE7] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE8
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE8] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE1
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE1] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE2
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE2] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
      ||
#ifdef SAFESTATE3
      (readSafeStateOp_B_Sg.SafeStateActive[SAFESTATE3] == TRUE)
#else
      (FALSE == TRUE) /* Always FALSE output */
#endif
  )
  {
    SafetyGuard_SvsToVCAN_t.IeSVS_e_DispView2 = DisplayView2_ViewOFF;
  }
  else
  { /* Do nothing */
  }

  (void)Rte_Write_PpSafeGuardSvsToVCAN_SvsToVCAN_t(&SafetyGuard_SvsToVCAN_t);


}

void Update_SafetyGuard_MirrorBlock(boolean SafetyGuard_Erase_block)
{
  /* DD-ID: {A8920491-0507-44e0-B0B8-BDFEAF16899C}*/
  if(TRUE == SafetyGuard_Erase_block)
  {
    Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock = Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy;
  }
  else
  {
    Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy = Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock;
  }
}

void SafetyGuard_NVM_Write_ResetReason(void)
{
  /* DD-ID: {B58EACD4-C814-4fb8-8EAB-E29A441CED44}*/
	/* Read ReasetReason from ErrorMgr */
	(void)Rte_Read_R_SafeState2Reason_FaultEnum_u16(&Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock);
	Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy = Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock;
	/* Request NVM to store Reset Reason */
	(void)Rte_Call_NvMService_AC3_SRBS_SafeStat2_ResetReason_WriteBlock(&Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock_copy);
	//  UART_printf("\nIn Safety_Gaurd -> SafeState called for  : %d\n",(uint32_t)(Rte_Safety_Guard_SafeStat2_ResetReason_MirrorBlock));
}

sint8_t SafetyGuard_Wait_for_NVM_Write_Status(void)
{
  /* DD-ID: {C4698881-671F-43f4-A4DC-C1C3EB45B116}*/
	NvM_RequestResultType ErrorStatus_u8 = NVM_REQ_NOT_OK;
	sint8_t ret = NVM_WR_PENDING;
	/* Read Block status from NVM */
	(void)Rte_Call_NvMService_AC3_SRBS_SafeStat2_ResetReason_GetErrorStatus(&ErrorStatus_u8);
	if(NVM_REQ_OK == ErrorStatus_u8)
	{
		ret = NVM_WR_DONE;
	}
	else if(NVM_REQ_PENDING != ErrorStatus_u8)
	{
		ret = NVM_WR_FAILED;
	}
	else{
		ret = NVM_WR_PENDING;
	}

	return ret;
}

#define Safety_Guard_STOP_SEC_CODE
#include "Safety_Guard_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
