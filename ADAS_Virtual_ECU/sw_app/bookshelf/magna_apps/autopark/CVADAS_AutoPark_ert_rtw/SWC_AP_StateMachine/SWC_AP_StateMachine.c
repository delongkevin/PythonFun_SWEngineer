/*
 * File: SWC_AP_StateMachine.c
 *
 * Code generated for Simulink model 'SWC_AP_StateMachine'.
 *
 * Model version                  : 1.2855
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:49:36 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "SWC_AP_StateMachine.h"
#include "SWC_AP_StateMachine_private.h"
#include "uMultiWordNe.h"

/* Named constants for Chart: '<S34>/Chart1' */
#define SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define SWC_AP_StateMachine_IN_Not_Pressed_OFF ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_Not_Pressed_ON ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_Pressed ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_SwitchStuck ((uint8_T)4U)

/* Named constants for Chart: '<S5>/AUTOPARK_StateMachine' */
#define SWC_AP_StateMachine_IN_ACTIVE_AUTOPARK ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_Abort   ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_Abort_HMI_1 ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_Abort_HMI_2 ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_Abort_HMI_3 ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_Active_FullAutoPark ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_Active_SemiAutoPark ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_Active_SemiAutoParkExit ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_AutoParkScanBackward ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_AutoParkScanFault ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_AutoParkScanNoGear ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_AutoParkScanNoReverse ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_BSM_Handshake ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_BUTTON_PRESS_TAKECONTROL ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_COMPLETE_HMI_FRONT_REAR ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_COMPLETE_RELEASE ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_CRUISE_CONTROL_ENGAGED_TAKECONTROL ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_Complete ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_Complete_FullAutoPark ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_Complete_SemiAutoPark ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_DISCLAIMER ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_DIsableHMI ((uint8_T)5U)
#define SWC_AP_StateMachine_IN_DOOR_OPEN_TAKECONTROL ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_DRIVER_OVERRIDE_TAKECONTROL ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_Default ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_EPS_Handshake_e ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_ESC_ACTIVE_TAKECONTROL ((uint8_T)5U)
#define SWC_AP_StateMachine_IN_Engaged_Full ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_FAULT   ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_FRONT_WIPE_TAKECONTROL ((uint8_T)6U)
#define SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_FaultBlinkingLED ((uint8_T)6U)
#define SWC_AP_StateMachine_IN_FaultLEDOFF ((uint8_T)7U)
#define SWC_AP_StateMachine_IN_Fault_Init ((uint8_T)8U)
#define SWC_AP_StateMachine_IN_FullAutoParkSCANNING ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_HandshakeStart ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_Handshake_FullAutoPark ((uint8_T)5U)
#define SWC_AP_StateMachine_IN_Handshake_FullAutoPark_c ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_Handshake_SemiAutoPark ((uint8_T)6U)
#define SWC_AP_StateMachine_IN_Handshake_SemiAutoPark_c ((uint8_T)5U)
#define SWC_AP_StateMachine_IN_IDLE    ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_INIT    ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_Idle    ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_LIFTGATE_OPEN_TAKECONTROL ((uint8_T)7U)
#define SWC_AP_StateMachine_IN_LO4_ACTIVE_TAKECONTROL ((uint8_T)8U)
#define SWC_AP_StateMachine_IN_MANUAL_PARK_TAKECONTROL ((uint8_T)9U)
#define SWC_AP_StateMachine_IN_MANUAL_PARK_TAKECONTROL_Default ((uint8_T)10U)
#define SWC_AP_StateMachine_IN_MOVE_BACKWARD ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_MOVE_FORWARD ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_MutlipleMoves ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_OFF     ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_ON      ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_PARALLEL_EXIT_REMOVE_HANDS_LEFT ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_PARALLEL_EXIT_REMOVE_HANDS_RIGHT ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_PARALLEL_EXIT_SELECT ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_PARALLEL_EXIT_STOP ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_PAUSED_OBJECT_IN_PATH ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON_BrkPedlPressed ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_PERP_SELECT_LEFT ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_FORWARD ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_REVERSE ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_o ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT_FORWARD ((uint8_T)5U)
#define SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT_REVERSE ((uint8_T)6U)
#define SWC_AP_StateMachine_IN_ParkIN_RelVehControlDelay ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_ParkIn  ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_Park_Exit ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_REAR_WIPE_TAKECONTROL ((uint8_T)11U)
#define SWC_AP_StateMachine_IN_REMOVE_HANDS_FEET ((uint8_T)5U)
#define SWC_AP_StateMachine_IN_ReleaseControl ((uint8_T)12U)
#define SWC_AP_StateMachine_IN_ReverseGearShitReq ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD ((uint8_T)5U)
#define SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_k ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_kx ((uint8_T)7U)
#define SWC_AP_StateMachine_IN_SEEK_BCKGND ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_SEMI_PARALLEL_REMOVE_HANDS_LEFT ((uint8_T)8U)
#define SWC_AP_StateMachine_IN_SEMI_PARALLEL_REMOVE_HANDS_RIGHT ((uint8_T)9U)
#define SWC_AP_StateMachine_IN_SEMI_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_GUIDANCE ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_o ((uint8_T)1U)
#define SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_on ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_SHIFT_TO_REVERSE ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE ((uint8_T)6U)
#define SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE_d ((uint8_T)10U)
#define SWC_AP_StateMachine_IN_SPACE_FOUND_SPEED_TOO_HIGH ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_SPACE_FOUND_STOP ((uint8_T)7U)
#define SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_STANDSTILL ((uint8_T)8U)
#define SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_STANDSTILL_n ((uint8_T)12U)
#define SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l ((uint8_T)3U)
#define SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la ((uint8_T)11U)
#define SWC_AP_StateMachine_IN_SPEED_TOO_HIGH_TAKECONTROL ((uint8_T)13U)
#define SWC_AP_StateMachine_IN_STANDBY ((uint8_T)4U)
#define SWC_AP_StateMachine_IN_STOP_FRONT ((uint8_T)5U)
#define SWC_AP_StateMachine_IN_STOP_REAR ((uint8_T)6U)
#define SWC_AP_StateMachine_IN_Scanning_FullAutoPark ((uint8_T)7U)
#define SWC_AP_StateMachine_IN_Scanning_SemiAutoPark ((uint8_T)8U)
#define SWC_AP_StateMachine_IN_SemiAutoParkSCANNING ((uint8_T)6U)
#define SWC_AP_StateMachine_IN_Standstill ((uint8_T)14U)
#define SWC_AP_StateMachine_IN_TRAILER_CONNECTED_TAKECONTROL ((uint8_T)15U)
#define SWC_AP_StateMachine_IN_WAIT_FOR_STEER_FRONT ((uint8_T)7U)
#define SWC_AP_StateMachine_IN_WAIT_FOR_STEER_REAR ((uint8_T)2U)
#define SWC_AP_StateMachine_IN_WAIT_FOR_STEER_REAR_o ((uint8_T)8U)
#define SWC_AP_StateMachine_IN_WHEEL_TOUCHED_TAKECONTROL ((uint8_T)16U)
#define SWC_AP_StateMachine_IN_WaitTimer ((uint8_T)17U)
#define SWC_AP_StateMachine_IN_WaitTimer1 ((uint8_T)18U)

/* Exported data definition */

/* Definition for custom storage class: Default */
boolean_T MeAP_b_ACCEngg;              /* '<S15>/Logical Operator7' */
boolean_T MeAP_b_APActConAvl;          /* '<S28>/Logical Operator10' */
boolean_T MeAP_b_AbortCon1;            /* '<S14>/Logical Operator3' */
boolean_T MeAP_b_AbortCon2;            /* '<S14>/Logical Operator5' */
boolean_T MeAP_b_AbortCon3;            /* '<S14>/Logical Operator7' */
boolean_T MeAP_b_BSMHandshakeFailed;   /* '<S15>/Logical Operator18' */
boolean_T MeAP_b_BrkPedlOverride;      /* '<S31>/Logical Operator3' */
boolean_T MeAP_b_BtnPsd;               /* '<S15>/Switch1' */
boolean_T MeAP_b_DoorOpen;             /* '<S15>/Switch' */
boolean_T MeAP_b_DriverOverride;       /* '<S31>/Logical Operator5' */
boolean_T MeAP_b_EPBOverride;          /* '<S31>/Relational Operator4' */
boolean_T MeAP_b_EPBStsFaulted;        /* '<S15>/Logical Operator31' */
boolean_T MeAP_b_EPSHandshakeFailed;   /* '<S15>/Logical Operator21' */
boolean_T MeAP_b_ESCActive;            /* '<S15>/Logical Operator39' */
boolean_T MeAP_b_ETMHandshakeFailed;   /* '<S15>/Logical Operator26' */
boolean_T MeAP_b_FrntSnsrBlk;          /* '<S15>/Relational Operator12' */
boolean_T MeAP_b_GasPedlOverride;      /* '<S31>/Logical Operator1' */
boolean_T MeAP_b_GearShiftOverride;    /* '<S65>/Logical Operator8' */
boolean_T MeAP_b_GearShiftReqWaitTimeout;/* '<S5>/AUTOPARK_StateMachine' */
boolean_T MeAP_b_HandsOn;              /* '<S15>/Logical Operator9' */
boolean_T MeAP_b_InitBrkPedlPressed;   /* '<S5>/AUTOPARK_StateMachine' */
boolean_T MeAP_b_LifeGateOpen;         /* '<S15>/Logical Operator1' */
boolean_T MeAP_b_Lo4DriveTrain;        /* '<S15>/Relational Operator9' */
boolean_T MeAP_b_ManualParkReq;        /* '<S15>/Logical Operator12' */
boolean_T MeAP_b_MnvSpdExceed;         /* '<S15>/Logical Operator3' */
boolean_T MeAP_b_ObjInPathTimeout;     /* '<S15>/Logical Operator29' */
boolean_T MeAP_b_PausedPressBtnTimeout;/* '<S15>/Logical Operator30' */
boolean_T MeAP_b_PreEPSInterfaceAbort1;/* '<S5>/AUTOPARK_StateMachine' */
boolean_T MeAP_b_PreEPSInterfaceAbort2;/* '<S5>/AUTOPARK_StateMachine' */
boolean_T MeAP_b_RearSnsrBlk;          /* '<S15>/Relational Operator13' */
boolean_T MeAP_b_SeekSpdExceed;        /* '<S15>/Logical Operator33' */
boolean_T MeAP_b_TCMFailed;            /* '<S15>/Logical Operator23' */
boolean_T MeAP_b_TrlrConn;             /* '<S15>/Logical Operator6' */
boolean_T MeAP_b_VehCndSts;            /* '<S29>/Logical Operator8' */
uint32_T MeAP_cnt_StateDebugVar;       /* '<S5>/AUTOPARK_StateMachine' */
uint32_T MeAP_cnt_TransDebugVar;       /* '<S5>/AUTOPARK_StateMachine' */
uint16_T MeAP_s_GearShiftReqWaitCnt;   /* '<S5>/AUTOPARK_StateMachine' */
MdlrefDW_SWC_AP_StateMachine_T SWC_AP_StateMachine_MdlrefDW;

/* Block signals (default storage) */
B_SWC_AP_StateMachine_c_T SWC_AP_StateMachine_B;

/* Block states (default storage) */
DW_SWC_AP_StateMachine_f_T SWC_AP_StateMachine_DW;

/* Forward declaration for local functions */
static void SWC_AP_StateMachine_enter_atomic_OFF(TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_IeAP_b_StandstillReq,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq);
static void SWC_AP_StateMachine_enter_atomic_INIT(TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_IeAP_b_StandstillReq,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq);
static void SWC_AP_StateMachine_enter_internal_INIT(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
static void SWC_AP_StateMachine_enter_atomic_STANDBY(TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_IeAP_b_StandstillReq,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_FAULT(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPADisable, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_IeAP_b_StandstillReq,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_exit_internal_Scanning_FullAutoPark(void);
static void SWC_AP_StateMachine_exit_internal_Scanning_SemiAutoPark(void);
static void SWC_AP_StateMachine_exit_internal_ParkIn(void);
static void SWC_AP_StateMachine_exit_internal_Park_Exit(void);
static void SWC_AP_StateMachine_exit_internal_Abort(void);
static void SWC_AP_StateMachine_exit_internal_ON(void);
static void SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_gh3(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur);
static void SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_gh(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_Scanning_SemiAutoPark(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_g(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur);
static void SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_Scanning_FullAutoPark(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_ParkIn(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_ParKMnvrActv
  *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_SemiAutoParkSCANNING(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP_g(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_FullAutoParkSCANNING(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_Park_Exit(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_ParKMnvrActv
  *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_IDLE(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam,
  const uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat
  *rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_PAUSED_PRESS_BUTTON(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, TeAP_e_PAMVolSig *
  rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_FULL_AUTO_ACTIVE_FRONT_REAR(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM,
  boolean_T *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_PAUSED_OBJECT_IN_PATH(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM,
  boolean_T *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_PAUSED_PRESS_BUTTON(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM,
  boolean_T *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_enter_internal_REMOVE_HANDS_FEET(const uint16_T *
  rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_Active_FullAutoPark(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM,
  boolean_T *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_Handshake_FullAutoPark(const TbVBIA_VehState_AP *
  rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat
  *rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_PERP_SELECT_LEFT_l(const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_PERP_SELECT_LEFT_FORWARD(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_PERP_SELECT_RIGHT_d(const TeAutoPark_e_ParkStyle
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void
  SWC_AP_StateMachine_enter_internal_SEMI_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH(
  const TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_py(const uint16_T *
  rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_SEARCHING_MOVE_FORWARD_l(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_SPACE_FOUND_SELECT_SPACE_h(const
  ParkingSlotType_t *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const
  SlotSide_t *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_Default_g(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_pys(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_SPACE_FOUND_SPEED_TOO_HIGH_k(
  const TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_SPACE_FOUND_STOP_k(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_SPACE_FOUND_STOP_STANDSTILL_i(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_Scanning_SemiAutoPark(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_MOVE_BACKWARD(const boolean_T *rtu_MeAP_b_PosMet,
  const boolean_T *rtu_MeAP_b_SteerActionReq, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const boolean_T *
  rtu_MeAP_b_ObjPrestFC, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_MutlipleMoves(const boolean_T *rtu_MeAP_b_PosMet,
  const boolean_T *rtu_MeAP_b_SteerActionReq, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const boolean_T *
  rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_DISCLAIMER(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_DISCLAIMER(const
  ParkingSlotType_t *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat
  *rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_PERP_SELECT_LEFT(const TeAutoPark_e_ParkStyle
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_PERP_SELECT_RIGHT(const TeAutoPark_e_ParkStyle
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void
  SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_SEARCHING_MOVE_FORWARD(const TbVBIA_VehState_AP *
  rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_SPACE_FOUND_SELECT_SPACE(const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_p(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_SPACE_FOUND_SPEED_TOO_HIGH(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_Default(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_SPACE_FOUND_STOP(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_SPACE_FOUND_STOP_STANDSTILL(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_ParkIn(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const TeAP_e_UsrPPPAManeuverSel
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const boolean_T
  *rtu_MeAP_b_PosMet, const boolean_T *rtu_MeAP_b_SteerActionReq, const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TbNVM_ProxyCalibParam
  *rtu_MbNVM_ProxyParam, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd, const
  boolean_T *rtu_MeAP_b_ObjInPath, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_InterfaceBSM *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv
  *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_inner_default_FULL_AUTO_ACTIVE_FRONT(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_enter_internal_PAUSED_PRESS_BUTTON_b(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, TeAP_e_PAMVolSig *
  rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR_k(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_FULL_AUTO_ACTIVE_FRONT_REAR_a(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_PAUSED_OBJECT_IN_PATH_i(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_enter_internal_REMOVE_HANDS_FEET_b(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_Active_FullAutoPark_j(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_FullAutoParkSCANNING(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeHMI_e_UsrParkOutSide *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_Handshake_FullAutoPark_i(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat
  *rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_PARALLEL_EXIT_REMOVE_HANDS_LEFT(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_SemiAutoParkSCANNING(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeHMI_e_UsrParkOutSide *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_MOVE_BACKWARD_e(const boolean_T
  *rtu_MeAP_b_PosMet, const boolean_T *rtu_MeAP_b_SteerActionReq, const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM);
static void SWC_AP_StateMachine_MutlipleMoves_k(const boolean_T
  *rtu_MeAP_b_PosMet, const boolean_T *rtu_MeAP_b_SteerActionReq, const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_enter_internal_DOOR_OPEN_TAKECONTROL(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp);
static void SWC_AP_StateMachine_enter_internal_LIFTGATE_OPEN_TAKECONTROL(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp);
static void SWC_AP_StateMachine_enter_internal_Abort_HMI_3(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp);
static void SWC_AP_StateMachine_enter_internal_Abort(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_StandstillReq, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq);
static void SWC_AP_StateMachine_ACTIVE_AUTOPARK(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const TeHMI_e_UsrParkOutSide
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const TeAP_e_UsrPPPAManeuverSel
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const boolean_T
  *rtu_MeAP_b_PosMet, const boolean_T *rtu_MeAP_b_SteerActionReq, const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TbNVM_ProxyCalibParam
  *rtu_MbNVM_ProxyParam, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd, const
  boolean_T *rtu_MeAP_b_ObjInPath, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_InterfaceBSM *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv
  *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_PAMLedCtrlStatus *rty_IeAP_e_SPMLedSts, boolean_T
  *rty_IeAP_b_SPMFailSts, boolean_T *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *
  rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_IeAP_b_StandstillReq, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_enter_internal_Standstill(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_BUTTON_PRESS_TAKECONTROL(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_CRUISE_CONTROL_ENGAGED_TAKECONTROL(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_DOOR_OPEN_TAKECONTROL(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_ESC_ACTIVE_TAKECONTROL(const TbVBIA_VehState_AP *
  rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_FRONT_WIPE_TAKECONTROL(const TbVBIA_VehState_AP *
  rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_LIFTGATE_OPEN_TAKECONTROL(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_Abort_HMI_3(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_Abort(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_IeAP_b_StandstillReq,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill);
static void SWC_AP_StateMachine_ON(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const TeHMI_e_UsrParkOutSide
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const TeAP_e_UsrPPPAManeuverSel
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const boolean_T
  *rtu_MbDiag_PlantModeOn, const boolean_T *rtu_MeAP_b_PosMet, const boolean_T
  *rtu_MeAP_b_SteerActionReq, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam,
  const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd, const boolean_T
  *rtu_MeAP_b_ObjInPath, const boolean_T *rtu_IbFID_PPPA_MeAP_b_PPPADisable,
  const real32_T *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd, const real32_T *
  rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_InterfaceBSM *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv
  *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_PAMLedCtrlStatus *rty_IeAP_e_SPMLedSts, boolean_T
  *rty_IeAP_b_SPMFailSts, boolean_T *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *
  rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_IeAP_b_StandstillReq, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill);

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_atomic_OFF(TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_IeAP_b_StandstillReq,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq)
{
  MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Off;
  MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
  MeAP_cnt_StateDebugVar = 1U;
  *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
  *rty_IeAP_b_SPMFailSts = false;
  *rty_IeAP_b_SPMFaultSts = false;
  *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
  *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
  *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
  SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts = TeAP_e_SPMLatCtrlReqSts_Idle;
  *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
  *rty_IeAP_b_VehMnvrDirSPM = false;
  *rty_IeAP_b_StandstillReq = false;
  *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_atomic_INIT(TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_IeAP_b_StandstillReq,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq)
{
  MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Initialize;
  MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
  MeAP_cnt_StateDebugVar = 2U;
  *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
  *rty_IeAP_b_SPMFailSts = false;
  *rty_IeAP_b_SPMFaultSts = false;
  *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
  *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
  *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
  SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts = TeAP_e_SPMLatCtrlReqSts_Idle;
  *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
  *rty_IeAP_b_VehMnvrDirSPM = false;
  *rty_IeAP_b_StandstillReq = false;
  *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_INIT(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_WaitEngineCnt = 0U;
  SWC_AP_StateMachine_DW.MeAP_b_WaitEngineTimeout = false;
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_e_EngineSts ==
      TeVBII_e_EngineSts_Engine_On) {
    if (!SWC_AP_StateMachine_DW.MeAP_b_WaitEngineTimeout) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_WaitEngineCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_WaitEngineCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_WaitEngineCnt > KeAP_s_WaitEngineOnThd)
      {
        SWC_AP_StateMachine_DW.MeAP_b_WaitEngineTimeout = true;
        MeAP_cnt_TransDebugVar = 5U;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_WaitEngineTimeout = false;
        MeAP_cnt_TransDebugVar = 4U;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_WaitEngineTimeout = true;
      MeAP_cnt_TransDebugVar = 7U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_cnt_WaitEngineCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_CamHandshakeTimeout = false;
    MeAP_cnt_TransDebugVar = 2U;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_atomic_STANDBY(TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_IeAP_b_StandstillReq,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Standby;
  MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
  MeAP_cnt_StateDebugVar = 3U;
  *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
  *rty_IeAP_b_SPMFailSts = false;
  *rty_IeAP_b_SPMFaultSts = false;
  *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
  *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
  *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
  SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts = TeAP_e_SPMLatCtrlReqSts_Idle;
  *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
  *rty_IeAP_b_VehMnvrDirSPM = false;

  /* false = Backward, true= Forward  */
  *rty_IeAP_b_StandstillReq = false;
  *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
  MeAP_b_PreEPSInterfaceAbort1 = false;
  MeAP_b_PreEPSInterfaceAbort2 = false;
  SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
  SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
  SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
  SWC_AP_StateMachine_DW.MeAP_b_VehicleParked = false;
  SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete = false;
  SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle = false;
  SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;

  /* Chime reset */
  *rty_MeAP_b_ChimeActvReqLHFSVM = false;
  *rty_MeAP_b_ChimeActvReqRHFSVM = false;
  *rty_MeAP_b_ChimeActvReqLHRSVM = false;
  *rty_MeAP_b_ChimeActvReqRHRSVM = false;
  *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
  *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
  *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_FAULT(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPADisable, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_IeAP_b_StandstillReq,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Fault;

  /* Outputs for Atomic SubSystem: '<S3>/AP_Statemachine' */
  /* Chart: '<S5>/AUTOPARK_StateMachine' */
  *rty_IeAP_b_SPMFaultSts = true;
  *rty_IeAP_b_SPMFailSts = true;
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_e_CmdIgnSts != TeVBII_e_CmdIgnSts_RUN)
  {
    SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine =
      SWC_AP_StateMachine_IN_OFF;
    SWC_AP_StateMachine_enter_atomic_OFF(rty_IeAP_e_InterfaceBSM,
      rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
      rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
      rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
      rty_IeAP_e_GearShiftReq);
  } else if ((rtu_IbVBII_VehState_LowSpd->IeVBII_e_EngineSts !=
              TeVBII_e_EngineSts_Engine_On) &&
             (rtu_IbVBII_VehState_LowSpd->IeVBII_e_EssEngState ==
              TeVBII_e_EssEngState_SNA)) {
    SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine =
      SWC_AP_StateMachine_IN_INIT;
    SWC_AP_StateMachine_enter_atomic_INIT(rty_IeAP_e_InterfaceBSM,
      rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
      rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
      rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
      rty_IeAP_e_GearShiftReq);
    SWC_AP_StateMachine_enter_internal_INIT(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
  } else if (!*rtu_IbFID_PPPA_MeAP_b_PPPADisable) {
    SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine = SWC_AP_StateMachine_IN_ON;
    SWC_AP_StateMachine_DW.is_ON = SWC_AP_StateMachine_IN_STANDBY;
    SWC_AP_StateMachine_enter_atomic_STANDBY(rty_IeAP_e_InterfaceBSM,
      rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
      rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
      rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
      rty_IeAP_e_GearShiftReq, rty_MeAP_e_PAMVolSigSVM,
      rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
      rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
      rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
    SWC_AP_StateMachine_DW.is_STANDBY = SWC_AP_StateMachine_IN_Idle;
    SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
    MeAP_cnt_StateDebugVar = 97U;
  } else {
    switch (SWC_AP_StateMachine_DW.is_FAULT) {
     case SWC_AP_StateMachine_IN_AutoParkScanBackward:
      if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed || (*rty_IeAP_e_SPMLedSts ==
           TeAP_e_PAMLedCtrlStatus_BlinkingLight)) {
        SWC_AP_StateMachine_DW.is_FAULT =
          SWC_AP_StateMachine_IN_FaultBlinkingLED;
        *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_BlinkingLight;
        MeAP_cnt_StateDebugVar = 615U;
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt >
                 *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur) {
        SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_DIsableHMI;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        MeAP_cnt_StateDebugVar = 614U;
        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = 0U;
      } else {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = (uint16_T)tmp;
      }
      break;

     case SWC_AP_StateMachine_IN_AutoParkScanFault:
      if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed || (*rty_IeAP_e_SPMLedSts ==
           TeAP_e_PAMLedCtrlStatus_BlinkingLight)) {
        SWC_AP_StateMachine_DW.is_FAULT =
          SWC_AP_StateMachine_IN_FaultBlinkingLED;
        *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_BlinkingLight;
        MeAP_cnt_StateDebugVar = 615U;
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt >
                 *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur) {
        SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_DIsableHMI;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        MeAP_cnt_StateDebugVar = 614U;
        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = 0U;
      } else {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = (uint16_T)tmp;
      }
      break;

     case SWC_AP_StateMachine_IN_AutoParkScanNoGear:
      if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed || (*rty_IeAP_e_SPMLedSts ==
           TeAP_e_PAMLedCtrlStatus_BlinkingLight)) {
        SWC_AP_StateMachine_DW.is_FAULT =
          SWC_AP_StateMachine_IN_FaultBlinkingLED;
        *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_BlinkingLight;
        MeAP_cnt_StateDebugVar = 615U;
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt >
                 *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur) {
        SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_DIsableHMI;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        MeAP_cnt_StateDebugVar = 614U;
        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = 0U;
      } else {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = (uint16_T)tmp;
      }
      break;

     case SWC_AP_StateMachine_IN_AutoParkScanNoReverse:
      if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed || (*rty_IeAP_e_SPMLedSts ==
           TeAP_e_PAMLedCtrlStatus_BlinkingLight)) {
        SWC_AP_StateMachine_DW.is_FAULT =
          SWC_AP_StateMachine_IN_FaultBlinkingLED;
        *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_BlinkingLight;
        MeAP_cnt_StateDebugVar = 615U;
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt >
                 *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur) {
        SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_DIsableHMI;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        MeAP_cnt_StateDebugVar = 614U;
        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = 0U;
      } else {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = (uint16_T)tmp;
      }
      break;

     case SWC_AP_StateMachine_IN_DIsableHMI:
      if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed || (*rty_IeAP_e_SPMLedSts ==
           TeAP_e_PAMLedCtrlStatus_BlinkingLight)) {
        SWC_AP_StateMachine_DW.is_FAULT =
          SWC_AP_StateMachine_IN_FaultBlinkingLED;
        *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_BlinkingLight;
        MeAP_cnt_StateDebugVar = 615U;
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_SPMBlinkLEDCnt >
                 *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur) {
        SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_FaultLEDOFF;
        *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
        MeAP_cnt_StateDebugVar = 616U;
      } else {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_SPMBlinkLEDCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_SPMBlinkLEDCnt = (uint16_T)tmp;
        *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
      }
      break;

     case SWC_AP_StateMachine_IN_FaultBlinkingLED:
      if (SWC_AP_StateMachine_DW.MeAP_cnt_SPMBlinkLEDCnt >
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur) {
        SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_FaultLEDOFF;
        *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
        MeAP_cnt_StateDebugVar = 616U;
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt >
                 *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur) {
        SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_DIsableHMI;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        MeAP_cnt_StateDebugVar = 614U;
        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = 0U;
      } else {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = (uint16_T)tmp;
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_SPMBlinkLEDCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_SPMBlinkLEDCnt = (uint16_T)tmp;
      }
      break;

     case SWC_AP_StateMachine_IN_FaultLEDOFF:
      break;

     default:
      /* case IN_Fault_Init: */
      if ((MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_Out) ||
          (MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_In)) {
        SWC_AP_StateMachine_DW.is_FAULT =
          SWC_AP_StateMachine_IN_AutoParkScanNoGear;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL;
        SWC_AP_StateMachine_DW.MeAP_cnt_SPMBlinkLEDCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = 0U;
        MeAP_cnt_StateDebugVar = 610U;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
      } else if ((!(MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_Out)) &&
                 (!(MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_In)) &&
                 ((int32_T)rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                  (int32_T)TeVBII_e_GearState_ReverseGear)) {
        SWC_AP_StateMachine_DW.is_FAULT =
          SWC_AP_StateMachine_IN_AutoParkScanBackward;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_TEMP_NA_OVERLAY;
        SWC_AP_StateMachine_DW.MeAP_cnt_SPMBlinkLEDCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = 0U;
        MeAP_cnt_StateDebugVar = 611U;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
      } else if ((!(MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_Out)) &&
                 (!(MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_In)) &&
                 (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
                  TeAP_e_FiltdGearState_ReverseGear)) {
        SWC_AP_StateMachine_DW.is_FAULT =
          SWC_AP_StateMachine_IN_AutoParkScanNoReverse;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_TEMP_NA_FULLSCREEN;
        SWC_AP_StateMachine_DW.MeAP_cnt_SPMBlinkLEDCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = 0U;
        MeAP_cnt_StateDebugVar = 612U;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
      } else {
        SWC_AP_StateMachine_DW.is_FAULT =
          SWC_AP_StateMachine_IN_AutoParkScanFault;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL;
        SWC_AP_StateMachine_DW.MeAP_cnt_SPMBlinkLEDCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_cnt_DisableHMICnt = 0U;
        MeAP_cnt_StateDebugVar = 613U;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/AUTOPARK_StateMachine' */
  /* End of Outputs for SubSystem: '<S3>/AP_Statemachine' */
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_exit_internal_Scanning_FullAutoPark(void)
{
  SWC_AP_StateMachine_DW.is_DISCLAIMER = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_PERP_SELECT_LEFT =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_PERP_SELECT_RIGHT =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_exit_internal_Scanning_SemiAutoPark(void)
{
  SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD_l =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL_a =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_exit_internal_ParkIn(void)
{
  SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_MutlipleMoves =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_Active_SemiAutoPark =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_exit_internal_Scanning_FullAutoPark();
  SWC_AP_StateMachine_exit_internal_Scanning_SemiAutoPark();
  SWC_AP_StateMachine_DW.is_ParkIn = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_exit_internal_Park_Exit(void)
{
  SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR_o =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_Active_SemiAutoParkExit =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark_l =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_Park_Exit = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_exit_internal_Abort(void)
{
  SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_Abort = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_exit_internal_ON(void)
{
  SWC_AP_StateMachine_exit_internal_ParkIn();
  SWC_AP_StateMachine_exit_internal_Park_Exit();
  SWC_AP_StateMachine_DW.is_ACTIVE_AUTOPARK =
    SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_exit_internal_Abort();
  SWC_AP_StateMachine_DW.is_Complete = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_STANDBY = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
  SWC_AP_StateMachine_DW.is_ON = SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_gh3(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur)
{
  int32_T tmp;
  if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt <=
      *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
      SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = true;
      MeAP_cnt_TransDebugVar = 20U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
      MeAP_cnt_TransDebugVar = 19U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
    MeAP_cnt_TransDebugVar = 17U;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_gh(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD_l =
    SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_k;
  *rty_IeAP_b_VehMnvrDirSPM = true;

  /* false = Backward, true= Forward  */
  *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
  *rty_MeAP_b_ChimeActvReqLHFSVM = false;
  *rty_MeAP_b_ChimeActvReqRHFSVM = false;
  *rty_MeAP_b_ChimeActvReqLHRSVM = false;
  *rty_MeAP_b_ChimeActvReqRHRSVM = false;
  *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
  *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
  *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_gh3
    (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
     rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur);
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_Scanning_SemiAutoPark(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  /* Constant: '<S8>/Constant' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if ((!SWC_AP_StateMachine_B.MeAP_b_ValidSlotAvl) || (((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistL)) && ((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistR)))) {
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_kx;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
    MeAP_cnt_StateDebugVar = 13U;
    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
    SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_gh
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
       rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  }

  /* End of Constant: '<S8>/Constant' */
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_g(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur)
{
  int32_T tmp;
  if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt <=
      *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
      SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = true;
      MeAP_cnt_TransDebugVar = 20U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
      MeAP_cnt_TransDebugVar = 19U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
    MeAP_cnt_TransDebugVar = 17U;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD =
    SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_k;
  *rty_IeAP_b_VehMnvrDirSPM = true;

  /* false = Backward, true= Forward  */
  *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
  *rty_MeAP_b_ChimeActvReqLHFSVM = false;
  *rty_MeAP_b_ChimeActvReqRHFSVM = false;
  *rty_MeAP_b_ChimeActvReqLHRSVM = false;
  *rty_MeAP_b_ChimeActvReqRHRSVM = false;
  *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
  *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
  *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_g
    (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
     rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur);
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_Scanning_FullAutoPark(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  /* Constant: '<S8>/Constant' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if ((!SWC_AP_StateMachine_B.MeAP_b_ValidSlotAvl) || (((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistL)) && ((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistR)))) {
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
    MeAP_cnt_StateDebugVar = 13U;
    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
    SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
       rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_b_InitBrkPedlPressed = false;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  }

  /* End of Constant: '<S8>/Constant' */
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_ParkIn(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_ParKMnvrActv
  *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  if (!rtu_IbVBII_VehState_LowSpd->IeVBII_b_ActvParkMode) {
    SWC_AP_StateMachine_DW.is_ParkIn =
      SWC_AP_StateMachine_IN_Scanning_FullAutoPark;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Scanning;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Enabled_Seeking;
    SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart = false;
    SWC_AP_StateMachine_enter_internal_Scanning_FullAutoPark
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
       rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
       rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
       rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
       rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
       rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    SWC_AP_StateMachine_DW.is_ParkIn =
      SWC_AP_StateMachine_IN_Scanning_SemiAutoPark;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Scanning;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Enabled_Seeking;
    SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
    SWC_AP_StateMachine_enter_internal_Scanning_SemiAutoPark
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
       rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
       rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
       rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
       rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
       rty_MeAP_e_PAMChimeRepnRateSVM);
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SemiAutoParkSCANNING(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  /* MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING =
      SWC_AP_StateMachine_IN_PARALLEL_EXIT_SELECT;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    MeAP_cnt_StateDebugVar = 79U;
  } else {
    SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING =
      SWC_AP_StateMachine_IN_PARALLEL_EXIT_STOP;
    SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_cnt_StateDebugVar = 80U;
    SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP_g(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_FullAutoParkSCANNING(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  /* MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING =
      SWC_AP_StateMachine_IN_PARALLEL_EXIT_SELECT;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    MeAP_cnt_StateDebugVar = 62U;
  } else {
    SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING =
      SWC_AP_StateMachine_IN_PARALLEL_EXIT_STOP;
    SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_cnt_StateDebugVar = 63U;
    SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP_g
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_Park_Exit(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_ParKMnvrActv
  *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  if (!rtu_IbVBII_VehState_LowSpd->IeVBII_b_ActvParkMode) {
    SWC_AP_StateMachine_DW.is_Park_Exit =
      SWC_AP_StateMachine_IN_FullAutoParkSCANNING;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Scanning;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Enabled_Seeking;
    SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart = false;
    SWC_AP_StateMachine_enter_internal_FullAutoParkSCANNING
      (rtu_IbVBII_VehState_LowSpd, rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    SWC_AP_StateMachine_DW.is_Park_Exit =
      SWC_AP_StateMachine_IN_SemiAutoParkSCANNING;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Scanning;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Enabled_Seeking;
    SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
    SWC_AP_StateMachine_enter_internal_SemiAutoParkSCANNING
      (rtu_IbVBII_VehState_LowSpd, rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_IDLE(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam,
  const uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat
  *rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  if ((SWC_AP_StateMachine_DW.MeAP_b_PPPAMode == TeAP_b_PPPAMode_ParkIn) &&
      (*rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake)) {
    SWC_AP_StateMachine_DW.is_ACTIVE_AUTOPARK = SWC_AP_StateMachine_IN_ParkIn;
    SWC_AP_StateMachine_DW.MeAP_cnt_Move = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart = false;
    SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    SWC_AP_StateMachine_enter_internal_ParkIn(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
      rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
      rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat,
      rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
      rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
      rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
      rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if ((SWC_AP_StateMachine_DW.MeAP_b_PPPAMode == TeAP_b_PPPAMode_ParkExit)
             && (*rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake) &&
             rtu_MbNVM_ProxyParam->KeAP_b_PullOutCtrlPres) {
    SWC_AP_StateMachine_DW.is_ACTIVE_AUTOPARK = SWC_AP_StateMachine_IN_Park_Exit;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart = false;
    SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    SWC_AP_StateMachine_enter_internal_Park_Exit(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_IeAP_e_ParKMnvrActv,
      rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat, rty_MeAP_e_PAMVolSigSVM,
      rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
      rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
      rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    if (!*rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake) {
      tmp = SWC_AP_StateMachine_DW.MeAP_s_CamHandshakeSecCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_s_CamHandshakeSecCnt = (uint16_T)tmp;

      /* Constant: '<S5>/Constant8' */
      if (SWC_AP_StateMachine_DW.MeAP_s_CamHandshakeSecCnt > ((uint16_T)500U)) {
        SWC_AP_StateMachine_B.MeAP_b_CamHandshakeTimeout = true;
        MeAP_cnt_TransDebugVar = 5U;
      } else {
        SWC_AP_StateMachine_B.MeAP_b_CamHandshakeTimeout = false;
        MeAP_cnt_TransDebugVar = 4U;
      }

      /* End of Constant: '<S5>/Constant8' */
    } else {
      SWC_AP_StateMachine_DW.MeAP_s_CamHandshakeSecCnt = 0U;
      SWC_AP_StateMachine_B.MeAP_b_CamHandshakeTimeout = false;
      MeAP_cnt_TransDebugVar = 2U;
    }

    /* Park-IN scenario */
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
         TeAP_e_FiltdGearState_Drive) ||
        (((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
           TeAP_e_FiltdGearState_Neutral) ||
          (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
           TeAP_e_FiltdGearState_Parking)) && (!*rtu_MeAP_b_ObjPrestFC))) {
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
      SWC_AP_StateMachine_DW.MeAP_b_PPPAMode = TeAP_b_PPPAMode_ParkIn;
      MeAP_cnt_StateDebugVar = 9U;
    } else {
      /* Park-EXIT scenario */
      if (((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
            TeAP_e_FiltdGearState_Neutral) ||
           (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
            TeAP_e_FiltdGearState_Parking)) && (*rtu_MeAP_b_ObjPrestFC)) {
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT;
        SWC_AP_StateMachine_DW.MeAP_b_PPPAMode = TeAP_b_PPPAMode_ParkExit;
        MeAP_cnt_StateDebugVar = 10U;
      } else {
        if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
            TeAP_e_FiltdGearState_ReverseGear) {
          *rty_IeAP_b_VehMnvrDirSPM = false;

          /* false = Backward, true= Forward  */
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
        }
      }
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_PAUSED_PRESS_BUTTON(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, TeAP_e_PAMVolSig *
  rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  uint32_T qY;
  MeAP_b_InitBrkPedlPressed = false;
  SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt <=
      *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
    qY = SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt + /*MW:OvSatOk*/
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (qY < SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt) {
      qY = MAX_uint32_T;
    }

    SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = qY;
    if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
      SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = true;
      MeAP_cnt_TransDebugVar = 84U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
      MeAP_cnt_TransDebugVar = 83U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
    MeAP_cnt_TransDebugVar = 81U;
  }

  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  MeAP_s_GearShiftReqWaitCnt = 0U;
  MeAP_b_GearShiftReqWaitTimeout = false;
  if ((*rtu_MeAP_e_GearCmd == TeAutoPark_e_GearCmd_Drive) &&
      (*rty_MeAP_b_StandStill) && (*rtu_IeAP_kph_TrgtVehSpd < 1.0E-5F) &&
      (*rtu_IeAP_cm_TrgtDist < 1.0E-5F)) {
    if (!MeAP_b_GearShiftReqWaitTimeout) {
      tmp = MeAP_s_GearShiftReqWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      MeAP_s_GearShiftReqWaitCnt = (uint16_T)tmp;
      if (MeAP_s_GearShiftReqWaitCnt > KeAP_s_GearShiftReqWaitCnt) {
        MeAP_b_GearShiftReqWaitTimeout = true;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_D;
      } else {
        MeAP_b_GearShiftReqWaitTimeout = false;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      }
    } else {
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_D;
    }
  } else {
    MeAP_s_GearShiftReqWaitCnt = 0U;
    MeAP_b_GearShiftReqWaitTimeout = false;
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
  }

  if ((*rty_IeAP_e_GearShiftReq == TeAP_e_GearShiftReq_D) &&
      (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
       TeAP_e_FiltdGearState_Drive)) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
      SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
      MeAP_cnt_TransDebugVar = 65U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
      MeAP_cnt_TransDebugVar = 64U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
    MeAP_cnt_TransDebugVar = 62U;
  }

  if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
      (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
    SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_FULL_AUTO_ACTIVE_FRONT_REAR(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM,
  boolean_T *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (*rtu_MeAP_b_ObjInPath) {
    SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
      SWC_AP_StateMachine_IN_PAUSED_OBJECT_IN_PATH;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PAUSED_OBJECT_IN_PATH;
    MeAP_cnt_StateDebugVar = 28U;
    *rty_MeAP_b_VCOpPaused = true;
    SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
    if (SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt <=
        *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt >
          *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur) {
        SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = true;
        MeAP_cnt_TransDebugVar = 78U;
      } else {
        SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = false;
        MeAP_cnt_TransDebugVar = 77U;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt = 0U;
      SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = false;
      MeAP_cnt_TransDebugVar = 75U;
    }

    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased) {
    SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
      SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON;
    MeAP_cnt_StateDebugVar = 29U;
    *rty_MeAP_b_VCOpPaused = true;
    SWC_AP_StateMachine_enter_internal_PAUSED_PRESS_BUTTON
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
       rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
       rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
       rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
       rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if (SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR ==
             SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT) {
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR =
        SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR;
      MeAP_cnt_StateDebugVar = 26U;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR
        (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
         rtu_IeAP_kph_TrgtVehSpd, rtu_IeAP_cm_TrgtDist, rty_IeAP_e_GearShiftReq,
         rty_MeAP_b_StandStill);
    } else {
      if ((*rtu_MeAP_e_GearCmd == TeAutoPark_e_GearCmd_Reverse) &&
          (*rty_MeAP_b_StandStill) && (*rtu_IeAP_kph_TrgtVehSpd < 1.0E-5F) &&
          (*rtu_IeAP_cm_TrgtDist < 1.0E-5F)) {
        if (!MeAP_b_GearShiftReqWaitTimeout) {
          tmp = MeAP_s_GearShiftReqWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          MeAP_s_GearShiftReqWaitCnt = (uint16_T)tmp;
          if (MeAP_s_GearShiftReqWaitCnt > KeAP_s_GearShiftReqWaitCnt) {
            MeAP_b_GearShiftReqWaitTimeout = true;
            *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_R;
          } else {
            MeAP_b_GearShiftReqWaitTimeout = false;
            *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
          }
        } else {
          *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_R;
        }
      } else {
        MeAP_s_GearShiftReqWaitCnt = 0U;
        MeAP_b_GearShiftReqWaitTimeout = false;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      }

      if ((*rty_IeAP_e_GearShiftReq == TeAP_e_GearShiftReq_R) &&
          (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
           TeAP_e_FiltdGearState_ReverseGear)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
          MeAP_cnt_TransDebugVar = 72U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
          MeAP_cnt_TransDebugVar = 71U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
        MeAP_cnt_TransDebugVar = 69U;
      }

      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
      }
    }
  } else {
    /* case IN_FULL_AUTO_ACTIVE_REAR: */
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
        TeAP_e_FiltdGearState_Drive) {
      SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR =
        SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_FRONT;
      MeAP_cnt_StateDebugVar = 27U;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      MeAP_s_GearShiftReqWaitCnt = 0U;
      MeAP_b_GearShiftReqWaitTimeout = false;
      if ((*rtu_MeAP_e_GearCmd == TeAutoPark_e_GearCmd_Reverse) &&
          (*rty_MeAP_b_StandStill) && (*rtu_IeAP_kph_TrgtVehSpd < 1.0E-5F) &&
          (*rtu_IeAP_cm_TrgtDist < 1.0E-5F)) {
        if (!MeAP_b_GearShiftReqWaitTimeout) {
          tmp = MeAP_s_GearShiftReqWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          MeAP_s_GearShiftReqWaitCnt = (uint16_T)tmp;
          if (MeAP_s_GearShiftReqWaitCnt > KeAP_s_GearShiftReqWaitCnt) {
            MeAP_b_GearShiftReqWaitTimeout = true;
            *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_R;
          } else {
            MeAP_b_GearShiftReqWaitTimeout = false;
            *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
          }
        } else {
          *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_R;
        }
      } else {
        MeAP_s_GearShiftReqWaitCnt = 0U;
        MeAP_b_GearShiftReqWaitTimeout = false;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      }

      if (*rty_IeAP_e_GearShiftReq == TeAP_e_GearShiftReq_R) {
        tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
          MeAP_cnt_TransDebugVar = 72U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
          MeAP_cnt_TransDebugVar = 71U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
        MeAP_cnt_TransDebugVar = 69U;
      }

      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
      }
    } else {
      if ((*rtu_MeAP_e_GearCmd == TeAutoPark_e_GearCmd_Drive) &&
          (*rty_MeAP_b_StandStill) && (*rtu_IeAP_kph_TrgtVehSpd < 1.0E-5F) &&
          (*rtu_IeAP_cm_TrgtDist < 1.0E-5F)) {
        if (!MeAP_b_GearShiftReqWaitTimeout) {
          tmp = MeAP_s_GearShiftReqWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          MeAP_s_GearShiftReqWaitCnt = (uint16_T)tmp;
          if (MeAP_s_GearShiftReqWaitCnt > KeAP_s_GearShiftReqWaitCnt) {
            MeAP_b_GearShiftReqWaitTimeout = true;
            *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_D;
          } else {
            MeAP_b_GearShiftReqWaitTimeout = false;
            *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
          }
        } else {
          *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_D;
        }
      } else {
        MeAP_s_GearShiftReqWaitCnt = 0U;
        MeAP_b_GearShiftReqWaitTimeout = false;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      }

      if ((*rty_IeAP_e_GearShiftReq == TeAP_e_GearShiftReq_D) &&
          (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
           TeAP_e_FiltdGearState_Drive)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
          MeAP_cnt_TransDebugVar = 65U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
          MeAP_cnt_TransDebugVar = 64U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
        MeAP_cnt_TransDebugVar = 62U;
      }

      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
      }
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_PAUSED_OBJECT_IN_PATH(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM,
  boolean_T *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (!*rtu_MeAP_b_ObjInPath) {
    SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
      SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR;
    *rty_MeAP_b_VCOpPaused = false;
    MeAP_b_InitBrkPedlPressed = false;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR =
      SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR;
    *rty_IeAP_b_VehMnvrDirSPM = false;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR;
    MeAP_cnt_StateDebugVar = 26U;
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
    SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
    SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR
      (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
       rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
       rtu_IeAP_kph_TrgtVehSpd, rtu_IeAP_cm_TrgtDist, rty_IeAP_e_GearShiftReq,
       rty_MeAP_b_StandStill);
  } else {
    if (SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt <=
        *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt >
          *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur) {
        SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = true;
        MeAP_cnt_TransDebugVar = 78U;
      } else {
        SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = false;
        MeAP_cnt_TransDebugVar = 77U;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt = 0U;
      SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = false;
      MeAP_cnt_TransDebugVar = 75U;
    }

    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_PAUSED_PRESS_BUTTON(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM,
  boolean_T *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  uint32_T qY;
  if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed) {
    SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
      SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR;
    *rty_MeAP_b_VCOpPaused = false;
    MeAP_b_InitBrkPedlPressed = false;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR =
      SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR;
    *rty_IeAP_b_VehMnvrDirSPM = false;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR;
    MeAP_cnt_StateDebugVar = 26U;
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
    SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
    SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR
      (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
       rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
       rtu_IeAP_kph_TrgtVehSpd, rtu_IeAP_cm_TrgtDist, rty_IeAP_e_GearShiftReq,
       rty_MeAP_b_StandStill);
  } else {
    if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt <=
        *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
      qY = SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt + /*MW:OvSatOk*/
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (qY < SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt) {
        qY = MAX_uint32_T;
      }

      SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = qY;
      if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt >
          *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
        SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = true;
        MeAP_cnt_TransDebugVar = 84U;
      } else {
        SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
        MeAP_cnt_TransDebugVar = 83U;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
      SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
      MeAP_cnt_TransDebugVar = 81U;
    }

    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_REMOVE_HANDS_FEET(const uint16_T *
  rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  *rty_MeAP_b_VCOpPaused = true;
  MeAP_b_InitBrkPedlPressed = true;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_Active_FullAutoPark(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM,
  boolean_T *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill)
{
  uint32_T qY;
  int32_T tmp;
  if ((SWC_AP_StateMachine_DW.MeAP_cnt_Move > 0) && (*rtu_MeAP_e_GearCmd ==
       TeAutoPark_e_GearCmd_Park)) {
    SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_ParkIn =
      SWC_AP_StateMachine_IN_Complete_FullAutoPark;
    MeAP_s_GearShiftReqWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = 0U;
    MeAP_b_GearShiftReqWaitTimeout = false;
    SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
    SWC_AP_StateMachine_DW.MeAP_b_VehicleParked = false;
    if ((*rty_MeAP_b_StandStill) && (*rtu_IeAP_kph_TrgtVehSpd < 1.0E-5F) &&
        (*rtu_IeAP_cm_TrgtDist < 1.0E-5F)) {
      if (!MeAP_b_GearShiftReqWaitTimeout) {
        tmp = MeAP_s_GearShiftReqWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        MeAP_s_GearShiftReqWaitCnt = (uint16_T)tmp;
        if (MeAP_s_GearShiftReqWaitCnt > KeAP_s_GearShiftReqWaitCnt) {
          MeAP_b_GearShiftReqWaitTimeout = true;
          *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_P;
          MeAP_cnt_TransDebugVar = 2003U;
        } else {
          MeAP_b_GearShiftReqWaitTimeout = false;
          *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
          MeAP_cnt_TransDebugVar = 2002U;
        }
      } else {
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_P;
        MeAP_cnt_TransDebugVar = 2001U;
      }
    } else {
      MeAP_s_GearShiftReqWaitCnt = 0U;
      MeAP_b_GearShiftReqWaitTimeout = false;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      MeAP_cnt_TransDebugVar = 2000U;
    }

    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_Parking) ||
        (rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts ==
         TeVBII_e_VehEPBSts_Applied)) {
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      SWC_AP_StateMachine_DW.MeAP_b_VehicleParked = true;
    }
  } else {
    switch (SWC_AP_StateMachine_DW.is_Active_FullAutoPark) {
     case SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR:
      SWC_AP_StateMachine_FULL_AUTO_ACTIVE_FRONT_REAR(rtu_IbVBII_VehState_LowSpd,
        rtu_MeAP_e_GearCmd, rtu_MeAP_b_ObjInPath,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
        rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
        rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur,
        rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
        rtu_IeAP_kph_TrgtVehSpd, rtu_IeAP_cm_TrgtDist, rty_MeAP_e_HMIPopUp,
        rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_b_VCOpPaused, rty_IeAP_e_GearShiftReq,
        rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
        rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
        rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
        rty_MeAP_e_PAMChimeRepnRateSVM, rty_MeAP_b_StandStill);
      break;

     case SWC_AP_StateMachine_IN_PAUSED_OBJECT_IN_PATH:
      SWC_AP_StateMachine_PAUSED_OBJECT_IN_PATH(rtu_IbVBII_VehState_LowSpd,
        rtu_MeAP_e_GearCmd, rtu_MeAP_b_ObjInPath,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
        rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
        rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur,
        rtu_IeAP_kph_TrgtVehSpd, rtu_IeAP_cm_TrgtDist, rty_MeAP_e_HMIPopUp,
        rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_b_VCOpPaused, rty_IeAP_e_GearShiftReq,
        rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
        rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
        rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
        rty_MeAP_e_PAMChimeRepnRateSVM, rty_MeAP_b_StandStill);
      break;

     case SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON:
      SWC_AP_StateMachine_PAUSED_PRESS_BUTTON(rtu_IbVBII_VehState_LowSpd,
        rtu_MeAP_e_GearCmd, rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
        rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
        rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
        rtu_IeAP_kph_TrgtVehSpd, rtu_IeAP_cm_TrgtDist, rty_MeAP_e_HMIPopUp,
        rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_b_VCOpPaused, rty_IeAP_e_GearShiftReq,
        rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
        rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
        rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
        rty_MeAP_e_PAMChimeRepnRateSVM, rty_MeAP_b_StandStill);
      break;

     case SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON_BrkPedlPressed:
      if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed &&
          SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs) {
        SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
          SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR;
        *rty_MeAP_b_VCOpPaused = false;
        MeAP_b_InitBrkPedlPressed = false;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR =
          SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR;
        MeAP_cnt_StateDebugVar = 26U;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
        SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR
          (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
           rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
           rtu_IeAP_kph_TrgtVehSpd, rtu_IeAP_cm_TrgtDist,
           rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
      } else if ((!SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs) &&
                 SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed) {
        SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
          SWC_AP_StateMachine_IN_REMOVE_HANDS_FEET;
        SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_REMOVE_HANDS_FEET;
        MeAP_cnt_StateDebugVar = 24U;
        SWC_AP_StateMachine_enter_internal_REMOVE_HANDS_FEET
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_b_VCOpPaused,
           rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
           rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
           rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
           rty_MeAP_e_PAMChimeRepnRateSVM);
      } else {
        if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt <=
            *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
          qY = SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt + /*MW:OvSatOk*/ *
            rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (qY < SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt) {
            qY = MAX_uint32_T;
          }

          SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = qY;
          if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
            SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = true;
            MeAP_cnt_TransDebugVar = 84U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
            MeAP_cnt_TransDebugVar = 83U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
          MeAP_cnt_TransDebugVar = 81U;
        }

        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
              KeAP_cnt_ScreenChimeTimeoutDur) {
            *rty_MeAP_b_ChimeActvReqLHFSVM = true;
            *rty_MeAP_b_ChimeActvReqRHFSVM = true;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      }
      break;

     default:
      /* case IN_REMOVE_HANDS_FEET: */
      if (SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs &&
          SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed &&
          (SWC_AP_StateMachine_DW.temporalCounter_i1 >= 67U)) {
        SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
          SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR;
        *rty_MeAP_b_VCOpPaused = false;
        MeAP_b_InitBrkPedlPressed = false;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR =
          SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR;
        MeAP_cnt_StateDebugVar = 26U;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
        SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR
          (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
           rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
           rtu_IeAP_kph_TrgtVehSpd, rtu_IeAP_cm_TrgtDist,
           rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
      } else if ((!SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs) &&
                 SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased) {
        SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
          SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON_BrkPedlPressed;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON;
        MeAP_cnt_StateDebugVar = 29U;
        *rty_MeAP_b_VCOpPaused = true;
        MeAP_b_InitBrkPedlPressed = true;
        SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
        if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt <=
            *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
          qY = SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt + /*MW:OvSatOk*/ *
            rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (qY < SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt) {
            qY = MAX_uint32_T;
          }

          SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = qY;
          if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
            SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = true;
            MeAP_cnt_TransDebugVar = 84U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
            MeAP_cnt_TransDebugVar = 83U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
          MeAP_cnt_TransDebugVar = 81U;
        }

        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
              KeAP_cnt_ScreenChimeTimeoutDur) {
            *rty_MeAP_b_ChimeActvReqLHFSVM = true;
            *rty_MeAP_b_ChimeActvReqRHFSVM = true;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else if (SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs &&
                 (!SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed)) {
        SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
          SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON;
        MeAP_cnt_StateDebugVar = 29U;
        *rty_MeAP_b_VCOpPaused = true;
        SWC_AP_StateMachine_enter_internal_PAUSED_PRESS_BUTTON
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
           rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
           rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
           rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
           rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                 KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
      break;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_Handshake_FullAutoPark(const TbVBIA_VehState_AP *
  rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat
  *rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (!*rty_MeAP_b_StandStill) {
    SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_ParkIn =
      SWC_AP_StateMachine_IN_Scanning_FullAutoPark;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Scanning;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Enabled_Seeking;
    SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart = false;
    SWC_AP_StateMachine_enter_internal_Scanning_FullAutoPark
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
       rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
       rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
       rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
       rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
       rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if (SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces &&
             SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces) {
    SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_ParkIn =
      SWC_AP_StateMachine_IN_Active_FullAutoPark;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Park_In;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Engaged_Full;
    *rty_MeAP_b_VCOpPaused = true;
    SWC_AP_StateMachine_DW.is_Active_FullAutoPark =
      SWC_AP_StateMachine_IN_REMOVE_HANDS_FEET;
    SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_REMOVE_HANDS_FEET;
    MeAP_cnt_StateDebugVar = 24U;
    SWC_AP_StateMachine_enter_internal_REMOVE_HANDS_FEET
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_b_VCOpPaused,
       rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
       rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
       rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
       rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    switch (SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark) {
     case SWC_AP_StateMachine_IN_BSM_Handshake:
      if (SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces) {
        SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark =
          SWC_AP_StateMachine_IN_Engaged_Full;
        *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Engaged_Full;
        SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt = 0U;
        if (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts ==
            TeVBII_e_ParkingIntrvntionSts_Active) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt = (uint16_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout =
            (SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt >
             *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt);
        } else {
          SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt = 0U;
          SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout = false;
        }
      } else {
        if (SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeActv) {
          *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_CVPAM_Request;
        } else {
          *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
        }

        if ((!SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout) &&
            (*rty_IeAP_e_InterfaceBSM == TeAP_e_InterfaceBSM_CVPAM_Request) &&
            (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts ==
             TeVBII_e_ParkingIntrvntionSts_Active)) {
          SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces = true;
          SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeSts = true;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces = false;
        }

        if ((*rty_IeAP_e_InterfaceBSM == TeAP_e_InterfaceBSM_CVPAM_Request) && (
             !SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout) {
            SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = true;
            MeAP_cnt_TransDebugVar = 42U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
            MeAP_cnt_TransDebugVar = 41U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
          MeAP_cnt_TransDebugVar = 39U;
        }
      }
      break;

     case SWC_AP_StateMachine_IN_EPS_Handshake_e:
      if (SWC_AP_StateMachine_B.MeAP_b_EPSHandshakeActv) {
        SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
          TeAP_e_SPMLatCtrlReqSts_SPM_Request;
      } else {
        SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
          TeAP_e_SPMLatCtrlReqSts_Idle;
      }

      if ((!SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout) &&
          (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts ==
           TeVBII_e_SPMLatCtrlRespSts_HasOpen) &&
          (SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
           TeAP_e_SPMLatCtrlReqSts_SPM_Request)) {
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = true;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = false;
      }

      if ((SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
           TeAP_e_SPMLatCtrlReqSts_SPM_Request) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout) {
          SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = true;
          MeAP_cnt_TransDebugVar = 58U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
          MeAP_cnt_TransDebugVar = 57U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
        MeAP_cnt_TransDebugVar = 55U;
      }
      break;

     case SWC_AP_StateMachine_IN_Engaged_Full:
      if (SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout) {
        SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark =
          SWC_AP_StateMachine_IN_ReverseGearShitReq;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_R;
        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
        MeAP_cnt_StateDebugVar = 21U;
        if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
            TeAP_e_FiltdGearState_ReverseGear) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
            SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
            MeAP_cnt_TransDebugVar = 48U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
            MeAP_cnt_TransDebugVar = 47U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
          MeAP_cnt_TransDebugVar = 45U;
        }
      } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts ==
                 TeVBII_e_ParkingIntrvntionSts_Active) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt = (uint16_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout =
          (SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt >
           *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt);
      } else {
        SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout = false;
      }
      break;

     default:
      /* case IN_ReverseGearShitReq: */
      if ((int32_T)rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
          (int32_T)TeVBII_e_GearState_ReverseGear) {
        SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark =
          SWC_AP_StateMachine_IN_EPS_Handshake_e;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
        SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
        MeAP_cnt_StateDebugVar = 22U;
        SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
        if (SWC_AP_StateMachine_B.MeAP_b_EPSHandshakeActv) {
          SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
            TeAP_e_SPMLatCtrlReqSts_SPM_Request;
        } else {
          SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
            TeAP_e_SPMLatCtrlReqSts_Idle;
        }

        if ((!SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout) &&
            (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts ==
             TeVBII_e_SPMLatCtrlRespSts_HasOpen) &&
            (SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
             TeAP_e_SPMLatCtrlReqSts_SPM_Request)) {
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = true;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = false;
        }

        if ((SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
             TeAP_e_SPMLatCtrlReqSts_SPM_Request) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout) {
            SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = true;
            MeAP_cnt_TransDebugVar = 58U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
            MeAP_cnt_TransDebugVar = 57U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
          MeAP_cnt_TransDebugVar = 55U;
        }
      } else if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
                 TeAP_e_FiltdGearState_ReverseGear) {
        tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
          MeAP_cnt_TransDebugVar = 48U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
          MeAP_cnt_TransDebugVar = 47U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
        MeAP_cnt_TransDebugVar = 45U;
      }
      break;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_PERP_SELECT_LEFT_l(const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  /* !MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle ==
              TeAutoPark_e_ParkStyle_Front_In) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_FORWARD;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD;
    MeAP_cnt_StateDebugVar = 41U;
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_ReverseGear) &&
        SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
      MeAP_cnt_TransDebugVar = 100U;
    } else {
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
      MeAP_cnt_TransDebugVar = 99U;
    }
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle ==
              TeAutoPark_e_ParkStyle_Rear_In) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_REVERSE;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE;
    MeAP_cnt_StateDebugVar = 42U;
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_ReverseGear) &&
        SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
      MeAP_cnt_TransDebugVar = 102U;
    } else {
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
      MeAP_cnt_TransDebugVar = 101U;
    }
  } else {
    if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
        (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
         &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
      SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
        SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE_d;
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
      MeAP_cnt_StateDebugVar = 34U;
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
        SWC_AP_StateMachine_IN_Default;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_PERP_SELECT_LEFT_FORWARD(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  /* !MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_o;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_LEFT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    MeAP_cnt_StateDebugVar = 39U;
  } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
              TeAP_e_FiltdGearState_ReverseGear) &&
             SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
    *rty_IeAP_b_VehMnvrDirSPM = false;

    /* false = Backward, true= Forward  */
    SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
    MeAP_cnt_TransDebugVar = 100U;
  } else {
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
    MeAP_cnt_TransDebugVar = 99U;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_PERP_SELECT_RIGHT_d(const TeAutoPark_e_ParkStyle
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  /* !MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE_d;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_cnt_StateDebugVar = 34U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
      SWC_AP_StateMachine_IN_Default;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle ==
              TeAutoPark_e_ParkStyle_Front_In) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT_FORWARD;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD;
    MeAP_cnt_StateDebugVar = 43U;
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_ReverseGear) &&
        SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
      MeAP_cnt_TransDebugVar = 104U;
    } else {
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
      MeAP_cnt_TransDebugVar = 103U;
    }
  } else {
    if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle ==
         TeAutoPark_e_ParkStyle_Rear_In) && uMultiWordNe
        (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
         &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
      SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
        SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT_REVERSE;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE;
      MeAP_cnt_StateDebugVar = 44U;
      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
           TeAP_e_FiltdGearState_ReverseGear) &&
          SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
        MeAP_cnt_TransDebugVar = 106U;
      } else {
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
        MeAP_cnt_TransDebugVar = 105U;
      }
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void
  SWC_AP_StateMachine_enter_internal_SEMI_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH(
  const TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
       *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) &&
      (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt <=
       *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur)) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = (uint16_T)tmp;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH;
    if (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur) {
      SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = true;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
  }

  if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt <=
      *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
      SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = true;
      MeAP_cnt_TransDebugVar = 20U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
      MeAP_cnt_TransDebugVar = 19U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
    MeAP_cnt_TransDebugVar = 17U;
  }

  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_py(const uint16_T *
  rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_SEARCHING_MOVE_FORWARD_l(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* Constant: '<S8>/Constant' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if (SWC_AP_StateMachine_B.MeAP_b_ValidSlotAvl && ((true &&
        SWC_AP_StateMachine_B.MeAP_e_b_PSExistL) || (true &&
        SWC_AP_StateMachine_B.MeAP_e_b_PSExistR))) {
    SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD_l =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    switch (SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD_l) {
     case SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_k:
      if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
          TeAP_e_FiltdGearState_ReverseGear) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD_l =
          SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
        SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
        SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_py
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
                 *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD_l =
          SWC_AP_StateMachine_IN_SEMI_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_enter_internal_SEMI_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH
          (rtu_IbVBII_VehState_LowSpd,
           rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
           rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, rty_MeAP_e_HMIPopUp,
           rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
           rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
           rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
           rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt <=
                 *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
          SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = true;
          MeAP_cnt_TransDebugVar = 20U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
          MeAP_cnt_TransDebugVar = 19U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
        MeAP_cnt_TransDebugVar = 17U;
      }
      break;

     case SWC_AP_StateMachine_IN_SEMI_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH:
      if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
          TeAP_e_FiltdGearState_ReverseGear) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD_l =
          SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
        SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
        SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_py
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
                 *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD_l =
          SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_k;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_gh3
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur);
      } else {
        if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
             *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) &&
            (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt <=
             *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = (uint16_T)tmp;
          *rty_MeAP_e_HMIPopUp =
            TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH;
          if (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur) {
            SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = true;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
        }

        if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt <=
            *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
            SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = true;
            MeAP_cnt_TransDebugVar = 20U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
            MeAP_cnt_TransDebugVar = 19U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
          MeAP_cnt_TransDebugVar = 17U;
        }

        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
              KeAP_cnt_ScreenChimeTimeoutDur) {
            *rty_MeAP_b_ChimeActvReqLHFSVM = true;
            *rty_MeAP_b_ChimeActvReqRHFSVM = true;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      }
      break;

     default:
      /* case IN_SHIFT_TO_DRIVE: */
      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
           TeAP_e_FiltdGearState_ReverseGear) &&
          (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
           *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd)) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD_l =
          SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_k;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_gh3
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur);
      } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
                  TeAP_e_FiltdGearState_ReverseGear) &&
                 (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
                  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd)) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD_l =
          SWC_AP_StateMachine_IN_SEMI_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_enter_internal_SEMI_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH
          (rtu_IbVBII_VehState_LowSpd,
           rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
           rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, rty_MeAP_e_HMIPopUp,
           rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
           rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
           rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
           rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                 KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
      break;
    }
  }

  /* End of Constant: '<S8>/Constant' */
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_SPACE_FOUND_SELECT_SPACE_h(const
  ParkingSlotType_t *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const
  SlotSide_t *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* !MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
              ParkingSlotType_E_PW_PARALLEL) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide ==
              SlotSide_E_SLOT_LEFT) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SEMI_PARALLEL_REMOVE_HANDS_LEFT;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_LEFT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_ParallelParking;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    MeAP_cnt_StateDebugVar = 37U;
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_ReverseGear) &&
        SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
      MeAP_cnt_TransDebugVar = 96U;
    } else {
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
      MeAP_cnt_TransDebugVar = 95U;
    }
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
              ParkingSlotType_E_PW_PARALLEL) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide ==
              SlotSide_E_SLOT_RIGHT) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SEMI_PARALLEL_REMOVE_HANDS_RIGHT;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_ParallelParking;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    MeAP_cnt_StateDebugVar = 38U;
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_ReverseGear) &&
        SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
      MeAP_cnt_TransDebugVar = 98U;
    } else {
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
      MeAP_cnt_TransDebugVar = 97U;
    }
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
              ParkingSlotType_E_PW_PERPENDICULAR) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide ==
              SlotSide_E_SLOT_LEFT) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_o;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_LEFT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    MeAP_cnt_StateDebugVar = 39U;
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
              ParkingSlotType_E_PW_PERPENDICULAR) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide ==
              SlotSide_E_SLOT_RIGHT) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_RIGHT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    MeAP_cnt_StateDebugVar = 40U;
  } else if (SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b ==
             SWC_AP_StateMachine_IN_Default) {
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
        SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_on;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    }
  } else {
    /* case IN_SHIFT_TO_DRIVE: */
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
        SWC_AP_StateMachine_IN_Default;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
               KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_Default_g(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_pys(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SPACE_FOUND_SPEED_TOO_HIGH_k(
  const TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  MeAP_cnt_StateDebugVar = 21U;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
      *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur) {
      SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = true;
      MeAP_cnt_TransDebugVar = 26U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
      MeAP_cnt_TransDebugVar = 25U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
    MeAP_cnt_TransDebugVar = 23U;
  }

  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_SPACE_FOUND_STOP_k(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* Constant: '<S8>/Constant' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if ((!SWC_AP_StateMachine_B.MeAP_b_ValidSlotAvl) || (((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistL)) && ((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistR)))) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_kx;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
    MeAP_cnt_StateDebugVar = 13U;
    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
    SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_gh
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
       rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    /* !MeAP_b_StandStill &&... */
    if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
         KeAP_kph_StandStillSpdThd) &&
        (*rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus)) {
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
        SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
      SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
        SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_STANDSTILL_n;
      SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL_a =
        SWC_AP_StateMachine_IN_Default;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP_STANDSTILL;
      SWC_AP_StateMachine_enter_internal_Default_g
        (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
         rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
         rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
         rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
    } else {
      /* MeAP_b_StandStill &&... */
      if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <
          KeAP_kph_StandStillSpdThd) {
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
          SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE_d;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 34U;
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
          SWC_AP_StateMachine_IN_Default;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      } else {
        switch (SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k) {
         case SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_o:
          if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
               TeAP_e_FiltdGearState_ReverseGear) &&
              (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
               *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd)) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
              SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
            *rty_IeAP_b_VehMnvrDirSPM = true;

            /* false = Backward, true= Forward  */
            SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
              (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
                      TeAP_e_FiltdGearState_ReverseGear) &&
                     (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
                      *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd)) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
              SWC_AP_StateMachine_IN_SPACE_FOUND_SPEED_TOO_HIGH;
            *rty_IeAP_b_VehMnvrDirSPM = true;

            /* false = Backward, true= Forward  */
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SPEED_TOO_HIGH;
            SWC_AP_StateMachine_enter_internal_SPACE_FOUND_SPEED_TOO_HIGH_k
              (rtu_IbVBII_VehState_LowSpd,
               rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
               rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                     KeAP_cnt_ScreenChimeTimeoutDur) {
            tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
              *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
            if (tmp > 65535) {
              tmp = 65535;
            }

            SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
            if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                KeAP_cnt_ScreenChimeTimeoutDur) {
              *rty_MeAP_b_ChimeActvReqLHFSVM = true;
              *rty_MeAP_b_ChimeActvReqRHFSVM = true;
              *rty_MeAP_b_ChimeActvReqLHRSVM = false;
              *rty_MeAP_b_ChimeActvReqRHRSVM = false;
              *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
              *rty_MeAP_e_PAMChimeRepnRateSVM =
                TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
            } else {
              *rty_MeAP_b_ChimeActvReqLHFSVM = false;
              *rty_MeAP_b_ChimeActvReqRHFSVM = false;
              *rty_MeAP_b_ChimeActvReqLHRSVM = false;
              *rty_MeAP_b_ChimeActvReqRHRSVM = false;
              *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
              *rty_MeAP_e_PAMChimeRepnRateSVM =
                TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
            }
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
          break;

         case SWC_AP_StateMachine_IN_SPACE_FOUND_SPEED_TOO_HIGH:
          if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
              TeAP_e_FiltdGearState_ReverseGear) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
              SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_o;
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
            *rty_IeAP_b_VehMnvrDirSPM = false;

            /* false = Backward, true= Forward  */
            SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_pys
              (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
                     *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
              SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
            *rty_IeAP_b_VehMnvrDirSPM = true;

            /* false = Backward, true= Forward  */
            SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
              (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else {
            if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
                *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
              tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt +
                *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
              if (tmp > 65535) {
                tmp = 65535;
              }

              SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = (uint16_T)tmp;
              if (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt >
                  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur) {
                SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = true;
                MeAP_cnt_TransDebugVar = 26U;
              } else {
                SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
                MeAP_cnt_TransDebugVar = 25U;
              }
            } else {
              SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
              SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
              MeAP_cnt_TransDebugVar = 23U;
            }

            if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                KeAP_cnt_ScreenChimeTimeoutDur) {
              tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
                *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
              if (tmp > 65535) {
                tmp = 65535;
              }

              SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
              if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                  KeAP_cnt_ScreenChimeTimeoutDur) {
                *rty_MeAP_b_ChimeActvReqLHFSVM = true;
                *rty_MeAP_b_ChimeActvReqRHFSVM = true;
                *rty_MeAP_b_ChimeActvReqLHRSVM = false;
                *rty_MeAP_b_ChimeActvReqRHRSVM = false;
                *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
                *rty_MeAP_e_PAMChimeRepnRateSVM =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
                *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
              } else {
                *rty_MeAP_b_ChimeActvReqLHFSVM = false;
                *rty_MeAP_b_ChimeActvReqRHFSVM = false;
                *rty_MeAP_b_ChimeActvReqLHRSVM = false;
                *rty_MeAP_b_ChimeActvReqRHRSVM = false;
                *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
                *rty_MeAP_e_PAMChimeRepnRateSVM =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
                *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
              }
            } else {
              *rty_MeAP_b_ChimeActvReqLHFSVM = false;
              *rty_MeAP_b_ChimeActvReqRHFSVM = false;
              *rty_MeAP_b_ChimeActvReqLHRSVM = false;
              *rty_MeAP_b_ChimeActvReqRHRSVM = false;
              *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
              *rty_MeAP_e_PAMChimeRepnRateSVM =
                TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
            }
          }
          break;

         default:
          /* case IN_SPACE_FOUND_STOP: */
          if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
              TeAP_e_FiltdGearState_ReverseGear) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
              SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_o;
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
            *rty_IeAP_b_VehMnvrDirSPM = false;

            /* false = Backward, true= Forward  */
            SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_pys
              (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
                     *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
              SWC_AP_StateMachine_IN_SPACE_FOUND_SPEED_TOO_HIGH;
            *rty_IeAP_b_VehMnvrDirSPM = true;

            /* false = Backward, true= Forward  */
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SPEED_TOO_HIGH;
            SWC_AP_StateMachine_enter_internal_SPACE_FOUND_SPEED_TOO_HIGH_k
              (rtu_IbVBII_VehState_LowSpd,
               rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
               rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else {
            MeAP_cnt_TransDebugVar = 22U;
            if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                KeAP_cnt_ScreenChimeTimeoutDur) {
              tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
                *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
              if (tmp > 65535) {
                tmp = 65535;
              }

              SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
              if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                  KeAP_cnt_ScreenChimeTimeoutDur) {
                *rty_MeAP_b_ChimeActvReqLHFSVM = true;
                *rty_MeAP_b_ChimeActvReqRHFSVM = true;
                *rty_MeAP_b_ChimeActvReqLHRSVM = false;
                *rty_MeAP_b_ChimeActvReqRHRSVM = false;
                *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
                *rty_MeAP_e_PAMChimeRepnRateSVM =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
                *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
              } else {
                *rty_MeAP_b_ChimeActvReqLHFSVM = false;
                *rty_MeAP_b_ChimeActvReqRHFSVM = false;
                *rty_MeAP_b_ChimeActvReqLHRSVM = false;
                *rty_MeAP_b_ChimeActvReqRHRSVM = false;
                *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
                *rty_MeAP_e_PAMChimeRepnRateSVM =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
                *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
              }
            } else {
              *rty_MeAP_b_ChimeActvReqLHFSVM = false;
              *rty_MeAP_b_ChimeActvReqRHFSVM = false;
              *rty_MeAP_b_ChimeActvReqLHRSVM = false;
              *rty_MeAP_b_ChimeActvReqRHRSVM = false;
              *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
              *rty_MeAP_e_PAMChimeRepnRateSVM =
                TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
            }
          }
          break;
        }
      }
    }
  }

  /* End of Constant: '<S8>/Constant' */
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_SPACE_FOUND_STOP_STANDSTILL_i(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* Constant: '<S8>/Constant' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if ((!SWC_AP_StateMachine_B.MeAP_b_ValidSlotAvl) || (((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistL)) && ((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistR)))) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL_a =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
      SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_kx;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
    MeAP_cnt_StateDebugVar = 13U;
    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
    SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_gh
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
       rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    /* MeAP_b_StandStill &&... */
    if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <
        KeAP_kph_StandStillSpdThd) {
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL_a =
        SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
      SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
        SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE_d;
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
      MeAP_cnt_StateDebugVar = 34U;
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
        SWC_AP_StateMachine_IN_Default;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    } else if (SWC_AP_StateMachine_DW.temporalCounter_i1 >= 167U) {
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL_a =
        SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
      SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
        SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
      MeAP_cnt_StateDebugVar = 14U;
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
        SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
        (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
         rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
         rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
         rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
    } else if (SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL_a ==
               SWC_AP_StateMachine_IN_Default) {
      if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
          TeAP_e_FiltdGearState_ReverseGear) {
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL_a =
          SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_on;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
              KeAP_cnt_ScreenChimeTimeoutDur) {
            *rty_MeAP_b_ChimeActvReqLHFSVM = true;
            *rty_MeAP_b_ChimeActvReqRHFSVM = true;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                 KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      /* case IN_SHIFT_TO_DRIVE: */
      if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
          TeAP_e_FiltdGearState_ReverseGear) {
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL_a =
          SWC_AP_StateMachine_IN_Default;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP_STANDSTILL;
        SWC_AP_StateMachine_enter_internal_Default_g
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                 KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    }
  }

  /* End of Constant: '<S8>/Constant' */
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_Scanning_SemiAutoPark(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if ((*rty_MeAP_b_StandStill) &&
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart) {
    SWC_AP_StateMachine_exit_internal_Scanning_SemiAutoPark();
    SWC_AP_StateMachine_DW.is_ParkIn =
      SWC_AP_StateMachine_IN_Handshake_SemiAutoPark;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Handshake;
    MeAP_cnt_StateDebugVar = 47U;
    SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
    SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
    if (SWC_AP_StateMachine_B.MeAP_b_EPSHandshakeActv) {
      SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
        TeAP_e_SPMLatCtrlReqSts_SPM_Request;
    } else {
      SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
        TeAP_e_SPMLatCtrlReqSts_Idle;
    }

    if ((!SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout) &&
        (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts ==
         TeVBII_e_SPMLatCtrlRespSts_HasOpen) &&
        (SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
         TeAP_e_SPMLatCtrlReqSts_SPM_Request)) {
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = true;
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = false;
    }

    if ((SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
         TeAP_e_SPMLatCtrlReqSts_SPM_Request) &&
        (!SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces)) {
      tmp = SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt >
          *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout) {
        SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = true;
        MeAP_cnt_TransDebugVar = 118U;
      } else {
        SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
        MeAP_cnt_TransDebugVar = 117U;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
      SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
      MeAP_cnt_TransDebugVar = 115U;
    }
  } else {
    switch (SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark) {
     case SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_o:
      SWC_AP_StateMachine_PERP_SELECT_LEFT_l
        (rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle,
         rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
         rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
         rtu_IbVBII_VehState_LowSpd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
         rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
         rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
         rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
         rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
         rty_MeAP_e_PAMChimeRepnRateSVM);
      break;

     case SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_FORWARD:
      SWC_AP_StateMachine_PERP_SELECT_LEFT_FORWARD
        (rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
         rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
         rtu_IbVBII_VehState_LowSpd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
         rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
         rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
         rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
         rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
         rty_MeAP_e_PAMChimeRepnRateSVM);
      break;

     case SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_REVERSE:
      /* !MeAP_b_StandStill &&... */
      if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
          KeAP_kph_StandStillSpdThd) {
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 14U;
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
          SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
                 (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
                  &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_PERP_SELECT_LEFT_o;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_LEFT;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        MeAP_cnt_StateDebugVar = 39U;
      } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                  TeAP_e_FiltdGearState_ReverseGear) &&
                 SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
        MeAP_cnt_TransDebugVar = 102U;
      } else {
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
        MeAP_cnt_TransDebugVar = 101U;
      }
      break;

     case SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT:
      SWC_AP_StateMachine_PERP_SELECT_RIGHT_d
        (rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle,
         rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
         rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
         rtu_IbVBII_VehState_LowSpd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
         rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
         rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
         rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
         rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
         rty_MeAP_e_PAMChimeRepnRateSVM);
      break;

     case SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT_FORWARD:
      /* !MeAP_b_StandStill &&... */
      if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
          KeAP_kph_StandStillSpdThd) {
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 14U;
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
          SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
                 (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
                  &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_RIGHT;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        MeAP_cnt_StateDebugVar = 40U;
      } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                  TeAP_e_FiltdGearState_ReverseGear) &&
                 SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
        MeAP_cnt_TransDebugVar = 104U;
      } else {
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
        MeAP_cnt_TransDebugVar = 103U;
      }
      break;

     case SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT_REVERSE:
      /* !MeAP_b_StandStill &&... */
      if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
          KeAP_kph_StandStillSpdThd) {
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 14U;
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
          SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
                 (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
                  &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_RIGHT;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        MeAP_cnt_StateDebugVar = 40U;
      } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                  TeAP_e_FiltdGearState_ReverseGear) &&
                 SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
        MeAP_cnt_TransDebugVar = 106U;
      } else {
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
        MeAP_cnt_TransDebugVar = 105U;
      }
      break;

     case SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_kx:
      SWC_AP_StateMachine_SEARCHING_MOVE_FORWARD_l(rtu_IbVBII_VehState_LowSpd,
        rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
        rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
        rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, rty_MeAP_e_HMIPopUp,
        rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
        rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
        rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
        rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
        rty_MeAP_e_PAMChimeRepnRateSVM);
      break;

     case SWC_AP_StateMachine_IN_SEMI_PARALLEL_REMOVE_HANDS_LEFT:
      /* !MeAP_b_StandStill &&... */
      if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
          KeAP_kph_StandStillSpdThd) {
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 14U;
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
          SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
                 (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
                  &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE_d;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 34U;
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
          SWC_AP_StateMachine_IN_Default;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                  TeAP_e_FiltdGearState_ReverseGear) &&
                 SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
        MeAP_cnt_TransDebugVar = 96U;
      } else {
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
        MeAP_cnt_TransDebugVar = 95U;
      }
      break;

     case SWC_AP_StateMachine_IN_SEMI_PARALLEL_REMOVE_HANDS_RIGHT:
      /* !MeAP_b_StandStill &&... */
      if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
          KeAP_kph_StandStillSpdThd) {
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 14U;
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_k =
          SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP_e
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
                 (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
                  &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
        SWC_AP_StateMachine_DW.is_Scanning_SemiAutoPark =
          SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE_d;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 34U;
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE_b =
          SWC_AP_StateMachine_IN_Default;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                  TeAP_e_FiltdGearState_ReverseGear) &&
                 SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
        MeAP_cnt_TransDebugVar = 98U;
      } else {
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
        MeAP_cnt_TransDebugVar = 97U;
      }
      break;

     case SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE_d:
      SWC_AP_StateMachine_SPACE_FOUND_SELECT_SPACE_h
        (rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
         rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide,
         rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
         rtu_IbVBII_VehState_LowSpd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
         rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
         rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
         rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
         rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
         rty_MeAP_e_PAMChimeRepnRateSVM);
      break;

     case SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_la:
      SWC_AP_StateMachine_SPACE_FOUND_STOP_k
        (rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus,
         rtu_IbVBII_VehState_LowSpd,
         rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
         rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, rty_MeAP_e_HMIPopUp,
         rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
         rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
         rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
         rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
         rty_MeAP_e_PAMChimeRepnRateSVM);
      break;

     default:
      /* case IN_SPACE_FOUND_STOP_STANDSTILL: */
      SWC_AP_StateMachine_SPACE_FOUND_STOP_STANDSTILL_i
        (rtu_IbVBII_VehState_LowSpd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
         rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
         rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
         rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
         rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
         rty_MeAP_e_PAMChimeRepnRateSVM);
      break;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_MOVE_BACKWARD(const boolean_T *rtu_MeAP_b_PosMet,
  const boolean_T *rtu_MeAP_b_SteerActionReq, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const boolean_T *
  rtu_MeAP_b_ObjPrestFC, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
       TeAP_e_FiltdGearState_Drive) && (!*rtu_MeAP_b_ObjPrestFC)) {
    if (!*rtu_MeAP_b_SteerActionReq) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves =
        SWC_AP_StateMachine_IN_MOVE_FORWARD;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_FORWARD;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
      }
    } else {
      SWC_AP_StateMachine_DW.is_MutlipleMoves =
        SWC_AP_StateMachine_IN_WAIT_FOR_STEER_FRONT;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WAIT_FOR_STEER_FRONT;
      MeAP_cnt_StateDebugVar = 54U;
    }
  } else if ((*rtu_MeAP_b_PosMet) && (*rtu_MeAP_e_GearCmd ==
              TeAutoPark_e_GearCmd_Drive)) {
    SWC_AP_StateMachine_DW.is_MutlipleMoves = SWC_AP_StateMachine_IN_STOP_REAR;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_STOP_REAR;
    MeAP_cnt_StateDebugVar = 52U;
    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
        (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_MutlipleMoves(const boolean_T *rtu_MeAP_b_PosMet,
  const boolean_T *rtu_MeAP_b_SteerActionReq, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const boolean_T *
  rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  boolean_T tmp_0;
  switch (SWC_AP_StateMachine_DW.is_MutlipleMoves) {
   case SWC_AP_StateMachine_IN_MOVE_BACKWARD:
    SWC_AP_StateMachine_MOVE_BACKWARD(rtu_MeAP_b_PosMet,
      rtu_MeAP_b_SteerActionReq, rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rtu_MeAP_b_ObjPrestFC,
      rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
      rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
      rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
      rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
    break;

   case SWC_AP_StateMachine_IN_MOVE_FORWARD:
    if ((*rtu_MeAP_b_PosMet) && (*rtu_MeAP_e_GearCmd ==
         TeAutoPark_e_GearCmd_Reverse)) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves =
        SWC_AP_StateMachine_IN_STOP_FRONT;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_STOP_FRONT;
      MeAP_cnt_StateDebugVar = 56U;
      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      tmp_0 = !*rtu_MeAP_b_ObjPrestRC;
      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
           TeAP_e_FiltdGearState_ReverseGear) && tmp_0 &&
          (*rtu_MeAP_b_SteerActionReq)) {
        SWC_AP_StateMachine_DW.is_MutlipleMoves =
          SWC_AP_StateMachine_IN_WAIT_FOR_STEER_REAR_o;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR;
        MeAP_cnt_StateDebugVar = 58U;
      } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                  TeAP_e_FiltdGearState_ReverseGear) && tmp_0 &&
                 (!*rtu_MeAP_b_SteerActionReq)) {
        SWC_AP_StateMachine_DW.is_MutlipleMoves =
          SWC_AP_StateMachine_IN_MOVE_BACKWARD;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_BACKWARD;
        MeAP_cnt_StateDebugVar = 51U;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
        if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
        }
      } else {
        if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
        }
      }
    }
    break;

   case SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_GUIDANCE:
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_Drive) && (*rtu_MeAP_b_SteerActionReq)) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves =
        SWC_AP_StateMachine_IN_WAIT_FOR_STEER_FRONT;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WAIT_FOR_STEER_FRONT;
      MeAP_cnt_StateDebugVar = 54U;
    } else {
      /*   */
      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
           TeAP_e_FiltdGearState_Drive) && (!*rtu_MeAP_b_SteerActionReq)) {
        SWC_AP_StateMachine_DW.is_MutlipleMoves =
          SWC_AP_StateMachine_IN_MOVE_FORWARD;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_FORWARD;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
        if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
        }
      }
    }
    break;

   case SWC_AP_StateMachine_IN_SHIFT_TO_REVERSE:
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_ReverseGear) && (*rtu_MeAP_b_SteerActionReq)) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves =
        SWC_AP_StateMachine_IN_WAIT_FOR_STEER_REAR_o;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR;
      MeAP_cnt_StateDebugVar = 58U;
    } else {
      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
           TeAP_e_FiltdGearState_ReverseGear) && (!*rtu_MeAP_b_SteerActionReq))
      {
        SWC_AP_StateMachine_DW.is_MutlipleMoves =
          SWC_AP_StateMachine_IN_MOVE_BACKWARD;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_BACKWARD;
        MeAP_cnt_StateDebugVar = 51U;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
        if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
        }
      }
    }
    break;

   case SWC_AP_StateMachine_IN_STOP_FRONT:
    if (*rty_MeAP_b_StandStill) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves =
        SWC_AP_StateMachine_IN_SHIFT_TO_REVERSE;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_REVERSE;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      MeAP_cnt_StateDebugVar = 57U;
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
               KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
    break;

   case SWC_AP_StateMachine_IN_STOP_REAR:
    if (*rty_MeAP_b_StandStill) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves =
        SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_GUIDANCE;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE_GUIDANCE;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      MeAP_cnt_StateDebugVar = 53U;
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
               KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
    break;

   case SWC_AP_StateMachine_IN_WAIT_FOR_STEER_FRONT:
    if (!*rtu_MeAP_b_SteerActionReq) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves =
        SWC_AP_StateMachine_IN_MOVE_FORWARD;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_FORWARD;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
      }
    }
    break;

   default:
    /* case IN_WAIT_FOR_STEER_REAR: */
    if (!*rtu_MeAP_b_SteerActionReq) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves =
        SWC_AP_StateMachine_IN_MOVE_BACKWARD;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_BACKWARD;
      MeAP_cnt_StateDebugVar = 51U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
      }
    }
    break;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_DISCLAIMER(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* !MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_DISCLAIMER =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_b_InitBrkPedlPressed = false;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
              ParkingSlotType_E_PW_PARALLEL)) {
    SWC_AP_StateMachine_DW.is_DISCLAIMER =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_b_InitBrkPedlPressed = true;
    MeAP_cnt_StateDebugVar = 16U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
      SWC_AP_StateMachine_IN_Default;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
              ParkingSlotType_E_PW_PERPENDICULAR) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide ==
              SlotSide_E_SLOT_LEFT) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_DISCLAIMER =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_PERP_SELECT_LEFT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
    SWC_AP_StateMachine_DW.is_PERP_SELECT_LEFT = SWC_AP_StateMachine_IN_Default;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_LEFT;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
              ParkingSlotType_E_PW_PERPENDICULAR) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide ==
              SlotSide_E_SLOT_RIGHT) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_DISCLAIMER =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
    SWC_AP_StateMachine_DW.is_PERP_SELECT_RIGHT = SWC_AP_StateMachine_IN_Default;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_RIGHT;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  } else if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed) {
    SWC_AP_StateMachine_DW.is_DISCLAIMER =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_HandshakeStart;
    SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart = true;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    MeAP_cnt_StateDebugVar = 18U;
  } else if (SWC_AP_StateMachine_DW.is_DISCLAIMER ==
             SWC_AP_StateMachine_IN_Default) {
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_DISCLAIMER =
        SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_on;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else if (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
               ParkingSlotType_E_PW_PARALLEL) {
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_ParallelParking;
      MeAP_cnt_TransDebugVar = 32U;
    } else {
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
      MeAP_cnt_TransDebugVar = 31U;
    }
  } else {
    /* case IN_SHIFT_TO_DRIVE: */
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_DISCLAIMER = SWC_AP_StateMachine_IN_Default;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_DISCLAIMER;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      if (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
          ParkingSlotType_E_PW_PARALLEL) {
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_ParallelParking;
        MeAP_cnt_TransDebugVar = 32U;
      } else {
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
        MeAP_cnt_TransDebugVar = 31U;
      }
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
               KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_DISCLAIMER(const
  ParkingSlotType_t *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat
  *rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  SWC_AP_StateMachine_DW.is_DISCLAIMER = SWC_AP_StateMachine_IN_Default;
  *rty_IeAP_b_VehMnvrDirSPM = true;

  /* false = Backward, true= Forward  */
  *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_DISCLAIMER;
  *rty_MeAP_b_ChimeActvReqLHFSVM = false;
  *rty_MeAP_b_ChimeActvReqRHFSVM = false;
  *rty_MeAP_b_ChimeActvReqLHRSVM = false;
  *rty_MeAP_b_ChimeActvReqRHRSVM = false;
  *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
  *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
  *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  if (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
      ParkingSlotType_E_PW_PARALLEL) {
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_ParallelParking;
    MeAP_cnt_TransDebugVar = 32U;
  } else {
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
    MeAP_cnt_TransDebugVar = 31U;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_PERP_SELECT_LEFT(const TeAutoPark_e_ParkStyle
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* !MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_PERP_SELECT_LEFT =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_b_InitBrkPedlPressed = false;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if (((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle ==
               TeAutoPark_e_ParkStyle_Front_In) ||
              (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle ==
               TeAutoPark_e_ParkStyle_Rear_In)) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_PERP_SELECT_LEFT =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_DISCLAIMER;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_DISCLAIMER;
    MeAP_cnt_StateDebugVar = 17U;
    SWC_AP_StateMachine_enter_internal_DISCLAIMER
      (rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, rty_MeAP_e_HMIPopUp,
       rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_PERP_SELECT_LEFT =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_b_InitBrkPedlPressed = true;
    MeAP_cnt_StateDebugVar = 16U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
      SWC_AP_StateMachine_IN_Default;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  } else if (SWC_AP_StateMachine_DW.is_PERP_SELECT_LEFT ==
             SWC_AP_StateMachine_IN_Default) {
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_PERP_SELECT_LEFT =
        SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_on;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    }
  } else {
    /* case IN_SHIFT_TO_DRIVE: */
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_PERP_SELECT_LEFT =
        SWC_AP_StateMachine_IN_Default;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_LEFT;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
               KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_PERP_SELECT_RIGHT(const TeAutoPark_e_ParkStyle
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* !MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_PERP_SELECT_RIGHT =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_b_InitBrkPedlPressed = false;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if (((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle ==
               TeAutoPark_e_ParkStyle_Front_In) ||
              (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle ==
               TeAutoPark_e_ParkStyle_Rear_In)) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_PERP_SELECT_RIGHT =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_DISCLAIMER;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_DISCLAIMER;
    MeAP_cnt_StateDebugVar = 17U;
    SWC_AP_StateMachine_enter_internal_DISCLAIMER
      (rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, rty_MeAP_e_HMIPopUp,
       rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_PERP_SELECT_RIGHT =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_b_InitBrkPedlPressed = true;
    MeAP_cnt_StateDebugVar = 16U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
      SWC_AP_StateMachine_IN_Default;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  } else if (SWC_AP_StateMachine_DW.is_PERP_SELECT_RIGHT ==
             SWC_AP_StateMachine_IN_Default) {
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_PERP_SELECT_RIGHT =
        SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_on;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    }
  } else {
    /* case IN_SHIFT_TO_DRIVE: */
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_PERP_SELECT_RIGHT =
        SWC_AP_StateMachine_IN_Default;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_RIGHT;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
               KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void
  SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
       *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) &&
      (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt <=
       *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur)) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = (uint16_T)tmp;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH;
    if (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur) {
      SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = true;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
  }

  if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt <=
      *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
      SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = true;
      MeAP_cnt_TransDebugVar = 20U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
      MeAP_cnt_TransDebugVar = 19U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
    MeAP_cnt_TransDebugVar = 17U;
  }

  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_SEARCHING_MOVE_FORWARD(const TbVBIA_VehState_AP *
  rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* Constant: '<S8>/Constant' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if (SWC_AP_StateMachine_B.MeAP_b_ValidSlotAvl && ((true &&
        SWC_AP_StateMachine_B.MeAP_e_b_PSExistL) || (true &&
        SWC_AP_StateMachine_B.MeAP_e_b_PSExistR)) &&
      (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
       TeAP_e_FiltdGearState_ReverseGear)) {
    SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_b_InitBrkPedlPressed = false;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    switch (SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD) {
     case SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_k:
      if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
          TeAP_e_FiltdGearState_ReverseGear) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD =
          SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
        SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
        SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
                 *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD =
          SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
        SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH
          (rtu_IbVBII_VehState_LowSpd,
           rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
           rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, rty_MeAP_e_HMIPopUp,
           rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
           rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
           rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
           rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt <=
                 *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
          SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = true;
          MeAP_cnt_TransDebugVar = 20U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
          MeAP_cnt_TransDebugVar = 19U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
        MeAP_cnt_TransDebugVar = 17U;
      }
      break;

     case SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH:
      if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
          TeAP_e_FiltdGearState_ReverseGear) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD =
          SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
        SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
        SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
                 *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD =
          SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_k;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_g
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur);
      } else {
        if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
             *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) &&
            (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt <=
             *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = (uint16_T)tmp;
          *rty_MeAP_e_HMIPopUp =
            TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH;
          if (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur) {
            SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = true;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
        }

        if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt <=
            *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur) {
            SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = true;
            MeAP_cnt_TransDebugVar = 20U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
            MeAP_cnt_TransDebugVar = 19U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
          MeAP_cnt_TransDebugVar = 17U;
        }

        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
              KeAP_cnt_ScreenChimeTimeoutDur) {
            *rty_MeAP_b_ChimeActvReqLHFSVM = true;
            *rty_MeAP_b_ChimeActvReqRHFSVM = true;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      }
      break;

     default:
      /* case IN_SHIFT_TO_DRIVE: */
      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
           TeAP_e_FiltdGearState_ReverseGear) &&
          (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
           *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd)) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD =
          SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_k;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_g
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur);
      } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
                  TeAP_e_FiltdGearState_ReverseGear) &&
                 (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
                  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd)) {
        SWC_AP_StateMachine_DW.is_SEARCHING_MOVE_FORWARD =
          SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
        SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH
          (rtu_IbVBII_VehState_LowSpd,
           rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
           rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, rty_MeAP_e_HMIPopUp,
           rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
           rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
           rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
           rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                 KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
      break;
    }
  }

  /* End of Constant: '<S8>/Constant' */
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_SPACE_FOUND_SELECT_SPACE(const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* !MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_b_InitBrkPedlPressed = false;
    MeAP_cnt_StateDebugVar = 14U;
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
      SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
    SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
              ParkingSlotType_E_PW_PARALLEL) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_DISCLAIMER;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_DISCLAIMER;
    MeAP_cnt_StateDebugVar = 17U;
    SWC_AP_StateMachine_enter_internal_DISCLAIMER
      (rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, rty_MeAP_e_HMIPopUp,
       rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
              ParkingSlotType_E_PW_PERPENDICULAR) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide ==
              SlotSide_E_SLOT_LEFT) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_PERP_SELECT_LEFT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
    SWC_AP_StateMachine_DW.is_PERP_SELECT_LEFT = SWC_AP_StateMachine_IN_Default;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_LEFT;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType ==
              ParkingSlotType_E_PW_PERPENDICULAR) &&
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide ==
              SlotSide_E_SLOT_RIGHT) && uMultiWordNe
             (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
              &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_PerpendicularParking;
    SWC_AP_StateMachine_DW.is_PERP_SELECT_RIGHT = SWC_AP_StateMachine_IN_Default;
    *rty_IeAP_b_VehMnvrDirSPM = true;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PERP_SELECT_RIGHT;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  } else if (SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE ==
             SWC_AP_StateMachine_IN_Default) {
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
        SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_on;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    }
  } else {
    /* case IN_SHIFT_TO_DRIVE: */
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
        SWC_AP_StateMachine_IN_Default;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
               KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_p(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_SPACE_FOUND_SPEED_TOO_HIGH(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  MeAP_cnt_StateDebugVar = 21U;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
      *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur) {
      SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = true;
      MeAP_cnt_TransDebugVar = 26U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
      MeAP_cnt_TransDebugVar = 25U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
    MeAP_cnt_TransDebugVar = 23U;
  }

  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_Default(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_SPACE_FOUND_STOP(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* Constant: '<S8>/Constant' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if ((!SWC_AP_StateMachine_B.MeAP_b_ValidSlotAvl) || (((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistL)) && ((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistR)))) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
    MeAP_cnt_StateDebugVar = 13U;
    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
    SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
       rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    /* !MeAP_b_StandStill &&... */
    if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
         KeAP_kph_StandStillSpdThd) &&
        (*rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus)) {
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
        SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
      SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
        SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_STANDSTILL;
      SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
      MeAP_b_InitBrkPedlPressed = false;
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL =
        SWC_AP_StateMachine_IN_Default;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP_STANDSTILL;
      SWC_AP_StateMachine_enter_internal_Default
        (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
         rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
         rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
         rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
    } else {
      /* MeAP_b_StandStill &&... */
      if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <
          KeAP_kph_StandStillSpdThd) {
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
          SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
        SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
          SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_b_InitBrkPedlPressed = true;
        MeAP_cnt_StateDebugVar = 16U;
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
          SWC_AP_StateMachine_IN_Default;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      } else {
        switch (SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP) {
         case SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_o:
          if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
               TeAP_e_FiltdGearState_ReverseGear) &&
              (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
               *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd)) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
              SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
            *rty_IeAP_b_VehMnvrDirSPM = true;

            /* false = Backward, true= Forward  */
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
            SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP
              (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
                      TeAP_e_FiltdGearState_ReverseGear) &&
                     (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
                      *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd)) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
              SWC_AP_StateMachine_IN_SPACE_FOUND_SPEED_TOO_HIGH;
            *rty_IeAP_b_VehMnvrDirSPM = true;

            /* false = Backward, true= Forward  */
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SPEED_TOO_HIGH;
            SWC_AP_StateMachine_enter_internal_SPACE_FOUND_SPEED_TOO_HIGH
              (rtu_IbVBII_VehState_LowSpd,
               rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
               rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                     KeAP_cnt_ScreenChimeTimeoutDur) {
            tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
              *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
            if (tmp > 65535) {
              tmp = 65535;
            }

            SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
            if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                KeAP_cnt_ScreenChimeTimeoutDur) {
              *rty_MeAP_b_ChimeActvReqLHFSVM = true;
              *rty_MeAP_b_ChimeActvReqRHFSVM = true;
              *rty_MeAP_b_ChimeActvReqLHRSVM = false;
              *rty_MeAP_b_ChimeActvReqRHRSVM = false;
              *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
              *rty_MeAP_e_PAMChimeRepnRateSVM =
                TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
            } else {
              *rty_MeAP_b_ChimeActvReqLHFSVM = false;
              *rty_MeAP_b_ChimeActvReqRHFSVM = false;
              *rty_MeAP_b_ChimeActvReqLHRSVM = false;
              *rty_MeAP_b_ChimeActvReqRHRSVM = false;
              *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
              *rty_MeAP_e_PAMChimeRepnRateSVM =
                TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
            }
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
          break;

         case SWC_AP_StateMachine_IN_SPACE_FOUND_SPEED_TOO_HIGH:
          if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
              TeAP_e_FiltdGearState_ReverseGear) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
              SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_o;
            *rty_IeAP_b_VehMnvrDirSPM = false;

            /* false = Backward, true= Forward  */
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
            SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_p
              (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
                     *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
              SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
            *rty_IeAP_b_VehMnvrDirSPM = true;

            /* false = Backward, true= Forward  */
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
            SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP
              (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else {
            if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
                *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
              tmp = SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt +
                *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
              if (tmp > 65535) {
                tmp = 65535;
              }

              SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = (uint16_T)tmp;
              if (SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt >
                  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur) {
                SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = true;
                MeAP_cnt_TransDebugVar = 26U;
              } else {
                SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
                MeAP_cnt_TransDebugVar = 25U;
              }
            } else {
              SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
              SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
              MeAP_cnt_TransDebugVar = 23U;
            }

            if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                KeAP_cnt_ScreenChimeTimeoutDur) {
              tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
                *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
              if (tmp > 65535) {
                tmp = 65535;
              }

              SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
              if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                  KeAP_cnt_ScreenChimeTimeoutDur) {
                *rty_MeAP_b_ChimeActvReqLHFSVM = true;
                *rty_MeAP_b_ChimeActvReqRHFSVM = true;
                *rty_MeAP_b_ChimeActvReqLHRSVM = false;
                *rty_MeAP_b_ChimeActvReqRHRSVM = false;
                *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
                *rty_MeAP_e_PAMChimeRepnRateSVM =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
                *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
              } else {
                *rty_MeAP_b_ChimeActvReqLHFSVM = false;
                *rty_MeAP_b_ChimeActvReqRHFSVM = false;
                *rty_MeAP_b_ChimeActvReqLHRSVM = false;
                *rty_MeAP_b_ChimeActvReqRHRSVM = false;
                *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
                *rty_MeAP_e_PAMChimeRepnRateSVM =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
                *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
              }
            } else {
              *rty_MeAP_b_ChimeActvReqLHFSVM = false;
              *rty_MeAP_b_ChimeActvReqRHFSVM = false;
              *rty_MeAP_b_ChimeActvReqLHRSVM = false;
              *rty_MeAP_b_ChimeActvReqRHRSVM = false;
              *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
              *rty_MeAP_e_PAMChimeRepnRateSVM =
                TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
            }
          }
          break;

         default:
          /* case IN_SPACE_FOUND_STOP: */
          if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
              TeAP_e_FiltdGearState_ReverseGear) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
              SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_o;
            *rty_IeAP_b_VehMnvrDirSPM = false;

            /* false = Backward, true= Forward  */
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
            SWC_AP_StateMachine_enter_internal_SHIFT_TO_DRIVE_p
              (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
                     *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd) {
            SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
              SWC_AP_StateMachine_IN_SPACE_FOUND_SPEED_TOO_HIGH;
            *rty_IeAP_b_VehMnvrDirSPM = true;

            /* false = Backward, true= Forward  */
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SPEED_TOO_HIGH;
            SWC_AP_StateMachine_enter_internal_SPACE_FOUND_SPEED_TOO_HIGH
              (rtu_IbVBII_VehState_LowSpd,
               rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
               rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur,
               rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
               rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
               rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
               rty_MeAP_e_PAMChimeRepnRateSVM);
          } else {
            MeAP_cnt_TransDebugVar = 22U;
            if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                KeAP_cnt_ScreenChimeTimeoutDur) {
              tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
                *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
              if (tmp > 65535) {
                tmp = 65535;
              }

              SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
              if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                  KeAP_cnt_ScreenChimeTimeoutDur) {
                *rty_MeAP_b_ChimeActvReqLHFSVM = true;
                *rty_MeAP_b_ChimeActvReqRHFSVM = true;
                *rty_MeAP_b_ChimeActvReqLHRSVM = false;
                *rty_MeAP_b_ChimeActvReqRHRSVM = false;
                *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
                *rty_MeAP_e_PAMChimeRepnRateSVM =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
                *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
              } else {
                *rty_MeAP_b_ChimeActvReqLHFSVM = false;
                *rty_MeAP_b_ChimeActvReqRHFSVM = false;
                *rty_MeAP_b_ChimeActvReqLHRSVM = false;
                *rty_MeAP_b_ChimeActvReqRHRSVM = false;
                *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
                *rty_MeAP_e_PAMChimeRepnRateSVM =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
                *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
              }
            } else {
              *rty_MeAP_b_ChimeActvReqLHFSVM = false;
              *rty_MeAP_b_ChimeActvReqRHFSVM = false;
              *rty_MeAP_b_ChimeActvReqLHRSVM = false;
              *rty_MeAP_b_ChimeActvReqRHRSVM = false;
              *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
              *rty_MeAP_e_PAMChimeRepnRateSVM =
                TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
            }
          }
          break;
        }
      }
    }
  }

  /* End of Constant: '<S8>/Constant' */
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_SPACE_FOUND_STOP_STANDSTILL(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* Constant: '<S8>/Constant' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  if ((!SWC_AP_StateMachine_B.MeAP_b_ValidSlotAvl) || (((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistL)) && ((!true) ||
        (!SWC_AP_StateMachine_B.MeAP_e_b_PSExistR)))) {
    SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
      SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
    MeAP_cnt_StateDebugVar = 13U;
    SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
    SWC_AP_StateMachine_enter_internal_SEARCHING_MOVE_FORWARD
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
       rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    /* MeAP_b_StandStill &&... */
    if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <
        KeAP_kph_StandStillSpdThd) {
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL =
        SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
      SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
        SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE;
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
      MeAP_b_InitBrkPedlPressed = true;
      MeAP_cnt_StateDebugVar = 16U;
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_SELECT_SPACE =
        SWC_AP_StateMachine_IN_Default;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    } else if (SWC_AP_StateMachine_DW.temporalCounter_i1 >= 167U) {
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL =
        SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
      SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark =
        SWC_AP_StateMachine_IN_SPACE_FOUND_STOP;
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
      MeAP_b_InitBrkPedlPressed = false;
      MeAP_cnt_StateDebugVar = 14U;
      SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP =
        SWC_AP_StateMachine_IN_SPACE_FOUND_STOP_l;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP;
      SWC_AP_StateMachine_enter_internal_SPACE_FOUND_STOP
        (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
         rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
         rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
         rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
    } else if (SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL ==
               SWC_AP_StateMachine_IN_Default) {
      if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
          TeAP_e_FiltdGearState_ReverseGear) {
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL =
          SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_on;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
              KeAP_cnt_ScreenChimeTimeoutDur) {
            *rty_MeAP_b_ChimeActvReqLHFSVM = true;
            *rty_MeAP_b_ChimeActvReqRHFSVM = true;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                 KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      /* case IN_SHIFT_TO_DRIVE: */
      if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
          TeAP_e_FiltdGearState_ReverseGear) {
        SWC_AP_StateMachine_DW.is_SPACE_FOUND_STOP_STANDSTILL =
          SWC_AP_StateMachine_IN_Default;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPACE_FOUND_STOP_STANDSTILL;
        SWC_AP_StateMachine_enter_internal_Default
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                 KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    }
  }

  /* End of Constant: '<S8>/Constant' */
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_ParkIn(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const TeAP_e_UsrPPPAManeuverSel
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const boolean_T
  *rtu_MeAP_b_PosMet, const boolean_T *rtu_MeAP_b_SteerActionReq, const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TbNVM_ProxyCalibParam
  *rtu_MbNVM_ProxyParam, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd, const
  boolean_T *rtu_MeAP_b_ObjInPath, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_InterfaceBSM *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv
  *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel ==
       TeAP_e_UsrPPPAManeuverSel_ParkExit) && (MeAutoPark_e_AlgoState !=
       TeAP_e_AlgoState_Park_In) && rtu_MbNVM_ProxyParam->KeAP_b_PullOutCtrlPres)
  {
    SWC_AP_StateMachine_exit_internal_ParkIn();
    SWC_AP_StateMachine_DW.is_ACTIVE_AUTOPARK = SWC_AP_StateMachine_IN_Park_Exit;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart = false;
    SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    SWC_AP_StateMachine_enter_internal_Park_Exit(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_IeAP_e_ParKMnvrActv,
      rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat, rty_MeAP_e_PAMVolSigSVM,
      rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
      rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
      rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    switch (SWC_AP_StateMachine_DW.is_ParkIn) {
     case SWC_AP_StateMachine_IN_Active_FullAutoPark:
      SWC_AP_StateMachine_Active_FullAutoPark(rtu_IbVBII_VehState_LowSpd,
        rtu_MeAP_e_GearCmd, rtu_MeAP_b_ObjInPath,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
        rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
        rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur,
        rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
        rtu_IeAP_kph_TrgtVehSpd, rtu_IeAP_cm_TrgtDist, rty_MeAP_e_HMIPopUp,
        rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_b_VCOpPaused, rty_IeAP_e_GearShiftReq,
        rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
        rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
        rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
        rty_MeAP_e_PAMChimeRepnRateSVM, rty_MeAP_b_StandStill);
      break;

     case SWC_AP_StateMachine_IN_Active_SemiAutoPark:
      if ((SWC_AP_StateMachine_DW.MeAP_cnt_Move > 0) && (*rtu_MeAP_e_GearCmd ==
           TeAutoPark_e_GearCmd_Park)) {
        SWC_AP_StateMachine_DW.is_MutlipleMoves =
          SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
        SWC_AP_StateMachine_DW.is_Active_SemiAutoPark =
          SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
        SWC_AP_StateMachine_DW.is_ParkIn =
          SWC_AP_StateMachine_IN_Complete_SemiAutoPark;
        SWC_AP_StateMachine_DW.MeAP_b_VehicleParked = true;

        /* No req to show screen which informs user to shift gear to Park */
      } else if (SWC_AP_StateMachine_DW.is_Active_SemiAutoPark ==
                 SWC_AP_StateMachine_IN_MutlipleMoves) {
        SWC_AP_StateMachine_MutlipleMoves(rtu_MeAP_b_PosMet,
          rtu_MeAP_b_SteerActionReq, rtu_IbVBII_VehState_LowSpd,
          rtu_MeAP_e_GearCmd, rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
          rtu_MeAP_b_ObjPrestFC, rtu_MeAP_b_ObjPrestRC, rty_MeAP_e_HMIPopUp,
          rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
          rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
          rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
          rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM,
          rty_MeAP_b_StandStill);
      } else {
        /* case IN_WAIT_FOR_STEER_REAR: */
        if (!*rtu_MeAP_b_SteerActionReq) {
          SWC_AP_StateMachine_DW.is_Active_SemiAutoPark =
            SWC_AP_StateMachine_IN_MutlipleMoves;
          SWC_AP_StateMachine_DW.is_MutlipleMoves =
            SWC_AP_StateMachine_IN_MOVE_BACKWARD;
          *rty_IeAP_b_VehMnvrDirSPM = false;

          /* false = Backward, true= Forward  */
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_BACKWARD;
          MeAP_cnt_StateDebugVar = 51U;
          SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
          if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) && (
               !SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
            tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
            if (tmp > 255) {
              tmp = 255;
            }

            SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
            SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
          }
        }
      }
      break;

     case SWC_AP_StateMachine_IN_Complete_FullAutoPark:
      if ((*rty_MeAP_b_StandStill) && (*rtu_IeAP_kph_TrgtVehSpd < 1.0E-5F) &&
          (*rtu_IeAP_cm_TrgtDist < 1.0E-5F)) {
        if (!MeAP_b_GearShiftReqWaitTimeout) {
          tmp = MeAP_s_GearShiftReqWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          MeAP_s_GearShiftReqWaitCnt = (uint16_T)tmp;
          if (MeAP_s_GearShiftReqWaitCnt > KeAP_s_GearShiftReqWaitCnt) {
            MeAP_b_GearShiftReqWaitTimeout = true;
            *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_P;
            MeAP_cnt_TransDebugVar = 2003U;
          } else {
            MeAP_b_GearShiftReqWaitTimeout = false;
            *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
            MeAP_cnt_TransDebugVar = 2002U;
          }
        } else {
          *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_P;
          MeAP_cnt_TransDebugVar = 2001U;
        }
      } else {
        MeAP_s_GearShiftReqWaitCnt = 0U;
        MeAP_b_GearShiftReqWaitTimeout = false;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
        MeAP_cnt_TransDebugVar = 2000U;
      }

      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
           TeAP_e_FiltdGearState_Parking) ||
          (rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts ==
           TeVBII_e_VehEPBSts_Applied)) {
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
        SWC_AP_StateMachine_DW.MeAP_b_VehicleParked = true;
      }
      break;

     case SWC_AP_StateMachine_IN_Complete_SemiAutoPark:
      break;

     case SWC_AP_StateMachine_IN_Handshake_FullAutoPark:
      SWC_AP_StateMachine_Handshake_FullAutoPark(rtu_IbVBII_VehState_LowSpd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
        rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout,
        rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout,
        rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
        rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt,
        rty_IeAP_e_InterfaceBSM, rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp,
        rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_b_VCOpPaused,
        rty_IeAP_e_GearShiftReq, rty_MeAP_e_PAMVolSigSVM,
        rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
        rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
        rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM,
        rty_MeAP_b_StandStill);
      break;

     case SWC_AP_StateMachine_IN_Handshake_SemiAutoPark:
      if (SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces) {
        SWC_AP_StateMachine_DW.is_ParkIn =
          SWC_AP_StateMachine_IN_Active_SemiAutoPark;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Park_In;
        *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Engaged_Semi;
        MeAP_cnt_StateDebugVar = 48U;
        if (!*rtu_MeAP_b_SteerActionReq) {
          SWC_AP_StateMachine_DW.is_Active_SemiAutoPark =
            SWC_AP_StateMachine_IN_MutlipleMoves;
          SWC_AP_StateMachine_DW.is_MutlipleMoves =
            SWC_AP_StateMachine_IN_MOVE_BACKWARD;
          *rty_IeAP_b_VehMnvrDirSPM = false;

          /* false = Backward, true= Forward  */
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_BACKWARD;
          MeAP_cnt_StateDebugVar = 51U;
          SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
          if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) && (
               !SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
            tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
            if (tmp > 255) {
              tmp = 255;
            }

            SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
            SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
          }
        } else {
          SWC_AP_StateMachine_DW.is_Active_SemiAutoPark =
            SWC_AP_StateMachine_IN_WAIT_FOR_STEER_REAR;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR;
        }
      } else if (!*rty_MeAP_b_StandStill) {
        SWC_AP_StateMachine_DW.is_ParkIn =
          SWC_AP_StateMachine_IN_Scanning_SemiAutoPark;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Scanning;
        *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Enabled_Seeking;
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
        SWC_AP_StateMachine_enter_internal_Scanning_SemiAutoPark
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
           rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
           rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
           rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
           rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
           rty_MeAP_e_PAMChimeRepnRateSVM);
      } else {
        if (SWC_AP_StateMachine_B.MeAP_b_EPSHandshakeActv) {
          SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
            TeAP_e_SPMLatCtrlReqSts_SPM_Request;
        } else {
          SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
            TeAP_e_SPMLatCtrlReqSts_Idle;
        }

        if ((!SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout) &&
            (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts ==
             TeVBII_e_SPMLatCtrlRespSts_HasOpen) &&
            (SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
             TeAP_e_SPMLatCtrlReqSts_SPM_Request)) {
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = true;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = false;
        }

        if ((SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
             TeAP_e_SPMLatCtrlReqSts_SPM_Request) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout) {
            SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = true;
            MeAP_cnt_TransDebugVar = 118U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
            MeAP_cnt_TransDebugVar = 117U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
          MeAP_cnt_TransDebugVar = 115U;
        }
      }
      break;

     case SWC_AP_StateMachine_IN_Scanning_FullAutoPark:
      if ((*rty_MeAP_b_StandStill) &&
          SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart) {
        SWC_AP_StateMachine_exit_internal_Scanning_FullAutoPark();
        SWC_AP_StateMachine_DW.is_ParkIn =
          SWC_AP_StateMachine_IN_Handshake_FullAutoPark;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Handshake;
        SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark =
          SWC_AP_StateMachine_IN_BSM_Handshake;
        SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
        SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout = false;
        MeAP_cnt_StateDebugVar = 33U;
        if (SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeActv) {
          *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_CVPAM_Request;
        } else {
          *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
        }

        if ((!SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout) &&
            (*rty_IeAP_e_InterfaceBSM == TeAP_e_InterfaceBSM_CVPAM_Request) &&
            (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts ==
             TeVBII_e_ParkingIntrvntionSts_Active)) {
          SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces = true;
          SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeSts = true;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces = false;
        }

        if ((*rty_IeAP_e_InterfaceBSM == TeAP_e_InterfaceBSM_CVPAM_Request) && (
             !SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout) {
            SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = true;
            MeAP_cnt_TransDebugVar = 42U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
            MeAP_cnt_TransDebugVar = 41U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
          MeAP_cnt_TransDebugVar = 39U;
        }
      } else {
        switch (SWC_AP_StateMachine_DW.is_Scanning_FullAutoPark) {
         case SWC_AP_StateMachine_IN_DISCLAIMER:
          SWC_AP_StateMachine_DISCLAIMER
            (rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
             rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
             rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide,
             rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
             rtu_IbVBII_VehState_LowSpd,
             rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
             rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
             rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
             rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
             rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
             rty_MeAP_e_PAMChimeRepnRateSVM);
          break;

         case SWC_AP_StateMachine_IN_HandshakeStart:
          break;

         case SWC_AP_StateMachine_IN_PERP_SELECT_LEFT:
          SWC_AP_StateMachine_PERP_SELECT_LEFT
            (rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle,
             rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
             rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
             rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
             rtu_IbVBII_VehState_LowSpd,
             rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
             rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
             rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
             rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
             rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
             rty_MeAP_e_PAMChimeRepnRateSVM);
          break;

         case SWC_AP_StateMachine_IN_PERP_SELECT_RIGHT:
          SWC_AP_StateMachine_PERP_SELECT_RIGHT
            (rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle,
             rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
             rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
             rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
             rtu_IbVBII_VehState_LowSpd,
             rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
             rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
             rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
             rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
             rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
             rty_MeAP_e_PAMChimeRepnRateSVM);
          break;

         case SWC_AP_StateMachine_IN_SEARCHING_MOVE_FORWARD:
          SWC_AP_StateMachine_SEARCHING_MOVE_FORWARD(rtu_IbVBII_VehState_LowSpd,
            rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
            rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
            rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
            rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, rty_MeAP_e_HMIPopUp,
            rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
            rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
            rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
            rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
            rty_MeAP_e_PAMChimeRepnRateSVM);
          break;

         case SWC_AP_StateMachine_IN_SPACE_FOUND_SELECT_SPACE:
          SWC_AP_StateMachine_SPACE_FOUND_SELECT_SPACE
            (rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
             rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide,
             rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
             rtu_IbVBII_VehState_LowSpd,
             rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
             rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
             rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
             rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
             rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
             rty_MeAP_e_PAMChimeRepnRateSVM);
          break;

         case SWC_AP_StateMachine_IN_SPACE_FOUND_STOP:
          SWC_AP_StateMachine_SPACE_FOUND_STOP
            (rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus,
             rtu_IbVBII_VehState_LowSpd,
             rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
             rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
             rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
             rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, rty_MeAP_e_HMIPopUp,
             rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
             rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
             rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
             rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
             rty_MeAP_e_PAMChimeRepnRateSVM);
          break;

         default:
          /* case IN_SPACE_FOUND_STOP_STANDSTILL: */
          SWC_AP_StateMachine_SPACE_FOUND_STOP_STANDSTILL
            (rtu_IbVBII_VehState_LowSpd,
             rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
             rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
             rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat,
             rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
             rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
             rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
             rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
          break;
        }
      }
      break;

     default:
      /* case IN_Scanning_SemiAutoPark: */
      SWC_AP_StateMachine_Scanning_SemiAutoPark
        (rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus,
         rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle,
         rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
         rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
         rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide,
         rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
         rtu_IbVBII_VehState_LowSpd,
         rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout,
         rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
         rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, rty_MeAP_e_HMIPopUp,
         rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
         rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
         rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
         rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
         rty_MeAP_e_PAMChimeRepnRateSVM, rty_MeAP_b_StandStill);
      break;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_inner_default_FULL_AUTO_ACTIVE_FRONT(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if ((*rtu_MeAP_e_GearCmd == TeAutoPark_e_GearCmd_Reverse) &&
      (*rty_MeAP_b_StandStill)) {
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_R;
  } else {
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
  }

  if ((*rty_IeAP_e_GearShiftReq == TeAP_e_GearShiftReq_R) &&
      (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
       TeAP_e_FiltdGearState_ReverseGear)) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
      SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
      MeAP_cnt_TransDebugVar = 156U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
      MeAP_cnt_TransDebugVar = 155U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
    MeAP_cnt_TransDebugVar = 153U;
  }

  if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
      (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
    SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_PAUSED_PRESS_BUTTON_b(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, TeAP_e_PAMVolSig *
  rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  uint32_T qY;
  MeAP_b_InitBrkPedlPressed = false;
  SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt <=
      *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
    qY = SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt + /*MW:OvSatOk*/
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (qY < SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt) {
      qY = MAX_uint32_T;
    }

    SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = qY;
    if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
      SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = true;
      MeAP_cnt_TransDebugVar = 168U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
      MeAP_cnt_TransDebugVar = 167U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
    MeAP_cnt_TransDebugVar = 165U;
  }

  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR_k(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  MeAP_b_InitBrkPedlPressed = false;
  if ((*rtu_MeAP_e_GearCmd == TeAutoPark_e_GearCmd_Drive) &&
      (*rty_MeAP_b_StandStill)) {
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_D;
  } else {
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
  }

  if ((*rty_IeAP_e_GearShiftReq == TeAP_e_GearShiftReq_D) &&
      (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
       TeAP_e_FiltdGearState_Drive)) {
    tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
        *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
      SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
      MeAP_cnt_TransDebugVar = 150U;
    } else {
      SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
      MeAP_cnt_TransDebugVar = 149U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
    MeAP_cnt_TransDebugVar = 147U;
  }

  if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
      (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
    SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_FULL_AUTO_ACTIVE_FRONT_REAR_a(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (*rtu_MeAP_b_ObjInPath) {
    SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR_o =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
      SWC_AP_StateMachine_IN_PAUSED_OBJECT_IN_PATH;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PAUSED_OBJECT_IN_PATH;
    MeAP_cnt_StateDebugVar = 75U;
    *rty_MeAP_b_VCOpPaused = true;
    SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
    if (SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt <=
        *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt >
          *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur) {
        SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = true;
        MeAP_cnt_TransDebugVar = 162U;
      } else {
        SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = false;
        MeAP_cnt_TransDebugVar = 161U;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt = 0U;
      SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = false;
      MeAP_cnt_TransDebugVar = 159U;
    }

    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased) {
    SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR_o =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
      SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON;
    MeAP_cnt_StateDebugVar = 76U;
    *rty_MeAP_b_VCOpPaused = true;
    SWC_AP_StateMachine_enter_internal_PAUSED_PRESS_BUTTON_b
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
       rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
       rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
       rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
       rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if (SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR_o ==
             SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT) {
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
        TeAP_e_FiltdGearState_ReverseGear) {
      SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR_o =
        SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR;
      MeAP_cnt_StateDebugVar = 73U;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR_k
        (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
         rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else {
      SWC_AP_StateMachine_inner_default_FULL_AUTO_ACTIVE_FRONT
        (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
         rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    }
  } else {
    /* case IN_FULL_AUTO_ACTIVE_REAR: */
    if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
        TeAP_e_FiltdGearState_Drive) {
      SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR_o =
        SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_FRONT;
      MeAP_cnt_StateDebugVar = 74U;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      SWC_AP_StateMachine_inner_default_FULL_AUTO_ACTIVE_FRONT
        (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
         rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else {
      if ((*rtu_MeAP_e_GearCmd == TeAutoPark_e_GearCmd_Drive) &&
          (*rty_MeAP_b_StandStill)) {
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_D;
      } else {
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      }

      if ((*rty_IeAP_e_GearShiftReq == TeAP_e_GearShiftReq_D) &&
          (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
           TeAP_e_FiltdGearState_Drive)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
          MeAP_cnt_TransDebugVar = 150U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
          MeAP_cnt_TransDebugVar = 149U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
        MeAP_cnt_TransDebugVar = 147U;
      }

      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
      }
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_PAUSED_OBJECT_IN_PATH_i(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (!*rtu_MeAP_b_ObjInPath) {
    SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
      SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR;
    *rty_MeAP_b_VCOpPaused = false;
    SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR_o =
      SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR;
    *rty_IeAP_b_VehMnvrDirSPM = false;

    /* false = Backward, true= Forward  */
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR;
    MeAP_cnt_StateDebugVar = 73U;
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
    SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
    SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR_k
      (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
       rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
       rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
  } else {
    if (SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt <=
        *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt >
          *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur) {
        SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = true;
        MeAP_cnt_TransDebugVar = 162U;
      } else {
        SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = false;
        MeAP_cnt_TransDebugVar = 161U;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_s_ObjInPathCnt = 0U;
      SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m = false;
      MeAP_cnt_TransDebugVar = 159U;
    }

    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_REMOVE_HANDS_FEET_b(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  MeAP_b_InitBrkPedlPressed = true;
  SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
      KeAP_cnt_ScreenChimeTimeoutDur) {
    tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
    if (tmp > 65535) {
      tmp = 65535;
    }

    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      *rty_MeAP_b_ChimeActvReqLHFSVM = true;
      *rty_MeAP_b_ChimeActvReqRHFSVM = true;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else {
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_Active_FullAutoPark_j(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd,
  const boolean_T *rtu_MeAP_b_ObjInPath, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill)
{
  uint32_T qY;
  int32_T tmp;
  switch (SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f) {
   case SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR:
    SWC_AP_StateMachine_FULL_AUTO_ACTIVE_FRONT_REAR_a(rtu_IbVBII_VehState_LowSpd,
      rtu_MeAP_e_GearCmd, rtu_MeAP_b_ObjInPath,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
      rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
      rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur,
      rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
      rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_b_VCOpPaused,
      rty_IeAP_e_GearShiftReq, rty_MeAP_e_PAMVolSigSVM,
      rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
      rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
      rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM,
      rty_MeAP_b_StandStill);
    break;

   case SWC_AP_StateMachine_IN_PAUSED_OBJECT_IN_PATH:
    SWC_AP_StateMachine_PAUSED_OBJECT_IN_PATH_i(rtu_IbVBII_VehState_LowSpd,
      rtu_MeAP_e_GearCmd, rtu_MeAP_b_ObjInPath,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
      rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
      rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, rty_MeAP_e_HMIPopUp,
      rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_b_VCOpPaused, rty_IeAP_e_GearShiftReq,
      rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
      rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
      rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
      rty_MeAP_e_PAMChimeRepnRateSVM, rty_MeAP_b_StandStill);
    break;

   case SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON:
    if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed) {
      SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
        SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR;
      *rty_MeAP_b_VCOpPaused = false;
      SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR_o =
        SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR;
      MeAP_cnt_StateDebugVar = 73U;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR_k
        (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
         rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else {
      if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt <=
          *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
        qY = SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt + /*MW:OvSatOk*/
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (qY < SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt) {
          qY = MAX_uint32_T;
        }

        SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = qY;
        if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
          SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = true;
          MeAP_cnt_TransDebugVar = 168U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
          MeAP_cnt_TransDebugVar = 167U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
        MeAP_cnt_TransDebugVar = 165U;
      }

      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    }
    break;

   case SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON_BrkPedlPressed:
    if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed &&
        SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs) {
      SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
        SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR;
      *rty_MeAP_b_VCOpPaused = false;
      SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR_o =
        SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR;
      MeAP_cnt_StateDebugVar = 73U;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR_k
        (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
         rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed &&
               (!SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs)) {
      SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
        SWC_AP_StateMachine_IN_REMOVE_HANDS_FEET;
      SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_REMOVE_HANDS_FEET;
      MeAP_cnt_StateDebugVar = 71U;
      *rty_MeAP_b_VCOpPaused = true;
      SWC_AP_StateMachine_enter_internal_REMOVE_HANDS_FEET_b
        (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
         rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
         rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
         rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
    } else {
      if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt <=
          *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
        qY = SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt + /*MW:OvSatOk*/
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (qY < SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt) {
          qY = MAX_uint32_T;
        }

        SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = qY;
        if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
          SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = true;
          MeAP_cnt_TransDebugVar = 168U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
          MeAP_cnt_TransDebugVar = 167U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
        MeAP_cnt_TransDebugVar = 165U;
      }

      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    }
    break;

   default:
    /* case IN_REMOVE_HANDS_FEET: */
    if (SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs &&
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed &&
        (SWC_AP_StateMachine_DW.temporalCounter_i1 >= 67U)) {
      SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
        SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_FRONT_REAR;
      *rty_MeAP_b_VCOpPaused = false;
      SWC_AP_StateMachine_DW.is_FULL_AUTO_ACTIVE_FRONT_REAR_o =
        SWC_AP_StateMachine_IN_FULL_AUTO_ACTIVE_REAR;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR;
      MeAP_cnt_StateDebugVar = 73U;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      SWC_AP_StateMachine_enter_internal_FULL_AUTO_ACTIVE_REAR_k
        (rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
         rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else if ((!SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs) &&
               SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased) {
      SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
        SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON_BrkPedlPressed;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON;
      MeAP_cnt_StateDebugVar = 76U;
      *rty_MeAP_b_VCOpPaused = true;
      MeAP_b_InitBrkPedlPressed = true;
      SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
      if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt <=
          *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
        qY = SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt + /*MW:OvSatOk*/
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (qY < SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt) {
          qY = MAX_uint32_T;
        }

        SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = qY;
        if (SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur) {
          SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = true;
          MeAP_cnt_TransDebugVar = 168U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
          MeAP_cnt_TransDebugVar = 167U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_PausedPressBtnCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c = false;
        MeAP_cnt_TransDebugVar = 165U;
      }

      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else if (SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs &&
               (!SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed)) {
      SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
        SWC_AP_StateMachine_IN_PAUSED_PRESS_BUTTON;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON;
      MeAP_cnt_StateDebugVar = 76U;
      *rty_MeAP_b_VCOpPaused = true;
      SWC_AP_StateMachine_enter_internal_PAUSED_PRESS_BUTTON_b
        (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
         rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
         rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
         rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
         rty_MeAP_e_PAMChimeRepnRateSVM);
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
               KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
    break;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_FullAutoParkSCANNING(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeHMI_e_UsrParkOutSide *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if ((*rty_MeAP_b_StandStill) &&
      SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart) {
    SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Park_Exit =
      SWC_AP_StateMachine_IN_Handshake_FullAutoPark_c;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Handshake;
    SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark_l =
      SWC_AP_StateMachine_IN_BSM_Handshake;
    MeAP_cnt_StateDebugVar = 67U;
    SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt = 0U;
    SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
    SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout = false;
    if (SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeActv) {
      *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_CVPAM_Request;
    } else {
      *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
    }

    if ((!SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout) &&
        (*rty_IeAP_e_InterfaceBSM == TeAP_e_InterfaceBSM_CVPAM_Request) &&
        (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts ==
         TeVBII_e_ParkingIntrvntionSts_Active)) {
      SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces = true;
      SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeSts = true;
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces = false;
    }

    if ((*rty_IeAP_e_InterfaceBSM == TeAP_e_InterfaceBSM_CVPAM_Request) &&
        (!SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces)) {
      tmp = SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt >
          *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout) {
        SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = true;
        MeAP_cnt_TransDebugVar = 128U;
      } else {
        SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
        MeAP_cnt_TransDebugVar = 127U;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt = 0U;
      SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
      MeAP_cnt_TransDebugVar = 125U;
    }
  } else {
    switch (SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING) {
     case SWC_AP_StateMachine_IN_DISCLAIMER:
      /* !MeAP_b_StandStill &&... */
      if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
          KeAP_kph_StandStillSpdThd) {
        SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING =
          SWC_AP_StateMachine_IN_PARALLEL_EXIT_STOP;
        SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 63U;
        SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP_g
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd) && uMultiWordNe
                 (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
                  &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
        SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING =
          SWC_AP_StateMachine_IN_PARALLEL_EXIT_SELECT;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        MeAP_cnt_StateDebugVar = 62U;
      } else {
        if (SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed) {
          SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING =
            SWC_AP_StateMachine_IN_HandshakeStart;
          SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart = true;
          MeAP_cnt_StateDebugVar = 65U;
        }
      }
      break;

     case SWC_AP_StateMachine_IN_HandshakeStart:
      break;

     case SWC_AP_StateMachine_IN_PARALLEL_EXIT_SELECT:
      /* !MeAP_b_StandStill &&... */
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
           KeAP_kph_StandStillSpdThd) &&
          (*rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus)) {
        SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING =
          SWC_AP_StateMachine_IN_PARALLEL_EXIT_STOP;
        SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 63U;
        SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP_g
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else {
        if (((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel ==
              TeHMI_e_UsrParkOutSide_Left) ||
             (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel ==
              TeHMI_e_UsrParkOutSide_Right)) && uMultiWordNe
            (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
             &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
          SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING =
            SWC_AP_StateMachine_IN_DISCLAIMER;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_DISCLAIMER;
          *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_OutParking;
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          MeAP_cnt_StateDebugVar = 64U;
          MeAP_b_InitBrkPedlPressed = true;
        }
      }
      break;

     default:
      /* case IN_PARALLEL_EXIT_STOP: */
      /* MeAP_b_StandStill &&... */
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <
           KeAP_kph_StandStillSpdThd) ||
          (SWC_AP_StateMachine_DW.temporalCounter_i1 >= 167U)) {
        SWC_AP_StateMachine_DW.is_FullAutoParkSCANNING =
          SWC_AP_StateMachine_IN_PARALLEL_EXIT_SELECT;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        MeAP_cnt_StateDebugVar = 62U;
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                 KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
      break;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_Handshake_FullAutoPark_i(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat
  *rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_MeAP_b_VCOpPaused, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (!*rty_MeAP_b_StandStill) {
    SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark_l =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Park_Exit =
      SWC_AP_StateMachine_IN_FullAutoParkSCANNING;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Scanning;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Enabled_Seeking;
    SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart = false;
    SWC_AP_StateMachine_enter_internal_FullAutoParkSCANNING
      (rtu_IbVBII_VehState_LowSpd, rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else if (SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces &&
             SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces) {
    SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark_l =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Park_Exit =
      SWC_AP_StateMachine_IN_Active_FullAutoPark;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Park_Out;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Engaged_Full;
    SWC_AP_StateMachine_DW.is_Active_FullAutoPark_f =
      SWC_AP_StateMachine_IN_REMOVE_HANDS_FEET;
    SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_REMOVE_HANDS_FEET;
    MeAP_cnt_StateDebugVar = 71U;
    *rty_MeAP_b_VCOpPaused = true;
    SWC_AP_StateMachine_enter_internal_REMOVE_HANDS_FEET_b
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    switch (SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark_l) {
     case SWC_AP_StateMachine_IN_BSM_Handshake:
      if (SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces) {
        SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark_l =
          SWC_AP_StateMachine_IN_Engaged_Full;
        *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Engaged_Full;
        SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt = 0U;
        if (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts ==
            TeVBII_e_ParkingIntrvntionSts_Active) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt = (uint16_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout =
            (SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt >
             *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt);
        } else {
          SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt = 0U;
          SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout = false;
        }
      } else {
        if (SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeActv) {
          *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_CVPAM_Request;
        } else {
          *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
        }

        if ((!SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout) &&
            (*rty_IeAP_e_InterfaceBSM == TeAP_e_InterfaceBSM_CVPAM_Request) &&
            (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts ==
             TeVBII_e_ParkingIntrvntionSts_Active)) {
          SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces = true;
          SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeSts = true;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces = false;
        }

        if ((*rty_IeAP_e_InterfaceBSM == TeAP_e_InterfaceBSM_CVPAM_Request) && (
             !SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout) {
            SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = true;
            MeAP_cnt_TransDebugVar = 128U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
            MeAP_cnt_TransDebugVar = 127U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_BSMInterfaceCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout = false;
          MeAP_cnt_TransDebugVar = 125U;
        }
      }
      break;

     case SWC_AP_StateMachine_IN_EPS_Handshake_e:
      if (SWC_AP_StateMachine_B.MeAP_b_EPSHandshakeActv) {
        SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
          TeAP_e_SPMLatCtrlReqSts_SPM_Request;
      } else {
        SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
          TeAP_e_SPMLatCtrlReqSts_Idle;
      }

      if ((!SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout) &&
          (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts ==
           TeVBII_e_SPMLatCtrlRespSts_HasOpen) &&
          (SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
           TeAP_e_SPMLatCtrlReqSts_SPM_Request)) {
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = true;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = false;
      }

      if ((SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
           TeAP_e_SPMLatCtrlReqSts_SPM_Request) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout) {
          SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = true;
          MeAP_cnt_TransDebugVar = 144U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
          MeAP_cnt_TransDebugVar = 143U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
        MeAP_cnt_TransDebugVar = 141U;
      }
      break;

     case SWC_AP_StateMachine_IN_Engaged_Full:
      if (SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout) {
        SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark_l =
          SWC_AP_StateMachine_IN_ReverseGearShitReq;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_R;
        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
        MeAP_cnt_StateDebugVar = 68U;
        if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
            TeAP_e_FiltdGearState_ReverseGear) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
            SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
            MeAP_cnt_TransDebugVar = 134U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
            MeAP_cnt_TransDebugVar = 133U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
          MeAP_cnt_TransDebugVar = 131U;
        }
      } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts ==
                 TeVBII_e_ParkingIntrvntionSts_Active) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt = (uint16_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout =
          (SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt >
           *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt);
      } else {
        SWC_AP_StateMachine_DW.MeAP_cnt_EngagedFullWaitCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_b_EngagedFullWaitTimeout = false;
      }
      break;

     default:
      /* case IN_ReverseGearShitReq: */
      if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
          TeAP_e_FiltdGearState_ReverseGear) {
        SWC_AP_StateMachine_DW.is_Handshake_FullAutoPark_l =
          SWC_AP_StateMachine_IN_EPS_Handshake_e;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
        MeAP_cnt_StateDebugVar = 69U;
        SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
        SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
        if (SWC_AP_StateMachine_B.MeAP_b_EPSHandshakeActv) {
          SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
            TeAP_e_SPMLatCtrlReqSts_SPM_Request;
        } else {
          SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
            TeAP_e_SPMLatCtrlReqSts_Idle;
        }

        if ((!SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout) &&
            (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts ==
             TeVBII_e_SPMLatCtrlRespSts_HasOpen) &&
            (SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
             TeAP_e_SPMLatCtrlReqSts_SPM_Request)) {
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = true;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = false;
        }

        if ((SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
             TeAP_e_SPMLatCtrlReqSts_SPM_Request) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout) {
            SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = true;
            MeAP_cnt_TransDebugVar = 144U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
            MeAP_cnt_TransDebugVar = 143U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
          MeAP_cnt_TransDebugVar = 141U;
        }
      } else if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
                 TeAP_e_FiltdGearState_ReverseGear) {
        tmp = SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout) {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = true;
          MeAP_cnt_TransDebugVar = 134U;
        } else {
          SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
          MeAP_cnt_TransDebugVar = 133U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_s_GearShiftWaitCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout = false;
        MeAP_cnt_TransDebugVar = 131U;
      }
      break;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_PARALLEL_EXIT_REMOVE_HANDS_LEFT(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;

  /* !MeAP_b_StandStill &&... */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
      KeAP_kph_StandStillSpdThd) {
    SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING =
      SWC_AP_StateMachine_IN_PARALLEL_EXIT_STOP;
    SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    MeAP_cnt_StateDebugVar = 80U;
    SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
       rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
       rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
       rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
  } else {
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_ReverseGear) &&
        SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
      MeAP_cnt_TransDebugVar = 172U;
    } else {
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
      MeAP_cnt_TransDebugVar = 171U;
    }

    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_SemiAutoParkSCANNING(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeHMI_e_UsrParkOutSide *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if ((*rty_MeAP_b_StandStill) &&
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart) {
    SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_Park_Exit =
      SWC_AP_StateMachine_IN_Handshake_SemiAutoPark_c;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Handshake;
    MeAP_cnt_StateDebugVar = 84U;
    SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
    SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
    if (SWC_AP_StateMachine_B.MeAP_b_EPSHandshakeActv) {
      SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
        TeAP_e_SPMLatCtrlReqSts_SPM_Request;
    } else {
      SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
        TeAP_e_SPMLatCtrlReqSts_Idle;
    }

    if ((!SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout) &&
        (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts ==
         TeVBII_e_SPMLatCtrlRespSts_HasOpen) &&
        (SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
         TeAP_e_SPMLatCtrlReqSts_SPM_Request)) {
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = true;
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = false;
    }

    if ((SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
         TeAP_e_SPMLatCtrlReqSts_SPM_Request) &&
        (!SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces)) {
      tmp = SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt >
          *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout) {
        SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = true;
        MeAP_cnt_TransDebugVar = 182U;
      } else {
        SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
        MeAP_cnt_TransDebugVar = 181U;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
      SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
      MeAP_cnt_TransDebugVar = 179U;
    }
  } else {
    switch (SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING) {
     case SWC_AP_StateMachine_IN_PARALLEL_EXIT_REMOVE_HANDS_LEFT:
      SWC_AP_StateMachine_PARALLEL_EXIT_REMOVE_HANDS_LEFT
        (rtu_IbVBII_VehState_LowSpd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
         rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
         rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
         rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
         rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
         rty_MeAP_e_PAMChimeRepnRateSVM);
      break;

     case SWC_AP_StateMachine_IN_PARALLEL_EXIT_REMOVE_HANDS_RIGHT:
      /* !MeAP_b_StandStill &&... */
      if (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
          KeAP_kph_StandStillSpdThd) {
        SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING =
          SWC_AP_StateMachine_IN_PARALLEL_EXIT_STOP;
        SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 80U;
        SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else {
        if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
             TeAP_e_FiltdGearState_ReverseGear) &&
            SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
          *rty_IeAP_b_VehMnvrDirSPM = false;

          /* false = Backward, true= Forward  */
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
          MeAP_cnt_TransDebugVar = 172U;
        } else {
          *rty_IeAP_b_VehMnvrDirSPM = true;

          /* false = Backward, true= Forward  */
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
          MeAP_cnt_TransDebugVar = 171U;
        }

        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
              KeAP_cnt_ScreenChimeTimeoutDur) {
            *rty_MeAP_b_ChimeActvReqLHFSVM = true;
            *rty_MeAP_b_ChimeActvReqRHFSVM = true;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      }
      break;

     case SWC_AP_StateMachine_IN_PARALLEL_EXIT_SELECT:
      /* !MeAP_b_StandStill &&... */
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
           KeAP_kph_StandStillSpdThd) &&
          (*rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus)) {
        SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING =
          SWC_AP_StateMachine_IN_PARALLEL_EXIT_STOP;
        SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        MeAP_cnt_StateDebugVar = 80U;
        SWC_AP_StateMachine_enter_internal_PARALLEL_EXIT_STOP
          (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
      } else if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel ==
                  TeHMI_e_UsrParkOutSide_Left) && uMultiWordNe
                 (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
                  &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
        SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING =
          SWC_AP_StateMachine_IN_PARALLEL_EXIT_REMOVE_HANDS_LEFT;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_LEFT;
        MeAP_cnt_StateDebugVar = 81U;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_OutParking;
        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
        if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
             TeAP_e_FiltdGearState_ReverseGear) &&
            SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
          *rty_IeAP_b_VehMnvrDirSPM = false;

          /* false = Backward, true= Forward  */
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
          MeAP_cnt_TransDebugVar = 172U;
        } else {
          *rty_IeAP_b_VehMnvrDirSPM = true;

          /* false = Backward, true= Forward  */
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
          MeAP_cnt_TransDebugVar = 171U;
        }

        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
              KeAP_cnt_ScreenChimeTimeoutDur) {
            *rty_MeAP_b_ChimeActvReqLHFSVM = true;
            *rty_MeAP_b_ChimeActvReqRHFSVM = true;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel ==
             TeHMI_e_UsrParkOutSide_Right) && uMultiWordNe
            (&rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter->chunks[0U],
             &SWC_AP_StateMachine_B.UnitDelay.chunks[0U], 2)) {
          SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING =
            SWC_AP_StateMachine_IN_PARALLEL_EXIT_REMOVE_HANDS_RIGHT;
          *rty_MeAP_e_HMIPopUp =
            TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_RIGHT;
          MeAP_cnt_StateDebugVar = 81U;
          *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Active_OutParking;
          SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
          if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
               TeAP_e_FiltdGearState_ReverseGear) &&
              SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff) {
            *rty_IeAP_b_VehMnvrDirSPM = false;

            /* false = Backward, true= Forward  */
            SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = true;
            MeAP_cnt_TransDebugVar = 172U;
          } else {
            *rty_IeAP_b_VehMnvrDirSPM = true;

            /* false = Backward, true= Forward  */
            SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
            MeAP_cnt_TransDebugVar = 171U;
          }

          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
              KeAP_cnt_ScreenChimeTimeoutDur) {
            tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
              *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
            if (tmp > 65535) {
              tmp = 65535;
            }

            SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
            if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                KeAP_cnt_ScreenChimeTimeoutDur) {
              *rty_MeAP_b_ChimeActvReqLHFSVM = true;
              *rty_MeAP_b_ChimeActvReqRHFSVM = true;
              *rty_MeAP_b_ChimeActvReqLHRSVM = false;
              *rty_MeAP_b_ChimeActvReqRHRSVM = false;
              *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
              *rty_MeAP_e_PAMChimeRepnRateSVM =
                TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
            } else {
              *rty_MeAP_b_ChimeActvReqLHFSVM = false;
              *rty_MeAP_b_ChimeActvReqRHFSVM = false;
              *rty_MeAP_b_ChimeActvReqLHRSVM = false;
              *rty_MeAP_b_ChimeActvReqRHRSVM = false;
              *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
              *rty_MeAP_e_PAMChimeRepnRateSVM =
                TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
            }
          } else {
            *rty_MeAP_b_ChimeActvReqLHFSVM = false;
            *rty_MeAP_b_ChimeActvReqRHFSVM = false;
            *rty_MeAP_b_ChimeActvReqLHRSVM = false;
            *rty_MeAP_b_ChimeActvReqRHRSVM = false;
            *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
            *rty_MeAP_e_PAMChimeRepnRateSVM =
              TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
            *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          }
        }
      }
      break;

     default:
      /* case IN_PARALLEL_EXIT_STOP: */
      /* MeAP_b_StandStill &&... */
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <
           KeAP_kph_StandStillSpdThd) ||
          (SWC_AP_StateMachine_DW.temporalCounter_i1 >= 167U)) {
        SWC_AP_StateMachine_DW.is_SemiAutoParkSCANNING =
          SWC_AP_StateMachine_IN_PARALLEL_EXIT_SELECT;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        MeAP_cnt_StateDebugVar = 79U;
      } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
                 KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
      break;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_MOVE_BACKWARD_e(const boolean_T
  *rtu_MeAP_b_PosMet, const boolean_T *rtu_MeAP_b_SteerActionReq, const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM)
{
  int32_T tmp;
  if ((*rtu_MeAP_b_PosMet) && (*rtu_MeAP_e_GearCmd == TeAutoPark_e_GearCmd_Drive))
  {
    SWC_AP_StateMachine_DW.is_MutlipleMoves_g = SWC_AP_StateMachine_IN_STOP_REAR;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_STOP_REAR;
    MeAP_cnt_StateDebugVar = 89U;
    SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
        KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
  } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
              TeAP_e_FiltdGearState_Drive) && (!*rtu_MeAP_b_ObjPrestFC)) {
    if (*rtu_MeAP_b_SteerActionReq) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
        SWC_AP_StateMachine_IN_WAIT_FOR_STEER_FRONT;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WAIT_FOR_STEER_FRONT;
      MeAP_cnt_StateDebugVar = 91U;
    } else {
      SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
        SWC_AP_StateMachine_IN_MOVE_FORWARD;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_FORWARD;
      MeAP_cnt_StateDebugVar = 92U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
      }
    }
  } else {
    if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
        (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
      if (tmp > 255) {
        tmp = 255;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_MutlipleMoves_k(const boolean_T
  *rtu_MeAP_b_PosMet, const boolean_T *rtu_MeAP_b_SteerActionReq, const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TeAutoPark_e_GearCmd
  *rtu_MeAP_e_GearCmd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_IeAP_b_VehMnvrDirSPM,
  TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T
  *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  boolean_T tmp_0;
  switch (SWC_AP_StateMachine_DW.is_MutlipleMoves_g) {
   case SWC_AP_StateMachine_IN_MOVE_BACKWARD:
    SWC_AP_StateMachine_MOVE_BACKWARD_e(rtu_MeAP_b_PosMet,
      rtu_MeAP_b_SteerActionReq, rtu_IbVBII_VehState_LowSpd, rtu_MeAP_e_GearCmd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rtu_MeAP_b_ObjPrestFC,
      rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
      rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
      rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
      rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
    break;

   case SWC_AP_StateMachine_IN_MOVE_FORWARD:
    if ((*rtu_MeAP_b_PosMet) && (*rtu_MeAP_e_GearCmd ==
         TeAutoPark_e_GearCmd_Reverse)) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
        SWC_AP_StateMachine_IN_STOP_FRONT;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_STOP_FRONT;
      MeAP_cnt_StateDebugVar = 93U;
      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = 0U;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
            KeAP_cnt_ScreenChimeTimeoutDur) {
          *rty_MeAP_b_ChimeActvReqLHFSVM = true;
          *rty_MeAP_b_ChimeActvReqRHFSVM = true;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
        } else {
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
        }
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      tmp_0 = !*rtu_MeAP_b_ObjPrestRC;
      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
           TeAP_e_FiltdGearState_ReverseGear) && tmp_0 &&
          (*rtu_MeAP_b_SteerActionReq)) {
        SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
          SWC_AP_StateMachine_IN_WAIT_FOR_STEER_REAR_o;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR;
        MeAP_cnt_StateDebugVar = 95U;
      } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                  TeAP_e_FiltdGearState_ReverseGear) && tmp_0 &&
                 (!*rtu_MeAP_b_SteerActionReq)) {
        SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
          SWC_AP_StateMachine_IN_MOVE_BACKWARD;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_BACKWARD;
        MeAP_cnt_StateDebugVar = 88U;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
        if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
        }
      } else {
        if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
        }
      }
    }
    break;

   case SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_GUIDANCE:
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_Drive) && (*rtu_MeAP_b_SteerActionReq)) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
        SWC_AP_StateMachine_IN_WAIT_FOR_STEER_FRONT;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WAIT_FOR_STEER_FRONT;
      MeAP_cnt_StateDebugVar = 91U;
    } else {
      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
           TeAP_e_FiltdGearState_Drive) && (!*rtu_MeAP_b_SteerActionReq)) {
        SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
          SWC_AP_StateMachine_IN_MOVE_FORWARD;
        *rty_IeAP_b_VehMnvrDirSPM = true;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_FORWARD;
        MeAP_cnt_StateDebugVar = 92U;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
        if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
        }
      }
    }
    break;

   case SWC_AP_StateMachine_IN_SHIFT_TO_REVERSE:
    if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_ReverseGear) && (*rtu_MeAP_b_SteerActionReq)) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
        SWC_AP_StateMachine_IN_WAIT_FOR_STEER_REAR_o;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR;
      MeAP_cnt_StateDebugVar = 95U;
    } else {
      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
           TeAP_e_FiltdGearState_ReverseGear) && (!*rtu_MeAP_b_SteerActionReq))
      {
        SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
          SWC_AP_StateMachine_IN_MOVE_BACKWARD;
        *rty_IeAP_b_VehMnvrDirSPM = false;

        /* false = Backward, true= Forward  */
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_BACKWARD;
        MeAP_cnt_StateDebugVar = 88U;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
        if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
            (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
        }
      }
    }
    break;

   case SWC_AP_StateMachine_IN_STOP_FRONT:
    if (*rty_MeAP_b_StandStill) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
        SWC_AP_StateMachine_IN_SHIFT_TO_REVERSE;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_REVERSE;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      MeAP_cnt_StateDebugVar = 94U;
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
               KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
    break;

   case SWC_AP_StateMachine_IN_STOP_REAR:
    if (*rty_MeAP_b_StandStill) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
        SWC_AP_StateMachine_IN_SHIFT_TO_DRIVE_GUIDANCE;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE_GUIDANCE;
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      MeAP_cnt_StateDebugVar = 90U;
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
               KeAP_cnt_ScreenChimeTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenChimeCnt <=
          KeAP_cnt_ScreenChimeTimeoutDur) {
        *rty_MeAP_b_ChimeActvReqLHFSVM = true;
        *rty_MeAP_b_ChimeActvReqRHFSVM = true;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_Type11;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_Medium;
      } else {
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      }
    } else {
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    }
    break;

   case SWC_AP_StateMachine_IN_WAIT_FOR_STEER_FRONT:
    if (!*rtu_MeAP_b_SteerActionReq) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
        SWC_AP_StateMachine_IN_MOVE_FORWARD;
      *rty_IeAP_b_VehMnvrDirSPM = true;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_FORWARD;
      MeAP_cnt_StateDebugVar = 92U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
      }
    }
    break;

   default:
    /* case IN_WAIT_FOR_STEER_REAR: */
    if (!*rtu_MeAP_b_SteerActionReq) {
      SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
        SWC_AP_StateMachine_IN_MOVE_BACKWARD;
      *rty_IeAP_b_VehMnvrDirSPM = false;

      /* false = Backward, true= Forward  */
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_BACKWARD;
      MeAP_cnt_StateDebugVar = 88U;
      SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2) &&
          (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
      }
    }
    break;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_DOOR_OPEN_TAKECONTROL(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
  SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt < KeAP_cnt_AbortHMIWaitCnt)
  {
    if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
          KeAP_cnt_AbortHMIWaitCnt) {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
      }
    } else {
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_LIFTGATE_OPEN_TAKECONTROL(const
  uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
  SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt < KeAP_cnt_AbortHMIWaitCnt)
  {
    if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
          KeAP_cnt_AbortHMIWaitCnt) {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
      }
    } else {
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_Abort_HMI_3(const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp)
{
  int32_T tmp;
  MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
  MeAP_b_PreEPSInterfaceAbort1 = false;
  MeAP_b_PreEPSInterfaceAbort2 = false;
  if (MeAP_b_DoorOpen) {
    MeAP_cnt_TransDebugVar = 220U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_DOOR_OPEN_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_DOOR_OPEN_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 220U;
    SWC_AP_StateMachine_enter_internal_DOOR_OPEN_TAKECONTROL
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp);
  } else if (MeAP_b_LifeGateOpen) {
    MeAP_cnt_TransDebugVar = 221U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_LIFTGATE_OPEN_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_LIFTGATE_OPEN_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 221U;
    SWC_AP_StateMachine_enter_internal_LIFTGATE_OPEN_TAKECONTROL
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp);
  } else if (MeAP_b_ESCActive) {
    MeAP_cnt_TransDebugVar = 222U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_ESC_ACTIVE_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_ESC_ACTIVE_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 222U;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
        KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
  } else if (MeAP_b_MnvSpdExceed) {
    MeAP_cnt_TransDebugVar = 223U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_SPEED_TOO_HIGH_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPEED_TOO_HIGH_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 223U;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
        KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
  } else if (MeAP_b_Lo4DriveTrain) {
    MeAP_cnt_TransDebugVar = 224U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_LO4_ACTIVE_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_LO4_ACTIVE_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 224U;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
        KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
  } else if (MeAP_b_TrlrConn) {
    MeAP_cnt_TransDebugVar = 225U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_TRAILER_CONNECTED_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_TRAILER_CONNECTED_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 225U;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
        KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
  } else if (MeAP_b_FrntSnsrBlk) {
    MeAP_cnt_TransDebugVar = 226U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_FRONT_WIPE_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FRONT_WIPE_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 226U;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
        KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
  } else if (MeAP_b_RearSnsrBlk) {
    MeAP_cnt_TransDebugVar = 227U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_REAR_WIPE_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_REAR_WIPE_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 227U;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
        KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
  } else if (MeAP_b_ACCEngg) {
    MeAP_cnt_TransDebugVar = 228U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_CRUISE_CONTROL_ENGAGED_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 228U;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
        KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
  } else if (MeAP_b_BtnPsd) {
    MeAP_cnt_TransDebugVar = 229U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_BUTTON_PRESS_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_BUTTON_PRESS_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 229U;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
        KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
  } else if (MeAP_b_HandsOn) {
    MeAP_cnt_TransDebugVar = 230U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_WaitTimer;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt = 0U;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt <
        KeAP_cnt_AbortDelayWaitCnt) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt = (uint16_T)tmp;
      SWC_AP_StateMachine_DW.MeAP_b_AbortDelayTimeOut =
        (SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt >=
         KeAP_cnt_AbortDelayWaitCnt);
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortDelayTimeOut = false;
    }
  } else if (MeAP_b_DriverOverride) {
    MeAP_cnt_TransDebugVar = 231U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_WaitTimer1;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt = 0U;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt <
        KeAP_cnt_AbortDelayWaitCnt) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt = (uint16_T)tmp;
      SWC_AP_StateMachine_DW.MeAP_b_AbortDelayTimeOut =
        (SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt >=
         KeAP_cnt_AbortDelayWaitCnt);
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortDelayTimeOut = false;
    }
  } else if (MeAP_b_ManualParkReq) {
    MeAP_cnt_TransDebugVar = 232U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_MANUAL_PARK_TAKECONTROL;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 232U;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
        KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
  } else {
    MeAP_cnt_TransDebugVar = 233U;
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
      SWC_AP_StateMachine_IN_MANUAL_PARK_TAKECONTROL_Default;
    *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL;
    MeAP_cnt_StateDebugVar = 233U;
    SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
        KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_Abort(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_StandstillReq, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq)
{
  if ((!(MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_Out)) &&
      (!(MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_In)) &&
      (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
       TeAP_e_FiltdGearState_ReverseGear)) {
    SWC_AP_StateMachine_DW.is_Abort = SWC_AP_StateMachine_IN_Abort_HMI_1;
    MeAP_cnt_StateDebugVar = 100U;
    *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
    SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts = TeAP_e_SPMLatCtrlReqSts_Idle;
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
    *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
    *rty_IeAP_b_SPMFailSts = false;
    *rty_IeAP_b_SPMFaultSts = false;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    *rty_IeAP_b_StandstillReq = true;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
    MeAP_b_PreEPSInterfaceAbort1 = true;
    MeAP_b_PreEPSInterfaceAbort2 = false;
    if (MeAP_b_DoorOpen) {
      MeAP_cnt_TransDebugVar = 183U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_DOOR_OPEN_FULLSCREEN;
      MeAP_cnt_StateDebugVar = 183U;
    } else if (MeAP_b_LifeGateOpen) {
      MeAP_cnt_TransDebugVar = 184U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_LIFEGATE_OPEN_FULLSCREEN;
      MeAP_cnt_StateDebugVar = 184U;
    } else if (MeAP_b_ESCActive) {
      MeAP_cnt_TransDebugVar = 185U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_ESC_ACTIVE_FULLSCREEN;
    } else if (MeAP_b_SeekSpdExceed || MeAP_b_MnvSpdExceed) {
      MeAP_cnt_TransDebugVar = 186U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FULLSCREEN;
      MeAP_cnt_StateDebugVar = 186U;
    } else if (MeAP_b_Lo4DriveTrain) {
      MeAP_cnt_TransDebugVar = 187U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_LO4_ACTIVE_FULLSCREEN;
      MeAP_cnt_StateDebugVar = 187U;
    } else if (MeAP_b_TrlrConn) {
      MeAP_cnt_TransDebugVar = 188U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_TRAILER_CONNECTED_FULLSCREEN;
      MeAP_cnt_StateDebugVar = 188U;
    } else if (MeAP_b_FrntSnsrBlk) {
      MeAP_cnt_TransDebugVar = 189U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FRONT_WIPE_FULLSCREEN;
    } else if (MeAP_b_RearSnsrBlk) {
      MeAP_cnt_TransDebugVar = 190U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_REAR_WIPE_FULLSCREEN;
    } else if (MeAP_b_ACCEngg) {
      MeAP_cnt_TransDebugVar = 191U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_FULLSCREEN;
      MeAP_cnt_StateDebugVar = 191U;
    } else if (MeAP_b_BtnPsd) {
      MeAP_cnt_TransDebugVar = 192U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_BUTTON_PRESS_FULLSCREEN;
      MeAP_cnt_StateDebugVar = 192U;
    } else {
      MeAP_cnt_TransDebugVar = 193U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_TEMP_NA_FULLSCREEN;
    }
  } else if ((!(MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_Out)) &&
             (!(MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_In)) &&
             (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
              TeAP_e_FiltdGearState_ReverseGear)) {
    SWC_AP_StateMachine_DW.is_Abort = SWC_AP_StateMachine_IN_Abort_HMI_2;
    *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
    SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts = TeAP_e_SPMLatCtrlReqSts_Idle;
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
    *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
    *rty_IeAP_b_SPMFailSts = false;
    *rty_IeAP_b_SPMFaultSts = false;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    *rty_IeAP_b_StandstillReq = true;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
    MeAP_b_PreEPSInterfaceAbort1 = false;
    MeAP_b_PreEPSInterfaceAbort2 = true;
    if (MeAP_b_DoorOpen) {
      MeAP_cnt_TransDebugVar = 200U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_DOOR_OPEN_OVERLAY;
      MeAP_cnt_StateDebugVar = 200U;
    } else if (MeAP_b_LifeGateOpen) {
      MeAP_cnt_TransDebugVar = 201U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_LIFTGATE_OPEN_OVERLAY;
      MeAP_cnt_StateDebugVar = 201U;
    } else if (MeAP_b_ESCActive) {
      MeAP_cnt_TransDebugVar = 202U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_ESC_ACTIVE_OVERLAY;
      MeAP_cnt_StateDebugVar = 202U;
    } else if (MeAP_b_BtnPsd) {
      MeAP_cnt_TransDebugVar = 203U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_BUTTON_PRESS_TAKECONTROL;
      MeAP_cnt_StateDebugVar = 203U;
    } else if (MeAP_b_Lo4DriveTrain) {
      MeAP_cnt_TransDebugVar = 204U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_LO4_ACTIVE_OVERLAY;
      MeAP_cnt_StateDebugVar = 204U;
    } else if (MeAP_b_TrlrConn) {
      MeAP_cnt_TransDebugVar = 205U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_TRAILER_CONNECTED_OVERLAY;
      MeAP_cnt_StateDebugVar = 205U;
    } else if (MeAP_b_FrntSnsrBlk) {
      MeAP_cnt_TransDebugVar = 206U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_FRONT_WIPE_OVERLAY;
      MeAP_cnt_StateDebugVar = 206U;
    } else if (MeAP_b_RearSnsrBlk) {
      MeAP_cnt_TransDebugVar = 207U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_REAR_WIPE_OVERLAY;
      MeAP_cnt_StateDebugVar = 207U;
    } else if (MeAP_b_ACCEngg) {
      MeAP_cnt_TransDebugVar = 208U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_TAKECONTROL;
      MeAP_cnt_StateDebugVar = 208U;
    } else if (MeAP_b_SeekSpdExceed || MeAP_b_MnvSpdExceed) {
      MeAP_cnt_TransDebugVar = 209U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_UNAVAIL_SPEED_TOO_HIGH_OVERLAY;
      MeAP_cnt_StateDebugVar = 209U;
    } else {
      MeAP_cnt_TransDebugVar = 210U;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_TEMP_NA_OVERLAY;
      MeAP_cnt_StateDebugVar = 210U;
    }
  } else {
    SWC_AP_StateMachine_DW.is_Abort = SWC_AP_StateMachine_IN_Abort_HMI_3;
    MeAP_cnt_StateDebugVar = 102U;
    SWC_AP_StateMachine_enter_internal_Abort_HMI_3
      (rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp);
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_ACTIVE_AUTOPARK(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const TeHMI_e_UsrParkOutSide
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const TeAP_e_UsrPPPAManeuverSel
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const boolean_T
  *rtu_MeAP_b_PosMet, const boolean_T *rtu_MeAP_b_SteerActionReq, const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TbNVM_ProxyCalibParam
  *rtu_MbNVM_ProxyParam, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd, const
  boolean_T *rtu_MeAP_b_ObjInPath, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_InterfaceBSM *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv
  *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_PAMLedCtrlStatus *rty_IeAP_e_SPMLedSts, boolean_T
  *rty_IeAP_b_SPMFailSts, boolean_T *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *
  rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_IeAP_b_StandstillReq, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Active;
  *rty_IeAP_b_SPMFailSts = false;
  *rty_IeAP_b_SPMFaultSts = false;
  *rty_IeAP_b_StandstillReq = false;
  if (MeAP_b_AbortCon1 || MeAP_b_AbortCon2 || MeAP_b_AbortCon3 ||
      (!SWC_AP_StateMachine_B.DataTypeConversion5)) {
    SWC_AP_StateMachine_exit_internal_ParkIn();
    SWC_AP_StateMachine_exit_internal_Park_Exit();
    SWC_AP_StateMachine_DW.is_ACTIVE_AUTOPARK =
      SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
    SWC_AP_StateMachine_DW.is_ON = SWC_AP_StateMachine_IN_Abort;
    SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
    MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Abort;
    SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle = false;

    /* Chime reset */
    *rty_MeAP_b_ChimeActvReqLHFSVM = false;
    *rty_MeAP_b_ChimeActvReqRHFSVM = false;
    *rty_MeAP_b_ChimeActvReqLHRSVM = false;
    *rty_MeAP_b_ChimeActvReqRHRSVM = false;
    *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
    *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
    SWC_AP_StateMachine_enter_internal_Abort(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_IeAP_e_InterfaceBSM,
      rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
      rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
      rty_IeAP_b_StandstillReq, rty_IeAP_e_GearShiftReq);
  } else {
    /* MeAP_cnt_Move > uint8(0) &&MeAP_e_GearCmd==TeAutoPark_e_GearCmd.Park &&(MeAutoPark_e_AlgoState!=TeAP_e_AlgoState.Idle &&MeAutoPark_e_AlgoState!=TeAP_e_AlgoState.Scanning &&MeAutoPark_e_AlgoState!=TeAP_e_AlgoState.Handshake) */
    if (SWC_AP_StateMachine_DW.MeAP_b_VehicleParked) {
      SWC_AP_StateMachine_exit_internal_ParkIn();
      SWC_AP_StateMachine_exit_internal_Park_Exit();
      SWC_AP_StateMachine_DW.is_ACTIVE_AUTOPARK =
        SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
      SWC_AP_StateMachine_DW.is_ON = SWC_AP_StateMachine_IN_Complete;
      MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Complete;
      SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;

      /* Chime reset */
      *rty_MeAP_b_ChimeActvReqLHFSVM = false;
      *rty_MeAP_b_ChimeActvReqRHFSVM = false;
      *rty_MeAP_b_ChimeActvReqLHRSVM = false;
      *rty_MeAP_b_ChimeActvReqRHRSVM = false;
      *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
      *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
      if ((MeAutoPark_e_AlgoState == TeAP_e_AlgoState_Park_In) &&
          rtu_IbVBII_VehState_LowSpd->IeVBII_b_ActvParkMode) {
        SWC_AP_StateMachine_DW.is_Complete =
          SWC_AP_StateMachine_IN_COMPLETE_HMI_FRONT_REAR;
        SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
          TeAP_e_SPMLatCtrlReqSts_Idle;

        /*  EPS Handshake Closed  */
        *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
        SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeSts = false;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
        MeAP_cnt_StateDebugVar = 402U;
        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = 0U;
        if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
            TeAP_e_FiltdGearState_ReverseGear) {
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_COMPLETE_HMI_REAR;
        } else {
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_COMPLETE_HMI_FRONT;
        }

        if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt <=
            KeAP_cnt_ScreenWaitTimeoutDur) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = (uint16_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete =
            ((SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt <=
              KeAP_cnt_ScreenWaitTimeoutDur) ||
             (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
              TeAP_e_FiltdGearState_Parking));
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete = false;
        }
      } else {
        SWC_AP_StateMachine_DW.is_Complete =
          SWC_AP_StateMachine_IN_ParkIN_RelVehControlDelay;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
        SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;
        if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
             TeAP_e_FiltdGearState_Parking) ||
            (rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts ==
             TeVBII_e_VehEPBSts_Applied)) {
          if (!SWC_AP_StateMachine_DW.MeAP_b_RelVehControl) {
            tmp = SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt +
              *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
            if (tmp > 65535) {
              tmp = 65535;
            }

            SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = (uint16_T)tmp;
            if (SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt >=
                KeAP_cnt_RelCntrlWaitThd) {
              SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = true;
              MeAP_cnt_TransDebugVar = 2241U;
            } else {
              SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;
              MeAP_cnt_TransDebugVar = 2240U;
            }
          } else {
            SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = true;
            MeAP_cnt_TransDebugVar = 241U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;
          SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = 0U;
          MeAP_cnt_TransDebugVar = 240U;
        }
      }
    } else {
      switch (SWC_AP_StateMachine_DW.is_ACTIVE_AUTOPARK) {
       case SWC_AP_StateMachine_IN_IDLE:
        SWC_AP_StateMachine_IDLE(rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake,
          rtu_IbVBII_VehState_LowSpd, rtu_MbNVM_ProxyParam,
          rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
          rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
          rtu_MeAP_b_ObjPrestFC, rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp,
          rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
          rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
          rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
          rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
          rty_MeAP_e_PAMChimeRepnRateSVM);
        break;

       case SWC_AP_StateMachine_IN_ParkIn:
        SWC_AP_StateMachine_ParkIn
          (rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus,
           rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle,
           rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
           rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel,
           rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
           rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide,
           rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, rtu_MeAP_b_PosMet,
           rtu_MeAP_b_SteerActionReq, rtu_IbVBII_VehState_LowSpd,
           rtu_MbNVM_ProxyParam, rtu_MeAP_e_GearCmd, rtu_MeAP_b_ObjInPath,
           rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
           rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
           rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout,
           rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout,
           rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
           rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur,
           rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
           rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur,
           rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt,
           rtu_MeAP_b_ObjPrestFC, rtu_MeAP_b_ObjPrestRC, rtu_IeAP_kph_TrgtVehSpd,
           rtu_IeAP_cm_TrgtDist, rty_IeAP_e_InterfaceBSM,
           rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat,
           rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_b_VCOpPaused,
           rty_IeAP_e_GearShiftReq, rty_MeAP_e_PAMVolSigSVM,
           rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
           rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
           rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM,
           rty_MeAP_b_StandStill);
        break;

       default:
        /* case IN_Park_Exit: */
        if ((*rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel ==
             TeAP_e_UsrPPPAManeuverSel_ParkIn) && (MeAutoPark_e_AlgoState !=
             TeAP_e_AlgoState_Park_Out)) {
          SWC_AP_StateMachine_exit_internal_Park_Exit();
          SWC_AP_StateMachine_DW.is_ACTIVE_AUTOPARK =
            SWC_AP_StateMachine_IN_ParkIn;
          SWC_AP_StateMachine_DW.MeAP_cnt_Move = 0U;
          SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeStart = false;
          SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          SWC_AP_StateMachine_enter_internal_ParkIn(rtu_IbVBII_VehState_LowSpd,
            rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
            rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
            rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat,
            rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
            rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
            rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
            rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
        } else {
          switch (SWC_AP_StateMachine_DW.is_Park_Exit) {
           case SWC_AP_StateMachine_IN_Active_FullAutoPark:
            SWC_AP_StateMachine_Active_FullAutoPark_j(rtu_IbVBII_VehState_LowSpd,
              rtu_MeAP_e_GearCmd, rtu_MeAP_b_ObjInPath,
              rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
              rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
              rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur,
              rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
              rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM,
              rty_MeAP_b_VCOpPaused, rty_IeAP_e_GearShiftReq,
              rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
              rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
              rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
              rty_MeAP_e_PAMChimeRepnRateSVM, rty_MeAP_b_StandStill);
            break;

           case SWC_AP_StateMachine_IN_Active_SemiAutoParkExit:
            if (SWC_AP_StateMachine_DW.is_Active_SemiAutoParkExit ==
                SWC_AP_StateMachine_IN_MutlipleMoves) {
              SWC_AP_StateMachine_MutlipleMoves_k(rtu_MeAP_b_PosMet,
                rtu_MeAP_b_SteerActionReq, rtu_IbVBII_VehState_LowSpd,
                rtu_MeAP_e_GearCmd, rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
                rtu_MeAP_b_ObjPrestFC, rtu_MeAP_b_ObjPrestRC,
                rty_MeAP_e_HMIPopUp, rty_IeAP_b_VehMnvrDirSPM,
                rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
                rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
                rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
                rty_MeAP_e_PAMChimeRepnRateSVM, rty_MeAP_b_StandStill);
            } else {
              /* case IN_WAIT_FOR_STEER_REAR: */
              if (!*rtu_MeAP_b_SteerActionReq) {
                SWC_AP_StateMachine_DW.is_Active_SemiAutoParkExit =
                  SWC_AP_StateMachine_IN_MutlipleMoves;
                SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
                  SWC_AP_StateMachine_IN_MOVE_BACKWARD;
                *rty_IeAP_b_VehMnvrDirSPM = false;

                /* false = Backward, true= Forward  */
                *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_BACKWARD;
                MeAP_cnt_StateDebugVar = 88U;
                SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
                if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2)
                    && (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
                  tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
                  if (tmp > 255) {
                    tmp = 255;
                  }

                  SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
                  SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
                }
              }
            }
            break;

           case SWC_AP_StateMachine_IN_FullAutoParkSCANNING:
            SWC_AP_StateMachine_FullAutoParkSCANNING
              (rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus,
               rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel,
               rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
               rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
               rtu_IbVBII_VehState_LowSpd,
               rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout,
               rty_IeAP_e_InterfaceBSM, rty_MeAP_e_HMIPopUp,
               rty_IeAP_e_SPMActvStat, rty_MeAP_e_PAMVolSigSVM,
               rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
               rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
               rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM,
               rty_MeAP_b_StandStill);
            break;

           case SWC_AP_StateMachine_IN_Handshake_FullAutoPark_c:
            SWC_AP_StateMachine_Handshake_FullAutoPark_i
              (rtu_IbVBII_VehState_LowSpd,
               rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout,
               rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout,
               rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
               rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt,
               rty_IeAP_e_InterfaceBSM, rty_IeAP_e_ParKMnvrActv,
               rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat,
               rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_b_VCOpPaused,
               rty_IeAP_e_GearShiftReq, rty_MeAP_e_PAMVolSigSVM,
               rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
               rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
               rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM,
               rty_MeAP_b_StandStill);
            break;

           case SWC_AP_StateMachine_IN_Handshake_SemiAutoPark_c:
            if (!*rty_MeAP_b_StandStill) {
              SWC_AP_StateMachine_DW.is_Park_Exit =
                SWC_AP_StateMachine_IN_SemiAutoParkSCANNING;
              MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Scanning;
              *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Enabled_Seeking;
              SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeStart = false;
              SWC_AP_StateMachine_enter_internal_SemiAutoParkSCANNING
                (rtu_IbVBII_VehState_LowSpd,
                 rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
                 rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat,
                 rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
                 rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
                 rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
                 rty_MeAP_e_PAMChimeRepnRateSVM);
            } else if (SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces) {
              SWC_AP_StateMachine_DW.is_Park_Exit =
                SWC_AP_StateMachine_IN_Active_SemiAutoParkExit;
              MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Park_Out;
              *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Engaged_Semi;
              if (!*rtu_MeAP_b_SteerActionReq) {
                SWC_AP_StateMachine_DW.is_Active_SemiAutoParkExit =
                  SWC_AP_StateMachine_IN_MutlipleMoves;
                SWC_AP_StateMachine_DW.is_MutlipleMoves_g =
                  SWC_AP_StateMachine_IN_MOVE_BACKWARD;
                *rty_IeAP_b_VehMnvrDirSPM = false;

                /* false = Backward, true= Forward  */
                *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_MOVE_BACKWARD;
                MeAP_cnt_StateDebugVar = 88U;
                SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = false;
                if ((rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 0.2)
                    && (!SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated)) {
                  tmp = SWC_AP_StateMachine_DW.MeAP_cnt_Move + 1;
                  if (tmp > 255) {
                    tmp = 255;
                  }

                  SWC_AP_StateMachine_DW.MeAP_cnt_Move = (uint8_T)tmp;
                  SWC_AP_StateMachine_DW.MeAP_b_MvCntUpdated = true;
                }
              } else {
                SWC_AP_StateMachine_DW.is_Active_SemiAutoParkExit =
                  SWC_AP_StateMachine_IN_WAIT_FOR_STEER_REAR;
                *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR;
                MeAP_cnt_StateDebugVar = 86U;
              }
            } else {
              if (SWC_AP_StateMachine_B.MeAP_b_EPSHandshakeActv) {
                SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
                  TeAP_e_SPMLatCtrlReqSts_SPM_Request;
              } else {
                SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
                  TeAP_e_SPMLatCtrlReqSts_Idle;
              }

              if ((!SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout) &&
                  (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts ==
                   TeVBII_e_SPMLatCtrlRespSts_HasOpen) &&
                  (SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
                   TeAP_e_SPMLatCtrlReqSts_SPM_Request)) {
                SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = true;
              } else {
                SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = false;
              }

              if ((SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts ==
                   TeAP_e_SPMLatCtrlReqSts_SPM_Request) &&
                  (!SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces)) {
                tmp = SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt +
                  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
                if (tmp > 65535) {
                  tmp = 65535;
                }

                SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = (uint16_T)tmp;
                if (SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt >
                    *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout) {
                  SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = true;
                  MeAP_cnt_TransDebugVar = 182U;
                } else {
                  SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
                  MeAP_cnt_TransDebugVar = 181U;
                }
              } else {
                SWC_AP_StateMachine_DW.MeAP_s_EPSInterfaceCnt = 0U;
                SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout = false;
                MeAP_cnt_TransDebugVar = 179U;
              }
            }
            break;

           default:
            /* case IN_SemiAutoParkSCANNING: */
            SWC_AP_StateMachine_SemiAutoParkSCANNING
              (rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus,
               rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel,
               rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
               rtu_IbVBII_VehState_LowSpd,
               rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
               rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout,
               rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMActvStat,
               rty_IeAP_b_VehMnvrDirSPM, rty_MeAP_e_PAMVolSigSVM,
               rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
               rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
               rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM,
               rty_MeAP_b_StandStill);
            break;
          }
        }
        break;
      }
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_enter_internal_Standstill(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill)
{
  int32_T tmp;
  SWC_AP_StateMachine_DW.MeAP_cnt_StandstillTimer = 0U;
  SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout = false;
  SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = 0U;
  SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;
  if (*rty_MeAP_b_StandStill) {
    if (!SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_StandstillTimer +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_StandstillTimer = (uint16_T)tmp;
      SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout =
        (SWC_AP_StateMachine_DW.MeAP_cnt_StandstillTimer >=
         KeAP_cnt_StandstillTimeoutDur);
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout = true;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout = false;
  }

  if (SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout &&
      (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
       TeAP_e_FiltdGearState_Parking)) {
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_P;
  } else {
    *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
  }

  if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
       TeAP_e_FiltdGearState_Parking) ||
      (rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts ==
       TeVBII_e_VehEPBSts_Applied)) {
    if (!SWC_AP_StateMachine_DW.MeAP_b_RelVehControl) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt >=
          KeAP_cnt_RelCntrlWaitThd) {
        SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = true;
        MeAP_cnt_TransDebugVar = 2241U;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;
        MeAP_cnt_TransDebugVar = 2240U;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = true;
      MeAP_cnt_TransDebugVar = 241U;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = 0U;
    SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;
    MeAP_cnt_TransDebugVar = 240U;
  }

  if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt < KeAP_cnt_AbortHMIWaitCnt)
  {
    if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
          KeAP_cnt_AbortHMIWaitCnt) {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
      }
    } else {
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_BUTTON_PRESS_TAKECONTROL(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (*rty_MeAP_b_StandStill) {
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
    MeAP_cnt_StateDebugVar = 234U;
    SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
  } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
             KeAP_cnt_AbortHMIWaitCnt) {
    if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
          KeAP_cnt_AbortHMIWaitCnt) {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
      }
    } else {
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_CRUISE_CONTROL_ENGAGED_TAKECONTROL(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (*rty_MeAP_b_StandStill) {
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
    MeAP_cnt_StateDebugVar = 234U;
    SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
  } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
             KeAP_cnt_AbortHMIWaitCnt) {
    if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
          KeAP_cnt_AbortHMIWaitCnt) {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
      }
    } else {
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_DOOR_OPEN_TAKECONTROL(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (*rty_MeAP_b_StandStill) {
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
    MeAP_cnt_StateDebugVar = 234U;
    SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
  } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
             KeAP_cnt_AbortHMIWaitCnt) {
    if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
          KeAP_cnt_AbortHMIWaitCnt) {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
      }
    } else {
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_ESC_ACTIVE_TAKECONTROL(const TbVBIA_VehState_AP *
  rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (*rty_MeAP_b_StandStill) {
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
    MeAP_cnt_StateDebugVar = 234U;
    SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
  } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
             KeAP_cnt_AbortHMIWaitCnt) {
    if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
          KeAP_cnt_AbortHMIWaitCnt) {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
      }
    } else {
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_FRONT_WIPE_TAKECONTROL(const TbVBIA_VehState_AP *
  rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (*rty_MeAP_b_StandStill) {
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
    MeAP_cnt_StateDebugVar = 234U;
    SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
  } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
             KeAP_cnt_AbortHMIWaitCnt) {
    if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
          KeAP_cnt_AbortHMIWaitCnt) {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
      }
    } else {
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_LIFTGATE_OPEN_TAKECONTROL(const
  TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *
  rty_MeAP_b_StandStill)
{
  int32_T tmp;
  if (*rty_MeAP_b_StandStill) {
    SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
    MeAP_cnt_StateDebugVar = 234U;
    SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
  } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
             KeAP_cnt_AbortHMIWaitCnt) {
    if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
          KeAP_cnt_AbortHMIWaitCnt) {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
      }
    } else {
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
    }
  } else {
    SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_Abort_HMI_3(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  switch (SWC_AP_StateMachine_DW.is_Abort_HMI_3) {
   case SWC_AP_StateMachine_IN_BUTTON_PRESS_TAKECONTROL:
    SWC_AP_StateMachine_BUTTON_PRESS_TAKECONTROL(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    break;

   case SWC_AP_StateMachine_IN_CRUISE_CONTROL_ENGAGED_TAKECONTROL:
    SWC_AP_StateMachine_CRUISE_CONTROL_ENGAGED_TAKECONTROL
      (rtu_IbVBII_VehState_LowSpd, rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
       rty_MeAP_e_HMIPopUp, rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    break;

   case SWC_AP_StateMachine_IN_DOOR_OPEN_TAKECONTROL:
    SWC_AP_StateMachine_DOOR_OPEN_TAKECONTROL(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    break;

   case SWC_AP_StateMachine_IN_DRIVER_OVERRIDE_TAKECONTROL:
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt <=
        KeAP_cnt_ScreenWaitTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = (uint16_T)tmp;
      SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle =
        (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt >=
         KeAP_cnt_ScreenWaitTimeoutDur);
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle = false;
    }
    break;

   case SWC_AP_StateMachine_IN_ESC_ACTIVE_TAKECONTROL:
    SWC_AP_StateMachine_ESC_ACTIVE_TAKECONTROL(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    break;

   case SWC_AP_StateMachine_IN_FRONT_WIPE_TAKECONTROL:
    SWC_AP_StateMachine_FRONT_WIPE_TAKECONTROL(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    break;

   case SWC_AP_StateMachine_IN_LIFTGATE_OPEN_TAKECONTROL:
    SWC_AP_StateMachine_LIFTGATE_OPEN_TAKECONTROL(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
      rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    break;

   case SWC_AP_StateMachine_IN_LO4_ACTIVE_TAKECONTROL:
    if (*rty_MeAP_b_StandStill) {
      SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
      MeAP_cnt_StateDebugVar = 234U;
      SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
        rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
               KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
    break;

   case SWC_AP_StateMachine_IN_MANUAL_PARK_TAKECONTROL:
    if (*rty_MeAP_b_StandStill) {
      SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
      MeAP_cnt_StateDebugVar = 234U;
      SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
        rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
               KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
    break;

   case SWC_AP_StateMachine_IN_MANUAL_PARK_TAKECONTROL_Default:
    if (*rty_MeAP_b_StandStill) {
      SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
      MeAP_cnt_StateDebugVar = 234U;
      SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
        rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
               KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
    break;

   case SWC_AP_StateMachine_IN_REAR_WIPE_TAKECONTROL:
    if (*rty_MeAP_b_StandStill) {
      SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
      MeAP_cnt_StateDebugVar = 234U;
      SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
        rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
               KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
    break;

   case SWC_AP_StateMachine_IN_ReleaseControl:
    break;

   case SWC_AP_StateMachine_IN_SPEED_TOO_HIGH_TAKECONTROL:
    if (*rty_MeAP_b_StandStill) {
      SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
      MeAP_cnt_StateDebugVar = 234U;
      SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
        rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
               KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
    break;

   case SWC_AP_StateMachine_IN_Standstill:
    if (SWC_AP_StateMachine_DW.MeAP_b_RelVehControl || MeAP_b_DriverOverride) {
      /* MeAP_b_HandsOn] */
      SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
        SWC_AP_StateMachine_IN_ReleaseControl;
      MeAP_cnt_StateDebugVar = 235U;
      *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
      SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
        TeAP_e_SPMLatCtrlReqSts_Idle;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
      *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
      SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle = true;
    } else {
      if (*rty_MeAP_b_StandStill) {
        if (!SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_StandstillTimer +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_StandstillTimer = (uint16_T)tmp;
          SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout =
            (SWC_AP_StateMachine_DW.MeAP_cnt_StandstillTimer >=
             KeAP_cnt_StandstillTimeoutDur);
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout = true;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout = false;
      }

      if (SWC_AP_StateMachine_DW.MeAP_b_StandstillTimeout &&
          (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
           TeAP_e_FiltdGearState_Parking)) {
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_P;
      } else {
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      }

      if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
           TeAP_e_FiltdGearState_Parking) ||
          (rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts ==
           TeVBII_e_VehEPBSts_Applied)) {
        if (!SWC_AP_StateMachine_DW.MeAP_b_RelVehControl) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt >=
              KeAP_cnt_RelCntrlWaitThd) {
            SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = true;
            MeAP_cnt_TransDebugVar = 2241U;
          } else {
            SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;
            MeAP_cnt_TransDebugVar = 2240U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = true;
          MeAP_cnt_TransDebugVar = 241U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = 0U;
        SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;
        MeAP_cnt_TransDebugVar = 240U;
      }

      if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
          KeAP_cnt_AbortHMIWaitCnt) {
        if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
              KeAP_cnt_AbortHMIWaitCnt) {
            SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
          } else {
            SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
          }
        } else {
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
      }
    }
    break;

   case SWC_AP_StateMachine_IN_TRAILER_CONNECTED_TAKECONTROL:
    if (*rty_MeAP_b_StandStill) {
      SWC_AP_StateMachine_DW.is_Abort_HMI_3 = SWC_AP_StateMachine_IN_Standstill;
      MeAP_cnt_StateDebugVar = 234U;
      SWC_AP_StateMachine_enter_internal_Standstill(rtu_IbVBII_VehState_LowSpd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_MeAP_e_HMIPopUp,
        rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt <
               KeAP_cnt_AbortHMIWaitCnt) {
      if (!SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt = (uint16_T)tmp;
        if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortHMIWaitCnt >=
            KeAP_cnt_AbortHMIWaitCnt) {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = true;
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
        }
      } else {
        *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_IDLE;
      }
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortHMITimeOut = false;
    }
    break;

   case SWC_AP_StateMachine_IN_WHEEL_TOUCHED_TAKECONTROL:
    if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt <=
        KeAP_cnt_ScreenWaitTimeoutDur) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = (uint16_T)tmp;
      SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle =
        (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt >=
         KeAP_cnt_ScreenWaitTimeoutDur);
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle = false;
    }
    break;

   case SWC_AP_StateMachine_IN_WaitTimer:
    if (SWC_AP_StateMachine_DW.MeAP_b_AbortDelayTimeOut) {
      SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
        SWC_AP_StateMachine_IN_WHEEL_TOUCHED_TAKECONTROL;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_WHEEL_TOUCHED_TAKECONTROL;
      MeAP_cnt_StateDebugVar = 230U;
      *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
      SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
        TeAP_e_SPMLatCtrlReqSts_Idle;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
      *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = 0U;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt <=
          KeAP_cnt_ScreenWaitTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = (uint16_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle =
          (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt >=
           KeAP_cnt_ScreenWaitTimeoutDur);
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle = false;
      }
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt <
               KeAP_cnt_AbortDelayWaitCnt) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt = (uint16_T)tmp;
      SWC_AP_StateMachine_DW.MeAP_b_AbortDelayTimeOut =
        (SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt >=
         KeAP_cnt_AbortDelayWaitCnt);
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortDelayTimeOut = false;
    }
    break;

   default:
    /* case IN_WaitTimer1: */
    if (SWC_AP_StateMachine_DW.MeAP_b_AbortDelayTimeOut) {
      SWC_AP_StateMachine_DW.is_Abort_HMI_3 =
        SWC_AP_StateMachine_IN_DRIVER_OVERRIDE_TAKECONTROL;
      *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_DRIVER_OVERRIDE_TAKECONTROL;
      *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
      SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
        TeAP_e_SPMLatCtrlReqSts_Idle;
      *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
      *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
      *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
      *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
      MeAP_cnt_StateDebugVar = 231U;
      SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = 0U;
      if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt <=
          KeAP_cnt_ScreenWaitTimeoutDur) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = (uint16_T)tmp;
        SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle =
          (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt >=
           KeAP_cnt_ScreenWaitTimeoutDur);
      } else {
        SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle = false;
      }
    } else if (SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt <
               KeAP_cnt_AbortDelayWaitCnt) {
      tmp = SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt +
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt = (uint16_T)tmp;
      SWC_AP_StateMachine_DW.MeAP_b_AbortDelayTimeOut =
        (SWC_AP_StateMachine_DW.MeAP_cnt_AbortDelayWaitCnt >=
         KeAP_cnt_AbortDelayWaitCnt);
    } else {
      SWC_AP_StateMachine_DW.MeAP_b_AbortDelayTimeOut = false;
    }
    break;
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_Abort(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus
  *rty_IeAP_e_SPMLedSts, boolean_T *rty_IeAP_b_SPMFailSts, boolean_T
  *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *rty_IeAP_e_SPMActvStat, boolean_T
  *rty_IeAP_b_VehMnvrDirSPM, boolean_T *rty_IeAP_b_StandstillReq,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill)
{
  MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Abort;
  if (SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle || (MeAP_b_PreEPSInterfaceAbort1 &&
       (!MeAP_b_PreEPSInterfaceAbort2) &&
       ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
         TeAP_e_FiltdGearState_ReverseGear) ||
        (SWC_AP_StateMachine_DW.temporalCounter_i1 >= 167U))) ||
      ((!MeAP_b_PreEPSInterfaceAbort1) && MeAP_b_PreEPSInterfaceAbort2 &&
       ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
         TeAP_e_FiltdGearState_ReverseGear) ||
        (SWC_AP_StateMachine_DW.temporalCounter_i1 >= 167U)))) {
    SWC_AP_StateMachine_exit_internal_Abort();
    SWC_AP_StateMachine_DW.is_ON = SWC_AP_StateMachine_IN_STANDBY;
    SWC_AP_StateMachine_enter_atomic_STANDBY(rty_IeAP_e_InterfaceBSM,
      rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
      rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
      rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
      rty_IeAP_e_GearShiftReq, rty_MeAP_e_PAMVolSigSVM,
      rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
      rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
      rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
    SWC_AP_StateMachine_DW.is_STANDBY = SWC_AP_StateMachine_IN_Idle;
    SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
    MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
    MeAP_cnt_StateDebugVar = 97U;
  } else {
    switch (SWC_AP_StateMachine_DW.is_Abort) {
     case SWC_AP_StateMachine_IN_Abort_HMI_1:
      *rty_IeAP_b_SPMFailSts = false;
      *rty_IeAP_b_SPMFaultSts = false;
      *rty_IeAP_b_StandstillReq = true;
      break;

     case SWC_AP_StateMachine_IN_Abort_HMI_2:
      *rty_IeAP_b_SPMFailSts = false;
      *rty_IeAP_b_SPMFaultSts = false;
      *rty_IeAP_b_StandstillReq = true;
      break;

     default:
      /* case IN_Abort_HMI_3: */
      SWC_AP_StateMachine_Abort_HMI_3(rtu_IbVBII_VehState_LowSpd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_IeAP_e_InterfaceBSM,
        rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
        rty_IeAP_e_SPMActvStat, rty_IeAP_e_GearShiftReq, rty_MeAP_b_StandStill);
      break;
    }
  }
}

/* Function for Chart: '<S5>/AUTOPARK_StateMachine' */
static void SWC_AP_StateMachine_ON(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const TeHMI_e_UsrParkOutSide
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const TeAP_e_UsrPPPAManeuverSel
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const boolean_T
  *rtu_MbDiag_PlantModeOn, const boolean_T *rtu_MeAP_b_PosMet, const boolean_T
  *rtu_MeAP_b_SteerActionReq, const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam,
  const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd, const boolean_T
  *rtu_MeAP_b_ObjInPath, const boolean_T *rtu_IbFID_PPPA_MeAP_b_PPPADisable,
  const real32_T *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd, const real32_T *
  rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist,
  TeAP_e_InterfaceBSM *rty_IeAP_e_InterfaceBSM, TeAP_e_ParKMnvrActv
  *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp,
  TeAP_e_PAMLedCtrlStatus *rty_IeAP_e_SPMLedSts, boolean_T
  *rty_IeAP_b_SPMFailSts, boolean_T *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *
  rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_IeAP_b_StandstillReq, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  boolean_T tmp_0;

  /* Outputs for Atomic SubSystem: '<S3>/AP_Statemachine' */
  /* Chart: '<S5>/AUTOPARK_StateMachine' incorporates:
   *  Constant: '<S5>/Constant8'
   */
  if ((rtu_IbVBII_VehState_LowSpd->IeVBII_e_CmdIgnSts != TeVBII_e_CmdIgnSts_RUN)
      && (!*rtu_MbDiag_PlantModeOn)) {
    SWC_AP_StateMachine_exit_internal_ON();
    SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine =
      SWC_AP_StateMachine_IN_OFF;
    SWC_AP_StateMachine_enter_atomic_OFF(rty_IeAP_e_InterfaceBSM,
      rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
      rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
      rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
      rty_IeAP_e_GearShiftReq);
  } else if ((rtu_IbVBII_VehState_LowSpd->IeVBII_e_EngineSts !=
              TeVBII_e_EngineSts_Engine_On) &&
             (rtu_IbVBII_VehState_LowSpd->IeVBII_e_EssEngState ==
              TeVBII_e_EssEngState_SNA)) {
    SWC_AP_StateMachine_exit_internal_ON();
    SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine =
      SWC_AP_StateMachine_IN_INIT;
    SWC_AP_StateMachine_enter_atomic_INIT(rty_IeAP_e_InterfaceBSM,
      rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
      rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
      rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
      rty_IeAP_e_GearShiftReq);
    SWC_AP_StateMachine_enter_internal_INIT(rtu_IbVBII_VehState_LowSpd,
      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
  } else if ((*rtu_IbFID_PPPA_MeAP_b_PPPADisable) &&
             SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus) {
    SWC_AP_StateMachine_exit_internal_ON();
    SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine =
      SWC_AP_StateMachine_IN_FAULT;
    MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Fault;
    *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
    *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
    *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
    *rty_IeAP_b_VehMnvrDirSPM = false;

    /* false = Backward, true= Forward  */
    SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
      TeAP_e_SPMLatCtrlReqSts_Faulted;
    *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Faulted;
    *rty_IeAP_b_SPMFaultSts = true;
    *rty_IeAP_b_SPMFailSts = true;
    SWC_AP_StateMachine_DW.is_FAULT = SWC_AP_StateMachine_IN_Fault_Init;
    MeAP_cnt_StateDebugVar = 609U;
  } else {
    switch (SWC_AP_StateMachine_DW.is_ON) {
     case SWC_AP_StateMachine_IN_ACTIVE_AUTOPARK:
      SWC_AP_StateMachine_ACTIVE_AUTOPARK
        (rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus,
         rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle,
         rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel,
         rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake,
         rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
         rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel,
         rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
         rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide,
         rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, rtu_MeAP_b_PosMet,
         rtu_MeAP_b_SteerActionReq, rtu_IbVBII_VehState_LowSpd,
         rtu_MbNVM_ProxyParam, rtu_MeAP_e_GearCmd, rtu_MeAP_b_ObjInPath,
         rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
         rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout,
         rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout,
         rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
         rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur,
         rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
         rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
         rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur,
         rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt,
         rtu_MeAP_b_ObjPrestFC, rtu_MeAP_b_ObjPrestRC, rtu_IeAP_kph_TrgtVehSpd,
         rtu_IeAP_cm_TrgtDist, rty_IeAP_e_InterfaceBSM, rty_IeAP_e_ParKMnvrActv,
         rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts, rty_IeAP_b_SPMFailSts,
         rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
         rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
         rty_MeAP_b_VCOpPaused, rty_IeAP_e_GearShiftReq, rty_MeAP_e_PAMVolSigSVM,
         rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
         rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
         rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM,
         rty_MeAP_b_StandStill);
      break;

     case SWC_AP_StateMachine_IN_Abort:
      SWC_AP_StateMachine_Abort(rtu_IbVBII_VehState_LowSpd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, rty_IeAP_e_InterfaceBSM,
        rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
        rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
        rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
        rty_IeAP_e_GearShiftReq, rty_MeAP_e_PAMVolSigSVM,
        rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
        rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
        rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM,
        rty_MeAP_b_StandStill);
      break;

     case SWC_AP_StateMachine_IN_Complete:
      MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Complete;

      /* (!MeAP_b_BSMHandshakeSts &&!MeAP_b_EPSHandshakeSts) ||after(5,sec) */
      if (SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete) {
        SWC_AP_StateMachine_DW.is_Complete =
          SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
        SWC_AP_StateMachine_DW.is_ON = SWC_AP_StateMachine_IN_STANDBY;
        SWC_AP_StateMachine_enter_atomic_STANDBY(rty_IeAP_e_InterfaceBSM,
          rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
          rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
          rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
          rty_IeAP_e_GearShiftReq, rty_MeAP_e_PAMVolSigSVM,
          rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
          rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
          rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
        SWC_AP_StateMachine_DW.is_STANDBY = SWC_AP_StateMachine_IN_Idle;
        SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
        MeAP_cnt_StateDebugVar = 97U;
      } else {
        switch (SWC_AP_StateMachine_DW.is_Complete) {
         case SWC_AP_StateMachine_IN_COMPLETE_HMI_FRONT_REAR:
          if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
              TeAP_e_FiltdGearState_ReverseGear) {
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_COMPLETE_HMI_REAR;
          } else {
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_COMPLETE_HMI_FRONT;
          }

          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt <=
              KeAP_cnt_ScreenWaitTimeoutDur) {
            tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt +
              *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
            if (tmp > 65535) {
              tmp = 65535;
            }

            SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = (uint16_T)tmp;
            SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete =
              ((SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt <=
                KeAP_cnt_ScreenWaitTimeoutDur) ||
               (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                TeAP_e_FiltdGearState_Parking));
          } else {
            SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete = false;
          }
          break;

         case SWC_AP_StateMachine_IN_COMPLETE_RELEASE:
          if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt <=
              KeAP_cnt_ScreenWaitTimeoutDur) {
            tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt +
              *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
            if (tmp > 65535) {
              tmp = 65535;
            }

            SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = (uint16_T)tmp;
            if ((SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt >=
                 KeAP_cnt_ScreenWaitTimeoutDur) ||
                (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                 TeAP_e_FiltdGearState_ReverseGear)) {
              SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete = true;
              MeAP_cnt_TransDebugVar = 405U;
            } else {
              SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete = false;
              MeAP_cnt_TransDebugVar = 404U;
            }
          } else {
            SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete = false;
            MeAP_cnt_TransDebugVar = 406U;
          }
          break;

         default:
          /* case IN_ParkIN_RelVehControlDelay: */
          if (SWC_AP_StateMachine_DW.MeAP_b_RelVehControl) {
            SWC_AP_StateMachine_DW.is_Complete =
              SWC_AP_StateMachine_IN_COMPLETE_RELEASE;
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_COMPLETE_RELEASE;
            *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;

            /*  BSM Handshake Closed  */
            *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
            SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
              TeAP_e_SPMLatCtrlReqSts_Idle;

            /*  EPS Handshake Closed  */
            *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Idle;
            *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
            *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_Off;
            SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeSts = false;
            MeAP_cnt_StateDebugVar = 401U;
            SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = 0U;
            if (SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt <=
                KeAP_cnt_ScreenWaitTimeoutDur) {
              tmp = SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt +
                *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
              if (tmp > 65535) {
                tmp = 65535;
              }

              SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt = (uint16_T)tmp;
              if ((SWC_AP_StateMachine_DW.MeAP_cnt_ScreenWaitCnt >=
                   KeAP_cnt_ScreenWaitTimeoutDur) ||
                  (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                   TeAP_e_FiltdGearState_ReverseGear)) {
                SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete = true;
                MeAP_cnt_TransDebugVar = 405U;
              } else {
                SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete = false;
                MeAP_cnt_TransDebugVar = 404U;
              }
            } else {
              SWC_AP_StateMachine_DW.MeAP_b_ManoeuvreComplete = false;
              MeAP_cnt_TransDebugVar = 406U;
            }
          } else if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
                      TeAP_e_FiltdGearState_Parking) ||
                     (rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts ==
                      TeVBII_e_VehEPBSts_Applied)) {
            if (!SWC_AP_StateMachine_DW.MeAP_b_RelVehControl) {
              tmp = SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt +
                *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
              if (tmp > 65535) {
                tmp = 65535;
              }

              SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = (uint16_T)tmp;
              if (SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt >=
                  KeAP_cnt_RelCntrlWaitThd) {
                SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = true;
                MeAP_cnt_TransDebugVar = 2241U;
              } else {
                SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;
                MeAP_cnt_TransDebugVar = 2240U;
              }
            } else {
              SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = true;
              MeAP_cnt_TransDebugVar = 241U;
            }
          } else {
            SWC_AP_StateMachine_DW.MeAP_b_RelVehControl = false;
            SWC_AP_StateMachine_DW.MeAP_cnt_RelCntrlWaitCnt = 0U;
            MeAP_cnt_TransDebugVar = 240U;
          }
          break;
        }
      }
      break;

     default:
      /* case IN_STANDBY: */
      MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Standby;
      *rty_IeAP_b_SPMFailSts = false;
      *rty_IeAP_b_SPMFaultSts = false;
      *rty_IeAP_b_StandstillReq = false;
      if (MeAP_b_VehCndSts &&
          (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <
           *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd) && MeAP_b_APActConAvl
          && SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus) {
        SWC_AP_StateMachine_DW.is_STANDBY =
          SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
        SWC_AP_StateMachine_DW.is_ON = SWC_AP_StateMachine_IN_ACTIVE_AUTOPARK;
        MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Active;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Scanning;

        /* Update Local timer and variable  */
        SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m = false;
        SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f = false;
        SWC_AP_StateMachine_DW.MeAP_b_BSMHandshakeSucces = false;
        SWC_AP_StateMachine_DW.MeAP_b_EPSHandshakeSucces = false;
        *rty_MeAP_b_ChimeActvReqLHFSVM = false;
        *rty_MeAP_b_ChimeActvReqRHFSVM = false;
        *rty_MeAP_b_ChimeActvReqLHRSVM = false;
        *rty_MeAP_b_ChimeActvReqRHRSVM = false;
        *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
        *rty_MeAP_e_PAMChimeRepnRateSVM = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
        *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;

        /* Update VCAN output */
        *rty_IeAP_e_SPMLedSts = TeAP_e_PAMLedCtrlStatus_ContinousLight;
        *rty_IeAP_b_SPMFailSts = false;
        *rty_IeAP_b_SPMFaultSts = false;
        *rty_IeAP_e_ParKMnvrActv = TeAP_e_ParKMnvrActv_Enabled_Seeking;
        *rty_IeAP_e_SPMActvStat = TeAP_e_SPMActvStat_Not_Active;
        *rty_IeAP_e_InterfaceBSM = TeAP_e_InterfaceBSM_Idle;
        SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts =
          TeAP_e_SPMLatCtrlReqSts_Idle;
        *rty_IeAP_e_GearShiftReq = TeAP_e_GearShiftReq_Idle;
        *rty_IeAP_b_VehMnvrDirSPM = false;
        *rty_IeAP_b_StandstillReq = false;
        SWC_AP_StateMachine_DW.is_ACTIVE_AUTOPARK = SWC_AP_StateMachine_IN_IDLE;
        MeAP_cnt_StateDebugVar = 6U;
        SWC_AP_StateMachine_DW.MeAP_s_CamHandshakeSecCnt = 0U;
        if (!*rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake) {
          tmp = SWC_AP_StateMachine_DW.MeAP_s_CamHandshakeSecCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_s_CamHandshakeSecCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_s_CamHandshakeSecCnt > ((uint16_T)500U))
          {
            SWC_AP_StateMachine_B.MeAP_b_CamHandshakeTimeout = true;
            MeAP_cnt_TransDebugVar = 5U;
          } else {
            SWC_AP_StateMachine_B.MeAP_b_CamHandshakeTimeout = false;
            MeAP_cnt_TransDebugVar = 4U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_s_CamHandshakeSecCnt = 0U;
          SWC_AP_StateMachine_B.MeAP_b_CamHandshakeTimeout = false;
          MeAP_cnt_TransDebugVar = 2U;
        }

        /* Park-IN scenario */
        if ((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
             TeAP_e_FiltdGearState_Drive) ||
            (((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
               TeAP_e_FiltdGearState_Neutral) ||
              (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
               TeAP_e_FiltdGearState_Parking)) && (!*rtu_MeAP_b_ObjPrestFC))) {
          *rty_IeAP_b_VehMnvrDirSPM = true;

          /* false = Backward, true= Forward  */
          *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD;
          SWC_AP_StateMachine_DW.MeAP_b_PPPAMode = TeAP_b_PPPAMode_ParkIn;
          MeAP_cnt_StateDebugVar = 9U;
        } else {
          /* Park-EXIT scenario */
          if (((rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
                TeAP_e_FiltdGearState_Neutral) ||
               (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
                TeAP_e_FiltdGearState_Parking)) && (*rtu_MeAP_b_ObjPrestFC)) {
            *rty_IeAP_b_VehMnvrDirSPM = true;

            /* false = Backward, true= Forward  */
            *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT;
            SWC_AP_StateMachine_DW.MeAP_b_PPPAMode = TeAP_b_PPPAMode_ParkExit;
            MeAP_cnt_StateDebugVar = 10U;
          } else {
            if (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
                TeAP_e_FiltdGearState_ReverseGear) {
              *rty_IeAP_b_VehMnvrDirSPM = false;

              /* false = Backward, true= Forward  */
              *rty_MeAP_e_HMIPopUp = TeAP_e_HMIPopUp_SHIFT_TO_DRIVE;
            }
          }
        }
      } else {
        tmp_0 = !MeAP_b_VehCndSts;
        if (SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus && (tmp_0 ||
             (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
              *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd) ||
             (!MeAP_b_APActConAvl))) {
          SWC_AP_StateMachine_DW.is_STANDBY =
            SWC_AP_StateMachine_IN_NO_ACTIVE_CHILD;
          SWC_AP_StateMachine_DW.is_ON = SWC_AP_StateMachine_IN_Abort;
          SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
          MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Abort;
          SWC_AP_StateMachine_DW.MeAP_b_HMIToIdle = false;

          /* Chime reset */
          *rty_MeAP_b_ChimeActvReqLHFSVM = false;
          *rty_MeAP_b_ChimeActvReqRHFSVM = false;
          *rty_MeAP_b_ChimeActvReqLHRSVM = false;
          *rty_MeAP_b_ChimeActvReqRHRSVM = false;
          *rty_MeAP_e_PAMChimeTypSVM = TeAP_e_PAMChimeTyp_None;
          *rty_MeAP_e_PAMChimeRepnRateSVM =
            TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
          *rty_MeAP_e_PAMVolSigSVM = TeAP_e_PAMVolSig_None;
          SWC_AP_StateMachine_enter_internal_Abort(rtu_IbVBII_VehState_LowSpd,
            rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
            rty_IeAP_e_InterfaceBSM, rty_IeAP_e_ParKMnvrActv,
            rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts, rty_IeAP_b_SPMFailSts,
            rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
            rty_IeAP_b_StandstillReq, rty_IeAP_e_GearShiftReq);
        } else if (SWC_AP_StateMachine_DW.is_STANDBY ==
                   SWC_AP_StateMachine_IN_Idle) {
          if (MeAP_b_VehCndSts &&
              (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <
               *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd) &&
              (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
               TeAP_e_FiltdGearState_ReverseGear) &&
              (SWC_AP_StateMachine_DW.temporalCounter_i1 >= 167U)) {
            SWC_AP_StateMachine_DW.is_STANDBY =
              SWC_AP_StateMachine_IN_SEEK_BCKGND;
            MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Scanning;
            MeAP_cnt_StateDebugVar = 96U;
          }
        } else {
          /* case IN_SEEK_BCKGND: */
          if (tmp_0 || (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >=
                        *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd) ||
              (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
               TeAP_e_FiltdGearState_ReverseGear)) {
            SWC_AP_StateMachine_DW.is_STANDBY = SWC_AP_StateMachine_IN_Idle;
            SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
            MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
            MeAP_cnt_StateDebugVar = 97U;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S5>/AUTOPARK_StateMachine' */
  /* End of Outputs for SubSystem: '<S3>/AP_Statemachine' */
}

/* System initialize for referenced model: 'SWC_AP_StateMachine' */
void SWC_AP_StateMachine_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S186>/Unit Delay9' */
  SWC_AP_StateMachine_DW.UnitDelay9_DSTATE = TeAP_e_FiltdGearState_Parking;

  /* SystemInitialize for Atomic SubSystem: '<S3>/AP_PreRequisits' */
  /* SystemInitialize for Atomic SubSystem: '<S4>/APA_EnablingCondition' */
  /* InitializeConditions for Delay: '<S18>/Delay' */
  SWC_AP_StateMachine_DW.icLoad = 1U;

  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_m3 = true;

  /* InitializeConditions for Delay: '<S19>/Delay' */
  SWC_AP_StateMachine_DW.icLoad_m = 1U;

  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_o = true;

  /* End of SystemInitialize for SubSystem: '<S4>/APA_EnablingCondition' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/AP_EnablingCondition' */
  /* SystemInitialize for Atomic SubSystem: '<S12>/AP_FeatureEnable' */
  /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_n = true;

  /* End of SystemInitialize for SubSystem: '<S12>/AP_FeatureEnable' */
  /* End of SystemInitialize for SubSystem: '<S4>/AP_EnablingCondition' */
  /* End of SystemInitialize for SubSystem: '<S3>/AP_PreRequisits' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/AP_Statemachine' */
  /* SystemInitialize for Chart: '<S5>/AUTOPARK_StateMachine' */
  SWC_AP_StateMachine_DW.MeAP_s_SeekPhaseSecCnt = ((uint16_T)0U);
  SWC_AP_StateMachine_DW.MeAP_s_SeekSpdExceedSecCnt = ((uint16_T)0U);
  SWC_AP_StateMachine_DW.MeAP_b_PPPAMode = TeAP_b_PPPAMode_Idle;
  MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
  MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Off;
  SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts = TeAP_e_SPMLatCtrlReqSts_Idle;

  /* End of SystemInitialize for SubSystem: '<S3>/AP_Statemachine' */
}

/* Output and update for referenced model: 'SWC_AP_StateMachine' */
void SWC_AP_StateMachine(const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const TeHMI_e_UsrParkOutSide
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const TeAP_e_UsrPPPAManeuverSel
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const boolean_T
  *rtu_MbDiag_PlantModeOn, const boolean_T *rtu_MbDiag_TestModeForceOn, const
  boolean_T *rtu_MeAP_b_PosMet, const boolean_T *rtu_MeAP_b_SteerActionReq,
  const TbVBIA_VehState_AP *rtu_IbVBII_VehState_LowSpd, const TbNVM_ReadParam
  *rtu_MbNVM_ReadParam, const TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam, const
  TbUSS_DiagFlag *rtu_MbUSS_DiagFlag, const IJobFPAOutput_t
  *rtu_LwSpd_FPA_Output, const TeAutoPark_e_GearCmd *rtu_MeAP_e_GearCmd, const
  boolean_T *rtu_MeAP_b_ManualParkReq, const boolean_T *rtu_MeAP_b_ObjInPath,
  const boolean_T *rtu_IbFID_PA_MeAP_b_FrntSenorFail, const boolean_T
  *rtu_IbFID_PA_MeAP_b_FrntSenorBlock, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RearSenorFail, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RearSenorBlock, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPAActvTrlr, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPAActv4LOW, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPADisable, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur, const boolean_T
  *rtu_IbAP_InputVrntTunParam_KeAP_b_AutoParkEn, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, const boolean_T
  *rtu_MeAP_b_ObjPrestFC, const boolean_T *rtu_MeAP_b_ObjPrestRC, const
  TeAP_e_PAMOffStatus2BT *rtu_MeAP_e_PAMOffStatus2BT, const real32_T
  *rtu_IeAP_kph_TrgtVehSpd, const real32_T *rtu_IeAP_cm_TrgtDist, const real32_T
  *rtu_IeAP_nm_StrwTrqReq, const TeTHA_e_RearBrkSupprInfo
  *rtu_MeTHA_e_RearBrkSupprInfo, TeAP_e_FrntSnsrStatus
  *rty_IeAP_e_FrntSnsrStatus, TeAP_e_RearSnsrStatus *rty_IeAP_e_RearSnsrStatus,
  boolean_T *rty_MeAP_b_DisableDiag, boolean_T
  *rty_MeAP_b_AutoParkEnblSwtStuckStatus, TeAP_e_InterfaceBSM
  *rty_IeAP_e_InterfaceBSM, TeAP_e_SPMLatCtrlReqSts *rty_IeAP_e_SPMLatCtrlReqSts,
  TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv, TeAP_e_HMIPopUp
  *rty_MeAP_e_HMIPopUp, TeAP_e_PAMLedCtrlStatus *rty_IeAP_e_SPMLedSts, boolean_T
  *rty_IeAP_b_SPMFailSts, boolean_T *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *
  rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_IeAP_b_StandstillReq, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_PAMVolSig
  *rty_MeAP_e_PAMVolSigSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *
  rty_MeAP_b_ChimeActvReqLHRSVM, boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp
  *rty_MeAP_e_PAMChimeTypSVM, TeAP_e_PAMChimeRepnRate
  *rty_MeAP_e_PAMChimeRepnRateSVM, uint8_T *rty_MeAP_b_parkout_perp_left,
  boolean_T *rty_MeAP_b_VCActive, boolean_T *rty_MeAP_b_PerpNoseIn, uint8_T
  *rty_MeAP_m_ParkSpotType, boolean_T *rty_MeAP_b_ParkOut, boolean_T
  *rty_MeAP_b_ResetVCKM, TeAP_e_USSSupplyPwrSt *rty_MeAP_e_USSSupplyPwrSt,
  TeAP_e_USSSystemMode *rty_MeAP_e_USSSystemMode, TeAP_e_USSSystemState
  *rty_MeAP_e_USSSystemState, uint8_T *rty_MeAP_e_USSFiringMode, boolean_T
  *rty_MeAP_b_USSReInit, boolean_T *rty_MeAP_b_ScanSts, uint16_T
  *rty_IbAP_SMDebugOut_MeAP_cnt_StateDebugVar, uint16_T
  *rty_IbAP_SMDebugOut_MeAP_cnt_TransDebugVar, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_VCOpPaused, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_BSMInterfaceTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_EPSInterfaceTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_GearShiftWaitTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_CamHandshakeTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_ObjInPathTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_PausedPressBtnTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_SeekSpdExceedTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_APInitSts, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_DriverOverride, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_StandStill, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_BSMHandshakeActv, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_VehCndSts, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_FeatureEnbl, boolean_T *rty_MeAP_b_StandStill)
{
  int32_T tmp;
  real_T tmp_0;
  boolean_T tmp_1;
  boolean_T LogicalOperator2_p_tmp;
  boolean_T guard1 = false;

  /* RelationalOperator: '<S184>/Relational Operator1' incorporates:
   *  Constant: '<S188>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_i =
    (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotType ==
     ParkingSlotType_E_PW_PARALLEL);

  /* RelationalOperator: '<S184>/Relational Operator3' incorporates:
   *  Constant: '<S193>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotSide ==
     SlotSide_E_SLOT_RIGHT);

  /* Logic: '<S184>/Logical Operator2' */
  SWC_AP_StateMachine_B.LogicalOperator3_i =
    (SWC_AP_StateMachine_B.LogicalOperator3_i &&
     SWC_AP_StateMachine_B.RelationalOperator12);

  /* Switch: '<S184>/Switch' incorporates:
   *  Constant: '<S184>/Constant'
   */
  if (SWC_AP_StateMachine_B.LogicalOperator3_i) {
    *rty_MeAP_m_ParkSpotType = ((uint8_T)1U);
  } else {
    /* RelationalOperator: '<S184>/Relational Operator5' incorporates:
     *  Constant: '<S195>/Constant'
     */
    SWC_AP_StateMachine_B.RelationalOperator5 =
      (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotSide ==
       SlotSide_E_SLOT_LEFT);

    /* RelationalOperator: '<S184>/Relational Operator4' incorporates:
     *  Constant: '<S194>/Constant'
     */
    SWC_AP_StateMachine_B.LogicalOperator3_l =
      (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotType ==
       ParkingSlotType_E_PW_PARALLEL);

    /* Logic: '<S184>/Logical Operator3' */
    SWC_AP_StateMachine_B.LogicalOperator3_l =
      (SWC_AP_StateMachine_B.LogicalOperator3_l &&
       SWC_AP_StateMachine_B.RelationalOperator5);

    /* Switch: '<S184>/Switch1' incorporates:
     *  Constant: '<S184>/Constant1'
     */
    if (SWC_AP_StateMachine_B.LogicalOperator3_l) {
      SWC_AP_StateMachine_B.Switch1_m = ((uint8_T)2U);
    } else {
      /* RelationalOperator: '<S184>/Relational Operator7' incorporates:
       *  Constant: '<S197>/Constant'
       */
      SWC_AP_StateMachine_B.RelationalOperator7 =
        (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotSide ==
         SlotSide_E_SLOT_RIGHT);

      /* RelationalOperator: '<S184>/Relational Operator6' incorporates:
       *  Constant: '<S196>/Constant'
       */
      SWC_AP_StateMachine_B.LogicalOperator4_my =
        (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotType ==
         ParkingSlotType_E_PW_PERPENDICULAR);

      /* Logic: '<S184>/Logical Operator4' */
      SWC_AP_StateMachine_B.LogicalOperator4_my =
        (SWC_AP_StateMachine_B.LogicalOperator4_my &&
         SWC_AP_StateMachine_B.RelationalOperator7);

      /* Switch: '<S184>/Switch2' incorporates:
       *  Constant: '<S184>/Constant2'
       */
      if (SWC_AP_StateMachine_B.LogicalOperator4_my) {
        SWC_AP_StateMachine_B.Switch2_p = ((uint8_T)3U);
      } else {
        /* RelationalOperator: '<S184>/Relational Operator8' incorporates:
         *  Constant: '<S198>/Constant'
         */
        SWC_AP_StateMachine_B.RelationalOperator8 =
          (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotSide ==
           SlotSide_E_SLOT_LEFT);

        /* RelationalOperator: '<S184>/Relational Operator2' incorporates:
         *  Constant: '<S192>/Constant'
         */
        SWC_AP_StateMachine_B.LogicalOperator5 =
          (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotType ==
           ParkingSlotType_E_PW_PERPENDICULAR);

        /* Logic: '<S184>/Logical Operator5' */
        SWC_AP_StateMachine_B.LogicalOperator5 =
          (SWC_AP_StateMachine_B.LogicalOperator5 &&
           SWC_AP_StateMachine_B.RelationalOperator8);

        /* Switch: '<S184>/Switch3' incorporates:
         *  Constant: '<S184>/Constant3'
         */
        if (SWC_AP_StateMachine_B.LogicalOperator5) {
          SWC_AP_StateMachine_B.Switch3_c = ((uint8_T)4U);
        } else {
          /* RelationalOperator: '<S184>/Relational Operator10' incorporates:
           *  Constant: '<S189>/Constant'
           */
          SWC_AP_StateMachine_B.RelationalOperator10 =
            (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotSide ==
             SlotSide_E_SLOT_RIGHT);

          /* RelationalOperator: '<S184>/Relational Operator9' incorporates:
           *  Constant: '<S199>/Constant'
           */
          SWC_AP_StateMachine_B.LogicalOperator6 =
            (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotType ==
             ParkingSlotType_E_PW_DIAGONAL);

          /* Logic: '<S184>/Logical Operator6' */
          SWC_AP_StateMachine_B.LogicalOperator6 =
            (SWC_AP_StateMachine_B.LogicalOperator6 &&
             SWC_AP_StateMachine_B.RelationalOperator10);

          /* Switch: '<S184>/Switch4' incorporates:
           *  Constant: '<S184>/Constant4'
           */
          if (SWC_AP_StateMachine_B.LogicalOperator6) {
            SWC_AP_StateMachine_B.Switch4_b = ((uint8_T)5U);
          } else {
            /* RelationalOperator: '<S184>/Relational Operator11' incorporates:
             *  Constant: '<S190>/Constant'
             */
            SWC_AP_StateMachine_B.RelationalOperator11 =
              (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotSide
               == SlotSide_E_SLOT_LEFT);

            /* RelationalOperator: '<S184>/Relational Operator12' incorporates:
             *  Constant: '<S191>/Constant'
             */
            SWC_AP_StateMachine_B.LogicalOperator7 =
              (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotType
               == ParkingSlotType_E_PW_DIAGONAL);

            /* Logic: '<S184>/Logical Operator7' */
            SWC_AP_StateMachine_B.LogicalOperator7 =
              (SWC_AP_StateMachine_B.LogicalOperator7 &&
               SWC_AP_StateMachine_B.RelationalOperator11);

            /* Switch: '<S184>/Switch5' incorporates:
             *  Constant: '<S184>/Constant5'
             *  Constant: '<S184>/Constant6'
             */
            if (SWC_AP_StateMachine_B.LogicalOperator7) {
              SWC_AP_StateMachine_B.Switch5 = ((uint8_T)6U);
            } else {
              SWC_AP_StateMachine_B.Switch5 = ((uint8_T)0U);
            }

            /* End of Switch: '<S184>/Switch5' */
            SWC_AP_StateMachine_B.Switch4_b = SWC_AP_StateMachine_B.Switch5;
          }

          /* End of Switch: '<S184>/Switch4' */
          SWC_AP_StateMachine_B.Switch3_c = SWC_AP_StateMachine_B.Switch4_b;
        }

        /* End of Switch: '<S184>/Switch3' */
        SWC_AP_StateMachine_B.Switch2_p = SWC_AP_StateMachine_B.Switch3_c;
      }

      /* End of Switch: '<S184>/Switch2' */
      SWC_AP_StateMachine_B.Switch1_m = SWC_AP_StateMachine_B.Switch2_p;
    }

    /* End of Switch: '<S184>/Switch1' */
    *rty_MeAP_m_ParkSpotType = SWC_AP_StateMachine_B.Switch1_m;
  }

  /* End of Switch: '<S184>/Switch' */

  /* Logic: '<S133>/Logical Operator4' */
  SWC_AP_StateMachine_B.LogicalOperator4 = ((*rtu_IbFID_PA_MeAP_b_FrntSenorFail)
    || (*rtu_IbFID_PA_MeAP_b_RearSenorFail));

  /* UnitDelay: '<S3>/Unit Delay3' */
  SWC_AP_StateMachine_B.UnitDelay3 = SWC_AP_StateMachine_DW.UnitDelay3_DSTATE_d;

  /* UnitDelay: '<S3>/Unit Delay1' */
  SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout =
    SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_f;

  /* UnitDelay: '<S3>/Unit Delay' */
  SWC_AP_StateMachine_B.IeAP_e_ParKMnvrActv =
    SWC_AP_StateMachine_DW.UnitDelay_DSTATE_f;

  /* UnitDelay: '<S3>/Unit Delay2' */
  SWC_AP_StateMachine_B.UnitDelay2 = SWC_AP_StateMachine_DW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay4' */
  SWC_AP_StateMachine_B.UnitDelay4_o =
    SWC_AP_StateMachine_DW.UnitDelay4_DSTATE_a;

  /* UnitDelay: '<S3>/Unit Delay5' */
  SWC_AP_StateMachine_B.UnitDelay5_l =
    SWC_AP_StateMachine_DW.UnitDelay5_DSTATE_k;

  /* UnitDelay: '<S3>/Unit Delay6' */
  SWC_AP_StateMachine_B.UnitDelay6_j =
    SWC_AP_StateMachine_DW.UnitDelay6_DSTATE_c;

  /* UnitDelay: '<S3>/Unit Delay7' */
  SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus =
    SWC_AP_StateMachine_DW.UnitDelay7_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay8' */
  SWC_AP_StateMachine_B.UnitDelay8 = SWC_AP_StateMachine_DW.UnitDelay8_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay9' */
  SWC_AP_StateMachine_B.UnitDelay9 = SWC_AP_StateMachine_DW.UnitDelay9_DSTATE_p;

  /* UnitDelay: '<S3>/Unit Delay10' */
  SWC_AP_StateMachine_B.UnitDelay10 = SWC_AP_StateMachine_DW.UnitDelay10_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay11' */
  SWC_AP_StateMachine_B.UnitDelay11 = SWC_AP_StateMachine_DW.UnitDelay11_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay12' */
  SWC_AP_StateMachine_B.UnitDelay12 = SWC_AP_StateMachine_DW.UnitDelay12_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay13' */
  SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout =
    SWC_AP_StateMachine_DW.UnitDelay13_DSTATE;

  /* UnitDelay: '<S3>/Unit Delay14' */
  SWC_AP_StateMachine_B.MeAP_b_InitBrkPedlPressed_h =
    SWC_AP_StateMachine_DW.UnitDelay14_DSTATE;

  /* Outputs for Atomic SubSystem: '<S3>/AP_PreRequisits' */
  /* Outputs for Atomic SubSystem: '<S4>/APA_EnablingCondition' */
  /* RelationalOperator: '<S18>/Relational Operator1' incorporates:
   *  Constant: '<S20>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
     TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S18>/Relational Operator' incorporates:
   *  Constant: '<S21>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
     TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S18>/Logical Operator2' */
  SWC_AP_StateMachine_B.LogicalOperator2 =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.RelationalOperator_g);

  /* Delay: '<S18>/Delay' */
  if (SWC_AP_StateMachine_DW.icLoad != 0) {
    SWC_AP_StateMachine_DW.Delay_DSTATE = SWC_AP_StateMachine_B.LogicalOperator2;
  }

  SWC_AP_StateMachine_B.Delay = SWC_AP_StateMachine_DW.Delay_DSTATE;

  /* End of Delay: '<S18>/Delay' */

  /* Logic: '<S22>/Logical Operator2' incorporates:
   *  Logic: '<S23>/Logical Operator'
   */
  SWC_AP_StateMachine_B.reset_f =
    !rtu_IbVBII_VehState_LowSpd->IeVBII_b_FrntParkAsstReq;
  SWC_AP_StateMachine_B.RelationalOperator_g = SWC_AP_StateMachine_B.reset_f;

  /* UnitDelay: '<S22>/Unit Delay' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    SWC_AP_StateMachine_DW.UnitDelay_DSTATE_k;

  /* Logic: '<S22>/Logical Operator3' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (SWC_AP_StateMachine_B.RelationalOperator_g &&
     SWC_AP_StateMachine_B.RelationalOperator_o);

  /* UnitDelay: '<S23>/Unit Delay' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    SWC_AP_StateMachine_DW.UnitDelay_DSTATE_m3;

  /* Logic: '<S18>/Logical Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (SWC_AP_StateMachine_B.RelationalOperator_g &&
     SWC_AP_StateMachine_B.RelationalOperator_o);

  /* Switch: '<S18>/Switch' */
  if (SWC_AP_StateMachine_B.RelationalOperator_g) {
    /* Logic: '<S18>/Logical Operator4' */
    SWC_AP_StateMachine_B.LogicalOperator4_m = !SWC_AP_StateMachine_B.Delay;
    SWC_AP_StateMachine_B.MeAP_b_FPASwtStatus =
      SWC_AP_StateMachine_B.LogicalOperator4_m;
  } else {
    SWC_AP_StateMachine_B.MeAP_b_FPASwtStatus = SWC_AP_StateMachine_B.Delay;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Logic: '<S18>/Logical Operator' */
  SWC_AP_StateMachine_B.MeAP_b_FPASwtStuckStatus =
    !SWC_AP_StateMachine_B.RelationalOperator_o;

  /* UnitDelay: '<S23>/Unit Delay2' */
  SWC_AP_StateMachine_B.UnitDelay2_b = SWC_AP_StateMachine_B.Switch3_l;

  /* UnitDelay: '<S23>/Unit Delay1' */
  SWC_AP_StateMachine_B.UnitDelay1_p =
    SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_k;

  /* Switch: '<S23>/Switch3' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Switch: '<S23>/Switch1'
   */
  if (SWC_AP_StateMachine_B.reset_f) {
    tmp_0 = floor(0.0);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 65536.0);
    }

    SWC_AP_StateMachine_B.Switch3_l = (uint16_T)(tmp_0 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-tmp_0 : (int32_T)(uint16_T)tmp_0);
  } else {
    if (SWC_AP_StateMachine_B.UnitDelay1_p) {
      /* Switch: '<S23>/Switch1' */
      SWC_AP_StateMachine_B.Switch1_e =
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd;
    } else {
      /* RelationalOperator: '<S23>/Relational Operator' incorporates:
       *  Switch: '<S23>/Switch1'
       */
      SWC_AP_StateMachine_B.RelationalOperator_h =
        (SWC_AP_StateMachine_B.UnitDelay2_b <=
         *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);

      /* Switch: '<S23>/Switch2' incorporates:
       *  Constant: '<S23>/Constant'
       *  Switch: '<S23>/Switch1'
       */
      if (SWC_AP_StateMachine_B.RelationalOperator_h) {
        SWC_AP_StateMachine_B.Switch2_k = 0.0;
      } else {
        /* Sum: '<S23>/Subtract' */
        SWC_AP_StateMachine_B.Subtract_j = (uint16_T)
          (SWC_AP_StateMachine_B.UnitDelay2_b -
           *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
        SWC_AP_StateMachine_B.Switch2_k = SWC_AP_StateMachine_B.Subtract_j;
      }

      /* End of Switch: '<S23>/Switch2' */

      /* Switch: '<S23>/Switch1' */
      SWC_AP_StateMachine_B.Switch1_e = SWC_AP_StateMachine_B.Switch2_k;
    }

    tmp_0 = floor(SWC_AP_StateMachine_B.Switch1_e);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 65536.0);
    }

    SWC_AP_StateMachine_B.Switch3_l = (uint16_T)(tmp_0 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-tmp_0 : (int32_T)(uint16_T)tmp_0);
  }

  /* End of Switch: '<S23>/Switch3' */

  /* RelationalOperator: '<S23>/Relational Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_g = (SWC_AP_StateMachine_B.Switch3_l >=
    *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);

  /* Logic: '<S23>/Logical Operator8' */
  SWC_AP_StateMachine_B.LogicalOperator8_e = (SWC_AP_StateMachine_B.reset_f ||
    SWC_AP_StateMachine_B.RelationalOperator_g);

  /* RelationalOperator: '<S19>/Relational Operator1' incorporates:
   *  Constant: '<S24>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
     TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S19>/Relational Operator' incorporates:
   *  Constant: '<S25>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
     TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S19>/Logical Operator2' */
  SWC_AP_StateMachine_B.LogicalOperator2_h =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.RelationalOperator_g);

  /* Delay: '<S19>/Delay' */
  if (SWC_AP_StateMachine_DW.icLoad_m != 0) {
    SWC_AP_StateMachine_DW.Delay_DSTATE_l =
      SWC_AP_StateMachine_B.LogicalOperator2_h;
  }

  SWC_AP_StateMachine_B.Delay_a = SWC_AP_StateMachine_DW.Delay_DSTATE_l;

  /* End of Delay: '<S19>/Delay' */

  /* Logic: '<S26>/Logical Operator2' incorporates:
   *  Logic: '<S27>/Logical Operator'
   */
  SWC_AP_StateMachine_B.reset_j =
    !rtu_IbVBII_VehState_LowSpd->IeVBII_b_ParkAsstReq;
  SWC_AP_StateMachine_B.RelationalOperator_g = SWC_AP_StateMachine_B.reset_j;

  /* UnitDelay: '<S26>/Unit Delay' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    SWC_AP_StateMachine_DW.UnitDelay_DSTATE_la;

  /* Logic: '<S26>/Logical Operator3' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (SWC_AP_StateMachine_B.RelationalOperator_g &&
     SWC_AP_StateMachine_B.RelationalOperator_o);

  /* UnitDelay: '<S27>/Unit Delay' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    SWC_AP_StateMachine_DW.UnitDelay_DSTATE_o;

  /* Logic: '<S19>/Logical Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (SWC_AP_StateMachine_B.RelationalOperator_g &&
     SWC_AP_StateMachine_B.RelationalOperator_o);

  /* Switch: '<S19>/Switch' */
  if (SWC_AP_StateMachine_B.RelationalOperator_g) {
    /* Logic: '<S19>/Logical Operator4' */
    SWC_AP_StateMachine_B.LogicalOperator4_o = !SWC_AP_StateMachine_B.Delay_a;
    SWC_AP_StateMachine_B.MeAP_b_RPASwtStatus =
      SWC_AP_StateMachine_B.LogicalOperator4_o;
  } else {
    SWC_AP_StateMachine_B.MeAP_b_RPASwtStatus = SWC_AP_StateMachine_B.Delay_a;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Logic: '<S19>/Logical Operator' */
  SWC_AP_StateMachine_B.MeAP_b_RPASwtStuckStatus =
    !SWC_AP_StateMachine_B.RelationalOperator_o;

  /* UnitDelay: '<S27>/Unit Delay2' */
  SWC_AP_StateMachine_B.UnitDelay2_m = SWC_AP_StateMachine_B.Switch3_p;

  /* UnitDelay: '<S27>/Unit Delay1' */
  SWC_AP_StateMachine_B.UnitDelay1_px =
    SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_fl;

  /* Switch: '<S27>/Switch3' incorporates:
   *  Constant: '<S27>/Constant1'
   *  Switch: '<S27>/Switch1'
   */
  if (SWC_AP_StateMachine_B.reset_j) {
    tmp_0 = floor(0.0);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 65536.0);
    }

    SWC_AP_StateMachine_B.Switch3_p = (uint16_T)(tmp_0 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-tmp_0 : (int32_T)(uint16_T)tmp_0);
  } else {
    if (SWC_AP_StateMachine_B.UnitDelay1_px) {
      /* Switch: '<S27>/Switch1' */
      SWC_AP_StateMachine_B.Switch1_c =
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd;
    } else {
      /* RelationalOperator: '<S27>/Relational Operator' incorporates:
       *  Switch: '<S27>/Switch1'
       */
      SWC_AP_StateMachine_B.RelationalOperator_k =
        (SWC_AP_StateMachine_B.UnitDelay2_m <=
         *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);

      /* Switch: '<S27>/Switch2' incorporates:
       *  Constant: '<S27>/Constant'
       *  Switch: '<S27>/Switch1'
       */
      if (SWC_AP_StateMachine_B.RelationalOperator_k) {
        SWC_AP_StateMachine_B.Switch2_i = 0.0;
      } else {
        /* Sum: '<S27>/Subtract' */
        SWC_AP_StateMachine_B.Subtract_a = (uint16_T)
          (SWC_AP_StateMachine_B.UnitDelay2_m -
           *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
        SWC_AP_StateMachine_B.Switch2_i = SWC_AP_StateMachine_B.Subtract_a;
      }

      /* End of Switch: '<S27>/Switch2' */

      /* Switch: '<S27>/Switch1' */
      SWC_AP_StateMachine_B.Switch1_c = SWC_AP_StateMachine_B.Switch2_i;
    }

    tmp_0 = floor(SWC_AP_StateMachine_B.Switch1_c);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 65536.0);
    }

    SWC_AP_StateMachine_B.Switch3_p = (uint16_T)(tmp_0 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-tmp_0 : (int32_T)(uint16_T)tmp_0);
  }

  /* End of Switch: '<S27>/Switch3' */

  /* RelationalOperator: '<S27>/Relational Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_g = (SWC_AP_StateMachine_B.Switch3_p >=
    *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);

  /* Logic: '<S27>/Logical Operator8' */
  SWC_AP_StateMachine_B.LogicalOperator8_a = (SWC_AP_StateMachine_B.reset_j ||
    SWC_AP_StateMachine_B.RelationalOperator_g);

  /* Update for Delay: '<S18>/Delay' */
  SWC_AP_StateMachine_DW.icLoad = 0U;
  SWC_AP_StateMachine_DW.Delay_DSTATE =
    SWC_AP_StateMachine_B.MeAP_b_FPASwtStatus;

  /* Update for UnitDelay: '<S22>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_k =
    rtu_IbVBII_VehState_LowSpd->IeVBII_b_FrntParkAsstReq;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_m3 =
    SWC_AP_StateMachine_B.LogicalOperator8_e;

  /* Update for UnitDelay: '<S23>/Unit Delay1' */
  SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_k = SWC_AP_StateMachine_B.reset_f;

  /* Update for Delay: '<S19>/Delay' */
  SWC_AP_StateMachine_DW.icLoad_m = 0U;
  SWC_AP_StateMachine_DW.Delay_DSTATE_l =
    SWC_AP_StateMachine_B.MeAP_b_RPASwtStatus;

  /* Update for UnitDelay: '<S26>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_la =
    rtu_IbVBII_VehState_LowSpd->IeVBII_b_ParkAsstReq;

  /* Update for UnitDelay: '<S27>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_o =
    SWC_AP_StateMachine_B.LogicalOperator8_a;

  /* Update for UnitDelay: '<S27>/Unit Delay1' */
  SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_fl = SWC_AP_StateMachine_B.reset_j;

  /* End of Outputs for SubSystem: '<S4>/APA_EnablingCondition' */

  /* UnitDelay: '<S15>/Unit Delay1' */
  SWC_AP_StateMachine_B.UnitDelay1 = SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_fv;

  /* UnitDelay: '<S15>/Unit Delay2' */
  SWC_AP_StateMachine_B.UnitDelay2_i =
    SWC_AP_StateMachine_DW.UnitDelay2_DSTATE_b;

  /* SignalConversion generated from: '<S4>/Bus Selector4' */
  SWC_AP_StateMachine_B.IeVBII_e_VehEPBSts =
    rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts;

  /* SignalConversion generated from: '<S4>/Bus Selector4' */
  SWC_AP_StateMachine_B.IeVBII_b_Override =
    rtu_IbVBII_VehState_LowSpd->IeVBII_b_Override;

  /* SignalConversion generated from: '<S4>/Bus Selector4' */
  SWC_AP_StateMachine_B.IeVBII_per_PdlPosAct =
    rtu_IbVBII_VehState_LowSpd->IeVBII_per_PdlPosAct;

  /* Outputs for Atomic SubSystem: '<S4>/AP_EnablingCondition' */
  /* SignalConversion generated from: '<S12>/Bus Selector' */
  SWC_AP_StateMachine_B.KeAP_b_SVSPresent =
    rtu_MbNVM_ProxyParam->KeAP_b_SVSPresent;

  /* Outputs for Atomic SubSystem: '<S12>/AP_FeatureEnable' */
  /* RelationalOperator: '<S28>/Relational Operator13' incorporates:
   *  Constant: '<S36>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ACCSysSts !=
     TeVBII_e_ACCSysSts_ACC_Engaged_BrakeOnly);

  /* RelationalOperator: '<S28>/Relational Operator2' incorporates:
   *  Constant: '<S39>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ACCSysSts !=
     TeVBII_e_ACCSysSts_NCC_Engaged);

  /* RelationalOperator: '<S28>/Relational Operator14' incorporates:
   *  Constant: '<S37>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ACCSysSts !=
     TeVBII_e_ACCSysSts_ACC_Engaged);

  /* Logic: '<S28>/Logical Operator4' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o &&
     SWC_AP_StateMachine_B.RelationalOperator_g &&
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* RelationalOperator: '<S28>/Relational Operator11' incorporates:
   *  Constant: '<S44>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts !=
     TeVBII_e_ParkingIntrvntionSts_Faulted_External);

  /* RelationalOperator: '<S28>/Relational Operator12' incorporates:
   *  Constant: '<S45>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts !=
     TeVBII_e_ParkingIntrvntionSts_Faulted_Internal);

  /* Logic: '<S28>/Logical Operator3' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (SWC_AP_StateMachine_B.RelationalOperator_g &&
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Logic: '<S28>/Logical Operator8' incorporates:
   *  Logic: '<S15>/Logical Operator8'
   *  Logic: '<S30>/Logical Operator2'
   *  Logic: '<S31>/Logical Operator7'
   */
  LogicalOperator2_p_tmp = !rtu_IbVBII_VehState_LowSpd->IeVBII_b_ActvParkMode;
  SWC_AP_StateMachine_B.LogicalOperator2_p = LogicalOperator2_p_tmp;

  /* Logic: '<S28>/Logical Operator6' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (SWC_AP_StateMachine_B.RelationalOperator_g &&
     SWC_AP_StateMachine_B.RelationalOperator_o &&
     rtu_IbVBII_VehState_LowSpd->IeVBII_b_GearShiftReqAccept &&
     rtu_IbVBII_VehState_LowSpd->IeVBII_b_ShifterAutoconnectSts &&
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Logic: '<S28>/Logical Operator7' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (SWC_AP_StateMachine_B.RelationalOperator_g ||
     rtu_IbVBII_VehState_LowSpd->IeVBII_b_ActvParkMode);

  /* RelationalOperator: '<S28>/Relational Operator8' incorporates:
   *  Constant: '<S41>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.IeVBII_e_VehEPBSts !=
     TeVBII_e_VehEPBSts_Fault_EPB_Released);

  /* RelationalOperator: '<S28>/Relational Operator9' incorporates:
   *  Constant: '<S42>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.IeVBII_e_VehEPBSts !=
     TeVBII_e_VehEPBSts_Fault_EPB_Applied);

  /* RelationalOperator: '<S28>/Relational Operator10' incorporates:
   *  Constant: '<S43>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (SWC_AP_StateMachine_B.IeVBII_e_VehEPBSts !=
     TeVBII_e_VehEPBSts_Fault_Present);

  /* Logic: '<S28>/Logical Operator2' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* RelationalOperator: '<S28>/Relational Operator5' incorporates:
   *  Constant: '<S38>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_TCaseRangeSts !=
     TeVBII_e_TCaseRangeSts_LOW);

  /* Logic: '<S28>/Logical Operator' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p &&
     rtu_MbNVM_ProxyParam->KeAP_b_CanNode67DTCM);

  /* Logic: '<S28>/Logical Operator5' */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    !rtu_MbNVM_ProxyParam->KeAP_b_CanNode67DTCM;

  /* Logic: '<S28>/Logical Operator1' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a ||
     (*rtu_IbFID_PPPA_MeAP_b_PPPAActv4LOW));

  /* RelationalOperator: '<S28>/Relational Operator6' incorporates:
   *  Constant: '<S40>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ExtBrkReqDisabled ==
     TeVBII_e_ExtBrkReqDisabled_NoRequest);

  /* Logic: '<S28>/Logical Operator10' */
  MeAP_b_APActConAvl = (SWC_AP_StateMachine_B.RelationalOperator_o &&
                        SWC_AP_StateMachine_B.LogicalOperator2_p &&
                        (*rtu_IbAP_InputVrntTunParam_KeAP_b_AutoParkEn) &&
                        SWC_AP_StateMachine_B.LogicalOperator3_a &&
                        SWC_AP_StateMachine_B.KeAP_b_SVSPresent &&
                        SWC_AP_StateMachine_B.RelationalOperator_g);

  /* RelationalOperator: '<S28>/Relational Operator' incorporates:
   *  Constant: '<S35>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
     TeAutoPark_e_AutoParkStatus_Active);

  /* Logic: '<S28>/Logical Operator9' */
  SWC_AP_StateMachine_B.LogicalOperator9 =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_b_AutoParkEnblSwt &&
     SWC_AP_StateMachine_B.RelationalOperator_g);

  /* Logic: '<S46>/Logical Operator2' incorporates:
   *  Logic: '<S47>/Logical Operator'
   */
  SWC_AP_StateMachine_B.reset = !SWC_AP_StateMachine_B.LogicalOperator9;
  SWC_AP_StateMachine_B.RelationalOperator_g = SWC_AP_StateMachine_B.reset;

  /* UnitDelay: '<S46>/Unit Delay' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    SWC_AP_StateMachine_DW.UnitDelay_DSTATE_m;

  /* Logic: '<S46>/Logical Operator3' */
  SWC_AP_StateMachine_B.LogicalOperator3 =
    (SWC_AP_StateMachine_B.RelationalOperator_g &&
     SWC_AP_StateMachine_B.RelationalOperator_o);

  /* UnitDelay: '<S28>/Unit Delay1' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_i;

  /* UnitDelay: '<S48>/Unit Delay1' */
  SWC_AP_StateMachine_B.UnitDelay1_o =
    SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_e;

  /* UnitDelay: '<S49>/Unit Delay' */
  SWC_AP_StateMachine_B.UnitDelay_n = SWC_AP_StateMachine_B.Switch1_e5;

  /* Switch: '<S49>/Switch1' incorporates:
   *  Constant: '<S49>/Constant'
   */
  if (SWC_AP_StateMachine_B.RelationalOperator_g) {
    SWC_AP_StateMachine_B.Switch1_e5 = false;
  } else {
    /* Logic: '<S48>/Logical Operator' */
    SWC_AP_StateMachine_B.LogicalOperator1_f =
      !SWC_AP_StateMachine_B.UnitDelay1_o;

    /* Logic: '<S48>/Logical Operator1' */
    SWC_AP_StateMachine_B.LogicalOperator1_f =
      (SWC_AP_StateMachine_B.LogicalOperator1_f &&
       SWC_AP_StateMachine_B.LogicalOperator9);

    /* Switch: '<S49>/Switch2' incorporates:
     *  Constant: '<S49>/Constant1'
     */
    if (SWC_AP_StateMachine_B.LogicalOperator1_f) {
      SWC_AP_StateMachine_B.Switch2_f = true;
    } else {
      SWC_AP_StateMachine_B.Switch2_f = SWC_AP_StateMachine_B.UnitDelay_n;
    }

    /* End of Switch: '<S49>/Switch2' */
    SWC_AP_StateMachine_B.Switch1_e5 = SWC_AP_StateMachine_B.Switch2_f;
  }

  /* End of Switch: '<S49>/Switch1' */

  /* UnitDelay: '<S47>/Unit Delay' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    SWC_AP_StateMachine_DW.UnitDelay_DSTATE_n;

  /* Logic: '<S28>/Logical Operator11' */
  SWC_AP_StateMachine_B.RelationalOperator_g = (SWC_AP_StateMachine_B.Switch1_e5
    && SWC_AP_StateMachine_B.LogicalOperator3 &&
    SWC_AP_StateMachine_B.RelationalOperator_g);

  /* UnitDelay: '<S28>/Unit Delay' */
  SWC_AP_StateMachine_B.UnitDelay_b = SWC_AP_StateMachine_B.MeAP_b_APASwtStatus;

  /* Switch: '<S28>/Switch' */
  if (SWC_AP_StateMachine_B.RelationalOperator_g) {
    /* Logic: '<S28>/Logical Operator12' */
    SWC_AP_StateMachine_B.LogicalOperator12 = !SWC_AP_StateMachine_B.UnitDelay_b;
    SWC_AP_StateMachine_B.MeAP_b_APASwtStatus =
      SWC_AP_StateMachine_B.LogicalOperator12;
  }

  /* End of Switch: '<S28>/Switch' */

  /* UnitDelay: '<S47>/Unit Delay1' */
  SWC_AP_StateMachine_B.UnitDelay1_f =
    SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_fb;

  /* UnitDelay: '<S47>/Unit Delay2' */
  SWC_AP_StateMachine_B.UnitDelay2_l = SWC_AP_StateMachine_B.Switch3_d;

  /* Switch: '<S47>/Switch3' incorporates:
   *  Constant: '<S47>/Constant1'
   *  Switch: '<S47>/Switch1'
   */
  if (SWC_AP_StateMachine_B.reset) {
    tmp_0 = floor(0.0);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 65536.0);
    }

    SWC_AP_StateMachine_B.Switch3_d = (uint16_T)(tmp_0 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-tmp_0 : (int32_T)(uint16_T)tmp_0);
  } else {
    if (SWC_AP_StateMachine_B.UnitDelay1_f) {
      /* Switch: '<S47>/Switch1' */
      SWC_AP_StateMachine_B.Switch1 =
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd;
    } else {
      /* RelationalOperator: '<S47>/Relational Operator' incorporates:
       *  Switch: '<S47>/Switch1'
       */
      SWC_AP_StateMachine_B.RelationalOperator_n =
        (SWC_AP_StateMachine_B.UnitDelay2_l <=
         *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);

      /* Switch: '<S47>/Switch2' incorporates:
       *  Constant: '<S47>/Constant'
       *  Switch: '<S47>/Switch1'
       */
      if (SWC_AP_StateMachine_B.RelationalOperator_n) {
        SWC_AP_StateMachine_B.Switch2 = 0.0;
      } else {
        /* Sum: '<S47>/Subtract' */
        SWC_AP_StateMachine_B.Subtract_l = (uint16_T)
          (SWC_AP_StateMachine_B.UnitDelay2_l -
           *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
        SWC_AP_StateMachine_B.Switch2 = SWC_AP_StateMachine_B.Subtract_l;
      }

      /* End of Switch: '<S47>/Switch2' */

      /* Switch: '<S47>/Switch1' */
      SWC_AP_StateMachine_B.Switch1 = SWC_AP_StateMachine_B.Switch2;
    }

    tmp_0 = floor(SWC_AP_StateMachine_B.Switch1);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 65536.0);
    }

    SWC_AP_StateMachine_B.Switch3_d = (uint16_T)(tmp_0 < 0.0 ? (int32_T)
      (uint16_T)-(int16_T)(uint16_T)-tmp_0 : (int32_T)(uint16_T)tmp_0);
  }

  /* End of Switch: '<S47>/Switch3' */

  /* RelationalOperator: '<S47>/Relational Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_g = (SWC_AP_StateMachine_B.Switch3_d >=
    *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);

  /* Logic: '<S47>/Logical Operator8' */
  SWC_AP_StateMachine_B.LogicalOperator8 = (SWC_AP_StateMachine_B.reset ||
    SWC_AP_StateMachine_B.RelationalOperator_g);

  /* UnitDelay: '<S34>/Unit Delay' */
  SWC_AP_StateMachine_B.UnitDelay_a = SWC_AP_StateMachine_DW.UnitDelay_DSTATE_a;

  /* Chart: '<S34>/Chart1' */
  if (SWC_AP_StateMachine_DW.is_active_c2_SWC_AP_StateMachine == 0U) {
    SWC_AP_StateMachine_DW.is_active_c2_SWC_AP_StateMachine = 1U;
    SWC_AP_StateMachine_DW.is_c2_SWC_AP_StateMachine =
      SWC_AP_StateMachine_IN_Not_Pressed_OFF;
    SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus = false;
    *rty_MeAP_b_AutoParkEnblSwtStuckStatus = false;
    SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = false;
    SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = true;
  } else {
    guard1 = false;
    switch (SWC_AP_StateMachine_DW.is_c2_SWC_AP_StateMachine) {
     case SWC_AP_StateMachine_IN_Not_Pressed_OFF:
      SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus = false;
      SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = false;
      SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = true;
      if (rtu_IbVBII_VehState_LowSpd->IeVBII_b_AutoParkEnblSwt &&
          (!SWC_AP_StateMachine_B.UnitDelay_a)) {
        SWC_AP_StateMachine_DW.is_c2_SWC_AP_StateMachine =
          SWC_AP_StateMachine_IN_Pressed;
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = true;
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = false;
        SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt = 0U;
        if ((SWC_AP_StateMachine_B.IeAP_e_ParKMnvrActv !=
             TeAP_e_ParKMnvrActv_Engaged_Full) &&
            rtu_IbVBII_VehState_LowSpd->IeVBII_b_AutoParkEnblSwt) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt = (uint16_T)tmp;
          *rty_MeAP_b_AutoParkEnblSwtStuckStatus =
            ((SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt >
              *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd) && true);
        } else {
          SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt = 0U;
          *rty_MeAP_b_AutoParkEnblSwtStuckStatus = false;
        }
      }
      break;

     case SWC_AP_StateMachine_IN_Not_Pressed_ON:
      SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus = true;
      SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = false;
      SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = true;
      if ((SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
           TeAutoPark_e_AutoParkStatus_Abort) ||
          (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
           TeAutoPark_e_AutoParkStatus_Complete) ||
          (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
           TeAutoPark_e_AutoParkStatus_Standby) ||
          (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
           TeAutoPark_e_AutoParkStatus_Fault)) {
        SWC_AP_StateMachine_DW.is_c2_SWC_AP_StateMachine =
          SWC_AP_StateMachine_IN_Not_Pressed_OFF;
        SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus = false;
        *rty_MeAP_b_AutoParkEnblSwtStuckStatus = false;
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = false;
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = true;
      } else {
        if (rtu_IbVBII_VehState_LowSpd->IeVBII_b_AutoParkEnblSwt) {
          SWC_AP_StateMachine_DW.is_c2_SWC_AP_StateMachine =
            SWC_AP_StateMachine_IN_Pressed;
          SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = true;
          SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = false;
          SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt = 0U;
          if ((SWC_AP_StateMachine_B.IeAP_e_ParKMnvrActv !=
               TeAP_e_ParKMnvrActv_Engaged_Full) &&
              rtu_IbVBII_VehState_LowSpd->IeVBII_b_AutoParkEnblSwt) {
            tmp = SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt +
              *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
            if (tmp > 65535) {
              tmp = 65535;
            }

            SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt = (uint16_T)tmp;
            *rty_MeAP_b_AutoParkEnblSwtStuckStatus =
              ((SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt >
                *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd) && true);
          } else {
            SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt = 0U;
            *rty_MeAP_b_AutoParkEnblSwtStuckStatus = false;
          }
        }
      }
      break;

     case SWC_AP_StateMachine_IN_Pressed:
      SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = true;
      SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = false;
      tmp_1 = !rtu_IbVBII_VehState_LowSpd->IeVBII_b_AutoParkEnblSwt;
      if (tmp_1 && ((!SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus) ||
                    (SWC_AP_StateMachine_B.IeAP_e_ParKMnvrActv ==
                     TeAP_e_ParKMnvrActv_Engaged_Full))) {
        SWC_AP_StateMachine_DW.is_c2_SWC_AP_StateMachine =
          SWC_AP_StateMachine_IN_Not_Pressed_ON;
        SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus = true;
        *rty_MeAP_b_AutoParkEnblSwtStuckStatus = false;
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = false;
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = true;
      } else if (tmp_1 && SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus &&
                 ((SWC_AP_StateMachine_B.IeAP_e_ParKMnvrActv ==
                   TeAP_e_ParKMnvrActv_Enabled_Seeking) ||
                  (SWC_AP_StateMachine_B.IeAP_e_ParKMnvrActv ==
                   TeAP_e_ParKMnvrActv_Engaged_Semi) ||
                  (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
                   TeAutoPark_e_AutoParkStatus_Complete))) {
        guard1 = true;
      } else if (*rty_MeAP_b_AutoParkEnblSwtStuckStatus) {
        SWC_AP_StateMachine_DW.is_c2_SWC_AP_StateMachine =
          SWC_AP_StateMachine_IN_SwitchStuck;
        *rty_MeAP_b_AutoParkEnblSwtStuckStatus = true;
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = true;
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = false;
      } else if ((SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
                  TeAutoPark_e_AutoParkStatus_Abort) ||
                 (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
                  TeAutoPark_e_AutoParkStatus_Complete) ||
                 (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
                  TeAutoPark_e_AutoParkStatus_Fault)) {
        guard1 = true;
      } else if ((SWC_AP_StateMachine_B.IeAP_e_ParKMnvrActv !=
                  TeAP_e_ParKMnvrActv_Engaged_Full) &&
                 rtu_IbVBII_VehState_LowSpd->IeVBII_b_AutoParkEnblSwt) {
        tmp = SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt +
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt = (uint16_T)tmp;
        *rty_MeAP_b_AutoParkEnblSwtStuckStatus =
          ((SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt >
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd) && true);
      } else {
        SWC_AP_StateMachine_DW.MeAP_cnt_SwtStuckTimeCnt = 0U;
        *rty_MeAP_b_AutoParkEnblSwtStuckStatus = false;
      }
      break;

     default:
      /* case IN_SwitchStuck: */
      SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = true;
      SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = false;
      tmp_1 = !rtu_IbVBII_VehState_LowSpd->IeVBII_b_AutoParkEnblSwt;
      if ((!SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus) && tmp_1) {
        /*  This is the invalid switch input & ignore the request i.e. not change states  */
        SWC_AP_StateMachine_DW.is_c2_SWC_AP_StateMachine =
          SWC_AP_StateMachine_IN_Not_Pressed_OFF;
        SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus = false;
        *rty_MeAP_b_AutoParkEnblSwtStuckStatus = false;
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = false;
        SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = true;
      } else {
        if (SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus && tmp_1) {
          /*  This is the invalid switch input & ignore the request i.e. not change states  */
          SWC_AP_StateMachine_DW.is_c2_SWC_AP_StateMachine =
            SWC_AP_StateMachine_IN_Not_Pressed_ON;
          SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus = true;
          *rty_MeAP_b_AutoParkEnblSwtStuckStatus = false;
          SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = false;
          SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = true;
        }
      }
      break;
    }

    if (guard1) {
      SWC_AP_StateMachine_DW.is_c2_SWC_AP_StateMachine =
        SWC_AP_StateMachine_IN_Not_Pressed_OFF;
      SWC_AP_StateMachine_B.MeAP_b_AutoParkEnblSwtStatus = false;
      *rty_MeAP_b_AutoParkEnblSwtStuckStatus = false;
      SWC_AP_StateMachine_B.MeAP_b_PPPABtnPressed = false;
      SWC_AP_StateMachine_B.MeAP_b_PPPABtnReleased = true;
    }
  }

  /* End of Chart: '<S34>/Chart1' */
  /* Update for UnitDelay: '<S46>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_m =
    SWC_AP_StateMachine_B.LogicalOperator9;

  /* Update for UnitDelay: '<S28>/Unit Delay1' */
  SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_i =
    SWC_AP_StateMachine_B.LogicalOperator3;

  /* Update for UnitDelay: '<S48>/Unit Delay1' */
  SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_e =
    SWC_AP_StateMachine_B.LogicalOperator9;

  /* Update for UnitDelay: '<S47>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_n =
    SWC_AP_StateMachine_B.LogicalOperator8;

  /* Update for UnitDelay: '<S47>/Unit Delay1' */
  SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_fb = SWC_AP_StateMachine_B.reset;

  /* Update for UnitDelay: '<S34>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_a =
    rtu_IbVBII_VehState_LowSpd->IeVBII_b_AutoParkEnblSwt;

  /* End of Outputs for SubSystem: '<S12>/AP_FeatureEnable' */

  /* Outputs for Atomic SubSystem: '<S12>/AP_VehicleConditions' */
  /* Logic: '<S29>/Logical Operator' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    !rtu_IbVBII_VehState_LowSpd->IeVBII_b_DriverDoorSts;

  /* Logic: '<S29>/Logical Operator2' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    !rtu_IbVBII_VehState_LowSpd->IeVBII_b_DoorRL;

  /* Logic: '<S29>/Logical Operator3' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    !rtu_IbVBII_VehState_LowSpd->IeVBII_b_DoorP;

  /* Logic: '<S29>/Logical Operator4' */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    !rtu_IbVBII_VehState_LowSpd->IeVBII_b_DoorRR;

  /* Logic: '<S29>/Logical Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (SWC_AP_StateMachine_B.RelationalOperator_g &&
     SWC_AP_StateMachine_B.RelationalOperator_o &&
     SWC_AP_StateMachine_B.LogicalOperator2_p &&
     SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* RelationalOperator: '<S29>/Relational Operator7' incorporates:
   *  Constant: '<S51>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_TrailerConnectionSts !=
     TeVBII_e_TrailerConnectionSts_Connected);

  /* RelationalOperator: '<S29>/Relational Operator1' incorporates:
   *  Constant: '<S52>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_TrlrPrsntSts !=
     TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S29>/Logical Operator5' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o &&
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Logic: '<S29>/Logical Operator6' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     (*rtu_IbFID_PPPA_MeAP_b_PPPAActvTrlr));

  /* Logic: '<S29>/Logical Operator8' */
  MeAP_b_VehCndSts = (SWC_AP_StateMachine_B.RelationalOperator_g &&
                      SWC_AP_StateMachine_B.RelationalOperator_o);

  /* End of Outputs for SubSystem: '<S12>/AP_VehicleConditions' */

  /* RelationalOperator: '<S30>/Relational Operator' incorporates:
   *  Constant: '<S30>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <= 0.4F);

  /* RelationalOperator: '<S30>/Relational Operator1' incorporates:
   *  Constant: '<S53>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_RhfWhlSpnSts ==
     TeVBII_e_WhlSpnSts_StandStill);

  /* RelationalOperator: '<S30>/Relational Operator2' incorporates:
   *  Constant: '<S54>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_LhfWhlSpnSts ==
     TeVBII_e_WhlSpnSts_StandStill);

  /* Logic: '<S30>/Logical Operator' */
  *rty_MeAP_b_StandStill = (SWC_AP_StateMachine_B.RelationalOperator_o &&
    SWC_AP_StateMachine_B.LogicalOperator2_p &&
    SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* RelationalOperator: '<S30>/Relational Operator3' incorporates:
   *  Constant: '<S55>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_BrkPdlStat == TeVBII_e_BrkPdlStat_PSD);

  /* RelationalOperator: '<S30>/Relational Operator4' incorporates:
   *  Constant: '<S56>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts !=
     TeVBII_e_ParkingIntrvntionSts_Faulted_External);

  /* RelationalOperator: '<S30>/Relational Operator5' incorporates:
   *  Constant: '<S57>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts !=
     TeVBII_e_ParkingIntrvntionSts_Faulted_Internal);

  /* Logic: '<S30>/Logical Operator3' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p &&
     SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* Logic: '<S30>/Logical Operator2' */
  SWC_AP_StateMachine_B.LogicalOperator3_a = LogicalOperator2_p_tmp;

  /* Logic: '<S30>/Logical Operator1' */
  SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeActv = ((*rty_MeAP_b_StandStill) &&
    SWC_AP_StateMachine_B.RelationalOperator_o &&
    SWC_AP_StateMachine_B.LogicalOperator2_p &&
    rtu_MbNVM_ProxyParam->KeAP_b_FullAutoPrkgSys &&
    SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* RelationalOperator: '<S31>/Relational Operator' incorporates:
   *  Constant: '<S58>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_BrkPdlStat == TeVBII_e_BrkPdlStat_PSD);

  /* RelationalOperator: '<S31>/Relational Operator5' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_nm_BrkTrqDriver >
     rtu_IbVBII_VehState_LowSpd->IeVBII_nm_BrkTrqAct);

  /* Logic: '<S31>/Logical Operator8' */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    !SWC_AP_StateMachine_B.MeAP_b_InitBrkPedlPressed_h;

  /* Logic: '<S31>/Logical Operator3' */
  MeAP_b_BrkPedlOverride = (SWC_AP_StateMachine_B.LogicalOperator2_p &&
    SWC_AP_StateMachine_B.RelationalOperator_o &&
    SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* RelationalOperator: '<S31>/Relational Operator2' incorporates:
   *  Constant: '<S31>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.IeVBII_per_PdlPosAct > KeAP_pct_PdlPosActThd);

  /* RelationalOperator: '<S31>/Relational Operator1' incorporates:
   *  Constant: '<S59>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_DriverReqAxleTrqEnabled ==
     TeVBII_e_DriverReqAxleTrqEnabled_No_Req);

  /* Logic: '<S31>/Logical Operator' */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (SWC_AP_StateMachine_B.LogicalOperator2_p &&
     SWC_AP_StateMachine_B.RelationalOperator_o);

  /* Logic: '<S31>/Logical Operator1' */
  MeAP_b_GasPedlOverride = (SWC_AP_StateMachine_B.IeVBII_b_Override ||
    SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* DataTypeConversion: '<S31>/Data Type Conversion' */
  SWC_AP_StateMachine_B.DataTypeConversion8 = (uint8_T)
    rtu_IbVBII_VehState_LowSpd->IeVBII_e_ShiftLvrPosReq;

  /* DataTypeConversion: '<S64>/Data Type Conversion2' */
  SWC_AP_StateMachine_B.DataTypeConversion2 = (uint8_T)
    rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState;

  /* MultiPortSwitch: '<S64>/Multiport Switch' incorporates:
   *  Constant: '<S64>/Constant10'
   *  Constant: '<S64>/Constant3'
   *  Constant: '<S64>/Constant4'
   *  Constant: '<S64>/Constant5'
   *  Constant: '<S64>/Constant6'
   *  Constant: '<S64>/Constant7'
   *  Constant: '<S64>/Constant8'
   *  Constant: '<S64>/Constant9'
   */
  switch (SWC_AP_StateMachine_B.DataTypeConversion2) {
   case 0:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)3U);
    break;

   case 1:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)4U);
    break;

   case 2:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)4U);
    break;

   case 3:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)4U);
    break;

   case 4:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)4U);
    break;

   case 5:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)4U);
    break;

   case 6:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)4U);
    break;

   case 7:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)4U);
    break;

   case 8:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)4U);
    break;

   case 9:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)4U);
    break;

   case 10:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)10U);
    break;

   case 11:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)11U);
    break;

   case 12:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)12U);
    break;

   case 13:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)1U);
    break;

   case 14:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)2U);
    break;

   default:
    SWC_AP_StateMachine_B.DataTypeConversion1 = ((uint8_T)15U);
    break;
  }

  /* End of MultiPortSwitch: '<S64>/Multiport Switch' */

  /* RelationalOperator: '<S31>/Relational Operator3' */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (SWC_AP_StateMachine_B.DataTypeConversion8 !=
     SWC_AP_StateMachine_B.DataTypeConversion1);

  /* Logic: '<S31>/Logical Operator2' */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (SWC_AP_StateMachine_B.LogicalOperator3_a &&
     SWC_AP_StateMachine_B.UnitDelay12);

  /* Logic: '<S65>/Logical Operator1' */
  SWC_AP_StateMachine_B.LogicalOperator4_f =
    !SWC_AP_StateMachine_B.LogicalOperator3_a;

  /* UnitDelay: '<S65>/Unit Delay2' */
  SWC_AP_StateMachine_B.UnitDelay2_n = SWC_AP_StateMachine_B.Switch4;

  /* Switch: '<S65>/Switch3' incorporates:
   *  Constant: '<S31>/Constant1'
   */
  if (SWC_AP_StateMachine_B.LogicalOperator4_f) {
    SWC_AP_StateMachine_B.MeAP_cnt_TransDebugVar_h =
      KeAP_Cnt_GearOverrideTimeThd;
  } else {
    /* RelationalOperator: '<S65>/Relational Operator' incorporates:
     *  Constant: '<S31>/Constant2'
     */
    SWC_AP_StateMachine_B.RelationalOperator = (KeAP_cnt_TimeStep <=
      SWC_AP_StateMachine_B.UnitDelay2_n);

    /* Switch: '<S65>/Switch1' incorporates:
     *  Constant: '<S65>/Constant'
     */
    if (SWC_AP_StateMachine_B.RelationalOperator) {
      /* Sum: '<S65>/Subtract' incorporates:
       *  Constant: '<S31>/Constant2'
       */
      SWC_AP_StateMachine_B.Subtract = (uint16_T)
        (SWC_AP_StateMachine_B.UnitDelay2_n - KeAP_cnt_TimeStep);
      SWC_AP_StateMachine_B.Switch1_p = SWC_AP_StateMachine_B.Subtract;
    } else {
      SWC_AP_StateMachine_B.Switch1_p = ((uint16_T)0U);
    }

    /* End of Switch: '<S65>/Switch1' */
    SWC_AP_StateMachine_B.MeAP_cnt_TransDebugVar_h =
      SWC_AP_StateMachine_B.Switch1_p;
  }

  /* End of Switch: '<S65>/Switch3' */

  /* RelationalOperator: '<S65>/Relational Operator1' incorporates:
   *  Constant: '<S31>/Constant2'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f = (KeAP_cnt_TimeStep >
    SWC_AP_StateMachine_B.MeAP_cnt_TransDebugVar_h);

  /* Logic: '<S65>/Logical Operator8' */
  MeAP_b_GearShiftOverride = (SWC_AP_StateMachine_B.LogicalOperator3_a &&
    SWC_AP_StateMachine_B.LogicalOperator4_f);

  /* RelationalOperator: '<S31>/Relational Operator4' incorporates:
   *  Constant: '<S60>/Constant'
   */
  MeAP_b_EPBOverride = (SWC_AP_StateMachine_B.IeVBII_e_VehEPBSts ==
                        TeVBII_e_VehEPBSts_Applied);

  /* Logic: '<S31>/Logical Operator4' */
  SWC_AP_StateMachine_B.LogicalOperator5_a = (MeAP_b_BrkPedlOverride ||
    MeAP_b_GearShiftOverride || MeAP_b_EPBOverride || MeAP_b_GasPedlOverride);

  /* DataTypeConversion: '<S12>/RHFWheelSpeed3' */
  SWC_AP_StateMachine_B.UnitDelay4 = SWC_AP_StateMachine_B.UnitDelay2;

  /* RelationalOperator: '<S31>/Relational Operator6' incorporates:
   *  Constant: '<S61>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator12 = (SWC_AP_StateMachine_B.UnitDelay4
    == TeAP_e_AlgoState_Park_In);

  /* RelationalOperator: '<S31>/Relational Operator7' incorporates:
   *  Constant: '<S62>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_i = (SWC_AP_StateMachine_B.UnitDelay4 ==
    TeAP_e_AlgoState_Park_Out);

  /* RelationalOperator: '<S31>/Relational Operator8' incorporates:
   *  Constant: '<S63>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
     TeAutoPark_e_AutoParkStatus_Abort);

  /* Logic: '<S31>/Logical Operator6' */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (SWC_AP_StateMachine_B.RelationalOperator12 ||
     SWC_AP_StateMachine_B.LogicalOperator3_i ||
     SWC_AP_StateMachine_B.RelationalOperator_g);

  /* Logic: '<S31>/Logical Operator7' */
  SWC_AP_StateMachine_B.RelationalOperator_g = LogicalOperator2_p_tmp;

  /* Logic: '<S31>/Logical Operator5' */
  MeAP_b_DriverOverride = (SWC_AP_StateMachine_B.LogicalOperator5_a &&
    SWC_AP_StateMachine_B.RelationalOperator12 &&
    SWC_AP_StateMachine_B.RelationalOperator_g);

  /* Switch: '<S65>/Switch4' incorporates:
   *  Constant: '<S65>/Constant2'
   */
  if (SWC_AP_StateMachine_B.LogicalOperator4_f) {
    tmp_0 = floor(0.0);
    if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
      tmp_0 = 0.0;
    } else {
      tmp_0 = fmod(tmp_0, 65536.0);
    }

    SWC_AP_StateMachine_B.Switch4 = (uint16_T)(tmp_0 < 0.0 ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp_0 : (int32_T)(uint16_T)tmp_0);
  } else {
    SWC_AP_StateMachine_B.Switch4 =
      SWC_AP_StateMachine_B.MeAP_cnt_TransDebugVar_h;
  }

  /* End of Switch: '<S65>/Switch4' */
  /* RelationalOperator: '<S33>/Relational Operator' incorporates:
   *  Constant: '<S66>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_g =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_BrkPdlStat ==
     TeVBII_e_BrkPdlStat_UPSTOP);

  /* Logic: '<S33>/Logical Operator1' */
  SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff =
    !rtu_IbVBII_VehState_LowSpd->IeVBII_b_HandsOnRecog;

  /* Logic: '<S33>/Logical Operator' */
  SWC_AP_StateMachine_B.MeAP_b_RmvHandsFeetConSucs =
    (SWC_AP_StateMachine_B.MeAP_b_WheelHandsOff &&
     SWC_AP_StateMachine_B.RelationalOperator_g);

  /* Logic: '<S32>/Logical Operator' */
  SWC_AP_StateMachine_B.MeAP_b_EPSHandshakeActv =
    (rtu_MbNVM_ProxyParam->KeAP_b_FullAutoPrkgSys &&
     rtu_MbNVM_ProxyParam->KeAP_b_PullOutCtrlPres);

  /* UnitDelay: '<S15>/Unit Delay3' */
  SWC_AP_StateMachine_B.UnitDelay3_o =
    SWC_AP_StateMachine_DW.UnitDelay3_DSTATE_o;

  /* UnitDelay: '<S15>/Unit Delay' */
  SWC_AP_StateMachine_B.UnitDelay_k = SWC_AP_StateMachine_DW.UnitDelay_DSTATE_e;

  /* RelationalOperator: '<S15>/Relational Operator29' incorporates:
   *  Constant: '<S98>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
     TeAutoPark_e_AutoParkStatus_Active);

  /* RelationalOperator: '<S15>/Relational Operator44' incorporates:
   *  Constant: '<S100>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
     TeAutoPark_e_AutoParkStatus_Abort);

  /* Logic: '<S15>/Logical Operator37' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/Constant5'
   */
  if (SWC_AP_StateMachine_B.RelationalOperator_o) {
    /* RelationalOperator: '<S15>/Relational Operator30' incorporates:
     *  Constant: '<S85>/Constant'
     */
    SWC_AP_StateMachine_B.RelationalOperator30 =
      (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
       TeAutoPark_e_AutoParkStatus_Active);

    /* RelationalOperator: '<S15>/Relational Operator46' incorporates:
     *  Constant: '<S101>/Constant'
     */
    SWC_AP_StateMachine_B.RelationalOperator43 =
      (SWC_AP_StateMachine_B.IeAP_e_ParKMnvrActv !=
       TeAP_e_ParKMnvrActv_Engaged_Full);

    /* RelationalOperator: '<S15>/Relational Operator45' */
    SWC_AP_StateMachine_B.LogicalOperator38 =
      (SWC_AP_StateMachine_B.MeAP_b_APASwtStatus !=
       SWC_AP_StateMachine_B.UnitDelay3_o);

    /* Logic: '<S15>/Logical Operator38' */
    SWC_AP_StateMachine_B.LogicalOperator38 =
      (SWC_AP_StateMachine_B.LogicalOperator38 &&
       SWC_AP_StateMachine_B.RelationalOperator43);

    /* RelationalOperator: '<S15>/Relational Operator43' */
    SWC_AP_StateMachine_B.RelationalOperator43 =
      (SWC_AP_StateMachine_B.MeAP_b_RPASwtStatus !=
       SWC_AP_StateMachine_B.UnitDelay2_i);

    /* RelationalOperator: '<S15>/Relational Operator42' */
    SWC_AP_StateMachine_B.LogicalOperator13 =
      (SWC_AP_StateMachine_B.MeAP_b_FPASwtStatus !=
       SWC_AP_StateMachine_B.UnitDelay1);

    /* Logic: '<S15>/Logical Operator35' */
    SWC_AP_StateMachine_B.LogicalOperator13 =
      (SWC_AP_StateMachine_B.LogicalOperator13 ||
       SWC_AP_StateMachine_B.RelationalOperator43 ||
       SWC_AP_StateMachine_B.LogicalOperator38);

    /* Logic: '<S15>/Logical Operator13' */
    SWC_AP_StateMachine_B.LogicalOperator13 =
      (SWC_AP_StateMachine_B.LogicalOperator13 &&
       SWC_AP_StateMachine_B.RelationalOperator30);

    /* Logic: '<S15>/Logical Operator36' */
    SWC_AP_StateMachine_B.LogicalOperator36 =
      (SWC_AP_StateMachine_B.LogicalOperator13 ||
       SWC_AP_StateMachine_B.UnitDelay_k);
    MeAP_b_BtnPsd = SWC_AP_StateMachine_B.LogicalOperator36;
  } else {
    MeAP_b_BtnPsd = false;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* Switch: '<S15>/Switch' */
  if (rtu_IbVBII_VehState_LowSpd->IeVBII_b_ActvParkMode) {
    MeAP_b_DoorOpen = rtu_IbVBII_VehState_LowSpd->IeVBII_b_DriverDoorSts;
  } else {
    /* Logic: '<S15>/Logical Operator' */
    SWC_AP_StateMachine_B.LogicalOperator =
      (rtu_IbVBII_VehState_LowSpd->IeVBII_b_DriverDoorSts ||
       rtu_IbVBII_VehState_LowSpd->IeVBII_b_DoorP ||
       rtu_IbVBII_VehState_LowSpd->IeVBII_b_DoorRL ||
       rtu_IbVBII_VehState_LowSpd->IeVBII_b_DoorRR);
    MeAP_b_DoorOpen = SWC_AP_StateMachine_B.LogicalOperator;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Logic: '<S15>/Logical Operator1' incorporates:
   *  Constant: '<S15>/Constant'
   */
  MeAP_b_LifeGateOpen = (rtu_IbVBII_VehState_LowSpd->IeVBII_b_TrnkStatus && true);

  /* RelationalOperator: '<S15>/Relational Operator5' incorporates:
   *  Constant: '<S88>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ExtBrkReqDisabled ==
     TeVBII_e_ExtBrkReqDisabled_ExternalSystemsTempOff);

  /* RelationalOperator: '<S15>/Relational Operator47' incorporates:
   *  Constant: '<S102>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ExtBrkReqDisabled ==
     TeVBII_e_ExtBrkReqDisabled_ExternalSystemsContinousOff);

  /* Logic: '<S15>/Logical Operator39' */
  MeAP_b_ESCActive = (SWC_AP_StateMachine_B.RelationalOperator_o ||
                      SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* RelationalOperator: '<S15>/Relational Operator' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > KeAP_kph_PSDOffThd);

  /* RelationalOperator: '<S15>/Relational Operator1' incorporates:
   *  Constant: '<S67>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = (SWC_AP_StateMachine_B.UnitDelay2 ==
    TeAP_e_AlgoState_Scanning);

  /* Logic: '<S15>/Logical Operator2' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o &&
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Logic: '<S15>/Logical Operator33' */
  MeAP_b_SeekSpdExceed = (SWC_AP_StateMachine_B.RelationalOperator_o ||
    SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout);

  /* RelationalOperator: '<S15>/Relational Operator2' incorporates:
   *  Constant: '<S15>/Constant2'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > KeAP_kph_ParkMnvThd);

  /* RelationalOperator: '<S15>/Relational Operator3' incorporates:
   *  Constant: '<S68>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = (SWC_AP_StateMachine_B.UnitDelay2 ==
    TeAP_e_AlgoState_Park_In);

  /* RelationalOperator: '<S15>/Relational Operator4' incorporates:
   *  Constant: '<S79>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a = (SWC_AP_StateMachine_B.UnitDelay2 ==
    TeAP_e_AlgoState_Park_Out);

  /* Logic: '<S15>/Logical Operator4' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* Logic: '<S15>/Logical Operator3' */
  MeAP_b_MnvSpdExceed = (SWC_AP_StateMachine_B.RelationalOperator_o &&
    rtu_IbVBII_VehState_LowSpd->IeVBII_b_ActvParkMode &&
    SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* RelationalOperator: '<S15>/Relational Operator9' incorporates:
   *  Constant: '<S105>/Constant'
   */
  MeAP_b_Lo4DriveTrain = (rtu_IbVBII_VehState_LowSpd->IeVBII_e_TCaseRangeSts ==
    TeVBII_e_TCaseRangeSts_LOW);

  /* RelationalOperator: '<S15>/Relational Operator10' incorporates:
   *  Constant: '<S106>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_TrailerConnectionSts ==
     TeVBII_e_TrailerConnectionSts_Connected);

  /* RelationalOperator: '<S15>/Relational Operator11' incorporates:
   *  Constant: '<S107>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_TrlrPrsntSts ==
     TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S15>/Logical Operator6' */
  MeAP_b_TrlrConn = (SWC_AP_StateMachine_B.RelationalOperator_o ||
                     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S111>/Constant'
   *  Switch: '<S109>/Switch1'
   */
  if (*rtu_IbFID_PA_MeAP_b_FrntSenorFail) {
    *rty_IeAP_e_FrntSnsrStatus = TeAP_e_FrntSnsrStatus_NotActive_Failure;
  } else {
    if (*rtu_IbFID_PA_MeAP_b_FrntSenorBlock) {
      /* Switch: '<S109>/Switch1' incorporates:
       *  Constant: '<S112>/Constant'
       */
      SWC_AP_StateMachine_B.Switch1_co = TeAP_e_FrntSnsrStatus_NotActive_Blocked;
    } else {
      /* Switch: '<S109>/Switch1' */
      SWC_AP_StateMachine_B.Switch1_co = SWC_AP_StateMachine_ConstB.Switch2_o;
    }

    *rty_IeAP_e_FrntSnsrStatus = SWC_AP_StateMachine_B.Switch1_co;
  }

  /* End of Switch: '<S109>/Switch' */

  /* RelationalOperator: '<S15>/Relational Operator12' incorporates:
   *  Constant: '<S69>/Constant'
   */
  MeAP_b_FrntSnsrBlk = (*rty_IeAP_e_FrntSnsrStatus ==
                        TeAP_e_FrntSnsrStatus_NotActive_Blocked);

  /* Switch: '<S110>/Switch' incorporates:
   *  Constant: '<S115>/Constant'
   *  Switch: '<S110>/Switch1'
   */
  if (*rtu_IbFID_PA_MeAP_b_RearSenorFail) {
    *rty_IeAP_e_RearSnsrStatus = TeAP_e_RearSnsrStatus_NotActive_Failure;
  } else {
    if (*rtu_IbFID_PA_MeAP_b_RearSenorBlock) {
      /* Switch: '<S110>/Switch1' incorporates:
       *  Constant: '<S116>/Constant'
       */
      SWC_AP_StateMachine_B.Switch1_n = TeAP_e_RearSnsrStatus_NotActive_Blocked;
    } else {
      /* Switch: '<S110>/Switch1' */
      SWC_AP_StateMachine_B.Switch1_n = SWC_AP_StateMachine_ConstB.Switch2;
    }

    *rty_IeAP_e_RearSnsrStatus = SWC_AP_StateMachine_B.Switch1_n;
  }

  /* End of Switch: '<S110>/Switch' */

  /* RelationalOperator: '<S15>/Relational Operator13' incorporates:
   *  Constant: '<S70>/Constant'
   */
  MeAP_b_RearSnsrBlk = (*rty_IeAP_e_RearSnsrStatus ==
                        TeAP_e_RearSnsrStatus_NotActive_Blocked);

  /* Logic: '<S15>/Logical Operator8' */
  SWC_AP_StateMachine_B.RelationalOperator_o = LogicalOperator2_p_tmp;

  /* RelationalOperator: '<S15>/Relational Operator6' incorporates:
   *  Constant: '<S99>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ACCSysSts ==
     TeVBII_e_ACCSysSts_ACC_Engaged);

  /* RelationalOperator: '<S15>/Relational Operator7' incorporates:
   *  Constant: '<S103>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ACCSysSts ==
     TeVBII_e_ACCSysSts_NCC_Engaged);

  /* RelationalOperator: '<S15>/Relational Operator8' incorporates:
   *  Constant: '<S104>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ACCSysSts ==
     TeVBII_e_ACCSysSts_ACC_Engaged_BrakeOnly);

  /* Logic: '<S15>/Logical Operator5' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a ||
     SWC_AP_StateMachine_B.LogicalOperator4_f);

  /* Logic: '<S15>/Logical Operator7' */
  MeAP_b_ACCEngg = (SWC_AP_StateMachine_B.RelationalOperator_o &&
                    SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Logic: '<S14>/Logical Operator' */
  SWC_AP_StateMachine_B.RelationalOperator_o = (MeAP_b_DoorOpen ||
    MeAP_b_LifeGateOpen || MeAP_b_ESCActive || MeAP_b_SeekSpdExceed ||
    MeAP_b_MnvSpdExceed || MeAP_b_Lo4DriveTrain || MeAP_b_TrlrConn ||
    MeAP_b_FrntSnsrBlk || MeAP_b_RearSnsrBlk || MeAP_b_ACCEngg || MeAP_b_BtnPsd);

  /* Logic: '<S14>/Logical Operator4' incorporates:
   *  Constant: '<S14>/Constant'
   *  Logic: '<S14>/Logical Operator6'
   */
  LogicalOperator2_p_tmp = !KeAP_b_DevlopmentTest;
  SWC_AP_StateMachine_B.LogicalOperator2_p = LogicalOperator2_p_tmp;

  /* Logic: '<S14>/Logical Operator3' */
  MeAP_b_AbortCon1 = (SWC_AP_StateMachine_B.RelationalOperator_o &&
                      SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* RelationalOperator: '<S15>/Relational Operator14' incorporates:
   *  Constant: '<S71>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (SWC_AP_StateMachine_B.UnitDelay2
    == TeAP_e_AlgoState_Park_In);

  /* RelationalOperator: '<S15>/Relational Operator15' incorporates:
   *  Constant: '<S72>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = (SWC_AP_StateMachine_B.UnitDelay2 ==
    TeAP_e_AlgoState_Park_Out);

  /* RelationalOperator: '<S15>/Relational Operator41' incorporates:
   *  Constant: '<S97>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (SWC_AP_StateMachine_B.IeAP_e_AutoParkStatus ==
     TeAutoPark_e_AutoParkStatus_Abort);

  /* Logic: '<S15>/Logical Operator10' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* Logic: '<S15>/Logical Operator9' */
  MeAP_b_HandsOn = (rtu_IbVBII_VehState_LowSpd->IeVBII_b_HandsOnRecog &&
                    SWC_AP_StateMachine_B.RelationalOperator_o);

  /* RelationalOperator: '<S15>/Relational Operator16' incorporates:
   *  Constant: '<S73>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (SWC_AP_StateMachine_B.UnitDelay2
    == TeAP_e_AlgoState_Park_In);

  /* RelationalOperator: '<S15>/Relational Operator17' incorporates:
   *  Constant: '<S74>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = (SWC_AP_StateMachine_B.UnitDelay2 ==
    TeAP_e_AlgoState_Park_Out);

  /* Logic: '<S15>/Logical Operator11' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Logic: '<S15>/Logical Operator12' */
  MeAP_b_ManualParkReq = ((*rtu_MeAP_b_ManualParkReq) &&
    SWC_AP_StateMachine_B.RelationalOperator_o);

  /* Logic: '<S14>/Logical Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_o = (MeAP_b_HandsOn ||
    MeAP_b_DriverOverride || MeAP_b_ManualParkReq);

  /* Logic: '<S14>/Logical Operator6' */
  SWC_AP_StateMachine_B.LogicalOperator2_p = LogicalOperator2_p_tmp;

  /* Logic: '<S14>/Logical Operator5' */
  MeAP_b_AbortCon2 = (SWC_AP_StateMachine_B.RelationalOperator_o &&
                      SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* RelationalOperator: '<S13>/Relational Operator1' incorporates:
   *  Constant: '<S13>/ENS_RQ_ST'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_EssEngState ==
     TeVBII_e_EssEngState_ENS_RQ_ST);

  /* RelationalOperator: '<S13>/Relational Operator2' incorporates:
   *  Constant: '<S13>/ENS_Starting'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_EssEngState ==
     TeVBII_e_EssEngState_ENS_Starting);

  /* Logic: '<S13>/Logical Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* RelationalOperator: '<S13>/Relational Operator' incorporates:
   *  Constant: '<S13>/IGN_RUN'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_CmdIgnSts == TeVBII_e_CmdIgnSts_IGN_LK);

  /* Logic: '<S13>/Logical Operator' */
  *rty_MeAP_b_DisableDiag = (SWC_AP_StateMachine_B.LogicalOperator2_p &&
    SWC_AP_StateMachine_B.RelationalOperator_o &&
    rtu_MbNVM_ProxyParam->KeAP_b_StopAndStrt);

  /* RelationalOperator: '<S15>/Relational Operator18' incorporates:
   *  Constant: '<S75>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (SWC_AP_StateMachine_B.UnitDelay2
    == TeAP_e_AlgoState_Handshake);

  /* RelationalOperator: '<S15>/Relational Operator19' incorporates:
   *  Constant: '<S76>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts ==
     TeVBII_e_ParkingIntrvntionSts_Faulted_External);

  /* RelationalOperator: '<S15>/Relational Operator20' incorporates:
   *  Constant: '<S77>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts ==
     TeVBII_e_ParkingIntrvntionSts_Faulted_Internal);

  /* Logic: '<S15>/Logical Operator14' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* Logic: '<S15>/Logical Operator15' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p &&
     SWC_AP_StateMachine_B.RelationalOperator_o);

  /* RelationalOperator: '<S15>/Relational Operator22' incorporates:
   *  Constant: '<S80>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts !=
     TeVBII_e_ParkingIntrvntionSts_Active);

  /* RelationalOperator: '<S15>/Relational Operator21' incorporates:
   *  Constant: '<S78>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (SWC_AP_StateMachine_B.IeAP_e_ParKMnvrActv ==
     TeAP_e_ParKMnvrActv_Engaged_Full);

  /* Logic: '<S15>/Logical Operator17' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o &&
     SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* Logic: '<S15>/Logical Operator18' */
  MeAP_b_BSMHandshakeFailed = (SWC_AP_StateMachine_B.LogicalOperator2_p ||
    SWC_AP_StateMachine_B.RelationalOperator_o ||
    SWC_AP_StateMachine_B.UnitDelay4_o);

  /* RelationalOperator: '<S15>/Relational Operator24' incorporates:
   *  Constant: '<S82>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts ==
     TeVBII_e_SPMLatCtrlRespSts_PermNotAvail);

  /* RelationalOperator: '<S15>/Relational Operator25' incorporates:
   *  Constant: '<S83>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts ==
     TeVBII_e_SPMLatCtrlRespSts_TempNotAvail);

  /* Logic: '<S15>/Logical Operator16' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* RelationalOperator: '<S15>/Relational Operator23' incorporates:
   *  Constant: '<S81>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = (SWC_AP_StateMachine_B.UnitDelay2 ==
    TeAP_e_AlgoState_Handshake);

  /* Logic: '<S15>/Logical Operator19' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o &&
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* RelationalOperator: '<S15>/Relational Operator27' incorporates:
   *  Constant: '<S84>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts !=
     TeVBII_e_SPMLatCtrlRespSts_HasOpen);

  /* RelationalOperator: '<S15>/Relational Operator38' incorporates:
   *  Constant: '<S94>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a = (SWC_AP_StateMachine_B.UnitDelay2 ==
    TeAP_e_AlgoState_Park_In);

  /* RelationalOperator: '<S15>/Relational Operator39' incorporates:
   *  Constant: '<S95>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f = (SWC_AP_StateMachine_B.UnitDelay2 ==
    TeAP_e_AlgoState_Park_Out);

  /* Logic: '<S15>/Logical Operator32' */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (SWC_AP_StateMachine_B.LogicalOperator3_a ||
     SWC_AP_StateMachine_B.LogicalOperator4_f);

  /* Logic: '<S15>/Logical Operator20' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p &&
     SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* Logic: '<S15>/Logical Operator21' */
  MeAP_b_EPSHandshakeFailed = (SWC_AP_StateMachine_B.RelationalOperator_o ||
    SWC_AP_StateMachine_B.LogicalOperator2_p ||
    SWC_AP_StateMachine_B.UnitDelay5_l);

  /* Logic: '<S15>/Logical Operator25' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    !rtu_IbVBII_VehState_LowSpd->IeVBII_b_GearShiftReqAccept;

  /* Logic: '<S15>/Logical Operator24' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    !rtu_IbVBII_VehState_LowSpd->IeVBII_b_ShifterAutoconnectSts;

  /* Logic: '<S15>/Logical Operator23' */
  MeAP_b_TCMFailed = (SWC_AP_StateMachine_B.UnitDelay6_j ||
                      SWC_AP_StateMachine_B.RelationalOperator_o ||
                      SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* RelationalOperator: '<S15>/Relational Operator31' incorporates:
   *  Constant: '<S86>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_TGWCamDispSts !=
     TeVBII_e_TGWCamDispSts_DISP_SURROUND_VIEW_CAMERA);

  /* RelationalOperator: '<S15>/Relational Operator32' incorporates:
   *  Constant: '<S87>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = (SWC_AP_StateMachine_B.UnitDelay9 ==
    TeAP_e_SPMActvStat_Active_ParallelParking);

  /* RelationalOperator: '<S15>/Relational Operator33' incorporates:
   *  Constant: '<S89>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a = (SWC_AP_StateMachine_B.UnitDelay9 ==
    TeAP_e_SPMActvStat_Active_PerpendicularParking);

  /* RelationalOperator: '<S15>/Relational Operator34' incorporates:
   *  Constant: '<S90>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f = (SWC_AP_StateMachine_B.UnitDelay9 ==
    TeAP_e_SPMActvStat_Active_OutParking);

  /* Logic: '<S15>/Logical Operator28' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a ||
     SWC_AP_StateMachine_B.LogicalOperator4_f);

  /* Logic: '<S15>/Logical Operator27' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o &&
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Logic: '<S15>/Logical Operator26' */
  MeAP_b_ETMHandshakeFailed = (SWC_AP_StateMachine_B.UnitDelay8 ||
    SWC_AP_StateMachine_B.RelationalOperator_o);

  /* Logic: '<S15>/Logical Operator29' incorporates:
   *  Constant: '<S15>/Constant3'
   */
  MeAP_b_ObjInPathTimeout = (SWC_AP_StateMachine_B.UnitDelay10 && true);

  /* Logic: '<S15>/Logical Operator30' incorporates:
   *  Constant: '<S15>/Constant4'
   */
  MeAP_b_PausedPressBtnTimeout = (SWC_AP_StateMachine_B.UnitDelay11 && true);

  /* RelationalOperator: '<S15>/Relational Operator35' incorporates:
   *  Constant: '<S92>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts ==
     TeVBII_e_VehEPBSts_Fault_EPB_Released);

  /* RelationalOperator: '<S15>/Relational Operator36' incorporates:
   *  Constant: '<S91>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts ==
     TeVBII_e_VehEPBSts_Fault_EPB_Applied);

  /* RelationalOperator: '<S15>/Relational Operator37' incorporates:
   *  Constant: '<S93>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts ==
     TeVBII_e_VehEPBSts_Fault_Present);

  /* Logic: '<S15>/Logical Operator31' */
  MeAP_b_EPBStsFaulted = (SWC_AP_StateMachine_B.RelationalOperator_o ||
    SWC_AP_StateMachine_B.LogicalOperator2_p ||
    SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* RelationalOperator: '<S15>/Relational Operator40' incorporates:
   *  Constant: '<S96>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (SWC_AP_StateMachine_B.UnitDelay2
    == TeAP_e_AlgoState_Scanning);

  /* Logic: '<S15>/Logical Operator34' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout &&
     SWC_AP_StateMachine_B.RelationalOperator_o);

  /* Logic: '<S14>/Logical Operator2' */
  SWC_AP_StateMachine_B.RelationalOperator_o = (MeAP_b_BSMHandshakeFailed ||
    MeAP_b_EPSHandshakeFailed || MeAP_b_TCMFailed || MeAP_b_ETMHandshakeFailed ||
    MeAP_b_ObjInPathTimeout || MeAP_b_PausedPressBtnTimeout ||
    MeAP_b_EPBStsFaulted || SWC_AP_StateMachine_B.RelationalOperator_o);

  /* Logic: '<S14>/Logical Operator8' incorporates:
   *  Constant: '<S14>/Constant2'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = !KeAP_b_DevlopmentTest;

  /* Logic: '<S14>/Logical Operator7' */
  MeAP_b_AbortCon3 = (SWC_AP_StateMachine_B.RelationalOperator_o &&
                      SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Update for UnitDelay: '<S15>/Unit Delay1' */
  SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_fv =
    SWC_AP_StateMachine_B.MeAP_b_FPASwtStatus;

  /* Update for UnitDelay: '<S15>/Unit Delay2' */
  SWC_AP_StateMachine_DW.UnitDelay2_DSTATE_b =
    SWC_AP_StateMachine_B.MeAP_b_RPASwtStatus;

  /* Update for UnitDelay: '<S15>/Unit Delay3' */
  SWC_AP_StateMachine_DW.UnitDelay3_DSTATE_o =
    SWC_AP_StateMachine_B.MeAP_b_APASwtStatus;

  /* Update for UnitDelay: '<S15>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_e = MeAP_b_BtnPsd;

  /* End of Outputs for SubSystem: '<S3>/AP_PreRequisits' */

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[0].
     m_isSlotValid_b != 0);

  /* Logic: '<S8>/Logical Operator3' */
  SWC_AP_StateMachine_B.LogicalOperator3_i =
    (SWC_AP_StateMachine_B.RelationalOperator12 &&
     (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.m_Parkable[0] != 0));

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[1].
     m_isSlotValid_b != 0);

  /* Logic: '<S8>/Logical Operator4' */
  SWC_AP_StateMachine_B.LogicalOperator5_a =
    (SWC_AP_StateMachine_B.RelationalOperator12 &&
     (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.m_Parkable[1] != 0));

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[2].
     m_isSlotValid_b != 0);

  /* Logic: '<S8>/Logical Operator5' */
  SWC_AP_StateMachine_B.LogicalOperator4_f =
    (SWC_AP_StateMachine_B.RelationalOperator12 &&
     (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.m_Parkable[2] != 0));

  /* DataTypeConversion: '<S8>/Data Type Conversion3' */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[3].
     m_isSlotValid_b != 0);

  /* Logic: '<S8>/Logical Operator6' */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (SWC_AP_StateMachine_B.RelationalOperator12 &&
     (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.m_Parkable[3] != 0));

  /* DataTypeConversion: '<S8>/Data Type Conversion4' */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[4].
     m_isSlotValid_b != 0);

  /* Logic: '<S8>/Logical Operator7' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.RelationalOperator12 &&
     (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.m_Parkable[4] != 0));

  /* DataTypeConversion: '<S8>/Data Type Conversion5' */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[5].
     m_isSlotValid_b != 0);

  /* Logic: '<S8>/Logical Operator8' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator12 &&
     (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.m_Parkable[5] != 0));

  /* Logic: '<S8>/Logical Operator' */
  SWC_AP_StateMachine_B.MeAP_b_ValidSlotAvl =
    (SWC_AP_StateMachine_B.LogicalOperator3_i ||
     SWC_AP_StateMachine_B.LogicalOperator5_a ||
     SWC_AP_StateMachine_B.LogicalOperator4_f ||
     SWC_AP_StateMachine_B.LogicalOperator3_a ||
     SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.RelationalOperator_o);

  /* RelationalOperator: '<S8>/Relational Operator2' incorporates:
   *  Constant: '<S125>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[0].m_SlotSide ==
     SlotSide_E_SLOT_LEFT);

  /* RelationalOperator: '<S8>/Relational Operator3' incorporates:
   *  Constant: '<S126>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[1].m_SlotSide ==
     SlotSide_E_SLOT_LEFT);

  /* RelationalOperator: '<S8>/Relational Operator4' incorporates:
   *  Constant: '<S127>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[2].m_SlotSide ==
     SlotSide_E_SLOT_LEFT);

  /* RelationalOperator: '<S8>/Relational Operator5' incorporates:
   *  Constant: '<S128>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[3].m_SlotSide ==
     SlotSide_E_SLOT_LEFT);

  /* RelationalOperator: '<S8>/Relational Operator6' incorporates:
   *  Constant: '<S129>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator5_a =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[4].m_SlotSide ==
     SlotSide_E_SLOT_LEFT);

  /* RelationalOperator: '<S8>/Relational Operator7' incorporates:
   *  Constant: '<S130>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[5].m_SlotSide ==
     SlotSide_E_SLOT_LEFT);

  /* Logic: '<S8>/Logical Operator1' */
  SWC_AP_StateMachine_B.MeAP_e_b_PSExistL =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a ||
     SWC_AP_StateMachine_B.LogicalOperator4_f ||
     SWC_AP_StateMachine_B.LogicalOperator5_a ||
     SWC_AP_StateMachine_B.RelationalOperator12);

  /* RelationalOperator: '<S8>/Relational Operator8' incorporates:
   *  Constant: '<S131>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[0].m_SlotSide ==
     SlotSide_E_SLOT_RIGHT);

  /* RelationalOperator: '<S8>/Relational Operator9' incorporates:
   *  Constant: '<S120>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[1].m_SlotSide ==
     SlotSide_E_SLOT_RIGHT);

  /* RelationalOperator: '<S8>/Relational Operator10' incorporates:
   *  Constant: '<S124>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[2].m_SlotSide ==
     SlotSide_E_SLOT_RIGHT);

  /* RelationalOperator: '<S8>/Relational Operator11' incorporates:
   *  Constant: '<S121>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[3].m_SlotSide ==
     SlotSide_E_SLOT_RIGHT);

  /* RelationalOperator: '<S8>/Relational Operator12' incorporates:
   *  Constant: '<S122>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator5_a =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[4].m_SlotSide ==
     SlotSide_E_SLOT_RIGHT);

  /* RelationalOperator: '<S8>/Relational Operator13' incorporates:
   *  Constant: '<S123>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (rtu_LwSpd_FPA_Output->m_FPAInfoToHMI.stFPAParkingSlotData[5].m_SlotSide ==
     SlotSide_E_SLOT_RIGHT);

  /* Logic: '<S8>/Logical Operator2' */
  SWC_AP_StateMachine_B.MeAP_e_b_PSExistR =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a ||
     SWC_AP_StateMachine_B.LogicalOperator4_f ||
     SWC_AP_StateMachine_B.LogicalOperator5_a ||
     SWC_AP_StateMachine_B.RelationalOperator12);

  /* Outputs for Atomic SubSystem: '<S3>/AP_Statemachine' */
  /* DataTypeConversion: '<S5>/Data Type Conversion5' */
  SWC_AP_StateMachine_B.DataTypeConversion5 =
    (rtu_LwSpd_FPA_Output->AutoParkInitializedStatus_b != 0);

  /* UnitDelay: '<S5>/Unit Delay' */
  SWC_AP_StateMachine_B.UnitDelay = SWC_AP_StateMachine_DW.UnitDelay_DSTATE;

  /* Chart: '<S5>/AUTOPARK_StateMachine' */
  if (SWC_AP_StateMachine_DW.temporalCounter_i1 < 255U) {
    SWC_AP_StateMachine_DW.temporalCounter_i1++;
  }

  if (SWC_AP_StateMachine_DW.is_active_c1_SWC_AP_StateMachine == 0U) {
    SWC_AP_StateMachine_DW.is_active_c1_SWC_AP_StateMachine = 1U;
    SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine =
      SWC_AP_StateMachine_IN_OFF;
    SWC_AP_StateMachine_enter_atomic_OFF(rty_IeAP_e_InterfaceBSM,
      rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
      rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
      rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
      rty_IeAP_e_GearShiftReq);
  } else {
    switch (SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine) {
     case SWC_AP_StateMachine_IN_FAULT:
      SWC_AP_StateMachine_FAULT(rtu_IbVBII_VehState_LowSpd,
        rtu_IbFID_PPPA_MeAP_b_PPPADisable,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur,
        rty_IeAP_e_InterfaceBSM, rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp,
        rty_IeAP_e_SPMLedSts, rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts,
        rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
        rty_IeAP_b_StandstillReq, rty_IeAP_e_GearShiftReq,
        rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
        rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
        rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
        rty_MeAP_e_PAMChimeRepnRateSVM);
      break;

     case SWC_AP_StateMachine_IN_INIT:
      MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Initialize;
      *rty_IeAP_b_SPMFailSts = false;
      *rty_IeAP_b_SPMFaultSts = false;
      *rty_IeAP_b_StandstillReq = false;
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_e_CmdIgnSts !=
           TeVBII_e_CmdIgnSts_RUN) && (!*rtu_MbDiag_TestModeForceOn)) {
        SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine =
          SWC_AP_StateMachine_IN_OFF;
        SWC_AP_StateMachine_enter_atomic_OFF(rty_IeAP_e_InterfaceBSM,
          rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
          rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
          rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
          rty_IeAP_e_GearShiftReq);
      } else if (SWC_AP_StateMachine_B.DataTypeConversion5 &&
                 (rtu_IbVBII_VehState_LowSpd->IeVBII_e_EngineSts ==
                  TeVBII_e_EngineSts_Engine_On) &&
                 SWC_AP_StateMachine_DW.MeAP_b_WaitEngineTimeout &&
                 (rtu_IbVBII_VehState_LowSpd->IeVBII_M_StrWhlTrq != (real32_T)
                  7.9921875)) {
        SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine =
          SWC_AP_StateMachine_IN_ON;
        SWC_AP_StateMachine_DW.is_ON = SWC_AP_StateMachine_IN_STANDBY;
        SWC_AP_StateMachine_enter_atomic_STANDBY(rty_IeAP_e_InterfaceBSM,
          rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
          rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
          rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
          rty_IeAP_e_GearShiftReq, rty_MeAP_e_PAMVolSigSVM,
          rty_MeAP_b_ChimeActvReqLHFSVM, rty_MeAP_b_ChimeActvReqLHRSVM,
          rty_MeAP_b_ChimeActvReqRHFSVM, rty_MeAP_b_ChimeActvReqRHRSVM,
          rty_MeAP_e_PAMChimeTypSVM, rty_MeAP_e_PAMChimeRepnRateSVM);
        SWC_AP_StateMachine_DW.is_STANDBY = SWC_AP_StateMachine_IN_Idle;
        SWC_AP_StateMachine_DW.temporalCounter_i1 = 0U;
        MeAutoPark_e_AlgoState = TeAP_e_AlgoState_Idle;
        MeAP_cnt_StateDebugVar = 97U;
      } else if (rtu_IbVBII_VehState_LowSpd->IeVBII_e_EngineSts ==
                 TeVBII_e_EngineSts_Engine_On) {
        if (!SWC_AP_StateMachine_DW.MeAP_b_WaitEngineTimeout) {
          tmp = SWC_AP_StateMachine_DW.MeAP_cnt_WaitEngineCnt +
            *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_AP_StateMachine_DW.MeAP_cnt_WaitEngineCnt = (uint16_T)tmp;
          if (SWC_AP_StateMachine_DW.MeAP_cnt_WaitEngineCnt >
              KeAP_s_WaitEngineOnThd) {
            SWC_AP_StateMachine_DW.MeAP_b_WaitEngineTimeout = true;
            MeAP_cnt_TransDebugVar = 5U;
          } else {
            SWC_AP_StateMachine_DW.MeAP_b_WaitEngineTimeout = false;
            MeAP_cnt_TransDebugVar = 4U;
          }
        } else {
          SWC_AP_StateMachine_DW.MeAP_b_WaitEngineTimeout = true;
          MeAP_cnt_TransDebugVar = 7U;
        }
      } else {
        SWC_AP_StateMachine_DW.MeAP_cnt_WaitEngineCnt = 0U;
        SWC_AP_StateMachine_B.MeAP_b_CamHandshakeTimeout = false;
        MeAP_cnt_TransDebugVar = 2U;
      }
      break;

     case SWC_AP_StateMachine_IN_OFF:
      MeAP_e_AutoParkStatus = TeAutoPark_e_AutoParkStatus_Off;
      *rty_IeAP_b_SPMFailSts = false;
      *rty_IeAP_b_SPMFaultSts = false;
      *rty_IeAP_b_StandstillReq = false;
      if ((rtu_IbVBII_VehState_LowSpd->IeVBII_e_CmdIgnSts ==
           TeVBII_e_CmdIgnSts_RUN) || (*rtu_MbDiag_TestModeForceOn)) {
        SWC_AP_StateMachine_DW.is_c1_SWC_AP_StateMachine =
          SWC_AP_StateMachine_IN_INIT;
        SWC_AP_StateMachine_enter_atomic_INIT(rty_IeAP_e_InterfaceBSM,
          rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts,
          rty_IeAP_b_SPMFailSts, rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
          rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
          rty_IeAP_e_GearShiftReq);
        SWC_AP_StateMachine_enter_internal_INIT(rtu_IbVBII_VehState_LowSpd,
          rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
      }
      break;

     default:
      /* case IN_ON: */
      SWC_AP_StateMachine_ON(rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus,
        rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle,
        rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel,
        rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake,
        rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
        rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel,
        rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
        rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide,
        rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, rtu_MbDiag_PlantModeOn,
        rtu_MeAP_b_PosMet, rtu_MeAP_b_SteerActionReq, rtu_IbVBII_VehState_LowSpd,
        rtu_MbNVM_ProxyParam, rtu_MeAP_e_GearCmd, rtu_MeAP_b_ObjInPath,
        rtu_IbFID_PPPA_MeAP_b_PPPADisable,
        rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd,
        rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
        rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout,
        rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout,
        rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
        rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur,
        rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
        rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
        rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur,
        rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt,
        rtu_MeAP_b_ObjPrestFC, rtu_MeAP_b_ObjPrestRC, rtu_IeAP_kph_TrgtVehSpd,
        rtu_IeAP_cm_TrgtDist, rty_IeAP_e_InterfaceBSM, rty_IeAP_e_ParKMnvrActv,
        rty_MeAP_e_HMIPopUp, rty_IeAP_e_SPMLedSts, rty_IeAP_b_SPMFailSts,
        rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat, rty_IeAP_b_VehMnvrDirSPM,
        rty_IeAP_b_StandstillReq, rty_MeAP_b_VCOpPaused, rty_IeAP_e_GearShiftReq,
        rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
        rty_MeAP_b_ChimeActvReqLHRSVM, rty_MeAP_b_ChimeActvReqRHFSVM,
        rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
        rty_MeAP_e_PAMChimeRepnRateSVM, rty_MeAP_b_StandStill);
      break;
    }
  }

  /* End of Chart: '<S5>/AUTOPARK_StateMachine' */

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE =
    *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter;

  /* End of Outputs for SubSystem: '<S3>/AP_Statemachine' */

  /* RelationalOperator: '<S187>/Relational Operator' incorporates:
   *  Constant: '<S214>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (MeAutoPark_e_AlgoState ==
    TeAP_e_AlgoState_Park_In);

  /* Logic: '<S187>/Logical Operator' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.RelationalOperator_o &&
     (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_isSlotValid_b !=
      0));

  /* Switch: '<S187>/Switch' incorporates:
   *  Constant: '<S187>/Constant'
   *  Constant: '<S187>/Constant1'
   */
  if (SWC_AP_StateMachine_B.LogicalOperator2_p) {
    SWC_AP_StateMachine_B.Switch[0] = true;
    SWC_AP_StateMachine_B.Switch[1] = false;
  } else {
    /* RelationalOperator: '<S187>/Relational Operator1' incorporates:
     *  Constant: '<S215>/Constant'
     */
    SWC_AP_StateMachine_B.RelationalOperator1 = (MeAutoPark_e_AlgoState ==
      TeAP_e_AlgoState_Park_Out);

    /* Logic: '<S187>/Logical Operator1' */
    SWC_AP_StateMachine_B.LogicalOperator1 =
      (SWC_AP_StateMachine_B.RelationalOperator1 &&
       (rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_isSlotValid_b
        != 0));

    /* Switch: '<S187>/Switch1' incorporates:
     *  Constant: '<S187>/Constant2'
     *  Constant: '<S187>/Constant3'
     *  Constant: '<S187>/Constant4'
     *  Constant: '<S187>/Constant6'
     */
    if (SWC_AP_StateMachine_B.LogicalOperator1) {
      SWC_AP_StateMachine_B.Switch1_j[0] = true;
      SWC_AP_StateMachine_B.Switch1_j[1] = true;
    } else {
      SWC_AP_StateMachine_B.Switch1_j[0] = false;
      SWC_AP_StateMachine_B.Switch1_j[1] = false;
    }

    /* End of Switch: '<S187>/Switch1' */
    SWC_AP_StateMachine_B.Switch[0] = SWC_AP_StateMachine_B.Switch1_j[0];
    SWC_AP_StateMachine_B.Switch[1] = SWC_AP_StateMachine_B.Switch1_j[1];
  }

  /* End of Switch: '<S187>/Switch' */

  /* DataTypeConversion: '<S10>/Data Type Conversion8' */
  SWC_AP_StateMachine_B.DataTypeConversion8 = (uint8_T)
    rtu_LwSpd_FPA_Output->m_FpaInfoToVC.stFPALockedSlotData.m_SlotSide;

  /* RelationalOperator: '<S183>/Compare' incorporates:
   *  Constant: '<S183>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.DataTypeConversion8 == ((uint8_T)1U));

  /* Logic: '<S10>/Logical Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_o = (SWC_AP_StateMachine_B.Switch[1] &&
    SWC_AP_StateMachine_B.RelationalOperator_o);

  /* DataTypeConversion: '<S10>/Data Type Conversion12' */
  *rty_MeAP_b_parkout_perp_left = SWC_AP_StateMachine_B.RelationalOperator_o;

  /* Logic: '<S10>/Logical Operator' */
  *rty_MeAP_b_ResetVCKM = (SWC_AP_StateMachine_B.Switch[1] ||
    SWC_AP_StateMachine_B.Switch[0]);

  /* SignalConversion generated from: '<Root>/MeAP_b_ParkOut' */
  *rty_MeAP_b_ParkOut = SWC_AP_StateMachine_B.Switch[1];

  /* SignalConversion generated from: '<Root>/MeAP_b_VCActive' */
  *rty_MeAP_b_VCActive = SWC_AP_StateMachine_B.Switch[0];

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_cnt_StateDebugVar = (uint16_T)
    MeAP_cnt_StateDebugVar;

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  SWC_AP_StateMachine_B.MeAP_cnt_TransDebugVar_h = (uint16_T)
    MeAP_cnt_TransDebugVar;

  /* BusCreator: '<S6>/Bus Creator' incorporates:
   *  Constant: '<S3>/Constant13'
   */
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_cnt_TransDebugVar =
    SWC_AP_StateMachine_B.MeAP_cnt_TransDebugVar_h;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_VCOpPaused =
    *rty_MeAP_b_VCOpPaused;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_BSMInterfaceTimeout =
    SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_EPSInterfaceTimeout =
    SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_GearShiftWaitTimeout =
    SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_CamHandshakeTimeout =
    SWC_AP_StateMachine_B.MeAP_b_CamHandshakeTimeout;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_ObjInPathTimeout =
    SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_PausedPressBtnTimeout =
    SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_SeekSpdExceedTimeout =
    SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_APInitSts = true;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_DriverOverride =
    MeAP_b_DriverOverride;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_StandStill =
    *rty_MeAP_b_StandStill;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_BSMHandshakeActv =
    SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeActv;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_VehCndSts = MeAP_b_VehCndSts;
  SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_FeatureEnbl = MeAP_b_APActConAvl;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_cnt_StateDebugVar =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_cnt_StateDebugVar;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_SeekSpdExceedTimeout =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_SeekSpdExceedTimeout;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_APInitSts =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_APInitSts;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_DriverOverride =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_DriverOverride;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_StandStill =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_StandStill;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_BSMHandshakeActv =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_BSMHandshakeActv;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_VehCndSts =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_VehCndSts;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_FeatureEnbl =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_FeatureEnbl;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_cnt_TransDebugVar =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_cnt_TransDebugVar;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_VCOpPaused =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_VCOpPaused;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_BSMInterfaceTimeout =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_BSMInterfaceTimeout;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_EPSInterfaceTimeout =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_EPSInterfaceTimeout;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_GearShiftWaitTimeout =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_GearShiftWaitTimeout;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_CamHandshakeTimeout =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_CamHandshakeTimeout;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_ObjInPathTimeout =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_ObjInPathTimeout;

  /* SignalConversion generated from: '<Root>/IbAP_SMDebugOut' */
  *rty_IbAP_SMDebugOut_MeAP_b_PausedPressBtnTimeout =
    SWC_AP_StateMachine_B.IbAP_SMDebugOut.MeAP_b_PausedPressBtnTimeout;

  /* RelationalOperator: '<S132>/Relational Operator1' incorporates:
   *  Constant: '<S138>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (MeAutoPark_e_AlgoState ==
    TeAP_e_AlgoState_Park_In);

  /* RelationalOperator: '<S132>/Relational Operator2' incorporates:
   *  Constant: '<S139>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = (MeAutoPark_e_AlgoState ==
    TeAP_e_AlgoState_Park_Out);

  /* RelationalOperator: '<S132>/Relational Operator3' incorporates:
   *  Constant: '<S141>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a = (MeAutoPark_e_AlgoState ==
    TeAP_e_AlgoState_Handshake);

  /* RelationalOperator: '<S132>/Relational Operator4' incorporates:
   *  Constant: '<S142>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f = (*rtu_MeAP_e_PAMOffStatus2BT !=
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF);

  /* Logic: '<S132>/Logical Operator' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a ||
     SWC_AP_StateMachine_B.LogicalOperator4_f);

  /* Switch: '<S132>/Switch8' incorporates:
   *  Constant: '<S132>/Constant1'
   *  Constant: '<S132>/Constant2'
   */
  if (SWC_AP_StateMachine_B.RelationalOperator_o) {
    SWC_AP_StateMachine_B.Switch8_m = ((uint8_T)2U);
  } else {
    SWC_AP_StateMachine_B.Switch8_m = ((uint8_T)0U);
  }

  /* End of Switch: '<S132>/Switch8' */

  /* RelationalOperator: '<S132>/Relational Operator6' incorporates:
   *  Constant: '<S137>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (MeAutoPark_e_AlgoState ==
    TeAP_e_AlgoState_Scanning);

  /* RelationalOperator: '<S132>/Relational Operator5' incorporates:
   *  Constant: '<S140>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = (MeAP_e_AutoParkStatus ==
    TeAutoPark_e_AutoParkStatus_Active);

  /* Logic: '<S132>/Logical Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o &&
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Switch: '<S132>/Switch9' incorporates:
   *  Constant: '<S132>/Constant'
   *  Constant: '<S132>/Constant3'
   */
  if (SWC_AP_StateMachine_B.RelationalOperator_o) {
    *rty_MeAP_e_USSFiringMode = ((uint8_T)1U);
  } else {
    *rty_MeAP_e_USSFiringMode = ((uint8_T)2U);
  }

  /* End of Switch: '<S132>/Switch9' */

  /* RelationalOperator: '<S132>/Relational Operator7' incorporates:
   *  Constant: '<S143>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (*rtu_MeTHA_e_RearBrkSupprInfo ==
    TeTHA_e_RearBrkSupprInfo_Suppress_Rear_Braking);

  /* Switch: '<S132>/Switch1' incorporates:
   *  Constant: '<S132>/Constant4'
   */
  if (SWC_AP_StateMachine_B.RelationalOperator_o) {
    SWC_AP_StateMachine_B.MeAP_e_USSFiringMode = ((uint8_T)2U);
  } else {
    SWC_AP_StateMachine_B.MeAP_e_USSFiringMode = *rty_MeAP_e_USSFiringMode;
  }

  /* End of Switch: '<S132>/Switch1' */

  /* RelationalOperator: '<S133>/Relational Operator18' incorporates:
   *  Constant: '<S155>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (*rty_IeAP_e_ParKMnvrActv ==
    TeAP_e_ParKMnvrActv_Idle);

  /* RelationalOperator: '<S133>/Relational Operator' incorporates:
   *  Constant: '<S151>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
     TeAP_e_FiltdGearState_Parking);

  /* RelationalOperator: '<S133>/Relational Operator1' incorporates:
   *  Constant: '<S133>/Constant1'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
     KeAP_kph_FrntWarnMaxSpdThd);

  /* RelationalOperator: '<S133>/Relational Operator6' incorporates:
   *  Constant: '<S144>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f = (*rtu_MeAP_e_PAMOffStatus2BT !=
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF);

  /* Logic: '<S133>/Logical Operator3' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p &&
     SWC_AP_StateMachine_B.LogicalOperator3_a &&
     SWC_AP_StateMachine_B.LogicalOperator4_f &&
     SWC_AP_StateMachine_B.RelationalOperator_o);

  /* RelationalOperator: '<S133>/Relational Operator2' incorporates:
   *  Constant: '<S145>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
     TeAP_e_FiltdGearState_Drive);

  /* RelationalOperator: '<S133>/Relational Operator3' incorporates:
   *  Constant: '<S150>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState ==
     TeAP_e_FiltdGearState_ReverseGear);

  /* Logic: '<S133>/Logical Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* RelationalOperator: '<S133>/Relational Operator4' incorporates:
   *  Constant: '<S133>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
     KeAP_kph_FrntWarnMaxSpdThd);

  /* RelationalOperator: '<S133>/Relational Operator19' incorporates:
   *  Constant: '<S133>/Constant7'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig < 30.0F);

  /* RelationalOperator: '<S133>/Relational Operator5' incorporates:
   *  Constant: '<S152>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator5_a = (*rtu_MeAP_e_PAMOffStatus2BT !=
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF);

  /* RelationalOperator: '<S133>/Relational Operator17' incorporates:
   *  Constant: '<S154>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator12 = (*rty_IeAP_e_ParKMnvrActv ==
    TeAP_e_ParKMnvrActv_Idle);

  /* Logic: '<S133>/Logical Operator2' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o &&
     SWC_AP_StateMachine_B.LogicalOperator3_a &&
     SWC_AP_StateMachine_B.LogicalOperator4_f &&
     SWC_AP_StateMachine_B.LogicalOperator5_a &&
     SWC_AP_StateMachine_B.RelationalOperator12);

  /* RelationalOperator: '<S133>/Relational Operator7' incorporates:
   *  Constant: '<S133>/Constant2'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a = (rtu_MbUSS_DiagFlag->overTempFault
    != 0.0);

  /* RelationalOperator: '<S133>/Relational Operator12' incorporates:
   *  Constant: '<S133>/Constant3'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f = (rtu_MbUSS_DiagFlag->commFault !=
    0.0);

  /* RelationalOperator: '<S133>/Relational Operator13' incorporates:
   *  Constant: '<S133>/Constant4'
   */
  SWC_AP_StateMachine_B.LogicalOperator5_a = (rtu_MbUSS_DiagFlag->commUnknown !=
    0.0);

  /* RelationalOperator: '<S133>/Relational Operator14' incorporates:
   *  Constant: '<S133>/Constant5'
   */
  SWC_AP_StateMachine_B.RelationalOperator12 =
    (rtu_MbUSS_DiagFlag->hardwareFault != 0.0);

  /* Logic: '<S133>/Logical Operator5' */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (SWC_AP_StateMachine_B.LogicalOperator3_a ||
     SWC_AP_StateMachine_B.LogicalOperator4_f ||
     SWC_AP_StateMachine_B.LogicalOperator5_a ||
     SWC_AP_StateMachine_B.RelationalOperator12);

  /* RelationalOperator: '<S133>/Relational Operator16' incorporates:
   *  Constant: '<S133>/Constant6'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig > 30.0F);

  /* RelationalOperator: '<S133>/Relational Operator15' incorporates:
   *  Constant: '<S153>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator5_a = (*rty_IeAP_e_ParKMnvrActv ==
    TeAP_e_ParKMnvrActv_Enabled_Seeking);

  /* Logic: '<S133>/Logical Operator6' */
  SWC_AP_StateMachine_B.LogicalOperator4_f =
    (SWC_AP_StateMachine_B.LogicalOperator4_f &&
     SWC_AP_StateMachine_B.LogicalOperator5_a);

  /* Logic: '<S133>/Logical Operator' */
  *rty_MeAP_b_USSReInit = (SWC_AP_StateMachine_B.LogicalOperator2_p ||
    SWC_AP_StateMachine_B.RelationalOperator_o ||
    SWC_AP_StateMachine_B.LogicalOperator3_a ||
    SWC_AP_StateMachine_B.LogicalOperator4_f);

  /* RelationalOperator: '<S135>/Relational Operator7' incorporates:
   *  Constant: '<S160>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (*rtu_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S135>/RelationalOperator2' incorporates:
   *  Constant: '<S135>/Constant2'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <= 65.0F);

  /* Logic: '<S135>/Logical Operator2' incorporates:
   *  Constant: '<S3>/Constant6'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (false &&
    SWC_AP_StateMachine_B.RelationalOperator_o &&
    SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* Switch: '<S135>/Switch5' incorporates:
   *  Constant: '<S159>/Constant'
   */
  if (SWC_AP_StateMachine_B.RelationalOperator_o) {
    *rty_MeAP_e_USSSystemMode = TeAP_e_USSSystemMode_All;
  } else {
    /* RelationalOperator: '<S135>/RelationalOperator5' incorporates:
     *  Constant: '<S135>/Constant4'
     */
    SWC_AP_StateMachine_B.RelationalOperator8_i =
      (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <= 65.0F);

    /* RelationalOperator: '<S135>/RelationalOperator4' incorporates:
     *  Constant: '<S135>/Constant3'
     */
    SWC_AP_StateMachine_B.LogicalOperator9_i =
      (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig >
       KeAP_kph_FrntWarnMaxSpdThd);

    /* Logic: '<S135>/Logical Operator9' */
    SWC_AP_StateMachine_B.LogicalOperator9_i =
      (SWC_AP_StateMachine_B.LogicalOperator9_i &&
       SWC_AP_StateMachine_B.RelationalOperator8_i);

    /* RelationalOperator: '<S135>/Relational Operator8' incorporates:
     *  Constant: '<S177>/Constant'
     */
    SWC_AP_StateMachine_B.RelationalOperator8_i =
      (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
       TeAP_e_FiltdGearState_Drive);

    /* RelationalOperator: '<S135>/RelationalOperator3' incorporates:
     *  Constant: '<S158>/Constant'
     */
    SWC_AP_StateMachine_B.LogicalOperator8_n = (MeAutoPark_e_AlgoState <=
      TeAP_e_AlgoState_Scanning);

    /* Logic: '<S135>/Logical Operator8' */
    SWC_AP_StateMachine_B.LogicalOperator8_n =
      (SWC_AP_StateMachine_B.LogicalOperator8_n &&
       SWC_AP_StateMachine_B.RelationalOperator8_i &&
       SWC_AP_StateMachine_B.LogicalOperator9_i);

    /* Switch: '<S135>/Switch1' incorporates:
     *  Constant: '<S176>/Constant'
     */
    if (SWC_AP_StateMachine_B.LogicalOperator8_n) {
      SWC_AP_StateMachine_B.Switch1_k = TeAP_e_USSSystemMode_PSS;
    } else {
      /* RelationalOperator: '<S135>/RelationalOperator7' incorporates:
       *  Constant: '<S135>/Constant5'
       */
      SWC_AP_StateMachine_B.RelationalOperator7_g =
        (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
         KeAP_kph_FrntWarnMaxSpdThd);

      /* RelationalOperator: '<S135>/Relational Operator9' incorporates:
       *  Constant: '<S162>/Constant'
       */
      SWC_AP_StateMachine_B.RelationalOperator9 =
        (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
         TeAP_e_FiltdGearState_Drive);

      /* RelationalOperator: '<S135>/RelationalOperator6' incorporates:
       *  Constant: '<S161>/Constant'
       */
      SWC_AP_StateMachine_B.LogicalOperator10 = (MeAutoPark_e_AlgoState <=
        TeAP_e_AlgoState_Scanning);

      /* Logic: '<S135>/Logical Operator10' */
      SWC_AP_StateMachine_B.LogicalOperator10 =
        (SWC_AP_StateMachine_B.LogicalOperator10 &&
         SWC_AP_StateMachine_B.RelationalOperator9 &&
         SWC_AP_StateMachine_B.RelationalOperator7_g);

      /* Switch: '<S135>/Switch2' incorporates:
       *  Constant: '<S178>/Constant'
       */
      if (SWC_AP_StateMachine_B.LogicalOperator10) {
        SWC_AP_StateMachine_B.Switch2_o = TeAP_e_USSSystemMode_FPA_PSS;
      } else {
        /* RelationalOperator: '<S135>/RelationalOperator8' incorporates:
         *  Constant: '<S135>/Constant6'
         */
        SWC_AP_StateMachine_B.RelationalOperator8_g =
          (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
           KeAP_kph_FrntWarnMaxSpdThd);

        /* RelationalOperator: '<S135>/Relational Operator12' incorporates:
         *  Constant: '<S164>/Constant'
         */
        SWC_AP_StateMachine_B.RelationalOperator9_m =
          (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
           TeAP_e_FiltdGearState_ReverseGear);

        /* RelationalOperator: '<S135>/Relational Operator11' incorporates:
         *  Constant: '<S165>/Constant'
         */
        SWC_AP_StateMachine_B.LogicalOperator12_c =
          (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
           TeAP_e_FiltdGearState_Drive);

        /* Logic: '<S135>/Logical Operator12' */
        SWC_AP_StateMachine_B.LogicalOperator12_c =
          (SWC_AP_StateMachine_B.LogicalOperator12_c ||
           SWC_AP_StateMachine_B.RelationalOperator9_m);

        /* RelationalOperator: '<S135>/RelationalOperator9' incorporates:
         *  Constant: '<S167>/Constant'
         */
        SWC_AP_StateMachine_B.RelationalOperator9_m = (MeAP_e_AutoParkStatus ==
          TeAutoPark_e_AutoParkStatus_Active);

        /* RelationalOperator: '<S135>/Relational Operator10' incorporates:
         *  Constant: '<S163>/Constant'
         */
        SWC_AP_StateMachine_B.LogicalOperator11_n = (*rtu_MeAP_e_PAMOffStatus2BT
          == TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

        /* Logic: '<S135>/Logical Operator13' */
        SWC_AP_StateMachine_B.LogicalOperator11_n =
          (SWC_AP_StateMachine_B.LogicalOperator11_n ||
           SWC_AP_StateMachine_B.RelationalOperator9_m);

        /* Logic: '<S135>/Logical Operator11' */
        SWC_AP_StateMachine_B.LogicalOperator11_n =
          (SWC_AP_StateMachine_B.LogicalOperator11_n &&
           SWC_AP_StateMachine_B.LogicalOperator12_c &&
           SWC_AP_StateMachine_B.RelationalOperator8_g);

        /* Switch: '<S135>/Switch3' incorporates:
         *  Constant: '<S166>/Constant'
         */
        if (SWC_AP_StateMachine_B.LogicalOperator11_n) {
          SWC_AP_StateMachine_B.Switch3 = TeAP_e_USSSystemMode_FPA_RPA;
        } else {
          /* RelationalOperator: '<S135>/RelationalOperator11' incorporates:
           *  Constant: '<S135>/Constant7'
           */
          SWC_AP_StateMachine_B.RelationalOperator11_g =
            (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
             KeAP_kph_RearWarnMaxSpdThd);

          /* RelationalOperator: '<S135>/Relational Operator13' incorporates:
           *  Constant: '<S170>/Constant'
           */
          SWC_AP_StateMachine_B.RelationalOperator13 =
            (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
             TeAP_e_FiltdGearState_ReverseGear);

          /* RelationalOperator: '<S135>/Relational Operator14' incorporates:
           *  Constant: '<S169>/Constant'
           */
          SWC_AP_StateMachine_B.LogicalOperator14 = (*rtu_MeAP_e_PAMOffStatus2BT
            == TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

          /* Logic: '<S135>/Logical Operator14' */
          SWC_AP_StateMachine_B.LogicalOperator14 =
            (SWC_AP_StateMachine_B.LogicalOperator14 &&
             SWC_AP_StateMachine_B.RelationalOperator13 &&
             SWC_AP_StateMachine_B.RelationalOperator11_g);

          /* Switch: '<S135>/Switch10' incorporates:
           *  Constant: '<S168>/Constant'
           */
          if (SWC_AP_StateMachine_B.LogicalOperator14) {
            SWC_AP_StateMachine_B.Switch10 = TeAP_e_USSSystemMode_RPA;
          } else {
            /* RelationalOperator: '<S135>/RelationalOperator10' incorporates:
             *  Constant: '<S135>/Constant8'
             */
            SWC_AP_StateMachine_B.RelationalOperator10_c =
              (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
               KeAP_kph_FrntWarnMaxSpdThd);

            /* RelationalOperator: '<S135>/Relational Operator17' incorporates:
             *  Constant: '<S172>/Constant'
             */
            SWC_AP_StateMachine_B.LogicalOperator15 =
              (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
               TeAP_e_FiltdGearState_ReverseGear);

            /* RelationalOperator: '<S135>/Relational Operator15' incorporates:
             *  Constant: '<S173>/Constant'
             */
            SWC_AP_StateMachine_B.LogicalOperator16 =
              (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear ==
               TeAP_e_FiltdGearState_Drive);

            /* Logic: '<S135>/Logical Operator16' */
            SWC_AP_StateMachine_B.LogicalOperator16 =
              (SWC_AP_StateMachine_B.LogicalOperator16 ||
               SWC_AP_StateMachine_B.LogicalOperator15);

            /* RelationalOperator: '<S135>/Relational Operator16' incorporates:
             *  Constant: '<S171>/Constant'
             */
            SWC_AP_StateMachine_B.LogicalOperator15 =
              (*rtu_MeAP_e_PAMOffStatus2BT ==
               TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

            /* Logic: '<S135>/Logical Operator15' */
            SWC_AP_StateMachine_B.LogicalOperator15 =
              (SWC_AP_StateMachine_B.LogicalOperator15 &&
               SWC_AP_StateMachine_B.LogicalOperator16 &&
               SWC_AP_StateMachine_B.RelationalOperator10_c);

            /* Switch: '<S135>/Switch11' incorporates:
             *  Constant: '<S174>/Constant'
             *  Constant: '<S175>/Constant'
             */
            if (SWC_AP_StateMachine_B.LogicalOperator15) {
              SWC_AP_StateMachine_B.Switch11 = TeAP_e_USSSystemMode_FPA;
            } else {
              SWC_AP_StateMachine_B.Switch11 = TeAP_e_USSSystemMode_None;
            }

            /* End of Switch: '<S135>/Switch11' */
            SWC_AP_StateMachine_B.Switch10 = SWC_AP_StateMachine_B.Switch11;
          }

          /* End of Switch: '<S135>/Switch10' */
          SWC_AP_StateMachine_B.Switch3 = SWC_AP_StateMachine_B.Switch10;
        }

        /* End of Switch: '<S135>/Switch3' */
        SWC_AP_StateMachine_B.Switch2_o = SWC_AP_StateMachine_B.Switch3;
      }

      /* End of Switch: '<S135>/Switch2' */
      SWC_AP_StateMachine_B.Switch1_k = SWC_AP_StateMachine_B.Switch2_o;
    }

    /* End of Switch: '<S135>/Switch1' */
    *rty_MeAP_e_USSSystemMode = SWC_AP_StateMachine_B.Switch1_k;
  }

  /* End of Switch: '<S135>/Switch5' */

  /* RelationalOperator: '<S136>/Relational Operator6' incorporates:
   *  Constant: '<S179>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (*rty_MeAP_e_USSSystemMode !=
    TeAP_e_USSSystemMode_None);

  /* Switch: '<S136>/Switch9' incorporates:
   *  Constant: '<S182>/Constant'
   */
  if (SWC_AP_StateMachine_B.RelationalOperator_o) {
    *rty_MeAP_e_USSSystemState = TeAP_e_USSSystemState_Active;
  } else {
    /* RelationalOperator: '<S136>/RelationalOperator1' incorporates:
     *  Constant: '<S136>/Constant1'
     */
    SWC_AP_StateMachine_B.RelationalOperator1_f =
      (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <= 65.0F);

    /* Switch: '<S136>/Switch8' incorporates:
     *  Constant: '<S180>/Constant'
     *  Constant: '<S181>/Constant'
     */
    if (SWC_AP_StateMachine_B.RelationalOperator1_f) {
      SWC_AP_StateMachine_B.Switch8 = TeAP_e_USSSystemState_Standby;
    } else {
      SWC_AP_StateMachine_B.Switch8 = TeAP_e_USSSystemState_Off;
    }

    /* End of Switch: '<S136>/Switch8' */
    *rty_MeAP_e_USSSystemState = SWC_AP_StateMachine_B.Switch8;
  }

  /* End of Switch: '<S136>/Switch9' */

  /* RelationalOperator: '<S134>/RelationalOperator' incorporates:
   *  Constant: '<S134>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <= 65.0F);

  /* Logic: '<S134>/Logical Operator7' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_ConstB.DataTypeConversion);

  /* Switch: '<S134>/Switch4' incorporates:
   *  Constant: '<S156>/Constant'
   *  Constant: '<S157>/Constant'
   */
  if (SWC_AP_StateMachine_B.RelationalOperator_o) {
    *rty_MeAP_e_USSSupplyPwrSt = TeAP_e_USSSupplyPwrSt_Enabled;
  } else {
    *rty_MeAP_e_USSSupplyPwrSt = TeAP_e_USSSupplyPwrSt_Disabled;
  }

  /* End of Switch: '<S134>/Switch4' */

  /* UnitDelay: '<S186>/Unit Delay6' */
  SWC_AP_StateMachine_B.UnitDelay6 = SWC_AP_StateMachine_DW.UnitDelay6_DSTATE;

  /* UnitDelay: '<S186>/Unit Delay9' */
  SWC_AP_StateMachine_B.UnitDelay9_o = SWC_AP_StateMachine_DW.UnitDelay9_DSTATE;

  /* UnitDelay: '<S186>/Unit Delay5' */
  SWC_AP_StateMachine_B.UnitDelay5 = SWC_AP_StateMachine_DW.UnitDelay5_DSTATE;

  /* UnitDelay: '<S186>/Unit Delay' */
  SWC_AP_StateMachine_B.UnitDelay4 = SWC_AP_StateMachine_DW.UnitDelay_DSTATE_p;

  /* RelationalOperator: '<S186>/Relational Operator1' incorporates:
   *  Constant: '<S200>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (SWC_AP_StateMachine_B.UnitDelay4
    == TeAP_e_AlgoState_Idle);

  /* RelationalOperator: '<S186>/Relational Operator5' incorporates:
   *  Constant: '<S209>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = (MeAutoPark_e_AlgoState ==
    TeAP_e_AlgoState_Scanning);

  /* Logic: '<S186>/Logical Operator1' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o &&
     SWC_AP_StateMachine_B.LogicalOperator2_p);

  /* UnitDelay: '<S186>/Unit Delay1' */
  SWC_AP_StateMachine_B.UnitDelay4 = SWC_AP_StateMachine_DW.UnitDelay1_DSTATE;

  /* RelationalOperator: '<S186>/Relational Operator7' incorporates:
   *  Constant: '<S210>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator2_p = (SWC_AP_StateMachine_B.UnitDelay4 ==
    TeAP_e_AlgoState_Handshake);

  /* RelationalOperator: '<S186>/Relational Operator2' incorporates:
   *  Constant: '<S206>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a = (MeAutoPark_e_AlgoState ==
    TeAP_e_AlgoState_Park_In);

  /* Logic: '<S186>/Logical Operator2' */
  SWC_AP_StateMachine_B.LogicalOperator2_p =
    (SWC_AP_StateMachine_B.LogicalOperator2_p &&
     SWC_AP_StateMachine_B.LogicalOperator3_a);

  /* UnitDelay: '<S186>/Unit Delay2' */
  SWC_AP_StateMachine_B.UnitDelay4 = SWC_AP_StateMachine_DW.UnitDelay2_DSTATE_p;

  /* RelationalOperator: '<S186>/Relational Operator8' incorporates:
   *  Constant: '<S211>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator3_a = (SWC_AP_StateMachine_B.UnitDelay4 ==
    TeAP_e_AlgoState_Park_In);

  /* RelationalOperator: '<S186>/Relational Operator9' incorporates:
   *  Constant: '<S212>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f = (MeAutoPark_e_AlgoState ==
    TeAP_e_AlgoState_Idle);

  /* Logic: '<S186>/Logical Operator3' */
  SWC_AP_StateMachine_B.LogicalOperator3_a =
    (SWC_AP_StateMachine_B.LogicalOperator3_a &&
     SWC_AP_StateMachine_B.LogicalOperator4_f);

  /* UnitDelay: '<S186>/Unit Delay3' */
  SWC_AP_StateMachine_B.UnitDelay4 = SWC_AP_StateMachine_DW.UnitDelay3_DSTATE;

  /* RelationalOperator: '<S186>/Relational Operator10' incorporates:
   *  Constant: '<S213>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator4_f = (SWC_AP_StateMachine_B.UnitDelay4 ==
    TeAP_e_AlgoState_Handshake);

  /* RelationalOperator: '<S186>/Relational Operator3' incorporates:
   *  Constant: '<S207>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator5_a = (MeAutoPark_e_AlgoState ==
    TeAP_e_AlgoState_Park_Out);

  /* Logic: '<S186>/Logical Operator4' */
  SWC_AP_StateMachine_B.LogicalOperator4_f =
    (SWC_AP_StateMachine_B.LogicalOperator4_f &&
     SWC_AP_StateMachine_B.LogicalOperator5_a);

  /* UnitDelay: '<S186>/Unit Delay4' */
  SWC_AP_StateMachine_B.UnitDelay4 = SWC_AP_StateMachine_DW.UnitDelay4_DSTATE;

  /* RelationalOperator: '<S186>/Relational Operator11' incorporates:
   *  Constant: '<S201>/Constant'
   */
  SWC_AP_StateMachine_B.LogicalOperator5_a = (SWC_AP_StateMachine_B.UnitDelay4 ==
    TeAP_e_AlgoState_Park_Out);

  /* RelationalOperator: '<S186>/Relational Operator12' incorporates:
   *  Constant: '<S202>/Constant'
   */
  SWC_AP_StateMachine_B.RelationalOperator12 = (MeAutoPark_e_AlgoState ==
    TeAP_e_AlgoState_Idle);

  /* Logic: '<S186>/Logical Operator5' */
  SWC_AP_StateMachine_B.LogicalOperator5_a =
    (SWC_AP_StateMachine_B.LogicalOperator5_a &&
     SWC_AP_StateMachine_B.RelationalOperator12);

  /* Logic: '<S186>/Logical Operator6' */
  SWC_AP_StateMachine_B.RelationalOperator_o =
    (SWC_AP_StateMachine_B.RelationalOperator_o ||
     SWC_AP_StateMachine_B.LogicalOperator2_p ||
     SWC_AP_StateMachine_B.LogicalOperator3_a ||
     SWC_AP_StateMachine_B.LogicalOperator4_f ||
     SWC_AP_StateMachine_B.LogicalOperator5_a);

  /* Switch: '<S186>/Switch9' incorporates:
   *  Constant: '<S186>/Constant'
   */
  if (SWC_AP_StateMachine_B.RelationalOperator_o) {
    MeAP_b_ResetKM = true;
  } else {
    /* RelationalOperator: '<S186>/Relational Operator6' incorporates:
     *  Constant: '<S203>/Constant'
     */
    SWC_AP_StateMachine_B.LogicalOperator13_c = (*rtu_MeAP_e_PAMOffStatus2BT !=
      TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF);

    /* RelationalOperator: '<S186>/Relational Operator4' incorporates:
     *  Constant: '<S208>/Constant'
     */
    SWC_AP_StateMachine_B.LogicalOperator_d = (SWC_AP_StateMachine_B.UnitDelay5 ==
      TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF);

    /* Logic: '<S186>/Logical Operator7' */
    SWC_AP_StateMachine_B.LogicalOperator_d =
      (SWC_AP_StateMachine_B.LogicalOperator_d &&
       SWC_AP_StateMachine_B.LogicalOperator13_c);

    /* RelationalOperator: '<S186>/Relational Operator13' */
    SWC_AP_StateMachine_B.LogicalOperator13_c =
      (rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState !=
       SWC_AP_StateMachine_B.UnitDelay9_o);

    /* RelationalOperator: '<S186>/Relational Operator15' incorporates:
     *  Constant: '<S186>/KeAP_kph_FrntWarnMaxSpdThd1'
     */
    SWC_AP_StateMachine_B.RelationalOperator18 =
      (SWC_AP_StateMachine_B.UnitDelay6 > KeAP_kph_FrntWarnMaxSpdThd);

    /* RelationalOperator: '<S186>/Relational Operator' incorporates:
     *  Constant: '<S186>/KeAP_kph_FrntWarnMaxSpdThd'
     */
    SWC_AP_StateMachine_B.LogicalOperator11 =
      (rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig <=
       KeAP_kph_FrntWarnMaxSpdThd);

    /* Logic: '<S186>/Logical Operator8' */
    SWC_AP_StateMachine_B.LogicalOperator11 =
      (SWC_AP_StateMachine_B.LogicalOperator11 &&
       SWC_AP_StateMachine_B.RelationalOperator18);

    /* Logic: '<S186>/Logical Operator11' */
    SWC_AP_StateMachine_B.LogicalOperator11 =
      (SWC_AP_StateMachine_B.LogicalOperator11 ||
       SWC_AP_StateMachine_B.LogicalOperator13_c);

    /* RelationalOperator: '<S186>/Relational Operator18' incorporates:
     *  Constant: '<S204>/Constant'
     */
    SWC_AP_StateMachine_B.RelationalOperator18 = (*rtu_MeAP_e_PAMOffStatus2BT !=
      TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF);

    /* RelationalOperator: '<S186>/Relational Operator19' incorporates:
     *  Constant: '<S205>/Constant'
     */
    SWC_AP_StateMachine_B.LogicalOperator13_c = (MeAP_e_AutoParkStatus !=
      TeAutoPark_e_AutoParkStatus_Active);

    /* Logic: '<S186>/Logical Operator13' */
    SWC_AP_StateMachine_B.LogicalOperator13_c =
      (SWC_AP_StateMachine_B.LogicalOperator13_c &&
       SWC_AP_StateMachine_B.RelationalOperator18 &&
       SWC_AP_StateMachine_B.LogicalOperator11);

    /* Logic: '<S186>/Logical Operator' */
    SWC_AP_StateMachine_B.LogicalOperator_d =
      (SWC_AP_StateMachine_B.LogicalOperator_d ||
       SWC_AP_StateMachine_B.LogicalOperator13_c);

    /* Switch: '<S186>/Switch1' incorporates:
     *  Constant: '<S186>/Constant1'
     *  Constant: '<S186>/Constant2'
     */
    if (SWC_AP_StateMachine_B.LogicalOperator_d) {
      SWC_AP_StateMachine_B.Switch1_pg = true;
    } else {
      SWC_AP_StateMachine_B.Switch1_pg = false;
    }

    /* End of Switch: '<S186>/Switch1' */
    MeAP_b_ResetKM = SWC_AP_StateMachine_B.Switch1_pg;
  }

  /* End of Switch: '<S186>/Switch9' */

  /* Abs: '<Root>/Abs' */
  SWC_AP_StateMachine_B.Abs = fabsf(*rtu_IeAP_nm_StrwTrqReq);

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/steeringTrqCmd_Thd'
   */
  SWC_AP_StateMachine_B.RelationalOperator_o = (SWC_AP_StateMachine_B.Abs >
    1.0E-5F);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (SWC_AP_StateMachine_B.RelationalOperator_o) {
    *rty_IeAP_e_SPMLatCtrlReqSts = TeAP_e_SPMLatCtrlReqSts_SPM_Request;
  } else {
    *rty_IeAP_e_SPMLatCtrlReqSts = SWC_AP_StateMachine_B.IeAP_e_SPMLatCtrlReqSts;
  }

  /* End of Switch: '<Root>/Switch' */

  /* SignalConversion: '<S3>/Signal Conversion' */
  *rty_MeAP_b_ScanSts = SWC_AP_StateMachine_B.MeAP_b_ValidSlotAvl;

  /* RelationalOperator: '<S185>/Relational Operator' incorporates:
   *  Constant: '<S185>/Constant2'
   */
  *rty_MeAP_b_PerpNoseIn = (*rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle ==
    TeAutoPark_e_ParkStyle_Front_In);

  /* Update for UnitDelay: '<S3>/Unit Delay3' */
  SWC_AP_StateMachine_DW.UnitDelay3_DSTATE_d = *rty_IeAP_e_GearShiftReq;

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  SWC_AP_StateMachine_DW.UnitDelay1_DSTATE_f =
    SWC_AP_StateMachine_B.MeAP_b_SeekSpdExceedTimeout_f;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_f = *rty_IeAP_e_ParKMnvrActv;

  /* Update for UnitDelay: '<S3>/Unit Delay2' */
  SWC_AP_StateMachine_DW.UnitDelay2_DSTATE = MeAutoPark_e_AlgoState;

  /* Update for UnitDelay: '<S3>/Unit Delay4' */
  SWC_AP_StateMachine_DW.UnitDelay4_DSTATE_a =
    SWC_AP_StateMachine_B.MeAP_b_BSMInterfaceTimeout;

  /* Update for UnitDelay: '<S3>/Unit Delay5' */
  SWC_AP_StateMachine_DW.UnitDelay5_DSTATE_k =
    SWC_AP_StateMachine_B.MeAP_b_EPSInterfaceTimeout;

  /* Update for UnitDelay: '<S3>/Unit Delay6' */
  SWC_AP_StateMachine_DW.UnitDelay6_DSTATE_c =
    SWC_AP_StateMachine_B.MeAP_b_GearShiftWaitTimeout;

  /* Update for UnitDelay: '<S3>/Unit Delay7' */
  SWC_AP_StateMachine_DW.UnitDelay7_DSTATE = MeAP_e_AutoParkStatus;

  /* Update for UnitDelay: '<S3>/Unit Delay8' */
  SWC_AP_StateMachine_DW.UnitDelay8_DSTATE =
    SWC_AP_StateMachine_B.MeAP_b_CamHandshakeTimeout;

  /* Update for UnitDelay: '<S3>/Unit Delay9' */
  SWC_AP_StateMachine_DW.UnitDelay9_DSTATE_p = *rty_IeAP_e_SPMActvStat;

  /* Update for UnitDelay: '<S3>/Unit Delay10' */
  SWC_AP_StateMachine_DW.UnitDelay10_DSTATE =
    SWC_AP_StateMachine_B.MeAP_b_ObjInPathTimeout_m;

  /* Update for UnitDelay: '<S3>/Unit Delay11' */
  SWC_AP_StateMachine_DW.UnitDelay11_DSTATE =
    SWC_AP_StateMachine_B.MeAP_b_PausedPressBtnTimeout_c;

  /* Update for UnitDelay: '<S3>/Unit Delay12' */
  SWC_AP_StateMachine_DW.UnitDelay12_DSTATE =
    SWC_AP_StateMachine_B.MeAP_b_BSMHandshakeSts;

  /* Update for UnitDelay: '<S3>/Unit Delay13' */
  SWC_AP_StateMachine_DW.UnitDelay13_DSTATE =
    SWC_AP_StateMachine_B.MeAP_b_SeekPhaseTimeout_m;

  /* Update for UnitDelay: '<S3>/Unit Delay14' */
  SWC_AP_StateMachine_DW.UnitDelay14_DSTATE = MeAP_b_InitBrkPedlPressed;

  /* Update for UnitDelay: '<S186>/Unit Delay6' */
  SWC_AP_StateMachine_DW.UnitDelay6_DSTATE =
    rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig;

  /* Update for UnitDelay: '<S186>/Unit Delay9' */
  SWC_AP_StateMachine_DW.UnitDelay9_DSTATE =
    rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState;

  /* Update for UnitDelay: '<S186>/Unit Delay5' */
  SWC_AP_StateMachine_DW.UnitDelay5_DSTATE = *rtu_MeAP_e_PAMOffStatus2BT;

  /* Update for UnitDelay: '<S186>/Unit Delay' */
  SWC_AP_StateMachine_DW.UnitDelay_DSTATE_p = MeAutoPark_e_AlgoState;

  /* Update for UnitDelay: '<S186>/Unit Delay1' */
  SWC_AP_StateMachine_DW.UnitDelay1_DSTATE = MeAutoPark_e_AlgoState;

  /* Update for UnitDelay: '<S186>/Unit Delay2' */
  SWC_AP_StateMachine_DW.UnitDelay2_DSTATE_p = MeAutoPark_e_AlgoState;

  /* Update for UnitDelay: '<S186>/Unit Delay3' */
  SWC_AP_StateMachine_DW.UnitDelay3_DSTATE = MeAutoPark_e_AlgoState;

  /* Update for UnitDelay: '<S186>/Unit Delay4' */
  SWC_AP_StateMachine_DW.UnitDelay4_DSTATE = MeAutoPark_e_AlgoState;
}

/* Model initialize function */
void SWC_AP_StateMachine_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_SWC_AP_StateMachine_T *const SWC_AP_StateMachine_M =
    &(SWC_AP_StateMachine_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(SWC_AP_StateMachine_M, rt_errorStatus);

  /* block I/O */
  {
    SWC_AP_StateMachine_B.UnitDelay9_o = TeAP_e_FiltdGearState_SNA;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
